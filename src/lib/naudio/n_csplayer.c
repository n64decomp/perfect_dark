#include "versions.h"
#include <libaudio.h>
#include <os_convert.h>
#include <os_internal.h>
#include <ultraerror.h>
#include "n_libaudio.h"
#include "n_seqp.h"
#include "cseq.h"
#include "n_cseqp.h"

static void __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item);
static void __n_setUsptFromTempo(N_ALCSPlayer *seqp, f32 tempo);
static void __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event);
ALMicroTime __n_vsDelta(N_ALVoiceState *vs, ALMicroTime t);
static void __n_CSPPostNextSeqEvent(N_ALCSPlayer *seqp);

u32 var8009c350[16];

// 110000 occurs twice in this table...
s32 var8005f150[] = {
	0,         10000,     20000,     30000,
	40000,     50000,     60000,     70000,
	80000,     90000,     100000,    110000,
	110000,    120000,    130000,    140000,
	150000,    160000,    170000,    190000,
	200000,    220000,    230000,    250000,
	270000,    290000,    310000,    330000,
	350000,    380000,    410000,    440000,
	470000,    500000,    540000,    580000,
	620000,    660000,    710000,    760000,
	820000,    880000,    940000,    1000000,
	1000000,   1100000,   1200000,   1300000,
	1400000,   1500000,   1600000,   1700000,
	1800000,   2000000,   2100000,   2300000,
	2400000,   2600000,   2800000,   3000000,
	3200000,   3500000,   3700000,   4000000,
	4300000,   4600000,   4900000,   5300000,
	5700000,   6100000,   6500000,   7000000,
	7500000,   8100000,   8600000,   9300000,
	9900000,   10000000,  11000000,  12000000,
	13000000,  14000000,  15000000,  16000000,
	17000000,  18000000,  19000000,  21000000,
	22000000,  24000000,  26000000,  28000000,
	30000000,  32000000,  34000000,  37000000,
	39000000,  42000000,  45000000,  49000000,
	50000000,  55000000,  60000000,  65000000,
	70000000,  75000000,  80000000,  85000000,
	90000000,  95000000,  100000000, 105000000,
	110000000, 115000000, 120000000, 125000000,
	130000000, 135000000, 140000000, 145000000,
	150000000, 155000000, 160000000, 165000000,
	170000000, 175000000, 180000000,
};

f32 var8005f34c[100] = {
	0.05,  0.05, 0.06,  0.06, 0.06,  0.07, 0.07,  0.08, 0.08,  0.09,
	0.10,  0.11, 0.13,  0.14, 0.17,  0.20, 0.25,  0.33, 0.5,   1,
	1.25,  1.5,  1.75,  2,    2.25,  2.5,  2.75,  3,    3.25,  3.5,
	3.75,  4,    4.25,  4.5,  4.75,  5,    5.25,  5.5,  5.75,  6,
	6.25,  6.5,  6.75,  7,    7.25,  7.5,  7.75,  8,    8.25,  8.5,
	8.75,  9,    9.25,  9.5,  9.75,  10,   10.25, 10.5, 10.75, 11,
	11.25, 11.5, 11.75, 12,   12.25, 12.5, 12.75, 13,   13.25, 13.5,
	13.75, 14,   14.25, 14.5, 14.75, 15,   15.25, 15.5, 15.75, 16,
	16.25, 16.5, 16.75, 17,   17.25, 17.5, 17.75, 18,   18.25, 18.5,
	18.75, 19,   19.25, 19.5, 19.75, 20,   20.25, 20.5, 20.75, 21,
};

void func00039cd0(N_ALCSPlayer *seqp);
static ALMicroTime __n_CSPVoiceHandler(void *node);

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

static void __n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp);
static void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event);

void n_alSynFilter13(N_ALVoice *v, f32 arg1);
u8 func0003d9cc(N_ALVoiceState *vs, N_ALCSPlayer *seqp);
ALFxRef func0003e540(u8 arg0);
ALFxRef func0003e5b8(u8 arg0);
void func0003e674(struct fx *fx, u8 arg1, void *param);
f32 func0003b9d4(s32 arg0);

