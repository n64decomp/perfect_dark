#include <os_internal.h>
#include <ultraerror.h>
#include "n_synthInternals.h"

void n_alSynFilter11(N_ALVoice *v, u8 channel)
{
	ALParam *update;

	if (v->pvoice) {
		update = (ALParam *)__n_allocParam();
		ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

		update->delta  = n_syn->paramSamples + v->pvoice->offset;
		update->type   = AL_FILTER_11;
		update->data.i = channel;
		update->next   = 0;

		n_alEnvmixerParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);
	}
}
