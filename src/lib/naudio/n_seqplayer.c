#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include "n_libaudio.h"
#include "n_seqp.h"
#include "seq.h"

void __n_unmapVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice)
{
	N_ALVoiceState *prev = 0;
	N_ALVoiceState *vs;

	/*
	 * we could use doubly linked lists here and save some code and
	 * execution time, but time spent here in negligible, so it won't
	 * make much difference.
	 */
	for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		if (&vs->voice == voice) {
			if (prev) {
				prev->next = vs->next;
			} else {
				seqp->vAllocHead = vs->next;
			}

			if (vs == seqp->vAllocTail) {
				seqp->vAllocTail = prev;
			}

			vs->next = seqp->vFreeList;
			seqp->vFreeList = vs;
			seqp->unk89--;
			return;
		}

		prev = vs;
	}
}

void __n_seqpReleaseVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime)
{
	N_ALEvent evt;
	N_ALVoiceState *vs = (N_ALVoiceState *)voice->clientPrivate;

	/*
	 * if in attack phase, remove all pending volume
	 * events for this voice from the queue
	 */

	if (vs->envPhase == AL_PHASE_ATTACK) {
		ALLink *thisNode;
		ALLink *nextNode;
		N_ALEventListItem *thisItem, *nextItem;

		thisNode = seqp->evtq.allocList.next;

		while (thisNode != 0) {
			nextNode = thisNode->next;
			thisItem = (N_ALEventListItem *)thisNode;
			nextItem = (N_ALEventListItem *)nextNode;

			if (thisItem->evt.type == AL_SEQP_ENV_EVT) {
				if (thisItem->evt.msg.vol.voice == voice) {
					if (nextItem) {
						nextItem->delta += thisItem->delta;
					}

					alUnlink(thisNode);
					alLink(thisNode, &seqp->evtq.freeList);
				}
			}

			thisNode = nextNode;
		}
	}

	vs->velocity = 0;
	vs->envPhase = AL_PHASE_RELEASE;
	vs->envGain  = 0;
	vs->envEndTime = seqp->curTime + deltaTime;

	n_alSynSetPriority(voice, 0); /* make candidate for stealing */
	n_alSynSetVol(voice, 0, deltaTime);

	evt.type = AL_NOTE_END_EVT;
	evt.msg.note.voice = voice;

	deltaTime += (PAL ? 40000 : 32000);

	n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
}

char __n_voiceNeedsNoteKill(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime killTime)
{
	ALLink *thisNode;
	ALLink *nextNode;
	N_ALEventListItem *thisItem;
	ALMicroTime itemTime = 0;
	char needsNoteKill = TRUE;

	thisNode = seqp->evtq.allocList.next;

	while (thisNode != 0) {
		nextNode = thisNode->next;
		thisItem = (N_ALEventListItem *)thisNode;
		itemTime += thisItem->delta;

		if (thisItem->evt.type == AL_NOTE_END_EVT) {
			if (thisItem->evt.msg.note.voice == voice) {
				if (itemTime > killTime) {
					if ((N_ALEventListItem *)nextNode) {
						((N_ALEventListItem *)nextNode)->delta += thisItem->delta;
					}

					alUnlink(thisNode);
					alLink(thisNode, &seqp->evtq.freeList);
				} else {
					needsNoteKill = FALSE;
				}

				break;
			}
		}

		thisNode = nextNode;
	}

	return needsNoteKill;
}

N_ALVoiceState *__n_mapVoice(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 channel)
{
	N_ALVoiceState *vs = seqp->vFreeList;

	if (seqp->unk89 > seqp->unk88) {
		return 0;
	}

	if (vs) {
		seqp->vFreeList = vs->next;
		vs->next = 0;

		if (!seqp->vAllocHead) {
			seqp->vAllocHead = vs;
		} else {
			seqp->vAllocTail->next = vs;
		}

		seqp->vAllocTail = vs;

		vs->channel = channel;
		vs->key = key;
		vs->velocity = vel;
		vs->voice.clientPrivate = vs;

		seqp->unk89++;
	}

	return vs;
}

