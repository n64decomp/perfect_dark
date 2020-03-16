#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/inventory.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0dcdb0.h"
#include "game/game_127910.h"
#include "game/game_179060.h"
#include "game/mplayer.h"
#include "game/game_197600.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1acda0[] = "%s: %d\n";
const char var7f1acda8[] = "%s %d %s\n";
const char var7f1acdb4[] = "%s: %d\n";
const char var7f1acdbc[] = "%s %s";
const char var7f1acdc4[] = "%s %s";

const u32 var7f1acdcc[] = {0x00000000};
const u32 var7f1acdd0[] = {0x3dcccccd};

GLOBAL_ASM(
glabel func0f0b0420
/*  f0b0420:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b0424:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b0428:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b042c:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f0b0430:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0b0434:	3c050010 */ 	lui	$a1,0x10
/*  f0b0438:	14400008 */ 	bnez	$v0,.L0f0b045c
/*  f0b043c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0b0440:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0b0444:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0b0448:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b044c:	01d81021 */ 	addu	$v0,$t6,$t8
/*  f0b0450:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0b0454:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0b0458:	ac480000 */ 	sw	$t0,0x0($v0)
.L0f0b045c:
/*  f0b045c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b0460:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b0464:	03e00008 */ 	jr	$ra
/*  f0b0468:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b046c
/*  f0b046c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b0470:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b0474:	00803825 */ 	or	$a3,$a0,$zero
/*  f0b0478:	14a00012 */ 	bnez	$a1,.L0f0b04c4
/*  f0b047c:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0b0480:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f0b0484:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f0b0488:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0b048c:	3c050010 */ 	lui	$a1,0x10
/*  f0b0490:	1440001f */ 	bnez	$v0,.L0f0b0510
/*  f0b0494:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f0b0498:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x288)
/*  f0b049c:	8defa248 */ 	lw	$t7,%lo(g_Vars+0x288)($t7)
/*  f0b04a0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0b04a4:	3c018007 */ 	lui	$at,0x8007
/*  f0b04a8:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f0b04ac:	ac2e0590 */ 	sw	$t6,0x590($at)
/*  f0b04b0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0b04b4:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0b04b8:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0b04bc:	10000014 */ 	beqz	$zero,.L0f0b0510
/*  f0b04c0:	ac480000 */ 	sw	$t0,0x0($v0)
.L0f0b04c4:
/*  f0b04c4:	3c098007 */ 	lui	$t1,%hi(var80070590)
/*  f0b04c8:	8d290590 */ 	lw	$t1,%lo(var80070590)($t1)
/*  f0b04cc:	3c050010 */ 	lui	$a1,0x10
/*  f0b04d0:	51200010 */ 	beqzl	$t1,.L0f0b0514
/*  f0b04d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b04d8:	90e40000 */ 	lbu	$a0,0x0($a3)
/*  f0b04dc:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0b04e0:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f0b04e4:	14400008 */ 	bnez	$v0,.L0f0b0508
/*  f0b04e8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f0b04ec:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x288)
/*  f0b04f0:	8d4aa248 */ 	lw	$t2,%lo(g_Vars+0x288)($t2)
/*  f0b04f4:	00065880 */ 	sll	$t3,$a2,0x2
/*  f0b04f8:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0b04fc:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f0b0500:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0b0504:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0b0508:
/*  f0b0508:	3c018007 */ 	lui	$at,0x8007
/*  f0b050c:	ac200590 */ 	sw	$zero,0x590($at)
.L0f0b0510:
/*  f0b0510:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b0514:
/*  f0b0514:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b0518:	03e00008 */ 	jr	$ra
/*  f0b051c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b0520
/*  f0b0520:	3c018007 */ 	lui	$at,0x8007
/*  f0b0524:	03e00008 */ 	jr	$ra
/*  f0b0528:	ac200590 */ 	sw	$zero,0x590($at)
);

GLOBAL_ASM(
glabel func0f0b052c
/*  f0b052c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0b0530:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0b0534:	00047880 */ 	sll	$t7,$a0,0x2
/*  f0b0538:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b053c:	03e00008 */ 	jr	$ra
/*  f0b0540:	8f020000 */ 	lw	$v0,0x0($t8)
);

void incrementKillCount(void)
{
	g_Vars.killcount++;
}

void incrementKnockoutCount(void)
{
	g_Vars.knockoutcount++;
}

void decrementKnockoutCount(void)
{
	g_Vars.knockoutcount--;
}

u8 getKnockoutCount(void)
{
	return g_Vars.knockoutcount;
}

u32 getKillCount(void)
{
	return g_Vars.killcount;
}

GLOBAL_ASM(
glabel func0f0b05a4
/*  f0b05a4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b05a8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b05ac:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b05b0:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f0b05b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b05b8:	8c6e001c */ 	lw	$t6,0x1c($v1)
/*  f0b05bc:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0b05c0:	ac6f001c */ 	sw	$t7,0x1c($v1)
/*  f0b05c4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b05c8:	8c581960 */ 	lw	$t8,0x1960($v0)
/*  f0b05cc:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0b05d0:	ac591960 */ 	sw	$t9,0x1960($v0)
/*  f0b05d4:	8d090318 */ 	lw	$t1,0x318($t0)
/*  f0b05d8:	51200055 */ 	beqzl	$t1,.L0f0b0730
/*  f0b05dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b05e0:	0fc3089f */ 	jal	getMissionTime
/*  f0b05e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b05e8:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0b05ec:	0fc5b9f1 */ 	jal	langGet
/*  f0b05f0:	24044c01 */ 	addiu	$a0,$zero,0x4c01
/*  f0b05f4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b05f8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b05fc:	8d0a0288 */ 	lw	$t2,0x288($t0)
/*  f0b0600:	3c057f1b */ 	lui	$a1,%hi(var7f1acda0)
/*  f0b0604:	24a5cda0 */ 	addiu	$a1,$a1,%lo(var7f1acda0)
/*  f0b0608:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0b060c:	00403025 */ 	or	$a2,$v0,$zero
/*  f0b0610:	0c004dad */ 	jal	sprintf
/*  f0b0614:	8d47001c */ 	lw	$a3,0x1c($t2)
/*  f0b0618:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f0b061c:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f0b0620:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b0624:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0628:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b062c:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0630:	8c6b001c */ 	lw	$t3,0x1c($v1)
/*  f0b0634:	29610002 */ 	slti	$at,$t3,0x2
/*  f0b0638:	54200011 */ 	bnezl	$at,.L0f0b0680
/*  f0b063c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0640:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0b0644:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f0b0648:	8c6f0048 */ 	lw	$t7,0x48($v1)
/*  f0b064c:	8dae194c */ 	lw	$t6,0x194c($t5)
/*  f0b0650:	018e1023 */ 	subu	$v0,$t4,$t6
/*  f0b0654:	01e2082a */ 	slt	$at,$t7,$v0
/*  f0b0658:	50200004 */ 	beqzl	$at,.L0f0b066c
/*  f0b065c:	8c780044 */ 	lw	$t8,0x44($v1)
/*  f0b0660:	ac620048 */ 	sw	$v0,0x48($v1)
/*  f0b0664:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0668:	8c780044 */ 	lw	$t8,0x44($v1)
.L0f0b066c:
/*  f0b066c:	0058082a */ 	slt	$at,$v0,$t8
/*  f0b0670:	50200003 */ 	beqzl	$at,.L0f0b0680
/*  f0b0674:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0678:	ac620044 */ 	sw	$v0,0x44($v1)
/*  f0b067c:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0b0680:
/*  f0b0680:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0b0684:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b0688:	8c591954 */ 	lw	$t9,0x1954($v0)
/*  f0b068c:	ac591958 */ 	sw	$t9,0x1958($v0)
/*  f0b0690:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b0694:	8c491950 */ 	lw	$t1,0x1950($v0)
/*  f0b0698:	ac491954 */ 	sw	$t1,0x1954($v0)
/*  f0b069c:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b06a0:	8c4a194c */ 	lw	$t2,0x194c($v0)
/*  f0b06a4:	ac4a1950 */ 	sw	$t2,0x1950($v0)
/*  f0b06a8:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0b06ac:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f0b06b0:	adab194c */ 	sw	$t3,0x194c($t5)
/*  f0b06b4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0b06b8:	8c451950 */ 	lw	$a1,0x1950($v0)
/*  f0b06bc:	50c50016 */ 	beql	$a2,$a1,.L0f0b0718
/*  f0b06c0:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06c4:	8c43194c */ 	lw	$v1,0x194c($v0)
/*  f0b06c8:	00656023 */ 	subu	$t4,$v1,$a1
/*  f0b06cc:	29810078 */ 	slti	$at,$t4,0x78
/*  f0b06d0:	50200011 */ 	beqzl	$at,.L0f0b0718
/*  f0b06d4:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06d8:	8c451954 */ 	lw	$a1,0x1954($v0)
/*  f0b06dc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0b06e0:	10c5000c */ 	beq	$a2,$a1,.L0f0b0714
/*  f0b06e4:	00657023 */ 	subu	$t6,$v1,$a1
/*  f0b06e8:	29c10078 */ 	slti	$at,$t6,0x78
/*  f0b06ec:	5020000a */ 	beqzl	$at,.L0f0b0718
/*  f0b06f0:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b06f4:	8c451958 */ 	lw	$a1,0x1958($v0)
/*  f0b06f8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0b06fc:	10c50005 */ 	beq	$a2,$a1,.L0f0b0714
/*  f0b0700:	00657823 */ 	subu	$t7,$v1,$a1
/*  f0b0704:	29e10078 */ 	slti	$at,$t7,0x78
/*  f0b0708:	50200003 */ 	beqzl	$at,.L0f0b0718
/*  f0b070c:	8d030288 */ 	lw	$v1,0x288($t0)
/*  f0b0710:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0b0714:
/*  f0b0714:	8d030288 */ 	lw	$v1,0x288($t0)
.L0f0b0718:
/*  f0b0718:	8c780058 */ 	lw	$t8,0x58($v1)
/*  f0b071c:	0304082a */ 	slt	$at,$t8,$a0
/*  f0b0720:	50200003 */ 	beqzl	$at,.L0f0b0730
/*  f0b0724:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b0728:	ac640058 */ 	sw	$a0,0x58($v1)
/*  f0b072c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b0730:
/*  f0b0730:	27bd0138 */ 	addiu	$sp,$sp,0x138
/*  f0b0734:	03e00008 */ 	jr	$ra
/*  f0b0738:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b073c
/*  f0b073c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0b0740:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0b0744:	03e00008 */ 	jr	$ra
/*  f0b0748:	8dc2001c */ 	lw	$v0,0x1c($t6)
/*  f0b074c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x288)
/*  f0b0750:	8c42a248 */ 	lw	$v0,%lo(g_Vars+0x288)($v0)
/*  f0b0754:	8c4e0020 */ 	lw	$t6,0x20($v0)
/*  f0b0758:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0b075c:	03e00008 */ 	jr	$ra
/*  f0b0760:	ac4f0020 */ 	sw	$t7,0x20($v0)
);

