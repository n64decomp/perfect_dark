#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/title.h"
#include "game/game_01afc0.h"
#include "game/game_097ba0.h"
#include "game/game_0b28d0.h"
#include "game/game_0b3350.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/game_1371b0.h"
#include "game/game_141820.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "game/game_1a3340.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_04320.h"
#include "lib/lib_04790.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_317f0.h"
#include "lib/lib_4a5e0.h"
#include "types.h"

s16 var800624a0 = 480;
s32 var800624a4 = false;
u32 var800624a8 = 0x00000000;
u32 var800624ac = 0x00000000;
u32 var800624b0 = 0x00000000;
s32 g_TitleMode = -1;
s32 g_TitleNextMode = -1;
u32 g_TitleDelayedTimer = 2;
s32 g_TitleDelayedMode = -1;
s32 g_TitleTimer = 0;
u32 var800624c8 = 0x00000000;
u32 var800624cc = 0x00000000;
u32 var800624d0 = 0x00000000;
u32 var800624d4 = 0x00000000;
u32 var800624d8 = 0x00000000;
u32 var800624dc = 0x00000000;
u32 var800624e0 = 0x00000000;
s32 g_TitleNextStage = -1;
u32 var800624e8 = 0x00000001;
u32 var800624ec = 0x00000001;
u32 var800624f0 = 0x00000000;
u32 var800624f4 = 0x00000001;
struct model *g_TitleModel = NULL;
struct model *g_TitleModel2 = NULL;
u32 var80062500 = 0x00000000;
u32 var80062504 = 0x00000000;
struct model *var80062508 = NULL;
struct model *var8006250c = NULL;
u32 var80062510 = 0x00000000;
u32 var80062514 = 0x00000000;
u32 var80062518 = 0x96969600;
u32 var8006251c = 0x96969600;
u32 var80062520 = 0xffffff00;
u32 var80062524 = 0xffffff00;
u32 var80062528 = 0x4d4d2e00;
u32 var8006252c = 0x00000000;
u32 var80062530 = 0xffffff00;
u32 var80062534 = 0xffffff00;
u32 var80062538 = 0x00000000;
u32 var8006253c = 0x00000000;
u32 var80062540 = 0x00000000;
u32 var80062544 = 0x00000000;
u32 var80062548 = 0x3fff3f00;
u32 var8006254c = 0x3fff3f00;
u32 var80062550 = 0x00000000;
u32 var80062554 = 0x00000000;
u32 var80062558 = 0x00000000;
u32 var8006255c = 0x00000000;
u32 var80062560 = 0xffffff00;
u32 var80062564 = 0xffffff00;
u32 var80062568 = 0x00000000;
u32 var8006256c = 0x00000000;
u32 var80062570 = 0x00000000;
u32 var80062574 = 0x00000000;
u32 var80062578 = 0x00000000;
u32 var8006257c = 0x00000000;
u32 var80062580 = 0xffffff00;
u32 var80062584 = 0xffffff00;
u32 var80062588 = 0x00007f00;
u32 var8006258c = 0x00000000;
u32 var80062590 = 0xffffff00;
u32 var80062594 = 0xffffff00;
u32 var80062598 = 0x00000000;
u32 var8006259c = 0x00000000;
u32 var800625a0 = 0x00000000;
u32 var800625a4 = 0x00000000;
u32 var800625a8 = 0x00000000;
u32 var800625ac = 0x00000000;
u32 var800625b0 = 0xffffff00;
u32 var800625b4 = 0xffffff00;
u32 var800625b8 = 0x00007f00;
u32 var800625bc = 0x00000000;
u32 var800625c0 = 0x00000000;
u32 var800625c4 = 0x00000000;
u32 var800625c8 = 0xffffff00;
u32 var800625cc = 0xffffff00;
u32 var800625d0 = 0x00007f00;
u32 var800625d4 = 0x00000000;
u32 var800625d8 = 0x00000000;
u32 var800625dc = 0x00000000;
u32 var800625e0 = 0xffffff00;
u32 var800625e4 = 0xffffff00;
u32 var800625e8 = 0x00007f00;
u32 var800625ec = 0x00000000;
u32 var800625f0 = 0x003100b3;
u32 var800625f4 = 0x00010001;
u32 var800625f8 = 0x0002564d;
u32 var800625fc = 0x003100c8;
u32 var80062600 = 0x00010001;
u32 var80062604 = 0x00030000;
u32 var80062608 = 0x004500cf;
u32 var8006260c = 0x00010001;
u32 var80062610 = 0x0002564e;
u32 var80062614 = 0x004500e3;
u32 var80062618 = 0x00010001;
u32 var8006261c = 0x0002564f;
u32 var80062620 = 0x004500f7;
u32 var80062624 = 0x00010001;
u32 var80062628 = 0x00025650;
u32 var8006262c = 0x0045010b;
u32 var80062630 = 0x00010001;
u32 var80062634 = 0x00025651;
u32 var80062638 = 0x00f900cf;
u32 var8006263c = 0x00010001;
u32 var80062640 = 0x00025652;
u32 var80062644 = 0x00f900e3;
u32 var80062648 = 0x00010001;
u32 var8006264c = 0x00025653;
u32 var80062650 = 0x00f900f7;
u32 var80062654 = 0x00010001;
u32 var80062658 = 0x00025654;
u32 var8006265c = 0x00f9010b;
u32 var80062660 = 0x00010001;
u32 var80062664 = 0x00025655;
u32 var80062668 = 0x00450122;
u32 var8006266c = 0x00010001;
u32 var80062670 = 0x00030000;
u32 var80062674 = 0x0045012b;
u32 var80062678 = 0x00000001;
u32 var8006267c = 0x0005564c;
u32 var80062680 = 0x010a0128;
u32 var80062684 = 0x00000001;
u32 var80062688 = 0x0006564b;
u32 var8006268c = 0x011e012b;
u32 var80062690 = 0x00000001;
u32 var80062694 = 0x0005564a;
u32 var80062698 = 0x00450140;
u32 var8006269c = 0x00010001;
u32 var800626a0 = 0x00030000;
u32 var800626a4 = 0x00450148;
u32 var800626a8 = 0x00000001;
u32 var800626ac = 0x00015657;
u32 var800626b0 = 0x008a0157;
u32 var800626b4 = 0x00000001;
u32 var800626b8 = 0x00015658;
u32 var800626bc = 0x00450174;
u32 var800626c0 = 0x00000001;
u32 var800626c4 = 0x00015659;
u32 var800626c8 = 0x004501ac;
u32 var800626cc = 0x00010001;
u32 var800626d0 = 0x00030000;
u32 var800626d4 = 0x004501b1;
u32 var800626d8 = 0x00000001;
u32 var800626dc = 0x0000565d;
u32 var800626e0 = 0x00450158;
u32 var800626e4 = 0x00000001;
u32 var800626e8 = 0x00040000;
u32 var800626ec = 0x00000000;
u32 var800626f0 = 0x00000001;
u32 var800626f4 = 0x00000003;
u32 var800626f8 = 0x00000000;
u32 var800626fc = 0x00000000;
u32 var80062700 = 0x00000000;
u32 var80062704 = 0x00000000;
u32 var80062708 = 0x00000000;
u32 var8006270c = 0x00000000;
u32 var80062710 = 0x00000000;
u32 var80062714 = 0x00000000;
u32 var80062718 = 0x00000000;
u32 var8006271c = 0x00000000;
u32 var80062720 = 0x00000000;
u32 var80062724 = 0x00000000;
u32 var80062728 = 0x00000000;
u32 var8006272c = 0x00000001;
u32 var80062730 = 0x00000001;
u32 var80062734 = 0x00000000;

char *mpPlayerGetWeaponOfChoiceName(u32 playernum, u32 slot)
{
	char *name;
	s32 weapon1;
	s32 weapon2;
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 weapon;

	setCurrentPlayerNum(playernum);

	currentPlayerGetWeaponOfChoice(&weapon1, &weapon2);

	weapon = slot == 1 ? weapon2 : weapon1;

	name = weaponGetName(weapon);
	setCurrentPlayerNum(prevplayernum);

	return name;
}

GLOBAL_ASM(
glabel func0f01616c
/*  f01616c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f016170:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f016174:	01c02825 */ 	or	$a1,$t6,$zero
/*  f016178:	44852000 */ 	mtc1	$a1,$f4
/*  f01617c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f016180:	30cf00ff */ 	andi	$t7,$a2,0xff
/*  f016184:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f016188:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f01618c:	03003825 */ 	or	$a3,$t8,$zero
/*  f016190:	01e03025 */ 	or	$a2,$t7,$zero
/*  f016194:	c7ac0010 */ 	lwc1	$f12,0x10($sp)
/*  f016198:	05c10005 */ 	bgez	$t6,.L0f0161b0
/*  f01619c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0161a0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0161a4:	44814000 */ 	mtc1	$at,$f8
/*  f0161a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0161ac:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0161b0:
/*  f0161b0:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0161b4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0161b8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0161bc:	4459f800 */ 	cfc1	$t9,$31
/*  f0161c0:	44c2f800 */ 	ctc1	$v0,$31
/*  f0161c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0161c8:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0161cc:	4442f800 */ 	cfc1	$v0,$31
/*  f0161d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0161d4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0161d8:	50400013 */ 	beqzl	$v0,.L0f016228
/*  f0161dc:	44028000 */ 	mfc1	$v0,$f16
/*  f0161e0:	44818000 */ 	mtc1	$at,$f16
/*  f0161e4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0161e8:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0161ec:	44c2f800 */ 	ctc1	$v0,$31
/*  f0161f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0161f4:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0161f8:	4442f800 */ 	cfc1	$v0,$31
/*  f0161fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016200:	30420078 */ 	andi	$v0,$v0,0x78
/*  f016204:	14400005 */ 	bnez	$v0,.L0f01621c
/*  f016208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01620c:	44028000 */ 	mfc1	$v0,$f16
/*  f016210:	3c018000 */ 	lui	$at,0x8000
/*  f016214:	10000007 */ 	beqz	$zero,.L0f016234
/*  f016218:	00411025 */ 	or	$v0,$v0,$at
.L0f01621c:
/*  f01621c:	10000005 */ 	beqz	$zero,.L0f016234
/*  f016220:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f016224:	44028000 */ 	mfc1	$v0,$f16
.L0f016228:
/*  f016228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01622c:	0440fffb */ 	bltz	$v0,.L0f01621c
/*  f016230:	00000000 */ 	sll	$zero,$zero,0x0
.L0f016234:
/*  f016234:	44d9f800 */ 	ctc1	$t9,$31
/*  f016238:	44869000 */ 	mtc1	$a2,$f18
/*  f01623c:	a0820000 */ 	sb	$v0,0x0($a0)
/*  f016240:	04c10005 */ 	bgez	$a2,.L0f016258
/*  f016244:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f016248:	3c014f80 */ 	lui	$at,0x4f80
/*  f01624c:	44814000 */ 	mtc1	$at,$f8
/*  f016250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016254:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f016258:
/*  f016258:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f01625c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f016260:	3c014f00 */ 	lui	$at,0x4f00
/*  f016264:	4449f800 */ 	cfc1	$t1,$31
/*  f016268:	44c3f800 */ 	ctc1	$v1,$31
/*  f01626c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016270:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f016274:	4443f800 */ 	cfc1	$v1,$31
/*  f016278:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01627c:	30630078 */ 	andi	$v1,$v1,0x78
/*  f016280:	50600013 */ 	beqzl	$v1,.L0f0162d0
/*  f016284:	44035000 */ 	mfc1	$v1,$f10
/*  f016288:	44815000 */ 	mtc1	$at,$f10
/*  f01628c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f016290:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f016294:	44c3f800 */ 	ctc1	$v1,$31
/*  f016298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01629c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0162a0:	4443f800 */ 	cfc1	$v1,$31
/*  f0162a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0162a8:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0162ac:	14600005 */ 	bnez	$v1,.L0f0162c4
/*  f0162b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0162b4:	44035000 */ 	mfc1	$v1,$f10
/*  f0162b8:	3c018000 */ 	lui	$at,0x8000
/*  f0162bc:	10000007 */ 	beqz	$zero,.L0f0162dc
/*  f0162c0:	00611825 */ 	or	$v1,$v1,$at
.L0f0162c4:
/*  f0162c4:	10000005 */ 	beqz	$zero,.L0f0162dc
/*  f0162c8:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0162cc:	44035000 */ 	mfc1	$v1,$f10
.L0f0162d0:
/*  f0162d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0162d4:	0460fffb */ 	bltz	$v1,.L0f0162c4
/*  f0162d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0162dc:
/*  f0162dc:	44c9f800 */ 	ctc1	$t1,$31
/*  f0162e0:	44878000 */ 	mtc1	$a3,$f16
/*  f0162e4:	a0830001 */ 	sb	$v1,0x1($a0)
/*  f0162e8:	04e10005 */ 	bgez	$a3,.L0f016300
/*  f0162ec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0162f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0162f4:	44814000 */ 	mtc1	$at,$f8
/*  f0162f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0162fc:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f016300:
/*  f016300:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f016304:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f016308:	3c014f00 */ 	lui	$at,0x4f00
/*  f01630c:	444af800 */ 	cfc1	$t2,$31
/*  f016310:	44c8f800 */ 	ctc1	$t0,$31
/*  f016314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016318:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f01631c:	4448f800 */ 	cfc1	$t0,$31
/*  f016320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016324:	31080078 */ 	andi	$t0,$t0,0x78
/*  f016328:	51000013 */ 	beqzl	$t0,.L0f016378
/*  f01632c:	44083000 */ 	mfc1	$t0,$f6
/*  f016330:	44813000 */ 	mtc1	$at,$f6
/*  f016334:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f016338:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f01633c:	44c8f800 */ 	ctc1	$t0,$31
/*  f016340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016344:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f016348:	4448f800 */ 	cfc1	$t0,$31
/*  f01634c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016350:	31080078 */ 	andi	$t0,$t0,0x78
/*  f016354:	15000005 */ 	bnez	$t0,.L0f01636c
/*  f016358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01635c:	44083000 */ 	mfc1	$t0,$f6
/*  f016360:	3c018000 */ 	lui	$at,0x8000
/*  f016364:	10000007 */ 	beqz	$zero,.L0f016384
/*  f016368:	01014025 */ 	or	$t0,$t0,$at
.L0f01636c:
/*  f01636c:	10000005 */ 	beqz	$zero,.L0f016384
/*  f016370:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f016374:	44083000 */ 	mfc1	$t0,$f6
.L0f016378:
/*  f016378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01637c:	0500fffb */ 	bltz	$t0,.L0f01636c
/*  f016380:	00000000 */ 	sll	$zero,$zero,0x0
.L0f016384:
/*  f016384:	a0880002 */ 	sb	$t0,0x2($a0)
/*  f016388:	a0820004 */ 	sb	$v0,0x4($a0)
/*  f01638c:	a0830005 */ 	sb	$v1,0x5($a0)
/*  f016390:	a0880006 */ 	sb	$t0,0x6($a0)
/*  f016394:	a0850008 */ 	sb	$a1,0x8($a0)
/*  f016398:	8fa20014 */ 	lw	$v0,0x14($sp)
/*  f01639c:	3c0142fe */ 	lui	$at,0x42fe
/*  f0163a0:	a0860009 */ 	sb	$a2,0x9($a0)
/*  f0163a4:	a087000a */ 	sb	$a3,0xa($a0)
/*  f0163a8:	a085000c */ 	sb	$a1,0xc($a0)
/*  f0163ac:	a086000d */ 	sb	$a2,0xd($a0)
/*  f0163b0:	a087000e */ 	sb	$a3,0xe($a0)
/*  f0163b4:	44caf800 */ 	ctc1	$t2,$31
/*  f0163b8:	44810000 */ 	mtc1	$at,$f0
/*  f0163bc:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0163c0:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0163c4:	4600820d */ 	trunc.w.s	$f8,$f16
/*  f0163c8:	440c4000 */ 	mfc1	$t4,$f8
/*  f0163cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0163d0:	a08c0010 */ 	sb	$t4,0x10($a0)
/*  f0163d4:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f0163d8:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0163dc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0163e0:	440e3000 */ 	mfc1	$t6,$f6
/*  f0163e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0163e8:	a08e0011 */ 	sb	$t6,0x11($a0)
/*  f0163ec:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0163f0:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0163f4:	4600820d */ 	trunc.w.s	$f8,$f16
/*  f0163f8:	44184000 */ 	mfc1	$t8,$f8
/*  f0163fc:	03e00008 */ 	jr	$ra
/*  f016400:	a0980012 */ 	sb	$t8,0x12($a0)
);

void titleInitLegal(void)
{
	func0f16d3d0();
	var800624f4 = 1;
	g_TitleTimer = 0;
	var800624a8 = 0;
	var800624ac = 0;
}

void titleExitLegal(void)
{
	// empty
}

void titleTickLegal(void)
{
	func0000bd30(60);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(false);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (g_TitleTimer > 180) {
		titleSetNextMode(TITLEMODE_CHECKCONTROLLERS);
	}
}

void titleInitCheckControllers(void)
{
	g_TitleTimer = 0;
	func00009ec4(true);
}

void titleExitCheckControllers(void)
{
	var800624e8 = 0;
	func00009ab0();
	func0000aab0(2);
	func00009ec4(false);
}

void titleTickCheckControllers(void)
{
	g_TitleTimer++;
	func0000be84(100, 10000);
	func0000bd20(0);

	if (g_TitleTimer > 6) {
		if ((getConnectedControllers() & 1) == 0) {
			titleSetNextMode(TITLEMODE_NOCONTROLLER);
		} else {
			titleSetNextMode(TITLEMODE_RARELOGO);
		}
	}
}

Gfx *titleRenderCheckControllers(Gfx *gdl)
{
	if (g_TitleTimer > 2 && g_TitleTimer < 6) {
		gdl = func0f01afc0(gdl);
	}

	return gdl;
}