N_ALVoiceState *__n_lookupVoice(N_ALSeqPlayer *seqp, u8 key, u8 channel)
{
	N_ALVoiceState *vs = seqp->vAllocHead;

	while (vs != 0) {
		if (vs->key == key
				&& vs->channel == channel
				&& vs->phase != AL_PHASE_RELEASE
				&& vs->phase != AL_PHASE_SUSTREL) {
			return vs;
		}

		vs = vs->next;
	}

	return 0;
}

ALSound *__n_lookupSoundQuick(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan)
{
	ALInstrument *inst = seqp->chanState[chan].instrument;
	s32 l = 1;
	s32 r = inst->soundCount;
	s32 i;
	ALKeyMap *keymap;

	while (r >= l) {
		i = (l + r) / 2;

		keymap = inst->soundArray[i - 1]->keyMap;

		if (key >= keymap->keyMin && key <= keymap->keyMax
				&& vel >= keymap->velocityMin && vel <= keymap->velocityMax) {
			return inst->soundArray[i - 1];
		} else if (key < keymap->keyMin || (vel < keymap->velocityMin && key <= keymap->keyMax)) {
			r = i - 1;
		} else {
			l = i + 1;
		}
	}

	return 0;
}

/**
 * __n_vsVol calculates the target volume for the voice based on the
 * note on velocity, envelope, sampleVolume and controller.
 */
s16 __n_vsVol(N_ALVoiceState *vs, N_ALSeqPlayer *seqp)
{
	u32 t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
	u32 t2 = (vs->sound->sampleVolume * seqp->vol * seqp->chanState[vs->channel].vol) >> 14;

	if (seqp->chanState[vs->channel].unk0d != 0xff) {
		t2 = (seqp->chanState[vs->channel].unk0d * t2 + 1) >> 8;
	}

	t1 *= t2;
	t1 >>= 15;

	return t1;
}

