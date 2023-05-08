#include "n_synthInternals.h"
#include <os.h>
#include <gu.h>
#include "constants.h"

void func0003ba64(struct fx *fx, f32 outputrate);

Acmd *n_alResamplePull2(N_PVoice *e, s16 *outp, s32 outCount, Acmd *p)
{
	Acmd *ptr = p;
	f32 sp28;

	ptr = n_alResamplePull(e, outp, p);

	if (e->unk8c != 0 && e->unk8c < 64) {
		if (e->unk8c >= 6) {
			sp28 = 26755 / sqrtf(e->unk8c + 1.0f);
		} else {
			sp28 = 65536 / (e->unk8c + 1.0f);
		}

		if (sp28 < 7723) {
			sp28 = 7723;
		}

		n_aNoop(ptr++, *outp, sp28, e->unk8c + 1);
	}

	if (e->fx.unk02 > 0) {
		if (e->unkb8 != 0) {
			func0003ba64(&e->fx, 22050);
		}

		n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(e->fx.unk08))

		if (e->unkb8 == 2) {
			e->unkb8 = 0;
		}

		n_aPoleFilter(ptr++, e->unkb8, *outp, 0, osVirtualToPhysical(e->unkbc) & 0xffffff);

		e->unkb8 = 0;
	}

	return ptr;
}

s32 n_alResampleParam2(N_PVoice *filter, s32 paramID, void *param)
{
	f32 *f = (f32 *) &param;

	switch (paramID) {
	case (AL_FILTER_RESET):
		filter->fx.unk02 = 0;
		n_alLoadParam(filter, AL_FILTER_RESET, param);
		break;
	case (AL_FILTER_12):
		filter->fx.unk02 = (s32) param;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_13):
		filter->fx.unk00 = *f;
		filter->unkb8 |= 2;
		break;
	case (AL_FILTER_11):
		filter->unk8c = (u8)param;
		break;
	default:
		n_alLoadParam(filter, paramID, param);
		break;
	}

	return 0;
}
