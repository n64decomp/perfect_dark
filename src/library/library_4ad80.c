#include <ultra64.h>
#include "types.h"

GLOBAL_ASM(
glabel func0004ad80
/*    4ad80:	18a00011 */ 	blez	$a1,.L0004adc8
/*    4ad84:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ad88:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*    4ad8c:	00ab082b */ 	sltu	$at,$a1,$t3
/*    4ad90:	1020000f */ 	beqz	$at,.L0004add0
/*    4ad94:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ad98:	00804025 */ 	or	$t0,$a0,$zero
/*    4ad9c:	00854821 */ 	addu	$t1,$a0,$a1
/*    4ada0:	0109082b */ 	sltu	$at,$t0,$t1
/*    4ada4:	10200008 */ 	beqz	$at,.L0004adc8
/*    4ada8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4adac:	310a000f */ 	andi	$t2,$t0,0xf
/*    4adb0:	2529fff0 */ 	addiu	$t1,$t1,-16
/*    4adb4:	010a4023 */ 	subu	$t0,$t0,$t2
.L0004adb8:
/*    4adb8:	bd190000 */ 	cache	0x19,0x0($t0)
/*    4adbc:	0109082b */ 	sltu	$at,$t0,$t1
/*    4adc0:	1420fffd */ 	bnez	$at,.L0004adb8
/*    4adc4:	25080010 */ 	addiu	$t0,$t0,0x10
.L0004adc8:
/*    4adc8:	03e00008 */ 	jr	$ra
/*    4adcc:	00000000 */ 	sll	$zero,$zero,0x0
.L0004add0:
/*    4add0:	3c088000 */ 	lui	$t0,0x8000
/*    4add4:	010b4821 */ 	addu	$t1,$t0,$t3
/*    4add8:	2529fff0 */ 	addiu	$t1,$t1,-16
.L0004addc:
/*    4addc:	bd010000 */ 	cache	0x1,0x0($t0)
/*    4ade0:	0109082b */ 	sltu	$at,$t0,$t1
/*    4ade4:	1420fffd */ 	bnez	$at,.L0004addc
/*    4ade8:	25080010 */ 	addiu	$t0,$t0,0x10
/*    4adec:	03e00008 */ 	jr	$ra
/*    4adf0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4adf4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4adf8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4adfc:	00000000 */ 	sll	$zero,$zero,0x0
);