GLOBAL_ASM(
glabel func0f0165f0
/*  f0165f0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0165f4:	3c0e8008 */ 	lui	$t6,%hi(var8007fb1c)
/*  f0165f8:	8dcefb1c */ 	lw	$t6,%lo(var8007fb1c)($t6)
/*  f0165fc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f016600:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f016604:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f016608:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f01660c:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f016610:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f016614:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f016618:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f01661c:	8ce7fb20 */ 	lw	$a3,%lo(var8007fb20)($a3)
/*  f016620:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f016624:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f016628:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f01662c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f016630:	0fc55cbe */ 	jal	textMeasure
/*  f016634:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f016638:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f01663c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f016640:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f016644:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f016648:	01f80019 */ 	multu	$t7,$t8
/*  f01664c:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f016650:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f016654:	0000c812 */ 	mflo	$t9
/*  f016658:	07210003 */ 	bgez	$t9,.L0f016668
/*  f01665c:	00194043 */ 	sra	$t0,$t9,0x1
/*  f016660:	27210001 */ 	addiu	$at,$t9,0x1
/*  f016664:	00014043 */ 	sra	$t0,$at,0x1
.L0f016668:
/*  f016668:	016c0019 */ 	multu	$t3,$t4
/*  f01666c:	01285023 */ 	subu	$t2,$t1,$t0
/*  f016670:	afaa0044 */ 	sw	$t2,0x44($sp)
/*  f016674:	00006812 */ 	mflo	$t5
/*  f016678:	05a10003 */ 	bgez	$t5,.L0f016688
/*  f01667c:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f016680:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f016684:	00017043 */ 	sra	$t6,$at,0x1
.L0f016688:
/*  f016688:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f01668c:	0c002f02 */ 	jal	func0000bc08
/*  f016690:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f016694:	0c002f06 */ 	jal	func0000bc18
/*  f016698:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f01669c:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0166a0:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*  f0166a4:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0166a8:	87aa003c */ 	lh	$t2,0x3c($sp)
/*  f0166ac:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0166b0:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0166b4:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0166b8:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0166bc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0166c0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0166c4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0166c8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0166cc:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0166d0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0166d4:	0fc5580f */ 	jal	textRenderWhite
/*  f0166d8:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0166dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0166e0:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0166e4:	03e00008 */ 	jr	$ra
/*  f0166e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel titleRenderLegal
.late_rodata
glabel var7f1a83cc
.word titleRenderLegal+0xec # f0167d8
glabel var7f1a83d0
.word titleRenderLegal+0xfc # f0167e8
glabel var7f1a83d4
.word titleRenderLegal+0x110 # f0167fc
glabel var7f1a83d8
.word titleRenderLegal+0x180 # f01686c
glabel var7f1a83dc
.word titleRenderLegal+0x180 # f01686c
glabel var7f1a83e0
.word titleRenderLegal+0x11c # f016808
glabel var7f1a83e4
.word titleRenderLegal+0x16c # f016858
.text
/*  f0166ec:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f0166f0:	3c0f8006 */ 	lui	$t7,%hi(var800626ec)
/*  f0166f4:	25ef26ec */ 	addiu	$t7,$t7,%lo(var800626ec)
/*  f0166f8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f0166fc:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f016700:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f016704:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f016708:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f01670c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f016710:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f016714:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f016718:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f01671c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f016720:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f016724:	25eb003c */ 	addiu	$t3,$t7,0x3c
/*  f016728:	27ae00e0 */ 	addiu	$t6,$sp,0xe0
.L0f01672c:
/*  f01672c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016730:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f016734:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f016738:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f01673c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f016740:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f016744:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f016748:	15ebfff8 */ 	bne	$t7,$t3,.L0f01672c
/*  f01674c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f016750:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016754:	3c0c8006 */ 	lui	$t4,%hi(var8006272c)
/*  f016758:	adc10000 */ 	sw	$at,0x0($t6)
/*  f01675c:	8d8c272c */ 	lw	$t4,%lo(var8006272c)($t4)
/*  f016760:	51800168 */ 	beqzl	$t4,.L0f016d04
/*  f016764:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f016768:	0fc06bf0 */ 	jal	func0f01afc0
/*  f01676c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016770:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016774:	0fc54d8a */ 	jal	func0f153628
/*  f016778:	00402025 */ 	or	$a0,$v0,$zero
/*  f01677c:	3c0d8006 */ 	lui	$t5,%hi(var800626ec)
/*  f016780:	3c108006 */ 	lui	$s0,%hi(var800625f0)
/*  f016784:	25ad26ec */ 	addiu	$t5,$t5,%lo(var800626ec)
/*  f016788:	3c1e8008 */ 	lui	$s8,%hi(var8007fb10)
/*  f01678c:	3c178008 */ 	lui	$s7,%hi(var8007fb1c)
/*  f016790:	3c168008 */ 	lui	$s6,%hi(var8007fb20)
/*  f016794:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016798:	261025f0 */ 	addiu	$s0,$s0,%lo(var800625f0)
/*  f01679c:	afad0120 */ 	sw	$t5,0x120($sp)
/*  f0167a0:	26d6fb20 */ 	addiu	$s6,$s6,%lo(var8007fb20)
/*  f0167a4:	26f7fb1c */ 	addiu	$s7,$s7,%lo(var8007fb1c)
/*  f0167a8:	27defb10 */ 	addiu	$s8,$s8,%lo(var8007fb10)
/*  f0167ac:	86030008 */ 	lh	$v1,0x8($s0)
.L0f0167b0:
/*  f0167b0:	3c157f7f */ 	lui	$s5,0x7f7f
/*  f0167b4:	36b5ffff */ 	ori	$s5,$s5,0xffff
/*  f0167b8:	2c610007 */ 	sltiu	$at,$v1,0x7
/*  f0167bc:	1020002b */ 	beqz	$at,.L0f01686c
/*  f0167c0:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0167c4:	3c017f1b */ 	lui	$at,%hi(var7f1a83cc)
/*  f0167c8:	00390821 */ 	addu	$at,$at,$t9
/*  f0167cc:	8c3983cc */ 	lw	$t9,%lo(var7f1a83cc)($at)
/*  f0167d0:	03200008 */ 	jr	$t9
/*  f0167d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0167d8:	3c128008 */ 	lui	$s2,%hi(var8007fb0c)
/*  f0167dc:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f0167e0:	10000024 */ 	beqz	$zero,.L0f016874
/*  f0167e4:	8e52fb0c */ 	lw	$s2,%lo(var8007fb0c)($s2)
/*  f0167e8:	3c118008 */ 	lui	$s1,%hi(var8007fb18)
/*  f0167ec:	3c128008 */ 	lui	$s2,%hi(var8007fb14)
/*  f0167f0:	8e31fb18 */ 	lw	$s1,%lo(var8007fb18)($s1)
/*  f0167f4:	1000001f */ 	beqz	$zero,.L0f016874
/*  f0167f8:	8e52fb14 */ 	lw	$s2,%lo(var8007fb14)($s2)
/*  f0167fc:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f016800:	1000001c */ 	beqz	$zero,.L0f016874
/*  f016804:	8ef20000 */ 	lw	$s2,0x0($s7)
/*  f016808:	9602000a */ 	lhu	$v0,0xa($s0)
/*  f01680c:	2401564a */ 	addiu	$at,$zero,0x564a
/*  f016810:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f016814:	8ef20000 */ 	lw	$s2,0x0($s7)
/*  f016818:	10410003 */ 	beq	$v0,$at,.L0f016828
/*  f01681c:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f016820:	24015649 */ 	addiu	$at,$zero,0x5649
/*  f016824:	14410013 */ 	bne	$v0,$at,.L0f016874
.L0f016828:
/*  f016828:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f01682c:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f016830:	24010001 */ 	addiu	$at,$zero,0x1
/*  f016834:	240b564a */ 	addiu	$t3,$zero,0x564a
/*  f016838:	17010004 */ 	bne	$t8,$at,.L0f01684c
/*  f01683c:	240f5649 */ 	addiu	$t7,$zero,0x5649
/*  f016840:	a60b000a */ 	sh	$t3,0xa($s0)
/*  f016844:	1000000b */ 	beqz	$zero,.L0f016874
/*  f016848:	86030008 */ 	lh	$v1,0x8($s0)
.L0f01684c:
/*  f01684c:	a60f000a */ 	sh	$t7,0xa($s0)
/*  f016850:	10000008 */ 	beqz	$zero,.L0f016874
/*  f016854:	86030008 */ 	lh	$v1,0x8($s0)
/*  f016858:	3c128008 */ 	lui	$s2,%hi(var8007fb0c)
/*  f01685c:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f016860:	8e52fb0c */ 	lw	$s2,%lo(var8007fb0c)($s2)
/*  f016864:	10000003 */ 	beqz	$zero,.L0f016874
/*  f016868:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f01686c:
/*  f01686c:	8ed10000 */ 	lw	$s1,0x0($s6)
/*  f016870:	8ef20000 */ 	lw	$s2,0x0($s7)
.L0f016874:
/*  f016874:	24010003 */ 	addiu	$at,$zero,0x3
/*  f016878:	54610015 */ 	bnel	$v1,$at,.L0f0168d0
/*  f01687c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f016880:	0fc54de0 */ 	jal	func0f153780
/*  f016884:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016888:	0c002f02 */ 	jal	func0000bc08
/*  f01688c:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016890:	86060002 */ 	lh	$a2,0x2($s0)
/*  f016894:	3c0c7f7f */ 	lui	$t4,0x7f7f
/*  f016898:	358cff7f */ 	ori	$t4,$t4,0xff7f
/*  f01689c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f0168a0:	24ce0002 */ 	addiu	$t6,$a2,0x2
/*  f0168a4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0168a8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0168ac:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0168b0:	0fc54e8d */ 	jal	func0f153a34
/*  f0168b4:	00403825 */ 	or	$a3,$v0,$zero
/*  f0168b8:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f0168bc:	0fc54d8a */ 	jal	func0f153628
/*  f0168c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0168c4:	10000106 */ 	beqz	$zero,.L0f016ce0
/*  f0168c8:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f0168cc:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0168d0:
/*  f0168d0:	54610075 */ 	bnel	$v1,$at,.L0f016aa8
/*  f0168d4:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0168d8:	0fc54de0 */ 	jal	func0f153780
/*  f0168dc:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f0168e0:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f0168e4:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f0168e8:	3c19e700 */ 	lui	$t9,0xe700
/*  f0168ec:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0168f0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0168f4:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0168f8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0168fc:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016900:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f016904:	afab0128 */ 	sw	$t3,0x128($sp)
/*  f016908:	af000004 */ 	sw	$zero,0x4($t8)
/*  f01690c:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f016910:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f016914:	3c0db900 */ 	lui	$t5,0xb900
/*  f016918:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f01691c:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f016920:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f016924:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f016928:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f01692c:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f016930:	3c0bba00 */ 	lui	$t3,0xba00
/*  f016934:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f016938:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f01693c:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f016940:	af200004 */ 	sw	$zero,0x4($t9)
/*  f016944:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f016948:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f01694c:	3c0cba00 */ 	lui	$t4,0xba00
/*  f016950:	358c0903 */ 	ori	$t4,$t4,0x903
/*  f016954:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f016958:	afae0128 */ 	sw	$t6,0x128($sp)
/*  f01695c:	240d0c00 */ 	addiu	$t5,$zero,0xc00
/*  f016960:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f016964:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f016968:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f01696c:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f016970:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f016974:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f016978:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f01697c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f016980:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f016984:	27a40128 */ 	addiu	$a0,$sp,0x128
/*  f016988:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f01698c:	00003825 */ 	or	$a3,$zero,$zero
/*  f016990:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f016994:	24a50234 */ 	addiu	$a1,$a1,0x0234
/*  f016998:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f01699c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0169a0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0169a4:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f0169a8:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f0169ac:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0169b0:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0169b4:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f0169b8:	3c19fcff */ 	lui	$t9,0xfcff
/*  f0169bc:	3c18fffc */ 	lui	$t8,0xfffc
/*  f0169c0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0169c4:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f0169c8:	3718f279 */ 	ori	$t8,$t8,0xf279
/*  f0169cc:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0169d0:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0169d4:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f0169d8:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f0169dc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0169e0:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f0169e4:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f0169e8:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f0169ec:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0169f0:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0169f4:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f0169f8:	3c01e400 */ 	lui	$at,0xe400
/*  f0169fc:	24ad0008 */ 	addiu	$t5,$a1,0x8
/*  f016a00:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f016a04:	86190000 */ 	lh	$t9,0x0($s0)
/*  f016a08:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f016a0c:	27380040 */ 	addiu	$t8,$t9,0x40
/*  f016a10:	00185880 */ 	sll	$t3,$t8,0x2
/*  f016a14:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016a18:	25b90018 */ 	addiu	$t9,$t5,0x18
/*  f016a1c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f016a20:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016a24:	01c16025 */ 	or	$t4,$t6,$at
/*  f016a28:	330b0fff */ 	andi	$t3,$t8,0xfff
/*  f016a2c:	018b7825 */ 	or	$t7,$t4,$t3
/*  f016a30:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016a34:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f016a38:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f016a3c:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f016a40:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f016a44:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016a48:	316f0fff */ 	andi	$t7,$t3,0xfff
/*  f016a4c:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f016a50:	030f7025 */ 	or	$t6,$t8,$t7
/*  f016a54:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016a58:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f016a5c:	240b0300 */ 	addiu	$t3,$zero,0x300
/*  f016a60:	3c0cb400 */ 	lui	$t4,0xb400
/*  f016a64:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016a68:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016a6c:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016a70:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016a74:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016a78:	3c0d0400 */ 	lui	$t5,0x400
/*  f016a7c:	35adfc00 */ 	ori	$t5,$t5,0xfc00
/*  f016a80:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016a84:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016a88:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016a8c:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016a90:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f016a94:	0fc54d8a */ 	jal	func0f153628
/*  f016a98:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016a9c:	10000090 */ 	beqz	$zero,.L0f016ce0
/*  f016aa0:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016aa4:	24010007 */ 	addiu	$at,$zero,0x7
.L0f016aa8:
/*  f016aa8:	54610075 */ 	bnel	$v1,$at,.L0f016c80
/*  f016aac:	860c0000 */ 	lh	$t4,0x0($s0)
/*  f016ab0:	0fc54de0 */ 	jal	func0f153780
/*  f016ab4:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016ab8:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f016abc:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016ac0:	3c0ce700 */ 	lui	$t4,0xe700
/*  f016ac4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f016ac8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f016acc:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016ad0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f016ad4:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f016ad8:	25780008 */ 	addiu	$t8,$t3,0x8
/*  f016adc:	afb80128 */ 	sw	$t8,0x128($sp)
/*  f016ae0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f016ae4:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f016ae8:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f016aec:	3c19b900 */ 	lui	$t9,0xb900
/*  f016af0:	37390002 */ 	ori	$t9,$t9,0x2
/*  f016af4:	25cd0008 */ 	addiu	$t5,$t6,0x8
/*  f016af8:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f016afc:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f016b00:	add90000 */ 	sw	$t9,0x0($t6)
/*  f016b04:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f016b08:	3c18ba00 */ 	lui	$t8,0xba00
/*  f016b0c:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f016b10:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f016b14:	afab0128 */ 	sw	$t3,0x128($sp)
/*  f016b18:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f016b1c:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f016b20:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f016b24:	3c0dba00 */ 	lui	$t5,0xba00
/*  f016b28:	35ad0903 */ 	ori	$t5,$t5,0x903
/*  f016b2c:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f016b30:	afae0128 */ 	sw	$t6,0x128($sp)
/*  f016b34:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f016b38:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f016b3c:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f016b40:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f016b44:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f016b48:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f016b4c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f016b50:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f016b54:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f016b58:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f016b5c:	27a40128 */ 	addiu	$a0,$sp,0x128
/*  f016b60:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f016b64:	00003825 */ 	or	$a3,$zero,$zero
/*  f016b68:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f016b6c:	24a5024c */ 	addiu	$a1,$a1,0x024c
/*  f016b70:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016b74:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016b78:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f016b7c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016b80:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016b84:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016b88:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016b8c:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f016b90:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f016b94:	3c0bfffc */ 	lui	$t3,0xfffc
/*  f016b98:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f016b9c:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016ba0:	356bf279 */ 	ori	$t3,$t3,0xf279
/*  f016ba4:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f016ba8:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f016bac:	adab0004 */ 	sw	$t3,0x4($t5)
/*  f016bb0:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f016bb4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f016bb8:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f016bbc:	270f0008 */ 	addiu	$t7,$t8,0x8
/*  f016bc0:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016bc4:	af000004 */ 	sw	$zero,0x4($t8)
/*  f016bc8:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f016bcc:	8fa50128 */ 	lw	$a1,0x128($sp)
/*  f016bd0:	3c01e400 */ 	lui	$at,0xe400
/*  f016bd4:	24b90008 */ 	addiu	$t9,$a1,0x8
/*  f016bd8:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f016bdc:	860c0000 */ 	lh	$t4,0x0($s0)
/*  f016be0:	86190002 */ 	lh	$t9,0x2($s0)
/*  f016be4:	258b0020 */ 	addiu	$t3,$t4,0x20
/*  f016be8:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f016bec:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016bf0:	272c002a */ 	addiu	$t4,$t9,0x2a
/*  f016bf4:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f016bf8:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f016bfc:	01c16825 */ 	or	$t5,$t6,$at
/*  f016c00:	31780fff */ 	andi	$t8,$t3,0xfff
/*  f016c04:	01b87825 */ 	or	$t7,$t5,$t8
/*  f016c08:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f016c0c:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f016c10:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f016c14:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f016c18:	332c0fff */ 	andi	$t4,$t9,0xfff
/*  f016c1c:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f016c20:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f016c24:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f016c28:	016f7025 */ 	or	$t6,$t3,$t7
/*  f016c2c:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f016c30:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f016c34:	24180540 */ 	addiu	$t8,$zero,0x540
/*  f016c38:	3c0db400 */ 	lui	$t5,0xb400
/*  f016c3c:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f016c40:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f016c44:	af380004 */ 	sw	$t8,0x4($t9)
/*  f016c48:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f016c4c:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f016c50:	3c190400 */ 	lui	$t9,0x400
/*  f016c54:	3739fc00 */ 	ori	$t9,$t9,0xfc00
/*  f016c58:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f016c5c:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f016c60:	3c0eb300 */ 	lui	$t6,0xb300
/*  f016c64:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f016c68:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f016c6c:	0fc54d8a */ 	jal	func0f153628
/*  f016c70:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016c74:	1000001a */ 	beqz	$zero,.L0f016ce0
/*  f016c78:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016c7c:	860c0000 */ 	lh	$t4,0x0($s0)
.L0f016c80:
/*  f016c80:	afac00dc */ 	sw	$t4,0xdc($sp)
/*  f016c84:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f016c88:	afad00d8 */ 	sw	$t5,0xd8($sp)
/*  f016c8c:	0fc5b9f1 */ 	jal	langGet
/*  f016c90:	9604000a */ 	lhu	$a0,0xa($s0)
/*  f016c94:	0c002f02 */ 	jal	func0000bc08
/*  f016c98:	00409825 */ 	or	$s3,$v0,$zero
/*  f016c9c:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f016ca0:	0014c403 */ 	sra	$t8,$s4,0x10
/*  f016ca4:	0c002f06 */ 	jal	func0000bc18
/*  f016ca8:	0300a025 */ 	or	$s4,$t8,$zero
/*  f016cac:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016cb0:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f016cb4:	27a600d8 */ 	addiu	$a2,$sp,0xd8
/*  f016cb8:	02603825 */ 	or	$a3,$s3,$zero
/*  f016cbc:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f016cc0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f016cc4:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f016cc8:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f016ccc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f016cd0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f016cd4:	0fc5580f */ 	jal	textRenderWhite
/*  f016cd8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f016cdc:	afa20128 */ 	sw	$v0,0x128($sp)
.L0f016ce0:
/*  f016ce0:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f016ce4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f016ce8:	020b082b */ 	sltu	$at,$s0,$t3
/*  f016cec:	5420feb0 */ 	bnezl	$at,.L0f0167b0
/*  f016cf0:	86030008 */ 	lh	$v1,0x8($s0)
/*  f016cf4:	0fc54de0 */ 	jal	func0f153780
/*  f016cf8:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f016cfc:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f016d00:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f016d04:
/*  f016d04:	8fa20128 */ 	lw	$v0,0x128($sp)
/*  f016d08:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f016d0c:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f016d10:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f016d14:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f016d18:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f016d1c:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f016d20:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f016d24:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f016d28:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f016d2c:	03e00008 */ 	jr	$ra
/*  f016d30:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

u32 var80062738 = 0;
u32 var8006273c = 0;
u32 var80062740 = 0;
u32 var80062744 = 0;
u32 var80062748 = 0;
u32 var8006274c = 0;
u32 var80062750 = 0;
u32 var80062754 = 0;
u32 var80062758 = 0;
u32 var8006275c = 0;
u32 var80062760 = 0;
u32 var80062764 = 0;

GLOBAL_ASM(
glabel titleInitPdLogo
/*  f016d34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f016d38:	3c018006 */ 	lui	$at,%hi(g_TitleTimer)
/*  f016d3c:	3c0f8006 */ 	lui	$t7,%hi(var80062738)
/*  f016d40:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f016d44:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f016d48:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016d4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f016d50:	ac2024c4 */ 	sw	$zero,%lo(g_TitleTimer)($at)
/*  f016d54:	25ef2738 */ 	addiu	$t7,$t7,%lo(var80062738)
/*  f016d58:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016d5c:	3c10800a */ 	lui	$s0,%hi(var8009cca0)
/*  f016d60:	8e10cca0 */ 	lw	$s0,%lo(var8009cca0)($s0)
/*  f016d64:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f016d68:	adc10000 */ 	sw	$at,0x0($t6)
/*  f016d6c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f016d70:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f016d74:	3c118008 */ 	lui	$s1,%hi(g_Props)
/*  f016d78:	2631b06c */ 	addiu	$s1,$s1,%lo(g_Props)
/*  f016d7c:	3c060004 */ 	lui	$a2,0x4
/*  f016d80:	adc10008 */ 	sw	$at,0x8($t6)
/*  f016d84:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f016d88:	96240244 */ 	lhu	$a0,0x244($s1)
/*  f016d8c:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f016d90:	00003825 */ 	or	$a3,$zero,$zero
/*  f016d94:	0fc69de5 */ 	jal	func0f1a7794
/*  f016d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f016d9c:	ae220240 */ 	sw	$v0,0x240($s1)
/*  f016da0:	0fc59ca0 */ 	jal	fileGetSize
/*  f016da4:	96240244 */ 	lhu	$a0,0x244($s1)
/*  f016da8:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016dac:	3469003f */ 	ori	$t1,$v1,0x3f
/*  f016db0:	3c0b0004 */ 	lui	$t3,0x4
/*  f016db4:	392a003f */ 	xori	$t2,$t1,0x3f
/*  f016db8:	356b7800 */ 	ori	$t3,$t3,0x7800
/*  f016dbc:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f016dc0:	016a9023 */ 	subu	$s2,$t3,$t2
/*  f016dc4:	0c008b49 */ 	jal	func00022d24
/*  f016dc8:	8e240240 */ 	lw	$a0,0x240($s1)
/*  f016dcc:	0fc2cca0 */ 	jal	func0f0b3280
/*  f016dd0:	8e240240 */ 	lw	$a0,0x240($s1)
/*  f016dd4:	3c038006 */ 	lui	$v1,%hi(g_TitleModel)
/*  f016dd8:	246324f8 */ 	addiu	$v1,$v1,%lo(g_TitleModel)
/*  f016ddc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016de0:	00402025 */ 	or	$a0,$v0,$zero
/*  f016de4:	0c006bd6 */ 	jal	func0001af58
/*  f016de8:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016dec:	3c048006 */ 	lui	$a0,%hi(g_TitleModel)
/*  f016df0:	8c8424f8 */ 	lw	$a0,%lo(g_TitleModel)($a0)
/*  f016df4:	0c006b4d */ 	jal	func0001ad34
/*  f016df8:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f016dfc:	3c0d8006 */ 	lui	$t5,%hi(var80062744)
/*  f016e00:	25ad2744 */ 	addiu	$t5,$t5,%lo(var80062744)
/*  f016e04:	8da10000 */ 	lw	$at,0x0($t5)
/*  f016e08:	27ac004c */ 	addiu	$t4,$sp,0x4c
/*  f016e0c:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f016e10:	ad810000 */ 	sw	$at,0x0($t4)
/*  f016e14:	8da10008 */ 	lw	$at,0x8($t5)
/*  f016e18:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f016e1c:	02002825 */ 	or	$a1,$s0,$zero
/*  f016e20:	ad810008 */ 	sw	$at,0x8($t4)
/*  f016e24:	9624024c */ 	lhu	$a0,0x24c($s1)
/*  f016e28:	02403025 */ 	or	$a2,$s2,$zero
/*  f016e2c:	0fc69de5 */ 	jal	func0f1a7794
/*  f016e30:	00003825 */ 	or	$a3,$zero,$zero
/*  f016e34:	ae220248 */ 	sw	$v0,0x248($s1)
/*  f016e38:	0fc59ca0 */ 	jal	fileGetSize
/*  f016e3c:	9624024c */ 	lhu	$a0,0x24c($s1)
/*  f016e40:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016e44:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f016e48:	39cf003f */ 	xori	$t7,$t6,0x3f
/*  f016e4c:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f016e50:	024f9023 */ 	subu	$s2,$s2,$t7
/*  f016e54:	0c008b49 */ 	jal	func00022d24
/*  f016e58:	8e240248 */ 	lw	$a0,0x248($s1)
/*  f016e5c:	0fc2cca0 */ 	jal	func0f0b3280
/*  f016e60:	8e240248 */ 	lw	$a0,0x248($s1)
/*  f016e64:	3c038006 */ 	lui	$v1,%hi(g_TitleModel2)
/*  f016e68:	246324fc */ 	addiu	$v1,$v1,%lo(g_TitleModel2)
/*  f016e6c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016e70:	00402025 */ 	or	$a0,$v0,$zero
/*  f016e74:	0c006bd6 */ 	jal	func0001af58
/*  f016e78:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016e7c:	3c048006 */ 	lui	$a0,%hi(g_TitleModel2)
/*  f016e80:	8c8424fc */ 	lw	$a0,%lo(g_TitleModel2)($a0)
/*  f016e84:	0c006b4d */ 	jal	func0001ad34
/*  f016e88:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f016e8c:	3c098006 */ 	lui	$t1,%hi(var80062750)
/*  f016e90:	25292750 */ 	addiu	$t1,$t1,%lo(var80062750)
/*  f016e94:	8d210000 */ 	lw	$at,0x0($t1)
/*  f016e98:	27a80040 */ 	addiu	$t0,$sp,0x40
/*  f016e9c:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  f016ea0:	ad010000 */ 	sw	$at,0x0($t0)
/*  f016ea4:	8d210008 */ 	lw	$at,0x8($t1)
/*  f016ea8:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f016eac:	02002825 */ 	or	$a1,$s0,$zero
/*  f016eb0:	ad010008 */ 	sw	$at,0x8($t0)
/*  f016eb4:	9624026c */ 	lhu	$a0,0x26c($s1)
/*  f016eb8:	02403025 */ 	or	$a2,$s2,$zero
/*  f016ebc:	0fc69de5 */ 	jal	func0f1a7794
/*  f016ec0:	00003825 */ 	or	$a3,$zero,$zero
/*  f016ec4:	ae220268 */ 	sw	$v0,0x268($s1)
/*  f016ec8:	0fc59ca0 */ 	jal	fileGetSize
/*  f016ecc:	9624026c */ 	lhu	$a0,0x26c($s1)
/*  f016ed0:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016ed4:	3479003f */ 	ori	$t9,$v1,0x3f
/*  f016ed8:	3b2c003f */ 	xori	$t4,$t9,0x3f
/*  f016edc:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f016ee0:	024c9023 */ 	subu	$s2,$s2,$t4
/*  f016ee4:	0c008b49 */ 	jal	func00022d24
/*  f016ee8:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016eec:	0fc2cc2b */ 	jal	func0f0b30ac
/*  f016ef0:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016ef4:	3c038006 */ 	lui	$v1,%hi(var80062508)
/*  f016ef8:	24632508 */ 	addiu	$v1,$v1,%lo(var80062508)
/*  f016efc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016f00:	00402025 */ 	or	$a0,$v0,$zero
/*  f016f04:	0c006bd6 */ 	jal	func0001af58
/*  f016f08:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016f0c:	3c048006 */ 	lui	$a0,%hi(var80062508)
/*  f016f10:	8c842508 */ 	lw	$a0,%lo(var80062508)($a0)
/*  f016f14:	0c006b4d */ 	jal	func0001ad34
/*  f016f18:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f016f1c:	3c188006 */ 	lui	$t8,%hi(var8006275c)
/*  f016f20:	2718275c */ 	addiu	$t8,$t8,%lo(var8006275c)
/*  f016f24:	8f010000 */ 	lw	$at,0x0($t8)
/*  f016f28:	27ad0034 */ 	addiu	$t5,$sp,0x34
/*  f016f2c:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f016f30:	ada10000 */ 	sw	$at,0x0($t5)
/*  f016f34:	8f010008 */ 	lw	$at,0x8($t8)
/*  f016f38:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f016f3c:	02002825 */ 	or	$a1,$s0,$zero
/*  f016f40:	ada10008 */ 	sw	$at,0x8($t5)
/*  f016f44:	96240274 */ 	lhu	$a0,0x274($s1)
/*  f016f48:	02403025 */ 	or	$a2,$s2,$zero
/*  f016f4c:	0fc69de5 */ 	jal	func0f1a7794
/*  f016f50:	00003825 */ 	or	$a3,$zero,$zero
/*  f016f54:	ae220270 */ 	sw	$v0,0x270($s1)
/*  f016f58:	0fc59ca0 */ 	jal	fileGetSize
/*  f016f5c:	96240274 */ 	lhu	$a0,0x274($s1)
/*  f016f60:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f016f64:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f016f68:	3948003f */ 	xori	$t0,$t2,0x3f
/*  f016f6c:	02088021 */ 	addu	$s0,$s0,$t0
/*  f016f70:	02489023 */ 	subu	$s2,$s2,$t0
/*  f016f74:	0c008b49 */ 	jal	func00022d24
/*  f016f78:	8e240270 */ 	lw	$a0,0x270($s1)
/*  f016f7c:	0fc2cc2b */ 	jal	func0f0b30ac
/*  f016f80:	8e240270 */ 	lw	$a0,0x270($s1)
/*  f016f84:	3c038006 */ 	lui	$v1,%hi(var8006250c)
/*  f016f88:	2463250c */ 	addiu	$v1,$v1,%lo(var8006250c)
/*  f016f8c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016f90:	00402025 */ 	or	$a0,$v0,$zero
/*  f016f94:	0c006bd6 */ 	jal	func0001af58
/*  f016f98:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016f9c:	3c048006 */ 	lui	$a0,%hi(var8006250c)
/*  f016fa0:	8c84250c */ 	lw	$a0,%lo(var8006250c)($a0)
/*  f016fa4:	0c006b4d */ 	jal	func0001ad34
/*  f016fa8:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f016fac:	8e240268 */ 	lw	$a0,0x268($s1)
/*  f016fb0:	0c006a6f */ 	jal	func0001a9bc
/*  f016fb4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f016fb8:	84430010 */ 	lh	$v1,0x10($v0)
/*  f016fbc:	3c04800a */ 	lui	$a0,%hi(var8009cca8)
/*  f016fc0:	2484cca8 */ 	addiu	$a0,$a0,%lo(var8009cca8)
/*  f016fc4:	00034880 */ 	sll	$t1,$v1,0x2
/*  f016fc8:	01234823 */ 	subu	$t1,$t1,$v1
/*  f016fcc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f016fd0:	25230007 */ 	addiu	$v1,$t1,0x7
/*  f016fd4:	346b0007 */ 	ori	$t3,$v1,0x7
/*  f016fd8:	39790007 */ 	xori	$t9,$t3,0x7
/*  f016fdc:	ac900000 */ 	sw	$s0,0x0($a0)
/*  f016fe0:	02198021 */ 	addu	$s0,$s0,$t9
/*  f016fe4:	ac900004 */ 	sw	$s0,0x4($a0)
/*  f016fe8:	94430016 */ 	lhu	$v1,0x16($v0)
/*  f016fec:	3c05800a */ 	lui	$a1,%hi(var8009ccb0)
/*  f016ff0:	24a5ccb0 */ 	addiu	$a1,$a1,%lo(var8009ccb0)
/*  f016ff4:	00036080 */ 	sll	$t4,$v1,0x2
/*  f016ff8:	25830007 */ 	addiu	$v1,$t4,0x7
/*  f016ffc:	02198021 */ 	addu	$s0,$s0,$t9
/*  f017000:	346e0007 */ 	ori	$t6,$v1,0x7
/*  f017004:	39cd0007 */ 	xori	$t5,$t6,0x7
/*  f017008:	acb00000 */ 	sw	$s0,0x0($a1)
/*  f01700c:	020d8021 */ 	addu	$s0,$s0,$t5
/*  f017010:	acb00004 */ 	sw	$s0,0x4($a1)
/*  f017014:	3c01800a */ 	lui	$at,%hi(var8009ccb8)
/*  f017018:	ac20ccb8 */ 	sw	$zero,%lo(var8009ccb8)($at)
/*  f01701c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f017020:	3c018006 */ 	lui	$at,%hi(var800624f4)
/*  f017024:	ac3024f4 */ 	sw	$s0,%lo(var800624f4)($at)
/*  f017028:	0c005204 */ 	jal	func00014810
/*  f01702c:	00002025 */ 	or	$a0,$zero,$zero
/*  f017030:	3c188006 */ 	lui	$t8,%hi(var800624a8)
/*  f017034:	8f1824a8 */ 	lw	$t8,%lo(var800624a8)($t8)
/*  f017038:	3c018006 */ 	lui	$at,%hi(var80062730)
/*  f01703c:	ac302730 */ 	sw	$s0,%lo(var80062730)($at)
/*  f017040:	3c018006 */ 	lui	$at,%hi(var80062734)
/*  f017044:	13000003 */ 	beqz	$t8,.L0f017054
/*  f017048:	ac202734 */ 	sw	$zero,%lo(var80062734)($at)
/*  f01704c:	0fc05e60 */ 	jal	func0f017980
/*  f017050:	00000000 */ 	sll	$zero,$zero,0x0
.L0f017054:
/*  f017054:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f017058:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01705c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f017060:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f017064:	03e00008 */ 	jr	$ra
/*  f017068:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

// Mismatch due to regalloc in modelthing block
//void titleInitPdLogo(void)
//{
//	u8 *nextaddr = var8009cca0;
//	u32 remaining;
//	u32 size;
//
//	g_TitleTimer = 0;
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062738
//		g_Props[MODEL_NLOGO].filedata = func0f1a7794(g_Props[MODEL_NLOGO].fileid, nextaddr, 0x47800, 0);
//		size = ALIGN64(fileGetSize(g_Props[MODEL_NLOGO].fileid));
//		nextaddr += size;
//		remaining = 0x47800 - size;
//		func00022d24(g_Props[MODEL_NLOGO].filedata);
//
//		g_TitleModel = func0f0b3280(g_Props[MODEL_NLOGO].filedata);
//		func0001af58(g_TitleModel, 1);
//		func0001ad34(g_TitleModel, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062744
//		g_Props[MODEL_NLOGO2].filedata = func0f1a7794(g_Props[MODEL_NLOGO2].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_Props[MODEL_NLOGO2].fileid));
//		nextaddr += size;
//		remaining -= size;
//		func00022d24(g_Props[MODEL_NLOGO2].filedata);
//
//		g_TitleModel2 = func0f0b3280(g_Props[MODEL_NLOGO2].filedata);
//		func0001af58(g_TitleModel2, 1);
//		func0001ad34(g_TitleModel2, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var80062750
//		g_Props[MODEL_PDTWO].filedata = func0f1a7794(g_Props[MODEL_PDTWO].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_Props[MODEL_PDTWO].fileid));
//		nextaddr += size;
//		remaining -= size;
//		func00022d24(g_Props[MODEL_PDTWO].filedata);
//
//		var80062508 = func0f0b30ac(g_Props[MODEL_PDTWO].filedata);
//		func0001af58(var80062508, 1);
//		func0001ad34(var80062508, &coord);
//	}
//
//	{
//		struct coord coord = {0, 0, 0}; // var8006275c
//		g_Props[MODEL_PDTHREE].filedata = func0f1a7794(g_Props[MODEL_PDTHREE].fileid, nextaddr, remaining, 0);
//		size = ALIGN64(fileGetSize(g_Props[MODEL_PDTHREE].fileid));
//		nextaddr += size;
//		remaining -= size;
//		func00022d24(g_Props[MODEL_PDTHREE].filedata);
//
//		var8006250c = func0f0b30ac(g_Props[MODEL_PDTHREE].filedata);
//		func0001af58(var8006250c, 1);
//		func0001ad34(var8006250c, &coord);
//	}
//
//	{
//		// fb0
//		struct modelthing *modelthing = func0001a9bc(g_Props[MODEL_PDTWO].filedata, 2);
//		u32 size2;
//
//		size = ALIGN8(modelthing->unk10 * 0xc);
//
//		var8009cca8[0] = nextaddr;
//
//		nextaddr += size;
//		remaining -= size;
//		var8009cca8[1] = nextaddr;
//
//		nextaddr += size;
//		remaining -= size;
//		size2 = ALIGN8(modelthing->unk16 * 4);
//		var8009ccb0[0] = nextaddr;
//
//		nextaddr += size2;
//		remaining -= size2;
//		var8009ccb0[1] = nextaddr;
//
//		var8009ccb8 = 0;
//		var800624f4 = 1;
//
//		func00014810(false);
//
//		var80062730 = 1;
//		var80062734 = 0;
//
//		if (var800624a8) {
//			func0f017980();
//		}
//	}
//}

void titleExitPdLogo(void)
{
	modelFree(g_TitleModel);
	modelFree(g_TitleModel2);
	modelFree(var80062508);
	modelFree(var8006250c);

	func00014810(true);
}

void titleTickPdLogo(void)
{
	func0000bd30(46);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(0);

	g_TitleTimer += g_Vars.lvupdate240_60;
	var8009ccb8 = 1 - var8009ccb8;

	if (var80062734) {
		if (g_AltTitle && g_Is4Mb != true) {
			g_TitleMode = TITLEMODE_SKIP;
			func0f13b660();
			g_TitleNextStage = STAGE_CREDITS; // for alt title screen
			setNumPlayers(1);
			func0000e95c(g_TitleNextStage);

			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;

			setDifficulty(DIFF_A);
			func00009ec4(true);
		} else {
			titleSetNextMode(TITLEMODE_SKIP);
		}
	}

	if (var800624a8 && g_TitleTimer > 666) {
		titleSetNextMode(TITLEMODE_SKIP);
	}

	if (func00015020(0, 0xffff)) {
		var800624a8 = var800624ac = 1;

		if (g_TitleTimer < 549) {
			titleSetNextMode(TITLEMODE_PDLOGO);
		}
	}
}

u32 var80062768 = 0x00000000;
u32 var8006276c = 0x00000001;
u32 var80062770 = 0x00000003;
u32 var80062774 = 0x00000000;
u32 var80062778 = 0x00000000;
u32 var8006277c = 0x00000000;
u32 var80062780 = 0x00000000;
u32 var80062784 = 0x00000000;
u32 var80062788 = 0x00000000;
u32 var8006278c = 0x00000000;
u32 var80062790 = 0x00000000;
u32 var80062794 = 0x00000000;
u32 var80062798 = 0x00000000;
u32 var8006279c = 0x00000000;
u32 var800627a0 = 0x00000000;
u32 var800627a4 = 0x00000000;
f32 var800627a8 = 0;
f32 var800627ac = 0;
f32 var800627b0 = 0;
f32 var800627b4 = 0;
f32 var800627b8 = 1;
f32 var800627bc = 0;
u32 var800627c0 = 0x00000000;
f32 var800627c4 = 0;
f32 var800627c8 = 1;
u32 var800627cc = 0x00000000;
u32 var800627d0 = 0x00000000;
u32 var800627d4 = 0x00000000;
u32 var800627d8 = 0x00000000;
u32 var800627dc = 0x00000000;
u32 var800627e0 = 0x00000000;
u32 var800627e4 = 0x00000000;
u32 var800627e8 = 0x00000000;
u32 var800627ec = 0x00000000;
u32 var800627f0 = 0x00000000;
f32 var800627f4 = 0;
u32 var800627f8 = 0x00000000;
u32 var800627fc = 0x00000000;
u32 var80062800 = 0x00000000;
u32 var80062804 = 0x00000001;
f32 var80062808 = 1.5705462694168;
u32 var8006280c = 0x00000000;
u32 var80062810 = 0x00000000;
f32 var80062814 = 0;
u32 var80062818 = 0x00000000;
u32 var8006281c = 0x00000001;
u32 var80062820 = 0x00000003;
u32 var80062824 = 0x00000000;
u32 var80062828 = 0x00000000;
u32 var8006282c = 0x00000000;
u32 var80062830 = 0x00000000;
u32 var80062834 = 0x00000000;
u32 var80062838 = 0x00000000;
u32 var8006283c = 0x00000000;
u32 var80062840 = 0x00000000;
u32 var80062844 = 0x00000000;
u32 var80062848 = 0x00000000;
u32 var8006284c = 0x00000000;
u32 var80062850 = 0x00000000;
u32 var80062854 = 0x00000000;
u32 var80062858 = 0x00000000;
u32 var8006285c = 0x00000000;
u32 var80062860 = 0x447a0000;
struct audiohandle *g_TitleAudioHandle = NULL;
u32 var80062868 = 0x00000000;
u32 var8006286c = 0x00000000;

GLOBAL_ASM(
glabel func0f017248
/*  f017248:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f01724c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f017250:	3c0f8006 */ 	lui	$t7,%hi(var80062768)
/*  f017254:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f017258:	25ef2768 */ 	addiu	$t7,$t7,%lo(var80062768)
/*  f01725c:	4487a000 */ 	mtc1	$a3,$f20
/*  f017260:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f017264:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f017268:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f01726c:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f017270:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f017274:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f017278:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f01727c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f017280:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f017284:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f017288:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f01728c:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f017290:	afa60158 */ 	sw	$a2,0x158($sp)
/*  f017294:	25eb003c */ 	addiu	$t3,$t7,0x3c
/*  f017298:	27ae0110 */ 	addiu	$t6,$sp,0x110
.L0f01729c:
/*  f01729c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0172a0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0172a4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0172a8:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f0172ac:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0172b0:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f0172b4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0172b8:	15ebfff8 */ 	bne	$t7,$t3,.L0f01729c
/*  f0172bc:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0172c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0172c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0172c8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0172cc:	0c006a47 */ 	jal	func0001a91c
/*  f0172d0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0172d4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0172d8:	0c006a87 */ 	jal	func0001aa1c
/*  f0172dc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0172e0:	8fac0158 */ 	lw	$t4,0x158($sp)
/*  f0172e4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0172e8:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0172ec:	0c006a47 */ 	jal	func0001a91c
/*  f0172f0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0172f4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0172f8:	0c006a87 */ 	jal	func0001aa1c
/*  f0172fc:	00402825 */ 	or	$a1,$v0,$zero
/*  f017300:	3c014780 */ 	lui	$at,0x4780
/*  f017304:	44812000 */ 	mtc1	$at,$f4
/*  f017308:	8fa60158 */ 	lw	$a2,0x158($sp)
/*  f01730c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f017310:	4604a182 */ 	mul.s	$f6,$f20,$f4
/*  f017314:	4480a000 */ 	mtc1	$zero,$f20
/*  f017318:	2ccd0001 */ 	sltiu	$t5,$a2,0x1
/*  f01731c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f017320:	27be00c0 */ 	addiu	$s8,$sp,0xc0
/*  f017324:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f017328:	44034000 */ 	mfc1	$v1,$f8
/*  f01732c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017330:	04610003 */ 	bgez	$v1,.L0f017340
/*  f017334:	0060b025 */ 	or	$s6,$v1,$zero
/*  f017338:	10000007 */ 	beqz	$zero,.L0f017358
/*  f01733c:	0000b025 */ 	or	$s6,$zero,$zero
.L0f017340:
/*  f017340:	3c010001 */ 	lui	$at,0x1
/*  f017344:	34210001 */ 	ori	$at,$at,0x1
/*  f017348:	0061082a */ 	slt	$at,$v1,$at
/*  f01734c:	54200003 */ 	bnezl	$at,.L0f01735c
/*  f017350:	8fa30160 */ 	lw	$v1,0x160($sp)
/*  f017354:	3c160001 */ 	lui	$s6,0x1
.L0f017358:
/*  f017358:	8fa30160 */ 	lw	$v1,0x160($sp)
.L0f01735c:
/*  f01735c:	06c10003 */ 	bgez	$s6,.L0f01736c
/*  f017360:	00161203 */ 	sra	$v0,$s6,0x8
/*  f017364:	26c100ff */ 	addiu	$at,$s6,0xff
/*  f017368:	00011203 */ 	sra	$v0,$at,0x8
.L0f01736c:
/*  f01736c:	0062082a */ 	slt	$at,$v1,$v0
/*  f017370:	10200002 */ 	beqz	$at,.L0f01737c
/*  f017374:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f017378:	afa300d8 */ 	sw	$v1,0xd8($sp)
.L0f01737c:
/*  f01737c:	14c00006 */ 	bnez	$a2,.L0f017398
/*  f017380:	3c180001 */ 	lui	$t8,0x1
/*  f017384:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f017388:	240f0100 */ 	addiu	$t7,$zero,0x100
/*  f01738c:	0316b023 */ 	subu	$s6,$t8,$s6
/*  f017390:	01eb7023 */ 	subu	$t6,$t7,$t3
/*  f017394:	afae00d8 */ 	sw	$t6,0xd8($sp)
.L0f017398:
/*  f017398:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f01739c:	8fad00d8 */ 	lw	$t5,0xd8($sp)
/*  f0173a0:	05810003 */ 	bgez	$t4,.L0f0173b0
/*  f0173a4:	29a10100 */ 	slti	$at,$t5,0x100
/*  f0173a8:	10000004 */ 	beqz	$zero,.L0f0173bc
/*  f0173ac:	afa000d8 */ 	sw	$zero,0xd8($sp)
.L0f0173b0:
/*  f0173b0:	14200002 */ 	bnez	$at,.L0f0173bc
/*  f0173b4:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f0173b8:	afb900d8 */ 	sw	$t9,0xd8($sp)
.L0f0173bc:
/*  f0173bc:	3c014380 */ 	lui	$at,0x4380
/*  f0173c0:	44818000 */ 	mtc1	$at,$f16
/*  f0173c4:	c7aa0164 */ 	lwc1	$f10,0x164($sp)
/*  f0173c8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0173cc:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0173d0:	44022000 */ 	mfc1	$v0,$f4
/*  f0173d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0173d8:	04410003 */ 	bgez	$v0,.L0f0173e8
/*  f0173dc:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0173e0:	10000005 */ 	beqz	$zero,.L0f0173f8
/*  f0173e4:	afa000b8 */ 	sw	$zero,0xb8($sp)
.L0f0173e8:
/*  f0173e8:	28410100 */ 	slti	$at,$v0,0x100
/*  f0173ec:	14200002 */ 	bnez	$at,.L0f0173f8
/*  f0173f0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0173f4:	afaf00b8 */ 	sw	$t7,0xb8($sp)
.L0f0173f8:
/*  f0173f8:	8fab016c */ 	lw	$t3,0x16c($sp)
/*  f0173fc:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f017400:	3c0142fe */ 	lui	$at,0x42fe
/*  f017404:	4481b000 */ 	mtc1	$at,$f22
/*  f017408:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f01740c:	afab0100 */ 	sw	$t3,0x100($sp)
/*  f017410:	afae00fc */ 	sw	$t6,0xfc($sp)
.L0f017414:
/*  f017414:	8fac0108 */ 	lw	$t4,0x108($sp)
/*  f017418:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f01741c:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f017420:	15800009 */ 	bnez	$t4,.L0f017448
/*  f017424:	24010001 */ 	addiu	$at,$zero,0x1
/*  f017428:	0c006a47 */ 	jal	func0001a91c
/*  f01742c:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017430:	00408025 */ 	or	$s0,$v0,$zero
/*  f017434:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017438:	0c006a47 */ 	jal	func0001a91c
/*  f01743c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f017440:	1000001f */ 	beqz	$zero,.L0f0174c0
/*  f017444:	00403025 */ 	or	$a2,$v0,$zero
.L0f017448:
/*  f017448:	15a1000a */ 	bne	$t5,$at,.L0f017474
/*  f01744c:	8fb90108 */ 	lw	$t9,0x108($sp)
/*  f017450:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017454:	0c006a47 */ 	jal	func0001a91c
/*  f017458:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f01745c:	00408025 */ 	or	$s0,$v0,$zero
/*  f017460:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017464:	0c006a47 */ 	jal	func0001a91c
/*  f017468:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f01746c:	10000014 */ 	beqz	$zero,.L0f0174c0
/*  f017470:	00403025 */ 	or	$a2,$v0,$zero
.L0f017474:
/*  f017474:	24010002 */ 	addiu	$at,$zero,0x2
/*  f017478:	1721000a */ 	bne	$t9,$at,.L0f0174a4
/*  f01747c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f017480:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017484:	0c006a47 */ 	jal	func0001a91c
/*  f017488:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f01748c:	00408025 */ 	or	$s0,$v0,$zero
/*  f017490:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f017494:	0c006a47 */ 	jal	func0001a91c
/*  f017498:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f01749c:	10000008 */ 	beqz	$zero,.L0f0174c0
/*  f0174a0:	00403025 */ 	or	$a2,$v0,$zero
.L0f0174a4:
/*  f0174a4:	0c006a47 */ 	jal	func0001a91c
/*  f0174a8:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0174ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0174b0:	8ee40008 */ 	lw	$a0,0x8($s7)
/*  f0174b4:	0c006a47 */ 	jal	func0001a91c
/*  f0174b8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f0174bc:	00403025 */ 	or	$a2,$v0,$zero
.L0f0174c0:
/*  f0174c0:	520000e5 */ 	beqzl	$s0,.L0f017858
/*  f0174c4:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0174c8:	104000e2 */ 	beqz	$v0,.L0f017854
/*  f0174cc:	8fb80158 */ 	lw	$t8,0x158($sp)
/*  f0174d0:	13000008 */ 	beqz	$t8,.L0f0174f4
/*  f0174d4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0174d8:	8e150004 */ 	lw	$s5,0x4($s0)
/*  f0174dc:	8cd10004 */ 	lw	$s1,0x4($a2)
/*  f0174e0:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0174e4:	0c006a87 */ 	jal	func0001aa1c
/*  f0174e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0174ec:	10000006 */ 	beqz	$zero,.L0f017508
/*  f0174f0:	86af0010 */ 	lh	$t7,0x10($s5)
.L0f0174f4:
/*  f0174f4:	8cd50004 */ 	lw	$s5,0x4($a2)
/*  f0174f8:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f0174fc:	0c006a87 */ 	jal	func0001aa1c
/*  f017500:	00c02825 */ 	or	$a1,$a2,$zero
/*  f017504:	86af0010 */ 	lh	$t7,0x10($s5)
.L0f017508:
/*  f017508:	8ea7000c */ 	lw	$a3,0xc($s5)
/*  f01750c:	862d0010 */ 	lh	$t5,0x10($s1)
/*  f017510:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f017514:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f017518:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f01751c:	01674821 */ 	addu	$t1,$t3,$a3
/*  f017520:	8fab0100 */ 	lw	$t3,0x100($sp)
/*  f017524:	25290007 */ 	addiu	$t1,$t1,0x7
/*  f017528:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f01752c:	352e0007 */ 	ori	$t6,$t1,0x7
/*  f017530:	39c90007 */ 	xori	$t1,$t6,0x7
/*  f017534:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f017538:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f01753c:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f017540:	032dc823 */ 	subu	$t9,$t9,$t5
/*  f017544:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f017548:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f01754c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017550:	03285021 */ 	addu	$t2,$t9,$t0
/*  f017554:	254a0007 */ 	addiu	$t2,$t2,0x7
/*  f017558:	35580007 */ 	ori	$t8,$t2,0x7
/*  f01755c:	18c00044 */ 	blez	$a2,.L0f017670
/*  f017560:	3b0a0007 */ 	xori	$t2,$t8,0x7
/*  f017564:	8fa30100 */ 	lw	$v1,0x100($sp)
/*  f017568:	00e02025 */ 	or	$a0,$a3,$zero
/*  f01756c:	01002825 */ 	or	$a1,$t0,$zero
/*  f017570:	88810000 */ 	lwl	$at,0x0($a0)
.L0f017574:
/*  f017574:	98810003 */ 	lwr	$at,0x3($a0)
/*  f017578:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f01757c:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f017580:	a861fff4 */ 	swl	$at,-0xc($v1)
/*  f017584:	b861fff7 */ 	swr	$at,-0x9($v1)
/*  f017588:	888d0004 */ 	lwl	$t5,0x4($a0)
/*  f01758c:	988d0007 */ 	lwr	$t5,0x7($a0)
/*  f017590:	846efff4 */ 	lh	$t6,-0xc($v1)
/*  f017594:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f017598:	a86dfff8 */ 	swl	$t5,-0x8($v1)
/*  f01759c:	b86dfffb */ 	swr	$t5,-0x5($v1)
/*  f0175a0:	8881fffc */ 	lwl	$at,-0x4($a0)
/*  f0175a4:	9881ffff */ 	lwr	$at,-0x1($a0)
/*  f0175a8:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f0175ac:	a861fffc */ 	swl	$at,-0x4($v1)
/*  f0175b0:	b861ffff */ 	swr	$at,-0x1($v1)
/*  f0175b4:	8498fff4 */ 	lh	$t8,-0xc($a0)
/*  f0175b8:	84b9fff4 */ 	lh	$t9,-0xc($a1)
/*  f0175bc:	03387823 */ 	subu	$t7,$t9,$t8
/*  f0175c0:	01f60019 */ 	multu	$t7,$s6
/*  f0175c4:	00001012 */ 	mflo	$v0
/*  f0175c8:	04410004 */ 	bgez	$v0,.L0f0175dc
/*  f0175cc:	00025c03 */ 	sra	$t3,$v0,0x10
/*  f0175d0:	3401ffff */ 	dli	$at,0xffff
/*  f0175d4:	00220821 */ 	addu	$at,$at,$v0
/*  f0175d8:	00015c03 */ 	sra	$t3,$at,0x10
.L0f0175dc:
/*  f0175dc:	000b6400 */ 	sll	$t4,$t3,0x10
/*  f0175e0:	000c6c03 */ 	sra	$t5,$t4,0x10
/*  f0175e4:	01cdc821 */ 	addu	$t9,$t6,$t5
/*  f0175e8:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f0175ec:	848ffff6 */ 	lh	$t7,-0xa($a0)
/*  f0175f0:	84b8fff6 */ 	lh	$t8,-0xa($a1)
/*  f0175f4:	846efff6 */ 	lh	$t6,-0xa($v1)
/*  f0175f8:	030f5823 */ 	subu	$t3,$t8,$t7
/*  f0175fc:	01760019 */ 	multu	$t3,$s6
/*  f017600:	00001012 */ 	mflo	$v0
/*  f017604:	04410004 */ 	bgez	$v0,.L0f017618
/*  f017608:	00026403 */ 	sra	$t4,$v0,0x10
/*  f01760c:	3401ffff */ 	dli	$at,0xffff
/*  f017610:	00220821 */ 	addu	$at,$at,$v0
/*  f017614:	00016403 */ 	sra	$t4,$at,0x10
.L0f017618:
/*  f017618:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f01761c:	000dcc03 */ 	sra	$t9,$t5,0x10
/*  f017620:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f017624:	a478fff6 */ 	sh	$t8,-0xa($v1)
/*  f017628:	848bfff8 */ 	lh	$t3,-0x8($a0)
/*  f01762c:	84affff8 */ 	lh	$t7,-0x8($a1)
/*  f017630:	846efff8 */ 	lh	$t6,-0x8($v1)
/*  f017634:	01eb6023 */ 	subu	$t4,$t7,$t3
/*  f017638:	01960019 */ 	multu	$t4,$s6
/*  f01763c:	00001012 */ 	mflo	$v0
/*  f017640:	04410004 */ 	bgez	$v0,.L0f017654
/*  f017644:	00026c03 */ 	sra	$t5,$v0,0x10
/*  f017648:	3401ffff */ 	dli	$at,0xffff
/*  f01764c:	00220821 */ 	addu	$at,$at,$v0
/*  f017650:	00016c03 */ 	sra	$t5,$at,0x10
.L0f017654:
/*  f017654:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f017658:	a46ffff8 */ 	sh	$t7,-0x8($v1)
/*  f01765c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017660:	0286082a */ 	slt	$at,$s4,$a2
/*  f017664:	5420ffc3 */ 	bnezl	$at,.L0f017574
/*  f017668:	88810000 */ 	lwl	$at,0x0($a0)
/*  f01766c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f017670:
/*  f017670:	96a20016 */ 	lhu	$v0,0x16($s5)
/*  f017674:	3c0b0001 */ 	lui	$t3,0x1
/*  f017678:	01769823 */ 	subu	$s3,$t3,$s6
/*  f01767c:	18400065 */ 	blez	$v0,.L0f017814
/*  f017680:	01208825 */ 	or	$s1,$t1,$zero
/*  f017684:	01409025 */ 	or	$s2,$t2,$zero
/*  f017688:	8fb000fc */ 	lw	$s0,0xfc($sp)
/*  f01768c:	822c0000 */ 	lb	$t4,0x0($s1)
.L0f017690:
/*  f017690:	82590000 */ 	lb	$t9,0x0($s2)
/*  f017694:	03c02025 */ 	or	$a0,$s8,$zero
/*  f017698:	01930019 */ 	multu	$t4,$s3
/*  f01769c:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0176a0:	00006812 */ 	mflo	$t5
/*  f0176a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0176a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0176ac:	03360019 */ 	multu	$t9,$s6
/*  f0176b0:	00007012 */ 	mflo	$t6
/*  f0176b4:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f0176b8:	07010004 */ 	bgez	$t8,.L0f0176cc
/*  f0176bc:	00187c03 */ 	sra	$t7,$t8,0x10
/*  f0176c0:	3401ffff */ 	dli	$at,0xffff
/*  f0176c4:	00380821 */ 	addu	$at,$at,$t8
/*  f0176c8:	00017c03 */ 	sra	$t7,$at,0x10
.L0f0176cc:
/*  f0176cc:	afaf00cc */ 	sw	$t7,0xcc($sp)
/*  f0176d0:	822b0001 */ 	lb	$t3,0x1($s1)
/*  f0176d4:	82590001 */ 	lb	$t9,0x1($s2)
/*  f0176d8:	448f3000 */ 	mtc1	$t7,$f6
/*  f0176dc:	01730019 */ 	multu	$t3,$s3
/*  f0176e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0176e4:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f0176e8:	00006012 */ 	mflo	$t4
/*  f0176ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0176f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0176f4:	03360019 */ 	multu	$t9,$s6
/*  f0176f8:	00006812 */ 	mflo	$t5
/*  f0176fc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f017700:	05c10004 */ 	bgez	$t6,.L0f017714
/*  f017704:	000ec403 */ 	sra	$t8,$t6,0x10
/*  f017708:	3401ffff */ 	dli	$at,0xffff
/*  f01770c:	002e0821 */ 	addu	$at,$at,$t6
/*  f017710:	0001c403 */ 	sra	$t8,$at,0x10
.L0f017714:
/*  f017714:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f017718:	822b0002 */ 	lb	$t3,0x2($s1)
/*  f01771c:	824c0002 */ 	lb	$t4,0x2($s2)
/*  f017720:	44985000 */ 	mtc1	$t8,$f10
/*  f017724:	01730019 */ 	multu	$t3,$s3
/*  f017728:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f01772c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f017730:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f017734:	0000c812 */ 	mflo	$t9
/*  f017738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01773c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017740:	01960019 */ 	multu	$t4,$s6
/*  f017744:	00006812 */ 	mflo	$t5
/*  f017748:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f01774c:	05c10004 */ 	bgez	$t6,.L0f017760
/*  f017750:	000e5c03 */ 	sra	$t3,$t6,0x10
/*  f017754:	3401ffff */ 	dli	$at,0xffff
/*  f017758:	002e0821 */ 	addu	$at,$at,$t6
/*  f01775c:	00015c03 */ 	sra	$t3,$at,0x10
.L0f017760:
/*  f017760:	448b9000 */ 	mtc1	$t3,$f18
/*  f017764:	afab00d4 */ 	sw	$t3,0xd4($sp)
/*  f017768:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f01776c:	45000009 */ 	bc1f	.L0f017794
/*  f017770:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f017774:	4610a032 */ 	c.eq.s	$f20,$f16
/*  f017778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01777c:	45000005 */ 	bc1f	.L0f017794
/*  f017780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017784:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f017788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01778c:	45030004 */ 	bc1tl	.L0f0177a0
/*  f017790:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
.L0f017794:
/*  f017794:	0c0011e4 */ 	jal	scaleTo1
/*  f017798:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f01779c:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
.L0f0177a0:
/*  f0177a0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0177a4:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0177a8:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0177ac:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0177b0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0177b4:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0177b8:	44199000 */ 	mfc1	$t9,$f18
/*  f0177bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0177c0:	a219fffc */ 	sb	$t9,-0x4($s0)
/*  f0177c4:	c7a800c4 */ 	lwc1	$f8,0xc4($sp)
/*  f0177c8:	46164402 */ 	mul.s	$f16,$f8,$f22
/*  f0177cc:	4600810d */ 	trunc.w.s	$f4,$f16
/*  f0177d0:	440e2000 */ 	mfc1	$t6,$f4
/*  f0177d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0177d8:	a20efffd */ 	sb	$t6,-0x3($s0)
/*  f0177dc:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0177e0:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0177e4:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0177e8:	44189000 */ 	mfc1	$t8,$f18
/*  f0177ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0177f0:	a218fffe */ 	sb	$t8,-0x2($s0)
/*  f0177f4:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f0177f8:	a20bffff */ 	sb	$t3,-0x1($s0)
/*  f0177fc:	96a20016 */ 	lhu	$v0,0x16($s5)
/*  f017800:	0282082a */ 	slt	$at,$s4,$v0
/*  f017804:	5420ffa2 */ 	bnezl	$at,.L0f017690
/*  f017808:	822c0000 */ 	lb	$t4,0x0($s1)
/*  f01780c:	86a60010 */ 	lh	$a2,0x10($s5)
/*  f017810:	0000a025 */ 	or	$s4,$zero,$zero
.L0f017814:
/*  f017814:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f017818:	00066080 */ 	sll	$t4,$a2,0x2
/*  f01781c:	01866023 */ 	subu	$t4,$t4,$a2
/*  f017820:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f017824:	01996821 */ 	addu	$t5,$t4,$t9
/*  f017828:	8fac00fc */ 	lw	$t4,0xfc($sp)
/*  f01782c:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f017830:	00025880 */ 	sll	$t3,$v0,0x2
/*  f017834:	35cf0007 */ 	ori	$t7,$t6,0x7
/*  f017838:	016cc821 */ 	addu	$t9,$t3,$t4
/*  f01783c:	272d0007 */ 	addiu	$t5,$t9,0x7
/*  f017840:	39f80007 */ 	xori	$t8,$t7,0x7
/*  f017844:	35ae0007 */ 	ori	$t6,$t5,0x7
/*  f017848:	39cf0007 */ 	xori	$t7,$t6,0x7
/*  f01784c:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f017850:	afaf00fc */ 	sw	$t7,0xfc($sp)
.L0f017854:
/*  f017854:	8fb80108 */ 	lw	$t8,0x108($sp)
.L0f017858:
/*  f017858:	270b0001 */ 	addiu	$t3,$t8,0x1
/*  f01785c:	29610004 */ 	slti	$at,$t3,0x4
/*  f017860:	1420feec */ 	bnez	$at,.L0f017414
/*  f017864:	afab0108 */ 	sw	$t3,0x108($sp)
/*  f017868:	8fa20150 */ 	lw	$v0,0x150($sp)
/*  f01786c:	8fb00168 */ 	lw	$s0,0x168($sp)
/*  f017870:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f017874:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f017878:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f01787c:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f017880:	332d00ff */ 	andi	$t5,$t9,0xff
/*  f017884:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f017888:	afb00110 */ 	sw	$s0,0x110($sp)
/*  f01788c:	8eee0008 */ 	lw	$t6,0x8($s7)
/*  f017890:	85c4000e */ 	lh	$a0,0xe($t6)
/*  f017894:	afa30150 */ 	sw	$v1,0x150($sp)
/*  f017898:	00047980 */ 	sll	$t7,$a0,0x6
/*  f01789c:	0fc59e7d */ 	jal	func0f1679f4
/*  f0178a0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0178a4:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0178a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0178ac:	0c005746 */ 	jal	func00015d18
/*  f0178b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0178b4:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f0178b8:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0178bc:	0c007308 */ 	jal	func0001cc20
/*  f0178c0:	aef8000c */ 	sw	$t8,0xc($s7)
/*  f0178c4:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0178c8:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0178cc:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f0178d0:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0178d4:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f0178d8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0178dc:	0c0087bd */ 	jal	func00021ef4
/*  f0178e0:	afac011c */ 	sw	$t4,0x11c($sp)
/*  f0178e4:	8fb9011c */ 	lw	$t9,0x11c($sp)
/*  f0178e8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0178ec:	27b1006c */ 	addiu	$s1,$sp,0x6c
/*  f0178f0:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0178f4:	8eed0008 */ 	lw	$t5,0x8($s7)
/*  f0178f8:	85ae000e */ 	lh	$t6,0xe($t5)
/*  f0178fc:	59c00012 */ 	blezl	$t6,.L0f017948
/*  f017900:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f017904:	8eef000c */ 	lw	$t7,0xc($s7)
.L0f017908:
/*  f017908:	02202825 */ 	or	$a1,$s1,$zero
/*  f01790c:	0c005746 */ 	jal	func00015d18
/*  f017910:	01f02021 */ 	addu	$a0,$t7,$s0
/*  f017914:	8ef8000c */ 	lw	$t8,0xc($s7)
/*  f017918:	00145980 */ 	sll	$t3,$s4,0x6
/*  f01791c:	02202025 */ 	or	$a0,$s1,$zero
/*  f017920:	0c005815 */ 	jal	func00016054
/*  f017924:	030b2821 */ 	addu	$a1,$t8,$t3
/*  f017928:	8eec0008 */ 	lw	$t4,0x8($s7)
/*  f01792c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f017930:	26100040 */ 	addiu	$s0,$s0,0x40
/*  f017934:	8599000e */ 	lh	$t9,0xe($t4)
/*  f017938:	0299082a */ 	slt	$at,$s4,$t9
/*  f01793c:	5420fff2 */ 	bnezl	$at,.L0f017908
/*  f017940:	8eef000c */ 	lw	$t7,0xc($s7)
/*  f017944:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f017948:
/*  f017948:	8fa20150 */ 	lw	$v0,0x150($sp)
/*  f01794c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f017950:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f017954:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f017958:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f01795c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f017960:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f017964:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f017968:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f01796c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f017970:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f017974:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f017978:	03e00008 */ 	jr	$ra
/*  f01797c:	27bd0150 */ 	addiu	$sp,$sp,0x150
);

