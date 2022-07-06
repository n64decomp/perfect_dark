#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/atan2f.h"
#include "game/savebuffer.h"
#include "game/sky.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"
#include "gbiex.h"

char var800a41c0[24];
u8 g_IrScanlines[2][480];

#if VERSION < VERSION_NTSC_1_0
u8 var800a8b58nb[0x1c0];
#endif

s32 var8007f840 = 0;
u8 var8007f844 = 0;
u8 var8007f848 = 0;
s32 g_IrBinocularRadius = PAL ? 102 : 90;
s32 var8007f850 = 3;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;

#if VERSION < VERSION_NTSC_1_0
void func0f13c2d0nb(void)
{
	mainOverrideVariable("fsrad", (u32 *)&g_IrBinocularRadius);
	mainOverrideVariable("fscs", (u32 *)&var8007f850);
}
#endif

Gfx *bviewDrawIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	return gdl;
}

Gfx *bview0f141864(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 320, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, arg3, 0, 0, arg5 - 1, 0);

	return gdl;
}

Gfx *bview0f141940(Gfx *gdl, s32 arg1, s32 arg2, s32 tile, s32 arg4, s32 width)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, tile, 0, 0, width - 1, 0);

	return gdl;
}

Gfx *bview0f141a20(Gfx *gdl, s32 top, s32 height, s32 left, s32 width)
{
	gDPPipeSync(gdl++);

	gSPTextureRectangle(gdl++,
			left << 2,
			top << 2,
			(left + width) << 2,
			(top + 1) << 2,
			G_TX_RENDERTILE, 0, 0, height * 1024, 1024);

	return gdl;
}

GLOBAL_ASM(
glabel bviewCopyPixels
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
//Gfx *bviewCopyPixels(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 left, s32 width)
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

Gfx *bviewDrawFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4)
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

	mainOverrideVariable("envcol", &envcol);
	mainOverrideVariable("primcol", &primcol);

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

	mainOverrideVariable("envcol", &envcol);
	mainOverrideVariable("primcol", &primcol);

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

Gfx *bviewDrawMotionBlur(Gfx *gdl, u32 colour, u32 alpha)
{
	u8 *fb = viGetFrontBuffer();
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

	mainOverrideVariable("sfxxx", &sfxxx);
	fxxx = sfxxx / 1000.0f;
	mainOverrideVariable("sfyyy", &sfyyy);
	fyyy = sfyyy / 1000.0f;

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / fyyy) * 0.5f;
	gdl = bviewPrepareStaticRgba16(gdl, colour, newalpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewCopyPixels(gdl, fb, viewtop + (s32)somefloat, 5, i, fxxx, viewleft, viewwidth);
		somefloat += 1.0f / fyyy;
	}

	return gdl;
}

/**
 * Draw static for the Infiltration intro cutscene and Slayer rockets.
 */
Gfx *bviewDrawStatic(Gfx *gdl, u32 arg1, s32 arg2)
{
	u8 *fb = viGetFrontBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	u8 *fb2 = (u8 *)(random() & 0xfff00 | 0x80000000);
	s32 y;

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticI8(gdl, arg1, arg2);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		gdl = bviewCopyPixels(gdl, fb2, random() % 240, 5, y, 1.0f, viewleft, viewwidth);
	}

	if (fb2) {
		// empty
	}

	return gdl;
}

/**
 * Draw the yellow interlace effect for Slayer rockets.
 */
Gfx *bviewDrawSlayerRocketInterlace(Gfx *gdl, u32 colour, u32 alpha)
{
	u8 *fb = viGetBackBuffer();
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

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 2.0f - sinf(angle), viewleft, viewwidth);

		angle += increment;
	}

	return gdl;
}

/**
 * Draw the blue film interlace effect for the Infiltration intro cutscene.
 */
Gfx *bviewDrawFilmInterlace(Gfx *gdl, u32 colour, u32 alpha)
{
	u8 *fb = viGetBackBuffer();
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

		gdl = bviewCopyPixels(gdl, fb, tmpy, 5, y, 1, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Draw a zoom in/out motion blur effect.
 *
 * Used when entering/exiting combat boosts and when entering/exiting xray mode.
 */
Gfx *bviewDrawZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4)
{
	u8 *fb = viGetFrontBuffer();
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
		gdl = bviewCopyPixels(gdl, fb, (s32)somefloat + viewtop, 5, i, arg3, viewleft, viewwidth);
		somefloat += 1.0f / arg4;
	}

	return gdl;
}

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

/**
 * Draw the fisheye curved effect when using an eyespy.
 *
 * PAL Beta adds padding above and below to compensate for the higher vertical
 * screen resolution, by adjusting the viewtop and viewheight variables and
 * drawing black filler at the end of the function. However the size of these
 * bars is static regardless of the screen layout and size being used.
 *
 * PAL Final improves on beta's mistake by checking the screen size, but there's
 * no check for a vertical split being used, and as a result the fisheye radius
 * is smaller than it should be when using a horizontal split. @bug
 */
Gfx *bviewDrawFisheye(Gfx *gdl, u32 colour, u32 alpha, s32 shuttertime60, s8 startuptimer60, u8 hit)
{
	u8 *fb = viGetBackBuffer();
	s32 viewtop;
	s32 viewheight;
	f32 f26;
	f32 halfheight;
	f32 sqhalfheight;
	s32 viewwidth;
	s32 viewleft;
	s32 s2;
	s32 i;
	s32 s3;
	u8 starting;
	s32 curradius;
	f32 startupfrac;
	f32 fullradius;
	s32 one = 1;
	s32 spec;
	u8 alpha2;

#if VERSION >= VERSION_PAL_FINAL && PAL
	s32 vpadding;
#endif

	f32 tmp;

#if VERSION >= VERSION_PAL_FINAL
	viewtop = viGetViewTop();
	viewheight = viGetViewHeight();
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();

	startupfrac = 1.0f;
	s2 = 0;

#if PAL
	if (PLAYERCOUNT() >= 2
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE
			|| optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
		vpadding = 16;
		viewtop += vpadding;
		viewheight -= vpadding * 2;
	} else {
		vpadding = 23;
		viewtop += vpadding;
		viewheight -= vpadding * 2;
	}
#endif

	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
#elif VERSION >= VERSION_PAL_BETA
	viewtop = viGetViewTop() + 16;
	viewheight = viGetViewHeight() - 32;
	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();
	startupfrac = 1.0f;
	s2 = 0;
#else
	viewtop = viGetViewTop();
	viewheight = viGetViewHeight();
	halfheight = viewheight * 0.5f;
	sqhalfheight = halfheight * halfheight;
	f26 = -(halfheight + halfheight) / viewheight;
	viewwidth = viGetViewWidth();
	viewleft = viGetViewLeft();
	startupfrac = 1.0f;
	s2 = 0;
#endif

	starting = (startuptimer60 < TICKS(50));

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "blurGfxFisheye");

	s3 = 1;

	if (starting) {
		fullradius = viewheight * 0.5f;
		startupfrac = startuptimer60 / (PAL ? 41.0f : 50.0f);
		curradius = fullradius * startupfrac;
		spec = startupfrac * 255.0f;

		if (spec > 255) {
			spec = 255;
		}
	}

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	if (starting) {
		for (i = viewtop; i < viewtop + viewheight; i++) {
			if (i % 2) {
				if (i > viewtop + fullradius - curradius && i < viewtop + fullradius + curradius) {
					gDPSetEnvColorViaWord(gdl++, (colour & 0xffffff00) | (spec & 0xff));

					tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * startupfrac;
					gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);
				}
			}

			s2 += s3;

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	} else {
		f32 f22 = 1.0f;

		for (i = viewtop; i < viewtop + viewheight; i++) {
			if (hit == EYESPYHIT_DAMAGE) {
				alpha2 = (random() % 120) + 120;
				colour = 0xff333300 | (alpha2 & 0xff);
				f22 = ((random() % 32) + 220.0f) * (1.0f / 256.0f);

				gDPSetEnvColorViaWord(gdl++, colour);
			} else {
				gDPSetEnvColorViaWord(gdl++, 0xffffffff);
			}

			tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * f22;
			gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);

			if (hit == EYESPYHIT_DAMAGE) {
				gDPSetEnvColorViaWord(gdl++, 0xddaaaa99);

				tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight) * 1.03f;
				gdl = bviewCopyPixels(gdl, fb, i, 5, i, tmp, viewleft, viewwidth);
			}

			s2 += s3;

			if ((i % 2) == 0) {
				gDPSetEnvColorViaWord(gdl++, 0x00000055);
				gDPFillRectangle(gdl++, viewleft, i, viewleft + viewwidth, i + 1);
			}

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	}

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0xff);

	s3 = 1;

	if (shuttertime60 != 0 || starting) {
		s32 s7;
		s32 spa8 = viewheight * 0.5f;
		f32 f20;

		if (!starting) {
			shuttertime60 -= TICKS(12);

			if (shuttertime60 < 0) {
				shuttertime60 = -shuttertime60;
			}

			s7 = spa8 * (shuttertime60 / TICKS(12.0f));
		} else {
			s7 = curradius;
		}

		for (i = viewtop; i < viewtop + spa8 - s7; i++) {
			gdl = bviewDrawFisheyeRect(gdl, i, 0.0f, viewleft, viewwidth);
			gdl = bviewDrawFisheyeRect(gdl, viewtop + viewtop + viewheight - i, 0.0f, viewleft, viewwidth);
		}

		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x000000ff);

		tmp = (f32) one * halfheight;
		f20 = halfheight;

		for (i = viewtop + spa8 - s7; i <= viewtop + spa8; i++) {
			f32 f2;

			if (sqhalfheight > f20 * f20) {
				f2 = sqrtf(sqhalfheight - f20 * f20) * (1.0f / 160.0f);
			} else {
				f2 = 0.01f;
			}

			f20 += -tmp / s7;

			gdl = bviewDrawFisheyeRect(gdl, i, f2 * startupfrac, viewleft, viewwidth);

			if (i != viewtop + viewtop + viewheight - i) {
				gdl = bviewDrawFisheyeRect(gdl, viewtop + viewtop + viewheight - i, f2 * startupfrac, viewleft, viewwidth);
			}
		}
	} else {
		s2 = 0;

		for (i = viewtop; i < viewtop + viewheight; i++) {
			tmp = bview0f142d74(s2, f26, halfheight, sqhalfheight);
			gdl = bviewDrawFisheyeRect(gdl, i, tmp, viewleft, viewwidth);

			s2 += s3;

			if (s2 >= viewheight * 0.5f) {
				s2 = viewheight * 0.5f;
				s3 = -s3;
			}
		}
	}

#if PAL
	s3 = viGetViewTop();
#if VERSION >= VERSION_PAL_FINAL
	s2 = s3 + viGetViewHeight() - vpadding;
#else
	s2 = s3 + viGetViewHeight() - 16;
#endif

#if VERSION >= VERSION_PAL_FINAL
	for (i = 0; i < vpadding; i++)
#else
	for (i = 0; i < 16; i++)
#endif
	{
		gDPFillRectangle(gdl++, viewleft, s3 , viewleft + viewwidth, s3 + 1);
		gDPFillRectangle(gdl++, viewleft, s2, viewleft + viewwidth, s2 + 1);

		s3++;
		s2++;
	}
#endif

	return gdl;
}

/**
 * Draw a black rectangle to the side of the circular fisheye lens.
 *
 * These are each 1px high, and go from the edge of the circle to the edge of
 * the screen. There is one drawn on every row on both sides.
 */
Gfx *bviewDrawEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha)
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

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 4;
	vertices[3].colour = 4;

	gDPSetColorArray(gdl++, colours, 2);
	gDPSetVerticeArray(gdl++, vertices, 4);

	if (colours);

	gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);

	return gdl;
}

#if VERSION >= VERSION_JPN_FINAL
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

GLOBAL_ASM(
glabel bviewDrawEyespyMetrics
.late_rodata
glabel var7f1b6c2cjf
.word 0x3a83126f
.word 0x3f19999a
.word 0x3c23d70a
.word 0x3bcccccd
.text
/*  f143c5c:	27bdfbf0 */ 	addiu	$sp,$sp,-1040
/*  f143c60:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f143c64:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f143c68:	0080a825 */ 	move	$s5,$a0
/*  f143c6c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f143c70:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f143c74:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f143c78:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f143c7c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f143c80:	0c002f29 */ 	jal	viGetViewLeft
/*  f143c84:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f143c88:	0c002f0b */ 	jal	viGetViewWidth
/*  f143c8c:	afa2030c */ 	sw	$v0,0x30c($sp)
/*  f143c90:	0c002f2d */ 	jal	viGetViewTop
/*  f143c94:	afa20308 */ 	sw	$v0,0x308($sp)
/*  f143c98:	0c002f0f */ 	jal	viGetViewHeight
/*  f143c9c:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f143ca0:	8fae0308 */ 	lw	$t6,0x308($sp)
/*  f143ca4:	44806000 */ 	mtc1	$zero,$f12
/*  f143ca8:	afa20300 */ 	sw	$v0,0x300($sp)
/*  f143cac:	29c10141 */ 	slti	$at,$t6,0x141
/*  f143cb0:	14200004 */ 	bnez	$at,.JF0f143cc4
/*  f143cb4:	3c16800a */ 	lui	$s6,0x800a
/*  f143cb8:	240f0002 */ 	li	$t7,0x2
/*  f143cbc:	10000003 */ 	b	.JF0f143ccc
/*  f143cc0:	afaf02b4 */ 	sw	$t7,0x2b4($sp)
.JF0f143cc4:
/*  f143cc4:	24190001 */ 	li	$t9,0x1
/*  f143cc8:	afb902b4 */ 	sw	$t9,0x2b4($sp)
.JF0f143ccc:
/*  f143ccc:	26d6a630 */ 	addiu	$s6,$s6,-22992
/*  f143cd0:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f143cd4:	afa002b0 */ 	sw	$zero,0x2b0($sp)
/*  f143cd8:	8f020480 */ 	lw	$v0,0x480($t8)
/*  f143cdc:	10400007 */ 	beqz	$v0,.JF0f143cfc
/*  f143ce0:	00000000 */ 	nop
/*  f143ce4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f143ce8:	10600004 */ 	beqz	$v1,.JF0f143cfc
/*  f143cec:	00000000 */ 	nop
/*  f143cf0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f143cf4:	14400003 */ 	bnez	$v0,.JF0f143d04
/*  f143cf8:	00408025 */ 	move	$s0,$v0
.JF0f143cfc:
/*  f143cfc:	10000e6d */ 	b	.JF0f1476b4
/*  f143d00:	02a01025 */ 	move	$v0,$s5
.JF0f143d04:
/*  f143d04:	0fc54978 */ 	jal	optionsGetScreenSplit
/*  f143d08:	e7ac02c4 */ 	swc1	$f12,0x2c4($sp)
/*  f143d0c:	44800000 */ 	mtc1	$zero,$f0
/*  f143d10:	24010001 */ 	li	$at,0x1
/*  f143d14:	1441001f */ 	bne	$v0,$at,.JF0f143d94
/*  f143d18:	c7ac02c4 */ 	lwc1	$f12,0x2c4($sp)
/*  f143d1c:	8ece006c */ 	lw	$t6,0x6c($s6)
/*  f143d20:	00002825 */ 	move	$a1,$zero
/*  f143d24:	00001825 */ 	move	$v1,$zero
/*  f143d28:	11c00003 */ 	beqz	$t6,.JF0f143d38
/*  f143d2c:	00002025 */ 	move	$a0,$zero
/*  f143d30:	10000001 */ 	b	.JF0f143d38
/*  f143d34:	24050001 */ 	li	$a1,0x1
.JF0f143d38:
/*  f143d38:	8ecf0068 */ 	lw	$t7,0x68($s6)
/*  f143d3c:	00001025 */ 	move	$v0,$zero
/*  f143d40:	11e00003 */ 	beqz	$t7,.JF0f143d50
/*  f143d44:	00000000 */ 	nop
/*  f143d48:	10000001 */ 	b	.JF0f143d50
/*  f143d4c:	24030001 */ 	li	$v1,0x1
.JF0f143d50:
/*  f143d50:	8ed90064 */ 	lw	$t9,0x64($s6)
/*  f143d54:	13200003 */ 	beqz	$t9,.JF0f143d64
/*  f143d58:	00000000 */ 	nop
/*  f143d5c:	10000001 */ 	b	.JF0f143d64
/*  f143d60:	24040001 */ 	li	$a0,0x1
.JF0f143d64:
/*  f143d64:	8ed80070 */ 	lw	$t8,0x70($s6)
/*  f143d68:	13000003 */ 	beqz	$t8,.JF0f143d78
/*  f143d6c:	00000000 */ 	nop
/*  f143d70:	10000001 */ 	b	.JF0f143d78
/*  f143d74:	24020001 */ 	li	$v0,0x1
.JF0f143d78:
/*  f143d78:	00447021 */ 	addu	$t6,$v0,$a0
/*  f143d7c:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f143d80:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f143d84:	2b210002 */ 	slti	$at,$t9,0x2
/*  f143d88:	14200002 */ 	bnez	$at,.JF0f143d94
/*  f143d8c:	24180001 */ 	li	$t8,0x1
/*  f143d90:	afb802b0 */ 	sw	$t8,0x2b0($sp)
.JF0f143d94:
/*  f143d94:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f143d98:	c60400c8 */ 	lwc1	$f4,0xc8($s0)
/*  f143d9c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f143da0:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f143da4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f143da8:	c60400cc */ 	lwc1	$f4,0xcc($s0)
/*  f143dac:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f143db0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f143db4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f143db8:	44034000 */ 	mfc1	$v1,$f8
/*  f143dbc:	c60400d0 */ 	lwc1	$f4,0xd0($s0)
/*  f143dc0:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f143dc4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f143dc8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f143dcc:	44835000 */ 	mtc1	$v1,$f10
/*  f143dd0:	44044000 */ 	mfc1	$a0,$f8
/*  f143dd4:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f143dd8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f143ddc:	46040032 */ 	c.eq.s	$f0,$f4
/*  f143de0:	44054000 */ 	mfc1	$a1,$f8
/*  f143de4:	4500000f */ 	bc1f	.JF0f143e24
/*  f143de8:	00000000 */ 	nop
/*  f143dec:	44843000 */ 	mtc1	$a0,$f6
/*  f143df0:	00000000 */ 	nop
/*  f143df4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f143df8:	46080032 */ 	c.eq.s	$f0,$f8
/*  f143dfc:	00000000 */ 	nop
/*  f143e00:	45000008 */ 	bc1f	.JF0f143e24
/*  f143e04:	00000000 */ 	nop
/*  f143e08:	44855000 */ 	mtc1	$a1,$f10
/*  f143e0c:	00000000 */ 	nop
/*  f143e10:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f143e14:	46040032 */ 	c.eq.s	$f0,$f4
/*  f143e18:	00000000 */ 	nop
/*  f143e1c:	4501000f */ 	bc1t	.JF0f143e5c
/*  f143e20:	00000000 */ 	nop
.JF0f143e24:
/*  f143e24:	00630019 */ 	multu	$v1,$v1
/*  f143e28:	0000c012 */ 	mflo	$t8
/*  f143e2c:	00000000 */ 	nop
/*  f143e30:	00000000 */ 	nop
/*  f143e34:	00840019 */ 	multu	$a0,$a0
/*  f143e38:	00007012 */ 	mflo	$t6
/*  f143e3c:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f143e40:	00000000 */ 	nop
/*  f143e44:	00a50019 */ 	multu	$a1,$a1
/*  f143e48:	0000c812 */ 	mflo	$t9
/*  f143e4c:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f143e50:	44983000 */ 	mtc1	$t8,$f6
/*  f143e54:	00000000 */ 	nop
/*  f143e58:	46803320 */ 	cvt.s.w	$f12,$f6
.JF0f143e5c:
/*  f143e5c:	c4286c2c */ 	lwc1	$f8,0x6c2c($at)
/*  f143e60:	460c403c */ 	c.lt.s	$f8,$f12
/*  f143e64:	00000000 */ 	nop
/*  f143e68:	45020006 */ 	bc1fl	.JF0f143e84
/*  f143e6c:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
/*  f143e70:	0c012838 */ 	jal	sqrtf
/*  f143e74:	00000000 */ 	nop
/*  f143e78:	10000002 */ 	b	.JF0f143e84
/*  f143e7c:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
/*  f143e80:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
.JF0f143e84:
/*  f143e84:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f143e88:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f143e8c:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f143e90:	14600006 */ 	bnez	$v1,.JF0f143eac
/*  f143e94:	3c0500ff */ 	lui	$a1,0xff
/*  f143e98:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f143e9c:	0fc54bce */ 	jal	textSetPrimColour
/*  f143ea0:	02a02025 */ 	move	$a0,$s5
/*  f143ea4:	1000000e */ 	b	.JF0f143ee0
/*  f143ea8:	0040a825 */ 	move	$s5,$v0
.JF0f143eac:
/*  f143eac:	24010001 */ 	li	$at,0x1
/*  f143eb0:	14610007 */ 	bne	$v1,$at,.JF0f143ed0
/*  f143eb4:	02a02025 */ 	move	$a0,$s5
/*  f143eb8:	3c052244 */ 	lui	$a1,0x2244
/*  f143ebc:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f143ec0:	0fc54bce */ 	jal	textSetPrimColour
/*  f143ec4:	02a02025 */ 	move	$a0,$s5
/*  f143ec8:	10000005 */ 	b	.JF0f143ee0
/*  f143ecc:	0040a825 */ 	move	$s5,$v0
.JF0f143ed0:
/*  f143ed0:	3c05ff33 */ 	lui	$a1,0xff33
/*  f143ed4:	0fc54bce */ 	jal	textSetPrimColour
/*  f143ed8:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f143edc:	0040a825 */ 	move	$s5,$v0
.JF0f143ee0:
/*  f143ee0:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f143ee4:	57200188 */ 	bnezl	$t9,.JF0f144508
/*  f143ee8:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f143eec:	8fac0304 */ 	lw	$t4,0x304($sp)
/*  f143ef0:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f143ef4:	8fb0030c */ 	lw	$s0,0x30c($sp)
/*  f143ef8:	3c0bf600 */ 	lui	$t3,0xf600
/*  f143efc:	0198f821 */ 	addu	$ra,$t4,$t8
/*  f143f00:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f143f04:	27e6ffe8 */ 	addiu	$a2,$ra,-24
/*  f143f08:	30ce03ff */ 	andi	$t6,$a2,0x3ff
/*  f143f0c:	2619001a */ 	addiu	$t9,$s0,0x1a
/*  f143f10:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f143f14:	000e3080 */ 	sll	$a2,$t6,0x2
/*  f143f18:	00187380 */ 	sll	$t6,$t8,0xe
/*  f143f1c:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f143f20:	25870037 */ 	addiu	$a3,$t4,0x37
/*  f143f24:	26040019 */ 	addiu	$a0,$s0,0x19
/*  f143f28:	308803ff */ 	andi	$t0,$a0,0x3ff
/*  f143f2c:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f143f30:	01e6c825 */ 	or	$t9,$t7,$a2
/*  f143f34:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f143f38:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f143f3c:	0008c380 */ 	sll	$t8,$t0,0xe
/*  f143f40:	0307c825 */ 	or	$t9,$t8,$a3
/*  f143f44:	03004025 */ 	move	$t0,$t8
/*  f143f48:	27edffd6 */ 	addiu	$t5,$ra,-42
/*  f143f4c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143f50:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f143f54:	260f0020 */ 	addiu	$t7,$s0,0x20
/*  f143f58:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f143f5c:	00186880 */ 	sll	$t5,$t8,0x2
/*  f143f60:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f143f64:	2609001f */ 	addiu	$t1,$s0,0x1f
/*  f143f68:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f143f6c:	313903ff */ 	andi	$t9,$t1,0x3ff
/*  f143f70:	030b7025 */ 	or	$t6,$t8,$t3
/*  f143f74:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f143f78:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f143f7c:	02a02825 */ 	move	$a1,$s5
/*  f143f80:	01277025 */ 	or	$t6,$t1,$a3
/*  f143f84:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f143f88:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f143f8c:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f143f90:	3c013f80 */ 	lui	$at,0x3f80
/*  f143f94:	44818000 */ 	mtc1	$at,$f16
/*  f143f98:	448f2000 */ 	mtc1	$t7,$f4
/*  f143f9c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f143fa0:	44813000 */ 	mtc1	$at,$f6
/*  f143fa4:	468023a0 */ 	cvt.s.w	$f14,$f4
/*  f143fa8:	44845000 */ 	mtc1	$a0,$f10
/*  f143fac:	24180001 */ 	li	$t8,0x1
/*  f143fb0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143fb4:	02a05025 */ 	move	$t2,$s5
/*  f143fb8:	468050a0 */ 	cvt.s.w	$f2,$f10
/*  f143fbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143fc0:	3c014f00 */ 	lui	$at,0x4f00
/*  f143fc4:	46067003 */ 	div.s	$f0,$f14,$f6
/*  f143fc8:	46001200 */ 	add.s	$f8,$f2,$f0
/*  f143fcc:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f143fd0:	4459f800 */ 	cfc1	$t9,$31
/*  f143fd4:	44d8f800 */ 	ctc1	$t8,$31
/*  f143fd8:	00000000 */ 	nop
/*  f143fdc:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f143fe0:	4458f800 */ 	cfc1	$t8,$31
/*  f143fe4:	00000000 */ 	nop
/*  f143fe8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f143fec:	53000013 */ 	beqzl	$t8,.JF0f14403c
/*  f143ff0:	44182000 */ 	mfc1	$t8,$f4
/*  f143ff4:	44812000 */ 	mtc1	$at,$f4
/*  f143ff8:	24180001 */ 	li	$t8,0x1
/*  f143ffc:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f144000:	44d8f800 */ 	ctc1	$t8,$31
/*  f144004:	00000000 */ 	nop
/*  f144008:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f14400c:	4458f800 */ 	cfc1	$t8,$31
/*  f144010:	00000000 */ 	nop
/*  f144014:	33180078 */ 	andi	$t8,$t8,0x78
/*  f144018:	17000005 */ 	bnez	$t8,.JF0f144030
/*  f14401c:	00000000 */ 	nop
/*  f144020:	44182000 */ 	mfc1	$t8,$f4
/*  f144024:	3c018000 */ 	lui	$at,0x8000
/*  f144028:	10000007 */ 	b	.JF0f144048
/*  f14402c:	0301c025 */ 	or	$t8,$t8,$at
.JF0f144030:
/*  f144030:	10000005 */ 	b	.JF0f144048
/*  f144034:	2418ffff */ 	li	$t8,-1
/*  f144038:	44182000 */ 	mfc1	$t8,$f4
.JF0f14403c:
/*  f14403c:	00000000 */ 	nop
/*  f144040:	0700fffb */ 	bltz	$t8,.JF0f144030
/*  f144044:	00000000 */ 	nop
.JF0f144048:
/*  f144048:	3c0140e0 */ 	lui	$at,0x40e0
/*  f14404c:	44d9f800 */ 	ctc1	$t9,$31
/*  f144050:	44813000 */ 	mtc1	$at,$f6
/*  f144054:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f144058:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f14405c:	46067303 */ 	div.s	$f12,$f14,$f6
/*  f144060:	01ebc825 */ 	or	$t9,$t7,$t3
/*  f144064:	27eeffe7 */ 	addiu	$t6,$ra,-25
/*  f144068:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14406c:	0326c025 */ 	or	$t8,$t9,$a2
/*  f144070:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f144074:	240f0001 */ 	li	$t7,0x1
/*  f144078:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f14407c:	02a01025 */ 	move	$v0,$s5
/*  f144080:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144084:	afbf0090 */ 	sw	$ra,0x90($sp)
/*  f144088:	0119c025 */ 	or	$t8,$t0,$t9
/*  f14408c:	03e08025 */ 	move	$s0,$ra
/*  f144090:	02a01825 */ 	move	$v1,$s5
/*  f144094:	ad580004 */ 	sw	$t8,0x4($t2)
/*  f144098:	3c04f600 */ 	lui	$a0,0xf600
/*  f14409c:	3c014f00 */ 	lui	$at,0x4f00
/*  f1440a0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1440a4:	2605ffca */ 	addiu	$a1,$s0,-54
/*  f1440a8:	460c1200 */ 	add.s	$f8,$f2,$f12
/*  f1440ac:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f1440b0:	444ef800 */ 	cfc1	$t6,$31
/*  f1440b4:	44cff800 */ 	ctc1	$t7,$31
/*  f1440b8:	00000000 */ 	nop
/*  f1440bc:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f1440c0:	444ff800 */ 	cfc1	$t7,$31
/*  f1440c4:	00000000 */ 	nop
/*  f1440c8:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1440cc:	51e00013 */ 	beqzl	$t7,.JF0f14411c
/*  f1440d0:	440f2000 */ 	mfc1	$t7,$f4
/*  f1440d4:	44812000 */ 	mtc1	$at,$f4
/*  f1440d8:	240f0001 */ 	li	$t7,0x1
/*  f1440dc:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f1440e0:	44cff800 */ 	ctc1	$t7,$31
/*  f1440e4:	00000000 */ 	nop
/*  f1440e8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1440ec:	444ff800 */ 	cfc1	$t7,$31
/*  f1440f0:	00000000 */ 	nop
/*  f1440f4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1440f8:	15e00005 */ 	bnez	$t7,.JF0f144110
/*  f1440fc:	00000000 */ 	nop
/*  f144100:	440f2000 */ 	mfc1	$t7,$f4
/*  f144104:	3c018000 */ 	lui	$at,0x8000
/*  f144108:	10000007 */ 	b	.JF0f144128
/*  f14410c:	01e17825 */ 	or	$t7,$t7,$at
.JF0f144110:
/*  f144110:	10000005 */ 	b	.JF0f144128
/*  f144114:	240fffff */ 	li	$t7,-1
/*  f144118:	440f2000 */ 	mfc1	$t7,$f4
.JF0f14411c:
/*  f14411c:	00000000 */ 	nop
/*  f144120:	05e0fffb */ 	bltz	$t7,.JF0f144110
/*  f144124:	00000000 */ 	nop
.JF0f144128:
/*  f144128:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14412c:	44cef800 */ 	ctc1	$t6,$31
/*  f144130:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f144134:	03047025 */ 	or	$t6,$t8,$a0
/*  f144138:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f14413c:	2619ffd5 */ 	addiu	$t9,$s0,-43
/*  f144140:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f144144:	00187080 */ 	sll	$t6,$t8,0x2
/*  f144148:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f14414c:	012e7825 */ 	or	$t7,$t1,$t6
/*  f144150:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f144154:	8fb80308 */ 	lw	$t8,0x308($sp)
/*  f144158:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f14415c:	3c01f600 */ 	lui	$at,0xf600
/*  f144160:	02a01025 */ 	move	$v0,$s5
/*  f144164:	0338f821 */ 	addu	$ra,$t9,$t8
/*  f144168:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f14416c:	27eeffe8 */ 	addiu	$t6,$ra,-24
/*  f144170:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144174:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f144178:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f14417c:	00182880 */ 	sll	$a1,$t8,0x2
/*  f144180:	03246025 */ 	or	$t4,$t9,$a0
/*  f144184:	01857825 */ 	or	$t7,$t4,$a1
/*  f144188:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f14418c:	8fa60304 */ 	lw	$a2,0x304($sp)
/*  f144190:	27ebffe7 */ 	addiu	$t3,$ra,-25
/*  f144194:	316e03ff */ 	andi	$t6,$t3,0x3ff
/*  f144198:	24c60019 */ 	addiu	$a2,$a2,0x19
/*  f14419c:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f1441a0:	448b3000 */ 	mtc1	$t3,$f6
/*  f1441a4:	00193080 */ 	sll	$a2,$t9,0x2
/*  f1441a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1441ac:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f1441b0:	01e6c825 */ 	or	$t9,$t7,$a2
/*  f1441b4:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f1441b8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1441bc:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1441c0:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f1441c4:	8faa0304 */ 	lw	$t2,0x304($sp)
/*  f1441c8:	01c17825 */ 	or	$t7,$t6,$at
/*  f1441cc:	01e5c825 */ 	or	$t9,$t7,$a1
/*  f1441d0:	afbf0094 */ 	sw	$ra,0x94($sp)
/*  f1441d4:	01e02025 */ 	move	$a0,$t7
/*  f1441d8:	27efffe1 */ 	addiu	$t7,$ra,-31
/*  f1441dc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1441e0:	2548002b */ 	addiu	$t0,$t2,0x2b
/*  f1441e4:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f1441e8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1441ec:	00184080 */ 	sll	$t0,$t8,0x2
/*  f1441f0:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f1441f4:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1441f8:	254f001a */ 	addiu	$t7,$t2,0x1a
/*  f1441fc:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f144200:	03087025 */ 	or	$t6,$t8,$t0
/*  f144204:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f144208:	24190001 */ 	li	$t9,0x1
/*  f14420c:	444ff800 */ 	cfc1	$t7,$31
/*  f144210:	44d9f800 */ 	ctc1	$t9,$31
/*  f144214:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f144218:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14421c:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f144220:	02a01825 */ 	move	$v1,$s5
/*  f144224:	01987025 */ 	or	$t6,$t4,$t8
/*  f144228:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f14422c:	4459f800 */ 	cfc1	$t9,$31
/*  f144230:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144234:	3c014f00 */ 	lui	$at,0x4f00
/*  f144238:	33390078 */ 	andi	$t9,$t9,0x78
/*  f14423c:	53200013 */ 	beqzl	$t9,.JF0f14428c
/*  f144240:	44195000 */ 	mfc1	$t9,$f10
/*  f144244:	44815000 */ 	mtc1	$at,$f10
/*  f144248:	24190001 */ 	li	$t9,0x1
/*  f14424c:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f144250:	44d9f800 */ 	ctc1	$t9,$31
/*  f144254:	00000000 */ 	nop
/*  f144258:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f14425c:	4459f800 */ 	cfc1	$t9,$31
/*  f144260:	00000000 */ 	nop
/*  f144264:	33390078 */ 	andi	$t9,$t9,0x78
/*  f144268:	17200005 */ 	bnez	$t9,.JF0f144280
/*  f14426c:	00000000 */ 	nop
/*  f144270:	44195000 */ 	mfc1	$t9,$f10
/*  f144274:	3c018000 */ 	lui	$at,0x8000
/*  f144278:	10000007 */ 	b	.JF0f144298
/*  f14427c:	0321c825 */ 	or	$t9,$t9,$at
.JF0f144280:
/*  f144280:	10000005 */ 	b	.JF0f144298
/*  f144284:	2419ffff */ 	li	$t9,-1
/*  f144288:	44195000 */ 	mfc1	$t9,$f10
.JF0f14428c:
/*  f14428c:	00000000 */ 	nop
/*  f144290:	0720fffb */ 	bltz	$t9,.JF0f144280
/*  f144294:	00000000 */ 	nop
.JF0f144298:
/*  f144298:	44cff800 */ 	ctc1	$t7,$31
/*  f14429c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1442a0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1442a4:	460c1101 */ 	sub.s	$f4,$f2,$f12
/*  f1442a8:	2559002c */ 	addiu	$t9,$t2,0x2c
/*  f1442ac:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1442b0:	01c67825 */ 	or	$t7,$t6,$a2
/*  f1442b4:	00187080 */ 	sll	$t6,$t8,0x2
/*  f1442b8:	24180001 */ 	li	$t8,0x1
/*  f1442bc:	4459f800 */ 	cfc1	$t9,$31
/*  f1442c0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1442c4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1442c8:	008e7825 */ 	or	$t7,$a0,$t6
/*  f1442cc:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f1442d0:	02a04825 */ 	move	$t1,$s5
/*  f1442d4:	ad2f0000 */ 	sw	$t7,0x0($t1)
/*  f1442d8:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f1442dc:	4458f800 */ 	cfc1	$t8,$31
/*  f1442e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442e4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1442e8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1442ec:	53000013 */ 	beqzl	$t8,.JF0f14433c
/*  f1442f0:	44183000 */ 	mfc1	$t8,$f6
/*  f1442f4:	44813000 */ 	mtc1	$at,$f6
/*  f1442f8:	24180001 */ 	li	$t8,0x1
/*  f1442fc:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f144300:	44d8f800 */ 	ctc1	$t8,$31
/*  f144304:	00000000 */ 	nop
/*  f144308:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f14430c:	4458f800 */ 	cfc1	$t8,$31
/*  f144310:	00000000 */ 	nop
/*  f144314:	33180078 */ 	andi	$t8,$t8,0x78
/*  f144318:	17000005 */ 	bnez	$t8,.JF0f144330
/*  f14431c:	00000000 */ 	nop
/*  f144320:	44183000 */ 	mfc1	$t8,$f6
/*  f144324:	3c018000 */ 	lui	$at,0x8000
/*  f144328:	10000007 */ 	b	.JF0f144348
/*  f14432c:	0301c025 */ 	or	$t8,$t8,$at
.JF0f144330:
/*  f144330:	10000005 */ 	b	.JF0f144348
/*  f144334:	2418ffff */ 	li	$t8,-1
/*  f144338:	44183000 */ 	mfc1	$t8,$f6
.JF0f14433c:
/*  f14433c:	00000000 */ 	nop
/*  f144340:	0700fffb */ 	bltz	$t8,.JF0f144330
/*  f144344:	00000000 */ 	nop
.JF0f144348:
/*  f144348:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14434c:	44d9f800 */ 	ctc1	$t9,$31
/*  f144350:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144354:	01e8c825 */ 	or	$t9,$t7,$t0
/*  f144358:	ad390004 */ 	sw	$t9,0x4($t1)
/*  f14435c:	8fb8030c */ 	lw	$t8,0x30c($sp)
/*  f144360:	240f0001 */ 	li	$t7,0x1
/*  f144364:	02a01025 */ 	move	$v0,$s5
/*  f144368:	44984000 */ 	mtc1	$t8,$f8
/*  f14436c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144370:	3c014f00 */ 	lui	$at,0x4f00
/*  f144374:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f144378:	46005100 */ 	add.s	$f4,$f10,$f0
/*  f14437c:	46102180 */ 	add.s	$f6,$f4,$f16
/*  f144380:	444ef800 */ 	cfc1	$t6,$31
/*  f144384:	44cff800 */ 	ctc1	$t7,$31
/*  f144388:	00000000 */ 	nop
/*  f14438c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f144390:	444ff800 */ 	cfc1	$t7,$31
/*  f144394:	00000000 */ 	nop
/*  f144398:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f14439c:	51e00013 */ 	beqzl	$t7,.JF0f1443ec
/*  f1443a0:	440f4000 */ 	mfc1	$t7,$f8
/*  f1443a4:	44814000 */ 	mtc1	$at,$f8
/*  f1443a8:	240f0001 */ 	li	$t7,0x1
/*  f1443ac:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f1443b0:	44cff800 */ 	ctc1	$t7,$31
/*  f1443b4:	00000000 */ 	nop
/*  f1443b8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1443bc:	444ff800 */ 	cfc1	$t7,$31
/*  f1443c0:	00000000 */ 	nop
/*  f1443c4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1443c8:	15e00005 */ 	bnez	$t7,.JF0f1443e0
/*  f1443cc:	00000000 */ 	nop
/*  f1443d0:	440f4000 */ 	mfc1	$t7,$f8
/*  f1443d4:	3c018000 */ 	lui	$at,0x8000
/*  f1443d8:	10000007 */ 	b	.JF0f1443f8
/*  f1443dc:	01e17825 */ 	or	$t7,$t7,$at
.JF0f1443e0:
/*  f1443e0:	10000005 */ 	b	.JF0f1443f8
/*  f1443e4:	240fffff */ 	li	$t7,-1
/*  f1443e8:	440f4000 */ 	mfc1	$t7,$f8
.JF0f1443ec:
/*  f1443ec:	00000000 */ 	nop
/*  f1443f0:	05e0fffb */ 	bltz	$t7,.JF0f1443e0
/*  f1443f4:	00000000 */ 	nop
.JF0f1443f8:
/*  f1443f8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1443fc:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f144400:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f144404:	44cef800 */ 	ctc1	$t6,$31
/*  f144408:	3c01f600 */ 	lui	$at,0xf600
/*  f14440c:	03017025 */ 	or	$t6,$t8,$at
/*  f144410:	25f90038 */ 	addiu	$t9,$t7,0x38
/*  f144414:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f144418:	44845000 */ 	mtc1	$a0,$f10
/*  f14441c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f144420:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f144424:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f144428:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f14442c:	8fb8030c */ 	lw	$t8,0x30c($sp)
/*  f144430:	02a01825 */ 	move	$v1,$s5
/*  f144434:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144438:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14443c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144440:	24980001 */ 	addiu	$t8,$a0,0x1
/*  f144444:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f144448:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f14444c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f144450:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144454:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f144458:	01e1c825 */ 	or	$t9,$t7,$at
/*  f14445c:	240f0001 */ 	li	$t7,0x1
/*  f144460:	444ef800 */ 	cfc1	$t6,$31
/*  f144464:	44cff800 */ 	ctc1	$t7,$31
/*  f144468:	0325c025 */ 	or	$t8,$t9,$a1
/*  f14446c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f144470:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f144474:	3c014f00 */ 	lui	$at,0x4f00
/*  f144478:	444ff800 */ 	cfc1	$t7,$31
/*  f14447c:	00000000 */ 	nop
/*  f144480:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f144484:	51e00013 */ 	beqzl	$t7,.JF0f1444d4
/*  f144488:	440f4000 */ 	mfc1	$t7,$f8
/*  f14448c:	44814000 */ 	mtc1	$at,$f8
/*  f144490:	240f0001 */ 	li	$t7,0x1
/*  f144494:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f144498:	44cff800 */ 	ctc1	$t7,$31
/*  f14449c:	00000000 */ 	nop
/*  f1444a0:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1444a4:	444ff800 */ 	cfc1	$t7,$31
/*  f1444a8:	00000000 */ 	nop
/*  f1444ac:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1444b0:	15e00005 */ 	bnez	$t7,.JF0f1444c8
/*  f1444b4:	00000000 */ 	nop
/*  f1444b8:	440f4000 */ 	mfc1	$t7,$f8
/*  f1444bc:	3c018000 */ 	lui	$at,0x8000
/*  f1444c0:	10000007 */ 	b	.JF0f1444e0
/*  f1444c4:	01e17825 */ 	or	$t7,$t7,$at
.JF0f1444c8:
/*  f1444c8:	10000005 */ 	b	.JF0f1444e0
/*  f1444cc:	240fffff */ 	li	$t7,-1
/*  f1444d0:	440f4000 */ 	mfc1	$t7,$f8
.JF0f1444d4:
/*  f1444d4:	00000000 */ 	nop
/*  f1444d8:	05e0fffb */ 	bltz	$t7,.JF0f1444c8
/*  f1444dc:	00000000 */ 	nop
.JF0f1444e0:
/*  f1444e0:	44cef800 */ 	ctc1	$t6,$31
/*  f1444e4:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f1444e8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1444ec:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1444f0:	25cfffc9 */ 	addiu	$t7,$t6,-55
/*  f1444f4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1444f8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1444fc:	030e7825 */ 	or	$t7,$t8,$t6
/*  f144500:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f144504:	8ed90284 */ 	lw	$t9,0x284($s6)
.JF0f144508:
/*  f144508:	8fae030c */ 	lw	$t6,0x30c($sp)
/*  f14450c:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f144510:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f144514:	24010001 */ 	li	$at,0x1
/*  f144518:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f14451c:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144520:	2738ffff */ 	addiu	$t8,$t9,-1
/*  f144524:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f144528:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f14452c:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f144530:	afae0058 */ 	sw	$t6,0x58($sp)
/*  f144534:	03387021 */ 	addu	$t6,$t9,$t8
/*  f144538:	25ceffff */ 	addiu	$t6,$t6,-1
/*  f14453c:	1461006b */ 	bne	$v1,$at,.JF0f1446ec
/*  f144540:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f144544:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f144548:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f14454c:	3c0cf600 */ 	lui	$t4,0xf600
/*  f144550:	02a03025 */ 	move	$a2,$s5
/*  f144554:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f144558:	00187043 */ 	sra	$t6,$t8,0x1
/*  f14455c:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f144560:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f144564:	306f03ff */ 	andi	$t7,$v1,0x3ff
/*  f144568:	244e0007 */ 	addiu	$t6,$v0,0x7
/*  f14456c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f144570:	000f1880 */ 	sll	$v1,$t7,0x2
/*  f144574:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f144578:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f14457c:	03037025 */ 	or	$t6,$t8,$v1
/*  f144580:	244f0002 */ 	addiu	$t7,$v0,0x2
/*  f144584:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f144588:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14458c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144590:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f144594:	00187380 */ 	sll	$t6,$t8,0xe
/*  f144598:	01d93825 */ 	or	$a3,$t6,$t9
/*  f14459c:	03202825 */ 	move	$a1,$t9
/*  f1445a0:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f1445a4:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f1445a8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1445ac:	030c7025 */ 	or	$t6,$t8,$t4
/*  f1445b0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1445b4:	01c3c825 */ 	or	$t9,$t6,$v1
/*  f1445b8:	244fffff */ 	addiu	$t7,$v0,-1
/*  f1445bc:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1445c0:	02a04025 */ 	move	$t0,$s5
/*  f1445c4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1445c8:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f1445cc:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1445d0:	01ccc825 */ 	or	$t9,$t6,$t4
/*  f1445d4:	244ffffa */ 	addiu	$t7,$v0,-6
/*  f1445d8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1445dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1445e0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1445e4:	03235025 */ 	or	$t2,$t9,$v1
/*  f1445e8:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f1445ec:	02a04825 */ 	move	$t1,$s5
/*  f1445f0:	244ffffc */ 	addiu	$t7,$v0,-4
/*  f1445f4:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f1445f8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1445fc:	ad390004 */ 	sw	$t9,0x4($t1)
/*  f144600:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144604:	00187380 */ 	sll	$t6,$t8,0xe
/*  f144608:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f14460c:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f144610:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f144614:	02a05825 */ 	move	$t3,$s5
/*  f144618:	306f03ff */ 	andi	$t7,$v1,0x3ff
/*  f14461c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f144620:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144624:	24990007 */ 	addiu	$t9,$a0,0x7
/*  f144628:	3c01f600 */ 	lui	$at,0xf600
/*  f14462c:	03011825 */ 	or	$v1,$t8,$at
/*  f144630:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f144634:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f144638:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14463c:	00787025 */ 	or	$t6,$v1,$t8
/*  f144640:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f144644:	02a02825 */ 	move	$a1,$s5
/*  f144648:	248f0002 */ 	addiu	$t7,$a0,0x2
/*  f14464c:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f144650:	0008cb80 */ 	sll	$t9,$t0,0xe
/*  f144654:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144658:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f14465c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f144660:	032e3825 */ 	or	$a3,$t9,$t6
/*  f144664:	03204025 */ 	move	$t0,$t9
/*  f144668:	24990005 */ 	addiu	$t9,$a0,0x5
/*  f14466c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f144670:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f144674:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144678:	00787025 */ 	or	$t6,$v1,$t8
/*  f14467c:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f144680:	02a03025 */ 	move	$a2,$s5
/*  f144684:	2499ffff */ 	addiu	$t9,$a0,-1
/*  f144688:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f14468c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f144690:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f144694:	248efffa */ 	addiu	$t6,$a0,-6
/*  f144698:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14469c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1446a0:	00197880 */ 	sll	$t7,$t9,0x2
/*  f1446a4:	02a04825 */ 	move	$t1,$s5
/*  f1446a8:	00785025 */ 	or	$t2,$v1,$t8
/*  f1446ac:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1446b0:	010fc025 */ 	or	$t8,$t0,$t7
/*  f1446b4:	248efffc */ 	addiu	$t6,$a0,-4
/*  f1446b8:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f1446bc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1446c0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1446c4:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f1446c8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f1446cc:	02a01025 */ 	move	$v0,$s5
/*  f1446d0:	010fc025 */ 	or	$t8,$t0,$t7
/*  f1446d4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1446d8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1446dc:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1446e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1446e4:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f1446e8:	9323006b */ 	lbu	$v1,0x6b($t9)
.JF0f1446ec:
/*  f1446ec:	14600009 */ 	bnez	$v1,.JF0f144714
/*  f1446f0:	3c0f0050 */ 	lui	$t7,0x50
/*  f1446f4:	3c18000f */ 	lui	$t8,0xf
/*  f1446f8:	3c1400ff */ 	lui	$s4,0xff
/*  f1446fc:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f144700:	371800ff */ 	ori	$t8,$t8,0xff
/*  f144704:	369400a0 */ 	ori	$s4,$s4,0xa0
/*  f144708:	afaf02bc */ 	sw	$t7,0x2bc($sp)
/*  f14470c:	1000000f */ 	b	.JF0f14474c
/*  f144710:	afb802b8 */ 	sw	$t8,0x2b8($sp)
.JF0f144714:
/*  f144714:	24010001 */ 	li	$at,0x1
/*  f144718:	14610007 */ 	bne	$v1,$at,.JF0f144738
/*  f14471c:	3c02ff33 */ 	lui	$v0,0xff33
/*  f144720:	3c022244 */ 	lui	$v0,0x2244
/*  f144724:	3454ffff */ 	ori	$s4,$v0,0xffff
/*  f144728:	240e0fff */ 	li	$t6,0xfff
/*  f14472c:	afb402bc */ 	sw	$s4,0x2bc($sp)
/*  f144730:	10000006 */ 	b	.JF0f14474c
/*  f144734:	afae02b8 */ 	sw	$t6,0x2b8($sp)
.JF0f144738:
/*  f144738:	3c190f00 */ 	lui	$t9,0xf00
/*  f14473c:	345400ff */ 	ori	$s4,$v0,0xff
/*  f144740:	373900ff */ 	ori	$t9,$t9,0xff
/*  f144744:	afb402bc */ 	sw	$s4,0x2bc($sp)
/*  f144748:	afb902b8 */ 	sw	$t9,0x2b8($sp)
.JF0f14474c:
/*  f14474c:	0fc5baa5 */ 	jal	langGet
/*  f144750:	2404580c */ 	li	$a0,0x580c
/*  f144754:	3c017f1b */ 	lui	$at,0x7f1b
/*  f144758:	c4246c30 */ 	lwc1	$f4,0x6c30($at)
/*  f14475c:	c7aa02c8 */ 	lwc1	$f10,0x2c8($sp)
/*  f144760:	27b30310 */ 	addiu	$s3,$sp,0x310
/*  f144764:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144768:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f14476c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f144770:	24e76ad0 */ 	addiu	$a3,$a3,0x6ad0
/*  f144774:	24a56ac4 */ 	addiu	$a1,$a1,0x6ac4
/*  f144778:	02602025 */ 	move	$a0,$s3
/*  f14477c:	00403025 */ 	move	$a2,$v0
/*  f144780:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f144784:	0c004d95 */ 	jal	sprintf
/*  f144788:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f14478c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144790:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f144794:	3c078008 */ 	lui	$a3,0x8008
/*  f144798:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f14479c:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f1447a0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1447a4:	02603025 */ 	move	$a2,$s3
/*  f1447a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1447ac:	0fc55d49 */ 	jal	textMeasure
/*  f1447b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1447b4:	8faa02b4 */ 	lw	$t2,0x2b4($sp)
/*  f1447b8:	8fae030c */ 	lw	$t6,0x30c($sp)
/*  f1447bc:	8fb20304 */ 	lw	$s2,0x304($sp)
/*  f1447c0:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f1447c4:	030ac023 */ 	subu	$t8,$t8,$t2
/*  f1447c8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f1447cc:	030ac021 */ 	addu	$t8,$t8,$t2
/*  f1447d0:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1447d4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1447d8:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f1447dc:	03005025 */ 	move	$t2,$t8
/*  f1447e0:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f1447e4:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f1447e8:	0049c821 */ 	addu	$t9,$v0,$t1
/*  f1447ec:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f1447f0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1447f4:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f1447f8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1447fc:	afb202f0 */ 	sw	$s2,0x2f0($sp)
/*  f144800:	afaa0084 */ 	sw	$t2,0x84($sp)
/*  f144804:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f144808:	afa202f4 */ 	sw	$v0,0x2f4($sp)
/*  f14480c:	02a02025 */ 	move	$a0,$s5
/*  f144810:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144814:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144818:	0fc54bed */ 	jal	text0f153858
/*  f14481c:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144820:	0c002eeb */ 	jal	viGetWidth
/*  f144824:	0040a825 */ 	move	$s5,$v0
/*  f144828:	00028400 */ 	sll	$s0,$v0,0x10
/*  f14482c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144830:	0c002eef */ 	jal	viGetHeight
/*  f144834:	03208025 */ 	move	$s0,$t9
/*  f144838:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14483c:	3c188008 */ 	lui	$t8,0x8008
/*  f144840:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f144844:	8def0144 */ 	lw	$t7,0x144($t7)
/*  f144848:	8fae02b8 */ 	lw	$t6,0x2b8($sp)
/*  f14484c:	02a02025 */ 	move	$a0,$s5
/*  f144850:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144854:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144858:	02603825 */ 	move	$a3,$s3
/*  f14485c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144860:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144864:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144868:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14486c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144870:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144874:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144878:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f14487c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f144880:	0040a825 */ 	move	$s5,$v0
/*  f144884:	0fc5baa5 */ 	jal	langGet
/*  f144888:	2404580d */ 	li	$a0,0x580d
/*  f14488c:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f144890:	3c017f1b */ 	lui	$at,0x7f1b
/*  f144894:	c4246c34 */ 	lwc1	$f4,0x6c34($at)
/*  f144898:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f14489c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1448a0:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1448a4:	c5ea0060 */ 	lwc1	$f10,0x60($t7)
/*  f1448a8:	24e76ae0 */ 	addiu	$a3,$a3,0x6ae0
/*  f1448ac:	24a56ad4 */ 	addiu	$a1,$a1,0x6ad4
/*  f1448b0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f1448b4:	02602025 */ 	move	$a0,$s3
/*  f1448b8:	00403025 */ 	move	$a2,$v0
/*  f1448bc:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f1448c0:	0c004d95 */ 	jal	sprintf
/*  f1448c4:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f1448c8:	3c188008 */ 	lui	$t8,0x8008
/*  f1448cc:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f1448d0:	3c078008 */ 	lui	$a3,0x8008
/*  f1448d4:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f1448d8:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f1448dc:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f1448e0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1448e4:	02603025 */ 	move	$a2,$s3
/*  f1448e8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1448ec:	0fc55d49 */ 	jal	textMeasure
/*  f1448f0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1448f4:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1448f8:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f1448fc:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f144900:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f144904:	00697021 */ 	addu	$t6,$v1,$t1
/*  f144908:	02397821 */ 	addu	$t7,$s1,$t9
/*  f14490c:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f144910:	afae02e4 */ 	sw	$t6,0x2e4($sp)
/*  f144914:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144918:	02a02025 */ 	move	$a0,$s5
/*  f14491c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144920:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144924:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144928:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f14492c:	0fc54bed */ 	jal	text0f153858
/*  f144930:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144934:	0c002eeb */ 	jal	viGetWidth
/*  f144938:	0040a825 */ 	move	$s5,$v0
/*  f14493c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144940:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144944:	0c002eef */ 	jal	viGetHeight
/*  f144948:	01c08025 */ 	move	$s0,$t6
/*  f14494c:	3c198008 */ 	lui	$t9,0x8008
/*  f144950:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144954:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f144958:	8f390144 */ 	lw	$t9,0x144($t9)
/*  f14495c:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f144960:	02a02025 */ 	move	$a0,$s5
/*  f144964:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144968:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f14496c:	02603825 */ 	move	$a3,$s3
/*  f144970:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144974:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144978:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14497c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144980:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144984:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144988:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14498c:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144990:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144994:	0040a825 */ 	move	$s5,$v0
/*  f144998:	0fc5baa5 */ 	jal	langGet
/*  f14499c:	2404580e */ 	li	$a0,0x580e
/*  f1449a0:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1449a4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1449a8:	24a56ae4 */ 	addiu	$a1,$a1,0x6ae4
/*  f1449ac:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f1449b0:	02602025 */ 	move	$a0,$s3
/*  f1449b4:	00403025 */ 	move	$a2,$v0
/*  f1449b8:	c72a001c */ 	lwc1	$f10,0x1c($t9)
/*  f1449bc:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f1449c0:	44072000 */ 	mfc1	$a3,$f4
/*  f1449c4:	0c004d95 */ 	jal	sprintf
/*  f1449c8:	00000000 */ 	nop
/*  f1449cc:	3c188008 */ 	lui	$t8,0x8008
/*  f1449d0:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f1449d4:	3c078008 */ 	lui	$a3,0x8008
/*  f1449d8:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f1449dc:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f1449e0:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f1449e4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1449e8:	02603025 */ 	move	$a2,$s3
/*  f1449ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1449f0:	0fc55d49 */ 	jal	textMeasure
/*  f1449f4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1449f8:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1449fc:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f144a00:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f144a04:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f144a08:	00697021 */ 	addu	$t6,$v1,$t1
/*  f144a0c:	02397821 */ 	addu	$t7,$s1,$t9
/*  f144a10:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f144a14:	afae02e4 */ 	sw	$t6,0x2e4($sp)
/*  f144a18:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144a1c:	02a02025 */ 	move	$a0,$s5
/*  f144a20:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144a24:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144a28:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144a2c:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f144a30:	0fc54bed */ 	jal	text0f153858
/*  f144a34:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144a38:	0c002eeb */ 	jal	viGetWidth
/*  f144a3c:	0040a825 */ 	move	$s5,$v0
/*  f144a40:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144a44:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144a48:	0c002eef */ 	jal	viGetHeight
/*  f144a4c:	01c08025 */ 	move	$s0,$t6
/*  f144a50:	3c198008 */ 	lui	$t9,0x8008
/*  f144a54:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144a58:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f144a5c:	8f390144 */ 	lw	$t9,0x144($t9)
/*  f144a60:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f144a64:	02a02025 */ 	move	$a0,$s5
/*  f144a68:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144a6c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144a70:	02603825 */ 	move	$a3,$s3
/*  f144a74:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144a78:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144a7c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144a80:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144a84:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144a88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144a8c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144a90:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144a94:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144a98:	0040a825 */ 	move	$s5,$v0
/*  f144a9c:	0fc5baa5 */ 	jal	langGet
/*  f144aa0:	2404580f */ 	li	$a0,0x580f
/*  f144aa4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f144aa8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144aac:	24a56aec */ 	addiu	$a1,$a1,0x6aec
/*  f144ab0:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f144ab4:	02602025 */ 	move	$a0,$s3
/*  f144ab8:	00403025 */ 	move	$a2,$v0
/*  f144abc:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f144ac0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f144ac4:	44074000 */ 	mfc1	$a3,$f8
/*  f144ac8:	0c004d95 */ 	jal	sprintf
/*  f144acc:	00000000 */ 	nop
/*  f144ad0:	3c188008 */ 	lui	$t8,0x8008
/*  f144ad4:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f144ad8:	3c078008 */ 	lui	$a3,0x8008
/*  f144adc:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f144ae0:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f144ae4:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f144ae8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144aec:	02603025 */ 	move	$a2,$s3
/*  f144af0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144af4:	0fc55d49 */ 	jal	textMeasure
/*  f144af8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144afc:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f144b00:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f144b04:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f144b08:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f144b0c:	00697021 */ 	addu	$t6,$v1,$t1
/*  f144b10:	02397821 */ 	addu	$t7,$s1,$t9
/*  f144b14:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f144b18:	afae02e4 */ 	sw	$t6,0x2e4($sp)
/*  f144b1c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144b20:	02a02025 */ 	move	$a0,$s5
/*  f144b24:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144b28:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144b2c:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144b30:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f144b34:	0fc54bed */ 	jal	text0f153858
/*  f144b38:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144b3c:	0c002eeb */ 	jal	viGetWidth
/*  f144b40:	0040a825 */ 	move	$s5,$v0
/*  f144b44:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144b48:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144b4c:	0c002eef */ 	jal	viGetHeight
/*  f144b50:	01c08025 */ 	move	$s0,$t6
/*  f144b54:	3c198008 */ 	lui	$t9,0x8008
/*  f144b58:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144b5c:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f144b60:	8f390144 */ 	lw	$t9,0x144($t9)
/*  f144b64:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f144b68:	02a02025 */ 	move	$a0,$s5
/*  f144b6c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144b70:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144b74:	02603825 */ 	move	$a3,$s3
/*  f144b78:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144b7c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144b80:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144b84:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144b88:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144b8c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144b90:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144b94:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144b98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144b9c:	0040a825 */ 	move	$s5,$v0
/*  f144ba0:	0fc5baa5 */ 	jal	langGet
/*  f144ba4:	24045810 */ 	li	$a0,0x5810
/*  f144ba8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144bac:	24a56af4 */ 	addiu	$a1,$a1,0x6af4
/*  f144bb0:	02602025 */ 	move	$a0,$s3
/*  f144bb4:	0c004d95 */ 	jal	sprintf
/*  f144bb8:	00403025 */ 	move	$a2,$v0
/*  f144bbc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f144bc0:	8dce0140 */ 	lw	$t6,0x140($t6)
/*  f144bc4:	3c078008 */ 	lui	$a3,0x8008
/*  f144bc8:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f144bcc:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f144bd0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144bd4:	02603025 */ 	move	$a2,$s3
/*  f144bd8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144bdc:	0fc55d49 */ 	jal	textMeasure
/*  f144be0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144be4:	8fa402b0 */ 	lw	$a0,0x2b0($sp)
/*  f144be8:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f144bec:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f144bf0:	10800003 */ 	beqz	$a0,.JF0f144c00
/*  f144bf4:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f144bf8:	10000002 */ 	b	.JF0f144c04
/*  f144bfc:	2402fffd */ 	li	$v0,-3
.JF0f144c00:
/*  f144c00:	00001025 */ 	move	$v0,$zero
.JF0f144c04:
/*  f144c04:	00597821 */ 	addu	$t7,$v0,$t9
/*  f144c08:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f144c0c:	10800003 */ 	beqz	$a0,.JF0f144c1c
/*  f144c10:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f144c14:	10000002 */ 	b	.JF0f144c20
/*  f144c18:	24020012 */ 	li	$v0,0x12
.JF0f144c1c:
/*  f144c1c:	00001025 */ 	move	$v0,$zero
.JF0f144c20:
/*  f144c20:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f144c24:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f144c28:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f144c2c:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f144c30:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f144c34:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f144c38:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f144c3c:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f144c40:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144c44:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f144c48:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f144c4c:	02a02025 */ 	move	$a0,$s5
/*  f144c50:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144c54:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144c58:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144c5c:	0fc54bed */ 	jal	text0f153858
/*  f144c60:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144c64:	0c002eeb */ 	jal	viGetWidth
/*  f144c68:	0040a825 */ 	move	$s5,$v0
/*  f144c6c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144c70:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144c74:	0c002eef */ 	jal	viGetHeight
/*  f144c78:	03208025 */ 	move	$s0,$t9
/*  f144c7c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144c80:	3c188008 */ 	lui	$t8,0x8008
/*  f144c84:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f144c88:	8def0144 */ 	lw	$t7,0x144($t7)
/*  f144c8c:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f144c90:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f144c94:	02a02025 */ 	move	$a0,$s5
/*  f144c98:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144c9c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144ca0:	02603825 */ 	move	$a3,$s3
/*  f144ca4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144ca8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144cac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144cb0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144cb4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144cb8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144cbc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144cc0:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144cc4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f144cc8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144ccc:	0040a825 */ 	move	$s5,$v0
/*  f144cd0:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144cd4:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144cd8:	5460000b */ 	bnezl	$v1,.JF0f144d08
/*  f144cdc:	24010001 */ 	li	$at,0x1
/*  f144ce0:	0fc5baa5 */ 	jal	langGet
/*  f144ce4:	24045811 */ 	li	$a0,0x5811
/*  f144ce8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144cec:	24a56af8 */ 	addiu	$a1,$a1,0x6af8
/*  f144cf0:	02602025 */ 	move	$a0,$s3
/*  f144cf4:	0c004d95 */ 	jal	sprintf
/*  f144cf8:	00403025 */ 	move	$a2,$v0
/*  f144cfc:	10000014 */ 	b	.JF0f144d50
/*  f144d00:	00000000 */ 	nop
/*  f144d04:	24010001 */ 	li	$at,0x1
.JF0f144d08:
/*  f144d08:	1461000a */ 	bne	$v1,$at,.JF0f144d34
/*  f144d0c:	00000000 */ 	nop
/*  f144d10:	0fc5baa5 */ 	jal	langGet
/*  f144d14:	24045893 */ 	li	$a0,0x5893
/*  f144d18:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144d1c:	24a56afc */ 	addiu	$a1,$a1,0x6afc
/*  f144d20:	02602025 */ 	move	$a0,$s3
/*  f144d24:	0c004d95 */ 	jal	sprintf
/*  f144d28:	00403025 */ 	move	$a2,$v0
/*  f144d2c:	10000008 */ 	b	.JF0f144d50
/*  f144d30:	00000000 */ 	nop
.JF0f144d34:
/*  f144d34:	0fc5baa5 */ 	jal	langGet
/*  f144d38:	2404589c */ 	li	$a0,0x589c
/*  f144d3c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144d40:	24a56b00 */ 	addiu	$a1,$a1,0x6b00
/*  f144d44:	02602025 */ 	move	$a0,$s3
/*  f144d48:	0c004d95 */ 	jal	sprintf
/*  f144d4c:	00403025 */ 	move	$a2,$v0
.JF0f144d50:
/*  f144d50:	3c0e8008 */ 	lui	$t6,0x8008
/*  f144d54:	8dce0140 */ 	lw	$t6,0x140($t6)
/*  f144d58:	3c078008 */ 	lui	$a3,0x8008
/*  f144d5c:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f144d60:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f144d64:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144d68:	02603025 */ 	move	$a2,$s3
/*  f144d6c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144d70:	0fc55d49 */ 	jal	textMeasure
/*  f144d74:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144d78:	8fa402b0 */ 	lw	$a0,0x2b0($sp)
/*  f144d7c:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f144d80:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f144d84:	10800003 */ 	beqz	$a0,.JF0f144d94
/*  f144d88:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f144d8c:	10000002 */ 	b	.JF0f144d98
/*  f144d90:	2402fffd */ 	li	$v0,-3
.JF0f144d94:
/*  f144d94:	00001025 */ 	move	$v0,$zero
.JF0f144d98:
/*  f144d98:	00597821 */ 	addu	$t7,$v0,$t9
/*  f144d9c:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f144da0:	10800003 */ 	beqz	$a0,.JF0f144db0
/*  f144da4:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f144da8:	10000002 */ 	b	.JF0f144db4
/*  f144dac:	24020014 */ 	li	$v0,0x14
.JF0f144db0:
/*  f144db0:	00001025 */ 	move	$v0,$zero
.JF0f144db4:
/*  f144db4:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f144db8:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f144dbc:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f144dc0:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f144dc4:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f144dc8:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f144dcc:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f144dd0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f144dd4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144dd8:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f144ddc:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f144de0:	02a02025 */ 	move	$a0,$s5
/*  f144de4:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144de8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144dec:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144df0:	0fc54bed */ 	jal	text0f153858
/*  f144df4:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144df8:	0c002eeb */ 	jal	viGetWidth
/*  f144dfc:	0040a825 */ 	move	$s5,$v0
/*  f144e00:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144e04:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144e08:	0c002eef */ 	jal	viGetHeight
/*  f144e0c:	03208025 */ 	move	$s0,$t9
/*  f144e10:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144e14:	3c188008 */ 	lui	$t8,0x8008
/*  f144e18:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f144e1c:	8def0144 */ 	lw	$t7,0x144($t7)
/*  f144e20:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f144e24:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f144e28:	02a02025 */ 	move	$a0,$s5
/*  f144e2c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144e30:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144e34:	02603825 */ 	move	$a3,$s3
/*  f144e38:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144e3c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144e40:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144e44:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144e48:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144e4c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144e50:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144e54:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144e58:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f144e5c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144e60:	0040a825 */ 	move	$s5,$v0
/*  f144e64:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144e68:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144e6c:	54600048 */ 	bnezl	$v1,.JF0f144f90
/*  f144e70:	24010001 */ 	li	$at,0x1
/*  f144e74:	0fc5baa5 */ 	jal	langGet
/*  f144e78:	24045812 */ 	li	$a0,0x5812
/*  f144e7c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144e80:	24a56b04 */ 	addiu	$a1,$a1,0x6b04
/*  f144e84:	02602025 */ 	move	$a0,$s3
/*  f144e88:	0c004d95 */ 	jal	sprintf
/*  f144e8c:	00403025 */ 	move	$a2,$v0
/*  f144e90:	3c0e8008 */ 	lui	$t6,0x8008
/*  f144e94:	8dce0140 */ 	lw	$t6,0x140($t6)
/*  f144e98:	3c078008 */ 	lui	$a3,0x8008
/*  f144e9c:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f144ea0:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f144ea4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144ea8:	02603025 */ 	move	$a2,$s3
/*  f144eac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144eb0:	0fc55d49 */ 	jal	textMeasure
/*  f144eb4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144eb8:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f144ebc:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f144ec0:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f144ec4:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f144ec8:	03291823 */ 	subu	$v1,$t9,$t1
/*  f144ecc:	11e00003 */ 	beqz	$t7,.JF0f144edc
/*  f144ed0:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f144ed4:	10000002 */ 	b	.JF0f144ee0
/*  f144ed8:	2402fff3 */ 	li	$v0,-13
.JF0f144edc:
/*  f144edc:	00001025 */ 	move	$v0,$zero
.JF0f144ee0:
/*  f144ee0:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f144ee4:	00584021 */ 	addu	$t0,$v0,$t8
/*  f144ee8:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144eec:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f144ef0:	00697021 */ 	addu	$t6,$v1,$t1
/*  f144ef4:	01197821 */ 	addu	$t7,$t0,$t9
/*  f144ef8:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f144efc:	afae02e4 */ 	sw	$t6,0x2e4($sp)
/*  f144f00:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144f04:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f144f08:	02a02025 */ 	move	$a0,$s5
/*  f144f0c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144f10:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144f14:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f144f18:	0fc54bed */ 	jal	text0f153858
/*  f144f1c:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f144f20:	0c002eeb */ 	jal	viGetWidth
/*  f144f24:	0040a825 */ 	move	$s5,$v0
/*  f144f28:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144f2c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144f30:	0c002eef */ 	jal	viGetHeight
/*  f144f34:	01c08025 */ 	move	$s0,$t6
/*  f144f38:	3c198008 */ 	lui	$t9,0x8008
/*  f144f3c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f144f40:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f144f44:	8f390144 */ 	lw	$t9,0x144($t9)
/*  f144f48:	8fb802bc */ 	lw	$t8,0x2bc($sp)
/*  f144f4c:	8fae02b8 */ 	lw	$t6,0x2b8($sp)
/*  f144f50:	02a02025 */ 	move	$a0,$s5
/*  f144f54:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f144f58:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f144f5c:	02603825 */ 	move	$a3,$s3
/*  f144f60:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144f64:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144f68:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144f6c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144f70:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144f74:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144f78:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f144f7c:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f144f80:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f144f84:	1000008f */ 	b	.JF0f1451c4
/*  f144f88:	0040a825 */ 	move	$s5,$v0
/*  f144f8c:	24010001 */ 	li	$at,0x1
.JF0f144f90:
/*  f144f90:	14610047 */ 	bne	$v1,$at,.JF0f1450b0
/*  f144f94:	00000000 */ 	nop
/*  f144f98:	0fc5baa5 */ 	jal	langGet
/*  f144f9c:	240458d1 */ 	li	$a0,0x58d1
/*  f144fa0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f144fa4:	24a56b0c */ 	addiu	$a1,$a1,0x6b0c
/*  f144fa8:	02602025 */ 	move	$a0,$s3
/*  f144fac:	0c004d95 */ 	jal	sprintf
/*  f144fb0:	00403025 */ 	move	$a2,$v0
/*  f144fb4:	3c198008 */ 	lui	$t9,0x8008
/*  f144fb8:	8f390140 */ 	lw	$t9,0x140($t9)
/*  f144fbc:	3c078008 */ 	lui	$a3,0x8008
/*  f144fc0:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f144fc4:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f144fc8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144fcc:	02603025 */ 	move	$a2,$s3
/*  f144fd0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144fd4:	0fc55d49 */ 	jal	textMeasure
/*  f144fd8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144fdc:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f144fe0:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f144fe4:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144fe8:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f144fec:	01e91823 */ 	subu	$v1,$t7,$t1
/*  f144ff0:	13000003 */ 	beqz	$t8,.JF0f145000
/*  f144ff4:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f144ff8:	10000002 */ 	b	.JF0f145004
/*  f144ffc:	2402fff3 */ 	li	$v0,-13
.JF0f145000:
/*  f145000:	00001025 */ 	move	$v0,$zero
.JF0f145004:
/*  f145004:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f145008:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f14500c:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f145010:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f145014:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f145018:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f14501c:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f145020:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f145024:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145028:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f14502c:	02a02025 */ 	move	$a0,$s5
/*  f145030:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145034:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145038:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f14503c:	0fc54bed */ 	jal	text0f153858
/*  f145040:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145044:	0c002eeb */ 	jal	viGetWidth
/*  f145048:	0040a825 */ 	move	$s5,$v0
/*  f14504c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145050:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f145054:	0c002eef */ 	jal	viGetHeight
/*  f145058:	03208025 */ 	move	$s0,$t9
/*  f14505c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145060:	3c188008 */ 	lui	$t8,0x8008
/*  f145064:	8f180140 */ 	lw	$t8,0x140($t8)
/*  f145068:	8def0144 */ 	lw	$t7,0x144($t7)
/*  f14506c:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f145070:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145074:	02a02025 */ 	move	$a0,$s5
/*  f145078:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f14507c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145080:	02603825 */ 	move	$a3,$s3
/*  f145084:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145088:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14508c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145090:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145094:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f145098:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f14509c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1450a0:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f1450a4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1450a8:	10000046 */ 	b	.JF0f1451c4
/*  f1450ac:	0040a825 */ 	move	$s5,$v0
.JF0f1450b0:
/*  f1450b0:	0fc5baa5 */ 	jal	langGet
/*  f1450b4:	240458d2 */ 	li	$a0,0x58d2
/*  f1450b8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1450bc:	24a56b14 */ 	addiu	$a1,$a1,0x6b14
/*  f1450c0:	02602025 */ 	move	$a0,$s3
/*  f1450c4:	0c004d95 */ 	jal	sprintf
/*  f1450c8:	00403025 */ 	move	$a2,$v0
/*  f1450cc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1450d0:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f1450d4:	3c078008 */ 	lui	$a3,0x8008
/*  f1450d8:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f1450dc:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f1450e0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1450e4:	02603025 */ 	move	$a2,$s3
/*  f1450e8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1450ec:	0fc55d49 */ 	jal	textMeasure
/*  f1450f0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1450f4:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1450f8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f1450fc:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f145100:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f145104:	03091823 */ 	subu	$v1,$t8,$t1
/*  f145108:	11c00003 */ 	beqz	$t6,.JF0f145118
/*  f14510c:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145110:	10000002 */ 	b	.JF0f14511c
/*  f145114:	2402fff3 */ 	li	$v0,-13
.JF0f145118:
/*  f145118:	00001025 */ 	move	$v0,$zero
.JF0f14511c:
/*  f14511c:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f145120:	00594021 */ 	addu	$t0,$v0,$t9
/*  f145124:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f145128:	27b902e0 */ 	addiu	$t9,$sp,0x2e0
/*  f14512c:	00697821 */ 	addu	$t7,$v1,$t1
/*  f145130:	01187021 */ 	addu	$t6,$t0,$t8
/*  f145134:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f145138:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f14513c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145140:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f145144:	02a02025 */ 	move	$a0,$s5
/*  f145148:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f14514c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145150:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f145154:	0fc54bed */ 	jal	text0f153858
/*  f145158:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f14515c:	0c002eeb */ 	jal	viGetWidth
/*  f145160:	0040a825 */ 	move	$s5,$v0
/*  f145164:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145168:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f14516c:	0c002eef */ 	jal	viGetHeight
/*  f145170:	01e08025 */ 	move	$s0,$t7
/*  f145174:	3c188008 */ 	lui	$t8,0x8008
/*  f145178:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14517c:	8dce0140 */ 	lw	$t6,0x140($t6)
/*  f145180:	8f180144 */ 	lw	$t8,0x144($t8)
/*  f145184:	8fb902bc */ 	lw	$t9,0x2bc($sp)
/*  f145188:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f14518c:	02a02025 */ 	move	$a0,$s5
/*  f145190:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145194:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145198:	02603825 */ 	move	$a3,$s3
/*  f14519c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1451a0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1451a4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1451a8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1451ac:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1451b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1451b4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1451b8:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f1451bc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1451c0:	0040a825 */ 	move	$s5,$v0
.JF0f1451c4:
/*  f1451c4:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1451c8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1451cc:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f1451d0:	5460000b */ 	bnezl	$v1,.JF0f145200
/*  f1451d4:	24010001 */ 	li	$at,0x1
/*  f1451d8:	0fc5baa5 */ 	jal	langGet
/*  f1451dc:	24045813 */ 	li	$a0,0x5813
/*  f1451e0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1451e4:	24a56b1c */ 	addiu	$a1,$a1,0x6b1c
/*  f1451e8:	02602025 */ 	move	$a0,$s3
/*  f1451ec:	0c004d95 */ 	jal	sprintf
/*  f1451f0:	00403025 */ 	move	$a2,$v0
/*  f1451f4:	10000014 */ 	b	.JF0f145248
/*  f1451f8:	00000000 */ 	nop
/*  f1451fc:	24010001 */ 	li	$at,0x1
.JF0f145200:
/*  f145200:	1461000a */ 	bne	$v1,$at,.JF0f14522c
/*  f145204:	00000000 */ 	nop
/*  f145208:	0fc5baa5 */ 	jal	langGet
/*  f14520c:	24045892 */ 	li	$a0,0x5892
/*  f145210:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145214:	24a56b20 */ 	addiu	$a1,$a1,0x6b20
/*  f145218:	02602025 */ 	move	$a0,$s3
/*  f14521c:	0c004d95 */ 	jal	sprintf
/*  f145220:	00403025 */ 	move	$a2,$v0
/*  f145224:	10000008 */ 	b	.JF0f145248
/*  f145228:	00000000 */ 	nop
.JF0f14522c:
/*  f14522c:	0fc5baa5 */ 	jal	langGet
/*  f145230:	2404589b */ 	li	$a0,0x589b
/*  f145234:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145238:	24a56b24 */ 	addiu	$a1,$a1,0x6b24
/*  f14523c:	02602025 */ 	move	$a0,$s3
/*  f145240:	0c004d95 */ 	jal	sprintf
/*  f145244:	00403025 */ 	move	$a2,$v0
.JF0f145248:
/*  f145248:	3c198008 */ 	lui	$t9,0x8008
/*  f14524c:	8f390140 */ 	lw	$t9,0x140($t9)
/*  f145250:	3c078008 */ 	lui	$a3,0x8008
/*  f145254:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f145258:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f14525c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145260:	02603025 */ 	move	$a2,$s3
/*  f145264:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145268:	0fc55d49 */ 	jal	textMeasure
/*  f14526c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145270:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145274:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f145278:	02a02025 */ 	move	$a0,$s5
/*  f14527c:	11e00003 */ 	beqz	$t7,.JF0f14528c
/*  f145280:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145284:	10000002 */ 	b	.JF0f145290
/*  f145288:	24020003 */ 	li	$v0,0x3
.JF0f14528c:
/*  f14528c:	00001025 */ 	move	$v0,$zero
.JF0f145290:
/*  f145290:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145294:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f145298:	00587021 */ 	addu	$t6,$v0,$t8
/*  f14529c:	01c91823 */ 	subu	$v1,$t6,$t1
/*  f1452a0:	13200003 */ 	beqz	$t9,.JF0f1452b0
/*  f1452a4:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f1452a8:	10000002 */ 	b	.JF0f1452b4
/*  f1452ac:	2402fff5 */ 	li	$v0,-11
.JF0f1452b0:
/*  f1452b0:	00001025 */ 	move	$v0,$zero
.JF0f1452b4:
/*  f1452b4:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f1452b8:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1452bc:	0069c021 */ 	addu	$t8,$v1,$t1
/*  f1452c0:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f1452c4:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f1452c8:	27af02e0 */ 	addiu	$t7,$sp,0x2e0
/*  f1452cc:	010ec821 */ 	addu	$t9,$t0,$t6
/*  f1452d0:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f1452d4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1452d8:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f1452dc:	afb802e4 */ 	sw	$t8,0x2e4($sp)
/*  f1452e0:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1452e4:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1452e8:	0fc54bed */ 	jal	text0f153858
/*  f1452ec:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f1452f0:	0c002eeb */ 	jal	viGetWidth
/*  f1452f4:	0040a825 */ 	move	$s5,$v0
/*  f1452f8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1452fc:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f145300:	0c002eef */ 	jal	viGetHeight
/*  f145304:	03008025 */ 	move	$s0,$t8
/*  f145308:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14530c:	3c198008 */ 	lui	$t9,0x8008
/*  f145310:	8f390140 */ 	lw	$t9,0x140($t9)
/*  f145314:	8dce0144 */ 	lw	$t6,0x144($t6)
/*  f145318:	8faf02bc */ 	lw	$t7,0x2bc($sp)
/*  f14531c:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f145320:	02a02025 */ 	move	$a0,$s5
/*  f145324:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145328:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f14532c:	02603825 */ 	move	$a3,$s3
/*  f145330:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145334:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145338:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14533c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145340:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f145344:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145348:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f14534c:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f145350:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f145354:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145358:	0040a825 */ 	move	$s5,$v0
/*  f14535c:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f145360:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f145364:	10600003 */ 	beqz	$v1,.JF0f145374
/*  f145368:	24010002 */ 	li	$at,0x2
/*  f14536c:	1461000a */ 	bne	$v1,$at,.JF0f145398
/*  f145370:	00000000 */ 	nop
.JF0f145374:
/*  f145374:	0fc5baa5 */ 	jal	langGet
/*  f145378:	24045814 */ 	li	$a0,0x5814
/*  f14537c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145380:	24a56b28 */ 	addiu	$a1,$a1,0x6b28
/*  f145384:	02602025 */ 	move	$a0,$s3
/*  f145388:	0c004d95 */ 	jal	sprintf
/*  f14538c:	00403025 */ 	move	$a2,$v0
/*  f145390:	10000008 */ 	b	.JF0f1453b4
/*  f145394:	00000000 */ 	nop
.JF0f145398:
/*  f145398:	0fc5baa5 */ 	jal	langGet
/*  f14539c:	24045891 */ 	li	$a0,0x5891
/*  f1453a0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1453a4:	24a56b2c */ 	addiu	$a1,$a1,0x6b2c
/*  f1453a8:	02602025 */ 	move	$a0,$s3
/*  f1453ac:	0c004d95 */ 	jal	sprintf
/*  f1453b0:	00403025 */ 	move	$a2,$v0
.JF0f1453b4:
/*  f1453b4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1453b8:	8def0140 */ 	lw	$t7,0x140($t7)
/*  f1453bc:	3c078008 */ 	lui	$a3,0x8008
/*  f1453c0:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f1453c4:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f1453c8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1453cc:	02603025 */ 	move	$a2,$s3
/*  f1453d0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1453d4:	0fc55d49 */ 	jal	textMeasure
/*  f1453d8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1453dc:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1453e0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f1453e4:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f1453e8:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f1453ec:	03091823 */ 	subu	$v1,$t8,$t1
/*  f1453f0:	11c00003 */ 	beqz	$t6,.JF0f145400
/*  f1453f4:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f1453f8:	10000002 */ 	b	.JF0f145404
/*  f1453fc:	2402fffe */ 	li	$v0,-2
.JF0f145400:
/*  f145400:	00001025 */ 	move	$v0,$zero
.JF0f145404:
/*  f145404:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f145408:	00594021 */ 	addu	$t0,$v0,$t9
/*  f14540c:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f145410:	27b902e0 */ 	addiu	$t9,$sp,0x2e0
/*  f145414:	00697821 */ 	addu	$t7,$v1,$t1
/*  f145418:	01187021 */ 	addu	$t6,$t0,$t8
/*  f14541c:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f145420:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f145424:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145428:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f14542c:	02a02025 */ 	move	$a0,$s5
/*  f145430:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145434:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145438:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f14543c:	0fc54bed */ 	jal	text0f153858
/*  f145440:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145444:	0c002eeb */ 	jal	viGetWidth
/*  f145448:	0040a825 */ 	move	$s5,$v0
/*  f14544c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145450:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f145454:	0c002eef */ 	jal	viGetHeight
/*  f145458:	01e08025 */ 	move	$s0,$t7
/*  f14545c:	3c188008 */ 	lui	$t8,0x8008
/*  f145460:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145464:	8dce0140 */ 	lw	$t6,0x140($t6)
/*  f145468:	8f180144 */ 	lw	$t8,0x144($t8)
/*  f14546c:	8fb902bc */ 	lw	$t9,0x2bc($sp)
/*  f145470:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f145474:	02a02025 */ 	move	$a0,$s5
/*  f145478:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f14547c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145480:	02603825 */ 	move	$a3,$s3
/*  f145484:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145488:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14548c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145490:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145494:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145498:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f14549c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1454a0:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f1454a4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1454a8:	0fc54be5 */ 	jal	text0f153838
/*  f1454ac:	00402025 */ 	move	$a0,$v0
/*  f1454b0:	8ed80288 */ 	lw	$t8,0x288($s6)
/*  f1454b4:	0040a825 */ 	move	$s5,$v0
/*  f1454b8:	0fc5475a */ 	jal	optionsGetContpadNum1
/*  f1454bc:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f1454c0:	00028600 */ 	sll	$s0,$v0,0x18
/*  f1454c4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f1454c8:	00107603 */ 	sra	$t6,$s0,0x18
/*  f1454cc:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f1454d0:	01c08025 */ 	move	$s0,$t6
/*  f1454d4:	03202025 */ 	move	$a0,$t9
/*  f1454d8:	0c0053be */ 	jal	joyGetButtons
/*  f1454dc:	3405ffff */ 	li	$a1,0xffff
/*  f1454e0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1454e4:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1454e8:	01e02025 */ 	move	$a0,$t7
/*  f1454ec:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f1454f0:	0c0053ee */ 	jal	joyGetButtonsPressedThisFrame
/*  f1454f4:	3405ffff */ 	li	$a1,0xffff
/*  f1454f8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1454fc:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f145500:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f145504:	0c00536a */ 	jal	joyGetStickX
/*  f145508:	03002025 */ 	move	$a0,$t8
/*  f14550c:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f145510:	00102600 */ 	sll	$a0,$s0,0x18
/*  f145514:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f145518:	00147603 */ 	sra	$t6,$s4,0x18
/*  f14551c:	01c0a025 */ 	move	$s4,$t6
/*  f145520:	0c005394 */ 	jal	joyGetStickY
/*  f145524:	03202025 */ 	move	$a0,$t9
/*  f145528:	02a01825 */ 	move	$v1,$s5
/*  f14552c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145530:	3c0fe700 */ 	lui	$t7,0xe700
/*  f145534:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f145538:	02a02025 */ 	move	$a0,$s5
/*  f14553c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145540:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f145544:	3c18ba00 */ 	lui	$t8,0xba00
/*  f145548:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f14554c:	02a02825 */ 	move	$a1,$s5
/*  f145550:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f145554:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f145558:	3c0eba00 */ 	lui	$t6,0xba00
/*  f14555c:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f145560:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145564:	241900c0 */ 	li	$t9,0xc0
/*  f145568:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f14556c:	02a03025 */ 	move	$a2,$s5
/*  f145570:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f145574:	3c0fba00 */ 	lui	$t7,0xba00
/*  f145578:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f14557c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f145580:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145584:	02a03825 */ 	move	$a3,$s5
/*  f145588:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f14558c:	3c18b900 */ 	lui	$t8,0xb900
/*  f145590:	37180002 */ 	ori	$t8,$t8,0x2
/*  f145594:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145598:	02a01825 */ 	move	$v1,$s5
/*  f14559c:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f1455a0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1455a4:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1455a8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455ac:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f1455b0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1455b4:	02a02025 */ 	move	$a0,$s5
/*  f1455b8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1455bc:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f1455c0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455c4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1455c8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1455cc:	02a02825 */ 	move	$a1,$s5
/*  f1455d0:	240f2000 */ 	li	$t7,0x2000
/*  f1455d4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1455d8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1455dc:	37180903 */ 	ori	$t8,$t8,0x903
/*  f1455e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455e4:	240e0c00 */ 	li	$t6,0xc00
/*  f1455e8:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1455ec:	02a03025 */ 	move	$a2,$s5
/*  f1455f0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1455f4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1455f8:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f1455fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145600:	02a04025 */ 	move	$t0,$s5
/*  f145604:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f145608:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f14560c:	3c180050 */ 	lui	$t8,0x50
/*  f145610:	3c0fb900 */ 	lui	$t7,0xb900
/*  f145614:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f145618:	37184340 */ 	ori	$t8,$t8,0x4340
/*  f14561c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145620:	02a01825 */ 	move	$v1,$s5
/*  f145624:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f145628:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f14562c:	3c19fffd */ 	lui	$t9,0xfffd
/*  f145630:	3c0efcff */ 	lui	$t6,0xfcff
/*  f145634:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f145638:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f14563c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145640:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f145644:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145648:	44945000 */ 	mtc1	$s4,$f10
/*  f14564c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145650:	15e00204 */ 	bnez	$t7,.JF0f145e64
/*  f145654:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f145658:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f14565c:	24010002 */ 	li	$at,0x2
/*  f145660:	2407ffab */ 	li	$a3,-85
/*  f145664:	17010003 */ 	bne	$t8,$at,.JF0f145674
/*  f145668:	24130014 */ 	li	$s3,0x14
/*  f14566c:	10000001 */ 	b	.JF0f145674
/*  f145670:	2407ffb4 */ 	li	$a3,-76
.JF0f145674:
/*  f145674:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145678:	24010001 */ 	li	$at,0x1
/*  f14567c:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f145680:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f145684:	32580808 */ 	andi	$t8,$s2,0x808
/*  f145688:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f14568c:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f145690:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145694:	14600011 */ 	bnez	$v1,.JF0f1456dc
/*  f145698:	00000000 */ 	nop
/*  f14569c:	11e00002 */ 	beqz	$t7,.JF0f1456a8
/*  f1456a0:	02202825 */ 	move	$a1,$s1
/*  f1456a4:	24130028 */ 	li	$s3,0x28
.JF0f1456a8:
/*  f1456a8:	13000004 */ 	beqz	$t8,.JF0f1456bc
/*  f1456ac:	02403025 */ 	move	$a2,$s2
/*  f1456b0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1456b4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1456b8:	01c09825 */ 	move	$s3,$t6
.JF0f1456bc:
/*  f1456bc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1456c0:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f1456c4:	02a01825 */ 	move	$v1,$s5
/*  f1456c8:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1456cc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1456d0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1456d4:	1000002f */ 	b	.JF0f145794
/*  f1456d8:	26b50008 */ 	addiu	$s5,$s5,0x8
.JF0f1456dc:
/*  f1456dc:	14610017 */ 	bne	$v1,$at,.JF0f14573c
/*  f1456e0:	24130014 */ 	li	$s3,0x14
/*  f1456e4:	322e0808 */ 	andi	$t6,$s1,0x808
/*  f1456e8:	2413007f */ 	li	$s3,0x7f
/*  f1456ec:	11c00002 */ 	beqz	$t6,.JF0f1456f8
/*  f1456f0:	02202825 */ 	move	$a1,$s1
/*  f1456f4:	241300be */ 	li	$s3,0xbe
.JF0f1456f8:
/*  f1456f8:	32590808 */ 	andi	$t9,$s2,0x808
/*  f1456fc:	13200004 */ 	beqz	$t9,.JF0f145710
/*  f145700:	02403025 */ 	move	$a2,$s2
/*  f145704:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145708:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14570c:	01e09825 */ 	move	$s3,$t7
.JF0f145710:
/*  f145710:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145714:	00187200 */ 	sll	$t6,$t8,0x8
/*  f145718:	3c0b1020 */ 	lui	$t3,0x1020
/*  f14571c:	01cbc825 */ 	or	$t9,$t6,$t3
/*  f145720:	02a01825 */ 	move	$v1,$s5
/*  f145724:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145728:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f14572c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145730:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145734:	10000017 */ 	b	.JF0f145794
/*  f145738:	26b50008 */ 	addiu	$s5,$s5,0x8
.JF0f14573c:
/*  f14573c:	32380808 */ 	andi	$t8,$s1,0x808
/*  f145740:	13000002 */ 	beqz	$t8,.JF0f14574c
/*  f145744:	02202825 */ 	move	$a1,$s1
/*  f145748:	24130028 */ 	li	$s3,0x28
.JF0f14574c:
/*  f14574c:	324e0808 */ 	andi	$t6,$s2,0x808
/*  f145750:	11c00004 */ 	beqz	$t6,.JF0f145764
/*  f145754:	02403025 */ 	move	$a2,$s2
/*  f145758:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14575c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145760:	03209825 */ 	move	$s3,$t9
.JF0f145764:
/*  f145764:	00137083 */ 	sra	$t6,$s3,0x2
/*  f145768:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f14576c:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145770:	02a01825 */ 	move	$v1,$s5
/*  f145774:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f145778:	030f7025 */ 	or	$t6,$t8,$t7
/*  f14577c:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f145780:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145784:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145788:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14578c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145790:	3c0b1020 */ 	lui	$t3,0x1020
.JF0f145794:
/*  f145794:	8fbf02b4 */ 	lw	$ra,0x2b4($sp)
/*  f145798:	24f80008 */ 	addiu	$t8,$a3,0x8
/*  f14579c:	8fb00094 */ 	lw	$s0,0x94($sp)
/*  f1457a0:	031f0019 */ 	multu	$t8,$ra
/*  f1457a4:	8fb10304 */ 	lw	$s1,0x304($sp)
/*  f1457a8:	3c01f600 */ 	lui	$at,0xf600
/*  f1457ac:	02a02025 */ 	move	$a0,$s5
/*  f1457b0:	262c0012 */ 	addiu	$t4,$s1,0x12
/*  f1457b4:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f1457b8:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f1457bc:	262d000a */ 	addiu	$t5,$s1,0xa
/*  f1457c0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1457c4:	00007812 */ 	mflo	$t7
/*  f1457c8:	01f05021 */ 	addu	$t2,$t7,$s0
/*  f1457cc:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f1457d0:	00ff0019 */ 	multu	$a3,$ra
/*  f1457d4:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f1457d8:	01e17025 */ 	or	$t6,$t7,$at
/*  f1457dc:	01ccc825 */ 	or	$t9,$t6,$t4
/*  f1457e0:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1457e4:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f1457e8:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f1457ec:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f1457f0:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f1457f4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1457f8:	0000c012 */ 	mflo	$t8
/*  f1457fc:	03104021 */ 	addu	$t0,$t8,$s0
/*  f145800:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145804:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f145808:	030d7825 */ 	or	$t7,$t8,$t5
/*  f14580c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f145810:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145814:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f145818:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f14581c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f145820:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f145824:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f145828:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f14582c:	01595021 */ 	addu	$t2,$t2,$t9
/*  f145830:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f145834:	14600012 */ 	bnez	$v1,.JF0f145880
/*  f145838:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f14583c:	30ae0404 */ 	andi	$t6,$a1,0x404
/*  f145840:	11c00002 */ 	beqz	$t6,.JF0f14584c
/*  f145844:	24130014 */ 	li	$s3,0x14
/*  f145848:	24130028 */ 	li	$s3,0x28
.JF0f14584c:
/*  f14584c:	30d90404 */ 	andi	$t9,$a2,0x404
/*  f145850:	13200004 */ 	beqz	$t9,.JF0f145864
/*  f145854:	02a01825 */ 	move	$v1,$s5
/*  f145858:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14585c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145860:	03009825 */ 	move	$s3,$t8
.JF0f145864:
/*  f145864:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145868:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f14586c:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f145870:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145874:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145878:	10000028 */ 	b	.JF0f14591c
/*  f14587c:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145880:
/*  f145880:	24010001 */ 	li	$at,0x1
/*  f145884:	14610013 */ 	bne	$v1,$at,.JF0f1458d4
/*  f145888:	30b90404 */ 	andi	$t9,$a1,0x404
/*  f14588c:	30b80404 */ 	andi	$t8,$a1,0x404
/*  f145890:	13000002 */ 	beqz	$t8,.JF0f14589c
/*  f145894:	2413007f */ 	li	$s3,0x7f
/*  f145898:	241300be */ 	li	$s3,0xbe
.JF0f14589c:
/*  f14589c:	30cf0404 */ 	andi	$t7,$a2,0x404
/*  f1458a0:	11e00004 */ 	beqz	$t7,.JF0f1458b4
/*  f1458a4:	02a01825 */ 	move	$v1,$s5
/*  f1458a8:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1458ac:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1458b0:	01c09825 */ 	move	$s3,$t6
.JF0f1458b4:
/*  f1458b4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1458b8:	0019c200 */ 	sll	$t8,$t9,0x8
/*  f1458bc:	030b7825 */ 	or	$t7,$t8,$t3
/*  f1458c0:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f1458c4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1458c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1458cc:	10000013 */ 	b	.JF0f14591c
/*  f1458d0:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f1458d4:
/*  f1458d4:	13200002 */ 	beqz	$t9,.JF0f1458e0
/*  f1458d8:	24130014 */ 	li	$s3,0x14
/*  f1458dc:	24130028 */ 	li	$s3,0x28
.JF0f1458e0:
/*  f1458e0:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f1458e4:	13000004 */ 	beqz	$t8,.JF0f1458f8
/*  f1458e8:	02a01825 */ 	move	$v1,$s5
/*  f1458ec:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1458f0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1458f4:	01e09825 */ 	move	$s3,$t7
.JF0f1458f8:
/*  f1458f8:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f1458fc:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145900:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f145904:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145908:	032ec025 */ 	or	$t8,$t9,$t6
/*  f14590c:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145910:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145914:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145918:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f14591c:
/*  f14591c:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f145920:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145924:	3c01f600 */ 	lui	$at,0xf600
/*  f145928:	01c1c025 */ 	or	$t8,$t6,$at
/*  f14592c:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145930:	8fbf02b4 */ 	lw	$ra,0x2b4($sp)
/*  f145934:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145938:	030c7825 */ 	or	$t7,$t8,$t4
/*  f14593c:	02a02025 */ 	move	$a0,$s5
/*  f145940:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f145944:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f145948:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14594c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145950:	001f7880 */ 	sll	$t7,$ra,0x2
/*  f145954:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f145958:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f14595c:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f145960:	01ff7821 */ 	addu	$t7,$t7,$ra
/*  f145964:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f145968:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f14596c:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f145970:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145974:	01595021 */ 	addu	$t2,$t2,$t9
/*  f145978:	14600012 */ 	bnez	$v1,.JF0f1459c4
/*  f14597c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f145980:	30af0202 */ 	andi	$t7,$a1,0x202
/*  f145984:	11e00002 */ 	beqz	$t7,.JF0f145990
/*  f145988:	24130014 */ 	li	$s3,0x14
/*  f14598c:	24130028 */ 	li	$s3,0x28
.JF0f145990:
/*  f145990:	30d90202 */ 	andi	$t9,$a2,0x202
/*  f145994:	13200004 */ 	beqz	$t9,.JF0f1459a8
/*  f145998:	02a01825 */ 	move	$v1,$s5
/*  f14599c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1459a0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1459a4:	01c09825 */ 	move	$s3,$t6
.JF0f1459a8:
/*  f1459a8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1459ac:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f1459b0:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f1459b4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1459b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1459bc:	10000028 */ 	b	.JF0f145a60
/*  f1459c0:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f1459c4:
/*  f1459c4:	24010001 */ 	li	$at,0x1
/*  f1459c8:	14610013 */ 	bne	$v1,$at,.JF0f145a18
/*  f1459cc:	30b90202 */ 	andi	$t9,$a1,0x202
/*  f1459d0:	30ae0202 */ 	andi	$t6,$a1,0x202
/*  f1459d4:	11c00002 */ 	beqz	$t6,.JF0f1459e0
/*  f1459d8:	2413007f */ 	li	$s3,0x7f
/*  f1459dc:	241300be */ 	li	$s3,0xbe
.JF0f1459e0:
/*  f1459e0:	30d80202 */ 	andi	$t8,$a2,0x202
/*  f1459e4:	13000004 */ 	beqz	$t8,.JF0f1459f8
/*  f1459e8:	02a01825 */ 	move	$v1,$s5
/*  f1459ec:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1459f0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1459f4:	01e09825 */ 	move	$s3,$t7
.JF0f1459f8:
/*  f1459f8:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1459fc:	00197200 */ 	sll	$t6,$t9,0x8
/*  f145a00:	01cbc025 */ 	or	$t8,$t6,$t3
/*  f145a04:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145a08:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145a0c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145a10:	10000013 */ 	b	.JF0f145a60
/*  f145a14:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145a18:
/*  f145a18:	13200002 */ 	beqz	$t9,.JF0f145a24
/*  f145a1c:	24130014 */ 	li	$s3,0x14
/*  f145a20:	24130028 */ 	li	$s3,0x28
.JF0f145a24:
/*  f145a24:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f145a28:	11c00004 */ 	beqz	$t6,.JF0f145a3c
/*  f145a2c:	02a01825 */ 	move	$v1,$s5
/*  f145a30:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145a34:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145a38:	03009825 */ 	move	$s3,$t8
.JF0f145a3c:
/*  f145a3c:	00137083 */ 	sra	$t6,$s3,0x2
/*  f145a40:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f145a44:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f145a48:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145a4c:	032f7025 */ 	or	$t6,$t9,$t7
/*  f145a50:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f145a54:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145a58:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145a5c:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145a60:
/*  f145a60:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f145a64:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f145a68:	3c01f600 */ 	lui	$at,0xf600
/*  f145a6c:	01e17025 */ 	or	$t6,$t7,$at
/*  f145a70:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145a74:	8fbf02b4 */ 	lw	$ra,0x2b4($sp)
/*  f145a78:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f145a7c:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f145a80:	02a02025 */ 	move	$a0,$s5
/*  f145a84:	01ed7025 */ 	or	$t6,$t7,$t5
/*  f145a88:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f145a8c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f145a90:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f145a94:	001fc080 */ 	sll	$t8,$ra,0x2
/*  f145a98:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f145a9c:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f145aa0:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f145aa4:	031fc021 */ 	addu	$t8,$t8,$ra
/*  f145aa8:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f145aac:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f145ab0:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f145ab4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145ab8:	01595021 */ 	addu	$t2,$t2,$t9
/*  f145abc:	01184021 */ 	addu	$t0,$t0,$t8
/*  f145ac0:	14600012 */ 	bnez	$v1,.JF0f145b0c
/*  f145ac4:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f145ac8:	30b80101 */ 	andi	$t8,$a1,0x101
/*  f145acc:	13000002 */ 	beqz	$t8,.JF0f145ad8
/*  f145ad0:	24130014 */ 	li	$s3,0x14
/*  f145ad4:	24130028 */ 	li	$s3,0x28
.JF0f145ad8:
/*  f145ad8:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f145adc:	13200004 */ 	beqz	$t9,.JF0f145af0
/*  f145ae0:	02a01825 */ 	move	$v1,$s5
/*  f145ae4:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145ae8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145aec:	01e09825 */ 	move	$s3,$t7
.JF0f145af0:
/*  f145af0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145af4:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145af8:	371900ff */ 	ori	$t9,$t8,0xff
/*  f145afc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145b00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145b04:	10000028 */ 	b	.JF0f145ba8
/*  f145b08:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145b0c:
/*  f145b0c:	24010001 */ 	li	$at,0x1
/*  f145b10:	14610013 */ 	bne	$v1,$at,.JF0f145b60
/*  f145b14:	30b90101 */ 	andi	$t9,$a1,0x101
/*  f145b18:	30af0101 */ 	andi	$t7,$a1,0x101
/*  f145b1c:	11e00002 */ 	beqz	$t7,.JF0f145b28
/*  f145b20:	2413007f */ 	li	$s3,0x7f
/*  f145b24:	241300be */ 	li	$s3,0xbe
.JF0f145b28:
/*  f145b28:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f145b2c:	11c00004 */ 	beqz	$t6,.JF0f145b40
/*  f145b30:	02a01825 */ 	move	$v1,$s5
/*  f145b34:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145b38:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145b3c:	03009825 */ 	move	$s3,$t8
.JF0f145b40:
/*  f145b40:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145b44:	00197a00 */ 	sll	$t7,$t9,0x8
/*  f145b48:	01eb7025 */ 	or	$t6,$t7,$t3
/*  f145b4c:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f145b50:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145b54:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145b58:	10000013 */ 	b	.JF0f145ba8
/*  f145b5c:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145b60:
/*  f145b60:	13200002 */ 	beqz	$t9,.JF0f145b6c
/*  f145b64:	24130014 */ 	li	$s3,0x14
/*  f145b68:	24130028 */ 	li	$s3,0x28
.JF0f145b6c:
/*  f145b6c:	30cf0101 */ 	andi	$t7,$a2,0x101
/*  f145b70:	11e00004 */ 	beqz	$t7,.JF0f145b84
/*  f145b74:	02a01825 */ 	move	$v1,$s5
/*  f145b78:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145b7c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145b80:	01c09825 */ 	move	$s3,$t6
.JF0f145b84:
/*  f145b84:	00137883 */ 	sra	$t7,$s3,0x2
/*  f145b88:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f145b8c:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145b90:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145b94:	03387825 */ 	or	$t7,$t9,$t8
/*  f145b98:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145b9c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145ba0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145ba4:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145ba8:
/*  f145ba8:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f145bac:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f145bb0:	3c01f600 */ 	lui	$at,0xf600
/*  f145bb4:	03017825 */ 	or	$t7,$t8,$at
/*  f145bb8:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145bbc:	8fbf02b4 */ 	lw	$ra,0x2b4($sp)
/*  f145bc0:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f145bc4:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f145bc8:	02a02025 */ 	move	$a0,$s5
/*  f145bcc:	030d7825 */ 	or	$t7,$t8,$t5
/*  f145bd0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f145bd4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f145bd8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145bdc:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f145be0:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f145be4:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f145be8:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f145bec:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f145bf0:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145bf4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145bf8:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f145bfc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145c00:	01595021 */ 	addu	$t2,$t2,$t9
/*  f145c04:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f145c08:	14600012 */ 	bnez	$v1,.JF0f145c54
/*  f145c0c:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f145c10:	30ae0030 */ 	andi	$t6,$a1,0x30
/*  f145c14:	11c00002 */ 	beqz	$t6,.JF0f145c20
/*  f145c18:	24130014 */ 	li	$s3,0x14
/*  f145c1c:	24130028 */ 	li	$s3,0x28
.JF0f145c20:
/*  f145c20:	30d90030 */ 	andi	$t9,$a2,0x30
/*  f145c24:	13200004 */ 	beqz	$t9,.JF0f145c38
/*  f145c28:	02a01825 */ 	move	$v1,$s5
/*  f145c2c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145c30:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145c34:	03009825 */ 	move	$s3,$t8
.JF0f145c38:
/*  f145c38:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145c3c:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f145c40:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f145c44:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145c48:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145c4c:	10000028 */ 	b	.JF0f145cf0
/*  f145c50:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145c54:
/*  f145c54:	24010001 */ 	li	$at,0x1
/*  f145c58:	14610013 */ 	bne	$v1,$at,.JF0f145ca8
/*  f145c5c:	30b90030 */ 	andi	$t9,$a1,0x30
/*  f145c60:	30b80030 */ 	andi	$t8,$a1,0x30
/*  f145c64:	13000002 */ 	beqz	$t8,.JF0f145c70
/*  f145c68:	2413007f */ 	li	$s3,0x7f
/*  f145c6c:	241300be */ 	li	$s3,0xbe
.JF0f145c70:
/*  f145c70:	30cf0030 */ 	andi	$t7,$a2,0x30
/*  f145c74:	11e00004 */ 	beqz	$t7,.JF0f145c88
/*  f145c78:	02a01825 */ 	move	$v1,$s5
/*  f145c7c:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145c80:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145c84:	01c09825 */ 	move	$s3,$t6
.JF0f145c88:
/*  f145c88:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145c8c:	0019c200 */ 	sll	$t8,$t9,0x8
/*  f145c90:	030b7825 */ 	or	$t7,$t8,$t3
/*  f145c94:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145c98:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145c9c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145ca0:	10000013 */ 	b	.JF0f145cf0
/*  f145ca4:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145ca8:
/*  f145ca8:	13200002 */ 	beqz	$t9,.JF0f145cb4
/*  f145cac:	24130014 */ 	li	$s3,0x14
/*  f145cb0:	24130028 */ 	li	$s3,0x28
.JF0f145cb4:
/*  f145cb4:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f145cb8:	13000004 */ 	beqz	$t8,.JF0f145ccc
/*  f145cbc:	02a01825 */ 	move	$v1,$s5
/*  f145cc0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145cc4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145cc8:	01e09825 */ 	move	$s3,$t7
.JF0f145ccc:
/*  f145ccc:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f145cd0:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145cd4:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f145cd8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145cdc:	032ec025 */ 	or	$t8,$t9,$t6
/*  f145ce0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145ce4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145ce8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145cec:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145cf0:
/*  f145cf0:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f145cf4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145cf8:	3c01f600 */ 	lui	$at,0xf600
/*  f145cfc:	01c1c025 */ 	or	$t8,$t6,$at
/*  f145d00:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145d04:	8fbf02b4 */ 	lw	$ra,0x2b4($sp)
/*  f145d08:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145d0c:	030c7825 */ 	or	$t7,$t8,$t4
/*  f145d10:	02a02025 */ 	move	$a0,$s5
/*  f145d14:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f145d18:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f145d1c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f145d20:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145d24:	001f7880 */ 	sll	$t7,$ra,0x2
/*  f145d28:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f145d2c:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f145d30:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f145d34:	01ff7821 */ 	addu	$t7,$t7,$ra
/*  f145d38:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f145d3c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f145d40:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f145d44:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145d48:	01595021 */ 	addu	$t2,$t2,$t9
/*  f145d4c:	14600012 */ 	bnez	$v1,.JF0f145d98
/*  f145d50:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f145d54:	30af2000 */ 	andi	$t7,$a1,0x2000
/*  f145d58:	11e00002 */ 	beqz	$t7,.JF0f145d64
/*  f145d5c:	24130014 */ 	li	$s3,0x14
/*  f145d60:	24130028 */ 	li	$s3,0x28
.JF0f145d64:
/*  f145d64:	30d92000 */ 	andi	$t9,$a2,0x2000
/*  f145d68:	13200004 */ 	beqz	$t9,.JF0f145d7c
/*  f145d6c:	02a01825 */ 	move	$v1,$s5
/*  f145d70:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145d74:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145d78:	01c09825 */ 	move	$s3,$t6
.JF0f145d7c:
/*  f145d7c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145d80:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f145d84:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f145d88:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145d8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145d90:	10000028 */ 	b	.JF0f145e34
/*  f145d94:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145d98:
/*  f145d98:	24010001 */ 	li	$at,0x1
/*  f145d9c:	14610013 */ 	bne	$v1,$at,.JF0f145dec
/*  f145da0:	30b92000 */ 	andi	$t9,$a1,0x2000
/*  f145da4:	30ae2000 */ 	andi	$t6,$a1,0x2000
/*  f145da8:	11c00002 */ 	beqz	$t6,.JF0f145db4
/*  f145dac:	2413007f */ 	li	$s3,0x7f
/*  f145db0:	241300be */ 	li	$s3,0xbe
.JF0f145db4:
/*  f145db4:	30d82000 */ 	andi	$t8,$a2,0x2000
/*  f145db8:	13000004 */ 	beqz	$t8,.JF0f145dcc
/*  f145dbc:	02a01825 */ 	move	$v1,$s5
/*  f145dc0:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145dc4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145dc8:	01e09825 */ 	move	$s3,$t7
.JF0f145dcc:
/*  f145dcc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145dd0:	00197200 */ 	sll	$t6,$t9,0x8
/*  f145dd4:	01cbc025 */ 	or	$t8,$t6,$t3
/*  f145dd8:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145ddc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145de0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145de4:	10000013 */ 	b	.JF0f145e34
/*  f145de8:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145dec:
/*  f145dec:	13200002 */ 	beqz	$t9,.JF0f145df8
/*  f145df0:	24130014 */ 	li	$s3,0x14
/*  f145df4:	24130028 */ 	li	$s3,0x28
.JF0f145df8:
/*  f145df8:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f145dfc:	11c00004 */ 	beqz	$t6,.JF0f145e10
/*  f145e00:	02a01825 */ 	move	$v1,$s5
/*  f145e04:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145e08:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145e0c:	03009825 */ 	move	$s3,$t8
.JF0f145e10:
/*  f145e10:	00137083 */ 	sra	$t6,$s3,0x2
/*  f145e14:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f145e18:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f145e1c:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145e20:	032f7025 */ 	or	$t6,$t9,$t7
/*  f145e24:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f145e28:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145e2c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145e30:	ac690000 */ 	sw	$t1,0x0($v1)
.JF0f145e34:
/*  f145e34:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f145e38:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f145e3c:	3c01f600 */ 	lui	$at,0xf600
/*  f145e40:	01e17025 */ 	or	$t6,$t7,$at
/*  f145e44:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f145e48:	02a01825 */ 	move	$v1,$s5
/*  f145e4c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f145e50:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f145e54:	01ed7025 */ 	or	$t6,$t7,$t5
/*  f145e58:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145e5c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f145e60:	26b50008 */ 	addiu	$s5,$s5,0x8
.JF0f145e64:
/*  f145e64:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f145e68:	24010002 */ 	li	$at,0x2
/*  f145e6c:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145e70:	17010003 */ 	bne	$t8,$at,.JF0f145e80
/*  f145e74:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145e78:	10000002 */ 	b	.JF0f145e84
/*  f145e7c:	2407ffd0 */ 	li	$a3,-48
.JF0f145e80:
/*  f145e80:	2407ffc9 */ 	li	$a3,-55
.JF0f145e84:
/*  f145e84:	3c0142a0 */ 	lui	$at,0x42a0
/*  f145e88:	44817000 */ 	mtc1	$at,$f14
/*  f145e8c:	3c0142c0 */ 	lui	$at,0x42c0
/*  f145e90:	44818000 */ 	mtc1	$at,$f16
/*  f145e94:	24010001 */ 	li	$at,0x1
/*  f145e98:	00022600 */ 	sll	$a0,$v0,0x18
/*  f145e9c:	46106102 */ 	mul.s	$f4,$f12,$f16
/*  f145ea0:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f145ea4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f145ea8:	44034000 */ 	mfc1	$v1,$f8
/*  f145eac:	00000000 */ 	nop
/*  f145eb0:	04610005 */ 	bgez	$v1,.JF0f145ec8
/*  f145eb4:	307300ff */ 	andi	$s3,$v1,0xff
/*  f145eb8:	00039823 */ 	negu	$s3,$v1
/*  f145ebc:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145ec0:	10000001 */ 	b	.JF0f145ec8
/*  f145ec4:	01e09825 */ 	move	$s3,$t7
.JF0f145ec8:
/*  f145ec8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145ecc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145ed0:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145ed4:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f145ed8:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145edc:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f145ee0:	14600006 */ 	bnez	$v1,.JF0f145efc
/*  f145ee4:	00000000 */ 	nop
/*  f145ee8:	02a01825 */ 	move	$v1,$s5
/*  f145eec:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145ef0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145ef4:	10000031 */ 	b	.JF0f145fbc
/*  f145ef8:	26b50008 */ 	addiu	$s5,$s5,0x8
.JF0f145efc:
/*  f145efc:	14610026 */ 	bne	$v1,$at,.JF0f145f98
/*  f145f00:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f145f04:	44935000 */ 	mtc1	$s3,$f10
/*  f145f08:	02a01825 */ 	move	$v1,$s5
/*  f145f0c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145f10:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145f14:	06610005 */ 	bgez	$s3,.JF0f145f2c
/*  f145f18:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f145f1c:	3c014f80 */ 	lui	$at,0x4f80
/*  f145f20:	44812000 */ 	mtc1	$at,$f4
/*  f145f24:	00000000 */ 	nop
/*  f145f28:	46040000 */ 	add.s	$f0,$f0,$f4
.JF0f145f2c:
/*  f145f2c:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f145f30:	3c014180 */ 	lui	$at,0x4180
/*  f145f34:	44813000 */ 	mtc1	$at,$f6
/*  f145f38:	3c014200 */ 	lui	$at,0x4200
/*  f145f3c:	44812000 */ 	mtc1	$at,$f4
/*  f145f40:	3c014020 */ 	lui	$at,0x4020
/*  f145f44:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f145f48:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145f4c:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f145f50:	440f5000 */ 	mfc1	$t7,$f10
/*  f145f54:	44815000 */ 	mtc1	$at,$f10
/*  f145f58:	000f7600 */ 	sll	$t6,$t7,0x18
/*  f145f5c:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f145f60:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f145f64:	44194000 */ 	mfc1	$t9,$f8
/*  f145f68:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f145f6c:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f145f70:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145f74:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f145f78:	440e3000 */ 	mfc1	$t6,$f6
/*  f145f7c:	00000000 */ 	nop
/*  f145f80:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f145f84:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f145f88:	032f7025 */ 	or	$t6,$t9,$t7
/*  f145f8c:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f145f90:	1000000a */ 	b	.JF0f145fbc
/*  f145f94:	ac780004 */ 	sw	$t8,0x4($v1)
.JF0f145f98:
/*  f145f98:	00137083 */ 	sra	$t6,$s3,0x2
/*  f145f9c:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f145fa0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f145fa4:	02a01825 */ 	move	$v1,$s5
/*  f145fa8:	01f97025 */ 	or	$t6,$t7,$t9
/*  f145fac:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f145fb0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145fb4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145fb8:	26b50008 */ 	addiu	$s5,$s5,0x8
.JF0f145fbc:
/*  f145fbc:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145fc0:	55e00050 */ 	bnezl	$t7,.JF0f146104
/*  f145fc4:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f145fc8:	1a800028 */ 	blez	$s4,.JF0f14606c
/*  f145fcc:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145fd0:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145fd4:	44819000 */ 	mtc1	$at,$f18
/*  f145fd8:	8faf02b4 */ 	lw	$t7,0x2b4($sp)
/*  f145fdc:	3c01f600 */ 	lui	$at,0xf600
/*  f145fe0:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f145fe4:	02a01825 */ 	move	$v1,$s5
/*  f145fe8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145fec:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f145ff0:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f145ff4:	440e2000 */ 	mfc1	$t6,$f4
/*  f145ff8:	00000000 */ 	nop
/*  f145ffc:	01c7c021 */ 	addu	$t8,$t6,$a3
/*  f146000:	030f0019 */ 	multu	$t8,$t7
/*  f146004:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f146008:	0000c812 */ 	mflo	$t9
/*  f14600c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f146010:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146014:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f146018:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f14601c:	03217025 */ 	or	$t6,$t9,$at
/*  f146020:	270f0015 */ 	addiu	$t7,$t8,0x15
/*  f146024:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f146028:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14602c:	01d87825 */ 	or	$t7,$t6,$t8
/*  f146030:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f146034:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f146038:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f14603c:	00f90019 */ 	multu	$a3,$t9
/*  f146040:	00007012 */ 	mflo	$t6
/*  f146044:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f146048:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f14604c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f146050:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146054:	270f0013 */ 	addiu	$t7,$t8,0x13
/*  f146058:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14605c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146060:	01d87825 */ 	or	$t7,$t6,$t8
/*  f146064:	10000026 */ 	b	.JF0f146100
/*  f146068:	ac6f0004 */ 	sw	$t7,0x4($v1)
.JF0f14606c:
/*  f14606c:	44819000 */ 	mtc1	$at,$f18
/*  f146070:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f146074:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f146078:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f14607c:	3c01f600 */ 	lui	$at,0xf600
/*  f146080:	00f90019 */ 	multu	$a3,$t9
/*  f146084:	02a01825 */ 	move	$v1,$s5
/*  f146088:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14608c:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f146090:	00007012 */ 	mflo	$t6
/*  f146094:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f146098:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14609c:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f1460a0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1460a4:	01c1c025 */ 	or	$t8,$t6,$at
/*  f1460a8:	25f90015 */ 	addiu	$t9,$t7,0x15
/*  f1460ac:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1460b0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1460b4:	030fc825 */ 	or	$t9,$t8,$t7
/*  f1460b8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1460bc:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f1460c0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1460c4:	44185000 */ 	mfc1	$t8,$f10
/*  f1460c8:	00000000 */ 	nop
/*  f1460cc:	03077821 */ 	addu	$t7,$t8,$a3
/*  f1460d0:	01f90019 */ 	multu	$t7,$t9
/*  f1460d4:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f1460d8:	00007012 */ 	mflo	$t6
/*  f1460dc:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f1460e0:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f1460e4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1460e8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1460ec:	270f0013 */ 	addiu	$t7,$t8,0x13
/*  f1460f0:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1460f4:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1460f8:	01d87825 */ 	or	$t7,$t6,$t8
/*  f1460fc:	ac6f0004 */ 	sw	$t7,0x4($v1)
.JF0f146100:
/*  f146100:	0004ce03 */ 	sra	$t9,$a0,0x18
.JF0f146104:
/*  f146104:	03202025 */ 	move	$a0,$t9
/*  f146108:	44842000 */ 	mtc1	$a0,$f4
/*  f14610c:	3c0141e0 */ 	lui	$at,0x41e0
/*  f146110:	44819000 */ 	mtc1	$at,$f18
/*  f146114:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f146118:	02a01025 */ 	move	$v0,$s5
/*  f14611c:	24010001 */ 	li	$at,0x1
/*  f146120:	46106182 */ 	mul.s	$f6,$f12,$f16
/*  f146124:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f146128:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f14612c:	44035000 */ 	mfc1	$v1,$f10
/*  f146130:	00000000 */ 	nop
/*  f146134:	04610005 */ 	bgez	$v1,.JF0f14614c
/*  f146138:	307300ff */ 	andi	$s3,$v1,0xff
/*  f14613c:	00039823 */ 	negu	$s3,$v1
/*  f146140:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146144:	10000001 */ 	b	.JF0f14614c
/*  f146148:	03009825 */ 	move	$s3,$t8
.JF0f14614c:
/*  f14614c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146150:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146154:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f146158:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f14615c:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146160:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146164:	14600005 */ 	bnez	$v1,.JF0f14617c
/*  f146168:	00000000 */ 	nop
/*  f14616c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146170:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146174:	10000031 */ 	b	.JF0f14623c
/*  f146178:	ac4f0004 */ 	sw	$t7,0x4($v0)
.JF0f14617c:
/*  f14617c:	14610026 */ 	bne	$v1,$at,.JF0f146218
/*  f146180:	02a01025 */ 	move	$v0,$s5
/*  f146184:	44932000 */ 	mtc1	$s3,$f4
/*  f146188:	02a01025 */ 	move	$v0,$s5
/*  f14618c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146190:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146194:	06610005 */ 	bgez	$s3,.JF0f1461ac
/*  f146198:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f14619c:	3c014f80 */ 	lui	$at,0x4f80
/*  f1461a0:	44813000 */ 	mtc1	$at,$f6
/*  f1461a4:	00000000 */ 	nop
/*  f1461a8:	46060000 */ 	add.s	$f0,$f0,$f6
.JF0f1461ac:
/*  f1461ac:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f1461b0:	3c014180 */ 	lui	$at,0x4180
/*  f1461b4:	44814000 */ 	mtc1	$at,$f8
/*  f1461b8:	3c014200 */ 	lui	$at,0x4200
/*  f1461bc:	44813000 */ 	mtc1	$at,$f6
/*  f1461c0:	3c014020 */ 	lui	$at,0x4020
/*  f1461c4:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f1461c8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f1461cc:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f1461d0:	44182000 */ 	mfc1	$t8,$f4
/*  f1461d4:	44812000 */ 	mtc1	$at,$f4
/*  f1461d8:	00187e00 */ 	sll	$t7,$t8,0x18
/*  f1461dc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f1461e0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1461e4:	440e5000 */ 	mfc1	$t6,$f10
/*  f1461e8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1461ec:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f1461f0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1461f4:	01f97025 */ 	or	$t6,$t7,$t9
/*  f1461f8:	440f4000 */ 	mfc1	$t7,$f8
/*  f1461fc:	00000000 */ 	nop
/*  f146200:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f146204:	0019c200 */ 	sll	$t8,$t9,0x8
/*  f146208:	01d87825 */ 	or	$t7,$t6,$t8
/*  f14620c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f146210:	1000000a */ 	b	.JF0f14623c
/*  f146214:	ac590004 */ 	sw	$t9,0x4($v0)
.JF0f146218:
/*  f146218:	00137883 */ 	sra	$t7,$s3,0x2
/*  f14621c:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f146220:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146224:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146228:	030e7825 */ 	or	$t7,$t8,$t6
/*  f14622c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f146230:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f146234:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146238:	ac490000 */ 	sw	$t1,0x0($v0)
.JF0f14623c:
/*  f14623c:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f146240:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f146244:	57000041 */ 	bnezl	$t8,.JF0f14634c
/*  f146248:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f14624c:	00ee0019 */ 	multu	$a3,$t6
/*  f146250:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f146254:	00007812 */ 	mflo	$t7
/*  f146258:	01e51821 */ 	addu	$v1,$t7,$a1
/*  f14625c:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f146260:	1880001d */ 	blez	$a0,.JF0f1462d8
/*  f146264:	00191b80 */ 	sll	$v1,$t9,0xe
/*  f146268:	46126282 */ 	mul.s	$f10,$f12,$f18
/*  f14626c:	3c01f600 */ 	lui	$at,0xf600
/*  f146270:	02a01025 */ 	move	$v0,$s5
/*  f146274:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146278:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f14627c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146280:	44193000 */ 	mfc1	$t9,$f6
/*  f146284:	00000000 */ 	nop
/*  f146288:	0327c021 */ 	addu	$t8,$t9,$a3
/*  f14628c:	030e0019 */ 	multu	$t8,$t6
/*  f146290:	00007812 */ 	mflo	$t7
/*  f146294:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f146298:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f14629c:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f1462a0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1462a4:	01c17825 */ 	or	$t7,$t6,$at
/*  f1462a8:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f1462ac:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1462b0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1462b4:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f1462b8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f1462bc:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f1462c0:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f1462c4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1462c8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1462cc:	00787025 */ 	or	$t6,$v1,$t8
/*  f1462d0:	1000001d */ 	b	.JF0f146348
/*  f1462d4:	ac4e0004 */ 	sw	$t6,0x4($v0)
.JF0f1462d8:
/*  f1462d8:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f1462dc:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f1462e0:	3c01f600 */ 	lui	$at,0xf600
/*  f1462e4:	00617825 */ 	or	$t7,$v1,$at
/*  f1462e8:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f1462ec:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1462f0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1462f4:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f1462f8:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f1462fc:	02a01025 */ 	move	$v0,$s5
/*  f146300:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f146304:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f146308:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14630c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f146310:	440f2000 */ 	mfc1	$t7,$f4
/*  f146314:	00000000 */ 	nop
/*  f146318:	01e7c821 */ 	addu	$t9,$t7,$a3
/*  f14631c:	03380019 */ 	multu	$t9,$t8
/*  f146320:	00007012 */ 	mflo	$t6
/*  f146324:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f146328:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f14632c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f146330:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f146334:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f146338:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14633c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f146340:	030e7825 */ 	or	$t7,$t8,$t6
/*  f146344:	ac4f0004 */ 	sw	$t7,0x4($v0)
.JF0f146348:
/*  f146348:	8ec40284 */ 	lw	$a0,0x284($s6)
.JF0f14634c:
/*  f14634c:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f146350:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f146354:	8c990480 */ 	lw	$t9,0x480($a0)
/*  f146358:	24010002 */ 	li	$at,0x2
/*  f14635c:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146360:	1460016c */ 	bnez	$v1,.JF0f146914
/*  f146364:	00000000 */ 	nop
/*  f146368:	17000334 */ 	bnez	$t8,.JF0f14703c
/*  f14636c:	8fae0308 */ 	lw	$t6,0x308($sp)
/*  f146370:	448e3000 */ 	mtc1	$t6,$f6
/*  f146374:	3c01420c */ 	lui	$at,0x420c
/*  f146378:	44816000 */ 	mtc1	$at,$f12
/*  f14637c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f146380:	3c0143b4 */ 	lui	$at,0x43b4
/*  f146384:	44817000 */ 	mtc1	$at,$f14
/*  f146388:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14638c:	44815000 */ 	mtc1	$at,$f10
/*  f146390:	44853000 */ 	mtc1	$a1,$f6
/*  f146394:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f146398:	460a4103 */ 	div.s	$f4,$f8,$f10
/*  f14639c:	3c013f00 */ 	lui	$at,0x3f00
/*  f1463a0:	270efff3 */ 	addiu	$t6,$t8,-13
/*  f1463a4:	afae02f0 */ 	sw	$t6,0x2f0($sp)
/*  f1463a8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1463ac:	44811000 */ 	mtc1	$at,$f2
/*  f1463b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1463b4:	02a01825 */ 	move	$v1,$s5
/*  f1463b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1463bc:	44819000 */ 	mtc1	$at,$f18
/*  f1463c0:	3c07f600 */ 	lui	$a3,0xf600
/*  f1463c4:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f1463c8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1463cc:	44193000 */ 	mfc1	$t9,$f6
/*  f1463d0:	00000000 */ 	nop
/*  f1463d4:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f1463d8:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f1463dc:	02a02025 */ 	move	$a0,$s5
/*  f1463e0:	c5e0001c */ 	lwc1	$f0,0x1c($t7)
/*  f1463e4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1463e8:	00000000 */ 	nop
/*  f1463ec:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f1463f0:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f1463f4:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f1463f8:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f1463fc:	44025000 */ 	mfc1	$v0,$f10
/*  f146400:	00000000 */ 	nop
/*  f146404:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146408:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f14640c:	440e2000 */ 	mfc1	$t6,$f4
/*  f146410:	04410005 */ 	bgez	$v0,.JF0f146428
/*  f146414:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f146418:	00029823 */ 	negu	$s3,$v0
/*  f14641c:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146420:	10000001 */ 	b	.JF0f146428
/*  f146424:	01e09825 */ 	move	$s3,$t7
.JF0f146428:
/*  f146428:	327900ff */ 	andi	$t9,$s3,0xff
/*  f14642c:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f146430:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146434:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146438:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14643c:	8fa502b4 */ 	lw	$a1,0x2b4($sp)
/*  f146440:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146444:	3c01f600 */ 	lui	$at,0xf600
/*  f146448:	00057880 */ 	sll	$t7,$a1,0x2
/*  f14644c:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f146450:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f146454:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146458:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f14645c:	01e02825 */ 	move	$a1,$t7
/*  f146460:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f146464:	01e1c825 */ 	or	$t9,$t7,$at
/*  f146468:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14646c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f146470:	032fc025 */ 	or	$t8,$t9,$t7
/*  f146474:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f146478:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14647c:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146480:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146484:	02a01825 */ 	move	$v1,$s5
/*  f146488:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f14648c:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146490:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f146494:	00187080 */ 	sll	$t6,$t8,0x2
/*  f146498:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14649c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1464a0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f1464a4:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1464a8:	8fa602b4 */ 	lw	$a2,0x2b4($sp)
/*  f1464ac:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1464b0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1464b4:	00067840 */ 	sll	$t7,$a2,0x1
/*  f1464b8:	01e03025 */ 	move	$a2,$t7
/*  f1464bc:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f1464c0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1464c4:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1464c8:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f1464cc:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1464d0:	c70a0020 */ 	lwc1	$f10,0x20($t8)
/*  f1464d4:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f1464d8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f1464dc:	00000000 */ 	nop
/*  f1464e0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1464e4:	00000000 */ 	nop
/*  f1464e8:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f1464ec:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1464f0:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f1464f4:	44022000 */ 	mfc1	$v0,$f4
/*  f1464f8:	00000000 */ 	nop
/*  f1464fc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146500:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f146504:	440f4000 */ 	mfc1	$t7,$f8
/*  f146508:	04410005 */ 	bgez	$v0,.JF0f146520
/*  f14650c:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f146510:	00029823 */ 	negu	$s3,$v0
/*  f146514:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146518:	10000001 */ 	b	.JF0f146520
/*  f14651c:	03009825 */ 	move	$s3,$t8
.JF0f146520:
/*  f146520:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146524:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146528:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f14652c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146530:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146534:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146538:	3c01f600 */ 	lui	$at,0xf600
/*  f14653c:	02a02025 */ 	move	$a0,$s5
/*  f146540:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f146544:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146548:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f14654c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146550:	01e1c025 */ 	or	$t8,$t7,$at
/*  f146554:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146558:	00197880 */ 	sll	$t7,$t9,0x2
/*  f14655c:	030f7025 */ 	or	$t6,$t8,$t7
/*  f146560:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146564:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146568:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f14656c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146570:	02a01825 */ 	move	$v1,$s5
/*  f146574:	03387823 */ 	subu	$t7,$t9,$t8
/*  f146578:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f14657c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146580:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146584:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146588:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f14658c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146590:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146594:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146598:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14659c:	3c01f600 */ 	lui	$at,0xf600
/*  f1465a0:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f1465a4:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1465a8:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f1465ac:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f1465b0:	c5e40024 */ 	lwc1	$f4,0x24($t7)
/*  f1465b4:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1465b8:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1465bc:	00000000 */ 	nop
/*  f1465c0:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f1465c4:	00000000 */ 	nop
/*  f1465c8:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f1465cc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1465d0:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f1465d4:	44024000 */ 	mfc1	$v0,$f8
/*  f1465d8:	00000000 */ 	nop
/*  f1465dc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1465e0:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1465e4:	44183000 */ 	mfc1	$t8,$f6
/*  f1465e8:	04410005 */ 	bgez	$v0,.JF0f146600
/*  f1465ec:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f1465f0:	00029823 */ 	negu	$s3,$v0
/*  f1465f4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1465f8:	10000001 */ 	b	.JF0f146600
/*  f1465fc:	01e09825 */ 	move	$s3,$t7
.JF0f146600:
/*  f146600:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146604:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146608:	373800ff */ 	ori	$t8,$t9,0xff
/*  f14660c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146610:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146614:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146618:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14661c:	02a02025 */ 	move	$a0,$s5
/*  f146620:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f146624:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146628:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f14662c:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f146630:	03077825 */ 	or	$t7,$t8,$a3
/*  f146634:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146638:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14663c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f146640:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146644:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146648:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f14664c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146650:	02a01825 */ 	move	$v1,$s5
/*  f146654:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f146658:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14665c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146660:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146664:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f146668:	00187380 */ 	sll	$t6,$t8,0xe
/*  f14666c:	01d97825 */ 	or	$t7,$t6,$t9
/*  f146670:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146674:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146678:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14667c:	03067021 */ 	addu	$t6,$t8,$a2
/*  f146680:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146684:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146688:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f14668c:	c7000028 */ 	lwc1	$f0,0x28($t8)
/*  f146690:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f146694:	00000000 */ 	nop
/*  f146698:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f14669c:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f1466a0:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f1466a4:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f1466a8:	44025000 */ 	mfc1	$v0,$f10
/*  f1466ac:	00000000 */ 	nop
/*  f1466b0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1466b4:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1466b8:	440f2000 */ 	mfc1	$t7,$f4
/*  f1466bc:	04410005 */ 	bgez	$v0,.JF0f1466d4
/*  f1466c0:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f1466c4:	00029823 */ 	negu	$s3,$v0
/*  f1466c8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1466cc:	10000001 */ 	b	.JF0f1466d4
/*  f1466d0:	03009825 */ 	move	$s3,$t8
.JF0f1466d4:
/*  f1466d4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1466d8:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1466dc:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f1466e0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1466e4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1466e8:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1466ec:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1466f0:	02a02025 */ 	move	$a0,$s5
/*  f1466f4:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f1466f8:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1466fc:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146700:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146704:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f146708:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f14670c:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146710:	030f7025 */ 	or	$t6,$t8,$t7
/*  f146714:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146718:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14671c:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146720:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146724:	02a01825 */ 	move	$v1,$s5
/*  f146728:	03387823 */ 	subu	$t7,$t9,$t8
/*  f14672c:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146730:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146734:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146738:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f14673c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146740:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146744:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146748:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14674c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146750:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146754:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146758:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f14675c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146760:	c5ea002c */ 	lwc1	$f10,0x2c($t7)
/*  f146764:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146768:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f14676c:	00000000 */ 	nop
/*  f146770:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f146774:	00000000 */ 	nop
/*  f146778:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f14677c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146780:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146784:	44022000 */ 	mfc1	$v0,$f4
/*  f146788:	00000000 */ 	nop
/*  f14678c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146790:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f146794:	44184000 */ 	mfc1	$t8,$f8
/*  f146798:	04410005 */ 	bgez	$v0,.JF0f1467b0
/*  f14679c:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f1467a0:	00029823 */ 	negu	$s3,$v0
/*  f1467a4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1467a8:	10000001 */ 	b	.JF0f1467b0
/*  f1467ac:	01e09825 */ 	move	$s3,$t7
.JF0f1467b0:
/*  f1467b0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1467b4:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1467b8:	373800ff */ 	ori	$t8,$t9,0xff
/*  f1467bc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1467c0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1467c4:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f1467c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1467cc:	02a02025 */ 	move	$a0,$s5
/*  f1467d0:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f1467d4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1467d8:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1467dc:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1467e0:	03017825 */ 	or	$t7,$t8,$at
/*  f1467e4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1467e8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1467ec:	01f87025 */ 	or	$t6,$t7,$t8
/*  f1467f0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1467f4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1467f8:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f1467fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146800:	3c01f600 */ 	lui	$at,0xf600
/*  f146804:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f146808:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14680c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146810:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146814:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f146818:	00187380 */ 	sll	$t6,$t8,0xe
/*  f14681c:	01d97825 */ 	or	$t7,$t6,$t9
/*  f146820:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146824:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146828:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14682c:	03067021 */ 	addu	$t6,$t8,$a2
/*  f146830:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146834:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146838:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f14683c:	c7040030 */ 	lwc1	$f4,0x30($t8)
/*  f146840:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f146844:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f146848:	00000000 */ 	nop
/*  f14684c:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146850:	00000000 */ 	nop
/*  f146854:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f146858:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14685c:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f146860:	44024000 */ 	mfc1	$v0,$f8
/*  f146864:	00000000 */ 	nop
/*  f146868:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14686c:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146870:	440f3000 */ 	mfc1	$t7,$f6
/*  f146874:	04410005 */ 	bgez	$v0,.JF0f14688c
/*  f146878:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f14687c:	00029823 */ 	negu	$s3,$v0
/*  f146880:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146884:	10000001 */ 	b	.JF0f14688c
/*  f146888:	03009825 */ 	move	$s3,$t8
.JF0f14688c:
/*  f14688c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146890:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146894:	02a01025 */ 	move	$v0,$s5
/*  f146898:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f14689c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1468a0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1468a4:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1468a8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1468ac:	02a01825 */ 	move	$v1,$s5
/*  f1468b0:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f1468b4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1468b8:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1468bc:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f1468c0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f1468c4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1468c8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f1468cc:	030f7025 */ 	or	$t6,$t8,$t7
/*  f1468d0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1468d4:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f1468d8:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f1468dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1468e0:	03387823 */ 	subu	$t7,$t9,$t8
/*  f1468e4:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1468e8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1468ec:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1468f0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f1468f4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f1468f8:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f1468fc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146900:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146904:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146908:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f14690c:	100001cb */ 	b	.JF0f14703c
/*  f146910:	afb902f4 */ 	sw	$t9,0x2f4($sp)
.JF0f146914:
/*  f146914:	14610181 */ 	bne	$v1,$at,.JF0f146f1c
/*  f146918:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f14691c:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f146920:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f146924:	02a01825 */ 	move	$v1,$s5
/*  f146928:	570001c5 */ 	bnezl	$t8,.JF0f147040
/*  f14692c:	02a01025 */ 	move	$v0,$s5
/*  f146930:	448f4000 */ 	mtc1	$t7,$f8
/*  f146934:	3c01420c */ 	lui	$at,0x420c
/*  f146938:	44816000 */ 	mtc1	$at,$f12
/*  f14693c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f146940:	3c0143b4 */ 	lui	$at,0x43b4
/*  f146944:	44817000 */ 	mtc1	$at,$f14
/*  f146948:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14694c:	44815000 */ 	mtc1	$at,$f10
/*  f146950:	44854000 */ 	mtc1	$a1,$f8
/*  f146954:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f146958:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f14695c:	3c013f00 */ 	lui	$at,0x3f00
/*  f146960:	270ffff3 */ 	addiu	$t7,$t8,-13
/*  f146964:	afaf02f0 */ 	sw	$t7,0x2f0($sp)
/*  f146968:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f14696c:	44811000 */ 	mtc1	$at,$f2
/*  f146970:	3c013f80 */ 	lui	$at,0x3f80
/*  f146974:	44819000 */ 	mtc1	$at,$f18
/*  f146978:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14697c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f146980:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f146984:	44194000 */ 	mfc1	$t9,$f8
/*  f146988:	00000000 */ 	nop
/*  f14698c:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146990:	8c8e0480 */ 	lw	$t6,0x480($a0)
/*  f146994:	02a02025 */ 	move	$a0,$s5
/*  f146998:	c5c0001c */ 	lwc1	$f0,0x1c($t6)
/*  f14699c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f1469a0:	00000000 */ 	nop
/*  f1469a4:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1469a8:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f1469ac:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f1469b0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1469b4:	44025000 */ 	mfc1	$v0,$f10
/*  f1469b8:	00000000 */ 	nop
/*  f1469bc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1469c0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1469c4:	440f3000 */ 	mfc1	$t7,$f6
/*  f1469c8:	04410005 */ 	bgez	$v0,.JF0f1469e0
/*  f1469cc:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f1469d0:	00029823 */ 	negu	$s3,$v0
/*  f1469d4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1469d8:	10000001 */ 	b	.JF0f1469e0
/*  f1469dc:	01c09825 */ 	move	$s3,$t6
.JF0f1469e0:
/*  f1469e0:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1469e4:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f1469e8:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1469ec:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f1469f0:	03197825 */ 	or	$t7,$t8,$t9
/*  f1469f4:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f1469f8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1469fc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146a00:	8fa502b4 */ 	lw	$a1,0x2b4($sp)
/*  f146a04:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146a08:	3c01f600 */ 	lui	$at,0xf600
/*  f146a0c:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f146a10:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f146a14:	03197821 */ 	addu	$t7,$t8,$t9
/*  f146a18:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146a1c:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f146a20:	03002825 */ 	move	$a1,$t8
/*  f146a24:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f146a28:	0301c825 */ 	or	$t9,$t8,$at
/*  f146a2c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146a30:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f146a34:	03387825 */ 	or	$t7,$t9,$t8
/*  f146a38:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146a3c:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146a40:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146a44:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a48:	02a01825 */ 	move	$v1,$s5
/*  f146a4c:	01d9c023 */ 	subu	$t8,$t6,$t9
/*  f146a50:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146a54:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146a58:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146a5c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146a60:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146a64:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146a68:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146a6c:	8fa602b4 */ 	lw	$a2,0x2b4($sp)
/*  f146a70:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146a74:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a78:	0006c040 */ 	sll	$t8,$a2,0x1
/*  f146a7c:	03003025 */ 	move	$a2,$t8
/*  f146a80:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f146a84:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146a88:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146a8c:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146a90:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146a94:	c5ea0020 */ 	lwc1	$f10,0x20($t7)
/*  f146a98:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146a9c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f146aa0:	00000000 */ 	nop
/*  f146aa4:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f146aa8:	00000000 */ 	nop
/*  f146aac:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146ab0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146ab4:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f146ab8:	44023000 */ 	mfc1	$v0,$f6
/*  f146abc:	00000000 */ 	nop
/*  f146ac0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146ac4:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146ac8:	44182000 */ 	mfc1	$t8,$f4
/*  f146acc:	04410005 */ 	bgez	$v0,.JF0f146ae4
/*  f146ad0:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f146ad4:	00029823 */ 	negu	$s3,$v0
/*  f146ad8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146adc:	10000001 */ 	b	.JF0f146ae4
/*  f146ae0:	01e09825 */ 	move	$s3,$t7
.JF0f146ae4:
/*  f146ae4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146ae8:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f146aec:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146af0:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f146af4:	032ec025 */ 	or	$t8,$t9,$t6
/*  f146af8:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146afc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146b00:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146b04:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146b08:	3c01f600 */ 	lui	$at,0xf600
/*  f146b0c:	02a02025 */ 	move	$a0,$s5
/*  f146b10:	00b97021 */ 	addu	$t6,$a1,$t9
/*  f146b14:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146b18:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146b1c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146b20:	01e1c825 */ 	or	$t9,$t7,$at
/*  f146b24:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146b28:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146b2c:	032f7025 */ 	or	$t6,$t9,$t7
/*  f146b30:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146b34:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146b38:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f146b3c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b40:	02a01825 */ 	move	$v1,$s5
/*  f146b44:	03197823 */ 	subu	$t7,$t8,$t9
/*  f146b48:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146b4c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146b50:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f146b54:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146b58:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146b5c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f146b60:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146b64:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146b68:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146b6c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b70:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146b74:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f146b78:	afb802f4 */ 	sw	$t8,0x2f4($sp)
/*  f146b7c:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146b80:	c5e60024 */ 	lwc1	$f6,0x24($t7)
/*  f146b84:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f146b88:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f146b8c:	00000000 */ 	nop
/*  f146b90:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f146b94:	00000000 */ 	nop
/*  f146b98:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146b9c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146ba0:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f146ba4:	44022000 */ 	mfc1	$v0,$f4
/*  f146ba8:	00000000 */ 	nop
/*  f146bac:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146bb0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f146bb4:	44194000 */ 	mfc1	$t9,$f8
/*  f146bb8:	04410005 */ 	bgez	$v0,.JF0f146bd0
/*  f146bbc:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f146bc0:	00029823 */ 	negu	$s3,$v0
/*  f146bc4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146bc8:	10000001 */ 	b	.JF0f146bd0
/*  f146bcc:	01e09825 */ 	move	$s3,$t7
.JF0f146bd0:
/*  f146bd0:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146bd4:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f146bd8:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146bdc:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146be0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146be4:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146be8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146bec:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146bf0:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146bf4:	3c01f600 */ 	lui	$at,0xf600
/*  f146bf8:	02a02025 */ 	move	$a0,$s5
/*  f146bfc:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f146c00:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146c04:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146c08:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146c0c:	01e1c025 */ 	or	$t8,$t7,$at
/*  f146c10:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146c14:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146c18:	030f7025 */ 	or	$t6,$t8,$t7
/*  f146c1c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146c20:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146c24:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146c28:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c2c:	02a01825 */ 	move	$v1,$s5
/*  f146c30:	03387823 */ 	subu	$t7,$t9,$t8
/*  f146c34:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146c38:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146c3c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146c40:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146c44:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146c48:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146c4c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146c50:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146c54:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146c58:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c5c:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146c60:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146c64:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146c68:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146c6c:	c5e00028 */ 	lwc1	$f0,0x28($t7)
/*  f146c70:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146c74:	00000000 */ 	nop
/*  f146c78:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f146c7c:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f146c80:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f146c84:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146c88:	44025000 */ 	mfc1	$v0,$f10
/*  f146c8c:	00000000 */ 	nop
/*  f146c90:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146c94:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146c98:	44183000 */ 	mfc1	$t8,$f6
/*  f146c9c:	04410005 */ 	bgez	$v0,.JF0f146cb4
/*  f146ca0:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f146ca4:	00029823 */ 	negu	$s3,$v0
/*  f146ca8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146cac:	10000001 */ 	b	.JF0f146cb4
/*  f146cb0:	01e09825 */ 	move	$s3,$t7
.JF0f146cb4:
/*  f146cb4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146cb8:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f146cbc:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146cc0:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f146cc4:	032ec025 */ 	or	$t8,$t9,$t6
/*  f146cc8:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146ccc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146cd0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146cd4:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146cd8:	3c01f600 */ 	lui	$at,0xf600
/*  f146cdc:	02a02025 */ 	move	$a0,$s5
/*  f146ce0:	00b97021 */ 	addu	$t6,$a1,$t9
/*  f146ce4:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146ce8:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146cec:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146cf0:	01e1c825 */ 	or	$t9,$t7,$at
/*  f146cf4:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146cf8:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146cfc:	032f7025 */ 	or	$t6,$t9,$t7
/*  f146d00:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146d04:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146d08:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f146d0c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146d10:	02a01825 */ 	move	$v1,$s5
/*  f146d14:	03197823 */ 	subu	$t7,$t8,$t9
/*  f146d18:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146d1c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146d20:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f146d24:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146d28:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146d2c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f146d30:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146d34:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146d38:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146d3c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146d40:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146d44:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f146d48:	afb802f4 */ 	sw	$t8,0x2f4($sp)
/*  f146d4c:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146d50:	c5ea002c */ 	lwc1	$f10,0x2c($t7)
/*  f146d54:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146d58:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f146d5c:	00000000 */ 	nop
/*  f146d60:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f146d64:	00000000 */ 	nop
/*  f146d68:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146d6c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146d70:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f146d74:	44023000 */ 	mfc1	$v0,$f6
/*  f146d78:	00000000 */ 	nop
/*  f146d7c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146d80:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146d84:	44192000 */ 	mfc1	$t9,$f4
/*  f146d88:	04410005 */ 	bgez	$v0,.JF0f146da0
/*  f146d8c:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f146d90:	00029823 */ 	negu	$s3,$v0
/*  f146d94:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146d98:	10000001 */ 	b	.JF0f146da0
/*  f146d9c:	01e09825 */ 	move	$s3,$t7
.JF0f146da0:
/*  f146da0:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146da4:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f146da8:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146dac:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146db0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146db4:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146db8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146dbc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146dc0:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146dc4:	3c01f600 */ 	lui	$at,0xf600
/*  f146dc8:	02a02025 */ 	move	$a0,$s5
/*  f146dcc:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f146dd0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146dd4:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146dd8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146ddc:	01e1c025 */ 	or	$t8,$t7,$at
/*  f146de0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146de4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146de8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f146dec:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146df0:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146df4:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146df8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146dfc:	3c01f600 */ 	lui	$at,0xf600
/*  f146e00:	03387823 */ 	subu	$t7,$t9,$t8
/*  f146e04:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146e08:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146e0c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146e10:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146e14:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146e18:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146e1c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146e20:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146e24:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146e28:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146e2c:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146e30:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146e34:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146e38:	c5e60030 */ 	lwc1	$f6,0x30($t7)
/*  f146e3c:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f146e40:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f146e44:	00000000 */ 	nop
/*  f146e48:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f146e4c:	00000000 */ 	nop
/*  f146e50:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146e54:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146e58:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f146e5c:	44022000 */ 	mfc1	$v0,$f4
/*  f146e60:	00000000 */ 	nop
/*  f146e64:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146e68:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f146e6c:	44184000 */ 	mfc1	$t8,$f8
/*  f146e70:	04410005 */ 	bgez	$v0,.JF0f146e88
/*  f146e74:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f146e78:	00029823 */ 	negu	$s3,$v0
/*  f146e7c:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146e80:	10000001 */ 	b	.JF0f146e88
/*  f146e84:	01e09825 */ 	move	$s3,$t7
.JF0f146e88:
/*  f146e88:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146e8c:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f146e90:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146e94:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f146e98:	032ec025 */ 	or	$t8,$t9,$t6
/*  f146e9c:	02a01025 */ 	move	$v0,$s5
/*  f146ea0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146ea4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f146ea8:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146eac:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146eb0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146eb4:	02a01825 */ 	move	$v1,$s5
/*  f146eb8:	00b97021 */ 	addu	$t6,$a1,$t9
/*  f146ebc:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146ec0:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146ec4:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146ec8:	01e1c825 */ 	or	$t9,$t7,$at
/*  f146ecc:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f146ed0:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146ed4:	032f7025 */ 	or	$t6,$t9,$t7
/*  f146ed8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f146edc:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146ee0:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f146ee4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146ee8:	03197823 */ 	subu	$t7,$t8,$t9
/*  f146eec:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146ef0:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146ef4:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f146ef8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146efc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146f00:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f146f04:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146f08:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146f0c:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f146f10:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f146f14:	10000049 */ 	b	.JF0f14703c
/*  f146f18:	afb802f4 */ 	sw	$t8,0x2f4($sp)
.JF0f146f1c:
/*  f146f1c:	448f2000 */ 	mtc1	$t7,$f4
/*  f146f20:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146f24:	44815000 */ 	mtc1	$at,$f10
/*  f146f28:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f146f2c:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f146f30:	8fa702b4 */ 	lw	$a3,0x2b4($sp)
/*  f146f34:	8fa80090 */ 	lw	$t0,0x90($sp)
/*  f146f38:	448e2000 */ 	mtc1	$t6,$f4
/*  f146f3c:	0007c900 */ 	sll	$t9,$a3,0x4
/*  f146f40:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f146f44:	0327c823 */ 	subu	$t9,$t9,$a3
/*  f146f48:	00193840 */ 	sll	$a3,$t9,0x1
/*  f146f4c:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f146f50:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f146f54:	44812000 */ 	mtc1	$at,$f4
/*  f146f58:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f146f5c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f146f60:	240500ff */ 	li	$a1,0xff
/*  f146f64:	2508fffd */ 	addiu	$t0,$t0,-3
/*  f146f68:	00002025 */ 	move	$a0,$zero
/*  f146f6c:	24060008 */ 	li	$a2,0x8
/*  f146f70:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f146f74:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f146f78:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f146f7c:	44034000 */ 	mfc1	$v1,$f8
/*  f146f80:	13200005 */ 	beqz	$t9,.JF0f146f98
/*  f146f84:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f146f88:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f146f8c:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f146f90:	2407000f */ 	li	$a3,0xf
/*  f146f94:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.JF0f146f98:
/*  f146f98:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146f9c:	02a01025 */ 	move	$v0,$s5
/*  f146fa0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146fa4:	8dee0490 */ 	lw	$t6,0x490($t7)
/*  f146fa8:	008e082a */ 	slt	$at,$a0,$t6
/*  f146fac:	54200003 */ 	bnezl	$at,.JF0f146fbc
/*  f146fb0:	30b800ff */ 	andi	$t8,$a1,0xff
/*  f146fb4:	24050088 */ 	li	$a1,0x88
/*  f146fb8:	30b800ff */ 	andi	$t8,$a1,0xff
.JF0f146fbc:
/*  f146fbc:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f146fc0:	032b7825 */ 	or	$t7,$t9,$t3
/*  f146fc4:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146fc8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f146fcc:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146fd0:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146fd4:	3c01f600 */ 	lui	$at,0xf600
/*  f146fd8:	02a01825 */ 	move	$v1,$s5
/*  f146fdc:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f146fe0:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146fe4:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146fe8:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146fec:	01c1c025 */ 	or	$t8,$t6,$at
/*  f146ff0:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146ff4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146ff8:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146ffc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f147000:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f147004:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f147008:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14700c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147010:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147014:	272ffffc */ 	addiu	$t7,$t9,-4
/*  f147018:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f14701c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f147020:	01d97825 */ 	or	$t7,$t6,$t9
/*  f147024:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147028:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f14702c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147030:	270efffb */ 	addiu	$t6,$t8,-5
/*  f147034:	1486ffd8 */ 	bne	$a0,$a2,.JF0f146f98
/*  f147038:	afae02f0 */ 	sw	$t6,0x2f0($sp)
.JF0f14703c:
/*  f14703c:	02a01025 */ 	move	$v0,$s5
.JF0f147040:
/*  f147040:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147044:	02a01825 */ 	move	$v1,$s5
/*  f147048:	3c19e700 */ 	lui	$t9,0xe700
/*  f14704c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f147050:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f147054:	3c0fba00 */ 	lui	$t7,0xba00
/*  f147058:	35ef0602 */ 	ori	$t7,$t7,0x602
/*  f14705c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147060:	24180040 */ 	li	$t8,0x40
/*  f147064:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f147068:	02a02025 */ 	move	$a0,$s5
/*  f14706c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f147070:	3c0eba00 */ 	lui	$t6,0xba00
/*  f147074:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f147078:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14707c:	3c190008 */ 	lui	$t9,0x8
/*  f147080:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147084:	02a02825 */ 	move	$a1,$s5
/*  f147088:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f14708c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f147090:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f147094:	3c180001 */ 	lui	$t8,0x1
/*  f147098:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f14709c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f1470a0:	8ece0298 */ 	lw	$t6,0x298($s6)
/*  f1470a4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1470a8:	05c10180 */ 	bgez	$t6,.JF0f1476ac
/*  f1470ac:	00000000 */ 	nop
/*  f1470b0:	8ed9029c */ 	lw	$t9,0x29c($s6)
/*  f1470b4:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f1470b8:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f1470bc:	0721017b */ 	bgez	$t9,.JF0f1476ac
/*  f1470c0:	8fa20300 */ 	lw	$v0,0x300($sp)
/*  f1470c4:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f1470c8:	25d9ff99 */ 	addiu	$t9,$t6,-103
/*  f1470cc:	44995000 */ 	mtc1	$t9,$f10
/*  f1470d0:	3c014188 */ 	lui	$at,0x4188
/*  f1470d4:	44810000 */ 	mtc1	$at,$f0
/*  f1470d8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f1470dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1470e0:	44814000 */ 	mtc1	$at,$f8
/*  f1470e4:	3c0141c8 */ 	lui	$at,0x41c8
/*  f1470e8:	8fae0308 */ 	lw	$t6,0x308($sp)
/*  f1470ec:	24190011 */ 	li	$t9,0x11
/*  f1470f0:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f1470f4:	240f000a */ 	li	$t7,0xa
/*  f1470f8:	02a02025 */ 	move	$a0,$s5
/*  f1470fc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f147100:	c7a602c8 */ 	lwc1	$f6,0x2c8($sp)
/*  f147104:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f147108:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f14710c:	44815000 */ 	mtc1	$at,$f10
/*  f147110:	44032000 */ 	mfc1	$v1,$f4
/*  f147114:	460a4103 */ 	div.s	$f4,$f8,$f10
/*  f147118:	448e4000 */ 	mtc1	$t6,$f8
/*  f14711c:	0060a025 */ 	move	$s4,$v1
/*  f147120:	468043a0 */ 	cvt.s.w	$f14,$f8
/*  f147124:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147128:	44053000 */ 	mfc1	$a1,$f6
/*  f14712c:	00000000 */ 	nop
/*  f147130:	28a10012 */ 	slti	$at,$a1,0x12
/*  f147134:	54200003 */ 	bnezl	$at,.JF0f147144
/*  f147138:	240100dc */ 	li	$at,0xdc
/*  f14713c:	24050011 */ 	li	$a1,0x11
/*  f147140:	240100dc */ 	li	$at,0xdc
.JF0f147144:
/*  f147144:	14410003 */ 	bne	$v0,$at,.JF0f147154
/*  f147148:	03252823 */ 	subu	$a1,$t9,$a1
/*  f14714c:	10000008 */ 	b	.JF0f147170
/*  f147150:	a3af00cf */ 	sb	$t7,0xcf($sp)
.JF0f147154:
/*  f147154:	240100b4 */ 	li	$at,0xb4
/*  f147158:	14410004 */ 	bne	$v0,$at,.JF0f14716c
/*  f14715c:	2418fff8 */ 	li	$t8,-8
/*  f147160:	2474ffff */ 	addiu	$s4,$v1,-1
/*  f147164:	10000002 */ 	b	.JF0f147170
/*  f147168:	a3b800cf */ 	sb	$t8,0xcf($sp)
.JF0f14716c:
/*  f14716c:	a3a000cf */ 	sb	$zero,0xcf($sp)
.JF0f147170:
/*  f147170:	afa500c8 */ 	sw	$a1,0xc8($sp)
/*  f147174:	0fc35617 */ 	jal	func0f0d479c
/*  f147178:	e7ae007c */ 	swc1	$f14,0x7c($sp)
/*  f14717c:	c7ae007c */ 	lwc1	$f14,0x7c($sp)
/*  f147180:	3c0eb600 */ 	lui	$t6,0xb600
/*  f147184:	24193000 */ 	li	$t9,0x3000
/*  f147188:	3c0fb700 */ 	lui	$t7,0xb700
/*  f14718c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f147190:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f147194:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f147198:	3c0efcff */ 	lui	$t6,0xfcff
/*  f14719c:	3c19fffe */ 	lui	$t9,0xfffe
/*  f1471a0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1471a4:	3739793c */ 	ori	$t9,$t9,0x793c
/*  f1471a8:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1471ac:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1471b0:	24180204 */ 	li	$t8,0x204
/*  f1471b4:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f1471b8:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f1471bc:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f1471c0:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f1471c4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1471c8:	3c0f0050 */ 	lui	$t7,0x50
/*  f1471cc:	3c19b900 */ 	lui	$t9,0xb900
/*  f1471d0:	24182000 */ 	li	$t8,0x2000
/*  f1471d4:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f1471d8:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f1471dc:	35ef41c8 */ 	ori	$t7,$t7,0x41c8
/*  f1471e0:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f1471e4:	ac4e0020 */ 	sw	$t6,0x20($v0)
/*  f1471e8:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f1471ec:	ac4f002c */ 	sw	$t7,0x2c($v0)
/*  f1471f0:	ac590028 */ 	sw	$t9,0x28($v0)
/*  f1471f4:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f1471f8:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f1471fc:	240100b4 */ 	li	$at,0xb4
/*  f147200:	270e003a */ 	addiu	$t6,$t8,0x3a
/*  f147204:	24550030 */ 	addiu	$s5,$v0,0x30
/*  f147208:	17210003 */ 	bne	$t9,$at,.JF0f147218
/*  f14720c:	afae02f0 */ 	sw	$t6,0x2f0($sp)
/*  f147210:	25c80005 */ 	addiu	$t0,$t6,0x5
/*  f147214:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.JF0f147218:
/*  f147218:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f14721c:	3c013f00 */ 	lui	$at,0x3f00
/*  f147220:	44813000 */ 	mtc1	$at,$f6
/*  f147224:	448f5000 */ 	mtc1	$t7,$f10
/*  f147228:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f14722c:	8faf030c */ 	lw	$t7,0x30c($sp)
/*  f147230:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f147234:	00009025 */ 	move	$s2,$zero
/*  f147238:	25f80022 */ 	addiu	$t8,$t7,0x22
/*  f14723c:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f147240:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f147244:	44812000 */ 	mtc1	$at,$f4
/*  f147248:	00000000 */ 	nop
/*  f14724c:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f147250:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f147254:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f147258:	44195000 */ 	mfc1	$t9,$f10
/*  f14725c:	00000000 */ 	nop
/*  f147260:	03390019 */ 	multu	$t9,$t9
/*  f147264:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f147268:	03288823 */ 	subu	$s1,$t9,$t0
/*  f14726c:	83b900cf */ 	lb	$t9,0xcf($sp)
/*  f147270:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f147274:	02398023 */ 	subu	$s0,$s1,$t9
/*  f147278:	00007012 */ 	mflo	$t6
/*  f14727c:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f147280:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f147284:	448e4000 */ 	mtc1	$t6,$f8
/*  f147288:	00000000 */ 	nop
/*  f14728c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f147290:	e7aa0074 */ 	swc1	$f10,0x74($sp)
.JF0f147294:
/*  f147294:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*  f147298:	24130050 */ 	li	$s3,0x50
/*  f14729c:	24020056 */ 	li	$v0,0x56
/*  f1472a0:	0244082a */ 	slt	$at,$s2,$a0
/*  f1472a4:	10200003 */ 	beqz	$at,.JF0f1472b4
/*  f1472a8:	00000000 */ 	nop
/*  f1472ac:	10000001 */ 	b	.JF0f1472b4
/*  f1472b0:	24130028 */ 	li	$s3,0x28
.JF0f1472b4:
/*  f1472b4:	0244082a */ 	slt	$at,$s2,$a0
/*  f1472b8:	10200003 */ 	beqz	$at,.JF0f1472c8
/*  f1472bc:	00000000 */ 	nop
/*  f1472c0:	10000001 */ 	b	.JF0f1472c8
/*  f1472c4:	24020022 */ 	li	$v0,0x22
.JF0f1472c8:
/*  f1472c8:	02100019 */ 	multu	$s0,$s0
/*  f1472cc:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f1472d0:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f1472d4:	01147821 */ 	addu	$t7,$t0,$s4
/*  f1472d8:	afa80230 */ 	sw	$t0,0x230($sp)
/*  f1472dc:	afaf0238 */ 	sw	$t7,0x238($sp)
/*  f1472e0:	a3a200db */ 	sb	$v0,0xdb($sp)
/*  f1472e4:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f1472e8:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f1472ec:	afa30234 */ 	sw	$v1,0x234($sp)
/*  f1472f0:	0000c812 */ 	mflo	$t9
/*  f1472f4:	03197023 */ 	subu	$t6,$t8,$t9
/*  f1472f8:	448e2000 */ 	mtc1	$t6,$f4
/*  f1472fc:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147300:	0c012838 */ 	jal	sqrtf
/*  f147304:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f147308:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f14730c:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f147310:	83b900cf */ 	lb	$t9,0xcf($sp)
/*  f147314:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f147318:	02348823 */ 	subu	$s1,$s1,$s4
/*  f14731c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147320:	02398023 */ 	subu	$s0,$s1,$t9
/*  f147324:	02100019 */ 	multu	$s0,$s0
/*  f147328:	44814000 */ 	mtc1	$at,$f8
/*  f14732c:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147330:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f147334:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f147338:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f14733c:	afb80240 */ 	sw	$t8,0x240($sp)
/*  f147340:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f147344:	00007812 */ 	mflo	$t7
/*  f147348:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f14734c:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f147350:	44982000 */ 	mtc1	$t8,$f4
/*  f147354:	44035000 */ 	mfc1	$v1,$f10
/*  f147358:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f14735c:	afa30244 */ 	sw	$v1,0x244($sp)
/*  f147360:	0c012838 */ 	jal	sqrtf
/*  f147364:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147368:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f14736c:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f147370:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147374:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f147378:	44813000 */ 	mtc1	$at,$f6
/*  f14737c:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f147380:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147384:	93a200db */ 	lbu	$v0,0xdb($sp)
/*  f147388:	afaf0248 */ 	sw	$t7,0x248($sp)
/*  f14738c:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f147390:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f147394:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f147398:	02a02025 */ 	move	$a0,$s5
/*  f14739c:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f1473a0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1473a4:	00003025 */ 	move	$a2,$zero
/*  f1473a8:	326700ff */ 	andi	$a3,$s3,0xff
/*  f1473ac:	24010001 */ 	li	$at,0x1
/*  f1473b0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1473b4:	440e5000 */ 	mfc1	$t6,$f10
/*  f1473b8:	00000000 */ 	nop
/*  f1473bc:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f1473c0:	afae023c */ 	sw	$t6,0x23c($sp)
/*  f1473c4:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1473c8:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f1473cc:	14600006 */ 	bnez	$v1,.JF0f1473e8
/*  f1473d0:	00000000 */ 	nop
/*  f1473d4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1473d8:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f1473dc:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1473e0:	10000017 */ 	b	.JF0f147440
/*  f1473e4:	0040a825 */ 	move	$s5,$v0
.JF0f1473e8:
/*  f1473e8:	1461000c */ 	bne	$v1,$at,.JF0f14741c
/*  f1473ec:	02a02025 */ 	move	$a0,$s5
/*  f1473f0:	00137080 */ 	sll	$t6,$s3,0x2
/*  f1473f4:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f1473f8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1473fc:	02a02025 */ 	move	$a0,$s5
/*  f147400:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f147404:	24060010 */ 	li	$a2,0x10
/*  f147408:	326700ff */ 	andi	$a3,$s3,0xff
/*  f14740c:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f147410:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147414:	1000000a */ 	b	.JF0f147440
/*  f147418:	0040a825 */ 	move	$s5,$v0
.JF0f14741c:
/*  f14741c:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147420:	30ef00ff */ 	andi	$t7,$a3,0xff
/*  f147424:	01e03825 */ 	move	$a3,$t7
/*  f147428:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f14742c:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147430:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147434:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f147438:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14743c:	0040a825 */ 	move	$s5,$v0
.JF0f147440:
/*  f147440:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147444:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f147448:	2a410011 */ 	slti	$at,$s2,0x11
/*  f14744c:	01144021 */ 	addu	$t0,$t0,$s4
/*  f147450:	1420ff90 */ 	bnez	$at,.JF0f147294
/*  f147454:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f147458:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14745c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147460:	3c014188 */ 	lui	$at,0x4188
/*  f147464:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f147468:	44813000 */ 	mtc1	$at,$f6
/*  f14746c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f147470:	c7240060 */ 	lwc1	$f4,0x60($t9)
/*  f147474:	c42a6c38 */ 	lwc1	$f10,0x6c38($at)
/*  f147478:	240f0011 */ 	li	$t7,0x11
/*  f14747c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f147480:	8fa80304 */ 	lw	$t0,0x304($sp)
/*  f147484:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f147488:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f14748c:	00009025 */ 	move	$s2,$zero
/*  f147490:	83ae00cf */ 	lb	$t6,0xcf($sp)
/*  f147494:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f147498:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f14749c:	44043000 */ 	mfc1	$a0,$f6
/*  f1474a0:	00000000 */ 	nop
/*  f1474a4:	28810012 */ 	slti	$at,$a0,0x12
/*  f1474a8:	54200003 */ 	bnezl	$at,.JF0f1474b8
/*  f1474ac:	240100b4 */ 	li	$at,0xb4
/*  f1474b0:	24040011 */ 	li	$a0,0x11
/*  f1474b4:	240100b4 */ 	li	$at,0xb4
.JF0f1474b8:
/*  f1474b8:	01e42023 */ 	subu	$a0,$t7,$a0
/*  f1474bc:	17010002 */ 	bne	$t8,$at,.JF0f1474c8
/*  f1474c0:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f1474c4:	25080005 */ 	addiu	$t0,$t0,0x5
.JF0f1474c8:
/*  f1474c8:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f1474cc:	03288823 */ 	subu	$s1,$t9,$t0
/*  f1474d0:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f1474d4:	25f8ffde */ 	addiu	$t8,$t7,-34
/*  f1474d8:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f1474dc:	022e8023 */ 	subu	$s0,$s1,$t6
/*  f1474e0:	afa400c8 */ 	sw	$a0,0xc8($sp)
.JF0f1474e4:
/*  f1474e4:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*  f1474e8:	24130050 */ 	li	$s3,0x50
/*  f1474ec:	24020056 */ 	li	$v0,0x56
/*  f1474f0:	0244082a */ 	slt	$at,$s2,$a0
/*  f1474f4:	10200003 */ 	beqz	$at,.JF0f147504
/*  f1474f8:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f1474fc:	10000001 */ 	b	.JF0f147504
/*  f147500:	24130028 */ 	li	$s3,0x28
.JF0f147504:
/*  f147504:	0244082a */ 	slt	$at,$s2,$a0
/*  f147508:	10200003 */ 	beqz	$at,.JF0f147518
/*  f14750c:	00000000 */ 	nop
/*  f147510:	10000001 */ 	b	.JF0f147518
/*  f147514:	24020022 */ 	li	$v0,0x22
.JF0f147518:
/*  f147518:	02100019 */ 	multu	$s0,$s0
/*  f14751c:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f147520:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f147524:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f147528:	afa80230 */ 	sw	$t0,0x230($sp)
/*  f14752c:	afb90238 */ 	sw	$t9,0x238($sp)
/*  f147530:	afa30234 */ 	sw	$v1,0x234($sp)
/*  f147534:	a3a200db */ 	sb	$v0,0xdb($sp)
/*  f147538:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f14753c:	afa400c8 */ 	sw	$a0,0xc8($sp)
/*  f147540:	00007812 */ 	mflo	$t7
/*  f147544:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f147548:	44984000 */ 	mtc1	$t8,$f8
/*  f14754c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147550:	0c012838 */ 	jal	sqrtf
/*  f147554:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f147558:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f14755c:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f147560:	83af00cf */ 	lb	$t7,0xcf($sp)
/*  f147564:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f147568:	02348823 */ 	subu	$s1,$s1,$s4
/*  f14756c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147570:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f147574:	02100019 */ 	multu	$s0,$s0
/*  f147578:	44815000 */ 	mtc1	$at,$f10
/*  f14757c:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147580:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f147584:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f147588:	01147021 */ 	addu	$t6,$t0,$s4
/*  f14758c:	afae0240 */ 	sw	$t6,0x240($sp)
/*  f147590:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f147594:	0000c812 */ 	mflo	$t9
/*  f147598:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f14759c:	03197023 */ 	subu	$t6,$t8,$t9
/*  f1475a0:	448e4000 */ 	mtc1	$t6,$f8
/*  f1475a4:	44033000 */ 	mfc1	$v1,$f6
/*  f1475a8:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f1475ac:	afa30244 */ 	sw	$v1,0x244($sp)
/*  f1475b0:	0c012838 */ 	jal	sqrtf
/*  f1475b4:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f1475b8:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f1475bc:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f1475c0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1475c4:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f1475c8:	44815000 */ 	mtc1	$at,$f10
/*  f1475cc:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f1475d0:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1475d4:	93a200db */ 	lbu	$v0,0xdb($sp)
/*  f1475d8:	afb90248 */ 	sw	$t9,0x248($sp)
/*  f1475dc:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f1475e0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f1475e4:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f1475e8:	02a02025 */ 	move	$a0,$s5
/*  f1475ec:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f1475f0:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f1475f4:	00003025 */ 	move	$a2,$zero
/*  f1475f8:	326700ff */ 	andi	$a3,$s3,0xff
/*  f1475fc:	24010001 */ 	li	$at,0x1
/*  f147600:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147604:	44183000 */ 	mfc1	$t8,$f6
/*  f147608:	00000000 */ 	nop
/*  f14760c:	afb802f4 */ 	sw	$t8,0x2f4($sp)
/*  f147610:	afb8023c */ 	sw	$t8,0x23c($sp)
/*  f147614:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f147618:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f14761c:	14600006 */ 	bnez	$v1,.JF0f147638
/*  f147620:	00000000 */ 	nop
/*  f147624:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147628:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f14762c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147630:	10000017 */ 	b	.JF0f147690
/*  f147634:	0040a825 */ 	move	$s5,$v0
.JF0f147638:
/*  f147638:	1461000c */ 	bne	$v1,$at,.JF0f14766c
/*  f14763c:	02a02025 */ 	move	$a0,$s5
/*  f147640:	0013c080 */ 	sll	$t8,$s3,0x2
/*  f147644:	0313c023 */ 	subu	$t8,$t8,$s3
/*  f147648:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f14764c:	02a02025 */ 	move	$a0,$s5
/*  f147650:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f147654:	24060010 */ 	li	$a2,0x10
/*  f147658:	326700ff */ 	andi	$a3,$s3,0xff
/*  f14765c:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f147660:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147664:	1000000a */ 	b	.JF0f147690
/*  f147668:	0040a825 */ 	move	$s5,$v0
.JF0f14766c:
/*  f14766c:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147670:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f147674:	03203825 */ 	move	$a3,$t9
/*  f147678:	27a5022c */ 	addiu	$a1,$sp,0x22c
/*  f14767c:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147680:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147684:	0fc50e93 */ 	jal	bviewDrawEyespySideRect
/*  f147688:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14768c:	0040a825 */ 	move	$s5,$v0
.JF0f147690:
/*  f147690:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147694:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f147698:	24010011 */ 	li	$at,0x11
/*  f14769c:	01144021 */ 	addu	$t0,$t0,$s4
/*  f1476a0:	1641ff90 */ 	bne	$s2,$at,.JF0f1474e4
/*  f1476a4:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f1476a8:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.JF0f1476ac:
/*  f1476ac:	0fc356a2 */ 	jal	func0f0d49c8
/*  f1476b0:	02a02025 */ 	move	$a0,$s5
.JF0f1476b4:
/*  f1476b4:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f1476b8:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1476bc:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1476c0:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1476c4:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1476c8:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1476cc:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1476d0:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1476d4:	03e00008 */ 	jr	$ra
/*  f1476d8:	27bd0410 */ 	addiu	$sp,$sp,0x410
);
#elif VERSION >= VERSION_PAL_FINAL
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

GLOBAL_ASM(
glabel bviewDrawEyespyMetrics
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
/*  f144868:	0fc5513c */ 	jal	textSetPrimColour
/*  f14486c:	02802025 */ 	move	$a0,$s4
/*  f144870:	1000000e */ 	b	.PF0f1448ac
/*  f144874:	0040a025 */ 	move	$s4,$v0
.PF0f144878:
/*  f144878:	24010001 */ 	li	$at,0x1
/*  f14487c:	14610007 */ 	bne	$v1,$at,.PF0f14489c
/*  f144880:	02802025 */ 	move	$a0,$s4
/*  f144884:	3c052244 */ 	lui	$a1,0x2244
/*  f144888:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f14488c:	0fc5513c */ 	jal	textSetPrimColour
/*  f144890:	02802025 */ 	move	$a0,$s4
/*  f144894:	10000005 */ 	b	.PF0f1448ac
/*  f144898:	0040a025 */ 	move	$s4,$v0
.PF0f14489c:
/*  f14489c:	3c05ff33 */ 	lui	$a1,0xff33
/*  f1448a0:	0fc5513c */ 	jal	textSetPrimColour
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
/*  f1451c0:	0fc5515b */ 	jal	text0f153858
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
/*  f1452d4:	0fc5515b */ 	jal	text0f153858
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
/*  f1453d8:	0fc5515b */ 	jal	text0f153858
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
/*  f1454dc:	0fc5515b */ 	jal	text0f153858
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
/*  f145600:	0fc5515b */ 	jal	text0f153858
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
/*  f14578c:	0fc5515b */ 	jal	text0f153858
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
/*  f1458b4:	0fc5515b */ 	jal	text0f153858
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
/*  f1459d8:	0fc5515b */ 	jal	text0f153858
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
/*  f145af0:	0fc5515b */ 	jal	text0f153858
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
/*  f145c84:	0fc5515b */ 	jal	text0f153858
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
/*  f145dd8:	0fc5515b */ 	jal	text0f153858
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
/*  f145e44:	0fc55153 */ 	jal	text0f153838
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
/*  f147c88:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
/*  f147cbc:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
/*  f147ce4:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
/*  f147f84:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
/*  f147fb8:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
/*  f147fe0:	0fc510cf */ 	jal	bviewDrawEyespySideRect
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
#elif VERSION >= VERSION_PAL_BETA
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

GLOBAL_ASM(
glabel bviewDrawEyespyMetrics
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
/*  f144ed0:	27bdfbf8 */ 	addiu	$sp,$sp,-1032
/*  f144ed4:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f144ed8:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f144edc:	0080a825 */ 	move	$s5,$a0
/*  f144ee0:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f144ee4:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f144ee8:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f144eec:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f144ef0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f144ef4:	0c002e8b */ 	jal	viGetViewLeft
/*  f144ef8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f144efc:	0c002e6d */ 	jal	viGetViewWidth
/*  f144f00:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f144f04:	0c002e8f */ 	jal	viGetViewTop
/*  f144f08:	00408825 */ 	move	$s1,$v0
/*  f144f0c:	244e0010 */ 	addiu	$t6,$v0,0x10
/*  f144f10:	0c002e71 */ 	jal	viGetViewHeight
/*  f144f14:	afae02fc */ 	sw	$t6,0x2fc($sp)
/*  f144f18:	8fb802fc */ 	lw	$t8,0x2fc($sp)
/*  f144f1c:	44806000 */ 	mtc1	$zero,$f12
/*  f144f20:	244fffe0 */ 	addiu	$t7,$v0,-32
/*  f144f24:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f144f28:	272effdf */ 	addiu	$t6,$t9,-33
/*  f144f2c:	2a210141 */ 	slti	$at,$s1,0x141
/*  f144f30:	afaf02f8 */ 	sw	$t7,0x2f8($sp)
/*  f144f34:	14200005 */ 	bnez	$at,.PB0f144f4c
/*  f144f38:	afae02f0 */ 	sw	$t6,0x2f0($sp)
/*  f144f3c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f144f40:	c4247f6c */ 	lwc1	$f4,0x7f6c($at)
/*  f144f44:	10000005 */ 	b	.PB0f144f5c
/*  f144f48:	e7a402a8 */ 	swc1	$f4,0x2a8($sp)
.PB0f144f4c:
/*  f144f4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f144f50:	44813000 */ 	mtc1	$at,$f6
/*  f144f54:	00000000 */ 	nop
/*  f144f58:	e7a602a8 */ 	swc1	$f6,0x2a8($sp)
.PB0f144f5c:
/*  f144f5c:	3c16800a */ 	lui	$s6,0x800a
/*  f144f60:	26d6e4d0 */ 	addiu	$s6,$s6,-6960
/*  f144f64:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144f68:	afa002a4 */ 	sw	$zero,0x2a4($sp)
/*  f144f6c:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f144f70:	10400007 */ 	beqz	$v0,.PB0f144f90
/*  f144f74:	00000000 */ 	nop
/*  f144f78:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f144f7c:	10600004 */ 	beqz	$v1,.PB0f144f90
/*  f144f80:	00000000 */ 	nop
/*  f144f84:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f144f88:	14400003 */ 	bnez	$v0,.PB0f144f98
/*  f144f8c:	00408025 */ 	move	$s0,$v0
.PB0f144f90:
/*  f144f90:	10000de0 */ 	b	.PB0f148714
/*  f144f94:	02a01025 */ 	move	$v0,$s5
.PB0f144f98:
/*  f144f98:	0fc550b9 */ 	jal	optionsGetScreenSplit
/*  f144f9c:	e7ac02bc */ 	swc1	$f12,0x2bc($sp)
/*  f144fa0:	44800000 */ 	mtc1	$zero,$f0
/*  f144fa4:	24010001 */ 	li	$at,0x1
/*  f144fa8:	1441001f */ 	bne	$v0,$at,.PB0f145028
/*  f144fac:	c7ac02bc */ 	lwc1	$f12,0x2bc($sp)
/*  f144fb0:	8ed8006c */ 	lw	$t8,0x6c($s6)
/*  f144fb4:	00002825 */ 	move	$a1,$zero
/*  f144fb8:	00001825 */ 	move	$v1,$zero
/*  f144fbc:	13000003 */ 	beqz	$t8,.PB0f144fcc
/*  f144fc0:	00002025 */ 	move	$a0,$zero
/*  f144fc4:	10000001 */ 	b	.PB0f144fcc
/*  f144fc8:	24050001 */ 	li	$a1,0x1
.PB0f144fcc:
/*  f144fcc:	8ed90068 */ 	lw	$t9,0x68($s6)
/*  f144fd0:	00001025 */ 	move	$v0,$zero
/*  f144fd4:	13200003 */ 	beqz	$t9,.PB0f144fe4
/*  f144fd8:	00000000 */ 	nop
/*  f144fdc:	10000001 */ 	b	.PB0f144fe4
/*  f144fe0:	24030001 */ 	li	$v1,0x1
.PB0f144fe4:
/*  f144fe4:	8ece0064 */ 	lw	$t6,0x64($s6)
/*  f144fe8:	11c00003 */ 	beqz	$t6,.PB0f144ff8
/*  f144fec:	00000000 */ 	nop
/*  f144ff0:	10000001 */ 	b	.PB0f144ff8
/*  f144ff4:	24040001 */ 	li	$a0,0x1
.PB0f144ff8:
/*  f144ff8:	8ecf0070 */ 	lw	$t7,0x70($s6)
/*  f144ffc:	11e00003 */ 	beqz	$t7,.PB0f14500c
/*  f145000:	00000000 */ 	nop
/*  f145004:	10000001 */ 	b	.PB0f14500c
/*  f145008:	24020001 */ 	li	$v0,0x1
.PB0f14500c:
/*  f14500c:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f145010:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f145014:	03257021 */ 	addu	$t6,$t9,$a1
/*  f145018:	29c10002 */ 	slti	$at,$t6,0x2
/*  f14501c:	14200002 */ 	bnez	$at,.PB0f145028
/*  f145020:	240f0001 */ 	li	$t7,0x1
/*  f145024:	afaf02a4 */ 	sw	$t7,0x2a4($sp)
.PB0f145028:
/*  f145028:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f14502c:	c60a00c8 */ 	lwc1	$f10,0xc8($s0)
/*  f145030:	3c017f1b */ 	lui	$at,0x7f1b
/*  f145034:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f145038:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f14503c:	c60a00cc */ 	lwc1	$f10,0xcc($s0)
/*  f145040:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f145044:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f145048:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f14504c:	44033000 */ 	mfc1	$v1,$f6
/*  f145050:	c60a00d0 */ 	lwc1	$f10,0xd0($s0)
/*  f145054:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f145058:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f14505c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f145060:	44834000 */ 	mtc1	$v1,$f8
/*  f145064:	44043000 */ 	mfc1	$a0,$f6
/*  f145068:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14506c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f145070:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f145074:	44053000 */ 	mfc1	$a1,$f6
/*  f145078:	4500000f */ 	bc1f	.PB0f1450b8
/*  f14507c:	00000000 */ 	nop
/*  f145080:	44842000 */ 	mtc1	$a0,$f4
/*  f145084:	00000000 */ 	nop
/*  f145088:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14508c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f145090:	00000000 */ 	nop
/*  f145094:	45000008 */ 	bc1f	.PB0f1450b8
/*  f145098:	00000000 */ 	nop
/*  f14509c:	44854000 */ 	mtc1	$a1,$f8
/*  f1450a0:	00000000 */ 	nop
/*  f1450a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1450a8:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f1450ac:	00000000 */ 	nop
/*  f1450b0:	4501000f */ 	bc1t	.PB0f1450f0
/*  f1450b4:	00000000 */ 	nop
.PB0f1450b8:
/*  f1450b8:	00630019 */ 	multu	$v1,$v1
/*  f1450bc:	00007812 */ 	mflo	$t7
/*  f1450c0:	00000000 */ 	nop
/*  f1450c4:	00000000 */ 	nop
/*  f1450c8:	00840019 */ 	multu	$a0,$a0
/*  f1450cc:	0000c012 */ 	mflo	$t8
/*  f1450d0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1450d4:	00000000 */ 	nop
/*  f1450d8:	00a50019 */ 	multu	$a1,$a1
/*  f1450dc:	00007012 */ 	mflo	$t6
/*  f1450e0:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f1450e4:	448f2000 */ 	mtc1	$t7,$f4
/*  f1450e8:	00000000 */ 	nop
/*  f1450ec:	46802320 */ 	cvt.s.w	$f12,$f4
.PB0f1450f0:
/*  f1450f0:	c4267f70 */ 	lwc1	$f6,0x7f70($at)
/*  f1450f4:	460c303c */ 	c.lt.s	$f6,$f12
/*  f1450f8:	00000000 */ 	nop
/*  f1450fc:	45020006 */ 	bc1fl	.PB0f145118
/*  f145100:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f145104:	0c012ae4 */ 	jal	sqrtf
/*  f145108:	00000000 */ 	nop
/*  f14510c:	10000002 */ 	b	.PB0f145118
/*  f145110:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f145114:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
.PB0f145118:
/*  f145118:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14511c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145120:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f145124:	14600006 */ 	bnez	$v1,.PB0f145140
/*  f145128:	3c0500ff */ 	lui	$a1,0xff
/*  f14512c:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f145130:	0fc552fc */ 	jal	textSetPrimColour
/*  f145134:	02a02025 */ 	move	$a0,$s5
/*  f145138:	1000000e */ 	b	.PB0f145174
/*  f14513c:	0040a825 */ 	move	$s5,$v0
.PB0f145140:
/*  f145140:	24010001 */ 	li	$at,0x1
/*  f145144:	14610007 */ 	bne	$v1,$at,.PB0f145164
/*  f145148:	02a02025 */ 	move	$a0,$s5
/*  f14514c:	3c052244 */ 	lui	$a1,0x2244
/*  f145150:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f145154:	0fc552fc */ 	jal	textSetPrimColour
/*  f145158:	02a02025 */ 	move	$a0,$s5
/*  f14515c:	10000005 */ 	b	.PB0f145174
/*  f145160:	0040a825 */ 	move	$s5,$v0
.PB0f145164:
/*  f145164:	3c05ff33 */ 	lui	$a1,0xff33
/*  f145168:	0fc552fc */ 	jal	textSetPrimColour
/*  f14516c:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f145170:	0040a825 */ 	move	$s5,$v0
.PB0f145174:
/*  f145174:	8fae02a4 */ 	lw	$t6,0x2a4($sp)
/*  f145178:	55c00180 */ 	bnezl	$t6,.PB0f14577c
/*  f14517c:	44914000 */ 	mtc1	$s1,$f8
/*  f145180:	44915000 */ 	mtc1	$s1,$f10
/*  f145184:	3c013f80 */ 	lui	$at,0x3f80
/*  f145188:	44818000 */ 	mtc1	$at,$f16
/*  f14518c:	468053a0 */ 	cvt.s.w	$f14,$f10
/*  f145190:	3c0140a0 */ 	lui	$at,0x40a0
/*  f145194:	44812000 */ 	mtc1	$at,$f4
/*  f145198:	8fac02f0 */ 	lw	$t4,0x2f0($sp)
/*  f14519c:	8fad0304 */ 	lw	$t5,0x304($sp)
/*  f1451a0:	3c0bf600 */ 	lui	$t3,0xf600
/*  f1451a4:	46047003 */ 	div.s	$f0,$f14,$f4
/*  f1451a8:	2584ffe8 */ 	addiu	$a0,$t4,-24
/*  f1451ac:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f1451b0:	25b9001a */ 	addiu	$t9,$t5,0x1a
/*  f1451b4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1451b8:	000f2080 */ 	sll	$a0,$t7,0x2
/*  f1451bc:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1451c0:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f1451c4:	25b40019 */ 	addiu	$s4,$t5,0x19
/*  f1451c8:	44944000 */ 	mtc1	$s4,$f8
/*  f1451cc:	0304c825 */ 	or	$t9,$t8,$a0
/*  f1451d0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1451d4:	8fa602fc */ 	lw	$a2,0x2fc($sp)
/*  f1451d8:	328703ff */ 	andi	$a3,$s4,0x3ff
/*  f1451dc:	00077380 */ 	sll	$t6,$a3,0xe
/*  f1451e0:	24c60037 */ 	addiu	$a2,$a2,0x37
/*  f1451e4:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f1451e8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1451ec:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f1451f0:	03003025 */ 	move	$a2,$t8
/*  f1451f4:	01c03825 */ 	move	$a3,$t6
/*  f1451f8:	2588ffd6 */ 	addiu	$t0,$t4,-42
/*  f1451fc:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f145200:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f145204:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145208:	25b80020 */ 	addiu	$t8,$t5,0x20
/*  f14520c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f145210:	000e4080 */ 	sll	$t0,$t6,0x2
/*  f145214:	46001180 */ 	add.s	$f6,$f2,$f0
/*  f145218:	00197380 */ 	sll	$t6,$t9,0xe
/*  f14521c:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f145220:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f145224:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f145228:	25a9001f */ 	addiu	$t1,$t5,0x1f
/*  f14522c:	313903ff */ 	andi	$t9,$t1,0x3ff
/*  f145230:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f145234:	02a02825 */ 	move	$a1,$s5
/*  f145238:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f14523c:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f145240:	24190001 */ 	li	$t9,0x1
/*  f145244:	4458f800 */ 	cfc1	$t8,$31
/*  f145248:	44d9f800 */ 	ctc1	$t9,$31
/*  f14524c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145250:	01267825 */ 	or	$t7,$t1,$a2
/*  f145254:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f145258:	02a05025 */ 	move	$t2,$s5
/*  f14525c:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f145260:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145264:	4459f800 */ 	cfc1	$t9,$31
/*  f145268:	3c014f00 */ 	lui	$at,0x4f00
/*  f14526c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f145270:	53200013 */ 	beqzl	$t9,.PB0f1452c0
/*  f145274:	44195000 */ 	mfc1	$t9,$f10
/*  f145278:	44815000 */ 	mtc1	$at,$f10
/*  f14527c:	24190001 */ 	li	$t9,0x1
/*  f145280:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f145284:	44d9f800 */ 	ctc1	$t9,$31
/*  f145288:	00000000 */ 	nop
/*  f14528c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f145290:	4459f800 */ 	cfc1	$t9,$31
/*  f145294:	00000000 */ 	nop
/*  f145298:	33390078 */ 	andi	$t9,$t9,0x78
/*  f14529c:	17200005 */ 	bnez	$t9,.PB0f1452b4
/*  f1452a0:	00000000 */ 	nop
/*  f1452a4:	44195000 */ 	mfc1	$t9,$f10
/*  f1452a8:	3c018000 */ 	lui	$at,0x8000
/*  f1452ac:	10000007 */ 	b	.PB0f1452cc
/*  f1452b0:	0321c825 */ 	or	$t9,$t9,$at
.PB0f1452b4:
/*  f1452b4:	10000005 */ 	b	.PB0f1452cc
/*  f1452b8:	2419ffff */ 	li	$t9,-1
/*  f1452bc:	44195000 */ 	mfc1	$t9,$f10
.PB0f1452c0:
/*  f1452c0:	00000000 */ 	nop
/*  f1452c4:	0720fffb */ 	bltz	$t9,.PB0f1452b4
/*  f1452c8:	00000000 */ 	nop
.PB0f1452cc:
/*  f1452cc:	3c0140e0 */ 	lui	$at,0x40e0
/*  f1452d0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1452d4:	44812000 */ 	mtc1	$at,$f4
/*  f1452d8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1452dc:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1452e0:	46047303 */ 	div.s	$f12,$f14,$f4
/*  f1452e4:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f1452e8:	0304c825 */ 	or	$t9,$t8,$a0
/*  f1452ec:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f1452f0:	8fb002f0 */ 	lw	$s0,0x2f0($sp)
/*  f1452f4:	02a01025 */ 	move	$v0,$s5
/*  f1452f8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452fc:	260effe7 */ 	addiu	$t6,$s0,-25
/*  f145300:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145304:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f145308:	240f0001 */ 	li	$t7,0x1
/*  f14530c:	00f8c825 */ 	or	$t9,$a3,$t8
/*  f145310:	02a01825 */ 	move	$v1,$s5
/*  f145314:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f145318:	3c04f600 */ 	lui	$a0,0xf600
/*  f14531c:	3c014f00 */ 	lui	$at,0x4f00
/*  f145320:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145324:	2605ffca */ 	addiu	$a1,$s0,-54
/*  f145328:	460c1180 */ 	add.s	$f6,$f2,$f12
/*  f14532c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f145330:	444ef800 */ 	cfc1	$t6,$31
/*  f145334:	44cff800 */ 	ctc1	$t7,$31
/*  f145338:	00000000 */ 	nop
/*  f14533c:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f145340:	444ff800 */ 	cfc1	$t7,$31
/*  f145344:	00000000 */ 	nop
/*  f145348:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f14534c:	51e00013 */ 	beqzl	$t7,.PB0f14539c
/*  f145350:	440f5000 */ 	mfc1	$t7,$f10
/*  f145354:	44815000 */ 	mtc1	$at,$f10
/*  f145358:	240f0001 */ 	li	$t7,0x1
/*  f14535c:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f145360:	44cff800 */ 	ctc1	$t7,$31
/*  f145364:	00000000 */ 	nop
/*  f145368:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f14536c:	444ff800 */ 	cfc1	$t7,$31
/*  f145370:	00000000 */ 	nop
/*  f145374:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f145378:	15e00005 */ 	bnez	$t7,.PB0f145390
/*  f14537c:	00000000 */ 	nop
/*  f145380:	440f5000 */ 	mfc1	$t7,$f10
/*  f145384:	3c018000 */ 	lui	$at,0x8000
/*  f145388:	10000007 */ 	b	.PB0f1453a8
/*  f14538c:	01e17825 */ 	or	$t7,$t7,$at
.PB0f145390:
/*  f145390:	10000005 */ 	b	.PB0f1453a8
/*  f145394:	240fffff */ 	li	$t7,-1
/*  f145398:	440f5000 */ 	mfc1	$t7,$f10
.PB0f14539c:
/*  f14539c:	00000000 */ 	nop
/*  f1453a0:	05e0fffb */ 	bltz	$t7,.PB0f145390
/*  f1453a4:	00000000 */ 	nop
.PB0f1453a8:
/*  f1453a8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1453ac:	44cef800 */ 	ctc1	$t6,$31
/*  f1453b0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1453b4:	03247025 */ 	or	$t6,$t9,$a0
/*  f1453b8:	01c87825 */ 	or	$t7,$t6,$t0
/*  f1453bc:	2618ffd5 */ 	addiu	$t8,$s0,-43
/*  f1453c0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1453c4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1453c8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1453cc:	012e7825 */ 	or	$t7,$t1,$t6
/*  f1453d0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1453d4:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f1453d8:	3c01f600 */ 	lui	$at,0xf600
/*  f1453dc:	02a01025 */ 	move	$v0,$s5
/*  f1453e0:	0311f821 */ 	addu	$ra,$t8,$s1
/*  f1453e4:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f1453e8:	27f9ffe8 */ 	addiu	$t9,$ra,-24
/*  f1453ec:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1453f0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1453f4:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f1453f8:	00182880 */ 	sll	$a1,$t8,0x2
/*  f1453fc:	01e46825 */ 	or	$t5,$t7,$a0
/*  f145400:	01a57025 */ 	or	$t6,$t5,$a1
/*  f145404:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f145408:	8fab02fc */ 	lw	$t3,0x2fc($sp)
/*  f14540c:	27ecffe7 */ 	addiu	$t4,$ra,-25
/*  f145410:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f145414:	256b0019 */ 	addiu	$t3,$t3,0x19
/*  f145418:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f14541c:	448c2000 */ 	mtc1	$t4,$f4
/*  f145420:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f145424:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145428:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f14542c:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f145430:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f145434:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145438:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f14543c:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f145440:	8fa902fc */ 	lw	$t1,0x2fc($sp)
/*  f145444:	03217025 */ 	or	$t6,$t9,$at
/*  f145448:	01c57825 */ 	or	$t7,$t6,$a1
/*  f14544c:	afbf0088 */ 	sw	$ra,0x88($sp)
/*  f145450:	01c02025 */ 	move	$a0,$t6
/*  f145454:	27eeffe1 */ 	addiu	$t6,$ra,-31
/*  f145458:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f14545c:	2527002b */ 	addiu	$a3,$t1,0x2b
/*  f145460:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f145464:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145468:	00183880 */ 	sll	$a3,$t8,0x2
/*  f14546c:	46001181 */ 	sub.s	$f6,$f2,$f0
/*  f145470:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f145474:	252e001a */ 	addiu	$t6,$t1,0x1a
/*  f145478:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14547c:	0307c825 */ 	or	$t9,$t8,$a3
/*  f145480:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f145484:	240f0001 */ 	li	$t7,0x1
/*  f145488:	444ef800 */ 	cfc1	$t6,$31
/*  f14548c:	44cff800 */ 	ctc1	$t7,$31
/*  f145490:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f145494:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145498:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f14549c:	02a01825 */ 	move	$v1,$s5
/*  f1454a0:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f1454a4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1454a8:	444ff800 */ 	cfc1	$t7,$31
/*  f1454ac:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1454b0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1454b4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1454b8:	51e00013 */ 	beqzl	$t7,.PB0f145508
/*  f1454bc:	440f4000 */ 	mfc1	$t7,$f8
/*  f1454c0:	44814000 */ 	mtc1	$at,$f8
/*  f1454c4:	240f0001 */ 	li	$t7,0x1
/*  f1454c8:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f1454cc:	44cff800 */ 	ctc1	$t7,$31
/*  f1454d0:	00000000 */ 	nop
/*  f1454d4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1454d8:	444ff800 */ 	cfc1	$t7,$31
/*  f1454dc:	00000000 */ 	nop
/*  f1454e0:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1454e4:	15e00005 */ 	bnez	$t7,.PB0f1454fc
/*  f1454e8:	00000000 */ 	nop
/*  f1454ec:	440f4000 */ 	mfc1	$t7,$f8
/*  f1454f0:	3c018000 */ 	lui	$at,0x8000
/*  f1454f4:	10000007 */ 	b	.PB0f145514
/*  f1454f8:	01e17825 */ 	or	$t7,$t7,$at
.PB0f1454fc:
/*  f1454fc:	10000005 */ 	b	.PB0f145514
/*  f145500:	240fffff */ 	li	$t7,-1
/*  f145504:	440f4000 */ 	mfc1	$t7,$f8
.PB0f145508:
/*  f145508:	00000000 */ 	nop
/*  f14550c:	05e0fffb */ 	bltz	$t7,.PB0f1454fc
/*  f145510:	00000000 */ 	nop
.PB0f145514:
/*  f145514:	44cef800 */ 	ctc1	$t6,$31
/*  f145518:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f14551c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f145520:	460c1281 */ 	sub.s	$f10,$f2,$f12
/*  f145524:	252f002c */ 	addiu	$t7,$t1,0x2c
/*  f145528:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f14552c:	032b7025 */ 	or	$t6,$t9,$t3
/*  f145530:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145534:	24180001 */ 	li	$t8,0x1
/*  f145538:	444ff800 */ 	cfc1	$t7,$31
/*  f14553c:	44d8f800 */ 	ctc1	$t8,$31
/*  f145540:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145544:	00997025 */ 	or	$t6,$a0,$t9
/*  f145548:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f14554c:	02a04025 */ 	move	$t0,$s5
/*  f145550:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f145554:	8fa90304 */ 	lw	$t1,0x304($sp)
/*  f145558:	4458f800 */ 	cfc1	$t8,$31
/*  f14555c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f145560:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145564:	33180078 */ 	andi	$t8,$t8,0x78
/*  f145568:	13000012 */ 	beqz	$t8,.PB0f1455b4
/*  f14556c:	3c014f00 */ 	lui	$at,0x4f00
/*  f145570:	44812000 */ 	mtc1	$at,$f4
/*  f145574:	24180001 */ 	li	$t8,0x1
/*  f145578:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f14557c:	44d8f800 */ 	ctc1	$t8,$31
/*  f145580:	00000000 */ 	nop
/*  f145584:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f145588:	4458f800 */ 	cfc1	$t8,$31
/*  f14558c:	00000000 */ 	nop
/*  f145590:	33180078 */ 	andi	$t8,$t8,0x78
/*  f145594:	17000005 */ 	bnez	$t8,.PB0f1455ac
/*  f145598:	00000000 */ 	nop
/*  f14559c:	44182000 */ 	mfc1	$t8,$f4
/*  f1455a0:	3c018000 */ 	lui	$at,0x8000
/*  f1455a4:	10000007 */ 	b	.PB0f1455c4
/*  f1455a8:	0301c025 */ 	or	$t8,$t8,$at
.PB0f1455ac:
/*  f1455ac:	10000005 */ 	b	.PB0f1455c4
/*  f1455b0:	2418ffff */ 	li	$t8,-1
.PB0f1455b4:
/*  f1455b4:	44182000 */ 	mfc1	$t8,$f4
/*  f1455b8:	00000000 */ 	nop
/*  f1455bc:	0700fffb */ 	bltz	$t8,.PB0f1455ac
/*  f1455c0:	00000000 */ 	nop
.PB0f1455c4:
/*  f1455c4:	44cff800 */ 	ctc1	$t7,$31
/*  f1455c8:	44893000 */ 	mtc1	$t1,$f6
/*  f1455cc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1455d0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1455d4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1455d8:	24190001 */ 	li	$t9,0x1
/*  f1455dc:	01c77825 */ 	or	$t7,$t6,$a3
/*  f1455e0:	02a01025 */ 	move	$v0,$s5
/*  f1455e4:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f1455e8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455ec:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f1455f0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1455f4:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f1455f8:	4458f800 */ 	cfc1	$t8,$31
/*  f1455fc:	44d9f800 */ 	ctc1	$t9,$31
/*  f145600:	00000000 */ 	nop
/*  f145604:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f145608:	4459f800 */ 	cfc1	$t9,$31
/*  f14560c:	00000000 */ 	nop
/*  f145610:	33390078 */ 	andi	$t9,$t9,0x78
/*  f145614:	53200013 */ 	beqzl	$t9,.PB0f145664
/*  f145618:	44193000 */ 	mfc1	$t9,$f6
/*  f14561c:	44813000 */ 	mtc1	$at,$f6
/*  f145620:	24190001 */ 	li	$t9,0x1
/*  f145624:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f145628:	44d9f800 */ 	ctc1	$t9,$31
/*  f14562c:	00000000 */ 	nop
/*  f145630:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f145634:	4459f800 */ 	cfc1	$t9,$31
/*  f145638:	00000000 */ 	nop
/*  f14563c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f145640:	17200005 */ 	bnez	$t9,.PB0f145658
/*  f145644:	00000000 */ 	nop
/*  f145648:	44193000 */ 	mfc1	$t9,$f6
/*  f14564c:	3c018000 */ 	lui	$at,0x8000
/*  f145650:	10000007 */ 	b	.PB0f145670
/*  f145654:	0321c825 */ 	or	$t9,$t9,$at
.PB0f145658:
/*  f145658:	10000005 */ 	b	.PB0f145670
/*  f14565c:	2419ffff */ 	li	$t9,-1
/*  f145660:	44193000 */ 	mfc1	$t9,$f6
.PB0f145664:
/*  f145664:	00000000 */ 	nop
/*  f145668:	0720fffb */ 	bltz	$t9,.PB0f145658
/*  f14566c:	00000000 */ 	nop
.PB0f145670:
/*  f145670:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f145674:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f145678:	44d8f800 */ 	ctc1	$t8,$31
/*  f14567c:	44844000 */ 	mtc1	$a0,$f8
/*  f145680:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145684:	3c01f600 */ 	lui	$at,0xf600
/*  f145688:	01e1c025 */ 	or	$t8,$t7,$at
/*  f14568c:	272e0038 */ 	addiu	$t6,$t9,0x38
/*  f145690:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f145694:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145698:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f14569c:	03197025 */ 	or	$t6,$t8,$t9
/*  f1456a0:	312f03ff */ 	andi	$t7,$t1,0x3ff
/*  f1456a4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1456a8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1456ac:	248e0001 */ 	addiu	$t6,$a0,0x1
/*  f1456b0:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f1456b4:	0306c825 */ 	or	$t9,$t8,$a2
/*  f1456b8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1456bc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1456c0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1456c4:	0301c825 */ 	or	$t9,$t8,$at
/*  f1456c8:	24180001 */ 	li	$t8,0x1
/*  f1456cc:	444ff800 */ 	cfc1	$t7,$31
/*  f1456d0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1456d4:	03257025 */ 	or	$t6,$t9,$a1
/*  f1456d8:	02a01825 */ 	move	$v1,$s5
/*  f1456dc:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f1456e0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1456e4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1456e8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1456ec:	4458f800 */ 	cfc1	$t8,$31
/*  f1456f0:	00000000 */ 	nop
/*  f1456f4:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1456f8:	53000013 */ 	beqzl	$t8,.PB0f145748
/*  f1456fc:	44183000 */ 	mfc1	$t8,$f6
/*  f145700:	44813000 */ 	mtc1	$at,$f6
/*  f145704:	24180001 */ 	li	$t8,0x1
/*  f145708:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f14570c:	44d8f800 */ 	ctc1	$t8,$31
/*  f145710:	00000000 */ 	nop
/*  f145714:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f145718:	4458f800 */ 	cfc1	$t8,$31
/*  f14571c:	00000000 */ 	nop
/*  f145720:	33180078 */ 	andi	$t8,$t8,0x78
/*  f145724:	17000005 */ 	bnez	$t8,.PB0f14573c
/*  f145728:	00000000 */ 	nop
/*  f14572c:	44183000 */ 	mfc1	$t8,$f6
/*  f145730:	3c018000 */ 	lui	$at,0x8000
/*  f145734:	10000007 */ 	b	.PB0f145754
/*  f145738:	0301c025 */ 	or	$t8,$t8,$at
.PB0f14573c:
/*  f14573c:	10000005 */ 	b	.PB0f145754
/*  f145740:	2418ffff */ 	li	$t8,-1
/*  f145744:	44183000 */ 	mfc1	$t8,$f6
.PB0f145748:
/*  f145748:	00000000 */ 	nop
/*  f14574c:	0700fffb */ 	bltz	$t8,.PB0f14573c
/*  f145750:	00000000 */ 	nop
.PB0f145754:
/*  f145754:	44cff800 */ 	ctc1	$t7,$31
/*  f145758:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f14575c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f145760:	00197380 */ 	sll	$t6,$t9,0xe
/*  f145764:	25f8ffc9 */ 	addiu	$t8,$t7,-55
/*  f145768:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14576c:	00197880 */ 	sll	$t7,$t9,0x2
/*  f145770:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f145774:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145778:	44914000 */ 	mtc1	$s1,$f8
.PB0f14577c:
/*  f14577c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f145780:	44813000 */ 	mtc1	$at,$f6
/*  f145784:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f145788:	8fa90304 */ 	lw	$t1,0x304($sp)
/*  f14578c:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145790:	24010001 */ 	li	$at,0x1
/*  f145794:	01317821 */ 	addu	$t7,$t1,$s1
/*  f145798:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f14579c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f1457a0:	44985000 */ 	mtc1	$t8,$f10
/*  f1457a4:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f1457a8:	25340019 */ 	addiu	$s4,$t1,0x19
/*  f1457ac:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f1457b0:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f1457b4:	afb80088 */ 	sw	$t8,0x88($sp)
/*  f1457b8:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f1457bc:	1461006d */ 	bne	$v1,$at,.PB0f145974
/*  f1457c0:	e7aa0068 */ 	swc1	$f10,0x68($sp)
/*  f1457c4:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f1457c8:	0011c843 */ 	sra	$t9,$s1,0x1
/*  f1457cc:	8faf02f8 */ 	lw	$t7,0x2f8($sp)
/*  f1457d0:	032e1021 */ 	addu	$v0,$t9,$t6
/*  f1457d4:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f1457d8:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f1457dc:	3c0cf600 */ 	lui	$t4,0xf600
/*  f1457e0:	03192021 */ 	addu	$a0,$t8,$t9
/*  f1457e4:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f1457e8:	306e03ff */ 	andi	$t6,$v1,0x3ff
/*  f1457ec:	24580007 */ 	addiu	$t8,$v0,0x7
/*  f1457f0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1457f4:	000e1880 */ 	sll	$v1,$t6,0x2
/*  f1457f8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1457fc:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f145800:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f145804:	244e0002 */ 	addiu	$t6,$v0,0x2
/*  f145808:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f14580c:	02a03025 */ 	move	$a2,$s5
/*  f145810:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f145814:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f145818:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14581c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f145820:	03193825 */ 	or	$a3,$t8,$t9
/*  f145824:	03202825 */ 	move	$a1,$t9
/*  f145828:	24590005 */ 	addiu	$t9,$v0,0x5
/*  f14582c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f145830:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145834:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f145838:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14583c:	0303c825 */ 	or	$t9,$t8,$v1
/*  f145840:	244effff */ 	addiu	$t6,$v0,-1
/*  f145844:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f145848:	02a04025 */ 	move	$t0,$s5
/*  f14584c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145850:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f145854:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f145858:	030cc825 */ 	or	$t9,$t8,$t4
/*  f14585c:	244efffa */ 	addiu	$t6,$v0,-6
/*  f145860:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145864:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145868:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f14586c:	03235025 */ 	or	$t2,$t9,$v1
/*  f145870:	0305c825 */ 	or	$t9,$t8,$a1
/*  f145874:	02a04825 */ 	move	$t1,$s5
/*  f145878:	244efffc */ 	addiu	$t6,$v0,-4
/*  f14587c:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f145880:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f145884:	ad390004 */ 	sw	$t9,0x4($t1)
/*  f145888:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14588c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f145890:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f145894:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f145898:	0305c825 */ 	or	$t9,$t8,$a1
/*  f14589c:	02a05825 */ 	move	$t3,$s5
/*  f1458a0:	306e03ff */ 	andi	$t6,$v1,0x3ff
/*  f1458a4:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f1458a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1458ac:	24990007 */ 	addiu	$t9,$a0,0x7
/*  f1458b0:	3c01f600 */ 	lui	$at,0xf600
/*  f1458b4:	01e11825 */ 	or	$v1,$t7,$at
/*  f1458b8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1458bc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1458c0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1458c4:	006fc025 */ 	or	$t8,$v1,$t7
/*  f1458c8:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f1458cc:	02a02825 */ 	move	$a1,$s5
/*  f1458d0:	248e0002 */ 	addiu	$t6,$a0,0x2
/*  f1458d4:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f1458d8:	0008cb80 */ 	sll	$t9,$t0,0xe
/*  f1458dc:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1458e0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1458e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1458e8:	03383825 */ 	or	$a3,$t9,$t8
/*  f1458ec:	03204025 */ 	move	$t0,$t9
/*  f1458f0:	24990005 */ 	addiu	$t9,$a0,0x5
/*  f1458f4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1458f8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1458fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145900:	006fc025 */ 	or	$t8,$v1,$t7
/*  f145904:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f145908:	02a03025 */ 	move	$a2,$s5
/*  f14590c:	2499ffff */ 	addiu	$t9,$a0,-1
/*  f145910:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f145914:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f145918:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14591c:	2498fffa */ 	addiu	$t8,$a0,-6
/*  f145920:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145924:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f145928:	00197080 */ 	sll	$t6,$t9,0x2
/*  f14592c:	02a04825 */ 	move	$t1,$s5
/*  f145930:	006f5025 */ 	or	$t2,$v1,$t7
/*  f145934:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f145938:	010e7825 */ 	or	$t7,$t0,$t6
/*  f14593c:	2498fffc */ 	addiu	$t8,$a0,-4
/*  f145940:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f145944:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145948:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14594c:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f145950:	00197080 */ 	sll	$t6,$t9,0x2
/*  f145954:	02a01025 */ 	move	$v0,$s5
/*  f145958:	010e7825 */ 	or	$t7,$t0,$t6
/*  f14595c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f145960:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f145964:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145968:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14596c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145970:	9323006b */ 	lbu	$v1,0x6b($t9)
.PB0f145974:
/*  f145974:	1460000b */ 	bnez	$v1,.PB0f1459a4
/*  f145978:	2404580c */ 	li	$a0,0x580c
/*  f14597c:	3c0e00ff */ 	lui	$t6,0xff
/*  f145980:	3c0f0050 */ 	lui	$t7,0x50
/*  f145984:	3c18000f */ 	lui	$t8,0xf
/*  f145988:	35ce00a0 */ 	ori	$t6,$t6,0xa0
/*  f14598c:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f145990:	371800ff */ 	ori	$t8,$t8,0xff
/*  f145994:	afae02b8 */ 	sw	$t6,0x2b8($sp)
/*  f145998:	afaf02b4 */ 	sw	$t7,0x2b4($sp)
/*  f14599c:	10000011 */ 	b	.PB0f1459e4
/*  f1459a0:	afb802b0 */ 	sw	$t8,0x2b0($sp)
.PB0f1459a4:
/*  f1459a4:	24010001 */ 	li	$at,0x1
/*  f1459a8:	14610008 */ 	bne	$v1,$at,.PB0f1459cc
/*  f1459ac:	3c02ff33 */ 	lui	$v0,0xff33
/*  f1459b0:	3c022244 */ 	lui	$v0,0x2244
/*  f1459b4:	3442ffff */ 	ori	$v0,$v0,0xffff
/*  f1459b8:	24190fff */ 	li	$t9,0xfff
/*  f1459bc:	afa202b8 */ 	sw	$v0,0x2b8($sp)
/*  f1459c0:	afa202b4 */ 	sw	$v0,0x2b4($sp)
/*  f1459c4:	10000007 */ 	b	.PB0f1459e4
/*  f1459c8:	afb902b0 */ 	sw	$t9,0x2b0($sp)
.PB0f1459cc:
/*  f1459cc:	344200ff */ 	ori	$v0,$v0,0xff
/*  f1459d0:	3c0e0f00 */ 	lui	$t6,0xf00
/*  f1459d4:	35ce00ff */ 	ori	$t6,$t6,0xff
/*  f1459d8:	afa202b8 */ 	sw	$v0,0x2b8($sp)
/*  f1459dc:	afa202b4 */ 	sw	$v0,0x2b4($sp)
/*  f1459e0:	afae02b0 */ 	sw	$t6,0x2b0($sp)
.PB0f1459e4:
/*  f1459e4:	0fc5c06a */ 	jal	langGet
/*  f1459e8:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f1459ec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1459f0:	c4247f74 */ 	lwc1	$f4,0x7f74($at)
/*  f1459f4:	c7a602c0 */ 	lwc1	$f6,0x2c0($sp)
/*  f1459f8:	27b30308 */ 	addiu	$s3,$sp,0x308
/*  f1459fc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145a00:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f145a04:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f145a08:	24e77e10 */ 	addiu	$a3,$a3,0x7e10
/*  f145a0c:	24a57e04 */ 	addiu	$a1,$a1,0x7e04
/*  f145a10:	02602025 */ 	move	$a0,$s3
/*  f145a14:	00403025 */ 	move	$a2,$v0
/*  f145a18:	460042a1 */ 	cvt.d.s	$f10,$f8
/*  f145a1c:	0c004e1d */ 	jal	sprintf
/*  f145a20:	f7aa0010 */ 	sdc1	$f10,0x10($sp)
/*  f145a24:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145a28:	8def1fd4 */ 	lw	$t7,0x1fd4($t7)
/*  f145a2c:	3c078008 */ 	lui	$a3,0x8008
/*  f145a30:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145a34:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145a38:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145a3c:	02603025 */ 	move	$a2,$s3
/*  f145a40:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145a44:	0fc5625a */ 	jal	textMeasure
/*  f145a48:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145a4c:	8fb202fc */ 	lw	$s2,0x2fc($sp)
/*  f145a50:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f145a54:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f145a58:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f145a5c:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f145a60:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f145a64:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f145a68:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f145a6c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145a70:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f145a74:	afb202e8 */ 	sw	$s2,0x2e8($sp)
/*  f145a78:	02a02025 */ 	move	$a0,$s5
/*  f145a7c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145a80:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145a84:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f145a88:	0fc5531b */ 	jal	text0f153858
/*  f145a8c:	afb402ec */ 	sw	$s4,0x2ec($sp)
/*  f145a90:	0c002e4d */ 	jal	viGetWidth
/*  f145a94:	0040a825 */ 	move	$s5,$v0
/*  f145a98:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145a9c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f145aa0:	0c002e51 */ 	jal	viGetHeight
/*  f145aa4:	03208025 */ 	move	$s0,$t9
/*  f145aa8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145aac:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145ab0:	8def1fd4 */ 	lw	$t7,0x1fd4($t7)
/*  f145ab4:	8dce1fd8 */ 	lw	$t6,0x1fd8($t6)
/*  f145ab8:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f145abc:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f145ac0:	02a02025 */ 	move	$a0,$s5
/*  f145ac4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145ac8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145acc:	02603825 */ 	move	$a3,$s3
/*  f145ad0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145ad4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145ad8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145adc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145ae0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f145ae4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145ae8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145aec:	0fc56160 */ 	jal	textRender
/*  f145af0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f145af4:	0040a825 */ 	move	$s5,$v0
/*  f145af8:	0fc5c06a */ 	jal	langGet
/*  f145afc:	2404580d */ 	li	$a0,0x580d
/*  f145b00:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145b04:	3c017f1b */ 	lui	$at,0x7f1b
/*  f145b08:	c4247f78 */ 	lwc1	$f4,0x7f78($at)
/*  f145b0c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f145b10:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145b14:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f145b18:	c5e60060 */ 	lwc1	$f6,0x60($t7)
/*  f145b1c:	24e77e20 */ 	addiu	$a3,$a3,0x7e20
/*  f145b20:	24a57e14 */ 	addiu	$a1,$a1,0x7e14
/*  f145b24:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f145b28:	02602025 */ 	move	$a0,$s3
/*  f145b2c:	00403025 */ 	move	$a2,$v0
/*  f145b30:	460042a1 */ 	cvt.d.s	$f10,$f8
/*  f145b34:	0c004e1d */ 	jal	sprintf
/*  f145b38:	f7aa0010 */ 	sdc1	$f10,0x10($sp)
/*  f145b3c:	3c188008 */ 	lui	$t8,0x8008
/*  f145b40:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f145b44:	3c078008 */ 	lui	$a3,0x8008
/*  f145b48:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f145b4c:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145b50:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145b54:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145b58:	02603025 */ 	move	$a2,$s3
/*  f145b5c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145b60:	0fc5625a */ 	jal	textMeasure
/*  f145b64:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145b68:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f145b6c:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f145b70:	02a02025 */ 	move	$a0,$s5
/*  f145b74:	02997021 */ 	addu	$t6,$s4,$t9
/*  f145b78:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f145b7c:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f145b80:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f145b84:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145b88:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f145b8c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145b90:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145b94:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f145b98:	afb402ec */ 	sw	$s4,0x2ec($sp)
/*  f145b9c:	0fc5531b */ 	jal	text0f153858
/*  f145ba0:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f145ba4:	0c002e4d */ 	jal	viGetWidth
/*  f145ba8:	0040a825 */ 	move	$s5,$v0
/*  f145bac:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145bb0:	00107403 */ 	sra	$t6,$s0,0x10
/*  f145bb4:	0c002e51 */ 	jal	viGetHeight
/*  f145bb8:	01c08025 */ 	move	$s0,$t6
/*  f145bbc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145bc0:	3c188008 */ 	lui	$t8,0x8008
/*  f145bc4:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f145bc8:	8def1fd8 */ 	lw	$t7,0x1fd8($t7)
/*  f145bcc:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145bd0:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f145bd4:	02a02025 */ 	move	$a0,$s5
/*  f145bd8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145bdc:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145be0:	02603825 */ 	move	$a3,$s3
/*  f145be4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145be8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145bec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145bf0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145bf4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f145bf8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145bfc:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f145c00:	0fc56160 */ 	jal	textRender
/*  f145c04:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f145c08:	0040a825 */ 	move	$s5,$v0
/*  f145c0c:	0fc5c06a */ 	jal	langGet
/*  f145c10:	2404580e */ 	li	$a0,0x580e
/*  f145c14:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f145c18:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145c1c:	24a57e24 */ 	addiu	$a1,$a1,0x7e24
/*  f145c20:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f145c24:	02602025 */ 	move	$a0,$s3
/*  f145c28:	00403025 */ 	move	$a2,$v0
/*  f145c2c:	c706001c */ 	lwc1	$f6,0x1c($t8)
/*  f145c30:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145c34:	44072000 */ 	mfc1	$a3,$f4
/*  f145c38:	0c004e1d */ 	jal	sprintf
/*  f145c3c:	00000000 */ 	nop
/*  f145c40:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145c44:	8dce1fd4 */ 	lw	$t6,0x1fd4($t6)
/*  f145c48:	3c078008 */ 	lui	$a3,0x8008
/*  f145c4c:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f145c50:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145c54:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145c58:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145c5c:	02603025 */ 	move	$a2,$s3
/*  f145c60:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145c64:	0fc5625a */ 	jal	textMeasure
/*  f145c68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145c6c:	8faf02e4 */ 	lw	$t7,0x2e4($sp)
/*  f145c70:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f145c74:	02a02025 */ 	move	$a0,$s5
/*  f145c78:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f145c7c:	27af02d8 */ 	addiu	$t7,$sp,0x2d8
/*  f145c80:	02397021 */ 	addu	$t6,$s1,$t9
/*  f145c84:	afae02d8 */ 	sw	$t6,0x2d8($sp)
/*  f145c88:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145c8c:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f145c90:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145c94:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145c98:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f145c9c:	afb402ec */ 	sw	$s4,0x2ec($sp)
/*  f145ca0:	0fc5531b */ 	jal	text0f153858
/*  f145ca4:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f145ca8:	0c002e4d */ 	jal	viGetWidth
/*  f145cac:	0040a825 */ 	move	$s5,$v0
/*  f145cb0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145cb4:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f145cb8:	0c002e51 */ 	jal	viGetHeight
/*  f145cbc:	03008025 */ 	move	$s0,$t8
/*  f145cc0:	3c198008 */ 	lui	$t9,0x8008
/*  f145cc4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145cc8:	8dce1fd4 */ 	lw	$t6,0x1fd4($t6)
/*  f145ccc:	8f391fd8 */ 	lw	$t9,0x1fd8($t9)
/*  f145cd0:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f145cd4:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f145cd8:	02a02025 */ 	move	$a0,$s5
/*  f145cdc:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145ce0:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145ce4:	02603825 */ 	move	$a3,$s3
/*  f145ce8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145cec:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145cf0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145cf4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145cf8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145cfc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145d00:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f145d04:	0fc56160 */ 	jal	textRender
/*  f145d08:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f145d0c:	0040a825 */ 	move	$s5,$v0
/*  f145d10:	0fc5c06a */ 	jal	langGet
/*  f145d14:	2404580f */ 	li	$a0,0x580f
/*  f145d18:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145d1c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145d20:	24a57e2c */ 	addiu	$a1,$a1,0x7e2c
/*  f145d24:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f145d28:	02602025 */ 	move	$a0,$s3
/*  f145d2c:	00403025 */ 	move	$a2,$v0
/*  f145d30:	c5c80028 */ 	lwc1	$f8,0x28($t6)
/*  f145d34:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145d38:	44075000 */ 	mfc1	$a3,$f10
/*  f145d3c:	0c004e1d */ 	jal	sprintf
/*  f145d40:	00000000 */ 	nop
/*  f145d44:	3c188008 */ 	lui	$t8,0x8008
/*  f145d48:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f145d4c:	3c078008 */ 	lui	$a3,0x8008
/*  f145d50:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f145d54:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145d58:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145d5c:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145d60:	02603025 */ 	move	$a2,$s3
/*  f145d64:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145d68:	0fc5625a */ 	jal	textMeasure
/*  f145d6c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145d70:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f145d74:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f145d78:	02a02025 */ 	move	$a0,$s5
/*  f145d7c:	02997021 */ 	addu	$t6,$s4,$t9
/*  f145d80:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f145d84:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f145d88:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f145d8c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145d90:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f145d94:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145d98:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145d9c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f145da0:	afb402ec */ 	sw	$s4,0x2ec($sp)
/*  f145da4:	0fc5531b */ 	jal	text0f153858
/*  f145da8:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f145dac:	0c002e4d */ 	jal	viGetWidth
/*  f145db0:	0040a825 */ 	move	$s5,$v0
/*  f145db4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145db8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f145dbc:	0c002e51 */ 	jal	viGetHeight
/*  f145dc0:	01c08025 */ 	move	$s0,$t6
/*  f145dc4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145dc8:	3c188008 */ 	lui	$t8,0x8008
/*  f145dcc:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f145dd0:	8def1fd8 */ 	lw	$t7,0x1fd8($t7)
/*  f145dd4:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145dd8:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f145ddc:	02a02025 */ 	move	$a0,$s5
/*  f145de0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145de4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145de8:	02603825 */ 	move	$a3,$s3
/*  f145dec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145df0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145df4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145df8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145dfc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f145e00:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145e04:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f145e08:	0fc56160 */ 	jal	textRender
/*  f145e0c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f145e10:	0040a825 */ 	move	$s5,$v0
/*  f145e14:	0fc5c06a */ 	jal	langGet
/*  f145e18:	24045810 */ 	li	$a0,0x5810
/*  f145e1c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145e20:	24a57e34 */ 	addiu	$a1,$a1,0x7e34
/*  f145e24:	02602025 */ 	move	$a0,$s3
/*  f145e28:	0c004e1d */ 	jal	sprintf
/*  f145e2c:	00403025 */ 	move	$a2,$v0
/*  f145e30:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145e34:	8def1fd4 */ 	lw	$t7,0x1fd4($t7)
/*  f145e38:	3c078008 */ 	lui	$a3,0x8008
/*  f145e3c:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145e40:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145e44:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145e48:	02603025 */ 	move	$a2,$s3
/*  f145e4c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145e50:	0fc5625a */ 	jal	textMeasure
/*  f145e54:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145e58:	8fa902a4 */ 	lw	$t1,0x2a4($sp)
/*  f145e5c:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f145e60:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f145e64:	11200003 */ 	beqz	$t1,.PB0f145e74
/*  f145e68:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f145e6c:	10000002 */ 	b	.PB0f145e78
/*  f145e70:	2402fffd */ 	li	$v0,-3
.PB0f145e74:
/*  f145e74:	00001025 */ 	move	$v0,$zero
.PB0f145e78:
/*  f145e78:	00581821 */ 	addu	$v1,$v0,$t8
/*  f145e7c:	11200003 */ 	beqz	$t1,.PB0f145e8c
/*  f145e80:	2463001e */ 	addiu	$v1,$v1,0x1e
/*  f145e84:	10000002 */ 	b	.PB0f145e90
/*  f145e88:	24020012 */ 	li	$v0,0x12
.PB0f145e8c:
/*  f145e8c:	00001025 */ 	move	$v0,$zero
.PB0f145e90:
/*  f145e90:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f145e94:	00594021 */ 	addu	$t0,$v0,$t9
/*  f145e98:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f145e9c:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f145ea0:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f145ea4:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f145ea8:	afb902d8 */ 	sw	$t9,0x2d8($sp)
/*  f145eac:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145eb0:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f145eb4:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f145eb8:	02a02025 */ 	move	$a0,$s5
/*  f145ebc:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145ec0:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145ec4:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f145ec8:	0fc5531b */ 	jal	text0f153858
/*  f145ecc:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f145ed0:	0c002e4d */ 	jal	viGetWidth
/*  f145ed4:	0040a825 */ 	move	$s5,$v0
/*  f145ed8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145edc:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f145ee0:	0c002e51 */ 	jal	viGetHeight
/*  f145ee4:	01e08025 */ 	move	$s0,$t7
/*  f145ee8:	3c188008 */ 	lui	$t8,0x8008
/*  f145eec:	3c198008 */ 	lui	$t9,0x8008
/*  f145ef0:	8f391fd4 */ 	lw	$t9,0x1fd4($t9)
/*  f145ef4:	8f181fd8 */ 	lw	$t8,0x1fd8($t8)
/*  f145ef8:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f145efc:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145f00:	02a02025 */ 	move	$a0,$s5
/*  f145f04:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145f08:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145f0c:	02603825 */ 	move	$a3,$s3
/*  f145f10:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145f14:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145f18:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145f1c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145f20:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f145f24:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145f28:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f145f2c:	0fc56160 */ 	jal	textRender
/*  f145f30:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f145f34:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145f38:	0040a825 */ 	move	$s5,$v0
/*  f145f3c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145f40:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f145f44:	5460000b */ 	bnezl	$v1,.PB0f145f74
/*  f145f48:	24010001 */ 	li	$at,0x1
/*  f145f4c:	0fc5c06a */ 	jal	langGet
/*  f145f50:	24045811 */ 	li	$a0,0x5811
/*  f145f54:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145f58:	24a57e38 */ 	addiu	$a1,$a1,0x7e38
/*  f145f5c:	02602025 */ 	move	$a0,$s3
/*  f145f60:	0c004e1d */ 	jal	sprintf
/*  f145f64:	00403025 */ 	move	$a2,$v0
/*  f145f68:	10000014 */ 	b	.PB0f145fbc
/*  f145f6c:	00000000 */ 	nop
/*  f145f70:	24010001 */ 	li	$at,0x1
.PB0f145f74:
/*  f145f74:	1461000a */ 	bne	$v1,$at,.PB0f145fa0
/*  f145f78:	00000000 */ 	nop
/*  f145f7c:	0fc5c06a */ 	jal	langGet
/*  f145f80:	24045893 */ 	li	$a0,0x5893
/*  f145f84:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145f88:	24a57e3c */ 	addiu	$a1,$a1,0x7e3c
/*  f145f8c:	02602025 */ 	move	$a0,$s3
/*  f145f90:	0c004e1d */ 	jal	sprintf
/*  f145f94:	00403025 */ 	move	$a2,$v0
/*  f145f98:	10000008 */ 	b	.PB0f145fbc
/*  f145f9c:	00000000 */ 	nop
.PB0f145fa0:
/*  f145fa0:	0fc5c06a */ 	jal	langGet
/*  f145fa4:	2404589c */ 	li	$a0,0x589c
/*  f145fa8:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145fac:	24a57e40 */ 	addiu	$a1,$a1,0x7e40
/*  f145fb0:	02602025 */ 	move	$a0,$s3
/*  f145fb4:	0c004e1d */ 	jal	sprintf
/*  f145fb8:	00403025 */ 	move	$a2,$v0
.PB0f145fbc:
/*  f145fbc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145fc0:	8dce1fd4 */ 	lw	$t6,0x1fd4($t6)
/*  f145fc4:	3c078008 */ 	lui	$a3,0x8008
/*  f145fc8:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f145fcc:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145fd0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f145fd4:	02603025 */ 	move	$a2,$s3
/*  f145fd8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145fdc:	0fc5625a */ 	jal	textMeasure
/*  f145fe0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145fe4:	8fa902a4 */ 	lw	$t1,0x2a4($sp)
/*  f145fe8:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f145fec:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f145ff0:	11200003 */ 	beqz	$t1,.PB0f146000
/*  f145ff4:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f145ff8:	10000002 */ 	b	.PB0f146004
/*  f145ffc:	2402fffd */ 	li	$v0,-3
.PB0f146000:
/*  f146000:	00001025 */ 	move	$v0,$zero
.PB0f146004:
/*  f146004:	004f1821 */ 	addu	$v1,$v0,$t7
/*  f146008:	11200003 */ 	beqz	$t1,.PB0f146018
/*  f14600c:	2463001e */ 	addiu	$v1,$v1,0x1e
/*  f146010:	10000002 */ 	b	.PB0f14601c
/*  f146014:	24020014 */ 	li	$v0,0x14
.PB0f146018:
/*  f146018:	00001025 */ 	move	$v0,$zero
.PB0f14601c:
/*  f14601c:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146020:	00584021 */ 	addu	$t0,$v0,$t8
/*  f146024:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f146028:	00797021 */ 	addu	$t6,$v1,$t9
/*  f14602c:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f146030:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f146034:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f146038:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14603c:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f146040:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146044:	02a02025 */ 	move	$a0,$s5
/*  f146048:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14604c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146050:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f146054:	0fc5531b */ 	jal	text0f153858
/*  f146058:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f14605c:	0c002e4d */ 	jal	viGetWidth
/*  f146060:	0040a825 */ 	move	$s5,$v0
/*  f146064:	00028400 */ 	sll	$s0,$v0,0x10
/*  f146068:	00107403 */ 	sra	$t6,$s0,0x10
/*  f14606c:	0c002e51 */ 	jal	viGetHeight
/*  f146070:	01c08025 */ 	move	$s0,$t6
/*  f146074:	3c0f8008 */ 	lui	$t7,0x8008
/*  f146078:	3c188008 */ 	lui	$t8,0x8008
/*  f14607c:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f146080:	8def1fd8 */ 	lw	$t7,0x1fd8($t7)
/*  f146084:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f146088:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f14608c:	02a02025 */ 	move	$a0,$s5
/*  f146090:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146094:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146098:	02603825 */ 	move	$a3,$s3
/*  f14609c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1460a0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1460a4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1460a8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1460ac:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1460b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1460b4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1460b8:	0fc56160 */ 	jal	textRender
/*  f1460bc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1460c0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1460c4:	0040a825 */ 	move	$s5,$v0
/*  f1460c8:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1460cc:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1460d0:	54600047 */ 	bnezl	$v1,.PB0f1461f0
/*  f1460d4:	24010001 */ 	li	$at,0x1
/*  f1460d8:	0fc5c06a */ 	jal	langGet
/*  f1460dc:	24045812 */ 	li	$a0,0x5812
/*  f1460e0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1460e4:	24a57e44 */ 	addiu	$a1,$a1,0x7e44
/*  f1460e8:	02602025 */ 	move	$a0,$s3
/*  f1460ec:	0c004e1d */ 	jal	sprintf
/*  f1460f0:	00403025 */ 	move	$a2,$v0
/*  f1460f4:	3c198008 */ 	lui	$t9,0x8008
/*  f1460f8:	8f391fd4 */ 	lw	$t9,0x1fd4($t9)
/*  f1460fc:	3c078008 */ 	lui	$a3,0x8008
/*  f146100:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f146104:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f146108:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14610c:	02603025 */ 	move	$a2,$s3
/*  f146110:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f146114:	0fc5625a */ 	jal	textMeasure
/*  f146118:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14611c:	8fae02a4 */ 	lw	$t6,0x2a4($sp)
/*  f146120:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f146124:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f146128:	11c00003 */ 	beqz	$t6,.PB0f146138
/*  f14612c:	2463ffb2 */ 	addiu	$v1,$v1,-78
/*  f146130:	10000002 */ 	b	.PB0f14613c
/*  f146134:	2402fff3 */ 	li	$v0,-13
.PB0f146138:
/*  f146138:	00001025 */ 	move	$v0,$zero
.PB0f14613c:
/*  f14613c:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f146140:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f146144:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f146148:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f14614c:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f146150:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f146154:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f146158:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f14615c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f146160:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f146164:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146168:	02a02025 */ 	move	$a0,$s5
/*  f14616c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146170:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146174:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f146178:	0fc5531b */ 	jal	text0f153858
/*  f14617c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146180:	0c002e4d */ 	jal	viGetWidth
/*  f146184:	0040a825 */ 	move	$s5,$v0
/*  f146188:	00028400 */ 	sll	$s0,$v0,0x10
/*  f14618c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f146190:	0c002e51 */ 	jal	viGetHeight
/*  f146194:	03208025 */ 	move	$s0,$t9
/*  f146198:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14619c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1461a0:	8def1fd4 */ 	lw	$t7,0x1fd4($t7)
/*  f1461a4:	8dce1fd8 */ 	lw	$t6,0x1fd8($t6)
/*  f1461a8:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f1461ac:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f1461b0:	02a02025 */ 	move	$a0,$s5
/*  f1461b4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1461b8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1461bc:	02603825 */ 	move	$a3,$s3
/*  f1461c0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1461c4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1461c8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1461cc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1461d0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1461d4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1461d8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1461dc:	0fc56160 */ 	jal	textRender
/*  f1461e0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1461e4:	1000008d */ 	b	.PB0f14641c
/*  f1461e8:	0040a825 */ 	move	$s5,$v0
/*  f1461ec:	24010001 */ 	li	$at,0x1
.PB0f1461f0:
/*  f1461f0:	14610046 */ 	bne	$v1,$at,.PB0f14630c
/*  f1461f4:	00000000 */ 	nop
/*  f1461f8:	0fc5c06a */ 	jal	langGet
/*  f1461fc:	240458d1 */ 	li	$a0,0x58d1
/*  f146200:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f146204:	24a57e4c */ 	addiu	$a1,$a1,0x7e4c
/*  f146208:	02602025 */ 	move	$a0,$s3
/*  f14620c:	0c004e1d */ 	jal	sprintf
/*  f146210:	00403025 */ 	move	$a2,$v0
/*  f146214:	3c0e8008 */ 	lui	$t6,0x8008
/*  f146218:	8dce1fd4 */ 	lw	$t6,0x1fd4($t6)
/*  f14621c:	3c078008 */ 	lui	$a3,0x8008
/*  f146220:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f146224:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f146228:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14622c:	02603025 */ 	move	$a2,$s3
/*  f146230:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f146234:	0fc5625a */ 	jal	textMeasure
/*  f146238:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f14623c:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f146240:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f146244:	8fb802fc */ 	lw	$t8,0x2fc($sp)
/*  f146248:	11e00003 */ 	beqz	$t7,.PB0f146258
/*  f14624c:	2463ffb2 */ 	addiu	$v1,$v1,-78
/*  f146250:	10000002 */ 	b	.PB0f14625c
/*  f146254:	2402fff3 */ 	li	$v0,-13
.PB0f146258:
/*  f146258:	00001025 */ 	move	$v0,$zero
.PB0f14625c:
/*  f14625c:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f146260:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146264:	00584021 */ 	addu	$t0,$v0,$t8
/*  f146268:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f14626c:	00797021 */ 	addu	$t6,$v1,$t9
/*  f146270:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f146274:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f146278:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f14627c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f146280:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f146284:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146288:	02a02025 */ 	move	$a0,$s5
/*  f14628c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146290:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146294:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f146298:	0fc5531b */ 	jal	text0f153858
/*  f14629c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1462a0:	0c002e4d */ 	jal	viGetWidth
/*  f1462a4:	0040a825 */ 	move	$s5,$v0
/*  f1462a8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1462ac:	00107403 */ 	sra	$t6,$s0,0x10
/*  f1462b0:	0c002e51 */ 	jal	viGetHeight
/*  f1462b4:	01c08025 */ 	move	$s0,$t6
/*  f1462b8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1462bc:	3c188008 */ 	lui	$t8,0x8008
/*  f1462c0:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f1462c4:	8def1fd8 */ 	lw	$t7,0x1fd8($t7)
/*  f1462c8:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f1462cc:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f1462d0:	02a02025 */ 	move	$a0,$s5
/*  f1462d4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1462d8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1462dc:	02603825 */ 	move	$a3,$s3
/*  f1462e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1462e4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1462e8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1462ec:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1462f0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1462f4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1462f8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f1462fc:	0fc56160 */ 	jal	textRender
/*  f146300:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f146304:	10000045 */ 	b	.PB0f14641c
/*  f146308:	0040a825 */ 	move	$s5,$v0
.PB0f14630c:
/*  f14630c:	0fc5c06a */ 	jal	langGet
/*  f146310:	240458d2 */ 	li	$a0,0x58d2
/*  f146314:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f146318:	24a57e54 */ 	addiu	$a1,$a1,0x7e54
/*  f14631c:	02602025 */ 	move	$a0,$s3
/*  f146320:	0c004e1d */ 	jal	sprintf
/*  f146324:	00403025 */ 	move	$a2,$v0
/*  f146328:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14632c:	8def1fd4 */ 	lw	$t7,0x1fd4($t7)
/*  f146330:	3c078008 */ 	lui	$a3,0x8008
/*  f146334:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f146338:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f14633c:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f146340:	02603025 */ 	move	$a2,$s3
/*  f146344:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f146348:	0fc5625a */ 	jal	textMeasure
/*  f14634c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f146350:	8fb802a4 */ 	lw	$t8,0x2a4($sp)
/*  f146354:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f146358:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f14635c:	13000003 */ 	beqz	$t8,.PB0f14636c
/*  f146360:	2463ffac */ 	addiu	$v1,$v1,-84
/*  f146364:	10000002 */ 	b	.PB0f146370
/*  f146368:	2402fff3 */ 	li	$v0,-13
.PB0f14636c:
/*  f14636c:	00001025 */ 	move	$v0,$zero
.PB0f146370:
/*  f146370:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f146374:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f146378:	00594021 */ 	addu	$t0,$v0,$t9
/*  f14637c:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f146380:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f146384:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f146388:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f14638c:	afb902d8 */ 	sw	$t9,0x2d8($sp)
/*  f146390:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f146394:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f146398:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f14639c:	02a02025 */ 	move	$a0,$s5
/*  f1463a0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1463a4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1463a8:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f1463ac:	0fc5531b */ 	jal	text0f153858
/*  f1463b0:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1463b4:	0c002e4d */ 	jal	viGetWidth
/*  f1463b8:	0040a825 */ 	move	$s5,$v0
/*  f1463bc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1463c0:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1463c4:	0c002e51 */ 	jal	viGetHeight
/*  f1463c8:	01e08025 */ 	move	$s0,$t7
/*  f1463cc:	3c188008 */ 	lui	$t8,0x8008
/*  f1463d0:	3c198008 */ 	lui	$t9,0x8008
/*  f1463d4:	8f391fd4 */ 	lw	$t9,0x1fd4($t9)
/*  f1463d8:	8f181fd8 */ 	lw	$t8,0x1fd8($t8)
/*  f1463dc:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f1463e0:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f1463e4:	02a02025 */ 	move	$a0,$s5
/*  f1463e8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1463ec:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1463f0:	02603825 */ 	move	$a3,$s3
/*  f1463f4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1463f8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1463fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f146400:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f146404:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f146408:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f14640c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f146410:	0fc56160 */ 	jal	textRender
/*  f146414:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f146418:	0040a825 */ 	move	$s5,$v0
.PB0f14641c:
/*  f14641c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146420:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f146424:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146428:	5460000b */ 	bnezl	$v1,.PB0f146458
/*  f14642c:	24010001 */ 	li	$at,0x1
/*  f146430:	0fc5c06a */ 	jal	langGet
/*  f146434:	24045813 */ 	li	$a0,0x5813
/*  f146438:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14643c:	24a57e5c */ 	addiu	$a1,$a1,0x7e5c
/*  f146440:	02602025 */ 	move	$a0,$s3
/*  f146444:	0c004e1d */ 	jal	sprintf
/*  f146448:	00403025 */ 	move	$a2,$v0
/*  f14644c:	10000014 */ 	b	.PB0f1464a0
/*  f146450:	00000000 */ 	nop
/*  f146454:	24010001 */ 	li	$at,0x1
.PB0f146458:
/*  f146458:	1461000a */ 	bne	$v1,$at,.PB0f146484
/*  f14645c:	00000000 */ 	nop
/*  f146460:	0fc5c06a */ 	jal	langGet
/*  f146464:	24045892 */ 	li	$a0,0x5892
/*  f146468:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14646c:	24a57e60 */ 	addiu	$a1,$a1,0x7e60
/*  f146470:	02602025 */ 	move	$a0,$s3
/*  f146474:	0c004e1d */ 	jal	sprintf
/*  f146478:	00403025 */ 	move	$a2,$v0
/*  f14647c:	10000008 */ 	b	.PB0f1464a0
/*  f146480:	00000000 */ 	nop
.PB0f146484:
/*  f146484:	0fc5c06a */ 	jal	langGet
/*  f146488:	2404589b */ 	li	$a0,0x589b
/*  f14648c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f146490:	24a57e64 */ 	addiu	$a1,$a1,0x7e64
/*  f146494:	02602025 */ 	move	$a0,$s3
/*  f146498:	0c004e1d */ 	jal	sprintf
/*  f14649c:	00403025 */ 	move	$a2,$v0
.PB0f1464a0:
/*  f1464a0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1464a4:	8dce1fd4 */ 	lw	$t6,0x1fd4($t6)
/*  f1464a8:	3c078008 */ 	lui	$a3,0x8008
/*  f1464ac:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f1464b0:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f1464b4:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f1464b8:	02603025 */ 	move	$a2,$s3
/*  f1464bc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1464c0:	0fc5625a */ 	jal	textMeasure
/*  f1464c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1464c8:	8fa902a4 */ 	lw	$t1,0x2a4($sp)
/*  f1464cc:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1464d0:	8fb802fc */ 	lw	$t8,0x2fc($sp)
/*  f1464d4:	11200003 */ 	beqz	$t1,.PB0f1464e4
/*  f1464d8:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f1464dc:	10000002 */ 	b	.PB0f1464e8
/*  f1464e0:	24020003 */ 	li	$v0,0x3
.PB0f1464e4:
/*  f1464e4:	00001025 */ 	move	$v0,$zero
.PB0f1464e8:
/*  f1464e8:	004f1821 */ 	addu	$v1,$v0,$t7
/*  f1464ec:	11200003 */ 	beqz	$t1,.PB0f1464fc
/*  f1464f0:	2463ffb9 */ 	addiu	$v1,$v1,-71
/*  f1464f4:	10000002 */ 	b	.PB0f146500
/*  f1464f8:	2402fff5 */ 	li	$v0,-11
.PB0f1464fc:
/*  f1464fc:	00001025 */ 	move	$v0,$zero
.PB0f146500:
/*  f146500:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146504:	00584021 */ 	addu	$t0,$v0,$t8
/*  f146508:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f14650c:	00797021 */ 	addu	$t6,$v1,$t9
/*  f146510:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f146514:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f146518:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f14651c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f146520:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f146524:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146528:	02a02025 */ 	move	$a0,$s5
/*  f14652c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146530:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146534:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f146538:	0fc5531b */ 	jal	text0f153858
/*  f14653c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146540:	0c002e4d */ 	jal	viGetWidth
/*  f146544:	0040a825 */ 	move	$s5,$v0
/*  f146548:	00028400 */ 	sll	$s0,$v0,0x10
/*  f14654c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f146550:	0c002e51 */ 	jal	viGetHeight
/*  f146554:	01c08025 */ 	move	$s0,$t6
/*  f146558:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14655c:	3c188008 */ 	lui	$t8,0x8008
/*  f146560:	8f181fd4 */ 	lw	$t8,0x1fd4($t8)
/*  f146564:	8def1fd8 */ 	lw	$t7,0x1fd8($t7)
/*  f146568:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f14656c:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f146570:	02a02025 */ 	move	$a0,$s5
/*  f146574:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146578:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14657c:	02603825 */ 	move	$a3,$s3
/*  f146580:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f146584:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f146588:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14658c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f146590:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f146594:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f146598:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f14659c:	0fc56160 */ 	jal	textRender
/*  f1465a0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1465a4:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1465a8:	0040a825 */ 	move	$s5,$v0
/*  f1465ac:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1465b0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1465b4:	10600003 */ 	beqz	$v1,.PB0f1465c4
/*  f1465b8:	24010002 */ 	li	$at,0x2
/*  f1465bc:	1461000a */ 	bne	$v1,$at,.PB0f1465e8
/*  f1465c0:	00000000 */ 	nop
.PB0f1465c4:
/*  f1465c4:	0fc5c06a */ 	jal	langGet
/*  f1465c8:	24045814 */ 	li	$a0,0x5814
/*  f1465cc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1465d0:	24a57e68 */ 	addiu	$a1,$a1,0x7e68
/*  f1465d4:	02602025 */ 	move	$a0,$s3
/*  f1465d8:	0c004e1d */ 	jal	sprintf
/*  f1465dc:	00403025 */ 	move	$a2,$v0
/*  f1465e0:	10000008 */ 	b	.PB0f146604
/*  f1465e4:	00000000 */ 	nop
.PB0f1465e8:
/*  f1465e8:	0fc5c06a */ 	jal	langGet
/*  f1465ec:	24045891 */ 	li	$a0,0x5891
/*  f1465f0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1465f4:	24a57e6c */ 	addiu	$a1,$a1,0x7e6c
/*  f1465f8:	02602025 */ 	move	$a0,$s3
/*  f1465fc:	0c004e1d */ 	jal	sprintf
/*  f146600:	00403025 */ 	move	$a2,$v0
.PB0f146604:
/*  f146604:	3c198008 */ 	lui	$t9,0x8008
/*  f146608:	8f391fd4 */ 	lw	$t9,0x1fd4($t9)
/*  f14660c:	3c078008 */ 	lui	$a3,0x8008
/*  f146610:	8ce71fd8 */ 	lw	$a3,0x1fd8($a3)
/*  f146614:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f146618:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14661c:	02603025 */ 	move	$a2,$s3
/*  f146620:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f146624:	0fc5625a */ 	jal	textMeasure
/*  f146628:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14662c:	8fae02a4 */ 	lw	$t6,0x2a4($sp)
/*  f146630:	3c014040 */ 	lui	$at,0x4040
/*  f146634:	44812000 */ 	mtc1	$at,$f4
/*  f146638:	11c00003 */ 	beqz	$t6,.PB0f146648
/*  f14663c:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f146640:	10000002 */ 	b	.PB0f14664c
/*  f146644:	2402ffdd */ 	li	$v0,-35
.PB0f146648:
/*  f146648:	00001025 */ 	move	$v0,$zero
.PB0f14664c:
/*  f14664c:	44805000 */ 	mtc1	$zero,$f10
/*  f146650:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f146654:	8fb802a4 */ 	lw	$t8,0x2a4($sp)
/*  f146658:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f14665c:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f146660:	44825000 */ 	mtc1	$v0,$f10
/*  f146664:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f146668:	02a02025 */ 	move	$a0,$s5
/*  f14666c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146670:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f146674:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f146678:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f14667c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f146680:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f146684:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146688:	44035000 */ 	mfc1	$v1,$f10
/*  f14668c:	53000004 */ 	beqzl	$t8,.PB0f1466a0
/*  f146690:	00001025 */ 	move	$v0,$zero
/*  f146694:	10000002 */ 	b	.PB0f1466a0
/*  f146698:	2402fffe */ 	li	$v0,-2
/*  f14669c:	00001025 */ 	move	$v0,$zero
.PB0f1466a0:
/*  f1466a0:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f1466a4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1466a8:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f1466ac:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f1466b0:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f1466b4:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f1466b8:	afb902d8 */ 	sw	$t9,0x2d8($sp)
/*  f1466bc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1466c0:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f1466c4:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f1466c8:	0fc5531b */ 	jal	text0f153858
/*  f1466cc:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1466d0:	0c002e4d */ 	jal	viGetWidth
/*  f1466d4:	0040a825 */ 	move	$s5,$v0
/*  f1466d8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1466dc:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1466e0:	0c002e51 */ 	jal	viGetHeight
/*  f1466e4:	01e08025 */ 	move	$s0,$t7
/*  f1466e8:	3c188008 */ 	lui	$t8,0x8008
/*  f1466ec:	3c198008 */ 	lui	$t9,0x8008
/*  f1466f0:	8f391fd4 */ 	lw	$t9,0x1fd4($t9)
/*  f1466f4:	8f181fd8 */ 	lw	$t8,0x1fd8($t8)
/*  f1466f8:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f1466fc:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f146700:	02a02025 */ 	move	$a0,$s5
/*  f146704:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f146708:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14670c:	02603825 */ 	move	$a3,$s3
/*  f146710:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f146714:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f146718:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14671c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f146720:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f146724:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f146728:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f14672c:	0fc56160 */ 	jal	textRender
/*  f146730:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f146734:	0fc55313 */ 	jal	text0f153838
/*  f146738:	00402025 */ 	move	$a0,$v0
/*  f14673c:	8ed80288 */ 	lw	$t8,0x288($s6)
/*  f146740:	0040a825 */ 	move	$s5,$v0
/*  f146744:	0fc54ebe */ 	jal	optionsGetContpadNum1
/*  f146748:	8f040070 */ 	lw	$a0,0x70($t8)
/*  f14674c:	00028600 */ 	sll	$s0,$v0,0x18
/*  f146750:	00022600 */ 	sll	$a0,$v0,0x18
/*  f146754:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f146758:	00047603 */ 	sra	$t6,$a0,0x18
/*  f14675c:	03208025 */ 	move	$s0,$t9
/*  f146760:	01c02025 */ 	move	$a0,$t6
/*  f146764:	0c00566a */ 	jal	joyGetButtons
/*  f146768:	3405ffff */ 	li	$a1,0xffff
/*  f14676c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f146770:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f146774:	01e02025 */ 	move	$a0,$t7
/*  f146778:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f14677c:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f146780:	3405ffff */ 	li	$a1,0xffff
/*  f146784:	00102600 */ 	sll	$a0,$s0,0x18
/*  f146788:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f14678c:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f146790:	0c005616 */ 	jal	joyGetStickX
/*  f146794:	03002025 */ 	move	$a0,$t8
/*  f146798:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f14679c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1467a0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f1467a4:	0014ce03 */ 	sra	$t9,$s4,0x18
/*  f1467a8:	0320a025 */ 	move	$s4,$t9
/*  f1467ac:	0c005640 */ 	jal	joyGetStickY
/*  f1467b0:	01c02025 */ 	move	$a0,$t6
/*  f1467b4:	02a01825 */ 	move	$v1,$s5
/*  f1467b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1467bc:	3c0fe700 */ 	lui	$t7,0xe700
/*  f1467c0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1467c4:	02a02025 */ 	move	$a0,$s5
/*  f1467c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1467cc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1467d0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1467d4:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f1467d8:	02a02825 */ 	move	$a1,$s5
/*  f1467dc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1467e0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1467e4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f1467e8:	37390602 */ 	ori	$t9,$t9,0x602
/*  f1467ec:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1467f0:	240e00c0 */ 	li	$t6,0xc0
/*  f1467f4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f1467f8:	02a03025 */ 	move	$a2,$s5
/*  f1467fc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f146800:	3c0fba00 */ 	lui	$t7,0xba00
/*  f146804:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f146808:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f14680c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146810:	02a03825 */ 	move	$a3,$s5
/*  f146814:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f146818:	3c18b900 */ 	lui	$t8,0xb900
/*  f14681c:	37180002 */ 	ori	$t8,$t8,0x2
/*  f146820:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146824:	02a01825 */ 	move	$v1,$s5
/*  f146828:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f14682c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f146830:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f146834:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146838:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f14683c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f146840:	02a02025 */ 	move	$a0,$s5
/*  f146844:	3c0eba00 */ 	lui	$t6,0xba00
/*  f146848:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f14684c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146850:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f146854:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146858:	02a02825 */ 	move	$a1,$s5
/*  f14685c:	240f2000 */ 	li	$t7,0x2000
/*  f146860:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146864:	3c18ba00 */ 	lui	$t8,0xba00
/*  f146868:	37180903 */ 	ori	$t8,$t8,0x903
/*  f14686c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146870:	24190c00 */ 	li	$t9,0xc00
/*  f146874:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f146878:	02a03025 */ 	move	$a2,$s5
/*  f14687c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f146880:	3c0eba00 */ 	lui	$t6,0xba00
/*  f146884:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f146888:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14688c:	02a04025 */ 	move	$t0,$s5
/*  f146890:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f146894:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f146898:	3c180050 */ 	lui	$t8,0x50
/*  f14689c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f1468a0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f1468a4:	37184340 */ 	ori	$t8,$t8,0x4340
/*  f1468a8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1468ac:	02a01825 */ 	move	$v1,$s5
/*  f1468b0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f1468b4:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f1468b8:	3c0efffd */ 	lui	$t6,0xfffd
/*  f1468bc:	3c19fcff */ 	lui	$t9,0xfcff
/*  f1468c0:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f1468c4:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f1468c8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1468cc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1468d0:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f1468d4:	44944000 */ 	mtc1	$s4,$f8
/*  f1468d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1468dc:	15e001d8 */ 	bnez	$t7,.PB0f147040
/*  f1468e0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f1468e4:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1468e8:	2405ffab */ 	li	$a1,-85
/*  f1468ec:	24010001 */ 	li	$at,0x1
/*  f1468f0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1468f4:	24130014 */ 	li	$s3,0x14
/*  f1468f8:	322e0808 */ 	andi	$t6,$s1,0x808
/*  f1468fc:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146900:	324f0808 */ 	andi	$t7,$s2,0x808
/*  f146904:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f146908:	14600011 */ 	bnez	$v1,.PB0f146950
/*  f14690c:	3c0b1020 */ 	lui	$t3,0x1020
/*  f146910:	11c00002 */ 	beqz	$t6,.PB0f14691c
/*  f146914:	02203025 */ 	move	$a2,$s1
/*  f146918:	24130028 */ 	li	$s3,0x28
.PB0f14691c:
/*  f14691c:	11e00004 */ 	beqz	$t7,.PB0f146930
/*  f146920:	02403825 */ 	move	$a3,$s2
/*  f146924:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146928:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14692c:	03009825 */ 	move	$s3,$t8
.PB0f146930:
/*  f146930:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146934:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146938:	02a01825 */ 	move	$v1,$s5
/*  f14693c:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f146940:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146944:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146948:	1000002f */ 	b	.PB0f146a08
/*  f14694c:	26b50008 */ 	addiu	$s5,$s5,0x8
.PB0f146950:
/*  f146950:	14610017 */ 	bne	$v1,$at,.PB0f1469b0
/*  f146954:	24130014 */ 	li	$s3,0x14
/*  f146958:	32380808 */ 	andi	$t8,$s1,0x808
/*  f14695c:	2413007f */ 	li	$s3,0x7f
/*  f146960:	13000002 */ 	beqz	$t8,.PB0f14696c
/*  f146964:	02203025 */ 	move	$a2,$s1
/*  f146968:	241300be */ 	li	$s3,0xbe
.PB0f14696c:
/*  f14696c:	32590808 */ 	andi	$t9,$s2,0x808
/*  f146970:	13200004 */ 	beqz	$t9,.PB0f146984
/*  f146974:	02403825 */ 	move	$a3,$s2
/*  f146978:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f14697c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146980:	01c09825 */ 	move	$s3,$t6
.PB0f146984:
/*  f146984:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146988:	000fc200 */ 	sll	$t8,$t7,0x8
/*  f14698c:	3c0b1020 */ 	lui	$t3,0x1020
/*  f146990:	030bc825 */ 	or	$t9,$t8,$t3
/*  f146994:	02a01825 */ 	move	$v1,$s5
/*  f146998:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f14699c:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f1469a0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1469a4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1469a8:	10000017 */ 	b	.PB0f146a08
/*  f1469ac:	26b50008 */ 	addiu	$s5,$s5,0x8
.PB0f1469b0:
/*  f1469b0:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f1469b4:	11e00002 */ 	beqz	$t7,.PB0f1469c0
/*  f1469b8:	02203025 */ 	move	$a2,$s1
/*  f1469bc:	24130028 */ 	li	$s3,0x28
.PB0f1469c0:
/*  f1469c0:	32580808 */ 	andi	$t8,$s2,0x808
/*  f1469c4:	13000004 */ 	beqz	$t8,.PB0f1469d8
/*  f1469c8:	02403825 */ 	move	$a3,$s2
/*  f1469cc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1469d0:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1469d4:	03209825 */ 	move	$s3,$t9
.PB0f1469d8:
/*  f1469d8:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f1469dc:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1469e0:	00197400 */ 	sll	$t6,$t9,0x10
/*  f1469e4:	02a01825 */ 	move	$v1,$s5
/*  f1469e8:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f1469ec:	01eec025 */ 	or	$t8,$t7,$t6
/*  f1469f0:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1469f4:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f1469f8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1469fc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146a00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a04:	3c0b1020 */ 	lui	$t3,0x1020
.PB0f146a08:
/*  f146a08:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f146a0c:	8fbf02fc */ 	lw	$ra,0x2fc($sp)
/*  f146a10:	3c01f600 */ 	lui	$at,0xf600
/*  f146a14:	00b05021 */ 	addu	$t2,$a1,$s0
/*  f146a18:	254a0008 */ 	addiu	$t2,$t2,0x8
/*  f146a1c:	27ec0012 */ 	addiu	$t4,$ra,0x12
/*  f146a20:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f146a24:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f146a28:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f146a2c:	000f6080 */ 	sll	$t4,$t7,0x2
/*  f146a30:	03217825 */ 	or	$t7,$t9,$at
/*  f146a34:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f146a38:	02a02025 */ 	move	$a0,$s5
/*  f146a3c:	00b04021 */ 	addu	$t0,$a1,$s0
/*  f146a40:	27ed000a */ 	addiu	$t5,$ra,0xa
/*  f146a44:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f146a48:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f146a4c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146a50:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146a54:	00186880 */ 	sll	$t5,$t8,0x2
/*  f146a58:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f146a5c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146a60:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146a64:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a68:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146a6c:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146a70:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146a74:	30f80404 */ 	andi	$t8,$a3,0x404
/*  f146a78:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146a7c:	30ce0404 */ 	andi	$t6,$a2,0x404
/*  f146a80:	24010001 */ 	li	$at,0x1
/*  f146a84:	14600010 */ 	bnez	$v1,.PB0f146ac8
/*  f146a88:	00000000 */ 	nop
/*  f146a8c:	11c00002 */ 	beqz	$t6,.PB0f146a98
/*  f146a90:	24130014 */ 	li	$s3,0x14
/*  f146a94:	24130028 */ 	li	$s3,0x28
.PB0f146a98:
/*  f146a98:	13000004 */ 	beqz	$t8,.PB0f146aac
/*  f146a9c:	02a01825 */ 	move	$v1,$s5
/*  f146aa0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146aa4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146aa8:	03209825 */ 	move	$s3,$t9
.PB0f146aac:
/*  f146aac:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146ab0:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146ab4:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f146ab8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146abc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146ac0:	10000027 */ 	b	.PB0f146b60
/*  f146ac4:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146ac8:
/*  f146ac8:	14610013 */ 	bne	$v1,$at,.PB0f146b18
/*  f146acc:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f146ad0:	30d90404 */ 	andi	$t9,$a2,0x404
/*  f146ad4:	13200002 */ 	beqz	$t9,.PB0f146ae0
/*  f146ad8:	2413007f */ 	li	$s3,0x7f
/*  f146adc:	241300be */ 	li	$s3,0xbe
.PB0f146ae0:
/*  f146ae0:	30ef0404 */ 	andi	$t7,$a3,0x404
/*  f146ae4:	11e00004 */ 	beqz	$t7,.PB0f146af8
/*  f146ae8:	02a01825 */ 	move	$v1,$s5
/*  f146aec:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f146af0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146af4:	01c09825 */ 	move	$s3,$t6
.PB0f146af8:
/*  f146af8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146afc:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f146b00:	032b7825 */ 	or	$t7,$t9,$t3
/*  f146b04:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146b08:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146b0c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b10:	10000013 */ 	b	.PB0f146b60
/*  f146b14:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146b18:
/*  f146b18:	13000002 */ 	beqz	$t8,.PB0f146b24
/*  f146b1c:	24130014 */ 	li	$s3,0x14
/*  f146b20:	24130028 */ 	li	$s3,0x28
.PB0f146b24:
/*  f146b24:	30f90404 */ 	andi	$t9,$a3,0x404
/*  f146b28:	13200004 */ 	beqz	$t9,.PB0f146b3c
/*  f146b2c:	02a01825 */ 	move	$v1,$s5
/*  f146b30:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146b34:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146b38:	01e09825 */ 	move	$s3,$t7
.PB0f146b3c:
/*  f146b3c:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146b40:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f146b44:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146b48:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146b4c:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146b50:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146b54:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146b58:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b5c:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146b60:
/*  f146b60:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f146b64:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146b68:	3c01f600 */ 	lui	$at,0xf600
/*  f146b6c:	01c1c825 */ 	or	$t9,$t6,$at
/*  f146b70:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f146b74:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146b78:	032c7825 */ 	or	$t7,$t9,$t4
/*  f146b7c:	02a02025 */ 	move	$a0,$s5
/*  f146b80:	01cdc825 */ 	or	$t9,$t6,$t5
/*  f146b84:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146b88:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146b8c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146b90:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b94:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146b98:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f146b9c:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146ba0:	30f90202 */ 	andi	$t9,$a3,0x202
/*  f146ba4:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f146ba8:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f146bac:	24010001 */ 	li	$at,0x1
/*  f146bb0:	14600010 */ 	bnez	$v1,.PB0f146bf4
/*  f146bb4:	00000000 */ 	nop
/*  f146bb8:	11c00002 */ 	beqz	$t6,.PB0f146bc4
/*  f146bbc:	24130014 */ 	li	$s3,0x14
/*  f146bc0:	24130028 */ 	li	$s3,0x28
.PB0f146bc4:
/*  f146bc4:	13200004 */ 	beqz	$t9,.PB0f146bd8
/*  f146bc8:	02a01825 */ 	move	$v1,$s5
/*  f146bcc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146bd0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146bd4:	01e09825 */ 	move	$s3,$t7
.PB0f146bd8:
/*  f146bd8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146bdc:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146be0:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f146be4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146be8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146bec:	10000027 */ 	b	.PB0f146c8c
/*  f146bf0:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146bf4:
/*  f146bf4:	14610013 */ 	bne	$v1,$at,.PB0f146c44
/*  f146bf8:	30d90202 */ 	andi	$t9,$a2,0x202
/*  f146bfc:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f146c00:	11e00002 */ 	beqz	$t7,.PB0f146c0c
/*  f146c04:	2413007f */ 	li	$s3,0x7f
/*  f146c08:	241300be */ 	li	$s3,0xbe
.PB0f146c0c:
/*  f146c0c:	30f80202 */ 	andi	$t8,$a3,0x202
/*  f146c10:	13000004 */ 	beqz	$t8,.PB0f146c24
/*  f146c14:	02a01825 */ 	move	$v1,$s5
/*  f146c18:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f146c1c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146c20:	01c09825 */ 	move	$s3,$t6
.PB0f146c24:
/*  f146c24:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146c28:	00197a00 */ 	sll	$t7,$t9,0x8
/*  f146c2c:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f146c30:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146c34:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146c38:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c3c:	10000013 */ 	b	.PB0f146c8c
/*  f146c40:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146c44:
/*  f146c44:	13200002 */ 	beqz	$t9,.PB0f146c50
/*  f146c48:	24130014 */ 	li	$s3,0x14
/*  f146c4c:	24130028 */ 	li	$s3,0x28
.PB0f146c50:
/*  f146c50:	30ef0202 */ 	andi	$t7,$a3,0x202
/*  f146c54:	11e00004 */ 	beqz	$t7,.PB0f146c68
/*  f146c58:	02a01825 */ 	move	$v1,$s5
/*  f146c5c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146c60:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146c64:	03009825 */ 	move	$s3,$t8
.PB0f146c68:
/*  f146c68:	00137883 */ 	sra	$t7,$s3,0x2
/*  f146c6c:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f146c70:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146c74:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f146c78:	032e7825 */ 	or	$t7,$t9,$t6
/*  f146c7c:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f146c80:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146c84:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c88:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146c8c:
/*  f146c8c:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f146c90:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146c94:	3c01f600 */ 	lui	$at,0xf600
/*  f146c98:	01c17825 */ 	or	$t7,$t6,$at
/*  f146c9c:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f146ca0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146ca4:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f146ca8:	02a02025 */ 	move	$a0,$s5
/*  f146cac:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f146cb0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146cb4:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f146cb8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146cbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146cc0:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146cc4:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f146cc8:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146ccc:	30ef0101 */ 	andi	$t7,$a3,0x101
/*  f146cd0:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146cd4:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f146cd8:	24010001 */ 	li	$at,0x1
/*  f146cdc:	14600010 */ 	bnez	$v1,.PB0f146d20
/*  f146ce0:	00000000 */ 	nop
/*  f146ce4:	11c00002 */ 	beqz	$t6,.PB0f146cf0
/*  f146ce8:	24130014 */ 	li	$s3,0x14
/*  f146cec:	24130028 */ 	li	$s3,0x28
.PB0f146cf0:
/*  f146cf0:	11e00004 */ 	beqz	$t7,.PB0f146d04
/*  f146cf4:	02a01825 */ 	move	$v1,$s5
/*  f146cf8:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146cfc:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146d00:	03009825 */ 	move	$s3,$t8
.PB0f146d04:
/*  f146d04:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146d08:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146d0c:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f146d10:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146d14:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146d18:	10000027 */ 	b	.PB0f146db8
/*  f146d1c:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146d20:
/*  f146d20:	14610013 */ 	bne	$v1,$at,.PB0f146d70
/*  f146d24:	30cf0101 */ 	andi	$t7,$a2,0x101
/*  f146d28:	30d80101 */ 	andi	$t8,$a2,0x101
/*  f146d2c:	13000002 */ 	beqz	$t8,.PB0f146d38
/*  f146d30:	2413007f */ 	li	$s3,0x7f
/*  f146d34:	241300be */ 	li	$s3,0xbe
.PB0f146d38:
/*  f146d38:	30f90101 */ 	andi	$t9,$a3,0x101
/*  f146d3c:	13200004 */ 	beqz	$t9,.PB0f146d50
/*  f146d40:	02a01825 */ 	move	$v1,$s5
/*  f146d44:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f146d48:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146d4c:	01c09825 */ 	move	$s3,$t6
.PB0f146d50:
/*  f146d50:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146d54:	000fc200 */ 	sll	$t8,$t7,0x8
/*  f146d58:	030bc825 */ 	or	$t9,$t8,$t3
/*  f146d5c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f146d60:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146d64:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146d68:	10000013 */ 	b	.PB0f146db8
/*  f146d6c:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146d70:
/*  f146d70:	11e00002 */ 	beqz	$t7,.PB0f146d7c
/*  f146d74:	24130014 */ 	li	$s3,0x14
/*  f146d78:	24130028 */ 	li	$s3,0x28
.PB0f146d7c:
/*  f146d7c:	30f80101 */ 	andi	$t8,$a3,0x101
/*  f146d80:	13000004 */ 	beqz	$t8,.PB0f146d94
/*  f146d84:	02a01825 */ 	move	$v1,$s5
/*  f146d88:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146d8c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146d90:	03209825 */ 	move	$s3,$t9
.PB0f146d94:
/*  f146d94:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146d98:	331900ff */ 	andi	$t9,$t8,0xff
/*  f146d9c:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146da0:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146da4:	01eec025 */ 	or	$t8,$t7,$t6
/*  f146da8:	371900ff */ 	ori	$t9,$t8,0xff
/*  f146dac:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146db0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146db4:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146db8:
/*  f146db8:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f146dbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146dc0:	3c01f600 */ 	lui	$at,0xf600
/*  f146dc4:	01c1c025 */ 	or	$t8,$t6,$at
/*  f146dc8:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f146dcc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146dd0:	030cc825 */ 	or	$t9,$t8,$t4
/*  f146dd4:	02a02025 */ 	move	$a0,$s5
/*  f146dd8:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f146ddc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146de0:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146de4:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146de8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146dec:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146df0:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146df4:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146df8:	30f80030 */ 	andi	$t8,$a3,0x30
/*  f146dfc:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146e00:	30ce0030 */ 	andi	$t6,$a2,0x30
/*  f146e04:	24010001 */ 	li	$at,0x1
/*  f146e08:	14600010 */ 	bnez	$v1,.PB0f146e4c
/*  f146e0c:	00000000 */ 	nop
/*  f146e10:	11c00002 */ 	beqz	$t6,.PB0f146e1c
/*  f146e14:	24130014 */ 	li	$s3,0x14
/*  f146e18:	24130028 */ 	li	$s3,0x28
.PB0f146e1c:
/*  f146e1c:	13000004 */ 	beqz	$t8,.PB0f146e30
/*  f146e20:	02a01825 */ 	move	$v1,$s5
/*  f146e24:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146e28:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146e2c:	03209825 */ 	move	$s3,$t9
.PB0f146e30:
/*  f146e30:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146e34:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146e38:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f146e3c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146e40:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146e44:	10000027 */ 	b	.PB0f146ee4
/*  f146e48:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146e4c:
/*  f146e4c:	14610013 */ 	bne	$v1,$at,.PB0f146e9c
/*  f146e50:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f146e54:	30d90030 */ 	andi	$t9,$a2,0x30
/*  f146e58:	13200002 */ 	beqz	$t9,.PB0f146e64
/*  f146e5c:	2413007f */ 	li	$s3,0x7f
/*  f146e60:	241300be */ 	li	$s3,0xbe
.PB0f146e64:
/*  f146e64:	30ef0030 */ 	andi	$t7,$a3,0x30
/*  f146e68:	11e00004 */ 	beqz	$t7,.PB0f146e7c
/*  f146e6c:	02a01825 */ 	move	$v1,$s5
/*  f146e70:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f146e74:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146e78:	01c09825 */ 	move	$s3,$t6
.PB0f146e7c:
/*  f146e7c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146e80:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f146e84:	032b7825 */ 	or	$t7,$t9,$t3
/*  f146e88:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146e8c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146e90:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146e94:	10000013 */ 	b	.PB0f146ee4
/*  f146e98:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146e9c:
/*  f146e9c:	13000002 */ 	beqz	$t8,.PB0f146ea8
/*  f146ea0:	24130014 */ 	li	$s3,0x14
/*  f146ea4:	24130028 */ 	li	$s3,0x28
.PB0f146ea8:
/*  f146ea8:	30f90030 */ 	andi	$t9,$a3,0x30
/*  f146eac:	13200004 */ 	beqz	$t9,.PB0f146ec0
/*  f146eb0:	02a01825 */ 	move	$v1,$s5
/*  f146eb4:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146eb8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146ebc:	01e09825 */ 	move	$s3,$t7
.PB0f146ec0:
/*  f146ec0:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146ec4:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f146ec8:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146ecc:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146ed0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146ed4:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146ed8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146edc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146ee0:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146ee4:
/*  f146ee4:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f146ee8:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146eec:	3c01f600 */ 	lui	$at,0xf600
/*  f146ef0:	01c1c825 */ 	or	$t9,$t6,$at
/*  f146ef4:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f146ef8:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146efc:	032c7825 */ 	or	$t7,$t9,$t4
/*  f146f00:	02a02025 */ 	move	$a0,$s5
/*  f146f04:	01cdc825 */ 	or	$t9,$t6,$t5
/*  f146f08:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146f0c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146f10:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146f14:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146f18:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146f1c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f146f20:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146f24:	30f92000 */ 	andi	$t9,$a3,0x2000
/*  f146f28:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f146f2c:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f146f30:	24010001 */ 	li	$at,0x1
/*  f146f34:	14600010 */ 	bnez	$v1,.PB0f146f78
/*  f146f38:	00000000 */ 	nop
/*  f146f3c:	11c00002 */ 	beqz	$t6,.PB0f146f48
/*  f146f40:	24130014 */ 	li	$s3,0x14
/*  f146f44:	24130028 */ 	li	$s3,0x28
.PB0f146f48:
/*  f146f48:	13200004 */ 	beqz	$t9,.PB0f146f5c
/*  f146f4c:	02a01825 */ 	move	$v1,$s5
/*  f146f50:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146f54:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f146f58:	01e09825 */ 	move	$s3,$t7
.PB0f146f5c:
/*  f146f5c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146f60:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146f64:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f146f68:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146f6c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146f70:	10000027 */ 	b	.PB0f147010
/*  f146f74:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146f78:
/*  f146f78:	14610013 */ 	bne	$v1,$at,.PB0f146fc8
/*  f146f7c:	30d92000 */ 	andi	$t9,$a2,0x2000
/*  f146f80:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f146f84:	11e00002 */ 	beqz	$t7,.PB0f146f90
/*  f146f88:	2413007f */ 	li	$s3,0x7f
/*  f146f8c:	241300be */ 	li	$s3,0xbe
.PB0f146f90:
/*  f146f90:	30f82000 */ 	andi	$t8,$a3,0x2000
/*  f146f94:	13000004 */ 	beqz	$t8,.PB0f146fa8
/*  f146f98:	02a01825 */ 	move	$v1,$s5
/*  f146f9c:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f146fa0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146fa4:	01c09825 */ 	move	$s3,$t6
.PB0f146fa8:
/*  f146fa8:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146fac:	00197a00 */ 	sll	$t7,$t9,0x8
/*  f146fb0:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f146fb4:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146fb8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146fbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146fc0:	10000013 */ 	b	.PB0f147010
/*  f146fc4:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f146fc8:
/*  f146fc8:	13200002 */ 	beqz	$t9,.PB0f146fd4
/*  f146fcc:	24130014 */ 	li	$s3,0x14
/*  f146fd0:	24130028 */ 	li	$s3,0x28
.PB0f146fd4:
/*  f146fd4:	30ef2000 */ 	andi	$t7,$a3,0x2000
/*  f146fd8:	11e00004 */ 	beqz	$t7,.PB0f146fec
/*  f146fdc:	02a01825 */ 	move	$v1,$s5
/*  f146fe0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f146fe4:	327800ff */ 	andi	$t8,$s3,0xff
/*  f146fe8:	03009825 */ 	move	$s3,$t8
.PB0f146fec:
/*  f146fec:	00137883 */ 	sra	$t7,$s3,0x2
/*  f146ff0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f146ff4:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146ff8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f146ffc:	032e7825 */ 	or	$t7,$t9,$t6
/*  f147000:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f147004:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f147008:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14700c:	ac690000 */ 	sw	$t1,0x0($v1)
.PB0f147010:
/*  f147010:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f147014:	00197380 */ 	sll	$t6,$t9,0xe
/*  f147018:	3c01f600 */ 	lui	$at,0xf600
/*  f14701c:	01c17825 */ 	or	$t7,$t6,$at
/*  f147020:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f147024:	02a01825 */ 	move	$v1,$s5
/*  f147028:	00197380 */ 	sll	$t6,$t9,0xe
/*  f14702c:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f147030:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f147034:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147038:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f14703c:	26b50008 */ 	addiu	$s5,$s5,0x8
.PB0f147040:
/*  f147040:	3c0142a0 */ 	lui	$at,0x42a0
/*  f147044:	44817000 */ 	mtc1	$at,$f14
/*  f147048:	3c0142c0 */ 	lui	$at,0x42c0
/*  f14704c:	44818000 */ 	mtc1	$at,$f16
/*  f147050:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f147054:	3c0b1020 */ 	lui	$t3,0x1020
/*  f147058:	46106102 */ 	mul.s	$f4,$f12,$f16
/*  f14705c:	2405ffc9 */ 	li	$a1,-55
/*  f147060:	24010001 */ 	li	$at,0x1
/*  f147064:	00022600 */ 	sll	$a0,$v0,0x18
/*  f147068:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f14706c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147070:	44035000 */ 	mfc1	$v1,$f10
/*  f147074:	00000000 */ 	nop
/*  f147078:	04610005 */ 	bgez	$v1,.PB0f147090
/*  f14707c:	307300ff */ 	andi	$s3,$v1,0xff
/*  f147080:	00039823 */ 	negu	$s3,$v1
/*  f147084:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147088:	10000001 */ 	b	.PB0f147090
/*  f14708c:	03209825 */ 	move	$s3,$t9
.PB0f147090:
/*  f147090:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f147094:	327800ff */ 	andi	$t8,$s3,0xff
/*  f147098:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f14709c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f1470a0:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f1470a4:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f1470a8:	14600006 */ 	bnez	$v1,.PB0f1470c4
/*  f1470ac:	00000000 */ 	nop
/*  f1470b0:	02a01825 */ 	move	$v1,$s5
/*  f1470b4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1470b8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1470bc:	10000031 */ 	b	.PB0f147184
/*  f1470c0:	26b50008 */ 	addiu	$s5,$s5,0x8
.PB0f1470c4:
/*  f1470c4:	14610026 */ 	bne	$v1,$at,.PB0f147160
/*  f1470c8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f1470cc:	44934000 */ 	mtc1	$s3,$f8
/*  f1470d0:	02a01825 */ 	move	$v1,$s5
/*  f1470d4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1470d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1470dc:	06610005 */ 	bgez	$s3,.PB0f1470f4
/*  f1470e0:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f1470e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1470e8:	44812000 */ 	mtc1	$at,$f4
/*  f1470ec:	00000000 */ 	nop
/*  f1470f0:	46040000 */ 	add.s	$f0,$f0,$f4
.PB0f1470f4:
/*  f1470f4:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f1470f8:	3c014180 */ 	lui	$at,0x4180
/*  f1470fc:	44813000 */ 	mtc1	$at,$f6
/*  f147100:	3c014200 */ 	lui	$at,0x4200
/*  f147104:	44812000 */ 	mtc1	$at,$f4
/*  f147108:	3c014020 */ 	lui	$at,0x4020
/*  f14710c:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f147110:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f147114:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f147118:	44194000 */ 	mfc1	$t9,$f8
/*  f14711c:	44814000 */ 	mtc1	$at,$f8
/*  f147120:	00197600 */ 	sll	$t6,$t9,0x18
/*  f147124:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f147128:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f14712c:	44185000 */ 	mfc1	$t8,$f10
/*  f147130:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147134:	331900ff */ 	andi	$t9,$t8,0xff
/*  f147138:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f14713c:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f147140:	440e3000 */ 	mfc1	$t6,$f6
/*  f147144:	00000000 */ 	nop
/*  f147148:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f14714c:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f147150:	03197025 */ 	or	$t6,$t8,$t9
/*  f147154:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f147158:	1000000a */ 	b	.PB0f147184
/*  f14715c:	ac6f0004 */ 	sw	$t7,0x4($v1)
.PB0f147160:
/*  f147160:	00137083 */ 	sra	$t6,$s3,0x2
/*  f147164:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f147168:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f14716c:	02a01825 */ 	move	$v1,$s5
/*  f147170:	03387025 */ 	or	$t6,$t9,$t8
/*  f147174:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f147178:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14717c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147180:	26b50008 */ 	addiu	$s5,$s5,0x8
.PB0f147184:
/*  f147184:	8fb902a4 */ 	lw	$t9,0x2a4($sp)
/*  f147188:	57200044 */ 	bnezl	$t9,.PB0f14729c
/*  f14718c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f147190:	1a800022 */ 	blez	$s4,.PB0f14721c
/*  f147194:	3c0141e0 */ 	lui	$at,0x41e0
/*  f147198:	3c0141e0 */ 	lui	$at,0x41e0
/*  f14719c:	44819000 */ 	mtc1	$at,$f18
/*  f1471a0:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f1471a4:	3c01f600 */ 	lui	$at,0xf600
/*  f1471a8:	46126282 */ 	mul.s	$f10,$f12,$f18
/*  f1471ac:	02a01825 */ 	move	$v1,$s5
/*  f1471b0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1471b4:	460e5203 */ 	div.s	$f8,$f10,$f14
/*  f1471b8:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1471bc:	440e2000 */ 	mfc1	$t6,$f4
/*  f1471c0:	00000000 */ 	nop
/*  f1471c4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1471c8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f1471cc:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1471d0:	8fb802fc */ 	lw	$t8,0x2fc($sp)
/*  f1471d4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1471d8:	01e1c825 */ 	or	$t9,$t7,$at
/*  f1471dc:	270e0015 */ 	addiu	$t6,$t8,0x15
/*  f1471e0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1471e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1471e8:	03387025 */ 	or	$t6,$t9,$t8
/*  f1471ec:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1471f0:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1471f4:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f1471f8:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f1471fc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147200:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147204:	25f90013 */ 	addiu	$t9,$t7,0x13
/*  f147208:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f14720c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147210:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147214:	10000020 */ 	b	.PB0f147298
/*  f147218:	ac790004 */ 	sw	$t9,0x4($v1)
.PB0f14721c:
/*  f14721c:	44819000 */ 	mtc1	$at,$f18
/*  f147220:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f147224:	3c01f600 */ 	lui	$at,0xf600
/*  f147228:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f14722c:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f147230:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147234:	8fae02fc */ 	lw	$t6,0x2fc($sp)
/*  f147238:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f14723c:	0321c025 */ 	or	$t8,$t9,$at
/*  f147240:	25cf0015 */ 	addiu	$t7,$t6,0x15
/*  f147244:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f147248:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14724c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f147250:	030e7825 */ 	or	$t7,$t8,$t6
/*  f147254:	02a01825 */ 	move	$v1,$s5
/*  f147258:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f14725c:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f147260:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147264:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f147268:	44184000 */ 	mfc1	$t8,$f8
/*  f14726c:	00000000 */ 	nop
/*  f147270:	03057021 */ 	addu	$t6,$t8,$a1
/*  f147274:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f147278:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f14727c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147280:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147284:	25f90013 */ 	addiu	$t9,$t7,0x13
/*  f147288:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f14728c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147290:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147294:	ac790004 */ 	sw	$t9,0x4($v1)
.PB0f147298:
/*  f147298:	0004c603 */ 	sra	$t8,$a0,0x18
.PB0f14729c:
/*  f14729c:	03002025 */ 	move	$a0,$t8
/*  f1472a0:	44842000 */ 	mtc1	$a0,$f4
/*  f1472a4:	3c0141e0 */ 	lui	$at,0x41e0
/*  f1472a8:	44819000 */ 	mtc1	$at,$f18
/*  f1472ac:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f1472b0:	02a01025 */ 	move	$v0,$s5
/*  f1472b4:	24010001 */ 	li	$at,0x1
/*  f1472b8:	46106182 */ 	mul.s	$f6,$f12,$f16
/*  f1472bc:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f1472c0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1472c4:	44034000 */ 	mfc1	$v1,$f8
/*  f1472c8:	00000000 */ 	nop
/*  f1472cc:	04610005 */ 	bgez	$v1,.PB0f1472e4
/*  f1472d0:	307300ff */ 	andi	$s3,$v1,0xff
/*  f1472d4:	00039823 */ 	negu	$s3,$v1
/*  f1472d8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1472dc:	10000001 */ 	b	.PB0f1472e4
/*  f1472e0:	01e09825 */ 	move	$s3,$t7
.PB0f1472e4:
/*  f1472e4:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1472e8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1472ec:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f1472f0:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f1472f4:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f1472f8:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1472fc:	14600005 */ 	bnez	$v1,.PB0f147314
/*  f147300:	00000000 */ 	nop
/*  f147304:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147308:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f14730c:	10000031 */ 	b	.PB0f1473d4
/*  f147310:	ac590004 */ 	sw	$t9,0x4($v0)
.PB0f147314:
/*  f147314:	14610026 */ 	bne	$v1,$at,.PB0f1473b0
/*  f147318:	02a01025 */ 	move	$v0,$s5
/*  f14731c:	44932000 */ 	mtc1	$s3,$f4
/*  f147320:	02a01025 */ 	move	$v0,$s5
/*  f147324:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f147328:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14732c:	06610005 */ 	bgez	$s3,.PB0f147344
/*  f147330:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f147334:	3c014f80 */ 	lui	$at,0x4f80
/*  f147338:	44813000 */ 	mtc1	$at,$f6
/*  f14733c:	00000000 */ 	nop
/*  f147340:	46060000 */ 	add.s	$f0,$f0,$f6
.PB0f147344:
/*  f147344:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f147348:	3c014180 */ 	lui	$at,0x4180
/*  f14734c:	44815000 */ 	mtc1	$at,$f10
/*  f147350:	3c014200 */ 	lui	$at,0x4200
/*  f147354:	44813000 */ 	mtc1	$at,$f6
/*  f147358:	3c014020 */ 	lui	$at,0x4020
/*  f14735c:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f147360:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147364:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f147368:	440f2000 */ 	mfc1	$t7,$f4
/*  f14736c:	44812000 */ 	mtc1	$at,$f4
/*  f147370:	000fce00 */ 	sll	$t9,$t7,0x18
/*  f147374:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f147378:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f14737c:	440e4000 */ 	mfc1	$t6,$f8
/*  f147380:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147384:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f147388:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f14738c:	03387025 */ 	or	$t6,$t9,$t8
/*  f147390:	44195000 */ 	mfc1	$t9,$f10
/*  f147394:	00000000 */ 	nop
/*  f147398:	333800ff */ 	andi	$t8,$t9,0xff
/*  f14739c:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f1473a0:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1473a4:	373800ff */ 	ori	$t8,$t9,0xff
/*  f1473a8:	1000000a */ 	b	.PB0f1473d4
/*  f1473ac:	ac580004 */ 	sw	$t8,0x4($v0)
.PB0f1473b0:
/*  f1473b0:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f1473b4:	333800ff */ 	andi	$t8,$t9,0xff
/*  f1473b8:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1473bc:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f1473c0:	01eec825 */ 	or	$t9,$t7,$t6
/*  f1473c4:	373800ff */ 	ori	$t8,$t9,0xff
/*  f1473c8:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1473cc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1473d0:	ac490000 */ 	sw	$t1,0x0($v0)
.PB0f1473d4:
/*  f1473d4:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f1473d8:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f1473dc:	15e00038 */ 	bnez	$t7,.PB0f1474c0
/*  f1473e0:	00ae1821 */ 	addu	$v1,$a1,$t6
/*  f1473e4:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f1473e8:	1880001b */ 	blez	$a0,.PB0f147458
/*  f1473ec:	00191b80 */ 	sll	$v1,$t9,0xe
/*  f1473f0:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f1473f4:	3c01f600 */ 	lui	$at,0xf600
/*  f1473f8:	02a01025 */ 	move	$v0,$s5
/*  f1473fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147400:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f147404:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147408:	44193000 */ 	mfc1	$t9,$f6
/*  f14740c:	00000000 */ 	nop
/*  f147410:	0325c021 */ 	addu	$t8,$t9,$a1
/*  f147414:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f147418:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f14741c:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f147420:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f147424:	03017025 */ 	or	$t6,$t8,$at
/*  f147428:	25f90018 */ 	addiu	$t9,$t7,0x18
/*  f14742c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147430:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147434:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147438:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f14743c:	8fb802fc */ 	lw	$t8,0x2fc($sp)
/*  f147440:	270e0016 */ 	addiu	$t6,$t8,0x16
/*  f147444:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147448:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f14744c:	0079c025 */ 	or	$t8,$v1,$t9
/*  f147450:	1000001b */ 	b	.PB0f1474c0
/*  f147454:	ac580004 */ 	sw	$t8,0x4($v0)
.PB0f147458:
/*  f147458:	46126282 */ 	mul.s	$f10,$f12,$f18
/*  f14745c:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f147460:	3c01f600 */ 	lui	$at,0xf600
/*  f147464:	00617025 */ 	or	$t6,$v1,$at
/*  f147468:	25f90018 */ 	addiu	$t9,$t7,0x18
/*  f14746c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147470:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147474:	460e5203 */ 	div.s	$f8,$f10,$f14
/*  f147478:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f14747c:	02a01025 */ 	move	$v0,$s5
/*  f147480:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f147484:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f147488:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14748c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147490:	440e2000 */ 	mfc1	$t6,$f4
/*  f147494:	00000000 */ 	nop
/*  f147498:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f14749c:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f1474a0:	8fb902fc */ 	lw	$t9,0x2fc($sp)
/*  f1474a4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1474a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1474ac:	27380016 */ 	addiu	$t8,$t9,0x16
/*  f1474b0:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1474b4:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1474b8:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f1474bc:	ac580004 */ 	sw	$t8,0x4($v0)
.PB0f1474c0:
/*  f1474c0:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f1474c4:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f1474c8:	24010002 */ 	li	$at,0x2
/*  f1474cc:	8c8e0480 */ 	lw	$t6,0x480($a0)
/*  f1474d0:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f1474d4:	14600152 */ 	bnez	$v1,.PB0f147a20
/*  f1474d8:	00000000 */ 	nop
/*  f1474dc:	15e002f8 */ 	bnez	$t7,.PB0f1480c0
/*  f1474e0:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f1474e4:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1474e8:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1474ec:	3c01420c */ 	lui	$at,0x420c
/*  f1474f0:	44816000 */ 	mtc1	$at,$f12
/*  f1474f4:	44185000 */ 	mfc1	$t8,$f10
/*  f1474f8:	25cffff3 */ 	addiu	$t7,$t6,-13
/*  f1474fc:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f147500:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147504:	8c990480 */ 	lw	$t9,0x480($a0)
/*  f147508:	3c0143b4 */ 	lui	$at,0x43b4
/*  f14750c:	44817000 */ 	mtc1	$at,$f14
/*  f147510:	c720001c */ 	lwc1	$f0,0x1c($t9)
/*  f147514:	3c05f600 */ 	lui	$a1,0xf600
/*  f147518:	02a01825 */ 	move	$v1,$s5
/*  f14751c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f147520:	00000000 */ 	nop
/*  f147524:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f147528:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f14752c:	460e5203 */ 	div.s	$f8,$f10,$f14
/*  f147530:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147534:	44023000 */ 	mfc1	$v0,$f6
/*  f147538:	00000000 */ 	nop
/*  f14753c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147540:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147544:	440f2000 */ 	mfc1	$t7,$f4
/*  f147548:	04410005 */ 	bgez	$v0,.PB0f147560
/*  f14754c:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147550:	00029823 */ 	negu	$s3,$v0
/*  f147554:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147558:	10000001 */ 	b	.PB0f147560
/*  f14755c:	03209825 */ 	move	$s3,$t9
.PB0f147560:
/*  f147560:	327800ff */ 	andi	$t8,$s3,0xff
/*  f147564:	00187400 */ 	sll	$t6,$t8,0x10
/*  f147568:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f14756c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147570:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147574:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147578:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14757c:	02a02025 */ 	move	$a0,$s5
/*  f147580:	27380005 */ 	addiu	$t8,$t9,0x5
/*  f147584:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147588:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14758c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f147590:	01e5c825 */ 	or	$t9,$t7,$a1
/*  f147594:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147598:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14759c:	032fc025 */ 	or	$t8,$t9,$t7
/*  f1475a0:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1475a4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1475a8:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1475ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f1475b0:	44811000 */ 	mtc1	$at,$f2
/*  f1475b4:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f1475b8:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1475bc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1475c0:	00187080 */ 	sll	$t6,$t8,0x2
/*  f1475c4:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f1475c8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1475cc:	030ec825 */ 	or	$t9,$t8,$t6
/*  f1475d0:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1475d4:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f1475d8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1475dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1475e0:	25f80007 */ 	addiu	$t8,$t7,0x7
/*  f1475e4:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f1475e8:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f1475ec:	44819000 */ 	mtc1	$at,$f18
/*  f1475f0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1475f4:	c7260020 */ 	lwc1	$f6,0x20($t9)
/*  f1475f8:	02a01825 */ 	move	$v1,$s5
/*  f1475fc:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f147600:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f147604:	00000000 */ 	nop
/*  f147608:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f14760c:	00000000 */ 	nop
/*  f147610:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f147614:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147618:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f14761c:	44022000 */ 	mfc1	$v0,$f4
/*  f147620:	00000000 */ 	nop
/*  f147624:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147628:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f14762c:	440e4000 */ 	mfc1	$t6,$f8
/*  f147630:	04410005 */ 	bgez	$v0,.PB0f147648
/*  f147634:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f147638:	00029823 */ 	negu	$s3,$v0
/*  f14763c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147640:	10000001 */ 	b	.PB0f147648
/*  f147644:	03209825 */ 	move	$s3,$t9
.PB0f147648:
/*  f147648:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14764c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f147650:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f147654:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f147658:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14765c:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147660:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147664:	02a02025 */ 	move	$a0,$s5
/*  f147668:	272f0005 */ 	addiu	$t7,$t9,0x5
/*  f14766c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147670:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147674:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147678:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f14767c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147680:	00187080 */ 	sll	$t6,$t8,0x2
/*  f147684:	032e7825 */ 	or	$t7,$t9,$t6
/*  f147688:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14768c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147690:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f147694:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147698:	02a01825 */ 	move	$v1,$s5
/*  f14769c:	03197023 */ 	subu	$t6,$t8,$t9
/*  f1476a0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1476a4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1476a8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1476ac:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1476b0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1476b4:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f1476b8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1476bc:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1476c0:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1476c4:	25cf0007 */ 	addiu	$t7,$t6,0x7
/*  f1476c8:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1476cc:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1476d0:	c7240024 */ 	lwc1	$f4,0x24($t9)
/*  f1476d4:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1476d8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f1476dc:	00000000 */ 	nop
/*  f1476e0:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f1476e4:	00000000 */ 	nop
/*  f1476e8:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f1476ec:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1476f0:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f1476f4:	44024000 */ 	mfc1	$v0,$f8
/*  f1476f8:	00000000 */ 	nop
/*  f1476fc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147700:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147704:	44185000 */ 	mfc1	$t8,$f10
/*  f147708:	04410005 */ 	bgez	$v0,.PB0f147720
/*  f14770c:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f147710:	00029823 */ 	negu	$s3,$v0
/*  f147714:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147718:	10000001 */ 	b	.PB0f147720
/*  f14771c:	03209825 */ 	move	$s3,$t9
.PB0f147720:
/*  f147720:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f147724:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f147728:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f14772c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f147730:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147734:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147738:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14773c:	02a02025 */ 	move	$a0,$s5
/*  f147740:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f147744:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147748:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14774c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f147750:	0305c825 */ 	or	$t9,$t8,$a1
/*  f147754:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147758:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f14775c:	03387025 */ 	or	$t6,$t9,$t8
/*  f147760:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f147764:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147768:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14776c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147770:	02a01825 */ 	move	$v1,$s5
/*  f147774:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f147778:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14777c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147780:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f147784:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147788:	00187380 */ 	sll	$t6,$t8,0xe
/*  f14778c:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147790:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147794:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147798:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14779c:	270e0007 */ 	addiu	$t6,$t8,0x7
/*  f1477a0:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f1477a4:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f1477a8:	c7200028 */ 	lwc1	$f0,0x28($t9)
/*  f1477ac:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1477b0:	00000000 */ 	nop
/*  f1477b4:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f1477b8:	460e4103 */ 	div.s	$f4,$f8,$f14
/*  f1477bc:	460e5203 */ 	div.s	$f8,$f10,$f14
/*  f1477c0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1477c4:	44023000 */ 	mfc1	$v0,$f6
/*  f1477c8:	00000000 */ 	nop
/*  f1477cc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1477d0:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1477d4:	440f2000 */ 	mfc1	$t7,$f4
/*  f1477d8:	04410005 */ 	bgez	$v0,.PB0f1477f0
/*  f1477dc:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f1477e0:	00029823 */ 	negu	$s3,$v0
/*  f1477e4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1477e8:	10000001 */ 	b	.PB0f1477f0
/*  f1477ec:	03209825 */ 	move	$s3,$t9
.PB0f1477f0:
/*  f1477f0:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1477f4:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1477f8:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f1477fc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147800:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147804:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147808:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14780c:	02a02025 */ 	move	$a0,$s5
/*  f147810:	27380005 */ 	addiu	$t8,$t9,0x5
/*  f147814:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147818:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14781c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f147820:	01e5c825 */ 	or	$t9,$t7,$a1
/*  f147824:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147828:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14782c:	032fc025 */ 	or	$t8,$t9,$t7
/*  f147830:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f147834:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147838:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14783c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147840:	02a01825 */ 	move	$v1,$s5
/*  f147844:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f147848:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14784c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147850:	00187080 */ 	sll	$t6,$t8,0x2
/*  f147854:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147858:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f14785c:	030ec825 */ 	or	$t9,$t8,$t6
/*  f147860:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147864:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f147868:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f14786c:	25f80007 */ 	addiu	$t8,$t7,0x7
/*  f147870:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147874:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f147878:	c726002c */ 	lwc1	$f6,0x2c($t9)
/*  f14787c:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f147880:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f147884:	00000000 */ 	nop
/*  f147888:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f14788c:	00000000 */ 	nop
/*  f147890:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f147894:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147898:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f14789c:	44022000 */ 	mfc1	$v0,$f4
/*  f1478a0:	00000000 */ 	nop
/*  f1478a4:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1478a8:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1478ac:	440e4000 */ 	mfc1	$t6,$f8
/*  f1478b0:	04410005 */ 	bgez	$v0,.PB0f1478c8
/*  f1478b4:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f1478b8:	00029823 */ 	negu	$s3,$v0
/*  f1478bc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1478c0:	10000001 */ 	b	.PB0f1478c8
/*  f1478c4:	03209825 */ 	move	$s3,$t9
.PB0f1478c8:
/*  f1478c8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1478cc:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f1478d0:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f1478d4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1478d8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1478dc:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1478e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1478e4:	02a02025 */ 	move	$a0,$s5
/*  f1478e8:	272f0005 */ 	addiu	$t7,$t9,0x5
/*  f1478ec:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1478f0:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1478f4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1478f8:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f1478fc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147900:	00187080 */ 	sll	$t6,$t8,0x2
/*  f147904:	032e7825 */ 	or	$t7,$t9,$t6
/*  f147908:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14790c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147910:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f147914:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147918:	03197023 */ 	subu	$t6,$t8,$t9
/*  f14791c:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147920:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147924:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f147928:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f14792c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f147930:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f147934:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147938:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f14793c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147940:	25cf0007 */ 	addiu	$t7,$t6,0x7
/*  f147944:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f147948:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f14794c:	c7240030 */ 	lwc1	$f4,0x30($t9)
/*  f147950:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f147954:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f147958:	00000000 */ 	nop
/*  f14795c:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f147960:	00000000 */ 	nop
/*  f147964:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f147968:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f14796c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f147970:	44024000 */ 	mfc1	$v0,$f8
/*  f147974:	00000000 */ 	nop
/*  f147978:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14797c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147980:	44185000 */ 	mfc1	$t8,$f10
/*  f147984:	04410005 */ 	bgez	$v0,.PB0f14799c
/*  f147988:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f14798c:	00029823 */ 	negu	$s3,$v0
/*  f147990:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147994:	10000001 */ 	b	.PB0f14799c
/*  f147998:	03209825 */ 	move	$s3,$t9
.PB0f14799c:
/*  f14799c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1479a0:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f1479a4:	02a01025 */ 	move	$v0,$s5
/*  f1479a8:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1479ac:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1479b0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1479b4:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1479b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1479bc:	02a01825 */ 	move	$v1,$s5
/*  f1479c0:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f1479c4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1479c8:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1479cc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1479d0:	0305c825 */ 	or	$t9,$t8,$a1
/*  f1479d4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1479d8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1479dc:	03387025 */ 	or	$t6,$t9,$t8
/*  f1479e0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f1479e4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1479e8:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1479ec:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1479f0:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f1479f4:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1479f8:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1479fc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f147a00:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147a04:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147a08:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147a0c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f147a10:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147a14:	270e0007 */ 	addiu	$t6,$t8,0x7
/*  f147a18:	100001a9 */ 	b	.PB0f1480c0
/*  f147a1c:	afae02ec */ 	sw	$t6,0x2ec($sp)
.PB0f147a20:
/*  f147a20:	1461016a */ 	bne	$v1,$at,.PB0f147fcc
/*  f147a24:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f147a28:	8faf02a4 */ 	lw	$t7,0x2a4($sp)
/*  f147a2c:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f147a30:	02a01825 */ 	move	$v1,$s5
/*  f147a34:	55e001a3 */ 	bnezl	$t7,.PB0f1480c4
/*  f147a38:	02a01025 */ 	move	$v0,$s5
/*  f147a3c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147a40:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f147a44:	3c01420c */ 	lui	$at,0x420c
/*  f147a48:	44816000 */ 	mtc1	$at,$f12
/*  f147a4c:	44182000 */ 	mfc1	$t8,$f4
/*  f147a50:	25cffff3 */ 	addiu	$t7,$t6,-13
/*  f147a54:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f147a58:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147a5c:	8c990480 */ 	lw	$t9,0x480($a0)
/*  f147a60:	3c0143b4 */ 	lui	$at,0x43b4
/*  f147a64:	44817000 */ 	mtc1	$at,$f14
/*  f147a68:	c720001c */ 	lwc1	$f0,0x1c($t9)
/*  f147a6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f147a70:	44811000 */ 	mtc1	$at,$f2
/*  f147a74:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f147a78:	3c013f80 */ 	lui	$at,0x3f80
/*  f147a7c:	44819000 */ 	mtc1	$at,$f18
/*  f147a80:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f147a84:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147a88:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f147a8c:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f147a90:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f147a94:	44024000 */ 	mfc1	$v0,$f8
/*  f147a98:	00000000 */ 	nop
/*  f147a9c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147aa0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147aa4:	440f5000 */ 	mfc1	$t7,$f10
/*  f147aa8:	04410005 */ 	bgez	$v0,.PB0f147ac0
/*  f147aac:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147ab0:	00029823 */ 	negu	$s3,$v0
/*  f147ab4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147ab8:	10000001 */ 	b	.PB0f147ac0
/*  f147abc:	03209825 */ 	move	$s3,$t9
.PB0f147ac0:
/*  f147ac0:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147ac4:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f147ac8:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f147acc:	00137600 */ 	sll	$t6,$s3,0x18
/*  f147ad0:	01d87825 */ 	or	$t7,$t6,$t8
/*  f147ad4:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f147ad8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f147adc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147ae0:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147ae4:	3c01f600 */ 	lui	$at,0xf600
/*  f147ae8:	02a02025 */ 	move	$a0,$s5
/*  f147aec:	25d80005 */ 	addiu	$t8,$t6,0x5
/*  f147af0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f147af4:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f147af8:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f147afc:	03217025 */ 	or	$t6,$t9,$at
/*  f147b00:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f147b04:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f147b08:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f147b0c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f147b10:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f147b14:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147b18:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147b1c:	02a01825 */ 	move	$v1,$s5
/*  f147b20:	01eec823 */ 	subu	$t9,$t7,$t6
/*  f147b24:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147b28:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147b2c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147b30:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147b34:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f147b38:	030f7025 */ 	or	$t6,$t8,$t7
/*  f147b3c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f147b40:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147b44:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147b48:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147b4c:	27380007 */ 	addiu	$t8,$t9,0x7
/*  f147b50:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147b54:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f147b58:	c5c80020 */ 	lwc1	$f8,0x20($t6)
/*  f147b5c:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f147b60:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f147b64:	00000000 */ 	nop
/*  f147b68:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f147b6c:	00000000 */ 	nop
/*  f147b70:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f147b74:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147b78:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f147b7c:	44025000 */ 	mfc1	$v0,$f10
/*  f147b80:	00000000 */ 	nop
/*  f147b84:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147b88:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147b8c:	440f3000 */ 	mfc1	$t7,$f6
/*  f147b90:	04410005 */ 	bgez	$v0,.PB0f147ba8
/*  f147b94:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147b98:	00029823 */ 	negu	$s3,$v0
/*  f147b9c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f147ba0:	10000001 */ 	b	.PB0f147ba8
/*  f147ba4:	01c09825 */ 	move	$s3,$t6
.PB0f147ba8:
/*  f147ba8:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147bac:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f147bb0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f147bb4:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f147bb8:	03197825 */ 	or	$t7,$t8,$t9
/*  f147bbc:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f147bc0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f147bc4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147bc8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147bcc:	3c01f600 */ 	lui	$at,0xf600
/*  f147bd0:	02a02025 */ 	move	$a0,$s5
/*  f147bd4:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f147bd8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147bdc:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f147be0:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f147be4:	01c1c025 */ 	or	$t8,$t6,$at
/*  f147be8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147bec:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f147bf0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f147bf4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f147bf8:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f147bfc:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147c00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147c04:	02a01825 */ 	move	$v1,$s5
/*  f147c08:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f147c0c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147c10:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147c14:	00197880 */ 	sll	$t7,$t9,0x2
/*  f147c18:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147c1c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f147c20:	032fc025 */ 	or	$t8,$t9,$t7
/*  f147c24:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f147c28:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147c2c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147c30:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147c34:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f147c38:	afb902ec */ 	sw	$t9,0x2ec($sp)
/*  f147c3c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f147c40:	c70a0024 */ 	lwc1	$f10,0x24($t8)
/*  f147c44:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f147c48:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f147c4c:	00000000 */ 	nop
/*  f147c50:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f147c54:	00000000 */ 	nop
/*  f147c58:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f147c5c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147c60:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f147c64:	44023000 */ 	mfc1	$v0,$f6
/*  f147c68:	00000000 */ 	nop
/*  f147c6c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147c70:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147c74:	440f2000 */ 	mfc1	$t7,$f4
/*  f147c78:	04410005 */ 	bgez	$v0,.PB0f147c90
/*  f147c7c:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147c80:	00029823 */ 	negu	$s3,$v0
/*  f147c84:	327800ff */ 	andi	$t8,$s3,0xff
/*  f147c88:	10000001 */ 	b	.PB0f147c90
/*  f147c8c:	03009825 */ 	move	$s3,$t8
.PB0f147c90:
/*  f147c90:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147c94:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f147c98:	00187400 */ 	sll	$t6,$t8,0x10
/*  f147c9c:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f147ca0:	032e7825 */ 	or	$t7,$t9,$t6
/*  f147ca4:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f147ca8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f147cac:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147cb0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147cb4:	3c01f600 */ 	lui	$at,0xf600
/*  f147cb8:	02a02025 */ 	move	$a0,$s5
/*  f147cbc:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f147cc0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147cc4:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f147cc8:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f147ccc:	0301c825 */ 	or	$t9,$t8,$at
/*  f147cd0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147cd4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f147cd8:	03387025 */ 	or	$t6,$t9,$t8
/*  f147cdc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f147ce0:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147ce4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147ce8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147cec:	02a01825 */ 	move	$v1,$s5
/*  f147cf0:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f147cf4:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147cf8:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147cfc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f147d00:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147d04:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147d08:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147d0c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147d10:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147d14:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147d18:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147d1c:	270e0007 */ 	addiu	$t6,$t8,0x7
/*  f147d20:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f147d24:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f147d28:	c7200028 */ 	lwc1	$f0,0x28($t9)
/*  f147d2c:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f147d30:	00000000 */ 	nop
/*  f147d34:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f147d38:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f147d3c:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f147d40:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f147d44:	44024000 */ 	mfc1	$v0,$f8
/*  f147d48:	00000000 */ 	nop
/*  f147d4c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147d50:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147d54:	440f5000 */ 	mfc1	$t7,$f10
/*  f147d58:	04410005 */ 	bgez	$v0,.PB0f147d70
/*  f147d5c:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147d60:	00029823 */ 	negu	$s3,$v0
/*  f147d64:	327900ff */ 	andi	$t9,$s3,0xff
/*  f147d68:	10000001 */ 	b	.PB0f147d70
/*  f147d6c:	03209825 */ 	move	$s3,$t9
.PB0f147d70:
/*  f147d70:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147d74:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f147d78:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f147d7c:	00137600 */ 	sll	$t6,$s3,0x18
/*  f147d80:	01d87825 */ 	or	$t7,$t6,$t8
/*  f147d84:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f147d88:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f147d8c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147d90:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147d94:	3c01f600 */ 	lui	$at,0xf600
/*  f147d98:	02a02025 */ 	move	$a0,$s5
/*  f147d9c:	25d80005 */ 	addiu	$t8,$t6,0x5
/*  f147da0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f147da4:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f147da8:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f147dac:	03217025 */ 	or	$t6,$t9,$at
/*  f147db0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f147db4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f147db8:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f147dbc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f147dc0:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f147dc4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147dc8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147dcc:	02a01825 */ 	move	$v1,$s5
/*  f147dd0:	01eec823 */ 	subu	$t9,$t7,$t6
/*  f147dd4:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147dd8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147ddc:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147de0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147de4:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f147de8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f147dec:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f147df0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147df4:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147df8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147dfc:	27380007 */ 	addiu	$t8,$t9,0x7
/*  f147e00:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147e04:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f147e08:	c5c8002c */ 	lwc1	$f8,0x2c($t6)
/*  f147e0c:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f147e10:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f147e14:	00000000 */ 	nop
/*  f147e18:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f147e1c:	00000000 */ 	nop
/*  f147e20:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f147e24:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147e28:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f147e2c:	44025000 */ 	mfc1	$v0,$f10
/*  f147e30:	00000000 */ 	nop
/*  f147e34:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147e38:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147e3c:	440f3000 */ 	mfc1	$t7,$f6
/*  f147e40:	04410005 */ 	bgez	$v0,.PB0f147e58
/*  f147e44:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147e48:	00029823 */ 	negu	$s3,$v0
/*  f147e4c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f147e50:	10000001 */ 	b	.PB0f147e58
/*  f147e54:	01c09825 */ 	move	$s3,$t6
.PB0f147e58:
/*  f147e58:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147e5c:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f147e60:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f147e64:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f147e68:	03197825 */ 	or	$t7,$t8,$t9
/*  f147e6c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f147e70:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f147e74:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147e78:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147e7c:	3c01f600 */ 	lui	$at,0xf600
/*  f147e80:	02a02025 */ 	move	$a0,$s5
/*  f147e84:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f147e88:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147e8c:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f147e90:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f147e94:	01c1c025 */ 	or	$t8,$t6,$at
/*  f147e98:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147e9c:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f147ea0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f147ea4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f147ea8:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f147eac:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147eb0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147eb4:	3c01f600 */ 	lui	$at,0xf600
/*  f147eb8:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f147ebc:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147ec0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147ec4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f147ec8:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147ecc:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f147ed0:	032fc025 */ 	or	$t8,$t9,$t7
/*  f147ed4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f147ed8:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f147edc:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147ee0:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f147ee4:	afb902ec */ 	sw	$t9,0x2ec($sp)
/*  f147ee8:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f147eec:	c70a0030 */ 	lwc1	$f10,0x30($t8)
/*  f147ef0:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f147ef4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f147ef8:	00000000 */ 	nop
/*  f147efc:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f147f00:	00000000 */ 	nop
/*  f147f04:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f147f08:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147f0c:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f147f10:	44023000 */ 	mfc1	$v0,$f6
/*  f147f14:	00000000 */ 	nop
/*  f147f18:	305300ff */ 	andi	$s3,$v0,0xff
/*  f147f1c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147f20:	440f2000 */ 	mfc1	$t7,$f4
/*  f147f24:	04410005 */ 	bgez	$v0,.PB0f147f3c
/*  f147f28:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f147f2c:	00029823 */ 	negu	$s3,$v0
/*  f147f30:	327800ff */ 	andi	$t8,$s3,0xff
/*  f147f34:	10000001 */ 	b	.PB0f147f3c
/*  f147f38:	03009825 */ 	move	$s3,$t8
.PB0f147f3c:
/*  f147f3c:	00137883 */ 	sra	$t7,$s3,0x2
/*  f147f40:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f147f44:	00187400 */ 	sll	$t6,$t8,0x10
/*  f147f48:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f147f4c:	032e7825 */ 	or	$t7,$t9,$t6
/*  f147f50:	02a01025 */ 	move	$v0,$s5
/*  f147f54:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f147f58:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f147f5c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f147f60:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147f64:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147f68:	02a01825 */ 	move	$v1,$s5
/*  f147f6c:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f147f70:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147f74:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f147f78:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f147f7c:	0301c825 */ 	or	$t9,$t8,$at
/*  f147f80:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f147f84:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f147f88:	03387025 */ 	or	$t6,$t9,$t8
/*  f147f8c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f147f90:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f147f94:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f147f98:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f147f9c:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f147fa0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f147fa4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f147fa8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f147fac:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f147fb0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147fb4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f147fb8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f147fbc:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f147fc0:	270e0007 */ 	addiu	$t6,$t8,0x7
/*  f147fc4:	1000003e */ 	b	.PB0f1480c0
/*  f147fc8:	afae02ec */ 	sw	$t6,0x2ec($sp)
.PB0f147fcc:
/*  f147fcc:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147fd0:	44815000 */ 	mtc1	$at,$f10
/*  f147fd4:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147fd8:	8fb902a4 */ 	lw	$t9,0x2a4($sp)
/*  f147fdc:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f147fe0:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f147fe4:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f147fe8:	240500ff */ 	li	$a1,0xff
/*  f147fec:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147ff0:	2407001e */ 	li	$a3,0x1e
/*  f147ff4:	2508fffd */ 	addiu	$t0,$t0,-3
/*  f147ff8:	00002025 */ 	move	$a0,$zero
/*  f147ffc:	44032000 */ 	mfc1	$v1,$f4
/*  f148000:	24060008 */ 	li	$a2,0x8
/*  f148004:	13200005 */ 	beqz	$t9,.PB0f14801c
/*  f148008:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f14800c:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f148010:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f148014:	2407000f */ 	li	$a3,0xf
/*  f148018:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.PB0f14801c:
/*  f14801c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f148020:	02a01025 */ 	move	$v0,$s5
/*  f148024:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f148028:	8f0e0490 */ 	lw	$t6,0x490($t8)
/*  f14802c:	008e082a */ 	slt	$at,$a0,$t6
/*  f148030:	54200003 */ 	bnezl	$at,.PB0f148040
/*  f148034:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f148038:	24050088 */ 	li	$a1,0x88
/*  f14803c:	30af00ff */ 	andi	$t7,$a1,0xff
.PB0f148040:
/*  f148040:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f148044:	032bc025 */ 	or	$t8,$t9,$t3
/*  f148048:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f14804c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f148050:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f148054:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f148058:	3c01f600 */ 	lui	$at,0xf600
/*  f14805c:	02a01825 */ 	move	$v1,$s5
/*  f148060:	01e7c821 */ 	addu	$t9,$t7,$a3
/*  f148064:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f148068:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14806c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f148070:	01c17825 */ 	or	$t7,$t6,$at
/*  f148074:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f148078:	00187080 */ 	sll	$t6,$t8,0x2
/*  f14807c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f148080:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f148084:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f148088:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14808c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f148090:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f148094:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f148098:	2738fffc */ 	addiu	$t8,$t9,-4
/*  f14809c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f1480a0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1480a4:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f1480a8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1480ac:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1480b0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1480b4:	25eefffb */ 	addiu	$t6,$t7,-5
/*  f1480b8:	1486ffd8 */ 	bne	$a0,$a2,.PB0f14801c
/*  f1480bc:	afae02e8 */ 	sw	$t6,0x2e8($sp)
.PB0f1480c0:
/*  f1480c0:	02a01025 */ 	move	$v0,$s5
.PB0f1480c4:
/*  f1480c4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1480c8:	02a01825 */ 	move	$v1,$s5
/*  f1480cc:	3c19e700 */ 	lui	$t9,0xe700
/*  f1480d0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1480d4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1480d8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1480dc:	37180602 */ 	ori	$t8,$t8,0x602
/*  f1480e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1480e4:	240f0040 */ 	li	$t7,0x40
/*  f1480e8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1480ec:	02a02025 */ 	move	$a0,$s5
/*  f1480f0:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f1480f4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1480f8:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f1480fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f148100:	3c190008 */ 	lui	$t9,0x8
/*  f148104:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f148108:	02a02825 */ 	move	$a1,$s5
/*  f14810c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f148110:	3c18ba00 */ 	lui	$t8,0xba00
/*  f148114:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f148118:	3c0f0001 */ 	lui	$t7,0x1
/*  f14811c:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f148120:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f148124:	8ece0298 */ 	lw	$t6,0x298($s6)
/*  f148128:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14812c:	05c10177 */ 	bgez	$t6,.PB0f14870c
/*  f148130:	00000000 */ 	nop
/*  f148134:	8ed9029c */ 	lw	$t9,0x29c($s6)
/*  f148138:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f14813c:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f148140:	07210172 */ 	bgez	$t9,.PB0f14870c
/*  f148144:	02a02025 */ 	move	$a0,$s5
/*  f148148:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f14814c:	25d9ff99 */ 	addiu	$t9,$t6,-103
/*  f148150:	44993000 */ 	mtc1	$t9,$f6
/*  f148154:	3c014188 */ 	lui	$at,0x4188
/*  f148158:	44810000 */ 	mtc1	$at,$f0
/*  f14815c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f148160:	3c013f80 */ 	lui	$at,0x3f80
/*  f148164:	44812000 */ 	mtc1	$at,$f4
/*  f148168:	8fa702f8 */ 	lw	$a3,0x2f8($sp)
/*  f14816c:	3c013f00 */ 	lui	$at,0x3f00
/*  f148170:	24190011 */ 	li	$t9,0x11
/*  f148174:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f148178:	2418000a */ 	li	$t8,0xa
/*  f14817c:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f148180:	44874000 */ 	mtc1	$a3,$f8
/*  f148184:	00000000 */ 	nop
/*  f148188:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f14818c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f148190:	44813000 */ 	mtc1	$at,$f6
/*  f148194:	3c0141c8 */ 	lui	$at,0x41c8
/*  f148198:	44035000 */ 	mfc1	$v1,$f10
/*  f14819c:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f1481a0:	c7a402c0 */ 	lwc1	$f4,0x2c0($sp)
/*  f1481a4:	0060a025 */ 	move	$s4,$v1
/*  f1481a8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f1481ac:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1481b0:	44815000 */ 	mtc1	$at,$f10
/*  f1481b4:	44064000 */ 	mfc1	$a2,$f8
/*  f1481b8:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f1481bc:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1481c0:	44052000 */ 	mfc1	$a1,$f4
/*  f1481c4:	00000000 */ 	nop
/*  f1481c8:	28a10012 */ 	slti	$at,$a1,0x12
/*  f1481cc:	54200003 */ 	bnezl	$at,.PB0f1481dc
/*  f1481d0:	240100dc */ 	li	$at,0xdc
/*  f1481d4:	24050011 */ 	li	$a1,0x11
/*  f1481d8:	240100dc */ 	li	$at,0xdc
.PB0f1481dc:
/*  f1481dc:	14e10003 */ 	bne	$a3,$at,.PB0f1481ec
/*  f1481e0:	03252823 */ 	subu	$a1,$t9,$a1
/*  f1481e4:	10000008 */ 	b	.PB0f148208
/*  f1481e8:	a3b800c3 */ 	sb	$t8,0xc3($sp)
.PB0f1481ec:
/*  f1481ec:	240100b4 */ 	li	$at,0xb4
/*  f1481f0:	14e10004 */ 	bne	$a3,$at,.PB0f148204
/*  f1481f4:	240ffff8 */ 	li	$t7,-8
/*  f1481f8:	2474ffff */ 	addiu	$s4,$v1,-1
/*  f1481fc:	10000002 */ 	b	.PB0f148208
/*  f148200:	a3af00c3 */ 	sb	$t7,0xc3($sp)
.PB0f148204:
/*  f148204:	a3a000c3 */ 	sb	$zero,0xc3($sp)
.PB0f148208:
/*  f148208:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f14820c:	0fc3530f */ 	jal	func0f0d479c
/*  f148210:	afa6007c */ 	sw	$a2,0x7c($sp)
/*  f148214:	3c0eb600 */ 	lui	$t6,0xb600
/*  f148218:	24193000 */ 	li	$t9,0x3000
/*  f14821c:	3c18b700 */ 	lui	$t8,0xb700
/*  f148220:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f148224:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f148228:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f14822c:	3c0efcff */ 	lui	$t6,0xfcff
/*  f148230:	3c19fffe */ 	lui	$t9,0xfffe
/*  f148234:	3c18ba00 */ 	lui	$t8,0xba00
/*  f148238:	3739793c */ 	ori	$t9,$t9,0x793c
/*  f14823c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f148240:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f148244:	240f0204 */ 	li	$t7,0x204
/*  f148248:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f14824c:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f148250:	ac580018 */ 	sw	$t8,0x18($v0)
/*  f148254:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f148258:	3c0eba00 */ 	lui	$t6,0xba00
/*  f14825c:	3c180050 */ 	lui	$t8,0x50
/*  f148260:	3c19b900 */ 	lui	$t9,0xb900
/*  f148264:	240f2000 */ 	li	$t7,0x2000
/*  f148268:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f14826c:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f148270:	371841c8 */ 	ori	$t8,$t8,0x41c8
/*  f148274:	ac4f001c */ 	sw	$t7,0x1c($v0)
/*  f148278:	ac4e0020 */ 	sw	$t6,0x20($v0)
/*  f14827c:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f148280:	ac58002c */ 	sw	$t8,0x2c($v0)
/*  f148284:	ac590028 */ 	sw	$t9,0x28($v0)
/*  f148288:	8faf02fc */ 	lw	$t7,0x2fc($sp)
/*  f14828c:	8fb902f8 */ 	lw	$t9,0x2f8($sp)
/*  f148290:	240100b4 */ 	li	$at,0xb4
/*  f148294:	25ee003a */ 	addiu	$t6,$t7,0x3a
/*  f148298:	24550030 */ 	addiu	$s5,$v0,0x30
/*  f14829c:	17210003 */ 	bne	$t9,$at,.PB0f1482ac
/*  f1482a0:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f1482a4:	25c80005 */ 	addiu	$t0,$t6,0x5
/*  f1482a8:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.PB0f1482ac:
/*  f1482ac:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*  f1482b0:	3c013f00 */ 	lui	$at,0x3f00
/*  f1482b4:	44815000 */ 	mtc1	$at,$f10
/*  f1482b8:	00a50019 */ 	multu	$a1,$a1
/*  f1482bc:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f1482c0:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1482c4:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f1482c8:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f1482cc:	83ae00c3 */ 	lb	$t6,0xc3($sp)
/*  f1482d0:	00a88823 */ 	subu	$s1,$a1,$t0
/*  f1482d4:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f1482d8:	25f90022 */ 	addiu	$t9,$t7,0x22
/*  f1482dc:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f1482e0:	0000c012 */ 	mflo	$t8
/*  f1482e4:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f1482e8:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f1482ec:	00009025 */ 	move	$s2,$zero
/*  f1482f0:	022e8023 */ 	subu	$s0,$s1,$t6
.PB0f1482f4:
/*  f1482f4:	8fa400bc */ 	lw	$a0,0xbc($sp)
/*  f1482f8:	24130050 */ 	li	$s3,0x50
/*  f1482fc:	24020056 */ 	li	$v0,0x56
/*  f148300:	0244082a */ 	slt	$at,$s2,$a0
/*  f148304:	10200003 */ 	beqz	$at,.PB0f148314
/*  f148308:	00000000 */ 	nop
/*  f14830c:	10000001 */ 	b	.PB0f148314
/*  f148310:	24130028 */ 	li	$s3,0x28
.PB0f148314:
/*  f148314:	0244082a */ 	slt	$at,$s2,$a0
/*  f148318:	10200003 */ 	beqz	$at,.PB0f148328
/*  f14831c:	00000000 */ 	nop
/*  f148320:	10000001 */ 	b	.PB0f148328
/*  f148324:	24020022 */ 	li	$v0,0x22
.PB0f148328:
/*  f148328:	02100019 */ 	multu	$s0,$s0
/*  f14832c:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f148330:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f148334:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f148338:	afa80224 */ 	sw	$t0,0x224($sp)
/*  f14833c:	afb8022c */ 	sw	$t8,0x22c($sp)
/*  f148340:	a3a200cf */ 	sb	$v0,0xcf($sp)
/*  f148344:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f148348:	afa30220 */ 	sw	$v1,0x220($sp)
/*  f14834c:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f148350:	0000c812 */ 	mflo	$t9
/*  f148354:	01f97023 */ 	subu	$t6,$t7,$t9
/*  f148358:	448e2000 */ 	mtc1	$t6,$f4
/*  f14835c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f148360:	0c012ae4 */ 	jal	sqrtf
/*  f148364:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f148368:	c7aa02a8 */ 	lwc1	$f10,0x2a8($sp)
/*  f14836c:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f148370:	83b900c3 */ 	lb	$t9,0xc3($sp)
/*  f148374:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f148378:	02348823 */ 	subu	$s1,$s1,$s4
/*  f14837c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f148380:	02398023 */ 	subu	$s0,$s1,$t9
/*  f148384:	02100019 */ 	multu	$s0,$s0
/*  f148388:	44815000 */ 	mtc1	$at,$f10
/*  f14838c:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f148390:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f148394:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f148398:	01147821 */ 	addu	$t7,$t0,$s4
/*  f14839c:	afaf0234 */ 	sw	$t7,0x234($sp)
/*  f1483a0:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f1483a4:	0000c012 */ 	mflo	$t8
/*  f1483a8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1483ac:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f1483b0:	448f2000 */ 	mtc1	$t7,$f4
/*  f1483b4:	44034000 */ 	mfc1	$v1,$f8
/*  f1483b8:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f1483bc:	afa30238 */ 	sw	$v1,0x238($sp)
/*  f1483c0:	0c012ae4 */ 	jal	sqrtf
/*  f1483c4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1483c8:	c7a602a8 */ 	lwc1	$f6,0x2a8($sp)
/*  f1483cc:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f1483d0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1483d4:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f1483d8:	44813000 */ 	mtc1	$at,$f6
/*  f1483dc:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f1483e0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1483e4:	93a200cf */ 	lbu	$v0,0xcf($sp)
/*  f1483e8:	afb8023c */ 	sw	$t8,0x23c($sp)
/*  f1483ec:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f1483f0:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f1483f4:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f1483f8:	02a02025 */ 	move	$a0,$s5
/*  f1483fc:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f148400:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f148404:	00003025 */ 	move	$a2,$zero
/*  f148408:	326700ff */ 	andi	$a3,$s3,0xff
/*  f14840c:	24010001 */ 	li	$at,0x1
/*  f148410:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f148414:	440e4000 */ 	mfc1	$t6,$f8
/*  f148418:	00000000 */ 	nop
/*  f14841c:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f148420:	afae0230 */ 	sw	$t6,0x230($sp)
/*  f148424:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f148428:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f14842c:	14600006 */ 	bnez	$v1,.PB0f148448
/*  f148430:	00000000 */ 	nop
/*  f148434:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f148438:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f14843c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f148440:	10000017 */ 	b	.PB0f1484a0
/*  f148444:	0040a825 */ 	move	$s5,$v0
.PB0f148448:
/*  f148448:	1461000c */ 	bne	$v1,$at,.PB0f14847c
/*  f14844c:	02a02025 */ 	move	$a0,$s5
/*  f148450:	00137080 */ 	sll	$t6,$s3,0x2
/*  f148454:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f148458:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f14845c:	02a02025 */ 	move	$a0,$s5
/*  f148460:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f148464:	24060010 */ 	li	$a2,0x10
/*  f148468:	326700ff */ 	andi	$a3,$s3,0xff
/*  f14846c:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f148470:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f148474:	1000000a */ 	b	.PB0f1484a0
/*  f148478:	0040a825 */ 	move	$s5,$v0
.PB0f14847c:
/*  f14847c:	00133883 */ 	sra	$a3,$s3,0x2
/*  f148480:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f148484:	03003825 */ 	move	$a3,$t8
/*  f148488:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f14848c:	326600ff */ 	andi	$a2,$s3,0xff
/*  f148490:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f148494:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f148498:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14849c:	0040a825 */ 	move	$s5,$v0
.PB0f1484a0:
/*  f1484a0:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1484a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1484a8:	2a410011 */ 	slti	$at,$s2,0x11
/*  f1484ac:	01144021 */ 	addu	$t0,$t0,$s4
/*  f1484b0:	1420ff90 */ 	bnez	$at,.PB0f1482f4
/*  f1484b4:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f1484b8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1484bc:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f1484c0:	3c014188 */ 	lui	$at,0x4188
/*  f1484c4:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f1484c8:	44813000 */ 	mtc1	$at,$f6
/*  f1484cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1484d0:	c7240060 */ 	lwc1	$f4,0x60($t9)
/*  f1484d4:	c4287f7c */ 	lwc1	$f8,0x7f7c($at)
/*  f1484d8:	24180011 */ 	li	$t8,0x11
/*  f1484dc:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f1484e0:	8fa802fc */ 	lw	$t0,0x2fc($sp)
/*  f1484e4:	8faf02f8 */ 	lw	$t7,0x2f8($sp)
/*  f1484e8:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f1484ec:	00009025 */ 	move	$s2,$zero
/*  f1484f0:	83ae00c3 */ 	lb	$t6,0xc3($sp)
/*  f1484f4:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f1484f8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1484fc:	44043000 */ 	mfc1	$a0,$f6
/*  f148500:	00000000 */ 	nop
/*  f148504:	28810012 */ 	slti	$at,$a0,0x12
/*  f148508:	54200003 */ 	bnezl	$at,.PB0f148518
/*  f14850c:	240100b4 */ 	li	$at,0xb4
/*  f148510:	24040011 */ 	li	$a0,0x11
/*  f148514:	240100b4 */ 	li	$at,0xb4
.PB0f148518:
/*  f148518:	03042023 */ 	subu	$a0,$t8,$a0
/*  f14851c:	15e10002 */ 	bne	$t7,$at,.PB0f148528
/*  f148520:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f148524:	25080005 */ 	addiu	$t0,$t0,0x5
.PB0f148528:
/*  f148528:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f14852c:	03288823 */ 	subu	$s1,$t9,$t0
/*  f148530:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f148534:	270fffde */ 	addiu	$t7,$t8,-34
/*  f148538:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f14853c:	022e8023 */ 	subu	$s0,$s1,$t6
/*  f148540:	afa400bc */ 	sw	$a0,0xbc($sp)
.PB0f148544:
/*  f148544:	8fa400bc */ 	lw	$a0,0xbc($sp)
/*  f148548:	24130050 */ 	li	$s3,0x50
/*  f14854c:	24020056 */ 	li	$v0,0x56
/*  f148550:	0244082a */ 	slt	$at,$s2,$a0
/*  f148554:	10200003 */ 	beqz	$at,.PB0f148564
/*  f148558:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f14855c:	10000001 */ 	b	.PB0f148564
/*  f148560:	24130028 */ 	li	$s3,0x28
.PB0f148564:
/*  f148564:	0244082a */ 	slt	$at,$s2,$a0
/*  f148568:	10200003 */ 	beqz	$at,.PB0f148578
/*  f14856c:	00000000 */ 	nop
/*  f148570:	10000001 */ 	b	.PB0f148578
/*  f148574:	24020022 */ 	li	$v0,0x22
.PB0f148578:
/*  f148578:	02100019 */ 	multu	$s0,$s0
/*  f14857c:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f148580:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f148584:	afa30220 */ 	sw	$v1,0x220($sp)
/*  f148588:	afa80224 */ 	sw	$t0,0x224($sp)
/*  f14858c:	afb9022c */ 	sw	$t9,0x22c($sp)
/*  f148590:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f148594:	a3a200cf */ 	sb	$v0,0xcf($sp)
/*  f148598:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f14859c:	afa400bc */ 	sw	$a0,0xbc($sp)
/*  f1485a0:	0000c012 */ 	mflo	$t8
/*  f1485a4:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f1485a8:	448f5000 */ 	mtc1	$t7,$f10
/*  f1485ac:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f1485b0:	0c012ae4 */ 	jal	sqrtf
/*  f1485b4:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f1485b8:	c7a802a8 */ 	lwc1	$f8,0x2a8($sp)
/*  f1485bc:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f1485c0:	83b800c3 */ 	lb	$t8,0xc3($sp)
/*  f1485c4:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f1485c8:	02348823 */ 	subu	$s1,$s1,$s4
/*  f1485cc:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1485d0:	02388023 */ 	subu	$s0,$s1,$t8
/*  f1485d4:	02100019 */ 	multu	$s0,$s0
/*  f1485d8:	44814000 */ 	mtc1	$at,$f8
/*  f1485dc:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1485e0:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f1485e4:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f1485e8:	01147021 */ 	addu	$t6,$t0,$s4
/*  f1485ec:	afae0234 */ 	sw	$t6,0x234($sp)
/*  f1485f0:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f1485f4:	0000c812 */ 	mflo	$t9
/*  f1485f8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1485fc:	01f97023 */ 	subu	$t6,$t7,$t9
/*  f148600:	448e5000 */ 	mtc1	$t6,$f10
/*  f148604:	44033000 */ 	mfc1	$v1,$f6
/*  f148608:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f14860c:	afa30238 */ 	sw	$v1,0x238($sp)
/*  f148610:	0c012ae4 */ 	jal	sqrtf
/*  f148614:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f148618:	c7a802a8 */ 	lwc1	$f8,0x2a8($sp)
/*  f14861c:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f148620:	3c0140a0 */ 	lui	$at,0x40a0
/*  f148624:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f148628:	44814000 */ 	mtc1	$at,$f8
/*  f14862c:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f148630:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f148634:	93a200cf */ 	lbu	$v0,0xcf($sp)
/*  f148638:	afb9023c */ 	sw	$t9,0x23c($sp)
/*  f14863c:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f148640:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f148644:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f148648:	02a02025 */ 	move	$a0,$s5
/*  f14864c:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f148650:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f148654:	00003025 */ 	move	$a2,$zero
/*  f148658:	326700ff */ 	andi	$a3,$s3,0xff
/*  f14865c:	24010001 */ 	li	$at,0x1
/*  f148660:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f148664:	440f3000 */ 	mfc1	$t7,$f6
/*  f148668:	00000000 */ 	nop
/*  f14866c:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f148670:	afaf0230 */ 	sw	$t7,0x230($sp)
/*  f148674:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f148678:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f14867c:	14600006 */ 	bnez	$v1,.PB0f148698
/*  f148680:	00000000 */ 	nop
/*  f148684:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f148688:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f14868c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f148690:	10000017 */ 	b	.PB0f1486f0
/*  f148694:	0040a825 */ 	move	$s5,$v0
.PB0f148698:
/*  f148698:	1461000c */ 	bne	$v1,$at,.PB0f1486cc
/*  f14869c:	02a02025 */ 	move	$a0,$s5
/*  f1486a0:	00137880 */ 	sll	$t7,$s3,0x2
/*  f1486a4:	01f37823 */ 	subu	$t7,$t7,$s3
/*  f1486a8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1486ac:	02a02025 */ 	move	$a0,$s5
/*  f1486b0:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f1486b4:	24060010 */ 	li	$a2,0x10
/*  f1486b8:	326700ff */ 	andi	$a3,$s3,0xff
/*  f1486bc:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f1486c0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1486c4:	1000000a */ 	b	.PB0f1486f0
/*  f1486c8:	0040a825 */ 	move	$s5,$v0
.PB0f1486cc:
/*  f1486cc:	00133883 */ 	sra	$a3,$s3,0x2
/*  f1486d0:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f1486d4:	03203825 */ 	move	$a3,$t9
/*  f1486d8:	27a50220 */ 	addiu	$a1,$sp,0x220
/*  f1486dc:	326600ff */ 	andi	$a2,$s3,0xff
/*  f1486e0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1486e4:	0fc51330 */ 	jal	bviewDrawEyespySideRect
/*  f1486e8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1486ec:	0040a825 */ 	move	$s5,$v0
.PB0f1486f0:
/*  f1486f0:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1486f4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1486f8:	24010011 */ 	li	$at,0x11
/*  f1486fc:	01144021 */ 	addu	$t0,$t0,$s4
/*  f148700:	1641ff90 */ 	bne	$s2,$at,.PB0f148544
/*  f148704:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f148708:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.PB0f14870c:
/*  f14870c:	0fc3539a */ 	jal	func0f0d49c8
/*  f148710:	02a02025 */ 	move	$a0,$s5
.PB0f148714:
/*  f148714:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f148718:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f14871c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f148720:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f148724:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f148728:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f14872c:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f148730:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f148734:	03e00008 */ 	jr	$ra
/*  f148738:	27bd0408 */ 	addiu	$sp,$sp,0x408
);
#elif VERSION >= VERSION_NTSC_1_0
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
Gfx *bviewDrawEyespyMetrics(Gfx *gdl)
{
	char text[256];
	s32 viewleft = viGetViewLeft();
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth();
	s32 viewheight = viGetViewHeight();
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 x2;
	s32 y2;
	struct chrdata *chr;
	s32 savedy;
	s32 movex;
	s32 movey;
	s32 movez;
	f32 movedist;
	f32 sqmovedist = 0.0f;
	u32 colourtextbright;
	u32 colourtextdull;
	u32 colourglow;
	s32 scale = viewwidth > 320 ? 2 : 1;
	bool vsplit = false;

	if (g_Vars.currentplayer->eyespy == NULL
			|| g_Vars.currentplayer->eyespy->prop == NULL
			|| g_Vars.currentplayer->eyespy->prop->chr == NULL) {
		return gdl;
	}

	chr = g_Vars.currentplayer->eyespy->prop->chr;

	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}

	movex = chr->prop->pos.x - chr->prevpos.x;
	movey = chr->prop->pos.y - chr->prevpos.y;
	movez = chr->prop->pos.z - chr->prevpos.z;

	if (movex != 0.0f || movey != 0.0f || movez != 0.0f) {
		sqmovedist = movex * movex + movey * movey + movez * movez;
	}

	if (sqmovedist > 0.001f) {
		movedist = sqrtf(sqmovedist);
	} else {
		movedist = 0.0f;
	}

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		gdl = textSetPrimColour(gdl, 0x00ff0028);
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		gdl = textSetPrimColour(gdl, 0x2244ffa0);
	} else {
		gdl = textSetPrimColour(gdl, 0xff3300a0);
	}

	if (!vsplit) {
		// Render borders/lines in background
		gDPFillRectangle(gdl++, viewleft + 25, viewtop + 55, viewleft + 26, viewbottom - 24);
		gDPFillRectangle(gdl++, viewleft + 31, viewtop + 55, viewleft + 32, viewbottom - 42);
		gDPFillRectangle(gdl++, viewleft + 25, viewbottom - 25, viewleft + 25 + viewwidth / 5.0f + 1, viewbottom - 24);
		gDPFillRectangle(gdl++, viewleft + 31, viewbottom - 43, viewleft + 25 + viewwidth / 7.0f + 1, viewbottom - 42);
		gDPFillRectangle(gdl++, viewright - 25, viewtop + 25, viewright - 24, viewbottom - 54);
		gDPFillRectangle(gdl++, viewright - 31, viewtop + 43, viewright - 30, viewbottom - 54);
		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 5.0f, viewtop + 25, viewright - 24, viewtop + 26);
		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 7.0f, viewtop + 43, viewright - 30, viewtop + 44);
		gDPFillRectangle(gdl++, viewleft, viewtop + 55, viewleft + viewwidth / 5.0f + 1, viewtop + 56);
		gDPFillRectangle(gdl++, viewright - viewwidth / 5.0f, viewbottom - 55, viewright + 1, viewbottom - 54);
	}

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		// Render crosshair
		s32 x = viewleft + (viewwidth >> 1);
		s32 y = viewtop + (viewheight >> 1);

		gDPFillRectangle(gdl++, x + 2, y + 0, x + 7, y + 1);
		gDPFillRectangle(gdl++, x + 2, y + 0, x + 5, y + 1);
		gDPFillRectangle(gdl++, x - 6, y + 0, x - 1, y + 1);
		gDPFillRectangle(gdl++, x - 4, y + 0, x - 1, y + 1);
		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 7);
		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 5);
		gDPFillRectangle(gdl++, x + 0, y - 6, x + 1, y - 1);
		gDPFillRectangle(gdl++, x + 0, y - 4, x + 1, y - 1);
	}

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		colourtextbright = 0x00ff00a0;
		colourtextdull = 0x005000ff;
		colourglow = 0x000f00ff;
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		colourtextbright = 0x2244ffff;
		colourtextdull = 0x2244ffff;
		colourglow = 0x00000fff;
	} else {
		colourtextbright = 0xff3300ff;
		colourtextdull = 0xff3300ff;
		colourglow = 0x0f0000ff;
	}

	// "S/MPS"
	sprintf(text, "%s %s%5.2f", langGet(L_MISC_073), "", movedist * 0.6f);
	savedy = viewtop + 14;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	// "H/M"
	sprintf(text, "%s %s%4.2f", langGet(L_MISC_074), "", g_Vars.currentplayer->eyespy->height * 0.01f);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	// "Y/D"
	sprintf(text, "%s %d", langGet(L_MISC_075), (s32)g_Vars.currentplayer->eyespy->theta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	// "P/D"
	sprintf(text, "%s %d", langGet(L_MISC_076), (s32)g_Vars.currentplayer->eyespy->verta);
	savedy += 9;
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = viewleft + 25 * scale;
	y = savedy;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	// "CI 2023"
	sprintf(text, "%s", langGet(L_MISC_077));
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
	y = (vsplit ? 18 : 0) + viewbottom - 41;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		sprintf(text, "%s", langGet(L_MISC_078)); // "YKK: 95935"
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		sprintf(text, "%s", langGet(L_MISC_208)); // "JM: 201172"
	} else {
		sprintf(text, "%s", langGet(L_MISC_217)); // "BNC: 15877"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

	x = viewleft + 25 * scale + (vsplit ? -3 : 0) + 5;
	y = viewbottom + (vsplit ? 20 : 0) - 34;
	x2 = x + textwidth; y2 = y + textheight; gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		// "CAMSPY"
		sprintf(text, "   %s", langGet(L_MISC_079));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 53 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		// "DRUGSPY"
		sprintf(text, "   %s", langGet(L_MISC_468));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 53 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
	} else {
		// "BOMBSPY"
		sprintf(text, "   %s", langGet(L_MISC_469));
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x = viewright - scale * 59 - 25;
		y = (vsplit ? -13 : 0) + viewtop + 27;
		x2 = x + textwidth; \
		y2 = y + textheight; \
		gdl = text0f153858(gdl, &x, &y, &x2, &y2);
		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
	}

	// Model number
	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
		sprintf(text, "%s", langGet(L_MISC_080)); // "MODEL 1.2"
	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
		sprintf(text, "%s", langGet(L_MISC_207)); // "MODEL 1.4"
	} else {
		sprintf(text, "%s", langGet(L_MISC_216)); // "MODEL 1.3"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = (vsplit ? 3 : 0) + viewright - scale * 46 - 25;
	y = (vsplit ? -11 : 0) + viewtop + 34;
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	// Gyrostat/dartammo text
	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY
			|| g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
		sprintf(text, "%s", langGet(L_MISC_081)); // "GYROSTAT"
	} else {
		sprintf(text, "%s", langGet(L_MISC_206)); // "DARTAMMO"
	}

	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = (vsplit ? -35 : 0) + (viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5));
	y = (vsplit ? -2 : 0) + viewbottom - 12;
	if (1);
	x2 = x + textwidth; \
	y2 = y + textheight; \
	gdl = text0f153858(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);

	gdl = text0f153838(gdl);

	{
		s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
		u16 buttonsdown = joyGetButtons(contpadnum, 0xffff); \
		u16 buttonsthisframe = joyGetButtonsPressedThisFrame(contpadnum, 0xffff);
		s8 cstickx = joyGetStickX(contpadnum); \
		s8 csticky = joyGetStickY(contpadnum);
		s32 xpos;
		s32 tmpval;
		u8 brightness;
		u8 brightness2;
		s32 points[8];
		s32 r;
		s32 g;
		s32 b;

		gDPPipeSync(gdl++); \
		gDPSetCycleType(gdl++, G_CYC_1CYCLE); \
		gDPSetColorDither(gdl++, G_CD_DISABLE); \
		gDPSetTexturePersp(gdl++, G_TP_NONE); \
		gDPSetAlphaCompare(gdl++, G_AC_NONE); \
		gDPSetTextureLOD(gdl++, G_TL_TILE); \
		gDPSetTextureFilter(gdl++, G_TF_BILERP); \
		gDPSetTextureConvert(gdl++, G_TC_FILT); \
		gDPSetTextureLUT(gdl++, G_TT_NONE); \
		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2); \
		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

		if (!vsplit) {
			xpos = (scale == 2) ? -76 : -85;

			// Up
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20; \
				if (buttonsdown & (U_JPAD | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) { \
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff); \
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
					brightness += 63; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
					brightness += 20; \
				} \
				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Down
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Left
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Right
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
					brightness += 63;
				}

				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Shoulder buttons
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & (L_TRIG | R_TRIG)) {
					brightness += 63;
				}

				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
			xpos += 10;

			// Z button
			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
				brightness = 20;

				if (buttonsdown & Z_TRIG) {
					brightness += 20;
				}

				if (buttonsthisframe & Z_TRIG) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
				brightness = 127;

				if (buttonsdown & Z_TRIG) {
					brightness += 63;
				}

				if (buttonsthisframe & Z_TRIG) {
					brightness += 63;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
			} else {
				brightness = 20;

				if (buttonsdown & Z_TRIG) {
					brightness += 20;
				}

				if (buttonsthisframe & Z_TRIG) {
					brightness += 20;
				}

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
			}

			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
		}

		xpos = (scale == 2 ? -48 : -55);

		// Stick X
		tmpval = cstickx * 96.0f / 80.0f;
		brightness = tmpval < 0 ? -tmpval : tmpval;

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
			r = brightness / 96.0f * 16.0f;
			g = brightness / 96.0f * 32.0f;
			b = brightness * 2.5f;
			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
		} else {
			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
		}

		if (!vsplit) {
			tmpval = cstickx * 28.0f / 80.0f;

			if (cstickx > 0) {
				gDPFillRectangle(gdl++,
						xpos * scale + viewright,
						viewtop + 19,
						(tmpval + xpos) * scale + viewright,
						viewtop + 21);
			} else {
				gDPFillRectangle(gdl++,
						(tmpval + xpos) * scale + viewright,
						viewtop + 19,
						xpos * scale + viewright,
						viewtop + 21);
			}
		}

		// Stick Y
		tmpval = csticky * 96.0f / 80.0f;
		brightness = tmpval < 0 ? -tmpval : tmpval;

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
			r = brightness / 96.0f * 16.0f;
			g = brightness / 96.0f * 32.0f;
			b = brightness * 2.5f;
			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
		} else {
			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
		}

		if (!vsplit) {
			tmpval = csticky * 28.0f / 80.0f;

			if (csticky > 0) {
				gDPFillRectangle(gdl++,
						xpos * scale + viewright,
						viewtop + 22,
						(tmpval + xpos) * scale + viewright,
						viewtop + 24);
			} else {
				gDPFillRectangle(gdl++,
						(tmpval + xpos) * scale + viewright,
						viewtop + 22,
						xpos * scale + viewright,
						viewtop + 24);
			}
		}

		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
			if (!vsplit) {
				// Camspy gyrobar 1
				x = viewright - viewwidth / 5.0f;
				y = viewbottom - 13;

				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 2
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 3
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 4
				x += scale * 2 + scale * 5;

				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 5
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Camspy gyrobar 6
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				x += scale * 2 + scale * 5;
			}
		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
			if (!vsplit) {
				// Bombspy gyrobar 1
				x = viewright - viewwidth / 5.0f;
				y = viewbottom - 13;

				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 2
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 3
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 4
				x += scale * 2 + scale * 5;

				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 5
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				// Bombspy gyrobar 6
				x += scale * 2 + scale * 5;

				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
				brightness = tmpval < 0 ? -tmpval : tmpval;

				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);

				x += scale * 2 + scale * 5;
			}
		} else {
			// Drugspy ammo
			s32 i;
			s32 width;

			brightness2 = 255;
			width = scale * 30;

			y = viewbottom - 13;
			x = viewright - viewwidth / 5.0f + 5;

			if (vsplit) {
				x -= 12;
				y -= 3;
				width = 15;
			}

			for (i = 0; i < 8; i++) {
				if (i >= g_Vars.currentplayer->eyespydarts) {
					brightness2 = 0x88;
				}

				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness2, 0xff);
				gDPFillRectangle(gdl++, x, y - 4, x + width, y);

				y -= 5;
			}
		}

		gDPPipeSync(gdl++); \
		gDPSetColorDither(gdl++, G_CD_BAYER); \
		gDPSetTexturePersp(gdl++, G_TP_PERSP); \
		gDPSetTextureLOD(gdl++, G_TL_LOD);

		if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
			s32 barheight = (viewbottom - viewtop - 103) / 17.0f - 1;
			s32 centrey;
			s32 sqcentrey;
			s32 ypos;
			u8 alpha;
			u32 stack;
			u32 stack2;
			s8 yoffset;
			s32 value = 17.0f * movedist / 25.0f;
			s32 i;

			if (value > 17) {
				value = 17;
			}

			value = 17 - value;

			if (viewheight == 220) {
				yoffset = 10;
			} else if (viewheight == 180) {
				barheight--;
				yoffset = -8;
			} else {
				yoffset = 0;
			}

			gdl = func0f0d479c(gdl);

			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
			gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
			gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
			gDPSetTextureFilter(gdl++, G_TF_BILERP);
			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
			gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

			// Speed bars (left side)
			y = viewtop + 58;

			if (viewheight == 180) {
				y += 5;
			}

			centrey = viewheight * .5f;
			ypos = centrey - y + 10;
			sqcentrey = centrey * centrey;

			for (i = 0; i < 17; i++) {
				brightness = i < value ? 0x28 : 0x50;
				alpha = i < value ? 0x22 : 0x56;

				points[0] = x = viewleft + 34;
				points[1] = y;
				points[2] = x = viewleft + 34;
				points[3] = y + barheight;
				points[6] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
				points[5] = y + barheight;

				ypos -= barheight;

				points[4] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
				points[7] = y;

				ypos -= 2;

				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0, brightness, 0, alpha);
				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0x10, brightness, brightness * 3, alpha);
				} else {
					gdl = bviewDrawEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
				}

				y += barheight;
				y += 2;
			}

			// Height bars (right side)
			value = g_Vars.currentplayer->eyespy->height * 17.0f * 0.00625f;

			if (value > 17) {
				value = 17;
			}

			value = 17 - value;

			y = viewtop + 46;

			if (viewheight == 180) {
				y += 5;
			}

			ypos = centrey - y + 10;

			for (i = 0; i < 17; i++) {
				brightness = i < value ? 0x28 : 0x50;
				alpha = i < value ? 0x22 : 0x56;

				points[0] = x = viewright - 34;
				points[1] = y;
				points[3] = y + barheight;
				points[2] = x = viewright - 34;
				points[6] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
				points[5] = y + barheight;

				ypos -= barheight;

				points[4] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
				points[7] = y;

				ypos -= 2;

				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0, brightness, 0, alpha);
				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
					gdl = bviewDrawEyespySideRect(gdl, points, 0x10, brightness, brightness * 3, alpha);
				} else {
					gdl = bviewDrawEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
				}

				y += barheight;
				y += 2;
			}
		}

		gdl = func0f0d49c8(gdl);
	}

	return gdl;
}
#else
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

GLOBAL_ASM(
glabel bviewDrawEyespyMetrics
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
/*  f13e558:	0fc537b7 */ 	jal	textSetPrimColour
/*  f13e55c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e560:	1000000e */ 	beqz	$zero,.NB0f13e59c
/*  f13e564:	44903000 */ 	mtc1	$s0,$f6
.NB0f13e568:
/*  f13e568:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13e56c:	14610007 */ 	bne	$v1,$at,.NB0f13e58c
/*  f13e570:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e574:	3c052244 */ 	lui	$a1,0x2244
/*  f13e578:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f13e57c:	0fc537b7 */ 	jal	textSetPrimColour
/*  f13e580:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e584:	10000005 */ 	beqz	$zero,.NB0f13e59c
/*  f13e588:	44903000 */ 	mtc1	$s0,$f6
.NB0f13e58c:
/*  f13e58c:	3c05ff33 */ 	lui	$a1,0xff33
/*  f13e590:	0fc537b7 */ 	jal	textSetPrimColour
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
/*  f13ee88:	0fc537d6 */ 	jal	text0f153858
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
/*  f13ef9c:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f0a0:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f1a4:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f298:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f3f0:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f51c:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f644:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f758:	0fc537d6 */ 	jal	text0f153858
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
/*  f13f8d4:	0fc537d6 */ 	jal	text0f153858
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
/*  f13fa40:	0fc537d6 */ 	jal	text0f153858
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
/*  f13faac:	0fc537ce */ 	jal	text0f153838
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
/*  f141884:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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
/*  f1418b8:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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
/*  f1418e0:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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
/*  f141ad4:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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
/*  f141b08:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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
/*  f141b30:	0fc4f85a */ 	jal	bviewDrawEyespySideRect
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

void bview0f1572f8(void)
{
	// empty
}

u8 var8007f878 = 0;

Gfx *bviewDrawNvLens(Gfx *gdl)
{
	u8 *fb = viGetBackBuffer();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewleft = viGetViewLeft();
	s32 viewbottom = viewtop + viewheight;
	s32 roomvalue;
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	// @bug: This is overflowing var800a41c0 into g_IrScanlines, but it has
	// no effect because IR scanlines are not rendered for night vision.
	strcpy(var800a41c0, "Fullscreen_DrawFaultScope");

	var8009caec = 0xbc;
	var8009caef = 0xbe;
	var8009caf0 = 0xde;
	var8009caed = 0x50;
	var8009caee = 0xc0;

	roomvalue = func0f0009c0(g_Vars.currentplayer->prop->rooms[0]);

	if (roomvalue > 128) {
		sky0f127334(roomvalue, roomvalue, roomvalue);
	}

	if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog == NULL) {
		gdl = bviewDrawMotionBlur(gdl, 0x00ff0000, 0x60);
	}

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 0xff);

	var8007f878++;

	for (y = viewtop; y < viewbottom; y++) {
		u8 green;

		if (((var8007f878 & 1) != (y & 1)) != 0) {
			u8 tmp = random() % 12;
			green = 0xff - tmp;
		} else {
			green = 0x94;
		}

		gDPSetColor(gdl++, G_SETENVCOLOR, (green << 16) + 0xff);

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 1, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Night vision doesn't have binoculars.
 */
Gfx *bviewDrawNvBinoculars(Gfx *gdl)
{
	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bviewDrawIrLens
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
/*  f1475ac:	0c002ac7 */ 	jal	viGetBackBuffer
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
/*  f147998:	0fc506ac */ 	jal	bviewCopyPixels
/*  f14799c:	00408825 */ 	or	$s1,$v0,$zero
/*  f1479a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1479a4:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1479a8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1479ac:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1479b0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1479b4:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1479b8:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f1479bc:	0fc506ac */ 	jal	bviewCopyPixels
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
/*  f1479f4:	0fc506ac */ 	jal	bviewCopyPixels
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
/*  f147a1c:	0fc506ac */ 	jal	bviewCopyPixels
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
/*  f147ab4:	0fc5090e */ 	jal	bviewDrawMotionBlur
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
);
#else
GLOBAL_ASM(
glabel bviewDrawIrLens
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
/*  f141e40:	0c002b27 */ 	jal	viGetBackBuffer
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
/*  f141f0c:	0fc4f0b4 */ 	jal	func0f13c2d0nb
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
/*  f1421d0:	0fc4f168 */ 	jal	bviewCopyPixels
/*  f1421d4:	00409025 */ 	or	$s2,$v0,$zero
/*  f1421d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1421dc:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1421e0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1421e4:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1421e8:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1421ec:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1421f0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f1421f4:	0fc4f168 */ 	jal	bviewCopyPixels
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
/*  f14222c:	0fc4f168 */ 	jal	bviewCopyPixels
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
/*  f142254:	0fc4f168 */ 	jal	bviewCopyPixels
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
/*  f1422d0:	0fc4f3ca */ 	jal	bviewDrawMotionBlur
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
);
#endif

const char var7f1b5e6c[] = "Fullscreen_DrawFaultScope";

#if VERSION < VERSION_NTSC_1_0
const char var7f1b03d8nb[] = "Fault Scope is active\n";
#endif

// Mismatch: scanincrement and fadeincrement float math is reordered.
//Gfx *bviewDrawIrLens(Gfx *gdl)
//{
//	s32 i;
//	s32 fadeincrement; // e8
//	u8 *fb = viGetBackBuffer();
//	s32 viewheight = viGetViewHeight();
//	s32 viewwidth = viGetViewWidth(); // dc
//	s32 viewtop = viGetViewTop();
//	s32 viewleft = viGetViewLeft(); // d4
//	s32 viewright;
//	s32 viewbottom;
//	s32 viewcentrex; // c8
//	s32 scantop;
//	s32 scanbottom; // ac
//	u32 red; // a0
//	s32 outerradius;
//	s32 a0;
//	s32 innerradius; // s5
//	s32 scanincrement;
//	s32 viewcentrey; // 64
//	s32 scanrate = 4;
//	s32 faderate = 2;
//	f32 viewheightf;
//	s32 tmp;
//	s32 stack[3];
//
//	viewright = viewleft + viewwidth;
//	viewcentrex = (viewleft + viewright) / 2;
//
//	outerradius = g_IrBinocularRadius;
//	innerradius = g_IrBinocularRadius / var8007f850;
//
//	var8007f840++;
//
//	if (var8007f840 >= 2) {
//		return gdl;
//	}
//
//	// @bug: This is overflowing var800a41c0 into g_IrScanlines, but it has
//	// no effect because the first couple of scanlines are obscured by the
//	// binocular and are therefore not rendered.
//	strcpy(var800a41c0, "Fullscreen_DrawFaultScope");
//
//#if VERSION < VERSION_NTSC_1_0
//	func0f13c2d0nb();
//#endif
//
//	viewbottom = viewtop + viewheight;
//	viewcentrey = (viewtop + viewbottom) / 2;
//	scantop = viewcentrey - outerradius;
//	scanbottom = viewcentrey + outerradius;
//
//	if (scantop > viewbottom) {
//		scantop = viewbottom;
//	}
//
//	if (scanbottom > viewbottom) {
//		scanbottom = viewbottom;
//	}
//
//	if (scantop < viewtop) {
//		scantop = viewtop;
//	}
//
//	if (scanbottom < viewtop) {
//		scanbottom = viewtop;
//	}
//
//	scanincrement = (f32)scanrate * viewheight / 240.0f;
//	fadeincrement = (f32)faderate * viewheight / 240.0f;
//
//	// This code runs on the first frame of IR use (90 != 0),
//	// and in debug versions developers could change the radius at runtime.
//	if (outerradius != g_Vars.currentplayer->fslastradius) {
//		for (i = 0; i < 480; i++) {
//#if VERSION >= VERSION_NTSC_1_0
//			g_IrScanlines[g_Vars.currentplayernum][i] = 0xff;
//#else
//			g_IrScanlines[0][i] = 0xff;
//#endif
//		}
//
//		g_Vars.currentplayer->fsscanline = 0;
//		g_Vars.currentplayer->fslastradius = outerradius;
//	}
//
//	// Increment the scanline
//	for (i = 0; i < scanincrement; i++) {
//		if (g_Vars.currentplayer->fsscanline >= scanbottom) {
//			g_Vars.currentplayer->fsscanline = scantop;
//		}
//
//		g_IrScanlines[g_Vars.currentplayernum][g_Vars.currentplayer->fsscanline] = 0xff - i;
//
//		g_Vars.currentplayer->fsscanline++;
//	}
//
//	var8009caec = 0xff;
//	var8009caef = 0xde;
//	var8009caf0 = 0xde;
//
//	gDPPipeSync(gdl++);
//
//	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);
//
//	innerradius = innerradius * innerradius;
//
//	for (i = scantop; i < scanbottom; i++) {
//#if VERSION >= VERSION_NTSC_1_0
//		if (i & 1) {
//			red = g_IrScanlines[g_Vars.currentplayernum][i];
//		} else {
//			red = g_IrScanlines[g_Vars.currentplayernum][i] * 2 / 3;
//		}
//#else
//		if (i & 1) {
//			red = g_IrScanlines[0][i];
//		} else {
//			red = g_IrScanlines[0][i] * 2 / 3;
//		}
//#endif
//
//		red += random() % 8;
//
//		if (red > 255) {
//			red = 255;
//		}
//
//		gDPSetEnvColorViaWord(gdl++, (red << 24) + 0xff);
//
//		a0 = viewcentrey - i;
//
//		if (a0 * a0 < innerradius) {
//			// Rendering a line that overlaps the semicircle
//			// in the middle of the screen
//			f32 f0 = a0;
//			s32 semicirclewidth = sqrtf(innerradius - (s32) (f0 * f0)) * (viewwidth / 320.0f);
//			s32 semicircleright = viewcentrex + semicirclewidth;
//			s32 rightsidewidth = viewwidth - semicircleright;
//
//			// Left and right of semicircle
//			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewleft, viewcentrex);
//			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, semicircleright, rightsidewidth);
//
//			// The semicircle itself has a static colour
//			gDPSetEnvColorViaWord(gdl++, 0xee0000ff);
//			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewcentrex, semicirclewidth);
//		} else {
//			gdl = bviewCopyPixels(gdl, fb, i, 5, i, 1.0f, viewleft, viewwidth);
//		}
//
//#if VERSION >= VERSION_NTSC_1_0
//		if (g_IrScanlines[g_Vars.currentplayernum][i] > fadeincrement) {
//			g_IrScanlines[g_Vars.currentplayernum][i] -= fadeincrement;
//		}
//#else
//		if (g_IrScanlines[0][i] > fadeincrement) {
//			g_IrScanlines[0][i] -= fadeincrement;
//		}
//#endif
//	}
//
//	if (g_Menus[g_Vars.currentplayerstats->mpindex].curdialog == NULL) {
//		gdl = bviewDrawMotionBlur(gdl, 0xff000000, 0x40);
//	}
//
//	return gdl;
//}

/**
 * Draw a horizontal blur/sretch effect. Unused.
 *
 * The term "Intro" used in the string suggests that was made for an older
 * version of the title screen, similar to bviewDrawIntroText.
 */
Gfx *bviewDrawIntroFaderBlur(Gfx *gdl, s32 arg1)
{
	u8 *fb = viGetBackBuffer();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 halfheight;
	f32 extra;
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "IntroFaderBlurGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	halfheight = viewheight * 0.5f;

	extra = 0.5f;
	extra += 0.5f;

	for (y = viewtop; y < viewtop + viewheight; y++) {
		f32 frac = (y - viewtop - halfheight) / halfheight;

		if (frac < 0.0f) {
			frac = -frac;
		}

		frac += extra;

		if (frac > 1.0f) {
			frac = 1.0f;
		}

		gdl = bviewCopyPixels(gdl, fb, y, 5, y, RANDOMFRAC() * frac + 1.0f, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Called from the title screen's "Rare Presents" mode, which is unused.
 */
Gfx *bviewDrawIntroText(Gfx *gdl)
{
	u8 *fb = viGetBackBuffer();
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
		gdl = bviewCopyPixels(gdl, fb, y, 5, y, 1.0f, viewleft, viewwidth);
	}

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *bviewDrawHorizonScanner(Gfx *gdl)
{
	u8 *fb = viGetBackBuffer();
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

	if (!PAL && g_ViRes == VIRES_HI) {
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
	gdl = textSetPrimColour(gdl, 0x000000ff);

	gDPFillRectangle(gdl++, viewleft, viewtop, viewleft + viewwidth, lenstop);
	gDPFillRectangle(gdl++, viewleft, lenstop + lensheight, viewleft + viewwidth, viewtop + viewheight);

	gdl = text0f153838(gdl);

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

	gdl = text0f153628(gdl);

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
	gdl = text0f153780(gdl);

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

		gdl = bviewCopyPixels(gdl, fb, liney, 5, liney, RANDOMFRAC() * range + 1, viewleft, viewwidth);
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

s32 var8008095cnb = 0;
s32 var80080960nb = -1;

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

GLOBAL_ASM(
glabel bviewDrawHorizonScanner
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
/*  f142660:	0c002b27 */ 	jal	viGetBackBuffer
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
/*  f1428a0:	0fc537b7 */ 	jal	textSetPrimColour
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
/*  f142928:	0fc537ce */ 	jal	text0f153838
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
/*  f142a48:	0fc5374a */ 	jal	text0f153628
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
/*  f142d54:	0fc537a0 */ 	jal	text0f153780
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
/*  f142ffc:	0fc4f168 */ 	jal	bviewCopyPixels
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
 * Draws the black part of the IR scanner, which obscures the edges of the
 * screen and creates the binocular effect.
 *
 * The two circles are "placed" at the 1/3 and 2/3 marks horizontally. The
 * screen is then iterated top to bottom, one line at a time, and draws
 * black rectangles on each line to fill in the area outside the circles.
 */
Gfx *bviewDrawIrBinoculars(Gfx *gdl)
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
				gdl = bviewDrawIrRect(gdl, viewleft, y, leftx - xoffset, y + 1);
			}

			// Middle (top and bottom)
			if (leftx + xoffset < rightx - xoffset) {
				gdl = bviewDrawIrRect(gdl, leftx + xoffset, y, rightx - xoffset, y + 1);
			}

			// Right side
			if (rightx + xoffset < viewright) {
				gdl = bviewDrawIrRect(gdl, rightx + xoffset, y, viewright, y + 1);
			}
		} else {
			// Very top or bottom - whole line is black
#if VERSION >= VERSION_NTSC_1_0
			gdl = bviewDrawIrRect(gdl, viewleft, y, viewright, y + 1);
#else
			gdl = bviewDrawIrRect(gdl, viewleft, y, viewright - 1, y + 1);
#endif
		}
	}

	return gdl;
}

Gfx *bview0f148b38(Gfx *gdl)
{
	return gdl;
}

void bviewSetMotionBlur(u32 bluramount)
{
	var8007f840 = 0;
	var8007f848 = 0;
	var8007f844 = (bluramount << 1) / 3;
}

void bviewClearMotionBlur(void)
{
	var8007f844 = 0;
}
