#include <ultra64.h>
#include "boot/boot.h"
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_000000.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/game_000840.h"
#include "game/game_000850.h"
#include "game/game_000860.h"
#include "game/game_000870.h"
#include "game/game_000880.h"
#include "game/game_0008e0.h"
#include "game/game_0008f0.h"
#include "game/game_000900.h"
#include "game/game_000910.h"
#include "game/game_005fd0.h"
#include "game/game_00b190.h"
#include "game/game_00b200.h"
#include "game/game_00b210.h"
#include "game/game_00b320.h"
#include "game/game_016100.h"
#include "game/game_01b0a0.h"
#include "game/game_092610.h"
#include "game/game_10ccd0.h"
#include "game/game_1165d0.h"
#include "game/game_11ecf0.h"
#include "game/game_127910.h"
#include "game/game_148b80.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/game_16ce10.h"
#include "game/game_16cfa0.h"
#include "game/game_175f50.h"
#include "game/game_175f90.h"
#include "game/game_176080.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_1a78b0.h"
#include "gvars/gvars.h"
#include "lib/lib_03050.h"
#include "lib/lib_070d0.h"
#include "lib/lib_074f0.h"
#include "lib/lib_08a20.h"
#include "lib/lib_09660.h"
#include "lib/lib_0bfb0.h"
#include "lib/lib_0c000.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_126b0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13750.h"
#include "lib/lib_13790.h"
#include "lib/lib_13900.h"
#include "lib/lib_15860.h"
#include "lib/lib_233c0.h"
#include "lib/lib_2f490.h"
#include "lib/lib_2fa00.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48650.h"
#include "lib/lib_48b20.h"
#include "lib/lib_4b480.h"
#include "types.h"

