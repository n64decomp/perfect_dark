#include "n_synthInternals.h"
#include <os.h>
#include <math.h>

#define N_EQPOWER_LENGTH 128

s16 n_eqpower[] = {
	0x7fff, 0x7ffc, 0x7ff5, 0x7fe8, 0x7fd7, 0x7fc0, 0x7fa5, 0x7f84,
	0x7f5f, 0x7f34, 0x7f05, 0x7ed0, 0x7e97, 0x7e58, 0x7e15, 0x7dcd,
	0x7d7f, 0x7d2d, 0x7cd6, 0x7c7a, 0x7c1a, 0x7bb4, 0x7b49, 0x7ada,
	0x7a66, 0x79ed, 0x796f, 0x78ed, 0x7866, 0x77da, 0x7749, 0x76b4,
	0x761a, 0x757b, 0x74d8, 0x7430, 0x7384, 0x72d3, 0x721e, 0x7164,
	0x70a6, 0x6fe3, 0x6f1c, 0x6e51, 0x6d81, 0x6cad, 0x6bd5, 0x6af9,
	0x6a18, 0x6933, 0x684a, 0x675d, 0x666c, 0x6577, 0x647e, 0x6381,
	0x6280, 0x617c, 0x6073, 0x5f67, 0x5e57, 0x5d43, 0x5c2c, 0x5b11,
	0x59f2, 0x58d0, 0x57aa, 0x5681, 0x5555, 0x5425, 0x52f2, 0x51bc,
	0x5082, 0x4f46, 0x4e06, 0x4cc3, 0x4b7d, 0x4a35, 0x48e9, 0x479b,
	0x4649, 0x44f5, 0x439e, 0x4245, 0x40e9, 0x3f8a, 0x3e29, 0x3cc6,
	0x3b60, 0x39f8, 0x388d, 0x3721, 0x35b2, 0x3441, 0x32ce, 0x3159,
	0x2fe2, 0x2e69, 0x2cef, 0x2b72, 0x29f4, 0x2875, 0x26f3, 0x2570,
	0x23ec, 0x2266, 0x20df, 0x1f57, 0x1dce, 0x1c43, 0x1ab7, 0x192a,
	0x179c, 0x160e, 0x147e, 0x12ed, 0x115c, 0x0fca, 0x0e38, 0x0ca5,
	0x0b11, 0x097d, 0x07e9, 0x0654, 0x04c0, 0x032a, 0x0195, 0x0000,
};

static Acmd *_pullSubFrame(N_PVoice *filter, s16 *inp, s16 *outp, s32 outCount, Acmd *p);