GLOBAL_ASM(
glabel func0003d9cc
/*    3d9cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3d9d0:	908f0031 */ 	lbu	$t7,0x31($a0)
/*    3d9d4:	8cae0060 */ 	lw	$t6,0x60($a1)
/*    3d9d8:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3d9dc:	030fc023 */ 	subu	$t8,$t8,$t7
/*    3d9e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3d9e4:	030fc021 */ 	addu	$t8,$t8,$t7
/*    3d9e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3d9ec:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    3d9f0:	9329000a */ 	lbu	$t1,0xa($t9)
/*    3d9f4:	312a0080 */ 	andi	$t2,$t1,0x80
/*    3d9f8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    3d9fc:	3c0142fe */ 	lui	$at,0x42fe
/*    3da00:	44813000 */ 	mtc1	$at,$f6
/*    3da04:	c4a4007c */ 	lwc1	$f4,0x7c($a1)
/*    3da08:	908c0031 */ 	lbu	$t4,0x31($a0)
/*    3da0c:	8cab0060 */ 	lw	$t3,0x60($a1)
/*    3da10:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    3da14:	000c6880 */ 	sll	$t5,$t4,0x2
/*    3da18:	01ac6823 */ 	subu	$t5,$t5,$t4
/*    3da1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3da20:	01ac6821 */ 	addu	$t5,$t5,$t4
/*    3da24:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3da28:	016d7821 */ 	addu	$t7,$t3,$t5
/*    3da2c:	4600428d */ 	trunc.w.s	$f10,$f8
/*    3da30:	91ee000a */ 	lbu	$t6,0xa($t7)
/*    3da34:	c4a40080 */ 	lwc1	$f4,0x80($a1)
/*    3da38:	44095000 */ 	mfc1	$t1,$f10
/*    3da3c:	31d8007f */ 	andi	$t8,$t6,0x7f
/*    3da40:	03095021 */ 	addu	$t2,$t8,$t1
/*    3da44:	448a8000 */ 	mtc1	$t2,$f16
/*    3da48:	00000000 */ 	nop
/*    3da4c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    3da50:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    3da54:	4600320d */ 	trunc.w.s	$f8,$f6
/*    3da58:	440b4000 */ 	mfc1	$t3,$f8
/*    3da5c:	00000000 */ 	nop
/*    3da60:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3da64:	8fad0010 */ 	lw	$t5,0x10($sp)
/*    3da68:	29a10080 */ 	slti	$at,$t5,0x80
/*    3da6c:	14200003 */ 	bnez	$at,.L0003da7c
/*    3da70:	00000000 */ 	nop
/*    3da74:	10000002 */ 	b	.L0003da80
/*    3da78:	2407007f */ 	addiu	$a3,$zero,0x7f
.L0003da7c:
/*    3da7c:	8fa70010 */ 	lw	$a3,0x10($sp)
.L0003da80:
/*    3da80:	04e10003 */ 	bgez	$a3,.L0003da90
/*    3da84:	00000000 */ 	nop
/*    3da88:	10000009 */ 	b	.L0003dab0
/*    3da8c:	00003025 */ 	or	$a2,$zero,$zero
.L0003da90:
/*    3da90:	8faf0010 */ 	lw	$t7,0x10($sp)
/*    3da94:	29e10080 */ 	slti	$at,$t7,0x80
/*    3da98:	14200003 */ 	bnez	$at,.L0003daa8
/*    3da9c:	00000000 */ 	nop
/*    3daa0:	10000002 */ 	b	.L0003daac
/*    3daa4:	2408007f */ 	addiu	$t0,$zero,0x7f
.L0003daa8:
/*    3daa8:	8fa80010 */ 	lw	$t0,0x10($sp)
.L0003daac:
/*    3daac:	01003025 */ 	or	$a2,$t0,$zero
.L0003dab0:
/*    3dab0:	8fae0014 */ 	lw	$t6,0x14($sp)
/*    3dab4:	00ce1025 */ 	or	$v0,$a2,$t6
/*    3dab8:	10000003 */ 	b	.L0003dac8
/*    3dabc:	304200ff */ 	andi	$v0,$v0,0xff
/*    3dac0:	10000001 */ 	b	.L0003dac8
/*    3dac4:	00000000 */ 	nop
.L0003dac8:
/*    3dac8:	03e00008 */ 	jr	$ra
/*    3dacc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

ALMicroTime __n_vsDelta(N_ALVoiceState *vs, ALMicroTime t)
{
	/*
	 * If we are interrupting a previously set envelope segment, we
	 * need to recalculate the segment end time given the current
	 * time. Note: this routine assumes that the voice is currently
	 * playing.
	 */

	s32 delta = vs->envEndTime - t;

	if (delta >= 0) {
		return delta;
	} else {
		return AL_GAIN_CHANGE_TIME;
	}
}

ALPan __vsPan(N_ALVoiceState *vs, N_ALSeqPlayer *seqp)
{
	s32 tmp;

	tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER + vs->sound->samplePan;
	tmp = MAX(tmp, AL_PAN_LEFT);
	tmp = MIN(tmp, AL_PAN_RIGHT);

	return (ALPan) tmp;
}

void __n_initFromBank(N_ALSeqPlayer *seqp, ALBank *b)
{
	/*
	 * init the chanState with the default instrument
	 */
	s32 i;
	ALInstrument *inst = 0;

	/* set to the first available instrument. */
	for (i = 0; !inst; i++) {
		inst = b->instArray[i];
	}

	/* sct 11/6/95 - Setup the channel state for the given instrument. */
	/* There is some wasted effort here since both calls the same state vars */
	/* but it's safer. */
	for (i = 0; i < seqp->maxChannels; i++) {
		__n_resetPerfChanState(seqp, i);
		__n_setInstChanState(seqp, inst, i);
	}

	if (b->percussion) {
		__n_resetPerfChanState(seqp, i);
		__n_setInstChanState(seqp, b->percussion, 9);
	}
}

