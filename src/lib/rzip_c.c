// see https://github.com/n64decomp/007/blob/master/tools/mktex/src/libpdtex/reader.c
// and https://github.com/doomhack/perfect_dark/blob/master/src/lib/rzip.c

#include <zlib.h>

#include "lib/rzip.h"

void *var80091558; // g_RzipUnused

bool rzipIs1172(void *buffer)
{
	const u8* src = buffer;
	return (src[0] == 0x11 && src[1] == 0x72);
}

bool rzipIs1173(void *buffer)
{
	const u8* src = buffer;
	return (src[0] == 0x11 && src[1] == 0x73);
}

static inline s32 rzipInflate1172(z_stream *strm, u8 *src, void *dst)
{
	strm->avail_in = 0x2000;
	strm->next_in = src;

	do {
		strm->avail_out = 0x2000;
		strm->next_out = dst;
		if (inflate(strm, Z_FINISH) == Z_STREAM_ERROR) {
			rmonPrintf("rzipInflate1172: Z_STREAM_ERROR\n");
			return 0;
		}
	} while (strm->avail_out == 0);

	return strm->total_out;
}

static inline s32 rzipInflate1173(z_stream *strm, u8 *src, void *dst, u32 dstLen)
{
	strm->avail_in = -1; // compressed size unknown
	strm->next_in = src;
	strm->avail_out = dstLen;
	strm->next_out = dst;

	if (inflate(strm, Z_SYNC_FLUSH) == Z_STREAM_ERROR) {
		rmonPrintf("rzipInflate1173: Z_STREAM_ERROR\n");
		return 0;
	}

	return strm->total_out;
}

s32 rzipInflate(void *srcp, void *dst, void *scratch)
{
	s32 ret = 0;
	u8 *src = srcp;
	z_stream strm = { 0 };

	ret = inflateInit2(&strm, -15);
	if (ret != Z_OK) {
		rmonPrintf("rzipInflate: inflateInit2 failed: %d\n", ret);
		return 0;
	}

	if (rzipIs1173(src)) {
		// 1173, we know the uncompressed length
		const u32 dstLen = ((u32)src[2] << 16) | ((u32)src[3] << 8) | (u32)src[4];
		ret = rzipInflate1173(&strm, src + 5, dst, dstLen);
	} else if (rzipIs1172(src)) {
		// 1172, uncompressed length unknown
		ret = rzipInflate1172(&strm, src + 2, dst);
	} else {
		rmonPrintf("rzipInflate: input not in any known rare zip format\n");
		ret = 0;
	}

	inflateEnd(&strm);

	if (ret) {
		var80091558 = strm.next_in;
		return strm.total_out;
	} else {
		return 0;
	}
}

u32 rzipInit(void)
{
	// this builds tables in the original assembly version, we don't need that
	return 0;
}

void *rzipGetSomething(void)
{
	return var80091558;
}
