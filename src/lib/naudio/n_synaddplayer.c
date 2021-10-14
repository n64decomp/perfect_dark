#include <os_internal.h>
#include "n_synthInternals.h"

void n_alSynAddPlayer(ALPlayer *client)
{
	OSIntMask mask = osSetIntMask(OS_IM_NONE);

	client->samplesLeft = n_syn->curSamples;

	client->next = n_syn->head;
	n_syn->head = client;

	osSetIntMask(mask);
}

void n_alSynAddSndPlayer(ALPlayer *client)
{
	OSIntMask mask = osSetIntMask(OS_IM_NONE);

	client->samplesLeft = n_syn->curSamples;

	client->next = n_syn->head;
	n_syn->head = client;

	osSetIntMask(mask);
}

GLOBAL_ASM(
glabel n_alSynAddSeqPlayer
/*    3c970:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c978:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c97c:	0c012194 */ 	jal	osSetIntMask
/*    3c980:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c984:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c988:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    3c98c:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    3c990:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c994:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c998:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c99c:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    3c9a0:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    3c9a4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c9a8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c9ac:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c9b0:	3c0b8006 */ 	lui	$t3,%hi(n_syn)
/*    3c9b4:	8d6bf114 */ 	lw	$t3,%lo(n_syn)($t3)
/*    3c9b8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c9bc:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c9c0:	0c012194 */ 	jal	osSetIntMask
/*    3c9c4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c9c8:	10000001 */ 	b	.L0003c9d0
/*    3c9cc:	00000000 */ 	nop
.L0003c9d0:
/*    3c9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c9d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c9d8:	03e00008 */ 	jr	$ra
/*    3c9dc:	00000000 */ 	nop
);
