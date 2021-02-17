#ifndef _IN_GBIEX_H
#define _IN_GBIEX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

/**
 * 04	rsp_uc05_vertex
 *
 * upper word
 * 00F00000	number of points
 * 000FFFFF	number of bytes to grab
 *
 * lower word
 * 0f000000	segment
 * 00ffffff	offset in point table
 */
#define	gDPSetVerticeArray(pkt, ptr, numvertices)                   \
{                                                                   \
	Gfx *_g = (Gfx *)(pkt);                                         \
                                                                    \
	_g->words.w0 = (_SHIFTL(0x04, 24, 8)                            \
			| _SHIFTL(numvertices - 1, 20, 4)                       \
			| _SHIFTL(numvertices * sizeof(struct gfxvtx), 0, 20)); \
	_g->words.w1 = (unsigned int)(ptr);                             \
}

/**
 * 07	rsp_color
 * This PD-specific command declares offset to RGBA data
 *
 * upper word
 * 00FF0000	number of bytes to grab, -4
 * 0000FFFF	number of bytes to grab
 *
 * lower word
 * 0f000000	segment
 * 00ffffff	address or offset in file
 */
#define	gDPSetColorArray(pkt, ptr, numcolors)     \
{                                                 \
	Gfx *_g = (Gfx *)(pkt);                       \
                                                  \
	_g->words.w0 = (_SHIFTL(0x07, 24, 8)          \
			| _SHIFTL((numcolors - 1) * 4, 16, 8) \
			| _SHIFTL(numcolors * 4, 0, 16));     \
	_g->words.w1 = (unsigned int)(ptr);           \
}

/**
 * B1	rsp_tri4
 * Draws up to four triangles at a time.
 * Expects values from 0-F, corresponding with # points declared by vertex command.
 * Triangles with all points set to 0 are not drawn.
 *
 * upper word
 * 0000F000	z4
 * 00000F00	z3
 * 000000F0	z2
 * 0000000F	z1
 *
 * lower word
 * f0000000	y4
 * 0f000000	x4
 * 00f00000	y3
 * 000f0000	x3
 * 0000f000	y2
 * 00000f00	x2
 * 000000f0	y1
 * 0000000f	x1
 */
#define	gDPTri4(pkt, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4) \
{                                        \
	Gfx *_g = (Gfx *)(pkt);              \
                                         \
	_g->words.w0 = (_SHIFTL(0xb1, 24, 8) \
			| _SHIFTL(z4, 12, 4)         \
			| _SHIFTL(z3, 8, 4)          \
			| _SHIFTL(z2, 4, 4)          \
			| _SHIFTL(z1, 0, 4));        \
	_g->words.w1 = (_SHIFTL(y4, 28, 4)   \
			| _SHIFTL(x4, 24, 4)         \
			| _SHIFTL(y3, 20, 4)         \
			| _SHIFTL(x3, 16, 4)         \
			| _SHIFTL(y2, 12, 4)         \
			| _SHIFTL(x2, 8, 4)          \
			| _SHIFTL(y1, 4, 4)          \
			| _SHIFTL(x1, 0, 4));        \
}

#define gDPTri2(pkt, x1, y1, z1, x2, y2, z2) \
	gDPTri4(pkt, x1, y1, z1, x2, y2, z2, 0, 0, 0, 0, 0, 0)

/**
 * Like gDPSetPrimColor, but is useful when the input colour is already in
 * RGBA format. It avoids unnecessary bitshifting and masking.
 */
#define	gDPSetPrimColorViaWord(pkt, m, l, rgba)     \
{                                                   \
	Gfx *_g = (Gfx *)(pkt);                         \
                                                    \
	_g->words.w0 =	(_SHIFTL(G_SETPRIMCOLOR, 24, 8) \
			| _SHIFTL(m, 8, 8)                      \
			| _SHIFTL(l, 0, 8));                    \
	_g->words.w1 =  (rgba);                         \
}

#define	gDPSetEnvColorViaWord(pkt, rgba) gDPSetColor(pkt, G_SETENVCOLOR, rgba)

/**
 * gDPFillRectangle - a wrapper around gDPFillRectangle which applies
 * g_ScaleX to the X coordinates.
 *
 * g_ScaleX is normally 1, but 2 when using hi-res.
 */
#define gDPFillRectangleScaled(pkt, x1, y1, x2, y2) gDPFillRectangle(pkt, (x1) * g_ScaleX, y1, (x2) * g_ScaleX, y2)

#endif
