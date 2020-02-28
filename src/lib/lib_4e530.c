#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_488e0.h"
#include "lib/lib_49a90.h"
#include "lib/lib_51ec0.h"
#include "lib/lib_52070.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004e530
/*    4e530:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    4e534:	3c0e8006 */ 	lui	$t6,0x8006
/*    4e538:	8dcecf00 */ 	lw	$t6,-0x3100($t6)
/*    4e53c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4e540:	afa40028 */ 	sw	$a0,0x28($sp)
/*    4e544:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    4e548:	afa60030 */ 	sw	$a2,0x30($sp)
/*    4e54c:	afa70034 */ 	sw	$a3,0x34($sp)
/*    4e550:	afb10018 */ 	sw	$s1,0x18($sp)
/*    4e554:	15c00003 */ 	bnez	$t6,.L0004e564
/*    4e558:	afb00014 */ 	sw	$s0,0x14($sp)
/*    4e55c:	10000032 */ 	beqz	$zero,.L0004e628
/*    4e560:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004e564:
/*    4e564:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    4e568:	15e00005 */ 	bnez	$t7,.L0004e580
/*    4e56c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e570:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    4e574:	2418000b */ 	addiu	$t8,$zero,0xb
/*    4e578:	10000004 */ 	beqz	$zero,.L0004e58c
/*    4e57c:	a7380000 */ 	sh	$t8,0x0($t9)
.L0004e580:
/*    4e580:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    4e584:	2408000c */ 	addiu	$t0,$zero,0xc
/*    4e588:	a5280000 */ 	sh	$t0,0x0($t1)
.L0004e58c:
/*    4e58c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    4e590:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    4e594:	24010001 */ 	addiu	$at,$zero,0x1
/*    4e598:	a16a0002 */ 	sb	$t2,0x2($t3)
/*    4e59c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    4e5a0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    4e5a4:	adac0004 */ 	sw	$t4,0x4($t5)
/*    4e5a8:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    4e5ac:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    4e5b0:	adee0008 */ 	sw	$t6,0x8($t7)
/*    4e5b4:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    4e5b8:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    4e5bc:	af38000c */ 	sw	$t8,0xc($t9)
/*    4e5c0:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    4e5c4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    4e5c8:	ad280010 */ 	sw	$t0,0x10($t1)
/*    4e5cc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    4e5d0:	ad400014 */ 	sw	$zero,0x14($t2)
/*    4e5d4:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    4e5d8:	1561000a */ 	bne	$t3,$at,.L0004e604
/*    4e5dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e5e0:	0c014810 */ 	jal	func00052040
/*    4e5e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e5e8:	00408825 */ 	or	$s1,$v0,$zero
/*    4e5ec:	02202025 */ 	or	$a0,$s1,$zero
/*    4e5f0:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    4e5f4:	0c0147bc */ 	jal	func00051ef0
/*    4e5f8:	00003025 */ 	or	$a2,$zero,$zero
/*    4e5fc:	10000009 */ 	beqz	$zero,.L0004e624
/*    4e600:	00408025 */ 	or	$s0,$v0,$zero
.L0004e604:
/*    4e604:	0c014810 */ 	jal	func00052040
/*    4e608:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e60c:	00408825 */ 	or	$s1,$v0,$zero
/*    4e610:	02202025 */ 	or	$a0,$s1,$zero
/*    4e614:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    4e618:	0c012238 */ 	jal	func000488e0
/*    4e61c:	00003025 */ 	or	$a2,$zero,$zero
/*    4e620:	00408025 */ 	or	$s0,$v0,$zero
.L0004e624:
/*    4e624:	02001025 */ 	or	$v0,$s0,$zero
.L0004e628:
/*    4e628:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4e62c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    4e630:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    4e634:	03e00008 */ 	jr	$ra
/*    4e638:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    4e63c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004e640
/*    4e640:	3c028006 */ 	lui	$v0,0x8006
/*    4e644:	03e00008 */ 	jr	$ra
/*    4e648:	8c420944 */ 	lw	$v0,0x944($v0)
/*    4e64c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004e650
/*    4e650:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4e654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4e658:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4e65c:	0c0126b8 */ 	jal	func00049ae0
/*    4e660:	afa50024 */ 	sw	$a1,0x24($sp)
/*    4e664:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    4e668:	0c01481c */ 	jal	func00052070
/*    4e66c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    4e670:	0c0126c9 */ 	jal	func00049b24
/*    4e674:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    4e678:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4e67c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    4e680:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4e684:	03e00008 */ 	jr	$ra
/*    4e688:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e68c:	00000000 */ 	sll	$zero,$zero,0x0
);