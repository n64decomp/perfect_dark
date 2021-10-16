#include <ultraerror.h>
#include <os_internal.h>
#include <os.h>
#include "n_synthInternals.h"

void n_alSynFreeVoice(N_ALVoice *voice)
{
	N_ALFreeParam *update;
	ALFilter *f;

	if (voice->pvoice) {
		if (voice->pvoice->offset) { /* if voice was stolen */
			update = (N_ALFreeParam *)__n_allocParam();
			ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

			/*
			 * set voice data
			 */
			update->delta  = n_syn->paramSamples + voice->pvoice->offset;
			update->type   = AL_FILTER_FREE_VOICE;
			update->pvoice = voice->pvoice;

			n_alEnvmixerParam(voice->pvoice, AL_FILTER_ADD_UPDATE, update);
		} else {
			_n_freePVoice( voice->pvoice);
		}

		voice->pvoice = 0;
	}
}
