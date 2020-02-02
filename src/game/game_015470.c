#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_005fd0.h"
#include "game/game_015470.h"
#include "game/game_066310.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_10ccd0.h"
#include "game/game_111600.h"
#include "game/game_11ecf0.h"
#include "game/game_129900.h"
#include "game/pdoptions.h"
#include "game/game_152fa0.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_1999b0.h"
#include "game/game_19c990.h"
#include "game/game_1a3340.h"

const u32 var7f1a83b0[] = {0x459c4000};
const u32 var7f1a83b4[] = {0x00000000};
const u32 var7f1a83b8[] = {0x00000000};
const u32 var7f1a83bc[] = {0x00000000};
const u32 var7f1a83c0[] = {0x3faaaaab};
const u32 var7f1a83c4[] = {0x461c4000};
const u32 var7f1a83c8[] = {0x461c4000};
const u32 var7f1a83cc[] = {0x7f0167d8};
const u32 var7f1a83d0[] = {0x7f0167e8};
const u32 var7f1a83d4[] = {0x7f0167fc};
const u32 var7f1a83d8[] = {0x7f01686c};
const u32 var7f1a83dc[] = {0x7f01686c};
const u32 var7f1a83e0[] = {0x7f016808};
const u32 var7f1a83e4[] = {0x7f016858};
const u32 var7f1a83e8[] = {0x3faaaaab};
const u32 var7f1a83ec[] = {0x461c4000};
const u32 var7f1a83f0[] = {0x3eb33333};
const u32 var7f1a83f4[] = {0x3f2147ae};
const u32 var7f1a83f8[] = {0x3fd27a74};
const u32 var7f1a83fc[] = {0x3e4c8b44};
const u32 var7f1a8400[] = {0x458ca000};
const u32 var7f1a8404[] = {0x3dcccccd};
const u32 var7f1a8408[] = {0x4087b1f9};
const u32 var7f1a840c[] = {0x3c9a6417};
const u32 var7f1a8410[] = {0x3ef13c64};
const u32 var7f1a8414[] = {0x3eb33333};
const u32 var7f1a8418[] = {0x3fc907a9};
const u32 var7f1a841c[] = {0x39459ed6};
const u32 var7f1a8420[] = {0x3c9a6417};
const u32 var7f1a8424[] = {0x40c907a9};
const u32 var7f1a8428[] = {0x40c907a9};
const u32 var7f1a842c[] = {0x40c907a9};
const u32 var7f1a8430[] = {0x40c907a9};
const u32 var7f1a8434[] = {0x3b83126f};
const u32 var7f1a8438[] = {0x3f4ccccd};
const u32 var7f1a843c[] = {0x38ed2501};
const u32 var7f1a8440[] = {0x3c3944e9};
const u32 var7f1a8444[] = {0x40c907a9};
const u32 var7f1a8448[] = {0x3bf5c28f};
const u32 var7f1a844c[] = {0x3ccccccd};
const u32 var7f1a8450[] = {0x3db851ec};
const u32 var7f1a8454[] = {0x3dcccccd};
const u32 var7f1a8458[] = {0x3bcddaca};
const u32 var7f1a845c[] = {0x3c8b4396};
const u32 var7f1a8460[] = {0x40490fdb};
const u32 var7f1a8464[] = {0x3e19999a};
const u32 var7f1a8468[] = {0x3e9db22d};
const u32 var7f1a846c[] = {0x3faaaaab};
const u32 var7f1a8470[] = {0x461c4000};
const u32 var7f1a8474[] = {0x3faaaaab};
const u32 var7f1a8478[] = {0x461c4000};
const u32 var7f1a847c[] = {0x40490fdb};
const u32 var7f1a8480[] = {0x3dcccccd};
const u32 var7f1a8484[] = {0x3f666666};
const u32 var7f1a8488[] = {0x3ecccccd};
const u32 var7f1a848c[] = {0x3ecccccd};
const u32 var7f1a8490[] = {0x40490fdb};
const u32 var7f1a8494[] = {0x3fc90fdb};
const u32 var7f1a8498[] = {0x40490fdb};
const u32 var7f1a849c[] = {0x3eb33333};
const u32 var7f1a84a0[] = {0x3e4ccccd};
const u32 var7f1a84a4[] = {0x3faaaaab};
const u32 var7f1a84a8[] = {0x461c4000};
const u32 var7f1a84ac[] = {0x40490fdb};
const u32 var7f1a84b0[] = {0x3fc90fdb};
const u32 var7f1a84b4[] = {0x3dcccccd};
const u32 var7f1a84b8[] = {0x3e4ccccd};
const u32 var7f1a84bc[] = {0x3fc90fdb};
const u32 var7f1a84c0[] = {0x3fba2e8c};
const u32 var7f1a84c4[] = {0x3faaaaab};
const u32 var7f1a84c8[] = {0x461c4000};
const u32 var7f1a84cc[] = {0x7f01a8e0};
const u32 var7f1a84d0[] = {0x7f01a8fc};
const u32 var7f1a84d4[] = {0x7f01a918};
const u32 var7f1a84d8[] = {0x7f01a934};
const u32 var7f1a84dc[] = {0x7f01a950};
const u32 var7f1a84e0[] = {0x7f01a984};
const u32 var7f1a84e4[] = {0x7f01a96c};
const u32 var7f1a84e8[] = {0x7f01aa48};
const u32 var7f1a84ec[] = {0x7f01aa5c};
const u32 var7f1a84f0[] = {0x7f01aa70};
const u32 var7f1a84f4[] = {0x7f01aa84};
const u32 var7f1a84f8[] = {0x7f01aa98};
const u32 var7f1a84fc[] = {0x7f01aaac};
const u32 var7f1a8500[] = {0x7f01aac0};
const u32 var7f1a8504[] = {0x7f01ab14};
const u32 var7f1a8508[] = {0x7f01ab24};
const u32 var7f1a850c[] = {0x7f01ab34};
const u32 var7f1a8510[] = {0x7f01ab44};
const u32 var7f1a8514[] = {0x7f01ab54};
const u32 var7f1a8518[] = {0x7f01ab74};
const u32 var7f1a851c[] = {0x7f01ab64};
const u32 var7f1a8520[] = {0x7f01ac20};
const u32 var7f1a8524[] = {0x7f01ac30};
const u32 var7f1a8528[] = {0x7f01ac40};
const u32 var7f1a852c[] = {0x7f01ac50};
const u32 var7f1a8530[] = {0x7f01ac60};
const u32 var7f1a8534[] = {0x7f01ac88};
const u32 var7f1a8538[] = {0x7f01ac70};
const u32 var7f1a853c[] = {0x7f01ac80};
const u32 var7f1a8540[] = {0x7f01ac80};
const u32 var7f1a8544[] = {0x7f01acd4};
const u32 var7f1a8548[] = {0x7f01acec};
const u32 var7f1a854c[] = {0x7f01ad1c};
const u32 var7f1a8550[] = {0x7f01ad04};
const u32 var7f1a8554[] = {0x7f01ad34};
const u32 var7f1a8558[] = {0x7f01ae88};
const u32 var7f1a855c[] = {0x7f01ae98};
const u32 var7f1a8560[] = {0x7f01aea8};
const u32 var7f1a8564[] = {0x7f01aeb8};
const u32 var7f1a8568[] = {0x7f01aed8};
const u32 var7f1a856c[] = {0x7f01aee0};
const u32 var7f1a8570[] = {0x7f01aee0};
const u32 var7f1a8574[] = {0x7f01aec8};
const u32 var7f1a8578[] = {0x7f01aec8};
const u32 var7f1a857c[] = {0x7f01af34};
const u32 var7f1a8580[] = {0x7f01af44};
const u32 var7f1a8584[] = {0x7f01af54};
const u32 var7f1a8588[] = {0x7f01af64};
const u32 var7f1a858c[] = {0x7f01af84};
const u32 var7f1a8590[] = {0x7f01afa0};
const u32 var7f1a8594[] = {0x7f01af94};
const u32 var7f1a8598[] = {0x7f01af74};
const u32 var7f1a859c[] = {0x7f01af74};
const u32 var7f1a85a0[] = {0x00000000};
const u32 var7f1a85a4[] = {0x3e89374c};
const u32 var7f1a85a8[] = {0x4196cbe4};
const u32 var7f1a85ac[] = {0x4196cbe4};

const char var7f1a85b0[] = "lvup: %d\n";
const char var7f1a85bc[] = "file id %x-%x";
const char var7f1a85cc[] = " ticking: ";
const char var7f1a85d8[] = "1";
const char var7f1a85dc[] = "0";
const char var7f1a85e0[] = "Live: %d\n";
const char var7f1a85ec[] = "current:";
const char var7f1a85f8[] = " numactive %d ";

const u32 var7f1a8608[] = {0x3ca3d70a};
const u32 var7f1a860c[] = {0x7f01d5b4};
const u32 var7f1a8610[] = {0x7f01d5b4};
const u32 var7f1a8614[] = {0x7f01d5b4};
const u32 var7f1a8618[] = {0x7f01d5e8};
const u32 var7f1a861c[] = {0x7f01d5b4};
const u32 var7f1a8620[] = {0x7f01d5b4};
const u32 var7f1a8624[] = {0x7f01d5b4};
const u32 var7f1a8628[] = {0x7f01d5e8};
const u32 var7f1a862c[] = {0x7f01d5e8};
const u32 var7f1a8630[] = {0x7f01d5b4};
const u32 var7f1a8634[] = {0x7f01d5b4};
const u32 var7f1a8638[] = {0x7f01d5e8};
const u32 var7f1a863c[] = {0x7f01d5b4};

const char var7f1a8640[] = "wettick";
const char var7f1a8648[] = "windspeed";

const u32 var7f1a8654[] = {0x00000000};
const u32 var7f1a8658[] = {0x00000000};
const u32 var7f1a865c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f015470
/*  f015470:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f015474:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f015478:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f01547c:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f015480:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f015484:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f015488:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f01548c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f015490:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f015494:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f015498:	11c00003 */ 	beqz	$t6,.L0f0154a8
/*  f01549c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0154a0:	10000002 */ 	beqz	$zero,.L0f0154ac
/*  f0154a4:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0154a8:
/*  f0154a8:	00003825 */ 	or	$a3,$zero,$zero
.L0f0154ac:
/*  f0154ac:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0154b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0154b4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0154b8:	11e00003 */ 	beqz	$t7,.L0f0154c8
/*  f0154bc:	00145880 */ 	sll	$t3,$s4,0x2
/*  f0154c0:	10000001 */ 	beqz	$zero,.L0f0154c8
/*  f0154c4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0154c8:
/*  f0154c8:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f0154cc:	3c0c800a */ 	lui	$t4,%hi(g_Vars)
/*  f0154d0:	258c9fc0 */ 	addiu	$t4,$t4,%lo(g_Vars)
/*  f0154d4:	13000003 */ 	beqz	$t8,.L0f0154e4
/*  f0154d8:	016c9021 */ 	addu	$s2,$t3,$t4
/*  f0154dc:	10000001 */ 	beqz	$zero,.L0f0154e4
/*  f0154e0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0154e4:
/*  f0154e4:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f0154e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0154ec:	24130f48 */ 	addiu	$s3,$zero,0xf48
/*  f0154f0:	13200003 */ 	beqz	$t9,.L0f015500
/*  f0154f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0154f8:	10000001 */ 	beqz	$zero,.L0f015500
/*  f0154fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f015500:
/*  f015500:	00434021 */ 	addu	$t0,$v0,$v1
/*  f015504:	01054821 */ 	addu	$t1,$t0,$a1
/*  f015508:	01275021 */ 	addu	$t2,$t1,$a3
/*  f01550c:	19400030 */ 	blez	$t2,.L0f0155d0
/*  f015510:	00008825 */ 	or	$s1,$zero,$zero
.L0f015514:
/*  f015514:	8e4d0064 */ 	lw	$t5,0x64($s2)
.L0f015518:
/*  f015518:	01b18021 */ 	addu	$s0,$t5,$s1
/*  f01551c:	8e040804 */ 	lw	$a0,0x804($s0)
/*  f015520:	26100638 */ 	addiu	$s0,$s0,0x638
/*  f015524:	50800008 */ 	beqzl	$a0,.L0f015548
/*  f015528:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f01552c:	0c00cdfc */ 	jal	func000337f0
/*  f015530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015534:	50400004 */ 	beqzl	$v0,.L0f015548
/*  f015538:	263107a4 */ 	addiu	$s1,$s1,0x7a4
/*  f01553c:	0c00cec9 */ 	jal	func00033b24
/*  f015540:	8e0401cc */ 	lw	$a0,0x1cc($s0)
/*  f015544:	263107a4 */ 	addiu	$s1,$s1,0x7a4
.L0f015548:
/*  f015548:	5633fff3 */ 	bnel	$s1,$s3,.L0f015518
/*  f01554c:	8e4d0064 */ 	lw	$t5,0x64($s2)
/*  f015550:	3c02800a */ 	lui	$v0,0x800a
/*  f015554:	8c42a02c */ 	lw	$v0,-0x5fd4($v0)
/*  f015558:	3c03800a */ 	lui	$v1,0x800a
/*  f01555c:	3c04800a */ 	lui	$a0,0x800a
/*  f015560:	3c06800a */ 	lui	$a2,0x800a
/*  f015564:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f015568:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f01556c:	8cc6a030 */ 	lw	$a2,-0x5fd0($a2)
/*  f015570:	8c84a024 */ 	lw	$a0,-0x5fdc($a0)
/*  f015574:	10400003 */ 	beqz	$v0,.L0f015584
/*  f015578:	8c63a028 */ 	lw	$v1,-0x5fd8($v1)
/*  f01557c:	10000002 */ 	beqz	$zero,.L0f015588
/*  f015580:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f015584:
/*  f015584:	00003825 */ 	or	$a3,$zero,$zero
.L0f015588:
/*  f015588:	10600003 */ 	beqz	$v1,.L0f015598
/*  f01558c:	00002825 */ 	or	$a1,$zero,$zero
/*  f015590:	10000001 */ 	beqz	$zero,.L0f015598
/*  f015594:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f015598:
/*  f015598:	10800003 */ 	beqz	$a0,.L0f0155a8
/*  f01559c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0155a0:	10000001 */ 	beqz	$zero,.L0f0155a8
/*  f0155a4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0155a8:
/*  f0155a8:	10c00003 */ 	beqz	$a2,.L0f0155b8
/*  f0155ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f0155b0:	10000001 */ 	beqz	$zero,.L0f0155b8
/*  f0155b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0155b8:
/*  f0155b8:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0155bc:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0155c0:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0155c4:	0298082a */ 	slt	$at,$s4,$t8
/*  f0155c8:	5420ffd2 */ 	bnezl	$at,.L0f015514
/*  f0155cc:	00008825 */ 	or	$s1,$zero,$zero
.L0f0155d0:
/*  f0155d0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0155d4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0155d8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0155dc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0155e0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0155e4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0155e8:	03e00008 */ 	jr	$ra
/*  f0155ec:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0155f0
/*  f0155f0:	44852000 */ 	mtc1	$a1,$f4
/*  f0155f4:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f0155f8:	3c018006 */ 	lui	$at,0x8006
/*  f0155fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f015600:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f015604:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f015608:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f01560c:	3c0f8006 */ 	lui	$t7,%hi(var80061360)
/*  f015610:	25ef1360 */ 	addiu	$t7,$t7,%lo(var80061360)
/*  f015614:	e4262468 */ 	swc1	$f6,0x2468($at)
/*  f015618:	3c0e0600 */ 	lui	$t6,0x600
/*  f01561c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015620:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f015624:	3c188006 */ 	lui	$t8,0x8006
/*  f015628:	8f182494 */ 	lw	$t8,0x2494($t8)
/*  f01562c:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f015630:	02001025 */ 	or	$v0,$s0,$zero
/*  f015634:	13000007 */ 	beqz	$t8,.L0f015654
/*  f015638:	3c19ba00 */ 	lui	$t9,0xba00
/*  f01563c:	0fc06bf0 */ 	jal	func0f01afc0
/*  f015640:	02002025 */ 	or	$a0,$s0,$zero
/*  f015644:	3c018006 */ 	lui	$at,0x8006
/*  f015648:	00408025 */ 	or	$s0,$v0,$zero
/*  f01564c:	10000023 */ 	beqz	$zero,.L0f0156dc
/*  f015650:	ac202494 */ 	sw	$zero,0x2494($at)
.L0f015654:
/*  f015654:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f015658:	3c0e0030 */ 	lui	$t6,0x30
/*  f01565c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f015660:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f015664:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015668:	afb000fc */ 	sw	$s0,0xfc($sp)
/*  f01566c:	0c002f02 */ 	jal	func0000bc08
/*  f015670:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015674:	244fffff */ 	addiu	$t7,$v0,-1
/*  f015678:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f01567c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f015680:	3c01ff10 */ 	lui	$at,0xff10
/*  f015684:	0301c825 */ 	or	$t9,$t8,$at
/*  f015688:	0c002ac7 */ 	jal	func0000ab1c
/*  f01568c:	add90000 */ 	sw	$t9,0x0($t6)
/*  f015690:	0c012d20 */ 	jal	func0004b480
/*  f015694:	00402025 */ 	or	$a0,$v0,$zero
/*  f015698:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f01569c:	02001825 */ 	or	$v1,$s0,$zero
/*  f0156a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0156a4:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f0156a8:	3c190001 */ 	lui	$t9,0x1
/*  f0156ac:	37390001 */ 	ori	$t9,$t9,0x1
/*  f0156b0:	3c18f700 */ 	lui	$t8,0xf700
/*  f0156b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0156b8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0156bc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0156c0:	3c0f0032 */ 	lui	$t7,0x32
/*  f0156c4:	3c0ef66d */ 	lui	$t6,0xf66d
/*  f0156c8:	35cec5ec */ 	ori	$t6,$t6,0xc5ec
/*  f0156cc:	35ef0190 */ 	ori	$t7,$t7,0x190
/*  f0156d0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0156d4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0156d8:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0156dc:
/*  f0156dc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0156e0:	44814000 */ 	mtc1	$at,$f8
/*  f0156e4:	3c017f1b */ 	lui	$at,%hi(var7f1a83b0)
/*  f0156e8:	3c188006 */ 	lui	$t8,0x8006
/*  f0156ec:	8f182410 */ 	lw	$t8,0x2410($t8)
/*  f0156f0:	c42a83b0 */ 	lwc1	$f10,%lo(var7f1a83b0)($at)
/*  f0156f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0156f8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0156fc:	8dcecc80 */ 	lw	$t6,-0x3380($t6)
/*  f015700:	44818000 */ 	mtc1	$at,$f16
/*  f015704:	3c073faa */ 	lui	$a3,0x3faa
/*  f015708:	0018c980 */ 	sll	$t9,$t8,0x6
/*  f01570c:	34e7aaab */ 	ori	$a3,$a3,0xaaab
/*  f015710:	27a500f2 */ 	addiu	$a1,$sp,0xf2
/*  f015714:	3c064270 */ 	lui	$a2,0x4270
/*  f015718:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f01571c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f015720:	032e2021 */ 	addu	$a0,$t9,$t6
/*  f015724:	0c001289 */ 	jal	func00004a24
/*  f015728:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f01572c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f015730:	35ef000e */ 	ori	$t7,$t7,0xe
/*  f015734:	02001025 */ 	or	$v0,$s0,$zero
/*  f015738:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f01573c:	97b800f2 */ 	lhu	$t8,0xf2($sp)
/*  f015740:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015744:	3c190103 */ 	lui	$t9,0x103
/*  f015748:	37390040 */ 	ori	$t9,$t9,0x40
/*  f01574c:	02005825 */ 	or	$t3,$s0,$zero
/*  f015750:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f015754:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f015758:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01575c:	8dce2410 */ 	lw	$t6,0x2410($t6)
/*  f015760:	3c18800a */ 	lui	$t8,0x800a
/*  f015764:	8f18cc80 */ 	lw	$t8,-0x3380($t8)
/*  f015768:	000e7980 */ 	sll	$t7,$t6,0x6
/*  f01576c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f015770:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015774:	0c012d20 */ 	jal	func0004b480
/*  f015778:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f01577c:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f015780:	02001825 */ 	or	$v1,$s0,$zero
/*  f015784:	3c19b600 */ 	lui	$t9,0xb600
/*  f015788:	ad620004 */ 	sw	$v0,0x4($t3)
/*  f01578c:	240effff */ 	addiu	$t6,$zero,-1
/*  f015790:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f015794:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f015798:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01579c:	02004025 */ 	or	$t0,$s0,$zero
/*  f0157a0:	3c0fb700 */ 	lui	$t7,0xb700
/*  f0157a4:	3c180006 */ 	lui	$t8,0x6
/*  f0157a8:	37182204 */ 	ori	$t8,$t8,0x2204
/*  f0157ac:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f0157b0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f0157b4:	3c098006 */ 	lui	$t1,%hi(var8006246c)
/*  f0157b8:	3c0c8006 */ 	lui	$t4,%hi(var80062460)
/*  f0157bc:	258c2460 */ 	addiu	$t4,$t4,%lo(var80062460)
/*  f0157c0:	2529246c */ 	addiu	$t1,$t1,%lo(var8006246c)
/*  f0157c4:	c5320000 */ 	lwc1	$f18,0x0($t1)
/*  f0157c8:	c5800000 */ 	lwc1	$f0,0x0($t4)
/*  f0157cc:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f0157d0:	c5820004 */ 	lwc1	$f2,0x4($t4)
/*  f0157d4:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f0157d8:	c52a0008 */ 	lwc1	$f10,0x8($t1)
/*  f0157dc:	c58c0008 */ 	lwc1	$f12,0x8($t4)
/*  f0157e0:	3c0a8006 */ 	lui	$t2,%hi(var80062478)
/*  f0157e4:	254a2478 */ 	addiu	$t2,$t2,%lo(var80062478)
/*  f0157e8:	3c198006 */ 	lui	$t9,0x8006
/*  f0157ec:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f0157f0:	8f392410 */ 	lw	$t9,0x2410($t9)
/*  f0157f4:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0157f8:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f0157fc:	3c0f800a */ 	lui	$t7,0x800a
/*  f015800:	8defcc84 */ 	lw	$t7,-0x337c($t7)
/*  f015804:	c5440004 */ 	lwc1	$f4,0x4($t2)
/*  f015808:	c5460008 */ 	lwc1	$f6,0x8($t2)
/*  f01580c:	c5520000 */ 	lwc1	$f18,0x0($t2)
/*  f015810:	44050000 */ 	mfc1	$a1,$f0
/*  f015814:	44061000 */ 	mfc1	$a2,$f2
/*  f015818:	44076000 */ 	mfc1	$a3,$f12
/*  f01581c:	00197180 */ 	sll	$t6,$t9,0x6
/*  f015820:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015824:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f015828:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f01582c:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f015830:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f015834:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f015838:	0c0010a9 */ 	jal	func000042a4
/*  f01583c:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f015840:	3c180102 */ 	lui	$t8,0x102
/*  f015844:	37180040 */ 	ori	$t8,$t8,0x40
/*  f015848:	02001825 */ 	or	$v1,$s0,$zero
/*  f01584c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f015850:	3c198006 */ 	lui	$t9,0x8006
/*  f015854:	8f392410 */ 	lw	$t9,0x2410($t9)
/*  f015858:	3c0f800a */ 	lui	$t7,0x800a
/*  f01585c:	8defcc84 */ 	lw	$t7,-0x337c($t7)
/*  f015860:	00197180 */ 	sll	$t6,$t9,0x6
/*  f015864:	afa300dc */ 	sw	$v1,0xdc($sp)
/*  f015868:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01586c:	0c012d20 */ 	jal	func0004b480
/*  f015870:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f015874:	8fa300dc */ 	lw	$v1,0xdc($sp)
/*  f015878:	3c180100 */ 	lui	$t8,0x100
/*  f01587c:	37180040 */ 	ori	$t8,$t8,0x40
/*  f015880:	02005025 */ 	or	$t2,$s0,$zero
/*  f015884:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f015888:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f01588c:	3c198006 */ 	lui	$t9,0x8006
/*  f015890:	8f392410 */ 	lw	$t9,0x2410($t9)
/*  f015894:	3c0f800a */ 	lui	$t7,0x800a
/*  f015898:	8defcc88 */ 	lw	$t7,-0x3378($t7)
/*  f01589c:	00197180 */ 	sll	$t6,$t9,0x6
/*  f0158a0:	afaa00d8 */ 	sw	$t2,0xd8($sp)
/*  f0158a4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158a8:	0c012d20 */ 	jal	func0004b480
/*  f0158ac:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f0158b0:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f0158b4:	02003825 */ 	or	$a3,$s0,$zero
/*  f0158b8:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f0158bc:	3c198000 */ 	lui	$t9,0x8000
/*  f0158c0:	ad420004 */ 	sw	$v0,0x4($t2)
/*  f0158c4:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0158c8:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0158cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158d0:	02004025 */ 	or	$t0,$s0,$zero
/*  f0158d4:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f0158d8:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f0158dc:	3c0e0386 */ 	lui	$t6,0x386
/*  f0158e0:	3c0f8006 */ 	lui	$t7,%hi(var80062450)
/*  f0158e4:	25ef2450 */ 	addiu	$t7,$t7,%lo(var80062450)
/*  f0158e8:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0158ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158f0:	3c038006 */ 	lui	$v1,%hi(var80062448)
/*  f0158f4:	02004825 */ 	or	$t1,$s0,$zero
/*  f0158f8:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f0158fc:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f015900:	3c180388 */ 	lui	$t8,0x388
/*  f015904:	24632448 */ 	addiu	$v1,$v1,%lo(var80062448)
/*  f015908:	37180010 */ 	ori	$t8,$t8,0x10
/*  f01590c:	3c198006 */ 	lui	$t9,%hi(var80062488)
/*  f015910:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f015914:	ad230004 */ 	sw	$v1,0x4($t1)
/*  f015918:	27392488 */ 	addiu	$t9,$t9,%lo(var80062488)
/*  f01591c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f015920:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f015924:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015928:	ac810000 */ 	sw	$at,0x0($a0)
/*  f01592c:	8f2f0004 */ 	lw	$t7,0x4($t9)
/*  f015930:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f015934:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f015938:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f01593c:	8f210008 */ 	lw	$at,0x8($t9)
/*  f015940:	0c0011e4 */ 	jal	scaleTo1
/*  f015944:	ac810008 */ 	sw	$at,0x8($a0)
/*  f015948:	3c0142fe */ 	lui	$at,0x42fe
/*  f01594c:	44810000 */ 	mtc1	$at,$f0
/*  f015950:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f015954:	3c038006 */ 	lui	$v1,%hi(var80062448)
/*  f015958:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01595c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f015960:	24632448 */ 	addiu	$v1,$v1,%lo(var80062448)
/*  f015964:	93a20113 */ 	lbu	$v0,0x113($sp)
/*  f015968:	3c07e700 */ 	lui	$a3,0xe700
/*  f01596c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f015970:	a0600001 */ 	sb	$zero,0x1($v1)
/*  f015974:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f015978:	4458f800 */ 	cfc1	$t8,$31
/*  f01597c:	44cef800 */ 	ctc1	$t6,$31
/*  f015980:	a0600004 */ 	sb	$zero,0x4($v1)
/*  f015984:	a0600005 */ 	sb	$zero,0x5($v1)
/*  f015988:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f01598c:	a0600006 */ 	sb	$zero,0x6($v1)
/*  f015990:	a0620008 */ 	sb	$v0,0x8($v1)
/*  f015994:	a0620009 */ 	sb	$v0,0x9($v1)
/*  f015998:	444ef800 */ 	cfc1	$t6,$31
/*  f01599c:	a062000a */ 	sb	$v0,0xa($v1)
/*  f0159a0:	a062000c */ 	sb	$v0,0xc($v1)
/*  f0159a4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0159a8:	a062000d */ 	sb	$v0,0xd($v1)
/*  f0159ac:	11c00013 */ 	beqz	$t6,.L0f0159fc
/*  f0159b0:	a062000e */ 	sb	$v0,0xe($v1)
/*  f0159b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0159b8:	44818000 */ 	mtc1	$at,$f16
/*  f0159bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0159c0:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0159c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0159c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0159cc:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0159d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0159d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0159d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0159dc:	15c00005 */ 	bnez	$t6,.L0f0159f4
/*  f0159e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0159e4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0159e8:	3c018000 */ 	lui	$at,0x8000
/*  f0159ec:	10000007 */ 	beqz	$zero,.L0f015a0c
/*  f0159f0:	01c17025 */ 	or	$t6,$t6,$at
.L0f0159f4:
/*  f0159f4:	10000005 */ 	beqz	$zero,.L0f015a0c
/*  f0159f8:	240effff */ 	addiu	$t6,$zero,-1
.L0f0159fc:
/*  f0159fc:	440e8000 */ 	mfc1	$t6,$f16
/*  f015a00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015a04:	05c0fffb */ 	bltz	$t6,.L0f0159f4
/*  f015a08:	00000000 */ 	sll	$zero,$zero,0x0
.L0f015a0c:
/*  f015a0c:	44d8f800 */ 	ctc1	$t8,$31
/*  f015a10:	c7b200c4 */ 	lwc1	$f18,0xc4($sp)
/*  f015a14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f015a18:	02002025 */ 	or	$a0,$s0,$zero
/*  f015a1c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f015a20:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a24:	02002825 */ 	or	$a1,$s0,$zero
/*  f015a28:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f015a30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a34:	02004025 */ 	or	$t0,$s0,$zero
/*  f015a38:	4459f800 */ 	cfc1	$t9,$31
/*  f015a3c:	44cff800 */ 	ctc1	$t7,$31
/*  f015a40:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a44:	02001025 */ 	or	$v0,$s0,$zero
/*  f015a48:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f015a4c:	3c0b0701 */ 	lui	$t3,0x701
/*  f015a50:	a06e0010 */ 	sb	$t6,0x10($v1)
/*  f015a54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a58:	444ff800 */ 	cfc1	$t7,$31
/*  f015a5c:	3c09fd10 */ 	lui	$t1,0xfd10
/*  f015a60:	356b4050 */ 	ori	$t3,$t3,0x4050
/*  f015a64:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f015a68:	11e00013 */ 	beqz	$t7,.L0f015ab8
/*  f015a6c:	3c0af510 */ 	lui	$t2,0xf510
/*  f015a70:	3c014f00 */ 	lui	$at,0x4f00
/*  f015a74:	44813000 */ 	mtc1	$at,$f6
/*  f015a78:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f015a7c:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f015a80:	44cff800 */ 	ctc1	$t7,$31
/*  f015a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015a88:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f015a8c:	444ff800 */ 	cfc1	$t7,$31
/*  f015a90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015a94:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f015a98:	15e00005 */ 	bnez	$t7,.L0f015ab0
/*  f015a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015aa0:	440f3000 */ 	mfc1	$t7,$f6
/*  f015aa4:	3c018000 */ 	lui	$at,0x8000
/*  f015aa8:	10000007 */ 	beqz	$zero,.L0f015ac8
/*  f015aac:	01e17825 */ 	or	$t7,$t7,$at
.L0f015ab0:
/*  f015ab0:	10000005 */ 	beqz	$zero,.L0f015ac8
/*  f015ab4:	240fffff */ 	addiu	$t7,$zero,-1
.L0f015ab8:
/*  f015ab8:	440f3000 */ 	mfc1	$t7,$f6
/*  f015abc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015ac0:	05e0fffb */ 	bltz	$t7,.L0f015ab0
/*  f015ac4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f015ac8:
/*  f015ac8:	44d9f800 */ 	ctc1	$t9,$31
/*  f015acc:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f015ad0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f015ad4:	a06f0011 */ 	sb	$t7,0x11($v1)
/*  f015ad8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f015adc:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f015ae0:	3c1f073f */ 	lui	$ra,0x73f
/*  f015ae4:	3c014f00 */ 	lui	$at,0x4f00
/*  f015ae8:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f015aec:	240ff9fc */ 	addiu	$t7,$zero,-1540
/*  f015af0:	37fff100 */ 	ori	$ra,$ra,0xf100
/*  f015af4:	4458f800 */ 	cfc1	$t8,$31
/*  f015af8:	44cef800 */ 	ctc1	$t6,$31
/*  f015afc:	3c0ce600 */ 	lui	$t4,0xe600
/*  f015b00:	3c0df300 */ 	lui	$t5,0xf300
/*  f015b04:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f015b08:	444ef800 */ 	cfc1	$t6,$31
/*  f015b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015b10:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f015b14:	51c00013 */ 	beqzl	$t6,.L0f015b64
/*  f015b18:	440e8000 */ 	mfc1	$t6,$f16
/*  f015b1c:	44818000 */ 	mtc1	$at,$f16
/*  f015b20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f015b24:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f015b28:	44cef800 */ 	ctc1	$t6,$31
/*  f015b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015b30:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f015b34:	444ef800 */ 	cfc1	$t6,$31
/*  f015b38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015b3c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f015b40:	15c00005 */ 	bnez	$t6,.L0f015b58
/*  f015b44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015b48:	440e8000 */ 	mfc1	$t6,$f16
/*  f015b4c:	3c018000 */ 	lui	$at,0x8000
/*  f015b50:	10000007 */ 	beqz	$zero,.L0f015b70
/*  f015b54:	01c17025 */ 	or	$t6,$t6,$at
.L0f015b58:
/*  f015b58:	10000005 */ 	beqz	$zero,.L0f015b70
/*  f015b5c:	240effff */ 	addiu	$t6,$zero,-1
/*  f015b60:	440e8000 */ 	mfc1	$t6,$f16
.L0f015b64:
/*  f015b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015b68:	05c0fffb */ 	bltz	$t6,.L0f015b58
/*  f015b6c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f015b70:
/*  f015b70:	a06e0012 */ 	sb	$t6,0x12($v1)
/*  f015b74:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015b78:	ac870000 */ 	sw	$a3,0x0($a0)
/*  f015b7c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f015b80:	aca70000 */ 	sw	$a3,0x0($a1)
/*  f015b84:	44d8f800 */ 	ctc1	$t8,$31
/*  f015b88:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f015b8c:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f015b90:	3c18ba00 */ 	lui	$t8,0xba00
/*  f015b94:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f015b98:	3c0e0008 */ 	lui	$t6,0x8
/*  f015b9c:	ad0e0004 */ 	sw	$t6,0x4($t0)
/*  f015ba0:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f015ba4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f015ba8:	37391102 */ 	ori	$t9,$t9,0x1102
/*  f015bac:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f015bb0:	02001825 */ 	or	$v1,$s0,$zero
/*  f015bb4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015bb8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015bbc:	3c0fba00 */ 	lui	$t7,0xba00
/*  f015bc0:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f015bc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f015bc8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f015bcc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015bd0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015bd4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f015bd8:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f015bdc:	02002825 */ 	or	$a1,$s0,$zero
/*  f015be0:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f015be4:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015be8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f015bec:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f015bf0:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f015bf4:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f015bf8:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f015bfc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c00:	02003025 */ 	or	$a2,$s0,$zero
/*  f015c04:	3c0fba00 */ 	lui	$t7,0xba00
/*  f015c08:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f015c0c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c10:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f015c14:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f015c18:	02001025 */ 	or	$v0,$s0,$zero
/*  f015c1c:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f015c20:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c24:	02001825 */ 	or	$v1,$s0,$zero
/*  f015c28:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015c2c:	ac470000 */ 	sw	$a3,0x0($v0)
/*  f015c30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c34:	02002025 */ 	or	$a0,$s0,$zero
/*  f015c38:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015c3c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f015c40:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c44:	3c0ebb00 */ 	lui	$t6,0xbb00
/*  f015c48:	3c190800 */ 	lui	$t9,0x800
/*  f015c4c:	37390800 */ 	ori	$t9,$t9,0x800
/*  f015c50:	35ce0001 */ 	ori	$t6,$t6,0x1
/*  f015c54:	02002825 */ 	or	$a1,$s0,$zero
/*  f015c58:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015c5c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f015c60:	3c0f0200 */ 	lui	$t7,0x200
/*  f015c64:	25ef4dc8 */ 	addiu	$t7,$t7,0x4dc8
/*  f015c68:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c6c:	02004025 */ 	or	$t0,$s0,$zero
/*  f015c70:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f015c74:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f015c78:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c7c:	02001025 */ 	or	$v0,$s0,$zero
/*  f015c80:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c84:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f015c88:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f015c8c:	02001825 */ 	or	$v1,$s0,$zero
/*  f015c90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c94:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015c98:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f015c9c:	02002025 */ 	or	$a0,$s0,$zero
/*  f015ca0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ca4:	ac7f0004 */ 	sw	$ra,0x4($v1)
/*  f015ca8:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f015cac:	02002825 */ 	or	$a1,$s0,$zero
/*  f015cb0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015cb4:	ac870000 */ 	sw	$a3,0x0($a0)
/*  f015cb8:	3c0e0001 */ 	lui	$t6,0x1
/*  f015cbc:	3c18f510 */ 	lui	$t8,0xf510
/*  f015cc0:	37181000 */ 	ori	$t8,$t8,0x1000
/*  f015cc4:	35ce4050 */ 	ori	$t6,$t6,0x4050
/*  f015cc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ccc:	02003025 */ 	or	$a2,$s0,$zero
/*  f015cd0:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f015cd4:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f015cd8:	3c0f0007 */ 	lui	$t7,0x7
/*  f015cdc:	35efc07c */ 	ori	$t7,$t7,0xc07c
/*  f015ce0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ce4:	3c19f200 */ 	lui	$t9,0xf200
/*  f015ce8:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f015cec:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f015cf0:	02001025 */ 	or	$v0,$s0,$zero
/*  f015cf4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015cf8:	3c180600 */ 	lui	$t8,0x600
/*  f015cfc:	3c0e0200 */ 	lui	$t6,0x200
/*  f015d00:	25ce43f8 */ 	addiu	$t6,$t6,0x43f8
/*  f015d04:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f015d08:	02001825 */ 	or	$v1,$s0,$zero
/*  f015d0c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f015d10:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d14:	3c0f0200 */ 	lui	$t7,0x200
/*  f015d18:	25ef4468 */ 	addiu	$t7,$t7,0x4468
/*  f015d1c:	3c190600 */ 	lui	$t9,0x600
/*  f015d20:	02002025 */ 	or	$a0,$s0,$zero
/*  f015d24:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f015d28:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f015d2c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d30:	3c180200 */ 	lui	$t8,0x200
/*  f015d34:	27185dd0 */ 	addiu	$t8,$t8,0x5dd0
/*  f015d38:	02002825 */ 	or	$a1,$s0,$zero
/*  f015d3c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f015d40:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f015d44:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d48:	02004025 */ 	or	$t0,$s0,$zero
/*  f015d4c:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f015d50:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f015d54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d58:	02001025 */ 	or	$v0,$s0,$zero
/*  f015d5c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d60:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f015d64:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*  f015d68:	02001825 */ 	or	$v1,$s0,$zero
/*  f015d6c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d70:	ac5f0004 */ 	sw	$ra,0x4($v0)
/*  f015d74:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f015d78:	02002025 */ 	or	$a0,$s0,$zero
/*  f015d7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d80:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015d84:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f015d88:	3c190001 */ 	lui	$t9,0x1
/*  f015d8c:	3c0ef510 */ 	lui	$t6,0xf510
/*  f015d90:	35ce1000 */ 	ori	$t6,$t6,0x1000
/*  f015d94:	37394050 */ 	ori	$t9,$t9,0x4050
/*  f015d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f015d9c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f015da0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015da4:	3c180007 */ 	lui	$t8,0x7
/*  f015da8:	3718c07c */ 	ori	$t8,$t8,0xc07c
/*  f015dac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015db0:	3c0ff200 */ 	lui	$t7,0xf200
/*  f015db4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f015db8:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f015dbc:	02003025 */ 	or	$a2,$s0,$zero
/*  f015dc0:	3c190200 */ 	lui	$t9,0x200
/*  f015dc4:	27394700 */ 	addiu	$t9,$t9,0x4700
/*  f015dc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015dcc:	3c0e0600 */ 	lui	$t6,0x600
/*  f015dd0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f015dd4:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f015dd8:	02001825 */ 	or	$v1,$s0,$zero
/*  f015ddc:	3c180200 */ 	lui	$t8,0x200
/*  f015de0:	27184d28 */ 	addiu	$t8,$t8,0x4d28
/*  f015de4:	3c0f0600 */ 	lui	$t7,0x600
/*  f015de8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f015dec:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f015df0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f015df4:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f015df8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f015dfc:	03e00008 */ 	jr	$ra
/*  f015e00:	27bd0108 */ 	addiu	$sp,$sp,0x108
/*  f015e04:	3c018006 */ 	lui	$at,0x8006
/*  f015e08:	a0202414 */ 	sb	$zero,0x2414($at)
/*  f015e0c:	3c01445c */ 	lui	$at,0x445c
/*  f015e10:	44812000 */ 	mtc1	$at,$f4
/*  f015e14:	3c01800a */ 	lui	$at,0x800a
/*  f015e18:	3c0e0200 */ 	lui	$t6,0x200
/*  f015e1c:	e424cc8c */ 	swc1	$f4,-0x3374($at)
/*  f015e20:	3c01c220 */ 	lui	$at,0xc220
/*  f015e24:	44813000 */ 	mtc1	$at,$f6
/*  f015e28:	3c0f0200 */ 	lui	$t7,0x200
/*  f015e2c:	3c018006 */ 	lui	$at,0x8006
/*  f015e30:	25ef0000 */ 	addiu	$t7,$t7,0x0
/*  f015e34:	25ce65d0 */ 	addiu	$t6,$t6,0x65d0
/*  f015e38:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f015e3c:	01cf3023 */ 	subu	$a2,$t6,$t7
/*  f015e40:	e4262484 */ 	swc1	$f6,0x2484($at)
/*  f015e44:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f015e48:	3c02800a */ 	lui	$v0,%hi(var8009cc90)
/*  f015e4c:	3c018006 */ 	lui	$at,0x8006
/*  f015e50:	24c6003f */ 	addiu	$a2,$a2,0x3f
/*  f015e54:	2442cc90 */ 	addiu	$v0,$v0,%lo(var8009cc90)
/*  f015e58:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f015e5c:	ac202498 */ 	sw	$zero,0x2498($at)
/*  f015e60:	34d8003f */ 	ori	$t8,$a2,0x3f
/*  f015e64:	3c05007f */ 	lui	$a1,0x7f
/*  f015e68:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f015e6c:	24a5bdc0 */ 	addiu	$a1,$a1,-16960
/*  f015e70:	0c003504 */ 	jal	func0000d410
/*  f015e74:	3b06003f */ 	xori	$a2,$t8,0x3f
/*  f015e78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f015e7c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f015e80:	03e00008 */ 	jr	$ra
/*  f015e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015e88:	3c028006 */ 	lui	$v0,%hi(var80062410)
/*  f015e8c:	24422410 */ 	addiu	$v0,$v0,%lo(var80062410)
/*  f015e90:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f015e94:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f015e98:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f015e9c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f015ea0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f015ea4:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f015ea8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f015eac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f015eb0:	37390806 */ 	ori	$t9,$t9,0x806
/*  f015eb4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f015eb8:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f015ebc:	00801825 */ 	or	$v1,$a0,$zero
/*  f015ec0:	3c04800a */ 	lui	$a0,0x800a
/*  f015ec4:	8c84cc90 */ 	lw	$a0,-0x3370($a0)
/*  f015ec8:	0c012d20 */ 	jal	func0004b480
/*  f015ecc:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f015ed0:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f015ed4:	3c0a8006 */ 	lui	$t2,%hi(var80062414)
/*  f015ed8:	254a2414 */ 	addiu	$t2,$t2,%lo(var80062414)
/*  f015edc:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f015ee0:	91440000 */ 	lbu	$a0,0x0($t2)
/*  f015ee4:	3c098006 */ 	lui	$t1,%hi(var80062498)
/*  f015ee8:	25292498 */ 	addiu	$t1,$t1,%lo(var80062498)
/*  f015eec:	10800003 */ 	beqz	$a0,.L0f015efc
/*  f015ef0:	3c0c800a */ 	lui	$t4,%hi(g_Vars)
/*  f015ef4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f015ef8:	14810076 */ 	bne	$a0,$at,.L0f0160d4
.L0f015efc:
/*  f015efc:	258c9fc0 */ 	addiu	$t4,$t4,%lo(g_Vars)
/*  f015f00:	8d8f0034 */ 	lw	$t7,0x34($t4)
/*  f015f04:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f015f08:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f015f0c:	24040118 */ 	addiu	$a0,$zero,0x118
/*  f015f10:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f015f14:	01cb0019 */ 	multu	$t6,$t3
/*  f015f18:	01c0c025 */ 	or	$t8,$t6,$zero
/*  f015f1c:	44801000 */ 	mtc1	$zero,$f2
/*  f015f20:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f015f24:	3c18800a */ 	lui	$t8,0x800a
/*  f015f28:	3c0f8006 */ 	lui	$t7,0x8006
/*  f015f2c:	00001812 */ 	mflo	$v1
/*  f015f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f38:	0064001a */ 	div	$zero,$v1,$a0
/*  f015f3c:	14800002 */ 	bnez	$a0,.L0f015f48
/*  f015f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f44:	0007000d */ 	break	0x7
.L0f015f48:
/*  f015f48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f015f4c:	14810004 */ 	bne	$a0,$at,.L0f015f60
/*  f015f50:	3c018000 */ 	lui	$at,0x8000
/*  f015f54:	14610002 */ 	bne	$v1,$at,.L0f015f60
/*  f015f58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f5c:	0006000d */ 	break	0x6
.L0f015f60:
/*  f015f60:	00004012 */ 	mflo	$t0
/*  f015f64:	29010100 */ 	slti	$at,$t0,0x100
/*  f015f68:	14200002 */ 	bnez	$at,.L0f015f74
/*  f015f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f70:	01604025 */ 	or	$t0,$t3,$zero
.L0f015f74:
/*  f015f74:	05010002 */ 	bgez	$t0,.L0f015f80
/*  f015f78:	3c01fffd */ 	lui	$at,0xfffd
/*  f015f7c:	00004025 */ 	or	$t0,$zero,$zero
.L0f015f80:
/*  f015f80:	34218280 */ 	ori	$at,$at,0x8280
/*  f015f84:	0061c821 */ 	addu	$t9,$v1,$at
/*  f015f88:	0324001a */ 	div	$zero,$t9,$a0
/*  f015f8c:	14800002 */ 	bnez	$a0,.L0f015f98
/*  f015f90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015f94:	0007000d */ 	break	0x7
.L0f015f98:
/*  f015f98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f015f9c:	14810004 */ 	bne	$a0,$at,.L0f015fb0
/*  f015fa0:	3c018000 */ 	lui	$at,0x8000
/*  f015fa4:	17210002 */ 	bne	$t9,$at,.L0f015fb0
/*  f015fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015fac:	0006000d */ 	break	0x6
.L0f015fb0:
/*  f015fb0:	00006812 */ 	mflo	$t5
/*  f015fb4:	016d1023 */ 	subu	$v0,$t3,$t5
/*  f015fb8:	28410100 */ 	slti	$at,$v0,0x100
/*  f015fbc:	14200002 */ 	bnez	$at,.L0f015fc8
/*  f015fc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015fc4:	01601025 */ 	or	$v0,$t3,$zero
.L0f015fc8:
/*  f015fc8:	04430003 */ 	bgezl	$v0,.L0f015fd8
/*  f015fcc:	c5800044 */ 	lwc1	$f0,0x44($t4)
/*  f015fd0:	00001025 */ 	or	$v0,$zero,$zero
/*  f015fd4:	c5800044 */ 	lwc1	$f0,0x44($t4)
.L0f015fd8:
/*  f015fd8:	3c038006 */ 	lui	$v1,%hi(var80062484)
/*  f015fdc:	24632484 */ 	addiu	$v1,$v1,%lo(var80062484)
/*  f015fe0:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f015fe4:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f015fe8:	44061000 */ 	mfc1	$a2,$f2
/*  f015fec:	3c073f80 */ 	lui	$a3,0x3f80
/*  f015ff0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f015ff4:	e7a20010 */ 	swc1	$f2,0x10($sp)
/*  f015ff8:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f015ffc:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f016000:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f016004:	8def2410 */ 	lw	$t7,0x2410($t7)
/*  f016008:	8f18cc88 */ 	lw	$t8,-0x3378($t8)
/*  f01600c:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f016010:	000f7180 */ 	sll	$t6,$t7,0x6
/*  f016014:	0c001301 */ 	jal	func00004c04
/*  f016018:	01d82021 */ 	addu	$a0,$t6,$t8
/*  f01601c:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f016020:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f016024:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f016028:	3c01800a */ 	lui	$at,0x800a
/*  f01602c:	01020019 */ 	multu	$t0,$v0
/*  f016030:	c42acc8c */ 	lwc1	$f10,-0x3374($at)
/*  f016034:	3c098006 */ 	lui	$t1,%hi(var80062498)
/*  f016038:	3c0a8006 */ 	lui	$t2,%hi(var80062414)
/*  f01603c:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f016040:	254a2414 */ 	addiu	$t2,$t2,%lo(var80062414)
/*  f016044:	25292498 */ 	addiu	$t1,$t1,%lo(var80062498)
/*  f016048:	02002025 */ 	or	$a0,$s0,$zero
/*  f01604c:	44058000 */ 	mfc1	$a1,$f16
/*  f016050:	00006812 */ 	mflo	$t5
/*  f016054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01605c:	01ab001a */ 	div	$zero,$t5,$t3
/*  f016060:	00003012 */ 	mflo	$a2
/*  f016064:	15600002 */ 	bnez	$t3,.L0f016070
/*  f016068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01606c:	0007000d */ 	break	0x7
.L0f016070:
/*  f016070:	2401ffff */ 	addiu	$at,$zero,-1
/*  f016074:	15610004 */ 	bne	$t3,$at,.L0f016088
/*  f016078:	3c018000 */ 	lui	$at,0x8000
/*  f01607c:	15a10002 */ 	bne	$t5,$at,.L0f016088
/*  f016080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016084:	0006000d */ 	break	0x6
.L0f016088:
/*  f016088:	0fc0557c */ 	jal	func0f0155f0
/*  f01608c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016090:	3c098006 */ 	lui	$t1,%hi(var80062498)
/*  f016094:	25292498 */ 	addiu	$t1,$t1,%lo(var80062498)
/*  f016098:	8d230000 */ 	lw	$v1,0x0($t1)
/*  f01609c:	3c0a8006 */ 	lui	$t2,%hi(var80062414)
/*  f0160a0:	254a2414 */ 	addiu	$t2,$t2,%lo(var80062414)
/*  f0160a4:	28610410 */ 	slti	$at,$v1,0x410
/*  f0160a8:	1420000a */ 	bnez	$at,.L0f0160d4
/*  f0160ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0160b0:	28610488 */ 	slti	$at,$v1,0x488
/*  f0160b4:	54200008 */ 	bnezl	$at,.L0f0160d8
/*  f0160b8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0160bc:	914f0000 */ 	lbu	$t7,0x0($t2)
/*  f0160c0:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f0160c4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0160c8:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f0160cc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0160d0:	a1590000 */ 	sb	$t9,0x0($t2)
.L0f0160d4:
/*  f0160d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0160d8:
/*  f0160d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f0160dc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0160e0:	03e00008 */ 	jr	$ra
/*  f0160e4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0160e8:	3c028006 */ 	lui	$v0,0x8006
/*  f0160ec:	90422414 */ 	lbu	$v0,0x2414($v0)
/*  f0160f0:	384e0002 */ 	xori	$t6,$v0,0x2
/*  f0160f4:	03e00008 */ 	jr	$ra
/*  f0160f8:	2dc20001 */ 	sltiu	$v0,$t6,0x1
/*  f0160fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f016100
/*  f016100:	3c0e800a */ 	lui	$t6,0x800a
/*  f016104:	8dcea24c */ 	lw	$t6,-0x5db4($t6)
/*  f016108:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f01610c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f016110:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f016114:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f016118:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f01611c:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f016120:	0fc44c6b */ 	jal	func0f1131ac
/*  f016124:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f016128:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f01612c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f016130:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f016134:	15e10003 */ 	bne	$t7,$at,.L0f016144
/*  f016138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01613c:	10000001 */ 	beqz	$zero,.L0f016144
/*  f016140:	8fa40024 */ 	lw	$a0,0x24($sp)
.L0f016144:
/*  f016144:	0fc28857 */ 	jal	func0f0a215c
/*  f016148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01614c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f016150:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f016154:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f016158:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01615c:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f016160:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f016164:	03e00008 */ 	jr	$ra
/*  f016168:	00000000 */ 	sll	$zero,$zero,0x0
);

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

