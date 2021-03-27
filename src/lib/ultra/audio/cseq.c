#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3c4d0.h"
#include "data.h"
#include "types.h"

u32 __alCSeqGetTrackEvent(ALCSeq *seq, u32 track, ALEvent *event, s32 arg3);
u8 __getTrackByte(ALCSeq *seq, u32 track);
u32 __readVarLen(ALCSeq *seq,u32 track);

void alCSeqNew(ALCSeq *seq, u8 *ptr)
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

void alCSeqNextEvent(ALCSeq *seq, ALEvent *evt, s32 arg2)
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

	__alCSeqGetTrackEvent(seq, firstTrack, evt, arg2);

	evt->msg.midi.ticks = firstTime;
	seq->lastTicks += firstTime;
	seq->lastDeltaTicks = firstTime;

	if (evt->type != AL_TRACK_END) {
		seq->evtDeltaTicks[firstTrack] += __readVarLen(seq, firstTrack);
	}

	seq->deltaFlag = 1;
}

u32 __alCSeqGetTrackEvent(ALCSeq *seq, u32 track, ALEvent *event, s32 arg3)
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

s32 alCSeqGetTicks(ALCSeq *seq)
{
	return seq->lastTicks;
}

void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *m)
{
	s32 i;

	seq->validTracks    = m->validTracks;
	seq->lastTicks      = m->lastTicks;
	seq->lastDeltaTicks = m->lastDeltaTicks;

	for (i = 0; i < 16; i++) {
		seq->curLoc[i]        = m->curLoc[i];
		seq->curBUPtr[i]      = m->curBUPtr[i];
		seq->curBULen[i]      = m->curBULen[i];
		seq->lastStatus[i]    = m->lastStatus[i];
		seq->evtDeltaTicks[i] = m->evtDeltaTicks[i];
	}
}

void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *m)
{
	s32 i;

	m->validTracks    = seq->validTracks;
	m->lastTicks      = seq->lastTicks;
	m->lastDeltaTicks = seq->lastDeltaTicks;

	for (i = 0; i < 16; i++) {
		m->curLoc[i]        = seq->curLoc[i];
		m->curBUPtr[i]      = seq->curBUPtr[i];
		m->curBULen[i]      = seq->curBULen[i];
		m->lastStatus[i]    = seq->lastStatus[i];
		m->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
	}
}

void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks)
{
	ALEvent evt;
	ALCSeq tempSeq;
	s32 i;

	alCSeqNew(&tempSeq, (u8*)seq->base);

	do {
		m->validTracks    = tempSeq.validTracks;
		m->lastTicks      = tempSeq.lastTicks;
		m->lastDeltaTicks = tempSeq.lastDeltaTicks;

		for (i = 0; i < 16; i++) {
			m->curLoc[i]        = tempSeq.curLoc[i];
			m->curBUPtr[i]      = tempSeq.curBUPtr[i];
			m->curBULen[i]      = tempSeq.curBULen[i];
			m->lastStatus[i]    = tempSeq.lastStatus[i];
			m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
		}

		alCSeqNextEvent(&tempSeq, &evt, 0);

		if (evt.type == AL_SEQ_END_EVT) {
			break;
		}
	} while (tempSeq.lastTicks < ticks);
}

