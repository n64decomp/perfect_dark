#include <ultra64.h>
#include "constants.h"
#include "types.h"

struct typea {
	u8 unk28;
	u8 unk29;
};

struct typeb {
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
		struct typea a;
		struct typeb b;
	} data;
} oscData;

oscData *freeOscStateList;
oscData oscStates[60];
N_ALSndPlayer var8009c2d0;

ALMicroTime updateOsc(void *oscState, f32 *updateVal);
static ALMicroTime updateOscMain(oscData *statePtr, f32 *updateVal);
static void func00030bd8(void *oscState);
static ALMicroTime initOscMain(void **oscState, f32 *initVal, u8 oscType, u8 arg3, u8 oscDepth, u8 arg5, u8 arg6);

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

ALMicroTime initOsc(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6)
{
	oscData *state;
	ALMicroTime result = 0;

	if (oscDelay == 0) {
		return 0;
	}

	if (oscType != 1 && oscType != 0x80) {
		return initOscMain(oscState, initVal, oscType, oscRate, oscDepth, oscDelay, arg6);
	}

	if (freeOscStateList != NULL) {
		state = freeOscStateList;
		freeOscStateList = freeOscStateList->next;
		state->type = oscType;
		*oscState = state;
		result = oscDelay << 14;

		switch (oscType) {
		case 1:
			state->unk24 = 0;
			state->unk22 = 259 - oscRate;
			state->data.a.unk28 = oscDepth >> 1;
			state->data.a.unk29 = 127 - state->data.a.unk28;
			*initVal = state->data.a.unk29;
			break;
		case 0x80:
			state->data.b.unk28 = _depth2Cents(oscDepth);
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

ALMicroTime updateOsc(void *oscState, f32 *updateVal)
{
	f32 sp2c;
	oscData *state = oscState;
	ALMicroTime result = AL_USEC_PER_FRAME;

	if (state->type != 1 && state->type != 0x80) {
		return updateOscMain(oscState, updateVal);
	}

	switch (state->type) {
	case 0x01:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * M_TAU);
		sp2c = sp2c * state->data.a.unk28;
		*updateVal = state->data.a.unk29 + sp2c;
		break;
	case 0x80:
		state->unk24++;

		if (state->unk24 >= state->unk22) {
			state->unk24 = 0;
		}

		sp2c = (f32)state->unk24 / (f32)state->unk22;
		sp2c = sinf(sp2c * M_TAU) * state->data.b.unk28;
		*updateVal = alCents2Ratio(sp2c);
		break;
	default:
		break;
	}

	return result;
}

void stopOsc(void *oscState)
{
	oscData *state = (oscData *)oscState;

	if (state->type != 1 && state->type != 0x80) {
		func00030bd8(oscState);
	}

	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

static f32 func000301a4(f32 value)
{
	// Almost value / (32768 / M_PI), but has a precision mismatch
	return sinf(value / 10430.379882812f);
}

extern s32 var8005f150[];
extern f32 var8005f34c[100];

static ALMicroTime initOscMain(void **oscState, f32 *initVal, u8 oscType, u8 arg3, u8 oscDepth, u8 arg5, u8 arg6)
{
	oscData *state;
	f32 oscDepthf;

	if (arg3 > 99) {
		arg3 = 99;
	}

	if (arg5 > 127) {
		arg5 = 127;
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
		state->unk1c = 1.0f / ((f32)var8005f150[arg6] / AL_USEC_PER_FRAME);
	}

	state->type = oscType;
	state->unk14 = 0;
	state->unk16 = 1000000.0f / (f32)var8005f34c[arg3] / AL_USEC_PER_FRAME;
	state->curCount = AL_USEC_PER_FRAME;

	oscDepthf = oscDepth;

	if (oscType & 0x80) {
		oscDepthf = _depth2Cents(oscDepthf);
	}

	oscType &= ~0x80;

	switch (oscType & ~0x80) {
	case 2:
	case 3:
	case 4:
	case 5:
		state->unk0c = oscDepthf;

		if (oscType == 2) {
			state->unk10 = -oscDepthf;
		} else {
			state->unk10 = 0;
		}

		state->curCount = 500000.0f / (f32)var8005f34c[arg3];
		break;
	case 6:
	case 8:
	case 11:
	case 12:
		state->unk10 = 0;
		state->unk0c = oscDepthf;
		break;
	case 7:
	case 9:
	case 13:
		state->unk10 = oscDepthf / 2.0f;
		state->unk0c = oscDepthf / 2.0f;
		break;
	case 10:
		state->unk10 = -oscDepthf;
		state->unk0c = oscDepthf * 2.0f;
		break;
	default:
		return 0;
	}

	if (state->type & 0x80) {
		*initVal = alCents2Ratio(state->unk10);
	} else {
		*initVal = state->unk10 + 127.0f;
	}

	*oscState = state;

	freeOscStateList = freeOscStateList->next;

	if (arg5) {
		return var8005f150[arg5];
	}

	return AL_USEC_PER_FRAME;
}

static ALMicroTime updateOscMain(oscData *statePtr, f32 *updateVal)
{
	f32 sp24;
	f32 sp20;
	f32 sp1c;

	if ((statePtr->type & ~0x80) >= 6) {
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

	switch (statePtr->type & ~0x80) {
	case 2:
	case 3:
	case 4:
	case 5:
		if (statePtr->unk14) {
			sp20 = sp24;
		} else {
			sp20 = statePtr->unk10;
		}
		statePtr->unk14 ^= 1;
		break;
	case 6:
	case 7:
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
	case 8:
	case 9:
		sp20 = func000301a4(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		break;
	case 10:
	case 11:
		sp20 *= sp24;
		sp20 += statePtr->unk10;
		break;
	case 12:
	case 13:
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
		sp20 = func000301a4(sp20 * 65536.0f) * sp24 + statePtr->unk10;
		sp20 += sp1c;
		sp20 /= 2.0f;
		break;
	}

	if (statePtr->type & 0x80) {
		*updateVal = alCents2Ratio(sp20);
	} else {
		*updateVal = sp20 + 127;
	}

	return statePtr->curCount;
}

static void func00030bd8(void *oscState)
{
	((oscData*)oscState)->next = freeOscStateList;
	freeOscStateList = (oscData*)oscState;
}

void func00030bfc(s32 arg0, s32 count)
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

void func00030c98(ALSeqpConfig *config)
{
	config->initOsc = initOsc;
	config->updateOsc = updateOsc;
	config->stopOsc = stopOsc;

	return;
}
