#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_006900.h"
#include "game/objectives.h"
#include "game/game_0b3350.h"
#include "game/menugfx.h"
#include "game/menuitem.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/objectives.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

u8 g_MpSelectedPlayersForStats[4];

#if VERSION >= VERSION_NTSC_1_0
s32 g_ScissorX1 = 0;
s32 g_ScissorX2 = 0;
s32 g_ScissorY1 = 0;
s32 g_ScissorY2 = 0;
#endif

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

s32 menuitem0f0e5d2c(s32 arg0, struct menuitem *item)
{
	union handlerdata data;
	s32 s0;
	s32 s1;
	s32 a0;
	bool done;
	s32 numgroups;

	if (item->handler == NULL) {
		return 0;
	}

	data.list.value = 0;
	data.list.unk0c = 0;

	item->handler(MENUOP_GETOPTGROUPCOUNT, item, &data);

	if (data.list.value == 0) {
		s1 = arg0 / (s32)g_LineHeight;
	} else {
		numgroups = data.list.value;
		s0 = arg0;
		done = false;
		s1 = 0;
		data.list.values32 = 0;
		data.list.unk04 = 0;

		while (!done) {
			if (data.list.values32 < numgroups) {
				item->handler(MENUOP_GETGROUPSTARTINDEX, item, &data);
				a0 = data.list.groupstartindex;
			} else {
				a0 = 9999;
			}

			data.list.value++;

			if (s1 + s0 / (s32)g_LineHeight >= a0) {
				s0 = s0 - (a0 - s1) * (s32)g_LineHeight - 11;
				s1 += a0 - s1;
			} else {
				s1 += s0 / (s32)g_LineHeight;
				done = true;
			}
		}
	}

	if (s1 < 0) {
		s1 = 0;
	}

	return s1;
}

s16 menuitem0f0e5ef8(s16 arg0, struct menuitem *item)
{
	union handlerdata data;
	bool done;
	s32 numlines;
	s32 numgroups;

	if (item->handler == NULL) {
		return 0;
	}

	if (arg0 < 0) {
		arg0 = 0;
	}

	data.list.value = 0;
	data.list.unk0c = 0;
	item->handler(MENUOP_GETOPTGROUPCOUNT, item, &data);

	if (data.list.value == 0) {
		return arg0 * g_LineHeight;
	}

	done = false;
	numlines = 0;

	numgroups = data.list.value;
	data.list.unk04 = 0;

	for (data.list.value = 0; !done && data.list.values32 < numgroups; data.list.value++) {
		item->handler(MENUOP_GETGROUPSTARTINDEX, item, &data);

		if (arg0 >= data.list.groupstartindex) {
			numlines++;
		} else {
			done = true;
		}
	}

	return arg0 * g_LineHeight + numlines * LINEHEIGHT;
}

Gfx *menuitemListRenderHeader(Gfx *gdl, s16 x1, s16 y1, s16 width, s16 arg4, s16 height, char *text, struct menudialog *dialog)
{
	s32 x;
	s32 y;
	u32 colour;

	colour = MIXCOLOUR(dialog, unk2c);

	if (dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x2c) & 0xffffff00) | (colour & 0xff);
	}

	gdl = func0f153780(gdl);
#if VERSION >= VERSION_NTSC_1_0
	gdl = menugfxDrawListGroupHeader(gdl, x1, y1, x1 + width, y1 + height, x1 + arg4, colour & 0xff);
#else
	gdl = menugfxDrawListGroupHeader(gdl, x1, y1, x1 + width, y1 + height, x1 + arg4);
#endif
	gdl = func0f153628(gdl);

	x = x1 + 3;
	y = y1 + 2;

	colour = MIXCOLOUR(dialog, unk30);

	if (dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x2c) & 0xffffff00) | (colour & 0xff);
	}

	func0f153e38(g_MenuColourPalettes3[dialog->type].unk30, g_MenuColourPalettes2[dialog->type].unk30);

	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, width, height, 0, 0);

	return gdl;
}

