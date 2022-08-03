#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

struct texture *g_Textures;
u32 var800aabc4;
struct texturething var800aabc8;
struct texcacheitem g_TexCacheItems[150];
s32 g_TexCacheCount;
s32 var800ab53c;
u8 *var800ab540;
u32 var800ab544;
s32 var800ab548;
u32 var800ab54c;
u32 g_TexBase;
u8 *g_TextureConfigSegment;
s32 g_TexNumConfigs;
struct texloadthing **g_TexWords;
struct textureconfig *g_TexWallhitConfigs;
Gfx *g_TexGdl1;
Gfx *g_TexGdl2;
Gfx *g_TexGdl3;
struct texturepair *g_ExplosionTexturePairs;
struct textureconfig *g_TexBeamConfigs;
struct textureconfig *g_TexLaserConfigs;
struct textureconfig *g_TexGroup03Configs;
struct textureconfig *g_TexGeCrosshairConfigs;
struct textureconfig *g_TexRedLinesConfigs;
struct textureconfig *g_TexShadowConfigs;
struct textureconfig *g_TexShieldConfigs;
struct textureconfig *g_TexShardConfigs;
struct textureconfig *g_TexScreenConfigs;
struct textureconfig *g_TexWaterConfigs;
struct textureconfig *g_TexSkyConfigs;
struct textureconfig *g_TexLightGlareConfigs;
struct textureconfig *g_TexSparkConfigs;
struct textureconfig *g_TexGeneralConfigs;
struct textureconfig *g_TexRadarConfigs;

u32 var800841b0 = 0x0006ddd0;
u32 var800841b4 = 0x00000000;

// The number of channels, excluding 1-bit alpha channels.
s32 g_TexFormatNumChannels[] = { 4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1 };

// Whether each format supports a 1-bit alpha channel.
s32 g_TexFormatHas1BitAlpha[] = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

// For non-paletted images, size in decimal of each colour channel.
// Eg. 32 means each channel can store up to 32 values (5-bits per channel).
// For paletted images, same thing but for the palette indices instead.
s32 g_TexFormatChannelSizes[] = { 256, 32, 256, 32, 256, 16, 8, 256, 16, 256, 16, 256, 16 };

s32 g_TexFormatBitsPerPixel[] = { 32, 16, 24, 15, 16, 8, 4, 8, 4, 16, 16, 16, 16 };

// Mapping to GBI format
s32 g_TexFormatGbiMappings[] = {
	G_IM_FMT_RGBA,
	G_IM_FMT_RGBA,
	G_IM_FMT_RGBA,
	G_IM_FMT_RGBA,
	G_IM_FMT_IA,
	G_IM_FMT_IA,
	G_IM_FMT_IA,
	G_IM_FMT_I,
	G_IM_FMT_I,
	G_IM_FMT_CI,
	G_IM_FMT_CI,
	G_IM_FMT_CI,
	G_IM_FMT_CI,
};

s32 g_TexFormatDepths[] = {
	G_IM_SIZ_32b,
	G_IM_SIZ_16b,
	G_IM_SIZ_32b,
	G_IM_SIZ_16b,
	G_IM_SIZ_16b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
};

s32 g_TexFormatLutModes[] = {
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_RGBA16,
	G_TT_RGBA16,
	G_TT_IA16,
	G_TT_IA16,
};

void func0f16e810(u32 arg0)
{
	// empty
}

/**
 * Inflate images (levels of detail) from a zlib-compressed texture.
 *
 * Zlib-compressed textures are always paletted and always use 16-bit colours.
 * The texture header contains palette information, then each image follows with
 * its own header and zlib compresed data.
 *
 * The texture header is:
 *
 * ffffffff nnnnnnnn [palette]
 *
 * f = pixel format (see TEXFORMAT constants)
 * n = number of colours in the palette minus 1
 * [palette] = 16 bits * number of colours
 *
 * Each images's header is:
 *
 * wwwwwwww hhhhhhhh [data]
 *
 * w = width in pixels
 * h = height in pixels
 * [data] = zlib compressed list of indices into the palette
 *
 * The zlib data is prefixed with the standard 5-byte rarezip header.
 */
s32 texInflateZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texturething *arg4, s32 arg5)
{
	s32 i;
	s32 imagebytesout;
	s32 numimages;
	bool writetocache;
	s32 format;
	bool foundthething;
	s32 totalbytesout;
	s32 width;
	s32 height;
	s32 numcolours;
	u8 *end;
	u8 *start;
	s32 j;
	u8 scratch2[0x800];
	u16 palette[256];
	u8 scratch[5120];

	writetocache = false;
	totalbytesout = 0;

	texSetBitstring(src);

	if (arg2 && forcenumimages) {
		numimages = forcenumimages;
	} else {
		numimages = 1;
	}

	arg4->unk0c->maxlod = forcenumimages;
	arg4->unk0c->unk0c_02 = arg2;

	if (arg2) {
		writetocache = true;

		for (i = 0; i < g_TexCacheCount; i++) {
			if (g_TexCacheItems[i].texturenum == arg4->unk0c->texturenum) {
				writetocache = false;
			}
		}
	}

	format = texReadBits(8);
	numcolours = texReadBits(8) + 1;

	for (i = 0; i < numcolours; i++) {
		palette[i] = texReadBits(16);
	}

	foundthething = false;

	for (j = 0; j < numimages; j++) {
		width = texReadBits(8);
		height = texReadBits(8);

		if (j == 0) {
			arg4->unk0c->width = width;
			arg4->unk0c->height = height;
			arg4->unk0c->unk0a = numcolours - 1;
			arg4->unk0c->gbiformat = g_TexFormatGbiMappings[format];
			arg4->unk0c->depth = g_TexFormatDepths[format];
			arg4->unk0c->lutmodeindex = g_TexFormatLutModes[format] >> G_MDSFT_TEXTLUT;
		} else if (writetocache) {
			g_TexCacheItems[g_TexCacheCount].widths[j - 1] = width;
			g_TexCacheItems[g_TexCacheCount].heights[j - 1] = height;
		}

		if (rzipInflate(var800ab540, scratch2, scratch) == 0) {
#if VERSION < VERSION_NTSC_1_0
			char message[128];
			sprintf(message, "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
					"texdecompress.c", 357,
					var800ab540[0], var800ab540[1], var800ab540[2], var800ab540[3],
					var800ab540[4], var800ab540[5], var800ab540[6], var800ab540[7],
					var800ab540[8], var800ab540[9], var800ab540[10], var800ab540[11],
					var800ab540[12], var800ab540[13], var800ab540[14], var800ab540[15]);
			crashSetMessage(message);
			CRASH();
#endif
		}

		imagebytesout = texAlignIndices(scratch2, width, height, format, &dst[totalbytesout]);
		texSetBitstring(rzipGetSomething());

		if (arg2 == 1) {
			if (IS4MB() && j == 2 && !foundthething) {
				arg4->unk0c->maxlod = j;
				foundthething = true;
			}

			if (totalbytesout + imagebytesout > 0x800 || foundthething) {
				if (!foundthething) {
					arg4->unk0c->maxlod = j;
					foundthething = true;
				}
			} else {
				texSwapAltRowBytes(&dst[totalbytesout], width, height, format);
				totalbytesout += imagebytesout;
			}
		} else {
			totalbytesout += imagebytesout;
		}
	}

	if (writetocache) {
		g_TexCacheItems[g_TexCacheCount].texturenum = arg4->unk0c->texturenum;

		g_TexCacheCount++;

		if (g_TexCacheCount >= ARRAYCOUNT(g_TexCacheItems)) {
			g_TexCacheCount = 0;
		}
	}

	if (!arg2) {
		if (forcenumimages >= 2) {
			s32 tmpwidth = width;
			s32 tmpheight = height;

			start = dst;
			end = &dst[totalbytesout];

			for (j = 1; j < forcenumimages; j++) {
				imagebytesout = texShrinkPaletted(start, end, tmpwidth, tmpheight, format, palette, numcolours);

				if (IS4MB() && j == 2) {
					arg4->unk0c->maxlod = j;
					break;
				}

				if (totalbytesout + imagebytesout > 0x800) {
					arg4->unk0c->maxlod = j;
					break;
				}

				texSwapAltRowBytes(start, tmpwidth, tmpheight, format);

				totalbytesout += imagebytesout;

				tmpwidth = (tmpwidth + 1) >> 1;
				tmpheight = (tmpheight + 1) >> 1;

				start = end;
				end += imagebytesout;
			}

			texSwapAltRowBytes(start, tmpwidth, tmpheight, format);
		} else {
			texSwapAltRowBytes(dst, width, height, format);
		}
	}

	for (i = 0; i < numcolours; i++) {
		dst[totalbytesout + 0] = palette[i] >> 8;
		dst[totalbytesout + 1] = palette[i] & 0xff;
		totalbytesout += 2;
	}

	if (numcolours & 1) {
#if VERSION < VERSION_NTSC_1_0
		u32 stack;
#endif

		dst[totalbytesout + 0] = dst[totalbytesout - 2];
		dst[totalbytesout + 1] = dst[totalbytesout - 1];
		totalbytesout += 2;
		arg4->unk0c->unk0a++;
	}

	totalbytesout = (totalbytesout + 7) & ~7;

	return totalbytesout;
}

/**
 * Copy a list of palette indices to the dst buffer, but ensure each row is
 * aligned to an 8 byte boundary.
 *
 * Return the number of output bytes.
 */
s32 texAlignIndices(u8 *src, s32 width, s32 height, s32 format, u8 *dst)
{
	u8 *outptr = dst;
	s32 x;
	s32 y;
	s32 indicesperbyte;

	if (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_IA16_CI8) {
		indicesperbyte = 1;
	} else if (format == TEXFORMAT_RGBA16_CI4 || format == TEXFORMAT_IA16_CI4) {
		indicesperbyte = 2;
	}

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x += indicesperbyte) {
			*outptr = *src;
			outptr++;
			src++;
		}

		outptr = (u8 *)(((u32)outptr + 7) & ~7);
	}

	return outptr - dst;
}

