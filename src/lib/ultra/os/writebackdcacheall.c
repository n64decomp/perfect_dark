#include <ultra64.h>

GLOBAL_ASM(
glabel osWritebackDCacheAll
/*    48120:	3c088000 */ 	lui	$t0,0x8000
/*    48124:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*    48128:	010a4821 */ 	addu	$t1,$t0,$t2
/*    4812c:	2529fff0 */ 	addiu	$t1,$t1,-16
.L00048130:
/*    48130:	bd010000 */ 	cache	0x1,0x0($t0)
/*    48134:	0109082b */ 	sltu	$at,$t0,$t1
/*    48138:	1420fffd */ 	bnez	$at,.L00048130
/*    4813c:	25080010 */ 	addiu	$t0,$t0,0x10
/*    48140:	03e00008 */ 	jr	$ra
/*    48144:	00000000 */ 	nop
);
