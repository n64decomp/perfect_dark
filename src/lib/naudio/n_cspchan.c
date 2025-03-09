#include <ultra64.h>
#include <n_libaudio.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void n_alCSPAllChanOn(N_ALCSPlayer *seqp)
{
	s32 i;

	seqp->chanMask = 0xffff;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].fadevoltarget = 255;
		seqp->chanState[i].fadevolcurrent = 255;
	}
}

void n_alCSPChanOff(N_ALCSPlayer *seqp, s32 chan)
{
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADEEND_CTRL, 0);
}

void n_alCSPChanOn(N_ALCSPlayer *seqp, s32 chan)
{
	seqp->chanMask |= 1 << chan;

	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADEEND_CTRL, 255);
}

void n_alCSPChanFadeAuto(N_ALCSPlayer *seqp, s32 chan, u8 targetvol)
{
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADESTART_CTRL, targetvol);
}

void n_alCSPChanFade(N_ALCSPlayer *seqp, s32 chan, u8 targetvol, u8 incvol)
{
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADESPEED_CTRL, incvol);
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADESTART_CTRL, targetvol);
}

void n_alCSPChanSurround(N_ALCSPlayer *seqp, s32 chan, u8 arg2)
{
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FXMIX80_CTRL, arg2);
}

void n_alCSPChanFadeForce(N_ALCSPlayer *seqp, s32 chan, u8 vol)
{
	n_alCSPSendMidi(seqp, 0, AL_MIDI_ControlChange | chan, AL_MIDI_FADEEND_CTRL, vol);
}
