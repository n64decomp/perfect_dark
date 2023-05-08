#include <libaudio.h>
#include "n_libaudio.h"
#include <os_internal.h>
#include <ultraerror.h>

static u32 __n_alCSeqGetTrackEvent(ALCSeq *seq, u32 track, N_ALEvent *event, s32 arg3);
static u8 __getTrackByte(ALCSeq *seq, u32 track);
static u32 __readVarLen(ALCSeq *seq,u32 track);

void n_alCSeqNew(ALCSeq *seq, u8 *ptr)
{
	u32 i, tmpOff, flagTmp;

	/* load the seqence pointed to by ptr   */
	seq->base = (ALCMidiHdr*)ptr;
	seq->validTracks = 0;
	seq->lastDeltaTicks = 0;
	seq->lastTicks = 0;
	seq->deltaFlag = 1;

	for (i = 0; i < 16; i++) {
		seq->lastStatus[i] = 0;
		seq->curBUPtr[i] = 0;
		seq->curBULen[i] = 0;
		tmpOff = seq->base->trackOffset[i];

		if (tmpOff) {
			flagTmp = 1 << i;
			seq->validTracks |= flagTmp;
			seq->curLoc[i] = (u8*)((u32)ptr + tmpOff);
			seq->evtDeltaTicks[i] = __readVarLen(seq,i);
		} else {
			seq->curLoc[i] = 0;
		}
	}

	seq->qnpt = 1.0f / (f32)seq->base->division;
}

void n_alCSeqNextEvent(ALCSeq *seq, N_ALEvent *evt, s32 arg2)
{
	u32 i;
	u32 firstTime = 0xffffffff;
	u32 firstTrack;
	u32 lastTicks = seq->lastDeltaTicks;

	for (i = 0; i < 16; i++) {
		if ((seq->validTracks >> i) & 1) {
			if (seq->deltaFlag) {
				seq->evtDeltaTicks[i] -= lastTicks;
			}

			if (seq->evtDeltaTicks[i] < firstTime) {
				firstTime = seq->evtDeltaTicks[i];
				firstTrack = i;
			}
		}
	}

	__n_alCSeqGetTrackEvent(seq, firstTrack, evt, arg2);

	evt->msg.midi.ticks = firstTime;
	seq->lastTicks += firstTime;
	seq->lastDeltaTicks = firstTime;

	if (evt->type != AL_TRACK_END) {
		seq->evtDeltaTicks[firstTrack] += __readVarLen(seq, firstTrack);
	}

	seq->deltaFlag = 1;
}

