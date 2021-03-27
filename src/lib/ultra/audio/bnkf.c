#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_37650.h"
#include "lib/lib_3c4d0.h"
#include "data.h"
#include "types.h"

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
/*    377a8:	0c00ddfa */ 	jal	func000377e8
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

GLOBAL_ASM(
glabel func000377e8
/*    377e8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    377ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    377f0:	afa40020 */ 	sw	$a0,0x20($sp)
/*    377f4:	afa50024 */ 	sw	$a1,0x24($sp)
/*    377f8:	afa60028 */ 	sw	$a2,0x28($sp)
/*    377fc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37800:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    37804:	11e00003 */ 	beqz	$t7,.L00037814
/*    37808:	00000000 */ 	nop
/*    3780c:	10000038 */ 	b	.L000378f0
/*    37810:	00000000 */ 	nop
.L00037814:
/*    37814:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37818:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3781c:	a3380002 */ 	sb	$t8,0x2($t9)
/*    37820:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    37824:	8d090008 */ 	lw	$t1,0x8($t0)
/*    37828:	1120000b */ 	beqz	$t1,.L00037858
/*    3782c:	00000000 */ 	nop
/*    37830:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    37834:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    37838:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    3783c:	016c6821 */ 	addu	$t5,$t3,$t4
/*    37840:	ad4d0008 */ 	sw	$t5,0x8($t2)
/*    37844:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37848:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3784c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    37850:	0c00de40 */ 	jal	_bnkfPatchInst
/*    37854:	8dc40008 */ 	lw	$a0,0x8($t6)
.L00037858:
/*    37858:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3785c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37860:	85f80000 */ 	lh	$t8,0x0($t7)
/*    37864:	1b000020 */ 	blez	$t8,.L000378e8
/*    37868:	00000000 */ 	nop
.L0003786c:
/*    3786c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    37870:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37874:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    37878:	00084880 */ 	sll	$t1,$t0,0x2
/*    3787c:	03295821 */ 	addu	$t3,$t9,$t1
/*    37880:	8d6c000c */ 	lw	$t4,0xc($t3)
/*    37884:	018d5021 */ 	addu	$t2,$t4,$t5
/*    37888:	ad6a000c */ 	sw	$t2,0xc($t3)
/*    3788c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    37890:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37894:	000fc080 */ 	sll	$t8,$t7,0x2
/*    37898:	01d84021 */ 	addu	$t0,$t6,$t8
/*    3789c:	8d19000c */ 	lw	$t9,0xc($t0)
/*    378a0:	13200009 */ 	beqz	$t9,.L000378c8
/*    378a4:	00000000 */ 	nop
/*    378a8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    378ac:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    378b0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    378b4:	000c6880 */ 	sll	$t5,$t4,0x2
/*    378b8:	012d5021 */ 	addu	$t2,$t1,$t5
/*    378bc:	8d44000c */ 	lw	$a0,0xc($t2)
/*    378c0:	0c00de40 */ 	jal	_bnkfPatchInst
/*    378c4:	8fa60028 */ 	lw	$a2,0x28($sp)
.L000378c8:
/*    378c8:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    378cc:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    378d0:	256f0001 */ 	addiu	$t7,$t3,0x1
/*    378d4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    378d8:	85d80000 */ 	lh	$t8,0x0($t6)
/*    378dc:	01f8082a */ 	slt	$at,$t7,$t8
/*    378e0:	1420ffe2 */ 	bnez	$at,.L0003786c
/*    378e4:	00000000 */ 	nop
.L000378e8:
/*    378e8:	10000001 */ 	b	.L000378f0
/*    378ec:	00000000 */ 	nop
.L000378f0:
/*    378f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    378f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    378f8:	03e00008 */ 	jr	$ra
/*    378fc:	00000000 */ 	nop
);

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
