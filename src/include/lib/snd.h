#ifndef _IN_LIB_SND_H
#define _IN_LIB_SND_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct curmp3 {
	union soundnumhack sfxref;
	u32 playing;
	u32 unk08;
	s32 responsetimer240;
	s32 prevwhisper;
	s32 prevacknowledge;
	s32 prevgreeting;
	u32 romaddr;
	u32 romsize;
	s32 responsetype;
};

extern struct curmp3 g_SndCurMp3;

bool sndIsFiltered(s32 audioid);
void sndSetSfxVolume(u16 volume);
void sndResetCurMp3(void);
void sndSetSoundMode(s32 mode);
ALSound *sndLoadSound(s16 soundnum);
void sndInit(void);
bool sndIsMp3(s16 soundnum);
bool snd0000fbc4(s16 arg0);
bool seqPlay(struct seqinstance *seq, s32 tracknum);
void seqSetVolume(struct seqinstance *seq, u16 volume);
void snd0000fe18(void);
void snd0000fe20(void);
void snd0000fe50(void);
void sndTick(void);
void sndStartMp3ByFilenum(u32 filenum);
void sndAdjust(struct sndstate **handle, s32 arg1, s32 arg2, s32 pan, s32 soundnum, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct sndstate *snd00010718(struct sndstate **handle, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8);
struct sndstate *sndStart(s32 arg0, s16 sound, struct sndstate **handle, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7);
void sndStartMp3(s16 soundnum, s32 arg1, s32 arg2, s32 arg3);
void sndPlayNosedive(s32 seconds);
void sndStopNosedive(void);
void sndPlayUfo(s32 seconds);
void sndStopUfo(void);

#endif