void func0f017980(void)
{
	var800627a8 = 0;
	var800627ac = 0;
	var800627b0 = 0;
	var800627b4 = 0;
	var800627b8 = 0.35f;
	var800627bc = 1;
	var800627f4 = 0.63f;
	var80062808 = 1.6443619728088f;
	var80062814 = 0.19975f;
	var800627c4 = 0;
	var800627c8 = 0;

	var800627c0 = 1;
	var800627cc = 0;
	var800627d0 = 0;
	var800627d4 = 0;
	var800627d8 = 0;
	var800627dc = 0;
	var800627e0 = 0;
	var800627e4 = 0;
	var800627e8 = 0;
	var800627ec = 0;
	var800627f0 = 0;
	var800627f8 = 1;
	var800627fc = 1;
	var80062800 = 0;
	var80062804 = 1;
	var8006280c = 1;
	var80062810 = 1;
	g_TitleTimer = 549;
	var80062730 = 0;

	func0f16deb8(1);
}

GLOBAL_ASM(
glabel titleRenderPdLogo
.late_rodata
glabel var7f1a8400
.word 0x458ca000
glabel var7f1a8404
.word 0x3dcccccd
glabel var7f1a8408
.word 0x4087b1f9
glabel var7f1a840c
.word 0x3c9a6417
glabel var7f1a8410
.word 0x3ef13c64
glabel var7f1a8414
.word 0x3eb33333
glabel var7f1a8418
.word 0x3fc907a9
glabel var7f1a841c
.word 0x39459ed6
glabel var7f1a8420
.word 0x3c9a6417
glabel var7f1a8424
.word 0x40c907a9
glabel var7f1a8428
.word 0x40c907a9
glabel var7f1a842c
.word 0x40c907a9
glabel var7f1a8430
.word 0x40c907a9
glabel var7f1a8434
.word 0x3b83126f
glabel var7f1a8438
.word 0x3f4ccccd
glabel var7f1a843c
.word 0x38ed2501
glabel var7f1a8440
.word 0x3c3944e9
glabel var7f1a8444
.word 0x40c907a9
glabel var7f1a8448
.word 0x3bf5c28f
glabel var7f1a844c
.word 0x3ccccccd
glabel var7f1a8450
.word 0x3db851ec
glabel var7f1a8454
.word 0x3dcccccd
glabel var7f1a8458
.word 0x3bcddaca
glabel var7f1a845c
.word 0x3c8b4396
glabel var7f1a8460
.word 0x40490fdb
glabel var7f1a8464
.word 0x3e19999a
glabel var7f1a8468
.word 0x3e9db22d
.text
/*  f017ac0:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f017ac4:	3c0f8006 */ 	lui	$t7,%hi(var80062818)
/*  f017ac8:	3c028006 */ 	lui	$v0,%hi(var80062730)
/*  f017acc:	25ef2818 */ 	addiu	$t7,$t7,%lo(var80062818)
/*  f017ad0:	24422730 */ 	addiu	$v0,$v0,%lo(var80062730)
/*  f017ad4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f017ad8:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f017adc:	25f9003c */ 	addiu	$t9,$t7,0x3c
/*  f017ae0:	27ae02f0 */ 	addiu	$t6,$sp,0x2f0
.L0f017ae4:
/*  f017ae4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017ae8:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f017aec:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f017af0:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f017af4:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f017af8:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f017afc:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f017b00:	15f9fff8 */ 	bne	$t7,$t9,.L0f017ae4
/*  f017b04:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f017b08:	8de10000 */ 	lw	$at,0x0($t7)
/*  f017b0c:	3c188006 */ 	lui	$t8,%hi(g_TitleTimer)
/*  f017b10:	3c048006 */ 	lui	$a0,%hi(var800627cc)
/*  f017b14:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017b18:	8f1824c4 */ 	lw	$t8,%lo(g_TitleTimer)($t8)
/*  f017b1c:	3c017f1b */ 	lui	$at,%hi(var7f1a8400)
/*  f017b20:	c4288400 */ 	lwc1	$f8,%lo(var7f1a8400)($at)
/*  f017b24:	44982000 */ 	mtc1	$t8,$f4
/*  f017b28:	3c017f1b */ 	lui	$at,%hi(var7f1a8404)
/*  f017b2c:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f017b30:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f017b34:	c4248404 */ 	lwc1	$f4,%lo(var7f1a8404)($at)
/*  f017b38:	3c098006 */ 	lui	$t1,%hi(var800627d4)
/*  f017b3c:	3c0a8006 */ 	lui	$t2,%hi(var800627e0)
/*  f017b40:	3c0c8006 */ 	lui	$t4,%hi(var800627f0)
/*  f017b44:	3c0d8006 */ 	lui	$t5,%hi(var80062800)
/*  f017b48:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f017b4c:	3c0b8006 */ 	lui	$t3,%hi(var800627c4)
/*  f017b50:	25ad2800 */ 	addiu	$t5,$t5,%lo(var80062800)
/*  f017b54:	258c27f0 */ 	addiu	$t4,$t4,%lo(var800627f0)
/*  f017b58:	254a27e0 */ 	addiu	$t2,$t2,%lo(var800627e0)
/*  f017b5c:	252927d4 */ 	addiu	$t1,$t1,%lo(var800627d4)
/*  f017b60:	3c013f80 */ 	lui	$at,0x3f80
/*  f017b64:	248427cc */ 	addiu	$a0,$a0,%lo(var800627cc)
/*  f017b68:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017b6c:	256b27c4 */ 	addiu	$t3,$t3,%lo(var800627c4)
/*  f017b70:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f017b74:	13200041 */ 	beqz	$t9,.L0f017c7c
/*  f017b78:	e7a6013c */ 	swc1	$f6,0x13c($sp)
/*  f017b7c:	44817000 */ 	mtc1	$at,$f14
/*  f017b80:	3c017f1b */ 	lui	$at,%hi(var7f1a8408)
/*  f017b84:	c4288408 */ 	lwc1	$f8,%lo(var7f1a8408)($at)
/*  f017b88:	3c018006 */ 	lui	$at,0x8006
/*  f017b8c:	44809000 */ 	mtc1	$zero,$f18
/*  f017b90:	e42827a8 */ 	swc1	$f8,0x27a8($at)
/*  f017b94:	3c017f1b */ 	lui	$at,%hi(var7f1a840c)
/*  f017b98:	c42a840c */ 	lwc1	$f10,%lo(var7f1a840c)($at)
/*  f017b9c:	3c018006 */ 	lui	$at,0x8006
/*  f017ba0:	3c1f8006 */ 	lui	$ra,%hi(var800627d8)
/*  f017ba4:	e42a27ac */ 	swc1	$f10,0x27ac($at)
/*  f017ba8:	3c017f1b */ 	lui	$at,%hi(var7f1a8410)
/*  f017bac:	c4248410 */ 	lwc1	$f4,%lo(var7f1a8410)($at)
/*  f017bb0:	3c018006 */ 	lui	$at,0x8006
/*  f017bb4:	27ff27d8 */ 	addiu	$ra,$ra,%lo(var800627d8)
/*  f017bb8:	e42427b0 */ 	swc1	$f4,0x27b0($at)
/*  f017bbc:	3c018006 */ 	lui	$at,0x8006
/*  f017bc0:	e43227b4 */ 	swc1	$f18,0x27b4($at)
/*  f017bc4:	3c017f1b */ 	lui	$at,%hi(var7f1a8414)
/*  f017bc8:	c4268414 */ 	lwc1	$f6,%lo(var7f1a8414)($at)
/*  f017bcc:	3c018006 */ 	lui	$at,0x8006
/*  f017bd0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f017bd4:	e42627b8 */ 	swc1	$f6,0x27b8($at)
/*  f017bd8:	3c018006 */ 	lui	$at,0x8006
/*  f017bdc:	e43227bc */ 	swc1	$f18,0x27bc($at)
/*  f017be0:	3c018006 */ 	lui	$at,%hi(var800627c0)
/*  f017be4:	ac2027c0 */ 	sw	$zero,%lo(var800627c0)($at)
/*  f017be8:	3c018006 */ 	lui	$at,0x8006
/*  f017bec:	e42e27c8 */ 	swc1	$f14,0x27c8($at)
/*  f017bf0:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017bf4:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f017bf8:	3c018006 */ 	lui	$at,%hi(var800627d0)
/*  f017bfc:	ac2027d0 */ 	sw	$zero,%lo(var800627d0)($at)
/*  f017c00:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017c04:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017c08:	3c018006 */ 	lui	$at,%hi(var800627dc)
/*  f017c0c:	ac2027dc */ 	sw	$zero,%lo(var800627dc)($at)
/*  f017c10:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017c14:	3c018006 */ 	lui	$at,%hi(var800627e4)
/*  f017c18:	ac2027e4 */ 	sw	$zero,%lo(var800627e4)($at)
/*  f017c1c:	3c018006 */ 	lui	$at,%hi(var800627e8)
/*  f017c20:	ac2027e8 */ 	sw	$zero,%lo(var800627e8)($at)
/*  f017c24:	3c018006 */ 	lui	$at,%hi(var80062804)
/*  f017c28:	ac232804 */ 	sw	$v1,%lo(var80062804)($at)
/*  f017c2c:	3c018006 */ 	lui	$at,%hi(var800627ec)
/*  f017c30:	ac2027ec */ 	sw	$zero,%lo(var800627ec)($at)
/*  f017c34:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017c38:	3c018006 */ 	lui	$at,0x8006
/*  f017c3c:	e43227f4 */ 	swc1	$f18,0x27f4($at)
/*  f017c40:	3c018006 */ 	lui	$at,%hi(var800627fc)
/*  f017c44:	ac2027fc */ 	sw	$zero,%lo(var800627fc)($at)
/*  f017c48:	3c018006 */ 	lui	$at,%hi(var800627f8)
/*  f017c4c:	ac2f27f8 */ 	sw	$t7,%lo(var800627f8)($at)
/*  f017c50:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f017c54:	3c018006 */ 	lui	$at,%hi(var8006280c)
/*  f017c58:	ac20280c */ 	sw	$zero,%lo(var8006280c)($at)
/*  f017c5c:	3c017f1b */ 	lui	$at,%hi(var7f1a8418)
/*  f017c60:	c4288418 */ 	lwc1	$f8,%lo(var7f1a8418)($at)
/*  f017c64:	3c018006 */ 	lui	$at,0x8006
/*  f017c68:	e4282808 */ 	swc1	$f8,0x2808($at)
/*  f017c6c:	3c018006 */ 	lui	$at,%hi(var80062810)
/*  f017c70:	ac202810 */ 	sw	$zero,%lo(var80062810)($at)
/*  f017c74:	3c018006 */ 	lui	$at,0x8006
/*  f017c78:	e4322814 */ 	swc1	$f18,0x2814($at)
.L0f017c7c:
/*  f017c7c:	3c048006 */ 	lui	$a0,%hi(var800627cc)
/*  f017c80:	248427cc */ 	addiu	$a0,$a0,%lo(var800627cc)
/*  f017c84:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f017c88:	3c013f80 */ 	lui	$at,0x3f80
/*  f017c8c:	44817000 */ 	mtc1	$at,$f14
/*  f017c90:	3c098006 */ 	lui	$t1,%hi(var800627d4)
/*  f017c94:	3c0a8006 */ 	lui	$t2,%hi(var800627e0)
/*  f017c98:	3c0c8006 */ 	lui	$t4,%hi(var800627f0)
/*  f017c9c:	3c0d8006 */ 	lui	$t5,%hi(var80062800)
/*  f017ca0:	3c1f8006 */ 	lui	$ra,%hi(var800627d8)
/*  f017ca4:	44809000 */ 	mtc1	$zero,$f18
/*  f017ca8:	27ff27d8 */ 	addiu	$ra,$ra,%lo(var800627d8)
/*  f017cac:	25ad2800 */ 	addiu	$t5,$t5,%lo(var80062800)
/*  f017cb0:	258c27f0 */ 	addiu	$t4,$t4,%lo(var800627f0)
/*  f017cb4:	254a27e0 */ 	addiu	$t2,$t2,%lo(var800627e0)
/*  f017cb8:	252927d4 */ 	addiu	$t1,$t1,%lo(var800627d4)
/*  f017cbc:	10400009 */ 	beqz	$v0,.L0f017ce4
/*  f017cc0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017cc4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f017cc8:	29c10004 */ 	slti	$at,$t6,0x4
/*  f017ccc:	14200005 */ 	bnez	$at,.L0f017ce4
/*  f017cd0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f017cd4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f017cd8:	3c018006 */ 	lui	$at,%hi(var800627d0)
/*  f017cdc:	ac2327d0 */ 	sw	$v1,%lo(var800627d0)($at)
/*  f017ce0:	ad230000 */ 	sw	$v1,0x0($t1)
.L0f017ce4:
/*  f017ce4:	3c198006 */ 	lui	$t9,%hi(var800627e4)
/*  f017ce8:	8f3927e4 */ 	lw	$t9,%lo(var800627e4)($t9)
/*  f017cec:	3c018006 */ 	lui	$at,0x8006
/*  f017cf0:	13200049 */ 	beqz	$t9,.L0f017e18
/*  f017cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017cf8:	c42027a8 */ 	lwc1	$f0,0x27a8($at)
/*  f017cfc:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017d00:	3c048006 */ 	lui	$a0,%hi(var800627a8)
/*  f017d04:	3c068006 */ 	lui	$a2,%hi(var800627ac)
/*  f017d08:	4602003c */ 	c.lt.s	$f0,$f2
/*  f017d0c:	3c017f1b */ 	lui	$at,%hi(var7f1a841c)
/*  f017d10:	24c627ac */ 	addiu	$a2,$a2,%lo(var800627ac)
/*  f017d14:	248427a8 */ 	addiu	$a0,$a0,%lo(var800627a8)
/*  f017d18:	45020038 */ 	bc1fl	.L0f017dfc
/*  f017d1c:	4600103e */ 	c.le.s	$f2,$f0
/*  f017d20:	c420841c */ 	lwc1	$f0,%lo(var7f1a841c)($at)
/*  f017d24:	3c017f1b */ 	lui	$at,%hi(var7f1a8420)
/*  f017d28:	c42a8420 */ 	lwc1	$f10,%lo(var7f1a8420)($at)
/*  f017d2c:	44051000 */ 	mfc1	$a1,$f2
/*  f017d30:	44070000 */ 	mfc1	$a3,$f0
/*  f017d34:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017d38:	0fc1b643 */ 	jal	func0f06d90c
/*  f017d3c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017d40:	3c028006 */ 	lui	$v0,%hi(var800627a8)
/*  f017d44:	3c0b8006 */ 	lui	$t3,%hi(var800627c4)
/*  f017d48:	256b27c4 */ 	addiu	$t3,$t3,%lo(var800627c4)
/*  f017d4c:	244227a8 */ 	addiu	$v0,$v0,%lo(var800627a8)
/*  f017d50:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017d54:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017d58:	3c098006 */ 	lui	$t1,%hi(var800627d4)
/*  f017d5c:	3c0a8006 */ 	lui	$t2,%hi(var800627e0)
/*  f017d60:	4600103e */ 	c.le.s	$f2,$f0
/*  f017d64:	3c0c8006 */ 	lui	$t4,%hi(var800627f0)
/*  f017d68:	3c0d8006 */ 	lui	$t5,%hi(var80062800)
/*  f017d6c:	3c1f8006 */ 	lui	$ra,%hi(var800627d8)
/*  f017d70:	44809000 */ 	mtc1	$zero,$f18
/*  f017d74:	27ff27d8 */ 	addiu	$ra,$ra,%lo(var800627d8)
/*  f017d78:	25ad2800 */ 	addiu	$t5,$t5,%lo(var80062800)
/*  f017d7c:	258c27f0 */ 	addiu	$t4,$t4,%lo(var800627f0)
/*  f017d80:	254a27e0 */ 	addiu	$t2,$t2,%lo(var800627e0)
/*  f017d84:	45000005 */ 	bc1f	.L0f017d9c
/*  f017d88:	252927d4 */ 	addiu	$t1,$t1,%lo(var800627d4)
/*  f017d8c:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f017d90:	3c018006 */ 	lui	$at,0x8006
/*  f017d94:	e43227ac */ 	swc1	$f18,0x27ac($at)
/*  f017d98:	c4400000 */ 	lwc1	$f0,0x0($v0)
.L0f017d9c:
/*  f017d9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8424)
/*  f017da0:	c42c8424 */ 	lwc1	$f12,%lo(var7f1a8424)($at)
/*  f017da4:	4600603e */ 	c.le.s	$f12,$f0
/*  f017da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017dac:	45020009 */ 	bc1fl	.L0f017dd4
/*  f017db0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017db4:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f017db8:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f017dbc:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017dc0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017dc4:	e5660000 */ 	swc1	$f6,0x0($t3)
/*  f017dc8:	1000000b */ 	beqz	$zero,.L0f017df8
/*  f017dcc:	c5620000 */ 	lwc1	$f2,0x0($t3)
/*  f017dd0:	4612003c */ 	c.lt.s	$f0,$f18
.L0f017dd4:
/*  f017dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017dd8:	45020008 */ 	bc1fl	.L0f017dfc
/*  f017ddc:	4600103e */ 	c.le.s	$f2,$f0
/*  f017de0:	460c0200 */ 	add.s	$f8,$f0,$f12
/*  f017de4:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f017de8:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f017dec:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017df0:	e56a0000 */ 	swc1	$f10,0x0($t3)
/*  f017df4:	c5620000 */ 	lwc1	$f2,0x0($t3)
.L0f017df8:
/*  f017df8:	4600103e */ 	c.le.s	$f2,$f0
.L0f017dfc:
/*  f017dfc:	3c013f80 */ 	lui	$at,0x3f80
/*  f017e00:	44817000 */ 	mtc1	$at,$f14
/*  f017e04:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f017e08:	45000021 */ 	bc1f	.L0f017e90
/*  f017e0c:	3c018006 */ 	lui	$at,%hi(var800627e4)
/*  f017e10:	1000001f */ 	beqz	$zero,.L0f017e90
/*  f017e14:	ac2027e4 */ 	sw	$zero,%lo(var800627e4)($at)
.L0f017e18:
/*  f017e18:	3c0f8006 */ 	lui	$t7,%hi(var800627d0)
/*  f017e1c:	8def27d0 */ 	lw	$t7,%lo(var800627d0)($t7)
/*  f017e20:	11e0001b */ 	beqz	$t7,.L0f017e90
/*  f017e24:	3c017f1b */ 	lui	$at,%hi(var7f1a842c)
/*  f017e28:	c42c842c */ 	lwc1	$f12,%lo(var7f1a842c)($at)
/*  f017e2c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017e30:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f017e34:	3c018006 */ 	lui	$at,0x8006
/*  f017e38:	c42427ac */ 	lwc1	$f4,0x27ac($at)
/*  f017e3c:	c506004c */ 	lwc1	$f6,0x4c($t0)
/*  f017e40:	3c028006 */ 	lui	$v0,%hi(var800627a8)
/*  f017e44:	244227a8 */ 	addiu	$v0,$v0,%lo(var800627a8)
/*  f017e48:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f017e4c:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f017e50:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f017e54:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f017e58:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f017e5c:	4600603e */ 	c.le.s	$f12,$f0
/*  f017e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017e64:	45020005 */ 	bc1fl	.L0f017e7c
/*  f017e68:	4612003c */ 	c.lt.s	$f0,$f18
/*  f017e6c:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f017e70:	10000007 */ 	beqz	$zero,.L0f017e90
/*  f017e74:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f017e78:	4612003c */ 	c.lt.s	$f0,$f18
.L0f017e7c:
/*  f017e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017e80:	45020004 */ 	bc1fl	.L0f017e94
/*  f017e84:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f017e88:	460c0280 */ 	add.s	$f10,$f0,$f12
/*  f017e8c:	e44a0000 */ 	swc1	$f10,0x0($v0)
.L0f017e90:
/*  f017e90:	8d220000 */ 	lw	$v0,0x0($t1)
.L0f017e94:
/*  f017e94:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017e98:	3c0b8006 */ 	lui	$t3,%hi(var800627c4)
/*  f017e9c:	3c017f1b */ 	lui	$at,%hi(var7f1a8430)
/*  f017ea0:	c42c8430 */ 	lwc1	$f12,%lo(var7f1a8430)($at)
/*  f017ea4:	256b27c4 */ 	addiu	$t3,$t3,%lo(var800627c4)
/*  f017ea8:	1040001a */ 	beqz	$v0,.L0f017f14
/*  f017eac:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f017eb0:	8d0e0038 */ 	lw	$t6,0x38($t0)
/*  f017eb4:	24190050 */ 	addiu	$t9,$zero,0x50
/*  f017eb8:	3c018006 */ 	lui	$at,0x8006
/*  f017ebc:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f017ec0:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f017ec4:	1b000009 */ 	blez	$t8,.L0f017eec
/*  f017ec8:	03001025 */ 	or	$v0,$t8,$zero
/*  f017ecc:	44824000 */ 	mtc1	$v0,$f8
/*  f017ed0:	44993000 */ 	mtc1	$t9,$f6
/*  f017ed4:	3c018006 */ 	lui	$at,0x8006
/*  f017ed8:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f017edc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f017ee0:	460a2203 */ 	div.s	$f8,$f4,$f10
/*  f017ee4:	10000002 */ 	beqz	$zero,.L0f017ef0
/*  f017ee8:	e42827bc */ 	swc1	$f8,0x27bc($at)
.L0f017eec:
/*  f017eec:	e43227bc */ 	swc1	$f18,0x27bc($at)
.L0f017ef0:
/*  f017ef0:	28410051 */ 	slti	$at,$v0,0x51
/*  f017ef4:	54200008 */ 	bnezl	$at,.L0f017f18
/*  f017ef8:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f017efc:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017f00:	afe30000 */ 	sw	$v1,0x0($ra)
/*  f017f04:	3c018006 */ 	lui	$at,0x8006
/*  f017f08:	e43227bc */ 	swc1	$f18,0x27bc($at)
/*  f017f0c:	3c018006 */ 	lui	$at,%hi(var800627c0)
/*  f017f10:	ac2327c0 */ 	sw	$v1,%lo(var800627c0)($at)
.L0f017f14:
/*  f017f14:	8fef0000 */ 	lw	$t7,0x0($ra)
.L0f017f18:
/*  f017f18:	11e00019 */ 	beqz	$t7,.L0f017f80
/*  f017f1c:	3c017f1b */ 	lui	$at,%hi(var7f1a8434)
/*  f017f20:	c4268434 */ 	lwc1	$f6,%lo(var7f1a8434)($at)
/*  f017f24:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f017f28:	3c018006 */ 	lui	$at,0x8006
/*  f017f2c:	c42827bc */ 	lwc1	$f8,0x27bc($at)
/*  f017f30:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f017f34:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f017f38:	e42027bc */ 	swc1	$f0,0x27bc($at)
/*  f017f3c:	3c017f1b */ 	lui	$at,%hi(var7f1a8438)
/*  f017f40:	c4248438 */ 	lwc1	$f4,%lo(var7f1a8438)($at)
/*  f017f44:	3c018006 */ 	lui	$at,0x8006
/*  f017f48:	4600203e */ 	c.le.s	$f4,$f0
/*  f017f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017f50:	45020006 */ 	bc1fl	.L0f017f6c
/*  f017f54:	4600703e */ 	c.le.s	$f14,$f0
/*  f017f58:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f017f5c:	55c00003 */ 	bnezl	$t6,.L0f017f6c
/*  f017f60:	4600703e */ 	c.le.s	$f14,$f0
/*  f017f64:	ad430000 */ 	sw	$v1,0x0($t2)
/*  f017f68:	4600703e */ 	c.le.s	$f14,$f0
.L0f017f6c:
/*  f017f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017f70:	45020004 */ 	bc1fl	.L0f017f84
/*  f017f74:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f017f78:	e42e27bc */ 	swc1	$f14,0x27bc($at)
/*  f017f7c:	afe00000 */ 	sw	$zero,0x0($ra)
.L0f017f80:
/*  f017f80:	8d430000 */ 	lw	$v1,0x0($t2)
.L0f017f84:
/*  f017f84:	10600064 */ 	beqz	$v1,.L0f018118
/*  f017f88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017f8c:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f017f90:	3c018006 */ 	lui	$at,0x8006
/*  f017f94:	3c048006 */ 	lui	$a0,%hi(var800627b0)
/*  f017f98:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f017f9c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f017fa0:	c42827b0 */ 	lwc1	$f8,0x27b0($at)
/*  f017fa4:	3c068006 */ 	lui	$a2,%hi(var800627b4)
/*  f017fa8:	3c017f1b */ 	lui	$at,%hi(var7f1a843c)
/*  f017fac:	4608903c */ 	c.lt.s	$f18,$f8
/*  f017fb0:	24c627b4 */ 	addiu	$a2,$a2,%lo(var800627b4)
/*  f017fb4:	248427b0 */ 	addiu	$a0,$a0,%lo(var800627b0)
/*  f017fb8:	4502001f */ 	bc1fl	.L0f018038
/*  f017fbc:	8d430000 */ 	lw	$v1,0x0($t2)
/*  f017fc0:	c420843c */ 	lwc1	$f0,%lo(var7f1a843c)($at)
/*  f017fc4:	3c017f1b */ 	lui	$at,%hi(var7f1a8440)
/*  f017fc8:	c42a8440 */ 	lwc1	$f10,%lo(var7f1a8440)($at)
/*  f017fcc:	44059000 */ 	mfc1	$a1,$f18
/*  f017fd0:	44070000 */ 	mfc1	$a3,$f0
/*  f017fd4:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f017fd8:	0fc1b6c0 */ 	jal	func0f06db00
/*  f017fdc:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f017fe0:	3c017f1b */ 	lui	$at,%hi(var7f1a8444)
/*  f017fe4:	c42c8444 */ 	lwc1	$f12,%lo(var7f1a8444)($at)
/*  f017fe8:	3c018006 */ 	lui	$at,0x8006
/*  f017fec:	44809000 */ 	mtc1	$zero,$f18
/*  f017ff0:	c42627b0 */ 	lwc1	$f6,0x27b0($at)
/*  f017ff4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f017ff8:	3c0a8006 */ 	lui	$t2,%hi(var800627e0)
/*  f017ffc:	4612303e */ 	c.le.s	$f6,$f18
/*  f018000:	3c0b8006 */ 	lui	$t3,%hi(var800627c4)
/*  f018004:	3c0c8006 */ 	lui	$t4,%hi(var800627f0)
/*  f018008:	3c0d8006 */ 	lui	$t5,%hi(var80062800)
/*  f01800c:	25ad2800 */ 	addiu	$t5,$t5,%lo(var80062800)
/*  f018010:	258c27f0 */ 	addiu	$t4,$t4,%lo(var800627f0)
/*  f018014:	256b27c4 */ 	addiu	$t3,$t3,%lo(var800627c4)
/*  f018018:	254a27e0 */ 	addiu	$t2,$t2,%lo(var800627e0)
/*  f01801c:	45000005 */ 	bc1f	.L0f018034
/*  f018020:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f018024:	3c018006 */ 	lui	$at,0x8006
/*  f018028:	e43227b0 */ 	swc1	$f18,0x27b0($at)
/*  f01802c:	3c018006 */ 	lui	$at,0x8006
/*  f018030:	e43227b4 */ 	swc1	$f18,0x27b4($at)
.L0f018034:
/*  f018034:	8d430000 */ 	lw	$v1,0x0($t2)
.L0f018038:
/*  f018038:	3c013f80 */ 	lui	$at,0x3f80
/*  f01803c:	44817000 */ 	mtc1	$at,$f14
/*  f018040:	2861001f */ 	slti	$at,$v1,0x1f
/*  f018044:	1420001c */ 	bnez	$at,.L0f0180b8
/*  f018048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01804c:	8d0f0038 */ 	lw	$t7,0x38($t0)
/*  f018050:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f018054:	006f7023 */ 	subu	$t6,$v1,$t7
/*  f018058:	29c1001f */ 	slti	$at,$t6,0x1f
/*  f01805c:	10200016 */ 	beqz	$at,.L0f0180b8
/*  f018060:	3c018006 */ 	lui	$at,%hi(var800627d0)
/*  f018064:	ac2027d0 */ 	sw	$zero,%lo(var800627d0)($at)
/*  f018068:	3c018006 */ 	lui	$at,%hi(var800627e4)
/*  f01806c:	ac2427e4 */ 	sw	$a0,%lo(var800627e4)($at)
/*  f018070:	3c018006 */ 	lui	$at,0x8006
/*  f018074:	c42427a8 */ 	lwc1	$f4,0x27a8($at)
/*  f018078:	3c014080 */ 	lui	$at,0x4080
/*  f01807c:	44814000 */ 	mtc1	$at,$f8
/*  f018080:	3c013e80 */ 	lui	$at,0x3e80
/*  f018084:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f018088:	460c5183 */ 	div.s	$f6,$f10,$f12
/*  f01808c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f018090:	44022000 */ 	mfc1	$v0,$f4
/*  f018094:	44812000 */ 	mtc1	$at,$f4
/*  f018098:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01809c:	44824000 */ 	mtc1	$v0,$f8
/*  f0180a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0180a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0180a8:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f0180ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0180b0:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0180b4:	e5680000 */ 	swc1	$f8,0x0($t3)
.L0f0180b8:
/*  f0180b8:	3c028006 */ 	lui	$v0,%hi(var800627e4)
/*  f0180bc:	28610065 */ 	slti	$at,$v1,0x65
/*  f0180c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0180c4:	14200009 */ 	bnez	$at,.L0f0180ec
/*  f0180c8:	8c4227e4 */ 	lw	$v0,%lo(var800627e4)($v0)
/*  f0180cc:	8d190038 */ 	lw	$t9,0x38($t0)
/*  f0180d0:	3c058006 */ 	lui	$a1,%hi(var800627e8)
/*  f0180d4:	24a527e8 */ 	addiu	$a1,$a1,%lo(var800627e8)
/*  f0180d8:	00797823 */ 	subu	$t7,$v1,$t9
/*  f0180dc:	29e10065 */ 	slti	$at,$t7,0x65
/*  f0180e0:	10200002 */ 	beqz	$at,.L0f0180ec
/*  f0180e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0180e8:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f0180ec:
/*  f0180ec:	3c058006 */ 	lui	$a1,%hi(var800627e8)
/*  f0180f0:	14400009 */ 	bnez	$v0,.L0f018118
/*  f0180f4:	24a527e8 */ 	addiu	$a1,$a1,%lo(var800627e8)
/*  f0180f8:	3c018006 */ 	lui	$at,0x8006
/*  f0180fc:	c42a27b0 */ 	lwc1	$f10,0x27b0($at)
/*  f018100:	4612503e */ 	c.le.s	$f10,$f18
/*  f018104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018108:	45000003 */ 	bc1f	.L0f018118
/*  f01810c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018110:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f018114:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f018118:
/*  f018118:	3c058006 */ 	lui	$a1,%hi(var800627e8)
/*  f01811c:	24a527e8 */ 	addiu	$a1,$a1,%lo(var800627e8)
/*  f018120:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f018124:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f018128:	3c0f8006 */ 	lui	$t7,%hi(var8006280c)
/*  f01812c:	11c00012 */ 	beqz	$t6,.L0f018178
/*  f018130:	3c017f1b */ 	lui	$at,%hi(var7f1a8448)
/*  f018134:	c4268448 */ 	lwc1	$f6,%lo(var7f1a8448)($at)
/*  f018138:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f01813c:	3c038006 */ 	lui	$v1,%hi(var800627c8)
/*  f018140:	246327c8 */ 	addiu	$v1,$v1,%lo(var800627c8)
/*  f018144:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f018148:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f01814c:	3c018006 */ 	lui	$at,0x8006
/*  f018150:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f018154:	e42627c8 */ 	swc1	$f6,0x27c8($at)
/*  f018158:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f01815c:	4612203e */ 	c.le.s	$f4,$f18
/*  f018160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018164:	45020005 */ 	bc1fl	.L0f01817c
/*  f018168:	8d820000 */ 	lw	$v0,0x0($t4)
/*  f01816c:	e4720000 */ 	swc1	$f18,0x0($v1)
/*  f018170:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f018174:	ad840000 */ 	sw	$a0,0x0($t4)
.L0f018178:
/*  f018178:	8d820000 */ 	lw	$v0,0x0($t4)
.L0f01817c:
/*  f01817c:	3c0e8006 */ 	lui	$t6,%hi(var800627ec)
/*  f018180:	10400009 */ 	beqz	$v0,.L0f0181a8
/*  f018184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018188:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01818c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018190:	2b210015 */ 	slti	$at,$t9,0x15
/*  f018194:	14200004 */ 	bnez	$at,.L0f0181a8
/*  f018198:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f01819c:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f0181a0:	3c018006 */ 	lui	$at,%hi(var800627ec)
/*  f0181a4:	ac2427ec */ 	sw	$a0,%lo(var800627ec)($at)
.L0f0181a8:
/*  f0181a8:	8dce27ec */ 	lw	$t6,%lo(var800627ec)($t6)
/*  f0181ac:	3c018006 */ 	lui	$at,%hi(var800627ec)
/*  f0181b0:	51c00004 */ 	beqzl	$t6,.L0f0181c4
/*  f0181b4:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f0181b8:	ac2027ec */ 	sw	$zero,%lo(var800627ec)($at)
/*  f0181bc:	ada40000 */ 	sw	$a0,0x0($t5)
/*  f0181c0:	8da20000 */ 	lw	$v0,0x0($t5)
.L0f0181c4:
/*  f0181c4:	3c018006 */ 	lui	$at,%hi(var8006280c)
/*  f0181c8:	1040000f */ 	beqz	$v0,.L0f018208
/*  f0181cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0181d0:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f0181d4:	3c068006 */ 	lui	$a2,%hi(var80062810)
/*  f0181d8:	24c62810 */ 	addiu	$a2,$a2,%lo(var80062810)
/*  f0181dc:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0181e0:	1b200009 */ 	blez	$t9,.L0f018208
/*  f0181e4:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f0181e8:	3c078006 */ 	lui	$a3,%hi(var800627fc)
/*  f0181ec:	3c098006 */ 	lui	$t1,%hi(var800627f8)
/*  f0181f0:	252927f8 */ 	addiu	$t1,$t1,%lo(var800627f8)
/*  f0181f4:	24e727fc */ 	addiu	$a3,$a3,%lo(var800627fc)
/*  f0181f8:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f0181fc:	ace40000 */ 	sw	$a0,0x0($a3)
/*  f018200:	ad240000 */ 	sw	$a0,0x0($t1)
/*  f018204:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f018208:
/*  f018208:	3c078006 */ 	lui	$a3,%hi(var800627fc)
/*  f01820c:	24e727fc */ 	addiu	$a3,$a3,%lo(var800627fc)
/*  f018210:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f018214:	3c068006 */ 	lui	$a2,%hi(var80062810)
/*  f018218:	3c098006 */ 	lui	$t1,%hi(var800627f8)
/*  f01821c:	252927f8 */ 	addiu	$t1,$t1,%lo(var800627f8)
/*  f018220:	11c0002c */ 	beqz	$t6,.L0f0182d4
/*  f018224:	24c62810 */ 	addiu	$a2,$a2,%lo(var80062810)
/*  f018228:	ac24280c */ 	sw	$a0,%lo(var8006280c)($at)
/*  f01822c:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f018230:	3c018006 */ 	lui	$at,0x8006
/*  f018234:	14400008 */ 	bnez	$v0,.L0f018258
/*  f018238:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f01823c:	c42a27f4 */ 	lwc1	$f10,0x27f4($at)
/*  f018240:	3c017f1b */ 	lui	$at,%hi(var7f1a844c)
/*  f018244:	c428844c */ 	lwc1	$f8,%lo(var7f1a844c)($at)
/*  f018248:	3c018006 */ 	lui	$at,0x8006
/*  f01824c:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f018250:	10000011 */ 	beqz	$zero,.L0f018298
/*  f018254:	e42627f4 */ 	swc1	$f6,0x27f4($at)
.L0f018258:
/*  f018258:	14820009 */ 	bne	$a0,$v0,.L0f018280
/*  f01825c:	3c018006 */ 	lui	$at,0x8006
/*  f018260:	3c018006 */ 	lui	$at,0x8006
/*  f018264:	c42427f4 */ 	lwc1	$f4,0x27f4($at)
/*  f018268:	3c017f1b */ 	lui	$at,%hi(var7f1a8450)
/*  f01826c:	c42a8450 */ 	lwc1	$f10,%lo(var7f1a8450)($at)
/*  f018270:	3c018006 */ 	lui	$at,0x8006
/*  f018274:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f018278:	10000007 */ 	beqz	$zero,.L0f018298
/*  f01827c:	e42827f4 */ 	swc1	$f8,0x27f4($at)
.L0f018280:
/*  f018280:	c42627f4 */ 	lwc1	$f6,0x27f4($at)
/*  f018284:	3c017f1b */ 	lui	$at,%hi(var7f1a8454)
/*  f018288:	c4248454 */ 	lwc1	$f4,%lo(var7f1a8454)($at)
/*  f01828c:	3c018006 */ 	lui	$at,0x8006
/*  f018290:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f018294:	e42a27f4 */ 	swc1	$f10,0x27f4($at)
.L0f018298:
/*  f018298:	3c018006 */ 	lui	$at,0x8006
/*  f01829c:	c42827f4 */ 	lwc1	$f8,0x27f4($at)
/*  f0182a0:	3c018006 */ 	lui	$at,0x8006
/*  f0182a4:	4608703e */ 	c.le.s	$f14,$f8
/*  f0182a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0182ac:	45000009 */ 	bc1f	.L0f0182d4
/*  f0182b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0182b4:	e43227f4 */ 	swc1	$f18,0x27f4($at)
/*  f0182b8:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0182bc:	17010005 */ 	bne	$t8,$at,.L0f0182d4
/*  f0182c0:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f0182c4:	3c058006 */ 	lui	$a1,%hi(var800627dc)
/*  f0182c8:	24a527dc */ 	addiu	$a1,$a1,%lo(var800627dc)
/*  f0182cc:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0182d0:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f0182d4:
/*  f0182d4:	8def280c */ 	lw	$t7,%lo(var8006280c)($t7)
/*  f0182d8:	3c058006 */ 	lui	$a1,%hi(var800627dc)
/*  f0182dc:	24a527dc */ 	addiu	$a1,$a1,%lo(var800627dc)
/*  f0182e0:	11e00012 */ 	beqz	$t7,.L0f01832c
/*  f0182e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0182e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8458)
/*  f0182ec:	c4268458 */ 	lwc1	$f6,%lo(var7f1a8458)($at)
/*  f0182f0:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0182f4:	3c028006 */ 	lui	$v0,%hi(var80062808)
/*  f0182f8:	24422808 */ 	addiu	$v0,$v0,%lo(var80062808)
/*  f0182fc:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f018300:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f018304:	3c018006 */ 	lui	$at,0x8006
/*  f018308:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f01830c:	e4262808 */ 	swc1	$f6,0x2808($at)
/*  f018310:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f018314:	4600603e */ 	c.le.s	$f12,$f0
/*  f018318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01831c:	45020004 */ 	bc1fl	.L0f018330
/*  f018320:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f018324:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f018328:	e4440000 */ 	swc1	$f4,0x0($v0)
.L0f01832c:
/*  f01832c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f018330:
/*  f018330:	3c017f1b */ 	lui	$at,%hi(var7f1a845c)
/*  f018334:	51c00012 */ 	beqzl	$t6,.L0f018380
/*  f018338:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f01833c:	c428845c */ 	lwc1	$f8,%lo(var7f1a845c)($at)
/*  f018340:	c50a004c */ 	lwc1	$f10,0x4c($t0)
/*  f018344:	3c0a8006 */ 	lui	$t2,%hi(var80062814)
/*  f018348:	254a2814 */ 	addiu	$t2,$t2,%lo(var80062814)
/*  f01834c:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f018350:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f018354:	3c018006 */ 	lui	$at,0x8006
/*  f018358:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f01835c:	e4282814 */ 	swc1	$f8,0x2814($at)
/*  f018360:	c54a0000 */ 	lwc1	$f10,0x0($t2)
/*  f018364:	460a703e */ 	c.le.s	$f14,$f10
/*  f018368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01836c:	45020004 */ 	bc1fl	.L0f018380
/*  f018370:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f018374:	e54e0000 */ 	swc1	$f14,0x0($t2)
/*  f018378:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f01837c:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f018380:
/*  f018380:	00003025 */ 	or	$a2,$zero,$zero
/*  f018384:	5040000a */ 	beqzl	$v0,.L0f0183b0
/*  f018388:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f01838c:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f018390:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018394:	2b21003d */ 	slti	$at,$t9,0x3d
/*  f018398:	14200004 */ 	bnez	$at,.L0f0183ac
/*  f01839c:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0183a0:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0183a4:	3c018006 */ 	lui	$at,%hi(var80062734)
/*  f0183a8:	ac242734 */ 	sw	$a0,%lo(var80062734)($at)
.L0f0183ac:
/*  f0183ac:	8fa40330 */ 	lw	$a0,0x330($sp)
.L0f0183b0:
/*  f0183b0:	0c002fc1 */ 	jal	func0000bf04
/*  f0183b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0183b8:	0c002cb1 */ 	jal	func0000b2c4
/*  f0183bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0183c0:	3c0e8006 */ 	lui	$t6,%hi(var800627cc)
/*  f0183c4:	8dce27cc */ 	lw	$t6,%lo(var800627cc)($t6)
/*  f0183c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0183cc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0183d0:	11c00003 */ 	beqz	$t6,.L0f0183e0
/*  f0183d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0183d8:	10000272 */ 	beqz	$zero,.L0f018da4
/*  f0183dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0183e0:
/*  f0183e0:	0fc59e6c */ 	jal	func0f1679b0
/*  f0183e4:	afa30330 */ 	sw	$v1,0x330($sp)
/*  f0183e8:	44809000 */ 	mtc1	$zero,$f18
/*  f0183ec:	3c01457a */ 	lui	$at,0x457a
/*  f0183f0:	44812000 */ 	mtc1	$at,$f4
/*  f0183f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0183f8:	44813000 */ 	mtc1	$at,$f6
/*  f0183fc:	44069000 */ 	mfc1	$a2,$f18
/*  f018400:	44079000 */ 	mfc1	$a3,$f18
/*  f018404:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f018408:	00402825 */ 	or	$a1,$v0,$zero
/*  f01840c:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f018410:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f018414:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018418:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f01841c:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f018420:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f018424:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f018428:	0c0011c3 */ 	jal	func0000470c
/*  f01842c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f018430:	8fa30330 */ 	lw	$v1,0x330($sp)
/*  f018434:	3c017f1b */ 	lui	$at,%hi(var7f1a8460)
/*  f018438:	c4228460 */ 	lwc1	$f2,%lo(var7f1a8460)($at)
/*  f01843c:	8fa80134 */ 	lw	$t0,0x134($sp)
/*  f018440:	3c180384 */ 	lui	$t8,0x384
/*  f018444:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018448:	3c190382 */ 	lui	$t9,0x382
/*  f01844c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f018450:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f018454:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f018458:	37390010 */ 	ori	$t9,$t9,0x10
/*  f01845c:	250f0010 */ 	addiu	$t7,$t0,0x10
/*  f018460:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f018464:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f018468:	3c018006 */ 	lui	$at,0x8006
/*  f01846c:	c4202814 */ 	lwc1	$f0,0x2814($at)
/*  f018470:	3c01bf80 */ 	lui	$at,0xbf80
/*  f018474:	44814000 */ 	mtc1	$at,$f8
/*  f018478:	3c017f1b */ 	lui	$at,%hi(var7f1a8464)
/*  f01847c:	c42a8464 */ 	lwc1	$f10,%lo(var7f1a8464)($at)
/*  f018480:	46080380 */ 	add.s	$f14,$f0,$f8
/*  f018484:	44809000 */ 	mtc1	$zero,$f18
/*  f018488:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f01848c:	3c058006 */ 	lui	$a1,%hi(var80062578)
/*  f018490:	24a52578 */ 	addiu	$a1,$a1,%lo(var80062578)
/*  f018494:	46027182 */ 	mul.s	$f6,$f14,$f2
/*  f018498:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f01849c:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f0184a0:	a0a00006 */ 	sb	$zero,0x6($a1)
/*  f0184a4:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0184a8:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0184ac:	a0a00004 */ 	sb	$zero,0x4($a1)
/*  f0184b0:	a0a00002 */ 	sb	$zero,0x2($a1)
/*  f0184b4:	46023300 */ 	add.s	$f12,$f6,$f2
/*  f0184b8:	46028202 */ 	mul.s	$f8,$f16,$f2
/*  f0184bc:	a0a00001 */ 	sb	$zero,0x1($a1)
/*  f0184c0:	a0a00000 */ 	sb	$zero,0x0($a1)
/*  f0184c4:	a0a2000e */ 	sb	$v0,0xe($a1)
/*  f0184c8:	a0a2000d */ 	sb	$v0,0xd($a1)
/*  f0184cc:	a0a2000c */ 	sb	$v0,0xc($a1)
/*  f0184d0:	a0a2000a */ 	sb	$v0,0xa($a1)
/*  f0184d4:	46024400 */ 	add.s	$f16,$f8,$f2
/*  f0184d8:	a0a20009 */ 	sb	$v0,0x9($a1)
/*  f0184dc:	a0a20008 */ 	sb	$v0,0x8($a1)
/*  f0184e0:	e7ac00e4 */ 	swc1	$f12,0xe4($sp)
/*  f0184e4:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*  f0184e8:	0c0068f7 */ 	jal	sinf
/*  f0184ec:	afa60330 */ 	sw	$a2,0x330($sp)
/*  f0184f0:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0184f4:	0c0068f4 */ 	jal	cosf
/*  f0184f8:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0184fc:	3c0142fe */ 	lui	$at,0x42fe
/*  f018500:	44815000 */ 	mtc1	$at,$f10
/*  f018504:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018508:	3c018006 */ 	lui	$at,%hi(var80062588)
/*  f01850c:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f018510:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018518:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f01851c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f018520:	44195000 */ 	mfc1	$t9,$f10
/*  f018524:	0c0068f7 */ 	jal	sinf
/*  f018528:	a0392588 */ 	sb	$t9,%lo(var80062588)($at)
/*  f01852c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018530:	44812000 */ 	mtc1	$at,$f4
/*  f018534:	3c018006 */ 	lui	$at,%hi(var80062588+0x1)
/*  f018538:	c7ac00e4 */ 	lwc1	$f12,0xe4($sp)
/*  f01853c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f018540:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f018544:	440e4000 */ 	mfc1	$t6,$f8
/*  f018548:	0c0068f4 */ 	jal	cosf
/*  f01854c:	a02e2589 */ 	sb	$t6,%lo(var80062588+0x1)($at)
/*  f018550:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f018554:	0c0068f4 */ 	jal	cosf
/*  f018558:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f01855c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018560:	44815000 */ 	mtc1	$at,$f10
/*  f018564:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018568:	44809000 */ 	mtc1	$zero,$f18
/*  f01856c:	3c018006 */ 	lui	$at,%hi(var80062588+0x2)
/*  f018570:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018574:	44059000 */ 	mfc1	$a1,$f18
/*  f018578:	44069000 */ 	mfc1	$a2,$f18
/*  f01857c:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018580:	3c07457a */ 	lui	$a3,0x457a
/*  f018584:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f018588:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f01858c:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f018590:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f018594:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f018598:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f01859c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0185a0:	44195000 */ 	mfc1	$t9,$f10
/*  f0185a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0185a8:	a039258a */ 	sb	$t9,%lo(var80062588+0x2)($at)
/*  f0185ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0185b0:	44812000 */ 	mtc1	$at,$f4
/*  f0185b4:	0c005ab9 */ 	jal	func00016ae4
/*  f0185b8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0185bc:	3c0f8006 */ 	lui	$t7,%hi(var800627c0)
/*  f0185c0:	8def27c0 */ 	lw	$t7,%lo(var800627c0)($t7)
/*  f0185c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0185c8:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0185cc:	15e10004 */ 	bne	$t7,$at,.L0f0185e0
/*  f0185d0:	3c0e8006 */ 	lui	$t6,%hi(g_TitleModel)
/*  f0185d4:	8dce24f8 */ 	lw	$t6,%lo(g_TitleModel)($t6)
/*  f0185d8:	10000004 */ 	beqz	$zero,.L0f0185ec
/*  f0185dc:	afae022c */ 	sw	$t6,0x22c($sp)
.L0f0185e0:
/*  f0185e0:	3c188006 */ 	lui	$t8,%hi(g_TitleModel2)
/*  f0185e4:	8f1824fc */ 	lw	$t8,%lo(g_TitleModel2)($t8)
/*  f0185e8:	afb8022c */ 	sw	$t8,0x22c($sp)
.L0f0185ec:
/*  f0185ec:	3c018006 */ 	lui	$at,0x8006
/*  f0185f0:	0c0058dd */ 	jal	func00016374
/*  f0185f4:	c42c27a8 */ 	lwc1	$f12,0x27a8($at)
/*  f0185f8:	3c018006 */ 	lui	$at,0x8006
/*  f0185fc:	c42c27b0 */ 	lwc1	$f12,0x27b0($at)
/*  f018600:	0c0058ba */ 	jal	func000162e8
/*  f018604:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f018608:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f01860c:	0c00567f */ 	jal	func000159fc
/*  f018610:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018614:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018618:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f01861c:	0c005680 */ 	jal	func00015a00
/*  f018620:	27a60270 */ 	addiu	$a2,$sp,0x270
/*  f018624:	3c018006 */ 	lui	$at,0x8006
/*  f018628:	c42c27b8 */ 	lwc1	$f12,0x27b8($at)
/*  f01862c:	0c0057c1 */ 	jal	func00015f04
/*  f018630:	27a50270 */ 	addiu	$a1,$sp,0x270
/*  f018634:	3c01437f */ 	lui	$at,0x437f
/*  f018638:	44813000 */ 	mtc1	$at,$f6
/*  f01863c:	3c018006 */ 	lui	$at,0x8006
/*  f018640:	c42827c8 */ 	lwc1	$f8,0x27c8($at)
/*  f018644:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f018648:	3c038006 */ 	lui	$v1,%hi(var80062560)
/*  f01864c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f018650:	24632560 */ 	addiu	$v1,$v1,%lo(var80062560)
/*  f018654:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f018658:	4459f800 */ 	cfc1	$t9,$31
/*  f01865c:	44c2f800 */ 	ctc1	$v0,$31
/*  f018660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018664:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f018668:	4442f800 */ 	cfc1	$v0,$31
/*  f01866c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018670:	30420078 */ 	andi	$v0,$v0,0x78
/*  f018674:	10400012 */ 	beqz	$v0,.L0f0186c0
/*  f018678:	3c014f00 */ 	lui	$at,0x4f00
/*  f01867c:	44812000 */ 	mtc1	$at,$f4
/*  f018680:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f018684:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f018688:	44c2f800 */ 	ctc1	$v0,$31
/*  f01868c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018690:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f018694:	4442f800 */ 	cfc1	$v0,$31
/*  f018698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01869c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0186a0:	14400005 */ 	bnez	$v0,.L0f0186b8
/*  f0186a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0186a8:	44022000 */ 	mfc1	$v0,$f4
/*  f0186ac:	3c018000 */ 	lui	$at,0x8000
/*  f0186b0:	10000007 */ 	beqz	$zero,.L0f0186d0
/*  f0186b4:	00411025 */ 	or	$v0,$v0,$at
.L0f0186b8:
/*  f0186b8:	10000005 */ 	beqz	$zero,.L0f0186d0
/*  f0186bc:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0186c0:
/*  f0186c0:	44022000 */ 	mfc1	$v0,$f4
/*  f0186c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0186c8:	0440fffb */ 	bltz	$v0,.L0f0186b8
/*  f0186cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0186d0:
/*  f0186d0:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f0186d4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0186d8:	a0620006 */ 	sb	$v0,0x6($v1)
/*  f0186dc:	a0620005 */ 	sb	$v0,0x5($v1)
/*  f0186e0:	a0620004 */ 	sb	$v0,0x4($v1)
/*  f0186e4:	a0620002 */ 	sb	$v0,0x2($v1)
/*  f0186e8:	a0620001 */ 	sb	$v0,0x1($v1)
/*  f0186ec:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f0186f0:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0186f4:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0186f8:	0c006a47 */ 	jal	func0001a91c
/*  f0186fc:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f018700:	10400027 */ 	beqz	$v0,.L0f0187a0
/*  f018704:	00402825 */ 	or	$a1,$v0,$zero
/*  f018708:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01870c:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f018710:	84d80010 */ 	lh	$t8,0x10($a2)
/*  f018714:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f018718:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f01871c:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f018720:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f018724:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f018728:	0c006a87 */ 	jal	func0001aa1c
/*  f01872c:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f018730:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f018734:	0fc59e7d */ 	jal	func0f1679f4
/*  f018738:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f01873c:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f018740:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018744:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018748:	af020004 */ 	sw	$v0,0x4($t8)
/*  f01874c:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018750:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018754:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018758:	3c0e0386 */ 	lui	$t6,0x386
/*  f01875c:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018760:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018764:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018768:	3c0f8006 */ 	lui	$t7,%hi(var80062530)
/*  f01876c:	3c190388 */ 	lui	$t9,0x388
/*  f018770:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018774:	3c188006 */ 	lui	$t8,%hi(var80062538)
/*  f018778:	27182538 */ 	addiu	$t8,$t8,%lo(var80062538)
/*  f01877c:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018780:	25ef2530 */ 	addiu	$t7,$t7,%lo(var80062530)
/*  f018784:	3c0e0601 */ 	lui	$t6,0x601
/*  f018788:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f01878c:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f018790:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018794:	ac4e0018 */ 	sw	$t6,0x18($v0)
/*  f018798:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f01879c:	ac58001c */ 	sw	$t8,0x1c($v0)
.L0f0187a0:
/*  f0187a0:	8fb9022c */ 	lw	$t9,0x22c($sp)
/*  f0187a4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0187a8:	0c006a47 */ 	jal	func0001a91c
/*  f0187ac:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f0187b0:	10400037 */ 	beqz	$v0,.L0f018890
/*  f0187b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0187b8:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0187bc:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f0187c0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0187c4:	84ce0010 */ 	lh	$t6,0x10($a2)
/*  f0187c8:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0187cc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0187d0:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f0187d4:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f0187d8:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f0187dc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0187e0:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0187e4:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0187e8:	0c006a87 */ 	jal	func0001aa1c
/*  f0187ec:	afb900d8 */ 	sw	$t9,0xd8($sp)
/*  f0187f0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0187f4:	0fc59e7d */ 	jal	func0f1679f4
/*  f0187f8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0187fc:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f018800:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f018804:	3c018006 */ 	lui	$at,0x8006
/*  f018808:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f01880c:	44809000 */ 	mtc1	$zero,$f18
/*  f018810:	c42627c8 */ 	lwc1	$f6,0x27c8($at)
/*  f018814:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018818:	3c188000 */ 	lui	$t8,0x8000
/*  f01881c:	4606903c */ 	c.lt.s	$f18,$f6
/*  f018820:	37180040 */ 	ori	$t8,$t8,0x40
/*  f018824:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018828:	3c190386 */ 	lui	$t9,0x386
/*  f01882c:	45000016 */ 	bc1f	.L0f018888
/*  f018830:	3c0eb800 */ 	lui	$t6,0xb800
/*  f018834:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f018838:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f01883c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f018840:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f018844:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018848:	3c0f8006 */ 	lui	$t7,%hi(var80062568)
/*  f01884c:	25ef2568 */ 	addiu	$t7,$t7,%lo(var80062568)
/*  f018850:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f018854:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f018858:	3c188006 */ 	lui	$t8,%hi(var80062560)
/*  f01885c:	3c0e0388 */ 	lui	$t6,0x388
/*  f018860:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018864:	27182560 */ 	addiu	$t8,$t8,%lo(var80062560)
/*  f018868:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f01886c:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f018870:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018874:	3c190601 */ 	lui	$t9,0x601
/*  f018878:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f01887c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f018880:	10000003 */ 	beqz	$zero,.L0f018890
/*  f018884:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f018888:
/*  f018888:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f01888c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018890:
/*  f018890:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f018894:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f018898:	0c006a47 */ 	jal	func0001a91c
/*  f01889c:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f0188a0:	10400037 */ 	beqz	$v0,.L0f018980
/*  f0188a4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0188a8:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0188ac:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f0188b0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0188b4:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f0188b8:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f0188bc:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0188c0:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0188c4:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f0188c8:	94cf0016 */ 	lhu	$t7,0x16($a2)
/*  f0188cc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0188d0:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f0188d4:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0188d8:	0c006a87 */ 	jal	func0001aa1c
/*  f0188dc:	afb800d8 */ 	sw	$t8,0xd8($sp)
/*  f0188e0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0188e4:	0fc59e7d */ 	jal	func0f1679f4
/*  f0188e8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0188ec:	8fb90160 */ 	lw	$t9,0x160($sp)
/*  f0188f0:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0188f4:	3c018006 */ 	lui	$at,0x8006
/*  f0188f8:	af220004 */ 	sw	$v0,0x4($t9)
/*  f0188fc:	44809000 */ 	mtc1	$zero,$f18
/*  f018900:	c42827c8 */ 	lwc1	$f8,0x27c8($at)
/*  f018904:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f018908:	3c0e8000 */ 	lui	$t6,0x8000
/*  f01890c:	4608903c */ 	c.lt.s	$f18,$f8
/*  f018910:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f018914:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018918:	3c180386 */ 	lui	$t8,0x386
/*  f01891c:	45000016 */ 	bc1f	.L0f018978
/*  f018920:	3c0fb800 */ 	lui	$t7,0xb800
/*  f018924:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f018928:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f01892c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f018930:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f018934:	37180010 */ 	ori	$t8,$t8,0x10
/*  f018938:	3c198006 */ 	lui	$t9,%hi(var80062568)
/*  f01893c:	27392568 */ 	addiu	$t9,$t9,%lo(var80062568)
/*  f018940:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f018944:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f018948:	3c0e8006 */ 	lui	$t6,%hi(var80062560)
/*  f01894c:	3c0f0388 */ 	lui	$t7,0x388
/*  f018950:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018954:	25ce2560 */ 	addiu	$t6,$t6,%lo(var80062560)
/*  f018958:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f01895c:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f018960:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018964:	3c180601 */ 	lui	$t8,0x601
/*  f018968:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f01896c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f018970:	10000003 */ 	beqz	$zero,.L0f018980
/*  f018974:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f018978:
/*  f018978:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f01897c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018980:
/*  f018980:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f018984:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f018988:	0c006a47 */ 	jal	func0001a91c
/*  f01898c:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f018990:	10400037 */ 	beqz	$v0,.L0f018a70
/*  f018994:	00402825 */ 	or	$a1,$v0,$zero
/*  f018998:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f01899c:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f0189a0:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f0189a4:	84d90010 */ 	lh	$t9,0x10($a2)
/*  f0189a8:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0189ac:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0189b0:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f0189b4:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f0189b8:	94d90016 */ 	lhu	$t9,0x16($a2)
/*  f0189bc:	afa60164 */ 	sw	$a2,0x164($sp)
/*  f0189c0:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0189c4:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0189c8:	0c006a87 */ 	jal	func0001aa1c
/*  f0189cc:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f0189d0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0189d4:	0fc59e7d */ 	jal	func0f1679f4
/*  f0189d8:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f0189dc:	8fb80160 */ 	lw	$t8,0x160($sp)
/*  f0189e0:	8fa60164 */ 	lw	$a2,0x164($sp)
/*  f0189e4:	3c018006 */ 	lui	$at,0x8006
/*  f0189e8:	af020004 */ 	sw	$v0,0x4($t8)
/*  f0189ec:	44809000 */ 	mtc1	$zero,$f18
/*  f0189f0:	c42a27c8 */ 	lwc1	$f10,0x27c8($at)
/*  f0189f4:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f0189f8:	3c0f8000 */ 	lui	$t7,0x8000
/*  f0189fc:	460a903c */ 	c.lt.s	$f18,$f10
/*  f018a00:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018a04:	24a70008 */ 	addiu	$a3,$a1,0x8
/*  f018a08:	3c0e0386 */ 	lui	$t6,0x386
/*  f018a0c:	45000016 */ 	bc1f	.L0f018a68
/*  f018a10:	3c19b800 */ 	lui	$t9,0xb800
/*  f018a14:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018a18:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018a1c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018a20:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018a24:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018a28:	3c188006 */ 	lui	$t8,%hi(var80062568)
/*  f018a2c:	27182568 */ 	addiu	$t8,$t8,%lo(var80062568)
/*  f018a30:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f018a34:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f018a38:	3c0f8006 */ 	lui	$t7,%hi(var80062560)
/*  f018a3c:	3c190388 */ 	lui	$t9,0x388
/*  f018a40:	37390010 */ 	ori	$t9,$t9,0x10
/*  f018a44:	25ef2560 */ 	addiu	$t7,$t7,%lo(var80062560)
/*  f018a48:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f018a4c:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f018a50:	24e30008 */ 	addiu	$v1,$a3,0x8
/*  f018a54:	3c0e0601 */ 	lui	$t6,0x601
/*  f018a58:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f018a5c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f018a60:	10000003 */ 	beqz	$zero,.L0f018a70
/*  f018a64:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f018a68:
/*  f018a68:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018a6c:	ac400004 */ 	sw	$zero,0x4($v0)
.L0f018a70:
/*  f018a70:	0fc59e59 */ 	jal	func0f167964
/*  f018a74:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f018a78:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f018a7c:	0fc59e73 */ 	jal	func0f1679cc
/*  f018a80:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f018a84:	3c013f80 */ 	lui	$at,0x3f80
/*  f018a88:	44812000 */ 	mtc1	$at,$f4
/*  f018a8c:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f018a90:	3c068006 */ 	lui	$a2,%hi(var80062804)
/*  f018a94:	3c078006 */ 	lui	$a3,%hi(var800627bc)
/*  f018a98:	240f00f0 */ 	addiu	$t7,$zero,0xf0
/*  f018a9c:	27ae0270 */ 	addiu	$t6,$sp,0x270
/*  f018aa0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f018aa4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f018aa8:	8ce727bc */ 	lw	$a3,%lo(var800627bc)($a3)
/*  f018aac:	8cc62804 */ 	lw	$a2,%lo(var80062804)($a2)
/*  f018ab0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ab4:	8fa5022c */ 	lw	$a1,0x22c($sp)
/*  f018ab8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f018abc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018ac0:	0fc05c92 */ 	jal	func0f017248
/*  f018ac4:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f018ac8:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f018acc:	3c0f8000 */ 	lui	$t7,0x8000
/*  f018ad0:	3c0e0386 */ 	lui	$t6,0x386
/*  f018ad4:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f018ad8:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f018adc:	37390002 */ 	ori	$t9,$t9,0x2
/*  f018ae0:	3c188006 */ 	lui	$t8,%hi(var80062580)
/*  f018ae4:	27182580 */ 	addiu	$t8,$t8,%lo(var80062580)
/*  f018ae8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f018aec:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f018af0:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f018af4:	24590018 */ 	addiu	$t9,$v0,0x18
/*  f018af8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f018afc:	afb90330 */ 	sw	$t9,0x330($sp)
/*  f018b00:	3c0e8006 */ 	lui	$t6,%hi(var80062578)
/*  f018b04:	3c0f0388 */ 	lui	$t7,0x388
/*  f018b08:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f018b0c:	25ce2578 */ 	addiu	$t6,$t6,%lo(var80062578)
/*  f018b10:	3c188006 */ 	lui	$t8,%hi(var80062858)
/*  f018b14:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f018b18:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f018b1c:	27182858 */ 	addiu	$t8,$t8,%lo(var80062858)
/*  f018b20:	8f010000 */ 	lw	$at,0x0($t8)
/*  f018b24:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f018b28:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b2c:	ac810000 */ 	sw	$at,0x0($a0)
/*  f018b30:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f018b34:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f018b38:	8f010008 */ 	lw	$at,0x8($t8)
/*  f018b3c:	0c0059b7 */ 	jal	func000166dc
/*  f018b40:	ac810008 */ 	sw	$at,0x8($a0)
/*  f018b44:	3c013f80 */ 	lui	$at,0x3f80
/*  f018b48:	44813000 */ 	mtc1	$at,$f6
/*  f018b4c:	c7a8013c */ 	lwc1	$f8,0x13c($sp)
/*  f018b50:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b54:	0c0057e2 */ 	jal	func00015f88
/*  f018b58:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f018b5c:	27a402b0 */ 	addiu	$a0,$sp,0x2b0
/*  f018b60:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f018b64:	0c005680 */ 	jal	func00015a00
/*  f018b68:	27a60230 */ 	addiu	$a2,$sp,0x230
/*  f018b6c:	3c017f1b */ 	lui	$at,%hi(var7f1a8468)
/*  f018b70:	c42c8468 */ 	lwc1	$f12,%lo(var7f1a8468)($at)
/*  f018b74:	0c0057c1 */ 	jal	func00015f04
/*  f018b78:	27a50230 */ 	addiu	$a1,$sp,0x230
/*  f018b7c:	3c028006 */ 	lui	$v0,%hi(var800627f8)
/*  f018b80:	8c4227f8 */ 	lw	$v0,%lo(var800627f8)($v0)
/*  f018b84:	27a30230 */ 	addiu	$v1,$sp,0x230
/*  f018b88:	04420085 */ 	bltzl	$v0,.L0f018da0
/*  f018b8c:	8fa20330 */ 	lw	$v0,0x330($sp)
/*  f018b90:	10400082 */ 	beqz	$v0,.L0f018d9c
/*  f018b94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f018b98:	1441001f */ 	bne	$v0,$at,.L0f018c18
/*  f018b9c:	3c058006 */ 	lui	$a1,%hi(var8006250c)
/*  f018ba0:	3c018006 */ 	lui	$at,0x8006
/*  f018ba4:	c42027f4 */ 	lwc1	$f0,0x27f4($at)
/*  f018ba8:	3c013f00 */ 	lui	$at,0x3f00
/*  f018bac:	44815000 */ 	mtc1	$at,$f10
/*  f018bb0:	44070000 */ 	mfc1	$a3,$f0
/*  f018bb4:	00003025 */ 	or	$a2,$zero,$zero
/*  f018bb8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f018bbc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018bc0:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018bc4:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018bc8:	45000002 */ 	bc1f	.L0f018bd4
/*  f018bcc:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018bd0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018bd4:
/*  f018bd4:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018bd8:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018bdc:	8ca5250c */ 	lw	$a1,%lo(var8006250c)($a1)
/*  f018be0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018be4:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018be8:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018bec:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018bf0:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018bf4:	03201025 */ 	or	$v0,$t9,$zero
/*  f018bf8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018bfc:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f018c00:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018c04:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018c08:	0fc05c92 */ 	jal	func0f017248
/*  f018c0c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018c10:	10000062 */ 	beqz	$zero,.L0f018d9c
/*  f018c14:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018c18:
/*  f018c18:	24010002 */ 	addiu	$at,$zero,0x2
/*  f018c1c:	14410023 */ 	bne	$v0,$at,.L0f018cac
/*  f018c20:	3c058006 */ 	lui	$a1,%hi(var80062508)
/*  f018c24:	3c018006 */ 	lui	$at,0x8006
/*  f018c28:	c42027f4 */ 	lwc1	$f0,0x27f4($at)
/*  f018c2c:	3c013f00 */ 	lui	$at,0x3f00
/*  f018c30:	44812000 */ 	mtc1	$at,$f4
/*  f018c34:	3c013f80 */ 	lui	$at,0x3f80
/*  f018c38:	44813000 */ 	mtc1	$at,$f6
/*  f018c3c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018c40:	00003025 */ 	or	$a2,$zero,$zero
/*  f018c44:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018c48:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018c4c:	45000002 */ 	bc1f	.L0f018c58
/*  f018c50:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f018c54:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018c58:
/*  f018c58:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018c5c:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018c60:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018c64:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018c68:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018c6c:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018c70:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018c74:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018c78:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018c7c:	44815000 */ 	mtc1	$at,$f10
/*  f018c80:	44074000 */ 	mfc1	$a3,$f8
/*  f018c84:	8ca52508 */ 	lw	$a1,%lo(var80062508)($a1)
/*  f018c88:	03201025 */ 	or	$v0,$t9,$zero
/*  f018c8c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018c90:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018c94:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018c9c:	0fc05c92 */ 	jal	func0f017248
/*  f018ca0:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f018ca4:	1000003d */ 	beqz	$zero,.L0f018d9c
/*  f018ca8:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018cac:
/*  f018cac:	24010003 */ 	addiu	$at,$zero,0x3
/*  f018cb0:	14410022 */ 	bne	$v0,$at,.L0f018d3c
/*  f018cb4:	3c058006 */ 	lui	$a1,0x8006
/*  f018cb8:	3c018006 */ 	lui	$at,0x8006
/*  f018cbc:	c42027f4 */ 	lwc1	$f0,0x27f4($at)
/*  f018cc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f018cc4:	44812000 */ 	mtc1	$at,$f4
/*  f018cc8:	44070000 */ 	mfc1	$a3,$f0
/*  f018ccc:	00003025 */ 	or	$a2,$zero,$zero
/*  f018cd0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f018cd4:	3c058006 */ 	lui	$a1,%hi(var80062508)
/*  f018cd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f018cdc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ce0:	45000002 */ 	bc1f	.L0f018cec
/*  f018ce4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018ce8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018cec:
/*  f018cec:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018cf0:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018cf4:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018cf8:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018cfc:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d00:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d04:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d08:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018d0c:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018d10:	44813000 */ 	mtc1	$at,$f6
/*  f018d14:	8ca52508 */ 	lw	$a1,%lo(var80062508)($a1)
/*  f018d18:	03201025 */ 	or	$v0,$t9,$zero
/*  f018d1c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018d20:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d24:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018d28:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018d2c:	0fc05c92 */ 	jal	func0f017248
/*  f018d30:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f018d34:	10000019 */ 	beqz	$zero,.L0f018d9c
/*  f018d38:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018d3c:
/*  f018d3c:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f018d40:	8c42ccb8 */ 	lw	$v0,%lo(var8009ccb8)($v0)
/*  f018d44:	3c18800a */ 	lui	$t8,%hi(var8009cca8)
/*  f018d48:	3c0f800a */ 	lui	$t7,%hi(var8009ccb0)
/*  f018d4c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d50:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d54:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d58:	3c013f80 */ 	lui	$at,0x3f80
/*  f018d5c:	44814000 */ 	mtc1	$at,$f8
/*  f018d60:	8defccb0 */ 	lw	$t7,%lo(var8009ccb0)($t7)
/*  f018d64:	8f18cca8 */ 	lw	$t8,%lo(var8009cca8)($t8)
/*  f018d68:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018d6c:	8ca52508 */ 	lw	$a1,9480($a1)
/*  f018d70:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f018d74:	03201025 */ 	or	$v0,$t9,$zero
/*  f018d78:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018d7c:	00003025 */ 	or	$a2,$zero,$zero
/*  f018d80:	3c073f80 */ 	lui	$a3,0x3f80
/*  f018d84:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f018d88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f018d8c:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f018d90:	0fc05c92 */ 	jal	func0f017248
/*  f018d94:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f018d98:	afa20330 */ 	sw	$v0,0x330($sp)
.L0f018d9c:
/*  f018d9c:	8fa20330 */ 	lw	$v0,0x330($sp)
.L0f018da0:
/*  f018da0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f018da4:
/*  f018da4:	27bd0330 */ 	addiu	$sp,$sp,0x330
/*  f018da8:	03e00008 */ 	jr	$ra
/*  f018dac:	00000000 */ 	sll	$zero,$zero,0x0
);

