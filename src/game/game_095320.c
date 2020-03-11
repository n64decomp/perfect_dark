#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0601b0.h"
#include "game/propobj.h"
#include "game/game_091e10.h"
#include "game/game_095320.h"
#include "game/game_0b3350.h"
#include "game/game_0dcdb0.h"
#include "game/game_111600.h"
#include "game/game_11ecf0.h"
#include "game/game_127910.h"
#include "game/game_167ae0.h"
#include "game/game_19c990.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_49a90.h"
#include "types.h"

const u32 var7f1ab790[] = {0x00000000};
const u32 var7f1ab794[] = {0x00000000};
const u32 var7f1ab798[] = {0x00000000};
const u32 var7f1ab79c[] = {0x00000000};
const u32 var7f1ab7a0[] = {0x00000000};
const u32 var7f1ab7a4[] = {0x00000000};
const u32 var7f1ab7a8[] = {0x00000000};
const u32 var7f1ab7ac[] = {0x00000000};
const u32 var7f1ab7b0[] = {0x00000000};
const u32 var7f1ab7b4[] = {0x00000000};
const u32 var7f1ab7b8[] = {0x00000000};
const u32 var7f1ab7bc[] = {0x00000000};
const u32 var7f1ab7c0[] = {0x00000000};

const char var7f1ab7c4[] = "%s %d: ";

GLOBAL_ASM(
glabel func0f095320
/*  f095320:	3c01baff */ 	lui	$at,0xbaff
/*  f095324:	3421beff */ 	ori	$at,$at,0xbeff
/*  f095328:	03e00008 */ 	jr	$ra
/*  f09532c:	00811026 */ 	xor	$v0,$a0,$at
);

GLOBAL_ASM(
glabel func0f095330
/*  f095330:	3c01babe */ 	lui	$at,0xbabe
/*  f095334:	3421ffff */ 	ori	$at,$at,0xffff
/*  f095338:	03e00008 */ 	jr	$ra
/*  f09533c:	00811026 */ 	xor	$v0,$a0,$at
);

GLOBAL_ASM(
glabel func0f095340
/*  f095340:	3c01b00b */ 	lui	$at,0xb00b
/*  f095344:	34211e55 */ 	ori	$at,$at,0x1e55
/*  f095348:	03e00008 */ 	jr	$ra
/*  f09534c:	00811026 */ 	xor	$v0,$a0,$at
/*  f095350:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f095354:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f095358:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f09535c:	0c0126b8 */ 	jal	func00049ae0
/*  f095360:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f095364:	3c04b46b */ 	lui	$a0,0xb46b
/*  f095368:	0fc254d0 */ 	jal	func0f095340
/*  f09536c:	34841e45 */ 	ori	$a0,$a0,0x1e45
/*  f095370:	3c05a000 */ 	lui	$a1,0xa000
/*  f095374:	00452025 */ 	or	$a0,$v0,$a1
/*  f095378:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f09537c:	3c188000 */ 	lui	$t8,0x8000
/*  f095380:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f095384:	306e0003 */ 	andi	$t6,$v1,0x3
/*  f095388:	11c00005 */ 	beqz	$t6,.L0f0953a0
/*  f09538c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095390:	8c830000 */ 	lw	$v1,0x0($a0)
.L0f095394:
/*  f095394:	306f0003 */ 	andi	$t7,$v1,0x3
/*  f095398:	55e0fffe */ 	bnezl	$t7,.L0f095394
/*  f09539c:	8c830000 */ 	lw	$v1,0x0($a0)
.L0f0953a0:
/*  f0953a0:	8f180308 */ 	lw	$t8,0x308($t8)
/*  f0953a4:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0953a8:	03194025 */ 	or	$t0,$t8,$t9
/*  f0953ac:	01054825 */ 	or	$t1,$t0,$a1
/*  f0953b0:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f0953b4:	0c0126c9 */ 	jal	func00049b24
/*  f0953b8:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f0953bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0953c0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0953c4:	03e00008 */ 	jr	$ra
/*  f0953c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0953cc
/*  f0953cc:	3c02800a */ 	lui	$v0,%hi(var8009d0b0)
/*  f0953d0:	8c42d0b0 */ 	lw	$v0,%lo(var8009d0b0)($v0)
/*  f0953d4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0953d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0953dc:	10400009 */ 	beqz	$v0,.L0f095404
/*  f0953e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0953e4:	94430004 */ 	lhu	$v1,0x4($v0)
.L0f0953e8:
/*  f0953e8:	0066082a */ 	slt	$at,$v1,$a2
/*  f0953ec:	54200003 */ 	bnezl	$at,.L0f0953fc
/*  f0953f0:	8c420008 */ 	lw	$v0,0x8($v0)
/*  f0953f4:	24660001 */ 	addiu	$a2,$v1,0x1
/*  f0953f8:	8c420008 */ 	lw	$v0,0x8($v0)
.L0f0953fc:
/*  f0953fc:	5440fffa */ 	bnezl	$v0,.L0f0953e8
/*  f095400:	94430004 */ 	lhu	$v1,0x4($v0)
.L0f095404:
/*  f095404:	3c07800a */ 	lui	$a3,%hi(g_NumTags)
/*  f095408:	24e7d0c4 */ 	addiu	$a3,$a3,%lo(g_NumTags)
/*  f09540c:	10c0001b */ 	beqz	$a2,.L0f09547c
/*  f095410:	ace60000 */ 	sw	$a2,0x0($a3)
/*  f095414:	00062080 */ 	sll	$a0,$a2,0x2
/*  f095418:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f09541c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f095420:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f095424:	00003025 */ 	or	$a2,$zero,$zero
/*  f095428:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f09542c:	0c0048f2 */ 	jal	malloc
/*  f095430:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f095434:	3c07800a */ 	lui	$a3,%hi(g_NumTags)
/*  f095438:	24e7d0c4 */ 	addiu	$a3,$a3,%lo(g_NumTags)
/*  f09543c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f095440:	3c03800a */ 	lui	$v1,%hi(g_TagPtrs)
/*  f095444:	2463d0c8 */ 	addiu	$v1,$v1,%lo(g_TagPtrs)
/*  f095448:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f09544c:	1b20000b */ 	blez	$t9,.L0f09547c
/*  f095450:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f095454:	00001025 */ 	or	$v0,$zero,$zero
/*  f095458:	8c680000 */ 	lw	$t0,0x0($v1)
.L0f09545c:
/*  f09545c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f095460:	01024821 */ 	addu	$t1,$t0,$v0
/*  f095464:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f095468:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f09546c:	24420004 */ 	addiu	$v0,$v0,4
/*  f095470:	00ca082a */ 	slt	$at,$a2,$t2
/*  f095474:	5420fff9 */ 	bnezl	$at,.L0f09545c
/*  f095478:	8c680000 */ 	lw	$t0,0x0($v1)
.L0f09547c:
/*  f09547c:	3c02800a */ 	lui	$v0,%hi(var8009d0b0)
/*  f095480:	8c42d0b0 */ 	lw	$v0,%lo(var8009d0b0)($v0)
/*  f095484:	3c03800a */ 	lui	$v1,%hi(g_TagPtrs)
/*  f095488:	2463d0c8 */ 	addiu	$v1,$v1,%lo(g_TagPtrs)
/*  f09548c:	10400009 */ 	beqz	$v0,.L0f0954b4
/*  f095490:	3c040aff */ 	lui	$a0,0xaff
/*  f095494:	944c0004 */ 	lhu	$t4,0x4($v0)
.L0f095498:
/*  f095498:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f09549c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0954a0:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f0954a4:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f0954a8:	8c420008 */ 	lw	$v0,0x8($v0)
/*  f0954ac:	5440fffa */ 	bnezl	$v0,.L0f095498
/*  f0954b0:	944c0004 */ 	lhu	$t4,0x4($v0)
.L0f0954b4:
/*  f0954b4:	0fc254c8 */ 	jal	func0f095320
/*  f0954b8:	3484b4a3 */ 	ori	$a0,$a0,0xb4a3
/*  f0954bc:	3c04adfe */ 	lui	$a0,0xadfe
/*  f0954c0:	0fc254cc */ 	jal	func0f095330
/*  f0954c4:	34840006 */ 	ori	$a0,$a0,0x6
/*  f0954c8:	0c0057f4 */ 	jal	func00015fd0
/*  f0954cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0954d0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0954d4:	504f0011 */ 	beql	$v0,$t7,.L0f09551c
/*  f0954d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0954dc:	0c004b70 */ 	jal	random
/*  f0954e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0954e4:	0c004b70 */ 	jal	random
/*  f0954e8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0954ec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0954f0:	3c010001 */ 	lui	$at,0x1
/*  f0954f4:	3421fff8 */ 	ori	$at,$at,0xfff8
/*  f0954f8:	0081c024 */ 	and	$t8,$a0,$at
/*  f0954fc:	3c018001 */ 	lui	$at,0x8001
/*  f095500:	03012021 */ 	addu	$a0,$t8,$at
/*  f095504:	3c010001 */ 	lui	$at,0x1
/*  f095508:	3421fffe */ 	ori	$at,$at,0xfffe
/*  f09550c:	00412824 */ 	and	$a1,$v0,$at
/*  f095510:	0c003504 */ 	jal	func0000d410
/*  f095514:	24061000 */ 	addiu	$a2,$zero,0x1000
/*  f095518:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f09551c:
/*  f09551c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f095520:	03e00008 */ 	jr	$ra
/*  f095524:	00000000 */ 	sll	$zero,$zero,0x0
);

