#include <ultra64.h>
#include "types.h"
#include "boot/boot.h"
#include "gvars/gvars.h"
#include "library/library_121e0.h"

void func000121e0(void)
{
	// empty
}

GLOBAL_ASM(
glabel func000121e8
/*    121e8:	00803025 */ 	or	$a2,$a0,$zero
/*    121ec:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    121f0:	3c04800a */ 	lui	$a0,%hi(var8009946c)
/*    121f4:	3c03800a */ 	lui	$v1,%hi(g_PrimaryMemoryPools)
/*    121f8:	3c02800a */ 	lui	$v0,%hi(g_SecondaryMemoryPools)
/*    121fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12200:	244293b8 */ 	addiu	$v0,$v0,%lo(g_SecondaryMemoryPools)
/*    12204:	24639300 */ 	addiu	$v1,$v1,%lo(g_PrimaryMemoryPools)
/*    12208:	2484946c */ 	addiu	$a0,$a0,%lo(var8009946c)
.L0001220c:
/*    1220c:	24420014 */ 	addiu	$v0,$v0,0x14
/*    12210:	0044082b */ 	sltu	$at,$v0,$a0
/*    12214:	24630014 */ 	addiu	$v1,$v1,0x14
/*    12218:	ac60ffec */ 	sw	$zero,-0x14($v1)
/*    1221c:	ac60fff0 */ 	sw	$zero,-0x10($v1)
/*    12220:	ac60fff4 */ 	sw	$zero,-0xc($v1)
/*    12224:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*    12228:	ac40ffec */ 	sw	$zero,-0x14($v0)
/*    1222c:	ac40fff0 */ 	sw	$zero,-0x10($v0)
/*    12230:	ac40fff4 */ 	sw	$zero,-0xc($v0)
/*    12234:	1420fff5 */ 	bnez	$at,.L0001220c
/*    12238:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*    1223c:	3c02800a */ 	lui	$v0,%hi(g_PrimaryMemoryPools)
/*    12240:	24429300 */ 	addiu	$v0,$v0,%lo(g_PrimaryMemoryPools)
/*    12244:	00c51821 */ 	addu	$v1,$a2,$a1
/*    12248:	ac460000 */ 	sw	$a2,0x0($v0)
/*    1224c:	ac430008 */ 	sw	$v1,0x8($v0)
/*    12250:	ac460078 */ 	sw	$a2,0x78($v0)
/*    12254:	ac430080 */ 	sw	$v1,0x80($v0)
/*    12258:	ac460050 */ 	sw	$a2,0x50($v0)
/*    1225c:	0c0005b0 */ 	jal	func000016c0
/*    12260:	ac430058 */ 	sw	$v1,0x58($v0)
/*    12264:	3c018000 */ 	lui	$at,0x8000
/*    12268:	00417021 */ 	addu	$t6,$v0,$at
/*    1226c:	0c0005b0 */ 	jal	func000016c0
/*    12270:	afae0018 */ 	sw	$t6,0x18($sp)
/*    12274:	3c010040 */ 	lui	$at,0x40
/*    12278:	34210001 */ 	ori	$at,$at,0x1
/*    1227c:	0041082a */ 	slt	$at,$v0,$at
/*    12280:	14200007 */ 	bnez	$at,.L000122a0
/*    12284:	3c03800a */ 	lui	$v1,%hi(g_PrimaryMemoryPools)
/*    12288:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    1228c:	3c02800a */ 	lui	$v0,%hi(g_SecondaryMemoryPools)
/*    12290:	244293b8 */ 	addiu	$v0,$v0,%lo(g_SecondaryMemoryPools)
/*    12294:	3c0f8040 */ 	lui	$t7,0x8040
/*    12298:	ac4f0050 */ 	sw	$t7,0x50($v0)
/*    1229c:	ac580058 */ 	sw	$t8,0x58($v0)
.L000122a0:
/*    122a0:	3c02800a */ 	lui	$v0,%hi(g_SecondaryMemoryPools)
/*    122a4:	3c04800a */ 	lui	$a0,%hi(var8009946c)
/*    122a8:	2484946c */ 	addiu	$a0,$a0,%lo(var8009946c)
/*    122ac:	244293b8 */ 	addiu	$v0,$v0,%lo(g_SecondaryMemoryPools)
/*    122b0:	24639300 */ 	addiu	$v1,$v1,%lo(g_PrimaryMemoryPools)
.L000122b4:
/*    122b4:	8c790008 */ 	lw	$t9,0x8($v1)
/*    122b8:	8c480008 */ 	lw	$t0,0x8($v0)
/*    122bc:	24420014 */ 	addiu	$v0,$v0,0x14
/*    122c0:	24630014 */ 	addiu	$v1,$v1,0x14
/*    122c4:	ac79fff8 */ 	sw	$t9,-0x8($v1)
/*    122c8:	1444fffa */ 	bne	$v0,$a0,.L000122b4
/*    122cc:	ac48fff8 */ 	sw	$t0,-0x8($v0)
/*    122d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    122d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    122d8:	03e00008 */ 	jr	$ra
/*    122dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000122e0
/*    122e0:	3c0e8009 */ 	lui	$t6,0x8009
/*    122e4:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*    122e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    122ec:	3c02800a */ 	lui	$v0,%hi(g_PrimaryMemoryPools)
/*    122f0:	15c10005 */ 	bne	$t6,$at,.L00012308
/*    122f4:	24429300 */ 	addiu	$v0,$v0,%lo(g_PrimaryMemoryPools)
/*    122f8:	8c4f0058 */ 	lw	$t7,0x58($v0)
/*    122fc:	8c580054 */ 	lw	$t8,0x54($v0)
/*    12300:	03e00008 */ 	jr	$ra
/*    12304:	01f81023 */ 	subu	$v0,$t7,$t8
.L00012308:
/*    12308:	3c02800a */ 	lui	$v0,%hi(g_SecondaryMemoryPools)
/*    1230c:	244293b8 */ 	addiu	$v0,$v0,%lo(g_SecondaryMemoryPools)
/*    12310:	8c590058 */ 	lw	$t9,0x58($v0)
/*    12314:	8c480054 */ 	lw	$t0,0x54($v0)
/*    12318:	03281823 */ 	subu	$v1,$t9,$t0
/*    1231c:	03e00008 */ 	jr	$ra
/*    12320:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func00012324
/*    12324:	3c0e8009 */ 	lui	$t6,0x8009
/*    12328:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*    1232c:	24010001 */ 	addiu	$at,$zero,0x1
/*    12330:	3c03800a */ 	lui	$v1,0x800a
/*    12334:	15c10004 */ 	bne	$t6,$at,.L00012348
/*    12338:	00000000 */ 	sll	$zero,$zero,0x0
/*    1233c:	3c03800a */ 	lui	$v1,0x800a
/*    12340:	03e00008 */ 	jr	$ra
/*    12344:	8c629354 */ 	lw	$v0,-0x6cac($v1)
.L00012348:
/*    12348:	8c63940c */ 	lw	$v1,-0x6bf4($v1)
/*    1234c:	03e00008 */ 	jr	$ra
/*    12350:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func00012354
/*    12354:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    12358:	000e7880 */ 	sll	$t7,$t6,0x2
/*    1235c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    12360:	000f7880 */ 	sll	$t7,$t7,0x2
/*    12364:	afa60008 */ 	sw	$a2,0x8($sp)
/*    12368:	008f2021 */ 	addu	$a0,$a0,$t7
/*    1236c:	8c820004 */ 	lw	$v0,0x4($a0)
/*    12370:	00a03825 */ 	or	$a3,$a1,$zero
/*    12374:	14400003 */ 	bnez	$v0,.L00012384
/*    12378:	00401825 */ 	or	$v1,$v0,$zero
/*    1237c:	03e00008 */ 	jr	$ra
/*    12380:	00601025 */ 	or	$v0,$v1,$zero
.L00012384:
/*    12384:	8c850008 */ 	lw	$a1,0x8($a0)
/*    12388:	0047c021 */ 	addu	$t8,$v0,$a3
/*    1238c:	00a2082b */ 	sltu	$at,$a1,$v0
/*    12390:	50200004 */ 	beqzl	$at,.L000123a4
/*    12394:	00b8082b */ 	sltu	$at,$a1,$t8
/*    12398:	03e00008 */ 	jr	$ra
/*    1239c:	00001025 */ 	or	$v0,$zero,$zero
/*    123a0:	00b8082b */ 	sltu	$at,$a1,$t8
.L000123a4:
/*    123a4:	10200003 */ 	beqz	$at,.L000123b4
/*    123a8:	0047c821 */ 	addu	$t9,$v0,$a3
/*    123ac:	03e00008 */ 	jr	$ra
/*    123b0:	00001025 */ 	or	$v0,$zero,$zero
.L000123b4:
/*    123b4:	ac990004 */ 	sw	$t9,0x4($a0)
/*    123b8:	ac830010 */ 	sw	$v1,0x10($a0)
/*    123bc:	00601025 */ 	or	$v0,$v1,$zero
/*    123c0:	03e00008 */ 	jr	$ra
/*    123c4:	00000000 */ 	sll	$zero,$zero,0x0
);

