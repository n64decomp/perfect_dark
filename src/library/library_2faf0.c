#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0002faf0
/*    2faf0:	ac850000 */ 	sw	$a1,0x0($a0)
/*    2faf4:	ac860008 */ 	sw	$a2,0x8($a0)
/*    2faf8:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    2fafc:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*    2fb00:	ac80000c */ 	sw	$zero,0xc($a0)
/*    2fb04:	03e00008 */ 	jr	$ra
/*    2fb08:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fb0c:	03e00008 */ 	jr	$ra
/*    2fb10:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0002fb14
/*    2fb14:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    2fb18:	afa40008 */ 	sw	$a0,0x8($sp)
/*    2fb1c:	afa5000c */ 	sw	$a1,0xc($sp)
/*    2fb20:	afa00000 */ 	sw	$zero,0x0($sp)
/*    2fb24:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    2fb28:	2401fff0 */ 	addiu	$at,$zero,-16
/*    2fb2c:	00ee0019 */ 	multu	$a3,$t6
/*    2fb30:	00007812 */ 	mflo	$t7
/*    2fb34:	25f8000f */ 	addiu	$t8,$t7,0xf
/*    2fb38:	0301c824 */ 	and	$t9,$t8,$at
/*    2fb3c:	afb90004 */ 	sw	$t9,0x4($sp)
/*    2fb40:	8cc80004 */ 	lw	$t0,0x4($a2)
/*    2fb44:	8fa90004 */ 	lw	$t1,0x4($sp)
/*    2fb48:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*    2fb4c:	8ccc0008 */ 	lw	$t4,0x8($a2)
/*    2fb50:	01095021 */ 	addu	$t2,$t0,$t1
/*    2fb54:	016c6821 */ 	addu	$t5,$t3,$t4
/*    2fb58:	01aa082b */ 	sltu	$at,$t5,$t2
/*    2fb5c:	14200008 */ 	bnez	$at,.L0002fb80
/*    2fb60:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fb64:	8cce0004 */ 	lw	$t6,0x4($a2)
/*    2fb68:	afae0000 */ 	sw	$t6,0x0($sp)
/*    2fb6c:	8ccf0004 */ 	lw	$t7,0x4($a2)
/*    2fb70:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    2fb74:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    2fb78:	10000001 */ 	beqz	$zero,.L0002fb80
/*    2fb7c:	acd90004 */ 	sw	$t9,0x4($a2)
.L0002fb80:
/*    2fb80:	10000003 */ 	beqz	$zero,.L0002fb90
/*    2fb84:	8fa20000 */ 	lw	$v0,0x0($sp)
/*    2fb88:	10000001 */ 	beqz	$zero,.L0002fb90
/*    2fb8c:	00000000 */ 	sll	$zero,$zero,0x0
.L0002fb90:
/*    2fb90:	03e00008 */ 	jr	$ra
/*    2fb94:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    2fb98:	00000000 */ 	sll	$zero,$zero,0x0
/*    2fb9c:	00000000 */ 	sll	$zero,$zero,0x0
);