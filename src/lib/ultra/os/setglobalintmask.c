#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel __osSetGlobalIntMask
/*    51bc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    51bc4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    51bc8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    51bcc:	0c01256c */ 	jal	__osDisableInt
/*    51bd0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    51bd4:	3c0e8006 */ 	lui	$t6,%hi(__osGlobalIntMask)
/*    51bd8:	8dcecf70 */ 	lw	$t6,%lo(__osGlobalIntMask)($t6)
/*    51bdc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    51be0:	00408025 */ 	or	$s0,$v0,$zero
/*    51be4:	3c018006 */ 	lui	$at,%hi(__osGlobalIntMask)
/*    51be8:	01cfc025 */ 	or	$t8,$t6,$t7
/*    51bec:	ac38cf70 */ 	sw	$t8,%lo(__osGlobalIntMask)($at)
/*    51bf0:	0c012588 */ 	jal	__osRestoreInt
/*    51bf4:	02002025 */ 	or	$a0,$s0,$zero
/*    51bf8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    51bfc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    51c00:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    51c04:	03e00008 */ 	jr	$ra
/*    51c08:	00000000 */ 	nop
/*    51c0c:	00000000 */ 	nop
);
