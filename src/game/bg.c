#include <ultra64.h>
#include "constants.h"
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

static bool func0f15d08c(struct coord *a, struct coord *b);
static void room0f164c64(s32 roomnum);
static void bgExpandRoomToPortals(s32 roomnum);
static void bgTickPortals(void);
static void func0f164ab8(s32 portalnum);
static void currentPlayerCalculateScreenProperties(void);
static void bgFindRoomVtxBatches(s32 roomnum);
static Gfx *bgRenderRoomXlu(Gfx *gdl, s32 roomnum);
static Gfx *bgRenderRoomOpaque(Gfx *gdl, s32 roomnum);
static void bgChooseRoomsToLoad(void);
static void bgLoadRoom(s32 roomnum);
static void boxExpand(struct screenbox *a, struct screenbox *b);
static Gfx *currentPlayerScissorWithinViewportF(Gfx *gdl, f32 viewleft, f32 viewtop, f32 viewright, f32 viewbottom);
static void func0f15cd28(void);
static Gfx *func0f164150(Gfx *gdl);

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
s16 g_GlareRooms[100];
u32 *g_BgPrimaryData2;
struct bgroom *g_BgRooms;
struct bgportal *g_BgPortals;
struct var800a4ccc *var800a4ccc;
u8 *g_BgLightsFileData;
s16 *g_RoomPortals;
s16 var800a4ce4;
s16 var800a4ce6;
struct var800a4ce8 *var800a4ce8;
struct portalthing *g_PortalThings;
struct var800a4cf0 var800a4cf0;
s32 g_BgAlwaysRoom;

s32 g_StageIndex = 1;

s32 g_NumRoomsWithGlares = 0;
s32 g_CamRoom = 0x00000001;
struct var800a4640_00 *var8007fc24 = &var800a4640.unk2d0;
s32 var8007fc2c = 0;
s32 var8007fc30 = 0;
s32 var8007fc34 = 0;
u16 var8007fc3c = 0xfffe;
s32 g_NumPortalThings = 0;

static void roomUnpauseProps(u32 roomnum, bool tintedglassonly)
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

static void roomSetOnscreen(s32 roomnum, s32 draworder, struct screenbox *box)
{
	s32 index;

	if ((g_Rooms[roomnum].flags & ROOMFLAG_DISABLEDBYSCRIPT) == 0) {
		g_Rooms[roomnum].flags |= ROOMFLAG_ONSCREEN;

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

static Gfx *bg0f158184(Gfx *gdl, struct xraydata *xraydata)
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

static Gfx *func0f158400(Gfx *gdl, struct xraydata *xraydata, s16 vertices1[3], s16 vertices2[3], s16 vertices3[3], u32 colour1, u32 colour2, u32 colour3)
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

static void bgChooseXrayVtxColour(bool *inrange, s16 vertex[3], u32 *colour, struct xraydata *xraydata)
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

static Gfx *func0f158d9c(Gfx *gdl, struct xraydata *xraydata, s16 arg2[3], s16 arg3[3], s16 arg4[3], s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
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
u32 g_BgCmdResult = BGRESULT_TRUE;

static Gfx *bg0f1598b4(Gfx *gdl, Gfx *gdl2, struct gfxvtx *vertices, s16 arg3[3])
{
	s32 i;
	s32 stack;
	struct xraydata xraydata;
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
	xraydata.unk020 = g_CurrentStage->unk2c;
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

static Gfx *bgRenderRoomXrayPass(Gfx *gdl, s32 roomnum, struct roomblock *block, bool recurse, s16 arg4[3])
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

			sp34 = coords[1];

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
static Gfx *bgRenderRoomInXray(Gfx *gdl, s32 roomnum)
{
	struct coord sp54;
	s16 sp40[3];
	struct player *player = g_Vars.currentplayer;

	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return gdl;
	}

	if (g_Rooms[roomnum].loaded240 == 0) {
		return gdl;
	}

	sp54.x = player->eraserpos.x - g_BgRooms[roomnum].pos.x;
	sp54.y = player->eraserpos.y - g_BgRooms[roomnum].pos.y;
	sp54.z = player->eraserpos.z - g_BgRooms[roomnum].pos.z;

	sp40[0] = sp54.f[0];
	sp40[1] = sp54.f[1];
	sp40[2] = sp54.f[2];

	gdl = roomApplyMtx(gdl, roomnum);
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->opablocks, true, sp40);
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->xlublocks, true, sp40);

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
	gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

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

	gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (var800a4ce4); \
	if (var8007fc2c); \
	for (i = var800a4ce6; i >= var800a4ce4; i--) {
		for (k = 0; k < var8007fc2c; k++) {
			struct var800a4640_00 *thing = &var800a4640.unk000[k];

			if (thing->draworder == i) {
				gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

				gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);

				gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->perspmtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

				if (thing->roomnum == -1) {
					gdl = propsRender(gdl, 0, RENDERPASS_XLU, roomnumsbyprop);
				}

				gdl = propsRender(gdl, thing->roomnum, RENDERPASS_XLU, roomnumsbyprop);
			}
		}
	}

	gdl = skyRenderSuns(gdl, true);

	return gdl;
}

