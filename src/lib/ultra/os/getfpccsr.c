#include <ultra64.h>

GLOBAL_ASM(
glabel __osGetFpcCsr
/*    481d0:	4442f800 */ 	cfc1	$v0,$31
/*    481d4:	03e00008 */ 	jr	$ra
/*    481d8:	00000000 */ 	nop
/*    481dc:	00000000 */ 	nop
);
