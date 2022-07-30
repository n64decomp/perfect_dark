#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_006900.h"
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
s16 var800a4bf8[100];
u32 *g_BgPrimaryData2;
struct bgroom *g_BgRooms;
struct bgportal *g_BgPortals;
struct var800a4ccc *var800a4ccc;
u8 *var800a4cd0;
struct bgcmd *g_BgCommands;
u8 *g_BgLightsFileData;
f32 *g_BgTable5;
s16 *g_RoomPortals;
s16 var800a4ce4;
s16 var800a4ce6;
struct var800a4ce8 *var800a4ce8;
struct portalthing *g_PortalThings;
struct var800a4cf0 var800a4cf0;

s32 g_StageIndex = 1;
u32 var8007fc04 = 0x00000000;
u8 *var8007fc08 = NULL;

#if VERSION < VERSION_NTSC_1_0
u32 var80082474nb = 0;
#endif

s16 var8007fc0c = 0;
s16 var8007fc10 = 0;
s32 var8007fc14 = 0;
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
	s32 end;
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

		end = (xraydata->numtris - 1) / 4 + 1;

		for (i = xraydata->numtris; i < xraydata->numtris * 4; i++) {
			xraydata->tris[i][0] = xraydata->tris[i][1] = xraydata->tris[i][2] = 0;
		}

		for (i = 0; i < end; i++) {
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

GLOBAL_ASM(
glabel bgChooseXrayVtxColour
.late_rodata
glabel var7f1b75b4
.word 0x3fc90fdb
glabel var7f1b75b8
.word 0x3f266666
glabel var7f1b75bc
.word 0x3eb33333
glabel var7f1b75c0
.word 0x3fc90fdb
.text
/*  f158884:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f158888:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f15888c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f158890:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f158894:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f158898:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f15889c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1588a0:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f1588a4:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f1588a8:	44984000 */ 	mtc1	$t8,$f8
/*  f1588ac:	448f2000 */ 	mtc1	$t7,$f4
/*  f1588b0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1588b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1588b8:	460a3481 */ 	sub.s	$f18,$f6,$f10
/*  f1588bc:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f1588c0:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f1588c4:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f1588c8:	c4e80010 */ 	lwc1	$f8,0x10($a3)
/*  f1588cc:	4608203c */ 	c.lt.s	$f4,$f8
/*  f1588d0:	00000000 */ 	nop
/*  f1588d4:	45020128 */ 	bc1fl	.L0f158d78
/*  f1588d8:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f1588dc:	84b90004 */ 	lh	$t9,0x4($a1)
/*  f1588e0:	8ce80008 */ 	lw	$t0,0x8($a3)
/*  f1588e4:	44993000 */ 	mtc1	$t9,$f6
/*  f1588e8:	44889000 */ 	mtc1	$t0,$f18
/*  f1588ec:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1588f0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f1588f4:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f1588f8:	46063482 */ 	mul.s	$f18,$f6,$f6
/*  f1588fc:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f158900:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f158904:	c4ea0010 */ 	lwc1	$f10,0x10($a3)
/*  f158908:	460a903c */ 	c.lt.s	$f18,$f10
/*  f15890c:	00000000 */ 	nop
/*  f158910:	45020119 */ 	bc1fl	.L0f158d78
/*  f158914:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f158918:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f15891c:	8cea0004 */ 	lw	$t2,0x4($a3)
/*  f158920:	44894000 */ 	mtc1	$t1,$f8
/*  f158924:	448a5000 */ 	mtc1	$t2,$f10
/*  f158928:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f15892c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f158930:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f158934:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f158938:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f15893c:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f158940:	c4e80010 */ 	lwc1	$f8,0x10($a3)
/*  f158944:	4608303c */ 	c.lt.s	$f6,$f8
/*  f158948:	00000000 */ 	nop
/*  f15894c:	4502010a */ 	bc1fl	.L0f158d78
/*  f158950:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f158954:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f158958:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f15895c:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f158960:	0c012974 */ 	jal	sqrtf
/*  f158964:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f158968:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f15896c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158970:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f158974:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f158978:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15897c:	00000000 */ 	nop
/*  f158980:	450000fc */ 	bc1f	.L0f158d74
/*  f158984:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f158988:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*  f15898c:	c4e4000c */ 	lwc1	$f4,0xc($a3)
/*  f158990:	c4e20014 */ 	lwc1	$f2,0x14($a3)
/*  f158994:	3c013f80 */ 	lui	$at,0x3f80
/*  f158998:	46040303 */ 	div.s	$f12,$f0,$f4
/*  f15899c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1589a0:	00000000 */ 	nop
/*  f1589a4:	45020009 */ 	bc1fl	.L0f1589cc
/*  f1589a8:	44817000 */ 	mtc1	$at,$f14
/*  f1589ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f1589b0:	44817000 */ 	mtc1	$at,$f14
/*  f1589b4:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f1589b8:	46027481 */ 	sub.s	$f18,$f14,$f2
/*  f1589bc:	46123283 */ 	div.s	$f10,$f6,$f18
/*  f1589c0:	10000004 */ 	b	.L0f1589d4
/*  f1589c4:	460a7401 */ 	sub.s	$f16,$f14,$f10
/*  f1589c8:	44817000 */ 	mtc1	$at,$f14
.L0f1589cc:
/*  f1589cc:	00000000 */ 	nop
/*  f1589d0:	46007406 */ 	mov.s	$f16,$f14
.L0f1589d4:
/*  f1589d4:	c4e2001c */ 	lwc1	$f2,0x1c($a3)
/*  f1589d8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f1589dc:	00000000 */ 	nop
/*  f1589e0:	45020083 */ 	bc1fl	.L0f158bf0
/*  f1589e4:	46026201 */ 	sub.s	$f8,$f12,$f2
/*  f1589e8:	46026003 */ 	div.s	$f0,$f12,$f2
/*  f1589ec:	3c017f1b */ 	lui	$at,%hi(var7f1b75b4)
/*  f1589f0:	c42475b4 */ 	lwc1	$f4,%lo(var7f1b75b4)($at)
/*  f1589f4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1589f8:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f1589fc:	46007201 */ 	sub.s	$f8,$f14,$f0
/*  f158a00:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f158a04:	0c0068f7 */ 	jal	sinf
/*  f158a08:	00000000 */ 	nop
/*  f158a0c:	3c01437f */ 	lui	$at,0x437f
/*  f158a10:	44811000 */ 	mtc1	$at,$f2
/*  f158a14:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f158a18:	3c013f80 */ 	lui	$at,0x3f80
/*  f158a1c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f158a20:	44817000 */ 	mtc1	$at,$f14
/*  f158a24:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158a28:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f158a2c:	3c014f00 */ 	lui	$at,0x4f00
/*  f158a30:	444df800 */ 	cfc1	$t5,$31
/*  f158a34:	44cef800 */ 	ctc1	$t6,$31
/*  f158a38:	00000000 */ 	nop
/*  f158a3c:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f158a40:	444ef800 */ 	cfc1	$t6,$31
/*  f158a44:	00000000 */ 	nop
/*  f158a48:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f158a4c:	51c00013 */ 	beqzl	$t6,.L0f158a9c
/*  f158a50:	440e9000 */ 	mfc1	$t6,$f18
/*  f158a54:	44819000 */ 	mtc1	$at,$f18
/*  f158a58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f158a5c:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f158a60:	44cef800 */ 	ctc1	$t6,$31
/*  f158a64:	00000000 */ 	nop
/*  f158a68:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f158a6c:	444ef800 */ 	cfc1	$t6,$31
/*  f158a70:	00000000 */ 	nop
/*  f158a74:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f158a78:	15c00005 */ 	bnez	$t6,.L0f158a90
/*  f158a7c:	00000000 */ 	nop
/*  f158a80:	440e9000 */ 	mfc1	$t6,$f18
/*  f158a84:	3c018000 */ 	lui	$at,0x8000
/*  f158a88:	10000007 */ 	b	.L0f158aa8
/*  f158a8c:	01c17025 */ 	or	$t6,$t6,$at
.L0f158a90:
/*  f158a90:	10000005 */ 	b	.L0f158aa8
/*  f158a94:	240effff */ 	addiu	$t6,$zero,-1
/*  f158a98:	440e9000 */ 	mfc1	$t6,$f18
.L0f158a9c:
/*  f158a9c:	00000000 */ 	nop
/*  f158aa0:	05c0fffb */ 	bltz	$t6,.L0f158a90
/*  f158aa4:	00000000 */ 	nop
.L0f158aa8:
/*  f158aa8:	44cdf800 */ 	ctc1	$t5,$31
/*  f158aac:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158ab0:	904f0251 */ 	lbu	$t7,0x251($v0)
/*  f158ab4:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f158ab8:	3c014f00 */ 	lui	$at,0x4f00
/*  f158abc:	01eec004 */ 	sllv	$t8,$t6,$t7
/*  f158ac0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f158ac4:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f158ac8:	4459f800 */ 	cfc1	$t9,$31
/*  f158acc:	44c8f800 */ 	ctc1	$t0,$31
/*  f158ad0:	00000000 */ 	nop
/*  f158ad4:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f158ad8:	4448f800 */ 	cfc1	$t0,$31
/*  f158adc:	00000000 */ 	nop
/*  f158ae0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158ae4:	51000013 */ 	beqzl	$t0,.L0f158b34
/*  f158ae8:	44082000 */ 	mfc1	$t0,$f4
/*  f158aec:	44812000 */ 	mtc1	$at,$f4
/*  f158af0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158af4:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f158af8:	44c8f800 */ 	ctc1	$t0,$31
/*  f158afc:	00000000 */ 	nop
/*  f158b00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f158b04:	4448f800 */ 	cfc1	$t0,$31
/*  f158b08:	00000000 */ 	nop
/*  f158b0c:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158b10:	15000005 */ 	bnez	$t0,.L0f158b28
/*  f158b14:	00000000 */ 	nop
/*  f158b18:	44082000 */ 	mfc1	$t0,$f4
/*  f158b1c:	3c018000 */ 	lui	$at,0x8000
/*  f158b20:	10000007 */ 	b	.L0f158b40
/*  f158b24:	01014025 */ 	or	$t0,$t0,$at
.L0f158b28:
/*  f158b28:	10000005 */ 	b	.L0f158b40
/*  f158b2c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f158b30:	44082000 */ 	mfc1	$t0,$f4
.L0f158b34:
/*  f158b34:	00000000 */ 	nop
/*  f158b38:	0500fffb */ 	bltz	$t0,.L0f158b28
/*  f158b3c:	00000000 */ 	nop
.L0f158b40:
/*  f158b40:	3c014300 */ 	lui	$at,0x4300
/*  f158b44:	44d9f800 */ 	ctc1	$t9,$31
/*  f158b48:	44813000 */ 	mtc1	$at,$f6
/*  f158b4c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f158b50:	90490252 */ 	lbu	$t1,0x252($v0)
/*  f158b54:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f158b58:	3c014f00 */ 	lui	$at,0x4f00
/*  f158b5c:	01285004 */ 	sllv	$t2,$t0,$t1
/*  f158b60:	030a5825 */ 	or	$t3,$t8,$t2
/*  f158b64:	444cf800 */ 	cfc1	$t4,$31
/*  f158b68:	44cdf800 */ 	ctc1	$t5,$31
/*  f158b6c:	00000000 */ 	nop
/*  f158b70:	460092a4 */ 	cvt.w.s	$f10,$f18
/*  f158b74:	444df800 */ 	cfc1	$t5,$31
/*  f158b78:	00000000 */ 	nop
/*  f158b7c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f158b80:	51a00013 */ 	beqzl	$t5,.L0f158bd0
/*  f158b84:	440d5000 */ 	mfc1	$t5,$f10
/*  f158b88:	44815000 */ 	mtc1	$at,$f10
/*  f158b8c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f158b90:	460a9281 */ 	sub.s	$f10,$f18,$f10
/*  f158b94:	44cdf800 */ 	ctc1	$t5,$31
/*  f158b98:	00000000 */ 	nop
/*  f158b9c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f158ba0:	444df800 */ 	cfc1	$t5,$31
/*  f158ba4:	00000000 */ 	nop
/*  f158ba8:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f158bac:	15a00005 */ 	bnez	$t5,.L0f158bc4
/*  f158bb0:	00000000 */ 	nop
/*  f158bb4:	440d5000 */ 	mfc1	$t5,$f10
/*  f158bb8:	3c018000 */ 	lui	$at,0x8000
/*  f158bbc:	10000007 */ 	b	.L0f158bdc
/*  f158bc0:	01a16825 */ 	or	$t5,$t5,$at
.L0f158bc4:
/*  f158bc4:	10000005 */ 	b	.L0f158bdc
/*  f158bc8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f158bcc:	440d5000 */ 	mfc1	$t5,$f10
.L0f158bd0:
/*  f158bd0:	00000000 */ 	nop
/*  f158bd4:	05a0fffb */ 	bltz	$t5,.L0f158bc4
/*  f158bd8:	00000000 */ 	nop
.L0f158bdc:
/*  f158bdc:	44ccf800 */ 	ctc1	$t4,$31
/*  f158be0:	016d7025 */ 	or	$t6,$t3,$t5
/*  f158be4:	10000063 */ 	b	.L0f158d74
/*  f158be8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f158bec:	46026201 */ 	sub.s	$f8,$f12,$f2
.L0f158bf0:
/*  f158bf0:	3c017f1b */ 	lui	$at,%hi(var7f1b75b8)
/*  f158bf4:	c42675b8 */ 	lwc1	$f6,%lo(var7f1b75b8)($at)
/*  f158bf8:	46027101 */ 	sub.s	$f4,$f14,$f2
/*  f158bfc:	3c017f1b */ 	lui	$at,%hi(var7f1b75bc)
/*  f158c00:	c42a75bc */ 	lwc1	$f10,%lo(var7f1b75bc)($at)
/*  f158c04:	3c017f1b */ 	lui	$at,%hi(var7f1b75c0)
/*  f158c08:	46044003 */ 	div.s	$f0,$f8,$f4
/*  f158c0c:	c42875c0 */ 	lwc1	$f8,%lo(var7f1b75c0)($at)
/*  f158c10:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f158c14:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f158c18:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f158c1c:	460a9000 */ 	add.s	$f0,$f18,$f10
/*  f158c20:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f158c24:	0c0068f7 */ 	jal	sinf
/*  f158c28:	00000000 */ 	nop
/*  f158c2c:	3c01437f */ 	lui	$at,0x437f
/*  f158c30:	44811000 */ 	mtc1	$at,$f2
/*  f158c34:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158c38:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158c3c:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f158c40:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f158c44:	3c014f00 */ 	lui	$at,0x4f00
/*  f158c48:	4459f800 */ 	cfc1	$t9,$31
/*  f158c4c:	44c8f800 */ 	ctc1	$t0,$31
/*  f158c50:	00000000 */ 	nop
/*  f158c54:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f158c58:	4448f800 */ 	cfc1	$t0,$31
/*  f158c5c:	00000000 */ 	nop
/*  f158c60:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158c64:	51000013 */ 	beqzl	$t0,.L0f158cb4
/*  f158c68:	44083000 */ 	mfc1	$t0,$f6
/*  f158c6c:	44813000 */ 	mtc1	$at,$f6
/*  f158c70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158c74:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f158c78:	44c8f800 */ 	ctc1	$t0,$31
/*  f158c7c:	00000000 */ 	nop
/*  f158c80:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f158c84:	4448f800 */ 	cfc1	$t0,$31
/*  f158c88:	00000000 */ 	nop
/*  f158c8c:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158c90:	15000005 */ 	bnez	$t0,.L0f158ca8
/*  f158c94:	00000000 */ 	nop
/*  f158c98:	44083000 */ 	mfc1	$t0,$f6
/*  f158c9c:	3c018000 */ 	lui	$at,0x8000
/*  f158ca0:	10000007 */ 	b	.L0f158cc0
/*  f158ca4:	01014025 */ 	or	$t0,$t0,$at
.L0f158ca8:
/*  f158ca8:	10000005 */ 	b	.L0f158cc0
/*  f158cac:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f158cb0:	44083000 */ 	mfc1	$t0,$f6
.L0f158cb4:
/*  f158cb4:	00000000 */ 	nop
/*  f158cb8:	0500fffb */ 	bltz	$t0,.L0f158ca8
/*  f158cbc:	00000000 */ 	nop
.L0f158cc0:
/*  f158cc0:	3c014300 */ 	lui	$at,0x4300
/*  f158cc4:	44d9f800 */ 	ctc1	$t9,$31
/*  f158cc8:	44819000 */ 	mtc1	$at,$f18
/*  f158ccc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f158cd0:	90490253 */ 	lbu	$t1,0x253($v0)
/*  f158cd4:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f158cd8:	904a0252 */ 	lbu	$t2,0x252($v0)
/*  f158cdc:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f158ce0:	0128c004 */ 	sllv	$t8,$t0,$t1
/*  f158ce4:	014c5804 */ 	sllv	$t3,$t4,$t2
/*  f158ce8:	030b6825 */ 	or	$t5,$t8,$t3
/*  f158cec:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f158cf0:	444ef800 */ 	cfc1	$t6,$31
/*  f158cf4:	44cff800 */ 	ctc1	$t7,$31
/*  f158cf8:	3c014f00 */ 	lui	$at,0x4f00
/*  f158cfc:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f158d00:	444ff800 */ 	cfc1	$t7,$31
/*  f158d04:	00000000 */ 	nop
/*  f158d08:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f158d0c:	51e00013 */ 	beqzl	$t7,.L0f158d5c
/*  f158d10:	440f4000 */ 	mfc1	$t7,$f8
/*  f158d14:	44814000 */ 	mtc1	$at,$f8
/*  f158d18:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f158d1c:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f158d20:	44cff800 */ 	ctc1	$t7,$31
/*  f158d24:	00000000 */ 	nop
/*  f158d28:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f158d2c:	444ff800 */ 	cfc1	$t7,$31
/*  f158d30:	00000000 */ 	nop
/*  f158d34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f158d38:	15e00005 */ 	bnez	$t7,.L0f158d50
/*  f158d3c:	00000000 */ 	nop
/*  f158d40:	440f4000 */ 	mfc1	$t7,$f8
/*  f158d44:	3c018000 */ 	lui	$at,0x8000
/*  f158d48:	10000007 */ 	b	.L0f158d68
/*  f158d4c:	01e17825 */ 	or	$t7,$t7,$at
.L0f158d50:
/*  f158d50:	10000005 */ 	b	.L0f158d68
/*  f158d54:	240fffff */ 	addiu	$t7,$zero,-1
/*  f158d58:	440f4000 */ 	mfc1	$t7,$f8
.L0f158d5c:
/*  f158d5c:	00000000 */ 	nop
/*  f158d60:	05e0fffb */ 	bltz	$t7,.L0f158d50
/*  f158d64:	00000000 */ 	nop
.L0f158d68:
/*  f158d68:	44cef800 */ 	ctc1	$t6,$31
/*  f158d6c:	01afc825 */ 	or	$t9,$t5,$t7
/*  f158d70:	ad190000 */ 	sw	$t9,0x0($t0)
.L0f158d74:
/*  f158d74:	8fa90038 */ 	lw	$t1,0x38($sp)
.L0f158d78:
/*  f158d78:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f158d7c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f158d80:	15800002 */ 	bnez	$t4,.L0f158d8c
/*  f158d84:	340aff00 */ 	dli	$t2,0xff00
/*  f158d88:	af0a0000 */ 	sw	$t2,0x0($t8)
.L0f158d8c:
/*  f158d8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f158d90:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f158d94:	03e00008 */ 	jr	$ra
/*  f158d98:	00000000 */ 	nop
);

// Mismatch: Reordered statements in the last else block. Goal saves player and
// alphafrac to the stack after the division. The code below does it before.
//void bgChooseXrayVtxColour(bool *inrange, s16 vertex[3], u32 *colour, struct xraydata *xraydata)
//{
//	f32 sp2c[3];
//	f32 f12;
//	f32 alphafrac; // 24
//	f32 f0;
//	struct player *player = g_Vars.currentplayer; // 1c
//	f32 tmp;
//
//	*inrange = false;
//
//	sp2c[0] = (f32) vertex[0] - (f32) xraydata->unk000;
//	sp2c[0] = sp2c[0] * sp2c[0];
//
//	if (sp2c[0] < xraydata->unk010) {
//		sp2c[2] = (f32) vertex[2] - (f32) xraydata->unk008;
//		sp2c[2] = sp2c[2] * sp2c[2];
//
//		if (sp2c[2] < xraydata->unk010) {
//			sp2c[1] = (f32) vertex[1] - (f32) xraydata->unk004;
//			sp2c[1] = sp2c[1] * sp2c[1];
//
//			if (sp2c[1] < xraydata->unk010) {
//				f0 = sqrtf(sp2c[0] + sp2c[1] + sp2c[2]);
//
//				if (f0 < xraydata->unk00c) {
//					*inrange = true;
//
//					f12 = f0 / xraydata->unk00c;
//
//					if (xraydata->unk014 < f12) {
//						alphafrac = 1.0f - (f12 - xraydata->unk014) / (1.0f - xraydata->unk014);
//					} else {
//						alphafrac = 1.0f;
//					}
//
//					// 9e0
//					if (f12 < xraydata->unk01c) {
//						f32 f0 = f12 / xraydata->unk01c;
//
//						f0 = sinf((1.0f - f0) * 1.5707964f);
//
//						*colour = (u32)(f0 * 255.0f) << player->ecol_1
//							| (u32)((1.0f - f0) * 255.0f) << player->ecol_2
//							| (u32)(alphafrac * 128.0f);
//					} else {
//						// bec
//						f32 f0;
//
//						f0 = (f12 - xraydata->unk01c) / (1.0f - xraydata->unk01c);
//						f0 = 0.65f * f0 + 0.35f;
//
//						tmp = sinf(f0 * 1.5707964f);
//
//						*colour = (u32)(tmp * 255.0f) << player->ecol_3
//							| 0xff << player->ecol_2
//							| (u32)(alphafrac * 128.0f);
//					}
//				}
//			}
//		}
//	}
//
//	if (*inrange == false) {
//		*colour = 0x0000ff00;
//	}
//}

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

// Mismatch: Regalloc and some reordered instructions
//Gfx *bg0f1598b4(Gfx *gdl, Gfx *gdl2, struct gfxvtx *vertices, s16 arg3[3])
//{
//	s32 i;
//	s32 stack;
//	struct xraydata xraydata;
//	struct stagetableentry *stage = stageGetCurrent();
//	s16 sp120[16][3];
//	s32 colours[16];
//	bool inrange[16];
//
//	xraydata.unk00c = g_Vars.currentplayer->eraserbgdist;
//	xraydata.unk010 = xraydata.unk00c * xraydata.unk00c;
//	xraydata.unk018 = xraydata.unk00c * 0.25f;
//	xraydata.unk01c = g_Vars.currentplayer->eraserpropdist / xraydata.unk00c;
//
//	if (xraydata.unk01c > 0.7f) {
//		xraydata.unk01c = 0.7f;
//	}
//
//	xraydata.unk014 = 0.250f;
//	xraydata.unk020 = stage->unk2c;
//	xraydata.unk024 = xraydata.unk020 * xraydata.unk020;
//	xraydata.unk000 = arg3[0];
//	xraydata.unk004 = arg3[1];
//	xraydata.unk008 = arg3[2];
//	xraydata.numtris = 0;
//	xraydata.numvertices = 0;
//
//	while (true) {
//		if (gdl2->dma.cmd == G_ENDDL) {
//			break;
//		}
//
//		if (gdl2->dma.cmd == G_MTX) {
//			// empty
//		} else if (gdl2->dma.cmd == G_VTX) {
//			s32 index = gdl2->bytes[1] & 0xf;
//			s32 numvertices = (((u32)gdl2->bytes[1] >> 4)) + 1;
//			s32 offset = (gdl2->words.w1 & 0xffffff);
//			struct gfxvtx *vtx = (struct gfxvtx *)((u32)vertices + offset);
//			u32 stack[4];
//
//			for (i = 0; i < numvertices; i++) {
//				sp120[index + i][0] = vtx->x;
//				sp120[index + i][1] = vtx->y;
//				sp120[index + i][2] = vtx->z;
//
//				bgChooseXrayVtxColour(&inrange[i], sp120[index + i], &colours[index + i], &xraydata);
//
//				vtx++;
//			}
//		} else if (gdl2->dma.cmd == G_TRI1) {
//			s16 x = gdl2->tri.tri.v[0] / 10;
//			s16 y = gdl2->tri.tri.v[1] / 10;
//			s16 z = gdl2->tri.tri.v[2] / 10;
//
//			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
//		} else if (gdl2->dma.cmd == G_TRI4) {
//			s16 x;
//			s16 y;
//			s16 z;
//
//			x = gdl2->tri4.x1;
//			y = gdl2->tri4.y1;
//			z = gdl2->tri4.z1;
//
//			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
//
//			x = gdl2->tri4.x2;
//			y = gdl2->tri4.y2;
//			z = gdl2->tri4.z2;
//
//			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
//
//			x = gdl2->tri4.x3;
//			y = gdl2->tri4.y3;
//			z = gdl2->tri4.z3;
//
//			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
//
//			x = gdl2->tri4.x4;
//			y = gdl2->tri4.y4;
//			z = gdl2->tri4.z4;
//
//			gdl = func0f158d9c(gdl, &xraydata, sp120[x], sp120[y], sp120[z], colours[x], colours[y], colours[z], inrange[x], inrange[y], inrange[z]);
//		}
//
//		gdl2++;
//	}
//
//	gdl = bg0f158184(gdl, &xraydata);
//
//	return gdl;
//}

Gfx *bgRenderRoomXrayPass(Gfx *gdl, s32 roomnum, struct roomgfxdata18 *arg2, bool recurse, s16 arg4[3])
{
	struct player *player = g_Vars.currentplayer;

	if (arg2 == NULL) {
		return gdl;
	}

	switch (arg2->type) {
	case 0:
		gdl = bg0f1598b4(gdl, arg2->gdl, arg2->vertices, arg4);

		if (recurse) {
			gdl = bgRenderRoomXrayPass(gdl, roomnum, arg2->next, true, arg4);
		}
		break;
	case 1:
		if (arg2->child != NULL) {
			struct roomgfxdata18 *child1 = arg2->child;
			struct roomgfxdata18 *child2 = child1->next;
			struct coord *coords = arg2->unk0c;
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
				gdl = bgRenderRoomXrayPass(gdl, roomnum, arg2->next, true, arg4);
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
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->unk08, true, sp40);
	gdl = bgRenderRoomXrayPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->unk0c, true, sp40);

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

	var8007fc14 = 0;

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
			func0f13c780(thing->roomnum);

			if (var8007fc14 < 100) {
				var800a4bf8[var8007fc14++] = thing->roomnum;
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
/*  f155700:	0fc4dca0 */ 	jal	func0f13c780
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

Gfx *func0f15b114(Gfx *gdl)
{
	s32 i;

	if (g_Vars.mplayerisrunning == false && var8007fc14 > 0) {
		gdl = func0f13d40c(gdl);

		for (i = 0; i < var8007fc14; i++) {
			gdl = func0f13d568(gdl, var800a4bf8[i]);
		}

		gdl = func0f13d54c(gdl);
	}

	return sky0f12715c(gdl);
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
	scratch = ((u32)g_BgPrimaryData + inflatedsize) - primcompsize;
	scratch = ALIGN16(scratch + 0x8000);

	g_LoadType = LOADTYPE_BG;

	// Copy section 1 header + compressed primary to scratch space
	bgLoadFile((u8 *)scratch, 0, ALIGN16(primcompsize + 15));

	// Inflate primary data to the start of the buffer
	scratch += 0xc;
	bgInflate((u8 *)scratch, g_BgPrimaryData, primcompsize);

	// Shrink the allocation (ie. free the scratch space)
	mempRealloc(g_BgPrimaryData, inflatedsize, MEMPOOL_STAGE);

	// Load the section 2 header
	section2start = section1compsize + 0xc;

	bgLoadFile(header, section2start, 0x40);

	inflatedsize = (*(u16 *)&header[0] & 0x7fff) - 1;
	section2compsize = *(u16 *)&header[2];
	inflatedsize = (inflatedsize | 0xf) + 1;

	// Allocate space for the section 2 data (texture ID list).
	// This is the cause and fix for the Challenge 7 memory corruption bug in
	// NTSC 1.0. A full writeup about the bug and how the fix works can be found
	// in the docs folder of this project.
#if VERSION >= VERSION_NTSC_FINAL
	section2 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
	scratch = (u32)section2 + 0x8000;
#else
	section2 = mempAlloc(inflatedsize + 0x800, MEMPOOL_STAGE);
	scratch = (u32)section2 + 0x800;
#endif

	// Load compressed data from ROM to scratch
	bgLoadFile((u8 *)scratch, section2start + 4, ((section2compsize - 1) | 0xf) + 1);

	// Inflate section 2 to the start of the buffer
	bgInflate((u8 *)scratch, (u8 *)section2, section2compsize);

	// Iterate texture IDs and ensure they're loaded
	inflatedsize = (*(u16 *)&header[0] & 0x7fff) >> 1;

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

		if (g_BgPrimaryData2[3] == 0) {
			g_BgCommands = NULL;
		} else {
			g_BgCommands = (struct bgcmd *)(g_BgPrimaryData2[3] + g_BgPrimaryData + 0xf1000000);
		}

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

#if VERSION >= VERSION_NTSC_FINAL
GLOBAL_ASM(
glabel bgBuildTables
.late_rodata
glabel var7f1b75cc
.word 0x7f7fffff
glabel var7f1b75d0
.word 0xff7fffff
.text
/*  f15b908:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f15b90c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f15b910:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15b914:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15b918:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f15b91c:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b920:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f15b924:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f15b928:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f15b92c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f15b930:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b934:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f15b938:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b93c:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f15b940:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15b944:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f15b948:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f15b94c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f15b950:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f15b954:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15b958:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15b95c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15b960:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15b964:	0c0048f2 */ 	jal	mempAlloc
/*  f15b968:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b96c:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b970:	3c15800a */ 	lui	$s5,%hi(g_Rooms)
/*  f15b974:	26b54928 */ 	addiu	$s5,$s5,%lo(g_Rooms)
/*  f15b978:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f15b97c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15b980:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15b984:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f15b988:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15b98c:	0c0048f2 */ 	jal	mempAlloc
/*  f15b990:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b994:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b998:	3c03800a */ 	lui	$v1,%hi(var800a4ce8)
/*  f15b99c:	24634ce8 */ 	addiu	$v1,$v1,%lo(var800a4ce8)
/*  f15b9a0:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b9a4:	1a200010 */ 	blez	$s1,.L0f15b9e8
/*  f15b9a8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15b9ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f15b9b0:	3416ffff */ 	dli	$s6,0xffff
/*  f15b9b4:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f15b9b8:
/*  f15b9b8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b9bc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f15b9c0:	a7360000 */ 	sh	$s6,0x0($t9)
/*  f15b9c4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15b9c8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f15b9cc:	a5e00002 */ 	sh	$zero,0x2($t7)
/*  f15b9d0:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b9d4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15b9d8:	0291082a */ 	slt	$at,$s4,$s1
/*  f15b9dc:	5420fff6 */ 	bnezl	$at,.L0f15b9b8
/*  f15b9e0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f15b9e4:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15b9e8:
/*  f15b9e8:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f15b9ec:	13000013 */ 	beqz	$t8,.L0f15ba3c
/*  f15b9f0:	2624000f */ 	addiu	$a0,$s1,0xf
/*  f15b9f4:	3499000f */ 	ori	$t9,$a0,0xf
/*  f15b9f8:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f15b9fc:	0c0048f2 */ 	jal	mempAlloc
/*  f15ba00:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15ba04:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15ba08:	3c03800a */ 	lui	$v1,%hi(g_MpRoomVisibility)
/*  f15ba0c:	2463492c */ 	addiu	$v1,$v1,%lo(g_MpRoomVisibility)
/*  f15ba10:	1a20000a */ 	blez	$s1,.L0f15ba3c
/*  f15ba14:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15ba18:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f15ba1c:
/*  f15ba1c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f15ba20:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f15ba24:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15ba28:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15ba2c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15ba30:	5420fffa */ 	bnezl	$at,.L0f15ba1c
/*  f15ba34:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15ba38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15ba3c:
/*  f15ba3c:	1a200020 */ 	blez	$s1,.L0f15bac0
/*  f15ba40:	00009025 */ 	or	$s2,$zero,$zero
/*  f15ba44:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15ba48:
/*  f15ba48:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15ba4c:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba50:	adc00044 */ 	sw	$zero,0x44($t6)
/*  f15ba54:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba58:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15ba5c:	a3000008 */ 	sb	$zero,0x8($t8)
/*  f15ba60:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15ba64:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba68:	a5c0000a */ 	sh	$zero,0xa($t6)
/*  f15ba6c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba70:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15ba74:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f15ba78:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15ba7c:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba80:	a1c0004d */ 	sb	$zero,0x4d($t6)
/*  f15ba84:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba88:	01f26021 */ 	addu	$t4,$t7,$s2
/*  f15ba8c:	9198004e */ 	lbu	$t8,0x4e($t4)
/*  f15ba90:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f15ba94:	a199004e */ 	sb	$t9,0x4e($t4)
/*  f15ba98:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15ba9c:	01d26021 */ 	addu	$t4,$t6,$s2
/*  f15baa0:	918f004e */ 	lbu	$t7,0x4e($t4)
/*  f15baa4:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15baa8:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f15baac:	a198004e */ 	sb	$t8,0x4e($t4)
/*  f15bab0:	8e7902bc */ 	lw	$t9,0x2bc($s3)
/*  f15bab4:	0299082a */ 	slt	$at,$s4,$t9
/*  f15bab8:	5420ffe3 */ 	bnezl	$at,.L0f15ba48
/*  f15babc:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15bac0:
/*  f15bac0:	3c118008 */ 	lui	$s1,%hi(g_StageIndex)
/*  f15bac4:	2631fc00 */ 	addiu	$s1,$s1,%lo(g_StageIndex)
/*  f15bac8:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f15bacc:	24120038 */ 	addiu	$s2,$zero,0x38
/*  f15bad0:	3c108008 */ 	lui	$s0,%hi(g_Stages)
/*  f15bad4:	01d20019 */ 	multu	$t6,$s2
/*  f15bad8:	2610fcc0 */ 	addiu	$s0,$s0,%lo(g_Stages)
/*  f15badc:	00007812 */ 	mflo	$t7
/*  f15bae0:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f15bae4:	0fc57220 */ 	jal	func0f15c880
/*  f15bae8:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f15baec:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f15baf0:	03320019 */ 	multu	$t9,$s2
/*  f15baf4:	00007012 */ 	mflo	$t6
/*  f15baf8:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f15bafc:	0fc0a124 */ 	jal	chr0f028490
/*  f15bb00:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f15bb04:	3c188008 */ 	lui	$t8,%hi(g_StageIndex)
/*  f15bb08:	8f18fc00 */ 	lw	$t8,%lo(g_StageIndex)($t8)
/*  f15bb0c:	3c018008 */ 	lui	$at,%hi(g_Stages+0x18)
/*  f15bb10:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f15bb14:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f15bb18:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f15bb1c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f15bb20:	00390821 */ 	addu	$at,$at,$t9
/*  f15bb24:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x200)
/*  f15bb28:	2463a1c0 */ 	addiu	$v1,$v1,%lo(g_Vars+0x200)
/*  f15bb2c:	c420fcd8 */ 	lwc1	$f0,%lo(g_Stages+0x18)($at)
/*  f15bb30:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f15bb34:
/*  f15bb34:	24420080 */ 	addiu	$v0,$v0,0x80
/*  f15bb38:	0043082b */ 	sltu	$at,$v0,$v1
/*  f15bb3c:	1420fffd */ 	bnez	$at,.L0f15bb34
/*  f15bb40:	e4400068 */ 	swc1	$f0,0x68($v0)
/*  f15bb44:	3c013f80 */ 	lui	$at,0x3f80
/*  f15bb48:	44816000 */ 	mtc1	$at,$f12
/*  f15bb4c:	0c0059d2 */ 	jal	mtx00016748
/*  f15bb50:	00000000 */ 	nop
/*  f15bb54:	3c0e800a */ 	lui	$t6,%hi(var800a4920)
/*  f15bb58:	8dce4920 */ 	lw	$t6,%lo(var800a4920)($t6)
/*  f15bb5c:	3c17800a */ 	lui	$s7,%hi(g_BgPortals)
/*  f15bb60:	26f74cc8 */ 	addiu	$s7,$s7,%lo(g_BgPortals)
/*  f15bb64:	15c00324 */ 	bnez	$t6,.L0f15c7f8
/*  f15bb68:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bb6c:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bb70:	0000f025 */ 	or	$s8,$zero,$zero
/*  f15bb74:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f15bb78:	11e00006 */ 	beqz	$t7,.L0f15bb94
/*  f15bb7c:	02001025 */ 	or	$v0,$s0,$zero
/*  f15bb80:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15bb84:
/*  f15bb84:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f15bb88:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f15bb8c:	5700fffd */ 	bnezl	$t8,.L0f15bb84
/*  f15bb90:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15bb94:
/*  f15bb94:	001ec900 */ 	sll	$t9,$s8,0x4
/*  f15bb98:	3c028008 */ 	lui	$v0,%hi(g_NumPortalThings)
/*  f15bb9c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15bba0:	2442fc40 */ 	addiu	$v0,$v0,%lo(g_NumPortalThings)
/*  f15bba4:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15bba8:	ac5e0000 */ 	sw	$s8,0x0($v0)
/*  f15bbac:	0c0048f2 */ 	jal	mempAlloc
/*  f15bbb0:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15bbb4:	3c01800a */ 	lui	$at,%hi(g_PortalThings)
/*  f15bbb8:	ac224cec */ 	sw	$v0,%lo(g_PortalThings)($at)
/*  f15bbbc:	001e20c0 */ 	sll	$a0,$s8,0x3
/*  f15bbc0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15bbc4:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bbc8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15bbcc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15bbd0:	2412000c */ 	addiu	$s2,$zero,0xc
.L0f15bbd4:
/*  f15bbd4:	1bc0000b */ 	blez	$s8,.L0f15bc04
/*  f15bbd8:	00001825 */ 	or	$v1,$zero,$zero
.L0f15bbdc:
/*  f15bbdc:	02031021 */ 	addu	$v0,$s0,$v1
/*  f15bbe0:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f15bbe4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bbe8:	16980003 */ 	bne	$s4,$t8,.L0f15bbf8
/*  f15bbec:	00000000 */ 	nop
/*  f15bbf0:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f15bbf4:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15bbf8:
/*  f15bbf8:	16defff8 */ 	bne	$s6,$s8,.L0f15bbdc
/*  f15bbfc:	24630008 */ 	addiu	$v1,$v1,8
/*  f15bc00:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bc04:
/*  f15bc04:	02048821 */ 	addu	$s1,$s0,$a0
/*  f15bc08:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bc0c:	18a00007 */ 	blez	$a1,.L0f15bc2c
/*  f15bc10:	00000000 */ 	nop
/*  f15bc14:	00b20019 */ 	multu	$a1,$s2
/*  f15bc18:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bc1c:	0000c812 */ 	mflo	$t9
/*  f15bc20:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15bc24:	1000ffeb */ 	b	.L0f15bbd4
/*  f15bc28:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f15bc2c:
/*  f15bc2c:	17c00003 */ 	bnez	$s8,.L0f15bc3c
/*  f15bc30:	00008025 */ 	or	$s0,$zero,$zero
/*  f15bc34:	10000002 */ 	b	.L0f15bc40
/*  f15bc38:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15bc3c:
/*  f15bc3c:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15bc40:
/*  f15bc40:	00022080 */ 	sll	$a0,$v0,0x2
/*  f15bc44:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15bc48:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15bc4c:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15bc50:	0c0048f2 */ 	jal	mempAlloc
/*  f15bc54:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bc58:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15bc5c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15bc60:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15bc64:	3c13800a */ 	lui	$s3,%hi(g_RoomPortals)
/*  f15bc68:	26734ce0 */ 	addiu	$s3,$s3,%lo(g_RoomPortals)
/*  f15bc6c:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f15bc70:	aca0002c */ 	sw	$zero,0x2c($a1)
/*  f15bc74:	1a200033 */ 	blez	$s1,.L0f15bd44
/*  f15bc78:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15bc7c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bc80:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f15bc84:
/*  f15bc84:	00002025 */ 	or	$a0,$zero,$zero
/*  f15bc88:	00001825 */ 	or	$v1,$zero,$zero
/*  f15bc8c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15bc90:	1bc0001d */ 	blez	$s8,.L0f15bd08
/*  f15bc94:	a730000e */ 	sh	$s0,0xe($t9)
.L0f15bc98:
/*  f15bc98:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15bc9c:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f15bca0:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f15bca4:	568f000a */ 	bnel	$s4,$t7,.L0f15bcd0
/*  f15bca8:	84580004 */ 	lh	$t8,0x4($v0)
/*  f15bcac:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15bcb0:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f15bcb4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15bcb8:	03197021 */ 	addu	$t6,$t8,$t9
/*  f15bcbc:	a5d60000 */ 	sh	$s6,0x0($t6)
/*  f15bcc0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15bcc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15bcc8:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f15bccc:	84580004 */ 	lh	$t8,0x4($v0)
.L0f15bcd0:
/*  f15bcd0:	00107040 */ 	sll	$t6,$s0,0x1
/*  f15bcd4:	56980007 */ 	bnel	$s4,$t8,.L0f15bcf4
/*  f15bcd8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bcdc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15bce0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15bce4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15bce8:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f15bcec:	a5f60000 */ 	sh	$s6,0x0($t7)
/*  f15bcf0:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f15bcf4:
/*  f15bcf4:	16deffe8 */ 	bne	$s6,$s8,.L0f15bc98
/*  f15bcf8:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15bcfc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15bd00:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15bd04:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bd08:
/*  f15bd08:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bd0c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15bd10:	a3240005 */ 	sb	$a0,0x5($t9)
/*  f15bd14:	8cae002c */ 	lw	$t6,0x2c($a1)
/*  f15bd18:	01c4082a */ 	slt	$at,$t6,$a0
/*  f15bd1c:	50200003 */ 	beqzl	$at,.L0f15bd2c
/*  f15bd20:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15bd24:	aca4002c */ 	sw	$a0,0x2c($a1)
/*  f15bd28:	8cb102bc */ 	lw	$s1,0x2bc($a1)
.L0f15bd2c:
/*  f15bd2c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bd30:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15bd34:	0291082a */ 	slt	$at,$s4,$s1
/*  f15bd38:	5420ffd2 */ 	bnezl	$at,.L0f15bc84
/*  f15bd3c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bd40:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bd44:
/*  f15bd44:	1a200058 */ 	blez	$s1,.L0f15bea8
/*  f15bd48:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bd4c:	8eac0000 */ 	lw	$t4,0x0($s5)
.L0f15bd50:
/*  f15bd50:	818b0005 */ 	lb	$t3,0x5($t4)
/*  f15bd54:	5960004f */ 	blezl	$t3,.L0f15be94
/*  f15bd58:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bd5c:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15bd60:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15bd64:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bd68:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f15bd6c:	01f96821 */ 	addu	$t5,$t7,$t9
/*  f15bd70:	01a0f825 */ 	or	$ra,$t5,$zero
/*  f15bd74:	00008825 */ 	or	$s1,$zero,$zero
.L0f15bd78:
/*  f15bd78:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15bd7c:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15bd80:	000a70c0 */ 	sll	$t6,$t2,0x3
/*  f15bd84:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f15bd88:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15bd8c:	16840003 */ 	bne	$s4,$a0,.L0f15bd9c
/*  f15bd90:	00803825 */ 	or	$a3,$a0,$zero
/*  f15bd94:	10000001 */ 	b	.L0f15bd9c
/*  f15bd98:	84670004 */ 	lh	$a3,0x4($v1)
.L0f15bd9c:
/*  f15bd9c:	10200034 */ 	beqz	$at,.L0f15be70
/*  f15bda0:	02c04025 */ 	or	$t0,$s6,$zero
/*  f15bda4:	00084840 */ 	sll	$t1,$t0,0x1
.L0f15bda8:
/*  f15bda8:	01a92821 */ 	addu	$a1,$t5,$t1
/*  f15bdac:	84a60000 */ 	lh	$a2,0x0($a1)
/*  f15bdb0:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15bdb4:	00002025 */ 	or	$a0,$zero,$zero
/*  f15bdb8:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f15bdbc:	02181021 */ 	addu	$v0,$s0,$t8
/*  f15bdc0:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15bdc4:	16830007 */ 	bne	$s4,$v1,.L0f15bde4
/*  f15bdc8:	0067082a */ 	slt	$at,$v1,$a3
/*  f15bdcc:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f15bdd0:	01e7082a */ 	slt	$at,$t7,$a3
/*  f15bdd4:	10200006 */ 	beqz	$at,.L0f15bdf0
/*  f15bdd8:	00000000 */ 	nop
/*  f15bddc:	10000004 */ 	b	.L0f15bdf0
/*  f15bde0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bde4:
/*  f15bde4:	10200002 */ 	beqz	$at,.L0f15bdf0
/*  f15bde8:	00000000 */ 	nop
/*  f15bdec:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bdf0:
/*  f15bdf0:	5080001d */ 	beqzl	$a0,.L0f15be68
/*  f15bdf4:	010b082a */ 	slt	$at,$t0,$t3
/*  f15bdf8:	a4aa0000 */ 	sh	$t2,0x0($a1)
/*  f15bdfc:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15be00:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15be04:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f15be08:	870f000e */ 	lh	$t7,0xe($t8)
/*  f15be0c:	000f7040 */ 	sll	$t6,$t7,0x1
/*  f15be10:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f15be14:	03117821 */ 	addu	$t7,$t8,$s1
/*  f15be18:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f15be1c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15be20:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15be24:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15be28:	03326021 */ 	addu	$t4,$t9,$s2
/*  f15be2c:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15be30:	00187840 */ 	sll	$t7,$t8,0x1
/*  f15be34:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f15be38:	01b1f821 */ 	addu	$ra,$t5,$s1
/*  f15be3c:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15be40:	000ac8c0 */ 	sll	$t9,$t2,0x3
/*  f15be44:	02191821 */ 	addu	$v1,$s0,$t9
/*  f15be48:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15be4c:	16840004 */ 	bne	$s4,$a0,.L0f15be60
/*  f15be50:	00803825 */ 	or	$a3,$a0,$zero
/*  f15be54:	84670004 */ 	lh	$a3,0x4($v1)
/*  f15be58:	10000002 */ 	b	.L0f15be64
/*  f15be5c:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15be60:
/*  f15be60:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15be64:
/*  f15be64:	010b082a */ 	slt	$at,$t0,$t3
.L0f15be68:
/*  f15be68:	1420ffcf */ 	bnez	$at,.L0f15bda8
/*  f15be6c:	25290002 */ 	addiu	$t1,$t1,0x2
.L0f15be70:
/*  f15be70:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15be74:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15be78:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f15be7c:	1420ffbe */ 	bnez	$at,.L0f15bd78
/*  f15be80:	27ff0002 */ 	addiu	$ra,$ra,0x2
/*  f15be84:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x2bc)
/*  f15be88:	8e31a27c */ 	lw	$s1,%lo(g_Vars+0x2bc)($s1)
/*  f15be8c:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15be90:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f15be94:
/*  f15be94:	0291082a */ 	slt	$at,$s4,$s1
/*  f15be98:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15be9c:	1420ffac */ 	bnez	$at,.L0f15bd50
/*  f15bea0:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15bea4:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bea8:
/*  f15bea8:	17c00003 */ 	bnez	$s8,.L0f15beb8
/*  f15beac:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15beb0:	10000002 */ 	b	.L0f15bebc
/*  f15beb4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15beb8:
/*  f15beb8:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15bebc:
/*  f15bebc:	2444000f */ 	addiu	$a0,$v0,0xf
/*  f15bec0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bec4:	0c0048f2 */ 	jal	mempAlloc
/*  f15bec8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15becc:	3c10800a */ 	lui	$s0,%hi(var800a4cd0)
/*  f15bed0:	26104cd0 */ 	addiu	$s0,$s0,%lo(var800a4cd0)
/*  f15bed4:	1bc00009 */ 	blez	$s8,.L0f15befc
/*  f15bed8:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f15bedc:
/*  f15bedc:	0fc56d30 */ 	jal	func0f15b4c0
/*  f15bee0:	02802025 */ 	or	$a0,$s4,$zero
/*  f15bee4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f15bee8:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f15beec:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bef0:	169efffa */ 	bne	$s4,$s8,.L0f15bedc
/*  f15bef4:	a3220000 */ 	sb	$v0,0x0($t9)
/*  f15bef8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15befc:
/*  f15befc:	001e2080 */ 	sll	$a0,$s8,0x2
/*  f15bf00:	009e2021 */ 	addu	$a0,$a0,$s8
/*  f15bf04:	00042080 */ 	sll	$a0,$a0,0x2
/*  f15bf08:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15bf0c:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bf10:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15bf14:	0c0048f2 */ 	jal	mempAlloc
/*  f15bf18:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bf1c:	3c01800a */ 	lui	$at,%hi(var800a4ccc)
/*  f15bf20:	1bc00095 */ 	blez	$s8,.L0f15c178
/*  f15bf24:	ac224ccc */ 	sw	$v0,%lo(var800a4ccc)($at)
/*  f15bf28:	44808000 */ 	mtc1	$zero,$f16
/*  f15bf2c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bf30:	00003025 */ 	or	$a2,$zero,$zero
/*  f15bf34:	2413000c */ 	addiu	$s3,$zero,0xc
.L0f15bf38:
/*  f15bf38:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bf3c:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f15bf40:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f15bf44:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f15bf48:	02127821 */ 	addu	$t7,$s0,$s2
/*  f15bf4c:	95f90000 */ 	lhu	$t9,0x0($t7)
/*  f15bf50:	03308821 */ 	addu	$s1,$t9,$s0
/*  f15bf54:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bf58:	02201825 */ 	or	$v1,$s1,$zero
/*  f15bf5c:	18a00035 */ 	blez	$a1,.L0f15c034
/*  f15bf60:	26c40001 */ 	addiu	$a0,$s6,0x1
.L0f15bf64:
/*  f15bf64:	0085001a */ 	div	$zero,$a0,$a1
/*  f15bf68:	0000c010 */ 	mfhi	$t8
/*  f15bf6c:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f15bf70:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15bf74:	03130019 */ 	multu	$t8,$s3
/*  f15bf78:	0080b025 */ 	or	$s6,$a0,$zero
/*  f15bf7c:	14a00002 */ 	bnez	$a1,.L0f15bf88
/*  f15bf80:	00000000 */ 	nop
/*  f15bf84:	0007000d */ 	break	0x7
.L0f15bf88:
/*  f15bf88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15bf8c:	14a10004 */ 	bne	$a1,$at,.L0f15bfa0
/*  f15bf90:	3c018000 */ 	lui	$at,0x8000
/*  f15bf94:	14810002 */ 	bne	$a0,$at,.L0f15bfa0
/*  f15bf98:	00000000 */ 	nop
/*  f15bf9c:	0006000d */ 	break	0x6
.L0f15bfa0:
/*  f15bfa0:	00007012 */ 	mflo	$t6
/*  f15bfa4:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f15bfa8:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f15bfac:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f15bfb0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15bfb4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15bfb8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15bfbc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f15bfc0:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15bfc4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f15bfc8:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f15bfcc:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f15bfd0:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f15bfd4:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f15bfd8:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f15bfdc:	c466fff8 */ 	lwc1	$f6,-0x8($v1)
/*  f15bfe0:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f15bfe4:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f15bfe8:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f15bfec:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f15bff0:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f15bff4:	e7b200fc */ 	swc1	$f18,0xfc($sp)
/*  f15bff8:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f15bffc:	c46afff8 */ 	lwc1	$f10,-0x8($v1)
/*  f15c000:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f15c004:	c464fffc */ 	lwc1	$f4,-0x4($v1)
/*  f15c008:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f15c00c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f15c010:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c014:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15c018:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15c01c:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15c020:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15c024:	0085082a */ 	slt	$at,$a0,$a1
/*  f15c028:	5420ffce */ 	bnezl	$at,.L0f15bf64
/*  f15c02c:	26c40001 */ 	addiu	$a0,$s6,0x1
/*  f15c030:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15c034:
/*  f15c034:	c7a000f8 */ 	lwc1	$f0,0xf8($sp)
/*  f15c038:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*  f15c03c:	c7ae0100 */ 	lwc1	$f14,0x100($sp)
/*  f15c040:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f15c044:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f15c048:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15c04c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c050:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f15c054:	0c012974 */ 	jal	sqrtf
/*  f15c058:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f15c05c:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f15c060:	46000087 */ 	neg.s	$f2,$f0
/*  f15c064:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15c068:	46029183 */ 	div.s	$f6,$f18,$f2
/*  f15c06c:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c070:	3c017f1b */ 	lui	$at,%hi(var7f1b75cc)
/*  f15c074:	44808000 */ 	mtc1	$zero,$f16
/*  f15c078:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f15c07c:	02201825 */ 	or	$v1,$s1,$zero
/*  f15c080:	3c18800a */ 	lui	$t8,%hi(var800a4ccc)
/*  f15c084:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f15c088:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f15c08c:	c42675cc */ 	lwc1	$f6,%lo(var7f1b75cc)($at)
/*  f15c090:	3c017f1b */ 	lui	$at,%hi(var7f1b75d0)
/*  f15c094:	c42a75d0 */ 	lwc1	$f10,%lo(var7f1b75d0)($at)
/*  f15c098:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f15c09c:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f15c0a0:	46022483 */ 	div.s	$f18,$f4,$f2
/*  f15c0a4:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f15c0a8:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15c0ac:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f15c0b0:	19e00020 */ 	blez	$t7,.L0f15c134
/*  f15c0b4:	00000000 */ 	nop
/*  f15c0b8:	c4680004 */ 	lwc1	$f8,0x4($v1)
.L0f15c0bc:
/*  f15c0bc:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f15c0c0:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f15c0c4:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15c0c8:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f15c0cc:	00000000 */ 	nop
/*  f15c0d0:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15c0d4:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15c0d8:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f15c0dc:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f15c0e0:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f15c0e4:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15c0e8:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f15c0ec:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15c0f0:	00000000 */ 	nop
/*  f15c0f4:	45000002 */ 	bc1f	.L0f15c100
/*  f15c0f8:	00000000 */ 	nop
/*  f15c0fc:	e7a00104 */ 	swc1	$f0,0x104($sp)
.L0f15c100:
/*  f15c100:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15c104:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15c108:	00000000 */ 	nop
/*  f15c10c:	45020003 */ 	bc1fl	.L0f15c11c
/*  f15c110:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f15c114:	e7a00108 */ 	swc1	$f0,0x108($sp)
/*  f15c118:	92390000 */ 	lbu	$t9,0x0($s1)
.L0f15c11c:
/*  f15c11c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15c120:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15c124:	02d9082a */ 	slt	$at,$s6,$t9
/*  f15c128:	5420ffe4 */ 	bnezl	$at,.L0f15c0bc
/*  f15c12c:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f15c130:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15c134:
/*  f15c134:	8f184ccc */ 	lw	$t8,%lo(var800a4ccc)($t8)
/*  f15c138:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15c13c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c140:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f15c144:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f15c148:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f15c14c:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f15c150:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c154:	e4520004 */ 	swc1	$f18,0x4($v0)
/*  f15c158:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c15c:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f15c160:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15c164:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f15c168:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15c16c:	169eff72 */ 	bne	$s4,$s8,.L0f15bf38
/*  f15c170:	e4460010 */ 	swc1	$f6,0x10($v0)
/*  f15c174:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c178:
/*  f15c178:	0fc2d96a */ 	jal	portal0f0b65a8
/*  f15c17c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f15c180:	3c1e800a */ 	lui	$s8,%hi(g_BgCommands)
/*  f15c184:	27de4cd4 */ 	addiu	$s8,$s8,%lo(g_BgCommands)
/*  f15c188:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f15c18c:	1060001c */ 	beqz	$v1,.L0f15c200
/*  f15c190:	00000000 */ 	nop
/*  f15c194:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f15c198:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c19c:	00608025 */ 	or	$s0,$v1,$zero
/*  f15c1a0:	11c00017 */ 	beqz	$t6,.L0f15c200
/*  f15c1a4:	31c200ff */ 	andi	$v0,$t6,0xff
/*  f15c1a8:	3c13800a */ 	lui	$s3,%hi(g_BgPrimaryData)
/*  f15c1ac:	2673491c */ 	addiu	$s3,$s3,%lo(g_BgPrimaryData)
/*  f15c1b0:	3c14f100 */ 	lui	$s4,0xf100
/*  f15c1b4:	24110064 */ 	addiu	$s1,$zero,0x64
.L0f15c1b8:
/*  f15c1b8:	5622000c */ 	bnel	$s1,$v0,.L0f15c1ec
/*  f15c1bc:	92020008 */ 	lbu	$v0,0x8($s0)
/*  f15c1c0:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f15c1c4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15c1c8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f15c1cc:	0fc5761c */ 	jal	portalFindNumByVertices
/*  f15c1d0:	03142021 */ 	addu	$a0,$t8,$s4
/*  f15c1d4:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f15c1d8:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c1dc:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f15c1e0:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f15c1e4:	03328021 */ 	addu	$s0,$t9,$s2
/*  f15c1e8:	92020008 */ 	lbu	$v0,0x8($s0)
.L0f15c1ec:
/*  f15c1ec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c1f0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15c1f4:	1440fff0 */ 	bnez	$v0,.L0f15c1b8
/*  f15c1f8:	00000000 */ 	nop
/*  f15c1fc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c200:
/*  f15c200:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15c204:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15c208:	8e7802bc */ 	lw	$t8,0x2bc($s3)
/*  f15c20c:	1b000021 */ 	blez	$t8,.L0f15c294
/*  f15c210:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c214:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f15c218:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15c21c:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15c220:
/*  f15c220:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c224:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c228:	a5e00000 */ 	sh	$zero,0x0($t7)
/*  f15c22c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c230:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c234:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f15c238:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c23c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c240:	a1e20007 */ 	sb	$v0,0x7($t7)
/*  f15c244:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c248:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c24c:	a7000002 */ 	sh	$zero,0x2($t8)
/*  f15c250:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c254:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c258:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f15c25c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c260:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c264:	af030080 */ 	sw	$v1,0x80($t8)
/*  f15c268:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c26c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c270:	ade00084 */ 	sw	$zero,0x84($t7)
/*  f15c274:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c278:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c27c:	af000088 */ 	sw	$zero,0x88($t8)
/*  f15c280:	8e6e02bc */ 	lw	$t6,0x2bc($s3)
/*  f15c284:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15c288:	028e082a */ 	slt	$at,$s4,$t6
/*  f15c28c:	5420ffe4 */ 	bnezl	$at,.L0f15c220
/*  f15c290:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15c294:
/*  f15c294:	0fc04fb8 */ 	jal	roomsReset
/*  f15c298:	00000000 */ 	nop
/*  f15c29c:	44808000 */ 	mtc1	$zero,$f16
/*  f15c2a0:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c2a4:	e5f00018 */ 	swc1	$f16,0x18($t7)
/*  f15c2a8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c2ac:	e730001c */ 	swc1	$f16,0x1c($t9)
/*  f15c2b0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c2b4:	e7100020 */ 	swc1	$f16,0x20($t8)
/*  f15c2b8:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c2bc:	e5d00024 */ 	swc1	$f16,0x24($t6)
/*  f15c2c0:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c2c4:	e5f00028 */ 	swc1	$f16,0x28($t7)
/*  f15c2c8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c2cc:	0fc4f0fd */ 	jal	dyntexReset
/*  f15c2d0:	e730002c */ 	swc1	$f16,0x2c($t9)
/*  f15c2d4:	03a08025 */ 	or	$s0,$sp,$zero
/*  f15c2d8:	261000b3 */ 	addiu	$s0,$s0,0xb3
/*  f15c2dc:	3c12800a */ 	lui	$s2,%hi(g_BgSection3)
/*  f15c2e0:	3618000f */ 	ori	$t8,$s0,0xf
/*  f15c2e4:	26524924 */ 	addiu	$s2,$s2,%lo(g_BgSection3)
/*  f15c2e8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15c2ec:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c2f0:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c2f4:	0fc56c71 */ 	jal	bgLoadFile
/*  f15c2f8:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f15c2fc:	96020000 */ 	lhu	$v0,0x0($s0)
/*  f15c300:	34018000 */ 	dli	$at,0x8000
/*  f15c304:	96110002 */ 	lhu	$s1,0x2($s0)
/*  f15c308:	304f7fff */ 	andi	$t7,$v0,0x7fff
/*  f15c30c:	25e2ffff */ 	addiu	$v0,$t7,-1
/*  f15c310:	3459000f */ 	ori	$t9,$v0,0xf
/*  f15c314:	27220001 */ 	addiu	$v0,$t9,0x1
/*  f15c318:	00412021 */ 	addu	$a0,$v0,$at
/*  f15c31c:	0c0048f2 */ 	jal	mempAlloc
/*  f15c320:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c324:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c328:	34018000 */ 	dli	$at,0x8000
/*  f15c32c:	2626ffff */ 	addiu	$a2,$s1,-1
/*  f15c330:	00412021 */ 	addu	$a0,$v0,$at
/*  f15c334:	34d8000f */ 	ori	$t8,$a2,0xf
/*  f15c338:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f15c33c:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c340:	27060001 */ 	addiu	$a2,$t8,0x1
/*  f15c344:	0fc56c71 */ 	jal	bgLoadFile
/*  f15c348:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f15c34c:	02002025 */ 	or	$a0,$s0,$zero
/*  f15c350:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f15c354:	0fc5766a */ 	jal	bgInflate
/*  f15c358:	02203025 */ 	or	$a2,$s1,$zero
/*  f15c35c:	8e6302bc */ 	lw	$v1,0x2bc($s3)
/*  f15c360:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f15c364:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c368:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c36c:	1420007a */ 	bnez	$at,.L0f15c558
/*  f15c370:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c374:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c378:	3c13800a */ 	lui	$s3,%hi(g_BgRooms)
/*  f15c37c:	44818000 */ 	mtc1	$at,$f16
/*  f15c380:	26734cc4 */ 	addiu	$s3,$s3,%lo(g_BgRooms)
/*  f15c384:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c388:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c38c:	24120014 */ 	addiu	$s2,$zero,0x14
/*  f15c390:	86190000 */ 	lh	$t9,0x0($s0)
.L0f15c394:
/*  f15c394:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c398:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c39c:	44999000 */ 	mtc1	$t9,$f18
/*  f15c3a0:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c3a4:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f15c3a8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c3ac:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c3b0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15c3b4:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c3b8:	e5c80018 */ 	swc1	$f8,0x18($t6)
/*  f15c3bc:	8618fff6 */ 	lh	$t8,-0xa($s0)
/*  f15c3c0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c3c4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c3c8:	44989000 */ 	mtc1	$t8,$f18
/*  f15c3cc:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c3d0:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f15c3d4:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c3d8:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c3dc:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c3e0:	e5e4001c */ 	swc1	$f4,0x1c($t7)
/*  f15c3e4:	860efff8 */ 	lh	$t6,-0x8($s0)
/*  f15c3e8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15c3ec:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c3f0:	448e9000 */ 	mtc1	$t6,$f18
/*  f15c3f4:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c3f8:	c708000c */ 	lwc1	$f8,0xc($t8)
/*  f15c3fc:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f15c400:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c404:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f15c408:	e72a0020 */ 	swc1	$f10,0x20($t9)
/*  f15c40c:	860ffffa */ 	lh	$t7,-0x6($s0)
/*  f15c410:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15c414:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c418:	448f9000 */ 	mtc1	$t7,$f18
/*  f15c41c:	03127021 */ 	addu	$t6,$t8,$s2
/*  f15c420:	c5c40004 */ 	lwc1	$f4,0x4($t6)
/*  f15c424:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f15c428:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c42c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f15c430:	e7060024 */ 	swc1	$f6,0x24($t8)
/*  f15c434:	8619fffc */ 	lh	$t9,-0x4($s0)
/*  f15c438:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c43c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c440:	44999000 */ 	mtc1	$t9,$f18
/*  f15c444:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c448:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f15c44c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c450:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c454:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c458:	e5c80028 */ 	swc1	$f8,0x28($t6)
/*  f15c45c:	8618fffe */ 	lh	$t8,-0x2($s0)
/*  f15c460:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c464:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c468:	44989000 */ 	mtc1	$t8,$f18
/*  f15c46c:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c470:	c726000c */ 	lwc1	$f6,0xc($t9)
/*  f15c474:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c478:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c47c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c480:	e5e4002c */ 	swc1	$f4,0x2c($t7)
/*  f15c484:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c488:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c48c:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c490:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*  f15c494:	46124180 */ 	add.s	$f6,$f8,$f18
/*  f15c498:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f15c49c:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*  f15c4a0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c4a4:	03111021 */ 	addu	$v0,$t8,$s1
/*  f15c4a8:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f15c4ac:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f15c4b0:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15c4b4:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f15c4b8:	e4460034 */ 	swc1	$f6,0x34($v0)
/*  f15c4bc:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c4c0:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f15c4c4:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c4c8:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f15c4cc:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c4d0:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f15c4d4:	e4520038 */ 	swc1	$f18,0x38($v0)
/*  f15c4d8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c4dc:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f15c4e0:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f15c4e4:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c4e8:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f15c4ec:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c4f0:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f15c4f4:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f15c4f8:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f15c4fc:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f15c500:	46069381 */ 	sub.s	$f14,$f18,$f6
/*  f15c504:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15c508:	00000000 */ 	nop
/*  f15c50c:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f15c510:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c514:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f15c518:	0c012974 */ 	jal	sqrtf
/*  f15c51c:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f15c520:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c524:	44818000 */ 	mtc1	$at,$f16
/*  f15c528:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c52c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c530:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f15c534:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c538:	2631008c */ 	addiu	$s1,$s1,140
/*  f15c53c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f15c540:	e706003c */ 	swc1	$f6,0x3c($t8)
/*  f15c544:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c548:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c54c:	5420ff91 */ 	bnezl	$at,.L0f15c394
/*  f15c550:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15c554:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c558:
/*  f15c558:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c55c:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c560:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c564:	14200012 */ 	bnez	$at,.L0f15c5b0
/*  f15c568:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c56c:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c570:	944e0000 */ 	lhu	$t6,0x0($v0)
.L0f15c574:
/*  f15c574:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c578:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15c57c:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f15c580:	25f9010f */ 	addiu	$t9,$t7,0x10f
/*  f15c584:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c588:	3738000f */ 	ori	$t8,$t9,0xf
/*  f15c58c:	3b0e000f */ 	xori	$t6,$t8,0xf
/*  f15c590:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c594:	af2e0080 */ 	sw	$t6,0x80($t9)
/*  f15c598:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c59c:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c5a0:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c5a4:	5420fff3 */ 	bnezl	$at,.L0f15c574
/*  f15c5a8:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c5ac:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c5b0:
/*  f15c5b0:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c5b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f15c5b8:	1420001b */ 	bnez	$at,.L0f15c628
/*  f15c5bc:	00402825 */ 	or	$a1,$v0,$zero
/*  f15c5c0:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c5c4:	3403ffff */ 	dli	$v1,0xffff
.L0f15c5c8:
/*  f15c5c8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c5cc:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f15c5d0:	01f17021 */ 	addu	$t6,$t7,$s1
/*  f15c5d4:	a1d80008 */ 	sb	$t8,0x8($t6)
/*  f15c5d8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c5dc:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c5e0:	804f0008 */ 	lb	$t7,0x8($v0)
/*  f15c5e4:	59e0000a */ 	blezl	$t7,.L0f15c610
/*  f15c5e8:	a443000a */ 	sh	$v1,0xa($v0)
/*  f15c5ec:	a444000a */ 	sh	$a0,0xa($v0)
/*  f15c5f0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c5f4:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c5f8:	81d90008 */ 	lb	$t9,0x8($t6)
/*  f15c5fc:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15c600:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f15c604:	10000002 */ 	b	.L0f15c610
/*  f15c608:	000f2403 */ 	sra	$a0,$t7,0x10
/*  f15c60c:	a443000a */ 	sh	$v1,0xa($v0)
.L0f15c610:
/*  f15c610:	8fce02bc */ 	lw	$t6,0x2bc($s8)
/*  f15c614:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c618:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c61c:	028e082b */ 	sltu	$at,$s4,$t6
/*  f15c620:	1420ffe9 */ 	bnez	$at,.L0f15c5c8
/*  f15c624:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f15c628:
/*  f15c628:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f15c62c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15c630:	0c00490c */ 	jal	mempRealloc
/*  f15c634:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15c638:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c63c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c640:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c644:	5420000a */ 	bnezl	$at,.L0f15c670
/*  f15c648:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c64c:
/*  f15c64c:	0fc004f2 */ 	jal	roomInitLights
/*  f15c650:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c654:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c658:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c65c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c660:	1420fffa */ 	bnez	$at,.L0f15c64c
/*  f15c664:	00000000 */ 	nop
/*  f15c668:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c66c:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c670:
/*  f15c670:	1420000b */ 	bnez	$at,.L0f15c6a0
/*  f15c674:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f15c678:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f15c67c:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c680:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c684:	258c008c */ 	addiu	$t4,$t4,140
.L0f15c688:
/*  f15c688:	81990008 */ 	lb	$t9,0x8($t4)
/*  f15c68c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c690:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c694:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15c698:	1420fffb */ 	bnez	$at,.L0f15c688
/*  f15c69c:	02d9b021 */ 	addu	$s6,$s6,$t9
.L0f15c6a0:
/*  f15c6a0:	12c0001c */ 	beqz	$s6,.L0f15c714
/*  f15c6a4:	3c03800a */ 	lui	$v1,%hi(var800a41a0)
/*  f15c6a8:	00162080 */ 	sll	$a0,$s6,0x2
/*  f15c6ac:	00962023 */ 	subu	$a0,$a0,$s6
/*  f15c6b0:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15c6b4:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15c6b8:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15c6bc:	0c0048f2 */ 	jal	mempAlloc
/*  f15c6c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c6c4:	3c03800a */ 	lui	$v1,%hi(var800a41a0)
/*  f15c6c8:	246341a0 */ 	addiu	$v1,$v1,%lo(var800a41a0)
/*  f15c6cc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15c6d0:	1ac00013 */ 	blez	$s6,.L0f15c720
/*  f15c6d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15c6d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f15c6dc:
/*  f15c6dc:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c6e0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c6e4:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c6e8:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f15c6ec:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15c6f0:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f15c6f4:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f15c6f8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c6fc:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c700:	24420003 */ 	addiu	$v0,$v0,0x3
/*  f15c704:	1696fff5 */ 	bne	$s4,$s6,.L0f15c6dc
/*  f15c708:	a3200002 */ 	sb	$zero,0x2($t9)
/*  f15c70c:	10000004 */ 	b	.L0f15c720
/*  f15c710:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c714:
/*  f15c714:	246341a0 */ 	addiu	$v1,$v1,%lo(var800a41a0)
/*  f15c718:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f15c71c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c720:
/*  f15c720:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15c724:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c728:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15c72c:	1300000a */ 	beqz	$t8,.L0f15c758
/*  f15c730:	00000000 */ 	nop
.L0f15c734:
/*  f15c734:	0fc592ae */ 	jal	func0f164ab8
/*  f15c738:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c73c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15c740:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c744:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c748:	01d2c821 */ 	addu	$t9,$t6,$s2
/*  f15c74c:	972f0000 */ 	lhu	$t7,0x0($t9)
/*  f15c750:	15e0fff8 */ 	bnez	$t7,.L0f15c734
/*  f15c754:	00000000 */ 	nop
.L0f15c758:
/*  f15c758:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f15c75c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f15c760:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c764:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c768:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c76c:	5420000a */ 	bnezl	$at,.L0f15c798
/*  f15c770:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c774:
/*  f15c774:	0fc59319 */ 	jal	room0f164c64
/*  f15c778:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c77c:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c780:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c784:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c788:	1420fffa */ 	bnez	$at,.L0f15c774
/*  f15c78c:	00000000 */ 	nop
/*  f15c790:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c794:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c798:
/*  f15c798:	54200009 */ 	bnezl	$at,.L0f15c7c0
/*  f15c79c:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c7a0:
/*  f15c7a0:	0fc59233 */ 	jal	bgExpandRoomToPortals
/*  f15c7a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c7a8:	8e1802bc */ 	lw	$t8,0x2bc($s0)
/*  f15c7ac:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c7b0:	0298082a */ 	slt	$at,$s4,$t8
/*  f15c7b4:	1420fffa */ 	bnez	$at,.L0f15c7a0
/*  f15c7b8:	00000000 */ 	nop
/*  f15c7bc:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c7c0:
/*  f15c7c0:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c7c4:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f15c7c8:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c7cc:	11c0000a */ 	beqz	$t6,.L0f15c7f8
/*  f15c7d0:	00000000 */ 	nop
/*  f15c7d4:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c7d8:
/*  f15c7d8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c7dc:	332f00fe */ 	andi	$t7,$t9,0xfe
/*  f15c7e0:	a04f0006 */ 	sb	$t7,0x6($v0)
/*  f15c7e4:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f15c7e8:	03121021 */ 	addu	$v0,$t8,$s2
/*  f15c7ec:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c7f0:	55c0fff9 */ 	bnezl	$t6,.L0f15c7d8
/*  f15c7f4:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c7f8:
/*  f15c7f8:	0fc597b9 */ 	jal	envSetStageNum
/*  f15c7fc:	8fa40148 */ 	lw	$a0,0x148($sp)
/*  f15c800:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f15c804:	3c018008 */ 	lui	$at,%hi(var8007fc10)
/*  f15c808:	0fc04d54 */ 	jal	wallhitReset
/*  f15c80c:	a439fc10 */ 	sh	$t9,%lo(var8007fc10)($at)
/*  f15c810:	0fc00aa6 */ 	jal	func0f002a98
/*  f15c814:	00000000 */ 	nop
/*  f15c818:	0fc00703 */ 	jal	func0f001c0c
/*  f15c81c:	00000000 */ 	nop
/*  f15c820:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f15c824:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15c828:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15c82c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15c830:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f15c834:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f15c838:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f15c83c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f15c840:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f15c844:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f15c848:	03e00008 */ 	jr	$ra
/*  f15c84c:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bgBuildTables
.late_rodata
glabel var7f1b75cc
.word 0x7f7fffff
glabel var7f1b75d0
.word 0xff7fffff
.text
/*  f15b6cc:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f15b6d0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f15b6d4:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15b6d8:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15b6dc:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f15b6e0:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b6e4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f15b6e8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f15b6ec:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f15b6f0:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f15b6f4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b6f8:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f15b6fc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b700:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f15b704:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15b708:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f15b70c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f15b710:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f15b714:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f15b718:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15b71c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15b720:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15b724:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15b728:	0c0048f2 */ 	jal	mempAlloc
/*  f15b72c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b730:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b734:	3c15800a */ 	lui	$s5,%hi(g_Rooms)
/*  f15b738:	26b54928 */ 	addiu	$s5,$s5,%lo(g_Rooms)
/*  f15b73c:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f15b740:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15b744:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15b748:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f15b74c:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15b750:	0c0048f2 */ 	jal	mempAlloc
/*  f15b754:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b758:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b75c:	3c03800a */ 	lui	$v1,%hi(var800a4ce8)
/*  f15b760:	24634ce8 */ 	addiu	$v1,$v1,%lo(var800a4ce8)
/*  f15b764:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b768:	1a200010 */ 	blez	$s1,.L0f15b7ac
/*  f15b76c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15b770:	00001025 */ 	or	$v0,$zero,$zero
/*  f15b774:	3416ffff */ 	dli	$s6,0xffff
/*  f15b778:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f15b77c:
/*  f15b77c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b780:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f15b784:	a7360000 */ 	sh	$s6,0x0($t9)
/*  f15b788:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15b78c:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f15b790:	a5e00002 */ 	sh	$zero,0x2($t7)
/*  f15b794:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b798:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15b79c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15b7a0:	5420fff6 */ 	bnezl	$at,.L0f15b77c
/*  f15b7a4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f15b7a8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15b7ac:
/*  f15b7ac:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f15b7b0:	13000013 */ 	beqz	$t8,.L0f15b800
/*  f15b7b4:	2624000f */ 	addiu	$a0,$s1,0xf
/*  f15b7b8:	3499000f */ 	ori	$t9,$a0,0xf
/*  f15b7bc:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f15b7c0:	0c0048f2 */ 	jal	mempAlloc
/*  f15b7c4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b7c8:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b7cc:	3c03800a */ 	lui	$v1,%hi(g_MpRoomVisibility)
/*  f15b7d0:	2463492c */ 	addiu	$v1,$v1,%lo(g_MpRoomVisibility)
/*  f15b7d4:	1a20000a */ 	blez	$s1,.L0f15b800
/*  f15b7d8:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b7dc:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f15b7e0:
/*  f15b7e0:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f15b7e4:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f15b7e8:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b7ec:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b7f0:	0291082a */ 	slt	$at,$s4,$s1
/*  f15b7f4:	5420fffa */ 	bnezl	$at,.L0f15b7e0
/*  f15b7f8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15b7fc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15b800:
/*  f15b800:	1a200020 */ 	blez	$s1,.L0f15b884
/*  f15b804:	00009025 */ 	or	$s2,$zero,$zero
/*  f15b808:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15b80c:
/*  f15b80c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b810:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15b814:	adc00044 */ 	sw	$zero,0x44($t6)
/*  f15b818:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15b81c:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15b820:	a3000008 */ 	sb	$zero,0x8($t8)
/*  f15b824:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15b828:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15b82c:	a5c0000a */ 	sh	$zero,0xa($t6)
/*  f15b830:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15b834:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15b838:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f15b83c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15b840:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15b844:	a1c0004d */ 	sb	$zero,0x4d($t6)
/*  f15b848:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15b84c:	01f26021 */ 	addu	$t4,$t7,$s2
/*  f15b850:	9198004e */ 	lbu	$t8,0x4e($t4)
/*  f15b854:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f15b858:	a199004e */ 	sb	$t9,0x4e($t4)
/*  f15b85c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15b860:	01d26021 */ 	addu	$t4,$t6,$s2
/*  f15b864:	918f004e */ 	lbu	$t7,0x4e($t4)
/*  f15b868:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15b86c:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f15b870:	a198004e */ 	sb	$t8,0x4e($t4)
/*  f15b874:	8e7902bc */ 	lw	$t9,0x2bc($s3)
/*  f15b878:	0299082a */ 	slt	$at,$s4,$t9
/*  f15b87c:	5420ffe3 */ 	bnezl	$at,.L0f15b80c
/*  f15b880:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15b884:
/*  f15b884:	3c118008 */ 	lui	$s1,%hi(g_StageIndex)
/*  f15b888:	2631fc00 */ 	addiu	$s1,$s1,%lo(g_StageIndex)
/*  f15b88c:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f15b890:	24120038 */ 	addiu	$s2,$zero,0x38
/*  f15b894:	3c108008 */ 	lui	$s0,%hi(g_Stages)
/*  f15b898:	01d20019 */ 	multu	$t6,$s2
/*  f15b89c:	2610fcc0 */ 	addiu	$s0,$s0,%lo(g_Stages)
/*  f15b8a0:	00007812 */ 	mflo	$t7
/*  f15b8a4:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f15b8a8:	0fc5718f */ 	jal	func0f15c880
/*  f15b8ac:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f15b8b0:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f15b8b4:	03320019 */ 	multu	$t9,$s2
/*  f15b8b8:	00007012 */ 	mflo	$t6
/*  f15b8bc:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f15b8c0:	0fc0a124 */ 	jal	chr0f028490
/*  f15b8c4:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f15b8c8:	3c188008 */ 	lui	$t8,%hi(g_StageIndex)
/*  f15b8cc:	8f18fc00 */ 	lw	$t8,%lo(g_StageIndex)($t8)
/*  f15b8d0:	3c018008 */ 	lui	$at,%hi(g_Stages+0x18)
/*  f15b8d4:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f15b8d8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f15b8dc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f15b8e0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f15b8e4:	00390821 */ 	addu	$at,$at,$t9
/*  f15b8e8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x200)
/*  f15b8ec:	2463a1c0 */ 	addiu	$v1,$v1,%lo(g_Vars+0x200)
/*  f15b8f0:	c420fcd8 */ 	lwc1	$f0,%lo(g_Stages+0x18)($at)
/*  f15b8f4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f15b8f8:
/*  f15b8f8:	24420080 */ 	addiu	$v0,$v0,0x80
/*  f15b8fc:	0043082b */ 	sltu	$at,$v0,$v1
/*  f15b900:	1420fffd */ 	bnez	$at,.L0f15b8f8
/*  f15b904:	e4400068 */ 	swc1	$f0,0x68($v0)
/*  f15b908:	3c013f80 */ 	lui	$at,0x3f80
/*  f15b90c:	44816000 */ 	mtc1	$at,$f12
/*  f15b910:	0c0059d2 */ 	jal	mtx00016748
/*  f15b914:	00000000 */ 	nop
/*  f15b918:	3c0e800a */ 	lui	$t6,%hi(var800a4920)
/*  f15b91c:	8dce4920 */ 	lw	$t6,%lo(var800a4920)($t6)
/*  f15b920:	3c17800a */ 	lui	$s7,%hi(g_BgPortals)
/*  f15b924:	26f74cc8 */ 	addiu	$s7,$s7,%lo(g_BgPortals)
/*  f15b928:	15c00322 */ 	bnez	$t6,.L0f15c5b4
/*  f15b92c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b930:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15b934:	0000f025 */ 	or	$s8,$zero,$zero
/*  f15b938:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f15b93c:	11e00006 */ 	beqz	$t7,.L0f15b958
/*  f15b940:	02001025 */ 	or	$v0,$s0,$zero
/*  f15b944:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15b948:
/*  f15b948:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f15b94c:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f15b950:	5700fffd */ 	bnezl	$t8,.L0f15b948
/*  f15b954:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15b958:
/*  f15b958:	001ec900 */ 	sll	$t9,$s8,0x4
/*  f15b95c:	3c028008 */ 	lui	$v0,%hi(g_NumPortalThings)
/*  f15b960:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15b964:	2442fc40 */ 	addiu	$v0,$v0,%lo(g_NumPortalThings)
/*  f15b968:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15b96c:	ac5e0000 */ 	sw	$s8,0x0($v0)
/*  f15b970:	0c0048f2 */ 	jal	mempAlloc
/*  f15b974:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15b978:	3c01800a */ 	lui	$at,%hi(g_PortalThings)
/*  f15b97c:	ac224cec */ 	sw	$v0,%lo(g_PortalThings)($at)
/*  f15b980:	001e20c0 */ 	sll	$a0,$s8,0x3
/*  f15b984:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15b988:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15b98c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15b990:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15b994:	2412000c */ 	addiu	$s2,$zero,0xc
.L0f15b998:
/*  f15b998:	1bc0000b */ 	blez	$s8,.L0f15b9c8
/*  f15b99c:	00001825 */ 	or	$v1,$zero,$zero
.L0f15b9a0:
/*  f15b9a0:	02031021 */ 	addu	$v0,$s0,$v1
/*  f15b9a4:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f15b9a8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15b9ac:	16980003 */ 	bne	$s4,$t8,.L0f15b9bc
/*  f15b9b0:	00000000 */ 	nop
/*  f15b9b4:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f15b9b8:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15b9bc:
/*  f15b9bc:	16defff8 */ 	bne	$s6,$s8,.L0f15b9a0
/*  f15b9c0:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15b9c4:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15b9c8:
/*  f15b9c8:	02048821 */ 	addu	$s1,$s0,$a0
/*  f15b9cc:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15b9d0:	18a00007 */ 	blez	$a1,.L0f15b9f0
/*  f15b9d4:	00000000 */ 	nop
/*  f15b9d8:	00b20019 */ 	multu	$a1,$s2
/*  f15b9dc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b9e0:	0000c812 */ 	mflo	$t9
/*  f15b9e4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15b9e8:	1000ffeb */ 	b	.L0f15b998
/*  f15b9ec:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f15b9f0:
/*  f15b9f0:	17c00003 */ 	bnez	$s8,.L0f15ba00
/*  f15b9f4:	00008025 */ 	or	$s0,$zero,$zero
/*  f15b9f8:	10000002 */ 	b	.L0f15ba04
/*  f15b9fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15ba00:
/*  f15ba00:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15ba04:
/*  f15ba04:	00022080 */ 	sll	$a0,$v0,0x2
/*  f15ba08:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15ba0c:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15ba10:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15ba14:	0c0048f2 */ 	jal	mempAlloc
/*  f15ba18:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15ba1c:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15ba20:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15ba24:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15ba28:	3c13800a */ 	lui	$s3,%hi(g_RoomPortals)
/*  f15ba2c:	26734ce0 */ 	addiu	$s3,$s3,%lo(g_RoomPortals)
/*  f15ba30:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f15ba34:	aca0002c */ 	sw	$zero,0x2c($a1)
/*  f15ba38:	1a200033 */ 	blez	$s1,.L0f15bb08
/*  f15ba3c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15ba40:	00009025 */ 	or	$s2,$zero,$zero
/*  f15ba44:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f15ba48:
/*  f15ba48:	00002025 */ 	or	$a0,$zero,$zero
/*  f15ba4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f15ba50:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15ba54:	1bc0001d */ 	blez	$s8,.L0f15bacc
/*  f15ba58:	a730000e */ 	sh	$s0,0xe($t9)
.L0f15ba5c:
/*  f15ba5c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15ba60:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f15ba64:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f15ba68:	568f000a */ 	bnel	$s4,$t7,.L0f15ba94
/*  f15ba6c:	84580004 */ 	lh	$t8,0x4($v0)
/*  f15ba70:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15ba74:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f15ba78:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15ba7c:	03197021 */ 	addu	$t6,$t8,$t9
/*  f15ba80:	a5d60000 */ 	sh	$s6,0x0($t6)
/*  f15ba84:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15ba88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15ba8c:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f15ba90:	84580004 */ 	lh	$t8,0x4($v0)
.L0f15ba94:
/*  f15ba94:	00107040 */ 	sll	$t6,$s0,0x1
/*  f15ba98:	56980007 */ 	bnel	$s4,$t8,.L0f15bab8
/*  f15ba9c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15baa0:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15baa4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15baa8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15baac:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f15bab0:	a5f60000 */ 	sh	$s6,0x0($t7)
/*  f15bab4:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f15bab8:
/*  f15bab8:	16deffe8 */ 	bne	$s6,$s8,.L0f15ba5c
/*  f15babc:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15bac0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15bac4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15bac8:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bacc:
/*  f15bacc:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bad0:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15bad4:	a3240005 */ 	sb	$a0,0x5($t9)
/*  f15bad8:	8cae002c */ 	lw	$t6,0x2c($a1)
/*  f15badc:	01c4082a */ 	slt	$at,$t6,$a0
/*  f15bae0:	50200003 */ 	beqzl	$at,.L0f15baf0
/*  f15bae4:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15bae8:	aca4002c */ 	sw	$a0,0x2c($a1)
/*  f15baec:	8cb102bc */ 	lw	$s1,0x2bc($a1)
.L0f15baf0:
/*  f15baf0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15baf4:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15baf8:	0291082a */ 	slt	$at,$s4,$s1
/*  f15bafc:	5420ffd2 */ 	bnezl	$at,.L0f15ba48
/*  f15bb00:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bb04:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bb08:
/*  f15bb08:	1a200058 */ 	blez	$s1,.L0f15bc6c
/*  f15bb0c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bb10:	8eac0000 */ 	lw	$t4,0x0($s5)
.L0f15bb14:
/*  f15bb14:	818b0005 */ 	lb	$t3,0x5($t4)
/*  f15bb18:	5960004f */ 	blezl	$t3,.L0f15bc58
/*  f15bb1c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bb20:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15bb24:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15bb28:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bb2c:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f15bb30:	01f96821 */ 	addu	$t5,$t7,$t9
/*  f15bb34:	01a0f825 */ 	or	$ra,$t5,$zero
/*  f15bb38:	00008825 */ 	or	$s1,$zero,$zero
.L0f15bb3c:
/*  f15bb3c:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15bb40:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15bb44:	000a70c0 */ 	sll	$t6,$t2,0x3
/*  f15bb48:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f15bb4c:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15bb50:	16840003 */ 	bne	$s4,$a0,.L0f15bb60
/*  f15bb54:	00803825 */ 	or	$a3,$a0,$zero
/*  f15bb58:	10000001 */ 	b	.L0f15bb60
/*  f15bb5c:	84670004 */ 	lh	$a3,0x4($v1)
.L0f15bb60:
/*  f15bb60:	10200034 */ 	beqz	$at,.L0f15bc34
/*  f15bb64:	02c04025 */ 	or	$t0,$s6,$zero
/*  f15bb68:	00084840 */ 	sll	$t1,$t0,0x1
.L0f15bb6c:
/*  f15bb6c:	01a92821 */ 	addu	$a1,$t5,$t1
/*  f15bb70:	84a60000 */ 	lh	$a2,0x0($a1)
/*  f15bb74:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15bb78:	00002025 */ 	or	$a0,$zero,$zero
/*  f15bb7c:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f15bb80:	02181021 */ 	addu	$v0,$s0,$t8
/*  f15bb84:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15bb88:	16830007 */ 	bne	$s4,$v1,.L0f15bba8
/*  f15bb8c:	0067082a */ 	slt	$at,$v1,$a3
/*  f15bb90:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f15bb94:	01e7082a */ 	slt	$at,$t7,$a3
/*  f15bb98:	10200006 */ 	beqz	$at,.L0f15bbb4
/*  f15bb9c:	00000000 */ 	nop
/*  f15bba0:	10000004 */ 	b	.L0f15bbb4
/*  f15bba4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bba8:
/*  f15bba8:	10200002 */ 	beqz	$at,.L0f15bbb4
/*  f15bbac:	00000000 */ 	nop
/*  f15bbb0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bbb4:
/*  f15bbb4:	5080001d */ 	beqzl	$a0,.L0f15bc2c
/*  f15bbb8:	010b082a */ 	slt	$at,$t0,$t3
/*  f15bbbc:	a4aa0000 */ 	sh	$t2,0x0($a1)
/*  f15bbc0:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15bbc4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15bbc8:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f15bbcc:	870f000e */ 	lh	$t7,0xe($t8)
/*  f15bbd0:	000f7040 */ 	sll	$t6,$t7,0x1
/*  f15bbd4:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f15bbd8:	03117821 */ 	addu	$t7,$t8,$s1
/*  f15bbdc:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f15bbe0:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15bbe4:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15bbe8:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bbec:	03326021 */ 	addu	$t4,$t9,$s2
/*  f15bbf0:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15bbf4:	00187840 */ 	sll	$t7,$t8,0x1
/*  f15bbf8:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f15bbfc:	01b1f821 */ 	addu	$ra,$t5,$s1
/*  f15bc00:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15bc04:	000ac8c0 */ 	sll	$t9,$t2,0x3
/*  f15bc08:	02191821 */ 	addu	$v1,$s0,$t9
/*  f15bc0c:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15bc10:	16840004 */ 	bne	$s4,$a0,.L0f15bc24
/*  f15bc14:	00803825 */ 	or	$a3,$a0,$zero
/*  f15bc18:	84670004 */ 	lh	$a3,0x4($v1)
/*  f15bc1c:	10000002 */ 	b	.L0f15bc28
/*  f15bc20:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15bc24:
/*  f15bc24:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15bc28:
/*  f15bc28:	010b082a */ 	slt	$at,$t0,$t3
.L0f15bc2c:
/*  f15bc2c:	1420ffcf */ 	bnez	$at,.L0f15bb6c
/*  f15bc30:	25290002 */ 	addiu	$t1,$t1,0x2
.L0f15bc34:
/*  f15bc34:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bc38:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15bc3c:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f15bc40:	1420ffbe */ 	bnez	$at,.L0f15bb3c
/*  f15bc44:	27ff0002 */ 	addiu	$ra,$ra,0x2
/*  f15bc48:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x2bc)
/*  f15bc4c:	8e31a27c */ 	lw	$s1,%lo(g_Vars+0x2bc)($s1)
/*  f15bc50:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15bc54:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f15bc58:
/*  f15bc58:	0291082a */ 	slt	$at,$s4,$s1
/*  f15bc5c:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15bc60:	1420ffac */ 	bnez	$at,.L0f15bb14
/*  f15bc64:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15bc68:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bc6c:
/*  f15bc6c:	17c00003 */ 	bnez	$s8,.L0f15bc7c
/*  f15bc70:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bc74:	10000002 */ 	b	.L0f15bc80
/*  f15bc78:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15bc7c:
/*  f15bc7c:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15bc80:
/*  f15bc80:	2444000f */ 	addiu	$a0,$v0,0xf
/*  f15bc84:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bc88:	0c0048f2 */ 	jal	mempAlloc
/*  f15bc8c:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15bc90:	3c10800a */ 	lui	$s0,%hi(var800a4cd0)
/*  f15bc94:	26104cd0 */ 	addiu	$s0,$s0,%lo(var800a4cd0)
/*  f15bc98:	1bc00009 */ 	blez	$s8,.L0f15bcc0
/*  f15bc9c:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f15bca0:
/*  f15bca0:	0fc56ca4 */ 	jal	func0f15b4c0
/*  f15bca4:	02802025 */ 	or	$a0,$s4,$zero
/*  f15bca8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f15bcac:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f15bcb0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bcb4:	169efffa */ 	bne	$s4,$s8,.L0f15bca0
/*  f15bcb8:	a3220000 */ 	sb	$v0,0x0($t9)
/*  f15bcbc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bcc0:
/*  f15bcc0:	001e2080 */ 	sll	$a0,$s8,0x2
/*  f15bcc4:	009e2021 */ 	addu	$a0,$a0,$s8
/*  f15bcc8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f15bccc:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15bcd0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bcd4:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15bcd8:	0c0048f2 */ 	jal	mempAlloc
/*  f15bcdc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bce0:	3c01800a */ 	lui	$at,%hi(var800a4ccc)
/*  f15bce4:	1bc00095 */ 	blez	$s8,.L0f15bf3c
/*  f15bce8:	ac224ccc */ 	sw	$v0,%lo(var800a4ccc)($at)
/*  f15bcec:	44808000 */ 	mtc1	$zero,$f16
/*  f15bcf0:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bcf4:	00003025 */ 	or	$a2,$zero,$zero
/*  f15bcf8:	2413000c */ 	addiu	$s3,$zero,0xc
.L0f15bcfc:
/*  f15bcfc:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bd00:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f15bd04:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f15bd08:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f15bd0c:	02127821 */ 	addu	$t7,$s0,$s2
/*  f15bd10:	95f90000 */ 	lhu	$t9,0x0($t7)
/*  f15bd14:	03308821 */ 	addu	$s1,$t9,$s0
/*  f15bd18:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bd1c:	02201825 */ 	or	$v1,$s1,$zero
/*  f15bd20:	18a00035 */ 	blez	$a1,.L0f15bdf8
/*  f15bd24:	26c40001 */ 	addiu	$a0,$s6,0x1
.L0f15bd28:
/*  f15bd28:	0085001a */ 	div	$zero,$a0,$a1
/*  f15bd2c:	0000c010 */ 	mfhi	$t8
/*  f15bd30:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f15bd34:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15bd38:	03130019 */ 	multu	$t8,$s3
/*  f15bd3c:	0080b025 */ 	or	$s6,$a0,$zero
/*  f15bd40:	14a00002 */ 	bnez	$a1,.L0f15bd4c
/*  f15bd44:	00000000 */ 	nop
/*  f15bd48:	0007000d */ 	break	0x7
.L0f15bd4c:
/*  f15bd4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15bd50:	14a10004 */ 	bne	$a1,$at,.L0f15bd64
/*  f15bd54:	3c018000 */ 	lui	$at,0x8000
/*  f15bd58:	14810002 */ 	bne	$a0,$at,.L0f15bd64
/*  f15bd5c:	00000000 */ 	nop
/*  f15bd60:	0006000d */ 	break	0x6
.L0f15bd64:
/*  f15bd64:	00007012 */ 	mflo	$t6
/*  f15bd68:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f15bd6c:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f15bd70:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f15bd74:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15bd78:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15bd7c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15bd80:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f15bd84:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15bd88:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f15bd8c:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f15bd90:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f15bd94:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f15bd98:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f15bd9c:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f15bda0:	c466fff8 */ 	lwc1	$f6,-0x8($v1)
/*  f15bda4:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f15bda8:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f15bdac:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f15bdb0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f15bdb4:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f15bdb8:	e7b200fc */ 	swc1	$f18,0xfc($sp)
/*  f15bdbc:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f15bdc0:	c46afff8 */ 	lwc1	$f10,-0x8($v1)
/*  f15bdc4:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f15bdc8:	c464fffc */ 	lwc1	$f4,-0x4($v1)
/*  f15bdcc:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f15bdd0:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f15bdd4:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15bdd8:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15bddc:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15bde0:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15bde4:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bde8:	0085082a */ 	slt	$at,$a0,$a1
/*  f15bdec:	5420ffce */ 	bnezl	$at,.L0f15bd28
/*  f15bdf0:	26c40001 */ 	addiu	$a0,$s6,0x1
/*  f15bdf4:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bdf8:
/*  f15bdf8:	c7a000f8 */ 	lwc1	$f0,0xf8($sp)
/*  f15bdfc:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*  f15be00:	c7ae0100 */ 	lwc1	$f14,0x100($sp)
/*  f15be04:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f15be08:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f15be0c:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15be10:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15be14:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f15be18:	0c012974 */ 	jal	sqrtf
/*  f15be1c:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f15be20:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f15be24:	46000087 */ 	neg.s	$f2,$f0
/*  f15be28:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15be2c:	46029183 */ 	div.s	$f6,$f18,$f2
/*  f15be30:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15be34:	3c017f1b */ 	lui	$at,0x7f1b
/*  f15be38:	44808000 */ 	mtc1	$zero,$f16
/*  f15be3c:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f15be40:	02201825 */ 	or	$v1,$s1,$zero
/*  f15be44:	3c18800a */ 	lui	$t8,%hi(var800a4ccc)
/*  f15be48:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f15be4c:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f15be50:	c426745c */ 	lwc1	$f6,0x745c($at)
/*  f15be54:	3c017f1b */ 	lui	$at,0x7f1b
/*  f15be58:	c42a7460 */ 	lwc1	$f10,0x7460($at)
/*  f15be5c:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f15be60:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f15be64:	46022483 */ 	div.s	$f18,$f4,$f2
/*  f15be68:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f15be6c:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15be70:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f15be74:	19e00020 */ 	blez	$t7,.L0f15bef8
/*  f15be78:	00000000 */ 	nop
/*  f15be7c:	c4680004 */ 	lwc1	$f8,0x4($v1)
.L0f15be80:
/*  f15be80:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f15be84:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f15be88:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15be8c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f15be90:	00000000 */ 	nop
/*  f15be94:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15be98:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15be9c:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f15bea0:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f15bea4:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f15bea8:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15beac:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f15beb0:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15beb4:	00000000 */ 	nop
/*  f15beb8:	45000002 */ 	bc1f	.L0f15bec4
/*  f15bebc:	00000000 */ 	nop
/*  f15bec0:	e7a00104 */ 	swc1	$f0,0x104($sp)
.L0f15bec4:
/*  f15bec4:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15bec8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15becc:	00000000 */ 	nop
/*  f15bed0:	45020003 */ 	bc1fl	.L0f15bee0
/*  f15bed4:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f15bed8:	e7a00108 */ 	swc1	$f0,0x108($sp)
/*  f15bedc:	92390000 */ 	lbu	$t9,0x0($s1)
.L0f15bee0:
/*  f15bee0:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bee4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15bee8:	02d9082a */ 	slt	$at,$s6,$t9
/*  f15beec:	5420ffe4 */ 	bnezl	$at,.L0f15be80
/*  f15bef0:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f15bef4:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bef8:
/*  f15bef8:	8f184ccc */ 	lw	$t8,%lo(var800a4ccc)($t8)
/*  f15befc:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15bf00:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bf04:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f15bf08:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f15bf0c:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f15bf10:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f15bf14:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15bf18:	e4520004 */ 	swc1	$f18,0x4($v0)
/*  f15bf1c:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15bf20:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f15bf24:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15bf28:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f15bf2c:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15bf30:	169eff72 */ 	bne	$s4,$s8,.L0f15bcfc
/*  f15bf34:	e4460010 */ 	swc1	$f6,0x10($v0)
/*  f15bf38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bf3c:
/*  f15bf3c:	0fc2d96a */ 	jal	portal0f0b65a8
/*  f15bf40:	03c02025 */ 	or	$a0,$s8,$zero
/*  f15bf44:	3c1e800a */ 	lui	$s8,%hi(g_BgCommands)
/*  f15bf48:	27de4cd4 */ 	addiu	$s8,$s8,%lo(g_BgCommands)
/*  f15bf4c:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f15bf50:	1060001c */ 	beqz	$v1,.L0f15bfc4
/*  f15bf54:	00000000 */ 	nop
/*  f15bf58:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f15bf5c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bf60:	00608025 */ 	or	$s0,$v1,$zero
/*  f15bf64:	11c00017 */ 	beqz	$t6,.L0f15bfc4
/*  f15bf68:	31c200ff */ 	andi	$v0,$t6,0xff
/*  f15bf6c:	3c13800a */ 	lui	$s3,%hi(g_BgPrimaryData)
/*  f15bf70:	2673491c */ 	addiu	$s3,$s3,%lo(g_BgPrimaryData)
/*  f15bf74:	3c14f100 */ 	lui	$s4,0xf100
/*  f15bf78:	24110064 */ 	addiu	$s1,$zero,0x64
.L0f15bf7c:
/*  f15bf7c:	5622000c */ 	bnel	$s1,$v0,.L0f15bfb0
/*  f15bf80:	92020008 */ 	lbu	$v0,0x8($s0)
/*  f15bf84:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f15bf88:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15bf8c:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f15bf90:	0fc5758b */ 	jal	portalFindNumByVertices
/*  f15bf94:	03142021 */ 	addu	$a0,$t8,$s4
/*  f15bf98:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f15bf9c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15bfa0:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f15bfa4:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f15bfa8:	03328021 */ 	addu	$s0,$t9,$s2
/*  f15bfac:	92020008 */ 	lbu	$v0,0x8($s0)
.L0f15bfb0:
/*  f15bfb0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15bfb4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15bfb8:	1440fff0 */ 	bnez	$v0,.L0f15bf7c
/*  f15bfbc:	00000000 */ 	nop
/*  f15bfc0:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bfc4:
/*  f15bfc4:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15bfc8:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15bfcc:	8e7802bc */ 	lw	$t8,0x2bc($s3)
/*  f15bfd0:	1b000021 */ 	blez	$t8,.L0f15c058
/*  f15bfd4:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bfd8:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f15bfdc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15bfe0:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15bfe4:
/*  f15bfe4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bfe8:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15bfec:	a5e00000 */ 	sh	$zero,0x0($t7)
/*  f15bff0:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15bff4:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15bff8:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f15bffc:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c000:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c004:	a1e20007 */ 	sb	$v0,0x7($t7)
/*  f15c008:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c00c:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c010:	a7000002 */ 	sh	$zero,0x2($t8)
/*  f15c014:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c018:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c01c:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f15c020:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c024:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c028:	af030080 */ 	sw	$v1,0x80($t8)
/*  f15c02c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c030:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c034:	ade00084 */ 	sw	$zero,0x84($t7)
/*  f15c038:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c03c:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c040:	af000088 */ 	sw	$zero,0x88($t8)
/*  f15c044:	8e6e02bc */ 	lw	$t6,0x2bc($s3)
/*  f15c048:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15c04c:	028e082a */ 	slt	$at,$s4,$t6
/*  f15c050:	5420ffe4 */ 	bnezl	$at,.L0f15bfe4
/*  f15c054:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15c058:
/*  f15c058:	0fc04fb8 */ 	jal	roomsReset
/*  f15c05c:	00000000 */ 	nop
/*  f15c060:	44808000 */ 	mtc1	$zero,$f16
/*  f15c064:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c068:	e5f00018 */ 	swc1	$f16,0x18($t7)
/*  f15c06c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c070:	e730001c */ 	swc1	$f16,0x1c($t9)
/*  f15c074:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c078:	e7100020 */ 	swc1	$f16,0x20($t8)
/*  f15c07c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c080:	e5d00024 */ 	swc1	$f16,0x24($t6)
/*  f15c084:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c088:	e5f00028 */ 	swc1	$f16,0x28($t7)
/*  f15c08c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c090:	0fc4f071 */ 	jal	dyntexReset
/*  f15c094:	e730002c */ 	swc1	$f16,0x2c($t9)
/*  f15c098:	03a08025 */ 	or	$s0,$sp,$zero
/*  f15c09c:	261000b3 */ 	addiu	$s0,$s0,0xb3
/*  f15c0a0:	3c12800a */ 	lui	$s2,%hi(g_BgSection3)
/*  f15c0a4:	3618000f */ 	ori	$t8,$s0,0xf
/*  f15c0a8:	26524924 */ 	addiu	$s2,$s2,%lo(g_BgSection3)
/*  f15c0ac:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15c0b0:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c0b4:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c0b8:	0fc56be5 */ 	jal	bgLoadFile
/*  f15c0bc:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f15c0c0:	96020000 */ 	lhu	$v0,0x0($s0)
/*  f15c0c4:	96110002 */ 	lhu	$s1,0x2($s0)
/*  f15c0c8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c0cc:	304f7fff */ 	andi	$t7,$v0,0x7fff
/*  f15c0d0:	25e2ffff */ 	addiu	$v0,$t7,-1
/*  f15c0d4:	3459000f */ 	ori	$t9,$v0,0xf
/*  f15c0d8:	03201025 */ 	or	$v0,$t9,$zero
/*  f15c0dc:	0c0048f2 */ 	jal	mempAlloc
/*  f15c0e0:	24441001 */ 	addiu	$a0,$v0,0x1001
/*  f15c0e4:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c0e8:	2626ffff */ 	addiu	$a2,$s1,-1
/*  f15c0ec:	24441000 */ 	addiu	$a0,$v0,0x1000
/*  f15c0f0:	34d8000f */ 	ori	$t8,$a2,0xf
/*  f15c0f4:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f15c0f8:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c0fc:	27060001 */ 	addiu	$a2,$t8,0x1
/*  f15c100:	0fc56be5 */ 	jal	bgLoadFile
/*  f15c104:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f15c108:	02002025 */ 	or	$a0,$s0,$zero
/*  f15c10c:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f15c110:	0fc575d9 */ 	jal	bgInflate
/*  f15c114:	02203025 */ 	or	$a2,$s1,$zero
/*  f15c118:	8e6302bc */ 	lw	$v1,0x2bc($s3)
/*  f15c11c:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f15c120:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c124:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c128:	1420007a */ 	bnez	$at,.L0f15c314
/*  f15c12c:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c130:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c134:	3c13800a */ 	lui	$s3,%hi(g_BgRooms)
/*  f15c138:	44818000 */ 	mtc1	$at,$f16
/*  f15c13c:	26734cc4 */ 	addiu	$s3,$s3,%lo(g_BgRooms)
/*  f15c140:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c144:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c148:	24120014 */ 	addiu	$s2,$zero,0x14
/*  f15c14c:	86190000 */ 	lh	$t9,0x0($s0)
.L0f15c150:
/*  f15c150:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c154:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c158:	44999000 */ 	mtc1	$t9,$f18
/*  f15c15c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c160:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f15c164:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c168:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c16c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15c170:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c174:	e5c80018 */ 	swc1	$f8,0x18($t6)
/*  f15c178:	8618fff6 */ 	lh	$t8,-0xa($s0)
/*  f15c17c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c180:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c184:	44989000 */ 	mtc1	$t8,$f18
/*  f15c188:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c18c:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f15c190:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c194:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c198:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c19c:	e5e4001c */ 	swc1	$f4,0x1c($t7)
/*  f15c1a0:	860efff8 */ 	lh	$t6,-0x8($s0)
/*  f15c1a4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15c1a8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c1ac:	448e9000 */ 	mtc1	$t6,$f18
/*  f15c1b0:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c1b4:	c708000c */ 	lwc1	$f8,0xc($t8)
/*  f15c1b8:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f15c1bc:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c1c0:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f15c1c4:	e72a0020 */ 	swc1	$f10,0x20($t9)
/*  f15c1c8:	860ffffa */ 	lh	$t7,-0x6($s0)
/*  f15c1cc:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15c1d0:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c1d4:	448f9000 */ 	mtc1	$t7,$f18
/*  f15c1d8:	03127021 */ 	addu	$t6,$t8,$s2
/*  f15c1dc:	c5c40004 */ 	lwc1	$f4,0x4($t6)
/*  f15c1e0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f15c1e4:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c1e8:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f15c1ec:	e7060024 */ 	swc1	$f6,0x24($t8)
/*  f15c1f0:	8619fffc */ 	lh	$t9,-0x4($s0)
/*  f15c1f4:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c1f8:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c1fc:	44999000 */ 	mtc1	$t9,$f18
/*  f15c200:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c204:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f15c208:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c20c:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c210:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c214:	e5c80028 */ 	swc1	$f8,0x28($t6)
/*  f15c218:	8618fffe */ 	lh	$t8,-0x2($s0)
/*  f15c21c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c220:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c224:	44989000 */ 	mtc1	$t8,$f18
/*  f15c228:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c22c:	c726000c */ 	lwc1	$f6,0xc($t9)
/*  f15c230:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c234:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c238:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c23c:	e5e4002c */ 	swc1	$f4,0x2c($t7)
/*  f15c240:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c244:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c248:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c24c:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*  f15c250:	46124180 */ 	add.s	$f6,$f8,$f18
/*  f15c254:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f15c258:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*  f15c25c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c260:	03111021 */ 	addu	$v0,$t8,$s1
/*  f15c264:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f15c268:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f15c26c:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15c270:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f15c274:	e4460034 */ 	swc1	$f6,0x34($v0)
/*  f15c278:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c27c:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f15c280:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c284:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f15c288:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c28c:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f15c290:	e4520038 */ 	swc1	$f18,0x38($v0)
/*  f15c294:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c298:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f15c29c:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f15c2a0:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c2a4:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f15c2a8:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c2ac:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f15c2b0:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f15c2b4:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f15c2b8:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f15c2bc:	46069381 */ 	sub.s	$f14,$f18,$f6
/*  f15c2c0:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15c2c4:	00000000 */ 	nop
/*  f15c2c8:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f15c2cc:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c2d0:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f15c2d4:	0c012974 */ 	jal	sqrtf
/*  f15c2d8:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f15c2dc:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c2e0:	44818000 */ 	mtc1	$at,$f16
/*  f15c2e4:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c2e8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c2ec:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f15c2f0:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c2f4:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c2f8:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f15c2fc:	e706003c */ 	swc1	$f6,0x3c($t8)
/*  f15c300:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c304:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c308:	5420ff91 */ 	bnezl	$at,.L0f15c150
/*  f15c30c:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15c310:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c314:
/*  f15c314:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c318:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c31c:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c320:	14200012 */ 	bnez	$at,.L0f15c36c
/*  f15c324:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c328:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c32c:	944e0000 */ 	lhu	$t6,0x0($v0)
.L0f15c330:
/*  f15c330:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c334:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15c338:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f15c33c:	25f9010f */ 	addiu	$t9,$t7,0x10f
/*  f15c340:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c344:	3738000f */ 	ori	$t8,$t9,0xf
/*  f15c348:	3b0e000f */ 	xori	$t6,$t8,0xf
/*  f15c34c:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c350:	af2e0080 */ 	sw	$t6,0x80($t9)
/*  f15c354:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c358:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c35c:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c360:	5420fff3 */ 	bnezl	$at,.L0f15c330
/*  f15c364:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c368:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c36c:
/*  f15c36c:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c370:	00002025 */ 	or	$a0,$zero,$zero
/*  f15c374:	1420001b */ 	bnez	$at,.L0f15c3e4
/*  f15c378:	00402825 */ 	or	$a1,$v0,$zero
/*  f15c37c:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c380:	3403ffff */ 	dli	$v1,0xffff
.L0f15c384:
/*  f15c384:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c388:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f15c38c:	01f17021 */ 	addu	$t6,$t7,$s1
/*  f15c390:	a1d80008 */ 	sb	$t8,0x8($t6)
/*  f15c394:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c398:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c39c:	804f0008 */ 	lb	$t7,0x8($v0)
/*  f15c3a0:	59e0000a */ 	blezl	$t7,.L0f15c3cc
/*  f15c3a4:	a443000a */ 	sh	$v1,0xa($v0)
/*  f15c3a8:	a444000a */ 	sh	$a0,0xa($v0)
/*  f15c3ac:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c3b0:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c3b4:	81d90008 */ 	lb	$t9,0x8($t6)
/*  f15c3b8:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15c3bc:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f15c3c0:	10000002 */ 	b	.L0f15c3cc
/*  f15c3c4:	000f2403 */ 	sra	$a0,$t7,0x10
/*  f15c3c8:	a443000a */ 	sh	$v1,0xa($v0)
.L0f15c3cc:
/*  f15c3cc:	8fce02bc */ 	lw	$t6,0x2bc($s8)
/*  f15c3d0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c3d4:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c3d8:	028e082b */ 	sltu	$at,$s4,$t6
/*  f15c3dc:	1420ffe9 */ 	bnez	$at,.L0f15c384
/*  f15c3e0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f15c3e4:
/*  f15c3e4:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f15c3e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f15c3ec:	0c00490c */ 	jal	mempRealloc
/*  f15c3f0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15c3f4:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c3f8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c3fc:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c400:	5420000a */ 	bnezl	$at,.L0f15c42c
/*  f15c404:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c408:
/*  f15c408:	0fc004f2 */ 	jal	roomInitLights
/*  f15c40c:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c410:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c414:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c418:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c41c:	1420fffa */ 	bnez	$at,.L0f15c408
/*  f15c420:	00000000 */ 	nop
/*  f15c424:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c428:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c42c:
/*  f15c42c:	1420000b */ 	bnez	$at,.L0f15c45c
/*  f15c430:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f15c434:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f15c438:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c43c:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c440:	258c008c */ 	addiu	$t4,$t4,0x8c
.L0f15c444:
/*  f15c444:	81990008 */ 	lb	$t9,0x8($t4)
/*  f15c448:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c44c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c450:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15c454:	1420fffb */ 	bnez	$at,.L0f15c444
/*  f15c458:	02d9b021 */ 	addu	$s6,$s6,$t9
.L0f15c45c:
/*  f15c45c:	12c0001c */ 	beqz	$s6,.L0f15c4d0
/*  f15c460:	3c03800a */ 	lui	$v1,%hi(var800a41a0)
/*  f15c464:	00162080 */ 	sll	$a0,$s6,0x2
/*  f15c468:	00962023 */ 	subu	$a0,$a0,$s6
/*  f15c46c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15c470:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15c474:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15c478:	0c0048f2 */ 	jal	mempAlloc
/*  f15c47c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c480:	3c03800a */ 	lui	$v1,%hi(var800a41a0)
/*  f15c484:	246341a0 */ 	addiu	$v1,$v1,%lo(var800a41a0)
/*  f15c488:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15c48c:	1ac00013 */ 	blez	$s6,.L0f15c4dc
/*  f15c490:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15c494:	00001025 */ 	or	$v0,$zero,$zero
.L0f15c498:
/*  f15c498:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c49c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c4a0:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c4a4:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f15c4a8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15c4ac:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f15c4b0:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f15c4b4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c4b8:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c4bc:	24420003 */ 	addiu	$v0,$v0,0x3
/*  f15c4c0:	1696fff5 */ 	bne	$s4,$s6,.L0f15c498
/*  f15c4c4:	a3200002 */ 	sb	$zero,0x2($t9)
/*  f15c4c8:	10000004 */ 	b	.L0f15c4dc
/*  f15c4cc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c4d0:
/*  f15c4d0:	246341a0 */ 	addiu	$v1,$v1,%lo(var800a41a0)
/*  f15c4d4:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f15c4d8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c4dc:
/*  f15c4dc:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15c4e0:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c4e4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15c4e8:	1300000a */ 	beqz	$t8,.L0f15c514
/*  f15c4ec:	00000000 */ 	nop
.L0f15c4f0:
/*  f15c4f0:	0fc5921d */ 	jal	func0f164ab8
/*  f15c4f4:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c4f8:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15c4fc:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c500:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c504:	01d2c821 */ 	addu	$t9,$t6,$s2
/*  f15c508:	972f0000 */ 	lhu	$t7,0x0($t9)
/*  f15c50c:	15e0fff8 */ 	bnez	$t7,.L0f15c4f0
/*  f15c510:	00000000 */ 	nop
.L0f15c514:
/*  f15c514:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f15c518:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f15c51c:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c520:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c524:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c528:	5420000a */ 	bnezl	$at,.L0f15c554
/*  f15c52c:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c530:
/*  f15c530:	0fc59288 */ 	jal	room0f164c64
/*  f15c534:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c538:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c53c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c540:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c544:	1420fffa */ 	bnez	$at,.L0f15c530
/*  f15c548:	00000000 */ 	nop
/*  f15c54c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c550:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c554:
/*  f15c554:	54200009 */ 	bnezl	$at,.L0f15c57c
/*  f15c558:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c55c:
/*  f15c55c:	0fc591a2 */ 	jal	bgExpandRoomToPortals
/*  f15c560:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c564:	8e1802bc */ 	lw	$t8,0x2bc($s0)
/*  f15c568:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c56c:	0298082a */ 	slt	$at,$s4,$t8
/*  f15c570:	1420fffa */ 	bnez	$at,.L0f15c55c
/*  f15c574:	00000000 */ 	nop
/*  f15c578:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c57c:
/*  f15c57c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c580:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f15c584:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c588:	11c0000a */ 	beqz	$t6,.L0f15c5b4
/*  f15c58c:	00000000 */ 	nop
/*  f15c590:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c594:
/*  f15c594:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c598:	332f00fe */ 	andi	$t7,$t9,0xfe
/*  f15c59c:	a04f0006 */ 	sb	$t7,0x6($v0)
/*  f15c5a0:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f15c5a4:	03121021 */ 	addu	$v0,$t8,$s2
/*  f15c5a8:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c5ac:	55c0fff9 */ 	bnezl	$t6,.L0f15c594
/*  f15c5b0:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c5b4:
/*  f15c5b4:	0fc59729 */ 	jal	envSetStageNum
/*  f15c5b8:	8fa40148 */ 	lw	$a0,0x148($sp)
/*  f15c5bc:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f15c5c0:	3c018008 */ 	lui	$at,%hi(var8007fc10)
/*  f15c5c4:	0fc04d54 */ 	jal	wallhitReset
/*  f15c5c8:	a439fc10 */ 	sh	$t9,%lo(var8007fc10)($at)
/*  f15c5cc:	0fc00aa6 */ 	jal	func0f002a98
/*  f15c5d0:	00000000 */ 	nop
/*  f15c5d4:	0fc00703 */ 	jal	func0f001c0c
/*  f15c5d8:	00000000 */ 	nop
/*  f15c5dc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f15c5e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15c5e4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15c5e8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15c5ec:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f15c5f0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f15c5f4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f15c5f8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f15c5fc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f15c600:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f15c604:	03e00008 */ 	jr	$ra
/*  f15c608:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#else
GLOBAL_ASM(
glabel bgBuildTables
.late_rodata
glabel var7f1b75cc
.word 0x7f7fffff
glabel var7f1b75d0
.word 0xff7fffff
.text
/*  f156060:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f156064:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f156068:	3c13800a */ 	lui	$s3,0x800a
/*  f15606c:	2673e6c0 */ 	addiu	$s3,$s3,-6464
/*  f156070:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f156074:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f156078:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f15607c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f156080:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f156084:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f156088:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15608c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f156090:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f156094:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f156098:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15609c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1560a0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1560a4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1560a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1560ac:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1560b0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1560b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1560b8:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f1560bc:	0c004a0e */ 	jal	mempAlloc
/*  f1560c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1560c4:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f1560c8:	3c15800b */ 	lui	$s5,0x800b
/*  f1560cc:	26b590a8 */ 	addiu	$s5,$s5,-28504
/*  f1560d0:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f1560d4:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f1560d8:	348e000f */ 	ori	$t6,$a0,0xf
/*  f1560dc:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f1560e0:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f1560e4:	0c004a0e */ 	jal	mempAlloc
/*  f1560e8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1560ec:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f1560f0:	3c03800b */ 	lui	$v1,0x800b
/*  f1560f4:	24639468 */ 	addiu	$v1,$v1,-27544
/*  f1560f8:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f1560fc:	1a200010 */ 	blez	$s1,.NB0f156140
/*  f156100:	0000a025 */ 	or	$s4,$zero,$zero
/*  f156104:	00001025 */ 	or	$v0,$zero,$zero
/*  f156108:	3416ffff */ 	dli	$s6,0xffff
/*  f15610c:	8c780000 */ 	lw	$t8,0x0($v1)
.NB0f156110:
/*  f156110:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156114:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f156118:	a7360000 */ 	sh	$s6,0x0($t9)
/*  f15611c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f156120:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f156124:	a5e00002 */ 	sh	$zero,0x2($t7)
/*  f156128:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15612c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f156130:	0291082a */ 	slt	$at,$s4,$s1
/*  f156134:	5420fff6 */ 	bnezl	$at,.NB0f156110
/*  f156138:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f15613c:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156140:
/*  f156140:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f156144:	13000013 */ 	beqz	$t8,.NB0f156194
/*  f156148:	2624000f */ 	addiu	$a0,$s1,0xf
/*  f15614c:	3499000f */ 	ori	$t9,$a0,0xf
/*  f156150:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f156154:	0c004a0e */ 	jal	mempAlloc
/*  f156158:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15615c:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f156160:	3c03800b */ 	lui	$v1,0x800b
/*  f156164:	246390ac */ 	addiu	$v1,$v1,-28500
/*  f156168:	1a20000a */ 	blez	$s1,.NB0f156194
/*  f15616c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f156170:	8c6f0000 */ 	lw	$t7,0x0($v1)
.NB0f156174:
/*  f156174:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f156178:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f15617c:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f156180:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156184:	0291082a */ 	slt	$at,$s4,$s1
/*  f156188:	5420fffa */ 	bnezl	$at,.NB0f156174
/*  f15618c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f156190:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156194:
/*  f156194:	1a200020 */ 	blez	$s1,.NB0f156218
/*  f156198:	00009025 */ 	or	$s2,$zero,$zero
/*  f15619c:	8eb90000 */ 	lw	$t9,0x0($s5)
.NB0f1561a0:
/*  f1561a0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1561a4:	03327021 */ 	addu	$t6,$t9,$s2
/*  f1561a8:	adc00044 */ 	sw	$zero,0x44($t6)
/*  f1561ac:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f1561b0:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f1561b4:	a3000008 */ 	sb	$zero,0x8($t8)
/*  f1561b8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f1561bc:	03327021 */ 	addu	$t6,$t9,$s2
/*  f1561c0:	a5c0000a */ 	sh	$zero,0xa($t6)
/*  f1561c4:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f1561c8:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f1561cc:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f1561d0:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f1561d4:	03327021 */ 	addu	$t6,$t9,$s2
/*  f1561d8:	a1c0004d */ 	sb	$zero,0x4d($t6)
/*  f1561dc:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f1561e0:	01f26021 */ 	addu	$t4,$t7,$s2
/*  f1561e4:	9198004e */ 	lbu	$t8,0x4e($t4)
/*  f1561e8:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f1561ec:	a199004e */ 	sb	$t9,0x4e($t4)
/*  f1561f0:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f1561f4:	01d26021 */ 	addu	$t4,$t6,$s2
/*  f1561f8:	918f004e */ 	lbu	$t7,0x4e($t4)
/*  f1561fc:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f156200:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f156204:	a198004e */ 	sb	$t8,0x4e($t4)
/*  f156208:	8e7902bc */ 	lw	$t9,0x2bc($s3)
/*  f15620c:	0299082a */ 	slt	$at,$s4,$t9
/*  f156210:	5420ffe3 */ 	bnezl	$at,.NB0f1561a0
/*  f156214:	8eb90000 */ 	lw	$t9,0x0($s5)
.NB0f156218:
/*  f156218:	3c118008 */ 	lui	$s1,0x8008
/*  f15621c:	26312460 */ 	addiu	$s1,$s1,0x2460
/*  f156220:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f156224:	24120038 */ 	addiu	$s2,$zero,0x38
/*  f156228:	3c108008 */ 	lui	$s0,0x8008
/*  f15622c:	01d20019 */ 	multu	$t6,$s2
/*  f156230:	26102520 */ 	addiu	$s0,$s0,0x2520
/*  f156234:	00007812 */ 	mflo	$t7
/*  f156238:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f15623c:	0fc55bf6 */ 	jal	func0f15c880
/*  f156240:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f156244:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f156248:	03320019 */ 	multu	$t9,$s2
/*  f15624c:	00007012 */ 	mflo	$t6
/*  f156250:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f156254:	0fc09fa6 */ 	jal	chr0f028490
/*  f156258:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f15625c:	3c188008 */ 	lui	$t8,0x8008
/*  f156260:	8f182460 */ 	lw	$t8,0x2460($t8)
/*  f156264:	3c018008 */ 	lui	$at,0x8008
/*  f156268:	3c02800a */ 	lui	$v0,0x800a
/*  f15626c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f156270:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f156274:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f156278:	00390821 */ 	addu	$at,$at,$t9
/*  f15627c:	3c03800a */ 	lui	$v1,0x800a
/*  f156280:	2463e8c0 */ 	addiu	$v1,$v1,-5952
/*  f156284:	c4202538 */ 	lwc1	$f0,0x2538($at)
/*  f156288:	2442e6c0 */ 	addiu	$v0,$v0,-6464
.NB0f15628c:
/*  f15628c:	24420080 */ 	addiu	$v0,$v0,0x80
/*  f156290:	0043082b */ 	sltu	$at,$v0,$v1
/*  f156294:	1420fffd */ 	bnez	$at,.NB0f15628c
/*  f156298:	e4400068 */ 	swc1	$f0,0x68($v0)
/*  f15629c:	3c013f80 */ 	lui	$at,0x3f80
/*  f1562a0:	44816000 */ 	mtc1	$at,$f12
/*  f1562a4:	0c005db6 */ 	jal	mtx00016748
/*  f1562a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1562ac:	3c0e800b */ 	lui	$t6,0x800b
/*  f1562b0:	8dce90a0 */ 	lw	$t6,-0x6f60($t6)
/*  f1562b4:	3c17800b */ 	lui	$s7,0x800b
/*  f1562b8:	26f79448 */ 	addiu	$s7,$s7,-27576
/*  f1562bc:	15c00322 */ 	bnez	$t6,.NB0f156f48
/*  f1562c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1562c4:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f1562c8:	0000f025 */ 	or	$s8,$zero,$zero
/*  f1562cc:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f1562d0:	11e00006 */ 	beqz	$t7,.NB0f1562ec
/*  f1562d4:	02001025 */ 	or	$v0,$s0,$zero
/*  f1562d8:	94580008 */ 	lhu	$t8,0x8($v0)
.NB0f1562dc:
/*  f1562dc:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f1562e0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f1562e4:	5700fffd */ 	bnezl	$t8,.NB0f1562dc
/*  f1562e8:	94580008 */ 	lhu	$t8,0x8($v0)
.NB0f1562ec:
/*  f1562ec:	001ec900 */ 	sll	$t9,$s8,0x4
/*  f1562f0:	3c028008 */ 	lui	$v0,0x8008
/*  f1562f4:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f1562f8:	244224a4 */ 	addiu	$v0,$v0,0x24a4
/*  f1562fc:	348e000f */ 	ori	$t6,$a0,0xf
/*  f156300:	ac5e0000 */ 	sw	$s8,0x0($v0)
/*  f156304:	0c004a0e */ 	jal	mempAlloc
/*  f156308:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15630c:	3c01800b */ 	lui	$at,0x800b
/*  f156310:	ac22946c */ 	sw	$v0,-0x6b94($at)
/*  f156314:	001e20c0 */ 	sll	$a0,$s8,0x3
/*  f156318:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15631c:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f156320:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156324:	0000b025 */ 	or	$s6,$zero,$zero
/*  f156328:	2412000c */ 	addiu	$s2,$zero,0xc
.NB0f15632c:
/*  f15632c:	1bc0000b */ 	blez	$s8,.NB0f15635c
/*  f156330:	00001825 */ 	or	$v1,$zero,$zero
.NB0f156334:
/*  f156334:	02031021 */ 	addu	$v0,$s0,$v1
/*  f156338:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f15633c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f156340:	16980003 */ 	bne	$s4,$t8,.NB0f156350
/*  f156344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156348:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f15634c:	8ef00000 */ 	lw	$s0,0x0($s7)
.NB0f156350:
/*  f156350:	16defff8 */ 	bne	$s6,$s8,.NB0f156334
/*  f156354:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f156358:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f15635c:
/*  f15635c:	02048821 */ 	addu	$s1,$s0,$a0
/*  f156360:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f156364:	18a00007 */ 	blez	$a1,.NB0f156384
/*  f156368:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15636c:	00b20019 */ 	multu	$a1,$s2
/*  f156370:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156374:	0000c812 */ 	mflo	$t9
/*  f156378:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15637c:	1000ffeb */ 	beqz	$zero,.NB0f15632c
/*  f156380:	24840004 */ 	addiu	$a0,$a0,0x4
.NB0f156384:
/*  f156384:	17c00003 */ 	bnez	$s8,.NB0f156394
/*  f156388:	00008025 */ 	or	$s0,$zero,$zero
/*  f15638c:	10000002 */ 	beqz	$zero,.NB0f156398
/*  f156390:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f156394:
/*  f156394:	03c01025 */ 	or	$v0,$s8,$zero
.NB0f156398:
/*  f156398:	00022080 */ 	sll	$a0,$v0,0x2
/*  f15639c:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f1563a0:	348e000f */ 	ori	$t6,$a0,0xf
/*  f1563a4:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f1563a8:	0c004a0e */ 	jal	mempAlloc
/*  f1563ac:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1563b0:	3c05800a */ 	lui	$a1,0x800a
/*  f1563b4:	24a5e6c0 */ 	addiu	$a1,$a1,-6464
/*  f1563b8:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f1563bc:	3c13800b */ 	lui	$s3,0x800b
/*  f1563c0:	26739460 */ 	addiu	$s3,$s3,-27552
/*  f1563c4:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f1563c8:	aca0002c */ 	sw	$zero,0x2c($a1)
/*  f1563cc:	1a200033 */ 	blez	$s1,.NB0f15649c
/*  f1563d0:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1563d4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1563d8:	8eb80000 */ 	lw	$t8,0x0($s5)
.NB0f1563dc:
/*  f1563dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1563e0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1563e4:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f1563e8:	1bc0001d */ 	blez	$s8,.NB0f156460
/*  f1563ec:	a730000e */ 	sh	$s0,0xe($t9)
.NB0f1563f0:
/*  f1563f0:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f1563f4:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f1563f8:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f1563fc:	568f000a */ 	bnel	$s4,$t7,.NB0f156428
/*  f156400:	84580004 */ 	lh	$t8,0x4($v0)
/*  f156404:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f156408:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f15640c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f156410:	03197021 */ 	addu	$t6,$t8,$t9
/*  f156414:	a5d60000 */ 	sh	$s6,0x0($t6)
/*  f156418:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15641c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f156420:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f156424:	84580004 */ 	lh	$t8,0x4($v0)
.NB0f156428:
/*  f156428:	00107040 */ 	sll	$t6,$s0,0x1
/*  f15642c:	56980007 */ 	bnel	$s4,$t8,.NB0f15644c
/*  f156430:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f156434:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f156438:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15643c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f156440:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f156444:	a5f60000 */ 	sh	$s6,0x0($t7)
/*  f156448:	26d60001 */ 	addiu	$s6,$s6,0x1
.NB0f15644c:
/*  f15644c:	16deffe8 */ 	bne	$s6,$s8,.NB0f1563f0
/*  f156450:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f156454:	3c05800a */ 	lui	$a1,0x800a
/*  f156458:	24a5e6c0 */ 	addiu	$a1,$a1,-6464
/*  f15645c:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f156460:
/*  f156460:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156464:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f156468:	a3240005 */ 	sb	$a0,0x5($t9)
/*  f15646c:	8cae002c */ 	lw	$t6,0x2c($a1)
/*  f156470:	01c4082a */ 	slt	$at,$t6,$a0
/*  f156474:	50200003 */ 	beqzl	$at,.NB0f156484
/*  f156478:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15647c:	aca4002c */ 	sw	$a0,0x2c($a1)
/*  f156480:	8cb102bc */ 	lw	$s1,0x2bc($a1)
.NB0f156484:
/*  f156484:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156488:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15648c:	0291082a */ 	slt	$at,$s4,$s1
/*  f156490:	5420ffd2 */ 	bnezl	$at,.NB0f1563dc
/*  f156494:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156498:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f15649c:
/*  f15649c:	1a200058 */ 	blez	$s1,.NB0f156600
/*  f1564a0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1564a4:	8eac0000 */ 	lw	$t4,0x0($s5)
.NB0f1564a8:
/*  f1564a8:	818b0005 */ 	lb	$t3,0x5($t4)
/*  f1564ac:	5960004f */ 	blezl	$t3,.NB0f1565ec
/*  f1564b0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1564b4:	8598000e */ 	lh	$t8,0xe($t4)
/*  f1564b8:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f1564bc:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f1564c0:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f1564c4:	01f96821 */ 	addu	$t5,$t7,$t9
/*  f1564c8:	01a0f825 */ 	or	$ra,$t5,$zero
/*  f1564cc:	00008825 */ 	or	$s1,$zero,$zero
.NB0f1564d0:
/*  f1564d0:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f1564d4:	02cb082a */ 	slt	$at,$s6,$t3
/*  f1564d8:	000a70c0 */ 	sll	$t6,$t2,0x3
/*  f1564dc:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f1564e0:	84640002 */ 	lh	$a0,0x2($v1)
/*  f1564e4:	16840003 */ 	bne	$s4,$a0,.NB0f1564f4
/*  f1564e8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1564ec:	10000001 */ 	beqz	$zero,.NB0f1564f4
/*  f1564f0:	84670004 */ 	lh	$a3,0x4($v1)
.NB0f1564f4:
/*  f1564f4:	10200034 */ 	beqz	$at,.NB0f1565c8
/*  f1564f8:	02c04025 */ 	or	$t0,$s6,$zero
/*  f1564fc:	00084840 */ 	sll	$t1,$t0,0x1
.NB0f156500:
/*  f156500:	01a92821 */ 	addu	$a1,$t5,$t1
/*  f156504:	84a60000 */ 	lh	$a2,0x0($a1)
/*  f156508:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15650c:	00002025 */ 	or	$a0,$zero,$zero
/*  f156510:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f156514:	02181021 */ 	addu	$v0,$s0,$t8
/*  f156518:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15651c:	16830007 */ 	bne	$s4,$v1,.NB0f15653c
/*  f156520:	0067082a */ 	slt	$at,$v1,$a3
/*  f156524:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f156528:	01e7082a */ 	slt	$at,$t7,$a3
/*  f15652c:	10200006 */ 	beqz	$at,.NB0f156548
/*  f156530:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156534:	10000004 */ 	beqz	$zero,.NB0f156548
/*  f156538:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f15653c:
/*  f15653c:	10200002 */ 	beqz	$at,.NB0f156548
/*  f156540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156544:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f156548:
/*  f156548:	5080001d */ 	beqzl	$a0,.NB0f1565c0
/*  f15654c:	010b082a */ 	slt	$at,$t0,$t3
/*  f156550:	a4aa0000 */ 	sh	$t2,0x0($a1)
/*  f156554:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156558:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15655c:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f156560:	870f000e */ 	lh	$t7,0xe($t8)
/*  f156564:	000f7040 */ 	sll	$t6,$t7,0x1
/*  f156568:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f15656c:	03117821 */ 	addu	$t7,$t8,$s1
/*  f156570:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f156574:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156578:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15657c:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f156580:	03326021 */ 	addu	$t4,$t9,$s2
/*  f156584:	8598000e */ 	lh	$t8,0xe($t4)
/*  f156588:	00187840 */ 	sll	$t7,$t8,0x1
/*  f15658c:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f156590:	01b1f821 */ 	addu	$ra,$t5,$s1
/*  f156594:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f156598:	000ac8c0 */ 	sll	$t9,$t2,0x3
/*  f15659c:	02191821 */ 	addu	$v1,$s0,$t9
/*  f1565a0:	84640002 */ 	lh	$a0,0x2($v1)
/*  f1565a4:	16840004 */ 	bne	$s4,$a0,.NB0f1565b8
/*  f1565a8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1565ac:	84670004 */ 	lh	$a3,0x4($v1)
/*  f1565b0:	10000002 */ 	beqz	$zero,.NB0f1565bc
/*  f1565b4:	818b0005 */ 	lb	$t3,0x5($t4)
.NB0f1565b8:
/*  f1565b8:	818b0005 */ 	lb	$t3,0x5($t4)
.NB0f1565bc:
/*  f1565bc:	010b082a */ 	slt	$at,$t0,$t3
.NB0f1565c0:
/*  f1565c0:	1420ffcf */ 	bnez	$at,.NB0f156500
/*  f1565c4:	25290002 */ 	addiu	$t1,$t1,0x2
.NB0f1565c8:
/*  f1565c8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f1565cc:	02cb082a */ 	slt	$at,$s6,$t3
/*  f1565d0:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f1565d4:	1420ffbe */ 	bnez	$at,.NB0f1564d0
/*  f1565d8:	27ff0002 */ 	addiu	$ra,$ra,0x2
/*  f1565dc:	3c11800a */ 	lui	$s1,0x800a
/*  f1565e0:	8e31e97c */ 	lw	$s1,-0x1684($s1)
/*  f1565e4:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1565e8:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f1565ec:
/*  f1565ec:	0291082a */ 	slt	$at,$s4,$s1
/*  f1565f0:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f1565f4:	1420ffac */ 	bnez	$at,.NB0f1564a8
/*  f1565f8:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f1565fc:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156600:
/*  f156600:	17c00003 */ 	bnez	$s8,.NB0f156610
/*  f156604:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f156608:	10000002 */ 	beqz	$zero,.NB0f156614
/*  f15660c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f156610:
/*  f156610:	03c01025 */ 	or	$v0,$s8,$zero
.NB0f156614:
/*  f156614:	2444000f */ 	addiu	$a0,$v0,0xf
/*  f156618:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15661c:	0c004a0e */ 	jal	mempAlloc
/*  f156620:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f156624:	3c10800b */ 	lui	$s0,0x800b
/*  f156628:	26109450 */ 	addiu	$s0,$s0,-27568
/*  f15662c:	1bc00009 */ 	blez	$s8,.NB0f156654
/*  f156630:	ae020000 */ 	sw	$v0,0x0($s0)
.NB0f156634:
/*  f156634:	0fc556ca */ 	jal	func0f15b4c0
/*  f156638:	02802025 */ 	or	$a0,$s4,$zero
/*  f15663c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f156640:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f156644:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156648:	169efffa */ 	bne	$s4,$s8,.NB0f156634
/*  f15664c:	a3220000 */ 	sb	$v0,0x0($t9)
/*  f156650:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156654:
/*  f156654:	001e2080 */ 	sll	$a0,$s8,0x2
/*  f156658:	009e2021 */ 	addu	$a0,$a0,$s8
/*  f15665c:	00042080 */ 	sll	$a0,$a0,0x2
/*  f156660:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f156664:	3498000f */ 	ori	$t8,$a0,0xf
/*  f156668:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15666c:	0c004a0e */ 	jal	mempAlloc
/*  f156670:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f156674:	3c01800b */ 	lui	$at,0x800b
/*  f156678:	1bc00095 */ 	blez	$s8,.NB0f1568d0
/*  f15667c:	ac22944c */ 	sw	$v0,-0x6bb4($at)
/*  f156680:	44808000 */ 	mtc1	$zero,$f16
/*  f156684:	00009025 */ 	or	$s2,$zero,$zero
/*  f156688:	00003025 */ 	or	$a2,$zero,$zero
/*  f15668c:	2413000c */ 	addiu	$s3,$zero,0xc
.NB0f156690:
/*  f156690:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f156694:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f156698:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f15669c:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f1566a0:	02127821 */ 	addu	$t7,$s0,$s2
/*  f1566a4:	95f90000 */ 	lhu	$t9,0x0($t7)
/*  f1566a8:	03308821 */ 	addu	$s1,$t9,$s0
/*  f1566ac:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f1566b0:	02201825 */ 	or	$v1,$s1,$zero
/*  f1566b4:	18a00035 */ 	blez	$a1,.NB0f15678c
/*  f1566b8:	26c40001 */ 	addiu	$a0,$s6,0x1
.NB0f1566bc:
/*  f1566bc:	0085001a */ 	div	$zero,$a0,$a1
/*  f1566c0:	0000c010 */ 	mfhi	$t8
/*  f1566c4:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f1566c8:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f1566cc:	03130019 */ 	multu	$t8,$s3
/*  f1566d0:	0080b025 */ 	or	$s6,$a0,$zero
/*  f1566d4:	14a00002 */ 	bnez	$a1,.NB0f1566e0
/*  f1566d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1566dc:	0007000d */ 	break	0x7
.NB0f1566e0:
/*  f1566e0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1566e4:	14a10004 */ 	bne	$a1,$at,.NB0f1566f8
/*  f1566e8:	3c018000 */ 	lui	$at,0x8000
/*  f1566ec:	14810002 */ 	bne	$a0,$at,.NB0f1566f8
/*  f1566f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1566f4:	0006000d */ 	break	0x6
.NB0f1566f8:
/*  f1566f8:	00007012 */ 	mflo	$t6
/*  f1566fc:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f156700:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f156704:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f156708:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15670c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f156710:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f156714:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f156718:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15671c:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f156720:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f156724:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f156728:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f15672c:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f156730:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f156734:	c466fff8 */ 	lwc1	$f6,-0x8($v1)
/*  f156738:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f15673c:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f156740:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f156744:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f156748:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f15674c:	e7b200fc */ 	swc1	$f18,0xfc($sp)
/*  f156750:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f156754:	c46afff8 */ 	lwc1	$f10,-0x8($v1)
/*  f156758:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f15675c:	c464fffc */ 	lwc1	$f4,-0x4($v1)
/*  f156760:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f156764:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f156768:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15676c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f156770:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f156774:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f156778:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15677c:	0085082a */ 	slt	$at,$a0,$a1
/*  f156780:	5420ffce */ 	bnezl	$at,.NB0f1566bc
/*  f156784:	26c40001 */ 	addiu	$a0,$s6,0x1
/*  f156788:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f15678c:
/*  f15678c:	c7a000f8 */ 	lwc1	$f0,0xf8($sp)
/*  f156790:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*  f156794:	c7ae0100 */ 	lwc1	$f14,0x100($sp)
/*  f156798:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f15679c:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f1567a0:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f1567a4:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f1567a8:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f1567ac:	0c012e84 */ 	jal	sqrtf
/*  f1567b0:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f1567b4:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f1567b8:	46000087 */ 	neg.s	$f2,$f0
/*  f1567bc:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f1567c0:	46029183 */ 	div.s	$f6,$f18,$f2
/*  f1567c4:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f1567c8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1567cc:	44808000 */ 	mtc1	$zero,$f16
/*  f1567d0:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f1567d4:	02201825 */ 	or	$v1,$s1,$zero
/*  f1567d8:	3c18800b */ 	lui	$t8,0x800b
/*  f1567dc:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f1567e0:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f1567e4:	c4261c14 */ 	lwc1	$f6,0x1c14($at)
/*  f1567e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1567ec:	c42a1c18 */ 	lwc1	$f10,0x1c18($at)
/*  f1567f0:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f1567f4:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f1567f8:	46022483 */ 	div.s	$f18,$f4,$f2
/*  f1567fc:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f156800:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f156804:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f156808:	19e00020 */ 	blez	$t7,.NB0f15688c
/*  f15680c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156810:	c4680004 */ 	lwc1	$f8,0x4($v1)
.NB0f156814:
/*  f156814:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f156818:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f15681c:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f156820:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f156824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156828:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15682c:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f156830:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f156834:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f156838:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f15683c:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f156840:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f156844:	4608003c */ 	c.lt.s	$f0,$f8
/*  f156848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15684c:	45000002 */ 	bc1f	.NB0f156858
/*  f156850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156854:	e7a00104 */ 	swc1	$f0,0x104($sp)
.NB0f156858:
/*  f156858:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15685c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f156860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156864:	45020003 */ 	bc1fl	.NB0f156874
/*  f156868:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f15686c:	e7a00108 */ 	swc1	$f0,0x108($sp)
/*  f156870:	92390000 */ 	lbu	$t9,0x0($s1)
.NB0f156874:
/*  f156874:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f156878:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15687c:	02d9082a */ 	slt	$at,$s6,$t9
/*  f156880:	5420ffe4 */ 	bnezl	$at,.NB0f156814
/*  f156884:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f156888:	0000b025 */ 	or	$s6,$zero,$zero
.NB0f15688c:
/*  f15688c:	8f18944c */ 	lw	$t8,-0x6bb4($t8)
/*  f156890:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f156894:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156898:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f15689c:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f1568a0:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f1568a4:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f1568a8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1568ac:	e4520004 */ 	swc1	$f18,0x4($v0)
/*  f1568b0:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f1568b4:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f1568b8:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f1568bc:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f1568c0:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f1568c4:	169eff72 */ 	bne	$s4,$s8,.NB0f156690
/*  f1568c8:	e4460010 */ 	swc1	$f6,0x10($v0)
/*  f1568cc:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f1568d0:
/*  f1568d0:	0fc2d0c2 */ 	jal	portal0f0b65a8
/*  f1568d4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f1568d8:	3c1e800b */ 	lui	$s8,0x800b
/*  f1568dc:	27de9454 */ 	addiu	$s8,$s8,-27564
/*  f1568e0:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f1568e4:	1060001c */ 	beqz	$v1,.NB0f156958
/*  f1568e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1568ec:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f1568f0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1568f4:	00608025 */ 	or	$s0,$v1,$zero
/*  f1568f8:	11c00017 */ 	beqz	$t6,.NB0f156958
/*  f1568fc:	31c200ff */ 	andi	$v0,$t6,0xff
/*  f156900:	3c13800b */ 	lui	$s3,0x800b
/*  f156904:	2673909c */ 	addiu	$s3,$s3,-28516
/*  f156908:	3c14f100 */ 	lui	$s4,0xf100
/*  f15690c:	24110064 */ 	addiu	$s1,$zero,0x64
.NB0f156910:
/*  f156910:	5622000c */ 	bnel	$s1,$v0,.NB0f156944
/*  f156914:	92020008 */ 	lbu	$v0,0x8($s0)
/*  f156918:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f15691c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f156920:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f156924:	0fc55fd5 */ 	jal	portalFindNumByVertices
/*  f156928:	03142021 */ 	addu	$a0,$t8,$s4
/*  f15692c:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f156930:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f156934:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f156938:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f15693c:	03328021 */ 	addu	$s0,$t9,$s2
/*  f156940:	92020008 */ 	lbu	$v0,0x8($s0)
.NB0f156944:
/*  f156944:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f156948:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15694c:	1440fff0 */ 	bnez	$v0,.NB0f156910
/*  f156950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156954:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156958:
/*  f156958:	3c13800a */ 	lui	$s3,0x800a
/*  f15695c:	2673e6c0 */ 	addiu	$s3,$s3,-6464
/*  f156960:	8e7802bc */ 	lw	$t8,0x2bc($s3)
/*  f156964:	1b000021 */ 	blez	$t8,.NB0f1569ec
/*  f156968:	00009025 */ 	or	$s2,$zero,$zero
/*  f15696c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f156970:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f156974:	8eae0000 */ 	lw	$t6,0x0($s5)
.NB0f156978:
/*  f156978:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15697c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f156980:	a5e00000 */ 	sh	$zero,0x0($t7)
/*  f156984:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156988:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15698c:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f156990:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156994:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f156998:	a1e20007 */ 	sb	$v0,0x7($t7)
/*  f15699c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f1569a0:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f1569a4:	a7000002 */ 	sh	$zero,0x2($t8)
/*  f1569a8:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f1569ac:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f1569b0:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f1569b4:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f1569b8:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f1569bc:	af030080 */ 	sw	$v1,0x80($t8)
/*  f1569c0:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f1569c4:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f1569c8:	ade00084 */ 	sw	$zero,0x84($t7)
/*  f1569cc:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f1569d0:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f1569d4:	af000088 */ 	sw	$zero,0x88($t8)
/*  f1569d8:	8e6e02bc */ 	lw	$t6,0x2bc($s3)
/*  f1569dc:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f1569e0:	028e082a */ 	slt	$at,$s4,$t6
/*  f1569e4:	5420ffe4 */ 	bnezl	$at,.NB0f156978
/*  f1569e8:	8eae0000 */ 	lw	$t6,0x0($s5)
.NB0f1569ec:
/*  f1569ec:	0fc04f00 */ 	jal	roomsReset
/*  f1569f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1569f4:	44808000 */ 	mtc1	$zero,$f16
/*  f1569f8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f1569fc:	e5f00018 */ 	swc1	$f16,0x18($t7)
/*  f156a00:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156a04:	e730001c */ 	swc1	$f16,0x1c($t9)
/*  f156a08:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156a0c:	e7100020 */ 	swc1	$f16,0x20($t8)
/*  f156a10:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156a14:	e5d00024 */ 	swc1	$f16,0x24($t6)
/*  f156a18:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f156a1c:	e5f00028 */ 	swc1	$f16,0x28($t7)
/*  f156a20:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156a24:	0fc4dbbd */ 	jal	dyntexReset
/*  f156a28:	e730002c */ 	swc1	$f16,0x2c($t9)
/*  f156a2c:	03a08025 */ 	or	$s0,$sp,$zero
/*  f156a30:	261000b3 */ 	addiu	$s0,$s0,0xb3
/*  f156a34:	3c12800b */ 	lui	$s2,0x800b
/*  f156a38:	3618000f */ 	ori	$t8,$s0,0xf
/*  f156a3c:	265290a4 */ 	addiu	$s2,$s2,-28508
/*  f156a40:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f156a44:	00808025 */ 	or	$s0,$a0,$zero
/*  f156a48:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f156a4c:	0fc5560b */ 	jal	bgLoadFile
/*  f156a50:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f156a54:	96020000 */ 	lhu	$v0,0x0($s0)
/*  f156a58:	96110002 */ 	lhu	$s1,0x2($s0)
/*  f156a5c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f156a60:	304f7fff */ 	andi	$t7,$v0,0x7fff
/*  f156a64:	25e2ffff */ 	addiu	$v0,$t7,-1
/*  f156a68:	3459000f */ 	ori	$t9,$v0,0xf
/*  f156a6c:	03201025 */ 	or	$v0,$t9,$zero
/*  f156a70:	0c004a0e */ 	jal	mempAlloc
/*  f156a74:	24441001 */ 	addiu	$a0,$v0,0x1001
/*  f156a78:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f156a7c:	2626ffff */ 	addiu	$a2,$s1,-1
/*  f156a80:	24441000 */ 	addiu	$a0,$v0,0x1000
/*  f156a84:	34d8000f */ 	ori	$t8,$a2,0xf
/*  f156a88:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f156a8c:	00808025 */ 	or	$s0,$a0,$zero
/*  f156a90:	27060001 */ 	addiu	$a2,$t8,0x1
/*  f156a94:	0fc5560b */ 	jal	bgLoadFile
/*  f156a98:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f156a9c:	02002025 */ 	or	$a0,$s0,$zero
/*  f156aa0:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f156aa4:	0fc56023 */ 	jal	bgInflate
/*  f156aa8:	02203025 */ 	or	$a2,$s1,$zero
/*  f156aac:	8e6302bc */ 	lw	$v1,0x2bc($s3)
/*  f156ab0:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f156ab4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156ab8:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f156abc:	1420007a */ 	bnez	$at,.NB0f156ca8
/*  f156ac0:	3c013f00 */ 	lui	$at,0x3f00
/*  f156ac4:	3c1e800a */ 	lui	$s8,0x800a
/*  f156ac8:	3c13800b */ 	lui	$s3,0x800b
/*  f156acc:	44818000 */ 	mtc1	$at,$f16
/*  f156ad0:	26739444 */ 	addiu	$s3,$s3,-27580
/*  f156ad4:	27dee6c0 */ 	addiu	$s8,$s8,-6464
/*  f156ad8:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f156adc:	24120014 */ 	addiu	$s2,$zero,0x14
/*  f156ae0:	86190000 */ 	lh	$t9,0x0($s0)
.NB0f156ae4:
/*  f156ae4:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f156ae8:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156aec:	44999000 */ 	mtc1	$t9,$f18
/*  f156af0:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f156af4:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f156af8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f156afc:	03117021 */ 	addu	$t6,$t8,$s1
/*  f156b00:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f156b04:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f156b08:	e5c80018 */ 	swc1	$f8,0x18($t6)
/*  f156b0c:	8618fff6 */ 	lh	$t8,-0xa($s0)
/*  f156b10:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f156b14:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156b18:	44989000 */ 	mtc1	$t8,$f18
/*  f156b1c:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f156b20:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f156b24:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f156b28:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f156b2c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f156b30:	e5e4001c */ 	swc1	$f4,0x1c($t7)
/*  f156b34:	860efff8 */ 	lh	$t6,-0x8($s0)
/*  f156b38:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f156b3c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f156b40:	448e9000 */ 	mtc1	$t6,$f18
/*  f156b44:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f156b48:	c708000c */ 	lwc1	$f8,0xc($t8)
/*  f156b4c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f156b50:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f156b54:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f156b58:	e72a0020 */ 	swc1	$f10,0x20($t9)
/*  f156b5c:	860ffffa */ 	lh	$t7,-0x6($s0)
/*  f156b60:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f156b64:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156b68:	448f9000 */ 	mtc1	$t7,$f18
/*  f156b6c:	03127021 */ 	addu	$t6,$t8,$s2
/*  f156b70:	c5c40004 */ 	lwc1	$f4,0x4($t6)
/*  f156b74:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f156b78:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f156b7c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f156b80:	e7060024 */ 	swc1	$f6,0x24($t8)
/*  f156b84:	8619fffc */ 	lh	$t9,-0x4($s0)
/*  f156b88:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f156b8c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156b90:	44999000 */ 	mtc1	$t9,$f18
/*  f156b94:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f156b98:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f156b9c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f156ba0:	03117021 */ 	addu	$t6,$t8,$s1
/*  f156ba4:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f156ba8:	e5c80028 */ 	swc1	$f8,0x28($t6)
/*  f156bac:	8618fffe */ 	lh	$t8,-0x2($s0)
/*  f156bb0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f156bb4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156bb8:	44989000 */ 	mtc1	$t8,$f18
/*  f156bbc:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f156bc0:	c726000c */ 	lwc1	$f6,0xc($t9)
/*  f156bc4:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f156bc8:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f156bcc:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f156bd0:	e5e4002c */ 	swc1	$f4,0x2c($t7)
/*  f156bd4:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156bd8:	03311021 */ 	addu	$v0,$t9,$s1
/*  f156bdc:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f156be0:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*  f156be4:	46124180 */ 	add.s	$f6,$f8,$f18
/*  f156be8:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f156bec:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*  f156bf0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156bf4:	03111021 */ 	addu	$v0,$t8,$s1
/*  f156bf8:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f156bfc:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f156c00:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f156c04:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f156c08:	e4460034 */ 	swc1	$f6,0x34($v0)
/*  f156c0c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f156c10:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f156c14:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f156c18:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f156c1c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f156c20:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f156c24:	e4520038 */ 	swc1	$f18,0x38($v0)
/*  f156c28:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f156c2c:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f156c30:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f156c34:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f156c38:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f156c3c:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f156c40:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f156c44:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f156c48:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f156c4c:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f156c50:	46069381 */ 	sub.s	$f14,$f18,$f6
/*  f156c54:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f156c58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156c5c:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f156c60:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f156c64:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f156c68:	0c012e84 */ 	jal	sqrtf
/*  f156c6c:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f156c70:	3c013f00 */ 	lui	$at,0x3f00
/*  f156c74:	44818000 */ 	mtc1	$at,$f16
/*  f156c78:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156c7c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156c80:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f156c84:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f156c88:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f156c8c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f156c90:	e706003c */ 	swc1	$f6,0x3c($t8)
/*  f156c94:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f156c98:	0283082b */ 	sltu	$at,$s4,$v1
/*  f156c9c:	5420ff91 */ 	bnezl	$at,.NB0f156ae4
/*  f156ca0:	86190000 */ 	lh	$t9,0x0($s0)
/*  f156ca4:	24140001 */ 	addiu	$s4,$zero,0x1
.NB0f156ca8:
/*  f156ca8:	3c1e800a */ 	lui	$s8,0x800a
/*  f156cac:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f156cb0:	27dee6c0 */ 	addiu	$s8,$s8,-6464
/*  f156cb4:	14200012 */ 	bnez	$at,.NB0f156d00
/*  f156cb8:	02001025 */ 	or	$v0,$s0,$zero
/*  f156cbc:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f156cc0:	944e0000 */ 	lhu	$t6,0x0($v0)
.NB0f156cc4:
/*  f156cc4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156cc8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f156ccc:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f156cd0:	25f9010f */ 	addiu	$t9,$t7,0x10f
/*  f156cd4:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f156cd8:	3738000f */ 	ori	$t8,$t9,0xf
/*  f156cdc:	3b0e000f */ 	xori	$t6,$t8,0xf
/*  f156ce0:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f156ce4:	af2e0080 */ 	sw	$t6,0x80($t9)
/*  f156ce8:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f156cec:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f156cf0:	0283082b */ 	sltu	$at,$s4,$v1
/*  f156cf4:	5420fff3 */ 	bnezl	$at,.NB0f156cc4
/*  f156cf8:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f156cfc:	24140001 */ 	addiu	$s4,$zero,0x1
.NB0f156d00:
/*  f156d00:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f156d04:	00002025 */ 	or	$a0,$zero,$zero
/*  f156d08:	1420001b */ 	bnez	$at,.NB0f156d78
/*  f156d0c:	00402825 */ 	or	$a1,$v0,$zero
/*  f156d10:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f156d14:	3403ffff */ 	dli	$v1,0xffff
.NB0f156d18:
/*  f156d18:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f156d1c:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f156d20:	01f17021 */ 	addu	$t6,$t7,$s1
/*  f156d24:	a1d80008 */ 	sb	$t8,0x8($t6)
/*  f156d28:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f156d2c:	03311021 */ 	addu	$v0,$t9,$s1
/*  f156d30:	804f0008 */ 	lb	$t7,0x8($v0)
/*  f156d34:	59e0000a */ 	blezl	$t7,.NB0f156d60
/*  f156d38:	a443000a */ 	sh	$v1,0xa($v0)
/*  f156d3c:	a444000a */ 	sh	$a0,0xa($v0)
/*  f156d40:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f156d44:	03117021 */ 	addu	$t6,$t8,$s1
/*  f156d48:	81d90008 */ 	lb	$t9,0x8($t6)
/*  f156d4c:	00992021 */ 	addu	$a0,$a0,$t9
/*  f156d50:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f156d54:	10000002 */ 	beqz	$zero,.NB0f156d60
/*  f156d58:	000f2403 */ 	sra	$a0,$t7,0x10
/*  f156d5c:	a443000a */ 	sh	$v1,0xa($v0)
.NB0f156d60:
/*  f156d60:	8fce02bc */ 	lw	$t6,0x2bc($s8)
/*  f156d64:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156d68:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f156d6c:	028e082b */ 	sltu	$at,$s4,$t6
/*  f156d70:	1420ffe9 */ 	bnez	$at,.NB0f156d18
/*  f156d74:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f156d78:
/*  f156d78:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f156d7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f156d80:	0c004a53 */ 	jal	mempRealloc
/*  f156d84:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f156d88:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f156d8c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156d90:	2a210002 */ 	slti	$at,$s1,0x2
/*  f156d94:	5420000a */ 	bnezl	$at,.NB0f156dc0
/*  f156d98:	2a210002 */ 	slti	$at,$s1,0x2
.NB0f156d9c:
/*  f156d9c:	0fc004f2 */ 	jal	roomInitLights
/*  f156da0:	02802025 */ 	or	$a0,$s4,$zero
/*  f156da4:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f156da8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156dac:	0291082a */ 	slt	$at,$s4,$s1
/*  f156db0:	1420fffa */ 	bnez	$at,.NB0f156d9c
/*  f156db4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156db8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156dbc:	2a210002 */ 	slti	$at,$s1,0x2
.NB0f156dc0:
/*  f156dc0:	1420000b */ 	bnez	$at,.NB0f156df0
/*  f156dc4:	3c0c800b */ 	lui	$t4,0x800b
/*  f156dc8:	8d8c90a8 */ 	lw	$t4,-0x6f58($t4)
/*  f156dcc:	3c1e800a */ 	lui	$s8,0x800a
/*  f156dd0:	27dee6c0 */ 	addiu	$s8,$s8,-6464
/*  f156dd4:	258c008c */ 	addiu	$t4,$t4,0x8c
.NB0f156dd8:
/*  f156dd8:	81990008 */ 	lb	$t9,0x8($t4)
/*  f156ddc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156de0:	0291082a */ 	slt	$at,$s4,$s1
/*  f156de4:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f156de8:	1420fffb */ 	bnez	$at,.NB0f156dd8
/*  f156dec:	02d9b021 */ 	addu	$s6,$s6,$t9
.NB0f156df0:
/*  f156df0:	12c0001c */ 	beqz	$s6,.NB0f156e64
/*  f156df4:	3c03800b */ 	lui	$v1,0x800b
/*  f156df8:	00162080 */ 	sll	$a0,$s6,0x2
/*  f156dfc:	00962023 */ 	subu	$a0,$a0,$s6
/*  f156e00:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f156e04:	348f000f */ 	ori	$t7,$a0,0xf
/*  f156e08:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f156e0c:	0c004a0e */ 	jal	mempAlloc
/*  f156e10:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f156e14:	3c03800b */ 	lui	$v1,0x800b
/*  f156e18:	24638760 */ 	addiu	$v1,$v1,-30880
/*  f156e1c:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f156e20:	1ac00013 */ 	blez	$s6,.NB0f156e70
/*  f156e24:	0000a025 */ 	or	$s4,$zero,$zero
/*  f156e28:	00001025 */ 	or	$v0,$zero,$zero
.NB0f156e2c:
/*  f156e2c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f156e30:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156e34:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f156e38:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f156e3c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f156e40:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f156e44:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f156e48:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f156e4c:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f156e50:	24420003 */ 	addiu	$v0,$v0,0x3
/*  f156e54:	1696fff5 */ 	bne	$s4,$s6,.NB0f156e2c
/*  f156e58:	a3200002 */ 	sb	$zero,0x2($t9)
/*  f156e5c:	10000004 */ 	beqz	$zero,.NB0f156e70
/*  f156e60:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156e64:
/*  f156e64:	24638760 */ 	addiu	$v1,$v1,-30880
/*  f156e68:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f156e6c:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f156e70:
/*  f156e70:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f156e74:	00009025 */ 	or	$s2,$zero,$zero
/*  f156e78:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f156e7c:	1300000a */ 	beqz	$t8,.NB0f156ea8
/*  f156e80:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f156e84:
/*  f156e84:	0fc57cae */ 	jal	func0f164ab8
/*  f156e88:	02802025 */ 	or	$a0,$s4,$zero
/*  f156e8c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f156e90:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f156e94:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156e98:	01d2c821 */ 	addu	$t9,$t6,$s2
/*  f156e9c:	972f0000 */ 	lhu	$t7,0x0($t9)
/*  f156ea0:	15e0fff8 */ 	bnez	$t7,.NB0f156e84
/*  f156ea4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f156ea8:
/*  f156ea8:	3c10800a */ 	lui	$s0,0x800a
/*  f156eac:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f156eb0:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f156eb4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156eb8:	2a210002 */ 	slti	$at,$s1,0x2
/*  f156ebc:	5420000a */ 	bnezl	$at,.NB0f156ee8
/*  f156ec0:	2a210002 */ 	slti	$at,$s1,0x2
.NB0f156ec4:
/*  f156ec4:	0fc57d19 */ 	jal	room0f164c64
/*  f156ec8:	02802025 */ 	or	$a0,$s4,$zero
/*  f156ecc:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f156ed0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156ed4:	0291082a */ 	slt	$at,$s4,$s1
/*  f156ed8:	1420fffa */ 	bnez	$at,.NB0f156ec4
/*  f156edc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156ee0:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f156ee4:	2a210002 */ 	slti	$at,$s1,0x2
.NB0f156ee8:
/*  f156ee8:	54200009 */ 	bnezl	$at,.NB0f156f10
/*  f156eec:	8ef00000 */ 	lw	$s0,0x0($s7)
.NB0f156ef0:
/*  f156ef0:	0fc57c33 */ 	jal	bgExpandRoomToPortals
/*  f156ef4:	02802025 */ 	or	$a0,$s4,$zero
/*  f156ef8:	8e1802bc */ 	lw	$t8,0x2bc($s0)
/*  f156efc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f156f00:	0298082a */ 	slt	$at,$s4,$t8
/*  f156f04:	1420fffa */ 	bnez	$at,.NB0f156ef0
/*  f156f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156f0c:	8ef00000 */ 	lw	$s0,0x0($s7)
.NB0f156f10:
/*  f156f10:	00009025 */ 	or	$s2,$zero,$zero
/*  f156f14:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f156f18:	02001025 */ 	or	$v0,$s0,$zero
/*  f156f1c:	11c0000a */ 	beqz	$t6,.NB0f156f48
/*  f156f20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156f24:	90590006 */ 	lbu	$t9,0x6($v0)
.NB0f156f28:
/*  f156f28:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f156f2c:	332f00fe */ 	andi	$t7,$t9,0xfe
/*  f156f30:	a04f0006 */ 	sb	$t7,0x6($v0)
/*  f156f34:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f156f38:	03121021 */ 	addu	$v0,$t8,$s2
/*  f156f3c:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f156f40:	55c0fff9 */ 	bnezl	$t6,.NB0f156f28
/*  f156f44:	90590006 */ 	lbu	$t9,0x6($v0)
.NB0f156f48:
/*  f156f48:	0fc581b9 */ 	jal	envSetStageNum
/*  f156f4c:	8fa40148 */ 	lw	$a0,0x148($sp)
/*  f156f50:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f156f54:	3c018008 */ 	lui	$at,0x8008
/*  f156f58:	0fc04c9c */ 	jal	wallhitReset
/*  f156f5c:	a4392474 */ 	sh	$t9,0x2474($at)
/*  f156f60:	0fc00acc */ 	jal	func0f002a98
/*  f156f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156f68:	0fc00729 */ 	jal	func0f001c0c
/*  f156f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156f70:	0fc556e1 */ 	jal	bgBuildReferenceLightSums
/*  f156f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f156f78:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f156f7c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f156f80:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f156f84:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f156f88:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f156f8c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f156f90:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f156f94:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f156f98:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f156f9c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f156fa0:	03e00008 */ 	jr	$ra
/*  f156fa4:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#endif

// Mismatch: Not functionally identical (some portals are broken), and due to
// differences in callee-save register usage it's hard to spot why.
// I suspect pvertices is just a byte array but haven't tested that theory.
//void bgBuildTables(s32 stagenum)
//{
//	s32 s4;
//	s32 s6;
//	s32 k;
//	u8 *header;
//	u8 headerbuffer[0x50];
//	s32 numportals;
//	s32 index;
//	f32 fVar35;
//	f32 xdiff;
//	f32 ydiff;
//	f32 zdiff;
//	s16 lightindex;
//	s32 numlights;
//	u32 inflatedsize;
//	u8 *section3;
//	u8 *section3ptr;
//	u32 section3compsize;
//	u32 scratch;
//	struct portalvertices *pvertices;
//
//	g_Rooms = mempAlloc(ALIGN16(g_Vars.roomcount * sizeof(struct room)), MEMPOOL_STAGE);
//	var800a4ce8 = mempAlloc(ALIGN16(g_Vars.roomcount * sizeof(struct var800a4ce8)), MEMPOOL_STAGE);
//
//	// 9b8
//	for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//		var800a4ce8[s4].unk00 = 0xffff;
//		var800a4ce8[s4].unk02 = 0;
//	}
//
//	// 9ec
//	if (g_Vars.mplayerisrunning) {
//		g_MpRoomVisibility = mempAlloc(ALIGN16(g_Vars.roomcount), MEMPOOL_STAGE);
//
//		for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//			g_MpRoomVisibility[s4] = 0;
//		}
//	}
//
//	// a48
//	for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//		g_Rooms[s4].unk44 = NULL;
//		g_Rooms[s4].numlights = 0;
//		g_Rooms[s4].lightindex = 0;
//		g_Rooms[s4].flags = 0;
//		g_Rooms[s4].unk4d = 0;
//		g_Rooms[s4].prevop = 0;
//		g_Rooms[s4].b = 0;
//	}
//
//	// ae4
//	func0f15c880(g_Stages[g_StageIndex].unk14);
//	chr0f028490(g_Stages[g_StageIndex].unk14);
//
//	// b34
//	for (s4 = 0; s4 < 4; s4++) { // might not be s4
//		g_Vars.playerstats[s4].scale_bg2gfx = g_Stages[g_StageIndex].unk18;
//	}
//
//	mtx00016748(1);
//
//	// b64
//	if (var800a4920 == 0) {
//		// b84
//		s32 offset;
//		s32 numvertices;
//
//		numportals = 0;
//
//		for (s4 = 0; g_BgPortals[s4].verticesoffset != 0; s4++) { // might not be s4
//			numportals++;
//		}
//
//		g_NumPortalThings = numportals;
//		g_PortalThings = mempAlloc(ALIGN16(g_NumPortalThings * sizeof(struct portalthing)), MEMPOOL_STAGE);
//
//		// Iterate the portals and update their verticesoffset value. In
//		// storage, the g_BgPortals array is followed by vertice data, and each
//		// portal's verticesoffset value is an index into the vertice data.
//		// Here, the unk00 value is being converted to an offset relative to the
//		// start of the g_BgPortals array. Start by initialising offset past the
//		// end of the portal array, which is the start of the vertice data.
//		offset = numportals * sizeof(struct bgportal);
//		offset += sizeof(struct bgportal);
//
//		// Because each group of vertices is variable length, the portals can't
//		// be iterated in order and have their offset calculated. The vertice
//		// data has to be iterated in storage order, then iterate all portals to
//		// see if any refer to this index.
//		// bd4
//		for (s4 = 1; true; s4++) {
//			for (s6 = 0; s6 < numportals; s6++) {
//				if (g_BgPortals[s6].verticesoffset == s4) {
//					g_BgPortals[s6].verticesoffset = offset;
//				}
//			}
//
//			pvertices = (struct portalvertices *)((u32)g_BgPortals + offset);
//
//			if (pvertices->count <= 0) {
//				break;
//			}
//
//			offset += pvertices->count * sizeof(struct coord);
//			offset += 4;
//		}
//
//		// Calculate g_RoomPortals: An array of portal numbers, ordered by room
//		// number ascending. Each room struct contains an index into this array
//		// where its portal numbers start.
//		index = 0;
//		g_RoomPortals = mempAlloc(ALIGN16((numportals == 0 ? 1 : numportals) * sizeof(s16 *)), MEMPOOL_STAGE);
//
//		g_Vars.roomportalrecursionlimit = 0;
//
//		// c84
//		for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//			s32 numportalsthisroom = 0;
//
//			g_Rooms[s4].roomportallistoffset = index;
//
//			// c98
//			for (s6 = 0; s6 < numportals; s6++) {
//				if (s4 == g_BgPortals[s6].roomnum1) {
//					g_RoomPortals[index] = s6;
//					index++;
//					numportalsthisroom++;
//				}
//
//				if (s4 == g_BgPortals[s6].roomnum2) {
//					g_RoomPortals[index] = s6;
//					index++;
//					numportalsthisroom++;
//				}
//			}
//
//
//			g_Rooms[s4].numportals = numportalsthisroom;
//
//			if (numportalsthisroom > g_Vars.roomportalrecursionlimit) {
//				g_Vars.roomportalrecursionlimit = numportalsthisroom;
//			}
//		}
//
//		// Sort the portal numbers in g_RoomPortals within their room groups.
//		// Sorting is done by neighbouring room number ascending.
//		//
//		// @bug? The k loop doesn't reset to s6 after doing a swap, which means
//		// some items may not be sorted correctly.
//
//		// d50
//		for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//			// d78
//			for (s6 = 0; s6 < g_Rooms[s4].numportals; s6++) {
//				s32 thisportalnum = g_RoomPortals[g_Rooms[s4].roomportallistoffset + s6];
//				s32 thisneighbournum;
//
//				if (g_BgPortals[thisportalnum].roomnum1 == s4) {
//					thisneighbournum = g_BgPortals[thisportalnum].roomnum2;
//				} else {
//					thisneighbournum = g_BgPortals[thisportalnum].roomnum1;
//				}
//
//				// da8
//				for (k = s6; k < g_Rooms[s4].numportals; k++) {
//					s32 candportalnum = g_RoomPortals[g_Rooms[s4].roomportallistoffset + k];
//					s32 swap = false;
//
//					// dc4
//					if (s4 == g_BgPortals[candportalnum].roomnum1) {
//						if (g_BgPortals[candportalnum].roomnum2 < thisneighbournum) {
//							swap = true;
//						}
//					} else {
//						if (g_BgPortals[candportalnum].roomnum1 < thisneighbournum) {
//							swap = true;
//						}
//					}
//
//					// df0
//					if (swap) {
//						g_RoomPortals[g_Rooms[s4].roomportallistoffset + k] = thisportalnum;
//						g_RoomPortals[g_Rooms[s4].roomportallistoffset + s6] = candportalnum;
//
//						// e4c
//						if (g_BgPortals[g_RoomPortals[g_Rooms[s4].roomportallistoffset + s6]].roomnum1 == s4) {
//							thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[s4].roomportallistoffset + s6]].roomnum2;
//						} else {
//							thisneighbournum = g_BgPortals[g_RoomPortals[g_Rooms[s4].roomportallistoffset + s6]].roomnum1;
//						}
//					}
//				}
//			}
//		}
//
//		// ea8
//		var800a4cd0 = mempAlloc(ALIGN16(numportals == 0 ? 1 : numportals), MEMPOOL_STAGE);
//
//		// edc
//		for (s4 = 0; s4 < numportals; s4++) {
//			var800a4cd0[s4] = func0f15b4c0(s4);
//		}
//
//		var800a4ccc = mempAlloc(ALIGN16(numportals * sizeof(struct var800a4ccc)), MEMPOOL_STAGE);
//
//		// f38
//		for (s4 = 0; s4 < numportals; s4++) {
//			struct coord coord;
//			f32 min;
//			f32 max;
//			struct var800a4ccc *tmp;
//
//			coord.f[0] = coord.f[1] = coord.f[2] = 0;
//
//			pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[s4].verticesoffset);
//
//			// f64
//			for (s6 = 0; s6 < pvertices->count; s6++) {
//				s32 next = (s6 + 1) % pvertices->count;
//
//				coord.f[0] += (pvertices->vertices[s6].f[1] - pvertices->vertices[next].f[1]) * (pvertices->vertices[s6].f[2] + pvertices->vertices[next].f[2]);
//				coord.f[1] += (pvertices->vertices[s6].f[2] - pvertices->vertices[next].f[2]) * (pvertices->vertices[s6].f[0] + pvertices->vertices[next].f[0]);
//				coord.f[2] += (pvertices->vertices[s6].f[0] - pvertices->vertices[next].f[0]) * (pvertices->vertices[s6].f[1] + pvertices->vertices[next].f[1]);
//			}
//
//			// 030
//			fVar35 = -sqrtf(coord.f[0] * coord.f[0] + coord.f[1] * coord.f[1] + coord.f[2] * coord.f[2]);
//
//			coord.f[0] = coord.f[0] / fVar35;
//			coord.f[1] = coord.f[1] / fVar35;
//			coord.f[2] = coord.f[2] / fVar35;
//
//			min = _DMAX;
//			max = -_DMAX;
//
//			// 0bc
//			for (s6 = 0; s6 < pvertices->count; s6++) {
//				f32 value = pvertices->vertices[s6].f[0] * coord.f[0]
//					+ pvertices->vertices[s6].f[1] * coord.f[1]
//					+ pvertices->vertices[s6].f[2] * coord.f[2];
//
//				if (value < min) {
//					min = value;
//				}
//
//				if (value > max) {
//					max = value;
//				}
//			}
//
//			// 130
//			tmp = &var800a4ccc[s4];
//			tmp->coord.f[0] = coord.f[0];
//			tmp->coord.f[1] = coord.f[1];
//			tmp->coord.f[2] = coord.f[2];
//			tmp->unk0c = min;
//			tmp->unk10 = max;
//		}
//
//		// 174
//		portal0f0b65a8(numportals);
//
//		// 1a0
//		if (g_BgCommands != NULL) {
//			for (s4 = 0; g_BgCommands[s4].type != BGCMD_END; s4++) { // might not be s4
//				if (g_BgCommands[s4].type == BGCMD_PORTALARG) {
//					g_BgCommands[s4].param = portalFindNumByVertices((void *)(g_BgCommands[s4].param + (u32)g_BgPrimaryData + 0xf1000000));
//				}
//			}
//		}
//
//		// 220
//		for (s4 = 0; s4 < g_Vars.roomcount; s4++) {
//			g_Rooms[s4].flags = 0;
//			g_Rooms[s4].unk06 = 0;
//			g_Rooms[s4].unk07 = 1;
//			g_Rooms[s4].loaded240 = 0;
//			g_Rooms[s4].gfxdata = NULL;
//			g_Rooms[s4].gfxdatalen = -1;
//			g_Rooms[s4].unk84 = 0;
//			g_Rooms[s4].unk88 = 0;
//		}
//
//		// 294
//		roomsReset();
//
//		g_Rooms[0].bbmin[0] = 0;
//		g_Rooms[0].bbmin[1] = 0;
//		g_Rooms[0].bbmin[2] = 0;
//		g_Rooms[0].bbmax[0] = 0;
//		g_Rooms[0].bbmax[1] = 0;
//		g_Rooms[0].bbmax[2] = 0;
//
//		// 2cc
//		dyntexReset();
//
//		header = (u8 *)ALIGN16((u32)headerbuffer);
//		bgLoadFile(header, g_BgSection3, 0x40);
//		inflatedsize = (*(u16 *)&header[0] & 0x7fff) - 1;
//		section3compsize = *(u16 *)&header[2];
//		inflatedsize = (inflatedsize | 0xf) + 1;
//		section3 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
//		scratch = (u32)section3 + 0x8000;
//		bgLoadFile((u8 *)scratch, g_BgSection3 + 4, (section3compsize - 1 | 0xf) + 1);
//		bgInflate((u8 *)scratch, section3, section3compsize);
//		section3ptr = section3;
//
//		// 394
//		for (s4 = 1; s4 < (u32)g_Vars.roomcount; s4++) {
//			// Calculate bounding box
//			g_Rooms[s4].bbmin[0] = g_BgRooms[s4].pos.x + *(s16 *)&section3ptr[0];
//			g_Rooms[s4].bbmin[1] = g_BgRooms[s4].pos.y + *(s16 *)&section3ptr[2];
//			g_Rooms[s4].bbmin[2] = g_BgRooms[s4].pos.z + *(s16 *)&section3ptr[4];
//			g_Rooms[s4].bbmax[0] = g_BgRooms[s4].pos.x + *(s16 *)&section3ptr[6];
//			g_Rooms[s4].bbmax[1] = g_BgRooms[s4].pos.y + *(s16 *)&section3ptr[8];
//			g_Rooms[s4].bbmax[2] = g_BgRooms[s4].pos.z + *(s16 *)&section3ptr[10];
//
//			// Calculate centre
//			g_Rooms[s4].centre.x = (g_Rooms[s4].bbmax[0] + g_Rooms[s4].bbmin[0]) * 0.5f;
//			g_Rooms[s4].centre.y = (g_Rooms[s4].bbmax[1] + g_Rooms[s4].bbmin[1]) * 0.5f;
//			g_Rooms[s4].centre.z = (g_Rooms[s4].bbmax[2] + g_Rooms[s4].bbmin[2]) * 0.5f;
//
//			// Calculate radius
//			xdiff = g_Rooms[s4].bbmin[0] - g_Rooms[s4].bbmax[0];
//			ydiff = g_Rooms[s4].bbmin[1] - g_Rooms[s4].bbmax[1];
//			zdiff = g_Rooms[s4].bbmin[2] - g_Rooms[s4].bbmax[2];
//
//			g_Rooms[s4].radius = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff) * 0.5f;
//
//			section3ptr += 12;
//		}
//
//		// 574
//		for (s4 = 1; s4 < (u32)g_Vars.roomcount; s4++) {
//			g_Rooms[s4].gfxdatalen = ALIGN16(*(u16 *)section3ptr * 0x10 + 0x100);
//			section3ptr += 2;
//		}
//
//		lightindex = 0;
//
//		// 5c8
//		for (s4 = 1; s4 < (u32)g_Vars.roomcount; s4++) {
//			g_Rooms[s4].numlights = *section3ptr;
//
//			if (g_Rooms[s4].numlights > 0) {
//				g_Rooms[s4].lightindex = lightindex;
//				lightindex += g_Rooms[s4].numlights;
//			} else {
//				g_Rooms[s4].lightindex = -1;
//			}
//
//			section3ptr++;
//		}
//
//		mempRealloc(section3, 0, MEMPOOL_STAGE);
//
//		// 64c
//		for (s4 = 1; s4 < g_Vars.roomcount; s4++) {
//			roomInitLights(s4);
//		}
//
//		numlights = 0;
//
//		// 688
//		for (s4 = 1; s4 < g_Vars.roomcount; s4++) {
//			numlights += g_Rooms[s4].numlights;
//		}
//
//		// 6a0
//		if (numlights) {
//			var800a41a0 = mempAlloc(ALIGN16(numlights * 3), MEMPOOL_STAGE);
//
//			for (s4 = 0; s4 < numlights; s4++) {
//				var800a41a0[s4 * 3 + 0] = 0;
//				var800a41a0[s4 * 3 + 1] = 0;
//				var800a41a0[s4 * 3 + 2] = 0;
//			}
//		} else {
//			var800a41a0 = NULL;
//		}
//
//		// 734
//		for (s4 = 0; g_BgPortals[s4].verticesoffset; s4++) {
//			func0f164ab8(s4);
//		}
//
//		// 774
//		for (s4 = 1; s4 < g_Vars.roomcount; s4++) {
//			room0f164c64(s4);
//		}
//
//		// 7a0
//		for (s4 = 1; s4 < g_Vars.roomcount; s4++) {
//			bgExpandRoomToPortals(s4);
//		}
//
//		// 7d8
//		for (s4 = 0; g_BgPortals[s4].verticesoffset; s4++) { // might not be s4
//			g_BgPortals[s4].flags &= 0xfe;
//		}
//	}
//
//	// 7f8
//	envSetStageNum(stagenum);
//
//	var8007fc10 = 200;
//
//	wallhitReset();
//	func0f002a98();
//	func0f001c0c();
//}

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
		s32 *ptr = (s32 *)&func0f0069dc;
		s32 *end = (s32 *)&func0f006b08;

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

Gfx *func0f15da00(struct roomgfxdata18 *arg0, Gfx *arg1, Gfx *arg2)
{ \
	Gfx *tmp; \
	while (true) {
		if (arg0 == NULL) {
			return arg2;
		}

		if (arg1);
		if (arg1);
		if (arg1);
		if (arg1);

		switch (arg0->type) {
		case 0:
			if (arg1 < arg0->gdl && (arg2 > arg0->gdl || arg2 == NULL)) {
				arg2 = arg0->gdl;
			}
			arg0 = arg0->next;
			break;
		case 1:
			tmp = func0f15da00(arg0->child, arg1, arg2);
			arg0 = arg0->next;
			arg2 = tmp;
			break;
		default:
			return arg2;
		}
	}

	return arg2;
}

Gfx *room0f15dab4(s32 roomnum, Gfx *gdl, u32 types)
{
	struct roomgfxdata18 *thing1 = g_Rooms[roomnum].gfxdata->unk08;
	struct roomgfxdata18 *thing2 = g_Rooms[roomnum].gfxdata->unk0c;
	Gfx *sp1c = NULL;
	Gfx *sp18 = NULL;

	if ((types & VTXBATCHTYPE_OPA) && thing1) {
		sp1c = func0f15da00(thing1, gdl, NULL);

		if (types == VTXBATCHTYPE_OPA) {
			return sp1c;
		}
	}

	if ((types & VTXBATCHTYPE_XLU) && thing2) {
		sp18 = func0f15da00(thing2, gdl, NULL);

		if (types == VTXBATCHTYPE_XLU) {
			return sp18;
		}
	}

	if (sp1c) {
		if (sp18 && sp18 < sp1c) {
			return sp18;
		}

		return sp1c;
	}

	return sp18;
}

struct gfxvtx *room0f15dbb4(s32 roomnum, Gfx *gdl)
{
	struct roomgfxdata18 *thing = g_Rooms[roomnum].gfxdata->unk18;
	u32 end = (u32)g_Rooms[roomnum].gfxdata->vertices;

	while ((u32)(thing + 1) <= end) {
		switch (thing->type) {
		case 0:
			if (gdl == thing->gdl) {
				return thing->vertices;
			}
			break;
		case 1:
			if ((u32)thing->vertices < end) {
				end = (u32)thing->vertices;
			}
			break;
		}

		thing++;
	}

	return NULL;
}

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
/*  f15e090:	0fc576ad */ 	jal	room0f15dab4
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
/*  f15e0c8:	0fc576ad */ 	jal	room0f15dab4
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
/*  f15e0f4:	0fc576ed */ 	jal	room0f15dbb4
/*  f15e0f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e0fc:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f15e100:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15e104:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f15e108:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f15e10c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e110:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e114:	0fc576ad */ 	jal	room0f15dab4
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
/*  f15e154:	0fc5d7bd */ 	jal	tex0f175ef4
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
/*  f15e1d4:	0fc5d5b0 */ 	jal	tex0f1756c0
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
/*  f15883c:	0fc56093 */ 	jal	room0f15dab4
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
/*  f158874:	0fc56093 */ 	jal	room0f15dab4
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
/*  f1588a4:	0fc560d3 */ 	jal	room0f15dbb4
/*  f1588a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588ac:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f1588b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1588b4:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f1588b8:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f1588bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1588c0:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f1588c4:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f1588c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1588cc:	0fc56093 */ 	jal	room0f15dab4
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
/*  f158910:	0fc5c2e5 */ 	jal	tex0f175ef4
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
/*  f158994:	0fc5c0d8 */ 	jal	tex0f1756c0
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

// Mismatch: The below stores len * 4 into s1 which causes further codegen
// differences.
//void bgLoadRoom(s32 roomnum)
//{
//	s32 size; // 2f4
//	s32 inflatedlen; // 2f0
//	u8 *allocation;
//	s32 readlen;
//	s32 fileoffset;
//	u8 *memaddr;
//	struct roomgfxdata18 *thing1;
//	struct roomgfxdata18 *thing2;
//	s32 v0;
//	s32 len;
//	u32 sp208[50];
//	s32 sp140[50];
//	u32 sp78[50];
//	s32 allocationend;
//	s32 a2;
//	s32 i; // 6c
//	u32 end1;
//	u32 end2;
//	s32 prev;
//
//#if VERSION < VERSION_NTSC_1_0
//	bgVerifyLightSums("bg.c", 7076);
//#endif
//
//	if (roomnum == 0 || roomnum >= g_Vars.roomcount || g_Rooms[roomnum].loaded240) {
//		return;
//	}
//
//	if (g_Rooms[roomnum].gfxdatalen > 0) {
//		size = g_Rooms[roomnum].gfxdatalen;
//
//		if (debug0f11edb0()) {
//			size += 1024;
//		}
//	} else {
//		size = memaGetLongestFree();
//	}
//
//	bgGarbageCollectRooms(size, false);
//	allocation = memaAlloc(size);
//
//	if (allocation != NULL) {
//		dyntexSetCurrentRoom(roomnum);
//
//		readlen = ((g_BgRooms[roomnum + 1].unk00 - g_BgRooms[roomnum].unk00) + 0xf) & ~0xf;
//		fileoffset = (g_BgPrimaryData + g_BgRooms[roomnum].unk00 - g_BgPrimaryData) + 0xf1000000;
//		fileoffset -= var8007fc54;
//
//		if (size < readlen) {
//			dyntexSetCurrentRoom(-1);
//			return;
//		}
//
//		memaddr = size - readlen + allocation;
//		bgLoadFile(memaddr, fileoffset, readlen);
//
//		if (rzipIs1173(memaddr) && size < readlen + 0x20) {
//			dyntexSetCurrentRoom(-1);
//			return;
//		}
//
//		inflatedlen = bgInflate(memaddr, allocation, g_BgRooms[roomnum + 1].unk00 - g_BgRooms[roomnum].unk00);
//		g_Rooms[roomnum].gfxdata = (struct roomgfxdata *)allocation;
//
//		if (g_Rooms[roomnum].gfxdata->vertices) {
//			g_Rooms[roomnum].gfxdata->vertices = (struct gfxvtx *)((u32)g_Rooms[roomnum].gfxdata->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
//		}
//
//		if (g_Rooms[roomnum].gfxdata->colours) {
//			g_Rooms[roomnum].gfxdata->colours = (u32 *)((u32)g_Rooms[roomnum].gfxdata->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
//		}
//
//		if (g_Rooms[roomnum].gfxdata->unk08) {
//			g_Rooms[roomnum].gfxdata->unk08 = (struct roomgfxdata18 *)((u32)g_Rooms[roomnum].gfxdata->unk08 - g_BgRooms[roomnum].unk00 + (u32)allocation);
//		}
//
//		if (g_Rooms[roomnum].gfxdata->unk0c) {
//			g_Rooms[roomnum].gfxdata->unk0c = (struct roomgfxdata18 *)((u32)g_Rooms[roomnum].gfxdata->unk0c - g_BgRooms[roomnum].unk00 + (u32)allocation);
//		}
//
//		thing1 = g_Rooms[roomnum].gfxdata->unk18;
//		end1 = (u32)g_Rooms[roomnum].gfxdata->vertices;
//
//		while ((u32)(thing1 + 1) <= end1) {
//			switch (thing1->unk00) {
//			case 0:
//				if (thing1->unk04 != 0) {
//					thing1->unk04 = (void *)((u32)thing1->unk04 - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->gdl != 0) {
//					thing1->gdl = (Gfx *)((u32)thing1->gdl - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->vertices != 0) {
//					thing1->vertices = (struct gfxvtx *)((u32)thing1->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->colours != 0) {
//					thing1->colours = (u32 *)((u32)thing1->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				break;
//			case 1:
//				if (thing1->unk04 != 0) {
//					thing1->unk04 = (void *)((u32)thing1->unk04 - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->gdl != 0) {
//					thing1->gdl = (Gfx *)((u32)thing1->gdl - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->vertices != 0) {
//					thing1->vertices = (struct gfxvtx *)((u32)thing1->vertices - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if (thing1->colours != 0) {
//					thing1->colours = (u32 *)((u32)thing1->colours - g_BgRooms[roomnum].unk00 + (u32)allocation);
//				}
//				if ((u32)thing1->vertices < end1) {
//					end1 = (u32)thing1->vertices;
//				}
//				break;
//			}
//
//			thing1++;
//		}
//
//		g_Rooms[roomnum].gfxdata->numvertices = ((u32)g_Rooms[roomnum].gfxdata->colours - (u32)g_Rooms[roomnum].gfxdata->vertices) / sizeof(struct gfxvtx);
//		g_Rooms[roomnum].gfxdata->numcolours = ((u32)room0f15dab4(roomnum, 0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU) - (u32)g_Rooms[roomnum].gfxdata->colours) / sizeof(u32);
//
//		len = 0;
//		v0 = room0f15dab4(roomnum, NULL, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);
//
//		while (v0) {
//			sp208[len] = v0;
//			sp140[len] = room0f15dbb4(roomnum, v0);
//			len++;
//
//			v0 = room0f15dab4(roomnum, v0, VTXBATCHTYPE_OPA | VTXBATCHTYPE_XLU);
//		}
//
//		sp208[len] = (s32)allocation + inflatedlen;
//		allocationend = (s32)allocation + size;
//
//		tex0f175ef4(sp208[0], allocationend - (sp208[len] - sp208[0]), sp208[len] - sp208[0]);
//
//		for (i = 0; i < len + 1; i++) {
//			sp78[i] = sp208[i] + (allocationend - sp208[len]);
//		}
//
//		a2 = sp208[0];
//
//		for (i = 0; i < len; i++) {
//			v0 = tex0f1756c0(sp78[i], sp208[i + 1] - sp208[i], a2, 0, sp140[i]);
//			sp78[i] = a2;
//			a2 += v0;
//			a2 = ALIGN8(a2);
//		}
//
//		sp78[len] = a2;
//
//		prev = g_Rooms[roomnum].gfxdatalen;
//		g_Rooms[roomnum].gfxdatalen = ALIGN16(a2 - (s32)allocation + 0x20);
//
//		if (g_Rooms[roomnum].gfxdatalen > prev) {
//#if VERSION < VERSION_NTSC_1_0
//			crashSetMessage("bg.c: roominf[room].allocsize > calculated!");
//			CRASH();
//#endif
//		}
//
//		g_Rooms[roomnum].loaded240 = 1;
//
//		if (g_Rooms[roomnum].gfxdatalen != size) {
//			bool result = memaRealloc((s32)allocation, size, g_Rooms[roomnum].gfxdatalen);
//		}
//
//		thing2 = g_Rooms[roomnum].gfxdata->unk18;
//		end2 = (u32)g_Rooms[roomnum].gfxdata->vertices;
//
//		while ((u32)(thing2 + 1) <= end2) {
//			switch (thing2->unk00) {
//			case 0:
//				if (thing2->gdl) {
//					for (i = 0; i < len; i++) {
//						if (thing2->gdl == (Gfx *)sp208[i]) {
//							thing2->gdl = (Gfx *)sp78[i];
//							break;
//						}
//					}
//				}
//				break;
//			case 1:
//				if ((u32)thing2->vertices < end2) {
//					end2 = (u32)thing2->vertices;
//				}
//				break;
//			}
//
//			thing2++;
//		}
//
//		if (g_FogEnabled) {
//			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->unk08, 1);
//			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->unk0c, 5);
//		} else if (var800a65e4 == 0) {
//			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->unk08, 6);
//			gfxReplaceGbiCommandsRecursively(g_Rooms[roomnum].gfxdata->unk0c, 7);
//		}
//
//		bgFindRoomVtxBatches(roomnum);
//
//		g_Rooms[roomnum].flags |= ROOMFLAG_DIRTY;
//		g_Rooms[roomnum].flags |= ROOMFLAG_0200;
//		g_Rooms[roomnum].colours = NULL;
//
//		dyntexSetCurrentRoom(-1);
//	}
//
//#if VERSION < VERSION_NTSC_1_0
//	bgVerifyLightSums("bg.c", 7474);
//#endif
//}

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

Gfx *bgRenderRoomPass(Gfx *gdl, s32 roomnum, struct roomgfxdata18 *arg2, bool arg3)
{
	u32 v0;

	if (arg2 == NULL) {
		return gdl;
	}

	switch (arg2->type) {
	case 0:
		if (g_Rooms[roomnum].flags & ROOMFLAG_HASDYNTEX) {
			dyntexTickRoom(roomnum, arg2->vertices);
		}

		gSPSegment(gdl++, SPSEGMENT_BG_VTX, OS_PHYSICAL_TO_K0(arg2->vertices));

		roomHighlight(roomnum);

		v0 = (u32)g_Rooms[roomnum].colours;

		if (v0 != NULL) {
			s32 addr = ALIGN8((u32)&g_Rooms[roomnum].gfxdata->vertices[g_Rooms[roomnum].gfxdata->numvertices]);
			v0 += (((s32)arg2->colours - addr) >> 2) * 4;
		} else {
			v0 = (u32)arg2->colours;
		}

		gSPSegment(gdl++, SPSEGMENT_BG_COL, OS_PHYSICAL_TO_K0(v0));

		gSPDisplayList(gdl++, OS_PHYSICAL_TO_K0(arg2->gdl));

		if (arg3) {
			gdl = bgRenderRoomPass(gdl, roomnum, arg2->next, true);
		}
		break;
	case 1:
		if (arg2->child != NULL) {
			struct roomgfxdata18 *sp58;
			struct roomgfxdata18 *sp54;
			struct coord *coord;
			f32 sum;
			f32 sp40[3];
			f32 sp34[3];
			u32 stack;

			sp58 = arg2->child;
			sp54 = sp58->next;
			coord = arg2->unk0c;

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
				gdl = bgRenderRoomPass(gdl, roomnum, arg2->next, true);
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
	gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->unk08, true);
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
		if (!g_Rooms[roomnum].gfxdata->unk0c) {
			return gdl;
		}

		roomHighlight(roomnum);

		if (g_Rooms[roomnum].gfxdata);
		if (g_Rooms[roomnum].gfxdata);

		gdl = roomPushMtx(gdl, roomnum);
		gdl = bgRenderRoomPass(gdl, roomnum, g_Rooms[roomnum].gfxdata->unk0c, true);

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
		gdl = room0f15dab4(roomnum, NULL, VTXBATCHTYPE_OPA);

		if (gdl != NULL) {
			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gDPSetVerticeArray
					if (gdl[i].dma.cmd == G_VTX) {
						batchindex++;
					}
				}

				gdl = room0f15dab4(roomnum, gdl, VTXBATCHTYPE_OPA);
			}

			xlucount = 0;

			gdl = room0f15dab4(roomnum, NULL, VTXBATCHTYPE_XLU);

			while (gdl) {
				for (i = 0; gdl[i].dma.cmd != G_ENDDL; i++) {
					// if gDPSetVerticeArray
					if (gdl[i].dma.cmd == G_VTX) {
						xlucount++;
					}
				}

				gdl = room0f15dab4(roomnum, gdl, VTXBATCHTYPE_XLU);
			}

			batchindex += xlucount;

			batches = memaAlloc((batchindex * sizeof(struct vtxbatch) + 0xf) & ~0xf);

			if (batches != NULL) {
				gdl = room0f15dab4(roomnum, NULL, VTXBATCHTYPE_OPA);
				batchindex = 0;

				g_Rooms[roomnum].vtxbatches = batches;

				while (gdl) {
					struct gfxvtx *vertices = room0f15dbb4(roomnum, gdl);
					batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_OPA);
					gdl = room0f15dab4(roomnum, gdl, VTXBATCHTYPE_OPA);
				}

				if (xlucount) {
					gdl = room0f15dab4(roomnum, NULL, VTXBATCHTYPE_XLU);

					while (gdl) {
						struct gfxvtx *vertices = room0f15dbb4(roomnum, gdl);
						batchindex = bgPopulateVtxBatchType(roomnum, batches, gdl, batchindex, vertices, VTXBATCHTYPE_XLU);
						gdl = room0f15dab4(roomnum, gdl, VTXBATCHTYPE_XLU);
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

	return bg0f15f2b0(arg0, arg1, &sp24, &sp18);
}

bool bg0f15f2b0(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3)
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

GLOBAL_ASM(
glabel func0f15f560
.late_rodata
glabel var7f1b75d8
.word 0x7f7fffff
.text
/*  f15f560:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f15f564:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f15f568:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f15f56c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f15f570:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f15f574:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f15f578:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f15f57c:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f15f580:	3c017f1b */ 	lui	$at,%hi(var7f1b75d8)
/*  f15f584:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15f588:	00809825 */ 	or	$s3,$a0,$zero
/*  f15f58c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f15f590:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f15f594:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f15f598:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f15f59c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f15f5a0:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f15f5a4:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f15f5a8:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f15f5ac:	00006825 */ 	or	$t5,$zero,$zero
/*  f15f5b0:	c43475d8 */ 	lwc1	$f20,%lo(var7f1b75d8)($at)
/*  f15f5b4:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15f5b8:	8fb00110 */ 	lw	$s0,0x110($sp)
/*  f15f5bc:	8fb200b4 */ 	lw	$s2,0xb4($sp)
/*  f15f5c0:	8fb500cc */ 	lw	$s5,0xcc($sp)
/*  f15f5c4:	8fb700f0 */ 	lw	$s7,0xf0($sp)
/*  f15f5c8:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15f5cc:	00e06025 */ 	or	$t4,$a3,$zero
/*  f15f5d0:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15f5d4:	240a000c */ 	addiu	$t2,$zero,0xc
.L0f15f5d8:
/*  f15f5d8:	81820000 */ 	lb	$v0,0x0($t4)
/*  f15f5dc:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f15f5e0:	54410008 */ 	bnel	$v0,$at,.L0f15f604
/*  f15f5e4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f15f5e8:	8fae0108 */ 	lw	$t6,0x108($sp)
/*  f15f5ec:	00006825 */ 	or	$t5,$zero,$zero
/*  f15f5f0:	11c0026c */ 	beqz	$t6,.L0f15ffa4
/*  f15f5f4:	01c06025 */ 	or	$t4,$t6,$zero
/*  f15f5f8:	1000fff7 */ 	b	.L0f15f5d8
/*  f15f5fc:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f15f600:	24010004 */ 	addiu	$at,$zero,0x4
.L0f15f604:
/*  f15f604:	544100c8 */ 	bnel	$v0,$at,.L0f15f928
/*  f15f608:	2401fffd */ 	addiu	$at,$zero,-3
/*  f15f60c:	91850001 */ 	lbu	$a1,0x1($t4)
/*  f15f610:	8d870004 */ 	lw	$a3,0x4($t4)
/*  f15f614:	3c0100ff */ 	lui	$at,0xff
/*  f15f618:	30a6000f */ 	andi	$a2,$a1,0xf
/*  f15f61c:	00ca0019 */ 	multu	$a2,$t2
/*  f15f620:	8fb9010c */ 	lw	$t9,0x10c($sp)
/*  f15f624:	3421ffff */ 	ori	$at,$at,0xffff
/*  f15f628:	00e17824 */ 	and	$t7,$a3,$at
/*  f15f62c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f15f630:	00051902 */ 	srl	$v1,$a1,0x4
/*  f15f634:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f15f638:	3078000f */ 	andi	$t8,$v1,0xf
/*  f15f63c:	03001825 */ 	or	$v1,$t8,$zero
/*  f15f640:	3c02800a */ 	lui	$v0,%hi(var800a6470+0xc)
/*  f15f644:	00007812 */ 	mflo	$t7
/*  f15f648:	01cf2023 */ 	subu	$a0,$t6,$t7
/*  f15f64c:	84980000 */ 	lh	$t8,0x0($a0)
/*  f15f650:	24630000 */ 	addiu	$v1,$v1,0x0
/*  f15f654:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f15f658:	44982000 */ 	mtc1	$t8,$f4
/*  f15f65c:	2442647c */ 	addiu	$v0,$v0,%lo(var800a6470+0xc)
/*  f15f660:	2495000c */ 	addiu	$s5,$a0,0xc
/*  f15f664:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f668:	e5260000 */ 	swc1	$f6,0x0($t1)
/*  f15f66c:	84990002 */ 	lh	$t9,0x2($a0)
/*  f15f670:	c5200000 */ 	lwc1	$f0,0x0($t1)
/*  f15f674:	44994000 */ 	mtc1	$t9,$f8
/*  f15f678:	00000000 */ 	nop
/*  f15f67c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f680:	e52a0004 */ 	swc1	$f10,0x4($t1)
/*  f15f684:	848e0004 */ 	lh	$t6,0x4($a0)
/*  f15f688:	c5220004 */ 	lwc1	$f2,0x4($t1)
/*  f15f68c:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f15f690:	448e8000 */ 	mtc1	$t6,$f16
/*  f15f694:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15f698:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15f69c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f6a0:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f15f6a4:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f15f6a8:	e5320008 */ 	swc1	$f18,0x8($t1)
/*  f15f6ac:	c52c0008 */ 	lwc1	$f12,0x8($t1)
/*  f15f6b0:	e7ac00ac */ 	swc1	$f12,0xac($sp)
/*  f15f6b4:	1860003e */ 	blez	$v1,.L0f15f7b0
/*  f15f6b8:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
.L0f15f6bc:
/*  f15f6bc:	86b80000 */ 	lh	$t8,0x0($s5)
/*  f15f6c0:	26b5000c */ 	addiu	$s5,$s5,0xc
/*  f15f6c4:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f15f6c8:	44982000 */ 	mtc1	$t8,$f4
/*  f15f6cc:	00000000 */ 	nop
/*  f15f6d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f6d4:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f15f6d8:	86b9fff6 */ 	lh	$t9,-0xa($s5)
/*  f15f6dc:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15f6e0:	44994000 */ 	mtc1	$t9,$f8
/*  f15f6e4:	00000000 */ 	nop
/*  f15f6e8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f6ec:	e44a0004 */ 	swc1	$f10,0x4($v0)
/*  f15f6f0:	86aefff8 */ 	lh	$t6,-0x8($s5)
/*  f15f6f4:	448e8000 */ 	mtc1	$t6,$f16
/*  f15f6f8:	00000000 */ 	nop
/*  f15f6fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f700:	e4520008 */ 	swc1	$f18,0x8($v0)
/*  f15f704:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f15f708:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15f70c:	00000000 */ 	nop
/*  f15f710:	45020003 */ 	bc1fl	.L0f15f720
/*  f15f714:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15f718:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15f71c:	c4400004 */ 	lwc1	$f0,0x4($v0)
.L0f15f720:
/*  f15f720:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f15f724:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15f728:	00000000 */ 	nop
/*  f15f72c:	45020003 */ 	bc1fl	.L0f15f73c
/*  f15f730:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15f734:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15f738:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f15f73c:
/*  f15f73c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15f740:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15f744:	00000000 */ 	nop
/*  f15f748:	45020003 */ 	bc1fl	.L0f15f758
/*  f15f74c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15f750:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15f754:	c4400000 */ 	lwc1	$f0,0x0($v0)
.L0f15f758:
/*  f15f758:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f15f75c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15f760:	00000000 */ 	nop
/*  f15f764:	45020003 */ 	bc1fl	.L0f15f774
/*  f15f768:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15f76c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15f770:	c4400004 */ 	lwc1	$f0,0x4($v0)
.L0f15f774:
/*  f15f774:	c7b0009c */ 	lwc1	$f16,0x9c($sp)
/*  f15f778:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15f77c:	00000000 */ 	nop
/*  f15f780:	45020003 */ 	bc1fl	.L0f15f790
/*  f15f784:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15f788:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15f78c:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f15f790:
/*  f15f790:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f15f794:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15f798:	00000000 */ 	nop
/*  f15f79c:	45000002 */ 	bc1f	.L0f15f7a8
/*  f15f7a0:	00000000 */ 	nop
/*  f15f7a4:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
.L0f15f7a8:
/*  f15f7a8:	1c60ffc4 */ 	bgtz	$v1,.L0f15f6bc
/*  f15f7ac:	2442000c */ 	addiu	$v0,$v0,0xc
.L0f15f7b0:
/*  f15f7b0:	c6600000 */ 	lwc1	$f0,0x0($s3)
/*  f15f7b4:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f15f7b8:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f15f7bc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15f7c0:	00000000 */ 	nop
/*  f15f7c4:	45020009 */ 	bc1fl	.L0f15f7ec
/*  f15f7c8:	4600403c */ 	c.lt.s	$f8,$f0
/*  f15f7cc:	c6c60000 */ 	lwc1	$f6,0x0($s6)
/*  f15f7d0:	4604303c */ 	c.lt.s	$f6,$f4
/*  f15f7d4:	00000000 */ 	nop
/*  f15f7d8:	4502000e */ 	bc1fl	.L0f15f814
/*  f15f7dc:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f7e0:	1000000b */ 	b	.L0f15f810
/*  f15f7e4:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f7e8:	4600403c */ 	c.lt.s	$f8,$f0
.L0f15f7ec:
/*  f15f7ec:	00000000 */ 	nop
/*  f15f7f0:	45020008 */ 	bc1fl	.L0f15f814
/*  f15f7f4:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f7f8:	c6ca0000 */ 	lwc1	$f10,0x0($s6)
/*  f15f7fc:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15f800:	00000000 */ 	nop
/*  f15f804:	45020003 */ 	bc1fl	.L0f15f814
/*  f15f808:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f80c:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f810:
/*  f15f810:	c6600004 */ 	lwc1	$f0,0x4($s3)
.L0f15f814:
/*  f15f814:	c7b000a8 */ 	lwc1	$f16,0xa8($sp)
/*  f15f818:	4610003c */ 	c.lt.s	$f0,$f16
/*  f15f81c:	00000000 */ 	nop
/*  f15f820:	45020009 */ 	bc1fl	.L0f15f848
/*  f15f824:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f15f828:	c6d20004 */ 	lwc1	$f18,0x4($s6)
/*  f15f82c:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15f830:	00000000 */ 	nop
/*  f15f834:	4502000f */ 	bc1fl	.L0f15f874
/*  f15f838:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f83c:	1000000c */ 	b	.L0f15f870
/*  f15f840:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f844:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
.L0f15f848:
/*  f15f848:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15f84c:	00000000 */ 	nop
/*  f15f850:	45020008 */ 	bc1fl	.L0f15f874
/*  f15f854:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f858:	c6c40004 */ 	lwc1	$f4,0x4($s6)
/*  f15f85c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f15f860:	00000000 */ 	nop
/*  f15f864:	45020003 */ 	bc1fl	.L0f15f874
/*  f15f868:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f86c:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f870:
/*  f15f870:	c6600008 */ 	lwc1	$f0,0x8($s3)
.L0f15f874:
/*  f15f874:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15f878:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15f87c:	00000000 */ 	nop
/*  f15f880:	45020009 */ 	bc1fl	.L0f15f8a8
/*  f15f884:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f15f888:	c6ca0008 */ 	lwc1	$f10,0x8($s6)
/*  f15f88c:	4608503c */ 	c.lt.s	$f10,$f8
/*  f15f890:	00000000 */ 	nop
/*  f15f894:	4502000f */ 	bc1fl	.L0f15f8d4
/*  f15f898:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f89c:	1000000c */ 	b	.L0f15f8d0
/*  f15f8a0:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f8a4:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
.L0f15f8a8:
/*  f15f8a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15f8ac:	00000000 */ 	nop
/*  f15f8b0:	45020008 */ 	bc1fl	.L0f15f8d4
/*  f15f8b4:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f8b8:	c6d00008 */ 	lwc1	$f16,0x8($s6)
/*  f15f8bc:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15f8c0:	00000000 */ 	nop
/*  f15f8c4:	45020003 */ 	bc1fl	.L0f15f8d4
/*  f15f8c8:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f8cc:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f8d0:
/*  f15f8d0:	8faf00ec */ 	lw	$t7,0xec($sp)
.L0f15f8d4:
/*  f15f8d4:	11e001b1 */ 	beqz	$t7,.L0f15ff9c
/*  f15f8d8:	00000000 */ 	nop
/*  f15f8dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f15f8e0:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f15f8e4:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f15f8e8:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f15f8ec:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15f8f0:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15f8f4:	0fc57cac */ 	jal	bg0f15f2b0
/*  f15f8f8:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15f8fc:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15f900:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15f904:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15f908:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15f90c:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15f910:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15f914:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15f918:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f15f91c:	1000ff2e */ 	b	.L0f15f5d8
/*  f15f920:	258c0008 */ 	addiu	$t4,$t4,0x8
/*  f15f924:	2401fffd */ 	addiu	$at,$zero,-3
.L0f15f928:
/*  f15f928:	14410004 */ 	bne	$v0,$at,.L0f15f93c
/*  f15f92c:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f15f930:	01806825 */ 	or	$t5,$t4,$zero
/*  f15f934:	1000ff28 */ 	b	.L0f15f5d8
/*  f15f938:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f93c:
/*  f15f93c:	17000003 */ 	bnez	$t8,.L0f15f94c
/*  f15f940:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f15f944:	1000ff24 */ 	b	.L0f15f5d8
/*  f15f948:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f94c:
/*  f15f94c:	10410005 */ 	beq	$v0,$at,.L0f15f964
/*  f15f950:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f15f954:	50410004 */ 	beql	$v0,$at,.L0f15f968
/*  f15f958:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f15f95c:	1000ff1e */ 	b	.L0f15f5d8
/*  f15f960:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f964:
/*  f15f964:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f15f968:
/*  f15f968:	5441002e */ 	bnel	$v0,$at,.L0f15fa24
/*  f15f96c:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f15f970:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f15f974:	91990005 */ 	lbu	$t9,0x5($t4)
/*  f15f978:	0000b825 */ 	or	$s7,$zero,$zero
/*  f15f97c:	00004025 */ 	or	$t0,$zero,$zero
/*  f15f980:	0322001a */ 	div	$zero,$t9,$v0
/*  f15f984:	00007012 */ 	mflo	$t6
/*  f15f988:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f15f98c:	918f0006 */ 	lbu	$t7,0x6($t4)
/*  f15f990:	14400002 */ 	bnez	$v0,.L0f15f99c
/*  f15f994:	00000000 */ 	nop
/*  f15f998:	0007000d */ 	break	0x7
.L0f15f99c:
/*  f15f99c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15f9a0:	14410004 */ 	bne	$v0,$at,.L0f15f9b4
/*  f15f9a4:	3c018000 */ 	lui	$at,0x8000
/*  f15f9a8:	17210002 */ 	bne	$t9,$at,.L0f15f9b4
/*  f15f9ac:	00000000 */ 	nop
/*  f15f9b0:	0006000d */ 	break	0x6
.L0f15f9b4:
/*  f15f9b4:	01e2001a */ 	div	$zero,$t7,$v0
/*  f15f9b8:	0000c012 */ 	mflo	$t8
/*  f15f9bc:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f15f9c0:	91990007 */ 	lbu	$t9,0x7($t4)
/*  f15f9c4:	14400002 */ 	bnez	$v0,.L0f15f9d0
/*  f15f9c8:	00000000 */ 	nop
/*  f15f9cc:	0007000d */ 	break	0x7
.L0f15f9d0:
/*  f15f9d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15f9d4:	14410004 */ 	bne	$v0,$at,.L0f15f9e8
/*  f15f9d8:	3c018000 */ 	lui	$at,0x8000
/*  f15f9dc:	15e10002 */ 	bne	$t7,$at,.L0f15f9e8
/*  f15f9e0:	00000000 */ 	nop
/*  f15f9e4:	0006000d */ 	break	0x6
.L0f15f9e8:
/*  f15f9e8:	0322001a */ 	div	$zero,$t9,$v0
/*  f15f9ec:	00007012 */ 	mflo	$t6
/*  f15f9f0:	afae007c */ 	sw	$t6,0x7c($sp)
/*  f15f9f4:	14400002 */ 	bnez	$v0,.L0f15fa00
/*  f15f9f8:	00000000 */ 	nop
/*  f15f9fc:	0007000d */ 	break	0x7
.L0f15fa00:
/*  f15fa00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15fa04:	14410004 */ 	bne	$v0,$at,.L0f15fa18
/*  f15fa08:	3c018000 */ 	lui	$at,0x8000
/*  f15fa0c:	17210002 */ 	bne	$t9,$at,.L0f15fa18
/*  f15fa10:	00000000 */ 	nop
/*  f15fa14:	0006000d */ 	break	0x6
.L0f15fa18:
/*  f15fa18:	10000011 */ 	b	.L0f15fa60
/*  f15fa1c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f15fa20:	2401ffb1 */ 	addiu	$at,$zero,-79
.L0f15fa24:
/*  f15fa24:	5441000e */ 	bnel	$v0,$at,.L0f15fa60
/*  f15fa28:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f15fa2c:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*  f15fa30:	01809025 */ 	or	$s2,$t4,$zero
/*  f15fa34:	0160b825 */ 	or	$s7,$t3,$zero
/*  f15fa38:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15fa3c:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f15fa40:	91990007 */ 	lbu	$t9,0x7($t4)
/*  f15fa44:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15fa48:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15fa4c:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f15fa50:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f15fa54:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15fa58:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f15fa5c:	8fb90074 */ 	lw	$t9,0x74($sp)
.L0f15fa60:
/*  f15fa60:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f15fa64:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f15fa68:	17200005 */ 	bnez	$t9,.L0f15fa80
/*  f15fa6c:	00000000 */ 	nop
/*  f15fa70:	15c00003 */ 	bnez	$t6,.L0f15fa80
/*  f15fa74:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f15fa78:	11e00148 */ 	beqz	$t7,.L0f15ff9c
/*  f15fa7c:	00000000 */ 	nop
.L0f15fa80:
/*  f15fa80:	030b0019 */ 	multu	$t8,$t3
/*  f15fa84:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f15fa88:	0000c812 */ 	mflo	$t9
/*  f15fa8c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f15fa90:	01c92021 */ 	addu	$a0,$t6,$t1
/*  f15fa94:	01eb0019 */ 	multu	$t7,$t3
/*  f15fa98:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f15fa9c:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f15faa0:	00808825 */ 	or	$s1,$a0,$zero
/*  f15faa4:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f15faa8:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f15faac:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f15fab0:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f15fab4:	0000c012 */ 	mflo	$t8
/*  f15fab8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f15fabc:	03291021 */ 	addu	$v0,$t9,$t1
/*  f15fac0:	01cb0019 */ 	multu	$t6,$t3
/*  f15fac4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f15fac8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15facc:	4608503c */ 	c.lt.s	$f10,$f8
/*  f15fad0:	00007812 */ 	mflo	$t7
/*  f15fad4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f15fad8:	03091821 */ 	addu	$v1,$t8,$t1
/*  f15fadc:	45000003 */ 	bc1f	.L0f15faec
/*  f15fae0:	0060f025 */ 	or	$s8,$v1,$zero
/*  f15fae4:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f15fae8:	e7b200a4 */ 	swc1	$f18,0xa4($sp)
.L0f15faec:
/*  f15faec:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15faf0:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f15faf4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15faf8:	00000000 */ 	nop
/*  f15fafc:	45020003 */ 	bc1fl	.L0f15fb0c
/*  f15fb00:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f15fb04:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15fb08:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f15fb0c:
/*  f15fb0c:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f15fb10:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15fb14:	00000000 */ 	nop
/*  f15fb18:	45020004 */ 	bc1fl	.L0f15fb2c
/*  f15fb1c:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f15fb20:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15fb24:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f15fb28:	c7a40098 */ 	lwc1	$f4,0x98($sp)
.L0f15fb2c:
/*  f15fb2c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f15fb30:	00000000 */ 	nop
/*  f15fb34:	45020003 */ 	bc1fl	.L0f15fb44
/*  f15fb38:	c6600000 */ 	lwc1	$f0,0x0($s3)
/*  f15fb3c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15fb40:	c6600000 */ 	lwc1	$f0,0x0($s3)
.L0f15fb44:
/*  f15fb44:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f15fb48:	460a003c */ 	c.lt.s	$f0,$f10
/*  f15fb4c:	00000000 */ 	nop
/*  f15fb50:	45020007 */ 	bc1fl	.L0f15fb70
/*  f15fb54:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f15fb58:	c6c80000 */ 	lwc1	$f8,0x0($s6)
/*  f15fb5c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15fb60:	00000000 */ 	nop
/*  f15fb64:	450300e1 */ 	bc1tl	.L0f15feec
/*  f15fb68:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fb6c:	c7b20098 */ 	lwc1	$f18,0x98($sp)
.L0f15fb70:
/*  f15fb70:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15fb74:	00000000 */ 	nop
/*  f15fb78:	45020007 */ 	bc1fl	.L0f15fb98
/*  f15fb7c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f15fb80:	c6d00000 */ 	lwc1	$f16,0x0($s6)
/*  f15fb84:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15fb88:	00000000 */ 	nop
/*  f15fb8c:	450300d7 */ 	bc1tl	.L0f15feec
/*  f15fb90:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fb94:	c4860008 */ 	lwc1	$f6,0x8($a0)
.L0f15fb98:
/*  f15fb98:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f15fb9c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f15fba0:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15fba4:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*  f15fba8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15fbac:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15fbb0:	00000000 */ 	nop
/*  f15fbb4:	45020004 */ 	bc1fl	.L0f15fbc8
/*  f15fbb8:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f15fbbc:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15fbc0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15fbc4:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
.L0f15fbc8:
/*  f15fbc8:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15fbcc:	00000000 */ 	nop
/*  f15fbd0:	45020003 */ 	bc1fl	.L0f15fbe0
/*  f15fbd4:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f15fbd8:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f15fbdc:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f15fbe0:
/*  f15fbe0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f15fbe4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f15fbe8:	00000000 */ 	nop
/*  f15fbec:	45020004 */ 	bc1fl	.L0f15fc00
/*  f15fbf0:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f15fbf4:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15fbf8:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f15fbfc:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
.L0f15fc00:
/*  f15fc00:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15fc04:	00000000 */ 	nop
/*  f15fc08:	45020003 */ 	bc1fl	.L0f15fc18
/*  f15fc0c:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15fc10:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f15fc14:	c6600008 */ 	lwc1	$f0,0x8($s3)
.L0f15fc18:
/*  f15fc18:	c7a600ac */ 	lwc1	$f6,0xac($sp)
/*  f15fc1c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15fc20:	00000000 */ 	nop
/*  f15fc24:	45020007 */ 	bc1fl	.L0f15fc44
/*  f15fc28:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f15fc2c:	c6c40008 */ 	lwc1	$f4,0x8($s6)
/*  f15fc30:	4606203c */ 	c.lt.s	$f4,$f6
/*  f15fc34:	00000000 */ 	nop
/*  f15fc38:	450300ac */ 	bc1tl	.L0f15feec
/*  f15fc3c:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fc40:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
.L0f15fc44:
/*  f15fc44:	4600403c */ 	c.lt.s	$f8,$f0
/*  f15fc48:	00000000 */ 	nop
/*  f15fc4c:	45020007 */ 	bc1fl	.L0f15fc6c
/*  f15fc50:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f15fc54:	c6ca0008 */ 	lwc1	$f10,0x8($s6)
/*  f15fc58:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15fc5c:	00000000 */ 	nop
/*  f15fc60:	450300a2 */ 	bc1tl	.L0f15feec
/*  f15fc64:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fc68:	c4920004 */ 	lwc1	$f18,0x4($a0)
.L0f15fc6c:
/*  f15fc6c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f15fc70:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f15fc74:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f15fc78:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f15fc7c:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15fc80:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15fc84:	00000000 */ 	nop
/*  f15fc88:	45020004 */ 	bc1fl	.L0f15fc9c
/*  f15fc8c:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f15fc90:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15fc94:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15fc98:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
.L0f15fc9c:
/*  f15fc9c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15fca0:	00000000 */ 	nop
/*  f15fca4:	45020003 */ 	bc1fl	.L0f15fcb4
/*  f15fca8:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f15fcac:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15fcb0:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f15fcb4:
/*  f15fcb4:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f15fcb8:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15fcbc:	00000000 */ 	nop
/*  f15fcc0:	45020004 */ 	bc1fl	.L0f15fcd4
/*  f15fcc4:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f15fcc8:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15fccc:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f15fcd0:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
.L0f15fcd4:
/*  f15fcd4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15fcd8:	00000000 */ 	nop
/*  f15fcdc:	45020003 */ 	bc1fl	.L0f15fcec
/*  f15fce0:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15fce4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15fce8:	c6600004 */ 	lwc1	$f0,0x4($s3)
.L0f15fcec:
/*  f15fcec:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f15fcf0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f15fcf4:	00000000 */ 	nop
/*  f15fcf8:	45020007 */ 	bc1fl	.L0f15fd18
/*  f15fcfc:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f15fd00:	c6d00004 */ 	lwc1	$f16,0x4($s6)
/*  f15fd04:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15fd08:	00000000 */ 	nop
/*  f15fd0c:	45030077 */ 	bc1tl	.L0f15feec
/*  f15fd10:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fd14:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
.L0f15fd18:
/*  f15fd18:	4600203c */ 	c.lt.s	$f4,$f0
/*  f15fd1c:	00000000 */ 	nop
/*  f15fd20:	45020007 */ 	bc1fl	.L0f15fd40
/*  f15fd24:	02602025 */ 	or	$a0,$s3,$zero
/*  f15fd28:	c6c60004 */ 	lwc1	$f6,0x4($s6)
/*  f15fd2c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f15fd30:	00000000 */ 	nop
/*  f15fd34:	4503006d */ 	bc1tl	.L0f15feec
/*  f15fd38:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fd3c:	02602025 */ 	or	$a0,$s3,$zero
.L0f15fd40:
/*  f15fd40:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f15fd44:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f15fd48:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f15fd4c:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15fd50:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15fd54:	0fc57cac */ 	jal	bg0f15f2b0
/*  f15fd58:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15fd5c:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15fd60:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15fd64:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15fd68:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15fd6c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15fd70:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15fd74:	1040005c */ 	beqz	$v0,.L0f15fee8
/*  f15fd78:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15fd7c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f15fd80:	27ae008c */ 	addiu	$t6,$sp,0x8c
/*  f15fd84:	27af0080 */ 	addiu	$t7,$sp,0x80
/*  f15fd88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f15fd8c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f15fd90:	02202025 */ 	or	$a0,$s1,$zero
/*  f15fd94:	02802825 */ 	or	$a1,$s4,$zero
/*  f15fd98:	03c03025 */ 	or	$a2,$s8,$zero
/*  f15fd9c:	00003825 */ 	or	$a3,$zero,$zero
/*  f15fda0:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f15fda4:	afb60014 */ 	sw	$s6,0x14($sp)
/*  f15fda8:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15fdac:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15fdb0:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15fdb4:	0c00bd58 */ 	jal	func0002f560
/*  f15fdb8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f15fdbc:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15fdc0:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15fdc4:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15fdc8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15fdcc:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15fdd0:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15fdd4:	10400044 */ 	beqz	$v0,.L0f15fee8
/*  f15fdd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15fddc:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f15fde0:	c66a0000 */ 	lwc1	$f10,0x0($s3)
/*  f15fde4:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f15fde8:	c6720004 */ 	lwc1	$f18,0x4($s3)
/*  f15fdec:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f15fdf0:	c6680008 */ 	lwc1	$f8,0x8($s3)
/*  f15fdf4:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f15fdf8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f15fdfc:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f15fe00:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f15fe04:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f15fe08:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f15fe0c:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f15fe10:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f15fe14:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f15fe18:	4614103c */ 	c.lt.s	$f2,$f20
/*  f15fe1c:	00000000 */ 	nop
/*  f15fe20:	45020032 */ 	bc1fl	.L0f15feec
/*  f15fe24:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fe28:	11a0000a */ 	beqz	$t5,.L0f15fe54
/*  f15fe2c:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f15fe30:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f15fe34:	3c030f00 */ 	lui	$v1,0xf00
/*  f15fe38:	0043c824 */ 	and	$t9,$v0,$v1
/*  f15fe3c:	10790005 */ 	beq	$v1,$t9,.L0f15fe54
/*  f15fe40:	00000000 */ 	nop
/*  f15fe44:	3c030500 */ 	lui	$v1,0x500
/*  f15fe48:	00437024 */ 	and	$t6,$v0,$v1
/*  f15fe4c:	146e0003 */ 	bne	$v1,$t6,.L0f15fe5c
/*  f15fe50:	3c018000 */ 	lui	$at,0x8000
.L0f15fe54:
/*  f15fe54:	10000005 */ 	b	.L0f15fe6c
/*  f15fe58:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f15fe5c:
/*  f15fe5c:	2443fff8 */ 	addiu	$v1,$v0,-8
/*  f15fe60:	00617825 */ 	or	$t7,$v1,$at
/*  f15fe64:	01e01825 */ 	or	$v1,$t7,$zero
/*  f15fe68:	85e40000 */ 	lh	$a0,0x0($t7)
.L0f15fe6c:
/*  f15fe6c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f15fe70:	46001506 */ 	mov.s	$f20,$f2
/*  f15fe74:	e6100000 */ 	swc1	$f16,0x0($s0)
/*  f15fe78:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f15fe7c:	e6120004 */ 	swc1	$f18,0x4($s0)
/*  f15fe80:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f15fe84:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f15fe88:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f15fe8c:	e606000c */ 	swc1	$f6,0xc($s0)
/*  f15fe90:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f15fe94:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f15fe98:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f15fe9c:	e60a0014 */ 	swc1	$f10,0x14($s0)
/*  f15fea0:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f15fea4:	030a0019 */ 	multu	$t8,$t2
/*  f15fea8:	0000c812 */ 	mflo	$t9
/*  f15feac:	03357021 */ 	addu	$t6,$t9,$s5
/*  f15feb0:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f15feb4:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f15feb8:	01ea0019 */ 	multu	$t7,$t2
/*  f15febc:	0000c012 */ 	mflo	$t8
/*  f15fec0:	0315c821 */ 	addu	$t9,$t8,$s5
/*  f15fec4:	ae19001c */ 	sw	$t9,0x1c($s0)
/*  f15fec8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f15fecc:	a604002a */ 	sh	$a0,0x2a($s0)
/*  f15fed0:	ae0c0024 */ 	sw	$t4,0x24($s0)
/*  f15fed4:	01ca0019 */ 	multu	$t6,$t2
/*  f15fed8:	a6080028 */ 	sh	$t0,0x28($s0)
/*  f15fedc:	00007812 */ 	mflo	$t7
/*  f15fee0:	01f5c021 */ 	addu	$t8,$t7,$s5
/*  f15fee4:	ae180020 */ 	sw	$t8,0x20($s0)
.L0f15fee8:
/*  f15fee8:	26f7ffff */ 	addiu	$s7,$s7,-1
.L0f15feec:
/*  f15feec:	24010002 */ 	addiu	$at,$zero,0x2
/*  f15fef0:	56e1000d */ 	bnel	$s7,$at,.L0f15ff28
/*  f15fef4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15fef8:	92590006 */ 	lbu	$t9,0x6($s2)
/*  f15fefc:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f15ff00:	332e000f */ 	andi	$t6,$t9,0xf
/*  f15ff04:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f15ff08:	964f0006 */ 	lhu	$t7,0x6($s2)
/*  f15ff0c:	000fc302 */ 	srl	$t8,$t7,0xc
/*  f15ff10:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f15ff14:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f15ff18:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15ff1c:	1000001d */ 	b	.L0f15ff94
/*  f15ff20:	afae007c */ 	sw	$t6,0x7c($sp)
/*  f15ff24:	24010001 */ 	addiu	$at,$zero,0x1
.L0f15ff28:
/*  f15ff28:	16e1000e */ 	bne	$s7,$at,.L0f15ff64
/*  f15ff2c:	00000000 */ 	nop
/*  f15ff30:	964f0004 */ 	lhu	$t7,0x4($s2)
/*  f15ff34:	000b4400 */ 	sll	$t0,$t3,0x10
/*  f15ff38:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15ff3c:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f15ff40:	92590005 */ 	lbu	$t9,0x5($s2)
/*  f15ff44:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15ff48:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f15ff4c:	924f0002 */ 	lbu	$t7,0x2($s2)
/*  f15ff50:	0008cc03 */ 	sra	$t9,$t0,0x10
/*  f15ff54:	03204025 */ 	or	$t0,$t9,$zero
/*  f15ff58:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15ff5c:	1000000d */ 	b	.L0f15ff94
/*  f15ff60:	afb8007c */ 	sw	$t8,0x7c($sp)
.L0f15ff64:
/*  f15ff64:	16e0000b */ 	bnez	$s7,.L0f15ff94
/*  f15ff68:	00000000 */ 	nop
/*  f15ff6c:	924e0004 */ 	lbu	$t6,0x4($s2)
/*  f15ff70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15ff74:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f15ff78:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f15ff7c:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f15ff80:	0018cf02 */ 	srl	$t9,$t8,0x1c
/*  f15ff84:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f15ff88:	964e0002 */ 	lhu	$t6,0x2($s2)
/*  f15ff8c:	000e7b02 */ 	srl	$t7,$t6,0xc
/*  f15ff90:	afaf007c */ 	sw	$t7,0x7c($sp)
.L0f15ff94:
/*  f15ff94:	06e3feb2 */ 	bgezl	$s7,.L0f15fa60
/*  f15ff98:	8fb90074 */ 	lw	$t9,0x74($sp)
.L0f15ff9c:
/*  f15ff9c:	1000fd8e */ 	b	.L0f15f5d8
/*  f15ffa0:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15ffa4:
/*  f15ffa4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f15ffa8:	8fa200dc */ 	lw	$v0,0xdc($sp)
/*  f15ffac:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f15ffb0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f15ffb4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f15ffb8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f15ffbc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f15ffc0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f15ffc4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f15ffc8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f15ffcc:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f15ffd0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f15ffd4:	03e00008 */ 	jr	$ra
/*  f15ffd8:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

GLOBAL_ASM(
glabel func0f15ffdc
/*  f15ffdc:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f15ffe0:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f15ffe4:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f15ffe8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f15ffec:	00c0b825 */ 	or	$s7,$a2,$zero
/*  f15fff0:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f15fff4:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f15fff8:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f15fffc:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f160000:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f160004:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f160008:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f16000c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f160010:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f160014:	afa400f0 */ 	sw	$a0,0xf0($sp)
/*  f160018:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f16001c:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f160020:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f160024:	afa000cc */ 	sw	$zero,0xcc($sp)
/*  f160028:	8fb20110 */ 	lw	$s2,0x110($sp)
/*  f16002c:	8fb300e8 */ 	lw	$s3,0xe8($sp)
/*  f160030:	8fb400ac */ 	lw	$s4,0xac($sp)
/*  f160034:	8fb600c0 */ 	lw	$s6,0xc0($sp)
/*  f160038:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f16003c:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f160040:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160044:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f160048:
/*  f160048:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f16004c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f160050:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f160054:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f160058:	54410007 */ 	bnel	$v0,$at,.L0f160078
/*  f16005c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f160060:	53000269 */ 	beqzl	$t8,.L0f160a08
/*  f160064:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f160068:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f16006c:	1000fff6 */ 	b	.L0f160048
/*  f160070:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f160074:	24010001 */ 	addiu	$at,$zero,0x1
.L0f160078:
/*  f160078:	1441000d */ 	bne	$v0,$at,.L0f1600b0
/*  f16007c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160080:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f160084:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f160088:	3c0100ff */ 	lui	$at,0xff
/*  f16008c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f160090:	8d4b000c */ 	lw	$t3,0xc($t2)
/*  f160094:	00814824 */ 	and	$t1,$a0,$at
/*  f160098:	00099982 */ 	srl	$s3,$t1,0x6
/*  f16009c:	00136180 */ 	sll	$t4,$s3,0x6
/*  f1600a0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f1600a4:	01202025 */ 	or	$a0,$t1,$zero
/*  f1600a8:	10000252 */ 	b	.L0f1609f4
/*  f1600ac:	afad00a8 */ 	sw	$t5,0xa8($sp)
.L0f1600b0:
/*  f1600b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1600b4:	144100c7 */ 	bne	$v0,$at,.L0f1603d4
/*  f1600b8:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f1600bc:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f1600c0:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f1600c4:	3c0100ff */ 	lui	$at,0xff
/*  f1600c8:	90a20001 */ 	lbu	$v0,0x1($a1)
/*  f1600cc:	8ca40004 */ 	lw	$a0,0x4($a1)
/*  f1600d0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1600d4:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f1600d8:	3043000f */ 	andi	$v1,$v0,0xf
/*  f1600dc:	00817024 */ 	and	$t6,$a0,$at
/*  f1600e0:	0078082a */ 	slt	$at,$v1,$t8
/*  f1600e4:	00028902 */ 	srl	$s1,$v0,0x4
/*  f1600e8:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1600ec:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1600f0:	10200002 */ 	beqz	$at,.L0f1600fc
/*  f1600f4:	01eeb021 */ 	addu	$s6,$t7,$t6
/*  f1600f8:	afa300dc */ 	sw	$v1,0xdc($sp)
.L0f1600fc:
/*  f1600fc:	8fb300dc */ 	lw	$s3,0xdc($sp)
/*  f160100:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f160104:	3c0a800a */ 	lui	$t2,%hi(var800a6470)
/*  f160108:	254a6470 */ 	addiu	$t2,$t2,%lo(var800a6470)
/*  f16010c:	00134880 */ 	sll	$t1,$s3,0x2
/*  f160110:	012af021 */ 	addu	$s8,$t1,$t2
/*  f160114:	02231021 */ 	addu	$v0,$s1,$v1
/*  f160118:	27cb000c */ 	addiu	$t3,$s8,0xc
/*  f16011c:	0182082a */ 	slt	$at,$t4,$v0
/*  f160120:	10200002 */ 	beqz	$at,.L0f16012c
/*  f160124:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f160128:	afa200d8 */ 	sw	$v0,0xd8($sp)
.L0f16012c:
/*  f16012c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f160130:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f160134:	3c0f800a */ 	lui	$t7,%hi(var800a6470)
/*  f160138:	25ef6470 */ 	addiu	$t7,$t7,%lo(var800a6470)
/*  f16013c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f160140:	1a200019 */ 	blez	$s1,.L0f1601a8
/*  f160144:	01cf8021 */ 	addu	$s0,$t6,$t7
.L0f160148:
/*  f160148:	86d80000 */ 	lh	$t8,0x0($s6)
/*  f16014c:	02002825 */ 	or	$a1,$s0,$zero
/*  f160150:	44982000 */ 	mtc1	$t8,$f4
/*  f160154:	00000000 */ 	nop
/*  f160158:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16015c:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f160160:	86c90002 */ 	lh	$t1,0x2($s6)
/*  f160164:	44894000 */ 	mtc1	$t1,$f8
/*  f160168:	00000000 */ 	nop
/*  f16016c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f160170:	e60a0004 */ 	swc1	$f10,0x4($s0)
/*  f160174:	86ca0004 */ 	lh	$t2,0x4($s6)
/*  f160178:	448a8000 */ 	mtc1	$t2,$f16
/*  f16017c:	00000000 */ 	nop
/*  f160180:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f160184:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f160188:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f16018c:	0c0056d9 */ 	jal	mtx4TransformVecInPlace
/*  f160190:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f160194:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f160198:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f16019c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1601a0:	1e20ffe9 */ 	bgtz	$s1,.L0f160148
/*  f1601a4:	26d6000c */ 	addiu	$s6,$s6,0xc
.L0f1601a8:
/*  f1601a8:	8fa200d8 */ 	lw	$v0,0xd8($sp)
/*  f1601ac:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f1601b0:	c7c00000 */ 	lwc1	$f0,0x0($s8)
/*  f1601b4:	c7c20004 */ 	lwc1	$f2,0x4($s8)
/*  f1601b8:	c7cc0008 */ 	lwc1	$f12,0x8($s8)
/*  f1601bc:	0162082a */ 	slt	$at,$t3,$v0
/*  f1601c0:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f1601c4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f1601c8:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f1601cc:	e7a200a0 */ 	swc1	$f2,0xa0($sp)
/*  f1601d0:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f1601d4:	e7ac00a4 */ 	swc1	$f12,0xa4($sp)
/*  f1601d8:	1020002e */ 	beqz	$at,.L0f160294
/*  f1601dc:	e7ac0098 */ 	swc1	$f12,0x98($sp)
.L0f1601e0:
/*  f1601e0:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f1601e4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f1601e8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1601ec:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1601f0:	00000000 */ 	nop
/*  f1601f4:	45020003 */ 	bc1fl	.L0f160204
/*  f1601f8:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f1601fc:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160200:	c6000004 */ 	lwc1	$f0,0x4($s0)
.L0f160204:
/*  f160204:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f160208:	4606003c */ 	c.lt.s	$f0,$f6
/*  f16020c:	00000000 */ 	nop
/*  f160210:	45020003 */ 	bc1fl	.L0f160220
/*  f160214:	c6000008 */ 	lwc1	$f0,0x8($s0)
/*  f160218:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f16021c:	c6000008 */ 	lwc1	$f0,0x8($s0)
.L0f160220:
/*  f160220:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160224:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160228:	00000000 */ 	nop
/*  f16022c:	45020003 */ 	bc1fl	.L0f16023c
/*  f160230:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f160234:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f160238:	c6000000 */ 	lwc1	$f0,0x0($s0)
.L0f16023c:
/*  f16023c:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f160240:	4600503c */ 	c.lt.s	$f10,$f0
/*  f160244:	00000000 */ 	nop
/*  f160248:	45020003 */ 	bc1fl	.L0f160258
/*  f16024c:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f160250:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160254:	c6000004 */ 	lwc1	$f0,0x4($s0)
.L0f160258:
/*  f160258:	c7b00094 */ 	lwc1	$f16,0x94($sp)
/*  f16025c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f160260:	00000000 */ 	nop
/*  f160264:	45020003 */ 	bc1fl	.L0f160274
/*  f160268:	c6000008 */ 	lwc1	$f0,0x8($s0)
/*  f16026c:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160270:	c6000008 */ 	lwc1	$f0,0x8($s0)
.L0f160274:
/*  f160274:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160278:	4600903c */ 	c.lt.s	$f18,$f0
/*  f16027c:	00000000 */ 	nop
/*  f160280:	45000002 */ 	bc1f	.L0f16028c
/*  f160284:	00000000 */ 	nop
/*  f160288:	e7a00098 */ 	swc1	$f0,0x98($sp)
.L0f16028c:
/*  f16028c:	1662ffd4 */ 	bne	$s3,$v0,.L0f1601e0
/*  f160290:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f160294:
/*  f160294:	c6a00000 */ 	lwc1	$f0,0x0($s5)
/*  f160298:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f16029c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1602a0:	00000000 */ 	nop
/*  f1602a4:	45020007 */ 	bc1fl	.L0f1602c4
/*  f1602a8:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f1602ac:	c6e60000 */ 	lwc1	$f6,0x0($s7)
/*  f1602b0:	4604303c */ 	c.lt.s	$f6,$f4
/*  f1602b4:	00000000 */ 	nop
/*  f1602b8:	45030038 */ 	bc1tl	.L0f16039c
/*  f1602bc:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f1602c0:	c7a80090 */ 	lwc1	$f8,0x90($sp)
.L0f1602c4:
/*  f1602c4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f1602c8:	00000000 */ 	nop
/*  f1602cc:	45020007 */ 	bc1fl	.L0f1602ec
/*  f1602d0:	c6a00004 */ 	lwc1	$f0,0x4($s5)
/*  f1602d4:	c6ea0000 */ 	lwc1	$f10,0x0($s7)
/*  f1602d8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f1602dc:	00000000 */ 	nop
/*  f1602e0:	4503002e */ 	bc1tl	.L0f16039c
/*  f1602e4:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f1602e8:	c6a00004 */ 	lwc1	$f0,0x4($s5)
.L0f1602ec:
/*  f1602ec:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f1602f0:	4610003c */ 	c.lt.s	$f0,$f16
/*  f1602f4:	00000000 */ 	nop
/*  f1602f8:	45020007 */ 	bc1fl	.L0f160318
/*  f1602fc:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f160300:	c6f20004 */ 	lwc1	$f18,0x4($s7)
/*  f160304:	4610903c */ 	c.lt.s	$f18,$f16
/*  f160308:	00000000 */ 	nop
/*  f16030c:	45030023 */ 	bc1tl	.L0f16039c
/*  f160310:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f160314:	c7a60094 */ 	lwc1	$f6,0x94($sp)
.L0f160318:
/*  f160318:	4600303c */ 	c.lt.s	$f6,$f0
/*  f16031c:	00000000 */ 	nop
/*  f160320:	45020007 */ 	bc1fl	.L0f160340
/*  f160324:	c6a00008 */ 	lwc1	$f0,0x8($s5)
/*  f160328:	c6e40004 */ 	lwc1	$f4,0x4($s7)
/*  f16032c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160330:	00000000 */ 	nop
/*  f160334:	45030019 */ 	bc1tl	.L0f16039c
/*  f160338:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f16033c:	c6a00008 */ 	lwc1	$f0,0x8($s5)
.L0f160340:
/*  f160340:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160344:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160348:	00000000 */ 	nop
/*  f16034c:	45020007 */ 	bc1fl	.L0f16036c
/*  f160350:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160354:	c6ea0008 */ 	lwc1	$f10,0x8($s7)
/*  f160358:	4608503c */ 	c.lt.s	$f10,$f8
/*  f16035c:	00000000 */ 	nop
/*  f160360:	4503000e */ 	bc1tl	.L0f16039c
/*  f160364:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f160368:	c7b20098 */ 	lwc1	$f18,0x98($sp)
.L0f16036c:
/*  f16036c:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f160370:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f160374:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160378:	00000000 */ 	nop
/*  f16037c:	4502000c */ 	bc1fl	.L0f1603b0
/*  f160380:	02a02025 */ 	or	$a0,$s5,$zero
/*  f160384:	c6f00008 */ 	lwc1	$f16,0x8($s7)
/*  f160388:	4610903c */ 	c.lt.s	$f18,$f16
/*  f16038c:	00000000 */ 	nop
/*  f160390:	45020007 */ 	bc1fl	.L0f1603b0
/*  f160394:	02a02025 */ 	or	$a0,$s5,$zero
/*  f160398:	afa000e4 */ 	sw	$zero,0xe4($sp)
.L0f16039c:
/*  f16039c:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1603a0:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1603a4:	10000193 */ 	b	.L0f1609f4
/*  f1603a8:	2403000a */ 	addiu	$v1,$zero,0xa
/*  f1603ac:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1603b0:
/*  f1603b0:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f1603b4:	0fc57cac */ 	jal	bg0f15f2b0
/*  f1603b8:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f1603bc:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f1603c0:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f1603c4:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1603c8:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1603cc:	10000189 */ 	b	.L0f1609f4
/*  f1603d0:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f1603d4:
/*  f1603d4:	17200005 */ 	bnez	$t9,.L0f1603ec
/*  f1603d8:	00000000 */ 	nop
/*  f1603dc:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f1603e0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1603e4:	1000ff18 */ 	b	.L0f160048
/*  f1603e8:	afad0100 */ 	sw	$t5,0x100($sp)
.L0f1603ec:
/*  f1603ec:	10a20007 */ 	beq	$a1,$v0,.L0f16040c
/*  f1603f0:	00000000 */ 	nop
/*  f1603f4:	10c20005 */ 	beq	$a2,$v0,.L0f16040c
/*  f1603f8:	00000000 */ 	nop
/*  f1603fc:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f160400:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f160404:	1000ff10 */ 	b	.L0f160048
/*  f160408:	afaf0100 */ 	sw	$t7,0x100($sp)
.L0f16040c:
/*  f16040c:	14a2002d */ 	bne	$a1,$v0,.L0f1604c4
/*  f160410:	00000000 */ 	nop
/*  f160414:	8fa20100 */ 	lw	$v0,0x100($sp)
/*  f160418:	00009825 */ 	or	$s3,$zero,$zero
/*  f16041c:	00004025 */ 	or	$t0,$zero,$zero
/*  f160420:	90580005 */ 	lbu	$t8,0x5($v0)
/*  f160424:	0303001a */ 	div	$zero,$t8,$v1
/*  f160428:	00004812 */ 	mflo	$t1
/*  f16042c:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f160430:	904a0006 */ 	lbu	$t2,0x6($v0)
/*  f160434:	14600002 */ 	bnez	$v1,.L0f160440
/*  f160438:	00000000 */ 	nop
/*  f16043c:	0007000d */ 	break	0x7
.L0f160440:
/*  f160440:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160444:	14610004 */ 	bne	$v1,$at,.L0f160458
/*  f160448:	3c018000 */ 	lui	$at,0x8000
/*  f16044c:	17010002 */ 	bne	$t8,$at,.L0f160458
/*  f160450:	00000000 */ 	nop
/*  f160454:	0006000d */ 	break	0x6
.L0f160458:
/*  f160458:	0143001a */ 	div	$zero,$t2,$v1
/*  f16045c:	00005812 */ 	mflo	$t3
/*  f160460:	afab0070 */ 	sw	$t3,0x70($sp)
/*  f160464:	90590007 */ 	lbu	$t9,0x7($v0)
/*  f160468:	14600002 */ 	bnez	$v1,.L0f160474
/*  f16046c:	00000000 */ 	nop
/*  f160470:	0007000d */ 	break	0x7
.L0f160474:
/*  f160474:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160478:	14610004 */ 	bne	$v1,$at,.L0f16048c
/*  f16047c:	3c018000 */ 	lui	$at,0x8000
/*  f160480:	15410002 */ 	bne	$t2,$at,.L0f16048c
/*  f160484:	00000000 */ 	nop
/*  f160488:	0006000d */ 	break	0x6
.L0f16048c:
/*  f16048c:	0323001a */ 	div	$zero,$t9,$v1
/*  f160490:	00006012 */ 	mflo	$t4
/*  f160494:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f160498:	14600002 */ 	bnez	$v1,.L0f1604a4
/*  f16049c:	00000000 */ 	nop
/*  f1604a0:	0007000d */ 	break	0x7
.L0f1604a4:
/*  f1604a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1604a8:	14610004 */ 	bne	$v1,$at,.L0f1604bc
/*  f1604ac:	3c018000 */ 	lui	$at,0x8000
/*  f1604b0:	17210002 */ 	bne	$t9,$at,.L0f1604bc
/*  f1604b4:	00000000 */ 	nop
/*  f1604b8:	0006000d */ 	break	0x6
.L0f1604bc:
/*  f1604bc:	10000010 */ 	b	.L0f160500
/*  f1604c0:	00000000 */ 	nop
.L0f1604c4:
/*  f1604c4:	14c2000e */ 	bne	$a2,$v0,.L0f160500
/*  f1604c8:	00000000 */ 	nop
/*  f1604cc:	8fad0100 */ 	lw	$t5,0x100($sp)
/*  f1604d0:	24130003 */ 	addiu	$s3,$zero,0x3
/*  f1604d4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1604d8:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f1604dc:	01a0a025 */ 	or	$s4,$t5,$zero
/*  f1604e0:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f1604e4:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f1604e8:	91b80007 */ 	lbu	$t8,0x7($t5)
/*  f1604ec:	00184902 */ 	srl	$t1,$t8,0x4
/*  f1604f0:	afa90070 */ 	sw	$t1,0x70($sp)
/*  f1604f4:	8daa0000 */ 	lw	$t2,0x0($t5)
/*  f1604f8:	314b000f */ 	andi	$t3,$t2,0xf
/*  f1604fc:	afab0074 */ 	sw	$t3,0x74($sp)
.L0f160500:
/*  f160500:	8fb9006c */ 	lw	$t9,0x6c($sp)
.L0f160504:
/*  f160504:	2403000a */ 	addiu	$v1,$zero,0xa
/*  f160508:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f16050c:	17200009 */ 	bnez	$t9,.L0f160534
/*  f160510:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f160514:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f160518:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f16051c:	55800006 */ 	bnezl	$t4,.L0f160538
/*  f160520:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f160524:	55c00004 */ 	bnezl	$t6,.L0f160538
/*  f160528:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f16052c:	10000132 */ 	b	.L0f1609f8
/*  f160530:	8fac0100 */ 	lw	$t4,0x100($sp)
.L0f160534:
/*  f160534:	8faf006c */ 	lw	$t7,0x6c($sp)
.L0f160538:
/*  f160538:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f16053c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f160540:	01e60019 */ 	multu	$t7,$a2
/*  f160544:	3c05800a */ 	lui	$a1,%hi(var800a6470)
/*  f160548:	24a56470 */ 	addiu	$a1,$a1,%lo(var800a6470)
/*  f16054c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f160550:	0000c012 */ 	mflo	$t8
/*  f160554:	00184880 */ 	sll	$t1,$t8,0x2
/*  f160558:	01252021 */ 	addu	$a0,$t1,$a1
/*  f16055c:	01a60019 */ 	multu	$t5,$a2
/*  f160560:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f160564:	00808025 */ 	or	$s0,$a0,$zero
/*  f160568:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f16056c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f160570:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f160574:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f160578:	00005012 */ 	mflo	$t2
/*  f16057c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f160580:	01651021 */ 	addu	$v0,$t3,$a1
/*  f160584:	03260019 */ 	multu	$t9,$a2
/*  f160588:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f16058c:	00408825 */ 	or	$s1,$v0,$zero
/*  f160590:	4608503c */ 	c.lt.s	$f10,$f8
/*  f160594:	00006012 */ 	mflo	$t4
/*  f160598:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f16059c:	01c51821 */ 	addu	$v1,$t6,$a1
/*  f1605a0:	45000003 */ 	bc1f	.L0f1605b0
/*  f1605a4:	0060f025 */ 	or	$s8,$v1,$zero
/*  f1605a8:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f1605ac:	e7b2009c */ 	swc1	$f18,0x9c($sp)
.L0f1605b0:
/*  f1605b0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f1605b4:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f1605b8:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1605bc:	00000000 */ 	nop
/*  f1605c0:	45020003 */ 	bc1fl	.L0f1605d0
/*  f1605c4:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f1605c8:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f1605cc:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f1605d0:
/*  f1605d0:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f1605d4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1605d8:	00000000 */ 	nop
/*  f1605dc:	45020004 */ 	bc1fl	.L0f1605f0
/*  f1605e0:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f1605e4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f1605e8:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f1605ec:	c7a40090 */ 	lwc1	$f4,0x90($sp)
.L0f1605f0:
/*  f1605f0:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1605f4:	00000000 */ 	nop
/*  f1605f8:	45020003 */ 	bc1fl	.L0f160608
/*  f1605fc:	c6a00000 */ 	lwc1	$f0,0x0($s5)
/*  f160600:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160604:	c6a00000 */ 	lwc1	$f0,0x0($s5)
.L0f160608:
/*  f160608:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f16060c:	460a003c */ 	c.lt.s	$f0,$f10
/*  f160610:	00000000 */ 	nop
/*  f160614:	45020007 */ 	bc1fl	.L0f160634
/*  f160618:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f16061c:	c6e80000 */ 	lwc1	$f8,0x0($s7)
/*  f160620:	460a403c */ 	c.lt.s	$f8,$f10
/*  f160624:	00000000 */ 	nop
/*  f160628:	450300c5 */ 	bc1tl	.L0f160940
/*  f16062c:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160630:	c7b20090 */ 	lwc1	$f18,0x90($sp)
.L0f160634:
/*  f160634:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160638:	00000000 */ 	nop
/*  f16063c:	45020007 */ 	bc1fl	.L0f16065c
/*  f160640:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f160644:	c6f00000 */ 	lwc1	$f16,0x0($s7)
/*  f160648:	4610903c */ 	c.lt.s	$f18,$f16
/*  f16064c:	00000000 */ 	nop
/*  f160650:	450300bb */ 	bc1tl	.L0f160940
/*  f160654:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160658:	c4860008 */ 	lwc1	$f6,0x8($a0)
.L0f16065c:
/*  f16065c:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f160660:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f160664:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160668:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f16066c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160670:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160674:	00000000 */ 	nop
/*  f160678:	45020004 */ 	bc1fl	.L0f16068c
/*  f16067c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f160680:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f160684:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160688:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
.L0f16068c:
/*  f16068c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f160690:	00000000 */ 	nop
/*  f160694:	45020003 */ 	bc1fl	.L0f1606a4
/*  f160698:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f16069c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f1606a0:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f1606a4:
/*  f1606a4:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f1606a8:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1606ac:	00000000 */ 	nop
/*  f1606b0:	45020004 */ 	bc1fl	.L0f1606c4
/*  f1606b4:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f1606b8:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f1606bc:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f1606c0:	c7b00098 */ 	lwc1	$f16,0x98($sp)
.L0f1606c4:
/*  f1606c4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1606c8:	00000000 */ 	nop
/*  f1606cc:	45020003 */ 	bc1fl	.L0f1606dc
/*  f1606d0:	c6a00008 */ 	lwc1	$f0,0x8($s5)
/*  f1606d4:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f1606d8:	c6a00008 */ 	lwc1	$f0,0x8($s5)
.L0f1606dc:
/*  f1606dc:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f1606e0:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1606e4:	00000000 */ 	nop
/*  f1606e8:	45020007 */ 	bc1fl	.L0f160708
/*  f1606ec:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f1606f0:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f1606f4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1606f8:	00000000 */ 	nop
/*  f1606fc:	45030090 */ 	bc1tl	.L0f160940
/*  f160700:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160704:	c7a80098 */ 	lwc1	$f8,0x98($sp)
.L0f160708:
/*  f160708:	4600403c */ 	c.lt.s	$f8,$f0
/*  f16070c:	00000000 */ 	nop
/*  f160710:	45020007 */ 	bc1fl	.L0f160730
/*  f160714:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f160718:	c6ea0008 */ 	lwc1	$f10,0x8($s7)
/*  f16071c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f160720:	00000000 */ 	nop
/*  f160724:	45030086 */ 	bc1tl	.L0f160940
/*  f160728:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f16072c:	c4920004 */ 	lwc1	$f18,0x4($a0)
.L0f160730:
/*  f160730:	e7b200a0 */ 	swc1	$f18,0xa0($sp)
/*  f160734:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f160738:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f16073c:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f160740:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160744:	4604003c */ 	c.lt.s	$f0,$f4
/*  f160748:	00000000 */ 	nop
/*  f16074c:	45020004 */ 	bc1fl	.L0f160760
/*  f160750:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f160754:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160758:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f16075c:	c7a60094 */ 	lwc1	$f6,0x94($sp)
.L0f160760:
/*  f160760:	4600303c */ 	c.lt.s	$f6,$f0
/*  f160764:	00000000 */ 	nop
/*  f160768:	45020003 */ 	bc1fl	.L0f160778
/*  f16076c:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160770:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160774:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160778:
/*  f160778:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f16077c:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160780:	00000000 */ 	nop
/*  f160784:	45020004 */ 	bc1fl	.L0f160798
/*  f160788:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*  f16078c:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160790:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160794:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
.L0f160798:
/*  f160798:	4600503c */ 	c.lt.s	$f10,$f0
/*  f16079c:	00000000 */ 	nop
/*  f1607a0:	45020003 */ 	bc1fl	.L0f1607b0
/*  f1607a4:	c6a00004 */ 	lwc1	$f0,0x4($s5)
/*  f1607a8:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f1607ac:	c6a00004 */ 	lwc1	$f0,0x4($s5)
.L0f1607b0:
/*  f1607b0:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f1607b4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1607b8:	00000000 */ 	nop
/*  f1607bc:	45020007 */ 	bc1fl	.L0f1607dc
/*  f1607c0:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f1607c4:	c6f00004 */ 	lwc1	$f16,0x4($s7)
/*  f1607c8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f1607cc:	00000000 */ 	nop
/*  f1607d0:	4503005b */ 	bc1tl	.L0f160940
/*  f1607d4:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f1607d8:	c7a40094 */ 	lwc1	$f4,0x94($sp)
.L0f1607dc:
/*  f1607dc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f1607e0:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f1607e4:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1607e8:	00000000 */ 	nop
/*  f1607ec:	45020007 */ 	bc1fl	.L0f16080c
/*  f1607f0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1607f4:	c6e60004 */ 	lwc1	$f6,0x4($s7)
/*  f1607f8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1607fc:	00000000 */ 	nop
/*  f160800:	4503004f */ 	bc1tl	.L0f160940
/*  f160804:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160808:	02a02025 */ 	or	$a0,$s5,$zero
.L0f16080c:
/*  f16080c:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f160810:	0fc57cac */ 	jal	bg0f15f2b0
/*  f160814:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f160818:	10400048 */ 	beqz	$v0,.L0f16093c
/*  f16081c:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160820:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f160824:	27b80084 */ 	addiu	$t8,$sp,0x84
/*  f160828:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f16082c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f160830:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f160834:	02002025 */ 	or	$a0,$s0,$zero
/*  f160838:	02202825 */ 	or	$a1,$s1,$zero
/*  f16083c:	03c03025 */ 	or	$a2,$s8,$zero
/*  f160840:	00003825 */ 	or	$a3,$zero,$zero
/*  f160844:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f160848:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f16084c:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f160850:	0c00bd58 */ 	jal	func0002f560
/*  f160854:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f160858:	10400038 */ 	beqz	$v0,.L0f16093c
/*  f16085c:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160860:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f160864:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
/*  f160868:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f16086c:	c6b20004 */ 	lwc1	$f18,0x4($s5)
/*  f160870:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f160874:	c6aa0008 */ 	lwc1	$f10,0x8($s5)
/*  f160878:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f16087c:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f160880:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f160884:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f160888:	c5b20000 */ 	lwc1	$f18,0x0($t5)
/*  f16088c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f160890:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f160894:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f160898:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f16089c:	46101080 */ 	add.s	$f2,$f2,$f16
/*  f1608a0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f1608a4:	00000000 */ 	nop
/*  f1608a8:	45020025 */ 	bc1fl	.L0f160940
/*  f1608ac:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f1608b0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1608b4:	afaa00cc */ 	sw	$t2,0xcc($sp)
/*  f1608b8:	e5a20000 */ 	swc1	$f2,0x0($t5)
/*  f1608bc:	e6480000 */ 	swc1	$f8,0x0($s2)
/*  f1608c0:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f1608c4:	2402000c */ 	addiu	$v0,$zero,0xc
/*  f1608c8:	e6440004 */ 	swc1	$f4,0x4($s2)
/*  f1608cc:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f1608d0:	e6460008 */ 	swc1	$f6,0x8($s2)
/*  f1608d4:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f1608d8:	e64a000c */ 	swc1	$f10,0xc($s2)
/*  f1608dc:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f1608e0:	e6500010 */ 	swc1	$f16,0x10($s2)
/*  f1608e4:	c7b20080 */ 	lwc1	$f18,0x80($sp)
/*  f1608e8:	e6520014 */ 	swc1	$f18,0x14($s2)
/*  f1608ec:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1608f0:	01620019 */ 	multu	$t3,$v0
/*  f1608f4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1608f8:	0000c812 */ 	mflo	$t9
/*  f1608fc:	03366021 */ 	addu	$t4,$t9,$s6
/*  f160900:	ae4c0018 */ 	sw	$t4,0x18($s2)
/*  f160904:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f160908:	01c20019 */ 	multu	$t6,$v0
/*  f16090c:	00007812 */ 	mflo	$t7
/*  f160910:	01f6c021 */ 	addu	$t8,$t7,$s6
/*  f160914:	ae58001c */ 	sw	$t8,0x1c($s2)
/*  f160918:	8fa90074 */ 	lw	$t1,0x74($sp)
/*  f16091c:	a64b002a */ 	sh	$t3,0x2a($s2)
/*  f160920:	01220019 */ 	multu	$t1,$v0
/*  f160924:	00005012 */ 	mflo	$t2
/*  f160928:	01566821 */ 	addu	$t5,$t2,$s6
/*  f16092c:	ae4d0020 */ 	sw	$t5,0x20($s2)
/*  f160930:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160934:	a6480028 */ 	sh	$t0,0x28($s2)
/*  f160938:	ae590024 */ 	sw	$t9,0x24($s2)
.L0f16093c:
/*  f16093c:	2673ffff */ 	addiu	$s3,$s3,-1
.L0f160940:
/*  f160940:	24010002 */ 	addiu	$at,$zero,0x2
/*  f160944:	5661000d */ 	bnel	$s3,$at,.L0f16097c
/*  f160948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16094c:	928c0006 */ 	lbu	$t4,0x6($s4)
/*  f160950:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f160954:	318e000f */ 	andi	$t6,$t4,0xf
/*  f160958:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f16095c:	968f0006 */ 	lhu	$t7,0x6($s4)
/*  f160960:	000fc302 */ 	srl	$t8,$t7,0xc
/*  f160964:	afb80070 */ 	sw	$t8,0x70($sp)
/*  f160968:	92890003 */ 	lbu	$t1,0x3($s4)
/*  f16096c:	00095102 */ 	srl	$t2,$t1,0x4
/*  f160970:	1000001b */ 	b	.L0f1609e0
/*  f160974:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f160978:	24010001 */ 	addiu	$at,$zero,0x1
.L0f16097c:
/*  f16097c:	1661000c */ 	bne	$s3,$at,.L0f1609b0
/*  f160980:	00000000 */ 	nop
/*  f160984:	968d0004 */ 	lhu	$t5,0x4($s4)
/*  f160988:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f16098c:	31ab000f */ 	andi	$t3,$t5,0xf
/*  f160990:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f160994:	92990005 */ 	lbu	$t9,0x5($s4)
/*  f160998:	00196102 */ 	srl	$t4,$t9,0x4
/*  f16099c:	afac0070 */ 	sw	$t4,0x70($sp)
/*  f1609a0:	928e0002 */ 	lbu	$t6,0x2($s4)
/*  f1609a4:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f1609a8:	1000000d */ 	b	.L0f1609e0
/*  f1609ac:	afaf0074 */ 	sw	$t7,0x74($sp)
.L0f1609b0:
/*  f1609b0:	1660000b */ 	bnez	$s3,.L0f1609e0
/*  f1609b4:	00000000 */ 	nop
/*  f1609b8:	92980004 */ 	lbu	$t8,0x4($s4)
/*  f1609bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1609c0:	3309000f */ 	andi	$t1,$t8,0xf
/*  f1609c4:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f1609c8:	8e8a0004 */ 	lw	$t2,0x4($s4)
/*  f1609cc:	000a6f02 */ 	srl	$t5,$t2,0x1c
/*  f1609d0:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f1609d4:	968b0002 */ 	lhu	$t3,0x2($s4)
/*  f1609d8:	000bcb02 */ 	srl	$t9,$t3,0xc
/*  f1609dc:	afb90074 */ 	sw	$t9,0x74($sp)
.L0f1609e0:
/*  f1609e0:	0663fec8 */ 	bgezl	$s3,.L0f160504
/*  f1609e4:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f1609e8:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1609ec:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1609f0:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f1609f4:
/*  f1609f4:	8fac0100 */ 	lw	$t4,0x100($sp)
.L0f1609f8:
/*  f1609f8:	258e0008 */ 	addiu	$t6,$t4,0x8
/*  f1609fc:	1000fd92 */ 	b	.L0f160048
/*  f160a00:	afae0100 */ 	sw	$t6,0x100($sp)
/*  f160a04:	8fbf0054 */ 	lw	$ra,0x54($sp)
.L0f160a08:
/*  f160a08:	8fa200cc */ 	lw	$v0,0xcc($sp)
/*  f160a0c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f160a10:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f160a14:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f160a18:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f160a1c:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f160a20:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f160a24:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f160a28:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f160a2c:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f160a30:	03e00008 */ 	jr	$ra
/*  f160a34:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel bgCalculateHitInVtxBatch
.late_rodata
glabel var7f1b75dc
.word 0x7f7fffff
.text
/*  f160a38:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f160a3c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f160a40:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f160a44:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f160a48:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f160a4c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f160a50:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f160a54:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f160a58:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f160a5c:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f160a60:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f160a64:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f160a68:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f160a6c:	8fb00108 */ 	lw	$s0,0x108($sp)
/*  f160a70:	8cf10004 */ 	lw	$s1,0x4($a3)
/*  f160a74:	00809825 */ 	or	$s3,$a0,$zero
/*  f160a78:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f160a7c:	00e09025 */ 	or	$s2,$a3,$zero
/*  f160a80:	02002025 */ 	or	$a0,$s0,$zero
/*  f160a84:	0fc576ed */ 	jal	room0f15dbb4
/*  f160a88:	02202825 */ 	or	$a1,$s1,$zero
/*  f160a8c:	964e0000 */ 	lhu	$t6,0x0($s2)
/*  f160a90:	3c0100ff */ 	lui	$at,0xff
/*  f160a94:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f160a98:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f160a9c:	01f14021 */ 	addu	$t0,$t7,$s1
/*  f160aa0:	91040001 */ 	lbu	$a0,0x1($t0)
/*  f160aa4:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f160aa8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f160aac:	00047102 */ 	srl	$t6,$a0,0x4
/*  f160ab0:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f160ab4:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f160ab8:	25e40001 */ 	addiu	$a0,$t7,0x1
/*  f160abc:	0301c824 */ 	and	$t9,$t8,$at
/*  f160ac0:	03225021 */ 	addu	$t2,$t9,$v0
/*  f160ac4:	18800022 */ 	blez	$a0,.L0f160b50
/*  f160ac8:	03e01825 */ 	or	$v1,$ra,$zero
/*  f160acc:	00102880 */ 	sll	$a1,$s0,0x2
/*  f160ad0:	00b02821 */ 	addu	$a1,$a1,$s0
/*  f160ad4:	3c02800a */ 	lui	$v0,%hi(g_BgRooms)
/*  f160ad8:	24424cc4 */ 	addiu	$v0,$v0,%lo(g_BgRooms)
/*  f160adc:	00052880 */ 	sll	$a1,$a1,0x2
.L0f160ae0:
/*  f160ae0:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f160ae4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f160ae8:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f160aec:	448e3000 */ 	mtc1	$t6,$f6
/*  f160af0:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f160af4:	c7240004 */ 	lwc1	$f4,0x4($t9)
/*  f160af8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f160afc:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f160b00:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f160b04:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f160b08:	e46afff4 */ 	swc1	$f10,-0xc($v1)
/*  f160b0c:	8559fff6 */ 	lh	$t9,-0xa($t2)
/*  f160b10:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f160b14:	44999000 */ 	mtc1	$t9,$f18
/*  f160b18:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f160b1c:	c7100008 */ 	lwc1	$f16,0x8($t8)
/*  f160b20:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f160b24:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f160b28:	e464fff8 */ 	swc1	$f4,-0x8($v1)
/*  f160b2c:	8558fff8 */ 	lh	$t8,-0x8($t2)
/*  f160b30:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f160b34:	44985000 */ 	mtc1	$t8,$f10
/*  f160b38:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f160b3c:	c5e8000c */ 	lwc1	$f8,0xc($t7)
/*  f160b40:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f160b44:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f160b48:	1c80ffe5 */ 	bgtz	$a0,.L0f160ae0
/*  f160b4c:	e470fffc */ 	swc1	$f16,-0x4($v1)
.L0f160b50:
/*  f160b50:	81020008 */ 	lb	$v0,0x8($t0)
/*  f160b54:	3c017f1b */ 	lui	$at,%hi(var7f1b75dc)
/*  f160b58:	c43475dc */ 	lwc1	$f20,%lo(var7f1b75dc)($at)
/*  f160b5c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f160b60:	00006825 */ 	or	$t5,$zero,$zero
/*  f160b64:	104101d1 */ 	beq	$v0,$at,.L0f1612ac
/*  f160b68:	25080008 */ 	addiu	$t0,$t0,0x8
/*  f160b6c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f160b70:	104101ce */ 	beq	$v0,$at,.L0f1612ac
/*  f160b74:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f160b78:	afb20104 */ 	sw	$s2,0x104($sp)
/*  f160b7c:	241200fd */ 	addiu	$s2,$zero,0xfd
/*  f160b80:	8fbe00f0 */ 	lw	$s8,0xf0($sp)
/*  f160b84:	8fb40078 */ 	lw	$s4,0x78($sp)
/*  f160b88:	8fb0010c */ 	lw	$s0,0x10c($sp)
/*  f160b8c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f160b90:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f160b94:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f160b98:
/*  f160b98:	10410005 */ 	beq	$v0,$at,.L0f160bb0
/*  f160b9c:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f160ba0:	50410004 */ 	beql	$v0,$at,.L0f160bb4
/*  f160ba4:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f160ba8:	100001b7 */ 	b	.L0f161288
/*  f160bac:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f160bb0:
/*  f160bb0:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f160bb4:
/*  f160bb4:	5441002e */ 	bnel	$v0,$at,.L0f160c70
/*  f160bb8:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f160bbc:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f160bc0:	91190005 */ 	lbu	$t9,0x5($t0)
/*  f160bc4:	0000f025 */ 	or	$s8,$zero,$zero
/*  f160bc8:	00004825 */ 	or	$t1,$zero,$zero
/*  f160bcc:	0322001a */ 	div	$zero,$t9,$v0
/*  f160bd0:	00007012 */ 	mflo	$t6
/*  f160bd4:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f160bd8:	910f0006 */ 	lbu	$t7,0x6($t0)
/*  f160bdc:	14400002 */ 	bnez	$v0,.L0f160be8
/*  f160be0:	00000000 */ 	nop
/*  f160be4:	0007000d */ 	break	0x7
.L0f160be8:
/*  f160be8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160bec:	14410004 */ 	bne	$v0,$at,.L0f160c00
/*  f160bf0:	3c018000 */ 	lui	$at,0x8000
/*  f160bf4:	17210002 */ 	bne	$t9,$at,.L0f160c00
/*  f160bf8:	00000000 */ 	nop
/*  f160bfc:	0006000d */ 	break	0x6
.L0f160c00:
/*  f160c00:	01e2001a */ 	div	$zero,$t7,$v0
/*  f160c04:	0000c012 */ 	mflo	$t8
/*  f160c08:	afb800e0 */ 	sw	$t8,0xe0($sp)
/*  f160c0c:	91190007 */ 	lbu	$t9,0x7($t0)
/*  f160c10:	14400002 */ 	bnez	$v0,.L0f160c1c
/*  f160c14:	00000000 */ 	nop
/*  f160c18:	0007000d */ 	break	0x7
.L0f160c1c:
/*  f160c1c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160c20:	14410004 */ 	bne	$v0,$at,.L0f160c34
/*  f160c24:	3c018000 */ 	lui	$at,0x8000
/*  f160c28:	15e10002 */ 	bne	$t7,$at,.L0f160c34
/*  f160c2c:	00000000 */ 	nop
/*  f160c30:	0006000d */ 	break	0x6
.L0f160c34:
/*  f160c34:	0322001a */ 	div	$zero,$t9,$v0
/*  f160c38:	00007012 */ 	mflo	$t6
/*  f160c3c:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f160c40:	14400002 */ 	bnez	$v0,.L0f160c4c
/*  f160c44:	00000000 */ 	nop
/*  f160c48:	0007000d */ 	break	0x7
.L0f160c4c:
/*  f160c4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160c50:	14410004 */ 	bne	$v0,$at,.L0f160c64
/*  f160c54:	3c018000 */ 	lui	$at,0x8000
/*  f160c58:	17210002 */ 	bne	$t9,$at,.L0f160c64
/*  f160c5c:	00000000 */ 	nop
/*  f160c60:	0006000d */ 	break	0x6
.L0f160c64:
/*  f160c64:	10000011 */ 	b	.L0f160cac
/*  f160c68:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f160c6c:	2401ffb1 */ 	addiu	$at,$zero,-79
.L0f160c70:
/*  f160c70:	5441000e */ 	bnel	$v0,$at,.L0f160cac
/*  f160c74:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f160c78:	8d0f0004 */ 	lw	$t7,0x4($t0)
/*  f160c7c:	0100a025 */ 	or	$s4,$t0,$zero
/*  f160c80:	0160f025 */ 	or	$s8,$t3,$zero
/*  f160c84:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f160c88:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f160c8c:	91190007 */ 	lbu	$t9,0x7($t0)
/*  f160c90:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f160c94:	00197102 */ 	srl	$t6,$t9,0x4
/*  f160c98:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f160c9c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f160ca0:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f160ca4:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f160ca8:	8fb900dc */ 	lw	$t9,0xdc($sp)
.L0f160cac:
/*  f160cac:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f160cb0:	57200006 */ 	bnezl	$t9,.L0f160ccc
/*  f160cb4:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f160cb8:	15c00003 */ 	bnez	$t6,.L0f160cc8
/*  f160cbc:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f160cc0:	51e00171 */ 	beqzl	$t7,.L0f161288
/*  f160cc4:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f160cc8:
/*  f160cc8:	8fb800dc */ 	lw	$t8,0xdc($sp)
.L0f160ccc:
/*  f160ccc:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f160cd0:	030b0019 */ 	multu	$t8,$t3
/*  f160cd4:	0000c812 */ 	mflo	$t9
/*  f160cd8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f160cdc:	01df2021 */ 	addu	$a0,$t6,$ra
/*  f160ce0:	01eb0019 */ 	multu	$t7,$t3
/*  f160ce4:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f160ce8:	0080b025 */ 	or	$s6,$a0,$zero
/*  f160cec:	0000c012 */ 	mflo	$t8
/*  f160cf0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f160cf4:	033f1021 */ 	addu	$v0,$t9,$ra
/*  f160cf8:	01cb0019 */ 	multu	$t6,$t3
/*  f160cfc:	0040b825 */ 	or	$s7,$v0,$zero
/*  f160d00:	00007812 */ 	mflo	$t7
/*  f160d04:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f160d08:	031f1821 */ 	addu	$v1,$t8,$ra
/*  f160d0c:	afa300bc */ 	sw	$v1,0xbc($sp)
/*  f160d10:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f160d14:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f160d18:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f160d1c:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f160d20:	460a203c */ 	c.lt.s	$f4,$f10
/*  f160d24:	00000000 */ 	nop
/*  f160d28:	45020004 */ 	bc1fl	.L0f160d3c
/*  f160d2c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f160d30:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f160d34:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f160d38:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f160d3c:
/*  f160d3c:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160d40:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160d44:	00000000 */ 	nop
/*  f160d48:	45020003 */ 	bc1fl	.L0f160d58
/*  f160d4c:	c6700000 */ 	lwc1	$f16,0x0($s3)
/*  f160d50:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f160d54:	c6700000 */ 	lwc1	$f16,0x0($s3)
.L0f160d58:
/*  f160d58:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f160d5c:	4606803c */ 	c.lt.s	$f16,$f6
/*  f160d60:	00000000 */ 	nop
/*  f160d64:	45020007 */ 	bc1fl	.L0f160d84
/*  f160d68:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f160d6c:	c6a40000 */ 	lwc1	$f4,0x0($s5)
/*  f160d70:	4606203c */ 	c.lt.s	$f4,$f6
/*  f160d74:	00000000 */ 	nop
/*  f160d78:	45030116 */ 	bc1tl	.L0f1611d4
/*  f160d7c:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160d80:	c48a0000 */ 	lwc1	$f10,0x0($a0)
.L0f160d84:
/*  f160d84:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f160d88:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f160d8c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f160d90:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160d94:	00000000 */ 	nop
/*  f160d98:	45020003 */ 	bc1fl	.L0f160da8
/*  f160d9c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f160da0:	e7a0008c */ 	swc1	$f0,0x8c($sp)
/*  f160da4:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f160da8:
/*  f160da8:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f160dac:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160db0:	00000000 */ 	nop
/*  f160db4:	45020003 */ 	bc1fl	.L0f160dc4
/*  f160db8:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f160dbc:	e7a0008c */ 	swc1	$f0,0x8c($sp)
/*  f160dc0:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0f160dc4:
/*  f160dc4:	c6640000 */ 	lwc1	$f4,0x0($s3)
/*  f160dc8:	4604803c */ 	c.lt.s	$f16,$f4
/*  f160dcc:	00000000 */ 	nop
/*  f160dd0:	45020007 */ 	bc1fl	.L0f160df0
/*  f160dd4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f160dd8:	c6a60000 */ 	lwc1	$f6,0x0($s5)
/*  f160ddc:	4606803c */ 	c.lt.s	$f16,$f6
/*  f160de0:	00000000 */ 	nop
/*  f160de4:	450300fb */ 	bc1tl	.L0f1611d4
/*  f160de8:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160dec:	c48a0008 */ 	lwc1	$f10,0x8($a0)
.L0f160df0:
/*  f160df0:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f160df4:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f160df8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160dfc:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160e00:	00000000 */ 	nop
/*  f160e04:	45020003 */ 	bc1fl	.L0f160e14
/*  f160e08:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f160e0c:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160e10:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f160e14:
/*  f160e14:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f160e18:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160e1c:	00000000 */ 	nop
/*  f160e20:	45020003 */ 	bc1fl	.L0f160e30
/*  f160e24:	c6640008 */ 	lwc1	$f4,0x8($s3)
/*  f160e28:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160e2c:	c6640008 */ 	lwc1	$f4,0x8($s3)
.L0f160e30:
/*  f160e30:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f160e34:	4610203c */ 	c.lt.s	$f4,$f16
/*  f160e38:	00000000 */ 	nop
/*  f160e3c:	45020007 */ 	bc1fl	.L0f160e5c
/*  f160e40:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f160e44:	c6a60008 */ 	lwc1	$f6,0x8($s5)
/*  f160e48:	4610303c */ 	c.lt.s	$f6,$f16
/*  f160e4c:	00000000 */ 	nop
/*  f160e50:	450300e0 */ 	bc1tl	.L0f1611d4
/*  f160e54:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160e58:	c48a0008 */ 	lwc1	$f10,0x8($a0)
.L0f160e5c:
/*  f160e5c:	e7aa0094 */ 	swc1	$f10,0x94($sp)
/*  f160e60:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f160e64:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160e68:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160e6c:	00000000 */ 	nop
/*  f160e70:	45020003 */ 	bc1fl	.L0f160e80
/*  f160e74:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f160e78:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160e7c:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f160e80:
/*  f160e80:	c7b20094 */ 	lwc1	$f18,0x94($sp)
/*  f160e84:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160e88:	00000000 */ 	nop
/*  f160e8c:	45020003 */ 	bc1fl	.L0f160e9c
/*  f160e90:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f160e94:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160e98:	c7a40094 */ 	lwc1	$f4,0x94($sp)
.L0f160e9c:
/*  f160e9c:	c6660008 */ 	lwc1	$f6,0x8($s3)
/*  f160ea0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f160ea4:	00000000 */ 	nop
/*  f160ea8:	45020007 */ 	bc1fl	.L0f160ec8
/*  f160eac:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f160eb0:	c6b00008 */ 	lwc1	$f16,0x8($s5)
/*  f160eb4:	4610203c */ 	c.lt.s	$f4,$f16
/*  f160eb8:	00000000 */ 	nop
/*  f160ebc:	450300c5 */ 	bc1tl	.L0f1611d4
/*  f160ec0:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160ec4:	c48a0004 */ 	lwc1	$f10,0x4($a0)
.L0f160ec8:
/*  f160ec8:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f160ecc:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f160ed0:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160ed4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160ed8:	00000000 */ 	nop
/*  f160edc:	45020003 */ 	bc1fl	.L0f160eec
/*  f160ee0:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160ee4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160ee8:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160eec:
/*  f160eec:	c7b2009c */ 	lwc1	$f18,0x9c($sp)
/*  f160ef0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160ef4:	00000000 */ 	nop
/*  f160ef8:	45020003 */ 	bc1fl	.L0f160f08
/*  f160efc:	c6660004 */ 	lwc1	$f6,0x4($s3)
/*  f160f00:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160f04:	c6660004 */ 	lwc1	$f6,0x4($s3)
.L0f160f08:
/*  f160f08:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f160f0c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160f10:	00000000 */ 	nop
/*  f160f14:	45020007 */ 	bc1fl	.L0f160f34
/*  f160f18:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f160f1c:	c6b00004 */ 	lwc1	$f16,0x4($s5)
/*  f160f20:	4604803c */ 	c.lt.s	$f16,$f4
/*  f160f24:	00000000 */ 	nop
/*  f160f28:	450300aa */ 	bc1tl	.L0f1611d4
/*  f160f2c:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160f30:	c48a0004 */ 	lwc1	$f10,0x4($a0)
.L0f160f34:
/*  f160f34:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f160f38:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f160f3c:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160f40:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160f44:	00000000 */ 	nop
/*  f160f48:	45020003 */ 	bc1fl	.L0f160f58
/*  f160f4c:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160f50:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160f54:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160f58:
/*  f160f58:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f160f5c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160f60:	00000000 */ 	nop
/*  f160f64:	45020003 */ 	bc1fl	.L0f160f74
/*  f160f68:	c7a60090 */ 	lwc1	$f6,0x90($sp)
/*  f160f6c:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160f70:	c7a60090 */ 	lwc1	$f6,0x90($sp)
.L0f160f74:
/*  f160f74:	c6700004 */ 	lwc1	$f16,0x4($s3)
/*  f160f78:	4610303c */ 	c.lt.s	$f6,$f16
/*  f160f7c:	00000000 */ 	nop
/*  f160f80:	45020007 */ 	bc1fl	.L0f160fa0
/*  f160f84:	02602025 */ 	or	$a0,$s3,$zero
/*  f160f88:	c6a40004 */ 	lwc1	$f4,0x4($s5)
/*  f160f8c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160f90:	00000000 */ 	nop
/*  f160f94:	4503008f */ 	bc1tl	.L0f1611d4
/*  f160f98:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160f9c:	02602025 */ 	or	$a0,$s3,$zero
.L0f160fa0:
/*  f160fa0:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f160fa4:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f160fa8:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f160fac:	afa80080 */ 	sw	$t0,0x80($sp)
/*  f160fb0:	a7a900f4 */ 	sh	$t1,0xf4($sp)
/*  f160fb4:	afaa0088 */ 	sw	$t2,0x88($sp)
/*  f160fb8:	0fc57cac */ 	jal	bg0f15f2b0
/*  f160fbc:	afad00e8 */ 	sw	$t5,0xe8($sp)
/*  f160fc0:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f160fc4:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f160fc8:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f160fcc:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f160fd0:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f160fd4:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f160fd8:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f160fdc:	1040007c */ 	beqz	$v0,.L0f1611d0
/*  f160fe0:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f160fe4:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160fe8:	27ae00b0 */ 	addiu	$t6,$sp,0xb0
/*  f160fec:	27af00a4 */ 	addiu	$t7,$sp,0xa4
/*  f160ff0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f160ff4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f160ff8:	02c02025 */ 	or	$a0,$s6,$zero
/*  f160ffc:	02e02825 */ 	or	$a1,$s7,$zero
/*  f161000:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f161004:	00003825 */ 	or	$a3,$zero,$zero
/*  f161008:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f16100c:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f161010:	afa80080 */ 	sw	$t0,0x80($sp)
/*  f161014:	a7a900f4 */ 	sh	$t1,0xf4($sp)
/*  f161018:	afaa0088 */ 	sw	$t2,0x88($sp)
/*  f16101c:	afad00e8 */ 	sw	$t5,0xe8($sp)
/*  f161020:	0c00bd58 */ 	jal	func0002f560
/*  f161024:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f161028:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f16102c:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f161030:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f161034:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f161038:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f16103c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f161040:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f161044:	10400062 */ 	beqz	$v0,.L0f1611d0
/*  f161048:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f16104c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f161050:	c6680000 */ 	lwc1	$f8,0x0($s3)
/*  f161054:	c7b200b4 */ 	lwc1	$f18,0xb4($sp)
/*  f161058:	c6700004 */ 	lwc1	$f16,0x4($s3)
/*  f16105c:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f161060:	c66a0008 */ 	lwc1	$f10,0x8($s3)
/*  f161064:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f161068:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f16106c:	46109001 */ 	sub.s	$f0,$f18,$f16
/*  f161070:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f161074:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f161078:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f16107c:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f161080:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f161084:	4614103c */ 	c.lt.s	$f2,$f20
/*  f161088:	00000000 */ 	nop
/*  f16108c:	45020051 */ 	bc1fl	.L0f1611d4
/*  f161090:	27deffff */ 	addiu	$s8,$s8,-1
/*  f161094:	91180000 */ 	lbu	$t8,0x0($t0)
/*  f161098:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f16109c:	01001025 */ 	or	$v0,$t0,$zero
/*  f1610a0:	1258000a */ 	beq	$s2,$t8,.L0f1610cc
/*  f1610a4:	0228082b */ 	sltu	$at,$s1,$t0
/*  f1610a8:	10200008 */ 	beqz	$at,.L0f1610cc
/*  f1610ac:	00000000 */ 	nop
/*  f1610b0:	9059fff8 */ 	lbu	$t9,-0x8($v0)
.L0f1610b4:
/*  f1610b4:	2442fff8 */ 	addiu	$v0,$v0,-8
/*  f1610b8:	0222082b */ 	sltu	$at,$s1,$v0
/*  f1610bc:	12590003 */ 	beq	$s2,$t9,.L0f1610cc
/*  f1610c0:	00000000 */ 	nop
/*  f1610c4:	5420fffb */ 	bnezl	$at,.L0f1610b4
/*  f1610c8:	9059fff8 */ 	lbu	$t9,-0x8($v0)
.L0f1610cc:
/*  f1610cc:	1051000a */ 	beq	$v0,$s1,.L0f1610f8
/*  f1610d0:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f1610d4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f1610d8:	3c040f00 */ 	lui	$a0,0xf00
/*  f1610dc:	3c020500 */ 	lui	$v0,0x500
/*  f1610e0:	00647024 */ 	and	$t6,$v1,$a0
/*  f1610e4:	108e0004 */ 	beq	$a0,$t6,.L0f1610f8
/*  f1610e8:	00000000 */ 	nop
/*  f1610ec:	00627824 */ 	and	$t7,$v1,$v0
/*  f1610f0:	144f0003 */ 	bne	$v0,$t7,.L0f161100
/*  f1610f4:	3c018000 */ 	lui	$at,0x8000
.L0f1610f8:
/*  f1610f8:	10000004 */ 	b	.L0f16110c
/*  f1610fc:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f161100:
/*  f161100:	2462fff8 */ 	addiu	$v0,$v1,-8
/*  f161104:	0041c025 */ 	or	$t8,$v0,$at
/*  f161108:	87040000 */ 	lh	$a0,0x0($t8)
.L0f16110c:
/*  f16110c:	972e0002 */ 	lhu	$t6,0x2($t9)
/*  f161110:	24010002 */ 	addiu	$at,$zero,0x2
/*  f161114:	15c1000a */ 	bne	$t6,$at,.L0f161140
/*  f161118:	00000000 */ 	nop
/*  f16111c:	3c0f800b */ 	lui	$t7,%hi(g_Textures)
/*  f161120:	8defabc0 */ 	lw	$t7,%lo(g_Textures)($t7)
/*  f161124:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f161128:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f16112c:	932e0000 */ 	lbu	$t6,0x0($t9)
/*  f161130:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f161134:	15e00002 */ 	bnez	$t7,.L0f161140
/*  f161138:	00000000 */ 	nop
/*  f16113c:	00006825 */ 	or	$t5,$zero,$zero
.L0f161140:
/*  f161140:	51a00024 */ 	beqzl	$t5,.L0f1611d4
/*  f161144:	27deffff */ 	addiu	$s8,$s8,-1
/*  f161148:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f16114c:	46001506 */ 	mov.s	$f20,$f2
/*  f161150:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f161154:	c7b000b4 */ 	lwc1	$f16,0xb4($sp)
/*  f161158:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f16115c:	c7a600b8 */ 	lwc1	$f6,0xb8($sp)
/*  f161160:	e6060008 */ 	swc1	$f6,0x8($s0)
/*  f161164:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f161168:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f16116c:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f161170:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*  f161174:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f161178:	e6080014 */ 	swc1	$f8,0x14($s0)
/*  f16117c:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f161180:	030c0019 */ 	multu	$t8,$t4
/*  f161184:	0000c812 */ 	mflo	$t9
/*  f161188:	032a7021 */ 	addu	$t6,$t9,$t2
/*  f16118c:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f161190:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f161194:	01ec0019 */ 	multu	$t7,$t4
/*  f161198:	0000c012 */ 	mflo	$t8
/*  f16119c:	030ac821 */ 	addu	$t9,$t8,$t2
/*  f1611a0:	ae19001c */ 	sw	$t9,0x1c($s0)
/*  f1611a4:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f1611a8:	a604002a */ 	sh	$a0,0x2a($s0)
/*  f1611ac:	ae080024 */ 	sw	$t0,0x24($s0)
/*  f1611b0:	01cc0019 */ 	multu	$t6,$t4
/*  f1611b4:	a6090028 */ 	sh	$t1,0x28($s0)
/*  f1611b8:	00007812 */ 	mflo	$t7
/*  f1611bc:	01eac021 */ 	addu	$t8,$t7,$t2
/*  f1611c0:	ae180020 */ 	sw	$t8,0x20($s0)
/*  f1611c4:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f1611c8:	972e0002 */ 	lhu	$t6,0x2($t9)
/*  f1611cc:	a60e002c */ 	sh	$t6,0x2c($s0)
.L0f1611d0:
/*  f1611d0:	27deffff */ 	addiu	$s8,$s8,-1
.L0f1611d4:
/*  f1611d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1611d8:	57c1000d */ 	bnel	$s8,$at,.L0f161210
/*  f1611dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1611e0:	928f0006 */ 	lbu	$t7,0x6($s4)
/*  f1611e4:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f1611e8:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f1611ec:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f1611f0:	96990006 */ 	lhu	$t9,0x6($s4)
/*  f1611f4:	00197302 */ 	srl	$t6,$t9,0xc
/*  f1611f8:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f1611fc:	928f0003 */ 	lbu	$t7,0x3($s4)
/*  f161200:	000fc102 */ 	srl	$t8,$t7,0x4
/*  f161204:	1000001d */ 	b	.L0f16127c
/*  f161208:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f16120c:	24010001 */ 	addiu	$at,$zero,0x1
.L0f161210:
/*  f161210:	17c1000e */ 	bne	$s8,$at,.L0f16124c
/*  f161214:	00000000 */ 	nop
/*  f161218:	96990004 */ 	lhu	$t9,0x4($s4)
/*  f16121c:	000b4c00 */ 	sll	$t1,$t3,0x10
/*  f161220:	332e000f */ 	andi	$t6,$t9,0xf
/*  f161224:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f161228:	928f0005 */ 	lbu	$t7,0x5($s4)
/*  f16122c:	000fc102 */ 	srl	$t8,$t7,0x4
/*  f161230:	afb800e0 */ 	sw	$t8,0xe0($sp)
/*  f161234:	92990002 */ 	lbu	$t9,0x2($s4)
/*  f161238:	00097c03 */ 	sra	$t7,$t1,0x10
/*  f16123c:	01e04825 */ 	or	$t1,$t7,$zero
/*  f161240:	332e000f */ 	andi	$t6,$t9,0xf
/*  f161244:	1000000d */ 	b	.L0f16127c
/*  f161248:	afae00e4 */ 	sw	$t6,0xe4($sp)
.L0f16124c:
/*  f16124c:	17c0000b */ 	bnez	$s8,.L0f16127c
/*  f161250:	00000000 */ 	nop
/*  f161254:	92980004 */ 	lbu	$t8,0x4($s4)
/*  f161258:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f16125c:	3319000f */ 	andi	$t9,$t8,0xf
/*  f161260:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f161264:	8e8e0004 */ 	lw	$t6,0x4($s4)
/*  f161268:	000e7f02 */ 	srl	$t7,$t6,0x1c
/*  f16126c:	afaf00e0 */ 	sw	$t7,0xe0($sp)
/*  f161270:	96980002 */ 	lhu	$t8,0x2($s4)
/*  f161274:	0018cb02 */ 	srl	$t9,$t8,0xc
/*  f161278:	afb900e4 */ 	sw	$t9,0xe4($sp)
.L0f16127c:
/*  f16127c:	07c3fe8b */ 	bgezl	$s8,.L0f160cac
/*  f161280:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f161284:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f161288:
/*  f161288:	81020000 */ 	lb	$v0,0x0($t0)
/*  f16128c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f161290:	10410006 */ 	beq	$v0,$at,.L0f1612ac
/*  f161294:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f161298:	5441fe3f */ 	bnel	$v0,$at,.L0f160b98
/*  f16129c:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f1612a0:	afbe00f0 */ 	sw	$s8,0xf0($sp)
/*  f1612a4:	afb40078 */ 	sw	$s4,0x78($sp)
/*  f1612a8:	a7a900f4 */ 	sh	$t1,0xf4($sp)
.L0f1612ac:
/*  f1612ac:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1612b0:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1612b4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1612b8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1612bc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1612c0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1612c4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1612c8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1612cc:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1612d0:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1612d4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1612d8:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f1612dc:	03e00008 */ 	jr	$ra
/*  f1612e0:	01a01025 */ 	or	$v0,$t5,$zero
);

// Mismatch: Some significantly different codegen, probably related to how loops
// are iterated. Appears to be functionally correct.
//bool bgCalculateHitInVtxBatch(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct vtxbatch *batch, s32 roomnum, struct hitthing *hitthing)
//{
//	s16 spf4;
//	s32 spf0;
//	Gfx *gdl;
//	s32 ret; // e8
//	s32 spdc[3];
//	struct gfxvtx *vtx;
//	s32 numvertices;
//	f32 lowestsqdist;
//	Gfx *tmpgdl;
//	s32 texturenum;
//	s32 i;
//	s32 index;
//	u32 stack;
//	struct coord spb0;
//	struct coord spa4;
//	struct coord sp98;
//	struct coord sp8c;
//
//	Gfx *sp78;
//	Gfx *iter;
//
//	gdl = batch->gdl;
//
//	vtx = room0f15dbb4(roomnum, gdl);
//	iter = &gdl[batch->gbicmdindex];
//	numvertices = (((u32)iter->bytes[1] >> 4) & 0xf) + 1;
//	vtx = (struct gfxvtx *)((s32)vtx + (iter->words.w1 & 0xffffff));
//	i = 0;
//
//	while (numvertices > 0) {
//		var800a6470[i].x = g_BgRooms[roomnum].pos.x + vtx->x;
//		var800a6470[i].y = g_BgRooms[roomnum].pos.y + vtx->y;
//		var800a6470[i].z = g_BgRooms[roomnum].pos.z + vtx->z;
//
//		i++;
//		vtx++;
//		numvertices--;
//	}
//
//	lowestsqdist = MAXFLOAT;
//	ret = false;
//
//	iter++;
//
//	while (iter->dma.cmd != G_VTX && iter->dma.cmd != G_ENDDL) {
//		if (iter->dma.cmd != G_TRI1 && iter->dma.cmd != G_TRI4) {
//			iter++;
//			continue;
//		}
//
//		if (iter->dma.cmd == G_TRI1) {
//			spf0 = 0;
//			spf4 = 0;
//			spdc[0] = iter->tri.tri.v[0] / 10;
//			spdc[1] = iter->tri.tri.v[1] / 10;
//			spdc[2] = iter->tri.tri.v[2] / 10;
//		} else if (iter->dma.cmd == G_TRI4) {
//			spf0 = 3;
//			spf4 = 1;
//			spdc[0] = iter->tri4.x1;
//			spdc[1] = iter->tri4.y1;
//			spdc[2] = iter->tri4.z1;
//		}
//
//		do {
//			if (spdc[0] || spdc[1] || spdc[2]) {
//				sp98.x = var800a6470[spdc[0]].x;
//
//				if (var800a6470[spdc[1]].x < sp98.x) {
//					sp98.x = var800a6470[spdc[1]].x;
//				}
//
//				if (var800a6470[spdc[2]].x < sp98.x) {
//					sp98.x = var800a6470[spdc[2]].x;
//				}
//
//				if (!(arg0->x < sp98.x) || !(arg1->x < sp98.x)) {
//					sp8c.x = var800a6470[spdc[0]].x;
//
//					if (sp8c.x < var800a6470[spdc[1]].x) {
//						sp8c.x = var800a6470[spdc[1]].x;
//					}
//
//					if (sp8c.x < var800a6470[spdc[2]].x) {
//						sp8c.x = var800a6470[spdc[2]].x;
//					}
//
//					if (!(sp8c.x < arg0->x) || !(sp8c.x < arg1->x)) {
//						sp98.z = var800a6470[spdc[0]].z;
//
//						if (var800a6470[spdc[1]].z < sp98.z) {
//							sp98.z = var800a6470[spdc[1]].z;
//						}
//
//						if (var800a6470[spdc[2]].z < sp98.z) {
//							sp98.z = var800a6470[spdc[2]].z;
//						}
//
//						if (!(arg0->z < sp98.z) || !(arg1->z < sp98.z)) {
//							sp8c.z = var800a6470[spdc[0]].z;
//
//							if (sp8c.z < var800a6470[spdc[1]].z) {
//								sp8c.z = var800a6470[spdc[1]].z;
//							}
//
//							if (sp8c.z < var800a6470[spdc[2]].z) {
//								sp8c.z = var800a6470[spdc[2]].z;
//							}
//
//							if (!(sp8c.z < arg0->z) || !(sp8c.z < arg1->z)) {
//								sp98.y = var800a6470[spdc[0]].y;
//
//								if (var800a6470[spdc[1]].y < sp98.y) {
//									sp98.y = var800a6470[spdc[1]].y;
//								}
//
//								if (var800a6470[spdc[2]].y < sp98.y) {
//									sp98.y = var800a6470[spdc[2]].y;
//								}
//
//								if (!(arg0->y < sp98.y) || !(arg1->y < sp98.y)) {
//									sp8c.y = var800a6470[spdc[0]].y;
//
//									if (sp8c.y < var800a6470[spdc[1]].y) {
//										sp8c.y = var800a6470[spdc[1]].y;
//									}
//
//									if (sp8c.y < var800a6470[spdc[2]].y) {
//										sp8c.y = var800a6470[spdc[2]].y;
//									}
//
//									if (!(sp8c.y < arg0->y) || !(sp8c.y < arg1->y)) {
//										if (bg0f15f2b0(arg0, arg2, &sp98, &sp8c)) {
//											if (func0002f560(&var800a6470[spdc[0]], &var800a6470[spdc[1]], &var800a6470[spdc[2]], 0, arg0, arg1, arg2, &spb0, &spa4)) {
//												f32 tmp;
//												f32 sqdist;
//
//												tmp = spb0.x - arg0->x;
//												sqdist = tmp * tmp;
//												tmp = spb0.y - arg0->y;
//												sqdist += tmp * tmp;
//												tmp = spb0.z - arg0->z;
//												sqdist += tmp * tmp;
//
//												if (sqdist < lowestsqdist) {
//													ret = true;
//
//													tmpgdl = iter;
//
//													while (tmpgdl->bytes[0] != G_SETTIMG && tmpgdl > gdl) {
//														tmpgdl--;
//													}
//
//													if (tmpgdl == gdl
//															|| (tmpgdl->words.w1 & 0x0f000000) == 0x0f000000
//															|| (tmpgdl->words.w1 & 0x05000000) == 0x05000000) {
//														texturenum = -1;
//													} else {
//														texturenum = *(s16 *)((tmpgdl->words.w1 - 8) | 0x80000000);
//													}
//
//													if (batch->type == VTXBATCHTYPE_XLU && g_Textures[texturenum].surfacetype == SURFACETYPE_DEFAULT) {
//														ret = false;
//													}
//
//													if (ret) {
//														lowestsqdist = sqdist;
//
//														hitthing->unk00.x = spb0.x;
//														hitthing->unk00.y = spb0.y;
//														hitthing->unk00.z = spb0.z;
//														hitthing->unk0c.x = spa4.x;
//														hitthing->unk0c.y = spa4.y;
//														hitthing->unk0c.z = spa4.z;
//														hitthing->unk18 = &vtx[spdc[0]];
//														hitthing->unk1c = &vtx[spdc[1]];
//														hitthing->texturenum = texturenum;
//														hitthing->unk24 = iter;
//														hitthing->unk28 = spf4;
//														hitthing->unk20 = &vtx[spdc[2]];
//														hitthing->unk2c = batch->type;
//													}
//												}
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//
//				spf0--;
//
//				if (spf0 == 2) {
//					spdc[0] = iter->tri4.x2;
//					spdc[1] = iter->tri4.y2;
//					spdc[2] = iter->tri4.z2;
//					spf4 = 2;
//				} else if (spf0 == 1) {
//					spdc[0] = iter->tri4.x3;
//					spdc[1] = iter->tri4.y3;
//					spdc[2] = iter->tri4.z3;
//					spf4 = 3;
//				} else if (spf0 == 0) {
//					spdc[0] = iter->tri4.x4;
//					spdc[1] = iter->tri4.y4;
//					spdc[2] = iter->tri4.z4;
//					spf4 = 1;
//				}
//			} else {
//				break;
//			}
//		} while (spf0 >= 0);
//
//		iter++;
//	}
//
//	return ret;
//}

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
bool bgCalculateHitInRoom(struct coord *frompos, struct coord *topos, s32 roomnum, struct hitthing *hitthing)
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
				if (bgCalculateHitInVtxBatch(&spb8, &spac, &spa0, &g_Rooms[roomnum].vtxbatches[var800a6538[j].vtxbatchindex], roomnum, hitthing)) {
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
		if (bgCalculateHitInVtxBatch(&spb8, &spac, &spa0, &batch[var800a6538[i].vtxbatchindex], roomnum, hitthing)) {
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
						if (bgCalculateHitInVtxBatch(&spb8, &spac, &spa0, &batch[var800a6538[i].vtxbatchindex], roomnum, &sp60)) {
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
								hitthing->unk24 = sp60.unk24;
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

		if (value < thing->unk0c) {
			if (roomnum != g_BgPortals[portalnum].roomnum1) {
				return false;
			}
		} else if (value > thing->unk10) {
			if (roomnum != g_BgPortals[portalnum].roomnum2) {
				return false;
			}
		}
	}

	return true;
}

GLOBAL_ASM(
glabel func0f161d30
/*  f161d30:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f161d34:	00053c00 */ 	sll	$a3,$a1,0x10
/*  f161d38:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f161d3c:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f161d40:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f161d44:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f161d48:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f161d4c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161d50:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f161d54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161d58:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f161d5c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f161d60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f161d64:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f161d68:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f161d6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f161d70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f161d74:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f161d78:	f7b60010 */ 	sdc1	$f22,0x10($sp)
/*  f161d7c:	f7b40008 */ 	sdc1	$f20,0x8($sp)
/*  f161d80:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f161d84:	03193021 */ 	addu	$a2,$t8,$t9
/*  f161d88:	c4c60030 */ 	lwc1	$f6,0x30($a2)
/*  f161d8c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f161d90:	00002825 */ 	or	$a1,$zero,$zero
/*  f161d94:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f161d98:	c4c80034 */ 	lwc1	$f8,0x34($a2)
/*  f161d9c:	3c09800a */ 	lui	$t1,%hi(g_RoomPortals)
/*  f161da0:	3c08800a */ 	lui	$t0,%hi(g_BgPortals)
/*  f161da4:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f161da8:	c4ca0038 */ 	lwc1	$f10,0x38($a2)
/*  f161dac:	3c0a800a */ 	lui	$t2,%hi(var800a4ccc)
/*  f161db0:	240b0014 */ 	addiu	$t3,$zero,0x14
/*  f161db4:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*  f161db8:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f161dbc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f161dc0:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f161dc4:	598000cc */ 	blezl	$t4,.L0f1620f8
/*  f161dc8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f161dcc:	4480b000 */ 	mtc1	$zero,$f22
/*  f161dd0:	8d294ce0 */ 	lw	$t1,%lo(g_RoomPortals)($t1)
/*  f161dd4:	8d084cc8 */ 	lw	$t0,%lo(g_BgPortals)($t0)
/*  f161dd8:	8d4a4ccc */ 	lw	$t2,%lo(var800a4ccc)($t2)
/*  f161ddc:	84ce000e */ 	lh	$t6,0xe($a2)
.L0f161de0:
/*  f161de0:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*  f161de4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f161de8:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f161dec:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f161df0:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f161df4:	872d0000 */ 	lh	$t5,0x0($t9)
/*  f161df8:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f161dfc:	01ab0019 */ 	multu	$t5,$t3
/*  f161e00:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f161e04:	010e8821 */ 	addu	$s1,$t0,$t6
/*  f161e08:	962f0000 */ 	lhu	$t7,0x0($s1)
/*  f161e0c:	01e88021 */ 	addu	$s0,$t7,$t0
/*  f161e10:	0000c012 */ 	mflo	$t8
/*  f161e14:	030a9021 */ 	addu	$s2,$t8,$t2
/*  f161e18:	c64e0000 */ 	lwc1	$f14,0x0($s2)
/*  f161e1c:	c6500004 */ 	lwc1	$f16,0x4($s2)
/*  f161e20:	c6420008 */ 	lwc1	$f2,0x8($s2)
/*  f161e24:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f161e28:	c654000c */ 	lwc1	$f20,0xc($s2)
/*  f161e2c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f161e30:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f161e34:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f161e38:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f161e3c:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f161e40:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f161e44:	460a2000 */ 	add.s	$f0,$f4,$f10
/*  f161e48:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f161e4c:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f161e50:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f161e54:	4614003c */ 	c.lt.s	$f0,$f20
/*  f161e58:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f161e5c:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f161e60:	45000007 */ 	bc1f	.L0f161e80
/*  f161e64:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f161e68:	4614903c */ 	c.lt.s	$f18,$f20
/*  f161e6c:	00000000 */ 	nop
/*  f161e70:	4502000f */ 	bc1fl	.L0f161eb0
/*  f161e74:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161e78:	1000009b */ 	b	.L0f1620e8
/*  f161e7c:	000c6840 */ 	sll	$t5,$t4,0x1
.L0f161e80:
/*  f161e80:	c6420010 */ 	lwc1	$f2,0x10($s2)
/*  f161e84:	4600103c */ 	c.lt.s	$f2,$f0
/*  f161e88:	00000000 */ 	nop
/*  f161e8c:	45020008 */ 	bc1fl	.L0f161eb0
/*  f161e90:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161e94:	4612103c */ 	c.lt.s	$f2,$f18
/*  f161e98:	00000000 */ 	nop
/*  f161e9c:	45020004 */ 	bc1fl	.L0f161eb0
/*  f161ea0:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161ea4:	10000090 */ 	b	.L0f1620e8
/*  f161ea8:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f161eac:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
.L0f161eb0:
/*  f161eb0:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f161eb4:	26140004 */ 	addiu	$s4,$s0,0x4
/*  f161eb8:	460c5101 */ 	sub.s	$f4,$f10,$f12
/*  f161ebc:	00006025 */ 	or	$t4,$zero,$zero
/*  f161ec0:	00606825 */ 	or	$t5,$v1,$zero
/*  f161ec4:	02809825 */ 	or	$s3,$s4,$zero
/*  f161ec8:	e7a40068 */ 	swc1	$f4,0x68($sp)
/*  f161ecc:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f161ed0:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f161ed4:	26150010 */ 	addiu	$s5,$s0,0x10
/*  f161ed8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f161edc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f161ee0:	e7aa006c */ 	swc1	$f10,0x6c($sp)
/*  f161ee4:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f161ee8:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f161eec:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f161ef0:	92170000 */ 	lbu	$s7,0x0($s0)
/*  f161ef4:	1ae00064 */ 	blez	$s7,.L0f162088
.L0f161ef8:
/*  f161ef8:	26d90001 */ 	addiu	$t9,$s6,0x1
/*  f161efc:	57370003 */ 	bnel	$t9,$s7,.L0f161f0c
/*  f161f00:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
/*  f161f04:	0280a825 */ 	or	$s5,$s4,$zero
/*  f161f08:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
.L0f161f0c:
/*  f161f0c:	c6640000 */ 	lwc1	$f4,0x0($s3)
/*  f161f10:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f161f14:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f161f18:	c66a0004 */ 	lwc1	$f10,0x4($s3)
/*  f161f1c:	c6a80004 */ 	lwc1	$f8,0x4($s5)
/*  f161f20:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f161f24:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f161f28:	c6680008 */ 	lwc1	$f8,0x8($s3)
/*  f161f2c:	c6a60008 */ 	lwc1	$f6,0x8($s5)
/*  f161f30:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f161f34:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f161f38:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f161f3c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f161f40:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*  f161f44:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f161f48:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f161f4c:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f161f50:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f161f54:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f161f58:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f161f5c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f161f60:	46064201 */ 	sub.s	$f8,$f8,$f6
/*  f161f64:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f161f68:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f161f6c:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f161f70:	46062102 */ 	mul.s	$f4,$f4,$f6
/*  f161f74:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f161f78:	46085282 */ 	mul.s	$f10,$f10,$f8
/*  f161f7c:	460a2101 */ 	sub.s	$f4,$f4,$f10
/*  f161f80:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f161f84:	460a4202 */ 	mul.s	$f8,$f8,$f10
/*  f161f88:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f161f8c:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f161f90:	460a3182 */ 	mul.s	$f6,$f6,$f10
/*  f161f94:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f161f98:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*  f161f9c:	46084182 */ 	mul.s	$f6,$f8,$f8
/*  f161fa0:	e7aa0054 */ 	swc1	$f10,0x54($sp)
/*  f161fa4:	46042202 */ 	mul.s	$f8,$f4,$f4
/*  f161fa8:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f161fac:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f161fb0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f161fb4:	46043080 */ 	add.s	$f2,$f6,$f4
/*  f161fb8:	46161032 */ 	c.eq.s	$f2,$f22
/*  f161fbc:	00000000 */ 	nop
/*  f161fc0:	45020004 */ 	bc1fl	.L0f161fd4
/*  f161fc4:	c66a0000 */ 	lwc1	$f10,0x0($s3)
/*  f161fc8:	1000002f */ 	b	.L0f162088
/*  f161fcc:	00006825 */ 	or	$t5,$zero,$zero
/*  f161fd0:	c66a0000 */ 	lwc1	$f10,0x0($s3)
.L0f161fd4:
/*  f161fd4:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f161fd8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f161fdc:	c66a0004 */ 	lwc1	$f10,0x4($s3)
/*  f161fe0:	460a2282 */ 	mul.s	$f10,$f4,$f10
/*  f161fe4:	460a3180 */ 	add.s	$f6,$f6,$f10
/*  f161fe8:	c66a0008 */ 	lwc1	$f10,0x8($s3)
/*  f161fec:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f161ff0:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f161ff4:	46085282 */ 	mul.s	$f10,$f10,$f8
/*  f161ff8:	46065280 */ 	add.s	$f10,$f10,$f6
/*  f161ffc:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*  f162000:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*  f162004:	e7aa0058 */ 	swc1	$f10,0x58($sp)
/*  f162008:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f16200c:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f162010:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f162014:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f162018:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f16201c:	46082102 */ 	mul.s	$f4,$f4,$f8
/*  f162020:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f162024:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f162028:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f16202c:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f162030:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f162034:	460a103c */ 	c.lt.s	$f2,$f10
/*  f162038:	00000000 */ 	nop
/*  f16203c:	45000007 */ 	bc1f	.L0f16205c
/*  f162040:	00000000 */ 	nop
/*  f162044:	15820003 */ 	bne	$t4,$v0,.L0f162054
/*  f162048:	00000000 */ 	nop
/*  f16204c:	1000000e */ 	b	.L0f162088
/*  f162050:	00006825 */ 	or	$t5,$zero,$zero
.L0f162054:
/*  f162054:	10000006 */ 	b	.L0f162070
/*  f162058:	00606025 */ 	or	$t4,$v1,$zero
.L0f16205c:
/*  f16205c:	55830004 */ 	bnel	$t4,$v1,.L0f162070
/*  f162060:	00406025 */ 	or	$t4,$v0,$zero
/*  f162064:	10000008 */ 	b	.L0f162088
/*  f162068:	00006825 */ 	or	$t5,$zero,$zero
/*  f16206c:	00406025 */ 	or	$t4,$v0,$zero
.L0f162070:
/*  f162070:	92170000 */ 	lbu	$s7,0x0($s0)
/*  f162074:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f162078:	2673000c */ 	addiu	$s3,$s3,0xc
/*  f16207c:	02d7082a */ 	slt	$at,$s6,$s7
/*  f162080:	1420ff9d */ 	bnez	$at,.L0f161ef8
/*  f162084:	26b5000c */ 	addiu	$s5,$s5,0xc
.L0f162088:
/*  f162088:	51a00016 */ 	beqzl	$t5,.L0f1620e4
/*  f16208c:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f162090:	c644000c */ 	lwc1	$f4,0xc($s2)
/*  f162094:	4604003c */ 	c.lt.s	$f0,$f4
/*  f162098:	00000000 */ 	nop
/*  f16209c:	45020007 */ 	bc1fl	.L0f1620bc
/*  f1620a0:	c6460010 */ 	lwc1	$f6,0x10($s2)
/*  f1620a4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f1620a8:	54ee000e */ 	bnel	$a3,$t6,.L0f1620e4
/*  f1620ac:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620b0:	10000011 */ 	b	.L0f1620f8
/*  f1620b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1620b8:	c6460010 */ 	lwc1	$f6,0x10($s2)
.L0f1620bc:
/*  f1620bc:	4600303c */ 	c.lt.s	$f6,$f0
/*  f1620c0:	00000000 */ 	nop
/*  f1620c4:	45020007 */ 	bc1fl	.L0f1620e4
/*  f1620c8:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620cc:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f1620d0:	54ef0004 */ 	bnel	$a3,$t7,.L0f1620e4
/*  f1620d4:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620d8:	10000007 */ 	b	.L0f1620f8
/*  f1620dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1620e0:	80cc0005 */ 	lb	$t4,0x5($a2)
.L0f1620e4:
/*  f1620e4:	000c6840 */ 	sll	$t5,$t4,0x1
.L0f1620e8:
/*  f1620e8:	00ad082a */ 	slt	$at,$a1,$t5
/*  f1620ec:	5420ff3c */ 	bnezl	$at,.L0f161de0
/*  f1620f0:	84ce000e */ 	lh	$t6,0xe($a2)
/*  f1620f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1620f8:
/*  f1620f8:	d7b40008 */ 	ldc1	$f20,0x8($sp)
/*  f1620fc:	d7b60010 */ 	ldc1	$f22,0x10($sp)
/*  f162100:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f162104:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f162108:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16210c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f162110:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f162114:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f162118:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f16211c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f162120:	03e00008 */ 	jr	$ra
/*  f162124:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

// Mismatch: Goal writes to sp40 and lower
//bool func0f161d30(struct coord *arg0, s16 roomnum)
//{
//	struct room *room;
//	s32 portalnum;
//	struct var800a4ccc *s2;
//	struct portalvertices *pvertices;
//	s32 i;
//	s32 j;
//	struct coord *cur;
//	struct coord *next;
//	f32 f0;
//	f32 f18;
//	s32 t4;
//	bool t5;
//
//	struct coord sp74;
//	struct coord sp68;
//	struct coord sp5c;
//	f32 sp58;
//	struct coord sp4c;
//
//	room = &g_Rooms[roomnum];
//
//	sp74.f[0] = room->centre.f[0];
//	sp74.f[1] = room->centre.f[1];
//	sp74.f[2] = room->centre.f[2];
//
//	for (i = 0; i < room->numportals; i++) {
//		portalnum = g_RoomPortals[room->roomportallistoffset + i];
//		pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
//		s2 = &var800a4ccc[portalnum];
//
//		f0 = arg0->f[0] * s2->coord.f[0] + arg0->f[1] * s2->coord.f[1] + arg0->f[2] * s2->coord.f[2];
//		f18 = sp74.f[0] * s2->coord.f[0] + sp74.f[1] * s2->coord.f[1] + sp74.f[2] * s2->coord.f[2];
//
//		if (f0 < s2->unk0c) {
//			if (f18 < s2->unk0c) {
//				continue;
//			}
//		} else {
//			if (f0 > s2->unk10 && f18 > s2->unk10) {
//				continue;
//			}
//		}
//
//		sp68.f[0] = sp74.f[0] - arg0->f[0];
//		sp68.f[1] = sp74.f[1] - arg0->f[1];
//		sp68.f[2] = sp74.f[2] - arg0->f[2];
//
//		t4 = 0;
//		t5 = true;
//		cur = &pvertices->vertices[0];
//		next = &pvertices->vertices[1];
//
//		for (j = 0; j < pvertices->count; j++) {
//			f32 tmp;
//			f32 sp44;
//			f32 sp40;
//			f32 sp3c;
//			f32 sp38;
//			f32 sp34;
//			f32 sp30;
//
//			if (j + 1 == pvertices->count) {
//				next = &pvertices->vertices[0];
//			}
//
//			sp5c.f[0] = next->f[0] - cur->f[0];
//			sp5c.f[1] = next->f[1] - cur->f[1];
//			sp5c.f[2] = next->f[2] - cur->f[2];
//
//			sp44 = sp68.f[0];
//			sp40 = sp68.f[1];
//			sp3c = sp68.f[2];
//
//			sp38 = sp5c.f[0];
//			sp34 = sp5c.f[1];
//			sp30 = sp5c.f[2];
//
//			sp4c.f[0] = sp34 * sp3c - sp30 * sp40;
//			sp4c.f[1] = sp30 * sp44 - sp38 * sp3c;
//			sp4c.f[2] = sp38 * sp40 - sp34 * sp44;
//
//			if (sp4c.f[0] * sp4c.f[0] + sp4c.f[1] * sp4c.f[1] + sp4c.f[2] * sp4c.f[2] == 0.0f) {
//				t5 = false;
//				break;
//			}
//
//			sp58 = sp4c.f[0] * cur->f[0] + sp4c.f[1] * cur->f[1] + sp4c.f[2] * cur->f[2];
//			tmp = sp4c.f[0] * arg0->f[0] + sp4c.f[1] * arg0->f[1] + sp4c.f[2] * arg0->f[2];
//
//			if (tmp < sp58) {
//				if (t4 == 2) {
//					t5 = false;
//					break;
//				}
//
//				t4 = 1;
//			} else if (t4 == 1) {
//				t5 = false;
//				break;
//			} else {
//				t4 = 2;
//			}
//
//			cur++;
//			next++;
//		}
//
//		if (t5) {
//			if (f0 < s2->unk0c) {
//				if (roomnum == g_BgPortals[portalnum].roomnum2) {
//					return false;
//				}
//			} else if (f0 > s2->unk10) {
//				if (roomnum == g_BgPortals[portalnum].roomnum1) {
//					return false;
//				}
//			}
//		}
//	}
//
//	return true;
//}

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

bool bgPushValue(bool value)
{
	g_BgCmdStack[g_BgCmdStackIndex] = value;
	g_BgCmdStackIndex = (g_BgCmdStackIndex + 1) % 20;

	return value;
}

bool bgPopValue(void)
{
	bool val = g_BgCmdStack[g_BgCmdStackIndex = (g_BgCmdStackIndex + 19) % 20];
	return val;
}

bool bgGetNthValueFromEnd(s32 n)
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
struct bgcmd *bgExecuteCommandsBranch(struct bgcmd *cmd, bool execute)
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
				bgPushValue(cmd->param);
			}
			cmd += cmd->len;
			break;
		case BGCMD_POP:
			if (execute) {
				bgPopValue();
			}
			cmd += cmd->len;
			break;
		case BGCMD_AND:
			if (execute) {
				bgPushValue(bgPopValue() & bgPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_OR:
			if (execute) {
				bgPushValue(bgPopValue() | bgPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_NOT:
			if (execute) {
				bgPushValue(bgPopValue() == 0);
			}
			cmd += cmd->len;
			break;
		case BGCMD_XOR:
			if (execute) {
				bgPushValue(bgPopValue() ^ bgPopValue());
			}
			cmd += cmd->len;
			break;
		case BGCMD_PUSH_CAMINROOMRANGE:
			if (execute) {
				bgPushValue(g_CamRoom >= cmd[1].param && g_CamRoom <= cmd[2].param);
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_TRUE:
			if (execute) {
				var800a65c0.xmin = g_Vars.currentplayer->screenxminf;
				var800a65c0.ymin = g_Vars.currentplayer->screenyminf;
				var800a65c0.xmax = g_Vars.currentplayer->screenxmaxf;
				var800a65c0.ymax = g_Vars.currentplayer->screenymaxf;
				g_BgCmdResult = BGRESULT_TRUE;
			}
			cmd += cmd->len;
			break;
		case BGCMD_SETRESULT_IFPORTALINFOV:
			if (execute) {
				if (!PORTAL_IS_CLOSED(cmd[1].param)) {
					if (g_PortalGetScreenBbox(cmd[1].param, &g_PortalScreenBbox) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (boxGetIntersection(&var800a65c0, &g_PortalScreenBbox) == 0) {
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
					if (g_PortalGetScreenBbox(cmd[1].param, &portalbox) && boxGetIntersection(&var800a65c0, &portalbox)) {
						if (g_BgCmdResult != BGRESULT_TRUE) {
							boxCopy(&var800a65c0, &portalbox);
							g_BgCmdResult = BGRESULT_TRUE;
						} else {
							boxExpand(&var800a65c0, &portalbox);
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
					} else if (g_PortalGetScreenBbox(cmd[1].param, &portalbox) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (boxGetIntersection(&portalbox, (struct screenbox *)&g_Vars.currentplayer->screenxminf) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					} else if (boxGetIntersection(&g_PortalScreenBbox, &portalbox) == 0) {
						g_BgCmdResult = BGRESULT_FALSE;
					}
				}
			}
			cmd += cmd->len;
			break;
		case BGCMD_IFRESULT_SHOWROOM:
			if (execute) {
				if (g_BgCmdResult == BGRESULT_TRUE && func0f15cd90(cmd[1].param, &var800a65c0)) {
					roomSetOnscreen(cmd[1].param, 0, &var800a65c0);
					g_ActiveRoomNums[g_NumActiveRooms++] = cmd[1].param;
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
				bgPushValue(!PORTAL_IS_CLOSED(cmd[1].param));
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
			cmd = bgExecuteCommandsBranch(cmd + cmd->len, execute);
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
			cmd = bgExecuteCommandsBranch(cmd + cmd->len, bgPopValue() & execute);
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

struct bgcmd *bgExecuteCommands(struct bgcmd *cmd)
{
	struct player *player = g_Vars.currentplayer;
	g_BgCmdResult = BGRESULT_TRUE;

	if (!cmd) {
		return cmd;
	}

	// This may have been used in an osSyncPrintf call
	bgGetNthValueFromEnd(0);

	var800a65c0.xmin = player->screenxminf;
	var800a65c0.ymin = player->screenyminf;
	var800a65c0.xmax = player->screenxmaxf;
	var800a65c0.ymax = player->screenymaxf;

	return bgExecuteCommandsBranch(cmd, true);
}

GLOBAL_ASM(
glabel bgTickPortalsXray
/*  f162d9c:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f162da0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f162da4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f162da8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f162dac:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f162db0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f162db4:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f162db8:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f162dbc:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f162dc0:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f162dc4:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f162dc8:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f162dcc:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f162dd0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f162dd4:	0fc591d2 */ 	jal	currentPlayerCalculateScreenProperties
/*  f162dd8:	8e160284 */ 	lw	$s6,0x284($s0)
/*  f162ddc:	3c038008 */ 	lui	$v1,%hi(var8007fc34)
/*  f162de0:	2463fc34 */ 	addiu	$v1,$v1,%lo(var8007fc34)
/*  f162de4:	3c028008 */ 	lui	$v0,%hi(var8007fc30)
/*  f162de8:	8c42fc30 */ 	lw	$v0,%lo(var8007fc30)($v0)
/*  f162dec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f162df0:	01c2082a */ 	slt	$at,$t6,$v0
/*  f162df4:	50200003 */ 	beqzl	$at,.L0f162e04
/*  f162df8:	c6c41794 */ 	lwc1	$f4,0x1794($s6)
/*  f162dfc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f162e00:	c6c41794 */ 	lwc1	$f4,0x1794($s6)
.L0f162e04:
/*  f162e04:	00002025 */ 	or	$a0,$zero,$zero
/*  f162e08:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162e0c:	44183000 */ 	mfc1	$t8,$f6
/*  f162e10:	00000000 */ 	nop
/*  f162e14:	a7b8007c */ 	sh	$t8,0x7c($sp)
/*  f162e18:	c6c81798 */ 	lwc1	$f8,0x1798($s6)
/*  f162e1c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f162e20:	44085000 */ 	mfc1	$t0,$f10
/*  f162e24:	00000000 */ 	nop
/*  f162e28:	a7a8007e */ 	sh	$t0,0x7e($sp)
/*  f162e2c:	c6d0179c */ 	lwc1	$f16,0x179c($s6)
/*  f162e30:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f162e34:	440a9000 */ 	mfc1	$t2,$f18
/*  f162e38:	00000000 */ 	nop
/*  f162e3c:	a7aa0080 */ 	sh	$t2,0x80($sp)
/*  f162e40:	c6c417a0 */ 	lwc1	$f4,0x17a0($s6)
/*  f162e44:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162e48:	440c3000 */ 	mfc1	$t4,$f6
/*  f162e4c:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f162e50:	a7ac0082 */ 	sh	$t4,0x82($sp)
/*  f162e54:	24010016 */ 	addiu	$at,$zero,0x16
/*  f162e58:	5441000d */ 	bnel	$v0,$at,.L0f162e90
/*  f162e5c:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e60:	8ecd17a4 */ 	lw	$t5,0x17a4($s6)
/*  f162e64:	55a0000a */ 	bnezl	$t5,.L0f162e90
/*  f162e68:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e6c:	0fc2d5ee */ 	jal	camGetLodScaleZ
/*  f162e70:	00000000 */ 	nop
/*  f162e74:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e78:	44814000 */ 	mtc1	$at,$f8
/*  f162e7c:	00000000 */ 	nop
/*  f162e80:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f162e84:	10000005 */ 	b	.L0f162e9c
/*  f162e88:	e6ca002c */ 	swc1	$f10,0x2c($s6)
/*  f162e8c:	3c01c3fa */ 	lui	$at,0xc3fa
.L0f162e90:
/*  f162e90:	44818000 */ 	mtc1	$at,$f16
/*  f162e94:	00000000 */ 	nop
/*  f162e98:	e6d0002c */ 	swc1	$f16,0x2c($s6)
.L0f162e9c:
/*  f162e9c:	44800000 */ 	mtc1	$zero,$f0
/*  f162ea0:	00000000 */ 	nop
/*  f162ea4:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f162ea8:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f162eac:	c6d2002c */ 	lwc1	$f18,0x2c($s6)
/*  f162eb0:	0fc2d5de */ 	jal	camGetProjectionMtxF
/*  f162eb4:	e7b2009c */ 	swc1	$f18,0x9c($sp)
/*  f162eb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f162ebc:	0c0056d9 */ 	jal	mtx4TransformVecInPlace
/*  f162ec0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f162ec4:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f162ec8:	3c047f1b */ 	lui	$a0,%hi(var7f1b75ac)
/*  f162ecc:	3c058008 */ 	lui	$a1,%hi(edist)
/*  f162ed0:	e6c40018 */ 	swc1	$f4,0x18($s6)
/*  f162ed4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f162ed8:	24a5fcb0 */ 	addiu	$a1,$a1,%lo(edist)
/*  f162edc:	248475ac */ 	addiu	$a0,$a0,%lo(var7f1b75ac)
/*  f162ee0:	e6c6001c */ 	swc1	$f6,0x1c($s6)
/*  f162ee4:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f162ee8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f162eec:	e6c80020 */ 	swc1	$f8,0x20($s6)
/*  f162ef0:	0fc59570 */ 	jal	stageGetCurrent
/*  f162ef4:	00000000 */ 	nop
/*  f162ef8:	844e002e */ 	lh	$t6,0x2e($v0)
/*  f162efc:	3c148008 */ 	lui	$s4,%hi(var8007fc2c)
/*  f162f00:	2694fc2c */ 	addiu	$s4,$s4,%lo(var8007fc2c)
/*  f162f04:	448e5000 */ 	mtc1	$t6,$f10
/*  f162f08:	3c018008 */ 	lui	$at,%hi(var8007fc30)
/*  f162f0c:	3c06800a */ 	lui	$a2,%hi(var800a4640)
/*  f162f10:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f162f14:	24c64640 */ 	addiu	$a2,$a2,%lo(var800a4640)
/*  f162f18:	3c17800a */ 	lui	$s7,%hi(var800a4ce4+0x2)
/*  f162f1c:	3c1e800a */ 	lui	$s8,%hi(var800a4ce4)
/*  f162f20:	27de4ce4 */ 	addiu	$s8,$s8,%lo(var800a4ce4)
/*  f162f24:	26f74ce6 */ 	addiu	$s7,$s7,%lo(var800a4ce4+0x2)
/*  f162f28:	e6d00024 */ 	swc1	$f16,0x24($s6)
/*  f162f2c:	84580030 */ 	lh	$t8,0x30($v0)
/*  f162f30:	844f002e */ 	lh	$t7,0x2e($v0)
/*  f162f34:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f162f38:	44983000 */ 	mtc1	$t8,$f6
/*  f162f3c:	448f9000 */ 	mtc1	$t7,$f18
/*  f162f40:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f162f44:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f162f48:	240d7fff */ 	addiu	$t5,$zero,0x7fff
/*  f162f4c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f162f50:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f162f54:	3c15800a */ 	lui	$s5,%hi(g_Rooms)
/*  f162f58:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f162f5c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f162f60:	e6ca0028 */ 	swc1	$f10,0x28($s6)
/*  f162f64:	c6d20028 */ 	lwc1	$f18,0x28($s6)
/*  f162f68:	c7b00094 */ 	lwc1	$f16,0x94($sp)
/*  f162f6c:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f162f70:	87a9007c */ 	lh	$t1,0x7c($sp)
/*  f162f74:	46128180 */ 	add.s	$f6,$f16,$f18
/*  f162f78:	c7b2009c */ 	lwc1	$f18,0x9c($sp)
/*  f162f7c:	87aa007e */ 	lh	$t2,0x7e($sp)
/*  f162f80:	87ab0080 */ 	lh	$t3,0x80($sp)
/*  f162f84:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f162f88:	c6c80028 */ 	lwc1	$f8,0x28($s6)
/*  f162f8c:	87ac0082 */ 	lh	$t4,0x82($sp)
/*  f162f90:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f162f94:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f162f98:	c6c60028 */ 	lwc1	$f6,0x28($s6)
/*  f162f9c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f162fa0:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f162fa4:	c6ca0028 */ 	lwc1	$f10,0x28($s6)
/*  f162fa8:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f162fac:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f162fb0:	c6c80028 */ 	lwc1	$f8,0x28($s6)
/*  f162fb4:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f162fb8:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f162fbc:	c6c60028 */ 	lwc1	$f6,0x28($s6)
/*  f162fc0:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f162fc4:	ac20fc30 */ 	sw	$zero,%lo(var8007fc30)($at)
/*  f162fc8:	8e0402bc */ 	lw	$a0,0x2bc($s0)
/*  f162fcc:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f162fd0:	a4d902d0 */ 	sh	$t9,0x2d0($a2)
/*  f162fd4:	28810002 */ 	slti	$at,$a0,0x2
/*  f162fd8:	a0c802d3 */ 	sb	$t0,0x2d3($a2)
/*  f162fdc:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f162fe0:	a6e00000 */ 	sh	$zero,0x0($s7)
/*  f162fe4:	a7cd0000 */ 	sh	$t5,0x0($s8)
/*  f162fe8:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f162fec:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f162ff0:	a4c902d4 */ 	sh	$t1,0x2d4($a2)
/*  f162ff4:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f162ff8:	a4ca02d6 */ 	sh	$t2,0x2d6($a2)
/*  f162ffc:	a4cb02d8 */ 	sh	$t3,0x2d8($a2)
/*  f163000:	142000a5 */ 	bnez	$at,.L0f163298
/*  f163004:	a4cc02da */ 	sh	$t4,0x2da($a2)
/*  f163008:	3c013f00 */ 	lui	$at,0x3f00
/*  f16300c:	4481a000 */ 	mtc1	$at,$f20
/*  f163010:	26b54928 */ 	addiu	$s5,$s5,%lo(g_Rooms)
.L0f163014:
/*  f163014:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f163018:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f16301c:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f163020:	01d38021 */ 	addu	$s0,$t6,$s3
/*  f163024:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*  f163028:	4606503c */ 	c.lt.s	$f10,$f6
/*  f16302c:	00000000 */ 	nop
/*  f163030:	45030096 */ 	bc1tl	.L0f16328c
/*  f163034:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163038:	c6080024 */ 	lwc1	$f8,0x24($s0)
/*  f16303c:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f163040:	4610403c */ 	c.lt.s	$f8,$f16
/*  f163044:	00000000 */ 	nop
/*  f163048:	45030090 */ 	bc1tl	.L0f16328c
/*  f16304c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163050:	c6120020 */ 	lwc1	$f18,0x20($s0)
/*  f163054:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f163058:	4612203c */ 	c.lt.s	$f4,$f18
/*  f16305c:	00000000 */ 	nop
/*  f163060:	4503008a */ 	bc1tl	.L0f16328c
/*  f163064:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163068:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f16306c:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f163070:	4606503c */ 	c.lt.s	$f10,$f6
/*  f163074:	00000000 */ 	nop
/*  f163078:	45030084 */ 	bc1tl	.L0f16328c
/*  f16307c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163080:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*  f163084:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f163088:	4610403c */ 	c.lt.s	$f8,$f16
/*  f16308c:	00000000 */ 	nop
/*  f163090:	4503007e */ 	bc1tl	.L0f16328c
/*  f163094:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163098:	c6040028 */ 	lwc1	$f4,0x28($s0)
/*  f16309c:	4612203c */ 	c.lt.s	$f4,$f18
/*  f1630a0:	00000000 */ 	nop
/*  f1630a4:	45030079 */ 	bc1tl	.L0f16328c
/*  f1630a8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1630ac:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1630b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1630b4:	2861003c */ 	slti	$at,$v1,0x3c
/*  f1630b8:	10200073 */ 	beqz	$at,.L0f163288
/*  f1630bc:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1630c0:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f1630c4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1630c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1630cc:	35f80004 */ 	ori	$t8,$t7,0x4
/*  f1630d0:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f1630d4:	00d98821 */ 	addu	$s1,$a2,$t9
/*  f1630d8:	a6320000 */ 	sh	$s2,0x0($s1)
/*  f1630dc:	0fc55f6c */ 	jal	roomUnpauseProps
/*  f1630e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1630e4:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f1630e8:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f1630ec:	01138021 */ 	addu	$s0,$t0,$s3
/*  f1630f0:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*  f1630f4:	c6060024 */ 	lwc1	$f6,0x24($s0)
/*  f1630f8:	c612001c */ 	lwc1	$f18,0x1c($s0)
/*  f1630fc:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f163100:	c60a0028 */ 	lwc1	$f10,0x28($s0)
/*  f163104:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f163108:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f16310c:	c612002c */ 	lwc1	$f18,0x2c($s0)
/*  f163110:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f163114:	46048001 */ 	sub.s	$f0,$f16,$f4
/*  f163118:	c6040020 */ 	lwc1	$f4,0x20($s0)
/*  f16311c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f163120:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f163124:	46104081 */ 	sub.s	$f2,$f8,$f16
/*  f163128:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f16312c:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f163130:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f163134:	00000000 */ 	nop
/*  f163138:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f16313c:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f163140:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f163144:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f163148:	0c012974 */ 	jal	sqrtf
/*  f16314c:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f163150:	3c0142c8 */ 	lui	$at,0x42c8
/*  f163154:	44813000 */ 	mtc1	$at,$f6
/*  f163158:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f16315c:	3c038008 */ 	lui	$v1,%hi(var8007fc30)
/*  f163160:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f163164:	3c014f00 */ 	lui	$at,0x4f00
/*  f163168:	2463fc30 */ 	addiu	$v1,$v1,%lo(var8007fc30)
/*  f16316c:	4449f800 */ 	cfc1	$t1,$31
/*  f163170:	44caf800 */ 	ctc1	$t2,$31
/*  f163174:	00000000 */ 	nop
/*  f163178:	46004424 */ 	cvt.w.s	$f16,$f8
/*  f16317c:	444af800 */ 	cfc1	$t2,$31
/*  f163180:	00000000 */ 	nop
/*  f163184:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f163188:	51400013 */ 	beqzl	$t2,.L0f1631d8
/*  f16318c:	440a8000 */ 	mfc1	$t2,$f16
/*  f163190:	44818000 */ 	mtc1	$at,$f16
/*  f163194:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f163198:	46104401 */ 	sub.s	$f16,$f8,$f16
/*  f16319c:	44caf800 */ 	ctc1	$t2,$31
/*  f1631a0:	00000000 */ 	nop
/*  f1631a4:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f1631a8:	444af800 */ 	cfc1	$t2,$31
/*  f1631ac:	00000000 */ 	nop
/*  f1631b0:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f1631b4:	15400005 */ 	bnez	$t2,.L0f1631cc
/*  f1631b8:	00000000 */ 	nop
/*  f1631bc:	440a8000 */ 	mfc1	$t2,$f16
/*  f1631c0:	3c018000 */ 	lui	$at,0x8000
/*  f1631c4:	10000007 */ 	b	.L0f1631e4
/*  f1631c8:	01415025 */ 	or	$t2,$t2,$at
.L0f1631cc:
/*  f1631cc:	10000005 */ 	b	.L0f1631e4
/*  f1631d0:	240affff */ 	addiu	$t2,$zero,-1
/*  f1631d4:	440a8000 */ 	mfc1	$t2,$f16
.L0f1631d8:
/*  f1631d8:	00000000 */ 	nop
/*  f1631dc:	0540fffb */ 	bltz	$t2,.L0f1631cc
/*  f1631e0:	00000000 */ 	nop
.L0f1631e4:
/*  f1631e4:	86eb0000 */ 	lh	$t3,0x0($s7)
/*  f1631e8:	314200ff */ 	andi	$v0,$t2,0xff
/*  f1631ec:	44c9f800 */ 	ctc1	$t1,$31
/*  f1631f0:	0162082a */ 	slt	$at,$t3,$v0
/*  f1631f4:	10200002 */ 	beqz	$at,.L0f163200
/*  f1631f8:	a22a0003 */ 	sb	$t2,0x3($s1)
/*  f1631fc:	a6e20000 */ 	sh	$v0,0x0($s7)
.L0f163200:
/*  f163200:	87cc0000 */ 	lh	$t4,0x0($s8)
/*  f163204:	004c082a */ 	slt	$at,$v0,$t4
/*  f163208:	50200003 */ 	beqzl	$at,.L0f163218
/*  f16320c:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f163210:	a7c20000 */ 	sh	$v0,0x0($s8)
/*  f163214:	8e990000 */ 	lw	$t9,0x0($s4)
.L0f163218:
/*  f163218:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f16321c:	87ad007c */ 	lh	$t5,0x7c($sp)
/*  f163220:	87ae007e */ 	lh	$t6,0x7e($sp)
/*  f163224:	87af0080 */ 	lh	$t7,0x80($sp)
/*  f163228:	87b80082 */ 	lh	$t8,0x82($sp)
/*  f16322c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f163230:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f163234:	ae880000 */ 	sw	$t0,0x0($s4)
/*  f163238:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f16323c:	a62d0004 */ 	sh	$t5,0x4($s1)
/*  f163240:	a62e0006 */ 	sh	$t6,0x6($s1)
/*  f163244:	a62f0008 */ 	sh	$t7,0x8($s1)
/*  f163248:	a638000a */ 	sh	$t8,0xa($s1)
/*  f16324c:	8ecc1ba0 */ 	lw	$t4,0x1ba0($s6)
/*  f163250:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f163254:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x2bc)
/*  f163258:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f16325c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f163260:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f163264:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f163268:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16326c:	016d1021 */ 	addu	$v0,$t3,$t5
/*  f163270:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f163274:	3c06800a */ 	lui	$a2,%hi(var800a4640)
/*  f163278:	24c64640 */ 	addiu	$a2,$a2,%lo(var800a4640)
/*  f16327c:	35cf0004 */ 	ori	$t7,$t6,0x4
/*  f163280:	a44f0000 */ 	sh	$t7,0x0($v0)
/*  f163284:	8c84a27c */ 	lw	$a0,%lo(g_Vars+0x2bc)($a0)
.L0f163288:
/*  f163288:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f16328c:
/*  f16328c:	0244082a */ 	slt	$at,$s2,$a0
/*  f163290:	1420ff60 */ 	bnez	$at,.L0f163014
/*  f163294:	2673008c */ 	addiu	$s3,$s3,0x8c
.L0f163298:
/*  f163298:	0fc58e5f */ 	jal	bgChooseRoomsToLoad
/*  f16329c:	00000000 */ 	nop
/*  f1632a0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1632a4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1632a8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1632ac:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1632b0:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1632b4:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1632b8:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1632bc:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f1632c0:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f1632c4:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f1632c8:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f1632cc:	03e00008 */ 	jr	$ra
/*  f1632d0:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

const char var7f1b75ac[] = "edist";

u32 edist = 400;

// Mismatch: Regalloc and some reordered instructions. Related to var800a4640.
//void bgTickPortalsXray(void)
//{
//	struct coord vismax; // ac
//	struct coord vismin; // a0
//	struct coord eraserpos; // 94
//	struct coord vismid; // 88
//	struct player *player = g_Vars.currentplayer;
//	s16 ymax; // 82
//	s16 xmax; // 80
//	s16 ymin; // 7e
//	s16 xmin; // 7c
//	struct stagetableentry *stage;
//	s32 i;
//	u32 stack;
//
//	static u32 edist = 400;
//
//	currentPlayerCalculateScreenProperties();
//
//	if (var8007fc34 < var8007fc30) {
//		var8007fc34 = var8007fc30;
//	}
//
//	xmin = player->screenxminf;
//	ymin = player->screenyminf;
//	xmax = player->screenxmaxf;
//	ymax = player->screenymaxf;
//
//	if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT && player->gunsightoff == 0) {
//		player->eraserdepth = -500.0f / camGetLodScaleZ();
//	} else {
//		player->eraserdepth = -500.0f;
//	}
//
//	eraserpos.f[0] = 0.0f;
//	eraserpos.f[1] = 0.0f;
//	eraserpos.f[2] = player->eraserdepth;
//
//	mtx4TransformVecInPlace(camGetProjectionMtxF(), &eraserpos);
//
//	player->eraserpos.f[0] = eraserpos.f[0];
//	player->eraserpos.f[1] = eraserpos.f[1];
//	player->eraserpos.f[2] = eraserpos.f[2];
//
//	mainOverrideVariable("edist", &edist);
//
//	stage = stageGetCurrent();
//
//	player->eraserpropdist = stage->eraserpropdist;
//	player->eraserbgdist = (f32) stage->eraserpropdist + stage->unk30;
//
//	vismax.f[0] = eraserpos.f[0] + player->eraserbgdist;
//	vismax.f[1] = eraserpos.f[1] + player->eraserbgdist;
//	vismax.f[2] = eraserpos.f[2] + player->eraserbgdist;
//
//	vismin.f[0] = eraserpos.f[0] - player->eraserbgdist;
//	vismin.f[1] = eraserpos.f[1] - player->eraserbgdist;
//	vismin.f[2] = eraserpos.f[2] - player->eraserbgdist;
//
//	vismid.f[0] = eraserpos.f[0];
//	vismid.f[1] = eraserpos.f[1];
//	vismid.f[2] = eraserpos.f[2];
//
//	var8007fc2c = 0;
//	var8007fc30 = 0;
//
//	var800a4640.unk2d0.roomnum = -1;
//	var800a4640.unk2d0.draworder = 255;
//	var800a4640.unk2d0.box.xmin = xmin;
//	var800a4640.unk2d0.box.ymin = ymin;
//	var800a4640.unk2d0.box.xmax = xmax;
//	var800a4640.unk2d0.box.ymax = ymax;
//
//	var800a4ce6 = 0;
//	var800a4ce4 = 0x7fff;
//
//	for (i = 1; i < g_Vars.roomcount; i++) {
//		if (!(vismax.f[0] < g_Rooms[i].bbmin[0]) && !(vismin.f[0] > g_Rooms[i].bbmax[0])
//				&& !(vismax.f[2] < g_Rooms[i].bbmin[2]) && !(vismin.f[2] > g_Rooms[i].bbmax[2])
//				&& !(vismax.f[1] < g_Rooms[i].bbmin[1]) && !(vismin.f[1] > g_Rooms[i].bbmax[1])) {
//			s32 index = var8007fc2c;
//
//			if (1);
//			if (1);
//
//			if (index < 60) {
//				f32 x;
//				f32 y;
//				f32 z;
//
//				if (var800a4640.unk000[index].roomnum); \
//				g_Rooms[i].flags |= ROOMFLAG_ONSCREEN;
//
//				var800a4640.unk000[index].roomnum = i;
//
//				roomUnpauseProps(i, false);
//
//				x = (g_Rooms[i].bbmin[0] + g_Rooms[i].bbmax[0]) / 2.0f - vismid.f[0];
//				y = (g_Rooms[i].bbmin[1] + g_Rooms[i].bbmax[1]) / 2.0f - vismid.f[1];
//				z = (g_Rooms[i].bbmin[2] + g_Rooms[i].bbmax[2]) / 2.0f - vismid.f[2];
//
//				var800a4640.unk000[index].draworder = sqrtf(x * x + y * y + z * z) / 100.0f;
//
//				if (var800a4640.unk000[index].draworder > var800a4ce6) {
//					var800a4ce6 = var800a4640.unk000[index].draworder;
//				}
//
//				if (var800a4640.unk000[index].draworder < var800a4ce4) {
//					var800a4ce4 = var800a4640.unk000[index].draworder;
//				}
//
//				var800a4640.unk000[index].box.xmin = xmin;
//				var800a4640.unk000[index].box.ymin = ymin;
//				var800a4640.unk000[index].box.xmax = xmax;
//				var800a4640.unk000[index].box.ymax = ymax;
//
//				var8007fc2c++;
//				var8007fc30++;
//
//				g_Rooms[player->cam_room].flags |= ROOMFLAG_ONSCREEN;
//			} else {
//				// empty
//			}
//		}
//	}
//
//	bgChooseRoomsToLoad();
//
//	if (1);
//	if (1);
//}

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

			if (sum < thing->unk0c) {
				g_PortalThings[portalnum].unk02 = 1;
			} else if (sum > thing->unk10) {
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

		bgExecuteCommands(g_BgCommands);

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
	sp28.unk0c = ptr->unk0c;
	sp28.unk10 = ptr->unk10;

	tmp1 = sp28.coord.f[0] * room1centre.f[0] + sp28.coord.f[1] * room1centre.f[1] + sp28.coord.f[2] * room1centre.f[2];

	if (tmp1);

	sp18 = 0;

	if (tmp1 > sp28.unk10) {
		sp18 = 1;

		portalSwapRooms(portalnum);

		sp28.coord.x = -sp28.coord.x;
		sp28.coord.y = -sp28.coord.y;
		sp28.coord.z = -sp28.coord.z;

		tmp = sp28.unk0c;
		sp28.unk0c = -sp28.unk10;
		sp28.unk10 = -tmp;
	}

	tmp2 = sp28.coord.f[0] * room2centre.f[0] + sp28.coord.f[1] * room2centre.f[1] + sp28.coord.f[2] * room2centre.f[2];

	if (tmp2 <= sp28.unk0c && sp18) {
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
		thing.unk0c = (var800a4ccc + portalnum)->unk0c;
		thing.unk10 = (var800a4ccc + portalnum)->unk10;

		if (roomnum == g_BgPortals[portalnum].roomnum1) {
			thing.coord.f[0] = -thing.coord.f[0];
			thing.coord.f[1] = -thing.coord.f[1];
			thing.coord.f[2] = -thing.coord.f[2];

			tmp = thing.unk0c;
			thing.unk0c = -thing.unk10;
			thing.unk10 = -tmp;
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

				if (tmp < thing.unk0c) {
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