static Gfx *bgRenderScene(Gfx *gdl)
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
	if (g_BgAlwaysRoom >= 0 && !USINGDEVICE(DEVICE_NIGHTVISION) && !USINGDEVICE(DEVICE_IRSCANNER)) {
		gdl = envStopFog(gdl);
		gdl = vi0000ab78(gdl);

		if (g_StarsActive) {
			gdl = text0f153628(gdl);

			gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

			gdl = playerLoadMatrix(gdl);
			gdl = envStopFog(gdl);
			gdl = starsRender(gdl);
			gdl = text0f153780(gdl);
			gdl = vi0000ab78(gdl);
		}

		gdl = bgRenderRoomOpaque(gdl, g_BgAlwaysRoom);

		gSPPerspNormalize(gdl++, g_ViPerspScale);
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
		gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->perspmtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gdl = envStopFog(gdl);

		if (firstroomnum == thing->roomnum) {
			gdl = propsRender(gdl, 0, RENDERPASS_OPA_PREBG, roomnumsbyprop);
		}

		gdl = propsRender(gdl, thing->roomnum, RENDERPASS_OPA_PREBG, roomnumsbyprop);

		// Render BG opaque components
		gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
		gdl = envStartFog(gdl, false);

		gdl = bgRenderRoomOpaque(gdl, thing->roomnum);

		// Render prop opaque components - post BG pass
		gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->perspmtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = envStopFog(gdl);

		if (firstroomnum == thing->roomnum) {
			gdl = propsRender(gdl, 0, RENDERPASS_OPA_POSTBG, roomnumsbyprop);
		}

		gdl = propsRender(gdl, thing->roomnum, RENDERPASS_OPA_POSTBG, roomnumsbyprop);
	}

	gdl = envStopFog(gdl);
	gdl = currentPlayerScissorToViewport(gdl);

	// Render wall hits
	gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
		for (i = 0; i < var8007fc2c; i++) {
			roomnum = roomnums[i];
			gdl = wallhitRenderBgHits(var800a4640.unk000[roomnum].roomnum, gdl);
		}
	}

	// In NTSC 1.0 and newer this hack fixes a regalloc issue.
	// In NTSC beta this same regalloc issue occurs.
	// Applying the hack in NTSC beta fixes the regalloc issue but generates
	// very different code.
	for (i = var8007fc2c - 1; i >= 0; i--) {
		roomnum = roomnums[i];

		gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->orthomtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		thing = &var800a4640.unk000[roomnum];

		// Render BG translucent components
		gdl = currentPlayerScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
		gdl = envStartFog(gdl, true);

		gdl = bgRenderRoomXlu(gdl, thing->roomnum);

		gSPMatrix(gdl++, osVirtualToPhysical(g_Vars.currentplayer->perspmtxl), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = envStopFog(gdl);

		// Render prop translucent components
		if (firstroomnum == thing->roomnum) {
			gdl = propsRender(gdl, 0, RENDERPASS_XLU, roomnumsbyprop);
		}

		gdl = propsRender(gdl, thing->roomnum, RENDERPASS_XLU, roomnumsbyprop);

		if (!g_Vars.mplayerisrunning) {
			artifactsCalculateGlaresForRoom(thing->roomnum);

			if (g_NumRoomsWithGlares < 100) {
				g_GlareRooms[g_NumRoomsWithGlares++] = thing->roomnum;
			}
		}
	}

	return gdl;
}

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

