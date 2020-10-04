#include <libultra_internal.h>

GLOBAL_ASM(
glabel osPiGetCmdQueue
/*    52040:	3c0e8006 */ 	lui	$t6,%hi(__osPiDevMgr)
/*    52044:	8dcecf00 */ 	lw	$t6,%lo(__osPiDevMgr)($t6)
/*    52048:	15c00003 */ 	bnez	$t6,.L00052058
/*    5204c:	00000000 */ 	nop
/*    52050:	03e00008 */ 	jr	$ra
/*    52054:	00001025 */ 	or	$v0,$zero,$zero
.L00052058:
/*    52058:	3c028006 */ 	lui	$v0,%hi(__osPiDevMgr+0x8)
/*    5205c:	8c42cf08 */ 	lw	$v0,%lo(__osPiDevMgr+0x8)($v0)
/*    52060:	03e00008 */ 	jr	$ra
/*    52064:	00000000 */ 	nop
/*    52068:	00000000 */ 	nop
/*    5206c:	00000000 */ 	nop
);
