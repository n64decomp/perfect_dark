#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_013260.h"
#include "game/game_131060.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"
// Mismatch because the lui %hi instructions are swapped
//void func0f013260(void)
//{
//	struct gvars800a3fc8 *current;
//	struct gvars800a3fc8 *end;
//	var800a3fc0 = 0;
//	end = &var800a3fc8[10];
//	current = &var800a3fc8[0];
//
//	while (current != end) {
//		current->unk08 = 0;
//		current++;
//	}
//
//	var800a4130 = 0;
//	var8007f0b8 = 0;
//}

GLOBAL_ASM(
glabel func0f0132a0
/*  f0132a0:	3c038008 */ 	lui	$v1,%hi(var8007f0c0)
/*  f0132a4:	3c018006 */ 	lui	$at,0x8006
/*  f0132a8:	2463f0c0 */ 	addiu	$v1,$v1,%lo(var8007f0c0)
/*  f0132ac:	ac2023f0 */ 	sw	$zero,0x23f0($at)
/*  f0132b0:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0132b4:	3c048008 */ 	lui	$a0,0x8008
/*  f0132b8:	8c84fc00 */ 	lw	$a0,-0x400($a0)
/*  f0132bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0132c0:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0132c4:	10810007 */ 	beq	$a0,$at,.L0f0132e4
/*  f0132c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0132cc:	24010013 */ 	addiu	$at,$zero,0x13
/*  f0132d0:	10810004 */ 	beq	$a0,$at,.L0f0132e4
/*  f0132d4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0132d8:	10810002 */ 	beq	$a0,$at,.L0f0132e4
/*  f0132dc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0132e0:	14810092 */ 	bne	$a0,$at,.L0f01352c
.L0f0132e4:
/*  f0132e4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0132e8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0132ec:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0132f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0132f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0132f8:	11c00003 */ 	beqz	$t6,.L0f013308
/*  f0132fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f013300:	10000001 */ 	beqz	$zero,.L0f013308
/*  f013304:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f013308:
/*  f013308:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f01330c:	11e00003 */ 	beqz	$t7,.L0f01331c
/*  f013310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013314:	10000001 */ 	beqz	$zero,.L0f01331c
/*  f013318:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f01331c:
/*  f01331c:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f013320:	13000003 */ 	beqz	$t8,.L0f013330
/*  f013324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013328:	10000001 */ 	beqz	$zero,.L0f013330
/*  f01332c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f013330:
/*  f013330:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f013334:	00001025 */ 	or	$v0,$zero,$zero
/*  f013338:	13200003 */ 	beqz	$t9,.L0f013348
/*  f01333c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013340:	10000001 */ 	beqz	$zero,.L0f013348
/*  f013344:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f013348:
/*  f013348:	00454021 */ 	addu	$t0,$v0,$a1
/*  f01334c:	01044821 */ 	addu	$t1,$t0,$a0
/*  f013350:	01265021 */ 	addu	$t2,$t1,$a2
/*  f013354:	29410002 */ 	slti	$at,$t2,0x2
/*  f013358:	10200074 */ 	beqz	$at,.L0f01352c
/*  f01335c:	24040100 */ 	addiu	$a0,$zero,0x100
/*  f013360:	0c0048f2 */ 	jal	malloc
/*  f013364:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f013368:	3c038008 */ 	lui	$v1,%hi(var8007f0c0)
/*  f01336c:	2463f0c0 */ 	addiu	$v1,$v1,%lo(var8007f0c0)
/*  f013370:	0fc4c4cd */ 	jal	func0f131334
/*  f013374:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f013378:	3c038008 */ 	lui	$v1,%hi(var8007f0c0)
/*  f01337c:	2463f0c0 */ 	addiu	$v1,$v1,%lo(var8007f0c0)
/*  f013380:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f013384:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f013388:	44800000 */ 	mtc1	$zero,$f0
/*  f01338c:	ad620024 */ 	sw	$v0,0x24($t3)
/*  f013390:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f013394:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f013398:	3c048008 */ 	lui	$a0,0x8008
/*  f01339c:	ad860020 */ 	sw	$a2,0x20($t4)
/*  f0133a0:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0133a4:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0133a8:	e5a00008 */ 	swc1	$f0,0x8($t5)
/*  f0133ac:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0133b0:	e5c0000c */ 	swc1	$f0,0xc($t6)
/*  f0133b4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0133b8:	ade50010 */ 	sw	$a1,0x10($t7)
/*  f0133bc:	8c84fc00 */ 	lw	$a0,-0x400($a0)
/*  f0133c0:	10810002 */ 	beq	$a0,$at,.L0f0133cc
/*  f0133c4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0133c8:	14810005 */ 	bne	$a0,$at,.L0f0133e0
.L0f0133cc:
/*  f0133cc:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0133d0:	44812000 */ 	mtc1	$at,$f4
/*  f0133d4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0133d8:	1000000c */ 	beqz	$zero,.L0f01340c
/*  f0133dc:	e7040014 */ 	swc1	$f4,0x14($t8)
.L0f0133e0:
/*  f0133e0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0133e4:	14810005 */ 	bne	$a0,$at,.L0f0133fc
/*  f0133e8:	3c014120 */ 	lui	$at,0x4120
/*  f0133ec:	44813000 */ 	mtc1	$at,$f6
/*  f0133f0:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0133f4:	10000005 */ 	beqz	$zero,.L0f01340c
/*  f0133f8:	e7260014 */ 	swc1	$f6,0x14($t9)
.L0f0133fc:
/*  f0133fc:	3c0140a0 */ 	lui	$at,0x40a0
/*  f013400:	44814000 */ 	mtc1	$at,$f8
/*  f013404:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f013408:	e5080014 */ 	swc1	$f8,0x14($t0)
.L0f01340c:
/*  f01340c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f013410:	3c013f80 */ 	lui	$at,0x3f80
/*  f013414:	44811000 */ 	mtc1	$at,$f2
/*  f013418:	ad200034 */ 	sw	$zero,0x34($t1)
/*  f01341c:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f013420:	ad400038 */ 	sw	$zero,0x38($t2)
/*  f013424:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f013428:	ad60003c */ 	sw	$zero,0x3c($t3)
/*  f01342c:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f013430:	ad800040 */ 	sw	$zero,0x40($t4)
/*  f013434:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f013438:	ada00044 */ 	sw	$zero,0x44($t5)
/*  f01343c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f013440:	adc60094 */ 	sw	$a2,0x94($t6)
/*  f013444:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f013448:	240e000a */ 	addiu	$t6,$zero,0xa
/*  f01344c:	ade50048 */ 	sw	$a1,0x48($t7)
/*  f013450:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f013454:	af00004c */ 	sw	$zero,0x4c($t8)
/*  f013458:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f01345c:	af200050 */ 	sw	$zero,0x50($t9)
/*  f013460:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f013464:	ad000054 */ 	sw	$zero,0x54($t0)
/*  f013468:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f01346c:	e5200058 */ 	swc1	$f0,0x58($t1)
/*  f013470:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f013474:	e5400064 */ 	swc1	$f0,0x64($t2)
/*  f013478:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f01347c:	e5600070 */ 	swc1	$f0,0x70($t3)
/*  f013480:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f013484:	e582007c */ 	swc1	$f2,0x7c($t4)
/*  f013488:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f01348c:	e5a2005c */ 	swc1	$f2,0x5c($t5)
/*  f013490:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f013494:	adee0060 */ 	sw	$t6,0x60($t7)
/*  f013498:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f01349c:	8c440060 */ 	lw	$a0,0x60($v0)
/*  f0134a0:	04810003 */ 	bgez	$a0,.L0f0134b0
/*  f0134a4:	0004c023 */ 	negu	$t8,$a0
/*  f0134a8:	ac580060 */ 	sw	$t8,0x60($v0)
/*  f0134ac:	8c620000 */ 	lw	$v0,0x0($v1)
.L0f0134b0:
/*  f0134b0:	ac400060 */ 	sw	$zero,0x60($v0)
/*  f0134b4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0134b8:	3c014316 */ 	lui	$at,0x4316
/*  f0134bc:	44815000 */ 	mtc1	$at,$f10
/*  f0134c0:	af20006c */ 	sw	$zero,0x6c($t9)
/*  f0134c4:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f0134c8:	3c014170 */ 	lui	$at,0x4170
/*  f0134cc:	44818000 */ 	mtc1	$at,$f16
/*  f0134d0:	ad000078 */ 	sw	$zero,0x78($t0)
/*  f0134d4:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0134d8:	3c018006 */ 	lui	$at,0x8006
/*  f0134dc:	ad200084 */ 	sw	$zero,0x84($t1)
/*  f0134e0:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0134e4:	e54a00b8 */ 	swc1	$f10,0xb8($t2)
/*  f0134e8:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0134ec:	ad6000c0 */ 	sw	$zero,0xc0($t3)
/*  f0134f0:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0134f4:	e58000c4 */ 	swc1	$f0,0xc4($t4)
/*  f0134f8:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0134fc:	e5b000c8 */ 	swc1	$f16,0xc8($t5)
/*  f013500:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f013504:	e5c20088 */ 	swc1	$f2,0x88($t6)
/*  f013508:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f01350c:	ade00090 */ 	sw	$zero,0x90($t7)
/*  f013510:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f013514:	af0000cc */ 	sw	$zero,0xcc($t8)
/*  f013518:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f01351c:	af2000d0 */ 	sw	$zero,0xd0($t9)
/*  f013520:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f013524:	ad0000d4 */ 	sw	$zero,0xd4($t0)
/*  f013528:	ac2523f0 */ 	sw	$a1,0x23f0($at)
.L0f01352c:
/*  f01352c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013530:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013534:	03e00008 */ 	jr	$ra
/*  f013538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01353c:	00000000 */ 	sll	$zero,$zero,0x0
);