void *malloc(u32 len, u8 pool)
{
	void *allocation = func00012354(&g_PrimaryMemoryPools[0], len, pool);

	if (allocation) {
		return allocation;
	}

	allocation = func00012354(&g_SecondaryMemoryPools[0], len, pool);

	if (allocation) {
		return allocation;
	}

	return allocation;
}

GLOBAL_ASM(
glabel func00012430
/*    12430:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    12434:	000e1080 */ 	sll	$v0,$t6,0x2
/*    12438:	004e1021 */ 	addu	$v0,$v0,$t6
/*    1243c:	3c0f800a */ 	lui	$t7,%hi(g_PrimaryMemoryPools)
/*    12440:	25ef9300 */ 	addiu	$t7,$t7,%lo(g_PrimaryMemoryPools)
/*    12444:	00021080 */ 	sll	$v0,$v0,0x2
/*    12448:	afa50004 */ 	sw	$a1,0x4($sp)
/*    1244c:	afa60008 */ 	sw	$a2,0x8($sp)
/*    12450:	004f1821 */ 	addu	$v1,$v0,$t7
/*    12454:	8c780010 */ 	lw	$t8,0x10($v1)
/*    12458:	3c19800a */ 	lui	$t9,%hi(g_SecondaryMemoryPools)
/*    1245c:	273993b8 */ 	addiu	$t9,$t9,%lo(g_SecondaryMemoryPools)
/*    12460:	50980008 */ 	beql	$a0,$t8,.L00012484
/*    12464:	8c640004 */ 	lw	$a0,0x4($v1)
/*    12468:	00591821 */ 	addu	$v1,$v0,$t9
/*    1246c:	8c680010 */ 	lw	$t0,0x10($v1)
/*    12470:	50880004 */ 	beql	$a0,$t0,.L00012484
/*    12474:	8c640004 */ 	lw	$a0,0x4($v1)
/*    12478:	03e00008 */ 	jr	$ra
/*    1247c:	24020002 */ 	addiu	$v0,$zero,0x2
/*    12480:	8c640004 */ 	lw	$a0,0x4($v1)
.L00012484:
/*    12484:	8c690010 */ 	lw	$t1,0x10($v1)
/*    12488:	8faa0004 */ 	lw	$t2,0x4($sp)
/*    1248c:	00891023 */ 	subu	$v0,$a0,$t1
/*    12490:	01422823 */ 	subu	$a1,$t2,$v0
/*    12494:	1ca00009 */ 	bgtz	$a1,.L000124bc
/*    12498:	0085c021 */ 	addu	$t8,$a0,$a1
/*    1249c:	00855821 */ 	addu	$t3,$a0,$a1
/*    124a0:	256d000f */ 	addiu	$t5,$t3,0xf
/*    124a4:	35ae000f */ 	ori	$t6,$t5,0xf
/*    124a8:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*    124ac:	39cf000f */ 	xori	$t7,$t6,0xf
/*    124b0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*    124b4:	03e00008 */ 	jr	$ra
/*    124b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L000124bc:
/*    124bc:	ac780004 */ 	sw	$t8,0x4($v1)
/*    124c0:	24020001 */ 	addiu	$v0,$zero,0x1
/*    124c4:	03e00008 */ 	jr	$ra
/*    124c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    124cc:	03e00008 */ 	jr	$ra
/*    124d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000124d4
/*    124d4:	afa40000 */ 	sw	$a0,0x0($sp)
/*    124d8:	308e00ff */ 	andi	$t6,$a0,0xff
/*    124dc:	14a00008 */ 	bnez	$a1,.L00012500
/*    124e0:	01c02025 */ 	or	$a0,$t6,$zero
/*    124e4:	000e7880 */ 	sll	$t7,$t6,0x2
/*    124e8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    124ec:	3c18800a */ 	lui	$t8,%hi(g_PrimaryMemoryPools)
/*    124f0:	27189300 */ 	addiu	$t8,$t8,%lo(g_PrimaryMemoryPools)
/*    124f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    124f8:	10000007 */ 	beqz	$zero,.L00012518
/*    124fc:	01f81821 */ 	addu	$v1,$t7,$t8
.L00012500:
/*    12500:	0004c880 */ 	sll	$t9,$a0,0x2
/*    12504:	0324c821 */ 	addu	$t9,$t9,$a0
/*    12508:	3c08800a */ 	lui	$t0,%hi(g_SecondaryMemoryPools)
/*    1250c:	250893b8 */ 	addiu	$t0,$t0,%lo(g_SecondaryMemoryPools)
/*    12510:	0019c880 */ 	sll	$t9,$t9,0x2
/*    12514:	03281821 */ 	addu	$v1,$t9,$t0
.L00012518:
/*    12518:	8c690008 */ 	lw	$t1,0x8($v1)
/*    1251c:	8c6a0004 */ 	lw	$t2,0x4($v1)
/*    12520:	03e00008 */ 	jr	$ra
/*    12524:	012a1023 */ 	subu	$v0,$t1,$t2
);