s32 texGetAverageRed(u16 colour1, u16 colour2, u16 colour3, u16 colour4)
{
	s32 value = 0;

	value += ((colour1 >> 11) & 0x1f) << 3 | (colour1 >> 13) & 7;
	value += ((colour2 >> 11) & 0x1f) << 3 | (colour2 >> 13) & 7;
	value += ((colour3 >> 11) & 0x1f) << 3 | (colour3 >> 13) & 7;
	value += ((colour4 >> 11) & 0x1f) << 3 | (colour4 >> 13) & 7;

	value = (value + 2) >> 2;

	if (value < 0) {
		value = 0;
	}

	if (value > 0xff) {
		value = 0xff;
	}

	return value;
}

s32 texGetAverageGreen(u16 colour1, u16 colour2, u16 colour3, u16 colour4)
{
	s32 value = 0;

	value += ((colour1 >> 6) & 0x1f) << 3 | (colour1 >> 8) & 7;
	value += ((colour2 >> 6) & 0x1f) << 3 | (colour2 >> 8) & 7;
	value += ((colour3 >> 6) & 0x1f) << 3 | (colour3 >> 8) & 7;
	value += ((colour4 >> 6) & 0x1f) << 3 | (colour4 >> 8) & 7;

	value = (value + 2) >> 2;

	if (value < 0) {
		value = 0;
	}

	if (value > 0xff) {
		value = 0xff;
	}

	return value;
}

s32 texGetAverageBlue(u16 colour1, u16 colour2, u16 colour3, u16 colour4)
{
	s32 value = 0;

	value += ((colour1 >> 1) & 0x1f) << 3 | (colour1 >> 3) & 7;
	value += ((colour2 >> 1) & 0x1f) << 3 | (colour2 >> 3) & 7;
	value += ((colour3 >> 1) & 0x1f) << 3 | (colour3 >> 3) & 7;
	value += ((colour4 >> 1) & 0x1f) << 3 | (colour4 >> 3) & 7;

	value = (value + 2) >> 2;

	if (value < 0) {
		value = 0;
	}

	if (value > 0xff) {
		value = 0xff;
	}

	return value;
}

s32 texGetAverageAlpha(u16 colour1, u16 colour2, u16 colour3, u16 colour4)
{
	s32 value = 0
		+ (colour1 & 1 ? 0xff : 0)
		+ (colour2 & 1 ? 0xff : 0)
		+ (colour3 & 1 ? 0xff : 0)
		+ (colour4 & 1 ? 0xff : 0);

	value = (value + 2) >> 2;

	if (value < 0) {
		value = 0;
	}

	if (value > 0xff) {
		value = 0xff;
	}

	return value;
}

/**
 * Shrink a paletted texture to half its size by averaging each each 2x2 group
 * of pixels.
 *
 * Return the number of bytes written.
 */
s32 texShrinkPaletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format, u16 *palette, s32 numcolours)
{
	s32 j;
	s32 i;
	s32 alignedsrcwidth;
	s32 aligneddstwidth;
	s32 dstheight = (srcheight + 1) >> 1;
	u16 colour1;
	u16 colour2;
	u16 colour3;
	u16 colour4;
	s32 r;
	s32 g;
	s32 b;
	s32 a;
	s32 nextrow;
	s32 nextcol;
	s32 c;
	u8 *dst8;
	u8 *src8;
	u8 palette32[1024];

	switch (format) {
	case TEXFORMAT_RGBA16_CI8:
	case TEXFORMAT_IA16_CI8:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 7) & 0xff8;
		alignedsrcwidth = (srcwidth + 7) & 0xff8;
		break;
	case TEXFORMAT_RGBA16_CI4:
	case TEXFORMAT_IA16_CI4:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 15) & 0xff0;
		alignedsrcwidth = (srcwidth + 15) & 0xff0;
		break;
	}

	if (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_RGBA16_CI4) {
		for (i = 0; i < numcolours; i++) {
			colour1 = palette[i];

			palette32[i * 4 + 0] = ((((colour1 >> 11) & 0x1f) * 8) | ((colour1 >> 13) & 7));
			palette32[i * 4 + 1] = ((((colour1 >> 6) & 0x1f) * 8) | ((colour1 >> 8) & 7));
			palette32[i * 4 + 2] = ((((colour1 >> 1) & 0x1f) * 8) | ((colour1 >> 3) & 7));
			palette32[i * 4 + 3] = ((colour1 & 1) ? 0xff : 0);
		}
	}

	dst8 = dst;
	src8 = src;

	switch (format) {
	case TEXFORMAT_RGBA16_CI8:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				colour1 = palette[src8[j]];
				colour2 = palette[src8[nextcol]];
				colour3 = palette[src8[nextrow + j]];
				colour4 = palette[src8[nextrow + nextcol]];

				r = texGetAverageRed(colour1, colour2, colour3, colour4);
				g = texGetAverageGreen(colour1, colour2, colour3, colour4);
				b = texGetAverageBlue(colour1, colour2, colour3, colour4);
				a = texGetAverageAlpha(colour1, colour2, colour3, colour4);

				dst8[j >> 1] = texFindClosestColourIndexRGBA(palette32, numcolours, r, g, b, a);
			}

			dst8 += aligneddstwidth;
			src8 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth;
	case TEXFORMAT_IA16_CI8:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				colour1 = palette[src8[j]];
				colour2 = palette[src8[nextcol]];
				colour3 = palette[src8[nextrow + j]];
				colour4 = palette[src8[nextrow + nextcol]];

				c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
				a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

				dst8[j >> 1] = texFindClosestColourIndexIA(palette, numcolours, c, a);
			}

			dst8 += aligneddstwidth;
			src8 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth;
	case TEXFORMAT_RGBA16_CI4:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth >> 1 : 0;

			for (j = 0; j < alignedsrcwidth; j += 4) {
				colour1 = palette[(src8[j >> 1] >> 4) & 0xf];
				colour2 = palette[src8[j >> 1] >> ((j + 1 < srcwidth ? 0 : 4)) & 0xf];
				colour3 = palette[(src8[nextrow + (j >> 1)] >> 4) & 0xf];
				colour4 = palette[src8[nextrow + (j >> 1)] >> ((j + 1 < srcwidth ? 0 : 4)) & 0xf];

				r = texGetAverageRed(colour1, colour2, colour3, colour4);
				g = texGetAverageGreen(colour1, colour2, colour3, colour4);
				b = texGetAverageBlue(colour1, colour2, colour3, colour4);
				a = texGetAverageAlpha(colour1, colour2, colour3, colour4);

				dst8[j >> 2] = texFindClosestColourIndexRGBA(palette32, numcolours, r, g, b, a) << 4;

				colour1 = palette[(src8[(j + 2) >> 1] >> 4) & 0xf];
				colour2 = palette[(src8[(j + 2) >> 1] >> (j + 3 < srcwidth ? 0 : 4)) & 0xf];
				colour3 = palette[(src8[nextrow + ((j + 2) >> 1)] >> 4) & 0xf];
				colour4 = palette[(src8[nextrow + ((j + 2) >> 1)] >> (j + 3 < srcwidth ? 0 : 4)) & 0xf];

				r = texGetAverageRed(colour1, colour2, colour3, colour4);
				g = texGetAverageGreen(colour1, colour2, colour3, colour4);
				b = texGetAverageBlue(colour1, colour2, colour3, colour4);
				a = texGetAverageAlpha(colour1, colour2, colour3, colour4);

				dst8[j >> 2] |= texFindClosestColourIndexRGBA(palette32, numcolours, r, g, b, a) & 0xff;
			}

			dst8 += aligneddstwidth >> 1;
			src8 += alignedsrcwidth;
		}

		return (aligneddstwidth >> 1) * dstheight;
	case TEXFORMAT_IA16_CI4:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth >> 1 : 0;

			for (j = 0; j < alignedsrcwidth; j += 4) {
				// @bug: The brackets are wrong in colour2 and colour4 which
				// causes the index shift to be part of the ternary condition.
				// It's done correctly in TEXFORMAT_RGBA16_CI4 (above).
				// This buggy calculation is repeated further below.
				colour1 = palette[(src8[j >> 1] >> 4) & 0xf];
				colour2 = palette[(src8[j >> 1] >> (j + 1 < srcwidth) ? 0 : 4) & 0xf];
				colour3 = palette[(src8[nextrow + (j >> 1)] >> 4) & 0xf];
				colour4 = palette[(src8[nextrow + (j >> 1)] >> (j + 1 < srcwidth) ? 0 : 4) & 0xf];

				c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
				a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

				dst8[j >> 2] = texFindClosestColourIndexIA(palette, numcolours, c, a) << 4;

				colour1 = palette[(src8[(j + 2) >> 1] >> 4) & 0xf];
				colour2 = palette[(src8[(j + 2) >> 1] >> (j + 3 < srcwidth) ? 0 : 4) & 0xf];
				colour3 = palette[(src8[nextrow + ((j + 2) >> 1)] >> 4) & 0xf];
				colour4 = palette[(src8[nextrow + ((j + 2) >> 1)] >> (j + 3 < srcwidth) ? 0 : 4) & 0xf];

				c = ((((colour1 >> 8) & 0xff) + ((colour2 >> 8) & 0xff) + ((colour3 >> 8) & 0xff) + ((colour4 >> 8) & 0xff)) >> 2) & 0xff;
				a = ((((colour1 >> 0) & 0xff) + ((colour2 >> 0) & 0xff) + ((colour3 >> 0) & 0xff) + ((colour4 >> 0) & 0xff) + 1) >> 2) & 0xff;

				dst8[j >> 2] |= texFindClosestColourIndexIA(palette, numcolours, c, a) & 0xff;
			}

			dst8 += aligneddstwidth >> 1;
			src8 += alignedsrcwidth;
		}

		return (aligneddstwidth >> 1) * dstheight;
	}

	return 0;
}