Gfx *menuitemListOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2)
{
	gDPFillRectangleScaled(gdl++, x, y, x + x2, y + y2);
	return gdl;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuitemListRender
/*  f0e70d4:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f0e70d8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0e70dc:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f0e70e0:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f0e70e4:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0e70e8:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0e70ec:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0e70f0:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0e70f4:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0e70f8:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0e70fc:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e7100:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0e7104:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f0e7108:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0e710c:	afae016c */ 	sw	$t6,0x16c($sp)
/*  f0e7110:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f0e7114:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e7118:	8d4a0148 */ 	lw	$t2,0x148($t2)
/*  f0e711c:	8d6b014c */ 	lw	$t3,0x14c($t3)
/*  f0e7120:	2419270f */ 	li	$t9,0x270f
/*  f0e7124:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0e7128:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0e712c:	afb900fc */ 	sw	$t9,0xfc($sp)
/*  f0e7130:	a3a000ed */ 	sb	$zero,0xed($sp)
/*  f0e7134:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0e7138:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f0e713c:	8ca70008 */ 	lw	$a3,0x8($a1)
/*  f0e7140:	00a08825 */ 	move	$s1,$a1
/*  f0e7144:	00809025 */ 	move	$s2,$a0
/*  f0e7148:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f0e714c:	000c6a80 */ 	sll	$t5,$t4,0xa
/*  f0e7150:	05a3000b */ 	bgezl	$t5,.JF0f0e7180
/*  f0e7154:	240f000e */ 	li	$t7,0xe
/*  f0e7158:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e715c:	24040014 */ 	li	$a0,0x14
/*  f0e7160:	00e02825 */ 	move	$a1,$a3
/*  f0e7164:	0320f809 */ 	jalr	$t9
/*  f0e7168:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f0e716c:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f0e7170:	3c018007 */ 	lui	$at,0x8007
/*  f0e7174:	10000004 */ 	b	.JF0f0e7188
/*  f0e7178:	ac2e16e8 */ 	sw	$t6,0x16e8($at)
/*  f0e717c:	240f000e */ 	li	$t7,0xe
.JF0f0e7180:
/*  f0e7180:	3c018007 */ 	lui	$at,0x8007
/*  f0e7184:	ac2f16e8 */ 	sw	$t7,0x16e8($at)
.JF0f0e7188:
/*  f0e7188:	8e2a0008 */ 	lw	$t2,0x8($s1)
/*  f0e718c:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0e7190:	3c038008 */ 	lui	$v1,0x8008
/*  f0e7194:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f0e7198:	8705001e */ 	lh	$a1,0x1e($t8)
/*  f0e719c:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0e71a0:	05810002 */ 	bgez	$t4,.JF0f0e71ac
/*  f0e71a4:	00000000 */ 	nop
/*  f0e71a8:	86250004 */ 	lh	$a1,0x4($s1)
.JF0f0e71ac:
/*  f0e71ac:	8c6300f4 */ 	lw	$v1,0xf4($v1)
/*  f0e71b0:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e71b4:	3c028007 */ 	lui	$v0,0x8007
/*  f0e71b8:	244216d0 */ 	addiu	$v0,$v0,0x16d0
/*  f0e71bc:	01a30019 */ 	multu	$t5,$v1
/*  f0e71c0:	3c178007 */ 	lui	$s7,0x8007
/*  f0e71c4:	26f716d4 */ 	addiu	$s7,$s7,0x16d4
/*  f0e71c8:	3c048007 */ 	lui	$a0,0x8007
/*  f0e71cc:	248416d8 */ 	addiu	$a0,$a0,0x16d8
/*  f0e71d0:	3c1e8007 */ 	lui	$s8,0x8007
/*  f0e71d4:	27de16dc */ 	addiu	$s8,$s8,0x16dc
/*  f0e71d8:	0000c812 */ 	mflo	$t9
/*  f0e71dc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0e71e0:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0e71e4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0e71e8:	01e30019 */ 	multu	$t7,$v1
/*  f0e71ec:	0000c012 */ 	mflo	$t8
/*  f0e71f0:	aef80000 */ 	sw	$t8,0x0($s7)
/*  f0e71f4:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e71f8:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f0e71fc:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e7200:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0e7204:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f0e7208:	07210002 */ 	bgez	$t9,.JF0f0e7214
/*  f0e720c:	afcd0000 */ 	sw	$t5,0x0($s8)
/*  f0e7210:	ac400000 */ 	sw	$zero,0x0($v0)
.JF0f0e7214:
/*  f0e7214:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e7218:	05c30003 */ 	bgezl	$t6,.JF0f0e7228
/*  f0e721c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0e7220:	aee00000 */ 	sw	$zero,0x0($s7)
/*  f0e7224:	8c8f0000 */ 	lw	$t7,0x0($a0)
.JF0f0e7228:
/*  f0e7228:	05e30003 */ 	bgezl	$t7,.JF0f0e7238
/*  f0e722c:	8fd80000 */ 	lw	$t8,0x0($s8)
/*  f0e7230:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0e7234:	8fd80000 */ 	lw	$t8,0x0($s8)
.JF0f0e7238:
/*  f0e7238:	07010002 */ 	bgez	$t8,.JF0f0e7244
/*  f0e723c:	00000000 */ 	nop
/*  f0e7240:	afc00000 */ 	sw	$zero,0x0($s8)
.JF0f0e7244:
/*  f0e7244:	0c002eda */ 	jal	0xbb68
/*  f0e7248:	a7a500ee */ 	sh	$a1,0xee($sp)
/*  f0e724c:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0e7250:	8d4a16d0 */ 	lw	$t2,0x16d0($t2)
/*  f0e7254:	004a082a */ 	slt	$at,$v0,$t2
/*  f0e7258:	10200005 */ 	beqz	$at,.JF0f0e7270
/*  f0e725c:	00000000 */ 	nop
/*  f0e7260:	0c002eda */ 	jal	0xbb68
/*  f0e7264:	00000000 */ 	nop
/*  f0e7268:	3c018007 */ 	lui	$at,0x8007
/*  f0e726c:	ac2216d0 */ 	sw	$v0,0x16d0($at)
.JF0f0e7270:
/*  f0e7270:	0c002eda */ 	jal	0xbb68
/*  f0e7274:	00000000 */ 	nop
/*  f0e7278:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f0e727c:	004b082a */ 	slt	$at,$v0,$t3
/*  f0e7280:	10200004 */ 	beqz	$at,.JF0f0e7294
/*  f0e7284:	00000000 */ 	nop
/*  f0e7288:	0c002eda */ 	jal	0xbb68
/*  f0e728c:	00000000 */ 	nop
/*  f0e7290:	aee20000 */ 	sw	$v0,0x0($s7)
.JF0f0e7294:
/*  f0e7294:	0c002ede */ 	jal	0xbb78
/*  f0e7298:	00000000 */ 	nop
/*  f0e729c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0e72a0:	8d8c16d8 */ 	lw	$t4,0x16d8($t4)
/*  f0e72a4:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e72a8:	10200005 */ 	beqz	$at,.JF0f0e72c0
/*  f0e72ac:	00000000 */ 	nop
/*  f0e72b0:	0c002ede */ 	jal	0xbb78
/*  f0e72b4:	00000000 */ 	nop
/*  f0e72b8:	3c018007 */ 	lui	$at,0x8007
/*  f0e72bc:	ac2216d8 */ 	sw	$v0,0x16d8($at)
.JF0f0e72c0:
/*  f0e72c0:	0c002ede */ 	jal	0xbb78
/*  f0e72c4:	00000000 */ 	nop
/*  f0e72c8:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e72cc:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e72d0:	10200005 */ 	beqz	$at,.JF0f0e72e8
/*  f0e72d4:	00000000 */ 	nop
/*  f0e72d8:	0c002ede */ 	jal	0xbb78
/*  f0e72dc:	00000000 */ 	nop
/*  f0e72e0:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e72e4:	00401825 */ 	move	$v1,$v0
.JF0f0e72e8:
/*  f0e72e8:	3c098007 */ 	lui	$t1,0x8007
/*  f0e72ec:	8d2916d0 */ 	lw	$t1,0x16d0($t1)
/*  f0e72f0:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f0e72f4:	3c088007 */ 	lui	$t0,0x8007
/*  f0e72f8:	44892000 */ 	mtc1	$t1,$f4
/*  f0e72fc:	01a9082a */ 	slt	$at,$t5,$t1
/*  f0e7300:	10200002 */ 	beqz	$at,.JF0f0e730c
/*  f0e7304:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e7308:	aee90000 */ 	sw	$t1,0x0($s7)
.JF0f0e730c:
/*  f0e730c:	8d0816d8 */ 	lw	$t0,0x16d8($t0)
/*  f0e7310:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e7314:	50200003 */ 	beqzl	$at,.JF0f0e7324
/*  f0e7318:	44888000 */ 	mtc1	$t0,$f16
/*  f0e731c:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e7320:	44888000 */ 	mtc1	$t0,$f16
.JF0f0e7324:
/*  f0e7324:	3c014080 */ 	lui	$at,0x4080
/*  f0e7328:	44810000 */ 	mtc1	$at,$f0
/*  f0e732c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e7330:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e7334:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e7338:	02402025 */ 	move	$a0,$s2
/*  f0e733c:	3c058007 */ 	lui	$a1,0x8007
/*  f0e7340:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e7344:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0e7348:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e734c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e7350:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e7354:	440c3000 */ 	mfc1	$t4,$f6
/*  f0e7358:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0e735c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e7360:	03015025 */ 	or	$t2,$t8,$at
/*  f0e7364:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0e7368:	014dc825 */ 	or	$t9,$t2,$t5
/*  f0e736c:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f0e7370:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0e7374:	8fca0000 */ 	lw	$t2,0x0($s8)
/*  f0e7378:	448e4000 */ 	mtc1	$t6,$f8
/*  f0e737c:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e7380:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e7384:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e7388:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0e738c:	00000000 */ 	nop
/*  f0e7390:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e7394:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e7398:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e739c:	44189000 */ 	mfc1	$t8,$f18
/*  f0e73a0:	44195000 */ 	mfc1	$t9,$f10
/*  f0e73a4:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f0e73a8:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e73ac:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f0e73b0:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0e73b4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e73b8:	86220006 */ 	lh	$v0,0x6($s1)
/*  f0e73bc:	8ca516e8 */ 	lw	$a1,0x16e8($a1)
/*  f0e73c0:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e73c4:	04410003 */ 	bgez	$v0,.JF0f0e73d4
/*  f0e73c8:	0002b043 */ 	sra	$s6,$v0,0x1
/*  f0e73cc:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0e73d0:	0001b043 */ 	sra	$s6,$at,0x1
.JF0f0e73d4:
/*  f0e73d4:	02c5001a */ 	div	$zero,$s6,$a1
/*  f0e73d8:	14a00002 */ 	bnez	$a1,.JF0f0e73e4
/*  f0e73dc:	00000000 */ 	nop
/*  f0e73e0:	0007000d */ 	break	0x7
.JF0f0e73e4:
/*  f0e73e4:	2401ffff */ 	li	$at,-1
/*  f0e73e8:	14a10004 */ 	bne	$a1,$at,.JF0f0e73fc
/*  f0e73ec:	3c018000 */ 	lui	$at,0x8000
/*  f0e73f0:	16c10002 */ 	bne	$s6,$at,.JF0f0e73fc
/*  f0e73f4:	00000000 */ 	nop
/*  f0e73f8:	0006000d */ 	break	0x6
.JF0f0e73fc:
/*  f0e73fc:	0000b012 */ 	mflo	$s6
/*  f0e7400:	a7020006 */ 	sh	$v0,0x6($t8)
/*  f0e7404:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7408:	02c50019 */ 	multu	$s6,$a1
/*  f0e740c:	2401000c */ 	li	$at,0xc
/*  f0e7410:	90e30000 */ 	lbu	$v1,0x0($a3)
/*  f0e7414:	02402025 */ 	move	$a0,$s2
/*  f0e7418:	0000b012 */ 	mflo	$s6
/*  f0e741c:	10610004 */ 	beq	$v1,$at,.JF0f0e7430
/*  f0e7420:	00000000 */ 	nop
/*  f0e7424:	2401000f */ 	li	$at,0xf
/*  f0e7428:	54610050 */ 	bnel	$v1,$at,.JF0f0e756c
/*  f0e742c:	8cf90010 */ 	lw	$t9,0x10($a3)
.JF0f0e7430:
/*  f0e7430:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e7434:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f0e7438:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e743c:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e7440:	00ca6821 */ 	addu	$t5,$a2,$t2
/*  f0e7444:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7448:	02002825 */ 	move	$a1,$s0
/*  f0e744c:	0fc38907 */ 	jal	0xf0e241c
/*  f0e7450:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e7454:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e7458:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e745c:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e7460:	240e007f */ 	li	$t6,0x7f
/*  f0e7464:	240f0001 */ 	li	$t7,0x1
/*  f0e7468:	2418000f */ 	li	$t8,0xf
/*  f0e746c:	240b0001 */ 	li	$t3,0x1
/*  f0e7470:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e7474:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e7478:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e747c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e7480:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e7484:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e7488:	00402025 */ 	move	$a0,$v0
/*  f0e748c:	02002825 */ 	move	$a1,$s0
/*  f0e7490:	0fc38e16 */ 	jal	0xf0e3858
/*  f0e7494:	26070001 */ 	addiu	$a3,$s0,0x1
/*  f0e7498:	862a0000 */ 	lh	$t2,0x0($s1)
/*  f0e749c:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f0e74a0:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e74a4:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e74a8:	240e007f */ 	li	$t6,0x7f
/*  f0e74ac:	240f000f */ 	li	$t7,0xf
/*  f0e74b0:	24180001 */ 	li	$t8,0x1
/*  f0e74b4:	014d2821 */ 	addu	$a1,$t2,$t5
/*  f0e74b8:	00d96021 */ 	addu	$t4,$a2,$t9
/*  f0e74bc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e74c0:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e74c4:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0e74c8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e74cc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e74d0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e74d4:	0fc38e16 */ 	jal	0xf0e3858
/*  f0e74d8:	00402025 */ 	move	$a0,$v0
/*  f0e74dc:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e74e0:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e74e4:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e74e8:	240d007f */ 	li	$t5,0x7f
/*  f0e74ec:	2419000f */ 	li	$t9,0xf
/*  f0e74f0:	240c0001 */ 	li	$t4,0x1
/*  f0e74f4:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e74f8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e74fc:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0e7500:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e7504:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e7508:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e750c:	00402025 */ 	move	$a0,$v0
/*  f0e7510:	02002825 */ 	move	$a1,$s0
/*  f0e7514:	0fc38e16 */ 	jal	0xf0e3858
/*  f0e7518:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f0e751c:	86300000 */ 	lh	$s0,0x0($s1)
/*  f0e7520:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0e7524:	862f0006 */ 	lh	$t7,0x6($s1)
/*  f0e7528:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0e752c:	240a007f */ 	li	$t2,0x7f
/*  f0e7530:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f0e7534:	24cb0001 */ 	addiu	$t3,$a2,0x1
/*  f0e7538:	240d000f */ 	li	$t5,0xf
/*  f0e753c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e7540:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e7544:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e7548:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e754c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e7550:	00402025 */ 	move	$a0,$v0
/*  f0e7554:	02002825 */ 	move	$a1,$s0
/*  f0e7558:	0fc38e16 */ 	jal	0xf0e3858
/*  f0e755c:	02183821 */ 	addu	$a3,$s0,$t8
/*  f0e7560:	00409025 */ 	move	$s2,$v0
/*  f0e7564:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7568:	8cf90010 */ 	lw	$t9,0x10($a3)
.JF0f0e756c:
/*  f0e756c:	57200004 */ 	bnezl	$t9,.JF0f0e7580
/*  f0e7570:	afa0015c */ 	sw	$zero,0x15c($sp)
/*  f0e7574:	10000369 */ 	b	.JF0f0e831c
/*  f0e7578:	02401025 */ 	move	$v0,$s2
/*  f0e757c:	afa0015c */ 	sw	$zero,0x15c($sp)
.JF0f0e7580:
/*  f0e7580:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7584:	24040007 */ 	li	$a0,0x7
/*  f0e7588:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e758c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7590:	00e02825 */ 	move	$a1,$a3
/*  f0e7594:	0320f809 */ 	jalr	$t9
/*  f0e7598:	00000000 */ 	nop
/*  f0e759c:	8fa8015c */ 	lw	$t0,0x15c($sp)
/*  f0e75a0:	3c010001 */ 	lui	$at,0x1
/*  f0e75a4:	0101082b */ 	sltu	$at,$t0,$at
/*  f0e75a8:	54200003 */ 	bnezl	$at,.JF0f0e75b8
/*  f0e75ac:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0e75b0:	2408ffff */ 	li	$t0,-1
/*  f0e75b4:	862c0002 */ 	lh	$t4,0x2($s1)
.JF0f0e75b8:
/*  f0e75b8:	24040001 */ 	li	$a0,0x1
/*  f0e75bc:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e75c0:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f0e75c4:	afae0104 */ 	sw	$t6,0x104($sp)
/*  f0e75c8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e75cc:	afa800f0 */ 	sw	$t0,0xf0($sp)
/*  f0e75d0:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e75d4:	00e02825 */ 	move	$a1,$a3
/*  f0e75d8:	0320f809 */ 	jalr	$t9
/*  f0e75dc:	00000000 */ 	nop
/*  f0e75e0:	8faf015c */ 	lw	$t7,0x15c($sp)
/*  f0e75e4:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f0e75e8:	afaf0108 */ 	sw	$t7,0x108($sp)
/*  f0e75ec:	870b0000 */ 	lh	$t3,0x0($t8)
/*  f0e75f0:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e75f4:	01762023 */ 	subu	$a0,$t3,$s6
/*  f0e75f8:	0fc39ab7 */ 	jal	0xf0e6adc
/*  f0e75fc:	00808025 */ 	move	$s0,$a0
/*  f0e7600:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e7604:	0040a825 */ 	move	$s5,$v0
/*  f0e7608:	02402025 */ 	move	$a0,$s2
/*  f0e760c:	01506821 */ 	addu	$t5,$t2,$s0
/*  f0e7610:	0fc54b55 */ 	jal	0xf152d54
/*  f0e7614:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f0e7618:	00152400 */ 	sll	$a0,$s5,0x10
/*  f0e761c:	afa00160 */ 	sw	$zero,0x160($sp)
/*  f0e7620:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0e7624:	00409025 */ 	move	$s2,$v0
/*  f0e7628:	02a09825 */ 	move	$s3,$s5
/*  f0e762c:	01802025 */ 	move	$a0,$t4
/*  f0e7630:	0fc39b2a */ 	jal	0xf0e6ca8
/*  f0e7634:	8e250008 */ 	lw	$a1,0x8($s1)
/*  f0e7638:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e763c:	00567021 */ 	addu	$t6,$v0,$s6
/*  f0e7640:	24040002 */ 	li	$a0,0x2
/*  f0e7644:	872f0000 */ 	lh	$t7,0x0($t9)
/*  f0e7648:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e764c:	afa00158 */ 	sw	$zero,0x158($sp)
/*  f0e7650:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7654:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e7658:	01cfa023 */ 	subu	$s4,$t6,$t7
/*  f0e765c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7660:	00e02825 */ 	move	$a1,$a3
/*  f0e7664:	0320f809 */ 	jalr	$t9
/*  f0e7668:	00000000 */ 	nop
/*  f0e766c:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e7670:	8fa3014c */ 	lw	$v1,0x14c($sp)
/*  f0e7674:	1b0002d7 */ 	blez	$t8,.JF0f0e81d4
/*  f0e7678:	afa30100 */ 	sw	$v1,0x100($sp)
/*  f0e767c:	1060005d */ 	beqz	$v1,.JF0f0e77f4
/*  f0e7680:	00008025 */ 	move	$s0,$zero
/*  f0e7684:	00004025 */ 	move	$t0,$zero
/*  f0e7688:	afa000fc */ 	sw	$zero,0xfc($sp)
/*  f0e768c:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0e7690:	1860001a */ 	blez	$v1,.JF0f0e76fc
/*  f0e7694:	afa00150 */ 	sw	$zero,0x150($sp)
/*  f0e7698:	8e270008 */ 	lw	$a3,0x8($s1)
.JF0f0e769c:
/*  f0e769c:	afa800c8 */ 	sw	$t0,0xc8($sp)
/*  f0e76a0:	24040005 */ 	li	$a0,0x5
/*  f0e76a4:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e76a8:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e76ac:	00e02825 */ 	move	$a1,$a3
/*  f0e76b0:	0320f809 */ 	jalr	$t9
/*  f0e76b4:	00000000 */ 	nop
/*  f0e76b8:	8fa30154 */ 	lw	$v1,0x154($sp)
/*  f0e76bc:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f0e76c0:	02a3082a */ 	slt	$at,$s5,$v1
/*  f0e76c4:	54200007 */ 	bnezl	$at,.JF0f0e76e4
/*  f0e76c8:	24100001 */ 	li	$s0,0x1
/*  f0e76cc:	8fa8014c */ 	lw	$t0,0x14c($sp)
/*  f0e76d0:	afa300fc */ 	sw	$v1,0xfc($sp)
/*  f0e76d4:	250d0001 */ 	addiu	$t5,$t0,0x1
/*  f0e76d8:	10000002 */ 	b	.JF0f0e76e4
/*  f0e76dc:	afad014c */ 	sw	$t5,0x14c($sp)
/*  f0e76e0:	24100001 */ 	li	$s0,0x1
.JF0f0e76e4:
/*  f0e76e4:	16000005 */ 	bnez	$s0,.JF0f0e76fc
/*  f0e76e8:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0e76ec:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f0e76f0:	018e082a */ 	slt	$at,$t4,$t6
/*  f0e76f4:	5420ffe9 */ 	bnezl	$at,.JF0f0e769c
/*  f0e76f8:	8e270008 */ 	lw	$a3,0x8($s1)
.JF0f0e76fc:
/*  f0e76fc:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e7700:	8faf0158 */ 	lw	$t7,0x158($sp)
/*  f0e7704:	afa8013c */ 	sw	$t0,0x13c($sp)
/*  f0e7708:	0315082a */ 	slt	$at,$t8,$s5
/*  f0e770c:	afa00140 */ 	sw	$zero,0x140($sp)
/*  f0e7710:	14200004 */ 	bnez	$at,.JF0f0e7724
/*  f0e7714:	afaf0148 */ 	sw	$t7,0x148($sp)
/*  f0e7718:	2a81000e */ 	slti	$at,$s4,0xe
/*  f0e771c:	50200036 */ 	beqzl	$at,.JF0f0e77f8
/*  f0e7720:	8faa00fc */ 	lw	$t2,0xfc($sp)
.JF0f0e7724:
/*  f0e7724:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7728:	24040004 */ 	li	$a0,0x4
/*  f0e772c:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e7730:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7734:	00e02825 */ 	move	$a1,$a3
/*  f0e7738:	0320f809 */ 	jalr	$t9
/*  f0e773c:	00000000 */ 	nop
/*  f0e7740:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0e7744:	8d6b16e8 */ 	lw	$t3,0x16e8($t3)
/*  f0e7748:	87ad00ee */ 	lh	$t5,0xee($sp)
/*  f0e774c:	240c000e */ 	li	$t4,0xe
/*  f0e7750:	028b5021 */ 	addu	$t2,$s4,$t3
/*  f0e7754:	5940000f */ 	blezl	$t2,.JF0f0e7794
/*  f0e7758:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f0e775c:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e7760:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e7764:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e7768:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e776c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e7770:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7774:	8e2e0010 */ 	lw	$t6,0x10($s1)
/*  f0e7778:	02402025 */ 	move	$a0,$s2
/*  f0e777c:	0fc39b79 */ 	jal	0xf0e6de4
/*  f0e7780:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e7784:	240f0001 */ 	li	$t7,0x1
/*  f0e7788:	00409025 */ 	move	$s2,$v0
/*  f0e778c:	a3af00ed */ 	sb	$t7,0xed($sp)
/*  f0e7790:	8fb80104 */ 	lw	$t8,0x104($sp)
.JF0f0e7794:
/*  f0e7794:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e7798:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e779c:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e77a0:	2719000e */ 	addiu	$t9,$t8,0xe
/*  f0e77a4:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f0e77a8:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e77ac:	afb90104 */ 	sw	$t9,0x104($sp)
/*  f0e77b0:	1020000e */ 	beqz	$at,.JF0f0e77ec
/*  f0e77b4:	afaa013c */ 	sw	$t2,0x13c($sp)
/*  f0e77b8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e77bc:	24040005 */ 	li	$a0,0x5
/*  f0e77c0:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e77c4:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e77c8:	00e02825 */ 	move	$a1,$a3
/*  f0e77cc:	0320f809 */ 	jalr	$t9
/*  f0e77d0:	00000000 */ 	nop
/*  f0e77d4:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e77d8:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e77dc:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e77e0:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e77e4:	10000003 */ 	b	.JF0f0e77f4
/*  f0e77e8:	afae00fc */ 	sw	$t6,0xfc($sp)
.JF0f0e77ec:
/*  f0e77ec:	240b270f */ 	li	$t3,0x270f
/*  f0e77f0:	afab00fc */ 	sw	$t3,0xfc($sp)
.JF0f0e77f4:
/*  f0e77f4:	8faa00fc */ 	lw	$t2,0xfc($sp)
.JF0f0e77f8:
/*  f0e77f8:	3c167f1b */ 	lui	$s6,0x7f1b
/*  f0e77fc:	26d62ce0 */ 	addiu	$s6,$s6,0x2ce0
/*  f0e7800:	56aa0003 */ 	bnel	$s5,$t2,.JF0f0e7810
/*  f0e7804:	2415003c */ 	li	$s5,0x3c
/*  f0e7808:	2694fff2 */ 	addiu	$s4,$s4,-14
/*  f0e780c:	2415003c */ 	li	$s5,0x3c
.JF0f0e7810:
/*  f0e7810:	8e230010 */ 	lw	$v1,0x10($s1)
.JF0f0e7814:
/*  f0e7814:	44809000 */ 	mtc1	$zero,$f18
/*  f0e7818:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0e781c:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0e7820:	00000000 */ 	nop
/*  f0e7824:	45020008 */ 	bc1fl	.JF0f0e7848
/*  f0e7828:	906e003d */ 	lbu	$t6,0x3d($v1)
/*  f0e782c:	906d003c */ 	lbu	$t5,0x3c($v1)
/*  f0e7830:	01b50019 */ 	multu	$t5,$s5
/*  f0e7834:	00006012 */ 	mflo	$t4
/*  f0e7838:	02ccc821 */ 	addu	$t9,$s6,$t4
/*  f0e783c:	1000000f */ 	b	.JF0f0e787c
/*  f0e7840:	8f300018 */ 	lw	$s0,0x18($t9)
/*  f0e7844:	906e003d */ 	lbu	$t6,0x3d($v1)
.JF0f0e7848:
/*  f0e7848:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e784c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7850:	01d50019 */ 	multu	$t6,$s5
/*  f0e7854:	00007812 */ 	mflo	$t7
/*  f0e7858:	02cfc021 */ 	addu	$t8,$s6,$t7
/*  f0e785c:	8f040018 */ 	lw	$a0,0x18($t8)
/*  f0e7860:	01750019 */ 	multu	$t3,$s5
/*  f0e7864:	00005012 */ 	mflo	$t2
/*  f0e7868:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e786c:	0fc01a60 */ 	jal	0xf006980
/*  f0e7870:	8da50018 */ 	lw	$a1,0x18($t5)
/*  f0e7874:	00408025 */ 	move	$s0,$v0
/*  f0e7878:	8e230010 */ 	lw	$v1,0x10($s1)
.JF0f0e787c:
/*  f0e787c:	8c6c000c */ 	lw	$t4,0xc($v1)
/*  f0e7880:	02002025 */ 	move	$a0,$s0
/*  f0e7884:	00002825 */ 	move	$a1,$zero
/*  f0e7888:	51800009 */ 	beqzl	$t4,.JF0f0e78b0
/*  f0e788c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e7890:	0fc01a60 */ 	jal	0xf006980
/*  f0e7894:	2406007f */ 	li	$a2,0x7f
/*  f0e7898:	2401ff00 */ 	li	$at,-256
/*  f0e789c:	0041c824 */ 	and	$t9,$v0,$at
/*  f0e78a0:	320e00ff */ 	andi	$t6,$s0,0xff
/*  f0e78a4:	032e8025 */ 	or	$s0,$t9,$t6
/*  f0e78a8:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e78ac:	906f003c */ 	lbu	$t7,0x3c($v1)
.JF0f0e78b0:
/*  f0e78b0:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e78b4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e78b8:	01f50019 */ 	multu	$t7,$s5
/*  f0e78bc:	00001012 */ 	mflo	$v0
/*  f0e78c0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e78c4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e78c8:	8ca52e60 */ 	lw	$a1,0x2e60($a1)
/*  f0e78cc:	0fc54d69 */ 	jal	0xf1535a4
/*  f0e78d0:	8c842fc8 */ 	lw	$a0,0x2fc8($a0)
/*  f0e78d4:	8fb800fc */ 	lw	$t8,0xfc($sp)
/*  f0e78d8:	8faa0108 */ 	lw	$t2,0x108($sp)
/*  f0e78dc:	1678003f */ 	bne	$s3,$t8,.JF0f0e79dc
/*  f0e78e0:	026a082a */ 	slt	$at,$s3,$t2
/*  f0e78e4:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e78e8:	8ceb0004 */ 	lw	$t3,0x4($a3)
/*  f0e78ec:	000b5280 */ 	sll	$t2,$t3,0xa
/*  f0e78f0:	05430006 */ 	bgezl	$t2,.JF0f0e790c
/*  f0e78f4:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e78f8:	0fc3d768 */ 	jal	0xf0f5da0
/*  f0e78fc:	02402025 */ 	move	$a0,$s2
/*  f0e7900:	00409025 */ 	move	$s2,$v0
/*  f0e7904:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7908:	8cf90010 */ 	lw	$t9,0x10($a3)
.JF0f0e790c:
/*  f0e790c:	24040004 */ 	li	$a0,0x4
/*  f0e7910:	00e02825 */ 	move	$a1,$a3
/*  f0e7914:	0320f809 */ 	jalr	$t9
/*  f0e7918:	27a6013c */ 	addiu	$a2,$sp,0x13c
/*  f0e791c:	8fad013c */ 	lw	$t5,0x13c($sp)
/*  f0e7920:	00404025 */ 	move	$t0,$v0
/*  f0e7924:	02402025 */ 	move	$a0,$s2
/*  f0e7928:	25ac0001 */ 	addiu	$t4,$t5,0x1
/*  f0e792c:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0e7930:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e7934:	87aa00ee */ 	lh	$t2,0xee($sp)
/*  f0e7938:	01d41823 */ 	subu	$v1,$t6,$s4
/*  f0e793c:	2861000f */ 	slti	$at,$v1,0xf
/*  f0e7940:	54200003 */ 	bnezl	$at,.JF0f0e7950
/*  f0e7944:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e7948:	2403000e */ 	li	$v1,0xe
/*  f0e794c:	862f0002 */ 	lh	$t7,0x2($s1)
.JF0f0e7950:
/*  f0e7950:	86250000 */ 	lh	$a1,0x0($s1)
/*  f0e7954:	86270004 */ 	lh	$a3,0x4($s1)
/*  f0e7958:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e795c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e7960:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e7964:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f0e7968:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e796c:	0006c400 */ 	sll	$t8,$a2,0x10
/*  f0e7970:	00183403 */ 	sra	$a2,$t8,0x10
/*  f0e7974:	0fc39b79 */ 	jal	0xf0e6de4
/*  f0e7978:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e797c:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0e7980:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f0e7984:	00409025 */ 	move	$s2,$v0
/*  f0e7988:	240b270f */ 	li	$t3,0x270f
/*  f0e798c:	01ac082a */ 	slt	$at,$t5,$t4
/*  f0e7990:	50200010 */ 	beqzl	$at,.JF0f0e79d4
/*  f0e7994:	afab00fc */ 	sw	$t3,0xfc($sp)
/*  f0e7998:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e799c:	24040005 */ 	li	$a0,0x5
/*  f0e79a0:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0e79a4:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e79a8:	00e02825 */ 	move	$a1,$a3
/*  f0e79ac:	0320f809 */ 	jalr	$t9
/*  f0e79b0:	00000000 */ 	nop
/*  f0e79b4:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0e79b8:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e79bc:	2694000e */ 	addiu	$s4,$s4,0xe
/*  f0e79c0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0e79c4:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0e79c8:	100001f5 */ 	b	.JF0f0e81a0
/*  f0e79cc:	afae00fc */ 	sw	$t6,0xfc($sp)
/*  f0e79d0:	afab00fc */ 	sw	$t3,0xfc($sp)
.JF0f0e79d4:
/*  f0e79d4:	100001f2 */ 	b	.JF0f0e81a0
/*  f0e79d8:	2694000e */ 	addiu	$s4,$s4,0xe
.JF0f0e79dc:
/*  f0e79dc:	502001e8 */ 	beqzl	$at,.JF0f0e8180
/*  f0e79e0:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e79e4:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f0e79e8:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f0e79ec:	2401ff00 */ 	li	$at,-256
/*  f0e79f0:	15b30003 */ 	bne	$t5,$s3,.JF0f0e7a00
/*  f0e79f4:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e79f8:	02016025 */ 	or	$t4,$s0,$at
/*  f0e79fc:	01808025 */ 	move	$s0,$t4
.JF0f0e7a00:
/*  f0e7a00:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e7a04:	566e0069 */ 	bnel	$s3,$t6,.JF0f0e7bac
/*  f0e7a08:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e7a0c:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0e7a10:	3c014220 */ 	lui	$at,0x4220
/*  f0e7a14:	51e00065 */ 	beqzl	$t7,.JF0f0e7bac
/*  f0e7a18:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e7a1c:	44816000 */ 	mtc1	$at,$f12
/*  f0e7a20:	0fc01ae2 */ 	jal	0xf006b88
/*  f0e7a24:	00000000 */ 	nop
/*  f0e7a28:	3c01437f */ 	lui	$at,0x437f
/*  f0e7a2c:	44812000 */ 	mtc1	$at,$f4
/*  f0e7a30:	240b0001 */ 	li	$t3,0x1
/*  f0e7a34:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e7a38:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e7a3c:	4458f800 */ 	cfc1	$t8,$31
/*  f0e7a40:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7a44:	00000000 */ 	nop
/*  f0e7a48:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e7a4c:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7a50:	00000000 */ 	nop
/*  f0e7a54:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7a58:	51600013 */ 	beqzl	$t3,.JF0f0e7aa8
/*  f0e7a5c:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e7a60:	44814000 */ 	mtc1	$at,$f8
/*  f0e7a64:	240b0001 */ 	li	$t3,0x1
/*  f0e7a68:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e7a6c:	44cbf800 */ 	ctc1	$t3,$31
/*  f0e7a70:	00000000 */ 	nop
/*  f0e7a74:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e7a78:	444bf800 */ 	cfc1	$t3,$31
/*  f0e7a7c:	00000000 */ 	nop
/*  f0e7a80:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0e7a84:	15600005 */ 	bnez	$t3,.JF0f0e7a9c
/*  f0e7a88:	00000000 */ 	nop
/*  f0e7a8c:	440b4000 */ 	mfc1	$t3,$f8
/*  f0e7a90:	3c018000 */ 	lui	$at,0x8000
/*  f0e7a94:	10000007 */ 	b	.JF0f0e7ab4
/*  f0e7a98:	01615825 */ 	or	$t3,$t3,$at
.JF0f0e7a9c:
/*  f0e7a9c:	10000005 */ 	b	.JF0f0e7ab4
/*  f0e7aa0:	240bffff */ 	li	$t3,-1
/*  f0e7aa4:	440b4000 */ 	mfc1	$t3,$f8
.JF0f0e7aa8:
/*  f0e7aa8:	00000000 */ 	nop
/*  f0e7aac:	0560fffb */ 	bltz	$t3,.JF0f0e7a9c
/*  f0e7ab0:	00000000 */ 	nop
.JF0f0e7ab4:
/*  f0e7ab4:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e7ab8:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e7abc:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e7ac0:	44808000 */ 	mtc1	$zero,$f16
/*  f0e7ac4:	c46a0040 */ 	lwc1	$f10,0x40($v1)
/*  f0e7ac8:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0e7acc:	00000000 */ 	nop
/*  f0e7ad0:	45020008 */ 	bc1fl	.JF0f0e7af4
/*  f0e7ad4:	9079003d */ 	lbu	$t9,0x3d($v1)
/*  f0e7ad8:	906a003c */ 	lbu	$t2,0x3c($v1)
/*  f0e7adc:	01550019 */ 	multu	$t2,$s5
/*  f0e7ae0:	00006812 */ 	mflo	$t5
/*  f0e7ae4:	02cd6021 */ 	addu	$t4,$s6,$t5
/*  f0e7ae8:	1000000e */ 	b	.JF0f0e7b24
/*  f0e7aec:	8d870020 */ 	lw	$a3,0x20($t4)
/*  f0e7af0:	9079003d */ 	lbu	$t9,0x3d($v1)
.JF0f0e7af4:
/*  f0e7af4:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e7af8:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e7afc:	03350019 */ 	multu	$t9,$s5
/*  f0e7b00:	00007012 */ 	mflo	$t6
/*  f0e7b04:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0e7b08:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0e7b0c:	03150019 */ 	multu	$t8,$s5
/*  f0e7b10:	00005812 */ 	mflo	$t3
/*  f0e7b14:	02cb5021 */ 	addu	$t2,$s6,$t3
/*  f0e7b18:	0fc01a60 */ 	jal	0xf006980
/*  f0e7b1c:	8d450020 */ 	lw	$a1,0x20($t2)
/*  f0e7b20:	00403825 */ 	move	$a3,$v0
.JF0f0e7b24:
/*  f0e7b24:	02002025 */ 	move	$a0,$s0
/*  f0e7b28:	320500ff */ 	andi	$a1,$s0,0xff
/*  f0e7b2c:	2406007f */ 	li	$a2,0x7f
/*  f0e7b30:	0fc01a60 */ 	jal	0xf006980
/*  f0e7b34:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f0e7b38:	8fa500b0 */ 	lw	$a1,0xb0($sp)
/*  f0e7b3c:	00402025 */ 	move	$a0,$v0
/*  f0e7b40:	0fc01a60 */ 	jal	0xf006980
/*  f0e7b44:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e7b48:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e7b4c:	44809000 */ 	mtc1	$zero,$f18
/*  f0e7b50:	00408025 */ 	move	$s0,$v0
/*  f0e7b54:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f0e7b58:	4600903e */ 	c.le.s	$f18,$f0
/*  f0e7b5c:	00000000 */ 	nop
/*  f0e7b60:	45020005 */ 	bc1fl	.JF0f0e7b78
/*  f0e7b64:	44802000 */ 	mtc1	$zero,$f4
/*  f0e7b68:	906d003d */ 	lbu	$t5,0x3d($v1)
/*  f0e7b6c:	51a0000f */ 	beqzl	$t5,.JF0f0e7bac
/*  f0e7b70:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0e7b74:	44802000 */ 	mtc1	$zero,$f4
.JF0f0e7b78:
/*  f0e7b78:	00000000 */ 	nop
/*  f0e7b7c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e7b80:	00000000 */ 	nop
/*  f0e7b84:	45000004 */ 	bc1f	.JF0f0e7b98
/*  f0e7b88:	00000000 */ 	nop
/*  f0e7b8c:	906c003c */ 	lbu	$t4,0x3c($v1)
/*  f0e7b90:	51800006 */ 	beqzl	$t4,.JF0f0e7bac
/*  f0e7b94:	8e2e0008 */ 	lw	$t6,0x8($s1)
.JF0f0e7b98:
/*  f0e7b98:	0fc55880 */ 	jal	0xf156200
/*  f0e7b9c:	24040001 */ 	li	$a0,0x1
/*  f0e7ba0:	24190001 */ 	li	$t9,0x1
/*  f0e7ba4:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0e7ba8:	8e2e0008 */ 	lw	$t6,0x8($s1)
.JF0f0e7bac:
/*  f0e7bac:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f0e7bb0:	000fc280 */ 	sll	$t8,$t7,0xa
/*  f0e7bb4:	07030116 */ 	bgezl	$t8,.JF0f0e8010
/*  f0e7bb8:	afb3015c */ 	sw	$s3,0x15c($sp)
/*  f0e7bbc:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0e7bc0:	8fb9016c */ 	lw	$t9,0x16c($sp)
/*  f0e7bc4:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e7bc8:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0e7bcc:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e7bd0:	8dad16e8 */ 	lw	$t5,0x16e8($t5)
/*  f0e7bd4:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0e7bd8:	01542821 */ 	addu	$a1,$t2,$s4
/*  f0e7bdc:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0e7be0:	862c0004 */ 	lh	$t4,0x4($s1)
/*  f0e7be4:	afb000a4 */ 	sw	$s0,0xa4($sp)
/*  f0e7be8:	afac00a0 */ 	sw	$t4,0xa0($sp)
/*  f0e7bec:	872e0002 */ 	lh	$t6,0x2($t9)
/*  f0e7bf0:	008c1821 */ 	addu	$v1,$a0,$t4
/*  f0e7bf4:	00ad6021 */ 	addu	$t4,$a1,$t5
/*  f0e7bf8:	026e7826 */ 	xor	$t7,$s3,$t6
/*  f0e7bfc:	2def0001 */ 	sltiu	$t7,$t7,0x1
/*  f0e7c00:	a3af00a8 */ 	sb	$t7,0xa8($sp)
/*  f0e7c04:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0e7c08:	86260002 */ 	lh	$a2,0x2($s1)
/*  f0e7c0c:	27b90098 */ 	addiu	$t9,$sp,0x98
/*  f0e7c10:	00603825 */ 	move	$a3,$v1
/*  f0e7c14:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0e7c18:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0e7c1c:	10200002 */ 	beqz	$at,.JF0f0e7c28
/*  f0e7c20:	93af00ed */ 	lbu	$t7,0xed($sp)
/*  f0e7c24:	00c02825 */ 	move	$a1,$a2
.JF0f0e7c28:
/*  f0e7c28:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0e7c2c:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f0e7c30:	00ce1021 */ 	addu	$v0,$a2,$t6
/*  f0e7c34:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0e7c38:	0050082a */ 	slt	$at,$v0,$s0
/*  f0e7c3c:	10200002 */ 	beqz	$at,.JF0f0e7c48
/*  f0e7c40:	00000000 */ 	nop
/*  f0e7c44:	00408025 */ 	move	$s0,$v0
.JF0f0e7c48:
/*  f0e7c48:	11e00005 */ 	beqz	$t7,.JF0f0e7c60
/*  f0e7c4c:	24c2000e */ 	addiu	$v0,$a2,0xe
/*  f0e7c50:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0e7c54:	10200002 */ 	beqz	$at,.JF0f0e7c60
/*  f0e7c58:	00000000 */ 	nop
/*  f0e7c5c:	00402825 */ 	move	$a1,$v0
.JF0f0e7c60:
/*  f0e7c60:	07010002 */ 	bgez	$t8,.JF0f0e7c6c
/*  f0e7c64:	00000000 */ 	nop
/*  f0e7c68:	00002025 */ 	move	$a0,$zero
.JF0f0e7c6c:
/*  f0e7c6c:	04630003 */ 	bgezl	$v1,.JF0f0e7c7c
/*  f0e7c70:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e7c74:	00003825 */ 	move	$a3,$zero
/*  f0e7c78:	afa40094 */ 	sw	$a0,0x94($sp)
.JF0f0e7c7c:
/*  f0e7c7c:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e7c80:	0c002eeb */ 	jal	0xbbac
/*  f0e7c84:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e7c88:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0e7c8c:	8d4a00f4 */ 	lw	$t2,0xf4($t2)
/*  f0e7c90:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e7c94:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e7c98:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e7c9c:	008a001a */ 	div	$zero,$a0,$t2
/*  f0e7ca0:	15400002 */ 	bnez	$t2,.JF0f0e7cac
/*  f0e7ca4:	00000000 */ 	nop
/*  f0e7ca8:	0007000d */ 	break	0x7
.JF0f0e7cac:
/*  f0e7cac:	2401ffff */ 	li	$at,-1
/*  f0e7cb0:	15410004 */ 	bne	$t2,$at,.JF0f0e7cc4
/*  f0e7cb4:	3c018000 */ 	lui	$at,0x8000
/*  f0e7cb8:	14810002 */ 	bne	$a0,$at,.JF0f0e7cc4
/*  f0e7cbc:	00000000 */ 	nop
/*  f0e7cc0:	0006000d */ 	break	0x6
.JF0f0e7cc4:
/*  f0e7cc4:	00006812 */ 	mflo	$t5
/*  f0e7cc8:	004d082a */ 	slt	$at,$v0,$t5
/*  f0e7ccc:	50200014 */ 	beqzl	$at,.JF0f0e7d20
/*  f0e7cd0:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e7cd4:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e7cd8:	0c002eeb */ 	jal	0xbbac
/*  f0e7cdc:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e7ce0:	3c198008 */ 	lui	$t9,0x8008
/*  f0e7ce4:	8f3900f4 */ 	lw	$t9,0xf4($t9)
/*  f0e7ce8:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e7cec:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e7cf0:	0059001a */ 	div	$zero,$v0,$t9
/*  f0e7cf4:	00002012 */ 	mflo	$a0
/*  f0e7cf8:	17200002 */ 	bnez	$t9,.JF0f0e7d04
/*  f0e7cfc:	00000000 */ 	nop
/*  f0e7d00:	0007000d */ 	break	0x7
.JF0f0e7d04:
/*  f0e7d04:	2401ffff */ 	li	$at,-1
/*  f0e7d08:	17210004 */ 	bne	$t9,$at,.JF0f0e7d1c
/*  f0e7d0c:	3c018000 */ 	lui	$at,0x8000
/*  f0e7d10:	14410002 */ 	bne	$v0,$at,.JF0f0e7d1c
/*  f0e7d14:	00000000 */ 	nop
/*  f0e7d18:	0006000d */ 	break	0x6
.JF0f0e7d1c:
/*  f0e7d1c:	afa40094 */ 	sw	$a0,0x94($sp)
.JF0f0e7d20:
/*  f0e7d20:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e7d24:	0c002eeb */ 	jal	0xbbac
/*  f0e7d28:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f0e7d2c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e7d30:	8d6b00f4 */ 	lw	$t3,0xf4($t3)
/*  f0e7d34:	8fa7008c */ 	lw	$a3,0x8c($sp)
/*  f0e7d38:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e7d3c:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e7d40:	00eb001a */ 	div	$zero,$a3,$t3
/*  f0e7d44:	15600002 */ 	bnez	$t3,.JF0f0e7d50
/*  f0e7d48:	00000000 */ 	nop
/*  f0e7d4c:	0007000d */ 	break	0x7
.JF0f0e7d50:
/*  f0e7d50:	2401ffff */ 	li	$at,-1
/*  f0e7d54:	15610004 */ 	bne	$t3,$at,.JF0f0e7d68
/*  f0e7d58:	3c018000 */ 	lui	$at,0x8000
/*  f0e7d5c:	14e10002 */ 	bne	$a3,$at,.JF0f0e7d68
/*  f0e7d60:	00000000 */ 	nop
/*  f0e7d64:	0006000d */ 	break	0x6
.JF0f0e7d68:
/*  f0e7d68:	00006012 */ 	mflo	$t4
/*  f0e7d6c:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e7d70:	50200014 */ 	beqzl	$at,.JF0f0e7dc4
/*  f0e7d74:	02401025 */ 	move	$v0,$s2
/*  f0e7d78:	afa40094 */ 	sw	$a0,0x94($sp)
/*  f0e7d7c:	0c002eeb */ 	jal	0xbbac
/*  f0e7d80:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0e7d84:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e7d88:	8dce00f4 */ 	lw	$t6,0xf4($t6)
/*  f0e7d8c:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f0e7d90:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0e7d94:	004e001a */ 	div	$zero,$v0,$t6
/*  f0e7d98:	00003812 */ 	mflo	$a3
/*  f0e7d9c:	15c00002 */ 	bnez	$t6,.JF0f0e7da8
/*  f0e7da0:	00000000 */ 	nop
/*  f0e7da4:	0007000d */ 	break	0x7
.JF0f0e7da8:
/*  f0e7da8:	2401ffff */ 	li	$at,-1
/*  f0e7dac:	15c10004 */ 	bne	$t6,$at,.JF0f0e7dc0
/*  f0e7db0:	3c018000 */ 	lui	$at,0x8000
/*  f0e7db4:	14410002 */ 	bne	$v0,$at,.JF0f0e7dc0
/*  f0e7db8:	00000000 */ 	nop
/*  f0e7dbc:	0006000d */ 	break	0x6
.JF0f0e7dc0:
/*  f0e7dc0:	02401025 */ 	move	$v0,$s2
.JF0f0e7dc4:
/*  f0e7dc4:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0e7dc8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0e7dcc:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0e7dd0:	3c038008 */ 	lui	$v1,0x8008
/*  f0e7dd4:	8c6300f4 */ 	lw	$v1,0xf4($v1)
/*  f0e7dd8:	3c068007 */ 	lui	$a2,0x8007
/*  f0e7ddc:	24c616d0 */ 	addiu	$a2,$a2,0x16d0
/*  f0e7de0:	00830019 */ 	multu	$a0,$v1
/*  f0e7de4:	3c018007 */ 	lui	$at,0x8007
/*  f0e7de8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e7dec:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0e7df0:	0000c012 */ 	mflo	$t8
/*  f0e7df4:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0e7df8:	00000000 */ 	nop
/*  f0e7dfc:	00e30019 */ 	multu	$a3,$v1
/*  f0e7e00:	00005012 */ 	mflo	$t2
/*  f0e7e04:	aeea0000 */ 	sw	$t2,0x0($s7)
/*  f0e7e08:	ac2516d8 */ 	sw	$a1,0x16d8($at)
/*  f0e7e0c:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e7e10:	afd00000 */ 	sw	$s0,0x0($s8)
/*  f0e7e14:	3c018007 */ 	lui	$at,0x8007
/*  f0e7e18:	05a30003 */ 	bgezl	$t5,.JF0f0e7e28
/*  f0e7e1c:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e7e20:	ac2016d0 */ 	sw	$zero,0x16d0($at)
/*  f0e7e24:	8ef90000 */ 	lw	$t9,0x0($s7)
.JF0f0e7e28:
/*  f0e7e28:	3c018007 */ 	lui	$at,0x8007
/*  f0e7e2c:	07210002 */ 	bgez	$t9,.JF0f0e7e38
/*  f0e7e30:	00000000 */ 	nop
/*  f0e7e34:	aee00000 */ 	sw	$zero,0x0($s7)
.JF0f0e7e38:
/*  f0e7e38:	8d6b16d8 */ 	lw	$t3,0x16d8($t3)
/*  f0e7e3c:	05630003 */ 	bgezl	$t3,.JF0f0e7e4c
/*  f0e7e40:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0e7e44:	ac2016d8 */ 	sw	$zero,0x16d8($at)
/*  f0e7e48:	8fcc0000 */ 	lw	$t4,0x0($s8)
.JF0f0e7e4c:
/*  f0e7e4c:	05810002 */ 	bgez	$t4,.JF0f0e7e58
/*  f0e7e50:	00000000 */ 	nop
/*  f0e7e54:	afc00000 */ 	sw	$zero,0x0($s8)
.JF0f0e7e58:
/*  f0e7e58:	0c002eda */ 	jal	0xbb68
/*  f0e7e5c:	00000000 */ 	nop
/*  f0e7e60:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0e7e64:	8dce16d0 */ 	lw	$t6,0x16d0($t6)
/*  f0e7e68:	004e082a */ 	slt	$at,$v0,$t6
/*  f0e7e6c:	10200005 */ 	beqz	$at,.JF0f0e7e84
/*  f0e7e70:	00000000 */ 	nop
/*  f0e7e74:	0c002eda */ 	jal	0xbb68
/*  f0e7e78:	00000000 */ 	nop
/*  f0e7e7c:	3c018007 */ 	lui	$at,0x8007
/*  f0e7e80:	ac2216d0 */ 	sw	$v0,0x16d0($at)
.JF0f0e7e84:
/*  f0e7e84:	0c002eda */ 	jal	0xbb68
/*  f0e7e88:	00000000 */ 	nop
/*  f0e7e8c:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e7e90:	004f082a */ 	slt	$at,$v0,$t7
/*  f0e7e94:	10200004 */ 	beqz	$at,.JF0f0e7ea8
/*  f0e7e98:	00000000 */ 	nop
/*  f0e7e9c:	0c002eda */ 	jal	0xbb68
/*  f0e7ea0:	00000000 */ 	nop
/*  f0e7ea4:	aee20000 */ 	sw	$v0,0x0($s7)
.JF0f0e7ea8:
/*  f0e7ea8:	0c002ede */ 	jal	0xbb78
/*  f0e7eac:	00000000 */ 	nop
/*  f0e7eb0:	3c188007 */ 	lui	$t8,0x8007
/*  f0e7eb4:	8f1816d8 */ 	lw	$t8,0x16d8($t8)
/*  f0e7eb8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0e7ebc:	10200005 */ 	beqz	$at,.JF0f0e7ed4
/*  f0e7ec0:	00000000 */ 	nop
/*  f0e7ec4:	0c002ede */ 	jal	0xbb78
/*  f0e7ec8:	00000000 */ 	nop
/*  f0e7ecc:	3c018007 */ 	lui	$at,0x8007
/*  f0e7ed0:	ac2216d8 */ 	sw	$v0,0x16d8($at)
.JF0f0e7ed4:
/*  f0e7ed4:	0c002ede */ 	jal	0xbb78
/*  f0e7ed8:	00000000 */ 	nop
/*  f0e7edc:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e7ee0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e7ee4:	10200005 */ 	beqz	$at,.JF0f0e7efc
/*  f0e7ee8:	00000000 */ 	nop
/*  f0e7eec:	0c002ede */ 	jal	0xbb78
/*  f0e7ef0:	00000000 */ 	nop
/*  f0e7ef4:	afc20000 */ 	sw	$v0,0x0($s8)
/*  f0e7ef8:	00401825 */ 	move	$v1,$v0
.JF0f0e7efc:
/*  f0e7efc:	3c098007 */ 	lui	$t1,0x8007
/*  f0e7f00:	8d2916d0 */ 	lw	$t1,0x16d0($t1)
/*  f0e7f04:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f0e7f08:	3c088007 */ 	lui	$t0,0x8007
/*  f0e7f0c:	44893000 */ 	mtc1	$t1,$f6
/*  f0e7f10:	0149082a */ 	slt	$at,$t2,$t1
/*  f0e7f14:	10200002 */ 	beqz	$at,.JF0f0e7f20
/*  f0e7f18:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e7f1c:	aee90000 */ 	sw	$t1,0x0($s7)
.JF0f0e7f20:
/*  f0e7f20:	8d0816d8 */ 	lw	$t0,0x16d8($t0)
/*  f0e7f24:	0068082a */ 	slt	$at,$v1,$t0
/*  f0e7f28:	50200003 */ 	beqzl	$at,.JF0f0e7f38
/*  f0e7f2c:	44889000 */ 	mtc1	$t0,$f18
/*  f0e7f30:	afc80000 */ 	sw	$t0,0x0($s8)
/*  f0e7f34:	44889000 */ 	mtc1	$t0,$f18
.JF0f0e7f38:
/*  f0e7f38:	3c014080 */ 	lui	$at,0x4080
/*  f0e7f3c:	44810000 */ 	mtc1	$at,$f0
/*  f0e7f40:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e7f44:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e7f48:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e7f4c:	02401025 */ 	move	$v0,$s2
/*  f0e7f50:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e7f54:	24040013 */ 	li	$a0,0x13
/*  f0e7f58:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0e7f5c:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e7f60:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e7f64:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e7f68:	44198000 */ 	mfc1	$t9,$f16
/*  f0e7f6c:	44184000 */ 	mfc1	$t8,$f8
/*  f0e7f70:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f0e7f74:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f0e7f78:	01817025 */ 	or	$t6,$t4,$at
/*  f0e7f7c:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f0e7f80:	01ca6825 */ 	or	$t5,$t6,$t2
/*  f0e7f84:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0e7f88:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0e7f8c:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f0e7f90:	44995000 */ 	mtc1	$t9,$f10
/*  f0e7f94:	448e3000 */ 	mtc1	$t6,$f6
/*  f0e7f98:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e7f9c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e7fa0:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e7fa4:	00000000 */ 	nop
/*  f0e7fa8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0e7fac:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e7fb0:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e7fb4:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e7fb8:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e7fbc:	318f0fff */ 	andi	$t7,$t4,0xfff
/*  f0e7fc0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0e7fc4:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f0e7fc8:	03195825 */ 	or	$t3,$t8,$t9
/*  f0e7fcc:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0e7fd0:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0e7fd4:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f0e7fd8:	afb200b8 */ 	sw	$s2,0xb8($sp)
/*  f0e7fdc:	afb300bc */ 	sw	$s3,0xbc($sp)
/*  f0e7fe0:	afac00c0 */ 	sw	$t4,0xc0($sp)
/*  f0e7fe4:	afaf00c4 */ 	sw	$t7,0xc4($sp)
/*  f0e7fe8:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e7fec:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e7ff0:	00e02825 */ 	move	$a1,$a3
/*  f0e7ff4:	0320f809 */ 	jalr	$t9
/*  f0e7ff8:	00000000 */ 	nop
/*  f0e7ffc:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0e8000:	00409025 */ 	move	$s2,$v0
/*  f0e8004:	10000058 */ 	b	.JF0f0e8168
/*  f0e8008:	afae0160 */ 	sw	$t6,0x160($sp)
/*  f0e800c:	afb3015c */ 	sw	$s3,0x15c($sp)
.JF0f0e8010:
/*  f0e8010:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e8014:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0e8018:	24040003 */ 	li	$a0,0x3
/*  f0e801c:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e8020:	27a6015c */ 	addiu	$a2,$sp,0x15c
/*  f0e8024:	00004025 */ 	move	$t0,$zero
/*  f0e8028:	0320f809 */ 	jalr	$t9
/*  f0e802c:	00e02825 */ 	move	$a1,$a3
/*  f0e8030:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e8034:	2401000c */ 	li	$at,0xc
/*  f0e8038:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e803c:	01546821 */ 	addu	$t5,$t2,$s4
/*  f0e8040:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f0e8044:	afb8012c */ 	sw	$t8,0x12c($sp)
/*  f0e8048:	8e2b0008 */ 	lw	$t3,0x8($s1)
/*  f0e804c:	00403825 */ 	move	$a3,$v0
/*  f0e8050:	8fac011c */ 	lw	$t4,0x11c($sp)
/*  f0e8054:	91630000 */ 	lbu	$v1,0x0($t3)
/*  f0e8058:	02402025 */ 	move	$a0,$s2
/*  f0e805c:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e8060:	10610004 */ 	beq	$v1,$at,.JF0f0e8074
/*  f0e8064:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e8068:	2401000f */ 	li	$at,0xf
/*  f0e806c:	14610003 */ 	bne	$v1,$at,.JF0f0e807c
/*  f0e8070:	8faf011c */ 	lw	$t7,0x11c($sp)
.JF0f0e8074:
/*  f0e8074:	10000003 */ 	b	.JF0f0e8084
/*  f0e8078:	afac0130 */ 	sw	$t4,0x130($sp)
.JF0f0e807c:
/*  f0e807c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f0e8080:	afae0130 */ 	sw	$t6,0x130($sp)
.JF0f0e8084:
/*  f0e8084:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0e8088:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f0e808c:	0059082a */ 	slt	$at,$v0,$t9
/*  f0e8090:	50200004 */ 	beqzl	$at,.JF0f0e80a4
/*  f0e8094:	862a0002 */ 	lh	$t2,0x2($s1)
/*  f0e8098:	00594023 */ 	subu	$t0,$v0,$t9
/*  f0e809c:	afb9012c */ 	sw	$t9,0x12c($sp)
/*  f0e80a0:	862a0002 */ 	lh	$t2,0x2($s1)
.JF0f0e80a4:
/*  f0e80a4:	862d0006 */ 	lh	$t5,0x6($s1)
/*  f0e80a8:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f0e80ac:	8fac00e8 */ 	lw	$t4,0xe8($sp)
/*  f0e80b0:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e80b4:	030b1823 */ 	subu	$v1,$t8,$t3
/*  f0e80b8:	04630003 */ 	bgezl	$v1,.JF0f0e80c8
/*  f0e80bc:	8faf00f4 */ 	lw	$t7,0xf4($sp)
/*  f0e80c0:	00001825 */ 	move	$v1,$zero
/*  f0e80c4:	8faf00f4 */ 	lw	$t7,0xf4($sp)
.JF0f0e80c8:
/*  f0e80c8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e80cc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e80d0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e80d4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f0e80d8:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e80dc:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0e80e0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e80e4:	01d95023 */ 	subu	$t2,$t6,$t9
/*  f0e80e8:	014dc021 */ 	addu	$t8,$t2,$t5
/*  f0e80ec:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e80f0:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e80f4:	0fc55886 */ 	jal	0xf156218
/*  f0e80f8:	afa30020 */ 	sw	$v1,0x20($sp)
/*  f0e80fc:	240b00ff */ 	li	$t3,0xff
/*  f0e8100:	afb300b8 */ 	sw	$s3,0xb8($sp)
/*  f0e8104:	afab00bc */ 	sw	$t3,0xbc($sp)
/*  f0e8108:	8e270008 */ 	lw	$a3,0x8($s1)
/*  f0e810c:	00409025 */ 	move	$s2,$v0
/*  f0e8110:	2404000e */ 	li	$a0,0xe
/*  f0e8114:	8cf90010 */ 	lw	$t9,0x10($a3)
/*  f0e8118:	27a600b8 */ 	addiu	$a2,$sp,0xb8
/*  f0e811c:	00e02825 */ 	move	$a1,$a3
/*  f0e8120:	0320f809 */ 	jalr	$t9
/*  f0e8124:	00000000 */ 	nop
/*  f0e8128:	8fac00bc */ 	lw	$t4,0xbc($sp)
/*  f0e812c:	240100ff */ 	li	$at,0xff
/*  f0e8130:	02402025 */ 	move	$a0,$s2
/*  f0e8134:	1181000c */ 	beq	$t4,$at,.JF0f0e8168
/*  f0e8138:	8fa5011c */ 	lw	$a1,0x11c($sp)
/*  f0e813c:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e8140:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0e8144:	35ce007f */ 	ori	$t6,$t6,0x7f
/*  f0e8148:	01f43021 */ 	addu	$a2,$t7,$s4
/*  f0e814c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e8150:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e8154:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e8158:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e815c:	0fc39159 */ 	jal	0xf0e4564
/*  f0e8160:	24070006 */ 	li	$a3,0x6
/*  f0e8164:	00409025 */ 	move	$s2,$v0
.JF0f0e8168:
/*  f0e8168:	8faa00b4 */ 	lw	$t2,0xb4($sp)
/*  f0e816c:	51400004 */ 	beqzl	$t2,.JF0f0e8180
/*  f0e8170:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e8174:	0fc55880 */ 	jal	0xf156200
/*  f0e8178:	00002025 */ 	move	$a0,$zero
/*  f0e817c:	8fb80108 */ 	lw	$t8,0x108($sp)
.JF0f0e8180:
/*  f0e8180:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e8184:	8dad16e8 */ 	lw	$t5,0x16e8($t5)
/*  f0e8188:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e818c:	0278082a */ 	slt	$at,$s3,$t8
/*  f0e8190:	14200003 */ 	bnez	$at,.JF0f0e81a0
/*  f0e8194:	028da021 */ 	addu	$s4,$s4,$t5
/*  f0e8198:	240b0001 */ 	li	$t3,0x1
/*  f0e819c:	afab0120 */ 	sw	$t3,0x120($sp)
.JF0f0e81a0:
/*  f0e81a0:	86390006 */ 	lh	$t9,0x6($s1)
/*  f0e81a4:	240f0001 */ 	li	$t7,0x1
/*  f0e81a8:	0334082a */ 	slt	$at,$t9,$s4
/*  f0e81ac:	50200003 */ 	beqzl	$at,.JF0f0e81bc
/*  f0e81b0:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0e81b4:	afaf0120 */ 	sw	$t7,0x120($sp)
/*  f0e81b8:	8fac0120 */ 	lw	$t4,0x120($sp)
.JF0f0e81bc:
/*  f0e81bc:	5180fd95 */ 	beqzl	$t4,.JF0f0e7814
/*  f0e81c0:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e81c4:	0fc3d768 */ 	jal	0xf0f5da0
/*  f0e81c8:	02402025 */ 	move	$a0,$s2
/*  f0e81cc:	10000051 */ 	b	.JF0f0e8314
/*  f0e81d0:	00409025 */ 	move	$s2,$v0
.JF0f0e81d4:
/*  f0e81d4:	8e230010 */ 	lw	$v1,0x10($s1)
/*  f0e81d8:	44802000 */ 	mtc1	$zero,$f4
/*  f0e81dc:	c4720040 */ 	lwc1	$f18,0x40($v1)
/*  f0e81e0:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0e81e4:	00000000 */ 	nop
/*  f0e81e8:	4502000b */ 	bc1fl	.JF0f0e8218
/*  f0e81ec:	9078003d */ 	lbu	$t8,0x3d($v1)
/*  f0e81f0:	906e003c */ 	lbu	$t6,0x3c($v1)
/*  f0e81f4:	2415003c */ 	li	$s5,0x3c
/*  f0e81f8:	3c167f1b */ 	lui	$s6,0x7f1b
/*  f0e81fc:	01d50019 */ 	multu	$t6,$s5
/*  f0e8200:	26d62ce0 */ 	addiu	$s6,$s6,0x2ce0
/*  f0e8204:	00005012 */ 	mflo	$t2
/*  f0e8208:	02ca6821 */ 	addu	$t5,$s6,$t2
/*  f0e820c:	10000012 */ 	b	.JF0f0e8258
/*  f0e8210:	8db00018 */ 	lw	$s0,0x18($t5)
/*  f0e8214:	9078003d */ 	lbu	$t8,0x3d($v1)
.JF0f0e8218:
/*  f0e8218:	2415003c */ 	li	$s5,0x3c
/*  f0e821c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e8220:	03150019 */ 	multu	$t8,$s5
/*  f0e8224:	3c167f1b */ 	lui	$s6,0x7f1b
/*  f0e8228:	26d62ce0 */ 	addiu	$s6,$s6,0x2ce0
/*  f0e822c:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e8230:	00005812 */ 	mflo	$t3
/*  f0e8234:	02cbc821 */ 	addu	$t9,$s6,$t3
/*  f0e8238:	8f240018 */ 	lw	$a0,0x18($t9)
/*  f0e823c:	01f50019 */ 	multu	$t7,$s5
/*  f0e8240:	00006012 */ 	mflo	$t4
/*  f0e8244:	02cc7021 */ 	addu	$t6,$s6,$t4
/*  f0e8248:	0fc01a60 */ 	jal	0xf006980
/*  f0e824c:	8dc50018 */ 	lw	$a1,0x18($t6)
/*  f0e8250:	00408025 */ 	move	$s0,$v0
/*  f0e8254:	8e230010 */ 	lw	$v1,0x10($s1)
.JF0f0e8258:
/*  f0e8258:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e825c:	02002025 */ 	move	$a0,$s0
/*  f0e8260:	00002825 */ 	move	$a1,$zero
/*  f0e8264:	51400008 */ 	beqzl	$t2,.JF0f0e8288
/*  f0e8268:	8fab011c */ 	lw	$t3,0x11c($sp)
/*  f0e826c:	0fc01a60 */ 	jal	0xf006980
/*  f0e8270:	2406007f */ 	li	$a2,0x7f
/*  f0e8274:	2401ff00 */ 	li	$at,-256
/*  f0e8278:	00416824 */ 	and	$t5,$v0,$at
/*  f0e827c:	321800ff */ 	andi	$t8,$s0,0xff
/*  f0e8280:	01b88025 */ 	or	$s0,$t5,$t8
/*  f0e8284:	8fab011c */ 	lw	$t3,0x11c($sp)
.JF0f0e8288:
/*  f0e8288:	24045739 */ 	li	$a0,0x5739
/*  f0e828c:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0e8290:	afb90130 */ 	sw	$t9,0x130($sp)
/*  f0e8294:	862c0006 */ 	lh	$t4,0x6($s1)
/*  f0e8298:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f0e829c:	05810003 */ 	bgez	$t4,.JF0f0e82ac
/*  f0e82a0:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f0e82a4:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0e82a8:	00017043 */ 	sra	$t6,$at,0x1
.JF0f0e82ac:
/*  f0e82ac:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0e82b0:	0fc5baa5 */ 	jal	0xf16ea94
/*  f0e82b4:	afaa012c */ 	sw	$t2,0x12c($sp)
/*  f0e82b8:	0c002eef */ 	jal	0xbbbc
/*  f0e82bc:	00409825 */ 	move	$s3,$v0
/*  f0e82c0:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f0e82c4:	8fb800f4 */ 	lw	$t8,0xf4($sp)
/*  f0e82c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e82cc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e82d0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e82d4:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f0e82d8:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0e82dc:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0e82e0:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f0e82e4:	01796023 */ 	subu	$t4,$t3,$t9
/*  f0e82e8:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f0e82ec:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e82f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e82f4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e82f8:	02402025 */ 	move	$a0,$s2
/*  f0e82fc:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f0e8300:	27a6012c */ 	addiu	$a2,$sp,0x12c
/*  f0e8304:	02603825 */ 	move	$a3,$s3
/*  f0e8308:	0fc55886 */ 	jal	0xf156218
/*  f0e830c:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0e8310:	00409025 */ 	move	$s2,$v0
.JF0f0e8314:
/*  f0e8314:	0fc54bb7 */ 	jal	0xf152edc
/*  f0e8318:	02402025 */ 	move	$a0,$s2
.JF0f0e831c:
/*  f0e831c:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f0e8320:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0e8324:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0e8328:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0e832c:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0e8330:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0e8334:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0e8338:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0e833c:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f0e8340:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f0e8344:	03e00008 */ 	jr	$ra
/*  f0e8348:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuitemListRender
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
/*  f0e6498:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e649c:	a7a500ee */ 	sh	$a1,0xee($sp)
/*  f0e64a0:	3c0a8007 */ 	lui	$t2,%hi(g_ScissorX1)
/*  f0e64a4:	8d4a1190 */ 	lw	$t2,%lo(g_ScissorX1)($t2)
/*  f0e64a8:	004a082a */ 	slt	$at,$v0,$t2
/*  f0e64ac:	10200005 */ 	beqz	$at,.L0f0e64c4
/*  f0e64b0:	00000000 */ 	nop
/*  f0e64b4:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e64b8:	00000000 */ 	nop
/*  f0e64bc:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0e64c0:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0e64c4:
/*  f0e64c4:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e64c8:	00000000 */ 	nop
/*  f0e64cc:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*  f0e64d0:	004b082a */ 	slt	$at,$v0,$t3
/*  f0e64d4:	10200004 */ 	beqz	$at,.L0f0e64e8
/*  f0e64d8:	00000000 */ 	nop
/*  f0e64dc:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e64e0:	00000000 */ 	nop
/*  f0e64e4:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e64e8:
/*  f0e64e8:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e64ec:	00000000 */ 	nop
/*  f0e64f0:	3c0c8007 */ 	lui	$t4,%hi(g_ScissorY1)
/*  f0e64f4:	8d8c1198 */ 	lw	$t4,%lo(g_ScissorY1)($t4)
/*  f0e64f8:	004c082a */ 	slt	$at,$v0,$t4
/*  f0e64fc:	10200005 */ 	beqz	$at,.L0f0e6514
/*  f0e6500:	00000000 */ 	nop
/*  f0e6504:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e6508:	00000000 */ 	nop
/*  f0e650c:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e6510:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0e6514:
/*  f0e6514:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e6518:	00000000 */ 	nop
/*  f0e651c:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e6520:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e6524:	10200005 */ 	beqz	$at,.L0f0e653c
/*  f0e6528:	00000000 */ 	nop
/*  f0e652c:	0c002ef5 */ 	jal	viGetBufHeight
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
/*  f0e66a0:	0fc3859a */ 	jal	menugfx0f0e1668
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
/*  f0e66e4:	0fc38aa9 */ 	jal	menugfxDrawShimmer
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
/*  f0e6728:	0fc38aa9 */ 	jal	menugfxDrawShimmer
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
/*  f0e6768:	0fc38aa9 */ 	jal	menugfxDrawShimmer
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
/*  f0e67ac:	0fc38aa9 */ 	jal	menugfxDrawShimmer
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
/*  f0e684c:	0fc3974b */ 	jal	menuitem0f0e5d2c
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
/*  f0e6884:	0fc397be */ 	jal	menuitem0f0e5ef8
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
/*  f0e69d0:	0fc3980e */ 	jal	menuitemListRenderHeader
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
/*  f0e6b4c:	0fc3d43f */ 	jal	menuApplyScissor
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
/*  f0e6bc8:	0fc3980e */ 	jal	menuitemListRenderHeader
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
/*  f0e70ac:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e70b0:	00000000 */ 	nop
/*  f0e70b4:	3c0e8007 */ 	lui	$t6,%hi(g_ScissorX1)
/*  f0e70b8:	8dce1190 */ 	lw	$t6,%lo(g_ScissorX1)($t6)
/*  f0e70bc:	004e082a */ 	slt	$at,$v0,$t6
/*  f0e70c0:	10200005 */ 	beqz	$at,.L0f0e70d8
/*  f0e70c4:	00000000 */ 	nop
/*  f0e70c8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e70cc:	00000000 */ 	nop
/*  f0e70d0:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0e70d4:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0e70d8:
/*  f0e70d8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e70dc:	00000000 */ 	nop
/*  f0e70e0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e70e4:	004f082a */ 	slt	$at,$v0,$t7
/*  f0e70e8:	10200004 */ 	beqz	$at,.L0f0e70fc
/*  f0e70ec:	00000000 */ 	nop
/*  f0e70f0:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0e70f4:	00000000 */ 	nop
/*  f0e70f8:	aee20000 */ 	sw	$v0,0x0($s7)
.L0f0e70fc:
/*  f0e70fc:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e7100:	00000000 */ 	nop
/*  f0e7104:	3c188007 */ 	lui	$t8,%hi(g_ScissorY1)
/*  f0e7108:	8f181198 */ 	lw	$t8,%lo(g_ScissorY1)($t8)
/*  f0e710c:	0058082a */ 	slt	$at,$v0,$t8
/*  f0e7110:	10200005 */ 	beqz	$at,.L0f0e7128
/*  f0e7114:	00000000 */ 	nop
/*  f0e7118:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e711c:	00000000 */ 	nop
/*  f0e7120:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0e7124:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0e7128:
/*  f0e7128:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0e712c:	00000000 */ 	nop
/*  f0e7130:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f0e7134:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e7138:	10200005 */ 	beqz	$at,.L0f0e7150
/*  f0e713c:	00000000 */ 	nop
/*  f0e7140:	0c002ef5 */ 	jal	viGetBufHeight
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
/*  f0e73b0:	0fc38dec */ 	jal	menugfxDrawCheckbox
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
/*  f0e7418:	0fc3d43f */ 	jal	menuApplyScissor
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
glabel menuitemListRender
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
/*  f0e39fc:	0fc37aaa */ 	jal	menugfx0f0e1668
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
/*  f0e3a40:	0fc37fce */ 	jal	menugfxDrawShimmer
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
/*  f0e3a84:	0fc37fce */ 	jal	menugfxDrawShimmer
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
/*  f0e3ac4:	0fc37fce */ 	jal	menugfxDrawShimmer
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
/*  f0e3b08:	0fc37fce */ 	jal	menugfxDrawShimmer
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
/*  f0e3ba8:	0fc38c6f */ 	jal	menuitem0f0e5d2c
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
/*  f0e3be0:	0fc38ce2 */ 	jal	menuitem0f0e5ef8
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
/*  f0e3d24:	0fc38d32 */ 	jal	menuitemListRenderHeader
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
/*  f0e3e9c:	0fc3c728 */ 	jal	menuApplyScissor
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
/*  f0e3f18:	0fc38d32 */ 	jal	menuitemListRenderHeader
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
/*  f0e4544:	0fc38311 */ 	jal	menugfxDrawCheckbox
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
/*  f0e45ac:	0fc3c728 */ 	jal	menuApplyScissor
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

bool menuitemListTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
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

	if (item->flags & MENUITEMFLAG_00200000) {
		item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2);
		g_LineHeight = handlerdata2.list.value;
	} else {
		g_LineHeight = 11;
	}

	if (item->type == MENUITEMTYPE_DROPDOWN || item->type == MENUITEMTYPE_PLAYERSTATS) {
		min = data->list.unk06 / 2;
		min = min / (s32)g_LineHeight;
		min *= (s32)g_LineHeight;

		data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);

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

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);

		if (handlerdata.list.value) {
			last = handlerdata.list.value - 1;

			if (data->list.unk02 > last) {
				data->list.unk02 = last;
				data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);
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

				data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);

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
	handlerdata.list.groupstartindex = (tickflags & MENUTICKFLAG_ITEMISFOCUSED) ? 1 : 0;

	item->handler(MENUOP_25, item, &handlerdata);

	if (handlerdata.list.unk0c != handlerdata.list.value) {
		data->list.unk02 = handlerdata.list.value;
		data->list.unk04 = menuitem0f0e5ef8(data->list.unk02, item);
	}

	return true;
}

