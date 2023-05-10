#include <ultra64.h>
#include "constants.h"
#include "game/game_0b2150.h"
#include "bss.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

/**
 * With this function stubbed, light glares do not render,
 * nor do suns or their lens flares.
 */
void func0f0b2150(Gfx **gdlptr, f32 *arg1, f32 *arg2, s32 width, s32 height, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 tile, s32 arg10)
{
	if (arg2[0] > 0.0f && arg2[1] > 0.0f) {
		Gfx *gdl = *gdlptr;
		s32 xl;
		s32 yl;
		s32 xh;
		s32 yh;
		s32 s = 0;
		s32 t = 0;
		s32 dsdx;
		s32 dtdy;
		s32 widthx4;
		s32 heightx4;
		s32 sp20 = 0;
		s32 sp1c = 0;

		gDPSetTexturePersp(gdl++, G_TP_NONE);

		xl = (arg1[0] - arg2[0]) * 4.0f;
		yl = (arg1[1] - arg2[1]) * 4.0f;
		xh = (arg1[0] + arg2[0]) * 4.0f;
		yh = (arg1[1] + arg2[1]) * 4.0f;

		if (arg10) {
			sp20 = xl & 3;
			sp1c = yl & 3;
			xl -= sp20;
			yl -= sp1c;
		}

		if (xh >= 0 && yh >= 0) {
			if (arg8) {
				width *= 2;
				height *= 2;
				s = -(width * 16);
				t = -(height * 16);
			}

			if (xl < 0) {
				if (arg5) {
					t += ((-xl * height) << 5) / (xh - xl);
				} else {
					s += ((-xl * width) << 5) / (xh - xl);
				}

				xl = 0;
			}

			if (yl < 0) {
				if (arg5) {
					s += ((-yl * width) << 5) / (yh - yl);
				} else {
					t += ((-yl * height) << 5) / (yh - yl);
				}

				yl = 0;
			}

			widthx4 = g_ViBackData->x * 4;
			heightx4 = g_ViBackData->y * 4;

			if (widthx4 < xh) {
				xh = widthx4;
			}

			if (heightx4 < yh) {
				yh = heightx4;
			}

			if (arg5) {
				dsdx = width / (2.0f * arg2[1]) * 1024.0f;
				dtdy = height / (2.0f * arg2[0]) * 1024.0f;
			} else {
				dsdx = width / (2.0f * arg2[0]) * 1024.0f;
				dtdy = height / (2.0f * arg2[1]) * 1024.0f;
			}

			if (arg10) {
				s -= (sp20 * dsdx) >> 7;
				t -= (sp1c * dtdy) >> 7;
			}

			if (arg6) {
				dsdx = 0x10000 - dsdx;

				if (arg8) {
					s = (((width >> 1) - 1) << 5) - s;
				} else {
					s = ((width - 1) << 5) - s;
				}
			}

			if (arg7) {
				dtdy = 0x10000 - dtdy;

				if (arg8) {
					t = (((height >> 1) - 1) << 5) - t;
				} else {
					t = ((height - 1) << 5) - t;
				}
			}

			if (arg5) {
				gSPTextureRectangleFlip(gdl++, xl, yl, xh, yh, tile, s, t, dsdx, dtdy);
			} else {
				gSPTextureRectangle(gdl++, xl, yl, xh, yh, tile, s, t, dsdx, dtdy);
			}
		}

		gDPSetTexturePersp(gdl++, G_TP_PERSP);

		*gdlptr = gdl;
	}
}

void func0f0b2740(Gfx **gdl, f32 *arg1, f32 *arg2, s32 width, s32 height, bool arg5, bool arg6, bool arg7, u32 arg8)
{
	func0f0b2150(gdl, arg1, arg2, width, height, arg5, arg6, arg7, arg8, G_TX_RENDERTILE, false);
}

void func0f0b278c(Gfx **gdlptr, f32 *arg1, f32 *arg2, s32 twidth, u32 theight, u32 arg5, u32 arg6, u32 arg7, u32 r, u32 g, u32 b, u32 alpha, u32 arg12, u32 arg13)
{
	if (arg2[0] > 0.0f && arg2[1] > 0.0f) {
		Gfx *gdl = *gdlptr;

		gDPSetEnvColor(gdl++, r, g, b, alpha);

		if (arg12) {
			gDPSetCombineLERP(gdl++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, ENVIRONMENT, 0, COMBINED, 0, ENVIRONMENT, 0);
		} else if (arg13) {
			gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
		} else {
			gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0);
		}

		*gdlptr = gdl;

		func0f0b2150(gdlptr, arg1, arg2, twidth, theight, arg5, arg6, arg7, false, G_TX_RENDERTILE, false);
	}
}
