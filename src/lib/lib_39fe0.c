#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_3a100.h"
#include "types.h"

const u32 var70054a80[] = {0x3f8012ef};
const u32 var70054a84[] = {0x3f7fda28};
const u32 var70054a88[] = {0x00000000};
const u32 var70054a8c[] = {0x00000000};

GLOBAL_ASM(
glabel func00039fe0
/*    39fe0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    39fe4:	3c013f80 */ 	lui	$at,0x3f80
/*    39fe8:	44812000 */ 	mtc1	$at,$f4
/*    39fec:	00000000 */ 	sll	$zero,$zero,0x0
/*    39ff0:	e7a40000 */ 	swc1	$f4,0x0($sp)
/*    39ff4:	04800005 */ 	bltz	$a0,.L0003a00c
/*    39ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*    39ffc:	3c017005 */ 	lui	$at,%hi(var70054a80)
/*    3a000:	c4264a80 */ 	lwc1	$f6,%lo(var70054a80)($at)
/*    3a004:	10000005 */ 	beqz	$zero,.L0003a01c
/*    3a008:	e7a60004 */ 	swc1	$f6,0x4($sp)
.L0003a00c:
/*    3a00c:	3c017005 */ 	lui	$at,%hi(var70054a84)
/*    3a010:	c4284a84 */ 	lwc1	$f8,%lo(var70054a84)($at)
/*    3a014:	e7a80004 */ 	swc1	$f8,0x4($sp)
/*    3a018:	00042023 */ 	negu	$a0,$a0
.L0003a01c:
/*    3a01c:	1080000e */ 	beqz	$a0,.L0003a058
/*    3a020:	00000000 */ 	sll	$zero,$zero,0x0
.L0003a024:
/*    3a024:	308e0001 */ 	andi	$t6,$a0,0x1
/*    3a028:	11c00005 */ 	beqz	$t6,.L0003a040
/*    3a02c:	00000000 */ 	sll	$zero,$zero,0x0
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
/*    3a054:	00000000 */ 	sll	$zero,$zero,0x0
.L0003a058:
/*    3a058:	10000003 */ 	beqz	$zero,.L0003a068
/*    3a05c:	c7a00000 */ 	lwc1	$f0,0x0($sp)
/*    3a060:	10000001 */ 	beqz	$zero,.L0003a068
/*    3a064:	00000000 */ 	sll	$zero,$zero,0x0
.L0003a068:
/*    3a068:	03e00008 */ 	jr	$ra
/*    3a06c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003a070
/*    3a070:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3a074:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3a078:	afa40018 */ 	sw	$a0,0x18($sp)
/*    3a07c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    3a080:	afa60020 */ 	sw	$a2,0x20($sp)
/*    3a084:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3a088:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3a08c:	87b8001a */ 	lh	$t8,0x1a($sp)
/*    3a090:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    3a094:	8dcf0034 */ 	lw	$t7,0x34($t6)
/*    3a098:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*    3a09c:	0338c821 */ 	addu	$t9,$t9,$t8
/*    3a0a0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    3a0a4:	01f92021 */ 	addu	$a0,$t7,$t9
/*    3a0a8:	24840024 */ 	addiu	$a0,$a0,0x24
/*    3a0ac:	8fa70020 */ 	lw	$a3,0x20($sp)
/*    3a0b0:	0c00ef14 */ 	jal	func0003bc50
/*    3a0b4:	03003025 */ 	or	$a2,$t8,$zero
/*    3a0b8:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    3a0bc:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    3a0c0:	87aa001a */ 	lh	$t2,0x1a($sp)
/*    3a0c4:	8d090034 */ 	lw	$t1,0x34($t0)
/*    3a0c8:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    3a0cc:	016a5821 */ 	addu	$t3,$t3,$t2
/*    3a0d0:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3a0d4:	012b6021 */ 	addu	$t4,$t1,$t3
/*    3a0d8:	10000003 */ 	beqz	$zero,.L0003a0e8
/*    3a0dc:	8d820024 */ 	lw	$v0,0x24($t4)
/*    3a0e0:	10000001 */ 	beqz	$zero,.L0003a0e8
/*    3a0e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0003a0e8:
/*    3a0e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3a0ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    3a0f0:	03e00008 */ 	jr	$ra
/*    3a0f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    3a0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    3a0fc:	00000000 */ 	sll	$zero,$zero,0x0
);