s32 texFindClosestColourIndexRGBA(u8 *palette, s32 numcolours, s32 r, s32 g, s32 b, s32 a)
{
	s32 minindex = 0;
	s32 minvalue = 99999999;
	s32 curvalue;
	s32 tmp;
	s32 i;

	for (i = 0; i < numcolours; i++) {
		tmp = palette[i * 4 + 0] - r;
		curvalue = tmp * tmp;

		tmp = palette[i * 4 + 1] - g;
		curvalue += tmp * tmp;

		tmp = palette[i * 4 + 2] - b;
		curvalue += tmp * tmp;

		tmp = palette[i * 4 + 3] - a;
		curvalue += tmp * tmp;

		if (curvalue < minvalue) {
			minindex = i;
			minvalue = curvalue;
		}
	}

	return minindex;
}

s32 texFindClosestColourIndexIA(u16 *palette, s32 numcolours, s32 intensity, s32 alpha)
{
	s32 bestindex = 0;
	s32 bestvalue = 99999999;
	s32 i;

	for (i = 0; i < numcolours; i++) {
		s32 value = palette[i];
		s32 a = ((value >> 8) & 0xff) - intensity;
		s32 b = (value & 0xff) - alpha;
		s32 sum = a * a + b * b;

		if (sum < bestvalue) {
			bestindex = i;
			bestvalue = sum;
		}
	}

	return bestindex;
}

/**
 * Inflate images (levels of detail) from a non-zlib texture.
 *
 * Each image can have a different compression method and pixel format,
 * which is described in a three byte header per image:
 *
 * ffffwwww wwwwhhhh hhhhcccc
 *
 * f = pixel format (see TEXFORMAT constants)
 * w = width in pixels
 * h = height in pixels
 * c = compression method (see TEXCOMPMETHOD constants)
 */
s32 texInflateNonZlib(u8 *src, u8 *dst, s32 arg2, s32 forcenumimages, struct texturething *arg4, s32 arg5)
{
	u8 scratch[0x2000];
	u8 lookup[0x1000];
	u32 stack;
	s32 i;
	s32 numimages;
	s32 width;
	s32 height;
	s32 compmethod;
	s32 j;
	s32 totalbytesout = 0;
	s32 imagebytesout;
	s32 format;
	s32 value;
	u8 *start;
	u8 *end;
	bool writetocache = false;

	texSetBitstring(src);

	numimages = arg2 && forcenumimages ? forcenumimages : 1;

	arg4->unk0c->maxlod = forcenumimages;
	arg4->unk0c->unk0c_02 = arg2;

	if (arg2) {
		writetocache = true;

		for (i = 0; i < g_TexCacheCount; i++) {
			if (g_TexCacheItems[i].texturenum == arg4->unk0c->texturenum) {
				writetocache = false;
			}
		}
	}

	for (i = 0; i < numimages; i++) {
		format = texReadBits(4);
		width = texReadBits(8);
		height = texReadBits(8);
		compmethod = texReadBits(4);

		if (i == 0) {
			arg4->unk0c->width = width;
			arg4->unk0c->height = height;
			arg4->unk0c->gbiformat = g_TexFormatGbiMappings[format];
			arg4->unk0c->depth = g_TexFormatDepths[format];
			arg4->unk0c->lutmodeindex = g_TexFormatLutModes[format] >> G_MDSFT_TEXTLUT;
		} else if (writetocache) {
			g_TexCacheItems[g_TexCacheCount].widths[i - 1] = width;
			g_TexCacheItems[g_TexCacheCount].heights[i - 1] = height;
		}

		if (width * height > 0x2000) {
			return 0;
		}

		switch (compmethod) {
		case TEXCOMPMETHOD_UNCOMPRESSED0:
		case TEXCOMPMETHOD_UNCOMPRESSED1:
			imagebytesout = texReadUncompressed(&dst[totalbytesout], width, height, format);
			break;
		case TEXCOMPMETHOD_HUFFMAN:
			texInflateHuffman(scratch, g_TexFormatNumChannels[format] * width * height, g_TexFormatChannelSizes[format]);

			if (g_TexFormatHas1BitAlpha[format]) {
				texReadAlphaBits(&scratch[width * height * 3], width * height);
			}

			imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
			break;
		case TEXCOMPMETHOD_HUFFMANPERHCHANNEL:
			for (j = 0; j < g_TexFormatNumChannels[format]; j++) {
				texInflateHuffman(&scratch[width * height * j], width * height, g_TexFormatChannelSizes[format]);
			}

			if (g_TexFormatHas1BitAlpha[format]) {
				texReadAlphaBits(&scratch[width * height * 3], width * height);
			}

			imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
			break;
		case TEXCOMPMETHOD_RLE:
			texInflateRle(scratch, g_TexFormatNumChannels[format] * width * height);

			if (g_TexFormatHas1BitAlpha[format]) {
				texReadAlphaBits(&scratch[width * height * 3], width * height);
			}

			imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
			break;
		case TEXCOMPMETHOD_LOOKUP:
			value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
			imagebytesout = texInflateLookup(width, height, &dst[totalbytesout], lookup, value, format);
			break;
		case TEXCOMPMETHOD_HUFFMANLOOKUP:
			value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
			texInflateHuffman(scratch, width * height, value);
			imagebytesout = texInflateLookupFromBuffer(scratch, width, height, &dst[totalbytesout], lookup, value, format);
			break;
		case TEXCOMPMETHOD_RLELOOKUP:
			value = texBuildLookup(lookup, g_TexFormatBitsPerPixel[format]);
			texInflateRle(scratch, width * height);
			imagebytesout = texInflateLookupFromBuffer(scratch, width, height, &dst[totalbytesout], lookup, value, format);
			break;
		case TEXCOMPMETHOD_HUFFMANBLUR:
			value = texReadBits(3);
			texInflateHuffman(scratch, g_TexFormatNumChannels[format] * width * height, g_TexFormatChannelSizes[format]);
			texBlur(scratch, width, g_TexFormatNumChannels[format] * height, value, g_TexFormatChannelSizes[format]);

			if (g_TexFormatHas1BitAlpha[format]) {
				texReadAlphaBits(&scratch[width * height * 3], width * height);
			}

			imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
			break;
		case TEXCOMPMETHOD_RLEBLUR:
			value = texReadBits(3);
			texInflateRle(scratch, g_TexFormatNumChannels[format] * width * height);
			texBlur(scratch, width, g_TexFormatNumChannels[format] * height, value, g_TexFormatChannelSizes[format]);

			if (g_TexFormatHas1BitAlpha[format]) {
				texReadAlphaBits(&scratch[width * height * 3], width * height);
			}

			imagebytesout = texChannelsToPixels(scratch, width, height, &dst[totalbytesout], format);
			break;
		}

		if (arg2 == 1) {
			texSwapAltRowBytes(&dst[totalbytesout], width, height, format);
		}

		imagebytesout = (imagebytesout + 7) & ~7;
		totalbytesout += imagebytesout;

		if (var800ab548 == 0) {
			var800ab540++;
		} else {
			var800ab548 = 0;
		}
	}

	if (writetocache) {
		g_TexCacheItems[g_TexCacheCount].texturenum = arg4->unk0c->texturenum;

		g_TexCacheCount++;

		// Resetting this variable to 0 here suggests that the g_TexCacheItems
		// array is used in a circular manner, and that g_TexCacheCount is just
		// the index of the oldest/next element. But earlier in this function
		// there's a loop that iterates up to g_TexCacheCount, which doesn't
		// make any sense if this value is used as a pointer in a circular list.
		// Could be a @bug, or maybe they intended to reset the cache every time
		// it fills up.
		if (g_TexCacheCount >= ARRAYCOUNT(g_TexCacheItems)) {
			g_TexCacheCount = 0;
		}
	}

	if (!arg2) {
		if (forcenumimages >= 2) {
			s32 tmpwidth = width;
			s32 tmpheight = height;

			start = dst;
			if (1);
			end = &dst[totalbytesout];

			for (i = 1; i < forcenumimages; i++) {
				imagebytesout = texShrinkNonPaletted(start, end, tmpwidth, tmpheight, format);

				texSwapAltRowBytes(start, tmpwidth, tmpheight, format);

				totalbytesout += imagebytesout;

				tmpwidth = (tmpwidth + 1) >> 1;
				tmpheight = (tmpheight + 1) >> 1;

				start = end;
				end += imagebytesout;
			}

			texSwapAltRowBytes(start, tmpwidth, tmpheight, format);
		} else {
			texSwapAltRowBytes(dst, width, height, format);
		}
	}

	return totalbytesout;
}

/**
 * Shrink a non-paletted texture to half its size by averaging each each 2x2
 * group of pixels.
 *
 * Return the number of bytes written.
 *
 * If the source width is an odd number, the destination's final column is
 * calculated by sampling the final source column twice. Likewise for the height.
 */
