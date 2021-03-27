

#define KILL_TIME	50000	/* 50 ms */

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

ALVoiceState    *__mapVoice(ALSeqPlayer *, u8, u8, u8);
void            __unmapVoice(ALSeqPlayer *seqp, ALVoice *voice);
char		__voiceNeedsNoteKill(ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime killTime);	/* sct 1/5/96 */

ALVoiceState    *__lookupVoice(ALSeqPlayer *, u8, u8);
ALSound         *__lookupSound(ALSeqPlayer *, u8, u8, u8);
ALSound         *__lookupSoundQuick(ALSeqPlayer *, u8, u8, u8);

s16             __vsVol(ALVoiceState *voice, ALSeqPlayer *seqp);
ALMicroTime     __vsDelta(ALVoiceState *voice, ALMicroTime t);
ALPan           __vsPan(ALVoiceState *voice, ALSeqPlayer *seqp);

void		__initFromBank(ALSeqPlayer *seqp, ALBank *b);
void            __initChanState(ALSeqPlayer *seqp);
void            __resetPerfChanState(ALSeqPlayer *seqp, s32 chan);
void            __setInstChanState(ALSeqPlayer *seqp, ALInstrument *inst, s32 chan);

void            __seqpPrintVoices(ALSeqPlayer *);
void		__seqpReleaseVoice(ALSeqPlayer *seqp, ALVoice *voice,
                                           ALMicroTime deltaTime);

void            __seqpStopOsc(ALSeqPlayer *seqp, ALVoiceState *vs);

void		__postNextSeqEvent(ALSeqPlayer *seqp);			/* sct 11/7/95 */