GLOBAL_ASM(
glabel func0f016404
/*  f016404:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f016408:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01640c:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f016410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016414:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f016418:	3c018006 */ 	lui	$at,0x8006
/*  f01641c:	ac2e24f4 */ 	sw	$t6,0x24f4($at)
/*  f016420:	3c018006 */ 	lui	$at,0x8006
/*  f016424:	ac2024c4 */ 	sw	$zero,0x24c4($at)
/*  f016428:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01642c:	3c018006 */ 	lui	$at,0x8006
/*  f016430:	ac2024a8 */ 	sw	$zero,0x24a8($at)
/*  f016434:	3c018006 */ 	lui	$at,0x8006
/*  f016438:	ac2024ac */ 	sw	$zero,0x24ac($at)
/*  f01643c:	03e00008 */ 	jr	$ra
/*  f016440:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

void func0f016444(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f01644c
/*  f01644c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f016450:	3c014270 */ 	lui	$at,0x4270
/*  f016454:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f016458:	44816000 */ 	mtc1	$at,$f12
/*  f01645c:	0c002f4c */ 	jal	func0000bd30
/*  f016460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016464:	3c017f1b */ 	lui	$at,%hi(var7f1a83c0)
/*  f016468:	0c002f5f */ 	jal	func0000bd7c
/*  f01646c:	c42c83c0 */ 	lwc1	$f12,%lo(var7f1a83c0)($at)
/*  f016470:	3c0142c8 */ 	lui	$at,0x42c8
/*  f016474:	44816000 */ 	mtc1	$at,$f12
/*  f016478:	3c017f1b */ 	lui	$at,%hi(var7f1a83c4)
/*  f01647c:	0c002fa1 */ 	jal	func0000be84
/*  f016480:	c42e83c4 */ 	lwc1	$f14,%lo(var7f1a83c4)($at)
/*  f016484:	0c002f48 */ 	jal	func0000bd20
/*  f016488:	00002025 */ 	or	$a0,$zero,$zero
/*  f01648c:	3c028006 */ 	lui	$v0,%hi(var800624c4)
/*  f016490:	244224c4 */ 	addiu	$v0,$v0,%lo(var800624c4)
/*  f016494:	3c0f800a */ 	lui	$t7,0x800a
/*  f016498:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f01649c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0164a0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0164a4:	2b0100b5 */ 	slti	$at,$t8,0xb5
/*  f0164a8:	14200003 */ 	bnez	$at,.L0f0164b8
/*  f0164ac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0164b0:	0fc069f9 */ 	jal	func0f01a7e4
/*  f0164b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0164b8:
/*  f0164b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0164bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0164c0:	03e00008 */ 	jr	$ra
/*  f0164c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0164c8
/*  f0164c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0164cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0164d0:	3c018006 */ 	lui	$at,0x8006
/*  f0164d4:	ac2024c4 */ 	sw	$zero,0x24c4($at)
/*  f0164d8:	0c0027b1 */ 	jal	func00009ec4
/*  f0164dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0164e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0164e4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0164e8:	03e00008 */ 	jr	$ra
/*  f0164ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0164f0
/*  f0164f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0164f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0164f8:	3c018006 */ 	lui	$at,0x8006
/*  f0164fc:	0c0026ac */ 	jal	func00009ab0
/*  f016500:	ac2024e8 */ 	sw	$zero,0x24e8($at)
/*  f016504:	0c002aac */ 	jal	func0000aab0
/*  f016508:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f01650c:	0c0027b1 */ 	jal	func00009ec4
/*  f016510:	00002025 */ 	or	$a0,$zero,$zero
/*  f016514:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f016518:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01651c:	03e00008 */ 	jr	$ra
/*  f016520:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f016524
/*  f016524:	3c028006 */ 	lui	$v0,%hi(var800624c4)
/*  f016528:	244224c4 */ 	addiu	$v0,$v0,%lo(var800624c4)
/*  f01652c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f016530:	3c0142c8 */ 	lui	$at,0x42c8
/*  f016534:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f016538:	44816000 */ 	mtc1	$at,$f12
/*  f01653c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f016540:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f016544:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f016548:	3c017f1b */ 	lui	$at,%hi(var7f1a83c8)
/*  f01654c:	0c002fa1 */ 	jal	func0000be84
/*  f016550:	c42e83c8 */ 	lwc1	$f14,%lo(var7f1a83c8)($at)
/*  f016554:	0c002f48 */ 	jal	func0000bd20
/*  f016558:	00002025 */ 	or	$a0,$zero,$zero
/*  f01655c:	3c188006 */ 	lui	$t8,0x8006
/*  f016560:	8f1824c4 */ 	lw	$t8,0x24c4($t8)
/*  f016564:	2b010007 */ 	slti	$at,$t8,0x7
/*  f016568:	5420000d */ 	bnezl	$at,.L0f0165a0
/*  f01656c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f016570:	0c005013 */ 	jal	func0001404c
/*  f016574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016578:	30590001 */ 	andi	$t9,$v0,0x1
/*  f01657c:	17200005 */ 	bnez	$t9,.L0f016594
/*  f016580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f016584:	0fc069f9 */ 	jal	func0f01a7e4
/*  f016588:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f01658c:	10000004 */ 	beqz	$zero,.L0f0165a0
/*  f016590:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f016594:
/*  f016594:	0fc069f9 */ 	jal	func0f01a7e4
/*  f016598:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f01659c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0165a0:
/*  f0165a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0165a4:	03e00008 */ 	jr	$ra
/*  f0165a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0165ac
/*  f0165ac:	3c028006 */ 	lui	$v0,0x8006
/*  f0165b0:	8c4224c4 */ 	lw	$v0,0x24c4($v0)
/*  f0165b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0165b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0165bc:	28410003 */ 	slti	$at,$v0,0x3
/*  f0165c0:	14200006 */ 	bnez	$at,.L0f0165dc
/*  f0165c4:	28410006 */ 	slti	$at,$v0,0x6
/*  f0165c8:	50200005 */ 	beqzl	$at,.L0f0165e0
/*  f0165cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0165d0:	0fc06bf0 */ 	jal	func0f01afc0
/*  f0165d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0165d8:	00402025 */ 	or	$a0,$v0,$zero
.L0f0165dc:
/*  f0165dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0165e0:
/*  f0165e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0165e4:	00801025 */ 	or	$v0,$a0,$zero
/*  f0165e8:	03e00008 */ 	jr	$ra
/*  f0165ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0165f0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0165f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0165f8:	8dcefb1c */ 	lw	$t6,-0x4e4($t6)
/*  f0165fc:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f016600:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f016604:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f016608:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f01660c:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f016610:	3c078008 */ 	lui	$a3,0x8008
/*  f016614:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f016618:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f01661c:	8ce7fb20 */ 	lw	$a3,-0x4e0($a3)
/*  f016620:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f016624:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f016628:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f01662c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f016630:	0fc55cbe */ 	jal	func0f1572f8
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
/*  f0166d4:	0fc5580f */ 	jal	func0f15603c
/*  f0166d8:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0166dc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0166e0:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0166e4:	03e00008 */ 	jr	$ra
/*  f0166e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0166ec
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
/*  f016754:	3c0c8006 */ 	lui	$t4,0x8006
/*  f016758:	adc10000 */ 	sw	$at,0x0($t6)
/*  f01675c:	8d8c272c */ 	lw	$t4,0x272c($t4)
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
/*  f0167d8:	3c128008 */ 	lui	$s2,0x8008
/*  f0167dc:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f0167e0:	10000024 */ 	beqz	$zero,.L0f016874
/*  f0167e4:	8e52fb0c */ 	lw	$s2,-0x4f4($s2)
/*  f0167e8:	3c118008 */ 	lui	$s1,0x8008
/*  f0167ec:	3c128008 */ 	lui	$s2,0x8008
/*  f0167f0:	8e31fb18 */ 	lw	$s1,-0x4e8($s1)
/*  f0167f4:	1000001f */ 	beqz	$zero,.L0f016874
/*  f0167f8:	8e52fb14 */ 	lw	$s2,-0x4ec($s2)
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
/*  f016828:	3c188009 */ 	lui	$t8,0x8009
/*  f01682c:	93180af0 */ 	lbu	$t8,0xaf0($t8)
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
/*  f016858:	3c128008 */ 	lui	$s2,0x8008
/*  f01685c:	8fd10000 */ 	lw	$s1,0x0($s8)
/*  f016860:	8e52fb0c */ 	lw	$s2,-0x4f4($s2)
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
/*  f016960:	3c05800b */ 	lui	$a1,0x800b
/*  f016964:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f016968:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f01696c:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
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
/*  f016b38:	3c05800b */ 	lui	$a1,0x800b
/*  f016b3c:	adf90004 */ 	sw	$t9,0x4($t7)
/*  f016b40:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f016b44:	8ca5b5a8 */ 	lw	$a1,-0x4a58($a1)
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
/*  f016c8c:	0fc5b9f1 */ 	jal	textGet
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
/*  f016cd4:	0fc5580f */ 	jal	func0f15603c
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

GLOBAL_ASM(
glabel func0f016d34
/*  f016d34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f016d38:	3c018006 */ 	lui	$at,0x8006
/*  f016d3c:	3c0f8006 */ 	lui	$t7,%hi(var80062738)
/*  f016d40:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f016d44:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f016d48:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f016d4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f016d50:	ac2024c4 */ 	sw	$zero,0x24c4($at)
/*  f016d54:	25ef2738 */ 	addiu	$t7,$t7,%lo(var80062738)
/*  f016d58:	8de10000 */ 	lw	$at,0x0($t7)
/*  f016d5c:	3c10800a */ 	lui	$s0,0x800a
/*  f016d60:	8e10cca0 */ 	lw	$s0,-0x3360($s0)
/*  f016d64:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f016d68:	adc10000 */ 	sw	$at,0x0($t6)
/*  f016d6c:	8de10008 */ 	lw	$at,0x8($t7)
/*  f016d70:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f016d74:	3c118008 */ 	lui	$s1,%hi(proptable)
/*  f016d78:	2631b06c */ 	addiu	$s1,$s1,%lo(proptable)
/*  f016d7c:	3c060004 */ 	lui	$a2,0x4
/*  f016d80:	adc10008 */ 	sw	$at,0x8($t6)
/*  f016d84:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f016d88:	96240244 */ 	lhu	$a0,0x244($s1)
/*  f016d8c:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f016d90:	00003825 */ 	or	$a3,$zero,$zero
/*  f016d94:	0fc69de5 */ 	jal	func0f1a7794
/*  f016d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f016d9c:	ae220240 */ 	sw	$v0,0x240($s1)
/*  f016da0:	0fc59ca0 */ 	jal	func0f167280
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
/*  f016dd4:	3c038006 */ 	lui	$v1,%hi(var800624f8)
/*  f016dd8:	246324f8 */ 	addiu	$v1,$v1,%lo(var800624f8)
/*  f016ddc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016de0:	00402025 */ 	or	$a0,$v0,$zero
/*  f016de4:	0c006bd6 */ 	jal	func0001af58
/*  f016de8:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016dec:	3c048006 */ 	lui	$a0,0x8006
/*  f016df0:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
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
/*  f016e38:	0fc59ca0 */ 	jal	func0f167280
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
/*  f016e64:	3c038006 */ 	lui	$v1,%hi(var800624fc)
/*  f016e68:	246324fc */ 	addiu	$v1,$v1,%lo(var800624fc)
/*  f016e6c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f016e70:	00402025 */ 	or	$a0,$v0,$zero
/*  f016e74:	0c006bd6 */ 	jal	func0001af58
/*  f016e78:	3c053f80 */ 	lui	$a1,0x3f80
/*  f016e7c:	3c048006 */ 	lui	$a0,0x8006
/*  f016e80:	8c8424fc */ 	lw	$a0,0x24fc($a0)
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
/*  f016ec8:	0fc59ca0 */ 	jal	func0f167280
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
/*  f016f0c:	3c048006 */ 	lui	$a0,0x8006
/*  f016f10:	8c842508 */ 	lw	$a0,0x2508($a0)
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
/*  f016f58:	0fc59ca0 */ 	jal	func0f167280
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
/*  f016f9c:	3c048006 */ 	lui	$a0,0x8006
/*  f016fa0:	8c84250c */ 	lw	$a0,0x250c($a0)
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
/*  f017014:	3c01800a */ 	lui	$at,0x800a
/*  f017018:	ac20ccb8 */ 	sw	$zero,-0x3348($at)
/*  f01701c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f017020:	3c018006 */ 	lui	$at,0x8006
/*  f017024:	ac3024f4 */ 	sw	$s0,0x24f4($at)
/*  f017028:	0c005204 */ 	jal	func00014810
/*  f01702c:	00002025 */ 	or	$a0,$zero,$zero
/*  f017030:	3c188006 */ 	lui	$t8,0x8006
/*  f017034:	8f1824a8 */ 	lw	$t8,0x24a8($t8)
/*  f017038:	3c018006 */ 	lui	$at,0x8006
/*  f01703c:	ac302730 */ 	sw	$s0,0x2730($at)
/*  f017040:	3c018006 */ 	lui	$at,0x8006
/*  f017044:	13000003 */ 	beqz	$t8,.L0f017054
/*  f017048:	ac202734 */ 	sw	$zero,0x2734($at)
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

GLOBAL_ASM(
glabel func0f01706c
/*  f01706c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f017070:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f017074:	3c048006 */ 	lui	$a0,0x8006
/*  f017078:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f01707c:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
/*  f017080:	3c048006 */ 	lui	$a0,0x8006
/*  f017084:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f017088:	8c8424fc */ 	lw	$a0,0x24fc($a0)
/*  f01708c:	3c048006 */ 	lui	$a0,0x8006
/*  f017090:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f017094:	8c842508 */ 	lw	$a0,0x2508($a0)
/*  f017098:	3c048006 */ 	lui	$a0,0x8006
/*  f01709c:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f0170a0:	8c84250c */ 	lw	$a0,0x250c($a0)
/*  f0170a4:	0c005204 */ 	jal	func00014810
/*  f0170a8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0170ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0170b0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0170b4:	03e00008 */ 	jr	$ra
/*  f0170b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0170bc
/*  f0170bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0170c0:	3c014238 */ 	lui	$at,0x4238
/*  f0170c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0170c8:	44816000 */ 	mtc1	$at,$f12
/*  f0170cc:	0c002f4c */ 	jal	func0000bd30
/*  f0170d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0170d4:	3c017f1b */ 	lui	$at,%hi(var7f1a83e8)
/*  f0170d8:	0c002f5f */ 	jal	func0000bd7c
/*  f0170dc:	c42c83e8 */ 	lwc1	$f12,%lo(var7f1a83e8)($at)
/*  f0170e0:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0170e4:	44816000 */ 	mtc1	$at,$f12
/*  f0170e8:	3c017f1b */ 	lui	$at,%hi(var7f1a83ec)
/*  f0170ec:	0c002fa1 */ 	jal	func0000be84
/*  f0170f0:	c42e83ec */ 	lwc1	$f14,%lo(var7f1a83ec)($at)
/*  f0170f4:	0c002f48 */ 	jal	func0000bd20
/*  f0170f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0170fc:	3c0e8006 */ 	lui	$t6,0x8006
/*  f017100:	3c0f800a */ 	lui	$t7,0x800a
/*  f017104:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f017108:	8dce24c4 */ 	lw	$t6,0x24c4($t6)
/*  f01710c:	3c02800a */ 	lui	$v0,%hi(var8009ccb8)
/*  f017110:	3c018006 */ 	lui	$at,0x8006
/*  f017114:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f017118:	2442ccb8 */ 	addiu	$v0,$v0,%lo(var8009ccb8)
/*  f01711c:	ac3824c4 */ 	sw	$t8,0x24c4($at)
/*  f017120:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f017124:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f017128:	3c0a8006 */ 	lui	$t2,0x8006
/*  f01712c:	01194823 */ 	subu	$t1,$t0,$t9
/*  f017130:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f017134:	8d4a2734 */ 	lw	$t2,0x2734($t2)
/*  f017138:	3c0b800a */ 	lui	$t3,0x800a
/*  f01713c:	11400022 */ 	beqz	$t2,.L0f0171c8
/*  f017140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017144:	916b232c */ 	lbu	$t3,0x232c($t3)
/*  f017148:	3c0c8009 */ 	lui	$t4,0x8009
/*  f01714c:	1160001c */ 	beqz	$t3,.L0f0171c0
/*  f017150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f017154:	918c0af0 */ 	lbu	$t4,0xaf0($t4)
/*  f017158:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01715c:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f017160:	11810017 */ 	beq	$t4,$at,.L0f0171c0
/*  f017164:	3c018006 */ 	lui	$at,0x8006
/*  f017168:	0fc4ed98 */ 	jal	func0f13b660
/*  f01716c:	ac2d24b4 */ 	sw	$t5,0x24b4($at)
/*  f017170:	240e005c */ 	addiu	$t6,$zero,0x5c
/*  f017174:	3c018006 */ 	lui	$at,0x8006
/*  f017178:	ac2e24e4 */ 	sw	$t6,0x24e4($at)
/*  f01717c:	0fc068d5 */ 	jal	setNumPlayers
/*  f017180:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f017184:	3c048006 */ 	lui	$a0,0x8006
/*  f017188:	0c003a57 */ 	jal	func0000e95c
/*  f01718c:	8c8424e4 */ 	lw	$a0,0x24e4($a0)
/*  f017190:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f017194:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f017198:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f01719c:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f0171a0:	ac620298 */ 	sw	$v0,0x298($v1)
/*  f0171a4:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f0171a8:	0fc5b36a */ 	jal	setDifficulty
/*  f0171ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0171b0:	0c0027b1 */ 	jal	func00009ec4
/*  f0171b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0171b8:	10000003 */ 	beqz	$zero,.L0f0171c8
/*  f0171bc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0171c0:
/*  f0171c0:	0fc069f9 */ 	jal	func0f01a7e4
/*  f0171c4:	24040005 */ 	addiu	$a0,$zero,0x5
.L0f0171c8:
/*  f0171c8:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0171cc:	8def24a8 */ 	lw	$t7,0x24a8($t7)
/*  f0171d0:	3c188006 */ 	lui	$t8,0x8006
/*  f0171d4:	51e00008 */ 	beqzl	$t7,.L0f0171f8
/*  f0171d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0171dc:	8f1824c4 */ 	lw	$t8,0x24c4($t8)
/*  f0171e0:	2b01029b */ 	slti	$at,$t8,0x29b
/*  f0171e4:	54200004 */ 	bnezl	$at,.L0f0171f8
/*  f0171e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0171ec:	0fc069f9 */ 	jal	func0f01a7e4
/*  f0171f0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0171f4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0171f8:
/*  f0171f8:	0c005408 */ 	jal	func00015020
/*  f0171fc:	3405ffff */ 	dli	$a1,0xffff
/*  f017200:	1040000d */ 	beqz	$v0,.L0f017238
/*  f017204:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f017208:	3c028006 */ 	lui	$v0,%hi(var800624ac)
/*  f01720c:	244224ac */ 	addiu	$v0,$v0,%lo(var800624ac)
/*  f017210:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f017214:	3c098006 */ 	lui	$t1,0x8006
/*  f017218:	8d2924c4 */ 	lw	$t1,0x24c4($t1)
/*  f01721c:	3c018006 */ 	lui	$at,0x8006
/*  f017220:	ac2824a8 */ 	sw	$t0,0x24a8($at)
/*  f017224:	29210225 */ 	slti	$at,$t1,0x225
/*  f017228:	50200004 */ 	beqzl	$at,.L0f01723c
/*  f01722c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f017230:	0fc069f9 */ 	jal	func0f01a7e4
/*  f017234:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f017238:
/*  f017238:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01723c:
/*  f01723c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f017240:	03e00008 */ 	jr	$ra
/*  f017244:	00000000 */ 	sll	$zero,$zero,0x0
);

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

GLOBAL_ASM(
glabel func0f017980
/*  f017980:	44800000 */ 	mtc1	$zero,$f0
/*  f017984:	3c018006 */ 	lui	$at,0x8006
/*  f017988:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f01798c:	e42027a8 */ 	swc1	$f0,0x27a8($at)
/*  f017990:	3c018006 */ 	lui	$at,0x8006
/*  f017994:	e42027ac */ 	swc1	$f0,0x27ac($at)
/*  f017998:	3c018006 */ 	lui	$at,0x8006
/*  f01799c:	e42027b0 */ 	swc1	$f0,0x27b0($at)
/*  f0179a0:	3c018006 */ 	lui	$at,0x8006
/*  f0179a4:	e42027b4 */ 	swc1	$f0,0x27b4($at)
/*  f0179a8:	3c017f1b */ 	lui	$at,%hi(var7f1a83f0)
/*  f0179ac:	c42483f0 */ 	lwc1	$f4,%lo(var7f1a83f0)($at)
/*  f0179b0:	3c018006 */ 	lui	$at,0x8006
/*  f0179b4:	240e0225 */ 	addiu	$t6,$zero,0x225
/*  f0179b8:	e42427b8 */ 	swc1	$f4,0x27b8($at)
/*  f0179bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0179c0:	44813000 */ 	mtc1	$at,$f6
/*  f0179c4:	3c018006 */ 	lui	$at,0x8006
/*  f0179c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0179cc:	e42627bc */ 	swc1	$f6,0x27bc($at)
/*  f0179d0:	3c017f1b */ 	lui	$at,%hi(var7f1a83f4)
/*  f0179d4:	c42883f4 */ 	lwc1	$f8,%lo(var7f1a83f4)($at)
/*  f0179d8:	3c018006 */ 	lui	$at,0x8006
/*  f0179dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0179e0:	e42827f4 */ 	swc1	$f8,0x27f4($at)
/*  f0179e4:	3c017f1b */ 	lui	$at,%hi(var7f1a83f8)
/*  f0179e8:	c42a83f8 */ 	lwc1	$f10,%lo(var7f1a83f8)($at)
/*  f0179ec:	3c018006 */ 	lui	$at,0x8006
/*  f0179f0:	e42a2808 */ 	swc1	$f10,0x2808($at)
/*  f0179f4:	3c017f1b */ 	lui	$at,%hi(var7f1a83fc)
/*  f0179f8:	c43083fc */ 	lwc1	$f16,%lo(var7f1a83fc)($at)
/*  f0179fc:	3c018006 */ 	lui	$at,0x8006
/*  f017a00:	e4302814 */ 	swc1	$f16,0x2814($at)
/*  f017a04:	3c018006 */ 	lui	$at,0x8006
/*  f017a08:	e42027c4 */ 	swc1	$f0,0x27c4($at)
/*  f017a0c:	3c018006 */ 	lui	$at,0x8006
/*  f017a10:	e42027c8 */ 	swc1	$f0,0x27c8($at)
/*  f017a14:	3c018006 */ 	lui	$at,0x8006
/*  f017a18:	ac2427c0 */ 	sw	$a0,0x27c0($at)
/*  f017a1c:	3c018006 */ 	lui	$at,0x8006
/*  f017a20:	ac2027cc */ 	sw	$zero,0x27cc($at)
/*  f017a24:	3c018006 */ 	lui	$at,0x8006
/*  f017a28:	ac2027d0 */ 	sw	$zero,0x27d0($at)
/*  f017a2c:	3c018006 */ 	lui	$at,0x8006
/*  f017a30:	ac2027d4 */ 	sw	$zero,0x27d4($at)
/*  f017a34:	3c018006 */ 	lui	$at,0x8006
/*  f017a38:	ac2027d8 */ 	sw	$zero,0x27d8($at)
/*  f017a3c:	3c018006 */ 	lui	$at,0x8006
/*  f017a40:	ac2027dc */ 	sw	$zero,0x27dc($at)
/*  f017a44:	3c018006 */ 	lui	$at,0x8006
/*  f017a48:	ac2027e0 */ 	sw	$zero,0x27e0($at)
/*  f017a4c:	3c018006 */ 	lui	$at,0x8006
/*  f017a50:	ac2027e4 */ 	sw	$zero,0x27e4($at)
/*  f017a54:	3c018006 */ 	lui	$at,0x8006
/*  f017a58:	ac2027e8 */ 	sw	$zero,0x27e8($at)
/*  f017a5c:	3c018006 */ 	lui	$at,0x8006
/*  f017a60:	ac2027ec */ 	sw	$zero,0x27ec($at)
/*  f017a64:	3c018006 */ 	lui	$at,0x8006
/*  f017a68:	ac2027f0 */ 	sw	$zero,0x27f0($at)
/*  f017a6c:	3c018006 */ 	lui	$at,0x8006
/*  f017a70:	ac2427f8 */ 	sw	$a0,0x27f8($at)
/*  f017a74:	3c018006 */ 	lui	$at,0x8006
/*  f017a78:	ac2427fc */ 	sw	$a0,0x27fc($at)
/*  f017a7c:	3c018006 */ 	lui	$at,0x8006
/*  f017a80:	ac202800 */ 	sw	$zero,0x2800($at)
/*  f017a84:	3c018006 */ 	lui	$at,0x8006
/*  f017a88:	ac242804 */ 	sw	$a0,0x2804($at)
/*  f017a8c:	3c018006 */ 	lui	$at,0x8006
/*  f017a90:	ac24280c */ 	sw	$a0,0x280c($at)
/*  f017a94:	3c018006 */ 	lui	$at,0x8006
/*  f017a98:	ac242810 */ 	sw	$a0,0x2810($at)
/*  f017a9c:	3c018006 */ 	lui	$at,0x8006
/*  f017aa0:	ac2e24c4 */ 	sw	$t6,0x24c4($at)
/*  f017aa4:	3c018006 */ 	lui	$at,0x8006
/*  f017aa8:	0fc5b7ae */ 	jal	func0f16deb8
/*  f017aac:	ac202730 */ 	sw	$zero,0x2730($at)
/*  f017ab0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f017ab4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f017ab8:	03e00008 */ 	jr	$ra
/*  f017abc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f017ac0
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
/*  f017b0c:	3c188006 */ 	lui	$t8,0x8006
/*  f017b10:	3c048006 */ 	lui	$a0,%hi(var800627cc)
/*  f017b14:	adc10000 */ 	sw	$at,0x0($t6)
/*  f017b18:	8f1824c4 */ 	lw	$t8,0x24c4($t8)
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
/*  f017ba0:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017ba4:	e42a27ac */ 	swc1	$f10,0x27ac($at)
/*  f017ba8:	3c017f1b */ 	lui	$at,%hi(var7f1a8410)
/*  f017bac:	c4248410 */ 	lwc1	$f4,%lo(var7f1a8410)($at)
/*  f017bb0:	3c018006 */ 	lui	$at,0x8006
/*  f017bb4:	27ff27d8 */ 	addiu	$ra,$ra,0x27d8
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
/*  f017be0:	3c018006 */ 	lui	$at,0x8006
/*  f017be4:	ac2027c0 */ 	sw	$zero,0x27c0($at)
/*  f017be8:	3c018006 */ 	lui	$at,0x8006
/*  f017bec:	e42e27c8 */ 	swc1	$f14,0x27c8($at)
/*  f017bf0:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f017bf4:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f017bf8:	3c018006 */ 	lui	$at,0x8006
/*  f017bfc:	ac2027d0 */ 	sw	$zero,0x27d0($at)
/*  f017c00:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f017c04:	afe00000 */ 	sw	$zero,0x0($ra)
/*  f017c08:	3c018006 */ 	lui	$at,0x8006
/*  f017c0c:	ac2027dc */ 	sw	$zero,0x27dc($at)
/*  f017c10:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f017c14:	3c018006 */ 	lui	$at,0x8006
/*  f017c18:	ac2027e4 */ 	sw	$zero,0x27e4($at)
/*  f017c1c:	3c018006 */ 	lui	$at,0x8006
/*  f017c20:	ac2027e8 */ 	sw	$zero,0x27e8($at)
/*  f017c24:	3c018006 */ 	lui	$at,0x8006
/*  f017c28:	ac232804 */ 	sw	$v1,0x2804($at)
/*  f017c2c:	3c018006 */ 	lui	$at,0x8006
/*  f017c30:	ac2027ec */ 	sw	$zero,0x27ec($at)
/*  f017c34:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f017c38:	3c018006 */ 	lui	$at,0x8006
/*  f017c3c:	e43227f4 */ 	swc1	$f18,0x27f4($at)
/*  f017c40:	3c018006 */ 	lui	$at,0x8006
/*  f017c44:	ac2027fc */ 	sw	$zero,0x27fc($at)
/*  f017c48:	3c018006 */ 	lui	$at,0x8006
/*  f017c4c:	ac2f27f8 */ 	sw	$t7,0x27f8($at)
/*  f017c50:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f017c54:	3c018006 */ 	lui	$at,0x8006
/*  f017c58:	ac20280c */ 	sw	$zero,0x280c($at)
/*  f017c5c:	3c017f1b */ 	lui	$at,%hi(var7f1a8418)
/*  f017c60:	c4288418 */ 	lwc1	$f8,%lo(var7f1a8418)($at)
/*  f017c64:	3c018006 */ 	lui	$at,0x8006
/*  f017c68:	e4282808 */ 	swc1	$f8,0x2808($at)
/*  f017c6c:	3c018006 */ 	lui	$at,0x8006
/*  f017c70:	ac202810 */ 	sw	$zero,0x2810($at)
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
/*  f017ca0:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017ca4:	44809000 */ 	mtc1	$zero,$f18
/*  f017ca8:	27ff27d8 */ 	addiu	$ra,$ra,0x27d8
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
/*  f017cd8:	3c018006 */ 	lui	$at,0x8006
/*  f017cdc:	ac2327d0 */ 	sw	$v1,0x27d0($at)
/*  f017ce0:	ad230000 */ 	sw	$v1,0x0($t1)
.L0f017ce4:
/*  f017ce4:	3c198006 */ 	lui	$t9,0x8006
/*  f017ce8:	8f3927e4 */ 	lw	$t9,0x27e4($t9)
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
/*  f017d6c:	3c1f8006 */ 	lui	$ra,0x8006
/*  f017d70:	44809000 */ 	mtc1	$zero,$f18
/*  f017d74:	27ff27d8 */ 	addiu	$ra,$ra,0x27d8
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
/*  f017e0c:	3c018006 */ 	lui	$at,0x8006
/*  f017e10:	1000001f */ 	beqz	$zero,.L0f017e90
/*  f017e14:	ac2027e4 */ 	sw	$zero,0x27e4($at)
.L0f017e18:
/*  f017e18:	3c0f8006 */ 	lui	$t7,0x8006
/*  f017e1c:	8def27d0 */ 	lw	$t7,0x27d0($t7)
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
);

GLOBAL_ASM(
glabel func0f017f08
/*  f017f08:	e43227bc */ 	swc1	$f18,0x27bc($at)
/*  f017f0c:	3c018006 */ 	lui	$at,0x8006
/*  f017f10:	ac2327c0 */ 	sw	$v1,0x27c0($at)
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
/*  f018060:	3c018006 */ 	lui	$at,0x8006
/*  f018064:	ac2027d0 */ 	sw	$zero,0x27d0($at)
/*  f018068:	3c018006 */ 	lui	$at,0x8006
/*  f01806c:	ac2427e4 */ 	sw	$a0,0x27e4($at)
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
/*  f0180b8:	3c028006 */ 	lui	$v0,0x8006
/*  f0180bc:	28610065 */ 	slti	$at,$v1,0x65
/*  f0180c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0180c4:	14200009 */ 	bnez	$at,.L0f0180ec
/*  f0180c8:	8c4227e4 */ 	lw	$v0,0x27e4($v0)
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
/*  f018128:	3c0f8006 */ 	lui	$t7,0x8006
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
/*  f01817c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f018180:	10400009 */ 	beqz	$v0,.L0f0181a8
/*  f018184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018188:	8d180038 */ 	lw	$t8,0x38($t0)
/*  f01818c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f018190:	2b210015 */ 	slti	$at,$t9,0x15
/*  f018194:	14200004 */ 	bnez	$at,.L0f0181a8
/*  f018198:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f01819c:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f0181a0:	3c018006 */ 	lui	$at,0x8006
/*  f0181a4:	ac2427ec */ 	sw	$a0,0x27ec($at)
.L0f0181a8:
/*  f0181a8:	8dce27ec */ 	lw	$t6,0x27ec($t6)
/*  f0181ac:	3c018006 */ 	lui	$at,0x8006
/*  f0181b0:	51c00004 */ 	beqzl	$t6,.L0f0181c4
/*  f0181b4:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f0181b8:	ac2027ec */ 	sw	$zero,0x27ec($at)
/*  f0181bc:	ada40000 */ 	sw	$a0,0x0($t5)
/*  f0181c0:	8da20000 */ 	lw	$v0,0x0($t5)
.L0f0181c4:
/*  f0181c4:	3c018006 */ 	lui	$at,0x8006
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
/*  f018228:	ac24280c */ 	sw	$a0,0x280c($at)
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
/*  f0182d4:	8def280c */ 	lw	$t7,0x280c($t7)
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
/*  f0183a4:	3c018006 */ 	lui	$at,0x8006
/*  f0183a8:	ac242734 */ 	sw	$a0,0x2734($at)
.L0f0183ac:
/*  f0183ac:	8fa40330 */ 	lw	$a0,0x330($sp)
.L0f0183b0:
/*  f0183b0:	0c002fc1 */ 	jal	func0000bf04
/*  f0183b4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0183b8:	0c002cb1 */ 	jal	func0000b2c4
/*  f0183bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0183c0:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0183c4:	8dce27cc */ 	lw	$t6,0x27cc($t6)
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
/*  f0184e8:	0c0068f7 */ 	jal	func0001a3dc
/*  f0184ec:	afa60330 */ 	sw	$a2,0x330($sp)
/*  f0184f0:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0184f4:	0c0068f4 */ 	jal	func0001a3d0
/*  f0184f8:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f0184fc:	3c0142fe */ 	lui	$at,0x42fe
/*  f018500:	44815000 */ 	mtc1	$at,$f10
/*  f018504:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018508:	3c018006 */ 	lui	$at,0x8006
/*  f01850c:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f018510:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f018514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018518:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f01851c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f018520:	44195000 */ 	mfc1	$t9,$f10
/*  f018524:	0c0068f7 */ 	jal	func0001a3dc
/*  f018528:	a0392588 */ 	sb	$t9,0x2588($at)
/*  f01852c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018530:	44812000 */ 	mtc1	$at,$f4
/*  f018534:	3c018006 */ 	lui	$at,0x8006
/*  f018538:	c7ac00e4 */ 	lwc1	$f12,0xe4($sp)
/*  f01853c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f018540:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f018544:	440e4000 */ 	mfc1	$t6,$f8
/*  f018548:	0c0068f4 */ 	jal	func0001a3d0
/*  f01854c:	a02e2589 */ 	sb	$t6,0x2589($at)
/*  f018550:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f018554:	0c0068f4 */ 	jal	func0001a3d0
/*  f018558:	c7ac00e0 */ 	lwc1	$f12,0xe0($sp)
/*  f01855c:	3c0142fe */ 	lui	$at,0x42fe
/*  f018560:	44815000 */ 	mtc1	$at,$f10
/*  f018564:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f018568:	44809000 */ 	mtc1	$zero,$f18
/*  f01856c:	3c018006 */ 	lui	$at,0x8006
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
/*  f0185a8:	a039258a */ 	sb	$t9,0x258a($at)
/*  f0185ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0185b0:	44812000 */ 	mtc1	$at,$f4
/*  f0185b4:	0c005ab9 */ 	jal	func00016ae4
/*  f0185b8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0185bc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0185c0:	8def27c0 */ 	lw	$t7,0x27c0($t7)
/*  f0185c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0185c8:	27a501e8 */ 	addiu	$a1,$sp,0x1e8
/*  f0185cc:	15e10004 */ 	bne	$t7,$at,.L0f0185e0
/*  f0185d0:	3c0e8006 */ 	lui	$t6,0x8006
/*  f0185d4:	8dce24f8 */ 	lw	$t6,0x24f8($t6)
/*  f0185d8:	10000004 */ 	beqz	$zero,.L0f0185ec
/*  f0185dc:	afae022c */ 	sw	$t6,0x22c($sp)
.L0f0185e0:
/*  f0185e0:	3c188006 */ 	lui	$t8,0x8006
/*  f0185e4:	8f1824fc */ 	lw	$t8,0x24fc($t8)
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
/*  f01861c:	0c005680 */ 	jal	0x15a00
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
/*  f018a90:	3c068006 */ 	lui	$a2,0x8006
/*  f018a94:	3c078006 */ 	lui	$a3,0x8006
/*  f018a98:	240f00f0 */ 	addiu	$t7,$zero,0xf0
/*  f018a9c:	27ae0270 */ 	addiu	$t6,$sp,0x270
/*  f018aa0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f018aa4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f018aa8:	8ce727bc */ 	lw	$a3,0x27bc($a3)
/*  f018aac:	8cc62804 */ 	lw	$a2,0x2804($a2)
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
/*  f018b64:	0c005680 */ 	jal	0x15a00
/*  f018b68:	27a60230 */ 	addiu	$a2,$sp,0x230
/*  f018b6c:	3c017f1b */ 	lui	$at,%hi(var7f1a8468)
/*  f018b70:	c42c8468 */ 	lwc1	$f12,%lo(var7f1a8468)($at)
/*  f018b74:	0c0057c1 */ 	jal	func00015f04
/*  f018b78:	27a50230 */ 	addiu	$a1,$sp,0x230
/*  f018b7c:	3c028006 */ 	lui	$v0,0x8006
/*  f018b80:	8c4227f8 */ 	lw	$v0,0x27f8($v0)
/*  f018b84:	27a30230 */ 	addiu	$v1,$sp,0x230
/*  f018b88:	04420085 */ 	bltzl	$v0,.L0f018da0
/*  f018b8c:	8fa20330 */ 	lw	$v0,0x330($sp)
/*  f018b90:	10400082 */ 	beqz	$v0,.L0f018d9c
/*  f018b94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f018b98:	1441001f */ 	bne	$v0,$at,.L0f018c18
/*  f018b9c:	3c058006 */ 	lui	$a1,0x8006
/*  f018ba0:	3c018006 */ 	lui	$at,0x8006
/*  f018ba4:	c42027f4 */ 	lwc1	$f0,0x27f4($at)
/*  f018ba8:	3c013f00 */ 	lui	$at,0x3f00
/*  f018bac:	44815000 */ 	mtc1	$at,$f10
/*  f018bb0:	44070000 */ 	mfc1	$a3,$f0
/*  f018bb4:	00003025 */ 	or	$a2,$zero,$zero
/*  f018bb8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f018bbc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018bc0:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018bc4:	3c02800a */ 	lui	$v0,0x800a
/*  f018bc8:	45000002 */ 	bc1f	.L0f018bd4
/*  f018bcc:	3c18800a */ 	lui	$t8,0x800a
/*  f018bd0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018bd4:
/*  f018bd4:	8c42ccb8 */ 	lw	$v0,-0x3348($v0)
/*  f018bd8:	3c0f800a */ 	lui	$t7,0x800a
/*  f018bdc:	8ca5250c */ 	lw	$a1,0x250c($a1)
/*  f018be0:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018be4:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018be8:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018bec:	8defccb0 */ 	lw	$t7,-0x3350($t7)
/*  f018bf0:	8f18cca8 */ 	lw	$t8,-0x3358($t8)
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
/*  f018c20:	3c058006 */ 	lui	$a1,0x8006
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
/*  f018c58:	3c02800a */ 	lui	$v0,0x800a
/*  f018c5c:	8c42ccb8 */ 	lw	$v0,-0x3348($v0)
/*  f018c60:	3c18800a */ 	lui	$t8,0x800a
/*  f018c64:	3c0f800a */ 	lui	$t7,0x800a
/*  f018c68:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018c6c:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018c70:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018c74:	8defccb0 */ 	lw	$t7,-0x3350($t7)
/*  f018c78:	8f18cca8 */ 	lw	$t8,-0x3358($t8)
/*  f018c7c:	44815000 */ 	mtc1	$at,$f10
/*  f018c80:	44074000 */ 	mfc1	$a3,$f8
/*  f018c84:	8ca52508 */ 	lw	$a1,0x2508($a1)
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
/*  f018cd4:	3c058006 */ 	lui	$a1,0x8006
/*  f018cd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f018cdc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f018ce0:	45000002 */ 	bc1f	.L0f018cec
/*  f018ce4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018ce8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f018cec:
/*  f018cec:	3c02800a */ 	lui	$v0,0x800a
/*  f018cf0:	8c42ccb8 */ 	lw	$v0,-0x3348($v0)
/*  f018cf4:	3c18800a */ 	lui	$t8,0x800a
/*  f018cf8:	3c0f800a */ 	lui	$t7,0x800a
/*  f018cfc:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d00:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d04:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d08:	8defccb0 */ 	lw	$t7,-0x3350($t7)
/*  f018d0c:	8f18cca8 */ 	lw	$t8,-0x3358($t8)
/*  f018d10:	44813000 */ 	mtc1	$at,$f6
/*  f018d14:	8ca52508 */ 	lw	$a1,0x2508($a1)
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
/*  f018d3c:	3c02800a */ 	lui	$v0,0x800a
/*  f018d40:	8c42ccb8 */ 	lw	$v0,-0x3348($v0)
/*  f018d44:	3c18800a */ 	lui	$t8,0x800a
/*  f018d48:	3c0f800a */ 	lui	$t7,0x800a
/*  f018d4c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f018d50:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f018d54:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f018d58:	3c013f80 */ 	lui	$at,0x3f80
/*  f018d5c:	44814000 */ 	mtc1	$at,$f8
/*  f018d60:	8defccb0 */ 	lw	$t7,-0x3350($t7)
/*  f018d64:	8f18cca8 */ 	lw	$t8,-0x3358($t8)
/*  f018d68:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f018d6c:	8ca52508 */ 	lw	$a1,0x2508($a1)
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

GLOBAL_ASM(
glabel func0f018db0
/*  f018db0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f018db4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f018db8:	3c018006 */ 	lui	$at,0x8006
/*  f018dbc:	ac2024c4 */ 	sw	$zero,0x24c4($at)
/*  f018dc0:	0c005204 */ 	jal	func00014810
/*  f018dc4:	00002025 */ 	or	$a0,$zero,$zero
/*  f018dc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f018dcc:	3c018006 */ 	lui	$at,0x8006
/*  f018dd0:	ac202864 */ 	sw	$zero,0x2864($at)
/*  f018dd4:	03e00008 */ 	jr	$ra
/*  f018dd8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f018ddc
/*  f018ddc:	3c048006 */ 	lui	$a0,0x8006
/*  f018de0:	8c842864 */ 	lw	$a0,0x2864($a0)
/*  f018de4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f018de8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f018dec:	10800003 */ 	beqz	$a0,.L0f018dfc
/*  f018df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018df4:	0c00cec9 */ 	jal	func00033b24
/*  f018df8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f018dfc:
/*  f018dfc:	3c018006 */ 	lui	$at,0x8006
/*  f018e00:	ac202864 */ 	sw	$zero,0x2864($at)
/*  f018e04:	0c005204 */ 	jal	func00014810
/*  f018e08:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f018e0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f018e10:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f018e14:	03e00008 */ 	jr	$ra
/*  f018e18:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f018e1c
/*  f018e1c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f018e20:	3c014270 */ 	lui	$at,0x4270
/*  f018e24:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f018e28:	44816000 */ 	mtc1	$at,$f12
/*  f018e2c:	0c002f4c */ 	jal	func0000bd30
/*  f018e30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f018e34:	3c017f1b */ 	lui	$at,%hi(var7f1a846c)
/*  f018e38:	0c002f5f */ 	jal	func0000bd7c
/*  f018e3c:	c42c846c */ 	lwc1	$f12,%lo(var7f1a846c)($at)
/*  f018e40:	3c0142c8 */ 	lui	$at,0x42c8
/*  f018e44:	44816000 */ 	mtc1	$at,$f12
/*  f018e48:	3c017f1b */ 	lui	$at,%hi(var7f1a8470)
/*  f018e4c:	0c002fa1 */ 	jal	func0000be84
/*  f018e50:	c42e8470 */ 	lwc1	$f14,%lo(var7f1a8470)($at)
/*  f018e54:	0c002f48 */ 	jal	func0000bd20
/*  f018e58:	00002025 */ 	or	$a0,$zero,$zero
/*  f018e5c:	3c028006 */ 	lui	$v0,%hi(var800624c4)
/*  f018e60:	244224c4 */ 	addiu	$v0,$v0,%lo(var800624c4)
/*  f018e64:	3c0f800a */ 	lui	$t7,0x800a
/*  f018e68:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f018e6c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f018e70:	00002025 */ 	or	$a0,$zero,$zero
/*  f018e74:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f018e78:	2b01012d */ 	slti	$at,$t8,0x12d
/*  f018e7c:	14200005 */ 	bnez	$at,.L0f018e94
/*  f018e80:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f018e84:	0fc069f9 */ 	jal	func0f01a7e4
/*  f018e88:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f018e8c:	10000008 */ 	beqz	$zero,.L0f018eb0
/*  f018e90:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f018e94:
/*  f018e94:	0c005408 */ 	jal	func00015020
/*  f018e98:	3405ffff */ 	dli	$a1,0xffff
/*  f018e9c:	50400004 */ 	beqzl	$v0,.L0f018eb0
/*  f018ea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f018ea4:	0fc069f9 */ 	jal	func0f01a7e4
/*  f018ea8:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f018eac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f018eb0:
/*  f018eb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f018eb4:	03e00008 */ 	jr	$ra
/*  f018eb8:	00000000 */ 	sll	$zero,$zero,0x0
);

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
/*  f018f0c:	0fc5b9f1 */ 	jal	textGet
/*  f018f10:	afb0008c */ 	sw	$s0,0x8c($sp)
/*  f018f14:	3c0f8006 */ 	lui	$t7,0x8006
/*  f018f18:	95ef286c */ 	lhu	$t7,0x286c($t7)
/*  f018f1c:	00409825 */ 	or	$s3,$v0,$zero
/*  f018f20:	00402025 */ 	or	$a0,$v0,$zero
/*  f018f24:	0c012983 */ 	jal	func0004a60c
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
/*  f018fec:	3c0c8008 */ 	lui	$t4,0x8008
/*  f018ff0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f018ff4:	00107200 */ 	sll	$t6,$s0,0x8
/*  f018ff8:	8dadfb1c */ 	lw	$t5,-0x4e4($t5)
/*  f018ffc:	8d8cfb20 */ 	lw	$t4,-0x4e0($t4)
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
/*  f019034:	0fc5580f */ 	jal	func0f15603c
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

GLOBAL_ASM(
glabel func0f019088
/*  f019088:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f01908c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f019090:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f019094:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f019098:	0fc06bf0 */ 	jal	func0f01afc0
/*  f01909c:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0190a0:	0fc54d8a */ 	jal	func0f153628
/*  f0190a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0190a8:	0c002f40 */ 	jal	func0000bd00
/*  f0190ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0190b0:	24430032 */ 	addiu	$v1,$v0,0x32
/*  f0190b4:	0c002f44 */ 	jal	func0000bd10
/*  f0190b8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0190bc:	0c002f26 */ 	jal	func0000bc98
/*  f0190c0:	a7a2003e */ 	sh	$v0,0x3e($sp)
/*  f0190c4:	87ae003e */ 	lh	$t6,0x3e($sp)
/*  f0190c8:	3c198006 */ 	lui	$t9,0x8006
/*  f0190cc:	8f3924b4 */ 	lw	$t9,0x24b4($t9)
/*  f0190d0:	3c018006 */ 	lui	$at,0x8006
/*  f0190d4:	ac202868 */ 	sw	$zero,0x2868($at)
/*  f0190d8:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0190dc:	25f8ffb0 */ 	addiu	$t8,$t7,-80
/*  f0190e0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0190e4:	17210029 */ 	bne	$t9,$at,.L0f01918c
/*  f0190e8:	afb80050 */ 	sw	$t8,0x50($sp)
/*  f0190ec:	3c088006 */ 	lui	$t0,0x8006
/*  f0190f0:	8d0824c4 */ 	lw	$t0,0x24c4($t0)
/*  f0190f4:	27a9004c */ 	addiu	$t1,$sp,0x4c
/*  f0190f8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0190fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f019100:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f019104:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f019108:	24075605 */ 	addiu	$a3,$zero,0x5605
/*  f01910c:	0fc063af */ 	jal	func0f018ebc
/*  f019110:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f019114:	3c0a8006 */ 	lui	$t2,0x8006
/*  f019118:	8d4a24c4 */ 	lw	$t2,0x24c4($t2)
/*  f01911c:	00408025 */ 	or	$s0,$v0,$zero
/*  f019120:	29410047 */ 	slti	$at,$t2,0x47
/*  f019124:	14200025 */ 	bnez	$at,.L0f0191bc
/*  f019128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01912c:	0c002f40 */ 	jal	func0000bd00
/*  f019130:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019134:	24430032 */ 	addiu	$v1,$v0,0x32
/*  f019138:	0c002f44 */ 	jal	func0000bd10
/*  f01913c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f019140:	0c002f26 */ 	jal	func0000bc98
/*  f019144:	a7a2003e */ 	sh	$v0,0x3e($sp)
/*  f019148:	87ab003e */ 	lh	$t3,0x3e($sp)
/*  f01914c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f019150:	8dce24c4 */ 	lw	$t6,0x24c4($t6)
/*  f019154:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f019158:	258dffc4 */ 	addiu	$t5,$t4,-60
/*  f01915c:	27b8004c */ 	addiu	$t8,$sp,0x4c
/*  f019160:	25cfff9c */ 	addiu	$t7,$t6,-100
/*  f019164:	afad0050 */ 	sw	$t5,0x50($sp)
/*  f019168:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f01916c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f019170:	02002025 */ 	or	$a0,$s0,$zero
/*  f019174:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f019178:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f01917c:	0fc063af */ 	jal	func0f018ebc
/*  f019180:	24075606 */ 	addiu	$a3,$zero,0x5606
/*  f019184:	1000000d */ 	beqz	$zero,.L0f0191bc
/*  f019188:	00408025 */ 	or	$s0,$v0,$zero
.L0f01918c:
/*  f01918c:	3c198006 */ 	lui	$t9,0x8006
/*  f019190:	8f3924c4 */ 	lw	$t9,0x24c4($t9)
/*  f019194:	27a9004c */ 	addiu	$t1,$sp,0x4c
/*  f019198:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f01919c:	2728ffdd */ 	addiu	$t0,$t9,-35
/*  f0191a0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0191a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0191a8:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0191ac:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0191b0:	0fc063af */ 	jal	func0f018ebc
/*  f0191b4:	24075607 */ 	addiu	$a3,$zero,0x5607
/*  f0191b8:	00408025 */ 	or	$s0,$v0,$zero
.L0f0191bc:
/*  f0191bc:	0fc54de0 */ 	jal	func0f153780
/*  f0191c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0191c4:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0191c8:	8d4a2868 */ 	lw	$t2,0x2868($t2)
/*  f0191cc:	3c068006 */ 	lui	$a2,%hi(var80062864)
/*  f0191d0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0191d4:	11400015 */ 	beqz	$t2,.L0f01922c
/*  f0191d8:	24c62864 */ 	addiu	$a2,$a2,%lo(var80062864)
/*  f0191dc:	3c068006 */ 	lui	$a2,%hi(var80062864)
/*  f0191e0:	24c62864 */ 	addiu	$a2,$a2,%lo(var80062864)
/*  f0191e4:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f0191e8:	3c048009 */ 	lui	$a0,0x8009
/*  f0191ec:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f0191f0:	15600016 */ 	bnez	$t3,.L0f01924c
/*  f0191f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0191f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0191fc:	44812000 */ 	mtc1	$at,$f4
/*  f019200:	240cffff */ 	addiu	$t4,$zero,-1
/*  f019204:	240dffff */ 	addiu	$t5,$zero,-1
/*  f019208:	240effff */ 	addiu	$t6,$zero,-1
/*  f01920c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f019210:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f019214:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f019218:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f01921c:	0c004241 */ 	jal	func00010904
/*  f019220:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f019224:	10000009 */ 	beqz	$zero,.L0f01924c
/*  f019228:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01922c:
/*  f01922c:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f019230:	50800006 */ 	beqzl	$a0,.L0f01924c
/*  f019234:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f019238:	0c00cec9 */ 	jal	func00033b24
/*  f01923c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019240:	3c068006 */ 	lui	$a2,%hi(var80062864)
/*  f019244:	24c62864 */ 	addiu	$a2,$a2,%lo(var80062864)
/*  f019248:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f01924c:
/*  f01924c:	3c018006 */ 	lui	$at,0x8006
/*  f019250:	c4261630 */ 	lwc1	$f6,0x1630($at)
/*  f019254:	3c0142a0 */ 	lui	$at,0x42a0
/*  f019258:	44814000 */ 	mtc1	$at,$f8
/*  f01925c:	8fa2004c */ 	lw	$v0,0x4c($sp)
/*  f019260:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f019264:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f019268:	3c017f7f */ 	lui	$at,0x7f7f
/*  f01926c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f019270:	3421ffff */ 	ori	$at,$at,0xffff
/*  f019274:	00024a00 */ 	sll	$t1,$v0,0x8
/*  f019278:	01215025 */ 	or	$t2,$t1,$at
/*  f01927c:	00025c00 */ 	sll	$t3,$v0,0x10
/*  f019280:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f019284:	014b6025 */ 	or	$t4,$t2,$t3
/*  f019288:	02002025 */ 	or	$a0,$s0,$zero
/*  f01928c:	24650002 */ 	addiu	$a1,$v1,0x2
/*  f019290:	44188000 */ 	mfc1	$t8,$f16
/*  f019294:	2467000c */ 	addiu	$a3,$v1,0xc
/*  f019298:	24c80014 */ 	addiu	$t0,$a2,0x14
/*  f01929c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0192a0:	17200005 */ 	bnez	$t9,.L0f0192b8
/*  f0192a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0192a8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0192ac:	0fc54e8d */ 	jal	func0f153a34
/*  f0192b0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0192b4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0192b8:
/*  f0192b8:	0fc51f3e */ 	jal	func0f147cf8
/*  f0192bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0192c0:	3c038006 */ 	lui	$v1,0x8006
/*  f0192c4:	8c6324c4 */ 	lw	$v1,0x24c4($v1)
/*  f0192c8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0192cc:	286100df */ 	slti	$at,$v1,0xdf
/*  f0192d0:	54200046 */ 	bnezl	$at,.L0f0193ec
/*  f0192d4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0192d8:	44839000 */ 	mtc1	$v1,$f18
/*  f0192dc:	3c01435e */ 	lui	$at,0x435e
/*  f0192e0:	44813000 */ 	mtc1	$at,$f6
/*  f0192e4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0192e8:	3c01429c */ 	lui	$at,0x429c
/*  f0192ec:	44815000 */ 	mtc1	$at,$f10
/*  f0192f0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0192f4:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f0192f8:	0c002f40 */ 	jal	func0000bd00
/*  f0192fc:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f019300:	0c002f44 */ 	jal	func0000bd10
/*  f019304:	a7a20034 */ 	sh	$v0,0x34($sp)
/*  f019308:	0c002f40 */ 	jal	func0000bd00
/*  f01930c:	a7a20036 */ 	sh	$v0,0x36($sp)
/*  f019310:	0c002f22 */ 	jal	func0000bc88
/*  f019314:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f019318:	0c002f44 */ 	jal	func0000bd10
/*  f01931c:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f019320:	0c002f26 */ 	jal	func0000bc98
/*  f019324:	a7a2003c */ 	sh	$v0,0x3c($sp)
/*  f019328:	3c01437f */ 	lui	$at,0x437f
/*  f01932c:	44819000 */ 	mtc1	$at,$f18
/*  f019330:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f019334:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f019338:	87af003c */ 	lh	$t7,0x3c($sp)
/*  f01933c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f019340:	87ad003a */ 	lh	$t5,0x3a($sp)
/*  f019344:	87ae0038 */ 	lh	$t6,0x38($sp)
/*  f019348:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f01934c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f019350:	3c014f00 */ 	lui	$at,0x4f00
/*  f019354:	02002025 */ 	or	$a0,$s0,$zero
/*  f019358:	4459f800 */ 	cfc1	$t9,$31
/*  f01935c:	44c8f800 */ 	ctc1	$t0,$31
/*  f019360:	87a50034 */ 	lh	$a1,0x34($sp)
/*  f019364:	87a60036 */ 	lh	$a2,0x36($sp)
/*  f019368:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f01936c:	01ae3821 */ 	addu	$a3,$t5,$t6
/*  f019370:	4448f800 */ 	cfc1	$t0,$31
/*  f019374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019378:	31080078 */ 	andi	$t0,$t0,0x78
/*  f01937c:	51000013 */ 	beqzl	$t0,.L0f0193cc
/*  f019380:	44084000 */ 	mfc1	$t0,$f8
/*  f019384:	44814000 */ 	mtc1	$at,$f8
/*  f019388:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01938c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f019390:	44c8f800 */ 	ctc1	$t0,$31
/*  f019394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019398:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f01939c:	4448f800 */ 	cfc1	$t0,$31
/*  f0193a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0193a4:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0193a8:	15000005 */ 	bnez	$t0,.L0f0193c0
/*  f0193ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0193b0:	44084000 */ 	mfc1	$t0,$f8
/*  f0193b4:	3c018000 */ 	lui	$at,0x8000
/*  f0193b8:	10000007 */ 	beqz	$zero,.L0f0193d8
/*  f0193bc:	01014025 */ 	or	$t0,$t0,$at
.L0f0193c0:
/*  f0193c0:	10000005 */ 	beqz	$zero,.L0f0193d8
/*  f0193c4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0193c8:	44084000 */ 	mfc1	$t0,$f8
.L0f0193cc:
/*  f0193cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0193d0:	0500fffb */ 	bltz	$t0,.L0f0193c0
/*  f0193d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0193d8:
/*  f0193d8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0193dc:	0fc54e8d */ 	jal	func0f153a34
/*  f0193e0:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0193e4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0193e8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0193ec:
/*  f0193ec:	02001025 */ 	or	$v0,$s0,$zero
/*  f0193f0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0193f4:	03e00008 */ 	jr	$ra
/*  f0193f8:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f0193fc
/*  f0193fc:	3c0e8006 */ 	lui	$t6,0x8006
/*  f019400:	8dce24a8 */ 	lw	$t6,0x24a8($t6)
/*  f019404:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f019408:	3c05800a */ 	lui	$a1,0x800a
/*  f01940c:	3c018006 */ 	lui	$at,0x8006
/*  f019410:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f019414:	8ca5cca0 */ 	lw	$a1,-0x3360($a1)
/*  f019418:	11c00005 */ 	beqz	$t6,.L0f019430
/*  f01941c:	ac2024ac */ 	sw	$zero,0x24ac($at)
/*  f019420:	240f00b4 */ 	addiu	$t7,$zero,0xb4
/*  f019424:	3c018006 */ 	lui	$at,0x8006
/*  f019428:	10000003 */ 	beqz	$zero,.L0f019438
/*  f01942c:	ac2f24c4 */ 	sw	$t7,0x24c4($at)
.L0f019430:
/*  f019430:	3c018006 */ 	lui	$at,0x8006
/*  f019434:	ac2024c4 */ 	sw	$zero,0x24c4($at)
.L0f019438:
/*  f019438:	3c198006 */ 	lui	$t9,%hi(var80062870)
/*  f01943c:	27392870 */ 	addiu	$t9,$t9,%lo(var80062870)
/*  f019440:	8f210000 */ 	lw	$at,0x0($t9)
/*  f019444:	27b80018 */ 	addiu	$t8,$sp,0x18
/*  f019448:	8f2a0004 */ 	lw	$t2,0x4($t9)
/*  f01944c:	af010000 */ 	sw	$at,0x0($t8)
/*  f019450:	8f210008 */ 	lw	$at,0x8($t9)
/*  f019454:	3c048008 */ 	lui	$a0,0x8008
/*  f019458:	3c060004 */ 	lui	$a2,0x4
/*  f01945c:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f019460:	af010008 */ 	sw	$at,0x8($t8)
/*  f019464:	9484b110 */ 	lhu	$a0,-0x4ef0($a0)
/*  f019468:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f01946c:	0fc69de5 */ 	jal	func0f1a7794
/*  f019470:	00003825 */ 	or	$a3,$zero,$zero
/*  f019474:	3c038008 */ 	lui	$v1,%hi(proptable)
/*  f019478:	2463b06c */ 	addiu	$v1,$v1,%lo(proptable)
/*  f01947c:	ac6200a0 */ 	sw	$v0,0xa0($v1)
/*  f019480:	0c008b49 */ 	jal	func00022d24
/*  f019484:	00402025 */ 	or	$a0,$v0,$zero
/*  f019488:	3c048008 */ 	lui	$a0,0x8008
/*  f01948c:	0fc2cc2b */ 	jal	func0f0b30ac
/*  f019490:	8c84b10c */ 	lw	$a0,-0x4ef4($a0)
/*  f019494:	3c038006 */ 	lui	$v1,%hi(var800624f8)
/*  f019498:	246324f8 */ 	addiu	$v1,$v1,%lo(var800624f8)
/*  f01949c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f0194a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0194a4:	0c006bd6 */ 	jal	func0001af58
/*  f0194a8:	3c053f80 */ 	lui	$a1,0x3f80
/*  f0194ac:	3c048006 */ 	lui	$a0,0x8006
/*  f0194b0:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
/*  f0194b4:	0c006b4d */ 	jal	func0001ad34
/*  f0194b8:	27a50018 */ 	addiu	$a1,$sp,0x18
/*  f0194bc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0194c0:	3c018006 */ 	lui	$at,0x8006
/*  f0194c4:	ac2b24f4 */ 	sw	$t3,0x24f4($at)
/*  f0194c8:	0c005204 */ 	jal	func00014810
/*  f0194cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0194d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0194d4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0194d8:	03e00008 */ 	jr	$ra
/*  f0194dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0194e0
/*  f0194e0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0194e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0194e8:	3c048006 */ 	lui	$a0,0x8006
/*  f0194ec:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f0194f0:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
/*  f0194f4:	0c005204 */ 	jal	func00014810
/*  f0194f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0194fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019500:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f019504:	03e00008 */ 	jr	$ra
/*  f019508:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01950c
/*  f01950c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f019510:	3c014270 */ 	lui	$at,0x4270
/*  f019514:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f019518:	44816000 */ 	mtc1	$at,$f12
/*  f01951c:	0c002f4c */ 	jal	func0000bd30
/*  f019520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019524:	3c017f1b */ 	lui	$at,%hi(var7f1a8474)
/*  f019528:	0c002f5f */ 	jal	func0000bd7c
/*  f01952c:	c42c8474 */ 	lwc1	$f12,%lo(var7f1a8474)($at)
/*  f019530:	3c0142c8 */ 	lui	$at,0x42c8
/*  f019534:	44816000 */ 	mtc1	$at,$f12
/*  f019538:	3c017f1b */ 	lui	$at,%hi(var7f1a8478)
/*  f01953c:	0c002fa1 */ 	jal	func0000be84
/*  f019540:	c42e8478 */ 	lwc1	$f14,%lo(var7f1a8478)($at)
/*  f019544:	0c002f48 */ 	jal	func0000bd20
/*  f019548:	00002025 */ 	or	$a0,$zero,$zero
/*  f01954c:	3c038006 */ 	lui	$v1,%hi(var800624c4)
/*  f019550:	246324c4 */ 	addiu	$v1,$v1,%lo(var800624c4)
/*  f019554:	3c068006 */ 	lui	$a2,%hi(var800624ac)
/*  f019558:	3c02800a */ 	lui	$v0,0x800a
/*  f01955c:	8c429ff8 */ 	lw	$v0,-0x6008($v0)
/*  f019560:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f019564:	24c624ac */ 	addiu	$a2,$a2,%lo(var800624ac)
/*  f019568:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f01956c:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f019570:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f019574:	13000003 */ 	beqz	$t8,.L0f019584
/*  f019578:	00002025 */ 	or	$a0,$zero,$zero
/*  f01957c:	01e24021 */ 	addu	$t0,$t7,$v0
/*  f019580:	ac680000 */ 	sw	$t0,0x0($v1)
.L0f019584:
/*  f019584:	0c005408 */ 	jal	func00015020
/*  f019588:	3405ffff */ 	dli	$a1,0xffff
/*  f01958c:	3c038006 */ 	lui	$v1,%hi(var800624c4)
/*  f019590:	3c068006 */ 	lui	$a2,%hi(var800624ac)
/*  f019594:	24c624ac */ 	addiu	$a2,$a2,%lo(var800624ac)
/*  f019598:	10400013 */ 	beqz	$v0,.L0f0195e8
/*  f01959c:	246324c4 */ 	addiu	$v1,$v1,%lo(var800624c4)
/*  f0195a0:	3c098000 */ 	lui	$t1,0x8000
/*  f0195a4:	8d29030c */ 	lw	$t1,0x30c($t1)
/*  f0195a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0195ac:	3c018006 */ 	lui	$at,0x8006
/*  f0195b0:	14490009 */ 	bne	$v0,$t1,.L0f0195d8
/*  f0195b4:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0195b8:	ac2224a8 */ 	sw	$v0,0x24a8($at)
/*  f0195bc:	0fc069f9 */ 	jal	func0f01a7e4
/*  f0195c0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0195c4:	3c038006 */ 	lui	$v1,%hi(var800624c4)
/*  f0195c8:	3c068006 */ 	lui	$a2,%hi(var800624ac)
/*  f0195cc:	24c624ac */ 	addiu	$a2,$a2,%lo(var800624ac)
/*  f0195d0:	10000005 */ 	beqz	$zero,.L0f0195e8
/*  f0195d4:	246324c4 */ 	addiu	$v1,$v1,%lo(var800624c4)
.L0f0195d8:
/*  f0195d8:	8d4a24a8 */ 	lw	$t2,0x24a8($t2)
/*  f0195dc:	55400003 */ 	bnezl	$t2,.L0f0195ec
/*  f0195e0:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f0195e4:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f0195e8:
/*  f0195e8:	8ccb0000 */ 	lw	$t3,0x0($a2)
.L0f0195ec:
/*  f0195ec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0195f0:	3c0c8006 */ 	lui	$t4,0x8006
/*  f0195f4:	5160000f */ 	beqzl	$t3,.L0f019634
/*  f0195f8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0195fc:	8d8c24a8 */ 	lw	$t4,0x24a8($t4)
/*  f019600:	5580000c */ 	bnezl	$t4,.L0f019634
/*  f019604:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f019608:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f01960c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f019610:	29a1008d */ 	slti	$at,$t5,0x8d
/*  f019614:	14200006 */ 	bnez	$at,.L0f019630
/*  f019618:	3c018006 */ 	lui	$at,0x8006
/*  f01961c:	ac2224a8 */ 	sw	$v0,0x24a8($at)
/*  f019620:	0fc069f9 */ 	jal	func0f01a7e4
/*  f019624:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f019628:	3c038006 */ 	lui	$v1,%hi(var800624c4)
/*  f01962c:	246324c4 */ 	addiu	$v1,$v1,%lo(var800624c4)
.L0f019630:
/*  f019630:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f019634:
/*  f019634:	29c100f1 */ 	slti	$at,$t6,0xf1
/*  f019638:	54200004 */ 	bnezl	$at,.L0f01964c
/*  f01963c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019640:	0fc069f9 */ 	jal	func0f01a7e4
/*  f019644:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f019648:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01964c:
/*  f01964c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f019650:	03e00008 */ 	jr	$ra
/*  f019654:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f019658
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
/*  f0196b4:	3c098006 */ 	lui	$t1,0x8006
/*  f0196b8:	3c0a8006 */ 	lui	$t2,%hi(var800628bc)
/*  f0196bc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f0196c0:	3c014370 */ 	lui	$at,0x4370
/*  f0196c4:	44814000 */ 	mtc1	$at,$f8
/*  f0196c8:	8d2924c4 */ 	lw	$t1,0x24c4($t1)
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
/*  f019770:	0c0068f7 */ 	jal	func0001a3dc
/*  f019774:	e7ac004c */ 	swc1	$f12,0x4c($sp)
/*  f019778:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f01977c:	0c0068f4 */ 	jal	func0001a3d0
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
/*  f019878:	0c0068f4 */ 	jal	func0001a3d0
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
/*  f0198c8:	0c0068f4 */ 	jal	func0001a3d0
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
/*  f019984:	3c138006 */ 	lui	$s3,%hi(var800624f8)
/*  f019988:	267324f8 */ 	addiu	$s3,$s3,%lo(var800624f8)
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

GLOBAL_ASM(
glabel func0f019a80
/*  f019a80:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f019a84:	240efffd */ 	addiu	$t6,$zero,-3
/*  f019a88:	3c018006 */ 	lui	$at,0x8006
/*  f019a8c:	3c188006 */ 	lui	$t8,%hi(var800628c8)
/*  f019a90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f019a94:	ac2e24c4 */ 	sw	$t6,0x24c4($at)
/*  f019a98:	271828c8 */ 	addiu	$t8,$t8,%lo(var800628c8)
/*  f019a9c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f019aa0:	3c05800a */ 	lui	$a1,0x800a
/*  f019aa4:	8ca5cca0 */ 	lw	$a1,-0x3360($a1)
/*  f019aa8:	27af0018 */ 	addiu	$t7,$sp,0x18
/*  f019aac:	ade10000 */ 	sw	$at,0x0($t7)
/*  f019ab0:	8f010008 */ 	lw	$at,0x8($t8)
/*  f019ab4:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f019ab8:	3c048008 */ 	lui	$a0,0x8008
/*  f019abc:	3c060004 */ 	lui	$a2,0x4
/*  f019ac0:	ade10008 */ 	sw	$at,0x8($t7)
/*  f019ac4:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f019ac8:	9484bc70 */ 	lhu	$a0,-0x4390($a0)
/*  f019acc:	34c67800 */ 	ori	$a2,$a2,0x7800
/*  f019ad0:	0fc69de5 */ 	jal	func0f1a7794
/*  f019ad4:	00003825 */ 	or	$a3,$zero,$zero
/*  f019ad8:	3c038008 */ 	lui	$v1,%hi(proptable)
/*  f019adc:	2463b06c */ 	addiu	$v1,$v1,%lo(proptable)
/*  f019ae0:	ac620c00 */ 	sw	$v0,0xc00($v1)
/*  f019ae4:	0c008b49 */ 	jal	func00022d24
/*  f019ae8:	00402025 */ 	or	$a0,$v0,$zero
/*  f019aec:	3c048008 */ 	lui	$a0,0x8008
/*  f019af0:	0fc2cc2b */ 	jal	func0f0b30ac
/*  f019af4:	8c84bc6c */ 	lw	$a0,-0x4394($a0)
/*  f019af8:	3c038006 */ 	lui	$v1,%hi(var800624f8)
/*  f019afc:	246324f8 */ 	addiu	$v1,$v1,%lo(var800624f8)
/*  f019b00:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f019b04:	00402025 */ 	or	$a0,$v0,$zero
/*  f019b08:	0c006bd6 */ 	jal	func0001af58
/*  f019b0c:	3c053f80 */ 	lui	$a1,0x3f80
/*  f019b10:	3c048006 */ 	lui	$a0,0x8006
/*  f019b14:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
/*  f019b18:	0c006b4d */ 	jal	func0001ad34
/*  f019b1c:	27a50018 */ 	addiu	$a1,$sp,0x18
/*  f019b20:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f019b24:	3c018006 */ 	lui	$at,0x8006
/*  f019b28:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f019b2c:	ac2a24f4 */ 	sw	$t2,0x24f4($at)
/*  f019b30:	0c005204 */ 	jal	func00014810
/*  f019b34:	00002025 */ 	or	$a0,$zero,$zero
/*  f019b38:	3c028006 */ 	lui	$v0,%hi(var800624a4)
/*  f019b3c:	244224a4 */ 	addiu	$v0,$v0,%lo(var800624a4)
/*  f019b40:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f019b44:	3c0c8009 */ 	lui	$t4,0x8009
/*  f019b48:	55600007 */ 	bnezl	$t3,.L0f019b68
/*  f019b4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019b50:	918c0af0 */ 	lbu	$t4,0xaf0($t4)
/*  f019b54:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f019b58:	506c0003 */ 	beql	$v1,$t4,.L0f019b68
/*  f019b5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019b60:	ac430000 */ 	sw	$v1,0x0($v0)
/*  f019b64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f019b68:
/*  f019b68:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f019b6c:	03e00008 */ 	jr	$ra
/*  f019b70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f019b74
/*  f019b74:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f019b78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f019b7c:	3c048006 */ 	lui	$a0,0x8006
/*  f019b80:	0fc2cc33 */ 	jal	func0f0b30cc
/*  f019b84:	8c8424f8 */ 	lw	$a0,0x24f8($a0)
/*  f019b88:	0c005204 */ 	jal	func00014810
/*  f019b8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f019b90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019b94:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f019b98:	03e00008 */ 	jr	$ra
/*  f019b9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f019ba0
/*  f019ba0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f019ba4:	3c014270 */ 	lui	$at,0x4270
/*  f019ba8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f019bac:	44816000 */ 	mtc1	$at,$f12
/*  f019bb0:	0c002f4c */ 	jal	func0000bd30
/*  f019bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019bb8:	3c017f1b */ 	lui	$at,%hi(var7f1a84a4)
/*  f019bbc:	0c002f5f */ 	jal	func0000bd7c
/*  f019bc0:	c42c84a4 */ 	lwc1	$f12,%lo(var7f1a84a4)($at)
/*  f019bc4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f019bc8:	44816000 */ 	mtc1	$at,$f12
/*  f019bcc:	3c017f1b */ 	lui	$at,%hi(var7f1a84a8)
/*  f019bd0:	0c002fa1 */ 	jal	func0000be84
/*  f019bd4:	c42e84a8 */ 	lwc1	$f14,%lo(var7f1a84a8)($at)
/*  f019bd8:	0c002f48 */ 	jal	func0000bd20
/*  f019bdc:	00002025 */ 	or	$a0,$zero,$zero
/*  f019be0:	3c088006 */ 	lui	$t0,%hi(var800624c4)
/*  f019be4:	250824c4 */ 	addiu	$t0,$t0,%lo(var800624c4)
/*  f019be8:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f019bec:	04410003 */ 	bgez	$v0,.L0f019bfc
/*  f019bf0:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f019bf4:	10000041 */ 	beqz	$zero,.L0f019cfc
/*  f019bf8:	ad0e0000 */ 	sw	$t6,0x0($t0)
.L0f019bfc:
/*  f019bfc:	14400008 */ 	bnez	$v0,.L0f019c20
/*  f019c00:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f019c04:	2405006b */ 	addiu	$a1,$zero,0x6b
/*  f019c08:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f019c0c:	0fc5b46f */ 	jal	func0f16d1bc
/*  f019c10:	24077fff */ 	addiu	$a3,$zero,0x7fff
/*  f019c14:	3c088006 */ 	lui	$t0,%hi(var800624c4)
/*  f019c18:	250824c4 */ 	addiu	$t0,$t0,%lo(var800624c4)
/*  f019c1c:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f019c20:
/*  f019c20:	3c0f800a */ 	lui	$t7,0x800a
/*  f019c24:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f019c28:	00002025 */ 	or	$a0,$zero,$zero
/*  f019c2c:	3405ffff */ 	dli	$a1,0xffff
/*  f019c30:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f019c34:	0c005408 */ 	jal	func00015020
/*  f019c38:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f019c3c:	3c088006 */ 	lui	$t0,%hi(var800624c4)
/*  f019c40:	1040001d */ 	beqz	$v0,.L0f019cb8
/*  f019c44:	250824c4 */ 	addiu	$t0,$t0,%lo(var800624c4)
/*  f019c48:	3c198000 */ 	lui	$t9,0x8000
/*  f019c4c:	8f39030c */ 	lw	$t9,0x30c($t9)
/*  f019c50:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f019c54:	3c048006 */ 	lui	$a0,%hi(var800624a8)
/*  f019c58:	14790008 */ 	bne	$v1,$t9,.L0f019c7c
/*  f019c5c:	248424a8 */ 	addiu	$a0,$a0,%lo(var800624a8)
/*  f019c60:	3c018006 */ 	lui	$at,0x8006
/*  f019c64:	ac2324a8 */ 	sw	$v1,0x24a8($at)
/*  f019c68:	0fc069f9 */ 	jal	func0f01a7e4
/*  f019c6c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f019c70:	3c088006 */ 	lui	$t0,%hi(var800624c4)
/*  f019c74:	10000010 */ 	beqz	$zero,.L0f019cb8
/*  f019c78:	250824c4 */ 	addiu	$t0,$t0,%lo(var800624c4)
.L0f019c7c:
/*  f019c7c:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f019c80:	5520000e */ 	bnezl	$t1,.L0f019cbc
/*  f019c84:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f019c88:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f019c8c:	2841003c */ 	slti	$at,$v0,0x3c
/*  f019c90:	10200006 */ 	beqz	$at,.L0f019cac
/*  f019c94:	28410064 */ 	slti	$at,$v0,0x64
/*  f019c98:	10200007 */ 	beqz	$at,.L0f019cb8
/*  f019c9c:	ac830000 */ 	sw	$v1,0x0($a0)
/*  f019ca0:	240a0064 */ 	addiu	$t2,$zero,0x64
/*  f019ca4:	10000004 */ 	beqz	$zero,.L0f019cb8
/*  f019ca8:	ad0a0000 */ 	sw	$t2,0x0($t0)
.L0f019cac:
/*  f019cac:	3c018006 */ 	lui	$at,0x8006
/*  f019cb0:	ac2324ac */ 	sw	$v1,0x24ac($at)
/*  f019cb4:	ac830000 */ 	sw	$v1,0x0($a0)
.L0f019cb8:
/*  f019cb8:	8d020000 */ 	lw	$v0,0x0($t0)
.L0f019cbc:
/*  f019cbc:	3c048006 */ 	lui	$a0,%hi(var800624a8)
/*  f019cc0:	248424a8 */ 	addiu	$a0,$a0,%lo(var800624a8)
/*  f019cc4:	284100f1 */ 	slti	$at,$v0,0xf1
/*  f019cc8:	1020000a */ 	beqz	$at,.L0f019cf4
/*  f019ccc:	3c0b8006 */ 	lui	$t3,0x8006
/*  f019cd0:	8d6b24ac */ 	lw	$t3,0x24ac($t3)
/*  f019cd4:	15600007 */ 	bnez	$t3,.L0f019cf4
/*  f019cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f019cdc:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*  f019ce0:	2841008d */ 	slti	$at,$v0,0x8d
/*  f019ce4:	51800006 */ 	beqzl	$t4,.L0f019d00
/*  f019ce8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f019cec:	54200004 */ 	bnezl	$at,.L0f019d00
/*  f019cf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f019cf4:
/*  f019cf4:	0fc069f9 */ 	jal	func0f01a7e4
/*  f019cf8:	24040003 */ 	addiu	$a0,$zero,0x3
.L0f019cfc:
/*  f019cfc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f019d00:
/*  f019d00:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f019d04:	03e00008 */ 	jr	$ra
/*  f019d08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f019d0c
/*  f019d0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f019d10:	44812000 */ 	mtc1	$at,$f4
/*  f019d14:	3c017f1b */ 	lui	$at,%hi(var7f1a84ac)
/*  f019d18:	c42884ac */ 	lwc1	$f8,%lo(var7f1a84ac)($at)
/*  f019d1c:	460c2081 */ 	sub.s	$f2,$f4,$f12
/*  f019d20:	3c017f1b */ 	lui	$at,%hi(var7f1a84b0)
/*  f019d24:	c43084b0 */ 	lwc1	$f16,%lo(var7f1a84b0)($at)
/*  f019d28:	46021180 */ 	add.s	$f6,$f2,$f2
/*  f019d2c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f019d30:	03e00008 */ 	jr	$ra
/*  f019d34:	46105001 */ 	sub.s	$f0,$f10,$f16
);

GLOBAL_ASM(
glabel func0f019d38
/*  f019d38:	27bdfe60 */ 	addiu	$sp,$sp,-416
/*  f019d3c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f019d40:	3c0f8006 */ 	lui	$t7,%hi(var800628d4)
/*  f019d44:	3c108006 */ 	lui	$s0,%hi(var800624c4)
/*  f019d48:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f019d4c:	25ef28d4 */ 	addiu	$t7,$t7,%lo(var800628d4)
/*  f019d50:	0080a025 */ 	or	$s4,$a0,$zero
/*  f019d54:	261024c4 */ 	addiu	$s0,$s0,%lo(var800624c4)
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
/*  f019e04:	0c0068f7 */ 	jal	func0001a3dc
/*  f019e08:	46000306 */ 	mov.s	$f12,$f0
/*  f019e0c:	e7a0010c */ 	swc1	$f0,0x10c($sp)
/*  f019e10:	0fc06743 */ 	jal	func0f019d0c
/*  f019e14:	c7ac0158 */ 	lwc1	$f12,0x158($sp)
/*  f019e18:	0c0068f4 */ 	jal	func0001a3d0
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
/*  f019f50:	0c0068f7 */ 	jal	func0001a3dc
/*  f019f54:	46000306 */ 	mov.s	$f12,$f0
/*  f019f58:	3c013f00 */ 	lui	$at,0x3f00
/*  f019f5c:	44816000 */ 	mtc1	$at,$f12
/*  f019f60:	0fc06743 */ 	jal	func0f019d0c
/*  f019f64:	e7a0010c */ 	swc1	$f0,0x10c($sp)
/*  f019f68:	0c0068f4 */ 	jal	func0001a3d0
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
/*  f01a0b0:	3c138006 */ 	lui	$s3,%hi(var800624f8)
/*  f01a0b4:	267324f8 */ 	addiu	$s3,$s3,%lo(var800624f8)
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

GLOBAL_ASM(
glabel func0f01a360
/*  f01a360:	000471c0 */ 	sll	$t6,$a0,0x7
/*  f01a364:	3c0f800a */ 	lui	$t7,0x800a
/*  f01a368:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f01a36c:	8defa0a4 */ 	lw	$t7,-0x5f5c($t7)
/*  f01a370:	3c02800b */ 	lui	$v0,0x800b
/*  f01a374:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f01a378:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f01a37c:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f01a380:	00581021 */ 	addu	$v0,$v0,$t8
/*  f01a384:	03e00008 */ 	jr	$ra
/*  f01a388:	9042c7c9 */ 	lbu	$v0,-0x3837($v0)
/*  f01a38c:	000471c0 */ 	sll	$t6,$a0,0x7
/*  f01a390:	3c0f800a */ 	lui	$t7,0x800a
/*  f01a394:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f01a398:	8defa0a4 */ 	lw	$t7,-0x5f5c($t7)
/*  f01a39c:	3c01800b */ 	lui	$at,0x800b
/*  f01a3a0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f01a3a4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f01a3a8:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f01a3ac:	00380821 */ 	addu	$at,$at,$t8
/*  f01a3b0:	03e00008 */ 	jr	$ra
/*  f01a3b4:	a025c7c9 */ 	sb	$a1,-0x3837($at)
);

GLOBAL_ASM(
glabel func0f01a3b8
/*  f01a3b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01a3bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01a3c0:	240e0026 */ 	addiu	$t6,$zero,0x26
/*  f01a3c4:	3c018006 */ 	lui	$at,0x8006
/*  f01a3c8:	ac2e24e4 */ 	sw	$t6,0x24e4($at)
/*  f01a3cc:	0fc068d5 */ 	jal	setNumPlayers
/*  f01a3d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f01a3d4:	3c038006 */ 	lui	$v1,%hi(var800624a4)
/*  f01a3d8:	246324a4 */ 	addiu	$v1,$v1,%lo(var800624a4)
/*  f01a3dc:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f01a3e0:	240f0030 */ 	addiu	$t7,$zero,0x30
/*  f01a3e4:	3c018006 */ 	lui	$at,0x8006
/*  f01a3e8:	10400004 */ 	beqz	$v0,.L0f01a3fc
/*  f01a3ec:	3c198009 */ 	lui	$t9,0x8009
/*  f01a3f0:	ac2f24e4 */ 	sw	$t7,0x24e4($at)
/*  f01a3f4:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f01a3f8:	ac780000 */ 	sw	$t8,0x0($v1)
.L0f01a3fc:
/*  f01a3fc:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*  f01a400:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01a404:	2408005d */ 	addiu	$t0,$zero,0x5d
/*  f01a408:	17210011 */ 	bne	$t9,$at,.L0f01a450
/*  f01a40c:	3c018006 */ 	lui	$at,0x8006
/*  f01a410:	ac2824e4 */ 	sw	$t0,0x24e4($at)
/*  f01a414:	3c017f1b */ 	lui	$at,%hi(var7f1a84c0)
/*  f01a418:	0c002f5f */ 	jal	func0000bd7c
/*  f01a41c:	c42c84c0 */ 	lwc1	$f12,%lo(var7f1a84c0)($at)
/*  f01a420:	24040140 */ 	addiu	$a0,$zero,0x140
/*  f01a424:	0c002ef9 */ 	jal	func0000bbe4
/*  f01a428:	240500dc */ 	addiu	$a1,$zero,0xdc
/*  f01a42c:	24040140 */ 	addiu	$a0,$zero,0x140
/*  f01a430:	0c002ee8 */ 	jal	func0000bba0
/*  f01a434:	240500dc */ 	addiu	$a1,$zero,0xdc
/*  f01a438:	24040140 */ 	addiu	$a0,$zero,0x140
/*  f01a43c:	0fc4a2a7 */ 	jal	func0f128a9c
/*  f01a440:	240500dc */ 	addiu	$a1,$zero,0xdc
/*  f01a444:	24040140 */ 	addiu	$a0,$zero,0x140
/*  f01a448:	0c002f0a */ 	jal	func0000bc28
/*  f01a44c:	240500dc */ 	addiu	$a1,$zero,0xdc
.L0f01a450:
/*  f01a450:	3c048006 */ 	lui	$a0,0x8006
/*  f01a454:	0c003a57 */ 	jal	func0000e95c
/*  f01a458:	8c8424e4 */ 	lw	$a0,0x24e4($a0)
/*  f01a45c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f01a460:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f01a464:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f01a468:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f01a46c:	ac430298 */ 	sw	$v1,0x298($v0)
/*  f01a470:	ac43029c */ 	sw	$v1,0x29c($v0)
/*  f01a474:	0fc5b36a */ 	jal	setDifficulty
/*  f01a478:	00002025 */ 	or	$a0,$zero,$zero
/*  f01a47c:	0c0027b1 */ 	jal	func00009ec4
/*  f01a480:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f01a484:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01a488:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01a48c:	03e00008 */ 	jr	$ra
/*  f01a490:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01a494
/*  f01a494:	3c018006 */ 	lui	$at,0x8006
/*  f01a498:	03e00008 */ 	jr	$ra
/*  f01a49c:	ac2024c4 */ 	sw	$zero,0x24c4($at)
);

void func0f01a4a0(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f01a4a8
/*  f01a4a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01a4ac:	3c014270 */ 	lui	$at,0x4270
/*  f01a4b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01a4b4:	44816000 */ 	mtc1	$at,$f12
/*  f01a4b8:	0c002f4c */ 	jal	func0000bd30
/*  f01a4bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a4c0:	3c017f1b */ 	lui	$at,%hi(var7f1a84c4)
/*  f01a4c4:	0c002f5f */ 	jal	func0000bd7c
/*  f01a4c8:	c42c84c4 */ 	lwc1	$f12,%lo(var7f1a84c4)($at)
/*  f01a4cc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f01a4d0:	44816000 */ 	mtc1	$at,$f12
/*  f01a4d4:	3c017f1b */ 	lui	$at,%hi(var7f1a84c8)
/*  f01a4d8:	0c002fa1 */ 	jal	func0000be84
/*  f01a4dc:	c42e84c8 */ 	lwc1	$f14,%lo(var7f1a84c8)($at)
/*  f01a4e0:	0c002f48 */ 	jal	func0000bd20
/*  f01a4e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f01a4e8:	3c028006 */ 	lui	$v0,%hi(var800624c4)
/*  f01a4ec:	244224c4 */ 	addiu	$v0,$v0,%lo(var800624c4)
/*  f01a4f0:	3c0f800a */ 	lui	$t7,0x800a
/*  f01a4f4:	8def9ff8 */ 	lw	$t7,-0x6008($t7)
/*  f01a4f8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f01a4fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01a500:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01a504:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f01a508:	03e00008 */ 	jr	$ra
/*  f01a50c:	ac580000 */ 	sw	$t8,0x0($v0)
);

GLOBAL_ASM(
glabel func0f01a510
/*  f01a510:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f01a514:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f01a518:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f01a51c:	0c005013 */ 	jal	func0001404c
/*  f01a520:	00808025 */ 	or	$s0,$a0,$zero
/*  f01a524:	0fc06bf0 */ 	jal	func0f01afc0
/*  f01a528:	02002025 */ 	or	$a0,$s0,$zero
/*  f01a52c:	0fc54d8a */ 	jal	func0f153628
/*  f01a530:	00402025 */ 	or	$a0,$v0,$zero
/*  f01a534:	00408025 */ 	or	$s0,$v0,$zero
/*  f01a538:	0fc5b9f1 */ 	jal	textGet
/*  f01a53c:	24045647 */ 	addiu	$a0,$zero,0x5647
/*  f01a540:	3c0e8008 */ 	lui	$t6,0x8008
/*  f01a544:	8dcefb1c */ 	lw	$t6,-0x4e4($t6)
/*  f01a548:	3c078008 */ 	lui	$a3,0x8008
/*  f01a54c:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a550:	8ce7fb20 */ 	lw	$a3,-0x4e0($a3)
/*  f01a554:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a558:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a55c:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a560:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a564:	0fc55cbe */ 	jal	func0f1572f8
/*  f01a568:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f01a56c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f01a570:	3c098006 */ 	lui	$t1,0x8006
/*  f01a574:	852924a0 */ 	lh	$t1,0x24a0($t1)
/*  f01a578:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f01a57c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f01a580:	3c0f8008 */ 	lui	$t7,0x8008
/*  f01a584:	8def4120 */ 	lw	$t7,0x4120($t7)
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
/*  f01a5c8:	3c198008 */ 	lui	$t9,0x8008
/*  f01a5cc:	3c188008 */ 	lui	$t8,0x8008
/*  f01a5d0:	8f18fb1c */ 	lw	$t8,-0x4e4($t8)
/*  f01a5d4:	8f39fb20 */ 	lw	$t9,-0x4e0($t9)
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
/*  f01a614:	0fc55b92 */ 	jal	func0f156e48
/*  f01a618:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f01a61c:	10000018 */ 	beqz	$zero,.L0f01a680
/*  f01a620:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a624:
/*  f01a624:	0c002f02 */ 	jal	func0000bc08
/*  f01a628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a62c:	0c002f06 */ 	jal	func0000bc18
/*  f01a630:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a634:	3c0a8008 */ 	lui	$t2,0x8008
/*  f01a638:	3c0c8008 */ 	lui	$t4,0x8008
/*  f01a63c:	8d8cfb1c */ 	lw	$t4,-0x4e4($t4)
/*  f01a640:	8d4afb20 */ 	lw	$t2,-0x4e0($t2)
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
/*  f01a674:	0fc5580f */ 	jal	func0f15603c
/*  f01a678:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f01a67c:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a680:
/*  f01a680:	0fc5b9f1 */ 	jal	textGet
/*  f01a684:	24045648 */ 	addiu	$a0,$zero,0x5648
/*  f01a688:	3c0f8008 */ 	lui	$t7,0x8008
/*  f01a68c:	8deffb1c */ 	lw	$t7,-0x4e4($t7)
/*  f01a690:	3c078008 */ 	lui	$a3,0x8008
/*  f01a694:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f01a698:	8ce7fb20 */ 	lw	$a3,-0x4e0($a3)
/*  f01a69c:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f01a6a0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f01a6a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f01a6a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f01a6ac:	0fc55cbe */ 	jal	func0f1572f8
/*  f01a6b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f01a6b4:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f01a6b8:	3c0b8006 */ 	lui	$t3,0x8006
/*  f01a6bc:	856b24a0 */ 	lh	$t3,0x24a0($t3)
/*  f01a6c0:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f01a6c4:	0019c043 */ 	sra	$t8,$t9,0x1
/*  f01a6c8:	3c198008 */ 	lui	$t9,0x8008
/*  f01a6cc:	8f394120 */ 	lw	$t9,0x4120($t9)
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
/*  f01a710:	3c088008 */ 	lui	$t0,0x8008
/*  f01a714:	3c188008 */ 	lui	$t8,0x8008
/*  f01a718:	8f18fb1c */ 	lw	$t8,-0x4e4($t8)
/*  f01a71c:	8d08fb20 */ 	lw	$t0,-0x4e0($t0)
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
/*  f01a75c:	0fc55b92 */ 	jal	func0f156e48
/*  f01a760:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f01a764:	10000018 */ 	beqz	$zero,.L0f01a7c8
/*  f01a768:	00408025 */ 	or	$s0,$v0,$zero
.L0f01a76c:
/*  f01a76c:	0c002f02 */ 	jal	func0000bc08
/*  f01a770:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a774:	0c002f06 */ 	jal	func0000bc18
/*  f01a778:	a7a20048 */ 	sh	$v0,0x48($sp)
/*  f01a77c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f01a780:	3c0d8008 */ 	lui	$t5,0x8008
/*  f01a784:	8dadfb1c */ 	lw	$t5,-0x4e4($t5)
/*  f01a788:	8d4afb20 */ 	lw	$t2,-0x4e0($t2)
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
/*  f01a7bc:	0fc5580f */ 	jal	func0f15603c
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

GLOBAL_ASM(
glabel func0f01a7e4
/*  f01a7e4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01a7e8:	8dce24c0 */ 	lw	$t6,0x24c0($t6)
/*  f01a7ec:	3c018006 */ 	lui	$at,0x8006
/*  f01a7f0:	108e0002 */ 	beq	$a0,$t6,.L0f01a7fc
/*  f01a7f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a7f8:	ac2424b8 */ 	sw	$a0,0x24b8($at)
.L0f01a7fc:
/*  f01a7fc:	03e00008 */ 	jr	$ra
/*  f01a800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a804:	3c028006 */ 	lui	$v0,0x8006
/*  f01a808:	03e00008 */ 	jr	$ra
/*  f01a80c:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
);

GLOBAL_ASM(
glabel func0f01a810
/*  f01a810:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01a814:	85ce24a0 */ 	lh	$t6,0x24a0($t6)
/*  f01a818:	3c014410 */ 	lui	$at,0x4410
/*  f01a81c:	44812000 */ 	mtc1	$at,$f4
/*  f01a820:	448e3000 */ 	mtc1	$t6,$f6
/*  f01a824:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01a828:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01a82c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f01a830:	0c002f5f */ 	jal	func0000bd7c
/*  f01a834:	46082303 */ 	div.s	$f12,$f4,$f8
/*  f01a838:	3c058006 */ 	lui	$a1,0x8006
/*  f01a83c:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01a840:	0c002ef9 */ 	jal	func0000bbe4
/*  f01a844:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01a848:	3c058006 */ 	lui	$a1,0x8006
/*  f01a84c:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01a850:	0c002ee8 */ 	jal	func0000bba0
/*  f01a854:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01a858:	3c058006 */ 	lui	$a1,0x8006
/*  f01a85c:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01a860:	0fc4a2a7 */ 	jal	func0f128a9c
/*  f01a864:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01a868:	3c058006 */ 	lui	$a1,0x8006
/*  f01a86c:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01a870:	0c002f0a */ 	jal	func0000bc28
/*  f01a874:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01a878:	00002025 */ 	or	$a0,$zero,$zero
/*  f01a87c:	0fc4a2ae */ 	jal	func0f128ab8
/*  f01a880:	00002825 */ 	or	$a1,$zero,$zero
/*  f01a884:	00002025 */ 	or	$a0,$zero,$zero
/*  f01a888:	0c002f2a */ 	jal	func0000bca8
/*  f01a88c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01a890:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a894:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a898:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f01a89c:	3c068006 */ 	lui	$a2,%hi(var800624bc)
/*  f01a8a0:	24c624bc */ 	addiu	$a2,$a2,%lo(var800624bc)
/*  f01a8a4:	04600040 */ 	bltz	$v1,.L0f01a9a8
/*  f01a8a8:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f01a8ac:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f01a8b0:	3c028006 */ 	lui	$v0,0x8006
/*  f01a8b4:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a8b8:	3c018006 */ 	lui	$at,0x8006
/*  f01a8bc:	ac2324c0 */ 	sw	$v1,0x24c0($at)
/*  f01a8c0:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f01a8c4:	1020002f */ 	beqz	$at,.L0f01a984
/*  f01a8c8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f01a8cc:	3c017f1b */ 	lui	$at,%hi(var7f1a84cc)
/*  f01a8d0:	00380821 */ 	addu	$at,$at,$t8
/*  f01a8d4:	8c3884cc */ 	lw	$t8,%lo(var7f1a84cc)($at)
/*  f01a8d8:	03000008 */ 	jr	$t8
/*  f01a8dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a8e0:	0fc05911 */ 	jal	func0f016444
/*  f01a8e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a8e8:	3c028006 */ 	lui	$v0,0x8006
/*  f01a8ec:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a8f0:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a8f4:	10000023 */ 	beqz	$zero,.L0f01a984
/*  f01a8f8:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a8fc:	0fc0593c */ 	jal	func0f0164f0
/*  f01a900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a904:	3c028006 */ 	lui	$v0,0x8006
/*  f01a908:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a90c:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a910:	1000001c */ 	beqz	$zero,.L0f01a984
/*  f01a914:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a918:	0fc05c1b */ 	jal	func0f01706c
/*  f01a91c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a920:	3c028006 */ 	lui	$v0,0x8006
/*  f01a924:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a928:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a92c:	10000015 */ 	beqz	$zero,.L0f01a984
/*  f01a930:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a934:	0fc06538 */ 	jal	func0f0194e0
/*  f01a938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a93c:	3c028006 */ 	lui	$v0,0x8006
/*  f01a940:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a944:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a948:	1000000e */ 	beqz	$zero,.L0f01a984
/*  f01a94c:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a950:	0fc066dd */ 	jal	func0f019b74
/*  f01a954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a958:	3c028006 */ 	lui	$v0,0x8006
/*  f01a95c:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a960:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a964:	10000007 */ 	beqz	$zero,.L0f01a984
/*  f01a968:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01a96c:	0fc06928 */ 	jal	func0f01a4a0
/*  f01a970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01a974:	3c028006 */ 	lui	$v0,0x8006
/*  f01a978:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a97c:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a980:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
.L0f01a984:
/*  f01a984:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01a988:	50410006 */ 	beql	$v0,$at,.L0f01a9a4
/*  f01a98c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f01a990:	0c0027b1 */ 	jal	func00009ec4
/*  f01a994:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f01a998:	3c058006 */ 	lui	$a1,%hi(var800624b8)
/*  f01a99c:	24a524b8 */ 	addiu	$a1,$a1,%lo(var800624b8)
/*  f01a9a0:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f01a9a4:
/*  f01a9a4:	aca40000 */ 	sw	$a0,0x0($a1)
.L0f01a9a8:
/*  f01a9a8:	3c068006 */ 	lui	$a2,%hi(var800624bc)
/*  f01a9ac:	24c624bc */ 	addiu	$a2,$a2,%lo(var800624bc)
/*  f01a9b0:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f01a9b4:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f01a9b8:	3c088006 */ 	lui	$t0,0x8006
/*  f01a9bc:	10400010 */ 	beqz	$v0,.L0f01aa00
/*  f01a9c0:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f01a9c4:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f01a9c8:	8d0824b4 */ 	lw	$t0,0x24b4($t0)
/*  f01a9cc:	54880003 */ 	bnel	$a0,$t0,.L0f01a9dc
/*  f01a9d0:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f01a9d4:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f01a9d8:	8cc90000 */ 	lw	$t1,0x0($a2)
.L0f01a9dc:
/*  f01a9dc:	55200009 */ 	bnezl	$t1,.L0f01aa04
/*  f01a9e0:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f01a9e4:	3c028006 */ 	lui	$v0,0x8006
/*  f01a9e8:	8c4224c0 */ 	lw	$v0,0x24c0($v0)
/*  f01a9ec:	3c018006 */ 	lui	$at,0x8006
/*  f01a9f0:	50820004 */ 	beql	$a0,$v0,.L0f01aa04
/*  f01a9f4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f01a9f8:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f01a9fc:	ac2424c0 */ 	sw	$a0,0x24c0($at)
.L0f01aa00:
/*  f01aa00:	8ca30000 */ 	lw	$v1,0x0($a1)
.L0f01aa04:
/*  f01aa04:	3c018006 */ 	lui	$at,0x8006
/*  f01aa08:	04600038 */ 	bltz	$v1,.L0f01aaec
/*  f01aa0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa10:	ac2324b4 */ 	sw	$v1,0x24b4($at)
/*  f01aa14:	aca40000 */ 	sw	$a0,0x0($a1)
/*  f01aa18:	3c028006 */ 	lui	$v0,0x8006
/*  f01aa1c:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aa20:	3c018006 */ 	lui	$at,0x8006
/*  f01aa24:	ac2024ac */ 	sw	$zero,0x24ac($at)
/*  f01aa28:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f01aa2c:	10200028 */ 	beqz	$at,.L0f01aad0
/*  f01aa30:	00025080 */ 	sll	$t2,$v0,0x2
/*  f01aa34:	3c017f1b */ 	lui	$at,%hi(var7f1a84e8)
/*  f01aa38:	002a0821 */ 	addu	$at,$at,$t2
/*  f01aa3c:	8c2a84e8 */ 	lw	$t2,%lo(var7f1a84e8)($at)
/*  f01aa40:	01400008 */ 	jr	$t2
/*  f01aa44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa48:	0fc05901 */ 	jal	func0f016404
/*  f01aa4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa50:	3c028006 */ 	lui	$v0,0x8006
/*  f01aa54:	1000001e */ 	beqz	$zero,.L0f01aad0
/*  f01aa58:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aa5c:	0fc05932 */ 	jal	func0f0164c8
/*  f01aa60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa64:	3c028006 */ 	lui	$v0,0x8006
/*  f01aa68:	10000019 */ 	beqz	$zero,.L0f01aad0
/*  f01aa6c:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aa70:	0fc05b4d */ 	jal	func0f016d34
/*  f01aa74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa78:	3c028006 */ 	lui	$v0,0x8006
/*  f01aa7c:	10000014 */ 	beqz	$zero,.L0f01aad0
/*  f01aa80:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aa84:	0fc064ff */ 	jal	func0f0193fc
/*  f01aa88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aa8c:	3c028006 */ 	lui	$v0,0x8006
/*  f01aa90:	1000000f */ 	beqz	$zero,.L0f01aad0
/*  f01aa94:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aa98:	0fc066a0 */ 	jal	func0f019a80
/*  f01aa9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aaa0:	3c028006 */ 	lui	$v0,0x8006
/*  f01aaa4:	1000000a */ 	beqz	$zero,.L0f01aad0
/*  f01aaa8:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aaac:	0fc068ee */ 	jal	func0f01a3b8
/*  f01aab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aab4:	3c028006 */ 	lui	$v0,0x8006
/*  f01aab8:	10000005 */ 	beqz	$zero,.L0f01aad0
/*  f01aabc:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01aac0:	0fc06925 */ 	jal	func0f01a494
/*  f01aac4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aac8:	3c028006 */ 	lui	$v0,0x8006
/*  f01aacc:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
.L0f01aad0:
/*  f01aad0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01aad4:	10410005 */ 	beq	$v0,$at,.L0f01aaec
/*  f01aad8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01aadc:	10410003 */ 	beq	$v0,$at,.L0f01aaec
/*  f01aae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aae4:	0c0027b1 */ 	jal	func00009ec4
/*  f01aae8:	00002025 */ 	or	$a0,$zero,$zero
.L0f01aaec:
/*  f01aaec:	3c0b8006 */ 	lui	$t3,0x8006
/*  f01aaf0:	8d6b24b4 */ 	lw	$t3,0x24b4($t3)
/*  f01aaf4:	2d610007 */ 	sltiu	$at,$t3,0x7
/*  f01aaf8:	10200022 */ 	beqz	$at,.L0f01ab84
/*  f01aafc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f01ab00:	3c017f1b */ 	lui	$at,%hi(var7f1a8504)
/*  f01ab04:	002b0821 */ 	addu	$at,$at,$t3
/*  f01ab08:	8c2b8504 */ 	lw	$t3,%lo(var7f1a8504)($at)
/*  f01ab0c:	01600008 */ 	jr	$t3
/*  f01ab10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab14:	0fc05913 */ 	jal	func0f01644c
/*  f01ab18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab1c:	1000001a */ 	beqz	$zero,.L0f01ab88
/*  f01ab20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab24:	0fc05949 */ 	jal	func0f016524
/*  f01ab28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab2c:	10000016 */ 	beqz	$zero,.L0f01ab88
/*  f01ab30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab34:	0fc05c2f */ 	jal	func0f0170bc
/*  f01ab38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab3c:	10000012 */ 	beqz	$zero,.L0f01ab88
/*  f01ab40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab44:	0fc06543 */ 	jal	func0f01950c
/*  f01ab48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab4c:	1000000e */ 	beqz	$zero,.L0f01ab88
/*  f01ab50:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab54:	0fc066e8 */ 	jal	func0f019ba0
/*  f01ab58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab5c:	1000000a */ 	beqz	$zero,.L0f01ab88
/*  f01ab60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab64:	0fc0692a */ 	jal	func0f01a4a8
/*  f01ab68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ab6c:	10000006 */ 	beqz	$zero,.L0f01ab88
/*  f01ab70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ab74:	0c002f48 */ 	jal	func0000bd20
/*  f01ab78:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ab7c:	0fc069f9 */ 	jal	func0f01a7e4
/*  f01ab80:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f01ab84:
/*  f01ab84:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01ab88:
/*  f01ab88:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01ab8c:	03e00008 */ 	jr	$ra
/*  f01ab90:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01ab94
/*  f01ab94:	3c028006 */ 	lui	$v0,0x8006
/*  f01ab98:	8c4224b8 */ 	lw	$v0,0x24b8($v0)
/*  f01ab9c:	284e0000 */ 	slti	$t6,$v0,0x0
/*  f01aba0:	03e00008 */ 	jr	$ra
/*  f01aba4:	39c20001 */ 	xori	$v0,$t6,0x1
);

GLOBAL_ASM(
glabel func0f01aba8
/*  f01aba8:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01abac:	8dce24b8 */ 	lw	$t6,0x24b8($t6)
/*  f01abb0:	3c028006 */ 	lui	$v0,0x8006
/*  f01abb4:	05c00003 */ 	bltz	$t6,.L0f01abc4
/*  f01abb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01abbc:	03e00008 */ 	jr	$ra
/*  f01abc0:	00001025 */ 	or	$v0,$zero,$zero
.L0f01abc4:
/*  f01abc4:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01abc8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01abcc:	10410003 */ 	beq	$v0,$at,.L0f01abdc
/*  f01abd0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01abd4:	54410004 */ 	bnel	$v0,$at,.L0f01abe8
/*  f01abd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01abdc:
/*  f01abdc:	03e00008 */ 	jr	$ra
/*  f01abe0:	00001025 */ 	or	$v0,$zero,$zero
/*  f01abe4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01abe8:
/*  f01abe8:	03e00008 */ 	jr	$ra
/*  f01abec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01abf0
/*  f01abf0:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01abf4:	8dce24b4 */ 	lw	$t6,0x24b4($t6)
/*  f01abf8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01abfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01ac00:	2dc10009 */ 	sltiu	$at,$t6,0x9
/*  f01ac04:	10200020 */ 	beqz	$at,.L0f01ac88
/*  f01ac08:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f01ac0c:	3c017f1b */ 	lui	$at,%hi(var7f1a8520)
/*  f01ac10:	002e0821 */ 	addu	$at,$at,$t6
/*  f01ac14:	8c2e8520 */ 	lw	$t6,%lo(var7f1a8520)($at)
/*  f01ac18:	01c00008 */ 	jr	$t6
/*  f01ac1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac20:	0fc05911 */ 	jal	func0f016444
/*  f01ac24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac28:	10000018 */ 	beqz	$zero,.L0f01ac8c
/*  f01ac2c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac30:	0fc0593c */ 	jal	func0f0164f0
/*  f01ac34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac38:	10000014 */ 	beqz	$zero,.L0f01ac8c
/*  f01ac3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac40:	0fc05c1b */ 	jal	func0f01706c
/*  f01ac44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac48:	10000010 */ 	beqz	$zero,.L0f01ac8c
/*  f01ac4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac50:	0fc06538 */ 	jal	func0f0194e0
/*  f01ac54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac58:	1000000c */ 	beqz	$zero,.L0f01ac8c
/*  f01ac5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac60:	0fc066dd */ 	jal	func0f019b74
/*  f01ac64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac68:	10000008 */ 	beqz	$zero,.L0f01ac8c
/*  f01ac6c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac70:	0fc06928 */ 	jal	func0f01a4a0
/*  f01ac74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ac78:	10000004 */ 	beqz	$zero,.L0f01ac8c
/*  f01ac7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ac80:	0fc06377 */ 	jal	func0f018ddc
/*  f01ac84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01ac88:
/*  f01ac88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01ac8c:
/*  f01ac8c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f01ac90:	3c018006 */ 	lui	$at,0x8006
/*  f01ac94:	ac2224b8 */ 	sw	$v0,0x24b8($at)
/*  f01ac98:	3c018006 */ 	lui	$at,0x8006
/*  f01ac9c:	ac2224b4 */ 	sw	$v0,0x24b4($at)
/*  f01aca0:	03e00008 */ 	jr	$ra
/*  f01aca4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f01aca8
/*  f01aca8:	248effff */ 	addiu	$t6,$a0,-1
/*  f01acac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01acb0:	2dc10005 */ 	sltiu	$at,$t6,0x5
/*  f01acb4:	10200023 */ 	beqz	$at,.L0f01ad44
/*  f01acb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01acbc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f01acc0:	3c017f1b */ 	lui	$at,%hi(var7f1a8544)
/*  f01acc4:	002e0821 */ 	addu	$at,$at,$t6
/*  f01acc8:	8c2e8544 */ 	lw	$t6,%lo(var7f1a8544)($at)
/*  f01accc:	01c00008 */ 	jr	$t6
/*  f01acd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01acd4:	240f0007 */ 	addiu	$t7,$zero,0x7
/*  f01acd8:	3c018006 */ 	lui	$at,0x8006
/*  f01acdc:	0fc0636c */ 	jal	func0f018db0
/*  f01ace0:	ac2f24b4 */ 	sw	$t7,0x24b4($at)
/*  f01ace4:	10000018 */ 	beqz	$zero,.L0f01ad48
/*  f01ace8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01acec:	24180004 */ 	addiu	$t8,$zero,0x4
/*  f01acf0:	3c018006 */ 	lui	$at,0x8006
/*  f01acf4:	0fc066a0 */ 	jal	func0f019a80
/*  f01acf8:	ac3824b4 */ 	sw	$t8,0x24b4($at)
/*  f01acfc:	10000012 */ 	beqz	$zero,.L0f01ad48
/*  f01ad00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ad04:	24190008 */ 	addiu	$t9,$zero,0x8
/*  f01ad08:	3c018006 */ 	lui	$at,0x8006
/*  f01ad0c:	0fc0636c */ 	jal	func0f018db0
/*  f01ad10:	ac3924b4 */ 	sw	$t9,0x24b4($at)
/*  f01ad14:	1000000c */ 	beqz	$zero,.L0f01ad48
/*  f01ad18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ad1c:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f01ad20:	3c018006 */ 	lui	$at,0x8006
/*  f01ad24:	0fc064ff */ 	jal	func0f0193fc
/*  f01ad28:	ac2824b4 */ 	sw	$t0,0x24b4($at)
/*  f01ad2c:	10000006 */ 	beqz	$zero,.L0f01ad48
/*  f01ad30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ad34:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f01ad38:	3c018006 */ 	lui	$at,0x8006
/*  f01ad3c:	0fc05b4d */ 	jal	func0f016d34
/*  f01ad40:	ac2924b4 */ 	sw	$t1,0x24b4($at)
.L0f01ad44:
/*  f01ad44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01ad48:
/*  f01ad48:	240affff */ 	addiu	$t2,$zero,-1
/*  f01ad4c:	3c018006 */ 	lui	$at,0x8006
/*  f01ad50:	ac2a24b8 */ 	sw	$t2,0x24b8($at)
/*  f01ad54:	03e00008 */ 	jr	$ra
/*  f01ad58:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f01ad5c
/*  f01ad5c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01ad60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01ad64:	0fc06aea */ 	jal	func0f01aba8
/*  f01ad68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ad6c:	14400003 */ 	bnez	$v0,.L0f01ad7c
/*  f01ad70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ad74:	1000000e */ 	beqz	$zero,.L0f01adb0
/*  f01ad78:	00001025 */ 	or	$v0,$zero,$zero
.L0f01ad7c:
/*  f01ad7c:	3c028006 */ 	lui	$v0,0x8006
/*  f01ad80:	8c4224b4 */ 	lw	$v0,0x24b4($v0)
/*  f01ad84:	24010008 */ 	addiu	$at,$zero,0x8
/*  f01ad88:	54410004 */ 	bnel	$v0,$at,.L0f01ad9c
/*  f01ad8c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f01ad90:	10000007 */ 	beqz	$zero,.L0f01adb0
/*  f01ad94:	00001025 */ 	or	$v0,$zero,$zero
/*  f01ad98:	24010007 */ 	addiu	$at,$zero,0x7
.L0f01ad9c:
/*  f01ad9c:	54410004 */ 	bnel	$v0,$at,.L0f01adb0
/*  f01ada0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f01ada4:	10000002 */ 	beqz	$zero,.L0f01adb0
/*  f01ada8:	00001025 */ 	or	$v0,$zero,$zero
/*  f01adac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01adb0:
/*  f01adb0:	03e00008 */ 	jr	$ra
/*  f01adb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f01adb8
/*  f01adb8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01adbc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01adc0:	0c002aac */ 	jal	func0000aab0
/*  f01adc4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f01adc8:	3c058006 */ 	lui	$a1,0x8006
/*  f01adcc:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01add0:	0c002ef9 */ 	jal	func0000bbe4
/*  f01add4:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01add8:	3c058006 */ 	lui	$a1,0x8006
/*  f01addc:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01ade0:	0c002ee8 */ 	jal	func0000bba0
/*  f01ade4:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01ade8:	3c058006 */ 	lui	$a1,0x8006
/*  f01adec:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01adf0:	0fc4a2a7 */ 	jal	func0f128a9c
/*  f01adf4:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01adf8:	3c058006 */ 	lui	$a1,0x8006
/*  f01adfc:	84a524a0 */ 	lh	$a1,0x24a0($a1)
/*  f01ae00:	0c002f0a */ 	jal	func0000bc28
/*  f01ae04:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f01ae08:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ae0c:	0fc4a2ae */ 	jal	func0f128ab8
/*  f01ae10:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ae14:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ae18:	0c002f2a */ 	jal	func0000bca8
/*  f01ae1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ae20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ae24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01ae28:	03e00008 */ 	jr	$ra
/*  f01ae2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01ae30
/*  f01ae30:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01ae34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01ae38:	0fc06aea */ 	jal	func0f01aba8
/*  f01ae3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ae40:	50400028 */ 	beqzl	$v0,.L0f01aee4
/*  f01ae44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ae48:	0c005204 */ 	jal	func00014810
/*  f01ae4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ae50:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01ae54:	8dce24bc */ 	lw	$t6,0x24bc($t6)
/*  f01ae58:	3c0f8006 */ 	lui	$t7,0x8006
/*  f01ae5c:	55c00021 */ 	bnezl	$t6,.L0f01aee4
/*  f01ae60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ae64:	8def24b4 */ 	lw	$t7,0x24b4($t7)
/*  f01ae68:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f01ae6c:	1020001c */ 	beqz	$at,.L0f01aee0
/*  f01ae70:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f01ae74:	3c017f1b */ 	lui	$at,%hi(var7f1a8558)
/*  f01ae78:	002f0821 */ 	addu	$at,$at,$t7
/*  f01ae7c:	8c2f8558 */ 	lw	$t7,%lo(var7f1a8558)($at)
/*  f01ae80:	01e00008 */ 	jr	$t7
/*  f01ae84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ae88:	0fc05913 */ 	jal	func0f01644c
/*  f01ae8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ae90:	10000014 */ 	beqz	$zero,.L0f01aee4
/*  f01ae94:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ae98:	0fc05949 */ 	jal	func0f016524
/*  f01ae9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aea0:	10000010 */ 	beqz	$zero,.L0f01aee4
/*  f01aea4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01aea8:	0fc05c2f */ 	jal	func0f0170bc
/*  f01aeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aeb0:	1000000c */ 	beqz	$zero,.L0f01aee4
/*  f01aeb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01aeb8:	0fc06543 */ 	jal	func0f01950c
/*  f01aebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aec0:	10000008 */ 	beqz	$zero,.L0f01aee4
/*  f01aec4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01aec8:	0fc06387 */ 	jal	func0f018e1c
/*  f01aecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01aed0:	10000004 */ 	beqz	$zero,.L0f01aee4
/*  f01aed4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01aed8:	0fc066e8 */ 	jal	func0f019ba0
/*  f01aedc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01aee0:
/*  f01aee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01aee4:
/*  f01aee4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01aee8:	03e00008 */ 	jr	$ra
/*  f01aeec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01aef0
/*  f01aef0:	3c0e8006 */ 	lui	$t6,0x8006
/*  f01aef4:	8dce24bc */ 	lw	$t6,0x24bc($t6)
/*  f01aef8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f01aefc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f01af00:	00808025 */ 	or	$s0,$a0,$zero
/*  f01af04:	15c00026 */ 	bnez	$t6,.L0f01afa0
/*  f01af08:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f01af0c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f01af10:	8def24b4 */ 	lw	$t7,0x24b4($t7)
/*  f01af14:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f01af18:	10200021 */ 	beqz	$at,.L0f01afa0
/*  f01af1c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f01af20:	3c017f1b */ 	lui	$at,%hi(var7f1a857c)
/*  f01af24:	002f0821 */ 	addu	$at,$at,$t7
/*  f01af28:	8c2f857c */ 	lw	$t7,%lo(var7f1a857c)($at)
/*  f01af2c:	01e00008 */ 	jr	$t7
/*  f01af30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01af34:	0fc059bb */ 	jal	func0f0166ec
/*  f01af38:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af3c:	10000018 */ 	beqz	$zero,.L0f01afa0
/*  f01af40:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af44:	0fc0596b */ 	jal	func0f0165ac
/*  f01af48:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af4c:	10000014 */ 	beqz	$zero,.L0f01afa0
/*  f01af50:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af54:	0fc05eb0 */ 	jal	func0f017ac0
/*  f01af58:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af5c:	10000010 */ 	beqz	$zero,.L0f01afa0
/*  f01af60:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af64:	0fc06596 */ 	jal	func0f019658
/*  f01af68:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af6c:	1000000c */ 	beqz	$zero,.L0f01afa0
/*  f01af70:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af74:	0fc06422 */ 	jal	func0f019088
/*  f01af78:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af7c:	10000008 */ 	beqz	$zero,.L0f01afa0
/*  f01af80:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af84:	0fc0674e */ 	jal	func0f019d38
/*  f01af88:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af8c:	10000004 */ 	beqz	$zero,.L0f01afa0
/*  f01af90:	00408025 */ 	or	$s0,$v0,$zero
/*  f01af94:	0fc06944 */ 	jal	func0f01a510
/*  f01af98:	02002025 */ 	or	$a0,$s0,$zero
/*  f01af9c:	00408025 */ 	or	$s0,$v0,$zero
.L0f01afa0:
/*  f01afa0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f01afa4:	02001025 */ 	or	$v0,$s0,$zero
/*  f01afa8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01afac:	03e00008 */ 	jr	$ra
/*  f01afb0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f01afb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01afb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01afbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01afc0
/*  f01afc0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f01afc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f01afc8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f01afcc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f01afd0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f01afd4:	3c0f0030 */ 	lui	$t7,0x30
/*  f01afd8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f01afdc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f01afe0:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f01afe4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f01afe8:	0c002f02 */ 	jal	func0000bc08
/*  f01afec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01aff0:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f01aff4:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f01aff8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f01affc:	3c01ff10 */ 	lui	$at,0xff10
/*  f01b000:	03214025 */ 	or	$t0,$t9,$at
/*  f01b004:	0c002ac7 */ 	jal	func0000ab1c
/*  f01b008:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f01b00c:	0c012d20 */ 	jal	func0004b480
/*  f01b010:	00402025 */ 	or	$a0,$v0,$zero
/*  f01b014:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f01b018:	02001825 */ 	or	$v1,$s0,$zero
/*  f01b01c:	3c0c0001 */ 	lui	$t4,0x1
/*  f01b020:	ad420004 */ 	sw	$v0,0x4($t2)
/*  f01b024:	358c0001 */ 	ori	$t4,$t4,0x1
/*  f01b028:	3c0bf700 */ 	lui	$t3,0xf700
/*  f01b02c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f01b030:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f01b034:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01b038:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f01b03c:	0c002f02 */ 	jal	func0000bc08
/*  f01b040:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01b044:	0c002f06 */ 	jal	func0000bc18
/*  f01b048:	a7a20022 */ 	sh	$v0,0x22($sp)
/*  f01b04c:	87b90022 */ 	lh	$t9,0x22($sp)
/*  f01b050:	244dffff */ 	addiu	$t5,$v0,-1
/*  f01b054:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f01b058:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f01b05c:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f01b060:	310903ff */ 	andi	$t1,$t0,0x3ff
/*  f01b064:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f01b068:	3c01f600 */ 	lui	$at,0xf600
/*  f01b06c:	01e1c025 */ 	or	$t8,$t7,$at
/*  f01b070:	00095380 */ 	sll	$t2,$t1,0xe
/*  f01b074:	030a5825 */ 	or	$t3,$t8,$t2
/*  f01b078:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f01b07c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f01b080:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f01b084:	02001025 */ 	or	$v0,$s0,$zero
/*  f01b088:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f01b08c:	03e00008 */ 	jr	$ra
/*  f01b090:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f01b094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b09c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b0a0
/*  f01b0a0:	44800000 */ 	mtc1	$zero,$f0
/*  f01b0a4:	03e00008 */ 	jr	$ra
/*  f01b0a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b0ac
/*  f01b0ac:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b0b0:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b0b4:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b0b8:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b0bc:	51e00004 */ 	beqzl	$t7,.L0f01b0d0
/*  f01b0c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b0c4:	03e00008 */ 	jr	$ra
/*  f01b0c8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f01b0cc:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b0d0:
/*  f01b0d0:	44810000 */ 	mtc1	$at,$f0
/*  f01b0d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b0d8:	03e00008 */ 	jr	$ra
/*  f01b0dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b0e0
/*  f01b0e0:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b0e4:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b0e8:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b0ec:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b0f0:	51e00004 */ 	beqzl	$t7,.L0f01b104
/*  f01b0f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b0f8:	03e00008 */ 	jr	$ra
/*  f01b0fc:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f01b100:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b104:
/*  f01b104:	44810000 */ 	mtc1	$at,$f0
/*  f01b108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b10c:	03e00008 */ 	jr	$ra
/*  f01b110:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b114
/*  f01b114:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f01b118:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f01b11c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01b120:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f01b124:	51e00004 */ 	beqzl	$t7,.L0f01b138
/*  f01b128:	3c013f80 */ 	lui	$at,0x3f80
/*  f01b12c:	03e00008 */ 	jr	$ra
/*  f01b130:	c4400014 */ 	lwc1	$f0,0x14($v0)
/*  f01b134:	3c013f80 */ 	lui	$at,0x3f80
.L0f01b138:
/*  f01b138:	44810000 */ 	mtc1	$at,$f0
/*  f01b13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b140:	03e00008 */ 	jr	$ra
/*  f01b144:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01b148
/*  f01b148:	3c018006 */ 	lui	$at,0x8006
/*  f01b14c:	03e00008 */ 	jr	$ra
/*  f01b150:	ac2424e0 */ 	sw	$a0,0x24e0($at)
);

GLOBAL_ASM(
glabel func0f01b154
/*  f01b154:	3c018006 */ 	lui	$at,0x8006
/*  f01b158:	03e00008 */ 	jr	$ra
/*  f01b15c:	ac2424e4 */ 	sw	$a0,0x24e4($at)
);

GLOBAL_ASM(
glabel func0f01b160
/*  f01b160:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f01b164:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f01b168:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f01b16c:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f01b170:	8cce028c */ 	lw	$t6,0x28c($a2)
/*  f01b174:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f01b178:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f01b17c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f01b180:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f01b184:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f01b188:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f01b18c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f01b190:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f01b194:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f01b198:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f01b19c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f01b1a0:	00003825 */ 	or	$a3,$zero,$zero
/*  f01b1a4:	11e00003 */ 	beqz	$t7,.L0f01b1b4
/*  f01b1a8:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f01b1ac:	10000002 */ 	beqz	$zero,.L0f01b1b8
/*  f01b1b0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01b1b4:
/*  f01b1b4:	00002825 */ 	or	$a1,$zero,$zero
.L0f01b1b8:
/*  f01b1b8:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f01b1bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b1c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f01b1c4:	13000003 */ 	beqz	$t8,.L0f01b1d4
/*  f01b1c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f01b1cc:	10000001 */ 	beqz	$zero,.L0f01b1d4
/*  f01b1d0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f01b1d4:
/*  f01b1d4:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f01b1d8:	3c017f1b */ 	lui	$at,%hi(var7f1a85a4)
/*  f01b1dc:	13200003 */ 	beqz	$t9,.L0f01b1ec
/*  f01b1e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1e4:	10000001 */ 	beqz	$zero,.L0f01b1ec
/*  f01b1e8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f01b1ec:
/*  f01b1ec:	8cc80070 */ 	lw	$t0,0x70($a2)
/*  f01b1f0:	11000003 */ 	beqz	$t0,.L0f01b200
/*  f01b1f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b1f8:	10000001 */ 	beqz	$zero,.L0f01b200
/*  f01b1fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01b200:
/*  f01b200:	00434821 */ 	addu	$t1,$v0,$v1
/*  f01b204:	01245021 */ 	addu	$t2,$t1,$a0
/*  f01b208:	01455821 */ 	addu	$t3,$t2,$a1
/*  f01b20c:	19600313 */ 	blez	$t3,.L0f01be5c
/*  f01b210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b214:	afa700d8 */ 	sw	$a3,0xd8($sp)
/*  f01b218:	c43485a4 */ 	lwc1	$f20,%lo(var7f1a85a4)($at)
.L0f01b21c:
/*  f01b21c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01b220:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f01b224:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b228:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b22c:	8cec028c */ 	lw	$t4,0x28c($a3)
/*  f01b230:	3c01800a */ 	lui	$at,0x800a
/*  f01b234:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b238:	ac2c21b8 */ 	sw	$t4,0x21b8($at)
/*  f01b23c:	8dad21b8 */ 	lw	$t5,0x21b8($t5)
/*  f01b240:	3c0f800a */ 	lui	$t7,0x800a
/*  f01b244:	2404003c */ 	addiu	$a0,$zero,0x3c
/*  f01b248:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f01b24c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f01b250:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f01b254:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f01b258:	91ef2100 */ 	lbu	$t7,0x2100($t7)
/*  f01b25c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01b260:	51e0000f */ 	beqzl	$t7,.L0f01b2a0
/*  f01b264:	8ce80318 */ 	lw	$t0,0x318($a3)
/*  f01b268:	0fc2a257 */ 	jal	func0f0a895c
/*  f01b26c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f01b270:	18400009 */ 	blez	$v0,.L0f01b298
/*  f01b274:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b278:	3c18800a */ 	lui	$t8,0x800a
/*  f01b27c:	8f1821b8 */ 	lw	$t8,0x21b8($t8)
/*  f01b280:	3c01800a */ 	lui	$at,0x800a
/*  f01b284:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f01b288:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f01b28c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f01b290:	00390821 */ 	addu	$at,$at,$t9
/*  f01b294:	a0202100 */ 	sb	$zero,0x2100($at)
.L0f01b298:
/*  f01b298:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b29c:	8ce80318 */ 	lw	$t0,0x318($a3)
.L0f01b2a0:
/*  f01b2a0:	1500000f */ 	bnez	$t0,.L0f01b2e0
/*  f01b2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2a8:	0fc44a54 */ 	jal	func0f112950
/*  f01b2ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2b0:	3c09800a */ 	lui	$t1,0x800a
/*  f01b2b4:	8d2921b8 */ 	lw	$t1,0x21b8($t1)
/*  f01b2b8:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b2bc:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f01b2c0:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01b2c4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f01b2c8:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f01b2cc:	916b2101 */ 	lbu	$t3,0x2101($t3)
/*  f01b2d0:	104b0003 */ 	beq	$v0,$t3,.L0f01b2e0
/*  f01b2d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2d8:	0fc3fb35 */ 	jal	func0f0fecd4
/*  f01b2dc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b2e0:
/*  f01b2e0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01b2e4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01b2e8:	8cec0284 */ 	lw	$t4,0x284($a3)
/*  f01b2ec:	918d0250 */ 	lbu	$t5,0x250($t4)
/*  f01b2f0:	11a00244 */ 	beqz	$t5,.L0f01bc04
/*  f01b2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b2f8:	8cee0288 */ 	lw	$t6,0x288($a3)
/*  f01b2fc:	0000f025 */ 	or	$s8,$zero,$zero
/*  f01b300:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f01b304:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f01b308:	3c0f800a */ 	lui	$t7,0x800a
/*  f01b30c:	8defa248 */ 	lw	$t7,-0x5db8($t7)
/*  f01b310:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f01b314:	0fc549d2 */ 	jal	optionsGetUnk45
/*  f01b318:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f01b31c:	0c005207 */ 	jal	func0001481c
/*  f01b320:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f01b324:	18400237 */ 	blez	$v0,.L0f01bc04
/*  f01b328:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f01b32c:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f01b330:
/*  f01b330:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b334:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b338:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f01b33c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b340:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b344:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b348:	0c005212 */ 	jal	func00014848
/*  f01b34c:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f01b350:	0002b600 */ 	sll	$s6,$v0,0x18
/*  f01b354:	0016c603 */ 	sra	$t8,$s6,0x18
/*  f01b358:	0300b025 */ 	or	$s6,$t8,$zero
/*  f01b35c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b360:	0c005241 */ 	jal	func00014904
/*  f01b364:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b368:	0002be00 */ 	sll	$s7,$v0,0x18
/*  f01b36c:	0017ce03 */ 	sra	$t9,$s7,0x18
/*  f01b370:	0320b825 */ 	or	$s7,$t9,$zero
/*  f01b374:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b378:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b37c:	0c00529e */ 	jal	func00014a78
/*  f01b380:	3406ffff */ 	dli	$a2,0xffff
/*  f01b384:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b388:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b38c:	83a500d3 */ 	lb	$a1,0xd3($sp)
/*  f01b390:	0c0052d4 */ 	jal	func00014b50
/*  f01b394:	3406ffff */ 	dli	$a2,0xffff
/*  f01b398:	3c08800a */ 	lui	$t0,0x800a
/*  f01b39c:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b3a0:	3c0a800a */ 	lui	$t2,%hi(g_ActiveMenuThings)
/*  f01b3a4:	254a20d0 */ 	addiu	$t2,$t2,%lo(g_ActiveMenuThings)
/*  f01b3a8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b3ac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b3b0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b3b4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b3b8:	a2000032 */ 	sb	$zero,0x32($s0)
/*  f01b3bc:	3c0b800a */ 	lui	$t3,0x800a
/*  f01b3c0:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f01b3c4:	a7a200be */ 	sh	$v0,0xbe($sp)
/*  f01b3c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b3cc:	916c0250 */ 	lbu	$t4,0x250($t3)
/*  f01b3d0:	02206825 */ 	or	$t5,$s1,$zero
/*  f01b3d4:	55810006 */ 	bnel	$t4,$at,.L0f01b3f0
/*  f01b3d8:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f01b3dc:	31b18000 */ 	andi	$s1,$t5,0x8000
/*  f01b3e0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f01b3e4:	0000b825 */ 	or	$s7,$zero,$zero
/*  f01b3e8:	a7a000be */ 	sh	$zero,0xbe($sp)
/*  f01b3ec:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.L0f01b3f0:
/*  f01b3f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b3f4:	32380010 */ 	andi	$t8,$s1,0x10
/*  f01b3f8:	11e10003 */ 	beq	$t7,$at,.L0f01b408
/*  f01b3fc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01b400:	15e1000c */ 	bne	$t7,$at,.L0f01b434
/*  f01b404:	322b8000 */ 	andi	$t3,$s1,0x8000
.L0f01b408:
/*  f01b408:	17000003 */ 	bnez	$t8,.L0f01b418
/*  f01b40c:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b410:	32390020 */ 	andi	$t9,$s1,0x20
/*  f01b414:	13200002 */ 	beqz	$t9,.L0f01b420
.L0f01b418:
/*  f01b418:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f01b41c:	afa800b0 */ 	sw	$t0,0xb0($sp)
.L0f01b420:
/*  f01b420:	32498000 */ 	andi	$t1,$s2,0x8000
/*  f01b424:	1120000d */ 	beqz	$t1,.L0f01b45c
/*  f01b428:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b42c:	1000000b */ 	beqz	$zero,.L0f01b45c
/*  f01b430:	a20a0032 */ 	sb	$t2,0x32($s0)
.L0f01b434:
/*  f01b434:	11600003 */ 	beqz	$t3,.L0f01b444
/*  f01b438:	02209025 */ 	or	$s2,$s1,$zero
/*  f01b43c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f01b440:	afac00b0 */ 	sw	$t4,0xb0($sp)
.L0f01b444:
/*  f01b444:	324d0010 */ 	andi	$t5,$s2,0x10
/*  f01b448:	15a00002 */ 	bnez	$t5,.L0f01b454
/*  f01b44c:	324e0020 */ 	andi	$t6,$s2,0x20
/*  f01b450:	11c00002 */ 	beqz	$t6,.L0f01b45c
.L0f01b454:
/*  f01b454:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b458:	a20f0032 */ 	sb	$t7,0x32($s0)
.L0f01b45c:
/*  f01b45c:	92020032 */ 	lbu	$v0,0x32($s0)
/*  f01b460:	10400016 */ 	beqz	$v0,.L0f01b4bc
/*  f01b464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b468:	82030000 */ 	lb	$v1,0x0($s0)
/*  f01b46c:	28610002 */ 	slti	$at,$v1,0x2
/*  f01b470:	14200012 */ 	bnez	$at,.L0f01b4bc
/*  f01b474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b478:	82180034 */ 	lb	$t8,0x34($s0)
/*  f01b47c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f01b480:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b484:	1700000d */ 	bnez	$t8,.L0f01b4bc
/*  f01b488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b48c:	a2030034 */ 	sb	$v1,0x34($s0)
/*  f01b490:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01b494:	a2190000 */ 	sb	$t9,0x0($s0)
/*  f01b498:	3c08800a */ 	lui	$t0,0x800a
/*  f01b49c:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b4a0:	3c0a800a */ 	lui	$t2,%hi(g_ActiveMenuThings)
/*  f01b4a4:	254a20d0 */ 	addiu	$t2,$t2,%lo(g_ActiveMenuThings)
/*  f01b4a8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b4ac:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b4b0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b4b4:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f01b4b8:	92020032 */ 	lbu	$v0,0x32($s0)
.L0f01b4bc:
/*  f01b4bc:	54400009 */ 	bnezl	$v0,.L0f01b4e4
/*  f01b4c0:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b4c4:	82020034 */ 	lb	$v0,0x34($s0)
/*  f01b4c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01b4cc:	50400005 */ 	beqzl	$v0,.L0f01b4e4
/*  f01b4d0:	324b0008 */ 	andi	$t3,$s2,0x8
/*  f01b4d4:	a2020000 */ 	sb	$v0,0x0($s0)
/*  f01b4d8:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01b4dc:	a2000034 */ 	sb	$zero,0x34($s0)
/*  f01b4e0:	324b0008 */ 	andi	$t3,$s2,0x8
.L0f01b4e4:
/*  f01b4e4:	11600002 */ 	beqz	$t3,.L0f01b4f0
/*  f01b4e8:	324c0004 */ 	andi	$t4,$s2,0x4
/*  f01b4ec:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b4f0:
/*  f01b4f0:	11800002 */ 	beqz	$t4,.L0f01b4fc
/*  f01b4f4:	324d0002 */ 	andi	$t5,$s2,0x2
/*  f01b4f8:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b4fc:
/*  f01b4fc:	11a00002 */ 	beqz	$t5,.L0f01b508
/*  f01b500:	324e0001 */ 	andi	$t6,$s2,0x1
/*  f01b504:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b508:
/*  f01b508:	11c00002 */ 	beqz	$t6,.L0f01b514
/*  f01b50c:	324f0800 */ 	andi	$t7,$s2,0x800
/*  f01b510:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b514:
/*  f01b514:	11e00002 */ 	beqz	$t7,.L0f01b520
/*  f01b518:	32580400 */ 	andi	$t8,$s2,0x400
/*  f01b51c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b520:
/*  f01b520:	13000002 */ 	beqz	$t8,.L0f01b52c
/*  f01b524:	32590200 */ 	andi	$t9,$s2,0x200
/*  f01b528:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b52c:
/*  f01b52c:	13200002 */ 	beqz	$t9,.L0f01b538
/*  f01b530:	32480100 */ 	andi	$t0,$s2,0x100
/*  f01b534:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b538:
/*  f01b538:	11000002 */ 	beqz	$t0,.L0f01b544
/*  f01b53c:	8fa900d4 */ 	lw	$t1,0xd4($sp)
/*  f01b540:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b544:
/*  f01b544:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01b548:	11210008 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b54c:	3c0a800a */ 	lui	$t2,0x800a
/*  f01b550:	24010007 */ 	addiu	$at,$zero,0x7
/*  f01b554:	11210005 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b558:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01b55c:	11210003 */ 	beq	$t1,$at,.L0f01b56c
/*  f01b560:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b564:	15210089 */ 	bne	$t1,$at,.L0f01b78c
/*  f01b568:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b56c:
/*  f01b56c:	8d4aa248 */ 	lw	$t2,-0x5db8($t2)
/*  f01b570:	0fc549d9 */ 	jal	optionsGetUnk46
/*  f01b574:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f01b578:	00028600 */ 	sll	$s0,$v0,0x18
/*  f01b57c:	00022e00 */ 	sll	$a1,$v0,0x18
/*  f01b580:	00105e03 */ 	sra	$t3,$s0,0x18
/*  f01b584:	00056603 */ 	sra	$t4,$a1,0x18
/*  f01b588:	01608025 */ 	or	$s0,$t3,$zero
/*  f01b58c:	01802825 */ 	or	$a1,$t4,$zero
/*  f01b590:	0c005212 */ 	jal	func00014848
/*  f01b594:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b598:	00029600 */ 	sll	$s2,$v0,0x18
/*  f01b59c:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5a0:	00126e03 */ 	sra	$t5,$s2,0x18
/*  f01b5a4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f01b5a8:	01a09025 */ 	or	$s2,$t5,$zero
/*  f01b5ac:	01c02825 */ 	or	$a1,$t6,$zero
/*  f01b5b0:	0c005241 */ 	jal	func00014904
/*  f01b5b4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5b8:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f01b5bc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5c0:	00137e03 */ 	sra	$t7,$s3,0x18
/*  f01b5c4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f01b5c8:	01e09825 */ 	or	$s3,$t7,$zero
/*  f01b5cc:	03002825 */ 	or	$a1,$t8,$zero
/*  f01b5d0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5d4:	0c00529e */ 	jal	func00014a78
/*  f01b5d8:	3406ffff */ 	dli	$a2,0xffff
/*  f01b5dc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f01b5e0:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f01b5e4:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f01b5e8:	03202825 */ 	or	$a1,$t9,$zero
/*  f01b5ec:	03c02025 */ 	or	$a0,$s8,$zero
/*  f01b5f0:	0c0052d4 */ 	jal	func00014b50
/*  f01b5f4:	3406ffff */ 	dli	$a2,0xffff
/*  f01b5f8:	3c08800a */ 	lui	$t0,0x800a
/*  f01b5fc:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f01b600:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b604:	3043ffff */ 	andi	$v1,$v0,0xffff
/*  f01b608:	91090250 */ 	lbu	$t1,0x250($t0)
/*  f01b60c:	02205025 */ 	or	$t2,$s1,$zero
/*  f01b610:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f01b614:	15210005 */ 	bne	$t1,$at,.L0f01b62c
/*  f01b618:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01b61c:	31518000 */ 	andi	$s1,$t2,0x8000
/*  f01b620:	00009025 */ 	or	$s2,$zero,$zero
/*  f01b624:	00009825 */ 	or	$s3,$zero,$zero
/*  f01b628:	00001825 */ 	or	$v1,$zero,$zero
.L0f01b62c:
/*  f01b62c:	322c8000 */ 	andi	$t4,$s1,0x8000
/*  f01b630:	11800002 */ 	beqz	$t4,.L0f01b63c
/*  f01b634:	02201025 */ 	or	$v0,$s1,$zero
/*  f01b638:	afad00b0 */ 	sw	$t5,0xb0($sp)
.L0f01b63c:
/*  f01b63c:	306e2000 */ 	andi	$t6,$v1,0x2000
/*  f01b640:	11c00002 */ 	beqz	$t6,.L0f01b64c
/*  f01b644:	30580008 */ 	andi	$t8,$v0,0x8
/*  f01b648:	afaf00ac */ 	sw	$t7,0xac($sp)
.L0f01b64c:
/*  f01b64c:	13000002 */ 	beqz	$t8,.L0f01b658
/*  f01b650:	30590004 */ 	andi	$t9,$v0,0x4
/*  f01b654:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b658:
/*  f01b658:	13200002 */ 	beqz	$t9,.L0f01b664
/*  f01b65c:	30480002 */ 	andi	$t0,$v0,0x2
/*  f01b660:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b664:
/*  f01b664:	11000002 */ 	beqz	$t0,.L0f01b670
/*  f01b668:	30490001 */ 	andi	$t1,$v0,0x1
/*  f01b66c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b670:
/*  f01b670:	11200002 */ 	beqz	$t1,.L0f01b67c
/*  f01b674:	304a0800 */ 	andi	$t2,$v0,0x800
/*  f01b678:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b67c:
/*  f01b67c:	11400002 */ 	beqz	$t2,.L0f01b688
/*  f01b680:	304b0400 */ 	andi	$t3,$v0,0x400
/*  f01b684:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b688:
/*  f01b688:	11600002 */ 	beqz	$t3,.L0f01b694
/*  f01b68c:	304c0200 */ 	andi	$t4,$v0,0x200
/*  f01b690:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b694:
/*  f01b694:	11800002 */ 	beqz	$t4,.L0f01b6a0
/*  f01b698:	304d0100 */ 	andi	$t5,$v0,0x100
/*  f01b69c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b6a0:
/*  f01b6a0:	11a00002 */ 	beqz	$t5,.L0f01b6ac
/*  f01b6a4:	00121e00 */ 	sll	$v1,$s2,0x18
/*  f01b6a8:	24150002 */ 	addiu	$s5,$zero,0x2
.L0f01b6ac:
/*  f01b6ac:	06410005 */ 	bgez	$s2,.L0f01b6c4
/*  f01b6b0:	0003c603 */ 	sra	$t8,$v1,0x18
/*  f01b6b4:	00121823 */ 	negu	$v1,$s2
/*  f01b6b8:	00037600 */ 	sll	$t6,$v1,0x18
/*  f01b6bc:	10000002 */ 	beqz	$zero,.L0f01b6c8
/*  f01b6c0:	000e1e03 */ 	sra	$v1,$t6,0x18
.L0f01b6c4:
/*  f01b6c4:	03001825 */ 	or	$v1,$t8,$zero
.L0f01b6c8:
/*  f01b6c8:	06610005 */ 	bgez	$s3,.L0f01b6e0
/*  f01b6cc:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b6d0:	00131023 */ 	negu	$v0,$s3
/*  f01b6d4:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f01b6d8:	10000004 */ 	beqz	$zero,.L0f01b6ec
/*  f01b6dc:	00191603 */ 	sra	$v0,$t9,0x18
.L0f01b6e0:
/*  f01b6e0:	00131600 */ 	sll	$v0,$s3,0x18
/*  f01b6e4:	00024e03 */ 	sra	$t1,$v0,0x18
/*  f01b6e8:	01201025 */ 	or	$v0,$t1,$zero
.L0f01b6ec:
/*  f01b6ec:	10200004 */ 	beqz	$at,.L0f01b700
/*  f01b6f0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f01b6f4:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b6f8:	14200024 */ 	bnez	$at,.L0f01b78c
/*  f01b6fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b700:
/*  f01b700:	44822000 */ 	mtc1	$v0,$f4
/*  f01b704:	44833000 */ 	mtc1	$v1,$f6
/*  f01b708:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f01b70c:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f01b710:	46020203 */ 	div.s	$f8,$f0,$f2
/*  f01b714:	4614403c */ 	c.lt.s	$f8,$f20
/*  f01b718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b71c:	45020008 */ 	bc1fl	.L0f01b740
/*  f01b720:	46001283 */ 	div.s	$f10,$f2,$f0
/*  f01b724:	06410003 */ 	bgez	$s2,.L0f01b734
/*  f01b728:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b72c:	10000016 */ 	beqz	$zero,.L0f01b788
/*  f01b730:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b734:
/*  f01b734:	10000014 */ 	beqz	$zero,.L0f01b788
/*  f01b738:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b73c:	46001283 */ 	div.s	$f10,$f2,$f0
.L0f01b740:
/*  f01b740:	4614503c */ 	c.lt.s	$f10,$f20
/*  f01b744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b748:	45000007 */ 	bc1f	.L0f01b768
/*  f01b74c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b750:	06610003 */ 	bgez	$s3,.L0f01b760
/*  f01b754:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b758:	1000000b */ 	beqz	$zero,.L0f01b788
/*  f01b75c:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b760:
/*  f01b760:	10000009 */ 	beqz	$zero,.L0f01b788
/*  f01b764:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b768:
/*  f01b768:	06410003 */ 	bgez	$s2,.L0f01b778
/*  f01b76c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b770:	10000001 */ 	beqz	$zero,.L0f01b778
/*  f01b774:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b778:
/*  f01b778:	06610003 */ 	bgez	$s3,.L0f01b788
/*  f01b77c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b780:	10000001 */ 	beqz	$zero,.L0f01b788
/*  f01b784:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b788:
/*  f01b788:	afaa00b8 */ 	sw	$t2,0xb8($sp)
.L0f01b78c:
/*  f01b78c:	3c04800a */ 	lui	$a0,0x800a
/*  f01b790:	06c10005 */ 	bgez	$s6,.L0f01b7a8
/*  f01b794:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01b798:	00161823 */ 	negu	$v1,$s6
/*  f01b79c:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f01b7a0:	10000004 */ 	beqz	$zero,.L0f01b7b4
/*  f01b7a4:	000b1e03 */ 	sra	$v1,$t3,0x18
.L0f01b7a8:
/*  f01b7a8:	00161e00 */ 	sll	$v1,$s6,0x18
/*  f01b7ac:	00036e03 */ 	sra	$t5,$v1,0x18
/*  f01b7b0:	01a01825 */ 	or	$v1,$t5,$zero
.L0f01b7b4:
/*  f01b7b4:	06e10005 */ 	bgez	$s7,.L0f01b7cc
/*  f01b7b8:	28610015 */ 	slti	$at,$v1,0x15
/*  f01b7bc:	00171023 */ 	negu	$v0,$s7
/*  f01b7c0:	00027600 */ 	sll	$t6,$v0,0x18
/*  f01b7c4:	10000004 */ 	beqz	$zero,.L0f01b7d8
/*  f01b7c8:	000e1603 */ 	sra	$v0,$t6,0x18
.L0f01b7cc:
/*  f01b7cc:	00171600 */ 	sll	$v0,$s7,0x18
/*  f01b7d0:	0002c603 */ 	sra	$t8,$v0,0x18
/*  f01b7d4:	03001025 */ 	or	$v0,$t8,$zero
.L0f01b7d8:
/*  f01b7d8:	10200004 */ 	beqz	$at,.L0f01b7ec
/*  f01b7dc:	3c09800a */ 	lui	$t1,0x800a
/*  f01b7e0:	28410015 */ 	slti	$at,$v0,0x15
/*  f01b7e4:	54200026 */ 	bnezl	$at,.L0f01b880
/*  f01b7e8:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.L0f01b7ec:
/*  f01b7ec:	44828000 */ 	mtc1	$v0,$f16
/*  f01b7f0:	44839000 */ 	mtc1	$v1,$f18
/*  f01b7f4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01b7f8:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f01b7fc:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f01b800:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f01b804:	46020103 */ 	div.s	$f4,$f0,$f2
/*  f01b808:	4614203c */ 	c.lt.s	$f4,$f20
/*  f01b80c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b810:	45020008 */ 	bc1fl	.L0f01b834
/*  f01b814:	46001183 */ 	div.s	$f6,$f2,$f0
/*  f01b818:	06c10003 */ 	bgez	$s6,.L0f01b828
/*  f01b81c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f01b820:	10000016 */ 	beqz	$zero,.L0f01b87c
/*  f01b824:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b828:
/*  f01b828:	10000014 */ 	beqz	$zero,.L0f01b87c
/*  f01b82c:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b830:	46001183 */ 	div.s	$f6,$f2,$f0
.L0f01b834:
/*  f01b834:	4614303c */ 	c.lt.s	$f6,$f20
/*  f01b838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b83c:	45000007 */ 	bc1f	.L0f01b85c
/*  f01b840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b844:	06e10003 */ 	bgez	$s7,.L0f01b854
/*  f01b848:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f01b84c:	1000000b */ 	beqz	$zero,.L0f01b87c
/*  f01b850:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b854:
/*  f01b854:	10000009 */ 	beqz	$zero,.L0f01b87c
/*  f01b858:	0000a025 */ 	or	$s4,$zero,$zero
.L0f01b85c:
/*  f01b85c:	06c10003 */ 	bgez	$s6,.L0f01b86c
/*  f01b860:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f01b864:	10000001 */ 	beqz	$zero,.L0f01b86c
/*  f01b868:	0000a825 */ 	or	$s5,$zero,$zero
.L0f01b86c:
/*  f01b86c:	06e10003 */ 	bgez	$s7,.L0f01b87c
/*  f01b870:	0000a025 */ 	or	$s4,$zero,$zero
/*  f01b874:	10000001 */ 	beqz	$zero,.L0f01b87c
/*  f01b878:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f01b87c:
/*  f01b87c:	8c8800d8 */ 	lw	$t0,0xd8($a0)
.L0f01b880:
/*  f01b880:	3c0c8007 */ 	lui	$t4,0x8007
/*  f01b884:	11000002 */ 	beqz	$t0,.L0f01b890
/*  f01b888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b88c:	afa000b0 */ 	sw	$zero,0xb0($sp)
.L0f01b890:
/*  f01b890:	8d299ff4 */ 	lw	$t1,-0x600c($t1)
/*  f01b894:	55200003 */ 	bnezl	$t1,.L0f01b8a4
/*  f01b898:	8faa00b0 */ 	lw	$t2,0xb0($sp)
/*  f01b89c:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f01b8a0:	8faa00b0 */ 	lw	$t2,0xb0($sp)
.L0f01b8a4:
/*  f01b8a4:	97af00be */ 	lhu	$t7,0xbe($sp)
/*  f01b8a8:	15400016 */ 	bnez	$t2,.L0f01b904
/*  f01b8ac:	31f82000 */ 	andi	$t8,$t7,0x2000
/*  f01b8b0:	908b0250 */ 	lbu	$t3,0x250($a0)
/*  f01b8b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01b8b8:	1561000e */ 	bne	$t3,$at,.L0f01b8f4
/*  f01b8bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b8c0:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f01b8c4:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b8c8:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f01b8cc:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01b8d0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01b8d4:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f01b8d8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f01b8dc:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01b8e0:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f01b8e4:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f01b8e8:	8dcee4f8 */ 	lw	$t6,-0x1b08($t6)
/*  f01b8ec:	15c00005 */ 	bnez	$t6,.L0f01b904
/*  f01b8f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b8f4:
/*  f01b8f4:	0fc3fc10 */ 	jal	func0f0ff040
/*  f01b8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b8fc:	100000c1 */ 	beqz	$zero,.L0f01bc04
/*  f01b900:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01b904:
/*  f01b904:	13000002 */ 	beqz	$t8,.L0f01b910
/*  f01b908:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01b90c:	afb900ac */ 	sw	$t9,0xac($sp)
.L0f01b910:
/*  f01b910:	8fa800ac */ 	lw	$t0,0xac($sp)
/*  f01b914:	3c09800a */ 	lui	$t1,0x800a
/*  f01b918:	51000047 */ 	beqzl	$t0,.L0f01ba38
/*  f01b91c:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01b920:	8d2921b8 */ 	lw	$t1,0x21b8($t1)
/*  f01b924:	3c0b800a */ 	lui	$t3,%hi(g_ActiveMenuThings)
/*  f01b928:	256b20d0 */ 	addiu	$t3,$t3,%lo(g_ActiveMenuThings)
/*  f01b92c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f01b930:	01495023 */ 	subu	$t2,$t2,$t1
/*  f01b934:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f01b938:	014b8021 */ 	addu	$s0,$t2,$t3
/*  f01b93c:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f01b940:	3c0d800a */ 	lui	$t5,0x800a
/*  f01b944:	29810002 */ 	slti	$at,$t4,0x2
/*  f01b948:	54200032 */ 	bnezl	$at,.L0f01ba14
/*  f01b94c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b950:	8dada434 */ 	lw	$t5,-0x5bcc($t5)
/*  f01b954:	3c0e800a */ 	lui	$t6,0x800a
/*  f01b958:	51a00010 */ 	beqzl	$t5,.L0f01b99c
/*  f01b95c:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b960:	81cfdfeb */ 	lb	$t7,-0x2015($t6)
/*  f01b964:	05e3000d */ 	bgezl	$t7,.L0f01b99c
/*  f01b968:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f01b96c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01b970:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b974:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f01b978:	14810003 */ 	bne	$a0,$at,.L0f01b988
/*  f01b97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b980:	1000002c */ 	beqz	$zero,.L0f01ba34
/*  f01b984:	a3b800c7 */ 	sb	$t8,0xc7($sp)
.L0f01b988:
/*  f01b988:	0fc3f7c5 */ 	jal	func0f0fdf14
/*  f01b98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b990:	10000029 */ 	beqz	$zero,.L0f01ba38
/*  f01b994:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01b998:	9202000e */ 	lbu	$v0,0xe($s0)
.L0f01b99c:
/*  f01b99c:	3c19800b */ 	lui	$t9,0x800b
/*  f01b9a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01b9a4:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f01b9a8:	9339cb78 */ 	lbu	$t9,-0x3488($t9)
/*  f01b9ac:	5721000d */ 	bnel	$t9,$at,.L0f01b9e4
/*  f01b9b0:	920a0032 */ 	lbu	$t2,0x32($s0)
/*  f01b9b4:	0fc3f598 */ 	jal	func0f0fd660
/*  f01b9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01b9bc:	3c08800a */ 	lui	$t0,0x800a
/*  f01b9c0:	8d0821b8 */ 	lw	$t0,0x21b8($t0)
/*  f01b9c4:	3c02800a */ 	lui	$v0,0x800a
/*  f01b9c8:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f01b9cc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f01b9d0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f01b9d4:	00491021 */ 	addu	$v0,$v0,$t1
/*  f01b9d8:	10000006 */ 	beqz	$zero,.L0f01b9f4
/*  f01b9dc:	904220de */ 	lbu	$v0,0x20de($v0)
/*  f01b9e0:	920a0032 */ 	lbu	$t2,0x32($s0)
.L0f01b9e4:
/*  f01b9e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f01b9e8:	55400003 */ 	bnezl	$t2,.L0f01b9f8
/*  f01b9ec:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01b9f0:	a3ab00c7 */ 	sb	$t3,0xc7($sp)
.L0f01b9f4:
/*  f01b9f4:	24010004 */ 	addiu	$at,$zero,0x4
.L0f01b9f8:
/*  f01b9f8:	1041000e */ 	beq	$v0,$at,.L0f01ba34
/*  f01b9fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f01ba00:	0fc3f7c5 */ 	jal	func0f0fdf14
/*  f01ba04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba08:	1000000b */ 	beqz	$zero,.L0f01ba38
/*  f01ba0c:	83ad00c7 */ 	lb	$t5,0xc7($sp)
/*  f01ba10:	9204000e */ 	lbu	$a0,0xe($s0)
.L0f01ba14:
/*  f01ba14:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01ba18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f01ba1c:	14810003 */ 	bne	$a0,$at,.L0f01ba2c
/*  f01ba20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba24:	10000003 */ 	beqz	$zero,.L0f01ba34
/*  f01ba28:	a3ac00c7 */ 	sb	$t4,0xc7($sp)
.L0f01ba2c:
/*  f01ba2c:	0fc3f7c5 */ 	jal	func0f0fdf14
/*  f01ba30:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01ba34:
/*  f01ba34:	83ad00c7 */ 	lb	$t5,0xc7($sp)
.L0f01ba38:
/*  f01ba38:	11a0001f */ 	beqz	$t5,.L0f01bab8
/*  f01ba3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba40:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01ba44:	01a02025 */ 	or	$a0,$t5,$zero
/*  f01ba48:	3c0e800a */ 	lui	$t6,0x800a
/*  f01ba4c:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f01ba50:	3c18800a */ 	lui	$t8,0x800a
/*  f01ba54:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01ba58:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f01ba5c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f01ba60:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f01ba64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f01ba68:	831820d0 */ 	lb	$t8,0x20d0($t8)
/*  f01ba6c:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f01ba70:	17010011 */ 	bne	$t8,$at,.L0f01bab8
/*  f01ba74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ba78:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01ba7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ba80:	0fc2c42e */ 	jal	func0f0b10b8
/*  f01ba84:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f01ba88:	3c04800a */ 	lui	$a0,%hi(var800a0638)
/*  f01ba8c:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f01ba90:	00408025 */ 	or	$s0,$v0,$zero
/*  f01ba94:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f01ba98:	0fc2c42e */ 	jal	func0f0b10b8
/*  f01ba9c:	24840638 */ 	addiu	$a0,$a0,%lo(var800a0638)
/*  f01baa0:	16000005 */ 	bnez	$s0,.L0f01bab8
/*  f01baa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01baa8:	14400003 */ 	bnez	$v0,.L0f01bab8
/*  f01baac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bab0:	0fc3fade */ 	jal	activemenuChangeScreen
/*  f01bab4:	83a400c7 */ 	lb	$a0,0xc7($sp)
.L0f01bab8:
/*  f01bab8:	3c19800a */ 	lui	$t9,0x800a
/*  f01babc:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f01bac0:	00144880 */ 	sll	$t1,$s4,0x2
/*  f01bac4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bac8:	93280250 */ 	lbu	$t0,0x250($t9)
/*  f01bacc:	01344823 */ 	subu	$t1,$t1,$s4
/*  f01bad0:	02a99021 */ 	addu	$s2,$s5,$t1
/*  f01bad4:	11010046 */ 	beq	$t0,$at,.L0f01bbf0
/*  f01bad8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01badc:	16410011 */ 	bne	$s2,$at,.L0f01bb24
/*  f01bae0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f01bae4:	3c0a800a */ 	lui	$t2,0x800a
/*  f01bae8:	8d4a21b8 */ 	lw	$t2,0x21b8($t2)
/*  f01baec:	3c0c800a */ 	lui	$t4,%hi(g_ActiveMenuThings)
/*  f01baf0:	258c20d0 */ 	addiu	$t4,$t4,%lo(g_ActiveMenuThings)
/*  f01baf4:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f01baf8:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f01bafc:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f01bb00:	016c8021 */ 	addu	$s0,$t3,$t4
/*  f01bb04:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f01bb08:	1c400004 */ 	bgtz	$v0,.L0f01bb1c
/*  f01bb0c:	244dffff */ 	addiu	$t5,$v0,-1
/*  f01bb10:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f01bb14:	10000036 */ 	beqz	$zero,.L0f01bbf0
/*  f01bb18:	a212000e */ 	sb	$s2,0xe($s0)
.L0f01bb1c:
/*  f01bb1c:	10000034 */ 	beqz	$zero,.L0f01bbf0
/*  f01bb20:	ae0d0014 */ 	sw	$t5,0x14($s0)
.L0f01bb24:
/*  f01bb24:	02402025 */ 	or	$a0,$s2,$zero
/*  f01bb28:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f01bb2c:	0fc3f8a0 */ 	jal	func0f0fe280
/*  f01bb30:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f01bb34:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f01bb38:	24a585a0 */ 	addiu	$a1,$a1,-31328
/*  f01bb3c:	0c004c9d */ 	jal	func00013274
/*  f01bb40:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f01bb44:	14400002 */ 	bnez	$v0,.L0f01bb50
/*  f01bb48:	3c0e800a */ 	lui	$t6,0x800a
/*  f01bb4c:	00008825 */ 	or	$s1,$zero,$zero
.L0f01bb50:
/*  f01bb50:	8dce21b8 */ 	lw	$t6,0x21b8($t6)
/*  f01bb54:	3c18800a */ 	lui	$t8,%hi(g_ActiveMenuThings)
/*  f01bb58:	271820d0 */ 	addiu	$t8,$t8,%lo(g_ActiveMenuThings)
/*  f01bb5c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f01bb60:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f01bb64:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f01bb68:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f01bb6c:	9204000e */ 	lbu	$a0,0xe($s0)
/*  f01bb70:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01bb74:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f01bb78:	10810019 */ 	beq	$a0,$at,.L0f01bbe0
/*  f01bb7c:	240b000f */ 	addiu	$t3,$zero,0xf
/*  f01bb80:	17200017 */ 	bnez	$t9,.L0f01bbe0
/*  f01bb84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bb88:	10800007 */ 	beqz	$a0,.L0f01bba8
/*  f01bb8c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bb90:	10810005 */ 	beq	$a0,$at,.L0f01bba8
/*  f01bb94:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01bb98:	10810003 */ 	beq	$a0,$at,.L0f01bba8
/*  f01bb9c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f01bba0:	1481000f */ 	bne	$a0,$at,.L0f01bbe0
/*  f01bba4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01bba8:
/*  f01bba8:	9208000f */ 	lbu	$t0,0xf($s0)
/*  f01bbac:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f01bbb0:	52480005 */ 	beql	$s2,$t0,.L0f01bbc8
/*  f01bbb4:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f01bbb8:	ae090010 */ 	sw	$t1,0x10($s0)
/*  f01bbbc:	a212000f */ 	sb	$s2,0xf($s0)
/*  f01bbc0:	00008825 */ 	or	$s1,$zero,$zero
/*  f01bbc4:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f01bbc8:
/*  f01bbc8:	18400005 */ 	blez	$v0,.L0f01bbe0
/*  f01bbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bbd0:	12200003 */ 	beqz	$s1,.L0f01bbe0
/*  f01bbd4:	244affff */ 	addiu	$t2,$v0,-1
/*  f01bbd8:	00008825 */ 	or	$s1,$zero,$zero
/*  f01bbdc:	ae0a0010 */ 	sw	$t2,0x10($s0)
.L0f01bbe0:
/*  f01bbe0:	52200004 */ 	beqzl	$s1,.L0f01bbf4
/*  f01bbe4:	8fac00cc */ 	lw	$t4,0xcc($sp)
/*  f01bbe8:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*  f01bbec:	a212000e */ 	sb	$s2,0xe($s0)
.L0f01bbf0:
/*  f01bbf0:	8fac00cc */ 	lw	$t4,0xcc($sp)
.L0f01bbf4:
/*  f01bbf4:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f01bbf8:	03cc082a */ 	slt	$at,$s8,$t4
/*  f01bbfc:	5420fdcc */ 	bnezl	$at,.L0f01b330
/*  f01bc00:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f01bc04:
/*  f01bc04:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01bc08:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01bc0c:	8ced0284 */ 	lw	$t5,0x284($a3)
/*  f01bc10:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01bc14:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f01bc18:	91ae0250 */ 	lbu	$t6,0x250($t5)
/*  f01bc1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01bc20:	3c0f800a */ 	lui	$t7,0x800a
/*  f01bc24:	11c1006e */ 	beq	$t6,$at,.L0f01bde0
/*  f01bc28:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f01bc2c:	8def21b8 */ 	lw	$t7,0x21b8($t7)
/*  f01bc30:	3c19800a */ 	lui	$t9,%hi(g_ActiveMenuThings)
/*  f01bc34:	273920d0 */ 	addiu	$t9,$t9,%lo(g_ActiveMenuThings)
/*  f01bc38:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f01bc3c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f01bc40:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f01bc44:	03198021 */ 	addu	$s0,$t8,$t9
/*  f01bc48:	8603000a */ 	lh	$v1,0xa($s0)
/*  f01bc4c:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f01bc50:	50610026 */ 	beql	$v1,$at,.L0f01bcec
/*  f01bc54:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01bc58:	86080006 */ 	lh	$t0,0x6($s0)
/*  f01bc5c:	8604000c */ 	lh	$a0,0xc($s0)
/*  f01bc60:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f01bc64:	00684821 */ 	addu	$t1,$v1,$t0
/*  f01bc68:	05210003 */ 	bgez	$t1,.L0f01bc78
/*  f01bc6c:	00095043 */ 	sra	$t2,$t1,0x1
/*  f01bc70:	25210001 */ 	addiu	$at,$t1,0x1
/*  f01bc74:	00015043 */ 	sra	$t2,$at,0x1
.L0f01bc78:
/*  f01bc78:	a60a0006 */ 	sh	$t2,0x6($s0)
/*  f01bc7c:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f01bc80:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f01bc84:	05810003 */ 	bgez	$t4,.L0f01bc94
/*  f01bc88:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f01bc8c:	25810001 */ 	addiu	$at,$t4,0x1
/*  f01bc90:	00016843 */ 	sra	$t5,$at,0x1
.L0f01bc94:
/*  f01bc94:	01c31023 */ 	subu	$v0,$t6,$v1
/*  f01bc98:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f01bc9c:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f01bca0:	2b010002 */ 	slti	$at,$t8,0x2
/*  f01bca4:	10200006 */ 	beqz	$at,.L0f01bcc0
/*  f01bca8:	a60d0008 */ 	sh	$t5,0x8($s0)
/*  f01bcac:	2b01ffff */ 	slti	$at,$t8,-1
/*  f01bcb0:	54200004 */ 	bnezl	$at,.L0f01bcc4
/*  f01bcb4:	86190008 */ 	lh	$t9,0x8($s0)
/*  f01bcb8:	a6030006 */ 	sh	$v1,0x6($s0)
/*  f01bcbc:	8604000c */ 	lh	$a0,0xc($s0)
.L0f01bcc0:
/*  f01bcc0:	86190008 */ 	lh	$t9,0x8($s0)
.L0f01bcc4:
/*  f01bcc4:	03241023 */ 	subu	$v0,$t9,$a0
/*  f01bcc8:	00024400 */ 	sll	$t0,$v0,0x10
/*  f01bccc:	00084c03 */ 	sra	$t1,$t0,0x10
/*  f01bcd0:	29210002 */ 	slti	$at,$t1,0x2
/*  f01bcd4:	10200004 */ 	beqz	$at,.L0f01bce8
/*  f01bcd8:	2921ffff */ 	slti	$at,$t1,-1
/*  f01bcdc:	54200003 */ 	bnezl	$at,.L0f01bcec
/*  f01bce0:	86020004 */ 	lh	$v0,0x4($s0)
/*  f01bce4:	a6040008 */ 	sh	$a0,0x8($s0)
.L0f01bce8:
/*  f01bce8:	86020004 */ 	lh	$v0,0x4($s0)
.L0f01bcec:
/*  f01bcec:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f01bcf0:	24420005 */ 	addiu	$v0,$v0,0x5
/*  f01bcf4:	00025400 */ 	sll	$t2,$v0,0x10
/*  f01bcf8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f01bcfc:	000a5c03 */ 	sra	$t3,$t2,0x10
/*  f01bd00:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f01bd04:	01ab7021 */ 	addu	$t6,$t5,$t3
/*  f01bd08:	01601025 */ 	or	$v0,$t3,$zero
/*  f01bd0c:	05c10003 */ 	bgez	$t6,.L0f01bd1c
/*  f01bd10:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f01bd14:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f01bd18:	00017883 */ 	sra	$t7,$at,0x2
.L0f01bd1c:
/*  f01bd1c:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f01bd20:	86180002 */ 	lh	$t8,0x2($s0)
/*  f01bd24:	03021823 */ 	subu	$v1,$t8,$v0
/*  f01bd28:	0003cc00 */ 	sll	$t9,$v1,0x10
/*  f01bd2c:	00194403 */ 	sra	$t0,$t9,0x10
/*  f01bd30:	29010002 */ 	slti	$at,$t0,0x2
/*  f01bd34:	10200004 */ 	beqz	$at,.L0f01bd48
/*  f01bd38:	2901ffff */ 	slti	$at,$t0,-1
/*  f01bd3c:	54200003 */ 	bnezl	$at,.L0f01bd4c
/*  f01bd40:	3c013f80 */ 	lui	$at,0x3f80
/*  f01bd44:	a6020002 */ 	sh	$v0,0x2($s0)
.L0f01bd48:
/*  f01bd48:	3c013f80 */ 	lui	$at,0x3f80
.L0f01bd4c:
/*  f01bd4c:	44816000 */ 	mtc1	$at,$f12
/*  f01bd50:	c6000018 */ 	lwc1	$f0,0x18($s0)
/*  f01bd54:	3c01800a */ 	lui	$at,0x800a
/*  f01bd58:	460c003c */ 	c.lt.s	$f0,$f12
/*  f01bd5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd60:	45000009 */ 	bc1f	.L0f01bd88
/*  f01bd64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd68:	c428a004 */ 	lwc1	$f8,-0x5ffc($at)
/*  f01bd6c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f01bd70:	44815000 */ 	mtc1	$at,$f10
/*  f01bd74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bd78:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f01bd7c:	46100480 */ 	add.s	$f18,$f0,$f16
/*  f01bd80:	e6120018 */ 	swc1	$f18,0x18($s0)
/*  f01bd84:	c6000018 */ 	lwc1	$f0,0x18($s0)
.L0f01bd88:
/*  f01bd88:	3c01800a */ 	lui	$at,0x800a
/*  f01bd8c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f01bd90:	c422a004 */ 	lwc1	$f2,-0x5ffc($at)
/*  f01bd94:	3c0140a0 */ 	lui	$at,0x40a0
/*  f01bd98:	44813000 */ 	mtc1	$at,$f6
/*  f01bd9c:	45000002 */ 	bc1f	.L0f01bda8
/*  f01bda0:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f01bda4:	e60c0018 */ 	swc1	$f12,0x18($s0)
.L0f01bda8:
/*  f01bda8:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*  f01bdac:	3c017f1b */ 	lui	$at,%hi(var7f1a85a8)
/*  f01bdb0:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f01bdb4:	e60a001c */ 	swc1	$f10,0x1c($s0)
/*  f01bdb8:	c43085a8 */ 	lwc1	$f16,%lo(var7f1a85a8)($at)
/*  f01bdbc:	c600001c */ 	lwc1	$f0,0x1c($s0)
/*  f01bdc0:	3c017f1b */ 	lui	$at,%hi(var7f1a85ac)
/*  f01bdc4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f01bdc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bdcc:	45020005 */ 	bc1fl	.L0f01bde4
/*  f01bdd0:	8ce9006c */ 	lw	$t1,0x6c($a3)
/*  f01bdd4:	c43285ac */ 	lwc1	$f18,%lo(var7f1a85ac)($at)
/*  f01bdd8:	46120181 */ 	sub.s	$f6,$f0,$f18
/*  f01bddc:	e606001c */ 	swc1	$f6,0x1c($s0)
.L0f01bde0:
/*  f01bde0:	8ce9006c */ 	lw	$t1,0x6c($a3)
.L0f01bde4:
/*  f01bde4:	8fa600d8 */ 	lw	$a2,0xd8($sp)
/*  f01bde8:	3c0b800a */ 	lui	$t3,0x800a
/*  f01bdec:	11200003 */ 	beqz	$t1,.L0f01bdfc
/*  f01bdf0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f01bdf4:	10000001 */ 	beqz	$zero,.L0f01bdfc
/*  f01bdf8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01bdfc:
/*  f01bdfc:	8cea0068 */ 	lw	$t2,0x68($a3)
/*  f01be00:	3c0c800a */ 	lui	$t4,0x800a
/*  f01be04:	00002025 */ 	or	$a0,$zero,$zero
/*  f01be08:	11400003 */ 	beqz	$t2,.L0f01be18
/*  f01be0c:	00001825 */ 	or	$v1,$zero,$zero
/*  f01be10:	10000001 */ 	beqz	$zero,.L0f01be18
/*  f01be14:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f01be18:
/*  f01be18:	8d6ba024 */ 	lw	$t3,-0x5fdc($t3)
/*  f01be1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f01be20:	11600003 */ 	beqz	$t3,.L0f01be30
/*  f01be24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be28:	10000001 */ 	beqz	$zero,.L0f01be30
/*  f01be2c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f01be30:
/*  f01be30:	8d8ca030 */ 	lw	$t4,-0x5fd0($t4)
/*  f01be34:	11800003 */ 	beqz	$t4,.L0f01be44
/*  f01be38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be3c:	10000001 */ 	beqz	$zero,.L0f01be44
/*  f01be40:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f01be44:
/*  f01be44:	00436821 */ 	addu	$t5,$v0,$v1
/*  f01be48:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f01be4c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f01be50:	00cf082a */ 	slt	$at,$a2,$t7
/*  f01be54:	1420fcf1 */ 	bnez	$at,.L0f01b21c
/*  f01be58:	afa600d8 */ 	sw	$a2,0xd8($sp)
.L0f01be5c:
/*  f01be5c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01be60:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f01be64:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f01be68:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f01be6c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f01be70:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f01be74:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f01be78:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f01be7c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f01be80:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f01be84:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f01be88:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f01be8c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f01be90:	03e00008 */ 	jr	$ra
/*  f01be94:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
/*  f01be98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01be9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01bea0
/*  f01bea0:	3c028006 */ 	lui	$v0,%hi(var80062944)
/*  f01bea4:	24422944 */ 	addiu	$v0,$v0,%lo(var80062944)
/*  f01bea8:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f01beac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01beb0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01beb4:	11c00006 */ 	beqz	$t6,.L0f01bed0
/*  f01beb8:	3c018006 */ 	lui	$at,0x8006
/*  f01bebc:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f01bec0:	0c004e72 */ 	jal	func000139c8
/*  f01bec4:	a0202948 */ 	sb	$zero,0x2948($at)
/*  f01bec8:	0fc442fe */ 	jal	func0f110bf8
/*  f01becc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01bed0:
/*  f01bed0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01bed4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01bed8:	03e00008 */ 	jr	$ra
/*  f01bedc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01bee0
/*  f01bee0:	3c04800a */ 	lui	$a0,%hi(var800a19c0)
/*  f01bee4:	248419c0 */ 	addiu	$a0,$a0,%lo(var800a19c0)
/*  f01bee8:	3c03800a */ 	lui	$v1,%hi(var8009e000)
/*  f01beec:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f01bef0:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f01bef4:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f01bef8:	2463e000 */ 	addiu	$v1,$v1,%lo(var8009e000)
/*  f01befc:	8c6e04f8 */ 	lw	$t6,0x4f8($v1)
.L0f01bf00:
/*  f01bf00:	24630e70 */ 	addiu	$v1,$v1,0xe70
/*  f01bf04:	11c00004 */ 	beqz	$t6,.L0f01bf18
/*  f01bf08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bf0c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f01bf10:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f01bf14:	ac980000 */ 	sw	$t8,0x0($a0)
.L0f01bf18:
/*  f01bf18:	5462fff9 */ 	bnel	$v1,$v0,.L0f01bf00
/*  f01bf1c:	8c6e04f8 */ 	lw	$t6,0x4f8($v1)
/*  f01bf20:	03e00008 */ 	jr	$ra
/*  f01bf24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f01bf28
/*  f01bf28:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f01bf2c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f01bf30:	8dce06c8 */ 	lw	$t6,0x6c8($t6)
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
/*  f01bf68:	3c018008 */ 	lui	$at,0x8008
/*  f01bf6c:	10000003 */ 	beqz	$zero,.L0f01bf7c
/*  f01bf70:	ac2ffac0 */ 	sw	$t7,-0x540($at)
.L0f01bf74:
/*  f01bf74:	3c018008 */ 	lui	$at,0x8008
/*  f01bf78:	ac36fac0 */ 	sw	$s6,-0x540($at)
.L0f01bf7c:
/*  f01bf7c:	0fc01a77 */ 	jal	func0f0069dc
/*  f01bf80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bf84:	3c15800a */ 	lui	$s5,%hi(var800a19c0)
/*  f01bf88:	0fc06fb8 */ 	jal	func0f01bee0
/*  f01bf8c:	26b519c0 */ 	addiu	$s5,$s5,%lo(var800a19c0)
/*  f01bf90:	3c03800a */ 	lui	$v1,%hi(var8009e000)
/*  f01bf94:	3c05800a */ 	lui	$a1,%hi(var800a19c0)
/*  f01bf98:	24a519c0 */ 	addiu	$a1,$a1,%lo(var800a19c0)
/*  f01bf9c:	2463e000 */ 	addiu	$v1,$v1,%lo(var8009e000)
/*  f01bfa0:	9062083c */ 	lbu	$v0,0x83c($v1)
.L0f01bfa4:
/*  f01bfa4:	18400002 */ 	blez	$v0,.L0f01bfb0
/*  f01bfa8:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f01bfac:	a078083c */ 	sb	$t8,0x83c($v1)
.L0f01bfb0:
/*  f01bfb0:	8c7904f8 */ 	lw	$t9,0x4f8($v1)
/*  f01bfb4:	24630e70 */ 	addiu	$v1,$v1,0xe70
/*  f01bfb8:	13200002 */ 	beqz	$t9,.L0f01bfc4
/*  f01bfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bfc0:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01bfc4:
/*  f01bfc4:	5465fff7 */ 	bnel	$v1,$a1,.L0f01bfa4
/*  f01bfc8:	9062083c */ 	lbu	$v0,0x83c($v1)
/*  f01bfcc:	16000009 */ 	bnez	$s0,.L0f01bff4
/*  f01bfd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bfd4:	92ad0014 */ 	lbu	$t5,0x14($s5)
/*  f01bfd8:	11a00006 */ 	beqz	$t5,.L0f01bff4
/*  f01bfdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01bfe0:	92ae0015 */ 	lbu	$t6,0x15($s5)
/*  f01bfe4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f01bfe8:	15c10002 */ 	bne	$t6,$at,.L0f01bff4
/*  f01bfec:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c020:	3c04800a */ 	lui	$a0,%hi(var8009e000)
/*  f01c024:	3c05800a */ 	lui	$a1,%hi(var800a19c0)
/*  f01c028:	24a519c0 */ 	addiu	$a1,$a1,%lo(var800a19c0)
/*  f01c02c:	2484e000 */ 	addiu	$a0,$a0,%lo(var8009e000)
/*  f01c030:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f01c034:	8c8304f8 */ 	lw	$v1,0x4f8($a0)
.L0f01c038:
/*  f01c038:	24840e70 */ 	addiu	$a0,$a0,0xe70
/*  f01c03c:	10600009 */ 	beqz	$v1,.L0f01c064
/*  f01c040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c044:	90620060 */ 	lbu	$v0,0x60($v1)
/*  f01c048:	52c20006 */ 	beql	$s6,$v0,.L0f01c064
/*  f01c04c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01c050:	51220004 */ 	beql	$t1,$v0,.L0f01c064
/*  f01c054:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01c058:	14400002 */ 	bnez	$v0,.L0f01c064
/*  f01c05c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c094:	14c00005 */ 	bnez	$a2,.L0f01c0ac
/*  f01c098:	24590001 */ 	addiu	$t9,$v0,0x1
.L0f01c09c:
/*  f01c09c:	0fc3cc88 */ 	jal	func0f0f3220
/*  f01c0a0:	2504ffff */ 	addiu	$a0,$t0,-1
/*  f01c0a4:	10000003 */ 	beqz	$zero,.L0f01c0b4
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
/*  f01c0dc:	10000073 */ 	beqz	$zero,.L0f01c2ac
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
/*  f01c110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c114:	46040003 */ 	div.s	$f0,$f0,$f4
/*  f01c118:	24010007 */ 	addiu	$at,$zero,0x7
.L0f01c11c:
/*  f01c11c:	14610004 */ 	bne	$v1,$at,.L0f01c130
/*  f01c120:	3c014040 */ 	lui	$at,0x4040
/*  f01c124:	44813000 */ 	mtc1	$at,$f6
/*  f01c128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c12c:	46060003 */ 	div.s	$f0,$f0,$f6
.L0f01c130:
/*  f01c130:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01c134:	14610004 */ 	bne	$v1,$at,.L0f01c148
/*  f01c138:	3c014120 */ 	lui	$at,0x4120
/*  f01c13c:	44814000 */ 	mtc1	$at,$f8
/*  f01c140:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c198:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c19c:	45000002 */ 	bc1f	.L0f01c1a8
/*  f01c1a0:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c1c8:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c218:	0fc393f5 */ 	jal	func0f0e4fd4
/*  f01c21c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01c250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c254:	92b90015 */ 	lbu	$t9,0x15($s5)
.L0f01c258:
/*  f01c258:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c25c:	57210003 */ 	bnel	$t9,$at,.L0f01c26c
/*  f01c260:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f01c264:	ae160000 */ 	sw	$s6,0x0($s0)
/*  f01c268:	8e0d0000 */ 	lw	$t5,0x0($s0)
.L0f01c26c:
/*  f01c26c:	11a00007 */ 	beqz	$t5,.L0f01c28c
/*  f01c270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c274:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f01c278:	8dcf1bd4 */ 	lw	$t7,0x1bd4($t6)
/*  f01c27c:	11e00003 */ 	beqz	$t7,.L0f01c28c
/*  f01c280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c284:	0fc2e54e */ 	jal	func0f0b9538
/*  f01c288:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c28c:
/*  f01c28c:	10000007 */ 	beqz	$zero,.L0f01c2ac
/*  f01c290:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c294:
/*  f01c294:	44805000 */ 	mtc1	$zero,$f10
/*  f01c298:	14400003 */ 	bnez	$v0,.L0f01c2a8
/*  f01c29c:	e6aa0010 */ 	swc1	$f10,0x10($s5)
/*  f01c2a0:	10000002 */ 	beqz	$zero,.L0f01c2ac
/*  f01c2a4:	ae000000 */ 	sw	$zero,0x0($s0)
.L0f01c2a8:
/*  f01c2a8:	ae160000 */ 	sw	$s6,0x0($s0)
.L0f01c2ac:
/*  f01c2ac:	3c188008 */ 	lui	$t8,0x8008
/*  f01c2b0:	8f187260 */ 	lw	$t8,0x7260($t8)
/*  f01c2b4:	1b00006c */ 	blez	$t8,.L0f01c468
/*  f01c2b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c2bc:	8e79000c */ 	lw	$t9,0xc($s3)
/*  f01c2c0:	2b210004 */ 	slti	$at,$t9,0x4
/*  f01c2c4:	14200064 */ 	bnez	$at,.L0f01c458
/*  f01c2c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c2cc:	8e6304b4 */ 	lw	$v1,0x4b4($s3)
/*  f01c2d0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01c2d4:	10610003 */ 	beq	$v1,$at,.L0f01c2e4
/*  f01c2d8:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f01c2dc:	1461005b */ 	bne	$v1,$at,.L0f01c44c
/*  f01c2e0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c2e4:
/*  f01c2e4:	0c0027b1 */ 	jal	func00009ec4
/*  f01c2e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c2ec:	8e6d049c */ 	lw	$t5,0x49c($s3)
/*  f01c2f0:	3c148007 */ 	lui	$s4,%hi(var800714d8)
/*  f01c2f4:	269414d8 */ 	addiu	$s4,$s4,%lo(var800714d8)
/*  f01c2f8:	11a00003 */ 	beqz	$t5,.L0f01c308
/*  f01c2fc:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f01c300:	10000003 */ 	beqz	$zero,.L0f01c310
/*  f01c304:	ae760490 */ 	sw	$s6,0x490($s3)
.L0f01c308:
/*  f01c308:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f01c30c:	ae6e0490 */ 	sw	$t6,0x490($s3)
.L0f01c310:
/*  f01c310:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f01c314:	3c03800b */ 	lui	$v1,0x800b
/*  f01c318:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
/*  f01c31c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f01c320:	00008825 */ 	or	$s1,$zero,$zero
.L0f01c324:
/*  f01c324:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f01c328:	022fc004 */ 	sllv	$t8,$t7,$s1
/*  f01c32c:	0078c824 */ 	and	$t9,$v1,$t8
/*  f01c330:	13200026 */ 	beqz	$t9,.L0f01c3cc
/*  f01c334:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c338:	3c018007 */ 	lui	$at,0x8007
/*  f01c33c:	ac311448 */ 	sw	$s1,0x1448($at)
/*  f01c340:	8e6d0490 */ 	lw	$t5,0x490($s3)
/*  f01c344:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f01c348:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01c34c:	16cd0008 */ 	bne	$s6,$t5,.L0f01c370
/*  f01c350:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f01c354:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f01c358:	0fc5ff2c */ 	jal	func0f17fcb0
/*  f01c35c:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c360:	3c03800b */ 	lui	$v1,0x800b
/*  f01c364:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
/*  f01c368:	10000018 */ 	beqz	$zero,.L0f01c3cc
/*  f01c36c:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c370:
/*  f01c370:	14400015 */ 	bnez	$v0,.L0f01c3c8
/*  f01c374:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f01c378:	ae8f0000 */ 	sw	$t7,0x0($s4)
/*  f01c37c:	3c188009 */ 	lui	$t8,0x8009
/*  f01c380:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f01c384:	3c048008 */ 	lui	$a0,%hi(g_CombatSimulatorMenuDialog)
/*  f01c388:	248467a0 */ 	addiu	$a0,$a0,%lo(g_CombatSimulatorMenuDialog)
/*  f01c38c:	16d80008 */ 	bne	$s6,$t8,.L0f01c3b0
/*  f01c390:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c394:	3c048007 */ 	lui	$a0,%hi(g_4MbMainMenu)
/*  f01c398:	24845294 */ 	addiu	$a0,$a0,%lo(g_4MbMainMenu)
/*  f01c39c:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c3a0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c3a4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c3a8:	10000004 */ 	beqz	$zero,.L0f01c3bc
/*  f01c3ac:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c3b0:
/*  f01c3b0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c3b4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c3b8:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c3bc:
/*  f01c3bc:	3c03800b */ 	lui	$v1,0x800b
/*  f01c3c0:	10000002 */ 	beqz	$zero,.L0f01c3cc
/*  f01c3c4:	9463cb9e */ 	lhu	$v1,-0x3462($v1)
.L0f01c3c8:
/*  f01c3c8:	a1160494 */ 	sb	$s6,0x494($t0)
.L0f01c3cc:
/*  f01c3cc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c3d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01c3d4:	1621ffd3 */ 	bne	$s1,$at,.L0f01c324
/*  f01c3d8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f01c3dc:	3c018007 */ 	lui	$at,0x8007
/*  f01c3e0:	3079000f */ 	andi	$t9,$v1,0xf
/*  f01c3e4:	13200019 */ 	beqz	$t9,.L0f01c44c
/*  f01c3e8:	ac201448 */ 	sw	$zero,0x1448($at)
/*  f01c3ec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f01c3f0:	44818000 */ 	mtc1	$at,$f16
/*  f01c3f4:	3c048009 */ 	lui	$a0,0x8009
/*  f01c3f8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f01c3fc:	240effff */ 	addiu	$t6,$zero,-1
/*  f01c400:	240fffff */ 	addiu	$t7,$zero,-1
/*  f01c404:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f01c408:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f01c40c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f01c410:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f01c414:	24058098 */ 	addiu	$a1,$zero,-32616
/*  f01c418:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c41c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01c420:	0c004241 */ 	jal	func00010904
/*  f01c424:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f01c428:	3c188009 */ 	lui	$t8,%hi(var8009000c)
/*  f01c42c:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f01c430:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f01c434:	16d80003 */ 	bne	$s6,$t8,.L0f01c444
/*  f01c438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c43c:	10000001 */ 	beqz	$zero,.L0f01c444
/*  f01c440:	2404000b */ 	addiu	$a0,$zero,0xb
.L0f01c444:
/*  f01c444:	0fc2ebc3 */ 	jal	func0f0baf0c
/*  f01c448:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c44c:
/*  f01c44c:	3c018008 */ 	lui	$at,0x8008
/*  f01c450:	10000005 */ 	beqz	$zero,.L0f01c468
/*  f01c454:	ac207260 */ 	sw	$zero,0x7260($at)
.L0f01c458:
/*  f01c458:	0c0027b1 */ 	jal	func00009ec4
/*  f01c45c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01c460:	3c018007 */ 	lui	$at,0x8007
/*  f01c464:	ac200750 */ 	sw	$zero,0x750($at)
.L0f01c468:
/*  f01c468:	3c198006 */ 	lui	$t9,0x8006
/*  f01c46c:	93392940 */ 	lbu	$t9,0x2940($t9)
/*  f01c470:	3c148007 */ 	lui	$s4,%hi(var800714d8)
/*  f01c474:	269414d8 */ 	addiu	$s4,$s4,%lo(var800714d8)
/*  f01c478:	5720001b */ 	bnezl	$t9,.L0f01c4e8
/*  f01c47c:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f01c480:	8e6d04b4 */ 	lw	$t5,0x4b4($s3)
/*  f01c484:	24010026 */ 	addiu	$at,$zero,0x26
/*  f01c488:	15a10016 */ 	bne	$t5,$at,.L0f01c4e4
/*  f01c48c:	3c018007 */ 	lui	$at,0x8007
/*  f01c490:	ac200750 */ 	sw	$zero,0x750($at)
/*  f01c494:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f01c498:	29c1001f */ 	slti	$at,$t6,0x1f
/*  f01c49c:	54200012 */ 	bnezl	$at,.L0f01c4e8
/*  f01c4a0:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f01c4a4:	8e6f02ac */ 	lw	$t7,0x2ac($s3)
/*  f01c4a8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01c4ac:	3c02800a */ 	lui	$v0,%hi(var8009e000)
/*  f01c4b0:	11e1000c */ 	beq	$t7,$at,.L0f01c4e4
/*  f01c4b4:	2442e000 */ 	addiu	$v0,$v0,%lo(var8009e000)
/*  f01c4b8:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f01c4bc:	a040083c */ 	sb	$zero,0x83c($v0)
/*  f01c4c0:	a04016ac */ 	sb	$zero,0x16ac($v0)
/*  f01c4c4:	a040251c */ 	sb	$zero,0x251c($v0)
/*  f01c4c8:	a040338c */ 	sb	$zero,0x338c($v0)
/*  f01c4cc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f01c4d0:	0fc2ebc3 */ 	jal	func0f0baf0c
/*  f01c4d4:	af001a24 */ 	sw	$zero,0x1a24($t8)
/*  f01c4d8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f01c4dc:	3c018006 */ 	lui	$at,0x8006
/*  f01c4e0:	a0392940 */ 	sb	$t9,0x2940($at)
.L0f01c4e4:
/*  f01c4e4:	8ead0000 */ 	lw	$t5,0x0($s5)
.L0f01c4e8:
/*  f01c4e8:	ae600498 */ 	sw	$zero,0x498($s3)
/*  f01c4ec:	19a0018e */ 	blez	$t5,.L0f01cb28
/*  f01c4f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01c4f4:	3c018006 */ 	lui	$at,0x8006
/*  f01c4f8:	a02e294c */ 	sb	$t6,0x294c($at)
/*  f01c4fc:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01c500:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c504:	00008825 */ 	or	$s1,$zero,$zero
/*  f01c508:	10610003 */ 	beq	$v1,$at,.L0f01c518
/*  f01c50c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01c510:	14610023 */ 	bne	$v1,$at,.L0f01c5a0
/*  f01c514:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c518:
/*  f01c518:	8ea50008 */ 	lw	$a1,0x8($s5)
/*  f01c51c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f01c520:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f01c524:	14c50006 */ 	bne	$a2,$a1,.L0f01c540
/*  f01c528:	3c03800a */ 	lui	$v1,%hi(var8009e000)
/*  f01c52c:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f01c530:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f01c534:	948f0016 */ 	lhu	$t7,0x16($a0)
/*  f01c538:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f01c53c:	a4980016 */ 	sh	$t8,0x16($a0)
.L0f01c540:
/*  f01c540:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f01c544:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f01c548:	2463e000 */ 	addiu	$v1,$v1,%lo(var8009e000)
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
/*  f01c590:	0fc63005 */ 	jal	func0f18c014
/*  f01c594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c598:	0fc66d50 */ 	jal	func0f19b540
/*  f01c59c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c5a0:
/*  f01c5a0:	3c068007 */ 	lui	$a2,%hi(g_MpPlayerNum)
/*  f01c5a4:	3c05800a */ 	lui	$a1,%hi(var8009e000)
/*  f01c5a8:	3c038008 */ 	lui	$v1,%hi(g_MpReadyMenuDialog)
/*  f01c5ac:	246357b8 */ 	addiu	$v1,$v1,%lo(g_MpReadyMenuDialog)
/*  f01c5b0:	24a5e000 */ 	addiu	$a1,$a1,%lo(var8009e000)
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
/*  f01c5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c5e4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01c5e8:	54780004 */ 	bnel	$v1,$t8,.L0f01c5fc
/*  f01c5ec:	afa00154 */ 	sw	$zero,0x154($sp)
/*  f01c5f0:	10000002 */ 	beqz	$zero,.L0f01c5fc
/*  f01c5f4:	ae760498 */ 	sw	$s6,0x498($s3)
/*  f01c5f8:	afa00154 */ 	sw	$zero,0x154($sp)
.L0f01c5fc:
/*  f01c5fc:	1420fff0 */ 	bnez	$at,.L0f01c5c0
/*  f01c600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c604:	3c12800a */ 	lui	$s2,0x800a
/*  f01c608:	26529fc4 */ 	addiu	$s2,$s2,-24636
/*  f01c60c:	00008825 */ 	or	$s1,$zero,$zero
.L0f01c610:
/*  f01c610:	001168c0 */ 	sll	$t5,$s1,0x3
/*  f01c614:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f01c618:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f01c61c:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f01c620:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f01c624:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f01c628:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f01c62c:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
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
/*  f01c664:	10000002 */ 	beqz	$zero,.L0f01c670
/*  f01c668:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01c66c:
/*  f01c66c:	00003825 */ 	or	$a3,$zero,$zero
.L0f01c670:
/*  f01c670:	11000003 */ 	beqz	$t0,.L0f01c680
/*  f01c674:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c678:	10000001 */ 	beqz	$zero,.L0f01c680
/*  f01c67c:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01c680:
/*  f01c680:	11200003 */ 	beqz	$t1,.L0f01c690
/*  f01c684:	00002825 */ 	or	$a1,$zero,$zero
/*  f01c688:	10000001 */ 	beqz	$zero,.L0f01c690
/*  f01c68c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01c690:
/*  f01c690:	11600003 */ 	beqz	$t3,.L0f01c6a0
/*  f01c694:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c698:	10000001 */ 	beqz	$zero,.L0f01c6a0
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
/*  f01c6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c6cc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01c6d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f01c6d4:	10000104 */ 	beqz	$zero,.L0f01cae8
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
/*  f01c700:	0c005408 */ 	jal	func00015020
/*  f01c704:	3405ffff */ 	dli	$a1,0xffff
/*  f01c708:	8eb80004 */ 	lw	$t8,0x4($s5)
/*  f01c70c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01c710:	3050ffff */ 	andi	$s0,$v0,0xffff
/*  f01c714:	17010014 */ 	bne	$t8,$at,.L0f01c768
/*  f01c718:	3c0e800b */ 	lui	$t6,0x800b
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
/*  f01c740:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c744:	00002025 */ 	or	$a0,$zero,$zero
.L0f01c748:
/*  f01c748:	5472fffb */ 	bnel	$v1,$s2,.L0f01c738
/*  f01c74c:	806d0494 */ 	lb	$t5,0x494($v1)
/*  f01c750:	10000006 */ 	beqz	$zero,.L0f01c76c
/*  f01c754:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c758:
/*  f01c758:	8e840000 */ 	lw	$a0,0x0($s4)
/*  f01c75c:	2c8f0002 */ 	sltiu	$t7,$a0,0x2
/*  f01c760:	10000002 */ 	beqz	$zero,.L0f01c76c
/*  f01c764:	01e02025 */ 	or	$a0,$t7,$zero
.L0f01c768:
/*  f01c768:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01c76c:
/*  f01c76c:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f01c770:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01c774:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f01c778:	15c10005 */ 	bne	$t6,$at,.L0f01c790
/*  f01c77c:	0311c021 */ 	addu	$t8,$t8,$s1
/*  f01c780:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f01c784:	3c01800b */ 	lui	$at,0x800b
/*  f01c788:	00380821 */ 	addu	$at,$at,$t8
/*  f01c78c:	a020c7c9 */ 	sb	$zero,-0x3837($at)
.L0f01c790:
/*  f01c790:	1080003b */ 	beqz	$a0,.L0f01c880
/*  f01c794:	30591000 */ 	andi	$t9,$v0,0x1000
/*  f01c798:	13200039 */ 	beqz	$t9,.L0f01c880
/*  f01c79c:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f01c7a0:	00117880 */ 	sll	$t7,$s1,0x2
/*  f01c7a4:	01f17821 */ 	addu	$t7,$t7,$s1
/*  f01c7a8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f01c7ac:	3c01800b */ 	lui	$at,0x800b
/*  f01c7b0:	002f0821 */ 	addu	$at,$at,$t7
/*  f01c7b4:	a02dc855 */ 	sb	$t5,-0x37ab($at)
/*  f01c7b8:	8e630490 */ 	lw	$v1,0x490($s3)
/*  f01c7bc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01c7c0:	02714021 */ 	addu	$t0,$s3,$s1
/*  f01c7c4:	54610017 */ 	bnel	$v1,$at,.L0f01c824
/*  f01c7c8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c7cc:	810e0494 */ 	lb	$t6,0x494($t0)
/*  f01c7d0:	3c048009 */ 	lui	$a0,0x8009
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
/*  f01c800:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f01c804:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01c808:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f01c80c:	0c004241 */ 	jal	func00010904
/*  f01c810:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f01c814:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f01c818:
/*  f01c818:	10000019 */ 	beqz	$zero,.L0f01c880
/*  f01c81c:	a1160494 */ 	sb	$s6,0x494($t0)
/*  f01c820:	24010003 */ 	addiu	$at,$zero,0x3
.L0f01c824:
/*  f01c824:	14610012 */ 	bne	$v1,$at,.L0f01c870
/*  f01c828:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f01c82c:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f01c830:	ae8f0000 */ 	sw	$t7,0x0($s4)
/*  f01c834:	3c0e8009 */ 	lui	$t6,%hi(var8009000c)
/*  f01c838:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f01c83c:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f01c840:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c844:	16ce0006 */ 	bne	$s6,$t6,.L0f01c860
/*  f01c848:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f01c84c:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f01c850:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c854:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f01c858:	1000000a */ 	beqz	$zero,.L0f01c884
/*  f01c85c:	32191000 */ 	andi	$t9,$s0,0x1000
.L0f01c860:
/*  f01c860:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c864:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c868:	10000006 */ 	beqz	$zero,.L0f01c884
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
/*  f01c8a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c8a8:	10000023 */ 	beqz	$zero,.L0f01c938
/*  f01c8ac:	a1c00494 */ 	sb	$zero,0x494($t6)
.L0f01c8b0:
/*  f01c8b0:	81180494 */ 	lb	$t8,0x494($t0)
/*  f01c8b4:	13000020 */ 	beqz	$t8,.L0f01c938
/*  f01c8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c8bc:	8e630490 */ 	lw	$v1,0x490($s3)
/*  f01c8c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01c8c4:	14610014 */ 	bne	$v1,$at,.L0f01c918
/*  f01c8c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c8cc:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f01c8d0:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c8d4:	3c0f8009 */ 	lui	$t7,%hi(var8009000c)
/*  f01c8d8:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f01c8dc:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*  f01c8e0:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f01c8e4:	3c048008 */ 	lui	$a0,%hi(g_MpQuickGoMenuDialog)
/*  f01c8e8:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01c8ec:	16cf0006 */ 	bne	$s6,$t7,.L0f01c908
/*  f01c8f0:	24846500 */ 	addiu	$a0,$a0,%lo(g_MpQuickGoMenuDialog)
/*  f01c8f4:	3c048007 */ 	lui	$a0,%hi(menudialog_mpquickgo2)
/*  f01c8f8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c8fc:	24845120 */ 	addiu	$a0,$a0,%lo(menudialog_mpquickgo2)
/*  f01c900:	1000000d */ 	beqz	$zero,.L0f01c938
/*  f01c904:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c908:
/*  f01c908:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01c90c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f01c910:	10000009 */ 	beqz	$zero,.L0f01c938
/*  f01c914:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01c918:
/*  f01c918:	16c30007 */ 	bne	$s6,$v1,.L0f01c938
/*  f01c91c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c920:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f01c924:	a1000494 */ 	sb	$zero,0x494($t0)
/*  f01c928:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c92c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f01c930:	0fc5ff2c */ 	jal	func0f17fcb0
/*  f01c934:	ae980000 */ 	sw	$t8,0x0($s4)
.L0f01c938:
/*  f01c938:	10000003 */ 	beqz	$zero,.L0f01c948
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
/*  f01c95c:	3c04800b */ 	lui	$a0,0x800b
/*  f01c960:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f01c964:	8084c7fd */ 	lb	$a0,-0x3803($a0)
/*  f01c968:	0c005408 */ 	jal	func00015020
/*  f01c96c:	3405ffff */ 	dli	$a1,0xffff
/*  f01c970:	304f4000 */ 	andi	$t7,$v0,0x4000
/*  f01c974:	51e0005c */ 	beqzl	$t7,.L0f01cae8
/*  f01c978:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01c97c:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f01c980:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f01c984:	00001825 */ 	or	$v1,$zero,$zero
/*  f01c988:	11400003 */ 	beqz	$t2,.L0f01c998
/*  f01c98c:	00003825 */ 	or	$a3,$zero,$zero
/*  f01c990:	10000001 */ 	beqz	$zero,.L0f01c998
/*  f01c994:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01c998:
/*  f01c998:	8e680068 */ 	lw	$t0,0x68($s3)
/*  f01c99c:	00003025 */ 	or	$a2,$zero,$zero
/*  f01c9a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f01c9a4:	11000003 */ 	beqz	$t0,.L0f01c9b4
/*  f01c9a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f01c9ac:	10000001 */ 	beqz	$zero,.L0f01c9b4
/*  f01c9b0:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01c9b4:
/*  f01c9b4:	8e690064 */ 	lw	$t1,0x64($s3)
/*  f01c9b8:	000369c0 */ 	sll	$t5,$v1,0x7
/*  f01c9bc:	026d1021 */ 	addu	$v0,$s3,$t5
/*  f01c9c0:	11200003 */ 	beqz	$t1,.L0f01c9d0
/*  f01c9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c9c8:	10000001 */ 	beqz	$zero,.L0f01c9d0
/*  f01c9cc:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01c9d0:
/*  f01c9d0:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f01c9d4:	11600003 */ 	beqz	$t3,.L0f01c9e4
/*  f01c9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01c9dc:	10000001 */ 	beqz	$zero,.L0f01c9e4
/*  f01c9e0:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01c9e4:
/*  f01c9e4:	00857021 */ 	addu	$t6,$a0,$a1
/*  f01c9e8:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f01c9ec:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f01c9f0:	1b20001d */ 	blez	$t9,.L0f01ca68
/*  f01c9f4:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01ca18:	10000001 */ 	beqz	$zero,.L0f01ca20
/*  f01ca1c:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01ca20:
/*  f01ca20:	11000003 */ 	beqz	$t0,.L0f01ca30
/*  f01ca24:	00002825 */ 	or	$a1,$zero,$zero
/*  f01ca28:	10000001 */ 	beqz	$zero,.L0f01ca30
/*  f01ca2c:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01ca30:
/*  f01ca30:	11200003 */ 	beqz	$t1,.L0f01ca40
/*  f01ca34:	00002025 */ 	or	$a0,$zero,$zero
/*  f01ca38:	10000001 */ 	beqz	$zero,.L0f01ca40
/*  f01ca3c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01ca40:
/*  f01ca40:	11600003 */ 	beqz	$t3,.L0f01ca50
/*  f01ca44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ca48:	10000001 */ 	beqz	$zero,.L0f01ca50
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
/*  f01ca8c:	0fc43b2d */ 	jal	func0f10ecb4
/*  f01ca90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ca94:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ca98:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f01ca9c:	10000012 */ 	beqz	$zero,.L0f01cae8
/*  f01caa0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f01caa4:	8e6e029c */ 	lw	$t6,0x29c($s3)
.L0f01caa8:
/*  f01caa8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01caac:	05c0000b */ 	bltz	$t6,.L0f01cadc
/*  f01cab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cab4:	8e78028c */ 	lw	$t8,0x28c($s3)
/*  f01cab8:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cabc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cac0:	afb80124 */ 	sw	$t8,0x124($sp)
/*  f01cac4:	0fc43bc4 */ 	jal	func0f10ef10
/*  f01cac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cacc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cad0:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f01cad4:	10000004 */ 	beqz	$zero,.L0f01cae8
/*  f01cad8:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01cadc:
/*  f01cadc:	0fc5e3bc */ 	jal	func0f178ef0
/*  f01cae0:	02202825 */ 	or	$a1,$s1,$zero
.L0f01cae4:
/*  f01cae4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f01cae8:
/*  f01cae8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f01caec:	1621fec8 */ 	bne	$s1,$at,.L0f01c610
/*  f01caf0:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f01caf4:	1320000e */ 	beqz	$t9,.L0f01cb30
/*  f01caf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cafc:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cb00:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cb04:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cb08:	10610003 */ 	beq	$v1,$at,.L0f01cb18
/*  f01cb0c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cb10:	14610007 */ 	bne	$v1,$at,.L0f01cb30
/*  f01cb14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cb18:
/*  f01cb18:	0fc3e083 */ 	jal	func0f0f820c
/*  f01cb1c:	2405fffb */ 	addiu	$a1,$zero,-5
/*  f01cb20:	10000003 */ 	beqz	$zero,.L0f01cb30
/*  f01cb24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cb28:
/*  f01cb28:	3c018006 */ 	lui	$at,0x8006
/*  f01cb2c:	a020294c */ 	sb	$zero,0x294c($at)
.L0f01cb30:
/*  f01cb30:	3c0d8006 */ 	lui	$t5,0x8006
/*  f01cb34:	91ad294c */ 	lbu	$t5,0x294c($t5)
/*  f01cb38:	11a0001b */ 	beqz	$t5,.L0f01cba8
/*  f01cb3c:	3c028006 */ 	lui	$v0,%hi(var80062948)
/*  f01cb40:	24422948 */ 	addiu	$v0,$v0,%lo(var80062948)
/*  f01cb44:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f01cb48:	15e0000f */ 	bnez	$t7,.L0f01cb88
/*  f01cb4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cb50:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cb54:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cb58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01cb5c:	10610004 */ 	beq	$v1,$at,.L0f01cb70
/*  f01cb60:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cb64:	2401000b */ 	addiu	$at,$zero,0xb
/*  f01cb68:	14610007 */ 	bne	$v1,$at,.L0f01cb88
/*  f01cb6c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cb70:
/*  f01cb70:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f01cb74:	0fc44317 */ 	jal	func0f110c5c
/*  f01cb78:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f01cb7c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01cb80:	0fc44317 */ 	jal	func0f110c5c
/*  f01cb84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f01cb88:
/*  f01cb88:	3c188006 */ 	lui	$t8,%hi(var8006000c)
/*  f01cb8c:	93182944 */ 	lbu	$t8,0x2944($t8)
/*  f01cb90:	1300000b */ 	beqz	$t8,.L0f01cbc0
/*  f01cb94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cb98:	0fc4436a */ 	jal	func0f110da8
/*  f01cb9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cba0:	10000007 */ 	beqz	$zero,.L0f01cbc0
/*  f01cba4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cba8:
/*  f01cba8:	3c198006 */ 	lui	$t9,%hi(var8006000c)
/*  f01cbac:	93392944 */ 	lbu	$t9,0x2944($t9)
/*  f01cbb0:	16d90003 */ 	bne	$s6,$t9,.L0f01cbc0
/*  f01cbb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cbb8:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cbbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cbc0:
/*  f01cbc0:	3c018007 */ 	lui	$at,0x8007
/*  f01cbc4:	3c03800a */ 	lui	$v1,%hi(var8009e000)
/*  f01cbc8:	3c02800a */ 	lui	$v0,%hi(var800a19c0)
/*  f01cbcc:	ac201448 */ 	sw	$zero,0x1448($at)
/*  f01cbd0:	00002025 */ 	or	$a0,$zero,$zero
/*  f01cbd4:	244219c0 */ 	addiu	$v0,$v0,%lo(var800a19c0)
/*  f01cbd8:	2463e000 */ 	addiu	$v1,$v1,%lo(var8009e000)
/*  f01cbdc:	8c6d04f8 */ 	lw	$t5,0x4f8($v1)
.L0f01cbe0:
/*  f01cbe0:	24630e70 */ 	addiu	$v1,$v1,0x0e70
/*  f01cbe4:	0062082b */ 	sltu	$at,$v1,$v0
/*  f01cbe8:	11a00002 */ 	beqz	$t5,.L0f01cbf4
/*  f01cbec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cbf0:	02c02025 */ 	or	$a0,$s6,$zero
.L0f01cbf4:
/*  f01cbf4:	5420fffa */ 	bnezl	$at,.L0f01cbe0
/*  f01cbf8:	8c6d04f8 */ 	lw	$t5,0x4f8($v1)
/*  f01cbfc:	8eaf05d4 */ 	lw	$t7,0x5d4($s5)
/*  f01cc00:	000fc340 */ 	sll	$t8,$t7,0xd
/*  f01cc04:	07000006 */ 	bltz	$t8,.L0f01cc20
/*  f01cc08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cc0c:	8eb90008 */ 	lw	$t9,0x8($s5)
/*  f01cc10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f01cc14:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cc18:	132101df */ 	beq	$t9,$at,.L0f01d398
/*  f01cc1c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01cc5c:	3c0e8009 */ 	lui	$t6,%hi(var8009000c)
/*  f01cc60:	aeaf0008 */ 	sw	$t7,0x8($s5)
/*  f01cc64:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f01cc68:	3c198007 */ 	lui	$t9,%hi(g_MainMenuMenuDialog)
/*  f01cc6c:	27393a5c */ 	addiu	$t9,$t9,%lo(g_MainMenuMenuDialog)
/*  f01cc70:	16ce0004 */ 	bne	$s6,$t6,.L0f01cc84
/*  f01cc74:	3c188007 */ 	lui	$t8,%hi(g_MainMenu4MbMenuDialog)
/*  f01cc78:	27183a74 */ 	addiu	$t8,$t8,%lo(g_MainMenu4MbMenuDialog)
/*  f01cc7c:	10000002 */ 	beqz	$zero,.L0f01cc88
/*  f01cc80:	aeb8000c */ 	sw	$t8,0xc($s5)
.L0f01cc84:
/*  f01cc84:	aeb9000c */ 	sw	$t9,0xc($s5)
.L0f01cc88:
/*  f01cc88:	1000000f */ 	beqz	$zero,.L0f01ccc8
/*  f01cc8c:	8ea50008 */ 	lw	$a1,0x8($s5)
.L0f01cc90:
/*  f01cc90:	3c0d8009 */ 	lui	$t5,0x8009
/*  f01cc94:	91ad0af0 */ 	lbu	$t5,0xaf0($t5)
/*  f01cc98:	3c188008 */ 	lui	$t8,%hi(g_CombatSimulatorMenuDialog)
/*  f01cc9c:	271867a0 */ 	addiu	$t8,$t8,%lo(g_CombatSimulatorMenuDialog)
/*  f01cca0:	16cd0007 */ 	bne	$s6,$t5,.L0f01ccc0
/*  f01cca4:	00402825 */ 	or	$a1,$v0,$zero
/*  f01cca8:	3c0e8007 */ 	lui	$t6,%hi(g_4MbMainMenu)
/*  f01ccac:	2405000b */ 	addiu	$a1,$zero,0xb
/*  f01ccb0:	25ce5294 */ 	addiu	$t6,$t6,%lo(g_4MbMainMenu)
/*  f01ccb4:	aea50008 */ 	sw	$a1,0x8($s5)
/*  f01ccb8:	10000003 */ 	beqz	$zero,.L0f01ccc8
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
/*  f01ccdc:	0fc61e19 */ 	jal	func0f187864
/*  f01cce0:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cce4:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ccec:	8e790458 */ 	lw	$t9,0x458($s3)
/*  f01ccf0:	332d0002 */ 	andi	$t5,$t9,0x2
/*  f01ccf4:	51a000ca */ 	beqzl	$t5,.L0f01d020
/*  f01ccf8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01ccfc:	0fc44270 */ 	jal	func0f1109c0
/*  f01cd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cd04:	8e6f0458 */ 	lw	$t7,0x458($s3)
/*  f01cd08:	2401fffd */ 	addiu	$at,$zero,-3
/*  f01cd0c:	01e17024 */ 	and	$t6,$t7,$at
/*  f01cd10:	100000c2 */ 	beqz	$zero,.L0f01d01c
/*  f01cd14:	ae6e0458 */ 	sw	$t6,0x458($s3)
/*  f01cd18:	2401fffa */ 	addiu	$at,$zero,-6
.L0f01cd1c:
/*  f01cd1c:	54a10065 */ 	bnel	$a1,$at,.L0f01ceb4
/*  f01cd20:	2401fff9 */ 	addiu	$at,$zero,-7
/*  f01cd24:	8e780318 */ 	lw	$t8,0x318($s3)
/*  f01cd28:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f01cd2c:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cd30:	13000003 */ 	beqz	$t8,.L0f01cd40
/*  f01cd34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cd38:	0fc3f552 */ 	jal	func0f0fd548
/*  f01cd3c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f01cd40:
/*  f01cd40:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01cd44:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01cd48:	00008825 */ 	or	$s1,$zero,$zero
/*  f01cd4c:	24140038 */ 	addiu	$s4,$zero,0x38
.L0f01cd50:
/*  f01cd50:	3c19800b */ 	lui	$t9,0x800b
/*  f01cd54:	9739cb9e */ 	lhu	$t9,-0x3462($t9)
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
/*  f01cd90:	3c0d8007 */ 	lui	$t5,0x8007
/*  f01cd94:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f01cd98:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f01cd9c:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f01cda0:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f01cda4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f01cda8:	a24f0002 */ 	sb	$t7,0x2($s2)
/*  f01cdac:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01cdb0:	8dad1e6c */ 	lw	$t5,0x1e6c($t5)
/*  f01cdb4:	a24d0001 */ 	sb	$t5,0x1($s2)
/*  f01cdb8:	0fc06c55 */ 	jal	func0f01b154
/*  f01cdbc:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f01cdc0:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f01cdc4:	0004ce42 */ 	srl	$t9,$a0,0x19
/*  f01cdc8:	0fc5b36a */ 	jal	setDifficulty
/*  f01cdcc:	03202025 */ 	or	$a0,$t9,$zero
/*  f01cdd0:	0fc069f9 */ 	jal	func0f01a7e4
/*  f01cdd4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01cdd8:	0c003a57 */ 	jal	func0000e95c
/*  f01cddc:	92440001 */ 	lbu	$a0,0x1($s2)
/*  f01cde0:	1000002b */ 	beqz	$zero,.L0f01ce90
/*  f01cde4:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f01cde8:	8e70028c */ 	lw	$s0,0x28c($s3)
.L0f01cdec:
/*  f01cdec:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01cdf0:	afaf0158 */ 	sw	$t7,0x158($sp)
/*  f01cdf4:	0fc43b2d */ 	jal	func0f10ecb4
/*  f01cdf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cdfc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ce00:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ce04:	10000022 */ 	beqz	$zero,.L0f01ce90
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
/*  f01ce2c:	0fc43bc4 */ 	jal	func0f10ef10
/*  f01ce30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01ce34:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f01ce38:	02002025 */ 	or	$a0,$s0,$zero
/*  f01ce3c:	10000014 */ 	beqz	$zero,.L0f01ce90
/*  f01ce40:	8fb80120 */ 	lw	$t8,0x120($sp)
.L0f01ce44:
/*  f01ce44:	00116880 */ 	sll	$t5,$s1,0x2
/*  f01ce48:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f01ce4c:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f01ce50:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f01ce54:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f01ce58:	01b91021 */ 	addu	$v0,$t5,$t9
/*  f01ce5c:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f01ce60:	0fc5e3bc */ 	jal	func0f178ef0
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
/*  f01cea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cea8:	1000005d */ 	beqz	$zero,.L0f01d020
/*  f01ceac:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01ceb0:	2401fff9 */ 	addiu	$at,$zero,-7
.L0f01ceb4:
/*  f01ceb4:	14a10019 */ 	bne	$a1,$at,.L0f01cf1c
/*  f01ceb8:	00008025 */ 	or	$s0,$zero,$zero
/*  f01cebc:	0fc06fa8 */ 	jal	func0f01bea0
/*  f01cec0:	afa40158 */ 	sw	$a0,0x158($sp)
/*  f01cec4:	3c10800a */ 	lui	$s0,0x800a
/*  f01cec8:	26102200 */ 	addiu	$s0,$s0,0x2200
/*  f01cecc:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f01ced0:	3c018006 */ 	lui	$at,0x8006
/*  f01ced4:	a0392940 */ 	sb	$t9,0x2940($at)
/*  f01ced8:	0fc43da6 */ 	jal	func0f10f698
/*  f01cedc:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cee0:	0fc43c81 */ 	jal	func0f10f204
/*  f01cee4:	02002025 */ 	or	$a0,$s0,$zero
/*  f01cee8:	3c0f8009 */ 	lui	$t7,%hi(var8009000c)
/*  f01ceec:	91ef0af0 */ 	lbu	$t7,0xaf0($t7)
/*  f01cef0:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01cef4:	16cf0003 */ 	bne	$s6,$t7,.L0f01cf04
/*  f01cef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cefc:	10000001 */ 	beqz	$zero,.L0f01cf04
/*  f01cf00:	2404005d */ 	addiu	$a0,$zero,0x5d
.L0f01cf04:
/*  f01cf04:	0c003a57 */ 	jal	func0000e95c
/*  f01cf08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cf0c:	0fc5b4f4 */ 	jal	func0f16d3d0
/*  f01cf10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cf14:	10000042 */ 	beqz	$zero,.L0f01d020
/*  f01cf18:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f01cf1c:
/*  f01cf1c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01cf20:	afae0158 */ 	sw	$t6,0x158($sp)
/*  f01cf24:	0fc3e0cc */ 	jal	func0f0f8330
/*  f01cf28:	8ea4000c */ 	lw	$a0,0xc($s5)
/*  f01cf2c:	8ea30004 */ 	lw	$v1,0x4($s5)
/*  f01cf30:	24010003 */ 	addiu	$at,$zero,0x3
/*  f01cf34:	3c048009 */ 	lui	$a0,0x8009
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
/*  f01cf6c:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f01cf70:	00003025 */ 	or	$a2,$zero,$zero
/*  f01cf74:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f01cf78:	0c004241 */ 	jal	func00010904
/*  f01cf7c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f01cf80:	8ea30004 */ 	lw	$v1,0x4($s5)
.L0f01cf84:
/*  f01cf84:	24010002 */ 	addiu	$at,$zero,0x2
/*  f01cf88:	10610003 */ 	beq	$v1,$at,.L0f01cf98
/*  f01cf8c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f01cf90:	1461001e */ 	bne	$v1,$at,.L0f01d00c
/*  f01cf94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01cf98:
/*  f01cf98:	0fc68606 */ 	jal	ciGetTrainingData
/*  f01cf9c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01cfe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01cfe8:	50400008 */ 	beqzl	$v0,.L0f01d00c
/*  f01cfec:	02c08025 */ 	or	$s0,$s6,$zero
/*  f01cff0:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01cff4:	00186fc2 */ 	srl	$t5,$t8,0x1f
/*  f01cff8:	51a00004 */ 	beqzl	$t5,.L0f01d00c
/*  f01cffc:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01d000:
/*  f01d000:	10000002 */ 	beqz	$zero,.L0f01d00c
/*  f01d004:	00008025 */ 	or	$s0,$zero,$zero
/*  f01d008:	02c08025 */ 	or	$s0,$s6,$zero
.L0f01d00c:
/*  f01d00c:	52000004 */ 	beqzl	$s0,.L0f01d020
/*  f01d010:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f01d014:	0fc5b6c5 */ 	jal	func0f16db14
/*  f01d018:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d01c:
/*  f01d01c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f01d020:
/*  f01d020:	aea0000c */ 	sw	$zero,0xc($s5)
/*  f01d024:	100000dc */ 	beqz	$zero,.L0f01d398
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
/*  f01d050:	100000d1 */ 	beqz	$zero,.L0f01d398
/*  f01d054:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d058:
/*  f01d058:	8e6f046c */ 	lw	$t7,0x46c($s3)
/*  f01d05c:	11e00007 */ 	beqz	$t7,.L0f01d07c
/*  f01d060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d064:	0c003a61 */ 	jal	getCurrentStageId
/*  f01d068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d06c:	0c003a57 */ 	jal	func0000e95c
/*  f01d070:	00402025 */ 	or	$a0,$v0,$zero
/*  f01d074:	100000c8 */ 	beqz	$zero,.L0f01d398
/*  f01d078:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d07c:
/*  f01d07c:	0c003a57 */ 	jal	func0000e95c
/*  f01d080:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f01d084:	100000c4 */ 	beqz	$zero,.L0f01d398
/*  f01d088:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d08c:
/*  f01d08c:	8e6e0318 */ 	lw	$t6,0x318($s3)
/*  f01d090:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01d094:	3c018008 */ 	lui	$at,0x8008
/*  f01d098:	11c00004 */ 	beqz	$t6,.L0f01d0ac
/*  f01d09c:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01d0a0:	ac227260 */ 	sw	$v0,0x7260($at)
/*  f01d0a4:	10000062 */ 	beqz	$zero,.L0f01d230
/*  f01d0a8:	8e630298 */ 	lw	$v1,0x298($s3)
.L0f01d0ac:
/*  f01d0ac:	8e630298 */ 	lw	$v1,0x298($s3)
/*  f01d0b0:	3c04800b */ 	lui	$a0,%hi(var800aca38)
/*  f01d0b4:	2484ca38 */ 	addiu	$a0,$a0,%lo(var800aca38)
/*  f01d0b8:	04610003 */ 	bgez	$v1,.L0f01d0c8
/*  f01d0bc:	27a20070 */ 	addiu	$v0,$sp,0x70
/*  f01d0c0:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f01d0c4:	0700005a */ 	bltz	$t8,.L0f01d230
.L0f01d0c8:
/*  f01d0c8:	3c05800b */ 	lui	$a1,%hi(var800acad8)
/*  f01d0cc:	3c06800b */ 	lui	$a2,0x800b
/*  f01d0d0:	3c07800b */ 	lui	$a3,%hi(g_MpPlayers)
/*  f01d0d4:	24e7c7b8 */ 	addiu	$a3,$a3,%lo(g_MpPlayers)
/*  f01d0d8:	24c6c858 */ 	addiu	$a2,$a2,-14248
/*  f01d0dc:	24a5cad8 */ 	addiu	$a1,$a1,%lo(var800acad8)
/*  f01d0e0:	00807825 */ 	or	$t7,$a0,$zero
/*  f01d0e4:	00407025 */ 	or	$t6,$v0,$zero
/*  f01d0e8:	2499009c */ 	addiu	$t9,$a0,0x9c
.L0f01d0ec:
/*  f01d0ec:	8de10000 */ 	lw	$at,0x0($t7)
/*  f01d0f0:	25ef000c */ 	addiu	$t7,$t7,%lo(var8009000c)
/*  f01d0f4:	25ce000c */ 	addiu	$t6,$t6,%lo(var8009000c)
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
/*  f01d12c:	25ef000c */ 	addiu	$t7,$t7,%lo(var8009000c)
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
/*  f01d164:	2739000c */ 	addiu	$t9,$t9,%lo(var8006000c)
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
/*  f01d198:	2718000c */ 	addiu	$t8,$t8,%lo(var8006000c)
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
/*  f01d1d0:	25ce000c */ 	addiu	$t6,$t6,%lo(var8009000c)
/*  f01d1d4:	2718000c */ 	addiu	$t8,$t8,%lo(var8009000c)
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
/*  f01d23c:	3c18800a */ 	lui	$t8,0x800a
/*  f01d240:	28410011 */ 	slti	$at,$v0,0x11
/*  f01d244:	50200014 */ 	beqzl	$at,.L0f01d298
/*  f01d248:	8e6f046c */ 	lw	$t7,0x46c($s3)
/*  f01d24c:	8f1821d0 */ 	lw	$t8,0x21d0($t8)
/*  f01d250:	3c0d800a */ 	lui	$t5,0x800a
/*  f01d254:	57000005 */ 	bnezl	$t8,.L0f01d26c
/*  f01d258:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f01d25c:	8dad21d4 */ 	lw	$t5,0x21d4($t5)
/*  f01d260:	11a00008 */ 	beqz	$t5,.L0f01d284
/*  f01d264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d268:	8e450000 */ 	lw	$a1,0x0($s2)
.L0f01d26c:
/*  f01d26c:	24440001 */ 	addiu	$a0,$v0,0x1
/*  f01d270:	0005ce42 */ 	srl	$t9,$a1,0x19
/*  f01d274:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f01d278:	03202825 */ 	or	$a1,$t9,$zero
/*  f01d27c:	50400006 */ 	beqzl	$v0,.L0f01d298
/*  f01d280:	8e6f046c */ 	lw	$t7,0x46c($s3)
.L0f01d284:
/*  f01d284:	0fc43b90 */ 	jal	func0f10ee40
/*  f01d288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d28c:	10000042 */ 	beqz	$zero,.L0f01d398
/*  f01d290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d294:	8e6f046c */ 	lw	$t7,0x46c($s3)
.L0f01d298:
/*  f01d298:	11e00007 */ 	beqz	$t7,.L0f01d2b8
/*  f01d29c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d2a0:	0c003a61 */ 	jal	getCurrentStageId
/*  f01d2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d2a8:	0c003a57 */ 	jal	func0000e95c
/*  f01d2ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f01d2b0:	10000039 */ 	beqz	$zero,.L0f01d398
/*  f01d2b4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d2b8:
/*  f01d2b8:	0fc625cb */ 	jal	mpSetPaused
/*  f01d2bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d2c0:	3c02800b */ 	lui	$v0,0x800b
/*  f01d2c4:	2442cbb0 */ 	addiu	$v0,$v0,-13392
/*  f01d2c8:	904e0060 */ 	lbu	$t6,0x60($v0)
/*  f01d2cc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f01d2d0:	ae600314 */ 	sw	$zero,0x314($s3)
/*  f01d2d4:	ae600318 */ 	sw	$zero,0x318($s3)
/*  f01d2d8:	15c10002 */ 	bne	$t6,$at,.L0f01d2e4
/*  f01d2dc:	ae60031c */ 	sw	$zero,0x31c($s3)
/*  f01d2e0:	a0400060 */ 	sb	$zero,0x60($v0)
.L0f01d2e4:
/*  f01d2e4:	3c188009 */ 	lui	$t8,0x8009
/*  f01d2e8:	93180af0 */ 	lbu	$t8,0xaf0($t8)
/*  f01d2ec:	12d8000b */ 	beq	$s6,$t8,.L0f01d31c
/*  f01d2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d2f4:	0fc06c55 */ 	jal	func0f01b154
/*  f01d2f8:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d2fc:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d300:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d304:	0fc069f9 */ 	jal	func0f01a7e4
/*  f01d308:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d30c:	0c003a57 */ 	jal	func0000e95c
/*  f01d310:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d314:	10000020 */ 	beqz	$zero,.L0f01d398
/*  f01d318:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d31c:
/*  f01d31c:	0fc06c55 */ 	jal	func0f01b154
/*  f01d320:	2404005d */ 	addiu	$a0,$zero,0x5d
/*  f01d324:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d328:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d32c:	0fc069f9 */ 	jal	func0f01a7e4
/*  f01d330:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d334:	0c003a57 */ 	jal	func0000e95c
/*  f01d338:	2404005d */ 	addiu	$a0,$zero,0x5d
/*  f01d33c:	10000016 */ 	beqz	$zero,.L0f01d398
/*  f01d340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d344:	8e6d0298 */ 	lw	$t5,0x298($s3)
.L0f01d348:
/*  f01d348:	05a00013 */ 	bltz	$t5,.L0f01d398
/*  f01d34c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d350:	0fc625cb */ 	jal	mpSetPaused
/*  f01d354:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d358:	ae600314 */ 	sw	$zero,0x314($s3)
/*  f01d35c:	ae600318 */ 	sw	$zero,0x318($s3)
/*  f01d360:	ae60031c */ 	sw	$zero,0x31c($s3)
/*  f01d364:	0fc06c55 */ 	jal	func0f01b154
/*  f01d368:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d36c:	0fc068d5 */ 	jal	setNumPlayers
/*  f01d370:	02c02025 */ 	or	$a0,$s6,$zero
/*  f01d374:	0fc069f9 */ 	jal	func0f01a7e4
/*  f01d378:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f01d37c:	0c003a57 */ 	jal	func0000e95c
/*  f01d380:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f01d384:	3c12800a */ 	lui	$s2,%hi(g_MissionConfig)
/*  f01d388:	2652dfe8 */ 	addiu	$s2,$s2,%lo(g_MissionConfig)
/*  f01d38c:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f01d390:	332fff7f */ 	andi	$t7,$t9,0xff7f
/*  f01d394:	a24f0003 */ 	sb	$t7,0x3($s2)
.L0f01d398:
/*  f01d398:	0fc06fb8 */ 	jal	func0f01bee0
/*  f01d39c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01d3d8:	10000005 */ 	beqz	$zero,.L0f01d3f0
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
/*  f01d414:	3c19800a */ 	lui	$t9,0x800a
/*  f01d418:	370d0080 */ 	ori	$t5,$t8,0x80
/*  f01d41c:	a2ad05d5 */ 	sb	$t5,0x5d5($s5)
/*  f01d420:	8f39e844 */ 	lw	$t9,-0x17bc($t9)
/*  f01d424:	53200006 */ 	beqzl	$t9,.L0f01d440
/*  f01d428:	8e6f006c */ 	lw	$t7,0x6c($s3)
/*  f01d42c:	0fc277d4 */ 	jal	func0f09df50
/*  f01d430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d434:	3c01800a */ 	lui	$at,0x800a
/*  f01d438:	ac20e844 */ 	sw	$zero,-0x17bc($at)
/*  f01d43c:	8e6f006c */ 	lw	$t7,0x6c($s3)
.L0f01d440:
/*  f01d440:	a26004d0 */ 	sb	$zero,0x4d0($s3)
/*  f01d444:	00008825 */ 	or	$s1,$zero,$zero
/*  f01d448:	51e00004 */ 	beqzl	$t7,.L0f01d45c
/*  f01d44c:	00003825 */ 	or	$a3,$zero,$zero
/*  f01d450:	10000002 */ 	beqz	$zero,.L0f01d45c
/*  f01d454:	02c03825 */ 	or	$a3,$s6,$zero
/*  f01d458:	00003825 */ 	or	$a3,$zero,$zero
.L0f01d45c:
/*  f01d45c:	8e6e0068 */ 	lw	$t6,0x68($s3)
/*  f01d460:	51c00004 */ 	beqzl	$t6,.L0f01d474
/*  f01d464:	00003025 */ 	or	$a2,$zero,$zero
/*  f01d468:	10000002 */ 	beqz	$zero,.L0f01d474
/*  f01d46c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f01d470:	00003025 */ 	or	$a2,$zero,$zero
.L0f01d474:
/*  f01d474:	8e780064 */ 	lw	$t8,0x64($s3)
/*  f01d478:	53000004 */ 	beqzl	$t8,.L0f01d48c
/*  f01d47c:	00002825 */ 	or	$a1,$zero,$zero
/*  f01d480:	10000002 */ 	beqz	$zero,.L0f01d48c
/*  f01d484:	02c02825 */ 	or	$a1,$s6,$zero
/*  f01d488:	00002825 */ 	or	$a1,$zero,$zero
.L0f01d48c:
/*  f01d48c:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f01d490:	51a00004 */ 	beqzl	$t5,.L0f01d4a4
/*  f01d494:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d498:	10000002 */ 	beqz	$zero,.L0f01d4a4
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
/*  f01d4d0:	10000004 */ 	beqz	$zero,.L0f01d4e4
/*  f01d4d4:	8f2300e4 */ 	lw	$v1,0xe4($t9)
.L0f01d4d8:
/*  f01d4d8:	16200002 */ 	bnez	$s1,.L0f01d4e4
/*  f01d4dc:	00000000 */ 	sll	$zero,$zero,0x0
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
/*  f01d54c:	3c0d800a */ 	lui	$t5,0x800a
/*  f01d550:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01d554:	8dade4f8 */ 	lw	$t5,-0x1b08($t5)
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
/*  f01d578:	10000004 */ 	beqz	$zero,.L0f01d58c
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
/*  f01d5b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d5b4:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f01d5b8:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d5bc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f01d5c0:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f01d5c4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f01d5c8:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f01d5cc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f01d5d0:	3c0d800a */ 	lui	$t5,0x800a
/*  f01d5d4:	01b86821 */ 	addu	$t5,$t5,$t8
/*  f01d5d8:	8dade4f8 */ 	lw	$t5,-0x1b08($t5)
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
/*  f01d61c:	10000001 */ 	beqz	$zero,.L0f01d624
/*  f01d620:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01d624:
/*  f01d624:	8e6d0068 */ 	lw	$t5,0x68($s3)
/*  f01d628:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d62c:	11a00003 */ 	beqz	$t5,.L0f01d63c
/*  f01d630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d634:	10000001 */ 	beqz	$zero,.L0f01d63c
/*  f01d638:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01d63c:
/*  f01d63c:	8e790064 */ 	lw	$t9,0x64($s3)
/*  f01d640:	13200003 */ 	beqz	$t9,.L0f01d650
/*  f01d644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d648:	10000001 */ 	beqz	$zero,.L0f01d650
/*  f01d64c:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01d650:
/*  f01d650:	8e6f0070 */ 	lw	$t7,0x70($s3)
/*  f01d654:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f01d658:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f01d65c:	11e00003 */ 	beqz	$t7,.L0f01d66c
/*  f01d660:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f01d664:	10000001 */ 	beqz	$zero,.L0f01d66c
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
/*  f01d690:	3c0f800a */ 	lui	$t7,0x800a
/*  f01d694:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f01d698:	8defe4f8 */ 	lw	$t7,-0x1b08($t7)
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
/*  f01d6c4:	10000002 */ 	beqz	$zero,.L0f01d6d0
/*  f01d6c8:	02c03825 */ 	or	$a3,$s6,$zero
.L0f01d6cc:
/*  f01d6cc:	00003825 */ 	or	$a3,$zero,$zero
.L0f01d6d0:
/*  f01d6d0:	11000003 */ 	beqz	$t0,.L0f01d6e0
/*  f01d6d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f01d6d8:	10000001 */ 	beqz	$zero,.L0f01d6e0
/*  f01d6dc:	02c03025 */ 	or	$a2,$s6,$zero
.L0f01d6e0:
/*  f01d6e0:	11200003 */ 	beqz	$t1,.L0f01d6f0
/*  f01d6e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f01d6e8:	10000001 */ 	beqz	$zero,.L0f01d6f0
/*  f01d6ec:	02c02825 */ 	or	$a1,$s6,$zero
.L0f01d6f0:
/*  f01d6f0:	11600003 */ 	beqz	$t3,.L0f01d700
/*  f01d6f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f01d6f8:	10000001 */ 	beqz	$zero,.L0f01d700
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
/*  f01d71c:	3c018008 */ 	lui	$at,0x8008
/*  f01d720:	ac36fac0 */ 	sw	$s6,-0x540($at)
/*  f01d724:	51c00006 */ 	beqzl	$t6,.L0f01d740
/*  f01d728:	92af05d5 */ 	lbu	$t7,0x5d5($s5)
/*  f01d72c:	92ad05d5 */ 	lbu	$t5,0x5d5($s5)
/*  f01d730:	35b90004 */ 	ori	$t9,$t5,0x4
/*  f01d734:	10000004 */ 	beqz	$zero,.L0f01d748
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

GLOBAL_ASM(
glabel func0f01d770
/*  f01d770:	3c0e8008 */ 	lui	$t6,0x8008
/*  f01d774:	8dcef0c0 */ 	lw	$t6,-0xf40($t6)
/*  f01d778:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01d77c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01d780:	11c00031 */ 	beqz	$t6,.L0f01d848
/*  f01d784:	3c028008 */ 	lui	$v0,0x8008
/*  f01d788:	8c42fc00 */ 	lw	$v0,-0x400($v0)
/*  f01d78c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f01d790:	3c0f800a */ 	lui	$t7,0x800a
/*  f01d794:	54410009 */ 	bnel	$v0,$at,.L0f01d7bc
/*  f01d798:	2401000a */ 	addiu	$at,$zero,0xa
/*  f01d79c:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f01d7a0:	3c01c4fa */ 	lui	$at,0xc4fa
/*  f01d7a4:	44813000 */ 	mtc1	$at,$f6
/*  f01d7a8:	c5e41bb8 */ 	lwc1	$f4,0x1bb8($t7)
/*  f01d7ac:	4606203c */ 	c.lt.s	$f4,$f6
/*  f01d7b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d7b4:	45010024 */ 	bc1t	.L0f01d848
/*  f01d7b8:	2401000a */ 	addiu	$at,$zero,0xa
.L0f01d7bc:
/*  f01d7bc:	14410004 */ 	bne	$v0,$at,.L0f01d7d0
/*  f01d7c0:	3c18800a */ 	lui	$t8,0x800a
/*  f01d7c4:	8f18a26c */ 	lw	$t8,-0x5d94($t8)
/*  f01d7c8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f01d7cc:	1701001e */ 	bne	$t8,$at,.L0f01d848
.L0f01d7d0:
/*  f01d7d0:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01d7d4:	3c058006 */ 	lui	$a1,%hi(var80062954)
/*  f01d7d8:	24a52954 */ 	addiu	$a1,$a1,%lo(var80062954)
/*  f01d7dc:	0c0036cc */ 	jal	func0000db30
/*  f01d7e0:	24848640 */ 	addiu	$a0,$a0,-31168
/*  f01d7e4:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01d7e8:	3c058006 */ 	lui	$a1,%hi(var80062950)
/*  f01d7ec:	24a52950 */ 	addiu	$a1,$a1,%lo(var80062950)
/*  f01d7f0:	0c0036cc */ 	jal	func0000db30
/*  f01d7f4:	24848648 */ 	addiu	$a0,$a0,-31160
/*  f01d7f8:	3c198006 */ 	lui	$t9,0x8006
/*  f01d7fc:	8f392954 */ 	lw	$t9,0x2954($t9)
/*  f01d800:	3c048008 */ 	lui	$a0,0x8008
/*  f01d804:	53200011 */ 	beqzl	$t9,.L0f01d84c
/*  f01d808:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01d80c:	8c84f0c0 */ 	lw	$a0,-0xf40($a0)
/*  f01d810:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01d814:	8c820020 */ 	lw	$v0,0x20($a0)
/*  f01d818:	10400005 */ 	beqz	$v0,.L0f01d830
/*  f01d81c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d820:	10410007 */ 	beq	$v0,$at,.L0f01d840
/*  f01d824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d828:	10000008 */ 	beqz	$zero,.L0f01d84c
/*  f01d82c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d830:
/*  f01d830:	0fc4c68c */ 	jal	func0f131a30
/*  f01d834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d838:	10000004 */ 	beqz	$zero,.L0f01d84c
/*  f01d83c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d840:
/*  f01d840:	0fc4c874 */ 	jal	func0f1321d0
/*  f01d844:	00000000 */ 	sll	$zero,$zero,0x0
.L0f01d848:
/*  f01d848:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f01d84c:
/*  f01d84c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01d850:	03e00008 */ 	jr	$ra
/*  f01d854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01d85c:	00000000 */ 	sll	$zero,$zero,0x0
);