void menuitemDropdownInit(struct menuitem *item, union menuitemdata *data)
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

	if (item->flags & MENUITEMFLAG_00200000) {
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

	data->dropdown.unk04 = menuitem0f0e5ef8(data->dropdown.unk02, item);

	item->handler(MENUOP_LISTITEMFOCUS, item, &handlerdata);
}

Gfx *menuitemDropdownRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;
	char *text;
	s32 x;
	s32 y;
	union handlerdata data;

	x = context->x;
	y = context->y;
	text = menuResolveParam2Text(context->item);

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused != 0) {
		if ((context->focused & 2) != 0) {
			u32 tmpcolour;
			u32 weight = func0f006b08(20) * 255.0f; \
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		} else {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f; \
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		}

		func0f153e38(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		func0f153e38(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		colour = MIXCOLOUR(context->dialog, disabled);

		if (context->dialog->dimmed) {
			colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
		}

		func0f153e38(g_MenuColourPalettes3[context->dialog->type].disabled, g_MenuColourPalettes2[context->dialog->type].disabled);
	}

	gdl = func0f153628(gdl);

	x = context->x + 10;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);

	if (context->dialog->unk6e) {
		x = context->x + 80;
	} else {
		x = context->x + context->width - 60;
	}

	if (context->item->flags & MENUITEMFLAG_00000080) {
		x = context->x + 30;
	}

	y = context->y + 2;

	if (context->item->handler != NULL) {
		s32 textheight;
		s32 textwidth;

		data.list.value = 0;
		context->item->handler(MENUOP_GETOPTIONVALUE, context->item, &data);

		data.list.unk04 = 0;
		text = (char *)context->item->handler(MENUOP_GETOPTIONTEXT, context->item, &data);

		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = context->x + context->width - textwidth - 10;
		gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);
	}

	gdl = func0f153780(gdl);

	return gdl;
}

bool menuitemDropdownTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	u32 stack;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && item->handler) {
		if (dialog->dimmed && item == dialog->focuseditem) {
			menuitemListTick(item, inputs, tickflags, data);

			if (mpIsPlayerLockedOut(g_MpPlayerNum)) {
				if ((item->flags & MENUITEMFLAG_00040000) || (dialog->definition->flags & MENUDIALOGFLAG_MPLOCKABLE)) {
					dialog->dimmed = false;
				}
			}
		}

		if (inputs->back && dialog->dimmed) {
			dialog->dimmed = false;
			inputs->back = false;
			menuPlaySound(MENUSOUND_TOGGLEOFF);
		}

		if (inputs->select) {
			if (dialog->dimmed) {
				dialog->dimmed = false;
			} else {
				union handlerdata handlerdata;

				dialog->dimmed = true;
				menuitemDropdownInit(item, data);

				handlerdata.dropdown.value = 0;
				item->handler(MENUOP_GETOPTIONVALUE, item, &handlerdata);
				data->dropdown.unk0e = handlerdata.dropdown.value * g_LineHeight;
				menuPlaySound(MENUSOUND_TOGGLEOFF);
			}
		}
	}

	return true;
}

Gfx *menuitemDropdownOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
	s32 stack;
	s32 textwidth;
	s32 textheight;
	s32 numoptions;
	s32 i;
	char *text;
	struct menurendercontext context;

#if VERSION >= VERSION_NTSC_1_0
	if (dialog->unk6e) {
		context.x = x + 78;
	} else if (x2 < 0) {
		context.x = x + 2;
	} else {
		context.x = x + x2 - 62;
	}
#else
	if (dialog->unk6e) {
		context.x = x + 78;
	} else {
		context.x = x + x2 - 62;
	}