s32 texShrinkNonPaletted(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format)
{
	s32 i;
	s32 j;
	s32 alignedsrcwidth;
	s32 aligneddstwidth;
	u32 *dst32 = (u32 *) dst;
	u16 *dst16 = (u16 *) dst;
	u8 *dst8 = dst;
	u32 *src32 = (u32 *) src;
	u16 *src16 = (u16 *) src;
	u8 *src8 = src;
	s32 dstheight = (srcheight + 1) >> 1;
	s32 r;
	s32 g;
	s32 b;
	s32 a;
	s32 c;
	u32 tl32;
	u32 tr32;
	u32 bl32;
	u32 br32;
	u16 tl16;
	u16 tr16;
	u16 bl16;
	u16 br16;
	u8 tl8;
	u8 tr8;
	u8 bl8;
	u8 br8;
	s32 nextrow;
	s32 nextcol;

	switch (format) {
	case TEXFORMAT_RGBA32:
	case TEXFORMAT_RGB24:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 3) & 0xffc;
		alignedsrcwidth = (srcwidth + 3) & 0xffc;
		break;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_RGB15:
	case TEXFORMAT_IA16:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 3) & 0xffc;
		alignedsrcwidth = (srcwidth + 3) & 0xffc;
		break;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 7) & 0xff8;
		alignedsrcwidth = (srcwidth + 7) & 0xff8;
		break;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		aligneddstwidth = (((srcwidth + 1) >> 1) + 15) & 0xff0;
		alignedsrcwidth = (srcwidth + 15) & 0xff0;
		break;
	}

	switch (format) {
	case TEXFORMAT_RGBA32:
	case TEXFORMAT_RGB24:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				tl32 = src32[j];
				tr32 = src32[nextcol];
				bl32 = src32[nextrow + j];
				br32 = src32[nextrow + nextcol];

				r = ((((tl32 >> 24) & 0xff) + ((tr32 >> 24) & 0xff) + ((bl32 >> 24) & 0xff) + ((br32 >> 24) & 0xff)) >> 2) & 0xff;
				g = ((((tl32 >> 16) & 0xff) + ((tr32 >> 16) & 0xff) + ((bl32 >> 16) & 0xff) + ((br32 >> 16) & 0xff)) >> 2) & 0xff;
				b = ((((tl32 >>  8) & 0xff) + ((tr32 >>  8) & 0xff) + ((bl32 >>  8) & 0xff) + ((br32 >>  8) & 0xff)) >> 2) & 0xff;
				a = ((((tl32 >>  0) & 0xff) + ((tr32 >>  0) & 0xff) + ((bl32 >>  0) & 0xff) + ((br32 >>  0) & 0xff) + 1) >> 2) & 0xff;

				dst32[j >> 1] = r << 24 | g << 16 | b << 8 | a;
			}

			dst32 += aligneddstwidth;
			src32 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_RGB15:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				tl16 = src16[j];
				tr16 = src16[nextcol];
				bl16 = src16[nextrow + j];
				br16 = src16[nextrow + nextcol];

				r = ((((tl16 >> 11) & 0x1f) + ((tr16 >> 11) & 0x1f) + ((bl16 >> 11) & 0x1f) + ((br16 >> 11) & 0x1f)) >> 2) & 0x1f;
				g = ((((tl16 >>  6) & 0x1f) + ((tr16 >>  6) & 0x1f) + ((bl16 >>  6) & 0x1f) + ((br16 >>  6) & 0x1f)) >> 2) & 0x1f;
				b = ((((tl16 >>  1) & 0x1f) + ((tr16 >>  1) & 0x1f) + ((bl16 >>  1) & 0x1f) + ((br16 >>  1) & 0x1f)) >> 2) & 0x1f;
				a = ((((tl16 >>  0) & 0x01) + ((tr16 >>  0) & 0x01) + ((bl16 >>  0) & 0x01) + ((br16 >>  0) & 0x01) + 2) >> 2) & 0x01;

				dst16[j >> 1] = r << 11 | g << 6 | b << 1 | a;
			}

			dst16 += aligneddstwidth;
			src16 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth * 2;
	case TEXFORMAT_IA16:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				tl16 = src16[j];
				tr16 = src16[nextcol];
				bl16 = src16[nextrow + j];
				br16 = src16[nextrow + nextcol];

				c = ((tl16 >> 8) & 0xff) + ((tr16 >> 8) & 0xff) + ((bl16 >> 8) & 0xff) + ((br16 >> 8) & 0xff) + 2;
				c = c >> 2;

				if (c < 0) {
					c = 0;
				}

				if (c > 0xff) {
					c = 0xff;
				}

				a = (tl16 & 0xff) + (tr16 & 0xff) + (bl16 & 0xff) + (br16 & 0xff) + 2; // optimised out

				// @bug: Should be a >> 2
				a = c >> 2;

				if (a < 0) {
					a = 0;
				}

				if (a > 0xff) {
					a = 0xff;
				}

				dst16[j >> 1] = c << 8 | a;
			}

			dst16 += aligneddstwidth;
			src16 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth * 2;
	case TEXFORMAT_IA8:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				tl8 = src8[j];
				tr8 = src8[nextcol];
				bl8 = src8[nextrow + j];
				br8 = src8[nextrow + nextcol];

				c = (((tl8 >> 4) & 0xf) + ((tr8 >> 4) & 0xf) + ((bl8 >> 4) & 0xf) + ((br8 >> 4) & 0xf) + 2) >> 2;

				if (c < 0) {
					c = 0;
				}

				if (c > 0xf) {
					c = 0xf;
				}

				c <<= 4;

				a = ((tl8 & 0xf) + (tr8 & 0xf) + (bl8 & 0xf) + (br8 & 0xf) + 2) >> 2;

				if (a < 0) {
					a = 0;
				}

				if (a > 0xf) {
					a = 0xf;
				}

				dst8[j >> 1] = c | a;
			}

			dst8 += aligneddstwidth;
			src8 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth;
	case TEXFORMAT_I8:
		for (i = 0; i < srcheight; i += 2) {
			nextrow = i + 1 < srcheight ? alignedsrcwidth : 0;

			for (j = 0; j < alignedsrcwidth; j += 2) {
				nextcol = j + 1 < srcwidth ? j + 1 : j;

				// @bug: The code reads from uninitialised variable br8.
				// This is assumed to be due to a double write to bl8 as shown:
				tl8 = src8[j];
				tr8 = src8[nextcol];
				bl8 = src8[nextrow + j]; // optimised out
				bl8 = src8[nextrow + nextcol];

				c = (tl8 + tr8 + bl8 + br8 + 2) >> 2;

				if (c < 0) {
					c = 0;
				}

				if (c > 0xff) {
					c = 0xff;
				}

				dst8[j >> 1] = c;
			}

			dst8 += aligneddstwidth;
			src8 += alignedsrcwidth * 2;
		}

		return dstheight * aligneddstwidth;
	case TEXFORMAT_IA4:
		for (i = 0; i < srcheight; i += 2) {
			nextcol = i + 1;

			for (j = 0; j < alignedsrcwidth; j += 4) {
				tl8 = src8[j >> 1];
				tr8 = src8[(nextcol < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1)];
				bl8 = src8[(j >> 1) + 1];
				br8 = src8[(nextcol < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1) + 1];

				c = (((((tl8 >> 5) & 7) + ((tl8 >> 1) & 7) + ((tr8 >> 5) & 7) + ((tr8 >> 1) & 7)) << 3) & 0xe0)
					| (((((bl8 >> 5) & 7) + ((bl8 >> 1) & 7) + ((br8 >> 5) & 7) + ((br8 >> 1) & 7)) >> 1) & 0xe);

				a = (((((tl8 >> 4) & 1) + (tl8 & 1) + ((tr8 >> 4) & 1) + (tr8 & 1) + 1) << 2) & 0x10)
					| (((((bl8 >> 4) & 1) + (bl8 & 1) + ((br8 >> 4) & 1) + (br8 & 1) + 1) >> 2) & 1);

				dst8[j >> 2] = c | a;
			}

			dst8 += aligneddstwidth >> 1;
			src8 += alignedsrcwidth;
		}

		return (aligneddstwidth >> 1) * dstheight;
	case TEXFORMAT_I4:
		for (i = 0; i < srcheight; i += 2) {
			for (j = 0; j < alignedsrcwidth; j += 4) {
				tl8 = src8[j >> 1];
				tr8 = src8[(i + 1 < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1)];
				bl8 = src8[(j >> 1) + 1];
				br8 = src8[(i + 1 < srcheight ? (alignedsrcwidth >> 1) : 0) + (j >> 1) + 1];

				c = ((((tl8 >> 4) & 0xf) + (tl8 & 0xf) + ((tr8 >> 4) & 0xf) + (tr8 & 0xf)) << 2) & 0xf0;
				a = ((((bl8 >> 4) & 0xf) + (bl8 & 0xf) + ((br8 >> 4) & 0xf) + (br8 & 0xf)) >> 2) & 0xf;

				dst8[j >> 2] = c | a;
			}

			dst8 += aligneddstwidth >> 1;
			src8 += alignedsrcwidth;
		}

		return (aligneddstwidth >> 1) * dstheight;
	}

	return 0;
}

/**
 * Inflate Huffman data.
 *
 * This function operates on single channels rather than whole colours.
 * For example, for an RGBA32 image this function may be called once for each
 * channel with chansize = 256. This means the resulting data is in the format
 * RRR...GGG...BBB...AAA..., and the caller must convert it into a proper pixel
 * format.
 *
 * A typical Huffman implementation stores a tree, where each node contains
 * the lookup value and its frequency (number of uses). However, Rare's
 * implementation only stores a list of frequencies. It uses the chansize
 * to know how many values there are.
 */
void texInflateHuffman(u8 *dst, s32 numiterations, s32 chansize)
{
	u16 frequencies[2048];
	s16 nodes[2048][2];
	s32 i;
	s32 rootindex;
	s32 sum;
	u16 minfreq1;
	u16 minfreq2;
	s32 minindex1;
	s32 minindex2;
	bool done = false;

	// Read the frequencies list
	for (i = 0; i < chansize; i++) {
		frequencies[i] = texReadBits(8);
	}

	// Initialise the tree
	for (i = 0; i < 2048; i++) {
		nodes[i][0] = -1;
		nodes[i][1] = -1;
	}

	// Find the two smallest frequencies
	minfreq1 = 9999;
	minfreq2 = 9999;

	for (i = 0; i < chansize; i++) {
		if (frequencies[i] < minfreq1) {
			if (minfreq2 < minfreq1) {
				minfreq1 = frequencies[i];
				minindex1 = i;
			} else {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		} else if (frequencies[i] < minfreq2) {
			minfreq2 = frequencies[i];
			minindex2 = i;
		}
	}

	// Build the tree.
	// For each node in tree, a branch value < 10000 means this branch
	// leads to another node, and the value is the target node's index.
	// A branch value >= 10000 means the branch is a leaf node,
	// and the value is the channel value + 10000.
	while (!done) {
		sum = frequencies[minindex1] + frequencies[minindex2];

		if (sum == 0) {
			sum = 1;
		}

		frequencies[minindex1] = 9999;
		frequencies[minindex2] = 9999;

		if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
			nodes[minindex1][0] = minindex1 + 10000;
			rootindex = minindex1;
			frequencies[minindex1] = sum;

			if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
				nodes[minindex1][1] = minindex2 + 10000;
			} else {
				nodes[minindex1][1] = minindex2;
			}
		} else if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
			nodes[minindex2][0] = minindex2 + 10000;
			rootindex = minindex2;
			frequencies[minindex2] = sum;

			if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
				nodes[minindex2][1] = minindex1 + 10000;
			} else {
				nodes[minindex2][1] = minindex1;
			}
		} else {
			for (rootindex = 0; nodes[rootindex][0] >= 0 || nodes[rootindex][1] >= 0 || frequencies[rootindex] < 9999; rootindex++);

			frequencies[rootindex] = sum;
			nodes[rootindex][0] = minindex1;
			nodes[rootindex][1] = minindex2;
		}

		// Find the two smallest frequencies again for the next iteration
		minfreq1 = 9999;
		minfreq2 = 9999;

		for (i = 0; i < chansize; i++) {
			if (frequencies[i] < minfreq1) {
				if (minfreq1 > minfreq2) {
					minfreq1 = frequencies[i];
					minindex1 = i;
				} else {
					minfreq2 = frequencies[i];
					minindex2 = i;
				}
			} else if (frequencies[i] < minfreq2) {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		}

		if (minfreq1 == 9999 || minfreq2 == 9999) {
			done = true;
		}
	}

	// Read bits off the bitstring, traverse the tree
	// and write the channel values to dst
	for (i = 0; i < numiterations; i++) {
		s32 indexorvalue = rootindex;

		while (indexorvalue < 10000) {
			indexorvalue = nodes[indexorvalue][texReadBits(1)];
		}

		if (chansize <= 256) {
			dst[i] = indexorvalue - 10000;
		} else {
			u16 *tmp = (u16 *)dst;
			tmp[i] = indexorvalue - 10000;
		}
	}
}

