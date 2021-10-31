#include <ultra64.h>
#include <n_libaudio.h>
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

void func00039d68(N_ALCSPlayer *seqp, u32 status)
{
	n_alCSPSendMidi(seqp, 0, status | 0xb0, 0xfc, 0);
}

void func00039dac(N_ALCSPlayer *seqp, u32 arg1)
{
	seqp->chanMask |= 1 << arg1;

	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0xfc, 0xff);
}

void func00039e10(N_ALCSPlayer *seqp, u32 arg1, u8 arg2)
{
	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0xff, arg2);
}

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
);

void func00039ecc(N_ALCSPlayer *seqp, u32 arg1, u8 arg2)
{
	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0x41, arg2);
}

void func00039f18(N_ALCSPlayer *seqp, u32 arg1, u8 arg2)
{
	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0xfc, arg2);
}