GLOBAL_ASM(
glabel func00012528
/*    12528:	afa40000 */ 	sw	$a0,0x0($sp)
/*    1252c:	308e00ff */ 	andi	$t6,$a0,0xff
/*    12530:	24010004 */ 	addiu	$at,$zero,0x4
/*    12534:	15c10007 */ 	bne	$t6,$at,.L00012554
/*    12538:	01c02025 */ 	or	$a0,$t6,$zero
/*    1253c:	3c06800a */ 	lui	$a2,%hi(g_PrimaryMemoryPools)
/*    12540:	24c69300 */ 	addiu	$a2,$a2,%lo(g_PrimaryMemoryPools)
/*    12544:	8cc2007c */ 	lw	$v0,0x7c($a2)
/*    12548:	acc20050 */ 	sw	$v0,0x50($a2)
/*    1254c:	acc20080 */ 	sw	$v0,0x80($a2)
/*    12550:	acc20084 */ 	sw	$v0,0x84($a2)
.L00012554:
/*    12554:	00041080 */ 	sll	$v0,$a0,0x2
/*    12558:	00441021 */ 	addu	$v0,$v0,$a0
/*    1255c:	3c06800a */ 	lui	$a2,%hi(g_PrimaryMemoryPools)
/*    12560:	00021080 */ 	sll	$v0,$v0,0x2
/*    12564:	3c18800a */ 	lui	$t8,%hi(g_SecondaryMemoryPools)
/*    12568:	24c69300 */ 	addiu	$a2,$a2,%lo(g_PrimaryMemoryPools)
/*    1256c:	271893b8 */ 	addiu	$t8,$t8,%lo(g_SecondaryMemoryPools)
/*    12570:	00c21821 */ 	addu	$v1,$a2,$v0
/*    12574:	00582821 */ 	addu	$a1,$v0,$t8
/*    12578:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    1257c:	8cb90000 */ 	lw	$t9,0x0($a1)
/*    12580:	ac600010 */ 	sw	$zero,0x10($v1)
/*    12584:	aca00010 */ 	sw	$zero,0x10($a1)
/*    12588:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*    1258c:	03e00008 */ 	jr	$ra
/*    12590:	acb90004 */ 	sw	$t9,0x4($a1)
);

