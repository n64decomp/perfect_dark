#include "n_synthInternals.h"

void n_alSynSetFXParam(ALFxRef fx, s16 paramID, void *param)
{
	ALFx *f = (ALFx *)fx;

	n_alFxParamHdl(f, (s32)paramID, param);
}

void n_alFxInitlpfilter_mono(struct fx *fx, f32 outputrate);

void n_alSynSetOutputLPParam(struct fx *fx, s16 arg1, void *param)
{
	if (arg1 == 8) {
		fx->unk02 = (*(s32 *)param * 0.1f);
	} else if (arg1 == 9) {
		fx->unk00 = *(s32 *)param;
	}

	n_alFxInitlpfilter_mono(fx, n_syn->outputRate);
}