GLOBAL_ASM(
glabel func00039718
/*    39718:	27bdfde8 */ 	addiu	$sp,$sp,-536
/*    3971c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    39720:	afa40218 */ 	sw	$a0,0x218($sp)
/*    39724:	afa5021c */ 	sw	$a1,0x21c($sp)
/*    39728:	afa60220 */ 	sw	$a2,0x220($sp)
/*    3972c:	afa70224 */ 	sw	$a3,0x224($sp)
/*    39730:	8fae0218 */ 	lw	$t6,0x218($sp)
/*    39734:	27a40110 */ 	addiu	$a0,$sp,0x110
/*    39738:	0c00e34c */ 	jal	alCSeqNew
/*    3973c:	8dc50000 */ 	lw	$a1,0x0($t6)
/*    39740:	8faf0220 */ 	lw	$t7,0x220($sp)
/*    39744:	afa00108 */ 	sw	$zero,0x108($sp)
/*    39748:	11e00010 */ 	beqz	$t7,.L0003978c
/*    3974c:	00000000 */ 	nop
.L00039750:
/*    39750:	8fb90108 */ 	lw	$t9,0x108($sp)
/*    39754:	8fb8021c */ 	lw	$t8,0x21c($sp)
/*    39758:	00194100 */ 	sll	$t0,$t9,0x4
/*    3975c:	01194023 */ 	subu	$t0,$t0,$t9
/*    39760:	00084080 */ 	sll	$t0,$t0,0x2
/*    39764:	01194023 */ 	subu	$t0,$t0,$t9
/*    39768:	00084080 */ 	sll	$t0,$t0,0x2
/*    3976c:	03084821 */ 	addu	$t1,$t8,$t0
/*    39770:	ad200004 */ 	sw	$zero,0x4($t1)
/*    39774:	8faa0108 */ 	lw	$t2,0x108($sp)
/*    39778:	8fac0220 */ 	lw	$t4,0x220($sp)
/*    3977c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    39780:	016c082b */ 	sltu	$at,$t3,$t4
/*    39784:	1420fff2 */ 	bnez	$at,.L00039750
/*    39788:	afab0108 */ 	sw	$t3,0x108($sp)
.L0003978c:
/*    3978c:	8fad0114 */ 	lw	$t5,0x114($sp)
/*    39790:	afad001c */ 	sw	$t5,0x1c($sp)
/*    39794:	8fae011c */ 	lw	$t6,0x11c($sp)
/*    39798:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3979c:	8faf0120 */ 	lw	$t7,0x120($sp)
/*    397a0:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    397a4:	afa0010c */ 	sw	$zero,0x10c($sp)
.L000397a8:
/*    397a8:	8fb9010c */ 	lw	$t9,0x10c($sp)
/*    397ac:	0019c080 */ 	sll	$t8,$t9,0x2
/*    397b0:	03b84021 */ 	addu	$t0,$sp,$t8
/*    397b4:	8d080128 */ 	lw	$t0,0x128($t0)
/*    397b8:	03b84821 */ 	addu	$t1,$sp,$t8
/*    397bc:	ad280028 */ 	sw	$t0,0x28($t1)
/*    397c0:	8faa010c */ 	lw	$t2,0x10c($sp)
/*    397c4:	000a5880 */ 	sll	$t3,$t2,0x2
/*    397c8:	03ab6021 */ 	addu	$t4,$sp,$t3
/*    397cc:	8d8c0168 */ 	lw	$t4,0x168($t4)
/*    397d0:	03ab6821 */ 	addu	$t5,$sp,$t3
/*    397d4:	adac0068 */ 	sw	$t4,0x68($t5)
/*    397d8:	8fae010c */ 	lw	$t6,0x10c($sp)
/*    397dc:	03ae7821 */ 	addu	$t7,$sp,$t6
/*    397e0:	91ef01a8 */ 	lbu	$t7,0x1a8($t7)
/*    397e4:	03aec821 */ 	addu	$t9,$sp,$t6
/*    397e8:	a32f00a8 */ 	sb	$t7,0xa8($t9)
/*    397ec:	8fa8010c */ 	lw	$t0,0x10c($sp)
/*    397f0:	03a8c021 */ 	addu	$t8,$sp,$t0
/*    397f4:	931801b8 */ 	lbu	$t8,0x1b8($t8)
/*    397f8:	03a84821 */ 	addu	$t1,$sp,$t0
/*    397fc:	a13800b8 */ 	sb	$t8,0xb8($t1)
/*    39800:	8faa010c */ 	lw	$t2,0x10c($sp)
/*    39804:	000a6080 */ 	sll	$t4,$t2,0x2
/*    39808:	03ac5821 */ 	addu	$t3,$sp,$t4
/*    3980c:	8d6b01c8 */ 	lw	$t3,0x1c8($t3)
/*    39810:	03ac6821 */ 	addu	$t5,$sp,$t4
/*    39814:	adab00c8 */ 	sw	$t3,0xc8($t5)
/*    39818:	8faf010c */ 	lw	$t7,0x10c($sp)
/*    3981c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*    39820:	29c10010 */ 	slti	$at,$t6,0x10
/*    39824:	1420ffe0 */ 	bnez	$at,.L000397a8
/*    39828:	afae010c */ 	sw	$t6,0x10c($sp)
/*    3982c:	27a40110 */ 	addiu	$a0,$sp,0x110
/*    39830:	27a50208 */ 	addiu	$a1,$sp,0x208
/*    39834:	0c00e3ac */ 	jal	alCSeqNextEvent
/*    39838:	00003025 */ 	or	$a2,$zero,$zero
/*    3983c:	87b90208 */ 	lh	$t9,0x208($sp)
/*    39840:	24010013 */ 	addiu	$at,$zero,0x13
/*    39844:	1721003a */ 	bne	$t9,$at,.L00039930
/*    39848:	00000000 */ 	nop
/*    3984c:	8fb80214 */ 	lw	$t8,0x214($sp)
/*    39850:	8fa90224 */ 	lw	$t1,0x224($sp)
/*    39854:	00184203 */ 	sra	$t0,$t8,0x8
/*    39858:	0109082b */ 	sltu	$at,$t0,$t1
/*    3985c:	14200034 */ 	bnez	$at,.L00039930
/*    39860:	00000000 */ 	nop
/*    39864:	8faa0220 */ 	lw	$t2,0x220($sp)
/*    39868:	012a5821 */ 	addu	$t3,$t1,$t2
/*    3986c:	010b082b */ 	sltu	$at,$t0,$t3
/*    39870:	1020002f */ 	beqz	$at,.L00039930
/*    39874:	00000000 */ 	nop
/*    39878:	8fac0214 */ 	lw	$t4,0x214($sp)
/*    3987c:	8faf0224 */ 	lw	$t7,0x224($sp)
/*    39880:	8fb8021c */ 	lw	$t8,0x21c($sp)
/*    39884:	000c6a03 */ 	sra	$t5,$t4,0x8
/*    39888:	01af7023 */ 	subu	$t6,$t5,$t7
/*    3988c:	000ec900 */ 	sll	$t9,$t6,0x4
/*    39890:	032ec823 */ 	subu	$t9,$t9,$t6
/*    39894:	0019c880 */ 	sll	$t9,$t9,0x2
/*    39898:	032ec823 */ 	subu	$t9,$t9,$t6
/*    3989c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    398a0:	03194821 */ 	addu	$t1,$t8,$t9
/*    398a4:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    398a8:	15400021 */ 	bnez	$t2,.L00039930
/*    398ac:	00000000 */ 	nop
/*    398b0:	8fa80214 */ 	lw	$t0,0x214($sp)
/*    398b4:	8fac0224 */ 	lw	$t4,0x224($sp)
/*    398b8:	8fae021c */ 	lw	$t6,0x21c($sp)
/*    398bc:	00085a03 */ 	sra	$t3,$t0,0x8
/*    398c0:	016c6823 */ 	subu	$t5,$t3,$t4
/*    398c4:	000d7900 */ 	sll	$t7,$t5,0x4
/*    398c8:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    398cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*    398d0:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    398d4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    398d8:	27b9001c */ 	addiu	$t9,$sp,0x1c
/*    398dc:	272800e4 */ 	addiu	$t0,$t9,0xe4
/*    398e0:	01cfc021 */ 	addu	$t8,$t6,$t7
.L000398e4:
/*    398e4:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*    398e8:	2739000c */ 	addiu	$t9,$t9,0xc
/*    398ec:	2718000c */ 	addiu	$t8,$t8,0xc
/*    398f0:	af0afff4 */ 	sw	$t2,-0xc($t8)
/*    398f4:	8f29fff8 */ 	lw	$t1,-0x8($t9)
/*    398f8:	af09fff8 */ 	sw	$t1,-0x8($t8)
/*    398fc:	8f2afffc */ 	lw	$t2,-0x4($t9)
/*    39900:	1728fff8 */ 	bne	$t9,$t0,.L000398e4
/*    39904:	af0afffc */ 	sw	$t2,-0x4($t8)
/*    39908:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*    3990c:	af0a0000 */ 	sw	$t2,0x0($t8)
/*    39910:	8f290004 */ 	lw	$t1,0x4($t9)
/*    39914:	af090004 */ 	sw	$t1,0x4($t8)
/*    39918:	8fab0108 */ 	lw	$t3,0x108($sp)
/*    3991c:	256cffff */ 	addiu	$t4,$t3,-1
/*    39920:	1d800003 */ 	bgtz	$t4,.L00039930
/*    39924:	afac0108 */ 	sw	$t4,0x108($sp)
/*    39928:	10000007 */ 	b	.L00039948
/*    3992c:	00000000 */ 	nop
.L00039930:
/*    39930:	87ad0208 */ 	lh	$t5,0x208($sp)
/*    39934:	24010004 */ 	addiu	$at,$zero,0x4
/*    39938:	15a1ff94 */ 	bne	$t5,$at,.L0003978c
/*    3993c:	00000000 */ 	nop
/*    39940:	10000001 */ 	b	.L00039948
/*    39944:	00000000 */ 	nop
.L00039948:
/*    39948:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3994c:	27bd0218 */ 	addiu	$sp,$sp,0x218
/*    39950:	03e00008 */ 	jr	$ra
/*    39954:	00000000 */ 	nop
);

u8 __getTrackByte(ALCSeq *seq, u32 track)
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
                /* if here, then got a backup section. get the amount of
                   backup, and the len of the section. Subtract the amount of
                   backup from the curLoc ptr, and subtract four more, since
                   curLoc has been advanced by four while reading the codes. */
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

u32 __readVarLen(ALCSeq *seq, u32 track)
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