static ALMicroTime __n_CSPVoiceHandler(void *node)
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
				n_alSynFilter13(&vs->voice,
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
					n_alSynSetFXParam(fx,
							(seqp->nextEvent.msg.evt19.unk02 << 3) | (seqp->nextEvent.msg.evt19.unk01 & 7),
							&seqp->nextEvent.msg.evt19.param);
				}
			} else {
				ALFxRef fx = func0003e5b8(seqp->nextEvent.msg.evt19.unk00);

				if (fx) {
					func0003e674((struct fx *) fx, seqp->nextEvent.msg.evt19.unk01, &seqp->nextEvent.msg.evt19.param);
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
static void __n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp)
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
		seqp->state = AL_STOPPING;
		evt.type    = AL_SEQP_STOP_EVT;
		n_alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END, 0);
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

static void func00034f0c(N_ALCSPlayer *seqp, u8 channel)
{
	N_ALVoiceState *vs;

	for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
		if (vs->channel == channel && vs->envPhase != AL_PHASE_RELEASE) {
			s16 volume = __n_vsVol(vs, (N_ALSeqPlayer *) seqp);

			n_alSynSetVol(&vs->voice, volume, __n_vsDelta(vs, seqp->curTime));
		}
	}
}

static void func00034fb8(N_ALCSPlayer *seqp, u8 channel)
{
	N_ALVoiceState *vs;
	s16 sp2a;
	s8 sp29 = (s8)seqp->chanState[channel].unk12 - 64;
	f32 sp24 = seqp->chanState[channel].pitchBend;

	for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		if (vs->channel == channel) {
			sp2a = seqp->chanState[channel].unk11;

			n_alSynFilter12(&vs->voice, sp2a);

			if (sp2a) {
				n_alSynFilter13(&vs->voice, func0003b9d4((vs->key - vs->sound->keyMap->keyBase) + sp29) * 440 * sp24);
			}
		}
	}
}

void sndStartMp3ByFilenum(u8 arg0);
f32 _depth2Cents(u8 arg0);

static void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
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
				osSendMesg(seqp->queue, (OSMesg)((var8009c350[chan] & 0xffffff00) | (chanstate->unk10 >> 2)), OS_MESG_NOBLOCK);
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
					n_alSynFilter11(&vs->voice, byte2);
				}
			}
			break;
		case (0x1e):
			if (seqp->queue) {
				osSendMesg(seqp->queue, (OSMesg)((byte2 & 7) | 0x10 | ((seqp->node.samplesLeft << 5) & 0xffffff00)), OS_MESG_NOBLOCK);
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

							// @bug: chanstate is uninitialised
							if (chanstate->unk24) {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										(seqp->chanState[chan].releaseTime < AL_USEC_PER_FRAME ? AL_USEC_PER_FRAME : seqp->chanState[chan].releaseTime));
							} else {
								__n_seqpReleaseVoice((N_ALSeqPlayer*)seqp,
										&vs->voice,
										vstate->sound->envelope->releaseTime < AL_USEC_PER_FRAME ? AL_USEC_PER_FRAME : vstate->sound->envelope->releaseTime);
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
			sndStartMp3ByFilenum(byte2);
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
						sp5c->unk10 = -_depth2Cents(byte2);
						// fall-through
					case 0x03:
					case 0x04:
					case 0x05:
						sp5c->unk0c = _depth2Cents(byte2);
						break;
					case 0x07:
					case 0x09:
					case 0x0d:
						sp5c->unk0c = _depth2Cents(byte2) / 2.0f;
						break;
					case 0x0a:
						sp5c->unk0c = _depth2Cents(byte2) * 2.0f;
						break;
					default:
						sp5c->unk0c = _depth2Cents(byte2);
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
						n_alSynFilter13(&vs->voice, 440 * func0003b9d4(seqp->chanState[chan].unk12 + (vs->key - vs->sound->keyMap->keyBase) - 64) * bendRatio * vs->vibrato);
					}
				}
			}

		}
		break;

	default:
		break;
	}
}

static void __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
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

static void __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item)
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

static void __n_setUsptFromTempo(N_ALCSPlayer *seqp, f32 tempo)
{
	if (seqp->target) {
		seqp->uspt = (s32)((f32)tempo * seqp->target->qnpt);
	} else {
		seqp->uspt = 488;
	}
}

static void __n_CSPPostNextSeqEvent(N_ALCSPlayer *seqp)
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
