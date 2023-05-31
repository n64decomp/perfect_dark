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
#include "game/portalconv.h"
#include "game/stagetable.h"
#include "game/env.h"
#include "game/room.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/texdecompress.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/lib_17ce0.h"
#include "lib/lib_2f490.h"
#include "lib/main.h"
#include "lib/mema.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/rng.h"
#include "lib/rzip.h"
#include "lib/vi.h"
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

struct drawslot g_BgDrawSlots[61];
u8 *g_BgPrimaryData;
u32 var800a4920;
u32 g_BgSection3;
struct room *g_Rooms;
u8 *g_MpRoomVisibility;
s16 g_BgForceOnscreenRooms[350];
s32 g_BgNumForceOnscreenRooms;
u16 g_BgUnloadDelay240;
u16 g_BgUnloadDelay240_2;
u32 var800a4bf4;
s16 g_GlareRooms[100];
u32 *g_BgPrimaryData2;
struct bgroom *g_BgRooms;
struct bgportal *g_BgPortals;
struct portalmetric *g_PortalMetrics;
u8 *g_BgPortalAlphas;
struct bgcmd *g_BgCommands;
u8 *g_BgLightsFileData;
f32 *g_BgStanThings;
s16 *g_RoomPortals;
s16 g_BgMinDrawOrder;
s16 g_BgMaxDrawOrder;
struct drawslotpointer *g_BgDrawSlotsByRoom;
struct portalcamcacheitem *g_PortalCameraCache;
struct bgsnake g_BgSnake;

s32 g_StageIndex = 1;
u32 var8007fc04 = 0;
u8 *var8007fc08 = NULL;

#if VERSION < VERSION_NTSC_1_0
u32 var80082474nb = 0;
#endif

s16 var8007fc0c = 0;
s16 var8007fc10 = 0;
s32 g_NumRoomsWithGlares = 0;
u32 var8007fc18 = 0x01000100;
u32 var8007fc1c = 0;
s32 g_CamRoom = 1;
struct drawslot *g_BgSpecialDrawSlot = &g_BgDrawSlots[60];
s32 g_BgLoadCandidateTimer240 = 0;
s32 g_BgNumDrawSlots = 0;
s32 g_BgNumAttemptedDrawSlots = 0;
s32 g_BgMostAttemptedDrawSlots = 0;
s32 g_BgNumRoomLoadCandidates = 0;
u16 g_BgFrameCount = 0xfffe;
s32 g_BgNumPortalCameraCacheItems = 0;

void bgUnpausePropsInRoom(u32 roomnum, bool tintedglassonly)
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

void bgSetRoomOnscreen(s32 roomnum, s32 draworder, struct screenbox *box)
{
	s32 index;

#if VERSION < VERSION_NTSC_1_0
	g_Rooms[roomnum].flags |= ROOMFLAG_ONSCREEN;
#endif

	if ((g_Rooms[roomnum].flags & ROOMFLAG_DISABLEDBYSCRIPT) == 0) {
#if VERSION >= VERSION_NTSC_1_0
		g_Rooms[roomnum].flags |= ROOMFLAG_ONSCREEN;
#endif

		if (g_Rooms[roomnum].flags & ROOMFLAG_BBOXHACK) {
			box->xmin = g_BgDrawSlots[60].box.xmin;
			box->ymin = g_BgDrawSlots[60].box.ymin;
			box->xmax = g_BgDrawSlots[60].box.xmax;
			box->ymax = g_BgDrawSlots[60].box.ymax;
		}

		if (g_BgFrameCount == g_BgDrawSlotsByRoom[roomnum].updatedframe) {
			index = g_BgDrawSlotsByRoom[roomnum].slotnum;

			if (draworder > g_BgDrawSlots[index].draworder) {
				g_BgDrawSlots[index].draworder = draworder;

				if (g_BgDrawSlots[index].draworder > g_BgMaxDrawOrder) {
					g_BgMaxDrawOrder = g_BgDrawSlots[index].draworder;
				}

				if (g_BgDrawSlots[index].draworder < g_BgMinDrawOrder) {
					g_BgMinDrawOrder = g_BgDrawSlots[index].draworder;
				}
			}

			bgExpandBox(&g_BgDrawSlots[index].box, box);
		} else {
			index = g_BgNumDrawSlots;

			if (index > 59) {
				index = 59;
			}

			g_BgDrawSlots[index].roomnum = roomnum;
			g_BgDrawSlots[index].draworder = draworder;

			g_BgDrawSlots[index].box.xmin = box->xmin;
			g_BgDrawSlots[index].box.ymin = box->ymin;
			g_BgDrawSlots[index].box.xmax = box->xmax;
			g_BgDrawSlots[index].box.ymax = box->ymax;

			if (g_BgDrawSlots[index].draworder > g_BgMaxDrawOrder) {
				g_BgMaxDrawOrder = g_BgDrawSlots[index].draworder;
			}

			if (g_BgDrawSlots[index].draworder < g_BgMinDrawOrder) {
				g_BgMinDrawOrder = g_BgDrawSlots[index].draworder;
			}

			g_BgDrawSlotsByRoom[roomnum].updatedframe = g_BgFrameCount;
			g_BgDrawSlotsByRoom[roomnum].slotnum = index;

			g_BgNumAttemptedDrawSlots++;

			if (g_BgNumAttemptedDrawSlots < 60) {
				g_BgNumDrawSlots = g_BgNumAttemptedDrawSlots;
			}

			bgUnpausePropsInRoom(roomnum, false);

			if (g_Rooms[roomnum].loaded240 == 0 && var8007fc10 > 0) {
				var8007fc10--;
				bgLoadRoom(roomnum);
			} else if (g_Rooms[roomnum].loaded240 == 0) {
				var8007fc10--;
			}
		}
	}
}

void bgGetRoomBrightnessRange(s32 roomnum, u8 *min, u8 *max)
{
	*min = g_BgRooms[roomnum].br_light_min;
	*max = g_BgRooms[roomnum].br_light_max;
}

struct drawslot *bgGetRoomDrawSlot(s32 roomnum)
{
	s32 index = 60;

	if (g_BgFrameCount == g_BgDrawSlotsByRoom[roomnum].updatedframe) {
		index = g_BgDrawSlotsByRoom[roomnum].slotnum;
	}

	return &g_BgDrawSlots[index];
}

Gfx *bgRenderXrayData(Gfx *gdl, struct xraydata *xraydata)
{
	Vtx *vertices;
	Col *colours;
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
			colours[i].word = xraydata->colours[i];
		}

		count = xraydata->numvertices;
		gSPColor(gdl++, colours, count);

		count = xraydata->numvertices;
		gSPVertex(gdl++, vertices, count, 0);

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
			gSPTri4(gdl++,
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

Gfx *bgAddXrayTri(Gfx *gdl, struct xraydata *xraydata, s16 vertices1[3], s16 vertices2[3], s16 vertices3[3], u32 colour1, u32 colour2, u32 colour3)
{
	s16 sp30[3] = {-1, -1, -1};
	s32 count = 0;
	s16 i;

	if (xraydata->numtris >= 64) {
		gdl = bgRenderXrayData(gdl, xraydata);
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
			gdl = bgRenderXrayData(gdl, xraydata);

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

Gfx *bgProcessXrayTri(Gfx *gdl, struct xraydata *xraydata, s16 arg2[3], s16 arg3[3], s16 arg4[3], s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
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
			return bgAddXrayTri(gdl, xraydata, arg2, arg3, arg4, arg5, arg6, arg7);
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
					gdl = bgProcessXrayTri(gdl, xraydata, arg2, sp84[0], arg4, arg5, colours[0], arg7, arg8, inrange[0], arg10);
					gdl = bgProcessXrayTri(gdl, xraydata, arg4, sp84[0], arg3, arg7, colours[0], arg6, arg10, inrange[0], arg9);
				} else if (sp68 == 1) {
					gdl = bgProcessXrayTri(gdl, xraydata, arg3, sp84[1], arg2, arg6, colours[1], arg5, arg9, inrange[1], arg8);
					gdl = bgProcessXrayTri(gdl, xraydata, arg2, sp84[1], arg4, arg5, colours[1], arg7, arg8, inrange[1], arg10);
				} else if (sp68 == 2) {
					gdl = bgProcessXrayTri(gdl, xraydata, arg4, sp84[2], arg3, arg7, colours[2], arg6, arg10, inrange[2], arg9);
					gdl = bgProcessXrayTri(gdl, xraydata, arg3, sp84[2], arg2, arg6, colours[2], arg5, arg9, inrange[2], arg8);
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
					gdl = bgProcessXrayTri(gdl, xraydata, arg4, sp84[2], sp84[1], arg7, colours[2], colours[1], arg10, inrange[2], inrange[1]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg3, sp84[1], sp84[2], arg6, colours[1], colours[2], arg9, inrange[1], inrange[2]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg2, arg3, sp84[2], arg5, arg6, colours[2], arg8, arg9, inrange[2]);
				} else if (v0 == 1) {
					gdl = bgProcessXrayTri(gdl, xraydata, arg2, sp84[0], sp84[2], arg5, colours[0], colours[2], arg8, inrange[0], inrange[2]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg4, sp84[2], sp84[0], arg7, colours[2], colours[0], arg10, inrange[2], inrange[0]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg3, arg4, sp84[0], arg6, arg7, colours[0], arg9, arg10, inrange[0]);
				} else {
					gdl = bgProcessXrayTri(gdl, xraydata, arg3, sp84[1], sp84[0], arg6, colours[1], colours[0], arg9, inrange[1], inrange[0]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg2, sp84[0], sp84[1], arg5, colours[0], colours[1], arg8, inrange[0], inrange[1]);
					gdl = bgProcessXrayTri(gdl, xraydata, arg4, arg2, sp84[1], arg7, arg5, colours[1], arg10, arg8, inrange[1]);
				}
			} else if (sp64 == 3) {
				gdl = bgProcessXrayTri(gdl, xraydata, arg2, sp84[0], sp84[2], arg5, colours[0], colours[2], arg8, inrange[0], inrange[2]);
				gdl = bgProcessXrayTri(gdl, xraydata, arg3, sp84[1], sp84[0], arg6, colours[1], colours[0], arg9, inrange[1], inrange[0]);
				gdl = bgProcessXrayTri(gdl, xraydata, arg4, sp84[2], sp84[1], arg7, colours[2], colours[1], arg10, inrange[2], inrange[1]);
				gdl = bgProcessXrayTri(gdl, xraydata, sp84[0], sp84[1], sp84[2], colours[0], colours[1], colours[2], inrange[0], inrange[1], inrange[2]);
			}
		}
	}

	return gdl;
}

u32 var8007fc54 = 0;
bool g_BgCmdStack[20] = {0};
s32 g_BgCmdStackIndex = 0;
u32 g_BgCmdResult = BGRESULT_TRUE;

