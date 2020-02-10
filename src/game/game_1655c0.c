#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"
GLOBAL_ASM(
glabel stageFindById
/*  f1655c0:	3c068008 */ 	lui	$a2,0x8008
/*  f1655c4:	24c3fcc0 */ 	addiu	$v1,$a2,-832
/*  f1655c8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1655cc:	24620d58 */ 	addiu	$v0,$v1,0xd58
/*  f1655d0:	25cefcc1 */ 	addiu	$t6,$t6,-831
/*  f1655d4:	3c05800a */ 	lui	$a1,0x800a
/*  f1655d8:	004e082b */ 	sltu	$at,$v0,$t6
/*  f1655dc:	1420000a */ 	bnez	$at,.L0f165608
/*  f1655e0:	8ca5a474 */ 	lw	$a1,-0x5b8c($a1)
/*  f1655e4:	846f0000 */ 	lh	$t7,0x0($v1)
.L0f1655e8:
/*  f1655e8:	54af0004 */ 	bnel	$a1,$t7,.L0f1655fc
/*  f1655ec:	24630038 */ 	addiu	$v1,$v1,0x38
/*  f1655f0:	03e00008 */ 	jr	$ra
/*  f1655f4:	00601025 */ 	or	$v0,$v1,$zero
/*  f1655f8:	24630038 */ 	addiu	$v1,$v1,0x38
.L0f1655fc:
/*  f1655fc:	0062082b */ 	sltu	$at,$v1,$v0
/*  f165600:	5420fff9 */ 	bnezl	$at,.L0f1655e8
/*  f165604:	846f0000 */ 	lh	$t7,0x0($v1)
.L0f165608:
/*  f165608:	00001025 */ 	or	$v0,$zero,$zero
/*  f16560c:	03e00008 */ 	jr	$ra
/*  f165610:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel stageGetIndex
/*  f165614:	3c078008 */ 	lui	$a3,0x8008
/*  f165618:	24e2fcc0 */ 	addiu	$v0,$a3,-832
/*  f16561c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f165620:	24430d58 */ 	addiu	$v1,$v0,0xd58
/*  f165624:	25cefcc1 */ 	addiu	$t6,$t6,-831
/*  f165628:	006e082b */ 	sltu	$at,$v1,$t6
/*  f16562c:	1420000a */ 	bnez	$at,.L0f165658
/*  f165630:	00003025 */ 	or	$a2,$zero,$zero
.L0f165634:
/*  f165634:	844f0000 */ 	lh	$t7,0x0($v0)
/*  f165638:	24420038 */ 	addiu	$v0,$v0,0x38
/*  f16563c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f165640:	148f0003 */ 	bne	$a0,$t7,.L0f165650
/*  f165644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165648:	03e00008 */ 	jr	$ra
/*  f16564c:	00c01025 */ 	or	$v0,$a2,$zero
.L0f165650:
/*  f165650:	1420fff8 */ 	bnez	$at,.L0f165634
/*  f165654:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f165658:
/*  f165658:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f16565c:	03e00008 */ 	jr	$ra
/*  f165660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16566c:	00000000 */ 	sll	$zero,$zero,0x0
);