static void bgLoadFile(void *memaddr, u32 offset, u32 len)
{
	fileLoadPartToAddr(g_Stages[g_StageIndex].bgfileid, memaddr, offset, len);
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

	g_BgUnloadDelay240 = 120;
	g_BgUnloadDelay240_2 = 120;

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
	section2 = mempAlloc(inflatedsize + section2compsize, MEMPOOL_STAGE);
	scratch = (u32) section2 + inflatedsize;

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
	}

	if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
		// Remove two unnecessary portals that cause rooms to be rendered when they needn't be
		s32 i;
		s32 numportals = 0;

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			numportals++;
		}

		g_BgPortals[0x13] = g_BgPortals[numportals - 1]; // unlink rooms F and 13
		g_BgPortals[0x15] = g_BgPortals[numportals - 2]; // unlink rooms 10 and 13
		g_BgPortals[numportals - 2].verticesoffset = 0;
	}

	g_BgAlwaysRoom = -1;

	if (stagenum == STAGE_INFILTRATION
			|| stagenum == STAGE_RESCUE
			|| stagenum == STAGE_ESCAPE
			|| stagenum == STAGE_MAIANSOS) {
		g_BgAlwaysRoom = 0x0f;
	} else if (stagenum == STAGE_SKEDARRUINS
			|| stagenum == STAGE_WAR) {
		g_BgAlwaysRoom = 0x02;
	} else if (stagenum == STAGE_DEFECTION
			|| stagenum == STAGE_EXTRACTION
			|| stagenum == STAGE_MBR) {
		g_BgAlwaysRoom = 0x01;
	} else if (stagenum == STAGE_ATTACKSHIP) {
		g_BgAlwaysRoom = 0x71;
	}
}

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

	for (i = 0; i < 4; i++) {
		g_Vars.playerstats[i].scale_bg2gfx = g_Stages[g_StageIndex].unk18;
	}

	var8005ef10[0] = 65536;

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

		if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
			// Compensate for the two removed portals in bgReset
			offset += sizeof(struct bgportal) * 2;
		}

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
			tmp->coord = tmp2.coord;
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
		section3 = mempAlloc(inflatedsize + section3compsize, MEMPOOL_STAGE);
		scratch = section3 + inflatedsize;

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

	wallhitReset();
	func0f002a98();
	func0f001c0c();
}

void bgStop(void)
{
	var8005ef10[0] = 65536;
}

f32 func0f15c888(void)
{
	return g_Stages[g_StageIndex].unk1c / g_Stages[g_StageIndex].unk14;
}

void currentPlayerSetScaleBg2Gfx(f32 scale)
{
	g_Vars.currentplayerstats->scale_bg2gfx = g_Stages[g_StageIndex].unk18 * scale;
	var8005ef10[0] = 65536 * g_Vars.currentplayerstats->scale_bg2gfx;
}

void func0f15c920(void)
{
	var8007fc3c++;

	if (var8007fc3c == 0xffff) {
		var8007fc3c = 1;
		func0f15cd28();
	}
}

