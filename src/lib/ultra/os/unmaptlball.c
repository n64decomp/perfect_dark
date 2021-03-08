#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel osUnmapTLBAll
/*    52080:	40085000 */ 	mfc0	$t0,$10
/*    52084:	2409001e */ 	li	$t1,0x1e
/*    52088:	3c0a8000 */ 	lui	$t2,0x8000
/*    5208c:	408a5000 */ 	mtc0	$t2,$10
/*    52090:	40801000 */ 	mtc0	$zero,$2
/*    52094:	40801800 */ 	mtc0	$zero,$3
.PF00052098:
/*    52098:	40890000 */ 	mtc0	$t1,$0
/*    5209c:	00000000 */ 	nop
/*    520a0:	42000002 */ 	tlbwi
/*    520a4:	00000000 */ 	nop
/*    520a8:	00000000 */ 	nop
/*    520ac:	2129ffff */ 	addi	$t1,$t1,-1
/*    520b0:	0521fff9 */ 	bgez	$t1,.PF00052098
/*    520b4:	00000000 */ 	nop
/*    520b8:	40885000 */ 	mtc0	$t0,$10
/*    520bc:	03e00008 */ 	jr	$ra
/*    520c0:	00000000 */ 	nop
);
