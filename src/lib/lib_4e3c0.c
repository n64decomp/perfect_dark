#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_4b480.h"
#include "lib/lib_51ec0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004e3c0
/*    4e3c0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4e3c4:	3c0f8006 */ 	lui	$t7,0x8006
/*    4e3c8:	91ef0990 */ 	lbu	$t7,0x990($t7)
/*    4e3cc:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4e3d0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    4e3d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4e3d8:	afa50024 */ 	sw	$a1,0x24($sp)
/*    4e3dc:	11e00003 */ 	beqz	$t7,.L0004e3ec
/*    4e3e0:	afae001c */ 	sw	$t6,0x1c($sp)
/*    4e3e4:	25d8e000 */ 	addiu	$t8,$t6,-8192
/*    4e3e8:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0004e3ec:
/*    4e3ec:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    4e3f0:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    4e3f4:	03284821 */ 	addu	$t1,$t9,$t0
/*    4e3f8:	312a1fff */ 	andi	$t2,$t1,0x1fff
/*    4e3fc:	15400005 */ 	bnez	$t2,.L0004e414
/*    4e400:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e404:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    4e408:	3c018006 */ 	lui	$at,0x8006
/*    4e40c:	10000003 */ 	beqz	$zero,.L0004e41c
/*    4e410:	a02b0990 */ 	sb	$t3,0x990($at)
.L0004e414:
/*    4e414:	3c018006 */ 	lui	$at,0x8006
/*    4e418:	a0200990 */ 	sb	$zero,0x990($at)
.L0004e41c:
/*    4e41c:	0c0147b0 */ 	jal	func00051ec0
/*    4e420:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e424:	10400003 */ 	beqz	$v0,.L0004e434
/*    4e428:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e42c:	10000009 */ 	beqz	$zero,.L0004e454
/*    4e430:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004e434:
/*    4e434:	0c012d20 */ 	jal	func0004b480
/*    4e438:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    4e43c:	3c0ca450 */ 	lui	$t4,0xa450
/*    4e440:	ad820000 */ 	sw	$v0,0x0($t4)
/*    4e444:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    4e448:	3c0fa450 */ 	lui	$t7,0xa450
/*    4e44c:	00001025 */ 	or	$v0,$zero,$zero
/*    4e450:	aded0004 */ 	sw	$t5,0x4($t7)
.L0004e454:
/*    4e454:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4e458:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4e45c:	03e00008 */ 	jr	$ra
/*    4e460:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e464:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e468:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e46c:	00000000 */ 	sll	$zero,$zero,0x0
);