GLOBAL_ASM(
glabel func0f0b0764
/*  f0b0764:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b0768:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b076c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0b0770:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0b0774:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0b0778:	8c4e1940 */ 	lw	$t6,0x1940($v0)
/*  f0b077c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0b0780:	ac4f1940 */ 	sw	$t7,0x1940($v0)
/*  f0b0784:	8c780318 */ 	lw	$t8,0x318($v1)
/*  f0b0788:	53000020 */ 	beqzl	$t8,.L0f0b080c
/*  f0b078c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0b0790:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f0b0794:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b0798:	8f281940 */ 	lw	$t0,0x1940($t9)
/*  f0b079c:	15010008 */ 	bne	$t0,$at,.L0f0b07c0
/*  f0b07a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b07a4:	0fc5b9f1 */ 	jal	langGet
/*  f0b07a8:	24044c02 */ 	addiu	$a0,$zero,0x4c02
/*  f0b07ac:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f0b07b0:	0c004dad */ 	jal	sprintf
/*  f0b07b4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0b07b8:	10000011 */ 	beqz	$zero,.L0f0b0800
/*  f0b07bc:	27a40030 */ 	addiu	$a0,$sp,0x30
.L0f0b07c0:
/*  f0b07c0:	0fc5b9f1 */ 	jal	langGet
/*  f0b07c4:	24044c03 */ 	addiu	$a0,$zero,0x4c03
/*  f0b07c8:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0b07cc:	0fc5b9f1 */ 	jal	langGet
/*  f0b07d0:	24044c04 */ 	addiu	$a0,$zero,0x4c04
/*  f0b07d4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0b07d8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0b07dc:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f0b07e0:	3c057f1b */ 	lui	$a1,%hi(var7f1acda8)
/*  f0b07e4:	24a5cda8 */ 	addiu	$a1,$a1,%lo(var7f1acda8)
/*  f0b07e8:	8d271940 */ 	lw	$a3,0x1940($t1)
/*  f0b07ec:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0b07f0:	27a40030 */ 	addiu	$a0,$sp,0x30
/*  f0b07f4:	0c004dad */ 	jal	sprintf
/*  f0b07f8:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f0b07fc:	27a40030 */ 	addiu	$a0,$sp,0x30
.L0f0b0800:
/*  f0b0800:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f0b0804:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b0808:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0b080c:
/*  f0b080c:	27bd0130 */ 	addiu	$sp,$sp,0x130
/*  f0b0810:	03e00008 */ 	jr	$ra
/*  f0b0814:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b0818
/*  f0b0818:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0b081c:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0b0820:	8d2e0318 */ 	lw	$t6,0x318($t1)
/*  f0b0824:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f0b0828:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b082c:	51c0006e */ 	beqzl	$t6,.L0f0b09e8
/*  f0b0830:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b0834:	0fc3089f */ 	jal	getMissionTime
/*  f0b0838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b083c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0b0840:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0b0844:	8d2f0288 */ 	lw	$t7,0x288($t1)
/*  f0b0848:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0b084c:	3c0c800b */ 	lui	$t4,%hi(g_MpSimulants)
/*  f0b0850:	8de30070 */ 	lw	$v1,0x70($t7)
/*  f0b0854:	258cc538 */ 	addiu	$t4,$t4,%lo(g_MpSimulants)
/*  f0b0858:	24044c05 */ 	addiu	$a0,$zero,0x4c05
/*  f0b085c:	28610004 */ 	slti	$at,$v1,0x4
/*  f0b0860:	10200008 */ 	beqz	$at,.L0f0b0884
/*  f0b0864:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0b0868:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0b086c:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f0b0870:	3c19800b */ 	lui	$t9,%hi(g_MpPlayers)
/*  f0b0874:	2739c7b8 */ 	addiu	$t9,$t9,%lo(g_MpPlayers)
/*  f0b0878:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f0b087c:	10000007 */ 	beqz	$zero,.L0f0b089c
/*  f0b0880:	03194021 */ 	addu	$t0,$t8,$t9
.L0f0b0884:
/*  f0b0884:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0b0888:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b088c:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0b0890:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b0894:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f0b0898:	016c4021 */ 	addu	$t0,$t3,$t4
.L0f0b089c:
/*  f0b089c:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0b08a0:	0fc5b9f1 */ 	jal	langGet
/*  f0b08a4:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0b08a8:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0b08ac:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0b08b0:	3c057f1b */ 	lui	$a1,%hi(var7f1acdb4)
/*  f0b08b4:	00036840 */ 	sll	$t5,$v1,0x1
/*  f0b08b8:	010d7021 */ 	addu	$t6,$t0,$t5
/*  f0b08bc:	85c70024 */ 	lh	$a3,0x24($t6)
/*  f0b08c0:	24a5cdb4 */ 	addiu	$a1,$a1,%lo(var7f1acdb4)
/*  f0b08c4:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0b08c8:	0c004dad */ 	jal	sprintf
/*  f0b08cc:	00403025 */ 	or	$a2,$v0,$zero
/*  f0b08d0:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0b08d4:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f0b08d8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b08dc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0b08e0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0b08e4:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b08e8:	8c4f001c */ 	lw	$t7,0x1c($v0)
/*  f0b08ec:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0b08f0:	54200011 */ 	bnezl	$at,.L0f0b0938
/*  f0b08f4:	8d220284 */ 	lw	$v0,0x284($t1)
/*  f0b08f8:	8d390284 */ 	lw	$t9,0x284($t1)
/*  f0b08fc:	8fb80034 */ 	lw	$t8,0x34($sp)
/*  f0b0900:	8c4b0048 */ 	lw	$t3,0x48($v0)
/*  f0b0904:	8f2a194c */ 	lw	$t2,0x194c($t9)
/*  f0b0908:	030a1823 */ 	subu	$v1,$t8,$t2
/*  f0b090c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0b0910:	50200004 */ 	beqzl	$at,.L0f0b0924
/*  f0b0914:	8c4c0044 */ 	lw	$t4,0x44($v0)
/*  f0b0918:	ac430048 */ 	sw	$v1,0x48($v0)
/*  f0b091c:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b0920:	8c4c0044 */ 	lw	$t4,0x44($v0)
.L0f0b0924:
/*  f0b0924:	006c082a */ 	slt	$at,$v1,$t4
/*  f0b0928:	50200003 */ 	beqzl	$at,.L0f0b0938
/*  f0b092c:	8d220284 */ 	lw	$v0,0x284($t1)
/*  f0b0930:	ac430044 */ 	sw	$v1,0x44($v0)
/*  f0b0934:	8d220284 */ 	lw	$v0,0x284($t1)
.L0f0b0938:
/*  f0b0938:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0b093c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0b0940:	8c4d1954 */ 	lw	$t5,0x1954($v0)
/*  f0b0944:	ac4d1958 */ 	sw	$t5,0x1958($v0)
/*  f0b0948:	8d220284 */ 	lw	$v0,0x284($t1)
/*  f0b094c:	8c4e1950 */ 	lw	$t6,0x1950($v0)
/*  f0b0950:	ac4e1954 */ 	sw	$t6,0x1954($v0)
/*  f0b0954:	8d220284 */ 	lw	$v0,0x284($t1)
/*  f0b0958:	8c4f194c */ 	lw	$t7,0x194c($v0)
/*  f0b095c:	ac4f1950 */ 	sw	$t7,0x1950($v0)
/*  f0b0960:	8d380284 */ 	lw	$t8,0x284($t1)
/*  f0b0964:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0b0968:	af19194c */ 	sw	$t9,0x194c($t8)
/*  f0b096c:	8d220284 */ 	lw	$v0,0x284($t1)
/*  f0b0970:	8c451950 */ 	lw	$a1,0x1950($v0)
/*  f0b0974:	50c50016 */ 	beql	$a2,$a1,.L0f0b09d0
/*  f0b0978:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b097c:	8c44194c */ 	lw	$a0,0x194c($v0)
/*  f0b0980:	00855023 */ 	subu	$t2,$a0,$a1
/*  f0b0984:	29410078 */ 	slti	$at,$t2,0x78
/*  f0b0988:	50200011 */ 	beqzl	$at,.L0f0b09d0
/*  f0b098c:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b0990:	8c451954 */ 	lw	$a1,0x1954($v0)
/*  f0b0994:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0b0998:	10c5000c */ 	beq	$a2,$a1,.L0f0b09cc
/*  f0b099c:	00855823 */ 	subu	$t3,$a0,$a1
/*  f0b09a0:	29610078 */ 	slti	$at,$t3,0x78
/*  f0b09a4:	5020000a */ 	beqzl	$at,.L0f0b09d0
/*  f0b09a8:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b09ac:	8c451958 */ 	lw	$a1,0x1958($v0)
/*  f0b09b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b09b4:	10c50005 */ 	beq	$a2,$a1,.L0f0b09cc
/*  f0b09b8:	00856023 */ 	subu	$t4,$a0,$a1
/*  f0b09bc:	29810078 */ 	slti	$at,$t4,0x78
/*  f0b09c0:	50200003 */ 	beqzl	$at,.L0f0b09d0
/*  f0b09c4:	8d220288 */ 	lw	$v0,0x288($t1)
/*  f0b09c8:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0b09cc:
/*  f0b09cc:	8d220288 */ 	lw	$v0,0x288($t1)
.L0f0b09d0:
/*  f0b09d0:	8c4d0058 */ 	lw	$t5,0x58($v0)
/*  f0b09d4:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0b09d8:	50200003 */ 	beqzl	$at,.L0f0b09e8
/*  f0b09dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b09e0:	ac430058 */ 	sw	$v1,0x58($v0)
/*  f0b09e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b09e8:
/*  f0b09e8:	27bd0140 */ 	addiu	$sp,$sp,0x140
/*  f0b09ec:	03e00008 */ 	jr	$ra
/*  f0b09f0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b09f4
/*  f0b09f4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b09f8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b09fc:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0b0a00:	8d0f0318 */ 	lw	$t7,0x318($t0)
/*  f0b0a04:	240effff */ 	addiu	$t6,$zero,-1
/*  f0b0a08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b0a0c:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0b0a10:	afa50154 */ 	sw	$a1,0x154($sp)
/*  f0b0a14:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0b0a18:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b0a1c:	11e00009 */ 	beqz	$t7,.L0f0b0a44
/*  f0b0a20:	afa00140 */ 	sw	$zero,0x140($sp)
/*  f0b0a24:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0x10)
/*  f0b0a28:	9318cb98 */ 	lbu	$t8,%lo(g_MpSetup+0x10)($t8)
/*  f0b0a2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b0a30:	57010005 */ 	bnel	$t8,$at,.L0f0b0a48
/*  f0b0a34:	8fb90150 */ 	lw	$t9,0x150($sp)
/*  f0b0a38:	0fc611ee */ 	jal	func0f1847b8
/*  f0b0a3c:	afa00148 */ 	sw	$zero,0x148($sp)
/*  f0b0a40:	8fa30148 */ 	lw	$v1,0x148($sp)
.L0f0b0a44:
/*  f0b0a44:	8fb90150 */ 	lw	$t9,0x150($sp)
.L0f0b0a48:
/*  f0b0a48:	07200019 */ 	bltz	$t9,.L0f0b0ab0
/*  f0b0a4c:	03202025 */ 	or	$a0,$t9,$zero
/*  f0b0a50:	0fc6341d */ 	jal	func0f18d074
/*  f0b0a54:	afa30148 */ 	sw	$v1,0x148($sp)
/*  f0b0a58:	04400015 */ 	bltz	$v0,.L0f0b0ab0
/*  f0b0a5c:	8fa30148 */ 	lw	$v1,0x148($sp)
/*  f0b0a60:	28410004 */ 	slti	$at,$v0,0x4
/*  f0b0a64:	10200009 */ 	beqz	$at,.L0f0b0a8c
/*  f0b0a68:	00026080 */ 	sll	$t4,$v0,0x2
/*  f0b0a6c:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0b0a70:	01224821 */ 	addu	$t1,$t1,$v0
/*  f0b0a74:	3c0a800b */ 	lui	$t2,%hi(g_MpPlayers)
/*  f0b0a78:	254ac7b8 */ 	addiu	$t2,$t2,%lo(g_MpPlayers)
/*  f0b0a7c:	00094940 */ 	sll	$t1,$t1,0x5
/*  f0b0a80:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0b0a84:	1000000a */ 	beqz	$zero,.L0f0b0ab0
/*  f0b0a88:	afab0140 */ 	sw	$t3,0x140($sp)
.L0f0b0a8c:
/*  f0b0a8c:	01826021 */ 	addu	$t4,$t4,$v0
/*  f0b0a90:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b0a94:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0b0a98:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b0a9c:	3c0e800b */ 	lui	$t6,%hi(g_MpSimulants)
/*  f0b0aa0:	25cec538 */ 	addiu	$t6,$t6,%lo(g_MpSimulants)
/*  f0b0aa4:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f0b0aa8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0b0aac:	afaf0140 */ 	sw	$t7,0x140($sp)
.L0f0b0ab0:
/*  f0b0ab0:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f0b0ab4:	07000018 */ 	bltz	$t8,.L0f0b0b18
/*  f0b0ab8:	03002025 */ 	or	$a0,$t8,$zero
/*  f0b0abc:	0fc6341d */ 	jal	func0f18d074
/*  f0b0ac0:	afa30148 */ 	sw	$v1,0x148($sp)
/*  f0b0ac4:	8fa30148 */ 	lw	$v1,0x148($sp)
/*  f0b0ac8:	04400013 */ 	bltz	$v0,.L0f0b0b18
/*  f0b0acc:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0b0ad0:	28410004 */ 	slti	$at,$v0,0x4
/*  f0b0ad4:	10200008 */ 	beqz	$at,.L0f0b0af8
/*  f0b0ad8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f0b0adc:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0b0ae0:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f0b0ae4:	3c09800b */ 	lui	$t1,%hi(g_MpPlayers)
/*  f0b0ae8:	2529c7b8 */ 	addiu	$t1,$t1,%lo(g_MpPlayers)
/*  f0b0aec:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0b0af0:	10000009 */ 	beqz	$zero,.L0f0b0b18
/*  f0b0af4:	03291821 */ 	addu	$v1,$t9,$t1
.L0f0b0af8:
/*  f0b0af8:	01425021 */ 	addu	$t2,$t2,$v0
/*  f0b0afc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b0b00:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0b0b04:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b0b08:	3c0c800b */ 	lui	$t4,%hi(g_MpSimulants)
/*  f0b0b0c:	258cc538 */ 	addiu	$t4,$t4,%lo(g_MpSimulants)
/*  f0b0b10:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f0b0b14:	016c1821 */ 	addu	$v1,$t3,$t4
.L0f0b0b18:
/*  f0b0b18:	8fad0154 */ 	lw	$t5,0x154($sp)
/*  f0b0b1c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0b20:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b0b24:	05a0003a */ 	bltz	$t5,.L0f0b0c10
/*  f0b0b28:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0b0b2c:	55cd0039 */ 	bnel	$t6,$t5,.L0f0b0c14
/*  f0b0b30:	8fae0154 */ 	lw	$t6,0x154($sp)
/*  f0b0b34:	1060000c */ 	beqz	$v1,.L0f0b0b68
/*  f0b0b38:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0b0b3c:	05e2000b */ 	bltzl	$t7,.L0f0b0b6c
/*  f0b0b40:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f0b0b44:	8478003c */ 	lh	$t8,0x3c($v1)
/*  f0b0b48:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0b0b4c:	a479003c */ 	sh	$t9,0x3c($v1)
/*  f0b0b50:	8fa9014c */ 	lw	$t1,0x14c($sp)
/*  f0b0b54:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0b0b58:	006a1021 */ 	addu	$v0,$v1,$t2
/*  f0b0b5c:	844b0024 */ 	lh	$t3,0x24($v0)
/*  f0b0b60:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f0b0b64:	a44c0024 */ 	sh	$t4,0x24($v0)
.L0f0b0b68:
/*  f0b0b68:	8d0e006c */ 	lw	$t6,0x6c($t0)
.L0f0b0b6c:
/*  f0b0b6c:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f0b0b70:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b0b74:	11c00003 */ 	beqz	$t6,.L0f0b0b84
/*  f0b0b78:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b0b7c:	10000001 */ 	beqz	$zero,.L0f0b0b84
/*  f0b0b80:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b0b84:
/*  f0b0b84:	8d0d0068 */ 	lw	$t5,0x68($t0)
/*  f0b0b88:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b0b8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b0b90:	11a00003 */ 	beqz	$t5,.L0f0b0ba0
/*  f0b0b94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0b98:	10000001 */ 	beqz	$zero,.L0f0b0ba0
/*  f0b0b9c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b0ba0:
/*  f0b0ba0:	8d0f0064 */ 	lw	$t7,0x64($t0)
/*  f0b0ba4:	11e00003 */ 	beqz	$t7,.L0f0b0bb4
/*  f0b0ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0bac:	10000001 */ 	beqz	$zero,.L0f0b0bb4
/*  f0b0bb0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b0bb4:
/*  f0b0bb4:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0b0bb8:	13000003 */ 	beqz	$t8,.L0f0b0bc8
/*  f0b0bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0bc0:	10000001 */ 	beqz	$zero,.L0f0b0bc8
/*  f0b0bc4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b0bc8:
/*  f0b0bc8:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0b0bcc:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0b0bd0:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0b0bd4:	032b082a */ 	slt	$at,$t9,$t3
/*  f0b0bd8:	1020000b */ 	beqz	$at,.L0f0b0c08
/*  f0b0bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0be0:	8d0c028c */ 	lw	$t4,0x28c($t0)
/*  f0b0be4:	03202025 */ 	or	$a0,$t9,$zero
/*  f0b0be8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0bec:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0b0bf0:	0fc2c206 */ 	jal	func0f0b0818
/*  f0b0bf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0bf8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0bfc:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f0b0c00:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0c04:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0b0c08:
/*  f0b0c08:	100000b8 */ 	beqz	$zero,.L0f0b0eec
/*  f0b0c0c:	8d060318 */ 	lw	$a2,0x318($t0)
.L0f0b0c10:
/*  f0b0c10:	8fae0154 */ 	lw	$t6,0x154($sp)
.L0f0b0c14:
/*  f0b0c14:	05c20044 */ 	bltzl	$t6,.L0f0b0d28
/*  f0b0c18:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f0b0c1c:	10600004 */ 	beqz	$v1,.L0f0b0c30
/*  f0b0c20:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b0c24:	846d003c */ 	lh	$t5,0x3c($v1)
/*  f0b0c28:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f0b0c2c:	a46f003c */ 	sh	$t7,0x3c($v1)
.L0f0b0c30:
/*  f0b0c30:	8d18006c */ 	lw	$t8,0x6c($t0)
/*  f0b0c34:	8fac0154 */ 	lw	$t4,0x154($sp)
/*  f0b0c38:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b0c3c:	13000003 */ 	beqz	$t8,.L0f0b0c4c
/*  f0b0c40:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b0c44:	10000001 */ 	beqz	$zero,.L0f0b0c4c
/*  f0b0c48:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b0c4c:
/*  f0b0c4c:	8d090068 */ 	lw	$t1,0x68($t0)
/*  f0b0c50:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b0c54:	11200003 */ 	beqz	$t1,.L0f0b0c64
/*  f0b0c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0c5c:	10000001 */ 	beqz	$zero,.L0f0b0c64
/*  f0b0c60:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b0c64:
/*  f0b0c64:	8d0a0064 */ 	lw	$t2,0x64($t0)
/*  f0b0c68:	11400003 */ 	beqz	$t2,.L0f0b0c78
/*  f0b0c6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0c70:	10000001 */ 	beqz	$zero,.L0f0b0c78
/*  f0b0c74:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b0c78:
/*  f0b0c78:	8d0b0070 */ 	lw	$t3,0x70($t0)
/*  f0b0c7c:	11600003 */ 	beqz	$t3,.L0f0b0c8c
/*  f0b0c80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0c84:	10000001 */ 	beqz	$zero,.L0f0b0c8c
/*  f0b0c88:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b0c8c:
/*  f0b0c8c:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0b0c90:	03247021 */ 	addu	$t6,$t9,$a0
/*  f0b0c94:	01c56821 */ 	addu	$t5,$t6,$a1
/*  f0b0c98:	018d082a */ 	slt	$at,$t4,$t5
/*  f0b0c9c:	50200022 */ 	beqzl	$at,.L0f0b0d28
/*  f0b0ca0:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f0b0ca4:	8d0f028c */ 	lw	$t7,0x28c($t0)
/*  f0b0ca8:	01802025 */ 	or	$a0,$t4,$zero
/*  f0b0cac:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0cb0:	afaf013c */ 	sw	$t7,0x13c($sp)
/*  f0b0cb4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x318)
/*  f0b0cb8:	8f18a2d8 */ 	lw	$t8,%lo(g_Vars+0x318)($t8)
/*  f0b0cbc:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0b0cc0:	13000012 */ 	beqz	$t8,.L0f0b0d0c
/*  f0b0cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0cc8:	05200010 */ 	bltz	$t1,.L0f0b0d0c
/*  f0b0ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0cd0:	0fc5b9f1 */ 	jal	langGet
/*  f0b0cd4:	240458b7 */ 	addiu	$a0,$zero,0x58b7
/*  f0b0cd8:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0b0cdc:	3c07800b */ 	lui	$a3,%hi(var800ac500)
/*  f0b0ce0:	3c057f1b */ 	lui	$a1,%hi(var7f1acdbc)
/*  f0b0ce4:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0b0ce8:	00eb3821 */ 	addu	$a3,$a3,$t3
/*  f0b0cec:	8ce7c500 */ 	lw	$a3,%lo(var800ac500)($a3)
/*  f0b0cf0:	24a5cdbc */ 	addiu	$a1,$a1,%lo(var7f1acdbc)
/*  f0b0cf4:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f0b0cf8:	0c004dad */ 	jal	sprintf
/*  f0b0cfc:	00403025 */ 	or	$a2,$v0,$zero
/*  f0b0d00:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f0b0d04:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f0b0d08:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b0d0c:
/*  f0b0d0c:	0fc2c1d9 */ 	jal	func0f0b0764
/*  f0b0d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0d14:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0d18:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f0b0d1c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0d20:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b0d24:	8fb90140 */ 	lw	$t9,0x140($sp)
.L0f0b0d28:
/*  f0b0d28:	8fae014c */ 	lw	$t6,0x14c($sp)
/*  f0b0d2c:	53200008 */ 	beqzl	$t9,.L0f0b0d50
/*  f0b0d30:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0b0d34:	05c00005 */ 	bltz	$t6,.L0f0b0d4c
/*  f0b0d38:	000e6840 */ 	sll	$t5,$t6,0x1
/*  f0b0d3c:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f0b0d40:	844f0024 */ 	lh	$t7,0x24($v0)
/*  f0b0d44:	25ec0001 */ 	addiu	$t4,$t7,0x1
/*  f0b0d48:	a44c0024 */ 	sh	$t4,0x24($v0)
.L0f0b0d4c:
/*  f0b0d4c:	8fb80150 */ 	lw	$t8,0x150($sp)
.L0f0b0d50:
/*  f0b0d50:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0b0d54:	0702003d */ 	bltzl	$t8,.L0f0b0e4c
/*  f0b0d58:	8d060318 */ 	lw	$a2,0x318($t0)
/*  f0b0d5c:	8d09006c */ 	lw	$t1,0x6c($t0)
/*  f0b0d60:	8d020068 */ 	lw	$v0,0x68($t0)
/*  f0b0d64:	8d030064 */ 	lw	$v1,0x64($t0)
/*  f0b0d68:	11200003 */ 	beqz	$t1,.L0f0b0d78
/*  f0b0d6c:	8d070070 */ 	lw	$a3,0x70($t0)
/*  f0b0d70:	10000002 */ 	beqz	$zero,.L0f0b0d7c
/*  f0b0d74:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b0d78:
/*  f0b0d78:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b0d7c:
/*  f0b0d7c:	10400003 */ 	beqz	$v0,.L0f0b0d8c
/*  f0b0d80:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b0d84:	10000001 */ 	beqz	$zero,.L0f0b0d8c
/*  f0b0d88:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b0d8c:
/*  f0b0d8c:	10600003 */ 	beqz	$v1,.L0f0b0d9c
/*  f0b0d90:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b0d94:	10000002 */ 	beqz	$zero,.L0f0b0da0
/*  f0b0d98:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b0d9c:
/*  f0b0d9c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0b0da0:
/*  f0b0da0:	10e00003 */ 	beqz	$a3,.L0f0b0db0
/*  f0b0da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0da8:	10000001 */ 	beqz	$zero,.L0f0b0db0
/*  f0b0dac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b0db0:
/*  f0b0db0:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0b0db4:	01647021 */ 	addu	$t6,$t3,$a0
/*  f0b0db8:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f0b0dbc:	0159082a */ 	slt	$at,$t2,$t9
/*  f0b0dc0:	50200022 */ 	beqzl	$at,.L0f0b0e4c
/*  f0b0dc4:	8d060318 */ 	lw	$a2,0x318($t0)
/*  f0b0dc8:	8d0d028c */ 	lw	$t5,0x28c($t0)
/*  f0b0dcc:	01402025 */ 	or	$a0,$t2,$zero
/*  f0b0dd0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0dd4:	afad013c */ 	sw	$t5,0x13c($sp)
/*  f0b0dd8:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x318)
/*  f0b0ddc:	8defa2d8 */ 	lw	$t7,%lo(g_Vars+0x318)($t7)
/*  f0b0de0:	8fac0154 */ 	lw	$t4,0x154($sp)
/*  f0b0de4:	11e00012 */ 	beqz	$t7,.L0f0b0e30
/*  f0b0de8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0dec:	05800010 */ 	bltz	$t4,.L0f0b0e30
/*  f0b0df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0df4:	0fc5b9f1 */ 	jal	langGet
/*  f0b0df8:	240458b8 */ 	addiu	$a0,$zero,0x58b8
/*  f0b0dfc:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f0b0e00:	3c07800b */ 	lui	$a3,%hi(var800ac500)
/*  f0b0e04:	3c057f1b */ 	lui	$a1,%hi(var7f1acdc4)
/*  f0b0e08:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0b0e0c:	00e93821 */ 	addu	$a3,$a3,$t1
/*  f0b0e10:	8ce7c500 */ 	lw	$a3,%lo(var800ac500)($a3)
/*  f0b0e14:	24a5cdc4 */ 	addiu	$a1,$a1,%lo(var7f1acdc4)
/*  f0b0e18:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f0b0e1c:	0c004dad */ 	jal	sprintf
/*  f0b0e20:	00403025 */ 	or	$a2,$v0,$zero
/*  f0b0e24:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f0b0e28:	0fc377c7 */ 	jal	currentPlayerQueueMessage
/*  f0b0e2c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b0e30:
/*  f0b0e30:	0fc2c169 */ 	jal	func0f0b05a4
/*  f0b0e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0e38:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0b0e3c:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f0b0e40:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0e44:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b0e48:	8d060318 */ 	lw	$a2,0x318($t0)
.L0f0b0e4c:
/*  f0b0e4c:	8fab0150 */ 	lw	$t3,0x150($sp)
/*  f0b0e50:	10c00026 */ 	beqz	$a2,.L0f0b0eec
/*  f0b0e54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0e58:	05600024 */ 	bltz	$t3,.L0f0b0eec
/*  f0b0e5c:	8fb90154 */ 	lw	$t9,0x154($sp)
/*  f0b0e60:	8d0e006c */ 	lw	$t6,0x6c($t0)
/*  f0b0e64:	8d020068 */ 	lw	$v0,0x68($t0)
/*  f0b0e68:	8d030064 */ 	lw	$v1,0x64($t0)
/*  f0b0e6c:	11c00003 */ 	beqz	$t6,.L0f0b0e7c
/*  f0b0e70:	8d070070 */ 	lw	$a3,0x70($t0)
/*  f0b0e74:	10000002 */ 	beqz	$zero,.L0f0b0e80
/*  f0b0e78:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b0e7c:
/*  f0b0e7c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b0e80:
/*  f0b0e80:	10400003 */ 	beqz	$v0,.L0f0b0e90
/*  f0b0e84:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b0e88:	10000001 */ 	beqz	$zero,.L0f0b0e90
/*  f0b0e8c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b0e90:
/*  f0b0e90:	10600003 */ 	beqz	$v1,.L0f0b0ea0
/*  f0b0e94:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b0e98:	10000002 */ 	beqz	$zero,.L0f0b0ea4
/*  f0b0e9c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b0ea0:
/*  f0b0ea0:	00001825 */ 	or	$v1,$zero,$zero
.L0f0b0ea4:
/*  f0b0ea4:	10e00003 */ 	beqz	$a3,.L0f0b0eb4
/*  f0b0ea8:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0b0eac:	10000001 */ 	beqz	$zero,.L0f0b0eb4
/*  f0b0eb0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b0eb4:
/*  f0b0eb4:	00436821 */ 	addu	$t5,$v0,$v1
/*  f0b0eb8:	01a45021 */ 	addu	$t2,$t5,$a0
/*  f0b0ebc:	01457821 */ 	addu	$t7,$t2,$a1
/*  f0b0ec0:	032f082a */ 	slt	$at,$t9,$t7
/*  f0b0ec4:	14200009 */ 	bnez	$at,.L0f0b0eec
/*  f0b0ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0ecc:	11990007 */ 	beq	$t4,$t9,.L0f0b0eec
/*  f0b0ed0:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0b0ed4:	3c09800b */ 	lui	$t1,%hi(g_MpPlayerChrs)
/*  f0b0ed8:	01384821 */ 	addu	$t1,$t1,$t8
/*  f0b0edc:	8d29c4d0 */ 	lw	$t1,%lo(g_MpPlayerChrs)($t1)
/*  f0b0ee0:	8d2b02d4 */ 	lw	$t3,0x2d4($t1)
/*  f0b0ee4:	a56c0076 */ 	sh	$t4,0x76($t3)
/*  f0b0ee8:	8d060318 */ 	lw	$a2,0x318($t0)
.L0f0b0eec:
/*  f0b0eec:	10c00030 */ 	beqz	$a2,.L0f0b0fb0
/*  f0b0ef0:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0b0ef4:	05c0002e */ 	bltz	$t6,.L0f0b0fb0
/*  f0b0ef8:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0b0efc:	3c0a800b */ 	lui	$t2,%hi(g_MpPlayerChrs)
/*  f0b0f00:	254ac4d0 */ 	addiu	$t2,$t2,%lo(g_MpPlayerChrs)
/*  f0b0f04:	01aa2821 */ 	addu	$a1,$t5,$t2
/*  f0b0f08:	8caf0000 */ 	lw	$t7,0($a1)
/*  f0b0f0c:	8de302d4 */ 	lw	$v1,0x2d4($t7)
/*  f0b0f10:	10600027 */ 	beqz	$v1,.L0f0b0fb0
/*  f0b0f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b0f18:	8c640020 */ 	lw	$a0,0x20($v1)
/*  f0b0f1c:	0fc660b5 */ 	jal	func0f1982d4
/*  f0b0f20:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0b0f24:	04400022 */ 	bltz	$v0,.L0f0b0fb0
/*  f0b0f28:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0b0f2c:	8fb90150 */ 	lw	$t9,0x150($sp)
/*  f0b0f30:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f0b0f34:	57380011 */ 	bnel	$t9,$t8,.L0f0b0f7c
/*  f0b0f38:	8cb90000 */ 	lw	$t9,0($a1)
/*  f0b0f3c:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f0b0f40:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f0b0f44:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b0f48:	8d2302d4 */ 	lw	$v1,0x2d4($t1)
/*  f0b0f4c:	44813000 */ 	mtc1	$at,$f6
/*  f0b0f50:	8c6e004c */ 	lw	$t6,0x4c($v1)
/*  f0b0f54:	006c5821 */ 	addu	$t3,$v1,$t4
/*  f0b0f58:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0b0f5c:	000d57c2 */ 	srl	$t2,$t5,0x1f
/*  f0b0f60:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f0b0f64:	016f2021 */ 	addu	$a0,$t3,$t7
/*  f0b0f68:	c4840244 */ 	lwc1	$f4,0x244($a0)
/*  f0b0f6c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b0f70:	1000000f */ 	beqz	$zero,.L0f0b0fb0
/*  f0b0f74:	e4880244 */ 	swc1	$f8,0x244($a0)
/*  f0b0f78:	8cb90000 */ 	lw	$t9,0x0($a1)
.L0f0b0f7c:
/*  f0b0f7c:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f0b0f80:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b0f84:	8f2302d4 */ 	lw	$v1,0x2d4($t9)
/*  f0b0f88:	44818000 */ 	mtc1	$at,$f16
/*  f0b0f8c:	8c6c004c */ 	lw	$t4,0x4c($v1)
/*  f0b0f90:	00784821 */ 	addu	$t1,$v1,$t8
/*  f0b0f94:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f0b0f98:	000e6fc2 */ 	srl	$t5,$t6,0x1f
/*  f0b0f9c:	000d5080 */ 	sll	$t2,$t5,0x2
/*  f0b0fa0:	012a2021 */ 	addu	$a0,$t1,$t2
/*  f0b0fa4:	c48a0214 */ 	lwc1	$f10,0x214($a0)
/*  f0b0fa8:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0b0fac:	e4920214 */ 	swc1	$f18,0x214($a0)
.L0f0b0fb0:
/*  f0b0fb0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0b0fb4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0b0fb8:	8d0b0488 */ 	lw	$t3,0x488($t0)
/*  f0b0fbc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b0fc0:	27bd0150 */ 	addiu	$sp,$sp,0x150
/*  f0b0fc4:	256f0001 */ 	addiu	$t7,$t3,0x1
/*  f0b0fc8:	03e00008 */ 	jr	$ra
/*  f0b0fcc:	ad0f0488 */ 	sw	$t7,0x488($t0)
);

