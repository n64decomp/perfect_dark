#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_01e250.h"
#include "game/game_066310.h"
#include "game/game_129210.h"
#include "gvars/gvars.h"
#include "library/library_126b0.h"
#include "library/library_12dc0.h"
#include "library/library_1a500.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f129210
/*  f129210:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f129214:	3c0e800a */ 	lui	$t6,0x800a
/*  f129218:	8dcea2fc */ 	lw	$t6,-0x5d04($t6)
/*  f12921c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f129220:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f129224:	0080b825 */ 	or	$s7,$a0,$zero
/*  f129228:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f12922c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f129230:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f129234:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f129238:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f12923c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f129240:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f129244:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f129248:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f12924c:	11c00047 */ 	beqz	$t6,.L0f12936c
/*  f129250:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f129254:	24160018 */ 	addiu	$s6,$zero,0x18
/*  f129258:	24150017 */ 	addiu	$s5,$zero,0x17
/*  f12925c:	24140012 */ 	addiu	$s4,$zero,0x12
/*  f129260:	24130008 */ 	addiu	$s3,$zero,0x8
.L0f129264:
/*  f129264:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f129268:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12926c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f129270:	5701003b */ 	bnel	$t8,$at,.L0f129360
/*  f129274:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f129278:	8df10004 */ 	lw	$s1,0x4($t7)
/*  f12927c:	8e320018 */ 	lw	$s2,0x18($s1)
/*  f129280:	8e420008 */ 	lw	$v0,0x8($s2)
/*  f129284:	8c500000 */ 	lw	$s0,0x0($v0)
/*  f129288:	52000035 */ 	beqzl	$s0,.L0f129360
/*  f12928c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f129290:	96020000 */ 	lhu	$v0,0x0($s0)
.L0f129294:
/*  f129294:	02002825 */ 	or	$a1,$s0,$zero
/*  f129298:	305900ff */ 	andi	$t9,$v0,0xff
/*  f12929c:	13330014 */ 	beq	$t9,$s3,.L0f1292f0
/*  f1292a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1292a4:	13340016 */ 	beq	$t9,$s4,.L0f129300
/*  f1292a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1292ac:	13350018 */ 	beq	$t9,$s5,.L0f129310
/*  f1292b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1292b4:	53360004 */ 	beql	$t9,$s6,.L0f1292c8
/*  f1292b8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f1292bc:	10000017 */ 	beqz	$zero,.L0f12931c
/*  f1292c0:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f1292c4:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f1292c8:
/*  f1292c8:	8e480010 */ 	lw	$t0,0x10($s2)
/*  f1292cc:	94490014 */ 	lhu	$t1,0x14($v0)
/*  f1292d0:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1292d4:	010a1821 */ 	addu	$v1,$t0,$t2
/*  f1292d8:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f1292dc:	16eb0002 */ 	bne	$s7,$t3,.L0f1292e8
/*  f1292e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1292e4:	ac7e0000 */ 	sw	$s8,0x0($v1)
.L0f1292e8:
/*  f1292e8:	1000000c */ 	beqz	$zero,.L0f12931c
/*  f1292ec:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f1292f0:
/*  f1292f0:	0c0071e1 */ 	jal	func0001c784
/*  f1292f4:	8e240018 */ 	lw	$a0,0x18($s1)
/*  f1292f8:	10000008 */ 	beqz	$zero,.L0f12931c
/*  f1292fc:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f129300:
/*  f129300:	0c0071f4 */ 	jal	func0001c7d0
/*  f129304:	8e240018 */ 	lw	$a0,0x18($s1)
/*  f129308:	10000004 */ 	beqz	$zero,.L0f12931c
/*  f12930c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f129310:
/*  f129310:	0c007207 */ 	jal	func0001c81c
/*  f129314:	8e240018 */ 	lw	$a0,0x18($s1)
/*  f129318:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f12931c:
/*  f12931c:	10400003 */ 	beqz	$v0,.L0f12932c
/*  f129320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129324:	1000000b */ 	beqz	$zero,.L0f129354
/*  f129328:	00408025 */ 	or	$s0,$v0,$zero
.L0f12932c:
/*  f12932c:	12000009 */ 	beqz	$s0,.L0f129354
/*  f129330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129334:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f129338:
/*  f129338:	50400004 */ 	beqzl	$v0,.L0f12934c
/*  f12933c:	8e100008 */ 	lw	$s0,0x8($s0)
/*  f129340:	10000004 */ 	beqz	$zero,.L0f129354
/*  f129344:	00408025 */ 	or	$s0,$v0,$zero
/*  f129348:	8e100008 */ 	lw	$s0,0x8($s0)
.L0f12934c:
/*  f12934c:	5600fffa */ 	bnezl	$s0,.L0f129338
/*  f129350:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f129354:
/*  f129354:	5600ffcf */ 	bnezl	$s0,.L0f129294
/*  f129358:	96020000 */ 	lhu	$v0,0x0($s0)
/*  f12935c:	8fac0040 */ 	lw	$t4,0x40($sp)
.L0f129360:
/*  f129360:	8d8d0020 */ 	lw	$t5,0x20($t4)
/*  f129364:	15a0ffbf */ 	bnez	$t5,.L0f129264
/*  f129368:	afad0040 */ 	sw	$t5,0x40($sp)
.L0f12936c:
/*  f12936c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f129370:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f129374:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f129378:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f12937c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f129380:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f129384:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f129388:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f12938c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f129390:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f129394:	03e00008 */ 	jr	$ra
/*  f129398:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f12939c
/*  f12939c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1293a0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1293a4:	3c138008 */ 	lui	$s3,%hi(var8007e3d0)
/*  f1293a8:	2673e3d0 */ 	addiu	$s3,$s3,%lo(var8007e3d0)
/*  f1293ac:	8e65005c */ 	lw	$a1,0x5c($s3)
/*  f1293b0:	8e620060 */ 	lw	$v0,0x60($s3)
/*  f1293b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1293b8:	00057083 */ 	sra	$t6,$a1,0x2
/*  f1293bc:	004e082a */ 	slt	$at,$v0,$t6
/*  f1293c0:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1293c4:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1293c8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1293cc:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1293d0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1293d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1293d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1293dc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1293e0:	1020004d */ 	beqz	$at,.L0f129518
/*  f1293e4:	01c02825 */ 	or	$a1,$t6,$zero
/*  f1293e8:	8e630064 */ 	lw	$v1,0x64($s3)
/*  f1293ec:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1293f0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1293f4:	2464ffff */ 	addiu	$a0,$v1,-1
/*  f1293f8:	18800047 */ 	blez	$a0,.L0f129518
/*  f1293fc:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f129400:	8e720058 */ 	lw	$s2,0x58($s3)
.L0f129404:
/*  f129404:	02567821 */ 	addu	$t7,$s2,$s6
/*  f129408:	85f8000e */ 	lh	$t8,0xe($t7)
/*  f12940c:	27c20001 */ 	addiu	$v0,$s8,0x1
/*  f129410:	0043082a */ 	slt	$at,$v0,$v1
/*  f129414:	5b000037 */ 	blezl	$t8,.L0f1294f4
/*  f129418:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f12941c:	10200034 */ 	beqz	$at,.L0f1294f0
/*  f129420:	0040a025 */ 	or	$s4,$v0,$zero
/*  f129424:	00028900 */ 	sll	$s1,$v0,0x4
/*  f129428:	02511021 */ 	addu	$v0,$s2,$s1
.L0f12942c:
/*  f12942c:	8459000e */ 	lh	$t9,0xe($v0)
/*  f129430:	02568021 */ 	addu	$s0,$s2,$s6
/*  f129434:	5b200029 */ 	blezl	$t9,.L0f1294dc
/*  f129438:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12943c:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f129440:	8c490004 */ 	lw	$t1,0x4($v0)
/*  f129444:	55090025 */ 	bnel	$t0,$t1,.L0f1294dc
/*  f129448:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12944c:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f129450:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f129454:	554b0021 */ 	bnel	$t2,$t3,.L0f1294dc
/*  f129458:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12945c:	844c000c */ 	lh	$t4,0xc($v0)
/*  f129460:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f129464:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f129468:	01970019 */ 	multu	$t4,$s7
/*  f12946c:	0000a812 */ 	mflo	$s5
/*  f129470:	26b5000f */ 	addiu	$s5,$s5,0xf
/*  f129474:	36ad000f */ 	ori	$t5,$s5,0xf
/*  f129478:	0fc4a484 */ 	jal	func0f129210
/*  f12947c:	39b5000f */ 	xori	$s5,$t5,0xf
/*  f129480:	8e720058 */ 	lw	$s2,0x58($s3)
/*  f129484:	02a02825 */ 	or	$a1,$s5,$zero
/*  f129488:	02568021 */ 	addu	$s0,$s2,$s6
/*  f12948c:	0251c021 */ 	addu	$t8,$s2,$s1
/*  f129490:	8719000e */ 	lh	$t9,0xe($t8)
/*  f129494:	860f000e */ 	lh	$t7,0xe($s0)
/*  f129498:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f12949c:	a608000e */ 	sh	$t0,0xe($s0)
/*  f1294a0:	8e690058 */ 	lw	$t1,0x58($s3)
/*  f1294a4:	01315021 */ 	addu	$t2,$t1,$s1
/*  f1294a8:	0c004b2d */ 	jal	func00012cb4
/*  f1294ac:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f1294b0:	8e6b0058 */ 	lw	$t3,0x58($s3)
/*  f1294b4:	01716021 */ 	addu	$t4,$t3,$s1
/*  f1294b8:	a580000e */ 	sh	$zero,0xe($t4)
/*  f1294bc:	8e720058 */ 	lw	$s2,0x58($s3)
/*  f1294c0:	8e6d0060 */ 	lw	$t5,0x60($s3)
/*  f1294c4:	8e630064 */ 	lw	$v1,0x64($s3)
/*  f1294c8:	02511021 */ 	addu	$v0,$s2,$s1
/*  f1294cc:	844e000c */ 	lh	$t6,0xc($v0)
/*  f1294d0:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f1294d4:	ae780060 */ 	sw	$t8,0x60($s3)
/*  f1294d8:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f1294dc:
/*  f1294dc:	0283082a */ 	slt	$at,$s4,$v1
/*  f1294e0:	26310010 */ 	addiu	$s1,$s1,0x10
/*  f1294e4:	1420ffd1 */ 	bnez	$at,.L0f12942c
/*  f1294e8:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f1294ec:	2464ffff */ 	addiu	$a0,$v1,-1
.L0f1294f0:
/*  f1294f0:	27de0001 */ 	addiu	$s8,$s8,0x1
.L0f1294f4:
/*  f1294f4:	03c4082a */ 	slt	$at,$s8,$a0
/*  f1294f8:	1420ffc2 */ 	bnez	$at,.L0f129404
/*  f1294fc:	26d60010 */ 	addiu	$s6,$s6,0x10
/*  f129500:	3c058008 */ 	lui	$a1,0x8008
/*  f129504:	8ca5e42c */ 	lw	$a1,-0x1bd4($a1)
/*  f129508:	3c028008 */ 	lui	$v0,0x8008
/*  f12950c:	8c42e430 */ 	lw	$v0,-0x1bd0($v0)
/*  f129510:	00057883 */ 	sra	$t7,$a1,0x2
/*  f129514:	01e02825 */ 	or	$a1,$t7,$zero
.L0f129518:
/*  f129518:	0045082a */ 	slt	$at,$v0,$a1
/*  f12951c:	50200004 */ 	beqzl	$at,.L0f129530
/*  f129520:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f129524:	0fc2440c */ 	jal	func0f091030
/*  f129528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12952c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f129530:
/*  f129530:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f129534:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f129538:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f12953c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f129540:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f129544:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f129548:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f12954c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f129550:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f129554:	03e00008 */ 	jr	$ra
/*  f129558:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f12955c
/*  f12955c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f129560:	3c0e8009 */ 	lui	$t6,0x8009
/*  f129564:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f129568:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f12956c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f129570:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f129574:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f129578:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f12957c:	00809025 */ 	or	$s2,$a0,$zero
/*  f129580:	00c09825 */ 	or	$s3,$a2,$zero
/*  f129584:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f129588:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f12958c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f129590:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f129594:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f129598:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f12959c:	16ae0003 */ 	bne	$s5,$t6,.L0f1295ac
/*  f1295a0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1295a4:	10000090 */ 	beqz	$zero,.L0f1297e8
/*  f1295a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1295ac:
/*  f1295ac:	00057880 */ 	sll	$t7,$a1,0x2
/*  f1295b0:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f1295b4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1295b8:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f1295bc:	3c188008 */ 	lui	$t8,%hi(var8007e3d0)
/*  f1295c0:	2718e3d0 */ 	addiu	$t8,$t8,%lo(var8007e3d0)
/*  f1295c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1295c8:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f1295cc:	8e39002c */ 	lw	$t9,0x2c($s1)
/*  f1295d0:	0332082a */ 	slt	$at,$t9,$s2
/*  f1295d4:	1420002f */ 	bnez	$at,.L0f129694
/*  f1295d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1295dc:	8e220030 */ 	lw	$v0,0x30($s1)
/*  f1295e0:	00122080 */ 	sll	$a0,$s2,0x2
/*  f1295e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1295e8:	1840002a */ 	blez	$v0,.L0f129694
/*  f1295ec:	00922023 */ 	subu	$a0,$a0,$s2
/*  f1295f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1295f4:	8e230024 */ 	lw	$v1,0x24($s1)
.L0f1295f8:
/*  f1295f8:	8468000e */ 	lh	$t0,0xe($v1)
/*  f1295fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f129600:	00a2082a */ 	slt	$at,$a1,$v0
/*  f129604:	15000021 */ 	bnez	$t0,.L0f12968c
/*  f129608:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f12960c:	00042080 */ 	sll	$a0,$a0,0x2
/*  f129610:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f129614:	3489000f */ 	ori	$t1,$a0,0xf
/*  f129618:	0c004aac */ 	jal	func00012ab0
/*  f12961c:	3924000f */ 	xori	$a0,$t1,0xf
/*  f129620:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f129624:	01706021 */ 	addu	$t4,$t3,$s0
/*  f129628:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f12962c:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f129630:	01b01821 */ 	addu	$v1,$t5,$s0
/*  f129634:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f129638:	11c00012 */ 	beqz	$t6,.L0f129684
/*  f12963c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129640:	a472000c */ 	sh	$s2,0xc($v1)
/*  f129644:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f129648:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f12964c:	a715000e */ 	sh	$s5,0xe($t8)
/*  f129650:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f129654:	03304021 */ 	addu	$t0,$t9,$s0
/*  f129658:	ad130004 */ 	sw	$s3,0x4($t0)
/*  f12965c:	8e290024 */ 	lw	$t1,0x24($s1)
/*  f129660:	01305021 */ 	addu	$t2,$t1,$s0
/*  f129664:	ad540008 */ 	sw	$s4,0x8($t2)
/*  f129668:	8e2b002c */ 	lw	$t3,0x2c($s1)
/*  f12966c:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f129670:	01726023 */ 	subu	$t4,$t3,$s2
/*  f129674:	ae2c002c */ 	sw	$t4,0x2c($s1)
/*  f129678:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f12967c:	1000005a */ 	beqz	$zero,.L0f1297e8
/*  f129680:	8dc20000 */ 	lw	$v0,0x0($t6)
.L0f129684:
/*  f129684:	10000058 */ 	beqz	$zero,.L0f1297e8
/*  f129688:	00001025 */ 	or	$v0,$zero,$zero
.L0f12968c:
/*  f12968c:	1420ffda */ 	bnez	$at,.L0f1295f8
/*  f129690:	26100010 */ 	addiu	$s0,$s0,0x10
.L0f129694:
/*  f129694:	0fc07934 */ 	jal	getNumChrs
/*  f129698:	00002825 */ 	or	$a1,$zero,$zero
/*  f12969c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1296a0:	18400039 */ 	blez	$v0,.L0f129788
/*  f1296a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1296a8:	0002b0c0 */ 	sll	$s6,$v0,0x3
/*  f1296ac:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f1296b0:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f1296b4:	02c2b023 */ 	subu	$s6,$s6,$v0
/*  f1296b8:	0016b080 */ 	sll	$s6,$s6,0x2
/*  f1296bc:	02c2b021 */ 	addu	$s6,$s6,$v0
/*  f1296c0:	3c178006 */ 	lui	$s7,%hi(g_ChrsA)
/*  f1296c4:	26f72988 */ 	addiu	$s7,$s7,%lo(g_ChrsA)
/*  f1296c8:	0016b0c0 */ 	sll	$s6,$s6,0x3
/*  f1296cc:	00009825 */ 	or	$s3,$zero,$zero
/*  f1296d0:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f1296d4:	27b40054 */ 	addiu	$s4,$sp,0x54
/*  f1296d8:	8eef0000 */ 	lw	$t7,0x0($s7)
.L0f1296dc:
/*  f1296dc:	026f8021 */ 	addu	$s0,$s3,$t7
/*  f1296e0:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f1296e4:	53000025 */ 	beqzl	$t8,.L0f12977c
/*  f1296e8:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f1296ec:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f1296f0:	50400022 */ 	beqzl	$v0,.L0f12977c
/*  f1296f4:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f1296f8:	90590001 */ 	lbu	$t9,0x1($v0)
/*  f1296fc:	33280080 */ 	andi	$t0,$t9,0x80
/*  f129700:	5500001e */ 	bnezl	$t0,.L0f12977c
/*  f129704:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129708:	82090007 */ 	lb	$t1,0x7($s0)
/*  f12970c:	57c9001b */ 	bnel	$s8,$t1,.L0f12977c
/*  f129710:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129714:	8e0a0030 */ 	lw	$t2,0x30($s0)
/*  f129718:	2a410006 */ 	slti	$at,$s2,0x6
/*  f12971c:	55400017 */ 	bnezl	$t2,.L0f12977c
/*  f129720:	26730368 */ 	addiu	$s3,$s3,0x368
/*  f129724:	10200005 */ 	beqz	$at,.L0f12973c
/*  f129728:	00125880 */ 	sll	$t3,$s2,0x2
/*  f12972c:	028b6021 */ 	addu	$t4,$s4,$t3
/*  f129730:	ad900000 */ 	sw	$s0,0x0($t4)
/*  f129734:	10000010 */ 	beqz	$zero,.L0f129778
/*  f129738:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f12973c:
/*  f12973c:	0c004b70 */ 	jal	random
/*  f129740:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129744:	0052001b */ 	divu	$zero,$v0,$s2
/*  f129748:	00001810 */ 	mfhi	$v1
/*  f12974c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f129750:	16400002 */ 	bnez	$s2,.L0f12975c
/*  f129754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f129758:	0007000d */ 	break	0x7
.L0f12975c:
/*  f12975c:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f129760:	00608825 */ 	or	$s1,$v1,$zero
/*  f129764:	0fc0f341 */ 	jal	func0f03cd04
/*  f129768:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f12976c:	00117880 */ 	sll	$t7,$s1,0x2
/*  f129770:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f129774:	af100000 */ 	sw	$s0,0x0($t8)
.L0f129778:
/*  f129778:	26730368 */ 	addiu	$s3,$s3,0x368
.L0f12977c:
/*  f12977c:	0276082a */ 	slt	$at,$s3,$s6
/*  f129780:	5420ffd6 */ 	bnezl	$at,.L0f1296dc
/*  f129784:	8eef0000 */ 	lw	$t7,0x0($s7)
.L0f129788:
/*  f129788:	00128843 */ 	sra	$s1,$s2,0x1
/*  f12978c:	12200015 */ 	beqz	$s1,.L0f1297e4
/*  f129790:	27b40054 */ 	addiu	$s4,$sp,0x54
.L0f129794:
/*  f129794:	0c004b70 */ 	jal	random
/*  f129798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12979c:	0052001b */ 	divu	$zero,$v0,$s2
/*  f1297a0:	00001810 */ 	mfhi	$v1
/*  f1297a4:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1297a8:	02994021 */ 	addu	$t0,$s4,$t9
/*  f1297ac:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f1297b0:	16400002 */ 	bnez	$s2,.L0f1297bc
/*  f1297b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1297b8:	0007000d */ 	break	0x7
.L0f1297bc:
/*  f1297bc:	00602825 */ 	or	$a1,$v1,$zero
/*  f1297c0:	11200006 */ 	beqz	$t1,.L0f1297dc
/*  f1297c4:	00035080 */ 	sll	$t2,$v1,0x2
/*  f1297c8:	028a8021 */ 	addu	$s0,$s4,$t2
/*  f1297cc:	0fc0f341 */ 	jal	func0f03cd04
/*  f1297d0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1297d4:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f1297d8:	2631ffff */ 	addiu	$s1,$s1,-1
.L0f1297dc:
/*  f1297dc:	1620ffed */ 	bnez	$s1,.L0f129794
/*  f1297e0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1297e4:
/*  f1297e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1297e8:
/*  f1297e8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1297ec:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1297f0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1297f4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1297f8:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1297fc:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f129800:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f129804:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f129808:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f12980c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f129810:	03e00008 */ 	jr	$ra
/*  f129814:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f129818
/*  f129818:	00047080 */ 	sll	$t6,$a0,0x2
/*  f12981c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f129820:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129824:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f129828:	3c0f8008 */ 	lui	$t7,%hi(var8007e3d0)
/*  f12982c:	25efe3d0 */ 	addiu	$t7,$t7,%lo(var8007e3d0)
/*  f129830:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f129834:	01cf4021 */ 	addu	$t0,$t6,$t7
/*  f129838:	8d070030 */ 	lw	$a3,0x30($t0)
/*  f12983c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f129840:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f129844:	18e00028 */ 	blez	$a3,.L0f1298e8
/*  f129848:	00001025 */ 	or	$v0,$zero,$zero
/*  f12984c:	00003025 */ 	or	$a2,$zero,$zero
/*  f129850:	8d030024 */ 	lw	$v1,0x24($t0)
.L0f129854:
/*  f129854:	8464000e */ 	lh	$a0,0xe($v1)
/*  f129858:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f12985c:	0047082a */ 	slt	$at,$v0,$a3
/*  f129860:	5880001f */ 	blezl	$a0,.L0f1298e0
/*  f129864:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f129868:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f12986c:	14b8001b */ 	bne	$a1,$t8,.L0f1298dc
/*  f129870:	2499ffff */ 	addiu	$t9,$a0,-1
/*  f129874:	a479000e */ 	sh	$t9,0xe($v1)
/*  f129878:	8d090024 */ 	lw	$t1,0x24($t0)
/*  f12987c:	01261821 */ 	addu	$v1,$t1,$a2
/*  f129880:	846a000e */ 	lh	$t2,0xe($v1)
/*  f129884:	55400019 */ 	bnezl	$t2,.L0f1298ec
/*  f129888:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f12988c:	8465000c */ 	lh	$a1,0xc($v1)
/*  f129890:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f129894:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f129898:	00055880 */ 	sll	$t3,$a1,0x2
/*  f12989c:	01655823 */ 	subu	$t3,$t3,$a1
/*  f1298a0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1298a4:	2565000f */ 	addiu	$a1,$t3,0xf
/*  f1298a8:	34ac000f */ 	ori	$t4,$a1,0xf
/*  f1298ac:	3985000f */ 	xori	$a1,$t4,0xf
/*  f1298b0:	0c004b2d */ 	jal	func00012cb4
/*  f1298b4:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f1298b8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f1298bc:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f1298c0:	8d0f0024 */ 	lw	$t7,0x24($t0)
/*  f1298c4:	8d0e002c */ 	lw	$t6,0x2c($t0)
/*  f1298c8:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f1298cc:	8719000c */ 	lh	$t9,0xc($t8)
/*  f1298d0:	01d94821 */ 	addu	$t1,$t6,$t9
/*  f1298d4:	10000004 */ 	beqz	$zero,.L0f1298e8
/*  f1298d8:	ad09002c */ 	sw	$t1,0x2c($t0)
.L0f1298dc:
/*  f1298dc:	24c60010 */ 	addiu	$a2,$a2,0x10
.L0f1298e0:
/*  f1298e0:	1420ffdc */ 	bnez	$at,.L0f129854
/*  f1298e4:	24630010 */ 	addiu	$v1,$v1,0x10
.L0f1298e8:
/*  f1298e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1298ec:
/*  f1298ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1298f0:	03e00008 */ 	jr	$ra
/*  f1298f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1298f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1298fc:	00000000 */ 	sll	$zero,$zero,0x0
);
