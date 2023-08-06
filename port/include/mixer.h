#ifndef MIXER_H
#define MIXER_H

#include <stdint.h>
#include <ultra64.h>

#undef aSegment
#undef aClearBuffer
#undef aSetBuffer
#undef aLoadBuffer
#undef aSaveBuffer
#undef aDMEMMove
#undef aMix
#undef aEnvMixer
#undef aResample
#undef aInterleave
#undef aSetVolume
#undef aSetVolume32
#undef aSetLoop
#undef aLoadADPCM
#undef aADPCMdec

void aClearBufferImpl(uint16_t addr, int nbytes);
void aLoadADPCMImpl(int num_entries_times_16, const int16_t *book_source_addr);
void aDMEMMoveImpl(uint16_t in_addr, uint16_t out_addr, int nbytes);
void aSetLoopImpl(ADPCM_STATE *adpcm_loop_state);
void aADPCMdecImpl(uint8_t flags, ADPCM_STATE state, int nbytes, uint16_t inofs, uint16_t outofs);
void aResampleImpl(uint8_t flags, uint16_t pitch, RESAMPLE_STATE state, uint16_t inofs, uint8_t outflag);
void aLoadBufferImpl(const void *source_addr, uint16_t dest_addr, uint16_t nbytes);
void aSaveBufferImpl(uint16_t source_addr, int16_t *dest_addr, uint16_t nbytes);
void aInterleaveImpl(void);
void aMixImpl(uint8_t flags, int16_t gain, uint16_t in_addr, uint16_t out_addr);
void aEnvMixerImpl(uint8_t flags, ENVMIX_STATE state, int16_t some_vol);
void aSetVolumeImpl(uint8_t flags, int16_t v, int16_t t, int16_t r);
void aPoleFilterImpl(uint8_t flags, int16_t gain, uint32_t t, uint32_t addr);
void aDisableImpl(uint16_t outp, uint32_t b, uint32_t c);
void aPlayMP3Impl(const void *mp3file, u32 mp3size, void *out);

#define aDisable(pkt, o, b, c) aDisableImpl(o, b, c)
#define aClearBuffer(pkt, d, c) aClearBufferImpl(d, c)
#define aLoadBuffer(pkt, c, d, s) aLoadBufferImpl(s, d, c)
#define aSaveBuffer(pkt, c, s, d) aSaveBufferImpl(s, d, c)
#define aLoadADPCM(pkt, c, d) aLoadADPCMImpl(c, d)
#define aDMEMMove(pkt, i, o, c) aDMEMMoveImpl(i, o, c)
#define aSetLoop(pkt, a) aSetLoopImpl(a)
#define aADPCMdec(pkt, s, f, c, i, o) aADPCMdecImpl(f, s, c, i, o)
#define aResample(pkt, s, f, p, i, o) aResampleImpl(f, p, s, i, o)
#define aInterleave(pkt) aInterleaveImpl()
#define aMix(pkt, f, g, i, o) aMixImpl(f, g, i, o)
#define aEnvMixer(pkt, f, t, s) aEnvMixerImpl(f, s, t)
#define aSetVolume(pkt, f, v, t, r) aSetVolumeImpl(f, v, t, r)
#define aPoleFilter(pkt, f, g, t, s) aPoleFilterImpl(f, g, t, s)
#define aPlayMP3(pkt, a, b, c) aPlayMP3Impl(a, b, c)

#endif