void titleInitRarePresents(void)
{
	g_TitleTimer = 0;
	func00014810(false);
	g_TitleAudioHandle = NULL;
}

void titleExitRarePresents(void)
{
	if (g_TitleAudioHandle) {
		audioStop(g_TitleAudioHandle);
	}

	g_TitleAudioHandle = NULL;
	func00014810(true);
}

void titleTickRarePresents(void)
{
	func0000bd30(60);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(0);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (g_TitleTimer > 300) {
		titleSetNextMode(TITLEMODE_PDLOGO);
	} else if (func00015020(0, 0xffff)) {
		titleSetNextMode(TITLEMODE_SKIP);
	}
}

GLOBAL_ASM(
glabel func0f018ebc
/*  f018ebc:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f018ec0:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f018ec4:	8fb500a0 */ 	lw	$s5,0xa0($sp)
/*  f018ec8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f018ecc:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f018ed0:	02a1001a */ 	div	$zero,$s5,$at
/*  f018ed4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f018ed8:	0080b025 */ 	or	$s6,$a0,$zero
/*  f018edc:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f018ee0:	00008012 */ 	mflo	$s0
/*  f018ee4:	30e4ffff */ 	andi	$a0,$a3,0xffff
/*  f018ee8:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f018eec:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f018ef0:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f018ef4:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f018ef8:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f018efc:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f018f00:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f018f04:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f018f08:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f018f0c:	0fc5b9f1 */ 	jal	langGet
/*  f018f10:	afb0008c */ 	sw	$s0,0x8c($sp)
/*  f018f14:	3c0f8006 */ 	lui	$t7,%hi(var8006286c)
/*  f018f18:	95ef286c */ 	lhu	$t7,%lo(var8006286c)($t7)
/*  f018f1c:	00409825 */ 	or	$s3,$v0,$zero
/*  f018f20:	00402025 */ 	or	$a0,$v0,$zero
/*  f018f24:	0c012983 */ 	jal	strlen
/*  f018f28:	a7af0080 */ 	sh	$t7,0x80($sp)
/*  f018f2c:	1e000003 */ 	bgtz	$s0,.L0f018f3c
/*  f018f30:	0050082a */ 	slt	$at,$v0,$s0
/*  f018f34:	10000048 */ 	beqz	$zero,.L0f019058
/*  f018f38:	02c01025 */ 	or	$v0,$s6,$zero
.L0f018f3c:
/*  f018f3c:	10200002 */ 	beqz	$at,.L0f018f48
/*  f018f40:	02a08825 */ 	or	$s1,$s5,$zero
/*  f018f44:	afa2008c */ 	sw	$v0,0x8c($sp)
.L0f018f48:
/*  f018f48:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f018f4c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f018f50:	02609025 */ 	or	$s2,$s3,$zero
/*  f018f54:	1b00003f */ 	blez	$t8,.L0f019054
/*  f018f58:	3c1e8006 */ 	lui	$s8,%hi(var80062868)
/*  f018f5c:	27de2868 */ 	addiu	$s8,$s8,%lo(var80062868)
/*  f018f60:	8fb700a4 */ 	lw	$s7,0xa4($sp)
/*  f018f64:	2415003c */ 	addiu	$s5,$zero,0x3c
.L0f018f68:
/*  f018f68:	2a21003d */ 	slti	$at,$s1,0x3d
/*  f018f6c:	14200002 */ 	bnez	$at,.L0f018f78
/*  f018f70:	02201025 */ 	or	$v0,$s1,$zero
/*  f018f74:	02a01025 */ 	or	$v0,$s5,$zero
.L0f018f78:
/*  f018f78:	2841000a */ 	slti	$at,$v0,0xa
/*  f018f7c:	10200003 */ 	beqz	$at,.L0f018f8c
/*  f018f80:	02a24023 */ 	subu	$t0,$s5,$v0
/*  f018f84:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f018f88:	afd90000 */ 	sw	$t9,0x0($s8)
.L0f018f8c:
/*  f018f8c:	00084a00 */ 	sll	$t1,$t0,0x8
/*  f018f90:	01284823 */ 	subu	$t1,$t1,$t0
/*  f018f94:	0135001a */ 	div	$zero,$t1,$s5
/*  f018f98:	00008012 */ 	mflo	$s0
/*  f018f9c:	aef00000 */ 	sw	$s0,0x0($s7)
/*  f018fa0:	924a0000 */ 	lbu	$t2,0x0($s2)
/*  f018fa4:	16a00002 */ 	bnez	$s5,.L0f018fb0
/*  f018fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018fac:	0007000d */ 	break	0x7
.L0f018fb0:
/*  f018fb0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f018fb4:	16a10004 */ 	bne	$s5,$at,.L0f018fc8
/*  f018fb8:	3c018000 */ 	lui	$at,0x8000
/*  f018fbc:	15210002 */ 	bne	$t1,$at,.L0f018fc8
/*  f018fc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018fc4:	0006000d */ 	break	0x6
.L0f018fc8:
/*  f018fc8:	a3aa0080 */ 	sb	$t2,0x80($sp)
/*  f018fcc:	0c002f02 */ 	jal	func0000bc08
/*  f018fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018fd4:	00029c00 */ 	sll	$s3,$v0,0x10
/*  f018fd8:	00135c03 */ 	sra	$t3,$s3,0x10
/*  f018fdc:	0c002f06 */ 	jal	func0000bc18
/*  f018fe0:	01609825 */ 	or	$s3,$t3,$zero
/*  f018fe4:	3c017f7f */ 	lui	$at,0x7f7f
/*  f018fe8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f018fec:	3c0c8008 */ 	lui	$t4,%hi(var8007fb20)
/*  f018ff0:	3c0d8008 */ 	lui	$t5,%hi(var8007fb1c)
/*  f018ff4:	00107200 */ 	sll	$t6,$s0,0x8
/*  f018ff8:	8dadfb1c */ 	lw	$t5,%lo(var8007fb1c)($t5)
/*  f018ffc:	8d8cfb20 */ 	lw	$t4,%lo(var8007fb20)($t4)
/*  f019000:	01c17825 */ 	or	$t7,$t6,$at
/*  f019004:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f019008:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f01900c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f019010:	02c02025 */ 	or	$a0,$s6,$zero
/*  f019014:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f019018:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f01901c:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f019020:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f019024:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f019028:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f01902c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f019030:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f019034:	0fc5580f */ 	jal	textRenderWhite
/*  f019038:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f01903c:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f019040:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f019044:	2631fffd */ 	addiu	$s1,$s1,-3
/*  f019048:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f01904c:	1688ffc6 */ 	bne	$s4,$t0,.L0f018f68
/*  f019050:	0040b025 */ 	or	$s6,$v0,$zero
.L0f019054:
/*  f019054:	02c01025 */ 	or	$v0,$s6,$zero
.L0f019058:
/*  f019058:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f01905c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f019060:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f019064:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f019068:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f01906c:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f019070:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f019074:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f019078:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f01907c:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f019080:	03e00008 */ 	jr	$ra
/*  f019084:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

Gfx *titleRenderRarePresents(Gfx *gdl)
{
	s32 sp84;
	s32 sp80;
	s32 sp76 = 255;

	gdl = func0f01afc0(gdl);
	gdl = func0f153628(gdl);

	sp84 = func0000bd00() + 50;
	sp80 = func0000bd10() + func0000bc98() - 80;

	var80062868 = 0;

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		gdl = func0f018ebc(gdl, &sp84, &sp80, L_OPTIONS(5), g_TitleTimer, &sp76); // "earth:"

		if (g_TitleTimer > 70) {
			sp84 = func0000bd00() + 50;
			sp80 = func0000bd10() + func0000bc98() - 60;
			gdl = func0f018ebc(gdl, &sp84, &sp80, L_OPTIONS(6), g_TitleTimer - 100, &sp76); // "   prehistory"
		}
	} else {
		gdl = func0f018ebc(gdl, &sp84, &sp80, L_OPTIONS(7), g_TitleTimer - 35, &sp76); // "rare presents"
	}

	gdl = func0f153780(gdl);

	if (var80062868) {
		if (g_TitleAudioHandle == NULL) {
			audioStart(var80095200, 0x3e, &g_TitleAudioHandle, -1, -1, -1, -1, -1);
		}
	} else {
		if (g_TitleAudioHandle) {
			audioStop(g_TitleAudioHandle);
		}

		g_TitleAudioHandle = NULL;
	}

	if (((s32)(var80061630 * 80.0f) % 2) == 0) {
		u32 tmp = (sp76 << 8) | 0x7f7fffff | (sp76 << 16);
		gdl = func0f153a34(gdl, sp84 + 2, sp80, sp84 + 12, sp80 + 20, tmp);
	}

	gdl = func0f147cf8(gdl);

	if (g_TitleTimer > 222) {
		f32 tmp2 = ((g_TitleTimer - 222.0f) / 78.0f);
		u32 stack;

		gdl = func0f153a34(gdl, func0000bd00(), func0000bd10(),
				func0000bd00() + func0000bc88(),
				func0000bd10() + func0000bc98(),
				255.0f * tmp2);
	}

	return gdl;
}

void titleInitNintendoLogo(void)
{
	u8 *nextaddr = var8009cca0;

	var800624ac = 0;

	if (var800624a8) {
		g_TitleTimer = 180;
	} else {
		g_TitleTimer = 0;
	}

	{
		struct coord coord = {0, 0, 0};

		g_Props[MODEL_NINTENDOLOGO].filedata = func0f1a7794(g_Props[MODEL_NINTENDOLOGO].fileid, nextaddr, 0x47800, 0);

		func00022d24(g_Props[MODEL_NINTENDOLOGO].filedata);
		g_TitleModel = func0f0b30ac(g_Props[MODEL_NINTENDOLOGO].filedata);
		func0001af58(g_TitleModel, 1);
		func0001ad34(g_TitleModel, &coord);
		var800624f4 = 1;
		func00014810(false);
	}
}

void titleExitNintendoLogo(void)
{
	modelFree(g_TitleModel);
	func00014810(true);
}

u32 var8006287c = 0x00000000;
u32 var80062880 = 0x00000001;
u32 var80062884 = 0x00000003;
u32 var80062888 = 0x00000000;
u32 var8006288c = 0x00000000;
u32 var80062890 = 0x00000000;
u32 var80062894 = 0x00000000;
u32 var80062898 = 0x00000000;
u32 var8006289c = 0x00000000;
u32 var800628a0 = 0x00000000;
u32 var800628a4 = 0x00000000;
u32 var800628a8 = 0x00000000;
u32 var800628ac = 0x00000000;
u32 var800628b0 = 0x00000000;
u32 var800628b4 = 0x00000000;
u32 var800628b8 = 0x00000000;
u32 var800628bc = 0x00000000;
u32 var800628c0 = 0x00000000;
u32 var800628c4 = 0x00000000;

void titleTickNintendoLogo(void)
{
	func0000bd30(60);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(0);

	g_TitleTimer += g_Vars.lvupdate240_60;

	if (var800624ac) {
		g_TitleTimer += g_Vars.lvupdate240_60;
	}

	if (func00015020(0, 0xffff)) {
		if (osResetType == RESET_TYPE_NMI) {
			var800624a8 = 1;
			titleSetNextMode(TITLEMODE_PDLOGO);
		} else if (var800624a8 == 0) {
			var800624ac = 1;
		}
	}

	if (var800624ac && var800624a8 == 0 && g_TitleTimer > 140) {
		var800624a8 = 1;
		var800624ac = 0;
		titleSetNextMode(TITLEMODE_PDLOGO);
	}

	if (g_TitleTimer > 240) {
		titleSetNextMode(TITLEMODE_PDLOGO);
	}
}

GLOBAL_ASM(
glabel titleRenderNintendoLogo
.late_rodata
glabel var7f1a847c
.word 0x40490fdb
glabel var7f1a8480
.word 0x3dcccccd
glabel var7f1a8484
.word 0x3f666666
glabel var7f1a8488
.word 0x3ecccccd
glabel var7f1a848c
.word 0x3ecccccd
glabel var7f1a8490
.word 0x40490fdb
glabel var7f1a8494
.word 0x3fc90fdb
glabel var7f1a8498
.word 0x40490fdb
glabel var7f1a849c
.word 0x3eb33333
glabel var7f1a84a0
.word 0x3e4ccccd
.text
/*  f019658:	27bdfe70 */ 	addiu	$sp,$sp,-400
/*  f01965c:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f019660:	3c0e8006 */ 	lui	$t6,%hi(var8006287c)
/*  f019664:	27b20150 */ 	addiu	$s2,$sp,0x150
/*  f019668:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f01966c:	25ce287c */ 	addiu	$t6,$t6,%lo(var8006287c)
/*  f019670:	27b000f8 */ 	addiu	$s0,$sp,0xf8
/*  f019674:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f019678:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f01967c:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f019680:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f019684:	25d9003c */ 	addiu	$t9,$t6,0x3c
/*  f019688:	02404025 */ 	or	$t0,$s2,$zero
.L0f01968c:
/*  f01968c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f019690:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f019694:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f019698:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f01969c:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f0196a0:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f0196a4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f0196a8:	15d9fff8 */ 	bne	$t6,$t9,.L0f01968c
/*  f0196ac:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f0196b0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0196b4:	3c098006 */ 	lui	$t1,%hi(g_TitleTimer)
/*  f0196b8:	3c0a8006 */ 	lui	$t2,%hi(var800628bc)
/*  f0196bc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f0196c0:	3c014370 */ 	lui	$at,0x4370
/*  f0196c4:	44814000 */ 	mtc1	$at,$f8
/*  f0196c8:	8d2924c4 */ 	lw	$t1,%lo(g_TitleTimer)($t1)
/*  f0196cc:	254a28bc */ 	addiu	$t2,$t2,%lo(var800628bc)
/*  f0196d0:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0196d4:	44892000 */ 	mtc1	$t1,$f4
/*  f0196d8:	ae010000 */ 	sw	$at,0x0($s0)
/*  f0196dc:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f0196e0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0196e4:	ae0d0004 */ 	sw	$t5,0x4($s0)
/*  f0196e8:	8d410008 */ 	lw	$at,0x8($t2)
/*  f0196ec:	46083503 */ 	div.s	$f20,$f6,$f8
/*  f0196f0:	0fc06bf0 */ 	jal	func0f01afc0
/*  f0196f4:	ae010008 */ 	sw	$at,0x8($s0)
/*  f0196f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0196fc:	44815000 */ 	mtc1	$at,$f10
/*  f019700:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f019704:	44818000 */ 	mtc1	$at,$f16
/*  f019708:	46145001 */ 	sub.s	$f0,$f10,$f20
/*  f01970c:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f019710:	3c0f8000 */ 	lui	$t7,0x8000
/*  f019714:	3c190386 */ 	lui	$t9,0x386
/*  f019718:	3c0e8006 */ 	lui	$t6,%hi(var80062598)
/*  f01971c:	25ce2598 */ 	addiu	$t6,$t6,%lo(var80062598)
/*  f019720:	37390010 */ 	ori	$t9,$t9,0x10
/*  f019724:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f019728:	37180002 */ 	ori	$t8,$t8,0x2
/*  f01972c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f019730:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f019734:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f019738:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f01973c:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f019740:	24480018 */ 	addiu	$t0,$v0,0x18
/*  f019744:	3c118006 */ 	lui	$s1,%hi(var80062590)
/*  f019748:	afa80190 */ 	sw	$t0,0x190($sp)
/*  f01974c:	3c090388 */ 	lui	$t1,0x388
/*  f019750:	26312590 */ 	addiu	$s1,$s1,%lo(var80062590)
/*  f019754:	35290010 */ 	ori	$t1,$t1,0x10
/*  f019758:	ac490010 */ 	sw	$t1,0x10($v0)
/*  f01975c:	ac510014 */ 	sw	$s1,0x14($v0)
/*  f019760:	3c017f1b */ 	lui	$at,%hi(var7f1a847c)
/*  f019764:	c424847c */ 	lwc1	$f4,%lo(var7f1a847c)($at)
/*  f019768:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f01976c:	46049302 */ 	mul.s	$f12,$f18,$f4
/*  f019770:	0c0068f7 */ 	jal	sinf
/*  f019774:	e7ac004c */ 	swc1	$f12,0x4c($sp)
/*  f019778:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f01977c:	0c0068f4 */ 	jal	cosf
/*  f019780:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f019784:	e7a000f8 */ 	swc1	$f0,0xf8($sp)
/*  f019788:	02002025 */ 	or	$a0,$s0,$zero
/*  f01978c:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f019790:	0c0011e4 */ 	jal	scaleTo1
/*  f019794:	27a60100 */ 	addiu	$a2,$sp,0x100
/*  f019798:	3c017f1b */ 	lui	$at,%hi(var7f1a8480)
/*  f01979c:	c4208480 */ 	lwc1	$f0,%lo(var7f1a8480)($at)
/*  f0197a0:	44801000 */ 	mtc1	$zero,$f2
/*  f0197a4:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0197a8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0197ac:	02202025 */ 	or	$a0,$s1,$zero
/*  f0197b0:	45000008 */ 	bc1f	.L0f0197d4
/*  f0197b4:	3c01437f */ 	lui	$at,0x437f
/*  f0197b8:	44813000 */ 	mtc1	$at,$f6
/*  f0197bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0197c0:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0197c4:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f0197c8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0197cc:	44028000 */ 	mfc1	$v0,$f16
/*  f0197d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0197d4:
/*  f0197d4:	3c017f1b */ 	lui	$at,%hi(var7f1a8484)
/*  f0197d8:	c4328484 */ 	lwc1	$f18,%lo(var7f1a8484)($at)
/*  f0197dc:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0197e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0197e4:	45000008 */ 	bc1f	.L0f019808
/*  f0197e8:	3c01437f */ 	lui	$at,0x437f
/*  f0197ec:	44813000 */ 	mtc1	$at,$f6
/*  f0197f0:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0197f4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0197f8:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f0197fc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f019800:	44028000 */ 	mfc1	$v0,$f16
/*  f019804:	00000000 */ 	sll	$zero,$zero,0x0
.L0f019808:
/*  f019808:	28410100 */ 	slti	$at,$v0,0x100
/*  f01980c:	14200002 */ 	bnez	$at,.L0f019818
/*  f019810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019814:	240200ff */ 	addiu	$v0,$zero,0xff
.L0f019818:
/*  f019818:	04430003 */ 	bgezl	$v0,.L0f019828
/*  f01981c:	304500ff */ 	andi	$a1,$v0,0xff
/*  f019820:	00001025 */ 	or	$v0,$zero,$zero
/*  f019824:	304500ff */ 	andi	$a1,$v0,0xff
.L0f019828:
/*  f019828:	30a600ff */ 	andi	$a2,$a1,0xff
/*  f01982c:	30a700ff */ 	andi	$a3,$a1,0xff
/*  f019830:	e7a20010 */ 	swc1	$f2,0x10($sp)
/*  f019834:	0fc0585b */ 	jal	func0f01616c
/*  f019838:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f01983c:	3c017f1b */ 	lui	$at,%hi(var7f1a8488)
/*  f019840:	c4328488 */ 	lwc1	$f18,%lo(var7f1a8488)($at)
/*  f019844:	44801000 */ 	mtc1	$zero,$f2
/*  f019848:	4612a03c */ 	c.lt.s	$f20,$f18
/*  f01984c:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f019850:	45000015 */ 	bc1f	.L0f0198a8
/*  f019854:	3c013f80 */ 	lui	$at,0x3f80
/*  f019858:	44812000 */ 	mtc1	$at,$f4
/*  f01985c:	3c017f1b */ 	lui	$at,%hi(var7f1a848c)
/*  f019860:	c426848c */ 	lwc1	$f6,%lo(var7f1a848c)($at)
/*  f019864:	3c017f1b */ 	lui	$at,%hi(var7f1a8490)
/*  f019868:	c4308490 */ 	lwc1	$f16,%lo(var7f1a8490)($at)
/*  f01986c:	4606a203 */ 	div.s	$f8,$f20,$f6
/*  f019870:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f019874:	46105302 */ 	mul.s	$f12,$f10,$f16
/*  f019878:	0c0068f4 */ 	jal	cosf
/*  f01987c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019880:	3c013f00 */ 	lui	$at,0x3f00
/*  f019884:	44813000 */ 	mtc1	$at,$f6
/*  f019888:	46000487 */ 	neg.s	$f18,$f0
/*  f01988c:	44814000 */ 	mtc1	$at,$f8
/*  f019890:	46069102 */ 	mul.s	$f4,$f18,$f6
/*  f019894:	3c017f1b */ 	lui	$at,%hi(var7f1a8494)
/*  f019898:	c4308494 */ 	lwc1	$f16,%lo(var7f1a8494)($at)
/*  f01989c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0198a0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0198a4:	e7b2009c */ 	swc1	$f18,0x9c($sp)
.L0f0198a8:
/*  f0198a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0198ac:	44812000 */ 	mtc1	$at,$f4
/*  f0198b0:	44813000 */ 	mtc1	$at,$f6
/*  f0198b4:	3c017f1b */ 	lui	$at,%hi(var7f1a8498)
/*  f0198b8:	4604a203 */ 	div.s	$f8,$f20,$f4
/*  f0198bc:	c4308498 */ 	lwc1	$f16,%lo(var7f1a8498)($at)
/*  f0198c0:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0198c4:	46105302 */ 	mul.s	$f12,$f10,$f16
/*  f0198c8:	0c0068f4 */ 	jal	cosf
/*  f0198cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0198d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0198d4:	44812000 */ 	mtc1	$at,$f4
/*  f0198d8:	46000487 */ 	neg.s	$f18,$f0
/*  f0198dc:	44814000 */ 	mtc1	$at,$f8
/*  f0198e0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0198e4:	3c017f1b */ 	lui	$at,%hi(var7f1a849c)
/*  f0198e8:	c430849c */ 	lwc1	$f16,%lo(var7f1a849c)($at)
/*  f0198ec:	44801000 */ 	mtc1	$zero,$f2
/*  f0198f0:	27b100a8 */ 	addiu	$s1,$sp,0xa8
/*  f0198f4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0198f8:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f0198fc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f019900:	e7a200a4 */ 	swc1	$f2,0xa4($sp)
/*  f019904:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f019908:	0c005923 */ 	jal	func0001648c
/*  f01990c:	e7b200a0 */ 	swc1	$f18,0xa0($sp)
/*  f019910:	3c017f1b */ 	lui	$at,%hi(var7f1a84a0)
/*  f019914:	c42484a0 */ 	lwc1	$f4,%lo(var7f1a84a0)($at)
/*  f019918:	3c013f80 */ 	lui	$at,0x3f80
/*  f01991c:	44814000 */ 	mtc1	$at,$f8
/*  f019920:	4604a182 */ 	mul.s	$f6,$f20,$f4
/*  f019924:	02202825 */ 	or	$a1,$s1,$zero
/*  f019928:	0c0057e2 */ 	jal	func00015f88
/*  f01992c:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f019930:	44801000 */ 	mtc1	$zero,$f2
/*  f019934:	3c013f80 */ 	lui	$at,0x3f80
/*  f019938:	44815000 */ 	mtc1	$at,$f10
/*  f01993c:	27b00108 */ 	addiu	$s0,$sp,0x108
/*  f019940:	44051000 */ 	mfc1	$a1,$f2
/*  f019944:	44061000 */ 	mfc1	$a2,$f2
/*  f019948:	02002025 */ 	or	$a0,$s0,$zero
/*  f01994c:	3c07457a */ 	lui	$a3,0x457a
/*  f019950:	e7a20010 */ 	swc1	$f2,0x10($sp)
/*  f019954:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f019958:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f01995c:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f019960:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f019964:	0c005ab9 */ 	jal	func00016ae4
/*  f019968:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f01996c:	02002025 */ 	or	$a0,$s0,$zero
/*  f019970:	0c00567f */ 	jal	func000159fc
/*  f019974:	02202825 */ 	or	$a1,$s1,$zero
/*  f019978:	02202025 */ 	or	$a0,$s1,$zero
/*  f01997c:	0c005746 */ 	jal	func00015d18
/*  f019980:	02002825 */ 	or	$a1,$s0,$zero
/*  f019984:	3c138006 */ 	lui	$s3,%hi(g_TitleModel)
/*  f019988:	267324f8 */ 	addiu	$s3,$s3,%lo(g_TitleModel)
/*  f01998c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f019990:	afb00150 */ 	sw	$s0,0x150($sp)
/*  f019994:	8d4d0008 */ 	lw	$t5,0x8($t2)
/*  f019998:	85a4000e */ 	lh	$a0,0xe($t5)
/*  f01999c:	0004c180 */ 	sll	$t8,$a0,0x6
/*  f0199a0:	0fc59e7d */ 	jal	func0f1679f4
/*  f0199a4:	03002025 */ 	or	$a0,$t8,$zero
/*  f0199a8:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0199ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0199b0:	0c005746 */ 	jal	func00015d18
/*  f0199b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0199b8:	8faf0160 */ 	lw	$t7,0x160($sp)
/*  f0199bc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0199c0:	af2f000c */ 	sw	$t7,0xc($t9)
/*  f0199c4:	0c007308 */ 	jal	func0001cc20
/*  f0199c8:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f0199cc:	8fa80190 */ 	lw	$t0,0x190($sp)
/*  f0199d0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0199d4:	afae0158 */ 	sw	$t6,0x158($sp)
/*  f0199d8:	afa00154 */ 	sw	$zero,0x154($sp)
/*  f0199dc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0199e0:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f0199e4:	0c0087bd */ 	jal	func00021ef4
/*  f0199e8:	afa8015c */ 	sw	$t0,0x15c($sp)
/*  f0199ec:	8fa9015c */ 	lw	$t1,0x15c($sp)
/*  f0199f0:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f0199f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0199f8:	afa90190 */ 	sw	$t1,0x190($sp)
/*  f0199fc:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*  f019a00:	00008825 */ 	or	$s1,$zero,$zero
/*  f019a04:	27b20054 */ 	addiu	$s2,$sp,0x54
/*  f019a08:	858b000e */ 	lh	$t3,0xe($t4)
/*  f019a0c:	59600014 */ 	blezl	$t3,.L0f019a60
/*  f019a10:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f019a14:	8c4a000c */ 	lw	$t2,0xc($v0)
.L0f019a18:
/*  f019a18:	02402825 */ 	or	$a1,$s2,$zero
/*  f019a1c:	0c005746 */ 	jal	func00015d18
/*  f019a20:	01512021 */ 	addu	$a0,$t2,$s1
/*  f019a24:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f019a28:	00107980 */ 	sll	$t7,$s0,0x6
/*  f019a2c:	02402025 */ 	or	$a0,$s2,$zero
/*  f019a30:	8db8000c */ 	lw	$t8,0xc($t5)
/*  f019a34:	0c005815 */ 	jal	func00016054
/*  f019a38:	030f2821 */ 	addu	$a1,$t8,$t7
/*  f019a3c:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f019a40:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f019a44:	26310040 */ 	addiu	$s1,$s1,0x40
/*  f019a48:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f019a4c:	872e000e */ 	lh	$t6,0xe($t9)
/*  f019a50:	020e082a */ 	slt	$at,$s0,$t6
/*  f019a54:	5420fff0 */ 	bnezl	$at,.L0f019a18
/*  f019a58:	8c4a000c */ 	lw	$t2,0xc($v0)
/*  f019a5c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f019a60:
/*  f019a60:	8fa20190 */ 	lw	$v0,0x190($sp)
/*  f019a64:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f019a68:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f019a6c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f019a70:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f019a74:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f019a78:	03e00008 */ 	jr	$ra
/*  f019a7c:	27bd0190 */ 	addiu	$sp,$sp,0x190
);

