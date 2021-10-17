#include <n_libaudio.h>
#include "synthInternals.h"

void n_alSeqpSetFilter11(N_ALSeqPlayer *seqp)
{
	N_ALEvent evt;

	evt.type = AL_FILTER_11;

	n_alEvtqPostEvent(&seqp->evtq, &evt, 0, 0);
}
