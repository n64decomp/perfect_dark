#include "n_synthInternals.h"

void n_alSynSetFXParam(ALFxRef fx, s16 paramID, void *param)
{
	ALFx *f = (ALFx *)fx;

	n_alFxParamHdl(f, (s32)paramID, param);
}

void func0003ba64(struct fx *fx, f32 outputrate);

void func0003e674(struct fx *fx, s16 arg1, void *param)
{
	if (arg1 == 8) {
		fx->unk02 = (*(s32 *)param * 0.1f);
	} else if (arg1 == 9) {
		fx->unk00 = *(s32 *)param;
	}

	func0003ba64(fx, n_syn->outputRate);
}