GLOBAL_ASM(
glabel func00012594
/*    12594:	308e00ff */ 	andi	$t6,$a0,0xff
/*    12598:	000e1080 */ 	sll	$v0,$t6,0x2
/*    1259c:	004e1021 */ 	addu	$v0,$v0,$t6
/*    125a0:	00021080 */ 	sll	$v0,$v0,0x2
/*    125a4:	3c0f800a */ 	lui	$t7,%hi(g_PrimaryMemoryPools)
/*    125a8:	3c18800a */ 	lui	$t8,%hi(g_SecondaryMemoryPools)
/*    125ac:	25ef9300 */ 	addiu	$t7,$t7,%lo(g_PrimaryMemoryPools)
/*    125b0:	271893b8 */ 	addiu	$t8,$t8,%lo(g_SecondaryMemoryPools)
/*    125b4:	004f1821 */ 	addu	$v1,$v0,$t7
/*    125b8:	00582821 */ 	addu	$a1,$v0,$t8
/*    125bc:	8c79000c */ 	lw	$t9,0xc($v1)
/*    125c0:	8ca8000c */ 	lw	$t0,0xc($a1)
/*    125c4:	afa40000 */ 	sw	$a0,0x0($sp)
/*    125c8:	ac600004 */ 	sw	$zero,0x4($v1)
/*    125cc:	aca00004 */ 	sw	$zero,0x4($a1)
/*    125d0:	ac790008 */ 	sw	$t9,0x8($v1)
/*    125d4:	03e00008 */ 	jr	$ra
/*    125d8:	aca80008 */ 	sw	$t0,0x8($a1)
);