struct tag *tagFindById(s32 tag_id)
{
	struct tag *tag = NULL;

	if (tag_id >= 0 && tag_id < g_NumTags) {
		tag = g_TagPtrs[tag_id];
	}

	return tag;
}

GLOBAL_ASM(
glabel func0f095560
/*  f095560:	3c03800a */ 	lui	$v1,%hi(var8009d0b0)
/*  f095564:	1080000f */ 	beqz	$a0,.L0f0955a4
/*  f095568:	8c63d0b0 */ 	lw	$v1,%lo(var8009d0b0)($v1)
/*  f09556c:	8c8e0040 */ 	lw	$t6,0x40($a0)
/*  f095570:	31cf0010 */ 	andi	$t7,$t6,0x10
/*  f095574:	51e0000c */ 	beqzl	$t7,.L0f0955a8
/*  f095578:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f09557c:	5060000a */ 	beqzl	$v1,.L0f0955a8
/*  f095580:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f095584:	8c78000c */ 	lw	$t8,0xc($v1)
.L0f095588:
/*  f095588:	54980004 */ 	bnel	$a0,$t8,.L0f09559c
/*  f09558c:	8c630008 */ 	lw	$v1,0x8($v1)
/*  f095590:	03e00008 */ 	jr	$ra
/*  f095594:	94620004 */ 	lhu	$v0,0x4($v1)
/*  f095598:	8c630008 */ 	lw	$v1,0x8($v1)
.L0f09559c:
/*  f09559c:	5460fffa */ 	bnezl	$v1,.L0f095588
/*  f0955a0:	8c78000c */ 	lw	$t8,0xc($v1)
.L0f0955a4:
/*  f0955a4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0955a8:
/*  f0955a8:	03e00008 */ 	jr	$ra
/*  f0955ac:	00000000 */ 	sll	$zero,$zero,0x0
);

struct defaultobj *objFindByTagId(s32 tag_id)
{
	struct tag *tag = tagFindById(tag_id);
	struct defaultobj *obj = NULL;

	if (tag) {
		obj = tag->obj;
	}

	if (obj && (obj->hidden & 0x10) == 0) {
		obj = NULL;
	}

	return obj;
}

s32 objectiveGetCount(void)
{
	return var8006ae70 + 1;
}

char *objectiveGetText(s32 index)
{
	if (index < 10 && g_Objectives[index]) {
		return langGet(g_Objectives[index]->text);
	}

	return NULL;
}

u32 objectiveGetDifficultyBits(s32 index)
{
	if (index < 10 && g_Objectives[index]) {
		return g_Objectives[index]->difficulties;
	}

	return DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD;
}