void titleInitRareLogo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleTimer = -3;

	{
		struct coord coord = {0, 0, 0};

		g_Props[MODEL_RARELOGO].filedata = func0f1a7794(g_Props[MODEL_RARELOGO].fileid, nextaddr, 0x47800, 0);

		func00022d24(g_Props[MODEL_RARELOGO].filedata);
		g_TitleModel = func0f0b30ac(g_Props[MODEL_RARELOGO].filedata);
		func0001af58(g_TitleModel, 1);
		func0001ad34(g_TitleModel, &coord);

		var800624f4 = 1;

		func0f16d3d0();
		func00014810(false);

		if (var800624a4 == false && g_Is4Mb != true) {
			var800624a4 = true;
		}
	}
}

void titleExitRareLogo(void)
{
	modelFree(g_TitleModel);
	func00014810(true);
}

u32 var800628d4 = 0x00000000;
u32 var800628d8 = 0x00000001;
u32 var800628dc = 0x00000003;
u32 var800628e0 = 0x00000000;
u32 var800628e4 = 0x00000000;
u32 var800628e8 = 0x00000000;
u32 var800628ec = 0x00000000;
u32 var800628f0 = 0x00000000;
u32 var800628f4 = 0x00000000;
u32 var800628f8 = 0x00000000;
u32 var800628fc = 0x00000000;
u32 var80062900 = 0x00000000;
u32 var80062904 = 0x00000000;
u32 var80062908 = 0x00000000;
u32 var8006290c = 0x00000000;
u32 var80062910 = 0x00000000;
u32 var80062914 = 0x00000000;
u32 var80062918 = 0x00000000;
u32 var8006291c = 0x00000000;
u32 var80062920 = 0x00000000;
s32 g_NumPlayers = 0;
u32 var80062928 = 0x00000000;
u32 var8006292c = 0x00000001;
u32 var80062930 = 0x00000001;
u32 var80062934 = 0x00000001;
u32 var80062938 = 0x00000000;
u32 var8006293c = 0x00000000;