#endif

	if (item->flags & MENUITEMFLAG_00000080) {
		context.x = x + 30;
	}

	context.y = y + 1;
	context.width = 56;
	context.item = item;
	context.focused = true;
	context.dialog = dialog;
	context.data = data;

	if (dialog->dimmed && item->handler && dialog->focuseditem == item) {
		union handlerdata handlerdata;

		if (item->flags & MENUITEMFLAG_00200000) {
			union handlerdata handlerdata2;
			item->handler(MENUOP_GETOPTIONHEIGHT, item, &handlerdata2); \
			g_LineHeight = handlerdata2.dropdown.value; \
		} else { \
			g_LineHeight = 11;
		}

		item->handler(MENUOP_GETOPTIONCOUNT, item, &handlerdata);
		numoptions = handlerdata.dropdown.value;

		context.width = 0;
		context.height = (s32)g_LineHeight * numoptions;

		for (i = 0; i != numoptions; i++) {
			handlerdata.dropdown.value = i;
			text = (char *)item->handler(MENUOP_GETOPTIONTEXT, item, &handlerdata);
			textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			textwidth += 6;

			if (textwidth > context.width) {
				context.width = textwidth;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (x2 > 0) {
			context.x = x + x2 - context.width - 7;
		}
#else
		context.x = x + x2 - context.width - 7;
#endif

		if (context.y + context.height > dialog->y + dialog->height + 2) {
			if (context.height > dialog->height) {
				i = dialog->height;
				i = i / g_LineHeight;
				i = i * g_LineHeight;
				context.height = i;
			}

			context.y = dialog->y + dialog->height - context.height + 2;
		}

		gdl = menuitemListRender(gdl, &context);
	}

	return gdl;
}

bool menuitemKeyboardIsStringEmptyOrSpaces(char *text)
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
Gfx *menuitemKeyboardRender(Gfx *gdl, struct menurendercontext *context)
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
			g_MenuColourPalettes3[context->dialog->type].unfocused,
			g_MenuColourPalettes2[context->dialog->type].unfocused);

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

	if (context->dialog->transitionfrac < 0) {
		cursorcolour = g_MenuColourPalettes[context->dialog->type].focused;
	} else {
		cursorcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].focused,
				g_MenuColourPalettes[context->dialog->type].focused,
				context->dialog->colourweight);
	}

	cursorcolour = colourBlend(colourBlend(0x0000ffff, 0x000000ff, 127), cursorcolour, alpha);

	gdl = gfxSetPrimColour(gdl, cursorcolour);

	gDPFillRectangleScaled(gdl++, x + 1, context->y + 2, x + 3, context->y + 9);

	gdl = func0f153838(gdl);

	// Render horizontal grid lines
	for (row = 0; row < 6; row++) {
		gdl = menugfxDrawFilledRect(gdl, context->x + 4, context->y + row * 11 + 13,
				context->x + 124, context->y + row * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	// Render vertical grid lines
	for (col = 0; col < 11; col++) {
		rowspan = 5;

		if (col == 1 || col == 3 || col == 4 || col == 6 || col == 7 || col == 9) {
			rowspan = 4;
		}

		gdl = menugfxDrawFilledRect(gdl, context->x + col * 12 + 4, context->y + 13,
				context->x + col * 12 + 5, context->y + rowspan * 11 + 14, 0x00ffff7f, 0x00ffff7f);
	}

	gdl = func0f153628(gdl);

	x = context->x + 10;
	y = context->y + 2;

	for (col = 0; col < 10; col++) {
		for (row = 0; row < 5; row++) {
			if (context->dialog->transitionfrac < 0) {
				textcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
			} else {
				textcolour = colourBlend(
						g_MenuColourPalettes[context->dialog->type2].unfocused,
						g_MenuColourPalettes[context->dialog->type].unfocused,
						context->dialog->colourweight);
			}

			if (context->dialog->dimmed) {
				textcolour = colourBlend(textcolour, 0x00000000, 127) & 0xffffff00 | textcolour & 0xff;
			}

			if (data->capseffective && col == 2 && row == 4) {
				// CAPS button - make it yellow
				textcolour = textcolour & 0xff | 0xffff0000;
			}

			// If this button is the focused one, set highlighted colour
			if (col == data->col && row == data->row) {
				alpha = func0f006b08(40) * 255;

				if (context->dialog->transitionfrac < 0) {
					tmpcolour = g_MenuColourPalettes[context->dialog->type].focused;
				} else {
					tmpcolour = colourBlend(
							g_MenuColourPalettes[context->dialog->type2].focused,
							g_MenuColourPalettes[context->dialog->type].focused,
							context->dialog->colourweight);
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
					if (index == 3 && menuitemKeyboardIsStringEmptyOrSpaces(data->string)) {
						if (context->dialog->transitionfrac < 0) {
							textcolour = g_MenuColourPalettes[context->dialog->type].disabled;
						} else {
							textcolour = colourBlend(
									g_MenuColourPalettes[context->dialog->type2].disabled,
									g_MenuColourPalettes[context->dialog->type].disabled,
									context->dialog->colourweight);
						}

						if (context->dialog->dimmed) {
							textcolour = colourBlend(textcolour, 0, 127) & 0xffffff00 | textcolour & 0xff;
						}

						func0f153e38(
								g_MenuColourPalettes3[context->dialog->type].disabled,
								g_MenuColourPalettes2[context->dialog->type].disabled);
					}

					gdl = textRenderProjected(gdl, &x, &y, langGet(labels[index]), g_CharsHandelGothicXs, g_FontHandelGothicXs, textcolour, context->width, context->height, 0, 0);

					if (index == 3 && menuitemKeyboardIsStringEmptyOrSpaces(data->string)) {
						func0f153e38(
								g_MenuColourPalettes3[context->dialog->type].unfocused,
								g_MenuColourPalettes2[context->dialog->type].unfocused);
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

		gdl = menugfxDrawLine(gdl, x1, y1, x2, y1 + 1, -1, -1); // top
		gdl = menugfxDrawLine(gdl, x2, y1, x2 + 1, y2 + 1, -1, -1); // right
		gdl = menugfxDrawLine(gdl, x1, y2, x2, y2 + 1, -1, -1); // bottom
		gdl = menugfxDrawLine(gdl, x1, y1, x1 + 1, y2 + 1, -1, -1); // left
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
bool menuitemKeyboardTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	struct menuitemdata_keyboard *kb = &data->keyboard;
	union handlerdata handlerdata;
	s32 delete = false;

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
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
			if (item->handler && !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
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
					if (item->handler && !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
						handlerdata.keyboard.string = kb->string;
						item->handler(MENUOP_SETTEXT, item, &handlerdata);
					}
				}

				// OK or CANCEL
				if (kb->col == 8 || kb->col == 5) {
					s32 ok = (kb->col == 8);

					if (kb->col == 5 || !menuitemKeyboardIsStringEmptyOrSpaces(kb->string)) {
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
	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
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

void menuitemKeyboardInit(struct menuitem *item, union menuitemdata *data)
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

Gfx *menuitemSeparatorRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	colour = (colour & 0xffffff00) | 0x3f;

#if VERSION >= VERSION_JPN_FINAL
	return menugfxDrawFilledRect(gdl, context->x, context->y, context->x + context->width, context->y + 1, colour, colour);
#else
	return menugfxDrawFilledRect(gdl, context->x, context->y + 2, context->x + context->width, context->y + 3, colour, colour);
#endif
}

u32 var800711e8 = 0x00000000;

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
/*  f0ea654:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0ea658:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0ea65c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ea660:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0ea664:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0ea668:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0ea66c:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0ea670:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0ea674:	11c00002 */ 	beqz	$t6,.JF0f0ea680
/*  f0ea678:	00001025 */ 	move	$v0,$zero
/*  f0ea67c:	2402000e */ 	li	$v0,0xe
.JF0f0ea680:
/*  f0ea680:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0ea684:	3c058007 */ 	lui	$a1,0x8007
/*  f0ea688:	24a51728 */ 	addiu	$a1,$a1,0x1728
/*  f0ea68c:	2484ecd0 */ 	addiu	$a0,$a0,-4912
/*  f0ea690:	0c0036b4 */ 	jal	0xdad0
/*  f0ea694:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0ea698:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0ea69c:	3c04800a */ 	lui	$a0,0x800a
/*  f0ea6a0:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0ea6a4:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0ea6a8:	0fc5baa5 */ 	jal	0xf16ea94
/*  f0ea6ac:	9484e6ca */ 	lhu	$a0,-0x1936($a0)
/*  f0ea6b0:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0ea6b4:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0ea6b8:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0ea6bc:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0ea6c0:	44803000 */ 	mtc1	$zero,$f6
/*  f0ea6c4:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0ea6c8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ea6cc:	00000000 */ 	nop
/*  f0ea6d0:	4502000b */ 	bc1fl	.JF0f0ea700
/*  f0ea6d4:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0ea6d8:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0ea6dc:	2410003c */ 	li	$s0,0x3c
/*  f0ea6e0:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0ea6e4:	01300019 */ 	multu	$t1,$s0
/*  f0ea6e8:	00005012 */ 	mflo	$t2
/*  f0ea6ec:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0ea6f0:	8d6b2cf8 */ 	lw	$t3,0x2cf8($t3)
/*  f0ea6f4:	10000012 */ 	b	.JF0f0ea740
/*  f0ea6f8:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0ea6fc:	906c003d */ 	lbu	$t4,0x3d($v1)
.JF0f0ea700:
/*  f0ea700:	2410003c */ 	li	$s0,0x3c
/*  f0ea704:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ea708:	01900019 */ 	multu	$t4,$s0
/*  f0ea70c:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0ea710:	25ce2ce0 */ 	addiu	$t6,$t6,0x2ce0
/*  f0ea714:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0ea718:	00006812 */ 	mflo	$t5
/*  f0ea71c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0ea720:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0ea724:	03100019 */ 	multu	$t8,$s0
/*  f0ea728:	0000c812 */ 	mflo	$t9
/*  f0ea72c:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0ea730:	0fc01a60 */ 	jal	0xf006980
/*  f0ea734:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0ea738:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0ea73c:	8fa30134 */ 	lw	$v1,0x134($sp)
.JF0f0ea740:
/*  f0ea740:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0ea744:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0ea748:	00002825 */ 	move	$a1,$zero
/*  f0ea74c:	5140000b */ 	beqzl	$t2,.JF0f0ea77c
/*  f0ea750:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0ea754:	0fc01a60 */ 	jal	0xf006980
/*  f0ea758:	2406002c */ 	li	$a2,0x2c
/*  f0ea75c:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0ea760:	2401ff00 */ 	li	$at,-256
/*  f0ea764:	00415824 */ 	and	$t3,$v0,$at
/*  f0ea768:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0ea76c:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0ea770:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0ea774:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0ea778:	9078003c */ 	lbu	$t8,0x3c($v1)
.JF0f0ea77c:
/*  f0ea77c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0ea780:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea784:	03100019 */ 	multu	$t8,$s0
/*  f0ea788:	00001012 */ 	mflo	$v0
/*  f0ea78c:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0ea790:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0ea794:	8ca52e60 */ 	lw	$a1,0x2e60($a1)
/*  f0ea798:	0fc54d69 */ 	jal	0xf1535a4
/*  f0ea79c:	8c842fc8 */ 	lw	$a0,0x2fc8($a0)
/*  f0ea7a0:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0ea7a4:	0fc54b55 */ 	jal	0xf152d54
/*  f0ea7a8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea7ac:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0ea7b0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea7b4:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ea7b8:	24a5ecd8 */ 	addiu	$a1,$a1,-4904
/*  f0ea7bc:	02002025 */ 	move	$a0,$s0
/*  f0ea7c0:	0c004d95 */ 	jal	0x13654
/*  f0ea7c4:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0ea7c8:	3c198008 */ 	lui	$t9,0x8008
/*  f0ea7cc:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0ea7d0:	3c078008 */ 	lui	$a3,0x8008
/*  f0ea7d4:	8ce7014c */ 	lw	$a3,0x14c($a3)
/*  f0ea7d8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0ea7dc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0ea7e0:	02003025 */ 	move	$a2,$s0
/*  f0ea7e4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ea7e8:	0fc55d49 */ 	jal	0xf157524
/*  f0ea7ec:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea7f0:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea7f4:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0ea7f8:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ea7fc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0ea800:	8dad0148 */ 	lw	$t5,0x148($t5)
/*  f0ea804:	8d6b014c */ 	lw	$t3,0x14c($t3)
/*  f0ea808:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0ea80c:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0ea810:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0ea814:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0ea818:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0ea81c:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0ea820:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea824:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea828:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea82c:	02003825 */ 	move	$a3,$s0
/*  f0ea830:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea834:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea838:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ea83c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea840:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0ea844:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ea848:	0fc55886 */ 	jal	0xf156218
/*  f0ea84c:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ea850:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea854:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0ea858:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0ea85c:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0ea860:	1140001f */ 	beqz	$t2,.JF0f0ea8e0
/*  f0ea864:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0ea868:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0ea86c:	8d8c0140 */ 	lw	$t4,0x140($t4)
/*  f0ea870:	3c078008 */ 	lui	$a3,0x8008
/*  f0ea874:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f0ea878:	24040055 */ 	li	$a0,0x55
/*  f0ea87c:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0ea880:	02003025 */ 	move	$a2,$s0
/*  f0ea884:	0fc55dde */ 	jal	0xf157778
/*  f0ea888:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ea88c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ea890:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0ea894:	8dad0140 */ 	lw	$t5,0x140($t5)
/*  f0ea898:	8d6b0144 */ 	lw	$t3,0x144($t3)
/*  f0ea89c:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0ea8a0:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0ea8a4:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0ea8a8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea8ac:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea8b0:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea8b4:	02003825 */ 	move	$a3,$s0
/*  f0ea8b8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea8bc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea8c0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0ea8c4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0ea8c8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0ea8cc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0ea8d0:	0fc55886 */ 	jal	0xf156218
/*  f0ea8d4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0ea8d8:	1000001a */ 	b	.JF0f0ea944
/*  f0ea8dc:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0ea8e0:
/*  f0ea8e0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0ea8e4:	24a5ece0 */ 	addiu	$a1,$a1,-4896
/*  f0ea8e8:	02002025 */ 	move	$a0,$s0
/*  f0ea8ec:	0c004d95 */ 	jal	0x13654
/*  f0ea8f0:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0ea8f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0ea8f8:	3c098008 */ 	lui	$t1,0x8008
/*  f0ea8fc:	8d290148 */ 	lw	$t1,0x148($t1)
/*  f0ea900:	8dce014c */ 	lw	$t6,0x14c($t6)
/*  f0ea904:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0ea908:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0ea90c:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0ea910:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0ea914:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0ea918:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0ea91c:	02003825 */ 	move	$a3,$s0
/*  f0ea920:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ea924:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ea928:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ea92c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ea930:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0ea934:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0ea938:	0fc55886 */ 	jal	0xf156218
/*  f0ea93c:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0ea940:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0ea944:
/*  f0ea944:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0ea948:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0ea94c:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0ea950:	11a00126 */ 	beqz	$t5,.JF0f0eadec
/*  f0ea954:	25cc0016 */ 	addiu	$t4,$t6,0x16
/*  f0ea958:	0fc25901 */ 	jal	0xf096404
/*  f0ea95c:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0ea960:	10400007 */ 	beqz	$v0,.JF0f0ea980
/*  f0ea964:	24010001 */ 	li	$at,0x1
/*  f0ea968:	1041000c */ 	beq	$v0,$at,.JF0f0ea99c
/*  f0ea96c:	24010002 */ 	li	$at,0x2
/*  f0ea970:	10410011 */ 	beq	$v0,$at,.JF0f0ea9b8
/*  f0ea974:	00000000 */ 	nop
/*  f0ea978:	10000015 */ 	b	.JF0f0ea9d0
/*  f0ea97c:	00000000 */ 	nop
.JF0f0ea980:
/*  f0ea980:	0fc5baa5 */ 	jal	0xf16ea94
/*  f0ea984:	24045601 */ 	li	$a0,0x5601
/*  f0ea988:	3c0fffff */ 	lui	$t7,0xffff
/*  f0ea98c:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0ea990:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea994:	1000000e */ 	b	.JF0f0ea9d0
/*  f0ea998:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.JF0f0ea99c:
/*  f0ea99c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f0ea9a0:	24045600 */ 	li	$a0,0x5600
/*  f0ea9a4:	3c1800ff */ 	lui	$t8,0xff
/*  f0ea9a8:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0ea9ac:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea9b0:	10000007 */ 	b	.JF0f0ea9d0
/*  f0ea9b4:	afb800c8 */ 	sw	$t8,0xc8($sp)
.JF0f0ea9b8:
/*  f0ea9b8:	0fc5baa5 */ 	jal	0xf16ea94
/*  f0ea9bc:	24045602 */ 	li	$a0,0x5602
/*  f0ea9c0:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0ea9c4:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0ea9c8:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0ea9cc:	afb900c8 */ 	sw	$t9,0xc8($sp)
.JF0f0ea9d0:
/*  f0ea9d0:	3c098007 */ 	lui	$t1,0x8007
/*  f0ea9d4:	8d291998 */ 	lw	$t1,0x1998($t1)
/*  f0ea9d8:	3c0c800a */ 	lui	$t4,0x800a
/*  f0ea9dc:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0ea9e0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0ea9e4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ea9e8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0ea9ec:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0ea9f0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0ea9f4:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0ea9f8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0ea9fc:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0eaa00:	8d8cebf8 */ 	lw	$t4,-0x1408($t4)
/*  f0eaa04:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eaa08:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0eaa0c:	11cc0004 */ 	beq	$t6,$t4,.JF0f0eaa20
/*  f0eaa10:	3c078008 */ 	lui	$a3,0x8008
/*  f0eaa14:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0eaa18:	8d6b2cf8 */ 	lw	$t3,0x2cf8($t3)
/*  f0eaa1c:	afab00c8 */ 	sw	$t3,0xc8($sp)
.JF0f0eaa20:
/*  f0eaa20:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0eaa24:	8dad0140 */ 	lw	$t5,0x140($t5)
/*  f0eaa28:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0eaa2c:	8ce70144 */ 	lw	$a3,0x144($a3)
/*  f0eaa30:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eaa34:	0fc55d49 */ 	jal	0xf157524
/*  f0eaa38:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0eaa3c:	3c028007 */ 	lui	$v0,0x8007
/*  f0eaa40:	8c421728 */ 	lw	$v0,0x1728($v0)
/*  f0eaa44:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0eaa48:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0eaa4c:	10400002 */ 	beqz	$v0,.JF0f0eaa58
/*  f0eaa50:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0eaa54:	afa200c8 */ 	sw	$v0,0xc8($sp)
.JF0f0eaa58:
/*  f0eaa58:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0eaa5c:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0eaa60:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0eaa64:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0eaa68:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0eaa6c:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0eaa70:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0eaa74:	8d6b0140 */ 	lw	$t3,0x140($t3)
/*  f0eaa78:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0eaa7c:	8d8c0144 */ 	lw	$t4,0x144($t4)
/*  f0eaa80:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0eaa84:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0eaa88:	014e4021 */ 	addu	$t0,$t2,$t6
/*  f0eaa8c:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0eaa90:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f0eaa94:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0eaa98:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0eaa9c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0eaaa0:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0eaaa4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0eaaa8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0eaaac:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0eaab0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0eaab4:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0eaab8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0eaabc:	0fc55886 */ 	jal	0xf156218
/*  f0eaac0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0eaac4:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0eaac8:	87a80146 */ 	lh	$t0,0x146($sp)
/*  f0eaacc:	00402025 */ 	move	$a0,$v0
/*  f0eaad0:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0eaad4:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0eaad8:	25080009 */ 	addiu	$t0,$t0,0x9
/*  f0eaadc:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0eaae0:	0fc54bb7 */ 	jal	0xf152edc
/*  f0eaae4:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0eaae8:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eaaec:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0eaaf0:	8fb8013c */ 	lw	$t8,0x13c($sp)
/*  f0eaaf4:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0eaaf8:	01856023 */ 	subu	$t4,$t4,$a1
/*  f0eaafc:	01851821 */ 	addu	$v1,$t4,$a1
/*  f0eab00:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0eab04:	24b90016 */ 	addiu	$t9,$a1,0x16
/*  f0eab08:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f0eab0c:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f0eab10:	87a90146 */ 	lh	$t1,0x146($sp)
/*  f0eab14:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0eab18:	00402025 */ 	move	$a0,$v0
/*  f0eab1c:	252afffe */ 	addiu	$t2,$t1,-2
/*  f0eab20:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f0eab24:	252e0008 */ 	addiu	$t6,$t1,0x8
/*  f0eab28:	afae00ac */ 	sw	$t6,0xac($sp)
/*  f0eab2c:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0eab30:	04610003 */ 	bgez	$v1,.JF0f0eab40
/*  f0eab34:	00035883 */ 	sra	$t3,$v1,0x2
/*  f0eab38:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0eab3c:	00015883 */ 	sra	$t3,$at,0x2
.JF0f0eab40:
/*  f0eab40:	00cb6823 */ 	subu	$t5,$a2,$t3
/*  f0eab44:	25afffe8 */ 	addiu	$t7,$t5,-24
/*  f0eab48:	01f90019 */ 	multu	$t7,$t9
/*  f0eab4c:	24010005 */ 	li	$at,0x5
/*  f0eab50:	01601825 */ 	move	$v1,$t3
/*  f0eab54:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0eab58:	00005012 */ 	mflo	$t2
/*  f0eab5c:	00000000 */ 	nop
/*  f0eab60:	00000000 */ 	nop
/*  f0eab64:	0141001a */ 	div	$zero,$t2,$at
/*  f0eab68:	00004812 */ 	mflo	$t1
/*  f0eab6c:	01697021 */ 	addu	$t6,$t3,$t1
/*  f0eab70:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f0eab74:	25cc0013 */ 	addiu	$t4,$t6,0x13
/*  f0eab78:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f0eab7c:	010b6821 */ 	addu	$t5,$t0,$t3
/*  f0eab80:	25b80005 */ 	addiu	$t8,$t5,0x5
/*  f0eab84:	0fc38c93 */ 	jal	0xf0e324c
/*  f0eab88:	afb800a8 */ 	sw	$t8,0xa8($sp)
/*  f0eab8c:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0eab90:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0eab94:	2401ff00 */ 	li	$at,-256
/*  f0eab98:	0061c824 */ 	and	$t9,$v1,$at
/*  f0eab9c:	3730003f */ 	ori	$s0,$t9,0x3f
/*  f0eaba0:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*  f0eaba4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eaba8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eabac:	03201825 */ 	move	$v1,$t9
/*  f0eabb0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0eabb4:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f0eabb8:	00402025 */ 	move	$a0,$v0
/*  f0eabbc:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eabc0:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eabc4:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0eabc8:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0eabcc:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f0eabd0:	00402025 */ 	move	$a0,$v0
/*  f0eabd4:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eabd8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0eabdc:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0eabe0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eabe4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eabe8:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eabec:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eabf0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eabf4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eabf8:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0eabfc:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0eac00:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0eac04:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0eac08:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eac0c:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0eac10:	00402025 */ 	move	$a0,$v0
/*  f0eac14:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eac18:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac1c:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eac20:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0eac24:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac28:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0eac2c:	00402025 */ 	move	$a0,$v0
/*  f0eac30:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0eac34:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0eac38:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac3c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0eac40:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac44:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac48:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eac4c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eac50:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0eac54:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac58:	00402025 */ 	move	$a0,$v0
/*  f0eac5c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0eac60:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eac64:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0eac68:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eac74:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eac78:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eac7c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eac80:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0eac84:	00402025 */ 	move	$a0,$v0
/*  f0eac88:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eac8c:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0eac90:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0eac94:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eac98:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eac9c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaca0:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaca4:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0eaca8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0eacac:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eacb0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0eacb4:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0eacb8:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0eacbc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0eacc0:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eacc4:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0eacc8:	00402025 */ 	move	$a0,$v0
/*  f0eaccc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eacd0:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eacd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eacd8:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0eacdc:	00402025 */ 	move	$a0,$v0
/*  f0eace0:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eace4:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0eace8:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0eacec:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0eacf0:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0eacf4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eacf8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eacfc:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0ead00:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead04:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ead08:	00402025 */ 	move	$a0,$v0
/*  f0ead0c:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ead10:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ead14:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ead18:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead20:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0ead24:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ead28:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0ead2c:	00402025 */ 	move	$a0,$v0
/*  f0ead30:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0ead34:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ead38:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ead3c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead40:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead44:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0ead48:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0ead4c:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0ead50:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0ead54:	2401ff00 */ 	li	$at,-256
/*  f0ead58:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f0ead5c:	0061c024 */ 	and	$t8,$v1,$at
/*  f0ead60:	3710003f */ 	ori	$s0,$t8,0x3f
/*  f0ead64:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ead68:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0ead6c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ead70:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ead74:	03001825 */ 	move	$v1,$t8
/*  f0ead78:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0ead7c:	00402025 */ 	move	$a0,$v0
/*  f0ead80:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0ead84:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0ead88:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0ead8c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ead90:	8faf004c */ 	lw	$t7,0x4c($sp)
/*  f0ead94:	00402025 */ 	move	$a0,$v0
/*  f0ead98:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0ead9c:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0eada0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0eada4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0eada8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eadac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eadb0:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eadb4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0eadb8:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f0eadbc:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f0eadc0:	00402025 */ 	move	$a0,$v0
/*  f0eadc4:	354900cf */ 	ori	$t1,$t2,0xcf
/*  f0eadc8:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0eadcc:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0eadd0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0eadd4:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0eadd8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaddc:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eade0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eade4:	10000077 */ 	b	.JF0f0eafc4
/*  f0eade8:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0eadec:
/*  f0eadec:	87ab0146 */ 	lh	$t3,0x146($sp)
/*  f0eadf0:	3c198008 */ 	lui	$t9,0x8008
/*  f0eadf4:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0eadf8:	250f0001 */ 	addiu	$t7,$t0,0x1
/*  f0eadfc:	3c078008 */ 	lui	$a3,0x8008
/*  f0eae00:	256dfffe */ 	addiu	$t5,$t3,-2
/*  f0eae04:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f0eae08:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f0eae0c:	afad007c */ 	sw	$t5,0x7c($sp)
/*  f0eae10:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0eae14:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0eae18:	8ce7014c */ 	lw	$a3,0x14c($a3)
/*  f0eae1c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0eae20:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0eae24:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0eae28:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0eae2c:	0fc55d49 */ 	jal	0xf157524
/*  f0eae30:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eae34:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0eae38:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f0eae3c:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0eae40:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0eae44:	01cc6821 */ 	addu	$t5,$t6,$t4
/*  f0eae48:	25ab0019 */ 	addiu	$t3,$t5,0x19
/*  f0eae4c:	2549fffe */ 	addiu	$t1,$t2,-2
/*  f0eae50:	afa90074 */ 	sw	$t1,0x74($sp)
/*  f0eae54:	0fc54bb7 */ 	jal	0xf152edc
/*  f0eae58:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0eae5c:	0fc38c93 */ 	jal	0xf0e324c
/*  f0eae60:	00402025 */ 	move	$a0,$v0
/*  f0eae64:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0eae68:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0eae6c:	2401ff00 */ 	li	$at,-256
/*  f0eae70:	00617824 */ 	and	$t7,$v1,$at
/*  f0eae74:	35f0003f */ 	ori	$s0,$t7,0x3f
/*  f0eae78:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0eae7c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eae80:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eae84:	01e01825 */ 	move	$v1,$t7
/*  f0eae88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0eae8c:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f0eae90:	00402025 */ 	move	$a0,$v0
/*  f0eae94:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0eae98:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eae9c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0eaea0:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0eaea4:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f0eaea8:	00402025 */ 	move	$a0,$v0
/*  f0eaeac:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eaeb0:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0eaeb4:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0eaeb8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaebc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaec0:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaec4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0eaec8:	87a90142 */ 	lh	$t1,0x142($sp)
/*  f0eaecc:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaed0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0eaed4:	00097080 */ 	sll	$t6,$t1,0x2
/*  f0eaed8:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f0eaedc:	01c93821 */ 	addu	$a3,$t6,$t1
/*  f0eaee0:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0eaee4:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0eaee8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eaeec:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0eaef0:	00402025 */ 	move	$a0,$v0
/*  f0eaef4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaef8:	01202825 */ 	move	$a1,$t1
/*  f0eaefc:	04e10003 */ 	bgez	$a3,.JF0f0eaf0c
/*  f0eaf00:	00076083 */ 	sra	$t4,$a3,0x2
/*  f0eaf04:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0eaf08:	00016083 */ 	sra	$t4,$at,0x2
.JF0f0eaf0c:
/*  f0eaf0c:	2587ffff */ 	addiu	$a3,$t4,-1
/*  f0eaf10:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0eaf14:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaf18:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0eaf1c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf20:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0eaf24:	00402025 */ 	move	$a0,$v0
/*  f0eaf28:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0eaf2c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0eaf30:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf34:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0eaf38:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf3c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf40:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaf44:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0eaf48:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f0eaf4c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf50:	00402025 */ 	move	$a0,$v0
/*  f0eaf54:	25ab0003 */ 	addiu	$t3,$t5,0x3
/*  f0eaf58:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0eaf5c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf60:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf64:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf68:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaf6c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0eaf70:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0eaf74:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0eaf78:	00402025 */ 	move	$a0,$v0
/*  f0eaf7c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0eaf80:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0eaf84:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0eaf88:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0eaf8c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eaf90:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eaf94:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eaf98:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0eaf9c:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0eafa0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0eafa4:	00402025 */ 	move	$a0,$v0
/*  f0eafa8:	24d90001 */ 	addiu	$t9,$a2,0x1
/*  f0eafac:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0eafb0:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0eafb4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0eafb8:	0fc38d3e */ 	jal	0xf0e34f8
/*  f0eafbc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0eafc0:	afa20130 */ 	sw	$v0,0x130($sp)
.JF0f0eafc4:
/*  f0eafc4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0eafc8:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0eafcc:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0eafd0:	03e00008 */ 	jr	$ra
/*  f0eafd4:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
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
/*  f0e98e8:	0c0036cc */ 	jal	mainOverrideVariable
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
/*  f0e9e48:	0fc38926 */ 	jal	menugfx0f0e2498
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
/*  f0e9e84:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9ee0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f0c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f38:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f64:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f94:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9fc0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea048:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea074:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea0a0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea114:	0fc38926 */ 	jal	menugfx0f0e2498
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
/*  f0ea150:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea1cc:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea1f8:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea24c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea274:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea278:	afa20130 */ 	sw	$v0,0x130($sp)
.L0f0ea27c:
/*  f0ea27c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ea280:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0ea284:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0ea288:	03e00008 */ 	jr	$ra
/*  f0ea28c:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuitemObjectivesRenderOne
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
/*  f0e98e8:	0c0036cc */ 	jal	mainOverrideVariable
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
/*  f0e9e48:	0fc38926 */ 	jal	menugfx0f0e2498
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
/*  f0e9e84:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9e88:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e9e8c:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e9e90:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e9e94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9e98:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e9e9c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e9ea0:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e9ea4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9ea8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9eac:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9ee0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f0c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f38:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f64:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9f94:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0e9fc0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e9fcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9fd0:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9fd4:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e9fd8:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e9fdc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e9fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e9fe4:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0e9fe8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e9fec:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e9ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e9ff4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e9ff8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e9ffc:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0ea000:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea008:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea048:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea074:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea0a0:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea114:	0fc38926 */ 	jal	menugfx0f0e2498
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
/*  f0ea150:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea154:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0ea158:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0ea15c:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0ea160:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea164:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0ea168:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0ea16c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0ea170:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea174:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea178:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea1cc:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea1f8:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea1fc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0ea200:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0ea204:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0ea208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea20c:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0ea210:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0ea214:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0ea218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea21c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ea220:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
/*  f0ea24c:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
/*  f0ea250:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0ea254:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0ea258:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0ea25c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ea260:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0ea264:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ea268:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0ea26c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0ea270:	0fc389d1 */ 	jal	menugfxDrawTessellatedRect
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
glabel menuitemObjectivesRenderOne
/*  f0e6a20:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0e6a24:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0e6a28:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e6a2c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0e6a30:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f0e6a34:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f0e6a38:	afa60138 */ 	sw	$a2,0x138($sp)
/*  f0e6a3c:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f0e6a40:	11c00002 */ 	beqz	$t6,.NB0f0e6a4c
/*  f0e6a44:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e6a48:	2402000c */ 	addiu	$v0,$zero,0xc
.NB0f0e6a4c:
/*  f0e6a4c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e6a50:	3c058007 */ 	lui	$a1,0x8007
/*  f0e6a54:	24a53898 */ 	addiu	$a1,$a1,0x3898
/*  f0e6a58:	248482d0 */ 	addiu	$a0,$a0,-32048
/*  f0e6a5c:	0c00381c */ 	jal	mainOverrideVariable
/*  f0e6a60:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0e6a64:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f0e6a68:	3c04800a */ 	lui	$a0,0x800a
/*  f0e6a6c:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f0e6a70:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0e6a74:	0fc5a4dd */ 	jal	langGet
/*  f0e6a78:	9484278a */ 	lhu	$a0,0x278a($a0)
/*  f0e6a7c:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e6a80:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e6a84:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0e6a88:	afb90124 */ 	sw	$t9,0x124($sp)
/*  f0e6a8c:	44803000 */ 	mtc1	$zero,$f6
/*  f0e6a90:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f0e6a94:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e6a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6a9c:	4502000b */ 	bc1fl	.NB0f0e6acc
/*  f0e6aa0:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0e6aa4:	9069003c */ 	lbu	$t1,0x3c($v1)
/*  f0e6aa8:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e6aac:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0e6ab0:	01300019 */ 	multu	$t1,$s0
/*  f0e6ab4:	00005012 */ 	mflo	$t2
/*  f0e6ab8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0e6abc:	8d6bc2f8 */ 	lw	$t3,-0x3d08($t3)
/*  f0e6ac0:	10000012 */ 	beqz	$zero,.NB0f0e6b0c
/*  f0e6ac4:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0e6ac8:	906c003d */ 	lbu	$t4,0x3d($v1)
.NB0f0e6acc:
/*  f0e6acc:	2410003c */ 	addiu	$s0,$zero,0x3c
/*  f0e6ad0:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6ad4:	01900019 */ 	multu	$t4,$s0
/*  f0e6ad8:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f0e6adc:	25cec2e0 */ 	addiu	$t6,$t6,-15648
/*  f0e6ae0:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e6ae4:	00006812 */ 	mflo	$t5
/*  f0e6ae8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0e6aec:	8de40018 */ 	lw	$a0,0x18($t7)
/*  f0e6af0:	03100019 */ 	multu	$t8,$s0
/*  f0e6af4:	0000c812 */ 	mflo	$t9
/*  f0e6af8:	032e4821 */ 	addu	$t1,$t9,$t6
/*  f0e6afc:	0fc01990 */ 	jal	colourBlend
/*  f0e6b00:	8d250018 */ 	lw	$a1,0x18($t1)
/*  f0e6b04:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f0e6b08:	8fa30134 */ 	lw	$v1,0x134($sp)
.NB0f0e6b0c:
/*  f0e6b0c:	8c6a000c */ 	lw	$t2,0xc($v1)
/*  f0e6b10:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f0e6b14:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e6b18:	5140000b */ 	beqzl	$t2,.NB0f0e6b48
/*  f0e6b1c:	9078003c */ 	lbu	$t8,0x3c($v1)
/*  f0e6b20:	0fc01990 */ 	jal	colourBlend
/*  f0e6b24:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0e6b28:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0e6b2c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6b30:	00415824 */ 	and	$t3,$v0,$at
/*  f0e6b34:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0e6b38:	016d7825 */ 	or	$t7,$t3,$t5
/*  f0e6b3c:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0e6b40:	8fa30134 */ 	lw	$v1,0x134($sp)
/*  f0e6b44:	9078003c */ 	lbu	$t8,0x3c($v1)
.NB0f0e6b48:
/*  f0e6b48:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0e6b4c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6b50:	03100019 */ 	multu	$t8,$s0
/*  f0e6b54:	00001012 */ 	mflo	$v0
/*  f0e6b58:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0e6b5c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0e6b60:	8ca5c460 */ 	lw	$a1,-0x3ba0($a1)
/*  f0e6b64:	0fc53925 */ 	jal	func0f153e38
/*  f0e6b68:	8c84c5c8 */ 	lw	$a0,-0x3a38($a0)
/*  f0e6b6c:	a3a000d0 */ 	sb	$zero,0xd0($sp)
/*  f0e6b70:	0fc5374a */ 	jal	func0f153628
/*  f0e6b74:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6b78:	27b000d0 */ 	addiu	$s0,$sp,0xd0
/*  f0e6b7c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6b80:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e6b84:	24a582d8 */ 	addiu	$a1,$a1,-32040
/*  f0e6b88:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6b8c:	0c004fc1 */ 	jal	sprintf
/*  f0e6b90:	8fa6013c */ 	lw	$a2,0x13c($sp)
/*  f0e6b94:	3c198008 */ 	lui	$t9,0x8008
/*  f0e6b98:	8f39236c */ 	lw	$t9,0x236c($t9)
/*  f0e6b9c:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6ba0:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f0e6ba4:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6ba8:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6bac:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e6bb0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e6bb4:	0fc54655 */ 	jal	textMeasure
/*  f0e6bb8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e6bbc:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e6bc0:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f0e6bc4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6bc8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6bcc:	8dad236c */ 	lw	$t5,0x236c($t5)
/*  f0e6bd0:	8d6b2370 */ 	lw	$t3,0x2370($t3)
/*  f0e6bd4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e6bd8:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e6bdc:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e6be0:	01c95023 */ 	subu	$t2,$t6,$t1
/*  f0e6be4:	254c0019 */ 	addiu	$t4,$t2,0x19
/*  f0e6be8:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0e6bec:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6bf0:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6bf4:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6bf8:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6bfc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6c00:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6c04:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e6c08:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6c0c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e6c10:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e6c14:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6c18:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e6c1c:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e6c20:	8faa0154 */ 	lw	$t2,0x154($sp)
/*  f0e6c24:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f0e6c28:	25c90019 */ 	addiu	$t1,$t6,0x19
/*  f0e6c2c:	1140001f */ 	beqz	$t2,.NB0f0e6cac
/*  f0e6c30:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6c34:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e6c38:	8d8c2364 */ 	lw	$t4,0x2364($t4)
/*  f0e6c3c:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6c40:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0e6c44:	24040055 */ 	addiu	$a0,$zero,0x55
/*  f0e6c48:	8fa50120 */ 	lw	$a1,0x120($sp)
/*  f0e6c4c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e6c50:	0fc546df */ 	jal	textWrap
/*  f0e6c54:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6c58:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6c5c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6c60:	8dad2364 */ 	lw	$t5,0x2364($t5)
/*  f0e6c64:	8d6b2368 */ 	lw	$t3,0x2368($t3)
/*  f0e6c68:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f0e6c6c:	87b8014a */ 	lh	$t8,0x14a($sp)
/*  f0e6c70:	87b9014e */ 	lh	$t9,0x14e($sp)
/*  f0e6c74:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6c78:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6c7c:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6c80:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6c88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6c8c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e6c90:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e6c94:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0e6c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0e6c9c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6ca0:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0e6ca4:	1000001a */ 	beqz	$zero,.NB0f0e6d10
/*  f0e6ca8:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e6cac:
/*  f0e6cac:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0e6cb0:	24a582e0 */ 	addiu	$a1,$a1,-32032
/*  f0e6cb4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e6cb8:	0c004fc1 */ 	jal	sprintf
/*  f0e6cbc:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e6cc0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e6cc4:	3c098008 */ 	lui	$t1,0x8008
/*  f0e6cc8:	8d29236c */ 	lw	$t1,0x236c($t1)
/*  f0e6ccc:	8dce2370 */ 	lw	$t6,0x2370($t6)
/*  f0e6cd0:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f0e6cd4:	87ac014a */ 	lh	$t4,0x14a($sp)
/*  f0e6cd8:	87ab014e */ 	lh	$t3,0x14e($sp)
/*  f0e6cdc:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6ce0:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6ce4:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6ce8:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e6cec:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6cf0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6cf4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e6cf8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e6cfc:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0e6d00:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e6d04:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6d08:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0e6d0c:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e6d10:
/*  f0e6d10:	8fad0150 */ 	lw	$t5,0x150($sp)
/*  f0e6d14:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6d18:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6d1c:	11a00141 */ 	beqz	$t5,.NB0f0e7224
/*  f0e6d20:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6d24:	0fc24dd9 */ 	jal	objectiveCheck
/*  f0e6d28:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0e6d2c:	10400007 */ 	beqz	$v0,.NB0f0e6d4c
/*  f0e6d30:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e6d34:	1041000c */ 	beq	$v0,$at,.NB0f0e6d68
/*  f0e6d38:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e6d3c:	10410011 */ 	beq	$v0,$at,.NB0f0e6d84
/*  f0e6d40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6d44:	10000015 */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d48:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0e6d4c:
/*  f0e6d4c:	0fc5a4dd */ 	jal	langGet
/*  f0e6d50:	24045601 */ 	addiu	$a0,$zero,0x5601
/*  f0e6d54:	3c0fffff */ 	lui	$t7,0xffff
/*  f0e6d58:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f0e6d5c:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d60:	1000000e */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d64:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.NB0f0e6d68:
/*  f0e6d68:	0fc5a4dd */ 	jal	langGet
/*  f0e6d6c:	24045600 */ 	addiu	$a0,$zero,0x5600
/*  f0e6d70:	3c1800ff */ 	lui	$t8,0xff
/*  f0e6d74:	371800ff */ 	ori	$t8,$t8,0xff
/*  f0e6d78:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d7c:	10000007 */ 	beqz	$zero,.NB0f0e6d9c
/*  f0e6d80:	afb800c8 */ 	sw	$t8,0xc8($sp)
.NB0f0e6d84:
/*  f0e6d84:	0fc5a4dd */ 	jal	langGet
/*  f0e6d88:	24045602 */ 	addiu	$a0,$zero,0x5602
/*  f0e6d8c:	3c19ff40 */ 	lui	$t9,0xff40
/*  f0e6d90:	373940ff */ 	ori	$t9,$t9,0x40ff
/*  f0e6d94:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0e6d98:	afb900c8 */ 	sw	$t9,0xc8($sp)
.NB0f0e6d9c:
/*  f0e6d9c:	3c098007 */ 	lui	$t1,0x8007
/*  f0e6da0:	8d293af0 */ 	lw	$t1,0x3af0($t1)
/*  f0e6da4:	3c0c800a */ 	lui	$t4,0x800a
/*  f0e6da8:	8fae0134 */ 	lw	$t6,0x134($sp)
/*  f0e6dac:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0e6db0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6db4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0e6db8:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6dbc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0e6dc0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0e6dc4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0e6dc8:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0e6dcc:	8d8c2c48 */ 	lw	$t4,0x2c48($t4)
/*  f0e6dd0:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f0e6dd4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0e6dd8:	11cc0004 */ 	beq	$t6,$t4,.NB0f0e6dec
/*  f0e6ddc:	3c078008 */ 	lui	$a3,0x8008
/*  f0e6de0:	3c0b7f1b */ 	lui	$t3,0x7f1b
/*  f0e6de4:	8d6bc2f8 */ 	lw	$t3,-0x3d08($t3)
/*  f0e6de8:	afab00c8 */ 	sw	$t3,0xc8($sp)
.NB0f0e6dec:
/*  f0e6dec:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e6df0:	8dad2364 */ 	lw	$t5,0x2364($t5)
/*  f0e6df4:	8fa600cc */ 	lw	$a2,0xcc($sp)
/*  f0e6df8:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f0e6dfc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e6e00:	0fc54655 */ 	jal	textMeasure
/*  f0e6e04:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e6e08:	3c028007 */ 	lui	$v0,0x8007
/*  f0e6e0c:	8c423898 */ 	lw	$v0,0x3898($v0)
/*  f0e6e10:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6e14:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6e18:	10400002 */ 	beqz	$v0,.NB0f0e6e24
/*  f0e6e1c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e6e20:	afa200c8 */ 	sw	$v0,0xc8($sp)
.NB0f0e6e24:
/*  f0e6e24:	87a2014a */ 	lh	$v0,0x14a($sp)
/*  f0e6e28:	87af0142 */ 	lh	$t7,0x142($sp)
/*  f0e6e2c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6e30:	87aa0146 */ 	lh	$t2,0x146($sp)
/*  f0e6e34:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f0e6e38:	01e28021 */ 	addu	$s0,$t7,$v0
/*  f0e6e3c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e6e40:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f0e6e44:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e6e48:	8d8c2368 */ 	lw	$t4,0x2368($t4)
/*  f0e6e4c:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f0e6e50:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e6e54:	014e1821 */ 	addu	$v1,$t2,$t6
/*  f0e6e58:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e6e5c:	24630009 */ 	addiu	$v1,$v1,0x9
/*  f0e6e60:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6e64:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e6e68:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0e6e6c:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e6e70:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e6e74:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6e78:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6e7c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0e6e80:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e6e84:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e6e88:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e6e8c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6e90:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0e6e94:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6e98:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f0e6e9c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0e6ea0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0e6ea4:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0e6ea8:	8dce2364 */ 	lw	$t6,0x2364($t6)
/*  f0e6eac:	8d4a2368 */ 	lw	$t2,0x2368($t2)
/*  f0e6eb0:	87ad014a */ 	lh	$t5,0x14a($sp)
/*  f0e6eb4:	87af014e */ 	lh	$t7,0x14e($sp)
/*  f0e6eb8:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f0e6ebc:	0218c823 */ 	subu	$t9,$s0,$t8
/*  f0e6ec0:	2729fff6 */ 	addiu	$t1,$t9,-10
/*  f0e6ec4:	01815824 */ 	and	$t3,$t4,$at
/*  f0e6ec8:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0e6ecc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e6ed0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6ed4:	27a50128 */ 	addiu	$a1,$sp,0x128
/*  f0e6ed8:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f0e6edc:	8fa700cc */ 	lw	$a3,0xcc($sp)
/*  f0e6ee0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e6ee4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e6ee8:	afa30124 */ 	sw	$v1,0x124($sp)
/*  f0e6eec:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e6ef0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6ef4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e6ef8:	0fc541a6 */ 	jal	textRenderProjected
/*  f0e6efc:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e6f00:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f0e6f04:	87b90146 */ 	lh	$t9,0x146($sp)
/*  f0e6f08:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6f0c:	02183023 */ 	subu	$a2,$s0,$t8
/*  f0e6f10:	24c6fff3 */ 	addiu	$a2,$a2,-13
/*  f0e6f14:	27290009 */ 	addiu	$t1,$t9,0x9
/*  f0e6f18:	afa90124 */ 	sw	$t1,0x124($sp)
/*  f0e6f1c:	0fc537a0 */ 	jal	func0f153780
/*  f0e6f20:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0e6f24:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e6f28:	87ae0146 */ 	lh	$t6,0x146($sp)
/*  f0e6f2c:	8fa60128 */ 	lw	$a2,0x128($sp)
/*  f0e6f30:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0e6f34:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0e6f38:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f0e6f3c:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0e6f40:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*  f0e6f44:	afab00ac */ 	sw	$t3,0xac($sp)
/*  f0e6f48:	24aa0016 */ 	addiu	$t2,$a1,0x16
/*  f0e6f4c:	01251821 */ 	addu	$v1,$t1,$a1
/*  f0e6f50:	8fab013c */ 	lw	$t3,0x13c($sp)
/*  f0e6f54:	afaa00b4 */ 	sw	$t2,0xb4($sp)
/*  f0e6f58:	24630042 */ 	addiu	$v1,$v1,0x42
/*  f0e6f5c:	25ccfffe */ 	addiu	$t4,$t6,-2
/*  f0e6f60:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f0e6f64:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0e6f68:	256dffff */ 	addiu	$t5,$t3,-1
/*  f0e6f6c:	27190002 */ 	addiu	$t9,$t8,0x2
/*  f0e6f70:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f0e6f74:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6f78:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f0e6f7c:	04610003 */ 	bgez	$v1,.NB0f0e6f8c
/*  f0e6f80:	00035083 */ 	sra	$t2,$v1,0x2
/*  f0e6f84:	24610003 */ 	addiu	$at,$v1,0x3
/*  f0e6f88:	00015083 */ 	sra	$t2,$at,0x2
.NB0f0e6f8c:
/*  f0e6f8c:	00ca6023 */ 	subu	$t4,$a2,$t2
/*  f0e6f90:	258effe8 */ 	addiu	$t6,$t4,-24
/*  f0e6f94:	01cd0019 */ 	multu	$t6,$t5
/*  f0e6f98:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0e6f9c:	afaa005c */ 	sw	$t2,0x5c($sp)
/*  f0e6fa0:	00007812 */ 	mflo	$t7
/*  f0e6fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e6fac:	01e1001a */ 	div	$zero,$t7,$at
/*  f0e6fb0:	0000c012 */ 	mflo	$t8
/*  f0e6fb4:	0158c821 */ 	addu	$t9,$t2,$t8
/*  f0e6fb8:	27290013 */ 	addiu	$t1,$t9,0x13
/*  f0e6fbc:	0fc37e4b */ 	jal	menugfx0f0e2498
/*  f0e6fc0:	afa90098 */ 	sw	$t1,0x98($sp)
/*  f0e6fc4:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e6fc8:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e6fcc:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e6fd0:	00616024 */ 	and	$t4,$v1,$at
/*  f0e6fd4:	3590003f */ 	ori	$s0,$t4,0x3f
/*  f0e6fd8:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e6fdc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e6fe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e6fe4:	01801825 */ 	or	$v1,$t4,$zero
/*  f0e6fe8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e6fec:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f0e6ff0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e6ff4:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e6ff8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e6ffc:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0e7000:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*  f0e7004:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0e7008:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e700c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e7010:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0e7014:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e7018:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e701c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7020:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7024:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e7028:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e702c:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e7030:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e7034:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e7038:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0e703c:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e7040:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7044:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0e7048:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e704c:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e7050:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7054:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7058:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e705c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e7060:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0e7064:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7068:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e706c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e7070:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e7074:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0e7078:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e707c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7080:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7084:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7088:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e708c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e7090:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7094:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0e7098:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e709c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0e70a0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e70a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e70a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e70ac:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e70b0:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e70b4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e70b8:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0e70bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e70c0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e70c4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e70c8:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e70cc:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e70d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e70d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e70d8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e70dc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e70e0:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e70e4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e70e8:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e70ec:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0e70f0:	24e7000e */ 	addiu	$a3,$a3,0xe
/*  f0e70f4:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e70f8:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e70fc:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0e7100:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7104:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7108:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e710c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7110:	8fa300a8 */ 	lw	$v1,0xa8($sp)
/*  f0e7114:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7118:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e711c:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0e7120:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0e7124:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e7128:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e712c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e7130:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7134:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7138:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e713c:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e7140:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7144:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e7148:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e714c:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e7150:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7154:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7158:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e715c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e7160:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e7164:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7168:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e716c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0e7170:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f0e7174:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7178:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e717c:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7180:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e7184:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0e7188:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0e718c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e7190:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0e7194:	00614824 */ 	and	$t1,$v1,$at
/*  f0e7198:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0e719c:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e71a0:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e71a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e71a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e71ac:	01201825 */ 	or	$v1,$t1,$zero
/*  f0e71b0:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f0e71b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71b8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0e71bc:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e71c0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e71c4:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0e71c8:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f0e71cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71d0:	24e7fffc */ 	addiu	$a3,$a3,-4
/*  f0e71d4:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0e71d8:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0e71dc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0e71e0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e71e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e71e8:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e71ec:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e71f0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f0e71f4:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0e71f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e71fc:	356e00cf */ 	ori	$t6,$t3,0xcf
/*  f0e7200:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e7204:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0e7208:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0e720c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0e7210:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7214:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7218:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e721c:	10000074 */ 	beqz	$zero,.NB0f0e73f0
/*  f0e7220:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e7224:
/*  f0e7224:	87b80146 */ 	lh	$t8,0x146($sp)
/*  f0e7228:	87ad0142 */ 	lh	$t5,0x142($sp)
/*  f0e722c:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0e7230:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0e7234:	8d6b236c */ 	lw	$t3,0x236c($t3)
/*  f0e7238:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f0e723c:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0e7240:	25af0016 */ 	addiu	$t7,$t5,0x16
/*  f0e7244:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0e7248:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f0e724c:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f0e7250:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0e7254:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f0e7258:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0e725c:	8ce72370 */ 	lw	$a3,0x2370($a3)
/*  f0e7260:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e7264:	0fc54655 */ 	jal	textMeasure
/*  f0e7268:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e726c:	87ae0142 */ 	lh	$t6,0x142($sp)
/*  f0e7270:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f0e7274:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f0e7278:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0e727c:	25f90019 */ 	addiu	$t9,$t7,0x19
/*  f0e7280:	0fc537a0 */ 	jal	func0f153780
/*  f0e7284:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f0e7288:	0fc37e4b */ 	jal	menugfx0f0e2498
/*  f0e728c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7290:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0e7294:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0e7298:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e729c:	00614824 */ 	and	$t1,$v1,$at
/*  f0e72a0:	3530003f */ 	ori	$s0,$t1,0x3f
/*  f0e72a4:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0e72a8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e72ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e72b0:	01201825 */ 	or	$v1,$t1,$zero
/*  f0e72b4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e72b8:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0e72bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e72c0:	87a50142 */ 	lh	$a1,0x142($sp)
/*  f0e72c4:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e72c8:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0e72cc:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0e72d0:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0e72d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e72d8:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e72dc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0e72e0:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0e72e4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e72e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e72ec:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e72f0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e72f4:	87ab0142 */ 	lh	$t3,0x142($sp)
/*  f0e72f8:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e72fc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f0e7300:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0e7304:	01cb7023 */ 	subu	$t6,$t6,$t3
/*  f0e7308:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e730c:	24e70042 */ 	addiu	$a3,$a3,0x42
/*  f0e7310:	24c80001 */ 	addiu	$t0,$a2,0x1
/*  f0e7314:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7318:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0e731c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7320:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7324:	01602825 */ 	or	$a1,$t3,$zero
/*  f0e7328:	04e10003 */ 	bgez	$a3,.NB0f0e7338
/*  f0e732c:	00076883 */ 	sra	$t5,$a3,0x2
/*  f0e7330:	24e10003 */ 	addiu	$at,$a3,0x3
/*  f0e7334:	00016883 */ 	sra	$t5,$at,0x2
.NB0f0e7338:
/*  f0e7338:	25a7ffff */ 	addiu	$a3,$t5,-1
/*  f0e733c:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f0e7340:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7344:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e7348:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e734c:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0e7350:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7354:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0e7358:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0e735c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e7360:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f0e7364:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7368:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e736c:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7370:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e7374:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e7378:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e737c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e7380:	25f90002 */ 	addiu	$t9,$t7,0x2
/*  f0e7384:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e7388:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e738c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e7390:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e7394:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e7398:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e739c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0e73a0:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0e73a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e73a8:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0e73ac:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0e73b0:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e73b4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e73b8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e73c0:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e73c4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e73c8:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0e73cc:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e73d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e73d4:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f0e73d8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e73dc:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0e73e0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e73e4:	0fc37ef6 */ 	jal	menugfxDrawTessellatedRect
/*  f0e73e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e73ec:	afa20130 */ 	sw	$v0,0x130($sp)
.NB0f0e73f0:
/*  f0e73f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e73f4:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f0e73f8:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0e73fc:	03e00008 */ 	jr	$ra
/*  f0e7400:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#endif

const char var7f1adfa0[] = "brcol";
const char var7f1adfa8[] = "%d: ";
const char var7f1adfb0[] = "%s";

// Mismatch: Stack usage is different. Target appears to use compiler-managed
// stack from 0x44 and below, which means the vars from 0x48 to 0x6c are real
// variables, and many are optimised out.
//Gfx *menuitemObjectivesRenderOne(Gfx *gdl, struct menudialog *dialog, s32 index, s32 position, s16 objx, s16 objy, s16 width, s16 height, bool withstatus, s32 arg9)
//{
//	u32 sp12c;
//	s32 x; // 128
//	s32 y; // 124
//	char *sp120;
//	char buffer[80]; // d0
//	char *spcc;
//	u32 spc8;
//	s32 textwidth; // c4
//	s32 textheight; // c0
//	s32 spbc;
//	s32 tmp;
//	s32 spb4;
//	s32 spb0;
//	s32 spac;
//	s32 spa8;
//	u32 stack3[2];
//	s32 sp9c;
//	s32 sp98;
//	u32 s0;
//	s32 stack[4];
//	s32 sp80;
//	s32 sp7c;
//	s32 sp78;
//	s32 sp74;
//	s32 stack2;
//	s32 sp6c;
//	s32 sp58;
//	s32 sp54;
//
//	spbc = 0;
//
//	if (arg9) {
//		spbc = PAL ? 16 : 12;
//	}
//
//	mainOverrideVariable("brcol", &var800711e8);
//	sp120 = langGet(g_Briefing.objectivenames[index]);
//	y = objy;
//	sp12c = MIXCOLOUR(dialog, unfocused);
//
//	if (dialog->dimmed) {
//		sp12c = (colourBlend(sp12c, 0, 0x2c) & 0xffffff00) | (sp12c & 0xff);
//	}
//
//	func0f153e38(g_MenuColourPalettes3[dialog->type].unfocused, g_MenuColourPalettes2[dialog->type].unfocused);
//	buffer[0] = '\0';
//
//	// Render objective number
//	gdl = func0f153628(gdl);
//	sprintf(buffer, "%d: ", position);
//	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
//	x = objx - textwidth + 25;
//	gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, sp12c, width, height, 0, 0);
//
//	x = objx + 25;
//
//	if (arg9) {
//		textWrap(85, sp120, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs);
//		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, sp12c, width, height, 0, 0);
//	} else {
//		sprintf(buffer, "%s", sp120);
//		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, sp12c, width, height, 0, 0);
//	}
//
//	if (withstatus) {
//		switch (objectiveCheck(index)) {
//		case OBJECTIVE_INCOMPLETE:
//			spcc = langGet(L_OPTIONS_001); // "Incomplete"
//			spc8 = 0xffff00ff;
//			break;
//		case OBJECTIVE_COMPLETE:
//			spcc = langGet(L_OPTIONS_000); // "Complete"
//			spc8 = 0x00ff00ff;
//			break;
//		case OBJECTIVE_FAILED:
//			spcc = langGet(L_OPTIONS_002); // "Failed"
//			spc8 = 0xff4040ff;
//			break;
//		}
//
//		if (dialog != g_Menus[g_MpPlayerNum].curdialog) {
//			spc8 = g_MenuColourPalettes[0].unfocused;
//		}
//
//		textMeasure(&textheight, &textwidth, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//		if (var800711e8 != 0) {
//			spc8 = var800711e8;
//		}
//
//		x = objx + width - textwidth - 10;
//		y = objy + spbc + 9;
//
//		gdl = textRenderProjected(gdl, &x, &y, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, spc8, width, height, 0, 0);
//
//		x = objx + width - textwidth - 10;
//		y = objy + spbc + 9;
//
//		gdl = textRenderProjected(gdl, &x, &y, spcc, g_CharsHandelGothicXs, g_FontHandelGothicXs, spc8 & 0xffffff7f, width, height, 0, 0);
//
//		x = objx + width - textwidth - 13;
//		y = objy + 9;
//
//		gdl = func0f153780(gdl);
//
//		spb4 = objx + 22;
//		spb0 = objy - 2;
//		spac = objy + 8;
//		spa8 = y + spbc + 2;
//		tmp = (objx * 3 + objx + 66) / 4;
//		sp9c = x;
//		sp98 = tmp + 19 + (sp9c - tmp - 24) * (position - 1) / 5;
//
//		sp58 = (objx * 3 + objx + 66) / 4 - 1;
//		sp54 = (objx * 3 + objx + 66) / 4 + 14;
//
//		gdl = menugfx0f0e2498(gdl);
//
//		// Blue lines
//		gdl = menugfxDrawTessellatedRect(gdl, objx, spb0, spb4, spb0 + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, spb4, spb0, spb4 + 1, spac, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, objx, spac, sp58, spac + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 3, spac, spb4 + 1, spac + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, spac, sp58 + 1, spa8 + 2, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, spac, sp58 + 3, spa8, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, spa8, sp54, spa8 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, spa8 + 2, sp54, spa8 + 3, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp54, spa8, sp98, spa8 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp54, spa8 + 2, sp98, spa8 + 3, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//
//		// Coloured lines
//		gdl = menugfxDrawTessellatedRect(gdl, sp98, spa8, sp98 + 1, spa8 + 3, (spc8 & 0xffffff00) | 0x3f, (spc8 & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp98 + 1, spa8 + 1, sp9c - 4, spa8 + 2, (spc8 & 0xffffff00) | 0x3f, (spc8 & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp9c - 4, spa8 + 1, sp9c, spa8 + 2, (spc8 & 0xffffff00) | 0x3f, spc8 & 0xffffff00 | 0xcf);
//	} else {
//		// Render lines without status
//		sp80 = objx + 22;
//		sp7c = objy - 2;
//		sp78 = objy + 8;
//		sp74 = y + 1;
//
//		textMeasure(&textheight, &textwidth, sp120, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
//
//		sp6c = objx + textwidth + 25;
//		sp58 = (objx * 3 + objx + 66) / 4 - 1;
//
//		gdl = func0f153780(gdl);
//		gdl = menugfx0f0e2498(gdl);
//
//		gdl = menugfxDrawTessellatedRect(gdl, objx, sp7c, sp80, sp7c + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp80, sp7c, sp80 + 1, sp78, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, objx, sp78, sp58, sp78 + 1, sp12c & 0xffffff00, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 3, sp78, sp80 + 1, sp78 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58, sp78, sp58 + 1, sp74 + 2, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, sp78, sp58 + 3, sp74, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//		gdl = menugfxDrawTessellatedRect(gdl, sp58 + 2, sp74, sp6c, sp74 + 1, (sp12c & 0xffffff00) | 0x3f, (sp12c & 0xffffff00) | 0x3f);
//	}
//
//	return gdl;
//}

Gfx *menuitemObjectivesRender(Gfx *gdl, struct menurendercontext *context)
{
	s32 y = context->y + 5;
	s32 position = 1;
	s32 i;

	for (i = 0; i < 6; i++) {
		if (g_Briefing.objectivenames[i] && g_Briefing.objectivedifficulties[i] & (1 << lvGetDifficulty())) {
			gdl = menuitemObjectivesRenderOne(gdl,
					context->dialog,
					i, position, context->x, y, context->width, context->height,
					context->item->param != 1,
					context->item->param == 2);

			position++;

			if (context->item->param == 0) {
				y += 18;
			} else if (context->item->param == 2) {
				y += VERSION >= VERSION_PAL_FINAL ? 34 : 30;
			} else {
				y += 14;
			}
		}
	}

	return gdl;
}

Gfx *menuitemModelRender(Gfx *gdl, struct menurendercontext *context)
{
	if (context->item->flags & MENUITEMFLAG_00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;

		if (context->dialog->transitionfrac < 0) {
			renderdata.colour = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			renderdata.colour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			renderdata.colour = (colourBlend(renderdata.colour, 0, 127) & 0xffffff00) | (renderdata.colour & 0xff);
		}

		renderdata.unk10 = true;

		data.type19.gdl = gdl;
		data.type19.unk04 = (s32)&renderdata;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *)context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

Gfx *menuitemLabelRender(Gfx *gdl, struct menurendercontext *context)
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

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	text = menuResolveParam2Text(context->item);

	if (!text) {
		return gdl;
	}

#if VERSION != VERSION_JPN_FINAL
	if (context->item->flags & MENUITEMFLAG_00000200) {
		font1 = g_CharsHandelGothicXs;
		font2 = g_FontHandelGothicXs;
		y -= 2;
	}
#endif

	if (context->item->flags & MENUITEMFLAG_00000020) {
		// Center
		s32 textheight;
		s32 textwidth;
		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
		x = context->x + (context->width - textwidth) / 2;
	}

	if (context->item->flags & MENUITEMFLAG_00000100) {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].checkedunfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].checkedunfocused,
					g_MenuColourPalettes[context->dialog->type].checkedunfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].checkedunfocused,
				g_MenuColourPalettes2[context->dialog->type].checkedunfocused);
	} else {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			colour1 = (colourBlend(colour1, 0, 127) & 0xffffff00) | (colour1 & 0xff);
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);
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

	if (context->item->flags & MENUITEMFLAG_01000000) {
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

	if ((context->item->flags & MENUITEMFLAG_00008000) == 0) {
		// Right side text
		text = menuResolveText(context->item->param3, context->item);

		// This is not how you check if a string is empty...
		if (text != NULL && text != "") {
			s32 textheight;
			s32 textwidth;

			y = context->y + 2;

#if VERSION != VERSION_JPN_FINAL
			if (context->item->flags & MENUITEMFLAG_00000200) {
				y -= 2;
			}
#endif

			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
			x = context->x + context->width - textwidth - 10;

			if (context->item->flags & MENUITEMFLAG_00000010) {
				x += 6;
			}

			gdl = textRenderProjected(gdl, &x, &y, text,
					font1, font2, colour2, context->width, context->height, 0, 0);
		}
	}

	gdl = func0f153780(gdl);

	if (menudfc) {
		if (context->width + 200 < menudfc->unk04 * 300 && context->dialog->redrawtimer < 0) {
			func0f0f13ec(context->item);
		}

		var8007fb9c = savedvalue;

		func0f153c88();
	}

	if (context->item->flags & MENUITEMFLAG_00200000) {
		struct menuitemrenderdata renderdata;
		union handlerdata data;

		renderdata.x = context->x;
		renderdata.y = context->y;
		renderdata.width = context->width;
		renderdata.colour = colour1;
		renderdata.unk10 = false;

		data.type19.gdl = gdl;
		data.type19.unk04 = 0;
		data.type19.renderdata2 = &renderdata;

		gdl = (Gfx *) context->item->handler(MENUOP_RENDER, context->item, &data);
	}

	return gdl;
}

/**
 * Renders two yellow bars and an optional label. Suspected to be a resource
 * meter but with the calculations ifdeffed out, so the widths are static.
 */
Gfx *menuitemMeterRender(Gfx *gdl, struct menurendercontext *context)
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

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
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

Gfx *menuitemSelectableRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 leftcolour;
	u32 rightcolour;
	char *text;
	s32 x = context->x + 10;
	s32 y = context->y + 2;
	struct fontchar *font1 = g_CharsHandelGothicSm;
	struct font *font2 = g_FontHandelGothicSm;

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	if (context->item->flags & MENUITEMFLAG_00400000) {
		font1 = g_CharsHandelGothicMd;
		font2 = g_FontHandelGothicMd;
	}

	text = menuResolveParam2Text(context->item);

	if (context->dialog->transitionfrac < 0) {
		leftcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		leftcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		leftcolour = colourBlend(leftcolour, 0, 127) & 0xffffff00 | leftcolour & 0xff;
	}

	rightcolour = leftcolour;

	if (context->focused) {
		// Mismatch: The addiu and lui at eb030 and eb034 are swapped. The addiu
		// is adding the lower half of the address of g_MenuColourPalettes for
		// use in the else branch. The lui is loading a value into $at for the
		// float to u32 conversion for weight.
		u32 colour2;
		u32 weight = func0f006b08(40) * 255; \
		if (context->dialog->transitionfrac < 0) { \
			colour2 = g_MenuColourPalettes[context->dialog->type].focused; \
		} else { \
			colour2 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		leftcolour = colourBlend(colourBlend(leftcolour, leftcolour & 0x000000ff, 127), colour2, weight);

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].focused,
				g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			leftcolour = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			leftcolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			leftcolour = colourBlend(leftcolour, 0x00000000, 127) & 0xffffff00 | leftcolour & 0xff;
		}

		rightcolour = leftcolour;

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);
	}

	if (context->item->flags & MENUITEMFLAG_00000020) {
		// Center text
		s32 textheight;
		s32 textwidth;
		textMeasure(&textheight, &textwidth, text, font1, font2, 0);
		x = context->x + (context->width - textwidth) / 2;
	}

	if (context->item->flags & MENUITEMFLAG_00400000) {
		x += 35;
		y += 6;
	}

	gdl = func0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
			leftcolour, context->width, context->height, 0, 0);

	if ((context->item->flags & (MENUITEMFLAG_00008000 | MENUITEMFLAG_00400000)) == 0) {
		// Right side text
		text = menuResolveText(context->item->param3, context->item);

		// This is not how you check if a string is empty...
		if (text != NULL && text != "") {
			s32 textheight;
			s32 textwidth;

			y = context->y + 2;
			textMeasure(&textheight, &textwidth, text, font1, font2, 0);
			x = context->x + context->width - textwidth - 10;

			gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
					rightcolour, context->width, context->height, 0, 0);
		}
	}

	return func0f153780(gdl);
}

bool menuitemSelectableTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && inputs->select) {
		menuPlaySound(MENUSOUND_SELECT);

		if (item->flags & MENUITEMFLAG_00000008) {
			menuPopDialog();
		}

		if (item->flags & MENUITEMFLAG_00000004) {
			menuPushDialog((struct menudialogdef *)item->handler);
		} else if (item->handler) {
			union handlerdata data;
			item->handler(MENUOP_SET, item, &data);
		}
	}

	return true;
}

Gfx *menuitemSliderRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour;
	char *label;
	char buffer[16];
	s32 x;
	s32 y;
	s32 extray;
	s32 textwidth;
	s32 textheight;
	union handlerdata data;
	s32 slidervalue;
	s32 markerx;

	extray = 0;

	if (context->item->handler != NULL) {
		context->item->handler(MENUOP_GETSLIDER, context->item, &data);
		slidervalue = data.slider.unk02;
	} else {
		slidervalue = 0;
	}

	if (context->dialog->unk6e != 0) {
		extray = 10;
	}

	if (context->item->flags & MENUITEMFLAG_00100000) {
		extray = 10;
	}

	x = context->x + 10;
	y = context->y + 2;

	if (context->item->flags & MENUITEMFLAG_00000010) {
		x -= 6;
	}

	label = menuResolveParam2Text(context->item);
	markerx = context->x + context->width + slidervalue * 75 / context->item->param3 - 82;

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused) {
		if (context->focused & 2) {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f;

			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight) | 0xff;
		}

		func0f153e38(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		func0f153e38(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = menugfxRenderSlider(gdl, context->x + context->width - 82, context->y + extray + 5, context->x + context->width - 7, context->y + extray + 11, markerx, colour);

	colour = MIXCOLOUR(context->dialog, unfocused);

	if (context->dialog->dimmed) {
		colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
	}

	if (context->focused != 0) {
		if (context->focused & 2) {
			u32 tmpcolour;
			u32 weight = func0f006b08(20) * 255.0f;
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		} else {
			u32 tmpcolour;
			u32 weight = func0f006b08(40) * 255.0f;
			tmpcolour = MIXCOLOUR(context->dialog, focused);

			colour = colourBlend(colour, colour & 0xff, 0x7f);
			colour = colourBlend(colour, tmpcolour, weight);
		}

		func0f153e38(g_MenuColourPalettes3[context->dialog->type].focused, g_MenuColourPalettes2[context->dialog->type].focused);
	} else {
		func0f153e38(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = func0f153628(gdl);
	gdl = textRenderProjected(gdl, &x, &y, label, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);

	if ((context->item->flags & MENUITEMFLAG_00002000) == 0) {
		strcpy(buffer, "");
		sprintf(buffer, "%d\n", slidervalue);

		if (context->item->handler != NULL) {
			data.slider.value = slidervalue;
			data.slider.label = buffer;

			context->item->handler(MENUOP_GETSLIDERLABEL, context->item, &data);
		}

		textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		x = context->x + context->width - textwidth - 7;
		y = context->y + 2;

		colour = MIXCOLOUR(context->dialog, unfocused);

		if (context->dialog->dimmed) {
			colour = (colourBlend(colour, 0, 0x7f) & 0xffffff00) | (colour & 0xff);
		}

		func0f153e38(g_MenuColourPalettes3[context->dialog->type].unfocused, g_MenuColourPalettes2[context->dialog->type].unfocused);

		colour = (colour & 0xffffff00) | ((colour & 0xff) >> 1);
		gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, context->width, context->height, 0, 0);
	}

	gdl = func0f153780(gdl);

	return gdl;
}

bool menuitemSliderTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	s32 index;
	union handlerdata handlerdata;
	s32 tmp;
	f32 f0;
	f32 f2;
	f32 f14;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED)) {
		if (tickflags & MENUTICKFLAG_DIALOGISDIMMED) {
			if (item->handler) {
				item->handler(MENUOP_GETSLIDER, item, &handlerdata);
				index = (s16)handlerdata.slider.value;
			} else {
				index = 0;
			}

			if ((item->flags & MENUITEMFLAG_00000800) == 0
					&& g_Menus[g_MpPlayerNum].xrepeatmode == MENUREPEATMODE_SLOW) {
				index = index + inputs->leftright;
			} else {
				f0 = data->slider.unk00 / 1000.0f;
				f0 = (f0 * 100.0f) / item->param3;
#if VERSION >= VERSION_PAL_BETA
				f0 = f0 + inputs->leftrightheld * g_Vars.diffframe60freal;
#else
				f0 = f0 + inputs->leftrightheld * g_Vars.diffframe60;
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

			if ((item->flags & MENUITEMFLAG_00000800) == 0 && f2 < 40) {
				if (g_Menus[g_MpPlayerNum].xrepeatmode != MENUREPEATMODE_SLOW) {
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
#if VERSION >= VERSION_PAL_BETA
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
				dialog->dimmed = false;
			}
		} else {
			if (inputs->select) {
				dialog->dimmed = true;
			}
		}
	}

	return true;
}

void menuitemSliderInit(union menuitemdata *data)
{
	data->slider.unk00 = 0;
}

Gfx *menuitemCarouselRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 colour = 0xff0000ff;

	if (context->focused) {
		u32 colour1;
		u32 weight = func0f006b08(40) * 255;

		if (context->dialog->transitionfrac < 0) {
			colour1 = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			colour1 = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		colour = colourBlend(colourBlend(colour, 0x000000ff, 127), colour1, weight);
	}

	// Left arrow
	gdl = menugfxDrawCarouselChevron(gdl, context->x, context->y + context->height / 2, 8, 1, -1, colour);

	// Right arrow
	gdl = menugfxDrawCarouselChevron(gdl, context->x + context->width, context->y + context->height / 2, 8, 3, -1, colour);

	// This part of the function is unused because param2 is always zero.
	// Setting it to 0x7b causes a crash.
	// 0x7c and 0x7d don't do anything with the option value, so it's probable
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

bool menuitemCarouselTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	union handlerdata data;
	s32 index;
	s32 numoptions;
	bool done;
	u32 stack;

	if (((tickflags & MENUTICKFLAG_ITEMISFOCUSED) || (item->flags & MENUITEMFLAG_04000000)) && item->handler) {
		if (inputs->leftright != 0) {
			if (mpIsPlayerLockedOut(g_MpPlayerNum) == 0 || (item->flags & MENUITEMFLAG_00020000) == 0) {
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

Gfx *menuitemCheckboxRender(Gfx *gdl, struct menurendercontext *context)
{
	u32 maincolour = 0x00000000;
	char *text;
	s32 x;
	s32 y;
	u8 data[3];
	bool checked = false;
	u32 fillcolour = 0xff002faf;
	struct font *font2 = g_FontHandelGothicSm;
	struct fontchar *font1 = g_CharsHandelGothicSm;

	if (context->item->flags & MENUITEMFLAG_00000200) {
		font2 = g_FontHandelGothicXs;
		font1 = g_CharsHandelGothicXs;
	}

	x = context->x;
	y = context->y;
	text = menuResolveParam2Text(context->item);
	data[0] = 0;

	if (context->item->handler
			&& context->item->handler(MENUOP_GET, context->item, (union handlerdata *)data) == true) {
		checked = true;

		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].checkedunfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].checkedunfocused,
					g_MenuColourPalettes[context->dialog->type].checkedunfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].checkedunfocused,
				g_MenuColourPalettes2[context->dialog->type].checkedunfocused);
	} else {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].unfocused,
				g_MenuColourPalettes2[context->dialog->type].unfocused);
	}

	gdl = func0f153628(gdl);

	if (context->focused) {
		// Mismatch: The addiu and lui at ec8fc and ec900 are swapped. The addiu
		// is adding the lower half of the address of g_MenuColourPalettes for
		// use in the else branch. The lui is loading a value into $at for the
		// float to u32 conversion for weight.
		u32 focuscolour;
		u32 weight = func0f006b08(40) * 255; \
		if (context->dialog->transitionfrac < 0) { \
			focuscolour = g_MenuColourPalettes[context->dialog->type].focused;
		} else {
			focuscolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].focused,
					g_MenuColourPalettes[context->dialog->type].focused,
					context->dialog->colourweight);
		}

		maincolour = colourBlend(colourBlend(maincolour, maincolour & 0xff, 127), focuscolour, weight);

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].focused,
				g_MenuColourPalettes2[context->dialog->type].focused);
	}

	if (menuIsItemDisabled(context->item, context->dialog)) {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].disabled;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].disabled,
					g_MenuColourPalettes[context->dialog->type].disabled,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
			maincolour = colourBlend(maincolour, 0, 127) & 0xffffff00 | maincolour & 0xff;
		}

		func0f153e38(
				g_MenuColourPalettes3[context->dialog->type].disabled,
				g_MenuColourPalettes2[context->dialog->type].disabled);

		fillcolour = 0x7f002faf;
	}

	gdl = menugfxDrawCheckbox(gdl, context->x + context->width - 16, context->y + 2, 6,
			checked, maincolour, fillcolour);

	x = context->x + 10;
	y = context->y + 2;
	gdl = textRenderProjected(gdl, &x, &y, text, font1, font2,
			maincolour, context->width, context->height, 0, 0);

	return func0f153780(gdl);
}

