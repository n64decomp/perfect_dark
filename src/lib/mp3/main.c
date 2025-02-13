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

u32 var8005f700 = 0;
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

	sp18 = stream->dmafunc(stream->unk00, &stream->unk1c[stream->unk201c], stream->unk3f88, -1);

	if (sp18 < stream->unk3f88) {
		bzero(&stream->unk1c[sp18], stream->unk3f88 - sp18);
	}

	stream->unk18 += stream->unk3f88;
	stream->unk201c += stream->unk3f88;

	return stream->unk201c - stream->unk3f88;
}

bool mp3main_read_frame(struct asistream *stream, s32 arg1)
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
		sp1c = stream->dmafunc(stream->unk00, &stream->buffer[sp20], 1, sp24);

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

	sp1c = stream->dmafunc(stream->unk00, &stream->buffer[2], 2, -1);

	if (sp1c <= 0) {
		return false;
	}

	stream->unk18 += 2;

	stream->offset = 12;

	stream->version = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->layer = mp3util_get_bits(stream->buffer, &stream->offset, 2);
	stream->crctype = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->bitrateindex = mp3util_get_bits(stream->buffer, &stream->offset, 4);
	stream->samplerateindex = mp3util_get_bits(stream->buffer, &stream->offset, 2);
	stream->haspadding = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->privatebit = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->channelmode = mp3util_get_bits(stream->buffer, &stream->offset, 2);
	stream->channelmodeext = mp3util_get_bits(stream->buffer, &stream->offset, 2);
	stream->copyright = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->isoriginal = mp3util_get_bits(stream->buffer, &stream->offset, 1);
	stream->emphasis = mp3util_get_bits(stream->buffer, &stream->offset, 2);

	if (stream->bitrateindex == 15 || stream->samplerateindex == 3) { /* bad/reserved values */
		return mp3main_read_frame(stream, -1);
	}

	if (!stream->doneinitial) {
		stream->doneinitial = true;

		stream->initialversion = stream->version;
		stream->initiallayer = stream->layer;
		stream->initialcrctype = stream->crctype;
		stream->initialsamplerateindex = stream->samplerateindex;
		stream->initialchannelmode = stream->channelmode;
		stream->initialcopyright = stream->copyright;
		stream->initialisoriginal = stream->isoriginal;
	} else if (stream->version != stream->initialversion
			|| stream->layer != stream->initiallayer
			|| stream->crctype != stream->initialcrctype
			|| stream->samplerateindex != stream->initialsamplerateindex
			|| stream->channelmode != stream->initialchannelmode
			|| stream->isoriginal != stream->initialisoriginal) {
		return mp3main_read_frame(stream, -1);
	}

	stream->unk2068 = 4;

	if (stream->crctype == CRC_PROTECTED) {
		sp1c = stream->dmafunc(stream->unk00, &stream->buffer[4], 2, -1);

		if (sp1c <= 0) {
			return false;
		}

		stream->unk18 += 2;
		stream->offset += 16;
		stream->unk2068 = 6;
	}

	if (stream->layer == LAYER_3) {
		stream->decodeframefunc = mp3dec_decode_frame;
		stream->setsideinfofunc = mp3dec_set_side_info;
	} else if (stream->layer == LAYER_2) {
		return false;
	} else if (stream->layer == LAYER_1) {
		return false;
	}

	if (!stream->setsideinfofunc(stream)) {
		return false;
	}

	return true;
}

/**
 * System initialisation (ie. called once at boot).
 */
u32 mp3main_init(void)
{
	if (var8005f704++) {
		return 2;
	}

	mp3dec_init();
	return 0;
}

struct asistream *mp3main_start_file(s32 arg0, void *dmafunc, s32 filesize)
{
	struct asistream *stream = g_AsiStream;

	if (stream == NULL) {
		return NULL;
	}

	stream->unk0c = -1;
	stream->unk10 = -1;
	stream->unk14 = -1;

	stream->unk00 = arg0;
	stream->dmafunc = dmafunc;
	stream->filesize = filesize;

	stream->unk201c = 0;
	stream->unk2020 = 0;
	stream->unk3ba0 = 0;

	mp3main_read_frame(stream, 0);

	stream->unk8474 = 0;

	bzero(&stream->unk6a64, sizeof(stream->unk6a64[0]));

	return stream;
}

s32 mp3main_continue_file(struct asistream *streamptr, u16 **arg1, s32 *numchannels)
{
	struct asistream *stream = streamptr;
	s32 result;

	stream->unk3ba0++;

	if (stream->unk3ba0 >= ARRAYCOUNT(stream->unk2070)) {
		stream->unk3ba0 = 0;
	}

	if (!mp3main_read_frame(stream, stream->unk8474)) {
		g_Mp3Vars.state = MP3STATE_STOPPED;
		return 0;
	}

	stream->unk8474 = -1;

	result = stream->decodeframefunc(stream);

	if (!result) {
		// empty
	} else {
		*arg1 = stream->unk2070[stream->unk3ba0];
		*numchannels = stream->numchannels;
	}

	return result;
}
