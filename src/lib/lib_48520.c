#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_488e0.h"
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048520
/*    48520:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48524:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48528:	afa40028 */ 	sw	$a0,0x28($sp)
/*    4852c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    48530:	afa60030 */ 	sw	$a2,0x30($sp)
/*    48534:	0c01256c */ 	jal	__osDisableInt
/*    48538:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4853c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    48540:	3c18800a */ 	lui	$t8,%hi(var8009c6e0)
/*    48544:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    48548:	2718c6e0 */ 	addiu	$t8,$t8,%lo(var8009c6e0)
/*    4854c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*    48550:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    48554:	afb90020 */ 	sw	$t9,0x20($sp)
/*    48558:	af280000 */ 	sw	$t0,0x0($t9)
/*    4855c:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    48560:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    48564:	2401000e */ 	addiu	$at,$zero,0xe
/*    48568:	00408025 */ 	or	$s0,$v0,$zero
/*    4856c:	ad490004 */ 	sw	$t1,0x4($t2)
/*    48570:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    48574:	15610010 */ 	bne	$t3,$at,.L000485b8
/*    48578:	00000000 */ 	sll	$zero,$zero,0x0
/*    4857c:	3c0c8006 */ 	lui	$t4,%hi(var8005cf6c)
/*    48580:	8d8ccf6c */ 	lw	$t4,%lo(var8005cf6c)($t4)
/*    48584:	11800009 */ 	beqz	$t4,.L000485ac
/*    48588:	00000000 */ 	sll	$zero,$zero,0x0
/*    4858c:	3c0d8006 */ 	lui	$t5,%hi(var80060890)
/*    48590:	8dad0890 */ 	lw	$t5,%lo(var80060890)($t5)
/*    48594:	15a00005 */ 	bnez	$t5,.L000485ac
/*    48598:	00000000 */ 	sll	$zero,$zero,0x0
/*    4859c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    485a0:	8fa50030 */ 	lw	$a1,0x30($sp)
/*    485a4:	0c012238 */ 	jal	osSendMesg
/*    485a8:	00003025 */ 	or	$a2,$zero,$zero
.L000485ac:
/*    485ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    485b0:	3c018006 */ 	lui	$at,0x8006
/*    485b4:	ac2e0890 */ 	sw	$t6,0x890($at)
.L000485b8:
/*    485b8:	0c012588 */ 	jal	__osRestoreInt
/*    485bc:	02002025 */ 	or	$a0,$s0,$zero
/*    485c0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    485c4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    485c8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    485cc:	03e00008 */ 	jr	$ra
/*    485d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    485d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    485d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    485dc:	00000000 */ 	sll	$zero,$zero,0x0
);