Gfx *bgRenderGdlInXray(Gfx *gdl, s8 *readgdl, Vtx *vertices, s16 arg3[3])
{
	s32 i;
	u8 *verticesu8 = (u8 *) vertices;
	struct xraydata xraydata;
	struct stagetableentry *stage = stageGetCurrent();
	s16 dmemvertices[16][3];
	u32 dmemcolours[16];
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
		if (readgdl[0] == G_ENDDL) {
			break;
		}

		if (readgdl[0] == G_MTX) {
			// empty
		} else if (readgdl[0] == G_VTX) {
			Gfx *cmd = (Gfx *) readgdl;
			s32 dmemindex = cmd->bytes[1] & 0xf;
			s32 numvertices = ((u32) cmd->bytes[1] >> 4) + 1;
			u32 offset = cmd->words.w1 & 0xffffff;

			for (i = 0; i < numvertices; i++) {
				Vtx *vtx = (Vtx *) (verticesu8 + offset);

				dmemvertices[dmemindex + i][0] = vtx->x;
				dmemvertices[dmemindex + i][1] = vtx->y;
				dmemvertices[dmemindex + i][2] = vtx->z;

				bgChooseXrayVtxColour(&inrange[i], dmemvertices[dmemindex + i], &dmemcolours[dmemindex + i], &xraydata);

				offset += sizeof(Vtx);
			}
		} else if (readgdl[0] == G_TRI1) {
			Gfx *cmd = (Gfx *) readgdl;
			s16 x = cmd->tri.tri.v[0] / 10;
			s16 y = cmd->tri.tri.v[1] / 10;
			s16 z = cmd->tri.tri.v[2] / 10;

			gdl = bgProcessXrayTri(gdl, &xraydata, dmemvertices[x], dmemvertices[y], dmemvertices[z], dmemcolours[x], dmemcolours[y], dmemcolours[z], inrange[x], inrange[y], inrange[z]);
		} else if (readgdl[0] == G_TRI4) {
			Gfx *cmd = (Gfx *) readgdl;
			s16 x;
			s16 y;
			s16 z;

			x = cmd->tri4.x1;
			y = cmd->tri4.y1;
			z = cmd->tri4.z1;

			gdl = bgProcessXrayTri(gdl, &xraydata, dmemvertices[x], dmemvertices[y], dmemvertices[z], dmemcolours[x], dmemcolours[y], dmemcolours[z], inrange[x], inrange[y], inrange[z]);

			x = cmd->tri4.x2;
			y = cmd->tri4.y2;
			z = cmd->tri4.z2;

			gdl = bgProcessXrayTri(gdl, &xraydata, dmemvertices[x], dmemvertices[y], dmemvertices[z], dmemcolours[x], dmemcolours[y], dmemcolours[z], inrange[x], inrange[y], inrange[z]);

			x = cmd->tri4.x3;
			y = cmd->tri4.y3;
			z = cmd->tri4.z3;

			gdl = bgProcessXrayTri(gdl, &xraydata, dmemvertices[x], dmemvertices[y], dmemvertices[z], dmemcolours[x], dmemcolours[y], dmemcolours[z], inrange[x], inrange[y], inrange[z]);

			x = cmd->tri4.x4;
			y = cmd->tri4.y4;
			z = cmd->tri4.z4;

			gdl = bgProcessXrayTri(gdl, &xraydata, dmemvertices[x], dmemvertices[y], dmemvertices[z], dmemcolours[x], dmemcolours[y], dmemcolours[z], inrange[x], inrange[y], inrange[z]);
		}

		readgdl += 8;
	}

	gdl = bgRenderXrayData(gdl, &xraydata);

	return gdl;
}

