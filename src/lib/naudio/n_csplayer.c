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

u32 var8005f150 = 0x00000000;
u32 var8005f154 = 0x00002710;
u32 var8005f158 = 0x00004e20;
u32 var8005f15c = 0x00007530;
u32 var8005f160 = 0x00009c40;
u32 var8005f164 = 0x0000c350;
u32 var8005f168 = 0x0000ea60;
u32 var8005f16c = 0x00011170;
u32 var8005f170 = 0x00013880;
u32 var8005f174 = 0x00015f90;
u32 var8005f178 = 0x000186a0;
u32 var8005f17c = 0x0001adb0;
u32 var8005f180 = 0x0001adb0;
u32 var8005f184 = 0x0001d4c0;
u32 var8005f188 = 0x0001fbd0;
u32 var8005f18c = 0x000222e0;
u32 var8005f190 = 0x000249f0;
u32 var8005f194 = 0x00027100;
u32 var8005f198 = 0x00029810;
u32 var8005f19c = 0x0002e630;
u32 var8005f1a0 = 0x00030d40;
u32 var8005f1a4 = 0x00035b60;
u32 var8005f1a8 = 0x00038270;
u32 var8005f1ac = 0x0003d090;
u32 var8005f1b0 = 0x00041eb0;
u32 var8005f1b4 = 0x00046cd0;
u32 var8005f1b8 = 0x0004baf0;
u32 var8005f1bc = 0x00050910;
u32 var8005f1c0 = 0x00055730;
u32 var8005f1c4 = 0x0005cc60;
u32 var8005f1c8 = 0x00064190;
u32 var8005f1cc = 0x0006b6c0;
u32 var8005f1d0 = 0x00072bf0;
u32 var8005f1d4 = 0x0007a120;
u32 var8005f1d8 = 0x00083d60;
u32 var8005f1dc = 0x0008d9a0;
u32 var8005f1e0 = 0x000975e0;
u32 var8005f1e4 = 0x000a1220;
u32 var8005f1e8 = 0x000ad570;
u32 var8005f1ec = 0x000b98c0;
u32 var8005f1f0 = 0x000c8320;
u32 var8005f1f4 = 0x000d6d80;
u32 var8005f1f8 = 0x000e57e0;
u32 var8005f1fc = 0x000f4240;
u32 var8005f200 = 0x000f4240;
u32 var8005f204 = 0x0010c8e0;
u32 var8005f208 = 0x00124f80;
u32 var8005f20c = 0x0013d620;
u32 var8005f210 = 0x00155cc0;
u32 var8005f214 = 0x0016e360;
u32 var8005f218 = 0x00186a00;
u32 var8005f21c = 0x0019f0a0;
u32 var8005f220 = 0x001b7740;
u32 var8005f224 = 0x001e8480;
u32 var8005f228 = 0x00200b20;
u32 var8005f22c = 0x00231860;
u32 var8005f230 = 0x00249f00;
u32 var8005f234 = 0x0027ac40;
u32 var8005f238 = 0x002ab980;
u32 var8005f23c = 0x002dc6c0;
u32 var8005f240 = 0x0030d400;
u32 var8005f244 = 0x003567e0;
u32 var8005f248 = 0x00387520;
u32 var8005f24c = 0x003d0900;
u32 var8005f250 = 0x00419ce0;
u32 var8005f254 = 0x004630c0;
u32 var8005f258 = 0x004ac4a0;
u32 var8005f25c = 0x0050df20;
u32 var8005f260 = 0x0056f9a0;
u32 var8005f264 = 0x005d1420;
u32 var8005f268 = 0x00632ea0;
u32 var8005f26c = 0x006acfc0;
u32 var8005f270 = 0x007270e0;
u32 var8005f274 = 0x007b98a0;
u32 var8005f278 = 0x008339c0;
u32 var8005f27c = 0x008de820;
u32 var8005f280 = 0x00970fe0;
u32 var8005f284 = 0x00989680;
u32 var8005f288 = 0x00a7d8c0;
u32 var8005f28c = 0x00b71b00;
u32 var8005f290 = 0x00c65d40;
u32 var8005f294 = 0x00d59f80;
u32 var8005f298 = 0x00e4e1c0;
u32 var8005f29c = 0x00f42400;
u32 var8005f2a0 = 0x01036640;
u32 var8005f2a4 = 0x0112a880;
u32 var8005f2a8 = 0x0121eac0;
u32 var8005f2ac = 0x01406f40;
u32 var8005f2b0 = 0x014fb180;
u32 var8005f2b4 = 0x016e3600;
u32 var8005f2b8 = 0x018cba80;
u32 var8005f2bc = 0x01ab3f00;
u32 var8005f2c0 = 0x01c9c380;
u32 var8005f2c4 = 0x01e84800;
u32 var8005f2c8 = 0x0206cc80;
u32 var8005f2cc = 0x02349340;
u32 var8005f2d0 = 0x025317c0;
u32 var8005f2d4 = 0x0280de80;
u32 var8005f2d8 = 0x02aea540;
u32 var8005f2dc = 0x02ebae40;
u32 var8005f2e0 = 0x02faf080;
u32 var8005f2e4 = 0x03473bc0;
u32 var8005f2e8 = 0x03938700;
u32 var8005f2ec = 0x03dfd240;
u32 var8005f2f0 = 0x042c1d80;
u32 var8005f2f4 = 0x047868c0;
u32 var8005f2f8 = 0x04c4b400;
u32 var8005f2fc = 0x0510ff40;
u32 var8005f300 = 0x055d4a80;
u32 var8005f304 = 0x05a995c0;
u32 var8005f308 = 0x05f5e100;
u32 var8005f30c = 0x06422c40;
u32 var8005f310 = 0x068e7780;
u32 var8005f314 = 0x06dac2c0;
u32 var8005f318 = 0x07270e00;
u32 var8005f31c = 0x07735940;
u32 var8005f320 = 0x07bfa480;
u32 var8005f324 = 0x080befc0;
u32 var8005f328 = 0x08583b00;
u32 var8005f32c = 0x08a48640;
u32 var8005f330 = 0x08f0d180;
u32 var8005f334 = 0x093d1cc0;
u32 var8005f338 = 0x09896800;
u32 var8005f33c = 0x09d5b340;
u32 var8005f340 = 0x0a21fe80;
u32 var8005f344 = 0x0a6e49c0;
u32 var8005f348 = 0x0aba9500;
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
	seqp->unk84 = 0;
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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel __n_CSPHandleMIDIMsg
.late_rodata
glabel var70054838
.word __n_CSPHandleMIDIMsg+0x0934
glabel var7005483c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054840
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054844
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054848
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005484c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054850
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054854
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054858
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005485c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054860
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054864
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054868
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005486c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054870
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054874
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054878
.word __n_CSPHandleMIDIMsg+0x0094
glabel var7005487c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054880
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054884
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054888
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005488c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054890
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054894
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054898
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005489c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548ac
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b8
.word __n_CSPHandleMIDIMsg+0x0a58
glabel var700548bc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548cc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548dc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548ec
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f8
.word __n_CSPHandleMIDIMsg+0x0b54
glabel var700548fc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054900
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054904
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054908
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005490c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054910
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054914
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054918
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005491c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054920
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054924
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054928
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005492c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054930
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054934
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054938
.word __n_CSPHandleMIDIMsg+0x1ea4
glabel var7005493c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054940
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054944
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054948
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005494c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054950
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054954
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054958
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005495c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054960
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054964
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054968
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005496c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054970
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054974
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054978
.word __n_CSPHandleMIDIMsg+0x0ad0
glabel var7005497c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054980
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054984
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054988
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005498c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054990
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054994
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054998
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005499c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549ac
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b8
.word __n_CSPHandleMIDIMsg+0x1f34

