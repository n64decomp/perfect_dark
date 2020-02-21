#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004e470
/*    4e470:	3c0ea450 */ 	lui	$t6,0xa450
/*    4e474:	03e00008 */ 	jr	$ra
/*    4e478:	8dc20004 */ 	lw	$v0,0x4($t6)
/*    4e47c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004e480
/*    4e480:	18a0001f */ 	blez	$a1,.L0004e500
/*    4e484:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e488:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*    4e48c:	00ab082b */ 	sltu	$at,$a1,$t3
/*    4e490:	1020001d */ 	beqz	$at,.L0004e508
/*    4e494:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e498:	00804025 */ 	or	$t0,$a0,$zero
/*    4e49c:	00854821 */ 	addu	$t1,$a0,$a1
/*    4e4a0:	0109082b */ 	sltu	$at,$t0,$t1
/*    4e4a4:	10200016 */ 	beqz	$at,.L0004e500
/*    4e4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e4ac:	310a000f */ 	andi	$t2,$t0,0xf
/*    4e4b0:	11400007 */ 	beqz	$t2,.L0004e4d0
/*    4e4b4:	2529fff0 */ 	addiu	$t1,$t1,-16
/*    4e4b8:	010a4023 */ 	subu	$t0,$t0,$t2
/*    4e4bc:	bd150000 */ 	cache	0x15,0x0($t0)
/*    4e4c0:	0109082b */ 	sltu	$at,$t0,$t1
/*    4e4c4:	1020000e */ 	beqz	$at,.L0004e500
/*    4e4c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e4cc:	25080010 */ 	addiu	$t0,$t0,0x10
.L0004e4d0:
/*    4e4d0:	312a000f */ 	andi	$t2,$t1,0xf
/*    4e4d4:	11400006 */ 	beqz	$t2,.L0004e4f0
/*    4e4d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e4dc:	012a4823 */ 	subu	$t1,$t1,$t2
/*    4e4e0:	bd350010 */ 	cache	0x15,0x10($t1)
/*    4e4e4:	0128082b */ 	sltu	$at,$t1,$t0
/*    4e4e8:	14200005 */ 	bnez	$at,.L0004e500
/*    4e4ec:	00000000 */ 	sll	$zero,$zero,0x0
.L0004e4f0:
/*    4e4f0:	bd110000 */ 	cache	0x11,0x0($t0)
/*    4e4f4:	0109082b */ 	sltu	$at,$t0,$t1
/*    4e4f8:	1420fffd */ 	bnez	$at,.L0004e4f0
/*    4e4fc:	25080010 */ 	addiu	$t0,$t0,0x10
.L0004e500:
/*    4e500:	03e00008 */ 	jr	$ra
/*    4e504:	00000000 */ 	sll	$zero,$zero,0x0
.L0004e508:
/*    4e508:	3c088000 */ 	lui	$t0,0x8000
/*    4e50c:	010b4821 */ 	addu	$t1,$t0,$t3
/*    4e510:	2529fff0 */ 	addiu	$t1,$t1,-16
.L0004e514:
/*    4e514:	bd010000 */ 	cache	0x1,0x0($t0)
/*    4e518:	0109082b */ 	sltu	$at,$t0,$t1
/*    4e51c:	1420fffd */ 	bnez	$at,.L0004e514
/*    4e520:	25080010 */ 	addiu	$t0,$t0,0x10
/*    4e524:	03e00008 */ 	jr	$ra
/*    4e528:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e52c:	00000000 */ 	sll	$zero,$zero,0x0
);