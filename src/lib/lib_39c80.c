#include <ultra64.h>
#include <n_libaudio.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void func00039cd0(N_ALCSPlayer *seqp)
{
	s32 i;

	seqp->chanMask = 0xffff;

	for (i = 0; i < seqp->maxChannels; i++) {
		seqp->chanState[i].unk0e = 0xff;
		seqp->chanState[i].unk0d = 0xff;
	}
}

void func00039e5c(N_ALCSPlayer *seqp, s32 arg1, u8 arg2, u8 arg3)
{
	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0xfd, arg3);
	n_alCSPSendMidi(seqp, 0, arg1 | 0xb0, 0xff, arg2);
}
