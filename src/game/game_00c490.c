#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/ailists.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_00b480.h"
#include "game/game_00b820.h"
#include "game/game_00c490.h"
#include "game/game_0109d0.h"
#include "game/game_011110.h"
#include "game/game_012450.h"
#include "game/game_0125a0.h"
#include "game/game_012d50.h"
#include "game/game_0147d0.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/game_0601b0.h"
#include "game/game_091e10.h"
#include "game/game_096750.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/game_17f930.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1a7f60[] = "-nochr";
const char var7f1a7f68[] = "-noprop";
const char var7f1a7f70[] = "-noobj";
const char var7f1a7f78[] = "-noprop";

GLOBAL_ASM(
glabel func0f00c490
/*  f00c490:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00c494:	3c028007 */ 	lui	$v0,%hi(g_Lifts)
/*  f00c498:	3c038007 */ 	lui	$v1,%hi(var80069a70)
/*  f00c49c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00c4a0:	24639a70 */ 	addiu	$v1,$v1,%lo(var80069a70)
/*  f00c4a4:	24429a48 */ 	addiu	$v0,$v0,%lo(g_Lifts)
.L0f00c4a8:
/*  f00c4a8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f00c4ac:	0043082b */ 	sltu	$at,$v0,$v1
/*  f00c4b0:	1420fffd */ 	bnez	$at,.L0f00c4a8
/*  f00c4b4:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f00c4b8:	3c06800a */ 	lui	$a2,%hi(var8009ce40)
/*  f00c4bc:	3c07800a */ 	lui	$a3,%hi(var8009ce44)
/*  f00c4c0:	3c08800a */ 	lui	$t0,%hi(var8009ce48)
/*  f00c4c4:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c4c8:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c4cc:	2508ce48 */ 	addiu	$t0,$t0,%lo(var8009ce48)
/*  f00c4d0:	24e7ce44 */ 	addiu	$a3,$a3,%lo(var8009ce44)
/*  f00c4d4:	24c6ce40 */ 	addiu	$a2,$a2,%lo(var8009ce40)
/*  f00c4d8:	24030014 */ 	addiu	$v1,$zero,0x14
/*  f00c4dc:	240e0032 */ 	addiu	$t6,$zero,0x32
/*  f00c4e0:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f00c4e4:	2418000f */ 	addiu	$t8,$zero,0xf
/*  f00c4e8:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f00c4ec:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f00c4f0:	ad030000 */ 	sw	$v1,0x0($t0)
/*  f00c4f4:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f00c4f8:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f00c4fc:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f00c500:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00c504:	3c0a800a */ 	lui	$t2,%hi(g_Menus+0x2000)
/*  f00c508:	14820005 */ 	bne	$a0,$v0,.L0f00c520
/*  f00c50c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x4b4)
/*  f00c510:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c514:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c518:	10000004 */ 	b	.L0f00c52c
/*  f00c51c:	ad430000 */ 	sw	$v1,%lo(g_Menus+0x2000)($t2)
.L0f00c520:
/*  f00c520:	254ace50 */ 	addiu	$t2,$t2,-12720
/*  f00c524:	24190064 */ 	addiu	$t9,$zero,0x64
/*  f00c528:	ad590000 */ 	sw	$t9,0x0($t2)
.L0f00c52c:
/*  f00c52c:	14820006 */ 	bne	$a0,$v0,.L0f00c548
/*  f00c530:	3c0b800a */ 	lui	$t3,%hi(g_Menus+0x2000)
/*  f00c534:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c538:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c53c:	240d0028 */ 	addiu	$t5,$zero,0x28
/*  f00c540:	10000004 */ 	b	.L0f00c554
/*  f00c544:	ad6d0000 */ 	sw	$t5,%lo(g_Menus+0x2000)($t3)
.L0f00c548:
/*  f00c548:	256bce54 */ 	addiu	$t3,$t3,-12716
/*  f00c54c:	240e0050 */ 	addiu	$t6,$zero,0x50
/*  f00c550:	ad6e0000 */ 	sw	$t6,0x0($t3)
.L0f00c554:
/*  f00c554:	8defa474 */ 	lw	$t7,%lo(g_Vars+0x4b4)($t7)
/*  f00c558:	29e1005a */ 	slti	$at,$t7,0x5a
/*  f00c55c:	14200007 */ 	bnez	$at,.L0f00c57c
/*  f00c560:	00000000 */ 	nop
/*  f00c564:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f00c568:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f00c56c:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f00c570:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f00c574:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f00c578:	ad600000 */ 	sw	$zero,0x0($t3)
.L0f00c57c:
/*  f00c57c:	0fc03323 */ 	jal	func0f00cc8c
/*  f00c580:	00000000 */ 	nop
/*  f00c584:	0fc0338f */ 	jal	func0f00ce3c
/*  f00c588:	00000000 */ 	nop
/*  f00c58c:	3c018007 */ 	lui	$at,%hi(g_AlarmTimer)
/*  f00c590:	ac2098d4 */ 	sw	$zero,%lo(g_AlarmTimer)($at)
/*  f00c594:	3c018007 */ 	lui	$at,%hi(g_AlarmAudioHandle)
/*  f00c598:	ac2098d8 */ 	sw	$zero,%lo(g_AlarmAudioHandle)($at)
/*  f00c59c:	3c014280 */ 	lui	$at,0x4280
/*  f00c5a0:	44812000 */ 	mtc1	$at,$f4
/*  f00c5a4:	44800000 */ 	mtc1	$zero,$f0
/*  f00c5a8:	3c018007 */ 	lui	$at,%hi(g_AlarmSpeakerWeight)
/*  f00c5ac:	e42498dc */ 	swc1	$f4,%lo(g_AlarmSpeakerWeight)($at)
/*  f00c5b0:	3c018007 */ 	lui	$at,%hi(var800698e4)
/*  f00c5b4:	e42098e4 */ 	swc1	$f0,%lo(var800698e4)($at)
/*  f00c5b8:	3c018007 */ 	lui	$at,%hi(var800698e8)
/*  f00c5bc:	3c028007 */ 	lui	$v0,%hi(var800698ec)
/*  f00c5c0:	ac2098e8 */ 	sw	$zero,%lo(var800698e8)($at)
/*  f00c5c4:	244298ec */ 	addiu	$v0,$v0,%lo(var800698ec)
/*  f00c5c8:	3c018007 */ 	lui	$at,%hi(var800698f8)
/*  f00c5cc:	e4400000 */ 	swc1	$f0,0x0($v0)
/*  f00c5d0:	e4400004 */ 	swc1	$f0,0x4($v0)
/*  f00c5d4:	e4400008 */ 	swc1	$f0,0x8($v0)
/*  f00c5d8:	ac2098f8 */ 	sw	$zero,%lo(var800698f8)($at)
/*  f00c5dc:	3c018007 */ 	lui	$at,%hi(var800698fc)
/*  f00c5e0:	e42098fc */ 	swc1	$f0,%lo(var800698fc)($at)
/*  f00c5e4:	3c018007 */ 	lui	$at,%hi(var80069900)
/*  f00c5e8:	ac209900 */ 	sw	$zero,%lo(var80069900)($at)
/*  f00c5ec:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f00c5f0:	3c018007 */ 	lui	$at,%hi(g_CountdownTimerVisible)
/*  f00c5f4:	ac2c9904 */ 	sw	$t4,%lo(g_CountdownTimerVisible)($at)
/*  f00c5f8:	3c018007 */ 	lui	$at,%hi(g_CountdownTimerRunning)
/*  f00c5fc:	ac209908 */ 	sw	$zero,%lo(g_CountdownTimerRunning)($at)
/*  f00c600:	3c018007 */ 	lui	$at,%hi(g_CountdownTimerValue)
/*  f00c604:	e420990c */ 	swc1	$f0,%lo(g_CountdownTimerValue)($at)
/*  f00c608:	3c018007 */ 	lui	$at,%hi(var80069910)
/*  f00c60c:	ac209910 */ 	sw	$zero,%lo(var80069910)($at)
/*  f00c610:	3c06800a */ 	lui	$a2,%hi(var8009ce40)
/*  f00c614:	3c018007 */ 	lui	$at,%hi(g_TintedGlassEnabled)
/*  f00c618:	24c6ce40 */ 	addiu	$a2,$a2,%lo(var8009ce40)
/*  f00c61c:	ac2098d0 */ 	sw	$zero,%lo(g_TintedGlassEnabled)($at)
/*  f00c620:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f00c624:	3c07800a */ 	lui	$a3,%hi(var8009ce44)
/*  f00c628:	3c08800a */ 	lui	$t0,%hi(var8009ce48)
/*  f00c62c:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c630:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c634:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c638:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c63c:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c640:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c644:	2508ce48 */ 	addiu	$t0,$t0,%lo(var8009ce48)
/*  f00c648:	14600006 */ 	bnez	$v1,.L0f00c664
/*  f00c64c:	24e7ce44 */ 	addiu	$a3,$a3,%lo(var8009ce44)
/*  f00c650:	3c04800a */ 	lui	$a0,%hi(var8009ce58)
/*  f00c654:	2484ce58 */ 	addiu	$a0,$a0,%lo(var8009ce58)
/*  f00c658:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f00c65c:	1000002a */ 	b	.L0f00c708
/*  f00c660:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c664:
/*  f00c664:	00032080 */ 	sll	$a0,$v1,0x2
/*  f00c668:	00832023 */ 	subu	$a0,$a0,$v1
/*  f00c66c:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00c670:	00832021 */ 	addu	$a0,$a0,$v1
/*  f00c674:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f00c678:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c67c:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00c680:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00c684:	0c0048f2 */ 	jal	malloc
/*  f00c688:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c68c:	3c06800a */ 	lui	$a2,%hi(var8009ce40)
/*  f00c690:	24c6ce40 */ 	addiu	$a2,$a2,%lo(var8009ce40)
/*  f00c694:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f00c698:	3c04800a */ 	lui	$a0,%hi(var8009ce58)
/*  f00c69c:	2484ce58 */ 	addiu	$a0,$a0,%lo(var8009ce58)
/*  f00c6a0:	3c07800a */ 	lui	$a3,%hi(var8009ce44)
/*  f00c6a4:	3c08800a */ 	lui	$t0,%hi(var8009ce48)
/*  f00c6a8:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c6ac:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c6b0:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c6b4:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c6b8:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c6bc:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c6c0:	2508ce48 */ 	addiu	$t0,$t0,%lo(var8009ce48)
/*  f00c6c4:	24e7ce44 */ 	addiu	$a3,$a3,%lo(var8009ce44)
/*  f00c6c8:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00c6cc:	19a0000c */ 	blez	$t5,.L0f00c700
/*  f00c6d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f00c6d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c6d8:	8c8e0000 */ 	lw	$t6,0x0($a0)
.L0f00c6dc:
/*  f00c6dc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c6e0:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00c6e4:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f00c6e8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f00c6ec:	24420068 */ 	addiu	$v0,$v0,104
/*  f00c6f0:	0078082a */ 	slt	$at,$v1,$t8
/*  f00c6f4:	5420fff9 */ 	bnezl	$at,.L0f00c6dc
/*  f00c6f8:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f00c6fc:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c700:
/*  f00c700:	3c018007 */ 	lui	$at,%hi(var80069914)
/*  f00c704:	ac209914 */ 	sw	$zero,%lo(var80069914)($at)
.L0f00c708:
/*  f00c708:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f00c70c:	3c04800a */ 	lui	$a0,%hi(var8009ce5c)
/*  f00c710:	2484ce5c */ 	addiu	$a0,$a0,%lo(var8009ce5c)
/*  f00c714:	54400004 */ 	bnezl	$v0,.L0f00c728
/*  f00c718:	00022080 */ 	sll	$a0,$v0,0x2
/*  f00c71c:	10000029 */ 	b	.L0f00c7c4
/*  f00c720:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f00c724:	00022080 */ 	sll	$a0,$v0,0x2
.L0f00c728:
/*  f00c728:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c72c:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f00c730:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c734:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00c738:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c73c:	3499000f */ 	ori	$t9,$a0,0xf
/*  f00c740:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f00c744:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c748:	0c0048f2 */ 	jal	malloc
/*  f00c74c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00c750:	3c07800a */ 	lui	$a3,%hi(var8009ce44)
/*  f00c754:	24e7ce44 */ 	addiu	$a3,$a3,%lo(var8009ce44)
/*  f00c758:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f00c75c:	3c04800a */ 	lui	$a0,%hi(var8009ce5c)
/*  f00c760:	2484ce5c */ 	addiu	$a0,$a0,%lo(var8009ce5c)
/*  f00c764:	3c08800a */ 	lui	$t0,%hi(var8009ce48)
/*  f00c768:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c76c:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c770:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c774:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c778:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c77c:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c780:	2508ce48 */ 	addiu	$t0,$t0,%lo(var8009ce48)
/*  f00c784:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00c788:	19c0000c */ 	blez	$t6,.L0f00c7bc
/*  f00c78c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00c790:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c794:	8c8f0000 */ 	lw	$t7,0x0($a0)
.L0f00c798:
/*  f00c798:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c79c:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f00c7a0:	af000014 */ 	sw	$zero,0x14($t8)
/*  f00c7a4:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f00c7a8:	2442005c */ 	addiu	$v0,$v0,0x5c
/*  f00c7ac:	0079082a */ 	slt	$at,$v1,$t9
/*  f00c7b0:	5420fff9 */ 	bnezl	$at,.L0f00c798
/*  f00c7b4:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f00c7b8:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c7bc:
/*  f00c7bc:	3c018007 */ 	lui	$at,%hi(var80069918)
/*  f00c7c0:	ac209918 */ 	sw	$zero,%lo(var80069918)($at)
.L0f00c7c4:
/*  f00c7c4:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f00c7c8:	3c04800a */ 	lui	$a0,%hi(var8009ce60)
/*  f00c7cc:	2484ce60 */ 	addiu	$a0,$a0,%lo(var8009ce60)
/*  f00c7d0:	54400004 */ 	bnezl	$v0,.L0f00c7e4
/*  f00c7d4:	00022080 */ 	sll	$a0,$v0,0x2
/*  f00c7d8:	10000023 */ 	b	.L0f00c868
/*  f00c7dc:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f00c7e0:	00022080 */ 	sll	$a0,$v0,0x2
.L0f00c7e4:
/*  f00c7e4:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c7e8:	00042140 */ 	sll	$a0,$a0,0x5
/*  f00c7ec:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c7f0:	348d000f */ 	ori	$t5,$a0,0xf
/*  f00c7f4:	39a4000f */ 	xori	$a0,$t5,0xf
/*  f00c7f8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c7fc:	0c0048f2 */ 	jal	malloc
/*  f00c800:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00c804:	3c08800a */ 	lui	$t0,%hi(var8009ce48)
/*  f00c808:	2508ce48 */ 	addiu	$t0,$t0,%lo(var8009ce48)
/*  f00c80c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f00c810:	3c04800a */ 	lui	$a0,%hi(var8009ce60)
/*  f00c814:	2484ce60 */ 	addiu	$a0,$a0,%lo(var8009ce60)
/*  f00c818:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c81c:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c820:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c824:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c828:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c82c:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c830:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00c834:	19e0000c */ 	blez	$t7,.L0f00c868
/*  f00c838:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00c83c:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c840:	8c980000 */ 	lw	$t8,0x0($a0)
.L0f00c844:
/*  f00c844:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c848:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f00c84c:	af200014 */ 	sw	$zero,0x14($t9)
/*  f00c850:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f00c854:	24420060 */ 	addiu	$v0,$v0,0x60
/*  f00c858:	006d082a */ 	slt	$at,$v1,$t5
/*  f00c85c:	5420fff9 */ 	bnezl	$at,.L0f00c844
/*  f00c860:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f00c864:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c868:
/*  f00c868:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f00c86c:	14400004 */ 	bnez	$v0,.L0f00c880
/*  f00c870:	3c04800a */ 	lui	$a0,%hi(var8009ce64)
/*  f00c874:	2484ce64 */ 	addiu	$a0,$a0,%lo(var8009ce64)
/*  f00c878:	10000023 */ 	b	.L0f00c908
/*  f00c87c:	ac800000 */ 	sw	$zero,0x0($a0)
.L0f00c880:
/*  f00c880:	00022080 */ 	sll	$a0,$v0,0x2
/*  f00c884:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c888:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f00c88c:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c890:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00c894:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c898:	348e000f */ 	ori	$t6,$a0,0xf
/*  f00c89c:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f00c8a0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c8a4:	0c0048f2 */ 	jal	malloc
/*  f00c8a8:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00c8ac:	3c09800a */ 	lui	$t1,%hi(var8009ce4c)
/*  f00c8b0:	2529ce4c */ 	addiu	$t1,$t1,%lo(var8009ce4c)
/*  f00c8b4:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f00c8b8:	3c04800a */ 	lui	$a0,%hi(var8009ce64)
/*  f00c8bc:	2484ce64 */ 	addiu	$a0,$a0,%lo(var8009ce64)
/*  f00c8c0:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c8c4:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c8c8:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c8cc:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c8d0:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00c8d4:	1b00000c */ 	blez	$t8,.L0f00c908
/*  f00c8d8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00c8dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c8e0:	8c990000 */ 	lw	$t9,0x0($a0)
.L0f00c8e4:
/*  f00c8e4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c8e8:	03226821 */ 	addu	$t5,$t9,$v0
/*  f00c8ec:	ada00014 */ 	sw	$zero,0x14($t5)
/*  f00c8f0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f00c8f4:	2442005c */ 	addiu	$v0,$v0,0x5c
/*  f00c8f8:	006e082a */ 	slt	$at,$v1,$t6
/*  f00c8fc:	5420fff9 */ 	bnezl	$at,.L0f00c8e4
/*  f00c900:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f00c904:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c908:
/*  f00c908:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f00c90c:	14400004 */ 	bnez	$v0,.L0f00c920
/*  f00c910:	3c05800a */ 	lui	$a1,%hi(var8009ce68)
/*  f00c914:	24a5ce68 */ 	addiu	$a1,$a1,%lo(var8009ce68)
/*  f00c918:	10000022 */ 	b	.L0f00c9a4
/*  f00c91c:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f00c920:
/*  f00c920:	00022100 */ 	sll	$a0,$v0,0x4
/*  f00c924:	00822021 */ 	addu	$a0,$a0,$v0
/*  f00c928:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00c92c:	00822023 */ 	subu	$a0,$a0,$v0
/*  f00c930:	00042080 */ 	sll	$a0,$a0,0x2
/*  f00c934:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c938:	348f000f */ 	ori	$t7,$a0,0xf
/*  f00c93c:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f00c940:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c944:	0c0048f2 */ 	jal	malloc
/*  f00c948:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00c94c:	3c0a800a */ 	lui	$t2,%hi(var8009ce50)
/*  f00c950:	254ace50 */ 	addiu	$t2,$t2,%lo(var8009ce50)
/*  f00c954:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f00c958:	3c05800a */ 	lui	$a1,%hi(var8009ce68)
/*  f00c95c:	24a5ce68 */ 	addiu	$a1,$a1,%lo(var8009ce68)
/*  f00c960:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c964:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c968:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f00c96c:	1b20000d */ 	blez	$t9,.L0f00c9a4
/*  f00c970:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00c974:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c978:	3c048000 */ 	lui	$a0,0x8000
/*  f00c97c:	8cad0000 */ 	lw	$t5,0x0($a1)
.L0f00c980:
/*  f00c980:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c984:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f00c988:	adc40000 */ 	sw	$a0,0x0($t6)
/*  f00c98c:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f00c990:	2442010c */ 	addiu	$v0,$v0,0x10c
/*  f00c994:	006f082a */ 	slt	$at,$v1,$t7
/*  f00c998:	5420fff9 */ 	bnezl	$at,.L0f00c980
/*  f00c99c:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f00c9a0:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c9a4:
/*  f00c9a4:	8d620000 */ 	lw	$v0,0x0($t3)
/*  f00c9a8:	14400004 */ 	bnez	$v0,.L0f00c9bc
/*  f00c9ac:	3c04800a */ 	lui	$a0,%hi(var8009ce6c)
/*  f00c9b0:	2484ce6c */ 	addiu	$a0,$a0,%lo(var8009ce6c)
/*  f00c9b4:	1000001e */ 	b	.L0f00ca30
/*  f00c9b8:	ac800000 */ 	sw	$zero,0x0($a0)
.L0f00c9bc:
/*  f00c9bc:	000220c0 */ 	sll	$a0,$v0,0x3
/*  f00c9c0:	00822021 */ 	addu	$a0,$a0,$v0
/*  f00c9c4:	000420c0 */ 	sll	$a0,$a0,0x3
/*  f00c9c8:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00c9cc:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00c9d0:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00c9d4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c9d8:	0c0048f2 */ 	jal	malloc
/*  f00c9dc:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00c9e0:	3c0b800a */ 	lui	$t3,%hi(var8009ce54)
/*  f00c9e4:	256bce54 */ 	addiu	$t3,$t3,%lo(var8009ce54)
/*  f00c9e8:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*  f00c9ec:	3c04800a */ 	lui	$a0,%hi(var8009ce6c)
/*  f00c9f0:	2484ce6c */ 	addiu	$a0,$a0,%lo(var8009ce6c)
/*  f00c9f4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00c9f8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00c9fc:	19a0000c */ 	blez	$t5,.L0f00ca30
/*  f00ca00:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f00ca04:	00001025 */ 	or	$v0,$zero,$zero
/*  f00ca08:	8c8e0000 */ 	lw	$t6,0x0($a0)
.L0f00ca0c:
/*  f00ca0c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00ca10:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00ca14:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f00ca18:	8d780000 */ 	lw	$t8,0x0($t3)
/*  f00ca1c:	24420048 */ 	addiu	$v0,$v0,0x48
/*  f00ca20:	0078082a */ 	slt	$at,$v1,$t8
/*  f00ca24:	5420fff9 */ 	bnezl	$at,.L0f00ca0c
/*  f00ca28:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f00ca2c:	00001825 */ 	or	$v1,$zero,$zero
.L0f00ca30:
/*  f00ca30:	3c013f80 */ 	lui	$at,0x3f80
/*  f00ca34:	44810000 */ 	mtc1	$at,$f0
/*  f00ca38:	3c018007 */ 	lui	$at,%hi(var8006991c)
/*  f00ca3c:	ac20991c */ 	sw	$zero,%lo(var8006991c)($at)
/*  f00ca40:	3c018007 */ 	lui	$at,%hi(g_PadlockedDoors)
/*  f00ca44:	ac209920 */ 	sw	$zero,%lo(g_PadlockedDoors)($at)
/*  f00ca48:	3c018007 */ 	lui	$at,%hi(var80069924)
/*  f00ca4c:	ac209924 */ 	sw	$zero,%lo(var80069924)($at)
/*  f00ca50:	3c018007 */ 	lui	$at,%hi(var80069928)
/*  f00ca54:	ac209928 */ 	sw	$zero,%lo(var80069928)($at)
/*  f00ca58:	3c018007 */ 	lui	$at,%hi(var8006992c)
/*  f00ca5c:	ac20992c */ 	sw	$zero,%lo(var8006992c)($at)
/*  f00ca60:	3c018007 */ 	lui	$at,%hi(var80069930)
/*  f00ca64:	ac209930 */ 	sw	$zero,%lo(var80069930)($at)
/*  f00ca68:	3c018007 */ 	lui	$at,%hi(var80069934)
/*  f00ca6c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f00ca70:	ac399934 */ 	sw	$t9,%lo(var80069934)($at)
/*  f00ca74:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f00ca78:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f00ca7c:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f00ca80:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f00ca84:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f00ca88:	e4209950 */ 	swc1	$f0,%lo(var80069950)($at)
/*  f00ca8c:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f00ca90:	e4209954 */ 	swc1	$f0,%lo(var80069954)($at)
/*  f00ca94:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f00ca98:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f00ca9c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f00caa0:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f00caa4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f00caa8:	e420995c */ 	swc1	$f0,%lo(g_AmmoMultiplier)($at)
/*  f00caac:	8c4d0318 */ 	lw	$t5,0x318($v0)
/*  f00cab0:	11a00005 */ 	beqz	$t5,.L0f00cac8
/*  f00cab4:	3c078007 */ 	lui	$a3,%hi(var80069970)
/*  f00cab8:	24e79970 */ 	addiu	$a3,$a3,%lo(var80069970)
/*  f00cabc:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f00cac0:	1000001f */ 	b	.L0f00cb40
/*  f00cac4:	acee0000 */ 	sw	$t6,0x0($a3)
.L0f00cac8:
/*  f00cac8:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f00cacc:	3c078007 */ 	lui	$a3,%hi(var80069970)
/*  f00cad0:	24e79970 */ 	addiu	$a3,$a3,%lo(var80069970)
/*  f00cad4:	51e00004 */ 	beqzl	$t7,.L0f00cae8
/*  f00cad8:	00003025 */ 	or	$a2,$zero,$zero
/*  f00cadc:	10000002 */ 	b	.L0f00cae8
/*  f00cae0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f00cae4:	00003025 */ 	or	$a2,$zero,$zero
.L0f00cae8:
/*  f00cae8:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f00caec:	53000004 */ 	beqzl	$t8,.L0f00cb00
/*  f00caf0:	00002025 */ 	or	$a0,$zero,$zero
/*  f00caf4:	10000002 */ 	b	.L0f00cb00
/*  f00caf8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00cafc:	00002025 */ 	or	$a0,$zero,$zero
.L0f00cb00:
/*  f00cb00:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f00cb04:	53200004 */ 	beqzl	$t9,.L0f00cb18
/*  f00cb08:	00002825 */ 	or	$a1,$zero,$zero
/*  f00cb0c:	10000002 */ 	b	.L0f00cb18
/*  f00cb10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00cb14:	00002825 */ 	or	$a1,$zero,$zero
.L0f00cb18:
/*  f00cb18:	8c4d0070 */ 	lw	$t5,0x70($v0)
/*  f00cb1c:	51a00004 */ 	beqzl	$t5,.L0f00cb30
/*  f00cb20:	00001025 */ 	or	$v0,$zero,$zero
/*  f00cb24:	10000002 */ 	b	.L0f00cb30
/*  f00cb28:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f00cb2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f00cb30:
/*  f00cb30:	00457021 */ 	addu	$t6,$v0,$a1
/*  f00cb34:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f00cb38:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f00cb3c:	acf80000 */ 	sw	$t8,0x0($a3)
.L0f00cb40:
/*  f00cb40:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f00cb44:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00cb48:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00cb4c:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f00cb50:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f00cb54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f00cb58:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f00cb5c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f00cb60:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f00cb64:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f00cb68:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f00cb6c:	348d000f */ 	ori	$t5,$a0,0xf
/*  f00cb70:	0c0048f2 */ 	jal	malloc
/*  f00cb74:	39a4000f */ 	xori	$a0,$t5,0xf
/*  f00cb78:	3c078007 */ 	lui	$a3,%hi(var80069970)
/*  f00cb7c:	24e79970 */ 	addiu	$a3,$a3,%lo(var80069970)
/*  f00cb80:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f00cb84:	3c068007 */ 	lui	$a2,%hi(g_ThrownLaptops)
/*  f00cb88:	24c69968 */ 	addiu	$a2,$a2,%lo(g_ThrownLaptops)
/*  f00cb8c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f00cb90:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f00cb94:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00cb98:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f00cb9c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00cba0:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f00cba4:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00cba8:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f00cbac:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00cbb0:	0c0048f2 */ 	jal	malloc
/*  f00cbb4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00cbb8:	3c078007 */ 	lui	$a3,%hi(var80069970)
/*  f00cbbc:	3c018007 */ 	lui	$at,%hi(var8006996c)
/*  f00cbc0:	ac22996c */ 	sw	$v0,%lo(var8006996c)($at)
/*  f00cbc4:	24e79970 */ 	addiu	$a3,$a3,%lo(var80069970)
/*  f00cbc8:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f00cbcc:	3c068007 */ 	lui	$a2,%hi(g_ThrownLaptops)
/*  f00cbd0:	24c69968 */ 	addiu	$a2,$a2,%lo(g_ThrownLaptops)
/*  f00cbd4:	19a0000b */ 	blez	$t5,.L0f00cc04
/*  f00cbd8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00cbdc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00cbe0:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f00cbe4:
/*  f00cbe4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00cbe8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00cbec:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f00cbf0:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f00cbf4:	244200ac */ 	addiu	$v0,$v0,0xac
/*  f00cbf8:	0078082a */ 	slt	$at,$v1,$t8
/*  f00cbfc:	5420fff9 */ 	bnezl	$at,.L0f00cbe4
/*  f00cc00:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0f00cc04:
/*  f00cc04:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00cc08:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00cc0c:	03e00008 */ 	jr	$ra
/*  f00cc10:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00cc14
/*  f00cc14:	3c028007 */ 	lui	$v0,%hi(var8006991c)
/*  f00cc18:	2442991c */ 	addiu	$v0,$v0,%lo(var8006991c)
/*  f00cc1c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f00cc20:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f00cc24:	03e00008 */ 	jr	$ra
/*  f00cc28:	ac440000 */ 	sw	$a0,0x0($v0)
);

void func0f00cc2c(struct padlockeddoor *door)
{
	door->next = g_PadlockedDoors;
	g_PadlockedDoors = door;
}

