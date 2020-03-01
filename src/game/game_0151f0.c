#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0151f0
/*  f0151f0:	3c04800a */ 	lui	$a0,%hi(g_Objectives)
/*  f0151f4:	3c08800a */ 	lui	$t0,%hi(var8009d088)
/*  f0151f8:	3c06800a */ 	lui	$a2,%hi(var8009d088)
/*  f0151fc:	24c6d088 */ 	addiu	$a2,$a2,%lo(var8009d088)
/*  f015200:	2508d088 */ 	addiu	$t0,$t0,%lo(var8009d088)
/*  f015204:	2484d060 */ 	addiu	$a0,$a0,%lo(g_Objectives)
/*  f015208:	00001825 */ 	or	$v1,$zero,$zero
/*  f01520c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f015210:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f015214:
/*  f015214:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f015218:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f01521c:	1040000a */ 	beqz	$v0,.L0f015248
/*  f015220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015224:	904e000e */ 	lbu	$t6,0xe($v0)
/*  f015228:	00c31021 */ 	addu	$v0,$a2,$v1
/*  f01522c:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f015230:	11e00005 */ 	beqz	$t7,.L0f015248
/*  f015234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015238:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f01523c:	10b80002 */ 	beq	$a1,$t8,.L0f015248
/*  f015240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015244:	ac470000 */ 	sw	$a3,0x0($v0)
.L0f015248:
/*  f015248:	1488fff2 */ 	bne	$a0,$t0,.L0f015214
/*  f01524c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f015250:	03e00008 */ 	jr	$ra
/*  f015254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f015258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01525c:	00000000 */ 	sll	$zero,$zero,0x0
);
