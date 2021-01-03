#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_00c240.h"
#include "game/game_0601b0.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

void gvarsInitProps(void)
{
	s32 i;

	g_Vars.props = malloc(ALIGN64(g_Vars.maxprops * sizeof(struct prop)), 4);
	g_Vars.tangibleprops = malloc(ALIGN64(200 * sizeof(void *)), 4);

	var80069880 = 1;

	g_Vars.unk00033c = NULL;
	g_Vars.unk000340 = NULL;
	g_Vars.unk000354 = g_Vars.unk000350 = NULL;

	g_Vars.tangibleprops[0] = NULL;

	g_Vars.unk00034c = g_Vars.tangibleprops;
	g_Vars.freeprops = g_Vars.props;

	for (i = 0; i < g_Vars.maxprops - 1; i++) {
		g_Vars.props[i].next = &g_Vars.props[i + 1];
	}

	func0f00c390();

	if (g_Vars.normmplayerisrunning) {
		g_Vars.numpropstateindexes = 4;
	} else {
		g_Vars.numpropstateindexes = 7;
	}

	g_Vars.nextpropstateindex = 0;
	g_Vars.unk00035a = 0;
	g_Vars.unk00035b = 0;
	g_Vars.unk00035c = 0xfffe;
	g_Vars.unk00035e = 0xffff;

	for (i = 0; i < ARRAYCOUNT(g_Vars.propstates); i++) {
		g_Vars.propstates[i].propcount = 0;
		g_Vars.propstates[i].chrpropcount = 0;
		g_Vars.propstates[i].updatetime = 0;
		g_Vars.propstates[i].chrupdatetime = 0;
		g_Vars.propstates[i].slotupdate240 = 0;
		g_Vars.propstates[i].slotupdate60error = 2;
	}
}

GLOBAL_ASM(
glabel func0f00c390
/*  f00c390:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f00c394:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f00c398:	8ce402bc */ 	lw	$a0,0x2bc($a3)
/*  f00c39c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00c3a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f00c3a4:	00047040 */ 	sll	$t6,$a0,0x1
/*  f00c3a8:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f00c3ac:	348f000f */ 	ori	$t7,$a0,0xf
/*  f00c3b0:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f00c3b4:	0c0048f2 */ 	jal	malloc
/*  f00c3b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c3bc:	3c08800a */ 	lui	$t0,%hi(var8009cda0)
/*  f00c3c0:	2508cda0 */ 	addiu	$t0,$t0,%lo(var8009cda0)
/*  f00c3c4:	ad020000 */ 	sw	$v0,0x0($t0)
/*  f00c3c8:	24041000 */ 	addiu	$a0,$zero,0x1000
/*  f00c3cc:	0c0048f2 */ 	jal	malloc
/*  f00c3d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f00c3d4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f00c3d8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f00c3dc:	8cf902bc */ 	lw	$t9,0x2bc($a3)
/*  f00c3e0:	3c05800a */ 	lui	$a1,%hi(var8009cda4)
/*  f00c3e4:	24a5cda4 */ 	addiu	$a1,$a1,%lo(var8009cda4)
/*  f00c3e8:	3c08800a */ 	lui	$t0,%hi(var8009cda0)
/*  f00c3ec:	2508cda0 */ 	addiu	$t0,$t0,%lo(var8009cda0)
/*  f00c3f0:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f00c3f4:	1b20000d */ 	blez	$t9,.L0f00c42c
/*  f00c3f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f00c3fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f00c400:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f00c404:	8d0b0000 */ 	lw	$t3,0x0($t0)
.L0f00c408:
/*  f00c408:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c40c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00c410:	a5860000 */ 	sh	$a2,0x0($t4)
/*  f00c414:	8ced02bc */ 	lw	$t5,0x2bc($a3)
/*  f00c418:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00c41c:	006d082a */ 	slt	$at,$v1,$t5
/*  f00c420:	5420fff9 */ 	bnezl	$at,.L0f00c408
/*  f00c424:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f00c428:	00001825 */ 	or	$v1,$zero,$zero
.L0f00c42c:
/*  f00c42c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f00c430:	00003825 */ 	or	$a3,$zero,$zero
/*  f00c434:	240a0100 */ 	addiu	$t2,$zero,0x100
/*  f00c438:	2409fffe */ 	addiu	$t1,$zero,-2
/*  f00c43c:	24040010 */ 	addiu	$a0,$zero,0x10
.L0f00c440:
/*  f00c440:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f00c444:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f00c448:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f00c44c:	a5e90000 */ 	sh	$t1,0x0($t7)
.L0f00c450:
/*  f00c450:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f00c454:	0003c900 */ 	sll	$t9,$v1,0x4
/*  f00c458:	03195821 */ 	addu	$t3,$t8,$t9
/*  f00c45c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f00c460:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f00c464:	1444fffa */ 	bne	$v0,$a0,.L0f00c450
/*  f00c468:	a5860000 */ 	sh	$a2,0x0($t4)
/*  f00c46c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00c470:	146afff3 */ 	bne	$v1,$t2,.L0f00c440
/*  f00c474:	24e70010 */ 	addiu	$a3,$a3,0x10
/*  f00c478:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00c47c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f00c480:	03e00008 */ 	jr	$ra
/*  f00c484:	00000000 */ 	nop
/*  f00c488:	00000000 */ 	nop
/*  f00c48c:	00000000 */ 	nop
);
