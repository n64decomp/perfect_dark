#include <ultra64.h>
#include <n_libaudio.h>
#include "naudio/n_synthInternals.h"

ALFxRef func0003e540(s16 index)
{
	struct N_ALMainBus_s *mainbus = n_syn->mainBus;

	if (mainbus->filter.handler == (void *)n_alFxPull) {
		return (ALFxRef) n_syn->auxBus[index].fx;
	} else {
		return NULL;
	}
}

ALFxRef func0003e5b8(s16 index)
{
	struct N_ALMainBus_s *mainbus = n_syn->mainBus;

	if (mainbus->filter.handler == (void *)n_alFxPull) {
		return (ALFxRef) n_syn->auxBus[index].unk44;
	} else {
		return NULL;
	}
}