bool menuitemCheckboxTick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags)
{
	union handlerdata data;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && inputs->select) {
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

char *menuitemScrollableGetText(u32 type)
{
	switch (type) {
	case DESCRIPTION_MPCONFIG:
		return mpconfigGetDescription(g_Menus[g_MpPlayerNum].training.mpconfig);
	case DESCRIPTION_MPCHALLENGE:
		if (!mpIsChallengeLoaded()) {
			g_Menus[g_MpPlayerNum].unk840.unk010 = 0x4fac5ace;
			mpLoadAndStoreCurrentChallenge(g_Menus[g_MpPlayerNum].unk840.unk004, g_Menus[g_MpPlayerNum].unk840.unk008);
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
 * The text returned from menuitemScrollableGetText is first wrapped to fit the
 * width of the dialog. It is then separated into two strings:
 *
 * headings - which are started with the pipe character and ended with a
 * double line break
 * body text - which is anything else
 *
 * Headings are rendered in red, with a dropshadow and are outdented.
 */
Gfx *menuitemScrollableRender(Gfx *gdl, struct menurendercontext *context)
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

	rawtext = menuitemScrollableGetText(context->item->param);

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

	if (context->dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		colour = colourBlend(colour, 0, 0x7f) & 0xffffff00 | colour & 0xff;
	}

	func0f153e38(
			g_MenuColourPalettes3[context->dialog->type].unfocused,
			g_MenuColourPalettes2[context->dialog->type].unfocused);

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

bool menuitemScrollableTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	u32 stack;

#if VERSION >= VERSION_PAL_BETA
	if ((s16)dialog->height != data->scrollable.unk06 || data->scrollable.unk08 != g_LanguageId) {
#else
	if ((s16)dialog->height != data->scrollable.unk06) {
#endif
		char wrapped[8000] = "";
		char *rawtext;
		s32 width;
		s32 height;
		s32 rowindex;
		s32 colindex;
		s16 colwidth;
		s16 rowheight;

#if VERSION >= VERSION_PAL_BETA
		data->scrollable.unk08 = g_LanguageId;
#endif

		dialogFindItem(dialog, item, &rowindex, &colindex);

		colwidth = g_Menus[g_MpPlayerNum].cols[colindex].width;
		rowheight = g_Menus[g_MpPlayerNum].rows[rowindex].height;

		if (menuIsScrollableUnscrollable(item)) {
			width = colwidth - 10;
		} else {
			width = colwidth - 24;
		}

		rawtext = menuitemScrollableGetText(item->param);

		if (rawtext) {
			textWrap(width, rawtext, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm);
		}

		textMeasure(&height, &width, wrapped, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

		data->scrollable.unk04 = height - rowheight + 5;

		if (data->scrollable.unk04 < -10) {
			data->scrollable.unk04 = -10;
		}

		data->scrollable.unk06 = dialog->height;
	}

	if (menuIsScrollableUnscrollable(item)) {
		data->scrollable.unk00 = 0;
	} else if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		f32 floatval;
		s32 intval = 0;

		if (inputs->yaxis < 0) {
			floatval = -(f32)inputs->yaxis;
		} else {
			floatval = inputs->yaxis;
		}

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
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

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
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

void menuitemScrollableInit(union menuitemdata *data)
{
	data->scrollable.unk06 = -1;
	data->scrollable.unk00 = -10;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuitemMarqueeRender
/*  f0ee244:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0ee248:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0ee24c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0ee250:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0ee254:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f0ee258:	8cae0014 */ 	lw	$t6,0x14($a1)
/*  f0ee25c:	00a08825 */ 	move	$s1,$a1
/*  f0ee260:	afae0084 */ 	sw	$t6,0x84($sp)
/*  f0ee264:	0fc3c87a */ 	jal	0xf0f21e8
/*  f0ee268:	8ca40008 */ 	lw	$a0,0x8($a1)
/*  f0ee26c:	3c188007 */ 	lui	$t8,0x8007
/*  f0ee270:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0ee274:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0ee278:	2718172c */ 	addiu	$t8,$t8,0x172c
/*  f0ee27c:	9b010002 */ 	lwr	$at,0x2($t8)
/*  f0ee280:	27af0064 */ 	addiu	$t7,$sp,0x64
/*  f0ee284:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0ee288:	b9e10002 */ 	swr	$at,0x2($t7)
/*  f0ee28c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0ee290:	8d4a0154 */ 	lw	$t2,0x154($t2)
/*  f0ee294:	8d6b0150 */ 	lw	$t3,0x150($t3)
/*  f0ee298:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f0ee29c:	14400003 */ 	bnez	$v0,.JF0f0ee2ac
/*  f0ee2a0:	afab005c */ 	sw	$t3,0x5c($sp)
/*  f0ee2a4:	10000131 */ 	b	.JF0f0ee76c
/*  f0ee2a8:	8fa20088 */ 	lw	$v0,0x88($sp)
.JF0f0ee2ac:
/*  f0ee2ac:	8e300010 */ 	lw	$s0,0x10($s1)
/*  f0ee2b0:	44803000 */ 	mtc1	$zero,$f6
/*  f0ee2b4:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0ee2b8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0ee2bc:	00000000 */ 	nop
/*  f0ee2c0:	4502000c */ 	bc1fl	.JF0f0ee2f4
/*  f0ee2c4:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f0ee2c8:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0ee2cc:	2403003c */ 	li	$v1,0x3c
/*  f0ee2d0:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ee2d4:	01830019 */ 	multu	$t4,$v1
/*  f0ee2d8:	24422ce0 */ 	addiu	$v0,$v0,0x2ce0
/*  f0ee2dc:	00006812 */ 	mflo	$t5
/*  f0ee2e0:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0ee2e4:	8dc80018 */ 	lw	$t0,0x18($t6)
/*  f0ee2e8:	10000012 */ 	b	.JF0f0ee334
/*  f0ee2ec:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0ee2f0:	9219003d */ 	lbu	$t9,0x3d($s0)
.JF0f0ee2f4:
/*  f0ee2f4:	2403003c */ 	li	$v1,0x3c
/*  f0ee2f8:	9209003c */ 	lbu	$t1,0x3c($s0)
/*  f0ee2fc:	03230019 */ 	multu	$t9,$v1
/*  f0ee300:	3c027f1b */ 	lui	$v0,0x7f1b
/*  f0ee304:	24422ce0 */ 	addiu	$v0,$v0,0x2ce0
/*  f0ee308:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0ee30c:	00007812 */ 	mflo	$t7
/*  f0ee310:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0ee314:	8f040018 */ 	lw	$a0,0x18($t8)
/*  f0ee318:	01230019 */ 	multu	$t1,$v1
/*  f0ee31c:	00005012 */ 	mflo	$t2
/*  f0ee320:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f0ee324:	0fc01a60 */ 	jal	0xf006980
/*  f0ee328:	8d650018 */ 	lw	$a1,0x18($t3)
/*  f0ee32c:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0ee330:	8e300010 */ 	lw	$s0,0x10($s1)
.JF0f0ee334:
/*  f0ee334:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0ee338:	5180000c */ 	beqzl	$t4,.JF0f0ee36c
/*  f0ee33c:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f0ee340:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0ee344:	00002825 */ 	move	$a1,$zero
/*  f0ee348:	0fc01a60 */ 	jal	0xf006980
/*  f0ee34c:	2406007f */ 	li	$a2,0x7f
/*  f0ee350:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0ee354:	2401ff00 */ 	li	$at,-256
/*  f0ee358:	00416824 */ 	and	$t5,$v0,$at
/*  f0ee35c:	31c800ff */ 	andi	$t0,$t6,0xff
/*  f0ee360:	01a8c825 */ 	or	$t9,$t5,$t0
/*  f0ee364:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0ee368:	8faa0084 */ 	lw	$t2,0x84($sp)
.JF0f0ee36c:
/*  f0ee36c:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ee370:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ee374:	954b0000 */ 	lhu	$t3,0x0($t2)
/*  f0ee378:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f0ee37c:	01f84821 */ 	addu	$t1,$t7,$t8
/*  f0ee380:	012b6023 */ 	subu	$t4,$t1,$t3
/*  f0ee384:	afac007c */ 	sw	$t4,0x7c($sp)
/*  f0ee388:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f0ee38c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0ee390:	25cd0002 */ 	addiu	$t5,$t6,0x2
/*  f0ee394:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0ee398:	01198021 */ 	addu	$s0,$t0,$t9
/*  f0ee39c:	92020000 */ 	lbu	$v0,0x0($s0)
.JF0f0ee3a0:
/*  f0ee3a0:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ee3a4:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ee3a8:	14400003 */ 	bnez	$v0,.JF0f0ee3b8
/*  f0ee3ac:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0ee3b0:	10000029 */ 	b	.JF0f0ee458
/*  f0ee3b4:	00001025 */ 	move	$v0,$zero
.JF0f0ee3b8:
/*  f0ee3b8:	28610080 */ 	slti	$at,$v1,0x80
/*  f0ee3bc:	10200003 */ 	beqz	$at,.JF0f0ee3cc
/*  f0ee3c0:	a3a20064 */ 	sb	$v0,0x64($sp)
/*  f0ee3c4:	1000000f */ 	b	.JF0f0ee404
/*  f0ee3c8:	a3a00065 */ 	sb	$zero,0x65($sp)
.JF0f0ee3cc:
/*  f0ee3cc:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f0ee3d0:	3062007f */ 	andi	$v0,$v1,0x7f
/*  f0ee3d4:	2401003e */ 	li	$at,0x3e
/*  f0ee3d8:	14410005 */ 	bne	$v0,$at,.JF0f0ee3f0
/*  f0ee3dc:	a3af0065 */ 	sb	$t7,0x65($sp)
/*  f0ee3e0:	93a30064 */ 	lbu	$v1,0x64($sp)
/*  f0ee3e4:	2478ffff */ 	addiu	$t8,$v1,-1
/*  f0ee3e8:	3302007f */ 	andi	$v0,$t8,0x7f
/*  f0ee3ec:	a3b80064 */ 	sb	$t8,0x64($sp)
.JF0f0ee3f0:
/*  f0ee3f0:	24010004 */ 	li	$at,0x4
/*  f0ee3f4:	14410003 */ 	bne	$v0,$at,.JF0f0ee404
/*  f0ee3f8:	93a30064 */ 	lbu	$v1,0x64($sp)
/*  f0ee3fc:	246affff */ 	addiu	$t2,$v1,-1
/*  f0ee400:	a3aa0064 */ 	sb	$t2,0x64($sp)
.JF0f0ee404:
/*  f0ee404:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0ee408:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0ee40c:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f0ee410:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0ee414:	0fc55d49 */ 	jal	0xf157524
/*  f0ee418:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ee41c:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0ee420:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f0ee424:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f0ee428:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f0ee42c:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0ee430:	50200004 */ 	beqzl	$at,.JF0f0ee444
/*  f0ee434:	93ad0065 */ 	lbu	$t5,0x65($sp)
/*  f0ee438:	10000007 */ 	b	.JF0f0ee458
/*  f0ee43c:	00001025 */ 	move	$v0,$zero
/*  f0ee440:	93ad0065 */ 	lbu	$t5,0x65($sp)
.JF0f0ee444:
/*  f0ee444:	24020001 */ 	li	$v0,0x1
/*  f0ee448:	afa3007c */ 	sw	$v1,0x7c($sp)
/*  f0ee44c:	11a00002 */ 	beqz	$t5,.JF0f0ee458
/*  f0ee450:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ee454:	26100001 */ 	addiu	$s0,$s0,0x1
.JF0f0ee458:
/*  f0ee458:	24010001 */ 	li	$at,0x1
/*  f0ee45c:	5041ffd0 */ 	beql	$v0,$at,.JF0f0ee3a0
/*  f0ee460:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0ee464:	3c028008 */ 	lui	$v0,0x8008
/*  f0ee468:	8c4200f4 */ 	lw	$v0,0xf4($v0)
/*  f0ee46c:	86280000 */ 	lh	$t0,0x0($s1)
/*  f0ee470:	3c038007 */ 	lui	$v1,0x8007
/*  f0ee474:	246316d0 */ 	addiu	$v1,$v1,0x16d0
/*  f0ee478:	01020019 */ 	multu	$t0,$v0
/*  f0ee47c:	3c048007 */ 	lui	$a0,0x8007
/*  f0ee480:	248416d4 */ 	addiu	$a0,$a0,0x16d4
/*  f0ee484:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee488:	24c616d8 */ 	addiu	$a2,$a2,0x16d8
/*  f0ee48c:	3c058007 */ 	lui	$a1,0x8007
/*  f0ee490:	24a516dc */ 	addiu	$a1,$a1,0x16dc
/*  f0ee494:	0000c812 */ 	mflo	$t9
/*  f0ee498:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0ee49c:	86380004 */ 	lh	$t8,0x4($s1)
/*  f0ee4a0:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0ee4a4:	01f85021 */ 	addu	$t2,$t7,$t8
/*  f0ee4a8:	01420019 */ 	multu	$t2,$v0
/*  f0ee4ac:	00004812 */ 	mflo	$t1
/*  f0ee4b0:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f0ee4b4:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f0ee4b8:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f0ee4bc:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f0ee4c0:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f0ee4c4:	018e6821 */ 	addu	$t5,$t4,$t6
/*  f0ee4c8:	25a8ffff */ 	addiu	$t0,$t5,-1
/*  f0ee4cc:	07210002 */ 	bgez	$t9,.JF0f0ee4d8
/*  f0ee4d0:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f0ee4d4:	ac600000 */ 	sw	$zero,0x0($v1)
.JF0f0ee4d8:
/*  f0ee4d8:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0ee4dc:	05e30003 */ 	bgezl	$t7,.JF0f0ee4ec
/*  f0ee4e0:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0ee4e4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0ee4e8:	8cd80000 */ 	lw	$t8,0x0($a2)
.JF0f0ee4ec:
/*  f0ee4ec:	07030003 */ 	bgezl	$t8,.JF0f0ee4fc
/*  f0ee4f0:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0ee4f4:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0ee4f8:	8caa0000 */ 	lw	$t2,0x0($a1)
.JF0f0ee4fc:
/*  f0ee4fc:	05410002 */ 	bgez	$t2,.JF0f0ee508
/*  f0ee500:	00000000 */ 	nop
/*  f0ee504:	aca00000 */ 	sw	$zero,0x0($a1)
.JF0f0ee508:
/*  f0ee508:	0c002eda */ 	jal	0xbb68
/*  f0ee50c:	00000000 */ 	nop
/*  f0ee510:	3c098007 */ 	lui	$t1,0x8007
/*  f0ee514:	8d2916d0 */ 	lw	$t1,0x16d0($t1)
/*  f0ee518:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ee51c:	10200005 */ 	beqz	$at,.JF0f0ee534
/*  f0ee520:	00000000 */ 	nop
/*  f0ee524:	0c002eda */ 	jal	0xbb68
/*  f0ee528:	00000000 */ 	nop
/*  f0ee52c:	3c018007 */ 	lui	$at,0x8007
/*  f0ee530:	ac2216d0 */ 	sw	$v0,0x16d0($at)
.JF0f0ee534:
/*  f0ee534:	0c002eda */ 	jal	0xbb68
/*  f0ee538:	00000000 */ 	nop
/*  f0ee53c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0ee540:	8d6b16d4 */ 	lw	$t3,0x16d4($t3)
/*  f0ee544:	004b082a */ 	slt	$at,$v0,$t3
/*  f0ee548:	10200005 */ 	beqz	$at,.JF0f0ee560
/*  f0ee54c:	00000000 */ 	nop
/*  f0ee550:	0c002eda */ 	jal	0xbb68
/*  f0ee554:	00000000 */ 	nop
/*  f0ee558:	3c018007 */ 	lui	$at,0x8007
/*  f0ee55c:	ac2216d4 */ 	sw	$v0,0x16d4($at)
.JF0f0ee560:
/*  f0ee560:	0c002ede */ 	jal	0xbb78
/*  f0ee564:	00000000 */ 	nop
/*  f0ee568:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0ee56c:	8d8c16d8 */ 	lw	$t4,0x16d8($t4)
/*  f0ee570:	004c082a */ 	slt	$at,$v0,$t4
/*  f0ee574:	10200005 */ 	beqz	$at,.JF0f0ee58c
/*  f0ee578:	00000000 */ 	nop
/*  f0ee57c:	0c002ede */ 	jal	0xbb78
/*  f0ee580:	00000000 */ 	nop
/*  f0ee584:	3c018007 */ 	lui	$at,0x8007
/*  f0ee588:	ac2216d8 */ 	sw	$v0,0x16d8($at)
.JF0f0ee58c:
/*  f0ee58c:	0c002ede */ 	jal	0xbb78
/*  f0ee590:	00000000 */ 	nop
/*  f0ee594:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee598:	24c616dc */ 	addiu	$a2,$a2,0x16dc
/*  f0ee59c:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ee5a0:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ee5a4:	10200009 */ 	beqz	$at,.JF0f0ee5cc
/*  f0ee5a8:	00000000 */ 	nop
/*  f0ee5ac:	0c002ede */ 	jal	0xbb78
/*  f0ee5b0:	00000000 */ 	nop
/*  f0ee5b4:	3c018007 */ 	lui	$at,0x8007
/*  f0ee5b8:	ac2216dc */ 	sw	$v0,0x16dc($at)
/*  f0ee5bc:	3c058007 */ 	lui	$a1,0x8007
/*  f0ee5c0:	3c068007 */ 	lui	$a2,0x8007
/*  f0ee5c4:	24c616dc */ 	addiu	$a2,$a2,0x16dc
/*  f0ee5c8:	8ca516dc */ 	lw	$a1,0x16dc($a1)
.JF0f0ee5cc:
/*  f0ee5cc:	3c078007 */ 	lui	$a3,0x8007
/*  f0ee5d0:	3c038007 */ 	lui	$v1,0x8007
/*  f0ee5d4:	8c6316d0 */ 	lw	$v1,0x16d0($v1)
/*  f0ee5d8:	24e716d4 */ 	addiu	$a3,$a3,0x16d4
/*  f0ee5dc:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0ee5e0:	44834000 */ 	mtc1	$v1,$f8
/*  f0ee5e4:	3c048007 */ 	lui	$a0,0x8007
/*  f0ee5e8:	01c3082a */ 	slt	$at,$t6,$v1
/*  f0ee5ec:	10200002 */ 	beqz	$at,.JF0f0ee5f8
/*  f0ee5f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ee5f4:	ace30000 */ 	sw	$v1,0x0($a3)
.JF0f0ee5f8:
/*  f0ee5f8:	8c8416d8 */ 	lw	$a0,0x16d8($a0)
/*  f0ee5fc:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0ee600:	50200003 */ 	beqzl	$at,.JF0f0ee610
/*  f0ee604:	44842000 */ 	mtc1	$a0,$f4
/*  f0ee608:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0ee60c:	44842000 */ 	mtc1	$a0,$f4
.JF0f0ee610:
/*  f0ee610:	3c014080 */ 	lui	$at,0x4080
/*  f0ee614:	44810000 */ 	mtc1	$at,$f0
/*  f0ee618:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ee61c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f0ee620:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ee624:	3c01ed00 */ 	lui	$at,0xed00
/*  f0ee628:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0ee62c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ee630:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ee634:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ee638:	44089000 */ 	mfc1	$t0,$f18
/*  f0ee63c:	44095000 */ 	mfc1	$t1,$f10
/*  f0ee640:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ee644:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f0ee648:	01e1c025 */ 	or	$t8,$t7,$at
/*  f0ee64c:	312b0fff */ 	andi	$t3,$t1,0xfff
/*  f0ee650:	030b6025 */ 	or	$t4,$t8,$t3
/*  f0ee654:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0ee658:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0ee65c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0ee660:	448e8000 */ 	mtc1	$t6,$f16
/*  f0ee664:	448a4000 */ 	mtc1	$t2,$f8
/*  f0ee668:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ee66c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0ee670:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0ee674:	00000000 */ 	nop
/*  f0ee678:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0ee67c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ee680:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0ee684:	44083000 */ 	mfc1	$t0,$f6
/*  f0ee688:	44189000 */ 	mfc1	$t8,$f18
/*  f0ee68c:	31190fff */ 	andi	$t9,$t0,0xfff
/*  f0ee690:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f0ee694:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f0ee698:	01eb6025 */ 	or	$t4,$t7,$t3
/*  f0ee69c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0ee6a0:	0fc54d24 */ 	jal	0xf153490
/*  f0ee6a4:	afa50088 */ 	sw	$a1,0x88($sp)
/*  f0ee6a8:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f0ee6ac:	8dcd0004 */ 	lw	$t5,0x4($t6)
/*  f0ee6b0:	31a80800 */ 	andi	$t0,$t5,0x800
/*  f0ee6b4:	51000009 */ 	beqzl	$t0,.JF0f0ee6dc
/*  f0ee6b8:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ee6bc:	86240000 */ 	lh	$a0,0x0($s1)
/*  f0ee6c0:	86390004 */ 	lh	$t9,0x4($s1)
/*  f0ee6c4:	2406001c */ 	li	$a2,0x1c
/*  f0ee6c8:	0fc54d15 */ 	jal	0xf153454
/*  f0ee6cc:	00992821 */ 	addu	$a1,$a0,$t9
/*  f0ee6d0:	10000005 */ 	b	.JF0f0ee6e8
/*  f0ee6d4:	00000000 */ 	nop
/*  f0ee6d8:	86240000 */ 	lh	$a0,0x0($s1)
.JF0f0ee6dc:
/*  f0ee6dc:	2406000e */ 	li	$a2,0xe
/*  f0ee6e0:	0fc54d15 */ 	jal	0xf153454
/*  f0ee6e4:	00802825 */ 	move	$a1,$a0
.JF0f0ee6e8:
/*  f0ee6e8:	0fc54b55 */ 	jal	0xf152d54
/*  f0ee6ec:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f0ee6f0:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f0ee6f4:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0ee6f8:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f0ee6fc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ee700:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0ee704:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ee708:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f0ee70c:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f0ee710:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0ee714:	00402025 */ 	move	$a0,$v0
/*  f0ee718:	01eb6021 */ 	addu	$t4,$t7,$t3
/*  f0ee71c:	018e6823 */ 	subu	$t5,$t4,$t6
/*  f0ee720:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0ee724:	86280006 */ 	lh	$t0,0x6($s1)
/*  f0ee728:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0ee72c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0ee730:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0ee734:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0ee738:	02003825 */ 	move	$a3,$s0
/*  f0ee73c:	0fc55886 */ 	jal	0xf156218
/*  f0ee740:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0ee744:	0fc54bb7 */ 	jal	0xf152edc
/*  f0ee748:	00402025 */ 	move	$a0,$v0
/*  f0ee74c:	0fc3d768 */ 	jal	0xf0f5da0
/*  f0ee750:	00402025 */ 	move	$a0,$v0
/*  f0ee754:	0fc54d2a */ 	jal	0xf1534a8
/*  f0ee758:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0ee75c:	86390004 */ 	lh	$t9,0x4($s1)
/*  f0ee760:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f0ee764:	a5590004 */ 	sh	$t9,0x4($t2)
/*  f0ee768:	8fa20088 */ 	lw	$v0,0x88($sp)
.JF0f0ee76c:
/*  f0ee76c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0ee770:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0ee774:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0ee778:	03e00008 */ 	jr	$ra
/*  f0ee77c:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel menuitemMarqueeRender
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
/*  f0ed7bc:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7c0:	00000000 */ 	nop
/*  f0ed7c4:	3c198007 */ 	lui	$t9,%hi(g_ScissorX1)
/*  f0ed7c8:	8f391190 */ 	lw	$t9,%lo(g_ScissorX1)($t9)
/*  f0ed7cc:	0059082a */ 	slt	$at,$v0,$t9
/*  f0ed7d0:	10200005 */ 	beqz	$at,.L0f0ed7e8
/*  f0ed7d4:	00000000 */ 	nop
/*  f0ed7d8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7dc:	00000000 */ 	nop
/*  f0ed7e0:	3c018007 */ 	lui	$at,%hi(g_ScissorX1)
/*  f0ed7e4:	ac221190 */ 	sw	$v0,%lo(g_ScissorX1)($at)
.L0f0ed7e8:
/*  f0ed7e8:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed7ec:	00000000 */ 	nop
/*  f0ed7f0:	3c088007 */ 	lui	$t0,%hi(g_ScissorX2)
/*  f0ed7f4:	8d081194 */ 	lw	$t0,%lo(g_ScissorX2)($t0)
/*  f0ed7f8:	0048082a */ 	slt	$at,$v0,$t0
/*  f0ed7fc:	10200005 */ 	beqz	$at,.L0f0ed814
/*  f0ed800:	00000000 */ 	nop
/*  f0ed804:	0c002ef1 */ 	jal	viGetBufWidth
/*  f0ed808:	00000000 */ 	nop
/*  f0ed80c:	3c018007 */ 	lui	$at,%hi(g_ScissorX2)
/*  f0ed810:	ac221194 */ 	sw	$v0,%lo(g_ScissorX2)($at)
.L0f0ed814:
/*  f0ed814:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed818:	00000000 */ 	nop
/*  f0ed81c:	3c098007 */ 	lui	$t1,%hi(g_ScissorY1)
/*  f0ed820:	8d291198 */ 	lw	$t1,%lo(g_ScissorY1)($t1)
/*  f0ed824:	0049082a */ 	slt	$at,$v0,$t1
/*  f0ed828:	10200005 */ 	beqz	$at,.L0f0ed840
/*  f0ed82c:	00000000 */ 	nop
/*  f0ed830:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed834:	00000000 */ 	nop
/*  f0ed838:	3c018007 */ 	lui	$at,%hi(g_ScissorY1)
/*  f0ed83c:	ac221198 */ 	sw	$v0,%lo(g_ScissorY1)($at)
.L0f0ed840:
/*  f0ed840:	0c002ef5 */ 	jal	viGetBufHeight
/*  f0ed844:	00000000 */ 	nop
/*  f0ed848:	3c068007 */ 	lui	$a2,%hi(g_ScissorY2)
/*  f0ed84c:	24c6119c */ 	addiu	$a2,$a2,%lo(g_ScissorY2)
/*  f0ed850:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f0ed854:	0045082a */ 	slt	$at,$v0,$a1
/*  f0ed858:	10200009 */ 	beqz	$at,.L0f0ed880
/*  f0ed85c:	00000000 */ 	nop
/*  f0ed860:	0c002ef5 */ 	jal	viGetBufHeight
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
/*  f0eda00:	0fc3d43f */ 	jal	menuApplyScissor
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
glabel menuitemMarqueeRender
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
/*  f0eaa14:	0fc3c728 */ 	jal	menuApplyScissor
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
//Gfx *menuitemMarqueeRender(Gfx *gdl, struct menurendercontext *context)
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
//	if (context->item->flags & MENUITEMFLAG_00000200) {
//		font2 = g_FontHandelGothicXs;
//		font1 = g_CharsHandelGothicXs;
//	}
//
//	if (!text) {
//		return gdl;
//	}
//
//	// 5b8
//	if (context->dialog->transitionfrac < 0) {
//		colour = g_MenuColourPalettes[context->dialog->type].unfocused;
//	} else {
//		colour = colourBlend(
//				g_MenuColourPalettes[context->dialog->type2].unfocused,
//				g_MenuColourPalettes[context->dialog->type].unfocused,
//				context->dialog->colourweight);
//	}
//
//	// 644
//	if (context->dialog->dimmed) {
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
//	if (g_ScissorX1 > viGetBufWidth()) {
//		g_ScissorX1 = viGetBufWidth();
//	}
//
//	if (g_ScissorX2 > viGetBufWidth()) {
//		g_ScissorX2 = viGetBufWidth();
//	}
//
//	if (g_ScissorY1 > viGetBufHeight()) {
//		g_ScissorY1 = viGetBufHeight();
//	}
//
//	if (g_ScissorY2 > viGetBufHeight()) {
//		g_ScissorY2 = viGetBufHeight();
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
//	if (context->item->flags & MENUITEMFLAG_00000800) {
//		func0f153ce8(context->x, context->x + context->width, 0xe);
//	} else {
//		func0f153ce8(context->x, context->x, 0xe);
//	}
//
//	gdl = func0f153628(gdl);
//	gdl = textRenderProjected(gdl, &x, &y, &text[i], font1, font2,
//			colour, context->width + context->x - x, context->height, 0, 0);
//	gdl = func0f153780(gdl);
//	gdl = menuApplyScissor(gdl);
//
//	func0f153d3c();
//
//	unk14[2] = context->width;
//
//	return gdl;
//}

u32 var800711f0 = 0x00000002;

bool menuitemMarqueeTick(struct menuitem *item, union menuitemdata *data)
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

#if VERSION == VERSION_JPN_FINAL
	font1 = g_CharsHandelGothicSm;
	font2 = g_FontHandelGothicSm;
#else
	font2 = g_FontHandelGothicSm;
	font1 = g_CharsHandelGothicSm;

	if (item->flags & MENUITEMFLAG_00000200) {
		font2 = g_FontHandelGothicXs;
		font1 = g_CharsHandelGothicXs;
	}
#endif

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

void menuitemMarqueeInit(union menuitemdata *data)
{
	data->marquee.totalmoved = 0;
	data->marquee.unk04 = 50;
	data->marquee.unk06 = 0;
}

Gfx *menuitem07Render(Gfx *gdl)
{
	return gdl;
}

Gfx *menuitemRankingRender(Gfx *gdl, struct menurendercontext *context)
{
	struct ranking rankings[MAX_MPCHRS];
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
	struct menudialog *dialog;
	s32 gap;
	s32 i;

	if (context->item->param2 == 1) {
		team = true;
		numrows = mpGetTeamRankings(rankings);
	} else {
		numrows = mpGetPlayerRankings(rankings);
	}

	gdl = func0f153628(gdl);

	// Gap from last item to bottom of dialog + header height
#if VERSION >= VERSION_JPN_FINAL
	gap = numrows * (LINEHEIGHT - 1) - context->height + 22;
#else
	gap = numrows * (LINEHEIGHT - 1) - context->height + 18;
#endif

	if (gap < 0) {
		gap = 0;
	}

	if (data->scrolloffset > gap) {
		data->scrolloffset = gap;
	}

	if (context->dialog->transitionfrac < 0) {
		textcolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		textcolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
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

	dialog = context->dialog;

	if (dialog->transitionfrac < 0) {
		linecolour1 = g_MenuColourPalettes[dialog->type].unk00;
	} else {
		linecolour1 = colourBlend(
				g_MenuColourPalettes[dialog->type2].unk00,
				g_MenuColourPalettes[dialog->type].unk00,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		linecolour1 = colourBlend(linecolour1, 0, 44) & 0xffffff00 | linecolour1 & 0xff;
	}

	if (dialog->transitionfrac < 0) {
		linecolour2 = g_MenuColourPalettes[dialog->type].unk08;
	} else {
		linecolour2 = colourBlend(
				g_MenuColourPalettes[dialog->type2].unk08,
				g_MenuColourPalettes[dialog->type].unk08,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		linecolour2 = colourBlend(linecolour2, 0, 44) & 0xffffff00 | linecolour2 & 0xff;
	}

	linecolour1 = func0f153e94(context->x, context->y + 2, -129) & 0xff | linecolour1 & 0xffffff00;
	linecolour2 = func0f153e94(context->x + context->width, context->y + 2, -129) & 0xff | linecolour2 & 0xffffff00;

	// Horizontal line between header and body
	gdl = menugfxDrawFilledRect(gdl,
			context->x, context->y + 9,
			context->x + context->width, context->y + 10,
			linecolour1, linecolour1);

	gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
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

	if (g_ScissorX1 > viGetBufWidth()) {
		g_ScissorX1 = viGetBufWidth();
	}

	if (g_ScissorX2 > viGetBufWidth()) {
		g_ScissorX2 = viGetBufWidth();
	}

	if (g_ScissorY1 > viGetBufHeight()) {
		g_ScissorY1 = viGetBufHeight();
	}

	if (g_ScissorY2 > viGetBufHeight()) {
		g_ScissorY2 = viGetBufHeight();
	}

	if (g_ScissorX2 < g_ScissorX1) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY2 < g_ScissorY1) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
			context->x * g_ScaleX,
			context->y + 10,
			(context->x + context->width) * g_ScaleX,
			context->y + context->height - 1);
#endif

	gdl = func0f153628(gdl);

	for (i = 0; i < numrows; i++) {
		struct ranking *ranking = &rankings[i];
		u32 weight = 0;
		char valuebuffer[8];

#if VERSION < VERSION_NTSC_1_0
		u32 stack;
#endif

		if (numrows >= 2) {
			weight = i / (f32)(numrows - 1) * 255;
		}

		textcolour = colourBlend(0x008888ff, 0x00ffffff, weight);
		x = context->x + 5;
		y = context->y + i * 10 - data->scrolloffset + 14;

		if (team) {
			gdl = textRenderProjected(gdl, &x, &y, g_BossFile.teamnames[ranking->teamnum],
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		} else {
			gdl = textRenderProjected(gdl, &x, &y, ranking->mpchr->name,
					g_CharsHandelGothicSm, g_FontHandelGothicSm, textcolour, context->width, context->height, 0, 0);
		}

		if (!team) {
			// Deaths value (red)
			textcolour = colourBlend(0xcf0000ff, 0xff4040ff, weight);
			sprintf(valuebuffer, "%d\n", ranking->mpchr->numdeaths);
			textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			x = context->x - textwidth + 91;
			y = context->y + i * 10 - data->scrolloffset + 14;
			gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
					textcolour, context->width, context->height, 0, 0);
		}

		// Score value (green)
		textcolour = colourBlend(0x009f00ff, 0x00ff00ff, weight);
		sprintf(valuebuffer, "%d\n", ranking->score);
		textMeasure(&textheight, &textwidth, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
		x = context->x - textwidth + 120;
		y = context->y + i * 10 - data->scrolloffset + 14;
		gdl = textRenderProjected(gdl, &x, &y, valuebuffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
				textcolour, context->width, context->height, 0, 0);
	}

	return func0f153780(gdl);
}

bool menuitemRankingTick(struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if (tickflags & MENUTICKFLAG_ITEMISFOCUSED) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
#endif
		data->ranking.scrolloffset += intval;

		if (data->ranking.scrolloffset < 0) {
			data->ranking.scrolloffset = 0;
		}
	}

	return true;
}

void menuitemRankingInit(union menuitemdata *data)
{
	data->ranking.scrolloffset = 0;
}

Gfx *menuitemPlayerStatsRender(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_dropdown *data = &context->data->dropdown;
	s32 x;
	s32 y;
	u32 maincolour;
	s32 playernum = g_MpSelectedPlayersForStats[g_MpPlayerNum];
	struct mpchrconfig *mpchr;
	u32 selectioncolour;
	s32 textheight;
	s32 textwidth;
	s32 numchrs = mpGetNumChrs();
	char buffer[12];
	s32 i;
	u32 weight;
	s32 gap;
	s32 ypos = 0;

	mpchr = MPCHR(playernum);

	gdl = func0f153628(gdl);

	// Write selected player's name
	weight = func0f006b08(40) * 255;

	if (context->dialog->transitionfrac < 0) {
		selectioncolour = g_MenuColourPalettes[context->dialog->type].focused;
	} else {
		selectioncolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].focused,
				g_MenuColourPalettes[context->dialog->type].focused,
				context->dialog->colourweight);
	}

	selectioncolour = colourBlend(colourBlend(0xffffffff, 0x000000ff, 127), selectioncolour, weight);
	x = context->x + 2;
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, mpchr->name, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			selectioncolour, context->width, context->height, 0, 0);

	// "Suicides" heading
	if (context->dialog->transitionfrac < 0) {
		maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
	} else {
		maincolour = colourBlend(
				g_MenuColourPalettes[context->dialog->type2].unfocused,
				g_MenuColourPalettes[context->dialog->type].unfocused,
				context->dialog->colourweight);
	}

	if (context->dialog->dimmed) {
		maincolour = colourBlend(maincolour, 0x00000000, 127) & 0xffffff00 | maincolour & 0xff;
	}

	textMeasure(&textheight, &textwidth, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
#if VERSION >= VERSION_NTSC_1_0
	x = context->x - textwidth + 121;
#else
	x = context->x + 56;
#endif
	y = context->y + 1;

	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_281), g_CharsHandelGothicXs, g_FontHandelGothicXs,
			maincolour, context->width, context->height, 0, 0);

	// Num suicides
#if VERSION >= VERSION_NTSC_1_0
	x = context->x - textwidth + 119;
#endif
	sprintf(buffer, "%d\n", mpchr->killcounts[playernum]);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
#if VERSION >= VERSION_NTSC_1_0
	x -= textwidth;
#else
	x = context->x + 95;
#endif
	y = context->y + 1;

#if VERSION == VERSION_JPN_FINAL
	y++;
#endif

	gdl = textRenderProjected(gdl, &x, &y, buffer, g_CharsHandelGothicSm, g_FontHandelGothicSm,
			0xffff00ff, context->width, context->height, 0, 0);

	// Move ypos past top row
#if VERSION >= VERSION_JPN_FINAL
	ypos += 14;
#else
	ypos += 12;
#endif

	if (mpGetNumChrs() >= 2) {
		if (context->dialog->transitionfrac < 0) {
			maincolour = g_MenuColourPalettes[context->dialog->type].unfocused;
		} else {
			maincolour = colourBlend(
					g_MenuColourPalettes[context->dialog->type2].unfocused,
					g_MenuColourPalettes[context->dialog->type].unfocused,
					context->dialog->colourweight);
		}

		if (context->dialog->dimmed) {
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

#if VERSION >= VERSION_JPN_FINAL
		x = context->x + 25;
#else
		x = context->x - textwidth + 25;
#endif

		y = context->y + ypos;
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_283),  g_CharsHandelGothicXs, g_FontHandelGothicXs,
				maincolour, context->width, context->height, 0, 0);

		// Move ypos past heading row
#if VERSION >= VERSION_JPN_FINAL
		ypos += 12;
#else
		ypos += 7;
#endif

		// Prepare scissor for table
		gap = numchrs * (LINEHEIGHT - 1) - context->height + ypos;
		gap -= 10;

		if (gap < 0) {
			gap = 0;
		}

		if (data->scrolloffset > gap) {
			data->scrolloffset = gap;
		}

		gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
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

		if (g_ScissorX1 > viGetBufWidth()) {
			g_ScissorX1 = viGetBufWidth();
		}

		if (g_ScissorX2 > viGetBufWidth()) {
			g_ScissorX2 = viGetBufWidth();
		}

		if (g_ScissorY1 > viGetBufHeight()) {
			g_ScissorY1 = viGetBufHeight();
		}

		if (g_ScissorY2 > viGetBufHeight()) {
			g_ScissorY2 = viGetBufHeight();
		}

		if (g_ScissorX2 < g_ScissorX1) {
			g_ScissorX2 = g_ScissorX1;
		}

		if (g_ScissorY2 < g_ScissorY1) {
			g_ScissorY2 = g_ScissorY1;
		}

		gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
		gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
				context->x * g_ScaleX,
				context->y + ypos,
				(context->x + context->width) * g_ScaleX,
				context->y + context->height);
#endif

		ypos -= data->scrolloffset;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				struct mpchrconfig *loopmpchr = MPCHR(i);

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

#if VERSION >= VERSION_JPN_FINAL
					x = context->x + 25;
#else
					x = context->x - textwidth + 25;
#endif

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

bool menuitemPlayerStatsTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	f32 floatval;
	s32 intval;

	if ((tickflags & MENUTICKFLAG_ITEMISFOCUSED) && !dialog->dimmed) {
		intval = 0;
		floatval = inputs->yaxis < 0 ? -(f32)inputs->yaxis : inputs->yaxis;

		if (floatval > 20) {
			floatval = (floatval - 20) / 5;
#if VERSION >= VERSION_PAL_BETA
			floatval *= g_Vars.diffframe60freal;
#else
			floatval *= g_Vars.diffframe60f;
#endif

			intval = inputs->yaxis < 0 ? (s32)floatval : -(s32)floatval;
		}

#if VERSION >= VERSION_PAL_BETA
		intval = intval + (s32)(((f32)inputs->updownheld + (f32)inputs->updownheld) * g_Vars.diffframe60freal);
#else
		intval += inputs->updownheld * 2 * g_Vars.diffframe60;
#endif
		data->dropdown.scrolloffset += intval;

		if (data->dropdown.scrolloffset < 0) {
			data->dropdown.scrolloffset = 0;
		}
	}

	menuitemDropdownTick(item, dialog, inputs, tickflags, data);
}

Gfx *menuitemPlayerStatsOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
#if VERSION >= VERSION_NTSC_1_0
	return menuitemDropdownOverlay(gdl, x + 1, y, -1, y2, item, dialog, data);
#else
	return menuitemDropdownOverlay(gdl, x, y, 56, y2, item, dialog, data);
#endif
}

void menuitemPlayerStatsInit(struct menuitem *item, union menuitemdata *data)
{
	data->dropdown.scrolloffset = 0;
	g_MpSelectedPlayersForStats[g_MpPlayerNum] = g_MpPlayerNum;

	menuitemDropdownInit(item, data);
}

GLOBAL_ASM(
glabel menuitemControllerRenderLine
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

Gfx *menuitemControllerRenderTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha)
{
	gDPPipeSync(gdl++);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);

	func0f0b39c0(&gdl, &g_TexGeneralConfigs[texturenum], 2, 0, 2, 1, NULL);

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

struct lineconfig {
	s32 x1;
	s32 y1;
	s32 x2;
	s32 y2;
};

#if VERSION >= VERSION_JPN_FINAL
struct lineconfig linecfgs[] = {
	/* 0*/ { 12, 10, -1, 3  },
	/* 1*/ { 51, 10, -1, 3  },
	/* 2*/ { 12, 3,  75, -1 },
	/* 3*/ { 55, 19, 64, -1 },
	/* 4*/ { 63, 19, -1, 10 },
	/* 5*/ { 63, 10, 75, -1 },
	/* 6*/ { 51, 23, 55, -1 },
	/* 7*/ { 59, 23, 68, -1 },
	/* 8*/ { 67, 23, -1, 17 },
	/* 9*/ { 67, 17, 75, -1 },
	/*10*/ { 55, 27, 72, -1 },
	/*11*/ { 71, 27, -1, 24 },
	/*12*/ { 71, 24, 75, -1 },
	/*13*/ { 49, 31, 75, -1 },
	/*14*/ { 43, 28, -1, 38 },
	/*15*/ { 43, 38, 75, -1 },
	/*16*/ { 30, 35, 37, -1 },
	/*17*/ { 37, 35, -1, 45 },
	/*18*/ { 37, 45, 75, -1 },
	/*19*/ { 34, 52, 75, -1 },
	/*20*/ { 12, 30, -1, 59 },
	/*21*/ { 12, 59, 75, -1 },
};

GLOBAL_ASM(
glabel menuitemControllerRenderLines
/*  f0f04a4:	3c018006 */ 	lui	$at,0x8006
/*  f0f04a8:	c4241510 */ 	lwc1	$f4,0x1510($at)
/*  f0f04ac:	3c014080 */ 	lui	$at,0x4080
/*  f0f04b0:	44814000 */ 	mtc1	$at,$f8
/*  f0f04b4:	46002187 */ 	neg.s	$f6,$f4
/*  f0f04b8:	3c014248 */ 	lui	$at,0x4248
/*  f0f04bc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f04c0:	44818000 */ 	mtc1	$at,$f16
/*  f0f04c4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0f04c8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0f04cc:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f04d0:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0f04d4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0f04d8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0f04dc:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f04e0:	8fb00068 */ 	lw	$s0,0x68($sp)
/*  f0f04e4:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0f04e8:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0f04ec:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0f04f0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0f04f4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f04f8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0f04fc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0f0500:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0f0504:	44152000 */ 	mfc1	$s5,$f4
/*  f0f0508:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0f050c:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0510:	3c0de700 */ 	lui	$t5,0xe700
/*  f0f0514:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0518:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f051c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f0520:	0010c042 */ 	srl	$t8,$s0,0x1
/*  f0f0524:	03008025 */ 	move	$s0,$t8
/*  f0f0528:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f052c:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f0f0530:	3c0db900 */ 	lui	$t5,0xb900
/*  f0f0534:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0f0538:	00a0b025 */ 	move	$s6,$a1
/*  f0f053c:	3c05800b */ 	lui	$a1,0x800b
/*  f0f0540:	00c09025 */ 	move	$s2,$a2
/*  f0f0544:	00e09825 */ 	move	$s3,$a3
/*  f0f0548:	06a10004 */ 	bgez	$s5,.JF0f0f055c
/*  f0f054c:	32af0003 */ 	andi	$t7,$s5,0x3
/*  f0f0550:	11e00002 */ 	beqz	$t7,.JF0f0f055c
/*  f0f0554:	00000000 */ 	nop
/*  f0f0558:	25effffc */ 	addiu	$t7,$t7,-4
.JF0f0f055c:
/*  f0f055c:	01e0a825 */ 	move	$s5,$t7
/*  f0f0560:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f0564:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f0568:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f056c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f0570:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f0574:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f0578:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f0f057c:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f0580:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0584:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f0588:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f058c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f0590:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0f0594:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f0f0598:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f059c:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f05a0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f05a4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f05a8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f05ac:	240e0c00 */ 	li	$t6,0xc00
/*  f0f05b0:	24180001 */ 	li	$t8,0x1
/*  f0f05b4:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f05b8:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f05bc:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f05c0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f05c4:	8ca5bf98 */ 	lw	$a1,-0x4068($a1)
/*  f0f05c8:	240f0002 */ 	li	$t7,0x2
/*  f0f05cc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f05d0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f05d4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f05d8:	00003825 */ 	move	$a3,$zero
/*  f0f05dc:	24060002 */ 	li	$a2,0x2
/*  f0f05e0:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0f05e4:	0fc2d290 */ 	jal	0xf0b4a40
/*  f0f05e8:	24a50294 */ 	addiu	$a1,$a1,0x294
/*  f0f05ec:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f05f0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0f05f4:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f0f05f8:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f05fc:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0600:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0f0604:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0608:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0f060c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f0610:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0f0614:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0f0618:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0f061c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f0620:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0f0624:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0f0628:	3c0eff37 */ 	lui	$t6,0xff37
/*  f0f062c:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0f0630:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f0634:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f0f0638:	35ad9a25 */ 	ori	$t5,$t5,0x9a25
/*  f0f063c:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f0f0640:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f0644:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f0648:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0f064c:	2401ff00 */ 	li	$at,-256
/*  f0f0650:	02016025 */ 	or	$t4,$s0,$at
/*  f0f0654:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0f0658:	afb80050 */ 	sw	$t8,0x50($sp)
/*  f0f065c:	3c19fb00 */ 	lui	$t9,0xfb00
/*  f0f0660:	0272082a */ 	slt	$at,$s3,$s2
/*  f0f0664:	02408825 */ 	move	$s1,$s2
/*  f0f0668:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0f066c:	1420004e */ 	bnez	$at,.JF0f0f07a8
/*  f0f0670:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f0f0674:	00126900 */ 	sll	$t5,$s2,0x4
/*  f0f0678:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0f067c:	25ce1734 */ 	addiu	$t6,$t6,0x1734
/*  f0f0680:	26770001 */ 	addiu	$s7,$s3,0x1
/*  f0f0684:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0f0688:	01ae8021 */ 	addu	$s0,$t5,$t6
/*  f0f068c:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0f0690:	241e000e */ 	li	$s8,0xe
/*  f0f0694:	2414ffff */ 	li	$s4,-1
.JF0f0f0698:
/*  f0f0698:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f069c:	02a02825 */ 	move	$a1,$s5
/*  f0f06a0:	568f0005 */ 	bnel	$s4,$t7,.JF0f0f06b8
/*  f0f06a4:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f06a8:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f06ac:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0f06b0:	ae19000c */ 	sw	$t9,0xc($s0)
/*  f0f06b4:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f06b8:
/*  f0f06b8:	56880005 */ 	bnel	$s4,$t0,.JF0f0f06d0
/*  f0f06bc:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f06c0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f0f06c4:	25880001 */ 	addiu	$t0,$t4,0x1
/*  f0f06c8:	ae080008 */ 	sw	$t0,0x8($s0)
/*  f0f06cc:	8e0a0000 */ 	lw	$t2,0x0($s0)
.JF0f0f06d0:
/*  f0f06d0:	150a0002 */ 	bne	$t0,$t2,.JF0f0f06dc
/*  f0f06d4:	254e0001 */ 	addiu	$t6,$t2,0x1
/*  f0f06d8:	ae0e0008 */ 	sw	$t6,0x8($s0)
.JF0f0f06dc:
/*  f0f06dc:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f06e0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f06e4:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f0f06e8:	55e90004 */ 	bnel	$t7,$t1,.JF0f0f06fc
/*  f0f06ec:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f06f0:	ae18000c */ 	sw	$t8,0xc($s0)
/*  f0f06f4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f06f8:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f06fc:
/*  f0f06fc:	010a082a */ 	slt	$at,$t0,$t2
/*  f0f0700:	50200005 */ 	beqzl	$at,.JF0f0f0718
/*  f0f0704:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0f0708:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0f070c:	ae0a0008 */ 	sw	$t2,0x8($s0)
/*  f0f0710:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f0714:	8e0b000c */ 	lw	$t3,0xc($s0)
.JF0f0f0718:
/*  f0f0718:	0169082a */ 	slt	$at,$t3,$t1
/*  f0f071c:	50200006 */ 	beqzl	$at,.JF0f0f0738
/*  f0f0720:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0f0724:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f0f0728:	01205825 */ 	move	$t3,$t1
/*  f0f072c:	ae09000c */ 	sw	$t1,0xc($s0)
/*  f0f0730:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f0f0734:	8e080008 */ 	lw	$t0,0x8($s0)
.JF0f0f0738:
/*  f0f0738:	123e0008 */ 	beq	$s1,$s8,.JF0f0f075c
/*  f0f073c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0f0740:	24010011 */ 	li	$at,0x11
/*  f0f0744:	12210005 */ 	beq	$s1,$at,.JF0f0f075c
/*  f0f0748:	24010013 */ 	li	$at,0x13
/*  f0f074c:	12210003 */ 	beq	$s1,$at,.JF0f0f075c
/*  f0f0750:	24010015 */ 	li	$at,0x15
/*  f0f0754:	56210003 */ 	bnel	$s1,$at,.JF0f0f0764
/*  f0f0758:	86c20000 */ 	lh	$v0,0x0($s6)
.JF0f0f075c:
/*  f0f075c:	00152823 */ 	negu	$a1,$s5
/*  f0f0760:	86c20000 */ 	lh	$v0,0x0($s6)
.JF0f0f0764:
/*  f0f0764:	86c30002 */ 	lh	$v1,0x2($s6)
/*  f0f0768:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0f076c:	01026821 */ 	addu	$t5,$t0,$v0
/*  f0f0770:	01637821 */ 	addu	$t7,$t3,$v1
/*  f0f0774:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f0f0778:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f0f077c:	0142c821 */ 	addu	$t9,$t2,$v0
/*  f0f0780:	01236021 */ 	addu	$t4,$t1,$v1
/*  f0f0784:	01933821 */ 	addu	$a3,$t4,$s3
/*  f0f0788:	03323021 */ 	addu	$a2,$t9,$s2
/*  f0f078c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f0790:	0fc3c038 */ 	jal	0xf0f00e0
/*  f0f0794:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f0798:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f079c:	26100010 */ 	addiu	$s0,$s0,0x10
/*  f0f07a0:	16f1ffbd */ 	bne	$s7,$s1,.JF0f0f0698
/*  f0f07a4:	afa20050 */ 	sw	$v0,0x50($sp)
.JF0f0f07a8:
/*  f0f07a8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0f07ac:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0f07b0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0f07b4:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0f07b8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0f07bc:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0f07c0:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0f07c4:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0f07c8:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0f07cc:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0f07d0:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0f07d4:	03e00008 */ 	jr	$ra
/*  f0f07d8:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#else
Gfx *menuitemControllerRenderLines(Gfx *gdl, struct menurendercontext *context, s32 firstindex, s32 lastindex, s32 padx, s32 pady, u32 alpha)
{
	s32 speed;
	s32 i;

	static struct lineconfig linecfgs[] = {
#if PAL
		/* 0*/ { 12, -1, -1, 10 },
		/* 1*/ { 51, -1, -1, 10 },
		/* 2*/ { 12, -1, 75, -1 },
		/* 3*/ { 55, 19, 64, -1 },
		/* 4*/ { 63, 19, -1, 7  },
		/* 5*/ { 63, 7,  75, -1 },
		/* 6*/ { 51, 23, 55, -1 },
		/* 7*/ { 59, 23, 68, -1 },
		/* 8*/ { 67, 23, -1, 15 },
		/* 9*/ { 67, 15, 75, -1 },
		/*10*/ { 55, 27, 72, -1 },
		/*11*/ { 71, 27, -1, 23 },
		/*12*/ { 71, 23, 75, -1 },
		/*13*/ { 49, 31, 75, -1 },
		/*14*/ { 43, 28, -1, 39 },
		/*15*/ { 43, 39, 75, -1 },
		/*16*/ { 30, 35, 37, -1 },
		/*17*/ { 37, 35, -1, 47 },
		/*18*/ { 37, 47, 75, -1 },
		/*19*/ { 34, 55, 75, -1 },
		/*20*/ { 12, 30, -1, 63 },
		/*21*/ { 12, 63, 75, -1 },
#else
		/* 0*/ { 12, 10, -1, 3  },
		/* 1*/ { 51, 10, -1, 3  },
		/* 2*/ { 12, 3,  75, -1 },
		/* 3*/ { 55, 19, 64, -1 },
		/* 4*/ { 63, 19, -1, 10 },
		/* 5*/ { 63, 10, 75, -1 },
		/* 6*/ { 51, 23, 55, -1 },
		/* 7*/ { 59, 23, 68, -1 },
		/* 8*/ { 67, 23, -1, 17 },
		/* 9*/ { 67, 17, 75, -1 },
		/*10*/ { 55, 27, 72, -1 },
		/*11*/ { 71, 27, -1, 24 },
		/*12*/ { 71, 24, 75, -1 },
		/*13*/ { 49, 31, 75, -1 },
		/*14*/ { 43, 28, -1, 38 },
		/*15*/ { 43, 38, 75, -1 },
		/*16*/ { 30, 35, 37, -1 },
		/*17*/ { 37, 35, -1, 45 },
		/*18*/ { 37, 45, 75, -1 },
		/*19*/ { 34, 52, 75, -1 },
		/*20*/ { 12, 30, -1, 59 },
		/*21*/ { 12, 59, 75, -1 },
#endif
	};

	speed = (s32)(-var80061630 * 4.0f * 50.0f) % 4;
	alpha = alpha >> 1;

	gDPPipeSync(gdl++);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);

	func0f0b39c0(&gdl, &g_TexGeneralConfigs[55], 2, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
			TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);
	gDPSetEnvColorViaWord(gdl++, 0xffffff00 | alpha);

	for (i = firstindex; i <= lastindex; i++) {
		s32 thisspeed = speed;
		s32 tmp;

		if (linecfgs[i].y2 == -1) {
			linecfgs[i].y2 = linecfgs[i].y1 + 1;
		}

		if (linecfgs[i].x2 == -1) {
			linecfgs[i].x2 = linecfgs[i].x1 + 1;
		}

		if (linecfgs[i].x2 == linecfgs[i].x1) {
			linecfgs[i].x2 = linecfgs[i].x1 + 1;
		}

		if (linecfgs[i].y2 == linecfgs[i].y1) {
			linecfgs[i].y2 = linecfgs[i].y1 + 1;
		}

		if (linecfgs[i].x2 < linecfgs[i].x1) {
			tmp = linecfgs[i].x1;
			linecfgs[i].x1 = linecfgs[i].x2;
			linecfgs[i].x2 = tmp;
		}

		if (linecfgs[i].y2 < linecfgs[i].y1) {
			tmp = linecfgs[i].y1;
			linecfgs[i].y1 = linecfgs[i].y2;
			linecfgs[i].y2 = tmp;
		}

		switch (i) {
		case 14:
		case 17:
		case 20:
			thisspeed = -thisspeed;
			break;
		}

		gdl = menuitemControllerRenderLine(gdl, thisspeed,
				linecfgs[i].x1 + context->x + padx, linecfgs[i].y1 + context->y + pady,
				linecfgs[i].x2 + context->x + padx, linecfgs[i].y2 + context->y + pady);
	}

	return gdl;
}
#endif

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

