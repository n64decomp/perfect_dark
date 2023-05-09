#include <os_internal.h>
#include <ultraerror.h>
#include <libaudio.h>
#include "n_sndp.h"
#include "lib/snd.h"
#include "lib/lib_317f0.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s16 *var8009c334;

struct sndstate *g_SndpAllocStatesHead = NULL;
struct sndstate *g_SndpAllocStatesTail = NULL;
struct sndstate *g_SndpFreeStatesHead = NULL;
N_ALSndPlayer *g_SndPlayer = &var8009c2d0;
s16 var8005f130 = 0;
s32 var8005f134 = 0;
s32 var8005f138 = 0;
void (*g_SndpAddRefCallback)(ALSound *) = NULL;
void (*g_SndpRemoveRefCallback)(ALSound *) = NULL;

static ALMicroTime _n_sndpVoiceHandler(void *node);
static void _n_handleEvent(N_ALSndpEvent *event);
void sndpSetAddRefCallback(void *fn);
void sndpSetRemoveRefCallback(void *fn);
static void sndpFreeState(struct sndstate *state);
static void func00033bc0(struct sndstate *state);
static void func00033090(struct sndstate *state);
static void func00033100(struct sndstate *state);
static void _removeEvents(ALEventQueue *evtq, N_ALSoundState *state, u16 typemask);
static u16 sndpCountStates(s16 *numfreeptr, s16 *numallocedptr);

void n_alSndpNew(ALSndpConfig *config)
{
	u32 i;
	void *ptr;
	N_ALEvent evt;

	// Init member variables
	g_SndPlayer->maxSounds = config->maxSounds;
	g_SndPlayer->target = NULL;
	g_SndPlayer->frameTime = AL_USEC_PER_FRAME;

	ptr = alHeapAlloc(config->heap, 1, config->maxStates * sizeof(struct sndstate));
	g_SndPlayer->sndState = ptr;

	// Init the event queue
	ptr = alHeapAlloc(config->heap, 1, config->maxEvents * 0x1c);
	n_alEvtqNew(&g_SndPlayer->evtq, ptr, config->maxEvents);

	g_SndpFreeStatesHead = g_SndPlayer->sndState;

	for (i = 1; i < config->maxStates; i++) {
		struct sndstate *sndstate = g_SndPlayer->sndState;
		alLink(&sndstate[i].node, &sndstate[i - 1].node);
	}

	sndpSetAddRefCallback(NULL);
	sndpSetRemoveRefCallback(NULL);

	var8009c334 = alHeapAlloc(config->heap, sizeof(s16), config->unk10);

	for (i = 0; i < config->unk10; i++) {
		var8009c334[i] = 0x7fff;
	}

	// Add ourselves to the driver
	g_SndPlayer->node.next = NULL;
	g_SndPlayer->node.handler = (ALVoiceHandler) _n_sndpVoiceHandler;
	g_SndPlayer->node.clientData = g_SndPlayer;

	n_alSynAddSndPlayer(&g_SndPlayer->node);

	// Start responding to API events
	evt.type = AL_SNDP_API_EVT;

	n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, g_SndPlayer->frameTime, 1);

	g_SndPlayer->nextDelta = n_alEvtqNextEvent(&g_SndPlayer->evtq, &g_SndPlayer->nextEvent);
}

