#include "versions.h"
#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include <assert.h>
#include "n_libaudio.h"
#include "n_seqp.h"
#include "cseq.h"
#include "n_cseqp.h"

void __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item);
void __n_setUsptFromTempo(N_ALCSPlayer *seqp, f32 tempo);
void __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event);
ALMicroTime __n_vsDelta(N_ALVoiceState *vs, ALMicroTime t);

u32 var8009c350[16];

u32 var8005f150[] = {
	0x00000000, 0x00002710, 0x00004e20, 0x00007530,
	0x00009c40, 0x0000c350, 0x0000ea60, 0x00011170,
	0x00013880, 0x00015f90, 0x000186a0, 0x0001adb0,
	0x0001adb0, 0x0001d4c0, 0x0001fbd0, 0x000222e0,
	0x000249f0, 0x00027100, 0x00029810, 0x0002e630,
	0x00030d40, 0x00035b60, 0x00038270, 0x0003d090,
	0x00041eb0, 0x00046cd0, 0x0004baf0, 0x00050910,
	0x00055730, 0x0005cc60, 0x00064190, 0x0006b6c0,
	0x00072bf0, 0x0007a120, 0x00083d60, 0x0008d9a0,
	0x000975e0, 0x000a1220, 0x000ad570, 0x000b98c0,
	0x000c8320, 0x000d6d80, 0x000e57e0, 0x000f4240,
	0x000f4240, 0x0010c8e0, 0x00124f80, 0x0013d620,
	0x00155cc0, 0x0016e360, 0x00186a00, 0x0019f0a0,
	0x001b7740, 0x001e8480, 0x00200b20, 0x00231860,
	0x00249f00, 0x0027ac40, 0x002ab980, 0x002dc6c0,
	0x0030d400, 0x003567e0, 0x00387520, 0x003d0900,
	0x00419ce0, 0x004630c0, 0x004ac4a0, 0x0050df20,
	0x0056f9a0, 0x005d1420, 0x00632ea0, 0x006acfc0,
	0x007270e0, 0x007b98a0, 0x008339c0, 0x008de820,
	0x00970fe0, 0x00989680, 0x00a7d8c0, 0x00b71b00,
	0x00c65d40, 0x00d59f80, 0x00e4e1c0, 0x00f42400,
	0x01036640, 0x0112a880, 0x0121eac0, 0x01406f40,
	0x014fb180, 0x016e3600, 0x018cba80, 0x01ab3f00,
	0x01c9c380, 0x01e84800, 0x0206cc80, 0x02349340,
	0x025317c0, 0x0280de80, 0x02aea540, 0x02ebae40,
	0x02faf080, 0x03473bc0, 0x03938700, 0x03dfd240,
	0x042c1d80, 0x047868c0, 0x04c4b400, 0x0510ff40,
	0x055d4a80, 0x05a995c0, 0x05f5e100, 0x06422c40,
	0x068e7780, 0x06dac2c0, 0x07270e00, 0x07735940,
	0x07bfa480, 0x080befc0, 0x08583b00, 0x08a48640,
	0x08f0d180, 0x093d1cc0, 0x09896800, 0x09d5b340,
	0x0a21fe80, 0x0a6e49c0, 0x0aba9500,
};

u32 var8005f34c = 0x3d4ccccd;
u32 var8005f350 = 0x3d4ccccd;
u32 var8005f354 = 0x3d75c28f;
u32 var8005f358 = 0x3d75c28f;
u32 var8005f35c = 0x3d75c28f;
u32 var8005f360 = 0x3d8f5c29;
u32 var8005f364 = 0x3d8f5c29;
u32 var8005f368 = 0x3da3d70a;
u32 var8005f36c = 0x3da3d70a;
u32 var8005f370 = 0x3db851ec;
u32 var8005f374 = 0x3dcccccd;
u32 var8005f378 = 0x3de147ae;
u32 var8005f37c = 0x3e051eb8;
u32 var8005f380 = 0x3e0f5c29;
u32 var8005f384 = 0x3e2e147b;
u32 var8005f388 = 0x3e4ccccd;
u32 var8005f38c = 0x3e800000;
u32 var8005f390 = 0x3ea8f5c3;
u32 var8005f394 = 0x3f000000;
u32 var8005f398 = 0x3f800000;
u32 var8005f39c = 0x3fa00000;
u32 var8005f3a0 = 0x3fc00000;
u32 var8005f3a4 = 0x3fe00000;
u32 var8005f3a8 = 0x40000000;
u32 var8005f3ac = 0x40100000;
u32 var8005f3b0 = 0x40200000;
u32 var8005f3b4 = 0x40300000;
u32 var8005f3b8 = 0x40400000;
u32 var8005f3bc = 0x40500000;
u32 var8005f3c0 = 0x40600000;
u32 var8005f3c4 = 0x40700000;
u32 var8005f3c8 = 0x40800000;
u32 var8005f3cc = 0x40880000;
u32 var8005f3d0 = 0x40900000;
u32 var8005f3d4 = 0x40980000;
u32 var8005f3d8 = 0x40a00000;
u32 var8005f3dc = 0x40a80000;
u32 var8005f3e0 = 0x40b00000;
u32 var8005f3e4 = 0x40b80000;
u32 var8005f3e8 = 0x40c00000;
u32 var8005f3ec = 0x40c80000;
u32 var8005f3f0 = 0x40d00000;
u32 var8005f3f4 = 0x40d80000;
u32 var8005f3f8 = 0x40e00000;
u32 var8005f3fc = 0x40e80000;
u32 var8005f400 = 0x40f00000;
u32 var8005f404 = 0x40f80000;
u32 var8005f408 = 0x41000000;
u32 var8005f40c = 0x41040000;
u32 var8005f410 = 0x41080000;
u32 var8005f414 = 0x410c0000;
u32 var8005f418 = 0x41100000;
u32 var8005f41c = 0x41140000;
u32 var8005f420 = 0x41180000;
u32 var8005f424 = 0x411c0000;
u32 var8005f428 = 0x41200000;
u32 var8005f42c = 0x41240000;
u32 var8005f430 = 0x41280000;
u32 var8005f434 = 0x412c0000;
u32 var8005f438 = 0x41300000;
u32 var8005f43c = 0x41340000;
u32 var8005f440 = 0x41380000;
u32 var8005f444 = 0x413c0000;
u32 var8005f448 = 0x41400000;
u32 var8005f44c = 0x41440000;
u32 var8005f450 = 0x41480000;
u32 var8005f454 = 0x414c0000;
u32 var8005f458 = 0x41500000;
u32 var8005f45c = 0x41540000;
u32 var8005f460 = 0x41580000;
u32 var8005f464 = 0x415c0000;
u32 var8005f468 = 0x41600000;
u32 var8005f46c = 0x41640000;
u32 var8005f470 = 0x41680000;
u32 var8005f474 = 0x416c0000;
u32 var8005f478 = 0x41700000;
u32 var8005f47c = 0x41740000;
u32 var8005f480 = 0x41780000;
u32 var8005f484 = 0x417c0000;
u32 var8005f488 = 0x41800000;
u32 var8005f48c = 0x41820000;
u32 var8005f490 = 0x41840000;
u32 var8005f494 = 0x41860000;
u32 var8005f498 = 0x41880000;
u32 var8005f49c = 0x418a0000;
u32 var8005f4a0 = 0x418c0000;
u32 var8005f4a4 = 0x418e0000;
u32 var8005f4a8 = 0x41900000;
u32 var8005f4ac = 0x41920000;
u32 var8005f4b0 = 0x41940000;
u32 var8005f4b4 = 0x41960000;
u32 var8005f4b8 = 0x41980000;
u32 var8005f4bc = 0x419a0000;
u32 var8005f4c0 = 0x419c0000;
u32 var8005f4c4 = 0x419e0000;
u32 var8005f4c8 = 0x41a00000;
u32 var8005f4cc = 0x41a20000;
u32 var8005f4d0 = 0x41a40000;
u32 var8005f4d4 = 0x41a60000;
u32 var8005f4d8 = 0x41a80000;
u32 var8005f4dc = 0x00000000;