void titleTickRareLogo(void)
{
	func0000bd30(60);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(0);

	if (g_TitleTimer < 0) {
		g_TitleTimer++;
	} else {
		if (g_TitleTimer == 0) {
			func0f16d1bc(1, MUSIC_TITLE1, 0, 0x7fff);
		}

		g_TitleTimer += g_Vars.lvupdate240_60;

		if (func00015020(0, 0xffff)) {
			if (osResetType == RESET_TYPE_NMI) {
				var800624a8 = 1;
				titleSetNextMode(TITLEMODE_PDLOGO);
			} else if (var800624a8 == 0) {
				if (g_TitleTimer < 60) {
					var800624a8 = 1;

					if (g_TitleTimer < 100) {
						g_TitleTimer = 100;
					}
				} else {
					var800624ac = 1;
					var800624a8 = 1;
				}
			}
		}

		if (g_TitleTimer > 240 || var800624ac || (var800624a8 && g_TitleTimer > 140)) {
			titleSetNextMode(TITLEMODE_NINTENDOLOGO);
		}
	}
}

f32 func0f019d0c(f32 arg0)
{
	return ((1.0f - arg0) + (1.0f - arg0)) * M_PI - DEG2RAD(90);
}

GLOBAL_ASM(
glabel titleRenderRareLogo
.late_rodata
glabel var7f1a84b4
.word 0x3dcccccd
glabel var7f1a84b8
.word 0x3e4ccccd
glabel var7f1a84bc
.word 0x3fc90fdb
.text
/*  f019d38:	27bdfe60 */ 	addiu	$sp,$sp,-416
/*  f019d3c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f019d40:	3c0f8006 */ 	lui	$t7,%hi(var800628d4)
/*  f019d44:	3c108006 */ 	lui	$s0,%hi(g_TitleTimer)
/*  f019d48:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f019d4c:	25ef28d4 */ 	addiu	$t7,$t7,%lo(var800628d4)
/*  f019d50:	0080a025 */ 	or	$s4,$a0,$zero
/*  f019d54:	261024c4 */ 	addiu	$s0,$s0,%lo(g_TitleTimer)
/*  f019d58:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f019d5c:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f019d60:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f019d64:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f019d68:	25e8003c */ 	addiu	$t0,$t7,0x3c
/*  f019d6c:	27ae0160 */ 	addiu	$t6,$sp,0x160
.L0f019d70:
/*  f019d70:	8de10000 */ 	lw	$at,0x0($t7)
/*  f019d74:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f019d78:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f019d7c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f019d80:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f019d84:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f019d88:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f019d8c:	15e8fff8 */ 	bne	$t7,$t0,.L0f019d70
/*  f019d90:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f019d94:	8de10000 */ 	lw	$at,0x0($t7)
/*  f019d98:	02802025 */ 	or	$a0,$s4,$zero
/*  f019d9c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f019da0:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f019da4:	3c014370 */ 	lui	$at,0x4370
/*  f019da8:	44814000 */ 	mtc1	$at,$f8
/*  f019dac:	44892000 */ 	mtc1	$t1,$f4
/*  f019db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019db4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f019db8:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f019dbc:	0fc06bf0 */ 	jal	func0f01afc0
/*  f019dc0:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f019dc4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f019dc8:	3c0b8006 */ 	lui	$t3,%hi(var80062914)
/*  f019dcc:	0040a025 */ 	or	$s4,$v0,$zero
/*  f019dd0:	05410003 */ 	bgez	$t2,.L0f019de0
/*  f019dd4:	256b2914 */ 	addiu	$t3,$t3,%lo(var80062914)
/*  f019dd8:	10000154 */ 	beqz	$zero,.L0f01a32c
/*  f019ddc:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f019de0:
/*  f019de0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f019de4:	27b10104 */ 	addiu	$s1,$sp,0x104
/*  f019de8:	ae210000 */ 	sw	$at,0x0($s1)
/*  f019dec:	8d6d0004 */ 	lw	$t5,0x4($t3)
/*  f019df0:	ae2d0004 */ 	sw	$t5,0x4($s1)
/*  f019df4:	8d610008 */ 	lw	$at,0x8($t3)
/*  f019df8:	ae210008 */ 	sw	$at,0x8($s1)
/*  f019dfc:	0fc06743 */ 	jal	func0f019d0c
/*  f019e00:	c7ac0158 */ 	lwc1	$f12,0x158($sp)
/*  f019e04:	0c0068f7 */ 	jal	sinf
/*  f019e08:	46000306 */ 	mov.s	$f12,$f0
/*  f019e0c:	e7a0010c */ 	swc1	$f0,0x10c($sp)
/*  f019e10:	0fc06743 */ 	jal	func0f019d0c
/*  f019e14:	c7ac0158 */ 	lwc1	$f12,0x158($sp)
/*  f019e18:	0c0068f4 */ 	jal	cosf
/*  f019e1c:	46000306 */ 	mov.s	$f12,$f0
/*  f019e20:	27b20108 */ 	addiu	$s2,$sp,0x108
/*  f019e24:	27b3010c */ 	addiu	$s3,$sp,0x10c
/*  f019e28:	e7a00104 */ 	swc1	$f0,0x104($sp)
/*  f019e2c:	02603025 */ 	or	$a2,$s3,$zero
/*  f019e30:	02402825 */ 	or	$a1,$s2,$zero
/*  f019e34:	0c0011e4 */ 	jal	scaleTo1
/*  f019e38:	02202025 */ 	or	$a0,$s1,$zero
/*  f019e3c:	3c017f1b */ 	lui	$at,%hi(var7f1a84b4)
/*  f019e40:	c42084b4 */ 	lwc1	$f0,%lo(var7f1a84b4)($at)
/*  f019e44:	c7a20158 */ 	lwc1	$f2,0x158($sp)
/*  f019e48:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f019e4c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f019e50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019e54:	45000008 */ 	bc1f	.L0f019e78
/*  f019e58:	3c01437f */ 	lui	$at,0x437f
/*  f019e5c:	44818000 */ 	mtc1	$at,$f16
/*  f019e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019e64:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f019e68:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f019e6c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f019e70:	44103000 */ 	mfc1	$s0,$f6
/*  f019e74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f019e78:
/*  f019e78:	2a010100 */ 	slti	$at,$s0,0x100
/*  f019e7c:	14200002 */ 	bnez	$at,.L0f019e88
/*  f019e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019e84:	241000ff */ 	addiu	$s0,$zero,0xff
.L0f019e88:
/*  f019e88:	06010002 */ 	bgez	$s0,.L0f019e94
/*  f019e8c:	3c017f1b */ 	lui	$at,%hi(var7f1a84b8)
/*  f019e90:	00008025 */ 	or	$s0,$zero,$zero
.L0f019e94:
/*  f019e94:	c42084b8 */ 	lwc1	$f0,%lo(var7f1a84b8)($at)
/*  f019e98:	4600103c */ 	c.lt.s	$f2,$f0
/*  f019e9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019ea0:	45000013 */ 	bc1f	.L0f019ef0
/*  f019ea4:	3c01437f */ 	lui	$at,0x437f
/*  f019ea8:	44814000 */ 	mtc1	$at,$f8
/*  f019eac:	44802000 */ 	mtc1	$zero,$f4
/*  f019eb0:	3c048006 */ 	lui	$a0,%hi(var80062590)
/*  f019eb4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f019eb8:	24842590 */ 	addiu	$a0,$a0,%lo(var80062590)
/*  f019ebc:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f019ec0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f019ec4:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f019ec8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f019ecc:	44059000 */ 	mfc1	$a1,$f18
/*  f019ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019ed4:	30a800ff */ 	andi	$t0,$a1,0xff
/*  f019ed8:	01002825 */ 	or	$a1,$t0,$zero
/*  f019edc:	310600ff */ 	andi	$a2,$t0,0xff
/*  f019ee0:	0fc0585b */ 	jal	func0f01616c
/*  f019ee4:	310700ff */ 	andi	$a3,$t0,0xff
/*  f019ee8:	1000000b */ 	beqz	$zero,.L0f019f18
/*  f019eec:	3c013f00 */ 	lui	$at,0x3f00
.L0f019ef0:
/*  f019ef0:	44803000 */ 	mtc1	$zero,$f6
/*  f019ef4:	3c048006 */ 	lui	$a0,%hi(var80062590)
/*  f019ef8:	320500ff */ 	andi	$a1,$s0,0xff
/*  f019efc:	30a600ff */ 	andi	$a2,$a1,0xff
/*  f019f00:	30a700ff */ 	andi	$a3,$a1,0xff
/*  f019f04:	24842590 */ 	addiu	$a0,$a0,%lo(var80062590)
/*  f019f08:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f019f0c:	0fc0585b */ 	jal	func0f01616c
/*  f019f10:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f019f14:	3c013f00 */ 	lui	$at,0x3f00
.L0f019f18:
/*  f019f18:	00107880 */ 	sll	$t7,$s0,0x2
/*  f019f1c:	44816000 */ 	mtc1	$at,$f12
/*  f019f20:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f019f24:	000f7980 */ 	sll	$t7,$t7,0x6
/*  f019f28:	240100ff */ 	addiu	$at,$zero,0xff
/*  f019f2c:	01e1001a */ 	div	$zero,$t7,$at
/*  f019f30:	c7a80158 */ 	lwc1	$f8,0x158($sp)
/*  f019f34:	00008012 */ 	mflo	$s0
/*  f019f38:	460c403c */ 	c.lt.s	$f8,$f12
/*  f019f3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019f40:	4502001c */ 	bc1fl	.L0f019fb4
/*  f019f44:	44808000 */ 	mtc1	$zero,$f16
/*  f019f48:	0fc06743 */ 	jal	func0f019d0c
/*  f019f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019f50:	0c0068f7 */ 	jal	sinf
/*  f019f54:	46000306 */ 	mov.s	$f12,$f0
/*  f019f58:	3c013f00 */ 	lui	$at,0x3f00
/*  f019f5c:	44816000 */ 	mtc1	$at,$f12
/*  f019f60:	0fc06743 */ 	jal	func0f019d0c
/*  f019f64:	e7a0010c */ 	swc1	$f0,0x10c($sp)
/*  f019f68:	0c0068f4 */ 	jal	cosf
/*  f019f6c:	46000306 */ 	mov.s	$f12,$f0
/*  f019f70:	e7a00104 */ 	swc1	$f0,0x104($sp)
/*  f019f74:	02202025 */ 	or	$a0,$s1,$zero
/*  f019f78:	02402825 */ 	or	$a1,$s2,$zero
/*  f019f7c:	0c0011e4 */ 	jal	scaleTo1
/*  f019f80:	02603025 */ 	or	$a2,$s3,$zero
/*  f019f84:	44805000 */ 	mtc1	$zero,$f10
/*  f019f88:	3c048006 */ 	lui	$a0,%hi(var800625a8)
/*  f019f8c:	320500ff */ 	andi	$a1,$s0,0xff
/*  f019f90:	30a600ff */ 	andi	$a2,$a1,0xff
/*  f019f94:	30a700ff */ 	andi	$a3,$a1,0xff
/*  f019f98:	248425a8 */ 	addiu	$a0,$a0,%lo(var800625a8)
/*  f019f9c:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f019fa0:	0fc0585b */ 	jal	func0f01616c
/*  f019fa4:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f019fa8:	1000000b */ 	beqz	$zero,.L0f019fd8
/*  f019fac:	3c013f80 */ 	lui	$at,0x3f80
/*  f019fb0:	44808000 */ 	mtc1	$zero,$f16
.L0f019fb4:
/*  f019fb4:	3c048006 */ 	lui	$a0,%hi(var800625a8)
/*  f019fb8:	320500ff */ 	andi	$a1,$s0,0xff
/*  f019fbc:	30a600ff */ 	andi	$a2,$a1,0xff
/*  f019fc0:	30a700ff */ 	andi	$a3,$a1,0xff
/*  f019fc4:	248425a8 */ 	addiu	$a0,$a0,%lo(var800625a8)
/*  f019fc8:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f019fcc:	0fc0585b */ 	jal	func0f01616c
/*  f019fd0:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f019fd4:	3c013f80 */ 	lui	$at,0x3f80
.L0f019fd8:
/*  f019fd8:	44810000 */ 	mtc1	$at,$f0
/*  f019fdc:	3c01800a */ 	lui	$at,0x800a
/*  f019fe0:	c432a004 */ 	lwc1	$f18,-0x5ffc($at)
/*  f019fe4:	3c0142b4 */ 	lui	$at,0x42b4
/*  f019fe8:	44812000 */ 	mtc1	$at,$f4
/*  f019fec:	3c018006 */ 	lui	$at,0x8006
/*  f019ff0:	c4282920 */ 	lwc1	$f8,0x2920($at)
/*  f019ff4:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f019ff8:	c7b20158 */ 	lwc1	$f18,0x158($sp)
/*  f019ffc:	44801000 */ 	mtc1	$zero,$f2
/*  f01a000:	27b100c0 */ 	addiu	$s1,$sp,0xc0
/*  f01a004:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f01a008:	02202825 */ 	or	$a1,$s1,$zero
/*  f01a00c:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f01a010:	e7a200b4 */ 	swc1	$f2,0xb4($sp)
/*  f01a014:	e7a200bc */ 	swc1	$f2,0xbc($sp)
/*  f01a018:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f01a01c:	46040201 */ 	sub.s	$f8,$f0,$f4
/*  f01a020:	e42a2920 */ 	swc1	$f10,0x2920($at)
/*  f01a024:	3c017f1b */ 	lui	$at,%hi(var7f1a84bc)
/*  f01a028:	c43084bc */ 	lwc1	$f16,%lo(var7f1a84bc)($at)
/*  f01a02c:	46088182 */ 	mul.s	$f6,$f16,$f8
/*  f01a030:	0c005923 */ 	jal	func0001648c
/*  f01a034:	e7a600b8 */ 	swc1	$f6,0xb8($sp)
/*  f01a038:	3c013e80 */ 	lui	$at,0x3e80
/*  f01a03c:	44819000 */ 	mtc1	$at,$f18
/*  f01a040:	c7aa0158 */ 	lwc1	$f10,0x158($sp)
/*  f01a044:	3c013f80 */ 	lui	$at,0x3f80
/*  f01a048:	44818000 */ 	mtc1	$at,$f16
/*  f01a04c:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f01a050:	02202825 */ 	or	$a1,$s1,$zero
/*  f01a054:	0c0057e2 */ 	jal	func00015f88
/*  f01a058:	46102300 */ 	add.s	$f12,$f4,$f16
/*  f01a05c:	44800000 */ 	mtc1	$zero,$f0
/*  f01a060:	3c013f80 */ 	lui	$at,0x3f80
/*  f01a064:	44814000 */ 	mtc1	$at,$f8
/*  f01a068:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f01a06c:	44050000 */ 	mfc1	$a1,$f0
/*  f01a070:	44060000 */ 	mfc1	$a2,$f0
/*  f01a074:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a078:	3c07457a */ 	lui	$a3,0x457a
/*  f01a07c:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f01a080:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f01a084:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f01a088:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f01a08c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f01a090:	0c005ab9 */ 	jal	func00016ae4
/*  f01a094:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f01a098:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a09c:	0c00567f */ 	jal	func000159fc
/*  f01a0a0:	02202825 */ 	or	$a1,$s1,$zero
/*  f01a0a4:	02202025 */ 	or	$a0,$s1,$zero
/*  f01a0a8:	0c005746 */ 	jal	func00015d18
/*  f01a0ac:	02002825 */ 	or	$a1,$s0,$zero
/*  f01a0b0:	3c138006 */ 	lui	$s3,%hi(g_TitleModel)
/*  f01a0b4:	267324f8 */ 	addiu	$s3,$s3,%lo(g_TitleModel)
/*  f01a0b8:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f01a0bc:	afb00160 */ 	sw	$s0,0x160($sp)
/*  f01a0c0:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*  f01a0c4:	8544000e */ 	lh	$a0,0xe($t2)
/*  f01a0c8:	00046180 */ 	sll	$t4,$a0,0x6
/*  f01a0cc:	0fc59e7d */ 	jal	func0f1679f4
/*  f01a0d0:	01802025 */ 	or	$a0,$t4,$zero
/*  f01a0d4:	afa20170 */ 	sw	$v0,0x170($sp)
/*  f01a0d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a0dc:	0c005746 */ 	jal	func00015d18
/*  f01a0e0:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a0e4:	8fab0170 */ 	lw	$t3,0x170($sp)
/*  f01a0e8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f01a0ec:	adab000c */ 	sw	$t3,0xc($t5)
/*  f01a0f0:	0c007308 */ 	jal	func0001cc20
/*  f01a0f4:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a0f8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f01a0fc:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01a100:	0c006a47 */ 	jal	func0001a91c
/*  f01a104:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f01a108:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a10c:	0c006a87 */ 	jal	func0001aa1c
/*  f01a110:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a114:	50400003 */ 	beqzl	$v0,.L0f01a124
/*  f01a118:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f01a11c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f01a120:	8e780000 */ 	lw	$t8,0x0($s3)
.L0f01a124:
/*  f01a124:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f01a128:	0c006a47 */ 	jal	func0001a91c
/*  f01a12c:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f01a130:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a134:	0c006a87 */ 	jal	func0001aa1c
/*  f01a138:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a13c:	10400002 */ 	beqz	$v0,.L0f01a148
/*  f01a140:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01a144:	ac480000 */ 	sw	$t0,0x0($v0)
.L0f01a148:
/*  f01a148:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f01a14c:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f01a150:	0c006a47 */ 	jal	func0001a91c
/*  f01a154:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f01a158:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a15c:	0c006a87 */ 	jal	func0001aa1c
/*  f01a160:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a164:	10400002 */ 	beqz	$v0,.L0f01a170
/*  f01a168:	3c12bc00 */ 	lui	$s2,0xbc00
/*  f01a16c:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f01a170:
/*  f01a170:	02801025 */ 	or	$v0,$s4,$zero
/*  f01a174:	3c0e8000 */ 	lui	$t6,0x8000
/*  f01a178:	36520002 */ 	ori	$s2,$s2,0x2
/*  f01a17c:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f01a180:	26830008 */ 	addiu	$v1,$s4,0x8
/*  f01a184:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f01a188:	ac520000 */ 	sw	$s2,0x0($v0)
/*  f01a18c:	3c090386 */ 	lui	$t1,0x386
/*  f01a190:	3c108006 */ 	lui	$s0,%hi(var80062598)
/*  f01a194:	26102598 */ 	addiu	$s0,$s0,%lo(var80062598)
/*  f01a198:	35290010 */ 	ori	$t1,$t1,0x10
/*  f01a19c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f01a1a0:	ac700004 */ 	sw	$s0,0x4($v1)
/*  f01a1a4:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f01a1a8:	3c0a0388 */ 	lui	$t2,0x388
/*  f01a1ac:	3c118006 */ 	lui	$s1,%hi(var80062590)
/*  f01a1b0:	26312590 */ 	addiu	$s1,$s1,%lo(var80062590)
/*  f01a1b4:	354a0010 */ 	ori	$t2,$t2,0x10
/*  f01a1b8:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f01a1bc:	acd10004 */ 	sw	$s1,0x4($a2)
/*  f01a1c0:	24d40008 */ 	addiu	$s4,$a2,0x8
/*  f01a1c4:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f01a1c8:	afac0168 */ 	sw	$t4,0x168($sp)
/*  f01a1cc:	afa00164 */ 	sw	$zero,0x164($sp)
/*  f01a1d0:	afb4016c */ 	sw	$s4,0x16c($sp)
/*  f01a1d4:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f01a1d8:	0c0087bd */ 	jal	func00021ef4
/*  f01a1dc:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f01a1e0:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f01a1e4:	8fb4016c */ 	lw	$s4,0x16c($sp)
/*  f01a1e8:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01a1ec:	0c006a47 */ 	jal	func0001a91c
/*  f01a1f0:	8d640008 */ 	lw	$a0,0x8($t3)
/*  f01a1f4:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a1f8:	0c006a87 */ 	jal	func0001aa1c
/*  f01a1fc:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a200:	10400002 */ 	beqz	$v0,.L0f01a20c
/*  f01a204:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01a208:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f01a20c:
/*  f01a20c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f01a210:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f01a214:	0c006a47 */ 	jal	func0001a91c
/*  f01a218:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f01a21c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a220:	0c006a87 */ 	jal	func0001aa1c
/*  f01a224:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a228:	50400003 */ 	beqzl	$v0,.L0f01a238
/*  f01a22c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f01a230:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f01a234:	8e780000 */ 	lw	$t8,0x0($s3)
.L0f01a238:
/*  f01a238:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f01a23c:	0c006a47 */ 	jal	func0001a91c
/*  f01a240:	8f040008 */ 	lw	$a0,0x8($t8)
/*  f01a244:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f01a248:	0c006a87 */ 	jal	func0001aa1c
/*  f01a24c:	00402825 */ 	or	$a1,$v0,$zero
/*  f01a250:	10400003 */ 	beqz	$v0,.L0f01a260
/*  f01a254:	26830008 */ 	addiu	$v1,$s4,0x8
/*  f01a258:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01a25c:	ac480000 */ 	sw	$t0,0x0($v0)
.L0f01a260:
/*  f01a260:	02801025 */ 	or	$v0,$s4,$zero
/*  f01a264:	3c0f8000 */ 	lui	$t7,0x8000
/*  f01a268:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f01a26c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f01a270:	ac520000 */ 	sw	$s2,0x0($v0)
/*  f01a274:	3c0e0386 */ 	lui	$t6,0x386
/*  f01a278:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f01a27c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f01a280:	ac700004 */ 	sw	$s0,0x4($v1)
/*  f01a284:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f01a288:	3c090388 */ 	lui	$t1,0x388
/*  f01a28c:	35290010 */ 	ori	$t1,$t1,0x10
/*  f01a290:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f01a294:	acd10004 */ 	sw	$s1,0x4($a2)
/*  f01a298:	24d40008 */ 	addiu	$s4,$a2,0x8
/*  f01a29c:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f01a2a0:	afaa0168 */ 	sw	$t2,0x168($sp)
/*  f01a2a4:	afa00164 */ 	sw	$zero,0x164($sp)
/*  f01a2a8:	afb4016c */ 	sw	$s4,0x16c($sp)
/*  f01a2ac:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f01a2b0:	0c0087bd */ 	jal	func00021ef4
/*  f01a2b4:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f01a2b8:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f01a2bc:	8fb4016c */ 	lw	$s4,0x16c($sp)
/*  f01a2c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f01a2c4:	8c4c0008 */ 	lw	$t4,0x8($v0)
/*  f01a2c8:	00008825 */ 	or	$s1,$zero,$zero
/*  f01a2cc:	27b20058 */ 	addiu	$s2,$sp,0x58
/*  f01a2d0:	858b000e */ 	lh	$t3,0xe($t4)
/*  f01a2d4:	59600014 */ 	blezl	$t3,.L0f01a328
/*  f01a2d8:	02801025 */ 	or	$v0,$s4,$zero
/*  f01a2dc:	8c4d000c */ 	lw	$t5,0xc($v0)
.L0f01a2e0:
/*  f01a2e0:	02402825 */ 	or	$a1,$s2,$zero
/*  f01a2e4:	0c005746 */ 	jal	func00015d18
/*  f01a2e8:	01b12021 */ 	addu	$a0,$t5,$s1
/*  f01a2ec:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f01a2f0:	00104180 */ 	sll	$t0,$s0,0x6
/*  f01a2f4:	02402025 */ 	or	$a0,$s2,$zero
/*  f01a2f8:	8f38000c */ 	lw	$t8,0xc($t9)
/*  f01a2fc:	0c005815 */ 	jal	func00016054
/*  f01a300:	03082821 */ 	addu	$a1,$t8,$t0
/*  f01a304:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f01a308:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f01a30c:	26310040 */ 	addiu	$s1,$s1,0x40
/*  f01a310:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f01a314:	85ee000e */ 	lh	$t6,0xe($t7)
/*  f01a318:	020e082a */ 	slt	$at,$s0,$t6
/*  f01a31c:	5420fff0 */ 	bnezl	$at,.L0f01a2e0
/*  f01a320:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f01a324:	02801025 */ 	or	$v0,$s4,$zero
.L0f01a328:
/*  f01a328:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f01a32c:
/*  f01a32c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f01a330:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f01a334:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f01a338:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f01a33c:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f01a340:	03e00008 */ 	jr	$ra
/*  f01a344:	27bd01a0 */ 	addiu	$sp,$sp,0x1a0
);

