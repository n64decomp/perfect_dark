#include <libaudio.h>
#include "n_libaudio.h"

void n_alCSPPlay(N_ALCSPlayer *seqp)
{
	N_ALEvent evt;

	evt.type = AL_SEQP_PLAY_EVT;

	n_alEvtqPostEvent(&seqp->evtq, &evt, 0, 0);
}
