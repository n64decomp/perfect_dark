#include <libultra_internal.h>

GLOBAL_ASM(
glabel __osResetGlobalIntMask
/*    518a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    518a4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    518a8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    518ac:	0c01256c */ 	jal	__osDisableInt
/*    518b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    518b4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    518b8:	3c0e8006 */ 	lui	$t6,%hi(var8005cf70)
/*    518bc:	8dcecf70 */ 	lw	$t6,%lo(var8005cf70)($t6)
/*    518c0:	2401fbfe */ 	addiu	$at,$zero,-1026
/*    518c4:	01e1c024 */ 	and	$t8,$t7,$at
/*    518c8:	0300c827 */ 	nor	$t9,$t8,$zero
/*    518cc:	00408025 */ 	or	$s0,$v0,$zero
/*    518d0:	3c018006 */ 	lui	$at,%hi(var8005cf70)
/*    518d4:	01d94024 */ 	and	$t0,$t6,$t9
/*    518d8:	ac28cf70 */ 	sw	$t0,%lo(var8005cf70)($at)
/*    518dc:	0c012588 */ 	jal	__osRestoreInt
/*    518e0:	02002025 */ 	or	$a0,$s0,$zero
/*    518e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    518e8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    518ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    518f0:	03e00008 */ 	jr	$ra
/*    518f4:	00000000 */ 	nop
/*    518f8:	00000000 */ 	nop
/*    518fc:	00000000 */ 	nop
);
