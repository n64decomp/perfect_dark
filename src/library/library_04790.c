#include <ultra64.h>
#include "types.h"
#include "library/library_4a360.h"

GLOBAL_ASM(
glabel func00004790
/*     4790:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     4794:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     4798:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*     479c:	c4ae0000 */ 	lwc1	$f14,0x0($a1)
/*     47a0:	c4c00000 */ 	lwc1	$f0,0x0($a2)
/*     47a4:	46021102 */ 	mul.s	$f4,$f2,$f2
/*     47a8:	afa60020 */ 	sw	$a2,0x20($sp)
/*     47ac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*     47b0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*     47b4:	afa40018 */ 	sw	$a0,0x18($sp)
/*     47b8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*     47bc:	46062200 */ 	add.s	$f8,$f4,$f6
/*     47c0:	0c012974 */ 	jal	sqrtf
/*     47c4:	46085300 */ 	add.s	$f12,$f10,$f8
/*     47c8:	44801000 */ 	mtc1	$zero,$f2
/*     47cc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*     47d0:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*     47d4:	4600103c */ 	c.lt.s	$f2,$f0
/*     47d8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*     47dc:	3c013f80 */ 	lui	$at,0x3f80
/*     47e0:	4502000f */ 	bc1fl	.L00004820
/*     47e4:	44819000 */ 	mtc1	$at,$f18
/*     47e8:	3c013f80 */ 	lui	$at,0x3f80
/*     47ec:	44818000 */ 	mtc1	$at,$f16
/*     47f0:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*     47f4:	46008083 */ 	div.s	$f2,$f16,$f0
/*     47f8:	46029102 */ 	mul.s	$f4,$f18,$f2
/*     47fc:	e4840000 */ 	swc1	$f4,0x0($a0)
/*     4800:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*     4804:	46023282 */ 	mul.s	$f10,$f6,$f2
/*     4808:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*     480c:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*     4810:	46024402 */ 	mul.s	$f16,$f8,$f2
/*     4814:	10000005 */ 	beqz	$zero,.L0000482c
/*     4818:	e4d00000 */ 	swc1	$f16,0x0($a2)
/*     481c:	44819000 */ 	mtc1	$at,$f18
.L00004820:
/*     4820:	e4820000 */ 	swc1	$f2,0x0($a0)
/*     4824:	e4a20000 */ 	swc1	$f2,0x0($a1)
/*     4828:	e4d20000 */ 	swc1	$f18,0x0($a2)
.L0000482c:
/*     482c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     4830:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     4834:	03e00008 */ 	jr	$ra
/*     4838:	00000000 */ 	sll	$zero,$zero,0x0
/*     483c:	00000000 */ 	sll	$zero,$zero,0x0
);