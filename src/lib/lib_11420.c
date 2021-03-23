#include <ultra64.h>
#include "constants.h"
#include "game/music.h"
#include "game/game_176080.h"
#include "bss.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "lib/lib_38d10.h"
#include "lib/lib_39c80.h"
#include "lib/lib_39f70.h"
#include "data.h"
#include "types.h"

const u32 var70053ca0[] = {0x00000000};
const u32 var70053ca4[] = {0x00050000};

const char var70053ca8[] = "OFF";
const char var70053cac[] = "LEVELTUNE";
const char var70053cb8[] = "NRGTUNE";
const char var70053cc0[] = "WATCHTUNE";
const char var70053ccc[] = "MPDEATHTUNE";
const char var70053cd8[] = "AMBIENCE";
const char var70053ce4[] = " after %d %s\n";
const char var70053cf4[] = "Attempts";
const char var70053d00[] = "Attempt";
const char var70053d08[] = "MUSIC(Play) : Unpaused midi channel %d for state %d\n";
const char var70053d40[] = "MUSIC(Play) : Starting, Guid=%u, Midi=%d, Tune=%d\n";
const char var70053d74[] = "MUSIC(Play) : Done\n";
const char var70053d88[] = "MUSIC(Play) : About to dump the fading channel %d as a same state play request is waiting\n";
const char var70053de4[] = "MUSIC(Play) : About to dump the ambience channel %d\n";
const char var70053e1c[] = "MUSIC(Play) : Reason : A play request is waiting - State = %d\n";
const char var70053e5c[] = "MUSIC(Play) : SERIOUS -> Out of MIDI channels - Attempt = %d\n";
const char var70053e9c[] = "MUSIC(Play) : SERIOUS -> Tried %d times to play tune : Giving up\n";
const char var70053ee0[] = "MUSIC : Fading to pause\n";
const char var70053efc[] = "Music : Update Rate = %d";
const char var70053f18[] = "MUSIC TICK : Queue size = %d\n";
const char var70053f38[] = "MUSIC : Tick -> Channel %d (State=%d) has faded to stop : Dumping\n";
const char var70053f7c[] = "MUSIC : WARNING -> Force fade termination\n";
const char var70053fa8[] = "MUSIC TICK : Job Guid = %u\n";

u32 var8005edf0 = 0xffffffff;
u32 var8005edf4 = 0x00000000;
u32 var8005edf8 = 0x00000000;
u32 var8005edfc = 0x00000000;