struct weapon *weaponFindById(s32 itemid)
{
	if (itemid < 0) {
		return NULL;
	}

	if (itemid >= NUM_WEAPONS) {
		return NULL;
	}

	return g_Weapons[itemid];
}

GLOBAL_ASM(
glabel weaponGetFunctionById
/*  f0b1004:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1008:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b100c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1010:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1014:	10400006 */ 	beqz	$v0,.L0f0b1030
/*  f0b1018:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b101c:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0b1020:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b1024:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0b1028:	10000002 */ 	beqz	$zero,.L0f0b1034
/*  f0b102c:	8f020014 */ 	lw	$v0,0x14($t8)
.L0f0b1030:
/*  f0b1030:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1034:
/*  f0b1034:	03e00008 */ 	jr	$ra
/*  f0b1038:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b103c
/*  f0b103c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1040:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1044:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0b1048:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b104c:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f0b1050:	10400007 */ 	beqz	$v0,.L0f0b1070
/*  f0b1054:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1058:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f0b105c:	91f80003 */ 	lbu	$t8,0x3($t7)
/*  f0b1060:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b1064:	00594021 */ 	addu	$t0,$v0,$t9
/*  f0b1068:	10000002 */ 	beqz	$zero,.L0f0b1074
/*  f0b106c:	8d020014 */ 	lw	$v0,0x14($t0)
.L0f0b1070:
/*  f0b1070:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1074:
/*  f0b1074:	03e00008 */ 	jr	$ra
/*  f0b1078:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b107c
/*  f0b107c:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b1080:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b1084:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1088:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b108c:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b1090:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b1094:	10600006 */ 	beqz	$v1,.L0f0b10b0
/*  f0b1098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b109c:	90980003 */ 	lbu	$t8,0x3($a0)
/*  f0b10a0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b10a4:	00794021 */ 	addu	$t0,$v1,$t9
/*  f0b10a8:	03e00008 */ 	jr	$ra
/*  f0b10ac:	8d020014 */ 	lw	$v0,0x14($t0)
.L0f0b10b0:
/*  f0b10b0:	03e00008 */ 	jr	$ra
/*  f0b10b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel weaponGetFunction
/*  f0b10b8:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b10bc:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b10c0:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f0b10c4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b10c8:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b10cc:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b10d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b10d4:	10600003 */ 	beqz	$v1,.L0f0b10e4
/*  f0b10d8:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f0b10dc:	03e00008 */ 	jr	$ra
/*  f0b10e0:	8f220014 */ 	lw	$v0,0x14($t9)
.L0f0b10e4:
/*  f0b10e4:	03e00008 */ 	jr	$ra
/*  f0b10e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b10ec
/*  f0b10ec:	00041900 */ 	sll	$v1,$a0,0x4
/*  f0b10f0:	00641823 */ 	subu	$v1,$v1,$a0
/*  f0b10f4:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0b10f8:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0b10fc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b1100:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b1104:	000318c0 */ 	sll	$v1,$v1,0x3
/*  f0b1108:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0b110c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1110:	00031880 */ 	sll	$v1,$v1,0x2
/*  f0b1114:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1118:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0b111c:	91e40638 */ 	lbu	$a0,0x638($t7)
/*  f0b1120:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1124:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0b1128:	10400009 */ 	beqz	$v0,.L0f0b1150
/*  f0b112c:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0b1130:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0b1134:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0b1138:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0b113c:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0b1140:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0b1144:	00495021 */ 	addu	$t2,$v0,$t1
/*  f0b1148:	10000002 */ 	beqz	$zero,.L0f0b1154
/*  f0b114c:	8d420014 */ 	lw	$v0,0x14($t2)
.L0f0b1150:
/*  f0b1150:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1154:
/*  f0b1154:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1158:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b115c:	03e00008 */ 	jr	$ra
/*  f0b1160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1164:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1168:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b116c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1174:	14400003 */ 	bnez	$v0,.L0f0b1184
/*  f0b1178:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b117c:	1000000d */ 	beqz	$zero,.L0f0b11b4
/*  f0b1180:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1184:
/*  f0b1184:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b1188:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b118c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0b1190:
/*  f0b1190:	8c8e0014 */ 	lw	$t6,0x14($a0)
/*  f0b1194:	55c00004 */ 	bnezl	$t6,.L0f0b11a8
/*  f0b1198:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0b119c:	10000005 */ 	beqz	$zero,.L0f0b11b4
/*  f0b11a0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0b11a4:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0b11a8:
/*  f0b11a8:	1465fff9 */ 	bne	$v1,$a1,.L0f0b1190
/*  f0b11ac:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0b11b0:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f0b11b4:
/*  f0b11b4:	03e00008 */ 	jr	$ra
/*  f0b11b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b11bc
/*  f0b11bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b11c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b11c4:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b11c8:	90840000 */ 	lbu	$a0,0x0($a0)
/*  f0b11cc:	10400003 */ 	beqz	$v0,.L0f0b11dc
/*  f0b11d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b11d4:	10000003 */ 	beqz	$zero,.L0f0b11e4
/*  f0b11d8:	8c420024 */ 	lw	$v0,0x24($v0)
.L0f0b11dc:
/*  f0b11dc:	3c028007 */ 	lui	$v0,%hi(inve_000110c0)
/*  f0b11e0:	2442b0a0 */ 	addiu	$v0,$v0,%lo(inve_000110c0)
.L0f0b11e4:
/*  f0b11e4:	03e00008 */ 	jr	$ra
/*  f0b11e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b11ec
/*  f0b11ec:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b11f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b11f4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b11f8:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b11fc:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0b1200:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0b1204:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0b1208:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0b120c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0b1210:	1040000b */ 	beqz	$v0,.L0f0b1240
/*  f0b1214:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b1218:	5060000a */ 	beqzl	$v1,.L0f0b1244
/*  f0b121c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1220:	804e0007 */ 	lb	$t6,0x7($v0)
/*  f0b1224:	05c20007 */ 	bltzl	$t6,.L0f0b1244
/*  f0b1228:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b122c:	804f0007 */ 	lb	$t7,0x7($v0)
/*  f0b1230:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0b1234:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f0b1238:	10000002 */ 	beqz	$zero,.L0f0b1244
/*  f0b123c:	8f22001c */ 	lw	$v0,0x1c($t9)
.L0f0b1240:
/*  f0b1240:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1244:
/*  f0b1244:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1248:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b124c:	03e00008 */ 	jr	$ra
/*  f0b1250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1254:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1258:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b125c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0b1260:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0b1264:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1268:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b126c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b1270:	10400007 */ 	beqz	$v0,.L0f0b1290
/*  f0b1274:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0b1278:	c444002c */ 	lwc1	$f4,0x2c($v0)
/*  f0b127c:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f0b1280:	c4460030 */ 	lwc1	$f6,0x30($v0)
/*  f0b1284:	e4660004 */ 	swc1	$f6,0x4($v1)
/*  f0b1288:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f0b128c:	e4680008 */ 	swc1	$f8,0x8($v1)
.L0f0b1290:
/*  f0b1290:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1294:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1298:	03e00008 */ 	jr	$ra
/*  f0b129c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b12a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b12a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b12a8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0b12ac:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0b12b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b12b4:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b12b8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b12bc:	10400007 */ 	beqz	$v0,.L0f0b12dc
/*  f0b12c0:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0b12c4:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0b12c8:	e444002c */ 	swc1	$f4,0x2c($v0)
/*  f0b12cc:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f0b12d0:	e4460030 */ 	swc1	$f6,0x30($v0)
/*  f0b12d4:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f0b12d8:	e4480034 */ 	swc1	$f8,0x34($v0)
.L0f0b12dc:
/*  f0b12dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b12e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b12e4:	03e00008 */ 	jr	$ra
/*  f0b12e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b12ec
/*  f0b12ec:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0b12f0:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0b12f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b12f8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0b12fc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b1300:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b1304:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0b1308:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0b130c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b1310:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b1314:	03e00008 */ 	jr	$ra
/*  f0b1318:	c70007f4 */ 	lwc1	$f0,0x7f4($t8)
);