Gfx *bgRenderRoomXrayPass(Gfx *gdl, s32 roomnum, struct roomblock *block, bool recurse, s16 arg4[3])
{
	struct player *player = g_Vars.currentplayer;

	if (block == NULL) {
		return gdl;
	}

	switch (block->type) {
	case ROOMBLOCKTYPE_LEAF:
		gdl = bgRenderGdlInXray(gdl, (s8 *) block->gdl, block->vertices, arg4);

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

	roomGetPos(roomnum, &globaldrawworldoffset);

	sp54.x = player->eraserpos.x - globaldrawworldoffset.x;
	sp54.y = player->eraserpos.y - globaldrawworldoffset.y;
	sp54.z = player->eraserpos.z - globaldrawworldoffset.z;

	sp40[0] = sp54.f[0];
	sp40[1] = sp54.f[1];
	sp40[2] = sp54.f[2];

	gdl = roomApplyMtx(gdl, roomnum);
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
	gdl = bgScissorToViewport(gdl);

	for (i = g_BgMinDrawOrder; i <= g_BgMaxDrawOrder; i++) {
		for (j = 0; j < g_BgNumDrawSlots; j++) {
			struct drawslot *thing = &g_BgDrawSlots[j];

			if (thing->draworder == i) {
				gdl = bgRenderRoomInXray(gdl, thing->roomnum);
			}
		}
	}

	// Render props
	gdl = bgScissorToViewport(gdl);

	gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (g_BgMinDrawOrder); \
	if (g_BgNumDrawSlots); \
	for (i = g_BgMaxDrawOrder; i >= g_BgMinDrawOrder; i--) {
		for (k = 0; k < g_BgNumDrawSlots; k++) {
			struct drawslot *thing = &g_BgDrawSlots[k];

			if (thing->draworder == i) {
				gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

				gdl = bgScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);

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

Gfx *bgRenderScene(Gfx *gdl)
{
	s32 stagenum = g_Vars.stagenum;
	s32 firstroomnum = -1;
	s32 i;
	s32 roomnum;
	s16 roomnumsbyprop[200];
	struct prop **ptr;
	struct drawslot *thing;
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
	for (roomnum = 0; roomnum < g_BgNumDrawSlots; roomnum++) {
		roomorder[roomnum] = g_BgDrawSlots[roomnum].draworder;
		roomnums[roomnum] = roomnum;
	}

	// Sort them by distance ascending
	if (g_BgNumDrawSlots >= 2) {
		do {
			i = false;

			for (roomnum = 0; roomnum < g_BgNumDrawSlots - 1; roomnum++) {
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

	gdl = bgScissorToViewport(gdl);

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
	if (g_BgNumDrawSlots);

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
	for (i = 0; i < g_BgNumDrawSlots; i++) {
		roomnum = roomnums[i];

		if (firstroomnum < 0) {
			firstroomnum = g_BgDrawSlots[roomnum].roomnum;
			if (firstroomnum);
		}

		thing = &g_BgDrawSlots[roomnum];

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

		gdl = bgScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
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
	gdl = bgScissorToViewport(gdl);

	// Render wall hits
	gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	if (getVar80084040() && g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
		for (i = 0; i < g_BgNumDrawSlots; i++) {
			roomnum = roomnums[i];
			gdl = wallhitRenderBgHits(g_BgDrawSlots[roomnum].roomnum, gdl);
		}
	}

	if (1);

	for (i = g_BgNumDrawSlots - 1; i >= 0; i--) {
		roomnum = roomnums[i];

		gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		thing = &g_BgDrawSlots[roomnum];

		// Render BG translucent components
		gdl = bgScissorWithinViewportF(gdl, thing->box.xmin, thing->box.ymin, thing->box.xmax, thing->box.ymax);
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

s32 bgGetStageIndex(s32 stagenum)
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

f32 bgCalculatePortalSurfaceArea(s32 portalnum)
{
	struct portalvertices *pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
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

void bgGetPortalVtxInfo(s32 portalnum, struct coord *a, struct coord *b, struct coord *c, struct coord *normal)
{
	struct portalvertices *pvertices;
	pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

	a->x = pvertices->vertices[0].x;
	a->y = pvertices->vertices[0].y;
	a->z = pvertices->vertices[0].z;

	b->x = pvertices->vertices[1].x - pvertices->vertices[0].x;
	b->y = pvertices->vertices[1].y - pvertices->vertices[0].y;
	b->z = pvertices->vertices[1].z - pvertices->vertices[0].z;

	c->x = pvertices->vertices[1].x - pvertices->vertices[0].x;
	c->y = pvertices->vertices[1].y - pvertices->vertices[0].y;
	c->z = pvertices->vertices[1].z - pvertices->vertices[0].z;

	normal->x = (g_PortalMetrics + portalnum)->normal.x;
	normal->y = (g_PortalMetrics + portalnum)->normal.y;
	normal->z = (g_PortalMetrics + portalnum)->normal.z;
}

/**
 * We don't know that this is actually alpha.
 * The value is not used, so it's just a guess.
 * If may have been used if portals were being rendered.
 *
 * A 1 metre square portal would have alpha of 1.
 * A 1596 metre square portal would have alpha of 255.
 */
u8 bgCalculatePortalAlpha(s32 portal)
{
	s32 alpha = bgCalculatePortalSurfaceArea(portal) / 10000.0f;

	if (alpha > 0xff) {
		alpha = 0xff;
	}

	return alpha;
}

u8 bgGetPortalAlpha(s32 portalnum)
{
	return g_BgPortalAlphas[portalnum];
}

#if PIRACYCHECKS
u32 bgNot(u32 arg)
{
	return ~arg;
}

u32 bgXorBabebabe(u32 value)
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

#if VERSION >= VERSION_NTSC_1_0
	if (IS4MB()) {
		g_BgUnloadDelay240 = 6;
		g_BgUnloadDelay240_2 = 6;
	} else {
		g_BgUnloadDelay240 = 120;
		g_BgUnloadDelay240_2 = 120;
	}
#else
	if (IS4MB()) {
		g_BgUnloadDelay240 = 120;
		g_BgUnloadDelay240_2 = 120;
	} else {
		g_BgUnloadDelay240 = 3600;
		g_BgUnloadDelay240_2 = 3600;
	}

	var800a4bf4 = 0;
#endif

	g_StageIndex = bgGetStageIndex(stagenum);

	if (g_StageIndex < 0) {
		g_StageIndex = 0;
	}

	// Copy section 1 header to stack and parse into variables
	header = (u8 *)ALIGN16((uintptr_t)headerbuffer);
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
	scratch = (uintptr_t) g_BgPrimaryData + inflatedsize - primcompsize;
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
	scratch = (uintptr_t) section2 + inflatedsize;
#elif VERSION >= VERSION_NTSC_FINAL
	section2 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
	scratch = (uintptr_t) section2 + 0x8000;
#else
	section2 = mempAlloc(inflatedsize + 0x800, MEMPOOL_STAGE);
	scratch = (uintptr_t) section2 + 0x800;
#endif

	// Load compressed data from ROM to scratch
	bgLoadFile((u8 *) scratch, section2start + 4, ((section2compsize - 1) | 0xf) + 1);

	// Inflate section 2 to the start of the buffer
	bgInflate((u8 *) scratch, (u8 *) section2, section2compsize);

	// Iterate texture IDs and ensure they're loaded
	inflatedsize = (*(u16 *) &header[0] & 0x7fff) >> 1;

	for (i = 0; i ^ inflatedsize; i++) {
		texLoadFromTextureNum(section2[i] & 0xffff & 0xffff & 0xffff & 0xffff & 0xffff & 0xffff & 0xffff & 0xffff, NULL);
	}

	if (1);

	// Free section 2
	mempRealloc(section2, 0, MEMPOOL_STAGE);

	g_BgSection3 = section2start + section2compsize + 4;

#if PIRACYCHECKS
	{
		u32 addr = bgNot(PAL ? ~0xb0000340 : ~0xb0000454);
		u32 actualvalue;
		u32 expectedvalue = bgXorBabebabe((PAL ? 0x0330c820 : 0x0109082b) ^ 0xbabebabe);

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
		g_BgRooms = (struct bgroom *)(g_BgPrimaryData2[1] + g_BgPrimaryData - 0x0f000000);
		goto foo; foo:;
		g_Vars.roomcount = 0;

		for (j = 1; g_BgRooms[j].unk00 != 0; j++) {
			g_Vars.roomcount++;
		}

		g_BgPortals = (struct bgportal *)(g_BgPrimaryData2[2] + g_BgPrimaryData - 0x0f000000);

		if (g_BgPrimaryData2[3] == 0) {
			g_BgCommands = NULL;
		} else {
			g_BgCommands = (struct bgcmd *)(g_BgPrimaryData2[3] + g_BgPrimaryData - 0x0f000000);
		}

		if (g_BgPrimaryData2[4] == 0) {
			g_BgLightsFileData = NULL;
		} else {
			g_BgLightsFileData = (u8 *)(g_BgPrimaryData2[4] + g_BgPrimaryData - 0x0f000000);
		}

		if (g_BgPrimaryData2[5] == 0) {
			g_BgStanThings = NULL;
		} else {
			g_BgStanThings = (f32 *)(g_BgPrimaryData2[5] + g_BgPrimaryData - 0x0f000000);
		}
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
	struct portalmetric *metric;
	s32 numvertices;
	struct portalmetric tmp;
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
	g_BgDrawSlotsByRoom = mempAlloc(ALIGN16(g_Vars.roomcount * sizeof(struct drawslotpointer)), MEMPOOL_STAGE);

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_BgDrawSlotsByRoom[i].updatedframe = 0xffff;
		g_BgDrawSlotsByRoom[i].slotnum = 0;
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

	bgSetStageTranslationThing(g_Stages[g_StageIndex].unk14);
	chr0f028490(g_Stages[g_StageIndex].unk14);

	for (i = 0; i < MAX_PLAYERS; i++) {
		g_Vars.playerstats[i].scale_bg2gfx = g_Stages[g_StageIndex].unk18;
	}

	mtx00016748(1);

	if (var800a4920 == 0) {
		numportals = 0;

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			numportals++;
		}

		g_BgNumPortalCameraCacheItems = numportals;
		g_PortalCameraCache = mempAlloc(ALIGN16(g_BgNumPortalCameraCacheItems * sizeof(struct portalcamcacheitem)), MEMPOOL_STAGE);

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

			pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + offset);

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

		g_BgPortalAlphas = mempAlloc(ALIGN16(numportals == 0 ? 1 : numportals), MEMPOOL_STAGE);

		for (i = 0; i < numportals; i++) {
			g_BgPortalAlphas[i] = bgCalculatePortalAlpha(i);
		}

		g_PortalMetrics = mempAlloc(ALIGN16(numportals * sizeof(struct portalmetric)), MEMPOOL_STAGE);

		for (i = 0; i < numportals; i++) {
			// Clockwise vertices will cause the normal to point towards the viewer
			tmp.normal.x = 0.0f;
			tmp.normal.y = 0.0f;
			tmp.normal.z = 0.0f;

			pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[i].verticesoffset);

			for (j = 0; j < pvertices->count; j++) {
				struct coord *next = &pvertices->vertices[(j + 1) % pvertices->count];

				tmp.normal.x += (pvertices->vertices[j].y - next->y) * (pvertices->vertices[j].z + next->z);
				tmp.normal.y += (pvertices->vertices[j].z - next->z) * (pvertices->vertices[j].x + next->x);
				tmp.normal.z += (pvertices->vertices[j].x - next->x) * (pvertices->vertices[j].y + next->y);
			}

			divisor = -sqrtf(tmp.normal.f[0] * tmp.normal.f[0] + tmp.normal.f[1] * tmp.normal.f[1] + tmp.normal.f[2] * tmp.normal.f[2]);

			tmp.normal.x /= divisor;
			tmp.normal.y /= divisor;
			tmp.normal.z /= divisor;

			tmp.min = MAXFLOAT;
			tmp.max = MINFLOAT;

			for (j = 0; j < pvertices->count; j++) {
				f32 value = pvertices->vertices[j].f[0] * tmp.normal.f[0]
					+ pvertices->vertices[j].f[1] * tmp.normal.f[1]
					+ pvertices->vertices[j].f[2] * tmp.normal.f[2];

				if (value < tmp.min) {
					tmp.min = value;
				}

				if (value > tmp.max) {
					tmp.max = value;
				}
			}

			metric = &g_PortalMetrics[i];
			metric->normal.x = tmp.normal.x;
			metric->normal.y = tmp.normal.y;
			metric->normal.z = tmp.normal.z;
			metric->min = tmp.min;
			metric->max = tmp.max;
		}

		portal0f0b65a8(numportals);

		if (g_BgCommands != NULL) {
			for (i = 0; g_BgCommands[i].type != BGCMD_END; i++) {
				if (g_BgCommands[i].type == BGCMD_PORTALARG) {
					g_BgCommands[i].param = bgFindPortalByVertices((void *)((intptr_t)g_BgPrimaryData - 0x0f000000 + g_BgCommands[i].param));
				}
			}
		}

		for (i = 0; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags = 0;
			g_Rooms[i].snakecount = 0;
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
		header = (u8 *)ALIGN16((uintptr_t)headerbuffer);
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
			bgInitPortal(i);
		}

		for (i = 1; i < g_Vars.roomcount; i++) {
			bgInitRoom(i);
		}

		for (i = 1; i < g_Vars.roomcount; i++) {
			bgExpandRoomToPortals(i);
		}

		for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
			g_BgPortals[i].flags &= ~PORTALFLAG_CLOSED & 0xff;
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

void bgSetStageTranslationThing(f32 arg0)
{
	// empty
}

f32 bgGetStageTranslationThing(void)
{
	return g_Stages[g_StageIndex].unk1c / g_Stages[g_StageIndex].unk14;
}

f32 bgGetScaleBg2Gfx(void)
{
	return g_Vars.currentplayerstats->scale_bg2gfx;
}

void bgSetScaleBg2Gfx(f32 scale)
{
	g_Vars.currentplayerstats->scale_bg2gfx = g_Stages[g_StageIndex].unk18 * scale;
	mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);
}

/**
 * The counter is incremented once per frame per player.
 *
 * The portal camera cache uses this counter as a last-updated timestamp to keep
 * track of whether any cache item is current as of this frame/player or whether
 * it needs to be recalculated.
 *
 * When the counter rolls over, all portal camera cache is cleared to avoid any
 * potential issues with reusing the timestamps.
 */
void bgTickCounter(void)
{
	g_BgFrameCount++;

	if (g_BgFrameCount == 0xffff) {
		g_BgFrameCount = 1;

		bgClearPortalCameraCache();
	}

#if PIRACYCHECKS
	if ((g_BgFrameCount & 0xff) == 0xff) {
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

	g_BgNumForceOnscreenRooms = 0;

#if VERSION < VERSION_NTSC_1_0
	bgVerifyLightSums("bg.c", 5761);
#endif

	bgTickCounter();

	if (g_Vars.currentplayerindex == 0) {
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
	gdl = bgRenderSceneAndLoadCandidate(gdl);
	gdl = bgScissorToViewport(gdl);
	gdl = envStopFog(gdl);

	gSPMatrix(gdl++, var80092870, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	gdl = playerLoadMatrix(gdl);

	return gdl;
}

/**
 * Leftover from GE.
 */
f32 bgGetStanThing(s32 roomnum)
{
	return g_BgStanThings[roomnum + 1];
}

Gfx *bgScissorToViewport(Gfx *gdl)
{
	return bgScissorWithinViewport(gdl,
			g_Vars.currentplayer->viewleft,
			g_Vars.currentplayer->viewtop,
			g_Vars.currentplayer->viewleft + g_Vars.currentplayer->viewwidth,
			g_Vars.currentplayer->viewtop + g_Vars.currentplayer->viewheight);
}

Gfx *bgScissorWithinViewportF(Gfx *gdl, f32 viewleft, f32 viewtop, f32 viewright, f32 viewbottom)
{
	gdl = bgScissorWithinViewport(gdl, viewleft, viewtop, ceil(viewright), ceil(viewbottom));

	return gdl;
}

Gfx *bgScissorWithinViewport(Gfx *gdl, s32 viewleft, s32 viewtop, s32 viewright, s32 viewbottom)
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

void bgClearPortalCameraCache(void)
{
	s32 i;

	for (i = 0; i < g_BgNumPortalCameraCacheItems; i++) {
		g_PortalCameraCache[i].bboxisvalid = -1;
		g_PortalCameraCache[i].updatedframe2 = 0;
		g_PortalCameraCache[i].updatedframe1 = 0;
	}
}

bool bgRoomIntersectsScreenBox(s32 room, struct screenbox *screen)
{
	s32 i;
	struct coord roomscreenpos;
	struct coord corner;
	s32 numbehind = 0;
	s32 numfar = 0;
	s32 numleft = 0;
	s32 numright = 0;
	s32 numbelow = 0;
	s32 numabove = 0;

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

		if (bg3dPosTo2dPos(&corner, &roomscreenpos) == 0) {
			// Corner is behind the camera
			if (g_BgSnake.zrange.far <= -roomscreenpos.z) {
				numfar++;
			}

			if (roomscreenpos.x > screen->xmin) {
				numleft++;
			}

			if (roomscreenpos.x < screen->xmax) {
				numright++;
			}

			if (roomscreenpos.y > screen->ymin) {
				numbelow++;
			}

			if (roomscreenpos.y < screen->ymax) {
				numabove++;
			}

			numbehind++;
		} else {
			// Corner is in front of the camera
			if (g_BgSnake.zrange.far <= -roomscreenpos.z) {
				numfar++;
			}

			if (roomscreenpos.x < screen->xmin) {
				numleft++;
			} else if (roomscreenpos.x > screen->xmax) {
				numright++;
			}

			if (roomscreenpos.y < screen->ymin) {
				numbelow++;
			} else if (roomscreenpos.y > screen->ymax) {
				numabove++;
			}
		}
	}

	if (numbehind == 8
			|| numfar == 8
			|| numleft == 8
			|| numright == 8
			|| numbelow == 8
			|| numabove == 8) {
		return false;
	}

	return true;
}

bool bg3dPosTo2dPos(struct coord *cornerpos, struct coord *screenpos)
{
	Mtxf *matrix = camGetWorldToScreenMtxf();

	screenpos->x = cornerpos->x;
	screenpos->y = cornerpos->y;
	screenpos->z = cornerpos->z;

	mtx4TransformVecInPlace(matrix, screenpos);
	cam0f0b4d68(screenpos, screenpos->f);

	if (screenpos->z > 0) {
		return false;
	}

	return true;
}

bool bgGetPortalScreenBbox(s32 portalnum, struct screenbox *box)
{
	s32 i;
	s32 j;
	s32 len;
	s32 start;
	s32 numvalid;
	f32 sp2e4[2];
	f32 sp2d4[2][2];
	struct portalthing2 *thing;
	struct portalthing2 things[40];

	if (g_PortalCameraCache[portalnum].updatedframe2 == g_BgFrameCount) {
		box->xmin = g_PortalCameraCache[portalnum].xmin;
		box->ymin = g_PortalCameraCache[portalnum].ymin;
		box->xmax = g_PortalCameraCache[portalnum].xmax;
		box->ymax = g_PortalCameraCache[portalnum].ymax;

		return g_PortalCameraCache[portalnum].bboxisvalid;
	}

	len = portalConvertCoordinates(portalnum, &start, things);

	numvalid = 0;
	thing = &things[start];

	for (j = 0; j < len; j++) {
		if (thing->coord.z <= 0.0f) {
			cam0f0b4d68(&thing->coord, sp2e4);

			if (numvalid == 0) {
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

			numvalid++;
		}

		thing++;
	}

	if (numvalid == 0) {
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

	g_PortalCameraCache[portalnum].xmin = box->xmin;
	g_PortalCameraCache[portalnum].ymin = box->ymin;
	g_PortalCameraCache[portalnum].xmax = box->xmax;
	g_PortalCameraCache[portalnum].ymax = box->ymax;
	g_PortalCameraCache[portalnum].bboxisvalid = numvalid;
	g_PortalCameraCache[portalnum].updatedframe2 = g_BgFrameCount;

	return numvalid;
}

Gfx *bgDrawBoxEdge(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2 + 1, y2 + 1);

	return gdl;
}

Gfx *bgDrawBox(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gdl = bgDrawBoxEdge(gdl, x1, y1, x2, y1); // top
	gdl = bgDrawBoxEdge(gdl, x2, y1, x2, y2); // right
	gdl = bgDrawBoxEdge(gdl, x1, y2, x2, y2); // bottom
	gdl = bgDrawBoxEdge(gdl, x1, y1, x1, y2); // left

	return gdl;
}

bool bgGetBoxIntersection(struct screenbox *a, struct screenbox *b)
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

void bgExpandBox(struct screenbox *a, struct screenbox *b)
{
	a->xmin = a->xmin < b->xmin ? a->xmin : b->xmin;
	a->ymin = a->ymin < b->ymin ? a->ymin : b->ymin;
	a->xmax = a->xmax > b->xmax ? a->xmax : b->xmax;
	a->ymax = a->ymax > b->ymax ? a->ymax : b->ymax;
}

void bgCopyBox(struct screenbox *dst, struct screenbox *src)
{
	dst->xmin = src->xmin;
	dst->ymin = src->ymin;
	dst->xmax = src->xmax;
	dst->ymax = src->ymax;
}

bool bgRoomIsOnscreen(s32 room)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & 0xf) != 0;
	} else {
		return g_Rooms[room].flags & ROOMFLAG_ONSCREEN;
	}
}

bool bgRoomIsStandby(s32 room)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & 0xf0) != 0;
	}

	return g_Rooms[room].flags & ROOMFLAG_STANDBY;
}

bool bgRoomIsOnPlayerScreen(s32 room, u32 playernum)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & (1 << playernum)) != 0;
	} else {
		return g_Rooms[room].flags & ROOMFLAG_ONSCREEN;
	}
}

bool bgRoomIsOnPlayerStandby(s32 room, u32 playernum)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room] & (0x10 << playernum)) != 0;
	} else {
		return g_Rooms[room].flags & ROOMFLAG_STANDBY;
	}
}