GLOBAL_ASM(
glabel func0f00cc44
/*  f00cc44:	3c028007 */ 	lui	$v0,%hi(var80069924)
/*  f00cc48:	24429924 */ 	addiu	$v0,$v0,%lo(var80069924)
/*  f00cc4c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f00cc50:	ac8e0010 */ 	sw	$t6,0x10($a0)
/*  f00cc54:	03e00008 */ 	jr	$ra
/*  f00cc58:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f00cc5c
/*  f00cc5c:	3c028007 */ 	lui	$v0,%hi(var80069928)
/*  f00cc60:	24429928 */ 	addiu	$v0,$v0,%lo(var80069928)
/*  f00cc64:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f00cc68:	ac8e0010 */ 	sw	$t6,0x10($a0)
/*  f00cc6c:	03e00008 */ 	jr	$ra
/*  f00cc70:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f00cc74
/*  f00cc74:	3c028007 */ 	lui	$v0,%hi(var8006992c)
/*  f00cc78:	2442992c */ 	addiu	$v0,$v0,%lo(var8006992c)
/*  f00cc7c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f00cc80:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f00cc84:	03e00008 */ 	jr	$ra
/*  f00cc88:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f00cc8c
/*  f00cc8c:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f00cc90:	3c0e8006 */ 	lui	$t6,%hi(var80061a80)
/*  f00cc94:	27a200ec */ 	addiu	$v0,$sp,0xec
/*  f00cc98:	25ce1a80 */ 	addiu	$t6,$t6,%lo(var80061a80)
/*  f00cc9c:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f00cca0:	27a40004 */ 	addiu	$a0,$sp,0x4
/*  f00cca4:	25d9006c */ 	addiu	$t9,$t6,0x6c
/*  f00cca8:	00404025 */ 	or	$t0,$v0,$zero
.L0f00ccac:
/*  f00ccac:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00ccb0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00ccb4:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00ccb8:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00ccbc:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f00ccc0:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00ccc4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f00ccc8:	15d9fff8 */ 	bne	$t6,$t9,.L0f00ccac
/*  f00cccc:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00ccd0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00ccd4:	3c09800a */ 	lui	$t1,%hi(var8009ce98)
/*  f00ccd8:	2529ce98 */ 	addiu	$t1,$t1,%lo(var8009ce98)
/*  f00ccdc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00cce0:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f00cce4:	00406825 */ 	or	$t5,$v0,$zero
/*  f00cce8:	244c006c */ 	addiu	$t4,$v0,0x6c
/*  f00ccec:	ad190004 */ 	sw	$t9,0x4($t0)
.L0f00ccf0:
/*  f00ccf0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f00ccf4:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f00ccf8:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f00ccfc:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f00cd00:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f00cd04:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f00cd08:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f00cd0c:	15acfff8 */ 	bne	$t5,$t4,.L0f00ccf0
/*  f00cd10:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f00cd14:	8da10000 */ 	lw	$at,0x0($t5)
/*  f00cd18:	3c188006 */ 	lui	$t8,%hi(var80061af4)
/*  f00cd1c:	27181af4 */ 	addiu	$t8,$t8,%lo(var80061af4)
/*  f00cd20:	ad210000 */ 	sw	$at,0x0($t1)
/*  f00cd24:	8dac0004 */ 	lw	$t4,0x4($t5)
/*  f00cd28:	270e006c */ 	addiu	$t6,$t8,0x6c
/*  f00cd2c:	00604025 */ 	or	$t0,$v1,$zero
/*  f00cd30:	ad2c0004 */ 	sw	$t4,0x4($t1)
.L0f00cd34:
/*  f00cd34:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00cd38:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00cd3c:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00cd40:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00cd44:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f00cd48:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00cd4c:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f00cd50:	170efff8 */ 	bne	$t8,$t6,.L0f00cd34
/*  f00cd54:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00cd58:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00cd5c:	3c0b800a */ 	lui	$t3,%hi(var8009cf10)
/*  f00cd60:	256bcf10 */ 	addiu	$t3,$t3,%lo(var8009cf10)
/*  f00cd64:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00cd68:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f00cd6c:	00604825 */ 	or	$t1,$v1,$zero
/*  f00cd70:	246d006c */ 	addiu	$t5,$v1,0x6c
/*  f00cd74:	ad0e0004 */ 	sw	$t6,0x4($t0)
.L0f00cd78:
/*  f00cd78:	8d210000 */ 	lw	$at,0x0($t1)
/*  f00cd7c:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f00cd80:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f00cd84:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*  f00cd88:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f00cd8c:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*  f00cd90:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f00cd94:	152dfff8 */ 	bne	$t1,$t5,.L0f00cd78
/*  f00cd98:	ad61fffc */ 	sw	$at,-0x4($t3)
/*  f00cd9c:	8d210000 */ 	lw	$at,0x0($t1)
/*  f00cda0:	3c198006 */ 	lui	$t9,%hi(var80061b68)
/*  f00cda4:	27391b68 */ 	addiu	$t9,$t9,%lo(var80061b68)
/*  f00cda8:	ad610000 */ 	sw	$at,0x0($t3)
/*  f00cdac:	8d2d0004 */ 	lw	$t5,0x4($t1)
/*  f00cdb0:	2738006c */ 	addiu	$t8,$t9,0x6c
/*  f00cdb4:	00804025 */ 	or	$t0,$a0,$zero
/*  f00cdb8:	ad6d0004 */ 	sw	$t5,0x4($t3)
.L0f00cdbc:
/*  f00cdbc:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00cdc0:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f00cdc4:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00cdc8:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00cdcc:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f00cdd0:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00cdd4:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f00cdd8:	1738fff8 */ 	bne	$t9,$t8,.L0f00cdbc
/*  f00cddc:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00cde0:	8f210000 */ 	lw	$at,0x0($t9)
/*  f00cde4:	3c0c800a */ 	lui	$t4,%hi(var8009cf88)
/*  f00cde8:	258ccf88 */ 	addiu	$t4,$t4,%lo(var8009cf88)
/*  f00cdec:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00cdf0:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f00cdf4:	00805825 */ 	or	$t3,$a0,$zero
/*  f00cdf8:	2489006c */ 	addiu	$t1,$a0,0x6c
/*  f00cdfc:	ad180004 */ 	sw	$t8,0x4($t0)
.L0f00ce00:
/*  f00ce00:	8d610000 */ 	lw	$at,0x0($t3)
/*  f00ce04:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f00ce08:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f00ce0c:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f00ce10:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f00ce14:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f00ce18:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f00ce1c:	1569fff8 */ 	bne	$t3,$t1,.L0f00ce00
/*  f00ce20:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f00ce24:	8d610000 */ 	lw	$at,0x0($t3)
/*  f00ce28:	ad810000 */ 	sw	$at,0x0($t4)
/*  f00ce2c:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f00ce30:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f00ce34:	03e00008 */ 	jr	$ra
/*  f00ce38:	ad890004 */ 	sw	$t1,0x4($t4)
);

GLOBAL_ASM(
glabel func0f00ce3c
/*  f00ce3c:	3c03800a */ 	lui	$v1,%hi(g_ProxyMines)
/*  f00ce40:	3c02800a */ 	lui	$v0,%hi(var8009ce38)
/*  f00ce44:	2442ce38 */ 	addiu	$v0,$v0,%lo(var8009ce38)
/*  f00ce48:	2463cdc0 */ 	addiu	$v1,$v1,%lo(g_ProxyMines)
.L0f00ce4c:
/*  f00ce4c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f00ce50:	1462fffe */ 	bne	$v1,$v0,.L0f00ce4c
/*  f00ce54:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f00ce58:	03e00008 */ 	jr	$ra
/*  f00ce5c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel setupCountCommandType
/*  f00ce60:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f00ce64:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00ce68:	3c10800a */ 	lui	$s0,%hi(g_StageSetup+0x10)
/*  f00ce6c:	8e10d040 */ 	lw	$s0,%lo(g_StageSetup+0x10)($s0)
/*  f00ce70:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00ce74:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f00ce78:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00ce7c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00ce80:	12000010 */ 	beqz	$s0,.L0f00cec4
/*  f00ce84:	00008825 */ 	or	$s1,$zero,$zero
/*  f00ce88:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f00ce8c:	24130034 */ 	addiu	$s3,$zero,0x34
/*  f00ce90:	309200ff */ 	andi	$s2,$a0,0xff
/*  f00ce94:	5263000c */ 	beql	$s3,$v1,.L0f00cec8
/*  f00ce98:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f00ce9c:
/*  f00ce9c:	16430002 */ 	bne	$s2,$v1,.L0f00cea8
/*  f00cea0:	00000000 */ 	nop
/*  f00cea4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f00cea8:
/*  f00cea8:	0fc24784 */ 	jal	setupGetCommandLength
/*  f00ceac:	02002025 */ 	or	$a0,$s0,$zero
/*  f00ceb0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f00ceb4:	01d08021 */ 	addu	$s0,$t6,$s0
/*  f00ceb8:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f00cebc:	1663fff7 */ 	bne	$s3,$v1,.L0f00ce9c
/*  f00cec0:	00000000 */ 	nop
.L0f00cec4:
/*  f00cec4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f00cec8:
/*  f00cec8:	02201025 */ 	or	$v0,$s1,$zero
/*  f00cecc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00ced0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00ced4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00ced8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00cedc:	03e00008 */ 	jr	$ra
/*  f00cee0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f00cee4
.late_rodata
glabel var7f1a7f80
.word 0x358637bd
.text
/*  f00cee4:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f00cee8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f00ceec:	00808025 */ 	or	$s0,$a0,$zero
/*  f00cef0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00cef4:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f00cef8:	84840004 */ 	lh	$a0,0x4($a0)
/*  f00cefc:	0fc2486d */ 	jal	propLoad
/*  f00cf00:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f00cf04:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f00cf08:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f00cf0c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f00cf10:	448e2000 */ 	mtc1	$t6,$f4
/*  f00cf14:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00cf18:	05c10005 */ 	bgez	$t6,.L0f00cf30
/*  f00cf1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00cf20:	3c014f80 */ 	lui	$at,0x4f80
/*  f00cf24:	44814000 */ 	mtc1	$at,$f8
/*  f00cf28:	00000000 */ 	nop
/*  f00cf2c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f00cf30:
/*  f00cf30:	3c013b80 */ 	lui	$at,0x3b80
/*  f00cf34:	44815000 */ 	mtc1	$at,$f10
/*  f00cf38:	8c6f0318 */ 	lw	$t7,0x318($v1)
/*  f00cf3c:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f00cf40:	15e00004 */ 	bnez	$t7,.L0f00cf54
/*  f00cf44:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f00cf48:	8c78031c */ 	lw	$t8,0x31c($v1)
/*  f00cf4c:	53000005 */ 	beqzl	$t8,.L0f00cf64
/*  f00cf50:	8e030008 */ 	lw	$v1,0x8($s0)
.L0f00cf54:
/*  f00cf54:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f00cf58:	37290004 */ 	ori	$t1,$t9,0x4
/*  f00cf5c:	a2090002 */ 	sb	$t1,0x2($s0)
/*  f00cf60:	8e030008 */ 	lw	$v1,0x8($s0)
.L0f00cf64:
/*  f00cf64:	306a8000 */ 	andi	$t2,$v1,0x8000
/*  f00cf68:	1140001b */ 	beqz	$t2,.L0f00cfd8
/*  f00cf6c:	306e4000 */ 	andi	$t6,$v1,0x4000
/*  f00cf70:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f00cf74:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00cf78:	02002025 */ 	or	$a0,$s0,$zero
/*  f00cf7c:	15610009 */ 	bne	$t3,$at,.L0f00cfa4
/*  f00cf80:	000868c0 */ 	sll	$t5,$t0,0x3
/*  f00cf84:	000860c0 */ 	sll	$t4,$t0,0x3
/*  f00cf88:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00cf8c:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f00cf90:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00cf94:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00cf98:	02002025 */ 	or	$a0,$s0,$zero
/*  f00cf9c:	10000006 */ 	b	.L0f00cfb8
/*  f00cfa0:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00cfa4:
/*  f00cfa4:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00cfa8:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f00cfac:	0fc1a94b */ 	jal	func0f06a52c
/*  f00cfb0:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00cfb4:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00cfb8:
/*  f00cfb8:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f00cfbc:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f00cfc0:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f00cfc4:	44055000 */ 	mfc1	$a1,$f10
/*  f00cfc8:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00cfcc:	00000000 */ 	nop
/*  f00cfd0:	100001a3 */ 	b	.L0f00d660
/*  f00cfd4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00cfd8:
/*  f00cfd8:	51c0002d */ 	beqzl	$t6,.L0f00d090
/*  f00cfdc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00cfe0:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f00cfe4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00cfe8:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00cfec:	1040019b */ 	beqz	$v0,.L0f00d65c
/*  f00cff0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f00cff4:	8c4f001c */ 	lw	$t7,0x1c($v0)
/*  f00cff8:	51e00199 */ 	beqzl	$t7,.L0f00d660
/*  f00cffc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d000:	8c580020 */ 	lw	$t8,0x20($v0)
/*  f00d004:	53000196 */ 	beqzl	$t8,.L0f00d660
/*  f00d008:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d00c:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f00d010:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d014:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d018:	17210009 */ 	bne	$t9,$at,.L0f00d040
/*  f00d01c:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f00d020:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f00d024:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00d028:	00a92821 */ 	addu	$a1,$a1,$t1
/*  f00d02c:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00d030:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d034:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d038:	10000006 */ 	b	.L0f00d054
/*  f00d03c:	00403025 */ 	or	$a2,$v0,$zero
.L0f00d040:
/*  f00d040:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00d044:	00aa2821 */ 	addu	$a1,$a1,$t2
/*  f00d048:	0fc1a94b */ 	jal	func0f06a52c
/*  f00d04c:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00d050:	00403025 */ 	or	$a2,$v0,$zero
.L0f00d054:
/*  f00d054:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d058:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f00d05c:	c4840014 */ 	lwc1	$f4,0x14($a0)
/*  f00d060:	afa6006c */ 	sw	$a2,0x6c($sp)
/*  f00d064:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f00d068:	44053000 */ 	mfc1	$a1,$f6
/*  f00d06c:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00d070:	00000000 */ 	nop
/*  f00d074:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f00d078:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f00d07c:	0fc181a6 */ 	jal	propReparent
/*  f00d080:	8d65001c */ 	lw	$a1,0x1c($t3)
/*  f00d084:	10000176 */ 	b	.L0f00d660
/*  f00d088:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d08c:	86040006 */ 	lh	$a0,0x6($s0)
.L0f00d090:
/*  f00d090:	2405006e */ 	addiu	$a1,$zero,0x6e
/*  f00d094:	0481001b */ 	bgez	$a0,.L0f00d104
/*  f00d098:	00000000 */ 	nop
/*  f00d09c:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f00d0a0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d0a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d0a8:	15810009 */ 	bne	$t4,$at,.L0f00d0d0
/*  f00d0ac:	000870c0 */ 	sll	$t6,$t0,0x3
/*  f00d0b0:	000868c0 */ 	sll	$t5,$t0,0x3
/*  f00d0b4:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00d0b8:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f00d0bc:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00d0c0:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d0c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d0c8:	10000006 */ 	b	.L0f00d0e4
/*  f00d0cc:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d0d0:
/*  f00d0d0:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00d0d4:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f00d0d8:	0fc1a94b */ 	jal	func0f06a52c
/*  f00d0dc:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00d0e0:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d0e4:
/*  f00d0e4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f00d0e8:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*  f00d0ec:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f00d0f0:	44054000 */ 	mfc1	$a1,$f8
/*  f00d0f4:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00d0f8:	00000000 */ 	nop
/*  f00d0fc:	10000158 */ 	b	.L0f00d660
/*  f00d100:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00d104:
/*  f00d104:	0fc456ac */ 	jal	padUnpack
/*  f00d108:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f00d10c:	8faf0134 */ 	lw	$t7,0x134($sp)
/*  f00d110:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f00d114:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f00d118:	59e00151 */ 	blezl	$t7,.L0f00d660
/*  f00d11c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d120:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f00d124:	46003287 */ 	neg.s	$f10,$f6
/*  f00d128:	44800000 */ 	mtc1	$zero,$f0
/*  f00d12c:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f00d130:	46002207 */ 	neg.s	$f8,$f4
/*  f00d134:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f00d138:	46003287 */ 	neg.s	$f10,$f6
/*  f00d13c:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f00d140:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f00d144:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f00d148:	c7a40104 */ 	lwc1	$f4,0x104($sp)
/*  f00d14c:	44050000 */ 	mfc1	$a1,$f0
/*  f00d150:	44060000 */ 	mfc1	$a2,$f0
/*  f00d154:	44070000 */ 	mfc1	$a3,$f0
/*  f00d158:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f00d15c:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f00d160:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f00d164:	0c005b56 */ 	jal	func00016d58
/*  f00d168:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f00d16c:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f00d170:	c7a400f0 */ 	lwc1	$f4,0xf0($sp)
/*  f00d174:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f00d178:	8fb80134 */ 	lw	$t8,0x134($sp)
/*  f00d17c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f00d180:	a7b90082 */ 	sh	$t9,0x82($sp)
/*  f00d184:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f00d188:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f00d18c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f00d190:	a7b80080 */ 	sh	$t8,0x80($sp)
/*  f00d194:	0fc457c0 */ 	jal	padHasBboxData
/*  f00d198:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d19c:	14400013 */ 	bnez	$v0,.L0f00d1ec
/*  f00d1a0:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00d1a4:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f00d1a8:	c7a600ec */ 	lwc1	$f6,0xec($sp)
/*  f00d1ac:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f00d1b0:	312a0002 */ 	andi	$t2,$t1,0x2
/*  f00d1b4:	51400008 */ 	beqzl	$t2,.L0f00d1d8
/*  f00d1b8:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f00d1bc:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f00d1c0:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f00d1c4:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f00d1c8:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f00d1cc:	10000021 */ 	b	.L0f00d254
/*  f00d1d0:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
/*  f00d1d4:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
.L0f00d1d8:
/*  f00d1d8:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f00d1dc:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f00d1e0:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f00d1e4:	1000001b */ 	b	.L0f00d254
/*  f00d1e8:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
.L0f00d1ec:
/*  f00d1ec:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d1f0:	0fc457cd */ 	jal	padGetCentre
/*  f00d1f4:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f00d1f8:	c7a40124 */ 	lwc1	$f4,0x124($sp)
/*  f00d1fc:	c7a80128 */ 	lwc1	$f8,0x128($sp)
/*  f00d200:	3c013f00 */ 	lui	$at,0x3f00
/*  f00d204:	44815000 */ 	mtc1	$at,$f10
/*  f00d208:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f00d20c:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f00d210:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f00d214:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00d218:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f00d21c:	00000000 */ 	nop
/*  f00d220:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f00d224:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f00d228:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f00d22c:	c7a40108 */ 	lwc1	$f4,0x108($sp)
/*  f00d230:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f00d234:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f00d238:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f00d23c:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f00d240:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f00d244:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f00d248:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f00d24c:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f00d250:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
.L0f00d254:
/*  f00d254:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f00d258:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d25c:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d260:	15610007 */ 	bne	$t3,$at,.L0f00d280
/*  f00d264:	000860c0 */ 	sll	$t4,$t0,0x3
/*  f00d268:	3c058008 */ 	lui	$a1,%hi(g_Props)
/*  f00d26c:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f00d270:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d274:	8ca5b06c */ 	lw	$a1,%lo(g_Props)($a1)
/*  f00d278:	10000004 */ 	b	.L0f00d28c
/*  f00d27c:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0f00d280:
/*  f00d280:	0fc1a954 */ 	jal	func0f06a550
/*  f00d284:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d288:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0f00d28c:
/*  f00d28c:	0fc457c0 */ 	jal	padHasBboxData
/*  f00d290:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d294:	504000c1 */ 	beqzl	$v0,.L0f00d59c
/*  f00d298:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d29c:	0fc1a2bd */ 	jal	func0f068af4
/*  f00d2a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d2a4:	104000bc */ 	beqz	$v0,.L0f00d598
/*  f00d2a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f00d2ac:	44819000 */ 	mtc1	$at,$f18
/*  f00d2b0:	00000000 */ 	nop
/*  f00d2b4:	e7b20064 */ 	swc1	$f18,0x64($sp)
/*  f00d2b8:	8e030008 */ 	lw	$v1,0x8($s0)
/*  f00d2bc:	46009406 */ 	mov.s	$f16,$f18
/*  f00d2c0:	30640020 */ 	andi	$a0,$v1,0x20
/*  f00d2c4:	1080001c */ 	beqz	$a0,.L0f00d338
/*  f00d2c8:	30660040 */ 	andi	$a2,$v1,0x40
/*  f00d2cc:	c4420004 */ 	lwc1	$f2,0x4($v0)
/*  f00d2d0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f00d2d4:	306d0002 */ 	andi	$t5,$v1,0x2
/*  f00d2d8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d2dc:	00000000 */ 	nop
/*  f00d2e0:	45000015 */ 	bc1f	.L0f00d338
/*  f00d2e4:	00000000 */ 	nop
/*  f00d2e8:	11a0000b */ 	beqz	$t5,.L0f00d318
/*  f00d2ec:	c7a80120 */ 	lwc1	$f8,0x120($sp)
/*  f00d2f0:	c7a80120 */ 	lwc1	$f8,0x120($sp)
/*  f00d2f4:	c7a4011c */ 	lwc1	$f4,0x11c($sp)
/*  f00d2f8:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f00d2fc:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d300:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d304:	c5c80014 */ 	lwc1	$f8,0x14($t6)
/*  f00d308:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f00d30c:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f00d310:	10000009 */ 	b	.L0f00d338
/*  f00d314:	e7aa0064 */ 	swc1	$f10,0x64($sp)
.L0f00d318:
/*  f00d318:	c7a6011c */ 	lwc1	$f6,0x11c($sp)
/*  f00d31c:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f00d320:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d324:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f00d328:	c5e80014 */ 	lwc1	$f8,0x14($t7)
/*  f00d32c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f00d330:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f00d334:	e7aa0064 */ 	swc1	$f10,0x64($sp)
.L0f00d338:
/*  f00d338:	10c00018 */ 	beqz	$a2,.L0f00d39c
/*  f00d33c:	30650080 */ 	andi	$a1,$v1,0x80
/*  f00d340:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f00d344:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f00d348:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d34c:	00000000 */ 	nop
/*  f00d350:	45000012 */ 	bc1f	.L0f00d39c
/*  f00d354:	00000000 */ 	nop
/*  f00d358:	8e180018 */ 	lw	$t8,0x18($s0)
/*  f00d35c:	30790002 */ 	andi	$t9,$v1,0x2
/*  f00d360:	13200008 */ 	beqz	$t9,.L0f00d384
/*  f00d364:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f00d368:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d36c:	c7a80130 */ 	lwc1	$f8,0x130($sp)
/*  f00d370:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f00d374:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d378:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f00d37c:	10000007 */ 	b	.L0f00d39c
/*  f00d380:	46083483 */ 	div.s	$f18,$f6,$f8
.L0f00d384:
/*  f00d384:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f00d388:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f00d38c:	c7aa0124 */ 	lwc1	$f10,0x124($sp)
/*  f00d390:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f00d394:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*  f00d398:	46043403 */ 	div.s	$f16,$f6,$f4
.L0f00d39c:
/*  f00d39c:	50a00019 */ 	beqzl	$a1,.L0f00d404
/*  f00d3a0:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f00d3a4:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f00d3a8:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f00d3ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d3b0:	00000000 */ 	nop
/*  f00d3b4:	45020013 */ 	bc1fl	.L0f00d404
/*  f00d3b8:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f00d3bc:	8e090018 */ 	lw	$t1,0x18($s0)
/*  f00d3c0:	306a0002 */ 	andi	$t2,$v1,0x2
/*  f00d3c4:	11400008 */ 	beqz	$t2,.L0f00d3e8
/*  f00d3c8:	c52c0014 */ 	lwc1	$f12,0x14($t1)
/*  f00d3cc:	46020101 */ 	sub.s	$f4,$f0,$f2
/*  f00d3d0:	c7aa0128 */ 	lwc1	$f10,0x128($sp)
/*  f00d3d4:	c7a80124 */ 	lwc1	$f8,0x124($sp)
/*  f00d3d8:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f00d3dc:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f00d3e0:	10000007 */ 	b	.L0f00d400
/*  f00d3e4:	460a3403 */ 	div.s	$f16,$f6,$f10
.L0f00d3e8:
/*  f00d3e8:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d3ec:	c7a80130 */ 	lwc1	$f8,0x130($sp)
/*  f00d3f0:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f00d3f4:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d3f8:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f00d3fc:	46083483 */ 	div.s	$f18,$f6,$f8
.L0f00d400:
/*  f00d400:	c7a40064 */ 	lwc1	$f4,0x64($sp)
.L0f00d404:
/*  f00d404:	c7ac0064 */ 	lwc1	$f12,0x64($sp)
/*  f00d408:	4604803c */ 	c.lt.s	$f16,$f4
/*  f00d40c:	00000000 */ 	nop
/*  f00d410:	45020002 */ 	bc1fl	.L0f00d41c
/*  f00d414:	4610603c */ 	c.lt.s	$f12,$f16
/*  f00d418:	4610603c */ 	c.lt.s	$f12,$f16
.L0f00d41c:
/*  f00d41c:	46006386 */ 	mov.s	$f14,$f12
/*  f00d420:	45020003 */ 	bc1fl	.L0f00d430
/*  f00d424:	4612703c */ 	c.lt.s	$f14,$f18
/*  f00d428:	46008386 */ 	mov.s	$f14,$f16
/*  f00d42c:	4612703c */ 	c.lt.s	$f14,$f18
.L0f00d430:
/*  f00d430:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f00d434:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f00d438:	45000002 */ 	bc1f	.L0f00d444
/*  f00d43c:	00000000 */ 	nop
/*  f00d440:	46009386 */ 	mov.s	$f14,$f18
.L0f00d444:
/*  f00d444:	1480000f */ 	bnez	$a0,.L0f00d484
/*  f00d448:	306d0002 */ 	andi	$t5,$v1,0x2
/*  f00d44c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f00d450:	11600007 */ 	beqz	$t3,.L0f00d470
/*  f00d454:	c4420004 */ 	lwc1	$f2,0x4($v0)
/*  f00d458:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d45c:	00000000 */ 	nop
/*  f00d460:	45000008 */ 	bc1f	.L0f00d484
/*  f00d464:	00000000 */ 	nop
/*  f00d468:	10000006 */ 	b	.L0f00d484
/*  f00d46c:	46007306 */ 	mov.s	$f12,$f14
.L0f00d470:
/*  f00d470:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d474:	00000000 */ 	nop
/*  f00d478:	45000002 */ 	bc1f	.L0f00d484
/*  f00d47c:	00000000 */ 	nop
/*  f00d480:	46007306 */ 	mov.s	$f12,$f14
.L0f00d484:
/*  f00d484:	14c0000f */ 	bnez	$a2,.L0f00d4c4
/*  f00d488:	460e6303 */ 	div.s	$f12,$f12,$f14
/*  f00d48c:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f00d490:	11800007 */ 	beqz	$t4,.L0f00d4b0
/*  f00d494:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f00d498:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d49c:	00000000 */ 	nop
/*  f00d4a0:	45000008 */ 	bc1f	.L0f00d4c4
/*  f00d4a4:	00000000 */ 	nop
/*  f00d4a8:	10000006 */ 	b	.L0f00d4c4
/*  f00d4ac:	46007486 */ 	mov.s	$f18,$f14
.L0f00d4b0:
/*  f00d4b0:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4b4:	00000000 */ 	nop
/*  f00d4b8:	45000002 */ 	bc1f	.L0f00d4c4
/*  f00d4bc:	00000000 */ 	nop
/*  f00d4c0:	46007406 */ 	mov.s	$f16,$f14
.L0f00d4c4:
/*  f00d4c4:	14a0000f */ 	bnez	$a1,.L0f00d504
/*  f00d4c8:	3c017f1a */ 	lui	$at,%hi(var7f1a7f80)
/*  f00d4cc:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f00d4d0:	11a00007 */ 	beqz	$t5,.L0f00d4f0
/*  f00d4d4:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f00d4d8:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4dc:	00000000 */ 	nop
/*  f00d4e0:	45000008 */ 	bc1f	.L0f00d504
/*  f00d4e4:	00000000 */ 	nop
/*  f00d4e8:	10000006 */ 	b	.L0f00d504
/*  f00d4ec:	46007406 */ 	mov.s	$f16,$f14
.L0f00d4f0:
/*  f00d4f0:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4f4:	00000000 */ 	nop
/*  f00d4f8:	45000002 */ 	bc1f	.L0f00d504
/*  f00d4fc:	00000000 */ 	nop
/*  f00d500:	46007486 */ 	mov.s	$f18,$f14
.L0f00d504:
/*  f00d504:	c4207f80 */ 	lwc1	$f0,%lo(var7f1a7f80)($at)
/*  f00d508:	460e8403 */ 	div.s	$f16,$f16,$f14
/*  f00d50c:	3c013f80 */ 	lui	$at,0x3f80
/*  f00d510:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d514:	4600603e */ 	c.le.s	$f12,$f0
/*  f00d518:	00000000 */ 	nop
/*  f00d51c:	45010009 */ 	bc1t	.L0f00d544
/*  f00d520:	460e9483 */ 	div.s	$f18,$f18,$f14
/*  f00d524:	4600803e */ 	c.le.s	$f16,$f0
/*  f00d528:	00000000 */ 	nop
/*  f00d52c:	45030006 */ 	bc1tl	.L0f00d548
/*  f00d530:	44816000 */ 	mtc1	$at,$f12
/*  f00d534:	4600903e */ 	c.le.s	$f18,$f0
/*  f00d538:	00000000 */ 	nop
/*  f00d53c:	45020006 */ 	bc1fl	.L0f00d558
/*  f00d540:	e7ae0054 */ 	swc1	$f14,0x54($sp)
.L0f00d544:
/*  f00d544:	44816000 */ 	mtc1	$at,$f12
.L0f00d548:
/*  f00d548:	00000000 */ 	nop
/*  f00d54c:	46006486 */ 	mov.s	$f18,$f12
/*  f00d550:	46006406 */ 	mov.s	$f16,$f12
/*  f00d554:	e7ae0054 */ 	swc1	$f14,0x54($sp)
.L0f00d558:
/*  f00d558:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*  f00d55c:	0c005789 */ 	jal	func00015e24
/*  f00d560:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f00d564:	c7ac0060 */ 	lwc1	$f12,0x60($sp)
/*  f00d568:	0c0057a0 */ 	jal	func00015e80
/*  f00d56c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d570:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f00d574:	0c0057b7 */ 	jal	func00015edc
/*  f00d578:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d57c:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d580:	c7ae0054 */ 	lwc1	$f14,0x54($sp)
/*  f00d584:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*  f00d588:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*  f00d58c:	44053000 */ 	mfc1	$a1,$f6
/*  f00d590:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00d594:	00000000 */ 	nop
.L0f00d598:
/*  f00d598:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d59c:
/*  f00d59c:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f00d5a0:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f00d5a4:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f00d5a8:	44055000 */ 	mfc1	$a1,$f10
/*  f00d5ac:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00d5b0:	00000000 */ 	nop
/*  f00d5b4:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f00d5b8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d5bc:	0c0057c1 */ 	jal	func00015f04
/*  f00d5c0:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f00d5c4:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f00d5c8:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f00d5cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d5d0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f00d5d4:	07010004 */ 	bgez	$t8,.L0f00d5e8
/*  f00d5d8:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f00d5dc:	93290001 */ 	lbu	$t1,0x1($t9)
/*  f00d5e0:	352a0010 */ 	ori	$t2,$t1,0x10
/*  f00d5e4:	a32a0001 */ 	sb	$t2,0x1($t9)
.L0f00d5e8:
/*  f00d5e8:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f00d5ec:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00d5f0:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f00d5f4:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f00d5f8:	1180000a */ 	beqz	$t4,.L0f00d624
/*  f00d5fc:	27ae00a0 */ 	addiu	$t6,$sp,0xa0
/*  f00d600:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f00d604:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f00d608:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d60c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f00d610:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00d614:	0fc1aad8 */ 	jal	func0f06ab60
/*  f00d618:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f00d61c:	10000004 */ 	b	.L0f00d630
/*  f00d620:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f00d624:
/*  f00d624:	0fc1a9cc */ 	jal	func0f06a730
/*  f00d628:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f00d62c:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f00d630:
/*  f00d630:	31f88000 */ 	andi	$t8,$t7,0x8000
/*  f00d634:	13000005 */ 	beqz	$t8,.L0f00d64c
/*  f00d638:	00000000 */ 	nop
/*  f00d63c:	0fc1814e */ 	jal	func0f060538
/*  f00d640:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f00d644:	10000003 */ 	b	.L0f00d654
/*  f00d648:	00000000 */ 	nop
.L0f00d64c:
/*  f00d64c:	0fc1812f */ 	jal	func0f0604bc
/*  f00d650:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d654:
/*  f00d654:	0fc180bc */ 	jal	propShow
/*  f00d658:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d65c:
/*  f00d65c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00d660:
/*  f00d660:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00d664:	27bd0148 */ 	addiu	$sp,$sp,0x148
/*  f00d668:	03e00008 */ 	jr	$ra
/*  f00d66c:	00000000 */ 	nop
);

/**
 * Assigns a weapon to its home.
 *
 * Its home is a chr's hand or a pad, as defined in the stage's setup file.
 *
 * The Marquis of Queensbury Rules (everyone unarmed) and Enemy Rockets cheats
 * are implemented here.
 */
