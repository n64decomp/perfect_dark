#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_16110.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_44f60.h"
#include "lib/lib_45ed0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_46650.h"
#include "lib/lib_47550.h"
#include "lib/libc/ll.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003e730
/*    3e730:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e734:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e738:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e73c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e740:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e744:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3e748:	11e0001f */ 	beqz	$t7,.L0003e7c8
/*    3e74c:	00000000 */ 	nop
/*    3e750:	0c00c541 */ 	jal	__allocParam
/*    3e754:	00000000 */ 	nop
/*    3e758:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e75c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e760:	17000003 */ 	bnez	$t8,.L0003e770
/*    3e764:	00000000 */ 	nop
/*    3e768:	10000019 */ 	b	.L0003e7d0
/*    3e76c:	00000000 */ 	nop
.L0003e770:
/*    3e770:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e774:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    3e778:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    3e77c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e780:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3e784:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3e788:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3e78c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e790:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3e794:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3e798:	240e0011 */ 	addiu	$t6,$zero,0x11
/*    3e79c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3e7a0:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3e7a4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3e7a8:	af38000c */ 	sw	$t8,0xc($t9)
/*    3e7ac:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3e7b0:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3e7b4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3e7b8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3e7bc:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3e7c0:	0c00fc79 */ 	jal	n_alEnvmixerParam
/*    3e7c4:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003e7c8:
/*    3e7c8:	10000001 */ 	b	.L0003e7d0
/*    3e7cc:	00000000 */ 	nop
.L0003e7d0:
/*    3e7d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e7d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e7d8:	03e00008 */ 	jr	$ra
/*    3e7dc:	00000000 */ 	nop
);

/**
 * Note: If there are no valid tracks (ie. all tracks have
 * reached the end of their data stream), then return FALSE
 * to indicate that there is no next event.
 */
char __alCSeqNextDelta(ALCSeq *seq, s32 *pDeltaTicks)
{
	u32 i;
	u32	firstTime = 0xffffffff;
	u32 lastTicks = seq->lastDeltaTicks;

	if (!seq->validTracks) {
		return FALSE;
	}

	for (i = 0; i < 16; i++) {
		if ((seq->validTracks >> i) & 1) {
			if (seq->deltaFlag) {
				seq->evtDeltaTicks[i] -= lastTicks;
			}

			if (seq->evtDeltaTicks[i] < firstTime) {
				firstTime = seq->evtDeltaTicks[i];
			}
		}
	}

	seq->deltaFlag = 0;
	*pDeltaTicks = firstTime;

	return TRUE;
}