ALMicroTime __n_CSPVoiceHandler(void *node);

void n_alCSPNew(N_ALCSPlayer *seqp, ALSeqpConfig *c)
{
	s32                 i;
	N_ALEventListItem     *items;
	N_ALVoiceState        *vs;
	N_ALVoiceState        *voices;

	ALHeap *hp = c->heap;

	/*
	 * initialize member variables
	 */
	seqp->bank          = 0;
	seqp->target        = NULL;
	seqp->drvr          = n_syn;
	seqp->chanMask      = 0xffff;

	func00039cd0(seqp);

	seqp->uspt          = 488;
	seqp->nextDelta     = 0;
	seqp->state         = AL_STOPPED;
	seqp->vol           = 0x7fff;              /* full volume  */
	seqp->debugFlags    = c->debugFlags;
	seqp->frameTime     = AL_USEC_PER_FRAME; /* should get this from driver */
	seqp->curTime       = 0;
	seqp->initOsc       = c->initOsc;
	seqp->updateOsc     = c->updateOsc;
	seqp->stopOsc       = c->stopOsc;

	seqp->unk7c = 0;
	seqp->unk80 = 1;
	seqp->queue = 0;
	seqp->unk89 = 0;
	seqp->unk88 = c->maxVoices;

	seqp->nextEvent.type = AL_SEQP_API_EVT;	/* this will start the voice handler "spinning" */

	/*
	 * init the channel state
	 */
	seqp->maxChannels = c->maxChannels;
	seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState) );
	__n_initChanState((N_ALSeqPlayer*)seqp);

	/*
	 * init the voice state array
	 */
	voices = alHeapAlloc(hp, c->maxVoices, sizeof(N_ALVoiceState));
	seqp->vFreeList = 0;
	for (i = 0; i < c->maxVoices; i++) {
		vs = &voices[i];
		vs->next = seqp->vFreeList;
		seqp->vFreeList = vs;
	}

	seqp->vAllocHead = 0;
	seqp->vAllocTail = 0;

	/*
	 * init the event queue
	 */
	items = alHeapAlloc(hp, c->maxEvents, sizeof(N_ALEventListItem));
	n_alEvtqNew(&seqp->evtq, items, c->maxEvents);


	/*
	 * add ourselves to the driver
	 */
	seqp->node.next       = NULL;
	seqp->node.handler    = __n_CSPVoiceHandler;
	seqp->node.clientData = seqp;

	n_alSynAddSeqPlayer(&seqp->node);
}

void __n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp);
void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event);

void func0003e3e0(N_ALVoice *v, f32 arg1);
u8 func0003d9cc(N_ALVoiceState *vs, N_ALCSPlayer *seqp);
ALFxRef func0003e540(u8 arg0);
ALFxRef func0003e5b8(u8 arg0);
void func0003e674(ALFxRef fx, u8 arg1, void *param);
f32 func0003b9d4(s32 arg0);