void bgTick(void)
{
	s32 tickmode;

	g_NumActiveRooms = 0;

	func0f15c920();

	tickmode = g_Vars.tickmode;

	g_CamRoom = g_Vars.currentplayer->cam_room;

	bgTickPortals();
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

Gfx *currentPlayerScissorToViewport(Gfx *gdl)
{
	return currentPlayerScissorWithinViewport(gdl,
			g_Vars.currentplayer->viewleft,
			g_Vars.currentplayer->viewtop,
			g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth,
			g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight);
}

static Gfx *currentPlayerScissorWithinViewportF(Gfx *gdl, f32 viewleft, f32 viewtop, f32 viewright, f32 viewbottom)
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

static void func0f15cd28(void)
{
	s32 i;

	for (i = 0; i < g_NumPortalThings; i++) {
		g_PortalThings[i].unk06 = -1;
		g_PortalThings[i].unk04 = 0;
		g_PortalThings[i].unk00 = 0;
	}
}

static bool func0f15cd90(u32 room, struct screenbox *screen)
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

static bool func0f15d08c(struct coord *a, struct coord *b)
{
	Mtxf *matrix = g_Vars.currentplayer->worldtoscreenmtx;

	*b = *a;

	mtx4TransformVecInPlace(matrix, b);
	cam0f0b4d68(b, b->f);

	if (b->z > 0) {
		return false;
	}

	return true;
}

static bool g_PortalGetScreenBbox(s32 portalnum, struct screenbox *box)
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

static bool boxGetIntersection(struct screenbox *a, struct screenbox *b)
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

static void boxExpand(struct screenbox *a, struct screenbox *b)
{
	a->xmin = a->xmin < b->xmin ? a->xmin : b->xmin;
	a->ymin = a->ymin < b->ymin ? a->ymin : b->ymin;
	a->xmax = a->xmax > b->xmax ? a->xmax : b->xmax;
	a->ymax = a->ymax > b->ymax ? a->ymax : b->ymax;
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

u32 bgInflate(u8 *src, u8 *dst, u32 len)
{
	u32 result;
	u8 scratch[5120];

	if (rzipIs1173(src)) {
		result = rzipInflate(src, dst, &scratch);
	} else {
		result = len;
		bcopy(src, dst, len);
	}

	return result;
}

static Gfx *roomGetNextGdlInBlock(struct roomblock *block, Gfx *start, Gfx *end)
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

static Gfx *roomGetNextGdlInLayer(s32 roomnum, Gfx *start, u32 types)
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

static struct gfxvtx *roomFindVerticesForGdl(s32 roomnum, Gfx *gdl)
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

Gfx gbi_26a40[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, 0, SCALE, 0, TEXEL1, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	0,
};

Gfx gbi_26a58[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_TERR2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_TERR2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	0,
};

Gfx gbi_26b90[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	0,
};

Gfx gbi_26c78[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	0,
};

Gfx gbi_26d20[] = {
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	0,
};

Gfx gbi_26dc8[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
	0,
};

Gfx gbi_26df0[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_TERR, G_RM_AA_ZB_OPA_TERR2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
	0,
};

Gfx gbi_26e18[] = {
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
	gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
	0,
};

Gfx gbi_26e30[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_AA_OPA_TERR, G_RM_AA_OPA_TERR2),
	gsDPSetRenderMode(GBL_c1(G_BL_CLR_IN, G_BL_A_SHADE, G_BL_CLR_FOG, G_BL_1MA), G_RM_AA_OPA_TERR2),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
	0,
};

Gfx gbi_26e68[] = {
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(1, 0, SCALE, 0, 0, 0, 0, SHADE, 1, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	gsDPSetCombineLERP(1, 0, SCALE, 0, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	0,
};

Gfx gbi_26f50[] = {
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
	gsDPSetCombineLERP(TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SCALE, 0, TEXEL0, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
	gsDPSetCombineLERP(1, 0, SCALE, 0, 0, 0, 0, SHADE, 1, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEI2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATEIA2),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SCALE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0),
	gsDPSetCombineLERP(1, 0, SCALE, 0, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
	gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
	0,
};

Gfx *var80081018[] = {
	gbi_26a40,
	gbi_26a58,
	gbi_26dc8,
	gbi_26df0,
	gbi_26e18,
	gbi_26b90,
	gbi_26c78,
	gbi_26d20,
	gbi_26e30,
	gbi_26e68,
	gbi_26f50,
};

static void gfxReplaceGbiCommands(Gfx *startgdl, Gfx *endgdl, s32 type)
{
	Gfx *gdl = startgdl;

	while ((endgdl && gdl < endgdl) || (!endgdl && *(s8 *)gdl != G_ENDDL)) {
		Gfx *src = var80081018[type];

		while (src->words.w0 != 0) {
			if (src->words.w0 == gdl->words.w0 && src->words.w1 == gdl->words.w1) {
				*gdl = src[1];
			}

			src += 2;
		}

		gdl++;
	}
}

static void gfxReplaceGbiCommandsRecursively(struct roomblock *block, s32 type)
{
	if (block->type == ROOMBLOCKTYPE_PARENT);

	while (true) {
		if (!block) {
			return;
		}

		switch (block->type) {
		case ROOMBLOCKTYPE_LEAF:
			gfxReplaceGbiCommands(block->gdl, NULL, type);
			block = block->next;
			break;
		case ROOMBLOCKTYPE_PARENT:
			gfxReplaceGbiCommandsRecursively(block->child, type);
			block = block->next;
			break;
		default:
			return;
		}
	}
}

static void bgLoadRoom(s32 roomnum)
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

	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return;
	}

	// Determine how much memory to allocate.
	// It must be big enough to fit both the inflated and compressed room data.
	size = g_Rooms[roomnum].gfxdatalen;

	allocation = mempAlloc(size, MEMPOOL_STAGE);

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

		g_Rooms[roomnum].loaded240 = 1;

		if (g_Rooms[roomnum].gfxdatalen != size) {
			mempRealloc(allocation, g_Rooms[roomnum].gfxdatalen, MEMPOOL_STAGE);
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
}

static Gfx *bgRenderRoomPass(Gfx *gdl, s32 roomnum, struct roomblock *block, bool arg3)
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
static Gfx *bgRenderRoomOpaque(Gfx *gdl, s32 roomnum)
{
	if (g_Rooms[roomnum].loaded240 == 0) {
		return gdl;
	}

	gdl = roomApplyMtx(gdl, roomnum);

	gdl = lightsSetForRoom(gdl, roomnum);
	gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->opablocks, true);
	gdl = lightsSetDefault(gdl);

	return gdl;
}

/**
 * Render the transparency layer of the room.
 */
static Gfx *bgRenderRoomXlu(Gfx *gdl, s32 roomnum)
{
	if (roomnum == 0 || roomnum >= g_Vars.roomcount) {
		return gdl;
	}

	if (g_Rooms[roomnum].loaded240) {
		if (g_Rooms[roomnum].gfxdata->xlublocks == NULL) {
			return gdl;
		}

		roomHighlight(roomnum);

		gdl = roomApplyMtx(gdl, roomnum);
		gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->xlublocks, true);
	}

	return gdl;
}

static s32 bgPopulateVtxBatchType(s32 roomnum, struct vtxbatch *batches, Gfx *gdl, s32 batchindex, struct gfxvtx *vertices, s32 type)
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

static void bgFindRoomVtxBatches(s32 roomnum)
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

			batches = mempAlloc((batchindex * sizeof(struct vtxbatch) + 0xf) & ~0xf, MEMPOOL_STAGE);

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

									hitthing->unk00 = sp8c;
									hitthing->unk0c = sp80;
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

									hitthing->unk00 = sp84;
									hitthing->unk0c = sp78;
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

static bool bgTestHitInVtxBatch(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct vtxbatch *batch, s32 roomnum, struct hitthing *hitthing)
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

												hitthing->unk00 = spb0;
												hitthing->unk0c = spa4;
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

static s32 bg0f1612e4(struct coord *bbmin, struct coord *bbmax, struct coord *arg2, struct coord *arg3, struct coord *arg4, struct coord *arg5)
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

	spb8 = *frompos;

	spac = *topos;

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
								hitthing->unk00 = sp60.unk00;
								hitthing->unk0c = sp60.unk0c;
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
	copy = *pos;

	return copy.f[0] >= g_Rooms[roomnum].bbmin[0]
		&& copy.f[0] <= g_Rooms[roomnum].bbmax[0]
		&& copy.f[2] >= g_Rooms[roomnum].bbmin[2]
		&& copy.f[2] <= g_Rooms[roomnum].bbmax[2]
		&& copy.f[1] >= g_Rooms[roomnum].bbmin[1]
		&& copy.f[1] <= g_Rooms[roomnum].bbmax[1];
}

