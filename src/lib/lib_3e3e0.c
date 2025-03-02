#include <ultra64.h>
#include <n_libaudio.h>
#include "naudio/n_synthInternals.h"

ALFxRef n_alSynGetFXRef(s16 bus)
{
	struct N_ALMainBus_s *mainbus = n_syn->mainBus;

	if (mainbus->filter.handler == (void *)n_alFxPull) {
		return n_syn->auxBus[bus].fx;
	} else {
		return NULL;
	}
}

ALFxRef n_alSynGetOutputLPRef(s16 bus)
{
	struct N_ALMainBus_s *mainbus = n_syn->mainBus;

	if (mainbus->filter.handler == (void *)n_alFxPull) {
		return &n_syn->auxBus[bus].unk44->fx;
	} else {
		return NULL;
	}
}
