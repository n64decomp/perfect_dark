#ifndef _IN_LIB_SND_H
#define _IN_LIB_SND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool sndIsFiltered(s32 audioid);
bool sndIsPlayingMp3(void);
u16 snd0000e9dc(void);
void sndSetSfxVolume(u16 volume);
void snd0000ea80(u16 volume);
void sndResetCurMp3(void);
void sndLoadSfxCtl(void);
void sndIncrementAges(void);
ALEnvelope *sndLoadEnvelope(u32 offset, u16 index);
ALKeyMap *sndLoadKeymap(u32 offset, u16 index);
ALADPCMBook *sndLoadAdpcmBook(u32 offset, u16 index);
ALADPCMloop *sndLoadAdpcmLoop(u32 offset, u16 index);
ALWaveTable *sndLoadWavetable(u32 offset, u16 index);
void sndSetSoundMode(s32 mode);
ALSound *sndLoadSound(s16 soundnum);
void seqInit(struct seqinstance *seq);
void sndInit(void);
bool sndIsMp3(s16 soundnum);
bool snd0000fbc4(s16 arg0);
bool seqPlay(struct seqinstance *seq, s32 tracknum);
u16 seqGetVolume(struct seqinstance *seq);
void seqSetVolume(struct seqinstance *seq, u16 volume);
void sndHandleRetrace(void);
void snd0000fe20(void);
void snd0000fe50(void);
void sndTick(void);
bool sndIsDisabled(void);
void sndStartMp3ByFilenum(u32 filenum);
void sndAdjust(struct sndstate **handle, s32 arg1, s32 arg2, s32 pan, s32 soundnum, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct sndstate *snd00010718(struct sndstate **handle, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct sndstate *sndStart(s32 arg0, s16 sound, struct sndstate **handle, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7);
void sndStartMp3(s16 soundnum, s32 arg1, s32 arg2, s32 arg3);
void sndPlayNosedive(s32 seconds);
void sndStopNosedive(void);
void sndTickNosedive(void);
void sndPlayUfo(s32 seconds);
void sndStopUfo(void);
void sndTickUfo(void);

#endif
