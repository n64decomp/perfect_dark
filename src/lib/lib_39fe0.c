#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3a100.h"
#include "data.h"
#include "types.h"

const u32 var70054a80[] = {0x3f8012ef};
const u32 var70054a84[] = {0x3f7fda28};

GLOBAL_ASM(
glabel alCents2Ratio
/*    39fe0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    39fe4:	3c013f80 */ 	lui	$at,0x3f80
/*    39fe8:	44812000 */ 	mtc1	$at,$f4
/*    39fec:	00000000 */ 	nop
/*    39ff0:	e7a40000 */ 	swc1	$f4,0x0($sp)
/*    39ff4:	04800005 */ 	bltz	$a0,.L0003a00c
/*    39ff8:	00000000 */ 	nop
/*    39ffc:	3c017005 */ 	lui	$at,%hi(var70054a80)
/*    3a000:	c4264a80 */ 	lwc1	$f6,%lo(var70054a80)($at)
/*    3a004:	10000005 */ 	b	.L0003a01c
/*    3a008:	e7a60004 */ 	swc1	$f6,0x4($sp)
.L0003a00c:
/*    3a00c:	3c017005 */ 	lui	$at,%hi(var70054a84)
/*    3a010:	c4284a84 */ 	lwc1	$f8,%lo(var70054a84)($at)
/*    3a014:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*    3a018:	00042023 */ 	negu	$a0,$a0
.L0003a01c:
/*    3a01c:	1080000e */ 	beqz	$a0,.L0003a058
/*    3a020:	00000000 */ 	nop
.L0003a024:
/*    3a024:	308e0001 */ 	andi	$t6,$a0,0x1
/*    3a028:	11c00005 */ 	beqz	$t6,.L0003a040
/*    3a02c:	00000000 */ 	nop
/*    3a030:	c7aa0000 */ 	lwc1	$f10,0x0($sp)
/*    3a034:	c7b00004 */ 	lwc1	$f16,0x4($sp)
/*    3a038:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    3a03c:	e7b20000 */ 	swc1	$f18,0x0($sp)
.L0003a040:
/*    3a040:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3a044:	46042182 */ 	mul.s	$f6,$f4,$f4
/*    3a048:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    3a04c:	00042043 */ 	sra	$a0,$a0,0x1
/*    3a050:	1480fff4 */ 	bnez	$a0,.L0003a024
/*    3a054:	00000000 */ 	nop
.L0003a058:
/*    3a058:	10000003 */ 	b	.L0003a068
/*    3a05c:	c7a00000 */ 	lwc1	$f0,0x0($sp)
/*    3a060:	10000001 */ 	b	.L0003a068
/*    3a064:	00000000 */ 	nop
.L0003a068:
/*    3a068:	03e00008 */ 	jr	$ra
/*    3a06c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);