Acmd *n_alEnvmixerPull(N_PVoice *filter, s32 sampleOffset, Acmd *p)
{
	Acmd     *ptr = p;
	N_PVoice *e = (N_PVoice *)filter;
	s16      inp;
	s32      lastOffset;
	s32      thisOffset = sampleOffset;
	s32      samples;
	s16      loutp = 0;
	s32      fVol;
	ALParam  *thisParam;
	s32      outCount = FIXED_SAMPLE;

	/*
	 * Force the input to be the resampler output
	 */
	inp = N_AL_RESAMPLER_OUT;

	while (e->em_ctrlList != 0) {
		lastOffset = thisOffset;
		thisOffset = e->em_ctrlList->delta;

		samples = SAMPLE184(thisOffset - lastOffset);

		if (!samples) {
			thisOffset = lastOffset;
		}

		if (samples > outCount) {
			break;
		}

		switch (e->em_ctrlList->type) {
		case (AL_FILTER_START_VOICE_ALT):
			{
				ALStartParamAlt *param = (ALStartParamAlt *)e->em_ctrlList;
				s32 tmp;

				if (param->unity) {
					e->rs_upitch = 1;
				}

				n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, param->wave);

				e->em_motion = AL_PLAYING;
				e->em_first  = 1;
				e->em_delta  = 0;
				e->em_segEnd = SAMPLE184(param->samples);

				tmp = (param->volume + param->volume) / 2;

				e->em_volume = tmp;
				e->em_pan    = param->pan;
				e->em_dryamt = (n_eqpower[param->fxMix & 0x7f] & 0xfffe) | (param->fxMix >> 7);

				if (!var8009c340.surround) {
					e->em_dryamt &= 0xfffe;
				}

				e->em_wetamt = n_eqpower[N_EQPOWER_LENGTH - (param->fxMix & 0x7f) - 1] & 0xfffe;

				if (var8009c340.headphone) {
					e->em_pan = (e->em_pan >> 1) + 32;
				} else if (var8009c340.mono) {
					e->em_pan = 64;
				}

				if (param->samples) {
					e->em_cvolL = 1;
					e->em_cvolR = 1;
				} else {
					/*
					 * Attack time is zero. Simply set the
					 * volume. We don't want an attack segment.
					 */
					e->em_cvolL = (e->em_volume * n_eqpower[e->em_pan]) >> 15;
					e->em_cvolR = (e->em_volume * n_eqpower[N_EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
				}

				e->rs_ratio = param->pitch;
				e->fx.unk02 = param->unk15;
				e->fx.unk00 = param->unk18;
				e->unkb8 = 1;
				e->unk8c = param->unk14;
			}
			break;

		case (AL_FILTER_SET_FXAMT):
		case (AL_FILTER_SET_PAN):
		case (AL_FILTER_SET_VOLUME):
			ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);

			if (e->em_delta >= e->em_segEnd){
				/*
				 * We should have reached our target, calculate
				 * target in case e->em_segEnd was 0
				 */
				e->em_ltgt = (e->em_volume * n_eqpower[e->em_pan]) >> 15;
				e->em_rtgt = (e->em_volume * n_eqpower[N_EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
				e->em_delta = e->em_segEnd;   /* To prevent overflow */
				e->em_cvolL = e->em_ltgt;
				e->em_cvolR = e->em_rtgt;
			} else {
				/*
				 * Estimate the current volume
				 */
				e->em_cvolL = _getVol(e->em_cvolL, e->em_delta, e->em_lratm, e->em_lratl);
				e->em_cvolR = _getVol(e->em_cvolR, e->em_delta, e->em_rratm, e->em_rratl);
			}

			/*
			 * We can't have volume of zero, because the envelope
			 * would never go anywhere from there
			 */
			if (e->em_cvolL == 0) {
				e->em_cvolL = 1;
			}

			if (e->em_cvolR == 0) {
				e->em_cvolR = 1;
			}

			if (e->em_ctrlList->type == AL_FILTER_SET_PAN) {
				/*
				 * This should result in a change to the current
				 * segment rate and target
				 */
				if (var8009c340.headphone) {
					e->em_pan = ((s16)e->em_ctrlList->data.i >> 1) + 32;
				} else if (var8009c340.mono) {
					e->em_pan = 64;
				} else {
					e->em_pan = (s16) e->em_ctrlList->data.i;
				}
			}

			if (e->em_ctrlList->type == AL_FILTER_SET_VOLUME) {
				/*
				 * Switching to a new segment
				 */
				e->em_delta = 0;

				/*
				 * Map volume non-linearly to give something close to
				 * loudness
				 */
				fVol = (e->em_ctrlList->data.i);
				fVol = (fVol + fVol) / 2;

				e->em_volume = (s16) fVol;
				e->em_segEnd = SAMPLE184(e->em_ctrlList->moredata.i);
			}

			if (e->em_ctrlList->type == AL_FILTER_SET_FXAMT) {
				if (((e->em_dryamt ^ e->em_wetamt) & 1) ^ ((e->em_ctrlList->data.i + 1) >> 7)) {
					if (var8009c340.surround) {
						if (e->em_pan > 64) {
							e->em_dryamt ^= 1;
						} else {
							e->em_wetamt ^= 1;
						}
					}
				}

				e->em_dryamt = (n_eqpower[e->em_ctrlList->data.i & 0x7f] & 0xfffe) | (e->em_dryamt & 1);
				e->em_wetamt = (n_eqpower[N_EQPOWER_LENGTH - (e->em_ctrlList->data.i & 0x7f) - 1] & 0xfffe) | (e->em_wetamt & 1);
			}

			/*
			 * Force a volume update
			 */
			e->em_first = 1;
			break;

		case (AL_FILTER_START_VOICE):
			{
				ALStartParam *p = (ALStartParam *)e->em_ctrlList;

				/*
				 * Changing to PLAYING (since the previous state was
				 * persumable STOPPED, we'll just bump the output
				 * pointer rather than pull a subframe of zeros).
				 */
				if (p->unity) {
					e->rs_upitch = 1;
				}

				n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, p->wave);
				e->em_motion = AL_PLAYING;
			}
			break;
		case (AL_FILTER_STOP_VOICE):
			{
				/*
				 * Changing to STOPPED and reset the filter
				 */
				ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);
				n_alEnvmixerParam(e, AL_FILTER_RESET, 0);
			}
			break;

		case (AL_FILTER_FREE_VOICE):
			{
				N_ALFreeParam *param = (N_ALFreeParam *)e->em_ctrlList;
				param->pvoice->offset = 0;
				_n_freePVoice((N_PVoice *)param->pvoice);
			}
			break;
		case (AL_FILTER_SET_PITCH):
			ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);
			e->rs_ratio = e->em_ctrlList->data.f;
			break;
		case (AL_FILTER_SET_UNITY_PITCH):
			ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);
			e->rs_upitch = 1;
			break;
		case (AL_FILTER_SET_WAVETABLE):
			ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);
			n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, (void *)e->em_ctrlList->data.i);
			break;
		default:
			/*
			 * Pull the reuired number of samples and then pass the message
			 * on down the chain
			 */
			ptr = _pullSubFrame(e, &inp, &loutp, samples, ptr);
			n_alEnvmixerParam(e, e->em_ctrlList->type, (void *) e->em_ctrlList->data.i);
			break;
		}

		loutp += samples << 1;
		outCount -= samples;

		/*
		 * put the param record back on the free list
		 */
		thisParam = e->em_ctrlList;
		e->em_ctrlList = e->em_ctrlList->next;

		if (e->em_ctrlList == 0) {
			e->em_ctrlTail = 0;
		}

		_n_freeParam(thisParam);
	}

	ptr = _pullSubFrame(e, &inp, &loutp, outCount, ptr);

	/*
	 * Prevent overflow in e->em_delta
	 */
	if (e->em_delta > e->em_segEnd) {
		e->em_delta = e->em_segEnd;
	}

	return ptr;
}

