#include "n_synthInternals.h"

ALFxRef n_alSynAllocFX(s16 bus, ALSynConfig *c, ALHeap *hp)
{
	n_alFxNew(n_syn->auxBus[bus].fx_array, c, bus, hp);
	return n_syn->auxBus[bus].fx_array[0];
}
