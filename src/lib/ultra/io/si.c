#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSiDeviceBusy
/*    51c60:	3c0ea480 */ 	lui	$t6,0xa480
/*    51c64:	8dc40018 */ 	lw	$a0,0x18($t6)
/*    51c68:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    51c6c:	308f0003 */ 	andi	$t7,$a0,0x3
/*    51c70:	11e00003 */ 	beqz	$t7,.L00051c80
/*    51c74:	00000000 */ 	nop
/*    51c78:	10000002 */ 	b	.L00051c84
/*    51c7c:	24020001 */ 	addiu	$v0,$zero,0x1
.L00051c80:
/*    51c80:	00001025 */ 	or	$v0,$zero,$zero
.L00051c84:
/*    51c84:	03e00008 */ 	jr	$ra
/*    51c88:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    51c8c:	00000000 */ 	nop
);