ALMicroTime __n_CSPVoiceHandler(void *node)
{
	N_ALCSPlayer    *seqp = (N_ALCSPlayer *) node;
	N_ALEvent        evt;
	N_ALVoice       *voice;
	ALMicroTime      delta;
	N_ALVoiceState  *vs;
	void            *oscState;
	f32              oscValue;
	u8               chan;

	do {
		switch (seqp->nextEvent.type) {
		case (AL_SEQ_REF_EVT):
			__n_CSPHandleNextSeqEvent(seqp);
			break;

		case (AL_SEQP_API_EVT):
			evt.type = AL_SEQP_API_EVT;
			n_alEvtqPostEvent(&seqp->evtq, (N_ALEvent *)&evt, seqp->frameTime, 1);
			break;

		case (AL_NOTE_END_EVT):
			voice = seqp->nextEvent.msg.note.voice;

			n_alSynStopVoice(voice);
			n_alSynFreeVoice(voice);
			vs = (N_ALVoiceState *)voice->clientPrivate;

			if (vs->flags) {
				__n_seqpStopOsc((N_ALSeqPlayer*)seqp,vs);
			}

			__n_unmapVoice((N_ALSeqPlayer*)seqp, voice);
			break;

		case (AL_SEQP_ENV_EVT):
			voice = seqp->nextEvent.msg.vol.voice;
			vs = (N_ALVoiceState *)voice->clientPrivate;

			if (vs->envPhase == AL_PHASE_ATTACK) {
				vs->envPhase = AL_PHASE_DECAY;
			}

			delta = seqp->nextEvent.msg.vol.delta;
			vs->envEndTime = seqp->curTime + delta;
			vs->envGain = seqp->nextEvent.msg.vol.vol;
			n_alSynSetVol(voice, __n_vsVol(vs, (N_ALSeqPlayer*)seqp), delta);
			break;

		case (AL_TREM_OSC_EVT):
			vs = seqp->nextEvent.msg.osc.vs;
			oscState = seqp->nextEvent.msg.osc.oscState;
			delta = (*seqp->updateOsc)(oscState,&oscValue);
			vs->tremelo = (u8)oscValue;
			n_alSynSetVol(&vs->voice, __n_vsVol(vs,(N_ALSeqPlayer*)seqp), __n_vsDelta(vs,seqp->curTime));
			evt.type = AL_TREM_OSC_EVT;
			evt.msg.osc.vs = vs;
			evt.msg.osc.oscState = oscState;
			n_alEvtqPostEvent(&seqp->evtq, &evt, delta, 0);
			break;

		case (AL_VIB_OSC_EVT):
			vs = seqp->nextEvent.msg.osc.vs;
			oscState = seqp->nextEvent.msg.osc.oscState;
			chan = seqp->nextEvent.msg.osc.chan;
			delta = (*seqp->updateOsc)(oscState,&oscValue);
			vs->vibrato = oscValue;
			n_alSynSetPitch( &vs->voice, vs->pitch * vs->vibrato * seqp->chanState[chan].pitchBend);

			if (seqp->chanState[chan].unk11) {
				func0003e3e0(&vs->voice,
						440
						* func0003b9d4(seqp->chanState[chan].unk12 + (vs->key - vs->sound->keyMap->keyBase) - 64)
						* seqp->chanState[chan].pitchBend
						* vs->vibrato);
			}

			evt.type = AL_VIB_OSC_EVT;
			evt.msg.osc.vs = vs;
			evt.msg.osc.oscState = oscState;
			evt.msg.osc.chan = chan;
			n_alEvtqPostEvent(&seqp->evtq, &evt, delta, 0);
			break;

		case (AL_SEQP_MIDI_EVT):
		case (AL_CSP_NOTEOFF_EVT):	/* nextEvent is a note off midi message */
			__n_CSPHandleMIDIMsg(seqp, &seqp->nextEvent);
			break;

		case (AL_SEQP_META_EVT):
			__n_CSPHandleMetaMsg(seqp, &seqp->nextEvent);
			break;

		case (AL_SEQP_VOL_EVT):
			seqp->vol =  seqp->nextEvent.msg.spvol.vol;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				n_alSynSetVol(&vs->voice,
						__n_vsVol(vs, (N_ALSeqPlayer*)seqp),
						__n_vsDelta(vs, seqp->curTime));
			}
			break;

		case (AL_18_EVT):
			seqp->unk7c = seqp->nextEvent.msg.evt18.unk00;
			seqp->unk80 = seqp->nextEvent.msg.evt18.unk04;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				n_alSynSetFXMix(&vs->voice, func0003d9cc(vs, seqp));
			}
			break;

		case (AL_19_EVT):
			if (seqp->nextEvent.msg.evt19.unk01 < 8) {
				ALFxRef fx = func0003e540(seqp->nextEvent.msg.evt19.unk00);

				if (fx) {
					n_alSynSetFXParam(fx, seqp->nextEvent.msg.evt19.unk02 << 3 |
							seqp->nextEvent.msg.evt19.unk01 & 7, &seqp->nextEvent.msg.evt19.param);
				}
			} else {
				ALFxRef fx = func0003e5b8(seqp->nextEvent.msg.evt19.unk00);

				if (fx) {
					func0003e674(fx, seqp->nextEvent.msg.evt19.unk01, &seqp->nextEvent.msg.evt19.param);
				}
			}
			break;

		case (AL_SEQP_PLAY_EVT):
			if (seqp->state != AL_PLAYING) {
				seqp->state = AL_PLAYING;
				__n_CSPPostNextSeqEvent(seqp);
				/* seqp must be AL_PLAYING before we call this routine. */
			}
			break;

		case (AL_SEQP_STOP_EVT):
			if (seqp->state == AL_STOPPING ) {
				for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
					n_alSynStopVoice(&vs->voice);
					n_alSynFreeVoice(&vs->voice);

					if (vs->flags) {
						__n_seqpStopOsc((N_ALSeqPlayer*)seqp,vs);
					}

					__n_unmapVoice((N_ALSeqPlayer*)seqp, &vs->voice);
				}

				seqp->state = AL_STOPPED;

				/* alEvtqFlush(&seqp->evtq); - Don't flush event queue
				   anymore. */
				/* sct 1/3/96 - Don't overwrite nextEvent with
				   AL_SEQP_API_EVT or set nextDelta to
				   AL_USEC_PER_FRAME since we're not stopping event
				   processing. */
				/* sct 1/3/96 - Don't return here since we keep
				   processing events as usual. */
			}
			break;

		case (AL_SEQP_STOPPING_EVT):
			if (seqp->state == AL_PLAYING) {
				/* sct 12/29/95 - Remove events associated with the
				 * stopping sequence.  For compact sequence player,
				 * also remove all queued note off events since they
				 * are not contained in a compact sequence but are
				 * generated in response to note ons.  Note that
				 * flushing AL_SEQP_MIDI_EVTs may flush events that
				 * were posted after the call to alSeqpStop, so the
				 * application must queue these events either when
				 * the player is fully stopped, or when it is
				 * playing. */
				n_alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
				n_alEvtqFlushType(&seqp->evtq, AL_CSP_NOTEOFF_EVT);
				n_alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);

				/* sct 1/3/96 - Check to see which voices need to be
				   killed and release them. */
				/* Unkilled voices should have note end events
				   occurring prior to KILL_TIME. */
				for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
					if (__n_voiceNeedsNoteKill ((N_ALSeqPlayer*)seqp, &vs->voice, KILL_TIME)) {
						__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vs->voice, KILL_TIME);
					}
				}

				for (chan = 0; chan < 16; chan++) {
					seqp->chanState[chan].unk0d = seqp->chanState[chan].unk0e;

					if (seqp->chanState[chan].unk0d == 0) {
						seqp->chanMask &= (1 << chan) ^ 0xffff;
					} else {
						seqp->chanMask |= 1 << chan;
					}
				}

				seqp->state = AL_STOPPING;
				evt.type = AL_SEQP_STOP_EVT;
				n_alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END, 0);
			}
			break;

		case (AL_SEQP_PRIORITY_EVT):
			chan = seqp->nextEvent.msg.sppriority.chan;
			seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
			break;

		case (AL_SEQP_SEQ_EVT):
			/* Must be done playing to change sequences. */

			seqp->target = seqp->nextEvent.msg.spseq.seq;
			seqp->chanMask = 0xffff;

			if (seqp->bank) {
				__n_initFromBank((N_ALSeqPlayer *)seqp, seqp->bank);
			}
			break;

		case (AL_SEQP_BANK_EVT):
			/* Must be fully stopped to change banks. */

			seqp->bank = seqp->nextEvent.msg.spbank.bank;
			__n_initFromBank((N_ALSeqPlayer *)seqp, seqp->bank);
			break;

			/* sct 11/6/95 - these events should
			   now be handled by __n_CSPHandleNextSeqEvent */

		case (AL_SEQ_END_EVT):
		case (AL_TEMPO_EVT):
		case (AL_SEQ_MIDI_EVT):
			break;
		}

		seqp->nextDelta = n_alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent);
	} while (seqp->nextDelta == 0);

	/*
	 * assume that next callback won't be more than half an
	 * hour away
	 */
	seqp->curTime += seqp->nextDelta;		/* sct 11/7/95 */
	return seqp->nextDelta;
}

