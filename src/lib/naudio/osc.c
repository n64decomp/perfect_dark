#include <ultra64.h>
#include "constants.h"
#include "types.h"

/**
 * The seq.ctl file uses values 0 and 1 for tremType, and 0 and 128 for vibType.
 *
 * The other values are not used in seq.ctl but are referenced in this file.
 */
#define OSCTYPE_OFF  0
#define OSCTYPE_TREM 1
#define OSCTYPE_02   2
#define OSCTYPE_03   3
#define OSCTYPE_04   4
#define OSCTYPE_05   5
#define OSCTYPE_06   6
#define OSCTYPE_07   7
#define OSCTYPE_08   8
#define OSCTYPE_09   9
#define OSCTYPE_10   10
#define OSCTYPE_11   11
#define OSCTYPE_12   12
#define OSCTYPE_13   13
#define OSCTYPE_VIB  128

struct typetrem {
	u8 unk28;
	u8 unk29;
};

struct typevib {
	f32 unk28;
};

typedef struct oscData_s {
	struct oscData_s *next;
	u8 type;
	u8 stateFlags;
	u16 maxCount;
	s32 curCount;
	f32 unk0c;
	f32 unk10;
	u16 unk14;
	u16 unk16;
	f32 unk18;
	f32 unk1c;
	u16 unk20;
	u16 unk22;
	u16 unk24;
	u16 unk26;
	union {
		struct typetrem trem;
		struct typevib vib;
	} data;
} oscData;

oscData *freeOscStateList;
u32 var8009b874;
oscData oscStates[60];
u32 var8009c2c8;
u32 var8009c2cc;
N_ALSndPlayer var8009c2d0;

ALMicroTime osc_update(void *oscState, f32 *updateVal);
ALMicroTime osc_update_other(oscData *statePtr, f32 *updateVal);
void osc_stop_other(void *oscState);
ALMicroTime osc_init_other(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6);

f32 _depth2Cents(u8 depth)
{
	f32 x = 1.0309929847717f;
	f32 cents = 1.0f;

	while (depth) {
		if (depth & 1) {
			cents *= x;
		}

		x *= x;
		depth >>= 1;
	}

	return cents;
}

ALMicroTime osc_init(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6)
{
	oscData *state;
	ALMicroTime result = 0;

	if (oscDelay == 0) {
		return 0;
	}

	if (oscType != OSCTYPE_TREM && oscType != OSCTYPE_VIB) {
		return osc_init_other(oscState, initVal, oscType, oscRate, oscDepth, oscDelay, arg6);
	}

	if (freeOscStateList != NULL) {
		state = freeOscStateList;
		freeOscStateList = freeOscStateList->next;
		state->type = oscType;
		*oscState = state;
		result = oscDelay << 14;

		switch (oscType) {
		case OSCTYPE_TREM:
			state->unk24 = 0;
			state->unk22 = 259 - oscRate;
			state->data.trem.unk28 = oscDepth >> 1;
			state->data.trem.unk29 = 127 - state->data.trem.unk28;
			*initVal = state->data.trem.unk29;
			break;
		case OSCTYPE_VIB:
			state->data.vib.unk28 = _depth2Cents(oscDepth);
			state->unk24 = 0;
			state->unk22 = 259 - oscRate;
			*initVal = 1.0f;
			break;
		default:
			break;
		}
	}

	return result;
}

ALMicroTime osc_update(void *oscState, f32 *updateVal)
{
	f32 sp2c;
	oscData *state = oscState;
	ALMicroTime result = AL_USEC_PER_FRAME;

	if (state->type != OSCTYPE_TREM && state->type != OSCTYPE_VIB) {
		return osc_update_other(oscState, updateVal);
	}

	switch (state->type) {
	case OSCTYPE_TREM:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * DTOR(360));
		sp2c = sp2c * state->data.trem.unk28;
		*updateVal = state->data.trem.unk29 + sp2c;
		break;
	case OSCTYPE_VIB:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * DTOR(360)) * state->data.vib.unk28;
		*updateVal = alCents2Ratio(sp2c);
		break;
	default:
		break;
	}

	return result;
}