s32 getNumPlayers(void)
{
	return g_NumPlayers;
}

void setNumPlayers(s32 numplayers)
{
	g_NumPlayers = numplayers;
}

s32 playerGetTeam(s32 playernum)
{
	return g_MpPlayers[g_Vars.playerstats[playernum].mpindex].base.team;
}

void playerSetTeam(s32 playernum, s32 team)
{
	g_MpPlayers[g_Vars.playerstats[playernum].mpindex].base.team = team;
}

void titleInitSkip(void)
{
	g_TitleNextStage = STAGE_CITRAINING;

	setNumPlayers(1);

	if (var800624a4 != 0) {
		g_TitleNextStage = STAGE_DEFECTION;
		var800624a4++;
	}

	if (g_Is4Mb == true) {
		g_TitleNextStage = STAGE_4MBMENU;
		func0000bd7c(1.4545454978943f);
		func0000bbe4(320, 220);
		func0000bba0(320, 220);
		currentPlayerSetViewSize(320, 220);
		func0000bc28(320, 220);
	}

	func0000e95c(g_TitleNextStage);

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;

	setDifficulty(DIFF_A);
	func00009ec4(true);
}

void titleInitNoController(void)
{
	g_TitleTimer = 0;
}

void titleExitNoController(void)
{
	// empty
}