u16 menuitemControllerGetButtonAction(s32 mode, s32 buttonnum)
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
Gfx *menuitemControllerRenderText(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 padx, s32 pady, u32 valuecolour, u32 labelcolour, s8 prevmode)
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
#if VERSION >= VERSION_PAL_BETA
		ry = i * 8 + context->y + pady - 4;
#elif VERSION >= VERSION_NTSC_1_0
		ry = i * 7 + context->y + pady;
#endif

		// For the 2.x styles, only labels 4-7 are shown
		if (curmode < CONTROLMODE_21 || (i >= 4 && i <= 7)) {
			// Rendering a label such as "L/R BUTTONS:"
			rx = context->x + padx + 76;
#if VERSION < VERSION_NTSC_1_0
			ry = i * 7 + context->y + pady;
#endif
			gdl = textRenderProjected(gdl, &rx, &ry, langGet(labels[i]),
					g_CharsHandelGothicXs, g_FontHandelGothicXs, labelcolour, viGetWidth(), viGetHeight(), 0, 0);
		}

		textnum = menuitemControllerGetButtonAction(curmode, i);
		colour = valuecolour;

		// If there's a prevmode, get the text ID that was in this position for
		// prevmode. If it's the same text as curmode, don't fade the text.
		if (prevmode >= 0) {
			// I don't see how curmode can ever be > CONTROLMODE_24. Perhaps
			// during development the second player in the 2.x styles had to
			// choose their control style separately to player 1, in which case
			// there would have been 2.5, 2.6, 2.7 and 2.8 for player 2.
			if (curmode > CONTROLMODE_24) {
				if (textnum == menuitemControllerGetButtonAction(prevmode + 4, i)) {
					colour = labelcolour;
				}
			} else {
				if (textnum == menuitemControllerGetButtonAction(prevmode, i)) {
					colour = labelcolour;
				}
			}
		}

		if (curmode >= CONTROLMODE_21 && i == 2) {
			// Rendering a "CONTROLLER 1" or "CONTROLLER 2" heading
			rx = context->x + padx + 63;
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

Gfx *menuitemControllerRenderPad(Gfx *gdl, struct menurendercontext *context, s32 padx, s32 pady, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode)
{
	s32 rx = context->x + padx;
	s32 ry = context->y + pady + 4;

	// The controller graphic is split into 4 textures
	gdl = menuitemControllerRenderTexture(gdl, rx, ry, 0x33, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx + 32, ry, 0x34, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx, ry + 32, 0x35, alpha);
	gdl = menuitemControllerRenderTexture(gdl, rx + 32, ry + 32, 0x36, alpha);

	if (curmode >= CONTROLMODE_21) {
		gdl = menuitemControllerRenderLines(gdl, context, 13, 19, padx, pady, alpha);
	} else {
		gdl = menuitemControllerRenderLines(gdl, context, 0, 21, padx, pady, alpha);
	}

	return menuitemControllerRenderText(gdl, curmode, context, padx, pady, colour1, colour2, prevmode);
}

Gfx *menuitemControllerRender(Gfx *gdl, struct menurendercontext *context)
{
	struct menuitemdata_controller *data = &context->data->controller;
	u32 colour;
	u32 textcolour;
	s32 x;
	s32 y;
	char text[32];
	struct menudialog *dialog = context->dialog;
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

	if (dialog->transitionfrac < 0) {
		colour = g_MenuColourPalettes[dialog->type].unfocused;
	} else {
		colour = colourBlend(
				g_MenuColourPalettes[dialog->type2].unfocused,
				g_MenuColourPalettes[dialog->type].unfocused,
				dialog->colourweight);
	}

	if (dialog->dimmed) {
		colour = colourBlend(colour, 0, 44) & 0xffffff00 | colour & 0xff;
	}

	func0f153e38(
			g_MenuColourPalettes3[dialog->type].unfocused,
			g_MenuColourPalettes2[dialog->type].unfocused);

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
		gdl = menuitemControllerRenderPad(gdl, context, 0, 12,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);
		gdl = menuitemControllerRenderPad(gdl, context, 0, 80,
				g_Menus[g_MpPlayerNum].main.controlmode + 4,
				contalpha, textcolour, colour, data->prevmode);
	} else {
		gdl = menuitemControllerRenderPad(gdl, context, 0, PAL ? 19 : 15,
				g_Menus[g_MpPlayerNum].main.controlmode,
				contalpha, textcolour, colour, data->prevmode);

		x = context->x;
		y = context->y + 92;

#if VERSION == VERSION_JPN_FINAL
		y += 34;
#endif

		gdl = func0f153628(gdl);
		gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPWEAPONS_216), // "Hold weapon button for ..."
				g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
		gdl = func0f153780(gdl);
	}

	func0f153d3c();

	return gdl;
}

