#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b69d0.h"
#include "game/game_127910.h"
#include "game/bg.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/game_190260.h"
#include "game/game_197600.h"
#include "game/game_1999b0.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

struct chrdata *g_MpSimulantChrs[MAX_SIMULANTS];

u8 g_NumMpSimulantChrs = 0;

struct simdifficulty g_SimDifficulties[] = {
#if PAL
	{ 75, 0.26175770163536,  0.52351540327072,  500, 10, 0.69802051782608, 0.34901025891304,  833  },
	{ 50, 0.12215359508991,  0.24430719017982,  300, 10, 0.49733963608742, 0.13960410654545,  833  },
	{ 25, 0.069802053272724, 0.13960410654545,  150, 4,  0.34901025891304, 0.08725256472826,  1250 },
	{ 12, 0.026175770908594, 0.069802053272724, 75,  2,  0.24430719017982, 0.034901026636362, 2083 },
	{ 0,  0,                 0.034901026636362, 37,  1,  0.17450512945652, 0,                 3333 },
	{ 0,  0,                 0,                 0,   0,  0.13960410654545, 0,                 3333 },
	{ 0,  0,                 0,                 0,   0,  0,                0,                 0    },
#else
	{ 90, 0.26175770163536,  0.52351540327072,  600, 10, 0.69802051782608, 0.34901025891304,  1000 },
	{ 60, 0.12215359508991,  0.24430719017982,  360, 10, 0.49733963608742, 0.13960410654545,  1000 },
	{ 30, 0.069802053272724, 0.13960410654545,  180, 4,  0.34901025891304, 0.08725256472826,  1500 },
	{ 15, 0.026175770908594, 0.069802053272724, 90,  2,  0.24430719017982, 0.034901026636362, 2500 },
	{ 0,  0,                 0.034901026636362, 45,  1,  0.17450512945652, 0,                 4000 },
	{ 0,  0,                 0,                 0,   0,  0.13960410654545, 0,                 4000 },
	{ 0,  0,                 0,                 0,   0,  0,                0,                 0    },
#endif
};

u32 g_MpBotCommands[NUM_MPBOTCOMMANDS] = {
	L_MISC_175, // "Follow"
	L_MISC_176, // "Attack"
	L_MISC_177, // "Defend"
	L_MISC_178, // "Hold"
	L_MISC_179, // "Normal"
	L_MISC_180, // "Download"
	L_MISC_181, // "Get Case"
	L_MISC_182, // "Tag Box"
	L_MISC_209, // "Save Case"
	L_MISC_210, // "Def Hill"
	L_MISC_211, // "Hold Hill"
	L_MISC_212, // "Get Case"
	L_MISC_213, // "Pop Cap"
	L_MISC_214, // "Protect"
};

bool func0f190260(struct chrdata *chr)
{
	return chr->blurdrugamount >= g_SimDifficulties[chr->aibot->simulant->difficulty].blurdrugamount;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel mpChrReset
/*  f19134c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f191350:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f191354:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f191358:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19135c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f191360:	8c9002d4 */ 	lw	$s0,0x2d4($a0)
/*  f191364:	00808825 */ 	move	$s1,$a0
/*  f191368:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f19136c:	120000c9 */ 	beqz	$s0,.PF0f191694
/*  f191370:	240f00ff */ 	li	$t7,0xff
/*  f191374:	8c980018 */ 	lw	$t8,0x18($a0)
/*  f191378:	2401feff */ 	li	$at,-257
/*  f19137c:	8c880014 */ 	lw	$t0,0x14($a0)
/*  f191380:	0301c824 */ 	and	$t9,$t8,$at
/*  f191384:	3c01dfff */ 	lui	$at,0xdfff
/*  f191388:	44801000 */ 	mtc1	$zero,$f2
/*  f19138c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f191390:	240a0029 */ 	li	$t2,0x29
/*  f191394:	01014824 */ 	and	$t1,$t0,$at
/*  f191398:	a08f000c */ 	sb	$t7,0xc($a0)
/*  f19139c:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f1913a0:	ac890014 */ 	sw	$t1,0x14($a0)
/*  f1913a4:	a08a02a0 */ 	sb	$t2,0x2a0($a0)
/*  f1913a8:	11c0009e */ 	beqz	$t6,.PF0f191624
/*  f1913ac:	e482014c */ 	swc1	$f2,0x14c($a0)
/*  f1913b0:	2406ffff */ 	li	$a2,-1
/*  f1913b4:	44051000 */ 	mfc1	$a1,$f2
/*  f1913b8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f1913bc:	e4820100 */ 	swc1	$f2,0x100($a0)
/*  f1913c0:	a486017e */ 	sh	$a2,0x17e($a0)
/*  f1913c4:	a486012a */ 	sh	$a2,0x12a($a0)
/*  f1913c8:	0fc0d044 */ 	jal	chrSetShield
/*  f1913cc:	a4860292 */ 	sh	$a2,0x292($a0)
/*  f1913d0:	a2200184 */ 	sb	$zero,0x184($s1)
/*  f1913d4:	a2200185 */ 	sb	$zero,0x185($s1)
/*  f1913d8:	0fc29d45 */ 	jal	freeFireslot
/*  f1913dc:	8224017c */ 	lb	$a0,0x17c($s1)
/*  f1913e0:	0fc29d45 */ 	jal	freeFireslot
/*  f1913e4:	8224017d */ 	lb	$a0,0x17d($s1)
/*  f1913e8:	922b032d */ 	lbu	$t3,0x32d($s1)
/*  f1913ec:	3c014339 */ 	lui	$at,0x4339
/*  f1913f0:	44812000 */ 	mtc1	$at,$f4
/*  f1913f4:	316dfff3 */ 	andi	$t5,$t3,0xfff3
/*  f1913f8:	2406ffff */ 	li	$a2,-1
/*  f1913fc:	a22d032d */ 	sb	$t5,0x32d($s1)
/*  f191400:	31ae007f */ 	andi	$t6,$t5,0x7f
/*  f191404:	a226017c */ 	sb	$a2,0x17c($s1)
/*  f191408:	a226017d */ 	sb	$a2,0x17d($s1)
/*  f19140c:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f191410:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f191414:	ae200170 */ 	sw	$zero,0x170($s1)
/*  f191418:	ae200174 */ 	sw	$zero,0x174($s1)
/*  f19141c:	ae200178 */ 	sw	$zero,0x178($s1)
/*  f191420:	a220032c */ 	sb	$zero,0x32c($s1)
/*  f191424:	a22e032d */ 	sb	$t6,0x32d($s1)
/*  f191428:	ae200364 */ 	sw	$zero,0x364($s1)
/*  f19142c:	00001825 */ 	move	$v1,$zero
/*  f191430:	e6240028 */ 	swc1	$f4,0x28($s1)
.PF0f191434:
/*  f191434:	8e0f001c */ 	lw	$t7,0x1c($s0)
/*  f191438:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f19143c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f191440:	28610084 */ 	slti	$at,$v1,0x84
/*  f191444:	1420fffb */ 	bnez	$at,.PF0f191434
/*  f191448:	af000000 */ 	sw	$zero,0x0($t8)
/*  f19144c:	0fc66340 */ 	jal	aibotClearInventory
/*  f191450:	02202025 */ 	move	$a0,$s1
/*  f191454:	9208004c */ 	lbu	$t0,0x4c($s0)
/*  f191458:	920d009c */ 	lbu	$t5,0x9c($s0)
/*  f19145c:	44801000 */ 	mtc1	$zero,$f2
/*  f191460:	24190001 */ 	li	$t9,0x1
/*  f191464:	310bffdf */ 	andi	$t3,$t0,0xffdf
/*  f191468:	ae190020 */ 	sw	$t9,0x20($s0)
/*  f19146c:	31afff7f */ 	andi	$t7,$t5,0xff7f
/*  f191470:	2406ffff */ 	li	$a2,-1
/*  f191474:	a20b004c */ 	sb	$t3,0x4c($s0)
/*  f191478:	35790040 */ 	ori	$t9,$t3,0x40
/*  f19147c:	332b00fd */ 	andi	$t3,$t9,0xfd
/*  f191480:	a219004c */ 	sb	$t9,0x4c($s0)
/*  f191484:	a20f009c */ 	sb	$t7,0x9c($s0)
/*  f191488:	31e900bf */ 	andi	$t1,$t7,0xbf
/*  f19148c:	316d00f7 */ 	andi	$t5,$t3,0xf7
/*  f191490:	a20b004c */ 	sb	$t3,0x4c($s0)
/*  f191494:	31af00ef */ 	andi	$t7,$t5,0xef
/*  f191498:	a20d004c */ 	sb	$t5,0x4c($s0)
/*  f19149c:	31f900fb */ 	andi	$t9,$t7,0xfb
/*  f1914a0:	a20f004c */ 	sb	$t7,0x4c($s0)
/*  f1914a4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1914a8:	a209009c */ 	sb	$t1,0x9c($s0)
/*  f1914ac:	312a00df */ 	andi	$t2,$t1,0xdf
/*  f1914b0:	a219004c */ 	sb	$t9,0x4c($s0)
/*  f1914b4:	3328007f */ 	andi	$t0,$t9,0x7f
/*  f1914b8:	44810000 */ 	mtc1	$at,$f0
/*  f1914bc:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f1914c0:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f1914c4:	ae000010 */ 	sw	$zero,0x10($s0)
/*  f1914c8:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f1914cc:	a600002e */ 	sh	$zero,0x2e($s0)
/*  f1914d0:	ae00005c */ 	sw	$zero,0x5c($s0)
/*  f1914d4:	ae000060 */ 	sw	$zero,0x60($s0)
/*  f1914d8:	a2060074 */ 	sb	$a2,0x74($s0)
/*  f1914dc:	ae000034 */ 	sw	$zero,0x34($s0)
/*  f1914e0:	a200004d */ 	sb	$zero,0x4d($s0)
/*  f1914e4:	a200004e */ 	sb	$zero,0x4e($s0)
/*  f1914e8:	ae000044 */ 	sw	$zero,0x44($s0)
/*  f1914ec:	ae0000a0 */ 	sw	$zero,0xa0($s0)
/*  f1914f0:	a20a009c */ 	sb	$t2,0x9c($s0)
/*  f1914f4:	a6000064 */ 	sh	$zero,0x64($s0)
/*  f1914f8:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f1914fc:	a6060048 */ 	sh	$a2,0x48($s0)
/*  f191500:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f191504:	ae0600bc */ 	sw	$a2,0xbc($s0)
/*  f191508:	ae0000c8 */ 	sw	$zero,0xc8($s0)
/*  f19150c:	ae0000c4 */ 	sw	$zero,0xc4($s0)
/*  f191510:	ae0000cc */ 	sw	$zero,0xcc($s0)
/*  f191514:	ae0000d0 */ 	sw	$zero,0xd0($s0)
/*  f191518:	ae0000d8 */ 	sw	$zero,0xd8($s0)
/*  f19151c:	ae0000dc */ 	sw	$zero,0xdc($s0)
/*  f191520:	a606003e */ 	sh	$a2,0x3e($s0)
/*  f191524:	a600003c */ 	sh	$zero,0x3c($s0)
/*  f191528:	a60000e2 */ 	sh	$zero,0xe2($s0)
/*  f19152c:	a60000e0 */ 	sh	$zero,0xe0($s0)
/*  f191530:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f191534:	ae00011c */ 	sw	$zero,0x11c($s0)
/*  f191538:	ae060120 */ 	sw	$a2,0x120($s0)
/*  f19153c:	ae060124 */ 	sw	$a2,0x124($s0)
/*  f191540:	ae000128 */ 	sw	$zero,0x128($s0)
/*  f191544:	ae00012c */ 	sw	$zero,0x12c($s0)
/*  f191548:	00002025 */ 	move	$a0,$zero
/*  f19154c:	02001025 */ 	move	$v0,$s0
/*  f191550:	02001825 */ 	move	$v1,$s0
/*  f191554:	02002825 */ 	move	$a1,$s0
/*  f191558:	2407000c */ 	li	$a3,0xc
/*  f19155c:	e6020040 */ 	swc1	$f2,0x40($s0)
/*  f191560:	e602006c */ 	swc1	$f2,0x6c($s0)
/*  f191564:	e6020070 */ 	swc1	$f2,0x70($s0)
/*  f191568:	e60200e8 */ 	swc1	$f2,0xe8($s0)
/*  f19156c:	e60200e4 */ 	swc1	$f2,0xe4($s0)
/*  f191570:	e6020108 */ 	swc1	$f2,0x108($s0)
/*  f191574:	e602010c */ 	swc1	$f2,0x10c($s0)
/*  f191578:	e6020110 */ 	swc1	$f2,0x110($s0)
.PF0f19157c:
/*  f19157c:	a0460130 */ 	sb	$a2,0x130($v0)
/*  f191580:	e460013c */ 	swc1	$f0,0x13c($v1)
/*  f191584:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f191588:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f19158c:	ac660178 */ 	sw	$a2,0x178($v1)
/*  f191590:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f191594:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f191598:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f19159c:	1487fff7 */ 	bne	$a0,$a3,.PF0f19157c
/*  f1915a0:	a4a601a6 */ 	sh	$a2,0x1a6($a1)
/*  f1915a4:	ae0001e8 */ 	sw	$zero,0x1e8($s0)
/*  f1915a8:	0c004ad4 */ 	jal	random
/*  f1915ac:	ae000208 */ 	sw	$zero,0x208($s0)
/*  f1915b0:	9209009c */ 	lbu	$t1,0x9c($s0)
/*  f1915b4:	44801000 */ 	mtc1	$zero,$f2
/*  f1915b8:	ae020210 */ 	sw	$v0,0x210($s0)
/*  f1915bc:	312affef */ 	andi	$t2,$t1,0xffef
/*  f1915c0:	ae00020c */ 	sw	$zero,0x20c($s0)
/*  f1915c4:	ae0002c8 */ 	sw	$zero,0x2c8($s0)
/*  f1915c8:	a20a009c */ 	sb	$t2,0x9c($s0)
/*  f1915cc:	ae0002cc */ 	sw	$zero,0x2cc($s0)
/*  f1915d0:	0c004ad4 */ 	jal	random
/*  f1915d4:	e60202c4 */ 	swc1	$f2,0x2c4($s0)
/*  f1915d8:	0c004ad4 */ 	jal	random
/*  f1915dc:	ae0202d0 */ 	sw	$v0,0x2d0($s0)
/*  f1915e0:	44823000 */ 	mtc1	$v0,$f6
/*  f1915e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1915e8:	04410004 */ 	bgez	$v0,.PF0f1915fc
/*  f1915ec:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1915f0:	44815000 */ 	mtc1	$at,$f10
/*  f1915f4:	00000000 */ 	nop
/*  f1915f8:	460a4200 */ 	add.s	$f8,$f8,$f10
.PF0f1915fc:
/*  f1915fc:	3c012f80 */ 	lui	$at,0x2f80
/*  f191600:	44818000 */ 	mtc1	$at,$f16
/*  f191604:	920b009c */ 	lbu	$t3,0x9c($s0)
/*  f191608:	a2000078 */ 	sb	$zero,0x78($s0)
/*  f19160c:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f191610:	316cfffe */ 	andi	$t4,$t3,0xfffe
/*  f191614:	a20c009c */ 	sb	$t4,0x9c($s0)
/*  f191618:	ae000050 */ 	sw	$zero,0x50($s0)
/*  f19161c:	a200009d */ 	sb	$zero,0x9d($s0)
/*  f191620:	e61202d4 */ 	swc1	$f18,0x2d4($s0)
.PF0f191624:
/*  f191624:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f191628:	2401000b */ 	li	$at,0xb
/*  f19162c:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f191630:	10610002 */ 	beq	$v1,$at,.PF0f19163c
/*  f191634:	24010002 */ 	li	$at,0x2
/*  f191638:	14610005 */ 	bne	$v1,$at,.PF0f191650
.PF0f19163c:
/*  f19163c:	3c014100 */ 	lui	$at,0x4100
/*  f191640:	44812000 */ 	mtc1	$at,$f4
/*  f191644:	00000000 */ 	nop
/*  f191648:	e6240180 */ 	swc1	$f4,0x180($s1)
/*  f19164c:	8e020004 */ 	lw	$v0,0x4($s0)
.PF0f191650:
/*  f191650:	904d0048 */ 	lbu	$t5,0x48($v0)
/*  f191654:	24010005 */ 	li	$at,0x5
/*  f191658:	55a1000b */ 	bnel	$t5,$at,.PF0f191688
/*  f19165c:	24180001 */ 	li	$t8,0x1
/*  f191660:	960e0064 */ 	lhu	$t6,0x64($s0)
/*  f191664:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f191668:	0fc664de */ 	jal	mpHasShield
/*  f19166c:	a60f0064 */ 	sh	$t7,0x64($s0)
/*  f191670:	10400004 */ 	beqz	$v0,.PF0f191684
/*  f191674:	3c014100 */ 	lui	$at,0x4100
/*  f191678:	44813000 */ 	mtc1	$at,$f6
/*  f19167c:	00000000 */ 	nop
/*  f191680:	e6260180 */ 	swc1	$f6,0x180($s1)
.PF0f191684:
/*  f191684:	24180001 */ 	li	$t8,0x1
.PF0f191688:
/*  f191688:	24190064 */ 	li	$t9,0x64
/*  f19168c:	a2180059 */ 	sb	$t8,0x59($s0)
/*  f191690:	a2190058 */ 	sb	$t9,0x58($s0)
.PF0f191694:
/*  f191694:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f191698:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19169c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1916a0:	03e00008 */ 	jr	$ra
/*  f1916a4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel mpChrReset
/*  f19028c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f190290:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f190294:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f190298:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19029c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1902a0:	8c9002d4 */ 	lw	$s0,0x2d4($a0)
/*  f1902a4:	00808825 */ 	or	$s1,$a0,$zero
/*  f1902a8:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f1902ac:	120000cb */ 	beqz	$s0,.L0f1905dc
/*  f1902b0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f1902b4:	8c980018 */ 	lw	$t8,0x18($a0)
/*  f1902b8:	2401feff */ 	addiu	$at,$zero,-257
/*  f1902bc:	8c880014 */ 	lw	$t0,0x14($a0)
/*  f1902c0:	0301c824 */ 	and	$t9,$t8,$at
/*  f1902c4:	3c01dfff */ 	lui	$at,0xdfff
/*  f1902c8:	44801000 */ 	mtc1	$zero,$f2
/*  f1902cc:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1902d0:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1902d4:	01014824 */ 	and	$t1,$t0,$at
/*  f1902d8:	a08f000c */ 	sb	$t7,0xc($a0)
/*  f1902dc:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f1902e0:	ac890014 */ 	sw	$t1,0x14($a0)
/*  f1902e4:	a08a02a0 */ 	sb	$t2,0x2a0($a0)
/*  f1902e8:	11c000a0 */ 	beqz	$t6,.L0f19056c
/*  f1902ec:	e482014c */ 	swc1	$f2,0x14c($a0)
/*  f1902f0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1902f4:	44051000 */ 	mfc1	$a1,$f2
/*  f1902f8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f1902fc:	e4820100 */ 	swc1	$f2,0x100($a0)
/*  f190300:	a486017e */ 	sh	$a2,0x17e($a0)
/*  f190304:	a486012a */ 	sh	$a2,0x12a($a0)
/*  f190308:	0fc0cfea */ 	jal	chrSetShield
/*  f19030c:	a4860292 */ 	sh	$a2,0x292($a0)
/*  f190310:	a2200184 */ 	sb	$zero,0x184($s1)
/*  f190314:	a2200185 */ 	sb	$zero,0x185($s1)
/*  f190318:	0fc29c32 */ 	jal	freeFireslot
/*  f19031c:	8224017c */ 	lb	$a0,0x17c($s1)
/*  f190320:	0fc29c32 */ 	jal	freeFireslot
/*  f190324:	8224017d */ 	lb	$a0,0x17d($s1)
/*  f190328:	922b032d */ 	lbu	$t3,0x32d($s1)
/*  f19032c:	3c014339 */ 	lui	$at,0x4339
/*  f190330:	44812000 */ 	mtc1	$at,$f4
/*  f190334:	316dfff3 */ 	andi	$t5,$t3,0xfff3
/*  f190338:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f19033c:	a22d032d */ 	sb	$t5,0x32d($s1)
/*  f190340:	31ae007f */ 	andi	$t6,$t5,0x7f
/*  f190344:	a226017c */ 	sb	$a2,0x17c($s1)
/*  f190348:	a226017d */ 	sb	$a2,0x17d($s1)
/*  f19034c:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f190350:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f190354:	ae200170 */ 	sw	$zero,0x170($s1)
/*  f190358:	ae200174 */ 	sw	$zero,0x174($s1)
/*  f19035c:	ae200178 */ 	sw	$zero,0x178($s1)
/*  f190360:	a220032c */ 	sb	$zero,0x32c($s1)
/*  f190364:	a22e032d */ 	sb	$t6,0x32d($s1)
/*  f190368:	ae200364 */ 	sw	$zero,0x364($s1)
/*  f19036c:	00001825 */ 	or	$v1,$zero,$zero
/*  f190370:	e6240028 */ 	swc1	$f4,0x28($s1)
.L0f190374:
/*  f190374:	8e0f001c */ 	lw	$t7,0x1c($s0)
/*  f190378:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f19037c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190380:	28610084 */ 	slti	$at,$v1,0x84
/*  f190384:	1420fffb */ 	bnez	$at,.L0f190374
/*  f190388:	af000000 */ 	sw	$zero,0x0($t8)
/*  f19038c:	0fc65f00 */ 	jal	aibotClearInventory
/*  f190390:	02202025 */ 	or	$a0,$s1,$zero
/*  f190394:	9208004c */ 	lbu	$t0,0x4c($s0)
/*  f190398:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f19039c:	44801000 */ 	mtc1	$zero,$f2
/*  f1903a0:	310bffdf */ 	andi	$t3,$t0,0xffdf
/*  f1903a4:	31d8ff7f */ 	andi	$t8,$t6,0xff7f
/*  f1903a8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1903ac:	35680040 */ 	ori	$t0,$t3,0x40
/*  f1903b0:	a20b004c */ 	sb	$t3,0x4c($s0)
/*  f1903b4:	310c00fd */ 	andi	$t4,$t0,0xfd
/*  f1903b8:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f1903bc:	a218009c */ 	sb	$t8,0x9c($s0)
/*  f1903c0:	330a00bf */ 	andi	$t2,$t8,0xbf
/*  f1903c4:	318e00f7 */ 	andi	$t6,$t4,0xf7
/*  f1903c8:	a20c004c */ 	sb	$t4,0x4c($s0)
/*  f1903cc:	31d800ef */ 	andi	$t8,$t6,0xef
/*  f1903d0:	a20e004c */ 	sb	$t6,0x4c($s0)
/*  f1903d4:	330800fb */ 	andi	$t0,$t8,0xfb
/*  f1903d8:	a218004c */ 	sb	$t8,0x4c($s0)
/*  f1903dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f1903e0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1903e4:	240d012d */ 	addiu	$t5,$zero,0x12d
/*  f1903e8:	a20a009c */ 	sb	$t2,0x9c($s0)
/*  f1903ec:	314b00df */ 	andi	$t3,$t2,0xdf
/*  f1903f0:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f1903f4:	3109007f */ 	andi	$t1,$t0,0x7f
/*  f1903f8:	44810000 */ 	mtc1	$at,$f0
/*  f1903fc:	ae190020 */ 	sw	$t9,0x20($s0)
/*  f190400:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f190404:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f190408:	ae000010 */ 	sw	$zero,0x10($s0)
/*  f19040c:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f190410:	a600002e */ 	sh	$zero,0x2e($s0)
/*  f190414:	ae00005c */ 	sw	$zero,0x5c($s0)
/*  f190418:	ae000060 */ 	sw	$zero,0x60($s0)
/*  f19041c:	a2060074 */ 	sb	$a2,0x74($s0)
/*  f190420:	ae0d0030 */ 	sw	$t5,0x30($s0)
/*  f190424:	ae000034 */ 	sw	$zero,0x34($s0)
/*  f190428:	a200004d */ 	sb	$zero,0x4d($s0)
/*  f19042c:	a200004e */ 	sb	$zero,0x4e($s0)
/*  f190430:	ae000044 */ 	sw	$zero,0x44($s0)
/*  f190434:	ae0000a0 */ 	sw	$zero,0xa0($s0)
/*  f190438:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19043c:	a6000064 */ 	sh	$zero,0x64($s0)
/*  f190440:	a209004c */ 	sb	$t1,0x4c($s0)
/*  f190444:	a6060048 */ 	sh	$a2,0x48($s0)
/*  f190448:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f19044c:	ae0600bc */ 	sw	$a2,0xbc($s0)
/*  f190450:	ae0000c8 */ 	sw	$zero,0xc8($s0)
/*  f190454:	ae0000c4 */ 	sw	$zero,0xc4($s0)
/*  f190458:	ae0000cc */ 	sw	$zero,0xcc($s0)
/*  f19045c:	ae0000d0 */ 	sw	$zero,0xd0($s0)
/*  f190460:	ae0000d8 */ 	sw	$zero,0xd8($s0)
/*  f190464:	ae0000dc */ 	sw	$zero,0xdc($s0)
/*  f190468:	a606003e */ 	sh	$a2,0x3e($s0)
/*  f19046c:	a600003c */ 	sh	$zero,0x3c($s0)
/*  f190470:	a60000e2 */ 	sh	$zero,0xe2($s0)
/*  f190474:	a60000e0 */ 	sh	$zero,0xe0($s0)
/*  f190478:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f19047c:	ae00011c */ 	sw	$zero,0x11c($s0)
/*  f190480:	ae060120 */ 	sw	$a2,0x120($s0)
/*  f190484:	ae060124 */ 	sw	$a2,0x124($s0)
/*  f190488:	ae000128 */ 	sw	$zero,0x128($s0)
/*  f19048c:	ae00012c */ 	sw	$zero,0x12c($s0)
/*  f190490:	00002025 */ 	or	$a0,$zero,$zero
/*  f190494:	02001025 */ 	or	$v0,$s0,$zero
/*  f190498:	02001825 */ 	or	$v1,$s0,$zero
/*  f19049c:	02002825 */ 	or	$a1,$s0,$zero
/*  f1904a0:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f1904a4:	e6020040 */ 	swc1	$f2,0x40($s0)
/*  f1904a8:	e602006c */ 	swc1	$f2,0x6c($s0)
/*  f1904ac:	e6020070 */ 	swc1	$f2,0x70($s0)
/*  f1904b0:	e60200e8 */ 	swc1	$f2,0xe8($s0)
/*  f1904b4:	e60200e4 */ 	swc1	$f2,0xe4($s0)
/*  f1904b8:	e6020108 */ 	swc1	$f2,0x108($s0)
/*  f1904bc:	e602010c */ 	swc1	$f2,0x10c($s0)
/*  f1904c0:	e6020110 */ 	swc1	$f2,0x110($s0)
.L0f1904c4:
/*  f1904c4:	a0460130 */ 	sb	$a2,0x130($v0)
/*  f1904c8:	e460013c */ 	swc1	$f0,0x13c($v1)
/*  f1904cc:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f1904d0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1904d4:	ac660178 */ 	sw	$a2,0x178($v1)
/*  f1904d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1904dc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1904e0:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f1904e4:	1487fff7 */ 	bne	$a0,$a3,.L0f1904c4
/*  f1904e8:	a4a601a6 */ 	sh	$a2,0x1a6($a1)
/*  f1904ec:	ae0001e8 */ 	sw	$zero,0x1e8($s0)
/*  f1904f0:	0c004b70 */ 	jal	random
/*  f1904f4:	ae000208 */ 	sw	$zero,0x208($s0)
/*  f1904f8:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f1904fc:	44801000 */ 	mtc1	$zero,$f2
/*  f190500:	ae020210 */ 	sw	$v0,0x210($s0)
/*  f190504:	314bffef */ 	andi	$t3,$t2,0xffef
/*  f190508:	ae00020c */ 	sw	$zero,0x20c($s0)
/*  f19050c:	ae0002c8 */ 	sw	$zero,0x2c8($s0)
/*  f190510:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f190514:	ae0002cc */ 	sw	$zero,0x2cc($s0)
/*  f190518:	0c004b70 */ 	jal	random
/*  f19051c:	e60202c4 */ 	swc1	$f2,0x2c4($s0)
/*  f190520:	0c004b70 */ 	jal	random
/*  f190524:	ae0202d0 */ 	sw	$v0,0x2d0($s0)
/*  f190528:	44823000 */ 	mtc1	$v0,$f6
/*  f19052c:	3c014f80 */ 	lui	$at,0x4f80
/*  f190530:	04410004 */ 	bgez	$v0,.L0f190544
/*  f190534:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f190538:	44815000 */ 	mtc1	$at,$f10
/*  f19053c:	00000000 */ 	nop
/*  f190540:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f190544:
/*  f190544:	3c012f80 */ 	lui	$at,0x2f80
/*  f190548:	44818000 */ 	mtc1	$at,$f16
/*  f19054c:	920c009c */ 	lbu	$t4,0x9c($s0)
/*  f190550:	a2000078 */ 	sb	$zero,0x78($s0)
/*  f190554:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f190558:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*  f19055c:	a20d009c */ 	sb	$t5,0x9c($s0)
/*  f190560:	ae000050 */ 	sw	$zero,0x50($s0)
/*  f190564:	a200009d */ 	sb	$zero,0x9d($s0)
/*  f190568:	e61202d4 */ 	swc1	$f18,0x2d4($s0)
.L0f19056c:
/*  f19056c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f190570:	2401000b */ 	addiu	$at,$zero,0xb
/*  f190574:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f190578:	10610002 */ 	beq	$v1,$at,.L0f190584
/*  f19057c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f190580:	14610005 */ 	bne	$v1,$at,.L0f190598
.L0f190584:
/*  f190584:	3c014100 */ 	lui	$at,0x4100
/*  f190588:	44812000 */ 	mtc1	$at,$f4
/*  f19058c:	00000000 */ 	nop
/*  f190590:	e6240180 */ 	swc1	$f4,0x180($s1)
/*  f190594:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f190598:
/*  f190598:	904e0048 */ 	lbu	$t6,0x48($v0)
/*  f19059c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1905a0:	55c1000b */ 	bnel	$t6,$at,.L0f1905d0
/*  f1905a4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1905a8:	960f0064 */ 	lhu	$t7,0x64($s0)
/*  f1905ac:	31f8fffe */ 	andi	$t8,$t7,0xfffe
/*  f1905b0:	0fc6609e */ 	jal	mpHasShield
/*  f1905b4:	a6180064 */ 	sh	$t8,0x64($s0)
/*  f1905b8:	10400004 */ 	beqz	$v0,.L0f1905cc
/*  f1905bc:	3c014100 */ 	lui	$at,0x4100
/*  f1905c0:	44813000 */ 	mtc1	$at,$f6
/*  f1905c4:	00000000 */ 	nop
/*  f1905c8:	e6260180 */ 	swc1	$f6,0x180($s1)
.L0f1905cc:
/*  f1905cc:	24190001 */ 	addiu	$t9,$zero,0x1
.L0f1905d0:
/*  f1905d0:	24080078 */ 	addiu	$t0,$zero,0x78
/*  f1905d4:	a2190059 */ 	sb	$t9,0x59($s0)
/*  f1905d8:	a2080058 */ 	sb	$t0,0x58($s0)
.L0f1905dc:
/*  f1905dc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1905e0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1905e4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1905e8:	03e00008 */ 	jr	$ra
/*  f1905ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#else
GLOBAL_ASM(
glabel mpChrReset
/*  f18a44c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f18a450:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f18a454:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f18a458:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f18a45c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f18a460:	8c9002d4 */ 	lw	$s0,0x2d4($a0)
/*  f18a464:	00808825 */ 	or	$s1,$a0,$zero
/*  f18a468:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f18a46c:	120000c4 */ 	beqz	$s0,.NB0f18a780
/*  f18a470:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18a474:	8c980018 */ 	lw	$t8,0x18($a0)
/*  f18a478:	2401feff */ 	addiu	$at,$zero,-257
/*  f18a47c:	8c880014 */ 	lw	$t0,0x14($a0)
/*  f18a480:	0301c824 */ 	and	$t9,$t8,$at
/*  f18a484:	3c01dfff */ 	lui	$at,0xdfff
/*  f18a488:	44801000 */ 	mtc1	$zero,$f2
/*  f18a48c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f18a490:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f18a494:	01014824 */ 	and	$t1,$t0,$at
/*  f18a498:	a08f000c */ 	sb	$t7,0xc($a0)
/*  f18a49c:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f18a4a0:	ac890014 */ 	sw	$t1,0x14($a0)
/*  f18a4a4:	a08a02a0 */ 	sb	$t2,0x2a0($a0)
/*  f18a4a8:	11c00099 */ 	beqz	$t6,.NB0f18a710
/*  f18a4ac:	e482014c */ 	swc1	$f2,0x14c($a0)
/*  f18a4b0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f18a4b4:	44051000 */ 	mfc1	$a1,$f2
/*  f18a4b8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f18a4bc:	e4820100 */ 	swc1	$f2,0x100($a0)
/*  f18a4c0:	a486017e */ 	sh	$a2,0x17e($a0)
/*  f18a4c4:	a486012a */ 	sh	$a2,0x12a($a0)
/*  f18a4c8:	0fc0ce2c */ 	jal	chrSetShield
/*  f18a4cc:	a4860292 */ 	sh	$a2,0x292($a0)
/*  f18a4d0:	922b032d */ 	lbu	$t3,0x32d($s1)
/*  f18a4d4:	3c014339 */ 	lui	$at,0x4339
/*  f18a4d8:	44812000 */ 	mtc1	$at,$f4
/*  f18a4dc:	316dfff3 */ 	andi	$t5,$t3,0xfff3
/*  f18a4e0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f18a4e4:	a22d032d */ 	sb	$t5,0x32d($s1)
/*  f18a4e8:	31ae007f */ 	andi	$t6,$t5,0x7f
/*  f18a4ec:	a2200184 */ 	sb	$zero,0x184($s1)
/*  f18a4f0:	a2200185 */ 	sb	$zero,0x185($s1)
/*  f18a4f4:	a226017c */ 	sb	$a2,0x17c($s1)
/*  f18a4f8:	a226017d */ 	sb	$a2,0x17d($s1)
/*  f18a4fc:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f18a500:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f18a504:	ae200170 */ 	sw	$zero,0x170($s1)
/*  f18a508:	ae200174 */ 	sw	$zero,0x174($s1)
/*  f18a50c:	ae200178 */ 	sw	$zero,0x178($s1)
/*  f18a510:	a220032c */ 	sb	$zero,0x32c($s1)
/*  f18a514:	a22e032d */ 	sb	$t6,0x32d($s1)
/*  f18a518:	ae200364 */ 	sw	$zero,0x364($s1)
/*  f18a51c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18a520:	e6240028 */ 	swc1	$f4,0x28($s1)
.NB0f18a524:
/*  f18a524:	8e0f001c */ 	lw	$t7,0x1c($s0)
/*  f18a528:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f18a52c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18a530:	28410084 */ 	slti	$at,$v0,0x84
/*  f18a534:	1420fffb */ 	bnez	$at,.NB0f18a524
/*  f18a538:	af000000 */ 	sw	$zero,0x0($t8)
/*  f18a53c:	0fc646f8 */ 	jal	aibotClearInventory
/*  f18a540:	02202025 */ 	or	$a0,$s1,$zero
/*  f18a544:	9208004c */ 	lbu	$t0,0x4c($s0)
/*  f18a548:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f18a54c:	44801000 */ 	mtc1	$zero,$f2
/*  f18a550:	310bffdf */ 	andi	$t3,$t0,0xffdf
/*  f18a554:	31d8ff7f */ 	andi	$t8,$t6,0xff7f
/*  f18a558:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f18a55c:	35680040 */ 	ori	$t0,$t3,0x40
/*  f18a560:	a20b004c */ 	sb	$t3,0x4c($s0)
/*  f18a564:	310c00fd */ 	andi	$t4,$t0,0xfd
/*  f18a568:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f18a56c:	a218009c */ 	sb	$t8,0x9c($s0)
/*  f18a570:	330a00bf */ 	andi	$t2,$t8,0xbf
/*  f18a574:	318e00f7 */ 	andi	$t6,$t4,0xf7
/*  f18a578:	a20c004c */ 	sb	$t4,0x4c($s0)
/*  f18a57c:	31d800ef */ 	andi	$t8,$t6,0xef
/*  f18a580:	a20e004c */ 	sb	$t6,0x4c($s0)
/*  f18a584:	330800fb */ 	andi	$t0,$t8,0xfb
/*  f18a588:	a218004c */ 	sb	$t8,0x4c($s0)
/*  f18a58c:	3c014f80 */ 	lui	$at,0x4f80
/*  f18a590:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18a594:	240d012d */ 	addiu	$t5,$zero,0x12d
/*  f18a598:	a20a009c */ 	sb	$t2,0x9c($s0)
/*  f18a59c:	314b00df */ 	andi	$t3,$t2,0xdf
/*  f18a5a0:	a208004c */ 	sb	$t0,0x4c($s0)
/*  f18a5a4:	3109007f */ 	andi	$t1,$t0,0x7f
/*  f18a5a8:	44810000 */ 	mtc1	$at,$f0
/*  f18a5ac:	ae190020 */ 	sw	$t9,0x20($s0)
/*  f18a5b0:	ae000024 */ 	sw	$zero,0x24($s0)
/*  f18a5b4:	ae000028 */ 	sw	$zero,0x28($s0)
/*  f18a5b8:	ae000010 */ 	sw	$zero,0x10($s0)
/*  f18a5bc:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f18a5c0:	a600002e */ 	sh	$zero,0x2e($s0)
/*  f18a5c4:	ae00005c */ 	sw	$zero,0x5c($s0)
/*  f18a5c8:	ae000060 */ 	sw	$zero,0x60($s0)
/*  f18a5cc:	a2060074 */ 	sb	$a2,0x74($s0)
/*  f18a5d0:	ae0d0030 */ 	sw	$t5,0x30($s0)
/*  f18a5d4:	ae000034 */ 	sw	$zero,0x34($s0)
/*  f18a5d8:	a200004d */ 	sb	$zero,0x4d($s0)
/*  f18a5dc:	a200004e */ 	sb	$zero,0x4e($s0)
/*  f18a5e0:	ae000044 */ 	sw	$zero,0x44($s0)
/*  f18a5e4:	ae0000a0 */ 	sw	$zero,0xa0($s0)
/*  f18a5e8:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f18a5ec:	a6000064 */ 	sh	$zero,0x64($s0)
/*  f18a5f0:	a209004c */ 	sb	$t1,0x4c($s0)
/*  f18a5f4:	a6060048 */ 	sh	$a2,0x48($s0)
/*  f18a5f8:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f18a5fc:	ae0600bc */ 	sw	$a2,0xbc($s0)
/*  f18a600:	ae0000c8 */ 	sw	$zero,0xc8($s0)
/*  f18a604:	ae0000c4 */ 	sw	$zero,0xc4($s0)
/*  f18a608:	ae0000cc */ 	sw	$zero,0xcc($s0)
/*  f18a60c:	ae0000d0 */ 	sw	$zero,0xd0($s0)
/*  f18a610:	ae0000d8 */ 	sw	$zero,0xd8($s0)
/*  f18a614:	ae0000dc */ 	sw	$zero,0xdc($s0)
/*  f18a618:	a606003e */ 	sh	$a2,0x3e($s0)
/*  f18a61c:	a600003c */ 	sh	$zero,0x3c($s0)
/*  f18a620:	a60000e2 */ 	sh	$zero,0xe2($s0)
/*  f18a624:	a60000e0 */ 	sh	$zero,0xe0($s0)
/*  f18a628:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f18a62c:	ae00011c */ 	sw	$zero,0x11c($s0)
/*  f18a630:	ae060120 */ 	sw	$a2,0x120($s0)
/*  f18a634:	ae060124 */ 	sw	$a2,0x124($s0)
/*  f18a638:	ae000128 */ 	sw	$zero,0x128($s0)
/*  f18a63c:	ae00012c */ 	sw	$zero,0x12c($s0)
/*  f18a640:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a644:	02001025 */ 	or	$v0,$s0,$zero
/*  f18a648:	02001825 */ 	or	$v1,$s0,$zero
/*  f18a64c:	02002825 */ 	or	$a1,$s0,$zero
/*  f18a650:	2407000c */ 	addiu	$a3,$zero,0xc
/*  f18a654:	e6020040 */ 	swc1	$f2,0x40($s0)
/*  f18a658:	e602006c */ 	swc1	$f2,0x6c($s0)
/*  f18a65c:	e6020070 */ 	swc1	$f2,0x70($s0)
/*  f18a660:	e60200e8 */ 	swc1	$f2,0xe8($s0)
/*  f18a664:	e60200e4 */ 	swc1	$f2,0xe4($s0)
/*  f18a668:	e6020108 */ 	swc1	$f2,0x108($s0)
/*  f18a66c:	e602010c */ 	swc1	$f2,0x10c($s0)
/*  f18a670:	e6020110 */ 	swc1	$f2,0x110($s0)
.NB0f18a674:
/*  f18a674:	a0460130 */ 	sb	$a2,0x130($v0)
/*  f18a678:	e460013c */ 	swc1	$f0,0x13c($v1)
/*  f18a67c:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f18a680:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f18a684:	ac660178 */ 	sw	$a2,0x178($v1)
/*  f18a688:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18a68c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18a690:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f18a694:	1487fff7 */ 	bne	$a0,$a3,.NB0f18a674
/*  f18a698:	a4a601a6 */ 	sh	$a2,0x1a6($a1)
/*  f18a69c:	ae0001e8 */ 	sw	$zero,0x1e8($s0)
/*  f18a6a0:	0c004d84 */ 	jal	random
/*  f18a6a4:	ae000208 */ 	sw	$zero,0x208($s0)
/*  f18a6a8:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f18a6ac:	44801000 */ 	mtc1	$zero,$f2
/*  f18a6b0:	ae020210 */ 	sw	$v0,0x210($s0)
/*  f18a6b4:	314bffef */ 	andi	$t3,$t2,0xffef
/*  f18a6b8:	ae00020c */ 	sw	$zero,0x20c($s0)
/*  f18a6bc:	ae0002c8 */ 	sw	$zero,0x2c8($s0)
/*  f18a6c0:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f18a6c4:	ae0002cc */ 	sw	$zero,0x2cc($s0)
/*  f18a6c8:	0c004d84 */ 	jal	random
/*  f18a6cc:	e60202c4 */ 	swc1	$f2,0x2c4($s0)
/*  f18a6d0:	0c004d84 */ 	jal	random
/*  f18a6d4:	ae0202d0 */ 	sw	$v0,0x2d0($s0)
/*  f18a6d8:	44823000 */ 	mtc1	$v0,$f6
/*  f18a6dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f18a6e0:	04410004 */ 	bgez	$v0,.NB0f18a6f4
/*  f18a6e4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f18a6e8:	44815000 */ 	mtc1	$at,$f10
/*  f18a6ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a6f0:	460a4200 */ 	add.s	$f8,$f8,$f10
.NB0f18a6f4:
/*  f18a6f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f18a6f8:	44818000 */ 	mtc1	$at,$f16
/*  f18a6fc:	920c009c */ 	lbu	$t4,0x9c($s0)
/*  f18a700:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f18a704:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*  f18a708:	a20d009c */ 	sb	$t5,0x9c($s0)
/*  f18a70c:	e61202d4 */ 	swc1	$f18,0x2d4($s0)
.NB0f18a710:
/*  f18a710:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f18a714:	2401000b */ 	addiu	$at,$zero,0xb
/*  f18a718:	90430047 */ 	lbu	$v1,0x47($v0)
/*  f18a71c:	10610002 */ 	beq	$v1,$at,.NB0f18a728
/*  f18a720:	24010002 */ 	addiu	$at,$zero,0x2
/*  f18a724:	14610005 */ 	bne	$v1,$at,.NB0f18a73c
.NB0f18a728:
/*  f18a728:	3c014100 */ 	lui	$at,0x4100
/*  f18a72c:	44812000 */ 	mtc1	$at,$f4
/*  f18a730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a734:	e6240180 */ 	swc1	$f4,0x180($s1)
/*  f18a738:	8e020004 */ 	lw	$v0,0x4($s0)
.NB0f18a73c:
/*  f18a73c:	904e0048 */ 	lbu	$t6,0x48($v0)
/*  f18a740:	24010005 */ 	addiu	$at,$zero,0x5
/*  f18a744:	55c1000b */ 	bnel	$t6,$at,.NB0f18a774
/*  f18a748:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f18a74c:	960f0064 */ 	lhu	$t7,0x64($s0)
/*  f18a750:	31f8fffe */ 	andi	$t8,$t7,0xfffe
/*  f18a754:	0fc64896 */ 	jal	mpHasShield
/*  f18a758:	a6180064 */ 	sh	$t8,0x64($s0)
/*  f18a75c:	10400004 */ 	beqz	$v0,.NB0f18a770
/*  f18a760:	3c014100 */ 	lui	$at,0x4100
/*  f18a764:	44813000 */ 	mtc1	$at,$f6
/*  f18a768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a76c:	e6260180 */ 	swc1	$f6,0x180($s1)
.NB0f18a770:
/*  f18a770:	24190001 */ 	addiu	$t9,$zero,0x1
.NB0f18a774:
/*  f18a774:	24080078 */ 	addiu	$t0,$zero,0x78
/*  f18a778:	a2190059 */ 	sb	$t9,0x59($s0)
/*  f18a77c:	a2080058 */ 	sb	$t0,0x58($s0)
.NB0f18a780:
/*  f18a780:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f18a784:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f18a788:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f18a78c:	03e00008 */ 	jr	$ra
/*  f18a790:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

//void mpChrReset(struct chrdata *chr, u8 full)
//{
//	s32 i;
//	u32 rand;
//
//	if (chr->aibot) {
//		struct aibot *aibot = chr->aibot;
//
//		chr->fadealpha = -1;
//		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
//		chr->hidden &= ~CHRHFLAG_CLOAKED;
//		chr->myaction = MA_AIBOTMAINLOOP;
//		chr->shotbondsum = 0;
//
//		if (full) {
//			chr->numclosearghs = 0;
//			chr->damage = 0;
//			chr->target = -1;
//			chr->chrpreset1 = -1;
//			chr->cover = -1;
//			chrSetShield(chr, 0);
//			chr->cmnum = 0;
//			chr->cmnum2 = 0;
//			freeFireslot(chr->fireslot[0]);
//			freeFireslot(chr->fireslot[1]);
//			chr->unk32c_12 = 0;
//			chr->fireslot[0] = -1;
//			chr->fireslot[1] = -1;
//			chr->firecount[0] = 0;
//			chr->firecount[1] = 0;
//			chr->weapons_held[0] = NULL;
//			chr->weapons_held[1] = NULL;
//			chr->unk178 = 0;
//			chr->liftaction = 0;
//			chr->inlift = 0;
//			chr->unk364 = 0;
//			chr->chrheight = 185;
//
//			for (i = 0; i < 33; i++) {
//				aibot->unk01c->unk00[i] = 0;
//			}
//
//			aibotClearInventory(chr);
//
//			aibot->gunfunc = 0;
//			aibot->iscloserangeweapon = true;
//			aibot->unk09c_00 = 0;
//			aibot->cloakdeviceenabled = false;
//			aibot->unk04c_04 = 0;
//			aibot->unk04c_03 = 0;
//			aibot->unk09c_01 = 0;
//			aibot->unk04c_05 = 0;
//			aibot->weaponnum = WEAPON_UNARMED;
//			aibot->loadedammo[0] = 0;
//			aibot->loadedammo[1] = 0;
//			aibot->fetchprop = NULL;
//			aibot->unk02c = 0;
//			aibot->unk02e = 0;
//			aibot->unk05c = 0;
//			aibot->unk060 = 0;
//			aibot->unk074 = -1;
//			aibot->unk030 = 301;
//			aibot->unk034 = 0;
//			aibot->unk04d = 0;
//			aibot->unk04e = 0;
//			aibot->skrocket = NULL;
//			aibot->unk0a0 = 0;
//			aibot->rcp120cloakenabled = false;
//			aibot->unk064 = 0;
//			aibot->unk04c_00 = 0;
//			aibot->unk048 = -1;
//			aibot->unk04a = -1;
//			aibot->unk0bc = -1;
//			aibot->unk0c8 = 0;
//			aibot->unk0c4 = 0;
//			aibot->unk0cc = 0;
//			aibot->unk0d0 = 0;
//			aibot->unk0d8 = 0;
//			aibot->unk0dc = 0;
//			aibot->unk03e = -1;
//			aibot->unk03c = 0;
//			aibot->unk0e2 = 0;
//			aibot->unk0e0 = 0;
//			aibot->unk118 = 0;
//			aibot->unk11c = 0;
//			aibot->unk120 = -1;
//			aibot->unk124 = -1;
//			aibot->unk128 = 0;
//			aibot->unk12c = 0;
//			aibot->unk040 = 0;
//			aibot->unk06c = 0;
//			aibot->unk070 = 0;
//			aibot->unk0e8 = 0;
//			aibot->unk0e4 = 0;
//			aibot->unk108 = 0;
//			aibot->unk10c = 0;
//			aibot->unk110 = 0;
//
//			for (i = 0; i != 12; i++) {
//				aibot->unk130[i] = -1;
//				aibot->playerdistances[i] = U32_MAX;
//				aibot->unk16c[i] = 0;
//				aibot->unk178[i] = -1;
//				aibot->unk1a8[i] = -1;
//			}
//
//			aibot->unk1e8 = 0;
//			aibot->unk208 = 0;
//			aibot->rand = random();
//			aibot->randttl60 = 0;
//			aibot->unk2c8 = 0;
//			aibot->unk09c_03 = 0;
//			aibot->unk2cc = 0;
//			aibot->unk2c4 = 0;
//
//			aibot->unk2d0 = random();
//			aibot->aibot = random();
//			aibot->unk078 = 0;
//			aibot->cheap = 0;
//			aibot->unk050 = 0;
//			aibot->unk09d = 0;
//		}
//
//		if (aibot->simulant->type == SIMTYPE_TURTLE || aibot->simulant->type == SIMTYPE_SHIELD) {
//			chr->cshield = 8;
//		}
//
//		if (aibot->simulant->difficulty == SIMDIFF_DARK) {
//			aibot->unk064 &= ~1;
//
//			if (mpHasShield()) {
//				chr->cshield = 8;
//			}
//		}
//
//		aibot->unk059 = 1;
//		aibot->unk058 = 120;
//	}
//}

void mpInitSimulant(struct chrdata *chr, u8 full)
{
	f32 thing;
	struct prop *prop;
	struct defaultobj *obj;
	struct aibot *aibot = chr->aibot;
	struct coord pos;
	s16 rooms[8];

	if (chr->prop) {
		prop = chr->prop->child;

		while (prop) {
			obj = prop->obj;

			if (obj) {
				obj->hidden |= OBJHFLAG_REAPABLE;
			}

			prop = prop->next;
		}
	}

	if (aibot) {
		mpChrReset(chr, full);
		chrInitSplats(chr);
		thing = scenarioChooseSpawnLocation(chr->chrwidth, &pos, rooms, chr->prop);
		chr->hidden |= CHRHFLAG_00100000;
		chrMoveToPos(chr, &pos, rooms, thing, true);
		chr->aibot->unk0a4 = func0001ae44(chr->model);
		chr->aibot->angleoffset = 0;
		chr->aibot->speedtheta = 0;
		chr->aibot->unk0b0 = func0001ae44(chr->model);
		chr->aibot->unk0b4 = 0;
		chr->aibot->unk0b8 = 0;
		func0f02e9a0(chr, 0);
	}
}

void mpInitSimulants(void)
{
	s32 i;

	for (i = 0; i < g_NumMpSimulantChrs; i++) {
		mpInitSimulant(g_MpSimulantChrs[i], false);
	}
}

#if PIRACYCHECKS
u32 add87654321(u32 value)
{
	return value + 0x87654321;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
u32 propobjHandlePickupByAibot(struct prop *prop, struct chrdata *chr)
{
	struct defaultobj *obj = prop->obj;

	if (!chr || !chr->aibot) {
		return 0;
	}

	dprint();

	obj->flags3 &= ~OBJFLAG3_00004000;

	switch (obj->type) {
	case OBJTYPE_KEY:
		// Missing break, but doesn't matter as keys don't exist in multiplayer
	case OBJTYPE_AMMOCRATE:
		{
			struct ammocrateobj *crate = (struct ammocrateobj *)prop->obj;
			u32 qty = ammocrateGetPickupAmmoQty((struct ammocrateobj *)prop->obj);
			dprint();

			if (qty) {
				aibotGiveAmmoByType(chr->aibot, crate->ammotype, qty);
			}

			// Pickup sound
			func0f0939f8(NULL, prop, SFX_PICKUP_AMMO, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			objRemove2(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);

			if (qty) {
				dprint();
			}
		}
		return 2;
	case OBJTYPE_MULTIAMMOCRATE:
		{
			struct multiammocrateobj *crate = (struct multiammocrateobj *)prop->obj;
			u32 padding[1];
			u32 qty;
			s32 i;
#if PIRACYCHECKS
			{
				u32 *ptr = (u32 *)&func0f08e2ac;
				u32 *end = (u32 *)&doorSetMode;
				u32 checksum = 0;

				while (ptr < end) {
					checksum += *ptr;
					checksum *= 2;
					ptr++;
				}

				if (checksum != CHECKSUM_PLACEHOLDER) {
					u32 *ptr = (u32 *)chrCheckTargetInSight;
					ptr[0] = add87654321(0x24020001 - 0x87654321); // addiu v0,zero,1
					ptr[1] = add87654321(0x03e00008 - 0x87654321); // jr ra
					ptr[2] = add87654321(0x00000000 - 0x87654321); // nop
				}
			}
#endif
			dprint();

			for (i = 0; i != 19; i++) {
				qty = crate->slots[i].quantity;

				if (qty) {
					dprint();
				}

				if (qty) {
					aibotGiveAmmoByType(chr->aibot, i + 1, qty);
				}
			}

			// Pickup sound
			func0f0939f8(NULL, prop, SFX_PICKUP_AMMO, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			objRemove2(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		}
		return 2;
	case OBJTYPE_WEAPON:
		{
			struct weaponobj *weapon = prop->weapon;
			u32 itemtype = aibotGetInvItemType(chr, weapon->weaponnum);
			u32 result;
			u32 qty;

			if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
				result = chrGiveBriefcase(chr, prop);
			} else if (weapon->weaponnum == WEAPON_DATAUPLINK) {
				result = chrGiveUplink(chr, prop);
			} else {
				propPlayPickupSound(prop, weapon->weaponnum);
				qty = weaponGetPickupAmmoQty(weapon);

				if (qty) {
					aibotGiveAmmoByWeapon(chr->aibot, weapon->weaponnum, weapon->gunfunc, qty);
				}

				if (itemtype) {
					struct weapon *weapondef = weaponFindById(weapon->weaponnum);
					u32 originalpad = aibotGetWeaponPad(chr, weapon->weaponnum);
					u32 currentpad = obj->pad;

					if (itemtype == INVITEMTYPE_WEAP
							&& weapondef
							&& (weapondef->flags & WEAPONFLAG_DUALWIELD)
							&& originalpad != currentpad) {
						aibotGiveDualWeapon(chr, weapon->weaponnum);
						result = 1;
					} else {
						result = 2;
					}
				} else {
					aibotGiveProp(chr, prop);
					result = 1;
				}

				objRemove2(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			}

			return result;
		}
	case OBJTYPE_SHIELD:
		{
			struct shieldobj *shield = (struct shieldobj *)prop->obj;

			func0f0939f8(NULL, prop, SFX_PICKUP_SHIELD, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			chrSetShield(chr, shield->amount * 8);
			objRemove2(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		}
		return 3;
	case OBJTYPE_BASIC:
	case OBJTYPE_ALARM:
	case OBJTYPE_CCTV:
	case OBJTYPE_CHR:
	case OBJTYPE_SINGLEMONITOR:
	case OBJTYPE_MULTIMONITOR:
	case OBJTYPE_HANGINGMONITORS:
	case OBJTYPE_AUTOGUN:
	case OBJTYPE_LINKGUNS:
	case OBJTYPE_DEBRIS:
	case OBJTYPE_10:
	case OBJTYPE_HAT:
	case OBJTYPE_GRENADEPROB:
	case OBJTYPE_LINKLIFTDOOR:
	case OBJTYPE_TAG:
	case OBJTYPE_22:
	case OBJTYPE_BRIEFING:
	case OBJTYPE_GASBOTTLE:
	case OBJTYPE_RENAMEOBJ:
	case OBJTYPE_PADLOCKEDDOOR:
	case OBJTYPE_TRUCK:
	case OBJTYPE_HELI:
	case OBJTYPE_29:
	case OBJTYPE_GLASS:
	case OBJTYPE_SAFE:
	case OBJTYPE_SAFEITEM:
	case OBJTYPE_TANK:
	case OBJTYPE_CAMERAPOS:
	case OBJTYPE_TINTEDGLASS:
		break;
	}

	return 0;
}
#else
GLOBAL_ASM(
glabel propobjHandlePickupByAibot
.late_rodata
glabel var7f1b33d0nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33d4nb
.word propobjHandlePickupByAibot+0x080
glabel var7f1b33d8nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33dcnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33e0nb
.word propobjHandlePickupByAibot+0x080
glabel var7f1b33e4nb
.word propobjHandlePickupByAibot+0x1f4
glabel var7f1b33e8nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33ecnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33f0nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33f4nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33f8nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b33fcnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3400nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3404nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3408nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b340cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3410nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3414nb
.word propobjHandlePickupByAibot+0x130
glabel var7f1b3418nb
.word propobjHandlePickupByAibot+0x314
glabel var7f1b341cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3420nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3424nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3428nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b342cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3430nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3434nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3438nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b343cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3440nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3444nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3448nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b344cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3450nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3454nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3458nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b345cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3460nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3464nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3468nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b346cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3470nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3474nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3478nb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b347cnb
.word propobjHandlePickupByAibot+0x3ac
glabel var7f1b3480nb
.word propobjHandlePickupByAibot+0x3ac
.text
/*  f18a918:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f18a91c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f18a920:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f18a924:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f18a928:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f18a92c:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f18a930:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f18a934:	00a09025 */ 	or	$s2,$a1,$zero
/*  f18a938:	10a00004 */ 	beqz	$a1,.NB0f18a94c
/*  f18a93c:	afaf007c */ 	sw	$t7,0x7c($sp)
/*  f18a940:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f18a944:	17000003 */ 	bnez	$t8,.NB0f18a954
/*  f18a948:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18a94c:
/*  f18a94c:	100000de */ 	beqz	$zero,.NB0f18acc8
/*  f18a950:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18a954:
/*  f18a954:	0fc466bd */ 	jal	dprint
/*  f18a958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a95c:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f18a960:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18a964:	8c590010 */ 	lw	$t9,0x10($v0)
/*  f18a968:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f18a96c:	03214024 */ 	and	$t0,$t9,$at
/*  f18a970:	252afffd */ 	addiu	$t2,$t1,-3
/*  f18a974:	2d41002d */ 	sltiu	$at,$t2,0x2d
/*  f18a978:	102000d2 */ 	beqz	$at,.NB0f18acc4
/*  f18a97c:	ac480010 */ 	sw	$t0,0x10($v0)
/*  f18a980:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18a984:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18a988:	002a0821 */ 	addu	$at,$at,$t2
/*  f18a98c:	8c2a33d0 */ 	lw	$t2,0x33d0($at)
/*  f18a990:	01400008 */ 	jr	$t2
/*  f18a994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a998:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f18a99c:	8d710004 */ 	lw	$s1,0x4($t3)
/*  f18a9a0:	0fc21a7e */ 	jal	ammocrateGetPickupAmmoQty
/*  f18a9a4:	02202025 */ 	or	$a0,$s1,$zero
/*  f18a9a8:	0fc466bd */ 	jal	dprint
/*  f18a9ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f18a9b0:	12000004 */ 	beqz	$s0,.NB0f18a9c4
/*  f18a9b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f18a9b8:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
/*  f18a9bc:	0fc64fb5 */ 	jal	aibotGiveAmmoByType
/*  f18a9c0:	8e25005c */ 	lw	$a1,0x5c($s1)
.NB0f18a9c4:
/*  f18a9c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18a9c8:	44810000 */ 	mtc1	$at,$f0
/*  f18a9cc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f18a9d0:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f18a9d4:	240effff */ 	addiu	$t6,$zero,-1
/*  f18a9d8:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f18a9dc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f18a9e0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f18a9e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a9e8:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18a9ec:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f18a9f0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18a9f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18a9f8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18a9fc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18aa00:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18aa04:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18aa08:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18aa0c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18aa10:	0fc24762 */ 	jal	func0f0939f8
/*  f18aa14:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18aa18:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aa1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18aa20:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18aa24:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f18aa28:	0fc1a7e4 */ 	jal	objRemove2
/*  f18aa2c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f18aa30:	12000003 */ 	beqz	$s0,.NB0f18aa40
/*  f18aa34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa38:	0fc466bd */ 	jal	dprint
/*  f18aa3c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18aa40:
/*  f18aa40:	100000a1 */ 	beqz	$zero,.NB0f18acc8
/*  f18aa44:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f18aa48:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f18aa4c:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f18aa50:	0fc466bd */ 	jal	dprint
/*  f18aa54:	afb90070 */ 	sw	$t9,0x70($sp)
/*  f18aa58:	00008025 */ 	or	$s0,$zero,$zero
/*  f18aa5c:	8fb10070 */ 	lw	$s1,0x70($sp)
.NB0f18aa60:
/*  f18aa60:	9626005e */ 	lhu	$a2,0x5e($s1)
/*  f18aa64:	10c00004 */ 	beqz	$a2,.NB0f18aa78
/*  f18aa68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa6c:	0fc466bd */ 	jal	dprint
/*  f18aa70:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f18aa74:	8fa60068 */ 	lw	$a2,0x68($sp)
.NB0f18aa78:
/*  f18aa78:	10c00003 */ 	beqz	$a2,.NB0f18aa88
/*  f18aa7c:	26050001 */ 	addiu	$a1,$s0,0x1
/*  f18aa80:	0fc64fb5 */ 	jal	aibotGiveAmmoByType
/*  f18aa84:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
.NB0f18aa88:
/*  f18aa88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18aa8c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18aa90:	1601fff3 */ 	bne	$s0,$at,.NB0f18aa60
/*  f18aa94:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f18aa98:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18aa9c:	44810000 */ 	mtc1	$at,$f0
/*  f18aaa0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f18aaa4:	24090400 */ 	addiu	$t1,$zero,0x400
/*  f18aaa8:	240affff */ 	addiu	$t2,$zero,-1
/*  f18aaac:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f18aab0:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f18aab4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f18aab8:	00002025 */ 	or	$a0,$zero,$zero
/*  f18aabc:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18aac0:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f18aac4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18aac8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18aacc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18aad0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18aad4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18aad8:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18aadc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18aae0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18aae4:	0fc24762 */ 	jal	func0f0939f8
/*  f18aae8:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18aaec:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aaf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f18aaf4:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18aaf8:	30cc0004 */ 	andi	$t4,$a2,0x4
/*  f18aafc:	0fc1a7e4 */ 	jal	objRemove2
/*  f18ab00:	01803025 */ 	or	$a2,$t4,$zero
/*  f18ab04:	10000070 */ 	beqz	$zero,.NB0f18acc8
/*  f18ab08:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f18ab0c:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f18ab10:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab14:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f18ab18:	0fc64788 */ 	jal	aibotGetInvItemType
/*  f18ab1c:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab20:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f18ab24:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab28:	24010056 */ 	addiu	$at,$zero,0x56
/*  f18ab2c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab30:	54a10006 */ 	bnel	$a1,$at,.NB0f18ab4c
/*  f18ab34:	24010036 */ 	addiu	$at,$zero,0x36
/*  f18ab38:	0fc60340 */ 	jal	chrGiveBriefcase
/*  f18ab3c:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ab40:	10000062 */ 	beqz	$zero,.NB0f18accc
/*  f18ab44:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f18ab48:	24010036 */ 	addiu	$at,$zero,0x36
.NB0f18ab4c:
/*  f18ab4c:	14a10005 */ 	bne	$a1,$at,.NB0f18ab64
/*  f18ab50:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab54:	0fc60612 */ 	jal	chrGiveUplink
/*  f18ab58:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ab5c:	1000005b */ 	beqz	$zero,.NB0f18accc
/*  f18ab60:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f18ab64:
/*  f18ab64:	0fc2191a */ 	jal	propPlayPickupSound
/*  f18ab68:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f18ab6c:	0fc21aac */ 	jal	weaponGetPickupAmmoQty
/*  f18ab70:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ab74:	10400005 */ 	beqz	$v0,.NB0f18ab8c
/*  f18ab78:	00403825 */ 	or	$a3,$v0,$zero
/*  f18ab7c:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
/*  f18ab80:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab84:	0fc64f87 */ 	jal	aibotGiveAmmoByWeapon
/*  f18ab88:	9206005f */ 	lbu	$a2,0x5f($s0)
.NB0f18ab8c:
/*  f18ab8c:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f18ab90:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab94:	11c0001a */ 	beqz	$t6,.NB0f18ac00
/*  f18ab98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab9c:	0fc2bb4c */ 	jal	weaponFindById
/*  f18aba0:	9204005c */ 	lbu	$a0,0x5c($s0)
/*  f18aba4:	00408825 */ 	or	$s1,$v0,$zero
/*  f18aba8:	02402025 */ 	or	$a0,$s2,$zero
/*  f18abac:	0fc647c4 */ 	jal	aibotGetWeaponPad
/*  f18abb0:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18abb4:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f18abb8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f18abbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18abc0:	1701000d */ 	bne	$t8,$at,.NB0f18abf8
/*  f18abc4:	85e30006 */ 	lh	$v1,0x6($t7)
/*  f18abc8:	1220000b */ 	beqz	$s1,.NB0f18abf8
/*  f18abcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abd0:	8e39004c */ 	lw	$t9,0x4c($s1)
/*  f18abd4:	33281000 */ 	andi	$t0,$t9,0x1000
/*  f18abd8:	11000007 */ 	beqz	$t0,.NB0f18abf8
/*  f18abdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abe0:	10430005 */ 	beq	$v0,$v1,.NB0f18abf8
/*  f18abe4:	02402025 */ 	or	$a0,$s2,$zero
/*  f18abe8:	0fc647b9 */ 	jal	aibotGiveDualWeapon
/*  f18abec:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18abf0:	10000006 */ 	beqz	$zero,.NB0f18ac0c
/*  f18abf4:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18abf8:
/*  f18abf8:	10000004 */ 	beqz	$zero,.NB0f18ac0c
/*  f18abfc:	24100002 */ 	addiu	$s0,$zero,0x2
.NB0f18ac00:
/*  f18ac00:	0fc647d3 */ 	jal	aibotGiveProp
/*  f18ac04:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ac08:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18ac0c:
/*  f18ac0c:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18ac10:	00002825 */ 	or	$a1,$zero,$zero
/*  f18ac14:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18ac18:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f18ac1c:	0fc1a7e4 */ 	jal	objRemove2
/*  f18ac20:	01403025 */ 	or	$a2,$t2,$zero
/*  f18ac24:	10000028 */ 	beqz	$zero,.NB0f18acc8
/*  f18ac28:	02001025 */ 	or	$v0,$s0,$zero
/*  f18ac2c:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ac30:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18ac34:	44810000 */ 	mtc1	$at,$f0
/*  f18ac38:	8cb00004 */ 	lw	$s0,0x4($a1)
/*  f18ac3c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f18ac40:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f18ac44:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18ac48:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f18ac4c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f18ac50:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f18ac54:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18ac58:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18ac5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18ac60:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18ac64:	00002025 */ 	or	$a0,$zero,$zero
/*  f18ac68:	240601cd */ 	addiu	$a2,$zero,0x1cd
/*  f18ac6c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18ac70:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18ac74:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18ac78:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18ac7c:	0fc24762 */ 	jal	func0f0939f8
/*  f18ac80:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18ac84:	3c014100 */ 	lui	$at,0x4100
/*  f18ac88:	44813000 */ 	mtc1	$at,$f6
/*  f18ac8c:	c6040060 */ 	lwc1	$f4,0x60($s0)
/*  f18ac90:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ac94:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f18ac98:	44054000 */ 	mfc1	$a1,$f8
/*  f18ac9c:	0fc0ce2c */ 	jal	chrSetShield
/*  f18aca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aca4:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aca8:	00002825 */ 	or	$a1,$zero,$zero
/*  f18acac:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18acb0:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f18acb4:	0fc1a7e4 */ 	jal	objRemove2
/*  f18acb8:	01c03025 */ 	or	$a2,$t6,$zero
/*  f18acbc:	10000002 */ 	beqz	$zero,.NB0f18acc8
/*  f18acc0:	24020003 */ 	addiu	$v0,$zero,0x3
.NB0f18acc4:
/*  f18acc4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18acc8:
/*  f18acc8:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f18accc:
/*  f18accc:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f18acd0:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f18acd4:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f18acd8:	03e00008 */ 	jr	$ra
/*  f18acdc:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f190be4
.late_rodata
glabel var7f1b8ea4
.word 0x47742400
glabel var7f1b8ea8
.word 0x461c4000
.text
/*  f190be4:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f190be8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f190bec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f190bf0:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f190bf4:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f190bf8:	10a0000d */ 	beqz	$a1,.L0f190c30
/*  f190bfc:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f190c00:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f190c04:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x31c)
/*  f190c08:	13000009 */ 	beqz	$t8,.L0f190c30
/*  f190c0c:	00000000 */ 	nop
/*  f190c10:	8f39a2dc */ 	lw	$t9,%lo(g_Vars+0x31c)($t9)
/*  f190c14:	00a02025 */ 	or	$a0,$a1,$zero
/*  f190c18:	13200005 */ 	beqz	$t9,.L0f190c30
/*  f190c1c:	00000000 */ 	nop
/*  f190c20:	0fc0e6a5 */ 	jal	chrIsDead
/*  f190c24:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f190c28:	10400003 */ 	beqz	$v0,.L0f190c38
/*  f190c2c:	00000000 */ 	nop
.L0f190c30:
/*  f190c30:	10000153 */ 	b	.L0f191180
/*  f190c34:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c38:
/*  f190c38:	0fc47bba */ 	jal	dprint
/*  f190c3c:	00000000 */ 	nop
/*  f190c40:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f190c44:	85090002 */ 	lh	$t1,0x2($t0)
/*  f190c48:	11200003 */ 	beqz	$t1,.L0f190c58
/*  f190c4c:	00000000 */ 	nop
/*  f190c50:	1000014b */ 	b	.L0f191180
/*  f190c54:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c58:
/*  f190c58:	0fc21465 */ 	jal	func0f085194
/*  f190c5c:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190c60:	5040000d */ 	beqzl	$v0,.L0f190c98
/*  f190c64:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c68:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c6c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f190c70:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f190c74:	51410008 */ 	beql	$t2,$at,.L0f190c98
/*  f190c78:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c7c:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f190c80:	000b62c0 */ 	sll	$t4,$t3,0xb
/*  f190c84:	0581000a */ 	bgez	$t4,.L0f190cb0
/*  f190c88:	00000000 */ 	nop
/*  f190c8c:	1000013c */ 	b	.L0f191180
/*  f190c90:	00001025 */ 	or	$v0,$zero,$zero
/*  f190c94:	8fa20084 */ 	lw	$v0,0x84($sp)
.L0f190c98:
/*  f190c98:	8c4d0008 */ 	lw	$t5,0x8($v0)
/*  f190c9c:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f190ca0:	05c00003 */ 	bltz	$t6,.L0f190cb0
/*  f190ca4:	00000000 */ 	nop
/*  f190ca8:	10000135 */ 	b	.L0f191180
/*  f190cac:	00001025 */ 	or	$v0,$zero,$zero
.L0f190cb0:
/*  f190cb0:	0fc47bba */ 	jal	dprint
/*  f190cb4:	00000000 */ 	nop
/*  f190cb8:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190cbc:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f190cc0:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f190cc4:	17000005 */ 	bnez	$t8,.L0f190cdc
/*  f190cc8:	00000000 */ 	nop
/*  f190ccc:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f190cd0:	00194300 */ 	sll	$t0,$t9,0xc
/*  f190cd4:	05010003 */ 	bgez	$t0,.L0f190ce4
/*  f190cd8:	00000000 */ 	nop
.L0f190cdc:
/*  f190cdc:	10000128 */ 	b	.L0f191180
/*  f190ce0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ce4:
/*  f190ce4:	0fc47bba */ 	jal	dprint
/*  f190ce8:	00000000 */ 	nop
/*  f190cec:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f190cf0:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f190cf4:	312a0080 */ 	andi	$t2,$t1,0x80
/*  f190cf8:	1140000c */ 	beqz	$t2,.L0f190d2c
/*  f190cfc:	00000000 */ 	nop
/*  f190d00:	8c620048 */ 	lw	$v0,0x48($v1)
/*  f190d04:	10400009 */ 	beqz	$v0,.L0f190d2c
/*  f190d08:	00000000 */ 	nop
/*  f190d0c:	8c4b00b4 */ 	lw	$t3,0xb4($v0)
/*  f190d10:	19600006 */ 	blez	$t3,.L0f190d2c
/*  f190d14:	00000000 */ 	nop
/*  f190d18:	8c4c0090 */ 	lw	$t4,0x90($v0)
/*  f190d1c:	15800003 */ 	bnez	$t4,.L0f190d2c
/*  f190d20:	00000000 */ 	nop
/*  f190d24:	10000116 */ 	b	.L0f191180
/*  f190d28:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d2c:
/*  f190d2c:	0fc47bba */ 	jal	dprint
/*  f190d30:	00000000 */ 	nop
/*  f190d34:	0fc19990 */ 	jal	objPassesSafePickupChecks
/*  f190d38:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190d3c:	14400003 */ 	bnez	$v0,.L0f190d4c
/*  f190d40:	00000000 */ 	nop
/*  f190d44:	1000010e */ 	b	.L0f191180
/*  f190d48:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d4c:
/*  f190d4c:	0fc47bba */ 	jal	dprint
/*  f190d50:	00000000 */ 	nop
/*  f190d54:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f190d58:	24010008 */ 	addiu	$at,$zero,0x8
/*  f190d5c:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f190d60:	91a20003 */ 	lbu	$v0,0x3($t5)
/*  f190d64:	5441003c */ 	bnel	$v0,$at,.L0f190e58
/*  f190d68:	24010007 */ 	addiu	$at,$zero,0x7
/*  f190d6c:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f190d70:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190d74:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f190d78:	0fc65f90 */ 	jal	aibotGetInvItemType
/*  f190d7c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f190d80:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f190d84:	91e4005c */ 	lbu	$a0,0x5c($t7)
/*  f190d88:	0fc2c3f4 */ 	jal	weaponFindById
/*  f190d8c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f190d90:	0002282b */ 	sltu	$a1,$zero,$v0
/*  f190d94:	10a00004 */ 	beqz	$a1,.L0f190da8
/*  f190d98:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f190d9c:	8c45004c */ 	lw	$a1,0x4c($v0)
/*  f190da0:	30b81000 */ 	andi	$t8,$a1,0x1000
/*  f190da4:	2f050001 */ 	sltiu	$a1,$t8,0x1
.L0f190da8:
/*  f190da8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dac:	24010057 */ 	addiu	$at,$zero,0x57
/*  f190db0:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190db4:	1201009b */ 	beq	$s0,$at,.L0f191024
/*  f190db8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f190dbc:	10c10006 */ 	beq	$a2,$at,.L0f190dd8
/*  f190dc0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190dc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190dc8:	54c10015 */ 	bnel	$a2,$at,.L0f190e20
/*  f190dcc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dd0:	50a00013 */ 	beqzl	$a1,.L0f190e20
/*  f190dd4:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190dd8:
/*  f190dd8:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190ddc:	02002825 */ 	or	$a1,$s0,$zero
/*  f190de0:	9046005f */ 	lbu	$a2,0x5f($v0)
/*  f190de4:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f190de8:	00003825 */ 	or	$a3,$zero,$zero
/*  f190dec:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f190df0:	00408025 */ 	or	$s0,$v0,$zero
/*  f190df4:	9124005c */ 	lbu	$a0,0x5c($t1)
/*  f190df8:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f190dfc:	9125005f */ 	lbu	$a1,0x5f($t1)
/*  f190e00:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f190e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f190e08:	0202082a */ 	slt	$at,$s0,$v0
/*  f190e0c:	54200004 */ 	bnezl	$at,.L0f190e20
/*  f190e10:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190e14:	100000da */ 	b	.L0f191180
/*  f190e18:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e1c:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190e20:
/*  f190e20:	24010053 */ 	addiu	$at,$zero,0x53
/*  f190e24:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f190e28:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190e2c:	12010003 */ 	beq	$s0,$at,.L0f190e3c
/*  f190e30:	24010054 */ 	addiu	$at,$zero,0x54
/*  f190e34:	5601007c */ 	bnel	$s0,$at,.L0f191028
/*  f190e38:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f190e3c:
/*  f190e3c:	8d4b0040 */ 	lw	$t3,0x40($t2)
/*  f190e40:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f190e44:	51800078 */ 	beqzl	$t4,.L0f191028
/*  f190e48:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e4c:	100000cc */ 	b	.L0f191180
/*  f190e50:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e54:	24010007 */ 	addiu	$at,$zero,0x7
.L0f190e58:
/*  f190e58:	14410010 */ 	bne	$v0,$at,.L0f190e9c
/*  f190e5c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f190e60:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f190e64:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f190e68:	00003025 */ 	or	$a2,$zero,$zero
/*  f190e6c:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f190e70:	0fc6672e */ 	jal	aibotGetAmmoQuantityByType
/*  f190e74:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f190e78:	8e04005c */ 	lw	$a0,0x5c($s0)
/*  f190e7c:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f190e80:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190e84:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190e88:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190e8c:	54200066 */ 	bnezl	$at,.L0f191028
/*  f190e90:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e94:	100000ba */ 	b	.L0f191180
/*  f190e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f190e9c:
/*  f190e9c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f190ea0:	1441003d */ 	bne	$v0,$at,.L0f190f98
/*  f190ea4:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f190ea8:	8df00004 */ 	lw	$s0,0x4($t7)
/*  f190eac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f190eb0:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f190eb4:	0fc1a1ee */ 	jal	func0f0687b8
/*  f190eb8:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190ebc:	10400005 */ 	beqz	$v0,.L0f190ed4
/*  f190ec0:	02001825 */ 	or	$v1,$s0,$zero
/*  f190ec4:	0fc47bba */ 	jal	dprint
/*  f190ec8:	00000000 */ 	nop
/*  f190ecc:	100000ac */ 	b	.L0f191180
/*  f190ed0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed4:
/*  f190ed4:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed8:
/*  f190ed8:	24500001 */ 	addiu	$s0,$v0,0x1
/*  f190edc:	02002025 */ 	or	$a0,$s0,$zero
/*  f190ee0:	0fc668c7 */ 	jal	ammotypeGetWeapon
/*  f190ee4:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190ee8:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190eec:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f190ef0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190ef4:	9479005e */ 	lhu	$t9,0x5e($v1)
/*  f190ef8:	02002825 */ 	or	$a1,$s0,$zero
/*  f190efc:	00003025 */ 	or	$a2,$zero,$zero
/*  f190f00:	5b20001d */ 	blezl	$t9,.L0f190f78
/*  f190f04:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f08:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190f0c:	0fc6672e */ 	jal	aibotGetAmmoQuantityByType
/*  f190f10:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190f14:	02002025 */ 	or	$a0,$s0,$zero
/*  f190f18:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f190f1c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190f20:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190f24:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190f28:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190f2c:	50200012 */ 	beqzl	$at,.L0f190f78
/*  f190f30:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f34:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f190f38:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f190f3c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f40:	51200011 */ 	beqzl	$t1,.L0f190f88
/*  f190f44:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f48:	0fc65f90 */ 	jal	aibotGetInvItemType
/*  f190f4c:	01202825 */ 	or	$a1,$t1,$zero
/*  f190f50:	5440000d */ 	bnezl	$v0,.L0f190f88
/*  f190f54:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f58:	0fc47bba */ 	jal	dprint
/*  f190f5c:	00000000 */ 	nop
/*  f190f60:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f64:	0fc65fdb */ 	jal	aibotGiveProp
/*  f190f68:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f190f6c:	10000006 */ 	b	.L0f190f88
/*  f190f70:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f74:	24010013 */ 	addiu	$at,$zero,0x13
.L0f190f78:
/*  f190f78:	02001025 */ 	or	$v0,$s0,$zero
/*  f190f7c:	1601ffd6 */ 	bne	$s0,$at,.L0f190ed8
/*  f190f80:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190f84:	8faa0064 */ 	lw	$t2,0x64($sp)
.L0f190f88:
/*  f190f88:	51400027 */ 	beqzl	$t2,.L0f191028
/*  f190f8c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190f90:	1000007b */ 	b	.L0f191180
/*  f190f94:	00001025 */ 	or	$v0,$zero,$zero
.L0f190f98:
/*  f190f98:	24010015 */ 	addiu	$at,$zero,0x15
/*  f190f9c:	14410021 */ 	bne	$v0,$at,.L0f191024
/*  f190fa0:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f190fa4:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f190fa8:	00008025 */ 	or	$s0,$zero,$zero
/*  f190fac:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190fb0:	0fc0cfe8 */ 	jal	chrGetShield
/*  f190fb4:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f190fb8:	3c013e00 */ 	lui	$at,0x3e00
/*  f190fbc:	44812000 */ 	mtc1	$at,$f4
/*  f190fc0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f190fc4:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x10)
/*  f190fc8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f190fcc:	c5a80060 */ 	lwc1	$f8,0x60($t5)
/*  f190fd0:	4606403e */ 	c.le.s	$f8,$f6
/*  f190fd4:	00000000 */ 	nop
/*  f190fd8:	45000003 */ 	bc1f	.L0f190fe8
/*  f190fdc:	00000000 */ 	nop
/*  f190fe0:	1000000c */ 	b	.L0f191014
/*  f190fe4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f190fe8:
/*  f190fe8:	91cecb98 */ 	lbu	$t6,%lo(g_MpSetup+0x10)($t6)
/*  f190fec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190ff0:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f190ff4:	15c10007 */ 	bne	$t6,$at,.L0f191014
/*  f190ff8:	00000000 */ 	nop
/*  f190ffc:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f191000:	8f19009c */ 	lw	$t9,0x9c($t8)
/*  f191004:	001947c2 */ 	srl	$t0,$t9,0x1f
/*  f191008:	11000002 */ 	beqz	$t0,.L0f191014
/*  f19100c:	00000000 */ 	nop
/*  f191010:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f191014:
/*  f191014:	52000004 */ 	beqzl	$s0,.L0f191028
/*  f191018:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f19101c:	10000058 */ 	b	.L0f191180
/*  f191020:	00001025 */ 	or	$v0,$zero,$zero
.L0f191024:
/*  f191024:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f191028:
/*  f191028:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f19102c:	8d30001c */ 	lw	$s0,0x1c($t1)
/*  f191030:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f191034:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f191038:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f19103c:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f191040:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f191044:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f191048:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f19104c:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f191050:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f191054:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f191058:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f19105c:	0fc47bba */ 	jal	dprint
/*  f191060:	e7ae0044 */ 	swc1	$f14,0x44($sp)
/*  f191064:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f191068:	8faa008c */ 	lw	$t2,0x8c($sp)
/*  f19106c:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f191070:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f191074:	8d4b02d4 */ 	lw	$t3,0x2d4($t2)
/*  f191078:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f19107c:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f191080:	916c009c */ 	lbu	$t4,0x9c($t3)
/*  f191084:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea4)
/*  f191088:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f19108c:	11a00004 */ 	beqz	$t5,.L0f1910a0
/*  f191090:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f191094:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea8)
/*  f191098:	10000002 */ 	b	.L0f1910a4
/*  f19109c:	c4208ea4 */ 	lwc1	$f0,%lo(var7f1b8ea4)($at)
.L0f1910a0:
/*  f1910a0:	c4208ea8 */ 	lwc1	$f0,%lo(var7f1b8ea8)($at)
.L0f1910a4:
/*  f1910a4:	4600903e */ 	c.le.s	$f18,$f0
/*  f1910a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910ac:	3c01c348 */ 	lui	$at,0xc348
/*  f1910b0:	45000002 */ 	bc1f	.L0f1910bc
/*  f1910b4:	00000000 */ 	nop
/*  f1910b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910bc:
/*  f1910bc:	10400012 */ 	beqz	$v0,.L0f191108
/*  f1910c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910c4:	44812000 */ 	mtc1	$at,$f4
/*  f1910c8:	3c014348 */ 	lui	$at,0x4348
/*  f1910cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910d0:	460c203e */ 	c.le.s	$f4,$f12
/*  f1910d4:	00000000 */ 	nop
/*  f1910d8:	45000002 */ 	bc1f	.L0f1910e4
/*  f1910dc:	00000000 */ 	nop
/*  f1910e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910e4:
/*  f1910e4:	10400008 */ 	beqz	$v0,.L0f191108
/*  f1910e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910ec:	44813000 */ 	mtc1	$at,$f6
/*  f1910f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1910f4:	4606603e */ 	c.le.s	$f12,$f6
/*  f1910f8:	00000000 */ 	nop
/*  f1910fc:	45000002 */ 	bc1f	.L0f191108
/*  f191100:	00000000 */ 	nop
/*  f191104:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f191108:
/*  f191108:	10a00014 */ 	beqz	$a1,.L0f19115c
/*  f19110c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f191110:	0fc47bba */ 	jal	dprint
/*  f191114:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f191118:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f19111c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f191120:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191124:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f191128:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f19112c:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f191130:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f191134:	17000009 */ 	bnez	$t8,.L0f19115c
/*  f191138:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f19113c:	24190022 */ 	addiu	$t9,$zero,0x22
/*  f191140:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f191144:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f191148:	0c00b734 */ 	jal	func0002dcd0
/*  f19114c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f191150:	14400002 */ 	bnez	$v0,.L0f19115c
/*  f191154:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191158:	00001825 */ 	or	$v1,$zero,$zero
.L0f19115c:
/*  f19115c:	10600008 */ 	beqz	$v1,.L0f191180
/*  f191160:	00001025 */ 	or	$v0,$zero,$zero
/*  f191164:	0fc47bba */ 	jal	dprint
/*  f191168:	00000000 */ 	nop
/*  f19116c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f191170:	0fc641e1 */ 	jal	propobjHandlePickupByAibot
/*  f191174:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f191178:	10000002 */ 	b	.L0f191184
/*  f19117c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191180:
/*  f191180:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191184:
/*  f191184:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f191188:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f19118c:	03e00008 */ 	jr	$ra
/*  f191190:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f190be4
.late_rodata
glabel var7f1b8ea4
.word 0x47742400
glabel var7f1b8ea8
.word 0x461c4000
.text
/*  f18ace0:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f18ace4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18ace8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18acec:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f18acf0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f18acf4:	10a0000d */ 	beqz	$a1,.NB0f18ad2c
/*  f18acf8:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f18acfc:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f18ad00:	3c19800a */ 	lui	$t9,0x800a
/*  f18ad04:	13000009 */ 	beqz	$t8,.NB0f18ad2c
/*  f18ad08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad0c:	8f39e9dc */ 	lw	$t9,-0x1624($t9)
/*  f18ad10:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18ad14:	13200005 */ 	beqz	$t9,.NB0f18ad2c
/*  f18ad18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad1c:	0fc0e4ec */ 	jal	chrIsDead
/*  f18ad20:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f18ad24:	10400003 */ 	beqz	$v0,.NB0f18ad34
/*  f18ad28:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18ad2c:
/*  f18ad2c:	1000014f */ 	beqz	$zero,.NB0f18b26c
/*  f18ad30:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ad34:
/*  f18ad34:	0fc466bd */ 	jal	dprint
/*  f18ad38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad3c:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f18ad40:	85090002 */ 	lh	$t1,0x2($t0)
/*  f18ad44:	11200003 */ 	beqz	$t1,.NB0f18ad54
/*  f18ad48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad4c:	10000147 */ 	beqz	$zero,.NB0f18b26c
/*  f18ad50:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ad54:
/*  f18ad54:	0fc20e86 */ 	jal	func0f085194
/*  f18ad58:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18ad5c:	5040000d */ 	beqzl	$v0,.NB0f18ad94
/*  f18ad60:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad64:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad68:	24010011 */ 	addiu	$at,$zero,0x11
/*  f18ad6c:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f18ad70:	51410008 */ 	beql	$t2,$at,.NB0f18ad94
/*  f18ad74:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad78:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f18ad7c:	000b62c0 */ 	sll	$t4,$t3,0xb
/*  f18ad80:	0581000a */ 	bgez	$t4,.NB0f18adac
/*  f18ad84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad88:	10000138 */ 	beqz	$zero,.NB0f18b26c
/*  f18ad8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18ad90:	8fa20084 */ 	lw	$v0,0x84($sp)
.NB0f18ad94:
/*  f18ad94:	8c4d0008 */ 	lw	$t5,0x8($v0)
/*  f18ad98:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f18ad9c:	05c00003 */ 	bltz	$t6,.NB0f18adac
/*  f18ada0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ada4:	10000131 */ 	beqz	$zero,.NB0f18b26c
/*  f18ada8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18adac:
/*  f18adac:	0fc466bd */ 	jal	dprint
/*  f18adb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adb4:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f18adb8:	8df80008 */ 	lw	$t8,0x8($t7)
/*  f18adbc:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f18adc0:	07210003 */ 	bgez	$t9,.NB0f18add0
/*  f18adc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adc8:	10000128 */ 	beqz	$zero,.NB0f18b26c
/*  f18adcc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18add0:
/*  f18add0:	0fc466bd */ 	jal	dprint
/*  f18add4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18add8:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f18addc:	8c680040 */ 	lw	$t0,0x40($v1)
/*  f18ade0:	31090080 */ 	andi	$t1,$t0,0x80
/*  f18ade4:	1120000c */ 	beqz	$t1,.NB0f18ae18
/*  f18ade8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adec:	8c620048 */ 	lw	$v0,0x48($v1)
/*  f18adf0:	10400009 */ 	beqz	$v0,.NB0f18ae18
/*  f18adf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adf8:	8c4a00b4 */ 	lw	$t2,0xb4($v0)
/*  f18adfc:	19400006 */ 	blez	$t2,.NB0f18ae18
/*  f18ae00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae04:	8c4b0090 */ 	lw	$t3,0x90($v0)
/*  f18ae08:	15600003 */ 	bnez	$t3,.NB0f18ae18
/*  f18ae0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae10:	10000116 */ 	beqz	$zero,.NB0f18b26c
/*  f18ae14:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ae18:
/*  f18ae18:	0fc466bd */ 	jal	dprint
/*  f18ae1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae20:	0fc19630 */ 	jal	objPassesSafePickupChecks
/*  f18ae24:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18ae28:	14400003 */ 	bnez	$v0,.NB0f18ae38
/*  f18ae2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae30:	1000010e */ 	beqz	$zero,.NB0f18b26c
/*  f18ae34:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ae38:
/*  f18ae38:	0fc466bd */ 	jal	dprint
/*  f18ae3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae40:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f18ae44:	24010008 */ 	addiu	$at,$zero,0x8
/*  f18ae48:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f18ae4c:	91820003 */ 	lbu	$v0,0x3($t4)
/*  f18ae50:	5441003c */ 	bnel	$v0,$at,.NB0f18af44
/*  f18ae54:	24010007 */ 	addiu	$at,$zero,0x7
/*  f18ae58:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f18ae5c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18ae60:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f18ae64:	0fc64788 */ 	jal	aibotGetInvItemType
/*  f18ae68:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f18ae6c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f18ae70:	91c4005c */ 	lbu	$a0,0x5c($t6)
/*  f18ae74:	0fc2bb4c */ 	jal	weaponFindById
/*  f18ae78:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f18ae7c:	0002282b */ 	sltu	$a1,$zero,$v0
/*  f18ae80:	10a00004 */ 	beqz	$a1,.NB0f18ae94
/*  f18ae84:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f18ae88:	8c45004c */ 	lw	$a1,0x4c($v0)
/*  f18ae8c:	30af1000 */ 	andi	$t7,$a1,0x1000
/*  f18ae90:	2de50001 */ 	sltiu	$a1,$t7,0x1
.NB0f18ae94:
/*  f18ae94:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18ae98:	24010056 */ 	addiu	$at,$zero,0x56
/*  f18ae9c:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f18aea0:	1201009b */ 	beq	$s0,$at,.NB0f18b110
/*  f18aea4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f18aea8:	10c10006 */ 	beq	$a2,$at,.NB0f18aec4
/*  f18aeac:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f18aeb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18aeb4:	54c10015 */ 	bnel	$a2,$at,.NB0f18af0c
/*  f18aeb8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18aebc:	50a00013 */ 	beqzl	$a1,.NB0f18af0c
/*  f18aec0:	8fa20080 */ 	lw	$v0,0x80($sp)
.NB0f18aec4:
/*  f18aec4:	8f2402d4 */ 	lw	$a0,0x2d4($t9)
/*  f18aec8:	02002825 */ 	or	$a1,$s0,$zero
/*  f18aecc:	9046005f */ 	lbu	$a2,0x5f($v0)
/*  f18aed0:	0fc64ef1 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f18aed4:	00003825 */ 	or	$a3,$zero,$zero
/*  f18aed8:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f18aedc:	00408025 */ 	or	$s0,$v0,$zero
/*  f18aee0:	9104005c */ 	lbu	$a0,0x5c($t0)
/*  f18aee4:	0fc64e64 */ 	jal	weaponGetAmmoTypeByFunction
/*  f18aee8:	9105005f */ 	lbu	$a1,0x5f($t0)
/*  f18aeec:	0fc29da5 */ 	jal	ammotypeGetMaxCapacity
/*  f18aef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18aef4:	0202082a */ 	slt	$at,$s0,$v0
/*  f18aef8:	54200004 */ 	bnezl	$at,.NB0f18af0c
/*  f18aefc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18af00:	100000da */ 	beqz	$zero,.NB0f18b26c
/*  f18af04:	00001025 */ 	or	$v0,$zero,$zero
/*  f18af08:	8fa20080 */ 	lw	$v0,0x80($sp)
.NB0f18af0c:
/*  f18af0c:	24010052 */ 	addiu	$at,$zero,0x52
/*  f18af10:	8fa90084 */ 	lw	$t1,0x84($sp)
/*  f18af14:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f18af18:	12010003 */ 	beq	$s0,$at,.NB0f18af28
/*  f18af1c:	24010053 */ 	addiu	$at,$zero,0x53
/*  f18af20:	5601007c */ 	bnel	$s0,$at,.NB0f18b114
/*  f18af24:	8fa8008c */ 	lw	$t0,0x8c($sp)
.NB0f18af28:
/*  f18af28:	8d2a0040 */ 	lw	$t2,0x40($t1)
/*  f18af2c:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f18af30:	51600078 */ 	beqzl	$t3,.NB0f18b114
/*  f18af34:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18af38:	100000cc */ 	beqz	$zero,.NB0f18b26c
/*  f18af3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18af40:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f18af44:
/*  f18af44:	14410010 */ 	bne	$v0,$at,.NB0f18af88
/*  f18af48:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f18af4c:	8d900004 */ 	lw	$s0,0x4($t4)
/*  f18af50:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f18af54:	00003025 */ 	or	$a2,$zero,$zero
/*  f18af58:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f18af5c:	0fc64f26 */ 	jal	aibotGetAmmoQuantityByType
/*  f18af60:	8da402d4 */ 	lw	$a0,0x2d4($t5)
/*  f18af64:	8e04005c */ 	lw	$a0,0x5c($s0)
/*  f18af68:	0fc29da5 */ 	jal	ammotypeGetMaxCapacity
/*  f18af6c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f18af70:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f18af74:	00a2082a */ 	slt	$at,$a1,$v0
/*  f18af78:	54200066 */ 	bnezl	$at,.NB0f18b114
/*  f18af7c:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18af80:	100000ba */ 	beqz	$zero,.NB0f18b26c
/*  f18af84:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18af88:
/*  f18af88:	24010014 */ 	addiu	$at,$zero,0x14
/*  f18af8c:	1441003d */ 	bne	$v0,$at,.NB0f18b084
/*  f18af90:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f18af94:	8dd00004 */ 	lw	$s0,0x4($t6)
/*  f18af98:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18af9c:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f18afa0:	0fc19e8e */ 	jal	func0f0687b8
/*  f18afa4:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18afa8:	10400005 */ 	beqz	$v0,.NB0f18afc0
/*  f18afac:	02001825 */ 	or	$v1,$s0,$zero
/*  f18afb0:	0fc466bd */ 	jal	dprint
/*  f18afb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18afb8:	100000ac */ 	beqz	$zero,.NB0f18b26c
/*  f18afbc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18afc0:
/*  f18afc0:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18afc4:
/*  f18afc4:	24500001 */ 	addiu	$s0,$v0,0x1
/*  f18afc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f18afcc:	0fc650bf */ 	jal	ammotypeGetWeapon
/*  f18afd0:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f18afd4:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f18afd8:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f18afdc:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f18afe0:	9478005e */ 	lhu	$t8,0x5e($v1)
/*  f18afe4:	02002825 */ 	or	$a1,$s0,$zero
/*  f18afe8:	00003025 */ 	or	$a2,$zero,$zero
/*  f18afec:	5b00001d */ 	blezl	$t8,.NB0f18b064
/*  f18aff0:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18aff4:	8f2402d4 */ 	lw	$a0,0x2d4($t9)
/*  f18aff8:	0fc64f26 */ 	jal	aibotGetAmmoQuantityByType
/*  f18affc:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f18b000:	02002025 */ 	or	$a0,$s0,$zero
/*  f18b004:	0fc29da5 */ 	jal	ammotypeGetMaxCapacity
/*  f18b008:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f18b00c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f18b010:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f18b014:	00a2082a */ 	slt	$at,$a1,$v0
/*  f18b018:	50200012 */ 	beqzl	$at,.NB0f18b064
/*  f18b01c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18b020:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f18b024:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f18b028:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b02c:	51000011 */ 	beqzl	$t0,.NB0f18b074
/*  f18b030:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b034:	0fc64788 */ 	jal	aibotGetInvItemType
/*  f18b038:	01002825 */ 	or	$a1,$t0,$zero
/*  f18b03c:	5440000d */ 	bnezl	$v0,.NB0f18b074
/*  f18b040:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b044:	0fc466bd */ 	jal	dprint
/*  f18b048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b04c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b050:	0fc647d3 */ 	jal	aibotGiveProp
/*  f18b054:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f18b058:	10000006 */ 	beqz	$zero,.NB0f18b074
/*  f18b05c:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b060:	24010013 */ 	addiu	$at,$zero,0x13
.NB0f18b064:
/*  f18b064:	02001025 */ 	or	$v0,$s0,$zero
/*  f18b068:	1601ffd6 */ 	bne	$s0,$at,.NB0f18afc4
/*  f18b06c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18b070:	8fa90064 */ 	lw	$t1,0x64($sp)
.NB0f18b074:
/*  f18b074:	51200027 */ 	beqzl	$t1,.NB0f18b114
/*  f18b078:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18b07c:	1000007b */ 	beqz	$zero,.NB0f18b26c
/*  f18b080:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18b084:
/*  f18b084:	24010015 */ 	addiu	$at,$zero,0x15
/*  f18b088:	14410021 */ 	bne	$v0,$at,.NB0f18b110
/*  f18b08c:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f18b090:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f18b094:	00008025 */ 	or	$s0,$zero,$zero
/*  f18b098:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b09c:	0fc0ce2a */ 	jal	chrGetShield
/*  f18b0a0:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f18b0a4:	3c013e00 */ 	lui	$at,0x3e00
/*  f18b0a8:	44812000 */ 	mtc1	$at,$f4
/*  f18b0ac:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f18b0b0:	3c0d800b */ 	lui	$t5,0x800b
/*  f18b0b4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f18b0b8:	c5880060 */ 	lwc1	$f8,0x60($t4)
/*  f18b0bc:	4606403e */ 	c.le.s	$f8,$f6
/*  f18b0c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0c4:	45000003 */ 	bc1f	.NB0f18b0d4
/*  f18b0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0cc:	1000000c */ 	beqz	$zero,.NB0f18b100
/*  f18b0d0:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18b0d4:
/*  f18b0d4:	91ad1448 */ 	lbu	$t5,0x1448($t5)
/*  f18b0d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18b0dc:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f18b0e0:	15a10007 */ 	bne	$t5,$at,.NB0f18b100
/*  f18b0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0e8:	8dcf02d4 */ 	lw	$t7,0x2d4($t6)
/*  f18b0ec:	8df8009c */ 	lw	$t8,0x9c($t7)
/*  f18b0f0:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f18b0f4:	13200002 */ 	beqz	$t9,.NB0f18b100
/*  f18b0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0fc:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18b100:
/*  f18b100:	52000004 */ 	beqzl	$s0,.NB0f18b114
/*  f18b104:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18b108:	10000058 */ 	beqz	$zero,.NB0f18b26c
/*  f18b10c:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18b110:
/*  f18b110:	8fa8008c */ 	lw	$t0,0x8c($sp)
.NB0f18b114:
/*  f18b114:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18b118:	8d10001c */ 	lw	$s0,0x1c($t0)
/*  f18b11c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f18b120:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f18b124:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f18b128:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f18b12c:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f18b130:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f18b134:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f18b138:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f18b13c:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f18b140:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f18b144:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18b148:	0fc466bd */ 	jal	dprint
/*  f18b14c:	e7ae0044 */ 	swc1	$f14,0x44($sp)
/*  f18b150:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f18b154:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f18b158:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f18b15c:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f18b160:	8d2a02d4 */ 	lw	$t2,0x2d4($t1)
/*  f18b164:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18b168:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f18b16c:	914b009c */ 	lbu	$t3,0x9c($t2)
/*  f18b170:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18b174:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f18b178:	11800004 */ 	beqz	$t4,.NB0f18b18c
/*  f18b17c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f18b180:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18b184:	10000002 */ 	beqz	$zero,.NB0f18b190
/*  f18b188:	c4203484 */ 	lwc1	$f0,0x3484($at)
.NB0f18b18c:
/*  f18b18c:	c4203488 */ 	lwc1	$f0,0x3488($at)
.NB0f18b190:
/*  f18b190:	4600903e */ 	c.le.s	$f18,$f0
/*  f18b194:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b198:	3c01c348 */ 	lui	$at,0xc348
/*  f18b19c:	45000002 */ 	bc1f	.NB0f18b1a8
/*  f18b1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1a4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18b1a8:
/*  f18b1a8:	10400012 */ 	beqz	$v0,.NB0f18b1f4
/*  f18b1ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f18b1b0:	44812000 */ 	mtc1	$at,$f4
/*  f18b1b4:	3c014348 */ 	lui	$at,0x4348
/*  f18b1b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b1bc:	460c203e */ 	c.le.s	$f4,$f12
/*  f18b1c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1c4:	45000002 */ 	bc1f	.NB0f18b1d0
/*  f18b1c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1cc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18b1d0:
/*  f18b1d0:	10400008 */ 	beqz	$v0,.NB0f18b1f4
/*  f18b1d4:	00402825 */ 	or	$a1,$v0,$zero
/*  f18b1d8:	44813000 */ 	mtc1	$at,$f6
/*  f18b1dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f18b1e0:	4606603e */ 	c.le.s	$f12,$f6
/*  f18b1e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1e8:	45000002 */ 	bc1f	.NB0f18b1f4
/*  f18b1ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1f0:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f18b1f4:
/*  f18b1f4:	10a00014 */ 	beqz	$a1,.NB0f18b248
/*  f18b1f8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f18b1fc:	0fc466bd */ 	jal	dprint
/*  f18b200:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f18b204:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f18b208:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18b20c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f18b210:	8dae000c */ 	lw	$t6,0xc($t5)
/*  f18b214:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f18b218:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f18b21c:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f18b220:	15e00009 */ 	bnez	$t7,.NB0f18b248
/*  f18b224:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f18b228:	24180022 */ 	addiu	$t8,$zero,0x22
/*  f18b22c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18b230:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f18b234:	0c00bc36 */ 	jal	func0002dcd0
/*  f18b238:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f18b23c:	14400002 */ 	bnez	$v0,.NB0f18b248
/*  f18b240:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f18b244:	00001825 */ 	or	$v1,$zero,$zero
.NB0f18b248:
/*  f18b248:	10600008 */ 	beqz	$v1,.NB0f18b26c
/*  f18b24c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b250:	0fc466bd */ 	jal	dprint
/*  f18b254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b258:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18b25c:	0fc62a46 */ 	jal	propobjHandlePickupByAibot
/*  f18b260:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f18b264:	10000002 */ 	beqz	$zero,.NB0f18b270
/*  f18b268:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f18b26c:
/*  f18b26c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f18b270:
/*  f18b270:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f18b274:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f18b278:	03e00008 */ 	jr	$ra
/*  f18b27c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

// Mismatch: Uses too many callee-save registers
//bool func0f190be4(struct prop *prop, struct chrdata *chr)
//{
//	struct defaultobj *obj = prop->obj; // 84
//
//	struct weaponobj *weaponobj; // 80
//	s32 itemtype; // 7c
//	struct weapon *weapon;
//	bool singleonly;
//	s32 cap;
//	s32 qty;
//
//	struct ammocrateobj *crate;
//
//	s32 weaponnum; // 68
//	bool ignore1; // 64
//	struct multiammocrateobj *crate2;
//
//	struct shieldobj *shield; // 58
//	bool ignore2;
//
//	struct prop *chrprop;
//
//	f32 xdist; // 4c
//	f32 ydist; // 48
//	f32 zdist; // 44
//	f32 sqrange;
//	bool sp3c;
//	s32 i;
//	f32 latdist;
//	u32 stack;
//
//	if (!chr || !chr->aibot || !g_Vars.lvmpbotlevel || chrIsDead(chr)) {
//		return false;
//	}
//
//	dprint();
//
//	if (prop->timetoregen != 0) {
//		return false;
//	}
//
//	if (func0f085194(obj) && obj->type != OBJTYPE_HAT) {
//		if (obj->flags & OBJFLAG_UNCOLLECTABLE) {
//			return false;
//		}
//	} else {
//		if ((obj->flags & OBJFLAG_COLLECTABLE) == 0) {
//			return false;
//		}
//	}
//
//	dprint();
//
//	if ((obj->hidden & OBJHFLAG_REAPABLE) || (obj->flags & OBJFLAG_00080000)) {
//		return false;
//	}
//
//	dprint();
//
//	if ((obj->hidden & OBJHFLAG_AIRBORNE)
//			&& obj->projectile
//			&& obj->projectile->unk0b4 > 0
//			&& obj->projectile->unk090 == 0) {
//		return false;
//	}
//
//	dprint();
//
//	if (!objPassesSafePickupChecks(obj)) {
//		return false;
//	}
//
//	dprint();
//
//	// d64
//	if (obj->type == OBJTYPE_WEAPON) {
//		weaponobj = prop->weapon; // 80
//		itemtype = aibotGetInvItemType(chr, weaponobj->weaponnum); // 7c
//		weapon = weaponFindById(weaponobj->weaponnum);
//		singleonly = weapon && (weapon->flags & WEAPONFLAG_DUALWIELD) == 0;
//
//		if (weaponobj->weaponnum != WEAPON_BRIEFCASE2) {
//			// If aibot is dual wielding, or single wielding and weapon doesn't support dual,
//			// ignore the pickup if at max ammo already
//			if (itemtype == INVITEMTYPE_DUAL || (itemtype == INVITEMTYPE_WEAP && singleonly)) {
//				qty = aibotGetAmmoQuantityByWeapon(chr->aibot, weaponobj->weaponnum, weaponobj->gunfunc, false);
//				cap = ammotypeGetMaxCapacity(weaponGetAmmoTypeByFunction(weaponobj->weaponnum, weaponobj->gunfunc));
//
//				if (qty >= cap) {
//					return false;
//				}
//			}
//
//			// Ignore rockets that are in flight
//			if ((weaponobj->weaponnum == WEAPON_ROCKET || weaponobj->weaponnum == WEAPON_HOMINGROCKET)
//					&& (obj->hidden & OBJHFLAG_AIRBORNE)) {
//				return false;
//			}
//		}
//	} else /*e58*/ if (obj->type == OBJTYPE_AMMOCRATE) {
//		crate = (struct ammocrateobj *)prop->obj;
//
//		// Ignore ammo crate if at max ammo already
//		if (aibotGetAmmoQuantityByType(chr->aibot, crate->ammotype, false) >= ammotypeGetMaxCapacity(crate->ammotype)) {
//			return false;
//		}
//	} else /*e9c*/ if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
//		crate2 = (struct multiammocrateobj *)prop->obj;
//		ignore1 = true;
//
//		if (func0f0687b8(obj)) {
//			dprint();
//			return false;
//		}
//
//		for (i = 0; i < 0x13; i++) {
//			weaponnum = ammotypeGetWeapon(i + 1);
//
//			if (crate2->slots[i].quantity > 0) {
//				if (aibotGetAmmoQuantityByType(chr->aibot, i + 1, false) < ammotypeGetMaxCapacity(i + 1)) {
//					ignore1 = false;
//
//					if (weaponnum && !aibotGetInvItemType(chr, weaponnum)) {
//						dprint();
//						aibotGiveProp(chr, prop);
//					}
//
//					break;
//				}
//			}
//		}
//
//		if (ignore1) {
//			return false;
//		}
//	} else /*f9c*/ if (obj->type == OBJTYPE_SHIELD) {
//		shield = (struct shieldobj *)prop->obj; // 58
//		ignore2 = false;
//
//		if (shield->amount <= chrGetShield(chr) * 0.125f) {
//			ignore2 = true;
//		} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE && chr->aibot->unk09c_00) {
//			ignore2 = true;
//		}
//
//		if (ignore2) {
//			return false;
//		}
//	}
//
//	// 024
//	chrprop = chr->prop;
//
//	xdist = prop->pos.x - chrprop->pos.x;
//	ydist = prop->pos.y - chrprop->pos.y;
//	zdist = prop->pos.z - chrprop->pos.z;
//
//	latdist = xdist * xdist + zdist * zdist;
//
//	dprint();
//
//	if (chr->aibot->cheap) {
//		sqrange = 250 * 250;
//	} else {
//		sqrange = 100 * 100;
//	}
//
//	sp3c = latdist <= sqrange && ydist >= -200 && ydist <= 200;
//
//	// 108
//	if (sp3c) {
//		dprint();
//
//		if ((obj->flags2 & OBJFLAG2_00001000) == 0
//				&& !func0002dcd0(&chrprop->pos, chrprop->rooms, &prop->pos, prop->rooms, 0x22)) {
//			sp3c = false;
//		}
//	}
//
//	// 15c
//	if (sp3c) {
//		dprint();
//		return propobjHandlePickupByAibot(prop, chr);
//	}
//
//	return false;
//}

s32 mpObjIsSafe(struct defaultobj *obj)
{
	if (!obj) {
		return false;
	}

	if (obj->type == OBJTYPE_AMMOCRATE
			|| obj->type == OBJTYPE_MULTIAMMOCRATE
			|| obj->type == OBJTYPE_SHIELD) {
		return true;
	}

	if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *)obj;

		if (weapon->weaponnum == WEAPON_NBOMB ||
				weapon->weaponnum == WEAPON_GRENADE ||
				weapon->weaponnum == WEAPON_GRENADEROUND ||
				weapon->weaponnum == WEAPON_PROXIMITYMINE ||
				weapon->weaponnum == WEAPON_REMOTEMINE ||
				weapon->weaponnum == WEAPON_TIMEDMINE ||
				weapon->weaponnum == WEAPON_SKROCKET ||
				(weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)) {
			return false;
		}

		return true;
	}

	return false;
}

void func0f19124c(struct chrdata *chr)
{
	s32 i;
	s16 *propnumptr;
	s16 propnums[260];
	s16 allrooms[22];
	s16 neighbours[12];

	roomsCopy(chr->prop->rooms, allrooms);

	for (i = 0; chr->prop->rooms[i] != -1; i++) {
		roomGetNeighbours(chr->prop->rooms[i], neighbours, 10);
		roomsAppend(neighbours, allrooms, 20);
	}

	roomGetProps(allrooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON) {
			if (prop->timetoregen == 0) {
				struct defaultobj *obj = prop->obj;

#if VERSION >= VERSION_NTSC_1_0
				if (obj)
#endif
				{
					if ((obj->hidden & OBJHFLAG_AIRBORNE) == 0
							|| obj->projectile == NULL
							|| obj->projectile->unk0b4 <= 0
							|| obj->projectile->unk090) {
						if (mpObjIsSafe(obj)) {
							if (func0f190be4(prop, chr)) {
								propExecuteTickOperation(prop, 1);
							} else {
								dprint();
							}
						}
					}
				}
			}
		}

		propnumptr++;
	}
}

s32 chrGuessCrouchPos(struct chrdata *chr)
{
	s32 crouchpos;

	if (chr->chrheight <= 90) {
		crouchpos = CROUCHPOS_SQUAT;
	} else if (chr->chrheight <= 135) {
		crouchpos = CROUCHPOS_DUCK;
	} else {
		crouchpos = CROUCHPOS_STAND;
	}

	return crouchpos;
}

bool func0f191448(struct chrdata *chr)
{
	struct aibot *aibot;
	u32 stack;
	f32 speedforwards;
	f32 speedsideways;
	f32 angle;
	f32 angle2;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	angle = chrGetInverseTheta(chr) - func0f03e578(chr);

	if (angle < 0) {
		angle += M_BADTAU;
	}

	speedforwards = aibot->unk06c * cosf(angle) - sinf(angle) * aibot->unk070;
	speedsideways = aibot->unk06c * sinf(angle) + cosf(angle) * aibot->unk070;

	func0f0c2a58(chr, chrGuessCrouchPos(chr), speedsideways, speedforwards, aibot->speedtheta, &aibot->angleoffset, &aibot->unk068);

	angle2 = chrGetInverseTheta(chr) - aibot->angleoffset;

	if (angle2 < 0) {
		angle2 += M_BADTAU;
	}

	if (angle2 >= M_BADTAU) {
		angle2 -= M_BADTAU;
	}

	func0001ae90(chr->model, angle2);

	return true;
}

s32 mpchrGetWeaponNum(struct chrdata *chr)
{
	if (chr->aibot) {
		return chr->aibot->weaponnum;
	}

	return g_Vars.players[propGetPlayerNum(chr->prop)]->hands[HAND_RIGHT].gset.weaponnum;
}

u8 mpchrGetTargetsWeaponNum(struct chrdata *chr)
{
	struct prop *target = chrGetTargetProp(chr);
	u8 weaponnum = 0;

	if (target) {
		weaponnum = mpchrGetWeaponNum(target->chr);
	}

	return weaponnum;
}

bool func0f191638(struct chrdata *chr, bool arg1)
{
	bool result = false;
	struct prop *target;
	u32 stack;
	s32 mpindex;

	if (chr->target != -1) {
		target = chrGetTargetProp(chr);
		mpindex = mpPlayerGetIndex(target->chr);
		result = false;

		if (chr->aibot->unk16c[mpindex]) {
			result = true;
		}

		if (chr->aibot->simulant->difficulty > SIMDIFF_MEAT) {
			if (chr->aibot->unk178[mpindex] >= g_Vars.lvframe60 - PALDOWN(240)
					|| (arrayIntersects(chr->prop->rooms, target->rooms))) {
				result = true;
			}

			if (chr->aibot->simulant->difficulty >= SIMDIFF_NORMAL) {
				if (roomsAreNeighbours(chr->prop->rooms[0], target->rooms[0])
						|| chr->aibot->unk1a8[mpindex] == target->rooms[0]
						|| roomsAreNeighbours(chr->aibot->unk1a8[mpindex], target->rooms[0])) {
					result = true;
				}

				if (chr->aibot->simulant->difficulty == SIMDIFF_NORMAL) {
					if (chr->aibot->unk208 > 0 && chr->aibot->unk208 < 4) {
						result = true;
					}
				} else {
					if (chr->aibot->unk208 > 0 && chr->aibot->unk208 < 5) {
						result = true;
					}
				}
			}
		}

		if (!arg1
				&& (chr->aibot->simulant->difficulty == SIMDIFF_MEAT || chr->aibot->simulant->difficulty == SIMDIFF_EASY)
				&& !func0f02e064(chr)) {
			f32 tmp = func0f03e578(chr);
			f32 angle = atan2f(target->pos.x - chr->prop->pos.x, target->pos.z - chr->prop->pos.z) - tmp;

			if (angle < 0) {
				angle += M_BADTAU;
			}

			if (angle > M_PI) {
				angle = M_BADTAU - angle;
			}

			if (chr->aibot->simulant->difficulty == SIMDIFF_MEAT) {
				if (angle > 0.43626284599304f) {
					result = false;
				}
			} else {
				if (chr->aibot->simulant->difficulty == SIMDIFF_EASY && angle > 1.5705461502075f) {
					result = false;
				}
			}
		}
	}

	return result;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel aibotTick
.late_rodata
glabel var7f1b8ecc
.word 0x40c907a9
glabel var7f1b8ed0
.word 0x40c907a9
glabel var7f1b8ed4
.word 0x3d80a8be
glabel var7f1b8ed8
.word 0x40c907a9
glabel var7f1b8edc
.word 0x39c59ed7
glabel var7f1b8ee0
.word 0x3d7c45d9
glabel var7f1b8ee4
.word 0xc0490fdb
glabel var7f1b8ee8
.word 0x40490fdb
glabel var7f1b8eec
.word 0x40490fdb
glabel var7f1b8ef0
.word 0x4181e420
.text
/*  f1918d0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1918d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1918d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1918dc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1918e0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f1918e4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f1918e8:	8e3002d4 */ 	lw	$s0,0x2d4($s1)
/*  f1918ec:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f1918f0:	90870001 */ 	lbu	$a3,0x1($a0)
/*  f1918f4:	30ef0008 */ 	andi	$t7,$a3,0x8
/*  f1918f8:	000f382b */ 	sltu	$a3,$zero,$t7
/*  f1918fc:	10e00005 */ 	beqz	$a3,.L0f191914
/*  f191900:	00000000 */ 	nop
/*  f191904:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x34)
/*  f191908:	8ce79ff4 */ 	lw	$a3,%lo(g_Vars+0x34)($a3)
/*  f19190c:	0007c82b */ 	sltu	$t9,$zero,$a3
/*  f191910:	03203825 */ 	or	$a3,$t9,$zero
.L0f191914:
/*  f191914:	1200019d */ 	beqz	$s0,.L0f191f8c
/*  f191918:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f19191c:	10e00183 */ 	beqz	$a3,.L0f191f2c
/*  f191920:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x8)
/*  f191924:	8d089fc8 */ 	lw	$t0,%lo(g_Vars+0x8)($t0)
/*  f191928:	29010091 */ 	slti	$at,$t0,0x91
/*  f19192c:	1420017f */ 	bnez	$at,.L0f191f2c
/*  f191930:	00000000 */ 	nop
/*  f191934:	0fc652d0 */ 	jal	func0f194b40
/*  f191938:	02202025 */ 	or	$a0,$s1,$zero
/*  f19193c:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f191940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191944:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f191948:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19194c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f191950:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f191954:	11a10014 */ 	beq	$t5,$at,.L0f1919a8
/*  f191958:	01801825 */ 	or	$v1,$t4,$zero
/*  f19195c:	85840028 */ 	lh	$a0,0x28($t4)
.L0f191960:
/*  f191960:	0fc575ba */ 	jal	roomIsVisibleByAnyPlayer
/*  f191964:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f191968:	14400006 */ 	bnez	$v0,.L0f191984
/*  f19196c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f191970:	84640028 */ 	lh	$a0,0x28($v1)
/*  f191974:	0fc575d1 */ 	jal	roomIsVisibleByAnyAibot
/*  f191978:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f19197c:	10400005 */ 	beqz	$v0,.L0f191994
/*  f191980:	8fa30028 */ 	lw	$v1,0x28($sp)
.L0f191984:
/*  f191984:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f191988:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f19198c:	10000006 */ 	b	.L0f1919a8
/*  f191990:	a20f009c */ 	sb	$t7,0x9c($s0)
.L0f191994:
/*  f191994:	8464002a */ 	lh	$a0,0x2a($v1)
/*  f191998:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19199c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1919a0:	1481ffef */ 	bne	$a0,$at,.L0f191960
/*  f1919a4:	00000000 */ 	nop
.L0f1919a8:
/*  f1919a8:	862202d8 */ 	lh	$v0,0x2d8($s1)
/*  f1919ac:	18400012 */ 	blez	$v0,.L0f1919f8
/*  f1919b0:	28411389 */ 	slti	$at,$v0,0x1047
/*  f1919b4:	14200004 */ 	bnez	$at,.L0f1919c8
/*  f1919b8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x38)
/*  f1919bc:	24181388 */ 	addiu	$t8,$zero,0x1046
/*  f1919c0:	a63802d8 */ 	sh	$t8,0x2d8($s1)
/*  f1919c4:	862202d8 */ 	lh	$v0,0x2d8($s1)
.L0f1919c8:
/*  f1919c8:	922802ff */ 	lbu	$t0,0x2ff($s1)
/*  f1919cc:	8f399ff8 */ 	lw	$t9,%lo(g_Vars+0x38)($t9)
/*  f1919d0:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f1919d4:	03290019 */ 	multu	$t9,$t1
/*  f1919d8:	00005012 */ 	mflo	$t2
/*  f1919dc:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f1919e0:	a62b02d8 */ 	sh	$t3,0x2d8($s1)
/*  f1919e4:	862d02d8 */ 	lh	$t5,0x2d8($s1)
/*  f1919e8:	1da00003 */ 	bgtz	$t5,.L0f1919f8
/*  f1919ec:	00000000 */ 	nop
/*  f1919f0:	a62002d8 */ 	sh	$zero,0x2d8($s1)
/*  f1919f4:	a22002ff */ 	sb	$zero,0x2ff($s1)
.L0f1919f8:
/*  f1919f8:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f1919fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a00:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f191a04:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191a08:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a0c:	50400006 */ 	beqzl	$v0,.L0f191a28
/*  f191a10:	8e0c0044 */ 	lw	$t4,0x44($s0)
/*  f191a14:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a18:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a1c:	1000005b */ 	b	.L0f191b8c
/*  f191a20:	46000086 */ 	mov.s	$f2,$f0
/*  f191a24:	8e0c0044 */ 	lw	$t4,0x44($s0)
.L0f191a28:
/*  f191a28:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a2c:	11800005 */ 	beqz	$t4,.L0f191a44
/*  f191a30:	00000000 */ 	nop
/*  f191a34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a38:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a3c:	10000053 */ 	b	.L0f191b8c
/*  f191a40:	46000086 */ 	mov.s	$f2,$f0
.L0f191a44:
/*  f191a44:	0fc6458e */ 	jal	func0f191638
/*  f191a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f191a4c:	5040000c */ 	beqzl	$v0,.L0f191a80
/*  f191a50:	922402a0 */ 	lbu	$a0,0x2a0($s1)
/*  f191a54:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191a58:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a60:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191a64:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f191a68:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191a6c:	c60801c0 */ 	lwc1	$f8,0x1c0($s0)
/*  f191a70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f191a74:	10000045 */ 	b	.L0f191b8c
/*  f191a78:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f191a7c:	922402a0 */ 	lbu	$a0,0x2a0($s1)
.L0f191a80:
/*  f191a80:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f191a84:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f191a88:	1481000f */ 	bne	$a0,$at,.L0f191ac8
/*  f191a8c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f191a90:	8c6200d4 */ 	lw	$v0,0xd4($v1)
/*  f191a94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191a98:	1041000b */ 	beq	$v0,$at,.L0f191ac8
/*  f191a9c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191aa0:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f191aa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f191aa8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f191aac:	8de50080 */ 	lw	$a1,0x80($t7)
/*  f191ab0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191ab4:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191ab8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f191abc:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191ac0:	10000032 */ 	b	.L0f191b8c
/*  f191ac4:	46005080 */ 	add.s	$f2,$f10,$f0
.L0f191ac8:
/*  f191ac8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f191acc:	5481001e */ 	bnel	$a0,$at,.L0f191b48
/*  f191ad0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191ad4:	8602000a */ 	lh	$v0,0xa($s0)
/*  f191ad8:	3c014396 */ 	lui	$at,0x4396
/*  f191adc:	04400019 */ 	bltz	$v0,.L0f191b44
/*  f191ae0:	00021880 */ 	sll	$v1,$v0,0x2
/*  f191ae4:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f191ae8:	c704013c */ 	lwc1	$f4,0x13c($t8)
/*  f191aec:	44813000 */ 	mtc1	$at,$f6
/*  f191af0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x8)
/*  f191af4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f191af8:	00000000 */ 	nop
/*  f191afc:	45020012 */ 	bc1fl	.L0f191b48
/*  f191b00:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b04:	8f399fc8 */ 	lw	$t9,%lo(g_Vars+0x8)($t9)
/*  f191b08:	8e0801e4 */ 	lw	$t0,0x1e4($s0)
/*  f191b0c:	2729ffc4 */ 	addiu	$t1,$t9,-50
/*  f191b10:	0109082a */ 	slt	$at,$t0,$t1
/*  f191b14:	5420000c */ 	bnezl	$at,.L0f191b48
/*  f191b18:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b1c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f191b20:	914b0048 */ 	lbu	$t3,0x48($t2)
/*  f191b24:	51600008 */ 	beqzl	$t3,.L0f191b48
/*  f191b28:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b2c:	3c04800b */ 	lui	$a0,%hi(g_MpPlayerChrs)
/*  f191b30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f191b34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191b38:	8c84c4d0 */ 	lw	$a0,%lo(g_MpPlayerChrs)($a0)
/*  f191b3c:	10000013 */ 	b	.L0f191b8c
/*  f191b40:	46000086 */ 	mov.s	$f2,$f0
.L0f191b44:
/*  f191b44:	24010033 */ 	addiu	$at,$zero,0x33
.L0f191b48:
/*  f191b48:	1481000d */ 	bne	$a0,$at,.L0f191b80
/*  f191b4c:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191b50:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191b54:	8e0d01e4 */ 	lw	$t5,0x1e4($s0)
/*  f191b58:	258effc4 */ 	addiu	$t6,$t4,-50
/*  f191b5c:	01ae082a */ 	slt	$at,$t5,$t6
/*  f191b60:	14200007 */ 	bnez	$at,.L0f191b80
/*  f191b64:	00000000 */ 	nop
/*  f191b68:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f191b6c:	91f80048 */ 	lbu	$t8,0x48($t7)
/*  f191b70:	13000003 */ 	beqz	$t8,.L0f191b80
/*  f191b74:	00000000 */ 	nop
/*  f191b78:	10000004 */ 	b	.L0f191b8c
/*  f191b7c:	c6020098 */ 	lwc1	$f2,0x98($s0)
.L0f191b80:
/*  f191b80:	0fc0f95e */ 	jal	func0f03e578
/*  f191b84:	02202025 */ 	or	$a0,$s1,$zero
/*  f191b88:	46000086 */ 	mov.s	$f2,$f0
.L0f191b8c:
/*  f191b8c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ecc)
/*  f191b90:	c42e8ecc */ 	lwc1	$f14,%lo(var7f1b8ecc)($at)
/*  f191b94:	44809000 */ 	mtc1	$zero,$f18
/*  f191b98:	4602703e */ 	c.le.s	$f14,$f2
/*  f191b9c:	00000000 */ 	nop
/*  f191ba0:	45020007 */ 	bc1fl	.L0f191bc0
/*  f191ba4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191ba8:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191bac:
/*  f191bac:	4602703e */ 	c.le.s	$f14,$f2
/*  f191bb0:	00000000 */ 	nop
/*  f191bb4:	4503fffd */ 	bc1tl	.L0f191bac
/*  f191bb8:	460e1081 */ 	sub.s	$f2,$f2,$f14
/*  f191bbc:	4612103c */ 	c.lt.s	$f2,$f18
.L0f191bc0:
/*  f191bc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191bc4:	45020007 */ 	bc1fl	.L0f191be4
/*  f191bc8:	863902d8 */ 	lh	$t9,0x2d8($s1)
/*  f191bcc:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191bd0:
/*  f191bd0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191bd4:	00000000 */ 	nop
/*  f191bd8:	4503fffd */ 	bc1tl	.L0f191bd0
/*  f191bdc:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f191be0:	863902d8 */ 	lh	$t9,0x2d8($s1)
.L0f191be4:
/*  f191be4:	5b20002c */ 	blezl	$t9,.L0f191c98
/*  f191be8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191bec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191bf0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191bf4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed0)
/*  f191bf8:	44809000 */ 	mtc1	$zero,$f18
/*  f191bfc:	c42e8ed0 */ 	lwc1	$f14,%lo(var7f1b8ed0)($at)
/*  f191c00:	14400024 */ 	bnez	$v0,.L0f191c94
/*  f191c04:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c08:	8e080044 */ 	lw	$t0,0x44($s0)
/*  f191c0c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191c10:	55000021 */ 	bnezl	$t0,.L0f191c98
/*  f191c14:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191c18:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191c1c:	24010078 */ 	addiu	$at,$zero,0x64
/*  f191c20:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191c24:	0121001a */ 	div	$zero,$t1,$at
/*  f191c28:	00005010 */ 	mfhi	$t2
/*  f191c2c:	448a4000 */ 	mtc1	$t2,$f8
/*  f191c30:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed4)
/*  f191c34:	c4248ed4 */ 	lwc1	$f4,%lo(var7f1b8ed4)($at)
/*  f191c38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f191c3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f191c40:	0c0068f7 */ 	jal	sinf
/*  f191c44:	00000000 */ 	nop
/*  f191c48:	862b02d8 */ 	lh	$t3,0x2d8($s1)
/*  f191c4c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed8)
/*  f191c50:	c42e8ed8 */ 	lwc1	$f14,%lo(var7f1b8ed8)($at)
/*  f191c54:	448b3000 */ 	mtc1	$t3,$f6
/*  f191c58:	3c017f1c */ 	lui	$at,%hi(var7f1b8edc)
/*  f191c5c:	c42a8edc */ 	lwc1	$f10,%lo(var7f1b8edc)($at)
/*  f191c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f191c64:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c68:	44809000 */ 	mtc1	$zero,$f18
/*  f191c6c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f191c70:	00000000 */ 	nop
/*  f191c74:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f191c78:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f191c7c:	4602703e */ 	c.le.s	$f14,$f2
/*  f191c80:	00000000 */ 	nop
/*  f191c84:	45000002 */ 	bc1f	.L0f191c90
/*  f191c88:	00000000 */ 	nop
/*  f191c8c:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191c90:
/*  f191c90:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191c94:
/*  f191c94:	c7a40044 */ 	lwc1	$f4,0x44($sp)
.L0f191c98:
/*  f191c98:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee0)
/*  f191c9c:	c42a8ee0 */ 	lwc1	$f10,%lo(var7f1b8ee0)($at)
/*  f191ca0:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f191ca4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee4)
/*  f191ca8:	c4268ee4 */ 	lwc1	$f6,%lo(var7f1b8ee4)($at)
/*  f191cac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f191cb0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f191cb4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f191cb8:	c448004c */ 	lwc1	$f8,0x4c($v0)
/*  f191cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f191cc0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee8)
/*  f191cc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f191cc8:	45000003 */ 	bc1f	.L0f191cd8
/*  f191ccc:	00000000 */ 	nop
/*  f191cd0:	10000007 */ 	b	.L0f191cf0
/*  f191cd4:	460e0400 */ 	add.s	$f16,$f0,$f14
.L0f191cd8:
/*  f191cd8:	c4288ee8 */ 	lwc1	$f8,%lo(var7f1b8ee8)($at)
/*  f191cdc:	4600403e */ 	c.le.s	$f8,$f0
/*  f191ce0:	00000000 */ 	nop
/*  f191ce4:	45020003 */ 	bc1fl	.L0f191cf4
/*  f191ce8:	4610903e */ 	c.le.s	$f18,$f16
/*  f191cec:	460e0401 */ 	sub.s	$f16,$f0,$f14
.L0f191cf0:
/*  f191cf0:	4610903e */ 	c.le.s	$f18,$f16
.L0f191cf4:
/*  f191cf4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f191cf8:	3c017f1c */ 	lui	$at,%hi(var7f1b8eec)
/*  f191cfc:	4502000f */ 	bc1fl	.L0f191d3c
/*  f191d00:	46006107 */ 	neg.s	$f4,$f12
/*  f191d04:	460c803e */ 	c.le.s	$f16,$f12
/*  f191d08:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191d0c:	45020004 */ 	bc1fl	.L0f191d20
/*  f191d10:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f191d14:	10000015 */ 	b	.L0f191d6c
/*  f191d18:	46001006 */ 	mov.s	$f0,$f2
/*  f191d1c:	460c5080 */ 	add.s	$f2,$f10,$f12
.L0f191d20:
/*  f191d20:	4602703e */ 	c.le.s	$f14,$f2
/*  f191d24:	46001006 */ 	mov.s	$f0,$f2
/*  f191d28:	45020011 */ 	bc1fl	.L0f191d70
/*  f191d2c:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f191d30:	1000000e */ 	b	.L0f191d6c
/*  f191d34:	460e1001 */ 	sub.s	$f0,$f2,$f14
/*  f191d38:	46006107 */ 	neg.s	$f4,$f12
.L0f191d3c:
/*  f191d3c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f191d40:	4610203e */ 	c.le.s	$f4,$f16
/*  f191d44:	00000000 */ 	nop
/*  f191d48:	45020004 */ 	bc1fl	.L0f191d5c
/*  f191d4c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f191d50:	10000006 */ 	b	.L0f191d6c
/*  f191d54:	46001006 */ 	mov.s	$f0,$f2
/*  f191d58:	460c303c */ 	c.lt.s	$f6,$f12
.L0f191d5c:
/*  f191d5c:	460c3081 */ 	sub.s	$f2,$f6,$f12
/*  f191d60:	45000002 */ 	bc1f	.L0f191d6c
/*  f191d64:	46001006 */ 	mov.s	$f0,$f2
/*  f191d68:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0f191d6c:
/*  f191d6c:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0f191d70:
/*  f191d70:	e60a00ac */ 	swc1	$f10,0xac($s0)
/*  f191d74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191d78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f191d7c:	00000000 */ 	nop
/*  f191d80:	45020005 */ 	bc1fl	.L0f191d98
/*  f191d84:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191d88:	c60600ac */ 	lwc1	$f6,0xac($s0)
/*  f191d8c:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f191d90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191d94:	c60200ac */ 	lwc1	$f2,0xac($s0)
.L0f191d98:
/*  f191d98:	c42a8eec */ 	lwc1	$f10,%lo(var7f1b8eec)($at)
/*  f191d9c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef0)
/*  f191da0:	4602503e */ 	c.le.s	$f10,$f2
/*  f191da4:	00000000 */ 	nop
/*  f191da8:	45020005 */ 	bc1fl	.L0f191dc0
/*  f191dac:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f191db0:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f191db4:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f191db8:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191dbc:	c446004c */ 	lwc1	$f6,0x4c($v0)
.L0f191dc0:
/*  f191dc0:	4600703e */ 	c.le.s	$f14,$f0
/*  f191dc4:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f191dc8:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191dcc:	c60a00ac */ 	lwc1	$f10,0xac($s0)
/*  f191dd0:	c4248ef0 */ 	lwc1	$f4,%lo(var7f1b8ef0)($at)
/*  f191dd4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f191dd8:	45000006 */ 	bc1f	.L0f191df4
/*  f191ddc:	e60600ac */ 	swc1	$f6,0xac($s0)
/*  f191de0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191de4:
/*  f191de4:	4600703e */ 	c.le.s	$f14,$f0
/*  f191de8:	00000000 */ 	nop
/*  f191dec:	4503fffd */ 	bc1tl	.L0f191de4
/*  f191df0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191df4:
/*  f191df4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191df8:	00000000 */ 	nop
/*  f191dfc:	45020007 */ 	bc1fl	.L0f191e1c
/*  f191e00:	44050000 */ 	mfc1	$a1,$f0
/*  f191e04:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f191e08:
/*  f191e08:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191e0c:	00000000 */ 	nop
/*  f191e10:	4503fffd */ 	bc1tl	.L0f191e08
/*  f191e14:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f191e18:	44050000 */ 	mfc1	$a1,$f0
.L0f191e1c:
/*  f191e1c:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f191e20:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e24:	862c017e */ 	lh	$t4,0x17e($s1)
/*  f191e28:	44809000 */ 	mtc1	$zero,$f18
/*  f191e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191e30:	11810018 */ 	beq	$t4,$at,.L0f191e94
/*  f191e34:	00000000 */ 	nop
/*  f191e38:	8e0d004c */ 	lw	$t5,0x4c($s0)
/*  f191e3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e40:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f191e44:	05e00013 */ 	bltz	$t7,.L0f191e94
/*  f191e48:	00000000 */ 	nop
/*  f191e4c:	8e380174 */ 	lw	$t8,0x174($s1)
/*  f191e50:	00003025 */ 	or	$a2,$zero,$zero
/*  f191e54:	00003825 */ 	or	$a3,$zero,$zero
/*  f191e58:	13000003 */ 	beqz	$t8,.L0f191e68
/*  f191e5c:	00000000 */ 	nop
/*  f191e60:	10000001 */ 	b	.L0f191e68
/*  f191e64:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191e68:
/*  f191e68:	8e390170 */ 	lw	$t9,0x170($s1)
/*  f191e6c:	13200003 */ 	beqz	$t9,.L0f191e7c
/*  f191e70:	00000000 */ 	nop
/*  f191e74:	10000001 */ 	b	.L0f191e7c
/*  f191e78:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f191e7c:
/*  f191e7c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f191e80:	0fc0fa7d */ 	jal	func0f03e9f4
/*  f191e84:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f191e88:	44809000 */ 	mtc1	$zero,$f18
/*  f191e8c:	10000006 */ 	b	.L0f191ea8
/*  f191e90:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191e94:
/*  f191e94:	0fc0fe0a */ 	jal	chrResetAimEndProperties
/*  f191e98:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e9c:	44809000 */ 	mtc1	$zero,$f18
/*  f191ea0:	00000000 */ 	nop
/*  f191ea4:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191ea8:
/*  f191ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191eac:	10410003 */ 	beq	$v0,$at,.L0f191ebc
/*  f191eb0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f191eb4:	54410005 */ 	bnel	$v0,$at,.L0f191ecc
/*  f191eb8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ebc:
/*  f191ebc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ec0:	1000001a */ 	b	.L0f191f2c
/*  f191ec4:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ec8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ecc:
/*  f191ecc:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191ed0:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191ed4:	11000006 */ 	beqz	$t0,.L0f191ef0
/*  f191ed8:	00000000 */ 	nop
/*  f191edc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ee0:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ee4:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191ee8:	10000010 */ 	b	.L0f191f2c
/*  f191eec:	ae0901e4 */ 	sw	$t1,0x1e4($s0)
.L0f191ef0:
/*  f191ef0:	1441000a */ 	bne	$v0,$at,.L0f191f1c
/*  f191ef4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191ef8:	922a0065 */ 	lbu	$t2,0x65($s1)
/*  f191efc:	3c013f80 */ 	lui	$at,0x3f80
/*  f191f00:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f191f04:	55600006 */ 	bnezl	$t3,.L0f191f20
/*  f191f08:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191f0c:	44814000 */ 	mtc1	$at,$f8
/*  f191f10:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f14:	10000005 */ 	b	.L0f191f2c
/*  f191f18:	e608006c */ 	swc1	$f8,0x6c($s0)
.L0f191f1c:
/*  f191f1c:	e612006c */ 	swc1	$f18,0x6c($s0)
.L0f191f20:
/*  f191f20:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f24:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191f28:	ae0c01e4 */ 	sw	$t4,0x1e4($s0)
.L0f191f2c:
/*  f191f2c:	0fc64512 */ 	jal	func0f191448
/*  f191f30:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f34:	0fc08c26 */ 	jal	func0f023098
/*  f191f38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191f3c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x8)
/*  f191f40:	8dad9fc8 */ 	lw	$t5,%lo(g_Vars+0x8)($t5)
/*  f191f44:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f191f48:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f191f4c:	29a10091 */ 	slti	$at,$t5,0x91
/*  f191f50:	5420000f */ 	bnezl	$at,.L0f191f90
/*  f191f54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f58:	51c00004 */ 	beqzl	$t6,.L0f191f6c
/*  f191f5c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f191f60:	0fc615c8 */ 	jal	scenarioCallback14
/*  f191f64:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f68:	8faf0058 */ 	lw	$t7,0x58($sp)
.L0f191f6c:
/*  f191f6c:	51e00008 */ 	beqzl	$t7,.L0f191f90
/*  f191f70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f74:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191f78:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f7c:	54400004 */ 	bnezl	$v0,.L0f191f90
/*  f191f80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f84:	0fc64493 */ 	jal	func0f19124c
/*  f191f88:	02202025 */ 	or	$a0,$s1,$zero
.L0f191f8c:
/*  f191f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191f90:
/*  f191f90:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f191f94:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f191f98:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f191f9c:	03e00008 */ 	jr	$ra
/*  f191fa0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#else
GLOBAL_ASM(
glabel aibotTick
.late_rodata
glabel var7f1b8ecc
.word 0x40c907a9
glabel var7f1b8ed0
.word 0x40c907a9
glabel var7f1b8ed4
.word 0x3d566e92
glabel var7f1b8ed8
.word 0x40c907a9
glabel var7f1b8edc
.word 0x39a4af08
glabel var7f1b8ee0
.word 0x3d7c45d9
glabel var7f1b8ee4
.word 0xc0490fdb
glabel var7f1b8ee8
.word 0x40490fdb
glabel var7f1b8eec
.word 0x40490fdb
glabel var7f1b8ef0
.word 0x4181e420
.text
/*  f1918d0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1918d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1918d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1918dc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1918e0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f1918e4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f1918e8:	8e3002d4 */ 	lw	$s0,0x2d4($s1)
/*  f1918ec:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f1918f0:	90870001 */ 	lbu	$a3,0x1($a0)
/*  f1918f4:	30ef0008 */ 	andi	$t7,$a3,0x8
/*  f1918f8:	000f382b */ 	sltu	$a3,$zero,$t7
/*  f1918fc:	10e00005 */ 	beqz	$a3,.L0f191914
/*  f191900:	00000000 */ 	nop
/*  f191904:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x34)
/*  f191908:	8ce79ff4 */ 	lw	$a3,%lo(g_Vars+0x34)($a3)
/*  f19190c:	0007c82b */ 	sltu	$t9,$zero,$a3
/*  f191910:	03203825 */ 	or	$a3,$t9,$zero
.L0f191914:
/*  f191914:	1200019d */ 	beqz	$s0,.L0f191f8c
/*  f191918:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f19191c:	10e00183 */ 	beqz	$a3,.L0f191f2c
/*  f191920:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x8)
/*  f191924:	8d089fc8 */ 	lw	$t0,%lo(g_Vars+0x8)($t0)
/*  f191928:	29010091 */ 	slti	$at,$t0,0x91
/*  f19192c:	1420017f */ 	bnez	$at,.L0f191f2c
/*  f191930:	00000000 */ 	nop
/*  f191934:	0fc652d0 */ 	jal	func0f194b40
/*  f191938:	02202025 */ 	or	$a0,$s1,$zero
/*  f19193c:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f191940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191944:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f191948:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19194c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f191950:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f191954:	11a10014 */ 	beq	$t5,$at,.L0f1919a8
/*  f191958:	01801825 */ 	or	$v1,$t4,$zero
/*  f19195c:	85840028 */ 	lh	$a0,0x28($t4)
.L0f191960:
/*  f191960:	0fc575ba */ 	jal	roomIsVisibleByAnyPlayer
/*  f191964:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f191968:	14400006 */ 	bnez	$v0,.L0f191984
/*  f19196c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f191970:	84640028 */ 	lh	$a0,0x28($v1)
/*  f191974:	0fc575d1 */ 	jal	roomIsVisibleByAnyAibot
/*  f191978:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f19197c:	10400005 */ 	beqz	$v0,.L0f191994
/*  f191980:	8fa30028 */ 	lw	$v1,0x28($sp)
.L0f191984:
/*  f191984:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f191988:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f19198c:	10000006 */ 	b	.L0f1919a8
/*  f191990:	a20f009c */ 	sb	$t7,0x9c($s0)
.L0f191994:
/*  f191994:	8464002a */ 	lh	$a0,0x2a($v1)
/*  f191998:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19199c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1919a0:	1481ffef */ 	bne	$a0,$at,.L0f191960
/*  f1919a4:	00000000 */ 	nop
.L0f1919a8:
/*  f1919a8:	862202d8 */ 	lh	$v0,0x2d8($s1)
/*  f1919ac:	18400012 */ 	blez	$v0,.L0f1919f8
/*  f1919b0:	28411389 */ 	slti	$at,$v0,0x1389
/*  f1919b4:	14200004 */ 	bnez	$at,.L0f1919c8
/*  f1919b8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x38)
/*  f1919bc:	24181388 */ 	addiu	$t8,$zero,0x1388
/*  f1919c0:	a63802d8 */ 	sh	$t8,0x2d8($s1)
/*  f1919c4:	862202d8 */ 	lh	$v0,0x2d8($s1)
.L0f1919c8:
/*  f1919c8:	922802ff */ 	lbu	$t0,0x2ff($s1)
/*  f1919cc:	8f399ff8 */ 	lw	$t9,%lo(g_Vars+0x38)($t9)
/*  f1919d0:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f1919d4:	03290019 */ 	multu	$t9,$t1
/*  f1919d8:	00005012 */ 	mflo	$t2
/*  f1919dc:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f1919e0:	a62b02d8 */ 	sh	$t3,0x2d8($s1)
/*  f1919e4:	862d02d8 */ 	lh	$t5,0x2d8($s1)
/*  f1919e8:	1da00003 */ 	bgtz	$t5,.L0f1919f8
/*  f1919ec:	00000000 */ 	nop
/*  f1919f0:	a62002d8 */ 	sh	$zero,0x2d8($s1)
/*  f1919f4:	a22002ff */ 	sb	$zero,0x2ff($s1)
.L0f1919f8:
/*  f1919f8:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f1919fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a00:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f191a04:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191a08:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a0c:	50400006 */ 	beqzl	$v0,.L0f191a28
/*  f191a10:	8e0c0044 */ 	lw	$t4,0x44($s0)
/*  f191a14:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a18:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a1c:	1000005b */ 	b	.L0f191b8c
/*  f191a20:	46000086 */ 	mov.s	$f2,$f0
/*  f191a24:	8e0c0044 */ 	lw	$t4,0x44($s0)
.L0f191a28:
/*  f191a28:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a2c:	11800005 */ 	beqz	$t4,.L0f191a44
/*  f191a30:	00000000 */ 	nop
/*  f191a34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a38:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a3c:	10000053 */ 	b	.L0f191b8c
/*  f191a40:	46000086 */ 	mov.s	$f2,$f0
.L0f191a44:
/*  f191a44:	0fc6458e */ 	jal	func0f191638
/*  f191a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f191a4c:	5040000c */ 	beqzl	$v0,.L0f191a80
/*  f191a50:	922402a0 */ 	lbu	$a0,0x2a0($s1)
/*  f191a54:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191a58:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a60:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191a64:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f191a68:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191a6c:	c60801c0 */ 	lwc1	$f8,0x1c0($s0)
/*  f191a70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f191a74:	10000045 */ 	b	.L0f191b8c
/*  f191a78:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f191a7c:	922402a0 */ 	lbu	$a0,0x2a0($s1)
.L0f191a80:
/*  f191a80:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f191a84:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f191a88:	1481000f */ 	bne	$a0,$at,.L0f191ac8
/*  f191a8c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f191a90:	8c6200d4 */ 	lw	$v0,0xd4($v1)
/*  f191a94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191a98:	1041000b */ 	beq	$v0,$at,.L0f191ac8
/*  f191a9c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191aa0:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f191aa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f191aa8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f191aac:	8de50080 */ 	lw	$a1,0x80($t7)
/*  f191ab0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191ab4:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191ab8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f191abc:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191ac0:	10000032 */ 	b	.L0f191b8c
/*  f191ac4:	46005080 */ 	add.s	$f2,$f10,$f0
.L0f191ac8:
/*  f191ac8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f191acc:	5481001e */ 	bnel	$a0,$at,.L0f191b48
/*  f191ad0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191ad4:	8602000a */ 	lh	$v0,0xa($s0)
/*  f191ad8:	3c014396 */ 	lui	$at,0x4396
/*  f191adc:	04400019 */ 	bltz	$v0,.L0f191b44
/*  f191ae0:	00021880 */ 	sll	$v1,$v0,0x2
/*  f191ae4:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f191ae8:	c704013c */ 	lwc1	$f4,0x13c($t8)
/*  f191aec:	44813000 */ 	mtc1	$at,$f6
/*  f191af0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x8)
/*  f191af4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f191af8:	00000000 */ 	nop
/*  f191afc:	45020012 */ 	bc1fl	.L0f191b48
/*  f191b00:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b04:	8f399fc8 */ 	lw	$t9,%lo(g_Vars+0x8)($t9)
/*  f191b08:	8e0801e4 */ 	lw	$t0,0x1e4($s0)
/*  f191b0c:	2729ffc4 */ 	addiu	$t1,$t9,-60
/*  f191b10:	0109082a */ 	slt	$at,$t0,$t1
/*  f191b14:	5420000c */ 	bnezl	$at,.L0f191b48
/*  f191b18:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b1c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f191b20:	914b0048 */ 	lbu	$t3,0x48($t2)
/*  f191b24:	51600008 */ 	beqzl	$t3,.L0f191b48
/*  f191b28:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b2c:	3c04800b */ 	lui	$a0,%hi(g_MpPlayerChrs)
/*  f191b30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f191b34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191b38:	8c84c4d0 */ 	lw	$a0,%lo(g_MpPlayerChrs)($a0)
/*  f191b3c:	10000013 */ 	b	.L0f191b8c
/*  f191b40:	46000086 */ 	mov.s	$f2,$f0
.L0f191b44:
/*  f191b44:	24010033 */ 	addiu	$at,$zero,0x33
.L0f191b48:
/*  f191b48:	1481000d */ 	bne	$a0,$at,.L0f191b80
/*  f191b4c:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191b50:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191b54:	8e0d01e4 */ 	lw	$t5,0x1e4($s0)
/*  f191b58:	258effc4 */ 	addiu	$t6,$t4,-60
/*  f191b5c:	01ae082a */ 	slt	$at,$t5,$t6
/*  f191b60:	14200007 */ 	bnez	$at,.L0f191b80
/*  f191b64:	00000000 */ 	nop
/*  f191b68:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f191b6c:	91f80048 */ 	lbu	$t8,0x48($t7)
/*  f191b70:	13000003 */ 	beqz	$t8,.L0f191b80
/*  f191b74:	00000000 */ 	nop
/*  f191b78:	10000004 */ 	b	.L0f191b8c
/*  f191b7c:	c6020098 */ 	lwc1	$f2,0x98($s0)
.L0f191b80:
/*  f191b80:	0fc0f95e */ 	jal	func0f03e578
/*  f191b84:	02202025 */ 	or	$a0,$s1,$zero
/*  f191b88:	46000086 */ 	mov.s	$f2,$f0
.L0f191b8c:
/*  f191b8c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ecc)
/*  f191b90:	c42e8ecc */ 	lwc1	$f14,%lo(var7f1b8ecc)($at)
/*  f191b94:	44809000 */ 	mtc1	$zero,$f18
/*  f191b98:	4602703e */ 	c.le.s	$f14,$f2
/*  f191b9c:	00000000 */ 	nop
/*  f191ba0:	45020007 */ 	bc1fl	.L0f191bc0
/*  f191ba4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191ba8:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191bac:
/*  f191bac:	4602703e */ 	c.le.s	$f14,$f2
/*  f191bb0:	00000000 */ 	nop
/*  f191bb4:	4503fffd */ 	bc1tl	.L0f191bac
/*  f191bb8:	460e1081 */ 	sub.s	$f2,$f2,$f14
/*  f191bbc:	4612103c */ 	c.lt.s	$f2,$f18
.L0f191bc0:
/*  f191bc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191bc4:	45020007 */ 	bc1fl	.L0f191be4
/*  f191bc8:	863902d8 */ 	lh	$t9,0x2d8($s1)
/*  f191bcc:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191bd0:
/*  f191bd0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191bd4:	00000000 */ 	nop
/*  f191bd8:	4503fffd */ 	bc1tl	.L0f191bd0
/*  f191bdc:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f191be0:	863902d8 */ 	lh	$t9,0x2d8($s1)
.L0f191be4:
/*  f191be4:	5b20002c */ 	blezl	$t9,.L0f191c98
/*  f191be8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191bec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191bf0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191bf4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed0)
/*  f191bf8:	44809000 */ 	mtc1	$zero,$f18
/*  f191bfc:	c42e8ed0 */ 	lwc1	$f14,%lo(var7f1b8ed0)($at)
/*  f191c00:	14400024 */ 	bnez	$v0,.L0f191c94
/*  f191c04:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c08:	8e080044 */ 	lw	$t0,0x44($s0)
/*  f191c0c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191c10:	55000021 */ 	bnezl	$t0,.L0f191c98
/*  f191c14:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191c18:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191c1c:	24010078 */ 	addiu	$at,$zero,0x78
/*  f191c20:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191c24:	0121001a */ 	div	$zero,$t1,$at
/*  f191c28:	00005010 */ 	mfhi	$t2
/*  f191c2c:	448a4000 */ 	mtc1	$t2,$f8
/*  f191c30:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed4)
/*  f191c34:	c4248ed4 */ 	lwc1	$f4,%lo(var7f1b8ed4)($at)
/*  f191c38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f191c3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f191c40:	0c0068f7 */ 	jal	sinf
/*  f191c44:	00000000 */ 	nop
/*  f191c48:	862b02d8 */ 	lh	$t3,0x2d8($s1)
/*  f191c4c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed8)
/*  f191c50:	c42e8ed8 */ 	lwc1	$f14,%lo(var7f1b8ed8)($at)
/*  f191c54:	448b3000 */ 	mtc1	$t3,$f6
/*  f191c58:	3c017f1c */ 	lui	$at,%hi(var7f1b8edc)
/*  f191c5c:	c42a8edc */ 	lwc1	$f10,%lo(var7f1b8edc)($at)
/*  f191c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f191c64:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c68:	44809000 */ 	mtc1	$zero,$f18
/*  f191c6c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f191c70:	00000000 */ 	nop
/*  f191c74:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f191c78:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f191c7c:	4602703e */ 	c.le.s	$f14,$f2
/*  f191c80:	00000000 */ 	nop
/*  f191c84:	45000002 */ 	bc1f	.L0f191c90
/*  f191c88:	00000000 */ 	nop
/*  f191c8c:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191c90:
/*  f191c90:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191c94:
/*  f191c94:	c7a40044 */ 	lwc1	$f4,0x44($sp)
.L0f191c98:
/*  f191c98:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee0)
/*  f191c9c:	c42a8ee0 */ 	lwc1	$f10,%lo(var7f1b8ee0)($at)
/*  f191ca0:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f191ca4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee4)
/*  f191ca8:	c4268ee4 */ 	lwc1	$f6,%lo(var7f1b8ee4)($at)
/*  f191cac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f191cb0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f191cb4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f191cb8:	c448004c */ 	lwc1	$f8,0x4c($v0)
/*  f191cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f191cc0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee8)
/*  f191cc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f191cc8:	45000003 */ 	bc1f	.L0f191cd8
/*  f191ccc:	00000000 */ 	nop
/*  f191cd0:	10000007 */ 	b	.L0f191cf0
/*  f191cd4:	460e0400 */ 	add.s	$f16,$f0,$f14
.L0f191cd8:
/*  f191cd8:	c4288ee8 */ 	lwc1	$f8,%lo(var7f1b8ee8)($at)
/*  f191cdc:	4600403e */ 	c.le.s	$f8,$f0
/*  f191ce0:	00000000 */ 	nop
/*  f191ce4:	45020003 */ 	bc1fl	.L0f191cf4
/*  f191ce8:	4610903e */ 	c.le.s	$f18,$f16
/*  f191cec:	460e0401 */ 	sub.s	$f16,$f0,$f14
.L0f191cf0:
/*  f191cf0:	4610903e */ 	c.le.s	$f18,$f16
.L0f191cf4:
/*  f191cf4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f191cf8:	3c017f1c */ 	lui	$at,%hi(var7f1b8eec)
/*  f191cfc:	4502000f */ 	bc1fl	.L0f191d3c
/*  f191d00:	46006107 */ 	neg.s	$f4,$f12
/*  f191d04:	460c803e */ 	c.le.s	$f16,$f12
/*  f191d08:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191d0c:	45020004 */ 	bc1fl	.L0f191d20
/*  f191d10:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f191d14:	10000015 */ 	b	.L0f191d6c
/*  f191d18:	46001006 */ 	mov.s	$f0,$f2
/*  f191d1c:	460c5080 */ 	add.s	$f2,$f10,$f12
.L0f191d20:
/*  f191d20:	4602703e */ 	c.le.s	$f14,$f2
/*  f191d24:	46001006 */ 	mov.s	$f0,$f2
/*  f191d28:	45020011 */ 	bc1fl	.L0f191d70
/*  f191d2c:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f191d30:	1000000e */ 	b	.L0f191d6c
/*  f191d34:	460e1001 */ 	sub.s	$f0,$f2,$f14
/*  f191d38:	46006107 */ 	neg.s	$f4,$f12
.L0f191d3c:
/*  f191d3c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f191d40:	4610203e */ 	c.le.s	$f4,$f16
/*  f191d44:	00000000 */ 	nop
/*  f191d48:	45020004 */ 	bc1fl	.L0f191d5c
/*  f191d4c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f191d50:	10000006 */ 	b	.L0f191d6c
/*  f191d54:	46001006 */ 	mov.s	$f0,$f2
/*  f191d58:	460c303c */ 	c.lt.s	$f6,$f12
.L0f191d5c:
/*  f191d5c:	460c3081 */ 	sub.s	$f2,$f6,$f12
/*  f191d60:	45000002 */ 	bc1f	.L0f191d6c
/*  f191d64:	46001006 */ 	mov.s	$f0,$f2
/*  f191d68:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0f191d6c:
/*  f191d6c:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0f191d70:
/*  f191d70:	e60a00ac */ 	swc1	$f10,0xac($s0)
/*  f191d74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191d78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f191d7c:	00000000 */ 	nop
/*  f191d80:	45020005 */ 	bc1fl	.L0f191d98
/*  f191d84:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191d88:	c60600ac */ 	lwc1	$f6,0xac($s0)
/*  f191d8c:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f191d90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191d94:	c60200ac */ 	lwc1	$f2,0xac($s0)
.L0f191d98:
/*  f191d98:	c42a8eec */ 	lwc1	$f10,%lo(var7f1b8eec)($at)
/*  f191d9c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef0)
/*  f191da0:	4602503e */ 	c.le.s	$f10,$f2
/*  f191da4:	00000000 */ 	nop
/*  f191da8:	45020005 */ 	bc1fl	.L0f191dc0
/*  f191dac:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f191db0:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f191db4:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f191db8:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191dbc:	c446004c */ 	lwc1	$f6,0x4c($v0)
.L0f191dc0:
/*  f191dc0:	4600703e */ 	c.le.s	$f14,$f0
/*  f191dc4:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f191dc8:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191dcc:	c60a00ac */ 	lwc1	$f10,0xac($s0)
/*  f191dd0:	c4248ef0 */ 	lwc1	$f4,%lo(var7f1b8ef0)($at)
/*  f191dd4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f191dd8:	45000006 */ 	bc1f	.L0f191df4
/*  f191ddc:	e60600ac */ 	swc1	$f6,0xac($s0)
/*  f191de0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191de4:
/*  f191de4:	4600703e */ 	c.le.s	$f14,$f0
/*  f191de8:	00000000 */ 	nop
/*  f191dec:	4503fffd */ 	bc1tl	.L0f191de4
/*  f191df0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191df4:
/*  f191df4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191df8:	00000000 */ 	nop
/*  f191dfc:	45020007 */ 	bc1fl	.L0f191e1c
/*  f191e00:	44050000 */ 	mfc1	$a1,$f0
/*  f191e04:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f191e08:
/*  f191e08:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191e0c:	00000000 */ 	nop
/*  f191e10:	4503fffd */ 	bc1tl	.L0f191e08
/*  f191e14:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f191e18:	44050000 */ 	mfc1	$a1,$f0
.L0f191e1c:
/*  f191e1c:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f191e20:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e24:	862c017e */ 	lh	$t4,0x17e($s1)
/*  f191e28:	44809000 */ 	mtc1	$zero,$f18
/*  f191e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191e30:	11810018 */ 	beq	$t4,$at,.L0f191e94
/*  f191e34:	00000000 */ 	nop
/*  f191e38:	8e0d004c */ 	lw	$t5,0x4c($s0)
/*  f191e3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e40:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f191e44:	05e00013 */ 	bltz	$t7,.L0f191e94
/*  f191e48:	00000000 */ 	nop
/*  f191e4c:	8e380174 */ 	lw	$t8,0x174($s1)
/*  f191e50:	00003025 */ 	or	$a2,$zero,$zero
/*  f191e54:	00003825 */ 	or	$a3,$zero,$zero
/*  f191e58:	13000003 */ 	beqz	$t8,.L0f191e68
/*  f191e5c:	00000000 */ 	nop
/*  f191e60:	10000001 */ 	b	.L0f191e68
/*  f191e64:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191e68:
/*  f191e68:	8e390170 */ 	lw	$t9,0x170($s1)
/*  f191e6c:	13200003 */ 	beqz	$t9,.L0f191e7c
/*  f191e70:	00000000 */ 	nop
/*  f191e74:	10000001 */ 	b	.L0f191e7c
/*  f191e78:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f191e7c:
/*  f191e7c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f191e80:	0fc0fa7d */ 	jal	func0f03e9f4
/*  f191e84:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f191e88:	44809000 */ 	mtc1	$zero,$f18
/*  f191e8c:	10000006 */ 	b	.L0f191ea8
/*  f191e90:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191e94:
/*  f191e94:	0fc0fe0a */ 	jal	chrResetAimEndProperties
/*  f191e98:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e9c:	44809000 */ 	mtc1	$zero,$f18
/*  f191ea0:	00000000 */ 	nop
/*  f191ea4:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191ea8:
/*  f191ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191eac:	10410003 */ 	beq	$v0,$at,.L0f191ebc
/*  f191eb0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f191eb4:	54410005 */ 	bnel	$v0,$at,.L0f191ecc
/*  f191eb8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ebc:
/*  f191ebc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ec0:	1000001a */ 	b	.L0f191f2c
/*  f191ec4:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ec8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ecc:
/*  f191ecc:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191ed0:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191ed4:	11000006 */ 	beqz	$t0,.L0f191ef0
/*  f191ed8:	00000000 */ 	nop
/*  f191edc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ee0:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ee4:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191ee8:	10000010 */ 	b	.L0f191f2c
/*  f191eec:	ae0901e4 */ 	sw	$t1,0x1e4($s0)
.L0f191ef0:
/*  f191ef0:	1441000a */ 	bne	$v0,$at,.L0f191f1c
/*  f191ef4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191ef8:	922a0065 */ 	lbu	$t2,0x65($s1)
/*  f191efc:	3c013f80 */ 	lui	$at,0x3f80
/*  f191f00:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f191f04:	55600006 */ 	bnezl	$t3,.L0f191f20
/*  f191f08:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191f0c:	44814000 */ 	mtc1	$at,$f8
/*  f191f10:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f14:	10000005 */ 	b	.L0f191f2c
/*  f191f18:	e608006c */ 	swc1	$f8,0x6c($s0)
.L0f191f1c:
/*  f191f1c:	e612006c */ 	swc1	$f18,0x6c($s0)
.L0f191f20:
/*  f191f20:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f24:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191f28:	ae0c01e4 */ 	sw	$t4,0x1e4($s0)
.L0f191f2c:
/*  f191f2c:	0fc64512 */ 	jal	func0f191448
/*  f191f30:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f34:	0fc08c26 */ 	jal	func0f023098
/*  f191f38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191f3c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x8)
/*  f191f40:	8dad9fc8 */ 	lw	$t5,%lo(g_Vars+0x8)($t5)
/*  f191f44:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f191f48:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f191f4c:	29a10091 */ 	slti	$at,$t5,0x91
/*  f191f50:	5420000f */ 	bnezl	$at,.L0f191f90
/*  f191f54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f58:	51c00004 */ 	beqzl	$t6,.L0f191f6c
/*  f191f5c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f191f60:	0fc615c8 */ 	jal	scenarioCallback14
/*  f191f64:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f68:	8faf0058 */ 	lw	$t7,0x58($sp)
.L0f191f6c:
/*  f191f6c:	51e00008 */ 	beqzl	$t7,.L0f191f90
/*  f191f70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f74:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191f78:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f7c:	54400004 */ 	bnezl	$v0,.L0f191f90
/*  f191f80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f84:	0fc64493 */ 	jal	func0f19124c
/*  f191f88:	02202025 */ 	or	$a0,$s1,$zero
.L0f191f8c:
/*  f191f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191f90:
/*  f191f90:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f191f94:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f191f98:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f191f9c:	03e00008 */ 	jr	$ra
/*  f191fa0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#endif

// Mismatch: updateable is calculated differently
//s32 aibotTick(struct prop *prop)
//{
//	struct chrdata *chr = prop->chr;
//	struct aibot *aibot = chr->aibot;
//	s32 result = TICKOP_NONE;
//	bool updateable;
//	f32 oldangle;
//	f32 newangle;
//	f32 diffangle;
//	f32 tweenangle;
//	s32 i;
//
//	updateable = ((prop->flags & PROPFLAG_08) && g_Vars.lvupdate240) != 0;
//
//	if (aibot) {
//		if (updateable && g_Vars.lvframe60 >= 145) {
//			func0f194b40(chr);
//
//			// Calculate cheap
//			aibot->cheap = true;
//
//			for (i = 0; prop->rooms[i] != -1; i++) {
//				if (roomIsVisibleByAnyPlayer(prop->rooms[i]) || roomIsVisibleByAnyAibot(prop->rooms[i])) {
//					aibot->cheap = false;
//					break;
//				}
//			}
//
//			// Dampen blur
//			if (chr->blurdrugamount > 0) {
//				if (chr->blurdrugamount > 5000) {
//					chr->blurdrugamount = 5000;
//				}
//
//				chr->blurdrugamount -= g_Vars.lvupdate240_60 * (chr->blurnumtimesdied + 1);
//
//				if (chr->blurdrugamount <= 0) {
//					chr->blurdrugamount = 0;
//					chr->blurnumtimesdied = 0;
//				}
//			}
//
//			// Calculate target angle
//			oldangle = chrGetInverseTheta(chr);
//
//			if (chrIsDead(chr)) {
//				newangle = chrGetInverseTheta(chr);
//			} else if (aibot->skrocket) {
//				newangle = chrGetInverseTheta(chr);
//			} else if (func0f191638(chr, false)) {
//				struct prop *target = chrGetTargetProp(chr);
//				newangle = oldangle + chrGetAngleToPos(chr, &target->pos) + aibot->unk1c0;
//			} else if (chr->myaction == MA_AIBOTDOWNLOAD && g_ScenarioData.htm.unk0d4 != -1) {
//				newangle = oldangle + chrGetAngleToPos(chr, &g_ScenarioData.htm.unk07c[g_ScenarioData.htm.unk0d4].prop->pos);
//			} else if (chr->myaction == MA_AIBOTFOLLOW
//					&& aibot->followingplayernum >= 0
//					&& aibot->playerdistances[aibot->followingplayernum] < 300
//					&& aibot->unk1e4 >= g_Vars.lvframe60 - 60
//					&& aibot->simulant->difficulty != SIMDIFF_MEAT) {
//				newangle = chrGetInverseTheta(g_MpPlayerChrs[aibot->followingplayernum]);
//			} else if (chr->myaction == MA_AIBOTDEFEND
//					&& aibot->unk1e4 >= g_Vars.lvframe60 - 60
//					&& aibot->simulant->difficulty != SIMDIFF_MEAT) {
//				newangle = aibot->unk098;
//			} else {
//				newangle = func0f03e578(chr);
//			}
//
//			while (newangle >= M_BADTAU) {
//				newangle -= M_BADTAU;
//			}
//
//			while (newangle < 0) {
//				newangle += M_BADTAU;
//			}
//
//			if (chr->blurdrugamount > 0 && !chrIsDead(chr) && aibot->skrocket == NULL) {
//				newangle += chr->blurdrugamount * 0.00031410926021636f * sinf((g_Vars.lvframe60 % 120) * 0.052351541817188f);
//
//				if (newangle >= M_BADTAU) {
//					newangle -= M_BADTAU;
//				}
//
//				newangle += M_BADTAU;
//			}
//
//			diffangle = newangle - oldangle;
//			tweenangle = g_Vars.lvupdate240freal * 0.061590049415827f;
//
//			// cc8?
//			if (diffangle < -M_PI) {
//				diffangle += M_BADTAU;
//			} else if (diffangle >= M_PI) {
//				diffangle -= M_BADTAU;
//			}
//
//			// cfc
//			if (diffangle >= 0) {
//				if (diffangle >= tweenangle) {
//					newangle = tweenangle;
//				} else {
//					newangle = oldangle + tweenangle;
//
//					if (newangle >= M_BADTAU) {
//						newangle -= M_BADTAU;
//					}
//				}
//			} else {
//				// d40
//				if (diffangle <= -tweenangle) {
//					newangle = tweenangle;
//				} else {
//					newangle = oldangle - tweenangle;
//
//					if (newangle < 0) {
//						newangle += M_BADTAU;
//					}
//				}
//			}
//
//			aibot->speedtheta = newangle - oldangle;
//
//			if (aibot->speedtheta < 0) {
//				aibot->speedtheta += M_BADTAU;
//			}
//
//			if (aibot->speedtheta >= M_BADPI) {
//				aibot->speedtheta -= M_BADTAU;
//			}
//
//			aibot->speedtheta /= g_Vars.lvupdate240freal;
//			aibot->speedtheta *= 16.236389160156f;
//
//			while (newangle >= M_BADTAU) {
//				newangle -= M_BADTAU;
//			}
//
//			while (newangle < 0) {
//				newangle += M_BADTAU;
//			}
//
//			chrSetLookAngle(chr, newangle);
//
//			if (chr->target != -1 && !aibot->iscloserangeweapon) {
//				bool left = chr->weapons_held[HAND_LEFT] ? true : false;
//				bool right = chr->weapons_held[HAND_RIGHT] ? true : false;
//
//				func0f03e9f4(chr, aibot->unk068, left, right, 0);
//			} else {
//				chrResetAimEndProperties(chr);
//			}
//
//			if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD) {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//			} else if (aibot->skrocket) {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//				aibot->unk1e4 = g_Vars.lvframe60;
//			} else if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_20) == 0) {
//				aibot->unk06c = 1;
//				aibot->unk070 = 0;
//			} else {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//				aibot->unk1e4 = g_Vars.lvframe60;
//			}
//		}
//
//		func0f191448(chr);
//
//		result = func0f023098(prop);
//
//		if (g_Vars.lvframe60 >= 145) {
//			if (updateable) {
//				scenarioCallback14(chr);
//			}
//
//			if (updateable && !chrIsDead(chr)) {
//				func0f19124c(chr);
//			}
//		}
//	}
//
//	return result;
//}

f32 aibotCalculateMaxSpeed(struct chrdata *chr)
{
	f32 speed;

	if (chr->aibot->unk09c_01 || chr->aibot->unk09c_00) {
		speed = -63.600006103516f;
	} else {
		speed = g_HeadsAndBodies[chr->bodynum].height * (1.0f / 159.0f);
	}

	speed = speed * 0.002830188954249f + 1.0f;

	if (chr->aibot->simulant->base.simtype == SIMTYPE_TURTLE) {
		speed *= 3.5f;
	} else if (chr->aibot->simulant->base.simtype == SIMTYPE_SPEED) {
		speed *= 14.0f;
	} else {
		switch (chr->aibot->simulant->difficulty) {
		case SIMDIFF_MEAT:
			speed *= 5.0f;
			break;
		case SIMDIFF_EASY:
			speed *= 6.2f;
			break;
		default:
		case SIMDIFF_NORMAL:
			speed *= 7.6f;
			break;
		case SIMDIFF_HARD:
			speed *= 9.4f;
			break;
		case SIMDIFF_PERFECT:
			speed *= 11.2f;
			break;
		case SIMDIFF_DARK:
			speed *= 11.2f;
			break;
		}
	}

	if (chrGuessCrouchPos(chr) == CROUCHPOS_SQUAT) {
		speed *= 0.35f;
	} else if (chrGuessCrouchPos(chr) == CROUCHPOS_DUCK) {
		speed *= 0.5f;
	} else if (chr->actiontype == ACT_GOPOS
			&& chr->act_gopos.waypoints[chr->act_gopos.curindex] == NULL
			&& chrGetLateralDistanceToCoord(chr, &chr->act_gopos.endpos) < 200) {
		speed *= 0.5f;
	}

	return speed;
}

#if VERSION >= VERSION_NTSC_1_0
void func0f1921f8(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3)
{
	s32 i;
	f32 sp50;
	f32 cosine;
	f32 sine;
	u32 stack[4];
	f32 sp30[2];
	f32 fVar7;
	f32 fVar8;
	f32 speed;
	f32 tmp;

	if (!chr || !chr->aibot) {
		return;
	}

	if (g_Vars.lvframe60 < 145) {
		move[0] = 0;
		move[1] = 0;
		return;
	}

	fVar7 = chr->aibot->unk070;
	fVar8 = chr->aibot->unk06c;

	speed = aibotCalculateMaxSpeed(chr);

	fVar7 *= speed;
	fVar8 *= speed;

	sp50 = func0f03e578(chr);

	cosine = cosf(sp50);
	sine = sinf(sp50);

	sp30[0] = fVar7 * cosine + fVar8 * sine;
	sp30[1] = -fVar7 * sine + fVar8 * cosine;

	move[0] = 0;
	move[1] = 0;

	tmp = (PAL ? 0.065f : 0.055000007152557f) * arg3 / numupdates;

	for (i = 0; i < numupdates; i++) {
		chr->aibot->unk0b4 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b4 + sp30[0];
		chr->aibot->unk0b8 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b8 + sp30[1];

		move[0] += chr->aibot->unk0b4 * tmp;
		move[1] += chr->aibot->unk0b8 * tmp;
	}
}
#else
GLOBAL_ASM(
glabel func0f1921f8
.late_rodata
glabel var7f1b3510nb
.word 0x3d6147b0
glabel var7f1b3514nb
.word 0x3f71eb85
.text
/*  f18c2dc:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f18c2e0:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f18c2e4:	00808025 */ 	or	$s0,$a0,$zero
/*  f18c2e8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f18c2ec:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f18c2f0:	10800058 */ 	beqz	$a0,.NB0f18c454
/*  f18c2f4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f18c2f8:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f18c2fc:	3c06800a */ 	lui	$a2,0x800a
/*  f18c300:	24c6e6c0 */ 	addiu	$a2,$a2,-6464
/*  f18c304:	50400054 */ 	beqzl	$v0,.NB0f18c458
/*  f18c308:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18c30c:	8cce0008 */ 	lw	$t6,0x8($a2)
/*  f18c310:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c314:	29c10091 */ 	slti	$at,$t6,0x91
/*  f18c318:	50200007 */ 	beqzl	$at,.NB0f18c338
/*  f18c31c:	c4540070 */ 	lwc1	$f20,0x70($v0)
/*  f18c320:	44806000 */ 	mtc1	$zero,$f12
/*  f18c324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c328:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f18c32c:	10000049 */ 	beqz	$zero,.NB0f18c454
/*  f18c330:	e4ac0004 */ 	swc1	$f12,0x4($a1)
/*  f18c334:	c4540070 */ 	lwc1	$f20,0x70($v0)
.NB0f18c338:
/*  f18c338:	c456006c */ 	lwc1	$f22,0x6c($v0)
/*  f18c33c:	0fc63022 */ 	jal	aibotCalculateMaxSpeed
/*  f18c340:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f18c344:	4600a502 */ 	mul.s	$f20,$f20,$f0
/*  f18c348:	02002025 */ 	or	$a0,$s0,$zero
/*  f18c34c:	4600b582 */ 	mul.s	$f22,$f22,$f0
/*  f18c350:	0fc0f75b */ 	jal	func0f03e578
/*  f18c354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18c358:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f18c35c:	0c006d52 */ 	jal	cosf
/*  f18c360:	46000306 */ 	mov.s	$f12,$f0
/*  f18c364:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f18c368:	0c006d55 */ 	jal	sinf
/*  f18c36c:	e7a0004c */ 	swc1	$f0,0x4c($sp)
/*  f18c370:	c7ae004c */ 	lwc1	$f14,0x4c($sp)
/*  f18c374:	4600a287 */ 	neg.s	$f10,$f20
/*  f18c378:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f18c37c:	460ea102 */ 	mul.s	$f4,$f20,$f14
/*  f18c380:	44806000 */ 	mtc1	$zero,$f12
/*  f18c384:	3c06800a */ 	lui	$a2,0x800a
/*  f18c388:	4600b182 */ 	mul.s	$f6,$f22,$f0
/*  f18c38c:	24c6e6c0 */ 	addiu	$a2,$a2,-6464
/*  f18c390:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18c394:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f18c398:	00001825 */ 	or	$v1,$zero,$zero
/*  f18c39c:	460eb482 */ 	mul.s	$f18,$f22,$f14
/*  f18c3a0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f18c3a4:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f18c3a8:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f18c3ac:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f18c3b0:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f18c3b4:	e4ac0004 */ 	swc1	$f12,0x4($a1)
/*  f18c3b8:	8cc20034 */ 	lw	$v0,0x34($a2)
/*  f18c3bc:	c4c8004c */ 	lwc1	$f8,0x4c($a2)
/*  f18c3c0:	c4263510 */ 	lwc1	$f6,0x3510($at)
/*  f18c3c4:	44828000 */ 	mtc1	$v0,$f16
/*  f18c3c8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18c3cc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f18c3d0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f18c3d4:	1840001f */ 	blez	$v0,.NB0f18c454
/*  f18c3d8:	46125083 */ 	div.s	$f2,$f10,$f18
/*  f18c3dc:	c4203514 */ 	lwc1	$f0,0x3514($at)
/*  f18c3e0:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
.NB0f18c3e4:
/*  f18c3e4:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f18c3e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18c3ec:	c44600b4 */ 	lwc1	$f6,0xb4($v0)
/*  f18c3f0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f18c3f4:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f18c3f8:	e45000b4 */ 	swc1	$f16,0xb4($v0)
/*  f18c3fc:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f18c400:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f18c404:	c45200b8 */ 	lwc1	$f18,0xb8($v0)
/*  f18c408:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f18c40c:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f18c410:	e44400b8 */ 	swc1	$f4,0xb8($v0)
/*  f18c414:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f18c418:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f18c41c:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f18c420:	c5f000b4 */ 	lwc1	$f16,0xb4($t7)
/*  f18c424:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f18c428:	46124280 */ 	add.s	$f10,$f8,$f18
/*  f18c42c:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f18c430:	8e1802d4 */ 	lw	$t8,0x2d4($s0)
/*  f18c434:	c70400b8 */ 	lwc1	$f4,0xb8($t8)
/*  f18c438:	46022402 */ 	mul.s	$f16,$f4,$f2
/*  f18c43c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f18c440:	e4a80004 */ 	swc1	$f8,0x4($a1)
/*  f18c444:	8cd90034 */ 	lw	$t9,0x34($a2)
/*  f18c448:	0079082a */ 	slt	$at,$v1,$t9
/*  f18c44c:	5420ffe5 */ 	bnezl	$at,.NB0f18c3e4
/*  f18c450:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
.NB0f18c454:
/*  f18c454:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f18c458:
/*  f18c458:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f18c45c:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f18c460:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f18c464:	03e00008 */ 	jr	$ra
/*  f18c468:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
#endif

char *mpGetBotCommandName(s32 command)
{
	if (command < 0 || command >= NUM_MPBOTCOMMANDS) {
		return langGet(L_MISC_179); // "Normal"
	}

	return langGet(g_MpBotCommands[command]);
}

void mpAibotApplyAttack(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_ATTACK;
	chr->aibot->attackpropnum = prop - g_Vars.props;
	chr->aibot->unk0d8 = 1;
}

void mpAibotApplyFollow(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_FOLLOW;
	chr->aibot->followprotectpropnum = prop - g_Vars.props;
	chr->aibot->unk0d8 = 1;
}

void mpAibotApplyProtect(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_PROTECT;
	chr->aibot->followprotectpropnum = prop - g_Vars.props;
	chr->aibot->unk0d8 = 1;
}

void mpAibotApplyDefend(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3)
{
	chr->aibot->command = AIBOTCMD_DEFEND;
	chr->aibot->defendholdpos.x = pos->x;
	chr->aibot->defendholdpos.y = pos->y;
	chr->aibot->defendholdpos.z = pos->z;
	roomsCopy(room, chr->aibot->rooms);
	chr->aibot->unk098 = arg3;
	chr->aibot->unk0d8 = 1;
}

void mpAibotApplyHold(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3)
{
	chr->aibot->command = AIBOTCMD_HOLD;
	chr->aibot->defendholdpos.x = pos->x;
	chr->aibot->defendholdpos.y = pos->y;
	chr->aibot->defendholdpos.z = pos->z;
	roomsCopy(room, chr->aibot->rooms);
	chr->aibot->unk098 = arg3;
	chr->aibot->unk0d8 = 1;
}

void mpAibotApplyScenarioCommand(struct chrdata *chr, u32 command)
{
	chr->aibot->command = command;
	chr->aibot->unk0d8 = 1;
}

void aibotLoseGun(struct chrdata *chr, struct prop *attackerprop)
{
	if (chr->aibot->weaponnum >= WEAPON_FALCON2 && chr->aibot->weaponnum != WEAPON_BRIEFCASE2) {
		struct prop *prop = NULL;
		struct defaultobj *obj;

		if (chr->weapons_held[HAND_LEFT]) {
			obj = chr->weapons_held[HAND_LEFT]->obj;

			obj->hidden |= OBJHFLAG_REAPABLE;
			chr->weapons_held[HAND_LEFT] = NULL;
		}

		if (chr->weapons_held[HAND_RIGHT]) {
			prop = chr->weapons_held[HAND_RIGHT];
			weaponSetGunfireVisible(prop, false, -1);
			chr->weapons_held[HAND_RIGHT] = NULL;
		} else {
			s32 modelnum = weaponGetModel(chr->aibot->weaponnum);

			if (modelnum >= 0) {
				prop = weaponCreateForChr(chr, modelnum, chr->aibot->weaponnum, 0x20000000, 0, 0);
			}
		}

		if (prop && prop->obj) {
			obj = prop->obj;
			propobjSetDropped(prop, DROPREASON_1);
			chr->hidden |= CHRHFLAG_00000001;

			if (obj->hidden & OBJHFLAG_AIRBORNE) {
				obj->projectile->unk0b4 = PALDOWN(240);
				obj->projectile->unk108 = attackerprop;
			}
		}

		aibotRemoveInvItem(chr, chr->aibot->weaponnum);

		chr->aibot->loadedammo[0] = 0;
		chr->aibot->loadedammo[1] = 0;

		aibotSwitchToWeapon(chr, WEAPON_UNARMED, FUNC_PRIMARY);
	}
}

void func0f19277c(struct chrdata *chr, s32 propnum)
{
	struct chrdata *chr2 = NULL;
	s32 index;

	if (propnum >= 0) {
		chr2 = (g_Vars.props + propnum)->chr;

		index = mpPlayerGetIndex(chr2);

		chr->aibot->unk128 = chr->aibot->unk16c[index];
		chr->aibot->unk120 = chr->aibot->unk178[index];
	} else {
		chr->aibot->unk128 = 0;
		chr->aibot->unk120 = -1;
	}

	if (chr->aibot->unk120 > chr->aibot->unk124) {
		chr->aibot->unk124 = chr->aibot->unk120;
	}

	if (chr->target != propnum) {
		chr->target = propnum;
		chr->aibot->unk11c = 0;
		chr->aibot->unk1e8 = 0;
		chr->aibot->unk208 = 0;

		if (chr->aibot->unk128 && chr2) {
			chr->aibot->unk2c8 = PALDOWN(120);
		} else {
			chr->aibot->unk2c8 = 0;
		}
	} else {
		if (chr->aibot->unk128) {
			if (g_Vars.lvupdate240 > 0) {
				chr->aibot->unk11c += g_Vars.diffframe60;
			}
		} else {
			if (g_Vars.lvupdate240 > 0) {
				chr->aibot->unk11c -= g_Vars.diffframe60;
			}

			if (chr->aibot->unk11c < 0) {
				chr->aibot->unk11c = 0;
			}
		}
	}

	if (chr->aibot->unk128 && chr2) {
		if ((chr2->hidden & CHRHFLAG_CLOAKED) == 0) {
			chr->aibot->unk2c8 = PALDOWN(120);
		} else {
			if (chr->aibot->unk2c8 > 0) {
				chr->aibot->unk2c8 -= g_Vars.lvupdate240_60;
			}
		}
	} else {
		chr->aibot->unk2c8 = 0;
	}
}

bool func0f19294c(struct chrdata *botchr, struct chrdata *otherchr)
{
	if (otherchr->prop->type == PROPTYPE_PLAYER && !g_Vars.bondvisible) {
		return true;
	}

	if (otherchr->chrflags & CHRCFLAG_HIDDEN) {
		return true;
	}

	if ((otherchr->hidden & CHRHFLAG_CLOAKED)) {
		if (botchr && botchr->aibot
				&& ((botchr->target != -1 && chrGetTargetProp(botchr) == otherchr->prop && botchr->aibot->unk2c8 > 0)
				|| (botchr->aibot->unk09c_03 && func0f04911c(botchr, &otherchr->prop->pos, 0x20)))) {
			return false;
		}

		return true;
	}

	return false;
}

/**
 * Return true if there's ground between the chr and the death barrier.
 *
 * The death barrier is at -30000.
 * It's assumed that no walkable ground exists below -20000.
 */
bool chrHasGround(struct chrdata *chr)
{
	return chr->ground >= -20000;
}

void func0f192a74(struct chrdata *chr)
{
	struct aibot *aibot = chr->aibot;
	s32 diff = aibot->simulant->difficulty;
	s32 i;
	f32 fVar12;
	f32 fVar11;
	f32 tmp;

	aibot->unk1cc -= g_Vars.lvupdate240_60;

	if (aibot->unk1cc <= 0) {
		aibot->unk1d0 = random();
		aibot->unk1cc = PALDOWN(20) + random() % PALDOWN(20);
	}

	if (g_Vars.lvupdate240 > 0) {
		if (aibot->unk128) {
			aibot->unk1d4 += g_Vars.diffframe60;
		} else {
			aibot->unk1d4 -= g_Vars.diffframe60;
		}

		tmp = g_SimDifficulties[diff].unk10 * (aibot->speedtheta * g_Vars.lvupdate240f);

		if (tmp < 0) {
			tmp = -tmp;
		}

		aibot->unk1d4 -= tmp;
	}

	if (aibot->unk1d4 > aibot->unk11c) {
		aibot->unk1d4 = aibot->unk11c;
	}

	if (aibot->unk1d4 < 0) {
		aibot->unk1d4 = 0;
	}

	if (aibot->unk1d4 >= g_SimDifficulties[diff].unk0c) {
		aibot->unk1d4 = g_SimDifficulties[diff].unk0c;
		fVar12 = 0;
		fVar11 = 0;
	} else {
		tmp = (g_SimDifficulties[diff].unk0c - aibot->unk1d4) / g_SimDifficulties[diff].unk0c;
		fVar12 = g_SimDifficulties[diff].unk04 * tmp;
		fVar11 = g_SimDifficulties[diff].unk08 * tmp;
	}

	if (chr->target != -1) {
		struct prop *target = chrGetTargetProp(chr);

		if (target->chr->hidden & CHRHFLAG_CLOAKED) {
			if (fVar11 < g_SimDifficulties[diff].unk14) {
				fVar11 = g_SimDifficulties[diff].unk14;
			}
		}
	}

	if (fVar11 < g_SimDifficulties[diff].unk18) {
		fVar11 = g_SimDifficulties[diff].unk18;
	}

	aibot->unk1c8 = (fVar11 - fVar12) * (aibot->unk1d0 & 0xffff) * 0.000015259021893144f + fVar12;

	if (aibot->unk1d0 & 0x10000) {
		aibot->unk1c8 = -aibot->unk1c8;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		aibot->unk1c4 = aibot->unk1c4 * (PAL ? 0.97f : 0.97500002384186f) + aibot->unk1c8;
	}

	aibot->unk1c0 = aibot->unk1c4 * (PAL ? 0.029999971389771f : 0.024999976158142f);
}

bool func0f192d64(struct chrdata *botchr, struct chrdata *otherchr)
{
	struct aibot *aibot = botchr->aibot;
	bool result = true;

	if (aibot->simulant->base.simtype == SIMTYPE_PEACE) {
		s32 weaponnum = mpchrGetWeaponNum(otherchr);

		if (weaponnum == WEAPON_NONE || weaponnum == WEAPON_UNARMED) {
			result = false;
		}
	}

	return result;
}

bool func0f192dc0(struct chrdata *botchr, struct chrdata *chr)
{
	struct aibot *aibot = botchr->aibot;
	bool result = true;
	s32 otherweaponnum;
	s32 myscore1;
	s32 myscore2;
	s32 theirscore1;
	s32 theirscore2;

	if (aibot->simulant->base.simtype == SIMTYPE_COWARD) {
		otherweaponnum = mpchrGetWeaponNum(chr);

		aibotScoreWeapon(botchr, aibot->weaponnum, FUNC_PRIMARY, 1, false, &myscore1, &myscore2, false, false);
		aibotScoreWeapon(botchr, otherweaponnum, FUNC_PRIMARY, 1, false, &theirscore1, &theirscore2, false, false);

		if (theirscore1 >= myscore1 - 30) {
			result = false;
		}
	}

	return result;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f192e90
/*  f192e90:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f192e94:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f192e98:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f192e9c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f192ea0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f192ea4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f192ea8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f192eac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f192eb0:	8c9302d4 */ 	lw	$s3,0x2d4($a0)
/*  f192eb4:	240effff */ 	addiu	$t6,$zero,-1
/*  f192eb8:	a7ae006a */ 	sh	$t6,0x6a($sp)
/*  f192ebc:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192ec0:	3c19800b */ 	lui	$t9,%hi(g_MpNumPlayers)
/*  f192ec4:	8f39c530 */ 	lw	$t9,%lo(g_MpNumPlayers)($t9)
/*  f192ec8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f192ecc:	0080a825 */ 	or	$s5,$a0,$zero
/*  f192ed0:	0319001a */ 	div	$zero,$t8,$t9
/*  f192ed4:	00002010 */ 	mfhi	$a0
/*  f192ed8:	ae64012c */ 	sw	$a0,0x12c($s3)
/*  f192edc:	17200002 */ 	bnez	$t9,.L0f192ee8
/*  f192ee0:	00000000 */ 	nop
/*  f192ee4:	0007000d */ 	break	0x7
.L0f192ee8:
/*  f192ee8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f192eec:	17210004 */ 	bne	$t9,$at,.L0f192f00
/*  f192ef0:	3c018000 */ 	lui	$at,0x8000
/*  f192ef4:	17010002 */ 	bne	$t8,$at,.L0f192f00
/*  f192ef8:	00000000 */ 	nop
/*  f192efc:	0006000d */ 	break	0x6
.L0f192f00:
/*  f192f00:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f192f04:	00000000 */ 	nop
/*  f192f08:	1055002b */ 	beq	$v0,$s5,.L0f192fb8
/*  f192f0c:	00408825 */ 	or	$s1,$v0,$zero
/*  f192f10:	0c004b70 */ 	jal	random
/*  f192f14:	00000000 */ 	nop
/*  f192f18:	24013840 */ 	addiu	$at,$zero,0x2ee0
/*  f192f1c:	0041001b */ 	divu	$zero,$v0,$at
/*  f192f20:	3c0d800b */ 	lui	$t5,%hi(g_MpNumPlayers)
/*  f192f24:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x38)
/*  f192f28:	8dce9ff8 */ 	lw	$t6,%lo(g_Vars+0x38)($t6)
/*  f192f2c:	8dadc530 */ 	lw	$t5,%lo(g_MpNumPlayers)($t5)
/*  f192f30:	00006010 */ 	mfhi	$t4
/*  f192f34:	00000000 */ 	nop
/*  f192f38:	00000000 */ 	nop
/*  f192f3c:	01ae0019 */ 	multu	$t5,$t6
/*  f192f40:	00007812 */ 	mflo	$t7
/*  f192f44:	018f082b */ 	sltu	$at,$t4,$t7
/*  f192f48:	50200005 */ 	beqzl	$at,.L0f192f60
/*  f192f4c:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f192f50:	9279009c */ 	lbu	$t9,0x9c($s3)
/*  f192f54:	372b0010 */ 	ori	$t3,$t9,0x10
/*  f192f58:	a26b009c */ 	sb	$t3,0x9c($s3)
/*  f192f5c:	8e25001c */ 	lw	$a1,0x1c($s1)
.L0f192f60:
/*  f192f60:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f64:	0fc1250e */ 	jal	chrGetDistanceToCoord
/*  f192f68:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f192f6c:	8e6d012c */ 	lw	$t5,0x12c($s3)
/*  f192f70:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f74:	02202825 */ 	or	$a1,$s1,$zero
/*  f192f78:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f192f7c:	026e6021 */ 	addu	$t4,$s3,$t6
/*  f192f80:	e580013c */ 	swc1	$f0,0x13c($t4)
/*  f192f84:	0fc0e48b */ 	jal	chrCanSeeChr
/*  f192f88:	27a6006a */ 	addiu	$a2,$sp,0x6a
/*  f192f8c:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192f90:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f192f94:	a302016c */ 	sb	$v0,0x16c($t8)
/*  f192f98:	8e6b012c */ 	lw	$t3,0x12c($s3)
/*  f192f9c:	87b9006a */ 	lh	$t9,0x6a($sp)
/*  f192fa0:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f192fa4:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f192fa8:	a5d901a8 */ 	sh	$t9,0x1a8($t6)
/*  f192fac:	926c009c */ 	lbu	$t4,0x9c($s3)
/*  f192fb0:	318fffef */ 	andi	$t7,$t4,0xffef
/*  f192fb4:	a26f009c */ 	sb	$t7,0x9c($s3)
.L0f192fb8:
/*  f192fb8:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f192fbc:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
/*  f192fc0:	00009025 */ 	or	$s2,$zero,$zero
/*  f192fc4:	02608025 */ 	or	$s0,$s3,$zero
/*  f192fc8:	18e00010 */ 	blez	$a3,.L0f19300c
/*  f192fcc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f192fd0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L0f192fd4:
/*  f192fd4:	9218016c */ 	lbu	$t8,0x16c($s0)
/*  f192fd8:	00126880 */ 	sll	$t5,$s2,0x2
/*  f192fdc:	53000007 */ 	beqzl	$t8,.L0f192ffc
/*  f192fe0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f192fe4:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*  f192fe8:	026dc821 */ 	addu	$t9,$s3,$t5
/*  f192fec:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f192ff0:	af2b0178 */ 	sw	$t3,0x178($t9)
/*  f192ff4:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
/*  f192ff8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f192ffc:
/*  f192ffc:	0247082a */ 	slt	$at,$s2,$a3
/*  f193000:	1420fff4 */ 	bnez	$at,.L0f192fd4
/*  f193004:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f193008:	00009025 */ 	or	$s2,$zero,$zero
.L0f19300c:
/*  f19300c:	18e00008 */ 	blez	$a3,.L0f193030
/*  f193010:	27a2006c */ 	addiu	$v0,$sp,0x6c
/*  f193014:	00076080 */ 	sll	$t4,$a3,0x2
/*  f193018:	01821821 */ 	addu	$v1,$t4,$v0
.L0f19301c:
/*  f19301c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f193020:	0043082b */ 	sltu	$at,$v0,$v1
/*  f193024:	1420fffd */ 	bnez	$at,.L0f19301c
/*  f193028:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f19302c:	00009025 */ 	or	$s2,$zero,$zero
.L0f193030:
/*  f193030:	18e00026 */ 	blez	$a3,.L0f1930cc
/*  f193034:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f193038:	44801000 */ 	mtc1	$zero,$f2
/*  f19303c:	27a8006c */ 	addiu	$t0,$sp,0x6c
/*  f193040:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f193044:
/*  f193044:	46001006 */ 	mov.s	$f0,$f2
/*  f193048:	18e00014 */ 	blez	$a3,.L0f19309c
/*  f19304c:	00001825 */ 	or	$v1,$zero,$zero
/*  f193050:	00002025 */ 	or	$a0,$zero,$zero
/*  f193054:	27a5006c */ 	addiu	$a1,$sp,0x6c
.L0f193058:
/*  f193058:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f19305c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f193060:	55e0000b */ 	bnezl	$t7,.L0f193090
/*  f193064:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f193068:	04c00006 */ 	bltz	$a2,.L0f193084
/*  f19306c:	02641021 */ 	addu	$v0,$s3,$a0
/*  f193070:	c444013c */ 	lwc1	$f4,0x13c($v0)
/*  f193074:	4600203c */ 	c.lt.s	$f4,$f0
/*  f193078:	00000000 */ 	nop
/*  f19307c:	45020004 */ 	bc1fl	.L0f193090
/*  f193080:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193084:
/*  f193084:	00603025 */ 	or	$a2,$v1,$zero
/*  f193088:	c440013c */ 	lwc1	$f0,0x13c($v0)
/*  f19308c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193090:
/*  f193090:	0067082a */ 	slt	$at,$v1,$a3
/*  f193094:	1420fff0 */ 	bnez	$at,.L0f193058
/*  f193098:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f19309c:
/*  f19309c:	04c00007 */ 	bltz	$a2,.L0f1930bc
/*  f1930a0:	0272c021 */ 	addu	$t8,$s3,$s2
/*  f1930a4:	00066880 */ 	sll	$t5,$a2,0x2
/*  f1930a8:	a3060130 */ 	sb	$a2,0x130($t8)
/*  f1930ac:	010d5821 */ 	addu	$t3,$t0,$t5
/*  f1930b0:	ad690000 */ 	sw	$t1,0x0($t3)
/*  f1930b4:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f1930b8:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
.L0f1930bc:
/*  f1930bc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1930c0:	0247082a */ 	slt	$at,$s2,$a3
/*  f1930c4:	5420ffdf */ 	bnezl	$at,.L0f193044
/*  f1930c8:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f1930cc:
/*  f1930cc:	0fc64a9d */ 	jal	func0f192a74
/*  f1930d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930d4:	92a202a0 */ 	lbu	$v0,0x2a0($s5)
/*  f1930d8:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1930dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930e0:	54410006 */ 	bnel	$v0,$at,.L0f1930fc
/*  f1930e4:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1930e8:	0fc649df */ 	jal	func0f19277c
/*  f1930ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1930f0:	100000f2 */ 	b	.L0f1934bc
/*  f1930f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1930f8:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f1930fc:
/*  f1930fc:	5441001f */ 	bnel	$v0,$at,.L0f19317c
/*  f193100:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193104:	86620008 */ 	lh	$v0,0x8($s3)
/*  f193108:	0440001b */ 	bltz	$v0,.L0f193178
/*  f19310c:	0262c821 */ 	addu	$t9,$s3,$v0
/*  f193110:	932c016c */ 	lbu	$t4,0x16c($t9)
/*  f193114:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f193118:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f19311c:	11800016 */ 	beqz	$t4,.L0f193178
/*  f193120:	00027080 */ 	sll	$t6,$v0,0x2
/*  f193124:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f193128:	0fc0e6a5 */ 	jal	chrIsDead
/*  f19312c:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f193130:	54400012 */ 	bnezl	$v0,.L0f19317c
/*  f193134:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193138:	86780008 */ 	lh	$t8,0x8($s3)
/*  f19313c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x338)
/*  f193140:	8dcea2f8 */ 	lw	$t6,%lo(g_Vars+0x338)($t6)
/*  f193144:	00186880 */ 	sll	$t5,$t8,0x2
/*  f193148:	020d5821 */ 	addu	$t3,$s0,$t5
/*  f19314c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f193150:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193154:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193158:	8f2c001c */ 	lw	$t4,0x1c($t9)
/*  f19315c:	018e2823 */ 	subu	$a1,$t4,$t6
/*  f193160:	00a1001a */ 	div	$zero,$a1,$at
/*  f193164:	00002812 */ 	mflo	$a1
/*  f193168:	0fc649df */ 	jal	func0f19277c
/*  f19316c:	00000000 */ 	nop
/*  f193170:	100000d2 */ 	b	.L0f1934bc
/*  f193174:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193178:
/*  f193178:	86b8017e */ 	lh	$t8,0x17e($s5)
.L0f19317c:
/*  f19317c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f193180:	52380028 */ 	beql	$s1,$t8,.L0f193224
/*  f193184:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f193188:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19318c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193190:	00408025 */ 	or	$s0,$v0,$zero
/*  f193194:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193198:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19319c:	10400002 */ 	beqz	$v0,.L0f1931a8
/*  f1931a0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931a4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931a8:
/*  f1931a8:	8ead02d4 */ 	lw	$t5,0x2d4($s5)
/*  f1931ac:	8dab0128 */ 	lw	$t3,0x128($t5)
/*  f1931b0:	55600007 */ 	bnezl	$t3,.L0f1931d0
/*  f1931b4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931b8:	0fc64a53 */ 	jal	func0f19294c
/*  f1931bc:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931c0:	50400003 */ 	beqzl	$v0,.L0f1931d0
/*  f1931c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931c8:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f1931cc:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1931d0:
/*  f1931d0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931d4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f1931d8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1931dc:	10400002 */ 	beqz	$v0,.L0f1931e8
/*  f1931e0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931e4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931e8:
/*  f1931e8:	0fc64b59 */ 	jal	func0f192d64
/*  f1931ec:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931f0:	14400002 */ 	bnez	$v0,.L0f1931fc
/*  f1931f4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931f8:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931fc:
/*  f1931fc:	8eb902d4 */ 	lw	$t9,0x2d4($s5)
/*  f193200:	8f2c0128 */ 	lw	$t4,0x128($t9)
/*  f193204:	55800007 */ 	bnezl	$t4,.L0f193224
/*  f193208:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19320c:	0fc64b70 */ 	jal	func0f192dc0
/*  f193210:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f193214:	54400003 */ 	bnezl	$v0,.L0f193224
/*  f193218:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19321c:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f193220:	86a2017e */ 	lh	$v0,0x17e($s5)
.L0f193224:
/*  f193224:	3c0f800b */ 	lui	$t7,%hi(g_MpNumPlayers)
/*  f193228:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x338)
/*  f19322c:	16220062 */ 	bne	$s1,$v0,.L0f1933b8
/*  f193230:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f193234:	8defc530 */ 	lw	$t7,%lo(g_MpNumPlayers)($t7)
/*  f193238:	240effff */ 	addiu	$t6,$zero,-1
/*  f19323c:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f193240:	19e00047 */ 	blez	$t7,.L0f193360
/*  f193244:	00009025 */ 	or	$s2,$zero,$zero
/*  f193248:	0260a025 */ 	or	$s4,$s3,$zero
/*  f19324c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193250:
/*  f193250:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193254:	02002025 */ 	or	$a0,$s0,$zero
/*  f193258:	1055003a */ 	beq	$v0,$s5,.L0f193344
/*  f19325c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193260:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193264:	00402025 */ 	or	$a0,$v0,$zero
/*  f193268:	14400036 */ 	bnez	$v0,.L0f193344
/*  f19326c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193270:	02202825 */ 	or	$a1,$s1,$zero
/*  f193274:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193278:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19327c:	10400031 */ 	beqz	$v0,.L0f193344
/*  f193280:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193284:	0fc64b59 */ 	jal	func0f192d64
/*  f193288:	02202825 */ 	or	$a1,$s1,$zero
/*  f19328c:	1040002d */ 	beqz	$v0,.L0f193344
/*  f193290:	0270c021 */ 	addu	$t8,$s3,$s0
/*  f193294:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193298:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19329c:	11a0000c */ 	beqz	$t5,.L0f1932d0
/*  f1932a0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x338)
/*  f1932a4:	8f39a2f8 */ 	lw	$t9,%lo(g_Vars+0x338)($t9)
/*  f1932a8:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f1932ac:	24010048 */ 	addiu	$at,$zero,0x48
/*  f1932b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932b4:	01792823 */ 	subu	$a1,$t3,$t9
/*  f1932b8:	00a1001a */ 	div	$zero,$a1,$at
/*  f1932bc:	00002812 */ 	mflo	$a1
/*  f1932c0:	0fc649df */ 	jal	func0f19277c
/*  f1932c4:	00000000 */ 	nop
/*  f1932c8:	1000007c */ 	b	.L0f1934bc
/*  f1932cc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1932d0:
/*  f1932d0:	0fc64a53 */ 	jal	func0f19294c
/*  f1932d4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1932d8:	14400013 */ 	bnez	$v0,.L0f193328
/*  f1932dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932e0:	8e6e0004 */ 	lw	$t6,0x4($s3)
/*  f1932e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1932e8:	91c20048 */ 	lbu	$v0,0x48($t6)
/*  f1932ec:	10400002 */ 	beqz	$v0,.L0f1932f8
/*  f1932f0:	00000000 */ 	nop
/*  f1932f4:	1441000c */ 	bne	$v0,$at,.L0f193328
.L0f1932f8:
/*  f1932f8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x338)
/*  f1932fc:	8f18a2f8 */ 	lw	$t8,%lo(g_Vars+0x338)($t8)
/*  f193300:	8e2f001c */ 	lw	$t7,0x1c($s1)
/*  f193304:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193308:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19330c:	01f82823 */ 	subu	$a1,$t7,$t8
/*  f193310:	00a1001a */ 	div	$zero,$a1,$at
/*  f193314:	00002812 */ 	mflo	$a1
/*  f193318:	0fc649df */ 	jal	func0f19277c
/*  f19331c:	00000000 */ 	nop
/*  f193320:	10000066 */ 	b	.L0f1934bc
/*  f193324:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193328:
/*  f193328:	0fc64a53 */ 	jal	func0f19294c
/*  f19332c:	02202825 */ 	or	$a1,$s1,$zero
/*  f193330:	14400004 */ 	bnez	$v0,.L0f193344
/*  f193334:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f193338:	05610002 */ 	bgez	$t3,.L0f193344
/*  f19333c:	00000000 */ 	nop
/*  f193340:	afb00050 */ 	sw	$s0,0x50($sp)
.L0f193344:
/*  f193344:	3c19800b */ 	lui	$t9,%hi(g_MpNumPlayers)
/*  f193348:	8f39c530 */ 	lw	$t9,%lo(g_MpNumPlayers)($t9)
/*  f19334c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f193350:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193354:	0259082a */ 	slt	$at,$s2,$t9
/*  f193358:	5420ffbd */ 	bnezl	$at,.L0f193250
/*  f19335c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193360:
/*  f193360:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f193364:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193368:	0580000f */ 	bltz	$t4,.L0f1933a8
/*  f19336c:	00000000 */ 	nop
/*  f193370:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193374:	01802025 */ 	or	$a0,$t4,$zero
/*  f193378:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x338)
/*  f19337c:	8defa2f8 */ 	lw	$t7,%lo(g_Vars+0x338)($t7)
/*  f193380:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f193384:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193388:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19338c:	01cf2823 */ 	subu	$a1,$t6,$t7
/*  f193390:	00a1001a */ 	div	$zero,$a1,$at
/*  f193394:	00002812 */ 	mflo	$a1
/*  f193398:	0fc649df */ 	jal	func0f19277c
/*  f19339c:	00000000 */ 	nop
/*  f1933a0:	10000046 */ 	b	.L0f1934bc
/*  f1933a4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933a8:
/*  f1933a8:	0fc649df */ 	jal	func0f19277c
/*  f1933ac:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1933b0:	10000042 */ 	b	.L0f1934bc
/*  f1933b4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933b8:
/*  f1933b8:	8d6ba2f8 */ 	lw	$t3,%lo(g_Vars+0x338)($t3)
/*  f1933bc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f1933c0:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1933c4:	01abc821 */ 	addu	$t9,$t5,$t3
/*  f1933c8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1933cc:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f1933d0:	02626021 */ 	addu	$t4,$s3,$v0
/*  f1933d4:	918e016c */ 	lbu	$t6,0x16c($t4)
/*  f1933d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1933dc:	3c0f800b */ 	lui	$t7,%hi(g_MpNumPlayers)
/*  f1933e0:	11c00005 */ 	beqz	$t6,.L0f1933f8
/*  f1933e4:	00000000 */ 	nop
/*  f1933e8:	0fc649df */ 	jal	func0f19277c
/*  f1933ec:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1933f0:	10000032 */ 	b	.L0f1934bc
/*  f1933f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933f8:
/*  f1933f8:	8defc530 */ 	lw	$t7,%lo(g_MpNumPlayers)($t7)
/*  f1933fc:	00009025 */ 	or	$s2,$zero,$zero
/*  f193400:	02608025 */ 	or	$s0,$s3,$zero
/*  f193404:	59e0002a */ 	blezl	$t7,.L0f1934b0
/*  f193408:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19340c:	82040130 */ 	lb	$a0,0x130($s0)
.L0f193410:
/*  f193410:	0264c021 */ 	addu	$t8,$s3,$a0
/*  f193414:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193418:	11a0001d */ 	beqz	$t5,.L0f193490
/*  f19341c:	00000000 */ 	nop
/*  f193420:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193424:	00000000 */ 	nop
/*  f193428:	10550019 */ 	beq	$v0,$s5,.L0f193490
/*  f19342c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193430:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193434:	00402025 */ 	or	$a0,$v0,$zero
/*  f193438:	14400015 */ 	bnez	$v0,.L0f193490
/*  f19343c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193440:	02202825 */ 	or	$a1,$s1,$zero
/*  f193444:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193448:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19344c:	10400010 */ 	beqz	$v0,.L0f193490
/*  f193450:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193454:	0fc64b59 */ 	jal	func0f192d64
/*  f193458:	02202825 */ 	or	$a1,$s1,$zero
/*  f19345c:	1040000c */ 	beqz	$v0,.L0f193490
/*  f193460:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x338)
/*  f193464:	8f39a2f8 */ 	lw	$t9,%lo(g_Vars+0x338)($t9)
/*  f193468:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f19346c:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193470:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193474:	01792823 */ 	subu	$a1,$t3,$t9
/*  f193478:	00a1001a */ 	div	$zero,$a1,$at
/*  f19347c:	00002812 */ 	mflo	$a1
/*  f193480:	0fc649df */ 	jal	func0f19277c
/*  f193484:	00000000 */ 	nop
/*  f193488:	1000000c */ 	b	.L0f1934bc
/*  f19348c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193490:
/*  f193490:	3c0e800b */ 	lui	$t6,%hi(g_MpNumPlayers)
/*  f193494:	8dcec530 */ 	lw	$t6,%lo(g_MpNumPlayers)($t6)
/*  f193498:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19349c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1934a0:	024e082a */ 	slt	$at,$s2,$t6
/*  f1934a4:	5420ffda */ 	bnezl	$at,.L0f193410
/*  f1934a8:	82040130 */ 	lb	$a0,0x130($s0)
/*  f1934ac:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1934b0:
/*  f1934b0:	0fc649df */ 	jal	func0f19277c
/*  f1934b4:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1934b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1934bc:
/*  f1934bc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1934c0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1934c4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1934c8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1934cc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f1934d0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f1934d4:	03e00008 */ 	jr	$ra
/*  f1934d8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#else
GLOBAL_ASM(
glabel func0f192e90
/*  f192e90:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f192e94:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f192e98:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f192e9c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f192ea0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f192ea4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f192ea8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f192eac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f192eb0:	8c9302d4 */ 	lw	$s3,0x2d4($a0)
/*  f192eb4:	240effff */ 	addiu	$t6,$zero,-1
/*  f192eb8:	a7ae006a */ 	sh	$t6,0x6a($sp)
/*  f192ebc:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192ec0:	3c19800b */ 	lui	$t9,%hi(g_MpNumPlayers)
/*  f192ec4:	8f39c530 */ 	lw	$t9,%lo(g_MpNumPlayers)($t9)
/*  f192ec8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f192ecc:	0080a825 */ 	or	$s5,$a0,$zero
/*  f192ed0:	0319001a */ 	div	$zero,$t8,$t9
/*  f192ed4:	00002010 */ 	mfhi	$a0
/*  f192ed8:	ae64012c */ 	sw	$a0,0x12c($s3)
/*  f192edc:	17200002 */ 	bnez	$t9,.L0f192ee8
/*  f192ee0:	00000000 */ 	nop
/*  f192ee4:	0007000d */ 	break	0x7
.L0f192ee8:
/*  f192ee8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f192eec:	17210004 */ 	bne	$t9,$at,.L0f192f00
/*  f192ef0:	3c018000 */ 	lui	$at,0x8000
/*  f192ef4:	17010002 */ 	bne	$t8,$at,.L0f192f00
/*  f192ef8:	00000000 */ 	nop
/*  f192efc:	0006000d */ 	break	0x6
.L0f192f00:
/*  f192f00:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f192f04:	00000000 */ 	nop
/*  f192f08:	1055002b */ 	beq	$v0,$s5,.L0f192fb8
/*  f192f0c:	00408825 */ 	or	$s1,$v0,$zero
/*  f192f10:	0c004b70 */ 	jal	random
/*  f192f14:	00000000 */ 	nop
/*  f192f18:	24013840 */ 	addiu	$at,$zero,0x3840
/*  f192f1c:	0041001b */ 	divu	$zero,$v0,$at
/*  f192f20:	3c0d800b */ 	lui	$t5,%hi(g_MpNumPlayers)
/*  f192f24:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x38)
/*  f192f28:	8dce9ff8 */ 	lw	$t6,%lo(g_Vars+0x38)($t6)
/*  f192f2c:	8dadc530 */ 	lw	$t5,%lo(g_MpNumPlayers)($t5)
/*  f192f30:	00006010 */ 	mfhi	$t4
/*  f192f34:	00000000 */ 	nop
/*  f192f38:	00000000 */ 	nop
/*  f192f3c:	01ae0019 */ 	multu	$t5,$t6
/*  f192f40:	00007812 */ 	mflo	$t7
/*  f192f44:	018f082b */ 	sltu	$at,$t4,$t7
/*  f192f48:	50200005 */ 	beqzl	$at,.L0f192f60
/*  f192f4c:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f192f50:	9279009c */ 	lbu	$t9,0x9c($s3)
/*  f192f54:	372b0010 */ 	ori	$t3,$t9,0x10
/*  f192f58:	a26b009c */ 	sb	$t3,0x9c($s3)
/*  f192f5c:	8e25001c */ 	lw	$a1,0x1c($s1)
.L0f192f60:
/*  f192f60:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f64:	0fc1250e */ 	jal	chrGetDistanceToCoord
/*  f192f68:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f192f6c:	8e6d012c */ 	lw	$t5,0x12c($s3)
/*  f192f70:	02a02025 */ 	or	$a0,$s5,$zero
/*  f192f74:	02202825 */ 	or	$a1,$s1,$zero
/*  f192f78:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f192f7c:	026e6021 */ 	addu	$t4,$s3,$t6
/*  f192f80:	e580013c */ 	swc1	$f0,0x13c($t4)
/*  f192f84:	0fc0e48b */ 	jal	chrCanSeeChr
/*  f192f88:	27a6006a */ 	addiu	$a2,$sp,0x6a
/*  f192f8c:	8e6f012c */ 	lw	$t7,0x12c($s3)
/*  f192f90:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f192f94:	a302016c */ 	sb	$v0,0x16c($t8)
/*  f192f98:	8e6b012c */ 	lw	$t3,0x12c($s3)
/*  f192f9c:	87b9006a */ 	lh	$t9,0x6a($sp)
/*  f192fa0:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f192fa4:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f192fa8:	a5d901a8 */ 	sh	$t9,0x1a8($t6)
/*  f192fac:	926c009c */ 	lbu	$t4,0x9c($s3)
/*  f192fb0:	318fffef */ 	andi	$t7,$t4,0xffef
/*  f192fb4:	a26f009c */ 	sb	$t7,0x9c($s3)
.L0f192fb8:
/*  f192fb8:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f192fbc:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
/*  f192fc0:	00009025 */ 	or	$s2,$zero,$zero
/*  f192fc4:	02608025 */ 	or	$s0,$s3,$zero
/*  f192fc8:	18e00010 */ 	blez	$a3,.L0f19300c
/*  f192fcc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f192fd0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L0f192fd4:
/*  f192fd4:	9218016c */ 	lbu	$t8,0x16c($s0)
/*  f192fd8:	00126880 */ 	sll	$t5,$s2,0x2
/*  f192fdc:	53000007 */ 	beqzl	$t8,.L0f192ffc
/*  f192fe0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f192fe4:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*  f192fe8:	026dc821 */ 	addu	$t9,$s3,$t5
/*  f192fec:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f192ff0:	af2b0178 */ 	sw	$t3,0x178($t9)
/*  f192ff4:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
/*  f192ff8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f192ffc:
/*  f192ffc:	0247082a */ 	slt	$at,$s2,$a3
/*  f193000:	1420fff4 */ 	bnez	$at,.L0f192fd4
/*  f193004:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f193008:	00009025 */ 	or	$s2,$zero,$zero
.L0f19300c:
/*  f19300c:	18e00008 */ 	blez	$a3,.L0f193030
/*  f193010:	27a2006c */ 	addiu	$v0,$sp,0x6c
/*  f193014:	00076080 */ 	sll	$t4,$a3,0x2
/*  f193018:	01821821 */ 	addu	$v1,$t4,$v0
.L0f19301c:
/*  f19301c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f193020:	0043082b */ 	sltu	$at,$v0,$v1
/*  f193024:	1420fffd */ 	bnez	$at,.L0f19301c
/*  f193028:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f19302c:	00009025 */ 	or	$s2,$zero,$zero
.L0f193030:
/*  f193030:	18e00026 */ 	blez	$a3,.L0f1930cc
/*  f193034:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f193038:	44801000 */ 	mtc1	$zero,$f2
/*  f19303c:	27a8006c */ 	addiu	$t0,$sp,0x6c
/*  f193040:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f193044:
/*  f193044:	46001006 */ 	mov.s	$f0,$f2
/*  f193048:	18e00014 */ 	blez	$a3,.L0f19309c
/*  f19304c:	00001825 */ 	or	$v1,$zero,$zero
/*  f193050:	00002025 */ 	or	$a0,$zero,$zero
/*  f193054:	27a5006c */ 	addiu	$a1,$sp,0x6c
.L0f193058:
/*  f193058:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f19305c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f193060:	55e0000b */ 	bnezl	$t7,.L0f193090
/*  f193064:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f193068:	04c00006 */ 	bltz	$a2,.L0f193084
/*  f19306c:	02641021 */ 	addu	$v0,$s3,$a0
/*  f193070:	c444013c */ 	lwc1	$f4,0x13c($v0)
/*  f193074:	4600203c */ 	c.lt.s	$f4,$f0
/*  f193078:	00000000 */ 	nop
/*  f19307c:	45020004 */ 	bc1fl	.L0f193090
/*  f193080:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193084:
/*  f193084:	00603025 */ 	or	$a2,$v1,$zero
/*  f193088:	c440013c */ 	lwc1	$f0,0x13c($v0)
/*  f19308c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f193090:
/*  f193090:	0067082a */ 	slt	$at,$v1,$a3
/*  f193094:	1420fff0 */ 	bnez	$at,.L0f193058
/*  f193098:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f19309c:
/*  f19309c:	04c00007 */ 	bltz	$a2,.L0f1930bc
/*  f1930a0:	0272c021 */ 	addu	$t8,$s3,$s2
/*  f1930a4:	00066880 */ 	sll	$t5,$a2,0x2
/*  f1930a8:	a3060130 */ 	sb	$a2,0x130($t8)
/*  f1930ac:	010d5821 */ 	addu	$t3,$t0,$t5
/*  f1930b0:	ad690000 */ 	sw	$t1,0x0($t3)
/*  f1930b4:	3c07800b */ 	lui	$a3,%hi(g_MpNumPlayers)
/*  f1930b8:	8ce7c530 */ 	lw	$a3,%lo(g_MpNumPlayers)($a3)
.L0f1930bc:
/*  f1930bc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1930c0:	0247082a */ 	slt	$at,$s2,$a3
/*  f1930c4:	5420ffdf */ 	bnezl	$at,.L0f193044
/*  f1930c8:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f1930cc:
/*  f1930cc:	0fc64a9d */ 	jal	func0f192a74
/*  f1930d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930d4:	92a202a0 */ 	lbu	$v0,0x2a0($s5)
/*  f1930d8:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1930dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1930e0:	54410006 */ 	bnel	$v0,$at,.L0f1930fc
/*  f1930e4:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1930e8:	0fc649df */ 	jal	func0f19277c
/*  f1930ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1930f0:	100000f2 */ 	b	.L0f1934bc
/*  f1930f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1930f8:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f1930fc:
/*  f1930fc:	5441001f */ 	bnel	$v0,$at,.L0f19317c
/*  f193100:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193104:	86620008 */ 	lh	$v0,0x8($s3)
/*  f193108:	0440001b */ 	bltz	$v0,.L0f193178
/*  f19310c:	0262c821 */ 	addu	$t9,$s3,$v0
/*  f193110:	932c016c */ 	lbu	$t4,0x16c($t9)
/*  f193114:	3c10800b */ 	lui	$s0,%hi(g_MpPlayerChrs)
/*  f193118:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpPlayerChrs)
/*  f19311c:	11800016 */ 	beqz	$t4,.L0f193178
/*  f193120:	00027080 */ 	sll	$t6,$v0,0x2
/*  f193124:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f193128:	0fc0e6a5 */ 	jal	chrIsDead
/*  f19312c:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f193130:	54400012 */ 	bnezl	$v0,.L0f19317c
/*  f193134:	86b8017e */ 	lh	$t8,0x17e($s5)
/*  f193138:	86780008 */ 	lh	$t8,0x8($s3)
/*  f19313c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x338)
/*  f193140:	8dcea2f8 */ 	lw	$t6,%lo(g_Vars+0x338)($t6)
/*  f193144:	00186880 */ 	sll	$t5,$t8,0x2
/*  f193148:	020d5821 */ 	addu	$t3,$s0,$t5
/*  f19314c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f193150:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193154:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193158:	8f2c001c */ 	lw	$t4,0x1c($t9)
/*  f19315c:	018e2823 */ 	subu	$a1,$t4,$t6
/*  f193160:	00a1001a */ 	div	$zero,$a1,$at
/*  f193164:	00002812 */ 	mflo	$a1
/*  f193168:	0fc649df */ 	jal	func0f19277c
/*  f19316c:	00000000 */ 	nop
/*  f193170:	100000d2 */ 	b	.L0f1934bc
/*  f193174:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193178:
/*  f193178:	86b8017e */ 	lh	$t8,0x17e($s5)
.L0f19317c:
/*  f19317c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f193180:	52380028 */ 	beql	$s1,$t8,.L0f193224
/*  f193184:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f193188:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19318c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193190:	00408025 */ 	or	$s0,$v0,$zero
/*  f193194:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193198:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19319c:	10400002 */ 	beqz	$v0,.L0f1931a8
/*  f1931a0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931a4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931a8:
/*  f1931a8:	8ead02d4 */ 	lw	$t5,0x2d4($s5)
/*  f1931ac:	8dab0128 */ 	lw	$t3,0x128($t5)
/*  f1931b0:	55600007 */ 	bnezl	$t3,.L0f1931d0
/*  f1931b4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931b8:	0fc64a53 */ 	jal	func0f19294c
/*  f1931bc:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931c0:	50400003 */ 	beqzl	$v0,.L0f1931d0
/*  f1931c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931c8:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f1931cc:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1931d0:
/*  f1931d0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931d4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f1931d8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1931dc:	10400002 */ 	beqz	$v0,.L0f1931e8
/*  f1931e0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931e4:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931e8:
/*  f1931e8:	0fc64b59 */ 	jal	func0f192d64
/*  f1931ec:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1931f0:	14400002 */ 	bnez	$v0,.L0f1931fc
/*  f1931f4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1931f8:	a6b1017e */ 	sh	$s1,0x17e($s5)
.L0f1931fc:
/*  f1931fc:	8eb902d4 */ 	lw	$t9,0x2d4($s5)
/*  f193200:	8f2c0128 */ 	lw	$t4,0x128($t9)
/*  f193204:	55800007 */ 	bnezl	$t4,.L0f193224
/*  f193208:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19320c:	0fc64b70 */ 	jal	func0f192dc0
/*  f193210:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f193214:	54400003 */ 	bnezl	$v0,.L0f193224
/*  f193218:	86a2017e */ 	lh	$v0,0x17e($s5)
/*  f19321c:	a6b1017e */ 	sh	$s1,0x17e($s5)
/*  f193220:	86a2017e */ 	lh	$v0,0x17e($s5)
.L0f193224:
/*  f193224:	3c0f800b */ 	lui	$t7,%hi(g_MpNumPlayers)
/*  f193228:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x338)
/*  f19322c:	16220062 */ 	bne	$s1,$v0,.L0f1933b8
/*  f193230:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f193234:	8defc530 */ 	lw	$t7,%lo(g_MpNumPlayers)($t7)
/*  f193238:	240effff */ 	addiu	$t6,$zero,-1
/*  f19323c:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f193240:	19e00047 */ 	blez	$t7,.L0f193360
/*  f193244:	00009025 */ 	or	$s2,$zero,$zero
/*  f193248:	0260a025 */ 	or	$s4,$s3,$zero
/*  f19324c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193250:
/*  f193250:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193254:	02002025 */ 	or	$a0,$s0,$zero
/*  f193258:	1055003a */ 	beq	$v0,$s5,.L0f193344
/*  f19325c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193260:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193264:	00402025 */ 	or	$a0,$v0,$zero
/*  f193268:	14400036 */ 	bnez	$v0,.L0f193344
/*  f19326c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193270:	02202825 */ 	or	$a1,$s1,$zero
/*  f193274:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193278:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19327c:	10400031 */ 	beqz	$v0,.L0f193344
/*  f193280:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193284:	0fc64b59 */ 	jal	func0f192d64
/*  f193288:	02202825 */ 	or	$a1,$s1,$zero
/*  f19328c:	1040002d */ 	beqz	$v0,.L0f193344
/*  f193290:	0270c021 */ 	addu	$t8,$s3,$s0
/*  f193294:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193298:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19329c:	11a0000c */ 	beqz	$t5,.L0f1932d0
/*  f1932a0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x338)
/*  f1932a4:	8f39a2f8 */ 	lw	$t9,%lo(g_Vars+0x338)($t9)
/*  f1932a8:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f1932ac:	24010048 */ 	addiu	$at,$zero,0x48
/*  f1932b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932b4:	01792823 */ 	subu	$a1,$t3,$t9
/*  f1932b8:	00a1001a */ 	div	$zero,$a1,$at
/*  f1932bc:	00002812 */ 	mflo	$a1
/*  f1932c0:	0fc649df */ 	jal	func0f19277c
/*  f1932c4:	00000000 */ 	nop
/*  f1932c8:	1000007c */ 	b	.L0f1934bc
/*  f1932cc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1932d0:
/*  f1932d0:	0fc64a53 */ 	jal	func0f19294c
/*  f1932d4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1932d8:	14400013 */ 	bnez	$v0,.L0f193328
/*  f1932dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1932e0:	8e6e0004 */ 	lw	$t6,0x4($s3)
/*  f1932e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1932e8:	91c20048 */ 	lbu	$v0,0x48($t6)
/*  f1932ec:	10400002 */ 	beqz	$v0,.L0f1932f8
/*  f1932f0:	00000000 */ 	nop
/*  f1932f4:	1441000c */ 	bne	$v0,$at,.L0f193328
.L0f1932f8:
/*  f1932f8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x338)
/*  f1932fc:	8f18a2f8 */ 	lw	$t8,%lo(g_Vars+0x338)($t8)
/*  f193300:	8e2f001c */ 	lw	$t7,0x1c($s1)
/*  f193304:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193308:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19330c:	01f82823 */ 	subu	$a1,$t7,$t8
/*  f193310:	00a1001a */ 	div	$zero,$a1,$at
/*  f193314:	00002812 */ 	mflo	$a1
/*  f193318:	0fc649df */ 	jal	func0f19277c
/*  f19331c:	00000000 */ 	nop
/*  f193320:	10000066 */ 	b	.L0f1934bc
/*  f193324:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193328:
/*  f193328:	0fc64a53 */ 	jal	func0f19294c
/*  f19332c:	02202825 */ 	or	$a1,$s1,$zero
/*  f193330:	14400004 */ 	bnez	$v0,.L0f193344
/*  f193334:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f193338:	05610002 */ 	bgez	$t3,.L0f193344
/*  f19333c:	00000000 */ 	nop
/*  f193340:	afb00050 */ 	sw	$s0,0x50($sp)
.L0f193344:
/*  f193344:	3c19800b */ 	lui	$t9,%hi(g_MpNumPlayers)
/*  f193348:	8f39c530 */ 	lw	$t9,%lo(g_MpNumPlayers)($t9)
/*  f19334c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f193350:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193354:	0259082a */ 	slt	$at,$s2,$t9
/*  f193358:	5420ffbd */ 	bnezl	$at,.L0f193250
/*  f19335c:	82900130 */ 	lb	$s0,0x130($s4)
.L0f193360:
/*  f193360:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f193364:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193368:	0580000f */ 	bltz	$t4,.L0f1933a8
/*  f19336c:	00000000 */ 	nop
/*  f193370:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193374:	01802025 */ 	or	$a0,$t4,$zero
/*  f193378:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x338)
/*  f19337c:	8defa2f8 */ 	lw	$t7,%lo(g_Vars+0x338)($t7)
/*  f193380:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f193384:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193388:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19338c:	01cf2823 */ 	subu	$a1,$t6,$t7
/*  f193390:	00a1001a */ 	div	$zero,$a1,$at
/*  f193394:	00002812 */ 	mflo	$a1
/*  f193398:	0fc649df */ 	jal	func0f19277c
/*  f19339c:	00000000 */ 	nop
/*  f1933a0:	10000046 */ 	b	.L0f1934bc
/*  f1933a4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933a8:
/*  f1933a8:	0fc649df */ 	jal	func0f19277c
/*  f1933ac:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1933b0:	10000042 */ 	b	.L0f1934bc
/*  f1933b4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933b8:
/*  f1933b8:	8d6ba2f8 */ 	lw	$t3,%lo(g_Vars+0x338)($t3)
/*  f1933bc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f1933c0:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1933c4:	01abc821 */ 	addu	$t9,$t5,$t3
/*  f1933c8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1933cc:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f1933d0:	02626021 */ 	addu	$t4,$s3,$v0
/*  f1933d4:	918e016c */ 	lbu	$t6,0x16c($t4)
/*  f1933d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1933dc:	3c0f800b */ 	lui	$t7,%hi(g_MpNumPlayers)
/*  f1933e0:	11c00005 */ 	beqz	$t6,.L0f1933f8
/*  f1933e4:	00000000 */ 	nop
/*  f1933e8:	0fc649df */ 	jal	func0f19277c
/*  f1933ec:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1933f0:	10000032 */ 	b	.L0f1934bc
/*  f1933f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1933f8:
/*  f1933f8:	8defc530 */ 	lw	$t7,%lo(g_MpNumPlayers)($t7)
/*  f1933fc:	00009025 */ 	or	$s2,$zero,$zero
/*  f193400:	02608025 */ 	or	$s0,$s3,$zero
/*  f193404:	59e0002a */ 	blezl	$t7,.L0f1934b0
/*  f193408:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19340c:	82040130 */ 	lb	$a0,0x130($s0)
.L0f193410:
/*  f193410:	0264c021 */ 	addu	$t8,$s3,$a0
/*  f193414:	930d016c */ 	lbu	$t5,0x16c($t8)
/*  f193418:	11a0001d */ 	beqz	$t5,.L0f193490
/*  f19341c:	00000000 */ 	nop
/*  f193420:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f193424:	00000000 */ 	nop
/*  f193428:	10550019 */ 	beq	$v0,$s5,.L0f193490
/*  f19342c:	00408825 */ 	or	$s1,$v0,$zero
/*  f193430:	0fc0e6a5 */ 	jal	chrIsDead
/*  f193434:	00402025 */ 	or	$a0,$v0,$zero
/*  f193438:	14400015 */ 	bnez	$v0,.L0f193490
/*  f19343c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193440:	02202825 */ 	or	$a1,$s1,$zero
/*  f193444:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f193448:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19344c:	10400010 */ 	beqz	$v0,.L0f193490
/*  f193450:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193454:	0fc64b59 */ 	jal	func0f192d64
/*  f193458:	02202825 */ 	or	$a1,$s1,$zero
/*  f19345c:	1040000c */ 	beqz	$v0,.L0f193490
/*  f193460:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x338)
/*  f193464:	8f39a2f8 */ 	lw	$t9,%lo(g_Vars+0x338)($t9)
/*  f193468:	8e2b001c */ 	lw	$t3,0x1c($s1)
/*  f19346c:	24010048 */ 	addiu	$at,$zero,0x48
/*  f193470:	02a02025 */ 	or	$a0,$s5,$zero
/*  f193474:	01792823 */ 	subu	$a1,$t3,$t9
/*  f193478:	00a1001a */ 	div	$zero,$a1,$at
/*  f19347c:	00002812 */ 	mflo	$a1
/*  f193480:	0fc649df */ 	jal	func0f19277c
/*  f193484:	00000000 */ 	nop
/*  f193488:	1000000c */ 	b	.L0f1934bc
/*  f19348c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f193490:
/*  f193490:	3c0e800b */ 	lui	$t6,%hi(g_MpNumPlayers)
/*  f193494:	8dcec530 */ 	lw	$t6,%lo(g_MpNumPlayers)($t6)
/*  f193498:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19349c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1934a0:	024e082a */ 	slt	$at,$s2,$t6
/*  f1934a4:	5420ffda */ 	bnezl	$at,.L0f193410
/*  f1934a8:	82040130 */ 	lb	$a0,0x130($s0)
/*  f1934ac:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1934b0:
/*  f1934b0:	0fc649df */ 	jal	func0f19277c
/*  f1934b4:	86a5017e */ 	lh	$a1,0x17e($s5)
/*  f1934b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f1934bc:
/*  f1934bc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1934c0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1934c4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1934c8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1934cc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f1934d0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f1934d4:	03e00008 */ 	jr	$ra
/*  f1934d8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#endif

bool mpIsChrFollowedByChr(struct chrdata *leader, struct chrdata *follower)
{
	bool result = true;

	while (true) {
		struct aibot *aibot = follower->aibot;

		if (!aibot || follower->myaction != MA_AIBOTFOLLOW || aibot->followingplayernum < 0) {
			break;
		}

		follower = g_MpPlayerChrs[aibot->followingplayernum];

		if (follower == leader) {
			result = false;
			break;
		}
	}

	return result;
}

s32 func0f193530(struct chrdata *chr, f32 range)
{
	s32 result = -1;

	if ((g_MpSetup.options & MPOPTION_TEAMSENABLED)
			&& chr->myaction != MA_AIBOTFOLLOW
			&& (random() % 100) < chr->aibot->unk000) {
		f32 closestdistance = 0;
		s32 closestplayernum = -1;
		s32 i;

		for (i = 0; i < g_MpNumPlayers; i++) {
			if (chr != g_MpPlayerChrs[i]
					&& !chrIsDead(g_MpPlayerChrs[i])
					&& chr->team == g_MpPlayerChrs[i]->team
					&& mpIsChrFollowedByChr(chr, g_MpPlayerChrs[i])) {
				f32 distance = chr->aibot->playerdistances[i];

				if (closestplayernum < 0 || distance < closestdistance) {
					closestplayernum = i;
					closestdistance = distance;
				}
			}
		}

		if (closestplayernum >= 0 && closestdistance < range) {
			result = closestplayernum;
		}
	}

	return result;
}

void func0f19369c(struct chrdata *chr, s32 arg1)
{
	chr->aibot->unk02c[arg1] = g_AibotWeaponPreferences[chr->aibot->weaponnum].unk0e_00 * (PAL ? 50 : 60);

	if (g_AibotWeaponPreferences[chr->aibot->weaponnum].unk0e_03) {
		s32 capacity = weaponGetClipCapacityByFunction(chr->aibot->weaponnum, chr->aibot->gunfunc);

		chr->aibot->unk02c[arg1] *= capacity - chr->aibot->loadedammo[arg1];
		chr->aibot->unk02c[arg1] /= capacity;
	}
}

GLOBAL_ASM(
glabel func0f1937a4
.late_rodata
glabel var7f1b8f48
.word 0x40fccccd
glabel var7f1b8f4c
.word 0x4101999a
glabel var7f1b8f50
.word 0x40fccccd
.text
/*  f1937a4:	27bdfd88 */ 	addiu	$sp,$sp,-632
/*  f1937a8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1937ac:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f1937b0:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f1937b4:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f1937b8:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1937bc:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1937c0:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f1937c4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1937c8:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1937cc:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1937d0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f1937d4:	afa5027c */ 	sw	$a1,0x27c($sp)
/*  f1937d8:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1937dc:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f1937e0:	afa000c4 */ 	sw	$zero,0xc4($sp)
/*  f1937e4:	afae0274 */ 	sw	$t6,0x274($sp)
/*  f1937e8:	81d9004f */ 	lb	$t9,0x4f($t6)
/*  f1937ec:	0080f025 */ 	or	$s8,$a0,$zero
/*  f1937f0:	07210017 */ 	bgez	$t9,.L0f193850
/*  f1937f4:	3c08800b */ 	lui	$t0,%hi(g_MpSetup+0x10)
/*  f1937f8:	9108cb98 */ 	lbu	$t0,%lo(g_MpSetup+0x10)($t0)
/*  f1937fc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f193800:	55010014 */ 	bnel	$t0,$at,.L0f193854
/*  f193804:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193808:	8c89001c */ 	lw	$t1,0x1c($a0)
/*  f19380c:	3c0b800b */ 	lui	$t3,%hi(g_ScenarioData+0xe)
/*  f193810:	856bc11e */ 	lh	$t3,%lo(g_ScenarioData+0xe)($t3)
/*  f193814:	852a0028 */ 	lh	$t2,0x28($t1)
/*  f193818:	554b000e */ 	bnel	$t2,$t3,.L0f193854
/*  f19381c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193820:	0fc65241 */ 	jal	mpGetNumTeammatesDefendingHill
/*  f193824:	00000000 */ 	nop
/*  f193828:	00408025 */ 	or	$s0,$v0,$zero
/*  f19382c:	0fc65264 */ 	jal	mpGetNumOpponentsInHill
/*  f193830:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193834:	0202082a */ 	slt	$at,$s0,$v0
/*  f193838:	14200005 */ 	bnez	$at,.L0f193850
/*  f19383c:	244c0002 */ 	addiu	$t4,$v0,0x2
/*  f193840:	0190082a */ 	slt	$at,$t4,$s0
/*  f193844:	14200002 */ 	bnez	$at,.L0f193850
/*  f193848:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f19384c:	afad00c4 */ 	sw	$t5,0xc4($sp)
.L0f193850:
/*  f193850:	03c02025 */ 	or	$a0,$s8,$zero
.L0f193854:
/*  f193854:	27a5025c */ 	addiu	$a1,$sp,0x25c
/*  f193858:	27a60244 */ 	addiu	$a2,$sp,0x244
/*  f19385c:	0fc6601a */ 	jal	func0f198068
/*  f193860:	27a7022c */ 	addiu	$a3,$sp,0x22c
/*  f193864:	27b00214 */ 	addiu	$s0,$sp,0x214
/*  f193868:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f19386c:
/*  f19386c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193870:	2a810007 */ 	slti	$at,$s4,0x7
/*  f193874:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f193878:	1420fffc */ 	bnez	$at,.L0f19386c
/*  f19387c:	ae00fffc */ 	sw	$zero,-0x4($s0)
/*  f193880:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193884:	27a20178 */ 	addiu	$v0,$sp,0x178
/*  f193888:	27a301fc */ 	addiu	$v1,$sp,0x1fc
.L0f19388c:
/*  f19388c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f193890:	0043082b */ 	sltu	$at,$v0,$v1
/*  f193894:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193898:	1420fffc */ 	bnez	$at,.L0f19388c
/*  f19389c:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f1938a0:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f1938a4:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f1938a8:	27b000dc */ 	addiu	$s0,$sp,0xdc
/*  f1938ac:	27b100f4 */ 	addiu	$s1,$sp,0xf4
.L0f1938b0:
/*  f1938b0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1938b4:	0fc65f3c */ 	jal	aibotGetInvItem
/*  f1938b8:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1938bc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1938c0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1938c4:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1938c8:	1611fff9 */ 	bne	$s0,$s1,.L0f1938b0
/*  f1938cc:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*  f1938d0:	3c15800a */ 	lui	$s5,%hi(g_Vars+0x33c)
/*  f1938d4:	8eb5a2fc */ 	lw	$s5,%lo(g_Vars+0x33c)($s5)
/*  f1938d8:	27b701fc */ 	addiu	$s7,$sp,0x1fc
/*  f1938dc:	27b20274 */ 	addiu	$s2,$sp,0x274
/*  f1938e0:	52a000db */ 	beqzl	$s5,.L0f193c50
/*  f1938e4:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f1938e8:	8eaf0018 */ 	lw	$t7,0x18($s5)
.L0f1938ec:
/*  f1938ec:	55e000d5 */ 	bnezl	$t7,.L0f193c44
/*  f1938f0:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f1938f4:	86b80002 */ 	lh	$t8,0x2($s5)
/*  f1938f8:	570000d2 */ 	bnezl	$t8,.L0f193c44
/*  f1938fc:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193900:	92a20000 */ 	lbu	$v0,0x0($s5)
/*  f193904:	24010004 */ 	addiu	$at,$zero,0x4
/*  f193908:	5441004f */ 	bnel	$v0,$at,.L0f193a48
/*  f19390c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193910:	8eb10004 */ 	lw	$s1,0x4($s5)
/*  f193914:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193918:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f19391c:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f193920:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f193924:	15000045 */ 	bnez	$t0,.L0f193a3c
/*  f193928:	00000000 */ 	nop
/*  f19392c:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193930:	00001025 */ 	or	$v0,$zero,$zero
/*  f193934:	46000506 */ 	mov.s	$f20,$f0
/*  f193938:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19393c:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193940:	9224005c */ 	lbu	$a0,0x5c($s1)
/*  f193944:	27a20274 */ 	addiu	$v0,$sp,0x274
.L0f193948:
/*  f193948:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19394c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193950:	28a10002 */ 	slti	$at,$a1,0x2
/*  f193954:	1420001b */ 	bnez	$at,.L0f1939c4
/*  f193958:	00000000 */ 	nop
/*  f19395c:	14850019 */ 	bne	$a0,$a1,.L0f1939c4
/*  f193960:	00000000 */ 	nop
/*  f193964:	0c004b70 */ 	jal	random
/*  f193968:	00000000 */ 	nop
/*  f19396c:	3049000f */ 	andi	$t1,$v0,0xf
/*  f193970:	11200012 */ 	beqz	$t1,.L0f1939bc
/*  f193974:	27aa0214 */ 	addiu	$t2,$sp,0x214
/*  f193978:	02ca8021 */ 	addu	$s0,$s6,$t2
/*  f19397c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f193980:	02f66021 */ 	addu	$t4,$s7,$s6
/*  f193984:	5160000b */ 	beqzl	$t3,.L0f1939b4
/*  f193988:	02f67021 */ 	addu	$t6,$s7,$s6
/*  f19398c:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f193990:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f193994:	00000000 */ 	nop
/*  f193998:	45030006 */ 	bc1tl	.L0f1939b4
/*  f19399c:	02f67021 */ 	addu	$t6,$s7,$s6
/*  f1939a0:	0c004b70 */ 	jal	random
/*  f1939a4:	00000000 */ 	nop
/*  f1939a8:	304d000f */ 	andi	$t5,$v0,0xf
/*  f1939ac:	15a00003 */ 	bnez	$t5,.L0f1939bc
/*  f1939b0:	02f67021 */ 	addu	$t6,$s7,$s6
.L0f1939b4:
/*  f1939b4:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f1939b8:	e5d40000 */ 	swc1	$f20,0x0($t6)
.L0f1939bc:
/*  f1939bc:	10000003 */ 	b	.L0f1939cc
/*  f1939c0:	9224005c */ 	lbu	$a0,0x5c($s1)
.L0f1939c4:
/*  f1939c4:	1662ffe0 */ 	bne	$s3,$v0,.L0f193948
/*  f1939c8:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f1939cc:
/*  f1939cc:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f1939d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1939d4:	18400019 */ 	blez	$v0,.L0f193a3c
/*  f1939d8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1939dc:	0c004b70 */ 	jal	random
/*  f1939e0:	00000000 */ 	nop
/*  f1939e4:	304f000f */ 	andi	$t7,$v0,0xf
/*  f1939e8:	11e00014 */ 	beqz	$t7,.L0f193a3c
/*  f1939ec:	00118080 */ 	sll	$s0,$s1,0x2
/*  f1939f0:	27b80178 */ 	addiu	$t8,$sp,0x178
/*  f1939f4:	02189821 */ 	addu	$s3,$s0,$t8
/*  f1939f8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f1939fc:	03b04021 */ 	addu	$t0,$sp,$s0
/*  f193a00:	5320000c */ 	beqzl	$t9,.L0f193a34
/*  f193a04:	ae750000 */ 	sw	$s5,0x0($s3)
/*  f193a08:	c50600f4 */ 	lwc1	$f6,0xf4($t0)
/*  f193a0c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f193a10:	00000000 */ 	nop
/*  f193a14:	45030007 */ 	bc1tl	.L0f193a34
/*  f193a18:	ae750000 */ 	sw	$s5,0x0($s3)
/*  f193a1c:	0c004b70 */ 	jal	random
/*  f193a20:	00000000 */ 	nop
/*  f193a24:	3049000f */ 	andi	$t1,$v0,0xf
/*  f193a28:	15200004 */ 	bnez	$t1,.L0f193a3c
/*  f193a2c:	00000000 */ 	nop
/*  f193a30:	ae750000 */ 	sw	$s5,0x0($s3)
.L0f193a34:
/*  f193a34:	03b05021 */ 	addu	$t2,$sp,$s0
/*  f193a38:	e55400f4 */ 	swc1	$f20,0xf4($t2)
.L0f193a3c:
/*  f193a3c:	10000081 */ 	b	.L0f193c44
/*  f193a40:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a44:	24010001 */ 	addiu	$at,$zero,0x1
.L0f193a48:
/*  f193a48:	5441007e */ 	bnel	$v0,$at,.L0f193c44
/*  f193a4c:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a50:	8ea20004 */ 	lw	$v0,0x4($s5)
/*  f193a54:	8c4b0010 */ 	lw	$t3,0x10($v0)
/*  f193a58:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f193a5c:	55800079 */ 	bnezl	$t4,.L0f193c44
/*  f193a60:	8eb50020 */ 	lw	$s5,0x20($s5)
/*  f193a64:	90440003 */ 	lbu	$a0,0x3($v0)
/*  f193a68:	24010014 */ 	addiu	$at,$zero,0x14
/*  f193a6c:	00408025 */ 	or	$s0,$v0,$zero
/*  f193a70:	1481004d */ 	bne	$a0,$at,.L0f193ba8
/*  f193a74:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f193a78:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193a7c:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193a80:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193a84:	46000506 */ 	mov.s	$f20,$f0
/*  f193a88:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193a8c:	02009825 */ 	or	$s3,$s0,$zero
.L0f193a90:
/*  f193a90:	966d005e */ 	lhu	$t5,0x5e($s3)
/*  f193a94:	59a0003f */ 	blezl	$t5,.L0f193b94
/*  f193a98:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193a9c:	0fc668c7 */ 	jal	ammotypeGetWeapon
/*  f193aa0:	02802025 */ 	or	$a0,$s4,$zero
/*  f193aa4:	18400022 */ 	blez	$v0,.L0f193b30
/*  f193aa8:	00008025 */ 	or	$s0,$zero,$zero
/*  f193aac:	27a3025c */ 	addiu	$v1,$sp,0x25c
.L0f193ab0:
/*  f193ab0:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f193ab4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f193ab8:	28810002 */ 	slti	$at,$a0,0x2
/*  f193abc:	1420001a */ 	bnez	$at,.L0f193b28
/*  f193ac0:	00000000 */ 	nop
/*  f193ac4:	14440018 */ 	bne	$v0,$a0,.L0f193b28
/*  f193ac8:	00000000 */ 	nop
/*  f193acc:	0c004b70 */ 	jal	random
/*  f193ad0:	00000000 */ 	nop
/*  f193ad4:	304e000f */ 	andi	$t6,$v0,0xf
/*  f193ad8:	11c00015 */ 	beqz	$t6,.L0f193b30
/*  f193adc:	27af0214 */ 	addiu	$t7,$sp,0x214
/*  f193ae0:	020f8821 */ 	addu	$s1,$s0,$t7
/*  f193ae4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f193ae8:	02f0c821 */ 	addu	$t9,$s7,$s0
/*  f193aec:	5300000b */ 	beqzl	$t8,.L0f193b1c
/*  f193af0:	02f04821 */ 	addu	$t1,$s7,$s0
/*  f193af4:	c7280000 */ 	lwc1	$f8,0x0($t9)
/*  f193af8:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f193afc:	00000000 */ 	nop
/*  f193b00:	45030006 */ 	bc1tl	.L0f193b1c
/*  f193b04:	02f04821 */ 	addu	$t1,$s7,$s0
/*  f193b08:	0c004b70 */ 	jal	random
/*  f193b0c:	00000000 */ 	nop
/*  f193b10:	3048000f */ 	andi	$t0,$v0,0xf
/*  f193b14:	15000006 */ 	bnez	$t0,.L0f193b30
/*  f193b18:	02f04821 */ 	addu	$t1,$s7,$s0
.L0f193b1c:
/*  f193b1c:	ae350000 */ 	sw	$s5,0x0($s1)
/*  f193b20:	10000003 */ 	b	.L0f193b30
/*  f193b24:	e5340000 */ 	swc1	$f20,0x0($t1)
.L0f193b28:
/*  f193b28:	1472ffe1 */ 	bne	$v1,$s2,.L0f193ab0
/*  f193b2c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f193b30:
/*  f193b30:	0c004b70 */ 	jal	random
/*  f193b34:	00000000 */ 	nop
/*  f193b38:	304a000f */ 	andi	$t2,$v0,0xf
/*  f193b3c:	11400014 */ 	beqz	$t2,.L0f193b90
/*  f193b40:	00141080 */ 	sll	$v0,$s4,0x2
/*  f193b44:	27ab0178 */ 	addiu	$t3,$sp,0x178
/*  f193b48:	004b8021 */ 	addu	$s0,$v0,$t3
/*  f193b4c:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f193b50:	27ac00f4 */ 	addiu	$t4,$sp,0xf4
/*  f193b54:	004c8821 */ 	addu	$s1,$v0,$t4
/*  f193b58:	51a0000c */ 	beqzl	$t5,.L0f193b8c
/*  f193b5c:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193b60:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f193b64:	460aa03c */ 	c.lt.s	$f20,$f10
/*  f193b68:	00000000 */ 	nop
/*  f193b6c:	45030007 */ 	bc1tl	.L0f193b8c
/*  f193b70:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193b74:	0c004b70 */ 	jal	random
/*  f193b78:	00000000 */ 	nop
/*  f193b7c:	304e000f */ 	andi	$t6,$v0,0xf
/*  f193b80:	55c00004 */ 	bnezl	$t6,.L0f193b94
/*  f193b84:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193b88:	ae150000 */ 	sw	$s5,0x0($s0)
.L0f193b8c:
/*  f193b8c:	e6340000 */ 	swc1	$f20,0x0($s1)
.L0f193b90:
/*  f193b90:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f193b94:
/*  f193b94:	24010014 */ 	addiu	$at,$zero,0x14
/*  f193b98:	1681ffbd */ 	bne	$s4,$at,.L0f193a90
/*  f193b9c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193ba0:	10000028 */ 	b	.L0f193c44
/*  f193ba4:	8eb50020 */ 	lw	$s5,0x20($s5)
.L0f193ba8:
/*  f193ba8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f193bac:	14810024 */ 	bne	$a0,$at,.L0f193c40
/*  f193bb0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193bb4:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193bb8:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193bbc:	27a30274 */ 	addiu	$v1,$sp,0x274
.L0f193bc0:
/*  f193bc0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f193bc4:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f193bc8:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193bcc:	15e1001a */ 	bne	$t7,$at,.L0f193c38
/*  f193bd0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193bd4:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f193bd8:	26a50008 */ 	addiu	$a1,$s5,0x8
/*  f193bdc:	0c004b70 */ 	jal	random
/*  f193be0:	46000506 */ 	mov.s	$f20,$f0
/*  f193be4:	3058000f */ 	andi	$t8,$v0,0xf
/*  f193be8:	13000015 */ 	beqz	$t8,.L0f193c40
/*  f193bec:	27b90214 */ 	addiu	$t9,$sp,0x214
/*  f193bf0:	02d98021 */ 	addu	$s0,$s6,$t9
/*  f193bf4:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f193bf8:	02f64821 */ 	addu	$t1,$s7,$s6
/*  f193bfc:	5100000b */ 	beqzl	$t0,.L0f193c2c
/*  f193c00:	02f65821 */ 	addu	$t3,$s7,$s6
/*  f193c04:	c5240000 */ 	lwc1	$f4,0x0($t1)
/*  f193c08:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f193c0c:	00000000 */ 	nop
/*  f193c10:	45030006 */ 	bc1tl	.L0f193c2c
/*  f193c14:	02f65821 */ 	addu	$t3,$s7,$s6
/*  f193c18:	0c004b70 */ 	jal	random
/*  f193c1c:	00000000 */ 	nop
/*  f193c20:	304a000f */ 	andi	$t2,$v0,0xf
/*  f193c24:	15400006 */ 	bnez	$t2,.L0f193c40
/*  f193c28:	02f65821 */ 	addu	$t3,$s7,$s6
.L0f193c2c:
/*  f193c2c:	ae150000 */ 	sw	$s5,0x0($s0)
/*  f193c30:	10000003 */ 	b	.L0f193c40
/*  f193c34:	e5740000 */ 	swc1	$f20,0x0($t3)
.L0f193c38:
/*  f193c38:	1663ffe1 */ 	bne	$s3,$v1,.L0f193bc0
/*  f193c3c:	26d60004 */ 	addiu	$s6,$s6,0x4
.L0f193c40:
/*  f193c40:	8eb50020 */ 	lw	$s5,0x20($s5)
.L0f193c44:
/*  f193c44:	56a0ff29 */ 	bnezl	$s5,.L0f1938ec
/*  f193c48:	8eaf0018 */ 	lw	$t7,0x18($s5)
/*  f193c4c:	afa000a0 */ 	sw	$zero,0xa0($sp)
.L0f193c50:
/*  f193c50:	afa0009c */ 	sw	$zero,0x9c($sp)
/*  f193c54:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193c58:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f193c5c:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f193c60:	27b00274 */ 	addiu	$s0,$sp,0x274
.L0f193c64:
/*  f193c64:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193c68:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f193c6c:	0fc6639e */ 	jal	func0f198e78
/*  f193c70:	00003025 */ 	or	$a2,$zero,$zero
/*  f193c74:	14400006 */ 	bnez	$v0,.L0f193c90
/*  f193c78:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193c7c:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f193c80:	0fc6639e */ 	jal	func0f198e78
/*  f193c84:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f193c88:	50400013 */ 	beqzl	$v0,.L0f193cd8
/*  f193c8c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193c90:
/*  f193c90:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f193c94:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f193c98:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f193c9c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f193ca0:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f193ca4:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
/*  f193ca8:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f193cac:	000373c2 */ 	srl	$t6,$v1,0xf
/*  f193cb0:	15c00003 */ 	bnez	$t6,.L0f193cc0
/*  f193cb4:	0003c440 */ 	sll	$t8,$v1,0x11
/*  f193cb8:	07030007 */ 	bgezl	$t8,.L0f193cd8
/*  f193cbc:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193cc0:
/*  f193cc0:	8c420244 */ 	lw	$v0,0x244($v0)
/*  f193cc4:	0322082a */ 	slt	$at,$t9,$v0
/*  f193cc8:	50200003 */ 	beqzl	$at,.L0f193cd8
/*  f193ccc:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193cd0:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f193cd4:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f193cd8:
/*  f193cd8:	0270082b */ 	sltu	$at,$s3,$s0
/*  f193cdc:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f193ce0:	1420ffe0 */ 	bnez	$at,.L0f193c64
/*  f193ce4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f193ce8:	3c017f1c */ 	lui	$at,%hi(var7f1b8f48)
/*  f193cec:	c4328f48 */ 	lwc1	$f18,%lo(var7f1b8f48)($at)
/*  f193cf0:	3c014080 */ 	lui	$at,0x4080
/*  f193cf4:	27a8025c */ 	addiu	$t0,$sp,0x25c
/*  f193cf8:	44818000 */ 	mtc1	$at,$f16
/*  f193cfc:	44806000 */ 	mtc1	$zero,$f12
/*  f193d00:	00089821 */ 	addu	$s3,$zero,$t0
/*  f193d04:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f193d08:	0000b025 */ 	or	$s6,$zero,$zero
/*  f193d0c:	27b00274 */ 	addiu	$s0,$sp,0x274
/*  f193d10:	8e690000 */ 	lw	$t1,0x0($s3)
.L0f193d14:
/*  f193d14:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f193d18:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f193d1c:	552100d0 */ 	bnel	$t1,$at,.L0f194060
/*  f193d20:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193d24:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f193d28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193d2c:	8fad0274 */ 	lw	$t5,0x274($sp)
/*  f193d30:	54610007 */ 	bnel	$v1,$at,.L0f193d50
/*  f193d34:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f193d38:	8fca02d4 */ 	lw	$t2,0x2d4($s8)
/*  f193d3c:	8d4b009c */ 	lw	$t3,0x9c($t2)
/*  f193d40:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f193d44:	558000c6 */ 	bnezl	$t4,.L0f194060
/*  f193d48:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f193d4c:	8da20004 */ 	lw	$v0,0x4($t5)
.L0f193d50:
/*  f193d50:	3c017f1c */ 	lui	$at,%hi(var7f1b8f4c)
/*  f193d54:	c4228f4c */ 	lwc1	$f2,%lo(var7f1b8f4c)($at)
/*  f193d58:	904e0047 */ 	lbu	$t6,0x47($v0)
/*  f193d5c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193d60:	46006506 */ 	mov.s	$f20,$f12
/*  f193d64:	15c1001b */ 	bne	$t6,$at,.L0f193dd4
/*  f193d68:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f193d6c:	8faf027c */ 	lw	$t7,0x27c($sp)
/*  f193d70:	c7c60104 */ 	lwc1	$f6,0x104($s8)
/*  f193d74:	c7c80100 */ 	lwc1	$f8,0x100($s8)
/*  f193d78:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193d7c:	90430048 */ 	lbu	$v1,0x48($v0)
/*  f193d80:	15e10003 */ 	bne	$t7,$at,.L0f193d90
/*  f193d84:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f193d88:	1000005b */ 	b	.L0f193ef8
/*  f193d8c:	46009506 */ 	mov.s	$f20,$f18
.L0f193d90:
/*  f193d90:	8fb8027c */ 	lw	$t8,0x27c($sp)
/*  f193d94:	8fb90274 */ 	lw	$t9,0x274($sp)
/*  f193d98:	8fa8027c */ 	lw	$t0,0x27c($sp)
/*  f193d9c:	17000007 */ 	bnez	$t8,.L0f193dbc
/*  f193da0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193da4:	c72002d4 */ 	lwc1	$f0,0x2d4($t9)
/*  f193da8:	3c0140c0 */ 	lui	$at,0x40c0
/*  f193dac:	44815000 */ 	mtc1	$at,$f10
/*  f193db0:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f193db4:	10000050 */ 	b	.L0f193ef8
/*  f193db8:	46045501 */ 	sub.s	$f20,$f10,$f4
.L0f193dbc:
/*  f193dbc:	1501004e */ 	bne	$t0,$at,.L0f193ef8
/*  f193dc0:	8fa90274 */ 	lw	$t1,0x274($sp)
/*  f193dc4:	c52002d4 */ 	lwc1	$f0,0x2d4($t1)
/*  f193dc8:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f193dcc:	1000004a */ 	b	.L0f193ef8
/*  f193dd0:	46068501 */ 	sub.s	$f20,$f16,$f6
.L0f193dd4:
/*  f193dd4:	1140000d */ 	beqz	$t2,.L0f193e0c
/*  f193dd8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f193ddc:	8fab0274 */ 	lw	$t3,0x274($sp)
/*  f193de0:	3c013f80 */ 	lui	$at,0x3f80
/*  f193de4:	44815000 */ 	mtc1	$at,$f10
/*  f193de8:	c56002d4 */ 	lwc1	$f0,0x2d4($t3)
/*  f193dec:	c7c40104 */ 	lwc1	$f4,0x104($s8)
/*  f193df0:	c7c60100 */ 	lwc1	$f6,0x100($s8)
/*  f193df4:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f193df8:	90430048 */ 	lbu	$v1,0x48($v0)
/*  f193dfc:	46005501 */ 	sub.s	$f20,$f10,$f0
/*  f193e00:	46088081 */ 	sub.s	$f2,$f16,$f8
/*  f193e04:	1000003c */ 	b	.L0f193ef8
/*  f193e08:	46062381 */ 	sub.s	$f14,$f4,$f6
.L0f193e0c:
/*  f193e0c:	14610016 */ 	bne	$v1,$at,.L0f193e68
/*  f193e10:	03c02025 */ 	or	$a0,$s8,$zero
/*  f193e14:	0fc65227 */ 	jal	func0f19489c
/*  f193e18:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f193e1c:	3c014080 */ 	lui	$at,0x4080
/*  f193e20:	44818000 */ 	mtc1	$at,$f16
/*  f193e24:	3c017f1c */ 	lui	$at,%hi(var7f1b8f50)
/*  f193e28:	44806000 */ 	mtc1	$zero,$f12
/*  f193e2c:	c4328f50 */ 	lwc1	$f18,%lo(var7f1b8f50)($at)
/*  f193e30:	1040000d */ 	beqz	$v0,.L0f193e68
/*  f193e34:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f193e38:	8fac0274 */ 	lw	$t4,0x274($sp)
/*  f193e3c:	3c014040 */ 	lui	$at,0x4040
/*  f193e40:	44814000 */ 	mtc1	$at,$f8
/*  f193e44:	c58002d4 */ 	lwc1	$f0,0x2d4($t4)
/*  f193e48:	c7c40104 */ 	lwc1	$f4,0x104($s8)
/*  f193e4c:	c7c60100 */ 	lwc1	$f6,0x100($s8)
/*  f193e50:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f193e54:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f193e58:	46062381 */ 	sub.s	$f14,$f4,$f6
/*  f193e5c:	91a30048 */ 	lbu	$v1,0x48($t5)
/*  f193e60:	10000025 */ 	b	.L0f193ef8
/*  f193e64:	460a4081 */ 	sub.s	$f2,$f8,$f10
.L0f193e68:
/*  f193e68:	8fae0274 */ 	lw	$t6,0x274($sp)
/*  f193e6c:	93d802a0 */ 	lbu	$t8,0x2a0($s8)
/*  f193e70:	c7c80104 */ 	lwc1	$f8,0x104($s8)
/*  f193e74:	c7ca0100 */ 	lwc1	$f10,0x100($s8)
/*  f193e78:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f193e7c:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f193e80:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f193e84:	17010007 */ 	bne	$t8,$at,.L0f193ea4
/*  f193e88:	91e30048 */ 	lbu	$v1,0x48($t7)
/*  f193e8c:	c5c002d4 */ 	lwc1	$f0,0x2d4($t6)
/*  f193e90:	3c013f80 */ 	lui	$at,0x3f80
/*  f193e94:	4481a000 */ 	mtc1	$at,$f20
/*  f193e98:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f193e9c:	10000016 */ 	b	.L0f193ef8
/*  f193ea0:	46048081 */ 	sub.s	$f2,$f16,$f4
.L0f193ea4:
/*  f193ea4:	8fb9027c */ 	lw	$t9,0x27c($sp)
/*  f193ea8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193eac:	8fa8027c */ 	lw	$t0,0x27c($sp)
/*  f193eb0:	17210003 */ 	bne	$t9,$at,.L0f193ec0
/*  f193eb4:	00000000 */ 	nop
/*  f193eb8:	1000000f */ 	b	.L0f193ef8
/*  f193ebc:	46009506 */ 	mov.s	$f20,$f18
.L0f193ec0:
/*  f193ec0:	15000006 */ 	bnez	$t0,.L0f193edc
/*  f193ec4:	8faa027c */ 	lw	$t2,0x27c($sp)
/*  f193ec8:	8fa90274 */ 	lw	$t1,0x274($sp)
/*  f193ecc:	c52002d4 */ 	lwc1	$f0,0x2d4($t1)
/*  f193ed0:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f193ed4:	10000008 */ 	b	.L0f193ef8
/*  f193ed8:	46068501 */ 	sub.s	$f20,$f16,$f6
.L0f193edc:
/*  f193edc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193ee0:	15410005 */ 	bne	$t2,$at,.L0f193ef8
/*  f193ee4:	8fab0274 */ 	lw	$t3,0x274($sp)
/*  f193ee8:	3c014000 */ 	lui	$at,0x4000
/*  f193eec:	44814000 */ 	mtc1	$at,$f8
/*  f193ef0:	c56a02d4 */ 	lwc1	$f10,0x2d4($t3)
/*  f193ef4:	460a4501 */ 	sub.s	$f20,$f8,$f10
.L0f193ef8:
/*  f193ef8:	1460001f */ 	bnez	$v1,.L0f193f78
/*  f193efc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f193f00:	8fac0274 */ 	lw	$t4,0x274($sp)
/*  f193f04:	8faf0274 */ 	lw	$t7,0x274($sp)
/*  f193f08:	8d8202d0 */ 	lw	$v0,0x2d0($t4)
/*  f193f0c:	304d0007 */ 	andi	$t5,$v0,0x7
/*  f193f10:	29a10002 */ 	slti	$at,$t5,0x2
/*  f193f14:	10200004 */ 	beqz	$at,.L0f193f28
/*  f193f18:	01a01025 */ 	or	$v0,$t5,$zero
/*  f193f1c:	46006506 */ 	mov.s	$f20,$f12
/*  f193f20:	10000038 */ 	b	.L0f194004
/*  f193f24:	46006086 */ 	mov.s	$f2,$f12
.L0f193f28:
/*  f193f28:	28410004 */ 	slti	$at,$v0,0x4
/*  f193f2c:	10200006 */ 	beqz	$at,.L0f193f48
/*  f193f30:	c5e002d4 */ 	lwc1	$f0,0x2d4($t7)
/*  f193f34:	3c014000 */ 	lui	$at,0x4000
/*  f193f38:	44812000 */ 	mtc1	$at,$f4
/*  f193f3c:	46006506 */ 	mov.s	$f20,$f12
/*  f193f40:	10000030 */ 	b	.L0f194004
/*  f193f44:	46002081 */ 	sub.s	$f2,$f4,$f0
.L0f193f48:
/*  f193f48:	3c014180 */ 	lui	$at,0x4180
/*  f193f4c:	44813000 */ 	mtc1	$at,$f6
/*  f193f50:	00000000 */ 	nop
/*  f193f54:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f193f58:	4608a501 */ 	sub.s	$f20,$f20,$f8
/*  f193f5c:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193f60:	00000000 */ 	nop
/*  f193f64:	45020028 */ 	bc1fl	.L0f194008
/*  f193f68:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193f6c:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f193f70:	10000024 */ 	b	.L0f194004
/*  f193f74:	46006506 */ 	mov.s	$f20,$f12
.L0f193f78:
/*  f193f78:	14610016 */ 	bne	$v1,$at,.L0f193fd4
/*  f193f7c:	8fb80274 */ 	lw	$t8,0x274($sp)
/*  f193f80:	8f0202d0 */ 	lw	$v0,0x2d0($t8)
/*  f193f84:	8fb90274 */ 	lw	$t9,0x274($sp)
/*  f193f88:	3c014130 */ 	lui	$at,0x4130
/*  f193f8c:	304e0007 */ 	andi	$t6,$v0,0x7
/*  f193f90:	5dc00005 */ 	bgtzl	$t6,.L0f193fa8
/*  f193f94:	c72a02d4 */ 	lwc1	$f10,0x2d4($t9)
/*  f193f98:	46006506 */ 	mov.s	$f20,$f12
/*  f193f9c:	10000019 */ 	b	.L0f194004
/*  f193fa0:	46006086 */ 	mov.s	$f2,$f12
/*  f193fa4:	c72a02d4 */ 	lwc1	$f10,0x2d4($t9)
.L0f193fa8:
/*  f193fa8:	44812000 */ 	mtc1	$at,$f4
/*  f193fac:	00000000 */ 	nop
/*  f193fb0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f193fb4:	4606a501 */ 	sub.s	$f20,$f20,$f6
/*  f193fb8:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193fbc:	00000000 */ 	nop
/*  f193fc0:	45020011 */ 	bc1fl	.L0f194008
/*  f193fc4:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193fc8:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f193fcc:	1000000d */ 	b	.L0f194004
/*  f193fd0:	46006506 */ 	mov.s	$f20,$f12
.L0f193fd4:
/*  f193fd4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f193fd8:	1461000a */ 	bne	$v1,$at,.L0f194004
/*  f193fdc:	8fa80274 */ 	lw	$t0,0x274($sp)
/*  f193fe0:	c50802d4 */ 	lwc1	$f8,0x2d4($t0)
/*  f193fe4:	46104282 */ 	mul.s	$f10,$f8,$f16
/*  f193fe8:	460aa501 */ 	sub.s	$f20,$f20,$f10
/*  f193fec:	460ca03e */ 	c.le.s	$f20,$f12
/*  f193ff0:	00000000 */ 	nop
/*  f193ff4:	45020004 */ 	bc1fl	.L0f194008
/*  f193ff8:	4602703c */ 	c.lt.s	$f14,$f2
/*  f193ffc:	46141080 */ 	add.s	$f2,$f2,$f20
/*  f194000:	46006506 */ 	mov.s	$f20,$f12
.L0f194004:
/*  f194004:	4602703c */ 	c.lt.s	$f14,$f2
.L0f194008:
/*  f194008:	00000000 */ 	nop
/*  f19400c:	45020014 */ 	bc1fl	.L0f194060
/*  f194010:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194014:	c7c40180 */ 	lwc1	$f4,0x180($s8)
/*  f194018:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f19401c:	4614203e */ 	c.le.s	$f4,$f20
/*  f194020:	00000000 */ 	nop
/*  f194024:	4502000e */ 	bc1fl	.L0f194060
/*  f194028:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f19402c:	8c420214 */ 	lw	$v0,0x214($v0)
/*  f194030:	03b64821 */ 	addu	$t1,$sp,$s6
/*  f194034:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f194038:	50400009 */ 	beqzl	$v0,.L0f194060
/*  f19403c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194040:	8d29022c */ 	lw	$t1,0x22c($t1)
/*  f194044:	012a082a */ 	slt	$at,$t1,$t2
/*  f194048:	14200004 */ 	bnez	$at,.L0f19405c
/*  f19404c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f194050:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194054:	10000008 */ 	b	.L0f194078
/*  f194058:	afab009c */ 	sw	$t3,0x9c($sp)
.L0f19405c:
/*  f19405c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f194060:
/*  f194060:	0270082b */ 	sltu	$at,$s3,$s0
/*  f194064:	10200004 */ 	beqz	$at,.L0f194078
/*  f194068:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19406c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f194070:	5180ff28 */ 	beqzl	$t4,.L0f193d14
/*  f194074:	8e690000 */ 	lw	$t1,0x0($s3)
.L0f194078:
/*  f194078:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f19407c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194080:	0000b025 */ 	or	$s6,$zero,$zero
/*  f194084:	15a000fe */ 	bnez	$t5,.L0f194480
/*  f194088:	27af025c */ 	addiu	$t7,$sp,0x25c
/*  f19408c:	000f9821 */ 	addu	$s3,$zero,$t7
/*  f194090:	8fb70088 */ 	lw	$s7,0x88($sp)
/*  f194094:	8fb50084 */ 	lw	$s5,0x84($sp)
/*  f194098:	8e650000 */ 	lw	$a1,0x0($s3)
.L0f19409c:
/*  f19409c:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1940a0:	03b6c021 */ 	addu	$t8,$sp,$s6
/*  f1940a4:	50a100ea */ 	beql	$a1,$at,.L0f194450
/*  f1940a8:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f1940ac:	8f1800dc */ 	lw	$t8,0xdc($t8)
/*  f1940b0:	00057100 */ 	sll	$t6,$a1,0x4
/*  f1940b4:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f1940b8:	130000e4 */ 	beqz	$t8,.L0f19444c
/*  f1940bc:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f1940c0:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
/*  f1940c4:	03b65021 */ 	addu	$t2,$sp,$s6
/*  f1940c8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f1940cc:	0003cbc2 */ 	srl	$t9,$v1,0xf
/*  f1940d0:	17200003 */ 	bnez	$t9,.L0f1940e0
/*  f1940d4:	00034c40 */ 	sll	$t1,$v1,0x11
/*  f1940d8:	052300dd */ 	bgezl	$t1,.L0f194450
/*  f1940dc:	8fb400d8 */ 	lw	$s4,0xd8($sp)
.L0f1940e0:
/*  f1940e0:	8d4a022c */ 	lw	$t2,0x22c($t2)
/*  f1940e4:	3c0c800b */ 	lui	$t4,%hi(g_MpSetup+0x10)
/*  f1940e8:	014b082a */ 	slt	$at,$t2,$t3
/*  f1940ec:	542000d8 */ 	bnezl	$at,.L0f194450
/*  f1940f0:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f1940f4:	918ccb98 */ 	lbu	$t4,%lo(g_MpSetup+0x10)($t4)
/*  f1940f8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1940fc:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f194100:	55810008 */ 	bnel	$t4,$at,.L0f194124
/*  f194104:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
/*  f194108:	0fc65227 */ 	jal	func0f19489c
/*  f19410c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f194110:	10400003 */ 	beqz	$v0,.L0f194120
/*  f194114:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f194118:	100000d9 */ 	b	.L0f194480
/*  f19411c:	afad009c */ 	sw	$t5,0x9c($sp)
.L0f194120:
/*  f194120:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
.L0f194124:
/*  f194124:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f194128:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f19412c:	15e10004 */ 	bne	$t7,$at,.L0f194140
/*  f194130:	8fad027c */ 	lw	$t5,0x27c($sp)
/*  f194134:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f194138:	100000d1 */ 	b	.L0f194480
/*  f19413c:	afb8009c */ 	sw	$t8,0x9c($sp)
.L0f194140:
/*  f194140:	11c0002a */ 	beqz	$t6,.L0f1941ec
/*  f194144:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194148:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19414c:	3c088008 */ 	lui	$t0,%hi(g_AibotWeaponPreferences)
/*  f194150:	25087eb0 */ 	addiu	$t0,$t0,%lo(g_AibotWeaponPreferences)
/*  f194154:	0005c900 */ 	sll	$t9,$a1,0x4
/*  f194158:	03281021 */ 	addu	$v0,$t9,$t0
/*  f19415c:	9457000a */ 	lhu	$s7,0xa($v0)
/*  f194160:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f194164:	00003025 */ 	or	$a2,$zero,$zero
/*  f194168:	2ae10002 */ 	slti	$at,$s7,0x2
/*  f19416c:	14200002 */ 	bnez	$at,.L0f194178
/*  f194170:	000323c2 */ 	srl	$a0,$v1,0xf
/*  f194174:	24170001 */ 	addiu	$s7,$zero,0x1
.L0f194178:
/*  f194178:	9455000c */ 	lhu	$s5,0xc($v0)
/*  f19417c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f194180:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f194184:	14200002 */ 	bnez	$at,.L0f194190
/*  f194188:	00000000 */ 	nop
/*  f19418c:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f194190:
/*  f194190:	5080000c */ 	beqzl	$a0,.L0f1941c4
/*  f194194:	00035c40 */ 	sll	$t3,$v1,0x11
/*  f194198:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f19419c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1941a0:	0057082a */ 	slt	$at,$v0,$s7
/*  f1941a4:	5020000f */ 	beqzl	$at,.L0f1941e4
/*  f1941a8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1941ac:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1941b0:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f1941b4:	00054900 */ 	sll	$t1,$a1,0x4
/*  f1941b8:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1941bc:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
/*  f1941c0:	00035c40 */ 	sll	$t3,$v1,0x11
.L0f1941c4:
/*  f1941c4:	05610080 */ 	bgez	$t3,.L0f1943c8
/*  f1941c8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1941cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1941d0:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f1941d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1941d8:	0055082a */ 	slt	$at,$v0,$s5
/*  f1941dc:	1420007a */ 	bnez	$at,.L0f1943c8
/*  f1941e0:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f1941e4:
/*  f1941e4:	100000a6 */ 	b	.L0f194480
/*  f1941e8:	afac009c */ 	sw	$t4,0x9c($sp)
.L0f1941ec:
/*  f1941ec:	15a1002f */ 	bne	$t5,$at,.L0f1942ac
/*  f1941f0:	8fa9027c */ 	lw	$t1,0x27c($sp)
/*  f1941f4:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1941f8:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f1941fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f194200:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f194204:	00402025 */ 	or	$a0,$v0,$zero
/*  f194208:	0040b825 */ 	or	$s7,$v0,$zero
/*  f19420c:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f194210:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f194214:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f194218:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f19421c:	00402025 */ 	or	$a0,$v0,$zero
/*  f194220:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194224:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f194228:	0040a825 */ 	or	$s5,$v0,$zero
/*  f19422c:	00057900 */ 	sll	$t7,$a1,0x4
/*  f194230:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f194234:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
/*  f194238:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f19423c:	00003025 */ 	or	$a2,$zero,$zero
/*  f194240:	0003c3c2 */ 	srl	$t8,$v1,0xf
/*  f194244:	5300000c */ 	beqzl	$t8,.L0f194278
/*  f194248:	00034440 */ 	sll	$t0,$v1,0x11
/*  f19424c:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f194250:	00003825 */ 	or	$a3,$zero,$zero
/*  f194254:	0057082a */ 	slt	$at,$v0,$s7
/*  f194258:	14200012 */ 	bnez	$at,.L0f1942a4
/*  f19425c:	00000000 */ 	nop
/*  f194260:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194264:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f194268:	00057100 */ 	sll	$t6,$a1,0x4
/*  f19426c:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f194270:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
/*  f194274:	00034440 */ 	sll	$t0,$v1,0x11
.L0f194278:
/*  f194278:	05010007 */ 	bgez	$t0,.L0f194298
/*  f19427c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194280:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f194284:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f194288:	00003825 */ 	or	$a3,$zero,$zero
/*  f19428c:	0055082a */ 	slt	$at,$v0,$s5
/*  f194290:	14200004 */ 	bnez	$at,.L0f1942a4
/*  f194294:	00000000 */ 	nop
.L0f194298:
/*  f194298:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f19429c:	1000006d */ 	b	.L0f194454
/*  f1942a0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1942a4:
/*  f1942a4:	10000048 */ 	b	.L0f1943c8
/*  f1942a8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f1942ac:
/*  f1942ac:	15200022 */ 	bnez	$t1,.L0f194338
/*  f1942b0:	8fb9027c */ 	lw	$t9,0x27c($sp)
/*  f1942b4:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1942b8:	3c0b8008 */ 	lui	$t3,%hi(g_AibotWeaponPreferences)
/*  f1942bc:	256b7eb0 */ 	addiu	$t3,$t3,%lo(g_AibotWeaponPreferences)
/*  f1942c0:	00055100 */ 	sll	$t2,$a1,0x4
/*  f1942c4:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f1942c8:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f1942cc:	94570006 */ 	lhu	$s7,0x6($v0)
/*  f1942d0:	94550008 */ 	lhu	$s5,0x8($v0)
/*  f1942d4:	000363c2 */ 	srl	$t4,$v1,0xf
/*  f1942d8:	1180000c */ 	beqz	$t4,.L0f19430c
/*  f1942dc:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1942e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1942e4:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f1942e8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1942ec:	0057082a */ 	slt	$at,$v0,$s7
/*  f1942f0:	5020000f */ 	beqzl	$at,.L0f194330
/*  f1942f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1942f8:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1942fc:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f194300:	00056900 */ 	sll	$t5,$a1,0x4
/*  f194304:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f194308:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
.L0f19430c:
/*  f19430c:	0003c440 */ 	sll	$t8,$v1,0x11
/*  f194310:	0701002d */ 	bgez	$t8,.L0f1943c8
/*  f194314:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194318:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19431c:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f194320:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f194324:	0055082a */ 	slt	$at,$v0,$s5
/*  f194328:	14200027 */ 	bnez	$at,.L0f1943c8
/*  f19432c:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f194330:
/*  f194330:	10000053 */ 	b	.L0f194480
/*  f194334:	afae009c */ 	sw	$t6,0x9c($sp)
.L0f194338:
/*  f194338:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19433c:	57210023 */ 	bnel	$t9,$at,.L0f1943cc
/*  f194340:	00008025 */ 	or	$s0,$zero,$zero
/*  f194344:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194348:	3c098008 */ 	lui	$t1,%hi(g_AibotWeaponPreferences)
/*  f19434c:	25297eb0 */ 	addiu	$t1,$t1,%lo(g_AibotWeaponPreferences)
/*  f194350:	00054100 */ 	sll	$t0,$a1,0x4
/*  f194354:	01091021 */ 	addu	$v0,$t0,$t1
/*  f194358:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f19435c:	9457000a */ 	lhu	$s7,0xa($v0)
/*  f194360:	9455000c */ 	lhu	$s5,0xc($v0)
/*  f194364:	000353c2 */ 	srl	$t2,$v1,0xf
/*  f194368:	1140000c */ 	beqz	$t2,.L0f19439c
/*  f19436c:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f194370:	00003025 */ 	or	$a2,$zero,$zero
/*  f194374:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f194378:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f19437c:	0057082a */ 	slt	$at,$v0,$s7
/*  f194380:	5020000f */ 	beqzl	$at,.L0f1943c0
/*  f194384:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f194388:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f19438c:	3c038008 */ 	lui	$v1,%hi(g_AibotWeaponPreferences+0x4)
/*  f194390:	00055900 */ 	sll	$t3,$a1,0x4
/*  f194394:	006b1821 */ 	addu	$v1,$v1,$t3
/*  f194398:	94637eb4 */ 	lhu	$v1,%lo(g_AibotWeaponPreferences+0x4)($v1)
.L0f19439c:
/*  f19439c:	00036c40 */ 	sll	$t5,$v1,0x11
/*  f1943a0:	05a10009 */ 	bgez	$t5,.L0f1943c8
/*  f1943a4:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1943a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1943ac:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f1943b0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1943b4:	0055082a */ 	slt	$at,$v0,$s5
/*  f1943b8:	14200003 */ 	bnez	$at,.L0f1943c8
/*  f1943bc:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f1943c0:
/*  f1943c0:	1000002f */ 	b	.L0f194480
/*  f1943c4:	afaf009c */ 	sw	$t7,0x9c($sp)
.L0f1943c8:
/*  f1943c8:	00008025 */ 	or	$s0,$zero,$zero
.L0f1943cc:
/*  f1943cc:	03c02025 */ 	or	$a0,$s8,$zero
.L0f1943d0:
/*  f1943d0:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1943d4:	0fc6639e */ 	jal	func0f198e78
/*  f1943d8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1943dc:	10400017 */ 	beqz	$v0,.L0f19443c
/*  f1943e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1943e4:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f1943e8:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1943ec:	18400013 */ 	blez	$v0,.L0f19443c
/*  f1943f0:	00409025 */ 	or	$s2,$v0,$zero
/*  f1943f4:	12000003 */ 	beqz	$s0,.L0f194404
/*  f1943f8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1943fc:	10000002 */ 	b	.L0f194408
/*  f194400:	02a08825 */ 	or	$s1,$s5,$zero
.L0f194404:
/*  f194404:	02e08825 */ 	or	$s1,$s7,$zero
.L0f194408:
/*  f194408:	02402825 */ 	or	$a1,$s2,$zero
/*  f19440c:	0fc6672e */ 	jal	aibotGetAmmoQuantityByType
/*  f194410:	02803025 */ 	or	$a2,$s4,$zero
/*  f194414:	0051082a */ 	slt	$at,$v0,$s1
/*  f194418:	10200008 */ 	beqz	$at,.L0f19443c
/*  f19441c:	0012c080 */ 	sll	$t8,$s2,0x2
/*  f194420:	03b81021 */ 	addu	$v0,$sp,$t8
/*  f194424:	8c420178 */ 	lw	$v0,0x178($v0)
/*  f194428:	10400004 */ 	beqz	$v0,.L0f19443c
/*  f19442c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f194430:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194434:	10000005 */ 	b	.L0f19444c
/*  f194438:	afae009c */ 	sw	$t6,0x9c($sp)
.L0f19443c:
/*  f19443c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194440:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194444:	5601ffe2 */ 	bnel	$s0,$at,.L0f1943d0
/*  f194448:	03c02025 */ 	or	$a0,$s8,$zero
.L0f19444c:
/*  f19444c:	8fb400d8 */ 	lw	$s4,0xd8($sp)
.L0f194450:
/*  f194450:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f194454:
/*  f194454:	afb400d8 */ 	sw	$s4,0xd8($sp)
/*  f194458:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f19445c:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f194460:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194464:	2b210006 */ 	slti	$at,$t9,0x6
/*  f194468:	10200005 */ 	beqz	$at,.L0f194480
/*  f19446c:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*  f194470:	5100ff0a */ 	beqzl	$t0,.L0f19409c
/*  f194474:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194478:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f19447c:	afb50084 */ 	sw	$s5,0x84($sp)
.L0f194480:
/*  f194480:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f194484:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194488:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19448c:	15200036 */ 	bnez	$t1,.L0f194568
/*  f194490:	27aa025c */ 	addiu	$t2,$sp,0x25c
/*  f194494:	000a9821 */ 	addu	$s3,$zero,$t2
/*  f194498:	27b00274 */ 	addiu	$s0,$sp,0x274
/*  f19449c:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f1944a0:
/*  f1944a0:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1944a4:	3c0c800b */ 	lui	$t4,%hi(g_MpSetup+0x10)
/*  f1944a8:	51610029 */ 	beql	$t3,$at,.L0f194550
/*  f1944ac:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f1944b0:	918ccb98 */ 	lbu	$t4,%lo(g_MpSetup+0x10)($t4)
/*  f1944b4:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1944b8:	55810008 */ 	bnel	$t4,$at,.L0f1944dc
/*  f1944bc:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
/*  f1944c0:	0fc65227 */ 	jal	func0f19489c
/*  f1944c4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1944c8:	10400003 */ 	beqz	$v0,.L0f1944d8
/*  f1944cc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1944d0:	10000025 */ 	b	.L0f194568
/*  f1944d4:	afad009c */ 	sw	$t5,0x9c($sp)
.L0f1944d8:
/*  f1944d8:	93cf02a0 */ 	lbu	$t7,0x2a0($s8)
.L0f1944dc:
/*  f1944dc:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f1944e0:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f1944e4:	15e10004 */ 	bne	$t7,$at,.L0f1944f8
/*  f1944e8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1944ec:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1944f0:	1000001d */ 	b	.L0f194568
/*  f1944f4:	afb8009c */ 	sw	$t8,0x9c($sp)
.L0f1944f8:
/*  f1944f8:	15c00014 */ 	bnez	$t6,.L0f19454c
/*  f1944fc:	00003025 */ 	or	$a2,$zero,$zero
/*  f194500:	0fc6639e */ 	jal	func0f198e78
/*  f194504:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194508:	14400005 */ 	bnez	$v0,.L0f194520
/*  f19450c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f194510:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f194514:	0fc6639e */ 	jal	func0f198e78
/*  f194518:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19451c:	1040000b */ 	beqz	$v0,.L0f19454c
.L0f194520:
/*  f194520:	03b6c821 */ 	addu	$t9,$sp,$s6
/*  f194524:	8f3900dc */ 	lw	$t9,0xdc($t9)
/*  f194528:	03b61021 */ 	addu	$v0,$sp,$s6
/*  f19452c:	57200008 */ 	bnezl	$t9,.L0f194550
/*  f194530:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194534:	8c420214 */ 	lw	$v0,0x214($v0)
/*  f194538:	10400004 */ 	beqz	$v0,.L0f19454c
/*  f19453c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f194540:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194544:	10000008 */ 	b	.L0f194568
/*  f194548:	afa8009c */ 	sw	$t0,0x9c($sp)
.L0f19454c:
/*  f19454c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f194550:
/*  f194550:	0270082b */ 	sltu	$at,$s3,$s0
/*  f194554:	10200004 */ 	beqz	$at,.L0f194568
/*  f194558:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19455c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*  f194560:	5120ffcf */ 	beqzl	$t1,.L0f1944a0
/*  f194564:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f194568:
/*  f194568:	8faa027c */ 	lw	$t2,0x27c($sp)
/*  f19456c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194570:	55410032 */ 	bnel	$t2,$at,.L0f19463c
/*  f194574:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f194578:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f19457c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f194580:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f194584:	1560002c */ 	bnez	$t3,.L0f194638
/*  f194588:	27b3025c */ 	addiu	$s3,$sp,0x25c
/*  f19458c:	27b50274 */ 	addiu	$s5,$sp,0x274
/*  f194590:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f194594:
/*  f194594:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f194598:	00008825 */ 	or	$s1,$zero,$zero
/*  f19459c:	1181001f */ 	beq	$t4,$at,.L0f19461c
/*  f1945a0:	03c02025 */ 	or	$a0,$s8,$zero
.L0f1945a4:
/*  f1945a4:	8e650000 */ 	lw	$a1,0x0($s3)
/*  f1945a8:	0fc6639e */ 	jal	func0f198e78
/*  f1945ac:	02203025 */ 	or	$a2,$s1,$zero
/*  f1945b0:	10400016 */ 	beqz	$v0,.L0f19460c
/*  f1945b4:	02202825 */ 	or	$a1,$s1,$zero
/*  f1945b8:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f1945bc:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f1945c0:	18400012 */ 	blez	$v0,.L0f19460c
/*  f1945c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f1945c8:	8fa40274 */ 	lw	$a0,0x274($sp)
/*  f1945cc:	00402825 */ 	or	$a1,$v0,$zero
/*  f1945d0:	0fc6672e */ 	jal	aibotGetAmmoQuantityByType
/*  f1945d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1945d8:	00409025 */ 	or	$s2,$v0,$zero
/*  f1945dc:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f1945e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1945e4:	0242082a */ 	slt	$at,$s2,$v0
/*  f1945e8:	10200008 */ 	beqz	$at,.L0f19460c
/*  f1945ec:	00106880 */ 	sll	$t5,$s0,0x2
/*  f1945f0:	03ad1021 */ 	addu	$v0,$sp,$t5
/*  f1945f4:	8c420178 */ 	lw	$v0,0x178($v0)
/*  f1945f8:	10400004 */ 	beqz	$v0,.L0f19460c
/*  f1945fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f194600:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f194604:	10000005 */ 	b	.L0f19461c
/*  f194608:	afaf009c */ 	sw	$t7,0x9c($sp)
.L0f19460c:
/*  f19460c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f194610:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194614:	5621ffe3 */ 	bnel	$s1,$at,.L0f1945a4
/*  f194618:	03c02025 */ 	or	$a0,$s8,$zero
.L0f19461c:
/*  f19461c:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f194620:	0275082b */ 	sltu	$at,$s3,$s5
/*  f194624:	10200004 */ 	beqz	$at,.L0f194638
/*  f194628:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19462c:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f194630:	5300ffd8 */ 	beqzl	$t8,.L0f194594
/*  f194634:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f194638:
/*  f194638:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f19463c:
/*  f19463c:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f194640:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f194644:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f194648:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f19464c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f194650:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f194654:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f194658:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f19465c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f194660:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f194664:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f194668:	03e00008 */ 	jr	$ra
/*  f19466c:	27bd0278 */ 	addiu	$sp,$sp,0x278
);

bool func0f194670(struct chrdata *chr)
{
	return func0f1937a4(chr, 1) != 0;
}

s32 func0f194694(struct chrdata *chr)
{
	return func0f1937a4(chr, 0);
}

s32 func0f1946b4(struct chrdata *chr)
{
	return func0f1937a4(chr, 2);
}

s32 mpGetNumPlayerTeammates(struct chrdata *chr)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (chr->team == g_MpPlayerChrs[i]->team) {
			count++;
		}
	}

	return count;
}

s32 mpCountAibotsWithCommand(struct chrdata *self, u32 command, bool includeself)
{
	s32 count = 0;
	s32 i;

	for (i = PLAYERCOUNT(); i < g_MpNumPlayers; i++) {
		if (self->team == g_MpPlayerChrs[i]->team) {
			if (includeself || self != g_MpPlayerChrs[i]) {
				if (command == g_MpPlayerChrs[i]->aibot->command) {
					count++;
				}
			}
		}
	}

	return count;
}

s32 scenarioCtcIsChrsTokenHeld(struct chrdata *chr)
{
	struct mpchr *mpchr = var800ac500[mpPlayerGetIndex(chr)];
	struct prop *prop = g_ScenarioData.ctc.tokens[mpchr->team];

	return prop && (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER);
}

bool func0f19489c(struct chrdata *chr)
{
	if (chr->aibot->unk09c_01) {
		if (!chr->aibot->teamisonlyai
				|| mpGetNumPlayerTeammates(chr) >= 2
				|| !scenarioCtcIsChrsTokenHeld(chr)) {
			return true;
		}
	}

	return false;
}

s32 mpGetNumTeammatesDefendingHill(struct chrdata *bot)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (bot->team == g_MpPlayerChrs[i]->team
				&& g_MpPlayerChrs[i]->prop->rooms[0] == g_ScenarioData.cbt.unk0e[0]) {
			if (g_MpPlayerChrs[i]->aibot->command == AIBOTCMD_DEFHILL
					|| g_MpPlayerChrs[i]->aibot->command == AIBOTCMD_HOLDHILL) {
				count++;
			}
		}
	}

	return count;
}

/**
 * Find the opposing team who has the most players in the hill and return the
 * number of their players who are in the hill.
 *
 * This function is slightly misnamed.
 */
s32 mpGetNumOpponentsInHill(struct chrdata *chr)
{
	struct mpchr *mpchr = var800ac500[mpPlayerGetIndex(chr)];
	struct mpchr *loopmpchr;
	s32 countsperteam[8] = {0};
	s32 max = 0;
	s32 i;

	for (i = 0; i < g_MpNumPlayers; i++) {
		if (g_MpPlayerChrs[i]->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
			s32 mpindex = func0f18d074(i);

			if (mpindex < 4) {
				loopmpchr = &g_MpPlayers[mpindex].base;
			} else {
				loopmpchr = &g_MpSimulants[mpindex - 4].base;
			}

			if (loopmpchr->team != mpchr->team) {
				countsperteam[loopmpchr->team]++;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (countsperteam[i] > max) {
			max = countsperteam[i];
		}
	}

	return max;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f194b40
.late_rodata
glabel var7f1b8f54
.word 0x49742400
glabel var7f1b8f58
.word func0f194b40+0x2398
glabel var7f1b8f5c
.word func0f194b40+0x23fc
glabel var7f1b8f60
.word func0f194b40+0x23fc
glabel var7f1b8f64
.word func0f194b40+0x23fc
glabel var7f1b8f68
.word func0f194b40+0x2398
glabel var7f1b8f6c
.word func0f194b40+0x2398
glabel var7f1b8f70
.word func0f194b40+0x2398
glabel var7f1b8f74
.word func0f194b40+0x23fc
glabel var7f1b8f78
.word func0f194b40+0x23fc
glabel var7f1b8f7c
.word func0f194b40+0x2398
glabel var7f1b8f80
.word func0f194b40+0x2398
glabel var7f1b8f84
.word func0f194b40+0x2398
glabel var7f1b8f88
.word func0f194b40+0x2398
glabel var7f1b8f8c
.word func0f194b40+0x2398
glabel var7f1b8f90
.word func0f194b40+0x2398
glabel var7f1b8f94
.word func0f194b40+0x2398
glabel var7f1b8f98
.word func0f194b40+0x2398
glabel var7f1b8f9c
.word func0f194b40+0x2398
glabel var7f1b8fa0
.word func0f194b40+0x2398
glabel var7f1b8fa4
.word func0f194b40+0x2474
glabel var7f1b8fa8
.word func0f194b40+0x2398
glabel var7f1b8fac
.word func0f194b40+0x2398
glabel var7f1b8fb0
.word func0f194b40+0x2398
glabel var7f1b8fb4
.word func0f194b40+0x2398
glabel var7f1b8fb8
.word func0f194b40+0x2398
glabel var7f1b8fbc
.word func0f194b40+0x23fc
glabel var7f1b8fc0
.word func0f194b40+0x2398
glabel var7f1b8fc4
.word func0f194b40+0x2450
glabel var7f1b8fc8
.word 0x3d4ccccd
.text
/*  f195bf8:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f195bfc:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f195c00:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f195c04:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f195c08:	0080a025 */ 	move	$s4,$a0
/*  f195c0c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f195c10:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f195c14:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f195c18:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f195c1c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f195c20:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f195c24:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f195c28:	0fc0e706 */ 	jal	chrIsDead
/*  f195c2c:	2415ffff */ 	li	$s5,-1
/*  f195c30:	14400a77 */ 	bnez	$v0,.PF0f198610
/*  f195c34:	3c16800a */ 	lui	$s6,0x800a
/*  f195c38:	8e9202d4 */ 	lw	$s2,0x2d4($s4)
/*  f195c3c:	26d6a510 */ 	addiu	$s6,$s6,-23280
/*  f195c40:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f195c44:	8e4e02cc */ 	lw	$t6,0x2cc($s2)
/*  f195c48:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f195c4c:	07210017 */ 	bgez	$t9,.PF0f195cac
/*  f195c50:	ae5902cc */ 	sw	$t9,0x2cc($s2)
/*  f195c54:	0c004ad4 */ 	jal	random
/*  f195c58:	00000000 */ 	nop
/*  f195c5c:	24012ee0 */ 	li	$at,0x2ee0
/*  f195c60:	0041001b */ 	divu	$zero,$v0,$at
/*  f195c64:	00004810 */ 	mfhi	$t1
/*  f195c68:	252a05dc */ 	addiu	$t2,$t1,0x5dc
/*  f195c6c:	0c004ad4 */ 	jal	random
/*  f195c70:	ae4a02cc */ 	sw	$t2,0x2cc($s2)
/*  f195c74:	0c004ad4 */ 	jal	random
/*  f195c78:	ae4202d0 */ 	sw	$v0,0x2d0($s2)
/*  f195c7c:	44822000 */ 	mtc1	$v0,$f4
/*  f195c80:	3c014f80 */ 	lui	$at,0x4f80
/*  f195c84:	04410004 */ 	bgez	$v0,.PF0f195c98
/*  f195c88:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f195c8c:	44814000 */ 	mtc1	$at,$f8
/*  f195c90:	00000000 */ 	nop
/*  f195c94:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f195c98:
/*  f195c98:	3c012f80 */ 	lui	$at,0x2f80
/*  f195c9c:	44815000 */ 	mtc1	$at,$f10
/*  f195ca0:	00000000 */ 	nop
/*  f195ca4:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f195ca8:	e65202d4 */ 	swc1	$f18,0x2d4($s2)
.PF0f195cac:
/*  f195cac:	00008025 */ 	move	$s0,$zero
/*  f195cb0:	02403825 */ 	move	$a3,$s2
.PF0f195cb4:
/*  f195cb4:	84e2002c */ 	lh	$v0,0x2c($a3)
/*  f195cb8:	5840000f */ 	blezl	$v0,.PF0f195cf8
/*  f195cbc:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f195cc0:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f195cc4:	02802025 */ 	move	$a0,$s4
/*  f195cc8:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f195ccc:	a4ec002c */ 	sh	$t4,0x2c($a3)
/*  f195cd0:	84ed002c */ 	lh	$t5,0x2c($a3)
/*  f195cd4:	5da00037 */ 	bgtzl	$t5,.PF0f195db4
/*  f195cd8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195cdc:	02002825 */ 	move	$a1,$s0
/*  f195ce0:	24060001 */ 	li	$a2,0x1
/*  f195ce4:	0fc66ad0 */ 	jal	aibotReloadWeapon
/*  f195ce8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195cec:	10000030 */ 	b	.PF0f195db0
/*  f195cf0:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195cf4:	8e45004c */ 	lw	$a1,0x4c($s2)
.PF0f195cf8:
/*  f195cf8:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195cfc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d00:	00057080 */ 	sll	$t6,$a1,0x2
/*  f195d04:	0fc66ce7 */ 	jal	func0f19a29c
/*  f195d08:	000e2fc2 */ 	srl	$a1,$t6,0x1f
/*  f195d0c:	14400028 */ 	bnez	$v0,.PF0f195db0
/*  f195d10:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195d14:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f195d18:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f195d1c:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f195d20:	8f230024 */ 	lw	$v1,0x24($t9)
/*  f195d24:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195d28:	00054880 */ 	sll	$t1,$a1,0x2
/*  f195d2c:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f195d30:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d34:	0fc66abe */ 	jal	weaponGetClipCapacityByFunction
/*  f195d38:	afa302e8 */ 	sw	$v1,0x2e8($sp)
/*  f195d3c:	8fa302e8 */ 	lw	$v1,0x2e8($sp)
/*  f195d40:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195d44:	1c600008 */ 	bgtz	$v1,.PF0f195d68
/*  f195d48:	00000000 */ 	nop
/*  f195d4c:	18400006 */ 	blez	$v0,.PF0f195d68
/*  f195d50:	02802025 */ 	move	$a0,$s4
/*  f195d54:	02002825 */ 	move	$a1,$s0
/*  f195d58:	0fc651d3 */ 	jal	func0f19369c
/*  f195d5c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d60:	10000013 */ 	b	.PF0f195db0
/*  f195d64:	8fa70054 */ 	lw	$a3,0x54($sp)
.PF0f195d68:
/*  f195d68:	04410003 */ 	bgez	$v0,.PF0f195d78
/*  f195d6c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f195d70:	24410001 */ 	addiu	$at,$v0,0x1
/*  f195d74:	00015843 */ 	sra	$t3,$at,0x1
.PF0f195d78:
/*  f195d78:	006b082a */ 	slt	$at,$v1,$t3
/*  f195d7c:	5020000d */ 	beqzl	$at,.PF0f195db4
/*  f195d80:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195d84:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f195d88:	8e4c0124 */ 	lw	$t4,0x124($s2)
/*  f195d8c:	02802025 */ 	move	$a0,$s4
/*  f195d90:	25aeff9c */ 	addiu	$t6,$t5,-100
/*  f195d94:	018e082a */ 	slt	$at,$t4,$t6
/*  f195d98:	50200006 */ 	beqzl	$at,.PF0f195db4
/*  f195d9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195da0:	02002825 */ 	move	$a1,$s0
/*  f195da4:	0fc651d3 */ 	jal	func0f19369c
/*  f195da8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195dac:	8fa70054 */ 	lw	$a3,0x54($sp)
.PF0f195db0:
/*  f195db0:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f195db4:
/*  f195db4:	24010002 */ 	li	$at,0x2
/*  f195db8:	1601ffbe */ 	bne	$s0,$at,.PF0f195cb4
/*  f195dbc:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f195dc0:	8e4200cc */ 	lw	$v0,0xcc($s2)
/*  f195dc4:	58400045 */ 	blezl	$v0,.PF0f195edc
/*  f195dc8:	8e4d0020 */ 	lw	$t5,0x20($s2)
/*  f195dcc:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f195dd0:	02802025 */ 	move	$a0,$s4
/*  f195dd4:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f195dd8:	1f20003f */ 	bgtz	$t9,.PF0f195ed8
/*  f195ddc:	ae5900cc */ 	sw	$t9,0xcc($s2)
/*  f195de0:	0fc6637c */ 	jal	aibotGetInvItem
/*  f195de4:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f195de8:	00408025 */ 	move	$s0,$v0
/*  f195dec:	0fc4a571 */ 	jal	weaponGetModel
/*  f195df0:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195df4:	12000019 */ 	beqz	$s0,.PF0f195e5c
/*  f195df8:	00408825 */ 	move	$s1,$v0
/*  f195dfc:	04400017 */ 	bltz	$v0,.PF0f195e5c
/*  f195e00:	02802025 */ 	move	$a0,$s4
/*  f195e04:	00402825 */ 	move	$a1,$v0
/*  f195e08:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f195e0c:	0fc22e7f */ 	jal	chrGiveWeapon
/*  f195e10:	00003825 */ 	move	$a3,$zero
/*  f195e14:	02802025 */ 	move	$a0,$s4
/*  f195e18:	00002825 */ 	move	$a1,$zero
/*  f195e1c:	0fc66ad0 */ 	jal	aibotReloadWeapon
/*  f195e20:	00003025 */ 	move	$a2,$zero
/*  f195e24:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f195e28:	24010003 */ 	li	$at,0x3
/*  f195e2c:	02802025 */ 	move	$a0,$s4
/*  f195e30:	15210008 */ 	bne	$t1,$at,.PF0f195e54
/*  f195e34:	02202825 */ 	move	$a1,$s1
/*  f195e38:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f195e3c:	0fc22e7f */ 	jal	chrGiveWeapon
/*  f195e40:	3c071000 */ 	lui	$a3,0x1000
/*  f195e44:	02802025 */ 	move	$a0,$s4
/*  f195e48:	24050001 */ 	li	$a1,0x1
/*  f195e4c:	0fc66ad0 */ 	jal	aibotReloadWeapon
/*  f195e50:	00003025 */ 	move	$a2,$zero
.PF0f195e54:
/*  f195e54:	1000000e */ 	b	.PF0f195e90
/*  f195e58:	ae400034 */ 	sw	$zero,0x34($s2)
.PF0f195e5c:
/*  f195e5c:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f195e60:	24170001 */ 	li	$s7,0x1
/*  f195e64:	ad570020 */ 	sw	$s7,0x20($t2)
/*  f195e68:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f195e6c:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f195e70:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f195e74:	a06d004c */ 	sb	$t5,0x4c($v1)
/*  f195e78:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f195e7c:	906c004c */ 	lbu	$t4,0x4c($v1)
/*  f195e80:	318effbf */ 	andi	$t6,$t4,0xffbf
/*  f195e84:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f195e88:	a06f004c */ 	sb	$t7,0x4c($v1)
/*  f195e8c:	ae400034 */ 	sw	$zero,0x34($s2)
.PF0f195e90:
/*  f195e90:	02401025 */ 	move	$v0,$s2
/*  f195e94:	00001825 */ 	move	$v1,$zero
/*  f195e98:	02802025 */ 	move	$a0,$s4
/*  f195e9c:	24060008 */ 	li	$a2,0x8
.PF0f195ea0:
/*  f195ea0:	a440003c */ 	sh	$zero,0x3c($v0)
/*  f195ea4:	8c850170 */ 	lw	$a1,0x170($a0)
/*  f195ea8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f195eac:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f195eb0:	10a00007 */ 	beqz	$a1,.PF0f195ed0
/*  f195eb4:	00000000 */ 	nop
/*  f195eb8:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f195ebc:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f195ec0:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f195ec4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f195ec8:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f195ecc:	a16a005f */ 	sb	$t2,0x5f($t3)
.PF0f195ed0:
/*  f195ed0:	1466fff3 */ 	bne	$v1,$a2,.PF0f195ea0
/*  f195ed4:	24840004 */ 	addiu	$a0,$a0,0x4
.PF0f195ed8:
/*  f195ed8:	8e4d0020 */ 	lw	$t5,0x20($s2)
.PF0f195edc:
/*  f195edc:	2401001d */ 	li	$at,0x1d
/*  f195ee0:	24170001 */ 	li	$s7,0x1
/*  f195ee4:	55a10005 */ 	bnel	$t5,$at,.PF0f195efc
/*  f195ee8:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f195eec:	8e8e02d4 */ 	lw	$t6,0x2d4($s4)
/*  f195ef0:	240c03e7 */ 	li	$t4,0x3e7
/*  f195ef4:	adcc0024 */ 	sw	$t4,0x24($t6)
/*  f195ef8:	8e4f001c */ 	lw	$t7,0x1c($s2)
.PF0f195efc:
/*  f195efc:	8df80050 */ 	lw	$t8,0x50($t7)
/*  f195f00:	1b00000d */ 	blez	$t8,.PF0f195f38
/*  f195f04:	02802025 */ 	move	$a0,$s4
/*  f195f08:	0fc649bc */ 	jal	func0f191638
/*  f195f0c:	02e02825 */ 	move	$a1,$s7
/*  f195f10:	54400006 */ 	bnezl	$v0,.PF0f195f2c
/*  f195f14:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f195f18:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f195f1c:	2401002e */ 	li	$at,0x2e
/*  f195f20:	57210006 */ 	bnel	$t9,$at,.PF0f195f3c
/*  f195f24:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f195f28:	924a004c */ 	lbu	$t2,0x4c($s2)
.PF0f195f2c:
/*  f195f2c:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f195f30:	1000001e */ 	b	.PF0f195fac
/*  f195f34:	a24b004c */ 	sb	$t3,0x4c($s2)
.PF0f195f38:
/*  f195f38:	8e420210 */ 	lw	$v0,0x210($s2)
.PF0f195f3c:
/*  f195f3c:	240403e8 */ 	li	$a0,0x3e8
/*  f195f40:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f195f44:	00026142 */ 	srl	$t4,$v0,0x5
/*  f195f48:	0184001b */ 	divu	$zero,$t4,$a0
/*  f195f4c:	8da30050 */ 	lw	$v1,0x50($t5)
/*  f195f50:	00007010 */ 	mfhi	$t6
/*  f195f54:	25cf03e8 */ 	addiu	$t7,$t6,0x3e8
/*  f195f58:	14800002 */ 	bnez	$a0,.PF0f195f64
/*  f195f5c:	00000000 */ 	nop
/*  f195f60:	0007000d */ 	break	0x7
.PF0f195f64:
/*  f195f64:	01e3082b */ 	sltu	$at,$t7,$v1
/*  f195f68:	10200005 */ 	beqz	$at,.PF0f195f80
/*  f195f6c:	00025442 */ 	srl	$t2,$v0,0x11
/*  f195f70:	9259004c */ 	lbu	$t9,0x4c($s2)
/*  f195f74:	37290002 */ 	ori	$t1,$t9,0x2
/*  f195f78:	1000000c */ 	b	.PF0f195fac
/*  f195f7c:	a249004c */ 	sb	$t1,0x4c($s2)
.PF0f195f80:
/*  f195f80:	0144001b */ 	divu	$zero,$t2,$a0
/*  f195f84:	00005810 */ 	mfhi	$t3
/*  f195f88:	0163082b */ 	sltu	$at,$t3,$v1
/*  f195f8c:	14800002 */ 	bnez	$a0,.PF0f195f98
/*  f195f90:	00000000 */ 	nop
/*  f195f94:	0007000d */ 	break	0x7
.PF0f195f98:
/*  f195f98:	54200005 */ 	bnezl	$at,.PF0f195fb0
/*  f195f9c:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f195fa0:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f195fa4:	31acfffd */ 	andi	$t4,$t5,0xfffd
/*  f195fa8:	a24c004c */ 	sb	$t4,0x4c($s2)
.PF0f195fac:
/*  f195fac:	8e4e004c */ 	lw	$t6,0x4c($s2)
.PF0f195fb0:
/*  f195fb0:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f195fb4:	07020039 */ 	bltzl	$t8,.PF0f19609c
/*  f195fb8:	924b009c */ 	lbu	$t3,0x9c($s2)
/*  f195fbc:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f195fc0:	2401000d */ 	li	$at,0xd
/*  f195fc4:	02402025 */ 	move	$a0,$s2
/*  f195fc8:	17210033 */ 	bne	$t9,$at,.PF0f196098
/*  f195fcc:	2405000d */ 	li	$a1,0xd
/*  f195fd0:	00003025 */ 	move	$a2,$zero
/*  f195fd4:	0fc66b39 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f195fd8:	02e03825 */ 	move	$a3,$s7
/*  f195fdc:	00408025 */ 	move	$s0,$v0
/*  f195fe0:	02802025 */ 	move	$a0,$s4
/*  f195fe4:	0fc649bc */ 	jal	func0f191638
/*  f195fe8:	02e02825 */ 	move	$a1,$s7
/*  f195fec:	5040001a */ 	beqzl	$v0,.PF0f196058
/*  f195ff0:	8e4b0210 */ 	lw	$t3,0x210($s2)
/*  f195ff4:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f195ff8:	240100c8 */ 	li	$at,0xc8
/*  f195ffc:	00024982 */ 	srl	$t1,$v0,0x6
/*  f196000:	0121001b */ 	divu	$zero,$t1,$at
/*  f196004:	00005010 */ 	mfhi	$t2
/*  f196008:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f19600c:	0170082b */ 	sltu	$at,$t3,$s0
/*  f196010:	10200005 */ 	beqz	$at,.PF0f196028
/*  f196014:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f196018:	924c009c */ 	lbu	$t4,0x9c($s2)
/*  f19601c:	358e0020 */ 	ori	$t6,$t4,0x20
/*  f196020:	10000020 */ 	b	.PF0f1960a4
/*  f196024:	a24e009c */ 	sb	$t6,0x9c($s2)
.PF0f196028:
/*  f196028:	24010046 */ 	li	$at,0x46
/*  f19602c:	01e1001b */ 	divu	$zero,$t7,$at
/*  f196030:	0000c010 */ 	mfhi	$t8
/*  f196034:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f196038:	0330082b */ 	sltu	$at,$t9,$s0
/*  f19603c:	5420001a */ 	bnezl	$at,.PF0f1960a8
/*  f196040:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f196044:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196048:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f19604c:	10000015 */ 	b	.PF0f1960a4
/*  f196050:	a24a009c */ 	sb	$t2,0x9c($s2)
/*  f196054:	8e4b0210 */ 	lw	$t3,0x210($s2)
.PF0f196058:
/*  f196058:	240101f4 */ 	li	$at,0x1f4
/*  f19605c:	000b6b02 */ 	srl	$t5,$t3,0xc
/*  f196060:	01a1001b */ 	divu	$zero,$t5,$at
/*  f196064:	00006010 */ 	mfhi	$t4
/*  f196068:	258e012c */ 	addiu	$t6,$t4,0x12c
/*  f19606c:	01d0082b */ 	sltu	$at,$t6,$s0
/*  f196070:	50200006 */ 	beqzl	$at,.PF0f19608c
/*  f196074:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196078:	9258009c */ 	lbu	$t8,0x9c($s2)
/*  f19607c:	37190020 */ 	ori	$t9,$t8,0x20
/*  f196080:	10000008 */ 	b	.PF0f1960a4
/*  f196084:	a259009c */ 	sb	$t9,0x9c($s2)
/*  f196088:	9249009c */ 	lbu	$t1,0x9c($s2)
.PF0f19608c:
/*  f19608c:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f196090:	10000004 */ 	b	.PF0f1960a4
/*  f196094:	a24a009c */ 	sb	$t2,0x9c($s2)
.PF0f196098:
/*  f196098:	924b009c */ 	lbu	$t3,0x9c($s2)
.PF0f19609c:
/*  f19609c:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f1960a0:	a24d009c */ 	sb	$t5,0x9c($s2)
.PF0f1960a4:
/*  f1960a4:	8e4c0004 */ 	lw	$t4,0x4($s2)
.PF0f1960a8:
/*  f1960a8:	24010004 */ 	li	$at,0x4
/*  f1960ac:	918e0047 */ 	lbu	$t6,0x47($t4)
/*  f1960b0:	55c1000e */ 	bnel	$t6,$at,.PF0f1960ec
/*  f1960b4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960b8:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f1960bc:	241effff */ 	li	$s8,-1
/*  f1960c0:	53cf000a */ 	beql	$s8,$t7,.PF0f1960ec
/*  f1960c4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960c8:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f1960cc:	53000007 */ 	beqzl	$t8,.PF0f1960ec
/*  f1960d0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960d4:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f1960d8:	2401002f */ 	li	$at,0x2f
/*  f1960dc:	53210003 */ 	beql	$t9,$at,.PF0f1960ec
/*  f1960e0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960e4:	ae5700d8 */ 	sw	$s7,0xd8($s2)
/*  f1960e8:	824a004f */ 	lb	$t2,0x4f($s2)
.PF0f1960ec:
/*  f1960ec:	241effff */ 	li	$s8,-1
/*  f1960f0:	05430143 */ 	bgezl	$t2,.PF0f196600
/*  f1960f4:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f1960f8:	8e420118 */ 	lw	$v0,0x118($s2)
/*  f1960fc:	18400005 */ 	blez	$v0,.PF0f196114
/*  f196100:	00000000 */ 	nop
/*  f196104:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f196108:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f19610c:	ae4d0118 */ 	sw	$t5,0x118($s2)
/*  f196110:	01a01025 */ 	move	$v0,$t5
.PF0f196114:
/*  f196114:	5c40013a */ 	bgtzl	$v0,.PF0f196600
/*  f196118:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f19611c:	0fc655e3 */ 	jal	mpGetNumPlayerTeammates
/*  f196120:	02802025 */ 	move	$a0,$s4
/*  f196124:	3c03800b */ 	lui	$v1,0x800b
/*  f196128:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f19612c:	00409825 */ 	move	$s3,$v0
/*  f196130:	02802025 */ 	move	$a0,$s4
/*  f196134:	16e3001e */ 	bne	$s7,$v1,.PF0f1961b0
/*  f196138:	24010002 */ 	li	$at,0x2
/*  f19613c:	2405000b */ 	li	$a1,0xb
/*  f196140:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f196144:	00003025 */ 	move	$a2,$zero
/*  f196148:	18400010 */ 	blez	$v0,.PF0f19618c
/*  f19614c:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f196150:	05810003 */ 	bgez	$t4,.PF0f196160
/*  f196154:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196158:	25810001 */ 	addiu	$at,$t4,0x1
/*  f19615c:	00017043 */ 	sra	$t6,$at,0x1
.PF0f196160:
/*  f196160:	004e082a */ 	slt	$at,$v0,$t6
/*  f196164:	5420000a */ 	bnezl	$at,.PF0f196190
/*  f196168:	02802025 */ 	move	$a0,$s4
/*  f19616c:	0c004ad4 */ 	jal	random
/*  f196170:	00000000 */ 	nop
/*  f196174:	24010064 */ 	li	$at,0x64
/*  f196178:	0041001b */ 	divu	$zero,$v0,$at
/*  f19617c:	00007810 */ 	mfhi	$t7
/*  f196180:	2de10042 */ 	sltiu	$at,$t7,0x42
/*  f196184:	10200006 */ 	beqz	$at,.PF0f1961a0
/*  f196188:	02802025 */ 	move	$a0,$s4
.PF0f19618c:
/*  f19618c:	02802025 */ 	move	$a0,$s4
.PF0f196190:
/*  f196190:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196194:	2405000b */ 	li	$a1,0xb
/*  f196198:	10000111 */ 	b	.PF0f1965e0
/*  f19619c:	00000000 */ 	nop
.PF0f1961a0:
/*  f1961a0:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1961a4:	24050004 */ 	li	$a1,0x4
/*  f1961a8:	1000010d */ 	b	.PF0f1965e0
/*  f1961ac:	00000000 */ 	nop
.PF0f1961b0:
/*  f1961b0:	14610022 */ 	bne	$v1,$at,.PF0f19623c
/*  f1961b4:	02802025 */ 	move	$a0,$s4
/*  f1961b8:	24050005 */ 	li	$a1,0x5
/*  f1961bc:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f1961c0:	00003025 */ 	move	$a2,$zero
/*  f1961c4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f1961c8:	00184940 */ 	sll	$t1,$t8,0x5
/*  f1961cc:	05220013 */ 	bltzl	$t1,.PF0f19621c
/*  f1961d0:	02802025 */ 	move	$a0,$s4
/*  f1961d4:	18400010 */ 	blez	$v0,.PF0f196218
/*  f1961d8:	266a0001 */ 	addiu	$t2,$s3,0x1
/*  f1961dc:	05410003 */ 	bgez	$t2,.PF0f1961ec
/*  f1961e0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f1961e4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f1961e8:	00015843 */ 	sra	$t3,$at,0x1
.PF0f1961ec:
/*  f1961ec:	004b082a */ 	slt	$at,$v0,$t3
/*  f1961f0:	5420000a */ 	bnezl	$at,.PF0f19621c
/*  f1961f4:	02802025 */ 	move	$a0,$s4
/*  f1961f8:	0c004ad4 */ 	jal	random
/*  f1961fc:	00000000 */ 	nop
/*  f196200:	24010064 */ 	li	$at,0x64
/*  f196204:	0041001b */ 	divu	$zero,$v0,$at
/*  f196208:	00006810 */ 	mfhi	$t5
/*  f19620c:	2da10032 */ 	sltiu	$at,$t5,0x32
/*  f196210:	10200006 */ 	beqz	$at,.PF0f19622c
/*  f196214:	02802025 */ 	move	$a0,$s4
.PF0f196218:
/*  f196218:	02802025 */ 	move	$a0,$s4
.PF0f19621c:
/*  f19621c:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196220:	24050005 */ 	li	$a1,0x5
/*  f196224:	100000ee */ 	b	.PF0f1965e0
/*  f196228:	00000000 */ 	nop
.PF0f19622c:
/*  f19622c:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196230:	24050004 */ 	li	$a1,0x4
/*  f196234:	100000ea */ 	b	.PF0f1965e0
/*  f196238:	00000000 */ 	nop
.PF0f19623c:
/*  f19623c:	24010003 */ 	li	$at,0x3
/*  f196240:	1461001e */ 	bne	$v1,$at,.PF0f1962bc
/*  f196244:	02802025 */ 	move	$a0,$s4
/*  f196248:	2405000c */ 	li	$a1,0xc
/*  f19624c:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f196250:	00003025 */ 	move	$a2,$zero
/*  f196254:	18400010 */ 	blez	$v0,.PF0f196298
/*  f196258:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f19625c:	05810003 */ 	bgez	$t4,.PF0f19626c
/*  f196260:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196264:	25810001 */ 	addiu	$at,$t4,0x1
/*  f196268:	00017043 */ 	sra	$t6,$at,0x1
.PF0f19626c:
/*  f19626c:	004e082a */ 	slt	$at,$v0,$t6
/*  f196270:	5420000a */ 	bnezl	$at,.PF0f19629c
/*  f196274:	02802025 */ 	move	$a0,$s4
/*  f196278:	0c004ad4 */ 	jal	random
/*  f19627c:	00000000 */ 	nop
/*  f196280:	24010064 */ 	li	$at,0x64
/*  f196284:	0041001b */ 	divu	$zero,$v0,$at
/*  f196288:	00007810 */ 	mfhi	$t7
/*  f19628c:	2de10032 */ 	sltiu	$at,$t7,0x32
/*  f196290:	10200006 */ 	beqz	$at,.PF0f1962ac
/*  f196294:	02802025 */ 	move	$a0,$s4
.PF0f196298:
/*  f196298:	02802025 */ 	move	$a0,$s4
.PF0f19629c:
/*  f19629c:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1962a0:	2405000c */ 	li	$a1,0xc
/*  f1962a4:	100000ce */ 	b	.PF0f1965e0
/*  f1962a8:	00000000 */ 	nop
.PF0f1962ac:
/*  f1962ac:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1962b0:	24050004 */ 	li	$a1,0x4
/*  f1962b4:	100000ca */ 	b	.PF0f1965e0
/*  f1962b8:	00000000 */ 	nop
.PF0f1962bc:
/*  f1962bc:	24010004 */ 	li	$at,0x4
/*  f1962c0:	54610034 */ 	bnel	$v1,$at,.PF0f196394
/*  f1962c4:	24010005 */ 	li	$at,0x5
/*  f1962c8:	0fc6566f */ 	jal	mpGetNumTeammatesDefendingHill
/*  f1962cc:	02802025 */ 	move	$a0,$s4
/*  f1962d0:	8e98001c */ 	lw	$t8,0x1c($s4)
/*  f1962d4:	3c09800b */ 	lui	$t1,0x800b
/*  f1962d8:	8529c6be */ 	lh	$t1,-0x3942($t1)
/*  f1962dc:	87190028 */ 	lh	$t9,0x28($t8)
/*  f1962e0:	00408025 */ 	move	$s0,$v0
/*  f1962e4:	02802025 */ 	move	$a0,$s4
/*  f1962e8:	17290002 */ 	bne	$t9,$t1,.PF0f1962f4
/*  f1962ec:	00000000 */ 	nop
/*  f1962f0:	2450ffff */ 	addiu	$s0,$v0,-1
.PF0f1962f4:
/*  f1962f4:	1a000008 */ 	blez	$s0,.PF0f196318
/*  f1962f8:	00000000 */ 	nop
/*  f1962fc:	06610003 */ 	bgez	$s3,.PF0f19630c
/*  f196300:	00135043 */ 	sra	$t2,$s3,0x1
/*  f196304:	26610001 */ 	addiu	$at,$s3,0x1
/*  f196308:	00015043 */ 	sra	$t2,$at,0x1
.PF0f19630c:
/*  f19630c:	020a082a */ 	slt	$at,$s0,$t2
/*  f196310:	10200005 */ 	beqz	$at,.PF0f196328
/*  f196314:	00000000 */ 	nop
.PF0f196318:
/*  f196318:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f19631c:	2405000a */ 	li	$a1,0xa
/*  f196320:	100000af */ 	b	.PF0f1965e0
/*  f196324:	00000000 */ 	nop
.PF0f196328:
/*  f196328:	0fc65692 */ 	jal	mpGetNumOpponentsInHill
/*  f19632c:	02802025 */ 	move	$a0,$s4
/*  f196330:	0050082a */ 	slt	$at,$v0,$s0
/*  f196334:	10200012 */ 	beqz	$at,.PF0f196380
/*  f196338:	02802025 */ 	move	$a0,$s4
/*  f19633c:	0c004ad4 */ 	jal	random
/*  f196340:	00000000 */ 	nop
/*  f196344:	24010064 */ 	li	$at,0x64
/*  f196348:	0041001b */ 	divu	$zero,$v0,$at
/*  f19634c:	00005810 */ 	mfhi	$t3
/*  f196350:	2d610032 */ 	sltiu	$at,$t3,0x32
/*  f196354:	10200006 */ 	beqz	$at,.PF0f196370
/*  f196358:	02802025 */ 	move	$a0,$s4
/*  f19635c:	02802025 */ 	move	$a0,$s4
/*  f196360:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196364:	24050009 */ 	li	$a1,0x9
/*  f196368:	1000009d */ 	b	.PF0f1965e0
/*  f19636c:	00000000 */ 	nop
.PF0f196370:
/*  f196370:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196374:	24050004 */ 	li	$a1,0x4
/*  f196378:	10000099 */ 	b	.PF0f1965e0
/*  f19637c:	00000000 */ 	nop
.PF0f196380:
/*  f196380:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196384:	2405000a */ 	li	$a1,0xa
/*  f196388:	10000095 */ 	b	.PF0f1965e0
/*  f19638c:	00000000 */ 	nop
/*  f196390:	24010005 */ 	li	$at,0x5
.PF0f196394:
/*  f196394:	14610092 */ 	bne	$v1,$at,.PF0f1965e0
/*  f196398:	00000000 */ 	nop
/*  f19639c:	14570035 */ 	bne	$v0,$s7,.PF0f196474
/*  f1963a0:	02802025 */ 	move	$a0,$s4
/*  f1963a4:	02802025 */ 	move	$a0,$s4
/*  f1963a8:	24050006 */ 	li	$a1,0x6
/*  f1963ac:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f1963b0:	02e03025 */ 	move	$a2,$s7
/*  f1963b4:	00408025 */ 	move	$s0,$v0
/*  f1963b8:	0fc65655 */ 	jal	func0f19489c
/*  f1963bc:	02802025 */ 	move	$a0,$s4
/*  f1963c0:	10400005 */ 	beqz	$v0,.PF0f1963d8
/*  f1963c4:	02802025 */ 	move	$a0,$s4
/*  f1963c8:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1963cc:	24050006 */ 	li	$a1,0x6
/*  f1963d0:	10000083 */ 	b	.PF0f1965e0
/*  f1963d4:	00000000 */ 	nop
.PF0f1963d8:
/*  f1963d8:	0fc6563b */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f1963dc:	02802025 */ 	move	$a0,$s4
/*  f1963e0:	10400012 */ 	beqz	$v0,.PF0f19642c
/*  f1963e4:	00000000 */ 	nop
/*  f1963e8:	0c004ad4 */ 	jal	random
/*  f1963ec:	00000000 */ 	nop
/*  f1963f0:	24010064 */ 	li	$at,0x64
/*  f1963f4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1963f8:	00006810 */ 	mfhi	$t5
/*  f1963fc:	2da1001e */ 	sltiu	$at,$t5,0x1e
/*  f196400:	10200006 */ 	beqz	$at,.PF0f19641c
/*  f196404:	02802025 */ 	move	$a0,$s4
/*  f196408:	02802025 */ 	move	$a0,$s4
/*  f19640c:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196410:	24050006 */ 	li	$a1,0x6
/*  f196414:	10000072 */ 	b	.PF0f1965e0
/*  f196418:	00000000 */ 	nop
.PF0f19641c:
/*  f19641c:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196420:	24050008 */ 	li	$a1,0x8
/*  f196424:	1000006e */ 	b	.PF0f1965e0
/*  f196428:	00000000 */ 	nop
.PF0f19642c:
/*  f19642c:	0c004ad4 */ 	jal	random
/*  f196430:	00000000 */ 	nop
/*  f196434:	24010064 */ 	li	$at,0x64
/*  f196438:	0041001b */ 	divu	$zero,$v0,$at
/*  f19643c:	00006010 */ 	mfhi	$t4
/*  f196440:	2d810046 */ 	sltiu	$at,$t4,0x46
/*  f196444:	14200003 */ 	bnez	$at,.PF0f196454
/*  f196448:	02802025 */ 	move	$a0,$s4
/*  f19644c:	1e000005 */ 	bgtz	$s0,.PF0f196464
/*  f196450:	24050008 */ 	li	$a1,0x8
.PF0f196454:
/*  f196454:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196458:	24050006 */ 	li	$a1,0x6
/*  f19645c:	10000060 */ 	b	.PF0f1965e0
/*  f196460:	00000000 */ 	nop
.PF0f196464:
/*  f196464:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196468:	02802025 */ 	move	$a0,$s4
/*  f19646c:	1000005c */ 	b	.PF0f1965e0
/*  f196470:	00000000 */ 	nop
.PF0f196474:
/*  f196474:	24050006 */ 	li	$a1,0x6
/*  f196478:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f19647c:	00003025 */ 	move	$a2,$zero
/*  f196480:	00408825 */ 	move	$s1,$v0
/*  f196484:	02802025 */ 	move	$a0,$s4
/*  f196488:	24050008 */ 	li	$a1,0x8
/*  f19648c:	0fc655f7 */ 	jal	mpCountAibotsWithCommand
/*  f196490:	00003025 */ 	move	$a2,$zero
/*  f196494:	00408025 */ 	move	$s0,$v0
/*  f196498:	0fc65655 */ 	jal	func0f19489c
/*  f19649c:	02802025 */ 	move	$a0,$s4
/*  f1964a0:	10400005 */ 	beqz	$v0,.PF0f1964b8
/*  f1964a4:	02802025 */ 	move	$a0,$s4
/*  f1964a8:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1964ac:	24050006 */ 	li	$a1,0x6
/*  f1964b0:	1000004b */ 	b	.PF0f1965e0
/*  f1964b4:	00000000 */ 	nop
.PF0f1964b8:
/*  f1964b8:	0fc6563b */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f1964bc:	02802025 */ 	move	$a0,$s4
/*  f1964c0:	10400014 */ 	beqz	$v0,.PF0f196514
/*  f1964c4:	00000000 */ 	nop
/*  f1964c8:	5a00000a */ 	blezl	$s0,.PF0f1964f4
/*  f1964cc:	02802025 */ 	move	$a0,$s4
/*  f1964d0:	0c004ad4 */ 	jal	random
/*  f1964d4:	00000000 */ 	nop
/*  f1964d8:	24010064 */ 	li	$at,0x64
/*  f1964dc:	0041001b */ 	divu	$zero,$v0,$at
/*  f1964e0:	00007010 */ 	mfhi	$t6
/*  f1964e4:	2dc10046 */ 	sltiu	$at,$t6,0x46
/*  f1964e8:	10200006 */ 	beqz	$at,.PF0f196504
/*  f1964ec:	02802025 */ 	move	$a0,$s4
/*  f1964f0:	02802025 */ 	move	$a0,$s4
.PF0f1964f4:
/*  f1964f4:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1964f8:	24050008 */ 	li	$a1,0x8
/*  f1964fc:	10000038 */ 	b	.PF0f1965e0
/*  f196500:	00000000 */ 	nop
.PF0f196504:
/*  f196504:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196508:	24050006 */ 	li	$a1,0x6
/*  f19650c:	10000034 */ 	b	.PF0f1965e0
/*  f196510:	00000000 */ 	nop
.PF0f196514:
/*  f196514:	1a200005 */ 	blez	$s1,.PF0f19652c
/*  f196518:	24010003 */ 	li	$at,0x3
/*  f19651c:	0261001a */ 	div	$zero,$s3,$at
/*  f196520:	00007812 */ 	mflo	$t7
/*  f196524:	022f082a */ 	slt	$at,$s1,$t7
/*  f196528:	10200005 */ 	beqz	$at,.PF0f196540
.PF0f19652c:
/*  f19652c:	02802025 */ 	move	$a0,$s4
/*  f196530:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196534:	24050006 */ 	li	$a1,0x6
/*  f196538:	10000029 */ 	b	.PF0f1965e0
/*  f19653c:	00000000 */ 	nop
.PF0f196540:
/*  f196540:	1a000008 */ 	blez	$s0,.PF0f196564
/*  f196544:	02802025 */ 	move	$a0,$s4
/*  f196548:	06610003 */ 	bgez	$s3,.PF0f196558
/*  f19654c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f196550:	26610003 */ 	addiu	$at,$s3,0x3
/*  f196554:	0001c083 */ 	sra	$t8,$at,0x2
.PF0f196558:
/*  f196558:	0218082a */ 	slt	$at,$s0,$t8
/*  f19655c:	10200005 */ 	beqz	$at,.PF0f196574
/*  f196560:	00000000 */ 	nop
.PF0f196564:
/*  f196564:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196568:	24050008 */ 	li	$a1,0x8
/*  f19656c:	1000001c */ 	b	.PF0f1965e0
/*  f196570:	00000000 */ 	nop
.PF0f196574:
/*  f196574:	0c004ad4 */ 	jal	random
/*  f196578:	00000000 */ 	nop
/*  f19657c:	24010064 */ 	li	$at,0x64
/*  f196580:	0041001b */ 	divu	$zero,$v0,$at
/*  f196584:	0000c810 */ 	mfhi	$t9
/*  f196588:	2f21001e */ 	sltiu	$at,$t9,0x1e
/*  f19658c:	10200005 */ 	beqz	$at,.PF0f1965a4
/*  f196590:	02802025 */ 	move	$a0,$s4
/*  f196594:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f196598:	24050006 */ 	li	$a1,0x6
/*  f19659c:	10000010 */ 	b	.PF0f1965e0
/*  f1965a0:	00000000 */ 	nop
.PF0f1965a4:
/*  f1965a4:	0c004ad4 */ 	jal	random
/*  f1965a8:	00000000 */ 	nop
/*  f1965ac:	24010064 */ 	li	$at,0x64
/*  f1965b0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1965b4:	00004810 */ 	mfhi	$t1
/*  f1965b8:	2d21001e */ 	sltiu	$at,$t1,0x1e
/*  f1965bc:	10200006 */ 	beqz	$at,.PF0f1965d8
/*  f1965c0:	02802025 */ 	move	$a0,$s4
/*  f1965c4:	02802025 */ 	move	$a0,$s4
/*  f1965c8:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1965cc:	24050008 */ 	li	$a1,0x8
/*  f1965d0:	10000003 */ 	b	.PF0f1965e0
/*  f1965d4:	00000000 */ 	nop
.PF0f1965d8:
/*  f1965d8:	0fc64db2 */ 	jal	mpAibotApplyScenarioCommand
/*  f1965dc:	24050004 */ 	li	$a1,0x4
.PF0f1965e0:
/*  f1965e0:	0c004ad4 */ 	jal	random
/*  f1965e4:	00000000 */ 	nop
/*  f1965e8:	240107d0 */ 	li	$at,0x7d0
/*  f1965ec:	0041001b */ 	divu	$zero,$v0,$at
/*  f1965f0:	00005010 */ 	mfhi	$t2
/*  f1965f4:	254b03e8 */ 	addiu	$t3,$t2,0x3e8
/*  f1965f8:	ae4b0118 */ 	sw	$t3,0x118($s2)
/*  f1965fc:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
.PF0f196600:
/*  f196600:	24010029 */ 	li	$at,0x29
/*  f196604:	51a10005 */ 	beql	$t5,$at,.PF0f19661c
/*  f196608:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f19660c:	8e4c00d8 */ 	lw	$t4,0xd8($s2)
/*  f196610:	1180039a */ 	beqz	$t4,.PF0f19747c
/*  f196614:	00000000 */ 	nop
/*  f196618:	8e4e0004 */ 	lw	$t6,0x4($s2)
.PF0f19661c:
/*  f19661c:	ae4000d8 */ 	sw	$zero,0xd8($s2)
/*  f196620:	a65e0008 */ 	sh	$s8,0x8($s2)
/*  f196624:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f196628:	24010004 */ 	li	$at,0x4
/*  f19662c:	15e1000e */ 	bne	$t7,$at,.PF0f196668
/*  f196630:	00000000 */ 	nop
/*  f196634:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f196638:	13d8000b */ 	beq	$s8,$t8,.PF0f196668
/*  f19663c:	00000000 */ 	nop
/*  f196640:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f196644:	02802025 */ 	move	$a0,$s4
/*  f196648:	13200007 */ 	beqz	$t9,.PF0f196668
/*  f19664c:	00000000 */ 	nop
/*  f196650:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196654:	2415002f */ 	li	$s5,0x2f
/*  f196658:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f19665c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196660:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196664:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f196668:
/*  f196668:	06a10006 */ 	bgez	$s5,.PF0f196684
/*  f19666c:	00000000 */ 	nop
/*  f196670:	0fc655d3 */ 	jal	func0f194694
/*  f196674:	02802025 */ 	move	$a0,$s4
/*  f196678:	10400002 */ 	beqz	$v0,.PF0f196684
/*  f19667c:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f196680:	2415002a */ 	li	$s5,0x2a
.PF0f196684:
/*  f196684:	06a10240 */ 	bgez	$s5,.PF0f196f88
/*  f196688:	00000000 */ 	nop
/*  f19668c:	92420079 */ 	lbu	$v0,0x79($s2)
/*  f196690:	16e20019 */ 	bne	$s7,$v0,.PF0f1966f8
/*  f196694:	00000000 */ 	nop
/*  f196698:	8e4900c0 */ 	lw	$t1,0xc0($s2)
/*  f19669c:	8ecb0338 */ 	lw	$t3,0x338($s6)
/*  f1966a0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1966a4:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1966a8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1966ac:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f1966b0:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f1966b4:	0fc0e706 */ 	jal	chrIsDead
/*  f1966b8:	02002025 */ 	move	$a0,$s0
/*  f1966bc:	14400232 */ 	bnez	$v0,.PF0f196f88
/*  f1966c0:	02802025 */ 	move	$a0,$s4
/*  f1966c4:	0fc64e81 */ 	jal	func0f19294c
/*  f1966c8:	02002825 */ 	move	$a1,$s0
/*  f1966cc:	1440022e */ 	bnez	$v0,.PF0f196f88
/*  f1966d0:	02802025 */ 	move	$a0,$s4
/*  f1966d4:	0fc64f9c */ 	jal	func0f192dc0
/*  f1966d8:	02002825 */ 	move	$a1,$s0
/*  f1966dc:	1040022a */ 	beqz	$v0,.PF0f196f88
/*  f1966e0:	02002025 */ 	move	$a0,$s0
/*  f1966e4:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1966e8:	2415002f */ 	li	$s5,0x2f
/*  f1966ec:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1966f0:	10000225 */ 	b	.PF0f196f88
/*  f1966f4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1966f8:
/*  f1966f8:	1440000d */ 	bnez	$v0,.PF0f196730
/*  f1966fc:	2401000d */ 	li	$at,0xd
/*  f196700:	8e4c00d4 */ 	lw	$t4,0xd4($s2)
/*  f196704:	ae5701e0 */ 	sw	$s7,0x1e0($s2)
/*  f196708:	8ecf0338 */ 	lw	$t7,0x338($s6)
/*  f19670c:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f196710:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f196714:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f196718:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19671c:	24150032 */ 	li	$s5,0x32
/*  f196720:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196724:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f196728:	10000217 */ 	b	.PF0f196f88
/*  f19672c:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196730:
/*  f196730:	5441000e */ 	bnel	$v0,$at,.PF0f19676c
/*  f196734:	24010002 */ 	li	$at,0x2
/*  f196738:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*  f19673c:	ae4001e0 */ 	sw	$zero,0x1e0($s2)
/*  f196740:	8eca0338 */ 	lw	$t2,0x338($s6)
/*  f196744:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f196748:	01394821 */ 	addu	$t1,$t1,$t9
/*  f19674c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f196750:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f196754:	24150032 */ 	li	$s5,0x32
/*  f196758:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f19675c:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f196760:	10000209 */ 	b	.PF0f196f88
/*  f196764:	a642000a */ 	sh	$v0,0xa($s2)
/*  f196768:	24010002 */ 	li	$at,0x2
.PF0f19676c:
/*  f19676c:	54410005 */ 	bnel	$v0,$at,.PF0f196784
/*  f196770:	24010003 */ 	li	$at,0x3
/*  f196774:	24150033 */ 	li	$s5,0x33
/*  f196778:	10000203 */ 	b	.PF0f196f88
/*  f19677c:	ae5701dc */ 	sw	$s7,0x1dc($s2)
/*  f196780:	24010003 */ 	li	$at,0x3
.PF0f196784:
/*  f196784:	54410005 */ 	bnel	$v0,$at,.PF0f19679c
/*  f196788:	24010006 */ 	li	$at,0x6
/*  f19678c:	24150033 */ 	li	$s5,0x33
/*  f196790:	100001fd */ 	b	.PF0f196f88
/*  f196794:	ae4001dc */ 	sw	$zero,0x1dc($s2)
/*  f196798:	24010006 */ 	li	$at,0x6
.PF0f19679c:
/*  f19679c:	14410089 */ 	bne	$v0,$at,.PF0f1969c4
/*  f1967a0:	3c0d800b */ 	lui	$t5,0x800b
/*  f1967a4:	91add138 */ 	lbu	$t5,-0x2ec8($t5)
/*  f1967a8:	24010005 */ 	li	$at,0x5
/*  f1967ac:	15a10083 */ 	bne	$t5,$at,.PF0f1969bc
/*  f1967b0:	00000000 */ 	nop
/*  f1967b4:	8e4c009c */ 	lw	$t4,0x9c($s2)
/*  f1967b8:	000c7840 */ 	sll	$t7,$t4,0x1
/*  f1967bc:	05e0007f */ 	bltz	$t7,.PF0f1969bc
/*  f1967c0:	00000000 */ 	nop
/*  f1967c4:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1967c8:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1967cc:	3c07800b */ 	lui	$a3,0x800b
/*  f1967d0:	00003025 */ 	move	$a2,$zero
/*  f1967d4:	24e7c6b0 */ 	addiu	$a3,$a3,-14672
/*  f1967d8:	00002825 */ 	move	$a1,$zero
/*  f1967dc:	27b00298 */ 	addiu	$s0,$sp,0x298
/*  f1967e0:	24080003 */ 	li	$t0,0x3
.PF0f1967e4:
/*  f1967e4:	10a20020 */ 	beq	$a1,$v0,.PF0f196868
/*  f1967e8:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f1967ec:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1967f0:	87290000 */ 	lh	$t1,0x0($t9)
/*  f1967f4:	00055080 */ 	sll	$t2,$a1,0x2
/*  f1967f8:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f1967fc:	5120001b */ 	beqzl	$t1,.PF0f19686c
/*  f196800:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f196804:	8d640058 */ 	lw	$a0,0x58($t3)
/*  f196808:	24010004 */ 	li	$at,0x4
/*  f19680c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f196810:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f196814:	020d6021 */ 	addu	$t4,$s0,$t5
/*  f196818:	50610004 */ 	beql	$v1,$at,.PF0f19682c
/*  f19681c:	ad840000 */ 	sw	$a0,0x0($t4)
/*  f196820:	16e30004 */ 	bne	$s7,$v1,.PF0f196834
/*  f196824:	00000000 */ 	nop
/*  f196828:	ad840000 */ 	sw	$a0,0x0($t4)
.PF0f19682c:
/*  f19682c:	1000000e */ 	b	.PF0f196868
/*  f196830:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f196834:
/*  f196834:	11030003 */ 	beq	$t0,$v1,.PF0f196844
/*  f196838:	24010006 */ 	li	$at,0x6
/*  f19683c:	5461000b */ 	bnel	$v1,$at,.PF0f19686c
/*  f196840:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f196844:
/*  f196844:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f196848:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f19684c:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f196850:	906f0125 */ 	lbu	$t7,0x125($v1)
/*  f196854:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f196858:	55cf0004 */ 	bnel	$t6,$t7,.PF0f19686c
/*  f19685c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f196860:	af240000 */ 	sw	$a0,0x0($t9)
/*  f196864:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f196868:
/*  f196868:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f19686c:
/*  f19686c:	24010004 */ 	li	$at,0x4
/*  f196870:	14a1ffdc */ 	bne	$a1,$at,.PF0f1967e4
/*  f196874:	00000000 */ 	nop
/*  f196878:	18c00050 */ 	blez	$a2,.PF0f1969bc
/*  f19687c:	00000000 */ 	nop
/*  f196880:	0c004ad4 */ 	jal	random
/*  f196884:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f196888:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f19688c:	0046001b */ 	divu	$zero,$v0,$a2
/*  f196890:	00002010 */ 	mfhi	$a0
/*  f196894:	24890001 */ 	addiu	$t1,$a0,0x1
/*  f196898:	00808825 */ 	move	$s1,$a0
/*  f19689c:	0126001a */ 	div	$zero,$t1,$a2
/*  f1968a0:	00001810 */ 	mfhi	$v1
/*  f1968a4:	14c00002 */ 	bnez	$a2,.PF0f1968b0
/*  f1968a8:	00000000 */ 	nop
/*  f1968ac:	0007000d */ 	break	0x7
.PF0f1968b0:
/*  f1968b0:	14c00002 */ 	bnez	$a2,.PF0f1968bc
/*  f1968b4:	00000000 */ 	nop
/*  f1968b8:	0007000d */ 	break	0x7
.PF0f1968bc:
/*  f1968bc:	2401ffff */ 	li	$at,-1
/*  f1968c0:	14c10004 */ 	bne	$a2,$at,.PF0f1968d4
/*  f1968c4:	3c018000 */ 	lui	$at,0x8000
/*  f1968c8:	15210002 */ 	bne	$t1,$at,.PF0f1968d4
/*  f1968cc:	00000000 */ 	nop
/*  f1968d0:	0006000d */ 	break	0x6
.PF0f1968d4:
/*  f1968d4:	00035080 */ 	sll	$t2,$v1,0x2
.PF0f1968d8:
/*  f1968d8:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f1968dc:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f1968e0:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f1968e4:	afa30288 */ 	sw	$v1,0x288($sp)
/*  f1968e8:	02802025 */ 	move	$a0,$s4
/*  f1968ec:	0fc125bb */ 	jal	chrGetSquaredDistanceToCoord
/*  f1968f0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f1968f4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1968f8:	c424a5b4 */ 	lwc1	$f4,-0x5a4c($at)
/*  f1968fc:	8fa30288 */ 	lw	$v1,0x288($sp)
/*  f196900:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f196904:	4604003c */ 	c.lt.s	$f0,$f4
/*  f196908:	246d0001 */ 	addiu	$t5,$v1,0x1
/*  f19690c:	45000003 */ 	bc1f	.PF0f19691c
/*  f196910:	00000000 */ 	nop
/*  f196914:	10000010 */ 	b	.PF0f196958
/*  f196918:	00608825 */ 	move	$s1,$v1
.PF0f19691c:
/*  f19691c:	5071000f */ 	beql	$v1,$s1,.PF0f19695c
/*  f196920:	00116080 */ 	sll	$t4,$s1,0x2
/*  f196924:	01a6001a */ 	div	$zero,$t5,$a2
/*  f196928:	00001810 */ 	mfhi	$v1
/*  f19692c:	14c00002 */ 	bnez	$a2,.PF0f196938
/*  f196930:	00000000 */ 	nop
/*  f196934:	0007000d */ 	break	0x7
.PF0f196938:
/*  f196938:	2401ffff */ 	li	$at,-1
/*  f19693c:	14c10004 */ 	bne	$a2,$at,.PF0f196950
/*  f196940:	3c018000 */ 	lui	$at,0x8000
/*  f196944:	15a10002 */ 	bne	$t5,$at,.PF0f196950
/*  f196948:	00000000 */ 	nop
/*  f19694c:	0006000d */ 	break	0x6
.PF0f196950:
/*  f196950:	1000ffe1 */ 	b	.PF0f1968d8
/*  f196954:	00035080 */ 	sll	$t2,$v1,0x2
.PF0f196958:
/*  f196958:	00116080 */ 	sll	$t4,$s1,0x2
.PF0f19695c:
/*  f19695c:	020c9821 */ 	addu	$s3,$s0,$t4
/*  f196960:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f196964:	24010004 */ 	li	$at,0x4
/*  f196968:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f19696c:	50610004 */ 	beql	$v1,$at,.PF0f196980
/*  f196970:	2415002a */ 	li	$s5,0x2a
/*  f196974:	16e30004 */ 	bne	$s7,$v1,.PF0f196988
/*  f196978:	02802025 */ 	move	$a0,$s4
/*  f19697c:	2415002a */ 	li	$s5,0x2a
.PF0f196980:
/*  f196980:	10000181 */ 	b	.PF0f196f88
/*  f196984:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196988:
/*  f196988:	0fc65163 */ 	jal	mpIsChrFollowedByChr
/*  f19698c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196990:	1040000a */ 	beqz	$v0,.PF0f1969bc
/*  f196994:	00000000 */ 	nop
/*  f196998:	0c004ad4 */ 	jal	random
/*  f19699c:	24150032 */ 	li	$s5,0x32
/*  f1969a0:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f1969a4:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f1969a8:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f1969ac:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f1969b0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1969b4:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f1969b8:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f1969bc:
/*  f1969bc:	10000172 */ 	b	.PF0f196f88
/*  f1969c0:	00000000 */ 	nop
.PF0f1969c4:
/*  f1969c4:	24010008 */ 	li	$at,0x8
/*  f1969c8:	14410043 */ 	bne	$v0,$at,.PF0f196ad8
/*  f1969cc:	3c19800b */ 	lui	$t9,0x800b
/*  f1969d0:	9339d138 */ 	lbu	$t9,-0x2ec8($t9)
/*  f1969d4:	24010005 */ 	li	$at,0x5
/*  f1969d8:	1721016b */ 	bne	$t9,$at,.PF0f196f88
/*  f1969dc:	00000000 */ 	nop
/*  f1969e0:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1969e4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1969e8:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1969ec:	3c03800b */ 	lui	$v1,0x800b
/*  f1969f0:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1969f4:	8c63c708 */ 	lw	$v1,-0x38f8($v1)
/*  f1969f8:	24010003 */ 	li	$at,0x3
/*  f1969fc:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f196a00:	10810003 */ 	beq	$a0,$at,.PF0f196a10
/*  f196a04:	24010006 */ 	li	$at,0x6
/*  f196a08:	54810026 */ 	bnel	$a0,$at,.PF0f196aa4
/*  f196a0c:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PF0f196a10:
/*  f196a10:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f196a14:	928a0125 */ 	lbu	$t2,0x125($s4)
/*  f196a18:	02802025 */ 	move	$a0,$s4
/*  f196a1c:	920b0125 */ 	lbu	$t3,0x125($s0)
/*  f196a20:	154b000e */ 	bne	$t2,$t3,.PF0f196a5c
/*  f196a24:	00000000 */ 	nop
/*  f196a28:	0fc65163 */ 	jal	mpIsChrFollowedByChr
/*  f196a2c:	02002825 */ 	move	$a1,$s0
/*  f196a30:	10400155 */ 	beqz	$v0,.PF0f196f88
/*  f196a34:	00000000 */ 	nop
/*  f196a38:	0c004ad4 */ 	jal	random
/*  f196a3c:	24150032 */ 	li	$s5,0x32
/*  f196a40:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f196a44:	2dac0001 */ 	sltiu	$t4,$t5,0x1
/*  f196a48:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f196a4c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196a50:	02002025 */ 	move	$a0,$s0
/*  f196a54:	1000014c */ 	b	.PF0f196f88
/*  f196a58:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196a5c:
/*  f196a5c:	0fc0e706 */ 	jal	chrIsDead
/*  f196a60:	02002025 */ 	move	$a0,$s0
/*  f196a64:	14400148 */ 	bnez	$v0,.PF0f196f88
/*  f196a68:	02802025 */ 	move	$a0,$s4
/*  f196a6c:	0fc64e81 */ 	jal	func0f19294c
/*  f196a70:	02002825 */ 	move	$a1,$s0
/*  f196a74:	14400144 */ 	bnez	$v0,.PF0f196f88
/*  f196a78:	02802025 */ 	move	$a0,$s4
/*  f196a7c:	0fc64f9c */ 	jal	func0f192dc0
/*  f196a80:	02002825 */ 	move	$a1,$s0
/*  f196a84:	10400140 */ 	beqz	$v0,.PF0f196f88
/*  f196a88:	02002025 */ 	move	$a0,$s0
/*  f196a8c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196a90:	2415002f */ 	li	$s5,0x2f
/*  f196a94:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196a98:	1000013b */ 	b	.PF0f196f88
/*  f196a9c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196aa0:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PF0f196aa4:
/*  f196aa4:	2415002b */ 	li	$s5,0x2b
/*  f196aa8:	24640028 */ 	addiu	$a0,$v1,0x28
/*  f196aac:	e64800ec */ 	swc1	$f8,0xec($s2)
/*  f196ab0:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f196ab4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196ab8:	e64600f0 */ 	swc1	$f6,0xf0($s2)
/*  f196abc:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f196ac0:	0fc1968d */ 	jal	roomsCopy
/*  f196ac4:	e64a00f4 */ 	swc1	$f10,0xf4($s2)
/*  f196ac8:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f196acc:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f196ad0:	1000012d */ 	b	.PF0f196f88
/*  f196ad4:	a24f004c */ 	sb	$t7,0x4c($s2)
.PF0f196ad8:
/*  f196ad8:	24010009 */ 	li	$at,0x9
/*  f196adc:	14410048 */ 	bne	$v0,$at,.PF0f196c00
/*  f196ae0:	3c18800b */ 	lui	$t8,0x800b
/*  f196ae4:	9318d138 */ 	lbu	$t8,-0x2ec8($t8)
/*  f196ae8:	24010004 */ 	li	$at,0x4
/*  f196aec:	17010126 */ 	bne	$t8,$at,.PF0f196f88
/*  f196af0:	00000000 */ 	nop
/*  f196af4:	8e99001c */ 	lw	$t9,0x1c($s4)
/*  f196af8:	3c0a800b */ 	lui	$t2,0x800b
/*  f196afc:	854ac6be */ 	lh	$t2,-0x3942($t2)
/*  f196b00:	87290028 */ 	lh	$t1,0x28($t9)
/*  f196b04:	152a0016 */ 	bne	$t1,$t2,.PF0f196b60
/*  f196b08:	00000000 */ 	nop
/*  f196b0c:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f196b10:	13cb0013 */ 	beq	$s8,$t3,.PF0f196b60
/*  f196b14:	00000000 */ 	nop
/*  f196b18:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f196b1c:	11a00010 */ 	beqz	$t5,.PF0f196b60
/*  f196b20:	00000000 */ 	nop
/*  f196b24:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196b28:	02802025 */ 	move	$a0,$s4
/*  f196b2c:	02802025 */ 	move	$a0,$s4
/*  f196b30:	0fc64f9c */ 	jal	func0f192dc0
/*  f196b34:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196b38:	10400009 */ 	beqz	$v0,.PF0f196b60
/*  f196b3c:	02802025 */ 	move	$a0,$s4
/*  f196b40:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196b44:	2415002f */ 	li	$s5,0x2f
/*  f196b48:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196b4c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196b50:	240c00fa */ 	li	$t4,0xfa
/*  f196b54:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196b58:	1000010b */ 	b	.PF0f196f88
/*  f196b5c:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
.PF0f196b60:
/*  f196b60:	3c04800b */ 	lui	$a0,0x800b
/*  f196b64:	27ae0260 */ 	addiu	$t6,$sp,0x260
/*  f196b68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f196b6c:	8484c6be */ 	lh	$a0,-0x3942($a0)
/*  f196b70:	27a5026c */ 	addiu	$a1,$sp,0x26c
/*  f196b74:	27a60268 */ 	addiu	$a2,$sp,0x268
/*  f196b78:	0fc66f1c */ 	jal	func0f19ab70
/*  f196b7c:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f196b80:	10400101 */ 	beqz	$v0,.PF0f196f88
/*  f196b84:	c7b2026c */ 	lwc1	$f18,0x26c($sp)
/*  f196b88:	e65200ec */ 	swc1	$f18,0xec($s2)
/*  f196b8c:	c7a40270 */ 	lwc1	$f4,0x270($sp)
/*  f196b90:	3c04800b */ 	lui	$a0,0x800b
/*  f196b94:	2415002b */ 	li	$s5,0x2b
/*  f196b98:	e64400f0 */ 	swc1	$f4,0xf0($s2)
/*  f196b9c:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f196ba0:	2484c6be */ 	addiu	$a0,$a0,-14658
/*  f196ba4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196ba8:	0fc1968d */ 	jal	roomsCopy
/*  f196bac:	e64800f4 */ 	swc1	$f8,0xf4($s2)
/*  f196bb0:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f196bb4:	3c19800b */ 	lui	$t9,0x800b
/*  f196bb8:	8739c6be */ 	lh	$t9,-0x3942($t9)
/*  f196bbc:	85f80028 */ 	lh	$t8,0x28($t7)
/*  f196bc0:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f196bc4:	3c0a800b */ 	lui	$t2,0x800b
/*  f196bc8:	03194826 */ 	xor	$t1,$t8,$t9
/*  f196bcc:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  f196bd0:	0009582b */ 	sltu	$t3,$zero,$t1
/*  f196bd4:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f196bd8:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f196bdc:	018fc025 */ 	or	$t8,$t4,$t7
/*  f196be0:	a258004c */ 	sb	$t8,0x4c($s2)
/*  f196be4:	8fb90264 */ 	lw	$t9,0x264($sp)
/*  f196be8:	a6590048 */ 	sh	$t9,0x48($s2)
/*  f196bec:	8fa90260 */ 	lw	$t1,0x260($sp)
/*  f196bf0:	a649004a */ 	sh	$t1,0x4a($s2)
/*  f196bf4:	854ac6be */ 	lh	$t2,-0x3942($t2)
/*  f196bf8:	100000e3 */ 	b	.PF0f196f88
/*  f196bfc:	ae4a00bc */ 	sw	$t2,0xbc($s2)
.PF0f196c00:
/*  f196c00:	2401000a */ 	li	$at,0xa
/*  f196c04:	1441002c */ 	bne	$v0,$at,.PF0f196cb8
/*  f196c08:	3c0b800b */ 	lui	$t3,0x800b
/*  f196c0c:	916bd138 */ 	lbu	$t3,-0x2ec8($t3)
/*  f196c10:	24010004 */ 	li	$at,0x4
/*  f196c14:	3c04800b */ 	lui	$a0,0x800b
/*  f196c18:	156100db */ 	bne	$t3,$at,.PF0f196f88
/*  f196c1c:	27a50254 */ 	addiu	$a1,$sp,0x254
/*  f196c20:	27ad0248 */ 	addiu	$t5,$sp,0x248
/*  f196c24:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f196c28:	8484c6be */ 	lh	$a0,-0x3942($a0)
/*  f196c2c:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f196c30:	0fc66f1c */ 	jal	func0f19ab70
/*  f196c34:	27a7024c */ 	addiu	$a3,$sp,0x24c
/*  f196c38:	104000d3 */ 	beqz	$v0,.PF0f196f88
/*  f196c3c:	c7a60254 */ 	lwc1	$f6,0x254($sp)
/*  f196c40:	e64600ec */ 	swc1	$f6,0xec($s2)
/*  f196c44:	c7aa0258 */ 	lwc1	$f10,0x258($sp)
/*  f196c48:	3c04800b */ 	lui	$a0,0x800b
/*  f196c4c:	2415002b */ 	li	$s5,0x2b
/*  f196c50:	e64a00f0 */ 	swc1	$f10,0xf0($s2)
/*  f196c54:	c7b2025c */ 	lwc1	$f18,0x25c($sp)
/*  f196c58:	2484c6be */ 	addiu	$a0,$a0,-14658
/*  f196c5c:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196c60:	0fc1968d */ 	jal	roomsCopy
/*  f196c64:	e65200f4 */ 	swc1	$f18,0xf4($s2)
/*  f196c68:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f196c6c:	3c0f800b */ 	lui	$t7,0x800b
/*  f196c70:	85efc6be */ 	lh	$t7,-0x3942($t7)
/*  f196c74:	85cc0028 */ 	lh	$t4,0x28($t6)
/*  f196c78:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f196c7c:	3c19800b */ 	lui	$t9,0x800b
/*  f196c80:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f196c84:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f196c88:	0018482b */ 	sltu	$t1,$zero,$t8
/*  f196c8c:	000959c0 */ 	sll	$t3,$t1,0x7
/*  f196c90:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f196c94:	016e6025 */ 	or	$t4,$t3,$t6
/*  f196c98:	a24c004c */ 	sb	$t4,0x4c($s2)
/*  f196c9c:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f196ca0:	a64f0048 */ 	sh	$t7,0x48($s2)
/*  f196ca4:	8fb80248 */ 	lw	$t8,0x248($sp)
/*  f196ca8:	a658004a */ 	sh	$t8,0x4a($s2)
/*  f196cac:	8739c6be */ 	lh	$t9,-0x3942($t9)
/*  f196cb0:	100000b5 */ 	b	.PF0f196f88
/*  f196cb4:	ae5900bc */ 	sw	$t9,0xbc($s2)
.PF0f196cb8:
/*  f196cb8:	24010005 */ 	li	$at,0x5
/*  f196cbc:	1441003b */ 	bne	$v0,$at,.PF0f196dac
/*  f196cc0:	3c09800b */ 	lui	$t1,0x800b
/*  f196cc4:	9129d138 */ 	lbu	$t1,-0x2ec8($t1)
/*  f196cc8:	24010002 */ 	li	$at,0x2
/*  f196ccc:	3c02800b */ 	lui	$v0,0x800b
/*  f196cd0:	152100ad */ 	bne	$t1,$at,.PF0f196f88
/*  f196cd4:	00000000 */ 	nop
/*  f196cd8:	8c42c7ec */ 	lw	$v0,-0x3814($v0)
/*  f196cdc:	104000aa */ 	beqz	$v0,.PF0f196f88
/*  f196ce0:	00000000 */ 	nop
/*  f196ce4:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f196ce8:	104a00a7 */ 	beq	$v0,$t2,.PF0f196f88
/*  f196cec:	00000000 */ 	nop
/*  f196cf0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f196cf4:	24010003 */ 	li	$at,0x3
/*  f196cf8:	3c0d800b */ 	lui	$t5,0x800b
/*  f196cfc:	10610003 */ 	beq	$v1,$at,.PF0f196d0c
/*  f196d00:	24010006 */ 	li	$at,0x6
/*  f196d04:	54610027 */ 	bnel	$v1,$at,.PF0f196da4
/*  f196d08:	2415002c */ 	li	$s5,0x2c
.PF0f196d0c:
/*  f196d0c:	8dadd134 */ 	lw	$t5,-0x2ecc($t5)
/*  f196d10:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f196d14:	02802025 */ 	move	$a0,$s4
/*  f196d18:	31ab0002 */ 	andi	$t3,$t5,0x2
/*  f196d1c:	11600013 */ 	beqz	$t3,.PF0f196d6c
/*  f196d20:	00000000 */ 	nop
/*  f196d24:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f196d28:	920c0125 */ 	lbu	$t4,0x125($s0)
/*  f196d2c:	02002825 */ 	move	$a1,$s0
/*  f196d30:	15cc000e */ 	bne	$t6,$t4,.PF0f196d6c
/*  f196d34:	00000000 */ 	nop
/*  f196d38:	0fc65163 */ 	jal	mpIsChrFollowedByChr
/*  f196d3c:	02802025 */ 	move	$a0,$s4
/*  f196d40:	10400091 */ 	beqz	$v0,.PF0f196f88
/*  f196d44:	00000000 */ 	nop
/*  f196d48:	0c004ad4 */ 	jal	random
/*  f196d4c:	24150032 */ 	li	$s5,0x32
/*  f196d50:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f196d54:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f196d58:	ae5801e0 */ 	sw	$t8,0x1e0($s2)
/*  f196d5c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196d60:	02002025 */ 	move	$a0,$s0
/*  f196d64:	10000088 */ 	b	.PF0f196f88
/*  f196d68:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196d6c:
/*  f196d6c:	0fc64e81 */ 	jal	func0f19294c
/*  f196d70:	02002825 */ 	move	$a1,$s0
/*  f196d74:	14400084 */ 	bnez	$v0,.PF0f196f88
/*  f196d78:	02802025 */ 	move	$a0,$s4
/*  f196d7c:	0fc64f9c */ 	jal	func0f192dc0
/*  f196d80:	02002825 */ 	move	$a1,$s0
/*  f196d84:	10400080 */ 	beqz	$v0,.PF0f196f88
/*  f196d88:	02002025 */ 	move	$a0,$s0
/*  f196d8c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196d90:	2415002f */ 	li	$s5,0x2f
/*  f196d94:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196d98:	1000007b */ 	b	.PF0f196f88
/*  f196d9c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196da0:	2415002c */ 	li	$s5,0x2c
.PF0f196da4:
/*  f196da4:	10000078 */ 	b	.PF0f196f88
/*  f196da8:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196dac:
/*  f196dac:	2401000b */ 	li	$at,0xb
/*  f196db0:	1441003a */ 	bne	$v0,$at,.PF0f196e9c
/*  f196db4:	3c19800b */ 	lui	$t9,0x800b
/*  f196db8:	9339d138 */ 	lbu	$t9,-0x2ec8($t9)
/*  f196dbc:	3c02800b */ 	lui	$v0,0x800b
/*  f196dc0:	16f90071 */ 	bne	$s7,$t9,.PF0f196f88
/*  f196dc4:	00000000 */ 	nop
/*  f196dc8:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f196dcc:	1040006e */ 	beqz	$v0,.PF0f196f88
/*  f196dd0:	00000000 */ 	nop
/*  f196dd4:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f196dd8:	1049006b */ 	beq	$v0,$t1,.PF0f196f88
/*  f196ddc:	00000000 */ 	nop
/*  f196de0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f196de4:	24010003 */ 	li	$at,0x3
/*  f196de8:	3c0a800b */ 	lui	$t2,0x800b
/*  f196dec:	10610003 */ 	beq	$v1,$at,.PF0f196dfc
/*  f196df0:	24010006 */ 	li	$at,0x6
/*  f196df4:	54610027 */ 	bnel	$v1,$at,.PF0f196e94
/*  f196df8:	2415002c */ 	li	$s5,0x2c
.PF0f196dfc:
/*  f196dfc:	8d4ad134 */ 	lw	$t2,-0x2ecc($t2)
/*  f196e00:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f196e04:	02802025 */ 	move	$a0,$s4
/*  f196e08:	314d0002 */ 	andi	$t5,$t2,0x2
/*  f196e0c:	11a00013 */ 	beqz	$t5,.PF0f196e5c
/*  f196e10:	00000000 */ 	nop
/*  f196e14:	928b0125 */ 	lbu	$t3,0x125($s4)
/*  f196e18:	920e0125 */ 	lbu	$t6,0x125($s0)
/*  f196e1c:	02002825 */ 	move	$a1,$s0
/*  f196e20:	156e000e */ 	bne	$t3,$t6,.PF0f196e5c
/*  f196e24:	00000000 */ 	nop
/*  f196e28:	0fc65163 */ 	jal	mpIsChrFollowedByChr
/*  f196e2c:	02802025 */ 	move	$a0,$s4
/*  f196e30:	10400055 */ 	beqz	$v0,.PF0f196f88
/*  f196e34:	00000000 */ 	nop
/*  f196e38:	0c004ad4 */ 	jal	random
/*  f196e3c:	24150032 */ 	li	$s5,0x32
/*  f196e40:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f196e44:	2d8f0001 */ 	sltiu	$t7,$t4,0x1
/*  f196e48:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f196e4c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196e50:	02002025 */ 	move	$a0,$s0
/*  f196e54:	1000004c */ 	b	.PF0f196f88
/*  f196e58:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196e5c:
/*  f196e5c:	0fc64e81 */ 	jal	func0f19294c
/*  f196e60:	02002825 */ 	move	$a1,$s0
/*  f196e64:	14400048 */ 	bnez	$v0,.PF0f196f88
/*  f196e68:	02802025 */ 	move	$a0,$s4
/*  f196e6c:	0fc64f9c */ 	jal	func0f192dc0
/*  f196e70:	02002825 */ 	move	$a1,$s0
/*  f196e74:	10400044 */ 	beqz	$v0,.PF0f196f88
/*  f196e78:	02002025 */ 	move	$a0,$s0
/*  f196e7c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196e80:	2415002f */ 	li	$s5,0x2f
/*  f196e84:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196e88:	1000003f */ 	b	.PF0f196f88
/*  f196e8c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196e90:	2415002c */ 	li	$s5,0x2c
.PF0f196e94:
/*  f196e94:	1000003c */ 	b	.PF0f196f88
/*  f196e98:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196e9c:
/*  f196e9c:	2401000c */ 	li	$at,0xc
/*  f196ea0:	14410039 */ 	bne	$v0,$at,.PF0f196f88
/*  f196ea4:	3c18800b */ 	lui	$t8,0x800b
/*  f196ea8:	9318d138 */ 	lbu	$t8,-0x2ec8($t8)
/*  f196eac:	24010003 */ 	li	$at,0x3
/*  f196eb0:	3c02800b */ 	lui	$v0,0x800b
/*  f196eb4:	17010034 */ 	bne	$t8,$at,.PF0f196f88
/*  f196eb8:	00000000 */ 	nop
/*  f196ebc:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f196ec0:	3c09800b */ 	lui	$t1,0x800b
/*  f196ec4:	04400030 */ 	bltz	$v0,.PF0f196f88
/*  f196ec8:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f196ecc:	01394821 */ 	addu	$t1,$t1,$t9
/*  f196ed0:	8529c6b8 */ 	lh	$t1,-0x3948($t1)
/*  f196ed4:	3c0d800b */ 	lui	$t5,0x800b
/*  f196ed8:	8e8b001c */ 	lw	$t3,0x1c($s4)
/*  f196edc:	00095080 */ 	sll	$t2,$t1,0x2
/*  f196ee0:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f196ee4:	8dadca70 */ 	lw	$t5,-0x3590($t5)
/*  f196ee8:	3c0e800b */ 	lui	$t6,0x800b
/*  f196eec:	8da3001c */ 	lw	$v1,0x1c($t5)
/*  f196ef0:	106b0025 */ 	beq	$v1,$t3,.PF0f196f88
/*  f196ef4:	00000000 */ 	nop
/*  f196ef8:	8dced134 */ 	lw	$t6,-0x2ecc($t6)
/*  f196efc:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f196f00:	02802025 */ 	move	$a0,$s4
/*  f196f04:	31cc0002 */ 	andi	$t4,$t6,0x2
/*  f196f08:	11800013 */ 	beqz	$t4,.PF0f196f58
/*  f196f0c:	00000000 */ 	nop
/*  f196f10:	928f0125 */ 	lbu	$t7,0x125($s4)
/*  f196f14:	92180125 */ 	lbu	$t8,0x125($s0)
/*  f196f18:	02002825 */ 	move	$a1,$s0
/*  f196f1c:	15f8000e */ 	bne	$t7,$t8,.PF0f196f58
/*  f196f20:	00000000 */ 	nop
/*  f196f24:	0fc65163 */ 	jal	mpIsChrFollowedByChr
/*  f196f28:	02802025 */ 	move	$a0,$s4
/*  f196f2c:	10400016 */ 	beqz	$v0,.PF0f196f88
/*  f196f30:	00000000 */ 	nop
/*  f196f34:	0c004ad4 */ 	jal	random
/*  f196f38:	24150032 */ 	li	$s5,0x32
/*  f196f3c:	30590003 */ 	andi	$t9,$v0,0x3
/*  f196f40:	2f290001 */ 	sltiu	$t1,$t9,0x1
/*  f196f44:	ae4901e0 */ 	sw	$t1,0x1e0($s2)
/*  f196f48:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196f4c:	02002025 */ 	move	$a0,$s0
/*  f196f50:	1000000d */ 	b	.PF0f196f88
/*  f196f54:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196f58:
/*  f196f58:	0fc64e81 */ 	jal	func0f19294c
/*  f196f5c:	02002825 */ 	move	$a1,$s0
/*  f196f60:	14400009 */ 	bnez	$v0,.PF0f196f88
/*  f196f64:	02802025 */ 	move	$a0,$s4
/*  f196f68:	0fc64f9c */ 	jal	func0f192dc0
/*  f196f6c:	02002825 */ 	move	$a1,$s0
/*  f196f70:	10400005 */ 	beqz	$v0,.PF0f196f88
/*  f196f74:	02002025 */ 	move	$a0,$s0
/*  f196f78:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196f7c:	2415002f */ 	li	$s5,0x2f
/*  f196f80:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196f84:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f196f88:
/*  f196f88:	06a10078 */ 	bgez	$s5,.PF0f19716c
/*  f196f8c:	3c03800b */ 	lui	$v1,0x800b
/*  f196f90:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f196f94:	24010003 */ 	li	$at,0x3
/*  f196f98:	16e3001a */ 	bne	$s7,$v1,.PF0f197004
/*  f196f9c:	00000000 */ 	nop
/*  f196fa0:	8e4a009c */ 	lw	$t2,0x9c($s2)
/*  f196fa4:	000a6fc2 */ 	srl	$t5,$t2,0x1f
/*  f196fa8:	11a00070 */ 	beqz	$t5,.PF0f19716c
/*  f196fac:	00000000 */ 	nop
/*  f196fb0:	0c004ad4 */ 	jal	random
/*  f196fb4:	03c08025 */ 	move	$s0,$s8
/*  f196fb8:	24010064 */ 	li	$at,0x64
/*  f196fbc:	0041001b */ 	divu	$zero,$v0,$at
/*  f196fc0:	00005810 */ 	mfhi	$t3
/*  f196fc4:	2d610042 */ 	sltiu	$at,$t3,0x42
/*  f196fc8:	10200005 */ 	beqz	$at,.PF0f196fe0
/*  f196fcc:	02802025 */ 	move	$a0,$s4
/*  f196fd0:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f196fd4:	0fc65178 */ 	jal	func0f193530
/*  f196fd8:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f196fdc:	00408025 */ 	move	$s0,$v0
.PF0f196fe0:
/*  f196fe0:	06000062 */ 	bltz	$s0,.PF0f19716c
/*  f196fe4:	00000000 */ 	nop
/*  f196fe8:	0c004ad4 */ 	jal	random
/*  f196fec:	24150032 */ 	li	$s5,0x32
/*  f196ff0:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f196ff4:	2dcc0001 */ 	sltiu	$t4,$t6,0x1
/*  f196ff8:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f196ffc:	1000005b */ 	b	.PF0f19716c
/*  f197000:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197004:
/*  f197004:	14610024 */ 	bne	$v1,$at,.PF0f197098
/*  f197008:	3c02800b */ 	lui	$v0,0x800b
/*  f19700c:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f197010:	3c18800b */ 	lui	$t8,0x800b
/*  f197014:	04400055 */ 	bltz	$v0,.PF0f19716c
/*  f197018:	00027840 */ 	sll	$t7,$v0,0x1
/*  f19701c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f197020:	8718c6b8 */ 	lh	$t8,-0x3948($t8)
/*  f197024:	3c09800b */ 	lui	$t1,0x800b
/*  f197028:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f19702c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f197030:	01394821 */ 	addu	$t1,$t1,$t9
/*  f197034:	8d29ca70 */ 	lw	$t1,-0x3590($t1)
/*  f197038:	8d23001c */ 	lw	$v1,0x1c($t1)
/*  f19703c:	146a004b */ 	bne	$v1,$t2,.PF0f19716c
/*  f197040:	00000000 */ 	nop
/*  f197044:	0c004ad4 */ 	jal	random
/*  f197048:	03c08025 */ 	move	$s0,$s8
/*  f19704c:	24010064 */ 	li	$at,0x64
/*  f197050:	0041001b */ 	divu	$zero,$v0,$at
/*  f197054:	00006810 */ 	mfhi	$t5
/*  f197058:	2da10042 */ 	sltiu	$at,$t5,0x42
/*  f19705c:	10200005 */ 	beqz	$at,.PF0f197074
/*  f197060:	02802025 */ 	move	$a0,$s4
/*  f197064:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f197068:	0fc65178 */ 	jal	func0f193530
/*  f19706c:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f197070:	00408025 */ 	move	$s0,$v0
.PF0f197074:
/*  f197074:	0600003d */ 	bltz	$s0,.PF0f19716c
/*  f197078:	00000000 */ 	nop
/*  f19707c:	0c004ad4 */ 	jal	random
/*  f197080:	24150032 */ 	li	$s5,0x32
/*  f197084:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f197088:	2d6e0001 */ 	sltiu	$t6,$t3,0x1
/*  f19708c:	ae4e01e0 */ 	sw	$t6,0x1e0($s2)
/*  f197090:	10000036 */ 	b	.PF0f19716c
/*  f197094:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197098:
/*  f197098:	24010005 */ 	li	$at,0x5
/*  f19709c:	54610021 */ 	bnel	$v1,$at,.PF0f197124
/*  f1970a0:	24010002 */ 	li	$at,0x2
/*  f1970a4:	0fc65655 */ 	jal	func0f19489c
/*  f1970a8:	02802025 */ 	move	$a0,$s4
/*  f1970ac:	1040002f */ 	beqz	$v0,.PF0f19716c
/*  f1970b0:	00000000 */ 	nop
/*  f1970b4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1970b8:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1970bc:	2415002b */ 	li	$s5,0x2b
/*  f1970c0:	3c07800b */ 	lui	$a3,0x800b
/*  f1970c4:	24e7c6b0 */ 	addiu	$a3,$a3,-14672
/*  f1970c8:	00026040 */ 	sll	$t4,$v0,0x1
/*  f1970cc:	00ec7821 */ 	addu	$t7,$a3,$t4
/*  f1970d0:	85e30008 */ 	lh	$v1,0x8($t7)
/*  f1970d4:	24050042 */ 	li	$a1,0x42
/*  f1970d8:	27a601d8 */ 	addiu	$a2,$sp,0x1d8
/*  f1970dc:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f1970e0:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1970e4:	0fc45964 */ 	jal	padUnpack
/*  f1970e8:	87240018 */ 	lh	$a0,0x18($t9)
/*  f1970ec:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f1970f0:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f1970f4:	e64400ec */ 	swc1	$f4,0xec($s2)
/*  f1970f8:	c7a801dc */ 	lwc1	$f8,0x1dc($sp)
/*  f1970fc:	314dff7f */ 	andi	$t5,$t2,0xff7f
/*  f197100:	e64800f0 */ 	swc1	$f8,0xf0($s2)
/*  f197104:	c7a601e0 */ 	lwc1	$f6,0x1e0($sp)
/*  f197108:	e64600f4 */ 	swc1	$f6,0xf4($s2)
/*  f19710c:	8fa90220 */ 	lw	$t1,0x220($sp)
/*  f197110:	a65e00fa */ 	sh	$s8,0xfa($s2)
/*  f197114:	a24d004c */ 	sb	$t5,0x4c($s2)
/*  f197118:	10000014 */ 	b	.PF0f19716c
/*  f19711c:	a64900f8 */ 	sh	$t1,0xf8($s2)
/*  f197120:	24010002 */ 	li	$at,0x2
.PF0f197124:
/*  f197124:	14610011 */ 	bne	$v1,$at,.PF0f19716c
/*  f197128:	3c0b800b */ 	lui	$t3,0x800b
/*  f19712c:	8d6bc7ec */ 	lw	$t3,-0x3814($t3)
/*  f197130:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f197134:	156e000d */ 	bne	$t3,$t6,.PF0f19716c
/*  f197138:	00000000 */ 	nop
/*  f19713c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197140:	02802025 */ 	move	$a0,$s4
/*  f197144:	3c03800b */ 	lui	$v1,0x800b
/*  f197148:	2463c6b0 */ 	addiu	$v1,$v1,-14672
/*  f19714c:	846c00d2 */ 	lh	$t4,0xd2($v1)
/*  f197150:	2415002e */ 	li	$s5,0x2e
/*  f197154:	104c0005 */ 	beq	$v0,$t4,.PF0f19716c
/*  f197158:	00000000 */ 	nop
/*  f19715c:	8c6f0080 */ 	lw	$t7,0x80($v1)
/*  f197160:	2415002c */ 	li	$s5,0x2c
/*  f197164:	10000001 */ 	b	.PF0f19716c
/*  f197168:	ae4f0010 */ 	sw	$t7,0x10($s2)
.PF0f19716c:
/*  f19716c:	06a100a2 */ 	bgez	$s5,.PF0f1973f8
/*  f197170:	00000000 */ 	nop
/*  f197174:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f197178:	2401000c */ 	li	$at,0xc
/*  f19717c:	93020047 */ 	lbu	$v0,0x47($t8)
/*  f197180:	54410011 */ 	bnel	$v0,$at,.PF0f1971c8
/*  f197184:	24010009 */ 	li	$at,0x9
/*  f197188:	86420076 */ 	lh	$v0,0x76($s2)
/*  f19718c:	02802025 */ 	move	$a0,$s4
/*  f197190:	3c05800b */ 	lui	$a1,0x800b
/*  f197194:	04400098 */ 	bltz	$v0,.PF0f1973f8
/*  f197198:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19719c:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f1971a0:	0fc64e81 */ 	jal	func0f19294c
/*  f1971a4:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f1971a8:	14400093 */ 	bnez	$v0,.PF0f1973f8
/*  f1971ac:	00000000 */ 	nop
/*  f1971b0:	86490076 */ 	lh	$t1,0x76($s2)
/*  f1971b4:	2415002f */ 	li	$s5,0x2f
/*  f1971b8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f1971bc:	1000008e */ 	b	.PF0f1973f8
/*  f1971c0:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f1971c4:	24010009 */ 	li	$at,0x9
.PF0f1971c8:
/*  f1971c8:	54410021 */ 	bnel	$v0,$at,.PF0f197250
/*  f1971cc:	24010008 */ 	li	$at,0x8
/*  f1971d0:	8e4a0114 */ 	lw	$t2,0x114($s2)
/*  f1971d4:	0543000f */ 	bgezl	$t2,.PF0f197214
/*  f1971d8:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f1971dc:	86420076 */ 	lh	$v0,0x76($s2)
/*  f1971e0:	02802025 */ 	move	$a0,$s4
/*  f1971e4:	3c05800b */ 	lui	$a1,0x800b
/*  f1971e8:	04400009 */ 	bltz	$v0,.PF0f197210
/*  f1971ec:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1971f0:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f1971f4:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f1971f8:	0fc12b09 */ 	jal	chrCompareTeams
/*  f1971fc:	24060001 */ 	li	$a2,0x1
/*  f197200:	54400004 */ 	bnezl	$v0,.PF0f197214
/*  f197204:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f197208:	864b0076 */ 	lh	$t3,0x76($s2)
/*  f19720c:	ae4b0114 */ 	sw	$t3,0x114($s2)
.PF0f197210:
/*  f197210:	8e420114 */ 	lw	$v0,0x114($s2)
.PF0f197214:
/*  f197214:	02802025 */ 	move	$a0,$s4
/*  f197218:	3c05800b */ 	lui	$a1,0x800b
/*  f19721c:	04400076 */ 	bltz	$v0,.PF0f1973f8
/*  f197220:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197224:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f197228:	0fc64e81 */ 	jal	func0f19294c
/*  f19722c:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f197230:	14400071 */ 	bnez	$v0,.PF0f1973f8
/*  f197234:	00000000 */ 	nop
/*  f197238:	8e4c0114 */ 	lw	$t4,0x114($s2)
/*  f19723c:	2415002f */ 	li	$s5,0x2f
/*  f197240:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197244:	1000006c */ 	b	.PF0f1973f8
/*  f197248:	a64c0008 */ 	sh	$t4,0x8($s2)
/*  f19724c:	24010008 */ 	li	$at,0x8
.PF0f197250:
/*  f197250:	5441002a */ 	bnel	$v0,$at,.PF0f1972fc
/*  f197254:	24010006 */ 	li	$at,0x6
/*  f197258:	0fc625a2 */ 	jal	mpGetPlayerRankings
/*  f19725c:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f197260:	18400065 */ 	blez	$v0,.PF0f1973f8
/*  f197264:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f197268:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f19726c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f197270:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f197274:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f197278:	afb90050 */ 	sw	$t9,0x50($sp)
.PF0f19727c:
/*  f19727c:	0fc6386d */ 	jal	func0f18d0e8
/*  f197280:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f197284:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f197288:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f19728c:	00402025 */ 	move	$a0,$v0
/*  f197290:	10540012 */ 	beq	$v0,$s4,.PF0f1972dc
/*  f197294:	00402025 */ 	move	$a0,$v0
/*  f197298:	0fc0e706 */ 	jal	chrIsDead
/*  f19729c:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f1972a0:	1440000e */ 	bnez	$v0,.PF0f1972dc
/*  f1972a4:	8fb100d4 */ 	lw	$s1,0xd4($sp)
/*  f1972a8:	02802025 */ 	move	$a0,$s4
/*  f1972ac:	02202825 */ 	move	$a1,$s1
/*  f1972b0:	0fc12b09 */ 	jal	chrCompareTeams
/*  f1972b4:	24060002 */ 	li	$a2,0x2
/*  f1972b8:	10400008 */ 	beqz	$v0,.PF0f1972dc
/*  f1972bc:	02802025 */ 	move	$a0,$s4
/*  f1972c0:	0fc64e81 */ 	jal	func0f19294c
/*  f1972c4:	02202825 */ 	move	$a1,$s1
/*  f1972c8:	14400004 */ 	bnez	$v0,.PF0f1972dc
/*  f1972cc:	8fa900d8 */ 	lw	$t1,0xd8($sp)
/*  f1972d0:	2415002f */ 	li	$s5,0x2f
/*  f1972d4:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f1972d8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1972dc:
/*  f1972dc:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f1972e0:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f1972e4:	020a082b */ 	sltu	$at,$s0,$t2
/*  f1972e8:	1420ffe4 */ 	bnez	$at,.PF0f19727c
/*  f1972ec:	00000000 */ 	nop
/*  f1972f0:	10000041 */ 	b	.PF0f1973f8
/*  f1972f4:	00000000 */ 	nop
/*  f1972f8:	24010006 */ 	li	$at,0x6
.PF0f1972fc:
/*  f1972fc:	1441003e */ 	bne	$v0,$at,.PF0f1973f8
/*  f197300:	3c13800b */ 	lui	$s3,0x800b
/*  f197304:	2673cad0 */ 	addiu	$s3,$s3,-13616
/*  f197308:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f19730c:	44805000 */ 	mtc1	$zero,$f10
/*  f197310:	03c08825 */ 	move	$s1,$s8
/*  f197314:	00008025 */ 	move	$s0,$zero
/*  f197318:	19a00032 */ 	blez	$t5,.PF0f1973e4
/*  f19731c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
.PF0f197320:
/*  f197320:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f197324:	02002025 */ 	move	$a0,$s0
/*  f197328:	10540029 */ 	beq	$v0,$s4,.PF0f1973d0
/*  f19732c:	00402025 */ 	move	$a0,$v0
/*  f197330:	0fc0e706 */ 	jal	chrIsDead
/*  f197334:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f197338:	14400025 */ 	bnez	$v0,.PF0f1973d0
/*  f19733c:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197340:	02802025 */ 	move	$a0,$s4
/*  f197344:	24060002 */ 	li	$a2,0x2
/*  f197348:	0fc12b09 */ 	jal	chrCompareTeams
/*  f19734c:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197350:	1040001f */ 	beqz	$v0,.PF0f1973d0
/*  f197354:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197358:	02802025 */ 	move	$a0,$s4
/*  f19735c:	0fc64e81 */ 	jal	func0f19294c
/*  f197360:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197364:	1440001a */ 	bnez	$v0,.PF0f1973d0
/*  f197368:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f19736c:	8cab02d4 */ 	lw	$t3,0x2d4($a1)
/*  f197370:	11600005 */ 	beqz	$t3,.PF0f197388
/*  f197374:	00000000 */ 	nop
/*  f197378:	c4b20104 */ 	lwc1	$f18,0x104($a1)
/*  f19737c:	c4a40100 */ 	lwc1	$f4,0x100($a1)
/*  f197380:	1000000b */ 	b	.PF0f1973b0
/*  f197384:	46049001 */ 	sub.s	$f0,$f18,$f4
.PF0f197388:
/*  f197388:	0fc4a513 */ 	jal	propGetPlayerNum
/*  f19738c:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f197390:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197394:	02ce6021 */ 	addu	$t4,$s6,$t6
/*  f197398:	8d980064 */ 	lw	$t8,0x64($t4)
/*  f19739c:	3c014100 */ 	lui	$at,0x4100
/*  f1973a0:	44813000 */ 	mtc1	$at,$f6
/*  f1973a4:	c70800dc */ 	lwc1	$f8,0xdc($t8)
/*  f1973a8:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f1973ac:	00000000 */ 	nop
.PF0f1973b0:
/*  f1973b0:	06200005 */ 	bltz	$s1,.PF0f1973c8
/*  f1973b4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f1973b8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f1973bc:	00000000 */ 	nop
/*  f1973c0:	45020004 */ 	bc1fl	.PF0f1973d4
/*  f1973c4:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PF0f1973c8:
/*  f1973c8:	02008825 */ 	move	$s1,$s0
/*  f1973cc:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
.PF0f1973d0:
/*  f1973d0:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PF0f1973d4:
/*  f1973d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1973d8:	020f082a */ 	slt	$at,$s0,$t7
/*  f1973dc:	1420ffd0 */ 	bnez	$at,.PF0f197320
/*  f1973e0:	00000000 */ 	nop
.PF0f1973e4:
/*  f1973e4:	06200004 */ 	bltz	$s1,.PF0f1973f8
/*  f1973e8:	00000000 */ 	nop
/*  f1973ec:	2415002f */ 	li	$s5,0x2f
/*  f1973f0:	a6510008 */ 	sh	$s1,0x8($s2)
/*  f1973f4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1973f8:
/*  f1973f8:	06a1000d */ 	bgez	$s5,.PF0f197430
/*  f1973fc:	00000000 */ 	nop
/*  f197400:	8699017e */ 	lh	$t9,0x17e($s4)
/*  f197404:	13d9000a */ 	beq	$s8,$t9,.PF0f197430
/*  f197408:	00000000 */ 	nop
/*  f19740c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197410:	02802025 */ 	move	$a0,$s4
/*  f197414:	02802025 */ 	move	$a0,$s4
/*  f197418:	0fc64f9c */ 	jal	func0f192dc0
/*  f19741c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197420:	10400003 */ 	beqz	$v0,.PF0f197430
/*  f197424:	00000000 */ 	nop
/*  f197428:	2415002f */ 	li	$s5,0x2f
/*  f19742c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f197430:
/*  f197430:	06a1000b */ 	bgez	$s5,.PF0f197460
/*  f197434:	02802025 */ 	move	$a0,$s4
/*  f197438:	0fc65178 */ 	jal	func0f193530
/*  f19743c:	3c054396 */ 	lui	$a1,0x4396
/*  f197440:	04400007 */ 	bltz	$v0,.PF0f197460
/*  f197444:	00408025 */ 	move	$s0,$v0
/*  f197448:	0c004ad4 */ 	jal	random
/*  f19744c:	24150032 */ 	li	$s5,0x32
/*  f197450:	30490003 */ 	andi	$t1,$v0,0x3
/*  f197454:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f197458:	ae4a01e0 */ 	sw	$t2,0x1e0($s2)
/*  f19745c:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197460:
/*  f197460:	06a10006 */ 	bgez	$s5,.PF0f19747c
/*  f197464:	00000000 */ 	nop
/*  f197468:	0fc655db */ 	jal	func0f1946b4
/*  f19746c:	02802025 */ 	move	$a0,$s4
/*  f197470:	10400002 */ 	beqz	$v0,.PF0f19747c
/*  f197474:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f197478:	2415002a */ 	li	$s5,0x2a
.PF0f19747c:
/*  f19747c:	3c13800b */ 	lui	$s3,0x800b
/*  f197480:	06a00082 */ 	bltz	$s5,.PF0f19768c
/*  f197484:	2673cad0 */ 	addiu	$s3,$s3,-13616
/*  f197488:	2401002a */ 	li	$at,0x2a
/*  f19748c:	56a1000a */ 	bnel	$s5,$at,.PF0f1974b8
/*  f197490:	2401002f */ 	li	$at,0x2f
/*  f197494:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197498:	02802025 */ 	move	$a0,$s4
/*  f19749c:	50a0007c */ 	beqzl	$a1,.PF0f197690
/*  f1974a0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974a4:	0fc0eb3e */ 	jal	chrGoToProp
/*  f1974a8:	24060002 */ 	li	$a2,0x2
/*  f1974ac:	10000077 */ 	b	.PF0f19768c
/*  f1974b0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974b4:	2401002f */ 	li	$at,0x2f
.PF0f1974b8:
/*  f1974b8:	56a10009 */ 	bnel	$s5,$at,.PF0f1974e0
/*  f1974bc:	24010032 */ 	li	$at,0x32
/*  f1974c0:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f1974c4:	2401002f */ 	li	$at,0x2f
/*  f1974c8:	51a10071 */ 	beql	$t5,$at,.PF0f197690
/*  f1974cc:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974d0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974d4:	1000006d */ 	b	.PF0f19768c
/*  f1974d8:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f1974dc:	24010032 */ 	li	$at,0x32
.PF0f1974e0:
/*  f1974e0:	56a10010 */ 	bnel	$s5,$at,.PF0f197524
/*  f1974e4:	24010033 */ 	li	$at,0x33
/*  f1974e8:	928b02a0 */ 	lbu	$t3,0x2a0($s4)
/*  f1974ec:	24010032 */ 	li	$at,0x32
/*  f1974f0:	51610067 */ 	beql	$t3,$at,.PF0f197690
/*  f1974f4:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974f8:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974fc:	8e4e01e0 */ 	lw	$t6,0x1e0($s2)
/*  f197500:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f197504:	02802025 */ 	move	$a0,$s4
/*  f197508:	51c00061 */ 	beqzl	$t6,.PF0f197690
/*  f19750c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197510:	0fc64e0d */ 	jal	func0f19277c
/*  f197514:	03c02825 */ 	move	$a1,$s8
/*  f197518:	1000005d */ 	b	.PF0f197690
/*  f19751c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197520:	24010033 */ 	li	$at,0x33
.PF0f197524:
/*  f197524:	56a10010 */ 	bnel	$s5,$at,.PF0f197568
/*  f197528:	2401002b */ 	li	$at,0x2b
/*  f19752c:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197530:	8e4c01dc */ 	lw	$t4,0x1dc($s2)
/*  f197534:	02802025 */ 	move	$a0,$s4
/*  f197538:	51800004 */ 	beqzl	$t4,.PF0f19754c
/*  f19753c:	02802025 */ 	move	$a0,$s4
/*  f197540:	0fc64e0d */ 	jal	func0f19277c
/*  f197544:	03c02825 */ 	move	$a1,$s8
/*  f197548:	02802025 */ 	move	$a0,$s4
.PF0f19754c:
/*  f19754c:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f197550:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f197554:	0fc0e170 */ 	jal	chrGoToPos
/*  f197558:	24070002 */ 	li	$a3,0x2
/*  f19755c:	1000004c */ 	b	.PF0f197690
/*  f197560:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197564:	2401002b */ 	li	$at,0x2b
.PF0f197568:
/*  f197568:	56a10037 */ 	bnel	$s5,$at,.PF0f197648
/*  f19756c:	2401002c */ 	li	$at,0x2c
/*  f197570:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197574:	c64400ec */ 	lwc1	$f4,0xec($s2)
/*  f197578:	44808000 */ 	mtc1	$zero,$f16
/*  f19757c:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f197580:	c64600f0 */ 	lwc1	$f6,0xf0($s2)
/*  f197584:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f197588:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f19758c:	c65200f4 */ 	lwc1	$f18,0xf4($s2)
/*  f197590:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f197594:	3c0141a0 */ 	lui	$at,0x41a0
/*  f197598:	4610003c */ 	c.lt.s	$f0,$f16
/*  f19759c:	44817000 */ 	mtc1	$at,$f14
/*  f1975a0:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f1975a4:	45000002 */ 	bc1f	.PF0f1975b0
/*  f1975a8:	46125301 */ 	sub.s	$f12,$f10,$f18
/*  f1975ac:	46000007 */ 	neg.s	$f0,$f0
.PF0f1975b0:
/*  f1975b0:	4610103c */ 	c.lt.s	$f2,$f16
/*  f1975b4:	02802025 */ 	move	$a0,$s4
/*  f1975b8:	264500ec */ 	addiu	$a1,$s2,0xec
/*  f1975bc:	264600f8 */ 	addiu	$a2,$s2,0xf8
/*  f1975c0:	45000002 */ 	bc1f	.PF0f1975cc
/*  f1975c4:	24070002 */ 	li	$a3,0x2
/*  f1975c8:	46001087 */ 	neg.s	$f2,$f2
.PF0f1975cc:
/*  f1975cc:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1975d0:	00000000 */ 	nop
/*  f1975d4:	45020003 */ 	bc1fl	.PF0f1975e4
/*  f1975d8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1975dc:	46006307 */ 	neg.s	$f12,$f12
/*  f1975e0:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f1975e4:
/*  f1975e4:	00000000 */ 	nop
/*  f1975e8:	4501000e */ 	bc1t	.PF0f197624
/*  f1975ec:	00000000 */ 	nop
/*  f1975f0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1975f4:	3c014348 */ 	lui	$at,0x4348
/*  f1975f8:	4501000a */ 	bc1t	.PF0f197624
/*  f1975fc:	00000000 */ 	nop
/*  f197600:	44812000 */ 	mtc1	$at,$f4
/*  f197604:	00000000 */ 	nop
/*  f197608:	4602203c */ 	c.lt.s	$f4,$f2
/*  f19760c:	00000000 */ 	nop
/*  f197610:	45000008 */ 	bc1f	.PF0f197634
/*  f197614:	00000000 */ 	nop
/*  f197618:	828f032d */ 	lb	$t7,0x32d($s4)
/*  f19761c:	05e00005 */ 	bltz	$t7,.PF0f197634
/*  f197620:	00000000 */ 	nop
.PF0f197624:
/*  f197624:	0fc0e170 */ 	jal	chrGoToPos
/*  f197628:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f19762c:	10000018 */ 	b	.PF0f197690
/*  f197630:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PF0f197634:
/*  f197634:	0fc0baf7 */ 	jal	chrStand
/*  f197638:	02802025 */ 	move	$a0,$s4
/*  f19763c:	10000014 */ 	b	.PF0f197690
/*  f197640:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197644:	2401002c */ 	li	$at,0x2c
.PF0f197648:
/*  f197648:	56a1000c */ 	bnel	$s5,$at,.PF0f19767c
/*  f19764c:	2401002e */ 	li	$at,0x2e
/*  f197650:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f197654:	02802025 */ 	move	$a0,$s4
/*  f197658:	24060002 */ 	li	$a2,0x2
/*  f19765c:	5320000c */ 	beqzl	$t9,.PF0f197690
/*  f197660:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197664:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197668:	0fc0eb3e */ 	jal	chrGoToProp
/*  f19766c:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197670:	10000007 */ 	b	.PF0f197690
/*  f197674:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197678:	2401002e */ 	li	$at,0x2e
.PF0f19767c:
/*  f19767c:	16a10003 */ 	bne	$s5,$at,.PF0f19768c
/*  f197680:	02802025 */ 	move	$a0,$s4
/*  f197684:	0fc0baf7 */ 	jal	chrStand
/*  f197688:	a29502a0 */ 	sb	$s5,0x2a0($s4)
.PF0f19768c:
/*  f19768c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PF0f197690:
/*  f197690:	2401002a */ 	li	$at,0x2a
/*  f197694:	54410012 */ 	bnel	$v0,$at,.PF0f1976e0
/*  f197698:	2401002f */ 	li	$at,0x2f
/*  f19769c:	82890007 */ 	lb	$t1,0x7($s4)
/*  f1976a0:	2401000f */ 	li	$at,0xf
/*  f1976a4:	240b0029 */ 	li	$t3,0x29
/*  f1976a8:	1521000a */ 	bne	$t1,$at,.PF0f1976d4
/*  f1976ac:	00000000 */ 	nop
/*  f1976b0:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1976b4:	10a00007 */ 	beqz	$a1,.PF0f1976d4
/*  f1976b8:	00000000 */ 	nop
/*  f1976bc:	8caa0018 */ 	lw	$t2,0x18($a1)
/*  f1976c0:	15400004 */ 	bnez	$t2,.PF0f1976d4
/*  f1976c4:	00000000 */ 	nop
/*  f1976c8:	84ad0002 */ 	lh	$t5,0x2($a1)
/*  f1976cc:	11a00162 */ 	beqz	$t5,.PF0f197c58
/*  f1976d0:	00000000 */ 	nop
.PF0f1976d4:
/*  f1976d4:	10000160 */ 	b	.PF0f197c58
/*  f1976d8:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f1976dc:	2401002f */ 	li	$at,0x2f
.PF0f1976e0:
/*  f1976e0:	5441003f */ 	bnel	$v0,$at,.PF0f1977e0
/*  f1976e4:	24010032 */ 	li	$at,0x32
/*  f1976e8:	86420008 */ 	lh	$v0,0x8($s2)
/*  f1976ec:	3c04800b */ 	lui	$a0,0x800b
/*  f1976f0:	04400011 */ 	bltz	$v0,.PF0f197738
/*  f1976f4:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1976f8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f1976fc:	0fc0e706 */ 	jal	chrIsDead
/*  f197700:	8c84ca70 */ 	lw	$a0,-0x3590($a0)
/*  f197704:	5440000a */ 	bnezl	$v0,.PF0f197730
/*  f197708:	240f0029 */ 	li	$t7,0x29
/*  f19770c:	864c0008 */ 	lh	$t4,0x8($s2)
/*  f197710:	3c05800b */ 	lui	$a1,0x800b
/*  f197714:	02802025 */ 	move	$a0,$s4
/*  f197718:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f19771c:	00b82821 */ 	addu	$a1,$a1,$t8
/*  f197720:	0fc64f9c */ 	jal	func0f192dc0
/*  f197724:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f197728:	14400003 */ 	bnez	$v0,.PF0f197738
/*  f19772c:	240f0029 */ 	li	$t7,0x29
.PF0f197730:
/*  f197730:	10000149 */ 	b	.PF0f197c58
/*  f197734:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PF0f197738:
/*  f197738:	86590008 */ 	lh	$t9,0x8($s2)
/*  f19773c:	07210013 */ 	bgez	$t9,.PF0f19778c
/*  f197740:	00000000 */ 	nop
/*  f197744:	8689017e */ 	lh	$t1,0x17e($s4)
/*  f197748:	53c9000e */ 	beql	$s8,$t1,.PF0f197784
/*  f19774c:	240a0029 */ 	li	$t2,0x29
/*  f197750:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197754:	02802025 */ 	move	$a0,$s4
/*  f197758:	0fc0e706 */ 	jal	chrIsDead
/*  f19775c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197760:	54400008 */ 	bnezl	$v0,.PF0f197784
/*  f197764:	240a0029 */ 	li	$t2,0x29
/*  f197768:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f19776c:	02802025 */ 	move	$a0,$s4
/*  f197770:	02802025 */ 	move	$a0,$s4
/*  f197774:	0fc64f9c */ 	jal	func0f192dc0
/*  f197778:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f19777c:	14400003 */ 	bnez	$v0,.PF0f19778c
/*  f197780:	240a0029 */ 	li	$t2,0x29
.PF0f197784:
/*  f197784:	10000134 */ 	b	.PF0f197c58
/*  f197788:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PF0f19778c:
/*  f19778c:	0fc661c0 */ 	jal	func0f197600
/*  f197790:	02802025 */ 	move	$a0,$s4
/*  f197794:	0fc655ca */ 	jal	func0f194670
/*  f197798:	02802025 */ 	move	$a0,$s4
/*  f19779c:	10400003 */ 	beqz	$v0,.PF0f1977ac
/*  f1977a0:	240d0029 */ 	li	$t5,0x29
/*  f1977a4:	1000012c */ 	b	.PF0f197c58
/*  f1977a8:	a28d02a0 */ 	sb	$t5,0x2a0($s4)
.PF0f1977ac:
/*  f1977ac:	8e4201d8 */ 	lw	$v0,0x1d8($s2)
/*  f1977b0:	04400129 */ 	bltz	$v0,.PF0f197c58
/*  f1977b4:	00000000 */ 	nop
/*  f1977b8:	8ece0008 */ 	lw	$t6,0x8($s6)
/*  f1977bc:	8e4b0120 */ 	lw	$t3,0x120($s2)
/*  f1977c0:	24180029 */ 	li	$t8,0x29
/*  f1977c4:	01c26023 */ 	subu	$t4,$t6,$v0
/*  f1977c8:	016c082a */ 	slt	$at,$t3,$t4
/*  f1977cc:	10200122 */ 	beqz	$at,.PF0f197c58
/*  f1977d0:	00000000 */ 	nop
/*  f1977d4:	10000120 */ 	b	.PF0f197c58
/*  f1977d8:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1977dc:	24010032 */ 	li	$at,0x32
.PF0f1977e0:
/*  f1977e0:	5441004e */ 	bnel	$v0,$at,.PF0f19791c
/*  f1977e4:	24010033 */ 	li	$at,0x33
/*  f1977e8:	8642000a */ 	lh	$v0,0xa($s2)
/*  f1977ec:	3c04800b */ 	lui	$a0,0x800b
/*  f1977f0:	04400005 */ 	bltz	$v0,.PF0f197808
/*  f1977f4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1977f8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1977fc:	0fc0e706 */ 	jal	chrIsDead
/*  f197800:	8c84ca70 */ 	lw	$a0,-0x3590($a0)
/*  f197804:	10400003 */ 	beqz	$v0,.PF0f197814
.PF0f197808:
/*  f197808:	24190029 */ 	li	$t9,0x29
/*  f19780c:	10000112 */ 	b	.PF0f197c58
/*  f197810:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PF0f197814:
/*  f197814:	0fc661c0 */ 	jal	func0f197600
/*  f197818:	02802025 */ 	move	$a0,$s4
/*  f19781c:	8e4901e0 */ 	lw	$t1,0x1e0($s2)
/*  f197820:	11200037 */ 	beqz	$t1,.PF0f197900
/*  f197824:	00000000 */ 	nop
/*  f197828:	868a017e */ 	lh	$t2,0x17e($s4)
/*  f19782c:	13ca0034 */ 	beq	$s8,$t2,.PF0f197900
/*  f197830:	00000000 */ 	nop
/*  f197834:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f197838:	11a00031 */ 	beqz	$t5,.PF0f197900
/*  f19783c:	00000000 */ 	nop
/*  f197840:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197844:	02802025 */ 	move	$a0,$s4
/*  f197848:	02802025 */ 	move	$a0,$s4
/*  f19784c:	0fc64f9c */ 	jal	func0f192dc0
/*  f197850:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197854:	1040002a */ 	beqz	$v0,.PF0f197900
/*  f197858:	3c0143fa */ 	lui	$at,0x43fa
/*  f19785c:	864e000a */ 	lh	$t6,0xa($s2)
/*  f197860:	3c0c800b */ 	lui	$t4,0x800b
/*  f197864:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197868:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f19786c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f197870:	8d8cca70 */ 	lw	$t4,-0x3590($t4)
/*  f197874:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f197878:	44806000 */ 	mtc1	$zero,$f12
/*  f19787c:	8d82001c */ 	lw	$v0,0x1c($t4)
/*  f197880:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f197884:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f197888:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f19788c:	46064001 */ 	sub.s	$f0,$f8,$f6
/*  f197890:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f197894:	460c003c */ 	c.lt.s	$f0,$f12
/*  f197898:	00000000 */ 	nop
/*  f19789c:	45020003 */ 	bc1fl	.PF0f1978ac
/*  f1978a0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1978a4:	46000007 */ 	neg.s	$f0,$f0
/*  f1978a8:	460c103c */ 	c.lt.s	$f2,$f12
.PF0f1978ac:
/*  f1978ac:	44816000 */ 	mtc1	$at,$f12
/*  f1978b0:	45020003 */ 	bc1fl	.PF0f1978c0
/*  f1978b4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1978b8:	46001087 */ 	neg.s	$f2,$f2
/*  f1978bc:	460c003c */ 	c.lt.s	$f0,$f12
.PF0f1978c0:
/*  f1978c0:	00000000 */ 	nop
/*  f1978c4:	4500000e */ 	bc1f	.PF0f197900
/*  f1978c8:	00000000 */ 	nop
/*  f1978cc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1978d0:	2418002f */ 	li	$t8,0x2f
/*  f1978d4:	02802025 */ 	move	$a0,$s4
/*  f1978d8:	45000009 */ 	bc1f	.PF0f197900
/*  f1978dc:	00000000 */ 	nop
/*  f1978e0:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f1978e4:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1978e8:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1978ec:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1978f0:	240f00fa */ 	li	$t7,0xfa
/*  f1978f4:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1978f8:	ae4f01d8 */ 	sw	$t7,0x1d8($s2)
/*  f1978fc:	a25e0074 */ 	sb	$s8,0x74($s2)
.PF0f197900:
/*  f197900:	0fc655ca */ 	jal	func0f194670
/*  f197904:	02802025 */ 	move	$a0,$s4
/*  f197908:	104000d3 */ 	beqz	$v0,.PF0f197c58
/*  f19790c:	24190029 */ 	li	$t9,0x29
/*  f197910:	100000d1 */ 	b	.PF0f197c58
/*  f197914:	a29902a0 */ 	sb	$t9,0x2a0($s4)
/*  f197918:	24010033 */ 	li	$at,0x33
.PF0f19791c:
/*  f19791c:	54410063 */ 	bnel	$v0,$at,.PF0f197aac
/*  f197920:	2401002b */ 	li	$at,0x2b
/*  f197924:	82890007 */ 	lb	$t1,0x7($s4)
/*  f197928:	2401000f */ 	li	$at,0xf
/*  f19792c:	11210058 */ 	beq	$t1,$at,.PF0f197a90
/*  f197930:	00000000 */ 	nop
/*  f197934:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197938:	c648008c */ 	lwc1	$f8,0x8c($s2)
/*  f19793c:	44807000 */ 	mtc1	$zero,$f14
/*  f197940:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f197944:	c64a0090 */ 	lwc1	$f10,0x90($s2)
/*  f197948:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f19794c:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f197950:	c6440094 */ 	lwc1	$f4,0x94($s2)
/*  f197954:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f197958:	3c014220 */ 	lui	$at,0x4220
/*  f19795c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f197960:	460a3081 */ 	sub.s	$f2,$f6,$f10
/*  f197964:	45000002 */ 	bc1f	.PF0f197970
/*  f197968:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f19796c:	46000007 */ 	neg.s	$f0,$f0
.PF0f197970:
/*  f197970:	460e103c */ 	c.lt.s	$f2,$f14
/*  f197974:	00000000 */ 	nop
/*  f197978:	45020003 */ 	bc1fl	.PF0f197988
/*  f19797c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f197980:	46001087 */ 	neg.s	$f2,$f2
/*  f197984:	460e603c */ 	c.lt.s	$f12,$f14
.PF0f197988:
/*  f197988:	44817000 */ 	mtc1	$at,$f14
/*  f19798c:	45020003 */ 	bc1fl	.PF0f19799c
/*  f197990:	8e4200dc */ 	lw	$v0,0xdc($s2)
/*  f197994:	46006307 */ 	neg.s	$f12,$f12
/*  f197998:	8e4200dc */ 	lw	$v0,0xdc($s2)
.PF0f19799c:
/*  f19799c:	58400005 */ 	blezl	$v0,.PF0f1979b4
/*  f1979a0:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1979a4:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f1979a8:	004a6823 */ 	subu	$t5,$v0,$t2
/*  f1979ac:	ae4d00dc */ 	sw	$t5,0xdc($s2)
/*  f1979b0:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f1979b4:
/*  f1979b4:	00000000 */ 	nop
/*  f1979b8:	4503000f */ 	bc1tl	.PF0f1979f8
/*  f1979bc:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1979c0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1979c4:	3c014348 */ 	lui	$at,0x4348
/*  f1979c8:	4503000b */ 	bc1tl	.PF0f1979f8
/*  f1979cc:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1979d0:	44814000 */ 	mtc1	$at,$f8
/*  f1979d4:	00000000 */ 	nop
/*  f1979d8:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1979dc:	00000000 */ 	nop
/*  f1979e0:	4502000e */ 	bc1fl	.PF0f197a1c
/*  f1979e4:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1979e8:	828b032d */ 	lb	$t3,0x32d($s4)
/*  f1979ec:	0562000b */ 	bltzl	$t3,.PF0f197a1c
/*  f1979f0:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1979f4:	8e4c00dc */ 	lw	$t4,0xdc($s2)
.PF0f1979f8:
/*  f1979f8:	02802025 */ 	move	$a0,$s4
/*  f1979fc:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f197a00:	1d80001e */ 	bgtz	$t4,.PF0f197a7c
/*  f197a04:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f197a08:	0fc0e170 */ 	jal	chrGoToPos
/*  f197a0c:	24070002 */ 	li	$a3,0x2
/*  f197a10:	1000001b */ 	b	.PF0f197a80
/*  f197a14:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a18:	8e5801dc */ 	lw	$t8,0x1dc($s2)
.PF0f197a1c:
/*  f197a1c:	53000018 */ 	beqzl	$t8,.PF0f197a80
/*  f197a20:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a24:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f197a28:	53cf0015 */ 	beql	$s8,$t7,.PF0f197a80
/*  f197a2c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a30:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f197a34:	53200012 */ 	beqzl	$t9,.PF0f197a80
/*  f197a38:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a3c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197a40:	02802025 */ 	move	$a0,$s4
/*  f197a44:	02802025 */ 	move	$a0,$s4
/*  f197a48:	0fc64f9c */ 	jal	func0f192dc0
/*  f197a4c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197a50:	1040000a */ 	beqz	$v0,.PF0f197a7c
/*  f197a54:	2409002f */ 	li	$t1,0x2f
/*  f197a58:	a28902a0 */ 	sb	$t1,0x2a0($s4)
/*  f197a5c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197a60:	02802025 */ 	move	$a0,$s4
/*  f197a64:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197a68:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197a6c:	240a00fa */ 	li	$t2,0xfa
/*  f197a70:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197a74:	ae4a01d8 */ 	sw	$t2,0x1d8($s2)
/*  f197a78:	a25e0074 */ 	sb	$s8,0x74($s2)
.PF0f197a7c:
/*  f197a7c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
.PF0f197a80:
/*  f197a80:	240e0032 */ 	li	$t6,0x32
/*  f197a84:	1da00002 */ 	bgtz	$t5,.PF0f197a90
/*  f197a88:	00000000 */ 	nop
/*  f197a8c:	ae4e00dc */ 	sw	$t6,0xdc($s2)
.PF0f197a90:
/*  f197a90:	0fc655ca */ 	jal	func0f194670
/*  f197a94:	02802025 */ 	move	$a0,$s4
/*  f197a98:	1040006f */ 	beqz	$v0,.PF0f197c58
/*  f197a9c:	240b0029 */ 	li	$t3,0x29
/*  f197aa0:	1000006d */ 	b	.PF0f197c58
/*  f197aa4:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f197aa8:	2401002b */ 	li	$at,0x2b
.PF0f197aac:
/*  f197aac:	1441002f */ 	bne	$v0,$at,.PF0f197b6c
/*  f197ab0:	3c0c800b */ 	lui	$t4,0x800b
/*  f197ab4:	918cd138 */ 	lbu	$t4,-0x2ec8($t4)
/*  f197ab8:	24010004 */ 	li	$at,0x4
/*  f197abc:	5581001f */ 	bnel	$t4,$at,.PF0f197b3c
/*  f197ac0:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197ac4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f197ac8:	3c02800b */ 	lui	$v0,0x800b
/*  f197acc:	00187fc2 */ 	srl	$t7,$t8,0x1f
/*  f197ad0:	51e0001a */ 	beqzl	$t7,.PF0f197b3c
/*  f197ad4:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197ad8:	8442c6be */ 	lh	$v0,-0x3942($v0)
/*  f197adc:	8e5900bc */ 	lw	$t9,0xbc($s2)
/*  f197ae0:	53220006 */ 	beql	$t9,$v0,.PF0f197afc
/*  f197ae4:	8e8d001c */ 	lw	$t5,0x1c($s4)
/*  f197ae8:	9249004c */ 	lbu	$t1,0x4c($s2)
/*  f197aec:	312aff7f */ 	andi	$t2,$t1,0xff7f
/*  f197af0:	10000011 */ 	b	.PF0f197b38
/*  f197af4:	a24a004c */ 	sb	$t2,0x4c($s2)
/*  f197af8:	8e8d001c */ 	lw	$t5,0x1c($s4)
.PF0f197afc:
/*  f197afc:	85ae0028 */ 	lh	$t6,0x28($t5)
/*  f197b00:	51c2000e */ 	beql	$t6,$v0,.PF0f197b3c
/*  f197b04:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b08:	86440048 */ 	lh	$a0,0x48($s2)
/*  f197b0c:	04820006 */ 	bltzl	$a0,.PF0f197b28
/*  f197b10:	8644004a */ 	lh	$a0,0x4a($s2)
/*  f197b14:	0fc45b48 */ 	jal	padSetFlag
/*  f197b18:	3c050002 */ 	lui	$a1,0x2
/*  f197b1c:	10000007 */ 	b	.PF0f197b3c
/*  f197b20:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b24:	8644004a */ 	lh	$a0,0x4a($s2)
.PF0f197b28:
/*  f197b28:	04820004 */ 	bltzl	$a0,.PF0f197b3c
/*  f197b2c:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b30:	0fc45bfa */ 	jal	coverSetFlag
/*  f197b34:	24050100 */ 	li	$a1,0x100
.PF0f197b38:
/*  f197b38:	828b0007 */ 	lb	$t3,0x7($s4)
.PF0f197b3c:
/*  f197b3c:	2401000f */ 	li	$at,0xf
/*  f197b40:	240c0029 */ 	li	$t4,0x29
/*  f197b44:	11610003 */ 	beq	$t3,$at,.PF0f197b54
/*  f197b48:	00000000 */ 	nop
/*  f197b4c:	10000042 */ 	b	.PF0f197c58
/*  f197b50:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.PF0f197b54:
/*  f197b54:	0fc655ca */ 	jal	func0f194670
/*  f197b58:	02802025 */ 	move	$a0,$s4
/*  f197b5c:	1040003e */ 	beqz	$v0,.PF0f197c58
/*  f197b60:	24180029 */ 	li	$t8,0x29
/*  f197b64:	1000003c */ 	b	.PF0f197c58
/*  f197b68:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PF0f197b6c:
/*  f197b6c:	2401002c */ 	li	$at,0x2c
/*  f197b70:	54410029 */ 	bnel	$v0,$at,.PF0f197c18
/*  f197b74:	2401002e */ 	li	$at,0x2e
/*  f197b78:	0fc655ca */ 	jal	func0f194670
/*  f197b7c:	02802025 */ 	move	$a0,$s4
/*  f197b80:	10400003 */ 	beqz	$v0,.PF0f197b90
/*  f197b84:	240f0029 */ 	li	$t7,0x29
/*  f197b88:	10000033 */ 	b	.PF0f197c58
/*  f197b8c:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PF0f197b90:
/*  f197b90:	82990007 */ 	lb	$t9,0x7($s4)
/*  f197b94:	2401000f */ 	li	$at,0xf
/*  f197b98:	240a0029 */ 	li	$t2,0x29
/*  f197b9c:	17210008 */ 	bne	$t9,$at,.PF0f197bc0
/*  f197ba0:	00000000 */ 	nop
/*  f197ba4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197ba8:	10a00005 */ 	beqz	$a1,.PF0f197bc0
/*  f197bac:	00000000 */ 	nop
/*  f197bb0:	8ca90018 */ 	lw	$t1,0x18($a1)
/*  f197bb4:	3c03800b */ 	lui	$v1,0x800b
/*  f197bb8:	11200003 */ 	beqz	$t1,.PF0f197bc8
/*  f197bbc:	00000000 */ 	nop
.PF0f197bc0:
/*  f197bc0:	10000025 */ 	b	.PF0f197c58
/*  f197bc4:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PF0f197bc8:
/*  f197bc8:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f197bcc:	24010002 */ 	li	$at,0x2
/*  f197bd0:	12e30021 */ 	beq	$s7,$v1,.PF0f197c58
/*  f197bd4:	00000000 */ 	nop
/*  f197bd8:	1461001f */ 	bne	$v1,$at,.PF0f197c58
/*  f197bdc:	3c0d800b */ 	lui	$t5,0x800b
/*  f197be0:	8dadc7ec */ 	lw	$t5,-0x3814($t5)
/*  f197be4:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f197be8:	15ae001b */ 	bne	$t5,$t6,.PF0f197c58
/*  f197bec:	00000000 */ 	nop
/*  f197bf0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197bf4:	02802025 */ 	move	$a0,$s4
/*  f197bf8:	3c0b800b */ 	lui	$t3,0x800b
/*  f197bfc:	856bc782 */ 	lh	$t3,-0x387e($t3)
/*  f197c00:	240c0029 */ 	li	$t4,0x29
/*  f197c04:	144b0014 */ 	bne	$v0,$t3,.PF0f197c58
/*  f197c08:	00000000 */ 	nop
/*  f197c0c:	10000012 */ 	b	.PF0f197c58
/*  f197c10:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
/*  f197c14:	2401002e */ 	li	$at,0x2e
.PF0f197c18:
/*  f197c18:	1441000f */ 	bne	$v0,$at,.PF0f197c58
/*  f197c1c:	00000000 */ 	nop
/*  f197c20:	0fc655ca */ 	jal	func0f194670
/*  f197c24:	02802025 */ 	move	$a0,$s4
/*  f197c28:	10400003 */ 	beqz	$v0,.PF0f197c38
/*  f197c2c:	24180029 */ 	li	$t8,0x29
/*  f197c30:	10000009 */ 	b	.PF0f197c58
/*  f197c34:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PF0f197c38:
/*  f197c38:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197c3c:	02802025 */ 	move	$a0,$s4
/*  f197c40:	3c0f800b */ 	lui	$t7,0x800b
/*  f197c44:	85efc782 */ 	lh	$t7,-0x387e($t7)
/*  f197c48:	24190029 */ 	li	$t9,0x29
/*  f197c4c:	104f0002 */ 	beq	$v0,$t7,.PF0f197c58
/*  f197c50:	00000000 */ 	nop
/*  f197c54:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PF0f197c58:
/*  f197c58:	0fc64fd0 */ 	jal	func0f192e90
/*  f197c5c:	02802025 */ 	move	$a0,$s4
/*  f197c60:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197c64:	02802025 */ 	move	$a0,$s4
/*  f197c68:	8ec9000c */ 	lw	$t1,0xc($s6)
/*  f197c6c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f197c70:	012a001a */ 	div	$zero,$t1,$t2
/*  f197c74:	00006810 */ 	mfhi	$t5
/*  f197c78:	15400002 */ 	bnez	$t2,.PF0f197c84
/*  f197c7c:	00000000 */ 	nop
/*  f197c80:	0007000d */ 	break	0x7
.PF0f197c84:
/*  f197c84:	2401ffff */ 	li	$at,-1
/*  f197c88:	15410004 */ 	bne	$t2,$at,.PF0f197c9c
/*  f197c8c:	3c018000 */ 	lui	$at,0x8000
/*  f197c90:	15210002 */ 	bne	$t1,$at,.PF0f197c9c
/*  f197c94:	00000000 */ 	nop
/*  f197c98:	0006000d */ 	break	0x6
.PF0f197c9c:
/*  f197c9c:	144d0024 */ 	bne	$v0,$t5,.PF0f197d30
/*  f197ca0:	00000000 */ 	nop
/*  f197ca4:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f197ca8:	13ce0021 */ 	beq	$s8,$t6,.PF0f197d30
/*  f197cac:	00000000 */ 	nop
/*  f197cb0:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197cb4:	02802025 */ 	move	$a0,$s4
/*  f197cb8:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197cbc:	00408025 */ 	move	$s0,$v0
/*  f197cc0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f197cc4:	0fc4534d */ 	jal	waypointFindClosestToPos
/*  f197cc8:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f197ccc:	00408825 */ 	move	$s1,$v0
/*  f197cd0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f197cd4:	0fc4534d */ 	jal	waypointFindClosestToPos
/*  f197cd8:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f197cdc:	12200014 */ 	beqz	$s1,.PF0f197d30
/*  f197ce0:	00408025 */ 	move	$s0,$v0
/*  f197ce4:	10400012 */ 	beqz	$v0,.PF0f197d30
/*  f197ce8:	00000000 */ 	nop
/*  f197cec:	8ecb0008 */ 	lw	$t3,0x8($s6)
/*  f197cf0:	868f0000 */ 	lh	$t7,0x0($s4)
/*  f197cf4:	000b6243 */ 	sra	$t4,$t3,0x9
/*  f197cf8:	000cc1c0 */ 	sll	$t8,$t4,0x7
/*  f197cfc:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f197d00:	03192021 */ 	addu	$a0,$t8,$t9
/*  f197d04:	0fc45348 */ 	jal	waypointSetHashThing
/*  f197d08:	00802825 */ 	move	$a1,$a0
/*  f197d0c:	02002025 */ 	move	$a0,$s0
/*  f197d10:	02202825 */ 	move	$a1,$s1
/*  f197d14:	264601e8 */ 	addiu	$a2,$s2,0x1e8
/*  f197d18:	0fc45733 */ 	jal	waypointFindRoute
/*  f197d1c:	24070008 */ 	li	$a3,0x8
/*  f197d20:	ae420208 */ 	sw	$v0,0x208($s2)
/*  f197d24:	00002025 */ 	move	$a0,$zero
/*  f197d28:	0fc45348 */ 	jal	waypointSetHashThing
/*  f197d2c:	00002825 */ 	move	$a1,$zero
.PF0f197d30:
/*  f197d30:	0fc667fb */ 	jal	aibotTickInventory
/*  f197d34:	02802025 */ 	move	$a0,$s4
/*  f197d38:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f197d3c:	00009825 */ 	move	$s3,$zero
/*  f197d40:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f197d44:	02408825 */ 	move	$s1,$s2
.PF0f197d48:
/*  f197d48:	8e22005c */ 	lw	$v0,0x5c($s1)
/*  f197d4c:	0000a825 */ 	move	$s5,$zero
/*  f197d50:	18400004 */ 	blez	$v0,.PF0f197d64
/*  f197d54:	00000000 */ 	nop
/*  f197d58:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f197d5c:	00495023 */ 	subu	$t2,$v0,$t1
/*  f197d60:	ae2a005c */ 	sw	$t2,0x5c($s1)
.PF0f197d64:
/*  f197d64:	16770004 */ 	bne	$s3,$s7,.PF0f197d78
/*  f197d68:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f197d6c:	51a00003 */ 	beqzl	$t5,.PF0f197d7c
/*  f197d70:	8e4e0044 */ 	lw	$t6,0x44($s2)
/*  f197d74:	ae37005c */ 	sw	$s7,0x5c($s1)
.PF0f197d78:
/*  f197d78:	8e4e0044 */ 	lw	$t6,0x44($s2)
.PF0f197d7c:
/*  f197d7c:	15c00212 */ 	bnez	$t6,.PF0f1985c8
/*  f197d80:	00000000 */ 	nop
/*  f197d84:	8e4b00cc */ 	lw	$t3,0xcc($s2)
/*  f197d88:	1d60020f */ 	bgtz	$t3,.PF0f1985c8
/*  f197d8c:	00000000 */ 	nop
/*  f197d90:	8e42004c */ 	lw	$v0,0x4c($s2)
/*  f197d94:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f197d98:	02581821 */ 	addu	$v1,$s2,$t8
/*  f197d9c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f197da0:	05e300b5 */ 	bgezl	$t7,.PF0f198078
/*  f197da4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197da8:	8479003c */ 	lh	$t9,0x3c($v1)
/*  f197dac:	07200206 */ 	bltz	$t9,.PF0f1985c8
/*  f197db0:	00000000 */ 	nop
/*  f197db4:	8469002c */ 	lh	$t1,0x2c($v1)
/*  f197db8:	1d200203 */ 	bgtz	$t1,.PF0f1985c8
/*  f197dbc:	00000000 */ 	nop
/*  f197dc0:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f197dc4:	2401001c */ 	li	$at,0x1c
/*  f197dc8:	2404001c */ 	li	$a0,0x1c
/*  f197dcc:	1541000d */ 	bne	$t2,$at,.PF0f197e04
/*  f197dd0:	02e02825 */ 	move	$a1,$s7
/*  f197dd4:	0fc26dd4 */ 	jal	weaponGetMinClipQty
/*  f197dd8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ddc:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f197de0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197de4:	02802025 */ 	move	$a0,$s4
/*  f197de8:	01a2082a */ 	slt	$at,$t5,$v0
/*  f197dec:	10200005 */ 	beqz	$at,.PF0f197e04
/*  f197df0:	02602825 */ 	move	$a1,$s3
/*  f197df4:	0fc651d3 */ 	jal	func0f19369c
/*  f197df8:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197dfc:	100001f2 */ 	b	.PF0f1985c8
/*  f197e00:	00000000 */ 	nop
.PF0f197e04:
/*  f197e04:	846e003c */ 	lh	$t6,0x3c($v1)
/*  f197e08:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f197e0c:	01cb6023 */ 	subu	$t4,$t6,$t3
/*  f197e10:	a46c003c */ 	sh	$t4,0x3c($v1)
/*  f197e14:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f197e18:	53cf0042 */ 	beql	$s8,$t7,.PF0f197f24
/*  f197e1c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e20:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f197e24:	5300003f */ 	beqzl	$t8,.PF0f197f24
/*  f197e28:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e2c:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f197e30:	3c0e8009 */ 	lui	$t6,0x8009
/*  f197e34:	8e59011c */ 	lw	$t9,0x11c($s2)
/*  f197e38:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f197e3c:	02802025 */ 	move	$a0,$s4
/*  f197e40:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f197e44:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f197e48:	91ce8264 */ 	lbu	$t6,-0x7d9c($t6)
/*  f197e4c:	032e082a */ 	slt	$at,$t9,$t6
/*  f197e50:	54200034 */ 	bnezl	$at,.PF0f197f24
/*  f197e54:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e58:	0fc644c8 */ 	jal	func0f190260
/*  f197e5c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197e60:	14400030 */ 	bnez	$v0,.PF0f197f24
/*  f197e64:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197e68:	8e4b0020 */ 	lw	$t3,0x20($s2)
/*  f197e6c:	2401001c */ 	li	$at,0x1c
/*  f197e70:	02802025 */ 	move	$a0,$s4
/*  f197e74:	15610014 */ 	bne	$t3,$at,.PF0f197ec8
/*  f197e78:	24050028 */ 	li	$a1,0x28
/*  f197e7c:	02802025 */ 	move	$a0,$s4
/*  f197e80:	2405001e */ 	li	$a1,0x1e
/*  f197e84:	00003025 */ 	move	$a2,$zero
/*  f197e88:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f197e8c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197e90:	1040000b */ 	beqz	$v0,.PF0f197ec0
/*  f197e94:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197e98:	02802025 */ 	move	$a0,$s4
/*  f197e9c:	0fc124d8 */ 	jal	chrGetDistanceToTarget
/*  f197ea0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ea4:	3c014352 */ 	lui	$at,0x4352
/*  f197ea8:	44813000 */ 	mtc1	$at,$f6
/*  f197eac:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197eb0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f197eb4:	00000000 */ 	nop
/*  f197eb8:	4502001b */ 	bc1fl	.PF0f197f28
/*  f197ebc:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197ec0:
/*  f197ec0:	10000018 */ 	b	.PF0f197f24
/*  f197ec4:	a460003c */ 	sh	$zero,0x3c($v1)
.PF0f197ec8:
/*  f197ec8:	00003025 */ 	move	$a2,$zero
/*  f197ecc:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f197ed0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ed4:	10400010 */ 	beqz	$v0,.PF0f197f18
/*  f197ed8:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197edc:	3c014352 */ 	lui	$at,0x4352
/*  f197ee0:	44815000 */ 	mtc1	$at,$f10
/*  f197ee4:	3c014316 */ 	lui	$at,0x4316
/*  f197ee8:	44819000 */ 	mtc1	$at,$f18
/*  f197eec:	02802025 */ 	move	$a0,$s4
/*  f197ef0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ef4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f197ef8:	0fc124d8 */ 	jal	chrGetDistanceToTarget
/*  f197efc:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f197f00:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f197f04:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197f08:	4600403c */ 	c.lt.s	$f8,$f0
/*  f197f0c:	00000000 */ 	nop
/*  f197f10:	45020005 */ 	bc1fl	.PF0f197f28
/*  f197f14:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197f18:
/*  f197f18:	10000002 */ 	b	.PF0f197f24
/*  f197f1c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197f20:	a460003c */ 	sh	$zero,0x3c($v1)
.PF0f197f24:
/*  f197f24:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197f28:
/*  f197f28:	3c014352 */ 	lui	$at,0x4352
/*  f197f2c:	058101a6 */ 	bgez	$t4,.PF0f1985c8
/*  f197f30:	00000000 */ 	nop
/*  f197f34:	44813000 */ 	mtc1	$at,$f6
/*  f197f38:	02802025 */ 	move	$a0,$s4
/*  f197f3c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f197f40:	44105000 */ 	mfc1	$s0,$f10
/*  f197f44:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f197f48:	00000000 */ 	nop
/*  f197f4c:	02802025 */ 	move	$a0,$s4
/*  f197f50:	24050002 */ 	li	$a1,0x2
/*  f197f54:	02003025 */ 	move	$a2,$s0
/*  f197f58:	0fc0eef2 */ 	jal	chrPunchInflictDamage
/*  f197f5c:	00003825 */ 	move	$a3,$zero
/*  f197f60:	16600199 */ 	bnez	$s3,.PF0f1985c8
/*  f197f64:	00000000 */ 	nop
/*  f197f68:	8e580020 */ 	lw	$t8,0x20($s2)
/*  f197f6c:	2709ffff */ 	addiu	$t1,$t8,-1
/*  f197f70:	2d21001c */ 	sltiu	$at,$t1,0x1c
/*  f197f74:	10200006 */ 	beqz	$at,.PF0f197f90
/*  f197f78:	00094880 */ 	sll	$t1,$t1,0x2
/*  f197f7c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f197f80:	00290821 */ 	addu	$at,$at,$t1
/*  f197f84:	8c29a5b8 */ 	lw	$t1,-0x5a48($at)
/*  f197f88:	01200008 */ 	jr	$t1
/*  f197f8c:	00000000 */ 	nop
.PF0f197f90:
/*  f197f90:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f197f94:	24190064 */ 	li	$t9,0x64
/*  f197f98:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f197f9c:	91a20048 */ 	lbu	$v0,0x48($t5)
/*  f197fa0:	14400003 */ 	bnez	$v0,.PF0f197fb0
/*  f197fa4:	00000000 */ 	nop
/*  f197fa8:	10000007 */ 	b	.PF0f197fc8
/*  f197fac:	a659003c */ 	sh	$t9,0x3c($s2)
.PF0f197fb0:
/*  f197fb0:	16e20004 */ 	bne	$s7,$v0,.PF0f197fc4
/*  f197fb4:	240b0019 */ 	li	$t3,0x19
/*  f197fb8:	240e0032 */ 	li	$t6,0x32
/*  f197fbc:	10000002 */ 	b	.PF0f197fc8
/*  f197fc0:	a64e003c */ 	sh	$t6,0x3c($s2)
.PF0f197fc4:
/*  f197fc4:	a64b003c */ 	sh	$t3,0x3c($s2)
.PF0f197fc8:
/*  f197fc8:	0c004ad4 */ 	jal	random
/*  f197fcc:	00000000 */ 	nop
/*  f197fd0:	24010003 */ 	li	$at,0x3
/*  f197fd4:	0041001b */ 	divu	$zero,$v0,$at
/*  f197fd8:	00006010 */ 	mfhi	$t4
/*  f197fdc:	1580017a */ 	bnez	$t4,.PF0f1985c8
/*  f197fe0:	00000000 */ 	nop
/*  f197fe4:	864f003c */ 	lh	$t7,0x3c($s2)
/*  f197fe8:	25f8fff0 */ 	addiu	$t8,$t7,-16
/*  f197fec:	10000176 */ 	b	.PF0f1985c8
/*  f197ff0:	a658003e */ 	sh	$t8,0x3e($s2)
/*  f197ff4:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197ff8:	240d0064 */ 	li	$t5,0x64
/*  f197ffc:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f198000:	91420048 */ 	lbu	$v0,0x48($t2)
/*  f198004:	14400003 */ 	bnez	$v0,.PF0f198014
/*  f198008:	00000000 */ 	nop
/*  f19800c:	10000007 */ 	b	.PF0f19802c
/*  f198010:	a64d003c */ 	sh	$t5,0x3c($s2)
.PF0f198014:
/*  f198014:	16e20004 */ 	bne	$s7,$v0,.PF0f198028
/*  f198018:	240e0032 */ 	li	$t6,0x32
/*  f19801c:	2419004b */ 	li	$t9,0x4b
/*  f198020:	10000002 */ 	b	.PF0f19802c
/*  f198024:	a659003c */ 	sh	$t9,0x3c($s2)
.PF0f198028:
/*  f198028:	a64e003c */ 	sh	$t6,0x3c($s2)
.PF0f19802c:
/*  f19802c:	8e8b0174 */ 	lw	$t3,0x174($s4)
/*  f198030:	11600165 */ 	beqz	$t3,.PF0f1985c8
/*  f198034:	00000000 */ 	nop
/*  f198038:	864c003c */ 	lh	$t4,0x3c($s2)
/*  f19803c:	258fffdf */ 	addiu	$t7,$t4,-33
/*  f198040:	10000161 */ 	b	.PF0f1985c8
/*  f198044:	a64f003e */ 	sh	$t7,0x3e($s2)
/*  f198048:	24180032 */ 	li	$t8,0x32
/*  f19804c:	a658003c */ 	sh	$t8,0x3c($s2)
/*  f198050:	2404001c */ 	li	$a0,0x1c
/*  f198054:	0fc26dd4 */ 	jal	weaponGetMinClipQty
/*  f198058:	02e02825 */ 	move	$a1,$s7
/*  f19805c:	8e490024 */ 	lw	$t1,0x24($s2)
/*  f198060:	01225023 */ 	subu	$t2,$t1,$v0
/*  f198064:	10000158 */ 	b	.PF0f1985c8
/*  f198068:	ae4a0024 */ 	sw	$t2,0x24($s2)
/*  f19806c:	10000156 */ 	b	.PF0f1985c8
/*  f198070:	a640003c */ 	sh	$zero,0x3c($s2)
/*  f198074:	8e440020 */ 	lw	$a0,0x20($s2)
.PF0f198078:
/*  f198078:	24010019 */ 	li	$at,0x19
/*  f19807c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f198080:	14810011 */ 	bne	$a0,$at,.PF0f1980c8
/*  f198084:	00022880 */ 	sll	$a1,$v0,0x2
/*  f198088:	07230010 */ 	bgezl	$t9,.PF0f1980cc
/*  f19808c:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f198090:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f198094:	53ce000d */ 	beql	$s8,$t6,.PF0f1980cc
/*  f198098:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f19809c:	8e4b0024 */ 	lw	$t3,0x24($s2)
/*  f1980a0:	19600149 */ 	blez	$t3,.PF0f1985c8
/*  f1980a4:	00000000 */ 	nop
/*  f1980a8:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1980ac:	02802025 */ 	move	$a0,$s4
/*  f1980b0:	0fc66e54 */ 	jal	aibotCreateSlayerRocket
/*  f1980b4:	02802025 */ 	move	$a0,$s4
/*  f1980b8:	8e4c0024 */ 	lw	$t4,0x24($s2)
/*  f1980bc:	258fffff */ 	addiu	$t7,$t4,-1
/*  f1980c0:	10000141 */ 	b	.PF0f1985c8
/*  f1980c4:	ae4f0024 */ 	sw	$t7,0x24($s2)
.PF0f1980c8:
/*  f1980c8:	0005c7c2 */ 	srl	$t8,$a1,0x1f
.PF0f1980cc:
/*  f1980cc:	0fc66ce7 */ 	jal	func0f19a29c
/*  f1980d0:	03002825 */ 	move	$a1,$t8
/*  f1980d4:	1040005b */ 	beqz	$v0,.PF0f198244
/*  f1980d8:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f1980dc:	1660013a */ 	bnez	$s3,.PF0f1985c8
/*  f1980e0:	00000000 */ 	nop
/*  f1980e4:	8e420034 */ 	lw	$v0,0x34($s2)
/*  f1980e8:	02402025 */ 	move	$a0,$s2
/*  f1980ec:	58400005 */ 	blezl	$v0,.PF0f198104
/*  f1980f0:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f1980f4:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f1980f8:	00495023 */ 	subu	$t2,$v0,$t1
/*  f1980fc:	ae4a0034 */ 	sw	$t2,0x34($s2)
/*  f198100:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PF0f198104:
/*  f198104:	8db90034 */ 	lw	$t9,0x34($t5)
/*  f198108:	1f20012f */ 	bgtz	$t9,.PF0f1985c8
/*  f19810c:	00000000 */ 	nop
/*  f198110:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f198114:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198118:	00003825 */ 	move	$a3,$zero
/*  f19811c:	00067080 */ 	sll	$t6,$a2,0x2
/*  f198120:	0fc66b39 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f198124:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f198128:	5c400008 */ 	bgtzl	$v0,.PF0f19814c
/*  f19812c:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f198130:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198134:	2401000e */ 	li	$at,0xe
/*  f198138:	10810003 */ 	beq	$a0,$at,.PF0f198148
/*  f19813c:	2401000f */ 	li	$at,0xf
/*  f198140:	14810121 */ 	bne	$a0,$at,.PF0f1985c8
/*  f198144:	00000000 */ 	nop
.PF0f198148:
/*  f198148:	868c017e */ 	lh	$t4,0x17e($s4)
.PF0f19814c:
/*  f19814c:	00008025 */ 	move	$s0,$zero
/*  f198150:	13cc0018 */ 	beq	$s8,$t4,.PF0f1981b4
/*  f198154:	00000000 */ 	nop
/*  f198158:	8e4f0128 */ 	lw	$t7,0x128($s2)
/*  f19815c:	11e00015 */ 	beqz	$t7,.PF0f1981b4
/*  f198160:	00000000 */ 	nop
/*  f198164:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f198168:	3c198009 */ 	lui	$t9,0x8009
/*  f19816c:	8e58011c */ 	lw	$t8,0x11c($s2)
/*  f198170:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f198174:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f198178:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f19817c:	93398264 */ 	lbu	$t9,-0x7d9c($t9)
/*  f198180:	0319082a */ 	slt	$at,$t8,$t9
/*  f198184:	1420000b */ 	bnez	$at,.PF0f1981b4
/*  f198188:	00000000 */ 	nop
/*  f19818c:	0fc644c8 */ 	jal	func0f190260
/*  f198190:	02802025 */ 	move	$a0,$s4
/*  f198194:	14400006 */ 	bnez	$v0,.PF0f1981b0
/*  f198198:	02802025 */ 	move	$a0,$s4
/*  f19819c:	2405002d */ 	li	$a1,0x2d
/*  f1981a0:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f1981a4:	00003025 */ 	move	$a2,$zero
/*  f1981a8:	10400002 */ 	beqz	$v0,.PF0f1981b4
/*  f1981ac:	00000000 */ 	nop
.PF0f1981b0:
/*  f1981b0:	02e08025 */ 	move	$s0,$s7
.PF0f1981b4:
/*  f1981b4:	12000104 */ 	beqz	$s0,.PF0f1985c8
/*  f1981b8:	00000000 */ 	nop
/*  f1981bc:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1981c0:	02802025 */ 	move	$a0,$s4
/*  f1981c4:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f1981c8:	02402025 */ 	move	$a0,$s2
/*  f1981cc:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f1981d0:	00067080 */ 	sll	$t6,$a2,0x2
/*  f1981d4:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f1981d8:	0fc66b9c */ 	jal	aibotTryRemoveAmmoFromReserve
/*  f1981dc:	02e03825 */ 	move	$a3,$s7
/*  f1981e0:	0fc66d1f */ 	jal	func0f19a37c
/*  f1981e4:	02802025 */ 	move	$a0,$s4
/*  f1981e8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1981ec:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1981f0:	00056080 */ 	sll	$t4,$a1,0x2
/*  f1981f4:	0fc2c531 */ 	jal	weaponGetFunctionById
/*  f1981f8:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f1981fc:	5040000d */ 	beqzl	$v0,.PF0f198234
/*  f198200:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198204:	8c490010 */ 	lw	$t1,0x10($v0)
/*  f198208:	02802025 */ 	move	$a0,$s4
/*  f19820c:	00095340 */ 	sll	$t2,$t1,0xd
/*  f198210:	05430008 */ 	bgezl	$t2,.PF0f198234
/*  f198214:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198218:	0fc663a5 */ 	jal	aibotRemoveInvItem
/*  f19821c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198220:	02802025 */ 	move	$a0,$s4
/*  f198224:	02e02825 */ 	move	$a1,$s7
/*  f198228:	0fc6696c */ 	jal	aibotSwitchToWeapon
/*  f19822c:	00003025 */ 	move	$a2,$zero
/*  f198230:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PF0f198234:
/*  f198234:	0fc66cf7 */ 	jal	aibotGetProjectileThrowInterval
/*  f198238:	8da40020 */ 	lw	$a0,0x20($t5)
/*  f19823c:	100000e2 */ 	b	.PF0f1985c8
/*  f198240:	ae420034 */ 	sw	$v0,0x34($s2)
.PF0f198244:
/*  f198244:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f198248:	8f2e0170 */ 	lw	$t6,0x170($t9)
/*  f19824c:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f198250:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198254:	11c000d9 */ 	beqz	$t6,.PF0f1985bc
/*  f198258:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f19825c:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f198260:	596000d7 */ 	blezl	$t3,.PF0f1985c0
/*  f198264:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f198268:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19826c:	00008025 */ 	move	$s0,$zero
/*  f198270:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198274:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198278:	0fc2c8f8 */ 	jal	weaponGetNumTicksPerShot
/*  f19827c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f198280:	5c400030 */ 	bgtzl	$v0,.PF0f198344
/*  f198284:	02e08025 */ 	move	$s0,$s7
/*  f198288:	8e490020 */ 	lw	$t1,0x20($s2)
/*  f19828c:	24010006 */ 	li	$at,0x6
/*  f198290:	55210027 */ 	bnel	$t1,$at,.PF0f198330
/*  f198294:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198298:	8e4a004c */ 	lw	$t2,0x4c($s2)
/*  f19829c:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f1982a0:	000dc7c2 */ 	srl	$t8,$t5,0x1f
/*  f1982a4:	56f80022 */ 	bnel	$s7,$t8,.PF0f198330
/*  f1982a8:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f1982ac:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f1982b0:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1982b4:	1420001d */ 	bnez	$at,.PF0f19832c
/*  f1982b8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1982bc:	c428a628 */ 	lwc1	$f8,-0x59d8($at)
/*  f1982c0:	c6c4004c */ 	lwc1	$f4,0x4c($s6)
/*  f1982c4:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1982c8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1982cc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f1982d0:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f1982d4:	44039000 */ 	mfc1	$v1,$f18
/*  f1982d8:	44819000 */ 	mtc1	$at,$f18
/*  f1982dc:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f1982e0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1982e4:	e62a00e4 */ 	swc1	$f10,0xe4($s1)
/*  f1982e8:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1982ec:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1982f0:	00000000 */ 	nop
/*  f1982f4:	45020006 */ 	bc1fl	.PF0f198310
/*  f1982f8:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f1982fc:	44812000 */ 	mtc1	$at,$f4
/*  f198300:	00000000 */ 	nop
/*  f198304:	e62400e4 */ 	swc1	$f4,0xe4($s1)
/*  f198308:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f19830c:	4600020d */ 	trunc.w.s	$f8,$f0
.PF0f198310:
/*  f198310:	44024000 */ 	mfc1	$v0,$f8
/*  f198314:	00000000 */ 	nop
/*  f198318:	50430005 */ 	beql	$v0,$v1,.PF0f198330
/*  f19831c:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198320:	8e2c0024 */ 	lw	$t4,0x24($s1)
/*  f198324:	258fffff */ 	addiu	$t7,$t4,-1
/*  f198328:	ae2f0024 */ 	sw	$t7,0x24($s1)
.PF0f19832c:
/*  f19832c:	8e29005c */ 	lw	$t1,0x5c($s1)
.PF0f198330:
/*  f198330:	1d200004 */ 	bgtz	$t1,.PF0f198344
/*  f198334:	00000000 */ 	nop
/*  f198338:	10000002 */ 	b	.PF0f198344
/*  f19833c:	02e08025 */ 	move	$s0,$s7
/*  f198340:	02e08025 */ 	move	$s0,$s7
.PF0f198344:
/*  f198344:	52000052 */ 	beqzl	$s0,.PF0f198490
/*  f198348:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19834c:	8e2a00c4 */ 	lw	$t2,0xc4($s1)
/*  f198350:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198354:	15400004 */ 	bnez	$t2,.PF0f198368
/*  f198358:	00000000 */ 	nop
/*  f19835c:	91b8004d */ 	lbu	$t8,0x4d($t5)
/*  f198360:	5b000004 */ 	blezl	$t8,.PF0f198374
/*  f198364:	8699017e */ 	lh	$t9,0x17e($s4)
.PF0f198368:
/*  f198368:	1000003a */ 	b	.PF0f198454
/*  f19836c:	02e0a825 */ 	move	$s5,$s7
/*  f198370:	8699017e */ 	lh	$t9,0x17e($s4)
.PF0f198374:
/*  f198374:	13d90037 */ 	beq	$s8,$t9,.PF0f198454
/*  f198378:	00000000 */ 	nop
/*  f19837c:	8e4e0128 */ 	lw	$t6,0x128($s2)
/*  f198380:	11c00034 */ 	beqz	$t6,.PF0f198454
/*  f198384:	00000000 */ 	nop
/*  f198388:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f19838c:	3c0a8009 */ 	lui	$t2,0x8009
/*  f198390:	8e4b011c */ 	lw	$t3,0x11c($s2)
/*  f198394:	918f0048 */ 	lbu	$t7,0x48($t4)
/*  f198398:	000f4940 */ 	sll	$t1,$t7,0x5
/*  f19839c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1983a0:	914a8264 */ 	lbu	$t2,-0x7d9c($t2)
/*  f1983a4:	016a082a */ 	slt	$at,$t3,$t2
/*  f1983a8:	1420002a */ 	bnez	$at,.PF0f198454
/*  f1983ac:	00000000 */ 	nop
/*  f1983b0:	0fc644c8 */ 	jal	func0f190260
/*  f1983b4:	02802025 */ 	move	$a0,$s4
/*  f1983b8:	14400006 */ 	bnez	$v0,.PF0f1983d4
/*  f1983bc:	02802025 */ 	move	$a0,$s4
/*  f1983c0:	2405002d */ 	li	$a1,0x2d
/*  f1983c4:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f1983c8:	00003025 */ 	move	$a2,$zero
/*  f1983cc:	10400021 */ 	beqz	$v0,.PF0f198454
/*  f1983d0:	00000000 */ 	nop
.PF0f1983d4:
/*  f1983d4:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f1983d8:	02802025 */ 	move	$a0,$s4
/*  f1983dc:	0fc0e706 */ 	jal	chrIsDead
/*  f1983e0:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1983e4:	1440001b */ 	bnez	$v0,.PF0f198454
/*  f1983e8:	00000000 */ 	nop
/*  f1983ec:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1983f0:	2401000b */ 	li	$at,0xb
/*  f1983f4:	02e0a825 */ 	move	$s5,$s7
/*  f1983f8:	54810009 */ 	bnel	$a0,$at,.PF0f198420
/*  f1983fc:	24010014 */ 	li	$at,0x14
/*  f198400:	8e4d004c */ 	lw	$t5,0x4c($s2)
/*  f198404:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f198408:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f19840c:	56f90004 */ 	bnel	$s7,$t9,.PF0f198420
/*  f198410:	24010014 */ 	li	$at,0x14
/*  f198414:	1000000f */ 	b	.PF0f198454
/*  f198418:	ae3700c4 */ 	sw	$s7,0xc4($s1)
/*  f19841c:	24010014 */ 	li	$at,0x14
.PF0f198420:
/*  f198420:	1481000c */ 	bne	$a0,$at,.PF0f198454
/*  f198424:	00137040 */ 	sll	$t6,$s3,0x1
/*  f198428:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f19842c:	846c00e0 */ 	lh	$t4,0xe0($v1)
/*  f198430:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f198434:	240a004b */ 	li	$t2,0x4b
/*  f198438:	018f4821 */ 	addu	$t1,$t4,$t7
/*  f19843c:	a46900e0 */ 	sh	$t1,0xe0($v1)
/*  f198440:	846b00e0 */ 	lh	$t3,0xe0($v1)
/*  f198444:	2961004c */ 	slti	$at,$t3,0x4c
/*  f198448:	14200002 */ 	bnez	$at,.PF0f198454
/*  f19844c:	00000000 */ 	nop
/*  f198450:	a46a00e0 */ 	sh	$t2,0xe0($v1)
.PF0f198454:
/*  f198454:	16a0000d */ 	bnez	$s5,.PF0f19848c
/*  f198458:	00136840 */ 	sll	$t5,$s3,0x1
/*  f19845c:	024d1821 */ 	addu	$v1,$s2,$t5
/*  f198460:	846200e0 */ 	lh	$v0,0xe0($v1)
/*  f198464:	5840000a */ 	blezl	$v0,.PF0f198490
/*  f198468:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19846c:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f198470:	02e0a825 */ 	move	$s5,$s7
/*  f198474:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f198478:	a47900e0 */ 	sh	$t9,0xe0($v1)
/*  f19847c:	846e00e0 */ 	lh	$t6,0xe0($v1)
/*  f198480:	05c30003 */ 	bgezl	$t6,.PF0f198490
/*  f198484:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198488:	a46000e0 */ 	sh	$zero,0xe0($v1)
.PF0f19848c:
/*  f19848c:	8e45004c */ 	lw	$a1,0x4c($s2)
.PF0f198490:
/*  f198490:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198494:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198498:	0fc2c8f8 */ 	jal	weaponGetNumTicksPerShot
/*  f19849c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f1984a0:	1c400049 */ 	bgtz	$v0,.PF0f1985c8
/*  f1984a4:	00000000 */ 	nop
/*  f1984a8:	12a00047 */ 	beqz	$s5,.PF0f1985c8
/*  f1984ac:	00000000 */ 	nop
/*  f1984b0:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1984b4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1984b8:	00054880 */ 	sll	$t1,$a1,0x2
/*  f1984bc:	0fc66dc3 */ 	jal	func0f19a60c
/*  f1984c0:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f1984c4:	28410006 */ 	slti	$at,$v0,0x6
/*  f1984c8:	1420000b */ 	bnez	$at,.PF0f1984f8
/*  f1984cc:	ae22005c */ 	sw	$v0,0x5c($s1)
/*  f1984d0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1984d4:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f1984d8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1984dc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f1984e0:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f1984e4:	2401003c */ 	li	$at,0x3c
/*  f1984e8:	01a1001a */ 	div	$zero,$t5,$at
/*  f1984ec:	0000c012 */ 	mflo	$t8
/*  f1984f0:	ae38005c */ 	sw	$t8,0x5c($s1)
/*  f1984f4:	00000000 */ 	nop
.PF0f1984f8:
/*  f1984f8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1984fc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198500:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f198504:	0fc2c531 */ 	jal	weaponGetFunctionById
/*  f198508:	00192fc2 */ 	srl	$a1,$t9,0x1f
/*  f19850c:	1040002e */ 	beqz	$v0,.PF0f1985c8
/*  f198510:	00000000 */ 	nop
/*  f198514:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f198518:	306c1002 */ 	andi	$t4,$v1,0x1002
/*  f19851c:	1180002a */ 	beqz	$t4,.PF0f1985c8
/*  f198520:	00000000 */ 	nop
/*  f198524:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f198528:	30691000 */ 	andi	$t1,$v1,0x1000
/*  f19852c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f198530:	14200025 */ 	bnez	$at,.PF0f1985c8
/*  f198534:	00000000 */ 	nop
/*  f198538:	11200003 */ 	beqz	$t1,.PF0f198548
/*  f19853c:	24040003 */ 	li	$a0,0x3
/*  f198540:	10000001 */ 	b	.PF0f198548
/*  f198544:	24040002 */ 	li	$a0,0x2
.PF0f198548:
/*  f198548:	8e8b02d4 */ 	lw	$t3,0x2d4($s4)
/*  f19854c:	01731021 */ 	addu	$v0,$t3,$s3
/*  f198550:	904a004d */ 	lbu	$t2,0x4d($v0)
/*  f198554:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f198558:	a04d004d */ 	sb	$t5,0x4d($v0)
/*  f19855c:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f198560:	03131021 */ 	addu	$v0,$t8,$s3
/*  f198564:	9059004d */ 	lbu	$t9,0x4d($v0)
/*  f198568:	0324001a */ 	div	$zero,$t9,$a0
/*  f19856c:	00007010 */ 	mfhi	$t6
/*  f198570:	a04e004d */ 	sb	$t6,0x4d($v0)
/*  f198574:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f198578:	14800002 */ 	bnez	$a0,.PF0f198584
/*  f19857c:	00000000 */ 	nop
/*  f198580:	0007000d */ 	break	0x7
.PF0f198584:
/*  f198584:	2401ffff */ 	li	$at,-1
/*  f198588:	14810004 */ 	bne	$a0,$at,.PF0f19859c
/*  f19858c:	3c018000 */ 	lui	$at,0x8000
/*  f198590:	17210002 */ 	bne	$t9,$at,.PF0f19859c
/*  f198594:	00000000 */ 	nop
/*  f198598:	0006000d */ 	break	0x6
.PF0f19859c:
/*  f19859c:	00736021 */ 	addu	$t4,$v1,$s3
/*  f1985a0:	918f004d */ 	lbu	$t7,0x4d($t4)
/*  f1985a4:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f1985a8:	11e00007 */ 	beqz	$t7,.PF0f1985c8
/*  f1985ac:	24090005 */ 	li	$t1,0x5
/*  f1985b0:	006b5021 */ 	addu	$t2,$v1,$t3
/*  f1985b4:	10000004 */ 	b	.PF0f1985c8
/*  f1985b8:	ad49005c */ 	sw	$t1,0x5c($t2)
.PF0f1985bc:
/*  f1985bc:	ae2000c4 */ 	sw	$zero,0xc4($s1)
.PF0f1985c0:
/*  f1985c0:	a1a0004d */ 	sb	$zero,0x4d($t5)
/*  f1985c4:	a72000e0 */ 	sh	$zero,0xe0($t9)
.PF0f1985c8:
/*  f1985c8:	52a00007 */ 	beqzl	$s5,.PF0f1985e8
/*  f1985cc:	02802025 */ 	move	$a0,$s4
/*  f1985d0:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1985d4:	02802025 */ 	move	$a0,$s4
/*  f1985d8:	56600003 */ 	bnezl	$s3,.PF0f1985e8
/*  f1985dc:	02802025 */ 	move	$a0,$s4
/*  f1985e0:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f1985e4:	02802025 */ 	move	$a0,$s4
.PF0f1985e8:
/*  f1985e8:	02602825 */ 	move	$a1,$s3
/*  f1985ec:	0fc0fec3 */ 	jal	func0f03f988
/*  f1985f0:	02a03025 */ 	move	$a2,$s5
/*  f1985f4:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f1985f8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1985fc:	24010002 */ 	li	$at,0x2
/*  f198600:	25cc0004 */ 	addiu	$t4,$t6,0x4
/*  f198604:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f198608:	1661fdcf */ 	bne	$s3,$at,.PF0f197d48
/*  f19860c:	26310004 */ 	addiu	$s1,$s1,0x4
.PF0f198610:
/*  f198610:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f198614:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f198618:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f19861c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f198620:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f198624:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f198628:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f19862c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f198630:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f198634:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f198638:	03e00008 */ 	jr	$ra
/*  f19863c:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#else
GLOBAL_ASM(
glabel func0f194b40
.late_rodata
glabel var7f1b8f54
.word 0x49742400
glabel var7f1b8f58
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f5c
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8f60
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8f64
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8f68
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f6c
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f70
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f74
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8f78
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8f7c
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f80
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f84
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f88
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f8c
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f90
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f94
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f98
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8f9c
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fa0
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fa4
.word func0f194b40+0x245c # f196f9c
glabel var7f1b8fa8
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fac
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fb0
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fb4
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fb8
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fbc
.word func0f194b40+0x23e4 # f196f24
glabel var7f1b8fc0
.word func0f194b40+0x2380 # f196ec0
glabel var7f1b8fc4
.word func0f194b40+0x2438 # f196f78
glabel var7f1b8fc8
.word 0x3d4ccccd
.text
/*  f194b40:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f194b44:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f194b48:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f194b4c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f194b50:	0080a025 */ 	or	$s4,$a0,$zero
/*  f194b54:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f194b58:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f194b5c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f194b60:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f194b64:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f194b68:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f194b6c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f194b70:	0fc0e6a5 */ 	jal	chrIsDead
/*  f194b74:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f194b78:	14400a66 */ 	bnez	$v0,.L0f197514
/*  f194b7c:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f194b80:	8e9202d4 */ 	lw	$s2,0x2d4($s4)
/*  f194b84:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f194b88:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f194b8c:	8e4e02cc */ 	lw	$t6,0x2cc($s2)
/*  f194b90:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f194b94:	07210017 */ 	bgez	$t9,.L0f194bf4
/*  f194b98:	ae5902cc */ 	sw	$t9,0x2cc($s2)
/*  f194b9c:	0c004b70 */ 	jal	random
/*  f194ba0:	00000000 */ 	nop
/*  f194ba4:	24013840 */ 	addiu	$at,$zero,0x3840
/*  f194ba8:	0041001b */ 	divu	$zero,$v0,$at
/*  f194bac:	00004810 */ 	mfhi	$t1
/*  f194bb0:	252a0708 */ 	addiu	$t2,$t1,0x708
/*  f194bb4:	0c004b70 */ 	jal	random
/*  f194bb8:	ae4a02cc */ 	sw	$t2,0x2cc($s2)
/*  f194bbc:	0c004b70 */ 	jal	random
/*  f194bc0:	ae4202d0 */ 	sw	$v0,0x2d0($s2)
/*  f194bc4:	44822000 */ 	mtc1	$v0,$f4
/*  f194bc8:	3c014f80 */ 	lui	$at,0x4f80
/*  f194bcc:	04410004 */ 	bgez	$v0,.L0f194be0
/*  f194bd0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f194bd4:	44814000 */ 	mtc1	$at,$f8
/*  f194bd8:	00000000 */ 	nop
/*  f194bdc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f194be0:
/*  f194be0:	3c012f80 */ 	lui	$at,0x2f80
/*  f194be4:	44815000 */ 	mtc1	$at,$f10
/*  f194be8:	00000000 */ 	nop
/*  f194bec:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f194bf0:	e65202d4 */ 	swc1	$f18,0x2d4($s2)
.L0f194bf4:
/*  f194bf4:	00008025 */ 	or	$s0,$zero,$zero
/*  f194bf8:	02403825 */ 	or	$a3,$s2,$zero
.L0f194bfc:
/*  f194bfc:	84e2002c */ 	lh	$v0,0x2c($a3)
/*  f194c00:	5840000f */ 	blezl	$v0,.L0f194c40
/*  f194c04:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f194c08:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f194c0c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194c10:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f194c14:	a4ec002c */ 	sh	$t4,0x2c($a3)
/*  f194c18:	84ed002c */ 	lh	$t5,0x2c($a3)
/*  f194c1c:	5da00037 */ 	bgtzl	$t5,.L0f194cfc
/*  f194c20:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194c24:	02002825 */ 	or	$a1,$s0,$zero
/*  f194c28:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f194c2c:	0fc66690 */ 	jal	aibotReloadWeapon
/*  f194c30:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c34:	10000030 */ 	b	.L0f194cf8
/*  f194c38:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c3c:	8e45004c */ 	lw	$a1,0x4c($s2)
.L0f194c40:
/*  f194c40:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194c44:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c48:	00057080 */ 	sll	$t6,$a1,0x2
/*  f194c4c:	0fc668a7 */ 	jal	func0f19a29c
/*  f194c50:	000e2fc2 */ 	srl	$a1,$t6,0x1f
/*  f194c54:	14400028 */ 	bnez	$v0,.L0f194cf8
/*  f194c58:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c5c:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f194c60:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f194c64:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f194c68:	8f230024 */ 	lw	$v1,0x24($t9)
/*  f194c6c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194c70:	00054880 */ 	sll	$t1,$a1,0x2
/*  f194c74:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f194c78:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194c7c:	0fc6667e */ 	jal	weaponGetClipCapacityByFunction
/*  f194c80:	afa302e8 */ 	sw	$v1,0x2e8($sp)
/*  f194c84:	8fa302e8 */ 	lw	$v1,0x2e8($sp)
/*  f194c88:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f194c8c:	1c600008 */ 	bgtz	$v1,.L0f194cb0
/*  f194c90:	00000000 */ 	nop
/*  f194c94:	18400006 */ 	blez	$v0,.L0f194cb0
/*  f194c98:	02802025 */ 	or	$a0,$s4,$zero
/*  f194c9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f194ca0:	0fc64da7 */ 	jal	func0f19369c
/*  f194ca4:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194ca8:	10000013 */ 	b	.L0f194cf8
/*  f194cac:	8fa70054 */ 	lw	$a3,0x54($sp)
.L0f194cb0:
/*  f194cb0:	04410003 */ 	bgez	$v0,.L0f194cc0
/*  f194cb4:	00025843 */ 	sra	$t3,$v0,0x1
/*  f194cb8:	24410001 */ 	addiu	$at,$v0,0x1
/*  f194cbc:	00015843 */ 	sra	$t3,$at,0x1
.L0f194cc0:
/*  f194cc0:	006b082a */ 	slt	$at,$v1,$t3
/*  f194cc4:	5020000d */ 	beqzl	$at,.L0f194cfc
/*  f194cc8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194ccc:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f194cd0:	8e4c0124 */ 	lw	$t4,0x124($s2)
/*  f194cd4:	02802025 */ 	or	$a0,$s4,$zero
/*  f194cd8:	25aeff88 */ 	addiu	$t6,$t5,-120
/*  f194cdc:	018e082a */ 	slt	$at,$t4,$t6
/*  f194ce0:	50200006 */ 	beqzl	$at,.L0f194cfc
/*  f194ce4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f194ce8:	02002825 */ 	or	$a1,$s0,$zero
/*  f194cec:	0fc64da7 */ 	jal	func0f19369c
/*  f194cf0:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f194cf4:	8fa70054 */ 	lw	$a3,0x54($sp)
.L0f194cf8:
/*  f194cf8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f194cfc:
/*  f194cfc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f194d00:	1601ffbe */ 	bne	$s0,$at,.L0f194bfc
/*  f194d04:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f194d08:	8e4200cc */ 	lw	$v0,0xcc($s2)
/*  f194d0c:	58400045 */ 	blezl	$v0,.L0f194e24
/*  f194d10:	8e4d0020 */ 	lw	$t5,0x20($s2)
/*  f194d14:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f194d18:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d1c:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f194d20:	1f20003f */ 	bgtz	$t9,.L0f194e20
/*  f194d24:	ae5900cc */ 	sw	$t9,0xcc($s2)
/*  f194d28:	0fc65f3c */ 	jal	aibotGetInvItem
/*  f194d2c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f194d30:	00408025 */ 	or	$s0,$v0,$zero
/*  f194d34:	0fc4a2bd */ 	jal	weaponGetModel
/*  f194d38:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f194d3c:	12000019 */ 	beqz	$s0,.L0f194da4
/*  f194d40:	00408825 */ 	or	$s1,$v0,$zero
/*  f194d44:	04400017 */ 	bltz	$v0,.L0f194da4
/*  f194d48:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d4c:	00402825 */ 	or	$a1,$v0,$zero
/*  f194d50:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f194d54:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f194d58:	00003825 */ 	or	$a3,$zero,$zero
/*  f194d5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d60:	00002825 */ 	or	$a1,$zero,$zero
/*  f194d64:	0fc66690 */ 	jal	aibotReloadWeapon
/*  f194d68:	00003025 */ 	or	$a2,$zero,$zero
/*  f194d6c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f194d70:	24010003 */ 	addiu	$at,$zero,0x3
/*  f194d74:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d78:	15210008 */ 	bne	$t1,$at,.L0f194d9c
/*  f194d7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f194d80:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f194d84:	0fc22eb4 */ 	jal	chrGiveWeapon
/*  f194d88:	3c071000 */ 	lui	$a3,0x1000
/*  f194d8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194d90:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f194d94:	0fc66690 */ 	jal	aibotReloadWeapon
/*  f194d98:	00003025 */ 	or	$a2,$zero,$zero
.L0f194d9c:
/*  f194d9c:	1000000e */ 	b	.L0f194dd8
/*  f194da0:	ae400034 */ 	sw	$zero,0x34($s2)
.L0f194da4:
/*  f194da4:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f194da8:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f194dac:	ad570020 */ 	sw	$s7,0x20($t2)
/*  f194db0:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f194db4:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f194db8:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f194dbc:	a06d004c */ 	sb	$t5,0x4c($v1)
/*  f194dc0:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f194dc4:	906c004c */ 	lbu	$t4,0x4c($v1)
/*  f194dc8:	318effbf */ 	andi	$t6,$t4,0xffbf
/*  f194dcc:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f194dd0:	a06f004c */ 	sb	$t7,0x4c($v1)
/*  f194dd4:	ae400034 */ 	sw	$zero,0x34($s2)
.L0f194dd8:
/*  f194dd8:	02401025 */ 	or	$v0,$s2,$zero
/*  f194ddc:	00001825 */ 	or	$v1,$zero,$zero
/*  f194de0:	02802025 */ 	or	$a0,$s4,$zero
/*  f194de4:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f194de8:
/*  f194de8:	a440003c */ 	sh	$zero,0x3c($v0)
/*  f194dec:	8c850170 */ 	lw	$a1,0x170($a0)
/*  f194df0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f194df4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f194df8:	10a00007 */ 	beqz	$a1,.L0f194e18
/*  f194dfc:	00000000 */ 	nop
/*  f194e00:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f194e04:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f194e08:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f194e0c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f194e10:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f194e14:	a16a005f */ 	sb	$t2,0x5f($t3)
.L0f194e18:
/*  f194e18:	1466fff3 */ 	bne	$v1,$a2,.L0f194de8
/*  f194e1c:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f194e20:
/*  f194e20:	8e4d0020 */ 	lw	$t5,0x20($s2)
.L0f194e24:
/*  f194e24:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f194e28:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f194e2c:	55a10005 */ 	bnel	$t5,$at,.L0f194e44
/*  f194e30:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f194e34:	8e8e02d4 */ 	lw	$t6,0x2d4($s4)
/*  f194e38:	240c03e7 */ 	addiu	$t4,$zero,0x3e7
/*  f194e3c:	adcc0024 */ 	sw	$t4,0x24($t6)
/*  f194e40:	8e4f001c */ 	lw	$t7,0x1c($s2)
.L0f194e44:
/*  f194e44:	8df80050 */ 	lw	$t8,0x50($t7)
/*  f194e48:	1b00000d */ 	blez	$t8,.L0f194e80
/*  f194e4c:	02802025 */ 	or	$a0,$s4,$zero
/*  f194e50:	0fc6458e */ 	jal	func0f191638
/*  f194e54:	02e02825 */ 	or	$a1,$s7,$zero
/*  f194e58:	54400006 */ 	bnezl	$v0,.L0f194e74
/*  f194e5c:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f194e60:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f194e64:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f194e68:	57210006 */ 	bnel	$t9,$at,.L0f194e84
/*  f194e6c:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f194e70:	924a004c */ 	lbu	$t2,0x4c($s2)
.L0f194e74:
/*  f194e74:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f194e78:	1000001e */ 	b	.L0f194ef4
/*  f194e7c:	a24b004c */ 	sb	$t3,0x4c($s2)
.L0f194e80:
/*  f194e80:	8e420210 */ 	lw	$v0,0x210($s2)
.L0f194e84:
/*  f194e84:	240404b0 */ 	addiu	$a0,$zero,0x4b0
/*  f194e88:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f194e8c:	00026142 */ 	srl	$t4,$v0,0x5
/*  f194e90:	0184001b */ 	divu	$zero,$t4,$a0
/*  f194e94:	8da30050 */ 	lw	$v1,0x50($t5)
/*  f194e98:	00007010 */ 	mfhi	$t6
/*  f194e9c:	25cf04b0 */ 	addiu	$t7,$t6,0x4b0
/*  f194ea0:	14800002 */ 	bnez	$a0,.L0f194eac
/*  f194ea4:	00000000 */ 	nop
/*  f194ea8:	0007000d */ 	break	0x7
.L0f194eac:
/*  f194eac:	01e3082b */ 	sltu	$at,$t7,$v1
/*  f194eb0:	10200005 */ 	beqz	$at,.L0f194ec8
/*  f194eb4:	00025442 */ 	srl	$t2,$v0,0x11
/*  f194eb8:	9259004c */ 	lbu	$t9,0x4c($s2)
/*  f194ebc:	37290002 */ 	ori	$t1,$t9,0x2
/*  f194ec0:	1000000c */ 	b	.L0f194ef4
/*  f194ec4:	a249004c */ 	sb	$t1,0x4c($s2)
.L0f194ec8:
/*  f194ec8:	0144001b */ 	divu	$zero,$t2,$a0
/*  f194ecc:	00005810 */ 	mfhi	$t3
/*  f194ed0:	0163082b */ 	sltu	$at,$t3,$v1
/*  f194ed4:	14800002 */ 	bnez	$a0,.L0f194ee0
/*  f194ed8:	00000000 */ 	nop
/*  f194edc:	0007000d */ 	break	0x7
.L0f194ee0:
/*  f194ee0:	54200005 */ 	bnezl	$at,.L0f194ef8
/*  f194ee4:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f194ee8:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f194eec:	31acfffd */ 	andi	$t4,$t5,0xfffd
/*  f194ef0:	a24c004c */ 	sb	$t4,0x4c($s2)
.L0f194ef4:
/*  f194ef4:	8e4e004c */ 	lw	$t6,0x4c($s2)
.L0f194ef8:
/*  f194ef8:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f194efc:	07020039 */ 	bltzl	$t8,.L0f194fe4
/*  f194f00:	924b009c */ 	lbu	$t3,0x9c($s2)
/*  f194f04:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f194f08:	2401000d */ 	addiu	$at,$zero,0xd
/*  f194f0c:	02402025 */ 	or	$a0,$s2,$zero
/*  f194f10:	17210033 */ 	bne	$t9,$at,.L0f194fe0
/*  f194f14:	2405000d */ 	addiu	$a1,$zero,0xd
/*  f194f18:	00003025 */ 	or	$a2,$zero,$zero
/*  f194f1c:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f194f20:	02e03825 */ 	or	$a3,$s7,$zero
/*  f194f24:	00408025 */ 	or	$s0,$v0,$zero
/*  f194f28:	02802025 */ 	or	$a0,$s4,$zero
/*  f194f2c:	0fc6458e */ 	jal	func0f191638
/*  f194f30:	02e02825 */ 	or	$a1,$s7,$zero
/*  f194f34:	5040001a */ 	beqzl	$v0,.L0f194fa0
/*  f194f38:	8e4b0210 */ 	lw	$t3,0x210($s2)
/*  f194f3c:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f194f40:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f194f44:	00024982 */ 	srl	$t1,$v0,0x6
/*  f194f48:	0121001b */ 	divu	$zero,$t1,$at
/*  f194f4c:	00005010 */ 	mfhi	$t2
/*  f194f50:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f194f54:	0170082b */ 	sltu	$at,$t3,$s0
/*  f194f58:	10200005 */ 	beqz	$at,.L0f194f70
/*  f194f5c:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f194f60:	924c009c */ 	lbu	$t4,0x9c($s2)
/*  f194f64:	358e0020 */ 	ori	$t6,$t4,0x20
/*  f194f68:	10000020 */ 	b	.L0f194fec
/*  f194f6c:	a24e009c */ 	sb	$t6,0x9c($s2)
.L0f194f70:
/*  f194f70:	24010046 */ 	addiu	$at,$zero,0x46
/*  f194f74:	01e1001b */ 	divu	$zero,$t7,$at
/*  f194f78:	0000c010 */ 	mfhi	$t8
/*  f194f7c:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f194f80:	0330082b */ 	sltu	$at,$t9,$s0
/*  f194f84:	5420001a */ 	bnezl	$at,.L0f194ff0
/*  f194f88:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f194f8c:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f194f90:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f194f94:	10000015 */ 	b	.L0f194fec
/*  f194f98:	a24a009c */ 	sb	$t2,0x9c($s2)
/*  f194f9c:	8e4b0210 */ 	lw	$t3,0x210($s2)
.L0f194fa0:
/*  f194fa0:	240101f4 */ 	addiu	$at,$zero,0x1f4
/*  f194fa4:	000b6b02 */ 	srl	$t5,$t3,0xc
/*  f194fa8:	01a1001b */ 	divu	$zero,$t5,$at
/*  f194fac:	00006010 */ 	mfhi	$t4
/*  f194fb0:	258e012c */ 	addiu	$t6,$t4,0x12c
/*  f194fb4:	01d0082b */ 	sltu	$at,$t6,$s0
/*  f194fb8:	50200006 */ 	beqzl	$at,.L0f194fd4
/*  f194fbc:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f194fc0:	9258009c */ 	lbu	$t8,0x9c($s2)
/*  f194fc4:	37190020 */ 	ori	$t9,$t8,0x20
/*  f194fc8:	10000008 */ 	b	.L0f194fec
/*  f194fcc:	a259009c */ 	sb	$t9,0x9c($s2)
/*  f194fd0:	9249009c */ 	lbu	$t1,0x9c($s2)
.L0f194fd4:
/*  f194fd4:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f194fd8:	10000004 */ 	b	.L0f194fec
/*  f194fdc:	a24a009c */ 	sb	$t2,0x9c($s2)
.L0f194fe0:
/*  f194fe0:	924b009c */ 	lbu	$t3,0x9c($s2)
.L0f194fe4:
/*  f194fe4:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f194fe8:	a24d009c */ 	sb	$t5,0x9c($s2)
.L0f194fec:
/*  f194fec:	8e4c0004 */ 	lw	$t4,0x4($s2)
.L0f194ff0:
/*  f194ff0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f194ff4:	918e0047 */ 	lbu	$t6,0x47($t4)
/*  f194ff8:	55c1000e */ 	bnel	$t6,$at,.L0f195034
/*  f194ffc:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f195000:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f195004:	241effff */ 	addiu	$s8,$zero,-1
/*  f195008:	53cf000a */ 	beql	$s8,$t7,.L0f195034
/*  f19500c:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f195010:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f195014:	53000007 */ 	beqzl	$t8,.L0f195034
/*  f195018:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f19501c:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f195020:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f195024:	53210003 */ 	beql	$t9,$at,.L0f195034
/*  f195028:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f19502c:	ae5700d8 */ 	sw	$s7,0xd8($s2)
/*  f195030:	824a004f */ 	lb	$t2,0x4f($s2)
.L0f195034:
/*  f195034:	241effff */ 	addiu	$s8,$zero,-1
/*  f195038:	05430143 */ 	bgezl	$t2,.L0f195548
/*  f19503c:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f195040:	8e420118 */ 	lw	$v0,0x118($s2)
/*  f195044:	18400005 */ 	blez	$v0,.L0f19505c
/*  f195048:	00000000 */ 	nop
/*  f19504c:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f195050:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f195054:	ae4d0118 */ 	sw	$t5,0x118($s2)
/*  f195058:	01a01025 */ 	or	$v0,$t5,$zero
.L0f19505c:
/*  f19505c:	5c40013a */ 	bgtzl	$v0,.L0f195548
/*  f195060:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f195064:	0fc651b5 */ 	jal	mpGetNumPlayerTeammates
/*  f195068:	02802025 */ 	or	$a0,$s4,$zero
/*  f19506c:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f195070:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f195074:	00409825 */ 	or	$s3,$v0,$zero
/*  f195078:	02802025 */ 	or	$a0,$s4,$zero
/*  f19507c:	16e3001e */ 	bne	$s7,$v1,.L0f1950f8
/*  f195080:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195084:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f195088:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f19508c:	00003025 */ 	or	$a2,$zero,$zero
/*  f195090:	18400010 */ 	blez	$v0,.L0f1950d4
/*  f195094:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f195098:	05810003 */ 	bgez	$t4,.L0f1950a8
/*  f19509c:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f1950a0:	25810001 */ 	addiu	$at,$t4,0x1
/*  f1950a4:	00017043 */ 	sra	$t6,$at,0x1
.L0f1950a8:
/*  f1950a8:	004e082a */ 	slt	$at,$v0,$t6
/*  f1950ac:	5420000a */ 	bnezl	$at,.L0f1950d8
/*  f1950b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1950b4:	0c004b70 */ 	jal	random
/*  f1950b8:	00000000 */ 	nop
/*  f1950bc:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1950c0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1950c4:	00007810 */ 	mfhi	$t7
/*  f1950c8:	2de10042 */ 	sltiu	$at,$t7,0x42
/*  f1950cc:	10200006 */ 	beqz	$at,.L0f1950e8
/*  f1950d0:	02802025 */ 	or	$a0,$s4,$zero
.L0f1950d4:
/*  f1950d4:	02802025 */ 	or	$a0,$s4,$zero
.L0f1950d8:
/*  f1950d8:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1950dc:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f1950e0:	10000111 */ 	b	.L0f195528
/*  f1950e4:	00000000 */ 	nop
.L0f1950e8:
/*  f1950e8:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1950ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1950f0:	1000010d */ 	b	.L0f195528
/*  f1950f4:	00000000 */ 	nop
.L0f1950f8:
/*  f1950f8:	14610022 */ 	bne	$v1,$at,.L0f195184
/*  f1950fc:	02802025 */ 	or	$a0,$s4,$zero
/*  f195100:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f195104:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f195108:	00003025 */ 	or	$a2,$zero,$zero
/*  f19510c:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f195110:	00184940 */ 	sll	$t1,$t8,0x5
/*  f195114:	05220013 */ 	bltzl	$t1,.L0f195164
/*  f195118:	02802025 */ 	or	$a0,$s4,$zero
/*  f19511c:	18400010 */ 	blez	$v0,.L0f195160
/*  f195120:	266a0001 */ 	addiu	$t2,$s3,0x1
/*  f195124:	05410003 */ 	bgez	$t2,.L0f195134
/*  f195128:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f19512c:	25410001 */ 	addiu	$at,$t2,0x1
/*  f195130:	00015843 */ 	sra	$t3,$at,0x1
.L0f195134:
/*  f195134:	004b082a */ 	slt	$at,$v0,$t3
/*  f195138:	5420000a */ 	bnezl	$at,.L0f195164
/*  f19513c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195140:	0c004b70 */ 	jal	random
/*  f195144:	00000000 */ 	nop
/*  f195148:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19514c:	0041001b */ 	divu	$zero,$v0,$at
/*  f195150:	00006810 */ 	mfhi	$t5
/*  f195154:	2da10032 */ 	sltiu	$at,$t5,0x32
/*  f195158:	10200006 */ 	beqz	$at,.L0f195174
/*  f19515c:	02802025 */ 	or	$a0,$s4,$zero
.L0f195160:
/*  f195160:	02802025 */ 	or	$a0,$s4,$zero
.L0f195164:
/*  f195164:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195168:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f19516c:	100000ee */ 	b	.L0f195528
/*  f195170:	00000000 */ 	nop
.L0f195174:
/*  f195174:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195178:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19517c:	100000ea */ 	b	.L0f195528
/*  f195180:	00000000 */ 	nop
.L0f195184:
/*  f195184:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195188:	1461001e */ 	bne	$v1,$at,.L0f195204
/*  f19518c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195190:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f195194:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f195198:	00003025 */ 	or	$a2,$zero,$zero
/*  f19519c:	18400010 */ 	blez	$v0,.L0f1951e0
/*  f1951a0:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f1951a4:	05810003 */ 	bgez	$t4,.L0f1951b4
/*  f1951a8:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f1951ac:	25810001 */ 	addiu	$at,$t4,0x1
/*  f1951b0:	00017043 */ 	sra	$t6,$at,0x1
.L0f1951b4:
/*  f1951b4:	004e082a */ 	slt	$at,$v0,$t6
/*  f1951b8:	5420000a */ 	bnezl	$at,.L0f1951e4
/*  f1951bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1951c0:	0c004b70 */ 	jal	random
/*  f1951c4:	00000000 */ 	nop
/*  f1951c8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1951cc:	0041001b */ 	divu	$zero,$v0,$at
/*  f1951d0:	00007810 */ 	mfhi	$t7
/*  f1951d4:	2de10032 */ 	sltiu	$at,$t7,0x32
/*  f1951d8:	10200006 */ 	beqz	$at,.L0f1951f4
/*  f1951dc:	02802025 */ 	or	$a0,$s4,$zero
.L0f1951e0:
/*  f1951e0:	02802025 */ 	or	$a0,$s4,$zero
.L0f1951e4:
/*  f1951e4:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1951e8:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f1951ec:	100000ce */ 	b	.L0f195528
/*  f1951f0:	00000000 */ 	nop
.L0f1951f4:
/*  f1951f4:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1951f8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1951fc:	100000ca */ 	b	.L0f195528
/*  f195200:	00000000 */ 	nop
.L0f195204:
/*  f195204:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195208:	54610034 */ 	bnel	$v1,$at,.L0f1952dc
/*  f19520c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195210:	0fc65241 */ 	jal	mpGetNumTeammatesDefendingHill
/*  f195214:	02802025 */ 	or	$a0,$s4,$zero
/*  f195218:	8e98001c */ 	lw	$t8,0x1c($s4)
/*  f19521c:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0xe)
/*  f195220:	8529c11e */ 	lh	$t1,%lo(g_ScenarioData+0xe)($t1)
/*  f195224:	87190028 */ 	lh	$t9,0x28($t8)
/*  f195228:	00408025 */ 	or	$s0,$v0,$zero
/*  f19522c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195230:	17290002 */ 	bne	$t9,$t1,.L0f19523c
/*  f195234:	00000000 */ 	nop
/*  f195238:	2450ffff */ 	addiu	$s0,$v0,-1
.L0f19523c:
/*  f19523c:	1a000008 */ 	blez	$s0,.L0f195260
/*  f195240:	00000000 */ 	nop
/*  f195244:	06610003 */ 	bgez	$s3,.L0f195254
/*  f195248:	00135043 */ 	sra	$t2,$s3,0x1
/*  f19524c:	26610001 */ 	addiu	$at,$s3,0x1
/*  f195250:	00015043 */ 	sra	$t2,$at,0x1
.L0f195254:
/*  f195254:	020a082a */ 	slt	$at,$s0,$t2
/*  f195258:	10200005 */ 	beqz	$at,.L0f195270
/*  f19525c:	00000000 */ 	nop
.L0f195260:
/*  f195260:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195264:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f195268:	100000af */ 	b	.L0f195528
/*  f19526c:	00000000 */ 	nop
.L0f195270:
/*  f195270:	0fc65264 */ 	jal	mpGetNumOpponentsInHill
/*  f195274:	02802025 */ 	or	$a0,$s4,$zero
/*  f195278:	0050082a */ 	slt	$at,$v0,$s0
/*  f19527c:	10200012 */ 	beqz	$at,.L0f1952c8
/*  f195280:	02802025 */ 	or	$a0,$s4,$zero
/*  f195284:	0c004b70 */ 	jal	random
/*  f195288:	00000000 */ 	nop
/*  f19528c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195290:	0041001b */ 	divu	$zero,$v0,$at
/*  f195294:	00005810 */ 	mfhi	$t3
/*  f195298:	2d610032 */ 	sltiu	$at,$t3,0x32
/*  f19529c:	10200006 */ 	beqz	$at,.L0f1952b8
/*  f1952a0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952a8:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1952ac:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1952b0:	1000009d */ 	b	.L0f195528
/*  f1952b4:	00000000 */ 	nop
.L0f1952b8:
/*  f1952b8:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1952bc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1952c0:	10000099 */ 	b	.L0f195528
/*  f1952c4:	00000000 */ 	nop
.L0f1952c8:
/*  f1952c8:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1952cc:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f1952d0:	10000095 */ 	b	.L0f195528
/*  f1952d4:	00000000 */ 	nop
/*  f1952d8:	24010005 */ 	addiu	$at,$zero,0x5
.L0f1952dc:
/*  f1952dc:	14610092 */ 	bne	$v1,$at,.L0f195528
/*  f1952e0:	00000000 */ 	nop
/*  f1952e4:	14570035 */ 	bne	$v0,$s7,.L0f1953bc
/*  f1952e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1952f0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1952f4:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f1952f8:	02e03025 */ 	or	$a2,$s7,$zero
/*  f1952fc:	00408025 */ 	or	$s0,$v0,$zero
/*  f195300:	0fc65227 */ 	jal	func0f19489c
/*  f195304:	02802025 */ 	or	$a0,$s4,$zero
/*  f195308:	10400005 */ 	beqz	$v0,.L0f195320
/*  f19530c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195310:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195314:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195318:	10000083 */ 	b	.L0f195528
/*  f19531c:	00000000 */ 	nop
.L0f195320:
/*  f195320:	0fc6520d */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f195324:	02802025 */ 	or	$a0,$s4,$zero
/*  f195328:	10400012 */ 	beqz	$v0,.L0f195374
/*  f19532c:	00000000 */ 	nop
/*  f195330:	0c004b70 */ 	jal	random
/*  f195334:	00000000 */ 	nop
/*  f195338:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19533c:	0041001b */ 	divu	$zero,$v0,$at
/*  f195340:	00006810 */ 	mfhi	$t5
/*  f195344:	2da1001e */ 	sltiu	$at,$t5,0x1e
/*  f195348:	10200006 */ 	beqz	$at,.L0f195364
/*  f19534c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195350:	02802025 */ 	or	$a0,$s4,$zero
/*  f195354:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195358:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f19535c:	10000072 */ 	b	.L0f195528
/*  f195360:	00000000 */ 	nop
.L0f195364:
/*  f195364:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195368:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f19536c:	1000006e */ 	b	.L0f195528
/*  f195370:	00000000 */ 	nop
.L0f195374:
/*  f195374:	0c004b70 */ 	jal	random
/*  f195378:	00000000 */ 	nop
/*  f19537c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195380:	0041001b */ 	divu	$zero,$v0,$at
/*  f195384:	00006010 */ 	mfhi	$t4
/*  f195388:	2d810046 */ 	sltiu	$at,$t4,0x46
/*  f19538c:	14200003 */ 	bnez	$at,.L0f19539c
/*  f195390:	02802025 */ 	or	$a0,$s4,$zero
/*  f195394:	1e000005 */ 	bgtz	$s0,.L0f1953ac
/*  f195398:	24050008 */ 	addiu	$a1,$zero,0x8
.L0f19539c:
/*  f19539c:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1953a0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953a4:	10000060 */ 	b	.L0f195528
/*  f1953a8:	00000000 */ 	nop
.L0f1953ac:
/*  f1953ac:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1953b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953b4:	1000005c */ 	b	.L0f195528
/*  f1953b8:	00000000 */ 	nop
.L0f1953bc:
/*  f1953bc:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953c0:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f1953c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1953c8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1953cc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953d0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1953d4:	0fc651c9 */ 	jal	mpCountAibotsWithCommand
/*  f1953d8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1953dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f1953e0:	0fc65227 */ 	jal	func0f19489c
/*  f1953e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953e8:	10400005 */ 	beqz	$v0,.L0f195400
/*  f1953ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1953f0:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1953f4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1953f8:	1000004b */ 	b	.L0f195528
/*  f1953fc:	00000000 */ 	nop
.L0f195400:
/*  f195400:	0fc6520d */ 	jal	scenarioCtcIsChrsTokenHeld
/*  f195404:	02802025 */ 	or	$a0,$s4,$zero
/*  f195408:	10400014 */ 	beqz	$v0,.L0f19545c
/*  f19540c:	00000000 */ 	nop
/*  f195410:	5a00000a */ 	blezl	$s0,.L0f19543c
/*  f195414:	02802025 */ 	or	$a0,$s4,$zero
/*  f195418:	0c004b70 */ 	jal	random
/*  f19541c:	00000000 */ 	nop
/*  f195420:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195424:	0041001b */ 	divu	$zero,$v0,$at
/*  f195428:	00007010 */ 	mfhi	$t6
/*  f19542c:	2dc10046 */ 	sltiu	$at,$t6,0x46
/*  f195430:	10200006 */ 	beqz	$at,.L0f19544c
/*  f195434:	02802025 */ 	or	$a0,$s4,$zero
/*  f195438:	02802025 */ 	or	$a0,$s4,$zero
.L0f19543c:
/*  f19543c:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195440:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f195444:	10000038 */ 	b	.L0f195528
/*  f195448:	00000000 */ 	nop
.L0f19544c:
/*  f19544c:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195450:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195454:	10000034 */ 	b	.L0f195528
/*  f195458:	00000000 */ 	nop
.L0f19545c:
/*  f19545c:	1a200005 */ 	blez	$s1,.L0f195474
/*  f195460:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195464:	0261001a */ 	div	$zero,$s3,$at
/*  f195468:	00007812 */ 	mflo	$t7
/*  f19546c:	022f082a */ 	slt	$at,$s1,$t7
/*  f195470:	10200005 */ 	beqz	$at,.L0f195488
.L0f195474:
/*  f195474:	02802025 */ 	or	$a0,$s4,$zero
/*  f195478:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f19547c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f195480:	10000029 */ 	b	.L0f195528
/*  f195484:	00000000 */ 	nop
.L0f195488:
/*  f195488:	1a000008 */ 	blez	$s0,.L0f1954ac
/*  f19548c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195490:	06610003 */ 	bgez	$s3,.L0f1954a0
/*  f195494:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f195498:	26610003 */ 	addiu	$at,$s3,0x3
/*  f19549c:	0001c083 */ 	sra	$t8,$at,0x2
.L0f1954a0:
/*  f1954a0:	0218082a */ 	slt	$at,$s0,$t8
/*  f1954a4:	10200005 */ 	beqz	$at,.L0f1954bc
/*  f1954a8:	00000000 */ 	nop
.L0f1954ac:
/*  f1954ac:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1954b0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1954b4:	1000001c */ 	b	.L0f195528
/*  f1954b8:	00000000 */ 	nop
.L0f1954bc:
/*  f1954bc:	0c004b70 */ 	jal	random
/*  f1954c0:	00000000 */ 	nop
/*  f1954c4:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1954c8:	0041001b */ 	divu	$zero,$v0,$at
/*  f1954cc:	0000c810 */ 	mfhi	$t9
/*  f1954d0:	2f21001e */ 	sltiu	$at,$t9,0x1e
/*  f1954d4:	10200005 */ 	beqz	$at,.L0f1954ec
/*  f1954d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1954dc:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f1954e0:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f1954e4:	10000010 */ 	b	.L0f195528
/*  f1954e8:	00000000 */ 	nop
.L0f1954ec:
/*  f1954ec:	0c004b70 */ 	jal	random
/*  f1954f0:	00000000 */ 	nop
/*  f1954f4:	24010064 */ 	addiu	$at,$zero,0x64
/*  f1954f8:	0041001b */ 	divu	$zero,$v0,$at
/*  f1954fc:	00004810 */ 	mfhi	$t1
/*  f195500:	2d21001e */ 	sltiu	$at,$t1,0x1e
/*  f195504:	10200006 */ 	beqz	$at,.L0f195520
/*  f195508:	02802025 */ 	or	$a0,$s4,$zero
/*  f19550c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195510:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195514:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f195518:	10000003 */ 	b	.L0f195528
/*  f19551c:	00000000 */ 	nop
.L0f195520:
/*  f195520:	0fc64984 */ 	jal	mpAibotApplyScenarioCommand
/*  f195524:	24050004 */ 	addiu	$a1,$zero,0x4
.L0f195528:
/*  f195528:	0c004b70 */ 	jal	random
/*  f19552c:	00000000 */ 	nop
/*  f195530:	24010960 */ 	addiu	$at,$zero,0x960
/*  f195534:	0041001b */ 	divu	$zero,$v0,$at
/*  f195538:	00005010 */ 	mfhi	$t2
/*  f19553c:	254b04b0 */ 	addiu	$t3,$t2,0x4b0
/*  f195540:	ae4b0118 */ 	sw	$t3,0x118($s2)
/*  f195544:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
.L0f195548:
/*  f195548:	24010029 */ 	addiu	$at,$zero,0x29
/*  f19554c:	51a10005 */ 	beql	$t5,$at,.L0f195564
/*  f195550:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f195554:	8e4c00d8 */ 	lw	$t4,0xd8($s2)
/*  f195558:	11800398 */ 	beqz	$t4,.L0f1963bc
/*  f19555c:	00000000 */ 	nop
/*  f195560:	8e4e0004 */ 	lw	$t6,0x4($s2)
.L0f195564:
/*  f195564:	ae4000d8 */ 	sw	$zero,0xd8($s2)
/*  f195568:	a65e0008 */ 	sh	$s8,0x8($s2)
/*  f19556c:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f195570:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195574:	15e1000e */ 	bne	$t7,$at,.L0f1955b0
/*  f195578:	00000000 */ 	nop
/*  f19557c:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f195580:	13d8000b */ 	beq	$s8,$t8,.L0f1955b0
/*  f195584:	00000000 */ 	nop
/*  f195588:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f19558c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195590:	13200007 */ 	beqz	$t9,.L0f1955b0
/*  f195594:	00000000 */ 	nop
/*  f195598:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19559c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f1955a0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1955a4:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1955a8:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1955ac:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f1955b0:
/*  f1955b0:	06a10006 */ 	bgez	$s5,.L0f1955cc
/*  f1955b4:	00000000 */ 	nop
/*  f1955b8:	0fc651a5 */ 	jal	func0f194694
/*  f1955bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1955c0:	10400002 */ 	beqz	$v0,.L0f1955cc
/*  f1955c4:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f1955c8:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1955cc:
/*  f1955cc:	06a10240 */ 	bgez	$s5,.L0f195ed0
/*  f1955d0:	00000000 */ 	nop
/*  f1955d4:	92420079 */ 	lbu	$v0,0x79($s2)
/*  f1955d8:	16e20019 */ 	bne	$s7,$v0,.L0f195640
/*  f1955dc:	00000000 */ 	nop
/*  f1955e0:	8e4900c0 */ 	lw	$t1,0xc0($s2)
/*  f1955e4:	8ecb0338 */ 	lw	$t3,0x338($s6)
/*  f1955e8:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1955ec:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1955f0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1955f4:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f1955f8:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f1955fc:	0fc0e6a5 */ 	jal	chrIsDead
/*  f195600:	02002025 */ 	or	$a0,$s0,$zero
/*  f195604:	14400232 */ 	bnez	$v0,.L0f195ed0
/*  f195608:	02802025 */ 	or	$a0,$s4,$zero
/*  f19560c:	0fc64a53 */ 	jal	func0f19294c
/*  f195610:	02002825 */ 	or	$a1,$s0,$zero
/*  f195614:	1440022e */ 	bnez	$v0,.L0f195ed0
/*  f195618:	02802025 */ 	or	$a0,$s4,$zero
/*  f19561c:	0fc64b70 */ 	jal	func0f192dc0
/*  f195620:	02002825 */ 	or	$a1,$s0,$zero
/*  f195624:	1040022a */ 	beqz	$v0,.L0f195ed0
/*  f195628:	02002025 */ 	or	$a0,$s0,$zero
/*  f19562c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195630:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195634:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195638:	10000225 */ 	b	.L0f195ed0
/*  f19563c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f195640:
/*  f195640:	1440000d */ 	bnez	$v0,.L0f195678
/*  f195644:	2401000d */ 	addiu	$at,$zero,0xd
/*  f195648:	8e4c00d4 */ 	lw	$t4,0xd4($s2)
/*  f19564c:	ae5701e0 */ 	sw	$s7,0x1e0($s2)
/*  f195650:	8ecf0338 */ 	lw	$t7,0x338($s6)
/*  f195654:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f195658:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f19565c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f195660:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f195664:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195668:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f19566c:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f195670:	10000217 */ 	b	.L0f195ed0
/*  f195674:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195678:
/*  f195678:	5441000e */ 	bnel	$v0,$at,.L0f1956b4
/*  f19567c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195680:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*  f195684:	ae4001e0 */ 	sw	$zero,0x1e0($s2)
/*  f195688:	8eca0338 */ 	lw	$t2,0x338($s6)
/*  f19568c:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f195690:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195694:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f195698:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f19569c:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f1956a0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1956a4:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f1956a8:	10000209 */ 	b	.L0f195ed0
/*  f1956ac:	a642000a */ 	sh	$v0,0xa($s2)
/*  f1956b0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f1956b4:
/*  f1956b4:	54410005 */ 	bnel	$v0,$at,.L0f1956cc
/*  f1956b8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1956bc:	24150033 */ 	addiu	$s5,$zero,0x33
/*  f1956c0:	10000203 */ 	b	.L0f195ed0
/*  f1956c4:	ae5701dc */ 	sw	$s7,0x1dc($s2)
/*  f1956c8:	24010003 */ 	addiu	$at,$zero,0x3
.L0f1956cc:
/*  f1956cc:	54410005 */ 	bnel	$v0,$at,.L0f1956e4
/*  f1956d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1956d4:	24150033 */ 	addiu	$s5,$zero,0x33
/*  f1956d8:	100001fd */ 	b	.L0f195ed0
/*  f1956dc:	ae4001dc */ 	sw	$zero,0x1dc($s2)
/*  f1956e0:	24010006 */ 	addiu	$at,$zero,0x6
.L0f1956e4:
/*  f1956e4:	14410089 */ 	bne	$v0,$at,.L0f19590c
/*  f1956e8:	3c0d800b */ 	lui	$t5,%hi(g_MpSetup+0x10)
/*  f1956ec:	91adcb98 */ 	lbu	$t5,%lo(g_MpSetup+0x10)($t5)
/*  f1956f0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f1956f4:	15a10083 */ 	bne	$t5,$at,.L0f195904
/*  f1956f8:	00000000 */ 	nop
/*  f1956fc:	8e4c009c */ 	lw	$t4,0x9c($s2)
/*  f195700:	000c7840 */ 	sll	$t7,$t4,0x1
/*  f195704:	05e0007f */ 	bltz	$t7,.L0f195904
/*  f195708:	00000000 */ 	nop
/*  f19570c:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f195710:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f195714:	3c07800b */ 	lui	$a3,%hi(g_ScenarioData)
/*  f195718:	00003025 */ 	or	$a2,$zero,$zero
/*  f19571c:	24e7c110 */ 	addiu	$a3,$a3,%lo(g_ScenarioData)
/*  f195720:	00002825 */ 	or	$a1,$zero,$zero
/*  f195724:	27b00298 */ 	addiu	$s0,$sp,0x298
/*  f195728:	24080003 */ 	addiu	$t0,$zero,0x3
.L0f19572c:
/*  f19572c:	10a20020 */ 	beq	$a1,$v0,.L0f1957b0
/*  f195730:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f195734:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f195738:	87290000 */ 	lh	$t1,0x0($t9)
/*  f19573c:	00055080 */ 	sll	$t2,$a1,0x2
/*  f195740:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f195744:	5120001b */ 	beqzl	$t1,.L0f1957b4
/*  f195748:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19574c:	8d640058 */ 	lw	$a0,0x58($t3)
/*  f195750:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195754:	00066880 */ 	sll	$t5,$a2,0x2
/*  f195758:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f19575c:	020d6021 */ 	addu	$t4,$s0,$t5
/*  f195760:	50610004 */ 	beql	$v1,$at,.L0f195774
/*  f195764:	ad840000 */ 	sw	$a0,0x0($t4)
/*  f195768:	16e30004 */ 	bne	$s7,$v1,.L0f19577c
/*  f19576c:	00000000 */ 	nop
/*  f195770:	ad840000 */ 	sw	$a0,0x0($t4)
.L0f195774:
/*  f195774:	1000000e */ 	b	.L0f1957b0
/*  f195778:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f19577c:
/*  f19577c:	11030003 */ 	beq	$t0,$v1,.L0f19578c
/*  f195780:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195784:	5461000b */ 	bnel	$v1,$at,.L0f1957b4
/*  f195788:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f19578c:
/*  f19578c:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f195790:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f195794:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f195798:	906f0125 */ 	lbu	$t7,0x125($v1)
/*  f19579c:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f1957a0:	55cf0004 */ 	bnel	$t6,$t7,.L0f1957b4
/*  f1957a4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1957a8:	af240000 */ 	sw	$a0,0x0($t9)
/*  f1957ac:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1957b0:
/*  f1957b0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f1957b4:
/*  f1957b4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1957b8:	14a1ffdc */ 	bne	$a1,$at,.L0f19572c
/*  f1957bc:	00000000 */ 	nop
/*  f1957c0:	18c00050 */ 	blez	$a2,.L0f195904
/*  f1957c4:	00000000 */ 	nop
/*  f1957c8:	0c004b70 */ 	jal	random
/*  f1957cc:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f1957d0:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f1957d4:	0046001b */ 	divu	$zero,$v0,$a2
/*  f1957d8:	00002010 */ 	mfhi	$a0
/*  f1957dc:	24890001 */ 	addiu	$t1,$a0,0x1
/*  f1957e0:	00808825 */ 	or	$s1,$a0,$zero
/*  f1957e4:	0126001a */ 	div	$zero,$t1,$a2
/*  f1957e8:	00001810 */ 	mfhi	$v1
/*  f1957ec:	14c00002 */ 	bnez	$a2,.L0f1957f8
/*  f1957f0:	00000000 */ 	nop
/*  f1957f4:	0007000d */ 	break	0x7
.L0f1957f8:
/*  f1957f8:	14c00002 */ 	bnez	$a2,.L0f195804
/*  f1957fc:	00000000 */ 	nop
/*  f195800:	0007000d */ 	break	0x7
.L0f195804:
/*  f195804:	2401ffff */ 	addiu	$at,$zero,-1
/*  f195808:	14c10004 */ 	bne	$a2,$at,.L0f19581c
/*  f19580c:	3c018000 */ 	lui	$at,0x8000
/*  f195810:	15210002 */ 	bne	$t1,$at,.L0f19581c
/*  f195814:	00000000 */ 	nop
/*  f195818:	0006000d */ 	break	0x6
.L0f19581c:
/*  f19581c:	00035080 */ 	sll	$t2,$v1,0x2
.L0f195820:
/*  f195820:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f195824:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f195828:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f19582c:	afa30288 */ 	sw	$v1,0x288($sp)
/*  f195830:	02802025 */ 	or	$a0,$s4,$zero
/*  f195834:	0fc12555 */ 	jal	chrGetSquaredDistanceToCoord
/*  f195838:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f19583c:	3c017f1c */ 	lui	$at,%hi(var7f1b8f54)
/*  f195840:	c4248f54 */ 	lwc1	$f4,%lo(var7f1b8f54)($at)
/*  f195844:	8fa30288 */ 	lw	$v1,0x288($sp)
/*  f195848:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f19584c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f195850:	246d0001 */ 	addiu	$t5,$v1,0x1
/*  f195854:	45000003 */ 	bc1f	.L0f195864
/*  f195858:	00000000 */ 	nop
/*  f19585c:	10000010 */ 	b	.L0f1958a0
/*  f195860:	00608825 */ 	or	$s1,$v1,$zero
.L0f195864:
/*  f195864:	5071000f */ 	beql	$v1,$s1,.L0f1958a4
/*  f195868:	00116080 */ 	sll	$t4,$s1,0x2
/*  f19586c:	01a6001a */ 	div	$zero,$t5,$a2
/*  f195870:	00001810 */ 	mfhi	$v1
/*  f195874:	14c00002 */ 	bnez	$a2,.L0f195880
/*  f195878:	00000000 */ 	nop
/*  f19587c:	0007000d */ 	break	0x7
.L0f195880:
/*  f195880:	2401ffff */ 	addiu	$at,$zero,-1
/*  f195884:	14c10004 */ 	bne	$a2,$at,.L0f195898
/*  f195888:	3c018000 */ 	lui	$at,0x8000
/*  f19588c:	15a10002 */ 	bne	$t5,$at,.L0f195898
/*  f195890:	00000000 */ 	nop
/*  f195894:	0006000d */ 	break	0x6
.L0f195898:
/*  f195898:	1000ffe1 */ 	b	.L0f195820
/*  f19589c:	00035080 */ 	sll	$t2,$v1,0x2
.L0f1958a0:
/*  f1958a0:	00116080 */ 	sll	$t4,$s1,0x2
.L0f1958a4:
/*  f1958a4:	020c9821 */ 	addu	$s3,$s0,$t4
/*  f1958a8:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f1958ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1958b0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1958b4:	50610004 */ 	beql	$v1,$at,.L0f1958c8
/*  f1958b8:	2415002a */ 	addiu	$s5,$zero,0x2a
/*  f1958bc:	16e30004 */ 	bne	$s7,$v1,.L0f1958d0
/*  f1958c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1958c4:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1958c8:
/*  f1958c8:	10000181 */ 	b	.L0f195ed0
/*  f1958cc:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f1958d0:
/*  f1958d0:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f1958d4:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f1958d8:	1040000a */ 	beqz	$v0,.L0f195904
/*  f1958dc:	00000000 */ 	nop
/*  f1958e0:	0c004b70 */ 	jal	random
/*  f1958e4:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f1958e8:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f1958ec:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f1958f0:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f1958f4:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f1958f8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1958fc:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f195900:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195904:
/*  f195904:	10000172 */ 	b	.L0f195ed0
/*  f195908:	00000000 */ 	nop
.L0f19590c:
/*  f19590c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f195910:	14410043 */ 	bne	$v0,$at,.L0f195a20
/*  f195914:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0x10)
/*  f195918:	9339cb98 */ 	lbu	$t9,%lo(g_MpSetup+0x10)($t9)
/*  f19591c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195920:	1721016b */ 	bne	$t9,$at,.L0f195ed0
/*  f195924:	00000000 */ 	nop
/*  f195928:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f19592c:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f195930:	00024880 */ 	sll	$t1,$v0,0x2
/*  f195934:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData+0x58)
/*  f195938:	00691821 */ 	addu	$v1,$v1,$t1
/*  f19593c:	8c63c168 */ 	lw	$v1,%lo(g_ScenarioData+0x58)($v1)
/*  f195940:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195944:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f195948:	10810003 */ 	beq	$a0,$at,.L0f195958
/*  f19594c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195950:	54810026 */ 	bnel	$a0,$at,.L0f1959ec
/*  f195954:	c4680008 */ 	lwc1	$f8,0x8($v1)
.L0f195958:
/*  f195958:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f19595c:	928a0125 */ 	lbu	$t2,0x125($s4)
/*  f195960:	02802025 */ 	or	$a0,$s4,$zero
/*  f195964:	920b0125 */ 	lbu	$t3,0x125($s0)
/*  f195968:	154b000e */ 	bne	$t2,$t3,.L0f1959a4
/*  f19596c:	00000000 */ 	nop
/*  f195970:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195974:	02002825 */ 	or	$a1,$s0,$zero
/*  f195978:	10400155 */ 	beqz	$v0,.L0f195ed0
/*  f19597c:	00000000 */ 	nop
/*  f195980:	0c004b70 */ 	jal	random
/*  f195984:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195988:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f19598c:	2dac0001 */ 	sltiu	$t4,$t5,0x1
/*  f195990:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f195994:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195998:	02002025 */ 	or	$a0,$s0,$zero
/*  f19599c:	1000014c */ 	b	.L0f195ed0
/*  f1959a0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f1959a4:
/*  f1959a4:	0fc0e6a5 */ 	jal	chrIsDead
/*  f1959a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1959ac:	14400148 */ 	bnez	$v0,.L0f195ed0
/*  f1959b0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1959b4:	0fc64a53 */ 	jal	func0f19294c
/*  f1959b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1959bc:	14400144 */ 	bnez	$v0,.L0f195ed0
/*  f1959c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1959c4:	0fc64b70 */ 	jal	func0f192dc0
/*  f1959c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1959cc:	10400140 */ 	beqz	$v0,.L0f195ed0
/*  f1959d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1959d4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1959d8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f1959dc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1959e0:	1000013b */ 	b	.L0f195ed0
/*  f1959e4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f1959e8:	c4680008 */ 	lwc1	$f8,0x8($v1)
.L0f1959ec:
/*  f1959ec:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f1959f0:	24640028 */ 	addiu	$a0,$v1,0x28
/*  f1959f4:	e64800ec */ 	swc1	$f8,0xec($s2)
/*  f1959f8:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f1959fc:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195a00:	e64600f0 */ 	swc1	$f6,0xf0($s2)
/*  f195a04:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f195a08:	0fc195e9 */ 	jal	roomsCopy
/*  f195a0c:	e64a00f4 */ 	swc1	$f10,0xf4($s2)
/*  f195a10:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f195a14:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f195a18:	1000012d */ 	b	.L0f195ed0
/*  f195a1c:	a24f004c */ 	sb	$t7,0x4c($s2)
.L0f195a20:
/*  f195a20:	24010009 */ 	addiu	$at,$zero,0x9
/*  f195a24:	14410048 */ 	bne	$v0,$at,.L0f195b48
/*  f195a28:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x10)
/*  f195a2c:	9318cb98 */ 	lbu	$t8,%lo(g_MpSetup+0x10)($t8)
/*  f195a30:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195a34:	17010126 */ 	bne	$t8,$at,.L0f195ed0
/*  f195a38:	00000000 */ 	nop
/*  f195a3c:	8e99001c */ 	lw	$t9,0x1c($s4)
/*  f195a40:	3c0a800b */ 	lui	$t2,%hi(g_ScenarioData+0xe)
/*  f195a44:	854ac11e */ 	lh	$t2,%lo(g_ScenarioData+0xe)($t2)
/*  f195a48:	87290028 */ 	lh	$t1,0x28($t9)
/*  f195a4c:	152a0016 */ 	bne	$t1,$t2,.L0f195aa8
/*  f195a50:	00000000 */ 	nop
/*  f195a54:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f195a58:	13cb0013 */ 	beq	$s8,$t3,.L0f195aa8
/*  f195a5c:	00000000 */ 	nop
/*  f195a60:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f195a64:	11a00010 */ 	beqz	$t5,.L0f195aa8
/*  f195a68:	00000000 */ 	nop
/*  f195a6c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f195a70:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a74:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a78:	0fc64b70 */ 	jal	func0f192dc0
/*  f195a7c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f195a80:	10400009 */ 	beqz	$v0,.L0f195aa8
/*  f195a84:	02802025 */ 	or	$a0,$s4,$zero
/*  f195a88:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f195a8c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195a90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195a94:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f195a98:	240c012c */ 	addiu	$t4,$zero,0x12c
/*  f195a9c:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195aa0:	1000010b */ 	b	.L0f195ed0
/*  f195aa4:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
.L0f195aa8:
/*  f195aa8:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0xe)
/*  f195aac:	27ae0260 */ 	addiu	$t6,$sp,0x260
/*  f195ab0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f195ab4:	8484c11e */ 	lh	$a0,%lo(g_ScenarioData+0xe)($a0)
/*  f195ab8:	27a5026c */ 	addiu	$a1,$sp,0x26c
/*  f195abc:	27a60268 */ 	addiu	$a2,$sp,0x268
/*  f195ac0:	0fc66adc */ 	jal	func0f19ab70
/*  f195ac4:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f195ac8:	10400101 */ 	beqz	$v0,.L0f195ed0
/*  f195acc:	c7b2026c */ 	lwc1	$f18,0x26c($sp)
/*  f195ad0:	e65200ec */ 	swc1	$f18,0xec($s2)
/*  f195ad4:	c7a40270 */ 	lwc1	$f4,0x270($sp)
/*  f195ad8:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0xe)
/*  f195adc:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f195ae0:	e64400f0 */ 	swc1	$f4,0xf0($s2)
/*  f195ae4:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f195ae8:	2484c11e */ 	addiu	$a0,$a0,%lo(g_ScenarioData+0xe)
/*  f195aec:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195af0:	0fc195e9 */ 	jal	roomsCopy
/*  f195af4:	e64800f4 */ 	swc1	$f8,0xf4($s2)
/*  f195af8:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f195afc:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0xe)
/*  f195b00:	8739c11e */ 	lh	$t9,%lo(g_ScenarioData+0xe)($t9)
/*  f195b04:	85f80028 */ 	lh	$t8,0x28($t7)
/*  f195b08:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f195b0c:	3c0a800b */ 	lui	$t2,%hi(g_ScenarioData+0xe)
/*  f195b10:	03194826 */ 	xor	$t1,$t8,$t9
/*  f195b14:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  f195b18:	0009582b */ 	sltu	$t3,$zero,$t1
/*  f195b1c:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f195b20:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f195b24:	018fc025 */ 	or	$t8,$t4,$t7
/*  f195b28:	a258004c */ 	sb	$t8,0x4c($s2)
/*  f195b2c:	8fb90264 */ 	lw	$t9,0x264($sp)
/*  f195b30:	a6590048 */ 	sh	$t9,0x48($s2)
/*  f195b34:	8fa90260 */ 	lw	$t1,0x260($sp)
/*  f195b38:	a649004a */ 	sh	$t1,0x4a($s2)
/*  f195b3c:	854ac11e */ 	lh	$t2,%lo(g_ScenarioData+0xe)($t2)
/*  f195b40:	100000e3 */ 	b	.L0f195ed0
/*  f195b44:	ae4a00bc */ 	sw	$t2,0xbc($s2)
.L0f195b48:
/*  f195b48:	2401000a */ 	addiu	$at,$zero,0xa
/*  f195b4c:	1441002c */ 	bne	$v0,$at,.L0f195c00
/*  f195b50:	3c0b800b */ 	lui	$t3,%hi(g_MpSetup+0x10)
/*  f195b54:	916bcb98 */ 	lbu	$t3,%lo(g_MpSetup+0x10)($t3)
/*  f195b58:	24010004 */ 	addiu	$at,$zero,0x4
/*  f195b5c:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0xe)
/*  f195b60:	156100db */ 	bne	$t3,$at,.L0f195ed0
/*  f195b64:	27a50254 */ 	addiu	$a1,$sp,0x254
/*  f195b68:	27ad0248 */ 	addiu	$t5,$sp,0x248
/*  f195b6c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f195b70:	8484c11e */ 	lh	$a0,%lo(g_ScenarioData+0xe)($a0)
/*  f195b74:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f195b78:	0fc66adc */ 	jal	func0f19ab70
/*  f195b7c:	27a7024c */ 	addiu	$a3,$sp,0x24c
/*  f195b80:	104000d3 */ 	beqz	$v0,.L0f195ed0
/*  f195b84:	c7a60254 */ 	lwc1	$f6,0x254($sp)
/*  f195b88:	e64600ec */ 	swc1	$f6,0xec($s2)
/*  f195b8c:	c7aa0258 */ 	lwc1	$f10,0x258($sp)
/*  f195b90:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0xe)
/*  f195b94:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f195b98:	e64a00f0 */ 	swc1	$f10,0xf0($s2)
/*  f195b9c:	c7b2025c */ 	lwc1	$f18,0x25c($sp)
/*  f195ba0:	2484c11e */ 	addiu	$a0,$a0,%lo(g_ScenarioData+0xe)
/*  f195ba4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f195ba8:	0fc195e9 */ 	jal	roomsCopy
/*  f195bac:	e65200f4 */ 	swc1	$f18,0xf4($s2)
/*  f195bb0:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f195bb4:	3c0f800b */ 	lui	$t7,%hi(g_ScenarioData+0xe)
/*  f195bb8:	85efc11e */ 	lh	$t7,%lo(g_ScenarioData+0xe)($t7)
/*  f195bbc:	85cc0028 */ 	lh	$t4,0x28($t6)
/*  f195bc0:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f195bc4:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0xe)
/*  f195bc8:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f195bcc:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f195bd0:	0018482b */ 	sltu	$t1,$zero,$t8
/*  f195bd4:	000959c0 */ 	sll	$t3,$t1,0x7
/*  f195bd8:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f195bdc:	016e6025 */ 	or	$t4,$t3,$t6
/*  f195be0:	a24c004c */ 	sb	$t4,0x4c($s2)
/*  f195be4:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f195be8:	a64f0048 */ 	sh	$t7,0x48($s2)
/*  f195bec:	8fb80248 */ 	lw	$t8,0x248($sp)
/*  f195bf0:	a658004a */ 	sh	$t8,0x4a($s2)
/*  f195bf4:	8739c11e */ 	lh	$t9,%lo(g_ScenarioData+0xe)($t9)
/*  f195bf8:	100000b5 */ 	b	.L0f195ed0
/*  f195bfc:	ae5900bc */ 	sw	$t9,0xbc($s2)
.L0f195c00:
/*  f195c00:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195c04:	1441003b */ 	bne	$v0,$at,.L0f195cf4
/*  f195c08:	3c09800b */ 	lui	$t1,%hi(g_MpSetup+0x10)
/*  f195c0c:	9129cb98 */ 	lbu	$t1,%lo(g_MpSetup+0x10)($t1)
/*  f195c10:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195c14:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x13c)
/*  f195c18:	152100ad */ 	bne	$t1,$at,.L0f195ed0
/*  f195c1c:	00000000 */ 	nop
/*  f195c20:	8c42c24c */ 	lw	$v0,%lo(g_ScenarioData+0x13c)($v0)
/*  f195c24:	104000aa */ 	beqz	$v0,.L0f195ed0
/*  f195c28:	00000000 */ 	nop
/*  f195c2c:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f195c30:	104a00a7 */ 	beq	$v0,$t2,.L0f195ed0
/*  f195c34:	00000000 */ 	nop
/*  f195c38:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f195c3c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195c40:	3c0d800b */ 	lui	$t5,%hi(g_MpSetup+0xc)
/*  f195c44:	10610003 */ 	beq	$v1,$at,.L0f195c54
/*  f195c48:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195c4c:	54610027 */ 	bnel	$v1,$at,.L0f195cec
/*  f195c50:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195c54:
/*  f195c54:	8dadcb94 */ 	lw	$t5,%lo(g_MpSetup+0xc)($t5)
/*  f195c58:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f195c5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195c60:	31ab0002 */ 	andi	$t3,$t5,0x2
/*  f195c64:	11600013 */ 	beqz	$t3,.L0f195cb4
/*  f195c68:	00000000 */ 	nop
/*  f195c6c:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f195c70:	920c0125 */ 	lbu	$t4,0x125($s0)
/*  f195c74:	02002825 */ 	or	$a1,$s0,$zero
/*  f195c78:	15cc000e */ 	bne	$t6,$t4,.L0f195cb4
/*  f195c7c:	00000000 */ 	nop
/*  f195c80:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195c84:	02802025 */ 	or	$a0,$s4,$zero
/*  f195c88:	10400091 */ 	beqz	$v0,.L0f195ed0
/*  f195c8c:	00000000 */ 	nop
/*  f195c90:	0c004b70 */ 	jal	random
/*  f195c94:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195c98:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f195c9c:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f195ca0:	ae5801e0 */ 	sw	$t8,0x1e0($s2)
/*  f195ca4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195ca8:	02002025 */ 	or	$a0,$s0,$zero
/*  f195cac:	10000088 */ 	b	.L0f195ed0
/*  f195cb0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195cb4:
/*  f195cb4:	0fc64a53 */ 	jal	func0f19294c
/*  f195cb8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195cbc:	14400084 */ 	bnez	$v0,.L0f195ed0
/*  f195cc0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195cc4:	0fc64b70 */ 	jal	func0f192dc0
/*  f195cc8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195ccc:	10400080 */ 	beqz	$v0,.L0f195ed0
/*  f195cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f195cd4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195cd8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195cdc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195ce0:	1000007b */ 	b	.L0f195ed0
/*  f195ce4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f195ce8:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195cec:
/*  f195cec:	10000078 */ 	b	.L0f195ed0
/*  f195cf0:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f195cf4:
/*  f195cf4:	2401000b */ 	addiu	$at,$zero,0xb
/*  f195cf8:	1441003a */ 	bne	$v0,$at,.L0f195de4
/*  f195cfc:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0x10)
/*  f195d00:	9339cb98 */ 	lbu	$t9,%lo(g_MpSetup+0x10)($t9)
/*  f195d04:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x4)
/*  f195d08:	16f90071 */ 	bne	$s7,$t9,.L0f195ed0
/*  f195d0c:	00000000 */ 	nop
/*  f195d10:	8c42c114 */ 	lw	$v0,%lo(g_ScenarioData+0x4)($v0)
/*  f195d14:	1040006e */ 	beqz	$v0,.L0f195ed0
/*  f195d18:	00000000 */ 	nop
/*  f195d1c:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f195d20:	1049006b */ 	beq	$v0,$t1,.L0f195ed0
/*  f195d24:	00000000 */ 	nop
/*  f195d28:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f195d2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195d30:	3c0a800b */ 	lui	$t2,%hi(g_MpSetup+0xc)
/*  f195d34:	10610003 */ 	beq	$v1,$at,.L0f195d44
/*  f195d38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f195d3c:	54610027 */ 	bnel	$v1,$at,.L0f195ddc
/*  f195d40:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195d44:
/*  f195d44:	8d4acb94 */ 	lw	$t2,%lo(g_MpSetup+0xc)($t2)
/*  f195d48:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f195d4c:	02802025 */ 	or	$a0,$s4,$zero
/*  f195d50:	314d0002 */ 	andi	$t5,$t2,0x2
/*  f195d54:	11a00013 */ 	beqz	$t5,.L0f195da4
/*  f195d58:	00000000 */ 	nop
/*  f195d5c:	928b0125 */ 	lbu	$t3,0x125($s4)
/*  f195d60:	920e0125 */ 	lbu	$t6,0x125($s0)
/*  f195d64:	02002825 */ 	or	$a1,$s0,$zero
/*  f195d68:	156e000e */ 	bne	$t3,$t6,.L0f195da4
/*  f195d6c:	00000000 */ 	nop
/*  f195d70:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195d74:	02802025 */ 	or	$a0,$s4,$zero
/*  f195d78:	10400055 */ 	beqz	$v0,.L0f195ed0
/*  f195d7c:	00000000 */ 	nop
/*  f195d80:	0c004b70 */ 	jal	random
/*  f195d84:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195d88:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f195d8c:	2d8f0001 */ 	sltiu	$t7,$t4,0x1
/*  f195d90:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f195d94:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195d98:	02002025 */ 	or	$a0,$s0,$zero
/*  f195d9c:	1000004c */ 	b	.L0f195ed0
/*  f195da0:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195da4:
/*  f195da4:	0fc64a53 */ 	jal	func0f19294c
/*  f195da8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195dac:	14400048 */ 	bnez	$v0,.L0f195ed0
/*  f195db0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195db4:	0fc64b70 */ 	jal	func0f192dc0
/*  f195db8:	02002825 */ 	or	$a1,$s0,$zero
/*  f195dbc:	10400044 */ 	beqz	$v0,.L0f195ed0
/*  f195dc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f195dc4:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195dc8:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195dcc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195dd0:	1000003f */ 	b	.L0f195ed0
/*  f195dd4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f195dd8:	2415002c */ 	addiu	$s5,$zero,0x2c
.L0f195ddc:
/*  f195ddc:	1000003c */ 	b	.L0f195ed0
/*  f195de0:	ae420010 */ 	sw	$v0,0x10($s2)
.L0f195de4:
/*  f195de4:	2401000c */ 	addiu	$at,$zero,0xc
/*  f195de8:	14410039 */ 	bne	$v0,$at,.L0f195ed0
/*  f195dec:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x10)
/*  f195df0:	9318cb98 */ 	lbu	$t8,%lo(g_MpSetup+0x10)($t8)
/*  f195df4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195df8:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x4)
/*  f195dfc:	17010034 */ 	bne	$t8,$at,.L0f195ed0
/*  f195e00:	00000000 */ 	nop
/*  f195e04:	8c42c114 */ 	lw	$v0,%lo(g_ScenarioData+0x4)($v0)
/*  f195e08:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0x8)
/*  f195e0c:	04400030 */ 	bltz	$v0,.L0f195ed0
/*  f195e10:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f195e14:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195e18:	8529c118 */ 	lh	$t1,%lo(g_ScenarioData+0x8)($t1)
/*  f195e1c:	3c0d800b */ 	lui	$t5,%hi(g_MpPlayerChrs)
/*  f195e20:	8e8b001c */ 	lw	$t3,0x1c($s4)
/*  f195e24:	00095080 */ 	sll	$t2,$t1,0x2
/*  f195e28:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f195e2c:	8dadc4d0 */ 	lw	$t5,%lo(g_MpPlayerChrs)($t5)
/*  f195e30:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0xc)
/*  f195e34:	8da3001c */ 	lw	$v1,0x1c($t5)
/*  f195e38:	106b0025 */ 	beq	$v1,$t3,.L0f195ed0
/*  f195e3c:	00000000 */ 	nop
/*  f195e40:	8dcecb94 */ 	lw	$t6,%lo(g_MpSetup+0xc)($t6)
/*  f195e44:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f195e48:	02802025 */ 	or	$a0,$s4,$zero
/*  f195e4c:	31cc0002 */ 	andi	$t4,$t6,0x2
/*  f195e50:	11800013 */ 	beqz	$t4,.L0f195ea0
/*  f195e54:	00000000 */ 	nop
/*  f195e58:	928f0125 */ 	lbu	$t7,0x125($s4)
/*  f195e5c:	92180125 */ 	lbu	$t8,0x125($s0)
/*  f195e60:	02002825 */ 	or	$a1,$s0,$zero
/*  f195e64:	15f8000e */ 	bne	$t7,$t8,.L0f195ea0
/*  f195e68:	00000000 */ 	nop
/*  f195e6c:	0fc64d37 */ 	jal	mpIsChrFollowedByChr
/*  f195e70:	02802025 */ 	or	$a0,$s4,$zero
/*  f195e74:	10400016 */ 	beqz	$v0,.L0f195ed0
/*  f195e78:	00000000 */ 	nop
/*  f195e7c:	0c004b70 */ 	jal	random
/*  f195e80:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195e84:	30590003 */ 	andi	$t9,$v0,0x3
/*  f195e88:	2f290001 */ 	sltiu	$t1,$t9,0x1
/*  f195e8c:	ae4901e0 */ 	sw	$t1,0x1e0($s2)
/*  f195e90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195e94:	02002025 */ 	or	$a0,$s0,$zero
/*  f195e98:	1000000d */ 	b	.L0f195ed0
/*  f195e9c:	a642000a */ 	sh	$v0,0xa($s2)
.L0f195ea0:
/*  f195ea0:	0fc64a53 */ 	jal	func0f19294c
/*  f195ea4:	02002825 */ 	or	$a1,$s0,$zero
/*  f195ea8:	14400009 */ 	bnez	$v0,.L0f195ed0
/*  f195eac:	02802025 */ 	or	$a0,$s4,$zero
/*  f195eb0:	0fc64b70 */ 	jal	func0f192dc0
/*  f195eb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f195eb8:	10400005 */ 	beqz	$v0,.L0f195ed0
/*  f195ebc:	02002025 */ 	or	$a0,$s0,$zero
/*  f195ec0:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f195ec4:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f195ec8:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f195ecc:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f195ed0:
/*  f195ed0:	06a10078 */ 	bgez	$s5,.L0f1960b4
/*  f195ed4:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f195ed8:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f195edc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f195ee0:	16e3001a */ 	bne	$s7,$v1,.L0f195f4c
/*  f195ee4:	00000000 */ 	nop
/*  f195ee8:	8e4a009c */ 	lw	$t2,0x9c($s2)
/*  f195eec:	000a6fc2 */ 	srl	$t5,$t2,0x1f
/*  f195ef0:	11a00070 */ 	beqz	$t5,.L0f1960b4
/*  f195ef4:	00000000 */ 	nop
/*  f195ef8:	0c004b70 */ 	jal	random
/*  f195efc:	03c08025 */ 	or	$s0,$s8,$zero
/*  f195f00:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195f04:	0041001b */ 	divu	$zero,$v0,$at
/*  f195f08:	00005810 */ 	mfhi	$t3
/*  f195f0c:	2d610042 */ 	sltiu	$at,$t3,0x42
/*  f195f10:	10200005 */ 	beqz	$at,.L0f195f28
/*  f195f14:	02802025 */ 	or	$a0,$s4,$zero
/*  f195f18:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f195f1c:	0fc64d4c */ 	jal	func0f193530
/*  f195f20:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f195f24:	00408025 */ 	or	$s0,$v0,$zero
.L0f195f28:
/*  f195f28:	06000062 */ 	bltz	$s0,.L0f1960b4
/*  f195f2c:	00000000 */ 	nop
/*  f195f30:	0c004b70 */ 	jal	random
/*  f195f34:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195f38:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f195f3c:	2dcc0001 */ 	sltiu	$t4,$t6,0x1
/*  f195f40:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f195f44:	1000005b */ 	b	.L0f1960b4
/*  f195f48:	a650000a */ 	sh	$s0,0xa($s2)
.L0f195f4c:
/*  f195f4c:	14610024 */ 	bne	$v1,$at,.L0f195fe0
/*  f195f50:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0x4)
/*  f195f54:	8c42c114 */ 	lw	$v0,%lo(g_ScenarioData+0x4)($v0)
/*  f195f58:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0x8)
/*  f195f5c:	04400055 */ 	bltz	$v0,.L0f1960b4
/*  f195f60:	00027840 */ 	sll	$t7,$v0,0x1
/*  f195f64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f195f68:	8718c118 */ 	lh	$t8,%lo(g_ScenarioData+0x8)($t8)
/*  f195f6c:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f195f70:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f195f74:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f195f78:	01394821 */ 	addu	$t1,$t1,$t9
/*  f195f7c:	8d29c4d0 */ 	lw	$t1,%lo(g_MpPlayerChrs)($t1)
/*  f195f80:	8d23001c */ 	lw	$v1,0x1c($t1)
/*  f195f84:	146a004b */ 	bne	$v1,$t2,.L0f1960b4
/*  f195f88:	00000000 */ 	nop
/*  f195f8c:	0c004b70 */ 	jal	random
/*  f195f90:	03c08025 */ 	or	$s0,$s8,$zero
/*  f195f94:	24010064 */ 	addiu	$at,$zero,0x64
/*  f195f98:	0041001b */ 	divu	$zero,$v0,$at
/*  f195f9c:	00006810 */ 	mfhi	$t5
/*  f195fa0:	2da10042 */ 	sltiu	$at,$t5,0x42
/*  f195fa4:	10200005 */ 	beqz	$at,.L0f195fbc
/*  f195fa8:	02802025 */ 	or	$a0,$s4,$zero
/*  f195fac:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f195fb0:	0fc64d4c */ 	jal	func0f193530
/*  f195fb4:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f195fb8:	00408025 */ 	or	$s0,$v0,$zero
.L0f195fbc:
/*  f195fbc:	0600003d */ 	bltz	$s0,.L0f1960b4
/*  f195fc0:	00000000 */ 	nop
/*  f195fc4:	0c004b70 */ 	jal	random
/*  f195fc8:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f195fcc:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f195fd0:	2d6e0001 */ 	sltiu	$t6,$t3,0x1
/*  f195fd4:	ae4e01e0 */ 	sw	$t6,0x1e0($s2)
/*  f195fd8:	10000036 */ 	b	.L0f1960b4
/*  f195fdc:	a650000a */ 	sh	$s0,0xa($s2)
.L0f195fe0:
/*  f195fe0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f195fe4:	54610021 */ 	bnel	$v1,$at,.L0f19606c
/*  f195fe8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f195fec:	0fc65227 */ 	jal	func0f19489c
/*  f195ff0:	02802025 */ 	or	$a0,$s4,$zero
/*  f195ff4:	1040002f */ 	beqz	$v0,.L0f1960b4
/*  f195ff8:	00000000 */ 	nop
/*  f195ffc:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f196000:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f196004:	2415002b */ 	addiu	$s5,$zero,0x2b
/*  f196008:	3c07800b */ 	lui	$a3,%hi(g_ScenarioData)
/*  f19600c:	24e7c110 */ 	addiu	$a3,$a3,%lo(g_ScenarioData)
/*  f196010:	00026040 */ 	sll	$t4,$v0,0x1
/*  f196014:	00ec7821 */ 	addu	$t7,$a3,$t4
/*  f196018:	85e30008 */ 	lh	$v1,0x8($t7)
/*  f19601c:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f196020:	27a601d8 */ 	addiu	$a2,$sp,0x1d8
/*  f196024:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f196028:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f19602c:	0fc456ac */ 	jal	padUnpack
/*  f196030:	87240018 */ 	lh	$a0,0x18($t9)
/*  f196034:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f196038:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f19603c:	e64400ec */ 	swc1	$f4,0xec($s2)
/*  f196040:	c7a801dc */ 	lwc1	$f8,0x1dc($sp)
/*  f196044:	314dff7f */ 	andi	$t5,$t2,0xff7f
/*  f196048:	e64800f0 */ 	swc1	$f8,0xf0($s2)
/*  f19604c:	c7a601e0 */ 	lwc1	$f6,0x1e0($sp)
/*  f196050:	e64600f4 */ 	swc1	$f6,0xf4($s2)
/*  f196054:	8fa90220 */ 	lw	$t1,0x220($sp)
/*  f196058:	a65e00fa */ 	sh	$s8,0xfa($s2)
/*  f19605c:	a24d004c */ 	sb	$t5,0x4c($s2)
/*  f196060:	10000014 */ 	b	.L0f1960b4
/*  f196064:	a64900f8 */ 	sh	$t1,0xf8($s2)
/*  f196068:	24010002 */ 	addiu	$at,$zero,0x2
.L0f19606c:
/*  f19606c:	14610011 */ 	bne	$v1,$at,.L0f1960b4
/*  f196070:	3c0b800b */ 	lui	$t3,%hi(g_ScenarioData+0x13c)
/*  f196074:	8d6bc24c */ 	lw	$t3,%lo(g_ScenarioData+0x13c)($t3)
/*  f196078:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f19607c:	156e000d */ 	bne	$t3,$t6,.L0f1960b4
/*  f196080:	00000000 */ 	nop
/*  f196084:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196088:	02802025 */ 	or	$a0,$s4,$zero
/*  f19608c:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f196090:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f196094:	846c00d2 */ 	lh	$t4,0xd2($v1)
/*  f196098:	2415002e */ 	addiu	$s5,$zero,0x2e
/*  f19609c:	104c0005 */ 	beq	$v0,$t4,.L0f1960b4
/*  f1960a0:	00000000 */ 	nop
/*  f1960a4:	8c6f0080 */ 	lw	$t7,0x80($v1)
/*  f1960a8:	2415002c */ 	addiu	$s5,$zero,0x2c
/*  f1960ac:	10000001 */ 	b	.L0f1960b4
/*  f1960b0:	ae4f0010 */ 	sw	$t7,0x10($s2)
.L0f1960b4:
/*  f1960b4:	06a100a0 */ 	bgez	$s5,.L0f196338
/*  f1960b8:	00000000 */ 	nop
/*  f1960bc:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f1960c0:	2401000c */ 	addiu	$at,$zero,0xc
/*  f1960c4:	93020047 */ 	lbu	$v0,0x47($t8)
/*  f1960c8:	54410011 */ 	bnel	$v0,$at,.L0f196110
/*  f1960cc:	24010009 */ 	addiu	$at,$zero,0x9
/*  f1960d0:	86420076 */ 	lh	$v0,0x76($s2)
/*  f1960d4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1960d8:	3c05800b */ 	lui	$a1,%hi(g_MpPlayerChrs)
/*  f1960dc:	04400096 */ 	bltz	$v0,.L0f196338
/*  f1960e0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f1960e4:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f1960e8:	0fc64a53 */ 	jal	func0f19294c
/*  f1960ec:	8ca5c4d0 */ 	lw	$a1,%lo(g_MpPlayerChrs)($a1)
/*  f1960f0:	14400091 */ 	bnez	$v0,.L0f196338
/*  f1960f4:	00000000 */ 	nop
/*  f1960f8:	86490076 */ 	lh	$t1,0x76($s2)
/*  f1960fc:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196100:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196104:	1000008c */ 	b	.L0f196338
/*  f196108:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f19610c:	24010009 */ 	addiu	$at,$zero,0x9
.L0f196110:
/*  f196110:	54410021 */ 	bnel	$v0,$at,.L0f196198
/*  f196114:	24010008 */ 	addiu	$at,$zero,0x8
/*  f196118:	8e4a0114 */ 	lw	$t2,0x114($s2)
/*  f19611c:	0543000f */ 	bgezl	$t2,.L0f19615c
/*  f196120:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f196124:	86420076 */ 	lh	$v0,0x76($s2)
/*  f196128:	02802025 */ 	or	$a0,$s4,$zero
/*  f19612c:	3c05800b */ 	lui	$a1,%hi(g_MpPlayerChrs)
/*  f196130:	04400009 */ 	bltz	$v0,.L0f196158
/*  f196134:	00026880 */ 	sll	$t5,$v0,0x2
/*  f196138:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f19613c:	8ca5c4d0 */ 	lw	$a1,%lo(g_MpPlayerChrs)($a1)
/*  f196140:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f196144:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f196148:	54400004 */ 	bnezl	$v0,.L0f19615c
/*  f19614c:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f196150:	864b0076 */ 	lh	$t3,0x76($s2)
/*  f196154:	ae4b0114 */ 	sw	$t3,0x114($s2)
.L0f196158:
/*  f196158:	8e420114 */ 	lw	$v0,0x114($s2)
.L0f19615c:
/*  f19615c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196160:	3c05800b */ 	lui	$a1,%hi(g_MpPlayerChrs)
/*  f196164:	04400074 */ 	bltz	$v0,.L0f196338
/*  f196168:	00027080 */ 	sll	$t6,$v0,0x2
/*  f19616c:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f196170:	0fc64a53 */ 	jal	func0f19294c
/*  f196174:	8ca5c4d0 */ 	lw	$a1,%lo(g_MpPlayerChrs)($a1)
/*  f196178:	1440006f */ 	bnez	$v0,.L0f196338
/*  f19617c:	00000000 */ 	nop
/*  f196180:	8e4c0114 */ 	lw	$t4,0x114($s2)
/*  f196184:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196188:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f19618c:	1000006a */ 	b	.L0f196338
/*  f196190:	a64c0008 */ 	sh	$t4,0x8($s2)
/*  f196194:	24010008 */ 	addiu	$at,$zero,0x8
.L0f196198:
/*  f196198:	54410028 */ 	bnel	$v0,$at,.L0f19623c
/*  f19619c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1961a0:	0fc62179 */ 	jal	mpGetPlayerRankings
/*  f1961a4:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f1961a8:	18400063 */ 	blez	$v0,.L0f196338
/*  f1961ac:	00408825 */ 	or	$s1,$v0,$zero
/*  f1961b0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f1961b4:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f1961b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1961bc:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f1961c0:	03109821 */ 	addu	$s3,$t8,$s0
.L0f1961c4:
/*  f1961c4:	0fc6343a */ 	jal	func0f18d0e8
/*  f1961c8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f1961cc:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f1961d0:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f1961d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1961d8:	10540011 */ 	beq	$v0,$s4,.L0f196220
/*  f1961dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1961e0:	0fc0e6a5 */ 	jal	chrIsDead
/*  f1961e4:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f1961e8:	1440000d */ 	bnez	$v0,.L0f196220
/*  f1961ec:	02802025 */ 	or	$a0,$s4,$zero
/*  f1961f0:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f1961f4:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f1961f8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1961fc:	10400008 */ 	beqz	$v0,.L0f196220
/*  f196200:	02802025 */ 	or	$a0,$s4,$zero
/*  f196204:	0fc64a53 */ 	jal	func0f19294c
/*  f196208:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f19620c:	14400004 */ 	bnez	$v0,.L0f196220
/*  f196210:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f196214:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196218:	a6590008 */ 	sh	$t9,0x8($s2)
/*  f19621c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196220:
/*  f196220:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f196224:	0213082b */ 	sltu	$at,$s0,$s3
/*  f196228:	1420ffe6 */ 	bnez	$at,.L0f1961c4
/*  f19622c:	00000000 */ 	nop
/*  f196230:	10000041 */ 	b	.L0f196338
/*  f196234:	00000000 */ 	nop
/*  f196238:	24010006 */ 	addiu	$at,$zero,0x6
.L0f19623c:
/*  f19623c:	1441003e */ 	bne	$v0,$at,.L0f196338
/*  f196240:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f196244:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f196248:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f19624c:	44805000 */ 	mtc1	$zero,$f10
/*  f196250:	03c08825 */ 	or	$s1,$s8,$zero
/*  f196254:	00008025 */ 	or	$s0,$zero,$zero
/*  f196258:	19200032 */ 	blez	$t1,.L0f196324
/*  f19625c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
.L0f196260:
/*  f196260:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f196264:	02002025 */ 	or	$a0,$s0,$zero
/*  f196268:	10540029 */ 	beq	$v0,$s4,.L0f196310
/*  f19626c:	00402025 */ 	or	$a0,$v0,$zero
/*  f196270:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196274:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f196278:	14400025 */ 	bnez	$v0,.L0f196310
/*  f19627c:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f196280:	02802025 */ 	or	$a0,$s4,$zero
/*  f196284:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f196288:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f19628c:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f196290:	1040001f */ 	beqz	$v0,.L0f196310
/*  f196294:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f196298:	02802025 */ 	or	$a0,$s4,$zero
/*  f19629c:	0fc64a53 */ 	jal	func0f19294c
/*  f1962a0:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f1962a4:	1440001a */ 	bnez	$v0,.L0f196310
/*  f1962a8:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f1962ac:	8caa02d4 */ 	lw	$t2,0x2d4($a1)
/*  f1962b0:	11400005 */ 	beqz	$t2,.L0f1962c8
/*  f1962b4:	00000000 */ 	nop
/*  f1962b8:	c4b20104 */ 	lwc1	$f18,0x104($a1)
/*  f1962bc:	c4a40100 */ 	lwc1	$f4,0x100($a1)
/*  f1962c0:	1000000b */ 	b	.L0f1962f0
/*  f1962c4:	46049001 */ 	sub.s	$f0,$f18,$f4
.L0f1962c8:
/*  f1962c8:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f1962cc:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f1962d0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1962d4:	02cd5821 */ 	addu	$t3,$s6,$t5
/*  f1962d8:	8d6e0064 */ 	lw	$t6,0x64($t3)
/*  f1962dc:	3c014100 */ 	lui	$at,0x4100
/*  f1962e0:	44813000 */ 	mtc1	$at,$f6
/*  f1962e4:	c5c800dc */ 	lwc1	$f8,0xdc($t6)
/*  f1962e8:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f1962ec:	00000000 */ 	nop
.L0f1962f0:
/*  f1962f0:	06200005 */ 	bltz	$s1,.L0f196308
/*  f1962f4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f1962f8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f1962fc:	00000000 */ 	nop
/*  f196300:	45020004 */ 	bc1fl	.L0f196314
/*  f196304:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f196308:
/*  f196308:	02008825 */ 	or	$s1,$s0,$zero
/*  f19630c:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
.L0f196310:
/*  f196310:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f196314:
/*  f196314:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f196318:	020c082a */ 	slt	$at,$s0,$t4
/*  f19631c:	1420ffd0 */ 	bnez	$at,.L0f196260
/*  f196320:	00000000 */ 	nop
.L0f196324:
/*  f196324:	06200004 */ 	bltz	$s1,.L0f196338
/*  f196328:	00000000 */ 	nop
/*  f19632c:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f196330:	a6510008 */ 	sh	$s1,0x8($s2)
/*  f196334:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196338:
/*  f196338:	06a1000d */ 	bgez	$s5,.L0f196370
/*  f19633c:	00000000 */ 	nop
/*  f196340:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f196344:	13d8000a */ 	beq	$s8,$t8,.L0f196370
/*  f196348:	00000000 */ 	nop
/*  f19634c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196350:	02802025 */ 	or	$a0,$s4,$zero
/*  f196354:	02802025 */ 	or	$a0,$s4,$zero
/*  f196358:	0fc64b70 */ 	jal	func0f192dc0
/*  f19635c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196360:	10400003 */ 	beqz	$v0,.L0f196370
/*  f196364:	00000000 */ 	nop
/*  f196368:	2415002f */ 	addiu	$s5,$zero,0x2f
/*  f19636c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.L0f196370:
/*  f196370:	06a1000b */ 	bgez	$s5,.L0f1963a0
/*  f196374:	02802025 */ 	or	$a0,$s4,$zero
/*  f196378:	0fc64d4c */ 	jal	func0f193530
/*  f19637c:	3c054396 */ 	lui	$a1,0x4396
/*  f196380:	04400007 */ 	bltz	$v0,.L0f1963a0
/*  f196384:	00408025 */ 	or	$s0,$v0,$zero
/*  f196388:	0c004b70 */ 	jal	random
/*  f19638c:	24150032 */ 	addiu	$s5,$zero,0x32
/*  f196390:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f196394:	2df90001 */ 	sltiu	$t9,$t7,0x1
/*  f196398:	ae5901e0 */ 	sw	$t9,0x1e0($s2)
/*  f19639c:	a650000a */ 	sh	$s0,0xa($s2)
.L0f1963a0:
/*  f1963a0:	06a10006 */ 	bgez	$s5,.L0f1963bc
/*  f1963a4:	00000000 */ 	nop
/*  f1963a8:	0fc651ad */ 	jal	func0f1946b4
/*  f1963ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f1963b0:	10400002 */ 	beqz	$v0,.L0f1963bc
/*  f1963b4:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f1963b8:	2415002a */ 	addiu	$s5,$zero,0x2a
.L0f1963bc:
/*  f1963bc:	3c13800b */ 	lui	$s3,%hi(g_MpNumPlayers)
/*  f1963c0:	06a0007f */ 	bltz	$s5,.L0f1965c0
/*  f1963c4:	2673c530 */ 	addiu	$s3,$s3,%lo(g_MpNumPlayers)
/*  f1963c8:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1963cc:	56a1000a */ 	bnel	$s5,$at,.L0f1963f8
/*  f1963d0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1963d4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1963d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1963dc:	50a00079 */ 	beqzl	$a1,.L0f1965c4
/*  f1963e0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1963e4:	0fc0eadd */ 	jal	chrGoToProp
/*  f1963e8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1963ec:	10000074 */ 	b	.L0f1965c0
/*  f1963f0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1963f4:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f1963f8:
/*  f1963f8:	16a10008 */ 	bne	$s5,$at,.L0f19641c
/*  f1963fc:	24100032 */ 	addiu	$s0,$zero,0x32
/*  f196400:	928902a0 */ 	lbu	$t1,0x2a0($s4)
/*  f196404:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f196408:	5121006e */ 	beql	$t1,$at,.L0f1965c4
/*  f19640c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196410:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196414:	1000006a */ 	b	.L0f1965c0
/*  f196418:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f19641c:
/*  f19641c:	16b0000e */ 	bne	$s5,$s0,.L0f196458
/*  f196420:	24010033 */ 	addiu	$at,$zero,0x33
/*  f196424:	928a02a0 */ 	lbu	$t2,0x2a0($s4)
/*  f196428:	520a0066 */ 	beql	$s0,$t2,.L0f1965c4
/*  f19642c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196430:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196434:	8e4d01e0 */ 	lw	$t5,0x1e0($s2)
/*  f196438:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f19643c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196440:	51a00060 */ 	beqzl	$t5,.L0f1965c4
/*  f196444:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196448:	0fc649df */ 	jal	func0f19277c
/*  f19644c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f196450:	1000005c */ 	b	.L0f1965c4
/*  f196454:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f196458:
/*  f196458:	56a10010 */ 	bnel	$s5,$at,.L0f19649c
/*  f19645c:	2401002b */ 	addiu	$at,$zero,0x2b
/*  f196460:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196464:	8e4b01dc */ 	lw	$t3,0x1dc($s2)
/*  f196468:	02802025 */ 	or	$a0,$s4,$zero
/*  f19646c:	51600004 */ 	beqzl	$t3,.L0f196480
/*  f196470:	02802025 */ 	or	$a0,$s4,$zero
/*  f196474:	0fc649df */ 	jal	func0f19277c
/*  f196478:	03c02825 */ 	or	$a1,$s8,$zero
/*  f19647c:	02802025 */ 	or	$a0,$s4,$zero
.L0f196480:
/*  f196480:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f196484:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f196488:	0fc0e10f */ 	jal	chrGoToPos
/*  f19648c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f196490:	1000004c */ 	b	.L0f1965c4
/*  f196494:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196498:	2401002b */ 	addiu	$at,$zero,0x2b
.L0f19649c:
/*  f19649c:	56a10037 */ 	bnel	$s5,$at,.L0f19657c
/*  f1964a0:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f1964a4:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f1964a8:	c64400ec */ 	lwc1	$f4,0xec($s2)
/*  f1964ac:	44808000 */ 	mtc1	$zero,$f16
/*  f1964b0:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f1964b4:	c64600f0 */ 	lwc1	$f6,0xf0($s2)
/*  f1964b8:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f1964bc:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f1964c0:	c65200f4 */ 	lwc1	$f18,0xf4($s2)
/*  f1964c4:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f1964c8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f1964cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f1964d0:	44817000 */ 	mtc1	$at,$f14
/*  f1964d4:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f1964d8:	45000002 */ 	bc1f	.L0f1964e4
/*  f1964dc:	46125301 */ 	sub.s	$f12,$f10,$f18
/*  f1964e0:	46000007 */ 	neg.s	$f0,$f0
.L0f1964e4:
/*  f1964e4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f1964e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1964ec:	264500ec */ 	addiu	$a1,$s2,0xec
/*  f1964f0:	264600f8 */ 	addiu	$a2,$s2,0xf8
/*  f1964f4:	45000002 */ 	bc1f	.L0f196500
/*  f1964f8:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f1964fc:	46001087 */ 	neg.s	$f2,$f2
.L0f196500:
/*  f196500:	4610603c */ 	c.lt.s	$f12,$f16
/*  f196504:	00000000 */ 	nop
/*  f196508:	45020003 */ 	bc1fl	.L0f196518
/*  f19650c:	4600703c */ 	c.lt.s	$f14,$f0
/*  f196510:	46006307 */ 	neg.s	$f12,$f12
/*  f196514:	4600703c */ 	c.lt.s	$f14,$f0
.L0f196518:
/*  f196518:	00000000 */ 	nop
/*  f19651c:	4501000e */ 	bc1t	.L0f196558
/*  f196520:	00000000 */ 	nop
/*  f196524:	460c703c */ 	c.lt.s	$f14,$f12
/*  f196528:	3c014348 */ 	lui	$at,0x4348
/*  f19652c:	4501000a */ 	bc1t	.L0f196558
/*  f196530:	00000000 */ 	nop
/*  f196534:	44812000 */ 	mtc1	$at,$f4
/*  f196538:	00000000 */ 	nop
/*  f19653c:	4602203c */ 	c.lt.s	$f4,$f2
/*  f196540:	00000000 */ 	nop
/*  f196544:	45000008 */ 	bc1f	.L0f196568
/*  f196548:	00000000 */ 	nop
/*  f19654c:	828c032d */ 	lb	$t4,0x32d($s4)
/*  f196550:	05800005 */ 	bltz	$t4,.L0f196568
/*  f196554:	00000000 */ 	nop
.L0f196558:
/*  f196558:	0fc0e10f */ 	jal	chrGoToPos
/*  f19655c:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f196560:	10000018 */ 	b	.L0f1965c4
/*  f196564:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f196568:
/*  f196568:	0fc0baaf */ 	jal	chrStand
/*  f19656c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196570:	10000014 */ 	b	.L0f1965c4
/*  f196574:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196578:	2401002c */ 	addiu	$at,$zero,0x2c
.L0f19657c:
/*  f19657c:	56a1000c */ 	bnel	$s5,$at,.L0f1965b0
/*  f196580:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f196584:	8e580010 */ 	lw	$t8,0x10($s2)
/*  f196588:	02802025 */ 	or	$a0,$s4,$zero
/*  f19658c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f196590:	5300000c */ 	beqzl	$t8,.L0f1965c4
/*  f196594:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f196598:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f19659c:	0fc0eadd */ 	jal	chrGoToProp
/*  f1965a0:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1965a4:	10000007 */ 	b	.L0f1965c4
/*  f1965a8:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1965ac:	2401002e */ 	addiu	$at,$zero,0x2e
.L0f1965b0:
/*  f1965b0:	16a10003 */ 	bne	$s5,$at,.L0f1965c0
/*  f1965b4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1965b8:	0fc0baaf */ 	jal	chrStand
/*  f1965bc:	a29502a0 */ 	sb	$s5,0x2a0($s4)
.L0f1965c0:
/*  f1965c0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.L0f1965c4:
/*  f1965c4:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1965c8:	24100032 */ 	addiu	$s0,$zero,0x32
/*  f1965cc:	54410012 */ 	bnel	$v0,$at,.L0f196618
/*  f1965d0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1965d4:	828f0007 */ 	lb	$t7,0x7($s4)
/*  f1965d8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1965dc:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1965e0:	15e1000a */ 	bne	$t7,$at,.L0f19660c
/*  f1965e4:	00000000 */ 	nop
/*  f1965e8:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1965ec:	10a00007 */ 	beqz	$a1,.L0f19660c
/*  f1965f0:	00000000 */ 	nop
/*  f1965f4:	8cb90018 */ 	lw	$t9,0x18($a1)
/*  f1965f8:	17200004 */ 	bnez	$t9,.L0f19660c
/*  f1965fc:	00000000 */ 	nop
/*  f196600:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f196604:	11200160 */ 	beqz	$t1,.L0f196b88
/*  f196608:	00000000 */ 	nop
.L0f19660c:
/*  f19660c:	1000015e */ 	b	.L0f196b88
/*  f196610:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
/*  f196614:	2401002f */ 	addiu	$at,$zero,0x2f
.L0f196618:
/*  f196618:	1441003e */ 	bne	$v0,$at,.L0f196714
/*  f19661c:	00000000 */ 	nop
/*  f196620:	86420008 */ 	lh	$v0,0x8($s2)
/*  f196624:	3c04800b */ 	lui	$a0,%hi(g_MpPlayerChrs)
/*  f196628:	04400011 */ 	bltz	$v0,.L0f196670
/*  f19662c:	00026880 */ 	sll	$t5,$v0,0x2
/*  f196630:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f196634:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196638:	8c84c4d0 */ 	lw	$a0,%lo(g_MpPlayerChrs)($a0)
/*  f19663c:	5440000a */ 	bnezl	$v0,.L0f196668
/*  f196640:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f196644:	864b0008 */ 	lh	$t3,0x8($s2)
/*  f196648:	3c05800b */ 	lui	$a1,%hi(g_MpPlayerChrs)
/*  f19664c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196650:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f196654:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f196658:	0fc64b70 */ 	jal	func0f192dc0
/*  f19665c:	8ca5c4d0 */ 	lw	$a1,%lo(g_MpPlayerChrs)($a1)
/*  f196660:	14400003 */ 	bnez	$v0,.L0f196670
/*  f196664:	240c0029 */ 	addiu	$t4,$zero,0x29
.L0f196668:
/*  f196668:	10000147 */ 	b	.L0f196b88
/*  f19666c:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.L0f196670:
/*  f196670:	86580008 */ 	lh	$t8,0x8($s2)
/*  f196674:	07010013 */ 	bgez	$t8,.L0f1966c4
/*  f196678:	00000000 */ 	nop
/*  f19667c:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f196680:	53cf000e */ 	beql	$s8,$t7,.L0f1966bc
/*  f196684:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f196688:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19668c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196690:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196694:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196698:	54400008 */ 	bnezl	$v0,.L0f1966bc
/*  f19669c:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f1966a0:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f1966a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966a8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966ac:	0fc64b70 */ 	jal	func0f192dc0
/*  f1966b0:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f1966b4:	14400003 */ 	bnez	$v0,.L0f1966c4
/*  f1966b8:	24190029 */ 	addiu	$t9,$zero,0x29
.L0f1966bc:
/*  f1966bc:	10000132 */ 	b	.L0f196b88
/*  f1966c0:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.L0f1966c4:
/*  f1966c4:	0fc65d80 */ 	jal	func0f197600
/*  f1966c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966cc:	0fc6519c */ 	jal	func0f194670
/*  f1966d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1966d4:	10400003 */ 	beqz	$v0,.L0f1966e4
/*  f1966d8:	24090029 */ 	addiu	$t1,$zero,0x29
/*  f1966dc:	1000012a */ 	b	.L0f196b88
/*  f1966e0:	a28902a0 */ 	sb	$t1,0x2a0($s4)
.L0f1966e4:
/*  f1966e4:	8e4201d8 */ 	lw	$v0,0x1d8($s2)
/*  f1966e8:	04400127 */ 	bltz	$v0,.L0f196b88
/*  f1966ec:	00000000 */ 	nop
/*  f1966f0:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f1966f4:	8e4a0120 */ 	lw	$t2,0x120($s2)
/*  f1966f8:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f1966fc:	01a25823 */ 	subu	$t3,$t5,$v0
/*  f196700:	014b082a */ 	slt	$at,$t2,$t3
/*  f196704:	10200120 */ 	beqz	$at,.L0f196b88
/*  f196708:	00000000 */ 	nop
/*  f19670c:	1000011e */ 	b	.L0f196b88
/*  f196710:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196714:
/*  f196714:	1602004d */ 	bne	$s0,$v0,.L0f19684c
/*  f196718:	24010033 */ 	addiu	$at,$zero,0x33
/*  f19671c:	8642000a */ 	lh	$v0,0xa($s2)
/*  f196720:	3c04800b */ 	lui	$a0,%hi(g_MpPlayerChrs)
/*  f196724:	04400005 */ 	bltz	$v0,.L0f19673c
/*  f196728:	00026080 */ 	sll	$t4,$v0,0x2
/*  f19672c:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f196730:	0fc0e6a5 */ 	jal	chrIsDead
/*  f196734:	8c84c4d0 */ 	lw	$a0,%lo(g_MpPlayerChrs)($a0)
/*  f196738:	10400003 */ 	beqz	$v0,.L0f196748
.L0f19673c:
/*  f19673c:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196740:	10000111 */ 	b	.L0f196b88
/*  f196744:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f196748:
/*  f196748:	0fc65d80 */ 	jal	func0f197600
/*  f19674c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196750:	8e4f01e0 */ 	lw	$t7,0x1e0($s2)
/*  f196754:	11e00037 */ 	beqz	$t7,.L0f196834
/*  f196758:	00000000 */ 	nop
/*  f19675c:	8699017e */ 	lh	$t9,0x17e($s4)
/*  f196760:	13d90034 */ 	beq	$s8,$t9,.L0f196834
/*  f196764:	00000000 */ 	nop
/*  f196768:	8e490128 */ 	lw	$t1,0x128($s2)
/*  f19676c:	11200031 */ 	beqz	$t1,.L0f196834
/*  f196770:	00000000 */ 	nop
/*  f196774:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196778:	02802025 */ 	or	$a0,$s4,$zero
/*  f19677c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196780:	0fc64b70 */ 	jal	func0f192dc0
/*  f196784:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196788:	1040002a */ 	beqz	$v0,.L0f196834
/*  f19678c:	3c0143fa */ 	lui	$at,0x43fa
/*  f196790:	864d000a */ 	lh	$t5,0xa($s2)
/*  f196794:	3c0b800b */ 	lui	$t3,%hi(g_MpPlayerChrs)
/*  f196798:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f19679c:	000d5080 */ 	sll	$t2,$t5,0x2
/*  f1967a0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f1967a4:	8d6bc4d0 */ 	lw	$t3,%lo(g_MpPlayerChrs)($t3)
/*  f1967a8:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f1967ac:	44806000 */ 	mtc1	$zero,$f12
/*  f1967b0:	8d62001c */ 	lw	$v0,0x1c($t3)
/*  f1967b4:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f1967b8:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f1967bc:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f1967c0:	46064001 */ 	sub.s	$f0,$f8,$f6
/*  f1967c4:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f1967c8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1967cc:	00000000 */ 	nop
/*  f1967d0:	45020003 */ 	bc1fl	.L0f1967e0
/*  f1967d4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1967d8:	46000007 */ 	neg.s	$f0,$f0
/*  f1967dc:	460c103c */ 	c.lt.s	$f2,$f12
.L0f1967e0:
/*  f1967e0:	44816000 */ 	mtc1	$at,$f12
/*  f1967e4:	45020003 */ 	bc1fl	.L0f1967f4
/*  f1967e8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1967ec:	46001087 */ 	neg.s	$f2,$f2
/*  f1967f0:	460c003c */ 	c.lt.s	$f0,$f12
.L0f1967f4:
/*  f1967f4:	00000000 */ 	nop
/*  f1967f8:	4500000e */ 	bc1f	.L0f196834
/*  f1967fc:	00000000 */ 	nop
/*  f196800:	460c103c */ 	c.lt.s	$f2,$f12
/*  f196804:	240e002f */ 	addiu	$t6,$zero,0x2f
/*  f196808:	02802025 */ 	or	$a0,$s4,$zero
/*  f19680c:	45000009 */ 	bc1f	.L0f196834
/*  f196810:	00000000 */ 	nop
/*  f196814:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196818:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
/*  f19681c:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196820:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196824:	240c012c */ 	addiu	$t4,$zero,0x12c
/*  f196828:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f19682c:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
/*  f196830:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f196834:
/*  f196834:	0fc6519c */ 	jal	func0f194670
/*  f196838:	02802025 */ 	or	$a0,$s4,$zero
/*  f19683c:	104000d2 */ 	beqz	$v0,.L0f196b88
/*  f196840:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196844:	100000d0 */ 	b	.L0f196b88
/*  f196848:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f19684c:
/*  f19684c:	54410063 */ 	bnel	$v0,$at,.L0f1969dc
/*  f196850:	2401002b */ 	addiu	$at,$zero,0x2b
/*  f196854:	828f0007 */ 	lb	$t7,0x7($s4)
/*  f196858:	2401000f */ 	addiu	$at,$zero,0xf
/*  f19685c:	11e10058 */ 	beq	$t7,$at,.L0f1969c0
/*  f196860:	00000000 */ 	nop
/*  f196864:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f196868:	c648008c */ 	lwc1	$f8,0x8c($s2)
/*  f19686c:	44807000 */ 	mtc1	$zero,$f14
/*  f196870:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f196874:	c64a0090 */ 	lwc1	$f10,0x90($s2)
/*  f196878:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f19687c:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f196880:	c6440094 */ 	lwc1	$f4,0x94($s2)
/*  f196884:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f196888:	3c014220 */ 	lui	$at,0x4220
/*  f19688c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f196890:	460a3081 */ 	sub.s	$f2,$f6,$f10
/*  f196894:	45000002 */ 	bc1f	.L0f1968a0
/*  f196898:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f19689c:	46000007 */ 	neg.s	$f0,$f0
.L0f1968a0:
/*  f1968a0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f1968a4:	00000000 */ 	nop
/*  f1968a8:	45020003 */ 	bc1fl	.L0f1968b8
/*  f1968ac:	460e603c */ 	c.lt.s	$f12,$f14
/*  f1968b0:	46001087 */ 	neg.s	$f2,$f2
/*  f1968b4:	460e603c */ 	c.lt.s	$f12,$f14
.L0f1968b8:
/*  f1968b8:	44817000 */ 	mtc1	$at,$f14
/*  f1968bc:	45020003 */ 	bc1fl	.L0f1968cc
/*  f1968c0:	8e4200dc */ 	lw	$v0,0xdc($s2)
/*  f1968c4:	46006307 */ 	neg.s	$f12,$f12
/*  f1968c8:	8e4200dc */ 	lw	$v0,0xdc($s2)
.L0f1968cc:
/*  f1968cc:	58400005 */ 	blezl	$v0,.L0f1968e4
/*  f1968d0:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1968d4:	8ed90038 */ 	lw	$t9,0x38($s6)
/*  f1968d8:	00594823 */ 	subu	$t1,$v0,$t9
/*  f1968dc:	ae4900dc */ 	sw	$t1,0xdc($s2)
/*  f1968e0:	4600703c */ 	c.lt.s	$f14,$f0
.L0f1968e4:
/*  f1968e4:	00000000 */ 	nop
/*  f1968e8:	4503000f */ 	bc1tl	.L0f196928
/*  f1968ec:	8e4b00dc */ 	lw	$t3,0xdc($s2)
/*  f1968f0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1968f4:	3c014348 */ 	lui	$at,0x4348
/*  f1968f8:	4503000b */ 	bc1tl	.L0f196928
/*  f1968fc:	8e4b00dc */ 	lw	$t3,0xdc($s2)
/*  f196900:	44814000 */ 	mtc1	$at,$f8
/*  f196904:	00000000 */ 	nop
/*  f196908:	4602403c */ 	c.lt.s	$f8,$f2
/*  f19690c:	00000000 */ 	nop
/*  f196910:	4502000e */ 	bc1fl	.L0f19694c
/*  f196914:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
/*  f196918:	828a032d */ 	lb	$t2,0x32d($s4)
/*  f19691c:	0542000b */ 	bltzl	$t2,.L0f19694c
/*  f196920:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
/*  f196924:	8e4b00dc */ 	lw	$t3,0xdc($s2)
.L0f196928:
/*  f196928:	02802025 */ 	or	$a0,$s4,$zero
/*  f19692c:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f196930:	1d60001e */ 	bgtz	$t3,.L0f1969ac
/*  f196934:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f196938:	0fc0e10f */ 	jal	chrGoToPos
/*  f19693c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f196940:	1000001b */ 	b	.L0f1969b0
/*  f196944:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196948:	8e4e01dc */ 	lw	$t6,0x1dc($s2)
.L0f19694c:
/*  f19694c:	51c00018 */ 	beqzl	$t6,.L0f1969b0
/*  f196950:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196954:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f196958:	53cc0015 */ 	beql	$s8,$t4,.L0f1969b0
/*  f19695c:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f196960:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f196964:	53000012 */ 	beqzl	$t8,.L0f1969b0
/*  f196968:	8e4900dc */ 	lw	$t1,0xdc($s2)
/*  f19696c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196970:	02802025 */ 	or	$a0,$s4,$zero
/*  f196974:	02802025 */ 	or	$a0,$s4,$zero
/*  f196978:	0fc64b70 */ 	jal	func0f192dc0
/*  f19697c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196980:	1040000a */ 	beqz	$v0,.L0f1969ac
/*  f196984:	240f002f */ 	addiu	$t7,$zero,0x2f
/*  f196988:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
/*  f19698c:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196990:	02802025 */ 	or	$a0,$s4,$zero
/*  f196994:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196998:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19699c:	2419012c */ 	addiu	$t9,$zero,0x12c
/*  f1969a0:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1969a4:	ae5901d8 */ 	sw	$t9,0x1d8($s2)
/*  f1969a8:	a25e0074 */ 	sb	$s8,0x74($s2)
.L0f1969ac:
/*  f1969ac:	8e4900dc */ 	lw	$t1,0xdc($s2)
.L0f1969b0:
/*  f1969b0:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f1969b4:	1d200002 */ 	bgtz	$t1,.L0f1969c0
/*  f1969b8:	00000000 */ 	nop
/*  f1969bc:	ae4d00dc */ 	sw	$t5,0xdc($s2)
.L0f1969c0:
/*  f1969c0:	0fc6519c */ 	jal	func0f194670
/*  f1969c4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1969c8:	1040006f */ 	beqz	$v0,.L0f196b88
/*  f1969cc:	240a0029 */ 	addiu	$t2,$zero,0x29
/*  f1969d0:	1000006d */ 	b	.L0f196b88
/*  f1969d4:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
/*  f1969d8:	2401002b */ 	addiu	$at,$zero,0x2b
.L0f1969dc:
/*  f1969dc:	1441002f */ 	bne	$v0,$at,.L0f196a9c
/*  f1969e0:	3c0b800b */ 	lui	$t3,%hi(g_MpSetup+0x10)
/*  f1969e4:	916bcb98 */ 	lbu	$t3,%lo(g_MpSetup+0x10)($t3)
/*  f1969e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1969ec:	5561001f */ 	bnel	$t3,$at,.L0f196a6c
/*  f1969f0:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f1969f4:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f1969f8:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData+0xe)
/*  f1969fc:	000e67c2 */ 	srl	$t4,$t6,0x1f
/*  f196a00:	5180001a */ 	beqzl	$t4,.L0f196a6c
/*  f196a04:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a08:	8442c11e */ 	lh	$v0,%lo(g_ScenarioData+0xe)($v0)
/*  f196a0c:	8e5800bc */ 	lw	$t8,0xbc($s2)
/*  f196a10:	53020006 */ 	beql	$t8,$v0,.L0f196a2c
/*  f196a14:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f196a18:	924f004c */ 	lbu	$t7,0x4c($s2)
/*  f196a1c:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f196a20:	10000011 */ 	b	.L0f196a68
/*  f196a24:	a259004c */ 	sb	$t9,0x4c($s2)
/*  f196a28:	8e89001c */ 	lw	$t1,0x1c($s4)
.L0f196a2c:
/*  f196a2c:	852d0028 */ 	lh	$t5,0x28($t1)
/*  f196a30:	51a2000e */ 	beql	$t5,$v0,.L0f196a6c
/*  f196a34:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a38:	86440048 */ 	lh	$a0,0x48($s2)
/*  f196a3c:	04820006 */ 	bltzl	$a0,.L0f196a58
/*  f196a40:	8644004a */ 	lh	$a0,0x4a($s2)
/*  f196a44:	0fc45890 */ 	jal	padSetFlag
/*  f196a48:	3c050002 */ 	lui	$a1,0x2
/*  f196a4c:	10000007 */ 	b	.L0f196a6c
/*  f196a50:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a54:	8644004a */ 	lh	$a0,0x4a($s2)
.L0f196a58:
/*  f196a58:	04820004 */ 	bltzl	$a0,.L0f196a6c
/*  f196a5c:	828a0007 */ 	lb	$t2,0x7($s4)
/*  f196a60:	0fc45942 */ 	jal	coverSetFlag
/*  f196a64:	24050100 */ 	addiu	$a1,$zero,0x100
.L0f196a68:
/*  f196a68:	828a0007 */ 	lb	$t2,0x7($s4)
.L0f196a6c:
/*  f196a6c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f196a70:	240b0029 */ 	addiu	$t3,$zero,0x29
/*  f196a74:	11410003 */ 	beq	$t2,$at,.L0f196a84
/*  f196a78:	00000000 */ 	nop
/*  f196a7c:	10000042 */ 	b	.L0f196b88
/*  f196a80:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
.L0f196a84:
/*  f196a84:	0fc6519c */ 	jal	func0f194670
/*  f196a88:	02802025 */ 	or	$a0,$s4,$zero
/*  f196a8c:	1040003e */ 	beqz	$v0,.L0f196b88
/*  f196a90:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f196a94:	1000003c */ 	b	.L0f196b88
/*  f196a98:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196a9c:
/*  f196a9c:	2401002c */ 	addiu	$at,$zero,0x2c
/*  f196aa0:	54410029 */ 	bnel	$v0,$at,.L0f196b48
/*  f196aa4:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f196aa8:	0fc6519c */ 	jal	func0f194670
/*  f196aac:	02802025 */ 	or	$a0,$s4,$zero
/*  f196ab0:	10400003 */ 	beqz	$v0,.L0f196ac0
/*  f196ab4:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f196ab8:	10000033 */ 	b	.L0f196b88
/*  f196abc:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.L0f196ac0:
/*  f196ac0:	82980007 */ 	lb	$t8,0x7($s4)
/*  f196ac4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f196ac8:	24190029 */ 	addiu	$t9,$zero,0x29
/*  f196acc:	17010008 */ 	bne	$t8,$at,.L0f196af0
/*  f196ad0:	00000000 */ 	nop
/*  f196ad4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f196ad8:	10a00005 */ 	beqz	$a1,.L0f196af0
/*  f196adc:	00000000 */ 	nop
/*  f196ae0:	8caf0018 */ 	lw	$t7,0x18($a1)
/*  f196ae4:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f196ae8:	11e00003 */ 	beqz	$t7,.L0f196af8
/*  f196aec:	00000000 */ 	nop
.L0f196af0:
/*  f196af0:	10000025 */ 	b	.L0f196b88
/*  f196af4:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.L0f196af8:
/*  f196af8:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f196afc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f196b00:	12e30021 */ 	beq	$s7,$v1,.L0f196b88
/*  f196b04:	00000000 */ 	nop
/*  f196b08:	1461001f */ 	bne	$v1,$at,.L0f196b88
/*  f196b0c:	3c09800b */ 	lui	$t1,%hi(g_ScenarioData+0x13c)
/*  f196b10:	8d29c24c */ 	lw	$t1,%lo(g_ScenarioData+0x13c)($t1)
/*  f196b14:	8e8d001c */ 	lw	$t5,0x1c($s4)
/*  f196b18:	152d001b */ 	bne	$t1,$t5,.L0f196b88
/*  f196b1c:	00000000 */ 	nop
/*  f196b20:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b24:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b28:	3c0a800b */ 	lui	$t2,%hi(g_ScenarioData+0xd2)
/*  f196b2c:	854ac1e2 */ 	lh	$t2,%lo(g_ScenarioData+0xd2)($t2)
/*  f196b30:	240b0029 */ 	addiu	$t3,$zero,0x29
/*  f196b34:	144a0014 */ 	bne	$v0,$t2,.L0f196b88
/*  f196b38:	00000000 */ 	nop
/*  f196b3c:	10000012 */ 	b	.L0f196b88
/*  f196b40:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f196b44:	2401002e */ 	addiu	$at,$zero,0x2e
.L0f196b48:
/*  f196b48:	1441000f */ 	bne	$v0,$at,.L0f196b88
/*  f196b4c:	00000000 */ 	nop
/*  f196b50:	0fc6519c */ 	jal	func0f194670
/*  f196b54:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b58:	10400003 */ 	beqz	$v0,.L0f196b68
/*  f196b5c:	240e0029 */ 	addiu	$t6,$zero,0x29
/*  f196b60:	10000009 */ 	b	.L0f196b88
/*  f196b64:	a28e02a0 */ 	sb	$t6,0x2a0($s4)
.L0f196b68:
/*  f196b68:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b70:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0xd2)
/*  f196b74:	858cc1e2 */ 	lh	$t4,%lo(g_ScenarioData+0xd2)($t4)
/*  f196b78:	24180029 */ 	addiu	$t8,$zero,0x29
/*  f196b7c:	104c0002 */ 	beq	$v0,$t4,.L0f196b88
/*  f196b80:	00000000 */ 	nop
/*  f196b84:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.L0f196b88:
/*  f196b88:	0fc64ba4 */ 	jal	func0f192e90
/*  f196b8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b90:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f196b94:	02802025 */ 	or	$a0,$s4,$zero
/*  f196b98:	8ecf000c */ 	lw	$t7,0xc($s6)
/*  f196b9c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f196ba0:	01f9001a */ 	div	$zero,$t7,$t9
/*  f196ba4:	00004810 */ 	mfhi	$t1
/*  f196ba8:	17200002 */ 	bnez	$t9,.L0f196bb4
/*  f196bac:	00000000 */ 	nop
/*  f196bb0:	0007000d */ 	break	0x7
.L0f196bb4:
/*  f196bb4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f196bb8:	17210004 */ 	bne	$t9,$at,.L0f196bcc
/*  f196bbc:	3c018000 */ 	lui	$at,0x8000
/*  f196bc0:	15e10002 */ 	bne	$t7,$at,.L0f196bcc
/*  f196bc4:	00000000 */ 	nop
/*  f196bc8:	0006000d */ 	break	0x6
.L0f196bcc:
/*  f196bcc:	14490024 */ 	bne	$v0,$t1,.L0f196c60
/*  f196bd0:	00000000 */ 	nop
/*  f196bd4:	868d017e */ 	lh	$t5,0x17e($s4)
/*  f196bd8:	13cd0021 */ 	beq	$s8,$t5,.L0f196c60
/*  f196bdc:	00000000 */ 	nop
/*  f196be0:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f196be4:	02802025 */ 	or	$a0,$s4,$zero
/*  f196be8:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f196bec:	00408025 */ 	or	$s0,$v0,$zero
/*  f196bf0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f196bf4:	0fc45095 */ 	jal	waypointFindClosestToPos
/*  f196bf8:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f196bfc:	00408825 */ 	or	$s1,$v0,$zero
/*  f196c00:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f196c04:	0fc45095 */ 	jal	waypointFindClosestToPos
/*  f196c08:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f196c0c:	12200014 */ 	beqz	$s1,.L0f196c60
/*  f196c10:	00408025 */ 	or	$s0,$v0,$zero
/*  f196c14:	10400012 */ 	beqz	$v0,.L0f196c60
/*  f196c18:	00000000 */ 	nop
/*  f196c1c:	8eca0008 */ 	lw	$t2,0x8($s6)
/*  f196c20:	868c0000 */ 	lh	$t4,0x0($s4)
/*  f196c24:	000a5a43 */ 	sra	$t3,$t2,0x9
/*  f196c28:	000b71c0 */ 	sll	$t6,$t3,0x7
/*  f196c2c:	000cc0c0 */ 	sll	$t8,$t4,0x3
/*  f196c30:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f196c34:	0fc45090 */ 	jal	waypointSetHashThing
/*  f196c38:	00802825 */ 	or	$a1,$a0,$zero
/*  f196c3c:	02002025 */ 	or	$a0,$s0,$zero
/*  f196c40:	02202825 */ 	or	$a1,$s1,$zero
/*  f196c44:	264601e8 */ 	addiu	$a2,$s2,0x1e8
/*  f196c48:	0fc4547b */ 	jal	waypointFindRoute
/*  f196c4c:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f196c50:	ae420208 */ 	sw	$v0,0x208($s2)
/*  f196c54:	00002025 */ 	or	$a0,$zero,$zero
/*  f196c58:	0fc45090 */ 	jal	waypointSetHashThing
/*  f196c5c:	00002825 */ 	or	$a1,$zero,$zero
.L0f196c60:
/*  f196c60:	0fc663bb */ 	jal	aibotTickInventory
/*  f196c64:	02802025 */ 	or	$a0,$s4,$zero
/*  f196c68:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f196c6c:	00009825 */ 	or	$s3,$zero,$zero
/*  f196c70:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f196c74:	02408825 */ 	or	$s1,$s2,$zero
.L0f196c78:
/*  f196c78:	8e22005c */ 	lw	$v0,0x5c($s1)
/*  f196c7c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f196c80:	18400004 */ 	blez	$v0,.L0f196c94
/*  f196c84:	00000000 */ 	nop
/*  f196c88:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f196c8c:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f196c90:	ae39005c */ 	sw	$t9,0x5c($s1)
.L0f196c94:
/*  f196c94:	16770004 */ 	bne	$s3,$s7,.L0f196ca8
/*  f196c98:	8fa90088 */ 	lw	$t1,0x88($sp)
/*  f196c9c:	51200003 */ 	beqzl	$t1,.L0f196cac
/*  f196ca0:	8e4d0044 */ 	lw	$t5,0x44($s2)
/*  f196ca4:	ae37005c */ 	sw	$s7,0x5c($s1)
.L0f196ca8:
/*  f196ca8:	8e4d0044 */ 	lw	$t5,0x44($s2)
.L0f196cac:
/*  f196cac:	15a00207 */ 	bnez	$t5,.L0f1974cc
/*  f196cb0:	00000000 */ 	nop
/*  f196cb4:	8e4a00cc */ 	lw	$t2,0xcc($s2)
/*  f196cb8:	1d400204 */ 	bgtz	$t2,.L0f1974cc
/*  f196cbc:	00000000 */ 	nop
/*  f196cc0:	8e42004c */ 	lw	$v0,0x4c($s2)
/*  f196cc4:	00137040 */ 	sll	$t6,$s3,0x1
/*  f196cc8:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f196ccc:	00026040 */ 	sll	$t4,$v0,0x1
/*  f196cd0:	058300b5 */ 	bgezl	$t4,.L0f196fa8
/*  f196cd4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f196cd8:	8478003c */ 	lh	$t8,0x3c($v1)
/*  f196cdc:	070001fb */ 	bltz	$t8,.L0f1974cc
/*  f196ce0:	00000000 */ 	nop
/*  f196ce4:	846f002c */ 	lh	$t7,0x2c($v1)
/*  f196ce8:	1de001f8 */ 	bgtz	$t7,.L0f1974cc
/*  f196cec:	00000000 */ 	nop
/*  f196cf0:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f196cf4:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f196cf8:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f196cfc:	1721000d */ 	bne	$t9,$at,.L0f196d34
/*  f196d00:	02e02825 */ 	or	$a1,$s7,$zero
/*  f196d04:	0fc26d36 */ 	jal	weaponGetMinClipQty
/*  f196d08:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196d0c:	8e290024 */ 	lw	$t1,0x24($s1)
/*  f196d10:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196d14:	02802025 */ 	or	$a0,$s4,$zero
/*  f196d18:	0122082a */ 	slt	$at,$t1,$v0
/*  f196d1c:	10200005 */ 	beqz	$at,.L0f196d34
/*  f196d20:	02602825 */ 	or	$a1,$s3,$zero
/*  f196d24:	0fc64da7 */ 	jal	func0f19369c
/*  f196d28:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d2c:	100001e7 */ 	b	.L0f1974cc
/*  f196d30:	00000000 */ 	nop
.L0f196d34:
/*  f196d34:	846d003c */ 	lh	$t5,0x3c($v1)
/*  f196d38:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f196d3c:	01aa5823 */ 	subu	$t3,$t5,$t2
/*  f196d40:	a46b003c */ 	sh	$t3,0x3c($v1)
/*  f196d44:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f196d48:	53cc0042 */ 	beql	$s8,$t4,.L0f196e54
/*  f196d4c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d50:	8e4e0128 */ 	lw	$t6,0x128($s2)
/*  f196d54:	51c0003f */ 	beqzl	$t6,.L0f196e54
/*  f196d58:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d5c:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f196d60:	3c0d8008 */ 	lui	$t5,%hi(g_SimDifficulties)
/*  f196d64:	8e58011c */ 	lw	$t8,0x11c($s2)
/*  f196d68:	91f90048 */ 	lbu	$t9,0x48($t7)
/*  f196d6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196d70:	00194940 */ 	sll	$t1,$t9,0x5
/*  f196d74:	01a96821 */ 	addu	$t5,$t5,$t1
/*  f196d78:	91ad7d14 */ 	lbu	$t5,%lo(g_SimDifficulties)($t5)
/*  f196d7c:	030d082a */ 	slt	$at,$t8,$t5
/*  f196d80:	54200034 */ 	bnezl	$at,.L0f196e54
/*  f196d84:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196d88:	0fc64098 */ 	jal	func0f190260
/*  f196d8c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196d90:	14400030 */ 	bnez	$v0,.L0f196e54
/*  f196d94:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196d98:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f196d9c:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f196da0:	02802025 */ 	or	$a0,$s4,$zero
/*  f196da4:	15410014 */ 	bne	$t2,$at,.L0f196df8
/*  f196da8:	24050028 */ 	addiu	$a1,$zero,0x28
/*  f196dac:	02802025 */ 	or	$a0,$s4,$zero
/*  f196db0:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f196db4:	00003025 */ 	or	$a2,$zero,$zero
/*  f196db8:	0fc1241a */ 	jal	chrIsTargetInFov
/*  f196dbc:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196dc0:	1040000b */ 	beqz	$v0,.L0f196df0
/*  f196dc4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196dc8:	02802025 */ 	or	$a0,$s4,$zero
/*  f196dcc:	0fc12472 */ 	jal	chrGetDistanceToTarget
/*  f196dd0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196dd4:	3c014352 */ 	lui	$at,0x4352
/*  f196dd8:	44813000 */ 	mtc1	$at,$f6
/*  f196ddc:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196de0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f196de4:	00000000 */ 	nop
/*  f196de8:	4502001b */ 	bc1fl	.L0f196e58
/*  f196dec:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196df0:
/*  f196df0:	10000018 */ 	b	.L0f196e54
/*  f196df4:	a460003c */ 	sh	$zero,0x3c($v1)
.L0f196df8:
/*  f196df8:	00003025 */ 	or	$a2,$zero,$zero
/*  f196dfc:	0fc1241a */ 	jal	chrIsTargetInFov
/*  f196e00:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196e04:	10400010 */ 	beqz	$v0,.L0f196e48
/*  f196e08:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196e0c:	3c014352 */ 	lui	$at,0x4352
/*  f196e10:	44815000 */ 	mtc1	$at,$f10
/*  f196e14:	3c014316 */ 	lui	$at,0x4316
/*  f196e18:	44819000 */ 	mtc1	$at,$f18
/*  f196e1c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e20:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f196e24:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f196e28:	0fc12472 */ 	jal	chrGetDistanceToTarget
/*  f196e2c:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f196e30:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f196e34:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f196e38:	4600403c */ 	c.lt.s	$f8,$f0
/*  f196e3c:	00000000 */ 	nop
/*  f196e40:	45020005 */ 	bc1fl	.L0f196e58
/*  f196e44:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196e48:
/*  f196e48:	10000002 */ 	b	.L0f196e54
/*  f196e4c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f196e50:	a460003c */ 	sh	$zero,0x3c($v1)
.L0f196e54:
/*  f196e54:	846b003c */ 	lh	$t3,0x3c($v1)
.L0f196e58:
/*  f196e58:	3c014352 */ 	lui	$at,0x4352
/*  f196e5c:	0561019b */ 	bgez	$t3,.L0f1974cc
/*  f196e60:	00000000 */ 	nop
/*  f196e64:	44813000 */ 	mtc1	$at,$f6
/*  f196e68:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e6c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f196e70:	44105000 */ 	mfc1	$s0,$f10
/*  f196e74:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f196e78:	00000000 */ 	nop
/*  f196e7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f196e80:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f196e84:	02003025 */ 	or	$a2,$s0,$zero
/*  f196e88:	0fc0ee91 */ 	jal	chrPunchInflictDamage
/*  f196e8c:	00003825 */ 	or	$a3,$zero,$zero
/*  f196e90:	1660018e */ 	bnez	$s3,.L0f1974cc
/*  f196e94:	00000000 */ 	nop
/*  f196e98:	8e4e0020 */ 	lw	$t6,0x20($s2)
/*  f196e9c:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f196ea0:	2de1001c */ 	sltiu	$at,$t7,0x1c
/*  f196ea4:	10200006 */ 	beqz	$at,.L0f196ec0
/*  f196ea8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f196eac:	3c017f1c */ 	lui	$at,%hi(var7f1b8f58)
/*  f196eb0:	002f0821 */ 	addu	$at,$at,$t7
/*  f196eb4:	8c2f8f58 */ 	lw	$t7,%lo(var7f1b8f58)($at)
/*  f196eb8:	01e00008 */ 	jr	$t7
/*  f196ebc:	00000000 */ 	nop
.L0f196ec0:
/*  f196ec0:	8e9902d4 */ 	lw	$t9,0x2d4($s4)
/*  f196ec4:	24180078 */ 	addiu	$t8,$zero,0x78
/*  f196ec8:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f196ecc:	91220048 */ 	lbu	$v0,0x48($t1)
/*  f196ed0:	14400003 */ 	bnez	$v0,.L0f196ee0
/*  f196ed4:	00000000 */ 	nop
/*  f196ed8:	10000007 */ 	b	.L0f196ef8
/*  f196edc:	a658003c */ 	sh	$t8,0x3c($s2)
.L0f196ee0:
/*  f196ee0:	16e20004 */ 	bne	$s7,$v0,.L0f196ef4
/*  f196ee4:	240a001e */ 	addiu	$t2,$zero,0x1e
/*  f196ee8:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f196eec:	10000002 */ 	b	.L0f196ef8
/*  f196ef0:	a64d003c */ 	sh	$t5,0x3c($s2)
.L0f196ef4:
/*  f196ef4:	a64a003c */ 	sh	$t2,0x3c($s2)
.L0f196ef8:
/*  f196ef8:	0c004b70 */ 	jal	random
/*  f196efc:	00000000 */ 	nop
/*  f196f00:	24010003 */ 	addiu	$at,$zero,0x3
/*  f196f04:	0041001b */ 	divu	$zero,$v0,$at
/*  f196f08:	00005810 */ 	mfhi	$t3
/*  f196f0c:	1560016f */ 	bnez	$t3,.L0f1974cc
/*  f196f10:	00000000 */ 	nop
/*  f196f14:	864c003c */ 	lh	$t4,0x3c($s2)
/*  f196f18:	258effec */ 	addiu	$t6,$t4,-20
/*  f196f1c:	1000016b */ 	b	.L0f1974cc
/*  f196f20:	a64e003e */ 	sh	$t6,0x3e($s2)
/*  f196f24:	8e8f02d4 */ 	lw	$t7,0x2d4($s4)
/*  f196f28:	24090078 */ 	addiu	$t1,$zero,0x78
/*  f196f2c:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f196f30:	93220048 */ 	lbu	$v0,0x48($t9)
/*  f196f34:	14400003 */ 	bnez	$v0,.L0f196f44
/*  f196f38:	00000000 */ 	nop
/*  f196f3c:	10000007 */ 	b	.L0f196f5c
/*  f196f40:	a649003c */ 	sh	$t1,0x3c($s2)
.L0f196f44:
/*  f196f44:	16e20004 */ 	bne	$s7,$v0,.L0f196f58
/*  f196f48:	240d003c */ 	addiu	$t5,$zero,0x3c
/*  f196f4c:	2418005a */ 	addiu	$t8,$zero,0x5a
/*  f196f50:	10000002 */ 	b	.L0f196f5c
/*  f196f54:	a658003c */ 	sh	$t8,0x3c($s2)
.L0f196f58:
/*  f196f58:	a64d003c */ 	sh	$t5,0x3c($s2)
.L0f196f5c:
/*  f196f5c:	8e8a0174 */ 	lw	$t2,0x174($s4)
/*  f196f60:	1140015a */ 	beqz	$t2,.L0f1974cc
/*  f196f64:	00000000 */ 	nop
/*  f196f68:	864b003c */ 	lh	$t3,0x3c($s2)
/*  f196f6c:	256cffd8 */ 	addiu	$t4,$t3,-40
/*  f196f70:	10000156 */ 	b	.L0f1974cc
/*  f196f74:	a64c003e */ 	sh	$t4,0x3e($s2)
/*  f196f78:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f196f7c:	a64e003c */ 	sh	$t6,0x3c($s2)
/*  f196f80:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f196f84:	0fc26d36 */ 	jal	weaponGetMinClipQty
/*  f196f88:	02e02825 */ 	or	$a1,$s7,$zero
/*  f196f8c:	8e4f0024 */ 	lw	$t7,0x24($s2)
/*  f196f90:	01e2c823 */ 	subu	$t9,$t7,$v0
/*  f196f94:	1000014d */ 	b	.L0f1974cc
/*  f196f98:	ae590024 */ 	sw	$t9,0x24($s2)
/*  f196f9c:	1000014b */ 	b	.L0f1974cc
/*  f196fa0:	a640003c */ 	sh	$zero,0x3c($s2)
/*  f196fa4:	8e440020 */ 	lw	$a0,0x20($s2)
.L0f196fa8:
/*  f196fa8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f196fac:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f196fb0:	14810011 */ 	bne	$a0,$at,.L0f196ff8
/*  f196fb4:	00022880 */ 	sll	$a1,$v0,0x2
/*  f196fb8:	07030010 */ 	bgezl	$t8,.L0f196ffc
/*  f196fbc:	000577c2 */ 	srl	$t6,$a1,0x1f
/*  f196fc0:	868d017e */ 	lh	$t5,0x17e($s4)
/*  f196fc4:	53cd000d */ 	beql	$s8,$t5,.L0f196ffc
/*  f196fc8:	000577c2 */ 	srl	$t6,$a1,0x1f
/*  f196fcc:	8e4a0024 */ 	lw	$t2,0x24($s2)
/*  f196fd0:	1940013e */ 	blez	$t2,.L0f1974cc
/*  f196fd4:	00000000 */ 	nop
/*  f196fd8:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f196fdc:	02802025 */ 	or	$a0,$s4,$zero
/*  f196fe0:	0fc66a14 */ 	jal	aibotCreateSlayerRocket
/*  f196fe4:	02802025 */ 	or	$a0,$s4,$zero
/*  f196fe8:	8e4b0024 */ 	lw	$t3,0x24($s2)
/*  f196fec:	256cffff */ 	addiu	$t4,$t3,-1
/*  f196ff0:	10000136 */ 	b	.L0f1974cc
/*  f196ff4:	ae4c0024 */ 	sw	$t4,0x24($s2)
.L0f196ff8:
/*  f196ff8:	000577c2 */ 	srl	$t6,$a1,0x1f
.L0f196ffc:
/*  f196ffc:	0fc668a7 */ 	jal	func0f19a29c
/*  f197000:	01c02825 */ 	or	$a1,$t6,$zero
/*  f197004:	1040005b */ 	beqz	$v0,.L0f197174
/*  f197008:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f19700c:	1660012f */ 	bnez	$s3,.L0f1974cc
/*  f197010:	00000000 */ 	nop
/*  f197014:	8e420034 */ 	lw	$v0,0x34($s2)
/*  f197018:	02402025 */ 	or	$a0,$s2,$zero
/*  f19701c:	58400005 */ 	blezl	$v0,.L0f197034
/*  f197020:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197024:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f197028:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f19702c:	ae590034 */ 	sw	$t9,0x34($s2)
/*  f197030:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
.L0f197034:
/*  f197034:	8d380034 */ 	lw	$t8,0x34($t1)
/*  f197038:	1f000124 */ 	bgtz	$t8,.L0f1974cc
/*  f19703c:	00000000 */ 	nop
/*  f197040:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f197044:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197048:	00003825 */ 	or	$a3,$zero,$zero
/*  f19704c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f197050:	0fc666f9 */ 	jal	aibotGetAmmoQuantityByWeapon
/*  f197054:	000d37c2 */ 	srl	$a2,$t5,0x1f
/*  f197058:	5c400008 */ 	bgtzl	$v0,.L0f19707c
/*  f19705c:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f197060:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197064:	2401000e */ 	addiu	$at,$zero,0xe
/*  f197068:	10810003 */ 	beq	$a0,$at,.L0f197078
/*  f19706c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f197070:	14810116 */ 	bne	$a0,$at,.L0f1974cc
/*  f197074:	00000000 */ 	nop
.L0f197078:
/*  f197078:	868b017e */ 	lh	$t3,0x17e($s4)
.L0f19707c:
/*  f19707c:	00008025 */ 	or	$s0,$zero,$zero
/*  f197080:	13cb0018 */ 	beq	$s8,$t3,.L0f1970e4
/*  f197084:	00000000 */ 	nop
/*  f197088:	8e4c0128 */ 	lw	$t4,0x128($s2)
/*  f19708c:	11800015 */ 	beqz	$t4,.L0f1970e4
/*  f197090:	00000000 */ 	nop
/*  f197094:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f197098:	3c188008 */ 	lui	$t8,%hi(g_SimDifficulties)
/*  f19709c:	8e4e011c */ 	lw	$t6,0x11c($s2)
/*  f1970a0:	91f90048 */ 	lbu	$t9,0x48($t7)
/*  f1970a4:	00194940 */ 	sll	$t1,$t9,0x5
/*  f1970a8:	0309c021 */ 	addu	$t8,$t8,$t1
/*  f1970ac:	93187d14 */ 	lbu	$t8,%lo(g_SimDifficulties)($t8)
/*  f1970b0:	01d8082a */ 	slt	$at,$t6,$t8
/*  f1970b4:	1420000b */ 	bnez	$at,.L0f1970e4
/*  f1970b8:	00000000 */ 	nop
/*  f1970bc:	0fc64098 */ 	jal	func0f190260
/*  f1970c0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970c4:	14400006 */ 	bnez	$v0,.L0f1970e0
/*  f1970c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970cc:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f1970d0:	0fc1241a */ 	jal	chrIsTargetInFov
/*  f1970d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1970d8:	10400002 */ 	beqz	$v0,.L0f1970e4
/*  f1970dc:	00000000 */ 	nop
.L0f1970e0:
/*  f1970e0:	02e08025 */ 	or	$s0,$s7,$zero
.L0f1970e4:
/*  f1970e4:	120000f9 */ 	beqz	$s0,.L0f1974cc
/*  f1970e8:	00000000 */ 	nop
/*  f1970ec:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f1970f0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1970f4:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f1970f8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1970fc:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197100:	00066880 */ 	sll	$t5,$a2,0x2
/*  f197104:	000d37c2 */ 	srl	$a2,$t5,0x1f
/*  f197108:	0fc6675c */ 	jal	aibotTryRemoveAmmoFromReserve
/*  f19710c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f197110:	0fc668df */ 	jal	func0f19a37c
/*  f197114:	02802025 */ 	or	$a0,$s4,$zero
/*  f197118:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19711c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197120:	00055880 */ 	sll	$t3,$a1,0x2
/*  f197124:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f197128:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f19712c:	5040000d */ 	beqzl	$v0,.L0f197164
/*  f197130:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197134:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f197138:	02802025 */ 	or	$a0,$s4,$zero
/*  f19713c:	000fcb40 */ 	sll	$t9,$t7,0xd
/*  f197140:	07230008 */ 	bgezl	$t9,.L0f197164
/*  f197144:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197148:	0fc65f65 */ 	jal	aibotRemoveInvItem
/*  f19714c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f197150:	02802025 */ 	or	$a0,$s4,$zero
/*  f197154:	02e02825 */ 	or	$a1,$s7,$zero
/*  f197158:	0fc6652c */ 	jal	aibotSwitchToWeapon
/*  f19715c:	00003025 */ 	or	$a2,$zero,$zero
/*  f197160:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
.L0f197164:
/*  f197164:	0fc668b7 */ 	jal	aibotGetProjectileThrowInterval
/*  f197168:	8d240020 */ 	lw	$a0,0x20($t1)
/*  f19716c:	100000d7 */ 	b	.L0f1974cc
/*  f197170:	ae420034 */ 	sw	$v0,0x34($s2)
.L0f197174:
/*  f197174:	028ec021 */ 	addu	$t8,$s4,$t6
/*  f197178:	8f0d0170 */ 	lw	$t5,0x170($t8)
/*  f19717c:	02537821 */ 	addu	$t7,$s2,$s3
/*  f197180:	51a000ce */ 	beqzl	$t5,.L0f1974bc
/*  f197184:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f197188:	8e2a0024 */ 	lw	$t2,0x24($s1)
/*  f19718c:	594000cb */ 	blezl	$t2,.L0f1974bc
/*  f197190:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f197194:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197198:	00008025 */ 	or	$s0,$zero,$zero
/*  f19719c:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1971a0:	00055880 */ 	sll	$t3,$a1,0x2
/*  f1971a4:	0fc2c7ba */ 	jal	weaponGetNumTicksPerShot
/*  f1971a8:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f1971ac:	5c400030 */ 	bgtzl	$v0,.L0f197270
/*  f1971b0:	02e08025 */ 	or	$s0,$s7,$zero
/*  f1971b4:	8e4f0020 */ 	lw	$t7,0x20($s2)
/*  f1971b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1971bc:	55e10027 */ 	bnel	$t7,$at,.L0f19725c
/*  f1971c0:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f1971c4:	8e59004c */ 	lw	$t9,0x4c($s2)
/*  f1971c8:	00194880 */ 	sll	$t1,$t9,0x2
/*  f1971cc:	000977c2 */ 	srl	$t6,$t1,0x1f
/*  f1971d0:	56ee0022 */ 	bnel	$s7,$t6,.L0f19725c
/*  f1971d4:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f1971d8:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f1971dc:	2b010002 */ 	slti	$at,$t8,0x2
/*  f1971e0:	1420001d */ 	bnez	$at,.L0f197258
/*  f1971e4:	3c017f1c */ 	lui	$at,%hi(var7f1b8fc8)
/*  f1971e8:	c4288fc8 */ 	lwc1	$f8,%lo(var7f1b8fc8)($at)
/*  f1971ec:	c6c4004c */ 	lwc1	$f4,0x4c($s6)
/*  f1971f0:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1971f4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1971f8:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f1971fc:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f197200:	44039000 */ 	mfc1	$v1,$f18
/*  f197204:	44819000 */ 	mtc1	$at,$f18
/*  f197208:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f19720c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f197210:	e62a00e4 */ 	swc1	$f10,0xe4($s1)
/*  f197214:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f197218:	4600903c */ 	c.lt.s	$f18,$f0
/*  f19721c:	00000000 */ 	nop
/*  f197220:	45020006 */ 	bc1fl	.L0f19723c
/*  f197224:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f197228:	44812000 */ 	mtc1	$at,$f4
/*  f19722c:	00000000 */ 	nop
/*  f197230:	e62400e4 */ 	swc1	$f4,0xe4($s1)
/*  f197234:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f197238:	4600020d */ 	trunc.w.s	$f8,$f0
.L0f19723c:
/*  f19723c:	44024000 */ 	mfc1	$v0,$f8
/*  f197240:	00000000 */ 	nop
/*  f197244:	50430005 */ 	beql	$v0,$v1,.L0f19725c
/*  f197248:	8e2f005c */ 	lw	$t7,0x5c($s1)
/*  f19724c:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f197250:	256cffff */ 	addiu	$t4,$t3,-1
/*  f197254:	ae2c0024 */ 	sw	$t4,0x24($s1)
.L0f197258:
/*  f197258:	8e2f005c */ 	lw	$t7,0x5c($s1)
.L0f19725c:
/*  f19725c:	1de00004 */ 	bgtz	$t7,.L0f197270
/*  f197260:	00000000 */ 	nop
/*  f197264:	10000002 */ 	b	.L0f197270
/*  f197268:	02e08025 */ 	or	$s0,$s7,$zero
/*  f19726c:	02e08025 */ 	or	$s0,$s7,$zero
.L0f197270:
/*  f197270:	52000052 */ 	beqzl	$s0,.L0f1973bc
/*  f197274:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197278:	8e3900c4 */ 	lw	$t9,0xc4($s1)
/*  f19727c:	02534821 */ 	addu	$t1,$s2,$s3
/*  f197280:	17200004 */ 	bnez	$t9,.L0f197294
/*  f197284:	00000000 */ 	nop
/*  f197288:	912e004d */ 	lbu	$t6,0x4d($t1)
/*  f19728c:	59c00004 */ 	blezl	$t6,.L0f1972a0
/*  f197290:	8698017e */ 	lh	$t8,0x17e($s4)
.L0f197294:
/*  f197294:	1000003a */ 	b	.L0f197380
/*  f197298:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f19729c:	8698017e */ 	lh	$t8,0x17e($s4)
.L0f1972a0:
/*  f1972a0:	13d80037 */ 	beq	$s8,$t8,.L0f197380
/*  f1972a4:	00000000 */ 	nop
/*  f1972a8:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f1972ac:	11a00034 */ 	beqz	$t5,.L0f197380
/*  f1972b0:	00000000 */ 	nop
/*  f1972b4:	8e4b0004 */ 	lw	$t3,0x4($s2)
/*  f1972b8:	3c198008 */ 	lui	$t9,%hi(g_SimDifficulties)
/*  f1972bc:	8e4a011c */ 	lw	$t2,0x11c($s2)
/*  f1972c0:	916c0048 */ 	lbu	$t4,0x48($t3)
/*  f1972c4:	000c7940 */ 	sll	$t7,$t4,0x5
/*  f1972c8:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f1972cc:	93397d14 */ 	lbu	$t9,%lo(g_SimDifficulties)($t9)
/*  f1972d0:	0159082a */ 	slt	$at,$t2,$t9
/*  f1972d4:	1420002a */ 	bnez	$at,.L0f197380
/*  f1972d8:	00000000 */ 	nop
/*  f1972dc:	0fc64098 */ 	jal	func0f190260
/*  f1972e0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1972e4:	14400006 */ 	bnez	$v0,.L0f197300
/*  f1972e8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1972ec:	2405002d */ 	addiu	$a1,$zero,0x2d
/*  f1972f0:	0fc1241a */ 	jal	chrIsTargetInFov
/*  f1972f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f1972f8:	10400021 */ 	beqz	$v0,.L0f197380
/*  f1972fc:	00000000 */ 	nop
.L0f197300:
/*  f197300:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f197304:	02802025 */ 	or	$a0,$s4,$zero
/*  f197308:	0fc0e6a5 */ 	jal	chrIsDead
/*  f19730c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197310:	1440001b */ 	bnez	$v0,.L0f197380
/*  f197314:	00000000 */ 	nop
/*  f197318:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f19731c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f197320:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f197324:	54810009 */ 	bnel	$a0,$at,.L0f19734c
/*  f197328:	24010014 */ 	addiu	$at,$zero,0x14
/*  f19732c:	8e49004c */ 	lw	$t1,0x4c($s2)
/*  f197330:	00097080 */ 	sll	$t6,$t1,0x2
/*  f197334:	000ec7c2 */ 	srl	$t8,$t6,0x1f
/*  f197338:	56f80004 */ 	bnel	$s7,$t8,.L0f19734c
/*  f19733c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f197340:	1000000f */ 	b	.L0f197380
/*  f197344:	ae3700c4 */ 	sw	$s7,0xc4($s1)
/*  f197348:	24010014 */ 	addiu	$at,$zero,0x14
.L0f19734c:
/*  f19734c:	1481000c */ 	bne	$a0,$at,.L0f197380
/*  f197350:	00136840 */ 	sll	$t5,$s3,0x1
/*  f197354:	024d1821 */ 	addu	$v1,$s2,$t5
/*  f197358:	846b00e0 */ 	lh	$t3,0xe0($v1)
/*  f19735c:	8ecc0038 */ 	lw	$t4,0x38($s6)
/*  f197360:	2419005a */ 	addiu	$t9,$zero,0x5a
/*  f197364:	016c7821 */ 	addu	$t7,$t3,$t4
/*  f197368:	a46f00e0 */ 	sh	$t7,0xe0($v1)
/*  f19736c:	846a00e0 */ 	lh	$t2,0xe0($v1)
/*  f197370:	2941005b */ 	slti	$at,$t2,0x5b
/*  f197374:	14200002 */ 	bnez	$at,.L0f197380
/*  f197378:	00000000 */ 	nop
/*  f19737c:	a47900e0 */ 	sh	$t9,0xe0($v1)
.L0f197380:
/*  f197380:	16a0000d */ 	bnez	$s5,.L0f1973b8
/*  f197384:	00134840 */ 	sll	$t1,$s3,0x1
/*  f197388:	02491821 */ 	addu	$v1,$s2,$t1
/*  f19738c:	846200e0 */ 	lh	$v0,0xe0($v1)
/*  f197390:	5840000a */ 	blezl	$v0,.L0f1973bc
/*  f197394:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f197398:	8ece0038 */ 	lw	$t6,0x38($s6)
/*  f19739c:	02e0a825 */ 	or	$s5,$s7,$zero
/*  f1973a0:	004ec023 */ 	subu	$t8,$v0,$t6
/*  f1973a4:	a47800e0 */ 	sh	$t8,0xe0($v1)
/*  f1973a8:	846d00e0 */ 	lh	$t5,0xe0($v1)
/*  f1973ac:	05a30003 */ 	bgezl	$t5,.L0f1973bc
/*  f1973b0:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973b4:	a46000e0 */ 	sh	$zero,0xe0($v1)
.L0f1973b8:
/*  f1973b8:	8e45004c */ 	lw	$a1,0x4c($s2)
.L0f1973bc:
/*  f1973bc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973c0:	00055880 */ 	sll	$t3,$a1,0x2
/*  f1973c4:	0fc2c7ba */ 	jal	weaponGetNumTicksPerShot
/*  f1973c8:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f1973cc:	1c40003f */ 	bgtz	$v0,.L0f1974cc
/*  f1973d0:	00000000 */ 	nop
/*  f1973d4:	12a0003d */ 	beqz	$s5,.L0f1974cc
/*  f1973d8:	00000000 */ 	nop
/*  f1973dc:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973e0:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973e4:	00057880 */ 	sll	$t7,$a1,0x2
/*  f1973e8:	0fc66983 */ 	jal	func0f19a60c
/*  f1973ec:	000f2fc2 */ 	srl	$a1,$t7,0x1f
/*  f1973f0:	ae22005c */ 	sw	$v0,0x5c($s1)
/*  f1973f4:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1973f8:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1973fc:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f197400:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f197404:	00192fc2 */ 	srl	$a1,$t9,0x1f
/*  f197408:	10400030 */ 	beqz	$v0,.L0f1974cc
/*  f19740c:	00000000 */ 	nop
/*  f197410:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f197414:	306e1002 */ 	andi	$t6,$v1,0x1002
/*  f197418:	11c0002c */ 	beqz	$t6,.L0f1974cc
/*  f19741c:	00000000 */ 	nop
/*  f197420:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f197424:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f197428:	2b010002 */ 	slti	$at,$t8,0x2
/*  f19742c:	14200027 */ 	bnez	$at,.L0f1974cc
/*  f197430:	00000000 */ 	nop
/*  f197434:	11a00003 */ 	beqz	$t5,.L0f197444
/*  f197438:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f19743c:	10000001 */ 	b	.L0f197444
/*  f197440:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f197444:
/*  f197444:	8e8b02d4 */ 	lw	$t3,0x2d4($s4)
/*  f197448:	01731021 */ 	addu	$v0,$t3,$s3
/*  f19744c:	904c004d */ 	lbu	$t4,0x4d($v0)
/*  f197450:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f197454:	a04f004d */ 	sb	$t7,0x4d($v0)
/*  f197458:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f19745c:	01531021 */ 	addu	$v0,$t2,$s3
/*  f197460:	9059004d */ 	lbu	$t9,0x4d($v0)
/*  f197464:	0324001a */ 	div	$zero,$t9,$a0
/*  f197468:	00004810 */ 	mfhi	$t1
/*  f19746c:	a049004d */ 	sb	$t1,0x4d($v0)
/*  f197470:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f197474:	14800002 */ 	bnez	$a0,.L0f197480
/*  f197478:	00000000 */ 	nop
/*  f19747c:	0007000d */ 	break	0x7
.L0f197480:
/*  f197480:	2401ffff */ 	addiu	$at,$zero,-1
/*  f197484:	14810004 */ 	bne	$a0,$at,.L0f197498
/*  f197488:	3c018000 */ 	lui	$at,0x8000
/*  f19748c:	17210002 */ 	bne	$t9,$at,.L0f197498
/*  f197490:	00000000 */ 	nop
/*  f197494:	0006000d */ 	break	0x6
.L0f197498:
/*  f197498:	00737021 */ 	addu	$t6,$v1,$s3
/*  f19749c:	91d8004d */ 	lbu	$t8,0x4d($t6)
/*  f1974a0:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f1974a4:	13000009 */ 	beqz	$t8,.L0f1974cc
/*  f1974a8:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f1974ac:	006b6021 */ 	addu	$t4,$v1,$t3
/*  f1974b0:	10000006 */ 	b	.L0f1974cc
/*  f1974b4:	ad8d005c */ 	sw	$t5,0x5c($t4)
/*  f1974b8:	ae2000c4 */ 	sw	$zero,0xc4($s1)
.L0f1974bc:
/*  f1974bc:	00135040 */ 	sll	$t2,$s3,0x1
/*  f1974c0:	a1e0004d */ 	sb	$zero,0x4d($t7)
/*  f1974c4:	024ac821 */ 	addu	$t9,$s2,$t2
/*  f1974c8:	a72000e0 */ 	sh	$zero,0xe0($t9)
.L0f1974cc:
/*  f1974cc:	52a00007 */ 	beqzl	$s5,.L0f1974ec
/*  f1974d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974d4:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f1974d8:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974dc:	56600003 */ 	bnezl	$s3,.L0f1974ec
/*  f1974e0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1974e4:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f1974e8:	02802025 */ 	or	$a0,$s4,$zero
.L0f1974ec:
/*  f1974ec:	02602825 */ 	or	$a1,$s3,$zero
/*  f1974f0:	0fc0fe62 */ 	jal	func0f03f988
/*  f1974f4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1974f8:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f1974fc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f197500:	24010002 */ 	addiu	$at,$zero,0x2
/*  f197504:	252e0004 */ 	addiu	$t6,$t1,0x4
/*  f197508:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f19750c:	1661fdda */ 	bne	$s3,$at,.L0f196c78
/*  f197510:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f197514:
/*  f197514:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f197518:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f19751c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f197520:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f197524:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f197528:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f19752c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f197530:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f197534:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f197538:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f19753c:	03e00008 */ 	jr	$ra
/*  f197540:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#endif

void func0f197544(struct chrdata *chr)
{
	bool pass = false;
	struct aibot *aibot = chr->aibot;

	if (chr->myaction == MA_AIBOTGETITEM) {
		if (chr->act_gopos.waypoints[chr->act_gopos.curindex] == 0) {
			struct prop *prop = aibot->fetchprop;

#if VERSION >= VERSION_PAL_FINAL
			// pal-final adds a check for prop->obj
			if (prop && prop->obj && !prop->parent && prop->timetoregen == 0) {
				if (prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ) {
					prop->obj->flags3 |= OBJFLAG3_00004000;
				}
			}
#else
			if (prop && !prop->parent && prop->timetoregen == 0) {
				if (prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ) {
					prop->obj->flags3 |= OBJFLAG3_00004000;
				}
			}
#endif
		}

		aibot->unk0d8 = 1;
		pass = true;
	}

	if (!pass) {
		chrGoToPos(chr, &chr->act_gopos.endpos, chr->act_gopos.endrooms, chr->act_gopos.flags);
	}
}