/**
 * Inflate runlength-encoded data.
 *
 * This data consists of a 10 bit header followed by a list of directives,
 * where each directive can either be a literal block or a repeat (run) of
 * blocks within a sliding window.
 *
 * The header format is:
 *
 * 3 bits btfieldsize: The size in bits of the backtrack distance fields
 * 3 bits rlfieldsize: The size in bits of the runlen fields
 * 4 bits blocksize: The size in bits of each block of data
 *
 * In the data, the first bit is 0 if it's a literal block or 1 if it's a run.
 *
 * For literal blocks, the next <blocksize> bits should be read and appended to
 * the output stream.
 *
 * For runs, the next <btfieldsize> bits are the backtrack length (in blocks)
 * plus one, and the next <rlfieldsize> bits are the run length (in blocks)
 * minus a calculated fudge value.
 *
 * The fudge value is calculated based on the field sizes. For small runs it is
 * more space efficient to use multiple literal directives rather than a run
 * directive. Because of this, smaller runs are not used and the run lengths
 * in the data can be offset accordingly - this offset is the fudge value.
 *
 * Every run must be followed by a literal block without the 1-bit marker.
 * The algorithm does not support back to back runs.
 */
void texInflateRle(u8 *dst, s32 blockstotal)
{
	s32 btfieldsize = texReadBits(3);
	s32 rlfieldsize = texReadBits(3);
	s32 blocksize = texReadBits(4);
	s32 cost;
	s32 fudge;
	s32 blocksdone;
	s32 i;

	// Calculate the fudge value
	cost = btfieldsize + rlfieldsize + blocksize + 1;
	fudge = 0;

	while (cost > 0) {
		cost = cost - blocksize - 1;
		fudge++;
	}

	blocksdone = 0;

	while (blocksdone < blockstotal) {
		if (texReadBits(1) == 0) {
			// Found a literal directive
			if (blocksize <= 8) {
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		} else {
			// Found a run directive
			s32 startblockindex = blocksdone - texReadBits(btfieldsize) - 1;
			s32 runnumblocks = texReadBits(rlfieldsize) + fudge;

			if (blocksize <= 8) {
				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					dst[blocksdone] = dst[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;

				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					tmp[blocksdone] = tmp[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		}
	}
}

/**
 * Populate a lookup table by reading it out of the bit string.
 *
 * The first 11 bits denote the number of colours in the lookup table.
 * The data following this is a list of colours, where each colour is sized
 * according to the texture's format.
 *
 * This function does NOT work with pixel formats of 8 bits or less.
 */
s32 texBuildLookup(u8 *lookup, s32 bitsperpixel)
{
	s32 numcolours = texReadBits(11);
	s32 i;

	if (bitsperpixel <= 16) {
		u16 *dst = (u16 *)lookup;

		for (i = 0; i < numcolours; i++) {
			dst[i] = texReadBits(bitsperpixel);
		}
	} else if (bitsperpixel <= 24) {
		u32 *dst = (u32 *)lookup;

		for (i = 0; i < numcolours; i++) {
			dst[i] = texReadBits(bitsperpixel);
		}
	} else {
		u32 *dst = (u32 *)lookup;

		for (i = 0; i < numcolours; i++) {
			dst[i] = texReadBits(24) << 8 | texReadBits(bitsperpixel - 24);
		}
	}

	return numcolours;
}

s32 texGetBitSize(s32 decimal)
{
	s32 count = 0;

	decimal--;

	while (decimal > 0) {
		decimal >>= 1;
		count++;
	}

	return count;
}

void texReadAlphaBits(u8 *dst, s32 count)
{
	s32 i;

	for (i = 0; i < count; i++) {
		dst[i] = texReadBits(1);
	}
}

/**
 * Read pixel data from the bitstream and write to dst,
 * ensuring each row is aligned according to the pixel format.
 *
 * Return the number of output bytes.
 */
s32 texReadUncompressed(u8 *dst, s32 width, s32 height, s32 format)
{
	u32 *dst32 = (u32 *)(((u32)dst + 0xf) & ~0xf);
	u16 *dst16 = (u16 *)(((u32)dst + 7) & ~7);
	u8 *dst8 = (u8 *)(((u32)dst + 7) & ~7);
	s32 x;
	s32 y;

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(16) << 16;
				dst32[x] |= texReadBits(16);
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(24) << 8 | 0xff;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(16);
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(15) << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = texReadBits(8);
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = texReadBits(8);
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}

/**
 * Read grouped channel values and convert it to a proper pixel format.
 *
 * For example, for RGBA32 images the input is in the format
 * RRR...GGG...BBB...AAA... and is converted to RGBARGBARGBA...
 *
 * The existence and size of the channels depends on the pixel format.
 */
s32 texChannelsToPixels(u8 *src, s32 width, s32 height, u8 *dst, s32 format)
{
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;
	s32 x;
	s32 y;
	s32 pos = 0;
	s32 mult = width * height;

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | src[pos + mult * 3];
				pos++;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | 0xff;
				pos++;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | src[pos + mult * 3];
				pos++;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = src[pos] << 8 | src[pos + mult];
				pos++;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | 1;
				pos++;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
		for (y = 0; y < height; y++) {
			if ((width + 7) & 0xff8);

			for (x = 0; x < width; x++) {
				dst8[x] = src[pos] << 4 | src[pos + mult];
				pos++;
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = src[pos];
				pos++;
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
		for (y = 0; y < height; y++) {
			if ((width + 15) & 0xff0);

			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = src[pos] << 5 | src[pos + mult * 3] << 4 | src[pos + 1] << 1 | src[pos + mult * 3 + 1];
				pos += 2;
			}

			if (width & 1) {
				pos--;
			}

			dst8 += (width + 15) & 0xff0;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = src[pos] << 4 | src[pos + 1];
				pos += 2;
			}

			if (width & 1) {
				pos--;
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}

/**
 * Inflate a texture using the provided lookup table.
 *
 * The lookup table is a bitstring of colours in the pixel format described by
 * the format argument. The number of colours in the lookup table is given by
 * the numcolours argument.
 *
 * The data in the global source bitstring is expected to be a tightly packed
 * list of indices into the lookup table. The number of bits for each index
 * is calculated based on the number of colours in the lookup table. For
 * example, if the lookup table contains 8 colours then the indices will be 0-7,
 * which requires 3 bits per index.
 *
 * Return the number of bytes written to dst.
 */
s32 texInflateLookup(s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
	u32 *lookup32 = (u32 *)lookup;
	u16 *lookup16 = (u16 *)lookup;
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;
	s32 x;
	s32 y;
	s32 bitspercolour = texGetBitSize(numcolours);

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)];
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)] << 8;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)] << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = lookup16[texReadBits(bitspercolour)] << 4;

				if (x + 1 < width) {
					dst8[x >> 1] |= lookup[(texReadBits(bitspercolour) * 2) + 1];
				}
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}

/**
 * Like texInflateLookup, but the indices are provided in the src argument
 * as u8s or u16s rather than read from the global bitstring as tightly packed
 * bits.
 *
 * Whether u8s or u16s are expected depends on whether the number of colours
 * in the lookup table. If there are more than 256 colours then it must use
 * u16s, otherwise it expects u8s.
 */
s32 texInflateLookupFromBuffer(u8 *src, s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
	s32 x;
	s32 y;
	u32 *lookup32 = (u32 *)lookup;
	u16 *lookup16 = (u16 *)lookup;
	u8 *src8;
	u16 *src16;
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;

	if (numcolours <= 256) {
		src8 = (u8 *)src;
	} else {
		src16 = (u16 *)src;
	}

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst32[x] = lookup32[src8[x]];
				} else {
					dst32[x] = lookup32[src16[x]];
				}
			}

			dst32 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst32[x] = lookup32[src8[x]] << 8 | 0xff;
				} else {
					dst32[x] = lookup32[src16[x]] << 8 | 0xff;
				}
			}

			dst32 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst16[x] = lookup16[src8[x]];
				} else {
					dst16[x] = lookup16[src16[x]];
				}
			}

			dst16 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst16[x] = lookup16[src8[x]] << 1 | 1;
				} else {
					dst16[x] = lookup16[src16[x]] << 1 | 1;
				}
			}

			dst16 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			if ((width + 7) & 0xff8);

			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst8[x] = lookup16[src8[x]];
				} else {
					dst8[x] = lookup16[src16[x]];
				}
			}

			dst8 += (width + 7) & 0xff8;
			src8 += width;
			src16 += width;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				if (numcolours <= 256) {
					dst8[x >> 1] = lookup16[src8[x]] << 4 | lookup16[src8[x + 1]];
				} else {
					dst8[x >> 1] = lookup16[src16[x]] << 4 | lookup16[src16[x + 1]];
				}
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
			src8 += width;
			src16 += width;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}

