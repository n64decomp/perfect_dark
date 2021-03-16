#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osDisableInt
/*    495b0:	3c0a8006 */ 	lui	$t2,%hi(__osGlobalIntMask)
/*    495b4:	254acf70 */ 	addiu	$t2,$t2,%lo(__osGlobalIntMask)
/*    495b8:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    495bc:	316bff00 */ 	andi	$t3,$t3,0xff00
/*    495c0:	40086000 */ 	mfc0	$t0,$12
/*    495c4:	2401fffe */ 	addiu	$at,$zero,-2
/*    495c8:	01014824 */ 	and	$t1,$t0,$at
/*    495cc:	40896000 */ 	mtc0	$t1,$12
/*    495d0:	31020001 */ 	andi	$v0,$t0,0x1
/*    495d4:	8d480000 */ 	lw	$t0,0x0($t2)
/*    495d8:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*    495dc:	110b000e */ 	beq	$t0,$t3,.L00049618
/*    495e0:	3c0a8006 */ 	lui	$t2,%hi(__osRunningThread)
/*    495e4:	254a0940 */ 	addiu	$t2,$t2,%lo(__osRunningThread)
/*    495e8:	8d490118 */ 	lw	$t1,0x118($t2)
/*    495ec:	312aff00 */ 	andi	$t2,$t1,0xff00
/*    495f0:	01485024 */ 	and	$t2,$t2,$t0
/*    495f4:	3c01ffff */ 	lui	$at,0xffff
/*    495f8:	342100ff */ 	ori	$at,$at,0xff
/*    495fc:	01214824 */ 	and	$t1,$t1,$at
/*    49600:	012a4825 */ 	or	$t1,$t1,$t2
/*    49604:	2401fffe */ 	addiu	$at,$zero,-2
/*    49608:	01214824 */ 	and	$t1,$t1,$at
/*    4960c:	40896000 */ 	mtc0	$t1,$12
/*    49610:	00000000 */ 	nop
/*    49614:	00000000 */ 	nop
.L00049618:
/*    49618:	03e00008 */ 	jr	$ra
/*    4961c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osRestoreInt
/*    49620:	40086000 */ 	mfc0	$t0,$12
/*    49624:	01044025 */ 	or	$t0,$t0,$a0
/*    49628:	40886000 */ 	mtc0	$t0,$12
/*    4962c:	00000000 */ 	nop
/*    49630:	00000000 */ 	nop
/*    49634:	03e00008 */ 	jr	$ra
/*    49638:	00000000 */ 	nop
);