glabel var700549bc
.word __n_CSPHandleMIDIMsg+0x1d3c
glabel var700549c0
.word __n_CSPHandleMIDIMsg+0x1878
glabel var700549c4
.word __n_CSPHandleMIDIMsg+0x18dc
glabel var700549c8
.word __n_CSPHandleMIDIMsg+0x1994
glabel var700549cc
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549d0
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549d4
.word __n_CSPHandleMIDIMsg+0x1218
glabel var700549d8
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549dc
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549e0
.word __n_CSPHandleMIDIMsg+0x0c30
glabel var700549e4
.word __n_CSPHandleMIDIMsg+0x1a20
glabel var700549e8
.word __n_CSPHandleMIDIMsg+0x1a98
glabel var700549ec
.word __n_CSPHandleMIDIMsg+0x1af8
glabel var700549f0
.word __n_CSPHandleMIDIMsg+0x1b5c
glabel var700549f4
.word __n_CSPHandleMIDIMsg+0x1bbc
glabel var700549f8
.word __n_CSPHandleMIDIMsg+0x12c8
glabel var700549fc
.word __n_CSPHandleMIDIMsg+0x1c1c
glabel var70054a00
.word __n_CSPHandleMIDIMsg+0x1c7c
glabel var70054a04
.word __n_CSPHandleMIDIMsg+0x1cdc
glabel var70054a08
.word __n_CSPHandleMIDIMsg+0x1668
glabel var70054a0c
.word __n_CSPHandleMIDIMsg+0x16d8
glabel var70054a10
.word __n_CSPHandleMIDIMsg+0x1738
glabel var70054a14
.word __n_CSPHandleMIDIMsg+0x17a8
glabel var70054a18
.word __n_CSPHandleMIDIMsg+0x1808
glabel var70054a1c
.word __n_CSPHandleMIDIMsg+0x1e60
glabel var70054a20
.word __n_CSPHandleMIDIMsg+0x1624
glabel var70054a24
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a28
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a2c
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a30
.word __n_CSPHandleMIDIMsg+0x11d0
glabel var70054a34
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a38
.word __n_CSPHandleMIDIMsg+0x1634
glabel var70054a3c
.word __n_CSPHandleMIDIMsg+0x10d8
glabel var70054a40
.word __n_CSPHandleMIDIMsg+0x1118
glabel var70054a44
.word __n_CSPHandleMIDIMsg+0x1158
glabel var70054a48
.word __n_CSPHandleMIDIMsg+0x1dbc
glabel var70054a4c
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a50
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a54
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a58
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a5c
.word __n_CSPHandleMIDIMsg+0x1de8
glabel var70054a60
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a64
.word __n_CSPHandleMIDIMsg+0x1de8
glabel var70054a68
.word __n_CSPHandleMIDIMsg+0x1e0c
glabel var70054a6c
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a70
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a74
.word __n_CSPHandleMIDIMsg+0x1de8
.text
/*    35110:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    35114:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    35118:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*    3511c:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*    35120:	afb10038 */ 	sw	$s1,0x38($sp)
/*    35124:	afb00034 */ 	sw	$s0,0x34($sp)
/*    35128:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*    3512c:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*    35130:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*    35134:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*    35138:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    3513c:	93190004 */ 	lbu	$t9,0x4($t8)
/*    35140:	332800f0 */ 	andi	$t0,$t9,0xf0
/*    35144:	afa800c4 */ 	sw	$t0,0xc4($sp)
/*    35148:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*    3514c:	912a0004 */ 	lbu	$t2,0x4($t1)
/*    35150:	314b000f */ 	andi	$t3,$t2,0xf
/*    35154:	a3ab00c3 */ 	sb	$t3,0xc3($sp)
/*    35158:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    3515c:	918d0005 */ 	lbu	$t5,0x5($t4)
/*    35160:	a3ad00c2 */ 	sb	$t5,0xc2($sp)
/*    35164:	a3ad00c0 */ 	sb	$t5,0xc0($sp)
/*    35168:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3516c:	91cf0006 */ 	lbu	$t7,0x6($t6)
/*    35170:	a3af00c1 */ 	sb	$t7,0xc1($sp)
/*    35174:	a3af00bf */ 	sb	$t7,0xbf($sp)
/*    35178:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*    3517c:	2719ff80 */ 	addiu	$t9,$t8,-128
/*    35180:	2f210061 */ 	sltiu	$at,$t9,0x61
/*    35184:	1020081c */ 	beqz	$at,.L000371f8
/*    35188:	00000000 */ 	nop
/*    3518c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35190:	3c017005 */ 	lui	$at,%hi(var70054838)
/*    35194:	00390821 */ 	addu	$at,$at,$t9
/*    35198:	8c394838 */ 	lw	$t9,%lo(var70054838)($at)
/*    3519c:	03200008 */ 	jr	$t9
/*    351a0:	00000000 */ 	nop
/*    351a4:	93a800c1 */ 	lbu	$t0,0xc1($sp)
/*    351a8:	11000226 */ 	beqz	$t0,.L00035a44
/*    351ac:	00000000 */ 	nop
/*    351b0:	afa0006c */ 	sw	$zero,0x6c($sp)
/*    351b4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    351b8:	24010001 */ 	addiu	$at,$zero,0x1
/*    351bc:	8d2a002c */ 	lw	$t2,0x2c($t1)
/*    351c0:	15410008 */ 	bne	$t2,$at,.L000351e4
/*    351c4:	00000000 */ 	nop
/*    351c8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    351cc:	952b0030 */ 	lhu	$t3,0x30($t1)
/*    351d0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    351d4:	018d7004 */ 	sllv	$t6,$t5,$t4
/*    351d8:	016e7824 */ 	and	$t7,$t3,$t6
/*    351dc:	15e00023 */ 	bnez	$t7,.L0003526c
/*    351e0:	00000000 */ 	nop
.L000351e4:
/*    351e4:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    351e8:	8f190008 */ 	lw	$t9,0x8($t8)
/*    351ec:	1320001d */ 	beqz	$t9,.L00035264
/*    351f0:	00000000 */ 	nop
/*    351f4:	24080015 */ 	addiu	$t0,$zero,0x15
/*    351f8:	a7a800a4 */ 	sh	$t0,0xa4($sp)
/*    351fc:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35200:	35490080 */ 	ori	$t1,$t2,0x80
/*    35204:	a3a900ac */ 	sb	$t1,0xac($sp)
/*    35208:	93ad00c2 */ 	lbu	$t5,0xc2($sp)
/*    3520c:	a3ad00ad */ 	sb	$t5,0xad($sp)
/*    35210:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    35214:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35218:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3521c:	8d8b0024 */ 	lw	$t3,0x24($t4)
/*    35220:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    35224:	016f0019 */ 	multu	$t3,$t7
/*    35228:	0000c012 */ 	mflo	$t8
/*    3522c:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*    35230:	00000000 */ 	nop
/*    35234:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35238:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*    3523c:	3c01800a */ 	lui	$at,%hi(var8009c350)
/*    35240:	00085080 */ 	sll	$t2,$t0,0x2
/*    35244:	002a0821 */ 	addu	$at,$at,$t2
/*    35248:	ac39c350 */ 	sw	$t9,%lo(var8009c350)($at)
/*    3524c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35250:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35254:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35258:	00003825 */ 	or	$a3,$zero,$zero
/*    3525c:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35260:	24840048 */ 	addiu	$a0,$a0,0x48
.L00035264:
/*    35264:	100007e6 */ 	b	.L00037200
/*    35268:	00000000 */ 	nop
.L0003526c:
/*    3526c:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35270:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35274:	000c7080 */ 	sll	$t6,$t4,0x2
/*    35278:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    3527c:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    35280:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35284:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    35288:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3528c:	01ae5821 */ 	addu	$t3,$t5,$t6
/*    35290:	afab0094 */ 	sw	$t3,0x94($sp)
/*    35294:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35298:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    3529c:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352a0:	0c00f5cb */ 	jal	__n_lookupSoundQuick
/*    352a4:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352a8:	afa20084 */ 	sw	$v0,0x84($sp)
/*    352ac:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    352b0:	15e00003 */ 	bnez	$t7,.L000352c0
/*    352b4:	00000000 */ 	nop
/*    352b8:	100007d3 */ 	b	.L00037208
/*    352bc:	00000000 */ 	nop
.L000352c0:
/*    352c0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    352c4:	93080008 */ 	lbu	$t0,0x8($t8)
/*    352c8:	a7a80088 */ 	sh	$t0,0x88($sp)
/*    352cc:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    352d0:	932a000b */ 	lbu	$t2,0xb($t9)
/*    352d4:	a7aa008a */ 	sh	$t2,0x8a($sp)
/*    352d8:	a3a0008c */ 	sb	$zero,0x8c($sp)
/*    352dc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    352e0:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    352e4:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352e8:	0c00f576 */ 	jal	__n_mapVoice
/*    352ec:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352f0:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    352f4:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    352f8:	15200003 */ 	bnez	$t1,.L00035308
/*    352fc:	00000000 */ 	nop
/*    35300:	100007c1 */ 	b	.L00037208
/*    35304:	00000000 */ 	nop
.L00035308:
/*    35308:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    3530c:	258d0004 */ 	addiu	$t5,$t4,0x4
/*    35310:	afad00cc */ 	sw	$t5,0xcc($sp)
/*    35314:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    35318:	0c00f278 */ 	jal	func0003c9e0
/*    3531c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*    35320:	8fae0084 */ 	lw	$t6,0x84($sp)
/*    35324:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35328:	ad6e0020 */ 	sw	$t6,0x20($t3)
/*    3532c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35330:	a1e00034 */ 	sb	$zero,0x34($t7)
/*    35334:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35338:	9308000c */ 	lbu	$t0,0xc($t8)
/*    3533c:	29010040 */ 	slti	$at,$t0,0x40
/*    35340:	14200005 */ 	bnez	$at,.L00035358
/*    35344:	00000000 */ 	nop
/*    35348:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    3534c:	24190002 */ 	addiu	$t9,$zero,0x2
/*    35350:	10000003 */ 	b	.L00035360
/*    35354:	a1590035 */ 	sb	$t9,0x35($t2)
.L00035358:
/*    35358:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    3535c:	a1200035 */ 	sb	$zero,0x35($t1)
.L00035360:
/*    35360:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35364:	93ac00c2 */ 	lbu	$t4,0xc2($sp)
/*    35368:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3536c:	91cb0004 */ 	lbu	$t3,0x4($t6)
/*    35370:	81c80005 */ 	lb	$t0,0x5($t6)
/*    35374:	018b7823 */ 	subu	$t7,$t4,$t3
/*    35378:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3537c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    35380:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    35384:	030fc021 */ 	addu	$t8,$t8,$t7
/*    35388:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3538c:	0308c821 */ 	addu	$t9,$t8,$t0
/*    35390:	a7b90082 */ 	sh	$t9,0x82($sp)
/*    35394:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35398:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3539c:	11200006 */ 	beqz	$t1,.L000353b8
/*    353a0:	00000000 */ 	nop
/*    353a4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    353a8:	87ad0082 */ 	lh	$t5,0x82($sp)
/*    353ac:	818b0027 */ 	lb	$t3,0x27($t4)
/*    353b0:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    353b4:	a7af0082 */ 	sh	$t7,0x82($sp)
.L000353b8:
/*    353b8:	0c00e7f8 */ 	jal	func00039fe0
/*    353bc:	87a40082 */ 	lh	$a0,0x82($sp)
/*    353c0:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    353c4:	e5c00028 */ 	swc1	$f0,0x28($t6)
/*    353c8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    353cc:	93080024 */ 	lbu	$t0,0x24($t8)
/*    353d0:	1100000d */ 	beqz	$t0,.L00035408
/*    353d4:	00000000 */ 	nop
/*    353d8:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    353dc:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    353e0:	932a0025 */ 	lbu	$t2,0x25($t9)
/*    353e4:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    353e8:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    353ec:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    353f0:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    353f4:	8d8d001c */ 	lw	$t5,0x1c($t4)
/*    353f8:	8d6f0018 */ 	lw	$t7,0x18($t3)
/*    353fc:	01af7021 */ 	addu	$t6,$t5,$t7
/*    35400:	1000000e */ 	b	.L0003543c
/*    35404:	af0e0024 */ 	sw	$t6,0x24($t8)
.L00035408:
/*    35408:	8fa80084 */ 	lw	$t0,0x84($sp)
/*    3540c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35410:	8d190000 */ 	lw	$t9,0x0($t0)
/*    35414:	932a000c */ 	lbu	$t2,0xc($t9)
/*    35418:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    3541c:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35420:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35424:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    35428:	8daf0000 */ 	lw	$t7,0x0($t5)
/*    3542c:	8d8b001c */ 	lw	$t3,0x1c($t4)
/*    35430:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35434:	016ec021 */ 	addu	$t8,$t3,$t6
/*    35438:	ad180024 */ 	sw	$t8,0x24($t0)
.L0003543c:
/*    3543c:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35440:	a3200037 */ 	sb	$zero,0x37($t9)
/*    35444:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35448:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3544c:	11200005 */ 	beqz	$t1,.L00035464
/*    35450:	00000000 */ 	nop
/*    35454:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35458:	918d0028 */ 	lbu	$t5,0x28($t4)
/*    3545c:	1000000f */ 	b	.L0003549c
/*    35460:	afad0090 */ 	sw	$t5,0x90($sp)
.L00035464:
/*    35464:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    35468:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    3546c:	000ec080 */ 	sll	$t8,$t6,0x2
/*    35470:	030ec023 */ 	subu	$t8,$t8,$t6
/*    35474:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    35478:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3547c:	030ec021 */ 	addu	$t8,$t8,$t6
/*    35480:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35484:	01784021 */ 	addu	$t0,$t3,$t8
/*    35488:	8d190000 */ 	lw	$t9,0x0($t0)
/*    3548c:	afb90068 */ 	sw	$t9,0x68($sp)
/*    35490:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    35494:	91490004 */ 	lbu	$t1,0x4($t2)
/*    35498:	afa90090 */ 	sw	$t1,0x90($sp)
.L0003549c:
/*    3549c:	3c0142fe */ 	lui	$at,0x42fe
/*    354a0:	44812000 */ 	mtc1	$at,$f4
/*    354a4:	00000000 */ 	nop
/*    354a8:	e7a40078 */ 	swc1	$f4,0x78($sp)
/*    354ac:	8fac0090 */ 	lw	$t4,0x90($sp)
/*    354b0:	11800041 */ 	beqz	$t4,.L000355b8
/*    354b4:	00000000 */ 	nop
/*    354b8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    354bc:	8daf0070 */ 	lw	$t7,0x70($t5)
/*    354c0:	11e0003d */ 	beqz	$t7,.L000355b8
/*    354c4:	00000000 */ 	nop
/*    354c8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    354cc:	91cb0024 */ 	lbu	$t3,0x24($t6)
/*    354d0:	11600012 */ 	beqz	$t3,.L0003551c
/*    354d4:	00000000 */ 	nop
/*    354d8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    354dc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    354e0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    354e4:	9308002a */ 	lbu	$t0,0x2a($t8)
/*    354e8:	93060028 */ 	lbu	$a2,0x28($t8)
/*    354ec:	93070029 */ 	lbu	$a3,0x29($t8)
/*    354f0:	afa80010 */ 	sw	$t0,0x10($sp)
/*    354f4:	9319002b */ 	lbu	$t9,0x2b($t8)
/*    354f8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    354fc:	afb90014 */ 	sw	$t9,0x14($sp)
/*    35500:	930a0031 */ 	lbu	$t2,0x31($t8)
/*    35504:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    35508:	8d390070 */ 	lw	$t9,0x70($t1)
/*    3550c:	0320f809 */ 	jalr	$t9
/*    35510:	00000000 */ 	nop
/*    35514:	10000012 */ 	b	.L00035560
/*    35518:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0003551c:
/*    3551c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35520:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35524:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35528:	918d0006 */ 	lbu	$t5,0x6($t4)
/*    3552c:	91860004 */ 	lbu	$a2,0x4($t4)
/*    35530:	91870005 */ 	lbu	$a3,0x5($t4)
/*    35534:	afad0010 */ 	sw	$t5,0x10($sp)
/*    35538:	918f0007 */ 	lbu	$t7,0x7($t4)
/*    3553c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35540:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35544:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    35548:	91cb0031 */ 	lbu	$t3,0x31($t6)
/*    3554c:	afab0018 */ 	sw	$t3,0x18($sp)
/*    35550:	8d190070 */ 	lw	$t9,0x70($t0)
/*    35554:	0320f809 */ 	jalr	$t9
/*    35558:	00000000 */ 	nop
/*    3555c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035560:
/*    35560:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*    35564:	13000014 */ 	beqz	$t8,.L000355b8
/*    35568:	00000000 */ 	nop
/*    3556c:	240a0016 */ 	addiu	$t2,$zero,0x16
/*    35570:	a7aa00a4 */ 	sh	$t2,0xa4($sp)
/*    35574:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35578:	afa900a8 */ 	sw	$t1,0xa8($sp)
/*    3557c:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    35580:	afad00ac */ 	sw	$t5,0xac($sp)
/*    35584:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35588:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3558c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35590:	00003825 */ 	or	$a3,$zero,$zero
/*    35594:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35598:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3559c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    355a0:	918f0037 */ 	lbu	$t7,0x37($t4)
/*    355a4:	35ee0001 */ 	ori	$t6,$t7,0x1
/*    355a8:	a18e0037 */ 	sb	$t6,0x37($t4)
/*    355ac:	8fab006c */ 	lw	$t3,0x6c($sp)
/*    355b0:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    355b4:	ad0b0038 */ 	sw	$t3,0x38($t0)
.L000355b8:
/*    355b8:	4459f800 */ 	cfc1	$t9,$31
/*    355bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355c0:	44d8f800 */ 	ctc1	$t8,$31
/*    355c4:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*    355c8:	46003224 */ 	cvt.w.s	$f8,$f6
/*    355cc:	4458f800 */ 	cfc1	$t8,$31
/*    355d0:	00000000 */ 	nop
/*    355d4:	33010004 */ 	andi	$at,$t8,0x4
/*    355d8:	33180078 */ 	andi	$t8,$t8,0x78
/*    355dc:	13000014 */ 	beqz	$t8,.L00035630
/*    355e0:	00000000 */ 	nop
/*    355e4:	3c014f00 */ 	lui	$at,0x4f00
/*    355e8:	44814000 */ 	mtc1	$at,$f8
/*    355ec:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355f0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*    355f4:	44d8f800 */ 	ctc1	$t8,$31
/*    355f8:	00000000 */ 	nop
/*    355fc:	46004224 */ 	cvt.w.s	$f8,$f8
/*    35600:	4458f800 */ 	cfc1	$t8,$31
/*    35604:	00000000 */ 	nop
/*    35608:	33010004 */ 	andi	$at,$t8,0x4
/*    3560c:	33180078 */ 	andi	$t8,$t8,0x78
/*    35610:	17000005 */ 	bnez	$t8,.L00035628
/*    35614:	00000000 */ 	nop
/*    35618:	44184000 */ 	mfc1	$t8,$f8
/*    3561c:	3c018000 */ 	lui	$at,0x8000
/*    35620:	10000007 */ 	b	.L00035640
/*    35624:	0301c025 */ 	or	$t8,$t8,$at
.L00035628:
/*    35628:	10000005 */ 	b	.L00035640
/*    3562c:	2418ffff */ 	addiu	$t8,$zero,-1
.L00035630:
/*    35630:	44184000 */ 	mfc1	$t8,$f8
/*    35634:	00000000 */ 	nop
/*    35638:	0700fffb */ 	bltz	$t8,.L00035628
/*    3563c:	00000000 */ 	nop
.L00035640:
/*    35640:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35644:	44d9f800 */ 	ctc1	$t9,$31
/*    35648:	a1580036 */ 	sb	$t8,0x36($t2)
/*    3564c:	00000000 */ 	nop
/*    35650:	3c013f80 */ 	lui	$at,0x3f80
/*    35654:	44815000 */ 	mtc1	$at,$f10
/*    35658:	00000000 */ 	nop
/*    3565c:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*    35660:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35664:	912d0024 */ 	lbu	$t5,0x24($t1)
/*    35668:	11a00005 */ 	beqz	$t5,.L00035680
/*    3566c:	00000000 */ 	nop
/*    35670:	8faf0094 */ 	lw	$t7,0x94($sp)
/*    35674:	91ee002c */ 	lbu	$t6,0x2c($t7)
/*    35678:	10000004 */ 	b	.L0003568c
/*    3567c:	afae0090 */ 	sw	$t6,0x90($sp)
.L00035680:
/*    35680:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35684:	918b0008 */ 	lbu	$t3,0x8($t4)
/*    35688:	afab0090 */ 	sw	$t3,0x90($sp)
.L0003568c:
/*    3568c:	8fa80090 */ 	lw	$t0,0x90($sp)
/*    35690:	11000043 */ 	beqz	$t0,.L000357a0
/*    35694:	00000000 */ 	nop
/*    35698:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3569c:	8f380070 */ 	lw	$t8,0x70($t9)
/*    356a0:	1300003f */ 	beqz	$t8,.L000357a0
/*    356a4:	00000000 */ 	nop
/*    356a8:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    356ac:	91490024 */ 	lbu	$t1,0x24($t2)
/*    356b0:	11200012 */ 	beqz	$t1,.L000356fc
/*    356b4:	00000000 */ 	nop
/*    356b8:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    356bc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    356c0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    356c4:	91af002e */ 	lbu	$t7,0x2e($t5)
/*    356c8:	91a6002c */ 	lbu	$a2,0x2c($t5)
/*    356cc:	91a7002d */ 	lbu	$a3,0x2d($t5)
/*    356d0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    356d4:	91ae002f */ 	lbu	$t6,0x2f($t5)
/*    356d8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    356dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*    356e0:	91ac0031 */ 	lbu	$t4,0x31($t5)
/*    356e4:	afac0018 */ 	sw	$t4,0x18($sp)
/*    356e8:	8d790070 */ 	lw	$t9,0x70($t3)
/*    356ec:	0320f809 */ 	jalr	$t9
/*    356f0:	00000000 */ 	nop
/*    356f4:	10000012 */ 	b	.L00035740
/*    356f8:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L000356fc:
/*    356fc:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    35700:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35704:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35708:	9118000a */ 	lbu	$t8,0xa($t0)
/*    3570c:	91060008 */ 	lbu	$a2,0x8($t0)
/*    35710:	91070009 */ 	lbu	$a3,0x9($t0)
/*    35714:	afb80010 */ 	sw	$t8,0x10($sp)
/*    35718:	910a000b */ 	lbu	$t2,0xb($t0)
/*    3571c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35720:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35724:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    35728:	912f0031 */ 	lbu	$t7,0x31($t1)
/*    3572c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    35730:	8dd90070 */ 	lw	$t9,0x70($t6)
/*    35734:	0320f809 */ 	jalr	$t9
/*    35738:	00000000 */ 	nop
/*    3573c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035740:
/*    35740:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    35744:	11a00016 */ 	beqz	$t5,.L000357a0
/*    35748:	00000000 */ 	nop
/*    3574c:	240c0017 */ 	addiu	$t4,$zero,0x17
/*    35750:	a7ac00a4 */ 	sh	$t4,0xa4($sp)
/*    35754:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35758:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*    3575c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*    35760:	afb800ac */ 	sw	$t8,0xac($sp)
/*    35764:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35768:	a3a800b0 */ 	sb	$t0,0xb0($sp)
/*    3576c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35770:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35774:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35778:	00003825 */ 	or	$a3,$zero,$zero
/*    3577c:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35780:	24840048 */ 	addiu	$a0,$a0,0x48
/*    35784:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35788:	91490037 */ 	lbu	$t1,0x37($t2)
/*    3578c:	352f0002 */ 	ori	$t7,$t1,0x2
/*    35790:	a14f0037 */ 	sb	$t7,0x37($t2)
/*    35794:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    35798:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    3579c:	af2e003c */ 	sw	$t6,0x3c($t9)
.L000357a0:
/*    357a0:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*    357a4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    357a8:	e5b0002c */ 	swc1	$f16,0x2c($t5)
/*    357ac:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    357b0:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    357b4:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    357b8:	c5640014 */ 	lwc1	$f4,0x14($t3)
/*    357bc:	c588002c */ 	lwc1	$f8,0x2c($t4)
/*    357c0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    357c4:	00000000 */ 	nop
/*    357c8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    357cc:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*    357d0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    357d4:	0c00f673 */ 	jal	func0003d9cc
/*    357d8:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    357dc:	a3a20077 */ 	sb	$v0,0x77($sp)
/*    357e0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    357e4:	93080011 */ 	lbu	$t0,0x11($t8)
/*    357e8:	a3a80076 */ 	sb	$t0,0x76($sp)
/*    357ec:	93a90076 */ 	lbu	$t1,0x76($sp)
/*    357f0:	11200012 */ 	beqz	$t1,.L0003583c
/*    357f4:	00000000 */ 	nop
/*    357f8:	87af0082 */ 	lh	$t7,0x82($sp)
/*    357fc:	24010064 */ 	addiu	$at,$zero,0x64
/*    35800:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35804:	01e1001a */ 	div	$zero,$t7,$at
/*    35808:	91d90012 */ 	lbu	$t9,0x12($t6)
/*    3580c:	00005012 */ 	mflo	$t2
/*    35810:	01592021 */ 	addu	$a0,$t2,$t9
/*    35814:	0c00ee75 */ 	jal	func0003b9d4
/*    35818:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    3581c:	3c0143dc */ 	lui	$at,0x43dc
/*    35820:	44818000 */ 	mtc1	$at,$f16
/*    35824:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    35828:	46100482 */ 	mul.s	$f18,$f0,$f16
/*    3582c:	c5a40014 */ 	lwc1	$f4,0x14($t5)
/*    35830:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    35834:	10000005 */ 	b	.L0003584c
/*    35838:	e7a60070 */ 	swc1	$f6,0x70($sp)
.L0003583c:
/*    3583c:	3c0142fe */ 	lui	$at,0x42fe
/*    35840:	44814000 */ 	mtc1	$at,$f8
/*    35844:	00000000 */ 	nop
/*    35848:	e7a80070 */ 	swc1	$f8,0x70($sp)
.L0003584c:
/*    3584c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35850:	0c00f6c5 */ 	jal	__vsPan
/*    35854:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35858:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    3585c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35860:	0c00f629 */ 	jal	__n_vsVol
/*    35864:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35868:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    3586c:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35870:	916c0024 */ 	lbu	$t4,0x24($t3)
/*    35874:	11800005 */ 	beqz	$t4,.L0003588c
/*    35878:	00000000 */ 	nop
/*    3587c:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35880:	8f080018 */ 	lw	$t0,0x18($t8)
/*    35884:	10000005 */ 	b	.L0003589c
/*    35888:	afa800a0 */ 	sw	$t0,0xa0($sp)
.L0003588c:
/*    3588c:	8fa90084 */ 	lw	$t1,0x84($sp)
/*    35890:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*    35894:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35898:	afae00a0 */ 	sw	$t6,0xa0($sp)
.L0003589c:
/*    3589c:	8faa0084 */ 	lw	$t2,0x84($sp)
/*    358a0:	93b9009b */ 	lbu	$t9,0x9b($sp)
/*    358a4:	93ad0077 */ 	lbu	$t5,0x77($sp)
/*    358a8:	8d450008 */ 	lw	$a1,0x8($t2)
/*    358ac:	93ab0076 */ 	lbu	$t3,0x76($sp)
/*    358b0:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*    358b4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    358b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*    358bc:	afad0014 */ 	sw	$t5,0x14($sp)
/*    358c0:	afab0018 */ 	sw	$t3,0x18($sp)
/*    358c4:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    358c8:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*    358cc:	91980013 */ 	lbu	$t8,0x13($t4)
/*    358d0:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    358d4:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*    358d8:	87a700b6 */ 	lh	$a3,0xb6($sp)
/*    358dc:	afa80024 */ 	sw	$t0,0x24($sp)
/*    358e0:	0c00f370 */ 	jal	func0003cdc0
/*    358e4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    358e8:	24090006 */ 	addiu	$t1,$zero,0x6
/*    358ec:	a7a900a4 */ 	sh	$t1,0xa4($sp)
/*    358f0:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    358f4:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*    358f8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    358fc:	91ca0024 */ 	lbu	$t2,0x24($t6)
/*    35900:	11400008 */ 	beqz	$t2,.L00035924
/*    35904:	00000000 */ 	nop
/*    35908:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    3590c:	932d0026 */ 	lbu	$t5,0x26($t9)
/*    35910:	a3ad00b0 */ 	sb	$t5,0xb0($sp)
/*    35914:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35918:	8d6c001c */ 	lw	$t4,0x1c($t3)
/*    3591c:	10000009 */ 	b	.L00035944
/*    35920:	afac00ac */ 	sw	$t4,0xac($sp)
.L00035924:
/*    35924:	8fb80084 */ 	lw	$t8,0x84($sp)
/*    35928:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3592c:	9109000d */ 	lbu	$t1,0xd($t0)
/*    35930:	a3a900b0 */ 	sb	$t1,0xb0($sp)
/*    35934:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    35938:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    3593c:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    35940:	afaa00ac */ 	sw	$t2,0xac($sp)
.L00035944:
/*    35944:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35948:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3594c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35950:	00003825 */ 	or	$a3,$zero,$zero
/*    35954:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35958:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3595c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    35960:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*    35964:	11a0001d */ 	beqz	$t5,.L000359dc
/*    35968:	00000000 */ 	nop
/*    3596c:	240b0015 */ 	addiu	$t3,$zero,0x15
/*    35970:	a7ab00a4 */ 	sh	$t3,0xa4($sp)
/*    35974:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35978:	35980080 */ 	ori	$t8,$t4,0x80
/*    3597c:	a3b800ac */ 	sb	$t8,0xac($sp)
/*    35980:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    35984:	a3a800ad */ 	sb	$t0,0xad($sp)
/*    35988:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    3598c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35990:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    35994:	8d2f0024 */ 	lw	$t7,0x24($t1)
/*    35998:	8dca0008 */ 	lw	$t2,0x8($t6)
/*    3599c:	01ea0019 */ 	multu	$t7,$t2
/*    359a0:	0000c812 */ 	mflo	$t9
/*    359a4:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*    359a8:	00000000 */ 	nop
/*    359ac:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    359b0:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    359b4:	3c01800a */ 	lui	$at,%hi(var8009c350)
/*    359b8:	000b6080 */ 	sll	$t4,$t3,0x2
/*    359bc:	002c0821 */ 	addu	$at,$at,$t4
/*    359c0:	ac2dc350 */ 	sw	$t5,%lo(var8009c350)($at)
/*    359c4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    359c8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    359cc:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    359d0:	00003825 */ 	or	$a3,$zero,$zero
/*    359d4:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    359d8:	24840048 */ 	addiu	$a0,$a0,0x48
.L000359dc:
/*    359dc:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    359e0:	93080010 */ 	lbu	$t0,0x10($t8)
/*    359e4:	31090001 */ 	andi	$t1,$t0,0x1
/*    359e8:	11200014 */ 	beqz	$t1,.L00035a3c
/*    359ec:	00000000 */ 	nop
/*    359f0:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    359f4:	8dcf0084 */ 	lw	$t7,0x84($t6)
/*    359f8:	11e00010 */ 	beqz	$t7,.L00035a3c
/*    359fc:	00000000 */ 	nop
/*    35a00:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a04:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35a08:	3c0d800a */ 	lui	$t5,%hi(var8009c350)
/*    35a0c:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a10:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    35a14:	8dadc350 */ 	lw	$t5,%lo(var8009c350)($t5)
/*    35a18:	93080010 */ 	lbu	$t0,0x10($t8)
/*    35a1c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35a20:	2401ff00 */ 	addiu	$at,$zero,-256
/*    35a24:	01a16024 */ 	and	$t4,$t5,$at
/*    35a28:	00084883 */ 	sra	$t1,$t0,0x2
/*    35a2c:	01892825 */ 	or	$a1,$t4,$t1
/*    35a30:	00003025 */ 	or	$a2,$zero,$zero
/*    35a34:	0c012238 */ 	jal	osSendMesg
/*    35a38:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035a3c:
/*    35a3c:	100005f0 */ 	b	.L00037200
/*    35a40:	00000000 */ 	nop
.L00035a44:
/*    35a44:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35a48:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35a4c:	0c00f5a7 */ 	jal	__n_lookupVoice
/*    35a50:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35a54:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35a58:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35a5c:	15c00003 */ 	bnez	$t6,.L00035a6c
/*    35a60:	00000000 */ 	nop
/*    35a64:	100005e8 */ 	b	.L00037208
/*    35a68:	00000000 */ 	nop
.L00035a6c:
/*    35a6c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a70:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35a74:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a78:	01795823 */ 	subu	$t3,$t3,$t9
/*    35a7c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    35a80:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a84:	01795821 */ 	addu	$t3,$t3,$t9
/*    35a88:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a8c:	014b6821 */ 	addu	$t5,$t2,$t3
/*    35a90:	afad0094 */ 	sw	$t5,0x94($sp)
/*    35a94:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    35a98:	24010002 */ 	addiu	$at,$zero,0x2
/*    35a9c:	93080035 */ 	lbu	$t0,0x35($t8)
/*    35aa0:	15010005 */ 	bne	$t0,$at,.L00035ab8
/*    35aa4:	00000000 */ 	nop
/*    35aa8:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35aac:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    35ab0:	10000017 */ 	b	.L00035b10
/*    35ab4:	a12c0035 */ 	sb	$t4,0x35($t1)
.L00035ab8:
/*    35ab8:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35abc:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    35ac0:	a1ee0035 */ 	sb	$t6,0x35($t7)
/*    35ac4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    35ac8:	932a0024 */ 	lbu	$t2,0x24($t9)
/*    35acc:	11400009 */ 	beqz	$t2,.L00035af4
/*    35ad0:	00000000 */ 	nop
/*    35ad4:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*    35ad8:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35adc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35ae0:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    35ae4:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    35ae8:	8d660020 */ 	lw	$a2,0x20($t3)
/*    35aec:	10000008 */ 	b	.L00035b10
/*    35af0:	00000000 */ 	nop
.L00035af4:
/*    35af4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    35af8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35afc:	8db80020 */ 	lw	$t8,0x20($t5)
/*    35b00:	25a50004 */ 	addiu	$a1,$t5,0x4
/*    35b04:	8f080000 */ 	lw	$t0,0x0($t8)
/*    35b08:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    35b0c:	8d060008 */ 	lw	$a2,0x8($t0)
.L00035b10:
/*    35b10:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35b14:	91890010 */ 	lbu	$t1,0x10($t4)
/*    35b18:	312e0002 */ 	andi	$t6,$t1,0x2
/*    35b1c:	11c00010 */ 	beqz	$t6,.L00035b60
/*    35b20:	00000000 */ 	nop
/*    35b24:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35b28:	8df90084 */ 	lw	$t9,0x84($t7)
/*    35b2c:	1320000c */ 	beqz	$t9,.L00035b60
/*    35b30:	00000000 */ 	nop
/*    35b34:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    35b38:	93ab00c2 */ 	lbu	$t3,0xc2($sp)
/*    35b3c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35b40:	910c0010 */ 	lbu	$t4,0x10($t0)
/*    35b44:	000b6c00 */ 	sll	$t5,$t3,0x10
/*    35b48:	35b80008 */ 	ori	$t8,$t5,0x8
/*    35b4c:	000c4883 */ 	sra	$t1,$t4,0x2
/*    35b50:	03092825 */ 	or	$a1,$t8,$t1
/*    35b54:	00003025 */ 	or	$a2,$zero,$zero
/*    35b58:	0c012238 */ 	jal	osSendMesg
/*    35b5c:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035b60:
/*    35b60:	100005a7 */ 	b	.L00037200
/*    35b64:	00000000 */ 	nop
/*    35b68:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35b6c:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35b70:	0c00f5a7 */ 	jal	__n_lookupVoice
/*    35b74:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35b78:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35b7c:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35b80:	15c00003 */ 	bnez	$t6,.L00035b90
/*    35b84:	00000000 */ 	nop
/*    35b88:	1000059f */ 	b	.L00037208
/*    35b8c:	00000000 */ 	nop
.L00035b90:
/*    35b90:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    35b94:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35b98:	a32f0033 */ 	sb	$t7,0x33($t9)
/*    35b9c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35ba0:	0c00f629 */ 	jal	__n_vsVol
/*    35ba4:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35ba8:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35bac:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35bb0:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35bb4:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bb8:	0c00f6b4 */ 	jal	__n_vsDelta
/*    35bbc:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    35bc0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bc4:	00408025 */ 	or	$s0,$v0,$zero
/*    35bc8:	02003025 */ 	or	$a2,$s0,$zero
/*    35bcc:	02202825 */ 	or	$a1,$s1,$zero
/*    35bd0:	0c00f33c */ 	jal	n_alSynSetVol
/*    35bd4:	24840004 */ 	addiu	$a0,$a0,0x4
/*    35bd8:	10000589 */ 	b	.L00037200
/*    35bdc:	00000000 */ 	nop
/*    35be0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35be4:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    35be8:	11a0001c */ 	beqz	$t5,.L00035c5c
/*    35bec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00035bf0:
/*    35bf0:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    35bf4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35bf8:	910c0031 */ 	lbu	$t4,0x31($t0)
/*    35bfc:	15980013 */ 	bne	$t4,$t8,.L00035c4c
/*    35c00:	00000000 */ 	nop
/*    35c04:	93a900c0 */ 	lbu	$t1,0xc0($sp)
/*    35c08:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    35c0c:	a1c90033 */ 	sb	$t1,0x33($t6)
/*    35c10:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c14:	0c00f629 */ 	jal	__n_vsVol
/*    35c18:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35c1c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35c20:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35c24:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35c28:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c2c:	0c00f6b4 */ 	jal	__n_vsDelta
/*    35c30:	8de5001c */ 	lw	$a1,0x1c($t7)
/*    35c34:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c38:	00408025 */ 	or	$s0,$v0,$zero
/*    35c3c:	02003025 */ 	or	$a2,$s0,$zero
/*    35c40:	02202825 */ 	or	$a1,$s1,$zero
/*    35c44:	0c00f33c */ 	jal	n_alSynSetVol
/*    35c48:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035c4c:
/*    35c4c:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    35c50:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*    35c54:	1540ffe6 */ 	bnez	$t2,.L00035bf0
/*    35c58:	afaa00c8 */ 	sw	$t2,0xc8($sp)
.L00035c5c:
/*    35c5c:	10000568 */ 	b	.L00037200
/*    35c60:	00000000 */ 	nop
/*    35c64:	93b000c0 */ 	lbu	$s0,0xc0($sp)
/*    35c68:	2a01005d */ 	slti	$at,$s0,0x5d
/*    35c6c:	1420000f */ 	bnez	$at,.L00035cac
/*    35c70:	00000000 */ 	nop
/*    35c74:	240100fc */ 	addiu	$at,$zero,0xfc
/*    35c78:	1201012d */ 	beq	$s0,$at,.L00036130
/*    35c7c:	00000000 */ 	nop
/*    35c80:	240100fd */ 	addiu	$at,$zero,0xfd
/*    35c84:	12010050 */ 	beq	$s0,$at,.L00035dc8
/*    35c88:	00000000 */ 	nop
/*    35c8c:	240100fe */ 	addiu	$at,$zero,0xfe
/*    35c90:	120100ab */ 	beq	$s0,$at,.L00035f40
/*    35c94:	00000000 */ 	nop
/*    35c98:	240100ff */ 	addiu	$at,$zero,0xff
/*    35c9c:	12010057 */ 	beq	$s0,$at,.L00035dfc
/*    35ca0:	00000000 */ 	nop
/*    35ca4:	100004bf */ 	b	.L00036fa4
/*    35ca8:	00000000 */ 	nop
.L00035cac:
/*    35cac:	2a010042 */ 	slti	$at,$s0,0x42
/*    35cb0:	14200009 */ 	bnez	$at,.L00035cd8
/*    35cb4:	00000000 */ 	nop
/*    35cb8:	2401005b */ 	addiu	$at,$zero,0x5b
/*    35cbc:	12010244 */ 	beq	$s0,$at,.L000365d0
/*    35cc0:	00000000 */ 	nop
/*    35cc4:	2401005c */ 	addiu	$at,$zero,0x5c
/*    35cc8:	12010286 */ 	beq	$s0,$at,.L000366e4
/*    35ccc:	00000000 */ 	nop
/*    35cd0:	100004b4 */ 	b	.L00036fa4
/*    35cd4:	00000000 */ 	nop
.L00035cd8:
/*    35cd8:	2a010041 */ 	slti	$at,$s0,0x41
/*    35cdc:	14200006 */ 	bnez	$at,.L00035cf8
/*    35ce0:	00000000 */ 	nop
/*    35ce4:	24010041 */ 	addiu	$at,$zero,0x41
/*    35ce8:	12010253 */ 	beq	$s0,$at,.L00036638
/*    35cec:	00000000 */ 	nop
/*    35cf0:	100004ac */ 	b	.L00036fa4
/*    35cf4:	00000000 */ 	nop
.L00035cf8:
/*    35cf8:	2a010024 */ 	slti	$at,$s0,0x24
/*    35cfc:	14200006 */ 	bnez	$at,.L00035d18
/*    35d00:	00000000 */ 	nop
/*    35d04:	24010040 */ 	addiu	$at,$zero,0x40
/*    35d08:	120101c0 */ 	beq	$s0,$at,.L0003640c
/*    35d0c:	00000000 */ 	nop
/*    35d10:	100004a4 */ 	b	.L00036fa4
/*    35d14:	00000000 */ 	nop
.L00035d18:
/*    35d18:	260bffff */ 	addiu	$t3,$s0,-1
/*    35d1c:	2d610023 */ 	sltiu	$at,$t3,0x23
/*    35d20:	102004a0 */ 	beqz	$at,.L00036fa4
/*    35d24:	00000000 */ 	nop
/*    35d28:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35d2c:	3c017005 */ 	lui	$at,%hi(var700549bc)
/*    35d30:	002b0821 */ 	addu	$at,$at,$t3
/*    35d34:	8c2b49bc */ 	lw	$t3,%lo(var700549bc)($at)
/*    35d38:	01600008 */ 	jr	$t3
/*    35d3c:	00000000 */ 	nop
/*    35d40:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35d44:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35d48:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    35d4c:	00184880 */ 	sll	$t1,$t8,0x2
/*    35d50:	01384823 */ 	subu	$t1,$t1,$t8
/*    35d54:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35d58:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d5c:	01384821 */ 	addu	$t1,$t1,$t8
/*    35d60:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d64:	01897021 */ 	addu	$t6,$t4,$t1
/*    35d68:	a1cd0007 */ 	sb	$t5,0x7($t6)
/*    35d6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35d70:	8df90064 */ 	lw	$t9,0x64($t7)
/*    35d74:	13200012 */ 	beqz	$t9,.L00035dc0
/*    35d78:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L00035d7c:
/*    35d7c:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    35d80:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35d84:	914b0031 */ 	lbu	$t3,0x31($t2)
/*    35d88:	15680009 */ 	bne	$t3,$t0,.L00035db0
/*    35d8c:	00000000 */ 	nop
/*    35d90:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35d94:	0c00f6c5 */ 	jal	__vsPan
/*    35d98:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35d9c:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    35da0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35da4:	93a5009b */ 	lbu	$a1,0x9b($sp)
/*    35da8:	0c00f3bc */ 	jal	func0003cef0
/*    35dac:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035db0:
/*    35db0:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    35db4:	8f0c0000 */ 	lw	$t4,0x0($t8)
/*    35db8:	1580fff0 */ 	bnez	$t4,.L00035d7c
/*    35dbc:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00035dc0:
/*    35dc0:	1000047a */ 	b	.L00036fac
/*    35dc4:	00000000 */ 	nop
.L00035dc8:
/*    35dc8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35dcc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35dd0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35dd4:	000fc880 */ 	sll	$t9,$t7,0x2
/*    35dd8:	032fc823 */ 	subu	$t9,$t9,$t7
/*    35ddc:	8dae0060 */ 	lw	$t6,0x60($t5)
/*    35de0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35de4:	032fc821 */ 	addu	$t9,$t9,$t7
/*    35de8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35dec:	01d95021 */ 	addu	$t2,$t6,$t9
/*    35df0:	a149000f */ 	sb	$t1,0xf($t2)
/*    35df4:	1000046d */ 	b	.L00036fac
/*    35df8:	00000000 */ 	nop
.L00035dfc:
/*    35dfc:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e00:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e04:	00186080 */ 	sll	$t4,$t8,0x2
/*    35e08:	01986023 */ 	subu	$t4,$t4,$t8
/*    35e0c:	8d680060 */ 	lw	$t0,0x60($t3)
/*    35e10:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e14:	01986021 */ 	addu	$t4,$t4,$t8
/*    35e18:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e1c:	010c6821 */ 	addu	$t5,$t0,$t4
/*    35e20:	91af000f */ 	lbu	$t7,0xf($t5)
/*    35e24:	15e0000c */ 	bnez	$t7,.L00035e58
/*    35e28:	00000000 */ 	nop
/*    35e2c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35e30:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35e34:	240e0090 */ 	addiu	$t6,$zero,0x90
/*    35e38:	000a5880 */ 	sll	$t3,$t2,0x2
/*    35e3c:	016a5823 */ 	subu	$t3,$t3,$t2
/*    35e40:	8f290060 */ 	lw	$t1,0x60($t9)
/*    35e44:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e48:	016a5821 */ 	addu	$t3,$t3,$t2
/*    35e4c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e50:	012bc021 */ 	addu	$t8,$t1,$t3
/*    35e54:	a30e000f */ 	sb	$t6,0xf($t8)
.L00035e58:
/*    35e58:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35e5c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35e60:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35e64:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35e68:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35e6c:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35e70:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e74:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35e78:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e7c:	018fc821 */ 	addu	$t9,$t4,$t7
/*    35e80:	932a000e */ 	lbu	$t2,0xe($t9)
/*    35e84:	11490029 */ 	beq	$t2,$t1,.L00035f2c
/*    35e88:	00000000 */ 	nop
/*    35e8c:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e90:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e94:	00184080 */ 	sll	$t0,$t8,0x2
/*    35e98:	01184023 */ 	subu	$t0,$t0,$t8
/*    35e9c:	8d6e0060 */ 	lw	$t6,0x60($t3)
/*    35ea0:	00084080 */ 	sll	$t0,$t0,0x2
/*    35ea4:	01184021 */ 	addu	$t0,$t0,$t8
/*    35ea8:	00084080 */ 	sll	$t0,$t0,0x2
/*    35eac:	01c86821 */ 	addu	$t5,$t6,$t0
/*    35eb0:	91ac000d */ 	lbu	$t4,0xd($t5)
/*    35eb4:	91af000e */ 	lbu	$t7,0xe($t5)
/*    35eb8:	158f000d */ 	bne	$t4,$t7,.L00035ef0
/*    35ebc:	00000000 */ 	nop
/*    35ec0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    35ec4:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35ec8:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    35ecc:	000bc080 */ 	sll	$t8,$t3,0x2
/*    35ed0:	030bc023 */ 	subu	$t8,$t8,$t3
/*    35ed4:	8d490060 */ 	lw	$t1,0x60($t2)
/*    35ed8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35edc:	030bc021 */ 	addu	$t8,$t8,$t3
/*    35ee0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35ee4:	01387021 */ 	addu	$t6,$t1,$t8
/*    35ee8:	1000000e */ 	b	.L00035f24
/*    35eec:	a1d9000e */ 	sb	$t9,0xe($t6)
.L00035ef0:
/*    35ef0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35ef4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35ef8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    35efc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    35f00:	014f5023 */ 	subu	$t2,$t2,$t7
/*    35f04:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    35f08:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f0c:	014f5021 */ 	addu	$t2,$t2,$t7
/*    35f10:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f14:	018a5821 */ 	addu	$t3,$t4,$t2
/*    35f18:	a168000e */ 	sb	$t0,0xe($t3)
/*    35f1c:	10000423 */ 	b	.L00036fac
/*    35f20:	00000000 */ 	nop
.L00035f24:
/*    35f24:	10000003 */ 	b	.L00035f34
/*    35f28:	00000000 */ 	nop
.L00035f2c:
/*    35f2c:	1000041f */ 	b	.L00036fac
/*    35f30:	00000000 */ 	nop
.L00035f34:
/*    35f34:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    35f38:	240900fe */ 	addiu	$t1,$zero,0xfe
/*    35f3c:	a3090005 */ 	sb	$t1,0x5($t8)
.L00035f40:
/*    35f40:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35f44:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35f48:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35f4c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35f50:	8f2e0060 */ 	lw	$t6,0x60($t9)
/*    35f54:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f58:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f60:	01cf6021 */ 	addu	$t4,$t6,$t7
/*    35f64:	918a000d */ 	lbu	$t2,0xd($t4)
/*    35f68:	a3aa0067 */ 	sb	$t2,0x67($sp)
/*    35f6c:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    35f70:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35f74:	0009c080 */ 	sll	$t8,$t1,0x2
/*    35f78:	0309c023 */ 	subu	$t8,$t8,$t1
/*    35f7c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    35f80:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f84:	0309c021 */ 	addu	$t8,$t8,$t1
/*    35f88:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f8c:	0178c821 */ 	addu	$t9,$t3,$t8
/*    35f90:	932d000e */ 	lbu	$t5,0xe($t9)
/*    35f94:	a3ad0066 */ 	sb	$t5,0x66($sp)
/*    35f98:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35f9c:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35fa0:	000c5080 */ 	sll	$t2,$t4,0x2
/*    35fa4:	014c5023 */ 	subu	$t2,$t2,$t4
/*    35fa8:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    35fac:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb0:	014c5021 */ 	addu	$t2,$t2,$t4
/*    35fb4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb8:	01ea4021 */ 	addu	$t0,$t7,$t2
/*    35fbc:	9109000f */ 	lbu	$t1,0xf($t0)
/*    35fc0:	a3a900c1 */ 	sb	$t1,0xc1($sp)
/*    35fc4:	93ab0066 */ 	lbu	$t3,0x66($sp)
/*    35fc8:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    35fcc:	0178c823 */ 	subu	$t9,$t3,$t8
/*    35fd0:	afb90060 */ 	sw	$t9,0x60($sp)
/*    35fd4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    35fd8:	19a00012 */ 	blez	$t5,.L00036024
/*    35fdc:	00000000 */ 	nop
/*    35fe0:	93ae00c1 */ 	lbu	$t6,0xc1($sp)
/*    35fe4:	31cc0080 */ 	andi	$t4,$t6,0x80
/*    35fe8:	11800005 */ 	beqz	$t4,.L00036000
/*    35fec:	00000000 */ 	nop
/*    35ff0:	93af00c1 */ 	lbu	$t7,0xc1($sp)
/*    35ff4:	31ea007f */ 	andi	$t2,$t7,0x7f
/*    35ff8:	000a4040 */ 	sll	$t0,$t2,0x1
/*    35ffc:	a3a800c1 */ 	sb	$t0,0xc1($sp)
.L00036000:
/*    36000:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    36004:	93ab00c1 */ 	lbu	$t3,0xc1($sp)
/*    36008:	0169082a */ 	slt	$at,$t3,$t1
/*    3600c:	10200003 */ 	beqz	$at,.L0003601c
/*    36010:	00000000 */ 	nop
/*    36014:	93b800c1 */ 	lbu	$t8,0xc1($sp)
/*    36018:	afb80060 */ 	sw	$t8,0x60($sp)
.L0003601c:
/*    3601c:	1000000d */ 	b	.L00036054
/*    36020:	00000000 */ 	nop
.L00036024:
/*    36024:	93b900c1 */ 	lbu	$t9,0xc1($sp)
/*    36028:	332d007f */ 	andi	$t5,$t9,0x7f
/*    3602c:	a3ad00c1 */ 	sb	$t5,0xc1($sp)
/*    36030:	93ac00c1 */ 	lbu	$t4,0xc1($sp)
/*    36034:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    36038:	000c7823 */ 	negu	$t7,$t4
/*    3603c:	01cf082a */ 	slt	$at,$t6,$t7
/*    36040:	10200004 */ 	beqz	$at,.L00036054
/*    36044:	00000000 */ 	nop
/*    36048:	93aa00c1 */ 	lbu	$t2,0xc1($sp)
/*    3604c:	000a4023 */ 	negu	$t0,$t2
/*    36050:	afa80060 */ 	sw	$t0,0x60($sp)
.L00036054:
/*    36054:	93a90067 */ 	lbu	$t1,0x67($sp)
/*    36058:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3605c:	012bc021 */ 	addu	$t8,$t1,$t3
/*    36060:	a3b80067 */ 	sb	$t8,0x67($sp)
/*    36064:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36068:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3606c:	93b90067 */ 	lbu	$t9,0x67($sp)
/*    36070:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36074:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36078:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3607c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36080:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36084:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36088:	018f5021 */ 	addu	$t2,$t4,$t7
/*    3608c:	a159000d */ 	sb	$t9,0xd($t2)
/*    36090:	93a80067 */ 	lbu	$t0,0x67($sp)
/*    36094:	93a90066 */ 	lbu	$t1,0x66($sp)
/*    36098:	1109000d */ 	beq	$t0,$t1,.L000360d0
/*    3609c:	00000000 */ 	nop
/*    360a0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    360a4:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*    360a8:	00003825 */ 	or	$a3,$zero,$zero
/*    360ac:	8d660024 */ 	lw	$a2,0x24($t3)
/*    360b0:	25640048 */ 	addiu	$a0,$t3,0x48
/*    360b4:	00c00821 */ 	addu	$at,$a2,$zero
/*    360b8:	00013080 */ 	sll	$a2,$at,0x2
/*    360bc:	00c13023 */ 	subu	$a2,$a2,$at
/*    360c0:	000630c0 */ 	sll	$a2,$a2,0x3
/*    360c4:	00c13021 */ 	addu	$a2,$a2,$at
/*    360c8:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    360cc:	00063080 */ 	sll	$a2,$a2,0x2
.L000360d0:
/*    360d0:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    360d4:	13000009 */ 	beqz	$t8,.L000360fc
/*    360d8:	00000000 */ 	nop
/*    360dc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    360e0:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    360e4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    360e8:	95ae0030 */ 	lhu	$t6,0x30($t5)
/*    360ec:	018fc804 */ 	sllv	$t9,$t7,$t4
/*    360f0:	01d95025 */ 	or	$t2,$t6,$t9
/*    360f4:	10000009 */ 	b	.L0003611c
/*    360f8:	a5aa0030 */ 	sh	$t2,0x30($t5)
.L000360fc:
/*    360fc:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36100:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36104:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36108:	95090030 */ 	lhu	$t1,0x30($t0)
/*    3610c:	01787804 */ 	sllv	$t7,$t8,$t3
/*    36110:	01e06027 */ 	nor	$t4,$t7,$zero
/*    36114:	012c7024 */ 	and	$t6,$t1,$t4
/*    36118:	a50e0030 */ 	sh	$t6,0x30($t0)
.L0003611c:
/*    3611c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36120:	0c00d3c3 */ 	jal	func00034f0c
/*    36124:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36128:	100003a0 */ 	b	.L00036fac
/*    3612c:	00000000 */ 	nop
.L00036130:
/*    36130:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36134:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36138:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    3613c:	00185880 */ 	sll	$t3,$t8,0x2
/*    36140:	01785823 */ 	subu	$t3,$t3,$t8
/*    36144:	8d4d0060 */ 	lw	$t5,0x60($t2)
/*    36148:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3614c:	01785821 */ 	addu	$t3,$t3,$t8
/*    36150:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36154:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    36158:	a1f9000d */ 	sb	$t9,0xd($t7)
/*    3615c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36160:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36164:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36168:	00085080 */ 	sll	$t2,$t0,0x2
/*    3616c:	01485023 */ 	subu	$t2,$t2,$t0
/*    36170:	8d8e0060 */ 	lw	$t6,0x60($t4)
/*    36174:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36178:	01485021 */ 	addu	$t2,$t2,$t0
/*    3617c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36180:	01cac021 */ 	addu	$t8,$t6,$t2
/*    36184:	a309000e */ 	sb	$t1,0xe($t8)
/*    36188:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    3618c:	15a0000a */ 	bnez	$t5,.L000361b8
/*    36190:	00000000 */ 	nop
/*    36194:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36198:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3619c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361a0:	95790030 */ 	lhu	$t9,0x30($t3)
/*    361a4:	01ec4004 */ 	sllv	$t0,$t4,$t7
/*    361a8:	390effff */ 	xori	$t6,$t0,0xffff
/*    361ac:	032e5024 */ 	and	$t2,$t9,$t6
/*    361b0:	10000008 */ 	b	.L000361d4
/*    361b4:	a56a0030 */ 	sh	$t2,0x30($t3)
.L000361b8:
/*    361b8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    361bc:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    361c0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361c4:	95380030 */ 	lhu	$t8,0x30($t1)
/*    361c8:	01ac7804 */ 	sllv	$t7,$t4,$t5
/*    361cc:	030f4025 */ 	or	$t0,$t8,$t7
/*    361d0:	a5280030 */ 	sh	$t0,0x30($t1)
.L000361d4:
/*    361d4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    361d8:	0c00d3c3 */ 	jal	func00034f0c
/*    361dc:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    361e0:	10000372 */ 	b	.L00036fac
/*    361e4:	00000000 */ 	nop
/*    361e8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    361ec:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    361f0:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    361f4:	000b6080 */ 	sll	$t4,$t3,0x2
/*    361f8:	018b6023 */ 	subu	$t4,$t4,$t3
/*    361fc:	8dca0060 */ 	lw	$t2,0x60($t6)
/*    36200:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36204:	018b6021 */ 	addu	$t4,$t4,$t3
/*    36208:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3620c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    36210:	a1b90011 */ 	sb	$t9,0x11($t5)
/*    36214:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36218:	0c00d3ee */ 	jal	func00034fb8
/*    3621c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36220:	10000362 */ 	b	.L00036fac
/*    36224:	00000000 */ 	nop
/*    36228:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3622c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36230:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36234:	00097080 */ 	sll	$t6,$t1,0x2
/*    36238:	01c97023 */ 	subu	$t6,$t6,$t1
/*    3623c:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36240:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36244:	01c97021 */ 	addu	$t6,$t6,$t1
/*    36248:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3624c:	010e5821 */ 	addu	$t3,$t0,$t6
/*    36250:	a1780012 */ 	sb	$t8,0x12($t3)
/*    36254:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36258:	0c00d3ee */ 	jal	func00034fb8
/*    3625c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36260:	10000352 */ 	b	.L00036fac
/*    36264:	00000000 */ 	nop
/*    36268:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    3626c:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36270:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36274:	000d7880 */ 	sll	$t7,$t5,0x2
/*    36278:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    3627c:	8d990060 */ 	lw	$t9,0x60($t4)
/*    36280:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36284:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    36288:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3628c:	032f4821 */ 	addu	$t1,$t9,$t7
/*    36290:	a12a0013 */ 	sb	$t2,0x13($t1)
/*    36294:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36298:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*    3629c:	11c0000e */ 	beqz	$t6,.L000362d8
/*    362a0:	afae00c8 */ 	sw	$t6,0xc8($sp)
.L000362a4:
/*    362a4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    362a8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    362ac:	930b0031 */ 	lbu	$t3,0x31($t8)
/*    362b0:	156c0005 */ 	bne	$t3,$t4,.L000362c8
/*    362b4:	00000000 */ 	nop
/*    362b8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    362bc:	93a500bf */ 	lbu	$a1,0xbf($sp)
/*    362c0:	0c00f9cc */ 	jal	func0003e730
/*    362c4:	24840004 */ 	addiu	$a0,$a0,0x4
.L000362c8:
/*    362c8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*    362cc:	8db90000 */ 	lw	$t9,0x0($t5)
/*    362d0:	1720fff4 */ 	bnez	$t9,.L000362a4
/*    362d4:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000362d8:
/*    362d8:	10000334 */ 	b	.L00036fac
/*    362dc:	00000000 */ 	nop
/*    362e0:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    362e4:	8dea0084 */ 	lw	$t2,0x84($t7)
/*    362e8:	1140000d */ 	beqz	$t2,.L00036320
/*    362ec:	00000000 */ 	nop
/*    362f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    362f4:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    362f8:	2401ff00 */ 	addiu	$at,$zero,-256
/*    362fc:	8d2b0010 */ 	lw	$t3,0x10($t1)
/*    36300:	310e0007 */ 	andi	$t6,$t0,0x7
/*    36304:	35d80010 */ 	ori	$t8,$t6,0x10
/*    36308:	000b6140 */ 	sll	$t4,$t3,0x5
/*    3630c:	01816824 */ 	and	$t5,$t4,$at
/*    36310:	030d2825 */ 	or	$a1,$t8,$t5
/*    36314:	00003025 */ 	or	$a2,$zero,$zero
/*    36318:	0c012238 */ 	jal	osSendMesg
/*    3631c:	8d240084 */ 	lw	$a0,0x84($t1)
.L00036320:
/*    36320:	10000322 */ 	b	.L00036fac
/*    36324:	00000000 */ 	nop
/*    36328:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    3632c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36330:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36334:	00087080 */ 	sll	$t6,$t0,0x2
/*    36338:	01c87023 */ 	subu	$t6,$t6,$t0
/*    3633c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    36340:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36344:	01c87021 */ 	addu	$t6,$t6,$t0
/*    36348:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3634c:	014e4821 */ 	addu	$t1,$t2,$t6
/*    36350:	a1390009 */ 	sb	$t9,0x9($t1)
/*    36354:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36358:	8d6c0064 */ 	lw	$t4,0x64($t3)
/*    3635c:	1180001c */ 	beqz	$t4,.L000363d0
/*    36360:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036364:
/*    36364:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36368:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3636c:	930d0031 */ 	lbu	$t5,0x31($t8)
/*    36370:	15af0013 */ 	bne	$t5,$t7,.L000363c0
/*    36374:	00000000 */ 	nop
/*    36378:	93080034 */ 	lbu	$t0,0x34($t8)
/*    3637c:	24010003 */ 	addiu	$at,$zero,0x3
/*    36380:	1101000f */ 	beq	$t0,$at,.L000363c0
/*    36384:	00000000 */ 	nop
/*    36388:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    3638c:	0c00f629 */ 	jal	__n_vsVol
/*    36390:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    36394:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    36398:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    3639c:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363a0:	0c00f6b4 */ 	jal	__n_vsDelta
/*    363a4:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    363a8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363ac:	00408025 */ 	or	$s0,$v0,$zero
/*    363b0:	02003025 */ 	or	$a2,$s0,$zero
/*    363b4:	87a500b6 */ 	lh	$a1,0xb6($sp)
/*    363b8:	0c00f33c */ 	jal	n_alSynSetVol
/*    363bc:	24840004 */ 	addiu	$a0,$a0,0x4
.L000363c0:
/*    363c0:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    363c4:	8dd90000 */ 	lw	$t9,0x0($t6)
/*    363c8:	1720ffe6 */ 	bnez	$t9,.L00036364
/*    363cc:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000363d0:
/*    363d0:	100002f6 */ 	b	.L00036fac
/*    363d4:	00000000 */ 	nop
/*    363d8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    363dc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    363e0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    363e4:	000d7880 */ 	sll	$t7,$t5,0x2
/*    363e8:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    363ec:	8d6c0060 */ 	lw	$t4,0x60($t3)
/*    363f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363f4:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    363f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363fc:	018fc021 */ 	addu	$t8,$t4,$t7
/*    36400:	a3090008 */ 	sb	$t1,0x8($t8)
/*    36404:	100002e9 */ 	b	.L00036fac
/*    36408:	00000000 */ 	nop
.L0003640c:
/*    3640c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36410:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36414:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    36418:	00195880 */ 	sll	$t3,$t9,0x2
/*    3641c:	01795823 */ 	subu	$t3,$t3,$t9
/*    36420:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36424:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36428:	01795821 */ 	addu	$t3,$t3,$t9
/*    3642c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36430:	01cb6821 */ 	addu	$t5,$t6,$t3
/*    36434:	a1a8000c */ 	sb	$t0,0xc($t5)
/*    36438:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3643c:	8d8f0064 */ 	lw	$t7,0x64($t4)
/*    36440:	11e00061 */ 	beqz	$t7,.L000365c8
/*    36444:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L00036448:
/*    36448:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    3644c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36450:	91380031 */ 	lbu	$t8,0x31($t1)
/*    36454:	170a0058 */ 	bne	$t8,$t2,.L000365b8
/*    36458:	00000000 */ 	nop
/*    3645c:	91390035 */ 	lbu	$t9,0x35($t1)
/*    36460:	24010003 */ 	addiu	$at,$zero,0x3
/*    36464:	13210054 */ 	beq	$t9,$at,.L000365b8
/*    36468:	00000000 */ 	nop
/*    3646c:	93ae00bf */ 	lbu	$t6,0xbf($sp)
/*    36470:	29c10040 */ 	slti	$at,$t6,0x40
/*    36474:	1420000a */ 	bnez	$at,.L000364a0
/*    36478:	00000000 */ 	nop
/*    3647c:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36480:	91680035 */ 	lbu	$t0,0x35($t3)
/*    36484:	15000004 */ 	bnez	$t0,.L00036498
/*    36488:	00000000 */ 	nop
/*    3648c:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    36490:	240d0002 */ 	addiu	$t5,$zero,0x2
/*    36494:	a18d0035 */ 	sb	$t5,0x35($t4)
.L00036498:
/*    36498:	10000047 */ 	b	.L000365b8
/*    3649c:	00000000 */ 	nop
.L000364a0:
/*    364a0:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    364a4:	24010002 */ 	addiu	$at,$zero,0x2
/*    364a8:	91f80035 */ 	lbu	$t8,0x35($t7)
/*    364ac:	17010004 */ 	bne	$t8,$at,.L000364c0
/*    364b0:	00000000 */ 	nop
/*    364b4:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    364b8:	1000003f */ 	b	.L000365b8
/*    364bc:	a1400035 */ 	sb	$zero,0x35($t2)
.L000364c0:
/*    364c0:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    364c4:	24010004 */ 	addiu	$at,$zero,0x4
/*    364c8:	91390035 */ 	lbu	$t9,0x35($t1)
/*    364cc:	1721003a */ 	bne	$t9,$at,.L000365b8
/*    364d0:	00000000 */ 	nop
/*    364d4:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    364d8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    364dc:	a16e0035 */ 	sb	$t6,0x35($t3)
/*    364e0:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    364e4:	910d0024 */ 	lbu	$t5,0x24($t0)
/*    364e8:	11a00021 */ 	beqz	$t5,.L00036570
/*    364ec:	00000000 */ 	nop
/*    364f0:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    364f4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    364f8:	00185080 */ 	sll	$t2,$t8,0x2
/*    364fc:	01585023 */ 	subu	$t2,$t2,$t8
/*    36500:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    36504:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36508:	01585021 */ 	addu	$t2,$t2,$t8
/*    3650c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36510:	01ea4821 */ 	addu	$t1,$t7,$t2
/*    36514:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36518:	2b213e80 */ 	slti	$at,$t9,0x4e20
/*    3651c:	10200003 */ 	beqz	$at,.L0003652c
/*    36520:	00000000 */ 	nop
/*    36524:	1000000b */ 	b	.L00036554
/*    36528:	24103e80 */ 	addiu	$s0,$zero,0x4e20
.L0003652c:
/*    3652c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36530:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36534:	00086880 */ 	sll	$t5,$t0,0x2
/*    36538:	01a86823 */ 	subu	$t5,$t5,$t0
/*    3653c:	8dcb0060 */ 	lw	$t3,0x60($t6)
/*    36540:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36544:	01a86821 */ 	addu	$t5,$t5,$t0
/*    36548:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3654c:	016d6021 */ 	addu	$t4,$t3,$t5
/*    36550:	8d900020 */ 	lw	$s0,0x20($t4)
.L00036554:
/*    36554:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    36558:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    3655c:	02003025 */ 	or	$a2,$s0,$zero
/*    36560:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    36564:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    36568:	10000013 */ 	b	.L000365b8
/*    3656c:	00000000 */ 	nop
.L00036570:
/*    36570:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    36574:	8f0f0020 */ 	lw	$t7,0x20($t8)
/*    36578:	8dea0000 */ 	lw	$t2,0x0($t7)
/*    3657c:	8d490008 */ 	lw	$t1,0x8($t2)
/*    36580:	29213e80 */ 	slti	$at,$t1,0x4e20
/*    36584:	10200003 */ 	beqz	$at,.L00036594
/*    36588:	00000000 */ 	nop
/*    3658c:	10000005 */ 	b	.L000365a4
/*    36590:	24103e80 */ 	addiu	$s0,$zero,0x4e20
.L00036594:
/*    36594:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    36598:	8f2e0020 */ 	lw	$t6,0x20($t9)
/*    3659c:	8dc80000 */ 	lw	$t0,0x0($t6)
/*    365a0:	8d100008 */ 	lw	$s0,0x8($t0)
.L000365a4:
/*    365a4:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    365a8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    365ac:	02003025 */ 	or	$a2,$s0,$zero
/*    365b0:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    365b4:	24a50004 */ 	addiu	$a1,$a1,0x4
.L000365b8:
/*    365b8:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    365bc:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    365c0:	15a0ffa1 */ 	bnez	$t5,.L00036448
/*    365c4:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000365c8:
/*    365c8:	10000278 */ 	b	.L00036fac
/*    365cc:	00000000 */ 	nop
.L000365d0:
/*    365d0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    365d4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    365d8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    365dc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    365e0:	014f5023 */ 	subu	$t2,$t2,$t7
/*    365e4:	8d980060 */ 	lw	$t8,0x60($t4)
/*    365e8:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365ec:	014f5021 */ 	addu	$t2,$t2,$t7
/*    365f0:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365f4:	030a4821 */ 	addu	$t1,$t8,$t2
/*    365f8:	9139000a */ 	lbu	$t9,0xa($t1)
/*    365fc:	332e0080 */ 	andi	$t6,$t9,0x80
/*    36600:	01c85825 */ 	or	$t3,$t6,$t0
/*    36604:	a12b000a */ 	sb	$t3,0xa($t1)
/*    36608:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3660c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36610:	000fc080 */ 	sll	$t8,$t7,0x2
/*    36614:	030fc023 */ 	subu	$t8,$t8,$t7
/*    36618:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3661c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36620:	030fc021 */ 	addu	$t8,$t8,$t7
/*    36624:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36628:	01985021 */ 	addu	$t2,$t4,$t8
/*    3662c:	9159000a */ 	lbu	$t9,0xa($t2)
/*    36630:	001971c3 */ 	sra	$t6,$t9,0x7
/*    36634:	a3ae00bf */ 	sb	$t6,0xbf($sp)
.L00036638:
/*    36638:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3663c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36640:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36644:	00096880 */ 	sll	$t5,$t1,0x2
/*    36648:	01a96823 */ 	subu	$t5,$t5,$t1
/*    3664c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    36650:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36654:	01a96821 */ 	addu	$t5,$t5,$t1
/*    36658:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3665c:	016d7821 */ 	addu	$t7,$t3,$t5
/*    36660:	91ec000a */ 	lbu	$t4,0xa($t7)
/*    36664:	000ac9c0 */ 	sll	$t9,$t2,0x7
/*    36668:	3198007f */ 	andi	$t8,$t4,0x7f
/*    3666c:	03197025 */ 	or	$t6,$t8,$t9
/*    36670:	a1ee000a */ 	sb	$t6,0xa($t7)
/*    36674:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36678:	8d090064 */ 	lw	$t1,0x64($t0)
/*    3667c:	11200017 */ 	beqz	$t1,.L000366dc
/*    36680:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L00036684:
/*    36684:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36688:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3668c:	916d0031 */ 	lbu	$t5,0x31($t3)
/*    36690:	15ac000e */ 	bne	$t5,$t4,.L000366cc
/*    36694:	00000000 */ 	nop
/*    36698:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    3669c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    366a0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    366a4:	00197080 */ 	sll	$t6,$t9,0x2
/*    366a8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    366ac:	8d580060 */ 	lw	$t8,0x60($t2)
/*    366b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366b4:	01d97021 */ 	addu	$t6,$t6,$t9
/*    366b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366bc:	030e7821 */ 	addu	$t7,$t8,$t6
/*    366c0:	91e5000a */ 	lbu	$a1,0xa($t7)
/*    366c4:	0c00f414 */ 	jal	n_alSynSetFXMix
/*    366c8:	24840004 */ 	addiu	$a0,$a0,0x4
.L000366cc:
/*    366cc:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    366d0:	8d090000 */ 	lw	$t1,0x0($t0)
/*    366d4:	1520ffeb */ 	bnez	$t1,.L00036684
/*    366d8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000366dc:
/*    366dc:	10000233 */ 	b	.L00036fac
/*    366e0:	00000000 */ 	nop
.L000366e4:
/*    366e4:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    366e8:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
/*    366ec:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    366f0:	8dac003c */ 	lw	$t4,0x3c($t5)
/*    366f4:	016c082a */ 	slt	$at,$t3,$t4
/*    366f8:	1020000c */ 	beqz	$at,.L0003672c
/*    366fc:	00000000 */ 	nop
/*    36700:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36704:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    36708:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    3670c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36710:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36714:	8f380060 */ 	lw	$t8,0x60($t9)
/*    36718:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3671c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36720:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36724:	030f4021 */ 	addu	$t0,$t8,$t7
/*    36728:	a10a000b */ 	sb	$t2,0xb($t0)
.L0003672c:
/*    3672c:	1000021f */ 	b	.L00036fac
/*    36730:	00000000 */ 	nop
/*    36734:	0c0040db */ 	jal	snd0001036c
/*    36738:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    3673c:	1000021b */ 	b	.L00036fac
/*    36740:	00000000 */ 	nop
/*    36744:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36748:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3674c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36750:	000cc880 */ 	sll	$t9,$t4,0x2
/*    36754:	032cc823 */ 	subu	$t9,$t9,$t4
/*    36758:	8dab0060 */ 	lw	$t3,0x60($t5)
/*    3675c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36760:	032cc821 */ 	addu	$t9,$t9,$t4
/*    36764:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36768:	01797021 */ 	addu	$t6,$t3,$t9
/*    3676c:	a1c90032 */ 	sb	$t1,0x32($t6)
/*    36770:	1000020e */ 	b	.L00036fac
/*    36774:	00000000 */ 	nop
/*    36778:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3677c:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36780:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36784:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36788:	3c0a8006 */ 	lui	$t2,%hi(var8005f150)
/*    3678c:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36790:	00187880 */ 	sll	$t7,$t8,0x2
/*    36794:	8d0d0060 */ 	lw	$t5,0x60($t0)
/*    36798:	014f5021 */ 	addu	$t2,$t2,$t7
/*    3679c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367a0:	8d4af150 */ 	lw	$t2,%lo(var8005f150)($t2)
/*    367a4:	016c5821 */ 	addu	$t3,$t3,$t4
/*    367a8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367ac:	01abc821 */ 	addu	$t9,$t5,$t3
/*    367b0:	af2a0018 */ 	sw	$t2,0x18($t9)
/*    367b4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    367b8:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    367bc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    367c0:	000f4080 */ 	sll	$t0,$t7,0x2
/*    367c4:	010f4023 */ 	subu	$t0,$t0,$t7
/*    367c8:	8dd80060 */ 	lw	$t8,0x60($t6)
/*    367cc:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d0:	010f4021 */ 	addu	$t0,$t0,$t7
/*    367d4:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d8:	03086021 */ 	addu	$t4,$t8,$t0
/*    367dc:	a1890024 */ 	sb	$t1,0x24($t4)
/*    367e0:	100001f2 */ 	b	.L00036fac
/*    367e4:	00000000 */ 	nop
/*    367e8:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    367ec:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    367f0:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    367f4:	00197080 */ 	sll	$t6,$t9,0x2
/*    367f8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    367fc:	8d6a0060 */ 	lw	$t2,0x60($t3)
/*    36800:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36804:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36808:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3680c:	014e7821 */ 	addu	$t7,$t2,$t6
/*    36810:	a1ed0025 */ 	sb	$t5,0x25($t7)
/*    36814:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36818:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    3681c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36820:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36824:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36828:	8d090060 */ 	lw	$t1,0x60($t0)
/*    3682c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36830:	016c5821 */ 	addu	$t3,$t3,$t4
/*    36834:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36838:	012bc821 */ 	addu	$t9,$t1,$t3
/*    3683c:	a3380024 */ 	sb	$t8,0x24($t9)
/*    36840:	100001da */ 	b	.L00036fac
/*    36844:	00000000 */ 	nop
/*    36848:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3684c:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36850:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36854:	000c4880 */ 	sll	$t1,$t4,0x2
/*    36858:	3c0d8006 */ 	lui	$t5,%hi(var8005f150)
/*    3685c:	012c4823 */ 	subu	$t1,$t1,$t4
/*    36860:	000a7080 */ 	sll	$t6,$t2,0x2
/*    36864:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36868:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    3686c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36870:	8dadf150 */ 	lw	$t5,%lo(var8005f150)($t5)
/*    36874:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36878:	00094880 */ 	sll	$t1,$t1,0x2
/*    3687c:	01095821 */ 	addu	$t3,$t0,$t1
/*    36880:	ad6d001c */ 	sw	$t5,0x1c($t3)
/*    36884:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36888:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3688c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36890:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36894:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36898:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*    3689c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    368a4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a8:	014f6021 */ 	addu	$t4,$t2,$t7
/*    368ac:	a1980024 */ 	sb	$t8,0x24($t4)
/*    368b0:	100001be */ 	b	.L00036fac
/*    368b4:	00000000 */ 	nop
/*    368b8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    368bc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    368c0:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    368c4:	000bc880 */ 	sll	$t9,$t3,0x2
/*    368c8:	032bc823 */ 	subu	$t9,$t9,$t3
/*    368cc:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    368d0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368d4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    368d8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368dc:	01b97021 */ 	addu	$t6,$t5,$t9
/*    368e0:	a1c80026 */ 	sb	$t0,0x26($t6)
/*    368e4:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    368e8:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    368ec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    368f0:	000c4880 */ 	sll	$t1,$t4,0x2
/*    368f4:	012c4823 */ 	subu	$t1,$t1,$t4
/*    368f8:	8df80060 */ 	lw	$t8,0x60($t7)
/*    368fc:	00094880 */ 	sll	$t1,$t1,0x2
/*    36900:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36904:	00094880 */ 	sll	$t1,$t1,0x2
/*    36908:	03095821 */ 	addu	$t3,$t8,$t1
/*    3690c:	a16a0024 */ 	sb	$t2,0x24($t3)
/*    36910:	100001a6 */ 	b	.L00036fac
/*    36914:	00000000 */ 	nop
/*    36918:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3691c:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    36920:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36924:	000cc080 */ 	sll	$t8,$t4,0x2
/*    36928:	3c088006 */ 	lui	$t0,%hi(var8005f150)
/*    3692c:	030cc023 */ 	subu	$t8,$t8,$t4
/*    36930:	000dc880 */ 	sll	$t9,$t5,0x2
/*    36934:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    36938:	01194021 */ 	addu	$t0,$t0,$t9
/*    3693c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36940:	8d08f150 */ 	lw	$t0,%lo(var8005f150)($t0)
/*    36944:	030cc021 */ 	addu	$t8,$t8,$t4
/*    36948:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3694c:	01f84821 */ 	addu	$t1,$t7,$t8
/*    36950:	ad280020 */ 	sw	$t0,0x20($t1)
/*    36954:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36958:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    3695c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    36960:	00197080 */ 	sll	$t6,$t9,0x2
/*    36964:	01d97023 */ 	subu	$t6,$t6,$t9
/*    36968:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    3696c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36970:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36974:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36978:	01ae6021 */ 	addu	$t4,$t5,$t6
/*    3697c:	a18a0024 */ 	sb	$t2,0x24($t4)
/*    36980:	1000018a */ 	b	.L00036fac
/*    36984:	00000000 */ 	nop
/*    36988:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    3698c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36990:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    36994:	000bc880 */ 	sll	$t9,$t3,0x2
/*    36998:	032bc823 */ 	subu	$t9,$t9,$t3
/*    3699c:	8d090060 */ 	lw	$t1,0x60($t0)
/*    369a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369a4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    369a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369ac:	25f8ffc0 */ 	addiu	$t8,$t7,-64
/*    369b0:	01396821 */ 	addu	$t5,$t1,$t9
/*    369b4:	a1b80027 */ 	sb	$t8,0x27($t5)
/*    369b8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    369bc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    369c0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    369c4:	000f4080 */ 	sll	$t0,$t7,0x2
/*    369c8:	010f4023 */ 	subu	$t0,$t0,$t7
/*    369cc:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    369d0:	00084080 */ 	sll	$t0,$t0,0x2
/*    369d4:	010f4021 */ 	addu	$t0,$t0,$t7
/*    369d8:	00084080 */ 	sll	$t0,$t0,0x2
/*    369dc:	01885821 */ 	addu	$t3,$t4,$t0
/*    369e0:	a16e0024 */ 	sb	$t6,0x24($t3)
/*    369e4:	10000171 */ 	b	.L00036fac
/*    369e8:	00000000 */ 	nop
/*    369ec:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    369f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    369f4:	24010064 */ 	addiu	$at,$zero,0x64
/*    369f8:	00186880 */ 	sll	$t5,$t8,0x2
/*    369fc:	01b86823 */ 	subu	$t5,$t5,$t8
/*    36a00:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36a04:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a08:	01b86821 */ 	addu	$t5,$t5,$t8
/*    36a0c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a10:	032d5021 */ 	addu	$t2,$t9,$t5
/*    36a14:	854f0004 */ 	lh	$t7,0x4($t2)
/*    36a18:	01e1001a */ 	div	$zero,$t7,$at
/*    36a1c:	00006012 */ 	mflo	$t4
/*    36a20:	a54c0004 */ 	sh	$t4,0x4($t2)
/*    36a24:	00000000 */ 	nop
/*    36a28:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36a2c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36a30:	000b4880 */ 	sll	$t1,$t3,0x2
/*    36a34:	012b4823 */ 	subu	$t1,$t1,$t3
/*    36a38:	8d0e0060 */ 	lw	$t6,0x60($t0)
/*    36a3c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a40:	012b4821 */ 	addu	$t1,$t1,$t3
/*    36a44:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a48:	01c9c021 */ 	addu	$t8,$t6,$t1
/*    36a4c:	87190004 */ 	lh	$t9,0x4($t8)
/*    36a50:	00196880 */ 	sll	$t5,$t9,0x2
/*    36a54:	01b96823 */ 	subu	$t5,$t5,$t9
/*    36a58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    36a5c:	01b96821 */ 	addu	$t5,$t5,$t9
/*    36a60:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a64:	a70d0004 */ 	sh	$t5,0x4($t8)
/*    36a68:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36a6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36a70:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36a74:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36a78:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36a7c:	8dec0060 */ 	lw	$t4,0x60($t7)
/*    36a80:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a84:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36a88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a8c:	01885821 */ 	addu	$t3,$t4,$t0
/*    36a90:	856e0004 */ 	lh	$t6,0x4($t3)
/*    36a94:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36a98:	a5790004 */ 	sh	$t9,0x4($t3)
/*    36a9c:	10000143 */ 	b	.L00036fac
/*    36aa0:	00000000 */ 	nop
/*    36aa4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36aa8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36aac:	24010064 */ 	addiu	$at,$zero,0x64
/*    36ab0:	000f5080 */ 	sll	$t2,$t7,0x2
/*    36ab4:	014f5023 */ 	subu	$t2,$t2,$t7
/*    36ab8:	8db80060 */ 	lw	$t8,0x60($t5)
/*    36abc:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac0:	014f5021 */ 	addu	$t2,$t2,$t7
/*    36ac4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac8:	030a6021 */ 	addu	$t4,$t8,$t2
/*    36acc:	85880004 */ 	lh	$t0,0x4($t4)
/*    36ad0:	0101001a */ 	div	$zero,$t0,$at
/*    36ad4:	00007010 */ 	mfhi	$t6
/*    36ad8:	a58e0004 */ 	sh	$t6,0x4($t4)
/*    36adc:	00000000 */ 	nop
/*    36ae0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36ae4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ae8:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36aec:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36af0:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36af4:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36af8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36afc:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b00:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b04:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36b08:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36b0c:	032d7821 */ 	addu	$t7,$t9,$t5
/*    36b10:	85f80004 */ 	lh	$t8,0x4($t7)
/*    36b14:	000840c0 */ 	sll	$t0,$t0,0x3
/*    36b18:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36b1c:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b20:	03087021 */ 	addu	$t6,$t8,$t0
/*    36b24:	a5ee0004 */ 	sh	$t6,0x4($t7)
/*    36b28:	10000120 */ 	b	.L00036fac
/*    36b2c:	00000000 */ 	nop
/*    36b30:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36b34:	11800004 */ 	beqz	$t4,.L00036b48
/*    36b38:	00000000 */ 	nop
/*    36b3c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36b40:	252b0080 */ 	addiu	$t3,$t1,0x80
/*    36b44:	a3ab00bf */ 	sb	$t3,0xbf($sp)
.L00036b48:
/*    36b48:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36b4c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36b50:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36b54:	00184080 */ 	sll	$t0,$t8,0x2
/*    36b58:	01184023 */ 	subu	$t0,$t0,$t8
/*    36b5c:	8daa0060 */ 	lw	$t2,0x60($t5)
/*    36b60:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b64:	01184021 */ 	addu	$t0,$t0,$t8
/*    36b68:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b6c:	01487021 */ 	addu	$t6,$t2,$t0
/*    36b70:	a1d9002c */ 	sb	$t9,0x2c($t6)
/*    36b74:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36b78:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36b7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    36b80:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36b84:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36b88:	8d890060 */ 	lw	$t1,0x60($t4)
/*    36b8c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b90:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b94:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b98:	012dc021 */ 	addu	$t8,$t1,$t5
/*    36b9c:	a30f0024 */ 	sb	$t7,0x24($t8)
/*    36ba0:	10000102 */ 	b	.L00036fac
/*    36ba4:	00000000 */ 	nop
/*    36ba8:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36bac:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36bb0:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36bb4:	000e6080 */ 	sll	$t4,$t6,0x2
/*    36bb8:	018e6023 */ 	subu	$t4,$t4,$t6
/*    36bbc:	8d190060 */ 	lw	$t9,0x60($t0)
/*    36bc0:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bc4:	018e6021 */ 	addu	$t4,$t4,$t6
/*    36bc8:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bcc:	032c5821 */ 	addu	$t3,$t9,$t4
/*    36bd0:	a16a002d */ 	sb	$t2,0x2d($t3)
/*    36bd4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36bd8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36bdc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    36be0:	00184080 */ 	sll	$t0,$t8,0x2
/*    36be4:	01184023 */ 	subu	$t0,$t0,$t8
/*    36be8:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    36bec:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf0:	01184021 */ 	addu	$t0,$t0,$t8
/*    36bf4:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf8:	01e87021 */ 	addu	$t6,$t7,$t0
/*    36bfc:	a1c90024 */ 	sb	$t1,0x24($t6)
/*    36c00:	100000ea */ 	b	.L00036fac
/*    36c04:	00000000 */ 	nop
/*    36c08:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c0c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36c10:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36c14:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36c18:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36c1c:	8d4b0060 */ 	lw	$t3,0x60($t2)
/*    36c20:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c24:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36c28:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c2c:	00196040 */ 	sll	$t4,$t9,0x1
/*    36c30:	01787821 */ 	addu	$t7,$t3,$t8
/*    36c34:	a1ec002e */ 	sb	$t4,0x2e($t7)
/*    36c38:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36c3c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36c40:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36c44:	00195080 */ 	sll	$t2,$t9,0x2
/*    36c48:	01595023 */ 	subu	$t2,$t2,$t9
/*    36c4c:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36c50:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c54:	01595021 */ 	addu	$t2,$t2,$t9
/*    36c58:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c5c:	01ca6821 */ 	addu	$t5,$t6,$t2
/*    36c60:	a1a80024 */ 	sb	$t0,0x24($t5)
/*    36c64:	100000d1 */ 	b	.L00036fac
/*    36c68:	00000000 */ 	nop
/*    36c6c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36c70:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36c74:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36c78:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36c7c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36c80:	8f0c0060 */ 	lw	$t4,0x60($t8)
/*    36c84:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c88:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36c8c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c90:	0189c821 */ 	addu	$t9,$t4,$t1
/*    36c94:	a32b002f */ 	sb	$t3,0x2f($t9)
/*    36c98:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c9c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36ca0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36ca4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36ca8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36cac:	8d480060 */ 	lw	$t0,0x60($t2)
/*    36cb0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cb4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36cb8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cbc:	01187821 */ 	addu	$t7,$t0,$t8
/*    36cc0:	a1ee0024 */ 	sb	$t6,0x24($t7)
/*    36cc4:	100000b9 */ 	b	.L00036fac
/*    36cc8:	00000000 */ 	nop
/*    36ccc:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36cd0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36cd4:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36cd8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36cdc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36ce0:	8d2b0060 */ 	lw	$t3,0x60($t1)
/*    36ce4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ce8:	01595021 */ 	addu	$t2,$t2,$t9
/*    36cec:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36cf0:	016a6821 */ 	addu	$t5,$t3,$t2
/*    36cf4:	a1ac0028 */ 	sb	$t4,0x28($t5)
/*    36cf8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36cfc:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d00:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36d04:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d08:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36d0c:	8f0e0060 */ 	lw	$t6,0x60($t8)
/*    36d10:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d14:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36d18:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d1c:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36d20:	a3280024 */ 	sb	$t0,0x24($t9)
/*    36d24:	100000a1 */ 	b	.L00036fac
/*    36d28:	00000000 */ 	nop
/*    36d2c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36d30:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36d34:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36d38:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36d3c:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36d40:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    36d44:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d48:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36d4c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d50:	01987821 */ 	addu	$t7,$t4,$t8
/*    36d54:	a1eb0029 */ 	sb	$t3,0x29($t7)
/*    36d58:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36d5c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36d60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36d64:	00195080 */ 	sll	$t2,$t9,0x2
/*    36d68:	01595023 */ 	subu	$t2,$t2,$t9
/*    36d6c:	8d280060 */ 	lw	$t0,0x60($t1)
/*    36d70:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d74:	01595021 */ 	addu	$t2,$t2,$t9
/*    36d78:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d7c:	010a6821 */ 	addu	$t5,$t0,$t2
/*    36d80:	a1ae0024 */ 	sb	$t6,0x24($t5)
/*    36d84:	10000089 */ 	b	.L00036fac
/*    36d88:	00000000 */ 	nop
/*    36d8c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36d90:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d94:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36d98:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d9c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36da0:	8f0b0060 */ 	lw	$t3,0x60($t8)
/*    36da4:	00094880 */ 	sll	$t1,$t1,0x2
/*    36da8:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36dac:	00094880 */ 	sll	$t1,$t1,0x2
/*    36db0:	0169c821 */ 	addu	$t9,$t3,$t1
/*    36db4:	a32c002a */ 	sb	$t4,0x2a($t9)
/*    36db8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36dbc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36dc0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36dc4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36dc8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36dcc:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36dd0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36dd4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36dd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36ddc:	01d87821 */ 	addu	$t7,$t6,$t8
/*    36de0:	a1e80024 */ 	sb	$t0,0x24($t7)
/*    36de4:	10000071 */ 	b	.L00036fac
/*    36de8:	00000000 */ 	nop
/*    36dec:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36df0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36df4:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36df8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36dfc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36e00:	8d2c0060 */ 	lw	$t4,0x60($t1)
/*    36e04:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e08:	01595021 */ 	addu	$t2,$t2,$t9
/*    36e0c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e10:	018a6821 */ 	addu	$t5,$t4,$t2
/*    36e14:	a1ab002b */ 	sb	$t3,0x2b($t5)
/*    36e18:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36e1c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36e20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36e24:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36e28:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36e2c:	8f080060 */ 	lw	$t0,0x60($t8)
/*    36e30:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e34:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36e38:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e3c:	0109c821 */ 	addu	$t9,$t0,$t1
/*    36e40:	a32e0024 */ 	sb	$t6,0x24($t9)
/*    36e44:	10000059 */ 	b	.L00036fac
/*    36e48:	00000000 */ 	nop
/*    36e4c:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36e50:	000c5040 */ 	sll	$t2,$t4,0x1
/*    36e54:	a3aa00bf */ 	sb	$t2,0xbf($sp)
/*    36e58:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36e5c:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    36e60:	11a00041 */ 	beqz	$t5,.L00036f68
/*    36e64:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00036e68:
/*    36e68:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36e6c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36e70:	930f0031 */ 	lbu	$t7,0x31($t8)
/*    36e74:	15e80038 */ 	bne	$t7,$t0,.L00036f58
/*    36e78:	00000000 */ 	nop
/*    36e7c:	8f09003c */ 	lw	$t1,0x3c($t8)
/*    36e80:	11200035 */ 	beqz	$t1,.L00036f58
/*    36e84:	00000000 */ 	nop
/*    36e88:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    36e8c:	8dd9003c */ 	lw	$t9,0x3c($t6)
/*    36e90:	afb9005c */ 	sw	$t9,0x5c($sp)
/*    36e94:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    36e98:	2401ff7f */ 	addiu	$at,$zero,-129
/*    36e9c:	918a0004 */ 	lbu	$t2,0x4($t4)
/*    36ea0:	01415824 */ 	and	$t3,$t2,$at
/*    36ea4:	256dfffe */ 	addiu	$t5,$t3,-2
/*    36ea8:	2da1000c */ 	sltiu	$at,$t5,0xc
/*    36eac:	10200024 */ 	beqz	$at,.L00036f40
/*    36eb0:	00000000 */ 	nop
/*    36eb4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36eb8:	3c017005 */ 	lui	$at,%hi(var70054a48)
/*    36ebc:	002d0821 */ 	addu	$at,$at,$t5
/*    36ec0:	8c2d4a48 */ 	lw	$t5,%lo(var70054a48)($at)
/*    36ec4:	01a00008 */ 	jr	$t5
/*    36ec8:	00000000 */ 	nop
/*    36ecc:	0c00bf18 */ 	jal	func0002fc60
/*    36ed0:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ed4:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    36ed8:	46000407 */ 	neg.s	$f16,$f0
/*    36edc:	e5f00010 */ 	swc1	$f16,0x10($t7)
/*    36ee0:	0c00bf18 */ 	jal	func0002fc60
/*    36ee4:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ee8:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    36eec:	e500000c */ 	swc1	$f0,0xc($t0)
/*    36ef0:	10000019 */ 	b	.L00036f58
/*    36ef4:	00000000 */ 	nop
/*    36ef8:	0c00bf18 */ 	jal	func0002fc60
/*    36efc:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f00:	3c014000 */ 	lui	$at,0x4000
/*    36f04:	44819000 */ 	mtc1	$at,$f18
/*    36f08:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    36f0c:	46120103 */ 	div.s	$f4,$f0,$f18
/*    36f10:	e704000c */ 	swc1	$f4,0xc($t8)
/*    36f14:	10000010 */ 	b	.L00036f58
/*    36f18:	00000000 */ 	nop
/*    36f1c:	0c00bf18 */ 	jal	func0002fc60
/*    36f20:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f24:	3c014000 */ 	lui	$at,0x4000
/*    36f28:	44813000 */ 	mtc1	$at,$f6
/*    36f2c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    36f30:	46060202 */ 	mul.s	$f8,$f0,$f6
/*    36f34:	e528000c */ 	swc1	$f8,0xc($t1)
/*    36f38:	10000007 */ 	b	.L00036f58
/*    36f3c:	00000000 */ 	nop
.L00036f40:
/*    36f40:	0c00bf18 */ 	jal	func0002fc60
/*    36f44:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f48:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    36f4c:	e5c0000c */ 	swc1	$f0,0xc($t6)
/*    36f50:	10000001 */ 	b	.L00036f58
/*    36f54:	00000000 */ 	nop
.L00036f58:
/*    36f58:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    36f5c:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*    36f60:	1580ffc1 */ 	bnez	$t4,.L00036e68
/*    36f64:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036f68:
/*    36f68:	10000010 */ 	b	.L00036fac
/*    36f6c:	00000000 */ 	nop
/*    36f70:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36f74:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36f78:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36f7c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    36f80:	010f4023 */ 	subu	$t0,$t0,$t7
/*    36f84:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    36f88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f8c:	010f4021 */ 	addu	$t0,$t0,$t7
/*    36f90:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f94:	01a8c021 */ 	addu	$t8,$t5,$t0
/*    36f98:	a30a0031 */ 	sb	$t2,0x31($t8)
/*    36f9c:	10000003 */ 	b	.L00036fac
/*    36fa0:	00000000 */ 	nop
.L00036fa4:
/*    36fa4:	10000001 */ 	b	.L00036fac
/*    36fa8:	00000000 */ 	nop
.L00036fac:
/*    36fac:	10000094 */ 	b	.L00037200
/*    36fb0:	00000000 */ 	nop
/*    36fb4:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36fb8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36fbc:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    36fc0:	00196080 */ 	sll	$t4,$t9,0x2
/*    36fc4:	01996023 */ 	subu	$t4,$t4,$t9
/*    36fc8:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36fcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd0:	01996021 */ 	addu	$t4,$t4,$t9
/*    36fd4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*    36fdc:	916f0032 */ 	lbu	$t7,0x32($t3)
/*    36fe0:	000f69c0 */ 	sll	$t5,$t7,0x7
/*    36fe4:	01a85021 */ 	addu	$t2,$t5,$t0
/*    36fe8:	afaa0090 */ 	sw	$t2,0x90($sp)
/*    36fec:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ff0:	8fb80090 */ 	lw	$t8,0x90($sp)
/*    36ff4:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36ff8:	872e0000 */ 	lh	$t6,0x0($t9)
/*    36ffc:	030e082a */ 	slt	$at,$t8,$t6
/*    37000:	1020000e */ 	beqz	$at,.L0003703c
/*    37004:	00000000 */ 	nop
/*    37008:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3700c:	8faf0090 */ 	lw	$t7,0x90($sp)
/*    37010:	8d8b0020 */ 	lw	$t3,0x20($t4)
/*    37014:	000f6880 */ 	sll	$t5,$t7,0x2
/*    37018:	016d4021 */ 	addu	$t0,$t3,$t5
/*    3701c:	8d0a000c */ 	lw	$t2,0xc($t0)
/*    37020:	afaa0058 */ 	sw	$t2,0x58($sp)
/*    37024:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    37028:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    3702c:	0c00f7d9 */ 	jal	__n_setInstChanState
/*    37030:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    37034:	10000001 */ 	b	.L0003703c
/*    37038:	00000000 */ 	nop
.L0003703c:
/*    3703c:	10000070 */ 	b	.L00037200
/*    37040:	00000000 */ 	nop
/*    37044:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    37048:	93b800c0 */ 	lbu	$t8,0xc0($sp)
/*    3704c:	0009c9c0 */ 	sll	$t9,$t1,0x7
/*    37050:	03387021 */ 	addu	$t6,$t9,$t8
/*    37054:	25cce000 */ 	addiu	$t4,$t6,-8192
/*    37058:	afac0054 */ 	sw	$t4,0x54($sp)
/*    3705c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    37060:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    37064:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    37068:	000d4080 */ 	sll	$t0,$t5,0x2
/*    3706c:	010d4023 */ 	subu	$t0,$t0,$t5
/*    37070:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    37074:	00084080 */ 	sll	$t0,$t0,0x2
/*    37078:	010d4021 */ 	addu	$t0,$t0,$t5
/*    3707c:	00084080 */ 	sll	$t0,$t0,0x2
/*    37080:	01685021 */ 	addu	$t2,$t3,$t0
/*    37084:	85490004 */ 	lh	$t1,0x4($t2)
/*    37088:	01390019 */ 	multu	$t1,$t9
/*    3708c:	0000c012 */ 	mflo	$t8
/*    37090:	07010003 */ 	bgez	$t8,.L000370a0
/*    37094:	00187343 */ 	sra	$t6,$t8,0xd
/*    37098:	27011fff */ 	addiu	$at,$t8,0x1fff
/*    3709c:	00017343 */ 	sra	$t6,$at,0xd
.L000370a0:
/*    370a0:	afae004c */ 	sw	$t6,0x4c($sp)
/*    370a4:	0c00e7f8 */ 	jal	func00039fe0
/*    370a8:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*    370ac:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*    370b0:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    370b4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    370b8:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    370bc:	000d5880 */ 	sll	$t3,$t5,0x2
/*    370c0:	016d5823 */ 	subu	$t3,$t3,$t5
/*    370c4:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    370c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370cc:	016d5821 */ 	addu	$t3,$t3,$t5
/*    370d0:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370d4:	01eb4021 */ 	addu	$t0,$t7,$t3
/*    370d8:	e50a0014 */ 	swc1	$f10,0x14($t0)
/*    370dc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    370e0:	8d490064 */ 	lw	$t1,0x64($t2)
/*    370e4:	11200042 */ 	beqz	$t1,.L000371f0
/*    370e8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000370ec:
/*    370ec:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    370f0:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    370f4:	93380031 */ 	lbu	$t8,0x31($t9)
/*    370f8:	170e0039 */ 	bne	$t8,$t6,.L000371e0
/*    370fc:	00000000 */ 	nop
/*    37100:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    37104:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    37108:	c5900028 */ 	lwc1	$f16,0x28($t4)
/*    3710c:	c586002c */ 	lwc1	$f6,0x2c($t4)
/*    37110:	25840004 */ 	addiu	$a0,$t4,0x4
/*    37114:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    37118:	00000000 */ 	nop
/*    3711c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    37120:	44054000 */ 	mfc1	$a1,$f8
/*    37124:	0c00f3e8 */ 	jal	n_alSynSetPitch
/*    37128:	00000000 */ 	nop
/*    3712c:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    37130:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    37134:	000b4080 */ 	sll	$t0,$t3,0x2
/*    37138:	010b4023 */ 	subu	$t0,$t0,$t3
/*    3713c:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    37140:	00084080 */ 	sll	$t0,$t0,0x2
/*    37144:	010b4021 */ 	addu	$t0,$t0,$t3
/*    37148:	00084080 */ 	sll	$t0,$t0,0x2
/*    3714c:	01e85021 */ 	addu	$t2,$t7,$t0
/*    37150:	91490011 */ 	lbu	$t1,0x11($t2)
/*    37154:	11200022 */ 	beqz	$t1,.L000371e0
/*    37158:	00000000 */ 	nop
/*    3715c:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    37160:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    37164:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    37168:	8dea0020 */ 	lw	$t2,0x20($t7)
/*    3716c:	000e6080 */ 	sll	$t4,$t6,0x2
/*    37170:	018e6023 */ 	subu	$t4,$t4,$t6
/*    37174:	8f380060 */ 	lw	$t8,0x60($t9)
/*    37178:	8d490004 */ 	lw	$t1,0x4($t2)
/*    3717c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37180:	018e6021 */ 	addu	$t4,$t4,$t6
/*    37184:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37188:	91e80032 */ 	lbu	$t0,0x32($t7)
/*    3718c:	91390004 */ 	lbu	$t9,0x4($t1)
/*    37190:	030c6821 */ 	addu	$t5,$t8,$t4
/*    37194:	91ab0012 */ 	lbu	$t3,0x12($t5)
/*    37198:	01197023 */ 	subu	$t6,$t0,$t9
/*    3719c:	016e2021 */ 	addu	$a0,$t3,$t6
/*    371a0:	0c00ee75 */ 	jal	func0003b9d4
/*    371a4:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    371a8:	3c0143dc */ 	lui	$at,0x43dc
/*    371ac:	44815000 */ 	mtc1	$at,$f10
/*    371b0:	46000506 */ 	mov.s	$f20,$f0
/*    371b4:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    371b8:	460aa402 */ 	mul.s	$f16,$f20,$f10
/*    371bc:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    371c0:	c706002c */ 	lwc1	$f6,0x2c($t8)
/*    371c4:	27040004 */ 	addiu	$a0,$t8,0x4
/*    371c8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    371cc:	00000000 */ 	nop
/*    371d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    371d4:	44054000 */ 	mfc1	$a1,$f8
/*    371d8:	0c00f8f8 */ 	jal	func0003e3e0
/*    371dc:	00000000 */ 	nop
.L000371e0:
/*    371e0:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    371e4:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    371e8:	15a0ffc0 */ 	bnez	$t5,.L000370ec
/*    371ec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000371f0:
/*    371f0:	10000003 */ 	b	.L00037200
/*    371f4:	00000000 */ 	nop
.L000371f8:
/*    371f8:	10000001 */ 	b	.L00037200
/*    371fc:	00000000 */ 	nop
.L00037200:
/*    37200:	10000001 */ 	b	.L00037208
/*    37204:	00000000 */ 	nop
.L00037208:
/*    37208:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    3720c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*    37210:	8fb00034 */ 	lw	$s0,0x34($sp)
/*    37214:	8fb10038 */ 	lw	$s1,0x38($sp)
/*    37218:	03e00008 */ 	jr	$ra
/*    3721c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#else
GLOBAL_ASM(
glabel __n_CSPHandleMIDIMsg
.late_rodata
glabel var70054838
.word __n_CSPHandleMIDIMsg+0x0934
glabel var7005483c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054840
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054844
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054848
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005484c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054850
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054854
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054858
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005485c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054860
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054864
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054868
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005486c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054870
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054874
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054878
.word __n_CSPHandleMIDIMsg+0x0094
glabel var7005487c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054880
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054884
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054888
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005488c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054890
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054894
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054898
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005489c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548a8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548ac
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548b8
.word __n_CSPHandleMIDIMsg+0x0a58
glabel var700548bc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548c8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548cc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548d8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548dc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548e8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548ec
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700548f8
.word __n_CSPHandleMIDIMsg+0x0b54
glabel var700548fc
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054900
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054904
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054908
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005490c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054910
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054914
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054918
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005491c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054920
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054924
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054928
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005492c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054930
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054934
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054938
.word __n_CSPHandleMIDIMsg+0x1ea4
glabel var7005493c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054940
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054944
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054948
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005494c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054950
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054954
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054958
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005495c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054960
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054964
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054968
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005496c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054970
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054974
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054978
.word __n_CSPHandleMIDIMsg+0x0ad0
glabel var7005497c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054980
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054984
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054988
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005498c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054990
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054994
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var70054998
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var7005499c
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549a8
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549ac
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b0
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b4
.word __n_CSPHandleMIDIMsg+0x20e8
glabel var700549b8
.word __n_CSPHandleMIDIMsg+0x1f34

glabel var700549bc
.word __n_CSPHandleMIDIMsg+0x1d3c
glabel var700549c0
.word __n_CSPHandleMIDIMsg+0x1878
glabel var700549c4
.word __n_CSPHandleMIDIMsg+0x18dc
glabel var700549c8
.word __n_CSPHandleMIDIMsg+0x1994
glabel var700549cc
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549d0
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549d4
.word __n_CSPHandleMIDIMsg+0x1218
glabel var700549d8
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549dc
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var700549e0
.word __n_CSPHandleMIDIMsg+0x0c30
glabel var700549e4
.word __n_CSPHandleMIDIMsg+0x1a20
glabel var700549e8
.word __n_CSPHandleMIDIMsg+0x1a98
glabel var700549ec
.word __n_CSPHandleMIDIMsg+0x1af8
glabel var700549f0
.word __n_CSPHandleMIDIMsg+0x1b5c
glabel var700549f4
.word __n_CSPHandleMIDIMsg+0x1bbc
glabel var700549f8
.word __n_CSPHandleMIDIMsg+0x12c8
glabel var700549fc
.word __n_CSPHandleMIDIMsg+0x1c1c
glabel var70054a00
.word __n_CSPHandleMIDIMsg+0x1c7c
glabel var70054a04
.word __n_CSPHandleMIDIMsg+0x1cdc
glabel var70054a08
.word __n_CSPHandleMIDIMsg+0x1668
glabel var70054a0c
.word __n_CSPHandleMIDIMsg+0x16d8
glabel var70054a10
.word __n_CSPHandleMIDIMsg+0x1738
glabel var70054a14
.word __n_CSPHandleMIDIMsg+0x17a8
glabel var70054a18
.word __n_CSPHandleMIDIMsg+0x1808
glabel var70054a1c
.word __n_CSPHandleMIDIMsg+0x1e60
glabel var70054a20
.word __n_CSPHandleMIDIMsg+0x1624
glabel var70054a24
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a28
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a2c
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a30
.word __n_CSPHandleMIDIMsg+0x11d0
glabel var70054a34
.word __n_CSPHandleMIDIMsg+0x1e94
glabel var70054a38
.word __n_CSPHandleMIDIMsg+0x1634
glabel var70054a3c
.word __n_CSPHandleMIDIMsg+0x10d8
glabel var70054a40
.word __n_CSPHandleMIDIMsg+0x1118
glabel var70054a44
.word __n_CSPHandleMIDIMsg+0x1158
glabel var70054a48
.word __n_CSPHandleMIDIMsg+0x1dbc
glabel var70054a4c
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a50
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a54
.word __n_CSPHandleMIDIMsg+0x1dd0
glabel var70054a58
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a5c
.word __n_CSPHandleMIDIMsg+0x1de8
glabel var70054a60
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a64
.word __n_CSPHandleMIDIMsg+0x1de8
glabel var70054a68
.word __n_CSPHandleMIDIMsg+0x1e0c
glabel var70054a6c
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a70
.word __n_CSPHandleMIDIMsg+0x1e30
glabel var70054a74
.word __n_CSPHandleMIDIMsg+0x1de8
.text
/*    35110:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    35114:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    35118:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*    3511c:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*    35120:	afb10038 */ 	sw	$s1,0x38($sp)
/*    35124:	afb00034 */ 	sw	$s0,0x34($sp)
/*    35128:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*    3512c:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*    35130:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*    35134:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*    35138:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    3513c:	93190004 */ 	lbu	$t9,0x4($t8)
/*    35140:	332800f0 */ 	andi	$t0,$t9,0xf0
/*    35144:	afa800c4 */ 	sw	$t0,0xc4($sp)
/*    35148:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*    3514c:	912a0004 */ 	lbu	$t2,0x4($t1)
/*    35150:	314b000f */ 	andi	$t3,$t2,0xf
/*    35154:	a3ab00c3 */ 	sb	$t3,0xc3($sp)
/*    35158:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    3515c:	918d0005 */ 	lbu	$t5,0x5($t4)
/*    35160:	a3ad00c2 */ 	sb	$t5,0xc2($sp)
/*    35164:	a3ad00c0 */ 	sb	$t5,0xc0($sp)
/*    35168:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3516c:	91cf0006 */ 	lbu	$t7,0x6($t6)
/*    35170:	a3af00c1 */ 	sb	$t7,0xc1($sp)
/*    35174:	a3af00bf */ 	sb	$t7,0xbf($sp)
/*    35178:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*    3517c:	2719ff80 */ 	addiu	$t9,$t8,-128
/*    35180:	2f210061 */ 	sltiu	$at,$t9,0x61
/*    35184:	1020081c */ 	beqz	$at,.L000371f8
/*    35188:	00000000 */ 	nop
/*    3518c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35190:	3c017005 */ 	lui	$at,%hi(var70054838)
/*    35194:	00390821 */ 	addu	$at,$at,$t9
/*    35198:	8c394838 */ 	lw	$t9,%lo(var70054838)($at)
/*    3519c:	03200008 */ 	jr	$t9
/*    351a0:	00000000 */ 	nop
/*    351a4:	93a800c1 */ 	lbu	$t0,0xc1($sp)
/*    351a8:	11000226 */ 	beqz	$t0,.L00035a44
/*    351ac:	00000000 */ 	nop
/*    351b0:	afa0006c */ 	sw	$zero,0x6c($sp)
/*    351b4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    351b8:	24010001 */ 	addiu	$at,$zero,0x1
/*    351bc:	8d2a002c */ 	lw	$t2,0x2c($t1)
/*    351c0:	15410008 */ 	bne	$t2,$at,.L000351e4
/*    351c4:	00000000 */ 	nop
/*    351c8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    351cc:	952b0030 */ 	lhu	$t3,0x30($t1)
/*    351d0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    351d4:	018d7004 */ 	sllv	$t6,$t5,$t4
/*    351d8:	016e7824 */ 	and	$t7,$t3,$t6
/*    351dc:	15e00023 */ 	bnez	$t7,.L0003526c
/*    351e0:	00000000 */ 	nop
.L000351e4:
/*    351e4:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    351e8:	8f190008 */ 	lw	$t9,0x8($t8)
/*    351ec:	1320001d */ 	beqz	$t9,.L00035264
/*    351f0:	00000000 */ 	nop
/*    351f4:	24080015 */ 	addiu	$t0,$zero,0x15
/*    351f8:	a7a800a4 */ 	sh	$t0,0xa4($sp)
/*    351fc:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35200:	35490080 */ 	ori	$t1,$t2,0x80
/*    35204:	a3a900ac */ 	sb	$t1,0xac($sp)
/*    35208:	93ad00c2 */ 	lbu	$t5,0xc2($sp)
/*    3520c:	a3ad00ad */ 	sb	$t5,0xad($sp)
/*    35210:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    35214:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35218:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3521c:	8d8b0024 */ 	lw	$t3,0x24($t4)
/*    35220:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    35224:	016f0019 */ 	multu	$t3,$t7
/*    35228:	0000c012 */ 	mflo	$t8
/*    3522c:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*    35230:	00000000 */ 	nop
/*    35234:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35238:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*    3523c:	3c01800a */ 	lui	$at,%hi(var8009c350)
/*    35240:	00085080 */ 	sll	$t2,$t0,0x2
/*    35244:	002a0821 */ 	addu	$at,$at,$t2
/*    35248:	ac39c350 */ 	sw	$t9,%lo(var8009c350)($at)
/*    3524c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35250:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35254:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35258:	00003825 */ 	or	$a3,$zero,$zero
/*    3525c:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35260:	24840048 */ 	addiu	$a0,$a0,0x48
.L00035264:
/*    35264:	100007e6 */ 	b	.L00037200
/*    35268:	00000000 */ 	nop
.L0003526c:
/*    3526c:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35270:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35274:	000c7080 */ 	sll	$t6,$t4,0x2
/*    35278:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    3527c:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    35280:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35284:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    35288:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3528c:	01ae5821 */ 	addu	$t3,$t5,$t6
/*    35290:	afab0094 */ 	sw	$t3,0x94($sp)
/*    35294:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35298:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    3529c:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352a0:	0c00f5cb */ 	jal	__n_lookupSoundQuick
/*    352a4:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352a8:	afa20084 */ 	sw	$v0,0x84($sp)
/*    352ac:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    352b0:	15e00003 */ 	bnez	$t7,.L000352c0
/*    352b4:	00000000 */ 	nop
/*    352b8:	100007d3 */ 	b	.L00037208
/*    352bc:	00000000 */ 	nop
.L000352c0:
/*    352c0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    352c4:	93080008 */ 	lbu	$t0,0x8($t8)
/*    352c8:	a7a80088 */ 	sh	$t0,0x88($sp)
/*    352cc:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    352d0:	932a000b */ 	lbu	$t2,0xb($t9)
/*    352d4:	a7aa008a */ 	sh	$t2,0x8a($sp)
/*    352d8:	a3a0008c */ 	sb	$zero,0x8c($sp)
/*    352dc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    352e0:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    352e4:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352e8:	0c00f576 */ 	jal	__n_mapVoice
/*    352ec:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352f0:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    352f4:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    352f8:	15200003 */ 	bnez	$t1,.L00035308
/*    352fc:	00000000 */ 	nop
/*    35300:	100007c1 */ 	b	.L00037208
/*    35304:	00000000 */ 	nop
.L00035308:
/*    35308:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    3530c:	258d0004 */ 	addiu	$t5,$t4,0x4
/*    35310:	afad00cc */ 	sw	$t5,0xcc($sp)
/*    35314:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    35318:	0c00f278 */ 	jal	func0003c9e0
/*    3531c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*    35320:	8fae0084 */ 	lw	$t6,0x84($sp)
/*    35324:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35328:	ad6e0020 */ 	sw	$t6,0x20($t3)
/*    3532c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35330:	a1e00034 */ 	sb	$zero,0x34($t7)
/*    35334:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35338:	9308000c */ 	lbu	$t0,0xc($t8)
/*    3533c:	29010040 */ 	slti	$at,$t0,0x40
/*    35340:	14200005 */ 	bnez	$at,.L00035358
/*    35344:	00000000 */ 	nop
/*    35348:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    3534c:	24190002 */ 	addiu	$t9,$zero,0x2
/*    35350:	10000003 */ 	b	.L00035360
/*    35354:	a1590035 */ 	sb	$t9,0x35($t2)
.L00035358:
/*    35358:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    3535c:	a1200035 */ 	sb	$zero,0x35($t1)
.L00035360:
/*    35360:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35364:	93ac00c2 */ 	lbu	$t4,0xc2($sp)
/*    35368:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3536c:	91cb0004 */ 	lbu	$t3,0x4($t6)
/*    35370:	81c80005 */ 	lb	$t0,0x5($t6)
/*    35374:	018b7823 */ 	subu	$t7,$t4,$t3
/*    35378:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3537c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    35380:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    35384:	030fc021 */ 	addu	$t8,$t8,$t7
/*    35388:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3538c:	0308c821 */ 	addu	$t9,$t8,$t0
/*    35390:	a7b90082 */ 	sh	$t9,0x82($sp)
/*    35394:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35398:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3539c:	11200006 */ 	beqz	$t1,.L000353b8
/*    353a0:	00000000 */ 	nop
/*    353a4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    353a8:	87ad0082 */ 	lh	$t5,0x82($sp)
/*    353ac:	818b0027 */ 	lb	$t3,0x27($t4)
/*    353b0:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    353b4:	a7af0082 */ 	sh	$t7,0x82($sp)
.L000353b8:
/*    353b8:	0c00e7f8 */ 	jal	func00039fe0
/*    353bc:	87a40082 */ 	lh	$a0,0x82($sp)
/*    353c0:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    353c4:	e5c00028 */ 	swc1	$f0,0x28($t6)
/*    353c8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    353cc:	93080024 */ 	lbu	$t0,0x24($t8)
/*    353d0:	1100000d */ 	beqz	$t0,.L00035408
/*    353d4:	00000000 */ 	nop
/*    353d8:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    353dc:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    353e0:	932a0025 */ 	lbu	$t2,0x25($t9)
/*    353e4:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    353e8:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    353ec:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    353f0:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    353f4:	8d8d001c */ 	lw	$t5,0x1c($t4)
/*    353f8:	8d6f0018 */ 	lw	$t7,0x18($t3)
/*    353fc:	01af7021 */ 	addu	$t6,$t5,$t7
/*    35400:	1000000e */ 	b	.L0003543c
/*    35404:	af0e0024 */ 	sw	$t6,0x24($t8)
.L00035408:
/*    35408:	8fa80084 */ 	lw	$t0,0x84($sp)
/*    3540c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35410:	8d190000 */ 	lw	$t9,0x0($t0)
/*    35414:	932a000c */ 	lbu	$t2,0xc($t9)
/*    35418:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    3541c:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35420:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35424:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    35428:	8daf0000 */ 	lw	$t7,0x0($t5)
/*    3542c:	8d8b001c */ 	lw	$t3,0x1c($t4)
/*    35430:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35434:	016ec021 */ 	addu	$t8,$t3,$t6
/*    35438:	ad180024 */ 	sw	$t8,0x24($t0)
.L0003543c:
/*    3543c:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35440:	a3200037 */ 	sb	$zero,0x37($t9)
/*    35444:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35448:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3544c:	11200005 */ 	beqz	$t1,.L00035464
/*    35450:	00000000 */ 	nop
/*    35454:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35458:	918d0028 */ 	lbu	$t5,0x28($t4)
/*    3545c:	1000000f */ 	b	.L0003549c
/*    35460:	afad0090 */ 	sw	$t5,0x90($sp)
.L00035464:
/*    35464:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    35468:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    3546c:	000ec080 */ 	sll	$t8,$t6,0x2
/*    35470:	030ec023 */ 	subu	$t8,$t8,$t6
/*    35474:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    35478:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3547c:	030ec021 */ 	addu	$t8,$t8,$t6
/*    35480:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35484:	01784021 */ 	addu	$t0,$t3,$t8
/*    35488:	8d190000 */ 	lw	$t9,0x0($t0)
/*    3548c:	afb90068 */ 	sw	$t9,0x68($sp)
/*    35490:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    35494:	91490004 */ 	lbu	$t1,0x4($t2)
/*    35498:	afa90090 */ 	sw	$t1,0x90($sp)
.L0003549c:
/*    3549c:	3c0142fe */ 	lui	$at,0x42fe
/*    354a0:	44812000 */ 	mtc1	$at,$f4
/*    354a4:	00000000 */ 	nop
/*    354a8:	e7a40078 */ 	swc1	$f4,0x78($sp)
/*    354ac:	8fac0090 */ 	lw	$t4,0x90($sp)
/*    354b0:	11800041 */ 	beqz	$t4,.L000355b8
/*    354b4:	00000000 */ 	nop
/*    354b8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    354bc:	8daf0070 */ 	lw	$t7,0x70($t5)
/*    354c0:	11e0003d */ 	beqz	$t7,.L000355b8
/*    354c4:	00000000 */ 	nop
/*    354c8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    354cc:	91cb0024 */ 	lbu	$t3,0x24($t6)
/*    354d0:	11600012 */ 	beqz	$t3,.L0003551c
/*    354d4:	00000000 */ 	nop
/*    354d8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    354dc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    354e0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    354e4:	9308002a */ 	lbu	$t0,0x2a($t8)
/*    354e8:	93060028 */ 	lbu	$a2,0x28($t8)
/*    354ec:	93070029 */ 	lbu	$a3,0x29($t8)
/*    354f0:	afa80010 */ 	sw	$t0,0x10($sp)
/*    354f4:	9319002b */ 	lbu	$t9,0x2b($t8)
/*    354f8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    354fc:	afb90014 */ 	sw	$t9,0x14($sp)
/*    35500:	930a0031 */ 	lbu	$t2,0x31($t8)
/*    35504:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    35508:	8d390070 */ 	lw	$t9,0x70($t1)
/*    3550c:	0320f809 */ 	jalr	$t9
/*    35510:	00000000 */ 	nop
/*    35514:	10000012 */ 	b	.L00035560
/*    35518:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0003551c:
/*    3551c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35520:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35524:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35528:	918d0006 */ 	lbu	$t5,0x6($t4)
/*    3552c:	91860004 */ 	lbu	$a2,0x4($t4)
/*    35530:	91870005 */ 	lbu	$a3,0x5($t4)
/*    35534:	afad0010 */ 	sw	$t5,0x10($sp)
/*    35538:	918f0007 */ 	lbu	$t7,0x7($t4)
/*    3553c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35540:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35544:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    35548:	91cb0031 */ 	lbu	$t3,0x31($t6)
/*    3554c:	afab0018 */ 	sw	$t3,0x18($sp)
/*    35550:	8d190070 */ 	lw	$t9,0x70($t0)
/*    35554:	0320f809 */ 	jalr	$t9
/*    35558:	00000000 */ 	nop
/*    3555c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035560:
/*    35560:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*    35564:	13000014 */ 	beqz	$t8,.L000355b8
/*    35568:	00000000 */ 	nop
/*    3556c:	240a0016 */ 	addiu	$t2,$zero,0x16
/*    35570:	a7aa00a4 */ 	sh	$t2,0xa4($sp)
/*    35574:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35578:	afa900a8 */ 	sw	$t1,0xa8($sp)
/*    3557c:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    35580:	afad00ac */ 	sw	$t5,0xac($sp)
/*    35584:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35588:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3558c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35590:	00003825 */ 	or	$a3,$zero,$zero
/*    35594:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35598:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3559c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    355a0:	918f0037 */ 	lbu	$t7,0x37($t4)
/*    355a4:	35ee0001 */ 	ori	$t6,$t7,0x1
/*    355a8:	a18e0037 */ 	sb	$t6,0x37($t4)
/*    355ac:	8fab006c */ 	lw	$t3,0x6c($sp)
/*    355b0:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    355b4:	ad0b0038 */ 	sw	$t3,0x38($t0)
.L000355b8:
/*    355b8:	4459f800 */ 	cfc1	$t9,$31
/*    355bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355c0:	44d8f800 */ 	ctc1	$t8,$31
/*    355c4:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*    355c8:	46003224 */ 	cvt.w.s	$f8,$f6
/*    355cc:	4458f800 */ 	cfc1	$t8,$31
/*    355d0:	00000000 */ 	nop
/*    355d4:	33010004 */ 	andi	$at,$t8,0x4
/*    355d8:	33180078 */ 	andi	$t8,$t8,0x78
/*    355dc:	13000014 */ 	beqz	$t8,.L00035630
/*    355e0:	00000000 */ 	nop
/*    355e4:	3c014f00 */ 	lui	$at,0x4f00
/*    355e8:	44814000 */ 	mtc1	$at,$f8
/*    355ec:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355f0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*    355f4:	44d8f800 */ 	ctc1	$t8,$31
/*    355f8:	00000000 */ 	nop
/*    355fc:	46004224 */ 	cvt.w.s	$f8,$f8
/*    35600:	4458f800 */ 	cfc1	$t8,$31
/*    35604:	00000000 */ 	nop
/*    35608:	33010004 */ 	andi	$at,$t8,0x4
/*    3560c:	33180078 */ 	andi	$t8,$t8,0x78
/*    35610:	17000005 */ 	bnez	$t8,.L00035628
/*    35614:	00000000 */ 	nop
/*    35618:	44184000 */ 	mfc1	$t8,$f8
/*    3561c:	3c018000 */ 	lui	$at,0x8000
/*    35620:	10000007 */ 	b	.L00035640
/*    35624:	0301c025 */ 	or	$t8,$t8,$at
.L00035628:
/*    35628:	10000005 */ 	b	.L00035640
/*    3562c:	2418ffff */ 	addiu	$t8,$zero,-1
.L00035630:
/*    35630:	44184000 */ 	mfc1	$t8,$f8
/*    35634:	00000000 */ 	nop
/*    35638:	0700fffb */ 	bltz	$t8,.L00035628
/*    3563c:	00000000 */ 	nop
.L00035640:
/*    35640:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35644:	44d9f800 */ 	ctc1	$t9,$31
/*    35648:	a1580036 */ 	sb	$t8,0x36($t2)
/*    3564c:	00000000 */ 	nop
/*    35650:	3c013f80 */ 	lui	$at,0x3f80
/*    35654:	44815000 */ 	mtc1	$at,$f10
/*    35658:	00000000 */ 	nop
/*    3565c:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*    35660:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35664:	912d0024 */ 	lbu	$t5,0x24($t1)
/*    35668:	11a00005 */ 	beqz	$t5,.L00035680
/*    3566c:	00000000 */ 	nop
/*    35670:	8faf0094 */ 	lw	$t7,0x94($sp)
/*    35674:	91ee002c */ 	lbu	$t6,0x2c($t7)
/*    35678:	10000004 */ 	b	.L0003568c
/*    3567c:	afae0090 */ 	sw	$t6,0x90($sp)
.L00035680:
/*    35680:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35684:	918b0008 */ 	lbu	$t3,0x8($t4)
/*    35688:	afab0090 */ 	sw	$t3,0x90($sp)
.L0003568c:
/*    3568c:	8fa80090 */ 	lw	$t0,0x90($sp)
/*    35690:	11000043 */ 	beqz	$t0,.L000357a0
/*    35694:	00000000 */ 	nop
/*    35698:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3569c:	8f380070 */ 	lw	$t8,0x70($t9)
/*    356a0:	1300003f */ 	beqz	$t8,.L000357a0
/*    356a4:	00000000 */ 	nop
/*    356a8:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    356ac:	91490024 */ 	lbu	$t1,0x24($t2)
/*    356b0:	11200012 */ 	beqz	$t1,.L000356fc
/*    356b4:	00000000 */ 	nop
/*    356b8:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    356bc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    356c0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    356c4:	91af002e */ 	lbu	$t7,0x2e($t5)
/*    356c8:	91a6002c */ 	lbu	$a2,0x2c($t5)
/*    356cc:	91a7002d */ 	lbu	$a3,0x2d($t5)
/*    356d0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    356d4:	91ae002f */ 	lbu	$t6,0x2f($t5)
/*    356d8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    356dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*    356e0:	91ac0031 */ 	lbu	$t4,0x31($t5)
/*    356e4:	afac0018 */ 	sw	$t4,0x18($sp)
/*    356e8:	8d790070 */ 	lw	$t9,0x70($t3)
/*    356ec:	0320f809 */ 	jalr	$t9
/*    356f0:	00000000 */ 	nop
/*    356f4:	10000012 */ 	b	.L00035740
/*    356f8:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L000356fc:
/*    356fc:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    35700:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35704:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35708:	9118000a */ 	lbu	$t8,0xa($t0)
/*    3570c:	91060008 */ 	lbu	$a2,0x8($t0)
/*    35710:	91070009 */ 	lbu	$a3,0x9($t0)
/*    35714:	afb80010 */ 	sw	$t8,0x10($sp)
/*    35718:	910a000b */ 	lbu	$t2,0xb($t0)
/*    3571c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35720:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35724:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    35728:	912f0031 */ 	lbu	$t7,0x31($t1)
/*    3572c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    35730:	8dd90070 */ 	lw	$t9,0x70($t6)
/*    35734:	0320f809 */ 	jalr	$t9
/*    35738:	00000000 */ 	nop
/*    3573c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035740:
/*    35740:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    35744:	11a00016 */ 	beqz	$t5,.L000357a0
/*    35748:	00000000 */ 	nop
/*    3574c:	240c0017 */ 	addiu	$t4,$zero,0x17
/*    35750:	a7ac00a4 */ 	sh	$t4,0xa4($sp)
/*    35754:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35758:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*    3575c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*    35760:	afb800ac */ 	sw	$t8,0xac($sp)
/*    35764:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35768:	a3a800b0 */ 	sb	$t0,0xb0($sp)
/*    3576c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35770:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35774:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35778:	00003825 */ 	or	$a3,$zero,$zero
/*    3577c:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35780:	24840048 */ 	addiu	$a0,$a0,0x48
/*    35784:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35788:	91490037 */ 	lbu	$t1,0x37($t2)
/*    3578c:	352f0002 */ 	ori	$t7,$t1,0x2
/*    35790:	a14f0037 */ 	sb	$t7,0x37($t2)
/*    35794:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    35798:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    3579c:	af2e003c */ 	sw	$t6,0x3c($t9)
.L000357a0:
/*    357a0:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*    357a4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    357a8:	e5b0002c */ 	swc1	$f16,0x2c($t5)
/*    357ac:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    357b0:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    357b4:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    357b8:	c5640014 */ 	lwc1	$f4,0x14($t3)
/*    357bc:	c588002c */ 	lwc1	$f8,0x2c($t4)
/*    357c0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    357c4:	00000000 */ 	nop
/*    357c8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    357cc:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*    357d0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    357d4:	0c00f673 */ 	jal	func0003d9cc
/*    357d8:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    357dc:	a3a20077 */ 	sb	$v0,0x77($sp)
/*    357e0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    357e4:	93080011 */ 	lbu	$t0,0x11($t8)
/*    357e8:	a3a80076 */ 	sb	$t0,0x76($sp)
/*    357ec:	93a90076 */ 	lbu	$t1,0x76($sp)
/*    357f0:	11200012 */ 	beqz	$t1,.L0003583c
/*    357f4:	00000000 */ 	nop
/*    357f8:	87af0082 */ 	lh	$t7,0x82($sp)
/*    357fc:	24010064 */ 	addiu	$at,$zero,0x64
/*    35800:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35804:	01e1001a */ 	div	$zero,$t7,$at
/*    35808:	91d90012 */ 	lbu	$t9,0x12($t6)
/*    3580c:	00005012 */ 	mflo	$t2
/*    35810:	01592021 */ 	addu	$a0,$t2,$t9
/*    35814:	0c00ee75 */ 	jal	func0003b9d4
/*    35818:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    3581c:	3c0143dc */ 	lui	$at,0x43dc
/*    35820:	44818000 */ 	mtc1	$at,$f16
/*    35824:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    35828:	46100482 */ 	mul.s	$f18,$f0,$f16
/*    3582c:	c5a40014 */ 	lwc1	$f4,0x14($t5)
/*    35830:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    35834:	10000005 */ 	b	.L0003584c
/*    35838:	e7a60070 */ 	swc1	$f6,0x70($sp)
.L0003583c:
/*    3583c:	3c0142fe */ 	lui	$at,0x42fe
/*    35840:	44814000 */ 	mtc1	$at,$f8
/*    35844:	00000000 */ 	nop
/*    35848:	e7a80070 */ 	swc1	$f8,0x70($sp)
.L0003584c:
/*    3584c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35850:	0c00f6c5 */ 	jal	__vsPan
/*    35854:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35858:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    3585c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35860:	0c00f629 */ 	jal	__n_vsVol
/*    35864:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35868:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    3586c:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35870:	916c0024 */ 	lbu	$t4,0x24($t3)
/*    35874:	11800005 */ 	beqz	$t4,.L0003588c
/*    35878:	00000000 */ 	nop
/*    3587c:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35880:	8f080018 */ 	lw	$t0,0x18($t8)
/*    35884:	10000005 */ 	b	.L0003589c
/*    35888:	afa800a0 */ 	sw	$t0,0xa0($sp)
.L0003588c:
/*    3588c:	8fa90084 */ 	lw	$t1,0x84($sp)
/*    35890:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*    35894:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35898:	afae00a0 */ 	sw	$t6,0xa0($sp)
.L0003589c:
/*    3589c:	8faa0084 */ 	lw	$t2,0x84($sp)
/*    358a0:	93b9009b */ 	lbu	$t9,0x9b($sp)
/*    358a4:	93ad0077 */ 	lbu	$t5,0x77($sp)
/*    358a8:	8d450008 */ 	lw	$a1,0x8($t2)
/*    358ac:	93ab0076 */ 	lbu	$t3,0x76($sp)
/*    358b0:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*    358b4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    358b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*    358bc:	afad0014 */ 	sw	$t5,0x14($sp)
/*    358c0:	afab0018 */ 	sw	$t3,0x18($sp)
/*    358c4:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    358c8:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*    358cc:	91980013 */ 	lbu	$t8,0x13($t4)
/*    358d0:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    358d4:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*    358d8:	87a700b6 */ 	lh	$a3,0xb6($sp)
/*    358dc:	afa80024 */ 	sw	$t0,0x24($sp)
/*    358e0:	0c00f370 */ 	jal	func0003cdc0
/*    358e4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    358e8:	24090006 */ 	addiu	$t1,$zero,0x6
/*    358ec:	a7a900a4 */ 	sh	$t1,0xa4($sp)
/*    358f0:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    358f4:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*    358f8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    358fc:	91ca0024 */ 	lbu	$t2,0x24($t6)
/*    35900:	11400008 */ 	beqz	$t2,.L00035924
/*    35904:	00000000 */ 	nop
/*    35908:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    3590c:	932d0026 */ 	lbu	$t5,0x26($t9)
/*    35910:	a3ad00b0 */ 	sb	$t5,0xb0($sp)
/*    35914:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35918:	8d6c001c */ 	lw	$t4,0x1c($t3)
/*    3591c:	10000009 */ 	b	.L00035944
/*    35920:	afac00ac */ 	sw	$t4,0xac($sp)
.L00035924:
/*    35924:	8fb80084 */ 	lw	$t8,0x84($sp)
/*    35928:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3592c:	9109000d */ 	lbu	$t1,0xd($t0)
/*    35930:	a3a900b0 */ 	sb	$t1,0xb0($sp)
/*    35934:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    35938:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    3593c:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    35940:	afaa00ac */ 	sw	$t2,0xac($sp)
.L00035944:
/*    35944:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35948:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3594c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35950:	00003825 */ 	or	$a3,$zero,$zero
/*    35954:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    35958:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3595c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    35960:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*    35964:	11a0001d */ 	beqz	$t5,.L000359dc
/*    35968:	00000000 */ 	nop
/*    3596c:	240b0015 */ 	addiu	$t3,$zero,0x15
/*    35970:	a7ab00a4 */ 	sh	$t3,0xa4($sp)
/*    35974:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35978:	35980080 */ 	ori	$t8,$t4,0x80
/*    3597c:	a3b800ac */ 	sb	$t8,0xac($sp)
/*    35980:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    35984:	a3a800ad */ 	sb	$t0,0xad($sp)
/*    35988:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    3598c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35990:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    35994:	8d2f0024 */ 	lw	$t7,0x24($t1)
/*    35998:	8dca0008 */ 	lw	$t2,0x8($t6)
/*    3599c:	01ea0019 */ 	multu	$t7,$t2
/*    359a0:	0000c812 */ 	mflo	$t9
/*    359a4:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*    359a8:	00000000 */ 	nop
/*    359ac:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    359b0:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    359b4:	3c01800a */ 	lui	$at,%hi(var8009c350)
/*    359b8:	000b6080 */ 	sll	$t4,$t3,0x2
/*    359bc:	002c0821 */ 	addu	$at,$at,$t4
/*    359c0:	ac2dc350 */ 	sw	$t5,%lo(var8009c350)($at)
/*    359c4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    359c8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    359cc:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    359d0:	00003825 */ 	or	$a3,$zero,$zero
/*    359d4:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    359d8:	24840048 */ 	addiu	$a0,$a0,0x48
.L000359dc:
/*    359dc:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    359e0:	93080010 */ 	lbu	$t0,0x10($t8)
/*    359e4:	31090001 */ 	andi	$t1,$t0,0x1
/*    359e8:	11200014 */ 	beqz	$t1,.L00035a3c
/*    359ec:	00000000 */ 	nop
/*    359f0:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    359f4:	8dcf0084 */ 	lw	$t7,0x84($t6)
/*    359f8:	11e00010 */ 	beqz	$t7,.L00035a3c
/*    359fc:	00000000 */ 	nop
/*    35a00:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a04:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35a08:	3c0d800a */ 	lui	$t5,%hi(var8009c350)
/*    35a0c:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a10:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    35a14:	8dadc350 */ 	lw	$t5,%lo(var8009c350)($t5)
/*    35a18:	93080010 */ 	lbu	$t0,0x10($t8)
/*    35a1c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35a20:	2401ff00 */ 	addiu	$at,$zero,-256
/*    35a24:	01a16024 */ 	and	$t4,$t5,$at
/*    35a28:	00084883 */ 	sra	$t1,$t0,0x2
/*    35a2c:	01892825 */ 	or	$a1,$t4,$t1
/*    35a30:	00003025 */ 	or	$a2,$zero,$zero
/*    35a34:	0c012238 */ 	jal	osSendMesg
/*    35a38:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035a3c:
/*    35a3c:	100005f0 */ 	b	.L00037200
/*    35a40:	00000000 */ 	nop
.L00035a44:
/*    35a44:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35a48:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35a4c:	0c00f5a7 */ 	jal	__n_lookupVoice
/*    35a50:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35a54:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35a58:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35a5c:	15c00003 */ 	bnez	$t6,.L00035a6c
/*    35a60:	00000000 */ 	nop
/*    35a64:	100005e8 */ 	b	.L00037208
/*    35a68:	00000000 */ 	nop
.L00035a6c:
/*    35a6c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a70:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35a74:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a78:	01795823 */ 	subu	$t3,$t3,$t9
/*    35a7c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    35a80:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a84:	01795821 */ 	addu	$t3,$t3,$t9
/*    35a88:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a8c:	014b6821 */ 	addu	$t5,$t2,$t3
/*    35a90:	afad0094 */ 	sw	$t5,0x94($sp)
/*    35a94:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    35a98:	24010002 */ 	addiu	$at,$zero,0x2
/*    35a9c:	93080035 */ 	lbu	$t0,0x35($t8)
/*    35aa0:	15010005 */ 	bne	$t0,$at,.L00035ab8
/*    35aa4:	00000000 */ 	nop
/*    35aa8:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35aac:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    35ab0:	10000017 */ 	b	.L00035b10
/*    35ab4:	a12c0035 */ 	sb	$t4,0x35($t1)
.L00035ab8:
/*    35ab8:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35abc:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    35ac0:	a1ee0035 */ 	sb	$t6,0x35($t7)
/*    35ac4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    35ac8:	932a0024 */ 	lbu	$t2,0x24($t9)
/*    35acc:	11400009 */ 	beqz	$t2,.L00035af4
/*    35ad0:	00000000 */ 	nop
/*    35ad4:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*    35ad8:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35adc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35ae0:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    35ae4:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    35ae8:	8d660020 */ 	lw	$a2,0x20($t3)
/*    35aec:	10000008 */ 	b	.L00035b10
/*    35af0:	00000000 */ 	nop
.L00035af4:
/*    35af4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    35af8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35afc:	8db80020 */ 	lw	$t8,0x20($t5)
/*    35b00:	25a50004 */ 	addiu	$a1,$t5,0x4
/*    35b04:	8f080000 */ 	lw	$t0,0x0($t8)
/*    35b08:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    35b0c:	8d060008 */ 	lw	$a2,0x8($t0)
.L00035b10:
/*    35b10:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35b14:	91890010 */ 	lbu	$t1,0x10($t4)
/*    35b18:	312e0002 */ 	andi	$t6,$t1,0x2
/*    35b1c:	11c00010 */ 	beqz	$t6,.L00035b60
/*    35b20:	00000000 */ 	nop
/*    35b24:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35b28:	8df90084 */ 	lw	$t9,0x84($t7)
/*    35b2c:	1320000c */ 	beqz	$t9,.L00035b60
/*    35b30:	00000000 */ 	nop
/*    35b34:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    35b38:	93ab00c2 */ 	lbu	$t3,0xc2($sp)
/*    35b3c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35b40:	910c0010 */ 	lbu	$t4,0x10($t0)
/*    35b44:	000b6c00 */ 	sll	$t5,$t3,0x10
/*    35b48:	35b80008 */ 	ori	$t8,$t5,0x8
/*    35b4c:	000c4883 */ 	sra	$t1,$t4,0x2
/*    35b50:	03092825 */ 	or	$a1,$t8,$t1
/*    35b54:	00003025 */ 	or	$a2,$zero,$zero
/*    35b58:	0c012238 */ 	jal	osSendMesg
/*    35b5c:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035b60:
/*    35b60:	100005a7 */ 	b	.L00037200
/*    35b64:	00000000 */ 	nop
/*    35b68:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35b6c:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35b70:	0c00f5a7 */ 	jal	__n_lookupVoice
/*    35b74:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35b78:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35b7c:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35b80:	15c00003 */ 	bnez	$t6,.L00035b90
/*    35b84:	00000000 */ 	nop
/*    35b88:	1000059f */ 	b	.L00037208
/*    35b8c:	00000000 */ 	nop
.L00035b90:
/*    35b90:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    35b94:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35b98:	a32f0033 */ 	sb	$t7,0x33($t9)
/*    35b9c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35ba0:	0c00f629 */ 	jal	__n_vsVol
/*    35ba4:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35ba8:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35bac:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35bb0:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35bb4:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bb8:	0c00f6b4 */ 	jal	__n_vsDelta
/*    35bbc:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    35bc0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bc4:	00408025 */ 	or	$s0,$v0,$zero
/*    35bc8:	02003025 */ 	or	$a2,$s0,$zero
/*    35bcc:	02202825 */ 	or	$a1,$s1,$zero
/*    35bd0:	0c00f33c */ 	jal	n_alSynSetVol
/*    35bd4:	24840004 */ 	addiu	$a0,$a0,0x4
/*    35bd8:	10000589 */ 	b	.L00037200
/*    35bdc:	00000000 */ 	nop
/*    35be0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35be4:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    35be8:	11a0001c */ 	beqz	$t5,.L00035c5c
/*    35bec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00035bf0:
/*    35bf0:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    35bf4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35bf8:	910c0031 */ 	lbu	$t4,0x31($t0)
/*    35bfc:	15980013 */ 	bne	$t4,$t8,.L00035c4c
/*    35c00:	00000000 */ 	nop
/*    35c04:	93a900c0 */ 	lbu	$t1,0xc0($sp)
/*    35c08:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    35c0c:	a1c90033 */ 	sb	$t1,0x33($t6)
/*    35c10:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c14:	0c00f629 */ 	jal	__n_vsVol
/*    35c18:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35c1c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35c20:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35c24:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35c28:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c2c:	0c00f6b4 */ 	jal	__n_vsDelta
/*    35c30:	8de5001c */ 	lw	$a1,0x1c($t7)
/*    35c34:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c38:	00408025 */ 	or	$s0,$v0,$zero
/*    35c3c:	02003025 */ 	or	$a2,$s0,$zero
/*    35c40:	02202825 */ 	or	$a1,$s1,$zero
/*    35c44:	0c00f33c */ 	jal	n_alSynSetVol
/*    35c48:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035c4c:
/*    35c4c:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    35c50:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*    35c54:	1540ffe6 */ 	bnez	$t2,.L00035bf0
/*    35c58:	afaa00c8 */ 	sw	$t2,0xc8($sp)
.L00035c5c:
/*    35c5c:	10000568 */ 	b	.L00037200
/*    35c60:	00000000 */ 	nop
/*    35c64:	93b000c0 */ 	lbu	$s0,0xc0($sp)
/*    35c68:	2a01005d */ 	slti	$at,$s0,0x5d
/*    35c6c:	1420000f */ 	bnez	$at,.L00035cac
/*    35c70:	00000000 */ 	nop
/*    35c74:	240100fc */ 	addiu	$at,$zero,0xfc
/*    35c78:	1201012d */ 	beq	$s0,$at,.L00036130
/*    35c7c:	00000000 */ 	nop
/*    35c80:	240100fd */ 	addiu	$at,$zero,0xfd
/*    35c84:	12010050 */ 	beq	$s0,$at,.L00035dc8
/*    35c88:	00000000 */ 	nop
/*    35c8c:	240100fe */ 	addiu	$at,$zero,0xfe
/*    35c90:	120100ab */ 	beq	$s0,$at,.L00035f40
/*    35c94:	00000000 */ 	nop
/*    35c98:	240100ff */ 	addiu	$at,$zero,0xff
/*    35c9c:	12010057 */ 	beq	$s0,$at,.L00035dfc
/*    35ca0:	00000000 */ 	nop
/*    35ca4:	100004bf */ 	b	.L00036fa4
/*    35ca8:	00000000 */ 	nop
.L00035cac:
/*    35cac:	2a010042 */ 	slti	$at,$s0,0x42
/*    35cb0:	14200009 */ 	bnez	$at,.L00035cd8
/*    35cb4:	00000000 */ 	nop
/*    35cb8:	2401005b */ 	addiu	$at,$zero,0x5b
/*    35cbc:	12010244 */ 	beq	$s0,$at,.L000365d0
/*    35cc0:	00000000 */ 	nop
/*    35cc4:	2401005c */ 	addiu	$at,$zero,0x5c
/*    35cc8:	12010286 */ 	beq	$s0,$at,.L000366e4
/*    35ccc:	00000000 */ 	nop
/*    35cd0:	100004b4 */ 	b	.L00036fa4
/*    35cd4:	00000000 */ 	nop
.L00035cd8:
/*    35cd8:	2a010041 */ 	slti	$at,$s0,0x41
/*    35cdc:	14200006 */ 	bnez	$at,.L00035cf8
/*    35ce0:	00000000 */ 	nop
/*    35ce4:	24010041 */ 	addiu	$at,$zero,0x41
/*    35ce8:	12010253 */ 	beq	$s0,$at,.L00036638
/*    35cec:	00000000 */ 	nop
/*    35cf0:	100004ac */ 	b	.L00036fa4
/*    35cf4:	00000000 */ 	nop
.L00035cf8:
/*    35cf8:	2a010024 */ 	slti	$at,$s0,0x24
/*    35cfc:	14200006 */ 	bnez	$at,.L00035d18
/*    35d00:	00000000 */ 	nop
/*    35d04:	24010040 */ 	addiu	$at,$zero,0x40
/*    35d08:	120101c0 */ 	beq	$s0,$at,.L0003640c
/*    35d0c:	00000000 */ 	nop
/*    35d10:	100004a4 */ 	b	.L00036fa4
/*    35d14:	00000000 */ 	nop
.L00035d18:
/*    35d18:	260bffff */ 	addiu	$t3,$s0,-1
/*    35d1c:	2d610023 */ 	sltiu	$at,$t3,0x23
/*    35d20:	102004a0 */ 	beqz	$at,.L00036fa4
/*    35d24:	00000000 */ 	nop
/*    35d28:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35d2c:	3c017005 */ 	lui	$at,%hi(var700549bc)
/*    35d30:	002b0821 */ 	addu	$at,$at,$t3
/*    35d34:	8c2b49bc */ 	lw	$t3,%lo(var700549bc)($at)
/*    35d38:	01600008 */ 	jr	$t3
/*    35d3c:	00000000 */ 	nop
/*    35d40:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35d44:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35d48:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    35d4c:	00184880 */ 	sll	$t1,$t8,0x2
/*    35d50:	01384823 */ 	subu	$t1,$t1,$t8
/*    35d54:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35d58:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d5c:	01384821 */ 	addu	$t1,$t1,$t8
/*    35d60:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d64:	01897021 */ 	addu	$t6,$t4,$t1
/*    35d68:	a1cd0007 */ 	sb	$t5,0x7($t6)
/*    35d6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35d70:	8df90064 */ 	lw	$t9,0x64($t7)
/*    35d74:	13200012 */ 	beqz	$t9,.L00035dc0
/*    35d78:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L00035d7c:
/*    35d7c:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    35d80:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35d84:	914b0031 */ 	lbu	$t3,0x31($t2)
/*    35d88:	15680009 */ 	bne	$t3,$t0,.L00035db0
/*    35d8c:	00000000 */ 	nop
/*    35d90:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35d94:	0c00f6c5 */ 	jal	__vsPan
/*    35d98:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35d9c:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    35da0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35da4:	93a5009b */ 	lbu	$a1,0x9b($sp)
/*    35da8:	0c00f3bc */ 	jal	func0003cef0
/*    35dac:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035db0:
/*    35db0:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    35db4:	8f0c0000 */ 	lw	$t4,0x0($t8)
/*    35db8:	1580fff0 */ 	bnez	$t4,.L00035d7c
/*    35dbc:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00035dc0:
/*    35dc0:	1000047a */ 	b	.L00036fac
/*    35dc4:	00000000 */ 	nop
.L00035dc8:
/*    35dc8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35dcc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35dd0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35dd4:	000fc880 */ 	sll	$t9,$t7,0x2
/*    35dd8:	032fc823 */ 	subu	$t9,$t9,$t7
/*    35ddc:	8dae0060 */ 	lw	$t6,0x60($t5)
/*    35de0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35de4:	032fc821 */ 	addu	$t9,$t9,$t7
/*    35de8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35dec:	01d95021 */ 	addu	$t2,$t6,$t9
/*    35df0:	a149000f */ 	sb	$t1,0xf($t2)
/*    35df4:	1000046d */ 	b	.L00036fac
/*    35df8:	00000000 */ 	nop
.L00035dfc:
/*    35dfc:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e00:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e04:	00186080 */ 	sll	$t4,$t8,0x2
/*    35e08:	01986023 */ 	subu	$t4,$t4,$t8
/*    35e0c:	8d680060 */ 	lw	$t0,0x60($t3)
/*    35e10:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e14:	01986021 */ 	addu	$t4,$t4,$t8
/*    35e18:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e1c:	010c6821 */ 	addu	$t5,$t0,$t4
/*    35e20:	91af000f */ 	lbu	$t7,0xf($t5)
/*    35e24:	15e0000c */ 	bnez	$t7,.L00035e58
/*    35e28:	00000000 */ 	nop
/*    35e2c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35e30:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35e34:	240e0090 */ 	addiu	$t6,$zero,0x90
/*    35e38:	000a5880 */ 	sll	$t3,$t2,0x2
/*    35e3c:	016a5823 */ 	subu	$t3,$t3,$t2
/*    35e40:	8f290060 */ 	lw	$t1,0x60($t9)
/*    35e44:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e48:	016a5821 */ 	addu	$t3,$t3,$t2
/*    35e4c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e50:	012bc021 */ 	addu	$t8,$t1,$t3
/*    35e54:	a30e000f */ 	sb	$t6,0xf($t8)
.L00035e58:
/*    35e58:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35e5c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35e60:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35e64:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35e68:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35e6c:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35e70:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e74:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35e78:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e7c:	018fc821 */ 	addu	$t9,$t4,$t7
/*    35e80:	932a000e */ 	lbu	$t2,0xe($t9)
/*    35e84:	11490029 */ 	beq	$t2,$t1,.L00035f2c
/*    35e88:	00000000 */ 	nop
/*    35e8c:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e90:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e94:	00184080 */ 	sll	$t0,$t8,0x2
/*    35e98:	01184023 */ 	subu	$t0,$t0,$t8
/*    35e9c:	8d6e0060 */ 	lw	$t6,0x60($t3)
/*    35ea0:	00084080 */ 	sll	$t0,$t0,0x2
/*    35ea4:	01184021 */ 	addu	$t0,$t0,$t8
/*    35ea8:	00084080 */ 	sll	$t0,$t0,0x2
/*    35eac:	01c86821 */ 	addu	$t5,$t6,$t0
/*    35eb0:	91ac000d */ 	lbu	$t4,0xd($t5)
/*    35eb4:	91af000e */ 	lbu	$t7,0xe($t5)
/*    35eb8:	158f000d */ 	bne	$t4,$t7,.L00035ef0
/*    35ebc:	00000000 */ 	nop
/*    35ec0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    35ec4:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35ec8:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    35ecc:	000bc080 */ 	sll	$t8,$t3,0x2
/*    35ed0:	030bc023 */ 	subu	$t8,$t8,$t3
/*    35ed4:	8d490060 */ 	lw	$t1,0x60($t2)
/*    35ed8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35edc:	030bc021 */ 	addu	$t8,$t8,$t3
/*    35ee0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35ee4:	01387021 */ 	addu	$t6,$t1,$t8
/*    35ee8:	1000000e */ 	b	.L00035f24
/*    35eec:	a1d9000e */ 	sb	$t9,0xe($t6)
.L00035ef0:
/*    35ef0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35ef4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35ef8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    35efc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    35f00:	014f5023 */ 	subu	$t2,$t2,$t7
/*    35f04:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    35f08:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f0c:	014f5021 */ 	addu	$t2,$t2,$t7
/*    35f10:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f14:	018a5821 */ 	addu	$t3,$t4,$t2
/*    35f18:	a168000e */ 	sb	$t0,0xe($t3)
/*    35f1c:	10000423 */ 	b	.L00036fac
/*    35f20:	00000000 */ 	nop
.L00035f24:
/*    35f24:	10000003 */ 	b	.L00035f34
/*    35f28:	00000000 */ 	nop
.L00035f2c:
/*    35f2c:	1000041f */ 	b	.L00036fac
/*    35f30:	00000000 */ 	nop
.L00035f34:
/*    35f34:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    35f38:	240900fe */ 	addiu	$t1,$zero,0xfe
/*    35f3c:	a3090005 */ 	sb	$t1,0x5($t8)
.L00035f40:
/*    35f40:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35f44:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35f48:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35f4c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35f50:	8f2e0060 */ 	lw	$t6,0x60($t9)
/*    35f54:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f58:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f60:	01cf6021 */ 	addu	$t4,$t6,$t7
/*    35f64:	918a000d */ 	lbu	$t2,0xd($t4)
/*    35f68:	a3aa0067 */ 	sb	$t2,0x67($sp)
/*    35f6c:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    35f70:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35f74:	0009c080 */ 	sll	$t8,$t1,0x2
/*    35f78:	0309c023 */ 	subu	$t8,$t8,$t1
/*    35f7c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    35f80:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f84:	0309c021 */ 	addu	$t8,$t8,$t1
/*    35f88:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f8c:	0178c821 */ 	addu	$t9,$t3,$t8
/*    35f90:	932d000e */ 	lbu	$t5,0xe($t9)
/*    35f94:	a3ad0066 */ 	sb	$t5,0x66($sp)
/*    35f98:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35f9c:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35fa0:	000c5080 */ 	sll	$t2,$t4,0x2
/*    35fa4:	014c5023 */ 	subu	$t2,$t2,$t4
/*    35fa8:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    35fac:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb0:	014c5021 */ 	addu	$t2,$t2,$t4
/*    35fb4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb8:	01ea4021 */ 	addu	$t0,$t7,$t2
/*    35fbc:	9109000f */ 	lbu	$t1,0xf($t0)
/*    35fc0:	a3a900c1 */ 	sb	$t1,0xc1($sp)
/*    35fc4:	93ab0066 */ 	lbu	$t3,0x66($sp)
/*    35fc8:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    35fcc:	0178c823 */ 	subu	$t9,$t3,$t8
/*    35fd0:	afb90060 */ 	sw	$t9,0x60($sp)
/*    35fd4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    35fd8:	19a00012 */ 	blez	$t5,.L00036024
/*    35fdc:	00000000 */ 	nop
/*    35fe0:	93ae00c1 */ 	lbu	$t6,0xc1($sp)
/*    35fe4:	31cc0080 */ 	andi	$t4,$t6,0x80
/*    35fe8:	11800005 */ 	beqz	$t4,.L00036000
/*    35fec:	00000000 */ 	nop
/*    35ff0:	93af00c1 */ 	lbu	$t7,0xc1($sp)
/*    35ff4:	31ea007f */ 	andi	$t2,$t7,0x7f
/*    35ff8:	000a4040 */ 	sll	$t0,$t2,0x1
/*    35ffc:	a3a800c1 */ 	sb	$t0,0xc1($sp)
.L00036000:
/*    36000:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    36004:	93ab00c1 */ 	lbu	$t3,0xc1($sp)
/*    36008:	0169082a */ 	slt	$at,$t3,$t1
/*    3600c:	10200003 */ 	beqz	$at,.L0003601c
/*    36010:	00000000 */ 	nop
/*    36014:	93b800c1 */ 	lbu	$t8,0xc1($sp)
/*    36018:	afb80060 */ 	sw	$t8,0x60($sp)
.L0003601c:
/*    3601c:	1000000d */ 	b	.L00036054
/*    36020:	00000000 */ 	nop
.L00036024:
/*    36024:	93b900c1 */ 	lbu	$t9,0xc1($sp)
/*    36028:	332d007f */ 	andi	$t5,$t9,0x7f
/*    3602c:	a3ad00c1 */ 	sb	$t5,0xc1($sp)
/*    36030:	93ac00c1 */ 	lbu	$t4,0xc1($sp)
/*    36034:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    36038:	000c7823 */ 	negu	$t7,$t4
/*    3603c:	01cf082a */ 	slt	$at,$t6,$t7
/*    36040:	10200004 */ 	beqz	$at,.L00036054
/*    36044:	00000000 */ 	nop
/*    36048:	93aa00c1 */ 	lbu	$t2,0xc1($sp)
/*    3604c:	000a4023 */ 	negu	$t0,$t2
/*    36050:	afa80060 */ 	sw	$t0,0x60($sp)
.L00036054:
/*    36054:	93a90067 */ 	lbu	$t1,0x67($sp)
/*    36058:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3605c:	012bc021 */ 	addu	$t8,$t1,$t3
/*    36060:	a3b80067 */ 	sb	$t8,0x67($sp)
/*    36064:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36068:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3606c:	93b90067 */ 	lbu	$t9,0x67($sp)
/*    36070:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36074:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36078:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3607c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36080:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36084:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36088:	018f5021 */ 	addu	$t2,$t4,$t7
/*    3608c:	a159000d */ 	sb	$t9,0xd($t2)
/*    36090:	93a80067 */ 	lbu	$t0,0x67($sp)
/*    36094:	93a90066 */ 	lbu	$t1,0x66($sp)
/*    36098:	1109000d */ 	beq	$t0,$t1,.L000360d0
/*    3609c:	00000000 */ 	nop
/*    360a0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    360a4:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*    360a8:	00003825 */ 	or	$a3,$zero,$zero
/*    360ac:	8d660024 */ 	lw	$a2,0x24($t3)
/*    360b0:	25640048 */ 	addiu	$a0,$t3,0x48
/*    360b4:	00c00821 */ 	addu	$at,$a2,$zero
/*    360b8:	00013080 */ 	sll	$a2,$at,0x2
/*    360bc:	00c13023 */ 	subu	$a2,$a2,$at
/*    360c0:	000630c0 */ 	sll	$a2,$a2,0x3
/*    360c4:	00c13021 */ 	addu	$a2,$a2,$at
/*    360c8:	0c00f184 */ 	jal	n_alEvtqPostEvent
/*    360cc:	00063080 */ 	sll	$a2,$a2,0x2
.L000360d0:
/*    360d0:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    360d4:	13000009 */ 	beqz	$t8,.L000360fc
/*    360d8:	00000000 */ 	nop
/*    360dc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    360e0:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    360e4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    360e8:	95ae0030 */ 	lhu	$t6,0x30($t5)
/*    360ec:	018fc804 */ 	sllv	$t9,$t7,$t4
/*    360f0:	01d95025 */ 	or	$t2,$t6,$t9
/*    360f4:	10000009 */ 	b	.L0003611c
/*    360f8:	a5aa0030 */ 	sh	$t2,0x30($t5)
.L000360fc:
/*    360fc:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36100:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36104:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36108:	95090030 */ 	lhu	$t1,0x30($t0)
/*    3610c:	01787804 */ 	sllv	$t7,$t8,$t3
/*    36110:	01e06027 */ 	nor	$t4,$t7,$zero
/*    36114:	012c7024 */ 	and	$t6,$t1,$t4
/*    36118:	a50e0030 */ 	sh	$t6,0x30($t0)
.L0003611c:
/*    3611c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36120:	0c00d3c3 */ 	jal	func00034f0c
/*    36124:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36128:	100003a0 */ 	b	.L00036fac
/*    3612c:	00000000 */ 	nop
.L00036130:
/*    36130:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36134:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36138:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    3613c:	00185880 */ 	sll	$t3,$t8,0x2
/*    36140:	01785823 */ 	subu	$t3,$t3,$t8
/*    36144:	8d4d0060 */ 	lw	$t5,0x60($t2)
/*    36148:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3614c:	01785821 */ 	addu	$t3,$t3,$t8
/*    36150:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36154:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    36158:	a1f9000d */ 	sb	$t9,0xd($t7)
/*    3615c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36160:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36164:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36168:	00085080 */ 	sll	$t2,$t0,0x2
/*    3616c:	01485023 */ 	subu	$t2,$t2,$t0
/*    36170:	8d8e0060 */ 	lw	$t6,0x60($t4)
/*    36174:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36178:	01485021 */ 	addu	$t2,$t2,$t0
/*    3617c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36180:	01cac021 */ 	addu	$t8,$t6,$t2
/*    36184:	a309000e */ 	sb	$t1,0xe($t8)
/*    36188:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    3618c:	15a0000a */ 	bnez	$t5,.L000361b8
/*    36190:	00000000 */ 	nop
/*    36194:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36198:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3619c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361a0:	95790030 */ 	lhu	$t9,0x30($t3)
/*    361a4:	01ec4004 */ 	sllv	$t0,$t4,$t7
/*    361a8:	390effff */ 	xori	$t6,$t0,0xffff
/*    361ac:	032e5024 */ 	and	$t2,$t9,$t6
/*    361b0:	10000008 */ 	b	.L000361d4
/*    361b4:	a56a0030 */ 	sh	$t2,0x30($t3)
.L000361b8:
/*    361b8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    361bc:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    361c0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361c4:	95380030 */ 	lhu	$t8,0x30($t1)
/*    361c8:	01ac7804 */ 	sllv	$t7,$t4,$t5
/*    361cc:	030f4025 */ 	or	$t0,$t8,$t7
/*    361d0:	a5280030 */ 	sh	$t0,0x30($t1)
.L000361d4:
/*    361d4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    361d8:	0c00d3c3 */ 	jal	func00034f0c
/*    361dc:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    361e0:	10000372 */ 	b	.L00036fac
/*    361e4:	00000000 */ 	nop
/*    361e8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    361ec:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    361f0:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    361f4:	000b6080 */ 	sll	$t4,$t3,0x2
/*    361f8:	018b6023 */ 	subu	$t4,$t4,$t3
/*    361fc:	8dca0060 */ 	lw	$t2,0x60($t6)
/*    36200:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36204:	018b6021 */ 	addu	$t4,$t4,$t3
/*    36208:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3620c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    36210:	a1b90011 */ 	sb	$t9,0x11($t5)
/*    36214:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36218:	0c00d3ee */ 	jal	func00034fb8
/*    3621c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36220:	10000362 */ 	b	.L00036fac
/*    36224:	00000000 */ 	nop
/*    36228:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3622c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36230:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36234:	00097080 */ 	sll	$t6,$t1,0x2
/*    36238:	01c97023 */ 	subu	$t6,$t6,$t1
/*    3623c:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36240:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36244:	01c97021 */ 	addu	$t6,$t6,$t1
/*    36248:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3624c:	010e5821 */ 	addu	$t3,$t0,$t6
/*    36250:	a1780012 */ 	sb	$t8,0x12($t3)
/*    36254:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36258:	0c00d3ee */ 	jal	func00034fb8
/*    3625c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36260:	10000352 */ 	b	.L00036fac
/*    36264:	00000000 */ 	nop
/*    36268:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    3626c:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36270:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36274:	000d7880 */ 	sll	$t7,$t5,0x2
/*    36278:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    3627c:	8d990060 */ 	lw	$t9,0x60($t4)
/*    36280:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36284:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    36288:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3628c:	032f4821 */ 	addu	$t1,$t9,$t7
/*    36290:	a12a0013 */ 	sb	$t2,0x13($t1)
/*    36294:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36298:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*    3629c:	11c0000e */ 	beqz	$t6,.L000362d8
/*    362a0:	afae00c8 */ 	sw	$t6,0xc8($sp)
.L000362a4:
/*    362a4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    362a8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    362ac:	930b0031 */ 	lbu	$t3,0x31($t8)
/*    362b0:	156c0005 */ 	bne	$t3,$t4,.L000362c8
/*    362b4:	00000000 */ 	nop
/*    362b8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    362bc:	93a500bf */ 	lbu	$a1,0xbf($sp)
/*    362c0:	0c00f9cc */ 	jal	func0003e730
/*    362c4:	24840004 */ 	addiu	$a0,$a0,0x4
.L000362c8:
/*    362c8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*    362cc:	8db90000 */ 	lw	$t9,0x0($t5)
/*    362d0:	1720fff4 */ 	bnez	$t9,.L000362a4
/*    362d4:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000362d8:
/*    362d8:	10000334 */ 	b	.L00036fac
/*    362dc:	00000000 */ 	nop
/*    362e0:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    362e4:	8dea0084 */ 	lw	$t2,0x84($t7)
/*    362e8:	1140000d */ 	beqz	$t2,.L00036320
/*    362ec:	00000000 */ 	nop
/*    362f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    362f4:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    362f8:	2401ff00 */ 	addiu	$at,$zero,-256
/*    362fc:	8d2b0010 */ 	lw	$t3,0x10($t1)
/*    36300:	310e0007 */ 	andi	$t6,$t0,0x7
/*    36304:	35d80010 */ 	ori	$t8,$t6,0x10
/*    36308:	000b6140 */ 	sll	$t4,$t3,0x5
/*    3630c:	01816824 */ 	and	$t5,$t4,$at
/*    36310:	030d2825 */ 	or	$a1,$t8,$t5
/*    36314:	00003025 */ 	or	$a2,$zero,$zero
/*    36318:	0c012238 */ 	jal	osSendMesg
/*    3631c:	8d240084 */ 	lw	$a0,0x84($t1)
.L00036320:
/*    36320:	10000322 */ 	b	.L00036fac
/*    36324:	00000000 */ 	nop
/*    36328:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    3632c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36330:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36334:	00087080 */ 	sll	$t6,$t0,0x2
/*    36338:	01c87023 */ 	subu	$t6,$t6,$t0
/*    3633c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    36340:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36344:	01c87021 */ 	addu	$t6,$t6,$t0
/*    36348:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3634c:	014e4821 */ 	addu	$t1,$t2,$t6
/*    36350:	a1390009 */ 	sb	$t9,0x9($t1)
/*    36354:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36358:	8d6c0064 */ 	lw	$t4,0x64($t3)
/*    3635c:	1180001c */ 	beqz	$t4,.L000363d0
/*    36360:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036364:
/*    36364:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36368:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3636c:	930d0031 */ 	lbu	$t5,0x31($t8)
/*    36370:	15af0013 */ 	bne	$t5,$t7,.L000363c0
/*    36374:	00000000 */ 	nop
/*    36378:	93080034 */ 	lbu	$t0,0x34($t8)
/*    3637c:	24010003 */ 	addiu	$at,$zero,0x3
/*    36380:	1101000f */ 	beq	$t0,$at,.L000363c0
/*    36384:	00000000 */ 	nop
/*    36388:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    3638c:	0c00f629 */ 	jal	__n_vsVol
/*    36390:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    36394:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    36398:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    3639c:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363a0:	0c00f6b4 */ 	jal	__n_vsDelta
/*    363a4:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    363a8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363ac:	00408025 */ 	or	$s0,$v0,$zero
/*    363b0:	02003025 */ 	or	$a2,$s0,$zero
/*    363b4:	87a500b6 */ 	lh	$a1,0xb6($sp)
/*    363b8:	0c00f33c */ 	jal	n_alSynSetVol
/*    363bc:	24840004 */ 	addiu	$a0,$a0,0x4
.L000363c0:
/*    363c0:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    363c4:	8dd90000 */ 	lw	$t9,0x0($t6)
/*    363c8:	1720ffe6 */ 	bnez	$t9,.L00036364
/*    363cc:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000363d0:
/*    363d0:	100002f6 */ 	b	.L00036fac
/*    363d4:	00000000 */ 	nop
/*    363d8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    363dc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    363e0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    363e4:	000d7880 */ 	sll	$t7,$t5,0x2
/*    363e8:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    363ec:	8d6c0060 */ 	lw	$t4,0x60($t3)
/*    363f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363f4:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    363f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363fc:	018fc021 */ 	addu	$t8,$t4,$t7
/*    36400:	a3090008 */ 	sb	$t1,0x8($t8)
/*    36404:	100002e9 */ 	b	.L00036fac
/*    36408:	00000000 */ 	nop
.L0003640c:
/*    3640c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36410:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36414:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    36418:	00195880 */ 	sll	$t3,$t9,0x2
/*    3641c:	01795823 */ 	subu	$t3,$t3,$t9
/*    36420:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36424:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36428:	01795821 */ 	addu	$t3,$t3,$t9
/*    3642c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36430:	01cb6821 */ 	addu	$t5,$t6,$t3
/*    36434:	a1a8000c */ 	sb	$t0,0xc($t5)
/*    36438:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3643c:	8d8f0064 */ 	lw	$t7,0x64($t4)
/*    36440:	11e00061 */ 	beqz	$t7,.L000365c8
/*    36444:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L00036448:
/*    36448:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    3644c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36450:	91380031 */ 	lbu	$t8,0x31($t1)
/*    36454:	170a0058 */ 	bne	$t8,$t2,.L000365b8
/*    36458:	00000000 */ 	nop
/*    3645c:	91390035 */ 	lbu	$t9,0x35($t1)
/*    36460:	24010003 */ 	addiu	$at,$zero,0x3
/*    36464:	13210054 */ 	beq	$t9,$at,.L000365b8
/*    36468:	00000000 */ 	nop
/*    3646c:	93ae00bf */ 	lbu	$t6,0xbf($sp)
/*    36470:	29c10040 */ 	slti	$at,$t6,0x40
/*    36474:	1420000a */ 	bnez	$at,.L000364a0
/*    36478:	00000000 */ 	nop
/*    3647c:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36480:	91680035 */ 	lbu	$t0,0x35($t3)
/*    36484:	15000004 */ 	bnez	$t0,.L00036498
/*    36488:	00000000 */ 	nop
/*    3648c:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    36490:	240d0002 */ 	addiu	$t5,$zero,0x2
/*    36494:	a18d0035 */ 	sb	$t5,0x35($t4)
.L00036498:
/*    36498:	10000047 */ 	b	.L000365b8
/*    3649c:	00000000 */ 	nop
.L000364a0:
/*    364a0:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    364a4:	24010002 */ 	addiu	$at,$zero,0x2
/*    364a8:	91f80035 */ 	lbu	$t8,0x35($t7)
/*    364ac:	17010004 */ 	bne	$t8,$at,.L000364c0
/*    364b0:	00000000 */ 	nop
/*    364b4:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    364b8:	1000003f */ 	b	.L000365b8
/*    364bc:	a1400035 */ 	sb	$zero,0x35($t2)
.L000364c0:
/*    364c0:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    364c4:	24010004 */ 	addiu	$at,$zero,0x4
/*    364c8:	91390035 */ 	lbu	$t9,0x35($t1)
/*    364cc:	1721003a */ 	bne	$t9,$at,.L000365b8
/*    364d0:	00000000 */ 	nop
/*    364d4:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    364d8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    364dc:	a16e0035 */ 	sb	$t6,0x35($t3)
/*    364e0:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    364e4:	910d0024 */ 	lbu	$t5,0x24($t0)
/*    364e8:	11a00021 */ 	beqz	$t5,.L00036570
/*    364ec:	00000000 */ 	nop
/*    364f0:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    364f4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    364f8:	00185080 */ 	sll	$t2,$t8,0x2
/*    364fc:	01585023 */ 	subu	$t2,$t2,$t8
/*    36500:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    36504:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36508:	01585021 */ 	addu	$t2,$t2,$t8
/*    3650c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36510:	01ea4821 */ 	addu	$t1,$t7,$t2
/*    36514:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36518:	2b213e80 */ 	slti	$at,$t9,0x3e80
/*    3651c:	10200003 */ 	beqz	$at,.L0003652c
/*    36520:	00000000 */ 	nop
/*    36524:	1000000b */ 	b	.L00036554
/*    36528:	24103e80 */ 	addiu	$s0,$zero,0x3e80
.L0003652c:
/*    3652c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36530:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36534:	00086880 */ 	sll	$t5,$t0,0x2
/*    36538:	01a86823 */ 	subu	$t5,$t5,$t0
/*    3653c:	8dcb0060 */ 	lw	$t3,0x60($t6)
/*    36540:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36544:	01a86821 */ 	addu	$t5,$t5,$t0
/*    36548:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3654c:	016d6021 */ 	addu	$t4,$t3,$t5
/*    36550:	8d900020 */ 	lw	$s0,0x20($t4)
.L00036554:
/*    36554:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    36558:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    3655c:	02003025 */ 	or	$a2,$s0,$zero
/*    36560:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    36564:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    36568:	10000013 */ 	b	.L000365b8
/*    3656c:	00000000 */ 	nop
.L00036570:
/*    36570:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    36574:	8f0f0020 */ 	lw	$t7,0x20($t8)
/*    36578:	8dea0000 */ 	lw	$t2,0x0($t7)
/*    3657c:	8d490008 */ 	lw	$t1,0x8($t2)
/*    36580:	29213e80 */ 	slti	$at,$t1,0x3e80
/*    36584:	10200003 */ 	beqz	$at,.L00036594
/*    36588:	00000000 */ 	nop
/*    3658c:	10000005 */ 	b	.L000365a4
/*    36590:	24103e80 */ 	addiu	$s0,$zero,0x3e80
.L00036594:
/*    36594:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    36598:	8f2e0020 */ 	lw	$t6,0x20($t9)
/*    3659c:	8dc80000 */ 	lw	$t0,0x0($t6)
/*    365a0:	8d100008 */ 	lw	$s0,0x8($t0)
.L000365a4:
/*    365a4:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    365a8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    365ac:	02003025 */ 	or	$a2,$s0,$zero
/*    365b0:	0c00f4d0 */ 	jal	__n_seqpReleaseVoice
/*    365b4:	24a50004 */ 	addiu	$a1,$a1,0x4
.L000365b8:
/*    365b8:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    365bc:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    365c0:	15a0ffa1 */ 	bnez	$t5,.L00036448
/*    365c4:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000365c8:
/*    365c8:	10000278 */ 	b	.L00036fac
/*    365cc:	00000000 */ 	nop
.L000365d0:
/*    365d0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    365d4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    365d8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    365dc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    365e0:	014f5023 */ 	subu	$t2,$t2,$t7
/*    365e4:	8d980060 */ 	lw	$t8,0x60($t4)
/*    365e8:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365ec:	014f5021 */ 	addu	$t2,$t2,$t7
/*    365f0:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365f4:	030a4821 */ 	addu	$t1,$t8,$t2
/*    365f8:	9139000a */ 	lbu	$t9,0xa($t1)
/*    365fc:	332e0080 */ 	andi	$t6,$t9,0x80
/*    36600:	01c85825 */ 	or	$t3,$t6,$t0
/*    36604:	a12b000a */ 	sb	$t3,0xa($t1)
/*    36608:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3660c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36610:	000fc080 */ 	sll	$t8,$t7,0x2
/*    36614:	030fc023 */ 	subu	$t8,$t8,$t7
/*    36618:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3661c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36620:	030fc021 */ 	addu	$t8,$t8,$t7
/*    36624:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36628:	01985021 */ 	addu	$t2,$t4,$t8
/*    3662c:	9159000a */ 	lbu	$t9,0xa($t2)
/*    36630:	001971c3 */ 	sra	$t6,$t9,0x7
/*    36634:	a3ae00bf */ 	sb	$t6,0xbf($sp)
.L00036638:
/*    36638:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3663c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36640:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36644:	00096880 */ 	sll	$t5,$t1,0x2
/*    36648:	01a96823 */ 	subu	$t5,$t5,$t1
/*    3664c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    36650:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36654:	01a96821 */ 	addu	$t5,$t5,$t1
/*    36658:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3665c:	016d7821 */ 	addu	$t7,$t3,$t5
/*    36660:	91ec000a */ 	lbu	$t4,0xa($t7)
/*    36664:	000ac9c0 */ 	sll	$t9,$t2,0x7
/*    36668:	3198007f */ 	andi	$t8,$t4,0x7f
/*    3666c:	03197025 */ 	or	$t6,$t8,$t9
/*    36670:	a1ee000a */ 	sb	$t6,0xa($t7)
/*    36674:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36678:	8d090064 */ 	lw	$t1,0x64($t0)
/*    3667c:	11200017 */ 	beqz	$t1,.L000366dc
/*    36680:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L00036684:
/*    36684:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36688:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3668c:	916d0031 */ 	lbu	$t5,0x31($t3)
/*    36690:	15ac000e */ 	bne	$t5,$t4,.L000366cc
/*    36694:	00000000 */ 	nop
/*    36698:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    3669c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    366a0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    366a4:	00197080 */ 	sll	$t6,$t9,0x2
/*    366a8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    366ac:	8d580060 */ 	lw	$t8,0x60($t2)
/*    366b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366b4:	01d97021 */ 	addu	$t6,$t6,$t9
/*    366b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366bc:	030e7821 */ 	addu	$t7,$t8,$t6
/*    366c0:	91e5000a */ 	lbu	$a1,0xa($t7)
/*    366c4:	0c00f414 */ 	jal	n_alSynSetFXMix
/*    366c8:	24840004 */ 	addiu	$a0,$a0,0x4
.L000366cc:
/*    366cc:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    366d0:	8d090000 */ 	lw	$t1,0x0($t0)
/*    366d4:	1520ffeb */ 	bnez	$t1,.L00036684
/*    366d8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000366dc:
/*    366dc:	10000233 */ 	b	.L00036fac
/*    366e0:	00000000 */ 	nop
.L000366e4:
/*    366e4:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    366e8:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
/*    366ec:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    366f0:	8dac003c */ 	lw	$t4,0x3c($t5)
/*    366f4:	016c082a */ 	slt	$at,$t3,$t4
/*    366f8:	1020000c */ 	beqz	$at,.L0003672c
/*    366fc:	00000000 */ 	nop
/*    36700:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36704:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    36708:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    3670c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36710:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36714:	8f380060 */ 	lw	$t8,0x60($t9)
/*    36718:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3671c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36720:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36724:	030f4021 */ 	addu	$t0,$t8,$t7
/*    36728:	a10a000b */ 	sb	$t2,0xb($t0)
.L0003672c:
/*    3672c:	1000021f */ 	b	.L00036fac
/*    36730:	00000000 */ 	nop
/*    36734:	0c0040db */ 	jal	snd0001036c
/*    36738:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    3673c:	1000021b */ 	b	.L00036fac
/*    36740:	00000000 */ 	nop
/*    36744:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36748:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3674c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36750:	000cc880 */ 	sll	$t9,$t4,0x2
/*    36754:	032cc823 */ 	subu	$t9,$t9,$t4
/*    36758:	8dab0060 */ 	lw	$t3,0x60($t5)
/*    3675c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36760:	032cc821 */ 	addu	$t9,$t9,$t4
/*    36764:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36768:	01797021 */ 	addu	$t6,$t3,$t9
/*    3676c:	a1c90032 */ 	sb	$t1,0x32($t6)
/*    36770:	1000020e */ 	b	.L00036fac
/*    36774:	00000000 */ 	nop
/*    36778:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3677c:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36780:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36784:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36788:	3c0a8006 */ 	lui	$t2,%hi(var8005f150)
/*    3678c:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36790:	00187880 */ 	sll	$t7,$t8,0x2
/*    36794:	8d0d0060 */ 	lw	$t5,0x60($t0)
/*    36798:	014f5021 */ 	addu	$t2,$t2,$t7
/*    3679c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367a0:	8d4af150 */ 	lw	$t2,%lo(var8005f150)($t2)
/*    367a4:	016c5821 */ 	addu	$t3,$t3,$t4
/*    367a8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367ac:	01abc821 */ 	addu	$t9,$t5,$t3
/*    367b0:	af2a0018 */ 	sw	$t2,0x18($t9)
/*    367b4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    367b8:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    367bc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    367c0:	000f4080 */ 	sll	$t0,$t7,0x2
/*    367c4:	010f4023 */ 	subu	$t0,$t0,$t7
/*    367c8:	8dd80060 */ 	lw	$t8,0x60($t6)
/*    367cc:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d0:	010f4021 */ 	addu	$t0,$t0,$t7
/*    367d4:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d8:	03086021 */ 	addu	$t4,$t8,$t0
/*    367dc:	a1890024 */ 	sb	$t1,0x24($t4)
/*    367e0:	100001f2 */ 	b	.L00036fac
/*    367e4:	00000000 */ 	nop
/*    367e8:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    367ec:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    367f0:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    367f4:	00197080 */ 	sll	$t6,$t9,0x2
/*    367f8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    367fc:	8d6a0060 */ 	lw	$t2,0x60($t3)
/*    36800:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36804:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36808:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3680c:	014e7821 */ 	addu	$t7,$t2,$t6
/*    36810:	a1ed0025 */ 	sb	$t5,0x25($t7)
/*    36814:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36818:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    3681c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36820:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36824:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36828:	8d090060 */ 	lw	$t1,0x60($t0)
/*    3682c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36830:	016c5821 */ 	addu	$t3,$t3,$t4
/*    36834:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36838:	012bc821 */ 	addu	$t9,$t1,$t3
/*    3683c:	a3380024 */ 	sb	$t8,0x24($t9)
/*    36840:	100001da */ 	b	.L00036fac
/*    36844:	00000000 */ 	nop
/*    36848:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3684c:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36850:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36854:	000c4880 */ 	sll	$t1,$t4,0x2
/*    36858:	3c0d8006 */ 	lui	$t5,%hi(var8005f150)
/*    3685c:	012c4823 */ 	subu	$t1,$t1,$t4
/*    36860:	000a7080 */ 	sll	$t6,$t2,0x2
/*    36864:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36868:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    3686c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36870:	8dadf150 */ 	lw	$t5,%lo(var8005f150)($t5)
/*    36874:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36878:	00094880 */ 	sll	$t1,$t1,0x2
/*    3687c:	01095821 */ 	addu	$t3,$t0,$t1
/*    36880:	ad6d001c */ 	sw	$t5,0x1c($t3)
/*    36884:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36888:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3688c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36890:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36894:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36898:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*    3689c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    368a4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a8:	014f6021 */ 	addu	$t4,$t2,$t7
/*    368ac:	a1980024 */ 	sb	$t8,0x24($t4)
/*    368b0:	100001be */ 	b	.L00036fac
/*    368b4:	00000000 */ 	nop
/*    368b8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    368bc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    368c0:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    368c4:	000bc880 */ 	sll	$t9,$t3,0x2
/*    368c8:	032bc823 */ 	subu	$t9,$t9,$t3
/*    368cc:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    368d0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368d4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    368d8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368dc:	01b97021 */ 	addu	$t6,$t5,$t9
/*    368e0:	a1c80026 */ 	sb	$t0,0x26($t6)
/*    368e4:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    368e8:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    368ec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    368f0:	000c4880 */ 	sll	$t1,$t4,0x2
/*    368f4:	012c4823 */ 	subu	$t1,$t1,$t4
/*    368f8:	8df80060 */ 	lw	$t8,0x60($t7)
/*    368fc:	00094880 */ 	sll	$t1,$t1,0x2
/*    36900:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36904:	00094880 */ 	sll	$t1,$t1,0x2
/*    36908:	03095821 */ 	addu	$t3,$t8,$t1
/*    3690c:	a16a0024 */ 	sb	$t2,0x24($t3)
/*    36910:	100001a6 */ 	b	.L00036fac
/*    36914:	00000000 */ 	nop
/*    36918:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3691c:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    36920:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36924:	000cc080 */ 	sll	$t8,$t4,0x2
/*    36928:	3c088006 */ 	lui	$t0,%hi(var8005f150)
/*    3692c:	030cc023 */ 	subu	$t8,$t8,$t4
/*    36930:	000dc880 */ 	sll	$t9,$t5,0x2
/*    36934:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    36938:	01194021 */ 	addu	$t0,$t0,$t9
/*    3693c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36940:	8d08f150 */ 	lw	$t0,%lo(var8005f150)($t0)
/*    36944:	030cc021 */ 	addu	$t8,$t8,$t4
/*    36948:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3694c:	01f84821 */ 	addu	$t1,$t7,$t8
/*    36950:	ad280020 */ 	sw	$t0,0x20($t1)
/*    36954:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36958:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    3695c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    36960:	00197080 */ 	sll	$t6,$t9,0x2
/*    36964:	01d97023 */ 	subu	$t6,$t6,$t9
/*    36968:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    3696c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36970:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36974:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36978:	01ae6021 */ 	addu	$t4,$t5,$t6
/*    3697c:	a18a0024 */ 	sb	$t2,0x24($t4)
/*    36980:	1000018a */ 	b	.L00036fac
/*    36984:	00000000 */ 	nop
/*    36988:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    3698c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36990:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    36994:	000bc880 */ 	sll	$t9,$t3,0x2
/*    36998:	032bc823 */ 	subu	$t9,$t9,$t3
/*    3699c:	8d090060 */ 	lw	$t1,0x60($t0)
/*    369a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369a4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    369a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369ac:	25f8ffc0 */ 	addiu	$t8,$t7,-64
/*    369b0:	01396821 */ 	addu	$t5,$t1,$t9
/*    369b4:	a1b80027 */ 	sb	$t8,0x27($t5)
/*    369b8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    369bc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    369c0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    369c4:	000f4080 */ 	sll	$t0,$t7,0x2
/*    369c8:	010f4023 */ 	subu	$t0,$t0,$t7
/*    369cc:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    369d0:	00084080 */ 	sll	$t0,$t0,0x2
/*    369d4:	010f4021 */ 	addu	$t0,$t0,$t7
/*    369d8:	00084080 */ 	sll	$t0,$t0,0x2
/*    369dc:	01885821 */ 	addu	$t3,$t4,$t0
/*    369e0:	a16e0024 */ 	sb	$t6,0x24($t3)
/*    369e4:	10000171 */ 	b	.L00036fac
/*    369e8:	00000000 */ 	nop
/*    369ec:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    369f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    369f4:	24010064 */ 	addiu	$at,$zero,0x64
/*    369f8:	00186880 */ 	sll	$t5,$t8,0x2
/*    369fc:	01b86823 */ 	subu	$t5,$t5,$t8
/*    36a00:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36a04:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a08:	01b86821 */ 	addu	$t5,$t5,$t8
/*    36a0c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a10:	032d5021 */ 	addu	$t2,$t9,$t5
/*    36a14:	854f0004 */ 	lh	$t7,0x4($t2)
/*    36a18:	01e1001a */ 	div	$zero,$t7,$at
/*    36a1c:	00006012 */ 	mflo	$t4
/*    36a20:	a54c0004 */ 	sh	$t4,0x4($t2)
/*    36a24:	00000000 */ 	nop
/*    36a28:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36a2c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36a30:	000b4880 */ 	sll	$t1,$t3,0x2
/*    36a34:	012b4823 */ 	subu	$t1,$t1,$t3
/*    36a38:	8d0e0060 */ 	lw	$t6,0x60($t0)
/*    36a3c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a40:	012b4821 */ 	addu	$t1,$t1,$t3
/*    36a44:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a48:	01c9c021 */ 	addu	$t8,$t6,$t1
/*    36a4c:	87190004 */ 	lh	$t9,0x4($t8)
/*    36a50:	00196880 */ 	sll	$t5,$t9,0x2
/*    36a54:	01b96823 */ 	subu	$t5,$t5,$t9
/*    36a58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    36a5c:	01b96821 */ 	addu	$t5,$t5,$t9
/*    36a60:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a64:	a70d0004 */ 	sh	$t5,0x4($t8)
/*    36a68:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36a6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36a70:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36a74:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36a78:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36a7c:	8dec0060 */ 	lw	$t4,0x60($t7)
/*    36a80:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a84:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36a88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a8c:	01885821 */ 	addu	$t3,$t4,$t0
/*    36a90:	856e0004 */ 	lh	$t6,0x4($t3)
/*    36a94:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36a98:	a5790004 */ 	sh	$t9,0x4($t3)
/*    36a9c:	10000143 */ 	b	.L00036fac
/*    36aa0:	00000000 */ 	nop
/*    36aa4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36aa8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36aac:	24010064 */ 	addiu	$at,$zero,0x64
/*    36ab0:	000f5080 */ 	sll	$t2,$t7,0x2
/*    36ab4:	014f5023 */ 	subu	$t2,$t2,$t7
/*    36ab8:	8db80060 */ 	lw	$t8,0x60($t5)
/*    36abc:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac0:	014f5021 */ 	addu	$t2,$t2,$t7
/*    36ac4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac8:	030a6021 */ 	addu	$t4,$t8,$t2
/*    36acc:	85880004 */ 	lh	$t0,0x4($t4)
/*    36ad0:	0101001a */ 	div	$zero,$t0,$at
/*    36ad4:	00007010 */ 	mfhi	$t6
/*    36ad8:	a58e0004 */ 	sh	$t6,0x4($t4)
/*    36adc:	00000000 */ 	nop
/*    36ae0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36ae4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ae8:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36aec:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36af0:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36af4:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36af8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36afc:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b00:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b04:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36b08:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36b0c:	032d7821 */ 	addu	$t7,$t9,$t5
/*    36b10:	85f80004 */ 	lh	$t8,0x4($t7)
/*    36b14:	000840c0 */ 	sll	$t0,$t0,0x3
/*    36b18:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36b1c:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b20:	03087021 */ 	addu	$t6,$t8,$t0
/*    36b24:	a5ee0004 */ 	sh	$t6,0x4($t7)
/*    36b28:	10000120 */ 	b	.L00036fac
/*    36b2c:	00000000 */ 	nop
/*    36b30:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36b34:	11800004 */ 	beqz	$t4,.L00036b48
/*    36b38:	00000000 */ 	nop
/*    36b3c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36b40:	252b0080 */ 	addiu	$t3,$t1,0x80
/*    36b44:	a3ab00bf */ 	sb	$t3,0xbf($sp)
.L00036b48:
/*    36b48:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36b4c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36b50:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36b54:	00184080 */ 	sll	$t0,$t8,0x2
/*    36b58:	01184023 */ 	subu	$t0,$t0,$t8
/*    36b5c:	8daa0060 */ 	lw	$t2,0x60($t5)
/*    36b60:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b64:	01184021 */ 	addu	$t0,$t0,$t8
/*    36b68:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b6c:	01487021 */ 	addu	$t6,$t2,$t0
/*    36b70:	a1d9002c */ 	sb	$t9,0x2c($t6)
/*    36b74:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36b78:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36b7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    36b80:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36b84:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36b88:	8d890060 */ 	lw	$t1,0x60($t4)
/*    36b8c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b90:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b94:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b98:	012dc021 */ 	addu	$t8,$t1,$t5
/*    36b9c:	a30f0024 */ 	sb	$t7,0x24($t8)
/*    36ba0:	10000102 */ 	b	.L00036fac
/*    36ba4:	00000000 */ 	nop
/*    36ba8:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36bac:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36bb0:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36bb4:	000e6080 */ 	sll	$t4,$t6,0x2
/*    36bb8:	018e6023 */ 	subu	$t4,$t4,$t6
/*    36bbc:	8d190060 */ 	lw	$t9,0x60($t0)
/*    36bc0:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bc4:	018e6021 */ 	addu	$t4,$t4,$t6
/*    36bc8:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bcc:	032c5821 */ 	addu	$t3,$t9,$t4
/*    36bd0:	a16a002d */ 	sb	$t2,0x2d($t3)
/*    36bd4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36bd8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36bdc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    36be0:	00184080 */ 	sll	$t0,$t8,0x2
/*    36be4:	01184023 */ 	subu	$t0,$t0,$t8
/*    36be8:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    36bec:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf0:	01184021 */ 	addu	$t0,$t0,$t8
/*    36bf4:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf8:	01e87021 */ 	addu	$t6,$t7,$t0
/*    36bfc:	a1c90024 */ 	sb	$t1,0x24($t6)
/*    36c00:	100000ea */ 	b	.L00036fac
/*    36c04:	00000000 */ 	nop
/*    36c08:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c0c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36c10:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36c14:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36c18:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36c1c:	8d4b0060 */ 	lw	$t3,0x60($t2)
/*    36c20:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c24:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36c28:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c2c:	00196040 */ 	sll	$t4,$t9,0x1
/*    36c30:	01787821 */ 	addu	$t7,$t3,$t8
/*    36c34:	a1ec002e */ 	sb	$t4,0x2e($t7)
/*    36c38:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36c3c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36c40:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36c44:	00195080 */ 	sll	$t2,$t9,0x2
/*    36c48:	01595023 */ 	subu	$t2,$t2,$t9
/*    36c4c:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36c50:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c54:	01595021 */ 	addu	$t2,$t2,$t9
/*    36c58:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c5c:	01ca6821 */ 	addu	$t5,$t6,$t2
/*    36c60:	a1a80024 */ 	sb	$t0,0x24($t5)
/*    36c64:	100000d1 */ 	b	.L00036fac
/*    36c68:	00000000 */ 	nop
/*    36c6c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36c70:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36c74:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36c78:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36c7c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36c80:	8f0c0060 */ 	lw	$t4,0x60($t8)
/*    36c84:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c88:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36c8c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c90:	0189c821 */ 	addu	$t9,$t4,$t1
/*    36c94:	a32b002f */ 	sb	$t3,0x2f($t9)
/*    36c98:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c9c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36ca0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36ca4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36ca8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36cac:	8d480060 */ 	lw	$t0,0x60($t2)
/*    36cb0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cb4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36cb8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cbc:	01187821 */ 	addu	$t7,$t0,$t8
/*    36cc0:	a1ee0024 */ 	sb	$t6,0x24($t7)
/*    36cc4:	100000b9 */ 	b	.L00036fac
/*    36cc8:	00000000 */ 	nop
/*    36ccc:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36cd0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36cd4:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36cd8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36cdc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36ce0:	8d2b0060 */ 	lw	$t3,0x60($t1)
/*    36ce4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ce8:	01595021 */ 	addu	$t2,$t2,$t9
/*    36cec:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36cf0:	016a6821 */ 	addu	$t5,$t3,$t2
/*    36cf4:	a1ac0028 */ 	sb	$t4,0x28($t5)
/*    36cf8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36cfc:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d00:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36d04:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d08:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36d0c:	8f0e0060 */ 	lw	$t6,0x60($t8)
/*    36d10:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d14:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36d18:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d1c:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36d20:	a3280024 */ 	sb	$t0,0x24($t9)
/*    36d24:	100000a1 */ 	b	.L00036fac
/*    36d28:	00000000 */ 	nop
/*    36d2c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36d30:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36d34:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36d38:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36d3c:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36d40:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    36d44:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d48:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36d4c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d50:	01987821 */ 	addu	$t7,$t4,$t8
/*    36d54:	a1eb0029 */ 	sb	$t3,0x29($t7)
/*    36d58:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36d5c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36d60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36d64:	00195080 */ 	sll	$t2,$t9,0x2
/*    36d68:	01595023 */ 	subu	$t2,$t2,$t9
/*    36d6c:	8d280060 */ 	lw	$t0,0x60($t1)
/*    36d70:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d74:	01595021 */ 	addu	$t2,$t2,$t9
/*    36d78:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d7c:	010a6821 */ 	addu	$t5,$t0,$t2
/*    36d80:	a1ae0024 */ 	sb	$t6,0x24($t5)
/*    36d84:	10000089 */ 	b	.L00036fac
/*    36d88:	00000000 */ 	nop
/*    36d8c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36d90:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d94:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36d98:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d9c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36da0:	8f0b0060 */ 	lw	$t3,0x60($t8)
/*    36da4:	00094880 */ 	sll	$t1,$t1,0x2
/*    36da8:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36dac:	00094880 */ 	sll	$t1,$t1,0x2
/*    36db0:	0169c821 */ 	addu	$t9,$t3,$t1
/*    36db4:	a32c002a */ 	sb	$t4,0x2a($t9)
/*    36db8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36dbc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36dc0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36dc4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36dc8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36dcc:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36dd0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36dd4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36dd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36ddc:	01d87821 */ 	addu	$t7,$t6,$t8
/*    36de0:	a1e80024 */ 	sb	$t0,0x24($t7)
/*    36de4:	10000071 */ 	b	.L00036fac
/*    36de8:	00000000 */ 	nop
/*    36dec:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36df0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36df4:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36df8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36dfc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36e00:	8d2c0060 */ 	lw	$t4,0x60($t1)
/*    36e04:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e08:	01595021 */ 	addu	$t2,$t2,$t9
/*    36e0c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e10:	018a6821 */ 	addu	$t5,$t4,$t2
/*    36e14:	a1ab002b */ 	sb	$t3,0x2b($t5)
/*    36e18:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36e1c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36e20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36e24:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36e28:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36e2c:	8f080060 */ 	lw	$t0,0x60($t8)
/*    36e30:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e34:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36e38:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e3c:	0109c821 */ 	addu	$t9,$t0,$t1
/*    36e40:	a32e0024 */ 	sb	$t6,0x24($t9)
/*    36e44:	10000059 */ 	b	.L00036fac
/*    36e48:	00000000 */ 	nop
/*    36e4c:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36e50:	000c5040 */ 	sll	$t2,$t4,0x1
/*    36e54:	a3aa00bf */ 	sb	$t2,0xbf($sp)
/*    36e58:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36e5c:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    36e60:	11a00041 */ 	beqz	$t5,.L00036f68
/*    36e64:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00036e68:
/*    36e68:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36e6c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36e70:	930f0031 */ 	lbu	$t7,0x31($t8)
/*    36e74:	15e80038 */ 	bne	$t7,$t0,.L00036f58
/*    36e78:	00000000 */ 	nop
/*    36e7c:	8f09003c */ 	lw	$t1,0x3c($t8)
/*    36e80:	11200035 */ 	beqz	$t1,.L00036f58
/*    36e84:	00000000 */ 	nop
/*    36e88:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    36e8c:	8dd9003c */ 	lw	$t9,0x3c($t6)
/*    36e90:	afb9005c */ 	sw	$t9,0x5c($sp)
/*    36e94:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    36e98:	2401ff7f */ 	addiu	$at,$zero,-129
/*    36e9c:	918a0004 */ 	lbu	$t2,0x4($t4)
/*    36ea0:	01415824 */ 	and	$t3,$t2,$at
/*    36ea4:	256dfffe */ 	addiu	$t5,$t3,-2
/*    36ea8:	2da1000c */ 	sltiu	$at,$t5,0xc
/*    36eac:	10200024 */ 	beqz	$at,.L00036f40
/*    36eb0:	00000000 */ 	nop
/*    36eb4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36eb8:	3c017005 */ 	lui	$at,%hi(var70054a48)
/*    36ebc:	002d0821 */ 	addu	$at,$at,$t5
/*    36ec0:	8c2d4a48 */ 	lw	$t5,%lo(var70054a48)($at)
/*    36ec4:	01a00008 */ 	jr	$t5
/*    36ec8:	00000000 */ 	nop
/*    36ecc:	0c00bf18 */ 	jal	func0002fc60
/*    36ed0:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ed4:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    36ed8:	46000407 */ 	neg.s	$f16,$f0
/*    36edc:	e5f00010 */ 	swc1	$f16,0x10($t7)
/*    36ee0:	0c00bf18 */ 	jal	func0002fc60
/*    36ee4:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ee8:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    36eec:	e500000c */ 	swc1	$f0,0xc($t0)
/*    36ef0:	10000019 */ 	b	.L00036f58
/*    36ef4:	00000000 */ 	nop
/*    36ef8:	0c00bf18 */ 	jal	func0002fc60
/*    36efc:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f00:	3c014000 */ 	lui	$at,0x4000
/*    36f04:	44819000 */ 	mtc1	$at,$f18
/*    36f08:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    36f0c:	46120103 */ 	div.s	$f4,$f0,$f18
/*    36f10:	e704000c */ 	swc1	$f4,0xc($t8)
/*    36f14:	10000010 */ 	b	.L00036f58
/*    36f18:	00000000 */ 	nop
/*    36f1c:	0c00bf18 */ 	jal	func0002fc60
/*    36f20:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f24:	3c014000 */ 	lui	$at,0x4000
/*    36f28:	44813000 */ 	mtc1	$at,$f6
/*    36f2c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    36f30:	46060202 */ 	mul.s	$f8,$f0,$f6
/*    36f34:	e528000c */ 	swc1	$f8,0xc($t1)
/*    36f38:	10000007 */ 	b	.L00036f58
/*    36f3c:	00000000 */ 	nop
.L00036f40:
/*    36f40:	0c00bf18 */ 	jal	func0002fc60
/*    36f44:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f48:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    36f4c:	e5c0000c */ 	swc1	$f0,0xc($t6)
/*    36f50:	10000001 */ 	b	.L00036f58
/*    36f54:	00000000 */ 	nop
.L00036f58:
/*    36f58:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    36f5c:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*    36f60:	1580ffc1 */ 	bnez	$t4,.L00036e68
/*    36f64:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036f68:
/*    36f68:	10000010 */ 	b	.L00036fac
/*    36f6c:	00000000 */ 	nop
/*    36f70:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36f74:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36f78:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36f7c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    36f80:	010f4023 */ 	subu	$t0,$t0,$t7
/*    36f84:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    36f88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f8c:	010f4021 */ 	addu	$t0,$t0,$t7
/*    36f90:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f94:	01a8c021 */ 	addu	$t8,$t5,$t0
/*    36f98:	a30a0031 */ 	sb	$t2,0x31($t8)
/*    36f9c:	10000003 */ 	b	.L00036fac
/*    36fa0:	00000000 */ 	nop
.L00036fa4:
/*    36fa4:	10000001 */ 	b	.L00036fac
/*    36fa8:	00000000 */ 	nop
.L00036fac:
/*    36fac:	10000094 */ 	b	.L00037200
/*    36fb0:	00000000 */ 	nop
/*    36fb4:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36fb8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36fbc:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    36fc0:	00196080 */ 	sll	$t4,$t9,0x2
/*    36fc4:	01996023 */ 	subu	$t4,$t4,$t9
/*    36fc8:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36fcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd0:	01996021 */ 	addu	$t4,$t4,$t9
/*    36fd4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*    36fdc:	916f0032 */ 	lbu	$t7,0x32($t3)
/*    36fe0:	000f69c0 */ 	sll	$t5,$t7,0x7
/*    36fe4:	01a85021 */ 	addu	$t2,$t5,$t0
/*    36fe8:	afaa0090 */ 	sw	$t2,0x90($sp)
/*    36fec:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ff0:	8fb80090 */ 	lw	$t8,0x90($sp)
/*    36ff4:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36ff8:	872e0000 */ 	lh	$t6,0x0($t9)
/*    36ffc:	030e082a */ 	slt	$at,$t8,$t6
/*    37000:	1020000e */ 	beqz	$at,.L0003703c
/*    37004:	00000000 */ 	nop
/*    37008:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3700c:	8faf0090 */ 	lw	$t7,0x90($sp)
/*    37010:	8d8b0020 */ 	lw	$t3,0x20($t4)
/*    37014:	000f6880 */ 	sll	$t5,$t7,0x2
/*    37018:	016d4021 */ 	addu	$t0,$t3,$t5
/*    3701c:	8d0a000c */ 	lw	$t2,0xc($t0)
/*    37020:	afaa0058 */ 	sw	$t2,0x58($sp)
/*    37024:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    37028:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    3702c:	0c00f7d9 */ 	jal	__n_setInstChanState
/*    37030:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    37034:	10000001 */ 	b	.L0003703c
/*    37038:	00000000 */ 	nop
.L0003703c:
/*    3703c:	10000070 */ 	b	.L00037200
/*    37040:	00000000 */ 	nop
/*    37044:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    37048:	93b800c0 */ 	lbu	$t8,0xc0($sp)
/*    3704c:	0009c9c0 */ 	sll	$t9,$t1,0x7
/*    37050:	03387021 */ 	addu	$t6,$t9,$t8
/*    37054:	25cce000 */ 	addiu	$t4,$t6,-8192
/*    37058:	afac0054 */ 	sw	$t4,0x54($sp)
/*    3705c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    37060:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    37064:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    37068:	000d4080 */ 	sll	$t0,$t5,0x2
/*    3706c:	010d4023 */ 	subu	$t0,$t0,$t5
/*    37070:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    37074:	00084080 */ 	sll	$t0,$t0,0x2
/*    37078:	010d4021 */ 	addu	$t0,$t0,$t5
/*    3707c:	00084080 */ 	sll	$t0,$t0,0x2
/*    37080:	01685021 */ 	addu	$t2,$t3,$t0
/*    37084:	85490004 */ 	lh	$t1,0x4($t2)
/*    37088:	01390019 */ 	multu	$t1,$t9
/*    3708c:	0000c012 */ 	mflo	$t8
/*    37090:	07010003 */ 	bgez	$t8,.L000370a0
/*    37094:	00187343 */ 	sra	$t6,$t8,0xd
/*    37098:	27011fff */ 	addiu	$at,$t8,0x1fff
/*    3709c:	00017343 */ 	sra	$t6,$at,0xd
.L000370a0:
/*    370a0:	afae004c */ 	sw	$t6,0x4c($sp)
/*    370a4:	0c00e7f8 */ 	jal	func00039fe0
/*    370a8:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*    370ac:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*    370b0:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    370b4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    370b8:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    370bc:	000d5880 */ 	sll	$t3,$t5,0x2
/*    370c0:	016d5823 */ 	subu	$t3,$t3,$t5
/*    370c4:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    370c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370cc:	016d5821 */ 	addu	$t3,$t3,$t5
/*    370d0:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370d4:	01eb4021 */ 	addu	$t0,$t7,$t3
/*    370d8:	e50a0014 */ 	swc1	$f10,0x14($t0)
/*    370dc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    370e0:	8d490064 */ 	lw	$t1,0x64($t2)
/*    370e4:	11200042 */ 	beqz	$t1,.L000371f0
/*    370e8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000370ec:
/*    370ec:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    370f0:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    370f4:	93380031 */ 	lbu	$t8,0x31($t9)
/*    370f8:	170e0039 */ 	bne	$t8,$t6,.L000371e0
/*    370fc:	00000000 */ 	nop
/*    37100:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    37104:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    37108:	c5900028 */ 	lwc1	$f16,0x28($t4)
/*    3710c:	c586002c */ 	lwc1	$f6,0x2c($t4)
/*    37110:	25840004 */ 	addiu	$a0,$t4,0x4
/*    37114:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    37118:	00000000 */ 	nop
/*    3711c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    37120:	44054000 */ 	mfc1	$a1,$f8
/*    37124:	0c00f3e8 */ 	jal	n_alSynSetPitch
/*    37128:	00000000 */ 	nop
/*    3712c:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    37130:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    37134:	000b4080 */ 	sll	$t0,$t3,0x2
/*    37138:	010b4023 */ 	subu	$t0,$t0,$t3
/*    3713c:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    37140:	00084080 */ 	sll	$t0,$t0,0x2
/*    37144:	010b4021 */ 	addu	$t0,$t0,$t3
/*    37148:	00084080 */ 	sll	$t0,$t0,0x2
/*    3714c:	01e85021 */ 	addu	$t2,$t7,$t0
/*    37150:	91490011 */ 	lbu	$t1,0x11($t2)
/*    37154:	11200022 */ 	beqz	$t1,.L000371e0
/*    37158:	00000000 */ 	nop
/*    3715c:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    37160:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    37164:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    37168:	8dea0020 */ 	lw	$t2,0x20($t7)
/*    3716c:	000e6080 */ 	sll	$t4,$t6,0x2
/*    37170:	018e6023 */ 	subu	$t4,$t4,$t6
/*    37174:	8f380060 */ 	lw	$t8,0x60($t9)
/*    37178:	8d490004 */ 	lw	$t1,0x4($t2)
/*    3717c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37180:	018e6021 */ 	addu	$t4,$t4,$t6
/*    37184:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37188:	91e80032 */ 	lbu	$t0,0x32($t7)
/*    3718c:	91390004 */ 	lbu	$t9,0x4($t1)
/*    37190:	030c6821 */ 	addu	$t5,$t8,$t4
/*    37194:	91ab0012 */ 	lbu	$t3,0x12($t5)
/*    37198:	01197023 */ 	subu	$t6,$t0,$t9
/*    3719c:	016e2021 */ 	addu	$a0,$t3,$t6
/*    371a0:	0c00ee75 */ 	jal	func0003b9d4
/*    371a4:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    371a8:	3c0143dc */ 	lui	$at,0x43dc
/*    371ac:	44815000 */ 	mtc1	$at,$f10
/*    371b0:	46000506 */ 	mov.s	$f20,$f0
/*    371b4:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    371b8:	460aa402 */ 	mul.s	$f16,$f20,$f10
/*    371bc:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    371c0:	c706002c */ 	lwc1	$f6,0x2c($t8)
/*    371c4:	27040004 */ 	addiu	$a0,$t8,0x4
/*    371c8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    371cc:	00000000 */ 	nop
/*    371d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    371d4:	44054000 */ 	mfc1	$a1,$f8
/*    371d8:	0c00f8f8 */ 	jal	func0003e3e0
/*    371dc:	00000000 */ 	nop
.L000371e0:
/*    371e0:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    371e4:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    371e8:	15a0ffc0 */ 	bnez	$t5,.L000370ec
/*    371ec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000371f0:
/*    371f0:	10000003 */ 	b	.L00037200
/*    371f4:	00000000 */ 	nop
.L000371f8:
/*    371f8:	10000001 */ 	b	.L00037200
/*    371fc:	00000000 */ 	nop
.L00037200:
/*    37200:	10000001 */ 	b	.L00037208
/*    37204:	00000000 */ 	nop
.L00037208:
/*    37208:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    3720c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*    37210:	8fb00034 */ 	lw	$s0,0x34($sp)
/*    37214:	8fb10038 */ 	lw	$s1,0x38($sp)
/*    37218:	03e00008 */ 	jr	$ra
/*    3721c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#endif

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
