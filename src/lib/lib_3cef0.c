#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003cef0
/*    3cef0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3cef4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cef8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3cefc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3cf00:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3cf04:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3cf08:	11e0001f */ 	beqz	$t7,.L0003cf88
/*    3cf0c:	00000000 */ 	nop
/*    3cf10:	0c00c541 */ 	jal	__n_allocParam
/*    3cf14:	00000000 */ 	nop
/*    3cf18:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3cf1c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3cf20:	17000003 */ 	bnez	$t8,.L0003cf30
/*    3cf24:	00000000 */ 	nop
/*    3cf28:	10000019 */ 	b	.L0003cf90
/*    3cf2c:	00000000 */ 	nop
.L0003cf30:
/*    3cf30:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3cf34:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    3cf38:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    3cf3c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3cf40:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3cf44:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3cf48:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cf4c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3cf50:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3cf54:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3cf58:	240e000c */ 	addiu	$t6,$zero,0xc
/*    3cf5c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3cf60:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3cf64:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3cf68:	af38000c */ 	sw	$t8,0xc($t9)
/*    3cf6c:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3cf70:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3cf74:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cf78:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cf7c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3cf80:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3cf84:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003cf88:
/*    3cf88:	10000001 */ 	b	.L0003cf90
/*    3cf8c:	00000000 */ 	nop
.L0003cf90:
/*    3cf90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cf94:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3cf98:	03e00008 */ 	jr	$ra
/*    3cf9c:	00000000 */ 	nop
);