static u32 __n_alCSeqGetTrackEvent(ALCSeq *seq, u32 track, N_ALEvent *event, s32 arg3)
{
	u32 offset;
	u8 status, loopCt, curLpCt, *tmpPtr;

	status = __getTrackByte(seq, track);

	if (status == AL_MIDI_Meta) {
		u8 type = __getTrackByte(seq, track);

		if (type == AL_MIDI_META_TEMPO) {
			event->type = AL_TEMPO_EVT;
			event->msg.tempo.status = status;
			event->msg.tempo.type = type;
			event->msg.tempo.byte1 = __getTrackByte(seq, track);
			event->msg.tempo.byte2 = __getTrackByte(seq, track);
			event->msg.tempo.byte3 = __getTrackByte(seq, track);
			seq->lastStatus[track] = 0;  /* lastStatus not supported after meta */
		} else if (type == AL_MIDI_META_EOT) {
			u32 flagMask;

			flagMask = 1 << track;
			seq->validTracks = seq->validTracks ^ flagMask;

			if (seq->validTracks) { /* there is music left don't end */
				event->type = AL_TRACK_END;
			} else {       /* no more music send AL_SEQ_END_EVT msg */
				event->type = AL_SEQ_END_EVT;
			}
		} else if (type == AL_CMIDI_LOOPSTART_CODE) {
			status = __getTrackByte(seq, track);
			event->msg.loop.count = status << 8;

			status = __getTrackByte(seq, track);
			event->msg.loop.count += status;

			seq->lastStatus[track] = 0;
			event->type = AL_CSP_LOOPSTART;
		} else if (type == AL_CMIDI_LOOPEND_CODE) {
			tmpPtr = seq->curLoc[track];
			loopCt = *tmpPtr++;
			curLpCt = *tmpPtr;

			if (curLpCt == 0 || !arg3) {
				*tmpPtr = loopCt; /* reset current loop count */
				seq->curLoc[track] = tmpPtr + 5; /* move pointer to end of event */
			} else {
				if (curLpCt != 0xff) { /* not a loop forever */
					*tmpPtr = curLpCt - 1;   /* decrement current loop count */
				}

				tmpPtr++;                    /* get offset from end of event */
				offset = (*tmpPtr++) << 24;
				offset += (*tmpPtr++) << 16;
				offset += (*tmpPtr++) << 8;
				offset += *tmpPtr++;
				seq->curLoc[track] = tmpPtr - offset;
			}

			seq->lastStatus[track] = 0;
			event->type = AL_CSP_LOOPEND;
		}
	} else {
		event->type = AL_SEQ_MIDI_EVT;

		if (status & 0x80) {
			event->msg.midi.status = (status & 0xf0) | track;
			event->msg.midi.byte1 = __getTrackByte(seq,track);
			seq->lastStatus[track] = event->msg.midi.status;
		} else {    /* running status */
			event->msg.midi.status = seq->lastStatus[track];
			event->msg.midi.byte1 = status;
		}

		if ((event->msg.midi.status & 0xf0) != AL_MIDI_ProgramChange
				&& (event->msg.midi.status & 0xf0) != AL_MIDI_ChannelPressure) {
			event->msg.midi.byte2 = __getTrackByte(seq,track);

			if ((event->msg.midi.status & 0xf0) == AL_MIDI_NoteOn) {
				event->msg.midi.duration = __readVarLen(seq,track);
			}
		} else {
			event->msg.midi.byte2 = 0;
		}
	}

	return TRUE;
}

static u8 __getTrackByte(ALCSeq *seq, u32 track)
{
	u8 theByte;

	if (seq->curBULen[track]) {
		theByte = *seq->curBUPtr[track];
		seq->curBUPtr[track]++;
		seq->curBULen[track]--;
	} else /* need to handle backup mode */ {
		theByte = *seq->curLoc[track];
		seq->curLoc[track]++;

		if (theByte == AL_CMIDI_BLOCK_CODE) {
			u8 loBackUp, hiBackUp, theLen, nextByte;
			u32 backup;

			nextByte = *seq->curLoc[track];
			seq->curLoc[track]++;

			if (nextByte != AL_CMIDI_BLOCK_CODE) {
				/**
				 * if here, then got a backup section. get the amount of
				 * backup, and the len of the section. Subtract the amount of
				 * backup from the curLoc ptr, and subtract four more, since
				 * curLoc has been advanced by four while reading the codes.
				 */
				hiBackUp = nextByte;
				loBackUp = *seq->curLoc[track];
				seq->curLoc[track]++;
				theLen = *seq->curLoc[track];
				seq->curLoc[track]++;
				backup = (u32)hiBackUp;
				backup = backup << 8;
				backup += loBackUp;
				seq->curBUPtr[track] = seq->curLoc[track] - (backup + 4);
				seq->curBULen[track] = (u32)theLen;

				/* now get the byte */
				theByte = *seq->curBUPtr[track];
				seq->curBUPtr[track]++;
				seq->curBULen[track]--;
			}
		}
	}

	return theByte;
}

static u32 __readVarLen(ALCSeq *seq, u32 track)
{
	u32 value;
	u32 c;

	value = (u32)__getTrackByte(seq, track);

	if (value & 0x80) {
		value &= 0x7f;

		do {
			c = (u32)__getTrackByte(seq, track);
			value = (value << 7) + (c & 0x7f);
		} while (c & 0x80);
	}

	return value;
}