static bool func0f161c08(struct coord *arg0, s16 roomnum)
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

static bool func0f161d30(struct coord *arg0, s16 roomnum)
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

	pos = *posarg;

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

static void bgCmdDisableRoom(s32 roomnum)
{
	g_Rooms[roomnum].flags |= ROOMFLAG_DISABLEDBYSCRIPT;
}

static void bgCmdReset(void)
{
	var800a65c0.xmin = g_Vars.currentplayer->screenxminf;
	var800a65c0.ymin = g_Vars.currentplayer->screenyminf;
	var800a65c0.xmax = g_Vars.currentplayer->screenxmaxf;
	var800a65c0.ymax = g_Vars.currentplayer->screenymaxf;

	g_BgCmdResult = BGRESULT_TRUE;
}

static void bgCmdRestrictToPortal(s32 portalnum)
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

static void bgCmdTryEnableRoom(s32 roomnum)
{
	if (g_BgCmdResult == BGRESULT_TRUE && func0f15cd90(roomnum, &var800a65c0)) {
		roomSetOnscreen(roomnum, 0, &var800a65c0);
		g_ActiveRoomNums[g_NumActiveRooms++] = roomnum;
	}
}

static void bgExecuteCommands(void)
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
		} else if (g_CamRoom == 0x49) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x4c);
			bgCmdTryEnableRoom(0x48);
			bgCmdTryEnableRoom(0x4e);
			bgCmdTryEnableRoom(0x4d);
			bgCmdDisableRoom(0x4f);
		} else if (g_CamRoom == 0x4a) {
			bgCmdReset();
			bgCmdTryEnableRoom(0x4c);
			bgCmdTryEnableRoom(0x48);
			bgCmdTryEnableRoom(0x4e);
			bgCmdTryEnableRoom(0x4d);
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

static void bgTickPortalsXray(void)
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
	s32 i;
	struct var800a4640 *thing;

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
		player->eraserdepth = -500.0f / g_Vars.currentplayer->c_lodscalez;
	} else {
		player->eraserdepth = -500.0f;
	}

	eraserpos.f[0] = 0.0f;
	eraserpos.f[1] = 0.0f;
	eraserpos.f[2] = player->eraserdepth;

	mtx4TransformVecInPlace(g_Vars.currentplayer->projectionmtx, &eraserpos);

	player->eraserpos.f[0] = eraserpos.f[0];
	player->eraserpos.f[1] = eraserpos.f[1];
	player->eraserpos.f[2] = eraserpos.f[2];

	player->eraserpropdist = g_CurrentStage->eraserpropdist;
	player->eraserbgdist = (f32) g_CurrentStage->eraserpropdist + g_CurrentStage->unk30;

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

