#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/game_0d4690.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_121e0.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
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
const u32 var7f1b7408[] = {0x00000000};
const u32 var7f1b740c[] = {0x00000000};
const u32 var7f1b7410[] = {0x7f7fffff};
const u32 var7f1b7414[] = {0x7f7fffff};
const u32 var7f1b7418[] = {0x00000000};
const u32 var7f1b741c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f1531a0
/*  f1531a0:	03e00008 */ 	jr	$ra
/*  f1531a4:	00000000 */ 	nop
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

GLOBAL_ASM(
glabel func0f1531dc
/*  f1531dc:	10800005 */ 	beqz	$a0,.L0f1531f4
/*  f1531e0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1531e4:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f1531e8:	3c018008 */ 	lui	$at,%hi(var8007fad0)
/*  f1531ec:	03e00008 */ 	jr	$ra
/*  f1531f0:	ac2efad0 */ 	sw	$t6,%lo(var8007fad0)($at)
.L0f1531f4:
/*  f1531f4:	3c018008 */ 	lui	$at,%hi(var8007fad0)
/*  f1531f8:	ac2ffad0 */ 	sw	$t7,%lo(var8007fad0)($at)
/*  f1531fc:	03e00008 */ 	jr	$ra
/*  f153200:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153204
/*  f153204:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f153208:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f15320c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153210:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f153214:	00a42023 */ 	subu	$a0,$a1,$a0
/*  f153218:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f15321c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f153220:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f153224:	0c0048f2 */ 	jal	malloc
/*  f153228:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15322c:	244802a4 */ 	addiu	$t0,$v0,0x2a4
/*  f153230:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f153234:	00402025 */ 	or	$a0,$v0,$zero
/*  f153238:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f15323c:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f153240:	0c003504 */ 	jal	func0000d410
/*  f153244:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f153248:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f15324c:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f153250:	00001825 */ 	or	$v1,$zero,$zero
/*  f153254:	01001025 */ 	or	$v0,$t0,$zero
.L0f153258:
/*  f153258:	8c580008 */ 	lw	$t8,0x8($v0)
/*  f15325c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f153260:	2861005e */ 	slti	$at,$v1,0x5e
/*  f153264:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f153268:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f15326c:	1420fffa */ 	bnez	$at,.L0f153258
/*  f153270:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f153274:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f153278:	00002825 */ 	or	$a1,$zero,$zero
/*  f15327c:	00002025 */ 	or	$a0,$zero,$zero
/*  f153280:	11200012 */ 	beqz	$t1,.L0f1532cc
/*  f153284:	01001025 */ 	or	$v0,$t0,$zero
.L0f153288:
/*  f153288:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f15328c:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f153290:	00a3082a */ 	slt	$at,$a1,$v1
/*  f153294:	50200003 */ 	beqzl	$at,.L0f1532a4
/*  f153298:	28810468 */ 	slti	$at,$a0,0x468
/*  f15329c:	00602825 */ 	or	$a1,$v1,$zero
/*  f1532a0:	28810468 */ 	slti	$at,$a0,0x468
.L0f1532a4:
/*  f1532a4:	1420fff8 */ 	bnez	$at,.L0f153288
/*  f1532a8:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f1532ac:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f1532b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1532b4:	01001025 */ 	or	$v0,$t0,$zero
/*  f1532b8:	2404005e */ 	addiu	$a0,$zero,0x5e
.L0f1532bc:
/*  f1532bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1532c0:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f1532c4:	1464fffd */ 	bne	$v1,$a0,.L0f1532bc
/*  f1532c8:	a045fff7 */ 	sb	$a1,-0x9($v0)
.L0f1532cc:
/*  f1532cc:	8faa0038 */ 	lw	$t2,0x38($sp)
/*  f1532d0:	ad470000 */ 	sw	$a3,0x0($t2)
/*  f1532d4:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f1532d8:	ad680000 */ 	sw	$t0,0x0($t3)
/*  f1532dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1532e0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1532e4:	03e00008 */ 	jr	$ra
/*  f1532e8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1532ec
/*  f1532ec:	3c018008 */ 	lui	$at,%hi(var8007faec)
/*  f1532f0:	3c068008 */ 	lui	$a2,%hi(var8007faf4)
/*  f1532f4:	ac20faec */ 	sw	$zero,%lo(var8007faec)($at)
/*  f1532f8:	24c6faf4 */ 	addiu	$a2,$a2,%lo(var8007faf4)
/*  f1532fc:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f153300:	3c018008 */ 	lui	$at,%hi(var8007fafc)
/*  f153304:	ac20fafc */ 	sw	$zero,%lo(var8007fafc)($at)
/*  f153308:	3c018008 */ 	lui	$at,%hi(var8007fb04)
/*  f15330c:	ac20fb04 */ 	sw	$zero,%lo(var8007fb04)($at)
/*  f153310:	3c018008 */ 	lui	$at,%hi(var8007fb0c)
/*  f153314:	ac20fb0c */ 	sw	$zero,%lo(var8007fb0c)($at)
/*  f153318:	3c018008 */ 	lui	$at,%hi(var8007fb14)
/*  f15331c:	ac20fb14 */ 	sw	$zero,%lo(var8007fb14)($at)
/*  f153320:	3c018008 */ 	lui	$at,%hi(var8007fb1c)
/*  f153324:	ac20fb1c */ 	sw	$zero,%lo(var8007fb1c)($at)
/*  f153328:	3c018008 */ 	lui	$at,%hi(var8007fb24)
/*  f15332c:	ac20fb24 */ 	sw	$zero,%lo(var8007fb24)($at)
/*  f153330:	3c018008 */ 	lui	$at,%hi(var8007fb2c)
/*  f153334:	ac20fb2c */ 	sw	$zero,%lo(var8007fb2c)($at)
/*  f153338:	3c018008 */ 	lui	$at,%hi(var8007fb34)
/*  f15333c:	ac20fb34 */ 	sw	$zero,%lo(var8007fb34)($at)
/*  f153340:	3c018008 */ 	lui	$at,%hi(var8007faf0)
/*  f153344:	3c078008 */ 	lui	$a3,%hi(var8007faf8)
/*  f153348:	ac20faf0 */ 	sw	$zero,%lo(var8007faf0)($at)
/*  f15334c:	24e7faf8 */ 	addiu	$a3,$a3,%lo(var8007faf8)
/*  f153350:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f153354:	3c018008 */ 	lui	$at,%hi(var8007fb00)
/*  f153358:	ac20fb00 */ 	sw	$zero,%lo(var8007fb00)($at)
/*  f15335c:	3c018008 */ 	lui	$at,%hi(var8007fb08)
/*  f153360:	ac20fb08 */ 	sw	$zero,%lo(var8007fb08)($at)
/*  f153364:	3c018008 */ 	lui	$at,%hi(var8007fb10)
/*  f153368:	ac20fb10 */ 	sw	$zero,%lo(var8007fb10)($at)
/*  f15336c:	3c018008 */ 	lui	$at,%hi(var8007fb18)
/*  f153370:	ac20fb18 */ 	sw	$zero,%lo(var8007fb18)($at)
/*  f153374:	3c018008 */ 	lui	$at,%hi(var8007fb20)
/*  f153378:	ac20fb20 */ 	sw	$zero,%lo(var8007fb20)($at)
/*  f15337c:	3c018008 */ 	lui	$at,%hi(var8007fb28)
/*  f153380:	ac20fb28 */ 	sw	$zero,%lo(var8007fb28)($at)
/*  f153384:	3c018008 */ 	lui	$at,%hi(var8007fb30)
/*  f153388:	ac20fb30 */ 	sw	$zero,%lo(var8007fb30)($at)
/*  f15338c:	3c018008 */ 	lui	$at,%hi(var8007fb38)
/*  f153390:	ac20fb38 */ 	sw	$zero,%lo(var8007fb38)($at)
/*  f153394:	3c018008 */ 	lui	$at,%hi(var8007fac4)
/*  f153398:	ac20fac4 */ 	sw	$zero,%lo(var8007fac4)($at)
/*  f15339c:	3c018008 */ 	lui	$at,%hi(var8007fac8)
/*  f1533a0:	ac20fac8 */ 	sw	$zero,%lo(var8007fac8)($at)
/*  f1533a4:	3c018008 */ 	lui	$at,%hi(var8007facc)
/*  f1533a8:	ac20facc */ 	sw	$zero,%lo(var8007facc)($at)
/*  f1533ac:	3c018008 */ 	lui	$at,%hi(var8007fad4)
/*  f1533b0:	240effff */ 	addiu	$t6,$zero,-1
/*  f1533b4:	ac2efad4 */ 	sw	$t6,%lo(var8007fad4)($at)
/*  f1533b8:	3c018008 */ 	lui	$at,%hi(var8007fad8)
/*  f1533bc:	ac20fad8 */ 	sw	$zero,%lo(var8007fad8)($at)
/*  f1533c0:	3c018008 */ 	lui	$at,%hi(var8007fadc)
/*  f1533c4:	ac20fadc */ 	sw	$zero,%lo(var8007fadc)($at)
/*  f1533c8:	3c018008 */ 	lui	$at,%hi(var8007fae0)
/*  f1533cc:	ac20fae0 */ 	sw	$zero,%lo(var8007fae0)($at)
/*  f1533d0:	3c018008 */ 	lui	$at,%hi(var8007fae4)
/*  f1533d4:	ac20fae4 */ 	sw	$zero,%lo(var8007fae4)($at)
/*  f1533d8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x4b4)
/*  f1533dc:	8c42a474 */ 	lw	$v0,%lo(g_Vars+0x4b4)($v0)
/*  f1533e0:	3c018008 */ 	lui	$at,%hi(var8007fae8)
/*  f1533e4:	ac20fae8 */ 	sw	$zero,%lo(var8007fae8)($at)
/*  f1533e8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1533ec:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f1533f0:	14410021 */ 	bne	$v0,$at,.L0f153478
/*  f1533f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1533f8:	3c040080 */ 	lui	$a0,0x80
/*  f1533fc:	3c050080 */ 	lui	$a1,0x80
/*  f153400:	3c068008 */ 	lui	$a2,%hi(var8007fb0c)
/*  f153404:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f153408:	24e7fb10 */ 	addiu	$a3,$a3,%lo(var8007fb10)
/*  f15340c:	24c6fb0c */ 	addiu	$a2,$a2,%lo(var8007fb0c)
/*  f153410:	24a5bfb0 */ 	addiu	$a1,$a1,-16464
/*  f153414:	24849d30 */ 	addiu	$a0,$a0,-25296
/*  f153418:	0fc54c81 */ 	jal	func0f153204
/*  f15341c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153420:	3c040080 */ 	lui	$a0,0x80
/*  f153424:	3c050080 */ 	lui	$a1,0x80
/*  f153428:	3c068008 */ 	lui	$a2,%hi(var8007fb14)
/*  f15342c:	3c078008 */ 	lui	$a3,%hi(var8007fb18)
/*  f153430:	24e7fb18 */ 	addiu	$a3,$a3,%lo(var8007fb18)
/*  f153434:	24c6fb14 */ 	addiu	$a2,$a2,%lo(var8007fb14)
/*  f153438:	24a508e0 */ 	addiu	$a1,$a1,0x8e0
/*  f15343c:	2484dd80 */ 	addiu	$a0,$a0,-8832
/*  f153440:	0fc54c81 */ 	jal	func0f153204
/*  f153444:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153448:	3c040080 */ 	lui	$a0,0x80
/*  f15344c:	3c050080 */ 	lui	$a1,0x80
/*  f153450:	3c068008 */ 	lui	$a2,%hi(var8007fb1c)
/*  f153454:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f153458:	24e7fb20 */ 	addiu	$a3,$a3,%lo(var8007fb20)
/*  f15345c:	24c6fb1c */ 	addiu	$a2,$a2,%lo(var8007fb1c)
/*  f153460:	24a53da0 */ 	addiu	$a1,$a1,0x3da0
/*  f153464:	248408e0 */ 	addiu	$a0,$a0,0x8e0
/*  f153468:	0fc54c81 */ 	jal	func0f153204
/*  f15346c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153470:	1000006a */ 	b	.L0f15361c
/*  f153474:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f153478:
/*  f153478:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f15347c:	1441002b */ 	bne	$v0,$at,.L0f15352c
/*  f153480:	3c04007f */ 	lui	$a0,0x7f
/*  f153484:	3c040080 */ 	lui	$a0,0x80
/*  f153488:	3c050080 */ 	lui	$a1,0x80
/*  f15348c:	3c068008 */ 	lui	$a2,%hi(var8007fb04)
/*  f153490:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f153494:	24e7fb08 */ 	addiu	$a3,$a3,%lo(var8007fb08)
/*  f153498:	24c6fb04 */ 	addiu	$a2,$a2,%lo(var8007fb04)
/*  f15349c:	24a5dd80 */ 	addiu	$a1,$a1,-8832
/*  f1534a0:	2484bfb0 */ 	addiu	$a0,$a0,-16464
/*  f1534a4:	0fc54c81 */ 	jal	func0f153204
/*  f1534a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1534ac:	3c040080 */ 	lui	$a0,0x80
/*  f1534b0:	3c050080 */ 	lui	$a1,0x80
/*  f1534b4:	3c068008 */ 	lui	$a2,%hi(var8007fb0c)
/*  f1534b8:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f1534bc:	24e7fb10 */ 	addiu	$a3,$a3,%lo(var8007fb10)
/*  f1534c0:	24c6fb0c */ 	addiu	$a2,$a2,%lo(var8007fb0c)
/*  f1534c4:	24a5bfb0 */ 	addiu	$a1,$a1,-16464
/*  f1534c8:	24849d30 */ 	addiu	$a0,$a0,-25296
/*  f1534cc:	0fc54c81 */ 	jal	func0f153204
/*  f1534d0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1534d4:	3c040080 */ 	lui	$a0,0x80
/*  f1534d8:	3c050080 */ 	lui	$a1,0x80
/*  f1534dc:	3c068008 */ 	lui	$a2,%hi(var8007fb14)
/*  f1534e0:	3c078008 */ 	lui	$a3,%hi(var8007fb18)
/*  f1534e4:	24e7fb18 */ 	addiu	$a3,$a3,%lo(var8007fb18)
/*  f1534e8:	24c6fb14 */ 	addiu	$a2,$a2,%lo(var8007fb14)
/*  f1534ec:	24a508e0 */ 	addiu	$a1,$a1,0x8e0
/*  f1534f0:	2484dd80 */ 	addiu	$a0,$a0,-8832
/*  f1534f4:	0fc54c81 */ 	jal	func0f153204
/*  f1534f8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1534fc:	3c040080 */ 	lui	$a0,0x80
/*  f153500:	3c050080 */ 	lui	$a1,0x80
/*  f153504:	3c068008 */ 	lui	$a2,%hi(var8007fb1c)
/*  f153508:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f15350c:	24e7fb20 */ 	addiu	$a3,$a3,%lo(var8007fb20)
/*  f153510:	24c6fb1c */ 	addiu	$a2,$a2,%lo(var8007fb1c)
/*  f153514:	24a53da0 */ 	addiu	$a1,$a1,0x3da0
/*  f153518:	248408e0 */ 	addiu	$a0,$a0,0x8e0
/*  f15351c:	0fc54c81 */ 	jal	func0f153204
/*  f153520:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153524:	1000003d */ 	b	.L0f15361c
/*  f153528:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f15352c:
/*  f15352c:	3c050080 */ 	lui	$a1,0x80
/*  f153530:	24a58b20 */ 	addiu	$a1,$a1,-29920
/*  f153534:	24847860 */ 	addiu	$a0,$a0,0x7860
/*  f153538:	0fc54c81 */ 	jal	func0f153204
/*  f15353c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153540:	3c040080 */ 	lui	$a0,0x80
/*  f153544:	3c050080 */ 	lui	$a1,0x80
/*  f153548:	3c068008 */ 	lui	$a2,%hi(var8007fafc)
/*  f15354c:	3c078008 */ 	lui	$a3,%hi(var8007fb00)
/*  f153550:	24e7fb00 */ 	addiu	$a3,$a3,%lo(var8007fb00)
/*  f153554:	24c6fafc */ 	addiu	$a2,$a2,%lo(var8007fafc)
/*  f153558:	24a59d30 */ 	addiu	$a1,$a1,-25296
/*  f15355c:	24848b20 */ 	addiu	$a0,$a0,-29920
/*  f153560:	0fc54c81 */ 	jal	func0f153204
/*  f153564:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153568:	3c040080 */ 	lui	$a0,0x80
/*  f15356c:	3c050080 */ 	lui	$a1,0x80
/*  f153570:	3c068008 */ 	lui	$a2,%hi(var8007fb04)
/*  f153574:	3c078008 */ 	lui	$a3,%hi(var8007fb08)
/*  f153578:	24e7fb08 */ 	addiu	$a3,$a3,%lo(var8007fb08)
/*  f15357c:	24c6fb04 */ 	addiu	$a2,$a2,%lo(var8007fb04)
/*  f153580:	24a5dd80 */ 	addiu	$a1,$a1,-8832
/*  f153584:	2484bfb0 */ 	addiu	$a0,$a0,-16464
/*  f153588:	0fc54c81 */ 	jal	func0f153204
/*  f15358c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f153590:	3c040080 */ 	lui	$a0,0x80
/*  f153594:	3c050080 */ 	lui	$a1,0x80
/*  f153598:	3c068008 */ 	lui	$a2,%hi(var8007fb0c)
/*  f15359c:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f1535a0:	24e7fb10 */ 	addiu	$a3,$a3,%lo(var8007fb10)
/*  f1535a4:	24c6fb0c */ 	addiu	$a2,$a2,%lo(var8007fb0c)
/*  f1535a8:	24a5bfb0 */ 	addiu	$a1,$a1,-16464
/*  f1535ac:	24849d30 */ 	addiu	$a0,$a0,-25296
/*  f1535b0:	0fc54c81 */ 	jal	func0f153204
/*  f1535b4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1535b8:	3c040080 */ 	lui	$a0,0x80
/*  f1535bc:	3c050080 */ 	lui	$a1,0x80
/*  f1535c0:	3c068008 */ 	lui	$a2,%hi(var8007fb14)
/*  f1535c4:	3c078008 */ 	lui	$a3,%hi(var8007fb18)
/*  f1535c8:	24e7fb18 */ 	addiu	$a3,$a3,%lo(var8007fb18)
/*  f1535cc:	24c6fb14 */ 	addiu	$a2,$a2,%lo(var8007fb14)
/*  f1535d0:	24a508e0 */ 	addiu	$a1,$a1,0x8e0
/*  f1535d4:	2484dd80 */ 	addiu	$a0,$a0,-8832
/*  f1535d8:	0fc54c81 */ 	jal	func0f153204
/*  f1535dc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1535e0:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x4b4)
/*  f1535e4:	8defa474 */ 	lw	$t7,%lo(g_Vars+0x4b4)($t7)
/*  f1535e8:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1535ec:	3c040080 */ 	lui	$a0,0x80
/*  f1535f0:	15e10009 */ 	bne	$t7,$at,.L0f153618
/*  f1535f4:	248408e0 */ 	addiu	$a0,$a0,0x8e0
/*  f1535f8:	3c050080 */ 	lui	$a1,0x80
/*  f1535fc:	3c068008 */ 	lui	$a2,%hi(var8007fb1c)
/*  f153600:	3c078008 */ 	lui	$a3,%hi(var8007fb20)
/*  f153604:	24e7fb20 */ 	addiu	$a3,$a3,%lo(var8007fb20)
/*  f153608:	24c6fb1c */ 	addiu	$a2,$a2,%lo(var8007fb1c)
/*  f15360c:	24a53da0 */ 	addiu	$a1,$a1,0x3da0
/*  f153610:	0fc54c81 */ 	jal	func0f153204
/*  f153614:	afa00010 */ 	sw	$zero,0x10($sp)
.L0f153618:
/*  f153618:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f15361c:
/*  f15361c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f153620:	03e00008 */ 	jr	$ra
/*  f153624:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153628
/*  f153628:	00801025 */ 	or	$v0,$a0,$zero
/*  f15362c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153630:	3c0ee700 */ 	lui	$t6,0xe700
/*  f153634:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f153638:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15363c:	00801825 */ 	or	$v1,$a0,$zero
/*  f153640:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153644:	3c0fba00 */ 	lui	$t7,0xba00
/*  f153648:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f15364c:	00802825 */ 	or	$a1,$a0,$zero
/*  f153650:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f153654:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f153658:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15365c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f153660:	37180602 */ 	ori	$t8,$t8,0x602
/*  f153664:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f153668:	00803025 */ 	or	$a2,$a0,$zero
/*  f15366c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f153670:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f153674:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153678:	3c08b900 */ 	lui	$t0,0xb900
/*  f15367c:	3c090050 */ 	lui	$t1,0x50
/*  f153680:	35294240 */ 	ori	$t1,$t1,0x4240
/*  f153684:	3508031d */ 	ori	$t0,$t0,0x31d
/*  f153688:	00803825 */ 	or	$a3,$a0,$zero
/*  f15368c:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f153690:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f153694:	3c0afcff */ 	lui	$t2,0xfcff
/*  f153698:	3c0bff2d */ 	lui	$t3,0xff2d
/*  f15369c:	356bfeff */ 	ori	$t3,$t3,0xfeff
/*  f1536a0:	354a97ff */ 	ori	$t2,$t2,0x97ff
/*  f1536a4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1536a8:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f1536ac:	aceb0004 */ 	sw	$t3,0x4($a3)
/*  f1536b0:	00801025 */ 	or	$v0,$a0,$zero
/*  f1536b4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1536b8:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1536bc:	358c1301 */ 	ori	$t4,$t4,0x1301
/*  f1536c0:	00801825 */ 	or	$v1,$a0,$zero
/*  f1536c4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f1536c8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1536cc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1536d0:	3c0db900 */ 	lui	$t5,0xb900
/*  f1536d4:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f1536d8:	00802825 */ 	or	$a1,$a0,$zero
/*  f1536dc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f1536e0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1536e4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f1536e8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1536ec:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f1536f0:	00803025 */ 	or	$a2,$a0,$zero
/*  f1536f4:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1536f8:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1536fc:	3c0fba00 */ 	lui	$t7,0xba00
/*  f153700:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f153704:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153708:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f15370c:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f153710:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f153714:	00803825 */ 	or	$a3,$a0,$zero
/*  f153718:	3c19ba00 */ 	lui	$t9,0xba00
/*  f15371c:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f153720:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f153724:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f153728:	3c088008 */ 	lui	$t0,%hi(var8007fad8)
/*  f15372c:	8d08fad8 */ 	lw	$t0,%lo(var8007fad8)($t0)
/*  f153730:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153734:	00801025 */ 	or	$v0,$a0,$zero
/*  f153738:	1100000a */ 	beqz	$t0,.L0f153764
/*  f15373c:	3c0bba00 */ 	lui	$t3,0xba00
/*  f153740:	00801025 */ 	or	$v0,$a0,$zero
/*  f153744:	3c09ba00 */ 	lui	$t1,0xba00
/*  f153748:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f15374c:	240a3000 */ 	addiu	$t2,$zero,0x3000
/*  f153750:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f153754:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f153758:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15375c:	03e00008 */ 	jr	$ra
/*  f153760:	00801025 */ 	or	$v0,$a0,$zero
.L0f153764:
/*  f153764:	356b0c02 */ 	ori	$t3,$t3,0xc02
/*  f153768:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f15376c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f153770:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f153774:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f153778:	03e00008 */ 	jr	$ra
/*  f15377c:	00801025 */ 	or	$v0,$a0,$zero
);