/**
 * Calculates the delta time in ticks until the next sequence
 * event and posts a sequence reference event with the time in usecs.
 * Loops are handled automatically by the compact sequence.
 *
 * Does nothing if the sequence player is not playing or if there
 * is no target sequence.
 *
 * sct 11/7/95
 */
void __n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp)
{
	N_ALEvent evt;

	/* sct 1/5/96 - Do nothing if we don't have a target sequence. */
	if (seqp->target == NULL) {
		return;
	}

	n_alCSeqNextEvent(seqp->target, &evt, 1);

	switch (evt.type) {
	case AL_SEQ_MIDI_EVT:
		__n_CSPHandleMIDIMsg(seqp, &evt);
		__n_CSPPostNextSeqEvent(seqp);
		break;

	case AL_TEMPO_EVT:
		__n_CSPHandleMetaMsg(seqp, &evt);
		__n_CSPPostNextSeqEvent(seqp);
		break;

	case AL_SEQ_END_EVT:
		if (!var8005f4dc) {
			seqp->state = AL_STOPPING;
			evt.type    = AL_SEQP_STOP_EVT;
			n_alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END, 0);
		}
		break;

	case AL_TRACK_END:
	case AL_CSP_LOOPSTART:
	case AL_CSP_LOOPEND:
		__n_CSPPostNextSeqEvent(seqp);
		break;

	default:
		break;
	}
}

void func00034f0c(N_ALCSPlayer *seqp, u8 channel)
{
	N_ALVoiceState *vs;

	for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
		if (vs->channel == channel && vs->envPhase != AL_PHASE_RELEASE) {
			s16 volume = __n_vsVol(vs, (N_ALSeqPlayer *) seqp);

			n_alSynSetVol(&vs->voice, volume, __n_vsDelta(vs, seqp->curTime));
		}
	}
}

GLOBAL_ASM(
glabel func00034fb8
/*    34fb8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    34fbc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34fc0:	afa40030 */ 	sw	$a0,0x30($sp)
/*    34fc4:	afa50034 */ 	sw	$a1,0x34($sp)
/*    34fc8:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*    34fcc:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    34fd0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    34fd4:	0018c880 */ 	sll	$t9,$t8,0x2
/*    34fd8:	0338c823 */ 	subu	$t9,$t9,$t8
/*    34fdc:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    34fe0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    34fe4:	0338c821 */ 	addu	$t9,$t9,$t8
/*    34fe8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    34fec:	01f94021 */ 	addu	$t0,$t7,$t9
/*    34ff0:	81090012 */ 	lb	$t1,0x12($t0)
/*    34ff4:	252affc0 */ 	addiu	$t2,$t1,-64
/*    34ff8:	a3aa0029 */ 	sb	$t2,0x29($sp)
/*    34ffc:	93ad0037 */ 	lbu	$t5,0x37($sp)
/*    35000:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    35004:	000d7080 */ 	sll	$t6,$t5,0x2
/*    35008:	01cd7023 */ 	subu	$t6,$t6,$t5
/*    3500c:	8d6c0060 */ 	lw	$t4,0x60($t3)
/*    35010:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35014:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    35018:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3501c:	018ec021 */ 	addu	$t8,$t4,$t6
/*    35020:	c7040014 */ 	lwc1	$f4,0x14($t8)
/*    35024:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*    35028:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3502c:	8df90064 */ 	lw	$t9,0x64($t7)
/*    35030:	13200030 */ 	beqz	$t9,.L000350f4
/*    35034:	afb9002c */ 	sw	$t9,0x2c($sp)
.L00035038:
/*    35038:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3503c:	93aa0037 */ 	lbu	$t2,0x37($sp)
/*    35040:	91090031 */ 	lbu	$t1,0x31($t0)
/*    35044:	152a0027 */ 	bne	$t1,$t2,.L000350e4
/*    35048:	00000000 */ 	nop
/*    3504c:	93ac0037 */ 	lbu	$t4,0x37($sp)
/*    35050:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    35054:	000c7080 */ 	sll	$t6,$t4,0x2
/*    35058:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    3505c:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    35060:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35064:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    35068:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3506c:	01aec021 */ 	addu	$t8,$t5,$t6
/*    35070:	930f0011 */ 	lbu	$t7,0x11($t8)
/*    35074:	a7af002a */ 	sh	$t7,0x2a($sp)
/*    35078:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3507c:	87a5002a */ 	lh	$a1,0x2a($sp)
/*    35080:	0c00f924 */ 	jal	func0003e490
/*    35084:	24840004 */ 	addiu	$a0,$a0,0x4
/*    35088:	87b9002a */ 	lh	$t9,0x2a($sp)
/*    3508c:	13200015 */ 	beqz	$t9,.L000350e4
/*    35090:	00000000 */ 	nop
/*    35094:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    35098:	83ae0029 */ 	lb	$t6,0x29($sp)
/*    3509c:	8d0a0020 */ 	lw	$t2,0x20($t0)
/*    350a0:	91090032 */ 	lbu	$t1,0x32($t0)
/*    350a4:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    350a8:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    350ac:	012c6823 */ 	subu	$t5,$t1,$t4
/*    350b0:	0c00ee75 */ 	jal	func0003b9d4
/*    350b4:	01ae2021 */ 	addu	$a0,$t5,$t6
/*    350b8:	3c0143dc */ 	lui	$at,0x43dc
/*    350bc:	44813000 */ 	mtc1	$at,$f6
/*    350c0:	46000506 */ 	mov.s	$f20,$f0
/*    350c4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*    350c8:	4606a202 */ 	mul.s	$f8,$f20,$f6
/*    350cc:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    350d0:	24840004 */ 	addiu	$a0,$a0,0x4
/*    350d4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    350d8:	44058000 */ 	mfc1	$a1,$f16
/*    350dc:	0c00f8f8 */ 	jal	func0003e3e0
/*    350e0:	00000000 */ 	nop
.L000350e4:
/*    350e4:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    350e8:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*    350ec:	15e0ffd2 */ 	bnez	$t7,.L00035038
/*    350f0:	afaf002c */ 	sw	$t7,0x2c($sp)
.L000350f4:
/*    350f4:	10000001 */ 	b	.L000350fc
/*    350f8:	00000000 */ 	nop
.L000350fc:
/*    350fc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    35100:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*    35104:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    35108:	03e00008 */ 	jr	$ra
/*    3510c:	00000000 */ 	nop
);