s32 bgFindPortalByVertices(struct portalvertices *target)
{
	s32 i;
	struct bgportal *portal = g_BgPortals;

	for (i = 0; portal[i].verticesoffset != 0; i++) {
		struct portalvertices *pvertices = (struct portalvertices *)((uintptr_t)portal + portal[i].verticesoffset);

		if (pvertices == target) {
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
void bgPrintLoadedRooms(void)
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

			crashSetMessage(message);
			CRASH();
		}
#endif
	} else {
		result = len;
		bcopy(src, dst, len);
	}

	return result;
}

Gfx *bgGetNextGdlInBlock(struct roomblock *block, Gfx *start, Gfx *end)
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
			tmp = bgGetNextGdlInBlock(block->child, start, end);
			block = block->next;
			end = tmp;
			break;
		default:
			return end;
		}
	}

	return end;
}

Gfx *bgGetNextGdlInLayer(s32 roomnum, Gfx *start, u32 types)
{
	struct roomblock *opablocks = g_Rooms[roomnum].gfxdata->opablocks;
	struct roomblock *xlublocks = g_Rooms[roomnum].gfxdata->xlublocks;
	Gfx *opagdl = NULL;
	Gfx *xlugdl = NULL;

	if ((types & VTXBATCHTYPE_OPA) && opablocks) {
		opagdl = bgGetNextGdlInBlock(opablocks, start, NULL);

		if (types == VTXBATCHTYPE_OPA) {
			return opagdl;
		}
	}

	if ((types & VTXBATCHTYPE_XLU) && xlublocks) {
		xlugdl = bgGetNextGdlInBlock(xlublocks, start, NULL);

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

Vtx *bgFindVerticesForGdl(s32 roomnum, Gfx *gdl)
{
	struct roomblock *block = g_Rooms[roomnum].gfxdata->blocks;
	uintptr_t end = (uintptr_t)g_Rooms[roomnum].gfxdata->vertices;

	while ((uintptr_t)(block + 1) <= end) {
		switch (block->type) {
		case ROOMBLOCKTYPE_LEAF:
			if (gdl == block->gdl) {
				return block->vertices;
			}
			break;
		case ROOMBLOCKTYPE_PARENT:
			if ((uintptr_t)block->unk0c < end) {
				end = (uintptr_t)block->unk0c;
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
/*  f15dcc8:	0fc47b6c */ 	jal	debugIsRoomGfxExtraMemEnabled
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
/*  f15e090:	0fc576ad */ 	jal	bgGetNextGdlInLayer
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
/*  f15e0c8:	0fc576ad */ 	jal	bgGetNextGdlInLayer
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
/*  f15e0f4:	0fc576ed */ 	jal	bgFindVerticesForGdl
/*  f15e0f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e0fc:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f15e100:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15e104:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f15e108:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f15e10c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e110:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e114:	0fc576ad */ 	jal	bgGetNextGdlInLayer
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
/*  f15e2c4:	3c19800a */ 	lui	$t9,%hi(g_EnvHasTransparency)
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
/*  f15e3ac:	8f3965e4 */ 	lw	$t9,%lo(g_EnvHasTransparency)($t9)
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
/*  f1583fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b1a2cnb)
/*  f158400:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f158404:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f158408:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f15840c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f158410:	24841a2c */ 	addiu	$a0,$a0,%lo(var7f1b1a2cnb)
/*  f158414:	0fc55704 */ 	jal	bgVerifyLightSums
/*  f158418:	24051ba4 */ 	addiu	$a1,$zero,0x1ba4
/*  f15841c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158420:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x2bc)
/*  f158424:	5080020e */ 	beqzl	$a0,.NB0f158c60
/*  f158428:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15842c:	8dcee97c */ 	lw	$t6,%lo(g_Vars+0x2bc)($t6)
/*  f158430:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f158434:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f158438:	008e082a */ 	slt	$at,$a0,$t6
/*  f15843c:	10200207 */ 	beqz	$at,.NB0f158c5c
/*  f158440:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f158444:	3c18800b */ 	lui	$t8,%hi(g_Rooms)
/*  f158448:	8f1890a8 */ 	lw	$t8,%lo(g_Rooms)($t8)
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
/*  f158474:	0fc46652 */ 	jal	debugIsRoomGfxExtraMemEnabled
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
/*  f1584c4:	3c11800b */ 	lui	$s1,%hi(g_BgRooms)
/*  f1584c8:	26319444 */ 	addiu	$s1,$s1,%lo(g_BgRooms)
/*  f1584cc:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f1584d0:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1584d4:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f1584d8:	000e8080 */ 	sll	$s0,$t6,0x2
/*  f1584dc:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f1584e0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1584e4:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f1584e8:	3c04800b */ 	lui	$a0,%hi(g_BgPrimaryData)
/*  f1584ec:	8c84909c */ 	lw	$a0,%lo(g_BgPrimaryData)($a0)
/*  f1584f0:	03039023 */ 	subu	$s2,$t8,$v1
/*  f1584f4:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f1584f8:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f1584fc:	8fa702f4 */ 	lw	$a3,0x2f4($sp)
/*  f158500:	0241c824 */ 	and	$t9,$s2,$at
/*  f158504:	00645821 */ 	addu	$t3,$v1,$a0
/*  f158508:	3c01f100 */ 	lui	$at,0xf100
/*  f15850c:	3c0c8008 */ 	lui	$t4,%hi(var8007fc54)
/*  f158510:	01642823 */ 	subu	$a1,$t3,$a0
/*  f158514:	8d8c24b8 */ 	lw	$t4,%lo(var8007fc54)($t4)
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
/*  f1585a0:	3c09800b */ 	lui	$t1,%hi(g_Rooms)
/*  f1585a4:	252990a8 */ 	addiu	$t1,$t1,%lo(g_Rooms)
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
/*  f15883c:	0fc56093 */ 	jal	bgGetNextGdlInLayer
/*  f158840:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158844:	3c0c800b */ 	lui	$t4,%hi(g_Rooms)
/*  f158848:	8d8c90a8 */ 	lw	$t4,%lo(g_Rooms)($t4)
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
/*  f158874:	0fc56093 */ 	jal	bgGetNextGdlInLayer
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
/*  f1588a4:	0fc560d3 */ 	jal	bgFindVerticesForGdl
/*  f1588a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588ac:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f1588b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1588b4:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f1588b8:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f1588bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1588c0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f1588c4:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f1588c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588cc:	0fc56093 */ 	jal	bgGetNextGdlInLayer
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
/*  f1589dc:	3c0d800b */ 	lui	$t5,%hi(g_Rooms)
/*  f1589e0:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f1589e4:	ad860000 */ 	sw	$a2,0x0($t4)
/*  f1589e8:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f1589ec:	8dad90a8 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f1589f0:	00d3c023 */ 	subu	$t8,$a2,$s3
/*  f1589f4:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f1589f8:	35f9000f */ 	ori	$t9,$t7,0xf
/*  f1589fc:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f158a00:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f158a04:	3b2b000f */ 	xori	$t3,$t9,0xf
/*  f158a08:	ac6b0080 */ 	sw	$t3,0x80($v1)
/*  f158a0c:	3c0c800b */ 	lui	$t4,%hi(g_Rooms)
/*  f158a10:	8d8c90a8 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f158a14:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f158a18:	3c047f1b */ 	lui	$a0,%hi(var7f1b1a34nb)
/*  f158a1c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f158a20:	8c6e0080 */ 	lw	$t6,0x80($v1)
/*  f158a24:	004e082a */ 	slt	$at,$v0,$t6
/*  f158a28:	5020000a */ 	beqzl	$at,.NB0f158a54
/*  f158a2c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f158a30:	0c003074 */ 	jal	crashSetMessage
/*  f158a34:	24841a34 */ 	addiu	$a0,$a0,%lo(var7f1b1a34nb)
/*  f158a38:	24180045 */ 	addiu	$t8,$zero,0x45
/*  f158a3c:	a0180000 */ 	sb	$t8,0x0($zero)
/*  f158a40:	3c0f800b */ 	lui	$t7,%hi(g_Rooms)
/*  f158a44:	8def90a8 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f158a48:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f158a4c:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f158a50:	240a0001 */ 	addiu	$t2,$zero,0x1
.NB0f158a54:
/*  f158a54:	a46a0002 */ 	sh	$t2,0x2($v1)
/*  f158a58:	3c0b800b */ 	lui	$t3,%hi(g_Rooms)
/*  f158a5c:	8d6b90a8 */ 	lw	$t3,%lo(g_Rooms)($t3)
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
/*  f158a88:	3c0e800b */ 	lui	$t6,%hi(g_Rooms)
/*  f158a8c:	8dce90a8 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f158a90:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f158a94:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f158a98:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f158a9c:	8c720014 */ 	lw	$s2,0x14($v1)
.NB0f158aa0:
/*  f158aa0:	3c0c800b */ 	lui	$t4,%hi(g_FogEnabled)
/*  f158aa4:	3c0d800b */ 	lui	$t5,%hi(g_Rooms)
/*  f158aa8:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f158aac:	26450018 */ 	addiu	$a1,$s2,0x18
/*  f158ab0:	24a90014 */ 	addiu	$t1,$a1,0x14
/*  f158ab4:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f158ab8:	14200026 */ 	bnez	$at,.NB0f158b54
/*  f158abc:	3c0e800b */ 	lui	$t6,%hi(g_EnvHasTransparency)
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
/*  f158b54:	8d8caea0 */ 	lw	$t4,%lo(g_FogEnabled)($t4)
/*  f158b58:	11800012 */ 	beqz	$t4,.NB0f158ba4
/*  f158b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b60:	8dad90a8 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f158b64:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f158b68:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f158b6c:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f158b70:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*  f158b74:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158b78:	8de40008 */ 	lw	$a0,0x8($t7)
/*  f158b7c:	3c19800b */ 	lui	$t9,%hi(g_Rooms)
/*  f158b80:	8f3990a8 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f158b84:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f158b88:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f158b8c:	032b6021 */ 	addu	$t4,$t9,$t3
/*  f158b90:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*  f158b94:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158b98:	8da4000c */ 	lw	$a0,0xc($t5)
/*  f158b9c:	10000014 */ 	beqz	$zero,.NB0f158bf0
/*  f158ba0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f158ba4:
/*  f158ba4:	8dceaea4 */ 	lw	$t6,%lo(g_EnvHasTransparency)($t6)
/*  f158ba8:	3c18800b */ 	lui	$t8,%hi(g_Rooms)
/*  f158bac:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f158bb0:	15c0000f */ 	bnez	$t6,.NB0f158bf0
/*  f158bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158bb8:	8f1890a8 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f158bbc:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f158bc0:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f158bc4:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f158bc8:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158bcc:	8d640008 */ 	lw	$a0,0x8($t3)
/*  f158bd0:	3c0c800b */ 	lui	$t4,%hi(g_Rooms)
/*  f158bd4:	8d8c90a8 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f158bd8:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f158bdc:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f158be0:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f158be4:	8dd80014 */ 	lw	$t8,0x14($t6)
/*  f158be8:	0fc57fca */ 	jal	gfxReplaceGbiCommandsRecursively
/*  f158bec:	8f04000c */ 	lw	$a0,0xc($t8)
.NB0f158bf0:
/*  f158bf0:	0fc565e7 */ 	jal	bgFindRoomVtxBatches
/*  f158bf4:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f158bf8:	3c0f800b */ 	lui	$t7,%hi(g_Rooms)
/*  f158bfc:	8def90a8 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f158c00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f158c04:	3c0d800b */ 	lui	$t5,%hi(g_Rooms)
/*  f158c08:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f158c0c:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f158c10:	946b0000 */ 	lhu	$t3,0x0($v1)
/*  f158c14:	3c19800b */ 	lui	$t9,%hi(g_Rooms)
/*  f158c18:	356c0100 */ 	ori	$t4,$t3,0x100
/*  f158c1c:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f158c20:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f158c24:	8dad90a8 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f158c28:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f158c2c:	94780000 */ 	lhu	$t8,0x0($v1)
/*  f158c30:	370f0200 */ 	ori	$t7,$t8,0x200
/*  f158c34:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f158c38:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f158c3c:	8f3990a8 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f158c40:	032b6021 */ 	addu	$t4,$t9,$t3
/*  f158c44:	0fc4db9c */ 	jal	dyntexSetCurrentRoom
/*  f158c48:	ad800058 */ 	sw	$zero,0x58($t4)
/*  f158c4c:	3c047f1b */ 	lui	$a0,%hi(var7f1b1a60nb)
/*  f158c50:	24841a60 */ 	addiu	$a0,$a0,%lo(var7f1b1a60nb)
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
	uintptr_t end1;
	s32 i; // 6c
	uintptr_t end2;
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
	if (g_Rooms[roomnum].gfxdatalen > 0) {
		size = g_Rooms[roomnum].gfxdatalen;

		if (debugIsRoomGfxExtraMemEnabled()) {
			size += 1024;
		}
	} else {
		size = memaGetLongestFree();
	}

	// Try to free enough bytes
	bgGarbageCollectRooms(size, false);

	// Make the allocation
	allocation = memaAlloc(size);

	if (allocation != NULL) {
		dyntexSetCurrentRoom(roomnum);

		// Calculate the file offset and read length
		// of the compressed room data in the BG file
		readlen = ((g_BgRooms[roomnum + 1].unk00 - g_BgRooms[roomnum].unk00) + 0xf) & ~0xf;
		fileoffset = (g_BgPrimaryData + g_BgRooms[roomnum].unk00 - g_BgPrimaryData) - 0x0f000000;
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
			g_Rooms[roomnum].gfxdata->vertices = (Vtx *)((uintptr_t)g_Rooms[roomnum].gfxdata->vertices - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->colours) {
			g_Rooms[roomnum].gfxdata->colours = (Col *)((uintptr_t)g_Rooms[roomnum].gfxdata->colours - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->opablocks) {
			g_Rooms[roomnum].gfxdata->opablocks = (struct roomblock *)((uintptr_t)g_Rooms[roomnum].gfxdata->opablocks - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
		}

		if (g_Rooms[roomnum].gfxdata->xlublocks) {
			g_Rooms[roomnum].gfxdata->xlublocks = (struct roomblock *)((uintptr_t)g_Rooms[roomnum].gfxdata->xlublocks - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
		}

		// Promote offsets to pointers in each gfxdata block
		block1 = g_Rooms[roomnum].gfxdata->blocks;
		end1 = (uintptr_t)g_Rooms[roomnum].gfxdata->vertices;

		while ((intptr_t) (block1 + 1) <= end1) {
			switch (block1->type) {
			case ROOMBLOCKTYPE_LEAF:
				if (block1->next != NULL) {
					block1->next = (struct roomblock *)((uintptr_t)block1->next - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->gdl != 0) {
					block1->gdl = (Gfx *)((uintptr_t)block1->gdl - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->vertices != 0) {
					block1->vertices = (Vtx *)((uintptr_t)block1->vertices - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->colours != 0) {
					block1->colours = (Col *)((uintptr_t)block1->colours - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				break;
			case ROOMBLOCKTYPE_PARENT:
				if (block1->next != NULL) {
					block1->next = (struct roomblock *)((uintptr_t)block1->next - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->gdl != 0) {
					block1->gdl = (Gfx *)((uintptr_t)block1->gdl - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->vertices != 0) {
					block1->vertices = (Vtx *)((uintptr_t)block1->vertices - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if (block1->colours != 0) {
					block1->colours = (Col *)((uintptr_t)block1->colours - g_BgRooms[roomnum].unk00 + (uintptr_t)allocation);
				}
				if ((uintptr_t)block1->vertices < end1) {
					end1 = (uintptr_t)block1->vertices;
				}
				break;
			}

			block1++;
		}

		// Calculate the number of vertices and colours
		g_Rooms[roomnum].gfxdata->numvertices = ((uintptr_t)g_Rooms[roomnum].gfxdata->colours - (uintptr_t)g_Rooms[roomnum].gfxdata->vertices) / sizeof(Vtx);
		g_Rooms[roomnum].gfxdata->numcolours = ((uintptr_t)bgGetNextGdlInLayer(roomnum, 0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU) - (uintptr_t)g_Rooms[roomnum].gfxdata->colours) / sizeof(u32);

		// Build arrays of pointers to gfx blocks and vtx blocks
		len = 0;
		v0 = (u8 *) bgGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);

		while (v0) {
			gfxblocks[len] = v0;
			vtxblocks[len] = (u8 *) bgFindVerticesForGdl(roomnum, (void *) v0);
			len++;

			v0 = (u8 *) bgGetNextGdlInLayer(roomnum, (void *) v0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);
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
			a2 = (u8 *) ALIGN8((intptr_t) a2);
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
			memaRealloc((intptr_t) allocation, size, g_Rooms[roomnum].gfxdatalen);
		}

		// Update gdl pointers in the gfxdata so they point to the ones
		// that have been processed by the texture decompressor.
		block2 = g_Rooms[roomnum].gfxdata->blocks; // a1 =
		end2 = (uintptr_t) g_Rooms[roomnum].gfxdata->vertices; // a3 =

		while ((intptr_t) (block2 + 1) <= end2) {
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
				if ((uintptr_t) block2->unk0c < end2) {
					end2 = (uintptr_t) block2->unk0c;
				}
				break;
			}

			block2++;
		}

		// Do some find/replaces in the gdls based on some configuration
		if (g_FogEnabled) {
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->opablocks, 1);
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->xlublocks, 5);
		} else if (!g_EnvHasTransparency) {
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->opablocks, 6);
			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->xlublocks, 7);
		}

		// Create vertex batches - these are used for hit detection
		bgFindRoomVtxBatches(roomnum);

		g_Rooms[roomnum].flags |= ROOMFLAG_LIGHTS_DIRTY;
		g_Rooms[roomnum].flags |= ROOMFLAG_BRIGHTNESS_DIRTY_PERM;

		g_Rooms[roomnum].colours = NULL;

		dyntexSetCurrentRoom(-1);

#if VERSION < VERSION_NTSC_1_0
		bgVerifyLightSums("bg.c", 7474);
#endif
	}
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
	uintptr_t v0;

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

		v0 = (uintptr_t)g_Rooms[roomnum].colours;

		if (v0 != NULL) {
			s32 addr = ALIGN8((uintptr_t)&g_Rooms[roomnum].gfxdata->vertices[g_Rooms[roomnum].gfxdata->numvertices]);
			v0 += (((intptr_t)block->colours - addr) >> 2) * 4;
		} else {
			v0 = (uintptr_t)block->colours;
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

	gdl = roomApplyMtx(gdl, roomnum);

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

		gdl = roomApplyMtx(gdl, roomnum);
		gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->xlublocks, true);

		g_Rooms[roomnum].loaded240 = 1;
	} else {
		bgLoadRoom(roomnum);
	}

	return gdl;
}

s32 bgPopulateVtxBatchType(s32 roomnum, struct vtxbatch *batches, Gfx *gdl, s32 batchindex, Vtx *vertices, s32 type)
{
	s32 i;
	s32 j;
	s32 numvertices;
	Vtx *batchvertices;

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
			batchvertices = (Vtx *)((uintptr_t)vertices + (gdl[i].words.w1 & 0xffffff));

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
		gdl = bgGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA);

		if (gdl != NULL) {
			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gSPVertex
					if (gdl[i].dma.cmd == G_VTX) {
						batchindex++;
					}
				}

				gdl = bgGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_OPA);
			}

			xlucount = 0;

			gdl = bgGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_XLU);

			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gSPVertex
					if (gdl[i].dma.cmd == G_VTX) {
						xlucount++;
					}
				}

				gdl = bgGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_XLU);
			}

			batchindex += xlucount;

			batches = memaAlloc((batchindex * sizeof(struct vtxbatch) + 0xf) & ~0xf);

			if (batches != NULL) {
				gdl = bgGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_OPA);
				batchindex = 0;

				g_Rooms[roomnum].vtxbatches = batches;

				while (gdl) {
					Vtx *vertices = bgFindVerticesForGdl(roomnum, gdl);
					batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_OPA);
					gdl = bgGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_OPA);
				}

				if (xlucount) {
					gdl = bgGetNextGdlInLayer(roomnum, NULL, VTXBATCHTYPE_XLU);

					while (gdl) {
						Vtx *vertices = bgFindVerticesForGdl(roomnum, gdl);
						batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_XLU);
						gdl = bgGetNextGdlInLayer(roomnum, gdl, VTXBATCHTYPE_XLU);
					}
				}

				g_Rooms[roomnum].numvtxbatches = (s16)batchindex;
			}
		}
	}
}