GLOBAL_ASM(
glabel func0f0b131c
/*  f0b131c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1320:	14800034 */ 	bnez	$a0,.L0f0b13f4
/*  f0b1324:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1328:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b132c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1330:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1334:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b1338:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0b133c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0b1340:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f0b1344:	c442002c */ 	lwc1	$f2,0x2c($v0)
/*  f0b1348:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b134c:	11c00003 */ 	beqz	$t6,.L0f0b135c
/*  f0b1350:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b1354:	10000001 */ 	beqz	$zero,.L0f0b135c
/*  f0b1358:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b135c:
/*  f0b135c:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f0b1360:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1364:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b1368:	11e00003 */ 	beqz	$t7,.L0f0b1378
/*  f0b136c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1370:	10000001 */ 	beqz	$zero,.L0f0b1378
/*  f0b1374:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b1378:
/*  f0b1378:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f0b137c:	13000003 */ 	beqz	$t8,.L0f0b138c
/*  f0b1380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1384:	10000001 */ 	beqz	$zero,.L0f0b138c
/*  f0b1388:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b138c:
/*  f0b138c:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f0b1390:	13200003 */ 	beqz	$t9,.L0f0b13a0
/*  f0b1394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1398:	10000001 */ 	beqz	$zero,.L0f0b13a0
/*  f0b139c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b13a0:
/*  f0b13a0:	00434021 */ 	addu	$t0,$v0,$v1
/*  f0b13a4:	01044821 */ 	addu	$t1,$t0,$a0
/*  f0b13a8:	01265021 */ 	addu	$t2,$t1,$a2
/*  f0b13ac:	55410046 */ 	bnel	$t2,$at,.L0f0b14c8
/*  f0b13b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b13b4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0b13b8:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0b13bc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0b13c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b13c4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0b13c8:	1441003e */ 	bne	$v0,$at,.L0f0b14c4
/*  f0b13cc:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f0b13d0:	8cab028c */ 	lw	$t3,0x28c($a1)
/*  f0b13d4:	3c014060 */ 	lui	$at,0x4060
/*  f0b13d8:	44812000 */ 	mtc1	$at,$f4
/*  f0b13dc:	3c014000 */ 	lui	$at,0x4000
/*  f0b13e0:	15600038 */ 	bnez	$t3,.L0f0b14c4
/*  f0b13e4:	46041081 */ 	sub.s	$f2,$f2,$f4
/*  f0b13e8:	44813000 */ 	mtc1	$at,$f6
/*  f0b13ec:	10000035 */ 	beqz	$zero,.L0f0b14c4
/*  f0b13f0:	46061080 */ 	add.s	$f2,$f2,$f6
.L0f0b13f4:
/*  f0b13f4:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b13f8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b13fc:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1400:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b1404:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0b1408:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0b140c:	8cac006c */ 	lw	$t4,0x6c($a1)
/*  f0b1410:	c442002c */ 	lwc1	$f2,0x2c($v0)
/*  f0b1414:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b1418:	11800003 */ 	beqz	$t4,.L0f0b1428
/*  f0b141c:	46001087 */ 	neg.s	$f2,$f2
/*  f0b1420:	10000002 */ 	beqz	$zero,.L0f0b142c
/*  f0b1424:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b1428:
/*  f0b1428:	00003025 */ 	or	$a2,$zero,$zero
.L0f0b142c:
/*  f0b142c:	8cad0068 */ 	lw	$t5,0x68($a1)
/*  f0b1430:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1434:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b1438:	11a00003 */ 	beqz	$t5,.L0f0b1448
/*  f0b143c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1440:	10000001 */ 	beqz	$zero,.L0f0b1448
/*  f0b1444:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b1448:
/*  f0b1448:	8cae0064 */ 	lw	$t6,0x64($a1)
/*  f0b144c:	11c00003 */ 	beqz	$t6,.L0f0b145c
/*  f0b1450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1454:	10000001 */ 	beqz	$zero,.L0f0b145c
/*  f0b1458:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0b145c:
/*  f0b145c:	8caf0070 */ 	lw	$t7,0x70($a1)
/*  f0b1460:	11e00003 */ 	beqz	$t7,.L0f0b1470
/*  f0b1464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1468:	10000001 */ 	beqz	$zero,.L0f0b1470
/*  f0b146c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b1470:
/*  f0b1470:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0b1474:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0b1478:	03264021 */ 	addu	$t0,$t9,$a2
/*  f0b147c:	55010012 */ 	bnel	$t0,$at,.L0f0b14c8
/*  f0b1480:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1484:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0b1488:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0b148c:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0b1490:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1494:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0b1498:	1441000a */ 	bne	$v0,$at,.L0f0b14c4
/*  f0b149c:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f0b14a0:	8ca9028c */ 	lw	$t1,0x28c($a1)
/*  f0b14a4:	3c014060 */ 	lui	$at,0x4060
/*  f0b14a8:	44814000 */ 	mtc1	$at,$f8
/*  f0b14ac:	3c014000 */ 	lui	$at,0x4000
/*  f0b14b0:	15200004 */ 	bnez	$t1,.L0f0b14c4
/*  f0b14b4:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f0b14b8:	44815000 */ 	mtc1	$at,$f10
/*  f0b14bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b14c0:	460a1080 */ 	add.s	$f2,$f2,$f10
.L0f0b14c4:
/*  f0b14c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b14c8:
/*  f0b14c8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b14cc:	46001006 */ 	mov.s	$f0,$f2
/*  f0b14d0:	03e00008 */ 	jr	$ra
/*  f0b14d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b14d8
/*  f0b14d8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b14dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b14e0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0b14e4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0b14e8:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b14ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b14f0:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0b14f4:	10410008 */ 	beq	$v0,$at,.L0f0b1518
/*  f0b14f8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b14fc:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0b1500:	10410007 */ 	beq	$v0,$at,.L0f0b1520
/*  f0b1504:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0b1508:	50410008 */ 	beql	$v0,$at,.L0f0b152c
/*  f0b150c:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0b1510:	10000006 */ 	beqz	$zero,.L0f0b152c
/*  f0b1514:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b1518:
/*  f0b1518:	10000004 */ 	beqz	$zero,.L0f0b152c
/*  f0b151c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0b1520:
/*  f0b1520:	10000002 */ 	beqz	$zero,.L0f0b152c
/*  f0b1524:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0b1528:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f0b152c:
/*  f0b152c:	04600006 */ 	bltz	$v1,.L0f0b1548
/*  f0b1530:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0b1534:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0b1538:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0b153c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0b1540:	1000000d */ 	beqz	$zero,.L0f0b1578
/*  f0b1544:	c70016f4 */ 	lwc1	$f0,0x16f4($t8)
.L0f0b1548:
/*  f0b1548:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b154c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1550:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1554:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b1558:	50400006 */ 	beqzl	$v0,.L0f0b1574
/*  f0b155c:	44800000 */ 	mtc1	$zero,$f0
/*  f0b1560:	8c590024 */ 	lw	$t9,0x24($v0)
/*  f0b1564:	c7220000 */ 	lwc1	$f2,0x0($t9)
/*  f0b1568:	10000003 */ 	beqz	$zero,.L0f0b1578
/*  f0b156c:	46001006 */ 	mov.s	$f0,$f2
/*  f0b1570:	44800000 */ 	mtc1	$zero,$f0
.L0f0b1574:
/*  f0b1574:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b1578:
/*  f0b1578:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b157c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b1580:	03e00008 */ 	jr	$ra
/*  f0b1584:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1588
/*  f0b1588:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b158c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1590:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0b1594:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f0b1598:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b159c:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b15a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b15a4:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0b15a8:	10410008 */ 	beq	$v0,$at,.L0f0b15cc
/*  f0b15ac:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0b15b0:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0b15b4:	10410007 */ 	beq	$v0,$at,.L0f0b15d4
/*  f0b15b8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0b15bc:	50410008 */ 	beql	$v0,$at,.L0f0b15e0
/*  f0b15c0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0b15c4:	10000006 */ 	beqz	$zero,.L0f0b15e0
/*  f0b15c8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b15cc:
/*  f0b15cc:	10000004 */ 	beqz	$zero,.L0f0b15e0
/*  f0b15d0:	00002825 */ 	or	$a1,$zero,$zero
.L0f0b15d4:
/*  f0b15d4:	10000002 */ 	beqz	$zero,.L0f0b15e0
/*  f0b15d8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0b15dc:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0b15e0:
/*  f0b15e0:	04a0002c */ 	bltz	$a1,.L0f0b1694
/*  f0b15e4:	c7a40020 */ 	lwc1	$f4,0x20($sp)
/*  f0b15e8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0b15ec:	44813000 */ 	mtc1	$at,$f6
/*  f0b15f0:	3c01800a */ 	lui	$at,0x800a
/*  f0b15f4:	c42aa004 */ 	lwc1	$f10,-0x5ffc($at)
/*  f0b15f8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b15fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1600:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1604:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0b1608:	0fc2867c */ 	jal	getCurrentPlayerWeaponIdWrapper
/*  f0b160c:	e7a00018 */ 	swc1	$f0,0x18($sp)
/*  f0b1610:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0b1614:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0b1618:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0b161c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0b1620:	14410006 */ 	bne	$v0,$at,.L0f0b163c
/*  f0b1624:	c7a00018 */ 	lwc1	$f0,0x18($sp)
/*  f0b1628:	3c013f00 */ 	lui	$at,0x3f00
/*  f0b162c:	44818000 */ 	mtc1	$at,$f16
/*  f0b1630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1634:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f0b1638:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b163c:
/*  f0b163c:	3c014270 */ 	lui	$at,0x4270
/*  f0b1640:	44811000 */ 	mtc1	$at,$f2
/*  f0b1644:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b1648:	44819000 */ 	mtc1	$at,$f18
/*  f0b164c:	3c017f1b */ 	lui	$at,%hi(var7f1acdd0)
/*  f0b1650:	c424cdd0 */ 	lwc1	$f4,%lo(var7f1acdd0)($at)
/*  f0b1654:	8c8e0284 */ 	lw	$t6,0x284($a0)
/*  f0b1658:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0b165c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0b1660:	01c21821 */ 	addu	$v1,$t6,$v0
/*  f0b1664:	c46a16f4 */ 	lwc1	$f10,0x16f4($v1)
/*  f0b1668:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0b166c:	46085402 */ 	mul.s	$f16,$f10,$f8
/*  f0b1670:	e47016f4 */ 	swc1	$f16,0x16f4($v1)
/*  f0b1674:	8c8f0284 */ 	lw	$t7,0x284($a0)
/*  f0b1678:	01e21821 */ 	addu	$v1,$t7,$v0
/*  f0b167c:	c46416f4 */ 	lwc1	$f4,0x16f4($v1)
/*  f0b1680:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0b1684:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1688:	45020003 */ 	bc1fl	.L0f0b1698
/*  f0b168c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1690:	e46216f4 */ 	swc1	$f2,0x16f4($v1)
.L0f0b1694:
/*  f0b1694:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0b1698:
/*  f0b1698:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b169c:	03e00008 */ 	jr	$ra
/*  f0b16a0:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerUpdateGunZoomFovs(f32 arg0)
{
	s32 index = -1;

	switch (getCurrentPlayerWeaponIdWrapper(0)) {
	case WEAPON_SNIPERRIFLE:    index = 0; break;
	case WEAPON_FARSIGHTXR20:   index = 1; break;
	case WEAPON_HORIZONSCANNER: index = 2; break;
	}

	if (index >= 0) {
		f32 value = arg0 * 0.25f * g_Vars.lvupdate240f;

		if (getCurrentPlayerWeaponIdWrapper(0) == WEAPON_FARSIGHTXR20) {
			value *= 0.5f;
		}

		g_Vars.currentplayer->gunzoomfovs[index] /= 1 + value * 0.1f;

		if (g_Vars.currentplayer->gunzoomfovs[index] < 2) {
			g_Vars.currentplayer->gunzoomfovs[index] = 2;
		}
	}
}

bool weaponHasFlag(s32 itemid, u32 flag)
{
	struct weapon *weapon = weaponFindById(itemid);

	if (!weapon) {
		return false;
	}

	return (weapon->flags & flag) != 0;
}

GLOBAL_ASM(
glabel func0f0b1804
/*  f0b1804:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1808:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b180c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1810:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1814:	14400003 */ 	bnez	$v0,.L0f0b1824
/*  f0b1818:	00401825 */ 	or	$v1,$v0,$zero
/*  f0b181c:	10000007 */ 	beqz	$zero,.L0f0b183c
/*  f0b1820:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1824:
/*  f0b1824:	8c6e0024 */ 	lw	$t6,0x24($v1)
/*  f0b1828:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f0b182c:	8dcf001c */ 	lw	$t7,0x1c($t6)
/*  f0b1830:	01f81024 */ 	and	$v0,$t7,$t8
/*  f0b1834:	0002c82b */ 	sltu	$t9,$zero,$v0
/*  f0b1838:	03201025 */ 	or	$v0,$t9,$zero
.L0f0b183c:
/*  f0b183c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1840:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1844:	03e00008 */ 	jr	$ra
/*  f0b1848:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b184c
/*  f0b184c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1850:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1854:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1858:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b185c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0b1860:	14400003 */ 	bnez	$v0,.L0f0b1870
/*  f0b1864:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1868:	1000000e */ 	beqz	$zero,.L0f0b18a4
/*  f0b186c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1870:
/*  f0b1870:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f0b1874:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f0b1878:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b187c:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0b1880:	8f03001c */ 	lw	$v1,0x1c($t8)
/*  f0b1884:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1888:	10600006 */ 	beqz	$v1,.L0f0b18a4
/*  f0b188c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1890:	90790010 */ 	lbu	$t9,0x10($v1)
/*  f0b1894:	03281024 */ 	and	$v0,$t9,$t0
/*  f0b1898:	0002482b */ 	sltu	$t1,$zero,$v0
/*  f0b189c:	10000001 */ 	beqz	$zero,.L0f0b18a4
/*  f0b18a0:	01201025 */ 	or	$v0,$t1,$zero
.L0f0b18a4:
/*  f0b18a4:	03e00008 */ 	jr	$ra
/*  f0b18a8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b18ac:	03e00008 */ 	jr	$ra
/*  f0b18b0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f0b18b4:	03e00008 */ 	jr	$ra
/*  f0b18b8:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel currentPlayerHasWeaponEquipped
/*  f0b18bc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b18c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b18c4:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b18c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b18cc:	14400003 */ 	bnez	$v0,.L0f0b18dc
/*  f0b18d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b18d4:	1000001a */ 	beqz	$zero,.L0f0b1940
/*  f0b18d8:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0b18dc:
/*  f0b18dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b18e0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b18e4:	24080008 */ 	addiu	$t0,$zero,0x8
/*  f0b18e8:	24070005 */ 	addiu	$a3,$zero,0x5
.L0f0b18ec:
/*  f0b18ec:	8c850014 */ 	lw	$a1,0x14($a0)
/*  f0b18f0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b18f4:	10a0000f */ 	beqz	$a1,.L0f0b1934
/*  f0b18f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b18fc:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0b1900:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1904:	14ef000b */ 	bne	$a3,$t7,.L0f0b1934
/*  f0b1908:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0b190c:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0b1910:	8ca90014 */ 	lw	$t1,0x14($a1)
/*  f0b1914:	8f1900c4 */ 	lw	$t9,0xc4($t8)
/*  f0b1918:	03295024 */ 	and	$t2,$t9,$t1
/*  f0b191c:	15400003 */ 	bnez	$t2,.L0f0b192c
/*  f0b1920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1924:	10000006 */ 	beqz	$zero,.L0f0b1940
/*  f0b1928:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b192c:
/*  f0b192c:	10000004 */ 	beqz	$zero,.L0f0b1940
/*  f0b1930:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b1934:
/*  f0b1934:	1468ffed */ 	bne	$v1,$t0,.L0f0b18ec
/*  f0b1938:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0b193c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0b1940:
/*  f0b1940:	03e00008 */ 	jr	$ra
/*  f0b1944:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b1948
/*  f0b1948:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b194c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1950:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1954:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1958:	1040002b */ 	beqz	$v0,.L0f0b1a08
/*  f0b195c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b1960:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b1964:	24080008 */ 	addiu	$t0,$zero,0x8
/*  f0b1968:	24070005 */ 	addiu	$a3,$zero,0x5
.L0f0b196c:
/*  f0b196c:	8c850014 */ 	lw	$a1,0x14($a0)
/*  f0b1970:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0b1974:	10a00022 */ 	beqz	$a1,.L0f0b1a00
/*  f0b1978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b197c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0b1980:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0b1984:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1988:	14ef001d */ 	bne	$a3,$t7,.L0f0b1a00
/*  f0b198c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1990:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f0b1994:	3c02800a */ 	lui	$v0,0x800a
/*  f0b1998:	13000012 */ 	beqz	$t8,.L0f0b19e4
/*  f0b199c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b19a0:	8ca30014 */ 	lw	$v1,0x14($a1)
/*  f0b19a4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b19a8:	3079000f */ 	andi	$t9,$v1,0xf
/*  f0b19ac:	13200007 */ 	beqz	$t9,.L0f0b19cc
/*  f0b19b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b19b4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b19b8:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f0b19bc:	8c4900c4 */ 	lw	$t1,0xc4($v0)
/*  f0b19c0:	01215024 */ 	and	$t2,$t1,$at
/*  f0b19c4:	ac4a00c4 */ 	sw	$t2,0xc4($v0)
/*  f0b19c8:	8ca30014 */ 	lw	$v1,0x14($a1)
.L0f0b19cc:
/*  f0b19cc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0b19d0:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0b19d4:	8c4b00c4 */ 	lw	$t3,0xc4($v0)
/*  f0b19d8:	01636025 */ 	or	$t4,$t3,$v1
/*  f0b19dc:	1000000a */ 	beqz	$zero,.L0f0b1a08
/*  f0b19e0:	ac4c00c4 */ 	sw	$t4,0xc4($v0)
.L0f0b19e4:
/*  f0b19e4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0b19e8:	8cce0014 */ 	lw	$t6,0x14($a2)
/*  f0b19ec:	8c4d00c4 */ 	lw	$t5,0xc4($v0)
/*  f0b19f0:	01c07827 */ 	nor	$t7,$t6,$zero
/*  f0b19f4:	01afc024 */ 	and	$t8,$t5,$t7
/*  f0b19f8:	10000003 */ 	beqz	$zero,.L0f0b1a08
/*  f0b19fc:	ac5800c4 */ 	sw	$t8,0xc4($v0)
.L0f0b1a00:
/*  f0b1a00:	1468ffda */ 	bne	$v1,$t0,.L0f0b196c
/*  f0b1a04:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0b1a08:
/*  f0b1a08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1a0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1a10:	03e00008 */ 	jr	$ra
/*  f0b1a14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1a18
/*  f0b1a18:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0b1a1c:	10810005 */ 	beq	$a0,$at,.L0f0b1a34
/*  f0b1a20:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b1a24:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0b1a28:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b1a2c:	006e1821 */ 	addu	$v1,$v1,$t6
/*  f0b1a30:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
.L0f0b1a34:
/*  f0b1a34:	10600024 */ 	beqz	$v1,.L0f0b1ac8
/*  f0b1a38:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1a3c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0b1a40:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0b1a44:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f0b1a48:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1a4c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1a50:	11e00003 */ 	beqz	$t7,.L0f0b1a60
/*  f0b1a54:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b1a58:	10000001 */ 	beqz	$zero,.L0f0b1a60
/*  f0b1a5c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0b1a60:
/*  f0b1a60:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f0b1a64:	13000003 */ 	beqz	$t8,.L0f0b1a74
/*  f0b1a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1a6c:	10000001 */ 	beqz	$zero,.L0f0b1a74
/*  f0b1a70:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b1a74:
/*  f0b1a74:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f0b1a78:	13200003 */ 	beqz	$t9,.L0f0b1a88
/*  f0b1a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1a80:	10000001 */ 	beqz	$zero,.L0f0b1a88
/*  f0b1a84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0b1a88:
/*  f0b1a88:	8cc80070 */ 	lw	$t0,0x70($a2)
/*  f0b1a8c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0b1a90:	11000003 */ 	beqz	$t0,.L0f0b1aa0
/*  f0b1a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1a98:	10000001 */ 	beqz	$zero,.L0f0b1aa0
/*  f0b1a9c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0b1aa0:
/*  f0b1aa0:	00c54821 */ 	addu	$t1,$a2,$a1
/*  f0b1aa4:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0b1aa8:	01425821 */ 	addu	$t3,$t2,$v0
/*  f0b1aac:	29610002 */ 	slti	$at,$t3,0x2
/*  f0b1ab0:	14200003 */ 	bnez	$at,.L0f0b1ac0
/*  f0b1ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1ab8:	03e00008 */ 	jr	$ra
/*  f0b1abc:	94620002 */ 	lhu	$v0,0x2($v1)
.L0f0b1ac0:
/*  f0b1ac0:	03e00008 */ 	jr	$ra
/*  f0b1ac4:	94620000 */ 	lhu	$v0,0x0($v1)
.L0f0b1ac8:
/*  f0b1ac8:	03e00008 */ 	jr	$ra
/*  f0b1acc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1ad0
/*  f0b1ad0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1ad4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1ad8:	0fc2c686 */ 	jal	func0f0b1a18
/*  f0b1adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1ae0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1ae4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1ae8:	03e00008 */ 	jr	$ra
/*  f0b1aec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1af0
/*  f0b1af0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0b1af4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0b1af8:	8cce0284 */ 	lw	$t6,0x284($a2)
/*  f0b1afc:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0b1b00:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0b1b04:	81cf1580 */ 	lb	$t7,0x1580($t6)
/*  f0b1b08:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0b1b0c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0b1b10:	a0af0000 */ 	sb	$t7,0x0($a1)
/*  f0b1b14:	8cd80284 */ 	lw	$t8,0x284($a2)
/*  f0b1b18:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0b1b1c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f0b1b20:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0b1b24:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0b1b28:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0b1b2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b1b30:	31e300ff */ 	andi	$v1,$t7,0xff
/*  f0b1b34:	a0a80003 */ 	sb	$t0,0x3($a1)
/*  f0b1b38:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0b1b3c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f0b1b40:	914b063a */ 	lbu	$t3,0x63a($t2)
/*  f0b1b44:	a0ab0002 */ 	sb	$t3,0x2($a1)
/*  f0b1b48:	8ccc0284 */ 	lw	$t4,0x284($a2)
/*  f0b1b4c:	01826821 */ 	addu	$t5,$t4,$v0
/*  f0b1b50:	91ae0639 */ 	lbu	$t6,0x639($t5)
/*  f0b1b54:	1461002a */ 	bne	$v1,$at,.L0f0b1c00
/*  f0b1b58:	a0ae0001 */ 	sb	$t6,0x1($a1)
/*  f0b1b5c:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f0b1b60:	3c014120 */ 	lui	$at,0x4120
/*  f0b1b64:	44813000 */ 	mtc1	$at,$f6
/*  f0b1b68:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f0b1b6c:	c7040874 */ 	lwc1	$f4,0x874($t8)
/*  f0b1b70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b1b74:	3c014f00 */ 	lui	$at,0x4f00
/*  f0b1b78:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b1b7c:	4459f800 */ 	cfc1	$t9,$31
/*  f0b1b80:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b1b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1b88:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0b1b8c:	4448f800 */ 	cfc1	$t0,$31
/*  f0b1b90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1b94:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0b1b98:	51000013 */ 	beqzl	$t0,.L0f0b1be8
/*  f0b1b9c:	44085000 */ 	mfc1	$t0,$f10
/*  f0b1ba0:	44815000 */ 	mtc1	$at,$f10
/*  f0b1ba4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b1ba8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0b1bac:	44c8f800 */ 	ctc1	$t0,$31
/*  f0b1bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1bb4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0b1bb8:	4448f800 */ 	cfc1	$t0,$31
/*  f0b1bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1bc0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0b1bc4:	15000005 */ 	bnez	$t0,.L0f0b1bdc
/*  f0b1bc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1bcc:	44085000 */ 	mfc1	$t0,$f10
/*  f0b1bd0:	3c018000 */ 	lui	$at,0x8000
/*  f0b1bd4:	10000007 */ 	beqz	$zero,.L0f0b1bf4
/*  f0b1bd8:	01014025 */ 	or	$t0,$t0,$at
.L0f0b1bdc:
/*  f0b1bdc:	10000005 */ 	beqz	$zero,.L0f0b1bf4
/*  f0b1be0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0b1be4:	44085000 */ 	mfc1	$t0,$f10
.L0f0b1be8:
/*  f0b1be8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1bec:	0500fffb */ 	bltz	$t0,.L0f0b1bdc
/*  f0b1bf0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b1bf4:
/*  f0b1bf4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0b1bf8:	a0a80002 */ 	sb	$t0,0x2($a1)
/*  f0b1bfc:	90a30000 */ 	lbu	$v1,0x0($a1)
.L0f0b1c00:
/*  f0b1c00:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0b1c04:	14610005 */ 	bne	$v1,$at,.L0f0b1c1c
/*  f0b1c08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1c0c:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0b1c10:	01225021 */ 	addu	$t2,$t1,$v0
/*  f0b1c14:	8d4c0b90 */ 	lw	$t4,0xb90($t2)
/*  f0b1c18:	a0ac0002 */ 	sb	$t4,0x2($a1)
.L0f0b1c1c:
/*  f0b1c1c:	03e00008 */ 	jr	$ra
/*  f0b1c20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1c24
/*  f0b1c24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1c28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1c2c:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1c30:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b1c34:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0b1c38:	91c40000 */ 	lbu	$a0,0x0($t6)
/*  f0b1c3c:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0b1c40:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0b1c44:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b1c48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1c4c:	50600008 */ 	beqzl	$v1,.L0f0b1c70
/*  f0b1c50:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1c54:	80640007 */ 	lb	$a0,0x7($v1)
/*  f0b1c58:	04800004 */ 	bltz	$a0,.L0f0b1c6c
/*  f0b1c5c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f0b1c60:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0b1c64:	10000002 */ 	beqz	$zero,.L0f0b1c70
/*  f0b1c68:	8f02001c */ 	lw	$v0,0x1c($t8)
.L0f0b1c6c:
/*  f0b1c6c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1c70:
/*  f0b1c70:	03e00008 */ 	jr	$ra
/*  f0b1c74:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f0b1c78
/*  f0b1c78:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1c7c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1c80:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1c84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1c88:	10400008 */ 	beqz	$v0,.L0f0b1cac
/*  f0b1c8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1c90:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0b1c94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1c98:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1c9c:	55e10004 */ 	bnel	$t7,$at,.L0f0b1cb0
/*  f0b1ca0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1ca4:	10000002 */ 	beqz	$zero,.L0f0b1cb0
/*  f0b1ca8:	9042003c */ 	lbu	$v0,0x3c($v0)
.L0f0b1cac:
/*  f0b1cac:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1cb0:
/*  f0b1cb0:	03e00008 */ 	jr	$ra
/*  f0b1cb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1cb8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1cbc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1cc0:	0fc2c709 */ 	jal	func0f0b1c24
/*  f0b1cc4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0b1cc8:	10400002 */ 	beqz	$v0,.L0f0b1cd4
/*  f0b1ccc:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b1cd0:	8c430004 */ 	lw	$v1,0x4($v0)
.L0f0b1cd4:
/*  f0b1cd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1cd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b1cdc:	00601025 */ 	or	$v0,$v1,$zero
/*  f0b1ce0:	03e00008 */ 	jr	$ra
/*  f0b1ce4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1ce8
/*  f0b1ce8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1cec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1cf0:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1cf8:	44801000 */ 	mtc1	$zero,$f2
/*  f0b1cfc:	10400007 */ 	beqz	$v0,.L0f0b1d1c
/*  f0b1d00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1d04:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0b1d08:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1d0c:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1d10:	55e10003 */ 	bnel	$t7,$at,.L0f0b1d20
/*  f0b1d14:	46001006 */ 	mov.s	$f0,$f2
/*  f0b1d18:	c4420034 */ 	lwc1	$f2,0x34($v0)
.L0f0b1d1c:
/*  f0b1d1c:	46001006 */ 	mov.s	$f0,$f2
.L0f0b1d20:
/*  f0b1d20:	03e00008 */ 	jr	$ra
/*  f0b1d24:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b1d28
/*  f0b1d28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b1d2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1d30:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1d34:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0b1d38:	44801000 */ 	mtc1	$zero,$f2
/*  f0b1d3c:	10400016 */ 	beqz	$v0,.L0f0b1d98
/*  f0b1d40:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0b1d44:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f0b1d48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1d4c:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0b1d50:	15c10002 */ 	bne	$t6,$at,.L0f0b1d5c
/*  f0b1d54:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0b1d58:	c442001c */ 	lwc1	$f2,0x1c($v0)
.L0f0b1d5c:
/*  f0b1d5c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0b1d60:	5461000a */ 	bnel	$v1,$at,.L0f0b1d8c
/*  f0b1d64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0b1d68:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f0b1d6c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0b1d70:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f0b1d74:	15e10004 */ 	bne	$t7,$at,.L0f0b1d88
/*  f0b1d78:	3c01800a */ 	lui	$at,0x800a
/*  f0b1d7c:	c424a004 */ 	lwc1	$f4,-0x5ffc($at)
/*  f0b1d80:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0b1d84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0b1d88:
/*  f0b1d88:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0b1d8c:
/*  f0b1d8c:	54610003 */ 	bnel	$v1,$at,.L0f0b1d9c
/*  f0b1d90:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f0b1d94:	c4420020 */ 	lwc1	$f2,0x20($v0)
.L0f0b1d98:
/*  f0b1d98:	90980000 */ 	lbu	$t8,0x0($a0)
.L0f0b1d9c:
/*  f0b1d9c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b1da0:	57010012 */ 	bnel	$t8,$at,.L0f0b1dec
/*  f0b1da4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b1da8:	90990002 */ 	lbu	$t9,0x2($a0)
/*  f0b1dac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0b1db0:	44993000 */ 	mtc1	$t9,$f6
/*  f0b1db4:	07210004 */ 	bgez	$t9,.L0f0b1dc8
/*  f0b1db8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b1dbc:	44815000 */ 	mtc1	$at,$f10
/*  f0b1dc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1dc4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f0b1dc8:
/*  f0b1dc8:	3c014040 */ 	lui	$at,0x4040
/*  f0b1dcc:	44818000 */ 	mtc1	$at,$f16
/*  f0b1dd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0b1dd4:	44812000 */ 	mtc1	$at,$f4
/*  f0b1dd8:	46104483 */ 	div.s	$f18,$f8,$f16
/*  f0b1ddc:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0b1de0:	46023082 */ 	mul.s	$f2,$f6,$f2
/*  f0b1de4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1de8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0b1dec:
/*  f0b1dec:	0fc2883f */ 	jal	func0f0a20fc
/*  f0b1df0:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f0b1df4:	10400007 */ 	beqz	$v0,.L0f0b1e14
/*  f0b1df8:	c7a20018 */ 	lwc1	$f2,0x18($sp)
/*  f0b1dfc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b1e00:	0fc2883f */ 	jal	func0f0a20fc
/*  f0b1e04:	e7a20018 */ 	swc1	$f2,0x18($sp)
/*  f0b1e08:	10400002 */ 	beqz	$v0,.L0f0b1e14
/*  f0b1e0c:	c7a20018 */ 	lwc1	$f2,0x18($sp)
/*  f0b1e10:	46021080 */ 	add.s	$f2,$f2,$f2
.L0f0b1e14:
/*  f0b1e14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1e18:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b1e1c:	46001006 */ 	mov.s	$f0,$f2
/*  f0b1e20:	03e00008 */ 	jr	$ra
/*  f0b1e24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b1e28
/*  f0b1e28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1e2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1e30:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1e38:	10400008 */ 	beqz	$v0,.L0f0b1e5c
/*  f0b1e3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1e40:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0b1e44:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1e48:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1e4c:	55e10004 */ 	bnel	$t7,$at,.L0f0b1e60
/*  f0b1e50:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1e54:	10000002 */ 	beqz	$zero,.L0f0b1e60
/*  f0b1e58:	90420038 */ 	lbu	$v0,0x38($v0)
.L0f0b1e5c:
/*  f0b1e5c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1e60:
/*  f0b1e60:	03e00008 */ 	jr	$ra
/*  f0b1e64:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b1e68
/*  f0b1e68:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1e6c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1e70:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1e74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b1e78:	10400008 */ 	beqz	$v0,.L0f0b1e9c
/*  f0b1e7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1e80:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f0b1e84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b1e88:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0b1e8c:	55e10004 */ 	bnel	$t7,$at,.L0f0b1ea0
/*  f0b1e90:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b1e94:	10000002 */ 	beqz	$zero,.L0f0b1ea0
/*  f0b1e98:	9442003a */ 	lhu	$v0,0x3a($v0)
.L0f0b1e9c:
/*  f0b1e9c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1ea0:
/*  f0b1ea0:	03e00008 */ 	jr	$ra
/*  f0b1ea4:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f0b1ea8
/*  f0b1ea8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0b1eac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b1eb0:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b1eb4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0b1eb8:	10400006 */ 	beqz	$v0,.L0f0b1ed4
/*  f0b1ebc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0b1ec0:	8c4e0010 */ 	lw	$t6,0x10($v0)
/*  f0b1ec4:	01c47824 */ 	and	$t7,$t6,$a0
/*  f0b1ec8:	008f1026 */ 	xor	$v0,$a0,$t7
/*  f0b1ecc:	10000002 */ 	beqz	$zero,.L0f0b1ed8
/*  f0b1ed0:	2c420001 */ 	sltiu	$v0,$v0,0x1
.L0f0b1ed4:
/*  f0b1ed4:	00001025 */ 	or	$v0,$zero,$zero
.L0f0b1ed8:
/*  f0b1ed8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b1edc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0b1ee0:	03e00008 */ 	jr	$ra
/*  f0b1ee4:	00000000 */ 	sll	$zero,$zero,0x0
);