/**
 * For every second row, swap the bytes within that row.
 *
 * For textures with 32-bit colour values (in GBI format), swap every pair
 * within each word. For all other textures, swap every byte within each pair.
 */
void texSwapAltRowBytes(u8 *dst, s32 width, s32 height, s32 format)
{
	s32 x;
	s32 y;
	s32 alignedwidth;
	u32 *row = (u32 *)dst;
	s32 tmp;

	switch (format) {
	case TEXFORMAT_RGBA32:
	case TEXFORMAT_RGB24:
		alignedwidth = (width + 3) & 0xffc;
		break;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_RGB15:
	case TEXFORMAT_IA16:
		alignedwidth = ((width + 3) & 0xffc) >> 1;
		break;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
	case TEXFORMAT_RGBA16_CI8:
	case TEXFORMAT_IA16_CI8:
		alignedwidth = ((width + 7) & 0xff8) >> 2;
		break;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
	case TEXFORMAT_RGBA16_CI4:
	case TEXFORMAT_IA16_CI4:
		alignedwidth = ((width + 0xf) & 0xff0) >> 3;
		break;
	}

	row += alignedwidth;

	if (format == TEXFORMAT_RGBA32 || format == TEXFORMAT_RGB24) {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 4) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 2];
				row[x + 2] = tmp;

				tmp = row[x + 1];
				row[x + 1] = row[x + 3];
				row[x + 3] = tmp;
			}

			row += alignedwidth * 2;
		}
	} else {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 2) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 1];
				row[x + 1] = tmp;
			}

			row += alignedwidth * 2;
		}
	}
}

/**
 * Blur the pixels in the image with the surrounding pixels.
 */
void texBlur(u8 *pixels, s32 width, s32 height, s32 method, s32 chansize)
{
	s32 x;
	s32 y;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			s32 cur = pixels[y * width + x] + chansize * 2;
			s32 left = x > 0 ? pixels[y * width + x - 1] : 0;
			s32 above = y > 0 ? pixels[(y - 1) * width + x] : 0;
			s32 aboveleft = x > 0 && y > 0 ? pixels[(y - 1) * width + x - 1] : 0;

			switch (method) {
			case 0:
				pixels[y * width + x] = (cur + left) % chansize;
				break;
			case 1:
				pixels[y * width + x] = (cur + above) % chansize;
				break;
			case 2:
				pixels[y * width + x] = (cur + aboveleft) % chansize;
				break;
			case 3:
				pixels[y * width + x] = (cur + (left + above - aboveleft)) % chansize;
				break;
			case 4:
				pixels[y * width + x] = (cur + ((above - aboveleft) / 2 + left)) % chansize;
				break;
			case 5:
				pixels[y * width + x] = (cur + ((left - aboveleft) / 2 + above)) % chansize;
				break;
			case 6:
				pixels[y * width + x] = (cur + ((left + above) / 2)) % chansize;
				break;
			}
		}
	}
}

void tex0f172e70(struct texturething *arg0, u8 *arg1, s32 arg2)
{
	arg0->unk00 = (struct texloadthing *)arg1;
	arg0->unk04 = (struct texloadthing *)(arg1 + arg2);
	arg0->unk08 = (struct texloadthing *)arg1;
	arg0->unk0c = (struct texloadthing *)((s32)arg1 + arg2);
}

struct texloadthing *tex0f172e8c(s32 texturenum, struct texturething *arg1)
{
	struct texloadthing *end;
	struct texloadthing *cur;
	s32 i;

	if (arg1 == NULL) {
		arg1 = &var800aabc8;
	}

	if (arg1 == &var800aabc8) {
		cur = arg1->unk04;

		while (cur) {
			if (cur->texturenum == texturenum) {
				return cur;
			}

			if (!cur->unk0c_04) {
				return NULL;
			}

			cur = (struct texloadthing *)PHYS_TO_K0(cur->unk0c_04);
		}

		return NULL;
	}

	end = arg1->unk04;
	cur = arg1->unk0c;

	while (cur < end) {
		if (cur->texturenum == texturenum) {
			return cur;
		}

		cur++;
	}

	return NULL;
}

s32 func0f172f44(struct texturething *arg0)
{
	return (u32)arg0->unk0c - (u32)arg0->unk08;
}

struct texloadthing *func0f172f54(struct texturething *arg0)
{
	return arg0->unk08;
}

void texLoadFromDisplayList(Gfx *gdl, struct texturething *arg1, s32 arg2)
{
	u8 *bytes = (u8 *)gdl;

	while (bytes[0] != (u8)G_ENDDL) {
		// Look for GBI sequence: fd...... abcd....
		if (bytes[0] == G_SETTIMG && bytes[4] == 0xab && bytes[5] == 0xcd) {
			texLoad((s32 *)((s32)bytes + 4), arg1, arg2);
		}

		bytes += 8;
	}
}

