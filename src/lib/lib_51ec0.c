#include <ultra64.h>

GLOBAL_ASM(
glabel func00051ec0
/*    51ec0:	3c0ea450 */ 	lui	$t6,0xa450
/*    51ec4:	8dc4000c */ 	lw	$a0,0xc($t6)
/*    51ec8:	3c018000 */ 	lui	$at,0x8000
/*    51ecc:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    51ed0:	00817824 */ 	and	$t7,$a0,$at
/*    51ed4:	11e00003 */ 	beqz	$t7,.L00051ee4
/*    51ed8:	00000000 */ 	nop
/*    51edc:	10000002 */ 	b	.L00051ee8
/*    51ee0:	24020001 */ 	addiu	$v0,$zero,0x1
.L00051ee4:
/*    51ee4:	00001025 */ 	or	$v0,$zero,$zero
.L00051ee8:
/*    51ee8:	03e00008 */ 	jr	$ra
/*    51eec:	27bd0008 */ 	addiu	$sp,$sp,0x8
);