void menuitemControllerInit(union menuitemdata *data)
{
	data->controller.textfadetimer = 0;
	data->controller.contfadetimer = 0;
	data->controller.curmode = 255;
	data->controller.controlgroup = 255;
	data->controller.prevmode = -1;
}

Gfx *menuitemRender(Gfx *gdl, struct menurendercontext *context)
{
	switch (context->item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListRender(gdl, context);
	case MENUITEMTYPE_SELECTABLE:  return menuitemSelectableRender(gdl, context);
	case MENUITEMTYPE_SLIDER:      return menuitemSliderRender(gdl, context);
	case MENUITEMTYPE_CHECKBOX:    return menuitemCheckboxRender(gdl, context);
	case MENUITEMTYPE_SCROLLABLE:  return menuitemScrollableRender(gdl, context);
	case MENUITEMTYPE_MARQUEE:     return menuitemMarqueeRender(gdl, context);
	case MENUITEMTYPE_LABEL:       return menuitemLabelRender(gdl, context);
	case MENUITEMTYPE_METER:       return menuitemMeterRender(gdl, context);
	case MENUITEMTYPE_SEPARATOR:   return menuitemSeparatorRender(gdl, context);
	case MENUITEMTYPE_OBJECTIVES:  return menuitemObjectivesRender(gdl, context);
	case MENUITEMTYPE_07:          return menuitem07Render(gdl);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownRender(gdl, context);
	case MENUITEMTYPE_KEYBOARD:    return menuitemKeyboardRender(gdl, context);
	case MENUITEMTYPE_RANKING:     return menuitemRankingRender(gdl, context);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsRender(gdl, context);
	case MENUITEMTYPE_CAROUSEL:    return menuitemCarouselRender(gdl, context);
	case MENUITEMTYPE_MODEL:       return menuitemModelRender(gdl, context);
	case MENUITEMTYPE_CONTROLLER:  return menuitemControllerRender(gdl, context);
	}

	return gdl;
}

