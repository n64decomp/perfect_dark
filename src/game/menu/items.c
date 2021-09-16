#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_006900.h"
#include "game/game_095320.h"
#include "game/game_0b3350.h"
#include "game/game_0e0770.h"
#include "game/menu/items.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

u8 g_MpSelectedPlayersForStats[4];

const char var7f1adfa0[] = "brcol";
const char var7f1adfa8[] = "%d: ";
const char var7f1adfb0[] = "%s";

s32 g_ScissorX1 = 0x00000000;
s32 g_ScissorX2 = 0x00000000;
s32 g_ScissorY1 = 0x00000000;
s32 g_ScissorY2 = 0x00000000;
s32 var800711a0 = 0;
s32 var800711a4 = 0;
u32 g_LineHeight = 11;

u8 g_KeyboardKeys[5][10] = {
	{ '0','1','2','3','4','5','6','7','8','9' },
	{ 'A','B','C','D','E','F','G','H','I','J' },
	{ 'K','L','M','N','O','P','Q','R','S','T' },
	{ 'U','V','W','X','Y','Z',' ','?','!','.' },
	{ '1','2','1','2','1','2','3','1','2','3' },
};

s32 func0f0e5ce0(s32 value)
{
	if (value < var800711a4) {
		var800711a0++;

		if (var800711a0 > 320) {
			var800711a0 = 0;
		}
	}

	var800711a4 = value;

	return var800711a0;
}

GLOBAL_ASM(
glabel func0f0e5d2c
/*  f0e5d2c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e5d30:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e5d34:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0e5d38:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0e5d3c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0e5d40:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0e5d44:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e5d48:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e5d4c:	8cae0010 */ 	lw	$t6,0x10($a1)
/*  f0e5d50:	00a09825 */ 	or	$s3,$a1,$zero
/*  f0e5d54:	00803825 */ 	or	$a3,$a0,$zero
/*  f0e5d58:	15c00003 */ 	bnez	$t6,.L0f0e5d68
/*  f0e5d5c:	27b50050 */ 	addiu	$s5,$sp,0x50
/*  f0e5d60:	1000005c */ 	b	.L0f0e5ed4
/*  f0e5d64:	00001025 */ 	or	$v0,$zero,$zero
.L0f0e5d68:
/*  f0e5d68:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f0e5d6c:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0e5d70:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0e5d74:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0e5d78:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e5d7c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e5d80:	0320f809 */ 	jalr	$t9
/*  f0e5d84:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5d88:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e5d8c:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f0e5d90:	54c00011 */ 	bnezl	$a2,.L0f0e5dd8
/*  f0e5d94:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f0e5d98:	3c0f8007 */ 	lui	$t7,%hi(g_LineHeight)
/*  f0e5d9c:	8def11a8 */ 	lw	$t7,%lo(g_LineHeight)($t7)
/*  f0e5da0:	00ef001a */ 	div	$zero,$a3,$t7
/*  f0e5da4:	00008812 */ 	mflo	$s1
/*  f0e5da8:	15e00002 */ 	bnez	$t7,.L0f0e5db4
/*  f0e5dac:	00000000 */ 	nop
/*  f0e5db0:	0007000d */ 	break	0x7
.L0f0e5db4:
/*  f0e5db4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5db8:	15e10004 */ 	bne	$t7,$at,.L0f0e5dcc
/*  f0e5dbc:	3c018000 */ 	lui	$at,0x8000
/*  f0e5dc0:	14e10002 */ 	bne	$a3,$at,.L0f0e5dcc
/*  f0e5dc4:	00000000 */ 	nop
/*  f0e5dc8:	0006000d */ 	break	0x6
.L0f0e5dcc:
/*  f0e5dcc:	1000003d */ 	b	.L0f0e5ec4
/*  f0e5dd0:	00000000 */ 	nop
/*  f0e5dd4:	00c0a025 */ 	or	$s4,$a2,$zero
.L0f0e5dd8:
/*  f0e5dd8:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0e5ddc:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e5de0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5de4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e5de8:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f0e5dec:	00d4082a */ 	slt	$at,$a2,$s4
.L0f0e5df0:
/*  f0e5df0:	10200018 */ 	beqz	$at,.L0f0e5e54
/*  f0e5df4:	3c038007 */ 	lui	$v1,%hi(g_LineHeight)
/*  f0e5df8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0e5dfc:	8e790010 */ 	lw	$t9,0x10($s3)
/*  f0e5e00:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5e04:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5e08:	0320f809 */ 	jalr	$t9
/*  f0e5e0c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e5e10:	3c038007 */ 	lui	$v1,%hi(g_LineHeight)
/*  f0e5e14:	8c6311a8 */ 	lw	$v1,%lo(g_LineHeight)($v1)
/*  f0e5e18:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0e5e1c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e5e20:	0203001a */ 	div	$zero,$s0,$v1
/*  f0e5e24:	00001012 */ 	mflo	$v0
/*  f0e5e28:	14600002 */ 	bnez	$v1,.L0f0e5e34
/*  f0e5e2c:	00000000 */ 	nop
/*  f0e5e30:	0007000d */ 	break	0x7
.L0f0e5e34:
/*  f0e5e34:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5e38:	14610004 */ 	bne	$v1,$at,.L0f0e5e4c
/*  f0e5e3c:	3c018000 */ 	lui	$at,0x8000
/*  f0e5e40:	16010002 */ 	bne	$s0,$at,.L0f0e5e4c
/*  f0e5e44:	00000000 */ 	nop
/*  f0e5e48:	0006000d */ 	break	0x6
.L0f0e5e4c:
/*  f0e5e4c:	1000000f */ 	b	.L0f0e5e8c
/*  f0e5e50:	00512821 */ 	addu	$a1,$v0,$s1
.L0f0e5e54:
/*  f0e5e54:	8c6311a8 */ 	lw	$v1,%lo(g_LineHeight)($v1)
/*  f0e5e58:	2404270f */ 	addiu	$a0,$zero,0x270f
/*  f0e5e5c:	0203001a */ 	div	$zero,$s0,$v1
/*  f0e5e60:	00001012 */ 	mflo	$v0
/*  f0e5e64:	14600002 */ 	bnez	$v1,.L0f0e5e70
/*  f0e5e68:	00000000 */ 	nop
/*  f0e5e6c:	0007000d */ 	break	0x7
.L0f0e5e70:
/*  f0e5e70:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5e74:	14610004 */ 	bne	$v1,$at,.L0f0e5e88
/*  f0e5e78:	3c018000 */ 	lui	$at,0x8000
/*  f0e5e7c:	16010002 */ 	bne	$s0,$at,.L0f0e5e88
/*  f0e5e80:	00000000 */ 	nop
/*  f0e5e84:	0006000d */ 	break	0x6
.L0f0e5e88:
/*  f0e5e88:	00512821 */ 	addu	$a1,$v0,$s1
.L0f0e5e8c:
/*  f0e5e8c:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0e5e90:	14200008 */ 	bnez	$at,.L0f0e5eb4
/*  f0e5e94:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e5e98:	00911023 */ 	subu	$v0,$a0,$s1
/*  f0e5e9c:	00430019 */ 	multu	$v0,$v1
/*  f0e5ea0:	02228821 */ 	addu	$s1,$s1,$v0
/*  f0e5ea4:	0000c012 */ 	mflo	$t8
/*  f0e5ea8:	02188023 */ 	subu	$s0,$s0,$t8
/*  f0e5eac:	10000003 */ 	b	.L0f0e5ebc
/*  f0e5eb0:	2610fff5 */ 	addiu	$s0,$s0,-11
.L0f0e5eb4:
/*  f0e5eb4:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e5eb8:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0e5ebc:
/*  f0e5ebc:	5240ffcc */ 	beqzl	$s2,.L0f0e5df0
/*  f0e5ec0:	00d4082a */ 	slt	$at,$a2,$s4
.L0f0e5ec4:
/*  f0e5ec4:	06230003 */ 	bgezl	$s1,.L0f0e5ed4
/*  f0e5ec8:	02201025 */ 	or	$v0,$s1,$zero
/*  f0e5ecc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5ed0:	02201025 */ 	or	$v0,$s1,$zero
.L0f0e5ed4:
/*  f0e5ed4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e5ed8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e5edc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e5ee0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0e5ee4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0e5ee8:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0e5eec:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0e5ef0:	03e00008 */ 	jr	$ra
/*  f0e5ef4:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0e5ef8
/*  f0e5ef8:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0e5efc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e5f00:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0e5f04:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0e5f08:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0e5f0c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0e5f10:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e5f14:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e5f18:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0e5f1c:	8caf0010 */ 	lw	$t7,0x10($a1)
/*  f0e5f20:	0004a400 */ 	sll	$s4,$a0,0x10
/*  f0e5f24:	00147403 */ 	sra	$t6,$s4,0x10
/*  f0e5f28:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0e5f2c:	15e00003 */ 	bnez	$t7,.L0f0e5f3c
/*  f0e5f30:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0e5f34:	10000037 */ 	b	.L0f0e6014
/*  f0e5f38:	00001025 */ 	or	$v0,$zero,$zero
.L0f0e5f3c:
/*  f0e5f3c:	06810002 */ 	bgez	$s4,.L0f0e5f48
/*  f0e5f40:	27b50040 */ 	addiu	$s5,$sp,0x40
/*  f0e5f44:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0e5f48:
/*  f0e5f48:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0e5f4c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0e5f50:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f0e5f54:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e5f58:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e5f5c:	0320f809 */ 	jalr	$t9
/*  f0e5f60:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5f64:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0e5f68:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5f6c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0e5f70:	14400008 */ 	bnez	$v0,.L0f0e5f94
/*  f0e5f74:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e5f78:	3c188007 */ 	lui	$t8,%hi(g_LineHeight)
/*  f0e5f7c:	8f1811a8 */ 	lw	$t8,%lo(g_LineHeight)($t8)
/*  f0e5f80:	02980019 */ 	multu	$s4,$t8
/*  f0e5f84:	00001012 */ 	mflo	$v0
/*  f0e5f88:	00024400 */ 	sll	$t0,$v0,0x10
/*  f0e5f8c:	10000021 */ 	b	.L0f0e6014
/*  f0e5f90:	00081403 */ 	sra	$v0,$t0,0x10
.L0f0e5f94:
/*  f0e5f94:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0e5f98:	1a600013 */ 	blez	$s3,.L0f0e5fe8
/*  f0e5f9c:	afa00040 */ 	sw	$zero,0x40($sp)
.L0f0e5fa0:
/*  f0e5fa0:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f0e5fa4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5fa8:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e5fac:	0320f809 */ 	jalr	$t9
/*  f0e5fb0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e5fb4:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0e5fb8:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0e5fbc:	028a082a */ 	slt	$at,$s4,$t2
/*  f0e5fc0:	54200004 */ 	bnezl	$at,.L0f0e5fd4
/*  f0e5fc4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e5fc8:	10000002 */ 	b	.L0f0e5fd4
/*  f0e5fcc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0e5fd0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0e5fd4:
/*  f0e5fd4:	16000004 */ 	bnez	$s0,.L0f0e5fe8
/*  f0e5fd8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e5fdc:	0053082a */ 	slt	$at,$v0,$s3
/*  f0e5fe0:	1420ffef */ 	bnez	$at,.L0f0e5fa0
/*  f0e5fe4:	afa20040 */ 	sw	$v0,0x40($sp)
.L0f0e5fe8:
/*  f0e5fe8:	3c0b8007 */ 	lui	$t3,%hi(g_LineHeight)
/*  f0e5fec:	8d6b11a8 */ 	lw	$t3,%lo(g_LineHeight)($t3)
/*  f0e5ff0:	00116880 */ 	sll	$t5,$s1,0x2
/*  f0e5ff4:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f0e5ff8:	028b0019 */ 	multu	$s4,$t3
/*  f0e5ffc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e6000:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f0e6004:	00006012 */ 	mflo	$t4
/*  f0e6008:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0e600c:	00027400 */ 	sll	$t6,$v0,0x10
/*  f0e6010:	000e1403 */ 	sra	$v0,$t6,0x10
.L0f0e6014:
/*  f0e6014:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e6018:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e601c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e6020:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0e6024:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0e6028:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0e602c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0e6030:	03e00008 */ 	jr	$ra
/*  f0e6034:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0e6038
/*  f0e6038:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0e603c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0e6040:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0e6044:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e6048:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0e604c:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0e6050:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e6054:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0e6058:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e605c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e6060:	c6240040 */ 	lwc1	$f4,0x40($s1)
/*  f0e6064:	3c087f1b */ 	lui	$t0,%hi(g_MenuColourPalettes)
/*  f0e6068:	25081fb0 */ 	addiu	$t0,$t0,%lo(g_MenuColourPalettes)
/*  f0e606c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e6070:	00000000 */ 	nop
/*  f0e6074:	4502000a */ 	bc1fl	.L0f0e60a0
/*  f0e6078:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0e607c:	922e003c */ 	lbu	$t6,0x3c($s1)
/*  f0e6080:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x2c)
/*  f0e6084:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0e6088:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0e608c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0e6090:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f0e6094:	10000010 */ 	b	.L0f0e60d8
/*  f0e6098:	8e101fdc */ 	lw	$s0,%lo(g_MenuColourPalettes+0x2c)($s0)
/*  f0e609c:	9238003d */ 	lbu	$t8,0x3d($s1)
.L0f0e60a0:
/*  f0e60a0:	922a003c */ 	lbu	$t2,0x3c($s1)
/*  f0e60a4:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e60a8:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e60ac:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e60b0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e60b4:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e60b8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e60bc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e60c0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0e60c4:	01686021 */ 	addu	$t4,$t3,$t0
/*  f0e60c8:	8d85002c */ 	lw	$a1,0x2c($t4)
/*  f0e60cc:	0fc01a40 */ 	jal	colourBlend
/*  f0e60d0:	8d24002c */ 	lw	$a0,0x2c($t1)
/*  f0e60d4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e60d8:
/*  f0e60d8:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f0e60dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e60e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e60e4:	11a00007 */ 	beqz	$t5,.L0f0e6104
/*  f0e60e8:	00000000 */ 	nop
/*  f0e60ec:	0fc01a40 */ 	jal	colourBlend
/*  f0e60f0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e60f4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e60f8:	00417024 */ 	and	$t6,$v0,$at
/*  f0e60fc:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0e6100:	01cf8025 */ 	or	$s0,$t6,$t7
.L0f0e6104:
/*  f0e6104:	0fc54de0 */ 	jal	func0f153780
/*  f0e6108:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e610c:	87a50056 */ 	lh	$a1,0x56($sp)
/*  f0e6110:	87a6005a */ 	lh	$a2,0x5a($sp)
/*  f0e6114:	87a90066 */ 	lh	$t1,0x66($sp)
/*  f0e6118:	87ab0062 */ 	lh	$t3,0x62($sp)
/*  f0e611c:	87b9005e */ 	lh	$t9,0x5e($sp)
/*  f0e6120:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f0e6124:	00c95021 */ 	addu	$t2,$a2,$t1
/*  f0e6128:	00ab4021 */ 	addu	$t0,$a1,$t3
/*  f0e612c:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e6130:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6134:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e6138:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e613c:	0fc38653 */ 	jal	func0f0e194c
/*  f0e6140:	00b93821 */ 	addu	$a3,$a1,$t9
/*  f0e6144:	0fc54d8a */ 	jal	func0f153628
/*  f0e6148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e614c:	87ad0056 */ 	lh	$t5,0x56($sp)
/*  f0e6150:	87af005a */ 	lh	$t7,0x5a($sp)
/*  f0e6154:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0e6158:	25ae0003 */ 	addiu	$t6,$t5,0x3
/*  f0e615c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0e6160:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f0e6164:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f0e6168:	c6280040 */ 	lwc1	$f8,0x40($s1)
/*  f0e616c:	44805000 */ 	mtc1	$zero,$f10
/*  f0e6170:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0e6174:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0e6178:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0e617c:	00000000 */ 	nop
/*  f0e6180:	4502000a */ 	bc1fl	.L0f0e61ac
/*  f0e6184:	922a003d */ 	lbu	$t2,0x3d($s1)
/*  f0e6188:	9238003c */ 	lbu	$t8,0x3c($s1)
/*  f0e618c:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x30)
/*  f0e6190:	00184900 */ 	sll	$t1,$t8,0x4
/*  f0e6194:	01384823 */ 	subu	$t1,$t1,$t8
/*  f0e6198:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0e619c:	02098021 */ 	addu	$s0,$s0,$t1
/*  f0e61a0:	10000010 */ 	b	.L0f0e61e4
/*  f0e61a4:	8e101fe0 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x30)($s0)
/*  f0e61a8:	922a003d */ 	lbu	$t2,0x3d($s1)
.L0f0e61ac:
/*  f0e61ac:	922c003c */ 	lbu	$t4,0x3c($s1)
/*  f0e61b0:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e61b4:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e61b8:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e61bc:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e61c0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e61c4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e61c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e61cc:	004b4021 */ 	addu	$t0,$v0,$t3
/*  f0e61d0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0e61d4:	8dc50030 */ 	lw	$a1,0x30($t6)
/*  f0e61d8:	0fc01a40 */ 	jal	colourBlend
/*  f0e61dc:	8d040030 */ 	lw	$a0,0x30($t0)
/*  f0e61e0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e61e4:
/*  f0e61e4:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0e61e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e61ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e61f0:	51e00008 */ 	beqzl	$t7,.L0f0e6214
/*  f0e61f4:	9222003c */ 	lbu	$v0,0x3c($s1)
/*  f0e61f8:	0fc01a40 */ 	jal	colourBlend
/*  f0e61fc:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e6200:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6204:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e6208:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0e620c:	03388025 */ 	or	$s0,$t9,$t8
/*  f0e6210:	9222003c */ 	lbu	$v0,0x3c($s1)
.L0f0e6214:
/*  f0e6214:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x30)
/*  f0e6218:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x30)
/*  f0e621c:	00024900 */ 	sll	$t1,$v0,0x4
/*  f0e6220:	01224823 */ 	subu	$t1,$t1,$v0
/*  f0e6224:	00091080 */ 	sll	$v0,$t1,0x2
/*  f0e6228:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e622c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6230:	8ca52148 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x30)($a1)
/*  f0e6234:	0fc54f8e */ 	jal	func0f153e38
/*  f0e6238:	8c8422b0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x30)($a0)
/*  f0e623c:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicSm)
/*  f0e6240:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0e6244:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0e6248:	8d4afb10 */ 	lw	$t2,%lo(g_CharsHandelGothicSm)($t2)
/*  f0e624c:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f0e6250:	87ac0066 */ 	lh	$t4,0x66($sp)
/*  f0e6254:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e6258:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0e625c:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0e6260:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0e6264:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e6268:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e626c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6270:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e6274:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6278:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0e627c:	0fc5580f */ 	jal	textRenderProjected
/*  f0e6280:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e6284:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e6288:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0e628c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0e6290:	03e00008 */ 	jr	$ra
/*  f0e6294:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#else
GLOBAL_ASM(
glabel func0f0e6038
/*  f0e34c8:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0e34cc:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0e34d0:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0e34d4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e34d8:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0e34dc:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0e34e0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e34e4:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0e34e8:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e34ec:	44803000 */ 	mtc1	$zero,$f6
/*  f0e34f0:	c6240040 */ 	lwc1	$f4,0x40($s1)
/*  f0e34f4:	3c087f1b */ 	lui	$t0,0x7f1b
/*  f0e34f8:	2508c2e0 */ 	addiu	$t0,$t0,-15648
/*  f0e34fc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e3500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3504:	4502000a */ 	bc1fl	.NB0f0e3530
/*  f0e3508:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0e350c:	922e003c */ 	lbu	$t6,0x3c($s1)
/*  f0e3510:	3c107f1b */ 	lui	$s0,0x7f1b
/*  f0e3514:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0e3518:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0e351c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0e3520:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f0e3524:	10000010 */ 	beqz	$zero,.NB0f0e3568
/*  f0e3528:	8e10c30c */ 	lw	$s0,-0x3cf4($s0)
/*  f0e352c:	9238003d */ 	lbu	$t8,0x3d($s1)
.NB0f0e3530:
/*  f0e3530:	922a003c */ 	lbu	$t2,0x3c($s1)
/*  f0e3534:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e3538:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e353c:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e3540:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e3544:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e3548:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e354c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e3550:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0e3554:	01686021 */ 	addu	$t4,$t3,$t0
/*  f0e3558:	8d85002c */ 	lw	$a1,0x2c($t4)
/*  f0e355c:	0fc01990 */ 	jal	colourBlend
/*  f0e3560:	8d24002c */ 	lw	$a0,0x2c($t1)
/*  f0e3564:	00408025 */ 	or	$s0,$v0,$zero
.NB0f0e3568:
/*  f0e3568:	8e2d000c */ 	lw	$t5,0xc($s1)
/*  f0e356c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e3570:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e3574:	11a00003 */ 	beqz	$t5,.NB0f0e3584
/*  f0e3578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e357c:	0fc01990 */ 	jal	colourBlend
/*  f0e3580:	2406002c */ 	addiu	$a2,$zero,0x2c
.NB0f0e3584:
/*  f0e3584:	0fc537a0 */ 	jal	func0f153780
/*  f0e3588:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e358c:	87a50056 */ 	lh	$a1,0x56($sp)
/*  f0e3590:	87a6005a */ 	lh	$a2,0x5a($sp)
/*  f0e3594:	87b80066 */ 	lh	$t8,0x66($sp)
/*  f0e3598:	87a90062 */ 	lh	$t1,0x62($sp)
/*  f0e359c:	87af005e */ 	lh	$t7,0x5e($sp)
/*  f0e35a0:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f0e35a4:	00a95021 */ 	addu	$t2,$a1,$t1
/*  f0e35a8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e35ac:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e35b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e35b4:	0fc37b63 */ 	jal	func0f0e194c
/*  f0e35b8:	00af3821 */ 	addu	$a3,$a1,$t7
/*  f0e35bc:	0fc5374a */ 	jal	func0f153628
/*  f0e35c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e35c4:	87ab0056 */ 	lh	$t3,0x56($sp)
/*  f0e35c8:	87ac005a */ 	lh	$t4,0x5a($sp)
/*  f0e35cc:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f0e35d0:	25680003 */ 	addiu	$t0,$t3,0x3
/*  f0e35d4:	258d0002 */ 	addiu	$t5,$t4,0x2
/*  f0e35d8:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0e35dc:	afad0048 */ 	sw	$t5,0x48($sp)
/*  f0e35e0:	c6280040 */ 	lwc1	$f8,0x40($s1)
/*  f0e35e4:	44805000 */ 	mtc1	$zero,$f10
/*  f0e35e8:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0e35ec:	2442c2e0 */ 	addiu	$v0,$v0,-15648
/*  f0e35f0:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0e35f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e35f8:	4502000a */ 	bc1fl	.NB0f0e3624
/*  f0e35fc:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0e3600:	922f003c */ 	lbu	$t7,0x3c($s1)
/*  f0e3604:	3c107f1b */ 	lui	$s0,0x7f1b
/*  f0e3608:	000f7100 */ 	sll	$t6,$t7,0x4
/*  f0e360c:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f0e3610:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0e3614:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f0e3618:	10000010 */ 	beqz	$zero,.NB0f0e365c
/*  f0e361c:	8e10c310 */ 	lw	$s0,-0x3cf0($s0)
/*  f0e3620:	9238003d */ 	lbu	$t8,0x3d($s1)
.NB0f0e3624:
/*  f0e3624:	922a003c */ 	lbu	$t2,0x3c($s1)
/*  f0e3628:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0e362c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e3630:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e3634:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e3638:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0e363c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0e3640:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e3644:	00594821 */ 	addu	$t1,$v0,$t9
/*  f0e3648:	004b4021 */ 	addu	$t0,$v0,$t3
/*  f0e364c:	8d050030 */ 	lw	$a1,0x30($t0)
/*  f0e3650:	0fc01990 */ 	jal	colourBlend
/*  f0e3654:	8d240030 */ 	lw	$a0,0x30($t1)
/*  f0e3658:	00408025 */ 	or	$s0,$v0,$zero
.NB0f0e365c:
/*  f0e365c:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f0e3660:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e3664:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e3668:	51800008 */ 	beqzl	$t4,.NB0f0e368c
/*  f0e366c:	9222003c */ 	lbu	$v0,0x3c($s1)
/*  f0e3670:	0fc01990 */ 	jal	colourBlend
/*  f0e3674:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e3678:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e367c:	00416824 */ 	and	$t5,$v0,$at
/*  f0e3680:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0e3684:	01af8025 */ 	or	$s0,$t5,$t7
/*  f0e3688:	9222003c */ 	lbu	$v0,0x3c($s1)
.NB0f0e368c:
/*  f0e368c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e3690:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e3694:	00027100 */ 	sll	$t6,$v0,0x4
/*  f0e3698:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0e369c:	000e1080 */ 	sll	$v0,$t6,0x2
/*  f0e36a0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e36a4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e36a8:	8ca5c478 */ 	lw	$a1,-0x3b88($a1)
/*  f0e36ac:	0fc53925 */ 	jal	func0f153e38
/*  f0e36b0:	8c84c5e0 */ 	lw	$a0,-0x3a20($a0)
/*  f0e36b4:	3c188008 */ 	lui	$t8,0x8008
/*  f0e36b8:	3c198008 */ 	lui	$t9,0x8008
/*  f0e36bc:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f0e36c0:	8f182370 */ 	lw	$t8,0x2370($t8)
/*  f0e36c4:	87a9005e */ 	lh	$t1,0x5e($sp)
/*  f0e36c8:	87aa0066 */ 	lh	$t2,0x66($sp)
/*  f0e36cc:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0e36d0:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0e36d4:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0e36d8:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0e36dc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e36e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e36e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e36e8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e36ec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e36f0:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e36f4:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e36f8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0e36fc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e3700:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0e3704:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0e3708:	03e00008 */ 	jr	$ra
/*  f0e370c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#endif

Gfx *menuRenderOverlayList(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2)
{
	gDPFillRectangleScaled(gdl++, x, y, x + x2, y + y2);
	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuRenderItemList
/*  f0e6328:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f0e632c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0e6330:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0e6334:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0e6338:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0e633c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0e6340:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0e6344:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0e6348:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0e634c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0e6350:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e6354:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0e6358:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f0e635c:	3c0a8008 */ 	lui	$t2,%hi(g_FontHandelGothicSm)
/*  f0e6360:	afae016c */ 	sw	$t6,0x16c($sp)
/*  f0e6364:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f0e6368:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e636c:	8d4afb0c */ 	lw	$t2,%lo(g_FontHandelGothicSm)($t2)
/*  f0e6370:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e6374:	2419270f */ 	addiu	$t9,$zero,0x270f
/*  f0e6378:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0e637c:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0e6380:	afb900fc */ 	sw	$t9,0xfc($sp)
/*  f0e6384:	a3a000ed */ 	sb	$zero,0xed($sp)
/*  f0e6388:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0e638c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f0e6390:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0e6394:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e6398:	00809025 */ 	or	$s2,$a0,$zero
/*  f0e639c:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f0e63a0:	000c6a80 */ 	sll	$t5,$t4,0xa
/*  f0e63a4:	05a3000b */ 	bgezl	$t5,.L0f0e63d4
/*  f0e63a8:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f0e63ac:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e63b0:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e63b4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e63b8:	0320f809 */ 	jalr	$t9
/*  f0e63bc:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0e63c0:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f0e63c4:	3c018007 */ 	lui	$at,%hi(g_LineHeight)
/*  f0e63c8:	10000004 */ 	b	.L0f0e63dc
/*  f0e63cc:	ac2e11a8 */ 	sw	$t6,%lo(g_LineHeight)($at)
/*  f0e63d0:	240f000b */ 	addiu	$t7,$zero,0xb
.L0f0e63d4:
/*  f0e63d4:	3c018007 */ 	lui	$at,%hi(g_LineHeight)
/*  f0e63d8:	ac2f11a8 */ 	sw	$t7,%lo(g_LineHeight)($at)
.L0f0e63dc:
/*  f0e63dc:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*  f0e63e0:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0e63e4:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0e63e8:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0e63ec:	8705001e */ 	lh	$a1,0x1e($t8)
/*  f0e63f0:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0e63f4:	05810002 */ 	bgez	$t4,.L0f0e6400
/*  f0e63f8:	00000000 */ 	nop
/*  f0e63fc:	86250004 */ 	lh	$a1,0x4($s1)
.L0f0e6400:
/*  f0e6400:	8c63fac0 */ 	lw	$v1,%lo(g_ScaleX)($v1)
/*  f0e6404:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e6408:	3c028007 */ 	lui	$v0,%hi(g_ScissorX1)
/*  f0e640c:	24421190 */ 	addiu	$v0,$v0,%lo(g_ScissorX1)
/*  f0e6410:	01a30019 */ 	multu	$t5,$v1
/*  f0e6414:	3c178007 */ 	lui	$s7,%hi(g_ScissorX2)
/*  f0e6418:	26f71194 */ 	addiu	$s7,$s7,%lo(g_ScissorX2)
/*  f0e641c:	3c048007 */ 	lui	$a0,%hi(g_ScissorY1)
/*  f0e6420:	24841198 */ 	addiu	$a0,$a0,%lo(g_ScissorY1)
/*  f0e6424:	3c1e8007 */ 	lui	$s8,%hi(g_ScissorY2)
/*  f0e6428:	27de119c */ 	addiu	$s8,$s8,%lo(g_ScissorY2)
/*  f0e642c:	0000c812 */ 	mflo	$t9
/*  f0e6430:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0e6434:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0e6438:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0e643c:	01e30019 */ 	multu	$t7,$v1
/*  f0e6440:	0000c012 */ 	mflo	$t8
/*  f0e6444:	aef80000 */ 	sw	$t8,0x0($s7)
/*  f0e6448:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e644c:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f0e6450:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e6454:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e6458:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0e645c:	07210002 */ 	bgez	$t9,.L0f0e6468
/*  f0e6460:	afcd0000 */ 	sw	$t5,0x0($s8)
/*  f0e6464:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f0e6468:
/*  f0e6468:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e646c:	05c30003 */ 	bgezl	$t6,.L0f0e647c
/*  f0e6470:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0e6474:	aee00000 */ 	sw	$zero,0x0($s7)
/*  f0e6478:	8c8f0000 */ 	lw	$t7,0x0($a0)
.L0f0e647c:
/*  f0e647c:	05e30003 */ 	bgezl	$t7,.L0f0e648c
/*  f0e6480:	8fd80000 */ 	lw	$t8,0x0($s8)
/*  f0e6484:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0e6488:	8fd80000 */ 	lw	$t8,0x0($s8)
.L0f0e648c:
/*  f0e648c:	07010002 */ 	bgez	$t8,.L0f0e6498
/*  f0e6490:	00000000 */ 	nop
/*  f0e6494:	afc00000 */ 	sw	$zero,0x0($s8)
.L0f0e6498:
/*  f0e6498:	0c002ef1 */ 	jal	viGetBufX
/*  f0e649c:	a7a500ee */ 	sh	$a1,0xee($sp)
/*  f0e64a0:	3c0a8007 */ 	lui	$t2,%hi(g_ScissorX1)
/*  f0e64a4:	8d4a1190 */ 	lw	$t2,%lo(g_ScissorX1)($t2)
/*  f0e64a8:	004a082a */ 	slt	$at,$v0,$t2
/*  f0e64ac:	10200005 */ 	beqz	$at,.L0f0e64c4
/*  f0e64b0:	00000000 */ 	nop
/*  f0e64b4:	0c002ef1 */ 	jal	viGetBufX
/*  f0e64b8:	00000000 */ 	nop
/*  f0e64bc:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0e64c0:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0e64c4:
/*  f0e64c4:	0c002ef1 */ 	jal	viGetBufX
/*  f0e64c8:	00000000 */ 	nop
/*  f0e64cc:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f0e64d0:	004b082a */ 	slt	$at,$v0,$t3
/*  f0e64d4:	10200004 */ 	beqz	$at,.L0f0e64e8
/*  f0e64d8:	00000000 */ 	nop
/*  f0e64dc:	0c002ef1 */ 	jal	viGetBufX
/*  f0e64e0:	00000000 */ 	nop
/*  f0e64e4:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e64e8:
/*  f0e64e8:	0c002ef5 */ 	jal	viGetBufY
/*  f0e64ec:	00000000 */ 	nop
/*  f0e64f0:	3c0c8007 */ 	lui	$t4,%hi(g_ScissorY1)
/*  f0e64f4:	8d8c1198 */ 	lw	$t4,%lo(g_ScissorY1)($t4)
/*  f0e64f8:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e64fc:	10200005 */ 	beqz	$at,.L0f0e6514
/*  f0e6500:	00000000 */ 	nop
/*  f0e6504:	0c002ef5 */ 	jal	viGetBufY
/*  f0e6508:	00000000 */ 	nop
/*  f0e650c:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e6510:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0e6514:
/*  f0e6514:	0c002ef5 */ 	jal	viGetBufY
/*  f0e6518:	00000000 */ 	nop
/*  f0e651c:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e6520:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e6524:	10200005 */ 	beqz	$at,.L0f0e653c
/*  f0e6528:	00000000 */ 	nop
/*  f0e652c:	0c002ef5 */ 	jal	viGetBufY
/*  f0e6530:	00000000 */ 	nop
/*  f0e6534:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e6538:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e653c:
/*  f0e653c:	3c098007 */ 	lui	$t1,%hi(g_ScissorX1)
/*  f0e6540:	8d291190 */ 	lw	$t1,%lo(g_ScissorX1)($t1)
/*  f0e6544:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f0e6548:	3c088007 */ 	lui	$t0,%hi(g_ScissorY1)
/*  f0e654c:	44892000 */ 	mtc1	$t1,$f4
/*  f0e6550:	01a9082a */ 	slt	$at,$t5,$t1
/*  f0e6554:	10200002 */ 	beqz	$at,.L0f0e6560
/*  f0e6558:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e655c:	aee90000 */ 	sw	$t1,0x0($s7)
.L0f0e6560:
/*  f0e6560:	8d081198 */ 	lw	$t0,%lo(g_ScissorY1)($t0)
/*  f0e6564:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e6568:	50200003 */ 	beqzl	$at,.L0f0e6578
/*  f0e656c:	44888000 */ 	mtc1	$t0,$f16
/*  f0e6570:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e6574:	44888000 */ 	mtc1	$t0,$f16
.L0f0e6578:
/*  f0e6578:	3c014080 */ 	lui	$at,0x4080
/*  f0e657c:	44810000 */ 	mtc1	$at,$f0
/*  f0e6580:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e6584:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e6588:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e658c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6590:	3c058007 */ 	lui	$a1,%hi(g_LineHeight)
/*  f0e6594:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e6598:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0e659c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e65a0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e65a4:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e65a8:	440c3000 */ 	mfc1	$t4,$f6
/*  f0e65ac:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0e65b0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e65b4:	03015025 */ 	or	$t2,$t8,$at
/*  f0e65b8:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0e65bc:	014dc825 */ 	or	$t9,$t2,$t5
/*  f0e65c0:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0e65c4:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e65c8:	8fca0000 */ 	lw	$t2,0x0($s8)
/*  f0e65cc:	448e4000 */ 	mtc1	$t6,$f8
/*  f0e65d0:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e65d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e65d8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e65dc:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0e65e0:	00000000 */ 	nop
/*  f0e65e4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e65e8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e65ec:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e65f0:	44189000 */ 	mfc1	$t8,$f18
/*  f0e65f4:	44195000 */ 	mfc1	$t9,$f10
/*  f0e65f8:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f0e65fc:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e6600:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f0e6604:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0e6608:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e660c:	86220006 */ 	lh	$v0,0x6($s1)
/*  f0e6610:	8ca511a8 */ 	lw	$a1,%lo(g_LineHeight)($a1)
/*  f0e6614:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e6618:	04410003 */ 	bgez	$v0,.L0f0e6628
/*  f0e661c:	0002b043 */ 	sra	$s6,$v0,0x1
/*  f0e6620:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0e6624:	0001b043 */ 	sra	$s6,$at,0x1
.L0f0e6628:
/*  f0e6628:	02c5001a */ 	div	$zero,$s6,$a1
/*  f0e662c:	14a00002 */ 	bnez	$a1,.L0f0e6638
/*  f0e6630:	00000000 */ 	nop
/*  f0e6634:	0007000d */ 	break	0x7
.L0f0e6638:
/*  f0e6638:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e663c:	14a10004 */ 	bne	$a1,$at,.L0f0e6650
/*  f0e6640:	3c018000 */ 	lui	$at,0x8000
/*  f0e6644:	16c10002 */ 	bne	$s6,$at,.L0f0e6650
/*  f0e6648:	00000000 */ 	nop
/*  f0e664c:	0006000d */ 	break	0x6
.L0f0e6650:
/*  f0e6650:	0000b012 */ 	mflo	$s6
/*  f0e6654:	a7020006 */ 	sh	$v0,0x6($t8)
/*  f0e6658:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e665c:	02c50019 */ 	multu	$s6,$a1
/*  f0e6660:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e6664:	90e30000 */ 	lbu	$v1,0x0($a3)
/*  f0e6668:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e666c:	0000b012 */ 	mflo	$s6
/*  f0e6670:	10610004 */ 	beq	$v1,$at,.L0f0e6684
/*  f0e6674:	00000000 */ 	nop
/*  f0e6678:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e667c:	54610050 */ 	bnel	$v1,$at,.L0f0e67c0
/*  f0e6680:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e6684:
/*  f0e6684:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6688:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f0e668c:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6690:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e6694:	00ca6821 */ 	addu	$t5,$a2,$t2
/*  f0e6698:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e669c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e66a0:	0fc3859a */ 	jal	func0f0e1668
/*  f0e66a4:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e66a8:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e66ac:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e66b0:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e66b4:	240e007f */ 	addiu	$t6,$zero,0x7f
/*  f0e66b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e66bc:	2418000f */ 	addiu	$t8,$zero,0xf
/*  f0e66c0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e66c4:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e66c8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e66cc:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e66d0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e66d4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e66d8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e66dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e66e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e66e4:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e66e8:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f0e66ec:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0e66f0:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0e66f4:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e66f8:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e66fc:	240e007f */ 	addiu	$t6,$zero,0x7f
/*  f0e6700:	240f000f */ 	addiu	$t7,$zero,0xf
/*  f0e6704:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e6708:	014d2821 */ 	addu	$a1,$t2,$t5
/*  f0e670c:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e6710:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6714:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e6718:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0e671c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e6720:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e6724:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e6728:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e672c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6730:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6734:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6738:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e673c:	240d007f */ 	addiu	$t5,$zero,0x7f
/*  f0e6740:	2419000f */ 	addiu	$t9,$zero,0xf
/*  f0e6744:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e6748:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e674c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6750:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e6754:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e6758:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e675c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e6760:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6764:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e6768:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e676c:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e6770:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e6774:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0e6778:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e677c:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0e6780:	240a007f */ 	addiu	$t2,$zero,0x7f
/*  f0e6784:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f0e6788:	24cb0001 */ 	addiu	$t3,$a2,0x1
/*  f0e678c:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f0e6790:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e6794:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6798:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e679c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e67a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e67a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e67a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e67ac:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e67b0:	02183821 */ 	addu	$a3,$s0,$t8
/*  f0e67b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e67b8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e67bc:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e67c0:
/*  f0e67c0:	57200004 */ 	bnezl	$t9,.L0f0e67d4
/*  f0e67c4:	afa0015c */ 	sw	$zero,0x15c($sp)
/*  f0e67c8:	10000369 */ 	b	.L0f0e7570
/*  f0e67cc:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e67d0:	afa0015c */ 	sw	$zero,0x15c($sp)
.L0f0e67d4:
/*  f0e67d4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e67d8:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e67dc:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e67e0:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e67e4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e67e8:	0320f809 */ 	jalr	$t9
/*  f0e67ec:	00000000 */ 	nop
/*  f0e67f0:	8fa8015c */ 	lw	$t0,0x15c($sp)
/*  f0e67f4:	3c010001 */ 	lui	$at,0x1
/*  f0e67f8:	0101082b */ 	sltu	$at,$t0,$at
/*  f0e67fc:	54200003 */ 	bnezl	$at,.L0f0e680c
/*  f0e6800:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0e6804:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0e6808:	862c0002 */ 	lh	$t4,0x2($s1)
.L0f0e680c:
/*  f0e680c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e6810:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e6814:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f0e6818:	afae0104 */ 	sw	$t6,0x104($sp)
/*  f0e681c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6820:	afa800f0 */ 	sw	$t0,0xf0($sp)
/*  f0e6824:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6828:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e682c:	0320f809 */ 	jalr	$t9
/*  f0e6830:	00000000 */ 	nop
/*  f0e6834:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f0e6838:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e683c:	afaf0108 */ 	sw	$t7,0x108($sp)
/*  f0e6840:	870b0000 */ 	lh	$t3,0x0($t8)
/*  f0e6844:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e6848:	01762023 */ 	subu	$a0,$t3,$s6
/*  f0e684c:	0fc3974b */ 	jal	func0f0e5d2c
/*  f0e6850:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e6854:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e6858:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e685c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6860:	01506821 */ 	addu	$t5,$t2,$s0
/*  f0e6864:	0fc54d8a */ 	jal	func0f153628
/*  f0e6868:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f0e686c:	00152400 */ 	sll	$a0,$s5,0x10
/*  f0e6870:	afa00160 */ 	sw	$zero,0x160($sp)
/*  f0e6874:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0e6878:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e687c:	02a09825 */ 	or	$s3,$s5,$zero
/*  f0e6880:	01802025 */ 	or	$a0,$t4,$zero
/*  f0e6884:	0fc397be */ 	jal	func0f0e5ef8
/*  f0e6888:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e688c:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6890:	00567021 */ 	addu	$t6,$v0,$s6
/*  f0e6894:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e6898:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f0e689c:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e68a0:	afa00158 */ 	sw	$zero,0x158($sp)
/*  f0e68a4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e68a8:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e68ac:	01cfa023 */ 	subu	$s4,$t6,$t7
/*  f0e68b0:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e68b4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e68b8:	0320f809 */ 	jalr	$t9
/*  f0e68bc:	00000000 */ 	nop
/*  f0e68c0:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e68c4:	8fa3014c */ 	lw	$v1,0x14c($sp)
/*  f0e68c8:	1b0002d7 */ 	blez	$t8,.L0f0e7428
/*  f0e68cc:	afa30100 */ 	sw	$v1,0x100($sp)
/*  f0e68d0:	1060005d */ 	beqz	$v1,.L0f0e6a48
/*  f0e68d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e68d8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e68dc:	afa000fc */ 	sw	$zero,0xfc($sp)
/*  f0e68e0:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e68e4:	1860001a */ 	blez	$v1,.L0f0e6950
/*  f0e68e8:	afa00150 */ 	sw	$zero,0x150($sp)
/*  f0e68ec:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0e68f0:
/*  f0e68f0:	afa800c8 */ 	sw	$t0,0xc8($sp)
/*  f0e68f4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e68f8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e68fc:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6900:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6904:	0320f809 */ 	jalr	$t9
/*  f0e6908:	00000000 */ 	nop
/*  f0e690c:	8fa30154 */ 	lw	$v1,0x154($sp)
/*  f0e6910:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f0e6914:	02a3082a */ 	slt	$at,$s5,$v1
/*  f0e6918:	54200007 */ 	bnezl	$at,.L0f0e6938
/*  f0e691c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e6920:	8fa8014c */ 	lw	$t0,0x14c($sp)
/*  f0e6924:	afa300fc */ 	sw	$v1,0xfc($sp)
/*  f0e6928:	250d0001 */ 	addiu	$t5,$t0,0x1
/*  f0e692c:	10000002 */ 	b	.L0f0e6938
/*  f0e6930:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f0e6934:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0e6938:
/*  f0e6938:	16000005 */ 	bnez	$s0,.L0f0e6950
/*  f0e693c:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0e6940:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0e6944:	018e082a */ 	slt	$at,$t4,$t6
/*  f0e6948:	5420ffe9 */ 	bnezl	$at,.L0f0e68f0
/*  f0e694c:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0e6950:
/*  f0e6950:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e6954:	8faf0158 */ 	lw	$t7,0x158($sp)
/*  f0e6958:	afa8013c */ 	sw	$t0,0x13c($sp)
/*  f0e695c:	0315082a */ 	slt	$at,$t8,$s5
/*  f0e6960:	afa00140 */ 	sw	$zero,0x140($sp)
/*  f0e6964:	14200004 */ 	bnez	$at,.L0f0e6978
/*  f0e6968:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f0e696c:	2a81000b */ 	slti	$at,$s4,0xb
/*  f0e6970:	50200036 */ 	beqzl	$at,.L0f0e6a4c
/*  f0e6974:	8faa00fc */ 	lw	$t2,0xfc($sp)
.L0f0e6978:
/*  f0e6978:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e697c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e6980:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e6984:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6988:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e698c:	0320f809 */ 	jalr	$t9
/*  f0e6990:	00000000 */ 	nop
/*  f0e6994:	3c0b8007 */ 	lui	$t3,%hi(g_LineHeight)
/*  f0e6998:	8d6b11a8 */ 	lw	$t3,%lo(g_LineHeight)($t3)
/*  f0e699c:	87ad00ee */ 	lh	$t5,0xee($sp)
/*  f0e69a0:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f0e69a4:	028b5021 */ 	addu	$t2,$s4,$t3
/*  f0e69a8:	5940000f */ 	blezl	$t2,.L0f0e69e8
/*  f0e69ac:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f0e69b0:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e69b4:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e69b8:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e69bc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e69c0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e69c4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e69c8:	8e2e0010 */ 	lw	$t6,0x10($s1)
/*  f0e69cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e69d0:	0fc3980e */ 	jal	func0f0e6038
/*  f0e69d4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e69d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e69dc:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e69e0:	a3af00ed */ 	sb	$t7,0xed($sp)
/*  f0e69e4:	8fb80104 */ 	lw	$t8,0x104($sp)
.L0f0e69e8:
/*  f0e69e8:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e69ec:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e69f0:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e69f4:	2719000b */ 	addiu	$t9,$t8,0xb
/*  f0e69f8:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f0e69fc:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e6a00:	afb90104 */ 	sw	$t9,0x104($sp)
/*  f0e6a04:	1020000e */ 	beqz	$at,.L0f0e6a40
/*  f0e6a08:	afaa013c */ 	sw	$t2,0x13c($sp)
/*  f0e6a0c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6a10:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e6a14:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6a18:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6a1c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6a20:	0320f809 */ 	jalr	$t9
/*  f0e6a24:	00000000 */ 	nop
/*  f0e6a28:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e6a2c:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6a30:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e6a34:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e6a38:	10000003 */ 	b	.L0f0e6a48
/*  f0e6a3c:	afae00fc */ 	sw	$t6,0xfc($sp)
.L0f0e6a40:
/*  f0e6a40:	240b270f */ 	addiu	$t3,$zero,0x270f
/*  f0e6a44:	afab00fc */ 	sw	$t3,0xfc($sp)
.L0f0e6a48:
/*  f0e6a48:	8faa00fc */ 	lw	$t2,0xfc($sp)
.L0f0e6a4c:
/*  f0e6a4c:	3c167f1b */ 	lui	$s6,%hi(g_MenuColourPalettes)
/*  f0e6a50:	26d61fb0 */ 	addiu	$s6,$s6,%lo(g_MenuColourPalettes)
/*  f0e6a54:	56aa0003 */ 	bnel	$s5,$t2,.L0f0e6a64
/*  f0e6a58:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e6a5c:	2694fff5 */ 	addiu	$s4,$s4,-11
/*  f0e6a60:	2415003c */ 	addiu	$s5,$zero,0x3c
.L0f0e6a64:
/*  f0e6a64:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e6a68:
/*  f0e6a68:	44809000 */ 	mtc1	$zero,$f18
/*  f0e6a6c:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e6a70:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e6a74:	00000000 */ 	nop
/*  f0e6a78:	45020008 */ 	bc1fl	.L0f0e6a9c
/*  f0e6a7c:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0e6a80:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0e6a84:	01b50019 */ 	multu	$t5,$s5
/*  f0e6a88:	00006012 */ 	mflo	$t4
/*  f0e6a8c:	02ccc821 */ 	addu	$t9,$s6,$t4
/*  f0e6a90:	1000000f */ 	b	.L0f0e6ad0
/*  f0e6a94:	8f300018 */ 	lw	$s0,0x18($t9)
/*  f0e6a98:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0e6a9c:
/*  f0e6a9c:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e6aa0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6aa4:	01d50019 */ 	multu	$t6,$s5
/*  f0e6aa8:	00007812 */ 	mflo	$t7
/*  f0e6aac:	02cfc021 */ 	addu	$t8,$s6,$t7
/*  f0e6ab0:	8f040018 */ 	lw	$a0,0x18($t8)
/*  f0e6ab4:	01750019 */ 	multu	$t3,$s5
/*  f0e6ab8:	00005012 */ 	mflo	$t2
/*  f0e6abc:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e6ac0:	0fc01a40 */ 	jal	colourBlend
/*  f0e6ac4:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0e6ac8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e6acc:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e6ad0:
/*  f0e6ad0:	8c6c000c */ 	lw	$t4,0xc($v1)
/*  f0e6ad4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e6adc:	51800009 */ 	beqzl	$t4,.L0f0e6b04
/*  f0e6ae0:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e6ae4:	0fc01a40 */ 	jal	colourBlend
/*  f0e6ae8:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e6aec:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6af0:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e6af4:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0e6af8:	032e8025 */ 	or	$s0,$t9,$t6
/*  f0e6afc:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6b00:	906f003c */ 	lbu	$t7,0x3c($v1)
.L0f0e6b04:
/*  f0e6b04:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e6b08:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e6b0c:	01f50019 */ 	multu	$t7,$s5
/*  f0e6b10:	00001012 */ 	mflo	$v0
/*  f0e6b14:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e6b18:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6b1c:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e6b20:	0fc54f8e */ 	jal	func0f153e38
/*  f0e6b24:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e6b28:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e6b2c:	8faa0108 */ 	lw	$t2,0x108($sp)
/*  f0e6b30:	1678003f */ 	bne	$s3,$t8,.L0f0e6c30
/*  f0e6b34:	026a082a */ 	slt	$at,$s3,$t2
/*  f0e6b38:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6b3c:	8ceb0004 */ 	lw	$t3,0x4($a3)
/*  f0e6b40:	000b5280 */ 	sll	$t2,$t3,0xa
/*  f0e6b44:	05430006 */ 	bgezl	$t2,.L0f0e6b60
/*  f0e6b48:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6b4c:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0e6b50:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6b54:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e6b58:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6b5c:	8cf90010 */ 	lw	$t9,0x10($a3)
.L0f0e6b60:
/*  f0e6b60:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e6b64:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6b68:	0320f809 */ 	jalr	$t9
/*  f0e6b6c:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e6b70:	8fad013c */ 	lw	$t5,0x13c($sp)
/*  f0e6b74:	00404025 */ 	or	$t0,$v0,$zero
/*  f0e6b78:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e6b7c:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*  f0e6b80:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0e6b84:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e6b88:	87aa00ee */ 	lh	$t2,0xee($sp)
/*  f0e6b8c:	01d41823 */ 	subu	$v1,$t6,$s4
/*  f0e6b90:	2861000c */ 	slti	$at,$v1,0xc
/*  f0e6b94:	54200003 */ 	bnezl	$at,.L0f0e6ba4
/*  f0e6b98:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e6b9c:	2403000b */ 	addiu	$v1,$zero,0xb
/*  f0e6ba0:	862f0002 */ 	lh	$t7,0x2($s1)
.L0f0e6ba4:
/*  f0e6ba4:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e6ba8:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e6bac:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e6bb0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e6bb4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6bb8:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e6bbc:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e6bc0:	0006c400 */ 	sll	$t8,$a2,0x10
/*  f0e6bc4:	00183403 */ 	sra	$a2,$t8,0x10
/*  f0e6bc8:	0fc3980e */ 	jal	func0f0e6038
/*  f0e6bcc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e6bd0:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e6bd4:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e6bd8:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e6bdc:	240b270f */ 	addiu	$t3,$zero,0x270f
/*  f0e6be0:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e6be4:	50200010 */ 	beqzl	$at,.L0f0e6c28
/*  f0e6be8:	afab00fc */ 	sw	$t3,0xfc($sp)
/*  f0e6bec:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e6bf0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e6bf4:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e6bf8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e6bfc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e6c00:	0320f809 */ 	jalr	$t9
/*  f0e6c04:	00000000 */ 	nop
/*  f0e6c08:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e6c0c:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6c10:	2694000b */ 	addiu	$s4,$s4,0xb
/*  f0e6c14:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e6c18:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e6c1c:	100001f5 */ 	b	.L0f0e73f4
/*  f0e6c20:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f0e6c24:	afab00fc */ 	sw	$t3,0xfc($sp)
.L0f0e6c28:
/*  f0e6c28:	100001f2 */ 	b	.L0f0e73f4
/*  f0e6c2c:	2694000b */ 	addiu	$s4,$s4,0xb
.L0f0e6c30:
/*  f0e6c30:	502001e8 */ 	beqzl	$at,.L0f0e73d4
/*  f0e6c34:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e6c38:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f0e6c3c:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0e6c40:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6c44:	15b30003 */ 	bne	$t5,$s3,.L0f0e6c54
/*  f0e6c48:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6c4c:	02016025 */ 	or	$t4,$s0,$at
/*  f0e6c50:	01808025 */ 	or	$s0,$t4,$zero
.L0f0e6c54:
/*  f0e6c54:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e6c58:	566e0069 */ 	bnel	$s3,$t6,.L0f0e6e00
/*  f0e6c5c:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6c60:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0e6c64:	3c014220 */ 	lui	$at,0x4220
/*  f0e6c68:	51e00065 */ 	beqzl	$t7,.L0f0e6e00
/*  f0e6c6c:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6c70:	44816000 */ 	mtc1	$at,$f12
/*  f0e6c74:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e6c78:	00000000 */ 	nop
/*  f0e6c7c:	3c01437f */ 	lui	$at,0x437f
/*  f0e6c80:	44812000 */ 	mtc1	$at,$f4
/*  f0e6c84:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e6c88:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e6c8c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e6c90:	4458f800 */ 	cfc1	$t8,$31
/*  f0e6c94:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e6c98:	00000000 */ 	nop
/*  f0e6c9c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e6ca0:	444bf800 */ 	cfc1	$t3,$31
/*  f0e6ca4:	00000000 */ 	nop
/*  f0e6ca8:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e6cac:	51600013 */ 	beqzl	$t3,.L0f0e6cfc
/*  f0e6cb0:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e6cb4:	44814000 */ 	mtc1	$at,$f8
/*  f0e6cb8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e6cbc:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e6cc0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e6cc4:	00000000 */ 	nop
/*  f0e6cc8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e6ccc:	444bf800 */ 	cfc1	$t3,$31
/*  f0e6cd0:	00000000 */ 	nop
/*  f0e6cd4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e6cd8:	15600005 */ 	bnez	$t3,.L0f0e6cf0
/*  f0e6cdc:	00000000 */ 	nop
/*  f0e6ce0:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e6ce4:	3c018000 */ 	lui	$at,0x8000
/*  f0e6ce8:	10000007 */ 	b	.L0f0e6d08
/*  f0e6cec:	01615825 */ 	or	$t3,$t3,$at
.L0f0e6cf0:
/*  f0e6cf0:	10000005 */ 	b	.L0f0e6d08
/*  f0e6cf4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e6cf8:	440b4000 */ 	mfc1	$t3,$f8
.L0f0e6cfc:
/*  f0e6cfc:	00000000 */ 	nop
/*  f0e6d00:	0560fffb */ 	bltz	$t3,.L0f0e6cf0
/*  f0e6d04:	00000000 */ 	nop
.L0f0e6d08:
/*  f0e6d08:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e6d0c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6d10:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e6d14:	44808000 */ 	mtc1	$zero,$f16
/*  f0e6d18:	c46a0040 */ 	lwc1	$f10,0x40($v1)
/*  f0e6d1c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0e6d20:	00000000 */ 	nop
/*  f0e6d24:	45020008 */ 	bc1fl	.L0f0e6d48
/*  f0e6d28:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0e6d2c:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0e6d30:	01550019 */ 	multu	$t2,$s5
/*  f0e6d34:	00006812 */ 	mflo	$t5
/*  f0e6d38:	02cd6021 */ 	addu	$t4,$s6,$t5
/*  f0e6d3c:	1000000e */ 	b	.L0f0e6d78
/*  f0e6d40:	8d870020 */ 	lw	$a3,0x20($t4)
/*  f0e6d44:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0e6d48:
/*  f0e6d48:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6d4c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6d50:	03350019 */ 	multu	$t9,$s5
/*  f0e6d54:	00007012 */ 	mflo	$t6
/*  f0e6d58:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0e6d5c:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0e6d60:	03150019 */ 	multu	$t8,$s5
/*  f0e6d64:	00005812 */ 	mflo	$t3
/*  f0e6d68:	02cb5021 */ 	addu	$t2,$s6,$t3
/*  f0e6d6c:	0fc01a40 */ 	jal	colourBlend
/*  f0e6d70:	8d450020 */ 	lw	$a1,0x20($t2)
/*  f0e6d74:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e6d78:
/*  f0e6d78:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6d7c:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0e6d80:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e6d84:	0fc01a40 */ 	jal	colourBlend
/*  f0e6d88:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f0e6d8c:	8fa500b0 */ 	lw	$a1,0xb0($sp)
/*  f0e6d90:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6d94:	0fc01a40 */ 	jal	colourBlend
/*  f0e6d98:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e6d9c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e6da0:	44809000 */ 	mtc1	$zero,$f18
/*  f0e6da4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e6da8:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f0e6dac:	4600903e */ 	c.le.s	$f18,$f0
/*  f0e6db0:	00000000 */ 	nop
/*  f0e6db4:	45020005 */ 	bc1fl	.L0f0e6dcc
/*  f0e6db8:	44802000 */ 	mtc1	$zero,$f4
/*  f0e6dbc:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0e6dc0:	51a0000f */ 	beqzl	$t5,.L0f0e6e00
/*  f0e6dc4:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e6dc8:	44802000 */ 	mtc1	$zero,$f4
.L0f0e6dcc:
/*  f0e6dcc:	00000000 */ 	nop
/*  f0e6dd0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e6dd4:	00000000 */ 	nop
/*  f0e6dd8:	45000004 */ 	bc1f	.L0f0e6dec
/*  f0e6ddc:	00000000 */ 	nop
/*  f0e6de0:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e6de4:	51800006 */ 	beqzl	$t4,.L0f0e6e00
/*  f0e6de8:	8e2e0008 */ 	lw	$t6,0x8($s1)
.L0f0e6dec:
/*  f0e6dec:	0fc55809 */ 	jal	func0f156024
/*  f0e6df0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e6df4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e6df8:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0e6dfc:	8e2e0008 */ 	lw	$t6,0x8($s1)
.L0f0e6e00:
/*  f0e6e00:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f0e6e04:	000fc280 */ 	sll	$t8,$t7,0xa
/*  f0e6e08:	07030116 */ 	bgezl	$t8,.L0f0e7264
/*  f0e6e0c:	afb3015c */ 	sw	$s3,0x15c($sp)
/*  f0e6e10:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0e6e14:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e6e18:	3c0d8007 */ 	lui	$t5,%hi(g_LineHeight)
/*  f0e6e1c:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0e6e20:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e6e24:	8dad11a8 */ 	lw	$t5,%lo(g_LineHeight)($t5)
/*  f0e6e28:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0e6e2c:	01542821 */ 	addu	$a1,$t2,$s4
/*  f0e6e30:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0e6e34:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0e6e38:	afb000a4 */ 	sw	$s0,0xa4($sp)
/*  f0e6e3c:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0e6e40:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e6e44:	008c1821 */ 	addu	$v1,$a0,$t4
/*  f0e6e48:	00ad6021 */ 	addu	$t4,$a1,$t5
/*  f0e6e4c:	026e7826 */ 	xor	$t7,$s3,$t6
/*  f0e6e50:	2def0001 */ 	sltiu	$t7,$t7,0x1
/*  f0e6e54:	a3af00a8 */ 	sb	$t7,0xa8($sp)
/*  f0e6e58:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0e6e5c:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e6e60:	27b90098 */ 	addiu	$t9,$sp,0x98
/*  f0e6e64:	00603825 */ 	or	$a3,$v1,$zero
/*  f0e6e68:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0e6e6c:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0e6e70:	10200002 */ 	beqz	$at,.L0f0e6e7c
/*  f0e6e74:	93af00ed */ 	lbu	$t7,0xed($sp)
/*  f0e6e78:	00c02825 */ 	or	$a1,$a2,$zero
.L0f0e6e7c:
/*  f0e6e7c:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e6e80:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f0e6e84:	00ce1021 */ 	addu	$v0,$a2,$t6
/*  f0e6e88:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0e6e8c:	0050082a */ 	slt	$at,$v0,$s0
/*  f0e6e90:	10200002 */ 	beqz	$at,.L0f0e6e9c
/*  f0e6e94:	00000000 */ 	nop
/*  f0e6e98:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e6e9c:
/*  f0e6e9c:	11e00005 */ 	beqz	$t7,.L0f0e6eb4
/*  f0e6ea0:	24c2000b */ 	addiu	$v0,$a2,0xb
/*  f0e6ea4:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0e6ea8:	10200002 */ 	beqz	$at,.L0f0e6eb4
/*  f0e6eac:	00000000 */ 	nop
/*  f0e6eb0:	00402825 */ 	or	$a1,$v0,$zero
.L0f0e6eb4:
/*  f0e6eb4:	07010002 */ 	bgez	$t8,.L0f0e6ec0
/*  f0e6eb8:	00000000 */ 	nop
/*  f0e6ebc:	00002025 */ 	or	$a0,$zero,$zero
.L0f0e6ec0:
/*  f0e6ec0:	04630003 */ 	bgezl	$v1,.L0f0e6ed0
/*  f0e6ec4:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6ec8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e6ecc:	afa40094 */ 	sw	$a0,0x94($sp)
.L0f0e6ed0:
/*  f0e6ed0:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6ed4:	0c002f02 */ 	jal	viGetWidth
/*  f0e6ed8:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6edc:	3c0a8008 */ 	lui	$t2,%hi(g_ScaleX)
/*  f0e6ee0:	8d4afac0 */ 	lw	$t2,%lo(g_ScaleX)($t2)
/*  f0e6ee4:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6ee8:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6eec:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6ef0:	008a001a */ 	div	$zero,$a0,$t2
/*  f0e6ef4:	15400002 */ 	bnez	$t2,.L0f0e6f00
/*  f0e6ef8:	00000000 */ 	nop
/*  f0e6efc:	0007000d */ 	break	0x7
.L0f0e6f00:
/*  f0e6f00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6f04:	15410004 */ 	bne	$t2,$at,.L0f0e6f18
/*  f0e6f08:	3c018000 */ 	lui	$at,0x8000
/*  f0e6f0c:	14810002 */ 	bne	$a0,$at,.L0f0e6f18
/*  f0e6f10:	00000000 */ 	nop
/*  f0e6f14:	0006000d */ 	break	0x6
.L0f0e6f18:
/*  f0e6f18:	00006812 */ 	mflo	$t5
/*  f0e6f1c:	004d082a */ 	slt	$at,$v0,$t5
/*  f0e6f20:	50200014 */ 	beqzl	$at,.L0f0e6f74
/*  f0e6f24:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6f28:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6f2c:	0c002f02 */ 	jal	viGetWidth
/*  f0e6f30:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6f34:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f0e6f38:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f0e6f3c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6f40:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6f44:	0059001a */ 	div	$zero,$v0,$t9
/*  f0e6f48:	00002012 */ 	mflo	$a0
/*  f0e6f4c:	17200002 */ 	bnez	$t9,.L0f0e6f58
/*  f0e6f50:	00000000 */ 	nop
/*  f0e6f54:	0007000d */ 	break	0x7
.L0f0e6f58:
/*  f0e6f58:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6f5c:	17210004 */ 	bne	$t9,$at,.L0f0e6f70
/*  f0e6f60:	3c018000 */ 	lui	$at,0x8000
/*  f0e6f64:	14410002 */ 	bne	$v0,$at,.L0f0e6f70
/*  f0e6f68:	00000000 */ 	nop
/*  f0e6f6c:	0006000d */ 	break	0x6
.L0f0e6f70:
/*  f0e6f70:	afa40094 */ 	sw	$a0,0x94($sp)
.L0f0e6f74:
/*  f0e6f74:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6f78:	0c002f02 */ 	jal	viGetWidth
/*  f0e6f7c:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e6f80:	3c0b8008 */ 	lui	$t3,%hi(g_ScaleX)
/*  f0e6f84:	8d6bfac0 */ 	lw	$t3,%lo(g_ScaleX)($t3)
/*  f0e6f88:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e6f8c:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6f90:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6f94:	00eb001a */ 	div	$zero,$a3,$t3
/*  f0e6f98:	15600002 */ 	bnez	$t3,.L0f0e6fa4
/*  f0e6f9c:	00000000 */ 	nop
/*  f0e6fa0:	0007000d */ 	break	0x7
.L0f0e6fa4:
/*  f0e6fa4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e6fa8:	15610004 */ 	bne	$t3,$at,.L0f0e6fbc
/*  f0e6fac:	3c018000 */ 	lui	$at,0x8000
/*  f0e6fb0:	14e10002 */ 	bne	$a3,$at,.L0f0e6fbc
/*  f0e6fb4:	00000000 */ 	nop
/*  f0e6fb8:	0006000d */ 	break	0x6
.L0f0e6fbc:
/*  f0e6fbc:	00006012 */ 	mflo	$t4
/*  f0e6fc0:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e6fc4:	50200014 */ 	beqzl	$at,.L0f0e7018
/*  f0e6fc8:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e6fcc:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e6fd0:	0c002f02 */ 	jal	viGetWidth
/*  f0e6fd4:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e6fd8:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0e6fdc:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0e6fe0:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e6fe4:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e6fe8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0e6fec:	00003812 */ 	mflo	$a3
/*  f0e6ff0:	15c00002 */ 	bnez	$t6,.L0f0e6ffc
/*  f0e6ff4:	00000000 */ 	nop
/*  f0e6ff8:	0007000d */ 	break	0x7
.L0f0e6ffc:
/*  f0e6ffc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e7000:	15c10004 */ 	bne	$t6,$at,.L0f0e7014
/*  f0e7004:	3c018000 */ 	lui	$at,0x8000
/*  f0e7008:	14410002 */ 	bne	$v0,$at,.L0f0e7014
/*  f0e700c:	00000000 */ 	nop
/*  f0e7010:	0006000d */ 	break	0x6
.L0f0e7014:
/*  f0e7014:	02401025 */ 	or	$v0,$s2,$zero
.L0f0e7018:
/*  f0e7018:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0e701c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0e7020:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0e7024:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0e7028:	8c63fac0 */ 	lw	$v1,%lo(g_ScaleX)($v1)
/*  f0e702c:	3c068007 */ 	lui	$a2,%hi(g_ScissorX1)
/*  f0e7030:	24c61190 */ 	addiu	$a2,$a2,%lo(g_ScissorX1)
/*  f0e7034:	00830019 */ 	multu	$a0,$v1
/*  f0e7038:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e703c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e7040:	3c0b8007 */ 	lui	$t3,%hi(g_ScissorY1)
/*  f0e7044:	0000c012 */ 	mflo	$t8
/*  f0e7048:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0e704c:	00000000 */ 	nop
/*  f0e7050:	00e30019 */ 	multu	$a3,$v1
/*  f0e7054:	00005012 */ 	mflo	$t2
/*  f0e7058:	aeea0000 */ 	sw	$t2,0x0($s7)
/*  f0e705c:	ac251198 */ 	sw	$a1,%lo(g_ScissorY1)($at)
/*  f0e7060:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e7064:	afd00000 */ 	sw	$s0,0x0($s8)
/*  f0e7068:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0e706c:	05a30003 */ 	bgezl	$t5,.L0f0e707c
/*  f0e7070:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e7074:	ac201190 */ 	sw	$zero,%lo(g_ScissorX1)($at)
/*  f0e7078:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0e707c:
/*  f0e707c:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e7080:	07210002 */ 	bgez	$t9,.L0f0e708c
/*  f0e7084:	00000000 */ 	nop
/*  f0e7088:	aee00000 */ 	sw	$zero,0x0($s7)
.L0f0e708c:
/*  f0e708c:	8d6b1198 */ 	lw	$t3,%lo(g_ScissorY1)($t3)
/*  f0e7090:	05630003 */ 	bgezl	$t3,.L0f0e70a0
/*  f0e7094:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0e7098:	ac201198 */ 	sw	$zero,%lo(g_ScissorY1)($at)
/*  f0e709c:	8fcc0000 */ 	lw	$t4,0x0($s8)
.L0f0e70a0:
/*  f0e70a0:	05810002 */ 	bgez	$t4,.L0f0e70ac
/*  f0e70a4:	00000000 */ 	nop
/*  f0e70a8:	afc00000 */ 	sw	$zero,0x0($s8)
.L0f0e70ac:
/*  f0e70ac:	0c002ef1 */ 	jal	viGetBufX
/*  f0e70b0:	00000000 */ 	nop
/*  f0e70b4:	3c0e8007 */ 	lui	$t6,%hi(g_ScissorX1)
/*  f0e70b8:	8dce1190 */ 	lw	$t6,%lo(g_ScissorX1)($t6)
/*  f0e70bc:	004e082a */ 	slt	$at,$v0,$t6
/*  f0e70c0:	10200005 */ 	beqz	$at,.L0f0e70d8
/*  f0e70c4:	00000000 */ 	nop
/*  f0e70c8:	0c002ef1 */ 	jal	viGetBufX
/*  f0e70cc:	00000000 */ 	nop
/*  f0e70d0:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0e70d4:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0e70d8:
/*  f0e70d8:	0c002ef1 */ 	jal	viGetBufX
/*  f0e70dc:	00000000 */ 	nop
/*  f0e70e0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e70e4:	004f082a */ 	slt	$at,$v0,$t7
/*  f0e70e8:	10200004 */ 	beqz	$at,.L0f0e70fc
/*  f0e70ec:	00000000 */ 	nop
/*  f0e70f0:	0c002ef1 */ 	jal	viGetBufX
/*  f0e70f4:	00000000 */ 	nop
/*  f0e70f8:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e70fc:
/*  f0e70fc:	0c002ef5 */ 	jal	viGetBufY
/*  f0e7100:	00000000 */ 	nop
/*  f0e7104:	3c188007 */ 	lui	$t8,%hi(g_ScissorY1)
/*  f0e7108:	8f181198 */ 	lw	$t8,%lo(g_ScissorY1)($t8)
/*  f0e710c:	0058082a */ 	slt	$at,$v0,$t8
/*  f0e7110:	10200005 */ 	beqz	$at,.L0f0e7128
/*  f0e7114:	00000000 */ 	nop
/*  f0e7118:	0c002ef5 */ 	jal	viGetBufY
/*  f0e711c:	00000000 */ 	nop
/*  f0e7120:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e7124:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0e7128:
/*  f0e7128:	0c002ef5 */ 	jal	viGetBufY
/*  f0e712c:	00000000 */ 	nop
/*  f0e7130:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e7134:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e7138:	10200005 */ 	beqz	$at,.L0f0e7150
/*  f0e713c:	00000000 */ 	nop
/*  f0e7140:	0c002ef5 */ 	jal	viGetBufY
/*  f0e7144:	00000000 */ 	nop
/*  f0e7148:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e714c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e7150:
/*  f0e7150:	3c098007 */ 	lui	$t1,%hi(g_ScissorX1)
/*  f0e7154:	8d291190 */ 	lw	$t1,%lo(g_ScissorX1)($t1)
/*  f0e7158:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f0e715c:	3c088007 */ 	lui	$t0,%hi(g_ScissorY1)
/*  f0e7160:	44893000 */ 	mtc1	$t1,$f6
/*  f0e7164:	0149082a */ 	slt	$at,$t2,$t1
/*  f0e7168:	10200002 */ 	beqz	$at,.L0f0e7174
/*  f0e716c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e7170:	aee90000 */ 	sw	$t1,0x0($s7)
.L0f0e7174:
/*  f0e7174:	8d081198 */ 	lw	$t0,%lo(g_ScissorY1)($t0)
/*  f0e7178:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e717c:	50200003 */ 	beqzl	$at,.L0f0e718c
/*  f0e7180:	44889000 */ 	mtc1	$t0,$f18
/*  f0e7184:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e7188:	44889000 */ 	mtc1	$t0,$f18
.L0f0e718c:
/*  f0e718c:	3c014080 */ 	lui	$at,0x4080
/*  f0e7190:	44810000 */ 	mtc1	$at,$f0
/*  f0e7194:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e7198:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e719c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e71a0:	02401025 */ 	or	$v0,$s2,$zero
/*  f0e71a4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e71a8:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f0e71ac:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0e71b0:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e71b4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e71b8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e71bc:	44198000 */ 	mfc1	$t9,$f16
/*  f0e71c0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e71c4:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f0e71c8:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e71cc:	01817025 */ 	or	$t6,$t4,$at
/*  f0e71d0:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f0e71d4:	01ca6825 */ 	or	$t5,$t6,$t2
/*  f0e71d8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0e71dc:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e71e0:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f0e71e4:	44995000 */ 	mtc1	$t9,$f10
/*  f0e71e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0e71ec:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e71f0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e71f4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e71f8:	00000000 */ 	nop
/*  f0e71fc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e7200:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e7204:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e7208:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e720c:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e7210:	318f0fff */ 	andi	$t7,$t4,0xfff
/*  f0e7214:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e7218:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f0e721c:	03195825 */ 	or	$t3,$t8,$t9
/*  f0e7220:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0e7224:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0e7228:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f0e722c:	afb200b8 */ 	sw	$s2,0xb8($sp)
/*  f0e7230:	afb300bc */ 	sw	$s3,0xbc($sp)
/*  f0e7234:	afac00c0 */ 	sw	$t4,0xc0($sp)
/*  f0e7238:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f0e723c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7240:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7244:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7248:	0320f809 */ 	jalr	$t9
/*  f0e724c:	00000000 */ 	nop
/*  f0e7250:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0e7254:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e7258:	10000058 */ 	b	.L0f0e73bc
/*  f0e725c:	afae0160 */ 	sw	$t6,0x160($sp)
/*  f0e7260:	afb3015c */ 	sw	$s3,0x15c($sp)
.L0f0e7264:
/*  f0e7264:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7268:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0e726c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e7270:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7274:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e7278:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e727c:	0320f809 */ 	jalr	$t9
/*  f0e7280:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7284:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e7288:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e728c:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e7290:	01546821 */ 	addu	$t5,$t2,$s4
/*  f0e7294:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f0e7298:	afb8012c */ 	sw	$t8,0x12c($sp)
/*  f0e729c:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0e72a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f0e72a4:	8fac011c */ 	lw	$t4,0x11c($sp)
/*  f0e72a8:	91630000 */ 	lbu	$v1,0x0($t3)
/*  f0e72ac:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e72b0:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e72b4:	10610004 */ 	beq	$v1,$at,.L0f0e72c8
/*  f0e72b8:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e72bc:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e72c0:	14610003 */ 	bne	$v1,$at,.L0f0e72d0
/*  f0e72c4:	8faf011c */ 	lw	$t7,0x11c($sp)
.L0f0e72c8:
/*  f0e72c8:	10000003 */ 	b	.L0f0e72d8
/*  f0e72cc:	afac0130 */ 	sw	$t4,0x130($sp)
.L0f0e72d0:
/*  f0e72d0:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0e72d4:	afae0130 */ 	sw	$t6,0x130($sp)
.L0f0e72d8:
/*  f0e72d8:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0e72dc:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f0e72e0:	0059082a */ 	slt	$at,$v0,$t9
/*  f0e72e4:	50200004 */ 	beqzl	$at,.L0f0e72f8
/*  f0e72e8:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e72ec:	00594023 */ 	subu	$t0,$v0,$t9
/*  f0e72f0:	afb9012c */ 	sw	$t9,0x12c($sp)
/*  f0e72f4:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0e72f8:
/*  f0e72f8:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0e72fc:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f0e7300:	8fac00e8 */ 	lw	$t4,0xe8($sp)
/*  f0e7304:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e7308:	030b1823 */ 	subu	$v1,$t8,$t3
/*  f0e730c:	04630003 */ 	bgezl	$v1,.L0f0e731c
/*  f0e7310:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f0e7314:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e7318:	8faf00f4 */ 	lw	$t7,0xf4($sp)
.L0f0e731c:
/*  f0e731c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e7320:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7324:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e7328:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e732c:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e7330:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e7334:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7338:	01d95023 */ 	subu	$t2,$t6,$t9
/*  f0e733c:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e7340:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e7344:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e7348:	0fc5580f */ 	jal	textRenderProjected
/*  f0e734c:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f0e7350:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0e7354:	afb300b8 */ 	sw	$s3,0xb8($sp)
/*  f0e7358:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0e735c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7360:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e7364:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f0e7368:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e736c:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e7370:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e7374:	0320f809 */ 	jalr	$t9
/*  f0e7378:	00000000 */ 	nop
/*  f0e737c:	8fac00bc */ 	lw	$t4,0xbc($sp)
/*  f0e7380:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e7384:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7388:	1181000c */ 	beq	$t4,$at,.L0f0e73bc
/*  f0e738c:	8fa5011c */ 	lw	$a1,0x11c($sp)
/*  f0e7390:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e7394:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0e7398:	35ce007f */ 	ori	$t6,$t6,0x7f
/*  f0e739c:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e73a0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e73a4:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e73a8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73ac:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e73b0:	0fc38dec */ 	jal	renderCheckbox
/*  f0e73b4:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f0e73b8:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e73bc:
/*  f0e73bc:	8faa00b4 */ 	lw	$t2,0xb4($sp)
/*  f0e73c0:	51400004 */ 	beqzl	$t2,.L0f0e73d4
/*  f0e73c4:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e73c8:	0fc55809 */ 	jal	func0f156024
/*  f0e73cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0e73d0:	8fb80108 */ 	lw	$t8,0x108($sp)
.L0f0e73d4:
/*  f0e73d4:	3c0d8007 */ 	lui	$t5,%hi(g_LineHeight)
/*  f0e73d8:	8dad11a8 */ 	lw	$t5,%lo(g_LineHeight)($t5)
/*  f0e73dc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e73e0:	0278082a */ 	slt	$at,$s3,$t8
/*  f0e73e4:	14200003 */ 	bnez	$at,.L0f0e73f4
/*  f0e73e8:	028da021 */ 	addu	$s4,$s4,$t5
/*  f0e73ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e73f0:	afab0120 */ 	sw	$t3,0x120($sp)
.L0f0e73f4:
/*  f0e73f4:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e73f8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e73fc:	0334082a */ 	slt	$at,$t9,$s4
/*  f0e7400:	50200003 */ 	beqzl	$at,.L0f0e7410
/*  f0e7404:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0e7408:	afaf0120 */ 	sw	$t7,0x120($sp)
/*  f0e740c:	8fac0120 */ 	lw	$t4,0x120($sp)
.L0f0e7410:
/*  f0e7410:	5180fd95 */ 	beqzl	$t4,.L0f0e6a68
/*  f0e7414:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e7418:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0e741c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7420:	10000051 */ 	b	.L0f0e7568
/*  f0e7424:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e7428:
/*  f0e7428:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e742c:	44802000 */ 	mtc1	$zero,$f4
/*  f0e7430:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0e7434:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0e7438:	00000000 */ 	nop
/*  f0e743c:	4502000b */ 	bc1fl	.L0f0e746c
/*  f0e7440:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0e7444:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e7448:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e744c:	3c167f1b */ 	lui	$s6,%hi(g_MenuColourPalettes)
/*  f0e7450:	01d50019 */ 	multu	$t6,$s5
/*  f0e7454:	26d61fb0 */ 	addiu	$s6,$s6,%lo(g_MenuColourPalettes)
/*  f0e7458:	00005012 */ 	mflo	$t2
/*  f0e745c:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e7460:	10000012 */ 	b	.L0f0e74ac
/*  f0e7464:	8db00018 */ 	lw	$s0,0x18($t5)
/*  f0e7468:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0e746c:
/*  f0e746c:	2415003c */ 	addiu	$s5,$zero,0x3c
/*  f0e7470:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e7474:	03150019 */ 	multu	$t8,$s5
/*  f0e7478:	3c167f1b */ 	lui	$s6,%hi(g_MenuColourPalettes)
/*  f0e747c:	26d61fb0 */ 	addiu	$s6,$s6,%lo(g_MenuColourPalettes)
/*  f0e7480:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7484:	00005812 */ 	mflo	$t3
/*  f0e7488:	02cbc821 */ 	addu	$t9,$s6,$t3
/*  f0e748c:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0e7490:	01f50019 */ 	multu	$t7,$s5
/*  f0e7494:	00006012 */ 	mflo	$t4
/*  f0e7498:	02cc7021 */ 	addu	$t6,$s6,$t4
/*  f0e749c:	0fc01a40 */ 	jal	colourBlend
/*  f0e74a0:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e74a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e74a8:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0e74ac:
/*  f0e74ac:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e74b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e74b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e74b8:	51400008 */ 	beqzl	$t2,.L0f0e74dc
/*  f0e74bc:	8fab011c */ 	lw	$t3,0x11c($sp)
/*  f0e74c0:	0fc01a40 */ 	jal	colourBlend
/*  f0e74c4:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e74c8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e74cc:	00416824 */ 	and	$t5,$v0,$at
/*  f0e74d0:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0e74d4:	01b88025 */ 	or	$s0,$t5,$t8
/*  f0e74d8:	8fab011c */ 	lw	$t3,0x11c($sp)
.L0f0e74dc:
/*  f0e74dc:	24045739 */ 	addiu	$a0,$zero,0x5739
/*  f0e74e0:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0e74e4:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f0e74e8:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e74ec:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e74f0:	05810003 */ 	bgez	$t4,.L0f0e7500
/*  f0e74f4:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f0e74f8:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0e74fc:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e7500:
/*  f0e7500:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0e7504:	0fc5b9f1 */ 	jal	langGet
/*  f0e7508:	afaa012c */ 	sw	$t2,0x12c($sp)
/*  f0e750c:	0c002f06 */ 	jal	viGetHeight
/*  f0e7510:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e7514:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f0e7518:	8fb800f4 */ 	lw	$t8,0xf4($sp)
/*  f0e751c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7520:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7524:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e7528:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e752c:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e7530:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0e7534:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e7538:	01796023 */ 	subu	$t4,$t3,$t9
/*  f0e753c:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f0e7540:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e7544:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7548:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e754c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e7550:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e7554:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e7558:	02603825 */ 	or	$a3,$s3,$zero
/*  f0e755c:	0fc5580f */ 	jal	textRenderProjected
/*  f0e7560:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e7564:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e7568:
/*  f0e7568:	0fc54de0 */ 	jal	func0f153780
/*  f0e756c:	02402025 */ 	or	$a0,$s2,$zero
.L0f0e7570:
/*  f0e7570:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0e7574:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0e7578:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0e757c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0e7580:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0e7584:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0e7588:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0e758c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0e7590:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0e7594:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0e7598:	03e00008 */ 	jr	$ra
/*  f0e759c:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#else
GLOBAL_ASM(
glabel menuRenderItemList
/*  f0e37a0:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f0e37a4:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0e37a8:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0e37ac:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f0e37b0:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f0e37b4:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f0e37b8:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f0e37bc:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0e37c0:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f0e37c4:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f0e37c8:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0e37cc:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0e37d0:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0e37d4:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f0e37d8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0e37dc:	afae016c */ 	sw	$t6,0x16c($sp)
/*  f0e37e0:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f0e37e4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e37e8:	8d4a236c */ 	lw	$t2,0x236c($t2)
/*  f0e37ec:	8d6b2370 */ 	lw	$t3,0x2370($t3)
/*  f0e37f0:	2419270f */ 	addiu	$t9,$zero,0x270f
/*  f0e37f4:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0e37f8:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0e37fc:	afb900fc */ 	sw	$t9,0xfc($sp)
/*  f0e3800:	a3a000ed */ 	sb	$zero,0xed($sp)
/*  f0e3804:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0e3808:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f0e380c:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0e3810:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0e3814:	0080a025 */ 	or	$s4,$a0,$zero
/*  f0e3818:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f0e381c:	240f000b */ 	addiu	$t7,$zero,0xb
/*  f0e3820:	3c018007 */ 	lui	$at,0x8007
/*  f0e3824:	000c6a80 */ 	sll	$t5,$t4,0xa
/*  f0e3828:	05a1000a */ 	bgez	$t5,.NB0f0e3854
/*  f0e382c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3830:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3834:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e3838:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e383c:	0320f809 */ 	jalr	$t9
/*  f0e3840:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0e3844:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f0e3848:	3c018007 */ 	lui	$at,0x8007
/*  f0e384c:	10000002 */ 	beqz	$zero,.NB0f0e3858
/*  f0e3850:	ac2e3858 */ 	sw	$t6,0x3858($at)
.NB0f0e3854:
/*  f0e3854:	ac2f3858 */ 	sw	$t7,0x3858($at)
.NB0f0e3858:
/*  f0e3858:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0e385c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0e3860:	8f0a001c */ 	lw	$t2,0x1c($t8)
/*  f0e3864:	a7aa00ee */ 	sh	$t2,0xee($sp)
/*  f0e3868:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0e386c:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f0e3870:	000c6a00 */ 	sll	$t5,$t4,0x8
/*  f0e3874:	05a30004 */ 	bgezl	$t5,.NB0f0e3888
/*  f0e3878:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0e387c:	86390004 */ 	lh	$t9,0x4($s1)
/*  f0e3880:	a7b900ee */ 	sh	$t9,0xee($sp)
/*  f0e3884:	862e0000 */ 	lh	$t6,0x0($s1)
.NB0f0e3888:
/*  f0e3888:	8def2320 */ 	lw	$t7,0x2320($t7)
/*  f0e388c:	3c014080 */ 	lui	$at,0x4080
/*  f0e3890:	4481a000 */ 	mtc1	$at,$f20
/*  f0e3894:	01cf0019 */ 	multu	$t6,$t7
/*  f0e3898:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0e389c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e38a0:	02801025 */ 	or	$v0,$s4,$zero
/*  f0e38a4:	448e8000 */ 	mtc1	$t6,$f16
/*  f0e38a8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0e38ac:	3c058007 */ 	lui	$a1,0x8007
/*  f0e38b0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e38b4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f0e38b8:	0000c012 */ 	mflo	$t8
/*  f0e38bc:	44982000 */ 	mtc1	$t8,$f4
/*  f0e38c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e38c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e38c8:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0e38cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e38d0:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f0e38d4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e38d8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e38dc:	440b5000 */ 	mfc1	$t3,$f10
/*  f0e38e0:	44183000 */ 	mfc1	$t8,$f6
/*  f0e38e4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0e38e8:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0e38ec:	01a1c825 */ 	or	$t9,$t5,$at
/*  f0e38f0:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f0e38f4:	032a5825 */ 	or	$t3,$t9,$t2
/*  f0e38f8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0e38fc:	87ad00ee */ 	lh	$t5,0xee($sp)
/*  f0e3900:	862c0000 */ 	lh	$t4,0x0($s1)
/*  f0e3904:	8def2320 */ 	lw	$t7,0x2320($t7)
/*  f0e3908:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0e390c:	01cf0019 */ 	multu	$t6,$t7
/*  f0e3910:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e3914:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f0e3918:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e391c:	448f2000 */ 	mtc1	$t7,$f4
/*  f0e3920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3924:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e3928:	0000c012 */ 	mflo	$t8
/*  f0e392c:	44984000 */ 	mtc1	$t8,$f8
/*  f0e3930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3934:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e3938:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0e393c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3940:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0e3944:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e3948:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e394c:	440a9000 */ 	mfc1	$t2,$f18
/*  f0e3950:	44195000 */ 	mfc1	$t9,$f10
/*  f0e3954:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f0e3958:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e395c:	332a0fff */ 	andi	$t2,$t9,0xfff
/*  f0e3960:	018a5825 */ 	or	$t3,$t4,$t2
/*  f0e3964:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0e3968:	86240006 */ 	lh	$a0,0x6($s1)
/*  f0e396c:	8ca53858 */ 	lw	$a1,0x3858($a1)
/*  f0e3970:	8fad016c */ 	lw	$t5,0x16c($sp)
/*  f0e3974:	04810003 */ 	bgez	$a0,.NB0f0e3984
/*  f0e3978:	00049043 */ 	sra	$s2,$a0,0x1
/*  f0e397c:	24810001 */ 	addiu	$at,$a0,0x1
/*  f0e3980:	00019043 */ 	sra	$s2,$at,0x1
.NB0f0e3984:
/*  f0e3984:	0245001a */ 	div	$zero,$s2,$a1
/*  f0e3988:	14a00002 */ 	bnez	$a1,.NB0f0e3994
/*  f0e398c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3990:	0007000d */ 	break	0x7
.NB0f0e3994:
/*  f0e3994:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e3998:	14a10004 */ 	bne	$a1,$at,.NB0f0e39ac
/*  f0e399c:	3c018000 */ 	lui	$at,0x8000
/*  f0e39a0:	16410002 */ 	bne	$s2,$at,.NB0f0e39ac
/*  f0e39a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e39a8:	0006000d */ 	break	0x6
.NB0f0e39ac:
/*  f0e39ac:	00009012 */ 	mflo	$s2
/*  f0e39b0:	a5a40006 */ 	sh	$a0,0x6($t5)
/*  f0e39b4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e39b8:	02450019 */ 	multu	$s2,$a1
/*  f0e39bc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e39c0:	90e30000 */ 	lbu	$v1,0x0($a3)
/*  f0e39c4:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e39c8:	00009012 */ 	mflo	$s2
/*  f0e39cc:	10610004 */ 	beq	$v1,$at,.NB0f0e39e0
/*  f0e39d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e39d4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e39d8:	54610050 */ 	bnel	$v1,$at,.NB0f0e3b1c
/*  f0e39dc:	8cf90010 */ 	lw	$t9,0x10($a3)
.NB0f0e39e0:
/*  f0e39e0:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e39e4:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e39e8:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e39ec:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e39f0:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f0e39f4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e39f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e39fc:	0fc37aaa */ 	jal	func0f0e1668
/*  f0e3a00:	020e3821 */ 	addu	$a3,$s0,$t6
/*  f0e3a04:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e3a08:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e3a0c:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e3a10:	240a007f */ 	addiu	$t2,$zero,0x7f
/*  f0e3a14:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e3a18:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f0e3a1c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e3a20:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e3a24:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e3a28:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0e3a2c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e3a30:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e3a34:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e3a38:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3a3c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e3a40:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0e3a44:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f0e3a48:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0e3a4c:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0e3a50:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e3a54:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e3a58:	240a007f */ 	addiu	$t2,$zero,0x7f
/*  f0e3a5c:	240b000f */ 	addiu	$t3,$zero,0xf
/*  f0e3a60:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0e3a64:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f0e3a68:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e3a6c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e3a70:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e3a74:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0e3a78:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0e3a7c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e3a80:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e3a84:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0e3a88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3a8c:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e3a90:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e3a94:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e3a98:	2418007f */ 	addiu	$t8,$zero,0x7f
/*  f0e3a9c:	2419000f */ 	addiu	$t9,$zero,0xf
/*  f0e3aa0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e3aa4:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*  f0e3aa8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e3aac:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e3ab0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e3ab4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e3ab8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e3abc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3ac0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e3ac4:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0e3ac8:	020e3821 */ 	addu	$a3,$s0,$t6
/*  f0e3acc:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e3ad0:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e3ad4:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0e3ad8:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0e3adc:	240f007f */ 	addiu	$t7,$zero,0x7f
/*  f0e3ae0:	014b3021 */ 	addu	$a2,$t2,$t3
/*  f0e3ae4:	24ce0001 */ 	addiu	$t6,$a2,0x1
/*  f0e3ae8:	2418000f */ 	addiu	$t8,$zero,0xf
/*  f0e3aec:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e3af0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e3af4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e3af8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e3afc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e3b00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3b04:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e3b08:	0fc37fce */ 	jal	func0f0e2aa4
/*  f0e3b0c:	020d3821 */ 	addu	$a3,$s0,$t5
/*  f0e3b10:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e3b14:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3b18:	8cf90010 */ 	lw	$t9,0x10($a3)
.NB0f0e3b1c:
/*  f0e3b1c:	57200004 */ 	bnezl	$t9,.NB0f0e3b30
/*  f0e3b20:	afa0015c */ 	sw	$zero,0x15c($sp)
/*  f0e3b24:	100002f7 */ 	beqz	$zero,.NB0f0e4704
/*  f0e3b28:	02801025 */ 	or	$v0,$s4,$zero
/*  f0e3b2c:	afa0015c */ 	sw	$zero,0x15c($sp)
.NB0f0e3b30:
/*  f0e3b30:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3b34:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e3b38:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e3b3c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3b40:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3b44:	0320f809 */ 	jalr	$t9
/*  f0e3b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3b4c:	8fa8015c */ 	lw	$t0,0x15c($sp)
/*  f0e3b50:	3c010001 */ 	lui	$at,0x1
/*  f0e3b54:	0101082b */ 	sltu	$at,$t0,$at
/*  f0e3b58:	54200003 */ 	bnezl	$at,.NB0f0e3b68
/*  f0e3b5c:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0e3b60:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0e3b64:	862c0002 */ 	lh	$t4,0x2($s1)
.NB0f0e3b68:
/*  f0e3b68:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e3b6c:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e3b70:	258a0001 */ 	addiu	$t2,$t4,0x1
/*  f0e3b74:	afaa0104 */ 	sw	$t2,0x104($sp)
/*  f0e3b78:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3b7c:	afa800f0 */ 	sw	$t0,0xf0($sp)
/*  f0e3b80:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3b84:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3b88:	0320f809 */ 	jalr	$t9
/*  f0e3b8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3b90:	8fab015c */ 	lw	$t3,0x15c($sp)
/*  f0e3b94:	8fad016c */ 	lw	$t5,0x16c($sp)
/*  f0e3b98:	afab0108 */ 	sw	$t3,0x108($sp)
/*  f0e3b9c:	85ae0000 */ 	lh	$t6,0x0($t5)
/*  f0e3ba0:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e3ba4:	01d22023 */ 	subu	$a0,$t6,$s2
/*  f0e3ba8:	0fc38c6f */ 	jal	func0f0e5d2c
/*  f0e3bac:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e3bb0:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e3bb4:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e3bb8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e3bbc:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f0e3bc0:	0fc5374a */ 	jal	func0f153628
/*  f0e3bc4:	afb8012c */ 	sw	$t8,0x12c($sp)
/*  f0e3bc8:	00132400 */ 	sll	$a0,$s3,0x10
/*  f0e3bcc:	afa00160 */ 	sw	$zero,0x160($sp)
/*  f0e3bd0:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0e3bd4:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e3bd8:	0260a825 */ 	or	$s5,$s3,$zero
/*  f0e3bdc:	01802025 */ 	or	$a0,$t4,$zero
/*  f0e3be0:	0fc38ce2 */ 	jal	func0f0e5ef8
/*  f0e3be4:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e3be8:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e3bec:	00525021 */ 	addu	$t2,$v0,$s2
/*  f0e3bf0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e3bf4:	872b0000 */ 	lh	$t3,0x0($t9)
/*  f0e3bf8:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e3bfc:	afa00158 */ 	sw	$zero,0x158($sp)
/*  f0e3c00:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3c04:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e3c08:	014bb023 */ 	subu	$s6,$t2,$t3
/*  f0e3c0c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3c10:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3c14:	0320f809 */ 	jalr	$t9
/*  f0e3c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3c1c:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f0e3c20:	8fa3014c */ 	lw	$v1,0x14c($sp)
/*  f0e3c24:	19a00265 */ 	blez	$t5,.NB0f0e45bc
/*  f0e3c28:	afa30100 */ 	sw	$v1,0x100($sp)
/*  f0e3c2c:	1060005b */ 	beqz	$v1,.NB0f0e3d9c
/*  f0e3c30:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e3c34:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e3c38:	afa000fc */ 	sw	$zero,0xfc($sp)
/*  f0e3c3c:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e3c40:	18600018 */ 	blez	$v1,.NB0f0e3ca4
/*  f0e3c44:	afa00150 */ 	sw	$zero,0x150($sp)
/*  f0e3c48:	8e270008 */ 	lw	$a3,0x8($s1)
.NB0f0e3c4c:
/*  f0e3c4c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e3c50:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e3c54:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3c58:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3c5c:	0320f809 */ 	jalr	$t9
/*  f0e3c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3c64:	8fa30154 */ 	lw	$v1,0x154($sp)
/*  f0e3c68:	0263082a */ 	slt	$at,$s3,$v1
/*  f0e3c6c:	54200007 */ 	bnezl	$at,.NB0f0e3c8c
/*  f0e3c70:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e3c74:	8fb2014c */ 	lw	$s2,0x14c($sp)
/*  f0e3c78:	afa300fc */ 	sw	$v1,0xfc($sp)
/*  f0e3c7c:	26580001 */ 	addiu	$t8,$s2,0x1
/*  f0e3c80:	10000002 */ 	beqz	$zero,.NB0f0e3c8c
/*  f0e3c84:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e3c88:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f0e3c8c:
/*  f0e3c8c:	16000005 */ 	bnez	$s0,.NB0f0e3ca4
/*  f0e3c90:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0e3c94:	8faa0100 */ 	lw	$t2,0x100($sp)
/*  f0e3c98:	018a082a */ 	slt	$at,$t4,$t2
/*  f0e3c9c:	5420ffeb */ 	bnezl	$at,.NB0f0e3c4c
/*  f0e3ca0:	8e270008 */ 	lw	$a3,0x8($s1)
.NB0f0e3ca4:
/*  f0e3ca4:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f0e3ca8:	8fab0158 */ 	lw	$t3,0x158($sp)
/*  f0e3cac:	afb2013c */ 	sw	$s2,0x13c($sp)
/*  f0e3cb0:	01b3082a */ 	slt	$at,$t5,$s3
/*  f0e3cb4:	afa00140 */ 	sw	$zero,0x140($sp)
/*  f0e3cb8:	14200004 */ 	bnez	$at,.NB0f0e3ccc
/*  f0e3cbc:	afab0148 */ 	sw	$t3,0x148($sp)
/*  f0e3cc0:	2ac1000b */ 	slti	$at,$s6,0xb
/*  f0e3cc4:	50200036 */ 	beqzl	$at,.NB0f0e3da0
/*  f0e3cc8:	8faf00fc */ 	lw	$t7,0xfc($sp)
.NB0f0e3ccc:
/*  f0e3ccc:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3cd0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e3cd4:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e3cd8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3cdc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3ce0:	0320f809 */ 	jalr	$t9
/*  f0e3ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3ce8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0e3cec:	8dce3858 */ 	lw	$t6,0x3858($t6)
/*  f0e3cf0:	87b800ee */ 	lh	$t8,0xee($sp)
/*  f0e3cf4:	240c000b */ 	addiu	$t4,$zero,0xb
/*  f0e3cf8:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0e3cfc:	59e0000f */ 	blezl	$t7,.NB0f0e3d3c
/*  f0e3d00:	8fad0104 */ 	lw	$t5,0x104($sp)
/*  f0e3d04:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e3d08:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e3d0c:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e3d10:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e3d14:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e3d18:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e3d1c:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0e3d20:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e3d24:	0fc38d32 */ 	jal	func0f0e6038
/*  f0e3d28:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e3d2c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e3d30:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e3d34:	a3ab00ed */ 	sb	$t3,0xed($sp)
/*  f0e3d38:	8fad0104 */ 	lw	$t5,0x104($sp)
.NB0f0e3d3c:
/*  f0e3d3c:	8fae013c */ 	lw	$t6,0x13c($sp)
/*  f0e3d40:	8fb8014c */ 	lw	$t8,0x14c($sp)
/*  f0e3d44:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e3d48:	25b9000b */ 	addiu	$t9,$t5,0xb
/*  f0e3d4c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0e3d50:	030c082a */ 	slt	$at,$t8,$t4
/*  f0e3d54:	afb90104 */ 	sw	$t9,0x104($sp)
/*  f0e3d58:	1020000e */ 	beqz	$at,.NB0f0e3d94
/*  f0e3d5c:	afaf013c */ 	sw	$t7,0x13c($sp)
/*  f0e3d60:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3d64:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e3d68:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e3d6c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3d70:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3d74:	0320f809 */ 	jalr	$t9
/*  f0e3d78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3d7c:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0e3d80:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e3d84:	256d0001 */ 	addiu	$t5,$t3,0x1
/*  f0e3d88:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f0e3d8c:	10000003 */ 	beqz	$zero,.NB0f0e3d9c
/*  f0e3d90:	afaa00fc */ 	sw	$t2,0xfc($sp)
.NB0f0e3d94:
/*  f0e3d94:	240e270f */ 	addiu	$t6,$zero,0x270f
/*  f0e3d98:	afae00fc */ 	sw	$t6,0xfc($sp)
.NB0f0e3d9c:
/*  f0e3d9c:	8faf00fc */ 	lw	$t7,0xfc($sp)
.NB0f0e3da0:
/*  f0e3da0:	3c1e7f1b */ 	lui	$s8,0x7f1b
/*  f0e3da4:	27dec2e0 */ 	addiu	$s8,$s8,-15648
/*  f0e3da8:	166f0002 */ 	bne	$s3,$t7,.NB0f0e3db4
/*  f0e3dac:	2417003c */ 	addiu	$s7,$zero,0x3c
/*  f0e3db0:	26d6fff5 */ 	addiu	$s6,$s6,-11
.NB0f0e3db4:
/*  f0e3db4:	8e230010 */ 	lw	$v1,0x10($s1)
.NB0f0e3db8:
/*  f0e3db8:	44809000 */ 	mtc1	$zero,$f18
/*  f0e3dbc:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e3dc0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e3dc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3dc8:	45020008 */ 	bc1fl	.NB0f0e3dec
/*  f0e3dcc:	906a003d */ 	lbu	$t2,0x3d($v1)
/*  f0e3dd0:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e3dd4:	03170019 */ 	multu	$t8,$s7
/*  f0e3dd8:	00006012 */ 	mflo	$t4
/*  f0e3ddc:	03ccc821 */ 	addu	$t9,$s8,$t4
/*  f0e3de0:	1000000f */ 	beqz	$zero,.NB0f0e3e20
/*  f0e3de4:	8f300018 */ 	lw	$s0,0x18($t9)
/*  f0e3de8:	906a003d */ 	lbu	$t2,0x3d($v1)
.NB0f0e3dec:
/*  f0e3dec:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e3df0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e3df4:	01570019 */ 	multu	$t2,$s7
/*  f0e3df8:	00005812 */ 	mflo	$t3
/*  f0e3dfc:	03cb6821 */ 	addu	$t5,$s8,$t3
/*  f0e3e00:	8da40018 */ 	lw	$a0,0x18($t5)
/*  f0e3e04:	01d70019 */ 	multu	$t6,$s7
/*  f0e3e08:	00007812 */ 	mflo	$t7
/*  f0e3e0c:	03cfc021 */ 	addu	$t8,$s8,$t7
/*  f0e3e10:	0fc01990 */ 	jal	colourBlend
/*  f0e3e14:	8f050018 */ 	lw	$a1,0x18($t8)
/*  f0e3e18:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e3e1c:	8e230010 */ 	lw	$v1,0x10($s1)
.NB0f0e3e20:
/*  f0e3e20:	8c6c000c */ 	lw	$t4,0xc($v1)
/*  f0e3e24:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e3e28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e3e2c:	51800009 */ 	beqzl	$t4,.NB0f0e3e54
/*  f0e3e30:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e3e34:	0fc01990 */ 	jal	colourBlend
/*  f0e3e38:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e3e3c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e3e40:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e3e44:	320a00ff */ 	andi	$t2,$s0,0xff
/*  f0e3e48:	032a8025 */ 	or	$s0,$t9,$t2
/*  f0e3e4c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e3e50:	906b003c */ 	lbu	$t3,0x3c($v1)
.NB0f0e3e54:
/*  f0e3e54:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e3e58:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e3e5c:	01770019 */ 	multu	$t3,$s7
/*  f0e3e60:	00001012 */ 	mflo	$v0
/*  f0e3e64:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e3e68:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e3e6c:	8ca5c460 */ 	lw	$a1,-0x3ba0($a1)
/*  f0e3e70:	0fc53925 */ 	jal	func0f153e38
/*  f0e3e74:	8c84c5c8 */ 	lw	$a0,-0x3a38($a0)
/*  f0e3e78:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f0e3e7c:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f0e3e80:	16ad003f */ 	bne	$s5,$t5,.NB0f0e3f80
/*  f0e3e84:	02af082a */ 	slt	$at,$s5,$t7
/*  f0e3e88:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3e8c:	8cee0004 */ 	lw	$t6,0x4($a3)
/*  f0e3e90:	000e7a80 */ 	sll	$t7,$t6,0xa
/*  f0e3e94:	05e30006 */ 	bgezl	$t7,.NB0f0e3eb0
/*  f0e3e98:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3e9c:	0fc3c728 */ 	jal	func0f0f50fc
/*  f0e3ea0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e3ea4:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e3ea8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3eac:	8cf90010 */ 	lw	$t9,0x10($a3)
.NB0f0e3eb0:
/*  f0e3eb0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e3eb4:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3eb8:	0320f809 */ 	jalr	$t9
/*  f0e3ebc:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e3ec0:	8fb8013c */ 	lw	$t8,0x13c($sp)
/*  f0e3ec4:	00404025 */ 	or	$t0,$v0,$zero
/*  f0e3ec8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e3ecc:	270c0001 */ 	addiu	$t4,$t8,0x1
/*  f0e3ed0:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0e3ed4:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f0e3ed8:	87af00ee */ 	lh	$t7,0xee($sp)
/*  f0e3edc:	01561823 */ 	subu	$v1,$t2,$s6
/*  f0e3ee0:	2861000c */ 	slti	$at,$v1,0xc
/*  f0e3ee4:	54200003 */ 	bnezl	$at,.NB0f0e3ef4
/*  f0e3ee8:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e3eec:	2403000b */ 	addiu	$v1,$zero,0xb
/*  f0e3ef0:	862b0002 */ 	lh	$t3,0x2($s1)
.NB0f0e3ef4:
/*  f0e3ef4:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e3ef8:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e3efc:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e3f00:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e3f04:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e3f08:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e3f0c:	01763021 */ 	addu	$a2,$t3,$s6
/*  f0e3f10:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f0e3f14:	000d3403 */ 	sra	$a2,$t5,0x10
/*  f0e3f18:	0fc38d32 */ 	jal	func0f0e6038
/*  f0e3f1c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e3f20:	8fb8014c */ 	lw	$t8,0x14c($sp)
/*  f0e3f24:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e3f28:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e3f2c:	240e270f */ 	addiu	$t6,$zero,0x270f
/*  f0e3f30:	030c082a */ 	slt	$at,$t8,$t4
/*  f0e3f34:	50200010 */ 	beqzl	$at,.NB0f0e3f78
/*  f0e3f38:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f0e3f3c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e3f40:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e3f44:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e3f48:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e3f4c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e3f50:	0320f809 */ 	jalr	$t9
/*  f0e3f54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3f58:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0e3f5c:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e3f60:	26d6000b */ 	addiu	$s6,$s6,0xb
/*  f0e3f64:	256d0001 */ 	addiu	$t5,$t3,0x1
/*  f0e3f68:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f0e3f6c:	10000186 */ 	beqz	$zero,.NB0f0e4588
/*  f0e3f70:	afaa00fc */ 	sw	$t2,0xfc($sp)
/*  f0e3f74:	afae00fc */ 	sw	$t6,0xfc($sp)
.NB0f0e3f78:
/*  f0e3f78:	10000183 */ 	beqz	$zero,.NB0f0e4588
/*  f0e3f7c:	26d6000b */ 	addiu	$s6,$s6,0xb
.NB0f0e3f80:
/*  f0e3f80:	50200179 */ 	beqzl	$at,.NB0f0e4568
/*  f0e3f84:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f0e3f88:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0e3f8c:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0e3f90:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e3f94:	17150003 */ 	bne	$t8,$s5,.NB0f0e3fa4
/*  f0e3f98:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e3f9c:	02016025 */ 	or	$t4,$s0,$at
/*  f0e3fa0:	01808025 */ 	or	$s0,$t4,$zero
.NB0f0e3fa4:
/*  f0e3fa4:	872a0002 */ 	lh	$t2,0x2($t9)
/*  f0e3fa8:	56aa0055 */ 	bnel	$s5,$t2,.NB0f0e4100
/*  f0e3fac:	8e380008 */ 	lw	$t8,0x8($s1)
/*  f0e3fb0:	8e2b000c */ 	lw	$t3,0xc($s1)
/*  f0e3fb4:	3c014220 */ 	lui	$at,0x4220
/*  f0e3fb8:	51600051 */ 	beqzl	$t3,.NB0f0e4100
/*  f0e3fbc:	8e380008 */ 	lw	$t8,0x8($s1)
/*  f0e3fc0:	44816000 */ 	mtc1	$at,$f12
/*  f0e3fc4:	0fc019eb */ 	jal	func0f006b08
/*  f0e3fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3fcc:	3c01437f */ 	lui	$at,0x437f
/*  f0e3fd0:	44812000 */ 	mtc1	$at,$f4
/*  f0e3fd4:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0e3fd8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e3fdc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e3fe0:	444df800 */ 	cfc1	$t5,$31
/*  f0e3fe4:	44d2f800 */ 	ctc1	$s2,$31
/*  f0e3fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3fec:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e3ff0:	4452f800 */ 	cfc1	$s2,$31
/*  f0e3ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e3ff8:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0e3ffc:	52400013 */ 	beqzl	$s2,.NB0f0e404c
/*  f0e4000:	44124000 */ 	mfc1	$s2,$f8
/*  f0e4004:	44814000 */ 	mtc1	$at,$f8
/*  f0e4008:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0e400c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e4010:	44d2f800 */ 	ctc1	$s2,$31
/*  f0e4014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4018:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e401c:	4452f800 */ 	cfc1	$s2,$31
/*  f0e4020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4024:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0e4028:	16400005 */ 	bnez	$s2,.NB0f0e4040
/*  f0e402c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4030:	44124000 */ 	mfc1	$s2,$f8
/*  f0e4034:	3c018000 */ 	lui	$at,0x8000
/*  f0e4038:	10000007 */ 	beqz	$zero,.NB0f0e4058
/*  f0e403c:	02419025 */ 	or	$s2,$s2,$at
.NB0f0e4040:
/*  f0e4040:	10000005 */ 	beqz	$zero,.NB0f0e4058
/*  f0e4044:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0e4048:	44124000 */ 	mfc1	$s2,$f8
.NB0f0e404c:
/*  f0e404c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4050:	0640fffb */ 	bltz	$s2,.NB0f0e4040
/*  f0e4054:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0e4058:
/*  f0e4058:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e405c:	44cdf800 */ 	ctc1	$t5,$31
/*  f0e4060:	44808000 */ 	mtc1	$zero,$f16
/*  f0e4064:	c46a0040 */ 	lwc1	$f10,0x40($v1)
/*  f0e4068:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0e406c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4070:	45020008 */ 	bc1fl	.NB0f0e4094
/*  f0e4074:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e4078:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e407c:	01d70019 */ 	multu	$t6,$s7
/*  f0e4080:	00007812 */ 	mflo	$t7
/*  f0e4084:	03cfc021 */ 	addu	$t8,$s8,$t7
/*  f0e4088:	1000000e */ 	beqz	$zero,.NB0f0e40c4
/*  f0e408c:	8f070020 */ 	lw	$a3,0x20($t8)
/*  f0e4090:	906c003d */ 	lbu	$t4,0x3d($v1)
.NB0f0e4094:
/*  f0e4094:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e4098:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e409c:	01970019 */ 	multu	$t4,$s7
/*  f0e40a0:	0000c812 */ 	mflo	$t9
/*  f0e40a4:	03d95021 */ 	addu	$t2,$s8,$t9
/*  f0e40a8:	8d440020 */ 	lw	$a0,0x20($t2)
/*  f0e40ac:	01770019 */ 	multu	$t3,$s7
/*  f0e40b0:	00006812 */ 	mflo	$t5
/*  f0e40b4:	03cd7021 */ 	addu	$t6,$s8,$t5
/*  f0e40b8:	0fc01990 */ 	jal	colourBlend
/*  f0e40bc:	8dc50020 */ 	lw	$a1,0x20($t6)
/*  f0e40c0:	00403825 */ 	or	$a3,$v0,$zero
.NB0f0e40c4:
/*  f0e40c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e40c8:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0e40cc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e40d0:	0fc01990 */ 	jal	colourBlend
/*  f0e40d4:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f0e40d8:	8fa500b0 */ 	lw	$a1,0xb0($sp)
/*  f0e40dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e40e0:	0fc01990 */ 	jal	colourBlend
/*  f0e40e4:	02403025 */ 	or	$a2,$s2,$zero
/*  f0e40e8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e40ec:	0fc541a0 */ 	jal	func0f156024
/*  f0e40f0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e40f4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e40f8:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0e40fc:	8e380008 */ 	lw	$t8,0x8($s1)
.NB0f0e4100:
/*  f0e4100:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f0e4104:	000cca80 */ 	sll	$t9,$t4,0xa
/*  f0e4108:	072300bc */ 	bgezl	$t9,.NB0f0e43fc
/*  f0e410c:	afb5015c */ 	sw	$s5,0x15c($sp)
/*  f0e4110:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0e4114:	8faf016c */ 	lw	$t7,0x16c($sp)
/*  f0e4118:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e411c:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f0e4120:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e4124:	8dad3858 */ 	lw	$t5,0x3858($t5)
/*  f0e4128:	01769021 */ 	addu	$s2,$t3,$s6
/*  f0e412c:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e4130:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e4134:	afb000a4 */ 	sw	$s0,0xa4($sp)
/*  f0e4138:	024d9821 */ 	addu	$s3,$s2,$t5
/*  f0e413c:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0e4140:	85f80002 */ 	lh	$t8,0x2($t7)
/*  f0e4144:	010e1821 */ 	addu	$v1,$t0,$t6
/*  f0e4148:	27ae0098 */ 	addiu	$t6,$sp,0x98
/*  f0e414c:	02b86026 */ 	xor	$t4,$s5,$t8
/*  f0e4150:	2d8c0001 */ 	sltiu	$t4,$t4,0x1
/*  f0e4154:	a3ac00a8 */ 	sb	$t4,0xa8($sp)
/*  f0e4158:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e415c:	00604825 */ 	or	$t1,$v1,$zero
/*  f0e4160:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0e4164:	0246082a */ 	slt	$at,$s2,$a2
/*  f0e4168:	93b800ed */ 	lbu	$t8,0xed($sp)
/*  f0e416c:	10200002 */ 	beqz	$at,.NB0f0e4178
/*  f0e4170:	8fac0098 */ 	lw	$t4,0x98($sp)
/*  f0e4174:	00c09025 */ 	or	$s2,$a2,$zero
.NB0f0e4178:
/*  f0e4178:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e417c:	00cf1021 */ 	addu	$v0,$a2,$t7
/*  f0e4180:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0e4184:	0053082a */ 	slt	$at,$v0,$s3
/*  f0e4188:	10200002 */ 	beqz	$at,.NB0f0e4194
/*  f0e418c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4190:	00409825 */ 	or	$s3,$v0,$zero
.NB0f0e4194:
/*  f0e4194:	13000005 */ 	beqz	$t8,.NB0f0e41ac
/*  f0e4198:	24c2000b */ 	addiu	$v0,$a2,0xb
/*  f0e419c:	0242082a */ 	slt	$at,$s2,$v0
/*  f0e41a0:	10200002 */ 	beqz	$at,.NB0f0e41ac
/*  f0e41a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e41a8:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0e41ac:
/*  f0e41ac:	05810002 */ 	bgez	$t4,.NB0f0e41b8
/*  f0e41b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e41b4:	00004025 */ 	or	$t0,$zero,$zero
.NB0f0e41b8:
/*  f0e41b8:	04630003 */ 	bgezl	$v1,.NB0f0e41c8
/*  f0e41bc:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0e41c0:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e41c4:	afa80094 */ 	sw	$t0,0x94($sp)
.NB0f0e41c8:
/*  f0e41c8:	0c002f77 */ 	jal	viGetWidth
/*  f0e41cc:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0e41d0:	3c198008 */ 	lui	$t9,0x8008
/*  f0e41d4:	8f392320 */ 	lw	$t9,0x2320($t9)
/*  f0e41d8:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f0e41dc:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0e41e0:	0119001a */ 	div	$zero,$t0,$t9
/*  f0e41e4:	17200002 */ 	bnez	$t9,.NB0f0e41f0
/*  f0e41e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e41ec:	0007000d */ 	break	0x7
.NB0f0e41f0:
/*  f0e41f0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e41f4:	17210004 */ 	bne	$t9,$at,.NB0f0e4208
/*  f0e41f8:	3c018000 */ 	lui	$at,0x8000
/*  f0e41fc:	15010002 */ 	bne	$t0,$at,.NB0f0e4208
/*  f0e4200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4204:	0006000d */ 	break	0x6
.NB0f0e4208:
/*  f0e4208:	00005812 */ 	mflo	$t3
/*  f0e420c:	004b082a */ 	slt	$at,$v0,$t3
/*  f0e4210:	50200012 */ 	beqzl	$at,.NB0f0e425c
/*  f0e4214:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0e4218:	0c002f77 */ 	jal	viGetWidth
/*  f0e421c:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0e4220:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e4224:	8dad2320 */ 	lw	$t5,0x2320($t5)
/*  f0e4228:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0e422c:	004d001a */ 	div	$zero,$v0,$t5
/*  f0e4230:	00004012 */ 	mflo	$t0
/*  f0e4234:	15a00002 */ 	bnez	$t5,.NB0f0e4240
/*  f0e4238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e423c:	0007000d */ 	break	0x7
.NB0f0e4240:
/*  f0e4240:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e4244:	15a10004 */ 	bne	$t5,$at,.NB0f0e4258
/*  f0e4248:	3c018000 */ 	lui	$at,0x8000
/*  f0e424c:	14410002 */ 	bne	$v0,$at,.NB0f0e4258
/*  f0e4250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4254:	0006000d */ 	break	0x6
.NB0f0e4258:
/*  f0e4258:	afa80094 */ 	sw	$t0,0x94($sp)
.NB0f0e425c:
/*  f0e425c:	0c002f77 */ 	jal	viGetWidth
/*  f0e4260:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0e4264:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e4268:	8dce2320 */ 	lw	$t6,0x2320($t6)
/*  f0e426c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0e4270:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f0e4274:	012e001a */ 	div	$zero,$t1,$t6
/*  f0e4278:	15c00002 */ 	bnez	$t6,.NB0f0e4284
/*  f0e427c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4280:	0007000d */ 	break	0x7
.NB0f0e4284:
/*  f0e4284:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e4288:	15c10004 */ 	bne	$t6,$at,.NB0f0e429c
/*  f0e428c:	3c018000 */ 	lui	$at,0x8000
/*  f0e4290:	15210002 */ 	bne	$t1,$at,.NB0f0e429c
/*  f0e4294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4298:	0006000d */ 	break	0x6
.NB0f0e429c:
/*  f0e429c:	00005012 */ 	mflo	$t2
/*  f0e42a0:	004a082a */ 	slt	$at,$v0,$t2
/*  f0e42a4:	50200012 */ 	beqzl	$at,.NB0f0e42f0
/*  f0e42a8:	02801025 */ 	or	$v0,$s4,$zero
/*  f0e42ac:	0c002f77 */ 	jal	viGetWidth
/*  f0e42b0:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0e42b4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0e42b8:	8def2320 */ 	lw	$t7,0x2320($t7)
/*  f0e42bc:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f0e42c0:	004f001a */ 	div	$zero,$v0,$t7
/*  f0e42c4:	00004812 */ 	mflo	$t1
/*  f0e42c8:	15e00002 */ 	bnez	$t7,.NB0f0e42d4
/*  f0e42cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e42d0:	0007000d */ 	break	0x7
.NB0f0e42d4:
/*  f0e42d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e42d8:	15e10004 */ 	bne	$t7,$at,.NB0f0e42ec
/*  f0e42dc:	3c018000 */ 	lui	$at,0x8000
/*  f0e42e0:	14410002 */ 	bne	$v0,$at,.NB0f0e42ec
/*  f0e42e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e42e8:	0006000d */ 	break	0x6
.NB0f0e42ec:
/*  f0e42ec:	02801025 */ 	or	$v0,$s4,$zero
.NB0f0e42f0:
/*  f0e42f0:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e42f4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0e42f8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0e42fc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e4300:	8d8c2320 */ 	lw	$t4,0x2320($t4)
/*  f0e4304:	44925000 */ 	mtc1	$s2,$f10
/*  f0e4308:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e430c:	010c0019 */ 	multu	$t0,$t4
/*  f0e4310:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e4314:	26830008 */ 	addiu	$v1,$s4,0x8
/*  f0e4318:	24740008 */ 	addiu	$s4,$v1,0x8
/*  f0e431c:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f0e4320:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e4324:	0000c812 */ 	mflo	$t9
/*  f0e4328:	44999000 */ 	mtc1	$t9,$f18
/*  f0e432c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4330:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e4334:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0e4338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e433c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0e4340:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e4344:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4348:	440d4000 */ 	mfc1	$t5,$f8
/*  f0e434c:	44939000 */ 	mtc1	$s3,$f18
/*  f0e4350:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e4354:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0e4358:	000e5300 */ 	sll	$t2,$t6,0xc
/*  f0e435c:	01417825 */ 	or	$t7,$t2,$at
/*  f0e4360:	31990fff */ 	andi	$t9,$t4,0xfff
/*  f0e4364:	01f95825 */ 	or	$t3,$t7,$t9
/*  f0e4368:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0e436c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e4370:	8dad2320 */ 	lw	$t5,0x2320($t5)
/*  f0e4374:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e4378:	012d0019 */ 	multu	$t1,$t5
/*  f0e437c:	00007012 */ 	mflo	$t6
/*  f0e4380:	448e3000 */ 	mtc1	$t6,$f6
/*  f0e4384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4388:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e438c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0e4390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4394:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0e4398:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e439c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e43a0:	44188000 */ 	mfc1	$t8,$f16
/*  f0e43a4:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e43a8:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0e43ac:	000c7b00 */ 	sll	$t7,$t4,0xc
/*  f0e43b0:	316d0fff */ 	andi	$t5,$t3,0xfff
/*  f0e43b4:	01ed7025 */ 	or	$t6,$t7,$t5
/*  f0e43b8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0e43bc:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f0e43c0:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f0e43c4:	afb400b8 */ 	sw	$s4,0xb8($sp)
/*  f0e43c8:	afb500bc */ 	sw	$s5,0xbc($sp)
/*  f0e43cc:	afaa00c0 */ 	sw	$t2,0xc0($sp)
/*  f0e43d0:	afb800c4 */ 	sw	$t8,0xc4($sp)
/*  f0e43d4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e43d8:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e43dc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e43e0:	0320f809 */ 	jalr	$t9
/*  f0e43e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e43e8:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f0e43ec:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e43f0:	10000057 */ 	beqz	$zero,.NB0f0e4550
/*  f0e43f4:	afac0160 */ 	sw	$t4,0x160($sp)
/*  f0e43f8:	afb5015c */ 	sw	$s5,0x15c($sp)
.NB0f0e43fc:
/*  f0e43fc:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e4400:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e4404:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e4408:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e440c:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e4410:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e4414:	0320f809 */ 	jalr	$t9
/*  f0e4418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e441c:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e4420:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0e4424:	00403825 */ 	or	$a3,$v0,$zero
/*  f0e4428:	01767821 */ 	addu	$t7,$t3,$s6
/*  f0e442c:	25ed0001 */ 	addiu	$t5,$t7,0x1
/*  f0e4430:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f0e4434:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e4438:	8faa011c */ 	lw	$t2,0x11c($sp)
/*  f0e443c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e4440:	91c30000 */ 	lbu	$v1,0x0($t6)
/*  f0e4444:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e4448:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e444c:	10610003 */ 	beq	$v1,$at,.NB0f0e445c
/*  f0e4450:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e4454:	14610003 */ 	bne	$v1,$at,.NB0f0e4464
/*  f0e4458:	8fb8011c */ 	lw	$t8,0x11c($sp)
.NB0f0e445c:
/*  f0e445c:	10000003 */ 	beqz	$zero,.NB0f0e446c
/*  f0e4460:	afaa0130 */ 	sw	$t2,0x130($sp)
.NB0f0e4464:
/*  f0e4464:	270c0008 */ 	addiu	$t4,$t8,0x8
/*  f0e4468:	afac0130 */ 	sw	$t4,0x130($sp)
.NB0f0e446c:
/*  f0e446c:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0e4470:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f0e4474:	0059082a */ 	slt	$at,$v0,$t9
/*  f0e4478:	50200004 */ 	beqzl	$at,.NB0f0e448c
/*  f0e447c:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e4480:	00599023 */ 	subu	$s2,$v0,$t9
/*  f0e4484:	afb9012c */ 	sw	$t9,0x12c($sp)
/*  f0e4488:	862b0002 */ 	lh	$t3,0x2($s1)
.NB0f0e448c:
/*  f0e448c:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e4490:	8fae012c */ 	lw	$t6,0x12c($sp)
/*  f0e4494:	8faa00e8 */ 	lw	$t2,0xe8($sp)
/*  f0e4498:	016f6821 */ 	addu	$t5,$t3,$t7
/*  f0e449c:	01ae1823 */ 	subu	$v1,$t5,$t6
/*  f0e44a0:	04630003 */ 	bgezl	$v1,.NB0f0e44b0
/*  f0e44a4:	8fb800f4 */ 	lw	$t8,0xf4($sp)
/*  f0e44a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e44ac:	8fb800f4 */ 	lw	$t8,0xf4($sp)
.NB0f0e44b0:
/*  f0e44b0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e44b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e44b8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e44bc:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0e44c0:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e44c4:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0e44c8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e44cc:	01995823 */ 	subu	$t3,$t4,$t9
/*  f0e44d0:	016f6821 */ 	addu	$t5,$t3,$t7
/*  f0e44d4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e44d8:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0e44dc:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e44e0:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f0e44e4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0e44e8:	afb500b8 */ 	sw	$s5,0xb8($sp)
/*  f0e44ec:	afae00bc */ 	sw	$t6,0xbc($sp)
/*  f0e44f0:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e44f4:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0e44f8:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f0e44fc:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e4500:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e4504:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e4508:	0320f809 */ 	jalr	$t9
/*  f0e450c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e4510:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0e4514:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e4518:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e451c:	1141000c */ 	beq	$t2,$at,.NB0f0e4550
/*  f0e4520:	8fa5011c */ 	lw	$a1,0x11c($sp)
/*  f0e4524:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0e4528:	3c0cff00 */ 	lui	$t4,0xff00
/*  f0e452c:	358c007f */ 	ori	$t4,$t4,0x7f
/*  f0e4530:	03163021 */ 	addu	$a2,$t8,$s6
/*  f0e4534:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e4538:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e453c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e4540:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e4544:	0fc38311 */ 	jal	renderCheckbox
/*  f0e4548:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f0e454c:	0040a025 */ 	or	$s4,$v0,$zero
.NB0f0e4550:
/*  f0e4550:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f0e4554:	51600004 */ 	beqzl	$t3,.NB0f0e4568
/*  f0e4558:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f0e455c:	0fc541a0 */ 	jal	func0f156024
/*  f0e4560:	00002025 */ 	or	$a0,$zero,$zero
/*  f0e4564:	8fad0108 */ 	lw	$t5,0x108($sp)
.NB0f0e4568:
/*  f0e4568:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0e456c:	8def3858 */ 	lw	$t7,0x3858($t7)
/*  f0e4570:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0e4574:	02ad082a */ 	slt	$at,$s5,$t5
/*  f0e4578:	14200003 */ 	bnez	$at,.NB0f0e4588
/*  f0e457c:	02cfb021 */ 	addu	$s6,$s6,$t7
/*  f0e4580:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e4584:	afae0120 */ 	sw	$t6,0x120($sp)
.NB0f0e4588:
/*  f0e4588:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e458c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e4590:	0336082a */ 	slt	$at,$t9,$s6
/*  f0e4594:	50200003 */ 	beqzl	$at,.NB0f0e45a4
/*  f0e4598:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f0e459c:	afb80120 */ 	sw	$t8,0x120($sp)
/*  f0e45a0:	8faa0120 */ 	lw	$t2,0x120($sp)
.NB0f0e45a4:
/*  f0e45a4:	5140fe04 */ 	beqzl	$t2,.NB0f0e3db8
/*  f0e45a8:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e45ac:	0fc3c728 */ 	jal	func0f0f50fc
/*  f0e45b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e45b4:	10000051 */ 	beqz	$zero,.NB0f0e46fc
/*  f0e45b8:	0040a025 */ 	or	$s4,$v0,$zero
.NB0f0e45bc:
/*  f0e45bc:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e45c0:	44808000 */ 	mtc1	$zero,$f16
/*  f0e45c4:	c46a0040 */ 	lwc1	$f10,0x40($v1)
/*  f0e45c8:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0e45cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e45d0:	4502000b */ 	bc1fl	.NB0f0e4600
/*  f0e45d4:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0e45d8:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e45dc:	2417003c */ 	addiu	$s7,$zero,0x3c
/*  f0e45e0:	3c1e7f1b */ 	lui	$s8,0x7f1b
/*  f0e45e4:	01970019 */ 	multu	$t4,$s7
/*  f0e45e8:	27dec2e0 */ 	addiu	$s8,$s8,-15648
/*  f0e45ec:	00005812 */ 	mflo	$t3
/*  f0e45f0:	03cb7821 */ 	addu	$t7,$s8,$t3
/*  f0e45f4:	10000012 */ 	beqz	$zero,.NB0f0e4640
/*  f0e45f8:	8df00018 */ 	lw	$s0,0x18($t7)
/*  f0e45fc:	906d003d */ 	lbu	$t5,0x3d($v1)
.NB0f0e4600:
/*  f0e4600:	2417003c */ 	addiu	$s7,$zero,0x3c
/*  f0e4604:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e4608:	01b70019 */ 	multu	$t5,$s7
/*  f0e460c:	3c1e7f1b */ 	lui	$s8,0x7f1b
/*  f0e4610:	27dec2e0 */ 	addiu	$s8,$s8,-15648
/*  f0e4614:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e4618:	00007012 */ 	mflo	$t6
/*  f0e461c:	03cec821 */ 	addu	$t9,$s8,$t6
/*  f0e4620:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0e4624:	03170019 */ 	multu	$t8,$s7
/*  f0e4628:	00005012 */ 	mflo	$t2
/*  f0e462c:	03ca6021 */ 	addu	$t4,$s8,$t2
/*  f0e4630:	0fc01990 */ 	jal	colourBlend
/*  f0e4634:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0e4638:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e463c:	8e230010 */ 	lw	$v1,0x10($s1)
.NB0f0e4640:
/*  f0e4640:	8c6b000c */ 	lw	$t3,0xc($v1)
/*  f0e4644:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e4648:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e464c:	51600008 */ 	beqzl	$t3,.NB0f0e4670
/*  f0e4650:	8fae011c */ 	lw	$t6,0x11c($sp)
/*  f0e4654:	0fc01990 */ 	jal	colourBlend
/*  f0e4658:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e465c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e4660:	00417824 */ 	and	$t7,$v0,$at
/*  f0e4664:	320d00ff */ 	andi	$t5,$s0,0xff
/*  f0e4668:	01ed8025 */ 	or	$s0,$t7,$t5
/*  f0e466c:	8fae011c */ 	lw	$t6,0x11c($sp)
.NB0f0e4670:
/*  f0e4670:	24045739 */ 	addiu	$a0,$zero,0x5739
/*  f0e4674:	25d90008 */ 	addiu	$t9,$t6,0x8
/*  f0e4678:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f0e467c:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f0e4680:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0e4684:	05410003 */ 	bgez	$t2,.NB0f0e4694
/*  f0e4688:	000a6043 */ 	sra	$t4,$t2,0x1
/*  f0e468c:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0e4690:	00016043 */ 	sra	$t4,$at,0x1
.NB0f0e4694:
/*  f0e4694:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0e4698:	0fc5a4dd */ 	jal	langGet
/*  f0e469c:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e46a0:	0c002f7b */ 	jal	viGetHeight
/*  f0e46a4:	00409825 */ 	or	$s3,$v0,$zero
/*  f0e46a8:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0e46ac:	8fad00f4 */ 	lw	$t5,0xf4($sp)
/*  f0e46b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e46b4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e46b8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e46bc:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e46c0:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e46c4:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0e46c8:	8fb20128 */ 	lw	$s2,0x128($sp)
/*  f0e46cc:	01d95023 */ 	subu	$t2,$t6,$t9
/*  f0e46d0:	01586021 */ 	addu	$t4,$t2,$t8
/*  f0e46d4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e46d8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e46dc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e46e0:	02802025 */ 	or	$a0,$s4,$zero
/*  f0e46e4:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e46e8:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e46ec:	02603825 */ 	or	$a3,$s3,$zero
/*  f0e46f0:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e46f4:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0e46f8:	0040a025 */ 	or	$s4,$v0,$zero
.NB0f0e46fc:
/*  f0e46fc:	0fc537a0 */ 	jal	func0f153780
/*  f0e4700:	02802025 */ 	or	$a0,$s4,$zero
.NB0f0e4704:
/*  f0e4704:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0e4708:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e470c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0e4710:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0e4714:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0e4718:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f0e471c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f0e4720:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f0e4724:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f0e4728:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f0e472c:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f0e4730:	03e00008 */ 	jr	$ra
/*  f0e4734:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#endif

bool menuTickItemList(struct menuitem *item, struct menuinputs *inputs, u32 arg2, union menuitemdata *data)
{
	f32 f0;
	union handlerdata handlerdata;
	union handlerdata handlerdata2;
	s16 min;
	s16 max;
	s32 tmp;
	s32 i;
	u32 last;
	s16 prev2;
	s16 prev;

	if (item->handler == NULL) {
		return true;
	}

	if (item->param1 & 0x00200000) {
		item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
		g_LineHeight = handlerdata2.list.value;
	} else {
		g_LineHeight = 11;
	}

	if (item->type == MENUITEMTYPE_DROPDOWN || item->type == MENUITEMTYPE_PLAYERSTATS) {
		min = data->list.unk06 / 2;
		min = min / (s32)g_LineHeight;
		min *= (s32)g_LineHeight;

		data->list.unk04 = func0f0e5ef8(data->list.unk02, item);

		if (data->list.unk04 < min) {
			data->list.unk04 = min;
		}

		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);

		max = handlerdata.list2.unk02 * (s32)g_LineHeight - data->list.unk06 + min;

		if (data->list.unk04 > max) {
			data->list.unk04 = max;
		}
	}

	if (data->list.unk00 != data->list.unk04) {
		f0 = data->list.unk00;
		prev = data->list.unk00;

		for (i = 0; i < g_Vars.diffframe60; i++) {
			f0 = data->list.unk04 * (PAL ? 0.404f : 0.35f) + (PAL ? 0.59599995613098f : 0.65f) * f0;
		}

		data->list.unk00 = f0;

		if (data->list.unk00 != data->list.unk04 && prev == data->list.unk00) {
			if (data->list.unk00 < data->list.unk04) {
				data->list.unk00++;
			} else {
				data->list.unk00--;
			}
		}
	}

	if (arg2 & 2) {
		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);

		if (handlerdata.list.value) {
			last = handlerdata.list.value - 1;

			if (data->list.unk02 > last) {
				data->list.unk02 = last;
				data->list.unk04 = func0f0e5ef8(data->list.unk02, item);
			}

			if (inputs->updown) {
				prev2 = data->list.unk02;
				data->list.unk02 += inputs->updown;

				if (data->list.unk02 < 0) {
					data->list.unk02 = handlerdata.list.value - 1;
				}

				if (data->list.unk02 >= (s16)handlerdata.list.value) {
					data->list.unk02 = 0;
				}

				data->list.unk04 = func0f0e5ef8(data->list.unk02, item);

				if (prev2 != data->list.unk02) {
					handlerdata.list.value = data->list.unk02;
					item->handler(MENUOP_LISTITEMFOCUS, item, &handlerdata);

					menuPlaySound(MENUSOUND_SUBFOCUS);
				}
			}

			if (inputs->select) {
				handlerdata.list.value = data->list.unk02;
				handlerdata.list.unk04 = 0;

				if (inputs->start) {
					handlerdata.list.unk04 = 1;
				}

				item->handler(MENUOP_SET, item, &handlerdata);

				menuPlaySound(MENUSOUND_SELECT);

				if (handlerdata.list.unk04 == 2) {
					inputs->start = false;
				}
			}

			inputs->updown = false;
		}
	}

	tmp = data->list.unk02;
	handlerdata.list.value = tmp;
	handlerdata.list.unk04 = 1;
	handlerdata.list.unk0c = tmp;
	handlerdata.list.groupstartindex = (arg2 & 2) ? 1 : 0;

	item->handler(MENUOP_25, item, &handlerdata);

	if (handlerdata.list.unk0c != handlerdata.list.value) {
		data->list.unk02 = handlerdata.list.value;
		data->list.unk04 = func0f0e5ef8(data->list.unk02, item);
	}

	return true;
}

void menuInitItemDropdown(struct menuitem *item, union menuitemdata *data)
{
	s32 (*handler)(s32 operation, struct menuitem *item, union handlerdata *data);
	union handlerdata handlerdata;
	union handlerdata handlerdata2;

	data->dropdown.unk00 = 0;
	data->dropdown.unk02 = 0;
	data->dropdown.unk08 = 0;
	data->dropdown.unk0a = 0;

	handlerdata.dropdown.value = 0;

	handler = item->handler;

	if (item->param1 & 0x00200000) {
		handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
		g_LineHeight = handlerdata2.dropdown.value;
	} else {
		g_LineHeight = 11;
	}

	item->handler(MENUOP_GETOPTIONVALUE, item, &handlerdata);

	if (handlerdata.dropdown.value < 0xffff) {
		data->dropdown.unk02 = handlerdata.dropdown.value;
	} else {
		// The value won't fit in unk02.
		// Maybe MENUOP_25 is getting a scaled-down value?
		// But then how does it know the value is scaled?
		handlerdata.dropdown.value = 0;
		handlerdata.dropdown.unk04 = 0;

		item->handler(MENUOP_25, item, &handlerdata);
		data->dropdown.unk02 = handlerdata.dropdown.value;
	}

	data->dropdown.unk04 = func0f0e5ef8(data->dropdown.unk02, item);

	item->handler(MENUOP_LISTITEMFOCUS, item, &handlerdata);
}

GLOBAL_ASM(
glabel menuRenderItemDropdown
/*  f0e7a8c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e7a90:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e7a94:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0e7a98:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0e7a9c:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0e7aa0:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0e7aa4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e7aa8:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f0e7aac:	84af0002 */ 	lh	$t7,0x2($a1)
/*  f0e7ab0:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0e7ab4:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0e7ab8:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0e7abc:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0e7ac0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7ac4:	44803000 */ 	mtc1	$zero,$f6
/*  f0e7ac8:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e7acc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e7ad0:	00000000 */ 	nop
/*  f0e7ad4:	4502000a */ 	bc1fl	.L0f0e7b00
/*  f0e7ad8:	9068003d */ 	lbu	$t0,0x3d($v1)
/*  f0e7adc:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e7ae0:	3c117f1b */ 	lui	$s1,%hi(g_MenuColourPalettes+0x18)
/*  f0e7ae4:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e7ae8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e7aec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e7af0:	02398821 */ 	addu	$s1,$s1,$t9
/*  f0e7af4:	10000013 */ 	b	.L0f0e7b44
/*  f0e7af8:	8e311fc8 */ 	lw	$s1,%lo(g_MenuColourPalettes+0x18)($s1)
/*  f0e7afc:	9068003d */ 	lbu	$t0,0x3d($v1)
.L0f0e7b00:
/*  f0e7b00:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7b04:	3c0a7f1b */ 	lui	$t2,%hi(g_MenuColourPalettes)
/*  f0e7b08:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0e7b0c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7b10:	254a1fb0 */ 	addiu	$t2,$t2,%lo(g_MenuColourPalettes)
/*  f0e7b14:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0e7b18:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7b1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7b20:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0e7b24:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0e7b28:	01aa7021 */ 	addu	$t6,$t5,$t2
/*  f0e7b2c:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e7b30:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0e7b34:	0fc01a40 */ 	jal	colourBlend
/*  f0e7b38:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7b3c:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e7b40:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0e7b44:
/*  f0e7b44:	8c6f000c */ 	lw	$t7,0xc($v1)
/*  f0e7b48:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7b4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e7b50:	51e00008 */ 	beqzl	$t7,.L0f0e7b74
/*  f0e7b54:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0e7b58:	0fc01a40 */ 	jal	colourBlend
/*  f0e7b5c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7b60:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7b64:	0041c024 */ 	and	$t8,$v0,$at
/*  f0e7b68:	323900ff */ 	andi	$t9,$s1,0xff
/*  f0e7b6c:	03198825 */ 	or	$s1,$t8,$t9
/*  f0e7b70:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0e7b74:
/*  f0e7b74:	104000b7 */ 	beqz	$v0,.L0f0e7e54
/*  f0e7b78:	30480002 */ 	andi	$t0,$v0,0x2
/*  f0e7b7c:	11000055 */ 	beqz	$t0,.L0f0e7cd4
/*  f0e7b80:	3c014220 */ 	lui	$at,0x4220
/*  f0e7b84:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0e7b88:	44816000 */ 	mtc1	$at,$f12
/*  f0e7b8c:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e7b90:	00000000 */ 	nop
/*  f0e7b94:	3c01437f */ 	lui	$at,0x437f
/*  f0e7b98:	44814000 */ 	mtc1	$at,$f8
/*  f0e7b9c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7ba0:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0e7ba4:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0e7ba8:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0e7bac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e7bb0:	4449f800 */ 	cfc1	$t1,$31
/*  f0e7bb4:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7bb8:	00000000 */ 	nop
/*  f0e7bbc:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0e7bc0:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7bc4:	00000000 */ 	nop
/*  f0e7bc8:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7bcc:	51600013 */ 	beqzl	$t3,.L0f0e7c1c
/*  f0e7bd0:	440b8000 */ 	mfc1	$t3,$f16
/*  f0e7bd4:	44818000 */ 	mtc1	$at,$f16
/*  f0e7bd8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7bdc:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0e7be0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7be4:	00000000 */ 	nop
/*  f0e7be8:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0e7bec:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7bf0:	00000000 */ 	nop
/*  f0e7bf4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7bf8:	15600005 */ 	bnez	$t3,.L0f0e7c10
/*  f0e7bfc:	00000000 */ 	nop
/*  f0e7c00:	440b8000 */ 	mfc1	$t3,$f16
/*  f0e7c04:	3c018000 */ 	lui	$at,0x8000
/*  f0e7c08:	10000007 */ 	b	.L0f0e7c28
/*  f0e7c0c:	01615825 */ 	or	$t3,$t3,$at
.L0f0e7c10:
/*  f0e7c10:	10000005 */ 	b	.L0f0e7c28
/*  f0e7c14:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e7c18:	440b8000 */ 	mfc1	$t3,$f16
.L0f0e7c1c:
/*  f0e7c1c:	00000000 */ 	nop
/*  f0e7c20:	0560fffb */ 	bltz	$t3,.L0f0e7c10
/*  f0e7c24:	00000000 */ 	nop
.L0f0e7c28:
/*  f0e7c28:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0e7c2c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7c30:	44c9f800 */ 	ctc1	$t1,$31
/*  f0e7c34:	44802000 */ 	mtc1	$zero,$f4
/*  f0e7c38:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0e7c3c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0e7c40:	00000000 */ 	nop
/*  f0e7c44:	4502000a */ 	bc1fl	.L0f0e7c70
/*  f0e7c48:	906a003d */ 	lbu	$t2,0x3d($v1)
/*  f0e7c4c:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7c50:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0e7c54:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7c58:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7c5c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7c60:	00ed3821 */ 	addu	$a3,$a3,$t5
/*  f0e7c64:	10000010 */ 	b	.L0f0e7ca8
/*  f0e7c68:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0e7c6c:	906a003d */ 	lbu	$t2,0x3d($v1)
.L0f0e7c70:
/*  f0e7c70:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e7c74:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7c78:	000a7100 */ 	sll	$t6,$t2,0x4
/*  f0e7c7c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0e7c80:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f0e7c84:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0e7c88:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0e7c8c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0e7c90:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0e7c94:	00594021 */ 	addu	$t0,$v0,$t9
/*  f0e7c98:	8d050020 */ 	lw	$a1,0x20($t0)
/*  f0e7c9c:	0fc01a40 */ 	jal	colourBlend
/*  f0e7ca0:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0e7ca4:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e7ca8:
/*  f0e7ca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7cac:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0e7cb0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7cb4:	0fc01a40 */ 	jal	colourBlend
/*  f0e7cb8:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e7cbc:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0e7cc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7cc4:	0fc01a40 */ 	jal	colourBlend
/*  f0e7cc8:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0e7ccc:	10000053 */ 	b	.L0f0e7e1c
/*  f0e7cd0:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e7cd4:
/*  f0e7cd4:	44816000 */ 	mtc1	$at,$f12
/*  f0e7cd8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e7cdc:	00000000 */ 	nop
/*  f0e7ce0:	3c01437f */ 	lui	$at,0x437f
/*  f0e7ce4:	44813000 */ 	mtc1	$at,$f6
/*  f0e7ce8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7cec:	3c0f7f1b */ 	lui	$t7,%hi(g_MenuColourPalettes)
/*  f0e7cf0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0e7cf4:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(g_MenuColourPalettes)
/*  f0e7cf8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e7cfc:	4449f800 */ 	cfc1	$t1,$31
/*  f0e7d00:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7d04:	00000000 */ 	nop
/*  f0e7d08:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e7d0c:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7d10:	00000000 */ 	nop
/*  f0e7d14:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7d18:	51600013 */ 	beqzl	$t3,.L0f0e7d68
/*  f0e7d1c:	440b5000 */ 	mfc1	$t3,$f10
/*  f0e7d20:	44815000 */ 	mtc1	$at,$f10
/*  f0e7d24:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0e7d28:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e7d2c:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7d30:	00000000 */ 	nop
/*  f0e7d34:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e7d38:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7d3c:	00000000 */ 	nop
/*  f0e7d40:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7d44:	15600005 */ 	bnez	$t3,.L0f0e7d5c
/*  f0e7d48:	00000000 */ 	nop
/*  f0e7d4c:	440b5000 */ 	mfc1	$t3,$f10
/*  f0e7d50:	3c018000 */ 	lui	$at,0x8000
/*  f0e7d54:	10000007 */ 	b	.L0f0e7d74
/*  f0e7d58:	01615825 */ 	or	$t3,$t3,$at
.L0f0e7d5c:
/*  f0e7d5c:	10000005 */ 	b	.L0f0e7d74
/*  f0e7d60:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e7d64:	440b5000 */ 	mfc1	$t3,$f10
.L0f0e7d68:
/*  f0e7d68:	00000000 */ 	nop
/*  f0e7d6c:	0560fffb */ 	bltz	$t3,.L0f0e7d5c
/*  f0e7d70:	00000000 */ 	nop
.L0f0e7d74:
/*  f0e7d74:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f0e7d78:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7d7c:	44c9f800 */ 	ctc1	$t1,$31
/*  f0e7d80:	44809000 */ 	mtc1	$zero,$f18
/*  f0e7d84:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e7d88:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e7d8c:	00000000 */ 	nop
/*  f0e7d90:	4502000a */ 	bc1fl	.L0f0e7dbc
/*  f0e7d94:	906a003d */ 	lbu	$t2,0x3d($v1)
/*  f0e7d98:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7d9c:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0e7da0:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e7da4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0e7da8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e7dac:	00ed3821 */ 	addu	$a3,$a3,$t5
/*  f0e7db0:	10000010 */ 	b	.L0f0e7df4
/*  f0e7db4:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0e7db8:	906a003d */ 	lbu	$t2,0x3d($v1)
.L0f0e7dbc:
/*  f0e7dbc:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0e7dc0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7dc4:	000a7100 */ 	sll	$t6,$t2,0x4
/*  f0e7dc8:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0e7dcc:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f0e7dd0:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0e7dd4:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0e7dd8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0e7ddc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0e7de0:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0e7de4:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0e7de8:	0fc01a40 */ 	jal	colourBlend
/*  f0e7dec:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0e7df0:	00403825 */ 	or	$a3,$v0,$zero
.L0f0e7df4:
/*  f0e7df4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7df8:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0e7dfc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7e00:	0fc01a40 */ 	jal	colourBlend
/*  f0e7e04:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e7e08:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e7e0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7e10:	0fc01a40 */ 	jal	colourBlend
/*  f0e7e14:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e7e18:	00408825 */ 	or	$s1,$v0,$zero
.L0f0e7e1c:
/*  f0e7e1c:	8e0b0010 */ 	lw	$t3,0x10($s0)
/*  f0e7e20:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x20)
/*  f0e7e24:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x20)
/*  f0e7e28:	9162003c */ 	lbu	$v0,0x3c($t3)
/*  f0e7e2c:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0e7e30:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0e7e34:	000c1080 */ 	sll	$v0,$t4,0x2
/*  f0e7e38:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7e3c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7e40:	8ca52138 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x20)($a1)
/*  f0e7e44:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7e48:	8c8422a0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x20)($a0)
/*  f0e7e4c:	1000000e */ 	b	.L0f0e7e88
/*  f0e7e50:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0e7e54:
/*  f0e7e54:	8e0d0010 */ 	lw	$t5,0x10($s0)
/*  f0e7e58:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e7e5c:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e7e60:	91a2003c */ 	lbu	$v0,0x3c($t5)
/*  f0e7e64:	00025100 */ 	sll	$t2,$v0,0x4
/*  f0e7e68:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0e7e6c:	000a1080 */ 	sll	$v0,$t2,0x2
/*  f0e7e70:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7e74:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7e78:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e7e7c:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7e80:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e7e84:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0e7e88:
/*  f0e7e88:	0fc3c962 */ 	jal	menuIsItemDisabled
/*  f0e7e8c:	8e050010 */ 	lw	$a1,0x10($s0)
/*  f0e7e90:	10400038 */ 	beqz	$v0,.L0f0e7f74
/*  f0e7e94:	00000000 */ 	nop
/*  f0e7e98:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7e9c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e7ea0:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e7ea4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e7ea8:	00000000 */ 	nop
/*  f0e7eac:	4502000a */ 	bc1fl	.L0f0e7ed8
/*  f0e7eb0:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0e7eb4:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e7eb8:	3c117f1b */ 	lui	$s1,%hi(g_MenuColourPalettes+0x1c)
/*  f0e7ebc:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0e7ec0:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0e7ec4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0e7ec8:	02388821 */ 	addu	$s1,$s1,$t8
/*  f0e7ecc:	10000012 */ 	b	.L0f0e7f18
/*  f0e7ed0:	8e311fcc */ 	lw	$s1,%lo(g_MenuColourPalettes+0x1c)($s1)
/*  f0e7ed4:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0e7ed8:
/*  f0e7ed8:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0e7edc:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e7ee0:	03270019 */ 	multu	$t9,$a3
/*  f0e7ee4:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0e7ee8:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0e7eec:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7ef0:	00004012 */ 	mflo	$t0
/*  f0e7ef4:	00487821 */ 	addu	$t7,$v0,$t0
/*  f0e7ef8:	8de4001c */ 	lw	$a0,0x1c($t7)
/*  f0e7efc:	01270019 */ 	multu	$t1,$a3
/*  f0e7f00:	00005812 */ 	mflo	$t3
/*  f0e7f04:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0e7f08:	0fc01a40 */ 	jal	colourBlend
/*  f0e7f0c:	8d85001c */ 	lw	$a1,0x1c($t4)
/*  f0e7f10:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e7f14:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0e7f18:
/*  f0e7f18:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f0e7f1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e7f20:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e7f24:	51a00009 */ 	beqzl	$t5,.L0f0e7f4c
/*  f0e7f28:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0e7f2c:	0fc01a40 */ 	jal	colourBlend
/*  f0e7f30:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0e7f34:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7f38:	00415024 */ 	and	$t2,$v0,$at
/*  f0e7f3c:	322e00ff */ 	andi	$t6,$s1,0xff
/*  f0e7f40:	014e8825 */ 	or	$s1,$t2,$t6
/*  f0e7f44:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e7f48:	9062003c */ 	lbu	$v0,0x3c($v1)
.L0f0e7f4c:
/*  f0e7f4c:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x1c)
/*  f0e7f50:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x1c)
/*  f0e7f54:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f0e7f58:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f0e7f5c:	00181080 */ 	sll	$v0,$t8,0x2
/*  f0e7f60:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e7f64:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e7f68:	8ca52134 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x1c)($a1)
/*  f0e7f6c:	0fc54f8e */ 	jal	func0f153e38
/*  f0e7f70:	8c84229c */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x1c)($a0)
.L0f0e7f74:
/*  f0e7f74:	0fc54d8a */ 	jal	func0f153628
/*  f0e7f78:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e7f7c:	86190000 */ 	lh	$t9,0x0($s0)
/*  f0e7f80:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e7f84:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm)
/*  f0e7f88:	2728000a */ 	addiu	$t0,$t9,0xa
/*  f0e7f8c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0e7f90:	860f0002 */ 	lh	$t7,0x2($s0)
/*  f0e7f94:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm)($t4)
/*  f0e7f98:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e7f9c:	25e90002 */ 	addiu	$t1,$t7,0x2
/*  f0e7fa0:	afa90070 */ 	sw	$t1,0x70($sp)
/*  f0e7fa4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e7fa8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e7fac:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e7fb0:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f0e7fb4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7fb8:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0e7fbc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e7fc0:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f0e7fc4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e7fc8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e7fcc:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f0e7fd0:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0e7fd4:	0fc5580f */ 	jal	textRenderProjected
/*  f0e7fd8:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0e7fdc:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0e7fe0:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*  f0e7fe4:	91d8006e */ 	lbu	$t8,0x6e($t6)
/*  f0e7fe8:	53000006 */ 	beqzl	$t8,.L0f0e8004
/*  f0e7fec:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0e7ff0:	86190000 */ 	lh	$t9,0x0($s0)
/*  f0e7ff4:	27280050 */ 	addiu	$t0,$t9,0x50
/*  f0e7ff8:	10000006 */ 	b	.L0f0e8014
/*  f0e7ffc:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0e8000:	860f0000 */ 	lh	$t7,0x0($s0)
.L0f0e8004:
/*  f0e8004:	86090004 */ 	lh	$t1,0x4($s0)
/*  f0e8008:	01e95821 */ 	addu	$t3,$t7,$t1
/*  f0e800c:	256cffc4 */ 	addiu	$t4,$t3,-60
/*  f0e8010:	afac0074 */ 	sw	$t4,0x74($sp)
.L0f0e8014:
/*  f0e8014:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0e8018:	8daa0004 */ 	lw	$t2,0x4($t5)
/*  f0e801c:	314e0080 */ 	andi	$t6,$t2,0x80
/*  f0e8020:	51c00005 */ 	beqzl	$t6,.L0f0e8038
/*  f0e8024:	86080002 */ 	lh	$t0,0x2($s0)
/*  f0e8028:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0e802c:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f0e8030:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0e8034:	86080002 */ 	lh	$t0,0x2($s0)
.L0f0e8038:
/*  f0e8038:	250f0002 */ 	addiu	$t7,$t0,0x2
/*  f0e803c:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0e8040:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f0e8044:	8d2b0010 */ 	lw	$t3,0x10($t1)
/*  f0e8048:	11600034 */ 	beqz	$t3,.L0f0e811c
/*  f0e804c:	00000000 */ 	nop
/*  f0e8050:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0e8054:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0e8058:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e805c:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0e8060:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e8064:	0320f809 */ 	jalr	$t9
/*  f0e8068:	00000000 */ 	nop
/*  f0e806c:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f0e8070:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0e8074:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e8078:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0e807c:	8cb90010 */ 	lw	$t9,0x10($a1)
/*  f0e8080:	0320f809 */ 	jalr	$t9
/*  f0e8084:	00000000 */ 	nop
/*  f0e8088:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicSm)
/*  f0e808c:	8d8cfb0c */ 	lw	$t4,%lo(g_FontHandelGothicSm)($t4)
/*  f0e8090:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e8094:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0e8098:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0e809c:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f0e80a0:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f0e80a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e80a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e80ac:	0fc55cbe */ 	jal	textMeasure
/*  f0e80b0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e80b4:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f0e80b8:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f0e80bc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e80c0:	3c098008 */ 	lui	$t1,%hi(g_CharsHandelGothicSm)
/*  f0e80c4:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0e80c8:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0e80cc:	8d29fb10 */ 	lw	$t1,%lo(g_CharsHandelGothicSm)($t1)
/*  f0e80d0:	01aa7021 */ 	addu	$t6,$t5,$t2
/*  f0e80d4:	01d84023 */ 	subu	$t0,$t6,$t8
/*  f0e80d8:	250ffff6 */ 	addiu	$t7,$t0,-10
/*  f0e80dc:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0e80e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e80e4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e80e8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0e80ec:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0e80f0:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e80f4:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0e80f8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e80fc:	860c0006 */ 	lh	$t4,0x6($s0)
/*  f0e8100:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e8104:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e8108:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f0e810c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0e8110:	0fc5580f */ 	jal	textRenderProjected
/*  f0e8114:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e8118:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0e811c:
/*  f0e811c:	0fc54de0 */ 	jal	func0f153780
/*  f0e8120:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e8124:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8128:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0e812c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0e8130:	03e00008 */ 	jr	$ra
/*  f0e8134:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

bool menuTickItemDropdown(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data)
{
	u32 stack;

	if ((arg3 & 2) && item->handler) {
		if (frame->dimmed && item == frame->focuseditem) {
			menuTickItemList(item, inputs, arg3, data);

			if (mpIsPlayerLockedOut(g_MpPlayerNum)) {
				if ((item->param1 & 0x00040000) || (frame->dialog->unk10 & 0x10)) {
					frame->dimmed = false;
				}
			}
		}

		if (inputs->back && frame->dimmed) {
			frame->dimmed = false;
			inputs->back = false;
			menuPlaySound(MENUSOUND_TOGGLEOFF);
		}

		if (inputs->select) {
			if (frame->dimmed) {
				frame->dimmed = false;
			} else {
				union handlerdata handlerdata;

				frame->dimmed = true;
				menuInitItemDropdown(item, data);

				handlerdata.dropdown.value = 0;
				item->handler(MENUOP_GETOPTIONVALUE, item, &handlerdata);
				data->dropdown.unk0e = handlerdata.dropdown.value * g_LineHeight;
				menuPlaySound(MENUSOUND_TOGGLEOFF);
			}
		}
	}

	return true;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuRenderOverlayDropdown
/*  f0e8290:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0e8294:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0e8298:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0e829c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e82a0:	afb70038 */ 	sw	$s7,0x38($sp)
/*  f0e82a4:	afb60034 */ 	sw	$s6,0x34($sp)
/*  f0e82a8:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0e82ac:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0e82b0:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0e82b4:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0e82b8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e82bc:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0e82c0:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f0e82c4:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f0e82c8:	afa700ac */ 	sw	$a3,0xac($sp)
/*  f0e82cc:	9219006e */ 	lbu	$t9,0x6e($s0)
/*  f0e82d0:	00059400 */ 	sll	$s2,$a1,0x10
/*  f0e82d4:	00127403 */ 	sra	$t6,$s2,0x10
/*  f0e82d8:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0e82dc:	000f3403 */ 	sra	$a2,$t7,0x10
/*  f0e82e0:	13200004 */ 	beqz	$t9,.L0f0e82f4
/*  f0e82e4:	01c09025 */ 	or	$s2,$t6,$zero
/*  f0e82e8:	25c8004e */ 	addiu	$t0,$t6,0x4e
/*  f0e82ec:	1000000a */ 	b	.L0f0e8318
/*  f0e82f0:	a7a8006c */ 	sh	$t0,0x6c($sp)
.L0f0e82f4:
/*  f0e82f4:	87a900ae */ 	lh	$t1,0xae($sp)
/*  f0e82f8:	87ab00ae */ 	lh	$t3,0xae($sp)
/*  f0e82fc:	264a0002 */ 	addiu	$t2,$s2,0x2
/*  f0e8300:	05210003 */ 	bgez	$t1,.L0f0e8310
/*  f0e8304:	024b6021 */ 	addu	$t4,$s2,$t3
/*  f0e8308:	10000003 */ 	b	.L0f0e8318
/*  f0e830c:	a7aa006c */ 	sh	$t2,0x6c($sp)
.L0f0e8310:
/*  f0e8310:	258dffc2 */ 	addiu	$t5,$t4,-62
/*  f0e8314:	a7ad006c */ 	sh	$t5,0x6c($sp)
.L0f0e8318:
/*  f0e8318:	8fb100b4 */ 	lw	$s1,0xb4($sp)
/*  f0e831c:	2658001e */ 	addiu	$t8,$s2,0x1e
/*  f0e8320:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0e8324:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0e8328:	24080038 */ 	addiu	$t0,$zero,0x38
/*  f0e832c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0e8330:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f0e8334:	51e00003 */ 	beqzl	$t7,.L0f0e8344
/*  f0e8338:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0e833c:	a7b8006c */ 	sh	$t8,0x6c($sp)
/*  f0e8340:	8faa00bc */ 	lw	$t2,0xbc($sp)
.L0f0e8344:
/*  f0e8344:	a7b9006e */ 	sh	$t9,0x6e($sp)
/*  f0e8348:	a7a80070 */ 	sh	$t0,0x70($sp)
/*  f0e834c:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f0e8350:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0e8354:	afb0007c */ 	sw	$s0,0x7c($sp)
/*  f0e8358:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f0e835c:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0e8360:	51600073 */ 	beqzl	$t3,.L0f0e8530
/*  f0e8364:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8368:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f0e836c:	50400070 */ 	beqzl	$v0,.L0f0e8530
/*  f0e8370:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8374:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0e8378:	562c006d */ 	bnel	$s1,$t4,.L0f0e8530
/*  f0e837c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e8380:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*  f0e8384:	2418000b */ 	addiu	$t8,$zero,0xb
/*  f0e8388:	3c018007 */ 	lui	$at,%hi(g_LineHeight)
/*  f0e838c:	000d7280 */ 	sll	$t6,$t5,0xa
/*  f0e8390:	05c10009 */ 	bgez	$t6,.L0f0e83b8
/*  f0e8394:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e8398:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e839c:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f0e83a0:	0040f809 */ 	jalr	$v0
/*  f0e83a4:	a7b200a6 */ 	sh	$s2,0xa6($sp)
/*  f0e83a8:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0e83ac:	3c018007 */ 	lui	$at,%hi(g_LineHeight)
/*  f0e83b0:	10000003 */ 	b	.L0f0e83c0
/*  f0e83b4:	ac2f11a8 */ 	sw	$t7,%lo(g_LineHeight)($at)
.L0f0e83b8:
/*  f0e83b8:	ac3811a8 */ 	sw	$t8,%lo(g_LineHeight)($at)
/*  f0e83bc:	a7b200a6 */ 	sh	$s2,0xa6($sp)
.L0f0e83c0:
/*  f0e83c0:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e83c4:	27b7005c */ 	addiu	$s7,$sp,0x5c
/*  f0e83c8:	87b200a6 */ 	lh	$s2,0xa6($sp)
/*  f0e83cc:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e83d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e83d4:	0320f809 */ 	jalr	$t9
/*  f0e83d8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e83dc:	3c088007 */ 	lui	$t0,%hi(g_LineHeight)
/*  f0e83e0:	8fb6005c */ 	lw	$s6,0x5c($sp)
/*  f0e83e4:	8d0811a8 */ 	lw	$t0,%lo(g_LineHeight)($t0)
/*  f0e83e8:	a7a00070 */ 	sh	$zero,0x70($sp)
/*  f0e83ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e83f0:	01160019 */ 	multu	$t0,$s6
/*  f0e83f4:	00004812 */ 	mflo	$t1
/*  f0e83f8:	a7a90072 */ 	sh	$t1,0x72($sp)
/*  f0e83fc:	52c00021 */ 	beqzl	$s6,.L0f0e8484
/*  f0e8400:	87ac00ae */ 	lh	$t4,0xae($sp)
/*  f0e8404:	3c158008 */ 	lui	$s5,%hi(g_FontHandelGothicSm)
/*  f0e8408:	3c148008 */ 	lui	$s4,%hi(g_CharsHandelGothicSm)
/*  f0e840c:	2694fb10 */ 	addiu	$s4,$s4,%lo(g_CharsHandelGothicSm)
/*  f0e8410:	26b5fb0c */ 	addiu	$s5,$s5,%lo(g_FontHandelGothicSm)
/*  f0e8414:	27b30098 */ 	addiu	$s3,$sp,0x98
/*  f0e8418:	27b20094 */ 	addiu	$s2,$sp,0x94
/*  f0e841c:	afb0005c */ 	sw	$s0,0x5c($sp)
.L0f0e8420:
/*  f0e8420:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e8424:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e8428:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e842c:	0320f809 */ 	jalr	$t9
/*  f0e8430:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e8434:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0e8438:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e843c:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e8440:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e8444:	8e870000 */ 	lw	$a3,0x0($s4)
/*  f0e8448:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e844c:	0fc55cbe */ 	jal	textMeasure
/*  f0e8450:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e8454:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0e8458:	87ab0070 */ 	lh	$t3,0x70($sp)
/*  f0e845c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0e8460:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f0e8464:	0162082a */ 	slt	$at,$t3,$v0
/*  f0e8468:	10200003 */ 	beqz	$at,.L0f0e8478
/*  f0e846c:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e8470:	a7a20070 */ 	sh	$v0,0x70($sp)
/*  f0e8474:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e8478:
/*  f0e8478:	5616ffe9 */ 	bnel	$s0,$s6,.L0f0e8420
/*  f0e847c:	afb0005c */ 	sw	$s0,0x5c($sp)
/*  f0e8480:	87ac00ae */ 	lh	$t4,0xae($sp)
.L0f0e8484:
/*  f0e8484:	87ad00a6 */ 	lh	$t5,0xa6($sp)
/*  f0e8488:	59800007 */ 	blezl	$t4,.L0f0e84a8
/*  f0e848c:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0e8490:	87af0070 */ 	lh	$t7,0x70($sp)
/*  f0e8494:	01ac7021 */ 	addu	$t6,$t5,$t4
/*  f0e8498:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0e849c:	2708fff9 */ 	addiu	$t0,$t8,-7
/*  f0e84a0:	a7a8006c */ 	sh	$t0,0x6c($sp)
/*  f0e84a4:	8fa500b8 */ 	lw	$a1,0xb8($sp)
.L0f0e84a8:
/*  f0e84a8:	87b9006e */ 	lh	$t9,0x6e($sp)
/*  f0e84ac:	87aa0072 */ 	lh	$t2,0x72($sp)
/*  f0e84b0:	8ca30020 */ 	lw	$v1,0x20($a1)
/*  f0e84b4:	8ca90018 */ 	lw	$t1,0x18($a1)
/*  f0e84b8:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f0e84bc:	01232021 */ 	addu	$a0,$t1,$v1
/*  f0e84c0:	248d0002 */ 	addiu	$t5,$a0,0x2
/*  f0e84c4:	01ab082a */ 	slt	$at,$t5,$t3
/*  f0e84c8:	10200014 */ 	beqz	$at,.L0f0e851c
/*  f0e84cc:	006a082a */ 	slt	$at,$v1,$t2
/*  f0e84d0:	1020000e */ 	beqz	$at,.L0f0e850c
/*  f0e84d4:	3c028007 */ 	lui	$v0,%hi(g_LineHeight)
/*  f0e84d8:	8c4211a8 */ 	lw	$v0,%lo(g_LineHeight)($v0)
/*  f0e84dc:	00608025 */ 	or	$s0,$v1,$zero
/*  f0e84e0:	0062001b */ 	divu	$zero,$v1,$v0
/*  f0e84e4:	00008012 */ 	mflo	$s0
/*  f0e84e8:	14400002 */ 	bnez	$v0,.L0f0e84f4
/*  f0e84ec:	00000000 */ 	nop
/*  f0e84f0:	0007000d */ 	break	0x7
.L0f0e84f4:
/*  f0e84f4:	02020019 */ 	multu	$s0,$v0
/*  f0e84f8:	00008012 */ 	mflo	$s0
/*  f0e84fc:	a7b00072 */ 	sh	$s0,0x72($sp)
/*  f0e8500:	8cae0020 */ 	lw	$t6,0x20($a1)
/*  f0e8504:	8cac0018 */ 	lw	$t4,0x18($a1)
/*  f0e8508:	018e2021 */ 	addu	$a0,$t4,$t6
.L0f0e850c:
/*  f0e850c:	87af0072 */ 	lh	$t7,0x72($sp)
/*  f0e8510:	008fc023 */ 	subu	$t8,$a0,$t7
/*  f0e8514:	27080002 */ 	addiu	$t0,$t8,0x2
/*  f0e8518:	a7a8006e */ 	sh	$t0,0x6e($sp)
.L0f0e851c:
/*  f0e851c:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0e8520:	0fc398ca */ 	jal	menuRenderItemList
/*  f0e8524:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0e8528:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0e852c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0e8530:
/*  f0e8530:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0e8534:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0e8538:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0e853c:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0e8540:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0e8544:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0e8548:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0e854c:	8fb60034 */ 	lw	$s6,0x34($sp)
/*  f0e8550:	8fb70038 */ 	lw	$s7,0x38($sp)
/*  f0e8554:	03e00008 */ 	jr	$ra
/*  f0e8558:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);
#else
GLOBAL_ASM(
glabel menuRenderOverlayDropdown
/*  f0e5428:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0e542c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0e5430:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0e5434:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e5438:	afb70038 */ 	sw	$s7,0x38($sp)
/*  f0e543c:	afb60034 */ 	sw	$s6,0x34($sp)
/*  f0e5440:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0e5444:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0e5448:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0e544c:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0e5450:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e5454:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0e5458:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f0e545c:	afa600a8 */ 	sw	$a2,0xa8($sp)
/*  f0e5460:	afa700ac */ 	sw	$a3,0xac($sp)
/*  f0e5464:	920a006e */ 	lbu	$t2,0x6e($s0)
/*  f0e5468:	00057400 */ 	sll	$t6,$a1,0x10
/*  f0e546c:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f0e5470:	0006c400 */ 	sll	$t8,$a2,0x10
/*  f0e5474:	00074400 */ 	sll	$t0,$a3,0x10
/*  f0e5478:	00083c03 */ 	sra	$a3,$t0,0x10
/*  f0e547c:	00183403 */ 	sra	$a2,$t8,0x10
/*  f0e5480:	11400004 */ 	beqz	$t2,.NB0f0e5494
/*  f0e5484:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0e5488:	25eb004e */ 	addiu	$t3,$t7,0x4e
/*  f0e548c:	10000004 */ 	beqz	$zero,.NB0f0e54a0
/*  f0e5490:	a7ab006c */ 	sh	$t3,0x6c($sp)
.NB0f0e5494:
/*  f0e5494:	00a76021 */ 	addu	$t4,$a1,$a3
/*  f0e5498:	258dffc2 */ 	addiu	$t5,$t4,-62
/*  f0e549c:	a7ad006c */ 	sh	$t5,0x6c($sp)
.NB0f0e54a0:
/*  f0e54a0:	8fb100b4 */ 	lw	$s1,0xb4($sp)
/*  f0e54a4:	24b8001e */ 	addiu	$t8,$a1,0x1e
/*  f0e54a8:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0e54ac:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0e54b0:	24080038 */ 	addiu	$t0,$zero,0x38
/*  f0e54b4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0e54b8:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f0e54bc:	51e00003 */ 	beqzl	$t7,.NB0f0e54cc
/*  f0e54c0:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0e54c4:	a7b8006c */ 	sh	$t8,0x6c($sp)
/*  f0e54c8:	8faa00bc */ 	lw	$t2,0xbc($sp)
.NB0f0e54cc:
/*  f0e54cc:	a7b9006e */ 	sh	$t9,0x6e($sp)
/*  f0e54d0:	a7a80070 */ 	sh	$t0,0x70($sp)
/*  f0e54d4:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f0e54d8:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0e54dc:	afb0007c */ 	sw	$s0,0x7c($sp)
/*  f0e54e0:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f0e54e4:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0e54e8:	5160006e */ 	beqzl	$t3,.NB0f0e56a4
/*  f0e54ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e54f0:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f0e54f4:	5040006b */ 	beqzl	$v0,.NB0f0e56a4
/*  f0e54f8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e54fc:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0e5500:	00a76821 */ 	addu	$t5,$a1,$a3
/*  f0e5504:	562c0067 */ 	bnel	$s1,$t4,.NB0f0e56a4
/*  f0e5508:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e550c:	afad0048 */ 	sw	$t5,0x48($sp)
/*  f0e5510:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f0e5514:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0e5518:	3c018007 */ 	lui	$at,0x8007
/*  f0e551c:	000e7a80 */ 	sll	$t7,$t6,0xa
/*  f0e5520:	05e10008 */ 	bgez	$t7,.NB0f0e5544
/*  f0e5524:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e5528:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e552c:	0040f809 */ 	jalr	$v0
/*  f0e5530:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f0e5534:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f0e5538:	3c018007 */ 	lui	$at,0x8007
/*  f0e553c:	10000002 */ 	beqz	$zero,.NB0f0e5548
/*  f0e5540:	ac383858 */ 	sw	$t8,0x3858($at)
.NB0f0e5544:
/*  f0e5544:	ac393858 */ 	sw	$t9,0x3858($at)
.NB0f0e5548:
/*  f0e5548:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e554c:	27b7005c */ 	addiu	$s7,$sp,0x5c
/*  f0e5550:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e5554:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e5558:	0320f809 */ 	jalr	$t9
/*  f0e555c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e5560:	3c088007 */ 	lui	$t0,0x8007
/*  f0e5564:	8fb6005c */ 	lw	$s6,0x5c($sp)
/*  f0e5568:	8d083858 */ 	lw	$t0,0x3858($t0)
/*  f0e556c:	a7a00070 */ 	sh	$zero,0x70($sp)
/*  f0e5570:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5574:	01160019 */ 	multu	$t0,$s6
/*  f0e5578:	00004812 */ 	mflo	$t1
/*  f0e557c:	a7a90072 */ 	sh	$t1,0x72($sp)
/*  f0e5580:	52c00021 */ 	beqzl	$s6,.NB0f0e5608
/*  f0e5584:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0e5588:	3c158008 */ 	lui	$s5,0x8008
/*  f0e558c:	3c148008 */ 	lui	$s4,0x8008
/*  f0e5590:	26942370 */ 	addiu	$s4,$s4,0x2370
/*  f0e5594:	26b5236c */ 	addiu	$s5,$s5,0x236c
/*  f0e5598:	27b30098 */ 	addiu	$s3,$sp,0x98
/*  f0e559c:	27b20094 */ 	addiu	$s2,$sp,0x94
/*  f0e55a0:	afb0005c */ 	sw	$s0,0x5c($sp)
.NB0f0e55a4:
/*  f0e55a4:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e55a8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e55ac:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e55b0:	0320f809 */ 	jalr	$t9
/*  f0e55b4:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e55b8:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0e55bc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e55c0:	02602825 */ 	or	$a1,$s3,$zero
/*  f0e55c4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e55c8:	8e870000 */ 	lw	$a3,0x0($s4)
/*  f0e55cc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e55d0:	0fc54655 */ 	jal	textMeasure
/*  f0e55d4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e55d8:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0e55dc:	87ab0070 */ 	lh	$t3,0x70($sp)
/*  f0e55e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0e55e4:	24420006 */ 	addiu	$v0,$v0,0x6
/*  f0e55e8:	0162082a */ 	slt	$at,$t3,$v0
/*  f0e55ec:	10200003 */ 	beqz	$at,.NB0f0e55fc
/*  f0e55f0:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e55f4:	a7a20070 */ 	sh	$v0,0x70($sp)
/*  f0e55f8:	afa20098 */ 	sw	$v0,0x98($sp)
.NB0f0e55fc:
/*  f0e55fc:	5616ffe9 */ 	bnel	$s0,$s6,.NB0f0e55a4
/*  f0e5600:	afb0005c */ 	sw	$s0,0x5c($sp)
/*  f0e5604:	8fac0048 */ 	lw	$t4,0x48($sp)
.NB0f0e5608:
/*  f0e5608:	87ad0070 */ 	lh	$t5,0x70($sp)
/*  f0e560c:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0e5610:	87a8006e */ 	lh	$t0,0x6e($sp)
/*  f0e5614:	018d7023 */ 	subu	$t6,$t4,$t5
/*  f0e5618:	25cffff9 */ 	addiu	$t7,$t6,-7
/*  f0e561c:	a7af006c */ 	sh	$t7,0x6c($sp)
/*  f0e5620:	8cb80018 */ 	lw	$t8,0x18($a1)
/*  f0e5624:	8ca30020 */ 	lw	$v1,0x20($a1)
/*  f0e5628:	87a90072 */ 	lh	$t1,0x72($sp)
/*  f0e562c:	03032021 */ 	addu	$a0,$t8,$v1
/*  f0e5630:	248a0002 */ 	addiu	$t2,$a0,0x2
/*  f0e5634:	0109c821 */ 	addu	$t9,$t0,$t1
/*  f0e5638:	0159082a */ 	slt	$at,$t2,$t9
/*  f0e563c:	10200014 */ 	beqz	$at,.NB0f0e5690
/*  f0e5640:	0069082a */ 	slt	$at,$v1,$t1
/*  f0e5644:	1020000e */ 	beqz	$at,.NB0f0e5680
/*  f0e5648:	3c028007 */ 	lui	$v0,0x8007
/*  f0e564c:	8c423858 */ 	lw	$v0,0x3858($v0)
/*  f0e5650:	00608025 */ 	or	$s0,$v1,$zero
/*  f0e5654:	0062001b */ 	divu	$zero,$v1,$v0
/*  f0e5658:	00008012 */ 	mflo	$s0
/*  f0e565c:	14400002 */ 	bnez	$v0,.NB0f0e5668
/*  f0e5660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e5664:	0007000d */ 	break	0x7
.NB0f0e5668:
/*  f0e5668:	02020019 */ 	multu	$s0,$v0
/*  f0e566c:	00008012 */ 	mflo	$s0
/*  f0e5670:	a7b00072 */ 	sh	$s0,0x72($sp)
/*  f0e5674:	8cac0020 */ 	lw	$t4,0x20($a1)
/*  f0e5678:	8cab0018 */ 	lw	$t3,0x18($a1)
/*  f0e567c:	016c2021 */ 	addu	$a0,$t3,$t4
.NB0f0e5680:
/*  f0e5680:	87ad0072 */ 	lh	$t5,0x72($sp)
/*  f0e5684:	008d7023 */ 	subu	$t6,$a0,$t5
/*  f0e5688:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f0e568c:	a7af006e */ 	sh	$t7,0x6e($sp)
.NB0f0e5690:
/*  f0e5690:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0e5694:	0fc38de8 */ 	jal	menuRenderItemList
/*  f0e5698:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0e569c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0e56a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f0e56a4:
/*  f0e56a4:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0e56a8:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0e56ac:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0e56b0:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0e56b4:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0e56b8:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0e56bc:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0e56c0:	8fb60034 */ 	lw	$s6,0x34($sp)
/*  f0e56c4:	8fb70038 */ 	lw	$s7,0x38($sp)
/*  f0e56c8:	03e00008 */ 	jr	$ra
/*  f0e56cc:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);
#endif

// Mismatch due to register initialisation order near 380.
// 0x14 (MENUOP_GETOPTIONHEIGHT) is loaded into a0 earlier than it should be.
//Gfx *menuRenderOverlayDropdown(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data)
//{
//	s32 stack;
//	s32 textwidth; // 98
//	s32 textheight; // 94
//	s32 numoptions;
//	s32 i;
//	char *text;
//	s32 stack2;
//	struct menurendercontext context; // 6c
//
//	// 2e0
//	if (frame->unk6e) {
//		context.x = x + 78;
//	} else if (x2 < 0) {
//		context.x = x + 2;
//	} else {
//		context.x = x + x2 - 62;
//	}
//
//	// 334
//	if (item->param1 & 0x00000080) {
//		context.x = x + 30;
//	}
//
//	// 340
//	context.y = y + 1;
//	context.width = 56;
//	context.item = item;
//	context.focused = true;
//	context.frame = frame;
//	context.data = data;
//
//	// 360
//	if (frame->dimmed && item->handler && frame->focuseditem == item) {
//		// 380
//		union handlerdata handlerdata; // 5c
//
//		if (item->param1 & 0x00200000) {
//			union handlerdata handlerdata2; // 4c
//			item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
//			g_LineHeight = handlerdata2.dropdown.value;
//		} else {
//			g_LineHeight = 11;
//		}
//
//		// 3c0
//		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);
//		numoptions = handlerdata.dropdown.value;
//
//		context.width = 0;
//		context.height = (s32)g_LineHeight * numoptions;
//
//		for (i = 0; i != numoptions; i++) {
//			// 420
//			handlerdata.dropdown.value = i;
//			text = (char *)item->handler(MENUOP_GETOPTIONTEXT, item, &handlerdata);
//			textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
//			textwidth += 6;
//
//			if (textwidth > context.width) {
//				context.width = textwidth;
//			}
//		}
//
//		// 480
//		if (x2 > 0) {
//			context.x = x + x2 - context.width - 7;
//		}
//
//		// 4a4
//		if (context.y + context.height > frame->y + frame->height + 2) {
//			// 4d0
//			if (context.height > frame->height) {
//				i = frame->height;
//				i = i / g_LineHeight;
//				i = i * g_LineHeight;
//				context.height = i;
//			}
//
//			// 50c
//			context.y = frame->y + frame->height - context.height + 2;
//		}
//
//		// 51c
//		gdl = menuRenderItemList(gdl, &context);
//	}
//
//	return gdl;
//}

bool menuIsStringEmptyOrSpaces(char *text)
{
	s32 i;

	if (text[0] == '\0') {
		return true;
	}

	i = 0;

	while (text[i] != '\0') {
		if (text[i] != ' ') {
			return false;
		}

		i++;
	}

	return true;
}

/**
 * Keyboard reference:
 * +---------------------------------------+
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
 * |---+---+---+---+---+---+---+---+---+---|
 * | a | b | c | d | e | f | g | h | i | j |
 * |---+---+---+---+---+---+---+---+---+---|
 * | k | l | m | n | o | p | q | r | s | t |
 * |---+---+---+---+---+---+---+---+---+---|
 * | u | v | w | x | y | z |   | ? | ! | . |
 * |-------+-----------+-----------+-------|
 * |  DEL  |    CAPS   |   CANCEL  |   OK  |
 * +-------+-----------+-----------+-------+
 */
Gfx *menuRenderItemKeyboard(Gfx *gdl, struct menurendercontext *context)
{
	char label[8];
	s32 x;
	s32 y;
	struct menuitemdata_keyboard *data = &context->data->keyboard;
	u32 cursorcolour;
	u32 textcolour;
	u32 tmpcolour;
	s32 buttonwidth;
	s32 row;
	s32 col;
	s32 rowspan;
	u32 alpha;
	s32 textheight;
	s32 textwidth;

	label[1] = '\n';
	label[2] = '\0';

	func0f153e38(
			g_MenuColourPalettes3[context->frame->type].unfocused,
			g_MenuColourPalettes2[context->frame->type].unfocused);

	// Draw input field background
	gdl = gfxSetPrimColour(gdl, 0x0000ff7f);

	if (context->item->param3 == 0) {
		// Half width
		gDPFillRectangleScaled(gdl++,
				context->x + 4, context->y + 1,
				context->x + 63, context->y + 10);
	} else {
		// Full width
		gDPFillRectangleScaled(gdl++,
				context->x + 4, context->y + 1,
				context->x + 125, context->y + 10);
	}

	// Render text value
	gdl = func0f153838(gdl);

	x = context->x + 4;
	y = context->y + 2;

	gdl = func0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, data->string, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, context->width, context->height, 0, 0);
	gdl = func0f153780(gdl);

	// Render cursor
	alpha = func0f006b08(40) * 255;

	if (context->frame->transitiontimer < 0) {
		cursorcolour = g_MenuColourPalettes[context->frame->type].focused;
	} else {
		cursorcolour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].focused,
				g_MenuColourPalettes[context->frame->type].focused,
				context->frame->colourweight);
	}

	cursorcolour = colourBlend(colourBlend(0x0000ffff, 0x000000ff, 127), cursorcolour, alpha);

	gdl = gfxSetPrimColour(gdl, cursorcolour);

	gDPFillRectangleScaled(gdl++, x + 1, context->y + 2, x + 3, context->y + 9);

	gdl = func0f153838(gdl);

	// Render horizontal grid lines
	for (row = 0; row < 6; row++) {
		gdl = renderFilledRect(gdl, context->x + 4, context->y + row * 11 + 13,
				context->x + 124, context->y + row * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	// Render vertical grid lines
	for (col = 0; col < 11; col++) {
		rowspan = 5;

		if (col == 1 || col == 3 || col == 4 || col == 6 || col == 7 || col == 9) {
			rowspan = 4;
		}

		gdl = renderFilledRect(gdl, context->x + col * 12 + 4, context->y + 13,
				context->x + col * 12 + 5, context->y + rowspan * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	gdl = func0f153628(gdl);

	x = context->x + 10;
	y = context->y + 2;

	for (col = 0; col < 10; col++) {
		for (row = 0; row < 5; row++) {
			if (context->frame->transitiontimer < 0) {
				textcolour = g_MenuColourPalettes[context->frame->type].unfocused;
			} else {
				textcolour = colourBlend(
						g_MenuColourPalettes[context->frame->type2].unfocused,
						g_MenuColourPalettes[context->frame->type].unfocused,
						context->frame->colourweight);
			}

			if (context->frame->dimmed) {
				textcolour = colourBlend(textcolour, 0x00000000, 127) & 0xffffff00 | textcolour & 0xff;
			}

			if (data->capseffective && col == 2 && row == 4) {
				// CAPS button - make it yellow
				textcolour = textcolour & 0xff | 0xffff0000;
			}

			// If this button is the focused one, set highlighted colour
			if (col == data->col && row == data->row) {
				alpha = func0f006b08(40) * 255;

				if (context->frame->transitiontimer < 0) {
					tmpcolour = g_MenuColourPalettes[context->frame->type].focused;
				} else {
					tmpcolour = colourBlend(
							g_MenuColourPalettes[context->frame->type2].focused,
							g_MenuColourPalettes[context->frame->type].focused,
							context->frame->colourweight);
				}

				textcolour = colourBlend(colourBlend(textcolour, textcolour & 0xff, 127), tmpcolour, alpha);
			}

			x = context->x + col * 12 + 4;
			y = context->y + row * 11 + 15;

			if (row == 4) {
				u16 labels[] = {
					L_OPTIONS_314, // "DEL"
					L_OPTIONS_315, // "CAPS"
					L_OPTIONS_316, // "CANCEL"
					L_OPTIONS_317, // "OK"
				};

				s32 index = -1;

				if (col == 0) {
					index = 0;
				}

				if (col == 2) {
					index = 1;
				}

				if (col == 5) {
					index = 2;
				}

				if (col == 8) {
					index = 3;
				}

				if (index >= 0) {
					buttonwidth = 24;
					y++;

					if (index == 1 || index == 2) {
						buttonwidth = 36;
					}

					textMeasure(&textheight, &textwidth, langGet(labels[index]), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
					x = (buttonwidth - textwidth) / 2 + x;

					// Dim the OK button if string is empty
					if (index == 3 && menuIsStringEmptyOrSpaces(data->string)) {
						if (context->frame->transitiontimer < 0) {
							textcolour = g_MenuColourPalettes[context->frame->type].disabled;
						} else {
							textcolour = colourBlend(
									g_MenuColourPalettes[context->frame->type2].disabled,
									g_MenuColourPalettes[context->frame->type].disabled,
									context->frame->colourweight);
						}

						if (context->frame->dimmed) {
							textcolour = colourBlend(textcolour, 0, 127) & 0xffffff00 | textcolour & 0xff;
						}

						func0f153e38(
								g_MenuColourPalettes3[context->frame->type].disabled,
								g_MenuColourPalettes2[context->frame->type].disabled);
					}

					gdl = textRenderProjected(gdl, &x, &y, langGet(labels[index]), g_CharsHandelGothicXs, g_FontHandelGothicXs, textcolour, context->width, context->height, 0, 0);

					if (index == 3 && menuIsStringEmptyOrSpaces(data->string)) {
						func0f153e38(
								g_MenuColourPalettes3[context->frame->type].unfocused,
								g_MenuColourPalettes2[context->frame->type].unfocused);
					}
				}
			} else {
				// Alpha-numeric cell
				label[0] = g_KeyboardKeys[row][col];

				if (!data->capseffective && label[0] >= 'A' && label[0] <= 'Z') {
					// Make lowercase
					label[0] += 32;
				}

				textMeasure(&textheight, &textwidth, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
				x = (12 - textwidth) / 2 + x;
				gdl = textRenderProjected(gdl, &x, &y, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
			}
		}
	}

	gdl = func0f153780(gdl);

	// Highlight border of focused button
	{
		s32 x1 = context->x + data->col * 12 + 4;
		s32 x2 = context->x + data->col * 12 + 16;
		s32 y1 = context->y + data->row * 11 + 13;
		s32 y2 = context->y + data->row * 11 + 24;

		if (data->row == 4) {
			if (data->col == 8) {
				x2 += 12;
			}

			if (data->col == 5) {
				x2 += 24;
			}

			if (data->col == 2) {
				x2 += 24;
			}

			if (data->col == 0) {
				x2 += 12;
			}
		}

		gdl = renderLine(gdl, x1, y1, x2, y1 + 1, -1, -1); // top
		gdl = renderLine(gdl, x2, y1, x2 + 1, y2 + 1, -1, -1); // right
		gdl = renderLine(gdl, x1, y2, x2, y2 + 1, -1, -1); // bottom
		gdl = renderLine(gdl, x1, y1, x1 + 1, y2 + 1, -1, -1); // left
	}

	return gdl;
}

/**
 * Keyboard reference:
 * +---------------------------------------+
 * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
 * |---+---+---+---+---+---+---+---+---+---|
 * | a | b | c | d | e | f | g | h | i | j |
 * |---+---+---+---+---+---+---+---+---+---|
 * | k | l | m | n | o | p | q | r | s | t |
 * |---+---+---+---+---+---+---+---+---+---|
 * | u | v | w | x | y | z |   | ? | ! | . |
 * |-------+-----------+-----------+-------|
 * |  DEL  |    CAPS   |   CANCEL  |   OK  |
 * +-------+-----------+-----------+-------+
 */
bool menuTickItemKeyboard(struct menuitem *item, struct menuinputs *inputs, u32 arg2, union menuitemdata *data)
{
	struct menuitemdata_keyboard *kb = &data->keyboard;
	union handlerdata handlerdata;
	s32 delete = false;

	if (arg2 & 2) {
		s16 prevcol = kb->col;
		s16 prevrow = kb->row;

		// Handle left/right movement
		// In most cases the loop only runs once, but on row 4 the buttons span
		// across multiple columns so the loop will run again until the column
		// number is valid.
		if (inputs->leftright != 0) {
			do {
				kb->col += inputs->leftright;

				if (kb->col < 0) {
					kb->col = 9;
				}

				if (kb->col > 9) {
					kb->col = 0;
				}
			} while (kb->row == 4 && kb->col != 0 && kb->col != 2 && kb->col != 5 && kb->col != 8);
		}

		// Handle up/down movement
		if (inputs->updown) {
			kb->row += inputs->updown;

			if (kb->row < 0) {
				kb->row = 4;
			}

			if (kb->row > 4) {
				kb->row = 0;
			}

			// If moving onto row 4, bump column to a valid one
			if (kb->row == 4) {
				if (kb->col == 9) {
					kb->col = 8;
				}

				if (kb->col == 7 || kb->col == 6) {
					kb->col = 5;
				}

				if (kb->col == 3 || kb->col == 4) {
					kb->col = 2;
				}

				if (kb->col == 1) {
					kb->col = 0;
				}
			}
		}

		if (prevcol != kb->col || prevrow != kb->row) {
			menuPlaySound(MENUSOUND_KEYBOARDFOCUS);
		}

		if (inputs->back2) {
			delete = true;
		}

		if (inputs->start) {
			if (item->handler && !menuIsStringEmptyOrSpaces(kb->string)) {
				menuPlaySound(MENUSOUND_SELECT);

				handlerdata.keyboard.string = kb->string;
				item->handler(MENUOP_SETTEXT, item, &handlerdata);

				menuPopDialog();

				item->handler(MENUOP_SET, item, &handlerdata);
			}

			inputs->start = false;
		}

		if (inputs->select) {
			if (kb->row == 4) {
				// DEL
				if (kb->col == 0) {
					delete = true;
				}

				// CAPS
				if (kb->col == 2) {
					kb->capslock = 1 - kb->capslock;
				}

				// OK
				if (kb->col == 8) {
					if (item->handler && !menuIsStringEmptyOrSpaces(kb->string)) {
						handlerdata.keyboard.string = kb->string;
						item->handler(MENUOP_SETTEXT, item, &handlerdata);
					}
				}

				// OK or CANCEL
				if (kb->col == 8 || kb->col == 5) {
					s32 ok = (kb->col == 8);

					if (kb->col == 5 || !menuIsStringEmptyOrSpaces(kb->string)) {
						menuPopDialog();

						if (ok) {
							item->handler(MENUOP_SET, item, &handlerdata);
							menuPlaySound(MENUSOUND_SELECT);
						} else {
							menuPlaySound(MENUSOUND_KEYBOARDCANCEL);
						}

						inputs->select = false;
					}
				}
			} else {
				// Pressed A on number or letter
				s32 appended = false;
				s32 i;
				s32 textwidth;
				s32 textheight;

				if (kb->string[9] == '\0') {
					// String is not full
					i = 0;

					while (!appended) {
						if (kb->string[i] == '\0') {
							u8 key = g_KeyboardKeys[kb->row][kb->col];
							appended = true;

							if (kb->capseffective == 0 && key >= 'A' && key <= 'Z') {
								// Make lowercase
								key += 32;
							}

							kb->string[i] = key;
						}

						i++;
					}

					textMeasure(&textheight, &textwidth, kb->string, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

					if (item->param3 == 0 && textwidth > 58) {
						delete = true;
					}

					if (!delete) {
						menuPlaySound(MENUSOUND_FOCUS);
					}
				}
			}
		}

		// Handle deleting
		if (delete && kb->string[0] != '\0') {
			s32 deleted = false;
			s32 i = 10;

			menuPlaySound(MENUSOUND_FOCUS);

			while (!deleted) {
				if (kb->string[i] != '\0') {
					kb->string[i] = '\0';
					deleted = true;
				}

				i--;
			}
		}
	}

	// Update caps
	if (arg2 & 2) {
		u32 prev = kb->capseffective;
		kb->capseffective = kb->capslock;

		if (inputs->shoulder) {
			// Invert
			kb->capseffective = 1 - kb->capseffective;
		}

		if (kb->capseffective != prev) {
			if (kb->capseffective) {
				menuPlaySound(MENUSOUND_TOGGLEON);
			} else {
				menuPlaySound(MENUSOUND_TOGGLEOFF);
			}
		}
	}

	return true;
}

void menuInitItemKeyboard(struct menuitem *item, union menuitemdata *data)
{
	u32 stack;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(data->keyboard.string);) {
		data->keyboard.string[i++] = '\0';
	}

	if (item->handler) {
		union handlerdata handlerdata;
		handlerdata.keyboard.string = data->keyboard.string;
		item->handler(MENUOP_GETTEXT, item, &handlerdata);
	}

	data->keyboard.col = 0;
	data->keyboard.row = 4;
	data->keyboard.capseffective = 0;
	data->keyboard.capslock = 0;
}

Gfx *menuRenderItemSeparator(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;

	if (context->frame->transitiontimer < 0) {
		colour = g_MenuColourPalettes[context->frame->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].unfocused,
				g_MenuColourPalettes[context->frame->type].unfocused,
				context->frame->colourweight);
	}

	colour = (colour & 0xffffff00) | 0x3f;

	return renderFilledRect(gdl,
			context->x, context->y + 2, context->x + context->width, context->y + 3,
			colour, colour);
}

u32 var800711e8 = 0;

#if PAL
GLOBAL_ASM(
glabel menuRenderObjective
/*  f0e98ac:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e98b0:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e98b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e98b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e98bc:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e98c0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e98c4:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e98c8:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e98cc:	11c00002 */ 	beqz	$t6,.L0f0e98d8
/*  f0e98d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e98d4:	2402000c */ 	addiu	$v0,$zero,0x10
.L0f0e98d8:
/*  f0e98d8:	3c047f1b */ 	lui	$a0,%hi(var7f1adfa0)
/*  f0e98dc:	3c058007 */ 	lui	$a1,%hi(var800711e8)
/*  f0e98e0:	24a511e8 */ 	addiu	$a1,$a1,%lo(var800711e8)
/*  f0e98e4:	2484dfa0 */ 	addiu	$a0,$a0,%lo(var7f1adfa0)
/*  f0e98e8:	0c0036cc */ 	jal	func0000db30
/*  f0e98ec:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e98f0:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e98f4:	3c04800a */ 	lui	$a0,%hi(g_Briefing+0x2)
/*  f0e98f8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e98fc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e9900:	0fc5b9f1 */ 	jal	langGet
/*  f0e9904:	9484dfca */ 	lhu	$a0,%lo(g_Briefing+0x2)($a0)
/*  f0e9908:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e990c:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e9910:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e9914:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e9918:	44803000 */ 	mtc1	$zero,$f6
/*  f0e991c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e9920:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e9924:	00000000 */ 	nop
/*  f0e9928:	4502000b */ 	bc1fl	.L0f0e9958
/*  f0e992c:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e9930:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e9934:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e9938:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e993c:	01300019 */ 	multu	$t1,$s0
/*  f0e9940:	00005012 */ 	mflo	$t2
/*  f0e9944:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e9948:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e994c:	10000012 */ 	b	.L0f0e9998
/*  f0e9950:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e9954:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0e9958:
/*  f0e9958:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e995c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e9960:	01900019 */ 	multu	$t4,$s0
/*  f0e9964:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0e9968:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0e996c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e9970:	00006812 */ 	mflo	$t5
/*  f0e9974:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e9978:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e997c:	03100019 */ 	multu	$t8,$s0
/*  f0e9980:	0000c812 */ 	mflo	$t9
/*  f0e9984:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e9988:	0fc01a40 */ 	jal	colourBlend
/*  f0e998c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e9990:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e9994:	8fa30134 */ 	lw	$v1,0x134($sp)
.L0f0e9998:
/*  f0e9998:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e999c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e99a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e99a4:	5140000b */ 	beqzl	$t2,.L0f0e99d4
/*  f0e99a8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e99ac:	0fc01a40 */ 	jal	colourBlend
/*  f0e99b0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e99b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e99b8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e99bc:	00415824 */ 	and	$t3,$v0,$at
/*  f0e99c0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e99c4:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e99c8:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e99cc:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e99d0:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0e99d4:
/*  f0e99d4:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e99d8:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e99dc:	03100019 */ 	multu	$t8,$s0
/*  f0e99e0:	00001012 */ 	mflo	$v0
/*  f0e99e4:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e99e8:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e99ec:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e99f0:	0fc54f8e */ 	jal	func0f153e38
/*  f0e99f4:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e99f8:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e99fc:	0fc54d8a */ 	jal	func0f153628
/*  f0e9a00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a04:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e9a08:	3c057f1b */ 	lui	$a1,%hi(var7f1adfa8)
/*  f0e9a0c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9a10:	24a5dfa8 */ 	addiu	$a1,$a1,%lo(var7f1adfa8)
/*  f0e9a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9a18:	0c004dad */ 	jal	sprintf
/*  f0e9a1c:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e9a20:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm)
/*  f0e9a24:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm)($t9)
/*  f0e9a28:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9a2c:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0e9a30:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9a34:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9a38:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9a3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9a40:	0fc55cbe */ 	jal	textMeasure
/*  f0e9a44:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e9a48:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9a4c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e9a50:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e9a54:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm)
/*  f0e9a58:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm)($t5)
/*  f0e9a5c:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e9a60:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9a64:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9a68:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9a6c:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e9a70:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e9a74:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e9a78:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a7c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9a80:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9a84:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9a8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9a90:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9a94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9a98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9a9c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9aa0:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9aa4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9aa8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9aac:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e9ab0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9ab4:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e9ab8:	1140001f */ 	beqz	$t2,.L0f0e9b38
/*  f0e9abc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9ac0:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs)
/*  f0e9ac4:	8d8cfb04 */ 	lw	$t4,%lo(g_FontHandelGothicXs)($t4)
/*  f0e9ac8:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9acc:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9ad0:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e9ad4:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e9ad8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9adc:	0fc55d48 */ 	jal	textWrap
/*  f0e9ae0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9ae4:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicXs)
/*  f0e9ae8:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9aec:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9af0:	8d6bfb08 */ 	lw	$t3,%lo(g_CharsHandelGothicXs)($t3)
/*  f0e9af4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9af8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9afc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9b00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b04:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b08:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b0c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b18:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9b1c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9b20:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9b24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9b28:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9b30:	1000001a */ 	b	.L0f0e9b9c
/*  f0e9b34:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b38:
/*  f0e9b38:	3c057f1b */ 	lui	$a1,%hi(var7f1adfb0)
/*  f0e9b3c:	24a5dfb0 */ 	addiu	$a1,$a1,%lo(var7f1adfb0)
/*  f0e9b40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9b44:	0c004dad */ 	jal	sprintf
/*  f0e9b48:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e9b4c:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicSm)
/*  f0e9b50:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicSm)
/*  f0e9b54:	8d29fb0c */ 	lw	$t1,%lo(g_FontHandelGothicSm)($t1)
/*  f0e9b58:	8dcefb10 */ 	lw	$t6,%lo(g_CharsHandelGothicSm)($t6)
/*  f0e9b5c:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e9b60:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e9b64:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e9b68:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b6c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b70:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b78:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b80:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e9b84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9b88:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e9b8c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e9b90:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b94:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e9b98:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b9c:
/*  f0e9b9c:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e9ba0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9ba4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9ba8:	11a00141 */ 	beqz	$t5,.L0f0ea0b0
/*  f0e9bac:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9bb0:	0fc255a1 */ 	jal	objectiveCheck
/*  f0e9bb4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e9bb8:	10400007 */ 	beqz	$v0,.L0f0e9bd8
/*  f0e9bbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e9bc0:	1041000c */ 	beq	$v0,$at,.L0f0e9bf4
/*  f0e9bc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e9bc8:	10410011 */ 	beq	$v0,$at,.L0f0e9c10
/*  f0e9bcc:	00000000 */ 	nop
/*  f0e9bd0:	10000015 */ 	b	.L0f0e9c28
/*  f0e9bd4:	00000000 */ 	nop
.L0f0e9bd8:
/*  f0e9bd8:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bdc:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e9be0:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e9be4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e9be8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9bec:	1000000e */ 	b	.L0f0e9c28
/*  f0e9bf0:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L0f0e9bf4:
/*  f0e9bf4:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bf8:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e9bfc:	3c1800ff */ 	lui	$t8,0xff
/*  f0e9c00:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e9c04:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c08:	10000007 */ 	b	.L0f0e9c28
/*  f0e9c0c:	afb800c8 */ 	sw	$t8,0xc8($sp)
.L0f0e9c10:
/*  f0e9c10:	0fc5b9f1 */ 	jal	langGet
/*  f0e9c14:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e9c18:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e9c1c:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e9c20:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c24:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0e9c28:
/*  f0e9c28:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0e9c2c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0e9c30:	3c0c800a */ 	lui	$t4,%hi(g_Menus+0x4f8)
/*  f0e9c34:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e9c38:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e9c3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e9c44:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0e9c48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e9c4c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c50:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e9c54:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e9c58:	8d8ce4f8 */ 	lw	$t4,%lo(g_Menus+0x4f8)($t4)
/*  f0e9c5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9c60:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9c64:	11cc0004 */ 	beq	$t6,$t4,.L0f0e9c78
/*  f0e9c68:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9c6c:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e9c70:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e9c74:	afab00c8 */ 	sw	$t3,0xc8($sp)
.L0f0e9c78:
/*  f0e9c78:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9c7c:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9c80:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e9c84:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9c88:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9c8c:	0fc55cbe */ 	jal	textMeasure
/*  f0e9c90:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9c94:	3c028007 */ 	lui	$v0,%hi(var800711e8)
/*  f0e9c98:	8c4211e8 */ 	lw	$v0,%lo(var800711e8)($v0)
/*  f0e9c9c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9ca0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9ca4:	10400002 */ 	beqz	$v0,.L0f0e9cb0
/*  f0e9ca8:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0e9cac:	afa200c8 */ 	sw	$v0,0xc8($sp)
.L0f0e9cb0:
/*  f0e9cb0:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e9cb4:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e9cb8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9cbc:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e9cc0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e9cc4:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e9cc8:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0e9ccc:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0e9cd0:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9cd4:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0e9cd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e9cdc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9ce0:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e9ce4:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9ce8:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e9cec:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9cf0:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9cf4:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9cf8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9cfc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d00:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d08:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e9d0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e9d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d14:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9d18:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d1c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e9d20:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d24:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e9d28:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicXs)
/*  f0e9d2c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f0e9d30:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e9d34:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f0e9d38:	8d4afb08 */ 	lw	$t2,%lo(g_CharsHandelGothicXs)($t2)
/*  f0e9d3c:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e9d40:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9d44:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e9d48:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9d4c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9d50:	01815824 */ 	and	$t3,$t4,$at
/*  f0e9d54:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9d58:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e9d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d60:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9d64:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9d68:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d74:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9d78:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e9d7c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9d80:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e9d84:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d8c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d90:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e9d94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d98:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e9d9c:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e9da0:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e9da4:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e9da8:	0fc54de0 */ 	jal	func0f153780
/*  f0e9dac:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e9db0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9db4:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e9db8:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e9dbc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e9dc0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e9dc4:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e9dc8:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e9dcc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e9dd0:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e9dd4:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e9dd8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e9ddc:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e9de0:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e9de4:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e9de8:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e9dec:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e9df0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e9df4:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e9df8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e9dfc:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e9e00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e04:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e9e08:	04610003 */ 	bgez	$v1,.L0f0e9e18
/*  f0e9e0c:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e9e10:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e9e14:	00015083 */ 	sra	$t2,$at,0x2
.L0f0e9e18:
/*  f0e9e18:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e9e1c:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e9e20:	01cd0019 */ 	multu	$t6,$t5
/*  f0e9e24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9e28:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e9e2c:	00007812 */ 	mflo	$t7
/*  f0e9e30:	00000000 */ 	nop
/*  f0e9e34:	00000000 */ 	nop
/*  f0e9e38:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e9e3c:	0000c012 */ 	mflo	$t8
/*  f0e9e40:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e9e44:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e9e48:	0fc38926 */ 	jal	func0f0e2498
/*  f0e9e4c:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e9e50:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e9e54:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9e58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9e5c:	00616024 */ 	and	$t4,$v1,$at
/*  f0e9e60:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e9e64:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e9e68:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9e6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9e70:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e9e74:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e9e78:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e9e7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e80:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9e84:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9eb4:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9eb8:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9ebc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e9ec0:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e9ec4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e9ec8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e9ecc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9ed0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e9ed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ed8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9edc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9ee0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9ee4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e9ee8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9eec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e9ef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ef4:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e9ef8:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e9efc:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f00:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e9f04:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f0c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9f14:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9f18:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f20:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e9f24:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f28:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e9f2c:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f30:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f38:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f3c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9f40:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f44:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e9f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f4c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e9f50:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e9f54:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9f5c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f64:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9f6c:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9f70:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9f74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e9f78:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e9f7c:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e9f80:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e9f84:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f88:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e9f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f94:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f9c:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fa4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9fa8:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e9fac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9fb0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e9fb4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9fb8:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9fbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fc0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea00c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ea010:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ea014:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ea018:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea01c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0ea020:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea024:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea028:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea02c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ea030:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea034:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea038:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea03c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0ea040:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea044:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ea048:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea04c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea050:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea054:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ea058:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea05c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ea060:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0ea064:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ea068:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea06c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea070:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea074:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea078:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea07c:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ea080:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0ea084:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea088:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0ea08c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea090:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ea094:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea098:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea09c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea0a0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea0a4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea0a8:	10000074 */ 	b	.L0f0ea27c
/*  f0ea0ac:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea0b0:
/*  f0ea0b0:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0ea0b4:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0ea0b8:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0ea0bc:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0ea0c0:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0ea0c4:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0ea0c8:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0ea0cc:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0ea0d0:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0ea0d4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0ea0d8:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0ea0dc:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0ea0e0:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0ea0e4:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea0e8:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0ea0ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea0f0:	0fc55cbe */ 	jal	textMeasure
/*  f0ea0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea0f8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea0fc:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0ea100:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea104:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ea108:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0ea10c:	0fc54de0 */ 	jal	func0f153780
/*  f0ea110:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0ea114:	0fc38926 */ 	jal	func0f0e2498
/*  f0ea118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea11c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0ea120:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea124:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea128:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea12c:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea130:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0ea134:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea13c:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea140:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea144:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0ea148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea14c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0ea150:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea17c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea180:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0ea184:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea188:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0ea18c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0ea190:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0ea194:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0ea198:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0ea19c:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0ea1a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea1a4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0ea1a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1b0:	01602825 */ 	or	$a1,$t3,$zero
/*  f0ea1b4:	04e10003 */ 	bgez	$a3,.L0f0ea1c4
/*  f0ea1b8:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0ea1bc:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0ea1c0:	00016883 */ 	sra	$t5,$at,0x2
.L0f0ea1c4:
/*  f0ea1c4:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0ea1c8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ea1cc:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0ea1d4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea1d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0ea1dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0ea1e4:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0ea1e8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea1ec:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0ea1f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea1f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1f8:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea224:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea228:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea22c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ea230:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea234:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0ea238:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ea23c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea240:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ea244:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea24c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#else
GLOBAL_ASM(
glabel menuRenderObjective
/*  f0e98ac:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e98b0:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e98b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e98b8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e98bc:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e98c0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e98c4:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e98c8:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e98cc:	11c00002 */ 	beqz	$t6,.L0f0e98d8
/*  f0e98d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e98d4:	2402000c */ 	addiu	$v0,$zero,0xc
.L0f0e98d8:
/*  f0e98d8:	3c047f1b */ 	lui	$a0,%hi(var7f1adfa0)
/*  f0e98dc:	3c058007 */ 	lui	$a1,%hi(var800711e8)
/*  f0e98e0:	24a511e8 */ 	addiu	$a1,$a1,%lo(var800711e8)
/*  f0e98e4:	2484dfa0 */ 	addiu	$a0,$a0,%lo(var7f1adfa0)
/*  f0e98e8:	0c0036cc */ 	jal	func0000db30
/*  f0e98ec:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e98f0:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e98f4:	3c04800a */ 	lui	$a0,%hi(g_Briefing+0x2)
/*  f0e98f8:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e98fc:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e9900:	0fc5b9f1 */ 	jal	langGet
/*  f0e9904:	9484dfca */ 	lhu	$a0,%lo(g_Briefing+0x2)($a0)
/*  f0e9908:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e990c:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e9910:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e9914:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e9918:	44803000 */ 	mtc1	$zero,$f6
/*  f0e991c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e9920:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e9924:	00000000 */ 	nop
/*  f0e9928:	4502000b */ 	bc1fl	.L0f0e9958
/*  f0e992c:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e9930:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e9934:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e9938:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e993c:	01300019 */ 	multu	$t1,$s0
/*  f0e9940:	00005012 */ 	mflo	$t2
/*  f0e9944:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e9948:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e994c:	10000012 */ 	b	.L0f0e9998
/*  f0e9950:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e9954:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0e9958:
/*  f0e9958:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e995c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e9960:	01900019 */ 	multu	$t4,$s0
/*  f0e9964:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0e9968:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0e996c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e9970:	00006812 */ 	mflo	$t5
/*  f0e9974:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e9978:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e997c:	03100019 */ 	multu	$t8,$s0
/*  f0e9980:	0000c812 */ 	mflo	$t9
/*  f0e9984:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e9988:	0fc01a40 */ 	jal	colourBlend
/*  f0e998c:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e9990:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e9994:	8fa30134 */ 	lw	$v1,0x134($sp)
.L0f0e9998:
/*  f0e9998:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e999c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e99a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e99a4:	5140000b */ 	beqzl	$t2,.L0f0e99d4
/*  f0e99a8:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e99ac:	0fc01a40 */ 	jal	colourBlend
/*  f0e99b0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e99b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e99b8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e99bc:	00415824 */ 	and	$t3,$v0,$at
/*  f0e99c0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e99c4:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e99c8:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e99cc:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e99d0:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0e99d4:
/*  f0e99d4:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0e99d8:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0e99dc:	03100019 */ 	multu	$t8,$s0
/*  f0e99e0:	00001012 */ 	mflo	$v0
/*  f0e99e4:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e99e8:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e99ec:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0e99f0:	0fc54f8e */ 	jal	func0f153e38
/*  f0e99f4:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0e99f8:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e99fc:	0fc54d8a */ 	jal	func0f153628
/*  f0e9a00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a04:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e9a08:	3c057f1b */ 	lui	$a1,%hi(var7f1adfa8)
/*  f0e9a0c:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9a10:	24a5dfa8 */ 	addiu	$a1,$a1,%lo(var7f1adfa8)
/*  f0e9a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9a18:	0c004dad */ 	jal	sprintf
/*  f0e9a1c:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e9a20:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicSm)
/*  f0e9a24:	8f39fb0c */ 	lw	$t9,%lo(g_FontHandelGothicSm)($t9)
/*  f0e9a28:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9a2c:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0e9a30:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9a34:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9a38:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9a3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9a40:	0fc55cbe */ 	jal	textMeasure
/*  f0e9a44:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e9a48:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9a4c:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e9a50:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicSm)
/*  f0e9a54:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicSm)
/*  f0e9a58:	8dadfb0c */ 	lw	$t5,%lo(g_FontHandelGothicSm)($t5)
/*  f0e9a5c:	8d6bfb10 */ 	lw	$t3,%lo(g_CharsHandelGothicSm)($t3)
/*  f0e9a60:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9a64:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9a68:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9a6c:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e9a70:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e9a74:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e9a78:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9a7c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9a80:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9a84:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9a8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9a90:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9a94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9a98:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9a9c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9aa0:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9aa4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9aa8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e9aac:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e9ab0:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e9ab4:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e9ab8:	1140001f */ 	beqz	$t2,.L0f0e9b38
/*  f0e9abc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9ac0:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs)
/*  f0e9ac4:	8d8cfb04 */ 	lw	$t4,%lo(g_FontHandelGothicXs)($t4)
/*  f0e9ac8:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9acc:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9ad0:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e9ad4:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e9ad8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e9adc:	0fc55d48 */ 	jal	textWrap
/*  f0e9ae0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9ae4:	3c0b8008 */ 	lui	$t3,%hi(g_CharsHandelGothicXs)
/*  f0e9ae8:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9aec:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9af0:	8d6bfb08 */ 	lw	$t3,%lo(g_CharsHandelGothicXs)($t3)
/*  f0e9af4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e9af8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e9afc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e9b00:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b04:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b08:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b0c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b18:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e9b1c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9b20:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e9b24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e9b28:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e9b30:	1000001a */ 	b	.L0f0e9b9c
/*  f0e9b34:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b38:
/*  f0e9b38:	3c057f1b */ 	lui	$a1,%hi(var7f1adfb0)
/*  f0e9b3c:	24a5dfb0 */ 	addiu	$a1,$a1,%lo(var7f1adfb0)
/*  f0e9b40:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e9b44:	0c004dad */ 	jal	sprintf
/*  f0e9b48:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e9b4c:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicSm)
/*  f0e9b50:	3c098008 */ 	lui	$t1,%hi(g_FontHandelGothicSm)
/*  f0e9b54:	8d29fb0c */ 	lw	$t1,%lo(g_FontHandelGothicSm)($t1)
/*  f0e9b58:	8dcefb10 */ 	lw	$t6,%lo(g_CharsHandelGothicSm)($t6)
/*  f0e9b5c:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e9b60:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e9b64:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e9b68:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9b6c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9b70:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e9b78:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9b7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9b80:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e9b84:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9b88:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e9b8c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e9b90:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9b94:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e9b98:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0e9b9c:
/*  f0e9b9c:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e9ba0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9ba4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9ba8:	11a00141 */ 	beqz	$t5,.L0f0ea0b0
/*  f0e9bac:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0e9bb0:	0fc255a1 */ 	jal	objectiveCheck
/*  f0e9bb4:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e9bb8:	10400007 */ 	beqz	$v0,.L0f0e9bd8
/*  f0e9bbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e9bc0:	1041000c */ 	beq	$v0,$at,.L0f0e9bf4
/*  f0e9bc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e9bc8:	10410011 */ 	beq	$v0,$at,.L0f0e9c10
/*  f0e9bcc:	00000000 */ 	nop
/*  f0e9bd0:	10000015 */ 	b	.L0f0e9c28
/*  f0e9bd4:	00000000 */ 	nop
.L0f0e9bd8:
/*  f0e9bd8:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bdc:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e9be0:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e9be4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e9be8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9bec:	1000000e */ 	b	.L0f0e9c28
/*  f0e9bf0:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L0f0e9bf4:
/*  f0e9bf4:	0fc5b9f1 */ 	jal	langGet
/*  f0e9bf8:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e9bfc:	3c1800ff */ 	lui	$t8,0xff
/*  f0e9c00:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e9c04:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c08:	10000007 */ 	b	.L0f0e9c28
/*  f0e9c0c:	afb800c8 */ 	sw	$t8,0xc8($sp)
.L0f0e9c10:
/*  f0e9c10:	0fc5b9f1 */ 	jal	langGet
/*  f0e9c14:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e9c18:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e9c1c:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e9c20:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e9c24:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L0f0e9c28:
/*  f0e9c28:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0e9c2c:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0e9c30:	3c0c800a */ 	lui	$t4,%hi(g_Menus+0x4f8)
/*  f0e9c34:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e9c38:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e9c3c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c40:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e9c44:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0e9c48:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e9c4c:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e9c50:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e9c54:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e9c58:	8d8ce4f8 */ 	lw	$t4,%lo(g_Menus+0x4f8)($t4)
/*  f0e9c5c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e9c60:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e9c64:	11cc0004 */ 	beq	$t6,$t4,.L0f0e9c78
/*  f0e9c68:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f0e9c6c:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0x18)
/*  f0e9c70:	8d6b1fc8 */ 	lw	$t3,%lo(g_MenuColourPalettes+0x18)($t3)
/*  f0e9c74:	afab00c8 */ 	sw	$t3,0xc8($sp)
.L0f0e9c78:
/*  f0e9c78:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs)
/*  f0e9c7c:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs)($t5)
/*  f0e9c80:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e9c84:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f0e9c88:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e9c8c:	0fc55cbe */ 	jal	textMeasure
/*  f0e9c90:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9c94:	3c028007 */ 	lui	$v0,%hi(var800711e8)
/*  f0e9c98:	8c4211e8 */ 	lw	$v0,%lo(var800711e8)($v0)
/*  f0e9c9c:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9ca0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9ca4:	10400002 */ 	beqz	$v0,.L0f0e9cb0
/*  f0e9ca8:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0e9cac:	afa200c8 */ 	sw	$v0,0xc8($sp)
.L0f0e9cb0:
/*  f0e9cb0:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e9cb4:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e9cb8:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9cbc:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e9cc0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e9cc4:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e9cc8:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0e9ccc:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0e9cd0:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9cd4:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0e9cd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e9cdc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9ce0:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e9ce4:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9ce8:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e9cec:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9cf0:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9cf4:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e9cf8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e9cfc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d00:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d04:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d08:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e9d0c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e9d10:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d14:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e9d18:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d1c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e9d20:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d24:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e9d28:	3c0a8008 */ 	lui	$t2,%hi(g_CharsHandelGothicXs)
/*  f0e9d2c:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f0e9d30:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e9d34:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f0e9d38:	8d4afb08 */ 	lw	$t2,%lo(g_CharsHandelGothicXs)($t2)
/*  f0e9d3c:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e9d40:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e9d44:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e9d48:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e9d4c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e9d50:	01815824 */ 	and	$t3,$t4,$at
/*  f0e9d54:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e9d58:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e9d5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d60:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e9d64:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e9d68:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e9d6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e9d70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e9d74:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e9d78:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e9d7c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9d80:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e9d84:	0fc5580f */ 	jal	textRenderProjected
/*  f0e9d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e9d8c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e9d90:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e9d94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9d98:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e9d9c:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e9da0:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e9da4:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e9da8:	0fc54de0 */ 	jal	func0f153780
/*  f0e9dac:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e9db0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9db4:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e9db8:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e9dbc:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e9dc0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e9dc4:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e9dc8:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e9dcc:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e9dd0:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e9dd4:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e9dd8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e9ddc:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e9de0:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e9de4:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e9de8:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e9dec:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e9df0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e9df4:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e9df8:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e9dfc:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e9e00:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e04:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e9e08:	04610003 */ 	bgez	$v1,.L0f0e9e18
/*  f0e9e0c:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e9e10:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e9e14:	00015083 */ 	sra	$t2,$at,0x2
.L0f0e9e18:
/*  f0e9e18:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e9e1c:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e9e20:	01cd0019 */ 	multu	$t6,$t5
/*  f0e9e24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e9e28:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e9e2c:	00007812 */ 	mflo	$t7
/*  f0e9e30:	00000000 */ 	nop
/*  f0e9e34:	00000000 */ 	nop
/*  f0e9e38:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e9e3c:	0000c012 */ 	mflo	$t8
/*  f0e9e40:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e9e44:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e9e48:	0fc38926 */ 	jal	func0f0e2498
/*  f0e9e4c:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e9e50:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e9e54:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9e58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e9e5c:	00616024 */ 	and	$t4,$v1,$at
/*  f0e9e60:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e9e64:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e9e68:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e9e6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9e70:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e9e74:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e9e78:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e9e7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e80:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9e84:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e9eb4:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9eb8:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9ebc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e9ec0:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e9ec4:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e9ec8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e9ecc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9ed0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e9ed4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ed8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e9edc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9ee0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9ee4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e9ee8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9eec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e9ef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ef4:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e9ef8:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e9efc:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f00:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e9f04:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f0c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e9f14:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9f18:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f1c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f20:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e9f24:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f28:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e9f2c:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f30:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f34:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f38:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f3c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9f40:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9f44:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e9f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f4c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e9f50:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e9f54:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e9f58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9f5c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f64:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e9f6c:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9f70:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e9f74:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e9f78:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e9f7c:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e9f80:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e9f84:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9f88:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e9f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9f90:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9f94:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9f98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9f9c:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e9fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fa4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e9fa8:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e9fac:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e9fb0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e9fb4:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9fb8:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e9fbc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fc0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	func0f0e2744
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea00c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ea010:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ea014:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ea018:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea01c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0ea020:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea024:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea028:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea02c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ea030:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea034:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea038:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea03c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0ea040:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea044:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ea048:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea04c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea050:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea054:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0ea058:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea05c:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ea060:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0ea064:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ea068:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea06c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea070:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea074:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea078:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea07c:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0ea080:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0ea084:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea088:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0ea08c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea090:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0ea094:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0ea098:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ea09c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea0a0:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea0a4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea0a8:	10000074 */ 	b	.L0f0ea27c
/*  f0ea0ac:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea0b0:
/*  f0ea0b0:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0ea0b4:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0ea0b8:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0ea0bc:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicSm)
/*  f0ea0c0:	8d6bfb0c */ 	lw	$t3,%lo(g_FontHandelGothicSm)($t3)
/*  f0ea0c4:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0ea0c8:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0ea0cc:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0ea0d0:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0ea0d4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0ea0d8:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0ea0dc:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0ea0e0:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0ea0e4:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea0e8:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0ea0ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea0f0:	0fc55cbe */ 	jal	textMeasure
/*  f0ea0f4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea0f8:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea0fc:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0ea100:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea104:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0ea108:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0ea10c:	0fc54de0 */ 	jal	func0f153780
/*  f0ea110:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0ea114:	0fc38926 */ 	jal	func0f0e2498
/*  f0ea118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea11c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0ea120:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea124:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea128:	00614824 */ 	and	$t1,$v1,$at
/*  f0ea12c:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0ea130:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0ea134:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea13c:	01201825 */ 	or	$v1,$t1,$zero
/*  f0ea140:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea144:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0ea148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea14c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0ea150:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea17c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea180:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0ea184:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea188:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0ea18c:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0ea190:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0ea194:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0ea198:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0ea19c:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0ea1a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea1a4:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0ea1a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1b0:	01602825 */ 	or	$a1,$t3,$zero
/*  f0ea1b4:	04e10003 */ 	bgez	$a3,.L0f0ea1c4
/*  f0ea1b8:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0ea1bc:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0ea1c0:	00016883 */ 	sra	$t5,$at,0x2
.L0f0ea1c4:
/*  f0ea1c4:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0ea1c8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ea1cc:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1d0:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0ea1d4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea1d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0ea1dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea1e0:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0ea1e4:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0ea1e8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea1ec:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0ea1f0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea1f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea1f8:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea224:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea228:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea22c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ea230:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea234:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0ea238:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0ea23c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea240:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0ea244:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea24c:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	func0f0e2744
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#endif

Gfx *menuRenderItemObjectives(Gfx *gdl, struct menurendercontext *context)
{
	s32 y = context->y + 5;
	s32 position = 1;
	s32 i;

	for (i = 0; i < 6; i++) {
		if (g_Briefing.objectivenames[i]
				&& g_Briefing.objectivedifficulties[i] & (1 << lvGetDifficulty())) {
			gdl = menuRenderObjective(gdl,
					context->frame,
					i, position, context->x, y, context->width, context->height,
					context->item->param != 1,
					context->item->param == 2);

			position++;

			if (context->item->param == 0) {
				y += 18;
			} else if (context->item->param == 2) {
				y += PAL ? 34 : 30;
			} else {
				y += 14;
			}
		}
	}

	return gdl;
}

Gfx *menuRenderItemModel(Gfx *gdl, struct menurendercontext *context)
{
	if (context->item->param1 & 0x00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;

		if (context->frame->transitiontimer < 0) {
			renderdata.colour = g_MenuColourPalettes[context->frame->type].focused;
		} else {
			renderdata.colour = colourBlend(
					g_MenuColourPalettes[context->frame->type2].focused,
					g_MenuColourPalettes[context->frame->type].focused,
					context->frame->colourweight);
		}

		if (context->frame->dimmed) {
			renderdata.colour = (colourBlend(renderdata.colour, 0, 127) & 0xffffff00) | (renderdata.colour & 0xff);
		}

		renderdata.unk10 = true;

		data.type19.gdl = gdl;
		data.type19.renderdata1 = &renderdata;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *)context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

Gfx *menuRenderItemLabel(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour1;
	u32 colour2;
	char *text;
	s32 x;
	s32 y;
	struct menudfc *menudfc;
	u8 savedvalue = var8007fb9c;
	struct fontchar *font1 = g_CharsHandelGothicSm;
	struct font *font2 = g_FontHandelGothicSm;

	x = context->x + 10;
	y = context->y + 2;

	if (context->item->param1 & 0x00000010) {
		x -= 6;
	}

	text = menuResolveParam2Text(context->item);

	if (!text) {
		return gdl;
	}

	if (context->item->param1 & 0x00000200) {
		font1 = g_CharsHandelGothicXs;
		font2 = g_FontHandelGothicXs;
		y -= 2;
	}

	if (context->item->param1 & 0x00000020) {
		// Center
		s32 textheight;
		s32 textwidth;
		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
		x = context->x + (context->width - textwidth) / 2;
	}

	if (context->item->param1 & 0x00000100) {
		if (context->frame->transitiontimer < 0) {
			colour1 = g_MenuColourPalettes[context->frame->type].checkedunfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->frame->type2].checkedunfocused,
					g_MenuColourPalettes[context->frame->type].checkedunfocused,
					context->frame->colourweight);
		}

		if (context->frame->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->frame->type].checkedunfocused,
				g_MenuColourPalettes2[context->frame->type].checkedunfocused);
	} else {
		if (context->frame->transitiontimer < 0) {
			colour1 = g_MenuColourPalettes[context->frame->type].unfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->frame->type2].unfocused,
					g_MenuColourPalettes[context->frame->type].unfocused,
					context->frame->colourweight);
		}

		if (context->frame->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->frame->type].unfocused,
				g_MenuColourPalettes2[context->frame->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->frame)) {
		if (context->frame->transitiontimer < 0) {
			colour1 = g_MenuColourPalettes[context->frame->type].disabled;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->frame->type2].disabled,
					g_MenuColourPalettes[context->frame->type].disabled,
					context->frame->colourweight);
		}

		if (context->frame->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->frame->type].disabled,
				g_MenuColourPalettes2[context->frame->type].disabled);
	}

	menudfc = func0f0f1338(context->item);

	if (menudfc) {
		if (menudfc->unk04 < 0) {
			return gdl;
		}

		func0f153c50();
		func0f153c20(x, y, menudfc->unk04 * 300, 0);
		var8007fb9c = 1;
	}

	colour2 = colour1;

	if (context->item->param1 & 0x01000000) {
		union handlerdata data;
		data.label.colour2 = colour2;
		data.label.colour1 = colour1;

		if (context->item->handlervoid) {
			context->item->handlervoid(MENUOP_GETCOLOUR, context->item, &data);
		}

		if (context->item->handlervoid) {
		}

		colour2 = data.label.colour2;
		colour1 = data.label.colour1;
	}

	gdl = func0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, text,
			font1, font2, colour1, context->width, context->height, 0, 0);

	if ((context->item->param1 & 0x00008000) == 0) {
		// Right side text
		text = menuResolveText(context->item->param3, context->item);

		// This is not how you check if a string is empty...
		if (text != NULL && text != "") {
			s32 textheight;
			s32 textwidth;

			y = context->y + 2;

			if (context->item->param1 & 0x00000200) {
				y -= 2;
			}

			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
			x = context->x + context->width - textwidth - 10;

			if (context->item->param1 & 0x00000010) {
				x += 6;
			}

			gdl = textRenderProjected(gdl, &x, &y, text,
					font1, font2, colour2, context->width, context->height, 0, 0);
		}
	}

	gdl = func0f153780(gdl);

	if (menudfc) {
		if (context->width + 200 < menudfc->unk04 * 300 && context->frame->unk48 < 0) {
			func0f0f13ec(context->item);
		}

		var8007fb9c = savedvalue;

		func0f153c88();
	}

	if (context->item->param1 & 0x00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;
		renderdata.colour = colour1;
		renderdata.unk10 = false;

		data.type19.gdl = gdl;
		data.type19.renderdata1 = NULL;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *) context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

/**
 * Renders two yellow bars and an optional label. Suspected to be a resource
 * meter but with the calculations ifdeffed out, so the widths are static.
 */
Gfx *menuRenderItemMeter(Gfx *gdl, struct menurendercontext *context)
{
	u32 a = 9;
	char *text;
	s32 x;
	s32 y;
	u32 colour1;
	u32 colour2;
	u32 colour;
	s32 x1;
	s32 x2;
	s32 x3;

	if (context->frame->transitiontimer < 0) {
		colour = g_MenuColourPalettes[context->frame->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].unfocused,
				g_MenuColourPalettes[context->frame->type].unfocused,
				context->frame->colourweight);
	}

	if (context->frame->dimmed) {
		colour = (colourBlend(colour, 0, 127) & 0xffffff00) | (colour & 0xff);
	}

	colour2 = 0xffff0000 | (colour & 0xff);
	colour1 = colourBlend(colour2, colour2 & 0xff, 127);

	x1 = context->x + 32;
	x2 = x1 + a;
	x3 = x2 + 6;

	gdl = gfxSetPrimColour(gdl, colour1);
	gDPFillRectangleScaled(gdl++, x1, context->y, x2, context->y + 5);
	gdl = func0f153838(gdl);

	gdl = gfxSetPrimColour(gdl, colour2);
	gDPFillRectangleScaled(gdl++, x2, context->y, x3, context->y + 5);
	gdl = func0f153838(gdl);

	text = menuResolveParam2Text(context->item);

	if (text) {
		gdl = func0f153628(gdl);
		x = context->x;
		y = context->y - 1;
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
				colour2 & 0xffffff7f, context->width, context->height, 0, 0);
		gdl = func0f153780(gdl);
	}

	return gdl;
}

GLOBAL_ASM(
glabel menuRenderItemSelectable
/*  f0eaec0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0eaec4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0eaec8:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0eaecc:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0eaed0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f0eaed4:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0eaed8:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicSm)
/*  f0eaedc:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm)
/*  f0eaee0:	25cf000a */ 	addiu	$t7,$t6,0xa
/*  f0eaee4:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f0eaee8:	84b80002 */ 	lh	$t8,0x2($a1)
/*  f0eaeec:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0eaef0:	8c63fb10 */ 	lw	$v1,%lo(g_CharsHandelGothicSm)($v1)
/*  f0eaef4:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0eaef8:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0eaefc:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f0eaf00:	8ce7fb0c */ 	lw	$a3,%lo(g_FontHandelGothicSm)($a3)
/*  f0eaf04:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f0eaf08:	30480010 */ 	andi	$t0,$v0,0x10
/*  f0eaf0c:	11000004 */ 	beqz	$t0,.L0f0eaf20
/*  f0eaf10:	25eafffa */ 	addiu	$t2,$t7,-6
/*  f0eaf14:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0eaf18:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f0eaf1c:	8cc20004 */ 	lw	$v0,0x4($a2)
.L0f0eaf20:
/*  f0eaf20:	00025a40 */ 	sll	$t3,$v0,0x9
/*  f0eaf24:	05610005 */ 	bgez	$t3,.L0f0eaf3c
/*  f0eaf28:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0eaf2c:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicMd)
/*  f0eaf30:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicMd)
/*  f0eaf34:	8c63fb18 */ 	lw	$v1,%lo(g_CharsHandelGothicMd)($v1)
/*  f0eaf38:	8ce7fb14 */ 	lw	$a3,%lo(g_FontHandelGothicMd)($a3)
.L0f0eaf3c:
/*  f0eaf3c:	afa30068 */ 	sw	$v1,0x68($sp)
/*  f0eaf40:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eaf44:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f0eaf48:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0eaf4c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eaf50:	44803000 */ 	mtc1	$zero,$f6
/*  f0eaf54:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eaf58:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eaf5c:	00000000 */ 	nop
/*  f0eaf60:	4502000a */ 	bc1fl	.L0f0eaf8c
/*  f0eaf64:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0eaf68:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0eaf6c:	3c117f1b */ 	lui	$s1,%hi(g_MenuColourPalettes+0x18)
/*  f0eaf70:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0eaf74:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eaf78:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eaf7c:	022d8821 */ 	addu	$s1,$s1,$t5
/*  f0eaf80:	10000013 */ 	b	.L0f0eafd0
/*  f0eaf84:	8e311fc8 */ 	lw	$s1,%lo(g_MenuColourPalettes+0x18)($s1)
/*  f0eaf88:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0eaf8c:
/*  f0eaf8c:	9068003c */ 	lbu	$t0,0x3c($v1)
/*  f0eaf90:	3c187f1b */ 	lui	$t8,%hi(g_MenuColourPalettes)
/*  f0eaf94:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0eaf98:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eaf9c:	27181fb0 */ 	addiu	$t8,$t8,%lo(g_MenuColourPalettes)
/*  f0eafa0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0eafa4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eafa8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eafac:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0eafb0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0eafb4:	01385021 */ 	addu	$t2,$t1,$t8
/*  f0eafb8:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f0eafbc:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0eafc0:	0fc01a40 */ 	jal	colourBlend
/*  f0eafc4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eafc8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eafcc:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0eafd0:
/*  f0eafd0:	8c6b000c */ 	lw	$t3,0xc($v1)
/*  f0eafd4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eafd8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eafdc:	51600008 */ 	beqzl	$t3,.L0f0eb000
/*  f0eafe0:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f0eafe4:	0fc01a40 */ 	jal	colourBlend
/*  f0eafe8:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eafec:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eaff0:	00416024 */ 	and	$t4,$v0,$at
/*  f0eaff4:	322d00ff */ 	andi	$t5,$s1,0xff
/*  f0eaff8:	018d8825 */ 	or	$s1,$t4,$t5
/*  f0eaffc:	afb10078 */ 	sw	$s1,0x78($sp)
.L0f0eb000:
/*  f0eb000:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f0eb004:	3c014220 */ 	lui	$at,0x4220
/*  f0eb008:	51c00062 */ 	beqzl	$t6,.L0f0eb194
/*  f0eb00c:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0eb010:	44816000 */ 	mtc1	$at,$f12
/*  f0eb014:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb018:	00000000 */ 	nop
/*  f0eb01c:	3c01437f */ 	lui	$at,0x437f
/*  f0eb020:	44814000 */ 	mtc1	$at,$f8
/*  f0eb024:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0eb028:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes)
/*  f0eb02c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0eb030:	256b1fb0 */ 	addiu	$t3,$t3,%lo(g_MenuColourPalettes)
/*  f0eb034:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb038:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb03c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0eb040:	00000000 */ 	nop
/*  f0eb044:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0eb048:	4459f800 */ 	cfc1	$t9,$31
/*  f0eb04c:	00000000 */ 	nop
/*  f0eb050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0eb054:	53200013 */ 	beqzl	$t9,.L0f0eb0a4
/*  f0eb058:	44198000 */ 	mfc1	$t9,$f16
/*  f0eb05c:	44818000 */ 	mtc1	$at,$f16
/*  f0eb060:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0eb064:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0eb068:	44d9f800 */ 	ctc1	$t9,$31
/*  f0eb06c:	00000000 */ 	nop
/*  f0eb070:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0eb074:	4459f800 */ 	cfc1	$t9,$31
/*  f0eb078:	00000000 */ 	nop
/*  f0eb07c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0eb080:	17200005 */ 	bnez	$t9,.L0f0eb098
/*  f0eb084:	00000000 */ 	nop
/*  f0eb088:	44198000 */ 	mfc1	$t9,$f16
/*  f0eb08c:	3c018000 */ 	lui	$at,0x8000
/*  f0eb090:	10000007 */ 	b	.L0f0eb0b0
/*  f0eb094:	0321c825 */ 	or	$t9,$t9,$at
.L0f0eb098:
/*  f0eb098:	10000005 */ 	b	.L0f0eb0b0
/*  f0eb09c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0eb0a0:	44198000 */ 	mfc1	$t9,$f16
.L0f0eb0a4:
/*  f0eb0a4:	00000000 */ 	nop
/*  f0eb0a8:	0720fffb */ 	bltz	$t9,.L0f0eb098
/*  f0eb0ac:	00000000 */ 	nop
.L0f0eb0b0:
/*  f0eb0b0:	afb9005c */ 	sw	$t9,0x5c($sp)
/*  f0eb0b4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb0b8:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb0bc:	44802000 */ 	mtc1	$zero,$f4
/*  f0eb0c0:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0eb0c4:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0eb0c8:	00000000 */ 	nop
/*  f0eb0cc:	4502000a */ 	bc1fl	.L0f0eb0f8
/*  f0eb0d0:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0eb0d4:	9068003c */ 	lbu	$t0,0x3c($v1)
/*  f0eb0d8:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0eb0dc:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eb0e0:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eb0e4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eb0e8:	00e93821 */ 	addu	$a3,$a3,$t1
/*  f0eb0ec:	10000010 */ 	b	.L0f0eb130
/*  f0eb0f0:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0eb0f4:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0eb0f8:
/*  f0eb0f8:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0eb0fc:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb100:	00185100 */ 	sll	$t2,$t8,0x4
/*  f0eb104:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0eb108:	01585023 */ 	subu	$t2,$t2,$t8
/*  f0eb10c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0eb110:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0eb114:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0eb118:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0eb11c:	01cb7821 */ 	addu	$t7,$t6,$t3
/*  f0eb120:	8de50020 */ 	lw	$a1,0x20($t7)
/*  f0eb124:	0fc01a40 */ 	jal	colourBlend
/*  f0eb128:	8d840020 */ 	lw	$a0,0x20($t4)
/*  f0eb12c:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eb130:
/*  f0eb130:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eb134:	322500ff */ 	andi	$a1,$s1,0xff
/*  f0eb138:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb13c:	0fc01a40 */ 	jal	colourBlend
/*  f0eb140:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0eb144:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0eb148:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb14c:	0fc01a40 */ 	jal	colourBlend
/*  f0eb150:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f0eb154:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0eb158:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x20)
/*  f0eb15c:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x20)
/*  f0eb160:	9326003c */ 	lbu	$a2,0x3c($t9)
/*  f0eb164:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eb168:	00064100 */ 	sll	$t0,$a2,0x4
/*  f0eb16c:	01064023 */ 	subu	$t0,$t0,$a2
/*  f0eb170:	00083080 */ 	sll	$a2,$t0,0x2
/*  f0eb174:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb178:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb17c:	8ca52138 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x20)($a1)
/*  f0eb180:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb184:	8c8422a0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x20)($a0)
/*  f0eb188:	1000000e */ 	b	.L0f0eb1c4
/*  f0eb18c:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f0eb190:	8e090010 */ 	lw	$t1,0x10($s0)
.L0f0eb194:
/*  f0eb194:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0eb198:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0eb19c:	9126003c */ 	lbu	$a2,0x3c($t1)
/*  f0eb1a0:	0006c100 */ 	sll	$t8,$a2,0x4
/*  f0eb1a4:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f0eb1a8:	00183080 */ 	sll	$a2,$t8,0x2
/*  f0eb1ac:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb1b0:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb1b4:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0eb1b8:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb1bc:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0eb1c0:	8e040008 */ 	lw	$a0,0x8($s0)
.L0f0eb1c4:
/*  f0eb1c4:	0fc3c962 */ 	jal	menuIsItemDisabled
/*  f0eb1c8:	8e050010 */ 	lw	$a1,0x10($s0)
/*  f0eb1cc:	5040003b */ 	beqzl	$v0,.L0f0eb2bc
/*  f0eb1d0:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0eb1d4:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb1d8:	44804000 */ 	mtc1	$zero,$f8
/*  f0eb1dc:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0eb1e0:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0eb1e4:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0eb1e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eb1ec:	00000000 */ 	nop
/*  f0eb1f0:	4502000a */ 	bc1fl	.L0f0eb21c
/*  f0eb1f4:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0eb1f8:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb1fc:	3c117f1b */ 	lui	$s1,%hi(g_MenuColourPalettes+0x1c)
/*  f0eb200:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f0eb204:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0eb208:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eb20c:	022c8821 */ 	addu	$s1,$s1,$t4
/*  f0eb210:	10000011 */ 	b	.L0f0eb258
/*  f0eb214:	8e311fcc */ 	lw	$s1,%lo(g_MenuColourPalettes+0x1c)($s1)
/*  f0eb218:	906d003d */ 	lbu	$t5,0x3d($v1)
.L0f0eb21c:
/*  f0eb21c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0eb220:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb224:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0eb228:	000fc900 */ 	sll	$t9,$t7,0x4
/*  f0eb22c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0eb230:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0eb234:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0eb238:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0eb23c:	004e5821 */ 	addu	$t3,$v0,$t6
/*  f0eb240:	00594021 */ 	addu	$t0,$v0,$t9
/*  f0eb244:	8d05001c */ 	lw	$a1,0x1c($t0)
/*  f0eb248:	0fc01a40 */ 	jal	colourBlend
/*  f0eb24c:	8d64001c */ 	lw	$a0,0x1c($t3)
/*  f0eb250:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eb254:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0eb258:
/*  f0eb258:	8c69000c */ 	lw	$t1,0xc($v1)
/*  f0eb25c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eb260:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb264:	51200009 */ 	beqzl	$t1,.L0f0eb28c
/*  f0eb268:	afb10078 */ 	sw	$s1,0x78($sp)
/*  f0eb26c:	0fc01a40 */ 	jal	colourBlend
/*  f0eb270:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb274:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb278:	0041c024 */ 	and	$t8,$v0,$at
/*  f0eb27c:	322a00ff */ 	andi	$t2,$s1,0xff
/*  f0eb280:	030a8825 */ 	or	$s1,$t8,$t2
/*  f0eb284:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0eb288:	afb10078 */ 	sw	$s1,0x78($sp)
.L0f0eb28c:
/*  f0eb28c:	9066003c */ 	lbu	$a2,0x3c($v1)
/*  f0eb290:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x1c)
/*  f0eb294:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x1c)
/*  f0eb298:	00066100 */ 	sll	$t4,$a2,0x4
/*  f0eb29c:	01866023 */ 	subu	$t4,$t4,$a2
/*  f0eb2a0:	000c3080 */ 	sll	$a2,$t4,0x2
/*  f0eb2a4:	00862021 */ 	addu	$a0,$a0,$a2
/*  f0eb2a8:	00a62821 */ 	addu	$a1,$a1,$a2
/*  f0eb2ac:	8ca52134 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x1c)($a1)
/*  f0eb2b0:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb2b4:	8c84229c */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x1c)($a0)
/*  f0eb2b8:	8e0d0008 */ 	lw	$t5,0x8($s0)
.L0f0eb2bc:
/*  f0eb2bc:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0eb2c0:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0eb2c4:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f0eb2c8:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0eb2cc:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0eb2d0:	304e0020 */ 	andi	$t6,$v0,0x20
/*  f0eb2d4:	11c00010 */ 	beqz	$t6,.L0f0eb318
/*  f0eb2d8:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0eb2dc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eb2e0:	0fc55cbe */ 	jal	textMeasure
/*  f0eb2e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb2e8:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f0eb2ec:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0eb2f0:	86180000 */ 	lh	$t8,0x0($s0)
/*  f0eb2f4:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f0eb2f8:	05010003 */ 	bgez	$t0,.L0f0eb308
/*  f0eb2fc:	00084843 */ 	sra	$t1,$t0,0x1
/*  f0eb300:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0eb304:	00014843 */ 	sra	$t1,$at,0x1
.L0f0eb308:
/*  f0eb308:	03095021 */ 	addu	$t2,$t8,$t1
/*  f0eb30c:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0eb310:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0eb314:	8d820004 */ 	lw	$v0,0x4($t4)
.L0f0eb318:
/*  f0eb318:	00026a40 */ 	sll	$t5,$v0,0x9
/*  f0eb31c:	05a10006 */ 	bgez	$t5,.L0f0eb338
/*  f0eb320:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0eb324:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0eb328:	25cb0023 */ 	addiu	$t3,$t6,0x23
/*  f0eb32c:	afab0070 */ 	sw	$t3,0x70($sp)
/*  f0eb330:	25f90006 */ 	addiu	$t9,$t7,0x6
/*  f0eb334:	afb9006c */ 	sw	$t9,0x6c($sp)
.L0f0eb338:
/*  f0eb338:	0fc54d8a */ 	jal	func0f153628
/*  f0eb33c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb340:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0eb344:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0eb348:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0eb34c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eb350:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0eb354:	86090004 */ 	lh	$t1,0x4($s0)
/*  f0eb358:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb35c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0eb360:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0eb364:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f0eb368:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb36c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb370:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0eb374:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0eb378:	0fc5580f */ 	jal	textRenderProjected
/*  f0eb37c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0eb380:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0eb384:	8e060008 */ 	lw	$a2,0x8($s0)
/*  f0eb388:	3c010040 */ 	lui	$at,0x40
/*  f0eb38c:	34218000 */ 	ori	$at,$at,0x8000
/*  f0eb390:	8ccc0004 */ 	lw	$t4,0x4($a2)
/*  f0eb394:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0eb398:	01816824 */ 	and	$t5,$t4,$at
/*  f0eb39c:	15a0002c */ 	bnez	$t5,.L0f0eb450
/*  f0eb3a0:	00000000 */ 	nop
/*  f0eb3a4:	0fc3c539 */ 	jal	menuResolveText
/*  f0eb3a8:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0eb3ac:	10400028 */ 	beqz	$v0,.L0f0eb450
/*  f0eb3b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eb3b4:	3c0e7f1b */ 	lui	$t6,%hi(var7f1adfb8)
/*  f0eb3b8:	25cedfb8 */ 	addiu	$t6,$t6,%lo(var7f1adfb8)
/*  f0eb3bc:	104e0024 */ 	beq	$v0,$t6,.L0f0eb450
/*  f0eb3c0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0eb3c4:	860b0002 */ 	lh	$t3,0x2($s0)
/*  f0eb3c8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0eb3cc:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0eb3d0:	256f0002 */ 	addiu	$t7,$t3,0x2
/*  f0eb3d4:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f0eb3d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb3dc:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0eb3e0:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0eb3e4:	0fc55cbe */ 	jal	textMeasure
/*  f0eb3e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eb3ec:	86080000 */ 	lh	$t0,0x0($s0)
/*  f0eb3f0:	86180004 */ 	lh	$t8,0x4($s0)
/*  f0eb3f4:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0eb3f8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0eb3fc:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0eb400:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0eb404:	01184821 */ 	addu	$t1,$t0,$t8
/*  f0eb408:	012a6023 */ 	subu	$t4,$t1,$t2
/*  f0eb40c:	258dfff6 */ 	addiu	$t5,$t4,-10
/*  f0eb410:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0eb414:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eb418:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eb41c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0eb420:	86190004 */ 	lh	$t9,0x4($s0)
/*  f0eb424:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb428:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0eb42c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0eb430:	86080006 */ 	lh	$t0,0x6($s0)
/*  f0eb434:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb438:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb43c:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0eb440:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0eb444:	0fc5580f */ 	jal	textRenderProjected
/*  f0eb448:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0eb44c:	afa20080 */ 	sw	$v0,0x80($sp)
.L0f0eb450:
/*  f0eb450:	0fc54de0 */ 	jal	func0f153780
/*  f0eb454:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0eb458:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eb45c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eb460:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eb464:	03e00008 */ 	jr	$ra
/*  f0eb468:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

const char var7f1adfb8[] = "";

//Gfx *menuRenderItemSelectable(Gfx *gdl, struct menurendercontext *context)
//{
//	u32 leftcolour;
//	u32 rightcolour;
//	char *text;
//	s32 x = context->x + 10;
//	s32 y = context->y + 2;
//	struct fontchar *font1 = g_CharsHandelGothicSm;
//	struct font *font2 = g_FontHandelGothicSm;
//
//	if (context->item->param1 & 0x00000010) {
//		x -= 6;
//	}
//
//	if (context->item->param1 & 0x00400000) {
//		font1 = g_CharsHandelGothicMd;
//		font2 = g_FontHandelGothicMd;
//	}
//
//	text = menuResolveParam2Text(context->item);
//
//	if (context->frame->transitiontimer < 0) {
//		leftcolour = g_MenuColourPalettes[context->frame->type].unfocused;
//	} else {
//		leftcolour = colourBlend(
//				g_MenuColourPalettes[context->frame->type2].unfocused,
//				g_MenuColourPalettes[context->frame->type].unfocused,
//				context->frame->colourweight);
//	}
//
//	if (context->frame->dimmed) {
//		leftcolour = colourBlend(leftcolour, 0, 127) & 0xffffff00 | leftcolour & 0xff;
//	}
//
//	rightcolour = leftcolour;
//
//	if (context->focused) {
//		// Mismatch: The addiu and lui at eb030 and eb034 are swapped. The addiu
//		// is adding the lower half of the address of g_MenuColourPalettes for
//		// use in the else branch. The lui is loading a value into $at for the
//		// float to u32 conversion for weight.
//		u32 colour2;
//		u32 weight = func0f006b08(40) * 255;
//
//		if (context->frame->transitiontimer < 0) {
//			colour2 = g_MenuColourPalettes[context->frame->type].focused;
//		} else {
//			colour2 = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].focused,
//					g_MenuColourPalettes[context->frame->type].focused,
//					context->frame->colourweight);
//		}
//
//		leftcolour = colourBlend(colourBlend(leftcolour, leftcolour & 0x000000ff, 127), colour2, weight);
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].focused,
//				g_MenuColourPalettes2[context->frame->type].focused);
//	} else {
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].unfocused,
//				g_MenuColourPalettes2[context->frame->type].unfocused);
//	}
//
//	if (menuIsItemDisabled(context->item, context->frame)) {
//		if (context->frame->transitiontimer < 0) {
//			leftcolour = g_MenuColourPalettes[context->frame->type].disabled;
//		} else {
//			leftcolour = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].disabled,
//					g_MenuColourPalettes[context->frame->type].disabled,
//					context->frame->colourweight);
//		}
//
//		if (context->frame->dimmed) {
//			leftcolour = colourBlend(leftcolour, 0x00000000, 127) & 0xffffff00 | leftcolour & 0xff;
//		}
//
//		rightcolour = leftcolour;
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].disabled,
//				g_MenuColourPalettes2[context->frame->type].disabled);
//	}
//
//	if (context->item->param1 & 0x00000020) {
//		// Center text
//		s32 textheight;
//		s32 textwidth;
//		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
//		x = context->x + (context->width - textwidth) / 2;
//	}
//
//	if (context->item->param1 & 0x00400000) {
//		x += 35;
//		y += 6;
//	}
//
//	gdl = func0f153628(gdl);
//	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
//			leftcolour, context->width, context->height, 0, 0);
//
//	if ((context->item->param1 & 0x00408000) == 0) {
//		// Right side text
//		text = menuResolveText(context->item->param3, context->item);
//
//		// This is not how you check if a string is empty...
//		if (text != NULL && text != "") {
//			s32 textheight;
//			s32 textwidth;
//
//			y = context->y + 2;
//			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
//			x = context->x + context->width - textwidth - 10;
//
//			gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
//					rightcolour, context->width, context->height, 0, 0);
//		}
//	}
//
//	return func0f153780(gdl);
//}

bool menuTickItemSelectable(struct menuitem *item, struct menuinputs *inputs, u32 arg2)
{
	if ((arg2 & 2) && inputs->select) {
		menuPlaySound(MENUSOUND_SELECT);

		if (item->param1 & 0x00000008) {
			menuPopDialog();
		}

		if (item->param1 & 0x00000004) {
			menuPushDialog((struct menudialog *)item->handler);
		} else if (item->handler) {
			union handlerdata data;
			item->handler(MENUOP_SET, item, &data);
		}
	}

	return true;
}

const char var7f1adfbc[] = "";
const char var7f1adfc0[] = "%d\n";

GLOBAL_ASM(
glabel menuRenderItemSlider
/*  f0eb508:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0eb50c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0eb510:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0eb514:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0eb518:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0eb51c:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f0eb520:	afa0008c */ 	sw	$zero,0x8c($sp)
/*  f0eb524:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0eb528:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0eb52c:	8ce20010 */ 	lw	$v0,0x10($a3)
/*  f0eb530:	10400008 */ 	beqz	$v0,.L0f0eb554
/*  f0eb534:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0eb538:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0eb53c:	0040f809 */ 	jalr	$v0
/*  f0eb540:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0eb544:	87ae0076 */ 	lh	$t6,0x76($sp)
/*  f0eb548:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0eb54c:	10000002 */ 	b	.L0f0eb558
/*  f0eb550:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0eb554:
/*  f0eb554:	afa00070 */ 	sw	$zero,0x70($sp)
.L0f0eb558:
/*  f0eb558:	8e2f0010 */ 	lw	$t7,0x10($s1)
/*  f0eb55c:	91f8006e */ 	lbu	$t8,0x6e($t7)
/*  f0eb560:	13000002 */ 	beqz	$t8,.L0f0eb56c
/*  f0eb564:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0eb568:	afb9008c */ 	sw	$t9,0x8c($sp)
.L0f0eb56c:
/*  f0eb56c:	8ce80004 */ 	lw	$t0,0x4($a3)
/*  f0eb570:	00084ac0 */ 	sll	$t1,$t0,0xb
/*  f0eb574:	05210002 */ 	bgez	$t1,.L0f0eb580
/*  f0eb578:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f0eb57c:	afaa008c */ 	sw	$t2,0x8c($sp)
.L0f0eb580:
/*  f0eb580:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0eb584:	256c000a */ 	addiu	$t4,$t3,0xa
/*  f0eb588:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f0eb58c:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f0eb590:	25ae0002 */ 	addiu	$t6,$t5,0x2
/*  f0eb594:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0eb598:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0eb59c:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f0eb5a0:	31f80010 */ 	andi	$t8,$t7,0x10
/*  f0eb5a4:	13000003 */ 	beqz	$t8,.L0f0eb5b4
/*  f0eb5a8:	2588fffa */ 	addiu	$t0,$t4,-6
/*  f0eb5ac:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f0eb5b0:	8e270008 */ 	lw	$a3,0x8($s1)
.L0f0eb5b4:
/*  f0eb5b4:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0eb5b8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0eb5bc:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0eb5c0:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f0eb5c4:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0eb5c8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0eb5cc:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0eb5d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eb5d4:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f0eb5d8:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eb5dc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eb5e0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eb5e4:	01af001a */ 	div	$zero,$t5,$t7
/*  f0eb5e8:	862a0004 */ 	lh	$t2,0x4($s1)
/*  f0eb5ec:	86290000 */ 	lh	$t1,0x0($s1)
/*  f0eb5f0:	0000c012 */ 	mflo	$t8
/*  f0eb5f4:	44803000 */ 	mtc1	$zero,$f6
/*  f0eb5f8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0eb5fc:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f0eb600:	2728ffae */ 	addiu	$t0,$t9,-82
/*  f0eb604:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f0eb608:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb60c:	15e00002 */ 	bnez	$t7,.L0f0eb618
/*  f0eb610:	00000000 */ 	nop
/*  f0eb614:	0007000d */ 	break	0x7
.L0f0eb618:
/*  f0eb618:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0eb61c:	15e10004 */ 	bne	$t7,$at,.L0f0eb630
/*  f0eb620:	3c018000 */ 	lui	$at,0x8000
/*  f0eb624:	15a10002 */ 	bne	$t5,$at,.L0f0eb630
/*  f0eb628:	00000000 */ 	nop
/*  f0eb62c:	0006000d */ 	break	0x6
.L0f0eb630:
/*  f0eb630:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eb634:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eb638:	00000000 */ 	nop
/*  f0eb63c:	4502000a */ 	bc1fl	.L0f0eb668
/*  f0eb640:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0eb644:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0eb648:	2412003c */ 	addiu	$s2,$zero,0x3c
/*  f0eb64c:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x18)
/*  f0eb650:	01320019 */ 	multu	$t1,$s2
/*  f0eb654:	00005012 */ 	mflo	$t2
/*  f0eb658:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f0eb65c:	10000012 */ 	b	.L0f0eb6a8
/*  f0eb660:	8e101fc8 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x18)($s0)
/*  f0eb664:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0eb668:
/*  f0eb668:	2412003c */ 	addiu	$s2,$zero,0x3c
/*  f0eb66c:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eb670:	01920019 */ 	multu	$t4,$s2
/*  f0eb674:	3c0d7f1b */ 	lui	$t5,%hi(g_MenuColourPalettes)
/*  f0eb678:	25ad1fb0 */ 	addiu	$t5,$t5,%lo(g_MenuColourPalettes)
/*  f0eb67c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb680:	00007012 */ 	mflo	$t6
/*  f0eb684:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0eb688:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0eb68c:	01720019 */ 	multu	$t3,$s2
/*  f0eb690:	0000c012 */ 	mflo	$t8
/*  f0eb694:	030dc821 */ 	addu	$t9,$t8,$t5
/*  f0eb698:	0fc01a40 */ 	jal	colourBlend
/*  f0eb69c:	8f250018 */ 	lw	$a1,0x18($t9)
/*  f0eb6a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb6a4:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0eb6a8:
/*  f0eb6a8:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f0eb6ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb6b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb6b4:	51000008 */ 	beqzl	$t0,.L0f0eb6d8
/*  f0eb6b8:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0eb6bc:	0fc01a40 */ 	jal	colourBlend
/*  f0eb6c0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb6c4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb6c8:	00414824 */ 	and	$t1,$v0,$at
/*  f0eb6cc:	320a00ff */ 	andi	$t2,$s0,0xff
/*  f0eb6d0:	012a8025 */ 	or	$s0,$t1,$t2
/*  f0eb6d4:	8e22000c */ 	lw	$v0,0xc($s1)
.L0f0eb6d8:
/*  f0eb6d8:	1040005f */ 	beqz	$v0,.L0f0eb858
/*  f0eb6dc:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f0eb6e0:	11800050 */ 	beqz	$t4,.L0f0eb824
/*  f0eb6e4:	3c014220 */ 	lui	$at,0x4220
/*  f0eb6e8:	44816000 */ 	mtc1	$at,$f12
/*  f0eb6ec:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb6f0:	00000000 */ 	nop
/*  f0eb6f4:	3c01437f */ 	lui	$at,0x437f
/*  f0eb6f8:	44814000 */ 	mtc1	$at,$f8
/*  f0eb6fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0eb700:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb704:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0eb708:	444ef800 */ 	cfc1	$t6,$31
/*  f0eb70c:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb710:	00000000 */ 	nop
/*  f0eb714:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0eb718:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb71c:	00000000 */ 	nop
/*  f0eb720:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0eb724:	51e00013 */ 	beqzl	$t7,.L0f0eb774
/*  f0eb728:	440f8000 */ 	mfc1	$t7,$f16
/*  f0eb72c:	44818000 */ 	mtc1	$at,$f16
/*  f0eb730:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0eb734:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0eb738:	44cff800 */ 	ctc1	$t7,$31
/*  f0eb73c:	00000000 */ 	nop
/*  f0eb740:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0eb744:	444ff800 */ 	cfc1	$t7,$31
/*  f0eb748:	00000000 */ 	nop
/*  f0eb74c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0eb750:	15e00005 */ 	bnez	$t7,.L0f0eb768
/*  f0eb754:	00000000 */ 	nop
/*  f0eb758:	440f8000 */ 	mfc1	$t7,$f16
/*  f0eb75c:	3c018000 */ 	lui	$at,0x8000
/*  f0eb760:	10000007 */ 	b	.L0f0eb780
/*  f0eb764:	01e17825 */ 	or	$t7,$t7,$at
.L0f0eb768:
/*  f0eb768:	10000005 */ 	b	.L0f0eb780
/*  f0eb76c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0eb770:	440f8000 */ 	mfc1	$t7,$f16
.L0f0eb774:
/*  f0eb774:	00000000 */ 	nop
/*  f0eb778:	05e0fffb */ 	bltz	$t7,.L0f0eb768
/*  f0eb77c:	00000000 */ 	nop
.L0f0eb780:
/*  f0eb780:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f0eb784:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb788:	44cef800 */ 	ctc1	$t6,$31
/*  f0eb78c:	44802000 */ 	mtc1	$zero,$f4
/*  f0eb790:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0eb794:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0eb798:	00000000 */ 	nop
/*  f0eb79c:	45020009 */ 	bc1fl	.L0f0eb7c4
/*  f0eb7a0:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0eb7a4:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eb7a8:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0eb7ac:	01720019 */ 	multu	$t3,$s2
/*  f0eb7b0:	0000c012 */ 	mflo	$t8
/*  f0eb7b4:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f0eb7b8:	10000010 */ 	b	.L0f0eb7fc
/*  f0eb7bc:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0eb7c0:	906d003d */ 	lbu	$t5,0x3d($v1)
.L0f0eb7c4:
/*  f0eb7c4:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb7c8:	3c087f1b */ 	lui	$t0,%hi(g_MenuColourPalettes)
/*  f0eb7cc:	01b20019 */ 	multu	$t5,$s2
/*  f0eb7d0:	25081fb0 */ 	addiu	$t0,$t0,%lo(g_MenuColourPalettes)
/*  f0eb7d4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb7d8:	0000c812 */ 	mflo	$t9
/*  f0eb7dc:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0eb7e0:	8d240020 */ 	lw	$a0,0x20($t1)
/*  f0eb7e4:	01520019 */ 	multu	$t2,$s2
/*  f0eb7e8:	00006012 */ 	mflo	$t4
/*  f0eb7ec:	01887021 */ 	addu	$t6,$t4,$t0
/*  f0eb7f0:	0fc01a40 */ 	jal	colourBlend
/*  f0eb7f4:	8dc50020 */ 	lw	$a1,0x20($t6)
/*  f0eb7f8:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eb7fc:
/*  f0eb7fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb800:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0eb804:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb808:	0fc01a40 */ 	jal	colourBlend
/*  f0eb80c:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f0eb810:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0eb814:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb818:	0fc01a40 */ 	jal	colourBlend
/*  f0eb81c:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f0eb820:	345000ff */ 	ori	$s0,$v0,0xff
.L0f0eb824:
/*  f0eb824:	8e2f0010 */ 	lw	$t7,0x10($s1)
/*  f0eb828:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x20)
/*  f0eb82c:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x20)
/*  f0eb830:	91eb003c */ 	lbu	$t3,0x3c($t7)
/*  f0eb834:	01720019 */ 	multu	$t3,$s2
/*  f0eb838:	00001012 */ 	mflo	$v0
/*  f0eb83c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0eb840:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0eb844:	8ca52138 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x20)($a1)
/*  f0eb848:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb84c:	8c8422a0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x20)($a0)
/*  f0eb850:	1000000d */ 	b	.L0f0eb888
/*  f0eb854:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0eb858:
/*  f0eb858:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0eb85c:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0eb860:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0eb864:	930d003c */ 	lbu	$t5,0x3c($t8)
/*  f0eb868:	01b20019 */ 	multu	$t5,$s2
/*  f0eb86c:	00001012 */ 	mflo	$v0
/*  f0eb870:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0eb874:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0eb878:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0eb87c:	0fc54f8e */ 	jal	func0f153e38
/*  f0eb880:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0eb884:	862a0002 */ 	lh	$t2,0x2($s1)
.L0f0eb888:
/*  f0eb888:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f0eb88c:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0eb890:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0eb894:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0eb898:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f0eb89c:	2468000b */ 	addiu	$t0,$v1,0xb
/*  f0eb8a0:	03291021 */ 	addu	$v0,$t9,$t1
/*  f0eb8a4:	2445ffae */ 	addiu	$a1,$v0,-82
/*  f0eb8a8:	2447fff9 */ 	addiu	$a3,$v0,-7
/*  f0eb8ac:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eb8b0:	24660005 */ 	addiu	$a2,$v1,0x5
/*  f0eb8b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eb8b8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0eb8bc:	0fc387eb */ 	jal	func0f0e1fac
/*  f0eb8c0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0eb8c4:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0eb8c8:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eb8cc:	44804000 */ 	mtc1	$zero,$f8
/*  f0eb8d0:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0eb8d4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eb8d8:	00000000 */ 	nop
/*  f0eb8dc:	45020009 */ 	bc1fl	.L0f0eb904
/*  f0eb8e0:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0eb8e4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0eb8e8:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x18)
/*  f0eb8ec:	01f20019 */ 	multu	$t7,$s2
/*  f0eb8f0:	00005812 */ 	mflo	$t3
/*  f0eb8f4:	020b8021 */ 	addu	$s0,$s0,$t3
/*  f0eb8f8:	10000011 */ 	b	.L0f0eb940
/*  f0eb8fc:	8e101fc8 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x18)($s0)
/*  f0eb900:	9078003d */ 	lbu	$t8,0x3d($v1)
.L0f0eb904:
/*  f0eb904:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eb908:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0eb90c:	03120019 */ 	multu	$t8,$s2
/*  f0eb910:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0eb914:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eb918:	00006812 */ 	mflo	$t5
/*  f0eb91c:	01b94821 */ 	addu	$t1,$t5,$t9
/*  f0eb920:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0eb924:	01520019 */ 	multu	$t2,$s2
/*  f0eb928:	00006012 */ 	mflo	$t4
/*  f0eb92c:	01994021 */ 	addu	$t0,$t4,$t9
/*  f0eb930:	0fc01a40 */ 	jal	colourBlend
/*  f0eb934:	8d050018 */ 	lw	$a1,0x18($t0)
/*  f0eb938:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb93c:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0eb940:
/*  f0eb940:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f0eb944:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eb948:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb94c:	51c00008 */ 	beqzl	$t6,.L0f0eb970
/*  f0eb950:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f0eb954:	0fc01a40 */ 	jal	colourBlend
/*  f0eb958:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb95c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb960:	00417824 */ 	and	$t7,$v0,$at
/*  f0eb964:	320b00ff */ 	andi	$t3,$s0,0xff
/*  f0eb968:	01eb8025 */ 	or	$s0,$t7,$t3
/*  f0eb96c:	8e22000c */ 	lw	$v0,0xc($s1)
.L0f0eb970:
/*  f0eb970:	104000b0 */ 	beqz	$v0,.L0f0ebc34
/*  f0eb974:	30580002 */ 	andi	$t8,$v0,0x2
/*  f0eb978:	13000052 */ 	beqz	$t8,.L0f0ebac4
/*  f0eb97c:	3c014220 */ 	lui	$at,0x4220
/*  f0eb980:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0eb984:	44816000 */ 	mtc1	$at,$f12
/*  f0eb988:	0fc01ac2 */ 	jal	func0f006b08
/*  f0eb98c:	00000000 */ 	nop
/*  f0eb990:	3c01437f */ 	lui	$at,0x437f
/*  f0eb994:	44815000 */ 	mtc1	$at,$f10
/*  f0eb998:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0eb99c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb9a0:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0eb9a4:	444df800 */ 	cfc1	$t5,$31
/*  f0eb9a8:	44c9f800 */ 	ctc1	$t1,$31
/*  f0eb9ac:	00000000 */ 	nop
/*  f0eb9b0:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0eb9b4:	4449f800 */ 	cfc1	$t1,$31
/*  f0eb9b8:	00000000 */ 	nop
/*  f0eb9bc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0eb9c0:	51200013 */ 	beqzl	$t1,.L0f0eba10
/*  f0eb9c4:	44099000 */ 	mfc1	$t1,$f18
/*  f0eb9c8:	44819000 */ 	mtc1	$at,$f18
/*  f0eb9cc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0eb9d0:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0eb9d4:	44c9f800 */ 	ctc1	$t1,$31
/*  f0eb9d8:	00000000 */ 	nop
/*  f0eb9dc:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0eb9e0:	4449f800 */ 	cfc1	$t1,$31
/*  f0eb9e4:	00000000 */ 	nop
/*  f0eb9e8:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0eb9ec:	15200005 */ 	bnez	$t1,.L0f0eba04
/*  f0eb9f0:	00000000 */ 	nop
/*  f0eb9f4:	44099000 */ 	mfc1	$t1,$f18
/*  f0eb9f8:	3c018000 */ 	lui	$at,0x8000
/*  f0eb9fc:	10000007 */ 	b	.L0f0eba1c
/*  f0eba00:	01214825 */ 	or	$t1,$t1,$at
.L0f0eba04:
/*  f0eba04:	10000005 */ 	b	.L0f0eba1c
/*  f0eba08:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0eba0c:	44099000 */ 	mfc1	$t1,$f18
.L0f0eba10:
/*  f0eba10:	00000000 */ 	nop
/*  f0eba14:	0520fffb */ 	bltz	$t1,.L0f0eba04
/*  f0eba18:	00000000 */ 	nop
.L0f0eba1c:
/*  f0eba1c:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0eba20:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0eba24:	44cdf800 */ 	ctc1	$t5,$31
/*  f0eba28:	44803000 */ 	mtc1	$zero,$f6
/*  f0eba2c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0eba30:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eba34:	00000000 */ 	nop
/*  f0eba38:	45020009 */ 	bc1fl	.L0f0eba60
/*  f0eba3c:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0eba40:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0eba44:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0eba48:	01520019 */ 	multu	$t2,$s2
/*  f0eba4c:	00006012 */ 	mflo	$t4
/*  f0eba50:	00ec3821 */ 	addu	$a3,$a3,$t4
/*  f0eba54:	10000010 */ 	b	.L0f0eba98
/*  f0eba58:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0eba5c:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0eba60:
/*  f0eba60:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0eba64:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0eba68:	03320019 */ 	multu	$t9,$s2
/*  f0eba6c:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0eba70:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0eba74:	00004012 */ 	mflo	$t0
/*  f0eba78:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f0eba7c:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0eba80:	01720019 */ 	multu	$t3,$s2
/*  f0eba84:	0000c012 */ 	mflo	$t8
/*  f0eba88:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f0eba8c:	0fc01a40 */ 	jal	colourBlend
/*  f0eba90:	8da50020 */ 	lw	$a1,0x20($t5)
/*  f0eba94:	00403825 */ 	or	$a3,$v0,$zero
.L0f0eba98:
/*  f0eba98:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eba9c:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0ebaa0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebaa4:	0fc01a40 */ 	jal	colourBlend
/*  f0ebaa8:	afa70060 */ 	sw	$a3,0x60($sp)
/*  f0ebaac:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0ebab0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebab4:	0fc01a40 */ 	jal	colourBlend
/*  f0ebab8:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f0ebabc:	10000050 */ 	b	.L0f0ebc00
/*  f0ebac0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ebac4:
/*  f0ebac4:	44816000 */ 	mtc1	$at,$f12
/*  f0ebac8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ebacc:	00000000 */ 	nop
/*  f0ebad0:	3c01437f */ 	lui	$at,0x437f
/*  f0ebad4:	44814000 */ 	mtc1	$at,$f8
/*  f0ebad8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ebadc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ebae0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0ebae4:	4449f800 */ 	cfc1	$t1,$31
/*  f0ebae8:	44caf800 */ 	ctc1	$t2,$31
/*  f0ebaec:	00000000 */ 	nop
/*  f0ebaf0:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0ebaf4:	444af800 */ 	cfc1	$t2,$31
/*  f0ebaf8:	00000000 */ 	nop
/*  f0ebafc:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ebb00:	51400013 */ 	beqzl	$t2,.L0f0ebb50
/*  f0ebb04:	440a8000 */ 	mfc1	$t2,$f16
/*  f0ebb08:	44818000 */ 	mtc1	$at,$f16
/*  f0ebb0c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ebb10:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0ebb14:	44caf800 */ 	ctc1	$t2,$31
/*  f0ebb18:	00000000 */ 	nop
/*  f0ebb1c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0ebb20:	444af800 */ 	cfc1	$t2,$31
/*  f0ebb24:	00000000 */ 	nop
/*  f0ebb28:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ebb2c:	15400005 */ 	bnez	$t2,.L0f0ebb44
/*  f0ebb30:	00000000 */ 	nop
/*  f0ebb34:	440a8000 */ 	mfc1	$t2,$f16
/*  f0ebb38:	3c018000 */ 	lui	$at,0x8000
/*  f0ebb3c:	10000007 */ 	b	.L0f0ebb5c
/*  f0ebb40:	01415025 */ 	or	$t2,$t2,$at
.L0f0ebb44:
/*  f0ebb44:	10000005 */ 	b	.L0f0ebb5c
/*  f0ebb48:	240affff */ 	addiu	$t2,$zero,-1
/*  f0ebb4c:	440a8000 */ 	mfc1	$t2,$f16
.L0f0ebb50:
/*  f0ebb50:	00000000 */ 	nop
/*  f0ebb54:	0540fffb */ 	bltz	$t2,.L0f0ebb44
/*  f0ebb58:	00000000 */ 	nop
.L0f0ebb5c:
/*  f0ebb5c:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f0ebb60:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebb64:	44c9f800 */ 	ctc1	$t1,$31
/*  f0ebb68:	44802000 */ 	mtc1	$zero,$f4
/*  f0ebb6c:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0ebb70:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0ebb74:	00000000 */ 	nop
/*  f0ebb78:	45020009 */ 	bc1fl	.L0f0ebba0
/*  f0ebb7c:	9068003d */ 	lbu	$t0,0x3d($v1)
/*  f0ebb80:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0ebb84:	3c077f1b */ 	lui	$a3,%hi(g_MenuColourPalettes+0x20)
/*  f0ebb88:	01920019 */ 	multu	$t4,$s2
/*  f0ebb8c:	0000c812 */ 	mflo	$t9
/*  f0ebb90:	00f93821 */ 	addu	$a3,$a3,$t9
/*  f0ebb94:	10000010 */ 	b	.L0f0ebbd8
/*  f0ebb98:	8ce71fd0 */ 	lw	$a3,%lo(g_MenuColourPalettes+0x20)($a3)
/*  f0ebb9c:	9068003d */ 	lbu	$t0,0x3d($v1)
.L0f0ebba0:
/*  f0ebba0:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0ebba4:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes)
/*  f0ebba8:	01120019 */ 	multu	$t0,$s2
/*  f0ebbac:	256b1fb0 */ 	addiu	$t3,$t3,%lo(g_MenuColourPalettes)
/*  f0ebbb0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ebbb4:	00007812 */ 	mflo	$t7
/*  f0ebbb8:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0ebbbc:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0ebbc0:	01d20019 */ 	multu	$t6,$s2
/*  f0ebbc4:	00006812 */ 	mflo	$t5
/*  f0ebbc8:	01ab4821 */ 	addu	$t1,$t5,$t3
/*  f0ebbcc:	0fc01a40 */ 	jal	colourBlend
/*  f0ebbd0:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0ebbd4:	00403825 */ 	or	$a3,$v0,$zero
.L0f0ebbd8:
/*  f0ebbd8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ebbdc:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0ebbe0:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebbe4:	0fc01a40 */ 	jal	colourBlend
/*  f0ebbe8:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0ebbec:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ebbf0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebbf4:	0fc01a40 */ 	jal	colourBlend
/*  f0ebbf8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0ebbfc:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ebc00:
/*  f0ebc00:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0ebc04:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x20)
/*  f0ebc08:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x20)
/*  f0ebc0c:	914c003c */ 	lbu	$t4,0x3c($t2)
/*  f0ebc10:	01920019 */ 	multu	$t4,$s2
/*  f0ebc14:	00001012 */ 	mflo	$v0
/*  f0ebc18:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebc1c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebc20:	8ca52138 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x20)($a1)
/*  f0ebc24:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebc28:	8c8422a0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x20)($a0)
/*  f0ebc2c:	1000000c */ 	b	.L0f0ebc60
/*  f0ebc30:	00000000 */ 	nop
.L0f0ebc34:
/*  f0ebc34:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0ebc38:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0ebc3c:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0ebc40:	9328003c */ 	lbu	$t0,0x3c($t9)
/*  f0ebc44:	01120019 */ 	multu	$t0,$s2
/*  f0ebc48:	00001012 */ 	mflo	$v0
/*  f0ebc4c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebc50:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebc54:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0ebc58:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebc5c:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
.L0f0ebc60:
/*  f0ebc60:	0fc54d8a */ 	jal	func0f153628
/*  f0ebc64:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebc68:	3c0f8008 */ 	lui	$t7,%hi(g_CharsHandelGothicSm)
/*  f0ebc6c:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm)
/*  f0ebc70:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm)($t8)
/*  f0ebc74:	8deffb10 */ 	lw	$t7,%lo(g_CharsHandelGothicSm)($t7)
/*  f0ebc78:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ebc7c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ebc80:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ebc84:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ebc88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ebc8c:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ebc90:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ebc94:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0ebc98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebc9c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebca0:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ebca4:	8fa700a8 */ 	lw	$a3,0xa8($sp)
/*  f0ebca8:	0fc5580f */ 	jal	textRenderProjected
/*  f0ebcac:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0ebcb0:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0ebcb4:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0ebcb8:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0ebcbc:	3c057f1b */ 	lui	$a1,%hi(var7f1adfbc)
/*  f0ebcc0:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f0ebcc4:	312a2000 */ 	andi	$t2,$t1,0x2000
/*  f0ebcc8:	15400077 */ 	bnez	$t2,.L0f0ebea8
/*  f0ebccc:	00000000 */ 	nop
/*  f0ebcd0:	0c004c4c */ 	jal	strcpy
/*  f0ebcd4:	24a5dfbc */ 	addiu	$a1,$a1,%lo(var7f1adfbc)
/*  f0ebcd8:	3c057f1b */ 	lui	$a1,%hi(var7f1adfc0)
/*  f0ebcdc:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var7f1adfc0)
/*  f0ebce0:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0ebce4:	0c004dad */ 	jal	sprintf
/*  f0ebce8:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0ebcec:	8e2c0008 */ 	lw	$t4,0x8($s1)
/*  f0ebcf0:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0ebcf4:	27af0098 */ 	addiu	$t7,$sp,0x98
/*  f0ebcf8:	8d990010 */ 	lw	$t9,0x10($t4)
/*  f0ebcfc:	1320000a */ 	beqz	$t9,.L0f0ebd28
/*  f0ebd00:	00000000 */ 	nop
/*  f0ebd04:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0ebd08:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0ebd0c:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0ebd10:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0ebd14:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0ebd18:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0ebd1c:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0ebd20:	0320f809 */ 	jalr	$t9
/*  f0ebd24:	00000000 */ 	nop
.L0f0ebd28:
/*  f0ebd28:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm)
/*  f0ebd2c:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm)($t8)
/*  f0ebd30:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicSm)
/*  f0ebd34:	8ce7fb10 */ 	lw	$a3,%lo(g_CharsHandelGothicSm)($a3)
/*  f0ebd38:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0ebd3c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0ebd40:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0ebd44:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ebd48:	0fc55cbe */ 	jal	textMeasure
/*  f0ebd4c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ebd50:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0ebd54:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ebd58:	8fa90088 */ 	lw	$t1,0x88($sp)
/*  f0ebd5c:	44804000 */ 	mtc1	$zero,$f8
/*  f0ebd60:	01cd5821 */ 	addu	$t3,$t6,$t5
/*  f0ebd64:	01695023 */ 	subu	$t2,$t3,$t1
/*  f0ebd68:	254cfff9 */ 	addiu	$t4,$t2,-7
/*  f0ebd6c:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f0ebd70:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0ebd74:	250f0002 */ 	addiu	$t7,$t0,0x2
/*  f0ebd78:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0ebd7c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebd80:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f0ebd84:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0ebd88:	00000000 */ 	nop
/*  f0ebd8c:	45020009 */ 	bc1fl	.L0f0ebdb4
/*  f0ebd90:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0ebd94:	9079003c */ 	lbu	$t9,0x3c($v1)
/*  f0ebd98:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x18)
/*  f0ebd9c:	03320019 */ 	multu	$t9,$s2
/*  f0ebda0:	0000c012 */ 	mflo	$t8
/*  f0ebda4:	02188021 */ 	addu	$s0,$s0,$t8
/*  f0ebda8:	10000011 */ 	b	.L0f0ebdf0
/*  f0ebdac:	8e101fc8 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x18)($s0)
/*  f0ebdb0:	906e003d */ 	lbu	$t6,0x3d($v1)
.L0f0ebdb4:
/*  f0ebdb4:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0ebdb8:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ebdbc:	01d20019 */ 	multu	$t6,$s2
/*  f0ebdc0:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ebdc4:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ebdc8:	00006812 */ 	mflo	$t5
/*  f0ebdcc:	004d5821 */ 	addu	$t3,$v0,$t5
/*  f0ebdd0:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0ebdd4:	01320019 */ 	multu	$t1,$s2
/*  f0ebdd8:	00005012 */ 	mflo	$t2
/*  f0ebddc:	004a6021 */ 	addu	$t4,$v0,$t2
/*  f0ebde0:	0fc01a40 */ 	jal	colourBlend
/*  f0ebde4:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ebde8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ebdec:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ebdf0:
/*  f0ebdf0:	8c68000c */ 	lw	$t0,0xc($v1)
/*  f0ebdf4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ebdf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ebdfc:	51000009 */ 	beqzl	$t0,.L0f0ebe24
/*  f0ebe00:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ebe04:	0fc01a40 */ 	jal	colourBlend
/*  f0ebe08:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ebe0c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ebe10:	00417824 */ 	and	$t7,$v0,$at
/*  f0ebe14:	321900ff */ 	andi	$t9,$s0,0xff
/*  f0ebe18:	01f98025 */ 	or	$s0,$t7,$t9
/*  f0ebe1c:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ebe20:	9078003c */ 	lbu	$t8,0x3c($v1)
.L0f0ebe24:
/*  f0ebe24:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0ebe28:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0ebe2c:	03120019 */ 	multu	$t8,$s2
/*  f0ebe30:	00001012 */ 	mflo	$v0
/*  f0ebe34:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ebe38:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ebe3c:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0ebe40:	0fc54f8e */ 	jal	func0f153e38
/*  f0ebe44:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
/*  f0ebe48:	3c098008 */ 	lui	$t1,%hi(g_CharsHandelGothicSm)
/*  f0ebe4c:	3c0a8008 */ 	lui	$t2,%hi(g_FontHandelGothicSm)
/*  f0ebe50:	8d4afb0c */ 	lw	$t2,%lo(g_FontHandelGothicSm)($t2)
/*  f0ebe54:	8d29fb10 */ 	lw	$t1,%lo(g_CharsHandelGothicSm)($t1)
/*  f0ebe58:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ebe5c:	320d00ff */ 	andi	$t5,$s0,0xff
/*  f0ebe60:	000d5842 */ 	srl	$t3,$t5,0x1
/*  f0ebe64:	02017024 */ 	and	$t6,$s0,$at
/*  f0ebe68:	01cb8025 */ 	or	$s0,$t6,$t3
/*  f0ebe6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ebe70:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0ebe74:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ebe78:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ebe7c:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebe80:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ebe84:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ebe88:	86280006 */ 	lh	$t0,0x6($s1)
/*  f0ebe8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebe90:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebe94:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ebe98:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f0ebe9c:	0fc5580f */ 	jal	textRenderProjected
/*  f0ebea0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ebea4:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f0ebea8:
/*  f0ebea8:	0fc54de0 */ 	jal	func0f153780
/*  f0ebeac:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f0ebeb0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0ebeb4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ebeb8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ebebc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ebec0:	03e00008 */ 	jr	$ra
/*  f0ebec4:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

bool menuTickItemSlider(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data)
{
	s32 index;
	union handlerdata handlerdata;
	s32 tmp;
	f32 f0;
	f32 f2;
	f32 f14;

	if ((arg3 & 2)) {
		if (arg3 & 4) {
			if (item->handler) {
				item->handler(MENUOP_GETSLIDER, item, &handlerdata);
				index = (s16)handlerdata.slider.value;
			} else {
				index = 0;
			}

			if ((item->param1 & 0x00000800) == 0 && !g_Menus[g_MpPlayerNum].unk82c) {
				index = index + inputs->leftright;
			} else {
				f0 = data->slider.unk00 / 1000.0f;
				f0 = (f0 * 100.0f) / item->param3;
#if VERSION >= VERSION_PAL_FINAL
				f0 = f0 + inputs->unk08 * g_Vars.diffframe60freal;
#else
				f0 = f0 + inputs->unk08 * g_Vars.diffframe60;
#endif
				f0 = (item->param3 * f0) / 100.0f;

				tmp = f0;
				f0 -= tmp;
				index += tmp;

				data->slider.unk00 = f0 * 1000.0f;
			}

			if (inputs->xaxis < 0) {
				f14 = inputs->xaxis;
				f2 = -f14;
			} else {
				f14 = inputs->xaxis;
				f2 = f14;
			}

			if ((item->param1 & 0x00000800) == 0 && f2 < 40) {
				if (g_Menus[g_MpPlayerNum].unk82c) {
					index = index + inputs->leftright;
				}
			} else {
				f0 = data->slider.unk00 / 1000.0f;
				f0 = (f0 * 100.0f) / item->param3;

				if (inputs->xaxis < 0) {
					f2 = -f14;
				} else {
					f2 = f14;
				}

				if (f2 > 20) {
					f2 = (f2 - 20) * 0.0625f;
#if VERSION >= VERSION_PAL_FINAL
					f2 *= g_Vars.diffframe60freal;
#else
					f2 *= g_Vars.diffframe60f;
#endif

					if (inputs->xaxis < 0) {
						f0 -= f2;
					} else {
						f0 += f2;
					}
				}

				f0 = (item->param3 * f0) / 100.0f;
				tmp = f0;
				f0 -= tmp;
				index += tmp;
				data->slider.unk00 = f0 * 1000.0f;
			}

			if (index < 0) {
				index = 0;
			}

			if (index > item->param3) {
				index = item->param3;
			}

			inputs->leftright = 0;
			handlerdata.slider.value = index;

			if (item->handler) {
				item->handler(MENUOP_SET, item, &handlerdata);
			}

			if (inputs->select) {
				frame->dimmed = false;
			}
		} else {
			if (inputs->select) {
				frame->dimmed = true;
			}
		}
	}

	return true;
}

void menuInitItemSlider(union menuitemdata *data)
{
	data->slider.unk00 = 0;
}

Gfx *menuRenderItemCarousel(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour = 0xff0000ff;

	if (context->focused) {
		u32 colour1;
		u32 weight = func0f006b08(40) * 255;

		if (context->frame->transitiontimer < 0) {
			colour1 = g_MenuColourPalettes[context->frame->type].focused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->frame->type2].focused,
					g_MenuColourPalettes[context->frame->type].focused,
					context->frame->colourweight);
		}

		colour = colourBlend(colourBlend(colour, 0x000000ff, 127), colour1, weight);
	}

	// Left arrow
	gdl = menuRenderCarouselArrow(gdl, context->x, context->y + context->height / 2, 8, 1, -1, colour);

	// Right arrow
	gdl = menuRenderCarouselArrow(gdl, context->x + context->width, context->y + context->height / 2, 8, 3, -1, colour);

	// This part of the function is unused because param2 is always zero.
	// Setting it to 0x7b causes a crash.
	// 0x7c and 0x7d don't do anycontext with the option value, so it's probable
	// that the original source has a commented function call in that block.
	if (context->item->param2 == 0x7b && context->item->handler) {
		union handlerdata data;
		s32 headorbodynum = 0;

		context->item->handler(MENUOP_GETOPTIONVALUE, context->item, &data);
		headorbodynum += data.carousel.value;

		gdl = func0f14f07c(gdl, headorbodynum,
				context->x + context->width / 2 - 32, context->y,
				context->x + context->width / 2 + 32, context->y + 64);
	} else if ((context->item->param2 == 0x7c || context->item->param2 == 0x7d) && context->item->handler) {
		union handlerdata data;
		context->item->handler(MENUOP_GETOPTIONVALUE, context->item, &data);
	}

	return gdl;
}

bool menuTickItemCarousel(struct menuitem *item, struct menuinputs *inputs, u32 arg2)
{
	union handlerdata data;
	s32 index;
	s32 numoptions;
	bool done;
	u32 stack;

	if (((arg2 & 2) || (item->param1 & 0x04000000)) && item->handler) {
		if (inputs->leftright != 0) {
			if (mpIsPlayerLockedOut(g_MpPlayerNum) == 0 || (item->param1 & 0x00020000) == 0) {
				done = false;

				item->handler(MENUOP_GETOPTIONCOUNT, item, &data);

				numoptions = data.carousel.value;
				item->handler(MENUOP_GETOPTIONVALUE, item, &data);

				index = data.carousel.value;

				while (!done) {
					index = index + inputs->leftright;

					if (index >= numoptions) {
						index = 0;
					}

					if (index < 0) {
						index = numoptions - 1;
					}

					// Some kind of option-is-locked check?
					data.carousel.value = index;

					if (!item->handler(MENUOP_21, item, &data)) {
						done = true;
					}
				}

				data.carousel.value = index;
#if VERSION >= VERSION_NTSC_1_0
				data.carousel.unk04 = inputs->shoulder;
#endif

				item->handler(MENUOP_SET, item, &data);
			}
		}

		if (item->handler) {
			item->handler(MENUOP_11, item, &data);
		}
	}

	return true;
}

GLOBAL_ASM(
glabel menuRenderItemCheckbox
/*  f0ec64c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0ec650:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0ec654:	35ce2faf */ 	ori	$t6,$t6,0x2faf
/*  f0ec658:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ec65c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ec660:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ec664:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0ec668:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0ec66c:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f0ec670:	8caf0008 */ 	lw	$t7,0x8($a1)
/*  f0ec674:	3c028008 */ 	lui	$v0,%hi(g_FontHandelGothicSm)
/*  f0ec678:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicSm)
/*  f0ec67c:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0ec680:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ec684:	8c42fb0c */ 	lw	$v0,%lo(g_FontHandelGothicSm)($v0)
/*  f0ec688:	33190200 */ 	andi	$t9,$t8,0x200
/*  f0ec68c:	13200005 */ 	beqz	$t9,.L0f0ec6a4
/*  f0ec690:	8c63fb10 */ 	lw	$v1,%lo(g_CharsHandelGothicSm)($v1)
/*  f0ec694:	3c028008 */ 	lui	$v0,%hi(g_FontHandelGothicXs)
/*  f0ec698:	3c038008 */ 	lui	$v1,%hi(g_CharsHandelGothicXs)
/*  f0ec69c:	8c42fb04 */ 	lw	$v0,%lo(g_FontHandelGothicXs)($v0)
/*  f0ec6a0:	8c63fb08 */ 	lw	$v1,%lo(g_CharsHandelGothicXs)($v1)
.L0f0ec6a4:
/*  f0ec6a4:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ec6a8:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f0ec6ac:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ec6b0:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0ec6b4:	8e240008 */ 	lw	$a0,0x8($s1)
/*  f0ec6b8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0ec6bc:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ec6c0:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0ec6c4:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0ec6c8:	a3a00064 */ 	sb	$zero,0x64($sp)
/*  f0ec6cc:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0ec6d0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0ec6d4:	8ca30010 */ 	lw	$v1,0x10($a1)
/*  f0ec6d8:	50600042 */ 	beqzl	$v1,.L0f0ec7e4
/*  f0ec6dc:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec6e0:	0060f809 */ 	jalr	$v1
/*  f0ec6e4:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ec6e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ec6ec:	1441003c */ 	bne	$v0,$at,.L0f0ec7e0
/*  f0ec6f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec6f4:	afaa0060 */ 	sw	$t2,0x60($sp)
/*  f0ec6f8:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec6fc:	44803000 */ 	mtc1	$zero,$f6
/*  f0ec700:	3c0f7f1b */ 	lui	$t7,%hi(g_MenuColourPalettes)
/*  f0ec704:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0ec708:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(g_MenuColourPalettes)
/*  f0ec70c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ec710:	00000000 */ 	nop
/*  f0ec714:	4502000a */ 	bc1fl	.L0f0ec740
/*  f0ec718:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0ec71c:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0ec720:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x24)
/*  f0ec724:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0ec728:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0ec72c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0ec730:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f0ec734:	10000011 */ 	b	.L0f0ec77c
/*  f0ec738:	8e101fd4 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x24)($s0)
/*  f0ec73c:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ec740:
/*  f0ec740:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ec744:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec748:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0ec74c:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec750:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0ec754:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec758:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec75c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ec760:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0ec764:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0ec768:	8d250024 */ 	lw	$a1,0x24($t1)
/*  f0ec76c:	0fc01a40 */ 	jal	colourBlend
/*  f0ec770:	8f040024 */ 	lw	$a0,0x24($t8)
/*  f0ec774:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ec778:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec77c:
/*  f0ec77c:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f0ec780:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ec784:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ec788:	51400009 */ 	beqzl	$t2,.L0f0ec7b0
/*  f0ec78c:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ec790:	0fc01a40 */ 	jal	colourBlend
/*  f0ec794:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ec798:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ec79c:	00415824 */ 	and	$t3,$v0,$at
/*  f0ec7a0:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f0ec7a4:	016c8025 */ 	or	$s0,$t3,$t4
/*  f0ec7a8:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec7ac:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ec7b0:
/*  f0ec7b0:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x24)
/*  f0ec7b4:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x24)
/*  f0ec7b8:	00036900 */ 	sll	$t5,$v1,0x4
/*  f0ec7bc:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0ec7c0:	000d1880 */ 	sll	$v1,$t5,0x2
/*  f0ec7c4:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ec7c8:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ec7cc:	8ca5213c */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x24)($a1)
/*  f0ec7d0:	0fc54f8e */ 	jal	func0f153e38
/*  f0ec7d4:	8c8422a4 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x24)($a0)
/*  f0ec7d8:	10000039 */ 	b	.L0f0ec8c0
/*  f0ec7dc:	00000000 */ 	nop
.L0f0ec7e0:
/*  f0ec7e0:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec7e4:
/*  f0ec7e4:	44805000 */ 	mtc1	$zero,$f10
/*  f0ec7e8:	3c0f7f1b */ 	lui	$t7,%hi(g_MenuColourPalettes)
/*  f0ec7ec:	c4e80040 */ 	lwc1	$f8,0x40($a3)
/*  f0ec7f0:	25ef1fb0 */ 	addiu	$t7,$t7,%lo(g_MenuColourPalettes)
/*  f0ec7f4:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ec7f8:	00000000 */ 	nop
/*  f0ec7fc:	4502000a */ 	bc1fl	.L0f0ec828
/*  f0ec800:	90f9003d */ 	lbu	$t9,0x3d($a3)
/*  f0ec804:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0ec808:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x18)
/*  f0ec80c:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0ec810:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0ec814:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0ec818:	02188021 */ 	addu	$s0,$s0,$t8
/*  f0ec81c:	10000011 */ 	b	.L0f0ec864
/*  f0ec820:	8e101fc8 */ 	lw	$s0,%lo(g_MenuColourPalettes+0x18)($s0)
/*  f0ec824:	90f9003d */ 	lbu	$t9,0x3d($a3)
.L0f0ec828:
/*  f0ec828:	90ea003c */ 	lbu	$t2,0x3c($a3)
/*  f0ec82c:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec830:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec834:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0ec838:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec83c:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f0ec840:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0ec844:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec848:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0ec84c:	016f6021 */ 	addu	$t4,$t3,$t7
/*  f0ec850:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ec854:	0fc01a40 */ 	jal	colourBlend
/*  f0ec858:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0ec85c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ec860:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ec864:
/*  f0ec864:	8ced000c */ 	lw	$t5,0xc($a3)
/*  f0ec868:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ec86c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ec870:	51a00009 */ 	beqzl	$t5,.L0f0ec898
/*  f0ec874:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ec878:	0fc01a40 */ 	jal	colourBlend
/*  f0ec87c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ec880:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ec884:	00417024 */ 	and	$t6,$v0,$at
/*  f0ec888:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0ec88c:	01d88025 */ 	or	$s0,$t6,$t8
/*  f0ec890:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec894:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ec898:
/*  f0ec898:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x18)
/*  f0ec89c:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x18)
/*  f0ec8a0:	0003c900 */ 	sll	$t9,$v1,0x4
/*  f0ec8a4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0ec8a8:	00191880 */ 	sll	$v1,$t9,0x2
/*  f0ec8ac:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ec8b0:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ec8b4:	8ca52130 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x18)($a1)
/*  f0ec8b8:	0fc54f8e */ 	jal	func0f153e38
/*  f0ec8bc:	8c842298 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x18)($a0)
.L0f0ec8c0:
/*  f0ec8c0:	0fc54d8a */ 	jal	func0f153628
/*  f0ec8c4:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0ec8c8:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0ec8cc:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f0ec8d0:	3c014220 */ 	lui	$at,0x4220
/*  f0ec8d4:	51000060 */ 	beqzl	$t0,.L0f0eca58
/*  f0ec8d8:	8e240008 */ 	lw	$a0,0x8($s1)
/*  f0ec8dc:	44816000 */ 	mtc1	$at,$f12
/*  f0ec8e0:	0fc01ac2 */ 	jal	func0f006b08
/*  f0ec8e4:	00000000 */ 	nop
/*  f0ec8e8:	3c01437f */ 	lui	$at,0x437f
/*  f0ec8ec:	44818000 */ 	mtc1	$at,$f16
/*  f0ec8f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec8f4:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ec8f8:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0ec8fc:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ec900:	3c014f00 */ 	lui	$at,0x4f00
/*  f0ec904:	4449f800 */ 	cfc1	$t1,$31
/*  f0ec908:	44caf800 */ 	ctc1	$t2,$31
/*  f0ec90c:	00000000 */ 	nop
/*  f0ec910:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f0ec914:	444af800 */ 	cfc1	$t2,$31
/*  f0ec918:	00000000 */ 	nop
/*  f0ec91c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ec920:	51400013 */ 	beqzl	$t2,.L0f0ec970
/*  f0ec924:	440a2000 */ 	mfc1	$t2,$f4
/*  f0ec928:	44812000 */ 	mtc1	$at,$f4
/*  f0ec92c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ec930:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f0ec934:	44caf800 */ 	ctc1	$t2,$31
/*  f0ec938:	00000000 */ 	nop
/*  f0ec93c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0ec940:	444af800 */ 	cfc1	$t2,$31
/*  f0ec944:	00000000 */ 	nop
/*  f0ec948:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0ec94c:	15400005 */ 	bnez	$t2,.L0f0ec964
/*  f0ec950:	00000000 */ 	nop
/*  f0ec954:	440a2000 */ 	mfc1	$t2,$f4
/*  f0ec958:	3c018000 */ 	lui	$at,0x8000
/*  f0ec95c:	10000007 */ 	b	.L0f0ec97c
/*  f0ec960:	01415025 */ 	or	$t2,$t2,$at
.L0f0ec964:
/*  f0ec964:	10000005 */ 	b	.L0f0ec97c
/*  f0ec968:	240affff */ 	addiu	$t2,$zero,-1
/*  f0ec96c:	440a2000 */ 	mfc1	$t2,$f4
.L0f0ec970:
/*  f0ec970:	00000000 */ 	nop
/*  f0ec974:	0540fffb */ 	bltz	$t2,.L0f0ec964
/*  f0ec978:	00000000 */ 	nop
.L0f0ec97c:
/*  f0ec97c:	afaa004c */ 	sw	$t2,0x4c($sp)
/*  f0ec980:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ec984:	44c9f800 */ 	ctc1	$t1,$31
/*  f0ec988:	44804000 */ 	mtc1	$zero,$f8
/*  f0ec98c:	c4e60040 */ 	lwc1	$f6,0x40($a3)
/*  f0ec990:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0ec994:	00000000 */ 	nop
/*  f0ec998:	4502000b */ 	bc1fl	.L0f0ec9c8
/*  f0ec99c:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0ec9a0:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0ec9a4:	3c0c7f1b */ 	lui	$t4,%hi(g_MenuColourPalettes+0x20)
/*  f0ec9a8:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0ec9ac:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0ec9b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0ec9b4:	018f6021 */ 	addu	$t4,$t4,$t7
/*  f0ec9b8:	8d8c1fd0 */ 	lw	$t4,%lo(g_MenuColourPalettes+0x20)($t4)
/*  f0ec9bc:	10000010 */ 	b	.L0f0eca00
/*  f0ec9c0:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0ec9c4:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ec9c8:
/*  f0ec9c8:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ec9cc:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ec9d0:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0ec9d4:	00194100 */ 	sll	$t0,$t9,0x4
/*  f0ec9d8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0ec9dc:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0ec9e0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ec9e4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0ec9e8:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f0ec9ec:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ec9f0:	8d250020 */ 	lw	$a1,0x20($t1)
/*  f0ec9f4:	0fc01a40 */ 	jal	colourBlend
/*  f0ec9f8:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0ec9fc:	afa20050 */ 	sw	$v0,0x50($sp)
.L0f0eca00:
/*  f0eca00:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eca04:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0eca08:	0fc01a40 */ 	jal	colourBlend
/*  f0eca0c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eca10:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eca14:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0eca18:	0fc01a40 */ 	jal	colourBlend
/*  f0eca1c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0eca20:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0eca24:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x20)
/*  f0eca28:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x20)
/*  f0eca2c:	9143003c */ 	lbu	$v1,0x3c($t2)
/*  f0eca30:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eca34:	00035900 */ 	sll	$t3,$v1,0x4
/*  f0eca38:	01635823 */ 	subu	$t3,$t3,$v1
/*  f0eca3c:	000b1880 */ 	sll	$v1,$t3,0x2
/*  f0eca40:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0eca44:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0eca48:	8ca52138 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x20)($a1)
/*  f0eca4c:	0fc54f8e */ 	jal	func0f153e38
/*  f0eca50:	8c8422a0 */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x20)($a0)
/*  f0eca54:	8e240008 */ 	lw	$a0,0x8($s1)
.L0f0eca58:
/*  f0eca58:	0fc3c962 */ 	jal	menuIsItemDisabled
/*  f0eca5c:	8e250010 */ 	lw	$a1,0x10($s1)
/*  f0eca60:	5040003c */ 	beqzl	$v0,.L0f0ecb54
/*  f0eca64:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0eca68:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0eca6c:	44808000 */ 	mtc1	$zero,$f16
/*  f0eca70:	c4ea0040 */ 	lwc1	$f10,0x40($a3)
/*  f0eca74:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0eca78:	00000000 */ 	nop
/*  f0eca7c:	4502000a */ 	bc1fl	.L0f0ecaa8
/*  f0eca80:	90ed003d */ 	lbu	$t5,0x3d($a3)
/*  f0eca84:	90ef003c */ 	lbu	$t7,0x3c($a3)
/*  f0eca88:	3c107f1b */ 	lui	$s0,%hi(g_MenuColourPalettes+0x1c)
/*  f0eca8c:	000f6100 */ 	sll	$t4,$t7,0x4
/*  f0eca90:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f0eca94:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eca98:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f0eca9c:	10000012 */ 	b	.L0f0ecae8
/*  f0ecaa0:	8e101fcc */ 	lw	$s0,%lo(g_MenuColourPalettes+0x1c)($s0)
/*  f0ecaa4:	90ed003d */ 	lbu	$t5,0x3d($a3)
.L0f0ecaa8:
/*  f0ecaa8:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ecaac:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0ecab0:	01a30019 */ 	multu	$t5,$v1
/*  f0ecab4:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ecab8:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ecabc:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0ecac0:	00007012 */ 	mflo	$t6
/*  f0ecac4:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f0ecac8:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0ecacc:	03230019 */ 	multu	$t9,$v1
/*  f0ecad0:	00004012 */ 	mflo	$t0
/*  f0ecad4:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ecad8:	0fc01a40 */ 	jal	colourBlend
/*  f0ecadc:	8d25001c */ 	lw	$a1,0x1c($t1)
/*  f0ecae0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ecae4:	8e270010 */ 	lw	$a3,0x10($s1)
.L0f0ecae8:
/*  f0ecae8:	8cea000c */ 	lw	$t2,0xc($a3)
/*  f0ecaec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ecaf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ecaf4:	51400009 */ 	beqzl	$t2,.L0f0ecb1c
/*  f0ecaf8:	90e3003c */ 	lbu	$v1,0x3c($a3)
/*  f0ecafc:	0fc01a40 */ 	jal	colourBlend
/*  f0ecb00:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ecb04:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ecb08:	00415824 */ 	and	$t3,$v0,$at
/*  f0ecb0c:	320f00ff */ 	andi	$t7,$s0,0xff
/*  f0ecb10:	016f8025 */ 	or	$s0,$t3,$t7
/*  f0ecb14:	8e270010 */ 	lw	$a3,0x10($s1)
/*  f0ecb18:	90e3003c */ 	lbu	$v1,0x3c($a3)
.L0f0ecb1c:
/*  f0ecb1c:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0x1c)
/*  f0ecb20:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0x1c)
/*  f0ecb24:	00036100 */ 	sll	$t4,$v1,0x4
/*  f0ecb28:	01836023 */ 	subu	$t4,$t4,$v1
/*  f0ecb2c:	000c1880 */ 	sll	$v1,$t4,0x2
/*  f0ecb30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f0ecb34:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f0ecb38:	8ca52134 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0x1c)($a1)
/*  f0ecb3c:	0fc54f8e */ 	jal	func0f153e38
/*  f0ecb40:	8c84229c */ 	lw	$a0,%lo(g_MenuColourPalettes3+0x1c)($a0)
/*  f0ecb44:	3c0d7f00 */ 	lui	$t5,0x7f00
/*  f0ecb48:	35ad2faf */ 	ori	$t5,$t5,0x2faf
/*  f0ecb4c:	afad005c */ 	sw	$t5,0x5c($sp)
/*  f0ecb50:	862e0000 */ 	lh	$t6,0x0($s1)
.L0f0ecb54:
/*  f0ecb54:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ecb58:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0ecb5c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0ecb60:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0ecb64:	01d82821 */ 	addu	$a1,$t6,$t8
/*  f0ecb68:	24a5fff0 */ 	addiu	$a1,$a1,-16
/*  f0ecb6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ecb70:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0ecb74:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f0ecb78:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0ecb7c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ecb80:	0fc38dec */ 	jal	renderCheckbox
/*  f0ecb84:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0ecb88:	86290000 */ 	lh	$t1,0x0($s1)
/*  f0ecb8c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f0ecb90:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0ecb94:	252a000a */ 	addiu	$t2,$t1,0xa
/*  f0ecb98:	afaa006c */ 	sw	$t2,0x6c($sp)
/*  f0ecb9c:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0ecba0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ecba4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ecba8:	256f0002 */ 	addiu	$t7,$t3,0x2
/*  f0ecbac:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0ecbb0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ecbb4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ecbb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ecbbc:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ecbc0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ecbc4:	86380006 */ 	lh	$t8,0x6($s1)
/*  f0ecbc8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ecbcc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ecbd0:	27a60068 */ 	addiu	$a2,$sp,0x68
/*  f0ecbd4:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f0ecbd8:	0fc5580f */ 	jal	textRenderProjected
/*  f0ecbdc:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ecbe0:	0fc54de0 */ 	jal	func0f153780
/*  f0ecbe4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ecbe8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ecbec:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0ecbf0:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0ecbf4:	03e00008 */ 	jr	$ra
/*  f0ecbf8:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

//Gfx *menuRenderItemCheckbox(Gfx *gdl, struct menurendercontext *context)
//{
//	u32 maincolour = 0x00000000;
//	char *text;
//	s32 x;
//	s32 y;
//	u8 data[3];
//	bool checked = false;
//	u32 fillcolour = 0xff002faf;
//	struct font *font2 = g_FontHandelGothicSm;
//	struct fontchar *font1 = g_CharsHandelGothicSm;
//
//	if (context->item->param1 & 0x00000200) {
//		font2 = g_FontHandelGothicXs;
//		font1 = g_CharsHandelGothicXs;
//	}
//
//	x = context->x;
//	y = context->y;
//	text = menuResolveParam2Text(context->item);
//	data[0] = 0;
//
//	if (context->item->handler
//			&& context->item->handler(MENUOP_GET, context->item, (union handlerdata *)data) == true) {
//		checked = true;
//
//		if (context->frame->transitiontimer < 0) {
//			maincolour = g_MenuColourPalettes[context->frame->type].checkedunfocused;
//		} else {
//			maincolour = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].checkedunfocused,
//					g_MenuColourPalettes[context->frame->type].checkedunfocused,
//					context->frame->colourweight);
//		}
//
//		if (context->frame->dimmed) {
//			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
//		}
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].checkedunfocused,
//				g_MenuColourPalettes2[context->frame->type].checkedunfocused);
//	} else {
//		if (context->frame->transitiontimer < 0) {
//			maincolour = g_MenuColourPalettes[context->frame->type].unfocused;
//		} else {
//			maincolour = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].unfocused,
//					g_MenuColourPalettes[context->frame->type].unfocused,
//					context->frame->colourweight);
//		}
//
//		if (context->frame->dimmed) {
//			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
//		}
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].unfocused,
//				g_MenuColourPalettes2[context->frame->type].unfocused);
//	}
//
//	gdl = func0f153628(gdl);
//
//	if (context->focused) {
//		// Mismatch: The addiu and lui at ec8fc and ec900 are swapped. The addiu
//		// is adding the lower half of the address of g_MenuColourPalettes for
//		// use in the else branch. The lui is loading a value into $at for the
//		// float to u32 conversion for weight.
//		u32 focuscolour;
//		u32 weight = func0f006b08(40) * 255;
//
//		if (context->frame->transitiontimer < 0) {
//			focuscolour = g_MenuColourPalettes[context->frame->type].focused;
//		} else {
//			focuscolour = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].focused,
//					g_MenuColourPalettes[context->frame->type].focused,
//					context->frame->colourweight);
//		}
//
//		maincolour = colourBlend(colourBlend(maincolour, maincolour & 0xff, 127), focuscolour, weight);
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].focused,
//				g_MenuColourPalettes2[context->frame->type].focused);
//	}
//
//	if (menuIsItemDisabled(context->item, context->frame)) {
//		if (context->frame->transitiontimer < 0) {
//			maincolour = g_MenuColourPalettes[context->frame->type].disabled;
//		} else {
//			maincolour = colourBlend(
//					g_MenuColourPalettes[context->frame->type2].disabled,
//					g_MenuColourPalettes[context->frame->type].disabled,
//					context->frame->colourweight);
//		}
//
//		if (context->frame->dimmed) {
//			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
//		}
//
//		func0f153e38(
//				g_MenuColourPalettes3[context->frame->type].disabled,
//				g_MenuColourPalettes2[context->frame->type].disabled);
//
//		fillcolour = 0x7f002faf;
//	}
//
//	gdl = renderCheckbox(gdl, context->x + context->width - 16, context->y + 2, 6,
//			checked, maincolour, fillcolour);
//
//	x = context->x + 10;
//	y = context->y + 2;
//	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
//			maincolour, context->width, context->height, 0, 0);
//
//	return func0f153780(gdl);
//}

bool menuTickItemCheckbox(struct menuitem *item, struct menuinputs *inputs, u32 arg2)
{
	union handlerdata data;

	if ((arg2 & 2) && inputs->select) {
		if (item->handler && item->handler(MENUOP_GET, item, &data) == 1) {
			data.checkbox.value = 0;
			menuPlaySound(MENUSOUND_TOGGLEOFF);
		} else {
			data.checkbox.value = 1;
			menuPlaySound(MENUSOUND_TOGGLEON);
		}

		if (item->handler) {
			item->handler(MENUOP_SET, item, &data);
		}
	}

	return true;
}

char *menuItemScrollableGetText(u32 type)
{
	switch (type) {
	case DESCRIPTION_MPCONFIG:
		return mpconfigGetDescription(g_Menus[g_MpPlayerNum].training.mpconfig);
	case DESCRIPTION_MPCHALLENGE:
		if (!mpIsChallengeLoaded()) {
			g_Menus[g_MpPlayerNum].unk850 = 0x4fac5ace;
			mpLoadAndStoreCurrentChallenge(g_Menus[g_MpPlayerNum].mpconfigbuffer, g_Menus[g_MpPlayerNum].mpconfigbufferlen);
		}
		return mpGetCurrentChallengeDescription();
	case DESCRIPTION_CHRBIO:         return ciGetChrBioDescription();
	case DESCRIPTION_MISCBIO:        return ciGetMiscBioDescription();
	case DESCRIPTION_DEVICETRAINING: return dtGetDescription();
	case DESCRIPTION_FRWEAPON:       return frGetWeaponDescription();
	case DESCRIPTION_HANGARBIO:      return ciGetHangarBioDescription();
	case DESCRIPTION_HOLOTRAINING:   return htGetDescription();
	case DESCRIPTION_HOLOTIP1:       return htGetTip1();
	case DESCRIPTION_HOLOTIP2:       return htGetTip2();
	case DESCRIPTION_DEVICETIP1:     return dtGetTip1();
	case DESCRIPTION_DEVICETIP2:     return dtGetTip2();
	}

	return langGet(g_Briefing.briefingtextnum);
}

/**
 * Render a scrollable menu item, such as briefing paragraphs and challenge
 * descriptions.
 *
 * The text returned from menuItemScrollableGetText is first wrapped to fit the
 * width of the dialog. It is then separated into two strings:
 *
 * headings - which are started with the pipe character and ended with a
 * double line break
 * body text - which is anycontext else
 *
 * Headings are rendered in red, with a dropshadow and are outdented.
 */
Gfx *menuRenderItemScrollable(Gfx *gdl, struct menurendercontext *context)
{
	char alltext[8000] = "";
	char headingtext[8000];
	char bodytext[8000];
	bool prevwaslinebreak;
	char *streams[2];
	char *inptr;
	s32 inheading;
	struct menuitemdata_scrollable *data = &context->data->scrollable;
	u32 colour;
	s32 x;
	s32 y;
	char *rawtext;
	s32 paddingright = 24;

	rawtext = menuItemScrollableGetText(context->item->param);

	if (menuIsScrollableUnscrollable(context->item)) {
		paddingright = 10;
	}

	if (rawtext) {
		textWrap(context->width - paddingright, rawtext, alltext, g_CharsHandelGothicSm, g_FontHandelGothicSm);
	}

	inptr = alltext;
	streams[1] = headingtext;
	streams[0] = bodytext;
	inheading = 0;
	prevwaslinebreak = false;

	while (*inptr != '\0') {
		if (*inptr == '|') {
			// Pipe character - don't append it to either string,
			// but switch the active string to the heading one
			inheading = 1;
		} else if (*inptr == '\n') {
			// Copy line breaks to both strings
			*streams[0] = *inptr;
			streams[0]++;
			*streams[1] = *inptr;
			streams[1]++;

			if (prevwaslinebreak) {
				// Got two line breaks in a row, so switch the active string
				// back to the body one
				inheading = 0;
			}

			prevwaslinebreak = true;
		} else {
			// Append to whichever string is the active one
			prevwaslinebreak = false;
			*streams[inheading] = *inptr;
			streams[inheading]++;
		}

		inptr++;
	}

	*streams[0] = '\0';
	*streams[1] = '\0';

	x = context->x + 2;
	y = context->y + 2;

	if (context->frame->transitiontimer < 0) {
		colour = g_MenuColourPalettes[context->frame->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].unfocused,
				g_MenuColourPalettes[context->frame->type].unfocused,
				context->frame->colourweight);
	}

	if (context->frame->dimmed) {
		colour = colourBlend(colour, 0, 0x7f) & 0xffffff00 | colour & 0xff;
	}

	func0f153e38(
			g_MenuColourPalettes3[context->frame->type].unfocused,
			g_MenuColourPalettes2[context->frame->type].unfocused);

	gdl = func0f153628(gdl);

	// Heading text shadow
	x = context->x + 3;
	y = context->y + 3;
	gdl = textRenderProjected(gdl, &x, &y, headingtext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0x000000ff, context->width - 4, context->height - 4, -data->unk00, 0);

	// Heading text (red)
	x = context->x + 2;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, headingtext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0xff4444ff, context->width - 4, context->height - 4, -data->unk00, 0);

	// Body text
	x = menuIsScrollableUnscrollable(context->item) ? context->x + 5 : context->x + 12;
	y = context->y + 2;

	gdl = textRenderProjected(gdl, &x, &y, bodytext, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			colour, context->width - 4, context->height - 1, -data->unk00, 0);

	return func0f153780(gdl);
}

bool menuTickItemScrollable(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data)
{
	u32 stack;

#if PAL
	if ((s16)frame->height != data->scrollable.unk06 || data->scrollable.unk08 != g_LanguageId) {
#else
	if ((s16)frame->height != data->scrollable.unk06) {
#endif
		char wrapped[8000] = "";
		char *rawtext;
		s32 width;
		s32 height;
		u32 index1;
		u32 index2;
		s16 wvalue;
		s16 hvalue;

#if PAL
		data->scrollable.unk08 = g_LanguageId;
#endif

		func0f0f2354(frame, item, &index1, &index2);

		wvalue = g_Menus[g_MpPlayerNum].unk660[index2][0];
		hvalue = g_Menus[g_MpPlayerNum].unk4fc[index1][0];

		if (menuIsScrollableUnscrollable(item)) {
			width = wvalue - 10;
		} else {
			width = wvalue - 24;
		}

		rawtext = menuItemScrollableGetText(item->param);

		if (rawtext) {
			textWrap(width, rawtext, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm);
		}

		textMeasure(&height, &width, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		data->scrollable.unk04 = height - hvalue + 5;

		if (data->scrollable.unk04 < -10) {
			data->scrollable.unk04 = -10;
		}

		data->scrollable.unk06 = frame->height;
	}

	if (menuIsScrollableUnscrollable(item)) {
		data->scrollable.unk00 = 0;
	} else if (arg3 & 2) {
		f32 floatval;
		s32 intval = 0;

		if (inputs->yaxis < 0) {
			floatval = -(f32)inputs->yaxis;
		} else {
			floatval = inputs->yaxis;
		}

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_FINAL
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			if (inputs->yaxis < 0) {
				intval = floatval;
			} else {
				intval = -(s32)floatval;
			}
		}

#if VERSION >= VERSION_PAL_FINAL
		intval = intval + (s32)(((f32)inputs->unk09 + (f32)inputs->unk09) * g_Vars.diffframe60freal);
#else
		intval += inputs->unk09 * 2 * g_Vars.diffframe60;
#endif
		data->scrollable.unk00 += intval;

		if (data->scrollable.unk00 < -10) {
			data->scrollable.unk00 = -10;
		}

		if (data->scrollable.unk00 > data->scrollable.unk04) {
			data->scrollable.unk00 = data->scrollable.unk04;
		}
	}

	return true;
}

void menuInitItemScrollable(union menuitemdata *data)
{
	data->scrollable.unk06 = -1;
	data->scrollable.unk00 = -10;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuRenderItemMarquee
/*  f0ed528:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0ed52c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ed530:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ed534:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ed538:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f0ed53c:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ed540:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ed544:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0ed548:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0ed54c:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ed550:	3c0f8007 */ 	lui	$t7,%hi(var800711ec)
/*  f0ed554:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicSm)
/*  f0ed558:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicSm)
/*  f0ed55c:	95ef11ec */ 	lhu	$t7,%lo(var800711ec)($t7)
/*  f0ed560:	8f18fb0c */ 	lw	$t8,%lo(g_FontHandelGothicSm)($t8)
/*  f0ed564:	8f39fb10 */ 	lw	$t9,%lo(g_CharsHandelGothicSm)($t9)
/*  f0ed568:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0ed56c:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0ed570:	a7af0064 */ 	sh	$t7,0x64($sp)
/*  f0ed574:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0ed578:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0ed57c:	8e280008 */ 	lw	$t0,0x8($s1)
/*  f0ed580:	3c0b8008 */ 	lui	$t3,%hi(g_FontHandelGothicXs)
/*  f0ed584:	3c0c8008 */ 	lui	$t4,%hi(g_CharsHandelGothicXs)
/*  f0ed588:	8d090004 */ 	lw	$t1,0x4($t0)
/*  f0ed58c:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f0ed590:	11400005 */ 	beqz	$t2,.L0f0ed5a8
/*  f0ed594:	00000000 */ 	nop
/*  f0ed598:	8d6bfb04 */ 	lw	$t3,%lo(g_FontHandelGothicXs)($t3)
/*  f0ed59c:	8d8cfb08 */ 	lw	$t4,%lo(g_CharsHandelGothicXs)($t4)
/*  f0ed5a0:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ed5a4:	afac0058 */ 	sw	$t4,0x58($sp)
.L0f0ed5a8:
/*  f0ed5a8:	54400004 */ 	bnezl	$v0,.L0f0ed5bc
/*  f0ed5ac:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0ed5b0:	1000011b */ 	b	.L0f0eda20
/*  f0ed5b4:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed5b8:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed5bc:
/*  f0ed5bc:	44803000 */ 	mtc1	$zero,$f6
/*  f0ed5c0:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ed5c4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ed5c8:	00000000 */ 	nop
/*  f0ed5cc:	4502000c */ 	bc1fl	.L0f0ed600
/*  f0ed5d0:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0ed5d4:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0ed5d8:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed5dc:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ed5e0:	01a70019 */ 	multu	$t5,$a3
/*  f0ed5e4:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ed5e8:	00007012 */ 	mflo	$t6
/*  f0ed5ec:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0ed5f0:	8df80018 */ 	lw	$t8,0x18($t7)
/*  f0ed5f4:	10000012 */ 	b	.L0f0ed640
/*  f0ed5f8:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0ed5fc:	9079003d */ 	lbu	$t9,0x3d($v1)
.L0f0ed600:
/*  f0ed600:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0ed604:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0ed608:	03270019 */ 	multu	$t9,$a3
/*  f0ed60c:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0ed610:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0ed614:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ed618:	00004012 */ 	mflo	$t0
/*  f0ed61c:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0ed620:	8d240018 */ 	lw	$a0,0x18($t1)
/*  f0ed624:	01470019 */ 	multu	$t2,$a3
/*  f0ed628:	00005812 */ 	mflo	$t3
/*  f0ed62c:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f0ed630:	0fc01a40 */ 	jal	colourBlend
/*  f0ed634:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0ed638:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0ed63c:	8e230010 */ 	lw	$v1,0x10($s1)
.L0f0ed640:
/*  f0ed640:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f0ed644:	51a0000c */ 	beqzl	$t5,.L0f0ed678
/*  f0ed648:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0ed64c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0ed650:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ed654:	0fc01a40 */ 	jal	colourBlend
/*  f0ed658:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ed65c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ed660:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ed664:	00417024 */ 	and	$t6,$v0,$at
/*  f0ed668:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0ed66c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ed670:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0ed674:	8fab0084 */ 	lw	$t3,0x84($sp)
.L0f0ed678:
/*  f0ed678:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed67c:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0ed680:	956c0000 */ 	lhu	$t4,0x0($t3)
/*  f0ed684:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0ed688:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0ed68c:	014c6823 */ 	subu	$t5,$t2,$t4
/*  f0ed690:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0ed694:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0ed698:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ed69c:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0ed6a0:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0ed6a4:	03198021 */ 	addu	$s0,$t8,$t9
/*  f0ed6a8:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0ed6ac:
/*  f0ed6ac:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ed6b0:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ed6b4:	14400003 */ 	bnez	$v0,.L0f0ed6c4
/*  f0ed6b8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ed6bc:	10000013 */ 	b	.L0f0ed70c
/*  f0ed6c0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ed6c4:
/*  f0ed6c4:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0ed6c8:	a3a20064 */ 	sb	$v0,0x64($sp)
/*  f0ed6cc:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f0ed6d0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ed6d4:	0fc55cbe */ 	jal	textMeasure
/*  f0ed6d8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ed6dc:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f0ed6e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f0ed6e4:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0ed6e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0ed6ec:	012b1821 */ 	addu	$v1,$t1,$t3
/*  f0ed6f0:	0143082a */ 	slt	$at,$t2,$v1
/*  f0ed6f4:	50200004 */ 	beqzl	$at,.L0f0ed708
/*  f0ed6f8:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f0ed6fc:	10000003 */ 	b	.L0f0ed70c
/*  f0ed700:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ed704:	afa3007c */ 	sw	$v1,0x7c($sp)
.L0f0ed708:
/*  f0ed708:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ed70c:
/*  f0ed70c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ed710:	5041ffe6 */ 	beql	$v0,$at,.L0f0ed6ac
/*  f0ed714:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ed718:	3c028008 */ 	lui	$v0,%hi(g_ScaleX)
/*  f0ed71c:	8c42fac0 */ 	lw	$v0,%lo(g_ScaleX)($v0)
/*  f0ed720:	862c0000 */ 	lh	$t4,0x0($s1)
/*  f0ed724:	3c038007 */ 	lui	$v1,%hi(g_ScissorX1)
/*  f0ed728:	24631190 */ 	addiu	$v1,$v1,%lo(g_ScissorX1)
/*  f0ed72c:	01820019 */ 	multu	$t4,$v0
/*  f0ed730:	3c048007 */ 	lui	$a0,%hi(g_ScissorX2)
/*  f0ed734:	24841194 */ 	addiu	$a0,$a0,%lo(g_ScissorX2)
/*  f0ed738:	3c068007 */ 	lui	$a2,%hi(g_ScissorY1)
/*  f0ed73c:	24c61198 */ 	addiu	$a2,$a2,%lo(g_ScissorY1)
/*  f0ed740:	3c058007 */ 	lui	$a1,%hi(g_ScissorY2)
/*  f0ed744:	24a5119c */ 	addiu	$a1,$a1,%lo(g_ScissorY2)
/*  f0ed748:	00006812 */ 	mflo	$t5
/*  f0ed74c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0ed750:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0ed754:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ed758:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0ed75c:	03020019 */ 	multu	$t8,$v0
/*  f0ed760:	0000c812 */ 	mflo	$t9
/*  f0ed764:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0ed768:	86280002 */ 	lh	$t0,0x2($s1)
/*  f0ed76c:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f0ed770:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0ed774:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ed778:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0ed77c:	254cffff */ 	addiu	$t4,$t2,-1
/*  f0ed780:	05a10002 */ 	bgez	$t5,.L0f0ed78c
/*  f0ed784:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f0ed788:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f0ed78c:
/*  f0ed78c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0ed790:	05e30003 */ 	bgezl	$t7,.L0f0ed7a0
/*  f0ed794:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0ed798:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0ed79c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f0ed7a0:
/*  f0ed7a0:	05c30003 */ 	bgezl	$t6,.L0f0ed7b0
/*  f0ed7a4:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0ed7a8:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0ed7ac:	8cb80000 */ 	lw	$t8,0x0($a1)
.L0f0ed7b0:
/*  f0ed7b0:	07010002 */ 	bgez	$t8,.L0f0ed7bc
/*  f0ed7b4:	00000000 */ 	nop
/*  f0ed7b8:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0ed7bc:
/*  f0ed7bc:	0c002ef1 */ 	jal	viGetBufX
/*  f0ed7c0:	00000000 */ 	nop
/*  f0ed7c4:	3c198007 */ 	lui	$t9,%hi(g_ScissorX1)
/*  f0ed7c8:	8f391190 */ 	lw	$t9,%lo(g_ScissorX1)($t9)
/*  f0ed7cc:	0059082a */ 	slt	$at,$v0,$t9
/*  f0ed7d0:	10200005 */ 	beqz	$at,.L0f0ed7e8
/*  f0ed7d4:	00000000 */ 	nop
/*  f0ed7d8:	0c002ef1 */ 	jal	viGetBufX
/*  f0ed7dc:	00000000 */ 	nop
/*  f0ed7e0:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0ed7e4:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0ed7e8:
/*  f0ed7e8:	0c002ef1 */ 	jal	viGetBufX
/*  f0ed7ec:	00000000 */ 	nop
/*  f0ed7f0:	3c088007 */ 	lui	$t0,%hi(g_ScissorX2)
/*  f0ed7f4:	8d081194 */ 	lw	$t0,%lo(g_ScissorX2)($t0)
/*  f0ed7f8:	0048082a */ 	slt	$at,$v0,$t0
/*  f0ed7fc:	10200005 */ 	beqz	$at,.L0f0ed814
/*  f0ed800:	00000000 */ 	nop
/*  f0ed804:	0c002ef1 */ 	jal	viGetBufX
/*  f0ed808:	00000000 */ 	nop
/*  f0ed80c:	3c018007 */ 	lui	$at,%hi(g_ScissorX2)
/*  f0ed810:	ac221194 */ 	sw	$v0,%lo(g_ScissorX2)($at)
.L0f0ed814:
/*  f0ed814:	0c002ef5 */ 	jal	viGetBufY
/*  f0ed818:	00000000 */ 	nop
/*  f0ed81c:	3c098007 */ 	lui	$t1,%hi(g_ScissorY1)
/*  f0ed820:	8d291198 */ 	lw	$t1,%lo(g_ScissorY1)($t1)
/*  f0ed824:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ed828:	10200005 */ 	beqz	$at,.L0f0ed840
/*  f0ed82c:	00000000 */ 	nop
/*  f0ed830:	0c002ef5 */ 	jal	viGetBufY
/*  f0ed834:	00000000 */ 	nop
/*  f0ed838:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0ed83c:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0ed840:
/*  f0ed840:	0c002ef5 */ 	jal	viGetBufY
/*  f0ed844:	00000000 */ 	nop
/*  f0ed848:	3c068007 */ 	lui	$a2,%hi(g_ScissorY2)
/*  f0ed84c:	24c6119c */ 	addiu	$a2,$a2,%lo(g_ScissorY2)
/*  f0ed850:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ed854:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ed858:	10200009 */ 	beqz	$at,.L0f0ed880
/*  f0ed85c:	00000000 */ 	nop
/*  f0ed860:	0c002ef5 */ 	jal	viGetBufY
/*  f0ed864:	00000000 */ 	nop
/*  f0ed868:	3c018007 */ 	lui	$at,%hi(g_ScissorY2)
/*  f0ed86c:	ac22119c */ 	sw	$v0,%lo(g_ScissorY2)($at)
/*  f0ed870:	3c058007 */ 	lui	$a1,%hi(g_ScissorY2)
/*  f0ed874:	3c068007 */ 	lui	$a2,%hi(g_ScissorY2)
/*  f0ed878:	24c6119c */ 	addiu	$a2,$a2,%lo(g_ScissorY2)
/*  f0ed87c:	8ca5119c */ 	lw	$a1,%lo(g_ScissorY2)($a1)
.L0f0ed880:
/*  f0ed880:	3c078007 */ 	lui	$a3,%hi(g_ScissorX2)
/*  f0ed884:	3c038007 */ 	lui	$v1,%hi(g_ScissorX1)
/*  f0ed888:	8c631190 */ 	lw	$v1,%lo(g_ScissorX1)($v1)
/*  f0ed88c:	24e71194 */ 	addiu	$a3,$a3,%lo(g_ScissorX2)
/*  f0ed890:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed894:	44834000 */ 	mtc1	$v1,$f8
/*  f0ed898:	3c048007 */ 	lui	$a0,%hi(g_ScissorY1)
/*  f0ed89c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0ed8a0:	10200002 */ 	beqz	$at,.L0f0ed8ac
/*  f0ed8a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed8a8:	ace30000 */ 	sw	$v1,0x0($a3)
.L0f0ed8ac:
/*  f0ed8ac:	8c841198 */ 	lw	$a0,%lo(g_ScissorY1)($a0)
/*  f0ed8b0:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0ed8b4:	50200003 */ 	beqzl	$at,.L0f0ed8c4
/*  f0ed8b8:	44842000 */ 	mtc1	$a0,$f4
/*  f0ed8bc:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0ed8c0:	44842000 */ 	mtc1	$a0,$f4
.L0f0ed8c4:
/*  f0ed8c4:	3c014080 */ 	lui	$at,0x4080
/*  f0ed8c8:	44810000 */ 	mtc1	$at,$f0
/*  f0ed8cc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ed8d0:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ed8d4:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed8d8:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ed8dc:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0ed8e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ed8e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed8e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ed8ec:	440c9000 */ 	mfc1	$t4,$f18
/*  f0ed8f0:	44195000 */ 	mfc1	$t9,$f10
/*  f0ed8f4:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed8f8:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed8fc:	01e17025 */ 	or	$t6,$t7,$at
/*  f0ed900:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f0ed904:	01c84825 */ 	or	$t1,$t6,$t0
/*  f0ed908:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0ed90c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0ed910:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0ed914:	448b8000 */ 	mtc1	$t3,$f16
/*  f0ed918:	44984000 */ 	mtc1	$t8,$f8
/*  f0ed91c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ed920:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ed924:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ed928:	00000000 */ 	nop
/*  f0ed92c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ed930:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ed934:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ed938:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ed93c:	440e9000 */ 	mfc1	$t6,$f18
/*  f0ed940:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0ed944:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f0ed948:	31c80fff */ 	andi	$t0,$t6,0xfff
/*  f0ed94c:	01e84825 */ 	or	$t1,$t7,$t0
/*  f0ed950:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0ed954:	0fc54f49 */ 	jal	func0f153d24
/*  f0ed958:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f0ed95c:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0ed960:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*  f0ed964:	314c0800 */ 	andi	$t4,$t2,0x800
/*  f0ed968:	51800009 */ 	beqzl	$t4,.L0f0ed990
/*  f0ed96c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed970:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ed974:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ed978:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed97c:	0fc54f3a */ 	jal	func0f153ce8
/*  f0ed980:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f0ed984:	10000005 */ 	b	.L0f0ed99c
/*  f0ed988:	00000000 */ 	nop
/*  f0ed98c:	86240000 */ 	lh	$a0,0x0($s1)
.L0f0ed990:
/*  f0ed990:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ed994:	0fc54f3a */ 	jal	func0f153ce8
/*  f0ed998:	00802825 */ 	or	$a1,$a0,$zero
.L0f0ed99c:
/*  f0ed99c:	0fc54d8a */ 	jal	func0f153628
/*  f0ed9a0:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0ed9a4:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0ed9a8:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0ed9ac:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0ed9b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ed9b4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ed9b8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ed9bc:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ed9c0:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0ed9c4:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0ed9c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ed9cc:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f0ed9d0:	012b5023 */ 	subu	$t2,$t1,$t3
/*  f0ed9d4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ed9d8:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0ed9dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ed9e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ed9e4:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0ed9e8:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0ed9ec:	02003825 */ 	or	$a3,$s0,$zero
/*  f0ed9f0:	0fc5580f */ 	jal	textRenderProjected
/*  f0ed9f4:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ed9f8:	0fc54de0 */ 	jal	func0f153780
/*  f0ed9fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda00:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0eda04:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eda08:	0fc54f4f */ 	jal	func0f153d3c
/*  f0eda0c:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0eda10:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0eda14:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f0eda18:	a70d0004 */ 	sh	$t5,0x4($t8)
/*  f0eda1c:	8fa20088 */ 	lw	$v0,0x88($sp)
.L0f0eda20:
/*  f0eda20:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eda24:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eda28:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eda2c:	03e00008 */ 	jr	$ra
/*  f0eda30:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#else
GLOBAL_ASM(
glabel menuRenderItemMarquee
/*  f0ea690:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ea694:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0ea698:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0ea69c:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0ea6a0:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0ea6a4:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0ea6a8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0ea6ac:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0ea6b0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ea6b4:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ea6b8:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ea6bc:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ea6c0:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0ea6c4:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0ea6c8:	0fc3b85b */ 	jal	menuResolveParam2Text
/*  f0ea6cc:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ea6d0:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0ea6d4:	25ef389c */ 	addiu	$t7,$t7,0x389c
/*  f0ea6d8:	95e10000 */ 	lhu	$at,0x0($t7)
/*  f0ea6dc:	27b50074 */ 	addiu	$s5,$sp,0x74
/*  f0ea6e0:	3c168008 */ 	lui	$s6,0x8008
/*  f0ea6e4:	a6a10000 */ 	sh	$at,0x0($s5)
/*  f0ea6e8:	8e290008 */ 	lw	$t1,0x8($s1)
/*  f0ea6ec:	3c178008 */ 	lui	$s7,0x8008
/*  f0ea6f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f0ea6f4:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f0ea6f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0ea6fc:	8ed6236c */ 	lw	$s6,0x236c($s6)
/*  f0ea700:	314b0200 */ 	andi	$t3,$t2,0x200
/*  f0ea704:	11600005 */ 	beqz	$t3,.NB0f0ea71c
/*  f0ea708:	8ef72370 */ 	lw	$s7,0x2370($s7)
/*  f0ea70c:	3c168008 */ 	lui	$s6,0x8008
/*  f0ea710:	3c178008 */ 	lui	$s7,0x8008
/*  f0ea714:	8ed62364 */ 	lw	$s6,0x2364($s6)
/*  f0ea718:	8ef72368 */ 	lw	$s7,0x2368($s7)
.NB0f0ea71c:
/*  f0ea71c:	54400004 */ 	bnezl	$v0,.NB0f0ea730
/*  f0ea720:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ea724:	100000c3 */ 	beqz	$zero,.NB0f0eaa34
/*  f0ea728:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0ea72c:	8e300010 */ 	lw	$s0,0x10($s1)
.NB0f0ea730:
/*  f0ea730:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea734:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0ea738:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea73c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea740:	4502000c */ 	bc1fl	.NB0f0ea774
/*  f0ea744:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f0ea748:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0ea74c:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ea750:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ea754:	01830019 */ 	multu	$t4,$v1
/*  f0ea758:	2442c2e0 */ 	addiu	$v0,$v0,-15648
/*  f0ea75c:	00006812 */ 	mflo	$t5
/*  f0ea760:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ea764:	8dd90018 */ 	lw	$t9,0x18($t6)
/*  f0ea768:	10000012 */ 	beqz	$zero,.NB0f0ea7b4
/*  f0ea76c:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0ea770:	9218003d */ 	lbu	$t8,0x3d($s0)
.NB0f0ea774:
/*  f0ea774:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f0ea778:	9209003c */ 	lbu	$t1,0x3c($s0)
/*  f0ea77c:	03030019 */ 	multu	$t8,$v1
/*  f0ea780:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ea784:	2442c2e0 */ 	addiu	$v0,$v0,-15648
/*  f0ea788:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ea78c:	00007812 */ 	mflo	$t7
/*  f0ea790:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f0ea794:	8d040018 */ 	lw	$a0,0x18($t0)
/*  f0ea798:	01230019 */ 	multu	$t1,$v1
/*  f0ea79c:	00005012 */ 	mflo	$t2
/*  f0ea7a0:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f0ea7a4:	0fc01990 */ 	jal	colourBlend
/*  f0ea7a8:	8d650018 */ 	lw	$a1,0x18($t3)
/*  f0ea7ac:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0ea7b0:	8e300010 */ 	lw	$s0,0x10($s1)
.NB0f0ea7b4:
/*  f0ea7b4:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0ea7b8:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f0ea7bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ea7c0:	5180000a */ 	beqzl	$t4,.NB0f0ea7ec
/*  f0ea7c4:	8faa0094 */ 	lw	$t2,0x94($sp)
/*  f0ea7c8:	0fc01990 */ 	jal	colourBlend
/*  f0ea7cc:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0ea7d0:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0ea7d4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ea7d8:	00416824 */ 	and	$t5,$v0,$at
/*  f0ea7dc:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f0ea7e0:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f0ea7e4:	afb80084 */ 	sw	$t8,0x84($sp)
/*  f0ea7e8:	8faa0094 */ 	lw	$t2,0x94($sp)
.NB0f0ea7ec:
/*  f0ea7ec:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ea7f0:	86280004 */ 	lh	$t0,0x4($s1)
/*  f0ea7f4:	954b0000 */ 	lhu	$t3,0x0($t2)
/*  f0ea7f8:	02538021 */ 	addu	$s0,$s2,$s3
/*  f0ea7fc:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f0ea800:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f0ea804:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f0ea808:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0ea80c:	27b30078 */ 	addiu	$s3,$sp,0x78
/*  f0ea810:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0ea814:	25cd0002 */ 	addiu	$t5,$t6,0x2
/*  f0ea818:	afad0088 */ 	sw	$t5,0x88($sp)
/*  f0ea81c:	27b4007c */ 	addiu	$s4,$sp,0x7c
/*  f0ea820:	92020000 */ 	lbu	$v0,0x0($s0)
.NB0f0ea824:
/*  f0ea824:	02602025 */ 	or	$a0,$s3,$zero
/*  f0ea828:	02802825 */ 	or	$a1,$s4,$zero
/*  f0ea82c:	14400003 */ 	bnez	$v0,.NB0f0ea83c
/*  f0ea830:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ea834:	10000012 */ 	beqz	$zero,.NB0f0ea880
/*  f0ea838:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0ea83c:
/*  f0ea83c:	a3a20074 */ 	sb	$v0,0x74($sp)
/*  f0ea840:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0ea844:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0ea848:	0fc54655 */ 	jal	textMeasure
/*  f0ea84c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea850:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0ea854:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0ea858:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ea85c:	02401025 */ 	or	$v0,$s2,$zero
/*  f0ea860:	03381821 */ 	addu	$v1,$t9,$t8
/*  f0ea864:	01e3082a */ 	slt	$at,$t7,$v1
/*  f0ea868:	50200004 */ 	beqzl	$at,.NB0f0ea87c
/*  f0ea86c:	afa3008c */ 	sw	$v1,0x8c($sp)
/*  f0ea870:	10000003 */ 	beqz	$zero,.NB0f0ea880
/*  f0ea874:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ea878:	afa3008c */ 	sw	$v1,0x8c($sp)
.NB0f0ea87c:
/*  f0ea87c:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0ea880:
/*  f0ea880:	5052ffe8 */ 	beql	$v0,$s2,.NB0f0ea824
/*  f0ea884:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ea888:	3c038008 */ 	lui	$v1,0x8008
/*  f0ea88c:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0ea890:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0ea894:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ea898:	86380002 */ 	lh	$t8,0x2($s1)
/*  f0ea89c:	3c014080 */ 	lui	$at,0x4080
/*  f0ea8a0:	010a0019 */ 	multu	$t0,$t2
/*  f0ea8a4:	44982000 */ 	mtc1	$t8,$f4
/*  f0ea8a8:	44810000 */ 	mtc1	$at,$f0
/*  f0ea8ac:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0ea8b0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ea8b4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ea8b8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0ea8bc:	00004812 */ 	mflo	$t1
/*  f0ea8c0:	44894000 */ 	mtc1	$t1,$f8
/*  f0ea8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea8c8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ea8cc:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ea8d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea8d4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ea8d8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ea8dc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ea8e0:	440c9000 */ 	mfc1	$t4,$f18
/*  f0ea8e4:	44085000 */ 	mfc1	$t0,$f10
/*  f0ea8e8:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0ea8ec:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f0ea8f0:	01a1c825 */ 	or	$t9,$t5,$at
/*  f0ea8f4:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0ea8f8:	032a4825 */ 	or	$t1,$t9,$t2
/*  f0ea8fc:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0ea900:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ea904:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0ea908:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0ea90c:	86290002 */ 	lh	$t1,0x2($s1)
/*  f0ea910:	016c7021 */ 	addu	$t6,$t3,$t4
/*  f0ea914:	01cd0019 */ 	multu	$t6,$t5
/*  f0ea918:	862b0006 */ 	lh	$t3,0x6($s1)
/*  f0ea91c:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f0ea920:	258effff */ 	addiu	$t6,$t4,-1
/*  f0ea924:	448e4000 */ 	mtc1	$t6,$f8
/*  f0ea928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea92c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ea930:	0000c012 */ 	mflo	$t8
/*  f0ea934:	44988000 */ 	mtc1	$t8,$f16
/*  f0ea938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea93c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ea940:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ea944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea948:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ea94c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ea950:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ea954:	44083000 */ 	mfc1	$t0,$f6
/*  f0ea958:	44189000 */ 	mfc1	$t8,$f18
/*  f0ea95c:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ea960:	00195300 */ 	sll	$t2,$t9,0xc
/*  f0ea964:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0ea968:	014f4025 */ 	or	$t0,$t2,$t7
/*  f0ea96c:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0ea970:	0fc538e0 */ 	jal	func0f153d24
/*  f0ea974:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0ea978:	8e390008 */ 	lw	$t9,0x8($s1)
/*  f0ea97c:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f0ea980:	312b0800 */ 	andi	$t3,$t1,0x800
/*  f0ea984:	51600009 */ 	beqzl	$t3,.NB0f0ea9ac
/*  f0ea988:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ea98c:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ea990:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0ea994:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ea998:	0fc538d1 */ 	jal	func0f153ce8
/*  f0ea99c:	008c2821 */ 	addu	$a1,$a0,$t4
/*  f0ea9a0:	10000005 */ 	beqz	$zero,.NB0f0ea9b8
/*  f0ea9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ea9a8:	86240000 */ 	lh	$a0,0x0($s1)
.NB0f0ea9ac:
/*  f0ea9ac:	2406000e */ 	addiu	$a2,$zero,0xe
/*  f0ea9b0:	0fc538d1 */ 	jal	func0f153ce8
/*  f0ea9b4:	00802825 */ 	or	$a1,$a0,$zero
.NB0f0ea9b8:
/*  f0ea9b8:	0fc5374a */ 	jal	func0f153628
/*  f0ea9bc:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0ea9c0:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0ea9c4:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0ea9c8:	afb60014 */ 	sw	$s6,0x14($sp)
/*  f0ea9cc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0ea9d0:	86380000 */ 	lh	$t8,0x0($s1)
/*  f0ea9d4:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0ea9d8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0ea9dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea9e0:	01b85021 */ 	addu	$t2,$t5,$t8
/*  f0ea9e4:	014f4023 */ 	subu	$t0,$t2,$t7
/*  f0ea9e8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ea9ec:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0ea9f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea9f4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea9f8:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0ea9fc:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0eaa00:	02003825 */ 	or	$a3,$s0,$zero
/*  f0eaa04:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eaa08:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0eaa0c:	0fc537a0 */ 	jal	func0f153780
/*  f0eaa10:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eaa14:	0fc3c728 */ 	jal	func0f0f50fc
/*  f0eaa18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eaa1c:	0fc538e6 */ 	jal	func0f153d3c
/*  f0eaa20:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0eaa24:	86290004 */ 	lh	$t1,0x4($s1)
/*  f0eaa28:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f0eaa2c:	a5690004 */ 	sh	$t1,0x4($t3)
/*  f0eaa30:	8fa20098 */ 	lw	$v0,0x98($sp)
.NB0f0eaa34:
/*  f0eaa34:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0eaa38:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0eaa3c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0eaa40:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0eaa44:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0eaa48:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0eaa4c:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0eaa50:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0eaa54:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0eaa58:	03e00008 */ 	jr	$ra
/*  f0eaa5c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

u32 var800711ec = 0x20000000;

// Mismatch at 718
//Gfx *menuRenderItemMarquee(Gfx *gdl, struct menurendercontext *context)
//{
//	u16 *unk14 = context->unk14.u16; // 84
//	char *text = menuResolveParam2Text(context->item); // 80
//	s32 x; // 7c
//	s32 y; // 78
//	u32 colour; // 74
//	s32 i = 0; // 70
//	s32 textwidth; // 6c
//	s32 textheight; // 68
//	char string[] = {' ', '\0'}; // 64 - var800711ec
//	s32 hasmore;
//	struct font *font2 = g_FontHandelGothicSm; // 5c
//	struct fontchar *font1 = g_CharsHandelGothicSm; // 58
//
//	if (context->item->param1 & 0x00000200) {
//		font2 = g_FontHandelGothicXs;
//		font1 = g_CharsHandelGothicXs;
//	}
//
//	if (!text) {
//		return gdl;
//	}
//
//	// 5b8
//	if (context->frame->transitiontimer < 0) {
//		colour = g_MenuColourPalettes[context->frame->type].unfocused;
//	} else {
//		colour = colourBlend(
//				g_MenuColourPalettes[context->frame->type2].unfocused,
//				g_MenuColourPalettes[context->frame->type].unfocused,
//				context->frame->colourweight);
//	}
//
//	// 644
//	if (context->frame->dimmed) {
//		colour = colourBlend(colour, 0, 127) & 0xffffff00 | colour & 0xff;
//	}
//
//	// 674
//	x = context->x + context->width - *unk14;
//	y = context->y + 2;
//	hasmore = true;
//
//	while (hasmore == true) {
//		if (text[i] == '\0') {
//			hasmore = false;
//		} else {
//			string[0] = text[i];
//			textMeasure(&textheight, &textwidth, string, font1, font2, 0);
//
//			if (x + textwidth > context->x) {
//				hasmore = false;
//			} else {
//				x += textwidth;
//				hasmore = true;
//				i++;
//			}
//		}
//	}
//
//	// 718
//	// context->x is loaded into a0 but should be t4. Additionally, the loads of
//	// context->x and g_ScaleX are swapped.
//	g_ScissorX1 = context->x * g_ScaleX;
//	g_ScissorX2 = (context->x + context->width) * g_ScaleX;
//	g_ScissorY1 = context->y;
//	g_ScissorY2 = context->y + context->height - 1;
//
//	if (g_ScissorX1 < 0) {
//		g_ScissorX1 = 0;
//	}
//
//	if (g_ScissorX2 < 0) {
//		g_ScissorX2 = 0;
//	}
//
//	if (g_ScissorY1 < 0) {
//		g_ScissorY1 = 0;
//	}
//
//	if (g_ScissorY2 < 0) {
//		g_ScissorY2 = 0;
//	}
//
//	if (g_ScissorX1 > viGetBufX()) {
//		g_ScissorX1 = viGetBufX();
//	}
//
//	if (g_ScissorX2 > viGetBufX()) {
//		g_ScissorX2 = viGetBufX();
//	}
//
//	if (g_ScissorY1 > viGetBufY()) {
//		g_ScissorY1 = viGetBufY();
//	}
//
//	if (g_ScissorY2 > viGetBufY()) {
//		g_ScissorY2 = viGetBufY();
//	}
//
//	if (g_ScissorX2 < g_ScissorX1) {
//		g_ScissorX2 = g_ScissorX1;
//	}
//
//	if (g_ScissorY2 < g_ScissorY1) {
//		g_ScissorY2 = g_ScissorY1;
//	}
//
//	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
//
//	func0f153d24();
//
//	if (context->item->param1 & 0x00000800) {
//		func0f153ce8(context->x, context->x + context->width, 0xe);
//	} else {
//		func0f153ce8(context->x, context->x, 0xe);
//	}
//
//	gdl = func0f153628(gdl);
//	gdl = textRenderProjected(gdl, &x, &y, &text[i], font1, font2,
//			colour, context->width + context->x - x, context->height, 0, 0);
//	gdl = func0f153780(gdl);
//	gdl = func0f0f50fc(gdl);
//
//	func0f153d3c();
//
//	unk14[2] = context->width;
//
//	return gdl;
//}

u32 var800711f0 = 0x00000002;
u32 var800711f4 = 0x0000000c;
u32 var800711f8 = PAL ? -1 : 10;
u32 var800711fc = 0xffffffff;
u32 var80071200 = PAL ? 10 : 3;
u32 var80071204 = 0x00000033;
u32 var80071208 = PAL ? -1 : 10;
u32 var8007120c = 0xffffffff;
u32 var80071210 = PAL ? 10 : 3;
u32 var80071214 = 0x0000000c;
u32 var80071218 = PAL ? -1 : 3;
u32 var8007121c = 0x0000004b;
u32 var80071220 = 0xffffffff;
u32 var80071224 = 0x00000037;
u32 var80071228 = 0x00000013;
u32 var8007122c = 0x00000040;
u32 var80071230 = 0xffffffff;
u32 var80071234 = 0x0000003f;
u32 var80071238 = 0x00000013;
u32 var8007123c = 0xffffffff;
u32 var80071240 = PAL ? 7 : 10;
u32 var80071244 = 0x0000003f;
u32 var80071248 = PAL ? 7 : 10;
u32 var8007124c = 0x0000004b;
u32 var80071250 = 0xffffffff;
u32 var80071254 = 0x00000033;
u32 var80071258 = 0x00000017;
u32 var8007125c = 0x00000037;
u32 var80071260 = 0xffffffff;
u32 var80071264 = 0x0000003b;
u32 var80071268 = 0x00000017;
u32 var8007126c = 0x00000044;
u32 var80071270 = 0xffffffff;
u32 var80071274 = 0x00000043;
u32 var80071278 = 0x00000017;
u32 var8007127c = 0xffffffff;
u32 var80071280 = PAL ? 15 : 17;
u32 var80071284 = 0x00000043;
u32 var80071288 = PAL ? 15 : 17;
u32 var8007128c = 0x0000004b;
u32 var80071290 = 0xffffffff;
u32 var80071294 = 0x00000037;
u32 var80071298 = 0x0000001b;
u32 var8007129c = 0x00000048;
u32 var800712a0 = 0xffffffff;
u32 var800712a4 = 0x00000047;
u32 var800712a8 = 0x0000001b;
u32 var800712ac = 0xffffffff;
u32 var800712b0 = PAL ? 23 : 24;
u32 var800712b4 = 0x00000047;
u32 var800712b8 = PAL ? 23 : 24;
u32 var800712bc = 0x0000004b;
u32 var800712c0 = 0xffffffff;
u32 var800712c4 = 0x00000031;
u32 var800712c8 = 0x0000001f;
u32 var800712cc = 0x0000004b;
u32 var800712d0 = 0xffffffff;
u32 var800712d4 = 0x0000002b;
u32 var800712d8 = 0x0000001c;
u32 var800712dc = 0xffffffff;
u32 var800712e0 = PAL ? 39 : 38;
u32 var800712e4 = 0x0000002b;
u32 var800712e8 = PAL ? 39 : 38;
u32 var800712ec = 0x0000004b;
u32 var800712f0 = 0xffffffff;
u32 var800712f4 = 0x0000001e;
u32 var800712f8 = 0x00000023;
u32 var800712fc = 0x00000025;
u32 var80071300 = 0xffffffff;
u32 var80071304 = 0x00000025;
u32 var80071308 = 0x00000023;
u32 var8007130c = 0xffffffff;
u32 var80071310 = PAL ? 47 : 45;
u32 var80071314 = 0x00000025;
u32 var80071318 = PAL ? 47 : 45;
u32 var8007131c = 0x0000004b;
u32 var80071320 = 0xffffffff;
u32 var80071324 = 0x00000022;
u32 var80071328 = PAL ? 55 : 52;
u32 var8007132c = 0x0000004b;
u32 var80071330 = 0xffffffff;
u32 var80071334 = 0x0000000c;
u32 var80071338 = 0x0000001e;
u32 var8007133c = 0xffffffff;
u32 var80071340 = PAL ? 63 : 59;
u32 var80071344 = 0x0000000c;
u32 var80071348 = PAL ? 63 : 59;
u32 var8007134c = 0x0000004b;
u32 var80071350 = 0xffffffff;

bool menuTickItemMarquee(struct menuitem *item, union menuitemdata *data)
{
	s32 i;
	s32 textheight;
	s32 textwidth;
	struct fontchar *font1;
	struct font *font2;
	s32 increment;
	u16 sum = 0;
	char *text = menuResolveParam2Text(item);
	s32 limit;

	font2 = g_FontHandelGothicSm;
	font1 = g_CharsHandelGothicSm;

	if (item->param1 & 0x00000200) {
		font2 = g_FontHandelGothicXs;
		font1 = g_CharsHandelGothicXs;
	}

	if (!text) {
		return true;
	}

	i = 0;

	while (text[i] != '\0') {
		sum += text[i];
		i++;
	}

	if (data->marquee.sum != sum) {
		data->marquee.totalmoved = 0;
		data->marquee.sum = sum;
	}

	textMeasure(&textheight, &textwidth, text, font1, font2, 0);
	limit = data->marquee.unk04 + textwidth;
	increment = g_Vars.diffframe60 / 2;

	if (increment <= 0) {
		increment = 1;
	}

	data->marquee.totalmoved += increment;

	if (data->marquee.totalmoved > limit) {
		data->marquee.totalmoved = 0;
	}

	return true;
}

void menuInitItemMarquee(union menuitemdata *data)
{
	data->marquee.totalmoved = 0;
	data->marquee.unk04 = 50;
	data->marquee.unk06 = 0;
}

Gfx *menuRenderItem07(Gfx *gdl)
{
	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *menuRenderItemRanking(Gfx *gdl, struct menurendercontext *context)
{
	struct mpteaminfo info[12];
	s32 numrows;
	u32 textcolour;
	s32 x;
	s32 y;
	u32 linecolour2; // ultimately unused
	s32 textwidth;
	s32 textheight;
	s32 team = false;
	u32 linecolour1;
	struct menuitemdata_ranking *data = &context->data->ranking;
	struct menuframe *frame;
	s32 gap;
	s32 i;

	if (context->item->param2 == 1) {
		team = true;
		numrows = mpGetTeamRankings(info);
	} else {
		numrows = mpGetPlayerRankings(info);
	}

	gdl = func0f153628(gdl);

	// Gap from last item to bottom of dialog + header height
	gap = numrows * 10 - context->height + 18;

	if (gap < 0) {
		gap = 0;
	}

	if (data->scrolloffset > gap) {
		data->scrolloffset = gap;
	}

	if (context->frame->transitiontimer < 0) {
		textcolour = g_MenuColourPalettes[context->frame->type].unfocused;
	} else {
		textcolour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].unfocused,
				g_MenuColourPalettes[context->frame->type].unfocused,
				context->frame->colourweight);
	}

	if (context->frame->dimmed) {
		textcolour = colourBlend(textcolour, 0, 127) & 0xffffff00 | textcolour & 0xff;
	}

	if (!team) {
		// "Deaths"
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_277), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
		x = (context->x - textwidth) + 91;
		y = context->y + 1;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_277), g_CharsHandelGothicXs, g_FontHandelGothicXs,
				textcolour, context->width, context->height, 0, 0);
	}

	// "Score"
	textMeasure(&textheight, &textwidth, langGet(L_MPMENU_278), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = (context->x - textwidth) + 120;
	y = context->y + 1;
	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_278), g_CharsHandelGothicXs, g_FontHandelGothicXs,
			textcolour, context->width, context->height, 0, 0);
	gdl = func0f153780(gdl);

	frame = context->frame;

	if (frame->transitiontimer < 0) {
		linecolour1 = g_MenuColourPalettes[frame->type].unk00;
	} else {
		linecolour1 = colourBlend(
				g_MenuColourPalettes[frame->type2].unk00,
				g_MenuColourPalettes[frame->type].unk00,
				frame->colourweight);
	}

	if (frame->dimmed) {
		linecolour1 = colourBlend(linecolour1, 0, 44) & 0xffffff00 | linecolour1 & 0xff;
	}

	if (frame->transitiontimer < 0) {
		linecolour2 = g_MenuColourPalettes[frame->type].unk08;
	} else {
		linecolour2 = colourBlend(
				g_MenuColourPalettes[frame->type2].unk08,
				g_MenuColourPalettes[frame->type].unk08,
				frame->colourweight);
	}

	if (frame->dimmed) {
		linecolour2 = colourBlend(linecolour2, 0, 44) & 0xffffff00 | linecolour2 & 0xff;
	}

	linecolour1 = func0f153e94(context->x, context->y + 2, -129) & 0xff | linecolour1 & 0xffffff00;
	linecolour2 = func0f153e94(context->x + context->width, context->y + 2, -129) & 0xff | linecolour2 & 0xffffff00;

	// Horizontal line between header and body
	gdl = renderFilledRect(gdl,
			context->x, context->y + 9,
			context->x + context->width, context->y + 10,
			linecolour1, linecolour1);

	gDPPipeSync(gdl++);

	g_ScissorX1 = context->x * g_ScaleX;
	g_ScissorX2 = (context->x + context->width) * g_ScaleX;
	g_ScissorY1 = context->y + 10;
	g_ScissorY2 = context->y + context->height - 1;

	if (g_ScissorX1 < 0) {
		g_ScissorX1 = 0;
	}

	if (g_ScissorX2 < 0) {
		g_ScissorX2 = 0;
	}

	if (g_ScissorY1 < 0) {
		g_ScissorY1 = 0;
	}

	if (g_ScissorY2 < 0) {
		g_ScissorY2 = 0;
	}

	if (g_ScissorX1 > viGetBufX()) {
		g_ScissorX1 = viGetBufX();
	}

	if (g_ScissorX2 > viGetBufX()) {
		g_ScissorX2 = viGetBufX();
	}

	if (g_ScissorY1 > viGetBufY()) {
		g_ScissorY1 = viGetBufY();
	}

	if (g_ScissorY2 > viGetBufY()) {
		g_ScissorY2 = viGetBufY();
	}

	if (g_ScissorX2 < g_ScissorX1) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY2 < g_ScissorY1) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);

	gdl = func0f153628(gdl);

	for (i = 0; i < numrows; i++) {
		struct mpteaminfo *thisinfo = &info[i];
		u32 weight = 0;
		char valuebuffer[8];

		if (numrows >= 2) {
			weight = i / (f32)(numrows - 1) * 255;
		}

		textcolour = colourBlend(0x008888ff, 0x00ffffff, weight);
		x = context->x + 5;
		y = context->y + i * 10 - data->scrolloffset + 14;

		if (team) {
			gdl = textRenderProjected(gdl, &x, &y, g_BossFile.teamnames[thisinfo->teamnum],
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		} else {
			gdl = textRenderProjected(gdl, &x, &y, thisinfo->mpchr->name,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		}

		if (!team) {
			// Deaths value (red)
			textcolour = colourBlend(0xcf0000ff, 0xff4040ff, weight);
			sprintf(valuebuffer, "%d\n", thisinfo->mpchr->numdeaths);
			textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			x = context->x - textwidth + 91;
			y = context->y + i * 10 - data->scrolloffset + 14;
			gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
					textcolour, context->width, context->height, 0, 0);
		}

		// Score value (green)
		textcolour = colourBlend(0x009f00ff, 0x00ff00ff, weight);
		sprintf(valuebuffer, "%d\n", thisinfo->score);
		textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = context->x - textwidth + 120;
		y = context->y + i * 10 - data->scrolloffset + 14;
		gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				textcolour, context->width, context->height, 0, 0);
	}

	return func0f153780(gdl);
}
#else
const char var7f1ac174nb[] = "%d\n";
const char var7f1ac178nb[] = "%d\n";
const char var7f1ac17cnb[] = "%d\n";
const char var7f1ac180nb[] = "%d\n";
const char var7f1ac184nb[] = "%d\n";

GLOBAL_ASM(
glabel menuRenderItemRanking
/*  f0eab98:	27bdfe50 */ 	addiu	$sp,$sp,-432
/*  f0eab9c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0eaba0:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0eaba4:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0eaba8:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0eabac:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0eabb0:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0eabb4:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0eabb8:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0eabbc:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0eabc0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0eabc4:	afa401b0 */ 	sw	$a0,0x1b0($sp)
/*  f0eabc8:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f0eabcc:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0eabd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0eabd4:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0eabd8:	afae0098 */ 	sw	$t6,0x98($sp)
/*  f0eabdc:	8caf0008 */ 	lw	$t7,0x8($a1)
/*  f0eabe0:	8df80008 */ 	lw	$t8,0x8($t7)
/*  f0eabe4:	17010006 */ 	bne	$t8,$at,.NB0f0eac00
/*  f0eabe8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0eabec:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0eabf0:	0fc60b9d */ 	jal	mpGetTeamRankings
/*  f0eabf4:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eabf8:	10000004 */ 	beqz	$zero,.NB0f0eac0c
/*  f0eabfc:	afa200bc */ 	sw	$v0,0xbc($sp)
.NB0f0eac00:
/*  f0eac00:	0fc60a7a */ 	jal	mpGetPlayerRankings
/*  f0eac04:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eac08:	afa200bc */ 	sw	$v0,0xbc($sp)
.NB0f0eac0c:
/*  f0eac0c:	0fc5374a */ 	jal	func0f153628
/*  f0eac10:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eac14:	8fa800bc */ 	lw	$t0,0xbc($sp)
/*  f0eac18:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0eac1c:	86ca0006 */ 	lh	$t2,0x6($s6)
/*  f0eac20:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0eac24:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0eac28:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0eac2c:	012a1823 */ 	subu	$v1,$t1,$t2
/*  f0eac30:	24630012 */ 	addiu	$v1,$v1,0x12
/*  f0eac34:	04610002 */ 	bgez	$v1,.NB0f0eac40
/*  f0eac38:	8fab0098 */ 	lw	$t3,0x98($sp)
/*  f0eac3c:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0eac40:
/*  f0eac40:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f0eac44:	006c082a */ 	slt	$at,$v1,$t4
/*  f0eac48:	50200003 */ 	beqzl	$at,.NB0f0eac58
/*  f0eac4c:	8ed10010 */ 	lw	$s1,0x10($s6)
/*  f0eac50:	a5630000 */ 	sh	$v1,0x0($t3)
/*  f0eac54:	8ed10010 */ 	lw	$s1,0x10($s6)
.NB0f0eac58:
/*  f0eac58:	44803000 */ 	mtc1	$zero,$f6
/*  f0eac5c:	c6240040 */ 	lwc1	$f4,0x40($s1)
/*  f0eac60:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0eac64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eac68:	4502000b */ 	bc1fl	.NB0f0eac98
/*  f0eac6c:	9238003d */ 	lbu	$t8,0x3d($s1)
/*  f0eac70:	922d003c */ 	lbu	$t5,0x3c($s1)
/*  f0eac74:	2414003c */ 	addiu	$s4,$zero,0x3c
/*  f0eac78:	3c137f1b */ 	lui	$s3,0x7f1b
/*  f0eac7c:	01b40019 */ 	multu	$t5,$s4
/*  f0eac80:	2673c2e0 */ 	addiu	$s3,$s3,-15648
/*  f0eac84:	00007012 */ 	mflo	$t6
/*  f0eac88:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0eac8c:	10000012 */ 	beqz	$zero,.NB0f0eacd8
/*  f0eac90:	8df00018 */ 	lw	$s0,0x18($t7)
/*  f0eac94:	9238003d */ 	lbu	$t8,0x3d($s1)
.NB0f0eac98:
/*  f0eac98:	2414003c */ 	addiu	$s4,$zero,0x3c
/*  f0eac9c:	9229003c */ 	lbu	$t1,0x3c($s1)
/*  f0eaca0:	03140019 */ 	multu	$t8,$s4
/*  f0eaca4:	3c137f1b */ 	lui	$s3,0x7f1b
/*  f0eaca8:	2673c2e0 */ 	addiu	$s3,$s3,-15648
/*  f0eacac:	8e260044 */ 	lw	$a2,0x44($s1)
/*  f0eacb0:	0000c812 */ 	mflo	$t9
/*  f0eacb4:	02794021 */ 	addu	$t0,$s3,$t9
/*  f0eacb8:	8d040018 */ 	lw	$a0,0x18($t0)
/*  f0eacbc:	01340019 */ 	multu	$t1,$s4
/*  f0eacc0:	00005012 */ 	mflo	$t2
/*  f0eacc4:	026a6021 */ 	addu	$t4,$s3,$t2
/*  f0eacc8:	0fc01990 */ 	jal	colourBlend
/*  f0eaccc:	8d850018 */ 	lw	$a1,0x18($t4)
/*  f0eacd0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eacd4:	8ed10010 */ 	lw	$s1,0x10($s6)
.NB0f0eacd8:
/*  f0eacd8:	8e2b000c */ 	lw	$t3,0xc($s1)
/*  f0eacdc:	11600008 */ 	beqz	$t3,.NB0f0ead00
/*  f0eace0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eace4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eace8:	0fc01990 */ 	jal	colourBlend
/*  f0eacec:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eacf0:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0eacf4:	00556824 */ 	and	$t5,$v0,$s5
/*  f0eacf8:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0eacfc:	01ae8025 */ 	or	$s0,$t5,$t6
.NB0f0ead00:
/*  f0ead00:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ead04:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0ead08:	15e0002a */ 	bnez	$t7,.NB0f0eadb4
/*  f0ead0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ead10:	0fc5a4dd */ 	jal	langGet
/*  f0ead14:	24045115 */ 	addiu	$a0,$zero,0x5115
/*  f0ead18:	3c128008 */ 	lui	$s2,0x8008
/*  f0ead1c:	26522364 */ 	addiu	$s2,$s2,0x2364
/*  f0ead20:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0ead24:	3c118008 */ 	lui	$s1,0x8008
/*  f0ead28:	26312368 */ 	addiu	$s1,$s1,0x2368
/*  f0ead2c:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0ead30:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0ead34:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0ead38:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ead3c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ead40:	0fc54655 */ 	jal	textMeasure
/*  f0ead44:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ead48:	86d90000 */ 	lh	$t9,0x0($s6)
/*  f0ead4c:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*  f0ead50:	24045115 */ 	addiu	$a0,$zero,0x5115
/*  f0ead54:	03284823 */ 	subu	$t1,$t9,$t0
/*  f0ead58:	252a005b */ 	addiu	$t2,$t1,0x5b
/*  f0ead5c:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0ead60:	86cc0002 */ 	lh	$t4,0x2($s6)
/*  f0ead64:	258b0001 */ 	addiu	$t3,$t4,0x1
/*  f0ead68:	0fc5a4dd */ 	jal	langGet
/*  f0ead6c:	afab00b0 */ 	sw	$t3,0xb0($sp)
/*  f0ead70:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0ead74:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f0ead78:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead7c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ead80:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ead84:	86cf0004 */ 	lh	$t7,0x4($s6)
/*  f0ead88:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0ead8c:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0ead90:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0ead94:	86d80006 */ 	lh	$t8,0x6($s6)
/*  f0ead98:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ead9c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eada0:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eada4:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eada8:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eadac:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0eadb0:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0eadb4:
/*  f0eadb4:	3c118008 */ 	lui	$s1,0x8008
/*  f0eadb8:	3c128008 */ 	lui	$s2,0x8008
/*  f0eadbc:	26522364 */ 	addiu	$s2,$s2,0x2364
/*  f0eadc0:	26312368 */ 	addiu	$s1,$s1,0x2368
/*  f0eadc4:	0fc5a4dd */ 	jal	langGet
/*  f0eadc8:	24045116 */ 	addiu	$a0,$zero,0x5116
/*  f0eadcc:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0eadd0:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0eadd4:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0eadd8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eaddc:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0eade0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eade4:	0fc54655 */ 	jal	textMeasure
/*  f0eade8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eadec:	86c80000 */ 	lh	$t0,0x0($s6)
/*  f0eadf0:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0eadf4:	24045116 */ 	addiu	$a0,$zero,0x5116
/*  f0eadf8:	01095023 */ 	subu	$t2,$t0,$t1
/*  f0eadfc:	254c0078 */ 	addiu	$t4,$t2,0x78
/*  f0eae00:	afac00b4 */ 	sw	$t4,0xb4($sp)
/*  f0eae04:	86cb0002 */ 	lh	$t3,0x2($s6)
/*  f0eae08:	256d0001 */ 	addiu	$t5,$t3,0x1
/*  f0eae0c:	0fc5a4dd */ 	jal	langGet
/*  f0eae10:	afad00b0 */ 	sw	$t5,0xb0($sp)
/*  f0eae14:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0eae18:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f0eae1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eae20:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eae24:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eae28:	86d80004 */ 	lh	$t8,0x4($s6)
/*  f0eae2c:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eae30:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0eae34:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0eae38:	86d90006 */ 	lh	$t9,0x6($s6)
/*  f0eae3c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eae40:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eae44:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eae48:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eae4c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eae50:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0eae54:	0fc537a0 */ 	jal	func0f153780
/*  f0eae58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eae5c:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0eae60:	8ed00010 */ 	lw	$s0,0x10($s6)
/*  f0eae64:	44805000 */ 	mtc1	$zero,$f10
/*  f0eae68:	c6080040 */ 	lwc1	$f8,0x40($s0)
/*  f0eae6c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0eae70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eae74:	45020008 */ 	bc1fl	.NB0f0eae98
/*  f0eae78:	920c003d */ 	lbu	$t4,0x3d($s0)
/*  f0eae7c:	9208003c */ 	lbu	$t0,0x3c($s0)
/*  f0eae80:	01140019 */ 	multu	$t0,$s4
/*  f0eae84:	00004812 */ 	mflo	$t1
/*  f0eae88:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0eae8c:	1000000e */ 	beqz	$zero,.NB0f0eaec8
/*  f0eae90:	8d520000 */ 	lw	$s2,0x0($t2)
/*  f0eae94:	920c003d */ 	lbu	$t4,0x3d($s0)
.NB0f0eae98:
/*  f0eae98:	920e003c */ 	lbu	$t6,0x3c($s0)
/*  f0eae9c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eaea0:	01940019 */ 	multu	$t4,$s4
/*  f0eaea4:	00005812 */ 	mflo	$t3
/*  f0eaea8:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0eaeac:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0eaeb0:	01d40019 */ 	multu	$t6,$s4
/*  f0eaeb4:	00007812 */ 	mflo	$t7
/*  f0eaeb8:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f0eaebc:	0fc01990 */ 	jal	colourBlend
/*  f0eaec0:	8f050000 */ 	lw	$a1,0x0($t8)
/*  f0eaec4:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0eaec8:
/*  f0eaec8:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0eaecc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0eaed0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eaed4:	53200007 */ 	beqzl	$t9,.NB0f0eaef4
/*  f0eaed8:	c6100040 */ 	lwc1	$f16,0x40($s0)
/*  f0eaedc:	0fc01990 */ 	jal	colourBlend
/*  f0eaee0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0eaee4:	00554024 */ 	and	$t0,$v0,$s5
/*  f0eaee8:	324900ff */ 	andi	$t1,$s2,0xff
/*  f0eaeec:	01099025 */ 	or	$s2,$t0,$t1
/*  f0eaef0:	c6100040 */ 	lwc1	$f16,0x40($s0)
.NB0f0eaef4:
/*  f0eaef4:	44809000 */ 	mtc1	$zero,$f18
/*  f0eaef8:	920a003c */ 	lbu	$t2,0x3c($s0)
/*  f0eaefc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0eaf00:	000a6100 */ 	sll	$t4,$t2,0x4
/*  f0eaf04:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0eaf08:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eaf0c:	45000004 */ 	bc1f	.NB0f0eaf20
/*  f0eaf10:	026c1021 */ 	addu	$v0,$s3,$t4
/*  f0eaf14:	8c510008 */ 	lw	$s1,0x8($v0)
/*  f0eaf18:	1000000b */ 	beqz	$zero,.NB0f0eaf48
/*  f0eaf1c:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f0eaf20:
/*  f0eaf20:	920b003d */ 	lbu	$t3,0x3d($s0)
/*  f0eaf24:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f0eaf28:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eaf2c:	01740019 */ 	multu	$t3,$s4
/*  f0eaf30:	00006812 */ 	mflo	$t5
/*  f0eaf34:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f0eaf38:	0fc01990 */ 	jal	colourBlend
/*  f0eaf3c:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f0eaf40:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eaf44:	8e03000c */ 	lw	$v1,0xc($s0)
.NB0f0eaf48:
/*  f0eaf48:	10600004 */ 	beqz	$v1,.NB0f0eaf5c
/*  f0eaf4c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eaf50:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eaf54:	0fc01990 */ 	jal	colourBlend
/*  f0eaf58:	2406002c */ 	addiu	$a2,$zero,0x2c
.NB0f0eaf5c:
/*  f0eaf5c:	86c50002 */ 	lh	$a1,0x2($s6)
/*  f0eaf60:	86c40000 */ 	lh	$a0,0x0($s6)
/*  f0eaf64:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0eaf68:	0fc5393c */ 	jal	func0f153e94
/*  f0eaf6c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eaf70:	86c90000 */ 	lh	$t1,0x0($s6)
/*  f0eaf74:	86ca0004 */ 	lh	$t2,0x4($s6)
/*  f0eaf78:	86c50002 */ 	lh	$a1,0x2($s6)
/*  f0eaf7c:	305900ff */ 	andi	$t9,$v0,0xff
/*  f0eaf80:	02554024 */ 	and	$t0,$s2,$s5
/*  f0eaf84:	03289025 */ 	or	$s2,$t9,$t0
/*  f0eaf88:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0eaf8c:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f0eaf90:	0fc5393c */ 	jal	func0f153e94
/*  f0eaf94:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eaf98:	86c30002 */ 	lh	$v1,0x2($s6)
/*  f0eaf9c:	86c50000 */ 	lh	$a1,0x0($s6)
/*  f0eafa0:	86cc0004 */ 	lh	$t4,0x4($s6)
/*  f0eafa4:	246b000a */ 	addiu	$t3,$v1,0xa
/*  f0eafa8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eafac:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0eafb0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0eafb4:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eafb8:	24660009 */ 	addiu	$a2,$v1,0x9
/*  f0eafbc:	0fc380fc */ 	jal	renderFilledRect
/*  f0eafc0:	00ac3821 */ 	addu	$a3,$a1,$t4
/*  f0eafc4:	3c0de700 */ 	lui	$t5,0xe700
/*  f0eafc8:	3c038008 */ 	lui	$v1,0x8008
/*  f0eafcc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0eafd0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0eafd4:	24632320 */ 	addiu	$v1,$v1,0x2320
/*  f0eafd8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0eafdc:	86ce0000 */ 	lh	$t6,0x0($s6)
/*  f0eafe0:	86cb0002 */ 	lh	$t3,0x2($s6)
/*  f0eafe4:	3c014080 */ 	lui	$at,0x4080
/*  f0eafe8:	01cf0019 */ 	multu	$t6,$t7
/*  f0eafec:	256d000a */ 	addiu	$t5,$t3,0xa
/*  f0eaff0:	448d8000 */ 	mtc1	$t5,$f16
/*  f0eaff4:	44810000 */ 	mtc1	$at,$f0
/*  f0eaff8:	3c01ed00 */ 	lui	$at,0xed00
/*  f0eaffc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0eb000:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0eb004:	0000c012 */ 	mflo	$t8
/*  f0eb008:	44982000 */ 	mtc1	$t8,$f4
/*  f0eb00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb010:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0eb014:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0eb018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb01c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0eb020:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0eb024:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0eb028:	44085000 */ 	mfc1	$t0,$f10
/*  f0eb02c:	440f3000 */ 	mfc1	$t7,$f6
/*  f0eb030:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f0eb034:	00095300 */ 	sll	$t2,$t1,0xc
/*  f0eb038:	01416025 */ 	or	$t4,$t2,$at
/*  f0eb03c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f0eb040:	0198c825 */ 	or	$t9,$t4,$t8
/*  f0eb044:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f0eb048:	86c90004 */ 	lh	$t1,0x4($s6)
/*  f0eb04c:	86c80000 */ 	lh	$t0,0x0($s6)
/*  f0eb050:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0eb054:	86d90002 */ 	lh	$t9,0x2($s6)
/*  f0eb058:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0eb05c:	014b0019 */ 	multu	$t2,$t3
/*  f0eb060:	86c80006 */ 	lh	$t0,0x6($s6)
/*  f0eb064:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0eb068:	252affff */ 	addiu	$t2,$t1,-1
/*  f0eb06c:	448a2000 */ 	mtc1	$t2,$f4
/*  f0eb070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb074:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0eb078:	00006812 */ 	mflo	$t5
/*  f0eb07c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0eb080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb084:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0eb088:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0eb08c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb090:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0eb094:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0eb098:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0eb09c:	440f9000 */ 	mfc1	$t7,$f18
/*  f0eb0a0:	440d5000 */ 	mfc1	$t5,$f10
/*  f0eb0a4:	31ec0fff */ 	andi	$t4,$t7,0xfff
/*  f0eb0a8:	000cc300 */ 	sll	$t8,$t4,0xc
/*  f0eb0ac:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0eb0b0:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0eb0b4:	0fc5374a */ 	jal	func0f153628
/*  f0eb0b8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0eb0bc:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f0eb0c0:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0eb0c4:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0eb0c8:	186000dd */ 	blez	$v1,.NB0f0eb440
/*  f0eb0cc:	27b100c0 */ 	addiu	$s1,$sp,0xc0
/*  f0eb0d0:	3c148008 */ 	lui	$s4,0x8008
/*  f0eb0d4:	3c138008 */ 	lui	$s3,0x8008
/*  f0eb0d8:	26732370 */ 	addiu	$s3,$s3,0x2370
/*  f0eb0dc:	2694236c */ 	addiu	$s4,$s4,0x236c
/*  f0eb0e0:	0000b825 */ 	or	$s7,$zero,$zero
/*  f0eb0e4:	27b50074 */ 	addiu	$s5,$sp,0x74
.NB0f0eb0e8:
/*  f0eb0e8:	8fa300bc */ 	lw	$v1,0xbc($sp)
/*  f0eb0ec:	3c040088 */ 	lui	$a0,0x88
/*  f0eb0f0:	00009025 */ 	or	$s2,$zero,$zero
/*  f0eb0f4:	28610002 */ 	slti	$at,$v1,0x2
/*  f0eb0f8:	1420002d */ 	bnez	$at,.NB0f0eb1b0
/*  f0eb0fc:	348488ff */ 	ori	$a0,$a0,0x88ff
/*  f0eb100:	246cffff */ 	addiu	$t4,$v1,-1
/*  f0eb104:	448c2000 */ 	mtc1	$t4,$f4
/*  f0eb108:	449e8000 */ 	mtc1	$s8,$f16
/*  f0eb10c:	3c01437f */ 	lui	$at,0x437f
/*  f0eb110:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0eb114:	44815000 */ 	mtc1	$at,$f10
/*  f0eb118:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0eb11c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb120:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0eb124:	46069203 */ 	div.s	$f8,$f18,$f6
/*  f0eb128:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0eb12c:	4459f800 */ 	cfc1	$t9,$31
/*  f0eb130:	44d2f800 */ 	ctc1	$s2,$31
/*  f0eb134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb138:	46008124 */ 	cvt.w.s	$f4,$f16
/*  f0eb13c:	4452f800 */ 	cfc1	$s2,$31
/*  f0eb140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb144:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0eb148:	52400013 */ 	beqzl	$s2,.NB0f0eb198
/*  f0eb14c:	44122000 */ 	mfc1	$s2,$f4
/*  f0eb150:	44812000 */ 	mtc1	$at,$f4
/*  f0eb154:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0eb158:	46048101 */ 	sub.s	$f4,$f16,$f4
/*  f0eb15c:	44d2f800 */ 	ctc1	$s2,$31
/*  f0eb160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb164:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0eb168:	4452f800 */ 	cfc1	$s2,$31
/*  f0eb16c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb170:	32520078 */ 	andi	$s2,$s2,0x78
/*  f0eb174:	16400005 */ 	bnez	$s2,.NB0f0eb18c
/*  f0eb178:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb17c:	44122000 */ 	mfc1	$s2,$f4
/*  f0eb180:	3c018000 */ 	lui	$at,0x8000
/*  f0eb184:	10000007 */ 	beqz	$zero,.NB0f0eb1a4
/*  f0eb188:	02419025 */ 	or	$s2,$s2,$at
.NB0f0eb18c:
/*  f0eb18c:	10000005 */ 	beqz	$zero,.NB0f0eb1a4
/*  f0eb190:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0eb194:	44122000 */ 	mfc1	$s2,$f4
.NB0f0eb198:
/*  f0eb198:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb19c:	0640fffb */ 	bltz	$s2,.NB0f0eb18c
/*  f0eb1a0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0eb1a4:
/*  f0eb1a4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0eb1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb1ac:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0eb1b0:
/*  f0eb1b0:	3c0500ff */ 	lui	$a1,0xff
/*  f0eb1b4:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f0eb1b8:	0fc01990 */ 	jal	colourBlend
/*  f0eb1bc:	02403025 */ 	or	$a2,$s2,$zero
/*  f0eb1c0:	86c80000 */ 	lh	$t0,0x0($s6)
/*  f0eb1c4:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0eb1c8:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0eb1cc:	25090005 */ 	addiu	$t1,$t0,0x5
/*  f0eb1d0:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0eb1d4:	86ca0002 */ 	lh	$t2,0x2($s6)
/*  f0eb1d8:	85b80000 */ 	lh	$t8,0x0($t5)
/*  f0eb1dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb1e0:	01575821 */ 	addu	$t3,$t2,$s7
/*  f0eb1e4:	01787023 */ 	subu	$t6,$t3,$t8
/*  f0eb1e8:	25cf000e */ 	addiu	$t7,$t6,0xe
/*  f0eb1ec:	11800019 */ 	beqz	$t4,.NB0f0eb254
/*  f0eb1f0:	afaf00b0 */ 	sw	$t7,0xb0($sp)
/*  f0eb1f4:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0eb1f8:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f0eb1fc:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0eb200:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0eb204:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eb208:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0eb20c:	86cb0004 */ 	lh	$t3,0x4($s6)
/*  f0eb210:	00194080 */ 	sll	$t0,$t9,0x2
/*  f0eb214:	3c09800b */ 	lui	$t1,0x800b
/*  f0eb218:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0eb21c:	86d80006 */ 	lh	$t8,0x6($s6)
/*  f0eb220:	01194023 */ 	subu	$t0,$t0,$t9
/*  f0eb224:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0eb228:	25291460 */ 	addiu	$t1,$t1,0x1460
/*  f0eb22c:	01093821 */ 	addu	$a3,$t0,$t1
/*  f0eb230:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb234:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb238:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eb23c:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0eb240:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eb244:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb248:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0eb24c:	10000012 */ 	beqz	$zero,.NB0f0eb298
/*  f0eb250:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0eb254:
/*  f0eb254:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0eb258:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0eb25c:	8e270000 */ 	lw	$a3,0x0($s1)
/*  f0eb260:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eb264:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eb268:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eb26c:	86cc0004 */ 	lh	$t4,0x4($s6)
/*  f0eb270:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eb274:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0eb278:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0eb27c:	86d90006 */ 	lh	$t9,0x6($s6)
/*  f0eb280:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb284:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb288:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eb28c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb290:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0eb294:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0eb298:
/*  f0eb298:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*  f0eb29c:	3c04cf00 */ 	lui	$a0,0xcf00
/*  f0eb2a0:	348400ff */ 	ori	$a0,$a0,0xff
/*  f0eb2a4:	15000030 */ 	bnez	$t0,.NB0f0eb368
/*  f0eb2a8:	3c05ff40 */ 	lui	$a1,0xff40
/*  f0eb2ac:	34a540ff */ 	ori	$a1,$a1,0x40ff
/*  f0eb2b0:	0fc01990 */ 	jal	colourBlend
/*  f0eb2b4:	02403025 */ 	or	$a2,$s2,$zero
/*  f0eb2b8:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0eb2bc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0eb2c0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb2c4:	24a5c174 */ 	addiu	$a1,$a1,-16012
/*  f0eb2c8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0eb2cc:	0c004fc1 */ 	jal	sprintf
/*  f0eb2d0:	8526003c */ 	lh	$a2,0x3c($t1)
/*  f0eb2d4:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f0eb2d8:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0eb2dc:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0eb2e0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0eb2e4:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f0eb2e8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb2ec:	0fc54655 */ 	jal	textMeasure
/*  f0eb2f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eb2f4:	86cd0000 */ 	lh	$t5,0x0($s6)
/*  f0eb2f8:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f0eb2fc:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f0eb300:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eb304:	01abc023 */ 	subu	$t8,$t5,$t3
/*  f0eb308:	270e005b */ 	addiu	$t6,$t8,0x5b
/*  f0eb30c:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f0eb310:	86cf0002 */ 	lh	$t7,0x2($s6)
/*  f0eb314:	87280000 */ 	lh	$t0,0x0($t9)
/*  f0eb318:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f0eb31c:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0eb320:	01f76021 */ 	addu	$t4,$t7,$s7
/*  f0eb324:	01884823 */ 	subu	$t1,$t4,$t0
/*  f0eb328:	252a000e */ 	addiu	$t2,$t1,0xe
/*  f0eb32c:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f0eb330:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eb334:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eb338:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eb33c:	86d80004 */ 	lh	$t8,0x4($s6)
/*  f0eb340:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0eb344:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eb348:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0eb34c:	86ce0006 */ 	lh	$t6,0x6($s6)
/*  f0eb350:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb354:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb358:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0eb35c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb360:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0eb364:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0eb368:
/*  f0eb368:	3c04009f */ 	lui	$a0,0x9f
/*  f0eb36c:	3c0500ff */ 	lui	$a1,0xff
/*  f0eb370:	34a500ff */ 	ori	$a1,$a1,0xff
/*  f0eb374:	348400ff */ 	ori	$a0,$a0,0xff
/*  f0eb378:	0fc01990 */ 	jal	colourBlend
/*  f0eb37c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0eb380:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0eb384:	00408025 */ 	or	$s0,$v0,$zero
/*  f0eb388:	24a5c178 */ 	addiu	$a1,$a1,-16008
/*  f0eb38c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0eb390:	0c004fc1 */ 	jal	sprintf
/*  f0eb394:	8e260010 */ 	lw	$a2,0x10($s1)
/*  f0eb398:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0eb39c:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0eb3a0:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f0eb3a4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0eb3a8:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f0eb3ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb3b0:	0fc54655 */ 	jal	textMeasure
/*  f0eb3b4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eb3b8:	86d90000 */ 	lh	$t9,0x0($s6)
/*  f0eb3bc:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*  f0eb3c0:	8fab0098 */ 	lw	$t3,0x98($sp)
/*  f0eb3c4:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eb3c8:	032c4023 */ 	subu	$t0,$t9,$t4
/*  f0eb3cc:	25090078 */ 	addiu	$t1,$t0,0x78
/*  f0eb3d0:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0eb3d4:	86ca0002 */ 	lh	$t2,0x2($s6)
/*  f0eb3d8:	85780000 */ 	lh	$t8,0x0($t3)
/*  f0eb3dc:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0eb3e0:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0eb3e4:	01576821 */ 	addu	$t5,$t2,$s7
/*  f0eb3e8:	01b87023 */ 	subu	$t6,$t5,$t8
/*  f0eb3ec:	25cf000e */ 	addiu	$t7,$t6,0xe
/*  f0eb3f0:	afaf00b0 */ 	sw	$t7,0xb0($sp)
/*  f0eb3f4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eb3f8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0eb3fc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eb400:	86c80004 */ 	lh	$t0,0x4($s6)
/*  f0eb404:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0eb408:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0eb40c:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0eb410:	86c90006 */ 	lh	$t1,0x6($s6)
/*  f0eb414:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb418:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb41c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0eb420:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb424:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0eb428:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0eb42c:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f0eb430:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0eb434:	26f7000a */ 	addiu	$s7,$s7,0xa
/*  f0eb438:	17caff2b */ 	bne	$s8,$t2,.NB0f0eb0e8
/*  f0eb43c:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0eb440:
/*  f0eb440:	0fc537a0 */ 	jal	func0f153780
/*  f0eb444:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0eb448:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0eb44c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0eb450:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0eb454:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0eb458:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0eb45c:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0eb460:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0eb464:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0eb468:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0eb46c:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0eb470:	03e00008 */ 	jr	$ra
/*  f0eb474:	27bd01b0 */ 	addiu	$sp,$sp,0x1b0
);
#endif

bool menuTickItemRanking(struct menuinputs *inputs, u32 arg1, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if (arg1 & 2) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_FINAL
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_FINAL
		intval = intval + (s32)(((f32)inputs->unk09 + (f32)inputs->unk09) * g_Vars.diffframe60freal);
#else
		intval += inputs->unk09 * 2 * g_Vars.diffframe60;
#endif
		data->ranking.scrolloffset += intval;

		if (data->ranking.scrolloffset < 0) {
			data->ranking.scrolloffset = 0;
		}
	}

	return true;
}

void menuInitItemRanking(union menuitemdata *data)
{
	data->ranking.scrolloffset = 0;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *menuRenderItemPlayerStats(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_dropdown *data = &context->data->dropdown;
	s32 x;
	s32 y;
	u32 maincolour;
	s32 playernum = g_MpSelectedPlayersForStats[g_MpPlayerNum];
	struct mpchr *mpchr;
	u32 selectioncolour;
	s32 textheight;
	s32 textwidth;
	s32 numchrs = mpGetNumChrs();
	char buffer[12];
	s32 i;
	u32 weight;
	s32 gap;
	s32 ypos = 0;

	if (playernum < 4) {
		mpchr = &g_MpPlayers[playernum].base;
	} else {
		mpchr = &g_MpSimulants[playernum - 4].base;
	}

	gdl = func0f153628(gdl);

	// Write selected player's name
	weight = func0f006b08(40) * 255;

	if (context->frame->transitiontimer < 0) {
		selectioncolour = g_MenuColourPalettes[context->frame->type].focused;
	} else {
		selectioncolour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].focused,
				g_MenuColourPalettes[context->frame->type].focused,
				context->frame->colourweight);
	}

	selectioncolour = colourBlend(colourBlend(0xffffffff, 0x000000ff, 127), selectioncolour, weight);
	x = context->x + 2;
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, mpchr->name, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			selectioncolour, context->width, context->height, 0, 0);

	// "Suicides" heading
	if (context->frame->transitiontimer < 0) {
		maincolour = g_MenuColourPalettes[context->frame->type].unfocused;
	} else {
		maincolour = colourBlend(
				g_MenuColourPalettes[context->frame->type2].unfocused,
				g_MenuColourPalettes[context->frame->type].unfocused,
				context->frame->colourweight);
	}

	if (context->frame->dimmed) {
		maincolour = colourBlend(maincolour, 0x00000000, 127) & 0xffffff00 | maincolour & 0xff;
	}

	textMeasure(&textheight, &textwidth, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = context->x - textwidth + 121;
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs,
			maincolour, context->width, context->height, 0, 0);

	// Num suicides
	x = context->x - textwidth + 119;
	sprintf(buffer, "%d\n", mpchr->killcounts[playernum]);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
	x -= textwidth;
	y = context->y + 1;
	gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0xffff00ff, context->width, context->height, 0, 0);

	// Move ypos past top row
	ypos += 12;

	if (mpGetNumChrs() >= 2) {
		if (context->frame->transitiontimer < 0) {
			maincolour = g_MenuColourPalettes[context->frame->type].unfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->frame->type2].unfocused,
					g_MenuColourPalettes[context->frame->type].unfocused,
					context->frame->colourweight);
		}

		if (context->frame->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		// "Deaths" heading
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_282), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
		x = context->x - textwidth + 120;
		y = context->y + ypos;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_282), g_CharsHandelGothicXs, g_FontHandelGothicXs,
				maincolour, context->width, context->height, 0, 0);

		// "Kills" heading
		textMeasure(&textheight, &textwidth, langGet(L_MPMENU_283), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
		x = context->x - textwidth + 25;
		y = context->y + ypos;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_283),  g_CharsHandelGothicXs, g_FontHandelGothicXs,
				maincolour, context->width, context->height, 0, 0);

		// Move ypos past heading row
		ypos += 7;

		// Prepare scissor for table
		gap = numchrs * 10 - context->height + ypos;
		gap -= 10;

		if (gap < 0) {
			gap = 0;
		}

		if (data->scrolloffset > gap) {
			data->scrolloffset = gap;
		}

		gDPPipeSync(gdl++);

		g_ScissorX1 = context->x * g_ScaleX;
		g_ScissorX2 = (context->x + context->width) * g_ScaleX;
		g_ScissorY1 = context->y + ypos;
		g_ScissorY2 = context->y + context->height;

		if (g_ScissorX1 < 0) {
			g_ScissorX1 = 0;
		}

		if (g_ScissorX2 < 0) {
			g_ScissorX2 = 0;
		}

		if (g_ScissorY1 < 0) {
			g_ScissorY1 = 0;
		}

		if (g_ScissorY2 < 0) {
			g_ScissorY2 = 0;
		}

		if (g_ScissorX1 > viGetBufX()) {
			g_ScissorX1 = viGetBufX();
		}

		if (g_ScissorX2 > viGetBufX()) {
			g_ScissorX2 = viGetBufX();
		}

		if (g_ScissorY1 > viGetBufY()) {
			g_ScissorY1 = viGetBufY();
		}

		if (g_ScissorY2 > viGetBufY()) {
			g_ScissorY2 = viGetBufY();
		}

		if (g_ScissorX2 < g_ScissorX1) {
			g_ScissorX2 = g_ScissorX1;
		}

		if (g_ScissorY2 < g_ScissorY1) {
			g_ScissorY2 = g_ScissorY1;
		}

		gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);

		ypos -= data->scrolloffset;

		for (i = 0; i < 12; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchr *loopmpchr;

				if (i < 4) {
					loopmpchr = &g_MpPlayers[i].base;
				} else {
					loopmpchr = &g_MpSimulants[i - 4].base;
				}

				if (i != playernum) {
					// Name
					x = context->x + 29;
					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, loopmpchr->name, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0x00ffffff, context->width, context->height, 0, 0);

					// Num deaths
					sprintf(buffer, "%d\n", loopmpchr->killcounts[playernum]);
					textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
					x = context->x - textwidth + 120;
					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0xff4040ff, context->width, context->height, 0, 0);

					// Num kills
					sprintf(buffer, "%d\n", mpchr->killcounts[i]);
					textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
					x = context->x - textwidth + 25;
					y = context->y + ypos;
					gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
							0x00ff00ff, context->width, context->height, 0, 0);

					ypos += 10;
				}
			}
		}
	}

	return func0f153780(gdl);
}
#else
GLOBAL_ASM(
glabel menuRenderItemPlayerStats
/*  f0eb54c:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0eb550:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0eb554:	8def3af0 */ 	lw	$t7,0x3af0($t7)
/*  f0eb558:	3c18800a */ 	lui	$t8,0x800a
/*  f0eb55c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0eb560:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0eb564:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0eb568:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0eb56c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0eb570:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0eb574:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0eb578:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0eb57c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0eb580:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0eb584:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0eb588:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0eb58c:	931826a0 */ 	lbu	$t8,0x26a0($t8)
/*  f0eb590:	00a09825 */ 	or	$s3,$a1,$zero
/*  f0eb594:	0080b025 */ 	or	$s6,$a0,$zero
/*  f0eb598:	afae00bc */ 	sw	$t6,0xbc($sp)
/*  f0eb59c:	0fc61aa0 */ 	jal	mpGetNumChrs
/*  f0eb5a0:	afb800ac */ 	sw	$t8,0xac($sp)
/*  f0eb5a4:	8fa300ac */ 	lw	$v1,0xac($sp)
/*  f0eb5a8:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0eb5ac:	28610004 */ 	slti	$at,$v1,0x4
/*  f0eb5b0:	10200008 */ 	beqz	$at,.NB0f0eb5d4
/*  f0eb5b4:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0eb5b8:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0eb5bc:	3c08800b */ 	lui	$t0,0x800b
/*  f0eb5c0:	25081068 */ 	addiu	$t0,$t0,0x1068
/*  f0eb5c4:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0eb5c8:	03284821 */ 	addu	$t1,$t9,$t0
/*  f0eb5cc:	1000000b */ 	beqz	$zero,.NB0f0eb5fc
/*  f0eb5d0:	afa900a8 */ 	sw	$t1,0xa8($sp)
.NB0f0eb5d4:
/*  f0eb5d4:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0eb5d8:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0eb5dc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0eb5e0:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0eb5e4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0eb5e8:	3c0c800b */ 	lui	$t4,0x800b
/*  f0eb5ec:	258c0de8 */ 	addiu	$t4,$t4,0xde8
/*  f0eb5f0:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f0eb5f4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0eb5f8:	afad00a8 */ 	sw	$t5,0xa8($sp)
.NB0f0eb5fc:
/*  f0eb5fc:	0fc5374a */ 	jal	func0f153628
/*  f0eb600:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0eb604:	3c014220 */ 	lui	$at,0x4220
/*  f0eb608:	44816000 */ 	mtc1	$at,$f12
/*  f0eb60c:	0fc019eb */ 	jal	func0f006b08
/*  f0eb610:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0eb614:	3c01437f */ 	lui	$at,0x437f
/*  f0eb618:	44812000 */ 	mtc1	$at,$f4
/*  f0eb61c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0eb620:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0eb624:	444ef800 */ 	cfc1	$t6,$31
/*  f0eb628:	44d4f800 */ 	ctc1	$s4,$31
/*  f0eb62c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb630:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0eb634:	4454f800 */ 	cfc1	$s4,$31
/*  f0eb638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb63c:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0eb640:	12800012 */ 	beqz	$s4,.NB0f0eb68c
/*  f0eb644:	3c014f00 */ 	lui	$at,0x4f00
/*  f0eb648:	44814000 */ 	mtc1	$at,$f8
/*  f0eb64c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0eb650:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0eb654:	44d4f800 */ 	ctc1	$s4,$31
/*  f0eb658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb65c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0eb660:	4454f800 */ 	cfc1	$s4,$31
/*  f0eb664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb668:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0eb66c:	16800005 */ 	bnez	$s4,.NB0f0eb684
/*  f0eb670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb674:	44144000 */ 	mfc1	$s4,$f8
/*  f0eb678:	3c018000 */ 	lui	$at,0x8000
/*  f0eb67c:	10000007 */ 	beqz	$zero,.NB0f0eb69c
/*  f0eb680:	0281a025 */ 	or	$s4,$s4,$at
.NB0f0eb684:
/*  f0eb684:	10000005 */ 	beqz	$zero,.NB0f0eb69c
/*  f0eb688:	2414ffff */ 	addiu	$s4,$zero,-1
.NB0f0eb68c:
/*  f0eb68c:	44144000 */ 	mfc1	$s4,$f8
/*  f0eb690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb694:	0680fffb */ 	bltz	$s4,.NB0f0eb684
/*  f0eb698:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0eb69c:
/*  f0eb69c:	8e700010 */ 	lw	$s0,0x10($s3)
/*  f0eb6a0:	44cef800 */ 	ctc1	$t6,$31
/*  f0eb6a4:	44808000 */ 	mtc1	$zero,$f16
/*  f0eb6a8:	c60a0040 */ 	lwc1	$f10,0x40($s0)
/*  f0eb6ac:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0eb6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb6b4:	4502000b */ 	bc1fl	.NB0f0eb6e4
/*  f0eb6b8:	9208003d */ 	lbu	$t0,0x3d($s0)
/*  f0eb6bc:	920f003c */ 	lbu	$t7,0x3c($s0)
/*  f0eb6c0:	3c127f1b */ 	lui	$s2,0x7f1b
/*  f0eb6c4:	2652c2e0 */ 	addiu	$s2,$s2,-15648
/*  f0eb6c8:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0eb6cc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0eb6d0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0eb6d4:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f0eb6d8:	10000012 */ 	beqz	$zero,.NB0f0eb724
/*  f0eb6dc:	8f310020 */ 	lw	$s1,0x20($t9)
/*  f0eb6e0:	9208003d */ 	lbu	$t0,0x3d($s0)
.NB0f0eb6e4:
/*  f0eb6e4:	920b003c */ 	lbu	$t3,0x3c($s0)
/*  f0eb6e8:	3c127f1b */ 	lui	$s2,0x7f1b
/*  f0eb6ec:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eb6f0:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0eb6f4:	2652c2e0 */ 	addiu	$s2,$s2,-15648
/*  f0eb6f8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eb6fc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0eb700:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0eb704:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eb708:	02495021 */ 	addu	$t2,$s2,$t1
/*  f0eb70c:	024c6821 */ 	addu	$t5,$s2,$t4
/*  f0eb710:	8da50020 */ 	lw	$a1,0x20($t5)
/*  f0eb714:	8d440020 */ 	lw	$a0,0x20($t2)
/*  f0eb718:	0fc01990 */ 	jal	colourBlend
/*  f0eb71c:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eb720:	00408825 */ 	or	$s1,$v0,$zero
.NB0f0eb724:
/*  f0eb724:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0eb728:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0eb72c:	0fc01990 */ 	jal	colourBlend
/*  f0eb730:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb734:	00402025 */ 	or	$a0,$v0,$zero
/*  f0eb738:	02202825 */ 	or	$a1,$s1,$zero
/*  f0eb73c:	0fc01990 */ 	jal	colourBlend
/*  f0eb740:	02803025 */ 	or	$a2,$s4,$zero
/*  f0eb744:	866e0000 */ 	lh	$t6,0x0($s3)
/*  f0eb748:	3c178008 */ 	lui	$s7,0x8008
/*  f0eb74c:	3c1e8008 */ 	lui	$s8,0x8008
/*  f0eb750:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*  f0eb754:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f0eb758:	86780002 */ 	lh	$t8,0x2($s3)
/*  f0eb75c:	27de236c */ 	addiu	$s8,$s8,0x236c
/*  f0eb760:	26f72370 */ 	addiu	$s7,$s7,0x2370
/*  f0eb764:	8ee80000 */ 	lw	$t0,0x0($s7)
/*  f0eb768:	8fc90000 */ 	lw	$t1,0x0($s8)
/*  f0eb76c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0eb770:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0eb774:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0eb778:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eb77c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0eb780:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f0eb784:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0eb788:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0eb78c:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0eb790:	866b0006 */ 	lh	$t3,0x6($s3)
/*  f0eb794:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb798:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb79c:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0eb7a0:	8fa700a8 */ 	lw	$a3,0xa8($sp)
/*  f0eb7a4:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb7a8:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0eb7ac:	8e700010 */ 	lw	$s0,0x10($s3)
/*  f0eb7b0:	44802000 */ 	mtc1	$zero,$f4
/*  f0eb7b4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0eb7b8:	c6120040 */ 	lwc1	$f18,0x40($s0)
/*  f0eb7bc:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0eb7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb7c4:	45020009 */ 	bc1fl	.NB0f0eb7ec
/*  f0eb7c8:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0eb7cc:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0eb7d0:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0eb7d4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0eb7d8:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0eb7dc:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f0eb7e0:	10000011 */ 	beqz	$zero,.NB0f0eb828
/*  f0eb7e4:	8dd10018 */ 	lw	$s1,0x18($t6)
/*  f0eb7e8:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f0eb7ec:
/*  f0eb7ec:	9208003c */ 	lbu	$t0,0x3c($s0)
/*  f0eb7f0:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eb7f4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0eb7f8:	00084900 */ 	sll	$t1,$t0,0x4
/*  f0eb7fc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0eb800:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0eb804:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0eb808:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0eb80c:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f0eb810:	02495021 */ 	addu	$t2,$s2,$t1
/*  f0eb814:	8d450018 */ 	lw	$a1,0x18($t2)
/*  f0eb818:	0fc01990 */ 	jal	colourBlend
/*  f0eb81c:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0eb820:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eb824:	8e700010 */ 	lw	$s0,0x10($s3)
.NB0f0eb828:
/*  f0eb828:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0eb82c:	11600008 */ 	beqz	$t3,.NB0f0eb850
/*  f0eb830:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eb834:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eb838:	0fc01990 */ 	jal	colourBlend
/*  f0eb83c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eb840:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eb844:	00416024 */ 	and	$t4,$v0,$at
/*  f0eb848:	322d00ff */ 	andi	$t5,$s1,0xff
/*  f0eb84c:	018d8825 */ 	or	$s1,$t4,$t5
.NB0f0eb850:
/*  f0eb850:	0fc5a4dd */ 	jal	langGet
/*  f0eb854:	24045119 */ 	addiu	$a0,$zero,0x5119
/*  f0eb858:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0eb85c:	8dce2364 */ 	lw	$t6,0x2364($t6)
/*  f0eb860:	3c078008 */ 	lui	$a3,0x8008
/*  f0eb864:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0eb868:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0eb86c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0eb870:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eb874:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb878:	0fc54655 */ 	jal	textMeasure
/*  f0eb87c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0eb880:	866f0000 */ 	lh	$t7,0x0($s3)
/*  f0eb884:	24045119 */ 	addiu	$a0,$zero,0x5119
/*  f0eb888:	25f80038 */ 	addiu	$t8,$t7,0x38
/*  f0eb88c:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f0eb890:	86790002 */ 	lh	$t9,0x2($s3)
/*  f0eb894:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0eb898:	0fc5a4dd */ 	jal	langGet
/*  f0eb89c:	afa800b4 */ 	sw	$t0,0xb4($sp)
/*  f0eb8a0:	3c098008 */ 	lui	$t1,0x8008
/*  f0eb8a4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0eb8a8:	8d4a2364 */ 	lw	$t2,0x2364($t2)
/*  f0eb8ac:	8d292368 */ 	lw	$t1,0x2368($t1)
/*  f0eb8b0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0eb8b4:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0eb8b8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0eb8bc:	866b0004 */ 	lh	$t3,0x4($s3)
/*  f0eb8c0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0eb8c4:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0eb8c8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0eb8cc:	866c0006 */ 	lh	$t4,0x6($s3)
/*  f0eb8d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb8d4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb8d8:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0eb8dc:	00403825 */ 	or	$a3,$v0,$zero
/*  f0eb8e0:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb8e4:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0eb8e8:	8fa300ac */ 	lw	$v1,0xac($sp)
/*  f0eb8ec:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0eb8f0:	27b5008c */ 	addiu	$s5,$sp,0x8c
/*  f0eb8f4:	00036840 */ 	sll	$t5,$v1,0x1
/*  f0eb8f8:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0eb8fc:	85e60024 */ 	lh	$a2,0x24($t7)
/*  f0eb900:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0eb904:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0eb908:	24a5c17c */ 	addiu	$a1,$a1,-16004
/*  f0eb90c:	afad0064 */ 	sw	$t5,0x64($sp)
/*  f0eb910:	01a01825 */ 	or	$v1,$t5,$zero
/*  f0eb914:	0c004fc1 */ 	jal	sprintf
/*  f0eb918:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0eb91c:	8fd80000 */ 	lw	$t8,0x0($s8)
/*  f0eb920:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0eb924:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0eb928:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0eb92c:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f0eb930:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eb934:	0fc54655 */ 	jal	textMeasure
/*  f0eb938:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eb93c:	86790000 */ 	lh	$t9,0x0($s3)
/*  f0eb940:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f0eb944:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0eb948:	2728005f */ 	addiu	$t0,$t9,0x5f
/*  f0eb94c:	afa800b8 */ 	sw	$t0,0xb8($sp)
/*  f0eb950:	86690002 */ 	lh	$t1,0x2($s3)
/*  f0eb954:	3c0dffff */ 	lui	$t5,0xffff
/*  f0eb958:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f0eb95c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0eb960:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0eb964:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0eb968:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eb96c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0eb970:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f0eb974:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0eb978:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0eb97c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0eb980:	866f0006 */ 	lh	$t7,0x6($s3)
/*  f0eb984:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eb988:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eb98c:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0eb990:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0eb994:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eb998:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0eb99c:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0eb9a0:	0fc61aa0 */ 	jal	mpGetNumChrs
/*  f0eb9a4:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f0eb9a8:	28410002 */ 	slti	$at,$v0,0x2
/*  f0eb9ac:	14200157 */ 	bnez	$at,.NB0f0ebf0c
/*  f0eb9b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9b4:	8e700010 */ 	lw	$s0,0x10($s3)
/*  f0eb9b8:	44804000 */ 	mtc1	$zero,$f8
/*  f0eb9bc:	c6060040 */ 	lwc1	$f6,0x40($s0)
/*  f0eb9c0:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0eb9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0eb9c8:	45020009 */ 	bc1fl	.NB0f0eb9f0
/*  f0eb9cc:	9209003d */ 	lbu	$t1,0x3d($s0)
/*  f0eb9d0:	9218003c */ 	lbu	$t8,0x3c($s0)
/*  f0eb9d4:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0eb9d8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0eb9dc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0eb9e0:	02594021 */ 	addu	$t0,$s2,$t9
/*  f0eb9e4:	10000010 */ 	beqz	$zero,.NB0f0eba28
/*  f0eb9e8:	8d110018 */ 	lw	$s1,0x18($t0)
/*  f0eb9ec:	9209003d */ 	lbu	$t1,0x3d($s0)
.NB0f0eb9f0:
/*  f0eb9f0:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0eb9f4:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0eb9f8:	01220019 */ 	multu	$t1,$v0
/*  f0eb9fc:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0eba00:	00005012 */ 	mflo	$t2
/*  f0eba04:	024a5821 */ 	addu	$t3,$s2,$t2
/*  f0eba08:	8d640018 */ 	lw	$a0,0x18($t3)
/*  f0eba0c:	01820019 */ 	multu	$t4,$v0
/*  f0eba10:	00006812 */ 	mflo	$t5
/*  f0eba14:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f0eba18:	0fc01990 */ 	jal	colourBlend
/*  f0eba1c:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0eba20:	00408825 */ 	or	$s1,$v0,$zero
/*  f0eba24:	8e700010 */ 	lw	$s0,0x10($s3)
.NB0f0eba28:
/*  f0eba28:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0eba2c:	11e00008 */ 	beqz	$t7,.NB0f0eba50
/*  f0eba30:	02202025 */ 	or	$a0,$s1,$zero
/*  f0eba34:	00002825 */ 	or	$a1,$zero,$zero
/*  f0eba38:	0fc01990 */ 	jal	colourBlend
/*  f0eba3c:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0eba40:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0eba44:	0041c024 */ 	and	$t8,$v0,$at
/*  f0eba48:	323900ff */ 	andi	$t9,$s1,0xff
/*  f0eba4c:	03198825 */ 	or	$s1,$t8,$t9
.NB0f0eba50:
/*  f0eba50:	0fc5a4dd */ 	jal	langGet
/*  f0eba54:	2404511a */ 	addiu	$a0,$zero,0x511a
/*  f0eba58:	3c088008 */ 	lui	$t0,0x8008
/*  f0eba5c:	8d082364 */ 	lw	$t0,0x2364($t0)
/*  f0eba60:	3c078008 */ 	lui	$a3,0x8008
/*  f0eba64:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0eba68:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0eba6c:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0eba70:	00403025 */ 	or	$a2,$v0,$zero
/*  f0eba74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eba78:	0fc54655 */ 	jal	textMeasure
/*  f0eba7c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eba80:	86690000 */ 	lh	$t1,0x0($s3)
/*  f0eba84:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0eba88:	2404511a */ 	addiu	$a0,$zero,0x511a
/*  f0eba8c:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f0eba90:	256c0078 */ 	addiu	$t4,$t3,0x78
/*  f0eba94:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f0eba98:	866d0002 */ 	lh	$t5,0x2($s3)
/*  f0eba9c:	01b47021 */ 	addu	$t6,$t5,$s4
/*  f0ebaa0:	0fc5a4dd */ 	jal	langGet
/*  f0ebaa4:	afae00b4 */ 	sw	$t6,0xb4($sp)
/*  f0ebaa8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0ebaac:	3c188008 */ 	lui	$t8,0x8008
/*  f0ebab0:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f0ebab4:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f0ebab8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0ebabc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0ebac0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0ebac4:	86790004 */ 	lh	$t9,0x4($s3)
/*  f0ebac8:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebacc:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0ebad0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0ebad4:	86680006 */ 	lh	$t0,0x6($s3)
/*  f0ebad8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebadc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebae0:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0ebae4:	00403825 */ 	or	$a3,$v0,$zero
/*  f0ebae8:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ebaec:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ebaf0:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0ebaf4:	0fc5a4dd */ 	jal	langGet
/*  f0ebaf8:	2404511b */ 	addiu	$a0,$zero,0x511b
/*  f0ebafc:	3c098008 */ 	lui	$t1,0x8008
/*  f0ebb00:	8d292364 */ 	lw	$t1,0x2364($t1)
/*  f0ebb04:	3c078008 */ 	lui	$a3,0x8008
/*  f0ebb08:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0ebb0c:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0ebb10:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0ebb14:	00403025 */ 	or	$a2,$v0,$zero
/*  f0ebb18:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ebb1c:	0fc54655 */ 	jal	textMeasure
/*  f0ebb20:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ebb24:	866a0000 */ 	lh	$t2,0x0($s3)
/*  f0ebb28:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f0ebb2c:	2404511b */ 	addiu	$a0,$zero,0x511b
/*  f0ebb30:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f0ebb34:	258d0019 */ 	addiu	$t5,$t4,0x19
/*  f0ebb38:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0ebb3c:	866e0002 */ 	lh	$t6,0x2($s3)
/*  f0ebb40:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f0ebb44:	0fc5a4dd */ 	jal	langGet
/*  f0ebb48:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0ebb4c:	3c188008 */ 	lui	$t8,0x8008
/*  f0ebb50:	3c198008 */ 	lui	$t9,0x8008
/*  f0ebb54:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f0ebb58:	8f182368 */ 	lw	$t8,0x2368($t8)
/*  f0ebb5c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0ebb60:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ebb64:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ebb68:	86680004 */ 	lh	$t0,0x4($s3)
/*  f0ebb6c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebb70:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0ebb74:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0ebb78:	86690006 */ 	lh	$t1,0x6($s3)
/*  f0ebb7c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebb80:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebb84:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0ebb88:	00403825 */ 	or	$a3,$v0,$zero
/*  f0ebb8c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ebb90:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0ebb94:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f0ebb98:	866c0006 */ 	lh	$t4,0x6($s3)
/*  f0ebb9c:	26940007 */ 	addiu	$s4,$s4,0x7
/*  f0ebba0:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0ebba4:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0ebba8:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f0ebbac:	016c6823 */ 	subu	$t5,$t3,$t4
/*  f0ebbb0:	01b41821 */ 	addu	$v1,$t5,$s4
/*  f0ebbb4:	2463fff6 */ 	addiu	$v1,$v1,-10
/*  f0ebbb8:	04610002 */ 	bgez	$v1,.NB0f0ebbc4
/*  f0ebbbc:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0ebbc0:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0ebbc4:
/*  f0ebbc4:	84ce000c */ 	lh	$t6,0xc($a2)
/*  f0ebbc8:	3c058008 */ 	lui	$a1,0x8008
/*  f0ebbcc:	24a52320 */ 	addiu	$a1,$a1,0x2320
/*  f0ebbd0:	006e082a */ 	slt	$at,$v1,$t6
/*  f0ebbd4:	10200002 */ 	beqz	$at,.NB0f0ebbe0
/*  f0ebbd8:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0ebbdc:	a4c3000c */ 	sh	$v1,0xc($a2)
.NB0f0ebbe0:
/*  f0ebbe0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0ebbe4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0ebbe8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f0ebbec:	86780000 */ 	lh	$t8,0x0($s3)
/*  f0ebbf0:	866e0002 */ 	lh	$t6,0x2($s3)
/*  f0ebbf4:	3c014080 */ 	lui	$at,0x4080
/*  f0ebbf8:	03190019 */ 	multu	$t8,$t9
/*  f0ebbfc:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f0ebc00:	448f3000 */ 	mtc1	$t7,$f6
/*  f0ebc04:	44810000 */ 	mtc1	$at,$f0
/*  f0ebc08:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ebc0c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0ebc10:	24560008 */ 	addiu	$s6,$v0,0x8
/*  f0ebc14:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebc18:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f0ebc1c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0ebc20:	00004012 */ 	mflo	$t0
/*  f0ebc24:	44885000 */ 	mtc1	$t0,$f10
/*  f0ebc28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebc2c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0ebc30:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0ebc34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebc38:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ebc3c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ebc40:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0ebc44:	440a2000 */ 	mfc1	$t2,$f4
/*  f0ebc48:	44198000 */ 	mfc1	$t9,$f16
/*  f0ebc4c:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f0ebc50:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0ebc54:	01816825 */ 	or	$t5,$t4,$at
/*  f0ebc58:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f0ebc5c:	01a84825 */ 	or	$t1,$t5,$t0
/*  f0ebc60:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f0ebc64:	866b0004 */ 	lh	$t3,0x4($s3)
/*  f0ebc68:	866a0000 */ 	lh	$t2,0x0($s3)
/*  f0ebc6c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0ebc70:	86690002 */ 	lh	$t1,0x2($s3)
/*  f0ebc74:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0ebc78:	018e0019 */ 	multu	$t4,$t6
/*  f0ebc7c:	866a0006 */ 	lh	$t2,0x6($s3)
/*  f0ebc80:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0ebc84:	448b5000 */ 	mtc1	$t3,$f10
/*  f0ebc88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebc8c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0ebc90:	00007812 */ 	mflo	$t7
/*  f0ebc94:	448f9000 */ 	mtc1	$t7,$f18
/*  f0ebc98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebc9c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ebca0:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0ebca4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ebca8:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0ebcac:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ebcb0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ebcb4:	44194000 */ 	mfc1	$t9,$f8
/*  f0ebcb8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0ebcbc:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0ebcc0:	000d4300 */ 	sll	$t0,$t5,0xc
/*  f0ebcc4:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0ebcc8:	010fc025 */ 	or	$t8,$t0,$t7
/*  f0ebccc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0ebcd0:	84d9000c */ 	lh	$t9,0xc($a2)
/*  f0ebcd4:	0299a023 */ 	subu	$s4,$s4,$t9
.NB0f0ebcd8:
/*  f0ebcd8:	3c0d800b */ 	lui	$t5,0x800b
/*  f0ebcdc:	95ad144e */ 	lhu	$t5,0x144e($t5)
/*  f0ebce0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0ebce4:	02295004 */ 	sllv	$t2,$t1,$s1
/*  f0ebce8:	01aa5824 */ 	and	$t3,$t5,$t2
/*  f0ebcec:	11600083 */ 	beqz	$t3,.NB0f0ebefc
/*  f0ebcf0:	2a210004 */ 	slti	$at,$s1,0x4
/*  f0ebcf4:	10200008 */ 	beqz	$at,.NB0f0ebd18
/*  f0ebcf8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f0ebcfc:	00116080 */ 	sll	$t4,$s1,0x2
/*  f0ebd00:	01916021 */ 	addu	$t4,$t4,$s1
/*  f0ebd04:	3c0e800b */ 	lui	$t6,0x800b
/*  f0ebd08:	25ce1068 */ 	addiu	$t6,$t6,0x1068
/*  f0ebd0c:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f0ebd10:	1000000a */ 	beqz	$zero,.NB0f0ebd3c
/*  f0ebd14:	018e8021 */ 	addu	$s0,$t4,$t6
.NB0f0ebd18:
/*  f0ebd18:	00114080 */ 	sll	$t0,$s1,0x2
/*  f0ebd1c:	01114021 */ 	addu	$t0,$t0,$s1
/*  f0ebd20:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ebd24:	01114023 */ 	subu	$t0,$t0,$s1
/*  f0ebd28:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0ebd2c:	3c18800b */ 	lui	$t8,0x800b
/*  f0ebd30:	27180de8 */ 	addiu	$t8,$t8,0xde8
/*  f0ebd34:	250ffed0 */ 	addiu	$t7,$t0,-304
/*  f0ebd38:	01f88021 */ 	addu	$s0,$t7,$t8
.NB0f0ebd3c:
/*  f0ebd3c:	1239006f */ 	beq	$s1,$t9,.NB0f0ebefc
/*  f0ebd40:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebd44:	86690000 */ 	lh	$t1,0x0($s3)
/*  f0ebd48:	8eec0000 */ 	lw	$t4,0x0($s7)
/*  f0ebd4c:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f0ebd50:	252d001d */ 	addiu	$t5,$t1,0x1d
/*  f0ebd54:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0ebd58:	866a0002 */ 	lh	$t2,0x2($s3)
/*  f0ebd5c:	3c0800ff */ 	lui	$t0,0xff
/*  f0ebd60:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f0ebd64:	01545821 */ 	addu	$t3,$t2,$s4
/*  f0ebd68:	afab00b4 */ 	sw	$t3,0xb4($sp)
/*  f0ebd6c:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0ebd70:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ebd74:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ebd78:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f0ebd7c:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f0ebd80:	00114840 */ 	sll	$t1,$s1,0x1
/*  f0ebd84:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0ebd88:	86780006 */ 	lh	$t8,0x6($s3)
/*  f0ebd8c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebd90:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebd94:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0ebd98:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0ebd9c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0ebda0:	03299021 */ 	addu	$s2,$t9,$t1
/*  f0ebda4:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ebda8:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0ebdac:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f0ebdb0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ebdb4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0ebdb8:	020d5021 */ 	addu	$t2,$s0,$t5
/*  f0ebdbc:	85460024 */ 	lh	$a2,0x24($t2)
/*  f0ebdc0:	24a5c180 */ 	addiu	$a1,$a1,-16000
/*  f0ebdc4:	0c004fc1 */ 	jal	sprintf
/*  f0ebdc8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ebdcc:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0ebdd0:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0ebdd4:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0ebdd8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ebddc:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f0ebde0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ebde4:	0fc54655 */ 	jal	textMeasure
/*  f0ebde8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ebdec:	866c0000 */ 	lh	$t4,0x0($s3)
/*  f0ebdf0:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0ebdf4:	8ee90000 */ 	lw	$t1,0x0($s7)
/*  f0ebdf8:	8fcd0000 */ 	lw	$t5,0x0($s8)
/*  f0ebdfc:	018e4023 */ 	subu	$t0,$t4,$t6
/*  f0ebe00:	250f0078 */ 	addiu	$t7,$t0,0x78
/*  f0ebe04:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f0ebe08:	86780002 */ 	lh	$t8,0x2($s3)
/*  f0ebe0c:	3c0aff40 */ 	lui	$t2,0xff40
/*  f0ebe10:	354a40ff */ 	ori	$t2,$t2,0x40ff
/*  f0ebe14:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f0ebe18:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0ebe1c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0ebe20:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ebe24:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ebe28:	866b0004 */ 	lh	$t3,0x4($s3)
/*  f0ebe2c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebe30:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0ebe34:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0ebe38:	866c0006 */ 	lh	$t4,0x6($s3)
/*  f0ebe3c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebe40:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebe44:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0ebe48:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0ebe4c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ebe50:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0ebe54:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ebe58:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0ebe5c:	24a5c184 */ 	addiu	$a1,$a1,-15996
/*  f0ebe60:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ebe64:	0c004fc1 */ 	jal	sprintf
/*  f0ebe68:	86460024 */ 	lh	$a2,0x24($s2)
/*  f0ebe6c:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f0ebe70:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0ebe74:	27a5009c */ 	addiu	$a1,$sp,0x9c
/*  f0ebe78:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0ebe7c:	8ee70000 */ 	lw	$a3,0x0($s7)
/*  f0ebe80:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ebe84:	0fc54655 */ 	jal	textMeasure
/*  f0ebe88:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ebe8c:	86680000 */ 	lh	$t0,0x0($s3)
/*  f0ebe90:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0ebe94:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f0ebe98:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0ebe9c:	010fc023 */ 	subu	$t8,$t0,$t7
/*  f0ebea0:	27190019 */ 	addiu	$t9,$t8,0x19
/*  f0ebea4:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f0ebea8:	86690002 */ 	lh	$t1,0x2($s3)
/*  f0ebeac:	3c0c00ff */ 	lui	$t4,0xff
/*  f0ebeb0:	358c00ff */ 	ori	$t4,$t4,0xff
/*  f0ebeb4:	01346821 */ 	addu	$t5,$t1,$s4
/*  f0ebeb8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0ebebc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0ebec0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ebec4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0ebec8:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f0ebecc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebed0:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0ebed4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0ebed8:	86680006 */ 	lh	$t0,0x6($s3)
/*  f0ebedc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ebee0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ebee4:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f0ebee8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0ebeec:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ebef0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ebef4:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0ebef8:	2694000a */ 	addiu	$s4,$s4,0xa
.NB0f0ebefc:
/*  f0ebefc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0ebf00:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0ebf04:	1621ff74 */ 	bne	$s1,$at,.NB0f0ebcd8
/*  f0ebf08:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0ebf0c:
/*  f0ebf0c:	0fc537a0 */ 	jal	func0f153780
/*  f0ebf10:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0ebf14:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0ebf18:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ebf1c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ebf20:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ebf24:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0ebf28:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0ebf2c:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0ebf30:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0ebf34:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0ebf38:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0ebf3c:	03e00008 */ 	jr	$ra
/*  f0ebf40:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);
#endif

bool menuTickItemPlayerStats(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if ((arg3 & 2) && !frame->dimmed) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_FINAL
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_FINAL
		intval = intval + (s32)(((f32)inputs->unk09 + (f32)inputs->unk09) * g_Vars.diffframe60freal);
#else
		intval += inputs->unk09 * 2 * g_Vars.diffframe60;
#endif
		data->dropdown.scrolloffset += intval;

		if (data->dropdown.scrolloffset < 0) {
			data->dropdown.scrolloffset = 0;
		}
	}

	menuTickItemDropdown(item, frame, inputs, arg3, data);
}

Gfx *menuRenderOverlayPlayerStats(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data)
{
#if VERSION >= VERSION_NTSC_1_0
	return menuRenderOverlayDropdown(gdl, x + 1, y, -1, y2, item, frame, data);
#else
	return menuRenderOverlayDropdown(gdl, x, y, 56, y2, item, frame, data);
#endif
}

void menuInitItemPlayerStats(struct menuitem *item, union menuitemdata *data)
{
	data->dropdown.scrolloffset = 0;
	g_MpSelectedPlayersForStats[g_MpPlayerNum] = g_MpPlayerNum;

	menuInitItemDropdown(item, data);
}

GLOBAL_ASM(
glabel func0f0ef394
/*  f0ef394:	3c098008 */ 	lui	$t1,%hi(g_ScaleX)
/*  f0ef398:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f0ef39c:	2529fac0 */ 	addiu	$t1,$t1,%lo(g_ScaleX)
/*  f0ef3a0:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f0ef3a4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0ef3a8:	04c10004 */ 	bgez	$a2,.L0f0ef3bc
/*  f0ef3ac:	30ce0003 */ 	andi	$t6,$a2,0x3
/*  f0ef3b0:	11c00002 */ 	beqz	$t6,.L0f0ef3bc
/*  f0ef3b4:	00000000 */ 	nop
/*  f0ef3b8:	25cefffc */ 	addiu	$t6,$t6,-4
.L0f0ef3bc:
/*  f0ef3bc:	03190019 */ 	multu	$t8,$t9
/*  f0ef3c0:	01c52821 */ 	addu	$a1,$t6,$a1
/*  f0ef3c4:	8fae0014 */ 	lw	$t6,0x14($sp)
/*  f0ef3c8:	3c01e400 */ 	lui	$at,0xe400
/*  f0ef3cc:	00801025 */ 	or	$v0,$a0,$zero
/*  f0ef3d0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0ef3d4:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f0ef3d8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef3dc:	00801825 */ 	or	$v1,$a0,$zero
/*  f0ef3e0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef3e4:	00005012 */ 	mflo	$t2
/*  f0ef3e8:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f0ef3ec:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0ef3f0:	01816825 */ 	or	$t5,$t4,$at
/*  f0ef3f4:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0ef3f8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0ef3fc:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0ef400:	00065080 */ 	sll	$t2,$a2,0x2
/*  f0ef404:	00076880 */ 	sll	$t5,$a3,0x2
/*  f0ef408:	014b0019 */ 	multu	$t2,$t3
/*  f0ef40c:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f0ef410:	00055940 */ 	sll	$t3,$a1,0x5
/*  f0ef414:	3c0ab400 */ 	lui	$t2,0xb400
/*  f0ef418:	00804025 */ 	or	$t0,$a0,$zero
/*  f0ef41c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ef420:	00006012 */ 	mflo	$t4
/*  f0ef424:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f0ef428:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f0ef42c:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0ef430:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0ef434:	01606025 */ 	or	$t4,$t3,$zero
/*  f0ef438:	000c7400 */ 	sll	$t6,$t4,0x10
/*  f0ef43c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0ef440:	04e10004 */ 	bgez	$a3,.L0f0ef454
/*  f0ef444:	30ed0003 */ 	andi	$t5,$a3,0x3
/*  f0ef448:	11a00002 */ 	beqz	$t5,.L0f0ef454
/*  f0ef44c:	00000000 */ 	nop
/*  f0ef450:	25adfffc */ 	addiu	$t5,$t5,-4
.L0f0ef454:
/*  f0ef454:	000d7940 */ 	sll	$t7,$t5,0x5
/*  f0ef458:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f0ef45c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0ef460:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0ef464:	3c0ab300 */ 	lui	$t2,0xb300
/*  f0ef468:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f0ef46c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0ef470:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f0ef474:	00801025 */ 	or	$v0,$a0,$zero
/*  f0ef478:	018b001a */ 	div	$zero,$t4,$t3
/*  f0ef47c:	00006812 */ 	mflo	$t5
/*  f0ef480:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f0ef484:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f0ef488:	35d80400 */ 	ori	$t8,$t6,0x400
/*  f0ef48c:	15600002 */ 	bnez	$t3,.L0f0ef498
/*  f0ef490:	00000000 */ 	nop
/*  f0ef494:	0007000d */ 	break	0x7
.L0f0ef498:
/*  f0ef498:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ef49c:	15610004 */ 	bne	$t3,$at,.L0f0ef4b0
/*  f0ef4a0:	3c018000 */ 	lui	$at,0x8000
/*  f0ef4a4:	15810002 */ 	bne	$t4,$at,.L0f0ef4b0
/*  f0ef4a8:	00000000 */ 	nop
/*  f0ef4ac:	0006000d */ 	break	0x6
.L0f0ef4b0:
/*  f0ef4b0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f0ef4b4:	03e00008 */ 	jr	$ra
/*  f0ef4b8:	00000000 */ 	nop
);

Gfx *menuRenderControllerTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha)
{
	gDPPipeSync(gdl++);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);

	func0f0b39c0(&gdl, &var800ab5a8[texturenum], 2, 0, 2, 1, 0);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0);

	gDPSetColor(gdl++, G_SETENVCOLOR, 0xffffff00 | alpha);

	gSPTextureRectangle(gdl++,
			(x << 2) * g_ScaleX, y << 2,
			((x + 32) << 2) * g_ScaleX, (y + 32) << 2,
			0, 16, 1008, 1024 / g_ScaleX, 0xfc00);

	return gdl;
}

GLOBAL_ASM(
glabel menuRenderControllerLines
/*  f0ef758:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0ef75c:	c4241630 */ 	lwc1	$f4,%lo(var80061630)($at)
/*  f0ef760:	3c014080 */ 	lui	$at,0x4080
/*  f0ef764:	44814000 */ 	mtc1	$at,$f8
/*  f0ef768:	46002187 */ 	neg.s	$f6,$f4
/*  f0ef76c:	3c014248 */ 	lui	$at,0x4248
/*  f0ef770:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0ef774:	44818000 */ 	mtc1	$at,$f16
/*  f0ef778:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0ef77c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0ef780:	afa400a0 */ 	sw	$a0,0xa0($sp)
/*  f0ef784:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0ef788:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0ef78c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ef790:	8fb000b8 */ 	lw	$s0,0xb8($sp)
/*  f0ef794:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0ef798:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0ef79c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0ef7a0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0ef7a4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0ef7a8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0ef7ac:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0ef7b0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0ef7b4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0ef7b8:	44152000 */ 	mfc1	$s5,$f4
/*  f0ef7bc:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0ef7c0:	afad00a0 */ 	sw	$t5,0xa0($sp)
/*  f0ef7c4:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0ef7c8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0ef7cc:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0ef7d0:	0010c042 */ 	srl	$t8,$s0,0x1
/*  f0ef7d4:	03008025 */ 	or	$s0,$t8,$zero
/*  f0ef7d8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0ef7dc:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f0ef7e0:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0ef7e4:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0ef7e8:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0ef7ec:	00e09825 */ 	or	$s3,$a3,$zero
/*  f0ef7f0:	06a10004 */ 	bgez	$s5,.L0f0ef804
/*  f0ef7f4:	32af0003 */ 	andi	$t7,$s5,0x3
/*  f0ef7f8:	11e00002 */ 	beqz	$t7,.L0f0ef804
/*  f0ef7fc:	00000000 */ 	nop
/*  f0ef800:	25effffc */ 	addiu	$t7,$t7,-4
.L0f0ef804:
/*  f0ef804:	01e0a825 */ 	or	$s5,$t7,$zero
/*  f0ef808:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef80c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ef810:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0ef814:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef818:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef81c:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0ef820:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef824:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0ef828:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0ef82c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0ef830:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0ef834:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0ef838:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0ef83c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0ef840:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0ef844:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0ef848:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f0ef84c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0ef850:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0ef854:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0ef858:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0ef85c:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f0ef860:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0ef864:	37180903 */ 	ori	$t8,$t8,0x903
/*  f0ef868:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ef86c:	afaf00a0 */ 	sw	$t7,0xa0($sp)
/*  f0ef870:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f0ef874:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0ef878:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0ef87c:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0ef880:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ef884:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0ef888:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ef88c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0ef890:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0ef894:	27a400a0 */ 	addiu	$a0,$sp,0xa0
/*  f0ef898:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0ef89c:	24a50294 */ 	addiu	$a1,$a1,0x0294
/*  f0ef8a0:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef8a4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0ef8a8:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0ef8ac:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef8b0:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef8b4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0ef8b8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef8bc:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*  f0ef8c0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0ef8c4:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0ef8c8:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0ef8cc:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0ef8d0:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0ef8d4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0ef8d8:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0ef8dc:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0ef8e0:	3c0eff37 */ 	lui	$t6,0xff37
/*  f0ef8e4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0ef8e8:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f0ef8ec:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0ef8f0:	35ad9a25 */ 	ori	$t5,$t5,0x9a25
/*  f0ef8f4:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0ef8f8:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0ef8fc:	8faf00a0 */ 	lw	$t7,0xa0($sp)
/*  f0ef900:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ef904:	02016825 */ 	or	$t5,$s0,$at
/*  f0ef908:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0ef90c:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f0ef910:	3c19fb00 */ 	lui	$t9,0xfb00
/*  f0ef914:	0272082a */ 	slt	$at,$s3,$s2
/*  f0ef918:	02408825 */ 	or	$s1,$s2,$zero
/*  f0ef91c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0ef920:	1420004e */ 	bnez	$at,.L0f0efa5c
/*  f0ef924:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0ef928:	00127100 */ 	sll	$t6,$s2,0x4
/*  f0ef92c:	3c0f8007 */ 	lui	$t7,%hi(var800711f4)
/*  f0ef930:	25ef11f4 */ 	addiu	$t7,$t7,%lo(var800711f4)
/*  f0ef934:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f0ef938:	8fb300b4 */ 	lw	$s3,0xb4($sp)
/*  f0ef93c:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0ef940:	8fb200b0 */ 	lw	$s2,0xb0($sp)
/*  f0ef944:	241e0011 */ 	addiu	$s8,$zero,0x11
/*  f0ef948:	2417000e */ 	addiu	$s7,$zero,0xe
/*  f0ef94c:	2414ffff */ 	addiu	$s4,$zero,-1
.L0f0ef950:
/*  f0ef950:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f0ef954:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0ef958:	56980005 */ 	bnel	$s4,$t8,.L0f0ef970
/*  f0ef95c:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef960:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0ef964:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0ef968:	ae0d000c */ 	sw	$t5,0xc($s0)
/*  f0ef96c:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef970:
/*  f0ef970:	56880005 */ 	bnel	$s4,$t0,.L0f0ef988
/*  f0ef974:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef978:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0ef97c:	25c80001 */ 	addiu	$t0,$t6,0x1
/*  f0ef980:	ae080008 */ 	sw	$t0,0x8($s0)
/*  f0ef984:	8e0a0000 */ 	lw	$t2,0x0($s0)
.L0f0ef988:
/*  f0ef988:	150a0002 */ 	bne	$t0,$t2,.L0f0ef994
/*  f0ef98c:	25580001 */ 	addiu	$t8,$t2,0x1
/*  f0ef990:	ae180008 */ 	sw	$t8,0x8($s0)
.L0f0ef994:
/*  f0ef994:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef998:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0ef99c:	252d0001 */ 	addiu	$t5,$t1,0x1
/*  f0ef9a0:	57290004 */ 	bnel	$t9,$t1,.L0f0ef9b4
/*  f0ef9a4:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef9a8:	ae0d000c */ 	sw	$t5,0xc($s0)
/*  f0ef9ac:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef9b0:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef9b4:
/*  f0ef9b4:	010a082a */ 	slt	$at,$t0,$t2
/*  f0ef9b8:	50200005 */ 	beqzl	$at,.L0f0ef9d0
/*  f0ef9bc:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0ef9c0:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0ef9c4:	ae0a0008 */ 	sw	$t2,0x8($s0)
/*  f0ef9c8:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef9cc:	8e0b000c */ 	lw	$t3,0xc($s0)
.L0f0ef9d0:
/*  f0ef9d0:	0169082a */ 	slt	$at,$t3,$t1
/*  f0ef9d4:	50200006 */ 	beqzl	$at,.L0f0ef9f0
/*  f0ef9d8:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0ef9dc:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f0ef9e0:	01205825 */ 	or	$t3,$t1,$zero
/*  f0ef9e4:	ae09000c */ 	sw	$t1,0xc($s0)
/*  f0ef9e8:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0ef9ec:	8e080008 */ 	lw	$t0,0x8($s0)
.L0f0ef9f0:
/*  f0ef9f0:	12370005 */ 	beq	$s1,$s7,.L0f0efa08
/*  f0ef9f4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0ef9f8:	123e0003 */ 	beq	$s1,$s8,.L0f0efa08
/*  f0ef9fc:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0efa00:	56210003 */ 	bnel	$s1,$at,.L0f0efa10
/*  f0efa04:	86c20000 */ 	lh	$v0,0x0($s6)
.L0f0efa08:
/*  f0efa08:	00152823 */ 	negu	$a1,$s5
/*  f0efa0c:	86c20000 */ 	lh	$v0,0x0($s6)
.L0f0efa10:
/*  f0efa10:	86c30002 */ 	lh	$v1,0x2($s6)
/*  f0efa14:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0efa18:	01427021 */ 	addu	$t6,$t2,$v0
/*  f0efa1c:	01d23021 */ 	addu	$a2,$t6,$s2
/*  f0efa20:	0102c021 */ 	addu	$t8,$t0,$v0
/*  f0efa24:	01636821 */ 	addu	$t5,$t3,$v1
/*  f0efa28:	01b37021 */ 	addu	$t6,$t5,$s3
/*  f0efa2c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f0efa30:	01237821 */ 	addu	$t7,$t1,$v1
/*  f0efa34:	01f33821 */ 	addu	$a3,$t7,$s3
/*  f0efa38:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0efa3c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0efa40:	0fc3bce5 */ 	jal	func0f0ef394
/*  f0efa44:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0efa48:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f0efa4c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0efa50:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f0efa54:	1591ffbe */ 	bne	$t4,$s1,.L0f0ef950
/*  f0efa58:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0f0efa5c:
/*  f0efa5c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0efa60:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0efa64:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0efa68:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0efa6c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0efa70:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0efa74:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0efa78:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0efa7c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0efa80:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0efa84:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0efa88:	03e00008 */ 	jr	$ra
/*  f0efa8c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

// These are the action names, like "AIM", and "LOOK UP"
u16 var80071354[][9] = {
	/*0*/  { L_MPWEAPONS_194, L_MPWEAPONS_196, L_MPWEAPONS_202, L_MPWEAPONS_197, L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_205, L_MPWEAPONS_210 },
	/*1*/  { L_MPWEAPONS_194, L_MPWEAPONS_200, L_MPWEAPONS_202, L_MPWEAPONS_201, L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_205, L_MPWEAPONS_210 },
	/*2*/  { L_MPWEAPONS_203, L_MPWEAPONS_196, L_MPWEAPONS_202, L_MPWEAPONS_197, L_MPWEAPONS_205, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_194, L_MPWEAPONS_210 },
	/*3*/  { L_MPWEAPONS_203, L_MPWEAPONS_200, L_MPWEAPONS_202, L_MPWEAPONS_201, L_MPWEAPONS_205, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_194, L_MPWEAPONS_210 },
	/*4*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*5*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*6*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_206, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*7*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_211, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_207, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*8*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_209, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*9*/  { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_208, L_MPWEAPONS_194, L_OPTIONS_003   },
	/*10*/ { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_209, L_MPWEAPONS_205, L_OPTIONS_003   },
	/*11*/ { L_OPTIONS_003,   L_OPTIONS_003,   L_MPWEAPONS_212, L_OPTIONS_003,   L_MPWEAPONS_203, L_MPWEAPONS_204, L_MPWEAPONS_208, L_MPWEAPONS_205, L_OPTIONS_003   },
};

u16 menuControllerGetButtonAction(s32 mode, s32 buttonnum)
{
	u32 textid = var80071354[mode][buttonnum];

	if (textid == L_MPWEAPONS_194 // "AIM"
			&& optionsGetAimControl(g_Menus[g_MpPlayerNum].main.mpindex) == AIMCONTROL_TOGGLE) {
		textid = L_MPWEAPONS_195; // "AIM TOGGLE"
	}

	if (textid == L_MPWEAPONS_196 // "LOOK UP"
			&& optionsGetForwardPitch(g_Menus[g_MpPlayerNum].main.mpindex) == false) {
		textid = L_MPWEAPONS_198; // "LOOK DOWN"
	}

	if (textid == L_MPWEAPONS_197 // "LOOK DOWN"
			&& optionsGetForwardPitch(g_Menus[g_MpPlayerNum].main.mpindex) == false) {
		textid = L_MPWEAPONS_199; // "LOOK UP"
	}

	return textid;
}

/**
 * Renders the button labels and actions for the control style dialog.
 *
 * When switching modes (control styles), a fade effect is used to fade in the
 * action names, but only if they differ from the previous mode.
 *
 * Note that the valuecolour argument is mostly unused - only the alpha channel
 * is used because the rest is bitwise or'ed to white.
 */
#if VERSION >= VERSION_NTSC_1_0
Gfx *menuRenderControllerText(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 x, s32 y, u32 valuecolour, u32 labelcolour, s8 prevmode)
{
	s32 rx;
	s32 ry;
	u16 textnum;
	u32 colour;

	u16 labels[] = {
		/*0*/ L_MPWEAPONS_185, // "L/R BUTTONS:"
		/*1*/ L_MPWEAPONS_186, // "UP C BUTTON:"
		/*2*/ L_MPWEAPONS_187, // "LEFT/RIGHT C BUTTONS:"
		/*3*/ L_MPWEAPONS_188, // "DOWN C BUTTON:"
		/*4*/ L_MPWEAPONS_189, // "A BUTTON:"
		/*5*/ L_MPWEAPONS_190, // "B BUTTON:"
		/*6*/ L_MPWEAPONS_191, // "CONTROL STICK:"
		/*7*/ L_MPWEAPONS_192, // "Z BUTTON:"
		/*8*/ L_MPWEAPONS_193, // "+ CONTROL PAD:"
	};

	s32 i;

	gdl = func0f153628(gdl);

	for (i = 0; i < ARRAYCOUNT(labels); i++) {
#if VERSION >= VERSION_PAL_FINAL
		ry = i * 8 + context->y + y - 4;
#else
		ry = i * 7 + context->y + y;
#endif

		// For the 2.x styles, only labels 4-7 are shown
		if (curmode < CONTROLMODE_21 || (i >= 4 && i <= 7)) {
			// Rendering a label such as "L/R BUTTONS:"
			rx = context->x + x + 76;
			gdl = textRenderProjected(gdl, &rx, &ry, langGet(labels[i]),
					g_CharsHandelGothicXs, g_FontHandelGothicXs, labelcolour, viGetWidth(), viGetHeight(), 0, 0);
		}

		textnum = menuControllerGetButtonAction(curmode, i);
		colour = valuecolour;

		// If there's a prevmode, get the text ID that was in this position for
		// prevmode. If it's the same text as curmode, don't fade the text.
		if (prevmode >= 0) {
			// I don't see how curmode can ever be > CONTROLMODE_24. Perhaps
			// during development the second player in the 2.x styles had to
			// choose their control style separately to player 1, in which case
			// there would have been 2.5, 2.6, 2.7 and 2.8 for player 2.
			if (curmode > CONTROLMODE_24) {
				if (textnum == menuControllerGetButtonAction(prevmode + 4, i)) {
					colour = labelcolour;
				}
			} else {
				if (textnum == menuControllerGetButtonAction(prevmode, i)) {
					colour = labelcolour;
				}
			}
		}

		if (curmode >= CONTROLMODE_21 && i == 2) {
			// Rendering a "CONTROLLER 1" or "CONTROLLER 2" heading
			rx = context->x + x + 63;
			colour = labelcolour;
		} else {
			// Rendering a value such as "WALK/TURN"
			// Make it white but preserve alpha
			colour |= 0xffffff00;
		}

		gdl = textRenderProjected(gdl, &rx, &ry, langGet(textnum),
				g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, viGetWidth(), viGetHeight(), 0, 0);
	}

	return func0f153780(gdl);
}
#else
GLOBAL_ASM(
glabel menuRenderControllerText
/*  f0ec8f0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0ec8f4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0ec8f8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0ec8fc:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0ec900:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0ec904:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0ec908:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0ec90c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0ec910:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0ec914:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0ec918:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0ec91c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0ec920:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0ec924:	25ef3adc */ 	addiu	$t7,$t7,0x3adc
/*  f0ec928:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ec92c:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0ec930:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0ec934:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ec938:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0ec93c:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0ec940:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f0ec944:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0ec948:	95e10010 */ 	lhu	$at,0x10($t7)
/*  f0ec94c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f0ec950:	00c0f025 */ 	or	$s8,$a2,$zero
/*  f0ec954:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f0ec958:	0fc5374a */ 	jal	func0f153628
/*  f0ec95c:	a5c10010 */ 	sh	$at,0x10($t6)
/*  f0ec960:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0ec964:	00009025 */ 	or	$s2,$zero,$zero
/*  f0ec968:	83b700b7 */ 	lb	$s7,0xb7($sp)
/*  f0ec96c:	8fb400b0 */ 	lw	$s4,0xb0($sp)
.NB0f0ec970:
/*  f0ec970:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0ec974:	14200006 */ 	bnez	$at,.NB0f0ec990
/*  f0ec978:	8faa00a4 */ 	lw	$t2,0xa4($sp)
/*  f0ec97c:	2a410004 */ 	slti	$at,$s2,0x4
/*  f0ec980:	14200029 */ 	bnez	$at,.NB0f0eca28
/*  f0ec984:	2a410008 */ 	slti	$at,$s2,0x8
/*  f0ec988:	50200028 */ 	beqzl	$at,.NB0f0eca2c
/*  f0ec98c:	02c02025 */ 	or	$a0,$s6,$zero
.NB0f0ec990:
/*  f0ec990:	87c90000 */ 	lh	$t1,0x0($s8)
/*  f0ec994:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0ec998:	001268c0 */ 	sll	$t5,$s2,0x3
/*  f0ec99c:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0ec9a0:	256c004c */ 	addiu	$t4,$t3,0x4c
/*  f0ec9a4:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f0ec9a8:	87d90002 */ 	lh	$t9,0x2($s8)
/*  f0ec9ac:	01b26823 */ 	subu	$t5,$t5,$s2
/*  f0ec9b0:	00124040 */ 	sll	$t0,$s2,0x1
/*  f0ec9b4:	01b9c021 */ 	addu	$t8,$t5,$t9
/*  f0ec9b8:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f0ec9bc:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f0ec9c0:	03a82021 */ 	addu	$a0,$sp,$t0
/*  f0ec9c4:	0fc5a4dd */ 	jal	langGet
/*  f0ec9c8:	94840074 */ 	lhu	$a0,0x74($a0)
/*  f0ec9cc:	0c002f77 */ 	jal	viGetWidth
/*  f0ec9d0:	00409825 */ 	or	$s3,$v0,$zero
/*  f0ec9d4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0ec9d8:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f0ec9dc:	0c002f7b */ 	jal	viGetHeight
/*  f0ec9e0:	01208025 */ 	or	$s0,$t1,$zero
/*  f0ec9e4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0ec9e8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ec9ec:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f0ec9f0:	8d4a2368 */ 	lw	$t2,0x2368($t2)
/*  f0ec9f4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ec9f8:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ec9fc:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0eca00:	02603825 */ 	or	$a3,$s3,$zero
/*  f0eca04:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0eca08:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0eca0c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0eca10:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eca14:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eca18:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eca1c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0eca20:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eca24:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f0eca28:
/*  f0eca28:	02c02025 */ 	or	$a0,$s6,$zero
.NB0f0eca2c:
/*  f0eca2c:	0fc3b1f3 */ 	jal	menuControllerGetButtonAction
/*  f0eca30:	02402825 */ 	or	$a1,$s2,$zero
/*  f0eca34:	3050ffff */ 	andi	$s0,$v0,0xffff
/*  f0eca38:	06e00010 */ 	bltz	$s7,.NB0f0eca7c
/*  f0eca3c:	8fb100ac */ 	lw	$s1,0xac($sp)
/*  f0eca40:	2ac10008 */ 	slti	$at,$s6,0x8
/*  f0eca44:	14200008 */ 	bnez	$at,.NB0f0eca68
/*  f0eca48:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0eca4c:	26e40004 */ 	addiu	$a0,$s7,0x4
/*  f0eca50:	0fc3b1f3 */ 	jal	menuControllerGetButtonAction
/*  f0eca54:	02402825 */ 	or	$a1,$s2,$zero
/*  f0eca58:	56020009 */ 	bnel	$s0,$v0,.NB0f0eca80
/*  f0eca5c:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0eca60:	10000006 */ 	beqz	$zero,.NB0f0eca7c
/*  f0eca64:	02808825 */ 	or	$s1,$s4,$zero
.NB0f0eca68:
/*  f0eca68:	0fc3b1f3 */ 	jal	menuControllerGetButtonAction
/*  f0eca6c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0eca70:	56020003 */ 	bnel	$s0,$v0,.NB0f0eca80
/*  f0eca74:	2ac10004 */ 	slti	$at,$s6,0x4
/*  f0eca78:	02808825 */ 	or	$s1,$s4,$zero
.NB0f0eca7c:
/*  f0eca7c:	2ac10004 */ 	slti	$at,$s6,0x4
.NB0f0eca80:
/*  f0eca80:	1420000a */ 	bnez	$at,.NB0f0ecaac
/*  f0eca84:	02002025 */ 	or	$a0,$s0,$zero
/*  f0eca88:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0eca8c:	16410007 */ 	bne	$s2,$at,.NB0f0ecaac
/*  f0eca90:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f0eca94:	87cc0000 */ 	lh	$t4,0x0($s8)
/*  f0eca98:	02808825 */ 	or	$s1,$s4,$zero
/*  f0eca9c:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0ecaa0:	2738003f */ 	addiu	$t8,$t9,0x3f
/*  f0ecaa4:	10000004 */ 	beqz	$zero,.NB0f0ecab8
/*  f0ecaa8:	afb80094 */ 	sw	$t8,0x94($sp)
.NB0f0ecaac:
/*  f0ecaac:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0ecab0:	02217025 */ 	or	$t6,$s1,$at
/*  f0ecab4:	01c08825 */ 	or	$s1,$t6,$zero
.NB0f0ecab8:
/*  f0ecab8:	0fc5a4dd */ 	jal	langGet
/*  f0ecabc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ecac0:	0c002f77 */ 	jal	viGetWidth
/*  f0ecac4:	00409825 */ 	or	$s3,$v0,$zero
/*  f0ecac8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0ecacc:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0ecad0:	0c002f7b */ 	jal	viGetHeight
/*  f0ecad4:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0ecad8:	3c088008 */ 	lui	$t0,0x8008
/*  f0ecadc:	3c098008 */ 	lui	$t1,0x8008
/*  f0ecae0:	8d292364 */ 	lw	$t1,0x2364($t1)
/*  f0ecae4:	8d082368 */ 	lw	$t0,0x2368($t0)
/*  f0ecae8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0ecaec:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0ecaf0:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0ecaf4:	02603825 */ 	or	$a3,$s3,$zero
/*  f0ecaf8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0ecafc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0ecb00:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0ecb04:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ecb08:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ecb0c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ecb10:	0fc541a6 */ 	jal	textRenderProjected
/*  f0ecb14:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ecb18:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0ecb1c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0ecb20:	1641ff93 */ 	bne	$s2,$at,.NB0f0ec970
/*  f0ecb24:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0ecb28:	0fc537a0 */ 	jal	func0f153780
/*  f0ecb2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ecb30:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0ecb34:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ecb38:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0ecb3c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0ecb40:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0ecb44:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0ecb48:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0ecb4c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0ecb50:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0ecb54:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0ecb58:	03e00008 */ 	jr	$ra
/*  f0ecb5c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

Gfx *menuRenderControllerInfo(Gfx *gdl, struct menurendercontext *context, s32 x, s32 y, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode)
{
	s32 rx = context->x + x;
	s32 ry = context->y + y + 4;

	// The controller graphic is split into 4 textures
	gdl = menuRenderControllerTexture(gdl, rx, ry, 0x33, alpha);
	gdl = menuRenderControllerTexture(gdl, rx + 32, ry, 0x34, alpha);
	gdl = menuRenderControllerTexture(gdl, rx, ry + 32, 0x35, alpha);
	gdl = menuRenderControllerTexture(gdl, rx + 32, ry + 32, 0x36, alpha);

	if (curmode >= CONTROLMODE_21) {
		gdl = menuRenderControllerLines(gdl, context, 13, 19, x, y, alpha);
	} else {
		gdl = menuRenderControllerLines(gdl, context, 0, 21, x, y, alpha);
	}

	return menuRenderControllerText(gdl, curmode, context, x, y, colour1, colour2, prevmode);
}

Gfx *menuRenderItemController(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_controller *data = &context->data->controller;
	u32 colour;
	u32 textcolour;
	s32 x;
	s32 y;
	char text[32];
	struct menuframe *frame = context->frame;
	u32 contalpha;
	u32 textalpha;

	func0f153d24();

	// If changing modes within the same group (eg. within 1.x)
	if (data->curmode != (g_Menus[g_MpPlayerNum].main.controlmode & 0xff)) {
		data->prevmode = data->curmode;
		data->curmode = g_Menus[g_MpPlayerNum].main.controlmode;
		data->textfadetimer = 0;
	}

	// If changing control group (eg. 1.4 -> 2.1)
	if (data->controlgroup == 1) {
		if (g_Menus[g_MpPlayerNum].main.controlmode < CONTROLMODE_21) {
			data->controlgroup = 2;
			data->contfadetimer = 0;
			data->prevmode = -1;
		}
	} else {
		if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
			data->controlgroup = 1;
			data->contfadetimer = 0;
			data->prevmode = -1;
		}
	}

	// If text is fading in (eg. recently changed 1.1 -> 1.2)
	if (data->textfadetimer < 255) {
		s32 value = data->textfadetimer + g_Vars.diffframe240 * 2;

		if (value > 255) {
			value = 255;
		}

		data->textfadetimer = value;
	}

	// If controller is fading in (eg. recently changed 1.4 -> 2.1)
	if (data->contfadetimer < 255) {
		s32 value = data->contfadetimer + g_Vars.diffframe240 * 2;

		if (value > 255) {
			value = 255;
		}

		data->contfadetimer = value;
	}

	textalpha = data->textfadetimer;
	contalpha = data->contfadetimer;
	gdl = func0f153628(gdl);

	if (frame->transitiontimer < 0) {
		colour = g_MenuColourPalettes[frame->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[frame->type2].unfocused,
				g_MenuColourPalettes[frame->type].unfocused,
				frame->colourweight);
	}

	if (frame->dimmed) {
		colour = colourBlend(colour, 0, 44) & 0xffffff00 | colour & 0xff;
	}

	func0f153e38(
			g_MenuColourPalettes3[frame->type].unfocused,
			g_MenuColourPalettes2[frame->type].unfocused);

	if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
		sprintf(text, langGet(L_MPWEAPONS_213), // "Control Style %s %s"
				langGet(g_ControlStyleOptions[g_Menus[g_MpPlayerNum].main.controlmode]),
				langGet(L_MPWEAPONS_215)); // "(Two-Handed)"
	} else {
		sprintf(text, langGet(L_MPWEAPONS_213), // "Control Style %s %s"
				langGet(g_ControlStyleOptions[g_Menus[g_MpPlayerNum].main.controlmode]),
				langGet(L_MPWEAPONS_214)); // "(One-Handed)"
	}

	x = context->x + 2;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text,
			g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
	gdl = func0f153780(gdl);

	textcolour = colourBlend(colour, colour & 0xffffff00, textalpha);
	colour = colourBlend(colour, colour & 0xffffff00, contalpha);

	if (g_Menus[g_MpPlayerNum].main.controlmode >= CONTROLMODE_21) {
		gdl = menuRenderControllerInfo(gdl, context, 0, 12,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);
		gdl = menuRenderControllerInfo(gdl, context, 0, 80,
				g_Menus[g_MpPlayerNum].main.controlmode + 4,
				contalpha, textcolour, colour, data->prevmode);
	} else {
		gdl = menuRenderControllerInfo(gdl, context, 0, PAL ? 19 : 15,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);

		x = context->x;
		y = context->y + 92;
		gdl = func0f153628(gdl);
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPWEAPONS_216), // "Hold weapon button for ..."
				g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
		gdl = func0f153780(gdl);
	}

	func0f153d3c();

	return gdl;
}

void menuInitItemController(union menuitemdata *data)
{
	data->controller.textfadetimer = 0;
	data->controller.contfadetimer = 0;
	data->controller.curmode = 255;
	data->controller.controlgroup = 255;
	data->controller.prevmode = -1;
}

Gfx *menuRenderItem(Gfx *gdl, struct menurendercontext *context)
{
	switch (context->item->type) {
	case MENUITEMTYPE_LIST:        return menuRenderItemList(gdl, context);
	case MENUITEMTYPE_SELECTABLE:  return menuRenderItemSelectable(gdl, context);
	case MENUITEMTYPE_SLIDER:      return menuRenderItemSlider(gdl);
	case MENUITEMTYPE_CHECKBOX:    return menuRenderItemCheckbox(gdl, context);
	case MENUITEMTYPE_SCROLLABLE:  return menuRenderItemScrollable(gdl, context);
	case MENUITEMTYPE_MARQUEE:     return menuRenderItemMarquee(gdl, context);
	case MENUITEMTYPE_LABEL:       return menuRenderItemLabel(gdl, context);
	case MENUITEMTYPE_METER:       return menuRenderItemMeter(gdl, context);
	case MENUITEMTYPE_SEPARATOR:   return menuRenderItemSeparator(gdl, context);
	case MENUITEMTYPE_OBJECTIVES:  return menuRenderItemObjectives(gdl, context);
	case MENUITEMTYPE_07:          return menuRenderItem07(gdl);
	case MENUITEMTYPE_DROPDOWN:    return menuRenderItemDropdown(gdl);
	case MENUITEMTYPE_KEYBOARD:    return menuRenderItemKeyboard(gdl, context);
	case MENUITEMTYPE_RANKING:     return menuRenderItemRanking(gdl, context);
	case MENUITEMTYPE_PLAYERSTATS: return menuRenderItemPlayerStats(gdl, context);
	case MENUITEMTYPE_CAROUSEL:    return menuRenderItemCarousel(gdl, context);
	case MENUITEMTYPE_MODEL:       return menuRenderItemModel(gdl, context);
	case MENUITEMTYPE_CONTROLLER:  return menuRenderItemController(gdl, context);
	}

	return gdl;
}

/**
 * Return true if default up/down/left/right/back behaviour should be used.
 */
bool menuTickItem(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuTickItemList(item, inputs, arg3, data);
	case MENUITEMTYPE_SELECTABLE:  return menuTickItemSelectable(item, inputs, arg3);
	case MENUITEMTYPE_SLIDER:      return menuTickItemSlider(item, frame, inputs, arg3, data);
	case MENUITEMTYPE_CHECKBOX:    return menuTickItemCheckbox(item, inputs, arg3);
	case MENUITEMTYPE_SCROLLABLE:  return menuTickItemScrollable(item, frame, inputs, arg3, data);
	case MENUITEMTYPE_MARQUEE:     return menuTickItemMarquee(item, data);
	case MENUITEMTYPE_RANKING:     return menuTickItemRanking(inputs, arg3, data);
	case MENUITEMTYPE_DROPDOWN:    return menuTickItemDropdown(item, frame, inputs, arg3, data);
	case MENUITEMTYPE_KEYBOARD:    return menuTickItemKeyboard(item, inputs, arg3, data);
	case MENUITEMTYPE_CAROUSEL:    return menuTickItemCarousel(item, inputs, arg3);
	case MENUITEMTYPE_PLAYERSTATS: return menuTickItemPlayerStats(item, frame, inputs, arg3, data);
	}

	return true;
}

void menuInitItem(struct menuitem *item, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:
	case MENUITEMTYPE_DROPDOWN:
		menuInitItemDropdown(item, data);
		break;
	case MENUITEMTYPE_SCROLLABLE:
		menuInitItemScrollable(data);
		break;
	case MENUITEMTYPE_MARQUEE:
		menuInitItemMarquee(data);
		break;
	case MENUITEMTYPE_RANKING:
		menuInitItemRanking(data);
		break;
	case MENUITEMTYPE_SLIDER:
		menuInitItemSlider(data);
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		menuInitItemPlayerStats(item, data);
		break;
	case MENUITEMTYPE_KEYBOARD:
		menuInitItemKeyboard(item, data);
		break;
	case MENUITEMTYPE_CONTROLLER:
		menuInitItemController(data);
		break;
	}
}

Gfx *menuRenderOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuRenderOverlayList(gdl, x, y, x2, y2);
	case MENUITEMTYPE_DROPDOWN:    return menuRenderOverlayDropdown(gdl, x, y, x2, y2, item, frame, data);
	case MENUITEMTYPE_PLAYERSTATS: return menuRenderOverlayPlayerStats(gdl, x, y, x2, y2, item, frame, data);
	}

	return gdl;
}
