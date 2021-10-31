#include <libaudio.h>
#include "n_libaudio.h"

void n_alCSPSetSeq(N_ALCSPlayer *seqp, ALCSeq *seq)
{
	N_ALEvent evt;

	evt.type = AL_SEQP_SEQ_EVT;
	evt.msg.spseq.seq = seq;

	n_alEvtqPostEvent(&seqp->evtq, &evt, 0, 0);
}
