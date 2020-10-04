#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osDequeueThread
/*    4a210:	00803025 */ 	or	$a2,$a0,$zero
/*    4a214:	8cc70000 */ 	lw	$a3,0x0($a2)
/*    4a218:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4a21c:	10e0000a */ 	beqz	$a3,.L0004a248
/*    4a220:	00000000 */ 	nop
.L0004a224:
/*    4a224:	14e50004 */ 	bne	$a3,$a1,.L0004a238
/*    4a228:	00000000 */ 	nop
/*    4a22c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    4a230:	10000005 */ 	b	.L0004a248
/*    4a234:	acce0000 */ 	sw	$t6,0x0($a2)
.L0004a238:
/*    4a238:	00e03025 */ 	or	$a2,$a3,$zero
/*    4a23c:	8cc70000 */ 	lw	$a3,0x0($a2)
/*    4a240:	14e0fff8 */ 	bnez	$a3,.L0004a224
/*    4a244:	00000000 */ 	nop
.L0004a248:
/*    4a248:	03e00008 */ 	jr	$ra
/*    4a24c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);