void titleTickNoController(void)
{
	func0000bd30(60);
	func0000bd7c(1.33333333f);
	func0000be84(100, 10000);
	func0000bd20(0);

	g_TitleTimer += g_Vars.lvupdate240_60;
}

GLOBAL_ASM(
glabel titleRenderNoController
/*  f01a510:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f01a514:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f01a518:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f01a51c:	0c005013 */ 	jal	getConnectedControllers
/*  f01a520:	00808025 */ 	or	$s0,$a0,$zero
/*  f01a524:	0fc06bf0 */ 	jal	func0f01afc0
/*  f01a528:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a52c:	0fc54d8a */ 	jal	func0f153628
/*  f01a530:	00402025 */ 	or	$a0,$v0,$zero
/*  f01a534:	00408025 */ 	or	$s0,$v0,$zero
/*  f01a538:	0fc5b9f1 */ 	jal	langGet
/*  f01a53c:	24045647 */ 	addiu	$a0,$zero,0x5647
/*  f01a540:	3c0e8008 */ 	lui	$t6,%hi(var8007fb1c)
/*  f01a544:	8dcefb1c */ 	lw	$t6,%lo(var8007fb1c)($t6)
/*  f01a548:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f01a54c:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a550:	8ce7fb20 */ 	lw	$a3,%lo(var8007fb20)($a3)
/*  f01a554:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a558:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a55c:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a560:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a564:	0fc55cbe */ 	jal	textMeasure
/*  f01a568:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01a56c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f01a570:	3c098006 */ 	lui	$t1,%hi(var800624a0)
/*  f01a574:	852924a0 */ 	lh	$t1,%lo(var800624a0)($t1)
/*  f01a578:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f01a57c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f01a580:	3c0f8008 */ 	lui	$t7,%hi(g_LanguageId)
/*  f01a584:	8def4120 */ 	lw	$t7,%lo(g_LanguageId)($t7)
/*  f01a588:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f01a58c:	24190120 */ 	addiu	$t9,$zero,0x120
/*  f01a590:	03384023 */ 	subu	$t0,$t9,$t8
/*  f01a594:	afa8005c */ 	sw	$t0,0x5c($sp)
/*  f01a598:	05210003 */ 	bgez	$t1,.L0f01a5a8
/*  f01a59c:	00095043 */ 	sra	$t2,$t1,0x1
/*  f01a5a0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f01a5a4:	00015043 */ 	sra	$t2,$at,0x1
.L0f01a5a8:
/*  f01a5a8:	014c6823 */ 	subu	$t5,$t2,$t4
/*  f01a5ac:	25aefff4 */ 	addiu	$t6,$t5,-12
/*  f01a5b0:	11e0001c */ 	beqz	$t7,.L0f01a624
/*  f01a5b4:	afae0058 */ 	sw	$t6,0x58($sp)
/*  f01a5b8:	0c002f02 */ 	jal	func0000bc08
/*  f01a5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a5c0:	0c002f06 */ 	jal	func0000bc18
/*  f01a5c4:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a5c8:	3c198008 */ 	lui	$t9,%hi(var8007fb20)
/*  f01a5cc:	3c188008 */ 	lui	$t8,%hi(var8007fb1c)
/*  f01a5d0:	8f18fb1c */ 	lw	$t8,%lo(var8007fb1c)($t8)
/*  f01a5d4:	8f39fb20 */ 	lw	$t9,%lo(var8007fb20)($t9)
/*  f01a5d8:	87ab0048 */ 	lh	$t3,0x48($sp)
/*  f01a5dc:	3c090080 */ 	lui	$t1,0x80
/*  f01a5e0:	352900ff */ 	ori	$t1,$t1,0xff
/*  f01a5e4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f01a5e8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f01a5ec:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f01a5f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a5f4:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a5f8:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a5fc:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a600:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f01a604:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a608:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f01a60c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f01a610:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f01a614:	0fc55b92 */ 	jal	textRender
/*  f01a618:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f01a61c:	10000018 */ 	beqz	$zero,.L0f01a680
/*  f01a620:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a624:
/*  f01a624:	0c002f02 */ 	jal	func0000bc08
/*  f01a628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a62c:	0c002f06 */ 	jal	func0000bc18
/*  f01a630:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a634:	3c0a8008 */ 	lui	$t2,%hi(var8007fb20)
/*  f01a638:	3c0c8008 */ 	lui	$t4,%hi(var8007fb1c)
/*  f01a63c:	8d8cfb1c */ 	lw	$t4,%lo(var8007fb1c)($t4)
/*  f01a640:	8d4afb20 */ 	lw	$t2,%lo(var8007fb20)($t2)
/*  f01a644:	87ae0048 */ 	lh	$t6,0x48($sp)
/*  f01a648:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01a64c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f01a650:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a654:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a658:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a65c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a660:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f01a664:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f01a668:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a66c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f01a670:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f01a674:	0fc5580f */ 	jal	textRenderWhite
/*  f01a678:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f01a67c:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a680:
/*  f01a680:	0fc5b9f1 */ 	jal	langGet
/*  f01a684:	24045648 */ 	addiu	$a0,$zero,0x5648
/*  f01a688:	3c0f8008 */ 	lui	$t7,%hi(var8007fb1c)
/*  f01a68c:	8deffb1c */ 	lw	$t7,%lo(var8007fb1c)($t7)
/*  f01a690:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f01a694:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a698:	8ce7fb20 */ 	lw	$a3,%lo(var8007fb20)($a3)
/*  f01a69c:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a6a0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a6a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a6a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a6ac:	0fc55cbe */ 	jal	textMeasure
/*  f01a6b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f01a6b4:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f01a6b8:	3c0b8006 */ 	lui	$t3,%hi(var800624a0)
/*  f01a6bc:	856b24a0 */ 	lh	$t3,%lo(var800624a0)($t3)
/*  f01a6c0:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f01a6c4:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f01a6c8:	3c198008 */ 	lui	$t9,%hi(g_LanguageId)
/*  f01a6cc:	8f394120 */ 	lw	$t9,%lo(g_LanguageId)($t9)
/*  f01a6d0:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f01a6d4:	24080120 */ 	addiu	$t0,$zero,0x120
/*  f01a6d8:	01184823 */ 	subu	$t1,$t0,$t8
/*  f01a6dc:	afa9005c */ 	sw	$t1,0x5c($sp)
/*  f01a6e0:	05610003 */ 	bgez	$t3,.L0f01a6f0
/*  f01a6e4:	000b5043 */ 	sra	$t2,$t3,0x1
/*  f01a6e8:	25610001 */ 	addiu	$at,$t3,0x1
/*  f01a6ec:	00015043 */ 	sra	$t2,$at,0x1
.L0f01a6f0:
/*  f01a6f0:	014d7023 */ 	subu	$t6,$t2,$t5
/*  f01a6f4:	25cf000c */ 	addiu	$t7,$t6,0xc
/*  f01a6f8:	1320001c */ 	beqz	$t9,.L0f01a76c
/*  f01a6fc:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f01a700:	0c002f02 */ 	jal	func0000bc08
/*  f01a704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a708:	0c002f06 */ 	jal	func0000bc18
/*  f01a70c:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a710:	3c088008 */ 	lui	$t0,%hi(var8007fb20)
/*  f01a714:	3c188008 */ 	lui	$t8,%hi(var8007fb1c)
/*  f01a718:	8f18fb1c */ 	lw	$t8,%lo(var8007fb1c)($t8)
/*  f01a71c:	8d08fb20 */ 	lw	$t0,%lo(var8007fb20)($t0)
/*  f01a720:	87ac0048 */ 	lh	$t4,0x48($sp)
/*  f01a724:	3c0b0080 */ 	lui	$t3,0x80
/*  f01a728:	356b00ff */ 	ori	$t3,$t3,0xff
/*  f01a72c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f01a730:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f01a734:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f01a738:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a73c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a740:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a744:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a748:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f01a74c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a750:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f01a754:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f01a758:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f01a75c:	0fc55b92 */ 	jal	textRender
/*  f01a760:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f01a764:	10000018 */ 	beqz	$zero,.L0f01a7c8
/*  f01a768:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a76c:
/*  f01a76c:	0c002f02 */ 	jal	func0000bc08
/*  f01a770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a774:	0c002f06 */ 	jal	func0000bc18
/*  f01a778:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a77c:	3c0a8008 */ 	lui	$t2,%hi(var8007fb20)
/*  f01a780:	3c0d8008 */ 	lui	$t5,%hi(var8007fb1c)
/*  f01a784:	8dadfb1c */ 	lw	$t5,%lo(var8007fb1c)($t5)
/*  f01a788:	8d4afb20 */ 	lw	$t2,%lo(var8007fb20)($t2)
/*  f01a78c:	87af0048 */ 	lh	$t7,0x48($sp)
/*  f01a790:	240effff */ 	addiu	$t6,$zero,-1
/*  f01a794:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f01a798:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a79c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f01a7a0:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f01a7a4:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f01a7a8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f01a7ac:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f01a7b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f01a7b4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f01a7b8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f01a7bc:	0fc5580f */ 	jal	textRenderWhite
/*  f01a7c0:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f01a7c4:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a7c8:
/*  f01a7c8:	0fc54de0 */ 	jal	func0f153780
/*  f01a7cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a7d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f01a7d4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f01a7d8:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f01a7dc:	03e00008 */ 	jr	$ra
/*  f01a7e0:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because goal uses an implicit stack address for func0000bc08's
// return value while mine uses s0, or multiple stack addresses.
//
// Each time func000bc08 is called, goal puts the result in sp72 to preserve it
// past the call to func000bc18. It uses the same stack address each time.
// However, if the below is changed to call the final func000bc08 like the
// others, it uses s0 instead. Likewise, changing all calls to load their return
// values into variables also makes it use s0. And a mix between the two
// (as shown below) causes it to use different stack addresses.
//Gfx *titleRenderNoController(Gfx *gdl)
//{
//	s32 textheight; // sp100
//	s32 textwidth; // sp96
//	s32 x; // sp92
//	s32 y; // sp88
//	char *text; // sp84
//	u16 stack[6];
//
//	// This was likely printed to console
//	getConnectedControllers();
//
//	gdl = func0f01afc0(gdl);
//	gdl = func0f153628(gdl);
//
//	// First line
//	text = langGet(L_OPTIONS(71)); // "- no controller in controller socket 1 -"
//	textMeasure(&textheight, &textwidth, text, var8007fb20, var8007fb1c, 0);
//
//	x = 288 - (textwidth >> 1);
//	y = ((var800624a0 / 2) - (textheight >> 1)) - 12;
//
//	if (g_LanguageId != LANGUAGE_ENGLISH) {
//		gdl = textRender(gdl, &x, &y, text, var8007fb20, var8007fb1c,
//				-1, 0x008000ff, func0000bc08(), func0000bc18(), 0, 0);
//	} else {
//		gdl = textRenderWhite(gdl, &x, &y, text, var8007fb20, var8007fb1c,
//				-1, func0000bc08(), func0000bc18(), 0, 0);
//	}
//
//	// Second line
//	text = langGet(L_OPTIONS(72)); // "please power off and attach a controller"
//	textMeasure(&textheight, &textwidth, text, var8007fb20, var8007fb1c, 0);
//
//	x = 288 - (textwidth >> 1);
//	y = ((var800624a0 / 2) - (textheight >> 1)) + 12;
//
//	if (g_LanguageId != LANGUAGE_ENGLISH) {
//		gdl = textRender(gdl, &x, &y, text, var8007fb20, var8007fb1c,
//				-1, 0x008000ff, func0000bc08(), func0000bc18(), 0, 0);
//	} else {
//		s16 a = func0000bc08();
//		s16 b = func0000bc18();
//		gdl = textRenderWhite(gdl, &x, &y, text, var8007fb20, var8007fb1c,
//				-1, a, b, 0, 0);
//	}
//
//	return func0f153780(gdl);
//}

void titleSetNextMode(s32 mode)
{
	if (g_TitleDelayedMode != mode) {
		g_TitleNextMode = mode;
	}
}

s32 titleGetMode(void)
{
	return g_TitleMode;
}

void titleTick(void)
{
	func0000bd7c(576.0f / var800624a0);
	func0000bbe4(576, var800624a0);
	func0000bba0(576, var800624a0);
	currentPlayerSetViewSize(576, var800624a0);
	func0000bc28(576, var800624a0);
	currentPlayerSetViewPosition(0, 0);
	func0000bca8(0, 0);

	// If there's a new mode to transition to, schedule it to apply in 3 ticks
	// time and call the exit function for the current mode.
	if (g_TitleNextMode >= 0) {
		g_TitleDelayedTimer = 3;
		g_TitleDelayedMode = g_TitleNextMode;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			titleExitLegal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			titleExitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleExitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleExitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleExitRareLogo();
			break;
		case TITLEMODE_NOCONTROLLER:
			titleExitNoController();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS) {
			func00009ec4(true);
		}

		g_TitleNextMode = -1;
	}

	// If there's a new mode scheduled, tick the timer down
	if (g_TitleDelayedTimer != 0) {
		g_TitleDelayedTimer--;

		if (g_TitleMode == -1) {
			g_TitleDelayedTimer = 0;
		}

		if (g_TitleDelayedTimer == 0 && g_TitleDelayedMode != -1) {
			g_TitleNextMode = g_TitleDelayedMode;
			g_TitleDelayedMode = -1;
		}
	}

	// Apply new mode
	if (g_TitleNextMode >= 0) {
		g_TitleMode = g_TitleNextMode;
		g_TitleNextMode = -1;
		var800624ac = 0;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			titleInitLegal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			titleInitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleInitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleInitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleInitRareLogo();
			break;
		case TITLEMODE_SKIP:
			titleInitSkip();
			break;
		case TITLEMODE_NOCONTROLLER:
			titleInitNoController();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS && g_TitleMode != TITLEMODE_SKIP) {
			func00009ec4(false);
		}
	}

	// Run the current mode's tick function
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		titleTickLegal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		titleTickCheckControllers();
		break;
	case TITLEMODE_PDLOGO:
		titleTickPdLogo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		titleTickNintendoLogo();
		break;
	case TITLEMODE_RARELOGO:
		titleTickRareLogo();
		break;
	case TITLEMODE_NOCONTROLLER:
		titleTickNoController();
		break;
	case TITLEMODE_SKIP:
		func0000bd20(0);
		titleSetNextMode(TITLEMODE_RARELOGO);
		break;
	}
}

bool titleIsChangingMode(void)
{
	return g_TitleNextMode >= 0;
}

bool titleIsKeepingMode(void)
{
	if (g_TitleNextMode >= 0) {
		return false;
	}

	if (g_TitleMode == -1 || g_TitleMode == TITLEMODE_SKIP) {
		return false;
	}

	return true;
}

void titleExit(void)
{
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		titleExitLegal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		titleExitCheckControllers();
		break;
	case TITLEMODE_PDLOGO:
		titleExitPdLogo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		titleExitNintendoLogo();
		break;
	case TITLEMODE_RARELOGO:
		titleExitRareLogo();
		break;
	case TITLEMODE_NOCONTROLLER:
		titleExitNoController();
		break;
	case TITLEMODE_RAREPRESENTS1:
	case TITLEMODE_RAREPRESENTS2:
		titleExitRarePresents();
		break;
	}

	g_TitleNextMode = -1;
	g_TitleMode = -1;
}

void titleInitFromAiCmd(u32 value)
{
	switch (value) {
	case TITLEAIMODE_RAREPRESENTS1:
		g_TitleMode = TITLEMODE_RAREPRESENTS1;
		titleInitRarePresents();
		break;
	case TITLEAIMODE_RARELOGO:
		g_TitleMode = TITLEMODE_RARELOGO;
		titleInitRareLogo();
		break;
	case TITLEAIMODE_RAREPRESENTS2:
		g_TitleMode = TITLEMODE_RAREPRESENTS2;
		titleInitRarePresents();
		break;
	case TITLEAIMODE_NINTENDOLOGO:
		g_TitleMode = TITLEMODE_NINTENDOLOGO;
		titleInitNintendoLogo();
		break;
	case TITLEAIMODE_PDLOGO:
		g_TitleMode = TITLEMODE_PDLOGO;
		titleInitPdLogo();
		break;
	}

	g_TitleNextMode = -1;
}

bool func0f01ad5c(void)
{
	if (!titleIsKeepingMode()) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS2) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		return false;
	}

	return true;
}

void func0f01adb8(void)
{
	func0000aab0(2);
	func0000bbe4(576, var800624a0);
	func0000bba0(576, var800624a0);
	currentPlayerSetViewSize(576, var800624a0);
	func0000bc28(576, var800624a0);
	currentPlayerSetViewPosition(0, 0);
	func0000bca8(0, 0);
}

void func0f01ae30(void)
{
	if (titleIsKeepingMode()) {
		func00014810(false);

		if (g_TitleDelayedTimer == 0) {
			switch (g_TitleMode) {
			case TITLEMODE_LEGAL:
				titleTickLegal();
				break;
			case TITLEMODE_CHECKCONTROLLERS:
				titleTickCheckControllers();
				break;
			case TITLEMODE_PDLOGO:
				titleTickPdLogo();
				break;
			case TITLEMODE_NINTENDOLOGO:
				titleTickNintendoLogo();
				break;
			case TITLEMODE_RAREPRESENTS1:
			case TITLEMODE_RAREPRESENTS2:
				titleTickRarePresents();
				break;
			case TITLEMODE_RARELOGO:
				titleTickRareLogo();
				break;
			}
		}
	}
}

Gfx *titleRender(Gfx *gdl)
{
	if (g_TitleDelayedTimer == 0) {
		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			gdl = titleRenderLegal(gdl);
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			gdl = titleRenderCheckControllers(gdl);
			break;
		case TITLEMODE_PDLOGO:
			gdl = titleRenderPdLogo(gdl);
			break;
		case TITLEMODE_NINTENDOLOGO:
			gdl = titleRenderNintendoLogo(gdl);
			break;
		case TITLEMODE_RAREPRESENTS1:
		case TITLEMODE_RAREPRESENTS2:
			gdl = titleRenderRarePresents(gdl);
			break;
		case TITLEMODE_RARELOGO:
			gdl = titleRenderRareLogo(gdl);
			break;
		case TITLEMODE_NOCONTROLLER:
			gdl = titleRenderNoController(gdl);
			break;
		}
	}

	return gdl;
}
