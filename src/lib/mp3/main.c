#include <ultra64.h>
#include "internal.h"
#include "mp3.h"

#define LAYER_3 1
#define LAYER_2 2
#define LAYER_1 3

#define CRC_PROTECTED   0
#define CRC_UNPROTECTED 1

extern struct mp3vars g_Mp3Vars;
extern struct asistream *g_AsiStream;

struct mp3decfourbytes var8009c650[34];
f32 *var8009c6d8;
f32 *var8009c6dc;

u32 var8005f704 = 0;

s32 mp3main00043dd0(struct asistream *stream)
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

static bool mp3main00043ef8(struct asistream *stream, s32 arg1)
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
		sp1c = stream->unk04(stream->unk00, &stream->buffer[sp20], 1, sp24);

		if (sp1c <= 0) {
			return false;
		}

		sp24 = -1;
		stream->unk18++;

		if ((stream->buffer[sp20] & mask) != mask) {
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

	sp1c = stream->unk04(stream->unk00, &stream->buffer[2], 2, -1);

	if (sp1c <= 0) {
		return false;
	}

	stream->unk18 += 2;
	stream->count = 12;

	stream->version = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->layer = mp3utilGetBits(stream->buffer, &stream->count, 2);
	stream->crctype = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->bitrateindex = mp3utilGetBits(stream->buffer, &stream->count, 4);
	stream->samplerateindex = mp3utilGetBits(stream->buffer, &stream->count, 2);
	stream->haspadding = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->privatebit = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->channelmode = mp3utilGetBits(stream->buffer, &stream->count, 2);

	stream->unk3bc4 = mp3utilGetBits(stream->buffer, &stream->count, 2);
	stream->unk3bc8 = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->unk3bcc = mp3utilGetBits(stream->buffer, &stream->count, 1);
	stream->unk3bd0 = mp3utilGetBits(stream->buffer, &stream->count, 2);

	if (stream->bitrateindex == 15 || stream->samplerateindex == 3) {
		return mp3main00043ef8(stream, -1);
	}

	if (!stream->doneinitial) {
		stream->doneinitial = true;

		stream->initialversion = stream->version;
		stream->initiallayer = stream->layer;
		stream->initialcrctype = stream->crctype;
		stream->initialsamplerateindex = stream->samplerateindex;
		stream->initialchannelmode = stream->channelmode;
		stream->unk3bec = stream->unk3bc8;
		stream->unk3bf0 = stream->unk3bcc;
	} else if (stream->version != stream->initialversion
			|| stream->layer != stream->initiallayer
			|| stream->crctype != stream->initialcrctype
			|| stream->samplerateindex != stream->initialsamplerateindex
			|| stream->channelmode != stream->initialchannelmode
			|| stream->unk3bcc != stream->unk3bf0) {
		return mp3main00043ef8(stream, -1);
	}

	stream->unk2068 = 4;

	if (stream->crctype == CRC_PROTECTED) {
		sp1c = stream->unk04(stream->unk00, &stream->buffer[4], 2, -1);

		if (sp1c <= 0) {
			return false;
		}

		stream->unk18 += 2;
		stream->count += 16;
		stream->unk2068 = 6;
	}

	if (stream->layer == LAYER_3) {
		stream->unk8478 = mp3decDecodeFrame;
		stream->unk847c = mp3decSetSideInfo;
	} else if (stream->layer == LAYER_2) {
		return false;
	} else if (stream->layer == LAYER_1) {
		return false;
	}

	if (stream->unk847c(stream) == 0) {
		return false;
	}

	return true;
}

u32 mp3mainInit(void)
{
	if (var8005f704++) {
		return 2;
	}

	mp3decInit();
	return 0;
}

struct asistream *mp3main00044460(s32 arg0, void *arg1, s32 arg2)
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

	mp3main00043ef8(stream, 0);

	stream->unk8474 = 0;

	bzero(&stream->unk6a64, sizeof(stream->unk6a64[0]));

	return stream;
}

s32 mp3main0004453c(struct asistream *streamptr, struct mp3thing **arg1, s32 *arg2)
{
	struct asistream *stream = streamptr;
	s32 result;

	stream->unk3ba0++;

	if (stream->unk3ba0 > 5) {
		stream->unk3ba0 = 0;
	}

	if (!mp3main00043ef8(stream, stream->unk8474)) {
		g_Mp3Vars.var8009c3e0 = 3;
		return 0;
	}

	stream->unk8474 = -1;

	result = stream->unk8478(stream);

	if (!result) {
		// empty
	} else {
		*arg1 = &stream->unk2070[stream->unk3ba0];
		*arg2 = stream->numchannels;
	}

	return result;
}
