#include <libaudio.h>
#include "n_libaudio.h"

void n_alSeqpStop(N_ALSeqPlayer *seqp)
{
	N_ALEvent evt;

	evt.type = AL_SEQP_STOPPING_EVT;

	n_alEvtqPostEvent(&seqp->evtq, &evt, 0, 0);
}