void weaponAssignToHome(struct weaponobj *weapon, u32 arg1)
{
	if (weapon->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		u32 stack[2];
		struct chrdata *chr = chrFindByLiteralId(weapon->base.pad);

		if (chr && chr->prop && chr->model) {
			if (cheatIsActive(CHEAT_MARQUIS)) {
				weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
				weapon->base.flags |= OBJFLAG_20000000;
				func0f011560(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			} else {
				if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
					switch (weapon->weaponnum) {
					case WEAPON_FALCON2:
					case WEAPON_FALCON2_SILENCER:
					case WEAPON_FALCON2_SCOPE:
					case WEAPON_MAGSEC4:
					case WEAPON_MAULER:
					case WEAPON_PHOENIX:
					case WEAPON_DY357MAGNUM:
					case WEAPON_DY357LX:
					case WEAPON_CMP150:
					case WEAPON_CYCLONE:
					case WEAPON_CALLISTONTG:
					case WEAPON_RCP120:
					case WEAPON_LAPTOPGUN:
					case WEAPON_DRAGON:
					case WEAPON_AR34:
					case WEAPON_SUPERDRAGON:
					case WEAPON_SHOTGUN:
					case WEAPON_REAPER:
					case WEAPON_SNIPERRIFLE:
					case WEAPON_FARSIGHTXR20:
					case WEAPON_DEVASTATOR:
					case WEAPON_ROCKETLAUNCHER:
					case WEAPON_SLAYER:
					case WEAPON_COMBATKNIFE:
					case WEAPON_CROSSBOW:
					case WEAPON_TRANQUILIZER:
					case WEAPON_GRENADE:
					case WEAPON_NBOMB:
					case WEAPON_TIMEDMINE:
					case WEAPON_PROXIMITYMINE:
					case WEAPON_REMOTEMINE:
						weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
						weapon->base.modelnum = MODEL_CHRDYROCKET;
						weapon->base.extrascale = 256;
						break;
					case WEAPON_K7AVENGER:
						// Don't replace the K7 guard's weapon in Investigation
						// because it would make an objective impossible
						if (g_Vars.stagenum != STAGE_INVESTIGATION || getDifficulty() != DIFF_PA) {
							weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
							weapon->base.modelnum = MODEL_CHRDYROCKET;
							weapon->base.extrascale = 256;
						}
						break;
					}
				}

				func0f011560(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			}
		}
	} else {
		bool giveweapon = true;

		if (g_Vars.normmplayerisrunning || g_Vars.unk00031c) {
			struct mpweapon *mpweapon;
			s32 mpweaponnum;

			var8009cc30 = -1;

			// Seems like a weaponnum >= 240 means an mpweaponnum...
			switch (weapon->weaponnum) {
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff:
				mpweaponnum = weapon->weaponnum - 0xf0;
				mpweapon = func0f188e24(mpweaponnum);
				var8009cc30 = mpweaponnum;
				weapon->weaponnum = mpweapon->weaponnum;
				weapon->base.modelnum = mpweapon->model;
				weapon->base.extrascale = mpweapon->extrascale;
				giveweapon = mpweapon->giveweapon;

				if (mpweapon->weaponnum == WEAPON_MPSHIELD) {
					struct shieldobj *shield = (struct shieldobj *)weapon;
					shield->base.modelnum = MODEL_CHRSHIELD;
					shield->base.type = OBJTYPE_SHIELD;
					shield->base.flags |= OBJFLAG_01000000 | OBJFLAG_INVINCIBLE;
					shield->base.flags2 |= OBJFLAG2_00200000 | OBJFLAG2_00004000;
					shield->initialamount = 1;
					shield->amount = 1;
					func0f00cee4(&shield->base, arg1);
					giveweapon = false;
				}
				break;
			}
		}

		if (weapon->weaponnum != WEAPON_NONE && giveweapon) {
			func0f011560(weapon->weaponnum);
			func0f00cee4(&weapon->base, arg1);
		}
	}
}

GLOBAL_ASM(
glabel func0f00d904
/*  f00d904:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00d908:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00d90c:	8c8e0008 */ 	lw	$t6,0x8($a0)
/*  f00d910:	00803025 */ 	or	$a2,$a0,$zero
/*  f00d914:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f00d918:	11e00011 */ 	beqz	$t7,.L0f00d960
/*  f00d91c:	00000000 */ 	nop
/*  f00d920:	84840006 */ 	lh	$a0,0x6($a0)
/*  f00d924:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f00d928:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f00d92c:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f00d930:	1040000d */ 	beqz	$v0,.L0f00d968
/*  f00d934:	00402825 */ 	or	$a1,$v0,$zero
/*  f00d938:	8c58001c */ 	lw	$t8,0x1c($v0)
/*  f00d93c:	5300000b */ 	beqzl	$t8,.L0f00d96c
/*  f00d940:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00d944:	8c590020 */ 	lw	$t9,0x20($v0)
/*  f00d948:	53200008 */ 	beqzl	$t9,.L0f00d96c
/*  f00d94c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00d950:	0fc2276e */ 	jal	func0f089db8
/*  f00d954:	00c02025 */ 	or	$a0,$a2,$zero
/*  f00d958:	10000004 */ 	b	.L0f00d96c
/*  f00d95c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f00d960:
/*  f00d960:	0fc033b9 */ 	jal	func0f00cee4
/*  f00d964:	00c02025 */ 	or	$a0,$a2,$zero
.L0f00d968:
/*  f00d968:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f00d96c:
/*  f00d96c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00d970:	03e00008 */ 	jr	$ra
/*  f00d974:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00d978
/*  f00d978:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00d97c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00d980:	0fc033b9 */ 	jal	func0f00cee4
/*  f00d984:	00000000 */ 	nop
/*  f00d988:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00d98c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00d990:	03e00008 */ 	jr	$ra
/*  f00d994:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00d998
/*  f00d998:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00d99c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00d9a0:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f00d9a4:	a08e0003 */ 	sb	$t6,0x3($a0)
/*  f00d9a8:	0fc033b9 */ 	jal	func0f00cee4
/*  f00d9ac:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f00d9b0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f00d9b4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f00d9b8:	8c4f0298 */ 	lw	$t7,0x298($v0)
/*  f00d9bc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f00d9c0:	05e30005 */ 	bgezl	$t7,.L0f00d9d8
/*  f00d9c4:	8c990040 */ 	lw	$t9,0x40($a0)
/*  f00d9c8:	8c58029c */ 	lw	$t8,0x29c($v0)
/*  f00d9cc:	07020009 */ 	bltzl	$t8,.L0f00d9f4
/*  f00d9d0:	8c820014 */ 	lw	$v0,0x14($a0)
/*  f00d9d4:	8c990040 */ 	lw	$t9,0x40($a0)
.L0f00d9d8:
/*  f00d9d8:	3c010fff */ 	lui	$at,0xfff
/*  f00d9dc:	3421ffff */ 	ori	$at,$at,0xffff
/*  f00d9e0:	03214024 */ 	and	$t0,$t9,$at
/*  f00d9e4:	3c012000 */ 	lui	$at,0x2000
/*  f00d9e8:	01014825 */ 	or	$t1,$t0,$at
/*  f00d9ec:	ac890040 */ 	sw	$t1,0x40($a0)
/*  f00d9f0:	8c820014 */ 	lw	$v0,0x14($a0)
.L0f00d9f4:
/*  f00d9f4:	904b003f */ 	lbu	$t3,0x3f($v0)
/*  f00d9f8:	356c0020 */ 	ori	$t4,$t3,0x20
/*  f00d9fc:	a04c003f */ 	sb	$t4,0x3f($v0)
/*  f00da00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00da04:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00da08:	03e00008 */ 	jr	$ra
/*  f00da0c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00da10
.late_rodata
glabel var7f1a8048
.word 0x40c907a9
glabel var7f1a804c
.word 0x40c907a9
.text
/*  f00da10:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f00da14:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f00da18:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f00da1c:	00808025 */ 	or	$s0,$a0,$zero
/*  f00da20:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f00da24:	0fc033b9 */ 	jal	func0f00cee4
/*  f00da28:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f00da2c:	860e005c */ 	lh	$t6,0x5c($s0)
/*  f00da30:	05c2006e */ 	bltzl	$t6,.L0f00dbec
/*  f00da34:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f00da38:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f00da3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f00da40:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00da44:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f00da48:	8604005c */ 	lh	$a0,0x5c($s0)
/*  f00da4c:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f00da50:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f00da54:	0fc456ac */ 	jal	padUnpack
/*  f00da58:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f00da5c:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f00da60:	2604001c */ 	addiu	$a0,$s0,0x1c
/*  f00da64:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f00da68:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f00da6c:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f00da70:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f00da74:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f00da78:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f00da7c:	0c005882 */ 	jal	func00016208
/*  f00da80:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f00da84:	8e180014 */ 	lw	$t8,0x14($s0)
/*  f00da88:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f00da8c:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f00da90:	c7120008 */ 	lwc1	$f18,0x8($t8)
/*  f00da94:	44800000 */ 	mtc1	$zero,$f0
/*  f00da98:	3c013f80 */ 	lui	$at,0x3f80
/*  f00da9c:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f00daa0:	c7b200c0 */ 	lwc1	$f18,0xc0($sp)
/*  f00daa4:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f00daa8:	44050000 */ 	mfc1	$a1,$f0
/*  f00daac:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f00dab0:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f00dab4:	44060000 */ 	mfc1	$a2,$f0
/*  f00dab8:	44070000 */ 	mfc1	$a3,$f0
/*  f00dabc:	c728000c */ 	lwc1	$f8,0xc($t9)
/*  f00dac0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f00dac4:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f00dac8:	8e080014 */ 	lw	$t0,0x14($s0)
/*  f00dacc:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f00dad0:	afa4004c */ 	sw	$a0,0x4c($sp)
/*  f00dad4:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f00dad8:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f00dadc:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f00dae0:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f00dae4:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f00dae8:	46122501 */ 	sub.s	$f20,$f4,$f18
/*  f00daec:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f00daf0:	44819000 */ 	mtc1	$at,$f18
/*  f00daf4:	46065081 */ 	sub.s	$f2,$f10,$f6
/*  f00daf8:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f00dafc:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f00db00:	46044581 */ 	sub.s	$f22,$f8,$f4
/*  f00db04:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f00db08:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f00db0c:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f00db10:	0c005b56 */ 	jal	func00016d58
/*  f00db14:	e7b60018 */ 	swc1	$f22,0x18($sp)
/*  f00db18:	8e090018 */ 	lw	$t1,0x18($s0)
/*  f00db1c:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f00db20:	0c0057c1 */ 	jal	func00015f04
/*  f00db24:	c52c0014 */ 	lwc1	$f12,0x14($t1)
/*  f00db28:	8e0a00a8 */ 	lw	$t2,0xa8($s0)
/*  f00db2c:	3c014780 */ 	lui	$at,0x4780
/*  f00db30:	44811000 */ 	mtc1	$at,$f2
/*  f00db34:	448a5000 */ 	mtc1	$t2,$f10
/*  f00db38:	3c017f1b */ 	lui	$at,%hi(var7f1a8048)
/*  f00db3c:	c4308048 */ 	lwc1	$f16,%lo(var7f1a8048)($at)
/*  f00db40:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f00db44:	8e0b00ac */ 	lw	$t3,0xac($s0)
/*  f00db48:	8e0c00b4 */ 	lw	$t4,0xb4($s0)
/*  f00db4c:	8e0d00bc */ 	lw	$t5,0xbc($s0)
/*  f00db50:	448b9000 */ 	mtc1	$t3,$f18
/*  f00db54:	44800000 */ 	mtc1	$zero,$f0
/*  f00db58:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f00db5c:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f00db60:	4600a306 */ 	mov.s	$f12,$f20
/*  f00db64:	4600b386 */ 	mov.s	$f14,$f22
/*  f00db68:	e60000b0 */ 	swc1	$f0,0xb0($s0)
/*  f00db6c:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f00db70:	46024103 */ 	div.s	$f4,$f8,$f2
/*  f00db74:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f00db78:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f00db7c:	e60400a8 */ 	swc1	$f4,0xa8($s0)
/*  f00db80:	448c2000 */ 	mtc1	$t4,$f4
/*  f00db84:	00000000 */ 	nop
/*  f00db88:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f00db8c:	46109282 */ 	mul.s	$f10,$f18,$f16
/*  f00db90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f00db94:	448d4000 */ 	mtc1	$t5,$f8
/*  f00db98:	c61200a8 */ 	lwc1	$f18,0xa8($s0)
/*  f00db9c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f00dba0:	e61200a4 */ 	swc1	$f18,0xa4($s0)
/*  f00dba4:	46025183 */ 	div.s	$f6,$f10,$f2
/*  f00dba8:	e60400bc */ 	swc1	$f4,0xbc($s0)
/*  f00dbac:	0fc259d4 */ 	jal	func0f096750
/*  f00dbb0:	e60600b4 */ 	swc1	$f6,0xb4($s0)
/*  f00dbb4:	4614a282 */ 	mul.s	$f10,$f20,$f20
/*  f00dbb8:	e60000a0 */ 	swc1	$f0,0xa0($s0)
/*  f00dbbc:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f00dbc0:	0c012974 */ 	jal	sqrtf
/*  f00dbc4:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f00dbc8:	c7ac0058 */ 	lwc1	$f12,0x58($sp)
/*  f00dbcc:	0fc259d4 */ 	jal	func0f096750
/*  f00dbd0:	46000386 */ 	mov.s	$f14,$f0
/*  f00dbd4:	3c017f1b */ 	lui	$at,%hi(var7f1a804c)
/*  f00dbd8:	c428804c */ 	lwc1	$f8,%lo(var7f1a804c)($at)
/*  f00dbdc:	ae0000b8 */ 	sw	$zero,0xb8($s0)
/*  f00dbe0:	46004101 */ 	sub.s	$f4,$f8,$f0
/*  f00dbe4:	e60400c0 */ 	swc1	$f4,0xc0($s0)
/*  f00dbe8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f00dbec:
/*  f00dbec:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f00dbf0:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f00dbf4:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f00dbf8:	03e00008 */ 	jr	$ra
/*  f00dbfc:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
);

GLOBAL_ASM(
glabel func0f00dc00
.late_rodata
glabel var7f1a8050
.word 0x40c907a9
glabel var7f1a8054
.word 0xbfc907a9
.text
/*  f00dc00:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f00dc04:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00dc08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00dc0c:	0fc033b9 */ 	jal	func0f00cee4
/*  f00dc10:	00808025 */ 	or	$s0,$a0,$zero
/*  f00dc14:	8e0e0080 */ 	lw	$t6,0x80($s0)
/*  f00dc18:	8e0f0084 */ 	lw	$t7,0x84($s0)
/*  f00dc1c:	3c014780 */ 	lui	$at,0x4780
/*  f00dc20:	448e2000 */ 	mtc1	$t6,$f4
/*  f00dc24:	44811000 */ 	mtc1	$at,$f2
/*  f00dc28:	3c017f1b */ 	lui	$at,%hi(var7f1a8050)
/*  f00dc2c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00dc30:	c42c8050 */ 	lwc1	$f12,%lo(var7f1a8050)($at)
/*  f00dc34:	448f8000 */ 	mtc1	$t7,$f16
/*  f00dc38:	3c0142c8 */ 	lui	$at,0x42c8
/*  f00dc3c:	44812000 */ 	mtc1	$at,$f4
/*  f00dc40:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f00dc44:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f00dc48:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f00dc4c:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f00dc50:	44800000 */ 	mtc1	$zero,$f0
/*  f00dc54:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f00dc58:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f00dc5c:	a200005f */ 	sb	$zero,0x5f($s0)
/*  f00dc60:	ae030090 */ 	sw	$v1,0x90($s0)
/*  f00dc64:	ae030094 */ 	sw	$v1,0x94($s0)
/*  f00dc68:	ae030098 */ 	sw	$v1,0x98($s0)
/*  f00dc6c:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f00dc70:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f00dc74:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00dc78:	e600006c */ 	swc1	$f0,0x6c($s0)
/*  f00dc7c:	e6000070 */ 	swc1	$f0,0x70($s0)
/*  f00dc80:	e6000060 */ 	swc1	$f0,0x60($s0)
/*  f00dc84:	e6000078 */ 	swc1	$f0,0x78($s0)
/*  f00dc88:	e600007c */ 	swc1	$f0,0x7c($s0)
/*  f00dc8c:	e6000074 */ 	swc1	$f0,0x74($s0)
/*  f00dc90:	e6000088 */ 	swc1	$f0,0x88($s0)
/*  f00dc94:	e600008c */ 	swc1	$f0,0x8c($s0)
/*  f00dc98:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f00dc9c:	e60a0080 */ 	swc1	$f10,0x80($s0)
/*  f00dca0:	44985000 */ 	mtc1	$t8,$f10
/*  f00dca4:	44993000 */ 	mtc1	$t9,$f6
/*  f00dca8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f00dcac:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*  f00dcb0:	e6080084 */ 	swc1	$f8,0x84($s0)
/*  f00dcb4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f00dcb8:	46029103 */ 	div.s	$f4,$f18,$f2
/*  f00dcbc:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f00dcc0:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f00dcc4:	e6040064 */ 	swc1	$f4,0x64($s0)
/*  f00dcc8:	0c0048f2 */ 	jal	malloc
/*  f00dccc:	e6100068 */ 	swc1	$f16,0x68($s0)
/*  f00dcd0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f00dcd4:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f00dcd8:	a0430000 */ 	sb	$v1,0x0($v0)
/*  f00dcdc:	8604005c */ 	lh	$a0,0x5c($s0)
/*  f00dce0:	44800000 */ 	mtc1	$zero,$f0
/*  f00dce4:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f00dce8:	a200005e */ 	sb	$zero,0x5e($s0)
/*  f00dcec:	a20800a9 */ 	sb	$t0,0xa9($s0)
/*  f00dcf0:	0480001f */ 	bltz	$a0,.L0f00dd70
/*  f00dcf4:	e60000a0 */ 	swc1	$f0,0xa0($s0)
/*  f00dcf8:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f00dcfc:	0fc456ac */ 	jal	padUnpack
/*  f00dd00:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f00dd04:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f00dd08:	c7a6002c */ 	lwc1	$f6,0x2c($sp)
/*  f00dd0c:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*  f00dd10:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f00dd14:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f00dd18:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f00dd1c:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f00dd20:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f00dd24:	e7aa0084 */ 	swc1	$f10,0x84($sp)
/*  f00dd28:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f00dd2c:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f00dd30:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f00dd34:	0fc259d4 */ 	jal	func0f096750
/*  f00dd38:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f00dd3c:	c7a20088 */ 	lwc1	$f2,0x88($sp)
/*  f00dd40:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f00dd44:	e6000060 */ 	swc1	$f0,0x60($s0)
/*  f00dd48:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f00dd4c:	00000000 */ 	nop
/*  f00dd50:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f00dd54:	0c012974 */ 	jal	sqrtf
/*  f00dd58:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f00dd5c:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f00dd60:	0fc259d4 */ 	jal	func0f096750
/*  f00dd64:	46000386 */ 	mov.s	$f14,$f0
/*  f00dd68:	10000007 */ 	b	.L0f00dd88
/*  f00dd6c:	e6000074 */ 	swc1	$f0,0x74($s0)
.L0f00dd70:
/*  f00dd70:	86090004 */ 	lh	$t1,0x4($s0)
/*  f00dd74:	24010144 */ 	addiu	$at,$zero,0x144
/*  f00dd78:	15210003 */ 	bne	$t1,$at,.L0f00dd88
/*  f00dd7c:	3c017f1b */ 	lui	$at,%hi(var7f1a8054)
/*  f00dd80:	c4288054 */ 	lwc1	$f8,%lo(var7f1a8054)($at)
/*  f00dd84:	e6080074 */ 	swc1	$f8,0x74($s0)
.L0f00dd88:
/*  f00dd88:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00dd8c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00dd90:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f00dd94:	03e00008 */ 	jr	$ra
/*  f00dd98:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00dd9c
/*  f00dd9c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00dda0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00dda4:	0fc033b9 */ 	jal	func0f00cee4
/*  f00dda8:	00000000 */ 	nop
/*  f00ddac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00ddb0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00ddb4:	03e00008 */ 	jr	$ra
/*  f00ddb8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00ddbc
.late_rodata
glabel var7f1a8058
.word 0x3ebba0c0
.text
/*  f00ddbc:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f00ddc0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00ddc4:	00808025 */ 	or	$s0,$a0,$zero
/*  f00ddc8:	3c0e800a */ 	lui	$t6,%hi(var8009ce98)
/*  f00ddcc:	25cece98 */ 	addiu	$t6,$t6,%lo(var8009ce98)
/*  f00ddd0:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f00ddd4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00ddd8:	afa500cc */ 	sw	$a1,0xcc($sp)
/*  f00dddc:	00804025 */ 	or	$t0,$a0,$zero
/*  f00dde0:	25d9006c */ 	addiu	$t9,$t6,0x6c
.L0f00dde4:
/*  f00dde4:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00dde8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00ddec:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00ddf0:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00ddf4:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f00ddf8:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00ddfc:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f00de00:	15d9fff8 */ 	bne	$t6,$t9,.L0f00dde4
/*  f00de04:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00de08:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00de0c:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00de10:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f00de14:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f00de18:	0fc1fe49 */ 	jal	imageSlotSetImage
/*  f00de1c:	920500d3 */ 	lbu	$a1,0xd3($s0)
/*  f00de20:	86090006 */ 	lh	$t1,0x6($s0)
/*  f00de24:	8fa500cc */ 	lw	$a1,0xcc($sp)
/*  f00de28:	05210085 */ 	bgez	$t1,.L0f00e040
/*  f00de2c:	00000000 */ 	nop
/*  f00de30:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f00de34:	314b8000 */ 	andi	$t3,$t2,0x8000
/*  f00de38:	15600081 */ 	bnez	$t3,.L0f00e040
/*  f00de3c:	00000000 */ 	nop
/*  f00de40:	860c0004 */ 	lh	$t4,0x4($s0)
/*  f00de44:	afac00bc */ 	sw	$t4,0xbc($sp)
/*  f00de48:	860d00d0 */ 	lh	$t5,0xd0($s0)
/*  f00de4c:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f00de50:	01a52021 */ 	addu	$a0,$t5,$a1
/*  f00de54:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f00de58:	0fc2486d */ 	jal	propLoad
/*  f00de5c:	8fa400bc */ 	lw	$a0,0xbc($sp)
/*  f00de60:	96180000 */ 	lhu	$t8,0x0($s0)
/*  f00de64:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f00de68:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f00de6c:	44982000 */ 	mtc1	$t8,$f4
/*  f00de70:	3c014f80 */ 	lui	$at,0x4f80
/*  f00de74:	07010004 */ 	bgez	$t8,.L0f00de88
/*  f00de78:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00de7c:	44814000 */ 	mtc1	$at,$f8
/*  f00de80:	00000000 */ 	nop
/*  f00de84:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f00de88:
/*  f00de88:	3c013b80 */ 	lui	$at,0x3b80
/*  f00de8c:	44815000 */ 	mtc1	$at,$f10
/*  f00de90:	8c6f0318 */ 	lw	$t7,0x318($v1)
/*  f00de94:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f00de98:	15e00004 */ 	bnez	$t7,.L0f00deac
/*  f00de9c:	e7b000b0 */ 	swc1	$f16,0xb0($sp)
/*  f00dea0:	8c79031c */ 	lw	$t9,0x31c($v1)
/*  f00dea4:	13200004 */ 	beqz	$t9,.L0f00deb8
/*  f00dea8:	00000000 */ 	nop
.L0f00deac:
/*  f00deac:	920e0002 */ 	lbu	$t6,0x2($s0)
/*  f00deb0:	35c80004 */ 	ori	$t0,$t6,0x4
/*  f00deb4:	a2080002 */ 	sb	$t0,0x2($s0)
.L0f00deb8:
/*  f00deb8:	0fc1a954 */ 	jal	func0f06a550
/*  f00debc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00dec0:	0fc1a1bc */ 	jal	func0f0686f0
/*  f00dec4:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f00dec8:	ae020048 */ 	sw	$v0,0x48($s0)
/*  f00decc:	8fa900b4 */ 	lw	$t1,0xb4($sp)
/*  f00ded0:	5120005e */ 	beqzl	$t1,.L0f00e04c
/*  f00ded4:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f00ded8:	5040005c */ 	beqzl	$v0,.L0f00e04c
/*  f00dedc:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f00dee0:	8e0b0040 */ 	lw	$t3,0x40($s0)
/*  f00dee4:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00dee8:	356c0040 */ 	ori	$t4,$t3,0x40
/*  f00deec:	ae0c0040 */ 	sw	$t4,0x40($s0)
/*  f00def0:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f00def4:	c4920014 */ 	lwc1	$f18,0x14($a0)
/*  f00def8:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f00defc:	44054000 */ 	mfc1	$a1,$f8
/*  f00df00:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00df04:	00000000 */ 	nop
/*  f00df08:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f00df0c:	8e180018 */ 	lw	$t8,0x18($s0)
/*  f00df10:	24010001 */ 	addiu	$at,$zero,0x1
/*  f00df14:	8c6d0018 */ 	lw	$t5,0x18($v1)
/*  f00df18:	af0d0018 */ 	sw	$t5,0x18($t8)
/*  f00df1c:	820200d2 */ 	lb	$v0,0xd2($s0)
/*  f00df20:	14400008 */ 	bnez	$v0,.L0f00df44
/*  f00df24:	00000000 */ 	nop
/*  f00df28:	8c6f0018 */ 	lw	$t7,0x18($v1)
/*  f00df2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f00df30:	0c006a47 */ 	jal	modelGetPart
/*  f00df34:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f00df38:	8e190018 */ 	lw	$t9,0x18($s0)
/*  f00df3c:	1000001a */ 	b	.L0f00dfa8
/*  f00df40:	af22001c */ 	sw	$v0,0x1c($t9)
.L0f00df44:
/*  f00df44:	54410009 */ 	bnel	$v0,$at,.L0f00df6c
/*  f00df48:	24010002 */ 	addiu	$at,$zero,0x2
/*  f00df4c:	8c6e0018 */ 	lw	$t6,0x18($v1)
/*  f00df50:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00df54:	0c006a47 */ 	jal	modelGetPart
/*  f00df58:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f00df5c:	8e080018 */ 	lw	$t0,0x18($s0)
/*  f00df60:	10000011 */ 	b	.L0f00dfa8
/*  f00df64:	ad02001c */ 	sw	$v0,0x1c($t0)
/*  f00df68:	24010002 */ 	addiu	$at,$zero,0x2
.L0f00df6c:
/*  f00df6c:	54410009 */ 	bnel	$v0,$at,.L0f00df94
/*  f00df70:	8c6b0018 */ 	lw	$t3,0x18($v1)
/*  f00df74:	8c690018 */ 	lw	$t1,0x18($v1)
/*  f00df78:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f00df7c:	0c006a47 */ 	jal	modelGetPart
/*  f00df80:	8d240008 */ 	lw	$a0,0x8($t1)
/*  f00df84:	8e0a0018 */ 	lw	$t2,0x18($s0)
/*  f00df88:	10000007 */ 	b	.L0f00dfa8
/*  f00df8c:	ad42001c */ 	sw	$v0,0x1c($t2)
/*  f00df90:	8c6b0018 */ 	lw	$t3,0x18($v1)
.L0f00df94:
/*  f00df94:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f00df98:	0c006a47 */ 	jal	modelGetPart
/*  f00df9c:	8d640008 */ 	lw	$a0,0x8($t3)
/*  f00dfa0:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f00dfa4:	ad82001c */ 	sw	$v0,0x1c($t4)
.L0f00dfa8:
/*  f00dfa8:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f00dfac:	8fa400b4 */ 	lw	$a0,0xb4($sp)
/*  f00dfb0:	0fc181a6 */ 	jal	propReparent
/*  f00dfb4:	8da50014 */ 	lw	$a1,0x14($t5)
/*  f00dfb8:	3c017f1b */ 	lui	$at,%hi(var7f1a8058)
/*  f00dfbc:	c42c8058 */ 	lwc1	$f12,%lo(var7f1a8058)($at)
/*  f00dfc0:	0c0058ba */ 	jal	func000162e8
/*  f00dfc4:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f00dfc8:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f00dfcc:	8e180018 */ 	lw	$t8,0x18($s0)
/*  f00dfd0:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f00dfd4:	8df90018 */ 	lw	$t9,0x18($t7)
/*  f00dfd8:	c7060014 */ 	lwc1	$f6,0x14($t8)
/*  f00dfdc:	c72a0014 */ 	lwc1	$f10,0x14($t9)
/*  f00dfe0:	0c0057c1 */ 	jal	func00015f04
/*  f00dfe4:	460a3303 */ 	div.s	$f12,$f6,$f10
/*  f00dfe8:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00dfec:	0c006b43 */ 	jal	modelGetRootPosition
/*  f00dff0:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f00dff4:	c7b000a4 */ 	lwc1	$f16,0xa4($sp)
/*  f00dff8:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f00dffc:	c7a600ac */ 	lwc1	$f6,0xac($sp)
/*  f00e000:	46008487 */ 	neg.s	$f18,$f16
/*  f00e004:	46002207 */ 	neg.s	$f8,$f4
/*  f00e008:	46003287 */ 	neg.s	$f10,$f6
/*  f00e00c:	e7b200a4 */ 	swc1	$f18,0xa4($sp)
/*  f00e010:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f00e014:	e7aa00ac */ 	swc1	$f10,0xac($sp)
/*  f00e018:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f00e01c:	0c0059b7 */ 	jal	func000166dc
/*  f00e020:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f00e024:	8e060048 */ 	lw	$a2,0x48($s0)
/*  f00e028:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f00e02c:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f00e030:	0c0056f9 */ 	jal	func00015be4
/*  f00e034:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f00e038:	10000004 */ 	b	.L0f00e04c
/*  f00e03c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f00e040:
/*  f00e040:	0fc033b9 */ 	jal	func0f00cee4
/*  f00e044:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e048:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f00e04c:
/*  f00e04c:	50400009 */ 	beqzl	$v0,.L0f00e074
/*  f00e050:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00e054:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f00e058:	000e4040 */ 	sll	$t0,$t6,0x1
/*  f00e05c:	05030005 */ 	bgezl	$t0,.L0f00e074
/*  f00e060:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00e064:	90490001 */ 	lbu	$t1,0x1($v0)
/*  f00e068:	352a0001 */ 	ori	$t2,$t1,0x1
/*  f00e06c:	a04a0001 */ 	sb	$t2,0x1($v0)
/*  f00e070:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f00e074:
/*  f00e074:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00e078:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f00e07c:	03e00008 */ 	jr	$ra
/*  f00e080:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e084
/*  f00e084:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00e088:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00e08c:	00808025 */ 	or	$s0,$a0,$zero
/*  f00e090:	3c0e800a */ 	lui	$t6,%hi(var8009ce98)
/*  f00e094:	25cece98 */ 	addiu	$t6,$t6,%lo(var8009ce98)
/*  f00e098:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f00e09c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00e0a0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f00e0a4:	00804025 */ 	or	$t0,$a0,$zero
/*  f00e0a8:	25d9006c */ 	addiu	$t9,$t6,0x6c
.L0f00e0ac:
/*  f00e0ac:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00e0b0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00e0b4:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00e0b8:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00e0bc:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f00e0c0:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00e0c4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f00e0c8:	15d9fff8 */ 	bne	$t6,$t9,.L0f00e0ac
/*  f00e0cc:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00e0d0:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f00e0d4:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00e0d8:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f00e0dc:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f00e0e0:	0fc1fe49 */ 	jal	imageSlotSetImage
/*  f00e0e4:	9205022c */ 	lbu	$a1,0x22c($s0)
/*  f00e0e8:	3c09800a */ 	lui	$t1,%hi(var8009ce98)
/*  f00e0ec:	2529ce98 */ 	addiu	$t1,$t1,%lo(var8009ce98)
/*  f00e0f0:	260400d0 */ 	addiu	$a0,$s0,0xd0
/*  f00e0f4:	00806825 */ 	or	$t5,$a0,$zero
/*  f00e0f8:	252c006c */ 	addiu	$t4,$t1,0x6c
.L0f00e0fc:
/*  f00e0fc:	8d210000 */ 	lw	$at,0x0($t1)
/*  f00e100:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f00e104:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f00e108:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f00e10c:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*  f00e110:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f00e114:	8d21fffc */ 	lw	$at,-0x4($t1)
/*  f00e118:	152cfff8 */ 	bne	$t1,$t4,.L0f00e0fc
/*  f00e11c:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f00e120:	8d210000 */ 	lw	$at,0x0($t1)
/*  f00e124:	ada10000 */ 	sw	$at,0x0($t5)
/*  f00e128:	8d2c0004 */ 	lw	$t4,0x4($t1)
/*  f00e12c:	adac0004 */ 	sw	$t4,0x4($t5)
/*  f00e130:	0fc1fe49 */ 	jal	imageSlotSetImage
/*  f00e134:	9205022d */ 	lbu	$a1,0x22d($s0)
/*  f00e138:	3c18800a */ 	lui	$t8,%hi(var8009ce98)
/*  f00e13c:	2718ce98 */ 	addiu	$t8,$t8,%lo(var8009ce98)
/*  f00e140:	26040144 */ 	addiu	$a0,$s0,0x144
/*  f00e144:	00804025 */ 	or	$t0,$a0,$zero
/*  f00e148:	270e006c */ 	addiu	$t6,$t8,0x6c
.L0f00e14c:
/*  f00e14c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00e150:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f00e154:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f00e158:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f00e15c:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f00e160:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f00e164:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f00e168:	170efff8 */ 	bne	$t8,$t6,.L0f00e14c
/*  f00e16c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f00e170:	8f010000 */ 	lw	$at,0x0($t8)
/*  f00e174:	ad010000 */ 	sw	$at,0x0($t0)
/*  f00e178:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f00e17c:	ad0e0004 */ 	sw	$t6,0x4($t0)
/*  f00e180:	0fc1fe49 */ 	jal	imageSlotSetImage
/*  f00e184:	9205022e */ 	lbu	$a1,0x22e($s0)
/*  f00e188:	3c0b800a */ 	lui	$t3,%hi(var8009ce98)
/*  f00e18c:	256bce98 */ 	addiu	$t3,$t3,%lo(var8009ce98)
/*  f00e190:	260401b8 */ 	addiu	$a0,$s0,0x1b8
/*  f00e194:	00806825 */ 	or	$t5,$a0,$zero
/*  f00e198:	2569006c */ 	addiu	$t1,$t3,0x6c
.L0f00e19c:
/*  f00e19c:	8d610000 */ 	lw	$at,0x0($t3)
/*  f00e1a0:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f00e1a4:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f00e1a8:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*  f00e1ac:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f00e1b0:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*  f00e1b4:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f00e1b8:	1569fff8 */ 	bne	$t3,$t1,.L0f00e19c
/*  f00e1bc:	ada1fffc */ 	sw	$at,-0x4($t5)
/*  f00e1c0:	8d610000 */ 	lw	$at,0x0($t3)
/*  f00e1c4:	ada10000 */ 	sw	$at,0x0($t5)
/*  f00e1c8:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f00e1cc:	ada90004 */ 	sw	$t1,0x4($t5)
/*  f00e1d0:	0fc1fe49 */ 	jal	imageSlotSetImage
/*  f00e1d4:	9205022f */ 	lbu	$a1,0x22f($s0)
/*  f00e1d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e1dc:	0fc033b9 */ 	jal	func0f00cee4
/*  f00e1e0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f00e1e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00e1e8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00e1ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00e1f0:	03e00008 */ 	jr	$ra
/*  f00e1f4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e1f8
/*  f00e1f8:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f00e1fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00e200:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f00e204:	0fc457cd */ 	jal	padGetCentre
/*  f00e208:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f00e20c:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f00e210:	24050028 */ 	addiu	$a1,$zero,0x28
/*  f00e214:	0fc456ac */ 	jal	padUnpack
/*  f00e218:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f00e21c:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f00e220:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f00e224:	3c013f00 */ 	lui	$at,0x3f00
/*  f00e228:	44815000 */ 	mtc1	$at,$f10
/*  f00e22c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f00e230:	3c014120 */ 	lui	$at,0x4120
/*  f00e234:	44813000 */ 	mtc1	$at,$f6
/*  f00e238:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f00e23c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f00e240:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*  f00e244:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f00e248:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f00e24c:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f00e250:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f00e254:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f00e258:	46004082 */ 	mul.s	$f2,$f8,$f0
/*  f00e25c:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f00e260:	46002302 */ 	mul.s	$f12,$f4,$f0
/*  f00e264:	46101280 */ 	add.s	$f10,$f2,$f16
/*  f00e268:	46004382 */ 	mul.s	$f14,$f8,$f0
/*  f00e26c:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f00e270:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*  f00e274:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f00e278:	46028401 */ 	sub.s	$f16,$f16,$f2
/*  f00e27c:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f00e280:	460c9481 */ 	sub.s	$f18,$f18,$f12
/*  f00e284:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f00e288:	460a7100 */ 	add.s	$f4,$f14,$f10
/*  f00e28c:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f00e290:	460e5181 */ 	sub.s	$f6,$f10,$f14
/*  f00e294:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f00e298:	0fc593a3 */ 	jal	func0f164e8c
/*  f00e29c:	e7a60090 */ 	swc1	$f6,0x90($sp)
/*  f00e2a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00e2a4:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f00e2a8:	03e00008 */ 	jr	$ra
/*  f00e2ac:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e2b0
/*  f00e2b0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f00e2b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00e2b8:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f00e2bc:	0fc457cd */ 	jal	padGetCentre
/*  f00e2c0:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f00e2c4:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f00e2c8:	24050030 */ 	addiu	$a1,$zero,0x30
/*  f00e2cc:	0fc456ac */ 	jal	padUnpack
/*  f00e2d0:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f00e2d4:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f00e2d8:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f00e2dc:	3c013f00 */ 	lui	$at,0x3f00
/*  f00e2e0:	44815000 */ 	mtc1	$at,$f10
/*  f00e2e4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f00e2e8:	3c014120 */ 	lui	$at,0x4120
/*  f00e2ec:	44813000 */ 	mtc1	$at,$f6
/*  f00e2f0:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f00e2f4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f00e2f8:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f00e2fc:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f00e300:	27a40088 */ 	addiu	$a0,$sp,0x88
/*  f00e304:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f00e308:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f00e30c:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f00e310:	46004082 */ 	mul.s	$f2,$f8,$f0
/*  f00e314:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f00e318:	46002302 */ 	mul.s	$f12,$f4,$f0
/*  f00e31c:	46101280 */ 	add.s	$f10,$f2,$f16
/*  f00e320:	46004382 */ 	mul.s	$f14,$f8,$f0
/*  f00e324:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f00e328:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*  f00e32c:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f00e330:	46028401 */ 	sub.s	$f16,$f16,$f2
/*  f00e334:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f00e338:	460c9481 */ 	sub.s	$f18,$f18,$f12
/*  f00e33c:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f00e340:	460a7100 */ 	add.s	$f4,$f14,$f10
/*  f00e344:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f00e348:	460e5181 */ 	sub.s	$f6,$f10,$f14
/*  f00e34c:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f00e350:	0fc593a3 */ 	jal	func0f164e8c
/*  f00e354:	e7a60090 */ 	swc1	$f6,0x90($sp)
/*  f00e358:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00e35c:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f00e360:	03e00008 */ 	jr	$ra
/*  f00e364:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e368
.late_rodata
glabel var7f1a805c
.word 0x3fc907a9
glabel var7f1a8060
.word 0x3fc907a9
glabel var7f1a8064
.word 0x358637bd
.text
/*  f00e368:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f00e36c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f00e370:	00808025 */ 	or	$s0,$a0,$zero
/*  f00e374:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e378:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f00e37c:	84840004 */ 	lh	$a0,0x4($a0)
/*  f00e380:	240effff */ 	addiu	$t6,$zero,-1
/*  f00e384:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f00e388:	0fc2486d */ 	jal	propLoad
/*  f00e38c:	afa401c0 */ 	sw	$a0,0x1c0($sp)
/*  f00e390:	960f0070 */ 	lhu	$t7,0x70($s0)
/*  f00e394:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f00e398:	53000004 */ 	beqzl	$t8,.L0f00e3ac
/*  f00e39c:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f00e3a0:	0fc4581a */ 	jal	func0f116068
/*  f00e3a4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3a8:	8e190008 */ 	lw	$t9,0x8($s0)
.L0f00e3ac:
/*  f00e3ac:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f00e3b0:	05030005 */ 	bgezl	$t0,.L0f00e3c8
/*  f00e3b4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3b8:	0fc038ac */ 	jal	func0f00e2b0
/*  f00e3bc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3c0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f00e3c4:	86040006 */ 	lh	$a0,0x6($s0)
.L0f00e3c8:
/*  f00e3c8:	2405007e */ 	addiu	$a1,$zero,0x7e
/*  f00e3cc:	0fc456ac */ 	jal	padUnpack
/*  f00e3d0:	27a60168 */ 	addiu	$a2,$sp,0x168
/*  f00e3d4:	3c018006 */ 	lui	$at,%hi(var80061be0)
/*  f00e3d8:	c42c1be0 */ 	lwc1	$f12,%lo(var80061be0)($at)
/*  f00e3dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e3e0:	44812000 */ 	mtc1	$at,$f4
/*  f00e3e4:	c7a60198 */ 	lwc1	$f6,0x198($sp)
/*  f00e3e8:	27a50168 */ 	addiu	$a1,$sp,0x168
/*  f00e3ec:	460c2032 */ 	c.eq.s	$f4,$f12
/*  f00e3f0:	00000000 */ 	nop
/*  f00e3f4:	4503005b */ 	bc1tl	.L0f00e564
/*  f00e3f8:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
/*  f00e3fc:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f00e400:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f00e404:	8fa301bc */ 	lw	$v1,0x1bc($sp)
/*  f00e408:	3c0a800a */ 	lui	$t2,%hi(var800a4ccc)
/*  f00e40c:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00e410:	00034880 */ 	sll	$t1,$v1,0x2
/*  f00e414:	01234821 */ 	addu	$t1,$t1,$v1
/*  f00e418:	e7a80198 */ 	swc1	$f8,0x198($sp)
/*  f00e41c:	0460004e */ 	bltz	$v1,.L0f00e558
/*  f00e420:	e7b0019c */ 	swc1	$f16,0x19c($sp)
/*  f00e424:	8d4a4ccc */ 	lw	$t2,%lo(var800a4ccc)($t2)
/*  f00e428:	00094880 */ 	sll	$t1,$t1,0x2
/*  f00e42c:	c7a40170 */ 	lwc1	$f4,0x170($sp)
/*  f00e430:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f00e434:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e438:	c7aa016c */ 	lwc1	$f10,0x16c($sp)
/*  f00e43c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f00e440:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f00e444:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f00e448:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e44c:	c44e000c */ 	lwc1	$f14,0xc($v0)
/*  f00e450:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00e454:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f00e458:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f00e45c:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f00e460:	44812000 */ 	mtc1	$at,$f4
/*  f00e464:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f00e468:	46046181 */ 	sub.s	$f6,$f12,$f4
/*  f00e46c:	460e0481 */ 	sub.s	$f18,$f0,$f14
/*  f00e470:	46069002 */ 	mul.s	$f0,$f18,$f6
/*  f00e474:	00000000 */ 	nop
/*  f00e478:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f00e47c:	e7aa0150 */ 	swc1	$f10,0x150($sp)
/*  f00e480:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e484:	46002482 */ 	mul.s	$f18,$f4,$f0
/*  f00e488:	c7a40150 */ 	lwc1	$f4,0x150($sp)
/*  f00e48c:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f00e490:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f00e494:	c7b2018c */ 	lwc1	$f18,0x18c($sp)
/*  f00e498:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f00e49c:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f00e4a0:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f00e4a4:	c7a40190 */ 	lwc1	$f4,0x190($sp)
/*  f00e4a8:	c7aa0154 */ 	lwc1	$f10,0x154($sp)
/*  f00e4ac:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f00e4b0:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f00e4b4:	46123280 */ 	add.s	$f10,$f6,$f18
/*  f00e4b8:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f00e4bc:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f00e4c0:	460a9000 */ 	add.s	$f0,$f18,$f10
/*  f00e4c4:	c7aa0150 */ 	lwc1	$f10,0x150($sp)
/*  f00e4c8:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f00e4cc:	c7a80180 */ 	lwc1	$f8,0x180($sp)
/*  f00e4d0:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e4d4:	e7a40198 */ 	swc1	$f4,0x198($sp)
/*  f00e4d8:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f00e4dc:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e4e0:	e7b2019c */ 	swc1	$f18,0x19c($sp)
/*  f00e4e4:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e4e8:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f00e4ec:	c7b00188 */ 	lwc1	$f16,0x188($sp)
/*  f00e4f0:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e4f4:	c7b001a4 */ 	lwc1	$f16,0x1a4($sp)
/*  f00e4f8:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f00e4fc:	c7a401a0 */ 	lwc1	$f4,0x1a0($sp)
/*  f00e500:	46089000 */ 	add.s	$f0,$f18,$f8
/*  f00e504:	c7a80150 */ 	lwc1	$f8,0x150($sp)
/*  f00e508:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e50c:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e510:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f00e514:	c7a40174 */ 	lwc1	$f4,0x174($sp)
/*  f00e518:	e7b201a4 */ 	swc1	$f18,0x1a4($sp)
/*  f00e51c:	c7b20178 */ 	lwc1	$f18,0x178($sp)
/*  f00e520:	e7aa01a0 */ 	swc1	$f10,0x1a0($sp)
/*  f00e524:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f00e528:	00000000 */ 	nop
/*  f00e52c:	46128202 */ 	mul.s	$f8,$f16,$f18
/*  f00e530:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e534:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e538:	c7b001ac */ 	lwc1	$f16,0x1ac($sp)
/*  f00e53c:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f00e540:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f00e544:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f00e548:	46008180 */ 	add.s	$f6,$f16,$f0
/*  f00e54c:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f00e550:	e7a601ac */ 	swc1	$f6,0x1ac($sp)
/*  f00e554:	e7a801a8 */ 	swc1	$f8,0x1a8($sp)
.L0f00e558:
/*  f00e558:	0fc45864 */ 	jal	padCopyBboxFromPad
/*  f00e55c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e560:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
.L0f00e564:
/*  f00e564:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f00e568:	3c048008 */ 	lui	$a0,%hi(g_Props)
/*  f00e56c:	196000e1 */ 	blez	$t3,.L0f00e8f4
/*  f00e570:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f00e574:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f00e578:	0fc1a25b */ 	jal	func0f06896c
/*  f00e57c:	8c84b06c */ 	lw	$a0,%lo(g_Props)($a0)
/*  f00e580:	c7b20174 */ 	lwc1	$f18,0x174($sp)
/*  f00e584:	44800000 */ 	mtc1	$zero,$f0
/*  f00e588:	c7aa0178 */ 	lwc1	$f10,0x178($sp)
/*  f00e58c:	46009107 */ 	neg.s	$f4,$f18
/*  f00e590:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e594:	46005207 */ 	neg.s	$f8,$f10
/*  f00e598:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f00e59c:	c7a40184 */ 	lwc1	$f4,0x184($sp)
/*  f00e5a0:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e5a4:	c7b20180 */ 	lwc1	$f18,0x180($sp)
/*  f00e5a8:	46008187 */ 	neg.s	$f6,$f16
/*  f00e5ac:	44050000 */ 	mfc1	$a1,$f0
/*  f00e5b0:	44060000 */ 	mfc1	$a2,$f0
/*  f00e5b4:	44070000 */ 	mfc1	$a3,$f0
/*  f00e5b8:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f00e5bc:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f00e5c0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f00e5c4:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e5c8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f00e5cc:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f00e5d0:	0c005b56 */ 	jal	func00016d58
/*  f00e5d4:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f00e5d8:	3c017f1b */ 	lui	$at,%hi(var7f1a805c)
/*  f00e5dc:	c42c805c */ 	lwc1	$f12,%lo(var7f1a805c)($at)
/*  f00e5e0:	0c0058ba */ 	jal	func000162e8
/*  f00e5e4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e5e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8060)
/*  f00e5ec:	c42c8060 */ 	lwc1	$f12,%lo(var7f1a8060)($at)
/*  f00e5f0:	0c005900 */ 	jal	func00016400
/*  f00e5f4:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f00e5f8:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f00e5fc:	0c00567f */ 	jal	func000159fc
/*  f00e600:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e604:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e608:	0c00567f */ 	jal	func000159fc
/*  f00e60c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e610:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e614:	0fc457cd */ 	jal	padGetCentre
/*  f00e618:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f00e61c:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f00e620:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e624:	c7b001a0 */ 	lwc1	$f16,0x1a0($sp)
/*  f00e628:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e62c:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e630:	46104181 */ 	sub.s	$f6,$f8,$f16
/*  f00e634:	c7b001a8 */ 	lwc1	$f16,0x1a8($sp)
/*  f00e638:	c7a801ac */ 	lwc1	$f8,0x1ac($sp)
/*  f00e63c:	46049281 */ 	sub.s	$f10,$f18,$f4
/*  f00e640:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f00e644:	3c017f1b */ 	lui	$at,%hi(var7f1a8064)
/*  f00e648:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f00e64c:	c4208064 */ 	lwc1	$f0,%lo(var7f1a8064)($at)
/*  f00e650:	c7b00198 */ 	lwc1	$f16,0x198($sp)
/*  f00e654:	460a3303 */ 	div.s	$f12,$f6,$f10
/*  f00e658:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f00e65c:	c7a8019c */ 	lwc1	$f8,0x19c($sp)
/*  f00e660:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e664:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f00e668:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f00e66c:	46104101 */ 	sub.s	$f4,$f8,$f16
/*  f00e670:	460a9083 */ 	div.s	$f2,$f18,$f10
/*  f00e674:	c4520014 */ 	lwc1	$f18,0x14($v0)
/*  f00e678:	4600603e */ 	c.le.s	$f12,$f0
/*  f00e67c:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f00e680:	45010008 */ 	bc1t	.L0f00e6a4
/*  f00e684:	460a2383 */ 	div.s	$f14,$f4,$f10
/*  f00e688:	4600103e */ 	c.le.s	$f2,$f0
/*  f00e68c:	00000000 */ 	nop
/*  f00e690:	45030005 */ 	bc1tl	.L0f00e6a8
/*  f00e694:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e698:	4600703e */ 	c.le.s	$f14,$f0
/*  f00e69c:	00000000 */ 	nop
/*  f00e6a0:	45000005 */ 	bc1f	.L0f00e6b8
.L0f00e6a4:
/*  f00e6a4:	3c013f80 */ 	lui	$at,0x3f80
.L0f00e6a8:
/*  f00e6a8:	44816000 */ 	mtc1	$at,$f12
/*  f00e6ac:	00000000 */ 	nop
/*  f00e6b0:	46006386 */ 	mov.s	$f14,$f12
/*  f00e6b4:	46006086 */ 	mov.s	$f2,$f12
.L0f00e6b8:
/*  f00e6b8:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f00e6bc:	e7ac0050 */ 	swc1	$f12,0x50($sp)
/*  f00e6c0:	0c005789 */ 	jal	func00015e24
/*  f00e6c4:	e7ae0048 */ 	swc1	$f14,0x48($sp)
/*  f00e6c8:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e6cc:	0c0057a0 */ 	jal	func00015e80
/*  f00e6d0:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6d4:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f00e6d8:	0c0057b7 */ 	jal	func00015edc
/*  f00e6dc:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6e0:	c7a80168 */ 	lwc1	$f8,0x168($sp)
/*  f00e6e4:	c7b0016c */ 	lwc1	$f16,0x16c($sp)
/*  f00e6e8:	c7a60170 */ 	lwc1	$f6,0x170($sp)
/*  f00e6ec:	8fae01b0 */ 	lw	$t6,0x1b0($sp)
/*  f00e6f0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f00e6f4:	a7af00ee */ 	sh	$t7,0xee($sp)
/*  f00e6f8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f00e6fc:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f00e700:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f00e704:	a7ae00ec */ 	sh	$t6,0xec($sp)
/*  f00e708:	96020072 */ 	lhu	$v0,0x72($s0)
/*  f00e70c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f00e710:	c7b201ac */ 	lwc1	$f18,0x1ac($sp)
/*  f00e714:	10410004 */ 	beq	$v0,$at,.L0f00e728
/*  f00e718:	c7a401a8 */ 	lwc1	$f4,0x1a8($sp)
/*  f00e71c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00e720:	1441000e */ 	bne	$v0,$at,.L0f00e75c
/*  f00e724:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
.L0f00e728:
/*  f00e728:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f00e72c:	c7aa0174 */ 	lwc1	$f10,0x174($sp)
/*  f00e730:	c7b00178 */ 	lwc1	$f16,0x178($sp)
/*  f00e734:	c7b2017c */ 	lwc1	$f18,0x17c($sp)
/*  f00e738:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e73c:	00000000 */ 	nop
/*  f00e740:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e744:	00000000 */ 	nop
/*  f00e748:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e74c:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f00e750:	e7a60058 */ 	swc1	$f6,0x58($sp)
/*  f00e754:	1000000e */ 	b	.L0f00e790
/*  f00e758:	e7a4005c */ 	swc1	$f4,0x5c($sp)
.L0f00e75c:
/*  f00e75c:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e760:	c7b00180 */ 	lwc1	$f16,0x180($sp)
/*  f00e764:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e768:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f00e76c:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e770:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e774:	00000000 */ 	nop
/*  f00e778:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e77c:	00000000 */ 	nop
/*  f00e780:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e784:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f00e788:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f00e78c:	e7a8005c */ 	swc1	$f8,0x5c($sp)
.L0f00e790:
/*  f00e790:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f00e794:	3c014780 */ 	lui	$at,0x4780
/*  f00e798:	44810000 */ 	mtc1	$at,$f0
/*  f00e79c:	44988000 */ 	mtc1	$t8,$f16
/*  f00e7a0:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f00e7a4:	8e080064 */ 	lw	$t0,0x64($s0)
/*  f00e7a8:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7ac:	44992000 */ 	mtc1	$t9,$f4
/*  f00e7b0:	44888000 */ 	mtc1	$t0,$f16
/*  f00e7b4:	3c014c7a */ 	lui	$at,0x4c7a
/*  f00e7b8:	44811000 */ 	mtc1	$at,$f2
/*  f00e7bc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f00e7c0:	8e090068 */ 	lw	$t1,0x68($s0)
/*  f00e7c4:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f00e7c8:	8e0b00bc */ 	lw	$t3,0xbc($s0)
/*  f00e7cc:	44892000 */ 	mtc1	$t1,$f4
/*  f00e7d0:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f00e7d4:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7d8:	448a8000 */ 	mtc1	$t2,$f16
/*  f00e7dc:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f00e7e0:	e612005c */ 	swc1	$f18,0x5c($s0)
/*  f00e7e4:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f00e7e8:	46023483 */ 	div.s	$f18,$f6,$f2
/*  f00e7ec:	e6080060 */ 	swc1	$f8,0x60($s0)
/*  f00e7f0:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7f4:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f00e7f8:	e6120064 */ 	swc1	$f18,0x64($s0)
/*  f00e7fc:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f00e800:	e6080068 */ 	swc1	$f8,0x68($s0)
/*  f00e804:	11600006 */ 	beqz	$t3,.L0f00e820
/*  f00e808:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f00e80c:	8e0c00bc */ 	lw	$t4,0xbc($s0)
/*  f00e810:	8fad01cc */ 	lw	$t5,0x1cc($sp)
/*  f00e814:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f00e818:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f00e81c:	ae0200bc */ 	sw	$v0,0xbc($s0)
.L0f00e820:
/*  f00e820:	27ae0054 */ 	addiu	$t6,$sp,0x54
/*  f00e824:	27af00a0 */ 	addiu	$t7,$sp,0xa0
/*  f00e828:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f00e82c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f00e830:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e834:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f00e838:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00e83c:	0fc23550 */ 	jal	func0f08d540
/*  f00e840:	27a700ec */ 	addiu	$a3,$sp,0xec
/*  f00e844:	afa2010c */ 	sw	$v0,0x10c($sp)
/*  f00e848:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f00e84c:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*  f00e850:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f00e854:	0723000e */ 	bgezl	$t9,.L0f00e890
/*  f00e858:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e85c:	a60800c4 */ 	sh	$t0,0xc4($s0)
/*  f00e860:	860900c4 */ 	lh	$t1,0xc4($s0)
/*  f00e864:	0522000a */ 	bltzl	$t1,.L0f00e890
/*  f00e868:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e86c:	44802000 */ 	mtc1	$zero,$f4
/*  f00e870:	c60a007c */ 	lwc1	$f10,0x7c($s0)
/*  f00e874:	460a2032 */ 	c.eq.s	$f4,$f10
/*  f00e878:	00000000 */ 	nop
/*  f00e87c:	45020004 */ 	bc1fl	.L0f00e890
/*  f00e880:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e884:	0fc23545 */ 	jal	doorDeactivatePortal
/*  f00e888:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e88c:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00e890:
/*  f00e890:	c7a00050 */ 	lwc1	$f0,0x50($sp)
/*  f00e894:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e898:	10800010 */ 	beqz	$a0,.L0f00e8dc
/*  f00e89c:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f00e8a0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f00e8a4:	00000000 */ 	nop
/*  f00e8a8:	45020003 */ 	bc1fl	.L0f00e8b8
/*  f00e8ac:	4608003c */ 	c.lt.s	$f0,$f8
/*  f00e8b0:	46006006 */ 	mov.s	$f0,$f12
/*  f00e8b4:	4608003c */ 	c.lt.s	$f0,$f8
.L0f00e8b8:
/*  f00e8b8:	00000000 */ 	nop
/*  f00e8bc:	45020003 */ 	bc1fl	.L0f00e8cc
/*  f00e8c0:	c4900014 */ 	lwc1	$f16,0x14($a0)
/*  f00e8c4:	46004006 */ 	mov.s	$f0,$f8
/*  f00e8c8:	c4900014 */ 	lwc1	$f16,0x14($a0)
.L0f00e8cc:
/*  f00e8cc:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e8d0:	44053000 */ 	mfc1	$a1,$f6
/*  f00e8d4:	0c006bd6 */ 	jal	modelSetUnk14
/*  f00e8d8:	00000000 */ 	nop
.L0f00e8dc:
/*  f00e8dc:	0fc1812f */ 	jal	func0f0604bc
/*  f00e8e0:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8e4:	0fc180bc */ 	jal	propShow
/*  f00e8e8:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8ec:	10000003 */ 	b	.L0f00e8fc
/*  f00e8f0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00e8f4:
/*  f00e8f4:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f00e8f8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00e8fc:
/*  f00e8fc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00e900:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f00e904:	03e00008 */ 	jr	$ra
/*  f00e908:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e90c
/*  f00e90c:	44801000 */ 	mtc1	$zero,$f2
/*  f00e910:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00e914:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00e918:	e4a20004 */ 	swc1	$f2,0x4($a1)
/*  f00e91c:	e4a20008 */ 	swc1	$f2,0x8($a1)
/*  f00e920:	e4a2000c */ 	swc1	$f2,0xc($a1)
/*  f00e924:	c48e003c */ 	lwc1	$f14,0x3c($a0)
/*  f00e928:	c48c0034 */ 	lwc1	$f12,0x34($a0)
/*  f00e92c:	0fc259d4 */ 	jal	func0f096750
/*  f00e930:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f00e934:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f00e938:	44801000 */ 	mtc1	$zero,$f2
/*  f00e93c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f00e940:	e4a00010 */ 	swc1	$f0,0x10($a1)
/*  f00e944:	aca20038 */ 	sw	$v0,0x38($a1)
/*  f00e948:	aca2003c */ 	sw	$v0,0x3c($a1)
/*  f00e94c:	e4a20014 */ 	swc1	$f2,0x14($a1)
/*  f00e950:	e4a20018 */ 	swc1	$f2,0x18($a1)
/*  f00e954:	e4a2001c */ 	swc1	$f2,0x1c($a1)
/*  f00e958:	e4a20020 */ 	swc1	$f2,0x20($a1)
/*  f00e95c:	e4a20024 */ 	swc1	$f2,0x24($a1)
/*  f00e960:	e4a20028 */ 	swc1	$f2,0x28($a1)
/*  f00e964:	e4a2002c */ 	swc1	$f2,0x2c($a1)
/*  f00e968:	e4a20030 */ 	swc1	$f2,0x30($a1)
/*  f00e96c:	e4a20034 */ 	swc1	$f2,0x34($a1)
/*  f00e970:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00e974:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00e978:	03e00008 */ 	jr	$ra
/*  f00e97c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f00e980
/*  f00e980:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00e984:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f00e988:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f00e98c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f00e990:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f00e994:	2881005a */ 	slti	$at,$a0,0x5a
/*  f00e998:	00e08825 */ 	or	$s1,$a3,$zero
/*  f00e99c:	00a09025 */ 	or	$s2,$a1,$zero
/*  f00e9a0:	00809825 */ 	or	$s3,$a0,$zero
/*  f00e9a4:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f00e9a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e9ac:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f00e9b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f00e9b4:	10200061 */ 	beqz	$at,.L0f00eb3c
/*  f00e9b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00e9bc:	0fc59585 */ 	jal	stageGetIndex
/*  f00e9c0:	00000000 */ 	nop
/*  f00e9c4:	04410002 */ 	bgez	$v0,.L0f00e9d0
/*  f00e9c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f00e9cc:	00001825 */ 	or	$v1,$zero,$zero
.L0f00e9d0:
/*  f00e9d0:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f00e9d4:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f00e9d8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00e9dc:	3c028008 */ 	lui	$v0,%hi(g_Stages+0xe)
/*  f00e9e0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f00e9e4:	9444fcce */ 	lhu	$a0,%lo(g_Stages+0xe)($v0)
/*  f00e9e8:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f00e9ec:	3c018006 */ 	lui	$at,%hi(var8005d9a0)
/*  f00e9f0:	a02fd9a0 */ 	sb	$t7,%lo(var8005d9a0)($at)
/*  f00e9f4:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00e9f8:	02403025 */ 	or	$a2,$s2,$zero
/*  f00e9fc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f00ea00:	0fc59c80 */ 	jal	func0f167200
/*  f00ea04:	00808025 */ 	or	$s0,$a0,$zero
/*  f00ea08:	0fc59ca0 */ 	jal	fileGetSize
/*  f00ea0c:	02002025 */ 	or	$a0,$s0,$zero
/*  f00ea10:	02428021 */ 	addu	$s0,$s2,$v0
/*  f00ea14:	02a2a023 */ 	subu	$s4,$s5,$v0
/*  f00ea18:	0fc5b878 */ 	jal	langGetLangBankIndexFromStagenum
/*  f00ea1c:	02602025 */ 	or	$a0,$s3,$zero
/*  f00ea20:	a622001a */ 	sh	$v0,0x1a($s1)
/*  f00ea24:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00ea28:	02002825 */ 	or	$a1,$s0,$zero
/*  f00ea2c:	0fc5b9d9 */ 	jal	langSetBank
/*  f00ea30:	02803025 */ 	or	$a2,$s4,$zero
/*  f00ea34:	8e580010 */ 	lw	$t8,0x10($s2)
/*  f00ea38:	02589821 */ 	addu	$s3,$s2,$t8
/*  f00ea3c:	52600040 */ 	beqzl	$s3,.L0f00eb40
/*  f00ea40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00ea44:	0fc5b367 */ 	jal	getDifficulty
/*  f00ea48:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f00ea4c:	14400002 */ 	bnez	$v0,.L0f00ea58
/*  f00ea50:	00000000 */ 	nop
/*  f00ea54:	24160003 */ 	addiu	$s6,$zero,0x3
.L0f00ea58:
/*  f00ea58:	0fc5b367 */ 	jal	getDifficulty
/*  f00ea5c:	00000000 */ 	nop
/*  f00ea60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f00ea64:	14410002 */ 	bne	$v0,$at,.L0f00ea70
/*  f00ea68:	02201825 */ 	or	$v1,$s1,$zero
/*  f00ea6c:	24160002 */ 	addiu	$s6,$zero,0x2
.L0f00ea70:
/*  f00ea70:	00001025 */ 	or	$v0,$zero,$zero
.L0f00ea74:
/*  f00ea74:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f00ea78:	28410006 */ 	slti	$at,$v0,0x6
/*  f00ea7c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f00ea80:	1420fffc */ 	bnez	$at,.L0f00ea74
/*  f00ea84:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f00ea88:	2419582a */ 	addiu	$t9,$zero,0x582a
/*  f00ea8c:	a6390000 */ 	sh	$t9,0x0($s1)
/*  f00ea90:	92680003 */ 	lbu	$t0,0x3($s3)
/*  f00ea94:	24120034 */ 	addiu	$s2,$zero,0x34
/*  f00ea98:	02608025 */ 	or	$s0,$s3,$zero
/*  f00ea9c:	12480027 */ 	beq	$s2,$t0,.L0f00eb3c
/*  f00eaa0:	310300ff */ 	andi	$v1,$t0,0xff
/*  f00eaa4:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f00eaa8:	24140023 */ 	addiu	$s4,$zero,0x23
/*  f00eaac:	24130017 */ 	addiu	$s3,$zero,0x17
.L0f00eab0:
/*  f00eab0:	5073000f */ 	beql	$v1,$s3,.L0f00eaf0
/*  f00eab4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eab8:	14740019 */ 	bne	$v1,$s4,.L0f00eb20
/*  f00eabc:	00000000 */ 	nop
/*  f00eac0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eac4:	16a20004 */ 	bne	$s5,$v0,.L0f00ead8
/*  f00eac8:	00000000 */ 	nop
/*  f00eacc:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f00ead0:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f00ead4:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00ead8:
/*  f00ead8:	16c20011 */ 	bne	$s6,$v0,.L0f00eb20
/*  f00eadc:	00000000 */ 	nop
/*  f00eae0:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f00eae4:	1000000e */ 	b	.L0f00eb20
/*  f00eae8:	a62a0000 */ 	sh	$t2,0x0($s1)
/*  f00eaec:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00eaf0:
/*  f00eaf0:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f00eaf4:	1020000a */ 	beqz	$at,.L0f00eb20
/*  f00eaf8:	00000000 */ 	nop
/*  f00eafc:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f00eb00:	00026040 */ 	sll	$t4,$v0,0x1
/*  f00eb04:	022c6821 */ 	addu	$t5,$s1,$t4
/*  f00eb08:	a5ab0002 */ 	sh	$t3,0x2($t5)
/*  f00eb0c:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f00eb10:	820e000f */ 	lb	$t6,0xf($s0)
/*  f00eb14:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f00eb18:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f00eb1c:	a72e000e */ 	sh	$t6,0xe($t9)
.L0f00eb20:
/*  f00eb20:	0fc24784 */ 	jal	setupGetCommandLength
/*  f00eb24:	02002025 */ 	or	$a0,$s0,$zero
/*  f00eb28:	00024080 */ 	sll	$t0,$v0,0x2
/*  f00eb2c:	01108021 */ 	addu	$s0,$t0,$s0
/*  f00eb30:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f00eb34:	1643ffde */ 	bne	$s2,$v1,.L0f00eab0
/*  f00eb38:	00000000 */ 	nop
.L0f00eb3c:
/*  f00eb3c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00eb40:
/*  f00eb40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00eb44:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f00eb48:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f00eb4c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f00eb50:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f00eb54:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f00eb58:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f00eb5c:	03e00008 */ 	jr	$ra
/*  f00eb60:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f00eb64
/*  f00eb64:	3c018007 */ 	lui	$at,%hi(var80069960)
/*  f00eb68:	ac209960 */ 	sw	$zero,%lo(var80069960)($at)
/*  f00eb6c:	3c018007 */ 	lui	$at,%hi(var80069964)
/*  f00eb70:	240effff */ 	addiu	$t6,$zero,-1
/*  f00eb74:	ac2e9964 */ 	sw	$t6,%lo(var80069964)($at)
/*  f00eb78:	3c013f80 */ 	lui	$at,0x3f80
/*  f00eb7c:	44812000 */ 	mtc1	$at,$f4
/*  f00eb80:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f00eb84:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00eb88:	3c018006 */ 	lui	$at,%hi(var80061be0)
/*  f00eb8c:	3c028008 */ 	lui	$v0,%hi(g_Props)
/*  f00eb90:	3c038008 */ 	lui	$v1,%hi(propexplosiontypes)
/*  f00eb94:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00eb98:	00803025 */ 	or	$a2,$a0,$zero
/*  f00eb9c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f00eba0:	00008025 */ 	or	$s0,$zero,$zero
/*  f00eba4:	2463be34 */ 	addiu	$v1,$v1,%lo(propexplosiontypes)
/*  f00eba8:	2442b06c */ 	addiu	$v0,$v0,%lo(g_Props)
/*  f00ebac:	e4241be0 */ 	swc1	$f4,%lo(var80061be0)($at)
.L0f00ebb0:
/*  f00ebb0:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f00ebb4:	0043082b */ 	sltu	$at,$v0,$v1
/*  f00ebb8:	1420fffd */ 	bnez	$at,.L0f00ebb0
/*  f00ebbc:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*  f00ebc0:	28c1005a */ 	slti	$at,$a2,0x5a
/*  f00ebc4:	1020014f */ 	beqz	$at,.L0f00f104
/*  f00ebc8:	3c07800a */ 	lui	$a3,%hi(g_StageSetup)
/*  f00ebcc:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x318)
/*  f00ebd0:	8defa2d8 */ 	lw	$t7,%lo(g_Vars+0x318)($t7)
/*  f00ebd4:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f00ebd8:	3c018006 */ 	lui	$at,%hi(var8005d9a0)
/*  f00ebdc:	11e0000a */ 	beqz	$t7,.L0f00ec08
/*  f00ebe0:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00ebe4:	3c188008 */ 	lui	$t8,%hi(g_StageIndex)
/*  f00ebe8:	8f18fc00 */ 	lw	$t8,%lo(g_StageIndex)($t8)
/*  f00ebec:	3c028008 */ 	lui	$v0,%hi(g_Stages+0x10)
/*  f00ebf0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f00ebf4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f00ebf8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f00ebfc:	00591021 */ 	addu	$v0,$v0,$t9
/*  f00ec00:	10000009 */ 	b	.L0f00ec28
/*  f00ec04:	9442fcd0 */ 	lhu	$v0,%lo(g_Stages+0x10)($v0)
.L0f00ec08:
/*  f00ec08:	3c0a8008 */ 	lui	$t2,%hi(g_StageIndex)
/*  f00ec0c:	8d4afc00 */ 	lw	$t2,%lo(g_StageIndex)($t2)
/*  f00ec10:	3c028008 */ 	lui	$v0,%hi(g_Stages+0xe)
/*  f00ec14:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f00ec18:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f00ec1c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f00ec20:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f00ec24:	9442fcce */ 	lhu	$v0,%lo(g_Stages+0xe)($v0)
.L0f00ec28:
/*  f00ec28:	a02cd9a0 */ 	sb	$t4,%lo(var8005d9a0)($at)
/*  f00ec2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f00ec30:	0fc59c3f */ 	jal	func0f1670fc
/*  f00ec34:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f00ec38:	3c03800a */ 	lui	$v1,%hi(g_GeCreditsData)
/*  f00ec3c:	2463d050 */ 	addiu	$v1,$v1,%lo(g_GeCreditsData)
/*  f00ec40:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f00ec44:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f00ec48:	0fc5b878 */ 	jal	langGetLangBankIndexFromStagenum
/*  f00ec4c:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f00ec50:	0fc5b9ca */ 	jal	langSetBankSimple
/*  f00ec54:	00402025 */ 	or	$a0,$v0,$zero
/*  f00ec58:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f00ec5c:	3c07800a */ 	lui	$a3,%hi(g_StageSetup)
/*  f00ec60:	24e7d030 */ 	addiu	$a3,$a3,%lo(g_StageSetup)
/*  f00ec64:	8d2d000c */ 	lw	$t5,0xc($t1)
/*  f00ec68:	3c048008 */ 	lui	$a0,%hi(g_Stages+0xc)
/*  f00ec6c:	3c018006 */ 	lui	$at,%hi(var8005d9a0)
/*  f00ec70:	012d7021 */ 	addu	$t6,$t1,$t5
/*  f00ec74:	acee000c */ 	sw	$t6,0xc($a3)
/*  f00ec78:	8d2f0010 */ 	lw	$t7,0x10($t1)
/*  f00ec7c:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f00ec80:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f00ec84:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f00ec88:	acf80010 */ 	sw	$t8,0x10($a3)
/*  f00ec8c:	8d390014 */ 	lw	$t9,0x14($t1)
/*  f00ec90:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00ec94:	01395021 */ 	addu	$t2,$t1,$t9
/*  f00ec98:	acea0014 */ 	sw	$t2,0x14($a3)
/*  f00ec9c:	8d2b0018 */ 	lw	$t3,0x18($t1)
/*  f00eca0:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f00eca4:	acec0018 */ 	sw	$t4,0x18($a3)
/*  f00eca8:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f00ecac:	a02dd9a0 */ 	sb	$t5,%lo(var8005d9a0)($at)
/*  f00ecb0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f00ecb4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f00ecb8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f00ecbc:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f00ecc0:	0fc59c3f */ 	jal	func0f1670fc
/*  f00ecc4:	9484fccc */ 	lhu	$a0,%lo(g_Stages+0xc)($a0)
/*  f00ecc8:	3c07800a */ 	lui	$a3,%hi(g_StageSetup)
/*  f00eccc:	24e7d030 */ 	addiu	$a3,$a3,%lo(g_StageSetup)
/*  f00ecd0:	8ce60018 */ 	lw	$a2,0x18($a3)
/*  f00ecd4:	ace2001c */ 	sw	$v0,0x1c($a3)
/*  f00ecd8:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f00ecdc:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f00ece0:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f00ece4:	10c0000f */ 	beqz	$a2,.L0f00ed24
/*  f00ece8:	ace00008 */ 	sw	$zero,0x8($a3)
/*  f00ecec:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f00ecf0:	00001825 */ 	or	$v1,$zero,$zero
/*  f00ecf4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f00ecf8:	1300000a */ 	beqz	$t8,.L0f00ed24
/*  f00ecfc:	00000000 */ 	nop
/*  f00ed00:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f00ed04:	0089c821 */ 	addu	$t9,$a0,$t1
.L0f00ed08:
/*  f00ed08:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f00ed0c:	8ce60018 */ 	lw	$a2,0x18($a3)
/*  f00ed10:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f00ed14:	00c31021 */ 	addu	$v0,$a2,$v1
/*  f00ed18:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f00ed1c:	5480fffa */ 	bnezl	$a0,.L0f00ed08
/*  f00ed20:	0089c821 */ 	addu	$t9,$a0,$t1
.L0f00ed24:
/*  f00ed24:	3c088008 */ 	lui	$t0,%hi(g_GlobalAilists)
/*  f00ed28:	2508ac58 */ 	addiu	$t0,$t0,%lo(g_GlobalAilists)
/*  f00ed2c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f00ed30:	8d0a0008 */ 	lw	$t2,0x8($t0)
.L0f00ed34:
/*  f00ed34:	3c028008 */ 	lui	$v0,%hi(g_GlobalAilists)
/*  f00ed38:	00002825 */ 	or	$a1,$zero,$zero
/*  f00ed3c:	11400017 */ 	beqz	$t2,.L0f00ed9c
/*  f00ed40:	2442ac58 */ 	addiu	$v0,$v0,%lo(g_GlobalAilists)
/*  f00ed44:	8c4b000c */ 	lw	$t3,0xc($v0)
.L0f00ed48:
/*  f00ed48:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f00ed4c:	016c082a */ 	slt	$at,$t3,$t4
/*  f00ed50:	5020000f */ 	beqzl	$at,.L0f00ed90
/*  f00ed54:	8c4b0010 */ 	lw	$t3,0x10($v0)
/*  f00ed58:	8c410000 */ 	lw	$at,0x0($v0)
/*  f00ed5c:	24430008 */ 	addiu	$v1,$v0,0x8
/*  f00ed60:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f00ed64:	ac810000 */ 	sw	$at,0x0($a0)
/*  f00ed68:	8c610000 */ 	lw	$at,0x0($v1)
/*  f00ed6c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00ed70:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f00ed74:	ac410000 */ 	sw	$at,0x0($v0)
/*  f00ed78:	8c780004 */ 	lw	$t8,0x4($v1)
/*  f00ed7c:	8c810000 */ 	lw	$at,0x0($a0)
/*  f00ed80:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f00ed84:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f00ed88:	ac610000 */ 	sw	$at,0x0($v1)
/*  f00ed8c:	8c4b0010 */ 	lw	$t3,0x10($v0)
.L0f00ed90:
/*  f00ed90:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f00ed94:	5560ffec */ 	bnezl	$t3,.L0f00ed48
/*  f00ed98:	8c4b000c */ 	lw	$t3,0xc($v0)
.L0f00ed9c:
/*  f00ed9c:	54a0ffe5 */ 	bnezl	$a1,.L0f00ed34
/*  f00eda0:	8d0a0008 */ 	lw	$t2,0x8($t0)
/*  f00eda4:	8ccc0008 */ 	lw	$t4,0x8($a2)
.L0f00eda8:
/*  f00eda8:	00002825 */ 	or	$a1,$zero,$zero
/*  f00edac:	00001825 */ 	or	$v1,$zero,$zero
/*  f00edb0:	1180001c */ 	beqz	$t4,.L0f00ee24
/*  f00edb4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f00edb8:	8c4d000c */ 	lw	$t5,0xc($v0)
.L0f00edbc:
/*  f00edbc:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f00edc0:	01ae082a */ 	slt	$at,$t5,$t6
/*  f00edc4:	50200013 */ 	beqzl	$at,.L0f00ee14
/*  f00edc8:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f00edcc:	8c410000 */ 	lw	$at,0x0($v0)
/*  f00edd0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00edd4:	ac810000 */ 	sw	$at,0x0($a0)
/*  f00edd8:	8c580004 */ 	lw	$t8,0x4($v0)
/*  f00eddc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f00ede0:	8c4a000c */ 	lw	$t2,0xc($v0)
/*  f00ede4:	8c410008 */ 	lw	$at,0x8($v0)
/*  f00ede8:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f00edec:	ac410000 */ 	sw	$at,0x0($v0)
/*  f00edf0:	8ceb0018 */ 	lw	$t3,0x18($a3)
/*  f00edf4:	8c810000 */ 	lw	$at,0x0($a0)
/*  f00edf8:	01636021 */ 	addu	$t4,$t3,$v1
/*  f00edfc:	ad810008 */ 	sw	$at,0x8($t4)
/*  f00ee00:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f00ee04:	ad8e000c */ 	sw	$t6,0xc($t4)
/*  f00ee08:	8ce60018 */ 	lw	$a2,0x18($a3)
/*  f00ee0c:	00c31021 */ 	addu	$v0,$a2,$v1
/*  f00ee10:	8c4f0010 */ 	lw	$t7,0x10($v0)
.L0f00ee14:
/*  f00ee14:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f00ee18:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f00ee1c:	55e0ffe7 */ 	bnezl	$t7,.L0f00edbc
/*  f00ee20:	8c4d000c */ 	lw	$t5,0xc($v0)
.L0f00ee24:
/*  f00ee24:	54a0ffe0 */ 	bnezl	$a1,.L0f00eda8
/*  f00ee28:	8ccc0008 */ 	lw	$t4,0x8($a2)
/*  f00ee2c:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f00ee30:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f00ee34:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*  f00ee38:	3c038006 */ 	lui	$v1,%hi(g_NumGlobalAilists)
/*  f00ee3c:	2463ef30 */ 	addiu	$v1,$v1,%lo(g_NumGlobalAilists)
/*  f00ee40:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f00ee44:	11400009 */ 	beqz	$t2,.L0f00ee6c
/*  f00ee48:	00001025 */ 	or	$v0,$zero,$zero
/*  f00ee4c:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f00ee50:
/*  f00ee50:	000b68c0 */ 	sll	$t5,$t3,0x3
/*  f00ee54:	010d6021 */ 	addu	$t4,$t0,$t5
/*  f00ee58:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f00ee5c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f00ee60:	01601025 */ 	or	$v0,$t3,$zero
/*  f00ee64:	55c0fffa */ 	bnezl	$t6,.L0f00ee50
/*  f00ee68:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f00ee6c:
/*  f00ee6c:	3c038006 */ 	lui	$v1,%hi(g_NumLvAilists)
/*  f00ee70:	2463ef34 */ 	addiu	$v1,$v1,%lo(g_NumLvAilists)
/*  f00ee74:	000078c0 */ 	sll	$t7,$zero,0x3
/*  f00ee78:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f00ee7c:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f00ee80:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f00ee84:	00001025 */ 	or	$v0,$zero,$zero
/*  f00ee88:	13200008 */ 	beqz	$t9,.L0f00eeac
/*  f00ee8c:	244a0001 */ 	addiu	$t2,$v0,0x1
.L0f00ee90:
/*  f00ee90:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f00ee94:	00cb6821 */ 	addu	$t5,$a2,$t3
/*  f00ee98:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f00ee9c:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f00eea0:	01401025 */ 	or	$v0,$t2,$zero
/*  f00eea4:	5580fffa */ 	bnezl	$t4,.L0f00ee90
/*  f00eea8:	244a0001 */ 	addiu	$t2,$v0,0x1
.L0f00eeac:
/*  f00eeac:	8ce20014 */ 	lw	$v0,0x14($a3)
/*  f00eeb0:	1040001d */ 	beqz	$v0,.L0f00ef28
/*  f00eeb4:	00000000 */ 	nop
/*  f00eeb8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f00eebc:	00001825 */ 	or	$v1,$zero,$zero
/*  f00eec0:	00403025 */ 	or	$a2,$v0,$zero
/*  f00eec4:	11c00018 */ 	beqz	$t6,.L0f00ef28
/*  f00eec8:	00000000 */ 	nop
/*  f00eecc:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f00eed0:	00a97821 */ 	addu	$t7,$a1,$t1
.L0f00eed4:
/*  f00eed4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f00eed8:	8cf80014 */ 	lw	$t8,0x14($a3)
/*  f00eedc:	00002025 */ 	or	$a0,$zero,$zero
/*  f00eee0:	03033021 */ 	addu	$a2,$t8,$v1
/*  f00eee4:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f00eee8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f00eeec:	00a01025 */ 	or	$v0,$a1,$zero
/*  f00eef0:	07220007 */ 	bltzl	$t9,.L0f00ef10
/*  f00eef4:	a4c40006 */ 	sh	$a0,0x6($a2)
/*  f00eef8:	8c4a0004 */ 	lw	$t2,0x4($v0)
.L0f00eefc:
/*  f00eefc:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f00ef00:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f00ef04:	0543fffd */ 	bgezl	$t2,.L0f00eefc
/*  f00ef08:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f00ef0c:	a4c40006 */ 	sh	$a0,0x6($a2)
.L0f00ef10:
/*  f00ef10:	8ceb0014 */ 	lw	$t3,0x14($a3)
/*  f00ef14:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f00ef18:	01633021 */ 	addu	$a2,$t3,$v1
/*  f00ef1c:	8cc50000 */ 	lw	$a1,0x0($a2)
/*  f00ef20:	54a0ffec */ 	bnezl	$a1,.L0f00eed4
/*  f00ef24:	00a97821 */ 	addu	$t7,$a1,$t1
.L0f00ef28:
/*  f00ef28:	0fc03398 */ 	jal	setupCountCommandType
/*  f00ef2c:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f00ef30:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f00ef34:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f00ef38:	8cad0318 */ 	lw	$t5,0x318($a1)
/*  f00ef3c:	00401825 */ 	or	$v1,$v0,$zero
/*  f00ef40:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f00ef44:	15a00009 */ 	bnez	$t5,.L0f00ef6c
/*  f00ef48:	3c0c800a */ 	lui	$t4,%hi(g_MissionConfig+0x3)
/*  f00ef4c:	818edfeb */ 	lb	$t6,%lo(g_MissionConfig+0x3)($t4)
/*  f00ef50:	05c10006 */ 	bgez	$t6,.L0f00ef6c
/*  f00ef54:	00000000 */ 	nop
/*  f00ef58:	8ca20474 */ 	lw	$v0,0x474($a1)
/*  f00ef5c:	18400003 */ 	blez	$v0,.L0f00ef6c
/*  f00ef60:	00000000 */ 	nop
/*  f00ef64:	00621821 */ 	addu	$v1,$v1,$v0
/*  f00ef68:	00408025 */ 	or	$s0,$v0,$zero
.L0f00ef6c:
/*  f00ef6c:	0fc03398 */ 	jal	setupCountCommandType
/*  f00ef70:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f00ef74:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00ef78:	0fc03398 */ 	jal	setupCountCommandType
/*  f00ef7c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f00ef80:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00ef84:	0fc03398 */ 	jal	setupCountCommandType
/*  f00ef88:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f00ef8c:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00ef90:	0fc03398 */ 	jal	setupCountCommandType
/*  f00ef94:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00ef98:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00ef9c:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efa0:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f00efa4:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efa8:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efac:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f00efb0:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efb4:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efb8:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f00efbc:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efc0:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efc4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f00efc8:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efcc:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efd0:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f00efd4:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efd8:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efdc:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f00efe0:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00efe4:	0fc03398 */ 	jal	setupCountCommandType
/*  f00efe8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f00efec:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00eff0:	0fc03398 */ 	jal	setupCountCommandType
/*  f00eff4:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f00eff8:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00effc:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f000:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f00f004:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f008:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f00c:	2404002f */ 	addiu	$a0,$zero,0x2f
/*  f00f010:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f014:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f018:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f00f01c:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f020:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f024:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f00f028:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f02c:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f030:	24040024 */ 	addiu	$a0,$zero,0x24
/*  f00f034:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f038:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f03c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f00f040:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f044:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f048:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f00f04c:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f050:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f054:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f00f058:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f05c:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f060:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f00f064:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f068:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f06c:	2404002d */ 	addiu	$a0,$zero,0x2d
/*  f00f070:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f074:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f078:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f00f07c:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f080:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f084:	24040033 */ 	addiu	$a0,$zero,0x33
/*  f00f088:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f08c:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f090:	24040035 */ 	addiu	$a0,$zero,0x35
/*  f00f094:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f098:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f09c:	24040036 */ 	addiu	$a0,$zero,0x36
/*  f00f0a0:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0a4:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f0a8:	24040037 */ 	addiu	$a0,$zero,0x37
/*  f00f0ac:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0b0:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f0b4:	24040039 */ 	addiu	$a0,$zero,0x39
/*  f00f0b8:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0bc:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f0c0:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f00f0c4:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0c8:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f0cc:	2404003b */ 	addiu	$a0,$zero,0x3b
/*  f00f0d0:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x318)
/*  f00f0d4:	8defa2d8 */ 	lw	$t7,%lo(g_Vars+0x318)($t7)
/*  f00f0d8:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0dc:	51e00005 */ 	beqzl	$t7,.L0f00f0f4
/*  f00f0e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f00f0e4:	0fc61533 */ 	jal	scenarioCallback08
/*  f00f0e8:	00000000 */ 	nop
/*  f00f0ec:	02028021 */ 	addu	$s0,$s0,$v0
/*  f00f0f0:	02002025 */ 	or	$a0,$s0,$zero
.L0f00f0f4:
/*  f00f0f4:	0fc0444c */ 	jal	func0f011130
/*  f00f0f8:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f00f0fc:	1000000c */ 	b	.L0f00f130
/*  f00f100:	00000000 */ 	nop
.L0f00f104:
/*  f00f104:	24e7d030 */ 	addiu	$a3,$a3,%lo(g_StageSetup)
/*  f00f108:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f00f10c:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f00f110:	ace0000c */ 	sw	$zero,0xc($a3)
/*  f00f114:	ace00010 */ 	sw	$zero,0x10($a3)
/*  f00f118:	ace00014 */ 	sw	$zero,0x14($a3)
/*  f00f11c:	ace00018 */ 	sw	$zero,0x18($a3)
/*  f00f120:	ace0001c */ 	sw	$zero,0x1c($a3)
/*  f00f124:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f128:	0fc0444c */ 	jal	func0f011130
/*  f00f12c:	00002825 */ 	or	$a1,$zero,$zero
.L0f00f130:
/*  f00f130:	3c028009 */ 	lui	$v0,%hi(g_Is4Mb)
/*  f00f134:	90420af0 */ 	lbu	$v0,%lo(g_Is4Mb)($v0)
/*  f00f138:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f00f13c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00f140:	14820003 */ 	bne	$a0,$v0,.L0f00f150
/*  f00f144:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f00f148:	10000002 */ 	b	.L0f00f154
/*  f00f14c:	24030028 */ 	addiu	$v1,$zero,0x28
.L0f00f150:
/*  f00f150:	2403003c */ 	addiu	$v1,$zero,0x3c
.L0f00f154:
/*  f00f154:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00f158:	03235021 */ 	addu	$t2,$t9,$v1
/*  f00f15c:	254b0028 */ 	addiu	$t3,$t2,0x28
/*  f00f160:	3c01800a */ 	lui	$at,%hi(g_Vars+0x334)
/*  f00f164:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00f168:	ac2ba2f4 */ 	sw	$t3,%lo(g_Vars+0x334)($at)
/*  f00f16c:	03e00008 */ 	jr	$ra
/*  f00f170:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f00f174
.late_rodata
glabel var7f1a8068
.word func0f00f174+0x4f4 # f00f668
glabel var7f1a806c
.word func0f00f174+0x520 # f00f694
glabel var7f1a8070
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a8074
.word func0f00f174+0x570 # f00f6e4
glabel var7f1a8078
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a807c
.word func0f00f174+0x5d0 # f00f744
glabel var7f1a8080
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a8084
.word func0f00f174+0x540 # f00f6b4
glabel var7f1a8088
.word func0f00f174+0x4d0 # f00f644
glabel var7f1a808c
.word func0f00f174+0x654 # f00f7c8
glabel var7f1a8090
.word func0f00f174+0x680 # f00f7f4
glabel var7f1a8094
.word func0f00f174+0x628 # f00f79c
glabel var7f1a8098
.word func0f00f174+0x5fc # f00f770
glabel var7f1a809c
.word func0f00f174+0x111c # f010290
glabel var7f1a80a0
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a80a4
.word func0f00f174+0x111c # f010290
glabel var7f1a80a8
.word func0f00f174+0x5a0 # f00f714
glabel var7f1a80ac
.word func0f00f174+0x49c # f00f610
glabel var7f1a80b0
.word func0f00f174+0x111c # f010290
glabel var7f1a80b4
.word func0f00f174+0xb48 # f00fcbc
glabel var7f1a80b8
.word func0f00f174+0x6ac # f00f820
glabel var7f1a80bc
.word func0f00f174+0xf38 # f0100ac
glabel var7f1a80c0
.word func0f00f174+0x105c # f0101d0
glabel var7f1a80c4
.word func0f00f174+0x111c # f010290
glabel var7f1a80c8
.word func0f00f174+0x111c # f010290
glabel var7f1a80cc
.word func0f00f174+0x111c # f010290
glabel var7f1a80d0
.word func0f00f174+0x111c # f010290
glabel var7f1a80d4
.word func0f00f174+0x111c # f010290
glabel var7f1a80d8
.word func0f00f174+0x111c # f010290
glabel var7f1a80dc
.word func0f00f174+0x10c0 # f010234
glabel var7f1a80e0
.word func0f00f174+0x111c # f010290
glabel var7f1a80e4
.word func0f00f174+0x10a0 # f010214
glabel var7f1a80e8
.word func0f00f174+0x10b0 # f010224
glabel var7f1a80ec
.word func0f00f174+0x111c # f010290
glabel var7f1a80f0
.word func0f00f174+0xf98 # f01010c
glabel var7f1a80f4
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a80f8
.word func0f00f174+0xf68 # f0100dc
glabel var7f1a80fc
.word func0f00f174+0x111c # f010290
glabel var7f1a8100
.word func0f00f174+0xc20 # f00fd94
glabel var7f1a8104
.word func0f00f174+0xec8 # f01003c
glabel var7f1a8108
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a810c
.word func0f00f174+0xa00 # f00fb74
glabel var7f1a8110
.word func0f00f174+0xb1c # f00fc90
glabel var7f1a8114
.word func0f00f174+0x111c # f010290
glabel var7f1a8118
.word func0f00f174+0x111c # f010290
glabel var7f1a811c
.word func0f00f174+0xfec # f010160
glabel var7f1a8120
.word func0f00f174+0x708 # f00f87c
glabel var7f1a8124
.word func0f00f174+0x768 # f00f8dc
glabel var7f1a8128
.word func0f00f174+0x111c # f010290
glabel var7f1a812c
.word func0f00f174+0x111c # f010290
glabel var7f1a8130
.word func0f00f174+0x938 # f00faac
glabel var7f1a8134
.word func0f00f174+0x111c # f010290
glabel var7f1a8138
.word func0f00f174+0x900 # f00fa74
glabel var7f1a813c
.word func0f00f174+0x9a8 # f00fb1c
glabel var7f1a8140
.word func0f00f174+0xcc8 # f00fe3c
glabel var7f1a8144
.word func0f00f174+0x10d0 # f010244
glabel var7f1a8148
.word func0f00f174+0xd80 # f00fef4
glabel var7f1a814c
.word func0f00f174+0x10f8 # f01026c
glabel var7f1a8150
.word func0f00f174+0xa48 # f00fbbc
glabel var7f1a8154
.word 0x4096c5bf
glabel var7f1a8158
.word 0x404907a9
glabel var7f1a815c
.word 0x3d4ccccd
glabel var7f1a8160
.word 0x3f59999a
glabel var7f1a8164
.word 0x3e4ccccd
glabel var7f1a8168
.word func0f00f174+0x12ec # f010460
glabel var7f1a816c
.word func0f00f174+0x12ec # f010460
glabel var7f1a8170
.word func0f00f174+0x16dc # f010850
glabel var7f1a8174
.word func0f00f174+0x16dc # f010850
glabel var7f1a8178
.word func0f00f174+0x12ec # f010460
glabel var7f1a817c
.word func0f00f174+0x12ec # f010460
glabel var7f1a8180
.word func0f00f174+0x16dc # f010850
glabel var7f1a8184
.word func0f00f174+0x12ec # f010460
glabel var7f1a8188
.word func0f00f174+0x16dc # f010850
glabel var7f1a818c
.word func0f00f174+0x16dc # f010850
glabel var7f1a8190
.word func0f00f174+0x16dc # f010850
glabel var7f1a8194
.word func0f00f174+0x1358 # f0104cc
glabel var7f1a8198
.word func0f00f174+0x12ec # f010460
glabel var7f1a819c
.word func0f00f174+0x16dc # f010850
glabel var7f1a81a0
.word func0f00f174+0x16dc # f010850
glabel var7f1a81a4
.word func0f00f174+0x16dc # f010850
glabel var7f1a81a8
.word func0f00f174+0x13ac # f010520
glabel var7f1a81ac
.word func0f00f174+0x12ec # f010460
glabel var7f1a81b0
.word func0f00f174+0x12ec # f010460
glabel var7f1a81b4
.word func0f00f174+0x16dc # f010850
glabel var7f1a81b8
.word func0f00f174+0x16dc # f010850
glabel var7f1a81bc
.word func0f00f174+0x16dc # f010850
glabel var7f1a81c0
.word func0f00f174+0x16dc # f010850
glabel var7f1a81c4
.word func0f00f174+0x16dc # f010850
glabel var7f1a81c8
.word func0f00f174+0x16dc # f010850
glabel var7f1a81cc
.word func0f00f174+0x16dc # f010850
glabel var7f1a81d0
.word func0f00f174+0x16dc # f010850
glabel var7f1a81d4
.word func0f00f174+0x16dc # f010850
glabel var7f1a81d8
.word func0f00f174+0x16dc # f010850
glabel var7f1a81dc
.word func0f00f174+0x16dc # f010850
glabel var7f1a81e0
.word func0f00f174+0x16dc # f010850
glabel var7f1a81e4
.word func0f00f174+0x16dc # f010850
glabel var7f1a81e8
.word func0f00f174+0x16dc # f010850
glabel var7f1a81ec
.word func0f00f174+0x12ec # f010460
glabel var7f1a81f0
.word func0f00f174+0x16dc # f010850
glabel var7f1a81f4
.word func0f00f174+0x14d8 # f01064c
glabel var7f1a81f8
.word func0f00f174+0x16dc # f010850
glabel var7f1a81fc
.word func0f00f174+0x16dc # f010850
glabel var7f1a8200
.word func0f00f174+0x12ec # f010460
glabel var7f1a8204
.word func0f00f174+0x12ec # f010460
glabel var7f1a8208
.word func0f00f174+0x12ec # f010460
glabel var7f1a820c
.word func0f00f174+0x1414 # f010588
glabel var7f1a8210
.word func0f00f174+0x16dc # f010850
glabel var7f1a8214
.word func0f00f174+0x16dc # f010850
glabel var7f1a8218
.word func0f00f174+0x12ec # f010460
glabel var7f1a821c
.word func0f00f174+0x16dc # f010850
glabel var7f1a8220
.word func0f00f174+0x154c # f0106c0
glabel var7f1a8224
.word func0f00f174+0x1690 # f010804
.text
/*  f00f174:	27bdfdb8 */ 	addiu	$sp,$sp,-584
/*  f00f178:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f00f17c:	afa40248 */ 	sw	$a0,0x248($sp)
/*  f00f180:	3c057f1a */ 	lui	$a1,%hi(var7f1a7f60)
/*  f00f184:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f00f188:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f00f18c:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f00f190:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f00f194:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f00f198:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f00f19c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f00f1a0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f00f1a4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f00f1a8:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f00f1ac:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f00f1b0:	24a57f60 */ 	addiu	$a1,$a1,%lo(var7f1a7f60)
/*  f00f1b4:	0c004c04 */ 	jal	func00013010
/*  f00f1b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00f1bc:	2c430001 */ 	sltiu	$v1,$v0,0x1
/*  f00f1c0:	10600005 */ 	beqz	$v1,.L0f00f1d8
/*  f00f1c4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00f1c8:	3c057f1a */ 	lui	$a1,%hi(var7f1a7f68)
/*  f00f1cc:	0c004c04 */ 	jal	func00013010
/*  f00f1d0:	24a57f68 */ 	addiu	$a1,$a1,%lo(var7f1a7f68)
/*  f00f1d4:	2c430001 */ 	sltiu	$v1,$v0,0x1
.L0f00f1d8:
/*  f00f1d8:	3c057f1a */ 	lui	$a1,%hi(var7f1a7f70)
/*  f00f1dc:	afa30244 */ 	sw	$v1,0x244($sp)
/*  f00f1e0:	24a57f70 */ 	addiu	$a1,$a1,%lo(var7f1a7f70)
/*  f00f1e4:	0c004c04 */ 	jal	func00013010
/*  f00f1e8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00f1ec:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f00f1f0:	10800005 */ 	beqz	$a0,.L0f00f208
/*  f00f1f4:	3c057f1a */ 	lui	$a1,%hi(var7f1a7f78)
/*  f00f1f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00f1fc:	0c004c04 */ 	jal	func00013010
/*  f00f200:	24a57f78 */ 	addiu	$a1,$a1,%lo(var7f1a7f78)
/*  f00f204:	2c440001 */ 	sltiu	$a0,$v0,0x1
.L0f00f208:
/*  f00f208:	8fa50248 */ 	lw	$a1,0x248($sp)
/*  f00f20c:	24010022 */ 	addiu	$at,$zero,0x22
/*  f00f210:	0080a825 */ 	or	$s5,$a0,$zero
/*  f00f214:	10a10006 */ 	beq	$a1,$at,.L0f00f230
/*  f00f218:	2418582a */ 	addiu	$t8,$zero,0x582a
/*  f00f21c:	38a20030 */ 	xori	$v0,$a1,0x30
/*  f00f220:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f00f224:	2c430001 */ 	sltiu	$v1,$v0,0x1
/*  f00f228:	5460000e */ 	bnezl	$v1,.L0f00f264
/*  f00f22c:	afa3023c */ 	sw	$v1,0x23c($sp)
.L0f00f230:
/*  f00f230:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x298)
/*  f00f234:	8c63a258 */ 	lw	$v1,%lo(g_Vars+0x298)($v1)
/*  f00f238:	286e0000 */ 	slti	$t6,$v1,0x0
/*  f00f23c:	39ce0001 */ 	xori	$t6,$t6,0x1
/*  f00f240:	2dc30001 */ 	sltiu	$v1,$t6,0x1
/*  f00f244:	50600007 */ 	beqzl	$v1,.L0f00f264
/*  f00f248:	afa3023c */ 	sw	$v1,0x23c($sp)
/*  f00f24c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x29c)
/*  f00f250:	8c63a25c */ 	lw	$v1,%lo(g_Vars+0x29c)($v1)
/*  f00f254:	286f0000 */ 	slti	$t7,$v1,0x0
/*  f00f258:	39ef0001 */ 	xori	$t7,$t7,0x1
/*  f00f25c:	2de30001 */ 	sltiu	$v1,$t7,0x1
/*  f00f260:	afa3023c */ 	sw	$v1,0x23c($sp)
.L0f00f264:
/*  f00f264:	3c01800a */ 	lui	$at,%hi(g_Vars+0x2b8)
/*  f00f268:	3c03800a */ 	lui	$v1,%hi(g_Briefing+0xc)
/*  f00f26c:	3c02800a */ 	lui	$v0,%hi(g_Briefing)
/*  f00f270:	afa00238 */ 	sw	$zero,0x238($sp)
/*  f00f274:	afa00234 */ 	sw	$zero,0x234($sp)
/*  f00f278:	ac20a278 */ 	sw	$zero,%lo(g_Vars+0x2b8)($at)
/*  f00f27c:	2442dfc8 */ 	addiu	$v0,$v0,%lo(g_Briefing)
/*  f00f280:	2463dfd4 */ 	addiu	$v1,$v1,%lo(g_Briefing+0xc)
.L0f00f284:
/*  f00f284:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00f288:	a4400000 */ 	sh	$zero,0x0($v0)
/*  f00f28c:	1443fffd */ 	bne	$v0,$v1,.L0f00f284
/*  f00f290:	a440000c */ 	sh	$zero,0xc($v0)
/*  f00f294:	3c01800a */ 	lui	$at,%hi(g_Briefing)
/*  f00f298:	a438dfc8 */ 	sh	$t8,%lo(g_Briefing)($at)
/*  f00f29c:	28a1005a */ 	slti	$at,$a1,0x5a
/*  f00f2a0:	10200576 */ 	beqz	$at,.L0f01087c
/*  f00f2a4:	3c19800a */ 	lui	$t9,%hi(g_StageSetup+0x1c)
/*  f00f2a8:	8f39d04c */ 	lw	$t9,%lo(g_StageSetup+0x1c)($t9)
/*  f00f2ac:	13200003 */ 	beqz	$t9,.L0f00f2bc
/*  f00f2b0:	00000000 */ 	nop
/*  f00f2b4:	0fc04aa8 */ 	jal	func0f012aa0
/*  f00f2b8:	00000000 */ 	nop
.L0f00f2bc:
/*  f00f2bc:	0fc04b54 */ 	jal	func0f012d50
/*  f00f2c0:	00000000 */ 	nop
/*  f00f2c4:	8fab0244 */ 	lw	$t3,0x244($sp)
/*  f00f2c8:	11600015 */ 	beqz	$t3,.L0f00f320
/*  f00f2cc:	00000000 */ 	nop
/*  f00f2d0:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f2d4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f00f2d8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f00f2dc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f00f2e0:	8c6c0318 */ 	lw	$t4,0x318($v1)
/*  f00f2e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00f2e8:	3c0d800a */ 	lui	$t5,%hi(g_MissionConfig+0x3)
/*  f00f2ec:	15800008 */ 	bnez	$t4,.L0f00f310
/*  f00f2f0:	00000000 */ 	nop
/*  f00f2f4:	81aedfeb */ 	lb	$t6,%lo(g_MissionConfig+0x3)($t5)
/*  f00f2f8:	05c10005 */ 	bgez	$t6,.L0f00f310
/*  f00f2fc:	00000000 */ 	nop
/*  f00f300:	8c620474 */ 	lw	$v0,0x474($v1)
/*  f00f304:	18400002 */ 	blez	$v0,.L0f00f310
/*  f00f308:	00000000 */ 	nop
/*  f00f30c:	00822021 */ 	addu	$a0,$a0,$v0
.L0f00f310:
/*  f00f310:	0fc02d8b */ 	jal	func0f00b62c
/*  f00f314:	00000000 */ 	nop
/*  f00f318:	10000003 */ 	b	.L0f00f328
/*  f00f31c:	00000000 */ 	nop
.L0f00f320:
/*  f00f320:	0fc02d8b */ 	jal	func0f00b62c
/*  f00f324:	00002025 */ 	or	$a0,$zero,$zero
.L0f00f328:
/*  f00f328:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f00f32c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f00f330:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f00f334:	00008025 */ 	or	$s0,$zero,$zero
/*  f00f338:	00002825 */ 	or	$a1,$zero,$zero
/*  f00f33c:	11e00003 */ 	beqz	$t7,.L0f00f34c
/*  f00f340:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f344:	10000001 */ 	b	.L0f00f34c
/*  f00f348:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00f34c:
/*  f00f34c:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f00f350:	00001025 */ 	or	$v0,$zero,$zero
/*  f00f354:	00001825 */ 	or	$v1,$zero,$zero
/*  f00f358:	13000003 */ 	beqz	$t8,.L0f00f368
/*  f00f35c:	00000000 */ 	nop
/*  f00f360:	10000001 */ 	b	.L0f00f368
/*  f00f364:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00f368:
/*  f00f368:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f00f36c:	13200003 */ 	beqz	$t9,.L0f00f37c
/*  f00f370:	00000000 */ 	nop
/*  f00f374:	10000001 */ 	b	.L0f00f37c
/*  f00f378:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00f37c:
/*  f00f37c:	8ccb0070 */ 	lw	$t3,0x70($a2)
/*  f00f380:	11600003 */ 	beqz	$t3,.L0f00f390
/*  f00f384:	00000000 */ 	nop
/*  f00f388:	10000001 */ 	b	.L0f00f390
/*  f00f38c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00f390:
/*  f00f390:	00626021 */ 	addu	$t4,$v1,$v0
/*  f00f394:	01846821 */ 	addu	$t5,$t4,$a0
/*  f00f398:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f00f39c:	19c00027 */ 	blez	$t6,.L0f00f43c
/*  f00f3a0:	00000000 */ 	nop
.L0f00f3a4:
/*  f00f3a4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f00f3a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f00f3ac:	0fc03398 */ 	jal	setupCountCommandType
/*  f00f3b0:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f00f3b4:	0fc0494c */ 	jal	func0f012530
/*  f00f3b8:	00402025 */ 	or	$a0,$v0,$zero
/*  f00f3bc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f00f3c0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f00f3c4:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f00f3c8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f00f3cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f00f3d0:	11e00003 */ 	beqz	$t7,.L0f00f3e0
/*  f00f3d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f3d8:	10000001 */ 	b	.L0f00f3e0
/*  f00f3dc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00f3e0:
/*  f00f3e0:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f00f3e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f00f3e8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00f3ec:	13000003 */ 	beqz	$t8,.L0f00f3fc
/*  f00f3f0:	00000000 */ 	nop
/*  f00f3f4:	10000001 */ 	b	.L0f00f3fc
/*  f00f3f8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00f3fc:
/*  f00f3fc:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f00f400:	13200003 */ 	beqz	$t9,.L0f00f410
/*  f00f404:	00000000 */ 	nop
/*  f00f408:	10000001 */ 	b	.L0f00f410
/*  f00f40c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00f410:
/*  f00f410:	8ccb0070 */ 	lw	$t3,0x70($a2)
/*  f00f414:	11600003 */ 	beqz	$t3,.L0f00f424
/*  f00f418:	00000000 */ 	nop
/*  f00f41c:	10000001 */ 	b	.L0f00f424
/*  f00f420:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00f424:
/*  f00f424:	00626021 */ 	addu	$t4,$v1,$v0
/*  f00f428:	01846821 */ 	addu	$t5,$t4,$a0
/*  f00f42c:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f00f430:	020e082a */ 	slt	$at,$s0,$t6
/*  f00f434:	1420ffdb */ 	bnez	$at,.L0f00f3a4
/*  f00f438:	00000000 */ 	nop
.L0f00f43c:
/*  f00f43c:	3c0f800a */ 	lui	$t7,%hi(g_StageSetup+0x10)
/*  f00f440:	8defd040 */ 	lw	$t7,%lo(g_StageSetup+0x10)($t7)
/*  f00f444:	11e0050f */ 	beqz	$t7,.L0f010884
/*  f00f448:	00000000 */ 	nop
/*  f00f44c:	0fc5b367 */ 	jal	getDifficulty
/*  f00f450:	00000000 */ 	nop
/*  f00f454:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f00f458:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f00f45c:	8d4b0314 */ 	lw	$t3,0x314($t2)
/*  f00f460:	24580004 */ 	addiu	$t8,$v0,0x4
/*  f00f464:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f00f468:	11600052 */ 	beqz	$t3,.L0f00f5b4
/*  f00f46c:	0319a004 */ 	sllv	$s4,$t9,$t8
/*  f00f470:	8d46006c */ 	lw	$a2,0x6c($t2)
/*  f00f474:	24010002 */ 	addiu	$at,$zero,0x2
/*  f00f478:	00002825 */ 	or	$a1,$zero,$zero
/*  f00f47c:	10c00003 */ 	beqz	$a2,.L0f00f48c
/*  f00f480:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f484:	10000001 */ 	b	.L0f00f48c
/*  f00f488:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00f48c:
/*  f00f48c:	8d470068 */ 	lw	$a3,0x68($t2)
/*  f00f490:	00001025 */ 	or	$v0,$zero,$zero
/*  f00f494:	00001825 */ 	or	$v1,$zero,$zero
/*  f00f498:	10e00003 */ 	beqz	$a3,.L0f00f4a8
/*  f00f49c:	00000000 */ 	nop
/*  f00f4a0:	10000001 */ 	b	.L0f00f4a8
/*  f00f4a4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00f4a8:
/*  f00f4a8:	8d480064 */ 	lw	$t0,0x64($t2)
/*  f00f4ac:	11000003 */ 	beqz	$t0,.L0f00f4bc
/*  f00f4b0:	00000000 */ 	nop
/*  f00f4b4:	10000001 */ 	b	.L0f00f4bc
/*  f00f4b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00f4bc:
/*  f00f4bc:	8d490070 */ 	lw	$t1,0x70($t2)
/*  f00f4c0:	11200003 */ 	beqz	$t1,.L0f00f4d0
/*  f00f4c4:	00000000 */ 	nop
/*  f00f4c8:	10000001 */ 	b	.L0f00f4d0
/*  f00f4cc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00f4d0:
/*  f00f4d0:	00626021 */ 	addu	$t4,$v1,$v0
/*  f00f4d4:	01846821 */ 	addu	$t5,$t4,$a0
/*  f00f4d8:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f00f4dc:	15c10004 */ 	bne	$t6,$at,.L0f00f4f0
/*  f00f4e0:	3c010040 */ 	lui	$at,0x40
/*  f00f4e4:	02817825 */ 	or	$t7,$s4,$at
/*  f00f4e8:	10000032 */ 	b	.L0f00f5b4
/*  f00f4ec:	01e0a025 */ 	or	$s4,$t7,$zero
.L0f00f4f0:
/*  f00f4f0:	10c00003 */ 	beqz	$a2,.L0f00f500
/*  f00f4f4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f00f4f8:	10000002 */ 	b	.L0f00f504
/*  f00f4fc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00f500:
/*  f00f500:	00002825 */ 	or	$a1,$zero,$zero
.L0f00f504:
/*  f00f504:	10e00003 */ 	beqz	$a3,.L0f00f514
/*  f00f508:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f50c:	10000001 */ 	b	.L0f00f514
/*  f00f510:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00f514:
/*  f00f514:	11000003 */ 	beqz	$t0,.L0f00f524
/*  f00f518:	00001025 */ 	or	$v0,$zero,$zero
/*  f00f51c:	10000001 */ 	b	.L0f00f524
/*  f00f520:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00f524:
/*  f00f524:	11200003 */ 	beqz	$t1,.L0f00f534
/*  f00f528:	00001825 */ 	or	$v1,$zero,$zero
/*  f00f52c:	10000001 */ 	b	.L0f00f534
/*  f00f530:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00f534:
/*  f00f534:	0062c821 */ 	addu	$t9,$v1,$v0
/*  f00f538:	0324c021 */ 	addu	$t8,$t9,$a0
/*  f00f53c:	03055821 */ 	addu	$t3,$t8,$a1
/*  f00f540:	15610004 */ 	bne	$t3,$at,.L0f00f554
/*  f00f544:	3c010080 */ 	lui	$at,0x80
/*  f00f548:	02816025 */ 	or	$t4,$s4,$at
/*  f00f54c:	10000019 */ 	b	.L0f00f5b4
/*  f00f550:	0180a025 */ 	or	$s4,$t4,$zero
.L0f00f554:
/*  f00f554:	10c00003 */ 	beqz	$a2,.L0f00f564
/*  f00f558:	24010004 */ 	addiu	$at,$zero,0x4
/*  f00f55c:	10000002 */ 	b	.L0f00f568
/*  f00f560:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f00f564:
/*  f00f564:	00002825 */ 	or	$a1,$zero,$zero
.L0f00f568:
/*  f00f568:	10e00003 */ 	beqz	$a3,.L0f00f578
/*  f00f56c:	00002025 */ 	or	$a0,$zero,$zero
/*  f00f570:	10000001 */ 	b	.L0f00f578
/*  f00f574:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f00f578:
/*  f00f578:	11000003 */ 	beqz	$t0,.L0f00f588
/*  f00f57c:	00001025 */ 	or	$v0,$zero,$zero
/*  f00f580:	10000001 */ 	b	.L0f00f588
/*  f00f584:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00f588:
/*  f00f588:	11200003 */ 	beqz	$t1,.L0f00f598
/*  f00f58c:	00001825 */ 	or	$v1,$zero,$zero
/*  f00f590:	10000001 */ 	b	.L0f00f598
/*  f00f594:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00f598:
/*  f00f598:	00626821 */ 	addu	$t5,$v1,$v0
/*  f00f59c:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f00f5a0:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f00f5a4:	15e10003 */ 	bne	$t7,$at,.L0f00f5b4
/*  f00f5a8:	3c010100 */ 	lui	$at,0x100
/*  f00f5ac:	0281c825 */ 	or	$t9,$s4,$at
/*  f00f5b0:	0320a025 */ 	or	$s4,$t9,$zero
.L0f00f5b4:
/*  f00f5b4:	0fc05208 */ 	jal	mpRemoveAllSimulants
/*  f00f5b8:	00000000 */ 	nop
/*  f00f5bc:	3c12800a */ 	lui	$s2,%hi(g_StageSetup+0x10)
/*  f00f5c0:	8e52d040 */ 	lw	$s2,%lo(g_StageSetup+0x10)($s2)
/*  f00f5c4:	24010034 */ 	addiu	$at,$zero,0x34
/*  f00f5c8:	00009825 */ 	or	$s3,$zero,$zero
/*  f00f5cc:	92430003 */ 	lbu	$v1,0x3($s2)
/*  f00f5d0:	10610339 */ 	beq	$v1,$at,.L0f0102b8
/*  f00f5d4:	3c014780 */ 	lui	$at,0x4780
/*  f00f5d8:	4481b000 */ 	mtc1	$at,$f22
/*  f00f5dc:	4480a000 */ 	mtc1	$zero,$f20
/*  f00f5e0:	241e004c */ 	addiu	$s8,$zero,0x4c
/*  f00f5e4:	3417ffff */ 	dli	$s7,0xffff
/*  f00f5e8:	24160010 */ 	addiu	$s6,$zero,0x10
/*  f00f5ec:	2478ffff */ 	addiu	$t8,$v1,-1
.L0f00f5f0:
/*  f00f5f0:	2f01003b */ 	sltiu	$at,$t8,0x3b
/*  f00f5f4:	10200326 */ 	beqz	$at,.L0f010290
/*  f00f5f8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f00f5fc:	3c017f1b */ 	lui	$at,%hi(var7f1a8068)
/*  f00f600:	00380821 */ 	addu	$at,$at,$t8
/*  f00f604:	8c388068 */ 	lw	$t8,%lo(var7f1a8068)($at)
/*  f00f608:	03000008 */ 	jr	$t8
/*  f00f60c:	00000000 */ 	nop
/*  f00f610:	92500007 */ 	lbu	$s0,0x7($s2)
/*  f00f614:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f00f618:	86440004 */ 	lh	$a0,0x4($s2)
/*  f00f61c:	1040031c */ 	beqz	$v0,.L0f010290
/*  f00f620:	00000000 */ 	nop
/*  f00f624:	8c4b001c */ 	lw	$t3,0x1c($v0)
/*  f00f628:	11600319 */ 	beqz	$t3,.L0f010290
/*  f00f62c:	00000000 */ 	nop
/*  f00f630:	8c4c0020 */ 	lw	$t4,0x20($v0)
/*  f00f634:	11800316 */ 	beqz	$t4,.L0f010290
/*  f00f638:	00000000 */ 	nop
/*  f00f63c:	10000314 */ 	b	.L0f010290
/*  f00f640:	a050000f */ 	sb	$s0,0xf($v0)
/*  f00f644:	8fad0244 */ 	lw	$t5,0x244($sp)
/*  f00f648:	8fa40248 */ 	lw	$a0,0x248($sp)
/*  f00f64c:	02402825 */ 	or	$a1,$s2,$zero
/*  f00f650:	11a0030f */ 	beqz	$t5,.L0f010290
/*  f00f654:	00000000 */ 	nop
/*  f00f658:	0fc0b53f */ 	jal	func0f02d4fc
/*  f00f65c:	02603025 */ 	or	$a2,$s3,$zero
/*  f00f660:	1000030b */ 	b	.L0f010290
/*  f00f664:	00000000 */ 	nop
/*  f00f668:	12a00309 */ 	beqz	$s5,.L0f010290
/*  f00f66c:	00000000 */ 	nop
/*  f00f670:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f00f674:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f678:	01d47824 */ 	and	$t7,$t6,$s4
/*  f00f67c:	15e00304 */ 	bnez	$t7,.L0f010290
/*  f00f680:	00000000 */ 	nop
/*  f00f684:	0fc038da */ 	jal	func0f00e368
/*  f00f688:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f68c:	10000300 */ 	b	.L0f010290
/*  f00f690:	00000000 */ 	nop
/*  f00f694:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f00f698:	3c018006 */ 	lui	$at,%hi(var80061be0)
/*  f00f69c:	44992000 */ 	mtc1	$t9,$f4
/*  f00f6a0:	00000000 */ 	nop
/*  f00f6a4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00f6a8:	46163203 */ 	div.s	$f8,$f6,$f22
/*  f00f6ac:	100002f8 */ 	b	.L0f010290
/*  f00f6b0:	e4281be0 */ 	swc1	$f8,%lo(var80061be0)($at)
/*  f00f6b4:	8fb80244 */ 	lw	$t8,0x244($sp)
/*  f00f6b8:	130002f5 */ 	beqz	$t8,.L0f010290
/*  f00f6bc:	00000000 */ 	nop
/*  f00f6c0:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f00f6c4:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f6c8:	01746024 */ 	and	$t4,$t3,$s4
/*  f00f6cc:	158002f0 */ 	bnez	$t4,.L0f010290
/*  f00f6d0:	00000000 */ 	nop
/*  f00f6d4:	0fc0359c */ 	jal	weaponAssignToHome
/*  f00f6d8:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f6dc:	100002ec */ 	b	.L0f010290
/*  f00f6e0:	00000000 */ 	nop
/*  f00f6e4:	8fad0244 */ 	lw	$t5,0x244($sp)
/*  f00f6e8:	11a002e9 */ 	beqz	$t5,.L0f010290
/*  f00f6ec:	00000000 */ 	nop
/*  f00f6f0:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f00f6f4:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f6f8:	01d47824 */ 	and	$t7,$t6,$s4
/*  f00f6fc:	15e002e4 */ 	bnez	$t7,.L0f010290
/*  f00f700:	00000000 */ 	nop
/*  f00f704:	0fc0365e */ 	jal	func0f00d978
/*  f00f708:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f70c:	100002e0 */ 	b	.L0f010290
/*  f00f710:	00000000 */ 	nop
/*  f00f714:	8fb90244 */ 	lw	$t9,0x244($sp)
/*  f00f718:	132002dd */ 	beqz	$t9,.L0f010290
/*  f00f71c:	00000000 */ 	nop
/*  f00f720:	8e58000c */ 	lw	$t8,0xc($s2)
/*  f00f724:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f728:	03145824 */ 	and	$t3,$t8,$s4
/*  f00f72c:	156002d8 */ 	bnez	$t3,.L0f010290
/*  f00f730:	00000000 */ 	nop
/*  f00f734:	0fc03641 */ 	jal	func0f00d904
/*  f00f738:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f73c:	100002d4 */ 	b	.L0f010290
/*  f00f740:	00000000 */ 	nop
/*  f00f744:	12a002d2 */ 	beqz	$s5,.L0f010290
/*  f00f748:	00000000 */ 	nop
/*  f00f74c:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f00f750:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f754:	01946824 */ 	and	$t5,$t4,$s4
/*  f00f758:	15a002cd */ 	bnez	$t5,.L0f010290
/*  f00f75c:	00000000 */ 	nop
/*  f00f760:	0fc03684 */ 	jal	func0f00da10
/*  f00f764:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f768:	100002c9 */ 	b	.L0f010290
/*  f00f76c:	00000000 */ 	nop
/*  f00f770:	12a002c7 */ 	beqz	$s5,.L0f010290
/*  f00f774:	00000000 */ 	nop
/*  f00f778:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f00f77c:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f780:	01d47824 */ 	and	$t7,$t6,$s4
/*  f00f784:	15e002c2 */ 	bnez	$t7,.L0f010290
/*  f00f788:	00000000 */ 	nop
/*  f00f78c:	0fc03700 */ 	jal	func0f00dc00
/*  f00f790:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f794:	100002be */ 	b	.L0f010290
/*  f00f798:	00000000 */ 	nop
/*  f00f79c:	12a002bc */ 	beqz	$s5,.L0f010290
/*  f00f7a0:	00000000 */ 	nop
/*  f00f7a4:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f00f7a8:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f7ac:	0334c024 */ 	and	$t8,$t9,$s4
/*  f00f7b0:	170002b7 */ 	bnez	$t8,.L0f010290
/*  f00f7b4:	00000000 */ 	nop
/*  f00f7b8:	0fc03767 */ 	jal	func0f00dd9c
/*  f00f7bc:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f7c0:	100002b3 */ 	b	.L0f010290
/*  f00f7c4:	00000000 */ 	nop
/*  f00f7c8:	12a002b1 */ 	beqz	$s5,.L0f010290
/*  f00f7cc:	00000000 */ 	nop
/*  f00f7d0:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f00f7d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f7d8:	01746024 */ 	and	$t4,$t3,$s4
/*  f00f7dc:	158002ac */ 	bnez	$t4,.L0f010290
/*  f00f7e0:	00000000 */ 	nop
/*  f00f7e4:	0fc0376f */ 	jal	func0f00ddbc
/*  f00f7e8:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f7ec:	100002a8 */ 	b	.L0f010290
/*  f00f7f0:	00000000 */ 	nop
/*  f00f7f4:	12a002a6 */ 	beqz	$s5,.L0f010290
/*  f00f7f8:	00000000 */ 	nop
/*  f00f7fc:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f00f800:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f804:	01b47024 */ 	and	$t6,$t5,$s4
/*  f00f808:	15c002a1 */ 	bnez	$t6,.L0f010290
/*  f00f80c:	00000000 */ 	nop
/*  f00f810:	0fc03821 */ 	jal	func0f00e084
/*  f00f814:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f818:	1000029d */ 	b	.L0f010290
/*  f00f81c:	00000000 */ 	nop
/*  f00f820:	12a0029b */ 	beqz	$s5,.L0f010290
/*  f00f824:	00000000 */ 	nop
/*  f00f828:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f00f82c:	3c188008 */ 	lui	$t8,%hi(g_LanguageId)
/*  f00f830:	01f4c824 */ 	and	$t9,$t7,$s4
/*  f00f834:	53200005 */ 	beqzl	$t9,.L0f00f84c
/*  f00f838:	8e4b005c */ 	lw	$t3,0x5c($s2)
/*  f00f83c:	8f184120 */ 	lw	$t8,%lo(g_LanguageId)($t8)
/*  f00f840:	13000293 */ 	beqz	$t8,.L0f010290
/*  f00f844:	00000000 */ 	nop
/*  f00f848:	8e4b005c */ 	lw	$t3,0x5c($s2)
.L0f00f84c:
/*  f00f84c:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f850:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f854:	448b5000 */ 	mtc1	$t3,$f10
/*  f00f858:	00000000 */ 	nop
/*  f00f85c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f00f860:	46168483 */ 	div.s	$f18,$f16,$f22
/*  f00f864:	e652005c */ 	swc1	$f18,0x5c($s2)
/*  f00f868:	c644005c */ 	lwc1	$f4,0x5c($s2)
/*  f00f86c:	0fc033b9 */ 	jal	func0f00cee4
/*  f00f870:	e6440060 */ 	swc1	$f4,0x60($s2)
/*  f00f874:	10000286 */ 	b	.L0f010290
/*  f00f878:	00000000 */ 	nop
/*  f00f87c:	12a00284 */ 	beqz	$s5,.L0f010290
/*  f00f880:	00000000 */ 	nop
/*  f00f884:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f00f888:	01946824 */ 	and	$t5,$t4,$s4
/*  f00f88c:	15a00280 */ 	bnez	$t5,.L0f010290
/*  f00f890:	00000000 */ 	nop
/*  f00f894:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f00f898:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f00f89c:	05e3000b */ 	bgezl	$t7,.L0f00f8cc
/*  f00f8a0:	02402025 */ 	or	$a0,$s2,$zero
/*  f00f8a4:	0fc0387e */ 	jal	func0f00e1f8
/*  f00f8a8:	86440006 */ 	lh	$a0,0x6($s2)
/*  f00f8ac:	8e590064 */ 	lw	$t9,0x64($s2)
/*  f00f8b0:	a6420062 */ 	sh	$v0,0x62($s2)
/*  f00f8b4:	44993000 */ 	mtc1	$t9,$f6
/*  f00f8b8:	00000000 */ 	nop
/*  f00f8bc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f00f8c0:	46164283 */ 	div.s	$f10,$f8,$f22
/*  f00f8c4:	e64a0064 */ 	swc1	$f10,0x64($s2)
/*  f00f8c8:	02402025 */ 	or	$a0,$s2,$zero
.L0f00f8cc:
/*  f00f8cc:	0fc033b9 */ 	jal	func0f00cee4
/*  f00f8d0:	02602825 */ 	or	$a1,$s3,$zero
/*  f00f8d4:	1000026e */ 	b	.L0f010290
/*  f00f8d8:	00000000 */ 	nop
/*  f00f8dc:	12a0026c */ 	beqz	$s5,.L0f010290
/*  f00f8e0:	00000000 */ 	nop
/*  f00f8e4:	8e58000c */ 	lw	$t8,0xc($s2)
/*  f00f8e8:	03145824 */ 	and	$t3,$t8,$s4
/*  f00f8ec:	15600268 */ 	bnez	$t3,.L0f010290
/*  f00f8f0:	00000000 */ 	nop
/*  f00f8f4:	864c0004 */ 	lh	$t4,0x4($s2)
/*  f00f8f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f00f8fc:	02408025 */ 	or	$s0,$s2,$zero
/*  f00f900:	afac01f8 */ 	sw	$t4,0x1f8($sp)
/*  f00f904:	8e4d007c */ 	lw	$t5,0x7c($s2)
/*  f00f908:	8e4e0080 */ 	lw	$t6,0x80($s2)
/*  f00f90c:	e6540074 */ 	swc1	$f20,0x74($s2)
/*  f00f910:	448d8000 */ 	mtc1	$t5,$f16
/*  f00f914:	448e3000 */ 	mtc1	$t6,$f6
/*  f00f918:	e6540078 */ 	swc1	$f20,0x78($s2)
/*  f00f91c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f00f920:	a2400085 */ 	sb	$zero,0x85($s2)
/*  f00f924:	a2400086 */ 	sb	$zero,0x86($s2)
/*  f00f928:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f00f92c:	46169103 */ 	div.s	$f4,$f18,$f22
/*  f00f930:	46164283 */ 	div.s	$f10,$f8,$f22
/*  f00f934:	e644007c */ 	swc1	$f4,0x7c($s2)
/*  f00f938:	e64a0080 */ 	swc1	$f10,0x80($s2)
.L0f00f93c:
/*  f00f93c:	8e0f0064 */ 	lw	$t7,0x64($s0)
/*  f00f940:	51e00006 */ 	beqzl	$t7,.L0f00f95c
/*  f00f944:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f00f948:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f00f94c:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f00f950:	03332021 */ 	addu	$a0,$t9,$s3
/*  f00f954:	ae020064 */ 	sw	$v0,0x64($s0)
/*  f00f958:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f00f95c:
/*  f00f95c:	1636fff7 */ 	bne	$s1,$s6,.L0f00f93c
/*  f00f960:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f00f964:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f00f968:	a258005a */ 	sb	$t8,0x5a($s2)
/*  f00f96c:	0fc2486d */ 	jal	propLoad
/*  f00f970:	8fa401f8 */ 	lw	$a0,0x1f8($sp)
/*  f00f974:	8fab01f8 */ 	lw	$t3,0x1f8($sp)
/*  f00f978:	3c0d8008 */ 	lui	$t5,%hi(g_Props)
/*  f00f97c:	25adb06c */ 	addiu	$t5,$t5,%lo(g_Props)
/*  f00f980:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f00f984:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f00f988:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f00f98c:	50800025 */ 	beqzl	$a0,.L0f00fa24
/*  f00f990:	8e580008 */ 	lw	$t8,0x8($s2)
/*  f00f994:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00f998:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00f99c:	10400004 */ 	beqz	$v0,.L0f00f9b0
/*  f00f9a0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f00f9a4:	824e005a */ 	lb	$t6,0x5a($s2)
/*  f00f9a8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f00f9ac:	a24f005a */ 	sb	$t7,0x5a($s2)
.L0f00f9b0:
/*  f00f9b0:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00f9b4:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f00f9b8:	10400004 */ 	beqz	$v0,.L0f00f9cc
/*  f00f9bc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f00f9c0:	8259005a */ 	lb	$t9,0x5a($s2)
/*  f00f9c4:	27380001 */ 	addiu	$t8,$t9,0x1
/*  f00f9c8:	a258005a */ 	sb	$t8,0x5a($s2)
.L0f00f9cc:
/*  f00f9cc:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00f9d0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f00f9d4:	10400004 */ 	beqz	$v0,.L0f00f9e8
/*  f00f9d8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00f9dc:	824b005a */ 	lb	$t3,0x5a($s2)
/*  f00f9e0:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f00f9e4:	a24c005a */ 	sb	$t4,0x5a($s2)
.L0f00f9e8:
/*  f00f9e8:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00f9ec:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f00f9f0:	10400004 */ 	beqz	$v0,.L0f00fa04
/*  f00f9f4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f00f9f8:	824d005a */ 	lb	$t5,0x5a($s2)
/*  f00f9fc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f00fa00:	a24e005a */ 	sb	$t6,0x5a($s2)
.L0f00fa04:
/*  f00fa04:	0c006a6f */ 	jal	modelGetPartNodeData
/*  f00fa08:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f00fa0c:	50400005 */ 	beqzl	$v0,.L0f00fa24
/*  f00fa10:	8e580008 */ 	lw	$t8,0x8($s2)
/*  f00fa14:	824f005a */ 	lb	$t7,0x5a($s2)
/*  f00fa18:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f00fa1c:	a259005a */ 	sb	$t9,0x5a($s2)
/*  f00fa20:	8e580008 */ 	lw	$t8,0x8($s2)
.L0f00fa24:
/*  f00fa24:	2401feff */ 	addiu	$at,$zero,-257
/*  f00fa28:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fa2c:	03015824 */ 	and	$t3,$t8,$at
/*  f00fa30:	ae4b0008 */ 	sw	$t3,0x8($s2)
/*  f00fa34:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fa38:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fa3c:	8e420014 */ 	lw	$v0,0x14($s2)
/*  f00fa40:	10400213 */ 	beqz	$v0,.L0f010290
/*  f00fa44:	00000000 */ 	nop
/*  f00fa48:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f00fa4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fa50:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00fa54:	e6500088 */ 	swc1	$f16,0x88($s2)
/*  f00fa58:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f00fa5c:	e652008c */ 	swc1	$f18,0x8c($s2)
/*  f00fa60:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f00fa64:	0fc1c3c2 */ 	jal	func0f070f08
/*  f00fa68:	e6440090 */ 	swc1	$f4,0x90($s2)
/*  f00fa6c:	10000208 */ 	b	.L0f010290
/*  f00fa70:	00000000 */ 	nop
/*  f00fa74:	12a00206 */ 	beqz	$s5,.L0f010290
/*  f00fa78:	00000000 */ 	nop
/*  f00fa7c:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f00fa80:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fa84:	01946824 */ 	and	$t5,$t4,$s4
/*  f00fa88:	15a00201 */ 	bnez	$t5,.L0f010290
/*  f00fa8c:	00000000 */ 	nop
/*  f00fa90:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fa94:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fa98:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fa9c:	0fc03a43 */ 	jal	func0f00e90c
/*  f00faa0:	2645005c */ 	addiu	$a1,$s2,0x5c
/*  f00faa4:	100001fa */ 	b	.L0f010290
/*  f00faa8:	00000000 */ 	nop
/*  f00faac:	12a001f8 */ 	beqz	$s5,.L0f010290
/*  f00fab0:	00000000 */ 	nop
/*  f00fab4:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f00fab8:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fabc:	01d47824 */ 	and	$t7,$t6,$s4
/*  f00fac0:	15e001f3 */ 	bnez	$t7,.L0f010290
/*  f00fac4:	00000000 */ 	nop
/*  f00fac8:	0fc033b9 */ 	jal	func0f00cee4
/*  f00facc:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fad0:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fad4:	0fc03a43 */ 	jal	func0f00e90c
/*  f00fad8:	2645005c */ 	addiu	$a1,$s2,0x5c
/*  f00fadc:	e654009c */ 	swc1	$f20,0x9c($s2)
/*  f00fae0:	e65400a0 */ 	swc1	$f20,0xa0($s2)
/*  f00fae4:	e65400ac */ 	swc1	$f20,0xac($s2)
/*  f00fae8:	e65400b0 */ 	swc1	$f20,0xb0($s2)
/*  f00faec:	e65400b4 */ 	swc1	$f20,0xb4($s2)
/*  f00faf0:	e65400b8 */ 	swc1	$f20,0xb8($s2)
/*  f00faf4:	e65400bc */ 	swc1	$f20,0xbc($s2)
/*  f00faf8:	e65400c0 */ 	swc1	$f20,0xc0($s2)
/*  f00fafc:	e65400c4 */ 	swc1	$f20,0xc4($s2)
/*  f00fb00:	e65400c8 */ 	swc1	$f20,0xc8($s2)
/*  f00fb04:	ae4000cc */ 	sw	$zero,0xcc($s2)
/*  f00fb08:	e65400d0 */ 	swc1	$f20,0xd0($s2)
/*  f00fb0c:	e65400d4 */ 	swc1	$f20,0xd4($s2)
/*  f00fb10:	e65400d8 */ 	swc1	$f20,0xd8($s2)
/*  f00fb14:	100001de */ 	b	.L0f010290
/*  f00fb18:	e65400dc */ 	swc1	$f20,0xdc($s2)
/*  f00fb1c:	12a001dc */ 	beqz	$s5,.L0f010290
/*  f00fb20:	00000000 */ 	nop
/*  f00fb24:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f00fb28:	0334c024 */ 	and	$t8,$t9,$s4
/*  f00fb2c:	170001d8 */ 	bnez	$t8,.L0f010290
/*  f00fb30:	00000000 */ 	nop
/*  f00fb34:	8e4b0064 */ 	lw	$t3,0x64($s2)
/*  f00fb38:	8e4c006c */ 	lw	$t4,0x6c($s2)
/*  f00fb3c:	e654005c */ 	swc1	$f20,0x5c($s2)
/*  f00fb40:	448b3000 */ 	mtc1	$t3,$f6
/*  f00fb44:	448c8000 */ 	mtc1	$t4,$f16
/*  f00fb48:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fb4c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f00fb50:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fb54:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f00fb58:	46164283 */ 	div.s	$f10,$f8,$f22
/*  f00fb5c:	46169103 */ 	div.s	$f4,$f18,$f22
/*  f00fb60:	e64a0064 */ 	swc1	$f10,0x64($s2)
/*  f00fb64:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fb68:	e644006c */ 	swc1	$f4,0x6c($s2)
/*  f00fb6c:	100001c8 */ 	b	.L0f010290
/*  f00fb70:	00000000 */ 	nop
/*  f00fb74:	12a001c6 */ 	beqz	$s5,.L0f010290
/*  f00fb78:	00000000 */ 	nop
/*  f00fb7c:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f00fb80:	01b47024 */ 	and	$t6,$t5,$s4
/*  f00fb84:	15c001c2 */ 	bnez	$t6,.L0f010290
/*  f00fb88:	00000000 */ 	nop
/*  f00fb8c:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f00fb90:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f00fb94:	07230005 */ 	bgezl	$t9,.L0f00fbac
/*  f00fb98:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fb9c:	0fc0387e */ 	jal	func0f00e1f8
/*  f00fba0:	86440006 */ 	lh	$a0,0x6($s2)
/*  f00fba4:	a642005c */ 	sh	$v0,0x5c($s2)
/*  f00fba8:	02402025 */ 	or	$a0,$s2,$zero
.L0f00fbac:
/*  f00fbac:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fbb0:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fbb4:	100001b6 */ 	b	.L0f010290
/*  f00fbb8:	00000000 */ 	nop
/*  f00fbbc:	12a001b4 */ 	beqz	$s5,.L0f010290
/*  f00fbc0:	00000000 */ 	nop
/*  f00fbc4:	8e58000c */ 	lw	$t8,0xc($s2)
/*  f00fbc8:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fbcc:	03145824 */ 	and	$t3,$t8,$s4
/*  f00fbd0:	156001af */ 	bnez	$t3,.L0f010290
/*  f00fbd4:	00000000 */ 	nop
/*  f00fbd8:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fbdc:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fbe0:	8e420014 */ 	lw	$v0,0x14($s2)
/*  f00fbe4:	50400008 */ 	beqzl	$v0,.L0f00fc08
/*  f00fbe8:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f00fbec:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f00fbf0:	e6460060 */ 	swc1	$f6,0x60($s2)
/*  f00fbf4:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f00fbf8:	e6480064 */ 	swc1	$f8,0x64($s2)
/*  f00fbfc:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f00fc00:	e64a0068 */ 	swc1	$f10,0x68($s2)
/*  f00fc04:	8e4c0008 */ 	lw	$t4,0x8($s2)
.L0f00fc08:
/*  f00fc08:	8fa20238 */ 	lw	$v0,0x238($sp)
/*  f00fc0c:	3c017f1b */ 	lui	$at,%hi(var7f1a8154)
/*  f00fc10:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f00fc14:	05a10011 */ 	bgez	$t5,.L0f00fc5c
/*  f00fc18:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f00fc1c:	8fa20234 */ 	lw	$v0,0x234($sp)
/*  f00fc20:	3c017f1b */ 	lui	$at,%hi(var7f1a8158)
/*  f00fc24:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f00fc28:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f00fc2c:	24420028 */ 	addiu	$v0,$v0,0x28
/*  f00fc30:	afa20234 */ 	sw	$v0,0x234($sp)
/*  f00fc34:	0c0058dd */ 	jal	func00016374
/*  f00fc38:	c42c8154 */ 	lwc1	$f12,%lo(var7f1a8154)($at)
/*  f00fc3c:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f00fc40:	0c005768 */ 	jal	func00015da0
/*  f00fc44:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f00fc48:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f00fc4c:	0c005844 */ 	jal	func00016110
/*  f00fc50:	2645001c */ 	addiu	$a1,$s2,0x1c
/*  f00fc54:	1000018e */ 	b	.L0f010290
/*  f00fc58:	00000000 */ 	nop
.L0f00fc5c:
/*  f00fc5c:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f00fc60:	24420028 */ 	addiu	$v0,$v0,0x28
/*  f00fc64:	afa20238 */ 	sw	$v0,0x238($sp)
/*  f00fc68:	0c0058dd */ 	jal	func00016374
/*  f00fc6c:	c42c8158 */ 	lwc1	$f12,%lo(var7f1a8158)($at)
/*  f00fc70:	27a401a8 */ 	addiu	$a0,$sp,0x1a8
/*  f00fc74:	0c005768 */ 	jal	func00015da0
/*  f00fc78:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f00fc7c:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f00fc80:	0c005844 */ 	jal	func00016110
/*  f00fc84:	2645001c */ 	addiu	$a1,$s2,0x1c
/*  f00fc88:	10000181 */ 	b	.L0f010290
/*  f00fc8c:	00000000 */ 	nop
/*  f00fc90:	12a0017f */ 	beqz	$s5,.L0f010290
/*  f00fc94:	00000000 */ 	nop
/*  f00fc98:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f00fc9c:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fca0:	01d47824 */ 	and	$t7,$t6,$s4
/*  f00fca4:	15e0017a */ 	bnez	$t7,.L0f010290
/*  f00fca8:	00000000 */ 	nop
/*  f00fcac:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fcb0:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fcb4:	10000176 */ 	b	.L0f010290
/*  f00fcb8:	00000000 */ 	nop
/*  f00fcbc:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x318)
/*  f00fcc0:	8f39a2d8 */ 	lw	$t9,%lo(g_Vars+0x318)($t9)
/*  f00fcc4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f00fcc8:	3c04800a */ 	lui	$a0,%hi(var8009cc30)
/*  f00fccc:	13200017 */ 	beqz	$t9,.L0f00fd2c
/*  f00fcd0:	00000000 */ 	nop
/*  f00fcd4:	8c84cc30 */ 	lw	$a0,%lo(var8009cc30)($a0)
/*  f00fcd8:	04800014 */ 	bltz	$a0,.L0f00fd2c
/*  f00fcdc:	00000000 */ 	nop
/*  f00fce0:	0fc62389 */ 	jal	func0f188e24
/*  f00fce4:	00000000 */ 	nop
/*  f00fce8:	80430001 */ 	lb	$v1,0x1($v0)
/*  f00fcec:	90450002 */ 	lbu	$a1,0x2($v0)
/*  f00fcf0:	18600005 */ 	blez	$v1,.L0f00fd08
/*  f00fcf4:	28610014 */ 	slti	$at,$v1,0x14
/*  f00fcf8:	10200003 */ 	beqz	$at,.L0f00fd08
/*  f00fcfc:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f00fd00:	02585821 */ 	addu	$t3,$s2,$t8
/*  f00fd04:	a565005a */ 	sh	$a1,0x5a($t3)
.L0f00fd08:
/*  f00fd08:	80430003 */ 	lb	$v1,0x3($v0)
/*  f00fd0c:	18600007 */ 	blez	$v1,.L0f00fd2c
/*  f00fd10:	28610014 */ 	slti	$at,$v1,0x14
/*  f00fd14:	10200005 */ 	beqz	$at,.L0f00fd2c
/*  f00fd18:	00000000 */ 	nop
/*  f00fd1c:	904c0004 */ 	lbu	$t4,0x4($v0)
/*  f00fd20:	00036880 */ 	sll	$t5,$v1,0x2
/*  f00fd24:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f00fd28:	a5cc005a */ 	sh	$t4,0x5a($t6)
.L0f00fd2c:
/*  f00fd2c:	18a00158 */ 	blez	$a1,.L0f010290
/*  f00fd30:	00000000 */ 	nop
/*  f00fd34:	12a00156 */ 	beqz	$s5,.L0f010290
/*  f00fd38:	00000000 */ 	nop
/*  f00fd3c:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f00fd40:	00008825 */ 	or	$s1,$zero,$zero
/*  f00fd44:	01f4c824 */ 	and	$t9,$t7,$s4
/*  f00fd48:	17200151 */ 	bnez	$t9,.L0f010290
/*  f00fd4c:	00000000 */ 	nop
/*  f00fd50:	02408025 */ 	or	$s0,$s2,$zero
.L0f00fd54:
/*  f00fd54:	9618005e */ 	lhu	$t8,0x5e($s0)
/*  f00fd58:	5b000007 */ 	blezl	$t8,.L0f00fd78
/*  f00fd5c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f00fd60:	9604005c */ 	lhu	$a0,0x5c($s0)
/*  f00fd64:	52e40004 */ 	beql	$s7,$a0,.L0f00fd78
/*  f00fd68:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f00fd6c:	0fc2486d */ 	jal	propLoad
/*  f00fd70:	00000000 */ 	nop
/*  f00fd74:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f00fd78:
/*  f00fd78:	163efff6 */ 	bne	$s1,$s8,.L0f00fd54
/*  f00fd7c:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f00fd80:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fd84:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fd88:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fd8c:	10000140 */ 	b	.L0f010290
/*  f00fd90:	00000000 */ 	nop
/*  f00fd94:	12a0013e */ 	beqz	$s5,.L0f010290
/*  f00fd98:	00000000 */ 	nop
/*  f00fd9c:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f00fda0:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fda4:	01746824 */ 	and	$t5,$t3,$s4
/*  f00fda8:	15a00139 */ 	bnez	$t5,.L0f010290
/*  f00fdac:	00000000 */ 	nop
/*  f00fdb0:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fdb4:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fdb8:	8e460018 */ 	lw	$a2,0x18($s2)
/*  f00fdbc:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f00fdc0:	50c0000d */ 	beqzl	$a2,.L0f00fdf8
/*  f00fdc4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f00fdc8:	0c006a47 */ 	jal	modelGetPart
/*  f00fdcc:	8cc40008 */ 	lw	$a0,0x8($a2)
/*  f00fdd0:	10400008 */ 	beqz	$v0,.L0f00fdf4
/*  f00fdd4:	00402825 */ 	or	$a1,$v0,$zero
/*  f00fdd8:	0c006a87 */ 	jal	modelGetNodeData
/*  f00fddc:	8e440018 */ 	lw	$a0,0x18($s2)
/*  f00fde0:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f00fde4:	3c011000 */ 	lui	$at,0x1000
/*  f00fde8:	01817024 */ 	and	$t6,$t4,$at
/*  f00fdec:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f00fdf0:	ac4f0000 */ 	sw	$t7,0x0($v0)
.L0f00fdf4:
/*  f00fdf4:	3c01bf80 */ 	lui	$at,0xbf80
.L0f00fdf8:
/*  f00fdf8:	44818000 */ 	mtc1	$at,$f16
/*  f00fdfc:	e6540064 */ 	swc1	$f20,0x64($s2)
/*  f00fe00:	e6540068 */ 	swc1	$f20,0x68($s2)
/*  f00fe04:	e654006c */ 	swc1	$f20,0x6c($s2)
/*  f00fe08:	e6540070 */ 	swc1	$f20,0x70($s2)
/*  f00fe0c:	e6540078 */ 	swc1	$f20,0x78($s2)
/*  f00fe10:	e654007c */ 	swc1	$f20,0x7c($s2)
/*  f00fe14:	8e44005c */ 	lw	$a0,0x5c($s2)
/*  f00fe18:	0c006134 */ 	jal	ailistFindById
/*  f00fe1c:	e6500074 */ 	swc1	$f16,0x74($s2)
/*  f00fe20:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f00fe24:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f00fe28:	a6400060 */ 	sh	$zero,0x60($s2)
/*  f00fe2c:	a6590062 */ 	sh	$t9,0x62($s2)
/*  f00fe30:	ae400080 */ 	sw	$zero,0x80($s2)
/*  f00fe34:	10000116 */ 	b	.L0f010290
/*  f00fe38:	ae400084 */ 	sw	$zero,0x84($s2)
/*  f00fe3c:	8fb8023c */ 	lw	$t8,0x23c($sp)
/*  f00fe40:	13000113 */ 	beqz	$t8,.L0f010290
/*  f00fe44:	00000000 */ 	nop
/*  f00fe48:	12a00111 */ 	beqz	$s5,.L0f010290
/*  f00fe4c:	00000000 */ 	nop
/*  f00fe50:	8e4b000c */ 	lw	$t3,0xc($s2)
/*  f00fe54:	02402025 */ 	or	$a0,$s2,$zero
/*  f00fe58:	01746824 */ 	and	$t5,$t3,$s4
/*  f00fe5c:	15a0010c */ 	bnez	$t5,.L0f010290
/*  f00fe60:	00000000 */ 	nop
/*  f00fe64:	0fc033b9 */ 	jal	func0f00cee4
/*  f00fe68:	02602825 */ 	or	$a1,$s3,$zero
/*  f00fe6c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f00fe70:	44819000 */ 	mtc1	$at,$f18
/*  f00fe74:	8e500014 */ 	lw	$s0,0x14($s2)
/*  f00fe78:	e6540064 */ 	swc1	$f20,0x64($s2)
/*  f00fe7c:	e6540068 */ 	swc1	$f20,0x68($s2)
/*  f00fe80:	e6540078 */ 	swc1	$f20,0x78($s2)
/*  f00fe84:	e654007c */ 	swc1	$f20,0x7c($s2)
/*  f00fe88:	e6540080 */ 	swc1	$f20,0x80($s2)
/*  f00fe8c:	8e44005c */ 	lw	$a0,0x5c($s2)
/*  f00fe90:	0c006134 */ 	jal	ailistFindById
/*  f00fe94:	e652006c */ 	swc1	$f18,0x6c($s2)
/*  f00fe98:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f00fe9c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f00fea0:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f00fea4:	000e7800 */ 	sll	$t7,$t6,0x0
/*  f00fea8:	a6400060 */ 	sh	$zero,0x60($s2)
/*  f00feac:	a64c0062 */ 	sh	$t4,0x62($s2)
/*  f00feb0:	ae400088 */ 	sw	$zero,0x88($s2)
/*  f00feb4:	05e1000b */ 	bgez	$t7,.L0f00fee4
/*  f00feb8:	ae40008c */ 	sw	$zero,0x8c($s2)
/*  f00febc:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f00fec0:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f00fec4:	00003025 */ 	or	$a2,$zero,$zero
/*  f00fec8:	0c00a8db */ 	jal	func0002a36c
/*  f00fecc:	00003825 */ 	or	$a3,$zero,$zero
/*  f00fed0:	3c0141f0 */ 	lui	$at,0x41f0
/*  f00fed4:	44812000 */ 	mtc1	$at,$f4
/*  f00fed8:	00000000 */ 	nop
/*  f00fedc:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f00fee0:	e606000c */ 	swc1	$f6,0xc($s0)
.L0f00fee4:
/*  f00fee4:	9218003f */ 	lbu	$t8,0x3f($s0)
/*  f00fee8:	370b0020 */ 	ori	$t3,$t8,0x20
/*  f00feec:	100000e8 */ 	b	.L0f010290
/*  f00fef0:	a20b003f */ 	sb	$t3,0x3f($s0)
/*  f00fef4:	12a000e6 */ 	beqz	$s5,.L0f010290
/*  f00fef8:	00000000 */ 	nop
/*  f00fefc:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f00ff00:	02402025 */ 	or	$a0,$s2,$zero
/*  f00ff04:	01b46024 */ 	and	$t4,$t5,$s4
/*  f00ff08:	158000e1 */ 	bnez	$t4,.L0f010290
/*  f00ff0c:	00000000 */ 	nop
/*  f00ff10:	0fc033b9 */ 	jal	func0f00cee4
/*  f00ff14:	02602825 */ 	or	$a1,$s3,$zero
/*  f00ff18:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f00ff1c:	8e420014 */ 	lw	$v0,0x14($s2)
/*  f00ff20:	3c012000 */ 	lui	$at,0x2000
/*  f00ff24:	01c17825 */ 	or	$t7,$t6,$at
/*  f00ff28:	ae4f0008 */ 	sw	$t7,0x8($s2)
/*  f00ff2c:	9058003f */ 	lbu	$t8,0x3f($v0)
/*  f00ff30:	370b0020 */ 	ori	$t3,$t8,0x20
/*  f00ff34:	a04b003f */ 	sb	$t3,0x3f($v0)
/*  f00ff38:	e6540078 */ 	swc1	$f20,0x78($s2)
/*  f00ff3c:	e654007c */ 	swc1	$f20,0x7c($s2)
/*  f00ff40:	e6540080 */ 	swc1	$f20,0x80($s2)
/*  f00ff44:	e65400d0 */ 	swc1	$f20,0xd0($s2)
/*  f00ff48:	e65400d4 */ 	swc1	$f20,0xd4($s2)
/*  f00ff4c:	e65400dc */ 	swc1	$f20,0xdc($s2)
/*  f00ff50:	e65400d8 */ 	swc1	$f20,0xd8($s2)
/*  f00ff54:	0c006134 */ 	jal	ailistFindById
/*  f00ff58:	8e44005c */ 	lw	$a0,0x5c($s2)
/*  f00ff5c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f00ff60:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f00ff64:	a6400060 */ 	sh	$zero,0x60($s2)
/*  f00ff68:	a6430062 */ 	sh	$v1,0x62($s2)
/*  f00ff6c:	ae400088 */ 	sw	$zero,0x88($s2)
/*  f00ff70:	ae40008c */ 	sw	$zero,0x8c($s2)
/*  f00ff74:	a6430094 */ 	sh	$v1,0x94($s2)
/*  f00ff78:	ae4000bc */ 	sw	$zero,0xbc($s2)
/*  f00ff7c:	a2400096 */ 	sb	$zero,0x96($s2)
/*  f00ff80:	e65400a0 */ 	swc1	$f20,0xa0($s2)
/*  f00ff84:	e654009c */ 	swc1	$f20,0x9c($s2)
/*  f00ff88:	e6540098 */ 	swc1	$f20,0x98($s2)
/*  f00ff8c:	e65400b0 */ 	swc1	$f20,0xb0($s2)
/*  f00ff90:	e65400ac */ 	swc1	$f20,0xac($s2)
/*  f00ff94:	e65400a8 */ 	swc1	$f20,0xa8($s2)
/*  f00ff98:	e65400a4 */ 	swc1	$f20,0xa4($s2)
/*  f00ff9c:	e65400b4 */ 	swc1	$f20,0xb4($s2)
/*  f00ffa0:	3c017f1b */ 	lui	$at,%hi(var7f1a815c)
/*  f00ffa4:	c428815c */ 	lwc1	$f8,%lo(var7f1a815c)($at)
/*  f00ffa8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f00ffac:	ae4000c0 */ 	sw	$zero,0xc0($s2)
/*  f00ffb0:	ae4000c4 */ 	sw	$zero,0xc4($s2)
/*  f00ffb4:	a2400097 */ 	sb	$zero,0x97($s2)
/*  f00ffb8:	a64d0090 */ 	sh	$t5,0x90($s2)
/*  f00ffbc:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f00ffc0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00ffc4:	0c0048f2 */ 	jal	malloc
/*  f00ffc8:	e64800b8 */ 	swc1	$f8,0xb8($s2)
/*  f00ffcc:	ae4200e0 */ 	sw	$v0,0xe0($s2)
/*  f00ffd0:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f00ffd4:	0c0048f2 */ 	jal	malloc
/*  f00ffd8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00ffdc:	8e4c00e0 */ 	lw	$t4,0xe0($s2)
/*  f00ffe0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f00ffe4:	3c017f1b */ 	lui	$at,%hi(var7f1a8160)
/*  f00ffe8:	ad820004 */ 	sw	$v0,0x4($t4)
/*  f00ffec:	8e4e00e0 */ 	lw	$t6,0xe0($s2)
/*  f00fff0:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f00fff4:	a1e30000 */ 	sb	$v1,0x0($t7)
/*  f00fff8:	8e5900e0 */ 	lw	$t9,0xe0($s2)
/*  f00fffc:	af230008 */ 	sw	$v1,0x8($t9)
/*  f010000:	8e5800e0 */ 	lw	$t8,0xe0($s2)
/*  f010004:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f010008:	8e4b00e0 */ 	lw	$t3,0xe0($s2)
/*  f01000c:	a1600001 */ 	sb	$zero,0x1($t3)
/*  f010010:	8e4d00e0 */ 	lw	$t5,0xe0($s2)
/*  f010014:	c42a8160 */ 	lwc1	$f10,%lo(var7f1a8160)($at)
/*  f010018:	3c017f1b */ 	lui	$at,%hi(var7f1a8164)
/*  f01001c:	e5aa000c */ 	swc1	$f10,0xc($t5)
/*  f010020:	8e4c00e0 */ 	lw	$t4,0xe0($s2)
/*  f010024:	c4308164 */ 	lwc1	$f16,%lo(var7f1a8164)($at)
/*  f010028:	e5900010 */ 	swc1	$f16,0x10($t4)
/*  f01002c:	8e4e00e0 */ 	lw	$t6,0xe0($s2)
/*  f010030:	e5d40014 */ 	swc1	$f20,0x14($t6)
/*  f010034:	10000096 */ 	b	.L0f010290
/*  f010038:	ae4000e4 */ 	sw	$zero,0xe4($s2)
/*  f01003c:	12a00094 */ 	beqz	$s5,.L0f010290
/*  f010040:	00000000 */ 	nop
/*  f010044:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f010048:	02402025 */ 	or	$a0,$s2,$zero
/*  f01004c:	01f4c824 */ 	and	$t9,$t7,$s4
/*  f010050:	1720008f */ 	bnez	$t9,.L0f010290
/*  f010054:	00000000 */ 	nop
/*  f010058:	0fc033b9 */ 	jal	func0f00cee4
/*  f01005c:	02602825 */ 	or	$a1,$s3,$zero
/*  f010060:	3c01bf80 */ 	lui	$at,0xbf80
/*  f010064:	44810000 */ 	mtc1	$at,$f0
/*  f010068:	e6540074 */ 	swc1	$f20,0x74($s2)
/*  f01006c:	e6540078 */ 	swc1	$f20,0x78($s2)
/*  f010070:	e6540064 */ 	swc1	$f20,0x64($s2)
/*  f010074:	e6540068 */ 	swc1	$f20,0x68($s2)
/*  f010078:	e654006c */ 	swc1	$f20,0x6c($s2)
/*  f01007c:	e6540080 */ 	swc1	$f20,0x80($s2)
/*  f010080:	8e44005c */ 	lw	$a0,0x5c($s2)
/*  f010084:	e640007c */ 	swc1	$f0,0x7c($s2)
/*  f010088:	0c006134 */ 	jal	ailistFindById
/*  f01008c:	e6400070 */ 	swc1	$f0,0x70($s2)
/*  f010090:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f010094:	ae42005c */ 	sw	$v0,0x5c($s2)
/*  f010098:	a6400060 */ 	sh	$zero,0x60($s2)
/*  f01009c:	a6580062 */ 	sh	$t8,0x62($s2)
/*  f0100a0:	ae400084 */ 	sw	$zero,0x84($s2)
/*  f0100a4:	1000007a */ 	b	.L0f010290
/*  f0100a8:	ae400088 */ 	sw	$zero,0x88($s2)
/*  f0100ac:	864b0006 */ 	lh	$t3,0x6($s2)
/*  f0100b0:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0100b4:	01732021 */ 	addu	$a0,$t3,$s3
/*  f0100b8:	10400004 */ 	beqz	$v0,.L0f0100cc
/*  f0100bc:	ae42000c */ 	sw	$v0,0xc($s2)
/*  f0100c0:	8c4d0040 */ 	lw	$t5,0x40($v0)
/*  f0100c4:	35ac0010 */ 	ori	$t4,$t5,0x10
/*  f0100c8:	ac4c0040 */ 	sw	$t4,0x40($v0)
.L0f0100cc:
/*  f0100cc:	0fc0429a */ 	jal	func0f010a68
/*  f0100d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0100d4:	1000006e */ 	b	.L0f010290
/*  f0100d8:	00000000 */ 	nop
/*  f0100dc:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f0100e0:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0100e4:	01d32021 */ 	addu	$a0,$t6,$s3
/*  f0100e8:	10400004 */ 	beqz	$v0,.L0f0100fc
/*  f0100ec:	ae420024 */ 	sw	$v0,0x24($s2)
/*  f0100f0:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f0100f4:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f0100f8:	ac590040 */ 	sw	$t9,0x40($v0)
.L0f0100fc:
/*  f0100fc:	0fc44bce */ 	jal	textoverrideInsert
/*  f010100:	02402025 */ 	or	$a0,$s2,$zero
/*  f010104:	10000062 */ 	b	.L0f010290
/*  f010108:	00000000 */ 	nop
/*  f01010c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f010110:	0fc042a0 */ 	jal	func0f010a80
/*  f010114:	02402025 */ 	or	$a0,$s2,$zero
/*  f010118:	0fc5b367 */ 	jal	getDifficulty
/*  f01011c:	00000000 */ 	nop
/*  f010120:	14400002 */ 	bnez	$v0,.L0f01012c
/*  f010124:	00000000 */ 	nop
/*  f010128:	24100003 */ 	addiu	$s0,$zero,0x3
.L0f01012c:
/*  f01012c:	0fc5b367 */ 	jal	getDifficulty
/*  f010130:	00000000 */ 	nop
/*  f010134:	24010001 */ 	addiu	$at,$zero,0x1
/*  f010138:	54410003 */ 	bnel	$v0,$at,.L0f010148
/*  f01013c:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f010140:	24100002 */ 	addiu	$s0,$zero,0x2
/*  f010144:	8e580004 */ 	lw	$t8,0x4($s2)
.L0f010148:
/*  f010148:	16180051 */ 	bne	$s0,$t8,.L0f010290
/*  f01014c:	00000000 */ 	nop
/*  f010150:	8e4b0008 */ 	lw	$t3,0x8($s2)
/*  f010154:	3c01800a */ 	lui	$at,%hi(g_Briefing)
/*  f010158:	1000004d */ 	b	.L0f010290
/*  f01015c:	a42bdfc8 */ 	sh	$t3,%lo(g_Briefing)($at)
/*  f010160:	8e4d0004 */ 	lw	$t5,0x4($s2)
/*  f010164:	3c0142c8 */ 	lui	$at,0x42c8
/*  f010168:	44810000 */ 	mtc1	$at,$f0
/*  f01016c:	448d9000 */ 	mtc1	$t5,$f18
/*  f010170:	8e4c0008 */ 	lw	$t4,0x8($s2)
/*  f010174:	8e4e000c */ 	lw	$t6,0xc($s2)
/*  f010178:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f01017c:	448c4000 */ 	mtc1	$t4,$f8
/*  f010180:	448e9000 */ 	mtc1	$t6,$f18
/*  f010184:	8e4f0010 */ 	lw	$t7,0x10($s2)
/*  f010188:	8e590014 */ 	lw	$t9,0x14($s2)
/*  f01018c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f010190:	448f4000 */ 	mtc1	$t7,$f8
/*  f010194:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f010198:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f01019c:	44999000 */ 	mtc1	$t9,$f18
/*  f0101a0:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0101a4:	e6460004 */ 	swc1	$f6,0x4($s2)
/*  f0101a8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0101ac:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0101b0:	e6500008 */ 	swc1	$f16,0x8($s2)
/*  f0101b4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0101b8:	46165403 */ 	div.s	$f16,$f10,$f22
/*  f0101bc:	e646000c */ 	swc1	$f6,0xc($s2)
/*  f0101c0:	46162183 */ 	div.s	$f6,$f4,$f22
/*  f0101c4:	e6500010 */ 	swc1	$f16,0x10($s2)
/*  f0101c8:	10000031 */ 	b	.L0f010290
/*  f0101cc:	e6460014 */ 	swc1	$f6,0x14($s2)
/*  f0101d0:	0fc042a6 */ 	jal	func0f010a98
/*  f0101d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0101d8:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f0101dc:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f0101e0:	1020002b */ 	beqz	$at,.L0f010290
/*  f0101e4:	00025840 */ 	sll	$t3,$v0,0x1
/*  f0101e8:	8e580008 */ 	lw	$t8,0x8($s2)
/*  f0101ec:	3c01800a */ 	lui	$at,%hi(g_Briefing+0x2)
/*  f0101f0:	002b0821 */ 	addu	$at,$at,$t3
/*  f0101f4:	a438dfca */ 	sh	$t8,%lo(g_Briefing+0x2)($at)
/*  f0101f8:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f0101fc:	824d000f */ 	lb	$t5,0xf($s2)
/*  f010200:	3c01800a */ 	lui	$at,%hi(g_Briefing+0xe)
/*  f010204:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f010208:	002e0821 */ 	addu	$at,$at,$t6
/*  f01020c:	10000020 */ 	b	.L0f010290
/*  f010210:	a42ddfd6 */ 	sh	$t5,%lo(g_Briefing+0xe)($at)
/*  f010214:	0fc042b5 */ 	jal	objectiveAddRoomEnteredCriteria
/*  f010218:	02402025 */ 	or	$a0,$s2,$zero
/*  f01021c:	1000001c */ 	b	.L0f010290
/*  f010220:	00000000 */ 	nop
/*  f010224:	0fc042bb */ 	jal	objectiveAddMultiroomEnteredCriteria
/*  f010228:	02402025 */ 	or	$a0,$s2,$zero
/*  f01022c:	10000018 */ 	b	.L0f010290
/*  f010230:	00000000 */ 	nop
/*  f010234:	0fc042c1 */ 	jal	objectiveAddHolographCriteria
/*  f010238:	02402025 */ 	or	$a0,$s2,$zero
/*  f01023c:	10000014 */ 	b	.L0f010290
/*  f010240:	00000000 */ 	nop
/*  f010244:	3c038007 */ 	lui	$v1,%hi(var80069964)
/*  f010248:	24639964 */ 	addiu	$v1,$v1,%lo(var80069964)
/*  f01024c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f010250:	2401ffff */ 	addiu	$at,$zero,-1
/*  f010254:	14410003 */ 	bne	$v0,$at,.L0f010264
/*  f010258:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f01025c:	3c018007 */ 	lui	$at,%hi(var80069960)
/*  f010260:	ac329960 */ 	sw	$s2,%lo(var80069960)($at)
.L0f010264:
/*  f010264:	1000000a */ 	b	.L0f010290
/*  f010268:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f01026c:	12a00008 */ 	beqz	$s5,.L0f010290
/*  f010270:	00000000 */ 	nop
/*  f010274:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f010278:	02402025 */ 	or	$a0,$s2,$zero
/*  f01027c:	0334c024 */ 	and	$t8,$t9,$s4
/*  f010280:	17000003 */ 	bnez	$t8,.L0f010290
/*  f010284:	00000000 */ 	nop
/*  f010288:	0fc03666 */ 	jal	func0f00d998
/*  f01028c:	02602825 */ 	or	$a1,$s3,$zero
.L0f010290:
/*  f010290:	0fc24784 */ 	jal	setupGetCommandLength
/*  f010294:	02402025 */ 	or	$a0,$s2,$zero
/*  f010298:	00025880 */ 	sll	$t3,$v0,0x2
/*  f01029c:	01729021 */ 	addu	$s2,$t3,$s2
/*  f0102a0:	92430003 */ 	lbu	$v1,0x3($s2)
/*  f0102a4:	24010034 */ 	addiu	$at,$zero,0x34
/*  f0102a8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0102ac:	5461fcd0 */ 	bnel	$v1,$at,.L0f00f5f0
/*  f0102b0:	2478ffff */ 	addiu	$t8,$v1,-1
/*  f0102b4:	00009825 */ 	or	$s3,$zero,$zero
.L0f0102b8:
/*  f0102b8:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x318)
/*  f0102bc:	8d8ca2d8 */ 	lw	$t4,%lo(g_Vars+0x318)($t4)
/*  f0102c0:	1180004f */ 	beqz	$t4,.L0f010400
/*  f0102c4:	00000000 */ 	nop
/*  f0102c8:	0fc63319 */ 	jal	mpHasSimulants
/*  f0102cc:	00000000 */ 	nop
/*  f0102d0:	1040004b */ 	beqz	$v0,.L0f010400
/*  f0102d4:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f0102d8:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f0102dc:	afa000fc */ 	sw	$zero,0xfc($sp)
/*  f0102e0:	10400003 */ 	beqz	$v0,.L0f0102f0
/*  f0102e4:	27a30120 */ 	addiu	$v1,$sp,0x120
/*  f0102e8:	10000002 */ 	b	.L0f0102f4
/*  f0102ec:	24120008 */ 	addiu	$s2,$zero,0x8
.L0f0102f0:
/*  f0102f0:	24120004 */ 	addiu	$s2,$zero,0x4
.L0f0102f4:
/*  f0102f4:	27a20100 */ 	addiu	$v0,$sp,0x100
.L0f0102f8:
/*  f0102f8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0102fc:	0043082b */ 	sltu	$at,$v0,$v1
/*  f010300:	1420fffd */ 	bnez	$at,.L0f0102f8
/*  f010304:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f010308:	1a40003d */ 	blez	$s2,.L0f010400
/*  f01030c:	00003025 */ 	or	$a2,$zero,$zero
/*  f010310:	3c14800b */ 	lui	$s4,%hi(g_MpSetup)
/*  f010314:	2694cb88 */ 	addiu	$s4,$s4,%lo(g_MpSetup)
/*  f010318:	27b10100 */ 	addiu	$s1,$sp,0x100
.L0f01031c:
/*  f01031c:	0c004b70 */ 	jal	random
/*  f010320:	afa60120 */ 	sw	$a2,0x120($sp)
/*  f010324:	0052001b */ 	divu	$zero,$v0,$s2
/*  f010328:	00001810 */ 	mfhi	$v1
/*  f01032c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f010330:	022d7021 */ 	addu	$t6,$s1,$t5
/*  f010334:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f010338:	00608025 */ 	or	$s0,$v1,$zero
/*  f01033c:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f010340:	16400002 */ 	bnez	$s2,.L0f01034c
/*  f010344:	00000000 */ 	nop
/*  f010348:	0007000d */ 	break	0x7
.L0f01034c:
/*  f01034c:	11e00011 */ 	beqz	$t7,.L0f010394
/*  f010350:	26190001 */ 	addiu	$t9,$s0,0x1
.L0f010354:
/*  f010354:	0332001a */ 	div	$zero,$t9,$s2
/*  f010358:	00008010 */ 	mfhi	$s0
/*  f01035c:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f010360:	02385821 */ 	addu	$t3,$s1,$t8
/*  f010364:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f010368:	16400002 */ 	bnez	$s2,.L0f010374
/*  f01036c:	00000000 */ 	nop
/*  f010370:	0007000d */ 	break	0x7
.L0f010374:
/*  f010374:	2401ffff */ 	addiu	$at,$zero,-1
/*  f010378:	16410004 */ 	bne	$s2,$at,.L0f01038c
/*  f01037c:	3c018000 */ 	lui	$at,0x8000
/*  f010380:	17210002 */ 	bne	$t9,$at,.L0f01038c
/*  f010384:	00000000 */ 	nop
/*  f010388:	0006000d */ 	break	0x6
.L0f01038c:
/*  f01038c:	5580fff1 */ 	bnezl	$t4,.L0f010354
/*  f010390:	26190001 */ 	addiu	$t9,$s0,0x1
.L0f010394:
/*  f010394:	968f0016 */ 	lhu	$t7,0x16($s4)
/*  f010398:	26190004 */ 	addiu	$t9,$s0,0x4
/*  f01039c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0103a0:	03385804 */ 	sllv	$t3,$t8,$t9
/*  f0103a4:	00106880 */ 	sll	$t5,$s0,0x2
/*  f0103a8:	022d7021 */ 	addu	$t6,$s1,$t5
/*  f0103ac:	01eb6024 */ 	and	$t4,$t7,$t3
/*  f0103b0:	1180000e */ 	beqz	$t4,.L0f0103ec
/*  f0103b4:	afae005c */ 	sw	$t6,0x5c($sp)
/*  f0103b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0103bc:	0fc6333e */ 	jal	mpIsSimSlotEnabled
/*  f0103c0:	afa60120 */ 	sw	$a2,0x120($sp)
/*  f0103c4:	10400009 */ 	beqz	$v0,.L0f0103ec
/*  f0103c8:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0103cc:	8fa400fc */ 	lw	$a0,0xfc($sp)
/*  f0103d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f0103d4:	0fc05212 */ 	jal	func0f014848
/*  f0103d8:	afa60120 */ 	sw	$a2,0x120($sp)
/*  f0103dc:	8fad00fc */ 	lw	$t5,0xfc($sp)
/*  f0103e0:	8fa60120 */ 	lw	$a2,0x120($sp)
/*  f0103e4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0103e8:	afae00fc */ 	sw	$t6,0xfc($sp)
.L0f0103ec:
/*  f0103ec:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0103f0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0103f4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0103f8:	14d2ffc8 */ 	bne	$a2,$s2,.L0f01031c
/*  f0103fc:	af380000 */ 	sw	$t8,0x0($t9)
.L0f010400:
/*  f010400:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x318)
/*  f010404:	8defa2d8 */ 	lw	$t7,%lo(g_Vars+0x318)($t7)
/*  f010408:	11e00003 */ 	beqz	$t7,.L0f010418
/*  f01040c:	00000000 */ 	nop
/*  f010410:	0fc61548 */ 	jal	scenarioReset
/*  f010414:	00000000 */ 	nop
.L0f010418:
/*  f010418:	3c12800a */ 	lui	$s2,%hi(g_StageSetup+0x10)
/*  f01041c:	8e52d040 */ 	lw	$s2,%lo(g_StageSetup+0x10)($s2)
/*  f010420:	24010034 */ 	addiu	$at,$zero,0x34
/*  f010424:	2417002b */ 	addiu	$s7,$zero,0x2b
/*  f010428:	92430003 */ 	lbu	$v1,0x3($s2)
/*  f01042c:	24160008 */ 	addiu	$s6,$zero,0x8
/*  f010430:	3c150200 */ 	lui	$s5,0x200
/*  f010434:	10610113 */ 	beq	$v1,$at,.L0f010884
/*  f010438:	3c140008 */ 	lui	$s4,0x8
/*  f01043c:	246bfffd */ 	addiu	$t3,$v1,-3
.L0f010440:
/*  f010440:	2d610030 */ 	sltiu	$at,$t3,0x30
/*  f010444:	10200102 */ 	beqz	$at,.L0f010850
/*  f010448:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f01044c:	3c017f1b */ 	lui	$at,%hi(var7f1a8168)
/*  f010450:	002b0821 */ 	addu	$at,$at,$t3
/*  f010454:	8c2b8168 */ 	lw	$t3,%lo(var7f1a8168)($at)
/*  f010458:	01600008 */ 	jr	$t3
/*  f01045c:	00000000 */ 	nop
/*  f010460:	8e4c0014 */ 	lw	$t4,0x14($s2)
/*  f010464:	118000fa */ 	beqz	$t4,.L0f010850
/*  f010468:	00000000 */ 	nop
/*  f01046c:	8e4d0008 */ 	lw	$t5,0x8($s2)
/*  f010470:	31ae8000 */ 	andi	$t6,$t5,0x8000
/*  f010474:	11c000f6 */ 	beqz	$t6,.L0f010850
/*  f010478:	00000000 */ 	nop
/*  f01047c:	86420006 */ 	lh	$v0,0x6($s2)
/*  f010480:	0fc24908 */ 	jal	setupCommandGetObject
/*  f010484:	02622021 */ 	addu	$a0,$s3,$v0
/*  f010488:	104000f1 */ 	beqz	$v0,.L0f010850
/*  f01048c:	00408025 */ 	or	$s0,$v0,$zero
/*  f010490:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f010494:	130000ee */ 	beqz	$t8,.L0f010850
/*  f010498:	00000000 */ 	nop
/*  f01049c:	8e590040 */ 	lw	$t9,0x40($s2)
/*  f0104a0:	8e460018 */ 	lw	$a2,0x18($s2)
/*  f0104a4:	03347825 */ 	or	$t7,$t9,$s4
/*  f0104a8:	ae4f0040 */ 	sw	$t7,0x40($s2)
/*  f0104ac:	8cc50014 */ 	lw	$a1,0x14($a2)
/*  f0104b0:	0c006bd6 */ 	jal	modelSetUnk14
/*  f0104b4:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0104b8:	8e440014 */ 	lw	$a0,0x14($s2)
/*  f0104bc:	0fc181a6 */ 	jal	propReparent
/*  f0104c0:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f0104c4:	100000e2 */ 	b	.L0f010850
/*  f0104c8:	00000000 */ 	nop
/*  f0104cc:	864b0004 */ 	lh	$t3,0x4($s2)
/*  f0104d0:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f0104d4:	01732021 */ 	addu	$a0,$t3,$s3
/*  f0104d8:	864c0006 */ 	lh	$t4,0x6($s2)
/*  f0104dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0104e0:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f0104e4:	01932021 */ 	addu	$a0,$t4,$s3
/*  f0104e8:	120000d9 */ 	beqz	$s0,.L0f010850
/*  f0104ec:	00402825 */ 	or	$a1,$v0,$zero
/*  f0104f0:	104000d7 */ 	beqz	$v0,.L0f010850
/*  f0104f4:	00000000 */ 	nop
/*  f0104f8:	920d0003 */ 	lbu	$t5,0x3($s0)
/*  f0104fc:	16cd00d4 */ 	bne	$s6,$t5,.L0f010850
/*  f010500:	00000000 */ 	nop
/*  f010504:	904e0003 */ 	lbu	$t6,0x3($v0)
/*  f010508:	16ce00d1 */ 	bne	$s6,$t6,.L0f010850
/*  f01050c:	00000000 */ 	nop
/*  f010510:	0fc22b6b */ 	jal	propweaponSetDual
/*  f010514:	02002025 */ 	or	$a0,$s0,$zero
/*  f010518:	100000cd */ 	b	.L0f010850
/*  f01051c:	00000000 */ 	nop
/*  f010520:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f010524:	8e510008 */ 	lw	$s1,0x8($s2)
/*  f010528:	0fc24908 */ 	jal	setupCommandGetObject
/*  f01052c:	02622021 */ 	addu	$a0,$s3,$v0
/*  f010530:	00408025 */ 	or	$s0,$v0,$zero
/*  f010534:	0fc24908 */ 	jal	setupCommandGetObject
/*  f010538:	02712021 */ 	addu	$a0,$s3,$s1
/*  f01053c:	120000c4 */ 	beqz	$s0,.L0f010850
/*  f010540:	00000000 */ 	nop
/*  f010544:	8e030014 */ 	lw	$v1,0x14($s0)
/*  f010548:	106000c1 */ 	beqz	$v1,.L0f010850
/*  f01054c:	00000000 */ 	nop
/*  f010550:	104000bf */ 	beqz	$v0,.L0f010850
/*  f010554:	00000000 */ 	nop
/*  f010558:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f01055c:	130000bc */ 	beqz	$t8,.L0f010850
/*  f010560:	00000000 */ 	nop
/*  f010564:	ae430004 */ 	sw	$v1,0x4($s2)
/*  f010568:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f01056c:	02402025 */ 	or	$a0,$s2,$zero
/*  f010570:	0fc03305 */ 	jal	func0f00cc14
/*  f010574:	ae590008 */ 	sw	$t9,0x8($s2)
/*  f010578:	8e0f0040 */ 	lw	$t7,0x40($s0)
/*  f01057c:	35eb0001 */ 	ori	$t3,$t7,0x1
/*  f010580:	100000b3 */ 	b	.L0f010850
/*  f010584:	ae0b0040 */ 	sw	$t3,0x40($s0)
/*  f010588:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f01058c:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f010590:	8e510008 */ 	lw	$s1,0x8($s2)
/*  f010594:	02622021 */ 	addu	$a0,$s3,$v0
/*  f010598:	0fc24908 */ 	jal	setupCommandGetObject
/*  f01059c:	afac00bc */ 	sw	$t4,0xbc($sp)
/*  f0105a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0105a4:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0105a8:	02712021 */ 	addu	$a0,$s3,$s1
/*  f0105ac:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f0105b0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0105b4:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0105b8:	026d2021 */ 	addu	$a0,$s3,$t5
/*  f0105bc:	120000a4 */ 	beqz	$s0,.L0f010850
/*  f0105c0:	00000000 */ 	nop
/*  f0105c4:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*  f0105c8:	11c000a1 */ 	beqz	$t6,.L0f010850
/*  f0105cc:	00000000 */ 	nop
/*  f0105d0:	1220009f */ 	beqz	$s1,.L0f010850
/*  f0105d4:	00000000 */ 	nop
/*  f0105d8:	8e380014 */ 	lw	$t8,0x14($s1)
/*  f0105dc:	1300009c */ 	beqz	$t8,.L0f010850
/*  f0105e0:	00000000 */ 	nop
/*  f0105e4:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f0105e8:	16f90099 */ 	bne	$s7,$t9,.L0f010850
/*  f0105ec:	00000000 */ 	nop
/*  f0105f0:	10400097 */ 	beqz	$v0,.L0f010850
/*  f0105f4:	00000000 */ 	nop
/*  f0105f8:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f0105fc:	11e00094 */ 	beqz	$t7,.L0f010850
/*  f010600:	00000000 */ 	nop
/*  f010604:	904b0003 */ 	lbu	$t3,0x3($v0)
/*  f010608:	24010001 */ 	addiu	$at,$zero,0x1
/*  f01060c:	02402025 */ 	or	$a0,$s2,$zero
/*  f010610:	1561008f */ 	bne	$t3,$at,.L0f010850
/*  f010614:	00000000 */ 	nop
/*  f010618:	ae500004 */ 	sw	$s0,0x4($s2)
/*  f01061c:	ae510008 */ 	sw	$s1,0x8($s2)
/*  f010620:	ae42000c */ 	sw	$v0,0xc($s2)
/*  f010624:	0fc03311 */ 	jal	func0f00cc44
/*  f010628:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f01062c:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f010630:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f010634:	358d0400 */ 	ori	$t5,$t4,0x400
/*  f010638:	ae0d000c */ 	sw	$t5,0xc($s0)
/*  f01063c:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f010640:	35d80400 */ 	ori	$t8,$t6,0x400
/*  f010644:	10000082 */ 	b	.L0f010850
/*  f010648:	ac78000c */ 	sw	$t8,0xc($v1)
/*  f01064c:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f010650:	8e510008 */ 	lw	$s1,0x8($s2)
/*  f010654:	0fc24908 */ 	jal	setupCommandGetObject
/*  f010658:	02622021 */ 	addu	$a0,$s3,$v0
/*  f01065c:	00408025 */ 	or	$s0,$v0,$zero
/*  f010660:	0fc24908 */ 	jal	setupCommandGetObject
/*  f010664:	02712021 */ 	addu	$a0,$s3,$s1
/*  f010668:	12000079 */ 	beqz	$s0,.L0f010850
/*  f01066c:	00000000 */ 	nop
/*  f010670:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f010674:	13200076 */ 	beqz	$t9,.L0f010850
/*  f010678:	00000000 */ 	nop
/*  f01067c:	10400074 */ 	beqz	$v0,.L0f010850
/*  f010680:	00000000 */ 	nop
/*  f010684:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f010688:	11e00071 */ 	beqz	$t7,.L0f010850
/*  f01068c:	00000000 */ 	nop
/*  f010690:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f010694:	24010001 */ 	addiu	$at,$zero,0x1
/*  f010698:	02402025 */ 	or	$a0,$s2,$zero
/*  f01069c:	1561006c */ 	bne	$t3,$at,.L0f010850
/*  f0106a0:	00000000 */ 	nop
/*  f0106a4:	ae500004 */ 	sw	$s0,0x4($s2)
/*  f0106a8:	0fc0330b */ 	jal	func0f00cc2c
/*  f0106ac:	ae420008 */ 	sw	$v0,0x8($s2)
/*  f0106b0:	8e0c0040 */ 	lw	$t4,0x40($s0)
/*  f0106b4:	358d2000 */ 	ori	$t5,$t4,0x2000
/*  f0106b8:	10000065 */ 	b	.L0f010850
/*  f0106bc:	ae0d0040 */ 	sw	$t5,0x40($s0)
/*  f0106c0:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*  f0106c4:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f0106c8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0106cc:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0106d0:	8e58000c */ 	lw	$t8,0xc($s2)
/*  f0106d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0106d8:	02622021 */ 	addu	$a0,$s3,$v0
/*  f0106dc:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0106e0:	afb8008c */ 	sw	$t8,0x8c($sp)
/*  f0106e4:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0106e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0106ec:	13200005 */ 	beqz	$t9,.L0f010704
/*  f0106f0:	02792021 */ 	addu	$a0,$s3,$t9
/*  f0106f4:	0fc24908 */ 	jal	setupCommandGetObject
/*  f0106f8:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0106fc:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f010700:	00408825 */ 	or	$s1,$v0,$zero
.L0f010704:
/*  f010704:	8fa2008c */ 	lw	$v0,0x8c($sp)
/*  f010708:	10400006 */ 	beqz	$v0,.L0f010724
/*  f01070c:	02622021 */ 	addu	$a0,$s3,$v0
/*  f010710:	0fc24908 */ 	jal	setupCommandGetObject
/*  f010714:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f010718:	00408025 */ 	or	$s0,$v0,$zero
/*  f01071c:	8fa2008c */ 	lw	$v0,0x8c($sp)
/*  f010720:	8fa60088 */ 	lw	$a2,0x88($sp)
.L0f010724:
/*  f010724:	10c0004a */ 	beqz	$a2,.L0f010850
/*  f010728:	00000000 */ 	nop
/*  f01072c:	8ccf0014 */ 	lw	$t7,0x14($a2)
/*  f010730:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f010734:	11e00046 */ 	beqz	$t7,.L0f010850
/*  f010738:	00000000 */ 	nop
/*  f01073c:	11600006 */ 	beqz	$t3,.L0f010758
/*  f010740:	00000000 */ 	nop
/*  f010744:	12200042 */ 	beqz	$s1,.L0f010850
/*  f010748:	00000000 */ 	nop
/*  f01074c:	8e2c0014 */ 	lw	$t4,0x14($s1)
/*  f010750:	1180003f */ 	beqz	$t4,.L0f010850
/*  f010754:	00000000 */ 	nop
.L0f010758:
/*  f010758:	10400006 */ 	beqz	$v0,.L0f010774
/*  f01075c:	02402025 */ 	or	$a0,$s2,$zero
/*  f010760:	1200003b */ 	beqz	$s0,.L0f010850
/*  f010764:	00000000 */ 	nop
/*  f010768:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*  f01076c:	11a00038 */ 	beqz	$t5,.L0f010850
/*  f010770:	00000000 */ 	nop
.L0f010774:
/*  f010774:	ae460004 */ 	sw	$a2,0x4($s2)
/*  f010778:	ae510008 */ 	sw	$s1,0x8($s2)
/*  f01077c:	ae50000c */ 	sw	$s0,0xc($s2)
/*  f010780:	0fc03317 */ 	jal	func0f00cc5c
/*  f010784:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f010788:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f01078c:	3c010100 */ 	lui	$at,0x100
/*  f010790:	8cce0040 */ 	lw	$t6,0x40($a2)
/*  f010794:	00c02025 */ 	or	$a0,$a2,$zero
/*  f010798:	01c1c025 */ 	or	$t8,$t6,$at
/*  f01079c:	acd80040 */ 	sw	$t8,0x40($a2)
/*  f0107a0:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0107a4:	53200006 */ 	beqzl	$t9,.L0f0107c0
/*  f0107a8:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f0107ac:	8e2f0040 */ 	lw	$t7,0x40($s1)
/*  f0107b0:	3c010100 */ 	lui	$at,0x100
/*  f0107b4:	01e15825 */ 	or	$t3,$t7,$at
/*  f0107b8:	ae2b0040 */ 	sw	$t3,0x40($s1)
/*  f0107bc:	8fac008c */ 	lw	$t4,0x8c($sp)
.L0f0107c0:
/*  f0107c0:	51800009 */ 	beqzl	$t4,.L0f0107e8
/*  f0107c4:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0107c8:	8e0d0040 */ 	lw	$t5,0x40($s0)
/*  f0107cc:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f0107d0:	3c010100 */ 	lui	$at,0x100
/*  f0107d4:	01a17025 */ 	or	$t6,$t5,$at
/*  f0107d8:	0314c825 */ 	or	$t9,$t8,$s4
/*  f0107dc:	ae0e0040 */ 	sw	$t6,0x40($s0)
/*  f0107e0:	ae19000c */ 	sw	$t9,0xc($s0)
/*  f0107e4:	8ccf0040 */ 	lw	$t7,0x40($a2)
.L0f0107e8:
/*  f0107e8:	01f55824 */ 	and	$t3,$t7,$s5
/*  f0107ec:	11600018 */ 	beqz	$t3,.L0f010850
/*  f0107f0:	00000000 */ 	nop
/*  f0107f4:	0c006174 */ 	jal	func000185d0
/*  f0107f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0107fc:	10000014 */ 	b	.L0f010850
/*  f010800:	00000000 */ 	nop
/*  f010804:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f010808:	0fc24908 */ 	jal	setupCommandGetObject
/*  f01080c:	02622021 */ 	addu	$a0,$s3,$v0
/*  f010810:	1040000f */ 	beqz	$v0,.L0f010850
/*  f010814:	00408025 */ 	or	$s0,$v0,$zero
/*  f010818:	8c4c0014 */ 	lw	$t4,0x14($v0)
/*  f01081c:	02402025 */ 	or	$a0,$s2,$zero
/*  f010820:	1180000b */ 	beqz	$t4,.L0f010850
/*  f010824:	00000000 */ 	nop
/*  f010828:	0fc0331d */ 	jal	func0f00cc74
/*  f01082c:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f010830:	8e0d0040 */ 	lw	$t5,0x40($s0)
/*  f010834:	02002025 */ 	or	$a0,$s0,$zero
/*  f010838:	01b57025 */ 	or	$t6,$t5,$s5
/*  f01083c:	000ec9c0 */ 	sll	$t9,$t6,0x7
/*  f010840:	07210003 */ 	bgez	$t9,.L0f010850
/*  f010844:	ae0e0040 */ 	sw	$t6,0x40($s0)
/*  f010848:	0c006174 */ 	jal	func000185d0
/*  f01084c:	00002825 */ 	or	$a1,$zero,$zero
.L0f010850:
/*  f010850:	0fc24784 */ 	jal	setupGetCommandLength
/*  f010854:	02402025 */ 	or	$a0,$s2,$zero
/*  f010858:	00027880 */ 	sll	$t7,$v0,0x2
/*  f01085c:	01f29021 */ 	addu	$s2,$t7,$s2
/*  f010860:	92430003 */ 	lbu	$v1,0x3($s2)
/*  f010864:	24010034 */ 	addiu	$at,$zero,0x34
/*  f010868:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f01086c:	5461fef4 */ 	bnel	$v1,$at,.L0f010440
/*  f010870:	246bfffd */ 	addiu	$t3,$v1,-3
/*  f010874:	10000003 */ 	b	.L0f010884
/*  f010878:	00000000 */ 	nop
.L0f01087c:
/*  f01087c:	0fc02d8b */ 	jal	func0f00b62c
/*  f010880:	00002025 */ 	or	$a0,$zero,$zero
.L0f010884:
/*  f010884:	0fc02ef2 */ 	jal	func0f00bbc8
/*  f010888:	00000000 */ 	nop
/*  f01088c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f010890:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f010894:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f010898:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f01089c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0108a0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0108a4:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0108a8:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0108ac:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0108b0:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0108b4:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0108b8:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0108bc:	03e00008 */ 	jr	$ra
/*  f0108c0:	27bd0248 */ 	addiu	$sp,$sp,0x248
/*  f0108c4:	00000000 */ 	nop
/*  f0108c8:	00000000 */ 	nop
/*  f0108cc:	00000000 */ 	nop
);