Gfx *func0f153780(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, 0x00000040);
	gDPSetTexturePersp(gdl++, 0x00080000);
	gDPSetTextureLOD(gdl++, 0x00010000);

	return gdl;
}

Gfx *func0f1537dc(Gfx *gdl, u32 colour)
{
	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, 0x00500000, 0x4240);
	gDPSetCombine(gdl++, 0xffffff, 0xfffdf6fb);
	gDPSetPrimColor(gdl++, 0, 0, colour);

	return gdl;
}

Gfx *func0f153838(Gfx *gdl)
{
	gDPSetCombine(gdl++, 0xff97ff, 0xff2dfeff);

	return gdl;
}

GLOBAL_ASM(
glabel func0f153858
/*  f153858:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15385c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153860:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f153864:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f153868:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f15386c:	0fc54df7 */ 	jal	func0f1537dc
/*  f153870:	00002825 */ 	or	$a1,$zero,$zero
/*  f153874:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f153878:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f15387c:	3c01f600 */ 	lui	$at,0xf600
/*  f153880:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f153884:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f153888:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f15388c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f153890:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f153894:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f153898:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f15389c:	03214025 */ 	or	$t0,$t9,$at
/*  f1538a0:	010c6825 */ 	or	$t5,$t0,$t4
/*  f1538a4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1538a8:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f1538ac:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f1538b0:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f1538b4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f1538b8:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f1538bc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1538c0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1538c4:	000b4380 */ 	sll	$t0,$t3,0xe
/*  f1538c8:	03286025 */ 	or	$t4,$t9,$t0
/*  f1538cc:	0fc54e0e */ 	jal	func0f153838
/*  f1538d0:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1538d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1538d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1538dc:	03e00008 */ 	jr	$ra
/*  f1538e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1538e4
/*  f1538e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1538e8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1538ec:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1538f0:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1538f4:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1538f8:	0fc54df7 */ 	jal	func0f1537dc
/*  f1538fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f153900:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f153904:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f153908:	2463fac0 */ 	addiu	$v1,$v1,%lo(var8007fac0)
/*  f15390c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f153910:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f153914:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f153918:	3c01f600 */ 	lui	$at,0xf600
/*  f15391c:	01f80019 */ 	multu	$t7,$t8
/*  f153920:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f153924:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f153928:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f15392c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f153930:	01a17025 */ 	or	$t6,$t5,$at
/*  f153934:	0000c812 */ 	mflo	$t9
/*  f153938:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f15393c:	00084b80 */ 	sll	$t1,$t0,0xe
/*  f153940:	01c97825 */ 	or	$t7,$t6,$t1
/*  f153944:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f153948:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f15394c:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f153950:	8fad0020 */ 	lw	$t5,0x20($sp)
/*  f153954:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f153958:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f15395c:	03280019 */ 	multu	$t9,$t0
/*  f153960:	31c903ff */ 	andi	$t1,$t6,0x3ff
/*  f153964:	00097880 */ 	sll	$t7,$t1,0x2
/*  f153968:	00005012 */ 	mflo	$t2
/*  f15396c:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f153970:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f153974:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f153978:	0fc54e0e */ 	jal	func0f153838
/*  f15397c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f153980:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f153984:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f153988:	03e00008 */ 	jr	$ra
/*  f15398c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153990
/*  f153990:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f153994:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153998:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f15399c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1539a0:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1539a4:	0fc54df7 */ 	jal	func0f1537dc
/*  f1539a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1539ac:	3c0f8008 */ 	lui	$t7,%hi(var8007fad0)
/*  f1539b0:	8deffad0 */ 	lw	$t7,%lo(var8007fad0)($t7)
/*  f1539b4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f1539b8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f1539bc:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f1539c0:	01cf0019 */ 	multu	$t6,$t7
/*  f1539c4:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f1539c8:	3c01f600 */ 	lui	$at,0xf600
/*  f1539cc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f1539d0:	00ac6821 */ 	addu	$t5,$a1,$t4
/*  f1539d4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1539d8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1539dc:	24acffff */ 	addiu	$t4,$a1,-1
/*  f1539e0:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f1539e4:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f1539e8:	0000c012 */ 	mflo	$t8
/*  f1539ec:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f1539f0:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f1539f4:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f1539f8:	00095380 */ 	sll	$t2,$t1,0xe
/*  f1539fc:	2468ffff */ 	addiu	$t0,$v1,-1
/*  f153a00:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f153a04:	01415825 */ 	or	$t3,$t2,$at
/*  f153a08:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f153a0c:	00095380 */ 	sll	$t2,$t1,0xe
/*  f153a10:	014e7825 */ 	or	$t7,$t2,$t6
/*  f153a14:	0178c825 */ 	or	$t9,$t3,$t8
/*  f153a18:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f153a1c:	0fc54e0e */ 	jal	func0f153838
/*  f153a20:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f153a24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f153a28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f153a2c:	03e00008 */ 	jr	$ra
/*  f153a30:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153a34
/*  f153a34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f153a38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153a3c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f153a40:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f153a44:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f153a48:	0fc54df7 */ 	jal	func0f1537dc
/*  f153a4c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f153a50:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f153a54:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f153a58:	3c01f600 */ 	lui	$at,0xf600
/*  f153a5c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f153a60:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f153a64:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f153a68:	00095080 */ 	sll	$t2,$t1,0x2
/*  f153a6c:	0301c825 */ 	or	$t9,$t8,$at
/*  f153a70:	032a5825 */ 	or	$t3,$t9,$t2
/*  f153a74:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f153a78:	8faf0020 */ 	lw	$t7,0x20($sp)
/*  f153a7c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f153a80:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f153a84:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f153a88:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f153a8c:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f153a90:	00184080 */ 	sll	$t0,$t8,0x2
/*  f153a94:	01c84825 */ 	or	$t1,$t6,$t0
/*  f153a98:	0fc54e0e */ 	jal	func0f153838
/*  f153a9c:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f153aa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f153aa4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f153aa8:	03e00008 */ 	jr	$ra
/*  f153aac:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153ab0
/*  f153ab0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f153ab4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f153ab8:	00808025 */ 	or	$s0,$a0,$zero
/*  f153abc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f153ac0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f153ac4:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f153ac8:	ac2efb9c */ 	sw	$t6,%lo(var8007fb9c)($at)
/*  f153acc:	0fc59e7d */ 	jal	func0f1679f4
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

GLOBAL_ASM(
glabel func0f153b40
/*  f153b40:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f153b44:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f153b48:	24844634 */ 	addiu	$a0,$a0,%lo(var800a4634)
/*  f153b4c:	ac20fb9c */ 	sw	$zero,%lo(var8007fb9c)($at)
/*  f153b50:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f153b54:	3c0fb800 */ 	lui	$t7,0xb800
/*  f153b58:	246e0008 */ 	addiu	$t6,$v1,0x8
/*  f153b5c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f153b60:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f153b64:	03e00008 */ 	jr	$ra
/*  f153b68:	ac6f0000 */ 	sw	$t7,0x0($v1)
);

GLOBAL_ASM(
glabel func0f153b6c
/*  f153b6c:	3c0e8008 */ 	lui	$t6,%hi(var8007fba4)
/*  f153b70:	8dcefba4 */ 	lw	$t6,%lo(var8007fba4)($t6)
/*  f153b74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f153b78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153b7c:	108e0024 */ 	beq	$a0,$t6,.L0f153c10
/*  f153b80:	3c03800a */ 	lui	$v1,%hi(var800a45d0)
/*  f153b84:	246345d0 */ 	addiu	$v1,$v1,%lo(var800a45d0)
/*  f153b88:	8c6f0010 */ 	lw	$t7,0x10($v1)
/*  f153b8c:	c4600014 */ 	lwc1	$f0,0x14($v1)
/*  f153b90:	44805000 */ 	mtc1	$zero,$f10
/*  f153b94:	008f1023 */ 	subu	$v0,$a0,$t7
/*  f153b98:	00420019 */ 	multu	$v0,$v0
/*  f153b9c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f153ba0:	0000c012 */ 	mflo	$t8
/*  f153ba4:	44983000 */ 	mtc1	$t8,$f6
/*  f153ba8:	00000000 */ 	nop
/*  f153bac:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f153bb0:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f153bb4:	460c503c */ 	c.lt.s	$f10,$f12
/*  f153bb8:	00000000 */ 	nop
/*  f153bbc:	45000010 */ 	bc1f	.L0f153c00
/*  f153bc0:	00000000 */ 	nop
/*  f153bc4:	0c012974 */ 	jal	sqrtf
/*  f153bc8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f153bcc:	3c03800a */ 	lui	$v1,%hi(var800a45d0)
/*  f153bd0:	246345d0 */ 	addiu	$v1,$v1,%lo(var800a45d0)
/*  f153bd4:	8c79000c */ 	lw	$t9,0xc($v1)
/*  f153bd8:	3c018008 */ 	lui	$at,%hi(var8007fba0)
/*  f153bdc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f153be0:	44998000 */ 	mtc1	$t9,$f16
/*  f153be4:	00000000 */ 	nop
/*  f153be8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f153bec:	46120180 */ 	add.s	$f6,$f0,$f18
/*  f153bf0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f153bf4:	44092000 */ 	mfc1	$t1,$f4
/*  f153bf8:	10000003 */ 	b	.L0f153c08
/*  f153bfc:	ac29fba0 */ 	sw	$t1,%lo(var8007fba0)($at)
.L0f153c00:
/*  f153c00:	3c018008 */ 	lui	$at,%hi(var8007fba0)
/*  f153c04:	ac20fba0 */ 	sw	$zero,%lo(var8007fba0)($at)
.L0f153c08:
/*  f153c08:	3c018008 */ 	lui	$at,%hi(var8007fba4)
/*  f153c0c:	ac24fba4 */ 	sw	$a0,%lo(var8007fba4)($at)
.L0f153c10:
/*  f153c10:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f153c14:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f153c18:	03e00008 */ 	jr	$ra
/*  f153c1c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f153c20
/*  f153c20:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153c24:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153c28:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f153c2c:	44866000 */ 	mtc1	$a2,$f12
/*  f153c30:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f153c34:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f153c38:	a0580000 */ 	sb	$t8,0x0($v0)
/*  f153c3c:	ac44000c */ 	sw	$a0,0xc($v0)
/*  f153c40:	ac450010 */ 	sw	$a1,0x10($v0)
/*  f153c44:	a0470018 */ 	sb	$a3,0x18($v0)
/*  f153c48:	03e00008 */ 	jr	$ra
/*  f153c4c:	e44c0014 */ 	swc1	$f12,0x14($v0)
);

GLOBAL_ASM(
glabel func0f153c50
/*  f153c50:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153c54:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153c58:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f153c5c:	8c4e000c */ 	lw	$t6,0xc($v0)
/*  f153c60:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f153c64:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f153c68:	90580018 */ 	lbu	$t8,0x18($v0)
/*  f153c6c:	33280001 */ 	andi	$t0,$t9,0x1
/*  f153c70:	a0480029 */ 	sb	$t0,0x29($v0)
/*  f153c74:	ac4e001c */ 	sw	$t6,0x1c($v0)
/*  f153c78:	ac4f0020 */ 	sw	$t7,0x20($v0)
/*  f153c7c:	e4440024 */ 	swc1	$f4,0x24($v0)
/*  f153c80:	03e00008 */ 	jr	$ra
/*  f153c84:	a0580028 */ 	sb	$t8,0x28($v0)
);

GLOBAL_ASM(
glabel func0f153c88
/*  f153c88:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153c8c:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153c90:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f153c94:	90480029 */ 	lbu	$t0,0x29($v0)
/*  f153c98:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f153c9c:	8c4f0020 */ 	lw	$t7,0x20($v0)
/*  f153ca0:	c4440024 */ 	lwc1	$f4,0x24($v0)
/*  f153ca4:	90580028 */ 	lbu	$t8,0x28($v0)
/*  f153ca8:	03284825 */ 	or	$t1,$t9,$t0
/*  f153cac:	a0490000 */ 	sb	$t1,0x0($v0)
/*  f153cb0:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f153cb4:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f153cb8:	e4440014 */ 	swc1	$f4,0x14($v0)
/*  f153cbc:	03e00008 */ 	jr	$ra
/*  f153cc0:	a0580018 */ 	sb	$t8,0x18($v0)
/*  f153cc4:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153cc8:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153ccc:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f153cd0:	ac44002c */ 	sw	$a0,0x2c($v0)
/*  f153cd4:	ac450030 */ 	sw	$a1,0x30($v0)
/*  f153cd8:	35cf0002 */ 	ori	$t7,$t6,0x2
/*  f153cdc:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f153ce0:	03e00008 */ 	jr	$ra
/*  f153ce4:	ac460034 */ 	sw	$a2,0x34($v0)
);

GLOBAL_ASM(
glabel func0f153ce8
/*  f153ce8:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153cec:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153cf0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f153cf4:	ac440038 */ 	sw	$a0,0x38($v0)
/*  f153cf8:	ac45003c */ 	sw	$a1,0x3c($v0)
/*  f153cfc:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f153d00:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f153d04:	03e00008 */ 	jr	$ra
/*  f153d08:	ac460040 */ 	sw	$a2,0x40($v0)
/*  f153d0c:	3c01800a */ 	lui	$at,%hi(var800a45d0)
/*  f153d10:	03e00008 */ 	jr	$ra
/*  f153d14:	a02045d0 */ 	sb	$zero,%lo(var800a45d0)($at)
/*  f153d18:	3c01800a */ 	lui	$at,%hi(var800a45d0)
/*  f153d1c:	03e00008 */ 	jr	$ra
/*  f153d20:	a02045d0 */ 	sb	$zero,%lo(var800a45d0)($at)
);

GLOBAL_ASM(
glabel func0f153d24
/*  f153d24:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153d28:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153d2c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f153d30:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f153d34:	03e00008 */ 	jr	$ra
/*  f153d38:	a04e002a */ 	sb	$t6,0x2a($v0)
);

GLOBAL_ASM(
glabel func0f153d3c
/*  f153d3c:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153d40:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153d44:	904e002a */ 	lbu	$t6,0x2a($v0)
/*  f153d48:	03e00008 */ 	jr	$ra
/*  f153d4c:	a04e0000 */ 	sb	$t6,0x0($v0)
);

GLOBAL_ASM(
glabel func0f153d50
/*  f153d50:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153d54:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153d58:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f153d5c:	3c184444 */ 	lui	$t8,0x4444
/*  f153d60:	37184400 */ 	ori	$t8,$t8,0x4400
/*  f153d64:	2419ff00 */ 	addiu	$t9,$zero,-256
/*  f153d68:	35cf0004 */ 	ori	$t7,$t6,0x4
/*  f153d6c:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f153d70:	ac44004c */ 	sw	$a0,0x4c($v0)
/*  f153d74:	ac450050 */ 	sw	$a1,0x50($v0)
/*  f153d78:	ac460054 */ 	sw	$a2,0x54($v0)
/*  f153d7c:	ac580058 */ 	sw	$t8,0x58($v0)
/*  f153d80:	03e00008 */ 	jr	$ra
/*  f153d84:	ac59005c */ 	sw	$t9,0x5c($v0)
);

GLOBAL_ASM(
glabel func0f153d88
/*  f153d88:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*  f153d8c:	3c0142dc */ 	lui	$at,0x42dc
/*  f153d90:	44813000 */ 	mtc1	$at,$f6
/*  f153d94:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f153d98:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153d9c:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153da0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f153da4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f153da8:	3c014f00 */ 	lui	$at,0x4f00
/*  f153dac:	35cf0008 */ 	ori	$t7,$t6,0x8
/*  f153db0:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f153db4:	4458f800 */ 	cfc1	$t8,$31
/*  f153db8:	44d9f800 */ 	ctc1	$t9,$31
/*  f153dbc:	00000000 */ 	nop
/*  f153dc0:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f153dc4:	4459f800 */ 	cfc1	$t9,$31
/*  f153dc8:	00000000 */ 	nop
/*  f153dcc:	33390078 */ 	andi	$t9,$t9,0x78
/*  f153dd0:	53200013 */ 	beqzl	$t9,.L0f153e20
/*  f153dd4:	44195000 */ 	mfc1	$t9,$f10
/*  f153dd8:	44815000 */ 	mtc1	$at,$f10
/*  f153ddc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f153de0:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f153de4:	44d9f800 */ 	ctc1	$t9,$31
/*  f153de8:	00000000 */ 	nop
/*  f153dec:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f153df0:	4459f800 */ 	cfc1	$t9,$31
/*  f153df4:	00000000 */ 	nop
/*  f153df8:	33390078 */ 	andi	$t9,$t9,0x78
/*  f153dfc:	17200005 */ 	bnez	$t9,.L0f153e14
/*  f153e00:	00000000 */ 	nop
/*  f153e04:	44195000 */ 	mfc1	$t9,$f10
/*  f153e08:	3c018000 */ 	lui	$at,0x8000
/*  f153e0c:	10000007 */ 	b	.L0f153e2c
/*  f153e10:	0321c825 */ 	or	$t9,$t9,$at
.L0f153e14:
/*  f153e14:	10000005 */ 	b	.L0f153e2c
/*  f153e18:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f153e1c:	44195000 */ 	mfc1	$t9,$f10
.L0f153e20:
/*  f153e20:	00000000 */ 	nop
/*  f153e24:	0720fffb */ 	bltz	$t9,.L0f153e14
/*  f153e28:	00000000 */ 	nop
.L0f153e2c:
/*  f153e2c:	44d8f800 */ 	ctc1	$t8,$31
/*  f153e30:	03e00008 */ 	jr	$ra
/*  f153e34:	ac590060 */ 	sw	$t9,0x60($v0)
);

GLOBAL_ASM(
glabel func0f153e38
/*  f153e38:	3c02800a */ 	lui	$v0,%hi(var800a45d0)
/*  f153e3c:	244245d0 */ 	addiu	$v0,$v0,%lo(var800a45d0)
/*  f153e40:	ac440058 */ 	sw	$a0,0x58($v0)
/*  f153e44:	03e00008 */ 	jr	$ra
/*  f153e48:	ac45005c */ 	sw	$a1,0x5c($v0)
);

GLOBAL_ASM(
glabel func0f153e4c
/*  f153e4c:	3c01800a */ 	lui	$at,%hi(var800a45d0)
/*  f153e50:	03e00008 */ 	jr	$ra
/*  f153e54:	a02045d0 */ 	sb	$zero,%lo(var800a45d0)($at)
);

GLOBAL_ASM(
glabel func0f153e58
/*  f153e58:	3c04800a */ 	lui	$a0,%hi(var800a45d0)
/*  f153e5c:	248445d0 */ 	addiu	$a0,$a0,%lo(var800a45d0)
/*  f153e60:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f153e64:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f153e68:	000e102b */ 	sltu	$v0,$zero,$t6
/*  f153e6c:	10400007 */ 	beqz	$v0,.L0f153e8c
/*  f153e70:	00000000 */ 	nop
/*  f153e74:	90830018 */ 	lbu	$v1,0x18($a0)
/*  f153e78:	2c620001 */ 	sltiu	$v0,$v1,0x1
/*  f153e7c:	14400003 */ 	bnez	$v0,.L0f153e8c
/*  f153e80:	00000000 */ 	nop
/*  f153e84:	38620002 */ 	xori	$v0,$v1,0x2
/*  f153e88:	2c420001 */ 	sltiu	$v0,$v0,0x1
.L0f153e8c:
/*  f153e8c:	03e00008 */ 	jr	$ra
/*  f153e90:	00000000 */ 	nop
);

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

GLOBAL_ASM(
glabel func0f154ecc
/*  f154ecc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f154ed0:	00803825 */ 	or	$a3,$a0,$zero
/*  f154ed4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f154ed8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f154edc:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f154ee0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f154ee4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f154ee8:	3c06800a */ 	lui	$a2,%hi(var800a45d4)
/*  f154eec:	8cc645d4 */ 	lw	$a2,%lo(var800a45d4)($a2)
/*  f154ef0:	0fc550eb */ 	jal	func0f1543ac
/*  f154ef4:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f154ef8:	3c05800a */ 	lui	$a1,%hi(var800a45d0)
/*  f154efc:	24a545d0 */ 	addiu	$a1,$a1,%lo(var800a45d0)
/*  f154f00:	8cae0044 */ 	lw	$t6,0x44($a1)
/*  f154f04:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f154f08:	00402025 */ 	or	$a0,$v0,$zero
/*  f154f0c:	104e0005 */ 	beq	$v0,$t6,.L0f154f24
/*  f154f10:	00e01825 */ 	or	$v1,$a3,$zero
/*  f154f14:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f154f18:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f154f1c:	24e70008 */ 	addiu	$a3,$a3,0x8
/*  f154f20:	ac620004 */ 	sw	$v0,0x4($v1)
.L0f154f24:
/*  f154f24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f154f28:	aca40044 */ 	sw	$a0,0x44($a1)
/*  f154f2c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f154f30:	03e00008 */ 	jr	$ra
/*  f154f34:	00e01025 */ 	or	$v0,$a3,$zero
);

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
/*  f15516c:	0fc59e59 */ 	jal	func0f167964
/*  f155170:	a7b90030 */ 	sh	$t9,0x30($sp)
/*  f155174:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f155178:	0fc59e73 */ 	jal	func0f1679cc
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
/*  f155770:	0c002f02 */ 	jal	viGetX
/*  f155774:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155778:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f15577c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155780:	004e082a */ 	slt	$at,$v0,$t6
/*  f155784:	5420021a */ 	bnezl	$at,.L0f155ff0
/*  f155788:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f15578c:	0c002f06 */ 	jal	viGetY
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
/*  f15589c:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f1558a0:	5320001f */ 	beqzl	$t9,.L0f155920
/*  f1558a4:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f1558a8:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f1558ac:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
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
/*  f155c04:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f155c08:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
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
/*  f155c70:	3c02800a */ 	lui	$v0,%hi(var800a45d4)
/*  f155c74:	00007812 */ 	mflo	$t7
/*  f155c78:	006f7021 */ 	addu	$t6,$v1,$t7
/*  f155c7c:	01c5082a */ 	slt	$at,$t6,$a1
/*  f155c80:	54200023 */ 	bnezl	$at,.L0f155d10
/*  f155c84:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155c88:	82390001 */ 	lb	$t9,0x1($s1)
/*  f155c8c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f155c90:	8c4245d4 */ 	lw	$v0,%lo(var800a45d4)($v0)
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
/*  f155cc0:	3c198008 */ 	lui	$t9,%hi(var8007fac0)
/*  f155cc4:	8f39fac0 */ 	lw	$t9,%lo(var8007fac0)($t9)
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
/*  f155d40:	3c02800a */ 	lui	$v0,%hi(var800a45d4)
/*  f155d44:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155d48:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f155d4c:	8c4245d4 */ 	lw	$v0,%lo(var800a45d4)($v0)
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

GLOBAL_ASM(
glabel textRenderWhite
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
/*  f156090:	3c198008 */ 	lui	$t9,%hi(var8007fac0)
/*  f156094:	8f39fac0 */ 	lw	$t9,%lo(var8007fac0)($t9)
/*  f156098:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f15609c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1560a0:	03190019 */ 	multu	$t8,$t9
/*  f1560a4:	00004012 */ 	mflo	$t0
/*  f1560a8:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1560ac:	10000008 */ 	b	.L0f1560d0
/*  f1560b0:	afa900b0 */ 	sw	$t1,0xb0($sp)
.L0f1560b4:
/*  f1560b4:	3c0b8008 */ 	lui	$t3,%hi(var8007fac0)
/*  f1560b8:	8d6bfac0 */ 	lw	$t3,%lo(var8007fac0)($t3)
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
/*  f1560ec:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f1560f0:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
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
/*  f15661c:	3c0d8008 */ 	lui	$t5,%hi(var8007fac0)
/*  f156620:	8dadfac0 */ 	lw	$t5,%lo(var8007fac0)($t5)
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
/*  f156660:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f156664:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
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

GLOBAL_ASM(
glabel func0f1566cc
/*  f1566cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1566d0:	00803825 */ 	or	$a3,$a0,$zero
/*  f1566d4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1566d8:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1566dc:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1566e0:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1566e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1566e8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f1566ec:	00c02825 */ 	or	$a1,$a2,$zero
/*  f1566f0:	8d260004 */ 	lw	$a2,0x4($t1)
/*  f1566f4:	0fc550eb */ 	jal	func0f1543ac
/*  f1566f8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f1566fc:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f156700:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f156704:	8d2e0044 */ 	lw	$t6,0x44($t1)
/*  f156708:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f15670c:	00404025 */ 	or	$t0,$v0,$zero
/*  f156710:	104e0005 */ 	beq	$v0,$t6,.L0f156728
/*  f156714:	00e01825 */ 	or	$v1,$a3,$zero
/*  f156718:	3c0ffb00 */ 	lui	$t7,0xfb00
/*  f15671c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f156720:	24e70008 */ 	addiu	$a3,$a3,0x8
/*  f156724:	ac620004 */ 	sw	$v0,0x4($v1)
.L0f156728:
/*  f156728:	ad280044 */ 	sw	$t0,0x44($t1)
/*  f15672c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f156730:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f156734:	8d260008 */ 	lw	$a2,0x8($t1)
/*  f156738:	0fc550eb */ 	jal	func0f1543ac
/*  f15673c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f156740:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f156744:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f156748:	8d390008 */ 	lw	$t9,0x8($t1)
/*  f15674c:	8d2b0048 */ 	lw	$t3,0x48($t1)
/*  f156750:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f156754:	305800ff */ 	andi	$t8,$v0,0xff
/*  f156758:	03215024 */ 	and	$t2,$t9,$at
/*  f15675c:	030a4025 */ 	or	$t0,$t8,$t2
/*  f156760:	110b0006 */ 	beq	$t0,$t3,.L0f15677c
/*  f156764:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f156768:	00e01025 */ 	or	$v0,$a3,$zero
/*  f15676c:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f156770:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f156774:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f156778:	24e70008 */ 	addiu	$a3,$a3,0x8
.L0f15677c:
/*  f15677c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f156780:	ad280048 */ 	sw	$t0,0x48($t1)
/*  f156784:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f156788:	03e00008 */ 	jr	$ra
/*  f15678c:	00e01025 */ 	or	$v0,$a3,$zero
);

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
/*  f156828:	0c002f02 */ 	jal	viGetX
/*  f15682c:	00000000 */ 	nop
/*  f156830:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f156834:	004b082a */ 	slt	$at,$v0,$t3
/*  f156838:	1420006b */ 	bnez	$at,.L0f1569e8
/*  f15683c:	00000000 */ 	nop
/*  f156840:	0c002f06 */ 	jal	viGetY
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
/*  f1568b4:	3c0c8008 */ 	lui	$t4,%hi(var8007fac0)
/*  f1568b8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f1568bc:	53200017 */ 	beqzl	$t9,.L0f15691c
/*  f1568c0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1568c4:	8d8cfac0 */ 	lw	$t4,%lo(var8007fac0)($t4)
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
/*  f156e74:	3c0f8008 */ 	lui	$t7,%hi(var8007fac0)
/*  f156e78:	8deffac0 */ 	lw	$t7,%lo(var8007fac0)($t7)
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
/*  f157280:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f157284:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
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
/*  f1574c0:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f1574c4:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
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

GLOBAL_ASM(
glabel func0f157520
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

GLOBAL_ASM(
glabel func0f1577f0
/*  f1577f0:	c4ce0000 */ 	lwc1	$f14,0x0($a2)
/*  f1577f4:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f1577f8:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f1577fc:	c4c20004 */ 	lwc1	$f2,0x4($a2)
/*  f157800:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f157804:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f157808:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15780c:	460e3301 */ 	sub.s	$f12,$f6,$f14
/*  f157810:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*  f157814:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*  f157818:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f15781c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157820:	46127281 */ 	sub.s	$f10,$f14,$f18
/*  f157824:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f157828:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f15782c:	00000000 */ 	nop
/*  f157830:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f157834:	c4a80004 */ 	lwc1	$f8,0x4($a1)
/*  f157838:	460a2400 */ 	add.s	$f16,$f4,$f10
/*  f15783c:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f157840:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f157844:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f157848:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f15784c:	00000000 */ 	nop
/*  f157850:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f157854:	44803000 */ 	mtc1	$zero,$f6
/*  f157858:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f15785c:	46064032 */ 	c.eq.s	$f8,$f6
/*  f157860:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f157864:	c7a40010 */ 	lwc1	$f4,0x10($sp)
/*  f157868:	45000004 */ 	bc1f	.L0f15787c
/*  f15786c:	00000000 */ 	nop
/*  f157870:	44810000 */ 	mtc1	$at,$f0
/*  f157874:	10000012 */ 	b	.L0f1578c0
/*  f157878:	00000000 */ 	nop
.L0f15787c:
/*  f15787c:	46048403 */ 	div.s	$f16,$f16,$f4
/*  f157880:	44805000 */ 	mtc1	$zero,$f10
/*  f157884:	3c013f80 */ 	lui	$at,0x3f80
/*  f157888:	460a803c */ 	c.lt.s	$f16,$f10
/*  f15788c:	00000000 */ 	nop
/*  f157890:	45030007 */ 	bc1tl	.L0f1578b0
/*  f157894:	3c013f80 */ 	lui	$at,0x3f80
/*  f157898:	44814000 */ 	mtc1	$at,$f8
/*  f15789c:	00000000 */ 	nop
/*  f1578a0:	4610403c */ 	c.lt.s	$f8,$f16
/*  f1578a4:	00000000 */ 	nop
/*  f1578a8:	45000004 */ 	bc1f	.L0f1578bc
/*  f1578ac:	3c013f80 */ 	lui	$at,0x3f80
.L0f1578b0:
/*  f1578b0:	44810000 */ 	mtc1	$at,$f0
/*  f1578b4:	10000002 */ 	b	.L0f1578c0
/*  f1578b8:	00000000 */ 	nop
.L0f1578bc:
/*  f1578bc:	46008006 */ 	mov.s	$f0,$f16
.L0f1578c0:
/*  f1578c0:	03e00008 */ 	jr	$ra
/*  f1578c4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f1578c8
/*  f1578c8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1578cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1578d0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f1578d4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1578d8:	c4c80004 */ 	lwc1	$f8,0x4($a2)
/*  f1578dc:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f1578e0:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f1578e4:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f1578e8:	c4ae0000 */ 	lwc1	$f14,0x0($a1)
/*  f1578ec:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f1578f0:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f1578f4:	460c7102 */ 	mul.s	$f4,$f14,$f12
/*  f1578f8:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f1578fc:	3c017f1b */ 	lui	$at,%hi(var7f1b7410)
/*  f157900:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f157904:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f157908:	46007202 */ 	mul.s	$f8,$f14,$f0
/*  f15790c:	00000000 */ 	nop
/*  f157910:	46106282 */ 	mul.s	$f10,$f12,$f16
/*  f157914:	46149101 */ 	sub.s	$f4,$f18,$f20
/*  f157918:	46149180 */ 	add.s	$f6,$f18,$f20
/*  f15791c:	460a4080 */ 	add.s	$f2,$f8,$f10
/*  f157920:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f157924:	44805000 */ 	mtc1	$zero,$f10
/*  f157928:	00000000 */ 	nop
/*  f15792c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f157930:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f157934:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f157938:	45000003 */ 	bc1f	.L0f157948
/*  f15793c:	00000000 */ 	nop
/*  f157940:	1000001d */ 	b	.L0f1579b8
/*  f157944:	c4207410 */ 	lwc1	$f0,%lo(var7f1b7410)($at)
.L0f157948:
/*  f157948:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f15794c:	0c012974 */ 	jal	sqrtf
/*  f157950:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f157954:	c7a2002c */ 	lwc1	$f2,0x2c($sp)
/*  f157958:	44806000 */ 	mtc1	$zero,$f12
/*  f15795c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f157960:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f157964:	460c103c */ 	c.lt.s	$f2,$f12
/*  f157968:	00000000 */ 	nop
/*  f15796c:	45020012 */ 	bc1fl	.L0f1579b8
/*  f157970:	46001006 */ 	mov.s	$f0,$f2
/*  f157974:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f157978:	3c017f1b */ 	lui	$at,%hi(var7f1b7414)
/*  f15797c:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f157980:	00000000 */ 	nop
/*  f157984:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f157988:	00000000 */ 	nop
/*  f15798c:	4614a202 */ 	mul.s	$f8,$f20,$f20
/*  f157990:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f157994:	4604503e */ 	c.le.s	$f10,$f4
/*  f157998:	00000000 */ 	nop
/*  f15799c:	45000003 */ 	bc1f	.L0f1579ac
/*  f1579a0:	00000000 */ 	nop
/*  f1579a4:	10000004 */ 	b	.L0f1579b8
/*  f1579a8:	46006006 */ 	mov.s	$f0,$f12
.L0f1579ac:
/*  f1579ac:	10000002 */ 	b	.L0f1579b8
/*  f1579b0:	c4207414 */ 	lwc1	$f0,%lo(var7f1b7414)($at)
/*  f1579b4:	46001006 */ 	mov.s	$f0,$f2
.L0f1579b8:
/*  f1579b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1579bc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f1579c0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1579c4:	03e00008 */ 	jr	$ra
/*  f1579c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1579cc
/*  f1579cc:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f1579d0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1579d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1579d8:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f1579dc:	c4e00000 */ 	lwc1	$f0,0x0($a3)
/*  f1579e0:	c4e20004 */ 	lwc1	$f2,0x4($a3)
/*  f1579e4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1579e8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f1579ec:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f1579f0:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f1579f4:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f1579f8:	0c012974 */ 	jal	sqrtf
/*  f1579fc:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a00:	44803000 */ 	mtc1	$zero,$f6
/*  f157a04:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a08:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157a0c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157a10:	46000386 */ 	mov.s	$f14,$f0
/*  f157a14:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a18:	45020006 */ 	bc1fl	.L0f157a34
/*  f157a1c:	44814000 */ 	mtc1	$at,$f8
/*  f157a20:	3c013f80 */ 	lui	$at,0x3f80
/*  f157a24:	44810000 */ 	mtc1	$at,$f0
/*  f157a28:	100000dc */ 	b	.L0f157d9c
/*  f157a2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157a30:	44814000 */ 	mtc1	$at,$f8
.L0f157a34:
/*  f157a34:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f157a38:	8fa200b8 */ 	lw	$v0,0xb8($sp)
/*  f157a3c:	460e4403 */ 	div.s	$f16,$f8,$f14
/*  f157a40:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f157a44:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f157a48:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f157a4c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f157a50:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
/*  f157a54:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f157a58:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f157a5c:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f157a60:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f157a64:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f157a68:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f157a6c:	e7ae00ac */ 	swc1	$f14,0xac($sp)
/*  f157a70:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f157a74:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f157a78:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f157a7c:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f157a80:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f157a84:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f157a88:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157a8c:	0c012974 */ 	jal	sqrtf
/*  f157a90:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f157a94:	44803000 */ 	mtc1	$zero,$f6
/*  f157a98:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157a9c:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f157aa0:	46060032 */ 	c.eq.s	$f0,$f6
/*  f157aa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157aa8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157aac:	45010077 */ 	bc1t	.L0f157c8c
/*  f157ab0:	00000000 */ 	nop
/*  f157ab4:	44814000 */ 	mtc1	$at,$f8
/*  f157ab8:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f157abc:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f157ac0:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f157ac4:	02001025 */ 	or	$v0,$s0,$zero
/*  f157ac8:	46003207 */ 	neg.s	$f8,$f6
/*  f157acc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f157ad0:	00000000 */ 	nop
/*  f157ad4:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f157ad8:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f157adc:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f157ae0:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f157ae4:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157ae8:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f157aec:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f157af0:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f157af4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f157af8:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f157afc:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f157b00:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f157b04:	46044402 */ 	mul.s	$f16,$f8,$f4
/*  f157b08:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157b0c:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157b10:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f157b14:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f157b18:	46024101 */ 	sub.s	$f4,$f8,$f2
/*  f157b1c:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157b20:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f157b24:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f157b28:	00000000 */ 	nop
/*  f157b2c:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f157b30:	44804000 */ 	mtc1	$zero,$f8
/*  f157b34:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f157b38:	4608503c */ 	c.lt.s	$f10,$f8
/*  f157b3c:	00000000 */ 	nop
/*  f157b40:	45000003 */ 	bc1f	.L0f157b50
/*  f157b44:	00000000 */ 	nop
/*  f157b48:	46007387 */ 	neg.s	$f14,$f14
/*  f157b4c:	46008407 */ 	neg.s	$f16,$f16
.L0f157b50:
/*  f157b50:	460e1180 */ 	add.s	$f6,$f2,$f14
/*  f157b54:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f157b58:	46106100 */ 	add.s	$f4,$f12,$f16
/*  f157b5c:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f157b60:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f157b64:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f157b68:	460e5200 */ 	add.s	$f8,$f10,$f14
/*  f157b6c:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f157b70:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f157b74:	46103100 */ 	add.s	$f4,$f6,$f16
/*  f157b78:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f157b7c:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f157b80:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f157b84:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f157b88:	e7aa0048 */ 	swc1	$f10,0x48($sp)
/*  f157b8c:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f157b90:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f157b94:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f157b98:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f157b9c:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f157ba0:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f157ba4:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f157ba8:	46044202 */ 	mul.s	$f8,$f8,$f4
/*  f157bac:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f157bb0:	46085281 */ 	sub.s	$f10,$f10,$f8
/*  f157bb4:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f157bb8:	e7aa0068 */ 	swc1	$f10,0x68($sp)
/*  f157bbc:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157bc0:	46064202 */ 	mul.s	$f8,$f8,$f6
/*  f157bc4:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*  f157bc8:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157bcc:	46044381 */ 	sub.s	$f14,$f8,$f4
/*  f157bd0:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f157bd4:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f157bd8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f157bdc:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f157be0:	460a2102 */ 	mul.s	$f4,$f4,$f10
/*  f157be4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f157be8:	46005306 */ 	mov.s	$f12,$f10
/*  f157bec:	46043481 */ 	sub.s	$f18,$f6,$f4
/*  f157bf0:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f157bf4:	460a903c */ 	c.lt.s	$f18,$f10
/*  f157bf8:	00000000 */ 	nop
/*  f157bfc:	4502000a */ 	bc1fl	.L0f157c28
/*  f157c00:	460c9032 */ 	c.eq.s	$f18,$f12
/*  f157c04:	46008407 */ 	neg.s	$f16,$f16
/*  f157c08:	46003107 */ 	neg.s	$f4,$f6
/*  f157c0c:	46009306 */ 	mov.s	$f12,$f18
/*  f157c10:	00608025 */ 	or	$s0,$v1,$zero
/*  f157c14:	46005486 */ 	mov.s	$f18,$f10
/*  f157c18:	00401825 */ 	or	$v1,$v0,$zero
/*  f157c1c:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f157c20:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f157c24:	460c9032 */ 	c.eq.s	$f18,$f12
.L0f157c28:
/*  f157c28:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f157c2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f157c30:	45020012 */ 	bc1fl	.L0f157c7c
/*  f157c34:	460e903c */ 	c.lt.s	$f18,$f14
/*  f157c38:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c3c:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f157c40:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c44:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f157c48:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f157c4c:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157c50:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c54:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c58:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f157c5c:	c7a20060 */ 	lwc1	$f2,0x60($sp)
/*  f157c60:	4602003c */ 	c.lt.s	$f0,$f2
/*  f157c64:	00000000 */ 	nop
/*  f157c68:	45020038 */ 	bc1fl	.L0f157d4c
/*  f157c6c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f157c70:	10000035 */ 	b	.L0f157d48
/*  f157c74:	46000086 */ 	mov.s	$f2,$f0
/*  f157c78:	460e903c */ 	c.lt.s	$f18,$f14
.L0f157c7c:
/*  f157c7c:	00000000 */ 	nop
/*  f157c80:	45020007 */ 	bc1fl	.L0f157ca0
/*  f157c84:	460c703c */ 	c.lt.s	$f14,$f12
/*  f157c88:	afa300b8 */ 	sw	$v1,0xb8($sp)
.L0f157c8c:
/*  f157c8c:	0fc55e32 */ 	jal	func0f1578c8
/*  f157c90:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*  f157c94:	1000002c */ 	b	.L0f157d48
/*  f157c98:	46000086 */ 	mov.s	$f2,$f0
/*  f157c9c:	460c703c */ 	c.lt.s	$f14,$f12
.L0f157ca0:
/*  f157ca0:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f157ca4:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f157ca8:	45020006 */ 	bc1fl	.L0f157cc4
/*  f157cac:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f157cb0:	0fc55e32 */ 	jal	func0f1578c8
/*  f157cb4:	02003025 */ 	or	$a2,$s0,$zero
/*  f157cb8:	10000023 */ 	b	.L0f157d48
/*  f157cbc:	46000086 */ 	mov.s	$f2,$f0
/*  f157cc0:	c60c0004 */ 	lwc1	$f12,0x4($s0)
.L0f157cc4:
/*  f157cc4:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f157cc8:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f157ccc:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f157cd0:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f157cd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f157cd8:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f157cdc:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f157ce0:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f157ce4:	46105282 */ 	mul.s	$f10,$f10,$f16
/*  f157ce8:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f157cec:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f157cf0:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f157cf4:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f157cf8:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f157cfc:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f157d00:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f157d04:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f157d08:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f157d0c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f157d10:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f157d14:	46065380 */ 	add.s	$f14,$f10,$f6
/*  f157d18:	460e0032 */ 	c.eq.s	$f0,$f14
/*  f157d1c:	00000000 */ 	nop
/*  f157d20:	45020005 */ 	bc1fl	.L0f157d38
/*  f157d24:	46040201 */ 	sub.s	$f8,$f0,$f4
/*  f157d28:	44810000 */ 	mtc1	$at,$f0
/*  f157d2c:	1000001b */ 	b	.L0f157d9c
/*  f157d30:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d34:	46040201 */ 	sub.s	$f8,$f0,$f4
.L0f157d38:
/*  f157d38:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f157d3c:	460e0101 */ 	sub.s	$f4,$f0,$f14
/*  f157d40:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f157d44:	46043083 */ 	div.s	$f2,$f6,$f4
.L0f157d48:
/*  f157d48:	c7a800ac */ 	lwc1	$f8,0xac($sp)
.L0f157d4c:
/*  f157d4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157d50:	4602403c */ 	c.lt.s	$f8,$f2
/*  f157d54:	00000000 */ 	nop
/*  f157d58:	45020005 */ 	bc1fl	.L0f157d70
/*  f157d5c:	44805000 */ 	mtc1	$zero,$f10
/*  f157d60:	44810000 */ 	mtc1	$at,$f0
/*  f157d64:	1000000d */ 	b	.L0f157d9c
/*  f157d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f157d6c:	44805000 */ 	mtc1	$zero,$f10
.L0f157d70:
/*  f157d70:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f157d74:	460a103c */ 	c.lt.s	$f2,$f10
/*  f157d78:	00000000 */ 	nop
/*  f157d7c:	45000004 */ 	bc1f	.L0f157d90
/*  f157d80:	00000000 */ 	nop
/*  f157d84:	44800000 */ 	mtc1	$zero,$f0
/*  f157d88:	10000004 */ 	b	.L0f157d9c
/*  f157d8c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d90:
/*  f157d90:	46061002 */ 	mul.s	$f0,$f2,$f6
/*  f157d94:	00000000 */ 	nop
/*  f157d98:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f157d9c:
/*  f157d9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f157da0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f157da4:	03e00008 */ 	jr	$ra
/*  f157da8:	00000000 */ 	nop
/*  f157dac:	00000000 */ 	nop
);