void snd0001036c(u8 arg0);
f32 func0002fc60(u8 arg0);

void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
{
	N_ALVoice          *voice;
	N_ALVoiceState     *vs;
	s32                 status;
	u8                  chan;
	u8                  key;
	u8                  vel;
	u8                  byte1;
	u8                  byte2;
	ALMIDIEvent         *midi = &event->msg.midi;
	s16                 vol;
	N_ALEvent           evt;
	ALMicroTime         deltaTime;
	N_ALVoiceState     *vstate;
	ALPan   		    pan;
	ALChanState        *chanstate;
	s32                 sp90;
	ALVoiceConfig       config;
	ALSound            *sound;
	s16                 cents;
	f32                 pitch,oscValue;
	u8                  fxmix;
	u8                  sp76;
	f32                 sp70;
	void               *oscState;
	ALInstrument       *inst;
	u8                  sp67;
	u8                  sp66;
	s32                 sp60;

	status = midi->status & AL_MIDI_StatusMask;
	chan = midi->status & AL_MIDI_ChannelMask;
	byte1 = key  = midi->byte1;
	byte2 = vel  = midi->byte2;

	switch (status) {
	case (AL_MIDI_NoteOn):

		if (vel != 0) /* a real note on */ {
			oscState = 0;

			/* If we're not playing, don't process note ons. */
			if (seqp->state != AL_PLAYING || (seqp->chanMask & (1 << chan)) == 0) {
				if (midi->duration) {
					evt.type = AL_CSP_NOTEOFF_EVT;
					evt.msg.midi.status = chan | 0x80;
					evt.msg.midi.byte1 = key;
					evt.msg.midi.byte2 = 0;

					deltaTime = seqp->uspt * midi->duration;
					var8009c350[chan] = deltaTime;

					n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
				}

				break;
			}

			chanstate = &seqp->chanState[chan];

			sound = __n_lookupSoundQuick((N_ALSeqPlayer*)seqp, key, vel, chan);
			ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
					ERR_ALSEQP_NO_SOUND);

			config.priority = chanstate->priority;
			config.fxBus = chanstate->unk0b;
			config.unityPitch = 0;

			vstate = __n_mapVoice((N_ALSeqPlayer*)seqp, key, vel, chan);
			ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK,
					ERR_ALSEQP_NO_VOICE );

			voice = &vstate->voice;

			n_alSynAllocVoice(voice, &config);

			/*
			 * set up the voice state structure
			 */
			vstate->sound = sound;
			vstate->envPhase = AL_PHASE_ATTACK;

			if (chanstate->sustain > AL_SUSTAIN) {
				vstate->phase = AL_PHASE_SUSTAIN;
			} else {
				vstate->phase = AL_PHASE_NOTEON;
			}

			cents = (key - sound->keyMap->keyBase) * 100 + sound->keyMap->detune;

			if (chanstate->unk24) {
				cents += chanstate->unk27;
			}

			vstate->pitch = alCents2Ratio(cents);

			if (chanstate->unk24) {
				vstate->envGain = chanstate->attackVolume;
				vstate->envEndTime = seqp->curTime + chanstate->attackTime;
			} else {
				vstate->envGain = sound->envelope->attackVolume;
				vstate->envEndTime = seqp->curTime + sound->envelope->attackTime;
			}

			/*
			 * setup tremelo and vibrato if active
			 */
			vstate->flags = 0;

			if (chanstate->unk24) {
				sp90 = chanstate->tremType;
			} else {
				inst = seqp->chanState[chan].instrument;
				sp90 = inst->tremType;
			}

			oscValue = (f32)AL_VOL_FULL; /* set this as a default */

			if (sp90) {
				if (seqp->initOsc) {
					if (chanstate->unk24) {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,chanstate->tremType,
								chanstate->tremRate,chanstate->tremDepth,chanstate->tremDelay, chanstate->unk31);
					} else {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->tremType,
								inst->tremRate,inst->tremDepth,inst->tremDelay, chanstate->unk31);
					}

					if (deltaTime) /* a deltaTime of zero means don't run osc */ {
						evt.type = AL_TREM_OSC_EVT;
						evt.msg.osc.vs = vstate;
						evt.msg.osc.oscState = oscState;
						n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
						vstate->flags |= 0x01; /* set tremelo flag bit */
						vstate->oscState = oscState;
					}
				}
			}

			vstate->tremelo = (u8)oscValue;

			/* will default if not changed by initOsc */

			oscValue = 1.0f; /* set this as a default */

			if (chanstate->unk24) {
				sp90 = chanstate->vibType;
			} else {
				sp90 = inst->vibType;
			}

			if (sp90) {
				if (seqp->initOsc) {
					if (chanstate->unk24) {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,chanstate->vibType,
								chanstate->vibRate,chanstate->vibDepth,chanstate->vibDelay, chanstate->unk31);
					} else {
						deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->vibType,
								inst->vibRate,inst->vibDepth,inst->vibDelay, chanstate->unk31);
					}

					if (deltaTime)  /* a deltaTime of zero means don't run osc. */ {
						evt.type = AL_VIB_OSC_EVT;
						evt.msg.osc.vs = vstate;
						evt.msg.osc.oscState = oscState;
						evt.msg.osc.chan = chan;
						n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
						vstate->flags |= 0x02; /* set the vibrato flag bit */
						vstate->oscState2 = oscState;
					}
				}
			}

			vstate->vibrato = oscValue; /* will default if not changed by initOsc */

			/*
			 * calculate the note on parameters
			 */
			pitch = vstate->pitch * chanstate->pitchBend * vstate->vibrato;

			fxmix = func0003d9cc(vstate, seqp);

			sp76 = chanstate->unk11;

			if (sp76) {
				sp70 = 440 * func0003b9d4(cents / 100 + chanstate->unk12 - 64) * chanstate->pitchBend;
			} else {
				sp70 = 127.0f;
			}

			pan = __n_vsPan(vstate, (N_ALSeqPlayer*)seqp);
			vol = __n_vsVol(vstate, (N_ALSeqPlayer*)seqp);

			if (chanstate->unk24) {
				deltaTime = chanstate->attackTime;
			} else {
				deltaTime = sound->envelope->attackTime;
			}

			n_alSynStartVoiceParams(voice, sound->wavetable,
					pitch, vol, pan, fxmix, sp76, sp70, chanstate->unk13, deltaTime);

			/*
			 * set up callbacks for envelope
			 */
			evt.type = AL_SEQP_ENV_EVT;
			evt.msg.vol.voice = voice;

			if (chanstate->unk24) {
				evt.msg.vol.vol = chanstate->decayVolume;
				evt.msg.vol.delta = chanstate->decayTime;
			} else {
				evt.msg.vol.vol = sound->envelope->decayVolume;
				evt.msg.vol.delta = sound->envelope->decayTime;
			}

			n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);

			if (midi->duration) {
				/*
				 * set up note off evt. if no duration don't do this
				 */
				evt.type            = AL_CSP_NOTEOFF_EVT;
				evt.msg.midi.status = chan | AL_MIDI_NoteOff;
				evt.msg.midi.byte1  = key;
				evt.msg.midi.byte2  = 0;   /* not needed ? */
				deltaTime = seqp->uspt * midi->duration;
				var8009c350[chan] = deltaTime;

				/* max time would be about one hour ten minutes */
				n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
			}

			if ((chanstate->unk10 & 1) && seqp->queue) {
				osSendMesg(seqp->queue, (OSMesg)(var8009c350[chan] & 0xffffff00 | chanstate->unk10 >> 2), OS_MESG_NOBLOCK);
			}

			break;
		}

		/*
		 * NOTE: intentional fall-through for note on with zero
		 * velocity (Should never happen with compact midi sequence,
		 * but could happen with real time midi.)
		 */

	case (AL_MIDI_NoteOff):
		vstate = __n_lookupVoice((N_ALSeqPlayer*)seqp, key, chan);
		ALFlagFailIf(!vstate, seqp->debugFlags & NOTE_OFF_ERR_MASK,
				ERR_ALSEQP_OFF_VOICE );

		chanstate = &seqp->chanState[chan];

		if (vstate->phase == AL_PHASE_SUSTAIN) {
			vstate->phase = AL_PHASE_SUSTREL;
		} else {
			vstate->phase = AL_PHASE_RELEASE;

			if (chanstate->unk24) {
				__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vstate->voice,
						chanstate->releaseTime);
			} else {
				__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp, &vstate->voice,
						vstate->sound->envelope->releaseTime);
			}
		}

		if ((chanstate->unk10 & 2) && seqp->queue) {
			osSendMesg(seqp->queue, (OSMesg)(key << 16 | 8 | chanstate->unk10 >> 2), OS_MESG_NOBLOCK);
		}

		break;

	case (AL_MIDI_PolyKeyPressure):
		/*
		 * Aftertouch per key (hardwired to volume). Note that
		 * aftertouch affects only notes that are already
		 * sounding.
		 */
		vstate = __n_lookupVoice((N_ALSeqPlayer*)seqp, key, chan);
		ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

		vstate->velocity = byte2;
		n_alSynSetVol( &vstate->voice,
				__n_vsVol(vstate, (N_ALSeqPlayer*)seqp),
				__n_vsDelta(vstate,seqp->curTime));
		break;

	case (AL_MIDI_ChannelPressure):
		/*
		 * Aftertouch per channel (hardwired to volume). Note that
		 * aftertouch affects only notes that are already
		 * sounding.
		 */
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
			if (vs->channel == chan) {
				vs->velocity = byte1;
				n_alSynSetVol( &vs->voice,
						__n_vsVol(vs, (N_ALSeqPlayer*)seqp),
						__n_vsDelta(vs,seqp->curTime));
			}
		}
		break;

	case (AL_MIDI_ControlChange):
		switch (byte1) {
		case (AL_MIDI_PAN_CTRL):
			seqp->chanState[chan].pan = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					pan = __n_vsPan(vs, (N_ALSeqPlayer*)seqp);
					n_alSynSetPan( &vs->voice, pan);
				}
			}
			break;
		case (0xfd):
			seqp->chanState[chan].unk0f = byte2;
			break;
		case (0xff):
			if (seqp->chanState[chan].unk0f == 0) {
				seqp->chanState[chan].unk0f = 0x90;
			}

			if (seqp->chanState[chan].unk0e != byte2) {
				if (seqp->chanState[chan].unk0e == seqp->chanState[chan].unk0d) {
					seqp->chanState[chan].unk0e = byte2;
				} else {
					seqp->chanState[chan].unk0e = byte2;
					break;
				}
			} else {
				break;
			}

			midi->byte1 = 0xfe;
			// fall-through
		case (0xfe):
			sp67 = seqp->chanState[chan].unk0d;
			sp66 = seqp->chanState[chan].unk0e;
			vel = seqp->chanState[chan].unk0f;
			sp60 = sp66 - sp67;

			if (sp60 > 0) {
				if (vel & 0x80) {
					vel = (vel & 0x7f) << 1;
				}

				if (sp60 > vel) {
					sp60 = vel;
				}
			} else {
				vel &= 0x7f;

				if (sp60 < -vel) {
					sp60 = -vel;
				}
			}

			sp67 += sp60;
			seqp->chanState[chan].unk0d = sp67;

			if (sp67 != sp66) {
				n_alEvtqPostEvent(&seqp->evtq, event, seqp->uspt * 100, 0);
			}

			if (sp67) {
				seqp->chanMask |= 1 << chan;
			} else {
				seqp->chanMask &= ~(1 << chan);
			}

			func00034f0c(seqp, chan);
			break;
		case (0xfc):
			seqp->chanState[chan].unk0d = byte2;
			seqp->chanState[chan].unk0e = byte2;

			if (byte2 == 0) {
				seqp->chanMask &= (1 << chan) ^ 0xffff;
			} else {
				seqp->chanMask |= 1 << chan;
			}

			func00034f0c(seqp, chan);
			break;
		case (0x21):
			seqp->chanState[chan].unk11 = byte2;
			func00034fb8(seqp, chan);
			break;
		case (0x22):
			seqp->chanState[chan].unk12 = byte2;
			func00034fb8(seqp, chan);
			break;
		case (0x23):
			seqp->chanState[chan].unk13 = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					func0003e730(&vs->voice, byte2);
				}
			}
			break;
		case (0x1e):
			if (seqp->queue) {
				osSendMesg(seqp->queue, (OSMesg)(byte2 & 7 | 0x10 | (seqp->node.samplesLeft << 5) & 0xffffff00), OS_MESG_NOBLOCK);
			}
			break;
		case (AL_MIDI_VOLUME_CTRL):
			seqp->chanState[chan].vol = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE)) {
					vol = __n_vsVol(vs, (N_ALSeqPlayer*)seqp);
					n_alSynSetVol(&vs->voice, vol, __n_vsDelta(vs,seqp->curTime));
				}
			}
			break;
		case (AL_MIDI_PRIORITY_CTRL):
			/* leave current voices where they are */
			seqp->chanState[chan].priority = byte2;
			break;
		case (AL_MIDI_SUSTAIN_CTRL):
			seqp->chanState[chan].sustain = byte2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if ((vs->channel == chan) && (vs->phase != AL_PHASE_RELEASE)) {
					if ( byte2 > AL_SUSTAIN ) {
						/*
						 * sustain pedal down
						 */
						if (vs->phase == AL_PHASE_NOTEON) {
							vs->phase = AL_PHASE_SUSTAIN;
						}
					} else {
						/*
						 * sustain pedal up
						 */
						if (vs->phase == AL_PHASE_SUSTAIN) {
							vs->phase = AL_PHASE_NOTEON;
						} else if (vs->phase == AL_PHASE_SUSTREL) {
							vs->phase = AL_PHASE_RELEASE;

#define MIN_RELEASE_TIME (PAL ? 20000 : 16000)

							if (chanstate->unk24) {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										(seqp->chanState[chan].releaseTime < MIN_RELEASE_TIME ? MIN_RELEASE_TIME : seqp->chanState[chan].releaseTime));
							} else {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										vstate->sound->envelope->releaseTime < MIN_RELEASE_TIME ? MIN_RELEASE_TIME : vstate->sound->envelope->releaseTime);
							}
						}
					}
				}
			}
			break;
		case (AL_MIDI_FX1_CTRL):
			seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x80) | byte2;
			byte2 = seqp->chanState[chan].fxmix >> 7;
			// fall-through
		case (0x41):
			seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x7f) | (byte2 << 7);

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					n_alSynSetFXMix(&vs->voice, seqp->chanState[chan].fxmix);
				}
			}
			break;
		case (0x5c):
			if (byte2 < n_syn->maxAuxBusses) {
				seqp->chanState[chan].unk0b = byte2;
			}
			break;
		case (AL_MIDI_FX_CTRL_6):
			snd0001036c(byte2);
			break;
		case (0x20):
			seqp->chanState[chan].unk32 = byte2;
			break;
		case (AL_MIDI_FX_CTRL_0):
			seqp->chanState[chan].attackTime = var8005f150[byte2];
			seqp->chanState[chan].unk24 = 1;
			break;
		case (AL_MIDI_FX_CTRL_1):
			seqp->chanState[chan].attackVolume = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (AL_MIDI_FX_CTRL_2):
			seqp->chanState[chan].decayTime = var8005f150[byte2];
			seqp->chanState[chan].unk24 = 1;
			break;
		case (AL_MIDI_FX_CTRL_3):
			seqp->chanState[chan].decayVolume = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (AL_MIDI_FX_CTRL_4):
			seqp->chanState[chan].releaseTime = var8005f150[byte2];
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x02):
			seqp->chanState[chan].unk27 = byte2 - 64;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x03):
			seqp->chanState[chan].bendRange /= 100;
			seqp->chanState[chan].bendRange *= 100;
			seqp->chanState[chan].bendRange += byte2;
			break;
		case (0x04):
			seqp->chanState[chan].bendRange %= 100;
			seqp->chanState[chan].bendRange += byte2 * 100;
			break;
		case (0x0b):
			if (byte2) {
				byte2 += 0x80;
			}

			seqp->chanState[chan].vibType = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x0c):
			seqp->chanState[chan].vibRate = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x0d):
			seqp->chanState[chan].vibDepth = byte2 * 2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x0e):
			seqp->chanState[chan].vibDelay = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x0f):
			seqp->chanState[chan].tremType = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x11):
			seqp->chanState[chan].tremRate = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x12):
			seqp->chanState[chan].tremDepth = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x13):
			seqp->chanState[chan].tremDelay = byte2;
			seqp->chanState[chan].unk24 = 1;
			break;
		case (0x01):
			byte2 *= 2;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan && vs->oscState2) {
					struct oscstate *sp5c = vs->oscState2;

					switch (sp5c->unk04 & 0xffffff7f) {
					case 0x02:
						sp5c->unk10 = -func0002fc60(byte2);
						// fall-through
					case 0x03:
					case 0x04:
					case 0x05:
						sp5c->unk0c = func0002fc60(byte2);
						break;
					case 0x07:
					case 0x09:
					case 0x0d:
						sp5c->unk0c = func0002fc60(byte2) / 2.0f;
						break;
					case 0x0a:
						sp5c->unk0c = func0002fc60(byte2) * 2.0f;
						break;
					default:
						sp5c->unk0c = func0002fc60(byte2);
						break;
					}
				}
			}
			break;
		case 0x19:
			seqp->chanState[chan].unk31 = byte2;
			break;
		default:
			break;
		}
		break;
	case (AL_MIDI_ProgramChange):
		/* sct 1/16/96 - We must have a valid bank in order to process the program change. */
		sp90 = (seqp->chanState[chan].unk32 << 7) + key;

		if (sp90 < seqp->bank->instCount) {
			ALInstrument *inst = seqp->bank->instArray[sp90];
			__n_setInstChanState((N_ALSeqPlayer*)seqp, inst, chan);	/* sct 11/6/95 */
		} else {
			// empty
		}
		break;
	case (AL_MIDI_PitchBendChange):
		{
			s32 bendVal;
			f32 bendRatio;
			s32 cents;

			/* get 14-bit unsigned midi value */
			bendVal = ((byte2 << 7) + byte1) - 8192;

			/* calculate pitch bend in cents */
			cents = seqp->chanState[chan].bendRange * bendVal / 8192;

			/* calculate the corresponding ratio  */
			bendRatio = alCents2Ratio(cents);
			seqp->chanState[chan].pitchBend = bendRatio;

			for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
				if (vs->channel == chan) {
					n_alSynSetPitch( &vs->voice, vs->pitch * bendRatio * vs->vibrato);

					if (seqp->chanState[chan].unk11) {
						func0003e3e0(&vs->voice, 440 * func0003b9d4(seqp->chanState[chan].unk12 + (vs->key - vs->sound->keyMap->keyBase) - 64) * bendRatio * vs->vibrato);
					}
				}
			}

		}
		break;

	default:
		break;
	}
}

