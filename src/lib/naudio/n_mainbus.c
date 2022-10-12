#include <ultra64.h>
#include "n_synthInternals.h"

s32 func00037fc0(s32 arg0, Acmd **cmd);
void func0003ba64(struct fx *fx, f32 outputrate);

Acmd *n_alMainBusPull(s32 sampleOffset, Acmd *p)
{
	Acmd *ptr = p;
	s32 i;

	if (!func00037fc0(FIXED_SAMPLE, &ptr)) {
		aClearBuffer(ptr++, N_AL_MAIN_L_OUT, N_AL_DIVIDED << 1);
	}

	for (i = 0; i < n_syn->maxAuxBusses; i++) {
		ptr = (n_syn->mainBus->filter.handler)(sampleOffset, ptr, i);

		if (var8009c344[i]) {
			if (var8009c346[i]) {
				aMix(ptr++, 0, 0x8000, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
			} else {
				aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_R_OUT);
			}
		} else {
			if (var8009c346[i]) {
				aMix(ptr++, 0, 0x8000, N_AL_AUX_L_OUT, N_AL_MAIN_R_OUT);
			} else {
				aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_R_OUT);
			}

			aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
		}

		if (n_syn->auxBus[i].unk44->unk02 > 0) {
			struct auxbus44 *bus44 = n_syn->auxBus[i].unk44;

			if (bus44->unk28) {
				// @todo: Remove cast
				func0003ba64((struct fx *)bus44, n_syn->outputRate);
			}

			n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(&bus44->unk08));

			n_aPoleFilter(ptr++, 0, N_AL_MAIN_L_OUT, 0, osVirtualToPhysical(bus44->unk2c) & 0xffffff);
			n_aPoleFilter(ptr++, 0, N_AL_MAIN_R_OUT, 0, osVirtualToPhysical(bus44->unk30) & 0xffffff);

			bus44->unk28 = 0;
		}
	}

	return ptr;
}