const char var70052ca0[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70052cc4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052cf4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052d24[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052d54[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052d84[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052db4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600";
const char var70052de4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500";
const char var70052e14[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500";
const char var70052e44[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500";
const char var70052e74[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052ea4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052ed4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052f04[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052f34[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052f64[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052f94[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052fc4[] = "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700";
const char var70052ff4[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053018[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var7005303c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053060[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053084[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700530a8[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700530cc[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700530f0[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053114[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053138[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var7005315c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053180[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700531a4[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700531c8[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700531ec[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053210[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053234[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053258[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var7005327c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700532a0[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700532c4[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700532e8[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var7005330c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053330[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053354[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053378[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var7005339c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700533c0[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var700533e4[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70053408[] = "-ml0 -me0 -mgfx120 -mvtx100 -ma700";
const char var7005342c[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var70053450[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70053474[] = "-ml0 -me0 -mgfx120 -mvtx100 -ma500";
const char var70053498[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var700534bc[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var700534e0[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70053504[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70053528[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var7005354c[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var70053570[] = "-ml0 -me0 -mgfx120 -mvtx100 -ma700";
const char var70053594[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma400";
const char var700535b8[] = "-ml0 -me0 -mgfx200 -mvtx200 -ma400";
const char var700535dc[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma300";
const char var70053600[] = "-ml0 -me0 -mgfx80 -mvtx20 -ma001";
const char var70053624[] = "-ml0 -me0 -mgfx120 -mvtx98 -ma300";
const char var70053648[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var7005366c[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053690[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700536b4[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700536d8[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700536fc[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053720[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053744[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053768[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var7005378c[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700537b0[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700537d4[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700537f8[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var7005381c[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053840[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var70053864[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma130";
const char var70053888[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma140";
const char var700538ac[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var700538d0[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var700538f4[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var70053918[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var7005393c[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var70053960[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var70053984[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var700539a8[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var700539cc[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var700539f0[] = "-ml0 -me0 -mgfx96 -mvtx96 -ma115";
const char var70053a14[] = "-ml0 -me0 -mgfx100 -mvtx96 -ma120";
const char var70053a38[] = "-mgfx100 -mvtx50 -ma50";
const char var70053a50[] = "-ml0 -me0 -mgfx80 -mvtx20 -ma001";
const char var70053a74[] = "-ml0 -me0 -mgfx100 -mvtx96 -ma300";
const char var70053a98[] = "-level_";
const char var70053aa0[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";
const char var70053ad4[] = "-hard";
const char var70053adc[] = "-hard";
const char var70053ae4[] = "-ma";
const char var70053ae8[] = "-ma";
const char var70053aec[] = "-play";
const char var70053af4[] = "-play";
const char var70053afc[] = "-coop";
const char var70053b04[] = "-anti";
const char var70053b0c[] = "-mpbots";
const char var70053b14[] = "-play";
const char var70053b1c[] = "";

GLOBAL_ASM(
glabel func0000d520
/*     d520:	27bdeb28 */ 	addiu	$sp,$sp,-5336
/*     d524:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     d528:	0c002fec */ 	jal	func0000bfb0
/*     d52c:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d530:	0c003428 */ 	jal	func0000d0a0
/*     d534:	00000000 */ 	sll	$zero,$zero,0x0
/*     d538:	0c002288 */ 	jal	func00008a20
/*     d53c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d540:	0c005618 */ 	jal	initGlobalVariables
/*     d544:	00000000 */ 	sll	$zero,$zero,0x0
/*     d548:	0c004878 */ 	jal	func000121e0
/*     d54c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d550:	0c004a83 */ 	jal	func00012a0c
/*     d554:	00000000 */ 	sll	$zero,$zero,0x0
/*     d558:	0c004dd6 */ 	jal	func00013758
/*     d55c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d560:	0c0026ac */ 	jal	func00009ab0
/*     d564:	00000000 */ 	sll	$zero,$zero,0x0
/*     d568:	0c00be82 */ 	jal	func0002fa08
/*     d56c:	00000000 */ 	sll	$zero,$zero,0x0
/*     d570:	3c018006 */ 	lui	$at,0x8006
/*     d574:	0c004f25 */ 	jal	func00013c94
/*     d578:	ac22d9b0 */ 	sw	$v0,-0x2650($at)
/*     d57c:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d580:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d584:	0c0120d0 */ 	jal	func00048340
/*     d588:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d58c:	00008025 */ 	or	$s0,$zero,$zero
/*     d590:	3c070047 */ 	lui	$a3,0x47
.L0000d594:
/*     d594:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     d598:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     d59c:	27b81490 */ 	addiu	$t8,$sp,0x1490
/*     d5a0:	27b914cc */ 	addiu	$t9,$sp,0x14cc
/*     d5a4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     d5a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*     d5ac:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     d5b0:	afae0010 */ 	sw	$t6,0x10($sp)
/*     d5b4:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     d5b8:	27a414a8 */ 	addiu	$a0,$sp,0x14a8
/*     d5bc:	0c0122c8 */ 	jal	func00048b20
/*     d5c0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     d5c4:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d5c8:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d5cc:	0c0121bc */ 	jal	func000486f0
/*     d5d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*     d5d8:	56010006 */ 	bnel	$s0,$at,.L0000d5f4
/*     d5dc:	2a010002 */ 	slti	$at,$s0,0x2
/*     d5e0:	0c004f7f */ 	jal	func00013dfc
/*     d5e4:	00000000 */ 	sll	$zero,$zero,0x0
/*     d5e8:	10000007 */ 	beqz	$zero,.L0000d608
/*     d5ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5f0:	2a010002 */ 	slti	$at,$s0,0x2
.L0000d5f4:
/*     d5f4:	54200004 */ 	bnezl	$at,.L0000d608
/*     d5f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5fc:	0c0050bc */ 	jal	func000142f0
/*     d600:	00000000 */ 	sll	$zero,$zero,0x0
/*     d604:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000d608:
/*     d608:	24010004 */ 	addiu	$at,$zero,0x4
/*     d60c:	5601ffe1 */ 	bnel	$s0,$at,.L0000d594
/*     d610:	3c070047 */ 	lui	$a3,0x47
/*     d614:	3c057005 */ 	lui	$a1,%hi(var70053a98)
/*     d618:	24a53a98 */ 	addiu	$a1,$a1,%lo(var70053a98)
/*     d61c:	0c004c04 */ 	jal	func00013010
/*     d620:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d624:	14400004 */ 	bnez	$v0,.L0000d638
/*     d628:	00002025 */ 	or	$a0,$zero,$zero
/*     d62c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*     d630:	3c018006 */ 	lui	$at,0x8006
/*     d634:	ac2bd9b0 */ 	sw	$t3,-0x2650($at)
.L0000d638:
/*     d638:	0c0053d8 */ 	jal	func00014f60
/*     d63c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d640:	14400010 */ 	bnez	$v0,.L0000d684
/*     d644:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d648:	0c0053d8 */ 	jal	func00014f60
/*     d64c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d650:	1440000c */ 	bnez	$v0,.L0000d684
/*     d654:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d658:	0c0053d8 */ 	jal	func00014f60
/*     d65c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d660:	14400008 */ 	bnez	$v0,.L0000d684
/*     d664:	24040003 */ 	addiu	$a0,$zero,0x3
/*     d668:	0c0053d8 */ 	jal	func00014f60
/*     d66c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d670:	14400004 */ 	bnez	$v0,.L0000d684
/*     d674:	3c108006 */ 	lui	$s0,%hi(var8005d9d4)
/*     d678:	2610d9d4 */ 	addiu	$s0,$s0,%lo(var8005d9d4)
/*     d67c:	10000005 */ 	beqz	$zero,.L0000d694
/*     d680:	ae000000 */ 	sw	$zero,0x0($s0)
.L0000d684:
/*     d684:	3c108006 */ 	lui	$s0,%hi(var8005d9d4)
/*     d688:	2610d9d4 */ 	addiu	$s0,$s0,%lo(var8005d9d4)
/*     d68c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*     d690:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0000d694:
/*     d694:	3c0e8006 */ 	lui	$t6,%hi(var8005dd1c)
/*     d698:	afa01470 */ 	sw	$zero,0x1470($sp)
/*     d69c:	25cedd1c */ 	addiu	$t6,$t6,%lo(var8005dd1c)
/*     d6a0:	8dc10000 */ 	lw	$at,0x0($t6)
/*     d6a4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*     d6a8:	27ad1450 */ 	addiu	$t5,$sp,0x1450
/*     d6ac:	ada10000 */ 	sw	$at,0x0($t5)
/*     d6b0:	adb90004 */ 	sw	$t9,0x4($t5)
/*     d6b4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*     d6b8:	8dc10008 */ 	lw	$at,0x8($t6)
/*     d6bc:	adb9000c */ 	sw	$t9,0xc($t5)
/*     d6c0:	ada10008 */ 	sw	$at,0x8($t5)
/*     d6c4:	8dc10010 */ 	lw	$at,0x10($t6)
/*     d6c8:	8dd90014 */ 	lw	$t9,0x14($t6)
/*     d6cc:	ada10010 */ 	sw	$at,0x10($t5)
/*     d6d0:	adb90014 */ 	sw	$t9,0x14($t5)
/*     d6d4:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*     d6d8:	8dc10018 */ 	lw	$at,0x18($t6)
/*     d6dc:	adb9001c */ 	sw	$t9,0x1c($t5)
/*     d6e0:	0c0005b0 */ 	jal	func000016c0
/*     d6e4:	ada10018 */ 	sw	$at,0x18($t5)
/*     d6e8:	3c010040 */ 	lui	$at,0x40
/*     d6ec:	34210001 */ 	ori	$at,$at,0x1
/*     d6f0:	0041082a */ 	slt	$at,$v0,$at
/*     d6f4:	1020000e */ 	beqz	$at,.L0000d730
/*     d6f8:	3c028080 */ 	lui	$v0,0x8080
/*     d6fc:	3c0b8006 */ 	lui	$t3,0x8006
/*     d700:	8d6bcf84 */ 	lw	$t3,-0x307c($t3)
/*     d704:	3c18803f */ 	lui	$t8,0x803f
/*     d708:	371850b8 */ 	ori	$t8,$t8,0x50b8
/*     d70c:	3c01ffef */ 	lui	$at,0xffef
/*     d710:	000b60c0 */ 	sll	$t4,$t3,0x3
/*     d714:	030c1023 */ 	subu	$v0,$t8,$t4
/*     d718:	34214000 */ 	ori	$at,$at,0x4000
/*     d71c:	00411021 */ 	addu	$v0,$v0,$at
/*     d720:	304f1fff */ 	andi	$t7,$v0,0x1fff
/*     d724:	004f1023 */ 	subu	$v0,$v0,$t7
/*     d728:	10000001 */ 	beqz	$zero,.L0000d730
/*     d72c:	2442e380 */ 	addiu	$v0,$v0,-7296
.L0000d730:
/*     d730:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*     d734:	3c01fff6 */ 	lui	$at,0xfff6
/*     d738:	3421a000 */ 	ori	$at,$at,0xa000
/*     d73c:	00411021 */ 	addu	$v0,$v0,$at
/*     d740:	11a0000f */ 	beqz	$t5,.L0000d780
/*     d744:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     d748:	3c018000 */ 	lui	$at,0x8000
/*     d74c:	00418025 */ 	or	$s0,$v0,$at
/*     d750:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d754:	3c030200 */ 	lui	$v1,0x200
/*     d758:	360e003f */ 	ori	$t6,$s0,0x3f
/*     d75c:	3c0b0200 */ 	lui	$t3,0x200
/*     d760:	2465f550 */ 	addiu	$a1,$v1,-2736
/*     d764:	256bfe00 */ 	addiu	$t3,$t3,-512
/*     d768:	39c4003f */ 	xori	$a0,$t6,0x3f
/*     d76c:	00808025 */ 	or	$s0,$a0,$zero
/*     d770:	0c003504 */ 	jal	func0000d410
/*     d774:	01653023 */ 	subu	$a2,$t3,$a1
/*     d778:	1000000e */ 	beqz	$zero,.L0000d7b4
/*     d77c:	3c01ffff */ 	lui	$at,0xffff
.L0000d780:
/*     d780:	3c018000 */ 	lui	$at,0x8000
/*     d784:	00418025 */ 	or	$s0,$v0,$at
/*     d788:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d78c:	3c030200 */ 	lui	$v1,0x200
/*     d790:	3618003f */ 	ori	$t8,$s0,0x3f
/*     d794:	3c0f0200 */ 	lui	$t7,0x200
/*     d798:	2465ea20 */ 	addiu	$a1,$v1,-5600
/*     d79c:	25eff550 */ 	addiu	$t7,$t7,-2736
/*     d7a0:	3b04003f */ 	xori	$a0,$t8,0x3f
/*     d7a4:	00808025 */ 	or	$s0,$a0,$zero
/*     d7a8:	0c003504 */ 	jal	func0000d410
/*     d7ac:	01e53023 */ 	subu	$a2,$t7,$a1
/*     d7b0:	3c01ffff */ 	lui	$at,0xffff
.L0000d7b4:
/*     d7b4:	342141e0 */ 	ori	$at,$at,0x41e0
/*     d7b8:	02012821 */ 	addu	$a1,$s0,$at
/*     d7bc:	afa50048 */ 	sw	$a1,0x48($sp)
/*     d7c0:	02002025 */ 	or	$a0,$s0,$zero
/*     d7c4:	0c001d3c */ 	jal	func000074f0
/*     d7c8:	27a60050 */ 	addiu	$a2,$sp,0x50
/*     d7cc:	3c050004 */ 	lui	$a1,0x4
/*     d7d0:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d7d4:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     d7d8:	00003825 */ 	or	$a3,$zero,$zero
/*     d7dc:	24040500 */ 	addiu	$a0,$zero,0x500
/*     d7e0:	00076840 */ 	sll	$t5,$a3,0x1
.L0000d7e4:
/*     d7e4:	020d1821 */ 	addu	$v1,$s0,$t5
/*     d7e8:	00001025 */ 	or	$v0,$zero,$zero
.L0000d7ec:
/*     d7ec:	00627021 */ 	addu	$t6,$v1,$v0
/*     d7f0:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d7f4:	1444fffd */ 	bne	$v0,$a0,.L0000d7ec
/*     d7f8:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     d7fc:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     d800:	00e5082a */ 	slt	$at,$a3,$a1
/*     d804:	5420fff7 */ 	bnezl	$at,.L0000d7e4
/*     d808:	00076840 */ 	sll	$t5,$a3,0x1
/*     d80c:	3c198000 */ 	lui	$t9,0x8000
/*     d810:	8f390300 */ 	lw	$t9,0x300($t9)
/*     d814:	00003825 */ 	or	$a3,$zero,$zero
/*     d818:	00003025 */ 	or	$a2,$zero,$zero
/*     d81c:	13200010 */ 	beqz	$t9,.L0000d860
/*     d820:	24095f10 */ 	addiu	$t1,$zero,0x5f10
/*     d824:	240503f6 */ 	addiu	$a1,$zero,0x3f6
.L0000d828:
/*     d828:	00075840 */ 	sll	$t3,$a3,0x1
/*     d82c:	0006c040 */ 	sll	$t8,$a2,0x1
/*     d830:	01582021 */ 	addu	$a0,$t2,$t8
/*     d834:	020b1821 */ 	addu	$v1,$s0,$t3
/*     d838:	00001025 */ 	or	$v0,$zero,$zero
.L0000d83c:
/*     d83c:	00826021 */ 	addu	$t4,$a0,$v0
/*     d840:	958f0000 */ 	lhu	$t7,0x0($t4)
/*     d844:	00626821 */ 	addu	$t5,$v1,$v0
/*     d848:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d84c:	1445fffb */ 	bne	$v0,$a1,.L0000d83c
/*     d850:	a5af008a */ 	sh	$t7,0x8a($t5)
/*     d854:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     d858:	14c9fff3 */ 	bne	$a2,$t1,.L0000d828
/*     d85c:	24e70240 */ 	addiu	$a3,$a3,0x240
.L0000d860:
/*     d860:	0c002aac */ 	jal	func0000aab0
/*     d864:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d868:	0c0026d4 */ 	jal	func00009b50
/*     d86c:	02002025 */ 	or	$a0,$s0,$zero
/*     d870:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d874:	3c018006 */ 	lui	$at,0x8006
/*     d878:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d87c:	ac2af044 */ 	sw	$t2,-0xfbc($at)
/*     d880:	3c018006 */ 	lui	$at,0x8006
/*     d884:	254e0800 */ 	addiu	$t6,$t2,0x800
/*     d888:	ac2ef040 */ 	sw	$t6,-0xfc0($at)
/*     d88c:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d890:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d894:	0c0121bc */ 	jal	func000486f0
/*     d898:	00003025 */ 	or	$a2,$zero,$zero
/*     d89c:	14400007 */ 	bnez	$v0,.L0000d8bc
.L0000d8a0:
/*     d8a0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8a4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8a8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8ac:	0c0121bc */ 	jal	func000486f0
/*     d8b0:	00003025 */ 	or	$a2,$zero,$zero
/*     d8b4:	1040fffa */ 	beqz	$v0,.L0000d8a0
/*     d8b8:	00000000 */ 	sll	$zero,$zero,0x0
.L0000d8bc:
/*     d8bc:	00001825 */ 	or	$v1,$zero,$zero
.L0000d8c0:
/*     d8c0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8c4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8c8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d8d0:	0c0121bc */ 	jal	func000486f0
/*     d8d4:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8d8:	8fb91470 */ 	lw	$t9,0x1470($sp)
/*     d8dc:	24010001 */ 	addiu	$at,$zero,0x1
/*     d8e0:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d8e4:	872b0000 */ 	lh	$t3,0x0($t9)
/*     d8e8:	27b01450 */ 	addiu	$s0,$sp,0x1450
/*     d8ec:	5561000d */ 	bnel	$t3,$at,.L0000d924
/*     d8f0:	28610006 */ 	slti	$at,$v1,0x6
/*     d8f4:	0c002811 */ 	jal	func0000a044
/*     d8f8:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8fc:	3c048006 */ 	lui	$a0,%hi(var8005dcc8)
/*     d900:	3c058006 */ 	lui	$a1,%hi(var8005dcf0)
/*     d904:	24a5dcf0 */ 	addiu	$a1,$a1,%lo(var8005dcf0)
/*     d908:	2484dcc8 */ 	addiu	$a0,$a0,%lo(var8005dcc8)
/*     d90c:	00003025 */ 	or	$a2,$zero,$zero
/*     d910:	0c00be3d */ 	jal	func0002f8f4
/*     d914:	02003825 */ 	or	$a3,$s0,$zero
/*     d918:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d91c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     d920:	28610006 */ 	slti	$at,$v1,0x6
.L0000d924:
/*     d924:	1420ffe6 */ 	bnez	$at,.L0000d8c0
/*     d928:	00000000 */ 	sll	$zero,$zero,0x0
/*     d92c:	3c188000 */ 	lui	$t8,0x8000
/*     d930:	8f180300 */ 	lw	$t8,0x300($t8)
/*     d934:	17000003 */ 	bnez	$t8,.L0000d944
/*     d938:	00000000 */ 	sll	$zero,$zero,0x0
.L0000d93c:
/*     d93c:	1000ffff */ 	beqz	$zero,.L0000d93c
/*     d940:	00000000 */ 	sll	$zero,$zero,0x0
.L0000d944:
/*     d944:	0c001c34 */ 	jal	func000070d0
/*     d948:	00000000 */ 	sll	$zero,$zero,0x0
/*     d94c:	0fc69e2c */ 	jal	func0f1a78b0
/*     d950:	00000000 */ 	sll	$zero,$zero,0x0
/*     d954:	0fc59bdd */ 	jal	func0f166f74
/*     d958:	00000000 */ 	sll	$zero,$zero,0x0
/*     d95c:	0fc5d7d4 */ 	jal	func0f175f50
/*     d960:	00000000 */ 	sll	$zero,$zero,0x0
/*     d964:	0fc5d7e4 */ 	jal	func0f175f90
/*     d968:	00000000 */ 	sll	$zero,$zero,0x0
/*     d96c:	3c0c8006 */ 	lui	$t4,0x8006
/*     d970:	8d8cd9b0 */ 	lw	$t4,-0x2650($t4)
/*     d974:	11800003 */ 	beqz	$t4,.L0000d984
/*     d978:	3c047005 */ 	lui	$a0,%hi(var70053aa0)
/*     d97c:	0c004bbf */ 	jal	func00012efc
/*     d980:	24843aa0 */ 	addiu	$a0,$a0,%lo(var70053aa0)
.L0000d984:
/*     d984:	3c04800b */ 	lui	$a0,%hi(var800ad1c0)
/*     d988:	0c012d20 */ 	jal	func0004b480
/*     d98c:	2484d1c0 */ 	addiu	$a0,$a0,%lo(var800ad1c0)
/*     d990:	3c038009 */ 	lui	$v1,0x8009
/*     d994:	8c630b00 */ 	lw	$v1,0xb00($v1)
/*     d998:	3c018000 */ 	lui	$at,0x8000
/*     d99c:	00412025 */ 	or	$a0,$v0,$at
/*     d9a0:	0c00487a */ 	jal	func000121e8
/*     d9a4:	00642823 */ 	subu	$a1,$v1,$a0
/*     d9a8:	0c00494a */ 	jal	func00012528
/*     d9ac:	24040008 */ 	addiu	$a0,$zero,0x8
/*     d9b0:	0c00494a */ 	jal	func00012528
/*     d9b4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     d9b8:	0c0033be */ 	jal	func0000cef8
/*     d9bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9c0:	0fc02c84 */ 	jal	func0f00b210
/*     d9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9c8:	0fc5db77 */ 	jal	func0f176ddc
/*     d9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9d0:	0c000d34 */ 	jal	func000034d0
/*     d9d4:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9d8:	0fc02c64 */ 	jal	func0f00b190
/*     d9dc:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9e0:	0fc00000 */ 	jal	func0f000000
/*     d9e4:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9e8:	0fc59ebe */ 	jal	func0f167af8
/*     d9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9f0:	0fc41d3b */ 	jal	cheatsDisableAll
/*     d9f4:	00000000 */ 	sll	$zero,$zero,0x0
/*     d9f8:	0c003a70 */ 	jal	func0000e9c0
/*     d9fc:	00000000 */ 	sll	$zero,$zero,0x0
/*     da00:	0fc54c68 */ 	jal	func0f1531a0
/*     da04:	00000000 */ 	sll	$zero,$zero,0x0
/*     da08:	0c004de4 */ 	jal	func00013790
/*     da0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da10:	0fc49e44 */ 	jal	func0f127910
/*     da14:	00000000 */ 	sll	$zero,$zero,0x0
/*     da18:	0fc5b384 */ 	jal	func0f16ce10
/*     da1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da20:	0fc02c80 */ 	jal	func0f00b200
/*     da24:	00000000 */ 	sll	$zero,$zero,0x0
/*     da28:	0c0026a0 */ 	jal	func00009a80
/*     da2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da30:	0fc0021c */ 	jal	func0f000870
/*     da34:	00000000 */ 	sll	$zero,$zero,0x0
/*     da38:	0fc00220 */ 	jal	func0f000880
/*     da3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da40:	0fc00238 */ 	jal	func0f0008e0
/*     da44:	00000000 */ 	sll	$zero,$zero,0x0
/*     da48:	0fc0023c */ 	jal	func0f0008f0
/*     da4c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da50:	0fc00240 */ 	jal	func0f000900
/*     da54:	00000000 */ 	sll	$zero,$zero,0x0
/*     da58:	0fc02c60 */ 	jal	func0f00b180
/*     da5c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da60:	0fc00244 */ 	jal	func0f000910
/*     da64:	00000000 */ 	sll	$zero,$zero,0x0
/*     da68:	0fc00210 */ 	jal	func0f000840
/*     da6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da70:	0fc62084 */ 	jal	func0f188210
/*     da74:	00000000 */ 	sll	$zero,$zero,0x0
/*     da78:	0fc528ca */ 	jal	func0f14a328
/*     da7c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da80:	0fc46276 */ 	jal	func0f1189d8
/*     da84:	00000000 */ 	sll	$zero,$zero,0x0
/*     da88:	0fc528ef */ 	jal	func0f14a3bc
/*     da8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     da90:	0c008cf0 */ 	jal	func000233c0
/*     da94:	00000000 */ 	sll	$zero,$zero,0x0
/*     da98:	0fc00040 */ 	jal	func0f000100
/*     da9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa0:	0fc0004c */ 	jal	func0f000130
/*     daa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa8:	0fc00214 */ 	jal	func0f000850
/*     daac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab0:	0fc00218 */ 	jal	func0f000860
/*     dab4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab8:	0fc00024 */ 	jal	func0f000090
/*     dabc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac0:	0c0026fe */ 	jal	func00009bf8
/*     dac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac8:	0c0027b1 */ 	jal	func00009ec4
/*     dacc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dad0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     dad4:	3c018006 */ 	lui	$at,0x8006
/*     dad8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dadc:	ac20dd18 */ 	sw	$zero,-0x22e8($at)
/*     dae0:	03e00008 */ 	jr	$ra
/*     dae4:	27bd14d8 */ 	addiu	$sp,$sp,0x14d8
);

GLOBAL_ASM(
glabel func0000dae8
/*     dae8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     daec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     daf0:	0c003548 */ 	jal	func0000d520
/*     daf4:	00000000 */ 	sll	$zero,$zero,0x0
/*     daf8:	0c00be28 */ 	jal	func0002f8a0
/*     dafc:	00000000 */ 	sll	$zero,$zero,0x0
/*     db00:	0c003e01 */ 	jal	func0000f804
/*     db04:	00000000 */ 	sll	$zero,$zero,0x0
.L0000db08:
/*     db08:	0c0036cf */ 	jal	func0000db3c
/*     db0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     db10:	1000fffd */ 	beqz	$zero,.L0000db08
/*     db14:	00000000 */ 	sll	$zero,$zero,0x0
/*     db18:	00000000 */ 	sll	$zero,$zero,0x0
/*     db1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     db20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     db24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     db28:	03e00008 */ 	jr	$ra
/*     db2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000db30
/*     db30:	afa40000 */ 	sw	$a0,0x0($sp)
/*     db34:	03e00008 */ 	jr	$ra
/*     db38:	afa50004 */ 	sw	$a1,0x4($sp)
);

GLOBAL_ASM(
glabel func0000db3c
/*     db3c:	27bdff78 */ 	addiu	$sp,$sp,-136
/*     db40:	3c0f8006 */ 	lui	$t7,%hi(var8005dd5c)
/*     db44:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     db48:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     db4c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     db50:	afb60030 */ 	sw	$s6,0x30($sp)
/*     db54:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     db58:	afb40028 */ 	sw	$s4,0x28($sp)
/*     db5c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     db60:	afb20020 */ 	sw	$s2,0x20($sp)
/*     db64:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     db68:	afb00018 */ 	sw	$s0,0x18($sp)
/*     db6c:	afa00084 */ 	sw	$zero,0x84($sp)
/*     db70:	25efdd5c */ 	addiu	$t7,$t7,%lo(var8005dd5c)
/*     db74:	8de10000 */ 	lw	$at,0x0($t7)
/*     db78:	8de80004 */ 	lw	$t0,0x4($t7)
/*     db7c:	27ae0064 */ 	addiu	$t6,$sp,0x64
/*     db80:	adc10000 */ 	sw	$at,0x0($t6)
/*     db84:	adc80004 */ 	sw	$t0,0x4($t6)
/*     db88:	8de8000c */ 	lw	$t0,0xc($t7)
/*     db8c:	8de10008 */ 	lw	$at,0x8($t7)
/*     db90:	adc8000c */ 	sw	$t0,0xc($t6)
/*     db94:	adc10008 */ 	sw	$at,0x8($t6)
/*     db98:	8de10010 */ 	lw	$at,0x10($t7)
/*     db9c:	8de80014 */ 	lw	$t0,0x14($t7)
/*     dba0:	adc10010 */ 	sw	$at,0x10($t6)
/*     dba4:	adc80014 */ 	sw	$t0,0x14($t6)
/*     dba8:	8de8001c */ 	lw	$t0,0x1c($t7)
/*     dbac:	8de10018 */ 	lw	$at,0x18($t7)
/*     dbb0:	adc8001c */ 	sw	$t0,0x1c($t6)
/*     dbb4:	0fc5d7e6 */ 	jal	func0f175f98
/*     dbb8:	adc10018 */ 	sw	$at,0x18($t6)
/*     dbbc:	3c018006 */ 	lui	$at,0x8006
/*     dbc0:	3c048006 */ 	lui	$a0,%hi(g_StageNum)
/*     dbc4:	ac20d9c4 */ 	sw	$zero,-0x263c($at)
/*     dbc8:	0c004c35 */ 	jal	func000130d4
/*     dbcc:	2484d9b4 */ 	addiu	$a0,$a0,%lo(g_StageNum)
/*     dbd0:	3c098006 */ 	lui	$t1,0x8006
/*     dbd4:	8d29d9d4 */ 	lw	$t1,-0x262c($t1)
/*     dbd8:	3c028006 */ 	lui	$v0,%hi(g_StageNum)
/*     dbdc:	2442d9b4 */ 	addiu	$v0,$v0,%lo(g_StageNum)
/*     dbe0:	11200006 */ 	beqz	$t1,.L0000dbfc
/*     dbe4:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*     dbe8:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*     dbec:	240a00fd */ 	addiu	$t2,$zero,0xfd
/*     dbf0:	240b005b */ 	addiu	$t3,$zero,0x5b
/*     dbf4:	a64a04e4 */ 	sh	$t2,0x4e4($s2)
/*     dbf8:	ac4b0000 */ 	sw	$t3,0x0($v0)
.L0000dbfc:
/*     dbfc:	3c028006 */ 	lui	$v0,%hi(g_StageNum)
/*     dc00:	2442d9b4 */ 	addiu	$v0,$v0,%lo(g_StageNum)
/*     dc04:	8c440000 */ 	lw	$a0,0x0($v0)
/*     dc08:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*     dc0c:	2401005a */ 	addiu	$at,$zero,0x5a
/*     dc10:	10810016 */ 	beq	$a0,$at,.L0000dc6c
/*     dc14:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*     dc18:	0fc06c55 */ 	jal	func0f01b154
/*     dc1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dc20:	3c0c8006 */ 	lui	$t4,0x8006
/*     dc24:	8d8cd9b4 */ 	lw	$t4,-0x264c($t4)
/*     dc28:	2981005a */ 	slti	$at,$t4,0x5a
/*     dc2c:	1020000f */ 	beqz	$at,.L0000dc6c
/*     dc30:	00000000 */ 	sll	$zero,$zero,0x0
/*     dc34:	0fc06c52 */ 	jal	func0f01b148
/*     dc38:	00002025 */ 	or	$a0,$zero,$zero
/*     dc3c:	3c057005 */ 	lui	$a1,%hi(var70053ad4)
/*     dc40:	24a53ad4 */ 	addiu	$a1,$a1,%lo(var70053ad4)
/*     dc44:	0c004c04 */ 	jal	func00013010
/*     dc48:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dc4c:	10400007 */ 	beqz	$v0,.L0000dc6c
/*     dc50:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dc54:	3c057005 */ 	lui	$a1,%hi(var70053adc)
/*     dc58:	0c004c04 */ 	jal	func00013010
/*     dc5c:	24a53adc */ 	addiu	$a1,$a1,%lo(var70053adc)
/*     dc60:	90440000 */ 	lbu	$a0,0x0($v0)
/*     dc64:	0fc5b36a */ 	jal	setDifficulty
/*     dc68:	2484ffd0 */ 	addiu	$a0,$a0,-48
.L0000dc6c:
/*     dc6c:	3c028006 */ 	lui	$v0,%hi(g_StageNum)
/*     dc70:	2442d9b4 */ 	addiu	$v0,$v0,%lo(g_StageNum)
/*     dc74:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*     dc78:	24010026 */ 	addiu	$at,$zero,0x26
/*     dc7c:	3c198009 */ 	lui	$t9,0x8009
/*     dc80:	15a10007 */ 	bne	$t5,$at,.L0000dca0
/*     dc84:	00000000 */ 	sll	$zero,$zero,0x0
/*     dc88:	93390af0 */ 	lbu	$t9,0xaf0($t9)
/*     dc8c:	24160001 */ 	addiu	$s6,$zero,0x1
/*     dc90:	2418005d */ 	addiu	$t8,$zero,0x5d
/*     dc94:	16d90002 */ 	bne	$s6,$t9,.L0000dca0
/*     dc98:	00000000 */ 	sll	$zero,$zero,0x0
/*     dc9c:	ac580000 */ 	sw	$t8,0x0($v0)
.L0000dca0:
/*     dca0:	0c012144 */ 	jal	func00048510
/*     dca4:	24160001 */ 	addiu	$s6,$zero,0x1
/*     dca8:	0c004b82 */ 	jal	func00012e08
/*     dcac:	00402025 */ 	or	$a0,$v0,$zero
/*     dcb0:	3c178006 */ 	lui	$s7,%hi(var8005dd54)
/*     dcb4:	3c138009 */ 	lui	$s3,%hi(var8008db30)
/*     dcb8:	3c108006 */ 	lui	$s0,%hi(var8005d9cc)
/*     dcbc:	2610d9cc */ 	addiu	$s0,$s0,%lo(var8005d9cc)
/*     dcc0:	2673db30 */ 	addiu	$s3,$s3,%lo(var8008db30)
/*     dcc4:	26f7dd54 */ 	addiu	$s7,$s7,%lo(var8005dd54)
/*     dcc8:	241e0002 */ 	addiu	$s8,$zero,0x2
/*     dccc:	2415ffff */ 	addiu	$s5,$zero,-1
/*     dcd0:	27b40060 */ 	addiu	$s4,$sp,0x60
.L0000dcd4:
/*     dcd4:	ae000000 */ 	sw	$zero,0x0($s0)
/*     dcd8:	3c0e8006 */ 	lui	$t6,0x8006
/*     dcdc:	8dced9b0 */ 	lw	$t6,-0x2650($t6)
/*     dce0:	3c018006 */ 	lui	$at,0x8006
/*     dce4:	ac36d9c8 */ 	sw	$s6,-0x2638($at)
/*     dce8:	3c018006 */ 	lui	$at,0x8006
/*     dcec:	afa00060 */ 	sw	$zero,0x60($sp)
/*     dcf0:	11c0007b */ 	beqz	$t6,.L0000dee0
/*     dcf4:	ac20d9d0 */ 	sw	$zero,-0x2630($at)
/*     dcf8:	3c0f8006 */ 	lui	$t7,0x8006
/*     dcfc:	8defd9c4 */ 	lw	$t7,-0x263c($t7)
/*     dd00:	3c088009 */ 	lui	$t0,0x8009
/*     dd04:	15e00076 */ 	bnez	$t7,.L0000dee0
/*     dd08:	00000000 */ 	sll	$zero,$zero,0x0
/*     dd0c:	91080af0 */ 	lbu	$t0,0xaf0($t0)
/*     dd10:	02a02825 */ 	or	$a1,$s5,$zero
/*     dd14:	3c098006 */ 	lui	$t1,0x8006
/*     dd18:	16c8003a */ 	bne	$s6,$t0,.L0000de04
/*     dd1c:	3c0f8006 */ 	lui	$t7,0x8006
/*     dd20:	8d29d9b4 */ 	lw	$t1,-0x264c($t1)
/*     dd24:	2921005a */ 	slti	$at,$t1,0x5a
/*     dd28:	1020001e */ 	beqz	$at,.L0000dda4
/*     dd2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dd30:	0fc068d2 */ 	jal	getNumPlayers
/*     dd34:	afa5005c */ 	sw	$a1,0x5c($sp)
/*     dd38:	28410002 */ 	slti	$at,$v0,0x2
/*     dd3c:	14200019 */ 	bnez	$at,.L0000dda4
/*     dd40:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*     dd44:	3c0a8006 */ 	lui	$t2,0x8006
/*     dd48:	8d4adbd0 */ 	lw	$t2,-0x2430($t2)
/*     dd4c:	00002825 */ 	or	$a1,$zero,$zero
/*     dd50:	3c048006 */ 	lui	$a0,%hi(var80060190)
/*     dd54:	1140000d */ 	beqz	$t2,.L0000dd8c
/*     dd58:	3c0d8006 */ 	lui	$t5,0x8006
/*     dd5c:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     dd60:	3c0b8006 */ 	lui	$t3,0x8006
/*     dd64:	2562dbd0 */ 	addiu	$v0,$t3,-9264
/*     dd68:	8c430000 */ 	lw	$v1,0x0($v0)
/*     dd6c:	24840190 */ 	addiu	$a0,$a0,%lo(var80060190)
.L0000dd70:
/*     dd70:	50830007 */ 	beql	$a0,$v1,.L0000dd90
/*     dd74:	000560c0 */ 	sll	$t4,$a1,0x3
/*     dd78:	8c430008 */ 	lw	$v1,0x8($v0)
/*     dd7c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     dd80:	24420008 */ 	addiu	$v0,$v0,0x8
/*     dd84:	1460fffa */ 	bnez	$v1,.L0000dd70
/*     dd88:	00000000 */ 	sll	$zero,$zero,0x0
.L0000dd8c:
/*     dd8c:	000560c0 */ 	sll	$t4,$a1,0x3
.L0000dd90:
/*     dd90:	01ac6821 */ 	addu	$t5,$t5,$t4
/*     dd94:	8daddbd0 */ 	lw	$t5,-0x2430($t5)
/*     dd98:	15a00002 */ 	bnez	$t5,.L0000dda4
/*     dd9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dda0:	02a02825 */ 	or	$a1,$s5,$zero
.L0000dda4:
/*     dda4:	04a10010 */ 	bgez	$a1,.L0000dde8
/*     dda8:	3c198006 */ 	lui	$t9,0x8006
/*     ddac:	8f39dbd0 */ 	lw	$t9,-0x2430($t9)
/*     ddb0:	00002825 */ 	or	$a1,$zero,$zero
/*     ddb4:	3c048006 */ 	lui	$a0,0x8006
/*     ddb8:	1320000b */ 	beqz	$t9,.L0000dde8
/*     ddbc:	3c188006 */ 	lui	$t8,0x8006
/*     ddc0:	2702dbd0 */ 	addiu	$v0,$t8,-9264
/*     ddc4:	8c430000 */ 	lw	$v1,0x0($v0)
/*     ddc8:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
.L0000ddcc:
/*     ddcc:	50830007 */ 	beql	$a0,$v1,.L0000ddec
/*     ddd0:	000570c0 */ 	sll	$t6,$a1,0x3
/*     ddd4:	8c430008 */ 	lw	$v1,0x8($v0)
/*     ddd8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     dddc:	24420008 */ 	addiu	$v0,$v0,0x8
/*     dde0:	1460fffa */ 	bnez	$v1,.L0000ddcc
/*     dde4:	00000000 */ 	sll	$zero,$zero,0x0
.L0000dde8:
/*     dde8:	000570c0 */ 	sll	$t6,$a1,0x3
.L0000ddec:
/*     ddec:	3c048006 */ 	lui	$a0,0x8006
/*     ddf0:	008e2021 */ 	addu	$a0,$a0,$t6
/*     ddf4:	0c004bbf */ 	jal	func00012efc
/*     ddf8:	8c84dbd4 */ 	lw	$a0,-0x242c($a0)
/*     ddfc:	10000038 */ 	beqz	$zero,.L0000dee0
/*     de00:	00000000 */ 	sll	$zero,$zero,0x0
.L0000de04:
/*     de04:	8defd9b4 */ 	lw	$t7,-0x264c($t7)
/*     de08:	29e1005a */ 	slti	$at,$t7,0x5a
/*     de0c:	1020001e */ 	beqz	$at,.L0000de88
/*     de10:	00000000 */ 	sll	$zero,$zero,0x0
/*     de14:	0fc068d2 */ 	jal	getNumPlayers
/*     de18:	afa5005c */ 	sw	$a1,0x5c($sp)
/*     de1c:	28410002 */ 	slti	$at,$v0,0x2
/*     de20:	14200019 */ 	bnez	$at,.L0000de88
/*     de24:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*     de28:	3c088006 */ 	lui	$t0,0x8006
/*     de2c:	8d08d9d8 */ 	lw	$t0,-0x2628($t0)
/*     de30:	00002825 */ 	or	$a1,$zero,$zero
/*     de34:	3c048006 */ 	lui	$a0,%hi(var80060190)
/*     de38:	1100000d */ 	beqz	$t0,.L0000de70
/*     de3c:	3c0b8006 */ 	lui	$t3,0x8006
/*     de40:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     de44:	3c098006 */ 	lui	$t1,0x8006
/*     de48:	2522d9d8 */ 	addiu	$v0,$t1,-9768
/*     de4c:	8c430000 */ 	lw	$v1,0x0($v0)
/*     de50:	24840190 */ 	addiu	$a0,$a0,%lo(var80060190)
.L0000de54:
/*     de54:	50830007 */ 	beql	$a0,$v1,.L0000de74
/*     de58:	000550c0 */ 	sll	$t2,$a1,0x3
/*     de5c:	8c430008 */ 	lw	$v1,0x8($v0)
/*     de60:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     de64:	24420008 */ 	addiu	$v0,$v0,0x8
/*     de68:	1460fffa */ 	bnez	$v1,.L0000de54
/*     de6c:	00000000 */ 	sll	$zero,$zero,0x0
.L0000de70:
/*     de70:	000550c0 */ 	sll	$t2,$a1,0x3
.L0000de74:
/*     de74:	016a5821 */ 	addu	$t3,$t3,$t2
/*     de78:	8d6bd9d8 */ 	lw	$t3,-0x2628($t3)
/*     de7c:	15600002 */ 	bnez	$t3,.L0000de88
/*     de80:	00000000 */ 	sll	$zero,$zero,0x0
/*     de84:	02a02825 */ 	or	$a1,$s5,$zero
.L0000de88:
/*     de88:	04a10010 */ 	bgez	$a1,.L0000decc
/*     de8c:	3c0c8006 */ 	lui	$t4,0x8006
/*     de90:	8d8cd9d8 */ 	lw	$t4,-0x2628($t4)
/*     de94:	00002825 */ 	or	$a1,$zero,$zero
/*     de98:	3c048006 */ 	lui	$a0,0x8006
/*     de9c:	1180000b */ 	beqz	$t4,.L0000decc
/*     dea0:	3c0d8006 */ 	lui	$t5,0x8006
/*     dea4:	25a2d9d8 */ 	addiu	$v0,$t5,-9768
/*     dea8:	8c430000 */ 	lw	$v1,0x0($v0)
/*     deac:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
.L0000deb0:
/*     deb0:	50830007 */ 	beql	$a0,$v1,.L0000ded0
/*     deb4:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*     deb8:	8c430008 */ 	lw	$v1,0x8($v0)
/*     debc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     dec0:	24420008 */ 	addiu	$v0,$v0,0x8
/*     dec4:	1460fffa */ 	bnez	$v1,.L0000deb0
/*     dec8:	00000000 */ 	sll	$zero,$zero,0x0
.L0000decc:
/*     decc:	0005c8c0 */ 	sll	$t9,$a1,0x3
.L0000ded0:
/*     ded0:	3c048006 */ 	lui	$a0,0x8006
/*     ded4:	00992021 */ 	addu	$a0,$a0,$t9
/*     ded8:	0c004bbf */ 	jal	func00012efc
/*     dedc:	8c84d9dc */ 	lw	$a0,-0x2624($a0)
.L0000dee0:
/*     dee0:	3c018006 */ 	lui	$at,0x8006
/*     dee4:	ac20d9c4 */ 	sw	$zero,-0x263c($at)
/*     dee8:	0c00494a */ 	jal	func00012528
/*     deec:	24040007 */ 	addiu	$a0,$zero,0x7
/*     def0:	0c00494a */ 	jal	func00012528
/*     def4:	24040004 */ 	addiu	$a0,$zero,0x4
/*     def8:	0fc59cbc */ 	jal	func0f1672f0
/*     defc:	24040004 */ 	addiu	$a0,$zero,0x4
/*     df00:	3c057005 */ 	lui	$a1,%hi(var70053ae4)
/*     df04:	24a53ae4 */ 	addiu	$a1,$a1,%lo(var70053ae4)
/*     df08:	0c004c04 */ 	jal	func00013010
/*     df0c:	02c02025 */ 	or	$a0,$s6,$zero
/*     df10:	1040000b */ 	beqz	$v0,.L0000df40
/*     df14:	02c02025 */ 	or	$a0,$s6,$zero
/*     df18:	3c057005 */ 	lui	$a1,%hi(var70053ae8)
/*     df1c:	0c004c04 */ 	jal	func00013010
/*     df20:	24a53ae8 */ 	addiu	$a1,$a1,%lo(var70053ae8)
/*     df24:	00402025 */ 	or	$a0,$v0,$zero
/*     df28:	00002825 */ 	or	$a1,$zero,$zero
/*     df2c:	0c004d02 */ 	jal	func00013408
/*     df30:	00003025 */ 	or	$a2,$zero,$zero
/*     df34:	0002c280 */ 	sll	$t8,$v0,0xa
/*     df38:	3c018006 */ 	lui	$at,0x8006
/*     df3c:	ac38d9b8 */ 	sw	$t8,-0x2648($at)
.L0000df40:
/*     df40:	3c048006 */ 	lui	$a0,0x8006
/*     df44:	8c84d9b8 */ 	lw	$a0,-0x2648($a0)
/*     df48:	0c0048f2 */ 	jal	malloc
/*     df4c:	24050004 */ 	addiu	$a1,$zero,0x4
/*     df50:	3c058006 */ 	lui	$a1,0x8006
/*     df54:	8ca5d9b8 */ 	lw	$a1,-0x2648($a1)
/*     df58:	0c004a85 */ 	jal	func00012a14
/*     df5c:	00402025 */ 	or	$a0,$v0,$zero
/*     df60:	3c048006 */ 	lui	$a0,0x8006
/*     df64:	0fc02cc8 */ 	jal	func0f00b320
/*     df68:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     df6c:	0fc49e54 */ 	jal	func0f127950
/*     df70:	00000000 */ 	sll	$zero,$zero,0x0
/*     df74:	3c0e8006 */ 	lui	$t6,0x8006
/*     df78:	8dced9b4 */ 	lw	$t6,-0x264c($t6)
/*     df7c:	02c02025 */ 	or	$a0,$s6,$zero
/*     df80:	3c057005 */ 	lui	$a1,%hi(var70053aec)
/*     df84:	29c1005a */ 	slti	$at,$t6,0x5a
/*     df88:	14200003 */ 	bnez	$at,.L0000df98
/*     df8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df90:	10000017 */ 	beqz	$zero,.L0000dff0
/*     df94:	00008825 */ 	or	$s1,$zero,$zero
.L0000df98:
/*     df98:	0c004c04 */ 	jal	func00013010
/*     df9c:	24a53aec */ 	addiu	$a1,$a1,%lo(var70053aec)
/*     dfa0:	1040000b */ 	beqz	$v0,.L0000dfd0
/*     dfa4:	02c08825 */ 	or	$s1,$s6,$zero
/*     dfa8:	3c057005 */ 	lui	$a1,%hi(var70053af4)
/*     dfac:	24a53af4 */ 	addiu	$a1,$a1,%lo(var70053af4)
/*     dfb0:	0c004c04 */ 	jal	func00013010
/*     dfb4:	02c02025 */ 	or	$a0,$s6,$zero
/*     dfb8:	00402025 */ 	or	$a0,$v0,$zero
/*     dfbc:	00002825 */ 	or	$a1,$zero,$zero
/*     dfc0:	0c004d02 */ 	jal	func00013408
/*     dfc4:	00003025 */ 	or	$a2,$zero,$zero
/*     dfc8:	10000001 */ 	beqz	$zero,.L0000dfd0
/*     dfcc:	00408825 */ 	or	$s1,$v0,$zero
.L0000dfd0:
/*     dfd0:	0fc068d2 */ 	jal	getNumPlayers
/*     dfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd8:	28410002 */ 	slti	$at,$v0,0x2
/*     dfdc:	54200005 */ 	bnezl	$at,.L0000dff4
/*     dfe0:	2a210002 */ 	slti	$at,$s1,0x2
/*     dfe4:	0fc068d2 */ 	jal	getNumPlayers
/*     dfe8:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfec:	00408825 */ 	or	$s1,$v0,$zero
.L0000dff0:
/*     dff0:	2a210002 */ 	slti	$at,$s1,0x2
.L0000dff4:
/*     dff4:	10200005 */ 	beqz	$at,.L0000e00c
/*     dff8:	02c02025 */ 	or	$a0,$s6,$zero
/*     dffc:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e000:	ae550298 */ 	sw	$s5,0x298($s2)
/*     e004:	10000012 */ 	beqz	$zero,.L0000e050
/*     e008:	ae55029c */ 	sw	$s5,0x29c($s2)
.L0000e00c:
/*     e00c:	3c057005 */ 	lui	$a1,%hi(var70053afc)
/*     e010:	0c004c04 */ 	jal	func00013010
/*     e014:	24a53afc */ 	addiu	$a1,$a1,%lo(var70053afc)
/*     e018:	10400005 */ 	beqz	$v0,.L0000e030
/*     e01c:	02c02025 */ 	or	$a0,$s6,$zero
/*     e020:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e024:	ae560298 */ 	sw	$s6,0x298($s2)
/*     e028:	10000009 */ 	beqz	$zero,.L0000e050
/*     e02c:	ae55029c */ 	sw	$s5,0x29c($s2)
.L0000e030:
/*     e030:	3c057005 */ 	lui	$a1,%hi(var70053b04)
/*     e034:	0c004c04 */ 	jal	func00013010
/*     e038:	24a53b04 */ 	addiu	$a1,$a1,%lo(var70053b04)
/*     e03c:	10400004 */ 	beqz	$v0,.L0000e050
/*     e040:	00000000 */ 	sll	$zero,$zero,0x0
/*     e044:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e048:	ae550298 */ 	sw	$s5,0x298($s2)
/*     e04c:	ae56029c */ 	sw	$s6,0x29c($s2)
.L0000e050:
/*     e050:	0fc49e69 */ 	jal	func0f1279a4
/*     e054:	02202025 */ 	or	$a0,$s1,$zero
/*     e058:	3c057005 */ 	lui	$a1,%hi(var70053b0c)
/*     e05c:	24a53b0c */ 	addiu	$a1,$a1,%lo(var70053b0c)
/*     e060:	0c004c04 */ 	jal	func00013010
/*     e064:	02c02025 */ 	or	$a0,$s6,$zero
/*     e068:	10400002 */ 	beqz	$v0,.L0000e074
/*     e06c:	24090003 */ 	addiu	$t1,$zero,0x3
/*     e070:	ae56031c */ 	sw	$s6,0x31c($s2)
.L0000e074:
/*     e074:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*     e078:	3c01800b */ 	lui	$at,0x800b
/*     e07c:	05e10004 */ 	bgez	$t7,.L0000e090
/*     e080:	00000000 */ 	sll	$zero,$zero,0x0
/*     e084:	8e48029c */ 	lw	$t0,0x29c($s2)
/*     e088:	05020006 */ 	bltzl	$t0,.L0000e0a4
/*     e08c:	8e4a0470 */ 	lw	$t2,0x470($s2)
.L0000e090:
/*     e090:	0fc61e51 */ 	jal	func0f187944
/*     e094:	a429cb9e */ 	sh	$t1,-0x3462($at)
/*     e098:	10000033 */ 	beqz	$zero,.L0000e168
/*     e09c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e0a0:	8e4a0470 */ 	lw	$t2,0x470($s2)
.L0000e0a4:
/*     e0a4:	51400006 */ 	beqzl	$t2,.L0000e0c0
/*     e0a8:	8e4b0314 */ 	lw	$t3,0x314($s2)
/*     e0ac:	0fc61e51 */ 	jal	func0f187944
/*     e0b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e0b4:	1000002c */ 	beqz	$zero,.L0000e168
/*     e0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e0bc:	8e4b0314 */ 	lw	$t3,0x314($s2)
.L0000e0c0:
/*     e0c0:	2a210002 */ 	slti	$at,$s1,0x2
/*     e0c4:	15600028 */ 	bnez	$t3,.L0000e168
/*     e0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e0cc:	5020000a */ 	beqzl	$at,.L0000e0f8
/*     e0d0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*     e0d4:	8e4c031c */ 	lw	$t4,0x31c($s2)
/*     e0d8:	02c02025 */ 	or	$a0,$s6,$zero
/*     e0dc:	3c057005 */ 	lui	$a1,%hi(var70053b14)
/*     e0e0:	55800005 */ 	bnezl	$t4,.L0000e0f8
/*     e0e4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*     e0e8:	0c004c04 */ 	jal	func00013010
/*     e0ec:	24a53b14 */ 	addiu	$a1,$a1,%lo(var70053b14)
/*     e0f0:	1040001d */ 	beqz	$v0,.L0000e168
/*     e0f4:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0000e0f8:
/*     e0f8:	3c01800b */ 	lui	$at,0x800b
/*     e0fc:	a42dcb9e */ 	sh	$t5,-0x3462($at)
/*     e100:	2a210002 */ 	slti	$at,$s1,0x2
/*     e104:	14200006 */ 	bnez	$at,.L0000e120
/*     e108:	3c0a8006 */ 	lui	$t2,0x8006
/*     e10c:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*     e110:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*     e114:	94590016 */ 	lhu	$t9,0x16($v0)
/*     e118:	37380002 */ 	ori	$t8,$t9,0x2
/*     e11c:	a4580016 */ 	sh	$t8,0x16($v0)
.L0000e120:
/*     e120:	2a210003 */ 	slti	$at,$s1,0x3
/*     e124:	14200005 */ 	bnez	$at,.L0000e13c
/*     e128:	3c02800b */ 	lui	$v0,%hi(g_MpSetup)
/*     e12c:	2442cb88 */ 	addiu	$v0,$v0,%lo(g_MpSetup)
/*     e130:	944e0016 */ 	lhu	$t6,0x16($v0)
/*     e134:	35cf0004 */ 	ori	$t7,$t6,0x4
/*     e138:	a44f0016 */ 	sh	$t7,0x16($v0)
.L0000e13c:
/*     e13c:	2a210004 */ 	slti	$at,$s1,0x4
/*     e140:	14200005 */ 	bnez	$at,.L0000e158
/*     e144:	3c08800b */ 	lui	$t0,0x800b
/*     e148:	9508cb9e */ 	lhu	$t0,-0x3462($t0)
/*     e14c:	3c01800b */ 	lui	$at,0x800b
/*     e150:	35090008 */ 	ori	$t1,$t0,0x8
/*     e154:	a429cb9e */ 	sh	$t1,-0x3462($at)
.L0000e158:
/*     e158:	8d4ad9b4 */ 	lw	$t2,-0x264c($t2)
/*     e15c:	3c01800b */ 	lui	$at,0x800b
/*     e160:	0fc61e51 */ 	jal	func0f187944
/*     e164:	a02acb99 */ 	sb	$t2,-0x3467($at)
.L0000e168:
/*     e168:	0fc59cd4 */ 	jal	func0f167350
/*     e16c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e170:	0c004f7f */ 	jal	func00013dfc
/*     e174:	00000000 */ 	sll	$zero,$zero,0x0
/*     e178:	0c004de6 */ 	jal	func00013798
/*     e17c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e180:	3c048006 */ 	lui	$a0,0x8006
/*     e184:	0fc5d823 */ 	jal	func0f17608c
/*     e188:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     e18c:	3c048006 */ 	lui	$a0,0x8006
/*     e190:	0fc59f9f */ 	jal	func0f167e7c
/*     e194:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     e198:	3c048006 */ 	lui	$a0,0x8006
/*     e19c:	0c00270f */ 	jal	func00009c3c
/*     e1a0:	8c84d9b4 */ 	lw	$a0,-0x264c($a0)
/*     e1a4:	0fc5b3a5 */ 	jal	func0f16ce94
/*     e1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1ac:	0c0026a4 */ 	jal	func00009a90
/*     e1b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1b4:	02602025 */ 	or	$a0,$s3,$zero
/*     e1b8:	02802825 */ 	or	$a1,$s4,$zero
/*     e1bc:	0c0121bc */ 	jal	func000486f0
/*     e1c0:	00003025 */ 	or	$a2,$zero,$zero
/*     e1c4:	10550006 */ 	beq	$v0,$s5,.L0000e1e0
/*     e1c8:	02602025 */ 	or	$a0,$s3,$zero
.L0000e1cc:
/*     e1cc:	02802825 */ 	or	$a1,$s4,$zero
/*     e1d0:	0c0121bc */ 	jal	func000486f0
/*     e1d4:	00003025 */ 	or	$a2,$zero,$zero
/*     e1d8:	5455fffc */ 	bnel	$v0,$s5,.L0000e1cc
/*     e1dc:	02602025 */ 	or	$a0,$s3,$zero
.L0000e1e0:
/*     e1e0:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*     e1e4:	05620004 */ 	bltzl	$t3,.L0000e1f8
/*     e1e8:	02602025 */ 	or	$a0,$s3,$zero
/*     e1ec:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*     e1f0:	1180002c */ 	beqz	$t4,.L0000e2a4
/*     e1f4:	02602025 */ 	or	$a0,$s3,$zero
.L0000e1f8:
/*     e1f8:	02802825 */ 	or	$a1,$s4,$zero
/*     e1fc:	0c0121bc */ 	jal	func000486f0
/*     e200:	02c03025 */ 	or	$a2,$s6,$zero
/*     e204:	8fad0060 */ 	lw	$t5,0x60($sp)
/*     e208:	85a30000 */ 	lh	$v1,0x0($t5)
/*     e20c:	10760007 */ 	beq	$v1,$s6,.L0000e22c
/*     e210:	00000000 */ 	sll	$zero,$zero,0x0
/*     e214:	107e0018 */ 	beq	$v1,$s8,.L0000e278
/*     e218:	24010005 */ 	addiu	$at,$zero,0x5
/*     e21c:	1061001a */ 	beq	$v1,$at,.L0000e288
/*     e220:	240a0004 */ 	addiu	$t2,$zero,0x4
/*     e224:	1000001a */ 	beqz	$zero,.L0000e290
/*     e228:	8eeb0000 */ 	lw	$t3,0x0($s7)
.L0000e22c:
/*     e22c:	0c012144 */ 	jal	func00048510
/*     e230:	00000000 */ 	sll	$zero,$zero,0x0
/*     e234:	8e580028 */ 	lw	$t8,0x28($s2)
/*     e238:	3c01000b */ 	lui	$at,0xb
/*     e23c:	3421ebc2 */ 	ori	$at,$at,0xebc2
/*     e240:	03010019 */ 	multu	$t8,$at
/*     e244:	8e590018 */ 	lw	$t9,0x18($s2)
/*     e248:	3c01fffa */ 	lui	$at,0xfffa
/*     e24c:	34210a1f */ 	ori	$at,$at,0xa1f
/*     e250:	00591823 */ 	subu	$v1,$v0,$t9
/*     e254:	00007012 */ 	mflo	$t6
/*     e258:	01c17821 */ 	addu	$t7,$t6,$at
/*     e25c:	006f082b */ 	sltu	$at,$v1,$t7
/*     e260:	5420000b */ 	bnezl	$at,.L0000e290
/*     e264:	8eeb0000 */ 	lw	$t3,0x0($s7)
/*     e268:	0c0038c9 */ 	jal	func0000e324
/*     e26c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e270:	10000007 */ 	beqz	$zero,.L0000e290
/*     e274:	8eeb0000 */ 	lw	$t3,0x0($s7)
.L0000e278:
/*     e278:	8e080000 */ 	lw	$t0,0x0($s0)
/*     e27c:	2509ffff */ 	addiu	$t1,$t0,-1
/*     e280:	10000002 */ 	beqz	$zero,.L0000e28c
/*     e284:	ae090000 */ 	sw	$t1,0x0($s0)
.L0000e288:
/*     e288:	ae0a0000 */ 	sw	$t2,0x0($s0)
.L0000e28c:
/*     e28c:	8eeb0000 */ 	lw	$t3,0x0($s7)
.L0000e290:
/*     e290:	0562ffd9 */ 	bltzl	$t3,.L0000e1f8
/*     e294:	02602025 */ 	or	$a0,$s3,$zero
/*     e298:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*     e29c:	5580ffd6 */ 	bnezl	$t4,.L0000e1f8
/*     e2a0:	02602025 */ 	or	$a0,$s3,$zero
.L0000e2a4:
/*     e2a4:	0fc5b2e8 */ 	jal	stageLoad
/*     e2a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2ac:	0c004965 */ 	jal	func00012594
/*     e2b0:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e2b4:	0c004965 */ 	jal	func00012594
/*     e2b8:	24040007 */ 	addiu	$a0,$zero,0x7
/*     e2bc:	0fc59cbc */ 	jal	func0f1672f0
/*     e2c0:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e2c4:	0c0027b1 */ 	jal	func00009ec4
/*     e2c8:	02c02025 */ 	or	$a0,$s6,$zero
/*     e2cc:	0fc45a65 */ 	jal	func0f116994
/*     e2d0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2d4:	8eed0000 */ 	lw	$t5,0x0($s7)
/*     e2d8:	8fb90084 */ 	lw	$t9,0x84($sp)
/*     e2dc:	3c018006 */ 	lui	$at,0x8006
/*     e2e0:	ac2dd9b4 */ 	sw	$t5,-0x264c($at)
/*     e2e4:	1320fe7b */ 	beqz	$t9,.L0000dcd4
/*     e2e8:	aef50000 */ 	sw	$s5,0x0($s7)
/*     e2ec:	0fc5d7f2 */ 	jal	func0f175fc8
/*     e2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     e2f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     e2fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     e300:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     e304:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     e308:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     e30c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     e310:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     e314:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     e318:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     e31c:	03e00008 */ 	jr	$ra
/*     e320:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0000e324
/*     e324:	27bdff88 */ 	addiu	$sp,$sp,-120
/*     e328:	3c0f8006 */ 	lui	$t7,%hi(var8005dd7c)
/*     e32c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     e330:	afb20020 */ 	sw	$s2,0x20($sp)
/*     e334:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     e338:	afb00018 */ 	sw	$s0,0x18($sp)
/*     e33c:	25efdd7c */ 	addiu	$t7,$t7,%lo(var8005dd7c)
/*     e340:	8de10000 */ 	lw	$at,0x0($t7)
/*     e344:	8de80004 */ 	lw	$t0,0x4($t7)
/*     e348:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*     e34c:	adc10000 */ 	sw	$at,0x0($t6)
/*     e350:	adc80004 */ 	sw	$t0,0x4($t6)
/*     e354:	8de8000c */ 	lw	$t0,0xc($t7)
/*     e358:	8de10008 */ 	lw	$at,0x8($t7)
/*     e35c:	3c098006 */ 	lui	$t1,0x8006
/*     e360:	adc8000c */ 	sw	$t0,0xc($t6)
/*     e364:	adc10008 */ 	sw	$at,0x8($t6)
/*     e368:	8de10010 */ 	lw	$at,0x10($t7)
/*     e36c:	8de80014 */ 	lw	$t0,0x14($t7)
/*     e370:	3c0a8006 */ 	lui	$t2,0x8006
/*     e374:	adc10010 */ 	sw	$at,0x10($t6)
/*     e378:	adc80014 */ 	sw	$t0,0x14($t6)
/*     e37c:	8de8001c */ 	lw	$t0,0x1c($t7)
/*     e380:	8de10018 */ 	lw	$at,0x18($t7)
/*     e384:	adc8001c */ 	sw	$t0,0x1c($t6)
/*     e388:	adc10018 */ 	sw	$at,0x18($t6)
/*     e38c:	8d29dd54 */ 	lw	$t1,-0x22ac($t1)
/*     e390:	052300b7 */ 	bgezl	$t1,.L0000e670
/*     e394:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     e398:	8d4ad9cc */ 	lw	$t2,-0x2634($t2)
/*     e39c:	2d410002 */ 	sltiu	$at,$t2,0x2
/*     e3a0:	502000b3 */ 	beqzl	$at,.L0000e670
/*     e3a4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     e3a8:	0fc5b3a5 */ 	jal	func0f16ce94
/*     e3ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3b0:	0c0026a6 */ 	jal	func00009a98
/*     e3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3b8:	0c0026a4 */ 	jal	func00009a90
/*     e3bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3c0:	0c0026a8 */ 	jal	func00009aa0
/*     e3c4:	3c040002 */ 	lui	$a0,0x2
/*     e3c8:	0c000d36 */ 	jal	func000034d8
/*     e3cc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3d0:	0c0050bc */ 	jal	func000142f0
/*     e3d4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3d8:	0c0006ca */ 	jal	func00001b28
/*     e3dc:	00002025 */ 	or	$a0,$zero,$zero
/*     e3e0:	3c048006 */ 	lui	$a0,0x8006
/*     e3e4:	8c84d9c8 */ 	lw	$a0,-0x2638($a0)
/*     e3e8:	1080008b */ 	beqz	$a0,.L0000e618
/*     e3ec:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3f0:	0fc59e4f */ 	jal	func0f16793c
/*     e3f4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3f8:	244b0008 */ 	addiu	$t3,$v0,0x8
/*     e3fc:	afa20070 */ 	sw	$v0,0x70($sp)
/*     e400:	afab0074 */ 	sw	$t3,0x74($sp)
/*     e404:	3c0cf510 */ 	lui	$t4,0xf510
/*     e408:	3c0d0700 */ 	lui	$t5,0x700
/*     e40c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*     e410:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*     e414:	8fb90074 */ 	lw	$t9,0x74($sp)
/*     e418:	3c0ef500 */ 	lui	$t6,0xf500
/*     e41c:	35ce0100 */ 	ori	$t6,$t6,0x100
/*     e420:	27380008 */ 	addiu	$t8,$t9,0x8
/*     e424:	afb80074 */ 	sw	$t8,0x74($sp)
/*     e428:	3c0f0600 */ 	lui	$t7,0x600
/*     e42c:	af2f0004 */ 	sw	$t7,0x4($t9)
/*     e430:	0fc5ae5b */ 	jal	func0f16b96c
/*     e434:	af2e0000 */ 	sw	$t6,0x0($t9)
/*     e438:	0fc4a36f */ 	jal	func0f128dbc
/*     e43c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e440:	3c088006 */ 	lui	$t0,0x8006
/*     e444:	8d08d9b4 */ 	lw	$t0,-0x264c($t0)
/*     e448:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*     e44c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*     e450:	2901005a */ 	slti	$at,$t0,0x5a
/*     e454:	10200055 */ 	beqz	$at,.L0000e5ac
/*     e458:	00000000 */ 	sll	$zero,$zero,0x0
/*     e45c:	8e29006c */ 	lw	$t1,0x6c($s1)
/*     e460:	00009025 */ 	or	$s2,$zero,$zero
/*     e464:	00002825 */ 	or	$a1,$zero,$zero
/*     e468:	11200003 */ 	beqz	$t1,.L0000e478
/*     e46c:	00002025 */ 	or	$a0,$zero,$zero
/*     e470:	10000001 */ 	beqz	$zero,.L0000e478
/*     e474:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e478:
/*     e478:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*     e47c:	00001825 */ 	or	$v1,$zero,$zero
/*     e480:	00001025 */ 	or	$v0,$zero,$zero
/*     e484:	11400003 */ 	beqz	$t2,.L0000e494
/*     e488:	00000000 */ 	sll	$zero,$zero,0x0
/*     e48c:	10000001 */ 	beqz	$zero,.L0000e494
/*     e490:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e494:
/*     e494:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*     e498:	11600003 */ 	beqz	$t3,.L0000e4a8
/*     e49c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e4a0:	10000001 */ 	beqz	$zero,.L0000e4a8
/*     e4a4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e4a8:
/*     e4a8:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*     e4ac:	11800003 */ 	beqz	$t4,.L0000e4bc
/*     e4b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e4b4:	10000001 */ 	beqz	$zero,.L0000e4bc
/*     e4b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e4bc:
/*     e4bc:	00436821 */ 	addu	$t5,$v0,$v1
/*     e4c0:	01a4c821 */ 	addu	$t9,$t5,$a0
/*     e4c4:	0325c021 */ 	addu	$t8,$t9,$a1
/*     e4c8:	1b000038 */ 	blez	$t8,.L0000e5ac
/*     e4cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e4d0:
/*     e4d0:	0fc4a3b2 */ 	jal	func0f128ec8
/*     e4d4:	02402025 */ 	or	$a0,$s2,$zero
/*     e4d8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*     e4dc:	00402025 */ 	or	$a0,$v0,$zero
/*     e4e0:	3c0e8006 */ 	lui	$t6,0x8006
/*     e4e4:	8dced9b4 */ 	lw	$t6,-0x264c($t6)
/*     e4e8:	2401004e */ 	addiu	$at,$zero,0x4e
/*     e4ec:	55c10006 */ 	bnel	$t6,$at,.L0000e508
/*     e4f0:	8e300284 */ 	lw	$s0,0x284($s1)
/*     e4f4:	0fc06aea */ 	jal	func0f01aba8
/*     e4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e4fc:	1440000b */ 	bnez	$v0,.L0000e52c
/*     e500:	00000000 */ 	sll	$zero,$zero,0x0
/*     e504:	8e300284 */ 	lw	$s0,0x284($s1)
.L0000e508:
/*     e508:	86040634 */ 	lh	$a0,0x634($s0)
/*     e50c:	0c002f2a */ 	jal	func0000bca8
/*     e510:	86050636 */ 	lh	$a1,0x636($s0)
/*     e514:	8e300284 */ 	lw	$s0,0x284($s1)
/*     e518:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*     e51c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*     e520:	86060630 */ 	lh	$a2,0x630($s0)
/*     e524:	0c002f76 */ 	jal	func0000bdd8
/*     e528:	86070632 */ 	lh	$a3,0x632($s0)
.L0000e52c:
/*     e52c:	0fc5b2c1 */ 	jal	func0f16cb04
/*     e530:	00000000 */ 	sll	$zero,$zero,0x0
/*     e534:	8e2f006c */ 	lw	$t7,0x6c($s1)
/*     e538:	26520001 */ 	addiu	$s2,$s2,0x1
/*     e53c:	00002825 */ 	or	$a1,$zero,$zero
/*     e540:	11e00003 */ 	beqz	$t7,.L0000e550
/*     e544:	00002025 */ 	or	$a0,$zero,$zero
/*     e548:	10000001 */ 	beqz	$zero,.L0000e550
/*     e54c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e550:
/*     e550:	8e280068 */ 	lw	$t0,0x68($s1)
/*     e554:	00001825 */ 	or	$v1,$zero,$zero
/*     e558:	00001025 */ 	or	$v0,$zero,$zero
/*     e55c:	11000003 */ 	beqz	$t0,.L0000e56c
/*     e560:	00000000 */ 	sll	$zero,$zero,0x0
/*     e564:	10000001 */ 	beqz	$zero,.L0000e56c
/*     e568:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e56c:
/*     e56c:	8e290064 */ 	lw	$t1,0x64($s1)
/*     e570:	11200003 */ 	beqz	$t1,.L0000e580
/*     e574:	00000000 */ 	sll	$zero,$zero,0x0
/*     e578:	10000001 */ 	beqz	$zero,.L0000e580
/*     e57c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e580:
/*     e580:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*     e584:	11400003 */ 	beqz	$t2,.L0000e594
/*     e588:	00000000 */ 	sll	$zero,$zero,0x0
/*     e58c:	10000001 */ 	beqz	$zero,.L0000e594
/*     e590:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e594:
/*     e594:	00435821 */ 	addu	$t3,$v0,$v1
/*     e598:	01646021 */ 	addu	$t4,$t3,$a0
/*     e59c:	01856821 */ 	addu	$t5,$t4,$a1
/*     e5a0:	024d082a */ 	slt	$at,$s2,$t5
/*     e5a4:	1420ffca */ 	bnez	$at,.L0000e4d0
/*     e5a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e5ac:
/*     e5ac:	0fc5a4dd */ 	jal	func0f169374
/*     e5b0:	8fa40074 */ 	lw	$a0,0x74($sp)
/*     e5b4:	afa20074 */ 	sw	$v0,0x74($sp)
/*     e5b8:	0c000d38 */ 	jal	func000034e0
/*     e5bc:	27a40074 */ 	addiu	$a0,$sp,0x74
/*     e5c0:	0fc47b5c */ 	jal	func0f11ed70
/*     e5c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e5c8:	28410002 */ 	slti	$at,$v0,0x2
/*     e5cc:	54200005 */ 	bnezl	$at,.L0000e5e4
/*     e5d0:	8fb90074 */ 	lw	$t9,0x74($sp)
/*     e5d4:	0c0026aa */ 	jal	func00009aa8
/*     e5d8:	8fa40074 */ 	lw	$a0,0x74($sp)
/*     e5dc:	afa20074 */ 	sw	$v0,0x74($sp)
/*     e5e0:	8fb90074 */ 	lw	$t9,0x74($sp)
.L0000e5e4:
/*     e5e4:	3c0ee900 */ 	lui	$t6,0xe900
/*     e5e8:	3c09b800 */ 	lui	$t1,0xb800
/*     e5ec:	27380008 */ 	addiu	$t8,$t9,0x8
/*     e5f0:	afb80074 */ 	sw	$t8,0x74($sp)
/*     e5f4:	af200004 */ 	sw	$zero,0x4($t9)
/*     e5f8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*     e5fc:	8faf0074 */ 	lw	$t7,0x74($sp)
/*     e600:	3c048006 */ 	lui	$a0,0x8006
/*     e604:	25e80008 */ 	addiu	$t0,$t7,0x8
/*     e608:	afa80074 */ 	sw	$t0,0x74($sp)
/*     e60c:	ade00004 */ 	sw	$zero,0x4($t7)
/*     e610:	ade90000 */ 	sw	$t1,0x0($t7)
/*     e614:	8c84d9c8 */ 	lw	$a0,-0x2638($a0)
.L0000e618:
/*     e618:	50800006 */ 	beqzl	$a0,.L0000e634
/*     e61c:	8fa40070 */ 	lw	$a0,0x70($sp)
/*     e620:	0fc59e86 */ 	jal	func0f167a18
/*     e624:	00000000 */ 	sll	$zero,$zero,0x0
/*     e628:	0c002811 */ 	jal	func0000a044
/*     e62c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e630:	8fa40070 */ 	lw	$a0,0x70($sp)
.L0000e634:
/*     e634:	8fa50074 */ 	lw	$a1,0x74($sp)
/*     e638:	00003025 */ 	or	$a2,$zero,$zero
/*     e63c:	0c00be3d */ 	jal	func0002f8f4
/*     e640:	27a70050 */ 	addiu	$a3,$sp,0x50
/*     e644:	3c028006 */ 	lui	$v0,%hi(var8005d9cc)
/*     e648:	2442d9cc */ 	addiu	$v0,$v0,%lo(var8005d9cc)
/*     e64c:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*     e650:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     e654:	0c004aa3 */ 	jal	func00012a8c
/*     e658:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*     e65c:	0fc5b3e5 */ 	jal	func0f16cf94
/*     e660:	00000000 */ 	sll	$zero,$zero,0x0
/*     e664:	0c0026a8 */ 	jal	func00009aa0
/*     e668:	3c040001 */ 	lui	$a0,0x1
/*     e66c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0000e670:
/*     e670:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     e674:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     e678:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     e67c:	03e00008 */ 	jr	$ra
/*     e680:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0000e684
/*     e684:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     e688:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     e68c:	afb10018 */ 	sw	$s1,0x18($sp)
/*     e690:	0c004378 */ 	jal	func00010de0
/*     e694:	afb00014 */ 	sw	$s0,0x14($sp)
/*     e698:	3c0e8006 */ 	lui	$t6,0x8006
/*     e69c:	8dced9d0 */ 	lw	$t6,-0x2630($t6)
/*     e6a0:	55c000a7 */ 	bnezl	$t6,.L0000e940
/*     e6a4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     e6a8:	0fc471b4 */ 	jal	func0f11c6d0
/*     e6ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e6b0:	0c004f75 */ 	jal	func00013dd4
/*     e6b4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e6b8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*     e6bc:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*     e6c0:	8e0f0298 */ 	lw	$t7,0x298($s0)
/*     e6c4:	05e20049 */ 	bltzl	$t7,.L0000e7ec
/*     e6c8:	8e0b029c */ 	lw	$t3,0x29c($s0)
/*     e6cc:	8e19006c */ 	lw	$t9,0x6c($s0)
/*     e6d0:	8e18028c */ 	lw	$t8,0x28c($s0)
/*     e6d4:	00008825 */ 	or	$s1,$zero,$zero
/*     e6d8:	13200003 */ 	beqz	$t9,.L0000e6e8
/*     e6dc:	afb8002c */ 	sw	$t8,0x2c($sp)
/*     e6e0:	10000002 */ 	beqz	$zero,.L0000e6ec
/*     e6e4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e6e8:
/*     e6e8:	00002825 */ 	or	$a1,$zero,$zero
.L0000e6ec:
/*     e6ec:	8e080068 */ 	lw	$t0,0x68($s0)
/*     e6f0:	00002025 */ 	or	$a0,$zero,$zero
/*     e6f4:	00001825 */ 	or	$v1,$zero,$zero
/*     e6f8:	11000003 */ 	beqz	$t0,.L0000e708
/*     e6fc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e700:	10000001 */ 	beqz	$zero,.L0000e708
/*     e704:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e708:
/*     e708:	8e090064 */ 	lw	$t1,0x64($s0)
/*     e70c:	00001025 */ 	or	$v0,$zero,$zero
/*     e710:	11200003 */ 	beqz	$t1,.L0000e720
/*     e714:	00000000 */ 	sll	$zero,$zero,0x0
/*     e718:	10000001 */ 	beqz	$zero,.L0000e720
/*     e71c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e720:
/*     e720:	8e0a0070 */ 	lw	$t2,0x70($s0)
/*     e724:	11400003 */ 	beqz	$t2,.L0000e734
/*     e728:	00000000 */ 	sll	$zero,$zero,0x0
/*     e72c:	10000001 */ 	beqz	$zero,.L0000e734
/*     e730:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e734:
/*     e734:	00435821 */ 	addu	$t3,$v0,$v1
/*     e738:	01646021 */ 	addu	$t4,$t3,$a0
/*     e73c:	01856821 */ 	addu	$t5,$t4,$a1
/*     e740:	19a00023 */ 	blez	$t5,.L0000e7d0
/*     e744:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e748:
/*     e748:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*     e74c:	02202025 */ 	or	$a0,$s1,$zero
/*     e750:	0fc43b2d */ 	jal	func0f10ecb4
/*     e754:	00000000 */ 	sll	$zero,$zero,0x0
/*     e758:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*     e75c:	26310001 */ 	addiu	$s1,$s1,0x1
/*     e760:	00002825 */ 	or	$a1,$zero,$zero
/*     e764:	11c00003 */ 	beqz	$t6,.L0000e774
/*     e768:	00002025 */ 	or	$a0,$zero,$zero
/*     e76c:	10000001 */ 	beqz	$zero,.L0000e774
/*     e770:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e774:
/*     e774:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*     e778:	00001825 */ 	or	$v1,$zero,$zero
/*     e77c:	00001025 */ 	or	$v0,$zero,$zero
/*     e780:	11e00003 */ 	beqz	$t7,.L0000e790
/*     e784:	00000000 */ 	sll	$zero,$zero,0x0
/*     e788:	10000001 */ 	beqz	$zero,.L0000e790
/*     e78c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e790:
/*     e790:	8e180064 */ 	lw	$t8,0x64($s0)
/*     e794:	13000003 */ 	beqz	$t8,.L0000e7a4
/*     e798:	00000000 */ 	sll	$zero,$zero,0x0
/*     e79c:	10000001 */ 	beqz	$zero,.L0000e7a4
/*     e7a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e7a4:
/*     e7a4:	8e190070 */ 	lw	$t9,0x70($s0)
/*     e7a8:	13200003 */ 	beqz	$t9,.L0000e7b8
/*     e7ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7b0:	10000001 */ 	beqz	$zero,.L0000e7b8
/*     e7b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e7b8:
/*     e7b8:	00434021 */ 	addu	$t0,$v0,$v1
/*     e7bc:	01044821 */ 	addu	$t1,$t0,$a0
/*     e7c0:	01255021 */ 	addu	$t2,$t1,$a1
/*     e7c4:	022a082a */ 	slt	$at,$s1,$t2
/*     e7c8:	1420ffdf */ 	bnez	$at,.L0000e748
/*     e7cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e7d0:
/*     e7d0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*     e7d4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*     e7d8:	0fc5b6c5 */ 	jal	func0f16db14
/*     e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7e0:	10000057 */ 	beqz	$zero,.L0000e940
/*     e7e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     e7e8:	8e0b029c */ 	lw	$t3,0x29c($s0)
.L0000e7ec:
/*     e7ec:	05620049 */ 	bltzl	$t3,.L0000e914
/*     e7f0:	8e190318 */ 	lw	$t9,0x318($s0)
/*     e7f4:	8e0d006c */ 	lw	$t5,0x6c($s0)
/*     e7f8:	8e0c028c */ 	lw	$t4,0x28c($s0)
/*     e7fc:	00008825 */ 	or	$s1,$zero,$zero
/*     e800:	11a00003 */ 	beqz	$t5,.L0000e810
/*     e804:	afac0024 */ 	sw	$t4,0x24($sp)
/*     e808:	10000002 */ 	beqz	$zero,.L0000e814
/*     e80c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e810:
/*     e810:	00002825 */ 	or	$a1,$zero,$zero
.L0000e814:
/*     e814:	8e0e0068 */ 	lw	$t6,0x68($s0)
/*     e818:	00002025 */ 	or	$a0,$zero,$zero
/*     e81c:	00001825 */ 	or	$v1,$zero,$zero
/*     e820:	11c00003 */ 	beqz	$t6,.L0000e830
/*     e824:	00000000 */ 	sll	$zero,$zero,0x0
/*     e828:	10000001 */ 	beqz	$zero,.L0000e830
/*     e82c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e830:
/*     e830:	8e0f0064 */ 	lw	$t7,0x64($s0)
/*     e834:	00001025 */ 	or	$v0,$zero,$zero
/*     e838:	11e00003 */ 	beqz	$t7,.L0000e848
/*     e83c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e840:	10000001 */ 	beqz	$zero,.L0000e848
/*     e844:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e848:
/*     e848:	8e180070 */ 	lw	$t8,0x70($s0)
/*     e84c:	13000003 */ 	beqz	$t8,.L0000e85c
/*     e850:	00000000 */ 	sll	$zero,$zero,0x0
/*     e854:	10000001 */ 	beqz	$zero,.L0000e85c
/*     e858:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e85c:
/*     e85c:	0043c821 */ 	addu	$t9,$v0,$v1
/*     e860:	03244021 */ 	addu	$t0,$t9,$a0
/*     e864:	01054821 */ 	addu	$t1,$t0,$a1
/*     e868:	19200023 */ 	blez	$t1,.L0000e8f8
/*     e86c:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e870:
/*     e870:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*     e874:	02202025 */ 	or	$a0,$s1,$zero
/*     e878:	0fc43bc4 */ 	jal	func0f10ef10
/*     e87c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e880:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*     e884:	26310001 */ 	addiu	$s1,$s1,0x1
/*     e888:	00002825 */ 	or	$a1,$zero,$zero
/*     e88c:	11400003 */ 	beqz	$t2,.L0000e89c
/*     e890:	00002025 */ 	or	$a0,$zero,$zero
/*     e894:	10000001 */ 	beqz	$zero,.L0000e89c
/*     e898:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000e89c:
/*     e89c:	8e0b0068 */ 	lw	$t3,0x68($s0)
/*     e8a0:	00001825 */ 	or	$v1,$zero,$zero
/*     e8a4:	00001025 */ 	or	$v0,$zero,$zero
/*     e8a8:	11600003 */ 	beqz	$t3,.L0000e8b8
/*     e8ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e8b0:	10000001 */ 	beqz	$zero,.L0000e8b8
/*     e8b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000e8b8:
/*     e8b8:	8e0c0064 */ 	lw	$t4,0x64($s0)
/*     e8bc:	11800003 */ 	beqz	$t4,.L0000e8cc
/*     e8c0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e8c4:	10000001 */ 	beqz	$zero,.L0000e8cc
/*     e8c8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0000e8cc:
/*     e8cc:	8e0d0070 */ 	lw	$t5,0x70($s0)
/*     e8d0:	11a00003 */ 	beqz	$t5,.L0000e8e0
/*     e8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e8d8:	10000001 */ 	beqz	$zero,.L0000e8e0
/*     e8dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000e8e0:
/*     e8e0:	00437021 */ 	addu	$t6,$v0,$v1
/*     e8e4:	01c47821 */ 	addu	$t7,$t6,$a0
/*     e8e8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*     e8ec:	0238082a */ 	slt	$at,$s1,$t8
/*     e8f0:	1420ffdf */ 	bnez	$at,.L0000e870
/*     e8f4:	00000000 */ 	sll	$zero,$zero,0x0
.L0000e8f8:
/*     e8f8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*     e8fc:	8fa40024 */ 	lw	$a0,0x24($sp)
/*     e900:	0fc5b6c5 */ 	jal	func0f16db14
/*     e904:	00000000 */ 	sll	$zero,$zero,0x0
/*     e908:	1000000d */ 	beqz	$zero,.L0000e940
/*     e90c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     e910:	8e190318 */ 	lw	$t9,0x318($s0)
.L0000e914:
/*     e914:	13200005 */ 	beqz	$t9,.L0000e92c
/*     e918:	00000000 */ 	sll	$zero,$zero,0x0
/*     e91c:	0fc62e79 */ 	jal	func0f18b9e4
/*     e920:	00000000 */ 	sll	$zero,$zero,0x0
/*     e924:	10000006 */ 	beqz	$zero,.L0000e940
/*     e928:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000e92c:
/*     e92c:	0fc43988 */ 	jal	func0f10e620
/*     e930:	00000000 */ 	sll	$zero,$zero,0x0
/*     e934:	0fc5b6c5 */ 	jal	func0f16db14
/*     e938:	00000000 */ 	sll	$zero,$zero,0x0
/*     e93c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0000e940:
/*     e940:	24080001 */ 	addiu	$t0,$zero,0x1
/*     e944:	3c018006 */ 	lui	$at,0x8006
/*     e948:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     e94c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     e950:	ac28d9d0 */ 	sw	$t0,-0x2630($at)
/*     e954:	03e00008 */ 	jr	$ra
/*     e958:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0000e95c
/*     e95c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     e960:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     e964:	0fc471b4 */ 	jal	func0f11c6d0
/*     e968:	afa40018 */ 	sw	$a0,0x18($sp)
/*     e96c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     e970:	8fae0018 */ 	lw	$t6,0x18($sp)
/*     e974:	3c018006 */ 	lui	$at,0x8006
/*     e978:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     e97c:	03e00008 */ 	jr	$ra
/*     e980:	ac2edd54 */ 	sw	$t6,-0x22ac($at)
);

// func0000e984
s32 getCurrentStageId(void)
{
	return g_StageNum;
}

GLOBAL_ASM(
glabel func0000e990
/*     e990:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     e994:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     e998:	0fc25759 */ 	jal	func0f095d64
/*     e99c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9a0:	0fc256fd */ 	jal	func0f095bf4
/*     e9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9a8:	0c0039a1 */ 	jal	func0000e684
/*     e9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     e9b4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     e9b8:	03e00008 */ 	jr	$ra
/*     e9bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000e9c0
/*     e9c0:	03e00008 */ 	jr	$ra
/*     e9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9cc:	00000000 */ 	sll	$zero,$zero,0x0
);