GLOBAL_ASM(
glabel func00011420
.late_rodata
glabel var70053fc4
.word func00011420+0x50
glabel var70053fc8
.word func00011420+0x50
glabel var70053fcc
.word func00011420+0x50
glabel var70053fd0
.word func00011420+0x50
glabel var70053fd4
.word func00011420+0x50
glabel var70053fd8
.word func00011420+0x50
.text
/*    11420:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    11424:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    11428:	afb60030 */ 	sw	$s6,0x30($sp)
/*    1142c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    11430:	afb40028 */ 	sw	$s4,0x28($sp)
/*    11434:	afb30024 */ 	sw	$s3,0x24($sp)
/*    11438:	afb20020 */ 	sw	$s2,0x20($sp)
/*    1143c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    11440:	afb00018 */ 	sw	$s0,0x18($sp)
/*    11444:	afa50044 */ 	sw	$a1,0x44($sp)
/*    11448:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    1144c:	0080a825 */ 	or	$s5,$a0,$zero
/*    11450:	2dc10006 */ 	sltiu	$at,$t6,0x6
/*    11454:	10200006 */ 	beqz	$at,.L00011470
/*    11458:	000e7080 */ 	sll	$t6,$t6,0x2
/*    1145c:	3c017005 */ 	lui	$at,%hi(var70053fc4)
/*    11460:	002e0821 */ 	addu	$at,$at,$t6
/*    11464:	8c2e3fc4 */ 	lw	$t6,%lo(var70053fc4)($at)
/*    11468:	01c00008 */ 	jr	$t6
/*    1146c:	00000000 */ 	nop
.L00011470:
/*    11470:	3c12800b */ 	lui	$s2,%hi(var800aaa38)
/*    11474:	3c138009 */ 	lui	$s3,%hi(var80094ed8)
/*    11478:	26734ed8 */ 	addiu	$s3,$s3,%lo(var80094ed8)
/*    1147c:	2652aa38 */ 	addiu	$s2,$s2,%lo(var800aaa38)
/*    11480:	00008025 */ 	or	$s0,$zero,$zero
/*    11484:	24160003 */ 	addiu	$s6,$zero,0x3
/*    11488:	24140108 */ 	addiu	$s4,$zero,0x108
.L0001148c:
/*    1148c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*    11490:	8e580000 */ 	lw	$t8,0x0($s2)
/*    11494:	55f80022 */ 	bnel	$t7,$t8,.L00011520
/*    11498:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1149c:	02140019 */ 	multu	$s0,$s4
/*    114a0:	0000c812 */ 	mflo	$t9
/*    114a4:	02798821 */ 	addu	$s1,$s3,$t9
/*    114a8:	0c00e344 */ 	jal	func00038d10
/*    114ac:	8e2400f8 */ 	lw	$a0,0xf8($s1)
/*    114b0:	24010001 */ 	addiu	$at,$zero,0x1
/*    114b4:	5441001a */ 	bnel	$v0,$at,.L00011520
/*    114b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    114bc:	8ea80000 */ 	lw	$t0,0x0($s5)
/*    114c0:	24010005 */ 	addiu	$at,$zero,0x5
/*    114c4:	24090020 */ 	addiu	$t1,$zero,0x20
/*    114c8:	15010004 */ 	bne	$t0,$at,.L000114dc
/*    114cc:	00008025 */ 	or	$s0,$zero,$zero
/*    114d0:	24070018 */ 	addiu	$a3,$zero,0x18
/*    114d4:	10000002 */ 	b	.L000114e0
/*    114d8:	a3a7003b */ 	sb	$a3,0x3b($sp)
.L000114dc:
/*    114dc:	a3a9003b */ 	sb	$t1,0x3b($sp)
.L000114e0:
/*    114e0:	93a7003b */ 	lbu	$a3,0x3b($sp)
.L000114e4:
/*    114e4:	8e2400f8 */ 	lw	$a0,0xf8($s1)
/*    114e8:	02002825 */ 	or	$a1,$s0,$zero
/*    114ec:	0c00e797 */ 	jal	func00039e5c
/*    114f0:	240600ff */ 	addiu	$a2,$zero,0xff
/*    114f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*    114f8:	24010010 */ 	addiu	$at,$zero,0x10
/*    114fc:	5601fff9 */ 	bnel	$s0,$at,.L000114e4
/*    11500:	93a7003b */ 	lbu	$a3,0x3b($sp)
/*    11504:	ae400008 */ 	sw	$zero,0x8($s2)
/*    11508:	ae40000c */ 	sw	$zero,0xc($s2)
/*    1150c:	a6a00012 */ 	sh	$zero,0x12($s5)
/*    11510:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    11514:	10000004 */ 	b	.L00011528
/*    11518:	afaa0044 */ 	sw	$t2,0x44($sp)
/*    1151c:	26100001 */ 	addiu	$s0,$s0,0x1
.L00011520:
/*    11520:	1616ffda */ 	bne	$s0,$s6,.L0001148c
/*    11524:	26520010 */ 	addiu	$s2,$s2,0x10
.L00011528:
/*    11528:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    1152c:	3c118009 */ 	lui	$s1,%hi(var80094ed8)
/*    11530:	26314ed8 */ 	addiu	$s1,$s1,%lo(var80094ed8)
/*    11534:	15600067 */ 	bnez	$t3,.L000116d4
/*    11538:	00008025 */ 	or	$s0,$zero,$zero
.L0001153c:
/*    1153c:	0c00e344 */ 	jal	func00038d10
/*    11540:	8e2400f8 */ 	lw	$a0,0xf8($s1)
/*    11544:	14400014 */ 	bnez	$v0,.L00011598
/*    11548:	02202025 */ 	or	$a0,$s1,$zero
/*    1154c:	0c003f12 */ 	jal	func0000fc48
/*    11550:	8ea50004 */ 	lw	$a1,0x4($s5)
/*    11554:	10400014 */ 	beqz	$v0,.L000115a8
/*    11558:	02202025 */ 	or	$a0,$s1,$zero
/*    1155c:	96a50010 */ 	lhu	$a1,0x10($s5)
/*    11560:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    11564:	0c003f67 */ 	jal	func0000fd9c
/*    11568:	afac0044 */ 	sw	$t4,0x44($sp)
/*    1156c:	3c0e800b */ 	lui	$t6,%hi(var800aaa38)
/*    11570:	25ceaa38 */ 	addiu	$t6,$t6,%lo(var800aaa38)
/*    11574:	00106900 */ 	sll	$t5,$s0,0x4
/*    11578:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*    1157c:	01ae9021 */ 	addu	$s2,$t5,$t6
/*    11580:	24180001 */ 	addiu	$t8,$zero,0x1
/*    11584:	ae580004 */ 	sw	$t8,0x4($s2)
/*    11588:	ae400008 */ 	sw	$zero,0x8($s2)
/*    1158c:	ae40000c */ 	sw	$zero,0xc($s2)
/*    11590:	10000005 */ 	b	.L000115a8
/*    11594:	ae4f0000 */ 	sw	$t7,0x0($s2)
.L00011598:
/*    11598:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1159c:	2a010003 */ 	slti	$at,$s0,0x3
/*    115a0:	1420ffe6 */ 	bnez	$at,.L0001153c
/*    115a4:	26310108 */ 	addiu	$s1,$s1,0x108
.L000115a8:
/*    115a8:	8fb90044 */ 	lw	$t9,0x44($sp)
/*    115ac:	2411ffff */ 	addiu	$s1,$zero,-1
/*    115b0:	00008025 */ 	or	$s0,$zero,$zero
/*    115b4:	17200047 */ 	bnez	$t9,.L000116d4
/*    115b8:	3c12800b */ 	lui	$s2,%hi(var800aaa38)
/*    115bc:	2652aa38 */ 	addiu	$s2,$s2,%lo(var800aaa38)
.L000115c0:
/*    115c0:	8e420000 */ 	lw	$v0,0x0($s2)
/*    115c4:	10400004 */ 	beqz	$v0,.L000115d8
/*    115c8:	00000000 */ 	nop
/*    115cc:	8ea80000 */ 	lw	$t0,0x0($s5)
/*    115d0:	5502000b */ 	bnel	$t0,$v0,.L00011600
/*    115d4:	26100001 */ 	addiu	$s0,$s0,0x1
.L000115d8:
/*    115d8:	02140019 */ 	multu	$s0,$s4
/*    115dc:	00004812 */ 	mflo	$t1
/*    115e0:	02695021 */ 	addu	$t2,$s3,$t1
/*    115e4:	0c00e344 */ 	jal	func00038d10
/*    115e8:	8d4400f8 */ 	lw	$a0,0xf8($t2)
/*    115ec:	50400004 */ 	beqzl	$v0,.L00011600
/*    115f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*    115f4:	10000005 */ 	b	.L0001160c
/*    115f8:	02008825 */ 	or	$s1,$s0,$zero
/*    115fc:	26100001 */ 	addiu	$s0,$s0,0x1
.L00011600:
/*    11600:	2a010003 */ 	slti	$at,$s0,0x3
/*    11604:	1420ffee */ 	bnez	$at,.L000115c0
/*    11608:	26520010 */ 	addiu	$s2,$s2,0x10
.L0001160c:
/*    1160c:	2401ffff */ 	addiu	$at,$zero,-1
/*    11610:	56210018 */ 	bnel	$s1,$at,.L00011674
/*    11614:	2401ffff */ 	addiu	$at,$zero,-1
/*    11618:	96ab0016 */ 	lhu	$t3,0x16($s5)
/*    1161c:	3c12800b */ 	lui	$s2,%hi(var800aaa38)
/*    11620:	2652aa38 */ 	addiu	$s2,$s2,%lo(var800aaa38)
/*    11624:	29610003 */ 	slti	$at,$t3,0x3
/*    11628:	14200011 */ 	bnez	$at,.L00011670
/*    1162c:	00008025 */ 	or	$s0,$zero,$zero
.L00011630:
/*    11630:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*    11634:	24010005 */ 	addiu	$at,$zero,0x5
/*    11638:	5581000b */ 	bnel	$t4,$at,.L00011668
/*    1163c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    11640:	02140019 */ 	multu	$s0,$s4
/*    11644:	00006812 */ 	mflo	$t5
/*    11648:	026d7021 */ 	addu	$t6,$s3,$t5
/*    1164c:	0c00e344 */ 	jal	func00038d10
/*    11650:	8dc400f8 */ 	lw	$a0,0xf8($t6)
/*    11654:	50400004 */ 	beqzl	$v0,.L00011668
/*    11658:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1165c:	10000004 */ 	b	.L00011670
/*    11660:	02008825 */ 	or	$s1,$s0,$zero
/*    11664:	26100001 */ 	addiu	$s0,$s0,0x1
.L00011668:
/*    11668:	1616fff1 */ 	bne	$s0,$s6,.L00011630
/*    1166c:	26520010 */ 	addiu	$s2,$s2,0x10
.L00011670:
/*    11670:	2401ffff */ 	addiu	$at,$zero,-1
.L00011674:
/*    11674:	52210010 */ 	beql	$s1,$at,.L000116b8
/*    11678:	96a90016 */ 	lhu	$t1,0x16($s5)
/*    1167c:	02340019 */ 	multu	$s1,$s4
/*    11680:	00007812 */ 	mflo	$t7
/*    11684:	026fc021 */ 	addu	$t8,$s3,$t7
/*    11688:	0c00e7dc */ 	jal	func00039f70
/*    1168c:	8f0400f8 */ 	lw	$a0,0xf8($t8)
/*    11690:	3c08800b */ 	lui	$t0,%hi(var800aaa38)
/*    11694:	2508aa38 */ 	addiu	$t0,$t0,%lo(var800aaa38)
/*    11698:	0011c900 */ 	sll	$t9,$s1,0x4
/*    1169c:	03281021 */ 	addu	$v0,$t9,$t0
/*    116a0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    116a4:	ac400004 */ 	sw	$zero,0x4($v0)
/*    116a8:	ac400008 */ 	sw	$zero,0x8($v0)
/*    116ac:	10000009 */ 	b	.L000116d4
/*    116b0:	ac40000c */ 	sw	$zero,0xc($v0)
/*    116b4:	96a90016 */ 	lhu	$t1,0x16($s5)
.L000116b8:
/*    116b8:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    116bc:	314bffff */ 	andi	$t3,$t2,0xffff
/*    116c0:	29610006 */ 	slti	$at,$t3,0x6
/*    116c4:	14200003 */ 	bnez	$at,.L000116d4
/*    116c8:	a6aa0016 */ 	sh	$t2,0x16($s5)
/*    116cc:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    116d0:	afac0044 */ 	sw	$t4,0x44($sp)
.L000116d4:
/*    116d4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    116d8:	8fa20044 */ 	lw	$v0,0x44($sp)
/*    116dc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    116e0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    116e4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    116e8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    116ec:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    116f0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    116f4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    116f8:	03e00008 */ 	jr	$ra
/*    116fc:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func00011700
/*    11700:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    11704:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    11708:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    1170c:	8c850000 */ 	lw	$a1,0x0($a0)
/*    11710:	3c02800b */ 	lui	$v0,%hi(var800aaa38)
/*    11714:	2442aa38 */ 	addiu	$v0,$v0,%lo(var800aaa38)
/*    11718:	24040003 */ 	addiu	$a0,$zero,0x3
/*    1171c:	00001825 */ 	or	$v1,$zero,$zero
.L00011720:
/*    11720:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    11724:	14ae000e */ 	bne	$a1,$t6,.L00011760
/*    11728:	00037940 */ 	sll	$t7,$v1,0x5
/*    1172c:	01e37821 */ 	addu	$t7,$t7,$v1
/*    11730:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    11734:	3c048009 */ 	lui	$a0,%hi(var80094ed8+0xf8)
/*    11738:	008f2021 */ 	addu	$a0,$a0,$t7
/*    1173c:	8c844fd0 */ 	lw	$a0,%lo(var80094ed8+0xf8)($a0)
/*    11740:	0c00e7dc */ 	jal	func00039f70
/*    11744:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    11748:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    1174c:	ac400000 */ 	sw	$zero,0x0($v0)
/*    11750:	ac400004 */ 	sw	$zero,0x4($v0)
/*    11754:	ac400008 */ 	sw	$zero,0x8($v0)
/*    11758:	10000004 */ 	b	.L0001176c
/*    1175c:	ac40000c */ 	sw	$zero,0xc($v0)
.L00011760:
/*    11760:	24630001 */ 	addiu	$v1,$v1,0x1
/*    11764:	1464ffee */ 	bne	$v1,$a0,.L00011720
/*    11768:	24420010 */ 	addiu	$v0,$v0,0x10
.L0001176c:
/*    1176c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    11770:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    11774:	24020001 */ 	addiu	$v0,$zero,0x1
/*    11778:	03e00008 */ 	jr	$ra
/*    1177c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00011780
/*    11780:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    11784:	afb50028 */ 	sw	$s5,0x28($sp)
/*    11788:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1178c:	afb70030 */ 	sw	$s7,0x30($sp)
/*    11790:	afb6002c */ 	sw	$s6,0x2c($sp)
/*    11794:	afb40024 */ 	sw	$s4,0x24($sp)
/*    11798:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    1179c:	3c137005 */ 	lui	$s3,%hi(var70053ca0)
/*    117a0:	3c15800b */ 	lui	$s5,%hi(var800aaa38)
/*    117a4:	00809025 */ 	or	$s2,$a0,$zero
/*    117a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    117ac:	afb10018 */ 	sw	$s1,0x18($sp)
/*    117b0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    117b4:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    117b8:	26b5aa38 */ 	addiu	$s5,$s5,%lo(var800aaa38)
/*    117bc:	26733ca0 */ 	addiu	$s3,$s3,%lo(var70053ca0)
/*    117c0:	24140010 */ 	addiu	$s4,$zero,0x10
/*    117c4:	0000b025 */ 	or	$s6,$zero,$zero
/*    117c8:	24170003 */ 	addiu	$s7,$zero,0x3
.L000117cc:
/*    117cc:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*    117d0:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*    117d4:	55cf001d */ 	bnel	$t6,$t7,.L0001184c
/*    117d8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*    117dc:	8eb80004 */ 	lw	$t8,0x4($s5)
/*    117e0:	0016c940 */ 	sll	$t9,$s6,0x5
/*    117e4:	0336c821 */ 	addu	$t9,$t9,$s6
/*    117e8:	13000017 */ 	beqz	$t8,.L00011848
/*    117ec:	00008025 */ 	or	$s0,$zero,$zero
/*    117f0:	3c088009 */ 	lui	$t0,%hi(var80094ed8)
/*    117f4:	25084ed8 */ 	addiu	$t0,$t0,%lo(var80094ed8)
/*    117f8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    117fc:	03288821 */ 	addu	$s1,$t9,$t0
/*    11800:	8e490000 */ 	lw	$t1,0x0($s2)
.L00011804:
/*    11804:	8e2400f8 */ 	lw	$a0,0xf8($s1)
/*    11808:	02002825 */ 	or	$a1,$s0,$zero
/*    1180c:	02695021 */ 	addu	$t2,$s3,$t1
/*    11810:	91460000 */ 	lbu	$a2,0x0($t2)
/*    11814:	0c00e797 */ 	jal	func00039e5c
/*    11818:	24070020 */ 	addiu	$a3,$zero,0x20
/*    1181c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    11820:	5614fff8 */ 	bnel	$s0,$s4,.L00011804
/*    11824:	8e490000 */ 	lw	$t1,0x0($s2)
/*    11828:	8e4b0008 */ 	lw	$t3,0x8($s2)
/*    1182c:	8e2d00f8 */ 	lw	$t5,0xf8($s1)
/*    11830:	aeab0004 */ 	sw	$t3,0x4($s5)
/*    11834:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*    11838:	aeac0008 */ 	sw	$t4,0x8($s5)
/*    1183c:	8dae0060 */ 	lw	$t6,0x60($t5)
/*    11840:	91cf000d */ 	lbu	$t7,0xd($t6)
/*    11844:	aeaf000c */ 	sw	$t7,0xc($s5)
.L00011848:
/*    11848:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0001184c:
/*    1184c:	16d7ffdf */ 	bne	$s6,$s7,.L000117cc
/*    11850:	26b50010 */ 	addiu	$s5,$s5,0x10
/*    11854:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    11858:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1185c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    11860:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    11864:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    11868:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    1186c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    11870:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*    11874:	8fb70030 */ 	lw	$s7,0x30($sp)
/*    11878:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    1187c:	03e00008 */ 	jr	$ra
/*    11880:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func00011884
/*    11884:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    11888:	afb20020 */ 	sw	$s2,0x20($sp)
/*    1188c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    11890:	afb00018 */ 	sw	$s0,0x18($sp)
/*    11894:	3c10800b */ 	lui	$s0,%hi(var800aaa38)
/*    11898:	3c118009 */ 	lui	$s1,%hi(var80094ed8)
/*    1189c:	3c12800b */ 	lui	$s2,%hi(g_AudioXReasonsActive)
/*    118a0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    118a4:	afa40028 */ 	sw	$a0,0x28($sp)
/*    118a8:	2652aa68 */ 	addiu	$s2,$s2,%lo(g_AudioXReasonsActive)
/*    118ac:	26314ed8 */ 	addiu	$s1,$s1,%lo(var80094ed8)
/*    118b0:	2610aa38 */ 	addiu	$s0,$s0,%lo(var800aaa38)
.L000118b4:
/*    118b4:	0c00e7dc */ 	jal	func00039f70
/*    118b8:	8e2400f8 */ 	lw	$a0,0xf8($s1)
/*    118bc:	26100010 */ 	addiu	$s0,$s0,0x10
/*    118c0:	26310108 */ 	addiu	$s1,$s1,0x108
/*    118c4:	ae00fff0 */ 	sw	$zero,-0x10($s0)
/*    118c8:	ae00fff4 */ 	sw	$zero,-0xc($s0)
/*    118cc:	ae00fff8 */ 	sw	$zero,-0x8($s0)
/*    118d0:	1612fff8 */ 	bne	$s0,$s2,.L000118b4
/*    118d4:	ae00fffc */ 	sw	$zero,-0x4($s0)
/*    118d8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    118dc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    118e0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    118e4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    118e8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    118ec:	03e00008 */ 	jr	$ra
/*    118f0:	24020001 */ 	addiu	$v0,$zero,0x1
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func000118f4
/*    118f4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    118f8:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*    118fc:	3c018008 */ 	lui	$at,%hi(var800840e0)
/*    11900:	24020001 */ 	addiu	$v0,$zero,0x1
/*    11904:	03e00008 */ 	jr	$ra
/*    11908:	ac2e40e0 */ 	sw	$t6,%lo(var800840e0)($at)
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0001190c
.late_rodata
glabel var70053fdc
.word func0001190c+0x324
glabel var70053fe0
.word func0001190c+0x338
glabel var70053fe4
.word func0001190c+0x34c
glabel var70053fe8
.word func0001190c+0x360
glabel var70053fec
.word func0001190c+0x370
.text
/*    1190c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    11910:	3c0e8006 */ 	lui	$t6,%hi(g_Silent)
/*    11914:	8dcedda0 */ 	lw	$t6,%lo(g_Silent)($t6)
/*    11918:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1191c:	afb30020 */ 	sw	$s3,0x20($sp)
/*    11920:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    11924:	afb10018 */ 	sw	$s1,0x18($sp)
/*    11928:	15c0010f */ 	bnez	$t6,.L00011d68
/*    1192c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    11930:	3c138008 */ 	lui	$s3,%hi(var800840c4)
/*    11934:	3c10800b */ 	lui	$s0,%hi(var800aaa38)
/*    11938:	267340c4 */ 	addiu	$s3,$s3,%lo(var800840c4)
/*    1193c:	2610aa38 */ 	addiu	$s0,$s0,%lo(var800aaa38)
/*    11940:	00008825 */ 	or	$s1,$zero,$zero
/*    11944:	24120001 */ 	addiu	$s2,$zero,0x1
.L00011948:
/*    11948:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    1194c:	0011c140 */ 	sll	$t8,$s1,0x5
/*    11950:	0311c021 */ 	addu	$t8,$t8,$s1
/*    11954:	15e00023 */ 	bnez	$t7,.L000119e4
/*    11958:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    1195c:	3c198009 */ 	lui	$t9,%hi(var80094ed8)
/*    11960:	27394ed8 */ 	addiu	$t9,$t9,%lo(var80094ed8)
/*    11964:	03191821 */ 	addu	$v1,$t8,$t9
/*    11968:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    1196c:	0c00e344 */ 	jal	func00038d10
/*    11970:	afa30028 */ 	sw	$v1,0x28($sp)
/*    11974:	1452001b */ 	bne	$v0,$s2,.L000119e4
/*    11978:	8fa30028 */ 	lw	$v1,0x28($sp)
/*    1197c:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11980:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*    11984:	3c0e7005 */ 	lui	$t6,%hi(var70053ca0)
/*    11988:	8c8c0060 */ 	lw	$t4,0x60($a0)
/*    1198c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    11990:	91ce3ca0 */ 	lbu	$t6,%lo(var70053ca0)($t6)
/*    11994:	9182000d */ 	lbu	$v0,0xd($t4)
/*    11998:	01c2082a */ 	slt	$at,$t6,$v0
/*    1199c:	54200009 */ 	bnezl	$at,.L000119c4
/*    119a0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    119a4:	0c00e7dc */ 	jal	func00039f70
/*    119a8:	00000000 */ 	nop
/*    119ac:	ae000000 */ 	sw	$zero,0x0($s0)
/*    119b0:	ae000004 */ 	sw	$zero,0x4($s0)
/*    119b4:	ae000008 */ 	sw	$zero,0x8($s0)
/*    119b8:	1000000a */ 	b	.L000119e4
/*    119bc:	ae00000c */ 	sw	$zero,0xc($s0)
/*    119c0:	8e0f000c */ 	lw	$t7,0xc($s0)
.L000119c4:
/*    119c4:	544f0008 */ 	bnel	$v0,$t7,.L000119e8
/*    119c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*    119cc:	0c00e7dc */ 	jal	func00039f70
/*    119d0:	00000000 */ 	nop
/*    119d4:	ae000000 */ 	sw	$zero,0x0($s0)
/*    119d8:	ae000004 */ 	sw	$zero,0x4($s0)
/*    119dc:	ae000008 */ 	sw	$zero,0x8($s0)
/*    119e0:	ae00000c */ 	sw	$zero,0xc($s0)
.L000119e4:
/*    119e4:	26310001 */ 	addiu	$s1,$s1,0x1
.L000119e8:
/*    119e8:	2a210003 */ 	slti	$at,$s1,0x3
/*    119ec:	1420ffd6 */ 	bnez	$at,.L00011948
/*    119f0:	26100010 */ 	addiu	$s0,$s0,0x10
/*    119f4:	8e650000 */ 	lw	$a1,0x0($s3)
/*    119f8:	3c19800b */ 	lui	$t9,%hi(var800aa5d8)
/*    119fc:	2739a5d8 */ 	addiu	$t9,$t9,%lo(var800aa5d8)
/*    11a00:	24b1ffff */ 	addiu	$s1,$a1,-1
/*    11a04:	06200046 */ 	bltz	$s1,.L00011b20
/*    11a08:	0011c0c0 */ 	sll	$t8,$s1,0x3
/*    11a0c:	0311c023 */ 	subu	$t8,$t8,$s1
/*    11a10:	0018c080 */ 	sll	$t8,$t8,0x2
/*    11a14:	3c0a800b */ 	lui	$t2,%hi(var800aa5d8)
/*    11a18:	254aa5d8 */ 	addiu	$t2,$t2,%lo(var800aa5d8)
/*    11a1c:	03193021 */ 	addu	$a2,$t8,$t9
/*    11a20:	24100002 */ 	addiu	$s0,$zero,0x2
/*    11a24:	24090004 */ 	addiu	$t1,$zero,0x4
/*    11a28:	24080005 */ 	addiu	$t0,$zero,0x5
/*    11a2c:	24070003 */ 	addiu	$a3,$zero,0x3
.L00011a30:
/*    11a30:	94cc0012 */ 	lhu	$t4,0x12($a2)
/*    11a34:	550c0004 */ 	bnel	$t0,$t4,.L00011a48
/*    11a38:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*    11a3c:	10000034 */ 	b	.L00011b10
/*    11a40:	262bffff */ 	addiu	$t3,$s1,-1
/*    11a44:	8ccd0000 */ 	lw	$t5,0x0($a2)
.L00011a48:
/*    11a48:	262bffff */ 	addiu	$t3,$s1,-1
/*    11a4c:	15a00003 */ 	bnez	$t5,.L00011a5c
/*    11a50:	00000000 */ 	nop
/*    11a54:	1000002e */ 	b	.L00011b10
/*    11a58:	262bffff */ 	addiu	$t3,$s1,-1
.L00011a5c:
/*    11a5c:	0560002c */ 	bltz	$t3,.L00011b10
/*    11a60:	01601025 */ 	or	$v0,$t3,$zero
/*    11a64:	000270c0 */ 	sll	$t6,$v0,0x3
/*    11a68:	01c27023 */ 	subu	$t6,$t6,$v0
/*    11a6c:	3c0f800b */ 	lui	$t7,%hi(var800aa5d8)
/*    11a70:	25efa5d8 */ 	addiu	$t7,$t7,%lo(var800aa5d8)
/*    11a74:	000e7080 */ 	sll	$t6,$t6,0x2
/*    11a78:	01cf2821 */ 	addu	$a1,$t6,$t7
/*    11a7c:	94c30012 */ 	lhu	$v1,0x12($a2)
.L00011a80:
/*    11a80:	55230004 */ 	bnel	$t1,$v1,.L00011a94
/*    11a84:	94a40012 */ 	lhu	$a0,0x12($a1)
/*    11a88:	1000001d */ 	b	.L00011b00
/*    11a8c:	aca00000 */ 	sw	$zero,0x0($a1)
/*    11a90:	94a40012 */ 	lhu	$a0,0x12($a1)
.L00011a94:
/*    11a94:	5104001b */ 	beql	$t0,$a0,.L00011b04
/*    11a98:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11a9c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*    11aa0:	50400018 */ 	beqzl	$v0,.L00011b04
/*    11aa4:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11aa8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    11aac:	57020015 */ 	bnel	$t8,$v0,.L00011b04
/*    11ab0:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11ab4:	10720009 */ 	beq	$v1,$s2,.L00011adc
/*    11ab8:	00000000 */ 	nop
/*    11abc:	10700005 */ 	beq	$v1,$s0,.L00011ad4
/*    11ac0:	00000000 */ 	nop
/*    11ac4:	1067000b */ 	beq	$v1,$a3,.L00011af4
/*    11ac8:	00000000 */ 	nop
/*    11acc:	1000000d */ 	b	.L00011b04
/*    11ad0:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011ad4:
/*    11ad4:	1000000a */ 	b	.L00011b00
/*    11ad8:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011adc:
/*    11adc:	10920003 */ 	beq	$a0,$s2,.L00011aec
/*    11ae0:	00000000 */ 	nop
/*    11ae4:	54870007 */ 	bnel	$a0,$a3,.L00011b04
/*    11ae8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011aec:
/*    11aec:	10000004 */ 	b	.L00011b00
/*    11af0:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011af4:
/*    11af4:	54e40003 */ 	bnel	$a3,$a0,.L00011b04
/*    11af8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11afc:	aca00000 */ 	sw	$zero,0x0($a1)
.L00011b00:
/*    11b00:	24a5ffe4 */ 	addiu	$a1,$a1,-28
.L00011b04:
/*    11b04:	00aa082b */ 	sltu	$at,$a1,$t2
/*    11b08:	5020ffdd */ 	beqzl	$at,.L00011a80
/*    11b0c:	94c30012 */ 	lhu	$v1,0x12($a2)
.L00011b10:
/*    11b10:	01608825 */ 	or	$s1,$t3,$zero
/*    11b14:	0561ffc6 */ 	bgez	$t3,.L00011a30
/*    11b18:	24c6ffe4 */ 	addiu	$a2,$a2,-28
/*    11b1c:	8e650000 */ 	lw	$a1,0x0($s3)
.L00011b20:
/*    11b20:	24100002 */ 	addiu	$s0,$zero,0x2
/*    11b24:	00008825 */ 	or	$s1,$zero,$zero
/*    11b28:	18a00020 */ 	blez	$a1,.L00011bac
/*    11b2c:	00001025 */ 	or	$v0,$zero,$zero
/*    11b30:	3c06800b */ 	lui	$a2,%hi(var800aa5d8)
/*    11b34:	3c12800b */ 	lui	$s2,%hi(var800aa5d8)
/*    11b38:	2652a5d8 */ 	addiu	$s2,$s2,%lo(var800aa5d8)
/*    11b3c:	24c6a5d8 */ 	addiu	$a2,$a2,%lo(var800aa5d8)
/*    11b40:	2403001c */ 	addiu	$v1,$zero,0x1c
.L00011b44:
/*    11b44:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    11b48:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11b4c:	53200015 */ 	beqzl	$t9,.L00011ba4
/*    11b50:	0225082a */ 	slt	$at,$s1,$a1
/*    11b54:	00430019 */ 	multu	$v0,$v1
/*    11b58:	8cc10000 */ 	lw	$at,0x0($a2)
/*    11b5c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    11b60:	00006012 */ 	mflo	$t4
/*    11b64:	024c6821 */ 	addu	$t5,$s2,$t4
/*    11b68:	ada10000 */ 	sw	$at,0x0($t5)
/*    11b6c:	8ccf0004 */ 	lw	$t7,0x4($a2)
/*    11b70:	adaf0004 */ 	sw	$t7,0x4($t5)
/*    11b74:	8cc10008 */ 	lw	$at,0x8($a2)
/*    11b78:	ada10008 */ 	sw	$at,0x8($t5)
/*    11b7c:	8ccf000c */ 	lw	$t7,0xc($a2)
/*    11b80:	adaf000c */ 	sw	$t7,0xc($t5)
/*    11b84:	8cc10010 */ 	lw	$at,0x10($a2)
/*    11b88:	ada10010 */ 	sw	$at,0x10($t5)
/*    11b8c:	8ccf0014 */ 	lw	$t7,0x14($a2)
/*    11b90:	adaf0014 */ 	sw	$t7,0x14($t5)
/*    11b94:	8cc10018 */ 	lw	$at,0x18($a2)
/*    11b98:	ada10018 */ 	sw	$at,0x18($t5)
/*    11b9c:	8e650000 */ 	lw	$a1,0x0($s3)
/*    11ba0:	0225082a */ 	slt	$at,$s1,$a1
.L00011ba4:
/*    11ba4:	1420ffe7 */ 	bnez	$at,.L00011b44
/*    11ba8:	24c6001c */ 	addiu	$a2,$a2,0x1c
.L00011bac:
/*    11bac:	ae620000 */ 	sw	$v0,0x0($s3)
/*    11bb0:	3c038008 */ 	lui	$v1,%hi(var800840e0)
/*    11bb4:	8c6340e0 */ 	lw	$v1,%lo(var800840e0)($v1)
/*    11bb8:	3c12800b */ 	lui	$s2,%hi(var800aa5d8)
/*    11bbc:	2652a5d8 */ 	addiu	$s2,$s2,%lo(var800aa5d8)
/*    11bc0:	10600006 */ 	beqz	$v1,.L00011bdc
/*    11bc4:	3c188008 */ 	lui	$t8,%hi(var800840e4)
/*    11bc8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x40)
/*    11bcc:	8f39a000 */ 	lw	$t9,%lo(g_Vars+0x40)($t9)
/*    11bd0:	8f1840e4 */ 	lw	$t8,%lo(var800840e4)($t8)
/*    11bd4:	0319082a */ 	slt	$at,$t8,$t9
/*    11bd8:	10200058 */ 	beqz	$at,.L00011d3c
.L00011bdc:
/*    11bdc:	3c018008 */ 	lui	$at,%hi(var800840e4)
/*    11be0:	ac2340e4 */ 	sw	$v1,%lo(var800840e4)($at)
/*    11be4:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*    11be8:	11800054 */ 	beqz	$t4,.L00011d3c
.L00011bec:
/*    11bec:	3c0e800b */ 	lui	$t6,%hi(var800aa5d8+0x18)
/*    11bf0:	95cea5f0 */ 	lhu	$t6,%lo(var800aa5d8+0x18)($t6)
/*    11bf4:	3c01800b */ 	lui	$at,%hi(var800aa5d8+0x18)
/*    11bf8:	3c0f800b */ 	lui	$t7,%hi(var800aa5d8+0x12)
/*    11bfc:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*    11c00:	a42da5f0 */ 	sh	$t5,%lo(var800aa5d8+0x18)($at)
/*    11c04:	95efa5ea */ 	lhu	$t7,%lo(var800aa5d8+0x12)($t7)
/*    11c08:	00002025 */ 	or	$a0,$zero,$zero
/*    11c0c:	25f8ffff */ 	addiu	$t8,$t7,-1
/*    11c10:	2f010005 */ 	sltiu	$at,$t8,0x5
/*    11c14:	1020001d */ 	beqz	$at,.L00011c8c
/*    11c18:	0018c080 */ 	sll	$t8,$t8,0x2
/*    11c1c:	3c017005 */ 	lui	$at,%hi(var70053fdc)
/*    11c20:	00380821 */ 	addu	$at,$at,$t8
/*    11c24:	8c383fdc */ 	lw	$t8,%lo(var70053fdc)($at)
/*    11c28:	03000008 */ 	jr	$t8
/*    11c2c:	00000000 */ 	nop
/*    11c30:	02402025 */ 	or	$a0,$s2,$zero
/*    11c34:	0c004508 */ 	jal	func00011420
/*    11c38:	00002825 */ 	or	$a1,$zero,$zero
/*    11c3c:	10000013 */ 	b	.L00011c8c
/*    11c40:	00402025 */ 	or	$a0,$v0,$zero
/*    11c44:	02402025 */ 	or	$a0,$s2,$zero
/*    11c48:	0c0045c0 */ 	jal	func00011700
/*    11c4c:	00002825 */ 	or	$a1,$zero,$zero
/*    11c50:	1000000e */ 	b	.L00011c8c
/*    11c54:	00402025 */ 	or	$a0,$v0,$zero
/*    11c58:	02402025 */ 	or	$a0,$s2,$zero
/*    11c5c:	0c0045e0 */ 	jal	func00011780
/*    11c60:	00002825 */ 	or	$a1,$zero,$zero
/*    11c64:	10000009 */ 	b	.L00011c8c
/*    11c68:	00402025 */ 	or	$a0,$v0,$zero
/*    11c6c:	0c004621 */ 	jal	func00011884
/*    11c70:	00002025 */ 	or	$a0,$zero,$zero
/*    11c74:	10000005 */ 	b	.L00011c8c
/*    11c78:	00402025 */ 	or	$a0,$v0,$zero
/*    11c7c:	02402025 */ 	or	$a0,$s2,$zero
/*    11c80:	0c00463d */ 	jal	func000118f4
/*    11c84:	00002825 */ 	or	$a1,$zero,$zero
/*    11c88:	00402025 */ 	or	$a0,$v0,$zero
.L00011c8c:
/*    11c8c:	10800024 */ 	beqz	$a0,.L00011d20
/*    11c90:	3c06800b */ 	lui	$a2,%hi(var800aa5d8)
/*    11c94:	8e790000 */ 	lw	$t9,0x0($s3)
/*    11c98:	24c6a5d8 */ 	addiu	$a2,$a2,%lo(var800aa5d8)
/*    11c9c:	3c0e800b */ 	lui	$t6,%hi(var800aa5d8+0x1c)
/*    11ca0:	272cffff */ 	addiu	$t4,$t9,-1
/*    11ca4:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*    11ca8:	19800019 */ 	blez	$t4,.L00011d10
/*    11cac:	01802825 */ 	or	$a1,$t4,$zero
/*    11cb0:	000c68c0 */ 	sll	$t5,$t4,0x3
/*    11cb4:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    11cb8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    11cbc:	25c2a5f4 */ 	addiu	$v0,$t6,%lo(var800aa5d8+0x1c)
/*    11cc0:	01a21821 */ 	addu	$v1,$t5,$v0
/*    11cc4:	8c410000 */ 	lw	$at,0x0($v0)
.L00011cc8:
/*    11cc8:	2442001c */ 	addiu	$v0,$v0,0x1c
/*    11ccc:	24c6001c */ 	addiu	$a2,$a2,0x1c
/*    11cd0:	acc1ffe4 */ 	sw	$at,-0x1c($a2)
/*    11cd4:	8c58ffe8 */ 	lw	$t8,-0x18($v0)
/*    11cd8:	acd8ffe8 */ 	sw	$t8,-0x18($a2)
/*    11cdc:	8c41ffec */ 	lw	$at,-0x14($v0)
/*    11ce0:	acc1ffec */ 	sw	$at,-0x14($a2)
/*    11ce4:	8c58fff0 */ 	lw	$t8,-0x10($v0)
/*    11ce8:	acd8fff0 */ 	sw	$t8,-0x10($a2)
/*    11cec:	8c41fff4 */ 	lw	$at,-0xc($v0)
/*    11cf0:	acc1fff4 */ 	sw	$at,-0xc($a2)
/*    11cf4:	8c58fff8 */ 	lw	$t8,-0x8($v0)
/*    11cf8:	acd8fff8 */ 	sw	$t8,-0x8($a2)
/*    11cfc:	8c41fffc */ 	lw	$at,-0x4($v0)
/*    11d00:	acc1fffc */ 	sw	$at,-0x4($a2)
/*    11d04:	0043082b */ 	sltu	$at,$v0,$v1
/*    11d08:	5420ffef */ 	bnezl	$at,.L00011cc8
/*    11d0c:	8c410000 */ 	lw	$at,0x0($v0)
.L00011d10:
/*    11d10:	14900006 */ 	bne	$a0,$s0,.L00011d2c
/*    11d14:	3c038008 */ 	lui	$v1,%hi(var800840e0)
/*    11d18:	10000008 */ 	b	.L00011d3c
/*    11d1c:	8c6340e0 */ 	lw	$v1,%lo(var800840e0)($v1)
.L00011d20:
/*    11d20:	3c038008 */ 	lui	$v1,%hi(var800840e0)
/*    11d24:	10000005 */ 	b	.L00011d3c
/*    11d28:	8c6340e0 */ 	lw	$v1,%lo(var800840e0)($v1)
.L00011d2c:
/*    11d2c:	14a0ffaf */ 	bnez	$a1,.L00011bec
/*    11d30:	00000000 */ 	nop
/*    11d34:	3c038008 */ 	lui	$v1,%hi(var800840e0)
/*    11d38:	8c6340e0 */ 	lw	$v1,%lo(var800840e0)($v1)
.L00011d3c:
/*    11d3c:	10600009 */ 	beqz	$v1,.L00011d64
/*    11d40:	3c018008 */ 	lui	$at,%hi(var800840e4)
/*    11d44:	3c198008 */ 	lui	$t9,%hi(var800840e4)
/*    11d48:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x40)
/*    11d4c:	8d8ca000 */ 	lw	$t4,%lo(g_Vars+0x40)($t4)
/*    11d50:	8f3940e4 */ 	lw	$t9,%lo(var800840e4)($t9)
/*    11d54:	3c018008 */ 	lui	$at,%hi(var800840e4)
/*    11d58:	032c6823 */ 	subu	$t5,$t9,$t4
/*    11d5c:	10000002 */ 	b	.L00011d68
/*    11d60:	ac2d40e4 */ 	sw	$t5,%lo(var800840e4)($at)
.L00011d64:
/*    11d64:	ac2040e4 */ 	sw	$zero,%lo(var800840e4)($at)
.L00011d68:
/*    11d68:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    11d6c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    11d70:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    11d74:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    11d78:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    11d7c:	03e00008 */ 	jr	$ra
/*    11d80:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#else
GLOBAL_ASM(
glabel func0001190c
/*    11cb4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    11cb8:	3c0e8006 */ 	lui	$t6,0x8006
/*    11cbc:	8dcef6c0 */ 	lw	$t6,-0x940($t6)
/*    11cc0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    11cc4:	afb60030 */ 	sw	$s6,0x30($sp)
/*    11cc8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    11ccc:	afb40028 */ 	sw	$s4,0x28($sp)
/*    11cd0:	afb30024 */ 	sw	$s3,0x24($sp)
/*    11cd4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    11cd8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    11cdc:	15c00106 */ 	bnez	$t6,.NB000120f8
/*    11ce0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    11ce4:	3c168008 */ 	lui	$s6,0x8008
/*    11ce8:	3c10800b */ 	lui	$s0,0x800b
/*    11cec:	3c157005 */ 	lui	$s5,0x7005
/*    11cf0:	3c138009 */ 	lui	$s3,0x8009
/*    11cf4:	26d66944 */ 	addiu	$s6,$s6,0x6944
/*    11cf8:	26737e58 */ 	addiu	$s3,$s3,0x7e58
/*    11cfc:	26b553b0 */ 	addiu	$s5,$s5,0x53b0
/*    11d00:	2610f2e8 */ 	addiu	$s0,$s0,-3352
/*    11d04:	00008825 */ 	or	$s1,$zero,$zero
/*    11d08:	24140108 */ 	addiu	$s4,$zero,0x108
/*    11d0c:	24120001 */ 	addiu	$s2,$zero,0x1
.NB00011d10:
/*    11d10:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    11d14:	55e00023 */ 	bnezl	$t7,.NB00011da4
/*    11d18:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11d1c:	02340019 */ 	multu	$s1,$s4
/*    11d20:	0000c012 */ 	mflo	$t8
/*    11d24:	02781821 */ 	addu	$v1,$s3,$t8
/*    11d28:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11d2c:	0c00e838 */ 	jal	func00038d10
/*    11d30:	afa30038 */ 	sw	$v1,0x38($sp)
/*    11d34:	1452001a */ 	bne	$v0,$s2,.NB00011da0
/*    11d38:	8fa30038 */ 	lw	$v1,0x38($sp)
/*    11d3c:	8c6400f8 */ 	lw	$a0,0xf8($v1)
/*    11d40:	8e080000 */ 	lw	$t0,0x0($s0)
/*    11d44:	8c990060 */ 	lw	$t9,0x60($a0)
/*    11d48:	02a84821 */ 	addu	$t1,$s5,$t0
/*    11d4c:	912a0000 */ 	lbu	$t2,0x0($t1)
/*    11d50:	9322000d */ 	lbu	$v0,0xd($t9)
/*    11d54:	0142082a */ 	slt	$at,$t2,$v0
/*    11d58:	54200009 */ 	bnezl	$at,.NB00011d80
/*    11d5c:	8e0b000c */ 	lw	$t3,0xc($s0)
/*    11d60:	0c00ecd0 */ 	jal	func00039f70
/*    11d64:	00000000 */ 	sll	$zero,$zero,0x0
/*    11d68:	ae000000 */ 	sw	$zero,0x0($s0)
/*    11d6c:	ae000004 */ 	sw	$zero,0x4($s0)
/*    11d70:	ae000008 */ 	sw	$zero,0x8($s0)
/*    11d74:	1000000a */ 	beqz	$zero,.NB00011da0
/*    11d78:	ae00000c */ 	sw	$zero,0xc($s0)
/*    11d7c:	8e0b000c */ 	lw	$t3,0xc($s0)
.NB00011d80:
/*    11d80:	544b0008 */ 	bnel	$v0,$t3,.NB00011da4
/*    11d84:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11d88:	0c00ecd0 */ 	jal	func00039f70
/*    11d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    11d90:	ae000000 */ 	sw	$zero,0x0($s0)
/*    11d94:	ae000004 */ 	sw	$zero,0x4($s0)
/*    11d98:	ae000008 */ 	sw	$zero,0x8($s0)
/*    11d9c:	ae00000c */ 	sw	$zero,0xc($s0)
.NB00011da0:
/*    11da0:	26310001 */ 	addiu	$s1,$s1,0x1
.NB00011da4:
/*    11da4:	2a210003 */ 	slti	$at,$s1,0x3
/*    11da8:	1420ffd9 */ 	bnez	$at,.NB00011d10
/*    11dac:	26100010 */ 	addiu	$s0,$s0,0x10
/*    11db0:	8ec60000 */ 	lw	$a2,0x0($s6)
/*    11db4:	3c0d800b */ 	lui	$t5,0x800b
/*    11db8:	25adee88 */ 	addiu	$t5,$t5,-4472
/*    11dbc:	24d1ffff */ 	addiu	$s1,$a2,-1
/*    11dc0:	0620003f */ 	bltz	$s1,.NB00011ec0
/*    11dc4:	001160c0 */ 	sll	$t4,$s1,0x3
/*    11dc8:	01916023 */ 	subu	$t4,$t4,$s1
/*    11dcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    11dd0:	3c06800b */ 	lui	$a2,0x800b
/*    11dd4:	24c6ee88 */ 	addiu	$a2,$a2,-4472
/*    11dd8:	018d2821 */ 	addu	$a1,$t4,$t5
/*    11ddc:	24140004 */ 	addiu	$s4,$zero,0x4
/*    11de0:	24130002 */ 	addiu	$s3,$zero,0x2
/*    11de4:	24100003 */ 	addiu	$s0,$zero,0x3
.NB00011de8:
/*    11de8:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    11dec:	2627ffff */ 	addiu	$a3,$s1,-1
/*    11df0:	15c00003 */ 	bnez	$t6,.NB00011e00
/*    11df4:	00000000 */ 	sll	$zero,$zero,0x0
/*    11df8:	1000002d */ 	beqz	$zero,.NB00011eb0
/*    11dfc:	2627ffff */ 	addiu	$a3,$s1,-1
.NB00011e00:
/*    11e00:	04e0002b */ 	bltz	$a3,.NB00011eb0
/*    11e04:	00e01025 */ 	or	$v0,$a3,$zero
/*    11e08:	000278c0 */ 	sll	$t7,$v0,0x3
/*    11e0c:	01e27823 */ 	subu	$t7,$t7,$v0
/*    11e10:	3c18800b */ 	lui	$t8,0x800b
/*    11e14:	2718ee88 */ 	addiu	$t8,$t8,-4472
/*    11e18:	000f7880 */ 	sll	$t7,$t7,0x2
/*    11e1c:	01f82021 */ 	addu	$a0,$t7,$t8
/*    11e20:	94a30012 */ 	lhu	$v1,0x12($a1)
.NB00011e24:
/*    11e24:	56830004 */ 	bnel	$s4,$v1,.NB00011e38
/*    11e28:	8c820000 */ 	lw	$v0,0x0($a0)
/*    11e2c:	1000001c */ 	beqz	$zero,.NB00011ea0
/*    11e30:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e34:	8c820000 */ 	lw	$v0,0x0($a0)
.NB00011e38:
/*    11e38:	5040001a */ 	beqzl	$v0,.NB00011ea4
/*    11e3c:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e40:	8cb90000 */ 	lw	$t9,0x0($a1)
/*    11e44:	57220017 */ 	bnel	$t9,$v0,.NB00011ea4
/*    11e48:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e4c:	5072000a */ 	beql	$v1,$s2,.NB00011e78
/*    11e50:	94820012 */ 	lhu	$v0,0x12($a0)
/*    11e54:	10730005 */ 	beq	$v1,$s3,.NB00011e6c
/*    11e58:	00000000 */ 	sll	$zero,$zero,0x0
/*    11e5c:	5070000d */ 	beql	$v1,$s0,.NB00011e94
/*    11e60:	94880012 */ 	lhu	$t0,0x12($a0)
/*    11e64:	1000000f */ 	beqz	$zero,.NB00011ea4
/*    11e68:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011e6c:
/*    11e6c:	1000000c */ 	beqz	$zero,.NB00011ea0
/*    11e70:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e74:	94820012 */ 	lhu	$v0,0x12($a0)
.NB00011e78:
/*    11e78:	10520003 */ 	beq	$v0,$s2,.NB00011e88
/*    11e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    11e80:	54500008 */ 	bnel	$v0,$s0,.NB00011ea4
/*    11e84:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011e88:
/*    11e88:	10000005 */ 	beqz	$zero,.NB00011ea0
/*    11e8c:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e90:	94880012 */ 	lhu	$t0,0x12($a0)
.NB00011e94:
/*    11e94:	56080003 */ 	bnel	$s0,$t0,.NB00011ea4
/*    11e98:	2484ffe4 */ 	addiu	$a0,$a0,-28
/*    11e9c:	ac800000 */ 	sw	$zero,0x0($a0)
.NB00011ea0:
/*    11ea0:	2484ffe4 */ 	addiu	$a0,$a0,-28
.NB00011ea4:
/*    11ea4:	0086082b */ 	sltu	$at,$a0,$a2
/*    11ea8:	5020ffde */ 	beqzl	$at,.NB00011e24
/*    11eac:	94a30012 */ 	lhu	$v1,0x12($a1)
.NB00011eb0:
/*    11eb0:	00e08825 */ 	or	$s1,$a3,$zero
/*    11eb4:	04e1ffcc */ 	bgez	$a3,.NB00011de8
/*    11eb8:	24a5ffe4 */ 	addiu	$a1,$a1,-28
/*    11ebc:	8ec60000 */ 	lw	$a2,0x0($s6)
.NB00011ec0:
/*    11ec0:	24100003 */ 	addiu	$s0,$zero,0x3
/*    11ec4:	24130002 */ 	addiu	$s3,$zero,0x2
/*    11ec8:	24140004 */ 	addiu	$s4,$zero,0x4
/*    11ecc:	00008825 */ 	or	$s1,$zero,$zero
/*    11ed0:	18c00020 */ 	blez	$a2,.NB00011f54
/*    11ed4:	00001025 */ 	or	$v0,$zero,$zero
/*    11ed8:	3c05800b */ 	lui	$a1,0x800b
/*    11edc:	3c15800b */ 	lui	$s5,0x800b
/*    11ee0:	26b5ee88 */ 	addiu	$s5,$s5,-4472
/*    11ee4:	24a5ee88 */ 	addiu	$a1,$a1,-4472
/*    11ee8:	2403001c */ 	addiu	$v1,$zero,0x1c
.NB00011eec:
/*    11eec:	8ca90000 */ 	lw	$t1,0x0($a1)
/*    11ef0:	26310001 */ 	addiu	$s1,$s1,0x1
/*    11ef4:	51200015 */ 	beqzl	$t1,.NB00011f4c
/*    11ef8:	0226082a */ 	slt	$at,$s1,$a2
/*    11efc:	00430019 */ 	multu	$v0,$v1
/*    11f00:	8ca10000 */ 	lw	$at,0x0($a1)
/*    11f04:	24420001 */ 	addiu	$v0,$v0,0x1
/*    11f08:	00005012 */ 	mflo	$t2
/*    11f0c:	02aa5821 */ 	addu	$t3,$s5,$t2
/*    11f10:	ad610000 */ 	sw	$at,0x0($t3)
/*    11f14:	8cad0004 */ 	lw	$t5,0x4($a1)
/*    11f18:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*    11f1c:	8ca10008 */ 	lw	$at,0x8($a1)
/*    11f20:	ad610008 */ 	sw	$at,0x8($t3)
/*    11f24:	8cad000c */ 	lw	$t5,0xc($a1)
/*    11f28:	ad6d000c */ 	sw	$t5,0xc($t3)
/*    11f2c:	8ca10010 */ 	lw	$at,0x10($a1)
/*    11f30:	ad610010 */ 	sw	$at,0x10($t3)
/*    11f34:	8cad0014 */ 	lw	$t5,0x14($a1)
/*    11f38:	ad6d0014 */ 	sw	$t5,0x14($t3)
/*    11f3c:	8ca10018 */ 	lw	$at,0x18($a1)
/*    11f40:	ad610018 */ 	sw	$at,0x18($t3)
/*    11f44:	8ec60000 */ 	lw	$a2,0x0($s6)
/*    11f48:	0226082a */ 	slt	$at,$s1,$a2
.NB00011f4c:
/*    11f4c:	1420ffe7 */ 	bnez	$at,.NB00011eec
/*    11f50:	24a5001c */ 	addiu	$a1,$a1,0x1c
.NB00011f54:
/*    11f54:	aec20000 */ 	sw	$v0,0x0($s6)
/*    11f58:	3c038008 */ 	lui	$v1,0x8008
/*    11f5c:	8c63695c */ 	lw	$v1,0x695c($v1)
/*    11f60:	3c15800b */ 	lui	$s5,0x800b
/*    11f64:	26b5ee88 */ 	addiu	$s5,$s5,-4472
/*    11f68:	10600006 */ 	beqz	$v1,.NB00011f84
/*    11f6c:	3c0e8008 */ 	lui	$t6,0x8008
/*    11f70:	3c0f800a */ 	lui	$t7,0x800a
/*    11f74:	8defe700 */ 	lw	$t7,-0x1900($t7)
/*    11f78:	8dce6960 */ 	lw	$t6,0x6960($t6)
/*    11f7c:	01cf082a */ 	slt	$at,$t6,$t7
/*    11f80:	10200052 */ 	beqz	$at,.NB000120cc
.NB00011f84:
/*    11f84:	3c018008 */ 	lui	$at,0x8008
/*    11f88:	ac236960 */ 	sw	$v1,0x6960($at)
/*    11f8c:	8ed80000 */ 	lw	$t8,0x0($s6)
/*    11f90:	1300004e */ 	beqz	$t8,.NB000120cc
.NB00011f94:
/*    11f94:	3c19800b */ 	lui	$t9,0x800b
/*    11f98:	9739eea0 */ 	lhu	$t9,-0x1160($t9)
/*    11f9c:	3c01800b */ 	lui	$at,0x800b
/*    11fa0:	3c02800b */ 	lui	$v0,0x800b
/*    11fa4:	27280001 */ 	addiu	$t0,$t9,0x1
/*    11fa8:	a428eea0 */ 	sh	$t0,-0x1160($at)
/*    11fac:	9442ee9a */ 	lhu	$v0,-0x1166($v0)
/*    11fb0:	00002025 */ 	or	$a0,$zero,$zero
/*    11fb4:	00002825 */ 	or	$a1,$zero,$zero
/*    11fb8:	10520009 */ 	beq	$v0,$s2,.NB00011fe0
/*    11fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*    11fc0:	1053000b */ 	beq	$v0,$s3,.NB00011ff0
/*    11fc4:	00002825 */ 	or	$a1,$zero,$zero
/*    11fc8:	1050000d */ 	beq	$v0,$s0,.NB00012000
/*    11fcc:	00002825 */ 	or	$a1,$zero,$zero
/*    11fd0:	1054000f */ 	beq	$v0,$s4,.NB00012010
/*    11fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    11fd8:	10000010 */ 	beqz	$zero,.NB0001201c
/*    11fdc:	00000000 */ 	sll	$zero,$zero,0x0
.NB00011fe0:
/*    11fe0:	0c0045f8 */ 	jal	func00011420
/*    11fe4:	02a02025 */ 	or	$a0,$s5,$zero
/*    11fe8:	1000000c */ 	beqz	$zero,.NB0001201c
/*    11fec:	00402025 */ 	or	$a0,$v0,$zero
.NB00011ff0:
/*    11ff0:	0c0046b0 */ 	jal	func00011700
/*    11ff4:	02a02025 */ 	or	$a0,$s5,$zero
/*    11ff8:	10000008 */ 	beqz	$zero,.NB0001201c
/*    11ffc:	00402025 */ 	or	$a0,$v0,$zero
.NB00012000:
/*    12000:	0c0046d0 */ 	jal	func00011780
/*    12004:	02a02025 */ 	or	$a0,$s5,$zero
/*    12008:	10000004 */ 	beqz	$zero,.NB0001201c
/*    1200c:	00402025 */ 	or	$a0,$v0,$zero
.NB00012010:
/*    12010:	0c004711 */ 	jal	func00011884
/*    12014:	00002025 */ 	or	$a0,$zero,$zero
/*    12018:	00402025 */ 	or	$a0,$v0,$zero
.NB0001201c:
/*    1201c:	10800024 */ 	beqz	$a0,.NB000120b0
/*    12020:	3c05800b */ 	lui	$a1,0x800b
/*    12024:	8ec90000 */ 	lw	$t1,0x0($s6)
/*    12028:	24a5ee88 */ 	addiu	$a1,$a1,-4472
/*    1202c:	3c0c800b */ 	lui	$t4,0x800b
/*    12030:	252affff */ 	addiu	$t2,$t1,-1
/*    12034:	aeca0000 */ 	sw	$t2,0x0($s6)
/*    12038:	19400019 */ 	blez	$t2,.NB000120a0
/*    1203c:	01403025 */ 	or	$a2,$t2,$zero
/*    12040:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    12044:	016a5823 */ 	subu	$t3,$t3,$t2
/*    12048:	000b5880 */ 	sll	$t3,$t3,0x2
/*    1204c:	2582eea4 */ 	addiu	$v0,$t4,-4444
/*    12050:	01621821 */ 	addu	$v1,$t3,$v0
/*    12054:	8c410000 */ 	lw	$at,0x0($v0)
.NB00012058:
/*    12058:	2442001c */ 	addiu	$v0,$v0,0x1c
/*    1205c:	24a5001c */ 	addiu	$a1,$a1,0x1c
/*    12060:	aca1ffe4 */ 	sw	$at,-0x1c($a1)
/*    12064:	8c4effe8 */ 	lw	$t6,-0x18($v0)
/*    12068:	acaeffe8 */ 	sw	$t6,-0x18($a1)
/*    1206c:	8c41ffec */ 	lw	$at,-0x14($v0)
/*    12070:	aca1ffec */ 	sw	$at,-0x14($a1)
/*    12074:	8c4efff0 */ 	lw	$t6,-0x10($v0)
/*    12078:	acaefff0 */ 	sw	$t6,-0x10($a1)
/*    1207c:	8c41fff4 */ 	lw	$at,-0xc($v0)
/*    12080:	aca1fff4 */ 	sw	$at,-0xc($a1)
/*    12084:	8c4efff8 */ 	lw	$t6,-0x8($v0)
/*    12088:	acaefff8 */ 	sw	$t6,-0x8($a1)
/*    1208c:	8c41fffc */ 	lw	$at,-0x4($v0)
/*    12090:	aca1fffc */ 	sw	$at,-0x4($a1)
/*    12094:	0043082b */ 	sltu	$at,$v0,$v1
/*    12098:	5420ffef */ 	bnezl	$at,.NB00012058
/*    1209c:	8c410000 */ 	lw	$at,0x0($v0)
.NB000120a0:
/*    120a0:	14930006 */ 	bne	$a0,$s3,.NB000120bc
/*    120a4:	3c038008 */ 	lui	$v1,0x8008
/*    120a8:	10000008 */ 	beqz	$zero,.NB000120cc
/*    120ac:	8c63695c */ 	lw	$v1,0x695c($v1)
.NB000120b0:
/*    120b0:	3c038008 */ 	lui	$v1,0x8008
/*    120b4:	10000005 */ 	beqz	$zero,.NB000120cc
/*    120b8:	8c63695c */ 	lw	$v1,0x695c($v1)
.NB000120bc:
/*    120bc:	14c0ffb5 */ 	bnez	$a2,.NB00011f94
/*    120c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    120c4:	3c038008 */ 	lui	$v1,0x8008
/*    120c8:	8c63695c */ 	lw	$v1,0x695c($v1)
.NB000120cc:
/*    120cc:	10600009 */ 	beqz	$v1,.NB000120f4
/*    120d0:	3c018008 */ 	lui	$at,0x8008
/*    120d4:	3c0f8008 */ 	lui	$t7,0x8008
/*    120d8:	3c18800a */ 	lui	$t8,0x800a
/*    120dc:	8f18e700 */ 	lw	$t8,-0x1900($t8)
/*    120e0:	8def6960 */ 	lw	$t7,0x6960($t7)
/*    120e4:	3c018008 */ 	lui	$at,0x8008
/*    120e8:	01f8c823 */ 	subu	$t9,$t7,$t8
/*    120ec:	10000002 */ 	beqz	$zero,.NB000120f8
/*    120f0:	ac396960 */ 	sw	$t9,0x6960($at)
.NB000120f4:
/*    120f4:	ac206960 */ 	sw	$zero,0x6960($at)
.NB000120f8:
/*    120f8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    120fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    12100:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    12104:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    12108:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    1210c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    12110:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    12114:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    12118:	03e00008 */ 	jr	$ra
/*    1211c:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func00011d84
/*    11d84:	3c0e8006 */ 	lui	$t6,%hi(g_Silent)
/*    11d88:	8dcedda0 */ 	lw	$t6,%lo(g_Silent)($t6)
/*    11d8c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    11d90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    11d94:	15c000e0 */ 	bnez	$t6,.L00012118
/*    11d98:	afa00020 */ 	sw	$zero,0x20($sp)
/*    11d9c:	3c038008 */ 	lui	$v1,%hi(var800840f0)
/*    11da0:	246340f0 */ 	addiu	$v1,$v1,%lo(var800840f0)
/*    11da4:	8c620000 */ 	lw	$v0,0x0($v1)
/*    11da8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11dac:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11db0:	18400044 */ 	blez	$v0,.L00011ec4
/*    11db4:	00000000 */ 	nop
/*    11db8:	8d4f0318 */ 	lw	$t7,0x318($t2)
/*    11dbc:	3c048008 */ 	lui	$a0,%hi(var800840fc)
/*    11dc0:	55e00014 */ 	bnezl	$t7,.L00011e14
/*    11dc4:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11dc8:	8d58029c */ 	lw	$t8,0x29c($t2)
/*    11dcc:	07020006 */ 	bltzl	$t8,.L00011de8
/*    11dd0:	8d4c0298 */ 	lw	$t4,0x298($t2)
/*    11dd4:	8d5902a0 */ 	lw	$t9,0x2a0($t2)
/*    11dd8:	8f2b00d8 */ 	lw	$t3,0xd8($t9)
/*    11ddc:	5160000d */ 	beqzl	$t3,.L00011e14
/*    11de0:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11de4:	8d4c0298 */ 	lw	$t4,0x298($t2)
.L00011de8:
/*    11de8:	05800036 */ 	bltz	$t4,.L00011ec4
/*    11dec:	00000000 */ 	nop
/*    11df0:	8d4d02a0 */ 	lw	$t5,0x2a0($t2)
/*    11df4:	8dae00d8 */ 	lw	$t6,0xd8($t5)
/*    11df8:	51c00006 */ 	beqzl	$t6,.L00011e14
/*    11dfc:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11e00:	8d4f02a4 */ 	lw	$t7,0x2a4($t2)
/*    11e04:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*    11e08:	1700002e */ 	bnez	$t8,.L00011ec4
/*    11e0c:	00000000 */ 	nop
/*    11e10:	8d590034 */ 	lw	$t9,0x34($t2)
.L00011e14:
/*    11e14:	248440fc */ 	addiu	$a0,$a0,%lo(var800840fc)
/*    11e18:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e1c:	00595823 */ 	subu	$t3,$v0,$t9
/*    11e20:	1d600023 */ 	bgtz	$t3,.L00011eb0
/*    11e24:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    11e28:	0fc5b76c */ 	jal	func0f16ddb0
/*    11e2c:	00000000 */ 	nop
/*    11e30:	3c0d8008 */ 	lui	$t5,%hi(var80087264)
/*    11e34:	8dad7264 */ 	lw	$t5,%lo(var80087264)($t5)
/*    11e38:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x318)
/*    11e3c:	11a0001c */ 	beqz	$t5,.L00011eb0
/*    11e40:	00000000 */ 	nop
/*    11e44:	8dcea2d8 */ 	lw	$t6,%lo(g_Vars+0x318)($t6)
/*    11e48:	3c058008 */ 	lui	$a1,%hi(var800840f4)
/*    11e4c:	24a540f4 */ 	addiu	$a1,$a1,%lo(var800840f4)
/*    11e50:	11c00017 */ 	beqz	$t6,.L00011eb0
/*    11e54:	3c0f8008 */ 	lui	$t7,%hi(var800840f8)
/*    11e58:	8def40f8 */ 	lw	$t7,%lo(var800840f8)($t7)
/*    11e5c:	8cb80000 */ 	lw	$t8,0x0($a1)
/*    11e60:	24040003 */ 	addiu	$a0,$zero,0x3
/*    11e64:	01f8082a */ 	slt	$at,$t7,$t8
/*    11e68:	10200011 */ 	beqz	$at,.L00011eb0
/*    11e6c:	00000000 */ 	nop
/*    11e70:	0fc5b490 */ 	jal	musicEnd
/*    11e74:	aca00000 */ 	sw	$zero,0x0($a1)
/*    11e78:	0fc5b490 */ 	jal	musicEnd
/*    11e7c:	24040004 */ 	addiu	$a0,$zero,0x4
/*    11e80:	0fc5b490 */ 	jal	musicEnd
/*    11e84:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11e88:	3c04800b */ 	lui	$a0,%hi(g_MusicStageNum)
/*    11e8c:	0fc5db10 */ 	jal	stageGetPrimaryTrack
/*    11e90:	8c84a5d0 */ 	lw	$a0,%lo(g_MusicStageNum)($a0)
/*    11e94:	0fc5b3e8 */ 	jal	musicGetVolume
/*    11e98:	afa20018 */ 	sw	$v0,0x18($sp)
/*    11e9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11ea0:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    11ea4:	24060000 */ 	addiu	$a2,$zero,0x0
/*    11ea8:	0fc5b46f */ 	jal	musicStart
/*    11eac:	3047ffff */ 	andi	$a3,$v0,0xffff
.L00011eb0:
/*    11eb0:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11eb4:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11eb8:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11ebc:	1000001d */ 	b	.L00011f34
/*    11ec0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L00011ec4:
/*    11ec4:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11ec8:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11ecc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11ed0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11ed4:	10400017 */ 	beqz	$v0,.L00011f34
/*    11ed8:	00000000 */ 	nop
/*    11edc:	8d590318 */ 	lw	$t9,0x318($t2)
/*    11ee0:	3c0b8008 */ 	lui	$t3,%hi(var800840f8)
/*    11ee4:	3c0c8008 */ 	lui	$t4,%hi(var800840f4)
/*    11ee8:	13200012 */ 	beqz	$t9,.L00011f34
/*    11eec:	00000000 */ 	nop
/*    11ef0:	8d6b40f8 */ 	lw	$t3,%lo(var800840f8)($t3)
/*    11ef4:	8d8c40f4 */ 	lw	$t4,%lo(var800840f4)($t4)
/*    11ef8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11efc:	3c054000 */ 	lui	$a1,0x4000
/*    11f00:	016c082a */ 	slt	$at,$t3,$t4
/*    11f04:	1020000b */ 	beqz	$at,.L00011f34
/*    11f08:	24060001 */ 	addiu	$a2,$zero,0x1
/*    11f0c:	3c018008 */ 	lui	$at,%hi(var800840f4)
/*    11f10:	0fc5b4ab */ 	jal	func0f16d2ac
/*    11f14:	ac2040f4 */ 	sw	$zero,%lo(var800840f4)($at)
/*    11f18:	240d0078 */ 	addiu	$t5,$zero,0x64
/*    11f1c:	3c018008 */ 	lui	$at,%hi(var800840fc)
/*    11f20:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11f24:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11f28:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11f2c:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11f30:	ac2d40fc */ 	sw	$t5,%lo(var800840fc)($at)
.L00011f34:
/*    11f34:	3c048008 */ 	lui	$a0,%hi(var800840fc)
/*    11f38:	3c058008 */ 	lui	$a1,%hi(var800840f4)
/*    11f3c:	24a540f4 */ 	addiu	$a1,$a1,%lo(var800840f4)
/*    11f40:	1040001f */ 	beqz	$v0,.L00011fc0
/*    11f44:	248440fc */ 	addiu	$a0,$a0,%lo(var800840fc)
/*    11f48:	8d4e0318 */ 	lw	$t6,0x318($t2)
/*    11f4c:	11c0001c */ 	beqz	$t6,.L00011fc0
/*    11f50:	00000000 */ 	nop
/*    11f54:	8d420000 */ 	lw	$v0,0x0($t2)
/*    11f58:	8caf0000 */ 	lw	$t7,0x0($a1)
/*    11f5c:	8c830000 */ 	lw	$v1,0x0($a0)
/*    11f60:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    11f64:	18600016 */ 	blez	$v1,.L00011fc0
/*    11f68:	acb80000 */ 	sw	$t8,0x0($a1)
/*    11f6c:	0062c823 */ 	subu	$t9,$v1,$v0
/*    11f70:	1f200013 */ 	bgtz	$t9,.L00011fc0
/*    11f74:	ac990000 */ 	sw	$t9,0x0($a0)
/*    11f78:	0fc5b490 */ 	jal	musicEnd
/*    11f7c:	24040003 */ 	addiu	$a0,$zero,0x3
/*    11f80:	0fc5b490 */ 	jal	musicEnd
/*    11f84:	24040004 */ 	addiu	$a0,$zero,0x4
/*    11f88:	0fc5b490 */ 	jal	musicEnd
/*    11f8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11f90:	3c04800b */ 	lui	$a0,%hi(g_MusicStageNum)
/*    11f94:	0fc5db10 */ 	jal	stageGetPrimaryTrack
/*    11f98:	8c84a5d0 */ 	lw	$a0,%lo(g_MusicStageNum)($a0)
/*    11f9c:	0fc5b3e8 */ 	jal	musicGetVolume
/*    11fa0:	afa20018 */ 	sw	$v0,0x18($sp)
/*    11fa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11fa8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    11fac:	24060000 */ 	addiu	$a2,$zero,0x0
/*    11fb0:	0fc5b46f */ 	jal	musicStart
/*    11fb4:	3047ffff */ 	andi	$a3,$v0,0xffff
/*    11fb8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11fbc:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L00011fc0:
/*    11fc0:	3c06800b */ 	lui	$a2,%hi(g_AudioXReasonsActive)
/*    11fc4:	3c04800b */ 	lui	$a0,%hi(var800aaa78)
/*    11fc8:	3c09800b */ 	lui	$t1,%hi(g_AudioXReasonDurations)
/*    11fcc:	2529aa88 */ 	addiu	$t1,$t1,%lo(g_AudioXReasonDurations)
/*    11fd0:	2484aa78 */ 	addiu	$a0,$a0,%lo(var800aaa78)
/*    11fd4:	24c6aa68 */ 	addiu	$a2,$a2,%lo(g_AudioXReasonsActive)
/*    11fd8:	8d480034 */ 	lw	$t0,0x34($t2)
/*    11fdc:	00003825 */ 	or	$a3,$zero,$zero
.L00011fe0:
/*    11fe0:	8cc50000 */ 	lw	$a1,0x0($a2)
/*    11fe4:	54a00005 */ 	bnezl	$a1,.L00011ffc
/*    11fe8:	8c820000 */ 	lw	$v0,0x0($a0)
/*    11fec:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*    11ff0:	5980001f */ 	blezl	$t4,.L00012070
/*    11ff4:	24840004 */ 	addiu	$a0,$a0,0x0004
/*    11ff8:	8c820000 */ 	lw	$v0,0x0($a0)
.L00011ffc:
/*    11ffc:	3c0d800b */ 	lui	$t5,%hi(g_AudioXReasonDurations)
/*    12000:	25adaa88 */ 	addiu	$t5,$t5,%lo(g_AudioXReasonDurations)
/*    12004:	0048082a */ 	slt	$at,$v0,$t0
/*    12008:	14200004 */ 	bnez	$at,.L0001201c
/*    1200c:	00ed1821 */ 	addu	$v1,$a3,$t5
/*    12010:	00487023 */ 	subu	$t6,$v0,$t0
/*    12014:	10000002 */ 	b	.L00012020
/*    12018:	ac8e0000 */ 	sw	$t6,0x0($a0)
.L0001201c:
/*    1201c:	ac800000 */ 	sw	$zero,0x0($a0)
.L00012020:
/*    12020:	8c620000 */ 	lw	$v0,0x0($v1)
/*    12024:	10400011 */ 	beqz	$v0,.L0001206c
/*    12028:	0048082a */ 	slt	$at,$v0,$t0
/*    1202c:	14200003 */ 	bnez	$at,.L0001203c
/*    12030:	00487823 */ 	subu	$t7,$v0,$t0
/*    12034:	10000002 */ 	b	.L00012040
/*    12038:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0001203c:
/*    1203c:	ac600000 */ 	sw	$zero,0x0($v1)
.L00012040:
/*    12040:	8c780000 */ 	lw	$t8,0x0($v1)
/*    12044:	53000009 */ 	beqzl	$t8,.L0001206c
/*    12048:	acc00000 */ 	sw	$zero,0x0($a2)
/*    1204c:	14a00004 */ 	bnez	$a1,.L00012060
/*    12050:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    12054:	8c990000 */ 	lw	$t9,0x0($a0)
/*    12058:	53200005 */ 	beqzl	$t9,.L00012070
/*    1205c:	24840004 */ 	addiu	$a0,$a0,0x0004
.L00012060:
/*    12060:	10000002 */ 	b	.L0001206c
/*    12064:	afab0020 */ 	sw	$t3,0x20($sp)
/*    12068:	acc00000 */ 	sw	$zero,0x0($a2)
.L0001206c:
/*    1206c:	24840004 */ 	addiu	$a0,$a0,0x4
.L00012070:
/*    12070:	24e70004 */ 	addiu	$a3,$a3,0x4
/*    12074:	1489ffda */ 	bne	$a0,$t1,.L00011fe0
/*    12078:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    1207c:	11000016 */ 	beqz	$t0,.L000120d8
/*    12080:	3c0c8008 */ 	lui	$t4,%hi(var800840d8)
/*    12084:	8d8c40d8 */ 	lw	$t4,%lo(var800840d8)($t4)
/*    12088:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    1208c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    12090:	11800008 */ 	beqz	$t4,.L000120b4
/*    12094:	00000000 */ 	nop
/*    12098:	15a0000f */ 	bnez	$t5,.L000120d8
/*    1209c:	00000000 */ 	nop
/*    120a0:	0fc5b6a9 */ 	jal	func0f16daa4
/*    120a4:	00000000 */ 	nop
/*    120a8:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x34)
/*    120ac:	1000000a */ 	b	.L000120d8
/*    120b0:	8d089ff4 */ 	lw	$t0,%lo(g_Vars+0x34)($t0)
.L000120b4:
/*    120b4:	11c00008 */ 	beqz	$t6,.L000120d8
/*    120b8:	00000000 */ 	nop
/*    120bc:	8d4f04c8 */ 	lw	$t7,0x4c8($t2)
/*    120c0:	15e00005 */ 	bnez	$t7,.L000120d8
/*    120c4:	00000000 */ 	nop
/*    120c8:	0fc5b68b */ 	jal	func0f16da2c
/*    120cc:	00000000 */ 	nop
/*    120d0:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x34)
/*    120d4:	8d089ff4 */ 	lw	$t0,%lo(g_Vars+0x34)($t0)
.L000120d8:
/*    120d8:	3c038006 */ 	lui	$v1,%hi(var8005edf0)
/*    120dc:	2463edf0 */ 	addiu	$v1,$v1,%lo(var8005edf0)
/*    120e0:	8c620000 */ 	lw	$v0,0x0($v1)
/*    120e4:	0048082a */ 	slt	$at,$v0,$t0
/*    120e8:	10200008 */ 	beqz	$at,.L0001210c
/*    120ec:	0048c823 */ 	subu	$t9,$v0,$t0
/*    120f0:	0fc5b84e */ 	jal	func0f16e138
/*    120f4:	00000000 */ 	nop
/*    120f8:	3c038006 */ 	lui	$v1,%hi(var8005edf0)
/*    120fc:	2463edf0 */ 	addiu	$v1,$v1,%lo(var8005edf0)
/*    12100:	2418003c */ 	addiu	$t8,$zero,0x32
/*    12104:	10000002 */ 	b	.L00012110
/*    12108:	ac780000 */ 	sw	$t8,0x0($v1)
.L0001210c:
/*    1210c:	ac790000 */ 	sw	$t9,0x0($v1)
.L00012110:
/*    12110:	0c004643 */ 	jal	func0001190c
/*    12114:	00000000 */ 	nop
.L00012118:
/*    12118:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1211c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    12120:	03e00008 */ 	jr	$ra
/*    12124:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00011d84
/*    11d84:	3c0e8006 */ 	lui	$t6,%hi(g_Silent)
/*    11d88:	8dcedda0 */ 	lw	$t6,%lo(g_Silent)($t6)
/*    11d8c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    11d90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    11d94:	15c000e0 */ 	bnez	$t6,.L00012118
/*    11d98:	afa00020 */ 	sw	$zero,0x20($sp)
/*    11d9c:	3c038008 */ 	lui	$v1,%hi(var800840f0)
/*    11da0:	246340f0 */ 	addiu	$v1,$v1,%lo(var800840f0)
/*    11da4:	8c620000 */ 	lw	$v0,0x0($v1)
/*    11da8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11dac:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11db0:	18400044 */ 	blez	$v0,.L00011ec4
/*    11db4:	00000000 */ 	nop
/*    11db8:	8d4f0318 */ 	lw	$t7,0x318($t2)
/*    11dbc:	3c048008 */ 	lui	$a0,%hi(var800840fc)
/*    11dc0:	55e00014 */ 	bnezl	$t7,.L00011e14
/*    11dc4:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11dc8:	8d58029c */ 	lw	$t8,0x29c($t2)
/*    11dcc:	07020006 */ 	bltzl	$t8,.L00011de8
/*    11dd0:	8d4c0298 */ 	lw	$t4,0x298($t2)
/*    11dd4:	8d5902a0 */ 	lw	$t9,0x2a0($t2)
/*    11dd8:	8f2b00d8 */ 	lw	$t3,0xd8($t9)
/*    11ddc:	5160000d */ 	beqzl	$t3,.L00011e14
/*    11de0:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11de4:	8d4c0298 */ 	lw	$t4,0x298($t2)
.L00011de8:
/*    11de8:	05800036 */ 	bltz	$t4,.L00011ec4
/*    11dec:	00000000 */ 	nop
/*    11df0:	8d4d02a0 */ 	lw	$t5,0x2a0($t2)
/*    11df4:	8dae00d8 */ 	lw	$t6,0xd8($t5)
/*    11df8:	51c00006 */ 	beqzl	$t6,.L00011e14
/*    11dfc:	8d590034 */ 	lw	$t9,0x34($t2)
/*    11e00:	8d4f02a4 */ 	lw	$t7,0x2a4($t2)
/*    11e04:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*    11e08:	1700002e */ 	bnez	$t8,.L00011ec4
/*    11e0c:	00000000 */ 	nop
/*    11e10:	8d590034 */ 	lw	$t9,0x34($t2)
.L00011e14:
/*    11e14:	248440fc */ 	addiu	$a0,$a0,%lo(var800840fc)
/*    11e18:	ac800000 */ 	sw	$zero,0x0($a0)
/*    11e1c:	00595823 */ 	subu	$t3,$v0,$t9
/*    11e20:	1d600023 */ 	bgtz	$t3,.L00011eb0
/*    11e24:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    11e28:	0fc5b76c */ 	jal	func0f16ddb0
/*    11e2c:	00000000 */ 	nop
/*    11e30:	3c0d8008 */ 	lui	$t5,%hi(var80087264)
/*    11e34:	8dad7264 */ 	lw	$t5,%lo(var80087264)($t5)
/*    11e38:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x318)
/*    11e3c:	11a0001c */ 	beqz	$t5,.L00011eb0
/*    11e40:	00000000 */ 	nop
/*    11e44:	8dcea2d8 */ 	lw	$t6,%lo(g_Vars+0x318)($t6)
/*    11e48:	3c058008 */ 	lui	$a1,%hi(var800840f4)
/*    11e4c:	24a540f4 */ 	addiu	$a1,$a1,%lo(var800840f4)
/*    11e50:	11c00017 */ 	beqz	$t6,.L00011eb0
/*    11e54:	3c0f8008 */ 	lui	$t7,%hi(var800840f8)
/*    11e58:	8def40f8 */ 	lw	$t7,%lo(var800840f8)($t7)
/*    11e5c:	8cb80000 */ 	lw	$t8,0x0($a1)
/*    11e60:	24040003 */ 	addiu	$a0,$zero,0x3
/*    11e64:	01f8082a */ 	slt	$at,$t7,$t8
/*    11e68:	10200011 */ 	beqz	$at,.L00011eb0
/*    11e6c:	00000000 */ 	nop
/*    11e70:	0fc5b490 */ 	jal	musicEnd
/*    11e74:	aca00000 */ 	sw	$zero,0x0($a1)
/*    11e78:	0fc5b490 */ 	jal	musicEnd
/*    11e7c:	24040004 */ 	addiu	$a0,$zero,0x4
/*    11e80:	0fc5b490 */ 	jal	musicEnd
/*    11e84:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11e88:	3c04800b */ 	lui	$a0,%hi(g_MusicStageNum)
/*    11e8c:	0fc5db10 */ 	jal	stageGetPrimaryTrack
/*    11e90:	8c84a5d0 */ 	lw	$a0,%lo(g_MusicStageNum)($a0)
/*    11e94:	0fc5b3e8 */ 	jal	musicGetVolume
/*    11e98:	afa20018 */ 	sw	$v0,0x18($sp)
/*    11e9c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11ea0:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    11ea4:	24060000 */ 	addiu	$a2,$zero,0x0
/*    11ea8:	0fc5b46f */ 	jal	musicStart
/*    11eac:	3047ffff */ 	andi	$a3,$v0,0xffff
.L00011eb0:
/*    11eb0:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11eb4:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11eb8:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11ebc:	1000001d */ 	b	.L00011f34
/*    11ec0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L00011ec4:
/*    11ec4:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11ec8:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11ecc:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11ed0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11ed4:	10400017 */ 	beqz	$v0,.L00011f34
/*    11ed8:	00000000 */ 	nop
/*    11edc:	8d590318 */ 	lw	$t9,0x318($t2)
/*    11ee0:	3c0b8008 */ 	lui	$t3,%hi(var800840f8)
/*    11ee4:	3c0c8008 */ 	lui	$t4,%hi(var800840f4)
/*    11ee8:	13200012 */ 	beqz	$t9,.L00011f34
/*    11eec:	00000000 */ 	nop
/*    11ef0:	8d6b40f8 */ 	lw	$t3,%lo(var800840f8)($t3)
/*    11ef4:	8d8c40f4 */ 	lw	$t4,%lo(var800840f4)($t4)
/*    11ef8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11efc:	3c054000 */ 	lui	$a1,0x4000
/*    11f00:	016c082a */ 	slt	$at,$t3,$t4
/*    11f04:	1020000b */ 	beqz	$at,.L00011f34
/*    11f08:	24060001 */ 	addiu	$a2,$zero,0x1
/*    11f0c:	3c018008 */ 	lui	$at,%hi(var800840f4)
/*    11f10:	0fc5b4ab */ 	jal	func0f16d2ac
/*    11f14:	ac2040f4 */ 	sw	$zero,%lo(var800840f4)($at)
/*    11f18:	240d0078 */ 	addiu	$t5,$zero,0x78
/*    11f1c:	3c018008 */ 	lui	$at,%hi(var800840fc)
/*    11f20:	3c028008 */ 	lui	$v0,%hi(var80087264)
/*    11f24:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11f28:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    11f2c:	8c427264 */ 	lw	$v0,%lo(var80087264)($v0)
/*    11f30:	ac2d40fc */ 	sw	$t5,%lo(var800840fc)($at)
.L00011f34:
/*    11f34:	3c048008 */ 	lui	$a0,%hi(var800840fc)
/*    11f38:	3c058008 */ 	lui	$a1,%hi(var800840f4)
/*    11f3c:	24a540f4 */ 	addiu	$a1,$a1,%lo(var800840f4)
/*    11f40:	1040001f */ 	beqz	$v0,.L00011fc0
/*    11f44:	248440fc */ 	addiu	$a0,$a0,%lo(var800840fc)
/*    11f48:	8d4e0318 */ 	lw	$t6,0x318($t2)
/*    11f4c:	11c0001c */ 	beqz	$t6,.L00011fc0
/*    11f50:	00000000 */ 	nop
/*    11f54:	8d420000 */ 	lw	$v0,0x0($t2)
/*    11f58:	8caf0000 */ 	lw	$t7,0x0($a1)
/*    11f5c:	8c830000 */ 	lw	$v1,0x0($a0)
/*    11f60:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    11f64:	18600016 */ 	blez	$v1,.L00011fc0
/*    11f68:	acb80000 */ 	sw	$t8,0x0($a1)
/*    11f6c:	0062c823 */ 	subu	$t9,$v1,$v0
/*    11f70:	1f200013 */ 	bgtz	$t9,.L00011fc0
/*    11f74:	ac990000 */ 	sw	$t9,0x0($a0)
/*    11f78:	0fc5b490 */ 	jal	musicEnd
/*    11f7c:	24040003 */ 	addiu	$a0,$zero,0x3
/*    11f80:	0fc5b490 */ 	jal	musicEnd
/*    11f84:	24040004 */ 	addiu	$a0,$zero,0x4
/*    11f88:	0fc5b490 */ 	jal	musicEnd
/*    11f8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11f90:	3c04800b */ 	lui	$a0,%hi(g_MusicStageNum)
/*    11f94:	0fc5db10 */ 	jal	stageGetPrimaryTrack
/*    11f98:	8c84a5d0 */ 	lw	$a0,%lo(g_MusicStageNum)($a0)
/*    11f9c:	0fc5b3e8 */ 	jal	musicGetVolume
/*    11fa0:	afa20018 */ 	sw	$v0,0x18($sp)
/*    11fa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    11fa8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    11fac:	24060000 */ 	addiu	$a2,$zero,0x0
/*    11fb0:	0fc5b46f */ 	jal	musicStart
/*    11fb4:	3047ffff */ 	andi	$a3,$v0,0xffff
/*    11fb8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    11fbc:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L00011fc0:
/*    11fc0:	3c06800b */ 	lui	$a2,%hi(g_AudioXReasonsActive)
/*    11fc4:	3c04800b */ 	lui	$a0,%hi(var800aaa78)
/*    11fc8:	3c09800b */ 	lui	$t1,%hi(g_AudioXReasonDurations)
/*    11fcc:	2529aa88 */ 	addiu	$t1,$t1,%lo(g_AudioXReasonDurations)
/*    11fd0:	2484aa78 */ 	addiu	$a0,$a0,%lo(var800aaa78)
/*    11fd4:	24c6aa68 */ 	addiu	$a2,$a2,%lo(g_AudioXReasonsActive)
/*    11fd8:	8d480034 */ 	lw	$t0,0x34($t2)
/*    11fdc:	00003825 */ 	or	$a3,$zero,$zero
.L00011fe0:
/*    11fe0:	8cc50000 */ 	lw	$a1,0x0($a2)
/*    11fe4:	54a00005 */ 	bnezl	$a1,.L00011ffc
/*    11fe8:	8c820000 */ 	lw	$v0,0x0($a0)
/*    11fec:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*    11ff0:	5980001f */ 	blezl	$t4,.L00012070
/*    11ff4:	24840004 */ 	addiu	$a0,$a0,0x0004
/*    11ff8:	8c820000 */ 	lw	$v0,0x0($a0)
.L00011ffc:
/*    11ffc:	3c0d800b */ 	lui	$t5,%hi(g_AudioXReasonDurations)
/*    12000:	25adaa88 */ 	addiu	$t5,$t5,%lo(g_AudioXReasonDurations)
/*    12004:	0048082a */ 	slt	$at,$v0,$t0
/*    12008:	14200004 */ 	bnez	$at,.L0001201c
/*    1200c:	00ed1821 */ 	addu	$v1,$a3,$t5
/*    12010:	00487023 */ 	subu	$t6,$v0,$t0
/*    12014:	10000002 */ 	b	.L00012020
/*    12018:	ac8e0000 */ 	sw	$t6,0x0($a0)
.L0001201c:
/*    1201c:	ac800000 */ 	sw	$zero,0x0($a0)
.L00012020:
/*    12020:	8c620000 */ 	lw	$v0,0x0($v1)
/*    12024:	10400011 */ 	beqz	$v0,.L0001206c
/*    12028:	0048082a */ 	slt	$at,$v0,$t0
/*    1202c:	14200003 */ 	bnez	$at,.L0001203c
/*    12030:	00487823 */ 	subu	$t7,$v0,$t0
/*    12034:	10000002 */ 	b	.L00012040
/*    12038:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0001203c:
/*    1203c:	ac600000 */ 	sw	$zero,0x0($v1)
.L00012040:
/*    12040:	8c780000 */ 	lw	$t8,0x0($v1)
/*    12044:	53000009 */ 	beqzl	$t8,.L0001206c
/*    12048:	acc00000 */ 	sw	$zero,0x0($a2)
/*    1204c:	14a00004 */ 	bnez	$a1,.L00012060
/*    12050:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    12054:	8c990000 */ 	lw	$t9,0x0($a0)
/*    12058:	53200005 */ 	beqzl	$t9,.L00012070
/*    1205c:	24840004 */ 	addiu	$a0,$a0,0x0004
.L00012060:
/*    12060:	10000002 */ 	b	.L0001206c
/*    12064:	afab0020 */ 	sw	$t3,0x20($sp)
/*    12068:	acc00000 */ 	sw	$zero,0x0($a2)
.L0001206c:
/*    1206c:	24840004 */ 	addiu	$a0,$a0,0x4
.L00012070:
/*    12070:	24e70004 */ 	addiu	$a3,$a3,0x4
/*    12074:	1489ffda */ 	bne	$a0,$t1,.L00011fe0
/*    12078:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    1207c:	11000016 */ 	beqz	$t0,.L000120d8
/*    12080:	3c0c8008 */ 	lui	$t4,%hi(var800840d8)
/*    12084:	8d8c40d8 */ 	lw	$t4,%lo(var800840d8)($t4)
/*    12088:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    1208c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    12090:	11800008 */ 	beqz	$t4,.L000120b4
/*    12094:	00000000 */ 	nop
/*    12098:	15a0000f */ 	bnez	$t5,.L000120d8
/*    1209c:	00000000 */ 	nop
/*    120a0:	0fc5b6a9 */ 	jal	func0f16daa4
/*    120a4:	00000000 */ 	nop
/*    120a8:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x34)
/*    120ac:	1000000a */ 	b	.L000120d8
/*    120b0:	8d089ff4 */ 	lw	$t0,%lo(g_Vars+0x34)($t0)
.L000120b4:
/*    120b4:	11c00008 */ 	beqz	$t6,.L000120d8
/*    120b8:	00000000 */ 	nop
/*    120bc:	8d4f04c8 */ 	lw	$t7,0x4c8($t2)
/*    120c0:	15e00005 */ 	bnez	$t7,.L000120d8
/*    120c4:	00000000 */ 	nop
/*    120c8:	0fc5b68b */ 	jal	func0f16da2c
/*    120cc:	00000000 */ 	nop
/*    120d0:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x34)
/*    120d4:	8d089ff4 */ 	lw	$t0,%lo(g_Vars+0x34)($t0)
.L000120d8:
/*    120d8:	3c038006 */ 	lui	$v1,%hi(var8005edf0)
/*    120dc:	2463edf0 */ 	addiu	$v1,$v1,%lo(var8005edf0)
/*    120e0:	8c620000 */ 	lw	$v0,0x0($v1)
/*    120e4:	0048082a */ 	slt	$at,$v0,$t0
/*    120e8:	10200008 */ 	beqz	$at,.L0001210c
/*    120ec:	0048c823 */ 	subu	$t9,$v0,$t0
/*    120f0:	0fc5b84e */ 	jal	func0f16e138
/*    120f4:	00000000 */ 	nop
/*    120f8:	3c038006 */ 	lui	$v1,%hi(var8005edf0)
/*    120fc:	2463edf0 */ 	addiu	$v1,$v1,%lo(var8005edf0)
/*    12100:	2418003c */ 	addiu	$t8,$zero,0x3c
/*    12104:	10000002 */ 	b	.L00012110
/*    12108:	ac780000 */ 	sw	$t8,0x0($v1)
.L0001210c:
/*    1210c:	ac790000 */ 	sw	$t9,0x0($v1)
.L00012110:
/*    12110:	0c004643 */ 	jal	func0001190c
/*    12114:	00000000 */ 	nop
.L00012118:
/*    12118:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    1211c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    12120:	03e00008 */ 	jr	$ra
/*    12124:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func00011d84
/*    12120:	3c0e8006 */ 	lui	$t6,0x8006
/*    12124:	8dcef6c0 */ 	lw	$t6,-0x940($t6)
/*    12128:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1212c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12130:	15c000e0 */ 	bnez	$t6,.NB000124b4
/*    12134:	afa00020 */ 	sw	$zero,0x20($sp)
/*    12138:	3c038008 */ 	lui	$v1,0x8008
/*    1213c:	24636968 */ 	addiu	$v1,$v1,0x6968
/*    12140:	8c620000 */ 	lw	$v0,0x0($v1)
/*    12144:	3c0a800a */ 	lui	$t2,0x800a
/*    12148:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*    1214c:	18400044 */ 	blez	$v0,.NB00012260
/*    12150:	00000000 */ 	sll	$zero,$zero,0x0
/*    12154:	8d4f0318 */ 	lw	$t7,0x318($t2)
/*    12158:	3c048008 */ 	lui	$a0,0x8008
/*    1215c:	55e00014 */ 	bnezl	$t7,.NB000121b0
/*    12160:	8d590034 */ 	lw	$t9,0x34($t2)
/*    12164:	8d58029c */ 	lw	$t8,0x29c($t2)
/*    12168:	07020006 */ 	bltzl	$t8,.NB00012184
/*    1216c:	8d4c0298 */ 	lw	$t4,0x298($t2)
/*    12170:	8d5902a0 */ 	lw	$t9,0x2a0($t2)
/*    12174:	8f2b00d8 */ 	lw	$t3,0xd8($t9)
/*    12178:	5160000d */ 	beqzl	$t3,.NB000121b0
/*    1217c:	8d590034 */ 	lw	$t9,0x34($t2)
/*    12180:	8d4c0298 */ 	lw	$t4,0x298($t2)
.NB00012184:
/*    12184:	05800036 */ 	bltz	$t4,.NB00012260
/*    12188:	00000000 */ 	sll	$zero,$zero,0x0
/*    1218c:	8d4d02a0 */ 	lw	$t5,0x2a0($t2)
/*    12190:	8dae00d8 */ 	lw	$t6,0xd8($t5)
/*    12194:	51c00006 */ 	beqzl	$t6,.NB000121b0
/*    12198:	8d590034 */ 	lw	$t9,0x34($t2)
/*    1219c:	8d4f02a4 */ 	lw	$t7,0x2a4($t2)
/*    121a0:	8df800d8 */ 	lw	$t8,0xd8($t7)
/*    121a4:	1700002e */ 	bnez	$t8,.NB00012260
/*    121a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    121ac:	8d590034 */ 	lw	$t9,0x34($t2)
.NB000121b0:
/*    121b0:	24846974 */ 	addiu	$a0,$a0,0x6974
/*    121b4:	ac800000 */ 	sw	$zero,0x0($a0)
/*    121b8:	00595823 */ 	subu	$t3,$v0,$t9
/*    121bc:	1d600023 */ 	bgtz	$t3,.NB0001224c
/*    121c0:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*    121c4:	0fc5a26c */ 	jal	func0f16ddb0
/*    121c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    121cc:	3c0d8009 */ 	lui	$t5,0x8009
/*    121d0:	8dad99e4 */ 	lw	$t5,-0x661c($t5)
/*    121d4:	3c0e800a */ 	lui	$t6,0x800a
/*    121d8:	11a0001c */ 	beqz	$t5,.NB0001224c
/*    121dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    121e0:	8dcee9d8 */ 	lw	$t6,-0x1628($t6)
/*    121e4:	3c058008 */ 	lui	$a1,0x8008
/*    121e8:	24a5696c */ 	addiu	$a1,$a1,0x696c
/*    121ec:	11c00017 */ 	beqz	$t6,.NB0001224c
/*    121f0:	3c0f8008 */ 	lui	$t7,0x8008
/*    121f4:	8def6970 */ 	lw	$t7,0x6970($t7)
/*    121f8:	8cb80000 */ 	lw	$t8,0x0($a1)
/*    121fc:	24040003 */ 	addiu	$a0,$zero,0x3
/*    12200:	01f8082a */ 	slt	$at,$t7,$t8
/*    12204:	10200011 */ 	beqz	$at,.NB0001224c
/*    12208:	00000000 */ 	sll	$zero,$zero,0x0
/*    1220c:	0fc59fed */ 	jal	musicEnd
/*    12210:	aca00000 */ 	sw	$zero,0x0($a1)
/*    12214:	0fc59fed */ 	jal	musicEnd
/*    12218:	24040004 */ 	addiu	$a0,$zero,0x4
/*    1221c:	0fc59fed */ 	jal	musicEnd
/*    12220:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12224:	3c04800b */ 	lui	$a0,0x800b
/*    12228:	0fc5c638 */ 	jal	stageGetPrimaryTrack
/*    1222c:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*    12230:	0fc59f54 */ 	jal	musicGetVolume
/*    12234:	afa20018 */ 	sw	$v0,0x18($sp)
/*    12238:	24040001 */ 	addiu	$a0,$zero,0x1
/*    1223c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12240:	24060000 */ 	addiu	$a2,$zero,0x0
/*    12244:	0fc59fcc */ 	jal	musicStart
/*    12248:	3047ffff */ 	andi	$a3,$v0,0xffff
.NB0001224c:
/*    1224c:	3c0a800a */ 	lui	$t2,0x800a
/*    12250:	3c028009 */ 	lui	$v0,0x8009
/*    12254:	8c4299e4 */ 	lw	$v0,-0x661c($v0)
/*    12258:	1000001d */ 	beqz	$zero,.NB000122d0
/*    1225c:	254ae6c0 */ 	addiu	$t2,$t2,-6464
.NB00012260:
/*    12260:	3c028009 */ 	lui	$v0,0x8009
/*    12264:	8c4299e4 */ 	lw	$v0,-0x661c($v0)
/*    12268:	3c0a800a */ 	lui	$t2,0x800a
/*    1226c:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*    12270:	10400017 */ 	beqz	$v0,.NB000122d0
/*    12274:	00000000 */ 	sll	$zero,$zero,0x0
/*    12278:	8d590318 */ 	lw	$t9,0x318($t2)
/*    1227c:	3c0b8008 */ 	lui	$t3,0x8008
/*    12280:	3c0c8008 */ 	lui	$t4,0x8008
/*    12284:	13200012 */ 	beqz	$t9,.NB000122d0
/*    12288:	00000000 */ 	sll	$zero,$zero,0x0
/*    1228c:	8d6b6970 */ 	lw	$t3,0x6970($t3)
/*    12290:	8d8c696c */ 	lw	$t4,0x696c($t4)
/*    12294:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12298:	3c054000 */ 	lui	$a1,0x4000
/*    1229c:	016c082a */ 	slt	$at,$t3,$t4
/*    122a0:	1020000b */ 	beqz	$at,.NB000122d0
/*    122a4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    122a8:	3c018008 */ 	lui	$at,0x8008
/*    122ac:	0fc5a008 */ 	jal	func0f16d2ac
/*    122b0:	ac20696c */ 	sw	$zero,0x696c($at)
/*    122b4:	240d0078 */ 	addiu	$t5,$zero,0x78
/*    122b8:	3c018008 */ 	lui	$at,0x8008
/*    122bc:	3c028009 */ 	lui	$v0,0x8009
/*    122c0:	3c0a800a */ 	lui	$t2,0x800a
/*    122c4:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*    122c8:	8c4299e4 */ 	lw	$v0,-0x661c($v0)
/*    122cc:	ac2d6974 */ 	sw	$t5,0x6974($at)
.NB000122d0:
/*    122d0:	3c048008 */ 	lui	$a0,0x8008
/*    122d4:	3c058008 */ 	lui	$a1,0x8008
/*    122d8:	24a5696c */ 	addiu	$a1,$a1,0x696c
/*    122dc:	1040001f */ 	beqz	$v0,.NB0001235c
/*    122e0:	24846974 */ 	addiu	$a0,$a0,0x6974
/*    122e4:	8d4e0318 */ 	lw	$t6,0x318($t2)
/*    122e8:	11c0001c */ 	beqz	$t6,.NB0001235c
/*    122ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    122f0:	8d420000 */ 	lw	$v0,0x0($t2)
/*    122f4:	8caf0000 */ 	lw	$t7,0x0($a1)
/*    122f8:	8c830000 */ 	lw	$v1,0x0($a0)
/*    122fc:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    12300:	18600016 */ 	blez	$v1,.NB0001235c
/*    12304:	acb80000 */ 	sw	$t8,0x0($a1)
/*    12308:	0062c823 */ 	subu	$t9,$v1,$v0
/*    1230c:	1f200013 */ 	bgtz	$t9,.NB0001235c
/*    12310:	ac990000 */ 	sw	$t9,0x0($a0)
/*    12314:	0fc59fed */ 	jal	musicEnd
/*    12318:	24040003 */ 	addiu	$a0,$zero,0x3
/*    1231c:	0fc59fed */ 	jal	musicEnd
/*    12320:	24040004 */ 	addiu	$a0,$zero,0x4
/*    12324:	0fc59fed */ 	jal	musicEnd
/*    12328:	24040001 */ 	addiu	$a0,$zero,0x1
/*    1232c:	3c04800b */ 	lui	$a0,0x800b
/*    12330:	0fc5c638 */ 	jal	stageGetPrimaryTrack
/*    12334:	8c84ee80 */ 	lw	$a0,-0x1180($a0)
/*    12338:	0fc59f54 */ 	jal	musicGetVolume
/*    1233c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    12340:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12344:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12348:	24060000 */ 	addiu	$a2,$zero,0x0
/*    1234c:	0fc59fcc */ 	jal	musicStart
/*    12350:	3047ffff */ 	andi	$a3,$v0,0xffff
/*    12354:	3c0a800a */ 	lui	$t2,0x800a
/*    12358:	254ae6c0 */ 	addiu	$t2,$t2,-6464
.NB0001235c:
/*    1235c:	3c06800b */ 	lui	$a2,0x800b
/*    12360:	3c04800b */ 	lui	$a0,0x800b
/*    12364:	3c09800b */ 	lui	$t1,0x800b
/*    12368:	2529f338 */ 	addiu	$t1,$t1,-3272
/*    1236c:	2484f328 */ 	addiu	$a0,$a0,-3288
/*    12370:	24c6f318 */ 	addiu	$a2,$a2,-3304
/*    12374:	8d470034 */ 	lw	$a3,0x34($t2)
/*    12378:	00004025 */ 	or	$t0,$zero,$zero
.NB0001237c:
/*    1237c:	8cc50000 */ 	lw	$a1,0x0($a2)
/*    12380:	54a00005 */ 	bnezl	$a1,.NB00012398
/*    12384:	8c820000 */ 	lw	$v0,0x0($a0)
/*    12388:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*    1238c:	5980001f */ 	blezl	$t4,.NB0001240c
/*    12390:	24840004 */ 	addiu	$a0,$a0,0x4
/*    12394:	8c820000 */ 	lw	$v0,0x0($a0)
.NB00012398:
/*    12398:	3c0d800b */ 	lui	$t5,0x800b
/*    1239c:	25adf338 */ 	addiu	$t5,$t5,-3272
/*    123a0:	0047082a */ 	slt	$at,$v0,$a3
/*    123a4:	14200004 */ 	bnez	$at,.NB000123b8
/*    123a8:	010d1821 */ 	addu	$v1,$t0,$t5
/*    123ac:	00477023 */ 	subu	$t6,$v0,$a3
/*    123b0:	10000002 */ 	beqz	$zero,.NB000123bc
/*    123b4:	ac8e0000 */ 	sw	$t6,0x0($a0)
.NB000123b8:
/*    123b8:	ac800000 */ 	sw	$zero,0x0($a0)
.NB000123bc:
/*    123bc:	8c620000 */ 	lw	$v0,0x0($v1)
/*    123c0:	10400011 */ 	beqz	$v0,.NB00012408
/*    123c4:	0047082a */ 	slt	$at,$v0,$a3
/*    123c8:	14200003 */ 	bnez	$at,.NB000123d8
/*    123cc:	00477823 */ 	subu	$t7,$v0,$a3
/*    123d0:	10000002 */ 	beqz	$zero,.NB000123dc
/*    123d4:	ac6f0000 */ 	sw	$t7,0x0($v1)
.NB000123d8:
/*    123d8:	ac600000 */ 	sw	$zero,0x0($v1)
.NB000123dc:
/*    123dc:	8c780000 */ 	lw	$t8,0x0($v1)
/*    123e0:	53000009 */ 	beqzl	$t8,.NB00012408
/*    123e4:	acc00000 */ 	sw	$zero,0x0($a2)
/*    123e8:	14a00004 */ 	bnez	$a1,.NB000123fc
/*    123ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    123f0:	8c990000 */ 	lw	$t9,0x0($a0)
/*    123f4:	53200005 */ 	beqzl	$t9,.NB0001240c
/*    123f8:	24840004 */ 	addiu	$a0,$a0,0x4
.NB000123fc:
/*    123fc:	10000002 */ 	beqz	$zero,.NB00012408
/*    12400:	afab0020 */ 	sw	$t3,0x20($sp)
/*    12404:	acc00000 */ 	sw	$zero,0x0($a2)
.NB00012408:
/*    12408:	24840004 */ 	addiu	$a0,$a0,0x4
.NB0001240c:
/*    1240c:	25080004 */ 	addiu	$t0,$t0,0x4
/*    12410:	1489ffda */ 	bne	$a0,$t1,.NB0001237c
/*    12414:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    12418:	10e00013 */ 	beqz	$a3,.NB00012468
/*    1241c:	24040002 */ 	addiu	$a0,$zero,0x2
/*    12420:	0fc59f87 */ 	jal	func0f16d0a8
/*    12424:	24050001 */ 	addiu	$a1,$zero,0x1
/*    12428:	10400008 */ 	beqz	$v0,.NB0001244c
/*    1242c:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    12430:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    12434:	1580000c */ 	bnez	$t4,.NB00012468
/*    12438:	00000000 */ 	sll	$zero,$zero,0x0
/*    1243c:	0fc5a1d1 */ 	jal	func0f16daa4
/*    12440:	00000000 */ 	sll	$zero,$zero,0x0
/*    12444:	10000008 */ 	beqz	$zero,.NB00012468
/*    12448:	00000000 */ 	sll	$zero,$zero,0x0
.NB0001244c:
/*    1244c:	11a00006 */ 	beqz	$t5,.NB00012468
/*    12450:	3c0e800a */ 	lui	$t6,0x800a
/*    12454:	8dceeb88 */ 	lw	$t6,-0x1478($t6)
/*    12458:	15c00003 */ 	bnez	$t6,.NB00012468
/*    1245c:	00000000 */ 	sll	$zero,$zero,0x0
/*    12460:	0fc5a1b6 */ 	jal	func0f16da2c
/*    12464:	00000000 */ 	sll	$zero,$zero,0x0
.NB00012468:
/*    12468:	3c038006 */ 	lui	$v1,0x8006
/*    1246c:	3c0a800a */ 	lui	$t2,0x800a
/*    12470:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*    12474:	24630670 */ 	addiu	$v1,$v1,0x670
/*    12478:	8c620000 */ 	lw	$v0,0x0($v1)
/*    1247c:	8d470034 */ 	lw	$a3,0x34($t2)
/*    12480:	0047082a */ 	slt	$at,$v0,$a3
/*    12484:	10200008 */ 	beqz	$at,.NB000124a8
/*    12488:	0047c023 */ 	subu	$t8,$v0,$a3
/*    1248c:	0fc5a33b */ 	jal	func0f16e138
/*    12490:	00000000 */ 	sll	$zero,$zero,0x0
/*    12494:	3c038006 */ 	lui	$v1,0x8006
/*    12498:	24630670 */ 	addiu	$v1,$v1,0x670
/*    1249c:	240f003c */ 	addiu	$t7,$zero,0x3c
/*    124a0:	10000002 */ 	beqz	$zero,.NB000124ac
/*    124a4:	ac6f0000 */ 	sw	$t7,0x0($v1)
.NB000124a8:
/*    124a8:	ac780000 */ 	sw	$t8,0x0($v1)
.NB000124ac:
/*    124ac:	0c00472d */ 	jal	func0001190c
/*    124b0:	00000000 */ 	sll	$zero,$zero,0x0
.NB000124b4:
/*    124b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    124b8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    124bc:	03e00008 */ 	jr	$ra
/*    124c0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

GLOBAL_ASM(
glabel func00012128
/*    12128:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    1212c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    12130:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    12134:	afb60030 */ 	sw	$s6,0x30($sp)
/*    12138:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    1213c:	afb40028 */ 	sw	$s4,0x28($sp)
/*    12140:	afb20020 */ 	sw	$s2,0x20($sp)
/*    12144:	afb00018 */ 	sw	$s0,0x18($sp)
/*    12148:	3c11800b */ 	lui	$s1,%hi(var800aaa38)
/*    1214c:	3c138009 */ 	lui	$s3,%hi(var80094ed8)
/*    12150:	00809025 */ 	or	$s2,$a0,$zero
/*    12154:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    12158:	26734ed8 */ 	addiu	$s3,$s3,%lo(var80094ed8)
/*    1215c:	2631aa38 */ 	addiu	$s1,$s1,%lo(var800aaa38)
/*    12160:	00008025 */ 	or	$s0,$zero,$zero
/*    12164:	24140108 */ 	addiu	$s4,$zero,0x108
/*    12168:	24150001 */ 	addiu	$s5,$zero,0x1
/*    1216c:	24160003 */ 	addiu	$s6,$zero,0x3
.L00012170:
/*    12170:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*    12174:	564e000b */ 	bnel	$s2,$t6,.L000121a4
/*    12178:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1217c:	02140019 */ 	multu	$s0,$s4
/*    12180:	00007812 */ 	mflo	$t7
/*    12184:	026fc021 */ 	addu	$t8,$s3,$t7
/*    12188:	0c00e344 */ 	jal	func00038d10
/*    1218c:	8f0400f8 */ 	lw	$a0,0xf8($t8)
/*    12190:	54550004 */ 	bnel	$v0,$s5,.L000121a4
/*    12194:	26100001 */ 	addiu	$s0,$s0,0x1
/*    12198:	10000005 */ 	b	.L000121b0
/*    1219c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    121a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L000121a4:
/*    121a4:	1616fff2 */ 	bne	$s0,$s6,.L00012170
/*    121a8:	26310010 */ 	addiu	$s1,$s1,0x10
/*    121ac:	00001025 */ 	or	$v0,$zero,$zero
.L000121b0:
/*    121b0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    121b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    121b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    121bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    121c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    121c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    121c8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    121cc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    121d0:	03e00008 */ 	jr	$ra
/*    121d4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012574nb
/*    12574:	308e00ff */ 	andi	$t6,$a0,0xff
/*    12578:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    1257c:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    12580:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12584:	afa40020 */ 	sw	$a0,0x20($sp)
/*    12588:	11e00008 */ 	beqz	$t7,.NB000125ac
/*    1258c:	01c01825 */ 	or	$v1,$t6,$zero
/*    12590:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12594:	0c004931 */ 	jal	func00012128
/*    12598:	afae001c */ 	sw	$t6,0x1c($sp)
/*    1259c:	14400003 */ 	bnez	$v0,.NB000125ac
/*    125a0:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    125a4:	10000026 */ 	beqz	$zero,.NB00012640
/*    125a8:	00001025 */ 	or	$v0,$zero,$zero
.NB000125ac:
/*    125ac:	30780002 */ 	andi	$t8,$v1,0x2
/*    125b0:	13000007 */ 	beqz	$t8,.NB000125d0
/*    125b4:	24040002 */ 	addiu	$a0,$zero,0x2
/*    125b8:	0c004931 */ 	jal	func00012128
/*    125bc:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    125c0:	14400003 */ 	bnez	$v0,.NB000125d0
/*    125c4:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    125c8:	1000001d */ 	beqz	$zero,.NB00012640
/*    125cc:	00001025 */ 	or	$v0,$zero,$zero
.NB000125d0:
/*    125d0:	30790004 */ 	andi	$t9,$v1,0x4
/*    125d4:	13200007 */ 	beqz	$t9,.NB000125f4
/*    125d8:	24040003 */ 	addiu	$a0,$zero,0x3
/*    125dc:	0c004931 */ 	jal	func00012128
/*    125e0:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    125e4:	14400003 */ 	bnez	$v0,.NB000125f4
/*    125e8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    125ec:	10000014 */ 	beqz	$zero,.NB00012640
/*    125f0:	00001025 */ 	or	$v0,$zero,$zero
.NB000125f4:
/*    125f4:	30680008 */ 	andi	$t0,$v1,0x8
/*    125f8:	11000007 */ 	beqz	$t0,.NB00012618
/*    125fc:	24040004 */ 	addiu	$a0,$zero,0x4
/*    12600:	0c004931 */ 	jal	func00012128
/*    12604:	afa3001c */ 	sw	$v1,0x1c($sp)
/*    12608:	14400003 */ 	bnez	$v0,.NB00012618
/*    1260c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    12610:	1000000b */ 	beqz	$zero,.NB00012640
/*    12614:	00001025 */ 	or	$v0,$zero,$zero
.NB00012618:
/*    12618:	30690010 */ 	andi	$t1,$v1,0x10
/*    1261c:	51200008 */ 	beqzl	$t1,.NB00012640
/*    12620:	24020001 */ 	addiu	$v0,$zero,0x1
/*    12624:	0c004931 */ 	jal	func00012128
/*    12628:	24040005 */ 	addiu	$a0,$zero,0x5
/*    1262c:	54400004 */ 	bnezl	$v0,.NB00012640
/*    12630:	24020001 */ 	addiu	$v0,$zero,0x1
/*    12634:	10000002 */ 	beqz	$zero,.NB00012640
/*    12638:	00001025 */ 	or	$v0,$zero,$zero
/*    1263c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB00012640:
/*    12640:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12644:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    12648:	03e00008 */ 	jr	$ra
/*    1264c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