GLOBAL_ASM(
glabel objectiveGetStatus
.late_rodata
glabel var7f1ab7cc
.word objectiveGetStatus+0x454 # f095ad8
glabel var7f1ab7d0
.word objectiveGetStatus+0x454 # f095ad8
glabel var7f1ab7d4
.word objectiveGetStatus+0x98 # f09571c
glabel var7f1ab7d8
.word objectiveGetStatus+0xcc # f095750
glabel var7f1ab7dc
.word objectiveGetStatus+0xe8 # f09576c
glabel var7f1ab7e0
.word objectiveGetStatus+0x104 # f095788
glabel var7f1ab7e4
.word objectiveGetStatus+0x288 # f09590c
glabel var7f1ab7e8
.word objectiveGetStatus+0x3e4 # f095a68
glabel var7f1ab7ec
.word objectiveGetStatus+0x454 # f095ad8
glabel var7f1ab7f0
.word objectiveGetStatus+0x430 # f095ab4
glabel var7f1ab7f4
.word objectiveGetStatus+0x444 # f095ac8
.text
/*  f095684:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f095688:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f09568c:	2881000a */ 	slti	$at,$a0,0xa
/*  f095690:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f095694:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f095698:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f09569c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0956a0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0956a4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0956a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0956ac:	1020011e */ 	beqz	$at,.L0f095b28
/*  f0956b0:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f0956b4:	00041080 */ 	sll	$v0,$a0,0x2
/*  f0956b8:	3c04800a */ 	lui	$a0,%hi(g_Objectives)
/*  f0956bc:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0956c0:	8c84d060 */ 	lw	$a0,%lo(g_Objectives)($a0)
/*  f0956c4:	54800006 */ 	bnezl	$a0,.L0f0956e0
/*  f0956c8:	90830003 */ 	lbu	$v1,0x3($a0)
/*  f0956cc:	3c16800a */ 	lui	$s6,%hi(var8009d088)
/*  f0956d0:	02c2b021 */ 	addu	$s6,$s6,$v0
/*  f0956d4:	10000114 */ 	beqz	$zero,.L0f095b28
/*  f0956d8:	8ed6d088 */ 	lw	$s6,%lo(var8009d088)($s6)
/*  f0956dc:	90830003 */ 	lbu	$v1,0x3($a0)
.L0f0956e0:
/*  f0956e0:	24010018 */ 	addiu	$at,$zero,0x18
/*  f0956e4:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0956e8:	1061010f */ 	beq	$v1,$at,.L0f095b28
/*  f0956ec:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0956f0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0956f4:	246effe9 */ 	addiu	$t6,$v1,-23
.L0f0956f8:
/*  f0956f8:	2dc1000b */ 	sltiu	$at,$t6,0xb
/*  f0956fc:	102000f6 */ 	beqz	$at,.L0f095ad8
/*  f095700:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f095704:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f095708:	3c017f1b */ 	lui	$at,%hi(var7f1ab7cc)
/*  f09570c:	002e0821 */ 	addu	$at,$at,$t6
/*  f095710:	8c2eb7cc */ 	lw	$t6,%lo(var7f1ab7cc)($at)
/*  f095714:	01c00008 */ 	jr	$t6
/*  f095718:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09571c:	0fc2556c */ 	jal	objFindByTagId
/*  f095720:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f095724:	104000ec */ 	beqz	$v0,.L0f095ad8
/*  f095728:	00402025 */ 	or	$a0,$v0,$zero
/*  f09572c:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f095730:	51e000ea */ 	beqzl	$t7,.L0f095adc
/*  f095734:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095738:	0fc21a6a */ 	jal	objIsHealthy
/*  f09573c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095740:	504000e6 */ 	beqzl	$v0,.L0f095adc
/*  f095744:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095748:	100000e3 */ 	beqz	$zero,.L0f095ad8
/*  f09574c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f095750:	00002025 */ 	or	$a0,$zero,$zero
/*  f095754:	0fc127da */ 	jal	chrHasStageFlag
/*  f095758:	8ea50004 */ 	lw	$a1,0x4($s5)
/*  f09575c:	544000df */ 	bnezl	$v0,.L0f095adc
/*  f095760:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095764:	100000dc */ 	beqz	$zero,.L0f095ad8
/*  f095768:	0000a025 */ 	or	$s4,$zero,$zero
/*  f09576c:	00002025 */ 	or	$a0,$zero,$zero
/*  f095770:	0fc127da */ 	jal	chrHasStageFlag
/*  f095774:	8ea50004 */ 	lw	$a1,0x4($s5)
/*  f095778:	504000d8 */ 	beqzl	$v0,.L0f095adc
/*  f09577c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095780:	100000d5 */ 	beqz	$zero,.L0f095ad8
/*  f095784:	24140002 */ 	addiu	$s4,$zero,0x2
/*  f095788:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f09578c:	0fc2556c */ 	jal	objFindByTagId
/*  f095790:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f095794:	10400008 */ 	beqz	$v0,.L0f0957b8
/*  f095798:	00409825 */ 	or	$s3,$v0,$zero
/*  f09579c:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f0957a0:	13000005 */ 	beqz	$t8,.L0f0957b8
/*  f0957a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0957a8:	0fc21a6a */ 	jal	objIsHealthy
/*  f0957ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0957b0:	54400004 */ 	bnezl	$v0,.L0f0957c4
/*  f0957b4:	8e48006c */ 	lw	$t0,0x6c($s2)
.L0f0957b8:
/*  f0957b8:	100000c7 */ 	beqz	$zero,.L0f095ad8
/*  f0957bc:	24140002 */ 	addiu	$s4,$zero,0x2
/*  f0957c0:	8e48006c */ 	lw	$t0,0x6c($s2)
.L0f0957c4:
/*  f0957c4:	8e59028c */ 	lw	$t9,0x28c($s2)
/*  f0957c8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0957cc:	11000003 */ 	beqz	$t0,.L0f0957dc
/*  f0957d0:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f0957d4:	10000002 */ 	beqz	$zero,.L0f0957e0
/*  f0957d8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0957dc:
/*  f0957dc:	00003025 */ 	or	$a2,$zero,$zero
.L0f0957e0:
/*  f0957e0:	8e490068 */ 	lw	$t1,0x68($s2)
/*  f0957e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0957e8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0957ec:	11200003 */ 	beqz	$t1,.L0f0957fc
/*  f0957f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0957f4:	10000001 */ 	beqz	$zero,.L0f0957fc
/*  f0957f8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0957fc:
/*  f0957fc:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f095800:	00117880 */ 	sll	$t7,$s1,0x2
/*  f095804:	024f8021 */ 	addu	$s0,$s2,$t7
/*  f095808:	11400003 */ 	beqz	$t2,.L0f095818
/*  f09580c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095810:	10000001 */ 	beqz	$zero,.L0f095818
/*  f095814:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f095818:
/*  f095818:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f09581c:	11600003 */ 	beqz	$t3,.L0f09582c
/*  f095820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095824:	10000001 */ 	beqz	$zero,.L0f09582c
/*  f095828:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f09582c:
/*  f09582c:	00436021 */ 	addu	$t4,$v0,$v1
/*  f095830:	01856821 */ 	addu	$t5,$t4,$a1
/*  f095834:	01a67021 */ 	addu	$t6,$t5,$a2
/*  f095838:	19c0002d */ 	blez	$t6,.L0f0958f0
/*  f09583c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095840:	8e020064 */ 	lw	$v0,0x64($s0)
.L0f095844:
/*  f095844:	8e5802a0 */ 	lw	$t8,0x2a0($s2)
/*  f095848:	13020004 */ 	beq	$t8,$v0,.L0f09585c
/*  f09584c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095850:	8e5902a4 */ 	lw	$t9,0x2a4($s2)
/*  f095854:	5722000a */ 	bnel	$t9,$v0,.L0f095880
/*  f095858:	8e49006c */ 	lw	$t1,0x6c($s2)
.L0f09585c:
/*  f09585c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f095860:	02202025 */ 	or	$a0,$s1,$zero
/*  f095864:	0fc44a33 */ 	jal	currentPlayerHasProp
/*  f095868:	8e640014 */ 	lw	$a0,0x14($s3)
/*  f09586c:	10400003 */ 	beqz	$v0,.L0f09587c
/*  f095870:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f095874:	1000001e */ 	beqz	$zero,.L0f0958f0
/*  f095878:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f09587c:
/*  f09587c:	8e49006c */ 	lw	$t1,0x6c($s2)
.L0f095880:
/*  f095880:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f095884:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f095888:	8e420068 */ 	lw	$v0,0x68($s2)
/*  f09588c:	8e430064 */ 	lw	$v1,0x64($s2)
/*  f095890:	11200003 */ 	beqz	$t1,.L0f0958a0
/*  f095894:	8e440070 */ 	lw	$a0,0x70($s2)
/*  f095898:	10000002 */ 	beqz	$zero,.L0f0958a4
/*  f09589c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0958a0:
/*  f0958a0:	00003025 */ 	or	$a2,$zero,$zero
.L0f0958a4:
/*  f0958a4:	10400003 */ 	beqz	$v0,.L0f0958b4
/*  f0958a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0958ac:	10000001 */ 	beqz	$zero,.L0f0958b4
/*  f0958b0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0958b4:
/*  f0958b4:	10600003 */ 	beqz	$v1,.L0f0958c4
/*  f0958b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0958bc:	10000002 */ 	beqz	$zero,.L0f0958c8
/*  f0958c0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0958c4:
/*  f0958c4:	00001825 */ 	or	$v1,$zero,$zero
.L0f0958c8:
/*  f0958c8:	10800003 */ 	beqz	$a0,.L0f0958d8
/*  f0958cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0958d0:	10000001 */ 	beqz	$zero,.L0f0958d8
/*  f0958d4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0958d8:
/*  f0958d8:	00435021 */ 	addu	$t2,$v0,$v1
/*  f0958dc:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0958e0:	01666021 */ 	addu	$t4,$t3,$a2
/*  f0958e4:	022c082a */ 	slt	$at,$s1,$t4
/*  f0958e8:	5420ffd6 */ 	bnezl	$at,.L0f095844
/*  f0958ec:	8e020064 */ 	lw	$v0,0x64($s0)
.L0f0958f0:
/*  f0958f0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0958f4:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f0958f8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0958fc:	55a00077 */ 	bnezl	$t5,.L0f095adc
/*  f095900:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095904:	10000074 */ 	beqz	$zero,.L0f095ad8
/*  f095908:	0000a025 */ 	or	$s4,$zero,$zero
/*  f09590c:	0fc2556c */ 	jal	objFindByTagId
/*  f095910:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f095914:	10400070 */ 	beqz	$v0,.L0f095ad8
/*  f095918:	00409825 */ 	or	$s3,$v0,$zero
/*  f09591c:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f095920:	51c0006e */ 	beqzl	$t6,.L0f095adc
/*  f095924:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095928:	8e58006c */ 	lw	$t8,0x6c($s2)
/*  f09592c:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f095930:	00008825 */ 	or	$s1,$zero,$zero
/*  f095934:	13000003 */ 	beqz	$t8,.L0f095944
/*  f095938:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f09593c:	10000002 */ 	beqz	$zero,.L0f095948
/*  f095940:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f095944:
/*  f095944:	00003025 */ 	or	$a2,$zero,$zero
.L0f095948:
/*  f095948:	8e590068 */ 	lw	$t9,0x68($s2)
/*  f09594c:	00002825 */ 	or	$a1,$zero,$zero
/*  f095950:	00001825 */ 	or	$v1,$zero,$zero
/*  f095954:	13200003 */ 	beqz	$t9,.L0f095964
/*  f095958:	00001025 */ 	or	$v0,$zero,$zero
/*  f09595c:	10000001 */ 	beqz	$zero,.L0f095964
/*  f095960:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f095964:
/*  f095964:	8e480064 */ 	lw	$t0,0x64($s2)
/*  f095968:	00116880 */ 	sll	$t5,$s1,0x2
/*  f09596c:	024d8021 */ 	addu	$s0,$s2,$t5
/*  f095970:	11000003 */ 	beqz	$t0,.L0f095980
/*  f095974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095978:	10000001 */ 	beqz	$zero,.L0f095980
/*  f09597c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f095980:
/*  f095980:	8e490070 */ 	lw	$t1,0x70($s2)
/*  f095984:	11200003 */ 	beqz	$t1,.L0f095994
/*  f095988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09598c:	10000001 */ 	beqz	$zero,.L0f095994
/*  f095990:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f095994:
/*  f095994:	00435021 */ 	addu	$t2,$v0,$v1
/*  f095998:	01455821 */ 	addu	$t3,$t2,$a1
/*  f09599c:	01666021 */ 	addu	$t4,$t3,$a2
/*  f0959a0:	1980002d */ 	blez	$t4,.L0f095a58
/*  f0959a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0959a8:	8e020064 */ 	lw	$v0,0x64($s0)
.L0f0959ac:
/*  f0959ac:	8e4e02a0 */ 	lw	$t6,0x2a0($s2)
/*  f0959b0:	11c20004 */ 	beq	$t6,$v0,.L0f0959c4
/*  f0959b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0959b8:	8e4f02a4 */ 	lw	$t7,0x2a4($s2)
/*  f0959bc:	55e2000a */ 	bnel	$t7,$v0,.L0f0959e8
/*  f0959c0:	8e58006c */ 	lw	$t8,0x6c($s2)
.L0f0959c4:
/*  f0959c4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0959c8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0959cc:	0fc44a33 */ 	jal	currentPlayerHasProp
/*  f0959d0:	8e640014 */ 	lw	$a0,0x14($s3)
/*  f0959d4:	50400004 */ 	beqzl	$v0,.L0f0959e8
/*  f0959d8:	8e58006c */ 	lw	$t8,0x6c($s2)
/*  f0959dc:	1000001e */ 	beqz	$zero,.L0f095a58
/*  f0959e0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0959e4:	8e58006c */ 	lw	$t8,0x6c($s2)
.L0f0959e8:
/*  f0959e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0959ec:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f0959f0:	8e420068 */ 	lw	$v0,0x68($s2)
/*  f0959f4:	8e430064 */ 	lw	$v1,0x64($s2)
/*  f0959f8:	13000003 */ 	beqz	$t8,.L0f095a08
/*  f0959fc:	8e440070 */ 	lw	$a0,0x70($s2)
/*  f095a00:	10000002 */ 	beqz	$zero,.L0f095a0c
/*  f095a04:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f095a08:
/*  f095a08:	00003025 */ 	or	$a2,$zero,$zero
.L0f095a0c:
/*  f095a0c:	10400003 */ 	beqz	$v0,.L0f095a1c
/*  f095a10:	00002825 */ 	or	$a1,$zero,$zero
/*  f095a14:	10000001 */ 	beqz	$zero,.L0f095a1c
/*  f095a18:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f095a1c:
/*  f095a1c:	10600003 */ 	beqz	$v1,.L0f095a2c
/*  f095a20:	00001025 */ 	or	$v0,$zero,$zero
/*  f095a24:	10000002 */ 	beqz	$zero,.L0f095a30
/*  f095a28:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f095a2c:
/*  f095a2c:	00001825 */ 	or	$v1,$zero,$zero
.L0f095a30:
/*  f095a30:	10800003 */ 	beqz	$a0,.L0f095a40
/*  f095a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095a38:	10000001 */ 	beqz	$zero,.L0f095a40
/*  f095a3c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f095a40:
/*  f095a40:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f095a44:	03254021 */ 	addu	$t0,$t9,$a1
/*  f095a48:	01064821 */ 	addu	$t1,$t0,$a2
/*  f095a4c:	0229082a */ 	slt	$at,$s1,$t1
/*  f095a50:	5420ffd6 */ 	bnezl	$at,.L0f0959ac
/*  f095a54:	8e020064 */ 	lw	$v0,0x64($s0)
.L0f095a58:
/*  f095a58:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f095a5c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f095a60:	1000001e */ 	beqz	$zero,.L0f095adc
/*  f095a64:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095a68:	0fc2556c */ 	jal	objFindByTagId
/*  f095a6c:	8ea40004 */ 	lw	$a0,0x4($s5)
/*  f095a70:	8eaa0008 */ 	lw	$t2,0x8($s5)
/*  f095a74:	00402025 */ 	or	$a0,$v0,$zero
/*  f095a78:	55400018 */ 	bnezl	$t2,.L0f095adc
/*  f095a7c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095a80:	10400008 */ 	beqz	$v0,.L0f095aa4
/*  f095a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095a88:	8c4b0014 */ 	lw	$t3,0x14($v0)
/*  f095a8c:	11600005 */ 	beqz	$t3,.L0f095aa4
/*  f095a90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095a94:	0fc21a6a */ 	jal	objIsHealthy
/*  f095a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095a9c:	14400003 */ 	bnez	$v0,.L0f095aac
/*  f095aa0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095aa4:
/*  f095aa4:	1000000c */ 	beqz	$zero,.L0f095ad8
/*  f095aa8:	24140002 */ 	addiu	$s4,$zero,0x2
.L0f095aac:
/*  f095aac:	1000000a */ 	beqz	$zero,.L0f095ad8
/*  f095ab0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f095ab4:	8eac0008 */ 	lw	$t4,0x8($s5)
/*  f095ab8:	55800008 */ 	bnezl	$t4,.L0f095adc
/*  f095abc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095ac0:	10000005 */ 	beqz	$zero,.L0f095ad8
/*  f095ac4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f095ac8:	8ead000c */ 	lw	$t5,0xc($s5)
/*  f095acc:	55a00003 */ 	bnezl	$t5,.L0f095adc
/*  f095ad0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f095ad4:	0000a025 */ 	or	$s4,$zero,$zero
.L0f095ad8:
/*  f095ad8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f095adc:
/*  f095adc:	16c20005 */ 	bne	$s6,$v0,.L0f095af4
/*  f095ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095ae4:	12820008 */ 	beq	$s4,$v0,.L0f095b08
/*  f095ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095aec:	10000006 */ 	beqz	$zero,.L0f095b08
/*  f095af0:	0280b025 */ 	or	$s6,$s4,$zero
.L0f095af4:
/*  f095af4:	16c00004 */ 	bnez	$s6,.L0f095b08
/*  f095af8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f095afc:	16810002 */ 	bne	$s4,$at,.L0f095b08
/*  f095b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095b04:	0280b025 */ 	or	$s6,$s4,$zero
.L0f095b08:
/*  f095b08:	0fc24784 */ 	jal	setupGetCommandLength
/*  f095b0c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f095b10:	00027080 */ 	sll	$t6,$v0,0x2
/*  f095b14:	01d5a821 */ 	addu	$s5,$t6,$s5
/*  f095b18:	92a30003 */ 	lbu	$v1,0x3($s5)
/*  f095b1c:	24010018 */ 	addiu	$at,$zero,0x18
/*  f095b20:	5461fef5 */ 	bnel	$v1,$at,.L0f0956f8
/*  f095b24:	246effe9 */ 	addiu	$t6,$v1,-23
.L0f095b28:
/*  f095b28:	0fc47b88 */ 	jal	func0f11ee20
/*  f095b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095b30:	10400002 */ 	beqz	$v0,.L0f095b3c
/*  f095b34:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f095b38:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f095b3c:
/*  f095b3c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f095b40:	02c01025 */ 	or	$v0,$s6,$zero
/*  f095b44:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f095b48:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f095b4c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f095b50:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f095b54:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f095b58:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f095b5c:	03e00008 */ 	jr	$ra
/*  f095b60:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

bool objectiveIsAllComplete(void)
{
	s32 i;

	for (i = 0; i < objectiveGetCount(); i++) {
		u32 diffbits = objectiveGetDifficultyBits(i);

		if ((1 << getDifficulty() & diffbits) &&
				objectiveGetStatus(i) != OBJECTIVE_COMPLETE) {
			return false;
		}
	}

	return true;
}

GLOBAL_ASM(
glabel func0f095bf4
/*  f095bf4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f095bf8:	3c018007 */ 	lui	$at,0x8007
/*  f095bfc:	03e00008 */ 	jr	$ra
/*  f095c00:	ac2eae74 */ 	sw	$t6,-0x518c($at)
);

