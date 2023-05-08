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

#ifndef __N_SEQP__
#define __N_SEQP__

#define KILL_TIME	50000	/* 50 ms */

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif


void __n_unmapVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice);
char __n_voiceNeedsNoteKill(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime killTime);
void __n_seqpReleaseVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime);


N_ALVoiceState   *__n_mapVoice(N_ALSeqPlayer *, u8, u8, u8);
N_ALVoiceState   *__n_lookupVoice(N_ALSeqPlayer *, u8, u8);
ALSound          *__n_lookupSound(N_ALSeqPlayer *, u8, u8, u8);
ALSound          *__n_lookupSoundQuick(N_ALSeqPlayer *, u8, u8, u8);
s16               __n_vsVol(N_ALVoiceState *voice, N_ALSeqPlayer *seqp);
ALMicroTime       __n_vsDelta(N_ALVoiceState *voice, ALMicroTime t);
ALPan             __n_vsPan(N_ALVoiceState *voice, N_ALSeqPlayer *seqp);
void		  __n_initFromBank(N_ALSeqPlayer *seqp, ALBank *b);
void              __n_initChanState(N_ALSeqPlayer *seqp);
void              __n_setInstChanState(N_ALSeqPlayer *seqp, ALInstrument *inst, s32 chan);
void              __n_seqpStopOsc(N_ALSeqPlayer *seqp, N_ALVoiceState *vs);
void		  __n_postNextSeqEvent(N_ALSeqPlayer *seqp);

#endif /* __N_SEQP__ */