GLOBAL_ASM(
glabel texLoad
/*  f173010:	27bddb10 */ 	addiu	$sp,$sp,-9456
/*  f173014:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f173018:	00a08025 */ 	or	$s0,$a1,$zero
/*  f17301c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f173020:	afa424f0 */ 	sw	$a0,0x24f0($sp)
/*  f173024:	afa624f8 */ 	sw	$a2,0x24f8($sp)
/*  f173028:	14a00003 */ 	bnez	$a1,.L0f173038
/*  f17302c:	00003825 */ 	or	$a3,$zero,$zero
/*  f173030:	3c10800b */ 	lui	$s0,%hi(var800aabc8)
/*  f173034:	2610abc8 */ 	addiu	$s0,$s0,%lo(var800aabc8)
.L0f173038:
/*  f173038:	3c0e800b */ 	lui	$t6,%hi(var800aabc8)
/*  f17303c:	25ceabc8 */ 	addiu	$t6,$t6,%lo(var800aabc8)
/*  f173040:	160e0002 */ 	bne	$s0,$t6,.L0f17304c
/*  f173044:	8faf24f0 */ 	lw	$t7,0x24f0($sp)
/*  f173048:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f17304c:
/*  f17304c:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f173050:	3c01ffff */ 	lui	$at,0xffff
/*  f173054:	02002825 */ 	or	$a1,$s0,$zero
/*  f173058:	00411824 */ 	and	$v1,$v0,$at
/*  f17305c:	10600002 */ 	beqz	$v1,.L0f173068
/*  f173060:	3c01abcd */ 	lui	$at,0xabcd
/*  f173064:	146100ee */ 	bne	$v1,$at,.L0f173420
.L0f173068:
/*  f173068:	3c03800b */ 	lui	$v1,%hi(var800ab53c)
/*  f17306c:	2463b53c */ 	addiu	$v1,$v1,%lo(var800ab53c)
/*  f173070:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f173074:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f173078:	0fc5cba3 */ 	jal	tex0f172e8c
/*  f17307c:	a3a7148b */ 	sb	$a3,0x148b($sp)
/*  f173080:	144000e2 */ 	bnez	$v0,.L0f17340c
/*  f173084:	afa2149c */ 	sw	$v0,0x149c($sp)
/*  f173088:	3c19800b */ 	lui	$t9,%hi(var800ab53c)
/*  f17308c:	8f39b53c */ 	lw	$t9,%lo(var800ab53c)($t9)
/*  f173090:	27a314bf */ 	addiu	$v1,$sp,0x14bf
/*  f173094:	00035102 */ 	srl	$t2,$v1,0x4
/*  f173098:	2b210daf */ 	slti	$at,$t9,_numtextures
/*  f17309c:	102000e0 */ 	beqz	$at,.L0f173420
/*  f1730a0:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f1730a4:	0c012048 */ 	jal	osWritebackDCacheAll
/*  f1730a8:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f1730ac:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f1730b0:	0c013920 */ 	jal	osInvalDCache
/*  f1730b4:	24052000 */ 	addiu	$a1,$zero,0x2000
/*  f1730b8:	3c0d800b */ 	lui	$t5,%hi(var800ab53c)
/*  f1730bc:	8dadb53c */ 	lw	$t5,%lo(var800ab53c)($t5)
/*  f1730c0:	3c0c800b */ 	lui	$t4,%hi(g_Textures)
/*  f1730c4:	8d8cabc0 */ 	lw	$t4,%lo(g_Textures)($t4)
/*  f1730c8:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1730cc:	3c0100ff */ 	lui	$at,0xff
/*  f1730d0:	018e1021 */ 	addu	$v0,$t4,$t6
/*  f1730d4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1730d8:	8c470008 */ 	lw	$a3,0x8($v0)
/*  f1730dc:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1730e0:	00617824 */ 	and	$t7,$v1,$at
/*  f1730e4:	00e1c024 */ 	and	$t8,$a3,$at
/*  f1730e8:	11f800cd */ 	beq	$t7,$t8,.L0f173420
/*  f1730ec:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f1730f0:	030f3023 */ 	subu	$a2,$t8,$t7
/*  f1730f4:	24c6001f */ 	addiu	$a2,$a2,0x1f
/*  f1730f8:	2401fff8 */ 	addiu	$at,$zero,-8
/*  f1730fc:	3c0a01d6 */ 	lui	$t2,%hi(_texturesdataSegmentRomStart)
/*  f173100:	254a5f40 */ 	addiu	$t2,$t2,%lo(_texturesdataSegmentRomStart)
/*  f173104:	01e1c824 */ 	and	$t9,$t7,$at
/*  f173108:	00065902 */ 	srl	$t3,$a2,0x4
/*  f17310c:	000b3100 */ 	sll	$a2,$t3,0x4
/*  f173110:	032a2821 */ 	addu	$a1,$t9,$t2
/*  f173114:	0c003504 */ 	jal	dmaExec
/*  f173118:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f17311c:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f173120:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f173124:	93aa148b */ 	lbu	$t2,0x148b($sp)
/*  f173128:	306e0007 */ 	andi	$t6,$v1,0x7
/*  f17312c:	018e3021 */ 	addu	$a2,$t4,$t6
/*  f173130:	90c20000 */ 	lbu	$v0,0x0($a2)
/*  f173134:	00002825 */ 	or	$a1,$zero,$zero
/*  f173138:	02002025 */ 	or	$a0,$s0,$zero
/*  f17313c:	304f0080 */ 	andi	$t7,$v0,0x80
/*  f173140:	30490040 */ 	andi	$t1,$v0,0x40
/*  f173144:	3047003f */ 	andi	$a3,$v0,0x3f
/*  f173148:	000fc1c3 */ 	sra	$t8,$t7,0x7
/*  f17314c:	0009c983 */ 	sra	$t9,$t1,0x6
/*  f173150:	28e10006 */ 	slti	$at,$a3,0x6
/*  f173154:	afb814a8 */ 	sw	$t8,0x14a8($sp)
/*  f173158:	14200002 */ 	bnez	$at,.L0f173164
/*  f17315c:	03204825 */ 	or	$t1,$t9,$zero
/*  f173160:	24070005 */ 	addiu	$a3,$zero,0x5
.L0f173164:
/*  f173164:	1140000f */ 	beqz	$t2,.L0f1731a4
/*  f173168:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f17316c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f173170:	afa614ac */ 	sw	$a2,0x14ac($sp)
/*  f173174:	afa714a0 */ 	sw	$a3,0x14a0($sp)
/*  f173178:	0c004935 */ 	jal	mempGetPoolFree
/*  f17317c:	afa914a4 */ 	sw	$t1,0x14a4($sp)
/*  f173180:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f173184:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f173188:	0c004935 */ 	jal	mempGetPoolFree
/*  f17318c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f173190:	8fab0030 */ 	lw	$t3,0x30($sp)
/*  f173194:	8fa714a0 */ 	lw	$a3,0x14a0($sp)
/*  f173198:	8fa914a4 */ 	lw	$t1,0x14a4($sp)
/*  f17319c:	10000008 */ 	b	.L0f1731c0
/*  f1731a0:	004b1821 */ 	addu	$v1,$v0,$t3
.L0f1731a4:
/*  f1731a4:	afa614ac */ 	sw	$a2,0x14ac($sp)
/*  f1731a8:	afa714a0 */ 	sw	$a3,0x14a0($sp)
/*  f1731ac:	0fc5cbd1 */ 	jal	func0f172f44
/*  f1731b0:	afa914a4 */ 	sw	$t1,0x14a4($sp)
/*  f1731b4:	8fa714a0 */ 	lw	$a3,0x14a0($sp)
/*  f1731b8:	8fa914a4 */ 	lw	$t1,0x14a4($sp)
/*  f1731bc:	00401825 */ 	or	$v1,$v0,$zero
.L0f1731c0:
/*  f1731c0:	15200003 */ 	bnez	$t1,.L0f1731d0
/*  f1731c4:	2c6110cc */ 	sltiu	$at,$v1,0x10cc
/*  f1731c8:	14200005 */ 	bnez	$at,.L0f1731e0
/*  f1731cc:	00000000 */ 	nop
.L0f1731d0:
/*  f1731d0:	11200008 */ 	beqz	$t1,.L0f1731f4
/*  f1731d4:	2c610a28 */ 	sltiu	$at,$v1,0xa28
/*  f1731d8:	50200007 */ 	beqzl	$at,.L0f1731f8
/*  f1731dc:	93ac148b */ 	lbu	$t4,0x148b($sp)
.L0f1731e0:
/*  f1731e0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1731e4:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1731e8:	8fad24f0 */ 	lw	$t5,0x24f0($sp)
/*  f1731ec:	1000008c */ 	b	.L0f173420
/*  f1731f0:	ada20000 */ 	sw	$v0,0x0($t5)
.L0f1731f4:
/*  f1731f4:	93ac148b */ 	lbu	$t4,0x148b($sp)
.L0f1731f8:
/*  f1731f8:	27a20057 */ 	addiu	$v0,$sp,0x57
/*  f1731fc:	00027102 */ 	srl	$t6,$v0,0x4
/*  f173200:	11800015 */ 	beqz	$t4,.L0f173258
/*  f173204:	3c0b800b */ 	lui	$t3,%hi(var800ab53c)
/*  f173208:	8e03000c */ 	lw	$v1,0xc($s0)
/*  f17320c:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f173210:	25e20010 */ 	addiu	$v0,$t7,0x10
/*  f173214:	24580010 */ 	addiu	$t8,$v0,0x10
/*  f173218:	ae02000c */ 	sw	$v0,0xc($s0)
/*  f17321c:	ae180008 */ 	sw	$t8,0x8($s0)
/*  f173220:	1060000d */ 	beqz	$v1,.L0f173258
/*  f173224:	afa31490 */ 	sw	$v1,0x1490($sp)
/*  f173228:	3c048000 */ 	lui	$a0,0x8000
/*  f17322c:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f173230:
/*  f173230:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f173234:	00191202 */ 	srl	$v0,$t9,0x8
/*  f173238:	54400004 */ 	bnezl	$v0,.L0f17324c
/*  f17323c:	00441825 */ 	or	$v1,$v0,$a0
/*  f173240:	10000005 */ 	b	.L0f173258
/*  f173244:	afa31490 */ 	sw	$v1,0x1490($sp)
/*  f173248:	00441825 */ 	or	$v1,$v0,$a0
.L0f17324c:
/*  f17324c:	5460fff8 */ 	bnezl	$v1,.L0f173230
/*  f173250:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f173254:	afa31490 */ 	sw	$v1,0x1490($sp)
.L0f173258:
/*  f173258:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f17325c:	8d6bb53c */ 	lw	$t3,%lo(var800ab53c)($t3)
/*  f173260:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*  f173264:	3c18800b */ 	lui	$t8,%hi(var800ab53c)
/*  f173268:	a44b0000 */ 	sh	$t3,0x0($v0)
/*  f17326c:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f173270:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f173274:	25ac0008 */ 	addiu	$t4,$t5,0x8
/*  f173278:	25c8fff0 */ 	addiu	$t0,$t6,-16
/*  f17327c:	ae0c0008 */ 	sw	$t4,0x8($s0)
/*  f173280:	ae08000c */ 	sw	$t0,0xc($s0)
/*  f173284:	950d0000 */ 	lhu	$t5,0x0($t0)
/*  f173288:	8f19b53c */ 	lw	$t9,%lo(var800ab53c)($t8)
/*  f17328c:	9118000c */ 	lbu	$t8,0xc($t0)
/*  f173290:	31ac000f */ 	andi	$t4,$t5,0xf
/*  f173294:	00195900 */ 	sll	$t3,$t9,0x4
/*  f173298:	016c7025 */ 	or	$t6,$t3,$t4
/*  f17329c:	a50e0000 */ 	sh	$t6,0x0($t0)
/*  f1732a0:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f1732a4:	3319ffef */ 	andi	$t9,$t8,0xffef
/*  f1732a8:	a119000c */ 	sb	$t9,0xc($t0)
/*  f1732ac:	1120000d */ 	beqz	$t1,.L0f1732e4
/*  f1732b0:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f1732b4:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f1732b8:	8faa24f8 */ 	lw	$t2,0x24f8($sp)
/*  f1732bc:	afa8149c */ 	sw	$t0,0x149c($sp)
/*  f1732c0:	afa31490 */ 	sw	$v1,0x1490($sp)
/*  f1732c4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1732c8:	8fa414ac */ 	lw	$a0,0x14ac($sp)
/*  f1732cc:	8fa614a8 */ 	lw	$a2,0x14a8($sp)
/*  f1732d0:	0fc5ba06 */ 	jal	texInflateZlib
/*  f1732d4:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f1732d8:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*  f1732dc:	1000000c */ 	b	.L0f173310
/*  f1732e0:	afa20038 */ 	sw	$v0,0x38($sp)
.L0f1732e4:
/*  f1732e4:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f1732e8:	8fad24f8 */ 	lw	$t5,0x24f8($sp)
/*  f1732ec:	afa8149c */ 	sw	$t0,0x149c($sp)
/*  f1732f0:	afa31490 */ 	sw	$v1,0x1490($sp)
/*  f1732f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1732f8:	8fa414ac */ 	lw	$a0,0x14ac($sp)
/*  f1732fc:	8fa614a8 */ 	lw	$a2,0x14a8($sp)
/*  f173300:	0fc5bf79 */ 	jal	texInflateNonZlib
/*  f173304:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f173308:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*  f17330c:	afa20038 */ 	sw	$v0,0x38($sp)
.L0f173310:
/*  f173310:	93ab148b */ 	lbu	$t3,0x148b($sp)
/*  f173314:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f173318:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f17331c:	11600032 */ 	beqz	$t3,.L0f1733e8
/*  f173320:	2484002f */ 	addiu	$a0,$a0,0x2f
/*  f173324:	348c000f */ 	ori	$t4,$a0,0xf
/*  f173328:	3984000f */ 	xori	$a0,$t4,0xf
/*  f17332c:	0c004991 */ 	jal	mempAllocFromRight
/*  f173330:	afa31490 */ 	sw	$v1,0x1490($sp)
/*  f173334:	ae02000c */ 	sw	$v0,0xc($s0)
/*  f173338:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f17333c:	8fa4149c */ 	lw	$a0,0x149c($sp)
/*  f173340:	00402825 */ 	or	$a1,$v0,$zero
/*  f173344:	0c012c5c */ 	jal	bcopy
/*  f173348:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f17334c:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f173350:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f173354:	afa7149c */ 	sw	$a3,0x149c($sp)
/*  f173358:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f17335c:	24e50010 */ 	addiu	$a1,$a3,0x10
/*  f173360:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f173364:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f173368:	0c012c5c */ 	jal	bcopy
/*  f17336c:	2484fff8 */ 	addiu	$a0,$a0,-8
/*  f173370:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f173374:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f173378:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*  f17337c:	24ef0008 */ 	addiu	$t7,$a3,0x8
/*  f173380:	af0f0004 */ 	sw	$t7,0x4($t8)
/*  f173384:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f173388:	3c0100ff */ 	lui	$at,0xff
/*  f17338c:	8c44000c */ 	lw	$a0,0xc($v0)
/*  f173390:	0004c902 */ 	srl	$t9,$a0,0x4
/*  f173394:	00195200 */ 	sll	$t2,$t9,0x8
/*  f173398:	000a6902 */ 	srl	$t5,$t2,0x4
/*  f17339c:	01a45826 */ 	xor	$t3,$t5,$a0
/*  f1733a0:	1060000e */ 	beqz	$v1,.L0f1733dc
/*  f1733a4:	ac4b000c */ 	sw	$t3,0xc($v0)
/*  f1733a8:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f1733ac:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f1733b0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1733b4:	01817024 */ 	and	$t6,$t4,$at
/*  f1733b8:	01c17824 */ 	and	$t7,$t6,$at
/*  f1733bc:	0004c102 */ 	srl	$t8,$a0,0x4
/*  f1733c0:	01f8c826 */ 	xor	$t9,$t7,$t8
/*  f1733c4:	00195200 */ 	sll	$t2,$t9,0x8
/*  f1733c8:	000a6902 */ 	srl	$t5,$t2,0x4
/*  f1733cc:	01a45826 */ 	xor	$t3,$t5,$a0
/*  f1733d0:	ac6b000c */ 	sw	$t3,0xc($v1)
/*  f1733d4:	10000003 */ 	b	.L0f1733e4
/*  f1733d8:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f1733dc:
/*  f1733dc:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f1733e0:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f1733e4:
/*  f1733e4:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f1733e8:
/*  f1733e8:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f1733ec:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f1733f0:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f1733f4:	ae0f0008 */ 	sw	$t7,0x8($s0)
/*  f1733f8:	93b8148b */ 	lbu	$t8,0x148b($sp)
/*  f1733fc:	57000004 */ 	bnezl	$t8,.L0f173410
/*  f173400:	8fb9149c */ 	lw	$t9,0x149c($sp)
/*  f173404:	0fc5cbd1 */ 	jal	func0f172f44
/*  f173408:	02002025 */ 	or	$a0,$s0,$zero
.L0f17340c:
/*  f17340c:	8fb9149c */ 	lw	$t9,0x149c($sp)
.L0f173410:
/*  f173410:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f173414:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f173418:	8faa24f0 */ 	lw	$t2,0x24f0($sp)
/*  f17341c:	ad420000 */ 	sw	$v0,0x0($t2)
.L0f173420:
/*  f173420:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f173424:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f173428:	27bd24f0 */ 	addiu	$sp,$sp,0x24f0
/*  f17342c:	03e00008 */ 	jr	$ra
/*  f173430:	00000000 */ 	nop
);

