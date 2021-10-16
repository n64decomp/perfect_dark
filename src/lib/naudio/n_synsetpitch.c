#include <os_internal.h>
#include <ultraerror.h>
#include "n_synthInternals.h"

void n_alSynSetPitch(N_ALVoice *v, f32 pitch)
{
	ALParam *update;

	if (v->pvoice) {
		/*
		 * get new update struct from the free list
		 */

		update = __n_allocParam();
		ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

		/*
		 * set offset and pitch data
		 */
		update->delta = n_syn->paramSamples + v->pvoice->offset;
		update->type = AL_FILTER_SET_PITCH;
		update->data.f = pitch;
		update->next = 0;

		n_alEnvmixerParam(v->pvoice, AL_FILTER_ADD_UPDATE, update);
	}
}
