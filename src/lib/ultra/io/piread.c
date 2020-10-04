#include <libultra_internal.h>

GLOBAL_ASM(
glabel osPiReadIo
/*    4e650:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    4e654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4e658:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4e65c:	0c0126b8 */ 	jal	__osPiGetAccess
/*    4e660:	afa50024 */ 	sw	$a1,0x24($sp)
/*    4e664:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    4e668:	0c01481c */ 	jal	osPiRawReadIo
/*    4e66c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    4e670:	0c0126c9 */ 	jal	__osPiRelAccess
/*    4e674:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    4e678:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4e67c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    4e680:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    4e684:	03e00008 */ 	jr	$ra
/*    4e688:	00000000 */ 	nop
/*    4e68c:	00000000 */ 	nop
);
