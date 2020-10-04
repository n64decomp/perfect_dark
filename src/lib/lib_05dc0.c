#include <ultra64.h>

GLOBAL_ASM(
glabel func00005dc0
/*     5dc0:	3c028009 */ 	lui	$v0,%hi(var800902a0)
/*     5dc4:	244202a0 */ 	addiu	$v0,$v0,%lo(var800902a0)
/*     5dc8:	24030007 */ 	addiu	$v1,$zero,0x7
/*     5dcc:	a0430004 */ 	sb	$v1,0x4($v0)
/*     5dd0:	3c0ea460 */ 	lui	$t6,0xa460
/*     5dd4:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*     5dd8:	3c18a460 */ 	lui	$t8,0xa460
/*     5ddc:	3c08a460 */ 	lui	$t0,0xa460
/*     5de0:	a04f0005 */ 	sb	$t7,0x5($v0)
/*     5de4:	8f190018 */ 	lw	$t9,0x18($t8)
/*     5de8:	3c0aa460 */ 	lui	$t2,0xa460
/*     5dec:	3c048009 */ 	lui	$a0,%hi(var80090318)
/*     5df0:	a0590008 */ 	sb	$t9,0x8($v0)
/*     5df4:	8d09001c */ 	lw	$t1,0x1c($t0)
/*     5df8:	24840318 */ 	addiu	$a0,$a0,%lo(var80090318)
/*     5dfc:	3c0ca460 */ 	lui	$t4,0xa460
/*     5e00:	a0490006 */ 	sb	$t1,0x6($v0)
/*     5e04:	8d4b0020 */ 	lw	$t3,0x20($t2)
/*     5e08:	a0830004 */ 	sb	$v1,0x4($a0)
/*     5e0c:	a04b0007 */ 	sb	$t3,0x7($v0)
/*     5e10:	8d8d0024 */ 	lw	$t5,0x24($t4)
/*     5e14:	a08d0005 */ 	sb	$t5,0x5($a0)
/*     5e18:	8dcf0028 */ 	lw	$t7,0x28($t6)
/*     5e1c:	a08f0008 */ 	sb	$t7,0x8($a0)
/*     5e20:	8f19002c */ 	lw	$t9,0x2c($t8)
/*     5e24:	a0990006 */ 	sb	$t9,0x6($a0)
/*     5e28:	8d090030 */ 	lw	$t1,0x30($t0)
/*     5e2c:	03e00008 */ 	jr	$ra
/*     5e30:	a0890007 */ 	sb	$t1,0x7($a0)
/*     5e34:	00000000 */ 	nop
/*     5e38:	00000000 */ 	nop
/*     5e3c:	00000000 */ 	nop
);