static ALMicroTime _n_sndpVoiceHandler(void *node)
{
	N_ALSndPlayer *sndp = (N_ALSndPlayer *) node;
	N_ALSndpEvent evt;

	do {
		switch (sndp->nextEvent.type) {
		case (AL_SNDP_API_EVT):
			evt.common.type = AL_SNDP_API_EVT;
			n_alEvtqPostEvent(&sndp->evtq, (N_ALEvent *)&evt, sndp->frameTime, 1);
			break;

		default:
			_n_handleEvent((N_ALSndpEvent *)&sndp->nextEvent);
			break;
		}

		sndp->nextDelta = n_alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
	} while (sndp->nextDelta == 0);

	sndp->curTime += sndp->nextDelta;

	return sndp->nextDelta;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void _n_handleEvent(N_ALSndpEvent *event)
{
	ALVoiceConfig config;
	ALSound *sound;
	ALKeyMap *keymap;
	ALPan pan;
	N_ALSndpEvent sp94;
	N_ALSndpEvent sp84;
	ALMicroTime delta;
	s32 fxmix;
	s32 vol;
	s32 tmppan;
	s32 sp70;
	s32 isspecial;
	bool done = true;
	bool hasvoice = false;
	struct sndstate *state = NULL;
	struct sndstate *nextstate = NULL;
	s16 numfree;
	s16 numalloced;
	struct sndstate *iterstate;
	N_ALSndpEvent sp44;
	ALMicroTime sp40;

	do {
		if (nextstate != NULL) {
			sp84.common.state = (N_ALSoundState *)state;
			sp84.common.type = event->common.type;
			sp84.common.unk08 = event->common.unk08;
			event = &sp84;
		}

		state = (struct sndstate *)event->common.state;

		if (((u32)state & 0x80000000) == 0) {
			// empty
		}

		sound = state->sound;

		if (sound == NULL) {
			sndpCountStates(&numfree, &numalloced);
			return;
		}

		keymap = sound->keyMap;
		nextstate = (struct sndstate *)state->node.next;

		switch (event->common.type) {
		case AL_SNDP_PLAY_EVT:
			if (state->state != AL_STATE5 && state->state != AL_STATE4) {
				return;
			}

			config.fxBus = state->fxbus;
			config.priority = state->priority;
			config.unityPitch = 0;
			sp70 = var8005f130 >= g_SndPlayer->maxSounds;

			if (!sp70 || (state->flags & SNDSTATEFLAG_10)) {
				hasvoice = n_alSynAllocVoice(&state->voice, &config);
			}

			if (!hasvoice) {
				if (state->flags & (SNDSTATEFLAG_02 | SNDSTATEFLAG_10) || state->unk34 > 0) {
					state->state = AL_STATE4;
					state->unk34--;
					n_alEvtqPostEvent(&g_SndPlayer->evtq, &event->msg, 33333, 0);
				} else if (sp70) {
					iterstate = g_SndpAllocStatesTail;

					do {
						if ((iterstate->flags & (SNDSTATEFLAG_02 | SNDSTATEFLAG_10)) == 0
								&& (iterstate->flags & SNDSTATEFLAG_04)
								&& iterstate->state != AL_STATE3) {
							sp70 = 0;
							sp44.common.type = AL_SNDP_END_EVT;
							sp44.common.state = (N_ALSoundState *)iterstate;
							iterstate->state = AL_STATE3;

							n_alEvtqPostEvent(&g_SndPlayer->evtq, &sp44.msg, 1000, 0);
							n_alSynSetVol(&iterstate->voice, 0, 1000);
						}

						iterstate = (struct sndstate *)iterstate->node.prev;
					} while (sp70 && iterstate);

					if (sp70 == 0) {
						state->unk34 = 2;
						n_alEvtqPostEvent(&g_SndPlayer->evtq, &event->msg, 1001, 0);
					} else {
						func00033090(state);
					}
				} else {
					func00033090(state);
				}
				return;
			}

			delta = sound->envelope->attackTime / state->pitch / state->basepitch;

			if (state->flags & SNDSTATEFLAG_02) {
				state->unk48 = 0;
			} else {
				sp40 = sound->envelope->decayTime / state->pitch / state->basepitch;

				if (sp40 > 5500000) {
					sp40 = 5500000;
				}

				state->unk48 = 1000000 + sp40 + g_SndPlayer->curTime;

				if (state->unk48 < 0) {
					state->unk48 = 0;
				}
			}

			if (delta > 5500000) {
				func00033090(state);
				return;
			}

			state->flags |= SNDSTATEFLAG_04;
			state->envvol = sound->envelope->attackVolume;
			state->fxbus = config.fxBus;
			state->endtime = g_SndPlayer->curTime + delta;

			vol = MAX(0, (var8009c334[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);
			tmppan = state->pan + sound->samplePan - AL_PAN_CENTER;
			pan = MIN(MAX(tmppan, 0), 127);

			fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
			fxmix = MIN(127, MAX(0, fxmix));
			fxmix |= state->fxmix & 0x80;

			n_alSynStartVoiceParams(&state->voice, sound->wavetable, state->pitch * state->basepitch, vol, pan, fxmix, 0, 0, 0, delta);
			state->state = AL_PLAYING;
			var8005f130++;

			if ((state->flags & SNDSTATEFLAG_02) == 0) {
				if (delta == 0) {
					state->envvol =  sound->envelope->decayVolume;

					vol = MAX(0, (var8009c334[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);

					delta = sound->envelope->decayTime / state->basepitch / state->pitch;

					if (delta > 5500000) {
						func00033090(state);
						return;
					}

					state->endtime = g_SndPlayer->curTime + delta;

					n_alSynSetVol(&state->voice, vol, delta);

					sp94.common.type = AL_SNDP_STOP_EVT;
					sp94.common.state = (N_ALSoundState *)state;

					n_alEvtqPostEvent(&g_SndPlayer->evtq, &sp94.msg, delta, 0);

					if (state->flags & SNDSTATEFLAG_20) {
						func00033100(state);
					}
				} else {
					sp94.common.type = AL_SNDP_DECAY_EVT;
					sp94.common.state = (N_ALSoundState *)state;
					delta = sound->envelope->attackTime / state->pitch / state->basepitch;

					if (delta > 5500000) {
						func00033090(state);
						return;
					}

					n_alEvtqPostEvent(&g_SndPlayer->evtq, &sp94.msg, delta, 0);
				}
			}
			break;
		case AL_SNDP_STOP_EVT:
		case AL_SNDP_0400_EVT:
		case AL_SNDP_1000_EVT:
			if (event->common.type != AL_SNDP_1000_EVT || (state->flags & SNDSTATEFLAG_02)) {
				switch (state->state) {
				case AL_PLAYING:
					_removeEvents(&g_SndPlayer->evtq, (N_ALSoundState *)state, AL_SNDP_DECAY_EVT);
					delta = sound->envelope->releaseTime / state->basepitch / state->pitch;

					if (delta > 5500000) {
						func00033090(state);
						break;
					}

					n_alSynSetVol(&state->voice, 0, delta);

					if (delta) {
						sp94.common.type = AL_SNDP_END_EVT;
						sp94.common.state = (N_ALSoundState *)state;
						n_alEvtqPostEvent(&g_SndPlayer->evtq, &sp94.msg, delta, 0);
						state->state = AL_STOPPING;
					} else {
						func00033090(state);
					}
					break;
				case AL_STATE4:
				case AL_STATE5:
					func00033090(state);
					break;
				default:
					break;
				}

				if (event->common.type == AL_SNDP_STOP_EVT) {
					event->common.type = AL_SNDP_1000_EVT;
				}
			}
			break;
		case AL_SNDP_PAN_EVT:
			state->pan = event->common.unk08;

			if (state->state == AL_PLAYING) {
				tmppan = state->pan - AL_PAN_CENTER + sound->samplePan;
				pan = MIN(MAX(tmppan, 0), 127);

				n_alSynSetPan(&state->voice, pan);
			}
			break;
		case AL_SNDP_PITCH_EVT:
			state->pitch = event->pitch.pitch;

			if (state->state == AL_PLAYING) {
				n_alSynSetPitch(&state->voice, state->pitch * state->basepitch);

				if (state->flags & SNDSTATEFLAG_20) {
					func00033100(state);
				}
			}
			break;
		case AL_SNDP_FX_EVT:
			state->fxmix = event->common.unk08;

			if (state->state == AL_PLAYING) {
				fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
				fxmix = MIN(127, MAX(0, fxmix));
				fxmix |= state->fxmix & 0x80;

				n_alSynSetFXMix(&state->voice, fxmix);
			}
			break;
		case AL_SNDP_4000_EVT:
			state->fxmix = (u8)(state->fxmix & 0x7f) | (u8)(event->common.unk08 & 0x80);

			if (state->state == AL_PLAYING) {
				fxmix = (state->fxmix & 0x7f) + (keymap->keyMax & 0xf) * 8;
				fxmix = MIN(127, MAX(0, fxmix));
				fxmix |= state->fxmix & 0x80;

				n_alSynSetFXMix(&state->voice, fxmix);
			}
			break;
		case AL_SNDP_FXBUS_EVT:
			state->fxbus = event->common.unk08;

			if (state->fxbus >= n_syn->maxAuxBusses) {
				state->fxbus = 0;
			}

			if (state->state == AL_PLAYING) {
				state->voice.fxBus = state->fxbus;
			}
			break;
		case AL_SNDP_VOL_EVT:
			state->vol = event->common.unk08;

			if (state->state == AL_PLAYING) {
				vol = MAX(0, (var8009c334[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01)) / 0x7fff - 1);

				n_alSynSetVol(&state->voice, vol, MAX(1000, state->endtime - g_SndPlayer->curTime));
			}
			break;
		case AL_SNDP_0800_EVT:
			if (state->state == AL_PLAYING) {
				delta = sound->envelope->releaseTime / state->basepitch / state->pitch;

				if (delta > 5500000) {
					func00033090(state);
					break;
				}

				vol = MAX(0, var8009c334[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01) / 0x7fff - 1);

				n_alSynSetVol(&state->voice, vol, delta);
			}
			break;
		case AL_SNDP_DECAY_EVT:
			if ((state->flags & SNDSTATEFLAG_02) == 0) {
				state->envvol = sound->envelope->decayVolume;
				vol = MAX(0, var8009c334[keymap->keyMin & 0x1f] * (state->envvol * state->vol * sound->sampleVolume / 0x3f01) / 0x7fff - 1);
				delta = sound->envelope->decayTime / state->basepitch / state->pitch;

				if (delta > 5500000) {
					func00033090(state);
					break;
				}

				state->endtime = g_SndPlayer->curTime + delta;

				n_alSynSetVol(&state->voice, vol, delta);

				sp94.common.type = AL_SNDP_STOP_EVT;
				sp94.common.state = (N_ALSoundState *)state;

				n_alEvtqPostEvent(&g_SndPlayer->evtq, &sp94.msg, delta, 0);

				if (state->flags & SNDSTATEFLAG_20) {
					func00033100(state);
				}
			}
			break;
		case AL_SNDP_END_EVT:
			func00033090(state);
			break;
		case AL_SNDP_0200_EVT:
			if (state->flags & SNDSTATEFLAG_10) {
				func00033820(event->msg.msg.generic.data2, event->msg.msg.generic.data, state->vol, state->pan,
						state->pitch, state->fxmix, state->fxbus, state->unk30);
			}
			break;
		default:
			break;
		}

		isspecial = event->common.type & (AL_SNDP_PLAY_EVT
				| AL_SNDP_PITCH_EVT
				| AL_SNDP_DECAY_EVT
				| AL_SNDP_END_EVT
				| AL_SNDP_0200_EVT);

		if ((state = nextstate) && !isspecial) {
			done = state->flags & SNDSTATEFLAG_01;
		}
	} while (!done && state && !isspecial);
}

static void func00033090(struct sndstate *state)
{
	if (state->flags & SNDSTATEFLAG_04) {
		n_alSynStopVoice(&state->voice);
		n_alSynFreeVoice(&state->voice);
	}

	sndpFreeState(state);

	// @todo: Remove cast
	_removeEvents(&g_SndPlayer->evtq, (N_ALSoundState *)state, 0xffff);
}

static void func00033100(struct sndstate *state)
{
	N_ALSndpEvent evt;
	f32 pitch = alCents2Ratio(state->sound->keyMap->detune) * state->pitch;

	evt.common.type = AL_SNDP_PITCH_EVT;
	evt.common.state = (N_ALSoundState *)state;
	evt.common.unk08 = *(u32 *)&pitch;

	n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt.msg, 33333, 0);
}

static void _removeEvents(ALEventQueue *evtq, N_ALSoundState *state, u16 typemask)
{
	ALLink            *thisNode;
	ALLink            *nextNode;
	N_ALEventListItem *thisItem;
	N_ALEventListItem *nextItem;
	N_ALSndpEvent     *thisEvent;
	OSIntMask         mask;

	mask = osSetIntMask(OS_IM_NONE);

	thisNode = evtq->allocList.next;

	while (thisNode != 0) {
		nextNode = thisNode->next;
		thisItem = (N_ALEventListItem *)thisNode;
		nextItem = (N_ALEventListItem *)nextNode;
		thisEvent = (N_ALSndpEvent *) &thisItem->evt;

		if (thisEvent->common.state == state && thisEvent->common.type & typemask) {
			if (nextItem) {
				nextItem->delta += thisItem->delta;
			}

			alUnlink(thisNode);
			alLink(thisNode, &evtq->freeList);
		}

		thisNode = nextNode;
	}

	osSetIntMask(mask);
}

static u16 sndpCountStates(s16 *numfreeptr, s16 *numallocedptr)
{
	OSIntMask mask = osSetIntMask(1);
	u16 numalloced;
	u16 numfree;
	u16 numalloced2;
	struct sndstate *state1 = g_SndpAllocStatesHead;
	struct sndstate *state2 = g_SndpFreeStatesHead;
	struct sndstate *state3 = g_SndpAllocStatesTail;

	for (numalloced = 0; state1; numalloced++, state1 = (struct sndstate *)state1->node.next);
	for (numfree = 0; state2; numfree++, state2 = (struct sndstate *)state2->node.next);
	for (numalloced2 = 0; state3; numalloced2++, state3 = (struct sndstate *)state3->node.prev);

	*numfreeptr = numfree;
	*numallocedptr = numalloced;

	osSetIntMask(mask);

	return numalloced2;
}

void sndpSetAddRefCallback(void *fn)
{
	g_SndpAddRefCallback = fn;
}

static struct sndstate *func00033390(s32 arg0, ALSound *sound)
{
	struct sndstate *state;
	ALKeyMap *keymap;
	OSIntMask mask;
	s32 sp18;

	keymap = sound->keyMap;

	if (++var8005f134 > var8005f138) {
		var8005f138 = var8005f134;

		if (var8005f134 > 16) {
			// empty
		}
	}

	mask = osSetIntMask(1);
	state = g_SndpFreeStatesHead;

	if (state != NULL) {
		g_SndpFreeStatesHead = (struct sndstate *)state->node.next;

		alUnlink(&state->node);

		if (g_SndpAllocStatesHead) {
			state->node.next = &g_SndpAllocStatesHead->node;
			state->node.prev = NULL;
			g_SndpAllocStatesHead->node.prev = &state->node;
			g_SndpAllocStatesHead = state;
		} else {
			state->node.next = state->node.prev = NULL;
			g_SndpAllocStatesHead = state;
			g_SndpAllocStatesTail = state;
		}

		osSetIntMask(mask);

		sp18 = sound->envelope->decayTime + 1 == 0;

		state->sound = sound;
		state->priority = sp18 + 64;
		state->state = AL_STATE5;
		state->pitch = 1;
		state->unk34 = 2;
		state->flags = keymap->keyMax & 0xf0;
		state->unk30 = NULL;

		if (state->flags & SNDSTATEFLAG_20) {
			state->basepitch = alCents2Ratio(keymap->keyBase * 100 - 6000);
		} else {
			state->basepitch = alCents2Ratio(keymap->keyBase * 100 + keymap->detune - 6000);
		}

		if (sp18) {
			state->flags |= SNDSTATEFLAG_02;
		}

		state->fxmix = 0;
		state->pan = AL_PAN_CENTER;
		state->vol = 0x7fff;

		if (g_SndpAddRefCallback != NULL) {
			g_SndpAddRefCallback(state->sound);
		}
	} else {
		osSetIntMask(mask);
	}

	return state;
}

void sndpSetRemoveRefCallback(void *fn)
{
	g_SndpRemoveRefCallback = fn;
}

static void sndpFreeState(struct sndstate *state)
{
	var8005f134--;

	if (g_SndpAllocStatesHead == state) {
		g_SndpAllocStatesHead = (struct sndstate *)state->node.next;
	}

	if (g_SndpAllocStatesTail == state) {
		g_SndpAllocStatesTail = (struct sndstate *)state->node.prev;
	}

	alUnlink(&state->node);

	if (g_SndpFreeStatesHead) {
		state->node.next = &g_SndpFreeStatesHead->node;
		state->node.prev = NULL;
		g_SndpFreeStatesHead->node.prev = &state->node;
		g_SndpFreeStatesHead = state;
	} else {
		state->node.next = state->node.prev = NULL;
		g_SndpFreeStatesHead = state;
	}

	if (state->flags & SNDSTATEFLAG_04) {
		var8005f130--;
	}

	state->state = AL_STOPPED;

	if (state->unk30) {
		if (*state->unk30 == state) {
			*state->unk30 = 0;
		}

		state->unk30 = NULL;
	}

	if (g_SndpRemoveRefCallback != NULL) {
		g_SndpRemoveRefCallback(state->sound);
	}
}

s32 sndGetState(struct sndstate *state)
{
	if (state) {
		return state->state;
	} else {
		return false;
	}
}

struct sndstate *func00033820(s32 arg0, s16 soundnum, u16 vol, ALPan pan, f32 pitch, u8 fxmix, u8 fxbus, struct sndstate **handleptr)
{
	struct sndstate *state;
	struct sndstate *state2 = NULL;
	ALKeyMap *keymap;
	ALSound *sound;
	s16 sp4e = 0;
	s32 sp48;
	s32 sp44;
	s32 sp40 = 0;
	s32 abspan;
	N_ALEvent evt;
	N_ALEvent evt2;

	if (soundnum != 0) {
		do {
			sound = sndLoadSound(soundnum);
			state = func00033390(arg0, sound);

			if (state != NULL) {
				g_SndPlayer->target = state;
				evt.type = AL_SNDP_PLAY_EVT;
				evt.msg.generic.sndstate = state;
				abspan = pan + state->pan - AL_PAN_CENTER;

				if (abspan > 127) {
					abspan = 127;
				} else if (abspan < 0) {
					abspan = 0;
				}

				state->pan = abspan;
				state->vol = (u32)(vol * state->vol) >> 15;
				state->pitch *= pitch;
				state->fxmix = fxmix;
				state->fxbus = fxbus;
				state->soundnum = soundnum;
				state->unk48 = 0;

				sp44 = sound->keyMap->velocityMax * 33333;

				if (state->flags & SNDSTATEFLAG_10) {
					state->flags &= ~SNDSTATEFLAG_10;
					n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, sp40 + 1, 0);
					sp48 = sp44 + 1;
					sp4e = soundnum;
				} else {
					n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, sp44 + 1, 0);
				}

				state2 = state;
			}

			sp40 += sp44;
			keymap = sound->keyMap;
			soundnum = keymap->velocityMin + (keymap->keyMin & 0xc0) * 4;
		} while (soundnum && state);

		if (state2 != NULL) {
			state2->flags |= SNDSTATEFLAG_01;
			state2->unk30 = handleptr;

			if (sp4e != 0) {
				state2->flags |= SNDSTATEFLAG_10;

				evt2.type = AL_SNDP_0200_EVT;
				evt2.msg.generic.sndstate = state2;
				evt2.msg.generic.data = sp4e;
				evt2.msg.generic.data2 = arg0;

				n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt2, sp48, 0);
			}
		}
	}

	if (handleptr != NULL) {
		*handleptr = state2;
	}

	return state2;
}

void audioStop(struct sndstate *state)
{
	N_ALEvent evt;

	if (state && (state->flags & SNDSTATEFLAG_02)) {
		func00033bc0(state);
	} else {
		evt.type = AL_SNDP_0400_EVT;
		evt.msg.generic.sndstate = state;

		if (state != NULL) {
			evt.msg.generic.sndstate->flags &= ~SNDSTATEFLAG_10;

			n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
		}
	}
}

static void func00033bc0(struct sndstate *state)
{
	N_ALEvent evt;

	evt.type = AL_SNDP_END_EVT;
	evt.msg.generic.sndstate = state;

	if (state) {
		evt.msg.generic.sndstate->flags &= ~SNDSTATEFLAG_10;

		n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
	}
}

static void func00033c30(u8 flags)
{
	OSIntMask mask = osSetIntMask(1);
	N_ALEvent evt;
	struct sndstate *state = g_SndpAllocStatesHead;

	while (state) {
		evt.type = AL_SNDP_0400_EVT;
		evt.msg.generic.sndstate = state;

		if ((state->flags & flags) == flags) {
			evt.msg.generic.sndstate->flags &= ~SNDSTATEFLAG_10;
			n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
		}

		state = (struct sndstate *)state->node.next;
	}

	osSetIntMask(mask);
}

static void func00033cf0(u8 flags)
{
	OSIntMask mask = osSetIntMask(1);
	N_ALEvent evt;
	struct sndstate *state = g_SndpAllocStatesHead;

	while (state) {
		evt.type = AL_SNDP_END_EVT;
		evt.msg.generic.sndstate = state;

		if ((state->flags & flags) == flags) {
			evt.msg.generic.sndstate->flags &= ~SNDSTATEFLAG_10;
			n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
		}

		state = (struct sndstate *)state->node.next;
	}

	osSetIntMask(mask);
}

void func00033db0(void)
{
	func00033cf0(SNDSTATEFLAG_01);
}

void func00033dd8(void)
{
	func00033c30(SNDSTATEFLAG_01);
}

void audioPostEvent(struct sndstate *state, s16 type, s32 data)
{
	N_ALEvent evt;

	evt.type = type;
	evt.msg.generic.sndstate = state;
	evt.msg.generic.data = data;

	if (state) {
		n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
	} else {
		// empty
	}
}

u16 func00033ec4(u8 index)
{
	return var8009c334 ? var8009c334[index] : 0;
}

struct sndstate *sndpGetHeadState(void)
{
	return g_SndpAllocStatesHead;
}

ALMicroTime sndpGetCurTime(void)
{
	return g_SndPlayer->curTime;
}

void func00033f44(u8 index, u16 volume)
{
	if (var8009c334) {
		OSIntMask mask = osSetIntMask(1);
		struct sndstate *state = g_SndpAllocStatesHead;
		s32 i;
		N_ALEvent evt;

		var8009c334[index] = volume;

		for (i = 0; state != NULL; i++, state = (struct sndstate *)state->node.next) {
			if ((state->sound->keyMap->keyMin & 0x1f) == index) {
				evt.type = AL_SNDP_0800_EVT;
				evt.msg.generic.sndstate = state;
				n_alEvtqPostEvent(&g_SndPlayer->evtq, &evt, 0, 0);
			}
		}

		osSetIntMask(mask);
	}
}
