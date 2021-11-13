#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3e8c0.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_461c0.h"
#include "data.h"
#include "types.h"

extern struct mp3vars g_Mp3Vars;

u8 var8009c650[0x88];
u8 *var8009c6d8;
u8 *var8009c6dc;

u32 var8005f700 = 0;
u32 var8005f704 = 0;

s32 func00043dd0(struct asistream *stream)
{
	s32 sp1c = 0x1000;
	s32 sp18;

	if (stream->unk201c + stream->unk3f88 > 0x1ffb) {
		bcopy(&stream->unk1c[sp1c], &stream->unk1c, sp1c);
		stream->unk201c -= sp1c;
		stream->unk2020 -= sp1c * 8;
	}

	sp18 = stream->unk04(stream->unk00, &stream->unk1c[stream->unk201c], stream->unk3f88, -1);

	if (sp18 < stream->unk3f88) {
		bzero(&stream->unk1c[sp18], stream->unk3f88 - sp18);
	}

	stream->unk18 += stream->unk3f88;
	stream->unk201c += stream->unk3f88;

	return stream->unk201c - stream->unk3f88;
}

bool func00043ef8(struct asistream *stream, s32 arg1)
{
	s32 sp24;
	s32 sp20;
	s32 sp1c;
	u8 mask;

	if (arg1 != -1) {
		stream->unk18 = arg1;
	}

	sp24 = arg1;
	sp20 = 0;
	mask = 0xff;

	while (true) {
		sp1c = stream->unk04(stream->unk00, &stream->unk2024[sp20], 1, sp24);

		if (sp1c < 1) {
			return 0;
		}

		sp24 = -1;
		stream->unk18++;

		if ((stream->unk2024[sp20] & mask) != mask) {
			mask = 0xff;
			sp20 = 0;
			continue;
		}

		sp20++;

		if (mask == 0xf0) {
			break;
		}

		mask = 0xf0;
	}

	sp1c = stream->unk04(stream->unk00, &stream->unk2024[2], 2, -1);

	if (sp1c <= 0) {
		return 0;
	}

	stream->unk18 += 2;
	stream->unk2064 = 12;

	stream->unk3ba4 = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3ba8 = func000462c4(&stream->unk2024, &stream->unk2064, 2);
	stream->unk3bac = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3bb0 = func000462c4(&stream->unk2024, &stream->unk2064, 4);
	stream->unk3bb4 = func000462c4(&stream->unk2024, &stream->unk2064, 2);
	stream->unk3bb8 = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3bbc = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3bc0 = func000462c4(&stream->unk2024, &stream->unk2064, 2);
	stream->unk3bc4 = func000462c4(&stream->unk2024, &stream->unk2064, 2);
	stream->unk3bc8 = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3bcc = func000462c4(&stream->unk2024, &stream->unk2064, 1);
	stream->unk3bd0 = func000462c4(&stream->unk2024, &stream->unk2064, 2);

	if (stream->unk3bb0 == 15 || stream->unk3bb4 == 3) {
		return func00043ef8(stream, -1);
	}

	if (stream->unk3bd4 == 0) {
		stream->unk3bd4 = 1;
		stream->unk3bd8 = stream->unk3ba4;
		stream->unk3bdc = stream->unk3ba8;
		stream->unk3be0 = stream->unk3bac;
		stream->unk3be4 = stream->unk3bb4;
		stream->unk3be8 = stream->unk3bc0;
		stream->unk3bec = stream->unk3bc8;
		stream->unk3bf0 = stream->unk3bcc;
	} else if (stream->unk3ba4 != stream->unk3bd8
			|| stream->unk3ba8 != stream->unk3bdc
			|| stream->unk3bac != stream->unk3be0
			|| stream->unk3bb4 != stream->unk3be4
			|| stream->unk3bc0 != stream->unk3be8
			|| stream->unk3bcc != stream->unk3bf0) {
		return func00043ef8(stream, -1);
	}

	stream->unk2068 = 4;

	if (stream->unk3bac == 0) {
		sp1c = stream->unk04(stream->unk00, &stream->unk2024[4], 2, -1);

		if (sp1c < 1) {
			return 0;
		}

		stream->unk18 += 2;
		stream->unk2064 += 16;
		stream->unk2068 = 6;
	}

	if (stream->unk3ba8 == 1) {
		stream->unk8478 = func0004371c;
		stream->unk847c = func00042e38;
	} else if (stream->unk3ba8 == 2) {
		return 0;
	} else if (stream->unk3ba8 == 3) {
		return 0;
	}

	if (stream->unk847c(stream) == 0) {
		return 0;
	}

	return 1;
}

u32 func00044404(void)
{
	if (var8005f704++) {
		return 2;
	}

	func0003f8a0();
	return 0;
}

struct asistream *func00044460(s32 arg0, void *arg1, s32 arg2)
{
	struct asistream *stream = g_AsiStream;

	if (stream == NULL) {
		return NULL;
	}

	stream->unk0c = -1;
	stream->unk10 = -1;
	stream->unk14 = -1;

	stream->unk00 = arg0;
	stream->unk04 = arg1;
	stream->unk08 = arg2;

	stream->unk201c = 0;
	stream->unk2020 = 0;
	stream->unk3ba0 = 0;

	func00043ef8(stream, 0);

	stream->unk8474 = 0;

	bzero(&stream->unk6a64, sizeof(stream->unk6a64[0]));

	return stream;
}

s32 func0004453c(struct asistream *streamptr, struct mp3thing **arg1, s32 *arg2)
{
	struct asistream *stream = streamptr;
	s32 result;

	stream->unk3ba0++;

	if (stream->unk3ba0 > 5) {
		stream->unk3ba0 = 0;
	}

	if (!func00043ef8(stream, stream->unk8474)) {
		g_Mp3Vars.var8009c3e0 = 3;
		return 0;
	}

	stream->unk8474 = -1;

	result = stream->unk8478(stream);

	if (!result) {
		// empty
	} else {
		*arg1 = &stream->unk2070[stream->unk3ba0];
		*arg2 = stream->unk3f8c;
	}

	return result;
}
