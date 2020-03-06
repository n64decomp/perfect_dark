#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e730.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003cdc0
/*    3cdc0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3cdc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cdc8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3cdcc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3cdd0:	afa60028 */ 	sw	$a2,0x28($sp)
/*    3cdd4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    3cdd8:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3cddc:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3cde0:	11e0003c */ 	beqz	$t7,.L0003ced4
/*    3cde4:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cde8:	0c00c541 */ 	jal	func00031504
/*    3cdec:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cdf0:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3cdf4:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3cdf8:	17000003 */ 	bnez	$t8,.L0003ce08
/*    3cdfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    3ce00:	10000036 */ 	beqz	$zero,.L0003cedc
/*    3ce04:	00000000 */ 	sll	$zero,$zero,0x0
.L0003ce08:
/*    3ce08:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3ce0c:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3ce10:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3ce14:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3ce18:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3ce1c:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3ce20:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3ce24:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3ce28:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3ce2c:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    3ce30:	adc00000 */ 	sw	$zero,0x0($t6)
/*    3ce34:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3ce38:	240f000d */ 	addiu	$t7,$zero,0xd
/*    3ce3c:	a70f0008 */ 	sh	$t7,0x8($t8)
/*    3ce40:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3ce44:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3ce48:	8729001a */ 	lh	$t1,0x1a($t9)
/*    3ce4c:	a549000a */ 	sh	$t1,0xa($t2)
/*    3ce50:	93a80033 */ 	lbu	$t0,0x33($sp)
/*    3ce54:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3ce58:	a1680012 */ 	sb	$t0,0x12($t3)
/*    3ce5c:	87ac002e */ 	lh	$t4,0x2e($sp)
/*    3ce60:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3ce64:	a5ac0010 */ 	sh	$t4,0x10($t5)
/*    3ce68:	93ae0037 */ 	lbu	$t6,0x37($sp)
/*    3ce6c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3ce70:	a1ee0013 */ 	sb	$t6,0x13($t7)
/*    3ce74:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*    3ce78:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3ce7c:	e704000c */ 	swc1	$f4,0xc($t8)
/*    3ce80:	93b90043 */ 	lbu	$t9,0x43($sp)
/*    3ce84:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3ce88:	a1390014 */ 	sb	$t9,0x14($t1)
/*    3ce8c:	93aa003b */ 	lbu	$t2,0x3b($sp)
/*    3ce90:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    3ce94:	a10a0015 */ 	sb	$t2,0x15($t0)
/*    3ce98:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*    3ce9c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    3cea0:	e5660018 */ 	swc1	$f6,0x18($t3)
/*    3cea4:	0c00c5a6 */ 	jal	func00031698
/*    3cea8:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    3ceac:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    3ceb0:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    3ceb4:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    3ceb8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    3cebc:	adcd0020 */ 	sw	$t5,0x20($t6)
/*    3cec0:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cec4:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cec8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3cecc:	0c00fc79 */ 	jal	func0003f1e4
/*    3ced0:	8de40008 */ 	lw	$a0,0x8($t7)
.L0003ced4:
/*    3ced4:	10000001 */ 	beqz	$zero,.L0003cedc
/*    3ced8:	00000000 */ 	sll	$zero,$zero,0x0
.L0003cedc:
/*    3cedc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cee0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3cee4:	03e00008 */ 	jr	$ra
/*    3cee8:	00000000 */ 	sll	$zero,$zero,0x0
/*    3ceec:	00000000 */ 	sll	$zero,$zero,0x0
);