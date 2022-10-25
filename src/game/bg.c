#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/portal.h"
#include "game/room.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/ceil.h"
#include "game/bondgun.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/sky.h"
#include "game/stars.h"
#include "game/dyntex.h"
#include "game/game_13c510.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/gfxreplace.h"
#include "game/bg.h"
#include "game/game_165360.h"
#include "game/stagetable.h"
#include "game/env.h"
#include "game/room.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/texdecompress.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/lib_17ce0.h"
#include "lib/rzip.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "lib/mema.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_2f490.h"
#include "data.h"
#include "gbiex.h"
#include "types.h"

#define BGCMD_END                               0x00
#define BGCMD_PUSH                              0x01
#define BGCMD_POP                               0x02
#define BGCMD_AND                               0x03
#define BGCMD_OR                                0x04
#define BGCMD_NOT                               0x05
#define BGCMD_XOR                               0x06
#define BGCMD_PUSH_CAMINROOMRANGE               0x14
#define BGCMD_SETRESULT_TRUE                    0x1e
#define BGCMD_SETRESULT_IFPORTALINFOV           0x1f
#define BGCMD_IFRESULT_SHOWROOM                 0x20
#define BGCMD_SETRESULT_FALSE                   0x21
#define BGCMD_SETRESULT_TRUEIFTHROUGHPORTAL     0x22
#define BGCMD_SETRESULT_FALSEIFNOTTHROUGHPORTAL 0x23
#define BGCMD_DISABLEROOM                       0x24
#define BGCMD_DISABLEROOMRANGE                  0x25
#define BGCMD_LOADROOM                          0x26
#define BGCMD_LOADROOMRANGE                     0x27
#define BGCMD_SETROOMTESTSDISABLED              0x28
#define BGCMD_PUSH_PORTALISOPEN                 0x29
#define BGCMD_2A                                0x2a
#define BGCMD_BRANCH                            0x50
#define BGCMD_THROW                             0x51
#define BGCMD_CATCH                             0x52
#define BGCMD_IF                                0x5a
#define BGCMD_ELSE                              0x5b
#define BGCMD_ENDIF                             0x5c
#define BGCMD_PORTALARG                         0x64
#define BGCMD_ROOMARG                           0x65

#define BGRESULT_TRUE  0
#define BGRESULT_FALSE 1

#define VTXBATCHTYPE_OPA 0x01
#define VTXBATCHTYPE_XLU 0x02

struct var800a4640 var800a4640;
u8 *g_BgPrimaryData;
u32 var800a4920;
u32 g_BgSection3;
struct room *g_Rooms;
u8 *g_MpRoomVisibility;
s16 g_ActiveRoomNums[350];
s32 g_NumActiveRooms;
u16 g_BgUnloadDelay240;
u16 g_BgUnloadDelay240_2;
u32 var800a4bf4;
s16 g_GlareRooms[100];
u32 *g_BgPrimaryData2;
struct bgroom *g_BgRooms;
struct bgportal *g_BgPortals;
struct var800a4ccc *var800a4ccc;
u8 *var800a4cd0;
u8 *g_BgLightsFileData;
f32 *g_BgTable5;
s16 *g_RoomPortals;
s16 var800a4ce4;
s16 var800a4ce6;
struct var800a4ce8 *var800a4ce8;
struct portalthing *g_PortalThings;
struct var800a4cf0 var800a4cf0;

bool g_BgPreload = false;
s32 g_StageIndex = 1;
u32 var8007fc04 = 0x00000000;
u8 *var8007fc08 = NULL;

#if VERSION < VERSION_NTSC_1_0
u32 var80082474nb = 0;
#endif

s16 var8007fc0c = 0;
s16 var8007fc10 = 0;
s32 g_NumRoomsWithGlares = 0;
u32 var8007fc18 = 0x01000100;
u32 var8007fc1c = 0x00000000;
s32 g_CamRoom = 0x00000001;
struct var800a4640_00 *var8007fc24 = &var800a4640.unk2d0;
s32 var8007fc28 = 0;
s32 var8007fc2c = 0;
s32 var8007fc30 = 0;
s32 var8007fc34 = 0;
u32 g_BgNumRoomLoadCandidates = 0x00000000;
u16 var8007fc3c = 0xfffe;
s32 g_NumPortalThings = 0;

void roomUnpauseProps(u32 roomnum, bool tintedglassonly)
{
	struct prop *prop;
	struct defaultobj *obj;
	s16 *propnumptr;
	s16 rooms[2];
	s16 propnums[256];

	rooms[0] = roomnum;
	rooms[1] = -1;

	roomGetProps(rooms, propnums, 256);

	propnumptr = propnums;

	while (*propnumptr >= 0) {
		prop = &g_Vars.props[*propnumptr];

		if (!prop->active) {
			if (tintedglassonly) {
				/**
				 * @bug: A missing prop->type check means this is inadvertently
				 * casting other pointer types to obj pointers. By chance this
				 * happens to be harmless.
				 */
				obj = prop->obj;

				if (obj->type == OBJTYPE_TINTEDGLASS) {
					propUnpause(prop);
				}
			} else {
				propUnpause(prop);
			}
		}

		propnumptr++;
	}
}

void roomSetOnscreen(s32 roomnum, s32 draworder, struct screenbox *box)
{
	s32 index;

#if VERSION < VERSION_NTSC_1_0
	g_Rooms[roomnum].flags |= ROOMFLAG_ONSCREEN;
#endif

	if ((g_Rooms[roomnum].flags & ROOMFLAG_DISABLEDBYSCRIPT) == 0) {
#if VERSION >= VERSION_NTSC_1_0
		g_Rooms[roomnum].flags |= ROOMFLAG_ONSCREEN;
#endif

		if (g_Rooms[roomnum].flags & ROOMFLAG_0800) {
			box->xmin = var800a4640.unk2d0.box.xmin;
			box->ymin = var800a4640.unk2d0.box.ymin;
			box->xmax = var800a4640.unk2d0.box.xmax;
			box->ymax = var800a4640.unk2d0.box.ymax;
		}

		if (var8007fc3c == var800a4ce8[roomnum].unk00) {
			index = var800a4ce8[roomnum].unk02;

			if (draworder > var800a4640.unk000[index].draworder) {
				var800a4640.unk000[index].draworder = draworder;

				if (var800a4ce6 < var800a4640.unk000[index].draworder) {
					var800a4ce6 = var800a4640.unk000[index].draworder;
				}

				if (var800a4ce4 > var800a4640.unk000[index].draworder) {
					var800a4ce4 = var800a4640.unk000[index].draworder;
				}
			}

			boxExpand(&var800a4640.unk000[index].box, box);
		} else {
			index = var8007fc2c;

			if (index > 59) {
				index = 59;
			}

			var800a4640.unk000[index].roomnum = roomnum;
			var800a4640.unk000[index].draworder = draworder;

			var800a4640.unk000[index].box.xmin = box->xmin;
			var800a4640.unk000[index].box.ymin = box->ymin;
			var800a4640.unk000[index].box.xmax = box->xmax;
			var800a4640.unk000[index].box.ymax = box->ymax;

			if (var800a4ce6 < var800a4640.unk000[index].draworder) {
				var800a4ce6 = var800a4640.unk000[index].draworder;
			}

			if (var800a4ce4 > var800a4640.unk000[index].draworder) {
				var800a4ce4 = var800a4640.unk000[index].draworder;
			}

			var800a4ce8[roomnum].unk00 = var8007fc3c;
			var800a4ce8[roomnum].unk02 = index;

			var8007fc30++;

			if (var8007fc30 < 60) {
				var8007fc2c = var8007fc30;
			}

			roomUnpauseProps(roomnum, false);

			if (g_Rooms[roomnum].loaded240 == 0 && var8007fc10 > 0) {
				var8007fc10--;
				bgLoadRoom(roomnum);
			} else if (g_Rooms[roomnum].loaded240 == 0) {
				var8007fc10--;
			}
		}
	}
}

void func0f158108(s32 roomnum, u8 *arg1, u8 *arg2)
{
	*arg1 = g_BgRooms[roomnum].unk10;
	*arg2 = g_BgRooms[roomnum].unk11;
}

struct var800a4640_00 *func0f158140(s32 roomnum)
{
	s32 index = 60;

	if (var8007fc3c == var800a4ce8[roomnum].unk00) {
		index = var800a4ce8[roomnum].unk02;
	}

	return &var800a4640.unk000[index];
}

Gfx *bg0f158184(Gfx *gdl, struct xraydata *xraydata)
{
	struct gfxvtx *vertices;
	u32 *colours;
	s32 numgroups;
	s32 i;
	s32 count;

	if (xraydata->numtris > 0) {
		vertices = gfxAllocateVertices(xraydata->numvertices);
		colours = gfxAllocateColours(xraydata->numvertices);

		for (i = 0; i < xraydata->numvertices; i++) {
			vertices[i].x = xraydata->vertices[i][0];
			vertices[i].y = xraydata->vertices[i][1];
			vertices[i].z = xraydata->vertices[i][2];
			vertices[i].colour = i << 2;
			colours[i] = xraydata->colours[i];
		}

		count = xraydata->numvertices;
		gDPSetColorArray(gdl++, colours, count);

		count = xraydata->numvertices;
		gDPSetVerticeArray(gdl++, vertices, count);

		numgroups = (xraydata->numtris - 1) / 4 + 1;

		// @bug: The original code overflows the tris array and unintentionally writes zero
		// into the xraydata->numtris property. IDO reloads the xraydata->numtris value
		// on each loop iteration so it reads the 0 value and ends the loop.
#ifdef AVOID_UB
		for (i = xraydata->numtris; i < numgroups * 4; i++) {
			xraydata->tris[i][0] = xraydata->tris[i][1] = xraydata->tris[i][2] = 0;
		}
#else
		for (i = xraydata->numtris; i < xraydata->numtris * 4; i++) {
			xraydata->tris[i][0] = xraydata->tris[i][1] = xraydata->tris[i][2] = 0;
		}
#endif

		for (i = 0; i < numgroups; i++) {
			gDPTri4(gdl++,
					xraydata->tris[i * 4 + 0][0], xraydata->tris[i * 4 + 0][1], xraydata->tris[i * 4 + 0][2],
					xraydata->tris[i * 4 + 1][0], xraydata->tris[i * 4 + 1][1], xraydata->tris[i * 4 + 1][2],
					xraydata->tris[i * 4 + 2][0], xraydata->tris[i * 4 + 2][1], xraydata->tris[i * 4 + 2][2],
					xraydata->tris[i * 4 + 3][0], xraydata->tris[i * 4 + 3][1], xraydata->tris[i * 4 + 3][2]);
		}
	}

	xraydata->numtris = 0;
	xraydata->numvertices = 0;

	return gdl;
}

Gfx *func0f158400(Gfx *gdl, struct xraydata *xraydata, s16 vertices1[3], s16 vertices2[3], s16 vertices3[3], u32 colour1, u32 colour2, u32 colour3)
{
	s16 sp30[3] = {-1, -1, -1};
	s32 count = 0;
	s16 i;

	if (xraydata->numtris >= 64) {
		gdl = bg0f158184(gdl, xraydata);
	}

	for (i = 0; i < xraydata->numvertices && sp30[0] == -1; i++) {
		if (vertices1[0] == xraydata->vertices[i][0]
				&& vertices1[1] == xraydata->vertices[i][1]
				&& vertices1[2] == xraydata->vertices[i][2]) {
			sp30[0] = i;
			count++;
		}
	}

	for (i = 0; i < xraydata->numvertices && sp30[1] == -1; i++) {
		if (vertices2[0] == xraydata->vertices[i][0]
				&& vertices2[1] == xraydata->vertices[i][1]
				&& vertices2[2] == xraydata->vertices[i][2]) {
			sp30[1] = i;
			count++;
		}
	}

	for (i = 0; i < xraydata->numvertices && sp30[2] == -1; i++) {
		if (vertices3[0] == xraydata->vertices[i][0]
				&& vertices3[1] == xraydata->vertices[i][1]
				&& vertices3[2] == xraydata->vertices[i][2]) {
			sp30[2] = i;
			count++;
		}
	}

	if (count < 3) {
		if (xraydata->numvertices - count + 3 > 16) {
			gdl = bg0f158184(gdl, xraydata);

			xraydata->vertices[0][0] = vertices1[0];
			xraydata->vertices[0][1] = vertices1[1];
			xraydata->vertices[0][2] = vertices1[2];
			xraydata->colours[0] = colour1;

			xraydata->vertices[1][0] = vertices2[0];
			xraydata->vertices[1][1] = vertices2[1];
			xraydata->vertices[1][2] = vertices2[2];
			xraydata->colours[1] = colour2;

			xraydata->vertices[2][0] = vertices3[0];
			xraydata->vertices[2][1] = vertices3[1];
			xraydata->vertices[2][2] = vertices3[2];
			xraydata->colours[2] = colour3;

			xraydata->numvertices = 3;

			sp30[0] = 0;
			sp30[1] = 1;
			sp30[2] = 2;
		} else {
			if (sp30[0] == -1) {
				xraydata->vertices[xraydata->numvertices][0] = vertices1[0];
				xraydata->vertices[xraydata->numvertices][1] = vertices1[1];
				xraydata->vertices[xraydata->numvertices][2] = vertices1[2];
				xraydata->colours[xraydata->numvertices] = colour1;

				sp30[0] = xraydata->numvertices;

				xraydata->numvertices++;
			}

			if (sp30[1] == -1) {
				xraydata->vertices[xraydata->numvertices][0] = vertices2[0];
				xraydata->vertices[xraydata->numvertices][1] = vertices2[1];
				xraydata->vertices[xraydata->numvertices][2] = vertices2[2];
				xraydata->colours[xraydata->numvertices] = colour2;

				sp30[1] = xraydata->numvertices;

				xraydata->numvertices++;
			}

			if (sp30[2] == -1) {
				xraydata->vertices[xraydata->numvertices][0] = vertices3[0];
				xraydata->vertices[xraydata->numvertices][1] = vertices3[1];
				xraydata->vertices[xraydata->numvertices][2] = vertices3[2];
				xraydata->colours[xraydata->numvertices] = colour3;

				sp30[2] = xraydata->numvertices;

				xraydata->numvertices++;
			}
		}
	}

	xraydata->tris[xraydata->numtris][0] = sp30[0];
	xraydata->tris[xraydata->numtris][1] = sp30[1];
	xraydata->tris[xraydata->numtris][2] = sp30[2];
	xraydata->numtris++;

	return gdl;
}

void bgChooseXrayVtxColour(bool *inrange, s16 vertex[3], u32 *colour, struct xraydata *xraydata)
{
	f32 sp2c[3];
	f32 f12;
	f32 alphafrac;
	f32 anglefrac;
	struct player *player = g_Vars.currentplayer;
	f32 colfrac;

	*inrange = false;

	sp2c[0] = (f32) vertex[0] - (f32) xraydata->unk000;
	sp2c[0] = sp2c[0] * sp2c[0];

	if (sp2c[0] < xraydata->unk010) {
		sp2c[2] = (f32) vertex[2] - (f32) xraydata->unk008;
		sp2c[2] = sp2c[2] * sp2c[2];

		if (sp2c[2] < xraydata->unk010) {
			sp2c[1] = (f32) vertex[1] - (f32) xraydata->unk004;
			sp2c[1] = sp2c[1] * sp2c[1];

			if (sp2c[1] < xraydata->unk010) {
				f32 dist = sqrtf(sp2c[0] + sp2c[1] + sp2c[2]);

				if (dist < xraydata->unk00c) {
					*inrange = true;

					f12 = dist / xraydata->unk00c;

					if (xraydata->unk014 < f12) {
						alphafrac = 1.0f - (f12 - xraydata->unk014) / (1.0f - xraydata->unk014);
					} else {
						alphafrac = 1.0f;
					}

					if (f12 < xraydata->unk01c) {
						anglefrac = xraydata->unk01c;
						anglefrac = f12 / anglefrac;

						if (1);

						colfrac = sinf((1.0f - anglefrac) * 1.5707964f);

						*colour = (u32)(colfrac * 255.0f) << player->ecol_1
							| (u32)((1.0f - colfrac) * 255.0f) << player->ecol_2
							| (u32)(alphafrac * 128.0f);
					} else {
						anglefrac = (f12 - xraydata->unk01c) / (1.0f - xraydata->unk01c);
						anglefrac = 0.65f * anglefrac + 0.35f;

						if (1);

						colfrac = sinf(anglefrac * 1.5707964f);

						*colour = (u32)(colfrac * 255.0f) << player->ecol_3
							| 0xff << player->ecol_2
							| (u32)(alphafrac * 128.0f);
					}
				}
			}
		}
	}

	if (*inrange == false) {
		*colour = 0x0000ff00;
	}
}

Gfx *func0f158d9c(Gfx *gdl, struct xraydata *xraydata, s16 arg2[3], s16 arg3[3], s16 arg4[3], s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
{
	s32 spa4[3];
	s16 sp9c[3] = {0, 0, 0};
	s32 sum;
	s16 sp84[3][3];
	bool inrange[3];
	u32 colours[3];
	s32 sp68 = -1;
	s32 sp64 = 0;

	if (xraydata->unk020 > 0) {
		spa4[0] = arg3[0] - arg2[0];
		spa4[1] = arg3[1] - arg2[1];
		spa4[2] = arg3[2] - arg2[2];

		sum = spa4[0] * spa4[0] + spa4[1] * spa4[1] + spa4[2] * spa4[2];

		if (sum > xraydata->unk024) {
			sp84[0][0] = (arg3[0] + arg2[0]) / 2;
			sp84[0][1] = (arg3[1] + arg2[1]) / 2;
			sp84[0][2] = (arg3[2] + arg2[2]) / 2;
			sp9c[0] = 1;

			sp64++;
			sp68 = 0;

			bgChooseXrayVtxColour(&inrange[0], sp84[0], &colours[0], xraydata);
		}

		spa4[0] = arg4[0] - arg3[0];
		spa4[1] = arg4[1] - arg3[1];
		spa4[2] = arg4[2] - arg3[2];

		sum = spa4[0] * spa4[0] + spa4[1] * spa4[1] + spa4[2] * spa4[2];

		if (sum > xraydata->unk024) {
			sp84[1][0] = (arg4[0] + arg3[0]) / 2;
			sp84[1][1] = (arg4[1] + arg3[1]) / 2;
			sp84[1][2] = (arg4[2] + arg3[2]) / 2;
			sp9c[1] = 1;

			sp64++;
			sp68 = 1;

			bgChooseXrayVtxColour(&inrange[1], sp84[1], &colours[1], xraydata);
		}

		spa4[0] = arg2[0] - arg4[0];
		spa4[1] = arg2[1] - arg4[1];
		spa4[2] = arg2[2] - arg4[2];

		sum = spa4[0] * spa4[0] + spa4[1] * spa4[1] + spa4[2] * spa4[2];

		if (sum > xraydata->unk024) {
			sp84[2][0] = (arg2[0] + arg4[0]) / 2;
			sp84[2][1] = (arg2[1] + arg4[1]) / 2;
			sp84[2][2] = (arg2[2] + arg4[2]) / 2;
			sp9c[2] = 1;

			sp64++;
			sp68 = 2;

			bgChooseXrayVtxColour(&inrange[2], sp84[2], &colours[2], xraydata);
		}
	}

	if (sp64 == 0) {
		if (arg8 || arg9 || arg10) {
			return func0f158400(gdl, xraydata, arg2, arg3, arg4, arg5, arg6, arg7);
		}
	} else {
		bool render;

		if (arg8 || arg9 || arg10) {
			render = true;
		} else {
			u32 mask1 = 0;
			u32 mask2 = 0;

			render = true;

			mask1 = (arg2[0] < xraydata->unk000) ? 1 : 0;

			if (arg2[1] < xraydata->unk004) {
				mask1 |= 2;
			}

			if (arg2[2] < xraydata->unk008) {
				mask1 |= 4;
			}

			mask2 = (arg3[0] < xraydata->unk000) ? 1 : 0;

			if (arg3[1] < xraydata->unk004) {
				mask2 |= 2;
			}

			if (arg3[2] < xraydata->unk008) {
				mask2 |= 4;
			}

			if (mask1 == mask2) {
				mask2 = (arg4[0] < xraydata->unk000) ? 1 : 0;

				if (arg4[1] < xraydata->unk004) {
					mask2 |= 2;
				}

				if (arg4[2] < xraydata->unk008) {
					mask2 |= 4;
				}

				if (mask1 == mask2) {
					render = false;
				}
			}
		}

		if (render) {
			if (sp64 == 1) {
				if (sp68 == 0) {
					gdl = func0f158d9c(gdl, xraydata, arg2, sp84[0], arg4, arg5, colours[0], arg7, arg8, inrange[0], arg10);
					gdl = func0f158d9c(gdl, xraydata, arg4, sp84[0], arg3, arg7, colours[0], arg6, arg10, inrange[0], arg9);
				} else if (sp68 == 1) {
					gdl = func0f158d9c(gdl, xraydata, arg3, sp84[1], arg2, arg6, colours[1], arg5, arg9, inrange[1], arg8);
					gdl = func0f158d9c(gdl, xraydata, arg2, sp84[1], arg4, arg5, colours[1], arg7, arg8, inrange[1], arg10);
				} else if (sp68 == 2) {
					gdl = func0f158d9c(gdl, xraydata, arg4, sp84[2], arg3, arg7, colours[2], arg6, arg10, inrange[2], arg9);
					gdl = func0f158d9c(gdl, xraydata, arg3, sp84[2], arg2, arg6, colours[2], arg5, arg9, inrange[2], arg8);
				}
			} else if (sp64 == 2) {
				s32 v0 = 0;

				if (sp9c[1] == 0) {
					v0 = 1;
				}

				if (sp9c[2] == 0) {
					v0 = 2;
				}

				if (v0 == 0) {
					gdl = func0f158d9c(gdl, xraydata, arg4, sp84[2], sp84[1], arg7, colours[2], colours[1], arg10, inrange[2], inrange[1]);
					gdl = func0f158d9c(gdl, xraydata, arg3, sp84[1], sp84[2], arg6, colours[1], colours[2], arg9, inrange[1], inrange[2]);
					gdl = func0f158d9c(gdl, xraydata, arg2, arg3, sp84[2], arg5, arg6, colours[2], arg8, arg9, inrange[2]);
				} else if (v0 == 1) {
					gdl = func0f158d9c(gdl, xraydata, arg2, sp84[0], sp84[2], arg5, colours[0], colours[2], arg8, inrange[0], inrange[2]);
					gdl = func0f158d9c(gdl, xraydata, arg4, sp84[2], sp84[0], arg7, colours[2], colours[0], arg10, inrange[2], inrange[0]);
					gdl = func0f158d9c(gdl, xraydata, arg3, arg4, sp84[0], arg6, arg7, colours[0], arg9, arg10, inrange[0]);
				} else {
					gdl = func0f158d9c(gdl, xraydata, arg3, sp84[1], sp84[0], arg6, colours[1], colours[0], arg9, inrange[1], inrange[0]);
					gdl = func0f158d9c(gdl, xraydata, arg2, sp84[0], sp84[1], arg5, colours[0], colours[1], arg8, inrange[0], inrange[1]);
					gdl = func0f158d9c(gdl, xraydata, arg4, arg2, sp84[1], arg7, arg5, colours[1], arg10, arg8, inrange[1]);
				}
			} else if (sp64 == 3) {
				gdl = func0f158d9c(gdl, xraydata, arg2, sp84[0], sp84[2], arg5, colours[0], colours[2], arg8, inrange[0], inrange[2]);
				gdl = func0f158d9c(gdl, xraydata, arg3, sp84[1], sp84[0], arg6, colours[1], colours[0], arg9, inrange[1], inrange[0]);
				gdl = func0f158d9c(gdl, xraydata, arg4, sp84[2], sp84[1], arg7, colours[2], colours[1], arg10, inrange[2], inrange[1]);
				gdl = func0f158d9c(gdl, xraydata, sp84[0], sp84[1], sp84[2], colours[0], colours[1], colours[2], inrange[0], inrange[1], inrange[2]);
			}
		}
	}

	return gdl;
}

u32 var8007fc54 = 0;
bool g_BgCmdStack[20] = {0};
s32 g_BgCmdStackIndex = 0;
u32 g_BgCmdResult = BGRESULT_TRUE;

#if MATCHING
GLOBAL_ASM(
glabel bg0f1598b4
.late_rodata
glabel var7f1b75c4
.word 0x3f333333
.text
/*  f1598b4:	27bdfc28 */ 	addiu	$sp,$sp,-984
/*  f1598b8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f1598bc:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f1598c0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1598c4:	00e08025 */ 	or	$s0,$a3,$zero
/*  f1598c8:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f1598cc:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f1598d0:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f1598d4:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f1598d8:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1598dc:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1598e0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1598e4:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1598e8:	afa403d8 */ 	sw	$a0,0x3d8($sp)
/*  f1598ec:	0fc59570 */ 	jal	stageGetCurrent
/*  f1598f0:	afa603e0 */ 	sw	$a2,0x3e0($sp)
/*  f1598f4:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f1598f8:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f1598fc:	3c017f1b */ 	lui	$at,%hi(var7f1b75c4)
/*  f159900:	c42075c4 */ 	lwc1	$f0,%lo(var7f1b75c4)($at)
/*  f159904:	c4640028 */ 	lwc1	$f4,0x28($v1)
/*  f159908:	3c013e80 */ 	lui	$at,0x3e80
/*  f15990c:	44815000 */ 	mtc1	$at,$f10
/*  f159910:	e7a40190 */ 	swc1	$f4,0x190($sp)
/*  f159914:	c7a60190 */ 	lwc1	$f6,0x190($sp)
/*  f159918:	3c013e80 */ 	lui	$at,0x3e80
/*  f15991c:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f159920:	00000000 */ 	nop
/*  f159924:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f159928:	44815000 */ 	mtc1	$at,$f10
/*  f15992c:	e7a80194 */ 	swc1	$f8,0x194($sp)
/*  f159930:	e7b0019c */ 	swc1	$f16,0x19c($sp)
/*  f159934:	c4720024 */ 	lwc1	$f18,0x24($v1)
/*  f159938:	46069103 */ 	div.s	$f4,$f18,$f6
/*  f15993c:	e7a401a0 */ 	swc1	$f4,0x1a0($sp)
/*  f159940:	c7a801a0 */ 	lwc1	$f8,0x1a0($sp)
/*  f159944:	4608003c */ 	c.lt.s	$f0,$f8
/*  f159948:	00000000 */ 	nop
/*  f15994c:	45000002 */ 	bc1f	.L0f159958
/*  f159950:	00000000 */ 	nop
/*  f159954:	e7a001a0 */ 	swc1	$f0,0x1a0($sp)
.L0f159958:
/*  f159958:	e7aa0198 */ 	swc1	$f10,0x198($sp)
/*  f15995c:	844e002c */ 	lh	$t6,0x2c($v0)
/*  f159960:	241e0006 */ 	addiu	$s8,$zero,0x6
/*  f159964:	27b70120 */ 	addiu	$s7,$sp,0x120
/*  f159968:	01ce0019 */ 	multu	$t6,$t6
/*  f15996c:	afae01a4 */ 	sw	$t6,0x1a4($sp)
/*  f159970:	0000c012 */ 	mflo	$t8
/*  f159974:	afb801a8 */ 	sw	$t8,0x1a8($sp)
/*  f159978:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15997c:	afb90184 */ 	sw	$t9,0x184($sp)
/*  f159980:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f159984:	afae0188 */ 	sw	$t6,0x188($sp)
/*  f159988:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f15998c:	a7a003ce */ 	sh	$zero,0x3ce($sp)
/*  f159990:	a7a003cc */ 	sh	$zero,0x3cc($sp)
/*  f159994:	afaf018c */ 	sw	$t7,0x18c($sp)
.L0f159998:
/*  f159998:	82c20000 */ 	lb	$v0,0x0($s6)
/*  f15999c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f1599a0:	1041014f */ 	beq	$v0,$at,.L0f159ee0
/*  f1599a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1599a8:	1041014b */ 	beq	$v0,$at,.L0f159ed8
/*  f1599ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1599b0:	5441002a */ 	bnel	$v0,$at,.L0f159a5c
/*  f1599b4:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f1599b8:	92c20001 */ 	lbu	$v0,0x1($s6)
/*  f1599bc:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f1599c0:	3c0100ff */ 	lui	$at,0xff
/*  f1599c4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1599c8:	0002a902 */ 	srl	$s5,$v0,0x4
/*  f1599cc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1599d0:	0081c024 */ 	and	$t8,$a0,$at
/*  f1599d4:	03002025 */ 	or	$a0,$t8,$zero
/*  f1599d8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1599dc:	1aa0013e */ 	blez	$s5,.L0f159ed8
/*  f1599e0:	3043000f */ 	andi	$v1,$v0,0xf
/*  f1599e4:	8fb803e0 */ 	lw	$t8,0x3e0($sp)
/*  f1599e8:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1599ec:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1599f0:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1599f4:	00037080 */ 	sll	$t6,$v1,0x2
/*  f1599f8:	27af00e0 */ 	addiu	$t7,$sp,0xe0
/*  f1599fc:	01cfa021 */ 	addu	$s4,$t6,$t7
/*  f159a00:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f159a04:	27b300a0 */ 	addiu	$s3,$sp,0xa0
/*  f159a08:	03048821 */ 	addu	$s1,$t8,$a0
.L0f159a0c:
/*  f159a0c:	86390000 */ 	lh	$t9,0x0($s1)
/*  f159a10:	02602025 */ 	or	$a0,$s3,$zero
/*  f159a14:	02002825 */ 	or	$a1,$s0,$zero
/*  f159a18:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f159a1c:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f159a20:	02803025 */ 	or	$a2,$s4,$zero
/*  f159a24:	27a70184 */ 	addiu	$a3,$sp,0x184
/*  f159a28:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f159a2c:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f159a30:	0fc56221 */ 	jal	bgChooseXrayVtxColour
/*  f159a34:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f159a38:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f159a3c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f159a40:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f159a44:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f159a48:	1655fff0 */ 	bne	$s2,$s5,.L0f159a0c
/*  f159a4c:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f159a50:	1000ffd1 */ 	b	.L0f159998
/*  f159a54:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f159a58:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f159a5c:
/*  f159a5c:	14410056 */ 	bne	$v0,$at,.L0f159bb8
/*  f159a60:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f159a64:	92d80005 */ 	lbu	$t8,0x5($s6)
/*  f159a68:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f159a6c:	92cf0006 */ 	lbu	$t7,0x6($s6)
/*  f159a70:	031f001a */ 	div	$zero,$t8,$ra
/*  f159a74:	00001012 */ 	mflo	$v0
/*  f159a78:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f159a7c:	00197403 */ 	sra	$t6,$t9,0x10
/*  f159a80:	01ff001a */ 	div	$zero,$t7,$ra
/*  f159a84:	01c01025 */ 	or	$v0,$t6,$zero
/*  f159a88:	00001812 */ 	mflo	$v1
/*  f159a8c:	92ce0007 */ 	lbu	$t6,0x7($s6)
/*  f159a90:	27ac00e0 */ 	addiu	$t4,$sp,0xe0
/*  f159a94:	17e00002 */ 	bnez	$ra,.L0f159aa0
/*  f159a98:	00000000 */ 	nop
/*  f159a9c:	0007000d */ 	break	0x7
.L0f159aa0:
/*  f159aa0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159aa4:	17e10004 */ 	bne	$ra,$at,.L0f159ab8
/*  f159aa8:	3c018000 */ 	lui	$at,0x8000
/*  f159aac:	17010002 */ 	bne	$t8,$at,.L0f159ab8
/*  f159ab0:	00000000 */ 	nop
/*  f159ab4:	0006000d */ 	break	0x6
.L0f159ab8:
/*  f159ab8:	01df001a */ 	div	$zero,$t6,$ra
/*  f159abc:	00004012 */ 	mflo	$t0
/*  f159ac0:	0003c400 */ 	sll	$t8,$v1,0x10
/*  f159ac4:	0018cc03 */ 	sra	$t9,$t8,0x10
/*  f159ac8:	005e0019 */ 	multu	$v0,$s8
/*  f159acc:	03201825 */ 	or	$v1,$t9,$zero
/*  f159ad0:	17e00002 */ 	bnez	$ra,.L0f159adc
/*  f159ad4:	00000000 */ 	nop
/*  f159ad8:	0007000d */ 	break	0x7
.L0f159adc:
/*  f159adc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159ae0:	17e10004 */ 	bne	$ra,$at,.L0f159af4
/*  f159ae4:	3c018000 */ 	lui	$at,0x8000
/*  f159ae8:	15e10002 */ 	bne	$t7,$at,.L0f159af4
/*  f159aec:	00000000 */ 	nop
/*  f159af0:	0006000d */ 	break	0x6
.L0f159af4:
/*  f159af4:	0000c812 */ 	mflo	$t9
/*  f159af8:	00087c00 */ 	sll	$t7,$t0,0x10
/*  f159afc:	17e00002 */ 	bnez	$ra,.L0f159b08
/*  f159b00:	00000000 */ 	nop
/*  f159b04:	0007000d */ 	break	0x7
.L0f159b08:
/*  f159b08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159b0c:	17e10004 */ 	bne	$ra,$at,.L0f159b20
/*  f159b10:	3c018000 */ 	lui	$at,0x8000
/*  f159b14:	15c10002 */ 	bne	$t6,$at,.L0f159b20
/*  f159b18:	00000000 */ 	nop
/*  f159b1c:	0006000d */ 	break	0x6
.L0f159b20:
/*  f159b20:	007e0019 */ 	multu	$v1,$s8
/*  f159b24:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f159b28:	03004025 */ 	or	$t0,$t8,$zero
/*  f159b2c:	02f93021 */ 	addu	$a2,$s7,$t9
/*  f159b30:	00024880 */ 	sll	$t1,$v0,0x2
/*  f159b34:	0189c821 */ 	addu	$t9,$t4,$t1
/*  f159b38:	00035080 */ 	sll	$t2,$v1,0x2
/*  f159b3c:	00085880 */ 	sll	$t3,$t0,0x2
/*  f159b40:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159b44:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159b48:	00007012 */ 	mflo	$t6
/*  f159b4c:	02ee3821 */ 	addu	$a3,$s7,$t6
/*  f159b50:	00000000 */ 	nop
/*  f159b54:	031e0019 */ 	multu	$t8,$s8
/*  f159b58:	00007812 */ 	mflo	$t7
/*  f159b5c:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f159b60:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f159b64:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b68:	018a7821 */ 	addu	$t7,$t4,$t2
/*  f159b6c:	018bc821 */ 	addu	$t9,$t4,$t3
/*  f159b70:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f159b74:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159b78:	01a97821 */ 	addu	$t7,$t5,$t1
/*  f159b7c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f159b80:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b84:	01aac821 */ 	addu	$t9,$t5,$t2
/*  f159b88:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f159b8c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159b90:	01ab7821 */ 	addu	$t7,$t5,$t3
/*  f159b94:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f159b98:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b9c:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f159ba0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ba4:	0fc56367 */ 	jal	func0f158d9c
/*  f159ba8:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159bac:	afa203d8 */ 	sw	$v0,0x3d8($sp)
/*  f159bb0:	1000ff79 */ 	b	.L0f159998
/*  f159bb4:	26d60008 */ 	addiu	$s6,$s6,0x8
.L0f159bb8:
/*  f159bb8:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f159bbc:	144100c6 */ 	bne	$v0,$at,.L0f159ed8
/*  f159bc0:	00000000 */ 	nop
/*  f159bc4:	8ed00004 */ 	lw	$s0,0x4($s6)
/*  f159bc8:	92d10007 */ 	lbu	$s1,0x7($s6)
/*  f159bcc:	8ed20000 */ 	lw	$s2,0x0($s6)
/*  f159bd0:	3219000f */ 	andi	$t9,$s0,0xf
/*  f159bd4:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159bd8:	000e8403 */ 	sra	$s0,$t6,0x10
/*  f159bdc:	021e0019 */ 	multu	$s0,$s8
/*  f159be0:	0011c102 */ 	srl	$t8,$s1,0x4
/*  f159be4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159be8:	00198c03 */ 	sra	$s1,$t9,0x10
/*  f159bec:	324f000f */ 	andi	$t7,$s2,0xf
/*  f159bf0:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159bf4:	00189403 */ 	sra	$s2,$t8,0x10
/*  f159bf8:	27a200e0 */ 	addiu	$v0,$sp,0xe0
/*  f159bfc:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159c00:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159c04:	00007012 */ 	mflo	$t6
/*  f159c08:	02ee3021 */ 	addu	$a2,$s7,$t6
/*  f159c0c:	00537021 */ 	addu	$t6,$v0,$s3
/*  f159c10:	023e0019 */ 	multu	$s1,$s8
/*  f159c14:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159c18:	27a300a0 */ 	addiu	$v1,$sp,0xa0
/*  f159c1c:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159c20:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159c24:	00007812 */ 	mflo	$t7
/*  f159c28:	02ef3821 */ 	addu	$a3,$s7,$t7
/*  f159c2c:	00000000 */ 	nop
/*  f159c30:	025e0019 */ 	multu	$s2,$s8
/*  f159c34:	0000c012 */ 	mflo	$t8
/*  f159c38:	02f8c821 */ 	addu	$t9,$s7,$t8
/*  f159c3c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f159c40:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c44:	0054c021 */ 	addu	$t8,$v0,$s4
/*  f159c48:	00557021 */ 	addu	$t6,$v0,$s5
/*  f159c4c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f159c50:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c54:	0073c021 */ 	addu	$t8,$v1,$s3
/*  f159c58:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f159c5c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c60:	00747021 */ 	addu	$t6,$v1,$s4
/*  f159c64:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f159c68:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c6c:	0075c021 */ 	addu	$t8,$v1,$s5
/*  f159c70:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f159c74:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c78:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f159c7c:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c80:	0fc56367 */ 	jal	func0f158d9c
/*  f159c84:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f159c88:	92d00006 */ 	lbu	$s0,0x6($s6)
/*  f159c8c:	96d10006 */ 	lhu	$s1,0x6($s6)
/*  f159c90:	92d20003 */ 	lbu	$s2,0x3($s6)
/*  f159c94:	320e000f */ 	andi	$t6,$s0,0xf
/*  f159c98:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159c9c:	000f8403 */ 	sra	$s0,$t7,0x10
/*  f159ca0:	021e0019 */ 	multu	$s0,$s8
/*  f159ca4:	0011cb02 */ 	srl	$t9,$s1,0xc
/*  f159ca8:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159cac:	000e8c03 */ 	sra	$s1,$t6,0x10
/*  f159cb0:	0012c102 */ 	srl	$t8,$s2,0x4
/*  f159cb4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159cb8:	00199403 */ 	sra	$s2,$t9,0x10
/*  f159cbc:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159cc0:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159cc4:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159cc8:	00007812 */ 	mflo	$t7
/*  f159ccc:	02ef3021 */ 	addu	$a2,$s7,$t7
/*  f159cd0:	00737821 */ 	addu	$t7,$v1,$s3
/*  f159cd4:	023e0019 */ 	multu	$s1,$s8
/*  f159cd8:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159cdc:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159ce0:	00402025 */ 	or	$a0,$v0,$zero
/*  f159ce4:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159ce8:	0000c012 */ 	mflo	$t8
/*  f159cec:	02f83821 */ 	addu	$a3,$s7,$t8
/*  f159cf0:	00000000 */ 	nop
/*  f159cf4:	025e0019 */ 	multu	$s2,$s8
/*  f159cf8:	0000c812 */ 	mflo	$t9
/*  f159cfc:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f159d00:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f159d04:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d08:	0074c821 */ 	addu	$t9,$v1,$s4
/*  f159d0c:	00757821 */ 	addu	$t7,$v1,$s5
/*  f159d10:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f159d14:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d18:	0113c821 */ 	addu	$t9,$t0,$s3
/*  f159d1c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f159d20:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d24:	01147821 */ 	addu	$t7,$t0,$s4
/*  f159d28:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f159d2c:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d30:	0115c821 */ 	addu	$t9,$t0,$s5
/*  f159d34:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f159d38:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d3c:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f159d40:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d44:	0fc56367 */ 	jal	func0f158d9c
/*  f159d48:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f159d4c:	96d00004 */ 	lhu	$s0,0x4($s6)
/*  f159d50:	92d10005 */ 	lbu	$s1,0x5($s6)
/*  f159d54:	92d20002 */ 	lbu	$s2,0x2($s6)
/*  f159d58:	320f000f */ 	andi	$t7,$s0,0xf
/*  f159d5c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159d60:	00188403 */ 	sra	$s0,$t8,0x10
/*  f159d64:	021e0019 */ 	multu	$s0,$s8
/*  f159d68:	00117102 */ 	srl	$t6,$s1,0x4
/*  f159d6c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159d70:	000f8c03 */ 	sra	$s1,$t7,0x10
/*  f159d74:	3259000f */ 	andi	$t9,$s2,0xf
/*  f159d78:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159d7c:	000e9403 */ 	sra	$s2,$t6,0x10
/*  f159d80:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159d84:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159d88:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159d8c:	0000c012 */ 	mflo	$t8
/*  f159d90:	02f83021 */ 	addu	$a2,$s7,$t8
/*  f159d94:	0073c021 */ 	addu	$t8,$v1,$s3
/*  f159d98:	023e0019 */ 	multu	$s1,$s8
/*  f159d9c:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159da0:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159da4:	00402025 */ 	or	$a0,$v0,$zero
/*  f159da8:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159dac:	0000c812 */ 	mflo	$t9
/*  f159db0:	02f93821 */ 	addu	$a3,$s7,$t9
/*  f159db4:	00000000 */ 	nop
/*  f159db8:	025e0019 */ 	multu	$s2,$s8
/*  f159dbc:	00007012 */ 	mflo	$t6
/*  f159dc0:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f159dc4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f159dc8:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159dcc:	00747021 */ 	addu	$t6,$v1,$s4
/*  f159dd0:	0075c021 */ 	addu	$t8,$v1,$s5
/*  f159dd4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f159dd8:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159ddc:	01137021 */ 	addu	$t6,$t0,$s3
/*  f159de0:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f159de4:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159de8:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f159dec:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f159df0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159df4:	01157021 */ 	addu	$t6,$t0,$s5
/*  f159df8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f159dfc:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159e00:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f159e04:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159e08:	0fc56367 */ 	jal	func0f158d9c
/*  f159e0c:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f159e10:	92d00004 */ 	lbu	$s0,0x4($s6)
/*  f159e14:	8ed10004 */ 	lw	$s1,0x4($s6)
/*  f159e18:	96d20002 */ 	lhu	$s2,0x2($s6)
/*  f159e1c:	3218000f */ 	andi	$t8,$s0,0xf
/*  f159e20:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159e24:	00198403 */ 	sra	$s0,$t9,0x10
/*  f159e28:	021e0019 */ 	multu	$s0,$s8
/*  f159e2c:	00117f02 */ 	srl	$t7,$s1,0x1c
/*  f159e30:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159e34:	00188c03 */ 	sra	$s1,$t8,0x10
/*  f159e38:	00127302 */ 	srl	$t6,$s2,0xc
/*  f159e3c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159e40:	000f9403 */ 	sra	$s2,$t7,0x10
/*  f159e44:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159e48:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159e4c:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159e50:	0000c812 */ 	mflo	$t9
/*  f159e54:	02f93021 */ 	addu	$a2,$s7,$t9
/*  f159e58:	0073c821 */ 	addu	$t9,$v1,$s3
/*  f159e5c:	023e0019 */ 	multu	$s1,$s8
/*  f159e60:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159e64:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159e68:	00402025 */ 	or	$a0,$v0,$zero
/*  f159e6c:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159e70:	00007012 */ 	mflo	$t6
/*  f159e74:	02ee3821 */ 	addu	$a3,$s7,$t6
/*  f159e78:	00000000 */ 	nop
/*  f159e7c:	025e0019 */ 	multu	$s2,$s8
/*  f159e80:	00007812 */ 	mflo	$t7
/*  f159e84:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f159e88:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f159e8c:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159e90:	00747821 */ 	addu	$t7,$v1,$s4
/*  f159e94:	0075c821 */ 	addu	$t9,$v1,$s5
/*  f159e98:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f159e9c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ea0:	01137821 */ 	addu	$t7,$t0,$s3
/*  f159ea4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f159ea8:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159eac:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f159eb0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f159eb4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159eb8:	01157821 */ 	addu	$t7,$t0,$s5
/*  f159ebc:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f159ec0:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159ec4:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f159ec8:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ecc:	0fc56367 */ 	jal	func0f158d9c
/*  f159ed0:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159ed4:	afa203d8 */ 	sw	$v0,0x3d8($sp)
.L0f159ed8:
/*  f159ed8:	1000feaf */ 	b	.L0f159998
/*  f159edc:	26d60008 */ 	addiu	$s6,$s6,0x8
.L0f159ee0:
/*  f159ee0:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159ee4:	0fc56061 */ 	jal	bg0f158184
/*  f159ee8:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159eec:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f159ef0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f159ef4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f159ef8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f159efc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f159f00:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f159f04:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f159f08:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f159f0c:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f159f10:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f159f14:	03e00008 */ 	jr	$ra
/*  f159f18:	27bd03d8 */ 	addiu	$sp,$sp,0x3d8
);
#else
// Mismatch: Regalloc and some reordered instructions
Gfx *bg0f1598b4(Gfx *gdl, Gfx *gdl2, struct gfxvtx *vertices, s16 arg3[3])
{
	s32 i;
	s32 stack;
	struct xraydata xraydata;
	struct stagetableentry *stage = stageGetCurrent();
	s16 sp120[16][3];
	u32 colours[16];
	bool inrange[16];

	xraydata.unk00c = g_Vars.currentplayer->eraserbgdist;
	xraydata.unk010 = xraydata.unk00c * xraydata.unk00c;
	xraydata.unk018 = xraydata.unk00c * 0.25f;
	xraydata.unk01c = g_Vars.currentplayer->eraserpropdist / xraydata.unk00c;

	if (xraydata.unk01c > 0.7f) {
		xraydata.unk01c = 0.7f;
	}

	xraydata.unk014 = 0.250f;
	xraydata.unk020 = stage->unk2c;
	xraydata.unk024 = xraydata.unk020 * xraydata.unk020;
	xraydata.unk000 = arg3[0];
	xraydata.unk004 = arg3[1];
	xraydata.unk008 = arg3[2];
	xraydata.numtris = 0;
	xraydata.numvertices = 0;

	while (true) {
		if (gdl2->dma.cmd == G_ENDDL) {
			break;
		}

		if (gdl2->dma.cmd == G_MTX) {
			// empty
		} else if (gdl2->dma.cmd == G_VTX) {
			s32 index = gdl2->bytes[1] & 0xf;
			s32 numvertices = (((u32)gdl2->bytes[1] >> 4)) + 1;
			s32 offset = (gdl2->words.w1 & 0xffffff);
			struct gfxvtx *vtx = (struct gfxvtx *)((u32)vertices + offset);
			u32 stack[4];

			for (i = 0; i < numvertices; i++) {
				sp120[index + i][0] = vtx->x;
				sp120[index + i][1] = vtx->y;
				sp120[index + i][2] = vtx->z;

				bgChooseXrayVtxColour(&inrange[i], sp120[index + i], &colours[index + i], &xraydata);

				vtx++;
			}
		} else if (gdl2->dma.cmd == G_TRI1) {
			s16 x = gdl2->tri.tri.v[0] / 10;
			s16 y = gdl2->tri.tri.v[1] / 10;
			s16 z = gdl2->tri.tri.v[2] / 10;

			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
		} else if (gdl2->dma.cmd == G_TRI4) {
			s16 x;
			s16 y;
			s16 z;

			x = gdl2->tri4.x1;
			y = gdl2->tri4.y1;
			z = gdl2->tri4.z1;

			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);

			x = gdl2->tri4.x2;
			y = gdl2->tri4.y2;
			z = gdl2->tri4.z2;

			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);

			x = gdl2->tri4.x3;
			y = gdl2->tri4.y3;
			z = gdl2->tri4.z3;

			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);

			x = gdl2->tri4.x4;
			y = gdl2->tri4.y4;
			z = gdl2->tri4.z4;

			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
		}

		gdl2++;
	}

	gdl = bg0f158184(gdl, &xraydata);

	return gdl;
}
#endif

Gfx *bgRenderRoomXrayPass(Gfx *gdl, s32 roomnum, struct roomblock *block, bool recurse, s16 arg4[3])
{
	struct player *player = g_Vars.currentplayer;

	if (block == NULL) {
		return gdl;
	}

	switch (block->type) {
	case ROOMBLOCKTYPE_LEAF:
		gdl = bg0f1598b4(gdl, block->gdl, block->vertices, arg4);

		if (recurse) {
			gdl = bgRenderRoomXrayPass(gdl, roomnum, block->next, true, arg4);
		}
		break;
	case ROOMBLOCKTYPE_PARENT:
		if (block->child != NULL) {
			struct roomblock *child1 = block->child;
			struct roomblock *child2 = child1->next;
			struct coord *coords = block->unk0c;
			struct coord sp34;
			struct coord sp28;
			f32 sum;

			sp34.x = coords[1].x;
			sp34.y = coords[1].y;
			sp34.z = coords[1].z;

			sp28.x = coords[0].x - player->cam_pos.x;
			sp28.y = coords[0].y - player->cam_pos.y;
			sp28.z = coords[0].z - player->cam_pos.z;

			sum = sp34.f[0] * sp28.f[0] + sp34.f[1] * sp28.f[1] + sp34.f[2] * sp28.f[2];

			if (sum < 0.0f) {
				gdl = bgRenderRoomXrayPass(gdl, roomnum, child1, false, arg4);
				gdl = bgRenderRoomXrayPass(gdl, roomnum, child2, false, arg4);
			} else {
				gdl = bgRenderRoomXrayPass(gdl, roomnum, child2, false, arg4);
				gdl = bgRenderRoomXrayPass(gdl, roomnum, child1, false, arg4);
			}

			if (recurse) {
				gdl = bgRenderRoomXrayPass(gdl, roomnum, block->next, true, arg4);
			}
		}
		break;
	}

	return gdl;
}

/**
 * Render the given room for the purpose of the FarSight or xray scanner.
 */
Gfx *bgRenderRoomInXray(Gfx *gdl, s32 roomnum)
{
	struct coord sp54;
	struct coord globaldrawworldoffset;
	s16 sp40[3];
	struct player *player = g_Vars.currentplayer;

	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return gdl;
	}

	if (g_Rooms[roomnum].loaded240 == 0) {
		if (var8007fc10 > 0) {
			var8007fc10--;
			bgLoadRoom(roomnum);
		}
	}

	if (g_Rooms[roomnum].loaded240 == 0) {
		var8007fc10--;
	}

	if (g_Rooms[roomnum].loaded240 == 0) {
		return gdl;
	}

	room0f166df0(roomnum, &globaldrawworldoffset);

	sp54.x = player->eraserpos.x - globaldrawworldoffset.x;
	sp54.y = player->eraserpos.y - globaldrawworldoffset.y;
	sp54.z = player->eraserpos.z - globaldrawworldoffset.z;

	sp40[0] = sp54.f[0];
	sp40[1] = sp54.f[1];
	sp40[2] = sp54.f[2];

	gdl = roomPushMtx(gdl, roomnum);
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->opablocks, true, sp40);
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->xlublocks, true, sp40);

	g_Rooms[roomnum].loaded240 = 1;

	return gdl;
}

Gfx *bgRenderSceneInXray(Gfx *gdl)
{
	s16 *roomnumptr;
	s16 *room;
	s16 i;
	s32 j;
	s16 roomnumsbyprop[200];
	struct prop *prop;
	struct prop **ptr;
	s32 k;

	roomnumptr = roomnumsbyprop;

	for (ptr = g_Vars.onscreenprops; ptr < g_Vars.endonscreenprops; ptr++) {
		*roomnumptr = 0;
		prop = *ptr;

		if (prop) {
			room = prop->rooms;

			while (*room != -1) {
				if (g_Rooms[*room].flags & ROOMFLAG_ONSCREEN) {
					*roomnumptr = *room;
					break;
				}

				room++;
			}
		}

		roomnumptr++;
	}

	gdl = envStopFog(gdl);

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	// Render BG
	gdl = currentPlayerScissorToViewport(gdl);

	for (i = var800a4ce4; i <= var800a4ce6; i++) {
		for (j = 0; j < var8007fc2c; j++) {
			struct var800a4640_00 *thing = &var800a4640.unk000[j];

			if (thing->draworder == i) {
				gdl = bgRenderRoomInXray(gdl, thing->roomnum);
			}
		}
	}

	// Render props
	gdl = currentPlayerScissorToViewport(gdl);

	gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (var800a4ce4); \
	if (var8007fc2c); \
	for (i = var800a4ce6; i >= var800a4ce4; i--) {
		for (k = 0; k < var8007fc2c; k++) {
			struct var800a4640_00 *thing = &var800a4640.unk000[k];

			if (thing->draworder == i) {
				gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

				gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);

				gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

				if (debugIsPropRenderingEnabled() && getVar80084040()) {
					if (thing->roomnum == -1) {
						gdl = propsRender(gdl, 0, RENDERPASS_XLU, roomnumsbyprop);
					}

					gdl = propsRender(gdl, thing->roomnum, RENDERPASS_XLU, roomnumsbyprop);
				}

				if (1);
			}
		}
	}

	gdl = skyRenderSuns(gdl, true);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *bgRenderScene(Gfx *gdl)
{
	s32 stagenum = g_Vars.stagenum;
	s32 firstroomnum = -1;
	s32 i;
	s32 roomnum;
	s16 roomnumsbyprop[200];
	struct prop **ptr;
	struct var800a4640_00 *thing;
	s16 *roomnumptr;
	struct prop *prop;
	s16 tmp;
	s16 *room;
	s16 roomorder[60];
	s16 roomnums[60];

	g_NumRoomsWithGlares = 0;

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		gdl = bgRenderSceneInXray(gdl);
		return gdl;
	}

	// Build an array of all room numbers, and a parallel array that contains
	// their draw order (as defined by portal code).
	for (roomnum = 0; roomnum < var8007fc2c; roomnum++) {
		roomorder[roomnum] = var800a4640.unk000[roomnum].draworder;
		roomnums[roomnum] = roomnum;
	}

	// Sort them by distance ascending
	if (var8007fc2c >= 2) {
		do {
			i = false;

			for (roomnum = 0; roomnum < var8007fc2c - 1; roomnum++) {
				if (roomorder[roomnum + 1] < roomorder[roomnum]) {
					tmp = roomorder[roomnum];
					roomorder[roomnum] = roomorder[roomnum + 1];
					roomorder[roomnum + 1] = tmp;

					tmp = roomnums[roomnum];
					roomnums[roomnum] = roomnums[roomnum + 1];
					roomnums[roomnum + 1] = tmp;

					i = true;
				}
			}
		} while (i);
	}

	gdl = currentPlayerScissorToViewport(gdl);

	// Render special "always on" rooms, such as the Defection moon,
	// Attack Ship planet, and other sky tricks that are implemented as rooms
	if (!USINGDEVICE(DEVICE_NIGHTVISION) && !USINGDEVICE(DEVICE_IRSCANNER)
			&& (stagenum == g_Stages[STAGEINDEX_INFILTRATION].id
				|| stagenum == g_Stages[STAGEINDEX_RESCUE].id
				|| stagenum == g_Stages[STAGEINDEX_ESCAPE].id
				|| stagenum == g_Stages[STAGEINDEX_MAIANSOS].id
				|| stagenum == g_Stages[STAGEINDEX_SKEDARRUINS].id
				|| stagenum == g_Stages[STAGEINDEX_WAR].id
				|| stagenum == g_Stages[STAGEINDEX_DEFECTION].id
				|| stagenum == g_Stages[STAGEINDEX_EXTRACTION].id
				|| stagenum == g_Stages[STAGEINDEX_MBR].id
				|| stagenum == g_Stages[STAGEINDEX_TEST_OLD].id
				|| stagenum == g_Stages[STAGEINDEX_ATTACKSHIP].id)) {
		gdl = envStopFog(gdl);
		gdl = vi0000ab78(gdl);

		roomnum = -1;

		if (stagenum == g_Stages[STAGEINDEX_INFILTRATION].id
				|| stagenum == g_Stages[STAGEINDEX_RESCUE].id
				|| stagenum == g_Stages[STAGEINDEX_ESCAPE].id
				|| stagenum == g_Stages[STAGEINDEX_MAIANSOS].id) {
			roomnum = 0x0f;
		} else if (stagenum == g_Stages[STAGEINDEX_SKEDARRUINS].id
				|| stagenum == g_Stages[STAGEINDEX_WAR].id) {
			roomnum = 0x02;
		} else if (stagenum == g_Stages[STAGEINDEX_DEFECTION].id
				|| stagenum == g_Stages[STAGEINDEX_EXTRACTION].id
				|| stagenum == g_Stages[STAGEINDEX_MBR].id) {
			roomnum = 0x01;
		} else if (stagenum == g_Stages[STAGEINDEX_TEST_OLD].id) {
			roomnum = 0x01;
		} else if (stagenum == g_Stages[STAGEINDEX_ATTACKSHIP].id) {
			roomnum = 0x71;
		}

		if (PLAYERCOUNT() == 1
				&& (stagenum == STAGE_DEFECTION
					|| stagenum == STAGE_EXTRACTION
					|| stagenum == STAGE_TEST_OLD
					|| stagenum == STAGE_INFILTRATION
					|| stagenum == STAGE_ESCAPE
					|| stagenum == STAGE_ATTACKSHIP)) {
			gdl = text0f153628(gdl);

			gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

			gdl = playerLoadMatrix(gdl);
			gdl = envStopFog(gdl);
			gdl = starsRender(gdl);
			gdl = text0f153780(gdl);
			gdl = vi0000ab78(gdl);
		}

		if (roomnum != -1) {
			if (!g_Rooms[roomnum].loaded240) {
				bgLoadRoom(roomnum);
			}

			gdl = bgRenderRoomOpaque(gdl, roomnum);
		}

		gSPPerspNormalize(gdl++, viGetPerspScale());
	}

	gdl = skyRenderSuns(gdl, false);

	// Build an array of room numbers per onscreen prop.
	// For each onscreen prop there is exactly one entry in the roomnumsbyprop array.
	roomnumptr = roomnumsbyprop; \
	if (var8007fc2c);

	for (ptr = g_Vars.onscreenprops; ptr < g_Vars.endonscreenprops; ptr++) {
		*roomnumptr = 0;
		prop = *ptr;

		if (prop) {
			room = prop->rooms;

			while (*room != -1) {
				if (g_Rooms[*room].flags & ROOMFLAG_ONSCREEN) {
					*roomnumptr = *room;
					break;
				}

				room++;
			}
		}

		roomnumptr++;
	}

	// Render the opaque passes
	for (i = 0; i < var8007fc2c; i++) {
		roomnum = roomnums[i];

		if (firstroomnum < 0) {
			firstroomnum = var800a4640.unk000[roomnum].roomnum;
		}

		thing = &var800a4640.unk000[roomnum];

		// Render prop opaque components - pre BG pass
		gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gdl = envStopFog(gdl);

		if (debugIsPropRenderingEnabled() && getVar80084040()) {
			if (firstroomnum == thing->roomnum) {
				gdl = propsRender(gdl, 0, RENDERPASS_OPA_PREBG, roomnumsbyprop);
			}

			gdl = propsRender(gdl, thing->roomnum, RENDERPASS_OPA_PREBG, roomnumsbyprop);
		}

		// Render BG opaque components
		gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
		gdl = envStartFog(gdl, false);

		if (debugIsBgRenderingEnabled() && getVar80084040()) {
			if (g_StageIndex != STAGEINDEX_TEST_OLD) {
				gdl = bgRenderRoomOpaque(gdl, thing->roomnum);
			}
		}

		// Render prop opaque components - post BG pass
		gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = envStopFog(gdl);

		if (debugIsPropRenderingEnabled() && getVar80084040()) {
			if (firstroomnum == thing->roomnum) {
				gdl = propsRender(gdl, 0, RENDERPASS_OPA_POSTBG, roomnumsbyprop);
			}

			gdl = propsRender(gdl, thing->roomnum, RENDERPASS_OPA_POSTBG, roomnumsbyprop);
		}
	}

	gdl = envStopFog(gdl);
	gdl = currentPlayerScissorToViewport(gdl);

	// Render wall hits
	gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (getVar80084040() && g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
		for (i = 0; i < var8007fc2c; i++) {
			roomnum = roomnums[i];
			gdl = wallhitRenderBgHits(var800a4640.unk000[roomnum].roomnum, gdl);
		}
	}

	// In NTSC 1.0 and newer this hack fixes a regalloc issue.
	// In NTSC beta this same regalloc issue occurs.
	// Applying the hack in NTSC beta fixes the regalloc issue but generates
	// very different code.
#if VERSION >= VERSION_NTSC_1_0
	if (1)
#endif
	for (i = var8007fc2c - 1; i >= 0; i--) {
		roomnum = roomnums[i];

		gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		thing = &var800a4640.unk000[roomnum];

		// Render BG translucent components
		gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
		gdl = envStartFog(gdl, true);

		if (debugIsBgRenderingEnabled() && getVar80084040()) {
			gdl = bgRenderRoomXlu(gdl, thing->roomnum);
		}

		gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = envStopFog(gdl);

		// Render prop translucent components
		if (debugIsPropRenderingEnabled() && getVar80084040()) {
			if (firstroomnum == thing->roomnum) {
				gdl = propsRender(gdl, 0, RENDERPASS_XLU, roomnumsbyprop);
			}

			gdl = propsRender(gdl, thing->roomnum, RENDERPASS_XLU, roomnumsbyprop);
		}

		if (!g_Vars.mplayerisrunning) {
			artifactsCalculateGlaresForRoom(thing->roomnum);

			if (g_NumRoomsWithGlares < 100) {
				g_GlareRooms[g_NumRoomsWithGlares++] = thing->roomnum;
			}
		}
	}

#if VERSION < VERSION_NTSC_1_0
	debug0f119a80nb();
#endif

	return gdl;
}
#else
GLOBAL_ASM(
glabel bgRenderScene
/*  f154d54:	27bdfcc8 */ 	addiu	$sp,$sp,-824
/*  f154d58:	3c0e800a */ 	lui	$t6,0x800a
/*  f154d5c:	8dcee944 */ 	lw	$t6,-0x16bc($t6)
/*  f154d60:	3c018008 */ 	lui	$at,0x8008
/*  f154d64:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f154d68:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f154d6c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f154d70:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f154d74:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f154d78:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f154d7c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f154d80:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f154d84:	ac202478 */ 	sw	$zero,0x2478($at)
/*  f154d88:	95cf0010 */ 	lhu	$t7,0x10($t6)
/*  f154d8c:	3c13800a */ 	lui	$s3,0x800a
/*  f154d90:	24010001 */ 	addiu	$at,$zero,0x1
/*  f154d94:	00808825 */ 	or	$s1,$a0,$zero
/*  f154d98:	8e73eb74 */ 	lw	$s3,-0x148c($s3)
/*  f154d9c:	15e10005 */ 	bne	$t7,$at,.NB0f154db4
/*  f154da0:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f154da4:	0fc55249 */ 	jal	bgRenderSceneInXray
/*  f154da8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154dac:	1000026a */ 	beqz	$zero,.NB0f155758
/*  f154db0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f154db4:
/*  f154db4:	3c098008 */ 	lui	$t1,0x8008
/*  f154db8:	8d292490 */ 	lw	$t1,0x2490($t1)
/*  f154dbc:	00009025 */ 	or	$s2,$zero,$zero
/*  f154dc0:	1920000d */ 	blez	$t1,.NB0f154df8
/*  f154dc4:	3c10800b */ 	lui	$s0,0x800b
/*  f154dc8:	26108dc0 */ 	addiu	$s0,$s0,-29248
/*  f154dcc:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f154dd0:	27a30090 */ 	addiu	$v1,$sp,0x90
.NB0f154dd4:
/*  f154dd4:	a4720000 */ 	sh	$s2,0x0($v1)
/*  f154dd8:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f154ddc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f154de0:	0249082a */ 	slt	$at,$s2,$t1
/*  f154de4:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f154de8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f154dec:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f154df0:	1420fff8 */ 	bnez	$at,.NB0f154dd4
/*  f154df4:	a498fffe */ 	sh	$t8,-0x2($a0)
.NB0f154df8:
/*  f154df8:	29210002 */ 	slti	$at,$t1,0x2
/*  f154dfc:	1420001b */ 	bnez	$at,.NB0f154e6c
/*  f154e00:	252affff */ 	addiu	$t2,$t1,-1
/*  f154e04:	27a90090 */ 	addiu	$t1,$sp,0x90
.NB0f154e08:
/*  f154e08:	19400016 */ 	blez	$t2,.NB0f154e64
/*  f154e0c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f154e10:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f154e14:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f154e18:	01644021 */ 	addu	$t0,$t3,$a0
/*  f154e1c:	00002825 */ 	or	$a1,$zero,$zero
.NB0f154e20:
/*  f154e20:	84860002 */ 	lh	$a2,0x2($a0)
/*  f154e24:	84870000 */ 	lh	$a3,0x0($a0)
/*  f154e28:	01251821 */ 	addu	$v1,$t1,$a1
/*  f154e2c:	00c7082a */ 	slt	$at,$a2,$a3
/*  f154e30:	50200009 */ 	beqzl	$at,.NB0f154e58
/*  f154e34:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f154e38:	84620000 */ 	lh	$v0,0x0($v1)
/*  f154e3c:	846d0002 */ 	lh	$t5,0x2($v1)
/*  f154e40:	a4860000 */ 	sh	$a2,0x0($a0)
/*  f154e44:	a4870002 */ 	sh	$a3,0x2($a0)
/*  f154e48:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f154e4c:	a4620002 */ 	sh	$v0,0x2($v1)
/*  f154e50:	a46d0000 */ 	sh	$t5,0x0($v1)
/*  f154e54:	24840002 */ 	addiu	$a0,$a0,0x2
.NB0f154e58:
/*  f154e58:	0088082b */ 	sltu	$at,$a0,$t0
/*  f154e5c:	1420fff0 */ 	bnez	$at,.NB0f154e20
/*  f154e60:	24a50002 */ 	addiu	$a1,$a1,0x2
.NB0f154e64:
/*  f154e64:	1680ffe8 */ 	bnez	$s4,.NB0f154e08
/*  f154e68:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f154e6c:
/*  f154e6c:	02202025 */ 	or	$a0,$s1,$zero
/*  f154e70:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f154e74:	0000a025 */ 	or	$s4,$zero,$zero
/*  f154e78:	3c03800a */ 	lui	$v1,0x800a
/*  f154e7c:	8c63e944 */ 	lw	$v1,-0x16bc($v1)
/*  f154e80:	00408825 */ 	or	$s1,$v0,$zero
/*  f154e84:	8c6400d8 */ 	lw	$a0,0xd8($v1)
/*  f154e88:	14800013 */ 	bnez	$a0,.NB0f154ed8
/*  f154e8c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f154e90:	8dce2e24 */ 	lw	$t6,0x2e24($t6)
/*  f154e94:	15c00010 */ 	bnez	$t6,.NB0f154ed8
/*  f154e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154e9c:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f154ea0:	50400007 */ 	beqzl	$v0,.NB0f154ec0
/*  f154ea4:	8c6b1c54 */ 	lw	$t3,0x1c54($v1)
/*  f154ea8:	1040000b */ 	beqz	$v0,.NB0f154ed8
/*  f154eac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154eb0:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f154eb4:	15e00008 */ 	bnez	$t7,.NB0f154ed8
/*  f154eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154ebc:	8c6b1c54 */ 	lw	$t3,0x1c54($v1)
.NB0f154ec0:
/*  f154ec0:	8c7800c4 */ 	lw	$t8,0xc4($v1)
/*  f154ec4:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f154ec8:	03196024 */ 	and	$t4,$t8,$t9
/*  f154ecc:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f154ed0:	55a000c1 */ 	bnezl	$t5,.NB0f1551d8
/*  f154ed4:	02202025 */ 	or	$a0,$s1,$zero
.NB0f154ed8:
/*  f154ed8:	14800012 */ 	bnez	$a0,.NB0f154f24
/*  f154edc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f154ee0:	8dce2e24 */ 	lw	$t6,0x2e24($t6)
/*  f154ee4:	15c0000f */ 	bnez	$t6,.NB0f154f24
/*  f154ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154eec:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f154ef0:	50400007 */ 	beqzl	$v0,.NB0f154f10
/*  f154ef4:	8c781c54 */ 	lw	$t8,0x1c54($v1)
/*  f154ef8:	1040000a */ 	beqz	$v0,.NB0f154f24
/*  f154efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f00:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f154f04:	15e00007 */ 	bnez	$t7,.NB0f154f24
/*  f154f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f0c:	8c781c54 */ 	lw	$t8,0x1c54($v1)
.NB0f154f10:
/*  f154f10:	8c6b00c4 */ 	lw	$t3,0xc4($v1)
/*  f154f14:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f154f18:	01796024 */ 	and	$t4,$t3,$t9
/*  f154f1c:	318d0008 */ 	andi	$t5,$t4,0x8
/*  f154f20:	15a000ac */ 	bnez	$t5,.NB0f1551d4
.NB0f154f24:
/*  f154f24:	3c108008 */ 	lui	$s0,0x8008
/*  f154f28:	26102520 */ 	addiu	$s0,$s0,0x2520
/*  f154f2c:	860e05e8 */ 	lh	$t6,0x5e8($s0)
/*  f154f30:	126e001f */ 	beq	$s3,$t6,.NB0f154fb0
/*  f154f34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f38:	860f0738 */ 	lh	$t7,0x738($s0)
/*  f154f3c:	126f001c */ 	beq	$s3,$t7,.NB0f154fb0
/*  f154f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f44:	86180118 */ 	lh	$t8,0x118($s0)
/*  f154f48:	12780019 */ 	beq	$s3,$t8,.NB0f154fb0
/*  f154f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f50:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f154f54:	126b0016 */ 	beq	$s3,$t3,.NB0f154fb0
/*  f154f58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f5c:	861904d0 */ 	lh	$t9,0x4d0($s0)
/*  f154f60:	12790013 */ 	beq	$s3,$t9,.NB0f154fb0
/*  f154f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f68:	860c0070 */ 	lh	$t4,0x70($s0)
/*  f154f6c:	126c0010 */ 	beq	$s3,$t4,.NB0f154fb0
/*  f154f70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f74:	860d0620 */ 	lh	$t5,0x620($s0)
/*  f154f78:	126d000d */ 	beq	$s3,$t5,.NB0f154fb0
/*  f154f7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f80:	860e0310 */ 	lh	$t6,0x310($s0)
/*  f154f84:	126e000a */ 	beq	$s3,$t6,.NB0f154fb0
/*  f154f88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f8c:	860f07a8 */ 	lh	$t7,0x7a8($s0)
/*  f154f90:	126f0007 */ 	beq	$s3,$t7,.NB0f154fb0
/*  f154f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154f98:	86180850 */ 	lh	$t8,0x850($s0)
/*  f154f9c:	12780004 */ 	beq	$s3,$t8,.NB0f154fb0
/*  f154fa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154fa4:	860b0700 */ 	lh	$t3,0x700($s0)
/*  f154fa8:	566b008b */ 	bnel	$s3,$t3,.NB0f1551d8
/*  f154fac:	02202025 */ 	or	$a0,$s1,$zero
.NB0f154fb0:
/*  f154fb0:	0fc583b2 */ 	jal	envStopFog
/*  f154fb4:	02202025 */ 	or	$a0,$s1,$zero
/*  f154fb8:	0c002b3e */ 	jal	vi0000ab78
/*  f154fbc:	00402025 */ 	or	$a0,$v0,$zero
/*  f154fc0:	861905e8 */ 	lh	$t9,0x5e8($s0)
/*  f154fc4:	00408825 */ 	or	$s1,$v0,$zero
/*  f154fc8:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f154fcc:	1279000a */ 	beq	$s3,$t9,.NB0f154ff8
/*  f154fd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f154fd4:	860c0738 */ 	lh	$t4,0x738($s0)
/*  f154fd8:	126c0007 */ 	beq	$s3,$t4,.NB0f154ff8
/*  f154fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154fe0:	860d0118 */ 	lh	$t5,0x118($s0)
/*  f154fe4:	126d0004 */ 	beq	$s3,$t5,.NB0f154ff8
/*  f154fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f154fec:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f154ff0:	566e0004 */ 	bnel	$s3,$t6,.NB0f155004
/*  f154ff4:	860f04d0 */ 	lh	$t7,0x4d0($s0)
.NB0f154ff8:
/*  f154ff8:	1000001d */ 	beqz	$zero,.NB0f155070
/*  f154ffc:	2412000f */ 	addiu	$s2,$zero,0xf
/*  f155000:	860f04d0 */ 	lh	$t7,0x4d0($s0)
.NB0f155004:
/*  f155004:	126f0004 */ 	beq	$s3,$t7,.NB0f155018
/*  f155008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15500c:	86180070 */ 	lh	$t8,0x70($s0)
/*  f155010:	56780004 */ 	bnel	$s3,$t8,.NB0f155024
/*  f155014:	860b0620 */ 	lh	$t3,0x620($s0)
.NB0f155018:
/*  f155018:	10000015 */ 	beqz	$zero,.NB0f155070
/*  f15501c:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f155020:	860b0620 */ 	lh	$t3,0x620($s0)
.NB0f155024:
/*  f155024:	126b0007 */ 	beq	$s3,$t3,.NB0f155044
/*  f155028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15502c:	86190310 */ 	lh	$t9,0x310($s0)
/*  f155030:	12790004 */ 	beq	$s3,$t9,.NB0f155044
/*  f155034:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155038:	860c07a8 */ 	lh	$t4,0x7a8($s0)
/*  f15503c:	566c0004 */ 	bnel	$s3,$t4,.NB0f155050
/*  f155040:	860d0850 */ 	lh	$t5,0x850($s0)
.NB0f155044:
/*  f155044:	1000000a */ 	beqz	$zero,.NB0f155070
/*  f155048:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f15504c:	860d0850 */ 	lh	$t5,0x850($s0)
.NB0f155050:
/*  f155050:	566d0004 */ 	bnel	$s3,$t5,.NB0f155064
/*  f155054:	860e0700 */ 	lh	$t6,0x700($s0)
/*  f155058:	10000005 */ 	beqz	$zero,.NB0f155070
/*  f15505c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f155060:	860e0700 */ 	lh	$t6,0x700($s0)
.NB0f155064:
/*  f155064:	166e0002 */ 	bne	$s3,$t6,.NB0f155070
/*  f155068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15506c:	24120071 */ 	addiu	$s2,$zero,0x71
.NB0f155070:
/*  f155070:	3c0f800a */ 	lui	$t7,0x800a
/*  f155074:	8defe72c */ 	lw	$t7,-0x18d4($t7)
/*  f155078:	3c18800a */ 	lui	$t8,0x800a
/*  f15507c:	3c0b800a */ 	lui	$t3,0x800a
/*  f155080:	11e00003 */ 	beqz	$t7,.NB0f155090
/*  f155084:	3c19800a */ 	lui	$t9,0x800a
/*  f155088:	10000002 */ 	beqz	$zero,.NB0f155094
/*  f15508c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f155090:
/*  f155090:	00002825 */ 	or	$a1,$zero,$zero
.NB0f155094:
/*  f155094:	8f18e728 */ 	lw	$t8,-0x18d8($t8)
/*  f155098:	00001825 */ 	or	$v1,$zero,$zero
/*  f15509c:	00002025 */ 	or	$a0,$zero,$zero
/*  f1550a0:	13000003 */ 	beqz	$t8,.NB0f1550b0
/*  f1550a4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1550a8:	10000001 */ 	beqz	$zero,.NB0f1550b0
/*  f1550ac:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1550b0:
/*  f1550b0:	8d6be724 */ 	lw	$t3,-0x18dc($t3)
/*  f1550b4:	11600003 */ 	beqz	$t3,.NB0f1550c4
/*  f1550b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1550bc:	10000001 */ 	beqz	$zero,.NB0f1550c4
/*  f1550c0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1550c4:
/*  f1550c4:	8f39e730 */ 	lw	$t9,-0x18d0($t9)
/*  f1550c8:	13200003 */ 	beqz	$t9,.NB0f1550d8
/*  f1550cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1550d0:	10000001 */ 	beqz	$zero,.NB0f1550d8
/*  f1550d4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f1550d8:
/*  f1550d8:	00446021 */ 	addu	$t4,$v0,$a0
/*  f1550dc:	01836821 */ 	addu	$t5,$t4,$v1
/*  f1550e0:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f1550e4:	15c10023 */ 	bne	$t6,$at,.NB0f155174
/*  f1550e8:	24010030 */ 	addiu	$at,$zero,0x30
/*  f1550ec:	1261000b */ 	beq	$s3,$at,.NB0f15511c
/*  f1550f0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f1550f4:	12610009 */ 	beq	$s3,$at,.NB0f15511c
/*  f1550f8:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1550fc:	12610007 */ 	beq	$s3,$at,.NB0f15511c
/*  f155100:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f155104:	12610005 */ 	beq	$s3,$at,.NB0f15511c
/*  f155108:	24010019 */ 	addiu	$at,$zero,0x19
/*  f15510c:	12610003 */ 	beq	$s3,$at,.NB0f15511c
/*  f155110:	24010034 */ 	addiu	$at,$zero,0x34
/*  f155114:	56610018 */ 	bnel	$s3,$at,.NB0f155178
/*  f155118:	2406ffff */ 	addiu	$a2,$zero,-1
.NB0f15511c:
/*  f15511c:	0fc5374a */ 	jal	text0f153628
/*  f155120:	02202025 */ 	or	$a0,$s1,$zero
/*  f155124:	3c0f0103 */ 	lui	$t7,0x103
/*  f155128:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f15512c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f155130:	00408025 */ 	or	$s0,$v0,$zero
/*  f155134:	0fc2cb5a */ 	jal	camGetOrthogonalMtxL
/*  f155138:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f15513c:	0c013100 */ 	jal	osVirtualToPhysical
/*  f155140:	00402025 */ 	or	$a0,$v0,$zero
/*  f155144:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f155148:	0fc303b1 */ 	jal	playerLoadMatrix
/*  f15514c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155150:	0fc583b2 */ 	jal	envStopFog
/*  f155154:	00402025 */ 	or	$a0,$v0,$zero
/*  f155158:	0fc4c503 */ 	jal	starsRender
/*  f15515c:	00402025 */ 	or	$a0,$v0,$zero
/*  f155160:	0fc537a0 */ 	jal	text0f153780
/*  f155164:	00402025 */ 	or	$a0,$v0,$zero
/*  f155168:	0c002b3e */ 	jal	vi0000ab78
/*  f15516c:	00402025 */ 	or	$a0,$v0,$zero
/*  f155170:	00408825 */ 	or	$s1,$v0,$zero
.NB0f155174:
/*  f155174:	2406ffff */ 	addiu	$a2,$zero,-1
.NB0f155178:
/*  f155178:	1246000f */ 	beq	$s2,$a2,.NB0f1551b8
/*  f15517c:	2407008c */ 	addiu	$a3,$zero,0x8c
/*  f155180:	02470019 */ 	multu	$s2,$a3
/*  f155184:	3c18800b */ 	lui	$t8,0x800b
/*  f155188:	8f1890a8 */ 	lw	$t8,-0x6f58($t8)
/*  f15518c:	00005812 */ 	mflo	$t3
/*  f155190:	030bc821 */ 	addu	$t9,$t8,$t3
/*  f155194:	872c0002 */ 	lh	$t4,0x2($t9)
/*  f155198:	55800004 */ 	bnezl	$t4,.NB0f1551ac
/*  f15519c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1551a0:	0fc560fc */ 	jal	bgLoadRoom
/*  f1551a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1551a8:	02202025 */ 	or	$a0,$s1,$zero
.NB0f1551ac:
/*  f1551ac:	0fc564ca */ 	jal	bgRenderRoomOpaque
/*  f1551b0:	02402825 */ 	or	$a1,$s2,$zero
/*  f1551b4:	00408825 */ 	or	$s1,$v0,$zero
.NB0f1551b8:
/*  f1551b8:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f1551bc:	35ad000e */ 	ori	$t5,$t5,0xe
/*  f1551c0:	02208025 */ 	or	$s0,$s1,$zero
/*  f1551c4:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f1551c8:	0c002b3b */ 	jal	viGetPerspScale
/*  f1551cc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1551d0:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f1551d4:
/*  f1551d4:	02202025 */ 	or	$a0,$s1,$zero
.NB0f1551d8:
/*  f1551d8:	0fc481ab */ 	jal	skyRenderSuns
/*  f1551dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f1551e0:	3c05800a */ 	lui	$a1,0x800a
/*  f1551e4:	3c0e800a */ 	lui	$t6,0x800a
/*  f1551e8:	8dceea0c */ 	lw	$t6,-0x15f4($t6)
/*  f1551ec:	8ca5ea08 */ 	lw	$a1,-0x15f8($a1)
/*  f1551f0:	27b50198 */ 	addiu	$s5,$sp,0x198
/*  f1551f4:	3c098008 */ 	lui	$t1,0x8008
/*  f1551f8:	00ae082b */ 	sltu	$at,$a1,$t6
/*  f1551fc:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f155200:	2407008c */ 	addiu	$a3,$zero,0x8c
/*  f155204:	00408825 */ 	or	$s1,$v0,$zero
/*  f155208:	8d292490 */ 	lw	$t1,0x2490($t1)
/*  f15520c:	10200022 */ 	beqz	$at,.NB0f155298
/*  f155210:	02a04025 */ 	or	$t0,$s5,$zero
/*  f155214:	a5000000 */ 	sh	$zero,0x0($t0)
.NB0f155218:
/*  f155218:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f15521c:	3c0d800a */ 	lui	$t5,0x800a
/*  f155220:	10600015 */ 	beqz	$v1,.NB0f155278
/*  f155224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155228:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f15522c:	24620028 */ 	addiu	$v0,$v1,0x28
/*  f155230:	3c04800b */ 	lui	$a0,0x800b
/*  f155234:	10cf0010 */ 	beq	$a2,$t7,.NB0f155278
/*  f155238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15523c:	8c8490a8 */ 	lw	$a0,-0x6f58($a0)
/*  f155240:	84430000 */ 	lh	$v1,0x0($v0)
.NB0f155244:
/*  f155244:	00670019 */ 	multu	$v1,$a3
/*  f155248:	0000c012 */ 	mflo	$t8
/*  f15524c:	00985821 */ 	addu	$t3,$a0,$t8
/*  f155250:	95790000 */ 	lhu	$t9,0x0($t3)
/*  f155254:	332c0004 */ 	andi	$t4,$t9,0x4
/*  f155258:	51800004 */ 	beqzl	$t4,.NB0f15526c
/*  f15525c:	84430002 */ 	lh	$v1,0x2($v0)
/*  f155260:	10000005 */ 	beqz	$zero,.NB0f155278
/*  f155264:	a5030000 */ 	sh	$v1,0x0($t0)
/*  f155268:	84430002 */ 	lh	$v1,0x2($v0)
.NB0f15526c:
/*  f15526c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f155270:	14c3fff4 */ 	bne	$a2,$v1,.NB0f155244
/*  f155274:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f155278:
/*  f155278:	8dadea0c */ 	lw	$t5,-0x15f4($t5)
/*  f15527c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f155280:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f155284:	00ad082b */ 	sltu	$at,$a1,$t5
/*  f155288:	5420ffe3 */ 	bnezl	$at,.NB0f155218
/*  f15528c:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f155290:	3c098008 */ 	lui	$t1,0x8008
/*  f155294:	8d292490 */ 	lw	$t1,0x2490($t1)
.NB0f155298:
/*  f155298:	1920008c */ 	blez	$t1,.NB0f1554cc
/*  f15529c:	27b30090 */ 	addiu	$s3,$sp,0x90
.NB0f1552a0:
/*  f1552a0:	06c10007 */ 	bgez	$s6,.NB0f1552c0
/*  f1552a4:	86720000 */ 	lh	$s2,0x0($s3)
/*  f1552a8:	00127080 */ 	sll	$t6,$s2,0x2
/*  f1552ac:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f1552b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1552b4:	3c16800b */ 	lui	$s6,0x800b
/*  f1552b8:	02ceb021 */ 	addu	$s6,$s6,$t6
/*  f1552bc:	86d68dc0 */ 	lh	$s6,-0x7240($s6)
.NB0f1552c0:
/*  f1552c0:	3c0f0103 */ 	lui	$t7,0x103
/*  f1552c4:	0012c080 */ 	sll	$t8,$s2,0x2
/*  f1552c8:	0312c023 */ 	subu	$t8,$t8,$s2
/*  f1552cc:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f1552d0:	02201025 */ 	or	$v0,$s1,$zero
/*  f1552d4:	3c0b800b */ 	lui	$t3,0x800b
/*  f1552d8:	256b8dc0 */ 	addiu	$t3,$t3,-29248
/*  f1552dc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1552e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1552e4:	030b8021 */ 	addu	$s0,$t8,$t3
/*  f1552e8:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f1552ec:	0fc2cb52 */ 	jal	camGetPerspectiveMtxL
/*  f1552f0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1552f4:	0c013100 */ 	jal	osVirtualToPhysical
/*  f1552f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1552fc:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f155300:	02202025 */ 	or	$a0,$s1,$zero
/*  f155304:	0fc583b2 */ 	jal	envStopFog
/*  f155308:	af220004 */ 	sw	$v0,0x4($t9)
/*  f15530c:	0fc46640 */ 	jal	debugIsPropRenderingEnabled
/*  f155310:	00408825 */ 	or	$s1,$v0,$zero
/*  f155314:	50400014 */ 	beqzl	$v0,.NB0f155368
/*  f155318:	3c0c0103 */ 	lui	$t4,0x103
/*  f15531c:	0fc58908 */ 	jal	getVar80084040
/*  f155320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155324:	50400010 */ 	beqzl	$v0,.NB0f155368
/*  f155328:	3c0c0103 */ 	lui	$t4,0x103
/*  f15532c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f155330:	02202025 */ 	or	$a0,$s1,$zero
/*  f155334:	00003025 */ 	or	$a2,$zero,$zero
/*  f155338:	16c50005 */ 	bne	$s6,$a1,.NB0f155350
/*  f15533c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f155340:	0fc17ea2 */ 	jal	propsRender
/*  f155344:	00002825 */ 	or	$a1,$zero,$zero
/*  f155348:	00408825 */ 	or	$s1,$v0,$zero
/*  f15534c:	86050000 */ 	lh	$a1,0x0($s0)
.NB0f155350:
/*  f155350:	02202025 */ 	or	$a0,$s1,$zero
/*  f155354:	00003025 */ 	or	$a2,$zero,$zero
/*  f155358:	0fc17ea2 */ 	jal	propsRender
/*  f15535c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f155360:	00408825 */ 	or	$s1,$v0,$zero
/*  f155364:	3c0c0103 */ 	lui	$t4,0x103
.NB0f155368:
/*  f155368:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f15536c:	02201025 */ 	or	$v0,$s1,$zero
/*  f155370:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f155374:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f155378:	0fc2cb5a */ 	jal	camGetOrthogonalMtxL
/*  f15537c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155380:	0c013100 */ 	jal	osVirtualToPhysical
/*  f155384:	00402025 */ 	or	$a0,$v0,$zero
/*  f155388:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f15538c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155390:	ada20004 */ 	sw	$v0,0x4($t5)
/*  f155394:	86180008 */ 	lh	$t8,0x8($s0)
/*  f155398:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f15539c:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f1553a0:	860b000a */ 	lh	$t3,0xa($s0)
/*  f1553a4:	44984000 */ 	mtc1	$t8,$f8
/*  f1553a8:	448f3000 */ 	mtc1	$t7,$f6
/*  f1553ac:	448e2000 */ 	mtc1	$t6,$f4
/*  f1553b0:	448b5000 */ 	mtc1	$t3,$f10
/*  f1553b4:	46804220 */ 	cvt.s.w	$f8,$f8
/*  f1553b8:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f1553bc:	44074000 */ 	mfc1	$a3,$f8
/*  f1553c0:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f1553c4:	44063000 */ 	mfc1	$a2,$f6
/*  f1553c8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1553cc:	44052000 */ 	mfc1	$a1,$f4
/*  f1553d0:	0fc55ca6 */ 	jal	currentPlayerScissorWithinViewportF
/*  f1553d4:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f1553d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1553dc:	0fc58328 */ 	jal	envStartFog
/*  f1553e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1553e4:	0fc4663d */ 	jal	debugIsBgRenderingEnabled
/*  f1553e8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1553ec:	5040000e */ 	beqzl	$v0,.NB0f155428
/*  f1553f0:	3c0c0103 */ 	lui	$t4,0x103
/*  f1553f4:	0fc58908 */ 	jal	getVar80084040
/*  f1553f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1553fc:	10400009 */ 	beqz	$v0,.NB0f155424
/*  f155400:	3c198008 */ 	lui	$t9,0x8008
/*  f155404:	8f392460 */ 	lw	$t9,0x2460($t9)
/*  f155408:	24010026 */ 	addiu	$at,$zero,0x26
/*  f15540c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155410:	53210005 */ 	beql	$t9,$at,.NB0f155428
/*  f155414:	3c0c0103 */ 	lui	$t4,0x103
/*  f155418:	0fc564ca */ 	jal	bgRenderRoomOpaque
/*  f15541c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f155420:	00408825 */ 	or	$s1,$v0,$zero
.NB0f155424:
/*  f155424:	3c0c0103 */ 	lui	$t4,0x103
.NB0f155428:
/*  f155428:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f15542c:	02201025 */ 	or	$v0,$s1,$zero
/*  f155430:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f155434:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f155438:	0fc2cb52 */ 	jal	camGetPerspectiveMtxL
/*  f15543c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155440:	0c013100 */ 	jal	osVirtualToPhysical
/*  f155444:	00402025 */ 	or	$a0,$v0,$zero
/*  f155448:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f15544c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155450:	0fc583b2 */ 	jal	envStopFog
/*  f155454:	ada20004 */ 	sw	$v0,0x4($t5)
/*  f155458:	0fc46640 */ 	jal	debugIsPropRenderingEnabled
/*  f15545c:	00408825 */ 	or	$s1,$v0,$zero
/*  f155460:	10400013 */ 	beqz	$v0,.NB0f1554b0
/*  f155464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155468:	0fc58908 */ 	jal	getVar80084040
/*  f15546c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155470:	1040000f */ 	beqz	$v0,.NB0f1554b0
/*  f155474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155478:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15547c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155480:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f155484:	16c50005 */ 	bne	$s6,$a1,.NB0f15549c
/*  f155488:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15548c:	0fc17ea2 */ 	jal	propsRender
/*  f155490:	00002825 */ 	or	$a1,$zero,$zero
/*  f155494:	00408825 */ 	or	$s1,$v0,$zero
/*  f155498:	86050000 */ 	lh	$a1,0x0($s0)
.NB0f15549c:
/*  f15549c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1554a0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1554a4:	0fc17ea2 */ 	jal	propsRender
/*  f1554a8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1554ac:	00408825 */ 	or	$s1,$v0,$zero
.NB0f1554b0:
/*  f1554b0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1554b4:	8dce2490 */ 	lw	$t6,0x2490($t6)
/*  f1554b8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1554bc:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f1554c0:	028e082a */ 	slt	$at,$s4,$t6
/*  f1554c4:	1420ff76 */ 	bnez	$at,.NB0f1552a0
/*  f1554c8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1554cc:
/*  f1554cc:	0fc583b2 */ 	jal	envStopFog
/*  f1554d0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1554d4:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f1554d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1554dc:	3c0f0103 */ 	lui	$t7,0x103
/*  f1554e0:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f1554e4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1554e8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1554ec:	0fc2cb5a */ 	jal	camGetOrthogonalMtxL
/*  f1554f0:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f1554f4:	0c013100 */ 	jal	osVirtualToPhysical
/*  f1554f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1554fc:	0fc58908 */ 	jal	getVar80084040
/*  f155500:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f155504:	1040001c */ 	beqz	$v0,.NB0f155578
/*  f155508:	3c18800a */ 	lui	$t8,0x800a
/*  f15550c:	8f18e944 */ 	lw	$t8,-0x16bc($t8)
/*  f155510:	24010001 */ 	addiu	$at,$zero,0x1
/*  f155514:	3c198008 */ 	lui	$t9,0x8008
/*  f155518:	970b0010 */ 	lhu	$t3,0x10($t8)
/*  f15551c:	11610016 */ 	beq	$t3,$at,.NB0f155578
/*  f155520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155524:	8f392490 */ 	lw	$t9,0x2490($t9)
/*  f155528:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15552c:	27b30090 */ 	addiu	$s3,$sp,0x90
/*  f155530:	1b200011 */ 	blez	$t9,.NB0f155578
/*  f155534:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f155538:
/*  f155538:	86720000 */ 	lh	$s2,0x0($s3)
/*  f15553c:	3c04800b */ 	lui	$a0,0x800b
/*  f155540:	02202825 */ 	or	$a1,$s1,$zero
/*  f155544:	00126080 */ 	sll	$t4,$s2,0x2
/*  f155548:	01926023 */ 	subu	$t4,$t4,$s2
/*  f15554c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f155550:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f155554:	0fc4ef16 */ 	jal	wallhitRenderBgHits
/*  f155558:	84848dc0 */ 	lh	$a0,-0x7240($a0)
/*  f15555c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155560:	8dad2490 */ 	lw	$t5,0x2490($t5)
/*  f155564:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f155568:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f15556c:	028d082a */ 	slt	$at,$s4,$t5
/*  f155570:	1420fff1 */ 	bnez	$at,.NB0f155538
/*  f155574:	00408825 */ 	or	$s1,$v0,$zero
.NB0f155578:
/*  f155578:	3c098008 */ 	lui	$t1,0x8008
/*  f15557c:	8d292490 */ 	lw	$t1,0x2490($t1)
/*  f155580:	27af0090 */ 	addiu	$t7,$sp,0x90
/*  f155584:	2534ffff */ 	addiu	$s4,$t1,-1
/*  f155588:	0680006f */ 	bltz	$s4,.NB0f155748
/*  f15558c:	00147040 */ 	sll	$t6,$s4,0x1
/*  f155590:	3c14800b */ 	lui	$s4,0x800b
/*  f155594:	26949378 */ 	addiu	$s4,$s4,-27784
/*  f155598:	01cf9821 */ 	addu	$s3,$t6,$t7
/*  f15559c:	3c180103 */ 	lui	$t8,0x103
.NB0f1555a0:
/*  f1555a0:	86720000 */ 	lh	$s2,0x0($s3)
/*  f1555a4:	37180040 */ 	ori	$t8,$t8,0x40
/*  f1555a8:	02201025 */ 	or	$v0,$s1,$zero
/*  f1555ac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f1555b0:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f1555b4:	0fc2cb5a */ 	jal	camGetOrthogonalMtxL
/*  f1555b8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1555bc:	0c013100 */ 	jal	osVirtualToPhysical
/*  f1555c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1555c4:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f1555c8:	0012c880 */ 	sll	$t9,$s2,0x2
/*  f1555cc:	0332c823 */ 	subu	$t9,$t9,$s2
/*  f1555d0:	3c0c800b */ 	lui	$t4,0x800b
/*  f1555d4:	258c8dc0 */ 	addiu	$t4,$t4,-29248
/*  f1555d8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1555dc:	032c8021 */ 	addu	$s0,$t9,$t4
/*  f1555e0:	ad620004 */ 	sw	$v0,0x4($t3)
/*  f1555e4:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f1555e8:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f1555ec:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f1555f0:	8618000a */ 	lh	$t8,0xa($s0)
/*  f1555f4:	448f3000 */ 	mtc1	$t7,$f6
/*  f1555f8:	448e2000 */ 	mtc1	$t6,$f4
/*  f1555fc:	448d9000 */ 	mtc1	$t5,$f18
/*  f155600:	44984000 */ 	mtc1	$t8,$f8
/*  f155604:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f155608:	02202025 */ 	or	$a0,$s1,$zero
/*  f15560c:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f155610:	44073000 */ 	mfc1	$a3,$f6
/*  f155614:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f155618:	44062000 */ 	mfc1	$a2,$f4
/*  f15561c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f155620:	44059000 */ 	mfc1	$a1,$f18
/*  f155624:	0fc55ca6 */ 	jal	currentPlayerScissorWithinViewportF
/*  f155628:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f15562c:	00402025 */ 	or	$a0,$v0,$zero
/*  f155630:	0fc58328 */ 	jal	envStartFog
/*  f155634:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f155638:	0fc4663d */ 	jal	debugIsBgRenderingEnabled
/*  f15563c:	00408825 */ 	or	$s1,$v0,$zero
/*  f155640:	50400009 */ 	beqzl	$v0,.NB0f155668
/*  f155644:	3c0b0103 */ 	lui	$t3,0x103
/*  f155648:	0fc58908 */ 	jal	getVar80084040
/*  f15564c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155650:	10400004 */ 	beqz	$v0,.NB0f155664
/*  f155654:	02202025 */ 	or	$a0,$s1,$zero
/*  f155658:	0fc564f5 */ 	jal	bgRenderRoomXlu
/*  f15565c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f155660:	00408825 */ 	or	$s1,$v0,$zero
.NB0f155664:
/*  f155664:	3c0b0103 */ 	lui	$t3,0x103
.NB0f155668:
/*  f155668:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f15566c:	02201025 */ 	or	$v0,$s1,$zero
/*  f155670:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f155674:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f155678:	0fc2cb52 */ 	jal	camGetPerspectiveMtxL
/*  f15567c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155680:	0c013100 */ 	jal	osVirtualToPhysical
/*  f155684:	00402025 */ 	or	$a0,$v0,$zero
/*  f155688:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f15568c:	02202025 */ 	or	$a0,$s1,$zero
/*  f155690:	0fc583b2 */ 	jal	envStopFog
/*  f155694:	af220004 */ 	sw	$v0,0x4($t9)
/*  f155698:	0fc46640 */ 	jal	debugIsPropRenderingEnabled
/*  f15569c:	00408825 */ 	or	$s1,$v0,$zero
/*  f1556a0:	10400013 */ 	beqz	$v0,.NB0f1556f0
/*  f1556a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1556a8:	0fc58908 */ 	jal	getVar80084040
/*  f1556ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1556b0:	1040000f */ 	beqz	$v0,.NB0f1556f0
/*  f1556b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1556b8:	86050000 */ 	lh	$a1,0x0($s0)
/*  f1556bc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1556c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1556c4:	16c50005 */ 	bne	$s6,$a1,.NB0f1556dc
/*  f1556c8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1556cc:	0fc17ea2 */ 	jal	propsRender
/*  f1556d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1556d4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1556d8:	86050000 */ 	lh	$a1,0x0($s0)
.NB0f1556dc:
/*  f1556dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1556e0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1556e4:	0fc17ea2 */ 	jal	propsRender
/*  f1556e8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1556ec:	00408825 */ 	or	$s1,$v0,$zero
.NB0f1556f0:
/*  f1556f0:	3c0c800a */ 	lui	$t4,0x800a
/*  f1556f4:	8d8ce9d4 */ 	lw	$t4,-0x162c($t4)
/*  f1556f8:	5580000f */ 	bnezl	$t4,.NB0f155738
/*  f1556fc:	2673fffe */ 	addiu	$s3,$s3,-2
/*  f155700:	0fc4dca0 */ 	jal	artifactsCalculateGlaresForRoom
/*  f155704:	86040000 */ 	lh	$a0,0x0($s0)
/*  f155708:	3c028008 */ 	lui	$v0,0x8008
/*  f15570c:	8c422478 */ 	lw	$v0,0x2478($v0)
/*  f155710:	28410064 */ 	slti	$at,$v0,0x64
/*  f155714:	10200007 */ 	beqz	$at,.NB0f155734
/*  f155718:	00027040 */ 	sll	$t6,$v0,0x1
/*  f15571c:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f155720:	028e7821 */ 	addu	$t7,$s4,$t6
/*  f155724:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f155728:	3c018008 */ 	lui	$at,0x8008
/*  f15572c:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f155730:	ac382478 */ 	sw	$t8,0x2478($at)
.NB0f155734:
/*  f155734:	2673fffe */ 	addiu	$s3,$s3,-2
.NB0f155738:
/*  f155738:	27ab0090 */ 	addiu	$t3,$sp,0x90
/*  f15573c:	026b082b */ 	sltu	$at,$s3,$t3
/*  f155740:	5020ff97 */ 	beqzl	$at,.NB0f1555a0
/*  f155744:	3c180103 */ 	lui	$t8,0x103
.NB0f155748:
/*  f155748:	0fc466a0 */ 	jal	debug0f119a80nb
/*  f15574c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f155750:	02201025 */ 	or	$v0,$s1,$zero
/*  f155754:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f155758:
/*  f155758:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f15575c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f155760:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f155764:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f155768:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f15576c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f155770:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f155774:	03e00008 */ 	jr	$ra
/*  f155778:	27bd0338 */ 	addiu	$sp,$sp,0x338
);
#endif

Gfx *bgRenderArtifacts(Gfx *gdl)
{
	s32 i;

	if (g_Vars.mplayerisrunning == false && g_NumRoomsWithGlares > 0) {
		gdl = artifactsConfigureForGlares(gdl);

		for (i = 0; i < g_NumRoomsWithGlares; i++) {
			gdl = artifactsRenderGlaresForRoom(gdl, g_GlareRooms[i]);
		}

		gdl = artifactsUnconfigureForGlares(gdl);
	}

	gdl = skyRenderArtifacts(gdl);

	return gdl;
}

void bgLoadFile(void *memaddr, u32 offset, u32 len)
{
	if (var8007fc04) {
		bcopy(var8007fc08 + offset, memaddr, len);
	} else {
		fileLoadPartToAddr(g_Stages[g_StageIndex].bgfileid, memaddr, offset, len);
	}
}

s32 stageGetIndex2(s32 stagenum)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_Stages); i++) {
		if (g_Stages[i].id == stagenum) {
			index = i;
		}
	}

	return index;
}

f32 portal0f15b274(s32 portalnum)
{
	struct portalvertices *pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	s32 count = pvertices->count;
	s32 i;
	s32 j;
	f32 sum = 0.0f;
	f32 sp90[3];
	f32 sp84[3];
	f32 sp78[3];

	for (i = 2; i < count; i++) {
		for (j = 0; j < 3; j++) {
			sp84[j] = pvertices->vertices[i - 1].f[j] - pvertices->vertices[0].f[j];
			sp78[j] = pvertices->vertices[i].f[j] - pvertices->vertices[i - 1].f[j];
		}

		sp90[0] = sp84[1] * sp78[2] - sp84[2] * sp78[1];
		sp90[1] = -sp84[0] * sp78[2] + sp84[2] * sp78[0];
		sp90[2] = sp84[0] * sp78[1] - sp84[1] * sp78[0];

		sum += sqrtf(sp90[0] * sp90[0] + sp90[1] * sp90[1] + sp90[2] * sp90[2]) * 0.5f;
	}

	return sum;
}

void func0f15b3e4(s32 portalnum, struct coord *a, struct coord *b, struct coord *c, struct coord *d)
{
	struct portalvertices *pvertices;
	pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

	a->x = pvertices->vertices[0].x;
	a->y = pvertices->vertices[0].y;
	a->z = pvertices->vertices[0].z;

	b->x = pvertices->vertices[1].x - pvertices->vertices[0].x;
	b->y = pvertices->vertices[1].y - pvertices->vertices[0].y;
	b->z = pvertices->vertices[1].z - pvertices->vertices[0].z;

	c->x = pvertices->vertices[1].x - pvertices->vertices[0].x;
	c->y = pvertices->vertices[1].y - pvertices->vertices[0].y;
	c->z = pvertices->vertices[1].z - pvertices->vertices[0].z;

	d->x = (var800a4ccc + portalnum)->coord.x;
	d->y = (var800a4ccc + portalnum)->coord.y;
	d->z = (var800a4ccc + portalnum)->coord.z;
}

u8 func0f15b4c0(s32 portal)
{
	s32 uVar2 = portal0f15b274(portal) / 10000.0f;

	if (uVar2 > 0xff) {
		uVar2 = 0xff;
	}

	return uVar2;
}

u8 func0f15b508(s32 index)
{
	return var800a4cd0[index];
}

#if PIRACYCHECKS
u32 not(u32 arg)
{
	return ~arg;
}

u32 xorBabebabe(u32 value)
{
	return value ^ 0xbabebabe;
}
#endif

#if VERSION < VERSION_NTSC_1_0
/**
 * The following two functions were surely debug code that was accidentally left
 * in the NTSC beta build, whose purpose is to debug a light data corruption
 * issue.
 *
 * The first function is run on stage start and builds the known good checksums.
 * The second function runs on every tick, re-sums them and induces a crash if
 * they've changed.
 */
void bgBuildReferenceLightSums(void)
{
	s32 i;

	g_BgNumLightsChecksum = 0;

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_BgNumLightsChecksum += g_Rooms[i].numlights;
	}

	g_BgLightsOffsetChecksum = 0;

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_BgLightsOffsetChecksum += g_Rooms[i].lightindex;
	}
}

void bgVerifyLightSums(char *file, s32 line)
{
	s32 i;
	s32 sum;
	char message[128];
	u32 stack;

	sum = 0;

	for (i = 0; i < g_Vars.roomcount; i++) {
		sum += g_Rooms[i].numlights;
	}

	if (sum != g_BgNumLightsChecksum) {
		sprintf(message, "NumLightsChecksum failed %s %d", file, line);
		crashSetMessage(message);
		CRASH();
	}

	sum = 0;

	for (i = 0; i < g_Vars.roomcount; i++) {
		sum += g_Rooms[i].lightindex;
	}

	if (sum != g_BgLightsOffsetChecksum) {
		sprintf(message, "LightsOffsetChecksum failed %s %d", file, line);
		crashSetMessage(message);
		CRASH();
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
/**
 * Extracts and inflates primary data (room/portal/light tables) from the
 * BG file to memory, ensures required textures are loaded, and sets some
 * global pointers to each table within the primary data.
 *
 * -- Overview -----------------------------------------------------------------
 *
 * The structure of a BG File is:
 *
 * - Section 1:
 *   - Primary data (compressed):
 *     - Room table, with pointers to their room gfx data
 *     - Portal table
 *     - Portal command list
 *     - Light table
 *   - For each room, a compressed binary containing gfx data
 * - Section 2 (compressed) - list of texture IDs to load
 * - Section 3 (compressed) - unknown and not read by this function
 *
 * Each section has a header (uncompressed) containing size information:
 *
 * Section 1 header is 0x0c bytes long:
 * - 4 bytes decompressed size of primary data
 * - 4 bytes compressed size of section 1 in its entirety
 * - 4 bytes compressed size of primary data
 *
 * Section 2 and 3 headers are 0x04 bytes long:
 * - 2 bytes decompressed size of data (mask with 0x7fff)
 * - 2 bytes compressed size of data
 *
 * -- Primary Data (compressed) ------------------------------------------------
 *
 * Header is 0x18 bytes long:
 * - 4 bytes null
 * - 4 bytes pointer to room table
 * - 4 bytes pointer to portal table
 * - 4 bytes pointer to portal commands list
 * - 4 bytes pointer to light table
 * - 4 bytes null
 */
void bgReset(s32 stagenum)
{
	u8 *header;
	u8 headerbuffer[0x50];
	u32 numtextures;
	u16 *section2;
	s32 j;
	s32 i;
	u32 primcompsize;
	u32 inflatedsize; // used for both primary and section 2
	u32 section2compsize;
	u32 section2start;
	u32 section1compsize;
	u32 scratch;

	var8007fc0c = 8;

	if (IS4MB()) {
		g_BgUnloadDelay240 = 6;
		g_BgUnloadDelay240_2 = 6;
	} else {
		g_BgUnloadDelay240 = 120;
		g_BgUnloadDelay240_2 = 120;
	}

	switch (g_Vars.stagenum) {
	case STAGE_INFILTRATION:
	case STAGE_RESCUE:
	case STAGE_ESCAPE:
	case STAGE_MAIANSOS:
		g_BgPreload = false;
		break;
	default:
		g_BgPreload = true;
		break;
	}

	g_StageIndex = stageGetIndex2(stagenum);

	if (g_StageIndex < 0) {
		g_StageIndex = 0;
	}

	// Copy section 1 header to stack and parse into variables
	header = (u8 *)ALIGN16((u32)headerbuffer);
	bgLoadFile(header, 0, 0x40);
	inflatedsize = *(u32 *)&header[0];
	section1compsize = *(u32 *)&header[4];
	primcompsize = *(u32 *)&header[8];
	var8007fc54 = inflatedsize - primcompsize;
	var8007fc54 -= 0xc;
	inflatedsize = ALIGN16(inflatedsize);

	// Allocate space for the primary bg data
	// An extra 0x8000 or so is given as temporary scratch space
	g_BgPrimaryData = mempAlloc(ALIGN16(inflatedsize + 0x8010), MEMPOOL_STAGE);

	// Set up pointer to scratch space
	scratch = (u32) g_BgPrimaryData + inflatedsize - primcompsize;
	scratch = ALIGN16(scratch + 0x8000);

	g_LoadType = LOADTYPE_BG;

	// Copy section 1 header + compressed primary to scratch space
	bgLoadFile((u8 *) scratch, 0, ALIGN16(primcompsize + 15));

	// Inflate primary data to the start of the buffer
	scratch += 0xc;
	bgInflate((u8 *) scratch, g_BgPrimaryData, primcompsize);

	// Shrink the allocation (ie. free the scratch space)
	mempRealloc(g_BgPrimaryData, inflatedsize, MEMPOOL_STAGE);

	// Load the section 2 header
	section2start = section1compsize + 0xc;

	bgLoadFile(header, section2start, 0x40);

	inflatedsize = (*(u16 *) &header[0] & 0x7fff) - 1;
	section2compsize = *(u16 *) &header[2];
	inflatedsize = (inflatedsize | 0xf) + 1;

	// Allocate space for the section 2 data (texture ID list).
	// This is the cause and fix for the Challenge 7 memory corruption bug in
	// NTSC 1.0. A full writeup about the bug and how the fix works can be found
	// in the docs folder of this project.
#ifdef AVOID_UB
	section2 = mempAlloc(inflatedsize + section2compsize, MEMPOOL_STAGE);
	scratch = (u32) section2 + inflatedsize;
#elif VERSION >= VERSION_NTSC_FINAL
	section2 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
	scratch = (u32) section2 + 0x8000;
#else
	section2 = mempAlloc(inflatedsize + 0x800, MEMPOOL_STAGE);
	scratch = (u32) section2 + 0x800;
#endif

	// Load compressed data from ROM to scratch
	bgLoadFile((u8 *) scratch, section2start + 4, ((section2compsize - 1) | 0xf) + 1);

	// Inflate section 2 to the start of the buffer
	bgInflate((u8 *) scratch, (u8 *) section2, section2compsize);

	// Iterate texture IDs and ensure they're loaded
	inflatedsize = (*(u16 *) &header[0] & 0x7fff) >> 1;

	for (i = 0; i != inflatedsize; i++) {
		texLoadFromTextureNum(section2[i], NULL);
	}

	if (i);

	// Free section 2
	mempRealloc(section2, 0, MEMPOOL_STAGE);

	g_BgSection3 = section2start + section2compsize + 4;

#if PIRACYCHECKS
	{
		u32 addr = not(PAL ? ~0xb0000340 : ~0xb0000454);
		u32 actualvalue;
		u32 expectedvalue = xorBabebabe((PAL ? 0x0330c820 : 0x0109082b) ^ 0xbabebabe);

		osPiReadIo(addr, &actualvalue);

		if (actualvalue != expectedvalue) {
			// Copy 0x40 bytes from a random location in ROM to a random
			// location in RAM. The write address can be anywhere in the
			// boot segment or in the lib segment up to modelRenderNodeDl.
			dmaExec((void *)(PHYS_TO_K0(0x1000) + (random() & 0x1fff8)), random() & 0x1fffe, 0x40);
		}
	}
#endif

	var800a4920 = *(u32 *)g_BgPrimaryData;

	if (var800a4920 == 0) {
		g_BgPrimaryData2 = (u32 *)g_BgPrimaryData;
		g_BgRooms = (struct bgroom *)(g_BgPrimaryData2[1] + g_BgPrimaryData + 0xf1000000);
		if (g_BgPrimaryData);
		g_Vars.roomcount = 0;

		for (j = 1; g_BgRooms[j].unk00 != 0; j++) {
			g_Vars.roomcount++;
		}

		g_BgPortals = (struct bgportal *)(g_BgPrimaryData2[2] + g_BgPrimaryData + 0xf1000000);

		if (g_BgPrimaryData2[4] == 0) {
			g_BgLightsFileData = NULL;
		} else {
			g_BgLightsFileData = (u8 *)(g_BgPrimaryData2[4] + g_BgPrimaryData + 0xf1000000);
		}

		if (g_BgPrimaryData2[5] == 0) {
			g_BgTable5 = NULL;
		} else {
			g_BgTable5 = (f32 *)(g_BgPrimaryData2[5] + g_BgPrimaryData + 0xf1000000);
		}
	}
}
#else
GLOBAL_ASM(
glabel bgReset
/*  f155d14:	3c0f8009 */ 	lui	$t7,0x8009
/*  f155d18:	91ef30e0 */ 	lbu	$t7,0x30e0($t7)
/*  f155d1c:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f155d20:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f155d24:	3c018008 */ 	lui	$at,0x8008
/*  f155d28:	a42e2470 */ 	sh	$t6,0x2470($at)
/*  f155d2c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f155d30:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f155d34:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f155d38:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f155d3c:	15e10007 */ 	bne	$t7,$at,.NB0f155d5c
/*  f155d40:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f155d44:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f155d48:	3c01800b */ 	lui	$at,0x800b
/*  f155d4c:	a4229370 */ 	sh	$v0,-0x6c90($at)
/*  f155d50:	3c01800b */ 	lui	$at,0x800b
/*  f155d54:	10000006 */ 	beqz	$zero,.NB0f155d70
/*  f155d58:	a4229372 */ 	sh	$v0,-0x6c8e($at)
.NB0f155d5c:
/*  f155d5c:	24020e10 */ 	addiu	$v0,$zero,0xe10
/*  f155d60:	3c01800b */ 	lui	$at,0x800b
/*  f155d64:	a4229370 */ 	sh	$v0,-0x6c90($at)
/*  f155d68:	3c01800b */ 	lui	$at,0x800b
/*  f155d6c:	a4229372 */ 	sh	$v0,-0x6c8e($at)
.NB0f155d70:
/*  f155d70:	3c01800b */ 	lui	$at,0x800b
/*  f155d74:	0fc55629 */ 	jal	stageGetIndex2
/*  f155d78:	ac209374 */ 	sw	$zero,-0x6c8c($at)
/*  f155d7c:	3c038008 */ 	lui	$v1,0x8008
/*  f155d80:	24632460 */ 	addiu	$v1,$v1,0x2460
/*  f155d84:	04410002 */ 	bgez	$v0,.NB0f155d90
/*  f155d88:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f155d8c:	ac600000 */ 	sw	$zero,0x0($v1)
.NB0f155d90:
/*  f155d90:	03a02025 */ 	or	$a0,$sp,$zero
/*  f155d94:	24840073 */ 	addiu	$a0,$a0,0x73
/*  f155d98:	3499000f */ 	ori	$t9,$a0,0xf
/*  f155d9c:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f155da0:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f155da4:	00002825 */ 	or	$a1,$zero,$zero
/*  f155da8:	0fc5560b */ 	jal	bgLoadFile
/*  f155dac:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f155db0:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f155db4:	3c028008 */ 	lui	$v0,0x8008
/*  f155db8:	3401801f */ 	dli	$at,0x801f
/*  f155dbc:	8c6a0004 */ 	lw	$t2,0x4($v1)
/*  f155dc0:	8c720000 */ 	lw	$s2,0x0($v1)
/*  f155dc4:	244224b8 */ 	addiu	$v0,$v0,0x24b8
/*  f155dc8:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f155dcc:	8c710008 */ 	lw	$s1,0x8($v1)
/*  f155dd0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f155dd4:	02515823 */ 	subu	$t3,$s2,$s1
/*  f155dd8:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f155ddc:	364e000f */ 	ori	$t6,$s2,0xf
/*  f155de0:	39d2000f */ 	xori	$s2,$t6,0xf
/*  f155de4:	02412021 */ 	addu	$a0,$s2,$at
/*  f155de8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f155dec:	256dfff4 */ 	addiu	$t5,$t3,-12
/*  f155df0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f155df4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f155df8:	0c004a0e */ 	jal	mempAlloc
/*  f155dfc:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f155e00:	00525021 */ 	addu	$t2,$v0,$s2
/*  f155e04:	01518023 */ 	subu	$s0,$t2,$s1
/*  f155e08:	3401800f */ 	dli	$at,0x800f
/*  f155e0c:	3c03800b */ 	lui	$v1,0x800b
/*  f155e10:	02018021 */ 	addu	$s0,$s0,$at
/*  f155e14:	2463909c */ 	addiu	$v1,$v1,-28516
/*  f155e18:	360b000f */ 	ori	$t3,$s0,0xf
/*  f155e1c:	2626001e */ 	addiu	$a2,$s1,0x1e
/*  f155e20:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f155e24:	3964000f */ 	xori	$a0,$t3,0xf
/*  f155e28:	3c018006 */ 	lui	$at,0x8006
/*  f155e2c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f155e30:	34ce000f */ 	ori	$t6,$a2,0xf
/*  f155e34:	00808025 */ 	or	$s0,$a0,$zero
/*  f155e38:	a02df2c0 */ 	sb	$t5,-0xd40($at)
/*  f155e3c:	39c6000f */ 	xori	$a2,$t6,0xf
/*  f155e40:	0fc5560b */ 	jal	bgLoadFile
/*  f155e44:	00002825 */ 	or	$a1,$zero,$zero
/*  f155e48:	3c05800b */ 	lui	$a1,0x800b
/*  f155e4c:	2604000c */ 	addiu	$a0,$s0,0xc
/*  f155e50:	8ca5909c */ 	lw	$a1,-0x6f64($a1)
/*  f155e54:	0fc56023 */ 	jal	bgInflate
/*  f155e58:	02203025 */ 	or	$a2,$s1,$zero
/*  f155e5c:	3c04800b */ 	lui	$a0,0x800b
/*  f155e60:	8c84909c */ 	lw	$a0,-0x6f64($a0)
/*  f155e64:	02402825 */ 	or	$a1,$s2,$zero
/*  f155e68:	0c004a53 */ 	jal	mempRealloc
/*  f155e6c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f155e70:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f155e74:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f155e78:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f155e7c:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f155e80:	0fc5560b */ 	jal	bgLoadFile
/*  f155e84:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f155e88:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f155e8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f155e90:	94520000 */ 	lhu	$s2,0x0($v0)
/*  f155e94:	94590002 */ 	lhu	$t9,0x2($v0)
/*  f155e98:	32587fff */ 	andi	$t8,$s2,0x7fff
/*  f155e9c:	2712ffff */ 	addiu	$s2,$t8,-1
/*  f155ea0:	3649000f */ 	ori	$t1,$s2,0xf
/*  f155ea4:	25240801 */ 	addiu	$a0,$t1,0x801
/*  f155ea8:	0c004a0e */ 	jal	mempAlloc
/*  f155eac:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f155eb0:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f155eb4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f155eb8:	24440800 */ 	addiu	$a0,$v0,0x800
/*  f155ebc:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f155ec0:	34ca000f */ 	ori	$t2,$a2,0xf
/*  f155ec4:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f155ec8:	00808025 */ 	or	$s0,$a0,$zero
/*  f155ecc:	25460001 */ 	addiu	$a2,$t2,0x1
/*  f155ed0:	0fc5560b */ 	jal	bgLoadFile
/*  f155ed4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f155ed8:	02002025 */ 	or	$a0,$s0,$zero
/*  f155edc:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f155ee0:	0fc56023 */ 	jal	bgInflate
/*  f155ee4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f155ee8:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f155eec:	00008025 */ 	or	$s0,$zero,$zero
/*  f155ef0:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f155ef4:	95720000 */ 	lhu	$s2,0x0($t3)
/*  f155ef8:	324c7fff */ 	andi	$t4,$s2,0x7fff
/*  f155efc:	000c9043 */ 	sra	$s2,$t4,0x1
/*  f155f00:	52400008 */ 	beqzl	$s2,.NB0f155f24
/*  f155f04:	8fa4005c */ 	lw	$a0,0x5c($sp)
.NB0f155f08:
/*  f155f08:	96240000 */ 	lhu	$a0,0x0($s1)
/*  f155f0c:	0fc5b860 */ 	jal	texLoadFromTextureNum
/*  f155f10:	00002825 */ 	or	$a1,$zero,$zero
/*  f155f14:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f155f18:	1612fffb */ 	bne	$s0,$s2,.NB0f155f08
/*  f155f1c:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f155f20:	8fa4005c */ 	lw	$a0,0x5c($sp)
.NB0f155f24:
/*  f155f24:	00002825 */ 	or	$a1,$zero,$zero
/*  f155f28:	0c004a53 */ 	jal	mempRealloc
/*  f155f2c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f155f30:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f155f34:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f155f38:	3c04800b */ 	lui	$a0,0x800b
/*  f155f3c:	8c84909c */ 	lw	$a0,-0x6f64($a0)
/*  f155f40:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f155f44:	27190004 */ 	addiu	$t9,$t8,0x4
/*  f155f48:	3c01800b */ 	lui	$at,0x800b
/*  f155f4c:	ac3990a4 */ 	sw	$t9,-0x6f5c($at)
/*  f155f50:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f155f54:	3c03800b */ 	lui	$v1,0x800b
/*  f155f58:	246390a0 */ 	addiu	$v1,$v1,-28512
/*  f155f5c:	1520003a */ 	bnez	$t1,.NB0f156048
/*  f155f60:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f155f64:	3c02800b */ 	lui	$v0,0x800b
/*  f155f68:	24429440 */ 	addiu	$v0,$v0,-27584
/*  f155f6c:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f155f70:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*  f155f74:	3c07f100 */ 	lui	$a3,0xf100
/*  f155f78:	3c08800b */ 	lui	$t0,0x800b
/*  f155f7c:	3c03800a */ 	lui	$v1,0x800a
/*  f155f80:	01646021 */ 	addu	$t4,$t3,$a0
/*  f155f84:	25089444 */ 	addiu	$t0,$t0,-27580
/*  f155f88:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155f8c:	2463e6c0 */ 	addiu	$v1,$v1,-6464
/*  f155f90:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*  f155f94:	ac6002bc */ 	sw	$zero,0x2bc($v1)
/*  f155f98:	8dae0014 */ 	lw	$t6,0x14($t5)
/*  f155f9c:	00802825 */ 	or	$a1,$a0,$zero
/*  f155fa0:	25a20014 */ 	addiu	$v0,$t5,0x14
/*  f155fa4:	51c00009 */ 	beqzl	$t6,.NB0f155fcc
/*  f155fa8:	8ca90008 */ 	lw	$t1,0x8($a1)
/*  f155fac:	8c6f02bc */ 	lw	$t7,0x2bc($v1)
.NB0f155fb0:
/*  f155fb0:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f155fb4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f155fb8:	ac7802bc */ 	sw	$t8,0x2bc($v1)
/*  f155fbc:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f155fc0:	5720fffb */ 	bnezl	$t9,.NB0f155fb0
/*  f155fc4:	8c6f02bc */ 	lw	$t7,0x2bc($v1)
/*  f155fc8:	8ca90008 */ 	lw	$t1,0x8($a1)
.NB0f155fcc:
/*  f155fcc:	3c01800b */ 	lui	$at,0x800b
/*  f155fd0:	01245021 */ 	addu	$t2,$t1,$a0
/*  f155fd4:	01475821 */ 	addu	$t3,$t2,$a3
/*  f155fd8:	ac2b9448 */ 	sw	$t3,-0x6bb8($at)
/*  f155fdc:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f155fe0:	3c01800b */ 	lui	$at,0x800b
/*  f155fe4:	14400004 */ 	bnez	$v0,.NB0f155ff8
/*  f155fe8:	00446021 */ 	addu	$t4,$v0,$a0
/*  f155fec:	3c01800b */ 	lui	$at,0x800b
/*  f155ff0:	10000003 */ 	beqz	$zero,.NB0f156000
/*  f155ff4:	ac209454 */ 	sw	$zero,-0x6bac($at)
.NB0f155ff8:
/*  f155ff8:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155ffc:	ac2d9454 */ 	sw	$t5,-0x6bac($at)
.NB0f156000:
/*  f156000:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f156004:	3c01800b */ 	lui	$at,0x800b
/*  f156008:	14400004 */ 	bnez	$v0,.NB0f15601c
/*  f15600c:	00447021 */ 	addu	$t6,$v0,$a0
/*  f156010:	3c01800b */ 	lui	$at,0x800b
/*  f156014:	10000003 */ 	beqz	$zero,.NB0f156024
/*  f156018:	ac209458 */ 	sw	$zero,-0x6ba8($at)
.NB0f15601c:
/*  f15601c:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f156020:	ac2f9458 */ 	sw	$t7,-0x6ba8($at)
.NB0f156024:
/*  f156024:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f156028:	3c01800b */ 	lui	$at,0x800b
/*  f15602c:	14400004 */ 	bnez	$v0,.NB0f156040
/*  f156030:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f156034:	3c01800b */ 	lui	$at,0x800b
/*  f156038:	10000003 */ 	beqz	$zero,.NB0f156048
/*  f15603c:	ac20945c */ 	sw	$zero,-0x6ba4($at)
.NB0f156040:
/*  f156040:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f156044:	ac39945c */ 	sw	$t9,-0x6ba4($at)
.NB0f156048:
/*  f156048:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15604c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f156050:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f156054:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f156058:	03e00008 */ 	jr	$ra
/*  f15605c:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);
#endif

void bgBuildTables(s32 stagenum)
{
	s32 i;
	s32 j;
	s32 k;
	u32 r;
	u8 *header;
	s32 numportals;
	s32 index;
	f32 divisor;
	s16 lightindex;
	s32 candportalnum;
	s32 numportalsthisroom;
	bool swap;
	struct portalvertices *pvertices;
	struct var800a4ccc *tmp;
	s32 numvertices;
	struct var800a4ccc tmp2;
	u8 *scratch;
	u8 headerbuffer[0x50];
	s32 thisneighbournum;
	s32 offset;
	u32 inflatedsize;
	u32 section3compsize;
	s16 *bboxptr;
	u8 *section3;
	u16 *datalenptr;
	u8 *numlightsptr;

	g_Rooms = mempAlloc(ALIGN16(g_Vars.roomcount * sizeof(struct room)), MEMPOOL_STAGE);
	var800a4ce8 = mempAlloc(ALIGN16(g_Vars.roomcount * sizeof(struct var800a4ce8)), MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		var800a4ce8[i].unk00 = 0xffff;
		var800a4ce8[i].unk02 = 0;
	}

	if (g_Vars.mplayerisrunning) {
		g_MpRoomVisibility = mempAlloc(ALIGN16(g_Vars.roomcount), MEMPOOL_STAGE);

		for (i = 0; i < g_Vars.roomcount; i++) {
			g_MpRoomVisibility[i] = 0;
		}
	}

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].vtxbatches = NULL;
		g_Rooms[i].numlights = 0;
		g_Rooms[i].lightindex = 0;
		g_Rooms[i].flags = 0;
		g_Rooms[i].unk4d = 0;
		g_Rooms[i].lightop = 0;
		g_Rooms[i].unk4e_04 = 0;
	}

	func0f15c880(g_Stages[g_StageIndex].unk14);
	chr0f028490(g_Stages[g_StageIndex].unk14);

	for (i = 0; i < 4; i++) {
		g_Vars.playerstats[i].scale_bg2gfx = g_Stages[g_StageIndex].unk18;
	}

	mtx00016748(1);

	if (var800a4920 == 0) {
		numportals = 0;

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			numportals++;
		}

		g_NumPortalThings = numportals;
		g_PortalThings = mempAlloc(ALIGN16(g_NumPortalThings * sizeof(struct portalthing)), MEMPOOL_STAGE);

		// Iterate the portals and update their verticesoffset value. In
		// storage, the g_BgPortals array is followed by vertice data, and each
		// portal's verticesoffset value is an index into the vertice data.
		// Here, the unk00 value is being converted to an offset relative to the
		// start of the g_BgPortals array. Start by initialising offset past the
		// end of the portal array, which is the start of the vertice data.
		offset = numportals * sizeof(struct bgportal);
		offset += sizeof(struct bgportal);

		// Because each group of vertices is variable length, the portals can't
		// be iterated in order and have their offset calculated. The vertice
		// data has to be iterated in storage order, then iterate all portals to
		// see if any refer to this index.
		for (i = 1; true; i++) {
			for (j = 0; j < numportals; j++) {
				if (g_BgPortals[j].verticesoffset == i) {
					g_BgPortals[j].verticesoffset = offset;
				}
			}

			pvertices = (struct portalvertices *)((u32)g_BgPortals + offset);

			if (pvertices->count <= 0) {
				break;
			}

			offset += pvertices->count * 12;
			offset += 4;
		}

		// Calculate g_RoomPortals: An array of portal numbers, ordered by room
		// number ascending. Each room struct contains an index into this array
		// where its portal numbers start.
		index = 0;
		g_RoomPortals = mempAlloc(ALIGN16((numportals == 0 ? 1 : numportals) * sizeof(s16 *)), MEMPOOL_STAGE);

		g_Vars.roomportalrecursionlimit = 0;

		for (i = 0; i < g_Vars.roomcount; i++) {
			numportalsthisroom = 0;

			g_Rooms[i].roomportallistoffset = index;

			for (j = 0; j < numportals; j++) {
				if (i == g_BgPortals[j].roomnum1) {
					g_RoomPortals[index] = j;
					numportalsthisroom++;
					index++;
				}

				if (i == g_BgPortals[j].roomnum2) {
					g_RoomPortals[index] = j;
					numportalsthisroom++;
					index++;
				}
			}


			g_Rooms[i].numportals = numportalsthisroom;

			if (numportalsthisroom > g_Vars.roomportalrecursionlimit) {
				g_Vars.roomportalrecursionlimit = numportalsthisroom;
			}
		}

		// Sort the portal numbers in g_RoomPortals within their room groups.
		// Sorting is done by neighbouring room number ascending.
		//
		// @bug: The k loop doesn't reset to j after doing a swap, which means
		// some items may not be sorted correctly. This isn't a problem if the
		// data on ROM is already sorted, or if they actually don't need to be
		// sorted.
		for (i = 0; i < g_Vars.roomcount; i++) {
			for (j = 0; j < g_Rooms[i].numportals; j++) {
				if (g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum1 == i) {
					thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum2;
				} else {
					thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum1;
				}

				for (k = j; k < g_Rooms[i].numportals; k++) {
					swap = false;

					if (i == g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + k]].roomnum1) {
						if (g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + k]].roomnum2 < thisneighbournum) {
							swap = true;
						}
					} else {
						if (g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + k]].roomnum1 < thisneighbournum) {
							swap = true;
						}
					}

					if (swap) {
						candportalnum = g_RoomPortals[g_Rooms[i].roomportallistoffset + k];
						g_RoomPortals[g_Rooms[i].roomportallistoffset + k] = g_RoomPortals[g_Rooms[i].roomportallistoffset + j];
						g_RoomPortals[g_Rooms[i].roomportallistoffset + j] = candportalnum;

						if (g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum1 == i) {
							thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum2;
						} else {
							thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[i].roomportallistoffset + j]].roomnum1;
						}
					}
				}
			}
		}

		var800a4cd0 = mempAlloc(ALIGN16(numportals == 0 ? 1 : numportals), MEMPOOL_STAGE);

		for (i = 0; i < numportals; i++) {
			var800a4cd0[i] = func0f15b4c0(i);
		}

		var800a4ccc = mempAlloc(ALIGN16(numportals * sizeof(struct var800a4ccc)), MEMPOOL_STAGE);

		for (i = 0; i < numportals; i++) {
			tmp2.coord.x = 0.0f;
			tmp2.coord.y = 0.0f;
			tmp2.coord.z = 0.0f;

			pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[i].verticesoffset);

			for (j = 0; j < pvertices->count; j++) {
				struct coord *next = &pvertices->vertices[(j + 1) % pvertices->count];

				tmp2.coord.x += (pvertices->vertices[j].y - next->y) * (pvertices->vertices[j].z + next->z);
				tmp2.coord.y += (pvertices->vertices[j].z - next->z) * (pvertices->vertices[j].x + next->x);
				tmp2.coord.z += (pvertices->vertices[j].x - next->x) * (pvertices->vertices[j].y + next->y);
			}

			divisor = -sqrtf(tmp2.coord.f[0] * tmp2.coord.f[0] + tmp2.coord.f[1] * tmp2.coord.f[1] + tmp2.coord.f[2] * tmp2.coord.f[2]);

			tmp2.coord.x = tmp2.coord.x / divisor;
			tmp2.coord.y = tmp2.coord.y / divisor;
			tmp2.coord.z = tmp2.coord.z / divisor;

			tmp2.min = MAXFLOAT;
			tmp2.max = MINFLOAT;

			for (j = 0; j < pvertices->count; j++) {
				f32 value = pvertices->vertices[j].f[0] * tmp2.coord.f[0]
					+ pvertices->vertices[j].f[1] * tmp2.coord.f[1]
					+ pvertices->vertices[j].f[2] * tmp2.coord.f[2];

				if (value < tmp2.min) {
					tmp2.min = value;
				}

				if (value > tmp2.max) {
					tmp2.max = value;
				}
			}

			tmp = &var800a4ccc[i];
			tmp->coord.x = tmp2.coord.x;
			tmp->coord.y = tmp2.coord.y;
			tmp->coord.z = tmp2.coord.z;
			tmp->min = tmp2.min;
			tmp->max = tmp2.max;
		}

		portal0f0b65a8(numportals);

		for (i = 0; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags = 0;
			g_Rooms[i].unk06 = 0;
			g_Rooms[i].unk07 = 1;
			g_Rooms[i].loaded240 = 0;
			g_Rooms[i].gfxdata = NULL;
			g_Rooms[i].gfxdatalen = -1;
			g_Rooms[i].opawallhits = NULL;
			g_Rooms[i].xluwallhits = NULL;
		}

		roomsReset();

		g_Rooms[0].bbmin[0] = 0.0f;
		g_Rooms[0].bbmin[1] = 0.0f;
		g_Rooms[0].bbmin[2] = 0.0f;
		g_Rooms[0].bbmax[0] = 0.0f;
		g_Rooms[0].bbmax[1] = 0.0f;
		g_Rooms[0].bbmax[2] = 0.0f;

		dyntexReset();

		// Load section 3 of the BG file. To do this, the header of the BG file
		// must be loaded first as it contains the offset to section 3. Then
		// section 3 is loaded and inflated. Data is read out of section 3, then
		// the section 3 allocation is resized to 0, effectively freeing it.

		// Load and read the header
		header = (u8 *)ALIGN16((u32)headerbuffer);
		bgLoadFile(header, g_BgSection3, 0x40);
		inflatedsize = (*(u16 *)&header[0] & 0x7fff) - 1;
		section3compsize = *(u16 *)&header[2];
		inflatedsize = (inflatedsize | 0xf) + 1;

		// Load and inflate section 3
#ifdef AVOID_UB
		section3 = mempAlloc(inflatedsize + section3compsize, MEMPOOL_STAGE);
		scratch = section3 + inflatedsize;
#elif VERSION >= VERSION_NTSC_FINAL
		section3 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
		scratch = section3 + 0x8000;
#else
		section3 = mempAlloc(inflatedsize + 0x1000, MEMPOOL_STAGE);
		scratch = section3 + 0x1000;
#endif

		bgLoadFile(scratch, g_BgSection3 + 4, ((section3compsize - 1) | 0xf) + 1);
		bgInflate(scratch, section3, section3compsize);

		// Section 3 starts with a table of room bounding boxes
		bboxptr = (s16 *) section3;

		for (r = 1; r < g_Vars.roomcount; r++) {
			// Calculate bounding box
			g_Rooms[r].bbmin[0] = *bboxptr + g_BgRooms[r].pos.x; bboxptr++;
			g_Rooms[r].bbmin[1] = *bboxptr + g_BgRooms[r].pos.y; bboxptr++;
			g_Rooms[r].bbmin[2] = *bboxptr + g_BgRooms[r].pos.z; bboxptr++;
			g_Rooms[r].bbmax[0] = *bboxptr + g_BgRooms[r].pos.x; bboxptr++;
			g_Rooms[r].bbmax[1] = *bboxptr + g_BgRooms[r].pos.y; bboxptr++;
			g_Rooms[r].bbmax[2] = *bboxptr + g_BgRooms[r].pos.z; bboxptr++;

			if (1);

			// Calculate centre
			g_Rooms[r].centre.x = (g_Rooms[r].bbmin[0] + g_Rooms[r].bbmax[0]) / 2.0f;
			g_Rooms[r].centre.y = (g_Rooms[r].bbmin[1] + g_Rooms[r].bbmax[1]) / 2.0f;
			g_Rooms[r].centre.z = (g_Rooms[r].bbmin[2] + g_Rooms[r].bbmax[2]) / 2.0f;

			if (1);

			// Calculate radius
			g_Rooms[r].radius = sqrtf((g_Rooms[r].bbmin[0] - g_Rooms[r].bbmax[0]) * (g_Rooms[r].bbmin[0] - g_Rooms[r].bbmax[0])
					+ (g_Rooms[r].bbmin[1] - g_Rooms[r].bbmax[1]) * (g_Rooms[r].bbmin[1] - g_Rooms[r].bbmax[1])
					+ (g_Rooms[r].bbmin[2] - g_Rooms[r].bbmax[2]) * (g_Rooms[r].bbmin[2] - g_Rooms[r].bbmax[2])) / 2.0f;
		}

		// The next part of section 3 is a list of roomgfxdata sizes.
		// There is one per room and the value needs to be multiplied by 0x10.
		datalenptr = (u16 *) bboxptr;

		for (r = 1; r < g_Vars.roomcount; r++) {
			g_Rooms[r].gfxdatalen = ALIGN16(*datalenptr * 0x10 + 0x100);
			datalenptr++;
		}

		// The last part of section 3 is the number of lights per room.
		// This is calculating the index into the lights file where each room's
		// lights start. The light data is already ordered by room, so it can do
		// this easily by adding to the offset of the previous one.
		lightindex = 0;
		numlightsptr = (u8 *) datalenptr;

		for (r = 1; r < g_Vars.roomcount; r++) {
			g_Rooms[r].numlights = *numlightsptr;

			if (g_Rooms[r].numlights > 0) {
				g_Rooms[r].lightindex = lightindex;
				lightindex += g_Rooms[r].numlights;
			} else {
				g_Rooms[r].lightindex = -1;
			}

			numlightsptr++;
		}

		// Free the section 3 allocation
		mempRealloc(section3, 0, MEMPOOL_STAGE);

		for (i = 1; i < g_Vars.roomcount; i++) {
			roomInitLights(i);
		}

		// Initialise a table related to lights.
		// j is being reused here as a total light count.
		j = 0;

		for (i = 1; i < g_Vars.roomcount; i++) {
			j += g_Rooms[i].numlights;
		}

		if (j) {
			var800a41a0 = mempAlloc(ALIGN16(j * 3), MEMPOOL_STAGE);

			for (i = 0; i < j; i++) {
				var800a41a0[i * 3 + 0] = 0;
				var800a41a0[i * 3 + 1] = 0;
				var800a41a0[i * 3 + 2] = 0;
			}
		} else {
			var800a41a0 = NULL;
		}

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			func0f164ab8(i);
		}

		for (i = 1; i < g_Vars.roomcount; i++) {
			room0f164c64(i);
		}

		for (i = 1; i < g_Vars.roomcount; i++) {
			bgExpandRoomToPortals(i);
		}

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			g_BgPortals[i].flags &= (~PORTALFLAG_CLOSED) & 0xff;
		}
	}

	envSetStageNum(stagenum);

	var8007fc10 = 200;

	wallhitReset();
	func0f002a98();
	func0f001c0c();

#if VERSION < VERSION_NTSC_1_0
	bgBuildReferenceLightSums();
#endif
}

void bgStop(void)
{
	bgUnloadAllRooms();
	mtx00016748(1);
}

void func0f15c880(f32 arg0)
{
	// empty
}

f32 func0f15c888(void)
{
	return g_Stages[g_StageIndex].unk1c / g_Stages[g_StageIndex].unk14;
}

f32 currentPlayerGetScaleBg2Gfx(void)
{
	return g_Vars.currentplayerstats->scale_bg2gfx;
}

void currentPlayerSetScaleBg2Gfx(f32 scale)
{
	g_Vars.currentplayerstats->scale_bg2gfx = g_Stages[g_StageIndex].unk18 * scale;
	mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);
}

void func0f15c920(void)
{
	var8007fc3c++;

	if (var8007fc3c == 0xffff) {
		var8007fc3c = 1;
		func0f15cd28();
	}

#if PIRACYCHECKS
	if ((var8007fc3c & 0xff) == 0xff) {
		u32 checksum = 0;
		s32 *ptr = (s32 *)&menuTickTimers;
		s32 *end = (s32 *)&menuGetSinOscFrac;

		while (ptr < end) {
			checksum ^= ~*ptr;
			checksum ^= *ptr << 5;
			checksum ^= *ptr >> 15;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			ptr = (s32 *)&bgBuildTables + 20;

			if (1) {
				end = &ptr[4];
			}

			while (ptr < end) {
				*ptr -= 0x24e21;
				ptr++;
			}
		}
	}
#endif
}

void bgTick(void)
{
	s32 tickmode;

	g_NumActiveRooms = 0;

#if VERSION < VERSION_NTSC_1_0
	bgVerifyLightSums("bg.c", 5761);
#endif

	func0f15c920();

	if (g_Vars.currentplayerindex == 0 && !g_BgPreload) {
		bgTickRooms();
	}

	tickmode = g_Vars.tickmode;

	if (tickmode == TICKMODE_NORMAL) {
		var8007fc10 = 4;

#if VERSION >= VERSION_NTSC_1_0
		if (IS8MB() && var8007fc0c)
#else
		if (var8007fc0c)
#endif
		{
			var8007fc0c--;
			var8007fc10 = 200;
		}
	} else {
		var8007fc0c = 8;
		var8007fc10 = 200;
	}

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		var8007fc10 = 100;
	}

	g_CamRoom = g_Vars.currentplayer->cam_room;

#if VERSION >= VERSION_NTSC_1_0
	bgTickPortals();
#else
	bgVerifyLightSums("bg.c", 5834);
	bgTickPortals();
	bgVerifyLightSums("bg.c", 5846);
#endif
}

Gfx *bgRender(Gfx *gdl)
{
	gdl = lightsSetDefault(gdl);

	gSPSegment(gdl++, SPSEGMENT_BG_DL, g_BgPrimaryData);

	gdl = envStartFog(gdl, false);
	gdl = func0f164150(gdl);
	gdl = currentPlayerScissorToViewport(gdl);
	gdl = envStopFog(gdl);

	gSPMatrix(gdl++, var80092870, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	gdl = playerLoadMatrix(gdl);

	return gdl;
}

f32 func0f15cb5c(s32 arg0)
{
	return g_BgTable5[arg0 + 1];
}

Gfx *currentPlayerScissorToViewport(Gfx *gdl)
{
	return currentPlayerScissorWithinViewport(gdl,
			g_Vars.currentplayer->viewleft,
			g_Vars.currentplayer->viewtop,
			g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth,
			g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight);
}

Gfx *currentPlayerScissorWithinViewportF(Gfx *gdl, f32 viewleft, f32 viewtop, f32 viewright, f32 viewbottom)
{
	gdl = currentPlayerScissorWithinViewport(gdl, viewleft, viewtop, ceil(viewright), ceil(viewbottom));

	return gdl;
}

Gfx *currentPlayerScissorWithinViewport(Gfx *gdl, s32 viewleft, s32 viewtop, s32 viewright, s32 viewbottom)
{
	if (viewleft < g_Vars.currentplayer->viewleft) {
		viewleft = g_Vars.currentplayer->viewleft;
	}

	if (viewtop < g_Vars.currentplayer->viewtop) {
		viewtop = g_Vars.currentplayer->viewtop;
	}

	if (viewright > g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth) {
		viewright = g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth;
	}

	if (viewbottom > g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight) {
		viewbottom = g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viewleft, viewtop, viewright, viewbottom);

	return gdl;
}

void func0f15cd28(void)
{
	s32 i;

	for (i = 0; i < g_NumPortalThings; i++) {
		g_PortalThings[i].unk06 = -1;
		g_PortalThings[i].unk04 = 0;
		g_PortalThings[i].unk00 = 0;
	}
}

bool func0f15cd90(u32 room, struct screenbox *screen)
{
	s32 i;
	struct coord roomscreenpos;
	struct coord corner;
	s32 numa = 0;
	s32 numb = 0;
	s32 numc = 0;
	s32 numd = 0;
	s32 nume = 0;
	s32 numf = 0;

	for (i = 0; i != 8; i++) {
		if (i & 1) {
			corner.x = g_Rooms[room].bbmin[0];
		} else {
			corner.x = g_Rooms[room].bbmax[0];
		}

		if (i & 2) {
			corner.y = g_Rooms[room].bbmin[1];
		} else {
			corner.y = g_Rooms[room].bbmax[1];
		}

		if (i & 4) {
			corner.z = g_Rooms[room].bbmin[2];
		} else {
			corner.z = g_Rooms[room].bbmax[2];
		}

		if (func0f15d08c(&corner, &roomscreenpos) == 0) {
			if (var800a4cf0.zrange.far <= -roomscreenpos.z) {
				numb++;
			}

			if (roomscreenpos.x > screen->xmin) {
				numc++;
			}

			if (roomscreenpos.x < screen->xmax) {
				numd++;
			}

			if (roomscreenpos.y > screen->ymin) {
				nume++;
			}

			if (roomscreenpos.y < screen->ymax) {
				numf++;
			}

			numa++;
		} else {
			if (var800a4cf0.zrange.far <= -roomscreenpos.z) {
				numb++;
			}

			if (roomscreenpos.x < screen->xmin) {
				numc++;
			} else if (screen->xmax < roomscreenpos.x) {
				numd++;
			}

			if (roomscreenpos.y < screen->ymin) {
				nume++;
			} else if (screen->ymax < roomscreenpos.y) {
				numf++;
			}
		}
	}

	if (numa == 8
			|| numb == 8
			|| numc == 8
			|| numd == 8
			|| nume == 8
			|| numf == 8) {
		return false;
	}

	return true;
}

bool func0f15d08c(struct coord *a, struct coord *b)
{
	Mtxf *matrix = camGetWorldToScreenMtxf();

	b->x = a->x;
	b->y = a->y;
	b->z = a->z;

	mtx4TransformVecInPlace(matrix, b);
	cam0f0b4d68(b, b->f);

	if (b->z > 0) {
		return false;
	}

	return true;
}

bool g_PortalGetScreenBbox(s32 portalnum, struct screenbox *box)
{
	s32 i;
	s32 j;
	s32 len;
	s32 start;
	s32 sp2ec;
	f32 sp2e4[2];
	f32 sp2d4[2][2];
	struct portalthing2 *thing;
	struct portalthing2 things[40];

	if (var8007fc3c == g_PortalThings[portalnum].unk04) {
		box->xmin = g_PortalThings[portalnum].xmin;
		box->ymin = g_PortalThings[portalnum].ymin;
		box->xmax = g_PortalThings[portalnum].xmax;
		box->ymax = g_PortalThings[portalnum].ymax;

		return g_PortalThings[portalnum].unk06;
	}

	len = func0f165360(portalnum, &start, things);

	sp2ec = 0;
	thing = &things[start];

	for (j = 0; j < len; j++) {
		if (thing->coord.z <= 0.0f) {
			cam0f0b4d68(&thing->coord, sp2e4);

			if (sp2ec == 0) {
				sp2d4[0][0] = sp2d4[1][0] = sp2e4[0];
				sp2d4[0][1] = sp2d4[1][1] = sp2e4[1];
			} else {
				if (sp2e4[0] < sp2d4[0][0]) {
					sp2d4[0][0] = sp2e4[0];
				}

				if (sp2d4[1][0] < sp2e4[0]) {
					sp2d4[1][0] = sp2e4[0];
				}

				if (sp2e4[1] < sp2d4[0][1]) {
					sp2d4[0][1] = sp2e4[1];
				}

				if (sp2d4[1][1] < sp2e4[1]) {
					sp2d4[1][1] = sp2e4[1];
				}
			}

			sp2ec++;
		}

		thing++;
	}

	if (sp2ec == 0) {
		box->xmin = 0;
		box->xmax = 0;
		box->ymin = 0;
		box->ymax = 0;
	} else if (sp2d4[1][0] < sp2d4[0][0] || sp2d4[1][1] < sp2d4[0][1]) {
		struct player *player = g_Vars.currentplayer;
		box->xmin = player->screenxminf;
		box->ymin = player->screenyminf;
		box->xmax = player->screenxmaxf;
		box->ymax = player->screenymaxf;
	} else {
		sp2d4[0][0] -= 0.5f;
		sp2d4[0][1] -= 0.5f;
		sp2d4[1][0] += 0.5f;
		sp2d4[1][1] += 0.5f;

		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				f32 value = sp2d4[i][j];

				if (value >= 0.0f) {
					if (value > 32000.0f) {
						box->array[i][j] = 32000;
					} else {
						box->array[i][j] = value;
					}
				} else if (value < -32000.0f) {
					box->array[i][j] = -32000;
				} else {
					box->array[i][j] = value;
				}
			}
		}
	}

	g_PortalThings[portalnum].xmin = box->xmin;
	g_PortalThings[portalnum].ymin = box->ymin;
	g_PortalThings[portalnum].xmax = box->xmax;
	g_PortalThings[portalnum].ymax = box->ymax;
	g_PortalThings[portalnum].unk06 = sp2ec;
	g_PortalThings[portalnum].unk04 = var8007fc3c;

	return sp2ec;
}

Gfx *boxRenderBorder(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2 + 1, y2 + 1);

	return gdl;
}

Gfx *boxRender(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gdl = boxRenderBorder(gdl, x1, y1, x2, y1); // top
	gdl = boxRenderBorder(gdl, x2, y1, x2, y2); // right
	gdl = boxRenderBorder(gdl, x1, y2, x2, y2); // bottom
	gdl = boxRenderBorder(gdl, x1, y1, x1, y2); // left

	return gdl;
}

bool boxGetIntersection(struct screenbox *a, struct screenbox *b)
{
	a->xmin = a->xmin > b->xmin ? a->xmin : b->xmin;
	a->ymin = a->ymin > b->ymin ? a->ymin : b->ymin;
	a->xmax = b->xmax > a->xmax ? a->xmax : b->xmax;
	a->ymax = b->ymax > a->ymax ? a->ymax : b->ymax;

	if (a->xmin >= a->xmax) {
		a->xmin = a->xmax;
		return false;
	}

	if (a->ymax <= a->ymin) {
		a->ymin = a->ymax;
		return false;
	}

	return true;
}

void boxExpand(struct screenbox *a, struct screenbox *b)
{
	a->xmin = a->xmin < b->xmin ? a->xmin : b->xmin;
	a->ymin = a->ymin < b->ymin ? a->ymin : b->ymin;
	a->xmax = a->xmax > b->xmax ? a->xmax : b->xmax;
	a->ymax = a->ymax > b->ymax ? a->ymax : b->ymax;
}

void boxCopy(struct screenbox *dst, struct screenbox *src)
{
	dst->xmin = src->xmin;
	dst->ymin = src->ymin;
	dst->xmax = src->xmax;
	dst->ymax = src->ymax;
}

bool roomIsOnscreen(s32 room)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & 0xf) != 0;
	}

	return g_Rooms[room].flags & ROOMFLAG_ONSCREEN;
}

bool roomIsStandby(s32 room)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & 0xf0) != 0;
	}

	return g_Rooms[room].flags & ROOMFLAG_STANDBY;
}

bool roomIsOnPlayerScreen(s32 room, u32 playernum)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & (1 << playernum)) != 0;
	}

	return g_Rooms[room].flags & ROOMFLAG_ONSCREEN;
}

bool roomIsOnPlayerStandby(s32 room, u32 playernum)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & (0x10 << playernum)) != 0;
	}

	return g_Rooms[room].flags & ROOMFLAG_STANDBY;
}

s32 portalFindNumByVertices(struct portalvertices *arg0)
{
	s32 i;
	struct bgportal *portal = g_BgPortals;

	for (i = 0; portal[i].verticesoffset != 0; i++) {
		struct portalvertices *pvertices = (struct portalvertices *)((u32)portal + portal[i].verticesoffset);

		if (pvertices == arg0) {
			return i;
		}
	}

	return 0;
}

/**
 * Build a string showing the state of all rooms in the stage.
 *
 * The string contains "L" if a room is loaded, "." if not, and has line breaks
 * every 40 characters.
 *
 * Nothing is done with the string though. It's likely that debug versions of
 * the game would send the string to the host computer or display it on the HUD.
 */
void roomsHandleStateDebugging(void)
{
	if (debugIsRoomStateDebugEnabled()) {
		u8 string[704];
		s32 len = 0;
		s32 i;

		for (i = 1; i < g_Vars.roomcount; i++) {
			if ((i - 1) % 40 == 0) {
				if (i != 1) {
					string[len] = '\n';
					len++;
				}
			}

			if (g_Rooms[i].loaded240) {
				string[len] = 'L';
			} else {
				string[len] = '.';
			}

			len++;
		}

		string[len] = '\0';
	}
}

u32 bgInflate(u8 *src, u8 *dst, u32 len)
{
	u32 result;
	u8 scratch[5120];
#if VERSION < VERSION_NTSC_1_0
	char message[128];
#endif

	if (rzipIs1173(src)) {
		result = rzipInflate(src, dst, &scratch);

#if VERSION < VERSION_NTSC_1_0
		if (!result) {
			sprintf(message, "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
					"bg.c", 6914,
					src[0], src[1], src[2], src[3],
					src[4], src[5], src[6], src[7],
					src[8], src[9], src[10], src[11],
					src[12], src[13], src[14], src[15]);

			crashSetMessage(&message);
			CRASH();
		}
#endif
	} else {
		result = len;
		bcopy(src, dst, len);
	}

	return result;
}

Gfx *roomGetNextGdlInBlock(struct roomblock *block, Gfx *start, Gfx *end)
{ \
	Gfx *tmp; \
	while (true) {
		if (block == NULL) {
			return end;
		}

		if (start);
		if (start);
		if (start);
		if (start);

		switch (block->type) {
		case ROOMBLOCKTYPE_LEAF:
			if (block->gdl > start && (block->gdl < end || end == NULL)) {
				end = block->gdl;
			}
			block = block->next;
			break;
		case ROOMBLOCKTYPE_PARENT:
			tmp = roomGetNextGdlInBlock(block->child, start, end);
			block = block->next;
			end = tmp;
			break;
		default:
			return end;
		}
	}

	return end;
}

Gfx *roomGetNextGdlInLayer(s32 roomnum, Gfx *start, u32 types)
{
	struct roomblock *opablocks = g_Rooms[roomnum].gfxdata->opablocks;
	struct roomblock *xlublocks = g_Rooms[roomnum].gfxdata->xlublocks;
	Gfx *opagdl = NULL;
	Gfx *xlugdl = NULL;

	if ((types & VTXBATCHTYPE_OPA) && opablocks) {
		opagdl = roomGetNextGdlInBlock(opablocks, start, NULL);

		if (types == VTXBATCHTYPE_OPA) {
			return opagdl;
		}
	}

	if ((types & VTXBATCHTYPE_XLU) && xlublocks) {
		xlugdl = roomGetNextGdlInBlock(xlublocks, start, NULL);

		if (types == VTXBATCHTYPE_XLU) {
			return xlugdl;
		}
	}

	if (opagdl) {
		if (xlugdl && xlugdl < opagdl) {
			return xlugdl;
		}

		return opagdl;
	}

	return xlugdl;
}

struct gfxvtx *roomFindVerticesForGdl(s32 roomnum, Gfx *gdl)
{
	struct roomblock *block = g_Rooms[roomnum].gfxdata->blocks;
	u32 end = (u32)g_Rooms[roomnum].gfxdata->vertices;

	while ((u32)(block + 1) <= end) {
		switch (block->type) {
		case ROOMBLOCKTYPE_LEAF:
			if (gdl == block->gdl) {
				return block->vertices;
			}
			break;
		case ROOMBLOCKTYPE_PARENT:
			if ((u32)block->unk0c < end) {
				end = (u32)block->unk0c;
			}
			break;
		}

		block++;
	}

	return NULL;
}

#if MATCHING
#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bgLoadRoom
/*  f15dc58:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f15dc5c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f15dc60:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f15dc64:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15dc68:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f15dc6c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f15dc70:	108001f8 */ 	beqz	$a0,.L0f15e454
/*  f15dc74:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f15dc78:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x2bc)
/*  f15dc7c:	8dcea27c */ 	lw	$t6,%lo(g_Vars+0x2bc)($t6)
/*  f15dc80:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f15dc84:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f15dc88:	008e082a */ 	slt	$at,$a0,$t6
/*  f15dc8c:	102001f1 */ 	beqz	$at,.L0f15e454
/*  f15dc90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dc94:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f15dc98:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f15dc9c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f15dca0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dca4:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f15dca8:	030f1821 */ 	addu	$v1,$t8,$t7
/*  f15dcac:	846b0002 */ 	lh	$t3,0x2($v1)
/*  f15dcb0:	556001e9 */ 	bnezl	$t3,.L0f15e458
/*  f15dcb4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f15dcb8:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f15dcbc:	18400009 */ 	blez	$v0,.L0f15dce4
/*  f15dcc0:	00000000 */ 	nop
/*  f15dcc4:	afa202f4 */ 	sw	$v0,0x2f4($sp)
/*  f15dcc8:	0fc47b6c */ 	jal	debug0f11edb0
/*  f15dccc:	afa402f8 */ 	sw	$a0,0x2f8($sp)
/*  f15dcd0:	10400007 */ 	beqz	$v0,.L0f15dcf0
/*  f15dcd4:	8fac02f4 */ 	lw	$t4,0x2f4($sp)
/*  f15dcd8:	258d0400 */ 	addiu	$t5,$t4,0x400
/*  f15dcdc:	10000004 */ 	b	.L0f15dcf0
/*  f15dce0:	afad02f4 */ 	sw	$t5,0x2f4($sp)
.L0f15dce4:
/*  f15dce4:	0c004b37 */ 	jal	memaGetLongestFree
/*  f15dce8:	afa402f8 */ 	sw	$a0,0x2f8($sp)
/*  f15dcec:	afa202f4 */ 	sw	$v0,0x2f4($sp)
.L0f15dcf0:
/*  f15dcf0:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f15dcf4:	0fc5796e */ 	jal	bgGarbageCollectRooms
/*  f15dcf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f15dcfc:	0c004aac */ 	jal	memaAlloc
/*  f15dd00:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f15dd04:	104001d3 */ 	beqz	$v0,.L0f15e454
/*  f15dd08:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15dd0c:	0fc4f0dc */ 	jal	dyntexSetCurrentRoom
/*  f15dd10:	87a402fa */ 	lh	$a0,0x2fa($sp)
/*  f15dd14:	8fb002f8 */ 	lw	$s0,0x2f8($sp)
/*  f15dd18:	3c11800a */ 	lui	$s1,%hi(g_BgRooms)
/*  f15dd1c:	26314cc4 */ 	addiu	$s1,$s1,%lo(g_BgRooms)
/*  f15dd20:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f15dd24:	00107080 */ 	sll	$t6,$s0,0x2
/*  f15dd28:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f15dd2c:	000e8080 */ 	sll	$s0,$t6,0x2
/*  f15dd30:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f15dd34:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f15dd38:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f15dd3c:	3c04800a */ 	lui	$a0,%hi(g_BgPrimaryData)
/*  f15dd40:	8c84491c */ 	lw	$a0,%lo(g_BgPrimaryData)($a0)
/*  f15dd44:	03039023 */ 	subu	$s2,$t8,$v1
/*  f15dd48:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f15dd4c:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f15dd50:	8fa702f4 */ 	lw	$a3,0x2f4($sp)
/*  f15dd54:	0241c824 */ 	and	$t9,$s2,$at
/*  f15dd58:	00645821 */ 	addu	$t3,$v1,$a0
/*  f15dd5c:	3c01f100 */ 	lui	$at,0xf100
/*  f15dd60:	3c0c8008 */ 	lui	$t4,%hi(var8007fc54)
/*  f15dd64:	01642823 */ 	subu	$a1,$t3,$a0
/*  f15dd68:	8d8cfc54 */ 	lw	$t4,%lo(var8007fc54)($t4)
/*  f15dd6c:	00a12821 */ 	addu	$a1,$a1,$at
/*  f15dd70:	00f9082a */ 	slt	$at,$a3,$t9
/*  f15dd74:	03209025 */ 	or	$s2,$t9,$zero
/*  f15dd78:	10200005 */ 	beqz	$at,.L0f15dd90
/*  f15dd7c:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f15dd80:	0fc4f0dc */ 	jal	dyntexSetCurrentRoom
/*  f15dd84:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15dd88:	100001b3 */ 	b	.L0f15e458
/*  f15dd8c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15dd90:
/*  f15dd90:	00f26823 */ 	subu	$t5,$a3,$s2
/*  f15dd94:	01b49821 */ 	addu	$s3,$t5,$s4
/*  f15dd98:	02602025 */ 	or	$a0,$s3,$zero
/*  f15dd9c:	0fc56c71 */ 	jal	bgLoadFile
/*  f15dda0:	02403025 */ 	or	$a2,$s2,$zero
/*  f15dda4:	0c002277 */ 	jal	rzipIs1173
/*  f15dda8:	02602025 */ 	or	$a0,$s3,$zero
/*  f15ddac:	10400009 */ 	beqz	$v0,.L0f15ddd4
/*  f15ddb0:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f15ddb4:	264f0020 */ 	addiu	$t7,$s2,0x20
/*  f15ddb8:	01cf082a */ 	slt	$at,$t6,$t7
/*  f15ddbc:	50200006 */ 	beqzl	$at,.L0f15ddd8
/*  f15ddc0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15ddc4:	0fc4f0dc */ 	jal	dyntexSetCurrentRoom
/*  f15ddc8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15ddcc:	100001a2 */ 	b	.L0f15e458
/*  f15ddd0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15ddd4:
/*  f15ddd4:	8e380000 */ 	lw	$t8,0x0($s1)
.L0f15ddd8:
/*  f15ddd8:	02602025 */ 	or	$a0,$s3,$zero
/*  f15dddc:	02802825 */ 	or	$a1,$s4,$zero
/*  f15dde0:	03101021 */ 	addu	$v0,$t8,$s0
/*  f15dde4:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f15dde8:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f15ddec:	0fc5766a */ 	jal	bgInflate
/*  f15ddf0:	032b3023 */ 	subu	$a2,$t9,$t3
/*  f15ddf4:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f15ddf8:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f15ddfc:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f15de00:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f15de04:	afa202f0 */ 	sw	$v0,0x2f0($sp)
/*  f15de08:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15de0c:	01886821 */ 	addu	$t5,$t4,$t0
/*  f15de10:	adb40014 */ 	sw	$s4,0x14($t5)
/*  f15de14:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de18:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de1c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de20:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f15de24:	5060000b */ 	beqzl	$v1,.L0f15de54
/*  f15de28:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f15de2c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de30:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de34:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de38:	006b6023 */ 	subu	$t4,$v1,$t3
/*  f15de3c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15de40:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f15de44:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de48:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de4c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de50:	8e620004 */ 	lw	$v0,0x4($s3)
.L0f15de54:
/*  f15de54:	5040000b */ 	beqzl	$v0,.L0f15de84
/*  f15de58:	8e620008 */ 	lw	$v0,0x8($s3)
/*  f15de5c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de60:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de64:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de68:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15de6c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15de70:	ae6d0004 */ 	sw	$t5,0x4($s3)
/*  f15de74:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de78:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de7c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de80:	8e620008 */ 	lw	$v0,0x8($s3)
.L0f15de84:
/*  f15de84:	5040000b */ 	beqzl	$v0,.L0f15deb4
/*  f15de88:	8e62000c */ 	lw	$v0,0xc($s3)
/*  f15de8c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de90:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de94:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de98:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15de9c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15dea0:	ae6d0008 */ 	sw	$t5,0x8($s3)
/*  f15dea4:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15dea8:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15deac:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15deb0:	8e62000c */ 	lw	$v0,0xc($s3)
.L0f15deb4:
/*  f15deb4:	5040000b */ 	beqzl	$v0,.L0f15dee4
/*  f15deb8:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f15debc:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15dec0:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15dec4:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15dec8:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15decc:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15ded0:	ae6d000c */ 	sw	$t5,0xc($s3)
/*  f15ded4:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15ded8:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15dedc:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15dee0:	8e620000 */ 	lw	$v0,0x0($s3)
.L0f15dee4:
/*  f15dee4:	26630018 */ 	addiu	$v1,$s3,0x18
/*  f15dee8:	24650014 */ 	addiu	$a1,$v1,0x14
/*  f15deec:	0045082b */ 	sltu	$at,$v0,$a1
/*  f15def0:	14200060 */ 	bnez	$at,.L0f15e074
/*  f15def4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15def8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15defc:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f15df00:
/*  f15df00:	50400006 */ 	beqzl	$v0,.L0f15df1c
/*  f15df04:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f15df08:	50470029 */ 	beql	$v0,$a3,.L0f15dfb0
/*  f15df0c:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f15df10:	10000050 */ 	b	.L0f15e054
/*  f15df14:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15df18:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f15df1c:
/*  f15df1c:	50400008 */ 	beqzl	$v0,.L0f15df40
/*  f15df20:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f15df24:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15df28:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15df2c:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15df30:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15df34:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15df38:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f15df3c:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f15df40:
/*  f15df40:	50400008 */ 	beqzl	$v0,.L0f15df64
/*  f15df44:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15df48:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f15df4c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f15df50:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f15df54:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f15df58:	03345821 */ 	addu	$t3,$t9,$s4
/*  f15df5c:	ac6b0008 */ 	sw	$t3,0x8($v1)
/*  f15df60:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15df64:
/*  f15df64:	50400008 */ 	beqzl	$v0,.L0f15df88
/*  f15df68:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f15df6c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f15df70:	01906821 */ 	addu	$t5,$t4,$s0
/*  f15df74:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f15df78:	004e7823 */ 	subu	$t7,$v0,$t6
/*  f15df7c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f15df80:	ac78000c */ 	sw	$t8,0xc($v1)
/*  f15df84:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f15df88:
/*  f15df88:	50400032 */ 	beqzl	$v0,.L0f15e054
/*  f15df8c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15df90:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f15df94:	03305821 */ 	addu	$t3,$t9,$s0
/*  f15df98:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f15df9c:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f15dfa0:	01b47021 */ 	addu	$t6,$t5,$s4
/*  f15dfa4:	1000002a */ 	b	.L0f15e050
/*  f15dfa8:	ac6e0010 */ 	sw	$t6,0x10($v1)
/*  f15dfac:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f15dfb0:
/*  f15dfb0:	50400008 */ 	beqzl	$v0,.L0f15dfd4
/*  f15dfb4:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f15dfb8:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f15dfbc:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f15dfc0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f15dfc4:	00595823 */ 	subu	$t3,$v0,$t9
/*  f15dfc8:	01746021 */ 	addu	$t4,$t3,$s4
/*  f15dfcc:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f15dfd0:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f15dfd4:
/*  f15dfd4:	50400008 */ 	beqzl	$v0,.L0f15dff8
/*  f15dfd8:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15dfdc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f15dfe0:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f15dfe4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f15dfe8:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f15dfec:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f15dff0:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f15dff4:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15dff8:
/*  f15dff8:	50400008 */ 	beqzl	$v0,.L0f15e01c
/*  f15dffc:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f15e000:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f15e004:	01706021 */ 	addu	$t4,$t3,$s0
/*  f15e008:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f15e00c:	004d7023 */ 	subu	$t6,$v0,$t5
/*  f15e010:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f15e014:	ac6f000c */ 	sw	$t7,0xc($v1)
/*  f15e018:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f15e01c:
/*  f15e01c:	50400008 */ 	beqzl	$v0,.L0f15e040
/*  f15e020:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15e024:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15e028:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15e02c:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15e030:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15e034:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15e038:	ac6d0010 */ 	sw	$t5,0x10($v1)
/*  f15e03c:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15e040:
/*  f15e040:	0044082b */ 	sltu	$at,$v0,$a0
/*  f15e044:	50200003 */ 	beqzl	$at,.L0f15e054
/*  f15e048:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15e04c:	00402025 */ 	or	$a0,$v0,$zero
.L0f15e050:
/*  f15e050:	00a01825 */ 	or	$v1,$a1,$zero
.L0f15e054:
/*  f15e054:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f15e058:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15e05c:	5020ffa8 */ 	beqzl	$at,.L0f15df00
/*  f15e060:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f15e064:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15e068:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15e06c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15e070:	8e620000 */ 	lw	$v0,0x0($s3)
.L0f15e074:
/*  f15e074:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f15e078:	2401000c */ 	addiu	$at,$zero,0xc
/*  f15e07c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15e080:	0302c823 */ 	subu	$t9,$t8,$v0
/*  f15e084:	0321001b */ 	divu	$zero,$t9,$at
/*  f15e088:	00005812 */ 	mflo	$t3
/*  f15e08c:	a66b0014 */ 	sh	$t3,0x14($s3)
/*  f15e090:	0fc576ad */ 	jal	roomGetNextGdlInLayer
/*  f15e094:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e098:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f15e09c:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f15e0a0:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e0a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f15e0a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f15e0ac:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f15e0b0:	8dd30014 */ 	lw	$s3,0x14($t6)
/*  f15e0b4:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15e0b8:	8e6f0004 */ 	lw	$t7,0x4($s3)
/*  f15e0bc:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f15e0c0:	0018c882 */ 	srl	$t9,$t8,0x2
/*  f15e0c4:	a6790016 */ 	sh	$t9,0x16($s3)
/*  f15e0c8:	0fc576ad */ 	jal	roomGetNextGdlInLayer
/*  f15e0cc:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e0d0:	10400014 */ 	beqz	$v0,.L0f15e124
/*  f15e0d4:	00408025 */ 	or	$s0,$v0,$zero
/*  f15e0d8:	00121080 */ 	sll	$v0,$s2,0x2
/*  f15e0dc:	27ab0208 */ 	addiu	$t3,$sp,0x208
/*  f15e0e0:	27ac0140 */ 	addiu	$t4,$sp,0x140
/*  f15e0e4:	004c8821 */ 	addu	$s1,$v0,$t4
/*  f15e0e8:	004b9821 */ 	addu	$s3,$v0,$t3
.L0f15e0ec:
/*  f15e0ec:	ae700000 */ 	sw	$s0,0x0($s3)
/*  f15e0f0:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e0f4:	0fc576ed */ 	jal	roomFindVerticesForGdl
/*  f15e0f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e0fc:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f15e100:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15e104:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f15e108:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f15e10c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e110:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e114:	0fc576ad */ 	jal	roomGetNextGdlInLayer
/*  f15e118:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15e11c:	1440fff3 */ 	bnez	$v0,.L0f15e0ec
/*  f15e120:	00408025 */ 	or	$s0,$v0,$zero
.L0f15e124:
/*  f15e124:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f15e128:	00123880 */ 	sll	$a3,$s2,0x2
/*  f15e12c:	27ad0208 */ 	addiu	$t5,$sp,0x208
/*  f15e130:	00ed9821 */ 	addu	$s3,$a3,$t5
/*  f15e134:	028e1021 */ 	addu	$v0,$s4,$t6
/*  f15e138:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f15e13c:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f15e140:	8fa40208 */ 	lw	$a0,0x208($sp)
/*  f15e144:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f15e148:	02988021 */ 	addu	$s0,$s4,$t8
/*  f15e14c:	00441823 */ 	subu	$v1,$v0,$a0
/*  f15e150:	02032823 */ 	subu	$a1,$s0,$v1
/*  f15e154:	0fc5d7bd */ 	jal	texCopyGdls
/*  f15e158:	00603025 */ 	or	$a2,$v1,$zero
/*  f15e15c:	26420001 */ 	addiu	$v0,$s2,0x1
/*  f15e160:	1840000d */ 	blez	$v0,.L0f15e198
/*  f15e164:	00004025 */ 	or	$t0,$zero,$zero
/*  f15e168:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15e16c:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f15e170:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e174:	02192023 */ 	subu	$a0,$s0,$t9
.L0f15e178:
/*  f15e178:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f15e17c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e180:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f15e184:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f15e188:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15e18c:	1502fffa */ 	bne	$t0,$v0,.L0f15e178
/*  f15e190:	ad2cfffc */ 	sw	$t4,-0x4($t1)
/*  f15e194:	00004025 */ 	or	$t0,$zero,$zero
.L0f15e198:
/*  f15e198:	1a40001e */ 	blez	$s2,.L0f15e214
/*  f15e19c:	8fa60208 */ 	lw	$a2,0x208($sp)
/*  f15e1a0:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f15e1a4:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e1a8:	27b00140 */ 	addiu	$s0,$sp,0x140
.L0f15e1ac:
/*  f15e1ac:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*  f15e1b0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15e1b4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f15e1b8:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f15e1bc:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f15e1c0:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f15e1c4:	afa602dc */ 	sw	$a2,0x2dc($sp)
/*  f15e1c8:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f15e1cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f15e1d0:	01ae2823 */ 	subu	$a1,$t5,$t6
/*  f15e1d4:	0fc5d5b0 */ 	jal	texLoadFromGdl
/*  f15e1d8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15e1dc:	8fa602dc */ 	lw	$a2,0x2dc($sp)
/*  f15e1e0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f15e1e4:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f15e1e8:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f15e1ec:	ad260000 */ 	sw	$a2,0x0($t1)
/*  f15e1f0:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f15e1f4:	24c60007 */ 	addiu	$a2,$a2,0x7
/*  f15e1f8:	34cf0007 */ 	ori	$t7,$a2,0x7
/*  f15e1fc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e200:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f15e204:	39e60007 */ 	xori	$a2,$t7,0x7
/*  f15e208:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f15e20c:	1512ffe7 */ 	bne	$t0,$s2,.L0f15e1ac
/*  f15e210:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f15e214:
/*  f15e214:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f15e218:	27b00078 */ 	addiu	$s0,$sp,0x78
/*  f15e21c:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f15e220:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f15e224:	ad860000 */ 	sw	$a2,0x0($t4)
/*  f15e228:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e22c:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f15e230:	00d4c023 */ 	subu	$t8,$a2,$s4
/*  f15e234:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f15e238:	35f9000f */ 	ori	$t9,$t7,0xf
/*  f15e23c:	3b2b000f */ 	xori	$t3,$t9,0xf
/*  f15e240:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f15e244:	ac6b0080 */ 	sw	$t3,0x80($v1)
/*  f15e248:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f15e24c:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f15e250:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e254:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15e258:	3c0e800a */ 	lui	$t6,%hi(g_Rooms)
/*  f15e25c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f15e260:	a46a0002 */ 	sh	$t2,0x2($v1)
/*  f15e264:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f15e268:	8dce4928 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f15e26c:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f15e270:	02802025 */ 	or	$a0,$s4,$zero
/*  f15e274:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f15e278:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f15e27c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f15e280:	51e20009 */ 	beql	$t7,$v0,.L0f15e2a8
/*  f15e284:	8c730014 */ 	lw	$s3,0x14($v1)
/*  f15e288:	0c004b52 */ 	jal	memaRealloc
/*  f15e28c:	00403025 */ 	or	$a2,$v0,$zero
/*  f15e290:	3c19800a */ 	lui	$t9,%hi(g_Rooms)
/*  f15e294:	8f394928 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f15e298:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f15e29c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15e2a0:	032b1821 */ 	addu	$v1,$t9,$t3
/*  f15e2a4:	8c730014 */ 	lw	$s3,0x14($v1)
.L0f15e2a8:
/*  f15e2a8:	3c18800a */ 	lui	$t8,%hi(g_FogEnabled)
/*  f15e2ac:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f15e2b0:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f15e2b4:	26650018 */ 	addiu	$a1,$s3,0x18
/*  f15e2b8:	24a90014 */ 	addiu	$t1,$a1,0x14
/*  f15e2bc:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f15e2c0:	14200026 */ 	bnez	$at,.L0f15e35c
/*  f15e2c4:	3c19800a */ 	lui	$t9,%hi(var800a65e4)
/*  f15e2c8:	90a20000 */ 	lbu	$v0,0x0($a1)
.L0f15e2cc:
/*  f15e2cc:	50400006 */ 	beqzl	$v0,.L0f15e2e8
/*  f15e2d0:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f15e2d4:	504a0018 */ 	beql	$v0,$t2,.L0f15e338
/*  f15e2d8:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f15e2dc:	1000001b */ 	b	.L0f15e34c
/*  f15e2e0:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e2e4:	8ca60008 */ 	lw	$a2,0x8($a1)
.L0f15e2e8:
/*  f15e2e8:	50c00018 */ 	beqzl	$a2,.L0f15e34c
/*  f15e2ec:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e2f0:	1a400015 */ 	blez	$s2,.L0f15e348
/*  f15e2f4:	00004025 */ 	or	$t0,$zero,$zero
/*  f15e2f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f15e2fc:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e300:	00c02025 */ 	or	$a0,$a2,$zero
.L0f15e304:
/*  f15e304:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f15e308:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e30c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15e310:	148c0004 */ 	bne	$a0,$t4,.L0f15e324
/*  f15e314:	02026821 */ 	addu	$t5,$s0,$v0
/*  f15e318:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f15e31c:	1000000a */ 	b	.L0f15e348
/*  f15e320:	acae0008 */ 	sw	$t6,0x8($a1)
.L0f15e324:
/*  f15e324:	1512fff7 */ 	bne	$t0,$s2,.L0f15e304
/*  f15e328:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15e32c:	10000007 */ 	b	.L0f15e34c
/*  f15e330:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e334:	8ca2000c */ 	lw	$v0,0xc($a1)
.L0f15e338:
/*  f15e338:	0047082b */ 	sltu	$at,$v0,$a3
/*  f15e33c:	50200003 */ 	beqzl	$at,.L0f15e34c
/*  f15e340:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e344:	00403825 */ 	or	$a3,$v0,$zero
.L0f15e348:
/*  f15e348:	01202825 */ 	or	$a1,$t1,$zero
.L0f15e34c:
/*  f15e34c:	25290014 */ 	addiu	$t1,$t1,0x14
/*  f15e350:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f15e354:	5020ffdd */ 	beqzl	$at,.L0f15e2cc
/*  f15e358:	90a20000 */ 	lbu	$v0,0x0($a1)
.L0f15e35c:
/*  f15e35c:	8f1865e0 */ 	lw	$t8,%lo(g_FogEnabled)($t8)
/*  f15e360:	13000012 */ 	beqz	$t8,.L0f15e3ac
/*  f15e364:	00000000 */ 	nop
/*  f15e368:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f15e36c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f15e370:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f15e374:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f15e378:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*  f15e37c:	0fc595ca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f15e380:	8d840008 */ 	lw	$a0,0x8($t4)
/*  f15e384:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f15e388:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f15e38c:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e390:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f15e394:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f15e398:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*  f15e39c:	0fc595ca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f15e3a0:	8de4000c */ 	lw	$a0,0xc($t7)
/*  f15e3a4:	10000014 */ 	b	.L0f15e3f8
/*  f15e3a8:	00000000 */ 	nop
.L0f15e3ac:
/*  f15e3ac:	8f3965e4 */ 	lw	$t9,%lo(var800a65e4)($t9)
/*  f15e3b0:	3c0b800a */ 	lui	$t3,%hi(g_Rooms)
/*  f15e3b4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f15e3b8:	1720000f */ 	bnez	$t9,.L0f15e3f8
/*  f15e3bc:	00000000 */ 	nop
/*  f15e3c0:	8d6b4928 */ 	lw	$t3,%lo(g_Rooms)($t3)
/*  f15e3c4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f15e3c8:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f15e3cc:	8dae0014 */ 	lw	$t6,0x14($t5)
/*  f15e3d0:	0fc595ca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f15e3d4:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f15e3d8:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f15e3dc:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f15e3e0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f15e3e4:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f15e3e8:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f15e3ec:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f15e3f0:	0fc595ca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f15e3f4:	8d64000c */ 	lw	$a0,0xc($t3)
.L0f15e3f8:
/*  f15e3f8:	0fc57be7 */ 	jal	bgFindRoomVtxBatches
/*  f15e3fc:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e400:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f15e404:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f15e408:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e40c:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f15e410:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15e414:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f15e418:	946e0000 */ 	lhu	$t6,0x0($v1)
/*  f15e41c:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f15e420:	35d80100 */ 	ori	$t8,$t6,0x100
/*  f15e424:	a4780000 */ 	sh	$t8,0x0($v1)
/*  f15e428:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f15e42c:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f15e430:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f15e434:	946b0000 */ 	lhu	$t3,0x0($v1)
/*  f15e438:	356c0200 */ 	ori	$t4,$t3,0x200
/*  f15e43c:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f15e440:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e444:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f15e448:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f15e44c:	0fc4f0dc */ 	jal	dyntexSetCurrentRoom
/*  f15e450:	af000058 */ 	sw	$zero,0x58($t8)
.L0f15e454:
/*  f15e454:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15e458:
/*  f15e458:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f15e45c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f15e460:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15e464:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f15e468:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f15e46c:	03e00008 */ 	jr	$ra
/*  f15e470:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#else
GLOBAL_ASM(
glabel bgLoadRoom
/*  f1583f0:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f1583f4:	afa402f8 */ 	sw	$a0,0x2f8($sp)
/*  f1583f8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1583fc:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f158400:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f158404:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f158408:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f15840c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f158410:	24841a2c */ 	addiu	$a0,$a0,0x1a2c
/*  f158414:	0fc55704 */ 	jal	bgVerifyLightSums
/*  f158418:	24051ba4 */ 	addiu	$a1,$zero,0x1ba4
/*  f15841c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158420:	3c0e800a */ 	lui	$t6,0x800a
/*  f158424:	5080020e */ 	beqzl	$a0,.NB0f158c60
/*  f158428:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15842c:	8dcee97c */ 	lw	$t6,-0x1684($t6)
/*  f158430:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f158434:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f158438:	008e082a */ 	slt	$at,$a0,$t6
/*  f15843c:	10200207 */ 	beqz	$at,.NB0f158c5c
/*  f158440:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f158444:	3c18800b */ 	lui	$t8,0x800b
/*  f158448:	8f1890a8 */ 	lw	$t8,-0x6f58($t8)
/*  f15844c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f158450:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f158454:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f158458:	030f1821 */ 	addu	$v1,$t8,$t7
/*  f15845c:	846b0002 */ 	lh	$t3,0x2($v1)
/*  f158460:	556001ff */ 	bnezl	$t3,.NB0f158c60
/*  f158464:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f158468:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f15846c:	18400008 */ 	blez	$v0,.NB0f158490
/*  f158470:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158474:	0fc46652 */ 	jal	debug0f11edb0
/*  f158478:	afa202f4 */ 	sw	$v0,0x2f4($sp)
/*  f15847c:	10400007 */ 	beqz	$v0,.NB0f15849c
/*  f158480:	8fac02f4 */ 	lw	$t4,0x2f4($sp)
/*  f158484:	258d0400 */ 	addiu	$t5,$t4,0x400
/*  f158488:	10000004 */ 	beqz	$zero,.NB0f15849c
/*  f15848c:	afad02f4 */ 	sw	$t5,0x2f4($sp)
.NB0f158490:
/*  f158490:	0c004d4e */ 	jal	memaGetLongestFree
/*  f158494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158498:	afa202f4 */ 	sw	$v0,0x2f4($sp)
.NB0f15849c:
/*  f15849c:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f1584a0:	0fc5636f */ 	jal	bgGarbageCollectRooms
/*  f1584a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1584a8:	0c004cc9 */ 	jal	memaAlloc
/*  f1584ac:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f1584b0:	104001ea */ 	beqz	$v0,.NB0f158c5c
/*  f1584b4:	00409825 */ 	or	$s3,$v0,$zero
/*  f1584b8:	0fc4db9c */ 	jal	dyntexSetCurrentRoom
/*  f1584bc:	87a402fa */ 	lh	$a0,0x2fa($sp)
/*  f1584c0:	8fb002f8 */ 	lw	$s0,0x2f8($sp)
/*  f1584c4:	3c11800b */ 	lui	$s1,0x800b
/*  f1584c8:	26319444 */ 	addiu	$s1,$s1,-27580
/*  f1584cc:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f1584d0:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1584d4:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f1584d8:	000e8080 */ 	sll	$s0,$t6,0x2
/*  f1584dc:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f1584e0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1584e4:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f1584e8:	3c04800b */ 	lui	$a0,0x800b
/*  f1584ec:	8c84909c */ 	lw	$a0,-0x6f64($a0)
/*  f1584f0:	03039023 */ 	subu	$s2,$t8,$v1
/*  f1584f4:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f1584f8:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f1584fc:	8fa702f4 */ 	lw	$a3,0x2f4($sp)
/*  f158500:	0241c824 */ 	and	$t9,$s2,$at
/*  f158504:	00645821 */ 	addu	$t3,$v1,$a0
/*  f158508:	3c01f100 */ 	lui	$at,0xf100
/*  f15850c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f158510:	01642823 */ 	subu	$a1,$t3,$a0
/*  f158514:	8d8c24b8 */ 	lw	$t4,0x24b8($t4)
/*  f158518:	00a12821 */ 	addu	$a1,$a1,$at
/*  f15851c:	00f9082a */ 	slt	$at,$a3,$t9
/*  f158520:	03209025 */ 	or	$s2,$t9,$zero
/*  f158524:	10200005 */ 	beqz	$at,.NB0f15853c
/*  f158528:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f15852c:	0fc4db9c */ 	jal	dyntexSetCurrentRoom
/*  f158530:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f158534:	100001ca */ 	beqz	$zero,.NB0f158c60
/*  f158538:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f15853c:
/*  f15853c:	00f26823 */ 	subu	$t5,$a3,$s2
/*  f158540:	01b32021 */ 	addu	$a0,$t5,$s3
/*  f158544:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f158548:	0fc5560b */ 	jal	bgLoadFile
/*  f15854c:	02403025 */ 	or	$a2,$s2,$zero
/*  f158550:	0c0022df */ 	jal	rzipIs1173
/*  f158554:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f158558:	10400009 */ 	beqz	$v0,.NB0f158580
/*  f15855c:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f158560:	264f0020 */ 	addiu	$t7,$s2,0x20
/*  f158564:	01cf082a */ 	slt	$at,$t6,$t7
/*  f158568:	50200006 */ 	beqzl	$at,.NB0f158584
/*  f15856c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f158570:	0fc4db9c */ 	jal	dyntexSetCurrentRoom
/*  f158574:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f158578:	100001b9 */ 	beqz	$zero,.NB0f158c60
/*  f15857c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f158580:
/*  f158580:	8e380000 */ 	lw	$t8,0x0($s1)
.NB0f158584:
/*  f158584:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f158588:	02602825 */ 	or	$a1,$s3,$zero
/*  f15858c:	03101021 */ 	addu	$v0,$t8,$s0
/*  f158590:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f158594:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f158598:	0fc56023 */ 	jal	bgInflate
/*  f15859c:	032b3023 */ 	subu	$a2,$t9,$t3
/*  f1585a0:	3c09800b */ 	lui	$t1,0x800b
/*  f1585a4:	252990a8 */ 	addiu	$t1,$t1,-28504
/*  f1585a8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f1585ac:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f1585b0:	afa202f0 */ 	sw	$v0,0x2f0($sp)
/*  f1585b4:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1585b8:	01886821 */ 	addu	$t5,$t4,$t0
/*  f1585bc:	adb30014 */ 	sw	$s3,0x14($t5)
/*  f1585c0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f1585c4:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f1585c8:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f1585cc:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f1585d0:	5060000b */ 	beqzl	$v1,.NB0f158600
/*  f1585d4:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f1585d8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1585dc:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f1585e0:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f1585e4:	006b6023 */ 	subu	$t4,$v1,$t3
/*  f1585e8:	01936821 */ 	addu	$t5,$t4,$s3
/*  f1585ec:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f1585f0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f1585f4:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f1585f8:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f1585fc:	8e420004 */ 	lw	$v0,0x4($s2)
.NB0f158600:
/*  f158600:	5040000b */ 	beqzl	$v0,.NB0f158630
/*  f158604:	8e420008 */ 	lw	$v0,0x8($s2)
/*  f158608:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15860c:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f158610:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f158614:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f158618:	01936821 */ 	addu	$t5,$t4,$s3
/*  f15861c:	ae4d0004 */ 	sw	$t5,0x4($s2)
/*  f158620:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f158624:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f158628:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f15862c:	8e420008 */ 	lw	$v0,0x8($s2)
.NB0f158630:
/*  f158630:	5040000b */ 	beqzl	$v0,.NB0f158660
/*  f158634:	8e42000c */ 	lw	$v0,0xc($s2)
/*  f158638:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15863c:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f158640:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f158644:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f158648:	01936821 */ 	addu	$t5,$t4,$s3
/*  f15864c:	ae4d0008 */ 	sw	$t5,0x8($s2)
/*  f158650:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f158654:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f158658:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f15865c:	8e42000c */ 	lw	$v0,0xc($s2)
.NB0f158660:
/*  f158660:	5040000b */ 	beqzl	$v0,.NB0f158690
/*  f158664:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f158668:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15866c:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f158670:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f158674:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f158678:	01936821 */ 	addu	$t5,$t4,$s3
/*  f15867c:	ae4d000c */ 	sw	$t5,0xc($s2)
/*  f158680:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f158684:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f158688:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f15868c:	8e420000 */ 	lw	$v0,0x0($s2)
.NB0f158690:
/*  f158690:	26430018 */ 	addiu	$v1,$s2,0x18
/*  f158694:	24650014 */ 	addiu	$a1,$v1,0x14
/*  f158698:	0045082b */ 	sltu	$at,$v0,$a1
/*  f15869c:	14200060 */ 	bnez	$at,.NB0f158820
/*  f1586a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1586a4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1586a8:	90620000 */ 	lbu	$v0,0x0($v1)
.NB0f1586ac:
/*  f1586ac:	50400006 */ 	beqzl	$v0,.NB0f1586c8
/*  f1586b0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1586b4:	50470029 */ 	beql	$v0,$a3,.NB0f15875c
/*  f1586b8:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1586bc:	10000050 */ 	beqz	$zero,.NB0f158800
/*  f1586c0:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1586c4:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f1586c8:
/*  f1586c8:	50400008 */ 	beqzl	$v0,.NB0f1586ec
/*  f1586cc:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f1586d0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1586d4:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f1586d8:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f1586dc:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f1586e0:	01936821 */ 	addu	$t5,$t4,$s3
/*  f1586e4:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f1586e8:	8c620008 */ 	lw	$v0,0x8($v1)
.NB0f1586ec:
/*  f1586ec:	50400008 */ 	beqzl	$v0,.NB0f158710
/*  f1586f0:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f1586f4:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f1586f8:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f1586fc:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f158700:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f158704:	03335821 */ 	addu	$t3,$t9,$s3
/*  f158708:	ac6b0008 */ 	sw	$t3,0x8($v1)
/*  f15870c:	8c62000c */ 	lw	$v0,0xc($v1)
.NB0f158710:
/*  f158710:	50400008 */ 	beqzl	$v0,.NB0f158734
/*  f158714:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f158718:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f15871c:	01906821 */ 	addu	$t5,$t4,$s0
/*  f158720:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f158724:	004e7823 */ 	subu	$t7,$v0,$t6
/*  f158728:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f15872c:	ac78000c */ 	sw	$t8,0xc($v1)
/*  f158730:	8c620010 */ 	lw	$v0,0x10($v1)
.NB0f158734:
/*  f158734:	50400032 */ 	beqzl	$v0,.NB0f158800
/*  f158738:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15873c:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f158740:	03305821 */ 	addu	$t3,$t9,$s0
/*  f158744:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f158748:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f15874c:	01b37021 */ 	addu	$t6,$t5,$s3
/*  f158750:	1000002a */ 	beqz	$zero,.NB0f1587fc
/*  f158754:	ac6e0010 */ 	sw	$t6,0x10($v1)
/*  f158758:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f15875c:
/*  f15875c:	50400008 */ 	beqzl	$v0,.NB0f158780
/*  f158760:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f158764:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f158768:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f15876c:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f158770:	00595823 */ 	subu	$t3,$v0,$t9
/*  f158774:	01736021 */ 	addu	$t4,$t3,$s3
/*  f158778:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f15877c:	8c620008 */ 	lw	$v0,0x8($v1)
.NB0f158780:
/*  f158780:	50400008 */ 	beqzl	$v0,.NB0f1587a4
/*  f158784:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f158788:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f15878c:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f158790:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f158794:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f158798:	0313c821 */ 	addu	$t9,$t8,$s3
/*  f15879c:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f1587a0:	8c62000c */ 	lw	$v0,0xc($v1)
.NB0f1587a4:
/*  f1587a4:	50400008 */ 	beqzl	$v0,.NB0f1587c8
/*  f1587a8:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f1587ac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f1587b0:	01706021 */ 	addu	$t4,$t3,$s0
/*  f1587b4:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f1587b8:	004d7023 */ 	subu	$t6,$v0,$t5
/*  f1587bc:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f1587c0:	ac6f000c */ 	sw	$t7,0xc($v1)
/*  f1587c4:	8c620010 */ 	lw	$v0,0x10($v1)
.NB0f1587c8:
/*  f1587c8:	50400008 */ 	beqzl	$v0,.NB0f1587ec
/*  f1587cc:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f1587d0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1587d4:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f1587d8:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f1587dc:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f1587e0:	01936821 */ 	addu	$t5,$t4,$s3
/*  f1587e4:	ac6d0010 */ 	sw	$t5,0x10($v1)
/*  f1587e8:	8c62000c */ 	lw	$v0,0xc($v1)
.NB0f1587ec:
/*  f1587ec:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1587f0:	50200003 */ 	beqzl	$at,.NB0f158800
/*  f1587f4:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1587f8:	00402025 */ 	or	$a0,$v0,$zero
.NB0f1587fc:
/*  f1587fc:	00a01825 */ 	or	$v1,$a1,$zero
.NB0f158800:
/*  f158800:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f158804:	0085082b */ 	sltu	$at,$a0,$a1
/*  f158808:	5020ffa8 */ 	beqzl	$at,.NB0f1586ac
/*  f15880c:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f158810:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f158814:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f158818:	8df20014 */ 	lw	$s2,0x14($t7)
/*  f15881c:	8e420000 */ 	lw	$v0,0x0($s2)
.NB0f158820:
/*  f158820:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f158824:	2401000c */ 	addiu	$at,$zero,0xc
/*  f158828:	00002825 */ 	or	$a1,$zero,$zero
/*  f15882c:	0302c823 */ 	subu	$t9,$t8,$v0
/*  f158830:	0321001b */ 	divu	$zero,$t9,$at
/*  f158834:	00005812 */ 	mflo	$t3
/*  f158838:	a64b0014 */ 	sh	$t3,0x14($s2)
/*  f15883c:	0fc56093 */ 	jal	roomGetNextGdlInLayer
/*  f158840:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158844:	3c0c800b */ 	lui	$t4,0x800b
/*  f158848:	8d8c90a8 */ 	lw	$t4,-0x6f58($t4)
/*  f15884c:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f158850:	00008825 */ 	or	$s1,$zero,$zero
/*  f158854:	00002825 */ 	or	$a1,$zero,$zero
/*  f158858:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f15885c:	8dd20014 */ 	lw	$s2,0x14($t6)
/*  f158860:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f158864:	8e4f0004 */ 	lw	$t7,0x4($s2)
/*  f158868:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f15886c:	0018c882 */ 	srl	$t9,$t8,0x2
/*  f158870:	a6590016 */ 	sh	$t9,0x16($s2)
/*  f158874:	0fc56093 */ 	jal	roomGetNextGdlInLayer
/*  f158878:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15887c:	10400018 */ 	beqz	$v0,.NB0f1588e0
/*  f158880:	00408025 */ 	or	$s0,$v0,$zero
/*  f158884:	00111080 */ 	sll	$v0,$s1,0x2
/*  f158888:	27ab0208 */ 	addiu	$t3,$sp,0x208
/*  f15888c:	27ac0140 */ 	addiu	$t4,$sp,0x140
/*  f158890:	004c1821 */ 	addu	$v1,$v0,$t4
/*  f158894:	004b9021 */ 	addu	$s2,$v0,$t3
.NB0f158898:
/*  f158898:	ae500000 */ 	sw	$s0,0x0($s2)
/*  f15889c:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f1588a0:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f1588a4:	0fc560d3 */ 	jal	roomFindVerticesForGdl
/*  f1588a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588ac:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f1588b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1588b4:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f1588b8:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f1588bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1588c0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f1588c4:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f1588c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588cc:	0fc56093 */ 	jal	roomGetNextGdlInLayer
/*  f1588d0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1588d4:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f1588d8:	1440ffef */ 	bnez	$v0,.NB0f158898
/*  f1588dc:	00408025 */ 	or	$s0,$v0,$zero
.NB0f1588e0:
/*  f1588e0:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1588e4:	00113880 */ 	sll	$a3,$s1,0x2
/*  f1588e8:	27ad0208 */ 	addiu	$t5,$sp,0x208
/*  f1588ec:	00ed9021 */ 	addu	$s2,$a3,$t5
/*  f1588f0:	026e1021 */ 	addu	$v0,$s3,$t6
/*  f1588f4:	ae420000 */ 	sw	$v0,0x0($s2)
/*  f1588f8:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1588fc:	8fa40208 */ 	lw	$a0,0x208($sp)
/*  f158900:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f158904:	02788021 */ 	addu	$s0,$s3,$t8
/*  f158908:	00441823 */ 	subu	$v1,$v0,$a0
/*  f15890c:	02032823 */ 	subu	$a1,$s0,$v1
/*  f158910:	0fc5c2e5 */ 	jal	texCopyGdls
/*  f158914:	00603025 */ 	or	$a2,$v1,$zero
/*  f158918:	26220001 */ 	addiu	$v0,$s1,0x1
/*  f15891c:	1840000d */ 	blez	$v0,.NB0f158954
/*  f158920:	00004025 */ 	or	$t0,$zero,$zero
/*  f158924:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f158928:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f15892c:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f158930:	02192023 */ 	subu	$a0,$s0,$t9
.NB0f158934:
/*  f158934:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f158938:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15893c:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f158940:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f158944:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f158948:	1502fffa */ 	bne	$t0,$v0,.NB0f158934
/*  f15894c:	ad2cfffc */ 	sw	$t4,-0x4($t1)
/*  f158950:	00004025 */ 	or	$t0,$zero,$zero
.NB0f158954:
/*  f158954:	1a20001f */ 	blez	$s1,.NB0f1589d4
/*  f158958:	8fa60208 */ 	lw	$a2,0x208($sp)
/*  f15895c:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f158960:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f158964:	27b00140 */ 	addiu	$s0,$sp,0x140
.NB0f158968:
/*  f158968:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*  f15896c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f158970:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f158974:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f158978:	01ae2823 */ 	subu	$a1,$t5,$t6
/*  f15897c:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f158980:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f158984:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f158988:	afa602dc */ 	sw	$a2,0x2dc($sp)
/*  f15898c:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f158990:	00003825 */ 	or	$a3,$zero,$zero
/*  f158994:	0fc5c0d8 */ 	jal	texLoadFromGdl
/*  f158998:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15899c:	8fa602dc */ 	lw	$a2,0x2dc($sp)
/*  f1589a0:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f1589a4:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f1589a8:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f1589ac:	ad260000 */ 	sw	$a2,0x0($t1)
/*  f1589b0:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f1589b4:	24c60007 */ 	addiu	$a2,$a2,0x7
/*  f1589b8:	34cf0007 */ 	ori	$t7,$a2,0x7
/*  f1589bc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1589c0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1589c4:	39e60007 */ 	xori	$a2,$t7,0x7
/*  f1589c8:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f1589cc:	1511ffe6 */ 	bne	$t0,$s1,.NB0f158968
/*  f1589d0:	24630004 */ 	addiu	$v1,$v1,0x4
.NB0f1589d4:
/*  f1589d4:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f1589d8:	27b00078 */ 	addiu	$s0,$sp,0x78
/*  f1589dc:	3c0d800b */ 	lui	$t5,0x800b
/*  f1589e0:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f1589e4:	ad860000 */ 	sw	$a2,0x0($t4)
/*  f1589e8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f1589ec:	8dad90a8 */ 	lw	$t5,-0x6f58($t5)
/*  f1589f0:	00d3c023 */ 	subu	$t8,$a2,$s3
/*  f1589f4:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f1589f8:	35f9000f */ 	ori	$t9,$t7,0xf
/*  f1589fc:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f158a00:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f158a04:	3b2b000f */ 	xori	$t3,$t9,0xf
/*  f158a08:	ac6b0080 */ 	sw	$t3,0x80($v1)
/*  f158a0c:	3c0c800b */ 	lui	$t4,0x800b
/*  f158a10:	8d8c90a8 */ 	lw	$t4,-0x6f58($t4)
/*  f158a14:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f158a18:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f158a1c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f158a20:	8c6e0080 */ 	lw	$t6,0x80($v1)
/*  f158a24:	004e082a */ 	slt	$at,$v0,$t6
/*  f158a28:	5020000a */ 	beqzl	$at,.NB0f158a54
/*  f158a2c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f158a30:	0c003074 */ 	jal	crashSetMessage
/*  f158a34:	24841a34 */ 	addiu	$a0,$a0,0x1a34
/*  f158a38:	24180045 */ 	addiu	$t8,$zero,0x45
/*  f158a3c:	a0180000 */ 	sb	$t8,0x0($zero)
/*  f158a40:	3c0f800b */ 	lui	$t7,0x800b
/*  f158a44:	8def90a8 */ 	lw	$t7,-0x6f58($t7)
/*  f158a48:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f158a4c:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f158a50:	240a0001 */ 	addiu	$t2,$zero,0x1
.NB0f158a54:
/*  f158a54:	a46a0002 */ 	sh	$t2,0x2($v1)
/*  f158a58:	3c0b800b */ 	lui	$t3,0x800b
/*  f158a5c:	8d6b90a8 */ 	lw	$t3,-0x6f58($t3)
/*  f158a60:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f158a64:	8fad02f4 */ 	lw	$t5,0x2f4($sp)
/*  f158a68:	02602025 */ 	or	$a0,$s3,$zero
/*  f158a6c:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f158a70:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f158a74:	01a02825 */ 	or	$a1,$t5,$zero
/*  f158a78:	51a20009 */ 	beql	$t5,$v0,.NB0f158aa0
/*  f158a7c:	8c720014 */ 	lw	$s2,0x14($v1)
/*  f158a80:	0c004d69 */ 	jal	memaRealloc
/*  f158a84:	00403025 */ 	or	$a2,$v0,$zero
/*  f158a88:	3c0e800b */ 	lui	$t6,0x800b
/*  f158a8c:	8dce90a8 */ 	lw	$t6,-0x6f58($t6)
/*  f158a90:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f158a94:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f158a98:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f158a9c:	8c720014 */ 	lw	$s2,0x14($v1)
.NB0f158aa0:
/*  f158aa0:	3c0c800b */ 	lui	$t4,0x800b
/*  f158aa4:	3c0d800b */ 	lui	$t5,0x800b
/*  f158aa8:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f158aac:	26450018 */ 	addiu	$a1,$s2,0x18
/*  f158ab0:	24a90014 */ 	addiu	$t1,$a1,0x14
/*  f158ab4:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f158ab8:	14200026 */ 	bnez	$at,.NB0f158b54
/*  f158abc:	3c0e800b */ 	lui	$t6,0x800b
/*  f158ac0:	90a20000 */ 	lbu	$v0,0x0($a1)
.NB0f158ac4:
/*  f158ac4:	50400006 */ 	beqzl	$v0,.NB0f158ae0
/*  f158ac8:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f158acc:	504a0018 */ 	beql	$v0,$t2,.NB0f158b30
/*  f158ad0:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f158ad4:	1000001b */ 	beqz	$zero,.NB0f158b44
/*  f158ad8:	01202825 */ 	or	$a1,$t1,$zero
/*  f158adc:	8ca60008 */ 	lw	$a2,0x8($a1)
.NB0f158ae0:
/*  f158ae0:	50c00018 */ 	beqzl	$a2,.NB0f158b44
/*  f158ae4:	01202825 */ 	or	$a1,$t1,$zero
/*  f158ae8:	1a200015 */ 	blez	$s1,.NB0f158b40
/*  f158aec:	00004025 */ 	or	$t0,$zero,$zero
/*  f158af0:	00001025 */ 	or	$v0,$zero,$zero
/*  f158af4:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f158af8:	00c02025 */ 	or	$a0,$a2,$zero
.NB0f158afc:
/*  f158afc:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f158b00:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f158b04:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f158b08:	148f0004 */ 	bne	$a0,$t7,.NB0f158b1c
/*  f158b0c:	0202c821 */ 	addu	$t9,$s0,$v0
/*  f158b10:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f158b14:	1000000a */ 	beqz	$zero,.NB0f158b40
/*  f158b18:	acab0008 */ 	sw	$t3,0x8($a1)
.NB0f158b1c:
/*  f158b1c:	1511fff7 */ 	bne	$t0,$s1,.NB0f158afc
/*  f158b20:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f158b24:	10000007 */ 	beqz	$zero,.NB0f158b44
/*  f158b28:	01202825 */ 	or	$a1,$t1,$zero
/*  f158b2c:	8ca2000c */ 	lw	$v0,0xc($a1)
.NB0f158b30:
/*  f158b30:	0047082b */ 	sltu	$at,$v0,$a3
/*  f158b34:	50200003 */ 	beqzl	$at,.NB0f158b44
/*  f158b38:	01202825 */ 	or	$a1,$t1,$zero
/*  f158b3c:	00403825 */ 	or	$a3,$v0,$zero
.NB0f158b40:
/*  f158b40:	01202825 */ 	or	$a1,$t1,$zero
.NB0f158b44:
/*  f158b44:	25290014 */ 	addiu	$t1,$t1,0x14
/*  f158b48:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f158b4c:	5020ffdd */ 	beqzl	$at,.NB0f158ac4
/*  f158b50:	90a20000 */ 	lbu	$v0,0x0($a1)
.NB0f158b54:
/*  f158b54:	8d8caea0 */ 	lw	$t4,-0x5160($t4)
/*  f158b58:	11800012 */ 	beqz	$t4,.NB0f158ba4
/*  f158b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b60:	8dad90a8 */ 	lw	$t5,-0x6f58($t5)
/*  f158b64:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f158b68:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f158b6c:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f158b70:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*  f158b74:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158b78:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f158b7c:	3c19800b */ 	lui	$t9,0x800b
/*  f158b80:	8f3990a8 */ 	lw	$t9,-0x6f58($t9)
/*  f158b84:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f158b88:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f158b8c:	032b6021 */ 	addu	$t4,$t9,$t3
/*  f158b90:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*  f158b94:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158b98:	8da4000c */ 	lw	$a0,0xc($t5)
/*  f158b9c:	10000014 */ 	beqz	$zero,.NB0f158bf0
/*  f158ba0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f158ba4:
/*  f158ba4:	8dceaea4 */ 	lw	$t6,-0x515c($t6)
/*  f158ba8:	3c18800b */ 	lui	$t8,0x800b
/*  f158bac:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f158bb0:	15c0000f */ 	bnez	$t6,.NB0f158bf0
/*  f158bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158bb8:	8f1890a8 */ 	lw	$t8,-0x6f58($t8)
/*  f158bbc:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f158bc0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f158bc4:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f158bc8:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158bcc:	8d640008 */ 	lw	$a0,0x8($t3)
/*  f158bd0:	3c0c800b */ 	lui	$t4,0x800b
/*  f158bd4:	8d8c90a8 */ 	lw	$t4,-0x6f58($t4)
/*  f158bd8:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f158bdc:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f158be0:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f158be4:	8dd80014 */ 	lw	$t8,0x14($t6)
/*  f158be8:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158bec:	8f04000c */ 	lw	$a0,0xc($t8)
.NB0f158bf0:
/*  f158bf0:	0fc565e7 */ 	jal	bgFindRoomVtxBatches
/*  f158bf4:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158bf8:	3c0f800b */ 	lui	$t7,0x800b
/*  f158bfc:	8def90a8 */ 	lw	$t7,-0x6f58($t7)
/*  f158c00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f158c04:	3c0d800b */ 	lui	$t5,0x800b
/*  f158c08:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f158c0c:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f158c10:	946b0000 */ 	lhu	$t3,0x0($v1)
/*  f158c14:	3c19800b */ 	lui	$t9,0x800b
/*  f158c18:	356c0100 */ 	ori	$t4,$t3,0x100
/*  f158c1c:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f158c20:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f158c24:	8dad90a8 */ 	lw	$t5,-0x6f58($t5)
/*  f158c28:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f158c2c:	94780000 */ 	lhu	$t8,0x0($v1)
/*  f158c30:	370f0200 */ 	ori	$t7,$t8,0x200
/*  f158c34:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f158c38:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f158c3c:	8f3990a8 */ 	lw	$t9,-0x6f58($t9)
/*  f158c40:	032b6021 */ 	addu	$t4,$t9,$t3
/*  f158c44:	0fc4db9c */ 	jal	dyntexSetCurrentRoom
/*  f158c48:	ad800058 */ 	sw	$zero,0x58($t4)
/*  f158c4c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f158c50:	24841a60 */ 	addiu	$a0,$a0,0x1a60
/*  f158c54:	0fc55704 */ 	jal	bgVerifyLightSums
/*  f158c58:	24051d32 */ 	addiu	$a1,$zero,0x1d32
.NB0f158c5c:
/*  f158c5c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f158c60:
/*  f158c60:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f158c64:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f158c68:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f158c6c:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f158c70:	03e00008 */ 	jr	$ra
/*  f158c74:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#endif

#if VERSION < VERSION_NTSC_1_0
const char var7f1b1a2cnb[] = "bg.c";
const char var7f1b1a34nb[] = "bg.c: roominf[room].allocsize > calculated!";
const char var7f1b1a60nb[] = "bg.c";
#endif
#else

// Mismatch: With hacks removed, the below stores len * 4 into s1
void bgLoadRoom(s32 roomnum)
{
	s32 size; // 2f4
	s32 inflatedlen; // 2f0
	u8 *allocation;
	s32 readlen;
	s32 fileoffset;
	u8 *memaddr;
	u8 *a2; // 2dc
	struct roomblock *block1;
	struct roomblock *block2;
	u8 *v0;
	u8 *gfxblocks[50]; // 208
	u8 *vtxblocks[50]; // 140
	u8 *sp78[50];
	s32 len;
	u32 end1;
	s32 i; // 6c
	u32 end2;
	s32 prev;
	s32 v1;

#if VERSION < VERSION_NTSC_1_0
	bgVerifyLightSums("bg.c", 7076);
#endif

	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return;
	}

	if (g_Rooms[roomnum].loaded240) {
		return;
	}

	// Determine how much memory to allocate.
	// It must be big enough to fit both the inflated and compressed room data.
	size = g_Rooms[roomnum].gfxdatalen;

	if (g_BgPreload) {
		allocation = mempAlloc(size, MEMPOOL_STAGE);
	} else {
		// Try to free enough bytes
		bgGarbageCollectRooms(size, false);

		// Make the allocation
		allocation = memaAlloc(size);
	}

	if (allocation != NULL) {
		dyntexSetCurrentRoom(roomnum);

		// Calculate the file offset and read length
		// of the compressed room data in the BG file
		readlen = ((g_BgRooms[roomnum + 1].unk00 - g_BgRooms[roomnum].unk00) + 0xf) & ~0xf;
		fileoffset = (g_BgPrimaryData + g_BgRooms[roomnum].unk00 - g_BgPrimaryData) + 0xf1000000;
		fileoffset -= var8007fc54;

		if (size < readlen) {
			dyntexSetCurrentRoom(-1);
			return;
		}

		// Load the compressed data to the right side of the allocation
		memaddr = size - readlen + allocation;

		bgLoadFile(memaddr, fileoffset, readlen);

		if (rzipIs1173(memaddr) && readlen + 0x20 > size) {
			dyntexSetCurrentRoom(-1);
			return;
		}

		// Uncompress the data to the left size of the allocation
		inflatedlen = bgInflate(memaddr, allocation, g_BgRooms[roomnum + 1].unk00 - g_BgRooms[roomnum].unk00);

		g_Rooms[roomnum].gfxdata = (struct roomgfxdata *)allocation;

		// Promote offsets to pointers in the gfxdata header
		if (g_Rooms[roomnum].gfxdata->vertices) {
			g_Rooms[roomnum].gfxdata->vertices = (struct gfxvtx *)((u32)g_Rooms[roomnum].gfxdata->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->colours) {
			g_Rooms[roomnum].gfxdata->colours = (u32 *)((u32)g_Rooms[roomnum].gfxdata->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->opablocks) {
			g_Rooms[roomnum].gfxdata->opablocks = (struct roomblock *)((u32)g_Rooms[roomnum].gfxdata->opablocks - g_BgRooms[roomnum].unk00 + (u32)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->xlublocks) {
			g_Rooms[roomnum].gfxdata->xlublocks = (struct roomblock *)((u32)g_Rooms[roomnum].gfxdata->xlublocks - g_BgRooms[roomnum].unk00 + (u32)allocation);
		}

		// Promote offsets to pointers in each gfxdata block
		block1 = g_Rooms[roomnum].gfxdata->blocks;
		end1 = (u32)g_Rooms[roomnum].gfxdata->vertices;

		while ((s32) (block1 + 1) <= end1) {
			switch (block1->type) {
			case ROOMBLOCKTYPE_LEAF:
				if (block1->next != NULL) {
					block1->next = (struct roomblock *)((u32)block1->next - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->gdl != 0) {
					block1->gdl = (Gfx *)((u32)block1->gdl - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->vertices != 0) {
					block1->vertices = (struct gfxvtx *)((u32)block1->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->colours != 0) {
					block1->colours = (u32 *)((u32)block1->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				break;
			case ROOMBLOCKTYPE_PARENT:
				if (block1->next != NULL) {
					block1->next = (struct roomblock *)((u32)block1->next - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->gdl != 0) {
					block1->gdl = (Gfx *)((u32)block1->gdl - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->vertices != 0) {
					block1->vertices = (struct gfxvtx *)((u32)block1->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if (block1->colours != 0) {
					block1->colours = (u32 *)((u32)block1->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
				}
				if ((u32)block1->vertices < end1) {
					end1 = (u32)block1->vertices;
				}
				break;
			}

			block1++;
		}

		// Calculate the number of vertices and colours
		g_Rooms[roomnum].gfxdata->numvertices = ((u32)g_Rooms[roomnum].gfxdata->colours - (u32)g_Rooms[roomnum].gfxdata->vertices) / sizeof(struct gfxvtx);
		g_Rooms[roomnum].gfxdata->numcolours = ((u32)roomGetNextGdlInLayer(roomnum, 0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU) - (u32)g_Rooms[roomnum].gfxdata->colours) / sizeof(u32);

		// Build arrays of pointers to gfx blocks and vtx blocks
		len = 0;
		v0 = (u8 *) roomGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);

		while (v0) {
			gfxblocks[len] = v0;
			vtxblocks[len] = (u8 *) roomFindVerticesForGdl(roomnum, (void *) v0);
			len++;

			v0 = (u8 *) roomGetNextGdlInLayer(roomnum, (void *) v0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);
		}

		gfxblocks[len] = allocation + inflatedlen;

		// Copy gdls to the end of the allocation
		// and build a pointer array to them
		v1 = (gfxblocks[len] - gfxblocks[0]); \
		texCopyGdls((void *) gfxblocks[0], (void *) (allocation + size - v1), v1);

		if (allocation + size - v1);

		for (i = 0; i < len + 1; i++) {
			sp78[i] = gfxblocks[i] + (allocation + size - gfxblocks[len]);
		}

		// Load textures by scanning the gdls.
		// texLoadFromGdl is reading from sp78 and writing new GBI commands
		// to a2, overwriting the GBI commands that were loaded from the
		// BG file. As these are being processed the sp78 pointers are
		// changed to point to the written GBI, because they need to be kept
		// track of temporarily so the room blocks can be pointed to them.
		a2 = gfxblocks[0];

		for (i = 0; i < len; i++) {
			s32 byteswritten = texLoadFromGdl((void *) sp78[i], gfxblocks[i + 1] - gfxblocks[i], (void *) a2, NULL, vtxblocks[i]);
			sp78[i] = a2;
			a2 += byteswritten;
			a2 = (u8 *) ALIGN8((s32) a2);
		}

		sp78[len] = a2;

		// Free the right side of the allocation
		prev = g_Rooms[roomnum].gfxdatalen;
		g_Rooms[roomnum].gfxdatalen = ALIGN16(a2 - allocation + 0x20);

		if (g_Rooms[roomnum].gfxdatalen > prev) {
#if VERSION < VERSION_NTSC_1_0
			crashSetMessage("bg.c: roominf[room].allocsize > calculated!");
			CRASH();
#endif
		}

		g_Rooms[roomnum].loaded240 = 1;

		if (g_Rooms[roomnum].gfxdatalen != size) {
			if (g_BgPreload) {
				mempRealloc(allocation, g_Rooms[roomnum].gfxdatalen, MEMPOOL_STAGE);
			} else {
				memaRealloc((s32) allocation, size, g_Rooms[roomnum].gfxdatalen);
			}
		}

		// Update gdl pointers in the gfxdata so they point to the ones
		// that have been processed by the texture decompressor.
		block2 = g_Rooms[roomnum].gfxdata->blocks; // a1 =
		end2 = (u32) g_Rooms[roomnum].gfxdata->vertices; // a3 =

		while ((s32) (block2 + 1) <= end2) {
			switch (block2->type) {
			case ROOMBLOCKTYPE_LEAF:
				if (block2->gdl) {
					for (i = 0; i < len; i++) {
						Gfx *tmp = block2->gdl;

						if (tmp == (Gfx *) gfxblocks[i]) {
							block2->gdl = (Gfx *) sp78[i];
							break;
						}
					}
				}
				break;
			case ROOMBLOCKTYPE_PARENT:
				if ((u32) block2->unk0c < end2) {
					end2 = (u32) block2->unk0c;
				}
				break;
			}

			block2++;
		}

		// Do some find/replaces in the gdls based on some configuration
		if (g_FogEnabled) {
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->opablocks, 1);
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->xlublocks, 5);
		} else if (var800a65e4 == 0) {
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->opablocks, 6);
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->xlublocks, 7);
		}

		// Create vertex batches - these are used for hit detection
		bgFindRoomVtxBatches(roomnum);

		g_Rooms[roomnum].flags |= ROOMFLAG_DIRTY;
		g_Rooms[roomnum].flags |= ROOMFLAG_0200;

		g_Rooms[roomnum].colours = NULL;

		dyntexSetCurrentRoom(-1);
	}

#if VERSION < VERSION_NTSC_1_0
	bgVerifyLightSums("bg.c", 7474);
#endif
}
#endif

const char var7f1b7420[] = "Checking Convex Room %d";
const char var7f1b7438[] = " Portal %d %s%s%.1f < %.1f";
const char var7f1b7454[] = "";
const char var7f1b7458[] = "";
const char var7f1b745c[] = " Convex Room Failed (1)";
const char var7f1b7474[] = " Portal %d %s%s%.1f > %.1f";
const char var7f1b7490[] = "";
const char var7f1b7494[] = "";
const char var7f1b7498[] = " Convex Room Failed (0)";
const char var7f1b74b0[] = "Checking Concave Room %d";
const char var7f1b74cc[] = " Checking Portal %d";
const char var7f1b74e0[] = "Reject P:%d (%s%s%.1f %.1f n3=%.1f)";
const char var7f1b7504[] = "";
const char var7f1b7508[] = "";
const char var7f1b750c[] = "Reject P:%d (%s%s%.1f %.1f n4=%.1f)";
const char var7f1b7530[] = "";
const char var7f1b7534[] = "";
const char var7f1b7538[] = " Full %d%s%s %.1f %.1f (%.1f %.1f)";
const char var7f1b755c[] = "";
const char var7f1b7560[] = "";
const char var7f1b7564[] = " Failed 2 - Crossed portal %d";
const char var7f1b7584[] = " Failed 1 - Crossed portal %d";
const char var7f1b75a4[] = " Passed";

void bgUnloadRoom(s32 roomnum)
{
	u32 size;

	if (g_BgPreload) {
		return;
	}

	if (g_Rooms[roomnum].vtxbatches) {
		size = ((g_Rooms[roomnum].numvtxbatches) * sizeof(struct vtxbatch) + 0xf) & ~0xf;
		memaFree(g_Rooms[roomnum].vtxbatches, size);
		g_Rooms[roomnum].vtxbatches = NULL;
	}

	if (g_Rooms[roomnum].gfxdatalen > 0) {
		size = g_Rooms[roomnum].gfxdatalen;
		memaFree(g_Rooms[roomnum].gfxdata, size);
		g_Rooms[roomnum].gfxdata = NULL;
	}

	g_Rooms[roomnum].loaded240 = 0;
}

void bgUnloadAllRooms(void)
{
	s32 i;

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (g_Rooms[i].loaded240) {
			bgUnloadRoom(i);
		}
	}
}

/**
 * Find rooms which were recently visible and not yet unloaded, and unload them
 * until the given bytesneeded amount is available in mema.
 *
 * Rooms are unloaded in order of least recently visible.
 *
 * If there's still not enough space after 30 unloads and the desparate argument
 * is true, do a final iteration through all the rooms and free everything
 * that's not visible.
 */
void bgGarbageCollectRooms(s32 bytesneeded, bool desparate)
{
	s32 bytesfree = memaGetLongestFree();
	s32 oldestroom;
	s32 oldesttimer;
	s32 count = 0;
	s32 i;

	while (bytesfree < bytesneeded) {
		oldestroom = 0;
		oldesttimer = 0;

		for (i = 1; i < g_Vars.roomcount; i++) {
			if (g_Rooms[i].loaded240 > oldesttimer) {
				oldestroom = i;
				oldesttimer = g_Rooms[i].loaded240;
			}
		}

		if (oldestroom != 0) {
			bgUnloadRoom(oldestroom);
			memaDefrag();
		}

		bytesfree = memaGetLongestFree();
		count++;

		if (count == 30) {
			if (desparate == true) {
				for (i = 1; i < g_Vars.roomcount; i++) {
#if VERSION >= VERSION_NTSC_1_0
					if (g_Rooms[i].loaded240 > 8)
#else
					if (g_Rooms[i].loaded240)
#endif
					{
						bgUnloadRoom(i);
						memaDefrag();

						if (memaGetLongestFree() >= bytesneeded) {
							return;
						}
					}
				}
			}

			break;
		}
	}
}

/**
 * Increase the loaded240 timers for rooms which are no longer visible.
 * If any rooms have reached the timer limit then unload them, but don't unload
 * more than 2 rooms per frame.
 */
void bgTickRooms(void)
{
	s32 numunloaded = 0;
	s32 i;

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (g_Rooms[i].loaded240) {
#if VERSION >= VERSION_NTSC_1_0
			g_Rooms[i].loaded240++;
#else
			g_Rooms[i].loaded240 += g_Vars.lvupdate240;
#endif

			if (g_Rooms[i].loaded240 >= g_BgUnloadDelay240) {
				g_Rooms[i].loaded240 = g_BgUnloadDelay240;
			}

			if (g_Rooms[i].flags & ROOMFLAG_ONSCREEN) {
				g_Rooms[i].loaded240 = 1;
			}

			if (numunloaded < 2 && g_Rooms[i].loaded240 == g_BgUnloadDelay240_2) {
				bgUnloadRoom(i);
#if VERSION >= VERSION_NTSC_1_0
				memaDefrag();
#endif
				numunloaded++;
			}
		}
	}
}

Gfx *bgRenderRoomPass(Gfx *gdl, s32 roomnum, struct roomblock *block, bool arg3)
{
	u32 v0;

	if (block == NULL) {
		return gdl;
	}

	switch (block->type) {
	case ROOMBLOCKTYPE_LEAF:
		if (g_Rooms[roomnum].flags & ROOMFLAG_HASDYNTEX) {
			dyntexTickRoom(roomnum, block->vertices);
		}

		gSPSegment(gdl++, SPSEGMENT_BG_VTX, OS_PHYSICAL_TO_K0(block->vertices));

		roomHighlight(roomnum);

		v0 = (u32)g_Rooms[roomnum].colours;

		if (v0 != NULL) {
			s32 addr = ALIGN8((u32)&g_Rooms[roomnum].gfxdata->vertices[g_Rooms[roomnum].gfxdata->numvertices]);
			v0 += (((s32)block->colours - addr) >> 2) * 4;
		} else {
			v0 = (u32)block->colours;
		}

		gSPSegment(gdl++, SPSEGMENT_BG_COL, OS_PHYSICAL_TO_K0(v0));

		gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(block->gdl));

		if (arg3) {
			gdl = bgRenderRoomPass(gdl, roomnum, block->next, true);
		}
		break;
	case ROOMBLOCKTYPE_PARENT:
		if (block->child != NULL) {
			struct roomblock *sp58;
			struct roomblock *sp54;
			struct coord *coord;
			f32 sum;
			f32 sp40[3];
			f32 sp34[3];
			u32 stack;

			sp58 = block->child;
			sp54 = sp58->next;
			coord = block->unk0c;

			sp40[0] = coord[1].f[0];
			sp40[1] = coord[1].f[1];
			sp40[2] = coord[1].f[2];
			sp34[0] = coord[0].f[0] - g_Vars.currentplayer->cam_pos.f[0];
			sp34[1] = coord[0].f[1] - g_Vars.currentplayer->cam_pos.f[1];
			sp34[2] = coord[0].f[2] - g_Vars.currentplayer->cam_pos.f[2];

			sum = sp40[0] * sp34[0] + sp40[1] * sp34[1] + sp40[2] * sp34[2];

			if (sum < 0.0f) {
				gdl = bgRenderRoomPass(gdl, roomnum, sp58, false);
				gdl = bgRenderRoomPass(gdl, roomnum, sp54, false);
			} else {
				gdl = bgRenderRoomPass(gdl, roomnum, sp54, false);
				gdl = bgRenderRoomPass(gdl, roomnum, sp58, false);
			}

			if (arg3) {
				gdl = bgRenderRoomPass(gdl, roomnum, block->next, true);
			}
		}
		break;
	}

	return gdl;
}

/**
 * Render the opaque layer of the room.
 */
Gfx *bgRenderRoomOpaque(Gfx *gdl, s32 roomnum)
{
	if (g_Rooms[roomnum].loaded240 == 0) {
		return gdl;
	}

	gdl = roomPushMtx(gdl, roomnum);

	gdl = lightsSetForRoom(gdl, roomnum);
	gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->opablocks, true);
	gdl = lightsSetDefault(gdl);

	g_Rooms[roomnum].loaded240 = 1;

	return gdl;
}

/**
 * Render the transparency layer of the room.
 */
Gfx *bgRenderRoomXlu(Gfx *gdl, s32 roomnum)
{
	u32 stack;

	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return gdl;
	}

	if (g_Rooms[roomnum].loaded240) {
		if (g_Rooms[roomnum].gfxdata->xlublocks == NULL) {
			return gdl;
		}

		roomHighlight(roomnum);

		if (g_Rooms[roomnum].gfxdata);
		if (g_Rooms[roomnum].gfxdata);

		gdl = roomPushMtx(gdl, roomnum);
		gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->xlublocks, true);

		g_Rooms[roomnum].loaded240 = 1;
	} else {
		bgLoadRoom(roomnum);
	}

	return gdl;
}

s32 bgPopulateVtxBatchType(s32 roomnum, struct vtxbatch *batches, Gfx *gdl, s32 batchindex, struct gfxvtx *vertices, s32 type)
{
	s32 i;
	s32 j;
	s32 numvertices;
	struct gfxvtx *batchvertices;

	for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
		if (gdl[i].dma.cmd == G_VTX) {
			batches[batchindex].gdl = gdl;
			batches[batchindex].gbicmdindex = i;
			batches[batchindex].type = type;

			for (j = 0; j < 3; j++) {
				batches[batchindex].bbmin.f[j] = 32767.0f;
				batches[batchindex].bbmax.f[j] = -32768.0f;
			}

			numvertices = (((u32)gdl[i].bytes[1] >> 4) & 0xf) + 1;
			batchvertices = (struct gfxvtx *)((u32)vertices + (gdl[i].words.w1 & 0xffffff));

			for (j = 0; j < numvertices; j++) {
				f32 x = batchvertices[j].x;
				f32 y = batchvertices[j].y;
				f32 z = batchvertices[j].z;

				if (x < batches[batchindex].bbmin.x) {
					batches[batchindex].bbmin.x = x;
				}

				if (y < batches[batchindex].bbmin.y) {
					batches[batchindex].bbmin.y = y;
				}

				if (z < batches[batchindex].bbmin.z) {
					batches[batchindex].bbmin.z = z;
				}

				if (x > batches[batchindex].bbmax.x) {
					batches[batchindex].bbmax.x = x;
				}

				if (y > batches[batchindex].bbmax.y) {
					batches[batchindex].bbmax.y = y;
				}

				if (z > batches[batchindex].bbmax.z) {
					batches[batchindex].bbmax.z = z;
				}
			}

			if (batches[batchindex].bbmin.x == batches[batchindex].bbmax.x) {
				batches[batchindex].bbmax.x++;
			}

			if (batches[batchindex].bbmin.y == batches[batchindex].bbmax.y) {
				batches[batchindex].bbmax.y++;
			}

			if (batches[batchindex].bbmin.z == batches[batchindex].bbmax.z) {
				batches[batchindex].bbmax.z++;
			}

			batches[batchindex].bbmin.x += g_BgRooms[roomnum].pos.x;
			batches[batchindex].bbmin.y += g_BgRooms[roomnum].pos.y;
			batches[batchindex].bbmin.z += g_BgRooms[roomnum].pos.z;

			batches[batchindex].bbmax.x += g_BgRooms[roomnum].pos.x;
			batches[batchindex].bbmax.y += g_BgRooms[roomnum].pos.y;
			batches[batchindex].bbmax.z += g_BgRooms[roomnum].pos.z;

			batchindex++;
		}
	}

	return batchindex;
}

void bgFindRoomVtxBatches(s32 roomnum)
{
	s32 i;
	s32 batchindex = 0;
	s32 xlucount;
	Gfx *gdl;
	struct vtxbatch *batches;

	if (g_Rooms[roomnum].vtxbatches == NULL) {
		gdl = roomGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA);

		if (gdl != NULL) {
			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gDPSetVerticeArray
					if (gdl[i].dma.cmd == G_VTX) {
						batchindex++;
					}
				}

				gdl = roomGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_OPA);
			}

			xlucount = 0;

			gdl = roomGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_XLU);

			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gDPSetVerticeArray
					if (gdl[i].dma.cmd == G_VTX) {
						xlucount++;
					}
				}

				gdl = roomGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_XLU);
			}

			batchindex += xlucount;

			batches = memaAlloc((batchindex * sizeof(struct vtxbatch) + 0xf) & ~0xf);

			if (batches != NULL) {
				gdl = roomGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA);
				batchindex = 0;

				g_Rooms[roomnum].vtxbatches = batches;

				while (gdl) {
					struct gfxvtx *vertices = roomFindVerticesForGdl(roomnum, gdl);
					batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_OPA);
					gdl = roomGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_OPA);
				}

				if (xlucount) {
					gdl = roomGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_XLU);

					while (gdl) {
						struct gfxvtx *vertices = roomFindVerticesForGdl(roomnum, gdl);
						batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_XLU);
						gdl = roomGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_XLU);
					}
				}

				g_Rooms[roomnum].numvtxbatches = (s16)batchindex;
			}
		}
	}
}

bool func0f15f20c(struct coord *arg0, struct coord *arg1, s32 *arg2, s32 *arg3)
{
	struct coord sp24;
	struct coord sp18;

	sp24.x = arg2[0];
	sp24.y = arg2[1];
	sp24.z = arg2[2];

	sp18.x = arg3[0];
	sp18.y = arg3[1];
	sp18.z = arg3[2];

	return bgTestLineIntersectsBbox(arg0, arg1, &sp24, &sp18);
}

bool bgTestLineIntersectsBbox(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3)
{
	u32 stack[4];
	f32 f0;
	f32 f0_2;
	f32 f2;
	f32 f2_2;
	f32 f6;
	f32 f10;
	f32 sp34;
	f32 sp30;
	f32 f16;
	f32 f18;
	f32 f18_2;
	f32 sp20;
	f32 f12;
	f32 f12_2;
	f32 f14;
	f32 f14_2;

	// x
	f18 = arg1->x;
	f16 = arg3->x - arg0->x;
	f14 = arg2->x - arg0->x;

	if (f18 < 0.0f) {
		f18 = -f18;
		f14 = -f14;
		f16 = -f16;
	}

	if (f14 < 0.0f && f16 < 0.0f) {
		return false;
	}

	if (f16 < f14) {
		f32 tmp = f14;
		f14 = f16;
		f16 = tmp;
	}

	// y
	f12 = arg1->y;
	f2 = arg3->y - arg0->y;
	f0 = arg2->y - arg0->y;

	if (f12 < 0.0f) {
		f12 = -f12;
		f0 = -f0;
		f2 = -f2;
	}

	if (f0 < 0.0f && f2 < 0.0f) {
		return false;
	}

	if (f2 < f0) {
		sp20 = f0;
		f0 = f2;
		f2 = sp20;
	}

	f6 = f14 * f12;
	f10 = f0 * f18;

	if (f10 < f6) {
		if (f2 * f18 < f6) {
			return false;
		}

		sp34 = f14;
		sp30 = f18;
	} else {
		if (f16 * f12 < f10) {
			return false;
		}

		sp34 = f0;
		sp30 = f12;
	}

	if (f16 * f12 < f2 * f18) {
		f0_2 = f16;
		f14_2 = f18;
	} else {
		f0_2 = f2;
		f14_2 = f12;
	}

	// z
	f2_2 = arg1->z;
	f12_2 = arg3->z - arg0->z;
	f18_2 = arg2->z - arg0->z;

	if (f2_2 < 0.0f) {
		f2_2 = -f2_2;
		f18_2 = -f18_2;
		f12_2 = -f12_2;
	}

	if (f18_2 < 0.0f && f12_2 < 0.0f) {
		return false;
	}

	if (f12_2 < f18_2) {
		f32 tmp = f18_2;
		f18_2 = f12_2;
		f12_2 = tmp;
	}

	if (sp34 * f2_2 < f18_2 * sp30) {
		if (f0_2 * f2_2 < f18_2 * f14_2) {
			return false;
		}
	} else {
		if (f12_2 * sp30 < sp34 * f2_2) {
			return false;
		}
	}

	return true;
}

bool bgTestHitOnObj(struct coord *arg0, struct coord *arg1, struct coord *arg2, Gfx *gdl,
		Gfx *gdl2, struct gfxvtx *vertices, struct hitthing *hitthing)
{
	s16 stack;
	s16 triref;
	s32 trisremaining;
	bool intersectsbbox;
	f32 *ptr;
	f32 tmp;
	f32 sqdist;
	bool hit = false;
	struct coord *point1;
	struct coord *point2;
	struct coord *point3;
	struct gfxvtx *vtx;
	Gfx *imggdl = NULL;
	s32 texturenum;
	f32 lowestsqdist = MAXFLOAT;
	s32 offset;
	s32 numvertices;
	Gfx *tri4gdl;
	s32 count;
	struct coord min;
	struct coord max;
	struct coord sp8c;
	struct coord sp80;
	s32 points[3];

	while (true) {
		if (gdl->dma.cmd == G_ENDDL) {
			imggdl = NULL;

			if (gdl2 != NULL) {
				gdl = gdl2;
				gdl2 = NULL;
				continue;
			}
			break;
		} else if (gdl->dma.cmd == G_VTX) {
			ptr = var800a6470;
			count = gdl->bytes[1] & 0xf;
			offset = (gdl->words.w1 & 0xffffff);
			numvertices = (((u32)gdl->bytes[1] >> 4) & 0xf) + 1;
			vtx = (struct gfxvtx *)((u32)vertices + offset);
			vtx -= count;

			ptr[0] = vtx->x;
			ptr[1] = vtx->y;
			ptr[2] = vtx->z;

			min.x = ptr[0];
			max.x = ptr[0];
			min.y = ptr[1];
			max.y = ptr[1];
			min.z = ptr[2];
			max.z = ptr[2];

			ptr += 3;
			vtx++;
			numvertices--;

			while (numvertices > 0) {
				ptr[0] = vtx->x;
				ptr[1] = vtx->y;
				ptr[2] = vtx->z;

				if (ptr[0] < min.x) {
					min.x = ptr[0];
				}

				if (ptr[1] < min.y) {
					min.y = ptr[1];
				}

				if (ptr[2] < min.z) {
					min.z = ptr[2];
				}

				if (ptr[0] > max.x) {
					max.x = ptr[0];
				}

				if (ptr[1] > max.y) {
					max.y = ptr[1];
				}

				if (ptr[2] > max.z) {
					max.z = ptr[2];
				}

				vtx++;
				numvertices--;
				ptr += 3;
			}

			intersectsbbox = true;

			if (arg0->x < min.x) {
				if (arg1->x < min.x) {
					intersectsbbox = false;
				}
			} else if (arg0->x > max.x) {
				if (arg1->x > max.x) {
					intersectsbbox = false;
				}
			}

			if (arg0->y < min.y) {
				if (arg1->y < min.y) {
					intersectsbbox = false;
				}
			} else if (arg0->y > max.y) {
				if (arg1->y > max.y) {
					intersectsbbox = false;
				}
			}

			if (arg0->z < min.z) {
				if (arg1->z < min.z) {
					intersectsbbox = false;
				}
			} else if (arg0->z > max.z) {
				if (arg1->z > max.z) {
					intersectsbbox = false;
				}
			}

			if (intersectsbbox) {
				intersectsbbox = bgTestLineIntersectsBbox(arg0, arg2, &min, &max);
			}
		} else if (gdl->dma.cmd == (s8)G_SETTIMG) {
			imggdl = gdl;
		} else {
			if (!intersectsbbox) {
				gdl++;
				continue;
			}

			if (gdl->dma.cmd != G_TRI1 && gdl->dma.cmd != G_TRI4) {
				gdl++;
				continue;
			}

			if (gdl->dma.cmd == G_TRI1) {
				trisremaining = 0;
				triref = 0;
				points[0] = gdl->tri.tri.v[0] / 10;
				points[1] = gdl->tri.tri.v[1] / 10;
				points[2] = gdl->tri.tri.v[2] / 10;
			} else if (gdl->dma.cmd == G_TRI4) {
				tri4gdl = gdl;
				trisremaining = 3;
				triref = 1;
				points[0] = gdl->tri4.x1;
				points[1] = gdl->tri4.y1;
				points[2] = gdl->tri4.z1;
			}

			do {
				if (points[0] == 0 && points[1] == 0 && points[2] == 0) {
					break;
				}

				point1 = (struct coord *) (var800a6470 + points[0] * 3);
				point2 = (struct coord *) (var800a6470 + points[1] * 3);
				point3 = (struct coord *) (var800a6470 + points[2] * 3);

				min.x = point1->x;
				max.x = point1->x;

				if (point2->x < min.x) {
					min.x = point2->x;
				}

				if (point2->x > max.x) {
					max.x = point2->x;
				}

				if (point3->x < min.x) {
					min.x = point3->x;
				}

				if (point3->x > max.x) {
					max.x = point3->x;
				}

				if (!(arg0->x < min.x && arg1->x < min.x) && !(arg0->x > max.x && arg1->x > max.x)) {
					min.z = point1->z;
					max.z = point1->z;

					if (point2->z < min.z) {
						min.z = point2->z;
					}

					if (point2->z > max.z) {
						max.z = point2->z;
					}

					if (point3->z < min.z) {
						min.z = point3->z;
					}

					if (point3->z > max.z) {
						max.z = point3->z;
					}

					if (!(arg0->z < min.z && arg1->z < min.z) && !(arg0->z > max.z && arg1->z > max.z)) {
						min.y = point1->y;
						max.y = point1->y;

						if (point2->y < min.y) {
							min.y = point2->y;
						}

						if (point2->y > max.y) {
							max.y = point2->y;
						}

						if (point3->y < min.y) {
							min.y = point3->y;
						}

						if (point3->y > max.y) {
							max.y = point3->y;
						}

						if (!(arg0->y < min.y && arg1->y < min.y) && !(arg0->y > max.y && arg1->y > max.y)) {
							if (bgTestLineIntersectsBbox(arg0, arg2, &min, &max)
									&& func0002f560(point1, point2, point3, 0, arg0, arg1, arg2, &sp8c, &sp80)) {
								tmp = sp8c.x - arg0->x;
								sqdist = tmp * tmp;

								tmp = sp8c.y - arg0->y;
								sqdist += tmp * tmp;

								tmp = sp8c.z - arg0->z;
								sqdist += tmp * tmp;

								if (sqdist < lowestsqdist) {
									hit = true;

									if (imggdl == NULL
											|| (imggdl->words.w1 & 0x0f000000) == 0x0f000000
											|| (imggdl->words.w1 & 0x05000000) == 0x05000000) {
										texturenum = -1;
									} else {
										s32 tmp = PHYS_TO_K0(imggdl->words.w1 - 8);
										texturenum = *(s16 *) tmp;
									}

									lowestsqdist = sqdist;

									hitthing->unk00.x = sp8c.x;
									hitthing->unk00.y = sp8c.y;
									hitthing->unk00.z = sp8c.z;
									hitthing->unk0c.x = sp80.x;
									hitthing->unk0c.y = sp80.y;
									hitthing->unk0c.z = sp80.z;
									hitthing->unk18 = &vtx[points[0]];
									hitthing->unk1c = &vtx[points[1]];
									hitthing->unk20 = &vtx[points[2]];
									hitthing->texturenum = texturenum;
									hitthing->tricmd = gdl;
									hitthing->unk28 = triref;
								}
							}
						}
					}
				}

				trisremaining--;

				if (trisremaining == 2) {
					points[0] = tri4gdl->tri4.x2;
					points[1] = tri4gdl->tri4.y2;
					points[2] = tri4gdl->tri4.z2;
					triref = 2;
				} else if (trisremaining == 1) {
					points[0] = tri4gdl->tri4.x3;
					points[1] = tri4gdl->tri4.y3;
					points[2] = tri4gdl->tri4.z3;
					triref = 3;
				} else if (trisremaining == 0) {
					points[0] = tri4gdl->tri4.x4;
					points[1] = tri4gdl->tri4.y4;
					points[2] = tri4gdl->tri4.z4;
					triref = 1;
				}
			} while (trisremaining >= 0);
		}

		gdl++;
	}

	return hit;
}

bool bgTestHitOnChr(struct model *model, struct coord *arg1, struct coord *arg2, struct coord *arg3,
		Gfx *gdl, Gfx *gdl2, struct gfxvtx *vertices, f32 *sqdistptr, struct hitthing *hitthing)
{
	s16 triref;
	s32 i;
	bool intersectsbbox;
	s32 count;
	s32 spdc;
	s32 spd8;
	s32 numvertices;
	f32 *ptr;
	bool hit;
	f32 tmp;
	f32 sqdist;
	struct gfxvtx *vtx;
	struct coord *point1;
	struct coord *point2;
	struct coord *point3;
	u32 word;
	Gfx *tri4gdl;
	Mtxf *mtx;
	struct coord min;
	struct coord max;
	struct coord sp84;
	struct coord sp78;
	s32 points[3];

	spdc = 16;
	spd8 = 0;
	hit = false;

	while (true) {
		if (gdl->dma.cmd == G_ENDDL) {
			if (gdl2 != NULL) {
				gdl = gdl2;
				gdl2 = NULL;
				continue;
			}
			break;
		} else if (gdl->dma.cmd == G_MTX) {
			word = gdl->words.w1 & 0xffffff;
			i = word / sizeof(Mtxf);
			mtx = &model->matrices[i];
		} else if (gdl->dma.cmd == G_VTX) {
			count = (gdl->bytes[1] & 0xf);
			word = gdl->words.w1 & 0xffffff;
			numvertices = ((u32)gdl->bytes[1] >> 4) + 1;
			vtx = (struct gfxvtx *)((u32)vertices + word);

			if (count < spdc) {
				spdc = count;
			}

			if (numvertices + count > spd8) {
				spd8 = numvertices + count;
			}

			ptr = &var800a6470[count * 3];

			while (numvertices > 0) {
				if (1);

				ptr[0] = vtx->x;
				ptr[1] = vtx->y;
				ptr[2] = vtx->z;

				mtx4TransformVecInPlace(mtx, (struct coord *) ptr);

				numvertices--;
				ptr += 3;
				vtx++;
			}

			ptr = &var800a6470[spdc];

			min.x = ptr[0];
			max.x = ptr[0];
			min.y = ptr[1];
			max.y = ptr[1];
			min.z = ptr[2];
			max.z = ptr[2];

			ptr += 3;

			for (i = spdc; i < spd8; i++) {
				if (ptr[0] < min.x) {
					min.x = ptr[0];
				}

				if (ptr[1] < min.y) {
					min.y = ptr[1];
				}

				if (ptr[2] < min.z) {
					min.z = ptr[2];
				}

				if (ptr[0] > max.x) {
					max.x = ptr[0];
				}

				if (ptr[1] > max.y) {
					max.y = ptr[1];
				}

				if (ptr[2] > max.z) {
					max.z = ptr[2];
				}

				ptr += 3;
			}

			if ((arg1->x < min.x && arg2->x < min.x)
					|| (arg1->x > max.x && arg2->x > max.x)
					|| (arg1->y < min.y && arg2->y < min.y)
					|| (arg1->y > max.y && arg2->y > max.y)
					|| (arg1->z < min.z && arg2->z < min.z)
					|| (arg1->z > max.z && arg2->z > max.z)) {
				intersectsbbox = false;
			} else {
				intersectsbbox = bgTestLineIntersectsBbox(arg1, arg3, &min, &max);
			}
		} else {
			if (!intersectsbbox) {
				gdl++;
				continue;
			}

			if ((gdl->dma.cmd != G_TRI1 && gdl->dma.cmd != G_TRI4)) {
				gdl++;
				continue;
			}

			if (gdl->dma.cmd == G_TRI1) {
				i = 0;
				triref = 0;
				points[0] = gdl->tri.tri.v[0] / 10;
				points[1] = gdl->tri.tri.v[1] / 10;
				points[2] = gdl->tri.tri.v[2] / 10;
			} else if (gdl->dma.cmd == G_TRI4) {
				tri4gdl = gdl;
				i = 3;
				triref = 1;
				points[0] = gdl->tri4.x1;
				points[1] = gdl->tri4.y1;
				points[2] = gdl->tri4.z1;
			}

			do {
				if (points[0] == 0 && points[1] == 0 && points[2] == 0) {
					break;
				}

				point1 = (struct coord *) (var800a6470 + points[0] * 3);
				point2 = (struct coord *) (var800a6470 + points[1] * 3);
				point3 = (struct coord *) (var800a6470 + points[2] * 3);

				min.x = point1->x;
				max.x = point1->x;

				if (point2->x < min.x) {
					min.x = point2->x;
				}

				if (point2->x > max.x) {
					max.x = point2->x;
				}

				if (point3->x < min.x) {
					min.x = point3->x;
				}

				if (point3->x > max.x) {
					max.x = point3->x;
				}

				if (!(arg1->x < min.x && arg2->x < min.x) && !(arg1->x > max.x && arg2->x > max.x)) {
					min.z = point1->z;
					max.z = point1->z;

					if (point2->z < min.z) {
						min.z = point2->z;
					}

					if (point2->z > max.z) {
						max.z = point2->z;
					}

					if (point3->z < min.z) {
						min.z = point3->z;
					}

					if (point3->z > max.z) {
						max.z = point3->z;
					}

					if (!(arg1->z < min.z && arg2->z < min.z) && !(arg1->z > max.z && arg2->z > max.z)) {
						min.y = point1->y;
						max.y = point1->y;

						if (point2->y < min.y) {
							min.y = point2->y;
						}

						if (point2->y > max.y) {
							max.y = point2->y;
						}

						if (point3->y < min.y) {
							min.y = point3->y;
						}

						if (point3->y > max.y) {
							max.y = point3->y;
						}

						if (!(arg1->y < min.y && arg2->y < min.y) && !(arg1->y > max.y && arg2->y > max.y)) {
							if (bgTestLineIntersectsBbox(arg1, arg3, &min, &max)
									&& func0002f560(point1, point2, point3, 0, arg1, arg2, arg3, &sp84, &sp78)) {
								tmp = sp84.x - arg1->x;
								sqdist = tmp * tmp;

								tmp = sp84.y - arg1->y;
								sqdist += tmp * tmp;

								tmp = sp84.z - arg1->z;
								sqdist += tmp * tmp;

								if (sqdist < *sqdistptr) {
									hit = true;

									*sqdistptr = sqdist;

									hitthing->unk00.x = sp84.x;
									hitthing->unk00.y = sp84.y;
									hitthing->unk00.z = sp84.z;
									hitthing->unk0c.x = sp78.x;
									hitthing->unk0c.y = sp78.y;
									hitthing->unk0c.z = sp78.z;
									hitthing->unk18 = &vtx[points[0]];
									hitthing->unk1c = &vtx[points[1]];
									hitthing->unk20 = &vtx[points[2]];
									hitthing->texturenum = -1;
									hitthing->tricmd = gdl;
									hitthing->unk28 = triref;
								}
							}
						}
					}
				}

				i--;

				if (i == 2) {
					points[0] = tri4gdl->tri4.x2;
					points[1] = tri4gdl->tri4.y2;
					points[2] = tri4gdl->tri4.z2;
					triref = 2;
				} else if (i == 1) {
					points[0] = tri4gdl->tri4.x3;
					points[1] = tri4gdl->tri4.y3;
					points[2] = tri4gdl->tri4.z3;
					triref = 3;
				} else if (i == 0) {
					points[0] = tri4gdl->tri4.x4;
					points[1] = tri4gdl->tri4.y4;
					points[2] = tri4gdl->tri4.z4;
					triref = 1;
				}
			} while (i >= 0);
		}

		gdl++;
	}

	return hit;
}

bool bgTestHitInVtxBatch(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct vtxbatch *batch, s32 roomnum, struct hitthing *hitthing)
{
	s16 stack;
	s16 triref;
	s32 trisremaining;
	Gfx *gdl = batch->gdl;
	bool hit;
	s32 points[3];
	s32 numvertices;
	f32 sqdist;
	f32 lowestsqdist;
	s32 texturenum;
	s32 index;
	struct coord *point1;
	struct coord *point2;
	struct coord *point3;
	struct coord spb0;
	struct coord spa4;
	struct coord min;
	struct coord max;
	struct gfxvtx *vtx;
	f32 *ptr;
	Gfx *iter;
	Gfx *tmpgdl;
	Gfx *tri4gdl;

	vtx = roomFindVerticesForGdl(roomnum, gdl);
	iter = &gdl[batch->gbicmdindex];
	vtx = (struct gfxvtx *)((iter->words.w1 & 0xffffff) + (s32)vtx);
	numvertices = (((u32)iter->bytes[1] >> 4) & 0xf) + 1;
	ptr = var800a6470;

	while (numvertices > 0) {
		ptr[0] = g_BgRooms[roomnum].pos.x + vtx->x;
		ptr[1] = g_BgRooms[roomnum].pos.y + vtx->y;
		ptr[2] = g_BgRooms[roomnum].pos.z + vtx->z;

		ptr += 3;
		vtx++;
		numvertices--;
	}

	lowestsqdist = MAXFLOAT;
	hit = false;

	iter++;

	while (iter->dma.cmd != G_VTX && iter->dma.cmd != G_ENDDL) {
		if (iter->dma.cmd != G_TRI1 && iter->dma.cmd != G_TRI4) {
			iter++;
			continue;
		}

		if (iter->dma.cmd == G_TRI1) {
			trisremaining = 0;
			triref = 0;
			points[0] = iter->tri.tri.v[0] / 10;
			points[1] = iter->tri.tri.v[1] / 10;
			points[2] = iter->tri.tri.v[2] / 10;
		} else if (iter->dma.cmd == G_TRI4) {
			tri4gdl = iter;
			trisremaining = 3;
			triref = 1;
			points[0] = tri4gdl->tri4.x1;
			points[1] = tri4gdl->tri4.y1;
			points[2] = tri4gdl->tri4.z1;
		}

		do {
			if (points[0] == 0 && points[1] == 0 && points[2] == 0) {
				break;
			}

			point1 = (struct coord *) (var800a6470 + points[0] * 3);
			point2 = (struct coord *) (var800a6470 + points[1] * 3);
			point3 = (struct coord *) (var800a6470 + points[2] * 3);

			min.x = point1->x;

			if (point2->x < min.x) {
				min.x = point2->x;
			}

			if (point3->x < min.x) {
				min.x = point3->x;
			}

			if (!(arg0->x < min.x && arg1->x < min.x)) {
				max.x = point1->x;

				if (point2->x > max.x) {
					max.x = point2->x;
				}

				if (point3->x > max.x) {
					max.x = point3->x;
				}

				if (!(arg0->x > max.x && arg1->x > max.x)) {
					min.z = point1->z;

					if (point2->z < min.z) {
						min.z = point2->z;
					}

					if (point3->z < min.z) {
						min.z = point3->z;
					}

					if (!(arg0->z < min.z && arg1->z < min.z)) {
						max.z = point1->z;

						if (point2->z > max.z) {
							max.z = point2->z;
						}

						if (point3->z > max.z) {
							max.z = point3->z;
						}

						if (!(arg0->z > max.z && arg1->z > max.z)) {
							min.y = point1->y;

							if (point2->y < min.y) {
								min.y = point2->y;
							}

							if (point3->y < min.y) {
								min.y = point3->y;
							}

							if (!(arg0->y < min.y && arg1->y < min.y)) {
								max.y = point1->y;

								if (point2->y > max.y) {
									max.y = point2->y;
								}

								if (point3->y > max.y) {
									max.y = point3->y;
								}

								if (!(arg0->y > max.y && arg1->y > max.y)) {
									if (bgTestLineIntersectsBbox(arg0, arg2, &min, &max)
											&& func0002f560(point1, point2, point3, 0, arg0, arg1, arg2, &spb0, &spa4)) {
										f32 tmp;

										tmp = spb0.x - arg0->x;
										sqdist = tmp * tmp;
										tmp = spb0.y - arg0->y;
										sqdist += tmp * tmp;
										tmp = spb0.z - arg0->z;
										sqdist += tmp * tmp;

										if (sqdist < lowestsqdist) {
											hit = true;

											tmpgdl = iter;

											while (tmpgdl->bytes[0] != G_SETTIMG && tmpgdl > gdl) {
												tmpgdl--;
											}

											if (tmpgdl == gdl
													|| (tmpgdl->words.w1 & 0x0f000000) == 0x0f000000
													|| (tmpgdl->words.w1 & 0x05000000) == 0x05000000) {
												texturenum = -1;
											} else {
												s32 tmp = tmpgdl->words.w1 - 8;
												texturenum = *(s16 *) PHYS_TO_K0(tmp);
											}

											if (batch->type == VTXBATCHTYPE_XLU && g_Textures[texturenum].surfacetype == SURFACETYPE_DEFAULT) {
												hit = false;
											}

											if (hit) {
												lowestsqdist = sqdist;

												hitthing->unk00.x = spb0.x;
												hitthing->unk00.y = spb0.y;
												hitthing->unk00.z = spb0.z;
												hitthing->unk0c.x = spa4.x;
												hitthing->unk0c.y = spa4.y;
												hitthing->unk0c.z = spa4.z;
												hitthing->unk18 = &vtx[points[0]];
												hitthing->unk1c = &vtx[points[1]];
												hitthing->unk20 = &vtx[points[2]];
												hitthing->texturenum = texturenum;
												hitthing->tricmd = iter;
												hitthing->unk28 = triref;
												hitthing->unk2c = batch->type;
											}
										}
									}
								}
							}
						}
					}
				}
			}

			trisremaining--;

			if (1);
			if (1);
			if (1);

			if (trisremaining == 2) {
				points[0] = tri4gdl->tri4.x2;
				points[1] = tri4gdl->tri4.y2;
				points[2] = tri4gdl->tri4.z2;
				triref = 2;
			} else if (trisremaining == 1) {
				points[0] = tri4gdl->tri4.x3;
				points[1] = tri4gdl->tri4.y3;
				points[2] = tri4gdl->tri4.z3;
				triref = 3;
			} else if (trisremaining == 0) {
				points[0] = tri4gdl->tri4.x4;
				points[1] = tri4gdl->tri4.y4;
				points[2] = tri4gdl->tri4.z4;
				triref = 1;
			}
		} while (trisremaining >= 0);

		iter++;
	}

	return hit;
}

s32 bg0f1612e4(struct coord *bbmin, struct coord *bbmax, struct coord *arg2, struct coord *arg3, struct coord *arg4, struct coord *arg5)
{
	s32 i;
	u8 bail = true;
	s8 sp48[3];
	s32 bestindex;
	f32 sp38[3];
	f32 sp2c[3];

	for (i = 0; i < 3; i++) {
		if (arg2->f[i] < bbmin->f[i]) {
			sp48[i] = 1;
			sp38[i] = bbmin->f[i];
			bail = false;
		} else if (bbmax->f[i] < arg2->f[i]) {
			sp48[i] = 0;
			sp38[i] = bbmax->f[i];
			bail = false;
		} else {
			sp48[i] = 2;
			sp38[i] = 0.0f;
		}
	}

	if (bail) {
		return -1;
	}

	for (i = 0; i < 3; i++) {
		if (sp48[i] != 2 && arg3->f[i] != 0.0f) {
			sp2c[i] = (sp38[i] - arg2->f[i]) * arg4->f[i];
		} else {
			sp2c[i] = -1.0f;
		}
	}

	bestindex = 0;

	for (i = 1; i < 3; i++) {
		if (sp2c[i] > sp2c[bestindex]) {
			bestindex = i;
		}
	}

	if (sp2c[bestindex] < 0.0f) {
		return 0;
	}

	for (i = 0; i < 3; i++) {
		if (bestindex != i) {
			arg5->f[i] = arg2->f[i] + sp2c[bestindex] * arg3->f[i];

			if (arg5->f[i] < bbmin->f[i] || arg5->f[i] > bbmax->f[i]) {
				return 0;
			}
		} else {
			arg5->f[i] = sp38[i];
		}
	}

	return 1;
}

/**
 * Figure out which piece of BG geometry is hit in the given room based on a
 * line intersection from frompos to topos. Populate the hitthing struct with
 * the details. Props are not considered. Return true if a hit occurred.
 *
 * This is used not only for shots, but blood splatters and explosion scorch
 * marks too.
 *
 * Room vertices are already grouped into batches, where each batch has a
 * precomputed bounding box.
 */
bool bgTestHitInRoom(struct coord *frompos, struct coord *topos, s32 roomnum, struct hitthing *hitthing)
{
	s32 i;
	s32 count;
	f32 f20;
	s32 a0;
	s32 numbatches;
	s32 j;
	f32 f0;
	f32 spc8;
	f32 f2;
	struct coord spb8;
	struct coord spac;
	struct coord spa0;
	struct coord sp94;
	struct vtxbatch *batch;
	struct hitthing sp60;
	s32 tmpindex;

	count = 0;

	spb8.x = frompos->x;
	spb8.y = frompos->y;
	spb8.z = frompos->z;

	spac.x = topos->x;
	spac.y = topos->y;
	spac.z = topos->z;

	spa0.x = spac.x - spb8.x;
	spa0.y = spac.y - spb8.y;
	spa0.z = spac.z - spb8.z;

	sp94.x = 1.0f / spa0.x;
	sp94.y = 1.0f / spa0.y;
	sp94.z = 1.0f / spa0.z;

	if (roomnum < 0 || roomnum >= g_Vars.roomcount) {
		return false;
	}

	batch = g_Rooms[roomnum].vtxbatches;

	if (batch == NULL) {
		return false;
	}

	numbatches = g_Rooms[roomnum].numvtxbatches;

	for (i = 0; i < numbatches; batch++, i++) {
		j = bg0f1612e4(&batch->bbmin, &batch->bbmax, &spb8, &spa0, &sp94, &hitthing->unk00);

		if (j == 0) {
			continue;
		}

		if (j == 1) {
			f0 = spb8.x - hitthing->unk00.x;
			f20 = f0 * f0;

			f0 = spb8.y - hitthing->unk00.y;
			f20 += f0 * f0;

			f0 = spb8.z - hitthing->unk00.z;
			f20 += f0 * f0;
		} else {
			f20 = -1.0f;
		}

		if (count < ARRAYCOUNT(var800a6538)) {
			a0 = i;

			for (j = 0; j < count; j++) {
				f2 = var800a6538[j].unk04;

				if (f2 > f20) {
					tmpindex = var800a6538[j].vtxbatchindex;
					var800a6538[j].vtxbatchindex = a0;
					a0 = tmpindex;

					var800a6538[j].unk04 = f20;
					f20 = f2;
				}
			}

			var800a6538[j].vtxbatchindex = a0;
			var800a6538[j].unk04 = f20;
			count++;
		} else {
			count = 0;

			for (j = 0; j < ARRAYCOUNT(var800a6538); j++) {
				if (bgTestHitInVtxBatch(&spb8, &spac, &spa0, &g_Rooms[roomnum].vtxbatches[var800a6538[j].vtxbatchindex], roomnum, hitthing)) {
					f0 = spb8.x - hitthing->unk00.x;
					f2 = f0 * f0;

					f0 = spb8.y - hitthing->unk00.y;
					f2 += f0 * f0;

					f0 = spb8.z - hitthing->unk00.z;
					f2 += f0 * f0;

					if (count == 0) {
						var800a6538[0].vtxbatchindex = var800a6538[j].vtxbatchindex;
						var800a6538[0].unk04 = f2;
						count = 1;
					} else if (f2 < var800a6538[0].unk04) {
						var800a6538[0].vtxbatchindex = var800a6538[j].vtxbatchindex;
						var800a6538[0].unk04 = f2;
						count = 1;
					}
				}
			}

			if (count != 0) {
				if (f20 < var800a6538[0].unk04) {
					var800a6538[1].unk04 = var800a6538[0].unk04;
					var800a6538[0].unk04 = f20;
					var800a6538[1].vtxbatchindex = var800a6538[0].vtxbatchindex;
					var800a6538[0].vtxbatchindex = i;
				} else {
					var800a6538[1].vtxbatchindex = i;
					var800a6538[1].unk04 = f20;
				}

				count = 2;
			} else {
				var800a6538[0].vtxbatchindex = i;
				var800a6538[0].unk04 = f20;
				count = 1;
			}
		}
	}

	if (count == 0) {
		return false;
	}

	batch = g_Rooms[roomnum].vtxbatches;

	for (i = 0; i < count; i++) {
		if (bgTestHitInVtxBatch(&spb8, &spac, &spa0, &batch[var800a6538[i].vtxbatchindex], roomnum, hitthing)) {
			i++;

			if (i < count) {
				f0 = spb8.x - hitthing->unk00.x;
				spc8 = f0 * f0;

				f0 = spb8.y - hitthing->unk00.y;
				spc8 += f0 * f0;

				f0 = spb8.z - hitthing->unk00.z;
				spc8 += f0 * f0;

				for (; i < count; i++) {
					if (var800a6538[i].unk04 <= spc8) {
						if (bgTestHitInVtxBatch(&spb8, &spac, &spa0, &batch[var800a6538[i].vtxbatchindex], roomnum, &sp60)) {
							f0 = spb8.f[0] - sp60.unk00.f[0];
							f20 = f0 * f0;

							f0 = spb8.f[1] - sp60.unk00.f[1];
							f20 += f0 * f0;

							f0 = spb8.f[2] - sp60.unk00.f[2];
							f20 += f0 * f0;

							if (f20 < spc8) {
								hitthing->unk00.x = sp60.unk00.x;
								hitthing->unk00.y = sp60.unk00.y;
								hitthing->unk00.z = sp60.unk00.z;
								hitthing->unk0c.x = sp60.unk0c.x;
								hitthing->unk0c.y = sp60.unk0c.y;
								hitthing->unk0c.z = sp60.unk0c.z;
								hitthing->unk18 = sp60.unk18;
								hitthing->unk1c = sp60.unk1c;
								hitthing->unk20 = sp60.unk20;
								hitthing->texturenum = sp60.texturenum;
								hitthing->tricmd = sp60.tricmd;
								hitthing->unk28 = sp60.unk28;
								hitthing->unk2c = sp60.unk2c;

								spc8 = f20;
							}
						}
					}
				}
			}

			return true;
		}
	}

	return false;
}

bool roomIsLoaded(s32 room)
{
	return g_Rooms[room].loaded240;
}

bool roomContainsCoord(struct coord *pos, s16 roomnum)
{
	struct coord copy;
	copy.x = pos->x;
	copy.y = pos->y;
	copy.z = pos->z;

	return copy.f[0] >= g_Rooms[roomnum].bbmin[0]
		&& copy.f[0] <= g_Rooms[roomnum].bbmax[0]
		&& copy.f[2] >= g_Rooms[roomnum].bbmin[2]
		&& copy.f[2] <= g_Rooms[roomnum].bbmax[2]
		&& copy.f[1] >= g_Rooms[roomnum].bbmin[1]
		&& copy.f[1] <= g_Rooms[roomnum].bbmax[1];
}

bool func0f161c08(struct coord *arg0, s16 roomnum)
{
	s32 i;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		struct var800a4ccc *thing = &var800a4ccc[portalnum];

		f32 value = thing->coord.f[0] * arg0->f[0]
			+ thing->coord.f[1] * arg0->f[1]
			+ thing->coord.f[2] * arg0->f[2];

		if (value < thing->min) {
			if (roomnum != g_BgPortals[portalnum].roomnum1) {
				return false;
			}
		} else if (value > thing->max) {
			if (roomnum != g_BgPortals[portalnum].roomnum2) {
				return false;
			}
		}
	}

	return true;
}

bool func0f161d30(struct coord *arg0, s16 roomnum)
{
	s32 t5;
	struct coord *next;
	s32 t4;
	s32 portalnum;
	struct var800a4ccc *s2;
	s32 j;
	f32 f0;
	struct portalvertices *pvertices;
	struct coord sp74;
	struct coord sp68;
	struct coord sp5c;
	f32 sp58[1];
	struct coord sp4c;
	struct coord *cur;
	f32 f18;
	s32 i;
	f32 sum;

	sp74.f[0] = g_Rooms[roomnum].centre.f[0];
	sp74.f[1] = g_Rooms[roomnum].centre.f[1];
	sp74.f[2] = g_Rooms[roomnum].centre.f[2];

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		pvertices = (struct portalvertices *)((u8 *) g_BgPortals + g_BgPortals[portalnum].verticesoffset);
		s2 = &var800a4ccc[portalnum];

		f0 = arg0->f[0] * s2->coord.f[0] + arg0->f[1] * s2->coord.f[1] + arg0->f[2] * s2->coord.f[2];
		f18 = sp74.f[0] * s2->coord.f[0] + sp74.f[1] * s2->coord.f[1] + sp74.f[2] * s2->coord.f[2];

		if (f0 < s2->min) {
			if (f18 < s2->min) {
				continue;
			}
		} else {
			if (f0 > s2->max && f18 > s2->max) {
				continue;
			}
		}

		sp68.f[0] = sp74.f[0] - arg0->f[0];
		sp68.f[1] = sp74.f[1] - arg0->f[1];
		sp68.f[2] = sp74.f[2] - arg0->f[2];

		t4 = 0;
		t5 = true;
		cur = &pvertices->vertices[0];
		next = &pvertices->vertices[1];

		for (j = 0; j < pvertices->count; j++) {
			if (j + 1 == pvertices->count) {
				next = &pvertices->vertices[0];
			}

			sp5c.f[0] = next->f[0] - cur->f[0];
			sp5c.f[1] = next->f[1] - cur->f[1];
			sp5c.f[2] = next->f[2] - cur->f[2];

			sp4c.f[0] = sp5c.f[1] * sp68.f[2] - sp5c.f[2] * sp68.f[1];
			sp4c.f[1] = sp5c.f[2] * sp68.f[0] - sp5c.f[0] * sp68.f[2];
			sp4c.f[2] = sp5c.f[0] * sp68.f[1] - sp5c.f[1] * sp68.f[0];

			sum = sp4c.f[0] * sp4c.f[0] + sp4c.f[1] * sp4c.f[1] + sp4c.f[2] * sp4c.f[2];

			if (sum == 0.0f) {
				t5 = false;
				break;
			}

			sp58[0] = sp4c.f[0] * cur->f[0] + sp4c.f[1] * cur->f[1] + sp4c.f[2] * cur->f[2];
			sum = sp4c.f[0] * arg0->f[0] + sp4c.f[1] * arg0->f[1] + sp4c.f[2] * arg0->f[2];

			if (sum < sp58[0]) {
				if (t4 == 2) {
					t5 = false;
					break;
				}

				t4 = 1;
			} else if (t4 == 1) {
				t5 = false;
				break;
			} else {
				t4 = 2;
			}

			cur++;
			next++;
		}

		if (t5) {
			if (f0 < s2->min) {
				if (roomnum == g_BgPortals[portalnum].roomnum2) {
					return false;
				}
			} else if (f0 > s2->max) {
				if (roomnum == g_BgPortals[portalnum].roomnum1) {
					return false;
				}
			}
		}
	}

	return true;
}

bool func0f162128(struct coord *arg0, s16 roomnum)
{
	if (g_Rooms[roomnum].flags & ROOMFLAG_0010) {
		return func0f161d30(arg0, roomnum);
	}

	return func0f161c08(arg0, roomnum);
}

/**
 * Find rooms near the given pos so the caller can decide which room pos is
 * actually in.
 *
 * inrooms should point to an empty array of room numbers whose length is max + 1.
 * The function will populate this array with room numbers where the pos is
 * inside the room's bounding box.
 *
 * aboverooms works the same way, but it'll be populated with room numbers where
 * the pos is above the room's bounding box.
 *
 * For both arrays, the function will only consider rooms that have portals.
 * If this doesn't produce anything for both arrays, the function will try again
 * but with rooms that have no portals.
 *
 * If all of the above produces no results (ie. the pos is out of bounds) and
 * the bestroom pointer is not NULL, the function then finds the closest room
 * to pos and writes the room number to the bestroom pointer. The bestroom
 * pointer is a pointer to a single s16 rather than an array.
 */
void bgFindRoomsByPos(struct coord *posarg, s16 *inrooms, s16 *aboverooms, s32 max, s16 *bestroom)
{
	s32 inlen = 0;
	s32 abovelen = 0;
	s32 closestroomnum = -1;
	struct coord pos;
	f32 closestdist = 0.0f;
	s32 i;
	s32 j;

	pos.x = posarg->x;
	pos.y = posarg->y;
	pos.z = posarg->z;

	// Try rooms which have portals
	for (i = 1; i < g_Vars.roomcount; i++) {
		if (g_Rooms[i].numportals > 0
				&& pos.x >= g_Rooms[i].bbmin[0] && pos.x <= g_Rooms[i].bbmax[0]
				&& pos.z >= g_Rooms[i].bbmin[2] && pos.z <= g_Rooms[i].bbmax[2]
				&& pos.y >= g_Rooms[i].bbmin[1]) {
			if (pos.y <= g_Rooms[i].bbmax[1]) {
				// Pos is inside the bbox
				if (inlen < max) {
					inrooms[inlen] = i;
					inlen++;
				}
			} else {
				// Pos is above the bbox
				if (abovelen < max) {
					aboverooms[abovelen] = i;
					abovelen++;
				}
			}
		}
	}

	// Try again but with rooms that have no portals
	if (inlen == 0 && abovelen == 0) {
		for (i = 1; i < g_Vars.roomcount; i++) {
			if (g_Rooms[i].numportals == 0
					&& pos.x >= g_Rooms[i].bbmin[0] && pos.x <= g_Rooms[i].bbmax[0]
					&& pos.z >= g_Rooms[i].bbmin[2] && pos.z <= g_Rooms[i].bbmax[2]
					&& pos.y >= g_Rooms[i].bbmin[1]) {
				if (pos.y <= g_Rooms[i].bbmax[1]) {
					// Pos is inside the bbox
					if (inlen < max) {
						inrooms[inlen] = i;
						inlen++;
					}
				} else {
					// Pos is above the bbox
					if (abovelen < max) {
						aboverooms[abovelen] = i;
						abovelen++;
					}
				}
			}
		}
	}

	inrooms[inlen] = -1;
	aboverooms[abovelen] = -1;

	if (bestroom != NULL) {
		if (inlen == 0 && abovelen == 0) {
			for (i = 1; i < g_Vars.roomcount; i++) {
				f32 dist = 0.0f;

				for (j = 0; j < 3; j++) {
					if (pos.f[j] < g_Rooms[i].bbmin[j] || pos.f[j] > g_Rooms[i].bbmax[j]) {
						f32 dist1 = pos.f[j] - g_Rooms[i].bbmin[j];
						f32 dist2 = pos.f[j] - g_Rooms[i].bbmax[j];

						if (dist1 < 0.0f) {
							dist1 = -dist1;
						}

						if (dist2 < 0.0f) {
							dist2 = -dist2;
						}

						if (dist2 < dist1) {
							dist1 = dist2;
						}

						dist += dist1;
					}
				}

				if (dist > 0.0f && (closestroomnum < 0 || dist < closestdist)) {
					closestroomnum = i;
					closestdist = dist;
				}
			}
		}

		*bestroom = closestroomnum >= 0 ? closestroomnum : -1;
	}
}

void bgCmdDisableRoom(s32 roomnum)
{
	g_Rooms[roomnum].flags |= ROOMFLAG_DISABLEDBYSCRIPT;
}

void bgCmdReset(void)
{
	var800a65c0.xmin = g_Vars.currentplayer->screenxminf;
	var800a65c0.ymin = g_Vars.currentplayer->screenyminf;
	var800a65c0.xmax = g_Vars.currentplayer->screenxmaxf;
	var800a65c0.ymax = g_Vars.currentplayer->screenymaxf;

	g_BgCmdResult = BGRESULT_TRUE;
}

void bgCmdRestrictToPortal(s32 portalnum)
{
	if (g_BgCmdResult == BGRESULT_TRUE) {
		if (PORTAL_IS_OPEN(portalnum)) {
			if (g_PortalGetScreenBbox(portalnum, &g_PortalScreenBbox) == 0) {
				g_BgCmdResult = BGRESULT_FALSE;
			} else if (boxGetIntersection(&var800a65c0, &g_PortalScreenBbox) == 0) {
				g_BgCmdResult = BGRESULT_FALSE;
			}
		} else {
			g_BgCmdResult = BGRESULT_FALSE;
		}
	}
}

void bgCmdTryEnableRoom(s32 roomnum)
{
	if (g_BgCmdResult == BGRESULT_TRUE && func0f15cd90(roomnum, &var800a65c0)) {
		roomSetOnscreen(roomnum, 0, &var800a65c0);
		g_ActiveRoomNums[g_NumActiveRooms++] = roomnum;
	}
}

void bgExecuteCommands(void)
{
	switch (g_Stages[g_StageIndex].bgfileid) {
	case FILE_BG_ELD_SEG: // Villa
		if (g_CamRoom == 0x2b) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x2b);
			bgCmdRestrictToPortal(0x57);
			bgCmdTryEnableRoom(0x2c);
			bgCmdRestrictToPortal(0x58);
			bgCmdTryEnableRoom(0x2d);
			bgCmdReset();
			bgCmdRestrictToPortal(0x56);
			bgCmdTryEnableRoom(0x2a);
			bgCmdRestrictToPortal(0x54);
			bgCmdTryEnableRoom(0x29);
			bgCmdReset();
			bgCmdRestrictToPortal(0x56);
			bgCmdRestrictToPortal(0x55);
			bgCmdTryEnableRoom(0x49);
			bgCmdRestrictToPortal(0x97);
			bgCmdTryEnableRoom(0x4a);
			bgCmdTryEnableRoom(0x4b);
			bgCmdTryEnableRoom(0x54);
			bgCmdTryEnableRoom(0x4c);
			bgCmdTryEnableRoom(0x6e);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom == 0x33) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x33);
			bgCmdRestrictToPortal(0x5f);
			bgCmdTryEnableRoom(0x32);
			bgCmdRestrictToPortal(0x5e);
			bgCmdTryEnableRoom(0x31);
			bgCmdRestrictToPortal(0x5d);
			bgCmdTryEnableRoom(0x30);
			bgCmdReset();
			bgCmdRestrictToPortal(0x61);
			bgCmdTryEnableRoom(0x34);
			bgCmdRestrictToPortal(0x5b);
			bgCmdTryEnableRoom(0x2f);
			bgCmdRestrictToPortal(0x5a);
			bgCmdTryEnableRoom(0x2e);
			bgCmdRestrictToPortal(0x59);
			bgCmdTryEnableRoom(0x2d);
			bgCmdReset();
			bgCmdRestrictToPortal(0x61);
			bgCmdRestrictToPortal(0x60);
			bgCmdTryEnableRoom(0x35);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom == 0x34) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x34);
			bgCmdRestrictToPortal(0x60);
			bgCmdTryEnableRoom(0x35);
			bgCmdRestrictToPortal(0x62);
			bgCmdTryEnableRoom(0x37);
			bgCmdTryEnableRoom(0x38);
			bgCmdTryEnableRoom(0x39);
			bgCmdReset();
			bgCmdTryEnableRoom(0x36);
			bgCmdReset();
			bgCmdRestrictToPortal(0x61);
			bgCmdTryEnableRoom(0x33);
			bgCmdRestrictToPortal(0x5f);
			bgCmdTryEnableRoom(0x32);
			bgCmdReset();
			bgCmdRestrictToPortal(0x5b);
			bgCmdTryEnableRoom(0x2f);
			bgCmdRestrictToPortal(0x5a);
			bgCmdTryEnableRoom(0x2e);
			bgCmdRestrictToPortal(0x59);
			bgCmdTryEnableRoom(0x2d);
			bgCmdReset();
			bgCmdRestrictToPortal(0x5b);
			bgCmdRestrictToPortal(0x5c);
			bgCmdTryEnableRoom(0x30);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom == 0x35) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x35);
			bgCmdRestrictToPortal(0x62);
			bgCmdTryEnableRoom(0x37);
			bgCmdTryEnableRoom(0x38);
			bgCmdTryEnableRoom(0x39);
			bgCmdRestrictToPortal(0x71);
			bgCmdTryEnableRoom(0x3a);
			bgCmdReset();
			bgCmdTryEnableRoom(0x36);
			bgCmdReset();
			bgCmdRestrictToPortal(0x60);
			bgCmdTryEnableRoom(0x34);
			bgCmdRestrictToPortal(0x61);
			bgCmdTryEnableRoom(0x33);
			bgCmdReset();
			bgCmdRestrictToPortal(0x60);
			bgCmdRestrictToPortal(0x5b);
			bgCmdTryEnableRoom(0x2f);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom == 0x37) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x37);
			bgCmdTryEnableRoom(0x36);
			bgCmdRestrictToPortal(0x6f);
			bgCmdTryEnableRoom(0x38);
			bgCmdRestrictToPortal(0x72);
			bgCmdTryEnableRoom(0x3a);
			bgCmdReset();
			bgCmdRestrictToPortal(0x6f);
			bgCmdRestrictToPortal(0x70);
			bgCmdTryEnableRoom(0x28);
			bgCmdReset();
			bgCmdRestrictToPortal(0x62);
			bgCmdTryEnableRoom(0x35);
			bgCmdRestrictToPortal(0x60);
			bgCmdTryEnableRoom(0x34);
			bgCmdRestrictToPortal(0x5b);
			bgCmdTryEnableRoom(0x2f);
			bgCmdReset();
			bgCmdRestrictToPortal(0x6e);
			bgCmdTryEnableRoom(0x39);
			bgCmdRestrictToPortal(0x71);
			bgCmdTryEnableRoom(0x3a);
			bgCmdRestrictToPortal(0x73);
			bgCmdTryEnableRoom(0x3d);
			bgCmdTryEnableRoom(0x68);
			bgCmdTryEnableRoom(0x3c);
			bgCmdTryEnableRoom(0x62);
			bgCmdTryEnableRoom(0x66);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom == 0x38 || g_CamRoom == 0x3a) {
			bgCmdReset();

			if (g_CamRoom == 0x3a) {
				bgCmdTryEnableRoom(0x3a);
				bgCmdTryEnableRoom(0x36);
				bgCmdRestrictToPortal(0x72);
				bgCmdTryEnableRoom(0x38);
				bgCmdTryEnableRoom(0x37);
				bgCmdReset();
				bgCmdRestrictToPortal(0x71);
				bgCmdTryEnableRoom(0x39);
				bgCmdRestrictToPortal(0x6e);
				bgCmdTryEnableRoom(0x37);
				bgCmdRestrictToPortal(0x62);
				bgCmdTryEnableRoom(0x35);
				g_BgRoomTestsDisabled = true;
			} else {
				bgCmdTryEnableRoom(0x38);
				bgCmdTryEnableRoom(0x36);
				bgCmdReset();
				bgCmdRestrictToPortal(0x72);
				bgCmdTryEnableRoom(0x3a);
				bgCmdRestrictToPortal(0x71);
				bgCmdTryEnableRoom(0x39);
				bgCmdReset();
				bgCmdRestrictToPortal(0x70);
				bgCmdTryEnableRoom(0x28);
				bgCmdReset();
				bgCmdRestrictToPortal(0x6f);
				bgCmdTryEnableRoom(0x37);
				bgCmdRestrictToPortal(0x62);
				bgCmdTryEnableRoom(0x35);
				bgCmdReset();
				bgCmdRestrictToPortal(0x6f);
				bgCmdRestrictToPortal(0x6e);
				bgCmdTryEnableRoom(0x39);
				g_BgRoomTestsDisabled = true;
			}

			bgCmdReset();

			if (g_CamRoom == 0x38) {
				bgCmdRestrictToPortal(0x72);
			}

			bgCmdRestrictToPortal(0x73);
			bgCmdTryEnableRoom(0x35);
			bgCmdTryEnableRoom(0x3b);
			bgCmdTryEnableRoom(0x3c);
			bgCmdTryEnableRoom(0x3d);
			bgCmdTryEnableRoom(0x3f);
			bgCmdTryEnableRoom(0x4d);
			bgCmdTryEnableRoom(0x4e);
			bgCmdTryEnableRoom(0x4f);
			bgCmdTryEnableRoom(0x50);
			bgCmdTryEnableRoom(0x51);
			bgCmdTryEnableRoom(0x52);
			bgCmdTryEnableRoom(0x55);
			bgCmdTryEnableRoom(0x56);
			bgCmdTryEnableRoom(0x61);
			bgCmdTryEnableRoom(0x62);
			bgCmdTryEnableRoom(0x63);
			bgCmdTryEnableRoom(0x64);
			bgCmdTryEnableRoom(0x65);
			bgCmdTryEnableRoom(0x66);
			bgCmdTryEnableRoom(0x68);
			bgCmdTryEnableRoom(0x6a);
			bgCmdTryEnableRoom(0x6b);
			bgCmdTryEnableRoom(0x6c);
			bgCmdTryEnableRoom(0x6d);
			bgCmdTryEnableRoom(0x71);
			bgCmdReset();
			bgCmdRestrictToPortal(0x73);
			bgCmdRestrictToPortal(0x09);
			bgCmdTryEnableRoom(0x05);
			bgCmdReset();
			bgCmdRestrictToPortal(0x73);
			bgCmdRestrictToPortal(0x1e);
			bgCmdTryEnableRoom(0x0f);

			if (PORTAL_IS_OPEN(0x1e)) {
				bgCmdRestrictToPortal(0x1d);
				bgCmdTryEnableRoom(0x0e);
			}

			bgCmdReset();
			bgCmdRestrictToPortal(0x73);
			bgCmdRestrictToPortal(0x46);
			bgCmdTryEnableRoom(0x21);
			bgCmdRestrictToPortal(0x47);
			bgCmdTryEnableRoom(0x27);
			bgCmdReset();
			bgCmdRestrictToPortal(0x73);
			bgCmdRestrictToPortal(0x17);
			bgCmdTryEnableRoom(0x0c);

			if (PORTAL_IS_OPEN(0x24)) {
				bgCmdReset();
				bgCmdRestrictToPortal(0x73);
				bgCmdRestrictToPortal(0x24);
				bgCmdTryEnableRoom(0x11);

				if (PORTAL_IS_OPEN(0x20)) {
					bgCmdRestrictToPortal(0x24);
					bgCmdTryEnableRoom(0x10);
				}
			}

			if (PORTAL_IS_OPEN(0x2c)) {
				bgCmdReset();
				bgCmdRestrictToPortal(0x73);
				bgCmdRestrictToPortal(0x2c);
				bgCmdTryEnableRoom(0x16);
			}

			if (PORTAL_IS_OPEN(0x43)) {
				bgCmdReset();
				bgCmdRestrictToPortal(0x73);
				bgCmdRestrictToPortal(0x43);
				bgCmdTryEnableRoom(0x20);
			}
		} else if (g_CamRoom == 0x39) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x39);
			bgCmdTryEnableRoom(0x36);
			bgCmdRestrictToPortal(0x71);
			bgCmdTryEnableRoom(0x3a);
			bgCmdRestrictToPortal(0x73);
			bgCmdTryEnableRoom(0x3d);
			bgCmdTryEnableRoom(0x68);
			bgCmdTryEnableRoom(0x3c);
			bgCmdTryEnableRoom(0x62);
			bgCmdTryEnableRoom(0x66);
			bgCmdReset();
			bgCmdRestrictToPortal(0x71);
			bgCmdRestrictToPortal(0x72);
			bgCmdTryEnableRoom(0x38);
			bgCmdReset();
			bgCmdRestrictToPortal(0x6e);
			bgCmdTryEnableRoom(0x37);
			bgCmdRestrictToPortal(0x62);
			bgCmdTryEnableRoom(0x35);
			bgCmdReset();
			bgCmdRestrictToPortal(0x6e);
			bgCmdRestrictToPortal(0x6f);
			bgCmdTryEnableRoom(0x38);
			g_BgRoomTestsDisabled = true;
		} else if (g_CamRoom >= 0x44 && g_CamRoom <= 0x47) {
			bgCmdDisableRoom(0x40);
			bgCmdDisableRoom(0x3f);
			bgCmdDisableRoom(0x41);
			bgCmdDisableRoom(0x59);
			bgCmdDisableRoom(0x3e);
			bgCmdDisableRoom(0x50);
			bgCmdDisableRoom(0x4a);
			bgCmdDisableRoom(0x4b);
			bgCmdDisableRoom(0x4c);
			bgCmdDisableRoom(0x61);
			bgCmdDisableRoom(0x4e);
			bgCmdDisableRoom(0x63);
			bgCmdDisableRoom(0x51);
			bgCmdDisableRoom(0x4f);
			bgCmdDisableRoom(0x52);

			if (g_CamRoom == 0x46) {
				bgCmdReset();
				bgCmdTryEnableRoom(0x5f);
			}
		}

		if ((g_CamRoom >= 0x4a && g_CamRoom <= 0x4c)
				|| g_CamRoom == 0x3e
				|| g_CamRoom == 0x59
				|| g_CamRoom == 0x5b) {
			bgCmdDisableRoom(0x44);
			bgCmdDisableRoom(0x45);
			bgCmdDisableRoom(0x46);
			bgCmdDisableRoom(0x48);
			bgCmdDisableRoom(0x47);
		}

		if ((g_CamRoom >= 0x4a && g_CamRoom <= 0x4c)
				|| g_CamRoom == 0x3f
				|| g_CamRoom == 0x40
				|| g_CamRoom == 0x59
				|| g_CamRoom == 0x5b) {
			bgCmdDisableRoom(0x4f);
			bgCmdDisableRoom(0x61);
			bgCmdDisableRoom(0x0c);
			bgCmdDisableRoom(0x4e);
		}

		if (g_CamRoom == 0x61 || g_CamRoom == 0x62 || g_CamRoom == 0x4e || g_CamRoom == 0x68) {
			bgCmdDisableRoom(0x0c);
			bgCmdDisableRoom(0x3f);
			bgCmdDisableRoom(0x40);
			bgCmdDisableRoom(0x41);
			bgCmdDisableRoom(0x48);
			bgCmdDisableRoom(0x47);
			bgCmdDisableRoom(0x46);
			bgCmdDisableRoom(0x45);
			bgCmdDisableRoom(0x44);
			bgCmdDisableRoom(0x43);
			bgCmdDisableRoom(0x42);
			bgCmdDisableRoom(0x57);
			bgCmdDisableRoom(0x4c);

			if (g_CamRoom != 0x61) {
				g_Rooms[0x62].unk07 = 0;
				g_Rooms[0x4e].unk07 = 0;
				g_Rooms[0x68].unk07 = 0;
			}
		}
		break;
	case FILE_BG_PETE_SEG: // Chicago
		if (g_CamRoom >= 0x02 && g_CamRoom <= 0x10) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x54);
			bgCmdTryEnableRoom(0x58);

			if (g_CamRoom == 0x02 || g_CamRoom == 0x10) {
				bgCmdTryEnableRoom(0x29);
			}

			if (g_CamRoom == 0x0f) {
				bgCmdTryEnableRoom(0x57);
			}
		} else if (g_CamRoom == 0x11 || g_CamRoom == 0x12 || g_CamRoom == 0x14) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
		} else if (g_CamRoom == 0x25) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
			bgCmdTryEnableRoom(0x2a);
			bgCmdTryEnableRoom(0x58);
		} else if (g_CamRoom == 0x26) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
			bgCmdTryEnableRoom(0x2a);
			bgCmdTryEnableRoom(0x2b);
			bgCmdTryEnableRoom(0x58);
		} else if (g_CamRoom == 0x27) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x57);
			bgCmdTryEnableRoom(0x2b);
			bgCmdTryEnableRoom(0x58);
		} else if (g_CamRoom == 0x28) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
			bgCmdTryEnableRoom(0x2a);
			bgCmdTryEnableRoom(0x2b);
			bgCmdTryEnableRoom(0x58);
		} else if (g_CamRoom == 0x44 || g_CamRoom == 0x45) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x53);
			bgCmdTryEnableRoom(0x54);
			bgCmdTryEnableRoom(0x57);
			bgCmdTryEnableRoom(0x58);
		} else if (g_CamRoom >= 0x4a && g_CamRoom <= 0x52) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x57);
			bgCmdTryEnableRoom(0x58);
			bgCmdTryEnableRoom(0x53);
			bgCmdTryEnableRoom(0x54);

			if (g_CamRoom == 0x4e) {
				bgCmdTryEnableRoom(0x2b);
			}
		} else if (g_CamRoom == 0x61) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x58);
		}
		break;
	case FILE_BG_LUE_SEG: // Area 51
		if (g_CamRoom == 0x2e) {
			bgCmdReset();
			bgCmdRestrictToPortal(0x43);
			bgCmdTryEnableRoom(0x38);
			bgCmdRestrictToPortal(0x41);
			bgCmdTryEnableRoom(0x37);

			if (PORTAL_IS_OPEN(0x42)) {
				bgCmdRestrictToPortal(0x42);
				bgCmdTryEnableRoom(0x5c);
				bgCmdRestrictToPortal(0x70);
				bgCmdTryEnableRoom(0x5a);
			}
		} else if (g_CamRoom == 0x5a) {
			bgCmdReset();
			bgCmdRestrictToPortal(0x6c);
			bgCmdTryEnableRoom(0x59);
		}
		break;
	case FILE_BG_DAM_SEG: // Pelagic II
		if (g_CamRoom >= 0x29 && g_CamRoom <= 0x2b) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
			bgCmdTryEnableRoom(0x2a);
			bgCmdTryEnableRoom(0x2b);
		}
		break;
	case FILE_BG_PAM_SEG: // Deep Sea
		if (g_CamRoom == 0x03 || (g_CamRoom >= 0x06 && g_CamRoom <= 0x08)) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x09);
			bgCmdTryEnableRoom(0x0a);
			bgCmdTryEnableRoom(0x0b);
		} else if (g_CamRoom == 0x02) {
			bgCmdReset();
			bgCmdRestrictToPortal(0x02);
			bgCmdTryEnableRoom(0x0a);
			bgCmdTryEnableRoom(0x0b);
		}
		break;
	case FILE_BG_SHO_SEG: // Skedar Ruins
		if (g_CamRoom >= 0x04 && g_CamRoom <= 0x50) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x03);
			bgCmdTryEnableRoom(0x1c);
		} else if (g_CamRoom >= 0x56 && g_CamRoom <= 0x60) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x03);
			bgCmdTryEnableRoom(0x1c);
		}

		if (g_CamRoom == 0x04 || g_CamRoom == 0x09 || g_CamRoom == 0x0a) {
			bgCmdDisableRoom(0x0b);
			bgCmdDisableRoom(0x0c);
			bgCmdDisableRoom(0x0d);
			bgCmdDisableRoom(0x0e);
			bgCmdDisableRoom(0x0f);
			bgCmdDisableRoom(0x10);
			bgCmdDisableRoom(0x11);
			bgCmdDisableRoom(0x12);
		} else if (g_CamRoom == 0x1e || g_CamRoom == 0x1f) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x3a);
		} else if (g_CamRoom >= 0x2a && g_CamRoom <= 0x2c) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x33);
		} else if (g_CamRoom == 0x30) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x39);
		} else if (g_CamRoom == 0x3c) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x29);
		} else if (g_CamRoom == 0x47) {
			bgCmdReset();
			bgCmdDisableRoom(0x4b);
			bgCmdTryEnableRoom(0x4c);
			bgCmdTryEnableRoom(0x48);
			bgCmdTryEnableRoom(0x4e);
			bgCmdDisableRoom(0x4f);
		} else if (g_CamRoom == 0x49 || g_CamRoom == 0x4a) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x4c);
			bgCmdTryEnableRoom(0x48);
			bgCmdTryEnableRoom(0x4e);
			bgCmdTryEnableRoom(0x4d);
			bgCmdDisableRoom(0x4f);
		} else if (g_CamRoom == 0x4f) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x4e);
			bgCmdTryEnableRoom(0x4d);
		} else if (g_CamRoom >= 0x51 && g_CamRoom <= 0x55) {
			bgCmdDisableRoom(0x02);
		} else if (g_CamRoom >= 0x7d && g_CamRoom <= 0x84) {
			bgCmdDisableRoom(0x88);
			bgCmdDisableRoom(0x86);
		} else if (g_CamRoom == 0x88) {
			bgCmdDisableRoom(0x7d);
			bgCmdDisableRoom(0x7e);
			bgCmdDisableRoom(0x7f);
			bgCmdDisableRoom(0x80);
			bgCmdDisableRoom(0x81);
			bgCmdDisableRoom(0x82);
			bgCmdDisableRoom(0x83);
			bgCmdDisableRoom(0x84);
		}

		if (g_CamRoom >= 0x61 && g_CamRoom <= 0x7d) {
			bgCmdDisableRoom(0x02);
		}

		break;
	}
}

void bgTickPortalsXray(void)
{
	struct coord vismax;
	struct coord vismin;
	struct coord eraserpos;
	struct coord vismid;
	struct player *player = g_Vars.currentplayer;
	s16 ymax;
	s16 xmax;
	s16 ymin;
	s16 xmin;
	struct stagetableentry *stage;
	s32 i;
	struct var800a4640 *thing;

	static u32 edist = 400;

	currentPlayerCalculateScreenProperties();

	if (var800a4640.unk000);

	if (var8007fc34 < var8007fc30) {
		var8007fc34 = var8007fc30;
	}

	xmin = player->screenxminf;
	ymin = player->screenyminf;
	xmax = player->screenxmaxf;
	ymax = player->screenymaxf;

	if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT && player->gunsightoff == 0) {
		player->eraserdepth = -500.0f / camGetLodScaleZ();
	} else {
		player->eraserdepth = -500.0f;
	}

	eraserpos.f[0] = 0.0f;
	eraserpos.f[1] = 0.0f;
	eraserpos.f[2] = player->eraserdepth;

	mtx4TransformVecInPlace(camGetProjectionMtxF(), &eraserpos);

	player->eraserpos.f[0] = eraserpos.f[0];
	player->eraserpos.f[1] = eraserpos.f[1];
	player->eraserpos.f[2] = eraserpos.f[2];

	mainOverrideVariable("edist", &edist);

	stage = stageGetCurrent();

	player->eraserpropdist = stage->eraserpropdist;
	player->eraserbgdist = (f32) stage->eraserpropdist + stage->unk30;

	vismax.f[0] = eraserpos.f[0] + player->eraserbgdist;
	vismax.f[1] = eraserpos.f[1] + player->eraserbgdist;
	vismax.f[2] = eraserpos.f[2] + player->eraserbgdist;

	vismin.f[0] = eraserpos.f[0] - player->eraserbgdist;
	vismin.f[1] = eraserpos.f[1] - player->eraserbgdist;
	vismin.f[2] = eraserpos.f[2] - player->eraserbgdist;

	vismid.f[0] = eraserpos.f[0];
	vismid.f[1] = eraserpos.f[1];
	vismid.f[2] = eraserpos.f[2];

	var8007fc2c = 0;
	var8007fc30 = 0;

	var800a4640.unk2d0.roomnum = -1;
	var800a4640.unk2d0.draworder = 255;
	var800a4640.unk2d0.box.xmin = xmin;
	var800a4640.unk2d0.box.ymin = ymin;
	var800a4640.unk2d0.box.xmax = xmax;
	var800a4640.unk2d0.box.ymax = ymax;

	var800a4ce6 = 0;
	var800a4ce4 = 0x7fff;

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (!(vismax.f[0] < g_Rooms[i].bbmin[0]) && !(vismin.f[0] > g_Rooms[i].bbmax[0])
				&& !(vismax.f[2] < g_Rooms[i].bbmin[2]) && !(vismin.f[2] > g_Rooms[i].bbmax[2])
				&& !(vismax.f[1] < g_Rooms[i].bbmin[1]) && !(vismin.f[1] > g_Rooms[i].bbmax[1])) {
			s32 index = var8007fc2c;

			if (xmin);
			if (g_Rooms[i].bbmax);
			if (1);
			if (1);
			if (1);

			if (index < 60) {
				f32 x;
				f32 y;
				f32 z;

				g_Rooms[i].flags |= ROOMFLAG_ONSCREEN;

				var800a4640.unk000[index].roomnum = i;

				roomUnpauseProps(i, false);

				x = (g_Rooms[i].bbmin[0] + g_Rooms[i].bbmax[0]) / 2.0f - vismid.f[0];
				y = (g_Rooms[i].bbmin[1] + g_Rooms[i].bbmax[1]) / 2.0f - vismid.f[1];
				z = (g_Rooms[i].bbmin[2] + g_Rooms[i].bbmax[2]) / 2.0f - vismid.f[2];

				var800a4640.unk000[index].draworder = sqrtf(x * x + y * y + z * z) / 100.0f;

				if (var800a4640.unk000[index].draworder > var800a4ce6) {
					var800a4ce6 = var800a4640.unk000[index].draworder;
				}

				if (var800a4640.unk000[index].draworder < var800a4ce4) {
					var800a4ce4 = var800a4640.unk000[index].draworder;
				}

				var800a4640.unk000[index].box.xmin = xmin;
				var800a4640.unk000[index].box.ymin = ymin;
				var800a4640.unk000[index].box.xmax = xmax;
				var800a4640.unk000[index].box.ymax = ymax;

				var8007fc2c++;
				var8007fc30++;

				g_Rooms[player->cam_room].flags |= ROOMFLAG_ONSCREEN;
			} else {
				// empty
			}
		}
	}

	bgChooseRoomsToLoad();
}

void func0f1632d4(s16 roomnum1, s16 roomnum2, s16 draworder, struct screenbox *box)
{
	struct var800a4d00 *thing;
	s32 i;
	s32 j;

	if (g_Rooms[roomnum2].flags & ROOMFLAG_DISABLEDBYSCRIPT) {
		return;
	}

	if (draworder >= 2) {
		if (g_Rooms[roomnum2].portalrecursioncount < 255) {
			g_Rooms[roomnum2].portalrecursioncount++;
		}

		if (g_Rooms[roomnum2].portalrecursioncount > g_Vars.roomportalrecursionlimit) {
			return;
		}
	}

	if (g_Rooms[roomnum2].unk06 && g_Rooms[roomnum2].unk07) {
		i = var800a4cf0.unk04;
		thing = &var800a4cf0.unk10[i];

		while (i != var800a4cf0.index) {
			if (thing->roomnum == roomnum2) {
				for (j = 0; j < 5; j++) {
					if (thing->roomnums[j] == -1) {
						boxExpand(&thing->screenbox, box);
						thing->roomnums[j] = roomnum1;
						return;
					}
				}
			}

			i++;
			thing++;

			if (i == 250) {
				i = 0;
				thing = &var800a4cf0.unk10[0];
			}
		}
	}

	thing = &var800a4cf0.unk10[var800a4cf0.index];
	thing->roomnums[0] = roomnum1;
	thing->roomnum = roomnum2;
	thing->draworder = draworder;
	thing->roomportallistoffset = g_Rooms[roomnum2].roomportallistoffset;
	thing->numportals = g_Rooms[roomnum2].numportals;

	thing->screenbox.xmin = box->xmin;
	thing->screenbox.ymin = box->ymin;
	thing->screenbox.xmax = box->xmax;
	thing->screenbox.ymax = box->ymax;

	g_Rooms[roomnum2].unk06++;

	for (i = 1; i < 5; i++) {
		thing->roomnums[i] = -1;
	}

	var800a4cf0.index++;

	if (var800a4cf0.index == 250) {
		var800a4cf0.index = 0;
	}

	if (var800a4cf0.index == var800a4cf0.unk04) {
		var800a4cf0.index--;
	}
}

void func0f163528(struct var800a4d00 *arg0)
{
	struct coord *campos;
	s32 i;
	s16 portalnum;
	s16 s4;
	s16 s6;
	s16 s0;
	s16 unk02;
	s16 tmp;
	bool pass;
	struct var800a4ccc *thing;
	struct screenbox box1;
	struct screenbox box2;
	f32 sum;

	g_Rooms[arg0->roomnum].unk06--;
	var800a4cf0.unk00++;
	campos = &g_Vars.currentplayer->cam_pos;
	s4 = 0;
	s6 = -1;

	for (i = 0; i < arg0->numportals; i++) {
		portalnum = g_RoomPortals[arg0->roomportallistoffset + i];

		if (g_PortalThings[portalnum].unk00 != var8007fc3c) {
			thing = &var800a4ccc[portalnum];
			sum = thing->coord.x * campos->f[0]
				+ thing->coord.y * campos->f[1]
				+ thing->coord.z * campos->f[2];

			if (sum < thing->min) {
				g_PortalThings[portalnum].unk02 = 1;
			} else if (sum > thing->max) {
				g_PortalThings[portalnum].unk02 = 0;
			} else {
				g_PortalThings[portalnum].unk02 = 2;
			}

			g_PortalThings[portalnum].unk00 = var8007fc3c;
		}

		tmp = g_BgPortals[portalnum].roomnum1;
		unk02 = g_PortalThings[portalnum].unk02;

		if ((u32)tmp == arg0->roomnum) {
			if (unk02 == 0) {
				continue;
			}

			s0 = g_BgPortals[portalnum].roomnum2;
		} else {
			if (unk02 == 1) {
				continue;
			}

			s0 = tmp;
		}

		if (1);

		if (s6 != s0) {
			pass = s4 != 0;
			s4 = 0;

			if (pass) {
				roomSetOnscreen(s6, arg0->draworder, &box1);
				func0f1632d4(arg0->roomnum, s6, arg0->draworder + 1, &box1);
			}

			s6 = s0;
		}

		if (PORTAL_IS_CLOSED(portalnum)) {
			continue;
		}

		if (s0 == arg0->roomnums[0]
				|| s0 == arg0->roomnums[1]
				|| s0 == arg0->roomnums[2]
				|| s0 == arg0->roomnums[3]
				|| s0 == arg0->roomnums[4]) {
			continue;
		}

		if (g_BgPortals[portalnum].flags & PORTALFLAG_02) {
			box2.xmin = arg0->screenbox.xmin;
			box2.ymin = arg0->screenbox.ymin;
			box2.xmax = arg0->screenbox.xmax;
			box2.ymax = arg0->screenbox.ymax;
			unk02 = true;
		} else {
			unk02 = g_PortalGetScreenBbox(portalnum, &box2);
		}

		if (unk02) {
			boxGetIntersection(&box2, &arg0->screenbox);

			if (box2.xmin < box2.xmax && box2.ymin < box2.ymax) {
				if (s4 == 0) {
					box1.xmin = box2.xmin;
					box1.ymin = box2.ymin;
					box1.xmax = box2.xmax;
					box1.ymax = box2.ymax;
				} else {
					boxExpand(&box1, &box2);
				}

				s4++;
			}
		}
	}

	if (s4 != 0) {
		roomSetOnscreen(s6, arg0->draworder, &box1);
		func0f1632d4(arg0->roomnum, s6, arg0->draworder + 1, &box1);
	}
}

bool func0f163904(void)
{
	if (var800a4cf0.unk04 == var800a4cf0.index) {
		return false;
	}

	func0f163528(&var800a4cf0.unk10[var800a4cf0.unk04]);

	var800a4cf0.unk04++;

	if (var800a4cf0.unk04 == ARRAYCOUNT(var800a4cf0.unk10)) {
		var800a4cf0.unk04 = 0;
	}

	return true;
}

/**
 * Choose which rooms should be placed on standby and which are candidates for
 * loading.
 *
 * All offscreen neighbours of onscreen rooms are placed on standby and are
 * nominated for loading. Any tinted glass in these rooms will be unpaused.
 *
 * If the portal between the onscreen room and the offscreen room is blocked
 * (ie. a closed door or opaque glass) then nominate the neighbours of the
 * offscreen room for loading too. This is necessary because opening the door or
 * destroying the glass may make many rooms visible at once, and only one room
 * is loaded per tick.
 */
void bgChooseRoomsToLoad(void)
{
	s32 i;
	s32 j;
	u32 stack;

	g_BgNumRoomLoadCandidates = 0;

	for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
		if ((g_BgPortals[i].flags & PORTALFLAG_SKIP) == 0) {
			s32 roomnum1 = g_BgPortals[i].roomnum1;
			s32 roomnum2 = g_BgPortals[i].roomnum2;
			s32 portalnum;

			if ((g_Rooms[roomnum1].flags & ROOMFLAG_ONSCREEN) && (g_Rooms[roomnum2].flags & ROOMFLAG_ONSCREEN) == 0) {
				// From room1 to room2
				g_Rooms[roomnum2].flags |= ROOMFLAG_STANDBY;

				if (g_Rooms[roomnum2].loaded240 == 0) {
					g_Rooms[roomnum2].flags |= ROOMFLAG_LOADCANDIDATE;
					g_BgNumRoomLoadCandidates++;
				}

				roomUnpauseProps(roomnum2, true);

				if (PORTAL_IS_CLOSED(i)) {
					for (j = 0; j < g_Rooms[roomnum2].numportals; j++) {
						portalnum = g_RoomPortals[g_Rooms[roomnum2].roomportallistoffset + j];

						if (roomnum2 == g_BgPortals[portalnum].roomnum1) {
							if (g_Rooms[g_BgPortals[portalnum].roomnum2].loaded240 == 0) {
								g_Rooms[g_BgPortals[portalnum].roomnum2].flags |= ROOMFLAG_LOADCANDIDATE;
								g_BgNumRoomLoadCandidates++;
							}
						} else {
							if (g_Rooms[g_BgPortals[portalnum].roomnum1].loaded240 == 0) {
								g_Rooms[g_BgPortals[portalnum].roomnum1].flags |= ROOMFLAG_LOADCANDIDATE;
								g_BgNumRoomLoadCandidates++;
							}
						}
					}
				}
			} else if ((g_Rooms[roomnum2].flags & ROOMFLAG_ONSCREEN)
					&& (g_Rooms[roomnum1].flags & ROOMFLAG_ONSCREEN) == 0) {
				// From room2 to room1
				g_Rooms[roomnum1].flags |= ROOMFLAG_STANDBY;

				if (g_Rooms[roomnum1].loaded240 == 0) {
					g_Rooms[roomnum1].flags |= ROOMFLAG_LOADCANDIDATE;
					g_BgNumRoomLoadCandidates++;
				}

				roomUnpauseProps(roomnum1, true);

				if (PORTAL_IS_CLOSED(i)) {
					for (j = 0; j < g_Rooms[roomnum1].numportals; j++) {
						portalnum = g_RoomPortals[g_Rooms[roomnum1].roomportallistoffset + j];

						if (roomnum1 == g_BgPortals[portalnum].roomnum1) {
							if (g_Rooms[g_BgPortals[portalnum].roomnum1].loaded240 == 0) {
								g_Rooms[g_BgPortals[portalnum].roomnum1].flags |= ROOMFLAG_LOADCANDIDATE;
								g_BgNumRoomLoadCandidates++;
							}
						} else {
							if (g_Rooms[g_BgPortals[portalnum].roomnum1].loaded240 == 0) {
								g_Rooms[g_BgPortals[portalnum].roomnum2].flags |= ROOMFLAG_LOADCANDIDATE;
								g_BgNumRoomLoadCandidates++;
							}
						}
					}
				}
			}
		}
	}

	// Update visibility per player
	if (g_Vars.mplayerisrunning) {
		u8 flag1 = 0x01 << g_Vars.currentplayernum;
		u8 flag2 = 0x10 << g_Vars.currentplayernum;

		for (i = 0; i < g_Vars.roomcount; i++) {
			if (g_Rooms[i].flags & ROOMFLAG_ONSCREEN) {
				g_MpRoomVisibility[i] |= flag1;
			} else {
				g_MpRoomVisibility[i] &= ~flag1;
			}

			if (g_Rooms[i].flags & ROOMFLAG_STANDBY) {
				g_MpRoomVisibility[i] |= flag2;
			} else {
				g_MpRoomVisibility[i] &= ~flag2;
			}
		}
	}
}

void bgTickPortals(void)
{
	s32 i;
	s32 room;
	struct screenbox box;
	struct player *player = g_Vars.currentplayer;

	currentPlayerCalculateScreenProperties();

	box.xmin = player->screenxminf;
	box.ymin = player->screenyminf;
	box.xmax = player->screenxmaxf;
	box.ymax = player->screenymaxf;

	viGetZRange(&var800a4cf0.zrange);
	var800a4cf0.zrange.far = var800a4cf0.zrange.far / g_Vars.currentplayerstats->scale_bg2gfx;

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~(ROOMFLAG_DISABLEDBYSCRIPT | ROOMFLAG_ONSCREEN | ROOMFLAG_STANDBY | ROOMFLAG_LOADCANDIDATE);
		g_Rooms[i].portalrecursioncount = 0;
		g_Rooms[i].unk06 = 0;
		g_Rooms[i].unk07 = 1;
	}

	if (player->visionmode == VISIONMODE_XRAY) {
		bgTickPortalsXray();
	} else {
		if (var8007fc34 < var8007fc30) {
			var8007fc34 = var8007fc30;
		}

		var8007fc2c = 0;
		var8007fc30 = 0;
		var800a4ce6 = 0;
		var800a4ce4 = 32767;
		var800a4640.unk2d0.roomnum = -1;
		var800a4640.unk2d0.draworder = 255;
		var800a4cf0.unk00 = 0;
		var800a4cf0.index = 0;
		var800a4cf0.unk04 = 0;
		g_BgRoomTestsDisabled = false;
		var800a4640.unk2d0.box.xmin = box.xmin;
		var800a4640.unk2d0.box.ymin = box.ymin;
		var800a4640.unk2d0.box.xmax = box.xmax;
		var800a4640.unk2d0.box.ymax = box.ymax;

		bgExecuteCommands();

		if (!g_BgRoomTestsDisabled) {
			if (g_BgPortals[0].verticesoffset == 0) {
				for (room = 1; room < g_Vars.roomcount; room++) {
					if (func0f15cd90(room, &box)
							&& ((g_StageIndex != STAGEINDEX_INFILTRATION && g_StageIndex != STAGEINDEX_RESCUE && g_StageIndex != STAGEINDEX_ESCAPE) || room != 0xf)
							&& (g_StageIndex != STAGEINDEX_SKEDARRUINS || room != 0x02)
							&& ((g_StageIndex != STAGEINDEX_DEFECTION && g_StageIndex != STAGEINDEX_EXTRACTION) || room != 0x01)
							&& (g_StageIndex != STAGEINDEX_ATTACKSHIP || room != 0x71)) {
						roomSetOnscreen(room, 0, &box);
					}
				}
			} else {
				roomSetOnscreen(g_CamRoom, 0, &box);
				var800a4cf0.unk00 = 0;
				var800a4cf0.index = 0;
				var800a4cf0.unk04 = 0;
				func0f1632d4(g_CamRoom, g_CamRoom, 1, &box);

				while (func0f163904());
			}
		}

		bgChooseRoomsToLoad();
	}
}

Gfx *func0f164150(Gfx *gdl)
{
	gdl = bgRenderScene(gdl);
	gdl = currentPlayerScissorToViewport(gdl);

	if (g_Vars.currentplayerindex == 0) {
		var8007fc28 -= g_Vars.lvupdate240;
	}

	if (var8007fc28 < 0) {
		var8007fc28 = 0;
	}

	// Consider loading one room by finding the load candidate that is closest to the player
	if (var8007fc28 == 0 && var8007fc10 == 4 && g_Vars.tickmode == TICKMODE_NORMAL && IS8MB()) {
		struct player *player = g_Vars.currentplayer;
		s32 i;
		f32 value;
		struct coord dist;
		f32 bestvalue = MAXFLOAT;
		s32 bestroomnum = 0;
		f32 radius;

		if (g_BgNumRoomLoadCandidates) {
			for (i = 1; i < g_Vars.roomcount; i++) {
				if (!g_Rooms[i].loaded240 && (g_Rooms[i].flags & ROOMFLAG_LOADCANDIDATE)) {
					dist.x = g_Vars.currentplayer->prop->pos.x - g_Rooms[i].centre.x;
					dist.y = g_Vars.currentplayer->prop->pos.y - g_Rooms[i].centre.y;
					dist.z = g_Vars.currentplayer->prop->pos.z - g_Rooms[i].centre.z;

					value = dist.f[0] * dist.f[0] + dist.f[1] * dist.f[1] + dist.f[2] * dist.f[2];

					radius = g_Rooms[i].radius;

					if (var8009dd6c + radius < player->projectionmtx->m[2][0] * g_Rooms[i].centre.f[0]
							+ player->projectionmtx->m[2][1] * g_Rooms[i].centre.f[1]
							+ player->projectionmtx->m[2][2] * g_Rooms[i].centre.f[2]) {
						value *= 3.0f;
					}

					if (var8009dd4c + radius < var8009dd40.f[0] * g_Rooms[i].centre.f[0]
							+ var8009dd40.f[1] * g_Rooms[i].centre.f[1]
							+ var8009dd40.f[2] * g_Rooms[i].centre.f[2]) {
						value *= 1.5f;
					}

					if (var8009dd5c + radius < var8009dd50.f[0] * g_Rooms[i].centre.f[0]
							+ var8009dd50.f[1] * g_Rooms[i].centre.f[1]
							+ var8009dd50.f[2] * g_Rooms[i].centre.f[2]) {
						value *= 1.5f;
					}

					if (var8009dd2c + radius < var8009dd20.f[0] * g_Rooms[i].centre.f[0]
							+ var8009dd20.f[1] * g_Rooms[i].centre.f[1]
							+ var8009dd20.f[2] * g_Rooms[i].centre.f[2]) {
						value *= 2.0f;
					}

					if (var8009dd3c + radius < var8009dd30.f[0] * g_Rooms[i].centre.f[0]
							+ var8009dd30.f[1] * g_Rooms[i].centre.f[1]
							+ var8009dd30.f[2] * g_Rooms[i].centre.f[2]) {
						value *= 2.0f;
					}

					if (value < bestvalue) {
						bestvalue = value;
						bestroomnum = i;
					}
				}
			}
		}

		if (bestroomnum != 0) {
			bgLoadRoom(bestroomnum);
			var8007fc28 = 64;
		}
	}

	return gdl;
}

/**
 * @dangerous: This function assumes that the passed len is the allocated length
 * minus one. ie. It assumes there is space to write the -1 terminator once the
 * length is reached.
 *
 * This is only called from two places, both with len=100, so you'd need to have
 * over 100 rooms active at the same time before this would overflow the array.
 */
s32 roomsGetActive(s16 *rooms, s32 len)
{
	s32 i;

	for (i = 0; i < g_NumActiveRooms && i < len; i++) {
		rooms[i] = g_ActiveRoomNums[i];
	}

	rooms[i] = -1;

	return i;
}

s32 roomGetNeighbours(s32 roomnum, s16 *dstrooms, s32 len)
{
	s32 count = 0;
	s32 i;
	s32 j;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		s32 neighbournum = g_BgPortals[portalnum].roomnum1;

		if (neighbournum == roomnum) {
			neighbournum = g_BgPortals[portalnum].roomnum2;
		}

		for (j = 0; j < count; j++) {
			if (dstrooms[j] == neighbournum) {
				goto end;
			}
		}

		dstrooms[count] = neighbournum;
		count++;

		if (count >= len) {
			break;
		}

end:
		;
	}

	dstrooms[count] = -1;

	return count;
}

bool roomsAreNeighbours(s32 roomnum1, s32 roomnum2)
{
	s32 i;

	for (i = 0; i < g_Rooms[roomnum1].numportals; i++) {
		s32 portalnum = g_RoomPortals[g_Rooms[roomnum1].roomportallistoffset + i];

		if (g_BgPortals[portalnum].roomnum1 == roomnum2 || g_BgPortals[portalnum].roomnum2 == roomnum2) {
			return true;
		}
	}

	return false;
}

void currentPlayerCalculateScreenProperties(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 width = viGetWidth();
	u32 stack;
	f32 height = viGetHeight();
	u32 stack2;

	player->screenxminf = viGetViewLeft();

	if (player->screenxminf < 0) {
		player->screenxminf = 0;
	}

	if (player->screenxminf > width) {
		player->screenxminf = width;
	}

	player->screenyminf = viGetViewTop();

	if (player->screenyminf < 0) {
		player->screenyminf = 0;
	}

	if (player->screenyminf > height) {
		player->screenyminf = height;
	}

	player->screenxmaxf = viGetViewLeft() + viGetViewWidth();

	if (player->screenxmaxf < 0) {
		player->screenxmaxf = 0;
	}

	if (player->screenxmaxf > width) {
		player->screenxmaxf = width;
	}

	player->screenymaxf = viGetViewTop() + viGetViewHeight();

	if (player->screenymaxf < 0) {
		player->screenymaxf = 0;
	}

	if (player->screenymaxf > height) {
		player->screenymaxf = height;
	}
}

void bgExpandRoomToPortals(s32 roomnum)
{
	s32 i;
	s32 j;
	s32 k;
	s32 count = 0;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		struct portalvertices *pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

		for (j = 0; j < pvertices->count; j++) {
			for (k = 0; k < 3; k++) {
				f32 value = pvertices->vertices[j].f[k];

				if (value < g_Rooms[roomnum].bbmin[k]) {
					g_Rooms[roomnum].bbmin[k] = value;
					count++;
				}

				if (value > g_Rooms[roomnum].bbmax[k]) {
					g_Rooms[roomnum].bbmax[k] = value;
					count++;
				}
			}
		}
	}

	if (count);
}

bool portalExists(s32 portalnum)
{
	s32 i;

	for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
		if (i == portalnum) {
			return true;
		}
	}

	return false;
}

void portalSwapRooms(s32 portal)
{
	s16 tmp = g_BgPortals[portal].roomnum1;
	g_BgPortals[portal].roomnum1 = g_BgPortals[portal].roomnum2;
	g_BgPortals[portal].roomnum2 = tmp;
}

void func0f164ab8(s32 portalnum)
{
	struct coord room1centre;
	struct coord room2centre;
	f32 tmp;
	struct var800a4ccc sp28;
	struct var800a4ccc *ptr;
	f32 tmp1;
	f32 tmp2;
	bool sp18;
	s32 roomnum1;
	s32 roomnum2;

	roomnum1 = g_BgPortals[portalnum].roomnum1;
	roomnum2 = g_BgPortals[portalnum].roomnum2;

	room1centre.x = g_Rooms[roomnum1].centre.x;
	room1centre.y = g_Rooms[roomnum1].centre.y;
	room1centre.z = g_Rooms[roomnum1].centre.z;

	room2centre.x = g_Rooms[roomnum2].centre.x;
	room2centre.y = g_Rooms[roomnum2].centre.y;
	room2centre.z = g_Rooms[roomnum2].centre.z;

	ptr = &var800a4ccc[portalnum];
	sp28.coord.x = ptr->coord.x;
	sp28.coord.y = ptr->coord.y;
	sp28.coord.z = ptr->coord.z;
	sp28.min = ptr->min;
	sp28.max = ptr->max;

	tmp1 = sp28.coord.f[0] * room1centre.f[0] + sp28.coord.f[1] * room1centre.f[1] + sp28.coord.f[2] * room1centre.f[2];

	if (tmp1);

	sp18 = 0;

	if (tmp1 > sp28.max) {
		sp18 = 1;

		portalSwapRooms(portalnum);

		sp28.coord.x = -sp28.coord.x;
		sp28.coord.y = -sp28.coord.y;
		sp28.coord.z = -sp28.coord.z;

		tmp = sp28.min;
		sp28.min = -sp28.max;
		sp28.max = -tmp;
	}

	tmp2 = sp28.coord.f[0] * room2centre.f[0] + sp28.coord.f[1] * room2centre.f[1] + sp28.coord.f[2] * room2centre.f[2];

	if (tmp2 <= sp28.min && sp18) {
		portalSwapRooms(portalnum);
	}

	if (sp18);
}

void room0f164c64(s32 roomnum)
{
	struct portalvertices *pvertices;
	s32 i;
	s32 j;
	s32 k;
	struct var800a4ccc thing;
	s16 portalnum;
	s16 portalnum2;
	f32 tmp;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];

		thing.coord.f[0] = (var800a4ccc + portalnum)->coord.f[0];
		thing.coord.f[1] = (var800a4ccc + portalnum)->coord.f[1];
		thing.coord.f[2] = (var800a4ccc + portalnum)->coord.f[2];
		thing.min = (var800a4ccc + portalnum)->min;
		thing.max = (var800a4ccc + portalnum)->max;

		if (roomnum == g_BgPortals[portalnum].roomnum1) {
			thing.coord.f[0] = -thing.coord.f[0];
			thing.coord.f[1] = -thing.coord.f[1];
			thing.coord.f[2] = -thing.coord.f[2];

			tmp = thing.min;
			thing.min = -thing.max;
			thing.max = -tmp;
		}

		for (j = 0; j < g_Rooms[roomnum].numportals; j++) {
			portalnum2 = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + j];

			if (portalnum2 == portalnum) {
				continue;
			}

			pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum2].verticesoffset);

			for (k = 0; k < pvertices->count; k++) {
				tmp = thing.coord.f[0] * pvertices->vertices[k].f[0]
					+ thing.coord.f[1] * pvertices->vertices[k].f[1]
					+ thing.coord.f[2] * pvertices->vertices[k].f[2];

				if (tmp < thing.min) {
					g_Rooms[roomnum].flags |= ROOMFLAG_0010;
					return;
				}
			}
		}
	}
}

void portalSetOpen(s32 portal, bool open)
{
	g_BgPortals[portal].flags = (g_BgPortals[portal].flags | PORTALFLAG_CLOSED) ^ (open != false);
}

s32 func0f164e70(s32 arg0, s32 arg1, s32 arg2)
{
	return arg0;
}

void func0f164e80(s32 arg0, s32 arg1)
{
	// empty
}

f32 var8007fcb4 = 0;

s32 bg0f164e8c(struct coord *arg0, struct coord *arg1)
{
	s32 bestportalnum = -1;
	s32 count = 0;
	f32 bestthing = MAXFLOAT;
	f32 thisthing;
	s32 i;

	for (i = 0; g_BgPortals[i].verticesoffset; i++) {
		if (portal00017e30(i, arg0, arg1) != 0) {
			thisthing = var8007fcb4;

			if (thisthing < 0) {
				thisthing = -thisthing;
			}

			if (thisthing < bestthing) {
				if (count);
				if (i);
				bestportalnum = i;
				bestthing = thisthing;
				count++;
			}
		}
	}

	return bestportalnum;
}

bool bgIsBboxOverlapping(struct coord *portalbbmin, struct coord *portalbbmax, struct coord *propbbmin, struct coord *propbbmax)
{
	s32 i;

	for (i = 0; i < 3; i++) {
		if (propbbmin->f[i] > portalbbmax->f[i] || propbbmax->f[i] < portalbbmin->f[i]) {
			return false;
		}
	}

	return true;
}

void portalFindBbox(s32 portalnum, struct coord *bbmin, struct coord *bbmax)
{
	struct portalvertices *pvertices;
	s32 i;
	s32 j;

	bbmin->x = MAXFLOAT;
	bbmin->y = MAXFLOAT;
	bbmin->z = MAXFLOAT;

	bbmax->x = MINFLOAT;
	bbmax->y = MINFLOAT;
	bbmax->z = MINFLOAT;

	pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

	for (i = 0; i < pvertices->count; i++) {
		for (j = 0; j < 3; j++) {
			f32 value = pvertices->vertices[i].f[j];

			if (value < bbmin->f[j]) {
				bbmin->f[j] = value;
			}

			if (value > bbmax->f[j]) {
				bbmax->f[j] = value;
			}
		}
	}
}

void bgFindEnteredRooms(struct coord *bbmin, struct coord *bbmax, s16 *rooms, s32 maxlen, bool arg4)
{
	s16 room;
	s16 otherroom;
	s32 portalnum;
	struct coord propbbmin;
	struct coord propbbmax;
	s32 len;
	s32 i;
	s32 j;
	s32 k;
	s32 origlen;
	struct coord portalbbmin;
	struct coord portalbbmax;

	propbbmin.x = bbmin->x;
	propbbmin.y = bbmin->y;
	propbbmin.z = bbmin->z;

	propbbmax.x = bbmax->x;
	propbbmax.y = bbmax->y;
	propbbmax.z = bbmax->z;

	i = 0;

	for (len = 0; rooms[len] != -1; len++);

	while (true) {
		origlen = len;

		for (; i < origlen; i++) {
			room = rooms[i];

			for (j = 0; j < g_Rooms[room].numportals; j++) {
				portalnum = g_RoomPortals[g_Rooms[room].roomportallistoffset + j];

				if (arg4 && PORTAL_IS_CLOSED(portalnum)) {
					continue;
				}

				portalFindBbox(portalnum, &portalbbmin, &portalbbmax);

				if (bgIsBboxOverlapping(&portalbbmin, &portalbbmax, &propbbmin, &propbbmax)) {
					if (room == g_BgPortals[portalnum].roomnum1) {
						otherroom = g_BgPortals[portalnum].roomnum2;
					} else {
						otherroom = g_BgPortals[portalnum].roomnum1;
					}

					for (k = 0; k < len; k++) {
						if (rooms[k] == otherroom) {
							break;
						}
					}

					if (k == len) {
						if (len < maxlen) {
							rooms[len] = otherroom;
							len++;
						}

						if (len >= maxlen) {
							goto end;
						}
					}
				}
			}
		}

		if (len == origlen) {
			break;
		}
	}

end:
	rooms[len] = -1;
}

void bgPreload(void)
{
	if (g_BgPreload) {
		s32 i;

		for (i = 0; i < g_Vars.roomcount; i++) {
			bgLoadRoom(i);
		}
	}
}