void __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
{
	ALTempoEvent *tevt = &event->msg.tempo;
	s32 tempo;
	s32 oldUspt;
	u32 ticks;
	ALMicroTime tempDelta, curDelta = 0;
	N_ALEventListItem *thisNode, *nextNode, *firstTemp = 0;

	if (event->msg.tempo.status == AL_MIDI_Meta) {
		if (event->msg.tempo.type == AL_MIDI_META_TEMPO) {
			oldUspt = seqp->uspt;
			tempo = (tevt->byte1 << 16) | (tevt->byte2 <<  8) | (tevt->byte3 <<  0);
			__n_setUsptFromTempo(seqp, (f32)tempo);

			thisNode = (N_ALEventListItem*)seqp->evtq.allocList.next;

			while (thisNode) {
				curDelta += thisNode->delta;
				nextNode = (N_ALEventListItem*)thisNode->node.next;

				if (thisNode->evt.type == AL_CSP_NOTEOFF_EVT) {
					alUnlink((ALLink*)thisNode);

					if (firstTemp) {
						alLink((ALLink*)thisNode,(ALLink*)firstTemp);
					} else {
						thisNode->node.next = 0;
						thisNode->node.prev = 0;
						firstTemp = thisNode;
					}

					tempDelta = curDelta;         /* record the current delta */

					if (nextNode) {/* don't do this if no nextNode */
						curDelta -= thisNode->delta;  /* subtract out this delta */
						nextNode->delta += thisNode->delta; /* add it to next event */
					}

					thisNode->delta = tempDelta; /* set this event delta from current */
				}

				thisNode = nextNode;
			}

			thisNode = firstTemp;

			while (thisNode) {
				nextNode = (N_ALEventListItem*)thisNode->node.next;
				ticks = thisNode->delta/oldUspt;
				thisNode->delta = ticks * seqp->uspt;
				__n_CSPRepostEvent(&seqp->evtq,thisNode);
				thisNode = nextNode;
			}
		}
	}
}

