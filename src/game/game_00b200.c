#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_00b200.h"
#include "game/game_00b820.h"
#include "game/game_1668e0.h"
#include "game/game_16cfa0.h"
#include "game/game_187770.h"
#include "game/game_1999b0.h"

GLOBAL_ASM(
glabel func0f00b200
/*  f00b200:	03e00008 */ 	jr	$ra
/*  f00b204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b20c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b210
/*  f00b210:	27bdfdf8 */ 	addiu	$sp,$sp,-520
/*  f00b214:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f00b218:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00b21c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f00b220:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00b224:	3c108009 */ 	lui	$s0,%hi(g_MpChallenges)
/*  f00b228:	3c128009 */ 	lui	$s2,%hi(var80090018)
/*  f00b22c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f00b230:	265284c1 */ 	addiu	$s2,$s2,-31551
/*  f00b234:	261084b8 */ 	addiu	$s0,$s0,%lo(g_MpChallenges)
/*  f00b238:	00008825 */ 	or	$s1,$zero,$zero
/*  f00b23c:	27b30038 */ 	addiu	$s3,$sp,0x38
.L0f00b240:
/*  f00b240:	a2000004 */ 	sb	$zero,0x4($s0)
/*  f00b244:	a2000005 */ 	sb	$zero,0x5($s0)
/*  f00b248:	a2000006 */ 	sb	$zero,0x6($s0)
/*  f00b24c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f00b250:	a2000008 */ 	sb	$zero,0x8($s0)
/*  f00b254:	02202025 */ 	or	$a0,$s1,$zero
/*  f00b258:	02602825 */ 	or	$a1,$s3,$zero
/*  f00b25c:	0fc66e96 */ 	jal	func0f19ba58
/*  f00b260:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f00b264:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b268:	02402825 */ 	or	$a1,$s2,$zero
/*  f00b26c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f00b270:	0fc66f53 */ 	jal	func0f19bd4c
/*  f00b274:	02203825 */ 	or	$a3,$s1,$zero
/*  f00b278:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00b27c:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f00b280:	2610001a */ 	addiu	$s0,$s0,0x1a
/*  f00b284:	1420ffee */ 	bnez	$at,.L0f00b240
/*  f00b288:	2652001a */ 	addiu	$s2,$s2,0x1a
/*  f00b28c:	0fc636df */ 	jal	mpGetNumPresets
/*  f00b290:	00008825 */ 	or	$s1,$zero,$zero
/*  f00b294:	18400017 */ 	blez	$v0,.L0f00b2f4
/*  f00b298:	00117080 */ 	sll	$t6,$s1,0x2
/*  f00b29c:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f00b2a0:	3c0f8008 */ 	lui	$t7,%hi(g_MpPresets)
/*  f00b2a4:	25ef7b6c */ 	addiu	$t7,$t7,%lo(g_MpPresets)
/*  f00b2a8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00b2ac:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f00b2b0:	26120008 */ 	addiu	$s2,$s0,0x8
/*  f00b2b4:	8e040004 */ 	lw	$a0,0x4($s0)
.L0f00b2b8:
/*  f00b2b8:	02602825 */ 	or	$a1,$s3,$zero
/*  f00b2bc:	0fc66e45 */ 	jal	func0f19b914
/*  f00b2c0:	240601ca */ 	addiu	$a2,$zero,0x1ca
/*  f00b2c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b2c8:	02402825 */ 	or	$a1,$s2,$zero
/*  f00b2cc:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f00b2d0:	0fc66f53 */ 	jal	func0f19bd4c
/*  f00b2d4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b2d8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f00b2dc:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f00b2e0:	0fc636df */ 	jal	mpGetNumPresets
/*  f00b2e4:	26520018 */ 	addiu	$s2,$s2,%lo(var80090018)
/*  f00b2e8:	0222082a */ 	slt	$at,$s1,$v0
/*  f00b2ec:	5420fff2 */ 	bnezl	$at,.L0f00b2b8
/*  f00b2f0:	8e040004 */ 	lw	$a0,0x4($s0)
.L0f00b2f4:
/*  f00b2f4:	0fc66bf7 */ 	jal	func0f19afdc
/*  f00b2f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b2fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f00b300:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00b304:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00b308:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f00b30c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f00b310:	03e00008 */ 	jr	$ra
/*  f00b314:	27bd0208 */ 	addiu	$sp,$sp,0x208
/*  f00b318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b31c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b320
/*  f00b320:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b324:	3c02800b */ 	lui	$v0,%hi(g_TextBanks)
/*  f00b328:	3c03800b */ 	lui	$v1,%hi(var800aabb4)
/*  f00b32c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00b330:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00b334:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f00b338:	2463abb4 */ 	addiu	$v1,$v1,%lo(var800aabb4)
/*  f00b33c:	2442aaa0 */ 	addiu	$v0,$v0,%lo(g_TextBanks)
.L0f00b340:
/*  f00b340:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f00b344:	1443fffe */ 	bne	$v0,$v1,.L0f00b340
/*  f00b348:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f00b34c:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b350:	24040026 */ 	addiu	$a0,$zero,0x26
/*  f00b354:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b358:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b35c:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b360:	3c10800b */ 	lui	$s0,%hi(g_TextBanks)
/*  f00b364:	2610aaa0 */ 	addiu	$s0,$s0,%lo(g_TextBanks)
/*  f00b368:	ae020098 */ 	sw	$v0,0x98($s0)
/*  f00b36c:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b370:	24040028 */ 	addiu	$a0,$zero,0x28
/*  f00b374:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b378:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b37c:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b380:	ae0200a0 */ 	sw	$v0,0xa0($s0)
/*  f00b384:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b388:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f00b38c:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b390:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b394:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b398:	ae0200a4 */ 	sw	$v0,0xa4($s0)
/*  f00b39c:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b3a0:	2404002a */ 	addiu	$a0,$zero,0x2a
/*  f00b3a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3a8:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3ac:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3b0:	ae0200a8 */ 	sw	$v0,0xa8($s0)
/*  f00b3b4:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b3b8:	2404002b */ 	addiu	$a0,$zero,0x2b
/*  f00b3bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3c0:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3c4:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3c8:	ae0200ac */ 	sw	$v0,0xac($s0)
/*  f00b3cc:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b3d0:	2404002c */ 	addiu	$a0,$zero,0x2c
/*  f00b3d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b3d8:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b3dc:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b3e0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f00b3e4:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f00b3e8:	ae0200b0 */ 	sw	$v0,0xb0($s0)
/*  f00b3ec:	55c10008 */ 	bnel	$t6,$at,.L0f00b410
/*  f00b3f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00b3f4:	0fc5b9bd */ 	jal	textGetFileId
/*  f00b3f8:	24040027 */ 	addiu	$a0,$zero,0x27
/*  f00b3fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f00b400:	0fc59c3f */ 	jal	func0f1670fc
/*  f00b404:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00b408:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f00b40c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f00b410:
/*  f00b410:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00b414:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00b418:	03e00008 */ 	jr	$ra
/*  f00b41c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b420
/*  f00b420:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00b424:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b428:	3c018006 */ 	lui	$at,0x8006
/*  f00b42c:	ac202410 */ 	sw	$zero,0x2410($at)
/*  f00b430:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b434:	0c0048f2 */ 	jal	malloc
/*  f00b438:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b43c:	3c01800a */ 	lui	$at,0x800a
/*  f00b440:	ac22cc80 */ 	sw	$v0,-0x3380($at)
/*  f00b444:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b448:	0c0048f2 */ 	jal	malloc
/*  f00b44c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b450:	3c01800a */ 	lui	$at,0x800a
/*  f00b454:	ac22cc84 */ 	sw	$v0,-0x337c($at)
/*  f00b458:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f00b45c:	0c0048f2 */ 	jal	malloc
/*  f00b460:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b464:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b468:	3c01800a */ 	lui	$at,0x800a
/*  f00b46c:	ac22cc88 */ 	sw	$v0,-0x3378($at)
/*  f00b470:	03e00008 */ 	jr	$ra
/*  f00b474:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00b478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b47c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b480
/*  f00b480:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f00b484:	3c018006 */ 	lui	$at,0x8006
/*  f00b488:	ac2224b4 */ 	sw	$v0,0x24b4($at)
/*  f00b48c:	3c018006 */ 	lui	$at,0x8006
/*  f00b490:	ac2024d4 */ 	sw	$zero,0x24d4($at)
/*  f00b494:	3c018006 */ 	lui	$at,0x8006
/*  f00b498:	ac2024d8 */ 	sw	$zero,0x24d8($at)
/*  f00b49c:	3c018006 */ 	lui	$at,0x8006
/*  f00b4a0:	ac2024dc */ 	sw	$zero,0x24dc($at)
/*  f00b4a4:	3c018006 */ 	lui	$at,0x8006
/*  f00b4a8:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f00b4ac:	ac2e24bc */ 	sw	$t6,0x24bc($at)
/*  f00b4b0:	3c188006 */ 	lui	$t8,0x8006
/*  f00b4b4:	8f1824f0 */ 	lw	$t8,0x24f0($t8)
/*  f00b4b8:	3c018006 */ 	lui	$at,0x8006
/*  f00b4bc:	ac2224c0 */ 	sw	$v0,0x24c0($at)
/*  f00b4c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00b4c4:	3c018006 */ 	lui	$at,0x8006
/*  f00b4c8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f00b4cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b4d0:	13000004 */ 	beqz	$t8,.L0f00b4e4
/*  f00b4d4:	ac2f24f4 */ 	sw	$t7,0x24f4($at)
/*  f00b4d8:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f00b4dc:	3c018006 */ 	lui	$at,0x8006
/*  f00b4e0:	ac3924b8 */ 	sw	$t9,0x24b8($at)
.L0f00b4e4:
/*  f00b4e4:	3c040004 */ 	lui	$a0,0x4
/*  f00b4e8:	34847800 */ 	ori	$a0,$a0,0x7800
/*  f00b4ec:	0c0048f2 */ 	jal	malloc
/*  f00b4f0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b4f4:	3c01800a */ 	lui	$at,0x800a
/*  f00b4f8:	0fc02d08 */ 	jal	func0f00b420
/*  f00b4fc:	ac22cca0 */ 	sw	$v0,-0x3360($at)
/*  f00b500:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b504:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00b508:	03e00008 */ 	jr	$ra
/*  f00b50c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f00b510
/*  f00b510:	3c013f80 */ 	lui	$at,0x3f80
/*  f00b514:	44812000 */ 	mtc1	$at,$f4
/*  f00b518:	3c018006 */ 	lui	$at,0x8006
/*  f00b51c:	240e1388 */ 	addiu	$t6,$zero,0x1388
/*  f00b520:	e4242968 */ 	swc1	$f4,0x2968($at)
/*  f00b524:	3c018006 */ 	lui	$at,0x8006
/*  f00b528:	ac20296c */ 	sw	$zero,0x296c($at)
/*  f00b52c:	3c018006 */ 	lui	$at,0x8006
/*  f00b530:	ac202970 */ 	sw	$zero,0x2970($at)
/*  f00b534:	3c018006 */ 	lui	$at,0x8006
/*  f00b538:	ac202974 */ 	sw	$zero,0x2974($at)
/*  f00b53c:	3c018006 */ 	lui	$at,0x8006
/*  f00b540:	ac202978 */ 	sw	$zero,0x2978($at)
/*  f00b544:	3c018006 */ 	lui	$at,0x8006
/*  f00b548:	ac20297c */ 	sw	$zero,0x297c($at)
/*  f00b54c:	3c018006 */ 	lui	$at,0x8006
/*  f00b550:	ac2e2984 */ 	sw	$t6,0x2984($at)
/*  f00b554:	3c018006 */ 	lui	$at,0x8006
/*  f00b558:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b55c:	ac202988 */ 	sw	$zero,0x2988($at)
/*  f00b560:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00b564:	3c018006 */ 	lui	$at,0x8006
/*  f00b568:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f00b56c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f00b570:	ac20298c */ 	sw	$zero,0x298c($at)
/*  f00b574:	24040730 */ 	addiu	$a0,$zero,0x730
/*  f00b578:	0c0048f2 */ 	jal	malloc
/*  f00b57c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b580:	3c048006 */ 	lui	$a0,%hi(var80062a8c)
/*  f00b584:	24842a8c */ 	addiu	$a0,$a0,%lo(var80062a8c)
/*  f00b588:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b58c:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b590:
/*  f00b590:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f00b594:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f00b598:	2463005c */ 	addiu	$v1,$v1,0x5c
/*  f00b59c:	28610730 */ 	slti	$at,$v1,0x730
/*  f00b5a0:	1420fffb */ 	bnez	$at,.L0f00b590
/*  f00b5a4:	af000000 */ 	sw	$zero,0x0($t8)
/*  f00b5a8:	3c018006 */ 	lui	$at,0x8006
/*  f00b5ac:	ac202a90 */ 	sw	$zero,0x2a90($at)
/*  f00b5b0:	3c01800a */ 	lui	$at,0x800a
/*  f00b5b4:	ac20cd10 */ 	sw	$zero,-0x32f0($at)
/*  f00b5b8:	3c01800a */ 	lui	$at,0x800a
/*  f00b5bc:	ac20cd14 */ 	sw	$zero,-0x32ec($at)
/*  f00b5c0:	3c01800a */ 	lui	$at,0x800a
/*  f00b5c4:	ac20cd18 */ 	sw	$zero,-0x32e8($at)
/*  f00b5c8:	24041470 */ 	addiu	$a0,$zero,0x1470
/*  f00b5cc:	0c0048f2 */ 	jal	malloc
/*  f00b5d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b5d4:	3c018006 */ 	lui	$at,0x8006
/*  f00b5d8:	3c10800a */ 	lui	$s0,%hi(var8009ccc0)
/*  f00b5dc:	3c11800a */ 	lui	$s1,%hi(g_NumChrsC)
/*  f00b5e0:	ac222960 */ 	sw	$v0,0x2960($at)
/*  f00b5e4:	2631cd10 */ 	addiu	$s1,$s1,%lo(g_NumChrsC)
/*  f00b5e8:	2610ccc0 */ 	addiu	$s0,$s0,%lo(var8009ccc0)
.L0f00b5ec:
/*  f00b5ec:	24040240 */ 	addiu	$a0,$zero,0x240
/*  f00b5f0:	0c0048f2 */ 	jal	malloc
/*  f00b5f4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b5f8:	2459003f */ 	addiu	$t9,$v0,0x3f
/*  f00b5fc:	3728003f */ 	ori	$t0,$t9,0x3f
/*  f00b600:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f00b604:	3909003f */ 	xori	$t1,$t0,0x3f
/*  f00b608:	1611fff8 */ 	bne	$s0,$s1,.L0f00b5ec
/*  f00b60c:	ae09fffc */ 	sw	$t1,-0x4($s0)
/*  f00b610:	0fc02edc */ 	jal	resetSomeStageThings
/*  f00b614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b618:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00b61c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f00b620:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f00b624:	03e00008 */ 	jr	$ra
/*  f00b628:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f00b62c
/*  f00b62c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f00b630:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f00b634:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f00b638:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f00b63c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00b640:	11c00003 */ 	beqz	$t6,.L0f00b650
/*  f00b644:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f00b648:	10000002 */ 	beqz	$zero,.L0f00b654
/*  f00b64c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f00b650:
/*  f00b650:	00003825 */ 	or	$a3,$zero,$zero
.L0f00b654:
/*  f00b654:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f00b658:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b65c:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b660:	11e00003 */ 	beqz	$t7,.L0f00b670
/*  f00b664:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f00b668:	10000002 */ 	beqz	$zero,.L0f00b674
/*  f00b66c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f00b670:
/*  f00b670:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b674:
/*  f00b674:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f00b678:	00003025 */ 	or	$a2,$zero,$zero
/*  f00b67c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b680:	13000003 */ 	beqz	$t8,.L0f00b690
/*  f00b684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b688:	10000001 */ 	beqz	$zero,.L0f00b690
/*  f00b68c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f00b690:
/*  f00b690:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f00b694:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b698:	13200003 */ 	beqz	$t9,.L0f00b6a8
/*  f00b69c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b6a0:	10000001 */ 	beqz	$zero,.L0f00b6a8
/*  f00b6a4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f00b6a8:
/*  f00b6a8:	00464821 */ 	addu	$t1,$v0,$a2
/*  f00b6ac:	01235021 */ 	addu	$t2,$t1,$v1
/*  f00b6b0:	01475821 */ 	addu	$t3,$t2,$a3
/*  f00b6b4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f00b6b8:	25ae000a */ 	addiu	$t6,$t5,0xa
/*  f00b6bc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f00b6c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f00b6c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00b6c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f00b6cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f00b6d0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f00b6d4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f00b6d8:	25e4000f */ 	addiu	$a0,$t7,0xf
/*  f00b6dc:	3498000f */ 	ori	$t8,$a0,0xf
/*  f00b6e0:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f00b6e4:	0c0048f2 */ 	jal	malloc
/*  f00b6e8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f00b6ec:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b6f0:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b6f4:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f00b6f8:	3c048006 */ 	lui	$a0,%hi(g_ChrsA)
/*  f00b6fc:	24842988 */ 	addiu	$a0,$a0,%lo(g_ChrsA)
/*  f00b700:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b704:	18c00013 */ 	blez	$a2,.L0f00b754
/*  f00b708:	00001825 */ 	or	$v1,$zero,$zero
/*  f00b70c:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b710:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b714:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f00b718:
/*  f00b718:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00b71c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f00b720:	a5470000 */ 	sh	$a3,0x0($t2)
/*  f00b724:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f00b728:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00b72c:	ad800020 */ 	sw	$zero,0x20($t4)
/*  f00b730:	8c8d0000 */ 	lw	$t5,0x0($a0)
/*  f00b734:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f00b738:	adc0001c */ 	sw	$zero,0x1c($t6)
/*  f00b73c:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f00b740:	24420368 */ 	addiu	$v0,$v0,0x368
/*  f00b744:	0066082a */ 	slt	$at,$v1,$a2
/*  f00b748:	5420fff3 */ 	bnezl	$at,.L0f00b718
/*  f00b74c:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f00b750:	00001825 */ 	or	$v1,$zero,$zero
.L0f00b754:
/*  f00b754:	00062040 */ 	sll	$a0,$a2,0x1
/*  f00b758:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f00b75c:	3c01800a */ 	lui	$at,0x800a
/*  f00b760:	348f000f */ 	ori	$t7,$a0,0xf
/*  f00b764:	ac20cd10 */ 	sw	$zero,-0x32f0($at)
/*  f00b768:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f00b76c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b770:	0c0048f2 */ 	jal	malloc
/*  f00b774:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f00b778:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b77c:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b780:	8d040000 */ 	lw	$a0,0x0($t0)
/*  f00b784:	3c06800a */ 	lui	$a2,%hi(g_ChrnumsC)
/*  f00b788:	24c6cd14 */ 	addiu	$a2,$a2,%lo(g_ChrnumsC)
/*  f00b78c:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f00b790:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f00b794:	3489000f */ 	ori	$t1,$a0,0xf
/*  f00b798:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f00b79c:	3924000f */ 	xori	$a0,$t1,0xf
/*  f00b7a0:	0c0048f2 */ 	jal	malloc
/*  f00b7a4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00b7a8:	3c088006 */ 	lui	$t0,%hi(g_NumChrsA)
/*  f00b7ac:	2508298c */ 	addiu	$t0,$t0,%lo(g_NumChrsA)
/*  f00b7b0:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f00b7b4:	3c04800a */ 	lui	$a0,%hi(g_ChrIndexesC)
/*  f00b7b8:	2484cd18 */ 	addiu	$a0,$a0,%lo(g_ChrIndexesC)
/*  f00b7bc:	3c06800a */ 	lui	$a2,%hi(g_ChrnumsC)
/*  f00b7c0:	24c6cd14 */ 	addiu	$a2,$a2,%lo(g_ChrnumsC)
/*  f00b7c4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f00b7c8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f00b7cc:	1960000e */ 	blez	$t3,.L0f00b808
/*  f00b7d0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f00b7d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f00b7d8:	8ccc0000 */ 	lw	$t4,0x0($a2)
.L0f00b7dc:
/*  f00b7dc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00b7e0:	01826821 */ 	addu	$t5,$t4,$v0
/*  f00b7e4:	a5a70000 */ 	sh	$a3,0x0($t5)
/*  f00b7e8:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f00b7ec:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f00b7f0:	a5e70000 */ 	sh	$a3,0x0($t7)
/*  f00b7f4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f00b7f8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00b7fc:	0078082a */ 	slt	$at,$v1,$t8
/*  f00b800:	5420fff6 */ 	bnezl	$at,.L0f00b7dc
/*  f00b804:	8ccc0000 */ 	lw	$t4,0x0($a2)
.L0f00b808:
/*  f00b808:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00b80c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00b810:	03e00008 */ 	jr	$ra
/*  f00b814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00b81c:	00000000 */ 	sll	$zero,$zero,0x0
);
