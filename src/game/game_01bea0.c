#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_01bea0.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/game_0e0770.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/endscreen.h"
#include "game/game_127910.h"
#include "game/core.h"
#include "game/music.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/gamefile.h"
#include "game/mplayer/mplayer.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_13900.h"
#include "types.h"

const char var7f1a85b0[] = "lvup: %d\n";
const char var7f1a85bc[] = "file id %x-%x";
const char var7f1a85cc[] = " ticking: ";
const char var7f1a85d8[] = "1";
const char var7f1a85dc[] = "0";
const char var7f1a85e0[] = "Live: %d\n";
const char var7f1a85ec[] = "current:";
const char var7f1a85f8[] = " numactive %d ";

void func0f01bea0(void)
{
	if (var80062944) {
		var80062944 = 0;
		var80062948 = 0;
		func000139c8();
		func0f110bf8();
	}
}

void menuCountDialogs(void)
{
	s32 i;
	g_MenuData.count = 0;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curframe) {
			g_MenuData.count++;
		}
	}
}

GLOBAL_ASM(
glabel menuTickAll
.late_rodata
glabel var7f1a8608
.word 0x3ca3d70a
glabel var7f1a860c
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8610
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8614
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8618
.word menuTickAll+0x16c0 # f01d5e8
glabel var7f1a861c
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8620
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8624
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8628
.word menuTickAll+0x16c0 # f01d5e8
glabel var7f1a862c
.word menuTickAll+0x16c0 # f01d5e8
glabel var7f1a8630
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8634
.word menuTickAll+0x168c # f01d5b4
glabel var7f1a8638
.word menuTickAll+0x16c0 # f01d5e8
glabel var7f1a863c
.word menuTickAll+0x168c # f01d5b4
.text
/*  f01bf28:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f01bf2c:	3c0e8007 */ 	lui	$t6,%hi(g_ViMode)
/*  f01bf30:	8dce06c8 */ 	lw	$t6,%lo(g_ViMode)($t6)
/*  f01bf34:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f01bf38:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f01bf3c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f01bf40:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f01bf44:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f01bf48:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f01bf4c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f01bf50:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f01bf54:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f01bf58:	afb60154 */ 	sw	$s6,0x154($sp)
/*  f01bf5c:	16ce0005 */ 	bne	$s6,$t6,.L0f01bf74
/*  f01bf60:	00008025 */ 	or	$s0,$zero,$zero
/*  f01bf64:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f01bf68:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f01bf6c:	10000003 */ 	b	.L0f01bf7c
/*  f01bf70:	ac2ffac0 */ 	sw	$t7,%lo(g_ScreenWidthMultiplier)($at)
.L0f01bf74:
/*  f01bf74:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f01bf78:	ac36fac0 */ 	sw	$s6,%lo(g_ScreenWidthMultiplier)($at)
.L0f01bf7c:
/*  f01bf7c:	0fc01a77 */ 	jal	func0f0069dc
/*  f01bf80:	00000000 */ 	nop
/*  f01bf84:	3c15800a */ 	lui	$s5,%hi(g_MenuData)
/*  f01bf88:	0fc06fb8 */ 	jal	menuCountDialogs
/*  f01bf8c:	26b519c0 */ 	addiu	$s5,$s5,%lo(g_MenuData)
/*  f01bf90:	3c03800a */ 	lui	$v1,%hi(g_Menus)
/*  f01bf94:	3c05800a */ 	lui	$a1,%hi(g_MenuData)
/*  f01bf98:	24a519c0 */ 	addiu	$a1,$a1,%lo(g_MenuData)
/*  f01bf9c:	2463e000 */ 	addiu	$v1,$v1,%lo(g_Menus)
/*  f01bfa0:	9062083c */ 	lbu	$v0,0x83c($v1)
.L0f01bfa4:
/*  f01bfa4:	18400002 */ 	blez	$v0,.L0f01bfb0
/*  f01bfa8:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f01bfac:	a078083c */ 	sb	$t8,0x83c($v1)
.L0f01bfb0:
/*  f01bfb0:	8c7904f8 */ 	lw	$t9,0x4f8($v1)
/*  f01bfb4:	24630e70 */ 	addiu	$v1,$v1,0xe70
/*  f01bfb8:	13200002 */ 	beqz	$t9,.L0f01bfc4
/*  f01bfbc:	00000000 */ 	nop
/*  f01bfc0:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01bfc4:
/*  f01bfc4:	5465fff7 */ 	bnel	$v1,$a1,.L0f01bfa4
/*  f01bfc8:	9062083c */ 	lbu	$v0,0x83c($v1)
/*  f01bfcc:	16000009 */ 	bnez	$s0,.L0f01bff4
/*  f01bfd0:	00000000 */ 	nop
/*  f01bfd4:	92ad0014 */ 	lbu	$t5,0x14($s5)
/*  f01bfd8:	11a00006 */ 	beqz	$t5,.L0f01bff4
/*  f01bfdc:	00000000 */ 	nop
/*  f01bfe0:	92ae0015 */ 	lbu	$t6,0x15($s5)
/*  f01bfe4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f01bfe8:	15c10002 */ 	bne	$t6,$at,.L0f01bff4
/*  f01bfec:	00000000 */ 	nop
/*  f01bff0:	a2a00015 */ 	sb	$zero,0x15($s5)
.L0f01bff4:
/*  f01bff4:	5200002f */ 	beqzl	$s0,.L0f01c0b4
/*  f01bff8:	92a30015 */ 	lbu	$v1,0x15($s5)
/*  f01bffc:	82a8066e */ 	lb	$t0,0x66e($s5)
/*  f01c000:	3c10800a */ 	lui	$s0,%hi(var8009dfc0)
/*  f01c004:	2610dfc0 */ 	addiu	$s0,$s0,%lo(var8009dfc0)
/*  f01c008:	5900002a */ 	blezl	$t0,.L0f01c0b4
/*  f01c00c:	92a30015 */ 	lbu	$v1,0x15($s5)
/*  f01c010:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f01c014:	24070032 */ 	addiu	$a3,$zero,0x32
/*  f01c018:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c01c:	11e00024 */ 	beqz	$t7,.L0f01c0b0
/*  f01c020:	3c04800a */ 	lui	$a0,%hi(g_Menus)
/*  f01c024:	3c05800a */ 	lui	$a1,%hi(g_MenuData)
/*  f01c028:	24a519c0 */ 	addiu	$a1,$a1,%lo(g_MenuData)
/*  f01c02c:	2484e000 */ 	addiu	$a0,$a0,%lo(g_Menus)
/*  f01c030:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f01c034:	8c8304f8 */ 	lw	$v1,0x4f8($a0)
.L0f01c038:
/*  f01c038:	24840e70 */ 	addiu	$a0,$a0,0xe70
/*  f01c03c:	10600009 */ 	beqz	$v1,.L0f01c064
/*  f01c040:	00000000 */ 	nop
/*  f01c044:	90620060 */ 	lbu	$v0,0x60($v1)
/*  f01c048:	52c20006 */ 	beql	$s6,$v0,.L0f01c064
/*  f01c04c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01c050:	51220004 */ 	beql	$t1,$v0,.L0f01c064
/*  f01c054:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01c058:	14400002 */ 	bnez	$v0,.L0f01c064
/*  f01c05c:	00000000 */ 	nop
/*  f01c060:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01c064:
/*  f01c064:	5485fff4 */ 	bnel	$a0,$a1,.L0f01c038
/*  f01c068:	8c8304f8 */ 	lw	$v1,0x4f8($a0)
/*  f01c06c:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f01c070:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f01c074:	8e780318 */ 	lw	$t8,0x318($s3)
/*  f01c078:	53000003 */ 	beqzl	$t8,.L0f01c088
/*  f01c07c:	92a2066f */ 	lbu	$v0,0x66f($s5)
/*  f01c080:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f01c084:	92a2066f */ 	lbu	$v0,0x66f($s5)
.L0f01c088:
/*  f01c088:	00e2082a */ 	slt	$at,$a3,$v0
/*  f01c08c:	14200003 */ 	bnez	$at,.L0f01c09c
/*  f01c090:	00000000 */ 	nop
/*  f01c094:	14c00005 */ 	bnez	$a2,.L0f01c0ac
/*  f01c098:	24590001 */ 	addiu	$t9,$v0,0x1
.L0f01c09c:
/*  f01c09c:	0fc3cc88 */ 	jal	func0f0f3220
/*  f01c0a0:	2504ffff */ 	addiu	$a0,$t0,-1
/*  f01c0a4:	10000003 */ 	b	.L0f01c0b4
/*  f01c0a8:	92a30015 */ 	lbu	$v1,0x15($s5)
.L0f01c0ac:
/*  f01c0ac:	a2b9066f */ 	sb	$t9,0x66f($s5)
.L0f01c0b0:
/*  f01c0b0:	92a30015 */ 	lbu	$v1,0x15($s5)
.L0f01c0b4:
/*  f01c0b4:	3c10800a */ 	lui	$s0,%hi(var8009dfc0)
/*  f01c0b8:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f01c0bc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f01c0c0:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f01c0c4:	2610dfc0 */ 	addiu	$s0,$s0,%lo(var8009dfc0)
/*  f01c0c8:	10610072 */ 	beq	$v1,$at,.L0f01c294
/*  f01c0cc:	92a20014 */ 	lbu	$v0,0x14($s5)
/*  f01c0d0:	14430004 */ 	bne	$v0,$v1,.L0f01c0e4
/*  f01c0d4:	3c017f1b */ 	lui	$at,%hi(var7f1a8608)
/*  f01c0d8:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f01c0dc:	10000073 */ 	b	.L0f01c2ac
/*  f01c0e0:	a2ad0015 */ 	sb	$t5,0x15($s5)
.L0f01c0e4:
/*  f01c0e4:	c4228608 */ 	lwc1	$f2,%lo(var7f1a8608)($at)
/*  f01c0e8:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f01c0ec:	14400002 */ 	bnez	$v0,.L0f01c0f8
/*  f01c0f0:	46001006 */ 	mov.s	$f0,$f2
/*  f01c0f4:	46021000 */ 	add.s	$f0,$f2,$f2
.L0f01c0f8:
/*  f01c0f8:	14600002 */ 	bnez	$v1,.L0f01c104
/*  f01c0fc:	3c0140a0 */ 	lui	$at,0x40a0
/*  f01c100:	46000000 */ 	add.s	$f0,$f0,$f0
.L0f01c104:
/*  f01c104:	56230005 */ 	bnel	$s1,$v1,.L0f01c11c
/*  f01c108:	24010007 */ 	addiu	$at,$zero,0x7
/*  f01c10c:	44812000 */ 	mtc1	$at,$f4
/*  f01c110:	00000000 */ 	nop
/*  f01c114:	46040003 */ 	div.s	$f0,$f0,$f4
/*  f01c118:	24010007 */ 	addiu	$at,$zero,0x7
.L0f01c11c:
/*  f01c11c:	14610004 */ 	bne	$v1,$at,.L0f01c130
/*  f01c120:	3c014040 */ 	lui	$at,0x4040
/*  f01c124:	44813000 */ 	mtc1	$at,$f6
/*  f01c128:	00000000 */ 	nop
/*  f01c12c:	46060003 */ 	div.s	$f0,$f0,$f6
.L0f01c130:
/*  f01c130:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01c134:	14610004 */ 	bne	$v1,$at,.L0f01c148
/*  f01c138:	3c014120 */ 	lui	$at,0x4120
/*  f01c13c:	44814000 */ 	mtc1	$at,$f8
/*  f01c140:	00000000 */ 	nop
/*  f01c144:	46080003 */ 	div.s	$f0,$f0,$f8
.L0f01c148:
/*  f01c148:	14600009 */ 	bnez	$v1,.L0f01c170
/*  f01c14c:	3c014080 */ 	lui	$at,0x4080
/*  f01c150:	8e620284 */ 	lw	$v0,0x284($s3)
/*  f01c154:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f01c158:	904e15ea */ 	lbu	$t6,0x15ea($v0)
/*  f01c15c:	51c00005 */ 	beqzl	$t6,.L0f01c174
/*  f01c160:	92ad0016 */ 	lbu	$t5,0x16($s5)
/*  f01c164:	90581583 */ 	lbu	$t8,0x1583($v0)
/*  f01c168:	37190002 */ 	ori	$t9,$t8,0x2
/*  f01c16c:	a0591583 */ 	sb	$t9,0x1583($v0)
.L0f01c170:
/*  f01c170:	92ad0016 */ 	lbu	$t5,0x16($s5)
.L0f01c174:
/*  f01c174:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f01c178:	51a00005 */ 	beqzl	$t5,.L0f01c190
/*  f01c17c:	44816000 */ 	mtc1	$at,$f12
/*  f01c180:	92ae0014 */ 	lbu	$t6,0x14($s5)
/*  f01c184:	51c0000d */ 	beqzl	$t6,.L0f01c1bc
/*  f01c188:	3c013f80 */ 	lui	$at,0x3f80
/*  f01c18c:	44816000 */ 	mtc1	$at,$f12
.L0f01c190:
/*  f01c190:	c6620004 */ 	lwc1	$f2,0x4($s3)
/*  f01c194:	4602603c */ 	c.lt.s	$f12,$f2
/*  f01c198:	00000000 */ 	nop
/*  f01c19c:	45000002 */ 	bc1f	.L0f01c1a8
/*  f01c1a0:	00000000 */ 	nop
/*  f01c1a4:	46006086 */ 	mov.s	$f2,$f12
.L0f01c1a8:
/*  f01c1a8:	46020402 */ 	mul.s	$f16,$f0,$f2
/*  f01c1ac:	c6aa0010 */ 	lwc1	$f10,0x10($s5)
/*  f01c1b0:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f01c1b4:	e6b20010 */ 	swc1	$f18,0x10($s5)
/*  f01c1b8:	3c013f80 */ 	lui	$at,0x3f80
.L0f01c1bc:
/*  f01c1bc:	44812000 */ 	mtc1	$at,$f4
/*  f01c1c0:	c6a60010 */ 	lwc1	$f6,0x10($s5)
/*  f01c1c4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f01c1c8:	00000000 */ 	nop
/*  f01c1cc:	45020022 */ 	bc1fl	.L0f01c258
/*  f01c1d0:	92b90015 */ 	lbu	$t9,0x15($s5)
/*  f01c1d4:	92a20015 */ 	lbu	$v0,0x15($s5)
/*  f01c1d8:	44804000 */ 	mtc1	$zero,$f8
/*  f01c1dc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01c1e0:	50400003 */ 	beqzl	$v0,.L0f01c1f0
/*  f01c1e4:	8eb80004 */ 	lw	$t8,0x4($s5)
/*  f01c1e8:	ae160000 */ 	sw	$s6,0x0($s0)
/*  f01c1ec:	8eb80004 */ 	lw	$t8,0x4($s5)
.L0f01c1f0:
/*  f01c1f0:	e6a80010 */ 	swc1	$f8,0x10($s5)
/*  f01c1f4:	a2a20014 */ 	sb	$v0,0x14($s5)
/*  f01c1f8:	16d80011 */ 	bne	$s6,$t8,.L0f01c240
/*  f01c1fc:	a2af0015 */ 	sb	$t7,0x15($s5)
/*  f01c200:	304200ff */ 	andi	$v0,$v0,0xff
/*  f01c204:	16c20002 */ 	bne	$s6,$v0,.L0f01c210
/*  f01c208:	24190006 */ 	addiu	$t9,$zero,0x6
/*  f01c20c:	a2b90015 */ 	sb	$t9,0x15($s5)
.L0f01c210:
/*  f01c210:	14410008 */ 	bne	$v0,$at,.L0f01c234
/*  f01c214:	00000000 */ 	nop
/*  f01c218:	0fc393f5 */ 	jal	func0f0e4fd4
/*  f01c21c:	00000000 */ 	nop
/*  f01c220:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01c224:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f01c228:	a2ad0014 */ 	sb	$t5,0x14($s5)
/*  f01c22c:	a2ae0015 */ 	sb	$t6,0x15($s5)
/*  f01c230:	31a200ff */ 	andi	$v0,$t5,0xff
.L0f01c234:
/*  f01c234:	16220002 */ 	bne	$s1,$v0,.L0f01c240
/*  f01c238:	240f0007 */ 	addiu	$t7,$zero,0x7
/*  f01c23c:	a2af0015 */ 	sb	$t7,0x15($s5)
.L0f01c240:
/*  f01c240:	92b80014 */ 	lbu	$t8,0x14($s5)
/*  f01c244:	57000004 */ 	bnezl	$t8,.L0f01c258
/*  f01c248:	92b90015 */ 	lbu	$t9,0x15($s5)
/*  f01c24c:	0fc3e9ab */ 	jal	func0f0fa6ac
/*  f01c250:	00000000 */ 	nop
/*  f01c254:	92b90015 */ 	lbu	$t9,0x15($s5)
.L0f01c258:
/*  f01c258:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c25c:	57210003 */ 	bnel	$t9,$at,.L0f01c26c
/*  f01c260:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f01c264:	ae160000 */ 	sw	$s6,0x0($s0)
/*  f01c268:	8e0d0000 */ 	lw	$t5,0x0($s0)
.L0f01c26c:
/*  f01c26c:	11a00007 */ 	beqz	$t5,.L0f01c28c
/*  f01c270:	00000000 */ 	nop
/*  f01c274:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f01c278:	8dcf1bd4 */ 	lw	$t7,0x1bd4($t6)
/*  f01c27c:	11e00003 */ 	beqz	$t7,.L0f01c28c
/*  f01c280:	00000000 */ 	nop
/*  f01c284:	0fc2e54e */ 	jal	func0f0b9538
/*  f01c288:	00000000 */ 	nop
.L0f01c28c:
/*  f01c28c:	10000007 */ 	b	.L0f01c2ac
/*  f01c290:	00000000 */ 	nop
.L0f01c294:
/*  f01c294:	44805000 */ 	mtc1	$zero,$f10
/*  f01c298:	14400003 */ 	bnez	$v0,.L0f01c2a8
/*  f01c29c:	e6aa0010 */ 	swc1	$f10,0x10($s5)
/*  f01c2a0:	10000002 */ 	b	.L0f01c2ac
/*  f01c2a4:	ae000000 */ 	sw	$zero,0x0($s0)
.L0f01c2a8:
/*  f01c2a8:	ae160000 */ 	sw	$s6,0x0($s0)
.L0f01c2ac:
/*  f01c2ac:	3c188008 */ 	lui	$t8,%hi(var80087260)
/*  f01c2b0:	8f187260 */ 	lw	$t8,%lo(var80087260)($t8)
/*  f01c2b4:	1b00006c */ 	blez	$t8,.L0f01c468
/*  f01c2b8:	00000000 */ 	nop
/*  f01c2bc:	8e79000c */ 	lw	$t9,0xc($s3)
/*  f01c2c0:	2b210004 */ 	slti	$at,$t9,0x4
/*  f01c2c4:	14200064 */ 	bnez	$at,.L0f01c458
/*  f01c2c8:	00000000 */ 	nop
/*  f01c2cc:	8e6304b4 */ 	lw	$v1,0x4b4($s3)
/*  f01c2d0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01c2d4:	10610003 */ 	beq	$v1,$at,.L0f01c2e4
/*  f01c2d8:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f01c2dc:	1461005b */ 	bne	$v1,$at,.L0f01c44c
/*  f01c2e0:	00000000 */ 	nop
.L0f01c2e4:
/*  f01c2e4:	0c0027b1 */ 	jal	func00009ec4
/*  f01c2e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c2ec:	8e6d049c */ 	lw	$t5,0x49c($s3)
/*  f01c2f0:	3c148007 */ 	lui	$s4,%hi(var800714d8)
/*  f01c2f4:	269414d8 */ 	addiu	$s4,$s4,%lo(var800714d8)
/*  f01c2f8:	11a00003 */ 	beqz	$t5,.L0f01c308
/*  f01c2fc:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f01c300:	10000003 */ 	b	.L0f01c310
/*  f01c304:	ae760490 */ 	sw	$s6,0x490($s3)
.L0f01c308:
/*  f01c308:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f01c30c:	ae6e0490 */ 	sw	$t6,0x490($s3)
.L0f01c310:
/*  f01c310:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f01c314:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x16)
/*  f01c318:	9463cb9e */ 	lhu	$v1,%lo(g_MpSetup+0x16)($v1)
/*  f01c31c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f01c320:	00008825 */ 	or	$s1,$zero,$zero
.L0f01c324:
/*  f01c324:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01c328:	022fc004 */ 	sllv	$t8,$t7,$s1
/*  f01c32c:	0078c824 */ 	and	$t9,$v1,$t8
/*  f01c330:	13200026 */ 	beqz	$t9,.L0f01c3cc
/*  f01c334:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c338:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f01c33c:	ac311448 */ 	sw	$s1,%lo(g_MpPlayerNum)($at)
/*  f01c340:	8e6d0490 */ 	lw	$t5,0x490($s3)
/*  f01c344:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f01c348:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01c34c:	16cd0008 */ 	bne	$s6,$t5,.L0f01c370
/*  f01c350:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f01c354:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f01c358:	0fc5ff2c */ 	jal	func0f17fcb0
/*  f01c35c:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c360:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x16)
/*  f01c364:	9463cb9e */ 	lhu	$v1,%lo(g_MpSetup+0x16)($v1)
/*  f01c368:	10000018 */ 	b	.L0f01c3cc
/*  f01c36c:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c370:
/*  f01c370:	14400015 */ 	bnez	$v0,.L0f01c3c8
/*  f01c374:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f01c378:	ae8f0000 */ 	sw	$t7,0x0($s4)
/*  f01c37c:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f01c380:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f01c384:	3c048008 */ 	lui	$a0,%hi(g_CombatSimulatorMenuDialog)
/*  f01c388:	248467a0 */ 	addiu	$a0,$a0,%lo(g_CombatSimulatorMenuDialog)
/*  f01c38c:	16d80008 */ 	bne	$s6,$t8,.L0f01c3b0
/*  f01c390:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c394:	3c048007 */ 	lui	$a0,%hi(g_4MbMainMenu)
/*  f01c398:	24845294 */ 	addiu	$a0,$a0,%lo(g_4MbMainMenu)
/*  f01c39c:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c3a0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c3a4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c3a8:	10000004 */ 	b	.L0f01c3bc
/*  f01c3ac:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c3b0:
/*  f01c3b0:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c3b4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c3b8:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c3bc:
/*  f01c3bc:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x16)
/*  f01c3c0:	10000002 */ 	b	.L0f01c3cc
/*  f01c3c4:	9463cb9e */ 	lhu	$v1,%lo(g_MpSetup+0x16)($v1)
.L0f01c3c8:
/*  f01c3c8:	a1160494 */ 	sb	$s6,0x494($t0)
.L0f01c3cc:
/*  f01c3cc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c3d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01c3d4:	1621ffd3 */ 	bne	$s1,$at,.L0f01c324
/*  f01c3d8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f01c3dc:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f01c3e0:	3079000f */ 	andi	$t9,$v1,0xf
/*  f01c3e4:	13200019 */ 	beqz	$t9,.L0f01c44c
/*  f01c3e8:	ac201448 */ 	sw	$zero,%lo(g_MpPlayerNum)($at)
/*  f01c3ec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f01c3f0:	44818000 */ 	mtc1	$at,$f16
/*  f01c3f4:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f01c3f8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01c3fc:	240effff */ 	addiu	$t6,$zero,-1
/*  f01c400:	240fffff */ 	addiu	$t7,$zero,-1
/*  f01c404:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f01c408:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f01c40c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f01c410:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f01c414:	24058098 */ 	addiu	$a1,$zero,-32616
/*  f01c418:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c41c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01c420:	0c004241 */ 	jal	audioStart
/*  f01c424:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f01c428:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f01c42c:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f01c430:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f01c434:	16d80003 */ 	bne	$s6,$t8,.L0f01c444
/*  f01c438:	00000000 */ 	nop
/*  f01c43c:	10000001 */ 	b	.L0f01c444
/*  f01c440:	2404000b */ 	addiu	$a0,$zero,0xb
.L0f01c444:
/*  f01c444:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f01c448:	00000000 */ 	nop
.L0f01c44c:
/*  f01c44c:	3c018008 */ 	lui	$at,%hi(var80087260)
/*  f01c450:	10000005 */ 	b	.L0f01c468
/*  f01c454:	ac207260 */ 	sw	$zero,%lo(var80087260)($at)
.L0f01c458:
/*  f01c458:	0c0027b1 */ 	jal	func00009ec4
/*  f01c45c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01c460:	3c018007 */ 	lui	$at,%hi(g_PlayersWithControl)
/*  f01c464:	ac200750 */ 	sw	$zero,%lo(g_PlayersWithControl)($at)
.L0f01c468:
/*  f01c468:	3c198006 */ 	lui	$t9,%hi(var80062940)
/*  f01c46c:	93392940 */ 	lbu	$t9,%lo(var80062940)($t9)
/*  f01c470:	3c148007 */ 	lui	$s4,%hi(var800714d8)
/*  f01c474:	269414d8 */ 	addiu	$s4,$s4,%lo(var800714d8)
/*  f01c478:	5720001b */ 	bnezl	$t9,.L0f01c4e8
/*  f01c47c:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f01c480:	8e6d04b4 */ 	lw	$t5,0x4b4($s3)
/*  f01c484:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01c488:	15a10016 */ 	bne	$t5,$at,.L0f01c4e4
/*  f01c48c:	3c018007 */ 	lui	$at,%hi(g_PlayersWithControl)
/*  f01c490:	ac200750 */ 	sw	$zero,%lo(g_PlayersWithControl)($at)
/*  f01c494:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f01c498:	29c1001f */ 	slti	$at,$t6,0x1f
/*  f01c49c:	54200012 */ 	bnezl	$at,.L0f01c4e8
/*  f01c4a0:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f01c4a4:	8e6f02ac */ 	lw	$t7,0x2ac($s3)
/*  f01c4a8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01c4ac:	3c02800a */ 	lui	$v0,%hi(g_Menus)
/*  f01c4b0:	11e1000c */ 	beq	$t7,$at,.L0f01c4e4
/*  f01c4b4:	2442e000 */ 	addiu	$v0,$v0,%lo(g_Menus)
/*  f01c4b8:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f01c4bc:	a040083c */ 	sb	$zero,0x83c($v0)
/*  f01c4c0:	a04016ac */ 	sb	$zero,0x16ac($v0)
/*  f01c4c4:	a040251c */ 	sb	$zero,0x251c($v0)
/*  f01c4c8:	a040338c */ 	sb	$zero,0x338c($v0)
/*  f01c4cc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f01c4d0:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f01c4d4:	af001a24 */ 	sw	$zero,0x1a24($t8)
/*  f01c4d8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01c4dc:	3c018006 */ 	lui	$at,%hi(var80062940)
/*  f01c4e0:	a0392940 */ 	sb	$t9,%lo(var80062940)($at)
.L0f01c4e4:
/*  f01c4e4:	8ead0000 */ 	lw	$t5,0x0($s5)
.L0f01c4e8:
/*  f01c4e8:	ae600498 */ 	sw	$zero,0x498($s3)
/*  f01c4ec:	19a0018e */ 	blez	$t5,.L0f01cb28
/*  f01c4f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01c4f4:	3c018006 */ 	lui	$at,%hi(var8006294c)
/*  f01c4f8:	a02e294c */ 	sb	$t6,%lo(var8006294c)($at)
/*  f01c4fc:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01c500:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c504:	00008825 */ 	or	$s1,$zero,$zero
/*  f01c508:	10610003 */ 	beq	$v1,$at,.L0f01c518
/*  f01c50c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01c510:	14610023 */ 	bne	$v1,$at,.L0f01c5a0
/*  f01c514:	00000000 */ 	nop
.L0f01c518:
/*  f01c518:	8ea50008 */ 	lw	$a1,0x8($s5)
/*  f01c51c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f01c520:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f01c524:	14c50006 */ 	bne	$a2,$a1,.L0f01c540
/*  f01c528:	3c03800a */ 	lui	$v1,%hi(g_Menus)
/*  f01c52c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f01c530:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f01c534:	948f0016 */ 	lhu	$t7,0x16($a0)
/*  f01c538:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f01c53c:	a4980016 */ 	sh	$t8,0x16($a0)
.L0f01c540:
/*  f01c540:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f01c544:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f01c548:	2463e000 */ 	addiu	$v1,$v1,%lo(g_Menus)
.L0f01c54c:
/*  f01c54c:	8c7904f8 */ 	lw	$t9,0x4f8($v1)
/*  f01c550:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01c554:	5320000c */ 	beqzl	$t9,.L0f01c588
/*  f01c558:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c55c:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f01c560:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f01c564:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*  f01c568:	14c50006 */ 	bne	$a2,$a1,.L0f01c584
/*  f01c56c:	a062083b */ 	sb	$v0,0x83b($v1)
/*  f01c570:	948e0016 */ 	lhu	$t6,0x16($a0)
/*  f01c574:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01c578:	022fc004 */ 	sllv	$t8,$t7,$s1
/*  f01c57c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f01c580:	a4990016 */ 	sh	$t9,0x16($a0)
.L0f01c584:
/*  f01c584:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01c588:
/*  f01c588:	1621fff0 */ 	bne	$s1,$at,.L0f01c54c
/*  f01c58c:	24630e70 */ 	addiu	$v1,$v1,0x0e70
/*  f01c590:	0fc63005 */ 	jal	mpCalculateLockIfLastWinnerOrLoser
/*  f01c594:	00000000 */ 	nop
/*  f01c598:	0fc66d50 */ 	jal	mpPerformSanityChecks
/*  f01c59c:	00000000 */ 	nop
.L0f01c5a0:
/*  f01c5a0:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f01c5a4:	3c05800a */ 	lui	$a1,%hi(g_Menus)
/*  f01c5a8:	3c038008 */ 	lui	$v1,%hi(g_MpReadyMenuDialog)
/*  f01c5ac:	246357b8 */ 	addiu	$v1,$v1,%lo(g_MpReadyMenuDialog)
/*  f01c5b0:	24a5e000 */ 	addiu	$a1,$a1,%lo(g_Menus)
/*  f01c5b4:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
/*  f01c5b8:	00008825 */ 	or	$s1,$zero,$zero
/*  f01c5bc:	24040e70 */ 	addiu	$a0,$zero,0xe70
.L0f01c5c0:
/*  f01c5c0:	02240019 */ 	multu	$s1,$a0
/*  f01c5c4:	acd10000 */ 	sw	$s1,0x0($a2)
/*  f01c5c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c5cc:	2a210004 */ 	slti	$at,$s1,0x4
/*  f01c5d0:	00007812 */ 	mflo	$t7
/*  f01c5d4:	00af7021 */ 	addu	$t6,$a1,$t7
/*  f01c5d8:	8dc204f8 */ 	lw	$v0,0x4f8($t6)
/*  f01c5dc:	10400007 */ 	beqz	$v0,.L0f01c5fc
/*  f01c5e0:	00000000 */ 	nop
/*  f01c5e4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01c5e8:	54780004 */ 	bnel	$v1,$t8,.L0f01c5fc
/*  f01c5ec:	afa00154 */ 	sw	$zero,0x154($sp)
/*  f01c5f0:	10000002 */ 	b	.L0f01c5fc
/*  f01c5f4:	ae760498 */ 	sw	$s6,0x498($s3)
/*  f01c5f8:	afa00154 */ 	sw	$zero,0x154($sp)
.L0f01c5fc:
/*  f01c5fc:	1420fff0 */ 	bnez	$at,.L0f01c5c0
/*  f01c600:	00000000 */ 	nop
/*  f01c604:	3c12800a */ 	lui	$s2,%hi(g_Vars+0x4)
/*  f01c608:	26529fc4 */ 	addiu	$s2,$s2,%lo(g_Vars+0x4)
/*  f01c60c:	00008825 */ 	or	$s1,$zero,$zero
.L0f01c610:
/*  f01c610:	001168c0 */ 	sll	$t5,$s1,0x3
/*  f01c614:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f01c618:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01c61c:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f01c620:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f01c624:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f01c628:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f01c62c:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f01c630:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f01c634:	01af1821 */ 	addu	$v1,$t5,$t7
/*  f01c638:	8c6e04f8 */ 	lw	$t6,0x4f8($v1)
/*  f01c63c:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f01c640:	24c61448 */ 	addiu	$a2,$a2,%lo(g_MpPlayerNum)
/*  f01c644:	11c00025 */ 	beqz	$t6,.L0f01c6dc
/*  f01c648:	acd10000 */ 	sw	$s1,0x0($a2)
/*  f01c64c:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f01c650:	8e70028c */ 	lw	$s0,0x28c($s3)
/*  f01c654:	8e680068 */ 	lw	$t0,0x68($s3)
/*  f01c658:	8e690064 */ 	lw	$t1,0x64($s3)
/*  f01c65c:	13000003 */ 	beqz	$t8,.L0f01c66c
/*  f01c660:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f01c664:	10000002 */ 	b	.L0f01c670
/*  f01c668:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01c66c:
/*  f01c66c:	00003825 */ 	or	$a3,$zero,$zero
.L0f01c670:
/*  f01c670:	11000003 */ 	beqz	$t0,.L0f01c680
/*  f01c674:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c678:	10000001 */ 	b	.L0f01c680
/*  f01c67c:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01c680:
/*  f01c680:	11200003 */ 	beqz	$t1,.L0f01c690
/*  f01c684:	00002825 */ 	or	$a1,$zero,$zero
/*  f01c688:	10000001 */ 	b	.L0f01c690
/*  f01c68c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01c690:
/*  f01c690:	11600003 */ 	beqz	$t3,.L0f01c6a0
/*  f01c694:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c698:	10000001 */ 	b	.L0f01c6a0
/*  f01c69c:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01c6a0:
/*  f01c6a0:	9062083b */ 	lbu	$v0,0x83b($v1)
/*  f01c6a4:	0085c821 */ 	addu	$t9,$a0,$a1
/*  f01c6a8:	03266821 */ 	addu	$t5,$t9,$a2
/*  f01c6ac:	01a77821 */ 	addu	$t7,$t5,$a3
/*  f01c6b0:	004f082a */ 	slt	$at,$v0,$t7
/*  f01c6b4:	10200003 */ 	beqz	$at,.L0f01c6c4
/*  f01c6b8:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01c6bc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01c6c0:	00402025 */ 	or	$a0,$v0,$zero
.L0f01c6c4:
/*  f01c6c4:	0fc3e9c1 */ 	jal	func0f0fa704
/*  f01c6c8:	00000000 */ 	nop
/*  f01c6cc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01c6d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f01c6d4:	10000104 */ 	b	.L0f01cae8
/*  f01c6d8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01c6dc:
/*  f01c6dc:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01c6e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c6e4:	00112600 */ 	sll	$a0,$s1,0x18
/*  f01c6e8:	10610004 */ 	beq	$v1,$at,.L0f01c6fc
/*  f01c6ec:	00047603 */ 	sra	$t6,$a0,0x18
/*  f01c6f0:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01c6f4:	14610092 */ 	bne	$v1,$at,.L0f01c940
/*  f01c6f8:	0271c821 */ 	addu	$t9,$s3,$s1
.L0f01c6fc:
/*  f01c6fc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f01c700:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f01c704:	3405ffff */ 	dli	$a1,0xffff
/*  f01c708:	8eb80004 */ 	lw	$t8,0x4($s5)
/*  f01c70c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01c710:	3050ffff */ 	andi	$s0,$v0,0xffff
/*  f01c714:	17010014 */ 	bne	$t8,$at,.L0f01c768
/*  f01c718:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x88)
/*  f01c71c:	8e790490 */ 	lw	$t9,0x490($s3)
/*  f01c720:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01c724:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01c728:	1721000b */ 	bne	$t9,$at,.L0f01c758
/*  f01c72c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f01c730:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f01c734:	806d0494 */ 	lb	$t5,0x494($v1)
.L0f01c738:
/*  f01c738:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01c73c:	11a00002 */ 	beqz	$t5,.L0f01c748
/*  f01c740:	00000000 */ 	nop
/*  f01c744:	00002025 */ 	or	$a0,$zero,$zero
.L0f01c748:
/*  f01c748:	5472fffb */ 	bnel	$v1,$s2,.L0f01c738
/*  f01c74c:	806d0494 */ 	lb	$t5,0x494($v1)
/*  f01c750:	10000006 */ 	b	.L0f01c76c
/*  f01c754:	00000000 */ 	nop
.L0f01c758:
/*  f01c758:	8e840000 */ 	lw	$a0,0x0($s4)
/*  f01c75c:	2c8f0002 */ 	sltiu	$t7,$a0,0x2
/*  f01c760:	10000002 */ 	b	.L0f01c76c
/*  f01c764:	01e02025 */ 	or	$a0,$t7,$zero
.L0f01c768:
/*  f01c768:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01c76c:
/*  f01c76c:	91cecc10 */ 	lbu	$t6,%lo(g_MpSetup+0x88)($t6)
/*  f01c770:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01c774:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f01c778:	15c10005 */ 	bne	$t6,$at,.L0f01c790
/*  f01c77c:	0311c021 */ 	addu	$t8,$t8,$s1
/*  f01c780:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f01c784:	3c01800b */ 	lui	$at,%hi(g_MpPlayers+0x11)
/*  f01c788:	00380821 */ 	addu	$at,$at,$t8
/*  f01c78c:	a020c7c9 */ 	sb	$zero,%lo(g_MpPlayers+0x11)($at)
.L0f01c790:
/*  f01c790:	1080003b */ 	beqz	$a0,.L0f01c880
/*  f01c794:	30591000 */ 	andi	$t9,$v0,0x1000
/*  f01c798:	13200039 */ 	beqz	$t9,.L0f01c880
/*  f01c79c:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f01c7a0:	00117880 */ 	sll	$t7,$s1,0x2
/*  f01c7a4:	01f17821 */ 	addu	$t7,$t7,$s1
/*  f01c7a8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f01c7ac:	3c01800b */ 	lui	$at,%hi(g_MpPlayers+0x9d)
/*  f01c7b0:	002f0821 */ 	addu	$at,$at,$t7
/*  f01c7b4:	a02dc855 */ 	sb	$t5,%lo(g_MpPlayers+0x9d)($at)
/*  f01c7b8:	8e630490 */ 	lw	$v1,0x490($s3)
/*  f01c7bc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01c7c0:	02714021 */ 	addu	$t0,$s3,$s1
/*  f01c7c4:	54610017 */ 	bnel	$v1,$at,.L0f01c824
/*  f01c7c8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c7cc:	810e0494 */ 	lb	$t6,0x494($t0)
/*  f01c7d0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f01c7d4:	2405809a */ 	addiu	$a1,$zero,-32614
/*  f01c7d8:	15c0000f */ 	bnez	$t6,.L0f01c818
/*  f01c7dc:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c7e0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f01c7e4:	44819000 */ 	mtc1	$at,$f18
/*  f01c7e8:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f01c7ec:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01c7f0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01c7f4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f01c7f8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f01c7fc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f01c800:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f01c804:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01c808:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c80c:	0c004241 */ 	jal	audioStart
/*  f01c810:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f01c814:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c818:
/*  f01c818:	10000019 */ 	b	.L0f01c880
/*  f01c81c:	a1160494 */ 	sb	$s6,0x494($t0)
/*  f01c820:	24010003 */ 	addiu	$at,$zero,0x3
.L0f01c824:
/*  f01c824:	14610012 */ 	bne	$v1,$at,.L0f01c870
/*  f01c828:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f01c82c:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f01c830:	ae8f0000 */ 	sw	$t7,0x0($s4)
/*  f01c834:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f01c838:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f01c83c:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f01c840:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c844:	16ce0006 */ 	bne	$s6,$t6,.L0f01c860
/*  f01c848:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f01c84c:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f01c850:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c854:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f01c858:	1000000a */ 	b	.L0f01c884
/*  f01c85c:	32191000 */ 	andi	$t9,$s0,0x1000
.L0f01c860:
/*  f01c860:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c864:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c868:	10000006 */ 	b	.L0f01c884
/*  f01c86c:	32191000 */ 	andi	$t9,$s0,0x1000
.L0f01c870:
/*  f01c870:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f01c874:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f01c878:	0fc5ff2c */ 	jal	func0f17fcb0
/*  f01c87c:	00002025 */ 	or	$a0,$zero,$zero
.L0f01c880:
/*  f01c880:	32191000 */ 	andi	$t9,$s0,0x1000
.L0f01c884:
/*  f01c884:	1720002c */ 	bnez	$t9,.L0f01c938
/*  f01c888:	320d4000 */ 	andi	$t5,$s0,0x4000
/*  f01c88c:	11a00008 */ 	beqz	$t5,.L0f01c8b0
/*  f01c890:	02714021 */ 	addu	$t0,$s3,$s1
/*  f01c894:	8e6f0490 */ 	lw	$t7,0x490($s3)
/*  f01c898:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01c89c:	02717021 */ 	addu	$t6,$s3,$s1
/*  f01c8a0:	15e10025 */ 	bne	$t7,$at,.L0f01c938
/*  f01c8a4:	00000000 */ 	nop
/*  f01c8a8:	10000023 */ 	b	.L0f01c938
/*  f01c8ac:	a1c00494 */ 	sb	$zero,0x494($t6)
.L0f01c8b0:
/*  f01c8b0:	81180494 */ 	lb	$t8,0x494($t0)
/*  f01c8b4:	13000020 */ 	beqz	$t8,.L0f01c938
/*  f01c8b8:	00000000 */ 	nop
/*  f01c8bc:	8e630490 */ 	lw	$v1,0x490($s3)
/*  f01c8c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c8c4:	14610014 */ 	bne	$v1,$at,.L0f01c918
/*  f01c8c8:	00000000 */ 	nop
/*  f01c8cc:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f01c8d0:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c8d4:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f01c8d8:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f01c8dc:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*  f01c8e0:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f01c8e4:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f01c8e8:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c8ec:	16cf0006 */ 	bne	$s6,$t7,.L0f01c908
/*  f01c8f0:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f01c8f4:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f01c8f8:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c8fc:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f01c900:	1000000d */ 	b	.L0f01c938
/*  f01c904:	00000000 */ 	nop
.L0f01c908:
/*  f01c908:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01c90c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c910:	10000009 */ 	b	.L0f01c938
/*  f01c914:	00000000 */ 	nop
.L0f01c918:
/*  f01c918:	16c30007 */ 	bne	$s6,$v1,.L0f01c938
/*  f01c91c:	00000000 */ 	nop
/*  f01c920:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f01c924:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c928:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c92c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f01c930:	0fc5ff2c */ 	jal	func0f17fcb0
/*  f01c934:	ae980000 */ 	sw	$t8,0x0($s4)
.L0f01c938:
/*  f01c938:	10000003 */ 	b	.L0f01c948
/*  f01c93c:	8ea30004 */ 	lw	$v1,0x4($s5)
.L0f01c940:
/*  f01c940:	ae600490 */ 	sw	$zero,0x490($s3)
/*  f01c944:	a3200494 */ 	sb	$zero,0x494($t9)
.L0f01c948:
/*  f01c948:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01c94c:	14610065 */ 	bne	$v1,$at,.L0f01cae4
/*  f01c950:	00116880 */ 	sll	$t5,$s1,0x2
/*  f01c954:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f01c958:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f01c95c:	3c04800b */ 	lui	$a0,%hi(g_MpPlayers+0x45)
/*  f01c960:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f01c964:	8084c7fd */ 	lb	$a0,%lo(g_MpPlayers+0x45)($a0)
/*  f01c968:	0c005408 */ 	jal	contGetButtonsPressedThisFrame
/*  f01c96c:	3405ffff */ 	dli	$a1,0xffff
/*  f01c970:	304f4000 */ 	andi	$t7,$v0,0x4000
/*  f01c974:	51e0005c */ 	beqzl	$t7,.L0f01cae8
/*  f01c978:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c97c:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f01c980:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f01c984:	00001825 */ 	or	$v1,$zero,$zero
/*  f01c988:	11400003 */ 	beqz	$t2,.L0f01c998
/*  f01c98c:	00003825 */ 	or	$a3,$zero,$zero
/*  f01c990:	10000001 */ 	b	.L0f01c998
/*  f01c994:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01c998:
/*  f01c998:	8e680068 */ 	lw	$t0,0x68($s3)
/*  f01c99c:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c9a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f01c9a4:	11000003 */ 	beqz	$t0,.L0f01c9b4
/*  f01c9a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c9ac:	10000001 */ 	b	.L0f01c9b4
/*  f01c9b0:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01c9b4:
/*  f01c9b4:	8e690064 */ 	lw	$t1,0x64($s3)
/*  f01c9b8:	000369c0 */ 	sll	$t5,$v1,0x7
/*  f01c9bc:	026d1021 */ 	addu	$v0,$s3,$t5
/*  f01c9c0:	11200003 */ 	beqz	$t1,.L0f01c9d0
/*  f01c9c4:	00000000 */ 	nop
/*  f01c9c8:	10000001 */ 	b	.L0f01c9d0
/*  f01c9cc:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01c9d0:
/*  f01c9d0:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f01c9d4:	11600003 */ 	beqz	$t3,.L0f01c9e4
/*  f01c9d8:	00000000 */ 	nop
/*  f01c9dc:	10000001 */ 	b	.L0f01c9e4
/*  f01c9e0:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01c9e4:
/*  f01c9e4:	00857021 */ 	addu	$t6,$a0,$a1
/*  f01c9e8:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f01c9ec:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f01c9f0:	1b20001d */ 	blez	$t9,.L0f01ca68
/*  f01c9f4:	00000000 */ 	nop
/*  f01c9f8:	8c4f00e4 */ 	lw	$t7,0xe4($v0)
.L0f01c9fc:
/*  f01c9fc:	24420080 */ 	addiu	$v0,$v0,0x80
/*  f01ca00:	00003825 */ 	or	$a3,$zero,$zero
/*  f01ca04:	162f0002 */ 	bne	$s1,$t7,.L0f01ca10
/*  f01ca08:	00003025 */ 	or	$a2,$zero,$zero
/*  f01ca0c:	00608025 */ 	or	$s0,$v1,$zero
.L0f01ca10:
/*  f01ca10:	11400003 */ 	beqz	$t2,.L0f01ca20
/*  f01ca14:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01ca18:	10000001 */ 	b	.L0f01ca20
/*  f01ca1c:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01ca20:
/*  f01ca20:	11000003 */ 	beqz	$t0,.L0f01ca30
/*  f01ca24:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ca28:	10000001 */ 	b	.L0f01ca30
/*  f01ca2c:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01ca30:
/*  f01ca30:	11200003 */ 	beqz	$t1,.L0f01ca40
/*  f01ca34:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ca38:	10000001 */ 	b	.L0f01ca40
/*  f01ca3c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01ca40:
/*  f01ca40:	11600003 */ 	beqz	$t3,.L0f01ca50
/*  f01ca44:	00000000 */ 	nop
/*  f01ca48:	10000001 */ 	b	.L0f01ca50
/*  f01ca4c:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01ca50:
/*  f01ca50:	00857021 */ 	addu	$t6,$a0,$a1
/*  f01ca54:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f01ca58:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f01ca5c:	0079082a */ 	slt	$at,$v1,$t9
/*  f01ca60:	5420ffe6 */ 	bnezl	$at,.L0f01c9fc
/*  f01ca64:	8c4f00e4 */ 	lw	$t7,0xe4($v0)
.L0f01ca68:
/*  f01ca68:	0602001f */ 	bltzl	$s0,.L0f01cae8
/*  f01ca6c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01ca70:	8e6d0298 */ 	lw	$t5,0x298($s3)
/*  f01ca74:	05a2000c */ 	bltzl	$t5,.L0f01caa8
/*  f01ca78:	8e6e029c */ 	lw	$t6,0x29c($s3)
/*  f01ca7c:	8e6f028c */ 	lw	$t7,0x28c($s3)
/*  f01ca80:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ca84:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ca88:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f01ca8c:	0fc43b2d */ 	jal	soloPushCoopModeEndscreen
/*  f01ca90:	00000000 */ 	nop
/*  f01ca94:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ca98:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f01ca9c:	10000012 */ 	b	.L0f01cae8
/*  f01caa0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01caa4:	8e6e029c */ 	lw	$t6,0x29c($s3)
.L0f01caa8:
/*  f01caa8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01caac:	05c0000b */ 	bltz	$t6,.L0f01cadc
/*  f01cab0:	00000000 */ 	nop
/*  f01cab4:	8e78028c */ 	lw	$t8,0x28c($s3)
/*  f01cab8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cabc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cac0:	afb80124 */ 	sw	$t8,0x124($sp)
/*  f01cac4:	0fc43bc4 */ 	jal	soloPushAntiModeEndscreen
/*  f01cac8:	00000000 */ 	nop
/*  f01cacc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cad0:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f01cad4:	10000004 */ 	b	.L0f01cae8
/*  f01cad8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01cadc:
/*  f01cadc:	0fc5e3bc */ 	jal	mpPushEndscreenDialog
/*  f01cae0:	02202825 */ 	or	$a1,$s1,$zero
.L0f01cae4:
/*  f01cae4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01cae8:
/*  f01cae8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01caec:	1621fec8 */ 	bne	$s1,$at,.L0f01c610
/*  f01caf0:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f01caf4:	1320000e */ 	beqz	$t9,.L0f01cb30
/*  f01caf8:	00000000 */ 	nop
/*  f01cafc:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cb00:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cb04:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cb08:	10610003 */ 	beq	$v1,$at,.L0f01cb18
/*  f01cb0c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cb10:	14610007 */ 	bne	$v1,$at,.L0f01cb30
/*  f01cb14:	00000000 */ 	nop
.L0f01cb18:
/*  f01cb18:	0fc3e083 */ 	jal	func0f0f820c
/*  f01cb1c:	2405fffb */ 	addiu	$a1,$zero,-5
/*  f01cb20:	10000003 */ 	b	.L0f01cb30
/*  f01cb24:	00000000 */ 	nop
.L0f01cb28:
/*  f01cb28:	3c018006 */ 	lui	$at,%hi(var8006294c)
/*  f01cb2c:	a020294c */ 	sb	$zero,%lo(var8006294c)($at)
.L0f01cb30:
/*  f01cb30:	3c0d8006 */ 	lui	$t5,%hi(var8006294c)
/*  f01cb34:	91ad294c */ 	lbu	$t5,%lo(var8006294c)($t5)
/*  f01cb38:	11a0001b */ 	beqz	$t5,.L0f01cba8
/*  f01cb3c:	3c028006 */ 	lui	$v0,%hi(var80062948)
/*  f01cb40:	24422948 */ 	addiu	$v0,$v0,%lo(var80062948)
/*  f01cb44:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f01cb48:	15e0000f */ 	bnez	$t7,.L0f01cb88
/*  f01cb4c:	00000000 */ 	nop
/*  f01cb50:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cb54:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cb58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01cb5c:	10610004 */ 	beq	$v1,$at,.L0f01cb70
/*  f01cb60:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cb64:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cb68:	14610007 */ 	bne	$v1,$at,.L0f01cb88
/*  f01cb6c:	00000000 */ 	nop
.L0f01cb70:
/*  f01cb70:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f01cb74:	0fc44317 */ 	jal	func0f110c5c
/*  f01cb78:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f01cb7c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01cb80:	0fc44317 */ 	jal	func0f110c5c
/*  f01cb84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01cb88:
/*  f01cb88:	3c188006 */ 	lui	$t8,%hi(var80062944)
/*  f01cb8c:	93182944 */ 	lbu	$t8,%lo(var80062944)($t8)
/*  f01cb90:	1300000b */ 	beqz	$t8,.L0f01cbc0
/*  f01cb94:	00000000 */ 	nop
/*  f01cb98:	0fc4436a */ 	jal	func0f110da8
/*  f01cb9c:	00000000 */ 	nop
/*  f01cba0:	10000007 */ 	b	.L0f01cbc0
/*  f01cba4:	00000000 */ 	nop
.L0f01cba8:
/*  f01cba8:	3c198006 */ 	lui	$t9,%hi(var80062944)
/*  f01cbac:	93392944 */ 	lbu	$t9,%lo(var80062944)($t9)
/*  f01cbb0:	16d90003 */ 	bne	$s6,$t9,.L0f01cbc0
/*  f01cbb4:	00000000 */ 	nop
/*  f01cbb8:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cbbc:	00000000 */ 	nop
.L0f01cbc0:
/*  f01cbc0:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f01cbc4:	3c03800a */ 	lui	$v1,%hi(g_Menus)
/*  f01cbc8:	3c02800a */ 	lui	$v0,%hi(g_MenuData)
/*  f01cbcc:	ac201448 */ 	sw	$zero,%lo(g_MpPlayerNum)($at)
/*  f01cbd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cbd4:	244219c0 */ 	addiu	$v0,$v0,%lo(g_MenuData)
/*  f01cbd8:	2463e000 */ 	addiu	$v1,$v1,%lo(g_Menus)
/*  f01cbdc:	8c6d04f8 */ 	lw	$t5,0x4f8($v1)
.L0f01cbe0:
/*  f01cbe0:	24630e70 */ 	addiu	$v1,$v1,0x0e70
/*  f01cbe4:	0062082b */ 	sltu	$at,$v1,$v0
/*  f01cbe8:	11a00002 */ 	beqz	$t5,.L0f01cbf4
/*  f01cbec:	00000000 */ 	nop
/*  f01cbf0:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01cbf4:
/*  f01cbf4:	5420fffa */ 	bnezl	$at,.L0f01cbe0
/*  f01cbf8:	8c6d04f8 */ 	lw	$t5,0x4f8($v1)
/*  f01cbfc:	8eaf05d4 */ 	lw	$t7,0x5d4($s5)
/*  f01cc00:	000fc340 */ 	sll	$t8,$t7,0xd
/*  f01cc04:	07000006 */ 	bltz	$t8,.L0f01cc20
/*  f01cc08:	00000000 */ 	nop
/*  f01cc0c:	8eb90008 */ 	lw	$t9,0x8($s5)
/*  f01cc10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01cc14:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cc18:	132101df */ 	beq	$t9,$at,.L0f01d398
/*  f01cc1c:	00000000 */ 	nop
.L0f01cc20:
/*  f01cc20:	148001dd */ 	bnez	$a0,.L0f01d398
/*  f01cc24:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cc28:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cc2c:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f01cc30:	8ea50008 */ 	lw	$a1,0x8($s5)
/*  f01cc34:	10430002 */ 	beq	$v0,$v1,.L0f01cc40
/*  f01cc38:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cc3c:	14610022 */ 	bne	$v1,$at,.L0f01ccc8
.L0f01cc40:
/*  f01cc40:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01cc44:	54a10021 */ 	bnel	$a1,$at,.L0f01cccc
/*  f01cc48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01cc4c:	8e6d0490 */ 	lw	$t5,0x490($s3)
/*  f01cc50:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01cc54:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f01cc58:	15a1000d */ 	bne	$t5,$at,.L0f01cc90
/*  f01cc5c:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f01cc60:	aeaf0008 */ 	sw	$t7,0x8($s5)
/*  f01cc64:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f01cc68:	3c198007 */ 	lui	$t9,%hi(g_MainMenuMenuDialog)
/*  f01cc6c:	27393a5c */ 	addiu	$t9,$t9,%lo(g_MainMenuMenuDialog)
/*  f01cc70:	16ce0004 */ 	bne	$s6,$t6,.L0f01cc84
/*  f01cc74:	3c188007 */ 	lui	$t8,%hi(g_CiMainMenuDialogViaPause)
/*  f01cc78:	27183a74 */ 	addiu	$t8,$t8,%lo(g_CiMainMenuDialogViaPause)
/*  f01cc7c:	10000002 */ 	b	.L0f01cc88
/*  f01cc80:	aeb8000c */ 	sw	$t8,0xc($s5)
.L0f01cc84:
/*  f01cc84:	aeb9000c */ 	sw	$t9,0xc($s5)
.L0f01cc88:
/*  f01cc88:	1000000f */ 	b	.L0f01ccc8
/*  f01cc8c:	8ea50008 */ 	lw	$a1,0x8($s5)
.L0f01cc90:
/*  f01cc90:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f01cc94:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f01cc98:	3c188008 */ 	lui	$t8,%hi(g_CombatSimulatorMenuDialog)
/*  f01cc9c:	271867a0 */ 	addiu	$t8,$t8,%lo(g_CombatSimulatorMenuDialog)
/*  f01cca0:	16cd0007 */ 	bne	$s6,$t5,.L0f01ccc0
/*  f01cca4:	00402825 */ 	or	$a1,$v0,$zero
/*  f01cca8:	3c0e8007 */ 	lui	$t6,%hi(g_4MbMainMenu)
/*  f01ccac:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01ccb0:	25ce5294 */ 	addiu	$t6,$t6,%lo(g_4MbMainMenu)
/*  f01ccb4:	aea50008 */ 	sw	$a1,0x8($s5)
/*  f01ccb8:	10000003 */ 	b	.L0f01ccc8
/*  f01ccbc:	aeae000c */ 	sw	$t6,0xc($s5)
.L0f01ccc0:
/*  f01ccc0:	aea20008 */ 	sw	$v0,0x8($s5)
/*  f01ccc4:	aeb8000c */ 	sw	$t8,0xc($s5)
.L0f01ccc8:
/*  f01ccc8:	2401ffff */ 	addiu	$at,$zero,-1
.L0f01cccc:
/*  f01cccc:	10a100d7 */ 	beq	$a1,$at,.L0f01d02c
/*  f01ccd0:	2401fffb */ 	addiu	$at,$zero,-5
/*  f01ccd4:	54a10011 */ 	bnel	$a1,$at,.L0f01cd1c
/*  f01ccd8:	2401fffa */ 	addiu	$at,$zero,-6
/*  f01ccdc:	0fc61e19 */ 	jal	mpStartMatch
/*  f01cce0:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cce4:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cce8:	00000000 */ 	nop
/*  f01ccec:	8e790458 */ 	lw	$t9,0x458($s3)
/*  f01ccf0:	332d0002 */ 	andi	$t5,$t9,0x2
/*  f01ccf4:	51a000ca */ 	beqzl	$t5,.L0f01d020
/*  f01ccf8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01ccfc:	0fc44270 */ 	jal	func0f1109c0
/*  f01cd00:	00000000 */ 	nop
/*  f01cd04:	8e6f0458 */ 	lw	$t7,0x458($s3)
/*  f01cd08:	2401fffd */ 	addiu	$at,$zero,-3
/*  f01cd0c:	01e17024 */ 	and	$t6,$t7,$at
/*  f01cd10:	100000c2 */ 	b	.L0f01d01c
/*  f01cd14:	ae6e0458 */ 	sw	$t6,0x458($s3)
/*  f01cd18:	2401fffa */ 	addiu	$at,$zero,-6
.L0f01cd1c:
/*  f01cd1c:	54a10065 */ 	bnel	$a1,$at,.L0f01ceb4
/*  f01cd20:	2401fff9 */ 	addiu	$at,$zero,-7
/*  f01cd24:	8e780318 */ 	lw	$t8,0x318($s3)
/*  f01cd28:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f01cd2c:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cd30:	13000003 */ 	beqz	$t8,.L0f01cd40
/*  f01cd34:	00000000 */ 	nop
/*  f01cd38:	0fc3f552 */ 	jal	func0f0fd548
/*  f01cd3c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f01cd40:
/*  f01cd40:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01cd44:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01cd48:	00008825 */ 	or	$s1,$zero,$zero
/*  f01cd4c:	24140038 */ 	addiu	$s4,$zero,0x38
.L0f01cd50:
/*  f01cd50:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0x16)
/*  f01cd54:	9739cb9e */ 	lhu	$t9,%lo(g_MpSetup+0x16)($t9)
/*  f01cd58:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01cd5c:	022d7804 */ 	sllv	$t7,$t5,$s1
/*  f01cd60:	032f7024 */ 	and	$t6,$t9,$t7
/*  f01cd64:	51c0004d */ 	beqzl	$t6,.L0f01ce9c
/*  f01cd68:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01cd6c:	8e780298 */ 	lw	$t8,0x298($s3)
/*  f01cd70:	07020027 */ 	bltzl	$t8,.L0f01ce10
/*  f01cd74:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f01cd78:	8e6d04b4 */ 	lw	$t5,0x4b4($s3)
/*  f01cd7c:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f01cd80:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01cd84:	568d0019 */ 	bnel	$s4,$t5,.L0f01cdec
/*  f01cd88:	8e70028c */ 	lw	$s0,0x28c($s3)
/*  f01cd8c:	92590002 */ 	lbu	$t9,0x2($s2)
/*  f01cd90:	3c0d8007 */ 	lui	$t5,%hi(g_StageNames)
/*  f01cd94:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f01cd98:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f01cd9c:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f01cda0:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f01cda4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f01cda8:	a24f0002 */ 	sb	$t7,0x2($s2)
/*  f01cdac:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01cdb0:	8dad1e6c */ 	lw	$t5,%lo(g_StageNames)($t5)
/*  f01cdb4:	a24d0001 */ 	sb	$t5,0x1($s2)
/*  f01cdb8:	0fc06c55 */ 	jal	titleSetNextStage
/*  f01cdbc:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f01cdc0:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f01cdc4:	0004ce42 */ 	srl	$t9,$a0,0x19
/*  f01cdc8:	0fc5b36a */ 	jal	coreSetDifficulty
/*  f01cdcc:	03202025 */ 	or	$a0,$t9,$zero
/*  f01cdd0:	0fc069f9 */ 	jal	titleSetNextMode
/*  f01cdd4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01cdd8:	0c003a57 */ 	jal	mainSetStageNum
/*  f01cddc:	92440001 */ 	lbu	$a0,0x1($s2)
/*  f01cde0:	1000002b */ 	b	.L0f01ce90
/*  f01cde4:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f01cde8:	8e70028c */ 	lw	$s0,0x28c($s3)
.L0f01cdec:
/*  f01cdec:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cdf0:	afaf0158 */ 	sw	$t7,0x158($sp)
/*  f01cdf4:	0fc43b2d */ 	jal	soloPushCoopModeEndscreen
/*  f01cdf8:	00000000 */ 	nop
/*  f01cdfc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ce00:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ce04:	10000022 */ 	b	.L0f01ce90
/*  f01ce08:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f01ce0c:	8e78029c */ 	lw	$t8,0x29c($s3)
.L0f01ce10:
/*  f01ce10:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01ce14:	afae0158 */ 	sw	$t6,0x158($sp)
/*  f01ce18:	0700000a */ 	bltz	$t8,.L0f01ce44
/*  f01ce1c:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f01ce20:	8e70028c */ 	lw	$s0,0x28c($s3)
/*  f01ce24:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ce28:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f01ce2c:	0fc43bc4 */ 	jal	soloPushAntiModeEndscreen
/*  f01ce30:	00000000 */ 	nop
/*  f01ce34:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ce38:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ce3c:	10000014 */ 	b	.L0f01ce90
/*  f01ce40:	8fb80120 */ 	lw	$t8,0x120($sp)
.L0f01ce44:
/*  f01ce44:	00116880 */ 	sll	$t5,$s1,0x2
/*  f01ce48:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f01ce4c:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f01ce50:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f01ce54:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f01ce58:	01b91021 */ 	addu	$v0,$t5,$t9
/*  f01ce5c:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f01ce60:	0fc5e3bc */ 	jal	mpPushEndscreenDialog
/*  f01ce64:	02202825 */ 	or	$a1,$s1,$zero
/*  f01ce68:	8fa20058 */ 	lw	$v0,0x58($sp)
/*  f01ce6c:	8c4f004c */ 	lw	$t7,0x4c($v0)
/*  f01ce70:	51e00007 */ 	beqzl	$t7,.L0f01ce90
/*  f01ce74:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f01ce78:	944e0050 */ 	lhu	$t6,0x50($v0)
/*  f01ce7c:	51c00004 */ 	beqzl	$t6,.L0f01ce90
/*  f01ce80:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f01ce84:	0fc3f552 */ 	jal	func0f0fd548
/*  f01ce88:	02202025 */ 	or	$a0,$s1,$zero
/*  f01ce8c:	8fb80120 */ 	lw	$t8,0x120($sp)
.L0f01ce90:
/*  f01ce90:	270d0001 */ 	addiu	$t5,$t8,0x1
/*  f01ce94:	afad0120 */ 	sw	$t5,0x120($sp)
/*  f01ce98:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01ce9c:
/*  f01ce9c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01cea0:	1621ffab */ 	bne	$s1,$at,.L0f01cd50
/*  f01cea4:	00000000 */ 	nop
/*  f01cea8:	1000005d */ 	b	.L0f01d020
/*  f01ceac:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01ceb0:	2401fff9 */ 	addiu	$at,$zero,-7
.L0f01ceb4:
/*  f01ceb4:	14a10019 */ 	bne	$a1,$at,.L0f01cf1c
/*  f01ceb8:	00008025 */ 	or	$s0,$zero,$zero
/*  f01cebc:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cec0:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cec4:	3c10800a */ 	lui	$s0,%hi(g_SoloSaveFile)
/*  f01cec8:	26102200 */ 	addiu	$s0,$s0,%lo(g_SoloSaveFile)
/*  f01cecc:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f01ced0:	3c018006 */ 	lui	$at,%hi(var80062940)
/*  f01ced4:	a0392940 */ 	sb	$t9,%lo(var80062940)($at)
/*  f01ced8:	0fc43da6 */ 	jal	savefileLoadDefaults
/*  f01cedc:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cee0:	0fc43c81 */ 	jal	savefileApplyOptions
/*  f01cee4:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cee8:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f01ceec:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f01cef0:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01cef4:	16cf0003 */ 	bne	$s6,$t7,.L0f01cf04
/*  f01cef8:	00000000 */ 	nop
/*  f01cefc:	10000001 */ 	b	.L0f01cf04
/*  f01cf00:	2404005d */ 	addiu	$a0,$zero,0x5d
.L0f01cf04:
/*  f01cf04:	0c003a57 */ 	jal	mainSetStageNum
/*  f01cf08:	00000000 */ 	nop
/*  f01cf0c:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f01cf10:	00000000 */ 	nop
/*  f01cf14:	10000042 */ 	b	.L0f01d020
/*  f01cf18:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f01cf1c:
/*  f01cf1c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01cf20:	afae0158 */ 	sw	$t6,0x158($sp)
/*  f01cf24:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f01cf28:	8ea4000c */ 	lw	$a0,0xc($s5)
/*  f01cf2c:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cf30:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cf34:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f01cf38:	10610003 */ 	beq	$v1,$at,.L0f01cf48
/*  f01cf3c:	24058098 */ 	addiu	$a1,$zero,-32616
/*  f01cf40:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cf44:	1461000f */ 	bne	$v1,$at,.L0f01cf84
.L0f01cf48:
/*  f01cf48:	3c01bf80 */ 	lui	$at,0xbf80
/*  f01cf4c:	44812000 */ 	mtc1	$at,$f4
/*  f01cf50:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f01cf54:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01cf58:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01cf5c:	02c08025 */ 	or	$s0,$s6,$zero
/*  f01cf60:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f01cf64:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f01cf68:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f01cf6c:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f01cf70:	00003025 */ 	or	$a2,$zero,$zero
/*  f01cf74:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01cf78:	0c004241 */ 	jal	audioStart
/*  f01cf7c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f01cf80:	8ea30004 */ 	lw	$v1,0x4($s5)
.L0f01cf84:
/*  f01cf84:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01cf88:	10610003 */ 	beq	$v1,$at,.L0f01cf98
/*  f01cf8c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f01cf90:	1461001e */ 	bne	$v1,$at,.L0f01d00c
/*  f01cf94:	00000000 */ 	nop
.L0f01cf98:
/*  f01cf98:	0fc68606 */ 	jal	dtGetData
/*  f01cf9c:	00000000 */ 	nop
/*  f01cfa0:	8e6304b4 */ 	lw	$v1,0x4b4($s3)
/*  f01cfa4:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01cfa8:	10610003 */ 	beq	$v1,$at,.L0f01cfb8
/*  f01cfac:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f01cfb0:	54610016 */ 	bnel	$v1,$at,.L0f01d00c
/*  f01cfb4:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01cfb8:
/*  f01cfb8:	8e6f0284 */ 	lw	$t7,0x284($s3)
/*  f01cfbc:	8dee00bc */ 	lw	$t6,0xbc($t7)
/*  f01cfc0:	85c30028 */ 	lh	$v1,0x28($t6)
/*  f01cfc4:	28610016 */ 	slti	$at,$v1,0x16
/*  f01cfc8:	14200002 */ 	bnez	$at,.L0f01cfd4
/*  f01cfcc:	2861001a */ 	slti	$at,$v1,0x1a
/*  f01cfd0:	1420000b */ 	bnez	$at,.L0f01d000
.L0f01cfd4:
/*  f01cfd4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f01cfd8:	10610009 */ 	beq	$v1,$at,.L0f01d000
/*  f01cfdc:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f01cfe0:	10610007 */ 	beq	$v1,$at,.L0f01d000
/*  f01cfe4:	00000000 */ 	nop
/*  f01cfe8:	50400008 */ 	beqzl	$v0,.L0f01d00c
/*  f01cfec:	02c08025 */ 	or	$s0,$s6,$zero
/*  f01cff0:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01cff4:	00186fc2 */ 	srl	$t5,$t8,0x1f
/*  f01cff8:	51a00004 */ 	beqzl	$t5,.L0f01d00c
/*  f01cffc:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01d000:
/*  f01d000:	10000002 */ 	b	.L0f01d00c
/*  f01d004:	00008025 */ 	or	$s0,$zero,$zero
/*  f01d008:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01d00c:
/*  f01d00c:	52000004 */ 	beqzl	$s0,.L0f01d020
/*  f01d010:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01d014:	0fc5b6c5 */ 	jal	musicStartForMenu
/*  f01d018:	00000000 */ 	nop
.L0f01d01c:
/*  f01d01c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f01d020:
/*  f01d020:	aea0000c */ 	sw	$zero,0xc($s5)
/*  f01d024:	100000dc */ 	b	.L0f01d398
/*  f01d028:	aeb90008 */ 	sw	$t9,0x8($s5)
.L0f01d02c:
/*  f01d02c:	1076000a */ 	beq	$v1,$s6,.L0f01d058
/*  f01d030:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01d034:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01d038:	106100d7 */ 	beq	$v1,$at,.L0f01d398
/*  f01d03c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01d040:	10610012 */ 	beq	$v1,$at,.L0f01d08c
/*  f01d044:	24010009 */ 	addiu	$at,$zero,0x9
/*  f01d048:	506100bf */ 	beql	$v1,$at,.L0f01d348
/*  f01d04c:	8e6d0298 */ 	lw	$t5,0x298($s3)
/*  f01d050:	100000d1 */ 	b	.L0f01d398
/*  f01d054:	00000000 */ 	nop
.L0f01d058:
/*  f01d058:	8e6f046c */ 	lw	$t7,0x46c($s3)
/*  f01d05c:	11e00007 */ 	beqz	$t7,.L0f01d07c
/*  f01d060:	00000000 */ 	nop
/*  f01d064:	0c003a61 */ 	jal	mainGetStageNum
/*  f01d068:	00000000 */ 	nop
/*  f01d06c:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d070:	00402025 */ 	or	$a0,$v0,$zero
/*  f01d074:	100000c8 */ 	b	.L0f01d398
/*  f01d078:	00000000 */ 	nop
.L0f01d07c:
/*  f01d07c:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d080:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f01d084:	100000c4 */ 	b	.L0f01d398
/*  f01d088:	00000000 */ 	nop
.L0f01d08c:
/*  f01d08c:	8e6e0318 */ 	lw	$t6,0x318($s3)
/*  f01d090:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01d094:	3c018008 */ 	lui	$at,%hi(var80087260)
/*  f01d098:	11c00004 */ 	beqz	$t6,.L0f01d0ac
/*  f01d09c:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01d0a0:	ac227260 */ 	sw	$v0,%lo(var80087260)($at)
/*  f01d0a4:	10000062 */ 	b	.L0f01d230
/*  f01d0a8:	8e630298 */ 	lw	$v1,0x298($s3)
.L0f01d0ac:
/*  f01d0ac:	8e630298 */ 	lw	$v1,0x298($s3)
/*  f01d0b0:	3c04800b */ 	lui	$a0,%hi(g_MpPlayers+0x280)
/*  f01d0b4:	2484ca38 */ 	addiu	$a0,$a0,%lo(g_MpPlayers+0x280)
/*  f01d0b8:	04610003 */ 	bgez	$v1,.L0f01d0c8
/*  f01d0bc:	27a20070 */ 	addiu	$v0,$sp,0x70
/*  f01d0c0:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f01d0c4:	0700005a */ 	bltz	$t8,.L0f01d230
.L0f01d0c8:
/*  f01d0c8:	3c05800b */ 	lui	$a1,%hi(g_MpPlayers+0x320)
/*  f01d0cc:	3c06800b */ 	lui	$a2,%hi(g_MpPlayers+0xa0)
/*  f01d0d0:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f01d0d4:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f01d0d8:	24c6c858 */ 	addiu	$a2,$a2,%lo(g_MpPlayers+0xa0)
/*  f01d0dc:	24a5cad8 */ 	addiu	$a1,$a1,%lo(g_MpPlayers+0x320)
/*  f01d0e0:	00807825 */ 	or	$t7,$a0,$zero
/*  f01d0e4:	00407025 */ 	or	$t6,$v0,$zero
/*  f01d0e8:	2499009c */ 	addiu	$t9,$a0,0x9c
.L0f01d0ec:
/*  f01d0ec:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01d0f0:	25ef000c */ 	addiu	$t7,$t7,12
/*  f01d0f4:	25ce000c */ 	addiu	$t6,$t6,12
/*  f01d0f8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f01d0fc:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f01d100:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f01d104:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f01d108:	15f9fff8 */ 	bne	$t7,$t9,.L0f01d0ec
/*  f01d10c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f01d110:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01d114:	00807825 */ 	or	$t7,$a0,$zero
/*  f01d118:	00e0c825 */ 	or	$t9,$a3,$zero
/*  f01d11c:	24ed009c */ 	addiu	$t5,$a3,0x9c
/*  f01d120:	adc10000 */ 	sw	$at,0x0($t6)
.L0f01d124:
/*  f01d124:	8f210000 */ 	lw	$at,0x0($t9)
/*  f01d128:	2739000c */ 	addiu	$t9,$t9,0x000c
/*  f01d12c:	25ef000c */ 	addiu	$t7,$t7,12
/*  f01d130:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f01d134:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f01d138:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f01d13c:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f01d140:	172dfff8 */ 	bne	$t9,$t5,.L0f01d124
/*  f01d144:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f01d148:	8f210000 */ 	lw	$at,0x0($t9)
/*  f01d14c:	00e0c825 */ 	or	$t9,$a3,$zero
/*  f01d150:	00406825 */ 	or	$t5,$v0,$zero
/*  f01d154:	2458009c */ 	addiu	$t8,$v0,0x9c
/*  f01d158:	ade10000 */ 	sw	$at,0x0($t7)
.L0f01d15c:
/*  f01d15c:	8da10000 */ 	lw	$at,0x0($t5)
/*  f01d160:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f01d164:	2739000c */ 	addiu	$t9,$t9,12
/*  f01d168:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f01d16c:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f01d170:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f01d174:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f01d178:	15b8fff8 */ 	bne	$t5,$t8,.L0f01d15c
/*  f01d17c:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f01d180:	8da10000 */ 	lw	$at,0x0($t5)
/*  f01d184:	00406825 */ 	or	$t5,$v0,$zero
/*  f01d188:	00a0c025 */ 	or	$t8,$a1,$zero
/*  f01d18c:	24ae009c */ 	addiu	$t6,$a1,0x9c
/*  f01d190:	af210000 */ 	sw	$at,0x0($t9)
.L0f01d194:
/*  f01d194:	8f010000 */ 	lw	$at,0x0($t8)
/*  f01d198:	2718000c */ 	addiu	$t8,$t8,12
/*  f01d19c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f01d1a0:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f01d1a4:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f01d1a8:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f01d1ac:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f01d1b0:	170efff8 */ 	bne	$t8,$t6,.L0f01d194
/*  f01d1b4:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f01d1b8:	8f010000 */ 	lw	$at,0x0($t8)
/*  f01d1bc:	00a0c025 */ 	or	$t8,$a1,$zero
/*  f01d1c0:	00c07025 */ 	or	$t6,$a2,$zero
/*  f01d1c4:	24cf009c */ 	addiu	$t7,$a2,0x9c
/*  f01d1c8:	ada10000 */ 	sw	$at,0x0($t5)
.L0f01d1cc:
/*  f01d1cc:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f01d1d0:	25ce000c */ 	addiu	$t6,$t6,12
/*  f01d1d4:	2718000c */ 	addiu	$t8,$t8,12
/*  f01d1d8:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f01d1dc:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f01d1e0:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f01d1e4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f01d1e8:	15cffff8 */ 	bne	$t6,$t7,.L0f01d1cc
/*  f01d1ec:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f01d1f0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f01d1f4:	00c07025 */ 	or	$t6,$a2,$zero
/*  f01d1f8:	00407825 */ 	or	$t7,$v0,$zero
/*  f01d1fc:	2459009c */ 	addiu	$t9,$v0,0x9c
/*  f01d200:	af010000 */ 	sw	$at,0x0($t8)
.L0f01d204:
/*  f01d204:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01d208:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f01d20c:	25ce000c */ 	addiu	$t6,$t6,0x000c
/*  f01d210:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f01d214:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f01d218:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f01d21c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f01d220:	15f9fff8 */ 	bne	$t7,$t9,.L0f01d204
/*  f01d224:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f01d228:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01d22c:	adc10000 */ 	sw	$at,0x0($t6)
.L0f01d230:
/*  f01d230:	04620019 */ 	bltzl	$v1,.L0f01d298
/*  f01d234:	8e6f046c */ 	lw	$t7,0x46c($s3)
/*  f01d238:	92420002 */ 	lbu	$v0,0x2($s2)
/*  f01d23c:	3c18800a */ 	lui	$t8,%hi(g_CheatsActiveBank0)
/*  f01d240:	28410011 */ 	slti	$at,$v0,0x11
/*  f01d244:	50200014 */ 	beqzl	$at,.L0f01d298
/*  f01d248:	8e6f046c */ 	lw	$t7,0x46c($s3)
/*  f01d24c:	8f1821d0 */ 	lw	$t8,%lo(g_CheatsActiveBank0)($t8)
/*  f01d250:	3c0d800a */ 	lui	$t5,%hi(g_CheatsActiveBank1)
/*  f01d254:	57000005 */ 	bnezl	$t8,.L0f01d26c
/*  f01d258:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f01d25c:	8dad21d4 */ 	lw	$t5,%lo(g_CheatsActiveBank1)($t5)
/*  f01d260:	11a00008 */ 	beqz	$t5,.L0f01d284
/*  f01d264:	00000000 */ 	nop
/*  f01d268:	8e450000 */ 	lw	$a1,0x0($s2)
.L0f01d26c:
/*  f01d26c:	24440001 */ 	addiu	$a0,$v0,0x1
/*  f01d270:	0005ce42 */ 	srl	$t9,$a1,0x19
/*  f01d274:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f01d278:	03202825 */ 	or	$a1,$t9,$zero
/*  f01d27c:	50400006 */ 	beqzl	$v0,.L0f01d298
/*  f01d280:	8e6f046c */ 	lw	$t7,0x46c($s3)
.L0f01d284:
/*  f01d284:	0fc43b90 */ 	jal	soloPushSoloModeEndscreen
/*  f01d288:	00000000 */ 	nop
/*  f01d28c:	10000042 */ 	b	.L0f01d398
/*  f01d290:	00000000 */ 	nop
/*  f01d294:	8e6f046c */ 	lw	$t7,0x46c($s3)
.L0f01d298:
/*  f01d298:	11e00007 */ 	beqz	$t7,.L0f01d2b8
/*  f01d29c:	00000000 */ 	nop
/*  f01d2a0:	0c003a61 */ 	jal	mainGetStageNum
/*  f01d2a4:	00000000 */ 	nop
/*  f01d2a8:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d2ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f01d2b0:	10000039 */ 	b	.L0f01d398
/*  f01d2b4:	00000000 */ 	nop
.L0f01d2b8:
/*  f01d2b8:	0fc625cb */ 	jal	mpSetPaused
/*  f01d2bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d2c0:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0x28)
/*  f01d2c4:	2442cbb0 */ 	addiu	$v0,$v0,%lo(g_MpSetup+0x28)
/*  f01d2c8:	904e0060 */ 	lbu	$t6,0x60($v0)
/*  f01d2cc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01d2d0:	ae600314 */ 	sw	$zero,0x314($s3)
/*  f01d2d4:	ae600318 */ 	sw	$zero,0x318($s3)
/*  f01d2d8:	15c10002 */ 	bne	$t6,$at,.L0f01d2e4
/*  f01d2dc:	ae60031c */ 	sw	$zero,0x31c($s3)
/*  f01d2e0:	a0400060 */ 	sb	$zero,0x60($v0)
.L0f01d2e4:
/*  f01d2e4:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f01d2e8:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f01d2ec:	12d8000b */ 	beq	$s6,$t8,.L0f01d31c
/*  f01d2f0:	00000000 */ 	nop
/*  f01d2f4:	0fc06c55 */ 	jal	titleSetNextStage
/*  f01d2f8:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d2fc:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d300:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d304:	0fc069f9 */ 	jal	titleSetNextMode
/*  f01d308:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d30c:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d310:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d314:	10000020 */ 	b	.L0f01d398
/*  f01d318:	00000000 */ 	nop
.L0f01d31c:
/*  f01d31c:	0fc06c55 */ 	jal	titleSetNextStage
/*  f01d320:	2404005d */ 	addiu	$a0,$zero,0x5d
/*  f01d324:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d328:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d32c:	0fc069f9 */ 	jal	titleSetNextMode
/*  f01d330:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d334:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d338:	2404005d */ 	addiu	$a0,$zero,0x5d
/*  f01d33c:	10000016 */ 	b	.L0f01d398
/*  f01d340:	00000000 */ 	nop
/*  f01d344:	8e6d0298 */ 	lw	$t5,0x298($s3)
.L0f01d348:
/*  f01d348:	05a00013 */ 	bltz	$t5,.L0f01d398
/*  f01d34c:	00000000 */ 	nop
/*  f01d350:	0fc625cb */ 	jal	mpSetPaused
/*  f01d354:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d358:	ae600314 */ 	sw	$zero,0x314($s3)
/*  f01d35c:	ae600318 */ 	sw	$zero,0x318($s3)
/*  f01d360:	ae60031c */ 	sw	$zero,0x31c($s3)
/*  f01d364:	0fc06c55 */ 	jal	titleSetNextStage
/*  f01d368:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d36c:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d370:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d374:	0fc069f9 */ 	jal	titleSetNextMode
/*  f01d378:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d37c:	0c003a57 */ 	jal	mainSetStageNum
/*  f01d380:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d384:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01d388:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01d38c:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f01d390:	332fff7f */ 	andi	$t7,$t9,0xff7f
/*  f01d394:	a24f0003 */ 	sb	$t7,0x3($s2)
.L0f01d398:
/*  f01d398:	0fc06fb8 */ 	jal	menuCountDialogs
/*  f01d39c:	00000000 */ 	nop
/*  f01d3a0:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f01d3a4:	55c00026 */ 	bnezl	$t6,.L0f01d440
/*  f01d3a8:	8e6f006c */ 	lw	$t7,0x6c($s3)
/*  f01d3ac:	92a20015 */ 	lbu	$v0,0x15($s5)
/*  f01d3b0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f01d3b4:	5041000b */ 	beql	$v0,$at,.L0f01d3e4
/*  f01d3b8:	92b80014 */ 	lbu	$t8,0x14($s5)
/*  f01d3bc:	1040000c */ 	beqz	$v0,.L0f01d3f0
/*  f01d3c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f01d3c4:	44813000 */ 	mtc1	$at,$f6
/*  f01d3c8:	c6a80010 */ 	lwc1	$f8,0x10($s5)
/*  f01d3cc:	a2a20014 */ 	sb	$v0,0x14($s5)
/*  f01d3d0:	a2a00015 */ 	sb	$zero,0x15($s5)
/*  f01d3d4:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f01d3d8:	10000005 */ 	b	.L0f01d3f0
/*  f01d3dc:	e6aa0010 */ 	swc1	$f10,0x10($s5)
/*  f01d3e0:	92b80014 */ 	lbu	$t8,0x14($s5)
.L0f01d3e4:
/*  f01d3e4:	53000003 */ 	beqzl	$t8,.L0f01d3f4
/*  f01d3e8:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f01d3ec:	a2a00015 */ 	sb	$zero,0x15($s5)
.L0f01d3f0:
/*  f01d3f0:	8e6d0284 */ 	lw	$t5,0x284($s3)
.L0f01d3f4:
/*  f01d3f4:	91b915ea */ 	lbu	$t9,0x15ea($t5)
/*  f01d3f8:	56d90011 */ 	bnel	$s6,$t9,.L0f01d440
/*  f01d3fc:	8e6f006c */ 	lw	$t7,0x6c($s3)
/*  f01d400:	8e6f04b4 */ 	lw	$t7,0x4b4($s3)
/*  f01d404:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01d408:	51e1000d */ 	beql	$t7,$at,.L0f01d440
/*  f01d40c:	8e6f006c */ 	lw	$t7,0x6c($s3)
/*  f01d410:	92b805d5 */ 	lbu	$t8,0x5d5($s5)
/*  f01d414:	3c19800a */ 	lui	$t9,%hi(g_Menus+0x844)
/*  f01d418:	370d0080 */ 	ori	$t5,$t8,0x80
/*  f01d41c:	a2ad05d5 */ 	sb	$t5,0x5d5($s5)
/*  f01d420:	8f39e844 */ 	lw	$t9,%lo(g_Menus+0x844)($t9)
/*  f01d424:	53200006 */ 	beqzl	$t9,.L0f01d440
/*  f01d428:	8e6f006c */ 	lw	$t7,0x6c($s3)
/*  f01d42c:	0fc277d4 */ 	jal	func0f09df50
/*  f01d430:	00000000 */ 	nop
/*  f01d434:	3c01800a */ 	lui	$at,%hi(g_Menus+0x844)
/*  f01d438:	ac20e844 */ 	sw	$zero,%lo(g_Menus+0x844)($at)
/*  f01d43c:	8e6f006c */ 	lw	$t7,0x6c($s3)
.L0f01d440:
/*  f01d440:	a26004d0 */ 	sb	$zero,0x4d0($s3)
/*  f01d444:	00008825 */ 	or	$s1,$zero,$zero
/*  f01d448:	51e00004 */ 	beqzl	$t7,.L0f01d45c
/*  f01d44c:	00003825 */ 	or	$a3,$zero,$zero
/*  f01d450:	10000002 */ 	b	.L0f01d45c
/*  f01d454:	02c03825 */ 	or	$a3,$s6,$zero
/*  f01d458:	00003825 */ 	or	$a3,$zero,$zero
.L0f01d45c:
/*  f01d45c:	8e6e0068 */ 	lw	$t6,0x68($s3)
/*  f01d460:	51c00004 */ 	beqzl	$t6,.L0f01d474
/*  f01d464:	00003025 */ 	or	$a2,$zero,$zero
/*  f01d468:	10000002 */ 	b	.L0f01d474
/*  f01d46c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01d470:	00003025 */ 	or	$a2,$zero,$zero
.L0f01d474:
/*  f01d474:	8e780064 */ 	lw	$t8,0x64($s3)
/*  f01d478:	53000004 */ 	beqzl	$t8,.L0f01d48c
/*  f01d47c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01d480:	10000002 */ 	b	.L0f01d48c
/*  f01d484:	02c02825 */ 	or	$a1,$s6,$zero
/*  f01d488:	00002825 */ 	or	$a1,$zero,$zero
.L0f01d48c:
/*  f01d48c:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f01d490:	51a00004 */ 	beqzl	$t5,.L0f01d4a4
/*  f01d494:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d498:	10000002 */ 	b	.L0f01d4a4
/*  f01d49c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d4a0:	00002025 */ 	or	$a0,$zero,$zero
.L0f01d4a4:
/*  f01d4a4:	0085c821 */ 	addu	$t9,$a0,$a1
/*  f01d4a8:	03267821 */ 	addu	$t7,$t9,$a2
/*  f01d4ac:	01e77021 */ 	addu	$t6,$t7,$a3
/*  f01d4b0:	19c00099 */ 	blez	$t6,.L0f01d718
/*  f01d4b4:	240c000f */ 	addiu	$t4,$zero,0xf
/*  f01d4b8:	240a001f */ 	addiu	$t2,$zero,0x1f
/*  f01d4bc:	8e780314 */ 	lw	$t8,0x314($s3)
.L0f01d4c0:
/*  f01d4c0:	001169c0 */ 	sll	$t5,$s1,0x7
/*  f01d4c4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f01d4c8:	13000003 */ 	beqz	$t8,.L0f01d4d8
/*  f01d4cc:	026dc821 */ 	addu	$t9,$s3,$t5
/*  f01d4d0:	10000004 */ 	b	.L0f01d4e4
/*  f01d4d4:	8f2300e4 */ 	lw	$v1,0xe4($t9)
.L0f01d4d8:
/*  f01d4d8:	16200002 */ 	bnez	$s1,.L0f01d4e4
/*  f01d4dc:	00000000 */ 	nop
/*  f01d4e0:	00001825 */ 	or	$v1,$zero,$zero
.L0f01d4e4:
/*  f01d4e4:	04600071 */ 	bltz	$v1,.L0f01d6ac
/*  f01d4e8:	00117880 */ 	sll	$t7,$s1,0x2
/*  f01d4ec:	026f4021 */ 	addu	$t0,$s3,$t7
/*  f01d4f0:	8d020064 */ 	lw	$v0,0x64($t0)
/*  f01d4f4:	5040006e */ 	beqzl	$v0,.L0f01d6b0
/*  f01d4f8:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f01d4fc:	92ae0015 */ 	lbu	$t6,0x15($s5)
/*  f01d500:	240100ff */ 	addiu	$at,$zero,0xff
/*  f01d504:	55c1001b */ 	bnel	$t6,$at,.L0f01d574
/*  f01d508:	904e1c50 */ 	lbu	$t6,0x1c50($v0)
/*  f01d50c:	92b80014 */ 	lbu	$t8,0x14($s5)
/*  f01d510:	57000018 */ 	bnezl	$t8,.L0f01d574
/*  f01d514:	904e1c50 */ 	lbu	$t6,0x1c50($v0)
/*  f01d518:	8ead05d4 */ 	lw	$t5,0x5d4($s5)
/*  f01d51c:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f01d520:	05e20014 */ 	bltzl	$t7,.L0f01d574
/*  f01d524:	904e1c50 */ 	lbu	$t6,0x1c50($v0)
/*  f01d528:	92ae05d4 */ 	lbu	$t6,0x5d4($s5)
/*  f01d52c:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f01d530:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d534:	15c0000e */ 	bnez	$t6,.L0f01d570
/*  f01d538:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f01d53c:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f01d540:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f01d544:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d548:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f01d54c:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0x4f8)
/*  f01d550:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01d554:	8dade4f8 */ 	lw	$t5,%lo(g_Menus+0x4f8)($t5)
/*  f01d558:	55a00006 */ 	bnezl	$t5,.L0f01d574
/*  f01d55c:	904e1c50 */ 	lbu	$t6,0x1c50($v0)
/*  f01d560:	82b9001b */ 	lb	$t9,0x1b($s5)
/*  f01d564:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01d568:	53210006 */ 	beql	$t9,$at,.L0f01d584
/*  f01d56c:	904d1c50 */ 	lbu	$t5,0x1c50($v0)
.L0f01d570:
/*  f01d570:	904e1c50 */ 	lbu	$t6,0x1c50($v0)
.L0f01d574:
/*  f01d574:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f01d578:	10000004 */ 	b	.L0f01d58c
/*  f01d57c:	a0581c50 */ 	sb	$t8,0x1c50($v0)
/*  f01d580:	904d1c50 */ 	lbu	$t5,0x1c50($v0)
.L0f01d584:
/*  f01d584:	31b9ff7f */ 	andi	$t9,$t5,0xff7f
/*  f01d588:	a0591c50 */ 	sb	$t9,0x1c50($v0)
.L0f01d58c:
/*  f01d58c:	8eaf0004 */ 	lw	$t7,0x4($s5)
/*  f01d590:	25eeffff */ 	addiu	$t6,$t7,-1
/*  f01d594:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f01d598:	10200013 */ 	beqz	$at,.L0f01d5e8
/*  f01d59c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f01d5a0:	3c017f1b */ 	lui	$at,%hi(var7f1a860c)
/*  f01d5a4:	002e0821 */ 	addu	$at,$at,$t6
/*  f01d5a8:	8c2e860c */ 	lw	$t6,%lo(var7f1a860c)($at)
/*  f01d5ac:	01c00008 */ 	jr	$t6
/*  f01d5b0:	00000000 */ 	nop
/*  f01d5b4:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f01d5b8:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d5bc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f01d5c0:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f01d5c4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f01d5c8:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d5cc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f01d5d0:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0x4f8)
/*  f01d5d4:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01d5d8:	8dade4f8 */ 	lw	$t5,%lo(g_Menus+0x4f8)($t5)
/*  f01d5dc:	51a00003 */ 	beqzl	$t5,.L0f01d5ec
/*  f01d5e0:	8d190064 */ 	lw	$t9,0x64($t0)
/*  f01d5e4:	a26a04d0 */ 	sb	$t2,0x4d0($s3)
.L0f01d5e8:
/*  f01d5e8:	8d190064 */ 	lw	$t9,0x64($t0)
.L0f01d5ec:
/*  f01d5ec:	af201c54 */ 	sw	$zero,0x1c54($t9)
/*  f01d5f0:	8e6f0298 */ 	lw	$t7,0x298($s3)
/*  f01d5f4:	05e30005 */ 	bgezl	$t7,.L0f01d60c
/*  f01d5f8:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f01d5fc:	8e6e029c */ 	lw	$t6,0x29c($s3)
/*  f01d600:	05c2002b */ 	bltzl	$t6,.L0f01d6b0
/*  f01d604:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f01d608:	8e78006c */ 	lw	$t8,0x6c($s3)
.L0f01d60c:
/*  f01d60c:	00003825 */ 	or	$a3,$zero,$zero
/*  f01d610:	00003025 */ 	or	$a2,$zero,$zero
/*  f01d614:	13000003 */ 	beqz	$t8,.L0f01d624
/*  f01d618:	00002825 */ 	or	$a1,$zero,$zero
/*  f01d61c:	10000001 */ 	b	.L0f01d624
/*  f01d620:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01d624:
/*  f01d624:	8e6d0068 */ 	lw	$t5,0x68($s3)
/*  f01d628:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d62c:	11a00003 */ 	beqz	$t5,.L0f01d63c
/*  f01d630:	00000000 */ 	nop
/*  f01d634:	10000001 */ 	b	.L0f01d63c
/*  f01d638:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01d63c:
/*  f01d63c:	8e790064 */ 	lw	$t9,0x64($s3)
/*  f01d640:	13200003 */ 	beqz	$t9,.L0f01d650
/*  f01d644:	00000000 */ 	nop
/*  f01d648:	10000001 */ 	b	.L0f01d650
/*  f01d64c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01d650:
/*  f01d650:	8e6f0070 */ 	lw	$t7,0x70($s3)
/*  f01d654:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f01d658:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f01d65c:	11e00003 */ 	beqz	$t7,.L0f01d66c
/*  f01d660:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f01d664:	10000001 */ 	b	.L0f01d66c
/*  f01d668:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01d66c:
/*  f01d66c:	00857021 */ 	addu	$t6,$a0,$a1
/*  f01d670:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f01d674:	03076821 */ 	addu	$t5,$t8,$a3
/*  f01d678:	29a10002 */ 	slti	$at,$t5,0x2
/*  f01d67c:	1420000b */ 	bnez	$at,.L0f01d6ac
/*  f01d680:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f01d684:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f01d688:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f01d68c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f01d690:	3c0f800a */ 	lui	$t7,%hi(g_Menus+0x4f8)
/*  f01d694:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f01d698:	8defe4f8 */ 	lw	$t7,%lo(g_Menus+0x4f8)($t7)
/*  f01d69c:	51e00004 */ 	beqzl	$t7,.L0f01d6b0
/*  f01d6a0:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f01d6a4:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*  f01d6a8:	adcc1c54 */ 	sw	$t4,0x1c54($t6)
.L0f01d6ac:
/*  f01d6ac:	8e78006c */ 	lw	$t8,0x6c($s3)
.L0f01d6b0:
/*  f01d6b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01d6b4:	8e680068 */ 	lw	$t0,0x68($s3)
/*  f01d6b8:	8e690064 */ 	lw	$t1,0x64($s3)
/*  f01d6bc:	13000003 */ 	beqz	$t8,.L0f01d6cc
/*  f01d6c0:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f01d6c4:	10000002 */ 	b	.L0f01d6d0
/*  f01d6c8:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01d6cc:
/*  f01d6cc:	00003825 */ 	or	$a3,$zero,$zero
.L0f01d6d0:
/*  f01d6d0:	11000003 */ 	beqz	$t0,.L0f01d6e0
/*  f01d6d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f01d6d8:	10000001 */ 	b	.L0f01d6e0
/*  f01d6dc:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01d6e0:
/*  f01d6e0:	11200003 */ 	beqz	$t1,.L0f01d6f0
/*  f01d6e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f01d6e8:	10000001 */ 	b	.L0f01d6f0
/*  f01d6ec:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01d6f0:
/*  f01d6f0:	11600003 */ 	beqz	$t3,.L0f01d700
/*  f01d6f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d6f8:	10000001 */ 	b	.L0f01d700
/*  f01d6fc:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01d700:
/*  f01d700:	00856821 */ 	addu	$t5,$a0,$a1
/*  f01d704:	01a6c821 */ 	addu	$t9,$t5,$a2
/*  f01d708:	03277821 */ 	addu	$t7,$t9,$a3
/*  f01d70c:	022f082a */ 	slt	$at,$s1,$t7
/*  f01d710:	5420ff6b */ 	bnezl	$at,.L0f01d4c0
/*  f01d714:	8e780314 */ 	lw	$t8,0x314($s3)
.L0f01d718:
/*  f01d718:	8fae0158 */ 	lw	$t6,0x158($sp)
/*  f01d71c:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f01d720:	ac36fac0 */ 	sw	$s6,%lo(g_ScreenWidthMultiplier)($at)
/*  f01d724:	51c00006 */ 	beqzl	$t6,.L0f01d740
/*  f01d728:	92af05d5 */ 	lbu	$t7,0x5d5($s5)
/*  f01d72c:	92ad05d5 */ 	lbu	$t5,0x5d5($s5)
/*  f01d730:	35b90004 */ 	ori	$t9,$t5,0x4
/*  f01d734:	10000004 */ 	b	.L0f01d748
/*  f01d738:	a2b905d5 */ 	sb	$t9,0x5d5($s5)
/*  f01d73c:	92af05d5 */ 	lbu	$t7,0x5d5($s5)
.L0f01d740:
/*  f01d740:	31eefffb */ 	andi	$t6,$t7,0xfffb
/*  f01d744:	a2ae05d5 */ 	sb	$t6,0x5d5($s5)
.L0f01d748:
/*  f01d748:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f01d74c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f01d750:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f01d754:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f01d758:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f01d75c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f01d760:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f01d764:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f01d768:	03e00008 */ 	jr	$ra
/*  f01d76c:	27bd0168 */ 	addiu	$sp,$sp,0x168
);

