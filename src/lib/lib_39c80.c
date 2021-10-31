#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_43dd0.h"
#include "data.h"
#include "types.h"

void func00039cd0(N_ALCSPlayer *seqp)
{
	s32 i;

	seqp->chanMask = 0xffff;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].unk0e = 0xff;
		seqp->chanState[i].unk0d = 0xff;
	}
}

GLOBAL_ASM(
glabel func00039d68
/*    39d68:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39d6c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39d70:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39d74:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39d78:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39d7c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39d80:	00002825 */ 	or	$a1,$zero,$zero
/*    39d84:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39d88:	afa00010 */ 	sw	$zero,0x10($sp)
/*    39d8c:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39d90:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39d94:	10000001 */ 	b	.L00039d9c
/*    39d98:	00000000 */ 	nop
.L00039d9c:
/*    39d9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39da0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39da4:	03e00008 */ 	jr	$ra
/*    39da8:	00000000 */ 	nop
/*    39dac:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39db0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39db4:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39db8:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39dbc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    39dc0:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    39dc4:	24190001 */ 	addiu	$t9,$zero,0x1
/*    39dc8:	95cf0030 */ 	lhu	$t7,0x30($t6)
/*    39dcc:	03194004 */ 	sllv	$t0,$t9,$t8
/*    39dd0:	01e84825 */ 	or	$t1,$t7,$t0
/*    39dd4:	a5c90030 */ 	sh	$t1,0x30($t6)
/*    39dd8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39ddc:	240a00ff */ 	addiu	$t2,$zero,0xff
/*    39de0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    39de4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39de8:	00002825 */ 	or	$a1,$zero,$zero
/*    39dec:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39df0:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39df4:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39df8:	10000001 */ 	b	.L00039e00
/*    39dfc:	00000000 */ 	nop
.L00039e00:
/*    39e00:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39e04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39e08:	03e00008 */ 	jr	$ra
/*    39e0c:	00000000 */ 	nop
/*    39e10:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39e14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39e18:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39e1c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39e20:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39e24:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e28:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39e2c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39e30:	00002825 */ 	or	$a1,$zero,$zero
/*    39e34:	240700ff */ 	addiu	$a3,$zero,0xff
/*    39e38:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39e3c:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39e40:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39e44:	10000001 */ 	b	.L00039e4c
/*    39e48:	00000000 */ 	nop
.L00039e4c:
/*    39e4c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39e50:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39e54:	03e00008 */ 	jr	$ra
/*    39e58:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00039e5c
/*    39e5c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39e60:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39e64:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39e68:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39e6c:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39e70:	afa7002c */ 	sw	$a3,0x2c($sp)
/*    39e74:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e78:	93ae002f */ 	lbu	$t6,0x2f($sp)
/*    39e7c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39e80:	00002825 */ 	or	$a1,$zero,$zero
/*    39e84:	240700fd */ 	addiu	$a3,$zero,0xfd
/*    39e88:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39e8c:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39e90:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39e94:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39e98:	93af002b */ 	lbu	$t7,0x2b($sp)
/*    39e9c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39ea0:	00002825 */ 	or	$a1,$zero,$zero
/*    39ea4:	240700ff */ 	addiu	$a3,$zero,0xff
/*    39ea8:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39eac:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39eb0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    39eb4:	10000001 */ 	b	.L00039ebc
/*    39eb8:	00000000 */ 	nop
.L00039ebc:
/*    39ebc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39ec0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39ec4:	03e00008 */ 	jr	$ra
/*    39ec8:	00000000 */ 	nop
/*    39ecc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39ed0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39ed4:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39ed8:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39edc:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39ee0:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39ee4:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39ee8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39eec:	00002825 */ 	or	$a1,$zero,$zero
/*    39ef0:	24070041 */ 	addiu	$a3,$zero,0x41
/*    39ef4:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39ef8:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39efc:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39f00:	10000001 */ 	b	.L00039f08
/*    39f04:	00000000 */ 	nop
.L00039f08:
/*    39f08:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39f0c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39f10:	03e00008 */ 	jr	$ra
/*    39f14:	00000000 */ 	nop
/*    39f18:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    39f1c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    39f20:	afa40020 */ 	sw	$a0,0x20($sp)
/*    39f24:	afa50024 */ 	sw	$a1,0x24($sp)
/*    39f28:	afa60028 */ 	sw	$a2,0x28($sp)
/*    39f2c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    39f30:	93ae002b */ 	lbu	$t6,0x2b($sp)
/*    39f34:	8fa40020 */ 	lw	$a0,0x20($sp)
/*    39f38:	00002825 */ 	or	$a1,$zero,$zero
/*    39f3c:	240700fc */ 	addiu	$a3,$zero,0xfc
/*    39f40:	34c600b0 */ 	ori	$a2,$a2,0xb0
/*    39f44:	0c011194 */ 	jal	n_alCSPSendMidi
/*    39f48:	afae0010 */ 	sw	$t6,0x10($sp)
/*    39f4c:	10000001 */ 	b	.L00039f54
/*    39f50:	00000000 */ 	nop
.L00039f54:
/*    39f54:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    39f58:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    39f5c:	03e00008 */ 	jr	$ra
/*    39f60:	00000000 */ 	nop
);