GLOBAL_ASM(
glabel func000125dc
/*    125dc:	30ce00ff */ 	andi	$t6,$a2,0xff
/*    125e0:	000e7880 */ 	sll	$t7,$t6,0x2
/*    125e4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    125e8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    125ec:	afa60008 */ 	sw	$a2,0x8($sp)
/*    125f0:	008f2021 */ 	addu	$a0,$a0,$t7
/*    125f4:	8c820008 */ 	lw	$v0,0x8($a0)
/*    125f8:	14400003 */ 	bnez	$v0,.L00012608
/*    125fc:	00401825 */ 	or	$v1,$v0,$zero
/*    12600:	03e00008 */ 	jr	$ra
/*    12604:	00601025 */ 	or	$v0,$v1,$zero
.L00012608:
/*    12608:	8c830004 */ 	lw	$v1,0x4($a0)
/*    1260c:	00453023 */ 	subu	$a2,$v0,$a1
/*    12610:	0043082b */ 	sltu	$at,$v0,$v1
/*    12614:	50200004 */ 	beqzl	$at,.L00012628
/*    12618:	00c3082b */ 	sltu	$at,$a2,$v1
/*    1261c:	03e00008 */ 	jr	$ra
/*    12620:	00001025 */ 	or	$v0,$zero,$zero
/*    12624:	00c3082b */ 	sltu	$at,$a2,$v1
.L00012628:
/*    12628:	10200003 */ 	beqz	$at,.L00012638
/*    1262c:	00c01025 */ 	or	$v0,$a2,$zero
/*    12630:	03e00008 */ 	jr	$ra
/*    12634:	00001025 */ 	or	$v0,$zero,$zero
.L00012638:
/*    12638:	ac860008 */ 	sw	$a2,0x8($a0)
/*    1263c:	03e00008 */ 	jr	$ra
/*    12640:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00012644
/*    12644:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12648:	afa40018 */ 	sw	$a0,0x18($sp)
/*    1264c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12650:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    12654:	3c04800a */ 	lui	$a0,%hi(g_PrimaryMemoryPools)
/*    12658:	24849300 */ 	addiu	$a0,$a0,%lo(g_PrimaryMemoryPools)
/*    1265c:	93a6001f */ 	lbu	$a2,0x1f($sp)
/*    12660:	0c004977 */ 	jal	func000125dc
/*    12664:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12668:	10400003 */ 	beqz	$v0,.L00012678
/*    1266c:	3c04800a */ 	lui	$a0,%hi(g_SecondaryMemoryPools)
/*    12670:	1000000b */ 	beqz	$zero,.L000126a0
/*    12674:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00012678:
/*    12678:	248493b8 */ 	addiu	$a0,$a0,%lo(g_SecondaryMemoryPools)
/*    1267c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    12680:	0c004977 */ 	jal	func000125dc
/*    12684:	93a6001f */ 	lbu	$a2,0x1f($sp)
/*    12688:	10400003 */ 	beqz	$v0,.L00012698
/*    1268c:	00401825 */ 	or	$v1,$v0,$zero
/*    12690:	10000003 */ 	beqz	$zero,.L000126a0
/*    12694:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00012698:
/*    12698:	00601025 */ 	or	$v0,$v1,$zero
/*    1269c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000126a0:
/*    126a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    126a4:	03e00008 */ 	jr	$ra
/*    126a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    126ac:	00000000 */ 	sll	$zero,$zero,0x0
);