void __n_initChanState(N_ALSeqPlayer *seqp)
{
	int i;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].instrument = 0;
		__n_resetPerfChanState (seqp, i);
	}
}

void __n_resetPerfChanState(N_ALSeqPlayer *seqp, s32 chan)
{
	seqp->chanState[chan].fxId = AL_FX_NONE;
	seqp->chanState[chan].fxmix = AL_DEFAULT_FXMIX;
	seqp->chanState[chan].pan = AL_PAN_CENTER;
	seqp->chanState[chan].vol = AL_VOL_FULL;
	seqp->chanState[chan].priority = AL_DEFAULT_PRIORITY;
	seqp->chanState[chan].sustain = 0;
	seqp->chanState[chan].bendRange = 200;
	seqp->chanState[chan].pitchBend = 1;
	seqp->chanState[chan].unk10 = 0;
	seqp->chanState[chan].unk0d = 255;
	seqp->chanState[chan].unk0e = 255;
	seqp->chanState[chan].unk0f = 0;
	seqp->chanState[chan].unk0b = 0;
	seqp->chanState[chan].unk13 = 0;
	seqp->chanState[chan].unk12 = 0;
	seqp->chanState[chan].unk11 = 0;
	seqp->chanState[chan].unk32 = 0;
}

void __n_setInstChanState(N_ALSeqPlayer *seqp, ALInstrument *inst, s32 chan)
{
	ALSound *sound;

	seqp->chanState[chan].instrument = inst;
	seqp->chanState[chan].pan = inst->pan;
	seqp->chanState[chan].vol = inst->volume;
	seqp->chanState[chan].priority = inst->priority;
	seqp->chanState[chan].bendRange = inst->bendRange;

	if (inst->soundCount == 0) {
		return;
	}

	sound = inst->soundArray[0];

	seqp->chanState[chan].attackTime = sound->envelope->attackTime;
	seqp->chanState[chan].decayTime = sound->envelope->decayTime;
	seqp->chanState[chan].releaseTime = sound->envelope->releaseTime;
	seqp->chanState[chan].attackVolume = sound->envelope->attackVolume;
	seqp->chanState[chan].decayVolume = sound->envelope->decayVolume;

	seqp->chanState[chan].unk27 = 0;
	seqp->chanState[chan].tremType = inst->tremType;
	seqp->chanState[chan].tremRate = inst->tremRate;
	seqp->chanState[chan].tremDepth = inst->tremDepth;
	seqp->chanState[chan].tremDelay = inst->tremDelay;
	seqp->chanState[chan].vibType = inst->vibType;
	seqp->chanState[chan].ribRate = inst->vibRate;
	seqp->chanState[chan].vibDepth = inst->vibDepth;
	seqp->chanState[chan].vibDelay = inst->vibDelay;

	seqp->chanState[chan].unk24 = 0;
	seqp->chanState[chan].unk31 = 0;
}

void __n_seqpStopOsc(N_ALSeqPlayer *seqp, N_ALVoiceState *vs)
{
	N_ALEventListItem *thisNode,*nextNode;
	s16 evtType;

	thisNode = (N_ALEventListItem*)seqp->evtq.allocList.next;

	while (thisNode) {
		nextNode = (N_ALEventListItem*)thisNode->node.next;
		evtType = thisNode->evt.type;

		if (evtType == AL_TREM_OSC_EVT || evtType == AL_VIB_OSC_EVT) {
			if (thisNode->evt.msg.osc.vs == vs) {
				(*seqp->stopOsc)(thisNode->evt.msg.osc.oscState);
				alUnlink((ALLink*)thisNode);

				if (nextNode) {
					nextNode->delta += thisNode->delta;
				}

				alLink((ALLink*)thisNode, &seqp->evtq.freeList);

				if (evtType == AL_TREM_OSC_EVT) {
					vs->flags &= 0xfe;
				} else { /* must be a AL_VIB_OSC_EVT */
					vs->flags &= 0xfd;
				}

				if (!vs->flags) {
					return;  /* there should be no more events */
				}
			}
		}

		thisNode = nextNode;
	}
}
