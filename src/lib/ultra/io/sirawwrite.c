#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osSiRawWriteIo
/*    4ad30:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4ad34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4ad38:	afa40018 */ 	sw	$a0,0x18($sp)
/*    4ad3c:	0c014718 */ 	jal	__osSiDeviceBusy
/*    4ad40:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    4ad44:	10400003 */ 	beqz	$v0,.L0004ad54
/*    4ad48:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    4ad4c:	10000006 */ 	b	.L0004ad68
/*    4ad50:	2402ffff */ 	addiu	$v0,$zero,-1
.L0004ad54:
/*    4ad54:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    4ad58:	3c01a000 */ 	lui	$at,0xa000
/*    4ad5c:	00001025 */ 	or	$v0,$zero,$zero
/*    4ad60:	01e1c025 */ 	or	$t8,$t7,$at
/*    4ad64:	af0e0000 */ 	sw	$t6,0x0($t8)
.L0004ad68:
/*    4ad68:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4ad6c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4ad70:	03e00008 */ 	jr	$ra
/*    4ad74:	00000000 */ 	nop
/*    4ad78:	00000000 */ 	nop
/*    4ad7c:	00000000 */ 	nop
);