/**
 * Return true if default up/down/left/right/back behaviour should be used.
 */
bool menuitemTick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListTick(item, inputs, tickflags, data);
	case MENUITEMTYPE_SELECTABLE:  return menuitemSelectableTick(item, inputs, tickflags);
	case MENUITEMTYPE_SLIDER:      return menuitemSliderTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_CHECKBOX:    return menuitemCheckboxTick(item, inputs, tickflags);
	case MENUITEMTYPE_SCROLLABLE:  return menuitemScrollableTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_MARQUEE:     return menuitemMarqueeTick(item, data);
	case MENUITEMTYPE_RANKING:     return menuitemRankingTick(inputs, tickflags, data);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownTick(item, dialog, inputs, tickflags, data);
	case MENUITEMTYPE_KEYBOARD:    return menuitemKeyboardTick(item, inputs, tickflags, data);
	case MENUITEMTYPE_CAROUSEL:    return menuitemCarouselTick(item, inputs, tickflags);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsTick(item, dialog, inputs, tickflags, data);
	}

	return true;
}

void menuitemInit(struct menuitem *item, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:
	case MENUITEMTYPE_DROPDOWN:
		menuitemDropdownInit(item, data);
		break;
	case MENUITEMTYPE_SCROLLABLE:
		menuitemScrollableInit(data);
		break;
	case MENUITEMTYPE_MARQUEE:
		menuitemMarqueeInit(data);
		break;
	case MENUITEMTYPE_RANKING:
		menuitemRankingInit(data);
		break;
	case MENUITEMTYPE_SLIDER:
		menuitemSliderInit(data);
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		menuitemPlayerStatsInit(item, data);
		break;
	case MENUITEMTYPE_KEYBOARD:
		menuitemKeyboardInit(item, data);
		break;
	case MENUITEMTYPE_CONTROLLER:
		menuitemControllerInit(data);
		break;
	}
}

Gfx *menuitemOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data)
{
	switch (item->type) {
	case MENUITEMTYPE_LIST:        return menuitemListOverlay(gdl, x, y, x2, y2);
	case MENUITEMTYPE_DROPDOWN:    return menuitemDropdownOverlay(gdl, x, y, x2, y2, item, dialog, data);
	case MENUITEMTYPE_PLAYERSTATS: return menuitemPlayerStatsOverlay(gdl, x, y, x2, y2, item, dialog, data);
	}

	return gdl;
}