void osc_stop(void *oscState)
{
	oscData *state = (oscData *)oscState;

	if (state->type != OSCTYPE_TREM && state->type != OSCTYPE_VIB) {
		/**
		 * @bug: This function does the same freeing behaviour, which would
		 * cause the state's `next` pointer to point to itself, thus corrupting
		 * the linked list.
		 */
		osc_stop_other(oscState);
	}

	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

/**
 * 32767 => 0.00
 * 16384 => 1.00
 * 0     => 0.00
 */
f32 osc_s16_to_sine(f32 value)
{
	// Almost value / (32768 / M_PI), but has a precision mismatch
	return sinf(value / 10430.379882812f);
}

extern s32 g_CspTimeLookup[];
extern f32 g_CspRateLookup[100];

ALMicroTime osc_init_other(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6)
{
	oscData *state;
	f32 oscDepthf;

	if (oscRate > 99) {
		oscRate = 99;
	}

	if (oscDelay > 127) {
		oscDelay = 127;
	}

	if (arg6 > 127) {
		arg6 = 127;
	}

	if (freeOscStateList == NULL) {
		return 0;
	}

	state = freeOscStateList;

	if (arg6 == 0) {
		state->unk18 = 1;
		state->unk1c = 0;
	} else {
		state->unk18 = 0;
		state->unk1c = 1.0f / ((f32)g_CspTimeLookup[arg6] / AL_USEC_PER_FRAME);
	}

	state->type = oscType;
	state->unk14 = 0;
	state->unk16 = 1000000.0f / (f32)g_CspRateLookup[oscRate] / AL_USEC_PER_FRAME;
	state->curCount = AL_USEC_PER_FRAME;

	oscDepthf = oscDepth;

	if (oscType & OSCTYPE_VIB) {
		oscDepthf = _depth2Cents(oscDepthf);
	}

	oscType &= ~OSCTYPE_VIB;

	switch (oscType & ~OSCTYPE_VIB) {
	case OSCTYPE_02:
	case OSCTYPE_03:
	case OSCTYPE_04:
	case OSCTYPE_05:
		state->unk0c = oscDepthf;

		if (oscType == OSCTYPE_02) {
			state->unk10 = -oscDepthf;
		} else {
			state->unk10 = 0;
		}

		state->curCount = 500000.0f / (f32)g_CspRateLookup[oscRate];
		break;
	case OSCTYPE_06:
	case OSCTYPE_08:
	case OSCTYPE_11:
	case OSCTYPE_12:
		state->unk10 = 0;
		state->unk0c = oscDepthf;
		break;
	case OSCTYPE_07:
	case OSCTYPE_09:
	case OSCTYPE_13:
		state->unk10 = oscDepthf / 2.0f;
		state->unk0c = oscDepthf / 2.0f;
		break;
	case OSCTYPE_10:
		state->unk10 = -oscDepthf;
		state->unk0c = oscDepthf * 2.0f;
		break;
	default:
		return 0;
	}

	if (state->type & OSCTYPE_VIB) {
		*initVal = alCents2Ratio(state->unk10);
	} else {
		*initVal = state->unk10 + 127.0f;
	}

	*oscState = state;

	freeOscStateList = freeOscStateList->next;

	if (oscDelay) {
		return g_CspTimeLookup[oscDelay];
	}

	return AL_USEC_PER_FRAME;
}

ALMicroTime osc_update_other(oscData *statePtr, f32 *updateVal)
{
	f32 sp24;
	f32 sp20;
	f32 sp1c;

	if ((statePtr->type & ~OSCTYPE_VIB) >= 6) {
		statePtr->unk14++;

		if (statePtr->unk14 >= statePtr->unk16) {
			statePtr->unk14 = 0;
		}

		sp20 = (f32)statePtr->unk14 / (f32)statePtr->unk16;
	}

	if (statePtr->unk1c != 0.0f) {
		statePtr->unk18 += statePtr->unk1c;

		if (statePtr->unk18 >= 1.0f) {
			statePtr->unk18 = 1.0f;
			statePtr->unk1c = 0.0f;
		}
	}

	sp24 = statePtr->unk0c;

	if (statePtr->unk18 != 1.0f) {
		sp24 *= statePtr->unk18;
	}

	switch (statePtr->type & ~OSCTYPE_VIB) {
	case OSCTYPE_02:
	case OSCTYPE_03:
	case OSCTYPE_04:
	case OSCTYPE_05:
		if (statePtr->unk14) {
			sp20 = sp24;
		} else {
			sp20 = statePtr->unk10;
		}
		statePtr->unk14 ^= 1;
		break;
	case OSCTYPE_06:
	case OSCTYPE_07:
		if (sp20 < 0.25f) {
			sp20 *= 4.0f * sp24;
		} else if (sp20 >= 0.75f) {
			sp20 -= 0.75f;
			sp20 *= 4.0f * sp24;
			sp20 -= sp24;
		} else {
			sp20 -= 0.25f;
			sp20 *= 4.0f * sp24;
			sp20 = sp24 - sp20;
		}
		sp20 += statePtr->unk10;
		break;
	case OSCTYPE_08:
	case OSCTYPE_09:
		sp20 = osc_s16_to_sine(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		break;
	case OSCTYPE_10:
	case OSCTYPE_11:
		sp20 *= sp24;
		sp20 += statePtr->unk10;
		break;
	case OSCTYPE_12:
	case OSCTYPE_13:
		if (sp20 < 0.25f) {
			sp20 *= 4.0f * sp24;
		} else if (sp20 >= 0.75f) {
			sp20 -= 0.75f;
			sp20 *= 4.0f * sp24;
			sp20 -= sp24;
		} else {
			sp20 -= 0.25f;
			sp20 *= 4.0f * sp24;
			sp20 = sp24 - sp20;
		}

		sp1c = statePtr->unk10 + sp20;
		sp20 = (f32)statePtr->unk14 / (f32)statePtr->unk16;
		sp20 = osc_s16_to_sine(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		sp20 += sp1c;
		sp20 /= 2.0f;
		break;
	}

	if (statePtr->type & OSCTYPE_VIB) {
		*updateVal = alCents2Ratio(sp20);
	} else {
		*updateVal = sp20 + 127;
	}

	return statePtr->curCount;
}

void osc_stop_other(void *oscState)
{
	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

void osc_build_linkedlist(s32 arg0, s32 count)
{
	oscData *item;
	s32 i;

	freeOscStateList = &oscStates[0];
	item = &oscStates[0];

	for (i = 0; i < count - 1; i++) {
		item->next = &oscStates[i + 1];
		item = item->next;
	}

	item->next = NULL;
}

void osc_set_handlers(ALSeqpConfig *config)
{
	config->initOsc = osc_init;
	config->updateOsc = osc_update;
	config->stopOsc = osc_stop;

	return;
}
