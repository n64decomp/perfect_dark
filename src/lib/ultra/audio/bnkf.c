#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_37650.h"
#include "lib/lib_3c4d0.h"
#include "data.h"
#include "types.h"

void _bnkfPatchBank(ALBank *bank, s32 offset, s32 table);
void _bnkfPatchInst(ALInstrument *inst, s32 offset, s32 table);
void _bnkfPatchSound(ALSound *s, s32 offset, s32 table);
void _bnkfPatchWaveTable(ALWaveTable *w, s32 offset, s32 table);

void alSeqFileNew(ALSeqFile *file, u8 *base)
{
	s32 offset = (s32) base;
	s32 i;

	/*
	 * patch the file so that offsets are pointers
	 */
	for (i = 0; i < file->seqCount; i++) {
		file->seqArray[i].offset = (u8 *)((u8 *)file->seqArray[i].offset + offset);
	}
}

GLOBAL_ASM(
glabel func00037704
/*    37704:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    37708:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3770c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    37710:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    37714:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    37718:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3771c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    37720:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    37724:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    37728:	24014231 */ 	addiu	$at,$zero,0x4231
/*    3772c:	87190000 */ 	lh	$t9,0x0($t8)
/*    37730:	13210003 */ 	beq	$t9,$at,.L00037740
/*    37734:	00000000 */ 	nop
/*    37738:	10000027 */ 	b	.L000377d8
/*    3773c:	00000000 */ 	nop
.L00037740:
/*    37740:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    37744:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37748:	85090002 */ 	lh	$t1,0x2($t0)
/*    3774c:	19200020 */ 	blez	$t1,.L000377d0
/*    37750:	00000000 */ 	nop
.L00037754:
/*    37754:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    37758:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3775c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    37760:	000b6080 */ 	sll	$t4,$t3,0x2
/*    37764:	014c6821 */ 	addu	$t5,$t2,$t4
/*    37768:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3776c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    37770:	adb80004 */ 	sw	$t8,0x4($t5)
/*    37774:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    37778:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3777c:	00084880 */ 	sll	$t1,$t0,0x2
/*    37780:	03295821 */ 	addu	$t3,$t9,$t1
/*    37784:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*    37788:	11400009 */ 	beqz	$t2,.L000377b0
/*    3778c:	00000000 */ 	nop
/*    37790:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    37794:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    37798:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3779c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    377a0:	018fc021 */ 	addu	$t8,$t4,$t7
/*    377a4:	8f040004 */ 	lw	$a0,0x4($t8)
/*    377a8:	0c00ddfa */ 	jal	_bnkfPatchBank
/*    377ac:	8fa60020 */ 	lw	$a2,0x20($sp)
.L000377b0:
/*    377b0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    377b4:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    377b8:	25a80001 */ 	addiu	$t0,$t5,0x1
/*    377bc:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    377c0:	87290002 */ 	lh	$t1,0x2($t9)
/*    377c4:	0109082a */ 	slt	$at,$t0,$t1
/*    377c8:	1420ffe2 */ 	bnez	$at,.L00037754
/*    377cc:	00000000 */ 	nop
.L000377d0:
/*    377d0:	10000001 */ 	b	.L000377d8
/*    377d4:	00000000 */ 	nop
.L000377d8:
/*    377d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    377dc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    377e0:	03e00008 */ 	jr	$ra
/*    377e4:	00000000 */ 	nop
);

void _bnkfPatchBank(ALBank *bank, s32 offset, s32 table)
{
	s32 i;

	if (bank->flags) {
		return;
	}

	bank->flags = 1;

	if (bank->percussion) {
		bank->percussion = (ALInstrument *)((u8 *)bank->percussion + offset);
		_bnkfPatchInst(bank->percussion, offset, table);
	}

	for (i = 0; i < bank->instCount; i++) {
		bank->instArray[i] = (ALInstrument *)((u8 *)bank->instArray[i] + offset);

		if (bank->instArray[i]) {
			_bnkfPatchInst(bank->instArray[i], offset, table);
		}
	}
}

void _bnkfPatchInst(ALInstrument *inst, s32 offset, s32 table)
{
	s32 i;

	if (inst->flags) {
		return;
	}

	inst->flags = 1;

	for (i = 0; i < inst->soundCount; i++) {
		inst->soundArray[i] = (ALSound *)((u8 *)inst->soundArray[i] + offset);
		_bnkfPatchSound(inst->soundArray[i], offset, table);
	}
}

void _bnkfPatchSound(ALSound *s, s32 offset, s32 table)
{
	if (s->flags) {
		return;
	}

	s->flags = 1;

	s->envelope = (ALEnvelope *)((u8 *)s->envelope + offset);
	s->keyMap = (ALKeyMap *)((u8 *)s->keyMap + offset);

	s->wavetable = (ALWaveTable *)((u8 *)s->wavetable + offset);
	_bnkfPatchWaveTable(s->wavetable, offset, table);
}

void _bnkfPatchWaveTable(ALWaveTable *w, s32 offset, s32 table)
{
	if (w->flags) {
		return;
	}

	w->flags = 1;

	w->base += table;

	if (w->type == AL_ADPCM_WAVE) {
		w->waveInfo.adpcmWave.book  = (ALADPCMBook *)((u8 *)w->waveInfo.adpcmWave.book + offset);

		if (w->waveInfo.adpcmWave.loop) {
			w->waveInfo.adpcmWave.loop = (ALADPCMloop *)((u8 *)w->waveInfo.adpcmWave.loop + offset);
		}
	} else if (w->type == AL_RAW16_WAVE) {
		if (w->waveInfo.rawWave.loop) {
			w->waveInfo.rawWave.loop = (ALRawLoop *)((u8 *)w->waveInfo.rawWave.loop + offset);
		}
	}
}
