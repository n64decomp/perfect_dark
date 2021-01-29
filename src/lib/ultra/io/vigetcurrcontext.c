#include <ultra64.h>

GLOBAL_ASM(
glabel __osViGetCurrentContext
/*    49780:	3c028006 */ 	lui	$v0,%hi(__osViCurr)
/*    49784:	03e00008 */ 	jr	$ra
/*    49788:	8c420910 */ 	lw	$v0,%lo(__osViCurr)($v0)
/*    4978c:	00000000 */ 	nop
);
