#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_4b5e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004cde0
/*    4cde0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    4cde4:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4cde8:	30b000ff */ 	andi	$s0,$a1,0xff
/*    4cdec:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4cdf0:	afa40058 */ 	sw	$a0,0x58($sp)
/*    4cdf4:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    4cdf8:	27a20038 */ 	addiu	$v0,$sp,0x38
/*    4cdfc:	27a30058 */ 	addiu	$v1,$sp,0x58
.L0004ce00:
/*    4ce00:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4ce04:	a050fffd */ 	sb	$s0,-0x3($v0)
/*    4ce08:	a050fffe */ 	sb	$s0,-0x2($v0)
/*    4ce0c:	a050ffff */ 	sb	$s0,-0x1($v0)
/*    4ce10:	1443fffb */ 	bne	$v0,$v1,.L0004ce00
/*    4ce14:	a050fffc */ 	sb	$s0,-0x4($v0)
/*    4ce18:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    4ce1c:	24060400 */ 	addiu	$a2,$zero,0x400
/*    4ce20:	27a70038 */ 	addiu	$a3,$sp,0x38
/*    4ce24:	8dc40004 */ 	lw	$a0,0x4($t6)
/*    4ce28:	8dc50008 */ 	lw	$a1,0x8($t6)
/*    4ce2c:	0c012d84 */ 	jal	__osContRamWrite
/*    4ce30:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4ce34:	14400003 */ 	bnez	$v0,.L0004ce44
/*    4ce38:	00401825 */ 	or	$v1,$v0,$zero
/*    4ce3c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    4ce40:	a1f00065 */ 	sb	$s0,0x65($t7)
.L0004ce44:
/*    4ce44:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4ce48:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4ce4c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    4ce50:	03e00008 */ 	jr	$ra
/*    4ce54:	00601025 */ 	or	$v0,$v1,$zero
/*    4ce58:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ce5c:	00000000 */ 	sll	$zero,$zero,0x0
);