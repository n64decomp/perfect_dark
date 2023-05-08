/*====================================================================
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#ifndef __N_SYNTHINTERNALS__
#define __N_SYNTHINTERNALS__

#include <n_libaudio.h>
#include <synthInternals.h>
#include "n_abi.h"

#define SAMPLE_ROUND
#undef  SAMPLE_ROUND

#define FINAL_ROUND

#define SAMPLES               184
#define SAMPLE184(delta)      (((delta) + SAMPLES - 1) / SAMPLES) * SAMPLES
#define FIXED_SAMPLE          SAMPLES

#define N_AL_DECODER_IN	        0
#define	N_AL_RESAMPLER_OUT	0
#define N_AL_TEMP_0	        0
#define	N_AL_DECODER_OUT        368
#define	N_AL_TEMP_1	        368
#define	N_AL_TEMP_2	        736
#define	N_AL_MAIN_L_OUT	        1248
#define	N_AL_MAIN_R_OUT	        1616
#define	N_AL_AUX_L_OUT	        1984
#define	N_AL_AUX_R_OUT	        2352

#define N_AL_DIVIDED            368

typedef struct {
	struct ALParam_s    *next;
	s32                 delta;
	s16                 type;
	struct N_PVoice_s     *pvoice;
} N_ALFreeParam;

typedef struct N_PVoice_s {
	ALLink               node;
	struct N_ALVoice_s    *vvoice;
	/** ALLoadFilter *********************************/
	ADPCM_STATE                 *dc_state;
	ADPCM_STATE                 *dc_lstate;
	ALRawLoop                   dc_loop;
	struct ALWaveTable_s        *dc_table;
	s32                         dc_bookSize;
	ALDMAproc                   dc_dma;
	void                        *dc_dmaState;
	s32                         dc_sample;
	s32                         dc_lastsam;
	s32                         dc_first;
	s32                         dc_memin;
	/** ALResampler *********************************/
	RESAMPLE_STATE      *rs_state;
	f32                 rs_ratio;
	s32			rs_upitch;
	f32		        rs_delta;
	s32			rs_first;
	/** ALEnvMixer *********************************/
	ENVMIX_STATE	*em_state;
	s16		        em_pan;
	s16		        em_volume;
	s16		        em_cvolL;
	s16		        em_cvolR;
	s16		        em_dryamt;
	s16		        em_wetamt;
	u16                 em_lratl;
	s16                 em_lratm;
	s16                 em_ltgt;
	u16                 em_rratl;
	s16                 em_rratm;
	s16                 em_rtgt;
	s32                 em_delta;
	s32                 em_segEnd;
	s32			em_first;
	ALParam		*em_ctrlList;
	ALParam		*em_ctrlTail;
	s32                 em_motion;
	s32                 offset;
	u8 unk8c;
	u16 unk8e;
	struct fx fx;
	s32 unka8;
	s32 unkac;
	s32 unkb0;
	s32 unkb4;
	s32 unkb8;
	void *unkbc; // size 8
} N_PVoice;


typedef Acmd *(*N_ALCmdHandler)(s32, Acmd *, s32 bus);

typedef struct N_ALFilter_s {
	struct N_ALFilter_s   *source;
	N_ALCmdHandler        handler;
	ALSetParam          setParam;
	s16                 inp;
	s16                 outp;
	s32                 type;
} N_ALFilter;

typedef struct N_ALMainBus_s {
	N_ALFilter           filter;
} N_ALMainBus;

// Suspected to be the same as struct fx, but auxbus44 is too big to fit inside N_PVoice.
// Maybe auxbus44 contains struct fx at unk00, then adds unk30 and unk34?
struct auxbus44 {
	u16 unk00;
	s16 unk02;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	u32 unk28;
	void *unk2c; // size 8
	void *unk30; // size 8
	u32 unk34;
};
typedef struct N_ALAuxBus_s {
	ALFilter            filter;
	s32                 sourceCount;
	s32                 maxSources;
	N_PVoice           **sources;
	ALFx                *fx;
	ALFx		*fx_array[AL_MAX_AUX_BUS_SOURCES];
	struct auxbus44 *unk44;
} N_ALAuxBus;

void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp);

ALParam         *__n_allocParam(void);
void            _n_freeParam(ALParam *param);
void            _n_freePVoice(N_PVoice *pvoice);
s32             _n_timeToSamples(s32 micros);
ALMicroTime     _n_samplesToTime(s32 samples);


Acmd    *n_alAdpcmPull(N_PVoice *f,s16 *outp, s32 byteCount, Acmd *p);
s32     n_alLoadParam(N_PVoice *filter, s32 paramID, void *param);

Acmd    *n_alResamplePull(N_PVoice *f, s16 *outp, Acmd *p);
Acmd    *n_alResamplePull2(N_PVoice *f, s16 *outp, s32 outCount, Acmd *p);
s32     n_alResampleParam(N_PVoice *f, s32 paramID, void *param);
s32     n_alResampleParam2(N_PVoice *f, s32 paramID, void *param);

Acmd    *n_alEnvmixerPull(N_PVoice *f, s32 sampleOffset, Acmd *p);
s32     n_alEnvmixerParam(N_PVoice *p, s32 paramID, void *param);

s32 n_alAuxBusParam( s32 paramID, void *param);
Acmd *n_alAuxBusPull(s32 sampleOffset, Acmd *cmdptr, s32 fxBus, s32 *numpulls);

Acmd *n_alFxPull( s32 sampleOffset, Acmd *p, s32 arg2);
s32 n_alFxParamHdl(void *filter, s32 paramID, void *param);
void n_alFxNew(ALFx **r, ALSynConfig *c, s16 bus, ALHeap *hp);

Acmd *n_alMainBusPull( s32 sampleOffset, Acmd *p);
s32 n_alMainBusParam( s32 paramID, void *param);

Acmd *n_alSavePull(s32 sampleOffset, Acmd *p);
s32 n_alSaveParam( s32 paramID, void *param);

void n_alSaveNew(void);

void n_alSynNew(ALSynConfig *c);
void n_alSynDelete(void);

#endif /*  __N_SYNTHINTERNALS__ */
