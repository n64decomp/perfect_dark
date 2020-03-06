#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048830
/*    48830:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48834:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48838:	0c01256c */ 	jal	__osDisableInt
/*    4883c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48840:	3c0e8006 */ 	lui	$t6,%hi(var80060910)
/*    48844:	8dce0910 */ 	lw	$t6,%lo(var80060910)($t6)
/*    48848:	00408025 */ 	or	$s0,$v0,$zero
/*    4884c:	02002025 */ 	or	$a0,$s0,$zero
/*    48850:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    48854:	0c012588 */ 	jal	__osRestoreInt
/*    48858:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    4885c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48860:	8fa20020 */ 	lw	$v0,0x20($sp)
/*    48864:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48868:	03e00008 */ 	jr	$ra
/*    4886c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func00048870
/*    48870:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48874:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48878:	0c01256c */ 	jal	__osDisableInt
/*    4887c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48880:	3c0e8006 */ 	lui	$t6,%hi(var80060914)
/*    48884:	8dce0914 */ 	lw	$t6,%lo(var80060914)($t6)
/*    48888:	00408025 */ 	or	$s0,$v0,$zero
/*    4888c:	02002025 */ 	or	$a0,$s0,$zero
/*    48890:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    48894:	0c012588 */ 	jal	__osRestoreInt
/*    48898:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    4889c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    488a0:	8fa20020 */ 	lw	$v0,0x20($sp)
/*    488a4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    488a8:	03e00008 */ 	jr	$ra
/*    488ac:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func000488b0
/*    488b0:	3c0ea410 */ 	lui	$t6,0xa410
/*    488b4:	03e00008 */ 	jr	$ra
/*    488b8:	adc4000c */ 	sw	$a0,0xc($t6)
/*    488bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000488c0
/*    488c0:	14800003 */ 	bnez	$a0,.L000488d0
/*    488c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    488c8:	3c048006 */ 	lui	$a0,%hi(var80060940)
/*    488cc:	8c840940 */ 	lw	$a0,%lo(var80060940)($a0)
.L000488d0:
/*    488d0:	03e00008 */ 	jr	$ra
/*    488d4:	8c820004 */ 	lw	$v0,0x4($a0)
/*    488d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    488dc:	00000000 */ 	sll	$zero,$zero,0x0
);