GLOBAL_ASM(
glabel func0f095c04
/*  f095c04:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f095c08:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f095c0c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f095c10:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f095c14:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f095c18:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f095c1c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f095c20:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f095c24:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f095c28:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f095c2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f095c30:	11e00003 */ 	beqz	$t7,.L0f095c40
/*  f095c34:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f095c38:	10000002 */ 	beqz	$zero,.L0f095c44
/*  f095c3c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f095c40:
/*  f095c40:	00002825 */ 	or	$a1,$zero,$zero
.L0f095c44:
/*  f095c44:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f095c48:	00002025 */ 	or	$a0,$zero,$zero
/*  f095c4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f095c50:	13000003 */ 	beqz	$t8,.L0f095c60
/*  f095c54:	00001025 */ 	or	$v0,$zero,$zero
/*  f095c58:	10000001 */ 	beqz	$zero,.L0f095c60
/*  f095c5c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f095c60:
/*  f095c60:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f095c64:	13200003 */ 	beqz	$t9,.L0f095c74
/*  f095c68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095c6c:	10000001 */ 	beqz	$zero,.L0f095c74
/*  f095c70:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f095c74:
/*  f095c74:	8e080070 */ 	lw	$t0,0x70($s0)
/*  f095c78:	11000003 */ 	beqz	$t0,.L0f095c88
/*  f095c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095c80:	10000001 */ 	beqz	$zero,.L0f095c88
/*  f095c84:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f095c88:
/*  f095c88:	00434821 */ 	addu	$t1,$v0,$v1
/*  f095c8c:	01245021 */ 	addu	$t2,$t1,$a0
/*  f095c90:	01455821 */ 	addu	$t3,$t2,$a1
/*  f095c94:	1960002c */ 	blez	$t3,.L0f095d48
/*  f095c98:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095c9c:
/*  f095c9c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f095ca0:	02202025 */ 	or	$a0,$s1,$zero
/*  f095ca4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f095ca8:	8e0c02a0 */ 	lw	$t4,0x2a0($s0)
/*  f095cac:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f095cb0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f095cb4:	11820004 */ 	beq	$t4,$v0,.L0f095cc8
/*  f095cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095cbc:	8e0d02a4 */ 	lw	$t5,0x2a4($s0)
/*  f095cc0:	55a20004 */ 	bnel	$t5,$v0,.L0f095cd4
/*  f095cc4:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f095cc8:
/*  f095cc8:	0fc377e9 */ 	jal	func0f0ddfa4
/*  f095ccc:	24060018 */ 	addiu	$a2,$zero,0x18
/*  f095cd0:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f095cd4:
/*  f095cd4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f095cd8:	00002825 */ 	or	$a1,$zero,$zero
/*  f095cdc:	11c00003 */ 	beqz	$t6,.L0f095cec
/*  f095ce0:	00002025 */ 	or	$a0,$zero,$zero
/*  f095ce4:	10000001 */ 	beqz	$zero,.L0f095cec
/*  f095ce8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f095cec:
/*  f095cec:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f095cf0:	00001825 */ 	or	$v1,$zero,$zero
/*  f095cf4:	00001025 */ 	or	$v0,$zero,$zero
/*  f095cf8:	11e00003 */ 	beqz	$t7,.L0f095d08
/*  f095cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095d00:	10000001 */ 	beqz	$zero,.L0f095d08
/*  f095d04:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f095d08:
/*  f095d08:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f095d0c:	13000003 */ 	beqz	$t8,.L0f095d1c
/*  f095d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095d14:	10000001 */ 	beqz	$zero,.L0f095d1c
/*  f095d18:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f095d1c:
/*  f095d1c:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f095d20:	13200003 */ 	beqz	$t9,.L0f095d30
/*  f095d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095d28:	10000001 */ 	beqz	$zero,.L0f095d30
/*  f095d2c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f095d30:
/*  f095d30:	00434021 */ 	addu	$t0,$v0,$v1
/*  f095d34:	01044821 */ 	addu	$t1,$t0,$a0
/*  f095d38:	01255021 */ 	addu	$t2,$t1,$a1
/*  f095d3c:	022a082a */ 	slt	$at,$s1,$t2
/*  f095d40:	1420ffd6 */ 	bnez	$at,.L0f095c9c
/*  f095d44:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095d48:
/*  f095d48:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f095d4c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f095d50:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f095d54:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f095d58:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f095d5c:	03e00008 */ 	jr	$ra
/*  f095d60:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f095d64
/*  f095d64:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f095d68:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f095d6c:	3c0e7f1b */ 	lui	$t6,%hi(var7f1ab790)
/*  f095d70:	27b20054 */ 	addiu	$s2,$sp,0x54
/*  f095d74:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f095d78:	25ceb790 */ 	addiu	$t6,$t6,%lo(var7f1ab790)
/*  f095d7c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f095d80:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f095d84:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f095d88:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f095d8c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f095d90:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f095d94:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f095d98:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f095d9c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f095da0:	25d90030 */ 	addiu	$t9,$t6,0x30
/*  f095da4:	02404025 */ 	or	$t0,$s2,$zero
.L0f095da8:
/*  f095da8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f095dac:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f095db0:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f095db4:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f095db8:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f095dbc:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f095dc0:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f095dc4:	15d9fff8 */ 	bne	$t6,$t9,.L0f095da8
/*  f095dc8:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f095dcc:	95c10000 */ 	lhu	$at,0x0($t6)
/*  f095dd0:	3c098007 */ 	lui	$t1,%hi(var8006ae74)
/*  f095dd4:	3c168007 */ 	lui	$s6,%hi(var8006ae70)
/*  f095dd8:	a5010000 */ 	sh	$at,0x0($t0)
/*  f095ddc:	8d29ae74 */ 	lw	$t1,%lo(var8006ae74)($t1)
/*  f095de0:	26d6ae70 */ 	addiu	$s6,$s6,%lo(var8006ae70)
/*  f095de4:	55200053 */ 	bnezl	$t1,.L0f095f34
/*  f095de8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f095dec:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f095df0:	3c14800a */ 	lui	$s4,%hi(var8009d088)
/*  f095df4:	2694d088 */ 	addiu	$s4,$s4,%lo(var8009d088)
/*  f095df8:	0540004d */ 	bltz	$t2,.L0f095f30
/*  f095dfc:	00009825 */ 	or	$s3,$zero,$zero
/*  f095e00:	3c177f1b */ 	lui	$s7,%hi(var7f1ab7c4)
/*  f095e04:	26f7b7c4 */ 	addiu	$s7,$s7,%lo(var7f1ab7c4)
/*  f095e08:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f095e0c:
/*  f095e0c:	0fc255a1 */ 	jal	objectiveGetStatus
/*  f095e10:	02602025 */ 	or	$a0,$s3,$zero
/*  f095e14:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f095e18:	00408825 */ 	or	$s1,$v0,$zero
/*  f095e1c:	02602025 */ 	or	$a0,$s3,$zero
/*  f095e20:	104b0033 */ 	beq	$v0,$t3,.L0f095ef0
/*  f095e24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095e28:	0fc25594 */ 	jal	objectiveGetDifficultyBits
/*  f095e2c:	ae820000 */ 	sw	$v0,0x0($s4)
/*  f095e30:	0fc5b367 */ 	jal	getDifficulty
/*  f095e34:	00408025 */ 	or	$s0,$v0,$zero
/*  f095e38:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f095e3c:	004c6804 */ 	sllv	$t5,$t4,$v0
/*  f095e40:	01b0c024 */ 	and	$t8,$t5,$s0
/*  f095e44:	1300002a */ 	beqz	$t8,.L0f095ef0
/*  f095e48:	2404582c */ 	addiu	$a0,$zero,0x582c
/*  f095e4c:	0fc5b9f1 */ 	jal	langGet
/*  f095e50:	26b00001 */ 	addiu	$s0,$s5,0x1
/*  f095e54:	02402025 */ 	or	$a0,$s2,$zero
/*  f095e58:	02e02825 */ 	or	$a1,$s7,$zero
/*  f095e5c:	00403025 */ 	or	$a2,$v0,$zero
/*  f095e60:	0c004dad */ 	jal	sprintf
/*  f095e64:	02003825 */ 	or	$a3,$s0,$zero
/*  f095e68:	163e000b */ 	bne	$s1,$s8,.L0f095e98
/*  f095e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095e70:	0fc5b9f1 */ 	jal	langGet
/*  f095e74:	2404582d */ 	addiu	$a0,$zero,0x582d
/*  f095e78:	02402025 */ 	or	$a0,$s2,$zero
/*  f095e7c:	0c004c89 */ 	jal	strcat
/*  f095e80:	00402825 */ 	or	$a1,$v0,$zero
/*  f095e84:	02402025 */ 	or	$a0,$s2,$zero
/*  f095e88:	0fc25701 */ 	jal	func0f095c04
/*  f095e8c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f095e90:	10000017 */ 	beqz	$zero,.L0f095ef0
/*  f095e94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095e98:
/*  f095e98:	1620000b */ 	bnez	$s1,.L0f095ec8
/*  f095e9c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f095ea0:	0fc5b9f1 */ 	jal	langGet
/*  f095ea4:	2404582e */ 	addiu	$a0,$zero,0x582e
/*  f095ea8:	02402025 */ 	or	$a0,$s2,$zero
/*  f095eac:	0c004c89 */ 	jal	strcat
/*  f095eb0:	00402825 */ 	or	$a1,$v0,$zero
/*  f095eb4:	02402025 */ 	or	$a0,$s2,$zero
/*  f095eb8:	0fc25701 */ 	jal	func0f095c04
/*  f095ebc:	03c02825 */ 	or	$a1,$s8,$zero
/*  f095ec0:	1000000b */ 	beqz	$zero,.L0f095ef0
/*  f095ec4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095ec8:
/*  f095ec8:	16210009 */ 	bne	$s1,$at,.L0f095ef0
/*  f095ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095ed0:	0fc5b9f1 */ 	jal	langGet
/*  f095ed4:	2404582f */ 	addiu	$a0,$zero,0x582f
/*  f095ed8:	02402025 */ 	or	$a0,$s2,$zero
/*  f095edc:	0c004c89 */ 	jal	strcat
/*  f095ee0:	00402825 */ 	or	$a1,$v0,$zero
/*  f095ee4:	02402025 */ 	or	$a0,$s2,$zero
/*  f095ee8:	0fc25701 */ 	jal	func0f095c04
/*  f095eec:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f095ef0:
/*  f095ef0:	0fc25594 */ 	jal	objectiveGetDifficultyBits
/*  f095ef4:	02602025 */ 	or	$a0,$s3,$zero
/*  f095ef8:	0fc5b367 */ 	jal	getDifficulty
/*  f095efc:	00408025 */ 	or	$s0,$v0,$zero
/*  f095f00:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f095f04:	004fc804 */ 	sllv	$t9,$t7,$v0
/*  f095f08:	03307024 */ 	and	$t6,$t9,$s0
/*  f095f0c:	51c00003 */ 	beqzl	$t6,.L0f095f1c
/*  f095f10:	8ec80000 */ 	lw	$t0,0x0($s6)
/*  f095f14:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f095f18:	8ec80000 */ 	lw	$t0,0x0($s6)
.L0f095f1c:
/*  f095f1c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f095f20:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f095f24:	0113082a */ 	slt	$at,$t0,$s3
/*  f095f28:	1020ffb8 */ 	beqz	$at,.L0f095e0c
/*  f095f2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f095f30:
/*  f095f30:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f095f34:
/*  f095f34:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f095f38:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f095f3c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f095f40:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f095f44:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f095f48:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f095f4c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f095f50:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f095f54:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f095f58:	03e00008 */ 	jr	$ra
/*  f095f5c:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

void objectiveCheckRoomEntered(s32 currentroom)
{
	struct criteria_roomentered *criteria = g_RoomEnteredCriterias;

	while (criteria) {
		if (criteria->status == OBJECTIVE_INCOMPLETE) {
			s32 room = chrGetPadRoom(NULL, criteria->pad);

			if (room >= 0 && room == currentroom) {
				criteria->status = OBJECTIVE_COMPLETE;
			}
		}

		criteria = criteria->next;
	}
}

void objectiveCheckMultiroomEntered(s32 arg0, s16 *requiredrooms)
{
	struct criteria_multiroomentered *criteria = g_MultiroomEnteredCriterias;

	while (criteria) {
		if (criteria->status == OBJECTIVE_INCOMPLETE && criteria->unk04 == arg0) {
			s32 room = chrGetPadRoom(NULL, criteria->pad);

			if (room >= 0) {
				s16 objectiverooms[2];
				objectiverooms[0] = room;
				objectiverooms[1] = -1;

				if (arrayIntersects(&objectiverooms[0], requiredrooms)) {
					criteria->status = OBJECTIVE_COMPLETE;
				}
			}
		}

		criteria = criteria->next;
	}
}

GLOBAL_ASM(
glabel objectiveCheckHolograph
/*  f096088:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f09608c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f096090:	3c11800a */ 	lui	$s1,%hi(g_HolographCriterias)
/*  f096094:	8e31d0c0 */ 	lw	$s1,%lo(g_HolographCriterias)($s1)
/*  f096098:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f09609c:	46006586 */ 	mov.s	$f22,$f12
/*  f0960a0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0960a4:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f0960a8:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f0960ac:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f0960b0:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f0960b4:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0960b8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0960bc:	1220009a */ 	beqz	$s1,.L0f096328
/*  f0960c0:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0960c4:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0960c8:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0960cc:	27b6008c */ 	addiu	$s6,$sp,0x8c
/*  f0960d0:	27b50094 */ 	addiu	$s5,$sp,0x94
/*  f0960d4:	27b4009c */ 	addiu	$s4,$sp,0x9c
/*  f0960d8:	24130026 */ 	addiu	$s3,$zero,0x26
/*  f0960dc:	8e4e04b4 */ 	lw	$t6,0x4b4($s2)
.L0f0960e0:
/*  f0960e0:	566e0003 */ 	bnel	$s3,$t6,.L0f0960f0
/*  f0960e4:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f0960e8:	ae200008 */ 	sw	$zero,0x8($s1)
/*  f0960ec:	8e2f0008 */ 	lw	$t7,0x8($s1)
.L0f0960f0:
/*  f0960f0:	55e0008b */ 	bnezl	$t7,.L0f096320
/*  f0960f4:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0960f8:	0fc2556c */ 	jal	objFindByTagId
/*  f0960fc:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f096100:	10400086 */ 	beqz	$v0,.L0f09631c
/*  f096104:	00408025 */ 	or	$s0,$v0,$zero
/*  f096108:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f09610c:	50600084 */ 	beqzl	$v1,.L0f096320
/*  f096110:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096114:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f096118:	33190002 */ 	andi	$t9,$t8,0x2
/*  f09611c:	53200080 */ 	beqzl	$t9,.L0f096320
/*  f096120:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096124:	c4640014 */ 	lwc1	$f4,0x14($v1)
/*  f096128:	44803000 */ 	mtc1	$zero,$f6
/*  f09612c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096130:	4604303e */ 	c.le.s	$f6,$f4
/*  f096134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096138:	45020079 */ 	bc1fl	.L0f096320
/*  f09613c:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096140:	0fc21a6a */ 	jal	objIsHealthy
/*  f096144:	00402025 */ 	or	$a0,$v0,$zero
/*  f096148:	50400075 */ 	beqzl	$v0,.L0f096320
/*  f09614c:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096150:	44804000 */ 	mtc1	$zero,$f8
/*  f096154:	3c01bf80 */ 	lui	$at,0xbf80
/*  f096158:	44816000 */ 	mtc1	$at,$f12
/*  f09615c:	4608b032 */ 	c.eq.s	$f22,$f8
/*  f096160:	02802825 */ 	or	$a1,$s4,$zero
/*  f096164:	02a03025 */ 	or	$a2,$s5,$zero
/*  f096168:	02c03825 */ 	or	$a3,$s6,$zero
/*  f09616c:	45030010 */ 	bc1tl	.L0f0961b0
/*  f096170:	4616603c */ 	c.lt.s	$f12,$f22
/*  f096174:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f096178:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f09617c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f096180:	c4701bb0 */ 	lwc1	$f16,0x1bb0($v1)
/*  f096184:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f096188:	c4641bb8 */ 	lwc1	$f4,0x1bb8($v1)
/*  f09618c:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f096190:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f096194:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f096198:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09619c:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0961a0:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f0961a4:	4616b582 */ 	mul.s	$f22,$f22,$f22
/*  f0961a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0961ac:	4616603c */ 	c.lt.s	$f12,$f22
.L0f0961b0:
/*  f0961b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0961b4:	4502005a */ 	bc1fl	.L0f096320
/*  f0961b8:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0961bc:	0fc22677 */ 	jal	func0f0899dc
/*  f0961c0:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f0961c4:	10400055 */ 	beqz	$v0,.L0f09631c
/*  f0961c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0961cc:	27a80070 */ 	addiu	$t0,$sp,0x70
/*  f0961d0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0961d4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0961d8:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0961dc:	0fc1a00f */ 	jal	func0f06803c
/*  f0961e0:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0961e4:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0961e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0961ec:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f0961f0:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0961f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0961f8:	45020049 */ 	bc1fl	.L0f096320
/*  f0961fc:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096200:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f096204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096208:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f09620c:	46000506 */ 	mov.s	$f20,$f0
/*  f096210:	46140480 */ 	add.s	$f18,$f0,$f20
/*  f096214:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*  f096218:	4612803c */ 	c.lt.s	$f16,$f18
/*  f09621c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096220:	4502003f */ 	bc1fl	.L0f096320
/*  f096224:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096228:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f09622c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096230:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f096234:	4604003c */ 	c.lt.s	$f0,$f4
/*  f096238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09623c:	45020038 */ 	bc1fl	.L0f096320
/*  f096240:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096244:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f096248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09624c:	0fc2d5f6 */ 	jal	func0f0b57d8
/*  f096250:	46000506 */ 	mov.s	$f20,$f0
/*  f096254:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f096258:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f09625c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f096260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096264:	4502002e */ 	bc1fl	.L0f096320
/*  f096268:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f09626c:	0fc2d602 */ 	jal	func0f0b5808
/*  f096270:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096274:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f096278:	460a003c */ 	c.lt.s	$f0,$f10
/*  f09627c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096280:	45020027 */ 	bc1fl	.L0f096320
/*  f096284:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096288:	0fc2d602 */ 	jal	func0f0b5808
/*  f09628c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096290:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f096294:	46000506 */ 	mov.s	$f20,$f0
/*  f096298:	46140480 */ 	add.s	$f18,$f0,$f20
/*  f09629c:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f0962a0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0962a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0962a8:	4502001d */ 	bc1fl	.L0f096320
/*  f0962ac:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962b0:	0fc2d602 */ 	jal	func0f0b5808
/*  f0962b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0962b8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0962bc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0962c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0962c4:	45020016 */ 	bc1fl	.L0f096320
/*  f0962c8:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962cc:	0fc2d602 */ 	jal	func0f0b5808
/*  f0962d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0962d4:	0fc2d5fa */ 	jal	func0f0b57e8
/*  f0962d8:	46000506 */ 	mov.s	$f20,$f0
/*  f0962dc:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f0962e0:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f0962e4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0962e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0962ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0962f0:	4502000b */ 	bc1fl	.L0f096320
/*  f0962f4:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962f8:	ae290008 */ 	sw	$t1,0x8($s1)
/*  f0962fc:	8e4a04b4 */ 	lw	$t2,0x4b4($s2)
/*  f096300:	566a0007 */ 	bnel	$s3,$t2,.L0f096320
/*  f096304:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096308:	0fc68606 */ 	jal	ciGetTrainingData
/*  f09630c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f096310:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f096314:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f096318:	a04d0000 */ 	sb	$t5,0x0($v0)
.L0f09631c:
/*  f09631c:	8e31000c */ 	lw	$s1,0xc($s1)
.L0f096320:
/*  f096320:	5620ff6f */ 	bnezl	$s1,.L0f0960e0
/*  f096324:	8e4e04b4 */ 	lw	$t6,0x4b4($s2)
.L0f096328:
/*  f096328:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f09632c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f096330:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f096334:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f096338:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f09633c:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f096340:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f096344:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f096348:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f09634c:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f096350:	03e00008 */ 	jr	$ra
/*  f096354:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f096358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09635c:	00000000 */ 	sll	$zero,$zero,0x0
);