//void menuTickAll(void)
//{
//	s32 i;
//	s32 j;
//	s32 stack;
//	s32 sp344;
//	s32 sp340 = true;
//	s32 anyopen = false;
//
//	// bf5c
//	g_ScreenWidthMultiplier = g_ViMode == VIMODE_HIRES ? 2 : 1;
//
//	// bf7c
//	func0f0069dc();
//
//	if (g_MenuData.count) {
//		// empty
//	}
//
//	menuCountDialogs();
//
//	// @mismatch: End address for this loop is stored in a0 but should be a1.
//	for (i = 0; i < 4; i++) {
//		if (g_Menus[i].unk83c > 0) {
//			g_Menus[i].unk83c--;
//		}
//
//		if (g_Menus[i].curframe) {
//			anyopen = true;
//		}
//	}
//
//	// bfcc
//	if (!anyopen && g_MenuData.unk014 != 0 && g_MenuData.unk015 == 255) {
//		g_MenuData.unk015 = 0;
//	}
//
//	// bff4
//	if (anyopen && g_MenuData.unk66e > 0 && var8009dfc0) {
//		s32 bVar12 = 50;
//		s32 bVar11 = false;
//
//		for (j = 0; j < 4; j++) {
//			if (g_Menus[j].curframe) {
//				if (g_Menus[j].curframe->unk60 == 1
//						|| g_Menus[j].curframe->unk60 == 2
//						|| g_Menus[j].curframe->unk60 == 0) {
//					bVar11 = true;
//				}
//			}
//		}
//
//		if (g_Vars.normmplayerisrunning) {
//			bVar12 = 40;
//		}
//
//		if (g_MenuData.unk66f > bVar12 || !bVar11) {
//			func0f0f3220(g_MenuData.unk66e - 1);
//		} else {
//			g_MenuData.unk66f++;
//		}
//	}
//
//	// c0b0
//	if (g_MenuData.unk015 != 255) {
//		// c0d0
//		if (g_MenuData.unk015 == g_MenuData.unk014) {
//			g_MenuData.unk015 = 255;
//		} else {
//			// c0e4
//			f32 mult = 0.02f;
//
//			// c0ec
//			if (g_MenuData.unk014 == 0) {
//				mult = mult + mult;
//			}
//
//			// c0f8
//			if (g_MenuData.unk015 == 0) {
//				mult = mult + mult;
//			}
//
//			// c104
//			if (g_MenuData.unk015 == 8) {
//				mult = mult / 5.0f;
//			}
//
//			// c11c
//			if (g_MenuData.unk015 == 7) {
//				mult = mult / 3.0f;
//			}
//
//			// c134
//			if (g_MenuData.unk015 == 6) {
//				mult = mult / 10.0f;
//			}
//
//			// c148
//			if (g_MenuData.unk015 == 0) {
//				var8009dfc0 = false;
//
//				if (g_Vars.currentplayer->unk15ea) {
//					g_Vars.currentplayer->unk1583_06 = true;
//				}
//			}
//
//			// c170
//			if (g_MenuData.unk016 == 0 || g_MenuData.unk014 != 0) {
//				f32 diffframe = g_Vars.diffframe60f;
//
//				if (diffframe > 4) {
//					diffframe = 4;
//				}
//
//				g_MenuData.unk010 += mult * diffframe;
//			}
//
//			// c1b8
//			if (g_MenuData.unk010 > 1) {
//				// c1e0
//				if (g_MenuData.unk015) {
//					var8009dfc0 = true;
//				}
//
//				// c1ec
//				g_MenuData.unk010 = 0;
//				g_MenuData.unk014 = g_MenuData.unk015;
//				g_MenuData.unk015 = 255;
//
//				// c1f8
//				if (g_MenuData.root == MENUROOT_ENDSCREEN) {
//					if (g_MenuData.unk014 == 1) {
//						g_MenuData.unk015 = 6;
//					}
//
//					if (g_MenuData.unk014 == 6) {
//						func0f0e4fd4();
//						g_MenuData.unk014 = 1;
//						g_MenuData.unk015 = 8;
//					}
//
//					if (g_MenuData.unk014 == 8) {
//						g_MenuData.unk015 = 7;
//					}
//				}
//
//				if (g_MenuData.unk014 == 0) {
//					func0f0fa6ac();
//				}
//			}
//
//			// c254
//			if (g_MenuData.unk015 == 3) {
//				var8009dfc0 = true;
//			}
//
//			// c26c
//			// @mismatch: These conditions should branch to c28c then c2ac,
//			// but the below branches to c2ac directly. The branches can be
//			// fixed by uncommenting the else-if, but this breaks regalloc.
//			if (var8009dfc0 && g_Vars.currentplayer->unk1bd4) {
//				func0f0b9538();
//			}
//			//else if (var8009dfc0) {}
//
//			// c28c
//		}
//	} else {
//		g_MenuData.unk010 = 0;
//		var8009dfc0 = g_MenuData.unk014 == 0 ? false : true;
//	}
//
//	// c2ac
//	if (var80087260 > 0) {
//		if (g_Vars.lvframenum >= 4) {
//			// c2cc
//			if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
//				func00009ec4(false);
//				var800714d8 = 0;
//
//				// c2f8
//				if (g_Vars.unk00049c) {
//					g_Vars.unk000490 = 1;
//				} else {
//					g_Vars.unk000490 = 2;
//				}
//
//				// c310
//				for (i = 0; i < 4; i++) { // s1
//					g_Vars.unk000494[i] = 0;
//
//					if (g_MpSetup.chrslots & (1 << i)) {
//						g_MpPlayerNum = i;
//
//						if (g_Vars.unk000490 == 1) {
//							var800714d8++;
//							func0f17fcb0(true);
//						} else if (var800714d8 == 0) {
//							var800714d8++;
//
//							// c38c
//							if (IS4MB()) {
//								menuPushRootDialog(&g_4MbMainMenu, MENUROOT_4MBMAINMENU);
//							} else {
//								menuPushRootDialog(&g_CombatSimulatorMenuDialog, MENUROOT_MPSETUP);
//							}
//						} else {
//							g_Vars.unk000494[i] = 1;
//						}
//					}
//				}
//
//				// c3dc
//				g_MpPlayerNum = 0;
//
//				if (g_MpSetup.chrslots & 0xf) {
//					// Explosion sound
//					audioStart(var80095200, 0x8098, 0, -1, -1, -1, -1, -1);
//
//					// c444
//					currentPlayerPause(IS4MB() ? MENUROOT_4MBMAINMENU : MENUROOT_MPSETUP);
//				}
//			}
//
//			var80087260 = 0;
//		} else {
//			func00009ec4(true);
//			g_PlayersWithControl[0] = false;
//		}
//	}
//
//	// c468
//	if (var80062940 == 0 && g_Vars.stagenum == STAGE_CITRAINING) {
//		g_PlayersWithControl[0] = false;
//
//		if (g_Vars.lvframenum > 30 && g_Vars.tickmode != TICKMODE_CUTSCENE) {
//			g_Menus[0].unk83c = 0;
//			g_Menus[1].unk83c = 0;
//			g_Menus[2].unk83c = 0;
//			g_Menus[3].unk83c = 0;
//			g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
//			currentPlayerPause(MENUROOT_FILEMGR);
//			var80062940 = 1;
//		}
//	}
//
//	// c4e4
//	g_Vars.unk000498 = 0;
//
//	if (g_MenuData.count > 0) {
//		var8006294c = 1;
//
//		// c508
//		if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
//			// c518
//			if (g_MenuData.unk008 == -1) {
//				g_MpSetup.chrslots &= 0xfff0;
//			}
//
//			var800714d8 = 0;
//
//			// c540
//			for (i = 0; i < 4; i++) { // s1
//				if (g_Menus[i].curframe) {
//					g_Menus[i].playernum = var800714d8++;
//
//					if (g_MenuData.unk008 == -1) {
//						g_MpSetup.chrslots |= (1 << i);
//					}
//				}
//			}
//
//			mpCalculateLockIfLastWinnerOrLoser();
//			mpPerformSanityChecks();
//		}
//
//		// c5a0
//		for (i = 0; i < 4; i++) { // s1
//			g_MpPlayerNum = i;
//
//			if (g_Menus[g_MpPlayerNum].curframe) {
//				if (g_Menus[g_MpPlayerNum].curframe->dialog == &g_MpReadyMenuDialog) {
//					g_Vars.unk000498 = 1;
//				} else {
//					sp340 = false;
//				}
//			}
//		}
//
//		// c604
//		for (i = 0; i < 4; i++) { // s1
//			g_MpPlayerNum = i;
//
//			// c644
//			if (g_Menus[g_MpPlayerNum].curframe) {
//				s32 prevplayernum = g_Vars.currentplayernum;
//
//				if (g_Menus[g_MpPlayerNum].playernum < PLAYERCOUNT()) {
//					setCurrentPlayerNum(g_Menus[g_MpPlayerNum].playernum);
//				}
//
//				func0f0fa704();
//				setCurrentPlayerNum(prevplayernum);
//			} else {
//				// c6dc
//				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
//					s32 pass2;
//					u16 buttons = contGetButtonsPressedThisFrame(i, 0xffff);
//
//					// c714
//					if (g_MenuData.root == MENUROOT_4MBMAINMENU) {
//						if (g_Vars.unk000490 == 2) {
//							pass2 = true;
//
//							for (j = 0; j < 4; j++) { // s2
//								if (g_Vars.unk000494[j]) {
//									pass2 = false;
//								}
//							}
//						} else {
//							pass2 = var800714d8 < 2;
//						}
//					} else {
//						// c768
//						pass2 = true;
//					}
//
//					// c76c
//					if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
//						g_MpPlayers[i].base.team = 0;
//					}
//
//					// c790
//					if (pass2 && (buttons & START_BUTTON)) {
//						g_MpPlayers[i].handicap = 128;
//
//						if (g_Vars.unk000490 == 2) {
//							if (g_Vars.unk000494[i] == 0) {
//								// Explosion sound
//								audioStart(var80095200, 0x809a, 0, -1, -1, -1, -1, -1);
//							}
//
//							g_Vars.unk000494[i] = 1;
//						} else if (g_Vars.unk000490 == 3) {
//							var800714d8++;
//
//							if (IS4MB()) {
//								menuPushRootDialog(&menudialog_mpquickgo2, MENUROOT_4MBMAINMENU);
//							} else {
//								menuPushRootDialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
//							}
//						} else {
//							var800714d8++;
//							func0f17fcb0(false);
//						}
//					}
//
//					// c880
//					if ((buttons & START_BUTTON) == 0) {
//						if (buttons & B_BUTTON) {
//							if (g_Vars.unk000490 == 2) {
//								g_Vars.unk000494[i] = 0;
//							}
//						} else if (g_Vars.unk000494[i]) {
//							if (g_Vars.unk000490 == 3) {
//								g_Vars.unk000494[i] = 0;
//								var800714d8++;
//
//								if (IS4MB()) {
//									menuPushRootDialog(&menudialog_mpquickgo2, MENUROOT_4MBMAINMENU);
//								} else {
//									menuPushRootDialog(&g_MpQuickGoMenuDialog, MENUROOT_MPSETUP);
//								}
//							} else if (g_Vars.unk000490 == 1) {
//								g_Vars.unk000494[i] = 0;
//								var800714d8++;
//								func0f17fcb0(false);
//							}
//						}
//					}
//				} else {
//					// c940
//					g_Vars.unk000490 = 0;
//					g_Vars.unk000494[i] = 0;
//				}
//
//				if (g_MenuData.root == MENUROOT_MPENDSCREEN) {
//					u16 buttons2 = contGetButtonsPressedThisFrame(g_MpPlayers[i].base.unk45, 0xffff);
//
//					if (buttons2 & B_BUTTON) {
//						s32 playernum = -1;
//						s32 k;
//
//						for (k = 0; k < PLAYERCOUNT(); k++) {
//							if (g_Vars.playerstats[k].mpindex == i) {
//								playernum = k;
//							}
//						}
//
//						if (playernum >= 0) {
//							if (g_Vars.coopplayernum >= 0) {
//								s32 prevplayernum2 = g_Vars.currentplayernum;
//								setCurrentPlayerNum(playernum);
//								soloPushCoopModeEndscreen();
//								setCurrentPlayerNum(prevplayernum2);
//							} else if (g_Vars.antiplayernum >= 0) {
//								s32 prevplayernum2 = g_Vars.currentplayernum;
//								setCurrentPlayerNum(playernum);
//								soloPushAntiModeEndscreen();
//								setCurrentPlayerNum(prevplayernum2);
//							} else {
//								mpPushEndscreenDialog(playernum, i);
//							}
//						}
//					}
//				}
//			}
//		}
//
//		// cae8
//		if (sp340 &&
//				(g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
//			func0f0f820c(NULL, -5);
//		}
//	} else {
//		// cb28
//		var8006294c = 0;
//	}
//
//	// cb30
//	if (var8006294c) {
//		if (var80062948 == 0 &&
//				(g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)) {
//			var80062948 = 1;
//			func0f110c5c(0, FILETYPE_MPPLAYER);
//			func0f110c5c(1, FILETYPE_MPSETUP);
//		}
//
//		if (var80062944) {
//			func0f110da8();
//		}
//	} else {
//		// cba8
//		if (var80062944 == 1) {
//			func0f01bea0();
//		}
//	}
//
//	// cbc0
//	g_MpPlayerNum = 0;
//	sp344 = false;
//
//	for (i = 0; i < 4; i++) {
//		if (g_Menus[i].curframe) {
//			sp344 = true;
//		}
//	}
//
//	// cbfc
//	if ((g_MenuData.unk5d5_06 || g_MenuData.unk008 != -1) && sp344 == false) {
//		// cc28
//		if ((g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU)
//				&& g_MenuData.unk008 == -1) {
//			// cc4c
//			if (g_Vars.unk000490 == 2) {
//				g_MenuData.unk008 = MENUROOT_MAINMENU;
//				g_MenuData.unk00c = IS4MB() ? &g_CiMainMenuDialogViaPause : &g_MainMenuMenuDialog;
//			} else {
//				// cc90
//				if (IS4MB()) {
//					g_MenuData.unk008 = MENUROOT_4MBMAINMENU;
//					g_MenuData.unk00c = &g_4MbMainMenu;
//				} else {
//					// ccc0
//					g_MenuData.unk008 = MENUROOT_MPSETUP;
//					g_MenuData.unk00c = &g_CombatSimulatorMenuDialog;
//				}
//			}
//		}
//
//		// ccc8
//		if (g_MenuData.unk008 != -1) {
//			if (g_MenuData.unk008 == -5) {
//				mpStartMatch();
//				func0f01bea0();
//
//				if (g_Vars.unk000458 & 0x00000002) {
//					func0f1109c0();
//					g_Vars.unk000458 &= ~0x00000002;
//				}
//			} else /*cd1c*/ if (g_MenuData.unk008 == -6) {
//				s32 sp288 = 0;
//
//				if (g_Vars.normmplayerisrunning) {
//					func0f0fd548(4);
//				}
//
//				// cd40
//				for (i = 0; i < 4; i++) { // s1
//					// cd64
//					if (g_MpSetup.chrslots & (1 << i)) {
//						// cd70
//						if (g_Vars.coopplayernum >= 0) {
//							// cd78
//							if (g_Vars.stagenum == STAGE_DEEPSEA) {
//								// cd8c
//								g_MissionConfig.stageindex++;
//								g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stagenum;
//								titleSetNextStage(g_MissionConfig.stagenum);
//								coreSetDifficulty(g_MissionConfig.difficulty);
//								titleSetNextMode(TITLEMODE_SKIP);
//								mainSetStageNum(g_MissionConfig.stagenum);
//							} else {
//								// cde8
//								s32 prevplayernum = g_Vars.currentplayernum;
//								setCurrentPlayerNum(sp288);
//								soloPushCoopModeEndscreen();
//								sp344 = true;
//								setCurrentPlayerNum(prevplayernum);
//							}
//						} else /*ce10*/ if (g_Vars.antiplayernum >= 0) {
//							s32 prevplayernum = g_Vars.currentplayernum;
//							setCurrentPlayerNum(sp288);
//							soloPushAntiModeEndscreen();
//							sp344 = true;
//							setCurrentPlayerNum(prevplayernum);
//						} else {
//							// ce44
//							mpPushEndscreenDialog(sp288, i);
//							sp344 = true;
//
//							if (g_MpPlayers[i].saved && g_MpPlayers[i].unk50) {
//								func0f0fd548(i);
//							}
//						}
//
//						sp288++;
//					}
//				}
//			} else /*ceb0*/ if (g_MenuData.unk008 == -7) {
//				func0f01bea0();
//				var80062940 = 2;
//				savefileLoadDefaults(&g_SoloSaveFile);
//				savefileApplyOptions(&g_SoloSaveFile);
//				mainSetStageNum(IS4MB() ? STAGE_4MBMENU : STAGE_CITRAINING);
//				func0f16d3d0();
//			} else {
//				// cf1c
//				s32 pass = false;
//				menuPushRootDialog(g_MenuData.unk00c, g_MenuData.unk008);
//				sp344 = true;
//
//				if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
//					pass = true;
//					// Explosion sound
//					audioStart(var80095200, 0x8098, 0, -1, -1, -1, -1, -1);
//				}
//
//				if (g_MenuData.root == MENUROOT_MAINMENU || g_MenuData.root == MENUROOT_TRAINING) {
//					struct trainingdata *dtdata = dtGetData();
//
//					if ((g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU)
//							&& ((g_Vars.currentplayer->prop->rooms[0] >= 0x16 && g_Vars.currentplayer->prop->rooms[0] <= 0x19)
//								|| g_Vars.currentplayer->prop->rooms[0] == 0x0a
//								|| g_Vars.currentplayer->prop->rooms[0] == 0x1e
//								|| (dtdata && dtdata->intraining))) {
//						pass = false;
//					} else {
//						pass = true;
//					}
//				}
//
//				if (pass) {
//					musicStartForMenu();
//				}
//			}
//
//			// d020
//			g_MenuData.unk00c = NULL;
//			g_MenuData.unk008 = -1;
//		} else {
//			// d02c
//			switch (g_MenuData.root) {
//			case MENUROOT_ENDSCREEN: // d058
//				if (g_Vars.restartlevel) {
//					mainSetStageNum(mainGetStageNum());
//				} else {
//					mainSetStageNum(STAGE_TITLE);
//				}
//				break;
//			case MENUROOT_MPPAUSE: // d398
//				break;
//			case MENUROOT_MPENDSCREEN: // d08c
//				if (g_Vars.normmplayerisrunning) {
//					var80087260 = 3;
//				} else {
//					// d0ac
//					if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
//						struct mpplayer tmp;
//
//						tmp = g_MpPlayers[4];
//						g_MpPlayers[4] = g_MpPlayers[0];
//						g_MpPlayers[0] = tmp;
//
//						tmp = g_MpPlayers[5];
//						g_MpPlayers[5] = g_MpPlayers[1];
//						g_MpPlayers[1] = tmp;
//					}
//				}
//
//				// d230
//				if (g_Vars.coopplayernum >= 0
//						&& g_MissionConfig.stageindex <= SOLOSTAGEINDEX_SKEDARRUINS
//						&& ((!g_CheatsActiveBank0 && !g_CheatsActiveBank1) || isStageDifficultyUnlocked(g_MissionConfig.stageindex + 1, g_MissionConfig.difficulty))) {
//					soloPushSoloModeEndscreen();
//				} else if (g_Vars.restartlevel) {
//					mainSetStageNum(mainGetStageNum());
//				} else {
//					mpSetPaused(MPPAUSEMODE_UNPAUSED);
//					g_Vars.mplayerisrunning = false;
//					g_Vars.normmplayerisrunning = false;
//					g_Vars.lvmpbotlevel = 0;
//
//					if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
//						g_MpSetupSaveFile.locktype = MPLOCKTYPE_NONE;
//					}
//
//					// d2ec
//					if (g_Is4Mb != true) {
//						titleSetNextStage(STAGE_CITRAINING);
//						setNumPlayers(1);
//						titleSetNextMode(TITLEMODE_SKIP);
//						mainSetStageNum(STAGE_CITRAINING);
//					} else {
//						titleSetNextStage(STAGE_4MBMENU);
//						setNumPlayers(1);
//						titleSetNextMode(TITLEMODE_SKIP);
//						mainSetStageNum(STAGE_4MBMENU);
//					}
//				}
//				break;
//			case MENUROOT_9: // d348
//				if (g_Vars.coopplayernum >= 0) {
//					mpSetPaused(MPPAUSEMODE_UNPAUSED);
//					g_Vars.mplayerisrunning = false;
//					g_Vars.normmplayerisrunning = false;
//					g_Vars.lvmpbotlevel = 0;
//					titleSetNextStage(STAGE_CITRAINING);
//					setNumPlayers(1);
//					titleSetNextMode(TITLEMODE_SKIP);
//					mainSetStageNum(STAGE_CITRAINING);
//					g_MissionConfig.iscoop = false;
//				}
//				break;
//			}
//		}
//	}
//
//	// d398
//	menuCountDialogs();
//
//	if (g_MenuData.count == 0) {
//		if (g_MenuData.unk015 != 255) {
//			if (g_MenuData.unk015 != 0) {
//				g_MenuData.unk014 = g_MenuData.unk015;
//				g_MenuData.unk015 = 0;
//				g_MenuData.unk010 = 1.0f - g_MenuData.unk010;
//			}
//		} else {
//			// d3e0
//			if (g_MenuData.unk014 != 0) {
//				g_MenuData.unk015 = 0;
//			}
//		}
//
//		// d3f0
//		if (g_Vars.currentplayer->unk15ea == 1 && g_Vars.stagenum != STAGE_CITRAINING) {
//			// d410
//			g_MenuData.unk5d5_01 = true;
//
//			if (g_Menus[0].unk844) {
//				func0f09df50();
//				g_Menus[0].unk844 = 0;
//			}
//		}
//	}
//
//	// d440
//	g_Vars.paksconnected = 0;
//
//	for (i = 0; i < PLAYERCOUNT(); i++) { // s1
//		s32 mpindex = -1; // v1
//
//		// d4c8
//		if (g_Vars.mplayerisrunning) {
//			mpindex = g_Vars.playerstats[i].mpindex;
//		} else if (i == 0) {
//			mpindex = 0;
//		}
//
//		// d4e4
//		if (mpindex >= 0 && g_Vars.players[i]) {
//			// d504
//			if (g_MenuData.unk015 != 255U
//					|| g_MenuData.unk014
//					|| g_MenuData.unk5d5_05
//					|| g_MenuData.unk5d4
//					|| g_Menus[mpindex].curframe
//					|| g_MenuData.unk01b != -1) {
//				g_Vars.players[i]->unk1c50_01 = true;
//			} else {
//				g_Vars.players[i]->unk1c50_01 = false;
//			}
//
//			// d58c
//			switch (g_MenuData.root) {
//			case MENUROOT_ENDSCREEN:
//			case MENUROOT_MAINMENU:
//			case MENUROOT_MPSETUP:
//			case MENUROOT_MPENDSCREEN:
//			case MENUROOT_FILEMGR:
//			case MENUROOT_BOOTPAKMGR:
//			case MENUROOT_10:
//			case MENUROOT_4MBMAINMENU:
//			case MENUROOT_TRAINING: // f01d5b4
//				if (g_Menus[mpindex].curframe) {
//					g_Vars.paksconnected = 0x1f;
//				}
//				break;
//			}
//
//			// d5e8
//			g_Vars.players[i]->devicesinhibit = 0;
//
//			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
//					&& PLAYERCOUNT() >= 2
//					&& g_Menus[mpindex].curframe) {
//				g_Vars.players[i]->devicesinhibit = 15;
//			}
//		}
//	}
//
//	g_ScreenWidthMultiplier = 1;
//	g_MenuData.unk5d5_06 = sp344 ? true : false;
//}