void __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item)
{
	OSIntMask mask;
	ALLink *node;
	N_ALEventListItem *nextItem;

	mask = osSetIntMask(OS_IM_NONE);

	for (node = &evtq->allocList; node != 0; node = node->next) {
		if (!node->next) {
			alLink((ALLink *)item, node);
			break;
		} else {
			nextItem = (N_ALEventListItem *)node->next;

			if (item->delta < nextItem->delta) {
				nextItem->delta -= item->delta;
				alLink((ALLink *)item, node);
				break;
			}

			item->delta -= nextItem->delta;
		}
	}

	osSetIntMask(mask);
}

void __n_setUsptFromTempo(N_ALCSPlayer *seqp, f32 tempo)
{
	if (seqp->target) {
		seqp->uspt = (s32)((f32)tempo * seqp->target->qnpt);
	} else {
		seqp->uspt = 488;
	}
}

void __n_CSPPostNextSeqEvent(N_ALCSPlayer *seqp)
{
	N_ALEvent evt;
	s32 deltaTicks;

	if (seqp->state != AL_PLAYING || seqp->target == NULL) {
		return;
	}

	/* Get the next event time in ticks. */
	/* If false is returned, then there is no next delta (ie. end of sequence reached). */
	if (!__alCSeqNextDelta(seqp->target, &deltaTicks)) {
		return;
	}

	evt.type = AL_SEQ_REF_EVT;
	n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt, 0);
}

void func00037634(N_ALCSPlayer *seqp, u8 value)
{
	seqp->unk88 = value;
}
