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

void alBnkfNew(ALBankFile *file, u8 *table)
{
	s32 offset = (s32) file;
	s32 woffset = (s32) table;

	s32 i;

	/*
	 * check the file format revision in debug libraries
	 */
	ALFailIf(file->revision != AL_BANK_VERSION, ERR_ALBNKFNEW);

	/*
	 * patch the file so that offsets are pointers
	 */
	for (i = 0; i < file->bankCount; i++) {
		file->bankArray[i] = (ALBank *)((u8 *)file->bankArray[i] + offset);

		if (file->bankArray[i]) {
			_bnkfPatchBank(file->bankArray[i], offset, woffset);
		}
	}
}

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
