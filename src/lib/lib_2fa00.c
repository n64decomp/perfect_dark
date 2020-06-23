#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_0c000.h"
#include "lib/lib_4e690.h"
#include "types.h"

GLOBAL_ASM(
glabel func0002fa00
/*    2fa00:	03e00008 */ 	jr	$ra
/*    2fa04:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002fa08
/*    2fa08:	03e00008 */ 	jr	$ra
/*    2fa0c:	24020001 */ 	addiu	$v0,$zero,0x1
/*    2fa10:	03e00008 */ 	jr	$ra
/*    2fa14:	2402ffff */ 	addiu	$v0,$zero,-1
/*    2fa18:	03e00008 */ 	jr	$ra
/*    2fa1c:	00000000 */ 	nop
/*    2fa20:	03e00008 */ 	jr	$ra
/*    2fa24:	00000000 */ 	nop
/*    2fa28:	03e00008 */ 	jr	$ra
/*    2fa2c:	00000000 */ 	nop
/*    2fa30:	03e00008 */ 	jr	$ra
/*    2fa34:	00000000 */ 	nop
/*    2fa38:	03e00008 */ 	jr	$ra
/*    2fa3c:	00000000 */ 	nop
/*    2fa40:	03e00008 */ 	jr	$ra
/*    2fa44:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002fa48
/*    2fa48:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    2fa4c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    2fa50:	afb00018 */ 	sw	$s0,0x18($sp)
/*    2fa54:	00c09025 */ 	or	$s2,$a2,$zero
/*    2fa58:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    2fa5c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    2fa60:	afa40028 */ 	sw	$a0,0x28($sp)
/*    2fa64:	10c00008 */ 	beqz	$a2,.L0002fa88
/*    2fa68:	00008025 */ 	or	$s0,$zero,$zero
/*    2fa6c:	00a08825 */ 	or	$s1,$a1,$zero
/*    2fa70:	92240000 */ 	lbu	$a0,0x0($s1)
.L0002fa74:
/*    2fa74:	26100001 */ 	addiu	$s0,$s0,0x1
/*    2fa78:	0c00330d */ 	jal	func0000cc34
/*    2fa7c:	26310001 */ 	addiu	$s1,$s1,0x1
/*    2fa80:	5612fffc */ 	bnel	$s0,$s2,.L0002fa74
/*    2fa84:	92240000 */ 	lbu	$a0,0x0($s1)
.L0002fa88:
/*    2fa88:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    2fa8c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    2fa90:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    2fa94:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    2fa98:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    2fa9c:	03e00008 */ 	jr	$ra
/*    2faa0:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func0002faa4
/*    2faa4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2faa8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    2faac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2fab0:	afa50024 */ 	sw	$a1,0x24($sp)
/*    2fab4:	afa60028 */ 	sw	$a2,0x28($sp)
/*    2fab8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    2fabc:	3c047003 */ 	lui	$a0,%hi(func0002fa48)
/*    2fac0:	2484fa48 */ 	addiu	$a0,$a0,%lo(func0002fa48)
/*    2fac4:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    2fac8:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    2facc:	0c013b40 */ 	jal	_Printf
/*    2fad0:	00002825 */ 	or	$a1,$zero,$zero
/*    2fad4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2fad8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    2fadc:	03e00008 */ 	jr	$ra
/*    2fae0:	00000000 */ 	nop
/*    2fae4:	00000000 */ 	nop
/*    2fae8:	00000000 */ 	nop
/*    2faec:	00000000 */ 	nop
);