bool bgTestLineIntersectsIntBbox(struct coord *arg0, struct coord *arg1, s32 *arg2, s32 *arg3)
{
	struct coord arg2f;
	struct coord arg3f;

	arg2f.x = arg2[0];
	arg2f.y = arg2[1];
	arg2f.z = arg2[2];

	arg3f.x = arg3[0];
	arg3f.y = arg3[1];
	arg3f.z = arg3[2];

	return bgTestLineIntersectsBbox(arg0, arg1, &arg2f, &arg3f);
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
		Gfx *gdl2, Vtx *vertices, struct hitthing *hitthing)
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
	Vtx *vtx;
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
			vtx = (Vtx *)((uintptr_t)vertices + offset);
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
									&& func0002f560(point1, point2, point3, NULL, arg0, arg1, arg2, &sp8c, &sp80)) {
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
		Gfx *gdl, Gfx *gdl2, Vtx *vertices, f32 *sqdistptr, struct hitthing *hitthing)
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
	Vtx *vtx;
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
			vtx = (Vtx *)((uintptr_t)vertices + word);

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
									&& func0002f560(point1, point2, point3, NULL, arg1, arg2, arg3, &sp84, &sp78)) {
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
	Vtx *vtx;
	f32 *ptr;
	Gfx *iter;
	Gfx *tmpgdl;
	Gfx *tri4gdl;

	vtx = bgFindVerticesForGdl(roomnum, gdl);
	iter = &gdl[batch->gbicmdindex];
	vtx = (Vtx *)((iter->words.w1 & 0xffffff) + (s32)vtx);
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
											&& func0002f560(point1, point2, point3, NULL, arg0, arg1, arg2, &spb0, &spa4)) {
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

s32 bg0f1612e4(struct coord *bbmin, struct coord *bbmax, struct coord *frompos, struct coord *dist, struct coord *arg4, struct coord *arg5)
{
	s32 i;
	u8 bail = true;
	s8 sp48[3];
	s32 bestindex;
	f32 sp38[3];
	f32 sp2c[3];

	for (i = 0; i < 3; i++) {
		if (frompos->f[i] < bbmin->f[i]) {
			sp48[i] = 1;
			sp38[i] = bbmin->f[i];
			bail = false;
		} else if (frompos->f[i] > bbmax->f[i]) {
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
		if (sp48[i] != 2 && dist->f[i] != 0.0f) {
			sp2c[i] = (sp38[i] - frompos->f[i]) * arg4->f[i];
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
			arg5->f[i] = frompos->f[i] + sp2c[bestindex] * dist->f[i];

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
	struct coord from;
	struct coord to;
	struct coord dist;
	struct coord sp94;
	struct vtxbatch *batch;
	struct hitthing sp60;
	s32 tmpindex;

	count = 0;

	from.x = frompos->x;
	from.y = frompos->y;
	from.z = frompos->z;

	to.x = topos->x;
	to.y = topos->y;
	to.z = topos->z;

	dist.x = to.x - from.x;
	dist.y = to.y - from.y;
	dist.z = to.z - from.z;

	sp94.x = 1.0f / dist.x;
	sp94.y = 1.0f / dist.y;
	sp94.z = 1.0f / dist.z;

	if (roomnum < 0 || roomnum >= g_Vars.roomcount) {
		return false;
	}

	batch = g_Rooms[roomnum].vtxbatches;

	if (batch == NULL) {
		return false;
	}

	numbatches = g_Rooms[roomnum].numvtxbatches;

	for (i = 0; i < numbatches; batch++, i++) {
		j = bg0f1612e4(&batch->bbmin, &batch->bbmax, &from, &dist, &sp94, &hitthing->unk00);

		if (j == 0) {
			continue;
		}

		if (j == 1) {
			f0 = from.x - hitthing->unk00.x;
			f20 = f0 * f0;

			f0 = from.y - hitthing->unk00.y;
			f20 += f0 * f0;

			f0 = from.z - hitthing->unk00.z;
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
				if (bgTestHitInVtxBatch(&from, &to, &dist, &g_Rooms[roomnum].vtxbatches[var800a6538[j].vtxbatchindex], roomnum, hitthing)) {
					f0 = from.x - hitthing->unk00.x;
					f2 = f0 * f0;

					f0 = from.y - hitthing->unk00.y;
					f2 += f0 * f0;

					f0 = from.z - hitthing->unk00.z;
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
		if (bgTestHitInVtxBatch(&from, &to, &dist, &batch[var800a6538[i].vtxbatchindex], roomnum, hitthing)) {
			i++;

			if (i < count) {
				f0 = from.x - hitthing->unk00.x;
				spc8 = f0 * f0;

				f0 = from.y - hitthing->unk00.y;
				spc8 += f0 * f0;

				f0 = from.z - hitthing->unk00.z;
				spc8 += f0 * f0;

				for (; i < count; i++) {
					if (var800a6538[i].unk04 <= spc8) {
						if (bgTestHitInVtxBatch(&from, &to, &dist, &batch[var800a6538[i].vtxbatchindex], roomnum, &sp60)) {
							f0 = from.f[0] - sp60.unk00.f[0];
							f20 = f0 * f0;

							f0 = from.f[1] - sp60.unk00.f[1];
							f20 += f0 * f0;

							f0 = from.f[2] - sp60.unk00.f[2];
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

bool bgRoomIsLoaded(s32 room)
{
	return g_Rooms[room].loaded240;
}

bool bgRoomContainsCoord(struct coord *pos, s16 roomnum)
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

/**
 * Test if a world position is inside a room based on portal checks only.
 *
 * It works by iterating the portals for the given room and checking which side
 * of the portal the position is on. If the position is on the "inside" of all
 * portals then the position is determined to be in the room.
 *
 * Note that:
 * - Clockwise portal vertices makes the normal face towards the viewer.
 * - The normal points towards the front of the portal.
 * - The room on the front side is roomnum2.
 */
bool bgTestPosInRoomCheap(struct coord *pos, s16 roomnum)
{
	s32 i;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		struct portalmetric *metric = &g_PortalMetrics[portalnum];

		f32 value = metric->normal.f[0] * pos->f[0]
			+ metric->normal.f[1] * pos->f[1]
			+ metric->normal.f[2] * pos->f[2];

		if (value < metric->min) {
			if (roomnum != g_BgPortals[portalnum].roomnum1) {
				return false;
			}
		} else if (value > metric->max) {
			if (roomnum != g_BgPortals[portalnum].roomnum2) {
				return false;
			}
		}
	}

	return true;
}

bool bgTestPosInRoomExpensive(struct coord *pos, s16 roomnum)
{
	s32 t5;
	struct coord *next;
	s32 t4;
	s32 portalnum;
	struct portalmetric *metric;
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
		metric = &g_PortalMetrics[portalnum];

		f0 = pos->f[0] * metric->normal.f[0] + pos->f[1] * metric->normal.f[1] + pos->f[2] * metric->normal.f[2];
		f18 = sp74.f[0] * metric->normal.f[0] + sp74.f[1] * metric->normal.f[1] + sp74.f[2] * metric->normal.f[2];

		if (f0 < metric->min) {
			if (f18 < metric->min) {
				continue;
			}
		} else {
			if (f0 > metric->max && f18 > metric->max) {
				continue;
			}
		}

		sp68.f[0] = sp74.f[0] - pos->f[0];
		sp68.f[1] = sp74.f[1] - pos->f[1];
		sp68.f[2] = sp74.f[2] - pos->f[2];

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
			sum = sp4c.f[0] * pos->f[0] + sp4c.f[1] * pos->f[1] + sp4c.f[2] * pos->f[2];

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
			if (f0 < metric->min) {
				if (roomnum == g_BgPortals[portalnum].roomnum2) {
					return false;
				}
			} else if (f0 > metric->max) {
				if (roomnum == g_BgPortals[portalnum].roomnum1) {
					return false;
				}
			}
		}
	}

	return true;
}

bool bgTestPosInRoom(struct coord *pos, s16 roomnum)
{
	if (g_Rooms[roomnum].flags & ROOMFLAG_COMPLICATEDPORTALS) {
		return bgTestPosInRoomExpensive(pos, roomnum);
	} else {
		return bgTestPosInRoomCheap(pos, roomnum);
	}
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

bool bgCmdPushValue(bool value)
{
	g_BgCmdStack[g_BgCmdStackIndex] = value;
	g_BgCmdStackIndex = (g_BgCmdStackIndex + 1) % 20;

	return value;
}

bool bgCmdPopValue(void)
{
	bool val = g_BgCmdStack[g_BgCmdStackIndex = (g_BgCmdStackIndex + 19) % 20];
	return val;
}

bool bgCmdGetNthValueFromEnd(s32 n)
{
	return g_BgCmdStack[((g_BgCmdStackIndex - n) + 19) % 20];
}

/**
 * BG files contain bytecode that is used to override the default portal
 * behaviour. They can be used to check if the camera is in particular rooms
 * and then force other rooms to show or hide.
 *
 * Only six BG files use of this feature. They are Villa, Chicago, Area 51,
 * Pelagic II, Deep Sea and Skedar Ruins. All other BG files contain a single
 * "end" instruction in their bytecode.
 *
 * The scripting language supports if-statements with an infinite nesting level.
 * The interpreter maintains a stack of boolean values which can be pushed to
 * or popped from the end. This can be used to build complex conditions that
 * combine "AND" and "OR" operations.
 *
 * All commands are interpreted in order. There is no support for loops.
 *
 * When processing conditional code the function calls itself recursively for
 * that branch. The execute argument denotes whether the condition passed and
 * these statements should be executed, or whether the condition failed and
 * it's just passing over them to get to the endif command.
 */
struct bgcmd *bgCmdExecuteBranch(struct bgcmd *cmd, bool execute)
{
	s32 i;

	g_BgCmdThrowing = false;

	if (!cmd) {
		return cmd;
	}

	while (true) {
		switch (cmd->type) {
		case BGCMD_END:
			return cmd;
		case BGCMD_PUSH:
			if (execute) {
				bgCmdPushValue(cmd->param);
			}
			cmd += cmd->len;
			break;
		case BGCMD_POP:
			if (execute) {
				bgCmdPopValue();
			}
			cmd += cmd->len;
			break;
		case BGCMD_AND:
			if (execute) {
				bgCmdPushValue(bgCmdPopValue() & bgCmdPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_OR:
			if (execute) {
				bgCmdPushValue(bgCmdPopValue() | bgCmdPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_NOT:
			if (execute) {
				bgCmdPushValue(bgCmdPopValue() == 0);
			}
			cmd += cmd->len;
			break;
		case BGCMD_XOR:
			if (execute) {
				bgCmdPushValue(bgCmdPopValue() ^ bgCmdPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_PUSH_CAMINROOMRANGE:
			if (execute) {
				bgCmdPushValue(g_CamRoom >= cmd[1].param && g_CamRoom <= cmd[2].param);
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_TRUE:
			if (execute) {
				g_BgCmdScreenBox.xmin = g_Vars.currentplayer->screenxminf;
				g_BgCmdScreenBox.ymin = g_Vars.currentplayer->screenyminf;
				g_BgCmdScreenBox.xmax = g_Vars.currentplayer->screenxmaxf;
				g_BgCmdScreenBox.ymax = g_Vars.currentplayer->screenymaxf;
				g_BgCmdResult = BGRESULT_TRUE;
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_IFPORTALINFOV:
			if (execute) {
				if (!PORTAL_IS_CLOSED(cmd[1].param)) {
					if (!bgGetPortalScreenBbox(cmd[1].param, &g_PortalScreenBbox)) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (bgGetBoxIntersection(&g_BgCmdScreenBox, &g_PortalScreenBbox) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else {
						g_BgCmdResult = BGRESULT_TRUE;
					}
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_TRUEIFTHROUGHPORTAL:
			if (execute) {
				struct screenbox portalbox;

				if (!PORTAL_IS_CLOSED(cmd[1].param)) {
					if (bgGetPortalScreenBbox(cmd[1].param, &portalbox) && bgGetBoxIntersection(&g_BgCmdScreenBox, &portalbox)) {
						if (g_BgCmdResult != BGRESULT_TRUE) {
							bgCopyBox(&g_BgCmdScreenBox, &portalbox);
							g_BgCmdResult = BGRESULT_TRUE;
						} else {
							bgExpandBox(&g_BgCmdScreenBox, &portalbox);
						}
					}
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_FALSEIFNOTTHROUGHPORTAL:
			if (execute) {
				if (g_BgCmdResult == BGRESULT_TRUE) {
					struct screenbox portalbox;

					if (PORTAL_IS_CLOSED(cmd[1].param)) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (!bgGetPortalScreenBbox(cmd[1].param, &portalbox)) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (bgGetBoxIntersection(&portalbox, (struct screenbox *)&g_Vars.currentplayer->screenxminf) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (bgGetBoxIntersection(&g_PortalScreenBbox, &portalbox) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					}
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_IFRESULT_SHOWROOM:
			if (execute) {
				if (g_BgCmdResult == BGRESULT_TRUE && bgRoomIntersectsScreenBox(cmd[1].param, &g_BgCmdScreenBox)) {
					bgSetRoomOnscreen(cmd[1].param, 0, &g_BgCmdScreenBox);
					g_BgForceOnscreenRooms[g_BgNumForceOnscreenRooms++] = cmd[1].param;
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_DISABLEROOM:
			if (execute) {
				g_Rooms[cmd[1].param].flags |= ROOMFLAG_DISABLEDBYSCRIPT;
			}
			cmd += cmd->len;
			break;
		case BGCMD_DISABLEROOMRANGE:
			if (execute) {
				for (i = cmd[1].param; i <= cmd[2].param; i++) {
					g_Rooms[i].flags |= ROOMFLAG_DISABLEDBYSCRIPT;
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_LOADROOM:
			cmd += cmd->len;
			break;
		case BGCMD_LOADROOMRANGE:
			cmd += cmd->len;
			break;
		case BGCMD_SETROOMTESTSDISABLED:
			if (execute) {
				g_BgRoomTestsDisabled = true;
			}
			cmd += cmd->len;
			break;
		case BGCMD_PUSH_PORTALISOPEN:
			if (execute) {
				bgCmdPushValue(!PORTAL_IS_CLOSED(cmd[1].param));
			}
			cmd += cmd->len;
			break;
		case BGCMD_2A:
			if (execute) {
				g_Rooms[cmd[1].param].unk07 = 0;
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_FALSE:
			if (execute) {
				g_BgCmdResult = BGRESULT_FALSE;
			}
			cmd += cmd->len;
			break;
		case BGCMD_BRANCH:
			cmd = bgCmdExecuteBranch(cmd + cmd->len, execute);
			cmd += cmd->len;
			break;
		case BGCMD_CATCH:
			cmd += cmd->len;
			g_BgCmdThrowing = false;
			return cmd;
		case BGCMD_THROW:
			cmd += cmd->len;
			if (execute) {
				g_BgCmdThrowing = true;
			}
			execute = false;
			break;
		case BGCMD_IF:
			cmd = bgCmdExecuteBranch(cmd + cmd->len, bgCmdPopValue() & execute);
			if (g_BgCmdThrowing) {
				execute = false;
			}
			break;
		case BGCMD_ELSE:
			/**
			 * Assuming this is indeed an else command, it's not safe to assume
			 * that the execution state can be unconditionally toggled.
			 * For example, given the following portal code:
			 *
			 * if (a false condition)
			 *     if (any condition)
			 *         branch 1
			 *     else
			 *         branch 2
			 *     endif
			 * endif
			 *
			 * ...when reaching the else, execution would be turned on.
			 *
			 * However, this command isn't even used.
			 */
			execute ^= 1;
			cmd += cmd->len;
			break;
		case BGCMD_ENDIF:
			/**
			 * Note the return here rather than break.
			 */
			cmd += cmd->len;
			return cmd;
		default:
			if (1);
			if (1);
			if (1);
			if (1);
			return cmd;
		}
	}

	g_BgCmdThrowing = false;

	return cmd;
}

struct bgcmd *bgCmdExecute(struct bgcmd *cmd)
{
	struct player *player = g_Vars.currentplayer;
	g_BgCmdResult = BGRESULT_TRUE;

	if (!cmd) {
		return cmd;
	}

	// This may have been used in an osSyncPrintf call
	bgCmdGetNthValueFromEnd(0);

	g_BgCmdScreenBox.xmin = player->screenxminf;
	g_BgCmdScreenBox.ymin = player->screenyminf;
	g_BgCmdScreenBox.xmax = player->screenxmaxf;
	g_BgCmdScreenBox.ymax = player->screenymaxf;

	return bgCmdExecuteBranch(cmd, true);
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
	struct drawslot *thing;

	static u32 edist = 400;

	bgCalculateScreenProperties();

	if (g_BgDrawSlots);

	if (g_BgNumAttemptedDrawSlots > g_BgMostAttemptedDrawSlots) {
		g_BgMostAttemptedDrawSlots = g_BgNumAttemptedDrawSlots;
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

	g_BgNumDrawSlots = 0;
	g_BgNumAttemptedDrawSlots = 0;

	g_BgDrawSlots[60].roomnum = -1;
	g_BgDrawSlots[60].draworder = 255;
	g_BgDrawSlots[60].box.xmin = xmin;
	g_BgDrawSlots[60].box.ymin = ymin;
	g_BgDrawSlots[60].box.xmax = xmax;
	g_BgDrawSlots[60].box.ymax = ymax;

	g_BgMaxDrawOrder = 0;
	g_BgMinDrawOrder = 0x7fff;

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (!(vismax.f[0] < g_Rooms[i].bbmin[0]) && !(vismin.f[0] > g_Rooms[i].bbmax[0])
				&& !(vismax.f[2] < g_Rooms[i].bbmin[2]) && !(vismin.f[2] > g_Rooms[i].bbmax[2])
				&& !(vismax.f[1] < g_Rooms[i].bbmin[1]) && !(vismin.f[1] > g_Rooms[i].bbmax[1])) {
			s32 index = g_BgNumDrawSlots;

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

				g_BgDrawSlots[index].roomnum = i;

				bgUnpausePropsInRoom(i, false);

				x = (g_Rooms[i].bbmin[0] + g_Rooms[i].bbmax[0]) / 2.0f - vismid.f[0];
				y = (g_Rooms[i].bbmin[1] + g_Rooms[i].bbmax[1]) / 2.0f - vismid.f[1];
				z = (g_Rooms[i].bbmin[2] + g_Rooms[i].bbmax[2]) / 2.0f - vismid.f[2];

				g_BgDrawSlots[index].draworder = sqrtf(x * x + y * y + z * z) / 100.0f;

				if (g_BgDrawSlots[index].draworder > g_BgMaxDrawOrder) {
					g_BgMaxDrawOrder = g_BgDrawSlots[index].draworder;
				}

				if (g_BgDrawSlots[index].draworder < g_BgMinDrawOrder) {
					g_BgMinDrawOrder = g_BgDrawSlots[index].draworder;
				}

				g_BgDrawSlots[index].box.xmin = xmin;
				g_BgDrawSlots[index].box.ymin = ymin;
				g_BgDrawSlots[index].box.xmax = xmax;
				g_BgDrawSlots[index].box.ymax = ymax;

				g_BgNumDrawSlots++;
				g_BgNumAttemptedDrawSlots++;

				g_Rooms[player->cam_room].flags |= ROOMFLAG_ONSCREEN;
			} else {
				// empty
			}
		}
	}

	bgChooseRoomsToLoad();
}

void bgAddToSnake(s16 fromroomnum, s16 roomnum, s16 depth, struct screenbox *box)
{
	struct bgsnakeitem *item;
	s32 i;
	s32 j;

	if (g_Rooms[roomnum].flags & ROOMFLAG_DISABLEDBYSCRIPT) {
		return;
	}

	if (depth >= 2) {
		if (g_Rooms[roomnum].portalrecursioncount < 255) {
			g_Rooms[roomnum].portalrecursioncount++;
		}

		if (g_Rooms[roomnum].portalrecursioncount > g_Vars.roomportalrecursionlimit) {
			return;
		}
	}

	if (g_Rooms[roomnum].snakecount != 0 && g_Rooms[roomnum].unk07) {
		i = g_BgSnake.tailindex;
		item = &g_BgSnake.items[i];

		while (i != g_BgSnake.headindex) {
			if (item->roomnum == roomnum) {
				for (j = 0; j < ARRAYCOUNT(item->fromroomnums); j++) {
					if (item->fromroomnums[j] == -1) {
						bgExpandBox(&item->screenbox, box);
						item->fromroomnums[j] = fromroomnum;
						return;
					}
				}
			}

			i++;
			item++;

			if (i == ARRAYCOUNT(g_BgSnake.items)) {
				i = 0;
				item = &g_BgSnake.items[0];
			}
		}
	}

	item = &g_BgSnake.items[g_BgSnake.headindex];
	item->fromroomnums[0] = fromroomnum;
	item->roomnum = roomnum;
	item->depth = depth;
	item->roomportallistoffset = g_Rooms[roomnum].roomportallistoffset;
	item->numportals = g_Rooms[roomnum].numportals;

	item->screenbox.xmin = box->xmin;
	item->screenbox.ymin = box->ymin;
	item->screenbox.xmax = box->xmax;
	item->screenbox.ymax = box->ymax;

	g_Rooms[roomnum].snakecount++;

	for (i = 1; i < ARRAYCOUNT(item->fromroomnums); i++) {
		item->fromroomnums[i] = -1;
	}

	g_BgSnake.headindex++;

	if (g_BgSnake.headindex == 250) {
		g_BgSnake.headindex = 0;
	}

	if (g_BgSnake.headindex == g_BgSnake.tailindex) {
		g_BgSnake.headindex--;
	}
}

/**
 * Iterate the given item/room's portals and check if each of the neighbouring
 * rooms should be onscreen or not.
 *
 * Those that should be onscreen are added to the draw list and appended to the
 * snake so its neighbours will be processed recursively.
 */
void bgConsumeSnakeItem(struct bgsnakeitem *item)
{
	struct coord *campos;
	s32 i;
	s16 portalnum;
	s16 prevvalidcount;
	s16 prevfoundroom;
	s16 newfoundroom;
	s16 side;
	s16 tmp;
	bool pass;
	struct portalmetric *metric;
	struct screenbox prevbox;
	struct screenbox newbox;
	f32 sum;

	g_Rooms[item->roomnum].snakecount--;
	g_BgSnake.count++;
	campos = &g_Vars.currentplayer->cam_pos;
	prevvalidcount = 0;
	prevfoundroom = -1;

	for (i = 0; i < item->numportals; i++) {
		portalnum = g_RoomPortals[item->roomportallistoffset + i];

		// Calculate which side of the portal the camera is on
		// if we haven't done it on this frame yet.
		if (g_PortalCameraCache[portalnum].updatedframe1 != g_BgFrameCount) {
			metric = &g_PortalMetrics[portalnum];

			sum = metric->normal.x * campos->f[0]
				+ metric->normal.y * campos->f[1]
				+ metric->normal.z * campos->f[2];

			if (sum < metric->min) {
				g_PortalCameraCache[portalnum].side = 1;
			} else if (sum > metric->max) {
				g_PortalCameraCache[portalnum].side = 0;
			} else {
				g_PortalCameraCache[portalnum].side = 2;
			}

			g_PortalCameraCache[portalnum].updatedframe1 = g_BgFrameCount;
		}

		// Swap the rooms if needed, or skip past this portal entirely if the
		// other room and camera room are on the same side.
		tmp = g_BgPortals[portalnum].roomnum1;
		side = g_PortalCameraCache[portalnum].side;

		if ((u32)tmp == item->roomnum) {
			if (side == 0) {
				continue;
			}

			newfoundroom = g_BgPortals[portalnum].roomnum2;
		} else {
			if (side == 1) {
				continue;
			}

			newfoundroom = tmp;
		}

		if (1);

		// Avoid adding a room twice in a row, which would happen if there are
		// multiple portals between the same two rooms.
		if (prevfoundroom != newfoundroom) {
			if (prevvalidcount) {
				bgSetRoomOnscreen(prevfoundroom, item->depth, &prevbox);
				bgAddToSnake(item->roomnum, prevfoundroom, item->depth + 1, &prevbox);
			}

			prevvalidcount = 0;
			prevfoundroom = newfoundroom;
		}

		// Not sure why this check isn't done first?
		if (PORTAL_IS_CLOSED(portalnum)) {
			continue;
		}

		// If this room has already been processed in the reverse direction,
		// there's no need to add it again.
		if (newfoundroom == item->fromroomnums[0]
				|| newfoundroom == item->fromroomnums[1]
				|| newfoundroom == item->fromroomnums[2]
				|| newfoundroom == item->fromroomnums[3]
				|| newfoundroom == item->fromroomnums[4]) {
			continue;
		}

		// Reusing the side variable as a bboxisvalid variable
		if (g_BgPortals[portalnum].flags & PORTALFLAG_02) {
			newbox.xmin = item->screenbox.xmin;
			newbox.ymin = item->screenbox.ymin;
			newbox.xmax = item->screenbox.xmax;
			newbox.ymax = item->screenbox.ymax;
			side = true;
		} else {
			side = bgGetPortalScreenBbox(portalnum, &newbox);
		}

		if (side) {
			bgGetBoxIntersection(&newbox, &item->screenbox);

			if (newbox.xmin < newbox.xmax && newbox.ymin < newbox.ymax) {
				if (prevvalidcount == 0) {
					prevbox.xmin = newbox.xmin;
					prevbox.ymin = newbox.ymin;
					prevbox.xmax = newbox.xmax;
					prevbox.ymax = newbox.ymax;
				} else {
					bgExpandBox(&prevbox, &newbox);
				}

				prevvalidcount++;
			}
		}
	}

	if (prevvalidcount != 0) {
		bgSetRoomOnscreen(prevfoundroom, item->depth, &prevbox);
		bgAddToSnake(item->roomnum, prevfoundroom, item->depth + 1, &prevbox);
	}
}

/**
 * The "snake" is a circular array with a head index and tail index.
 * Items (rooms) are added to the head of the snake and consumed from the tail.
 * Consuming an item may cause more items to be added to the head.
 * Eventually the tail catches up to the head and the snake is finished.
 *
 * The structure is used for discovering onscreen rooms.
 */
bool bgTryConsumeSnake(void)
{
	if (g_BgSnake.tailindex == g_BgSnake.headindex) {
		return false;
	}

	bgConsumeSnakeItem(&g_BgSnake.items[g_BgSnake.tailindex]);

	g_BgSnake.tailindex++;

	if (g_BgSnake.tailindex == ARRAYCOUNT(g_BgSnake.items)) {
		g_BgSnake.tailindex = 0;
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

				bgUnpausePropsInRoom(roomnum2, true);

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

				bgUnpausePropsInRoom(roomnum1, true);

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

	bgCalculateScreenProperties();

	box.xmin = player->screenxminf;
	box.ymin = player->screenyminf;
	box.xmax = player->screenxmaxf;
	box.ymax = player->screenymaxf;

	viGetZRange(&g_BgSnake.zrange);
	g_BgSnake.zrange.far = g_BgSnake.zrange.far / g_Vars.currentplayerstats->scale_bg2gfx;

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~(ROOMFLAG_DISABLEDBYSCRIPT | ROOMFLAG_ONSCREEN | ROOMFLAG_STANDBY | ROOMFLAG_LOADCANDIDATE);
		g_Rooms[i].portalrecursioncount = 0;
		g_Rooms[i].snakecount = 0;
		g_Rooms[i].unk07 = 1;
	}

	if (player->visionmode == VISIONMODE_XRAY) {
		bgTickPortalsXray();
	} else {
		if (g_BgNumAttemptedDrawSlots > g_BgMostAttemptedDrawSlots) {
			g_BgMostAttemptedDrawSlots = g_BgNumAttemptedDrawSlots;
		}

		g_BgNumDrawSlots = 0;
		g_BgNumAttemptedDrawSlots = 0;
		g_BgMaxDrawOrder = 0;
		g_BgMinDrawOrder = 32767;
		g_BgDrawSlots[60].roomnum = -1;
		g_BgDrawSlots[60].draworder = 255;
		g_BgSnake.count = 0;
		g_BgSnake.headindex = 0;
		g_BgSnake.tailindex = 0;
		g_BgRoomTestsDisabled = false;
		g_BgDrawSlots[60].box.xmin = box.xmin;
		g_BgDrawSlots[60].box.ymin = box.ymin;
		g_BgDrawSlots[60].box.xmax = box.xmax;
		g_BgDrawSlots[60].box.ymax = box.ymax;

		bgCmdExecute(g_BgCommands);

		if (!g_BgRoomTestsDisabled) {
			if (g_BgPortals[0].verticesoffset == 0) {
				for (room = 1; room < g_Vars.roomcount; room++) {
					if (bgRoomIntersectsScreenBox(room, &box)
							&& ((g_StageIndex != STAGEINDEX_INFILTRATION && g_StageIndex != STAGEINDEX_RESCUE && g_StageIndex != STAGEINDEX_ESCAPE) || room != 0xf)
							&& (g_StageIndex != STAGEINDEX_SKEDARRUINS || room != 0x02)
							&& ((g_StageIndex != STAGEINDEX_DEFECTION && g_StageIndex != STAGEINDEX_EXTRACTION) || room != 0x01)
							&& (g_StageIndex != STAGEINDEX_ATTACKSHIP || room != 0x71)) {
						bgSetRoomOnscreen(room, 0, &box);
					}
				}
			} else {
				bgSetRoomOnscreen(g_CamRoom, 0, &box);

				g_BgSnake.count = 0;
				g_BgSnake.headindex = 0;
				g_BgSnake.tailindex = 0;

				bgAddToSnake(g_CamRoom, g_CamRoom, 1, &box);

				while (bgTryConsumeSnake());
			}
		}

		bgChooseRoomsToLoad();
	}
}

Gfx *bgRenderSceneAndLoadCandidate(Gfx *gdl)
{
	gdl = bgRenderScene(gdl);
	gdl = bgScissorToViewport(gdl);

	if (g_Vars.currentplayerindex == 0) {
		g_BgLoadCandidateTimer240 -= g_Vars.lvupdate240;
	}

	if (g_BgLoadCandidateTimer240 < 0) {
		g_BgLoadCandidateTimer240 = 0;
	}

	// Consider loading one room by finding the load candidate that is closest to the player
	if (g_BgLoadCandidateTimer240 == 0 && var8007fc10 == 4 && g_Vars.tickmode == TICKMODE_NORMAL && IS8MB()) {
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
			g_BgLoadCandidateTimer240 = 64;
		}
	}

	return gdl;
}

s32 bgGetForceOnscreenRooms(s16 *rooms, s32 len)
{
	s32 i;

	for (i = 0; i < g_BgNumForceOnscreenRooms && i < len; i++) {
		rooms[i] = g_BgForceOnscreenRooms[i];
	}

	rooms[i] = -1;

	return i;
}

s32 bgRoomGetNeighbours(s32 roomnum, s16 *dstrooms, s32 len)
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

bool bgRoomsAreNeighbours(s32 roomnum1, s32 roomnum2)
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

void bgCalculateScreenProperties(void)
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
		struct portalvertices *pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

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

bool bgPortalExists(s32 portalnum)
{
	s32 i;

	for (i = 0; g_BgPortals[i].verticesoffset != 0; i++) {
		if (i == portalnum) {
			return true;
		}
	}

	return false;
}

void bgPortalSwapRooms(s32 portal)
{
	s16 tmp = g_BgPortals[portal].roomnum1;
	g_BgPortals[portal].roomnum1 = g_BgPortals[portal].roomnum2;
	g_BgPortals[portal].roomnum2 = tmp;
}

void bgInitPortal(s32 portalnum)
{
	struct coord room1centre;
	struct coord room2centre;
	f32 tmp;
	struct portalmetric sp28;
	struct portalmetric *ptr;
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

	ptr = &g_PortalMetrics[portalnum];
	sp28.normal.x = ptr->normal.x;
	sp28.normal.y = ptr->normal.y;
	sp28.normal.z = ptr->normal.z;
	sp28.min = ptr->min;
	sp28.max = ptr->max;

	tmp1 = sp28.normal.f[0] * room1centre.f[0] + sp28.normal.f[1] * room1centre.f[1] + sp28.normal.f[2] * room1centre.f[2];

	if (tmp1);

	sp18 = 0;

	if (tmp1 > sp28.max) {
		sp18 = 1;

		bgPortalSwapRooms(portalnum);

		sp28.normal.x = -sp28.normal.x;
		sp28.normal.y = -sp28.normal.y;
		sp28.normal.z = -sp28.normal.z;

		tmp = sp28.min;
		sp28.min = -sp28.max;
		sp28.max = -tmp;
	}

	tmp2 = sp28.normal.f[0] * room2centre.f[0] + sp28.normal.f[1] * room2centre.f[1] + sp28.normal.f[2] * room2centre.f[2];

	if (tmp2 <= sp28.min && sp18) {
		bgPortalSwapRooms(portalnum);
	}

	if (sp18);
}

/**
 * Figure out if the room has complicated portals and set a flag on the room if so.
 *
 * Most rooms use a simple portal setup where the portals (doors) exist along the
 * bounding box of the room. The game engine can easily test if a position is
 * inside the room by checking which side of the portal's plane it's on.
 *
 * A complicated portal setup happens when you have an L-shaped room and there's
 * a portal (door) on the inside wall of the L. It means you can be inside the
 * room but your position is on the opposite side of the door's plane.
 */
void bgInitRoom(s32 roomnum)
{
	struct portalvertices *pvertices;
	s32 i;
	s32 j;
	s32 k;
	struct portalmetric metric;
	s16 portalnum;
	s16 portalnum2;
	f32 tmp;

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		portalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];

		metric.normal.f[0] = (g_PortalMetrics + portalnum)->normal.f[0];
		metric.normal.f[1] = (g_PortalMetrics + portalnum)->normal.f[1];
		metric.normal.f[2] = (g_PortalMetrics + portalnum)->normal.f[2];
		metric.min = (g_PortalMetrics + portalnum)->min;
		metric.max = (g_PortalMetrics + portalnum)->max;

		if (roomnum == g_BgPortals[portalnum].roomnum1) {
			metric.normal.f[0] = -metric.normal.f[0];
			metric.normal.f[1] = -metric.normal.f[1];
			metric.normal.f[2] = -metric.normal.f[2];

			tmp = metric.min;
			metric.min = -metric.max;
			metric.max = -tmp;
		}

		for (j = 0; j < g_Rooms[roomnum].numportals; j++) {
			portalnum2 = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + j];

			if (portalnum2 == portalnum) {
				continue;
			}

			pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum2].verticesoffset);

			for (k = 0; k < pvertices->count; k++) {
				tmp = metric.normal.f[0] * pvertices->vertices[k].f[0]
					+ metric.normal.f[1] * pvertices->vertices[k].f[1]
					+ metric.normal.f[2] * pvertices->vertices[k].f[2];

				if (tmp < metric.min) {
					g_Rooms[roomnum].flags |= ROOMFLAG_COMPLICATEDPORTALS;
					return;
				}
			}
		}
	}
}

void bgSetPortalOpenState(s32 portal, bool open)
{
	g_BgPortals[portal].flags = (g_BgPortals[portal].flags | PORTALFLAG_CLOSED) ^ (open != false);
}

Gfx *bgRenderPortals(Gfx *gdl, s32 arg1, s32 arg2)
{
	return gdl;
}

void bg0f164e80(s32 arg0, s32 arg1)
{
	// empty
}

f32 var8007fcb4 = 0;

s32 bgFindPortalBetweenPositions(struct coord *pos1, struct coord *pos2)
{
	s32 bestportalnum = -1;
	s32 count = 0;
	f32 bestthing = MAXFLOAT;
	f32 thisthing;
	s32 i;

	for (i = 0; g_BgPortals[i].verticesoffset; i++) {
		if (portalCalculateIntersection(i, pos1, pos2) != PORTALINTERSECTION_NONE) {
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

void bgCalculatePortalBbox(s32 portalnum, struct coord *bbmin, struct coord *bbmax)
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

	pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);

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

				bgCalculatePortalBbox(portalnum, &portalbbmin, &portalbbmax);

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