static void func0f1632d4(s16 roomnum1, s16 roomnum2, s16 draworder, struct screenbox *box)
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

static void func0f163528(struct var800a4d00 *arg0)
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

static bool func0f163904(void)
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
static void bgChooseRoomsToLoad(void)
{
	s32 i;
	s32 j;

	for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
		if ((g_BgPortals[i].flags & PORTALFLAG_SKIP) == 0) {
			s32 roomnum1 = g_BgPortals[i].roomnum1;
			s32 roomnum2 = g_BgPortals[i].roomnum2;
			s32 portalnum;

			if ((g_Rooms[roomnum1].flags & ROOMFLAG_ONSCREEN) && (g_Rooms[roomnum2].flags & ROOMFLAG_ONSCREEN) == 0) {
				// From room1 to room2
				g_Rooms[roomnum2].flags |= ROOMFLAG_STANDBY;
				roomUnpauseProps(roomnum2, true);
			} else if ((g_Rooms[roomnum2].flags & ROOMFLAG_ONSCREEN) && (g_Rooms[roomnum1].flags & ROOMFLAG_ONSCREEN) == 0) {
				// From room2 to room1
				g_Rooms[roomnum1].flags |= ROOMFLAG_STANDBY;
				roomUnpauseProps(roomnum1, true);
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

static void bgTickPortals(void)
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
					if (func0f15cd90(room, &box) && room != g_BgAlwaysRoom) {
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

static Gfx *func0f164150(Gfx *gdl)
{
	gdl = bgRenderScene(gdl);
	gdl = currentPlayerScissorToViewport(gdl);

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

static void currentPlayerCalculateScreenProperties(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 width = g_ViBackData->x;
	u32 stack;
	f32 height = g_ViBackData->y;
	u32 stack2;

	player->screenxminf = g_ViBackData->viewleft;

	if (player->screenxminf < 0) {
		player->screenxminf = 0;
	}

	if (player->screenxminf > width) {
		player->screenxminf = width;
	}

	player->screenyminf = g_ViBackData->viewtop;

	if (player->screenyminf < 0) {
		player->screenyminf = 0;
	}

	if (player->screenyminf > height) {
		player->screenyminf = height;
	}

	player->screenxmaxf = g_ViBackData->viewleft + g_ViBackData->viewx;

	if (player->screenxmaxf < 0) {
		player->screenxmaxf = 0;
	}

	if (player->screenxmaxf > width) {
		player->screenxmaxf = width;
	}

	player->screenymaxf = g_ViBackData->viewtop + g_ViBackData->viewy;

	if (player->screenymaxf < 0) {
		player->screenymaxf = 0;
	}

	if (player->screenymaxf > height) {
		player->screenymaxf = height;
	}
}

static void bgExpandRoomToPortals(s32 roomnum)
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

static void portalSwapRooms(s32 portal)
{
	s16 tmp = g_BgPortals[portal].roomnum1;
	g_BgPortals[portal].roomnum1 = g_BgPortals[portal].roomnum2;
	g_BgPortals[portal].roomnum2 = tmp;
}

static void func0f164ab8(s32 portalnum)
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

	room1centre = g_Rooms[roomnum1].centre;

	room2centre = g_Rooms[roomnum2].centre;

	ptr = &var800a4ccc[portalnum];
	sp28.coord = ptr->coord;
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

static void room0f164c64(s32 roomnum)
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

	propbbmin = *bbmin;

	propbbmax = *bbmax;

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

u8 g_BgPreloadInfiltration[][2] = {
	{0x01, 0x0e},
	{0x10, 0x26},
	{0x2e, 0x2e},
	{0x31, 0x31},
	{0x40, 0x51},
	{0x60, 0x66},
	{0x78, 0x78},
	{0x8c, 0x8d},
	{0x8f, 0x9a},
	{0xfc, 0xff},
};

u16 g_BgPreloadRescue[][2] = {
	{0x01, 0x02},
	{0x04, 0x0b},
	{0x0e, 0x0e},
	{0x17, 0x1c},
	{0x2e, 0x2e},
	{0x31, 0x31},
	{0x40, 0x4b},
	{0x51, 0x5a},
	{0x5c, 0x5c},
	{0x5e, 0xcc},
	{0xe0, 0xe1},
	{0xf2, 0x10e},
};

u16 g_BgPreloadEscape[][2] = {
	{0x10, 0x15},
	{0x23, 0x40},
	{0x46, 0x47},
	{0x59, 0x5d},
	{0x64, 0x70},
	{0x78, 0x84},
	{0x88, 0x9a},
	{0x9c, 0x9e},
	{0xa5, 0xa8},
	{0xab, 0xad},
	{0xbd, 0xbd},
	{0xbf, 0x10e},
};

u16 g_BgPreloadMaianSos[][2] = {
	{0x01, 0x01},
	{0x05, 0x06},
	{0x08, 0x08},
	{0x0f, 0x0f},
	{0x19, 0x1b},
	{0x27, 0x49},
	{0x51, 0xc6},
	{0xc8, 0xd2},
	{0xe0, 0xe2},
	{0xf2, 0x10e},
};

void bgPreload(void)
{
	s32 i;
	s32 j;

	if (g_Vars.stagenum == STAGE_INFILTRATION) {
		for (i = 0; i < ARRAYCOUNT(g_BgPreloadInfiltration); i++) {
			for (j = g_BgPreloadInfiltration[i][0]; j <= g_BgPreloadInfiltration[i][1]; j++) {
				bgLoadRoom(j);
			}
		}
	} else if (g_Vars.stagenum == STAGE_RESCUE) {
		for (i = 0; i < ARRAYCOUNT(g_BgPreloadRescue); i++) {
			for (j = g_BgPreloadRescue[i][0]; j <= g_BgPreloadRescue[i][1]; j++) {
				bgLoadRoom(j);
			}
		}
	} else if (g_Vars.stagenum == STAGE_ESCAPE) {
		for (i = 0; i < ARRAYCOUNT(g_BgPreloadEscape); i++) {
			for (j = g_BgPreloadEscape[i][0]; j <= g_BgPreloadEscape[i][1]; j++) {
				bgLoadRoom(j);
			}
		}
	} else if (g_Vars.stagenum == STAGE_MAIANSOS) {
		for (i = 0; i < ARRAYCOUNT(g_BgPreloadMaianSos); i++) {
			for (j = g_BgPreloadMaianSos[i][0]; j <= g_BgPreloadMaianSos[i][1]; j++) {
				bgLoadRoom(j);
			}
		}
	} else {
		for (i = 1; i < g_Vars.roomcount; i++) {
			bgLoadRoom(i);
		}
	}
}