//extern u8 _texturesdataSegmentRomStart;

/**
 * Load and decompress a texture from ROM.
 *
 * The given pointer points to a word which determines what to load.
 * The formats of the word are:
 *
 *     abcdxxxx -> load texture number xxxx
 *     0000xxxx -> load texture number xxxx
 *     (memory address) -> the texture is already loaded, so do nothing
 *
 * After loading and decompressing the texture, the value that's pointed to is
 * changed to be a pointer to... something.
 *
 * There are two types of textures:
 *
 * - Zlib-compressed textures, which are always paletted
 * - Non-zlib textures, which use a variety of (non-zlib) compression methods
 *   and are sometimes paletted
 *
 * Both types have support for multiple levels of detail (ie. multiple images
 * of varying size) within each texture. There are enough bits in the header
 * byte to support 64 levels of detail, but this function caps it to 5. Some
 * textures actually specify up to 7 levels of detail. However testing suggests
 * that the additional levels of detail are not even read.
 *
 * This function reads the above information from the first byte of texture data,
 * then calls the texInflateZlib or texInflateNonZlib to inflate the images.
 *
 * The format of the first byte is:
 * uzllllll
 *
 * u = unknown
 * z = texture is compressed with zlib
 * l = number of levels of detail within the texture
 */
// Mismatch: Reordered instructions and regalloc. Is functionally identical.
//void texLoad(u32 *ptr, struct texturething *arg1, s32 arg2)
//{
//	s32 sp14b0[1040];
//	u8 *sp14ac_ptr;
//	s32 sp14a8;
//	s32 sp14a4_iszlib;
//	s32 sp14a0_lod;
//	struct texloadthing *sp149c;
//	u32 freebytes;
//	u32 stack;
//	struct texloadthing *sp1490;
//	u32 stack2;
//	u8 sp148b_usingsharedstruct;
//	s8 sp48[5187];
//	s32 sp44;
//	s32 sp38;
//	struct texloadthing *sp34;
//	s32 sp30;
//	u8 *sp2c;
//
//	sp148b_usingsharedstruct = 0;
//
//	if (arg1 == NULL) {
//		arg1 = &var800aabc8;
//	}
//
//	if (arg1 == &var800aabc8) {
//		sp148b_usingsharedstruct = 1;
//	}
//
//	if ((*ptr & 0xffff0000) == 0 || (*ptr & 0xffff0000) == 0xabcd0000) {
//		var800ab53c = *ptr & 0xffff;
//
//		sp149c = tex0f172e8c(var800ab53c, arg1);
//
//		if (sp149c == NULL && var800ab53c < NUM_TEXTURES) {
//			sp2c = (void *)(((u32)sp14b0 + 0xf) >> 4 << 4);
//
//			if (sp2c);
//
//			osWritebackDCacheAll();
//			osInvalDCache(sp2c, DCACHE_SIZE);
//
//			if (g_Textures[var800ab53c].dataoffset == g_Textures[var800ab53c + 1].dataoffset) {
//				return;
//			}
//
//			sp44 = g_Textures[var800ab53c].dataoffset;
//
//			dmaExec(sp2c,
//					(u32)&_texturesdataSegmentRomStart + (sp44 & 0xfffffff8),
//					(((g_Textures[var800ab53c + 1].dataoffset - sp44) + 0x1f) >> 4) * 0x10);
//
//			if (sp148b_usingsharedstruct);
//			sp14ac_ptr = sp2c + (sp44 & 7);
//			sp14a8 = (*sp14ac_ptr & 0x80) >> 7;
//			sp14a4_iszlib = (*sp14ac_ptr & 0x40) >> 6;
//			sp14a0_lod = *sp14ac_ptr & 0x3f;
//
//			if (sp14a0_lod > 5) {
//				sp14a0_lod = 5;
//			}
//
//			sp14ac_ptr++;
//
//			if (sp148b_usingsharedstruct) {
//				freebytes = mempGetPoolFree(MEMPOOL_STAGE, MEMBANK_ONBOARD) + mempGetPoolFree(MEMPOOL_STAGE, MEMBANK_EXPANSION);
//			} else {
//				freebytes = func0f172f44(arg1);
//			}
//
//			if ((sp14a4_iszlib == 0 && freebytes < 4300) || (sp14a4_iszlib != 0 && freebytes < 2600)) {
//				*ptr = osVirtualToPhysical(arg1->unk00);
//				return;
//			}
//
//			if (sp148b_usingsharedstruct) {
//				sp1490 = arg1->unk0c;
//				arg1->unk0c = (struct texloadthing *)((((u32)sp48 + 0xf) >> 4 << 4) + 0x10);
//				arg1->unk08 = arg1->unk0c + 1;
//
//				while (sp1490) {
//					if (sp1490->unk0c_04 == 0) {
//						break;
//					}
//
//					sp1490 = (struct texloadthing *)PHYS_TO_K0(sp1490->unk0c_04);
//				}
//			}
//
//			*(s16 *)(arg1->unk08) = var800ab53c;
//			arg1->unk08 = (void *)((u32)arg1->unk08 + 8);
//			sp149c = (struct texloadthing *)(arg1->unk0c - 1);
//			arg1->unk0c = sp149c;
//			sp149c->texturenum = var800ab53c;
//			sp149c->unk04 = arg1->unk08;
//			sp149c->unk0c_03 = false;
//
//			if (sp14a4_iszlib) {
//				sp38 = texInflateZlib(sp14ac_ptr, (u32 *)arg1->unk08, sp14a8, sp14a0_lod, arg1, arg2);
//			} else {
//				sp38 = texInflateNonZlib(sp14ac_ptr, (u32 *)arg1->unk08, sp14a8, sp14a0_lod, arg1, arg2);
//			}
//
//			if (sp148b_usingsharedstruct) {
//				sp34 = mempAllocFromRight(ALIGN16(sp38 + 0x20), MEMPOOL_STAGE);
//				arg1->unk0c = sp34;
//
//				bcopy(sp149c, sp34, 0x10);
//
//				sp149c = sp34;
//				sp34++;
//
//				bcopy((void *)((u32)arg1->unk08 - 8), sp34, sp38 + 8);
//
//				arg1->unk0c->unk04 = (void *)((u32)sp34 + 8);
//				arg1->unk0c->unk0c_04 = 0;
//
//				if (sp1490 != NULL) {
//					sp1490->unk0c_04 = (u32)arg1->unk0c & 0xffffff;
//				} else {
//					arg1->unk04 = arg1->unk0c;
//				}
//
//				arg1->unk00 = arg1->unk0c;
//			}
//
//			arg1->unk08 = (void *)((u32)arg1->unk08 + sp38);
//
//			if (!sp148b_usingsharedstruct) {
//				func0f172f44(arg1);
//			}
//		}
//	}
//
//	*ptr = osVirtualToPhysical(sp149c->unk04);
//}

void texLoadFromConfigs(struct textureconfig *configs, s32 numconfigs, struct texturething *arg2, s32 arg3)
{
	s32 i;

	for (i = 0; i < numconfigs; i++) {
		if ((s32)configs[i].texturenum < NUM_TEXTURES) {
			texLoad(&configs[i].texturenum, arg2, 1);
			configs[i].unk0b = 1;
		} else {
			configs[i].texturenum += arg3;
		}
	}
}

void texLoadFromTextureNum(u32 texturenum, struct texturething *arg1)
{
	s32 texturenumcopy = texturenum;

	texLoad(&texturenumcopy, arg1, 1);
}

s32 func0f173510(s32 arg0, s32 arg1, s32 arg3)
{
	return arg0;
}