s8 weaponGetMaxFireRatePerTick(u32 weaponnum, u32 funcindex)
{
	u32 stack[2];
	s32 result = 0;
	struct weapon *weapon = weaponFindById(weaponnum);
	struct weaponfunc *func = weapon->functions[funcindex];

	if (func && func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
		struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *)func;

		result = 3600.0f / autofunc->maxfirerate;
	}

	return result;
}

u32 currentPlayerGetSight(void)
{
	struct weaponfunc *func = weaponGetFunctionById(g_Vars.currentplayer->unk0638, g_Vars.currentplayer->unk063b);

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		return SIGHT_NONE;
	}

	if (cheatIsActive(CHEAT_CLASSICSIGHT)) {
		return SIGHT_CLASSIC;
	}

	switch (g_Vars.currentplayer->unk0638) {
	case WEAPON_HORIZONSCANNER:
		return SIGHT_NONE;
	case WEAPON_NONE:
	case WEAPON_UNARMED:
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_RCP120:
	case WEAPON_SHOTGUN:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
	case WEAPON_COMBATKNIFE:
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	case WEAPON_ECMMINE:
		return SIGHT_DEFAULT;
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_SNIPERRIFLE:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
		return SIGHT_ZOOM;
	case WEAPON_MAULER:
	case WEAPON_REAPER:
		return SIGHT_SKEDAR;
	case WEAPON_PHOENIX:
	case WEAPON_CALLISTONTG:
	case WEAPON_FARSIGHTXR20:
		return SIGHT_MAIAN;
	case WEAPON_PP9I:
	case WEAPON_CC13:
	case WEAPON_KL01313:
	case WEAPON_KF7SPECIAL:
	case WEAPON_ZZT:
	case WEAPON_DMC:
	case WEAPON_AR53:
	case WEAPON_RCP45:
		return SIGHT_CLASSIC;
	}

	return SIGHT_DEFAULT;
}

