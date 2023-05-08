/*====================================================================
 *
 * Copyright 1995, Silicon Graphics, Inc.
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

#ifndef __N_SNDP__
#define __N_SNDP__

#include <libaudio.h>
#include "n_libaudio.h"

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define MIN_RATIO	0.0001

typedef enum {
	AL_SNDP_PLAY_EVT  = 0x0001,
	AL_SNDP_STOP_EVT  = 0x0002,
	AL_SNDP_PAN_EVT   = 0x0004,
	AL_SNDP_VOL_EVT   = 0x0008,
	AL_SNDP_PITCH_EVT = 0x0010,
	AL_SNDP_API_EVT   = 0x0020,
	AL_SNDP_DECAY_EVT = 0x0040,
	AL_SNDP_END_EVT   = 0x0080,
	AL_SNDP_FX_EVT    = 0x0100,
	AL_SNDP_0200_EVT  = 0x0200,
	AL_SNDP_0400_EVT  = 0x0400,
	AL_SNDP_0800_EVT  = 0x0800,
	AL_SNDP_1000_EVT  = 0x1000,
	AL_SNDP_FXBUS_EVT = 0x2000,
	AL_SNDP_4000_EVT  = 0x4000
} ALSndpMsgType;

typedef struct {
	N_ALVoice     voice;
	ALSound     *sound;         /* sound referenced here */
	s16         priority;
	f32         pitch;          /* current playback pitch                    */
	s32         state;          /* play state for this sound                 */
	s16         vol;            /* volume - combined with volume from bank   */
	ALPan       pan;            /* pan - 0 = left, 127 = right               */
	u8          fxMix;          /* wet/dry mix - 0 = dry, 127 = wet          */
} N_ALSoundState;

typedef union {

	N_ALEvent             msg;

	struct {
		u16              type;
		N_ALSoundState  *state;
		u32 unk08;
	} common;

	struct {
		s16             type;
		N_ALSoundState *state;
		s16             vol;
	} vol;

	struct {
		s16             type;
		N_ALSoundState *state;
		f32             pitch;
	} pitch;

	struct {
		s16             type;
		N_ALSoundState *state;
		ALPan           pan;
	} pan;

	struct {
		s16             type;
		N_ALSoundState *state;
		u8              mix;
	} fx;

} N_ALSndpEvent;

s32		_DivS32ByF32 (s32 i, f32 f);

#endif /* __N_SNDP__ */
