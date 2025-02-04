#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/savebuffer.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_NTSC_1_0
Vp *g_OrthoViewport = NULL;
#else
Vp g_OrthoViewport;
#endif

s32 g_HolorayMinY;
s32 g_HolorayMaxY;
s32 g_HolorayProjectFromX;
s32 g_HolorayProjectFromY;

void ortho_configure_full_mtx(Mtxf *mtx)
{
	struct coord pos;

	mtx4_load_identity(mtx);

	pos.x = -159.75f;
	pos.y = PAL ? 136.25f : 120.25f;
	pos.z = 0;

	pos.x = (0.5f - vi_get_width()) / 2.0f;
	pos.y = (0.5f + vi_get_height()) / 2.0f;
	pos.z = 0;

	mtx4_set_translation(&pos, mtx);
	mtx00015e4c(-1, mtx);

	if (g_UiScaleX == 2) {
		mtx00015df0(2, mtx);
	}
}

void ortho_configure_mtx(Mtxf *mtx)
{
	ortho_configure_full_mtx(mtx);
	mtx00015df0(0.1f, mtx);
	mtx00015e4c(0.1f, mtx);
}

Gfx *ortho_begin(Gfx *gdl)
{
	Mtxf mtx;
	Mtxf *mtx1;
	Mtxf *mtx2;

	mtx1 = gfx_allocate_matrix();
	mtx2 = gfx_allocate_matrix();

	mtx00016760();
	ortho_configure_mtx(&mtx);
	mtx_f2l(&mtx, mtx2);
	mtx4_load_identity(&mtx);

	guFrustumF(mtx.m,
			-(f32) vi_get_width() * 0.5f, vi_get_width() * 0.5f,
			-(f32) vi_get_height() * 0.5f, vi_get_height() * 0.5f,
			10, 10000, 1);

	mtx_f2l(&mtx, mtx1);
	mtx00016784();

	gSPMatrix(gdl++, osVirtualToPhysical(mtx2), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPMatrix(gdl++, osVirtualToPhysical(mtx1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

#if VERSION >= VERSION_NTSC_1_0
	if (g_OrthoViewport == NULL) {
		u32 size = align16(sizeof(*g_OrthoViewport));
		g_OrthoViewport = gfx_allocate(size);

		if (g_OrthoViewport != NULL) {
			g_OrthoViewport->vp.vscale[0] = vi_get_width() << 1;
			g_OrthoViewport->vp.vscale[1] = vi_get_height() << 1;
			g_OrthoViewport->vp.vscale[2] = 1;
			g_OrthoViewport->vp.vscale[3] = 0;

			g_OrthoViewport->vp.vtrans[0] = vi_get_width() << 1;
			g_OrthoViewport->vp.vtrans[1] = vi_get_height() << 1;
			g_OrthoViewport->vp.vtrans[2] = 0x1ff;
			g_OrthoViewport->vp.vtrans[3] = 0;
		}
	}

	gSPViewport(gdl++, g_OrthoViewport);
#else
	g_OrthoViewport.vp.vscale[0] = 640;
	g_OrthoViewport.vp.vscale[1] = 480;
	g_OrthoViewport.vp.vscale[2] = 640;
	g_OrthoViewport.vp.vscale[3] = 0;

	g_OrthoViewport.vp.vtrans[0] = 640;
	g_OrthoViewport.vp.vtrans[1] = 480;
	g_OrthoViewport.vp.vtrans[2] = 0x1ff;
	g_OrthoViewport.vp.vtrans[3] = 0;

	g_OrthoViewport.vp.vscale[0] = vi_get_width() << 1;
	g_OrthoViewport.vp.vscale[1] = vi_get_height() << 1;
	g_OrthoViewport.vp.vscale[2] = 1;
	g_OrthoViewport.vp.vscale[3] = 0;

	g_OrthoViewport.vp.vtrans[0] = vi_get_width() << 1;
	g_OrthoViewport.vp.vtrans[1] = vi_get_height() << 1;
	g_OrthoViewport.vp.vtrans[2] = 0x1ff;
	g_OrthoViewport.vp.vtrans[3] = 0;

	gSPViewport(gdl++, &g_OrthoViewport);
#endif

	gDPPipeSync(gdl++);

	return gdl;
}

Gfx *ortho_end(Gfx *gdl)
{
	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(vi_get_current_player_viewport()));
	gSPMatrix(gdl++, osVirtualToPhysical(cam_get_perspective_mtxl()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	return gdl;
}

Gfx *ortho_holoray_begin(Gfx *gdl, s32 type)
{
	Mtxf mtx;
	Mtxf *mtxptr = gfx_allocate_matrix();

	gDPPipeSync(gdl++);

	if (type == 0) {
		tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_MENURAY0], 2, 0, 2, 1, NULL);
	} else if (type == 1) {
		tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_MENURAY1], 2, 0, 2, 1, NULL);
	}

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
	gSPSetGeometryMode(gdl++, G_SHADE);
	gSPSetGeometryMode(gdl++, G_SHADING_SMOOTH);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	ortho_configure_full_mtx(&mtx);
	mtx_f2l(&mtx, mtxptr);

	gSPMatrix(gdl++, osVirtualToPhysical(mtxptr), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

Gfx *ortho_holoray_end(Gfx *gdl)
{
	Mtxf mtx;
	Mtxf *mtxptr = gfx_allocate_matrix();

	ortho_configure_full_mtx(&mtx);
	mtx00015df0(0.1f, &mtx);
	mtx00015e4c(0.1f, &mtx);
	mtx_f2l(&mtx, mtxptr);

	gSPMatrix(gdl++, osVirtualToPhysical(mtxptr), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

/**
 * This function is used to draw the walls, floor and ceiling of the
 * hologram projection tunnel, as well as the text projection ray.
 */
Gfx *ortho_draw_holoray(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, s32 type)
{
	Col *colours;
	Vtx *vertices;
	f32 tmp1;
	s16 a1;
	s16 t1;
	f32 sp34;
	f32 sp30;
	s16 sp2e;
	s16 sp2c;
	s16 sp2a;
	s16 sp28;
	s16 a1_2;
	s16 scale = 10;
	f32 tmp2;

	static u32 depthsub = 1000;
	static u32 txmul = 20;
	static u32 rsub = 5;

	colours = gfx_allocate_colours(2);
	vertices = gfx_allocate_vertices(4);

	sp34 = 1.0f;
	sp30 = 1.0f;

	main_override_variable("txmul", &txmul);

	if (y1 < g_HolorayMinY && y2 < g_HolorayMinY) {
		return gdl;
	}

	if (y1 > g_HolorayMaxY && y2 > g_HolorayMaxY) {
		return gdl;
	}

	if (y1 < g_HolorayMinY) {
		y1 = g_HolorayMinY;
	}

	if (y2 < g_HolorayMinY) {
		y2 = g_HolorayMinY;
	}

	if (y1 > g_HolorayMaxY) {
		y1 = g_HolorayMaxY;
	}

	if (y2 > g_HolorayMaxY) {
		y2 = g_HolorayMaxY;
	}

	sp2e = (x1 + y1) * txmul;
	sp2c = (x2 + y2) * txmul;
	sp2a = 0;
	sp28 = 16384;

	if (type == MENUPLANE_01) {
		sp30 = 2.0f;
	}

	main_override_variable("depthsub", &depthsub);

	a1 = 200;

	if (type == MENUPLANE_02 || type == MENUPLANE_03) {
		if (type == MENUPLANE_02) {
			sp2e = 0;
			sp2c = 1024;
		} else {
			sp2e = 1024;
			sp2c = 2048;
		}

		sp34 = 4.0f;
		sp30 = 4.0f;
		a1 = 6000;
	}

	if (type == MENUPLANE_08 || type == MENUPLANE_09 || type == MENUPLANE_11) {
		sp2e = 0;
		sp2c = 2048;
		a1 = 2000;
		sp34 = 4.0f;
		sp30 = 4.0f;

		if (type == MENUPLANE_09) {
			sp30 = 2.0f;
		}
	}

	if (type == MENUPLANE_04) {
		a1 = 2000;
		sp34 = 1.0f;
		sp30 = 1.0f;
	}

	if (type == MENUPLANE_05 || type == MENUPLANE_06 || type == MENUPLANE_10) {
		a1 = 1000;
		sp2e = 0;
		sp2c = 4096;
		sp30 = 4.0f;

		if (type == MENUPLANE_06) {
			sp2e = 384;
			sp2c = 4480;
			sp30 = 8.0f;
		} else if (type == MENUPLANE_10) {
			sp2e = 384;
			sp2c = 4480;
			sp30 = 8.0f;
		} else {
			sp34 = 2.0f;
		}
	}

	if (type == MENUPLANE_07) {
		main_override_variable("rsub", &rsub);

		a1 = -rsub;

		sp30 = 8.0f;
		sp2a = 256;
		sp28 = 0;
	}

	vertices[0].x = x1;
	vertices[0].y = y1;
	vertices[0].z = -10;

	vertices[1].x = x2;
	vertices[1].y = y2;
	vertices[1].z = -10;

	tmp1 = (f32) g_HolorayProjectFromX * a1 / scale;
	tmp2 = (f32) g_HolorayProjectFromY * a1 / scale;

	vertices[2].x = vertices[0].v[0] + (s16) tmp1;
	vertices[2].y = vertices[0].v[1] + (s16) tmp2;
	vertices[2].z = -10 - a1;

	vertices[3].x = vertices[1].v[0] + (s16) tmp1;
	vertices[3].y = vertices[1].v[1] + (s16) tmp2;
	vertices[3].z = -10 - a1;

	if (type == MENUPLANE_10) {
		t1 = g_20SecIntervalFrac * sp34 * 64.0f * 32.0f;
	} else {
		t1 = (g_20SecIntervalFrac - 0.5f) * sp34 * 64.0f * 32.0f;
	}

	if (type == MENUPLANE_10) {
		a1_2 = (g_20SecIntervalFrac - 0.5f) * sp30 * 64.0f * 32.0f;
	} else {
		a1_2 = g_20SecIntervalFrac * sp30 * 64.0f * 32.0f;
	}

	vertices[0].s = sp2e + t1;
	vertices[0].t = sp2a + a1_2;
	vertices[1].s = sp2c + t1;
	vertices[1].t = sp2a + a1_2;
	vertices[3].s = sp2c + t1;
	vertices[3].t = sp28 + a1_2;
	vertices[2].s = sp2e + t1;
	vertices[2].t = sp28 + a1_2;

	if (type == MENUPLANE_07) {
		vertices[0].colour = 0;
		vertices[1].colour = 0;
		vertices[2].colour = 4;
		vertices[3].colour = 4;
	} else {
		vertices[0].colour = 0;
		vertices[1].colour = 4;
		vertices[2].colour = 0;
		vertices[3].colour = 4;
	}

	colours[0].word = colour1;
	colours[1].word = colour2;

	gSPColor(gdl++, osVirtualToPhysical(colours), 2);
	gSPVertex(gdl++, osVirtualToPhysical(vertices), 4, 0);
	gSPTri2(gdl++, 0, 1, 3, 3, 2, 0);

	return gdl;
}

/**
 * Write the specified amount of bits to the buffer, advancing the internal pointer.
 *
 * numbits is expected to be 32 or less.
 *
 * This function only sets bits to on and does not unset them.
 */
void savebuffer_write_bits(struct savebuffer *buffer, u32 value, s32 numbits)
{
	u32 bit = 1 << (numbits - 1);

	for (; bit; bit >>= 1) {
		if (bit & value) {
			s32 bitindex = buffer->bitpos % 8;
			u8 mask = 1 << (7 - bitindex);
			s32 byteindex = buffer->bitpos / 8;

			buffer->bytes[byteindex] |= mask;
		}

		buffer->bitpos++;
	}
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * Given a `value` which has `numbits` of relevant bits, copy it to `dst`
 * but using the bit positions which line up with the given savebuffer's buffer.
 * The buffer's bitpos will be incremented by numbits.
 *
 * For example, if the savebuffer's bitpos is byte 100, bitindex 5 then the
 * value will be written to dst starting at byte 100, bitindex 5, and the
 * savebuffer's bitpos will be incremented accordingly.
 */
void savebuffer_align_to_buffer(struct savebuffer *buffer, u32 value, s32 numbits, u8 *dst)
{
	u32 bit = 1 << (numbits - 1);

	for (; bit; bit >>= 1) {
		s32 bitindex = buffer->bitpos % 8;
		u8 mask = 1 << (7 - bitindex);
		s32 byteindex = buffer->bitpos / 8;

		if (bit & value) {
			dst[byteindex] |= mask;
		} else {
			dst[byteindex] &= ~mask;
		}

		buffer->bitpos++;
	}
}
#endif

/**
 * Read the specified amount of bits from the buffer and return it as an
 * integer, advancing the internal pointer.
 *
 * numbits is expected to be 32 or less.
 */
u32 savebuffer_read_bits(struct savebuffer *buffer, s32 numbits)
{
	u32 bit = 1 << (numbits - 1);
	u32 value = 0;

	for (; bit; bit >>= 1) {
		s32 bitindex = buffer->bitpos % 8;
		u8 mask = 1 << (7 - bitindex);
		s32 byteindex = buffer->bitpos / 8;

		if (buffer->bytes[byteindex] & mask) {
			value |= bit;
		}

		buffer->bitpos++;
	}

	return value;
}

void savebuffer_reset(struct savebuffer *buffer)
{
	s32 i;

	buffer->bitpos = 0;

	for (i = 0; i < sizeof(buffer->bytes);) {
		buffer->bytes[i] = 0;
		i++;
	}
}

/**
 * Write the string to the start of the buffer
 * and reset the buffer's bitpos to the start.
 *
 * The buffer can then be used to read the string back.
 */
void savebuffer_prepare_string(struct savebuffer *buffer, u8 *src, u8 len)
{
	s32 i;

	buffer->bitpos = 0;

	for (i = 0; i < len; i++) {
		buffer->bytes[i] = src[i];
	}
}

void savebuffer_print(struct savebuffer *buffer)
{
	s32 tmp = buffer->bitpos;

	if (tmp / 8 && buffer->bitpos);
}

/**
 * Read a zero-terminated string from the buffer and move the buffer's internal
 * pointer past the end of the string.
 */
void savebuffer_read_string(struct savebuffer *buffer, char *dst, bool addlinebreak)
{
	bool foundnull = false;
	s32 index = 0;
	s32 i;

	for (i = 0; i < MAX_USERSTRING_LEN; i++) {
		s32 byte = savebuffer_read_bits(buffer, 8);

		if (!foundnull) {
			if (byte == '\0') {
				foundnull = true;
			} else {
				dst[i] = byte;
				index = i;
			}
		}
	}

	if (addlinebreak) {
		index++;
		dst[index] = '\n';
	}

	index++;
	dst[index] = '\0';
}

void savebuffer_write_string(struct savebuffer *buffer, char *src)
{
	bool done = false;
	s32 i;

	for (i = 0; i < MAX_USERSTRING_LEN; i++) {
		if (!done) {
			if (src[i] == '\0') {
				done = true;
			} else if (src[i] == '\n') {
				done = true;
			} else {
				u32 c = src[i];
				savebuffer_write_bits(buffer, c, 8);
			}
		}

		if (done) {
			savebuffer_write_bits(buffer, '\0', 8);
		}
	}
}

/**
 * Convert a savefile bitstring to a zero-terminated C string, with an optional
 * line break added before the zero terminator.
 *
 * Savefile bitstrings are max 10 bytes, do not have line breaks, and will be
 * missing the zero terminator if they are 10 bytes.
 */
void savebuffer_bitstring_to_cstring(u8 *bitstring, char *cstring, bool addlinebreak)
{
	struct savebuffer buffer;

	savebuffer_prepare_string(&buffer, bitstring, MAX_USERSTRING_LEN);
	savebuffer_read_string(&buffer, cstring, addlinebreak);
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * Convert a zero-terminated or newline-terminated C string
 * to a savefile bitstring.
 *
 * The C string is also terminated at length MAX_USERSTRING_LEN.
 */
void savebuffer_cstring_to_bitstring(u8 *bitstring, char *cstring)
{
	struct savebuffer buffer;
	bool done = false;
	s32 i;

	savebuffer_prepare_string(&buffer, bitstring, MAX_USERSTRING_LEN);

	for (i = 0; i < MAX_USERSTRING_LEN; i++) {
		if (!done) {
			if (cstring[i] == '\0') {
				done = true;
			} else if (cstring[i] == '\n') {
				done = true;
			} else {
				u32 c = cstring[i];
				savebuffer_align_to_buffer(&buffer, c, 8, bitstring);
			}
		}

		if (done) {
			savebuffer_align_to_buffer(&buffer, '\0', 8, bitstring);
		}
	}
}
#endif

void savebuffer_write_guid(struct savebuffer *buffer, struct fileguid *guid)
{
	savebuffer_write_bits(buffer, guid->fileid, 7);
	savebuffer_write_bits(buffer, guid->deviceserial, 13);
}

void savebuffer_read_guid(struct savebuffer *buffer, struct fileguid *guid)
{
	guid->fileid = savebuffer_read_bits(buffer, 7);
	guid->deviceserial = savebuffer_read_bits(buffer, 13);
}

void format_time(char *dst, s32 time60, s32 precision)
{
	s32 parts[5];
	bool donefirst = false;
	s32 len = 0;
	s32 i;

	parts[4] = time60 % 60 * 100 / 60; // hundredths
	parts[3] = time60 / 60; // seconds
	parts[2] = parts[3] / 60; // minutes
	parts[1] = parts[2] / 60; // hours
	parts[0] = parts[1] / 24; // days

	parts[3] %= 60; // seconds
	parts[2] %= 60; // minutes
	parts[1] %= 24; // hours

	for (i = 0; i <= precision; i++) {
		if (donefirst) {
			len += sprintf(&dst[len], ":%02d", parts[i]);
		} else if (parts[i] != 0 || i >= TIMEPRECISION_MINUTES) {
			len += sprintf(&dst[len], "%d", parts[i]);
			donefirst = true;
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void ortho_reset(void)
{
	g_OrthoViewport = NULL;
}
#endif