GLOBAL_ASM(
glabel func0f0b201c
/*  f0b201c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0b2020:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0b2024:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0b2028:	0fc2c41f */ 	jal	func0f0b107c
/*  f0b202c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0b2030:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0b2034:	10400002 */ 	beqz	$v0,.L0f0b2040
/*  f0b2038:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0b203c:	8c430008 */ 	lw	$v1,0x8($v0)
.L0f0b2040:
/*  f0b2040:	54600004 */ 	bnezl	$v1,.L0f0b2054
/*  f0b2044:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f0b2048:	3c038007 */ 	lui	$v1,%hi(invmenupos_00010fd0)
/*  f0b204c:	2463afb0 */ 	addiu	$v1,$v1,%lo(invmenupos_00010fd0)
/*  f0b2050:	c4640000 */ 	lwc1	$f4,0x0($v1)
.L0f0b2054:
/*  f0b2054:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f0b2058:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f0b205c:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f0b2060:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f0b2064:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f0b2068:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0b206c:	e4aa000c */ 	swc1	$f10,0xc($a1)
/*  f0b2070:	c4700010 */ 	lwc1	$f16,0x10($v1)
/*  f0b2074:	e4b00010 */ 	swc1	$f16,0x10($a1)
/*  f0b2078:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0b207c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0b2080:	03e00008 */ 	jr	$ra
/*  f0b2084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2088:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b208c:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b2090:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b2094:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b2098:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b209c:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b20a0:	10600003 */ 	beqz	$v1,.L0f0b20b0
/*  f0b20a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b20a8:	03e00008 */ 	jr	$ra
/*  f0b20ac:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f0b20b0:
/*  f0b20b0:	03e00008 */ 	jr	$ra
/*  f0b20b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b20b8:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b20bc:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b20c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b20c4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b20c8:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b20cc:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b20d0:	10600003 */ 	beqz	$v1,.L0f0b20e0
/*  f0b20d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b20d8:	03e00008 */ 	jr	$ra
/*  f0b20dc:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f0b20e0:
/*  f0b20e0:	03e00008 */ 	jr	$ra
/*  f0b20e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b20e8
/*  f0b20e8:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b20ec:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b20f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b20f4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b20f8:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b20fc:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b2100:	10600003 */ 	beqz	$v1,.L0f0b2110
/*  f0b2104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2108:	03e00008 */ 	jr	$ra
/*  f0b210c:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f0b2110:
/*  f0b2110:	03e00008 */ 	jr	$ra
/*  f0b2114:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0b2118
/*  f0b2118:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0b211c:	3c038007 */ 	lui	$v1,%hi(g_Weapons)
/*  f0b2120:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b2124:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0b2128:	006f1821 */ 	addu	$v1,$v1,$t7
/*  f0b212c:	8c63ff18 */ 	lw	$v1,%lo(g_Weapons)($v1)
/*  f0b2130:	10600003 */ 	beqz	$v1,.L0f0b2140
/*  f0b2134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2138:	03e00008 */ 	jr	$ra
/*  f0b213c:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f0b2140:
/*  f0b2140:	03e00008 */ 	jr	$ra
/*  f0b2144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b2148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b214c:	00000000 */ 	sll	$zero,$zero,0x0
);