s32 n_alEnvmixerParam(N_PVoice *filter, s32 paramID, void *param)
{
	N_PVoice *e = filter;

	switch (paramID) {
	case AL_FILTER_ADD_UPDATE:
		if (e->em_ctrlTail) {
			e->em_ctrlTail->next = (ALParam *)param;
		} else {
			e->em_ctrlList = (ALParam *)param;
		}

		e->em_ctrlTail = (ALParam *)param;
		break;
	case AL_FILTER_RESET:
		e->em_first = 1;
		e->em_motion = AL_STOPPED;
		e->em_volume = 1;
		e->em_segEnd = 0;
		e->rs_delta = 0;
		e->rs_first = 1;
		e->rs_upitch = 0;

		n_alResampleParam2(e, AL_FILTER_RESET, param);
		break;
	case AL_FILTER_START:
		e->em_motion = AL_PLAYING;
		break;
	default:
		n_alResampleParam2(e, paramID, param);
		break;
	}

	return 0;
}

static Acmd *_pullSubFrame(N_PVoice *filter, s16 *inp, s16 *outp, s32 outCount, Acmd *p)
{
	Acmd *ptr = p;
	N_PVoice *e = filter;

	/* filter must be playing and request non-zero output samples to pull. */
	if (e->em_motion != AL_PLAYING || !outCount) {
		return ptr;
	}

	/*
	 * ask all filters upstream from us to build their command
	 * lists.
	 */

	ptr = n_alResamplePull2(e, inp, outCount, p);

	/*
	 * construct our portion of the command list
	 */
	if (e->em_first) {
		e->em_first = 0;

		/*
		 * Calculate derived parameters
		 */
		e->em_ltgt = (e->em_volume * n_eqpower[e->em_pan]) >> 15;
		e->em_lratm = _getRate(e->em_cvolL, e->em_ltgt, e->em_segEnd, &(e->em_lratl));
		e->em_rtgt = (e->em_volume * n_eqpower[N_EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
		e->em_rratm = _getRate(e->em_cvolR, e->em_rtgt, e->em_segEnd, &(e->em_rratl));

		n_aSetVolume(ptr++, A_LEFT  | A_VOL, e->em_cvolL, e->em_dryamt, e->em_wetamt);
		n_aSetVolume(ptr++, A_RIGHT | A_VOL, e->em_rtgt, e->em_rratm,  e->em_rratl);
		n_aSetVolume(ptr++, A_RATE, e->em_ltgt, e->em_lratm, e->em_lratl);
		n_aEnvMixer (ptr++, A_INIT, e->em_cvolR, osVirtualToPhysical(e->em_state));
	} else {
		n_aEnvMixer(ptr++, A_CONTINUE, 0, osVirtualToPhysical(e->em_state));
	}

	/*
	 * bump the input buffer pointer
	 */
	*inp += (FIXED_SAMPLE << 1);
	e->em_delta += FIXED_SAMPLE;

	return ptr;
}

s16 _getRate(f32 vol, f32 tgt, s32 count, u16 *ratel)
{
	s16 s;
	s16 tmp;
	f32 invn;
	f32 a;
	f32 f;

	if (count == 0) {
		if (tgt >= vol) {
			*ratel = 0xffff;
			return 0x7fff;
		} else {
			*ratel = 0;
			return -0x8000;
		}
	}

	invn = 1 / (f32) count;

	if (tgt < 1) {
		tgt = 1;
	}

	if (vol <= 0) {
		vol = 1;
	}

	a = (tgt - vol) * invn * 8;
	s = a;

	f = a - s;
	s--;
	f++;

	tmp = f;
	s += tmp;
	f -= tmp;

	*ratel = 65535 * f;

	return s;
}

s16 _getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel)
{
	s32 sp4;

	/*
	 * Rate values are actually rate^8
	 */
	samples >>= 3;

	if (samples == 0) {
		return ivol;
	}

	sp4 = ratel * samples;
	sp4 >>= 16;
	sp4 += ratem * samples;

	ivol += sp4;

	return ivol;
}
