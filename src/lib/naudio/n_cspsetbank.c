#include <libaudio.h>
#include "n_libaudio.h"

void n_alCSPSetBank(N_ALCSPlayer *seqp, ALBank *b)
{
	N_ALEvent evt;

	evt.type = AL_SEQP_BANK_EVT;
	evt.msg.spbank.bank = b;

	n_alEvtqPostEvent(&seqp->evtq, &evt, 0, 0);
}
