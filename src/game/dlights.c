#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/gfxmemory.h"
#include "game/propsnd.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/bg.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/game_176080.h"
#include "game/mplayer/scenarios.h"
#include "game/portal.h"
#include "game/propobj.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_17ce0.h"
#include "lib/lib_2f490.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

const char var7f1a78e0[] = "LIGHTS : Hit occured on light %d in room %d\n";
const char var7f1a7910[] = "L2(%d) -> ";
const char var7f1a791c[] = "L2 -> BUILD LIGHTS TRANSFER TABLE - Starting\n";
const char var7f1a794c[] = "L2(%d) -> ";
const char var7f1a7958[] = "L2_BuildTransferTables -> Found %d portals\n";
const char var7f1a7984[] = "L2(%d) -> ";
const char var7f1a7990[] = "L2_BuildTransferTables -> Found %d rooms\n";
const char var7f1a79bc[] = "L2(%d) -> ";
const char var7f1a79c8[] = "L2_BuildTransferTables -> Alloc %u bytes of free memory\n";
const char var7f1a7a04[] = "L2(%d) -> ";
const char var7f1a7a10[] = "L2_BuildTransferTables -> Alloc %u bytes for scratch\n";
const char var7f1a7a48[] = "L2(%d) -> ";
const char var7f1a7a54[] = "L2 -> Building room based light transmission table\n";
const char var7f1a7a88[] = "L2(%d) -> ";
const char var7f1a7a94[] = "L2 -> Finished\n";
const char var7f1a7aa4[] = "L2(%d) -> ";
const char var7f1a7ab0[] = "L2 -> Generating room parameters from BG data\n";
const char var7f1a7ae0[] = "L2(%d) -> ";
const char var7f1a7aec[] = "L2 -> Light2_ProcessBgParams room %d does not have a 3D bounding box => Room Volume is bodged!\n";
const char var7f1a7b4c[] = "L2(%d) -> ";
const char var7f1a7b58[] = "%s%sL2 -> Surface area bodged for room %d - using %f\n";
const char var7f1a7b90[] = "";
const char var7f1a7b94[] = "";
const char var7f1a7b98[] = "L2(%d) -> ";
const char var7f1a7ba4[] = "L2 -> Finished\n";

s32 *var8009cad0;
u32 var8009cad4;
s32 *var8009cad8;
s32 g_NumPortals;
s32 var8009cae0;
s32 var8009cae4;
f32 (*var8009cae8)(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2);
u8 var8009caec;
u8 var8009caed;
u8 var8009caee;
u8 var8009caef;
u8 var8009caf0;

struct var80061420 *var80061420 = NULL;
u32 var80061424 = 0x00000000;
struct coord *var80061428 = NULL;
u16 **var8006142c = NULL;
u16 **var80061430 = NULL;
f32 *var80061434 = NULL;
bool *var80061438 = NULL;
f32 var8006143c = 50;
u32 var80061440 = 0x00000000;
u32 var80061444 = 1;
u32 var80061448 = 0x00000000;
bool g_IsSwitchingGoggles = false;
u32 var80061450 = 0x00000000;
u32 var80061454 = 0xffffffff;

#if VERSION >= VERSION_NTSC_1_0
s32 var80061458 = 0x00000000;
u32 var8006145c = 0x00000000;
#endif

Lights1 var80061460 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0x4d, 0x4d, 0x2e);

u32 func0f000920(s32 portalnum1, s32 portalnum2)
{
	if (portalnum1 != portalnum2) {
		s32 upper = (portalnum1 > portalnum2) ? portalnum1 : portalnum2;
		s32 lower = (portalnum1 < portalnum2) ? portalnum1 : portalnum2;

		return var80061430[upper][lower];
	}

	return 0;
}

struct light *roomGetLight(s32 roomnum, s32 lightnum)
{
	return (struct light *)&g_BgLightsFileData[(g_Rooms[roomnum].lightindex + lightnum) * 0x22];
}

u8 func0f0009c0(s32 roomnum)
{
	s32 value = g_Rooms[roomnum].unk52 + g_Rooms[roomnum].unk4b;

	if (value > 255) {
		value = 255;
	}

	if (value < 0) {
		value = 0;
	}

	return value;
}

u8 func0f000a10(s32 roomnum)
{
	s32 value = g_Rooms[roomnum].unk52;

	value += g_Rooms[roomnum].unk4b;

	if (value > 255) {
		value = 255;
	}

	if (value < 0) {
		value = 0;
	}

	return value;
}

u8 func0f000b18(u32 arg0)
{
	return 255;
}

u8 func0f000b24(s32 roomnum)
{
	u32 value;

	if (g_Rooms[roomnum].flags & ROOMFLAG_0040) {
		value = g_Rooms[roomnum].unk4b;
	} else {
		value = 255;
	}

	return value;
}

u8 roomGetBrightness(s32 room)
{
	return g_Rooms[room].brightness & 0xff;
}

s32 func0f000c54(s32 roomnum)
{
	if (g_Rooms[roomnum].unk52 > 255) {
		return 255;
	}

	if (g_Rooms[roomnum].unk52 < 0) {
		return 0;
	}

	return (g_Rooms[roomnum].flags & ROOMFLAG_0040) ? g_Rooms[roomnum].unk52 : 0;
}

f32 roomGetUnk5c(s32 roomnum)
{
	return g_Rooms[roomnum].unk5c;
}

f32 func0f000cec(s32 roomnum)
{
	f32 value = (g_Rooms[roomnum].unk52 + g_Rooms[roomnum].unk4b) / 0.0039215688593686f;

	if (value > 1) {
		value = 1;
	}

	if (value < 0) {
		value = 0;
	}

	return value;
}

f32 func0f000d6c(s32 roomnum)
{
	return g_Rooms[roomnum].unk4b / 255.0f;
}

f32 func0f000dbc(s32 roomnum)
{
	return g_Rooms[roomnum].brightness / 255.0f;
}

/**
 * The resulting position is not a world position. It is relative to the room.
 */
bool lightGetBboxCentre(s32 roomnum, u32 lightnum, struct coord *pos)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	s32 i;
	light += lightnum;

	pos->x = 0;
	pos->y = 0;
	pos->z = 0;

	for (i = 0; i < 4; i++) {
		pos->x += light->bbox[i].x;
		pos->y += light->bbox[i].y;
		pos->z += light->bbox[i].z;
	}

	pos->x *= 0.25f;
	pos->y *= 0.25f;
	pos->z *= 0.25f;

	return true;
}

bool lightIsHealthy(s32 roomnum, s32 lightnum)
{
	bool healthy;

	if (roomnum && roomGetLight(roomnum, lightnum)->healthy) {
		healthy = true;
	} else {
		healthy = false;
	}

	return healthy;
}

bool lightIsVulnerable(s32 roomnum, s32 lightnum)
{
	struct light *light = roomGetLight(roomnum, lightnum);

	return light->vulnerable;
}

bool lightIsOn(s32 roomnum, s32 lightnum)
{
	bool on;

	if (roomnum && roomGetLight(roomnum, lightnum)->on) {
		on = true;
	} else {
		on = false;
	}

	return on;
}

void roomSetUnk52(s32 roomnum, s32 value)
{
	g_Rooms[roomnum].unk52 = value;
}

void lightGetUnk07(s32 roomnum, u32 lightnum, struct coord *coord)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	light += lightnum;

	coord->x = light->unk07;
	coord->y = light->unk08;
	coord->z = light->unk09;
}

void func0f0010b4(void)
{
	if (var80061424) {
		var80061424 = 0;
	}

	var80061424 = 1;
}

void roomSetDefaults(struct room *room)
{
	room->unk48 = 0;
	room->unk49 = 255;
	room->unk4a = 0;
	room->brightness = 128;
	room->unk52 = 0;
	room->unk4b = 0;
	room->lightop = 0;
	room->flags &= ~(ROOMFLAG_0200 | ROOMFLAG_DIRTY | ROOMFLAG_RENDERALWAYS | ROOMFLAG_0040);
	room->unk6c = 1;
	room->unk70 = 1;
	room->unk5c = 1;
	room->unk60 = 0;
	room->unk64 = 0;
	room->unk68 = 0;
}

Gfx *lightsSetForRoom(Gfx *gdl, s16 roomnum)
{
	Lights1 *lights = gfxAllocate(sizeof(Lights1));

	u8 v0 = func0f000a10(roomnum);
	u8 a0 = (u32)(v0 * 0.5882353f);

	lights->a.l.col[0] = a0;
	lights->a.l.col[1] = a0;
	lights->a.l.col[2] = a0;
	lights->a.l.colc[0] = a0;
	lights->a.l.colc[1] = a0;
	lights->a.l.colc[2] = a0;

	lights->l[0].l.col[0] = v0;
	lights->l[0].l.col[1] = v0;
	lights->l[0].l.col[2] = v0;
	lights->l[0].l.colc[0] = v0;
	lights->l[0].l.colc[1] = v0;
	lights->l[0].l.colc[2] = v0;
	lights->l[0].l.dir[0] = 0x4d;
	lights->l[0].l.dir[1] = 0x4d;
	lights->l[0].l.dir[2] = 0x2e;

	gSPSetLights1(gdl++, (*lights));

	gSPLookAtX(gdl++, &camGetLookAt()->l[0]);
	gSPLookAtY(gdl++, &camGetLookAt()->l[1]);

	return gdl;
}

Gfx *lightsSetDefault(Gfx *gdl)
{
	gSPSetLights1(gdl++, var80061460);

	gSPLookAtX(gdl++, &camGetLookAt()->l[0]);
	gSPLookAtY(gdl++, &camGetLookAt()->l[1]);

	return gdl;
}

void roomInitLights(s32 roomnum)
{
	struct room *room = &g_Rooms[roomnum];
	struct light *light;
	s32 i;

	func0f158108(roomnum, &room->unk48, &room->unk49);

	room->unk48 = room->unk48 / 4;

	if (room->numlights) {
		room->unk4a = (f32)(room->unk49 - room->unk48) / (f32)room->numlights;
	} else {
		room->unk4a = 0;
	}

	if (room->unk48 > 255) {
		room->unk48 = 255;
	}

	if (room->unk49 > 255) {
		room->unk49 = 255;
	}

	room->unk4c = room->unk48;

	if (room->numlights == 0) {
		room->unk4c += (room->unk49 - room->unk48) * 4 / 5;
	}

	switch (g_Vars.stagenum) {
	case STAGE_EXTRACTION:
	case STAGE_DEFECTION:
		if (roomnum == 0x003d) { // near the top comms hub
			room->unk4c = 2;
		}
		break;
	}

	if (((g_StageIndex == STAGEINDEX_INFILTRATION || g_StageIndex == STAGEINDEX_RESCUE || g_StageIndex == STAGEINDEX_ESCAPE || g_StageIndex == STAGEINDEX_MAIANSOS)
				&& roomnum == 0x000f) // freight elevator shaft
			|| ((g_StageIndex == STAGEINDEX_DEFECTION || g_StageIndex == STAGEINDEX_EXTRACTION || g_StageIndex == STAGEINDEX_MBR)
				&& roomnum == 0x0001) // moon
			|| ((g_StageIndex == STAGEINDEX_SKEDARRUINS || g_StageIndex == STAGEINDEX_WAR)
				&& roomnum == 0x0002) // fake sky
			|| ((s32)g_StageIndex == STAGEINDEX_TEST_OLD
				&& roomnum == 0x0001)
			|| (g_StageIndex == STAGEINDEX_ATTACKSHIP
				&& roomnum == 0x0071)) { // planet
		room->flags |= ROOMFLAG_RENDERALWAYS;
	} else {
		room->flags &= ~ROOMFLAG_RENDERALWAYS;
	}

	room->flags |= ROOMFLAG_DIRTY;

	light = (struct light *)&g_BgLightsFileData[(u32)g_Rooms[roomnum].lightindex * 0x22];

	for (i = 0; i < room->numlights; i++) {
		{
			light->unk04 = g_Rooms[roomnum].unk4a;
			light->unk05_00 = true;
			light->healthy = true;
			light->on = true;
			light->sparking = false;
			light->vulnerable = true;

			switch (g_Vars.stagenum) {
			case STAGE_CITRAINING:
			case STAGE_DEFENSE:
				if (roomnum == 0x000a) { // firing range
					light->vulnerable = false;
				}
				break;
			case STAGE_DEFECTION:
			case STAGE_EXTRACTION:
				if (roomnum == 0x003e && (i == 0 || i == 1)) { // top comms hub
					light->vulnerable = false;
				}
				break;
			}
		}

		light++;
	}
}

bool lightsHandleHit(struct coord *gunpos, struct coord *hitpos, s32 roomnum)
{
	s32 i;
	f32 f2;
	struct coord spa4;
	struct coord sp98;
	struct coord sp8c;
	struct light *light;

	if (roomnum == 0 || g_Rooms[roomnum].numlights == 0) {
		return false;
	}

	spa4.x = gunpos->x - g_BgRooms[roomnum].pos.x;
	spa4.y = gunpos->y - g_BgRooms[roomnum].pos.y;
	spa4.z = gunpos->z - g_BgRooms[roomnum].pos.z;

	sp98.x = hitpos->x - g_BgRooms[roomnum].pos.x;
	sp98.y = hitpos->y - g_BgRooms[roomnum].pos.y;
	sp98.z = hitpos->z - g_BgRooms[roomnum].pos.z;

	sp8c.x = sp98.x - spa4.x;
	sp8c.y = sp98.y - spa4.y;
	sp8c.z = sp98.z - spa4.z;

	f2 = 2.0f / sqrtf(sp8c.x * sp8c.x + sp8c.y * sp8c.y + sp8c.z * sp8c.z);

	sp8c.x *= f2;
	sp8c.y *= f2;
	sp8c.z *= f2;

	sp98.x += sp8c.x;
	sp98.y += sp8c.y;
	sp98.z += sp8c.z;

	light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];

	for (i = 0; i < g_Rooms[roomnum].numlights; i++) {
		if (light->healthy && light->vulnerable) {
			if (func0002f490(&light->bbox[0], &light->bbox[1], &light->bbox[3], 0, &spa4, &sp98, &sp8c, 0, 0)
					|| func0002f490(&light->bbox[1], &light->bbox[2], &light->bbox[3], 0, &spa4, &sp98, &sp8c, 0, 0)) {
				struct coord soundpos;

				soundpos.x = light->bbox[0].x;
				soundpos.y = light->bbox[0].y;
				soundpos.z = light->bbox[0].z;

				roomSetLightBroken(roomnum, i);
				propsnd0f0939f8(0, 0, SFX_HIT_GLASS, -1, -1, 0x400, 0, 0, &soundpos, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
				return true;
			}
		}

		light++;
	}

	return false;
}

void roomSetLightsFaulty(s32 roomnum, s32 chance)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	s32 i;

	if (g_Rooms[roomnum].numlights) {
		for (i = 0; i < g_Rooms[roomnum].numlights; i++) {
			if ((random() % 100) < chance) {
				light->healthy = false;
				light->on = false;
			}

			light++;
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	g_Rooms[roomnum].unk4c = 50;
#else
	g_Rooms[roomnum].unk4c = 15;
#endif

	g_Rooms[roomnum].flags |= ROOMFLAG_DIRTY;
}

void roomSetLightBroken(s32 roomnum, s32 lightnum)
{
	struct light *light = roomGetLight(roomnum, lightnum);
	light->healthy = false;
	light->on = false;

	g_Rooms[roomnum].flags |= ROOMFLAG_DIRTY;
}

void lightsReset(void)
{
	if (var80061444) {
		func0f004c6c();
	}
}

void func0f001c0c(void)
{
	s32 i;
	s32 sp68;
	s32 table1size;
	s32 table2size;
	s32 table3size;
	s32 table4size;
	s32 sp54;
	u8 *ptr;
	u8 *s5;
	u8 *sp48;
	s32 *sp44;
	s32 j;
	s32 stack[4];

	osGetCount();

	var80061440 = 0;

	func0f0023b8();

	if (1);
	for (g_NumPortals = 0; g_BgPortals[g_NumPortals].verticesoffset != 0; g_NumPortals++);

	if (g_NumPortals == 0) {
		return;
	}

	table1size = align16(g_Vars.roomcount * 4);
	table2size = align16(g_NumPortals * 4);
	table3size = align16(g_Vars.roomcount * 4);
	table4size = align16((u32)var8009cae0 * (u32)var8009cae0);
	sp68 = align16(g_Vars.roomcount * 8);

	mempGetStageFree();

	ptr = mblurGetAllocation();

	var80061434 = (f32 *)ptr;
	ptr += table1size;

	var80061438 = (bool *)ptr;
	ptr += table2size;

	sp44 = (s32 *)(ptr);
	ptr += table3size;

	sp48 = (u8 *)ptr;
	ptr += table4size;

	s5 = (u8 *)ptr;

	var80061420 = mempAlloc(sp68, MEMPOOL_STAGE);

	for (i = 0; i < g_NumPortals; i++) {
		if (PORTAL_IS_CLOSED(i)) {
			var80061438[i] = false;
		} else {
			var80061438[i] = true;
			if (1);
		}
	}

	if (g_Vars.stagenum == STAGE_EXTRACTION || g_Vars.stagenum == STAGE_DEFECTION) {
		var80061438[98] = false;
		var80061438[100] = false;
	}

	func0f00215c(sp48);

	for (i = 1, table3size = 0; i < g_Vars.roomcount; i++) {
		sp44[i] = func0f177a54((void *)(i * var8009cae0 + sp48), g_Vars.roomcount, (void *)(&s5[i * var8009cae0]), 1);
		table3size += align4(sp44[i]);
	}

	ptr = mempAlloc(align16(table3size), MEMPOOL_STAGE);

	sp68 += align16(table3size);

	sp54 = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		s32 size = align4(sp44[i]);

		var80061420[i].unk00 = ptr;

		ptr += size;
		sp54 += size;

		for (j = 0; j < sp44[i]; j++) {
			var80061420[i].unk00[j] = *(&s5[i * var8009cae0] + j);
		}
	}

	table3size = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		sp44[i] = func0f177a54((void *)(sp48 + i), g_Vars.roomcount, (void *)(&s5[i * var8009cae0]), var8009cae0);

		table3size += align4(sp44[i]);
	}

	ptr = mempAlloc(align16(table3size), MEMPOOL_STAGE);

	align16(table3size);

	for (i = 1; i < g_Vars.roomcount; i++) {
		var80061420[i].unk04 = ptr;

		ptr += align4(sp44[i]);

		for (j = 0; j < sp44[i]; j++) {
			var80061420[i].unk04[j] = *(&s5[i * var8009cae0] + j);
		}
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags |= ROOMFLAG_ONSCREEN;
	}

	lightingTick();

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_ONSCREEN;
	}

	osGetCount();

	if (sp68);
}

f32 func0f002334(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2);

void func0f00215c(u8 *arg0)
{
	s32 i;
	s32 j;

	var8009cae8 = &func0f002334;

	var8006143c = 50.0f;
	var8009cae4 = 20;
	var80061440 = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		u8 *ptr = &arg0[i * var8009cae0];

		func0f00259c(i);

		for (j = 0; j < 1; j++) {
			ptr[j] = 0;
		}

		for (j = 1; j < g_Vars.roomcount; j++) {
			if (var80061434[i] < var80061434[j]) {
				var80061434[j] = var80061434[i];
			}

			ptr[j] = var80061434[j];
		}
	}
}

f32 func0f002334(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2)
{
	f32 fVar2 = 0;
	f32 result;

	if (portalnum1 != -1) {
		fVar2 = portal0f15b274(portalnum1);
	}

	result = (portal0f15b274(portalnum2) / (g_Rooms[roomnum].unk70 - fVar2)) * mult;
	return result;
}

void func0f0023b8(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < g_Vars.roomcount; i++) {
		bool valid = true;

		g_Rooms[i].unk6c = 1.0f;
		g_Rooms[i].unk70 = 1.0f;

		for (j = 0; j < 3; j++) {
			f32 diff = g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j];

			if (diff > 0.0f) {
				g_Rooms[i].unk6c *= (g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j]) / 100.0f;
			} else {
				valid = false;
			}
		}

		g_Rooms[i].unk6c += 1.0f;

		if (g_Rooms[i].unk6c > 60.0f) {
			g_Rooms[i].unk6c = 60.0f;
		}

		if (valid) {
			f32 xdiff = g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0];
			f32 ydiff = g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1];
			f32 zdiff = g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2];

			if (!(xdiff > 0)) {
				xdiff = -xdiff;
			}

			if (!(ydiff > 0)) {
				ydiff = -ydiff;
			}

			if (!(zdiff > 0)) {
				zdiff = -zdiff;
			}

			g_Rooms[i].unk70 = 2.0f * (xdiff * ydiff + xdiff * zdiff + ydiff * zdiff);
		} else {
			g_Rooms[i].unk70 = 20000000.0f;
		}
	}
}

void func0f00259c(s32 roomnum)
{
	s32 i;
	f32 sp58;
	f32 f20 = 0.0f;

	for (i = 0; i < g_Vars.roomcount; i++) {
		var80061434[i] = 0.0f;
	}

	var80061434[roomnum] = sqrtf(g_Rooms[roomnum].unk6c) * 255.0f;
	if (1);

	if (g_Rooms[roomnum].numportals != 0) {
		func0f002844(roomnum, var80061434[roomnum], 0, -1);
		if (1);
		if (1);
	}

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		f20 += portal0f15b274(g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i]);
	}

	sp58 = (g_Rooms[roomnum].unk70 - f20) / g_Rooms[roomnum].unk70;

	for (i = 1; i < g_Vars.roomcount; i++) {
		var80061434[i] *= 3.0f / sqrtf(g_Rooms[i].unk6c);
	}

	if (var80061434[roomnum] > 255.0f) {
		var80061434[roomnum] = 255.0f;
	}

	if (sp58 < 0.1f) {
		g_Rooms[roomnum].unk48 = g_Rooms[roomnum].unk49 >> 1;
		var80061434[roomnum] = g_Rooms[roomnum].unk49;
	}
}

void func0f002844(s32 roomnum, f32 arg1, s32 arg2, s32 portalnum)
{
	s32 i;
	s32 otherroomnum = -1;

	var80061440++;

	if (portalnum != -1) {
		if (roomnum == g_BgPortals[portalnum].roomnum1) {
			otherroomnum = (s32) g_BgPortals[portalnum].roomnum2;
		} else {
			otherroomnum = (s32) g_BgPortals[portalnum].roomnum1;
		}
	}

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 iterportalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		s32 iterroomnum;

		if (var80061438[iterportalnum]) {
			if (roomnum == g_BgPortals[iterportalnum].roomnum1) {
				iterroomnum = g_BgPortals[iterportalnum].roomnum2;
			} else {
				iterroomnum = g_BgPortals[iterportalnum].roomnum1;
			}

			if (iterroomnum != otherroomnum) {
				f32 f0 = var8009cae8(roomnum, arg1, portalnum, iterportalnum);

				if (f0 > var8006143c && arg2 < var8009cae4) {
					var80061434[roomnum] -= f0;
					var80061434[iterroomnum] += f0;

					if (var80061434[roomnum] < 0.0f) {
						var80061434[roomnum] = 0.0f;
					}

					func0f002844(iterroomnum, f0, arg2 + 1, iterportalnum);
				}
			}
		}
	}
}

void func0f002a98(void)
{
	s32 i;

	var8009cae0 = align4(g_Vars.roomcount);
#if VERSION >= VERSION_NTSC_1_0
	var80061458 = 0;
#endif
	g_Vars.remakewallhitvtx = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		roomSetDefaults(&g_Rooms[i]);
		roomInitLights(i);
	}

	var80061420 = 0;

	if (IS4MB()) {
		var80061444 = 0;
	}
}

void roomSetLightsOn(s32 roomnum, s32 enable)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	s32 i;

	if (g_Rooms[roomnum].numlights) {
		for (i = 0; i < g_Rooms[roomnum].numlights; i++) {
			if (light->healthy) {
				light->on = enable;
			}

			light++;
		}
	}

	if (enable) {
		g_Rooms[roomnum].flags &= ~ROOMFLAG_LIGHTSOFF;
	} else {
		g_Rooms[roomnum].flags |= ROOMFLAG_LIGHTSOFF;
	}

	g_Rooms[roomnum].flags |= ROOMFLAG_DIRTY;
}

void roomSetLighting(s32 roomnum, s32 operation, u8 arg2, u8 arg3, u8 arg4)
{
	{
		g_Rooms[roomnum].lightop = operation;

		switch (operation) {
		case LIGHTOP_1:
			g_Rooms[roomnum].unk60 = arg2 * 0.01f;
			break;
		case LIGHTOP_2:
			g_Rooms[roomnum].unk60 = arg2;
			g_Rooms[roomnum].unk64 = arg3 * 0.01f;
			g_Rooms[roomnum].unk68 = arg4 * 4.0f;
			g_Rooms[roomnum].unk54 = arg4;
			break;
		case LIGHTOP_3:
			g_Rooms[roomnum].unk60 = arg2 * 0.01f;
			g_Rooms[roomnum].unk64 = arg3 * 0.01f;
			g_Rooms[roomnum].unk68 = arg4 * 4.0f;
			g_Rooms[roomnum].unk54 = arg4;
			break;
		case LIGHTOP_4:
			g_Rooms[roomnum].unk60 = arg2 * 0.01f;
			g_Rooms[roomnum].unk64 = arg3 * 0.01f;
			g_Rooms[roomnum].unk68 = arg4 * 4.0f;
			g_Rooms[roomnum].unk54 = 0;
			break;
		case LIGHTOP_5:
			break;
		}
	}
}

#if MATCHING
#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel lightTickBroken
/*  f002ef8:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f002efc:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f002f00:	3c0e800a */ 	lui	$t6,%hi(g_Rooms)
/*  f002f04:	8dce4928 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f002f08:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f002f0c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f002f10:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f002f14:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f002f18:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f002f1c:	afa400d8 */ 	sw	$a0,0xd8($sp)
/*  f002f20:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f002f24:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f002f28:	972a000a */ 	lhu	$t2,0xa($t9)
/*  f002f2c:	3c0f800a */ 	lui	$t7,%hi(g_BgLightsFileData)
/*  f002f30:	8def4cd8 */ 	lw	$t7,%lo(g_BgLightsFileData)($t7)
/*  f002f34:	01456021 */ 	addu	$t4,$t2,$a1
/*  f002f38:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f002f3c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f002f40:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f002f44:	01af1821 */ 	addu	$v1,$t5,$t7
/*  f002f48:	80780005 */ 	lb	$t8,0x5($v1)
/*  f002f4c:	07020004 */ 	bltzl	$t8,.L0f002f60
/*  f002f50:	94790004 */ 	lhu	$t9,0x4($v1)
/*  f002f54:	10000112 */ 	b	.L0f0033a0
/*  f002f58:	00001025 */ 	or	$v0,$zero,$zero
/*  f002f5c:	94790004 */ 	lhu	$t9,0x4($v1)
.L0f002f60:
/*  f002f60:	00195ec0 */ 	sll	$t3,$t9,0x1b
/*  f002f64:	05610102 */ 	bgez	$t3,.L0f003370
/*  f002f68:	00000000 */ 	nop
/*  f002f6c:	0c004b70 */ 	jal	random
/*  f002f70:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002f74:	304c0007 */ 	andi	$t4,$v0,0x7
/*  f002f78:	15800005 */ 	bnez	$t4,.L0f002f90
/*  f002f7c:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002f80:	906d0005 */ 	lbu	$t5,0x5($v1)
/*  f002f84:	31afffef */ 	andi	$t7,$t5,0xffef
/*  f002f88:	10000104 */ 	b	.L0f00339c
/*  f002f8c:	a06f0005 */ 	sb	$t7,0x5($v1)
.L0f002f90:
/*  f002f90:	0c004b70 */ 	jal	random
/*  f002f94:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002f98:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f002f9c:	15c000ff */ 	bnez	$t6,.L0f00339c
/*  f002fa0:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002fa4:	0c004b70 */ 	jal	random
/*  f002fa8:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002fac:	44822000 */ 	mtc1	$v0,$f4
/*  f002fb0:	04410005 */ 	bgez	$v0,.L0f002fc8
/*  f002fb4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f002fb8:	3c014f80 */ 	lui	$at,0x4f80
/*  f002fbc:	44814000 */ 	mtc1	$at,$f8
/*  f002fc0:	00000000 */ 	nop
/*  f002fc4:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f002fc8:
/*  f002fc8:	3c012f80 */ 	lui	$at,0x2f80
/*  f002fcc:	44815000 */ 	mtc1	$at,$f10
/*  f002fd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f002fd4:	44814000 */ 	mtc1	$at,$f8
/*  f002fd8:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f002fdc:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f002fe0:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f002fe4:	0c004b70 */ 	jal	random
/*  f002fe8:	e7ac0070 */ 	swc1	$f12,0x70($sp)
/*  f002fec:	44823000 */ 	mtc1	$v0,$f6
/*  f002ff0:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002ff4:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f002ff8:	04410005 */ 	bgez	$v0,.L0f003010
/*  f002ffc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f003000:	3c014f80 */ 	lui	$at,0x4f80
/*  f003004:	44812000 */ 	mtc1	$at,$f4
/*  f003008:	00000000 */ 	nop
/*  f00300c:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f003010:
/*  f003010:	3c012f80 */ 	lui	$at,0x2f80
/*  f003014:	44814000 */ 	mtc1	$at,$f8
/*  f003018:	3c013f80 */ 	lui	$at,0x3f80
/*  f00301c:	44812000 */ 	mtc1	$at,$f4
/*  f003020:	46085002 */ 	mul.s	$f0,$f10,$f8
/*  f003024:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f003028:	3c077f1a */ 	lui	$a3,%hi(var7f1a7bb4)
/*  f00302c:	24e77bb4 */ 	addiu	$a3,$a3,%lo(var7f1a7bb4)
/*  f003030:	2406060a */ 	addiu	$a2,$zero,0x60a
/*  f003034:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f003038:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f00303c:	e7a2006c */ 	swc1	$f2,0x6c($sp)
/*  f003040:	8468000a */ 	lh	$t0,0xa($v1)
/*  f003044:	84780010 */ 	lh	$t8,0x10($v1)
/*  f003048:	846f0016 */ 	lh	$t7,0x16($v1)
/*  f00304c:	846a0012 */ 	lh	$t2,0x12($v1)
/*  f003050:	0308c823 */ 	subu	$t9,$t8,$t0
/*  f003054:	44995000 */ 	mtc1	$t9,$f10
/*  f003058:	01e87023 */ 	subu	$t6,$t7,$t0
/*  f00305c:	448e2000 */ 	mtc1	$t6,$f4
/*  f003060:	468053a0 */ 	cvt.s.w	$f14,$f10
/*  f003064:	8464000c */ 	lh	$a0,0xc($v1)
/*  f003068:	846c0014 */ 	lh	$t4,0x14($v1)
/*  f00306c:	8465000e */ 	lh	$a1,0xe($v1)
/*  f003070:	01445823 */ 	subu	$t3,$t2,$a0
/*  f003074:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f003078:	448b4000 */ 	mtc1	$t3,$f8
/*  f00307c:	01856823 */ 	subu	$t5,$t4,$a1
/*  f003080:	448d3000 */ 	mtc1	$t5,$f6
/*  f003084:	460e6382 */ 	mul.s	$f14,$f12,$f14
/*  f003088:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f00308c:	84780018 */ 	lh	$t8,0x18($v1)
/*  f003090:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f003094:	0304c823 */ 	subu	$t9,$t8,$a0
/*  f003098:	44994000 */ 	mtc1	$t9,$f8
/*  f00309c:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0030a0:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0030a4:	46106402 */ 	mul.s	$f16,$f12,$f16
/*  f0030a8:	00000000 */ 	nop
/*  f0030ac:	46126482 */ 	mul.s	$f18,$f12,$f18
/*  f0030b0:	c7ac006c */ 	lwc1	$f12,0x6c($sp)
/*  f0030b4:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0030b8:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f0030bc:	846a001a */ 	lh	$t2,0x1a($v1)
/*  f0030c0:	01455823 */ 	subu	$t3,$t2,$a1
/*  f0030c4:	448b2000 */ 	mtc1	$t3,$f4
/*  f0030c8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0030cc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0030d0:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f0030d4:	44885000 */ 	mtc1	$t0,$f10
/*  f0030d8:	46066002 */ 	mul.s	$f0,$f12,$f6
/*  f0030dc:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f0030e0:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0030e4:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0030e8:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f0030ec:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0030f0:	460e2180 */ 	add.s	$f6,$f4,$f14
/*  f0030f4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0030f8:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f0030fc:	846c000a */ 	lh	$t4,0xa($v1)
/*  f003100:	448c2000 */ 	mtc1	$t4,$f4
/*  f003104:	00000000 */ 	nop
/*  f003108:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00310c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f003110:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f003114:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f003118:	846d000a */ 	lh	$t5,0xa($v1)
/*  f00311c:	448d2000 */ 	mtc1	$t5,$f4
/*  f003120:	00000000 */ 	nop
/*  f003124:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003128:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f00312c:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f003130:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f003134:	806f0007 */ 	lb	$t7,0x7($v1)
/*  f003138:	448f2000 */ 	mtc1	$t7,$f4
/*  f00313c:	00000000 */ 	nop
/*  f003140:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003144:	e7a6008c */ 	swc1	$f6,0x8c($sp)
/*  f003148:	806e0008 */ 	lb	$t6,0x8($v1)
/*  f00314c:	448e4000 */ 	mtc1	$t6,$f8
/*  f003150:	00000000 */ 	nop
/*  f003154:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f003158:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f00315c:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f003160:	80780009 */ 	lb	$t8,0x9($v1)
/*  f003164:	46004287 */ 	neg.s	$f10,$f8
/*  f003168:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f00316c:	44982000 */ 	mtc1	$t8,$f4
/*  f003170:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f003174:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003178:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f00317c:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f003180:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f003184:	46002187 */ 	neg.s	$f6,$f4
/*  f003188:	46004287 */ 	neg.s	$f10,$f8
/*  f00318c:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f003190:	0fc5dc59 */ 	jal	func0f177164
/*  f003194:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f003198:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f00319c:	c7b00080 */ 	lwc1	$f16,0x80($sp)
/*  f0031a0:	c7ae00a8 */ 	lwc1	$f14,0xa8($sp)
/*  f0031a4:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f0031a8:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f0031ac:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0031b0:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0031b4:	460c7300 */ 	add.s	$f12,$f14,$f12
/*  f0031b8:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0031bc:	3c077f1a */ 	lui	$a3,%hi(var7f1a7bc0)
/*  f0031c0:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f0031c4:	e7b000a4 */ 	swc1	$f16,0xa4($sp)
/*  f0031c8:	e7ac00a8 */ 	swc1	$f12,0xa8($sp)
/*  f0031cc:	00802825 */ 	or	$a1,$a0,$zero
/*  f0031d0:	e7aa00ac */ 	swc1	$f10,0xac($sp)
/*  f0031d4:	2406060c */ 	addiu	$a2,$zero,0x60c
/*  f0031d8:	0fc5dc59 */ 	jal	func0f177164
/*  f0031dc:	24e77bc0 */ 	addiu	$a3,$a3,%lo(var7f1a7bc0)
/*  f0031e0:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f0031e4:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f0031e8:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f0031ec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0031f0:	0c004b70 */ 	jal	random
/*  f0031f4:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0031f8:	30430003 */ 	andi	$v1,$v0,0x3
/*  f0031fc:	1060000a */ 	beqz	$v1,.L0f003228
/*  f003200:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f003204:	24010001 */ 	addiu	$at,$zero,0x1
/*  f003208:	10610009 */ 	beq	$v1,$at,.L0f003230
/*  f00320c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f003210:	10610009 */ 	beq	$v1,$at,.L0f003238
/*  f003214:	24010003 */ 	addiu	$at,$zero,0x3
/*  f003218:	5061000a */ 	beql	$v1,$at,.L0f003244
/*  f00321c:	24090014 */ 	addiu	$t1,$zero,0x14
/*  f003220:	10000009 */ 	b	.L0f003248
/*  f003224:	8fa400d8 */ 	lw	$a0,0xd8($sp)
.L0f003228:
/*  f003228:	10000006 */ 	b	.L0f003244
/*  f00322c:	24090011 */ 	addiu	$t1,$zero,0x11
.L0f003230:
/*  f003230:	10000004 */ 	b	.L0f003244
/*  f003234:	24090012 */ 	addiu	$t1,$zero,0x12
.L0f003238:
/*  f003238:	10000002 */ 	b	.L0f003244
/*  f00323c:	24090013 */ 	addiu	$t1,$zero,0x13
/*  f003240:	24090014 */ 	addiu	$t1,$zero,0x14
.L0f003244:
/*  f003244:	8fa400d8 */ 	lw	$a0,0xd8($sp)
.L0f003248:
/*  f003248:	8fa500dc */ 	lw	$a1,0xdc($sp)
/*  f00324c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f003250:	0fc0037f */ 	jal	lightGetBboxCentre
/*  f003254:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f003258:	3c0b800a */ 	lui	$t3,%hi(g_BgRooms)
/*  f00325c:	8d6b4cc4 */ 	lw	$t3,%lo(g_BgRooms)($t3)
/*  f003260:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f003264:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f003268:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f00326c:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f003270:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f003274:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f003278:	27ad008c */ 	addiu	$t5,$sp,0x8c
/*  f00327c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f003280:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f003284:	00002825 */ 	or	$a1,$zero,$zero
/*  f003288:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f00328c:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f003290:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f003294:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f003298:	27a700a4 */ 	addiu	$a3,$sp,0xa4
/*  f00329c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0032a0:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f0032a4:	c464000c */ 	lwc1	$f4,0xc($v1)
/*  f0032a8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0032ac:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0032b0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0032b4:	0fc4be7c */ 	jal	sparksCreate
/*  f0032b8:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0032bc:	0c004b70 */ 	jal	random
/*  f0032c0:	00000000 */ 	nop
/*  f0032c4:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0032c8:	15e00008 */ 	bnez	$t7,.L0f0032ec
/*  f0032cc:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f0032d0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0032d4:	a7ae0064 */ 	sh	$t6,0x64($sp)
/*  f0032d8:	a7b80066 */ 	sh	$t8,0x66($sp)
/*  f0032dc:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0032e0:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0032e4:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f0032e8:	24060007 */ 	addiu	$a2,$zero,0x7
.L0f0032ec:
/*  f0032ec:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f0032f0:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f0032f4:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f0032f8:	24060050 */ 	addiu	$a2,$zero,0x50
/*  f0032fc:	0fc25480 */ 	jal	propsndGetRandomSparkSound
/*  f003300:	00000000 */ 	nop
/*  f003304:	3c01bf80 */ 	lui	$at,0xbf80
/*  f003308:	44810000 */ 	mtc1	$at,$f0
/*  f00330c:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f003310:	00023400 */ 	sll	$a2,$v0,0x10
/*  f003314:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f003318:	240affff */ 	addiu	$t2,$zero,-1
/*  f00331c:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f003320:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f003324:	27ad0074 */ 	addiu	$t5,$sp,0x74
/*  f003328:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f00332c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f003330:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f003334:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f003338:	03203025 */ 	or	$a2,$t9,$zero
/*  f00333c:	00002025 */ 	or	$a0,$zero,$zero
/*  f003340:	00002825 */ 	or	$a1,$zero,$zero
/*  f003344:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f003348:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00334c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f003350:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f003354:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f003358:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f00335c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f003360:	0fc24e7e */ 	jal	propsnd0f0939f8
/*  f003364:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f003368:	1000000d */ 	b	.L0f0033a0
/*  f00336c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f003370:
/*  f003370:	0c004b70 */ 	jal	random
/*  f003374:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f003378:	24010050 */ 	addiu	$at,$zero,0x50
/*  f00337c:	0041001b */ 	divu	$zero,$v0,$at
/*  f003380:	00007010 */ 	mfhi	$t6
/*  f003384:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f003388:	55c00005 */ 	bnezl	$t6,.L0f0033a0
/*  f00338c:	00001025 */ 	or	$v0,$zero,$zero
/*  f003390:	90790005 */ 	lbu	$t9,0x5($v1)
/*  f003394:	372a0010 */ 	ori	$t2,$t9,0x10
/*  f003398:	a06a0005 */ 	sb	$t2,0x5($v1)
.L0f00339c:
/*  f00339c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0033a0:
/*  f0033a0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0033a4:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
/*  f0033a8:	03e00008 */ 	jr	$ra
/*  f0033ac:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel lightTickBroken
/*  f002ef8:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f002efc:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f002f00:	3c0e800a */ 	lui	$t6,%hi(g_Rooms)
/*  f002f04:	8dce4928 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f002f08:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f002f0c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f002f10:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f002f14:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f002f18:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f002f1c:	afa400d8 */ 	sw	$a0,0xd8($sp)
/*  f002f20:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f002f24:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f002f28:	972a000a */ 	lhu	$t2,0xa($t9)
/*  f002f2c:	3c0f800a */ 	lui	$t7,%hi(g_BgLightsFileData)
/*  f002f30:	8def4cd8 */ 	lw	$t7,%lo(g_BgLightsFileData)($t7)
/*  f002f34:	01456021 */ 	addu	$t4,$t2,$a1
/*  f002f38:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f002f3c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f002f40:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f002f44:	01af1821 */ 	addu	$v1,$t5,$t7
/*  f002f48:	80780005 */ 	lb	$t8,0x5($v1)
/*  f002f4c:	07020004 */ 	bltzl	$t8,.L0f002f60
/*  f002f50:	94790004 */ 	lhu	$t9,0x4($v1)
/*  f002f54:	10000112 */ 	b	.L0f0033a0
/*  f002f58:	00001025 */ 	or	$v0,$zero,$zero
/*  f002f5c:	94790004 */ 	lhu	$t9,0x4($v1)
.L0f002f60:
/*  f002f60:	00195ec0 */ 	sll	$t3,$t9,0x1b
/*  f002f64:	05610102 */ 	bgez	$t3,.L0f003370
/*  f002f68:	00000000 */ 	nop
/*  f002f6c:	0c004b70 */ 	jal	random
/*  f002f70:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002f74:	304c0007 */ 	andi	$t4,$v0,0x7
/*  f002f78:	15800005 */ 	bnez	$t4,.L0f002f90
/*  f002f7c:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002f80:	906d0005 */ 	lbu	$t5,0x5($v1)
/*  f002f84:	31afffef */ 	andi	$t7,$t5,0xffef
/*  f002f88:	10000104 */ 	b	.L0f00339c
/*  f002f8c:	a06f0005 */ 	sb	$t7,0x5($v1)
.L0f002f90:
/*  f002f90:	0c004b70 */ 	jal	random
/*  f002f94:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002f98:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f002f9c:	15c000ff */ 	bnez	$t6,.L0f00339c
/*  f002fa0:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002fa4:	0c004b70 */ 	jal	random
/*  f002fa8:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f002fac:	44822000 */ 	mtc1	$v0,$f4
/*  f002fb0:	04410005 */ 	bgez	$v0,.L0f002fc8
/*  f002fb4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f002fb8:	3c014f80 */ 	lui	$at,0x4f80
/*  f002fbc:	44814000 */ 	mtc1	$at,$f8
/*  f002fc0:	00000000 */ 	nop
/*  f002fc4:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f002fc8:
/*  f002fc8:	3c012f80 */ 	lui	$at,0x2f80
/*  f002fcc:	44815000 */ 	mtc1	$at,$f10
/*  f002fd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f002fd4:	44814000 */ 	mtc1	$at,$f8
/*  f002fd8:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f002fdc:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f002fe0:	46082301 */ 	sub.s	$f12,$f4,$f8
/*  f002fe4:	0c004b70 */ 	jal	random
/*  f002fe8:	e7ac0070 */ 	swc1	$f12,0x70($sp)
/*  f002fec:	44823000 */ 	mtc1	$v0,$f6
/*  f002ff0:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f002ff4:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f002ff8:	04410005 */ 	bgez	$v0,.L0f003010
/*  f002ffc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f003000:	3c014f80 */ 	lui	$at,0x4f80
/*  f003004:	44812000 */ 	mtc1	$at,$f4
/*  f003008:	00000000 */ 	nop
/*  f00300c:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f003010:
/*  f003010:	3c012f80 */ 	lui	$at,0x2f80
/*  f003014:	44814000 */ 	mtc1	$at,$f8
/*  f003018:	3c013f80 */ 	lui	$at,0x3f80
/*  f00301c:	44812000 */ 	mtc1	$at,$f4
/*  f003020:	46085002 */ 	mul.s	$f0,$f10,$f8
/*  f003024:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f003028:	3c077f1a */ 	lui	$a3,%hi(var7f1a7bb4)
/*  f00302c:	24e77bb4 */ 	addiu	$a3,$a3,%lo(var7f1a7bb4)
/*  f003030:	2406060a */ 	addiu	$a2,$zero,0x622
/*  f003034:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f003038:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f00303c:	e7a2006c */ 	swc1	$f2,0x6c($sp)
/*  f003040:	8468000a */ 	lh	$t0,0xa($v1)
/*  f003044:	84780010 */ 	lh	$t8,0x10($v1)
/*  f003048:	846f0016 */ 	lh	$t7,0x16($v1)
/*  f00304c:	846a0012 */ 	lh	$t2,0x12($v1)
/*  f003050:	0308c823 */ 	subu	$t9,$t8,$t0
/*  f003054:	44995000 */ 	mtc1	$t9,$f10
/*  f003058:	01e87023 */ 	subu	$t6,$t7,$t0
/*  f00305c:	448e2000 */ 	mtc1	$t6,$f4
/*  f003060:	468053a0 */ 	cvt.s.w	$f14,$f10
/*  f003064:	8464000c */ 	lh	$a0,0xc($v1)
/*  f003068:	846c0014 */ 	lh	$t4,0x14($v1)
/*  f00306c:	8465000e */ 	lh	$a1,0xe($v1)
/*  f003070:	01445823 */ 	subu	$t3,$t2,$a0
/*  f003074:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f003078:	448b4000 */ 	mtc1	$t3,$f8
/*  f00307c:	01856823 */ 	subu	$t5,$t4,$a1
/*  f003080:	448d3000 */ 	mtc1	$t5,$f6
/*  f003084:	460e6382 */ 	mul.s	$f14,$f12,$f14
/*  f003088:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f00308c:	84780018 */ 	lh	$t8,0x18($v1)
/*  f003090:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f003094:	0304c823 */ 	subu	$t9,$t8,$a0
/*  f003098:	44994000 */ 	mtc1	$t9,$f8
/*  f00309c:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0030a0:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0030a4:	46106402 */ 	mul.s	$f16,$f12,$f16
/*  f0030a8:	00000000 */ 	nop
/*  f0030ac:	46126482 */ 	mul.s	$f18,$f12,$f18
/*  f0030b0:	c7ac006c */ 	lwc1	$f12,0x6c($sp)
/*  f0030b4:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0030b8:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f0030bc:	846a001a */ 	lh	$t2,0x1a($v1)
/*  f0030c0:	01455823 */ 	subu	$t3,$t2,$a1
/*  f0030c4:	448b2000 */ 	mtc1	$t3,$f4
/*  f0030c8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0030cc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0030d0:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f0030d4:	44885000 */ 	mtc1	$t0,$f10
/*  f0030d8:	46066002 */ 	mul.s	$f0,$f12,$f6
/*  f0030dc:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f0030e0:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0030e4:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0030e8:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f0030ec:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0030f0:	460e2180 */ 	add.s	$f6,$f4,$f14
/*  f0030f4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0030f8:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f0030fc:	846c000a */ 	lh	$t4,0xa($v1)
/*  f003100:	448c2000 */ 	mtc1	$t4,$f4
/*  f003104:	00000000 */ 	nop
/*  f003108:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00310c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f003110:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f003114:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f003118:	846d000a */ 	lh	$t5,0xa($v1)
/*  f00311c:	448d2000 */ 	mtc1	$t5,$f4
/*  f003120:	00000000 */ 	nop
/*  f003124:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003128:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f00312c:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f003130:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f003134:	806f0007 */ 	lb	$t7,0x7($v1)
/*  f003138:	448f2000 */ 	mtc1	$t7,$f4
/*  f00313c:	00000000 */ 	nop
/*  f003140:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003144:	e7a6008c */ 	swc1	$f6,0x8c($sp)
/*  f003148:	806e0008 */ 	lb	$t6,0x8($v1)
/*  f00314c:	448e4000 */ 	mtc1	$t6,$f8
/*  f003150:	00000000 */ 	nop
/*  f003154:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f003158:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f00315c:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f003160:	80780009 */ 	lb	$t8,0x9($v1)
/*  f003164:	46004287 */ 	neg.s	$f10,$f8
/*  f003168:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f00316c:	44982000 */ 	mtc1	$t8,$f4
/*  f003170:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f003174:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f003178:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f00317c:	e7a60094 */ 	swc1	$f6,0x94($sp)
/*  f003180:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f003184:	46002187 */ 	neg.s	$f6,$f4
/*  f003188:	46004287 */ 	neg.s	$f10,$f8
/*  f00318c:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f003190:	0fc5dc59 */ 	jal	func0f177164
/*  f003194:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f003198:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f00319c:	c7b00080 */ 	lwc1	$f16,0x80($sp)
/*  f0031a0:	c7ae00a8 */ 	lwc1	$f14,0xa8($sp)
/*  f0031a4:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f0031a8:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f0031ac:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0031b0:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0031b4:	460c7300 */ 	add.s	$f12,$f14,$f12
/*  f0031b8:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0031bc:	3c077f1a */ 	lui	$a3,%hi(var7f1a7bc0)
/*  f0031c0:	460a9280 */ 	add.s	$f10,$f18,$f10
/*  f0031c4:	e7b000a4 */ 	swc1	$f16,0xa4($sp)
/*  f0031c8:	e7ac00a8 */ 	swc1	$f12,0xa8($sp)
/*  f0031cc:	00802825 */ 	or	$a1,$a0,$zero
/*  f0031d0:	e7aa00ac */ 	swc1	$f10,0xac($sp)
/*  f0031d4:	2406060c */ 	addiu	$a2,$zero,0x624
/*  f0031d8:	0fc5dc59 */ 	jal	func0f177164
/*  f0031dc:	24e77bc0 */ 	addiu	$a3,$a3,%lo(var7f1a7bc0)
/*  f0031e0:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f0031e4:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f0031e8:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f0031ec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0031f0:	0c004b70 */ 	jal	random
/*  f0031f4:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0031f8:	30430003 */ 	andi	$v1,$v0,0x3
/*  f0031fc:	1060000a */ 	beqz	$v1,.L0f003228
/*  f003200:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f003204:	24010001 */ 	addiu	$at,$zero,0x1
/*  f003208:	10610009 */ 	beq	$v1,$at,.L0f003230
/*  f00320c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f003210:	10610009 */ 	beq	$v1,$at,.L0f003238
/*  f003214:	24010003 */ 	addiu	$at,$zero,0x3
/*  f003218:	5061000a */ 	beql	$v1,$at,.L0f003244
/*  f00321c:	24090014 */ 	addiu	$t1,$zero,0x14
/*  f003220:	10000009 */ 	b	.L0f003248
/*  f003224:	8fa400d8 */ 	lw	$a0,0xd8($sp)
.L0f003228:
/*  f003228:	10000006 */ 	b	.L0f003244
/*  f00322c:	24090011 */ 	addiu	$t1,$zero,0x11
.L0f003230:
/*  f003230:	10000004 */ 	b	.L0f003244
/*  f003234:	24090012 */ 	addiu	$t1,$zero,0x12
.L0f003238:
/*  f003238:	10000002 */ 	b	.L0f003244
/*  f00323c:	24090013 */ 	addiu	$t1,$zero,0x13
/*  f003240:	24090014 */ 	addiu	$t1,$zero,0x14
.L0f003244:
/*  f003244:	8fa400d8 */ 	lw	$a0,0xd8($sp)
.L0f003248:
/*  f003248:	8fa500dc */ 	lw	$a1,0xdc($sp)
/*  f00324c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f003250:	0fc0037f */ 	jal	lightGetBboxCentre
/*  f003254:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f003258:	3c0b800a */ 	lui	$t3,%hi(g_BgRooms)
/*  f00325c:	8d6b4cc4 */ 	lw	$t3,%lo(g_BgRooms)($t3)
/*  f003260:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f003264:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f003268:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f00326c:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f003270:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f003274:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f003278:	27ad008c */ 	addiu	$t5,$sp,0x8c
/*  f00327c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f003280:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f003284:	00002825 */ 	or	$a1,$zero,$zero
/*  f003288:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f00328c:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f003290:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f003294:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f003298:	27a700a4 */ 	addiu	$a3,$sp,0xa4
/*  f00329c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0032a0:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f0032a4:	c464000c */ 	lwc1	$f4,0xc($v1)
/*  f0032a8:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0032ac:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0032b0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0032b4:	0fc4be7c */ 	jal	sparksCreate
/*  f0032b8:	e7a6007c */ 	swc1	$f6,0x7c($sp)
/*  f0032bc:	0c004b70 */ 	jal	random
/*  f0032c0:	00000000 */ 	nop
/*  f0032c4:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0032c8:	15e00008 */ 	bnez	$t7,.L0f0032ec
/*  f0032cc:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f0032d0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0032d4:	a7ae0064 */ 	sh	$t6,0x64($sp)
/*  f0032d8:	a7b80066 */ 	sh	$t8,0x66($sp)
/*  f0032dc:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0032e0:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0032e4:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f0032e8:	24060007 */ 	addiu	$a2,$zero,0x7
.L0f0032ec:
/*  f0032ec:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f0032f0:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f0032f4:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f0032f8:	24060050 */ 	addiu	$a2,$zero,0x50
/*  f0032fc:	0fc25480 */ 	jal	propsndGetRandomSparkSound
/*  f003300:	00000000 */ 	nop
/*  f003304:	3c01bf80 */ 	lui	$at,0xbf80
/*  f003308:	44810000 */ 	mtc1	$at,$f0
/*  f00330c:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f003310:	00023400 */ 	sll	$a2,$v0,0x10
/*  f003314:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f003318:	240affff */ 	addiu	$t2,$zero,-1
/*  f00331c:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f003320:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f003324:	27ad0074 */ 	addiu	$t5,$sp,0x74
/*  f003328:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f00332c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f003330:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f003334:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f003338:	03203025 */ 	or	$a2,$t9,$zero
/*  f00333c:	00002025 */ 	or	$a0,$zero,$zero
/*  f003340:	00002825 */ 	or	$a1,$zero,$zero
/*  f003344:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f003348:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00334c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f003350:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f003354:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f003358:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f00335c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f003360:	0fc24e7e */ 	jal	propsnd0f0939f8
/*  f003364:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f003368:	1000000d */ 	b	.L0f0033a0
/*  f00336c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f003370:
/*  f003370:	0c004b70 */ 	jal	random
/*  f003374:	afa300d4 */ 	sw	$v1,0xd4($sp)
/*  f003378:	24010050 */ 	addiu	$at,$zero,0x50
/*  f00337c:	0041001b */ 	divu	$zero,$v0,$at
/*  f003380:	00007010 */ 	mfhi	$t6
/*  f003384:	8fa300d4 */ 	lw	$v1,0xd4($sp)
/*  f003388:	55c00005 */ 	bnezl	$t6,.L0f0033a0
/*  f00338c:	00001025 */ 	or	$v0,$zero,$zero
/*  f003390:	90790005 */ 	lbu	$t9,0x5($v1)
/*  f003394:	372a0010 */ 	ori	$t2,$t9,0x10
/*  f003398:	a06a0005 */ 	sb	$t2,0x5($v1)
.L0f00339c:
/*  f00339c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0033a0:
/*  f0033a0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0033a4:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
/*  f0033a8:	03e00008 */ 	jr	$ra
/*  f0033ac:	00000000 */ 	nop
);
#endif

const char var7f1a7bb4[] = "dlights.c";
const char var7f1a7bc0[] = "dlights.c";
#else
// Mismatch: Documented below
bool lightTickBroken(s32 roomnum, s32 lightnum)
{
	struct light *light = (struct light *)(g_BgLightsFileData + ((g_Rooms[roomnum].lightindex + lightnum) * 0x22));
	struct coord spc8;
	struct coord spbc;
	struct coord spb0;
	struct coord spa4;
	struct coord sp98;
	struct coord sp8c;
	struct coord sp80;
	struct coord centre; // 74
	f32 rand1; // 70
	f32 rand2; // 6c
	s32 sparktype; // 68

	if (!light->unk05_00) {
		return false;
	}

	if (light->sparking) {
		if ((random() % 8) == 0) {
			light->sparking = false;
		} else if ((random() % 2) == 0) {
			rand1 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
			rand2 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
			sparktype = -1;

			spc8.x = light->bbox[1].x - light->bbox[0].x;
			spc8.y = light->bbox[1].y - light->bbox[0].y;
			spc8.z = light->bbox[1].z - light->bbox[0].z;

			spc8.x = rand1 * spc8.x;
			spc8.y = rand1 * spc8.y;
			spc8.z = rand1 * spc8.z;

			spbc.x = light->bbox[2].x - light->bbox[0].x;
			spbc.y = light->bbox[2].y - light->bbox[0].y;
			spbc.z = light->bbox[2].z - light->bbox[0].z;

			spbc.x = rand2 * spbc.x;
			spbc.y = rand2 * spbc.y;
			spbc.z = rand2 * spbc.z;

			// @bug? These all use x
			sp98.x = light->bbox[0].x + spc8.x + spbc.x;
			sp98.y = light->bbox[0].x + spc8.y + spbc.y;
			sp98.z = light->bbox[0].x + spc8.z + spbc.z;

			sp8c.x = light->unk07;
			sp8c.y = light->unk08;
			sp8c.z = light->unk09;

			sp80.x = -sp8c.f[0];
			sp80.y = -sp8c.f[1];
			sp80.z = -sp8c.f[2];

			func0f177164(&sp98, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1546 : 1570, "dlights.c");

			spa4.x += sp80.x;
			spa4.y += sp80.y;
			spa4.z += sp80.z;

			func0f177164(&spa4, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1548 : 1572, "dlights.c");

			// Mismatch: Goal loads roomnum * 0x14 into sp58 here but doesn't
			// use it until after lightGetBboxCentre. The below statement does
			// the same but also emits the load and store instructions.
			g_BgRooms[roomnum].unk00 += 0;

			switch (random() % 4) {
			case 0:
				sparktype = SPARKTYPE_LIGHT1;
				break;
			case 1:
				sparktype = SPARKTYPE_LIGHT2;
				break;
			case 2:
				sparktype = SPARKTYPE_LIGHT3;
				break;
			case 3:
				sparktype = SPARKTYPE_LIGHT4;
				break;
			}

			lightGetBboxCentre(roomnum, lightnum, &centre);

			centre.x += g_BgRooms[roomnum].pos.x;
			centre.y += g_BgRooms[roomnum].pos.y;
			centre.z += g_BgRooms[roomnum].pos.z;

			sparksCreate(roomnum, NULL, &centre, &spa4, &sp8c, sparktype);

			if ((random() % 4) == 0) {
				s16 smokerooms[2]; // 64
				smokerooms[0] = roomnum;
				smokerooms[1] = -1;

				smokeCreateSimple(&centre, smokerooms, SMOKETYPE_BULLETIMPACT);
			}

			roomAdjustLighting(roomnum, 0x40, 0x50);
			propsnd0f0939f8(NULL, NULL, propsndGetRandomSparkSound(), -1, -1, 0x400, 0, 0x10, &centre, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
			return true;
		}
	} else {
		u32 stack;

		if ((random() % 80) == 0) {
			light->sparking = true;
		}
	}

	return false;
}
#endif

const char var7f1a7bcc[] = "L2 - g_bfGlobalLightRebuild = %d";
const char var7f1a7bf0[] = "Acoustic Shadowing is %s";
const char var7f1a7c0c[] = "Enabled";
const char var7f1a7c14[] = "Disabled";
const char var7f1a7c20[] = "L2 - Fading Rm%d - Mode=%d%%";
const char var7f1a7c40[] = "RWI : Re-light all affected char props : g_bfGlobalLightRebuild";
const char var7f1a7c80[] = "L2 - %d Rooms have been processed";
const char var7f1a7ca4[] = "L2 - %d Chars need lighting";
const char var7f1a7cc0[] = "L2(%d) -> ";
const char var7f1a7ccc[] = "L2 -> Building portal range table (Num Portals = %d)\n";
const char var7f1a7d04[] = "L2(%d) -> ";
const char var7f1a7d10[] = "L2 -> Allocated %uK for the compressed acoustic shadow table\n";
const char var7f1a7d50[] = "L2(%d) -> ";
const char var7f1a7d5c[] = "L2 -> Finished building portal range table\n";

void lightingTick(void)
{
	s32 i;

	func0f0037ac();

	if (g_Vars.remakewallhitvtx) {
		wallhitsRecolour();

		g_Vars.remakewallhitvtx = false;

		for (i = 1; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags &= ~ROOMFLAG_1000;
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void func0f003444(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < g_Vars.roomcount; i++) {
		struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];
		g_Rooms[i].lightop = LIGHTOP_1;
		g_Rooms[i].unk60 = 0.5f;

		for (j = 0; j < g_Rooms[i].numlights; j++) {
			light->unk05_00 = random() % 2 ? true : false;
			light->healthy = true;
			light->on = true;
			light->sparking = false;
			light->vulnerable = true;
			light->unk04 = g_Rooms[i].unk4a;

			light++;
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void func0f0035c0(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < g_Vars.roomcount; i++) {
		struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];
		g_Rooms[i].lightop = LIGHTOP_1;
		g_Rooms[i].unk60 = 0;

		for (j = 0; j < g_Rooms[i].numlights; j++) {
			light->unk05_00 = random() % 2 ? true : false;
			light->healthy = false;
			light->on = false;
			light->sparking = false;
			light->vulnerable = false;
			light->unk04 = 0;

			light++;
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void func0f00372c(void)
{
	if (g_Vars.tickmode != var80061458) {
		if (TICKMODE_NORMAL == g_Vars.tickmode && TICKMODE_NORMAL != var80061458) {
			func0f0035c0();
		}

		var80061458 = g_Vars.tickmode;
	}
}
#endif

void func0f0037ac(void)
{
#if VERSION >= VERSION_NTSC_1_0
	s32 i;
	s32 numprocessed = 0;
#else
	s32 numprocessed = 0;
	s32 i;
#endif
	s32 j;
	bool wasdirty = false;
	struct light *light;
	f32 amount;
	s32 v1;
	f32 angle;
	f32 average;
	u32 stack;

	if (var80061420 == NULL) {
		return;
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_0400;
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].unk54 -= g_Vars.lvupdate240;

		switch (g_Rooms[i].lightop) {
		case LIGHTOP_1:
			g_Rooms[i].unk5c = g_Rooms[i].unk60;

			if (g_Rooms[i].unk5c < 0.0f) {
				g_Rooms[i].unk5c = 0.0f;
			}

			g_Rooms[i].flags |= ROOMFLAG_DIRTY;
			roomSetLighting(i, 0, 0, 0, 0);
			break;
		case LIGHTOP_2:
			if (g_Rooms[i].unk54 < 0) {
				if (RANDOMFRAC() * 100.0f < g_Rooms[i].unk60) {
					g_Rooms[i].unk5c = 1.0f;
				} else {
					g_Rooms[i].unk5c = g_Rooms[i].unk64;

					if (g_Rooms[i].unk5c < 0.0f) {
						g_Rooms[i].unk5c = 0.0f;
					}
				}

				g_Rooms[i].unk54 = g_Rooms[i].unk68;
				g_Rooms[i].flags |= ROOMFLAG_DIRTY;
			}
			break;
		case LIGHTOP_3:
			if (g_Rooms[i].unk54 > 0) {
				g_Rooms[i].unk5c = g_Rooms[i].unk64;
				g_Rooms[i].unk5c += g_Rooms[i].unk54 / g_Rooms[i].unk68 * (g_Rooms[i].unk60 - g_Rooms[i].unk64);

				if (g_Rooms[i].unk5c < 0.0f) {
					g_Rooms[i].unk5c = 0.0f;
				}
			} else {
				roomSetLighting(i, 0, 0, 0, 0);
			}

			g_Rooms[i].flags |= ROOMFLAG_DIRTY;
			break;
		case LIGHTOP_4:
			v1 = g_Rooms[i].unk54 > 0 ? g_Rooms[i].unk54 : -g_Rooms[i].unk54;

			angle = (v1 % (s32) g_Rooms[i].unk68) * M_TAU / g_Rooms[i].unk68;
			average = (g_Rooms[i].unk60 + g_Rooms[i].unk64) * 0.5f;

			g_Rooms[i].unk5c = g_Rooms[i].unk60 + (cosf(angle) + 1.0f) * average;

			if (g_Rooms[i].unk5c < 0.0f) {
				g_Rooms[i].unk5c = 0.0f;
			}

			g_Rooms[i].flags |= ROOMFLAG_DIRTY;
			break;
		case LIGHTOP_5:
			g_Rooms[i].flags |= ROOMFLAG_DIRTY;
			break;
		}

		if (g_IsSwitchingGoggles) {
			g_Rooms[i].flags |= ROOMFLAG_DIRTY;
		}

		if (g_Rooms[i].flags & ROOMFLAG_DIRTY) {
			if (g_Rooms[i].numlights != 0) {
				s32 numlightson = 0;
				struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];

				for (j = 0; j < g_Rooms[i].numlights; j++) {
					if (light->on) {
						numlightson++;
					}

					light++;
				}

				if (g_Rooms[i].flags & ROOMFLAG_LIGHTSOFF) {
					amount = 2.0f;
				} else if (numlightson != 0) {
					amount = g_Rooms[i].unk4c;
				} else {
					amount = (f32)g_Rooms[i].unk4c / 2;
				}
			} else {
				if (g_Rooms[i].flags & ROOMFLAG_LIGHTSOFF) {
					amount = 2.0f;
				} else {
					amount = g_Rooms[i].unk4c;
				}
			}

			amount *= g_Rooms[i].unk5c;
			g_Rooms[i].brightness = amount;

			light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];

			for (j = 0; j < g_Rooms[i].numlights; j++) {
				if (light->on) {
					amount = g_Rooms[i].unk5c * light->unk04;
					g_Rooms[i].brightness += (s32)amount;
				}

				light++;
			}

			if (g_Rooms[i].brightness > 255) {
				g_Rooms[i].brightness = 255;
			}

			g_Rooms[i].flags &= ~ROOMFLAG_DIRTY;

			wasdirty = 1;
		}

		if (g_Rooms[i].unk52 != 0) {
			s32 updaterate = g_Vars.lvupdate240 * 2;

			if (var80061420 != NULL) {
				s32 spa0 = 0;
				s32 sp9c = 0;

				s32 ret = func0f177c8c(var80061420[i].unk04, &spa0, &sp9c);

				while (ret != -1) {
					if (ret != 0) {
						g_Rooms[sp9c].flags |= ROOMFLAG_0400;
					}

					ret = func0f177c8c(var80061420[i].unk04, &spa0, &sp9c);
				}
			}

			if (g_Rooms[i].unk52 > 0) {
				if (g_Rooms[i].unk52 < updaterate) {
					updaterate = g_Rooms[i].unk52;
				}

				g_Rooms[i].unk52 -= updaterate;
			} else {
				if (g_Rooms[i].unk52 > updaterate) {
					updaterate = g_Rooms[i].unk52;
				}

				g_Rooms[i].unk52 += updaterate;
			}

			g_Rooms[i].flags |= ROOMFLAG_0400;
		}

		g_Rooms[i].flags &= ~ROOMFLAG_DIRTY;
	}

	if (g_IsSwitchingGoggles || wasdirty) {
		for (i = 1; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags |= ROOMFLAG_0200;
		}
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (i != 0) {
			if ((g_Rooms[i].flags & ROOMFLAG_RENDERALWAYS) || (g_Rooms[i].flags & (ROOMFLAG_ONSCREEN | ROOMFLAG_STANDBY))) {
				if (g_Rooms[i].flags & (ROOMFLAG_0200 | ROOMFLAG_0400)) {
					s32 sum = 0;
					s32 sp90 = 0;
					s32 sp8c = 0;

					s32 ret = func0f177c8c(var80061420[i].unk00, &sp90, &sp8c);

					while (ret != -1) {
						if (sp8c != 0) {
							s32 add = 0;

							if (sp8c) {
								add += (s32)((1.0f / 255.0f) * ret * g_Rooms[sp8c].brightness);
							}

							sum += add;
						}

						ret = func0f177c8c(var80061420[i].unk00, &sp90, &sp8c);
					}

					if (sum > 255) {
						sum = 255;
					}

					g_Rooms[i].unk4b = sum;
					g_Rooms[i].flags |= ROOMFLAG_0040;
					g_Rooms[i].flags |= ROOMFLAG_1000;
					g_Rooms[i].flags &= ~(ROOMFLAG_0200 | ROOMFLAG_0400);

					if (g_Rooms[i].lightop == LIGHTOP_5) {
						s32 sp80;
						s32 sp7c;
						s32 sp78;

						sp78 = sp7c = sp80 = func0f000a10(i);

						scenarioHighlightRoom(i, &sp80, &sp7c, &sp78);

						g_Rooms[i].unk74 = sp80 * (1.0f / 255.0f);
						g_Rooms[i].unk78 = sp7c * (1.0f / 255.0f);
						g_Rooms[i].unk7c = sp78 * (1.0f / 255.0f);
					} else {
						g_Rooms[i].unk74 = func0f000a10(i) * (1.0f / 255.0f);
						g_Rooms[i].unk78 = g_Rooms[i].unk74;
						g_Rooms[i].unk7c = g_Rooms[i].unk74;
					}

					numprocessed++;
				}
			}
		}
	}

	if (g_Vars.joydisableframestogo <= 0 && (numprocessed || g_IsSwitchingGoggles)) {
		struct prop *prop = g_Vars.activeprops;

		while (prop) {
			if (prop->type == PROPTYPE_CHR) {
				for (i = 0; prop->rooms[i] != -1; i++) {
					if (g_Rooms[prop->rooms[i]].flags & ROOMFLAG_1000) {
						if (2 == g_IsSwitchingGoggles) {
							struct chrdata *chr = prop->chr;
							propCalculateShadeColour(chr->prop, chr->nextcol, chr->floorcol);
						} else {
							struct chrdata *chr = prop->chr;
							chr->unk32c_18 = true;
						}
					}
				}
			}

			prop = prop->next;
		}

		g_Vars.remakewallhitvtx = 0xf;
	}

	if (g_IsSwitchingGoggles) {
		g_IsSwitchingGoggles = false;
	}
}

void lightsTick(void)
{
	struct hand *hand1 = &g_Vars.currentplayer->hands[0];
	struct hand *hand2 = &g_Vars.currentplayer->hands[1];

	if (hand1->flashon || hand2->flashon) {
		roomAdjustLighting(g_Vars.currentplayer->prop->rooms[0], 64, 80);
	}
}

void func0f004384(void)
{
	// empty
}

void roomAdjustLighting(s32 roomnum, s32 start, s32 limit)
{
	if (var80061420 && !(g_Rooms[roomnum].flags & ROOMFLAG_OUTDOORS ? 1 : 0)) {
		s32 value;
		s32 sp78 = 0;
		s32 neighbournum = 0;

		value = func0f177c8c(var80061420[roomnum].unk04, &sp78, &neighbournum);

		while (value != -1) {
			f32 increment = value * 0.0039215688593686f * start * 5.0f;

			if (start > 0) {
				if (increment > start) {
					increment = start;
				}
			} else {
				if (increment < start) {
					increment = start;
				}
			}

			// @bug: Should be checking neighbournum flags, not roomnum
			if (!(g_Rooms[roomnum].flags & ROOMFLAG_OUTDOORS ? 1 : 0)) {
				func0f004558(neighbournum, increment, limit);
			}

			value = func0f177c8c(var80061420[roomnum].unk04, &sp78, &neighbournum);
		}
	}
}

void func0f004558(s32 roomnum, s32 increment, s32 limit)
{
	if (roomnum) {
		if (g_Rooms[roomnum].flags & ROOMFLAG_ONSCREEN) {
			if (increment > 0) {
				// Increasing
				if (g_Rooms[roomnum].unk52 < limit) {
					g_Rooms[roomnum].unk52 += increment;

					if (g_Rooms[roomnum].unk52 > limit) {
						g_Rooms[roomnum].unk52 = limit;
					}
				}
			} else {
				// Decreasing
				if (g_Rooms[roomnum].unk52 > limit) {
					g_Rooms[roomnum].unk52 += increment;

					if (g_Rooms[roomnum].unk52 < limit) {
						g_Rooms[roomnum].unk52 = limit;
					}
				}
			}
		}
	}
}

void roomHighlight(s32 roomnum)
{
	s32 i;
	s32 tmpr;
	s32 tmpg;
	s32 tmpb;
	s32 alpha;
	s32 red;
	s32 green;
	s32 blue;
	s32 extra;
	s32 numcolours;
	struct colour *src;
	struct colour *dst;
	u8 s2;
	s32 max;
	f32 mult;
	u32 stack;

	if (var8007fc3c != g_Rooms[roomnum].unk56 && g_Rooms[roomnum].loaded240 != 0) {
		g_Rooms[roomnum].unk56 = var8007fc3c;

		if ((g_Rooms[roomnum].flags & ROOMFLAG_0040) == 0) {
			g_Rooms[roomnum].flags |= ROOMFLAG_0200;
		}

		s2 = func0f000b24(roomnum);
		numcolours = g_Rooms[roomnum].gfxdata->numcolours;
		dst = gfxAllocateColours(numcolours);
		g_Rooms[roomnum].colours = dst;

		extra = g_Rooms[roomnum].unk52;
		src = (struct colour *)((u32)g_Rooms[roomnum].gfxdata->vertices + g_Rooms[roomnum].gfxdata->numvertices * sizeof(struct gfxvtx));
		src = (struct colour *)ALIGN8((s32)src);

		if (g_Rooms[roomnum].flags & ROOMFLAG_RENDERALWAYS) {
			g_Rooms[roomnum].colours = src;
			return;
		}

		for (i = 0; i < numcolours; i++) {
			// @bug? Why is this looking up vertices using a colour index?
			if (g_Rooms[roomnum].gfxdata->vertices[i].flags & 0x01) {
				dst[i].r = src[i].r;
				dst[i].g = src[i].g;
				dst[i].b = src[i].b;
				dst[i].a = src[i].a * (1.0f / 255.0f * s2);
			} else {
				tmpr = src[i].r;
				tmpg = src[i].g;
				tmpb = src[i].b;

				alpha = src[i].a;
				max = tmpr;

				if (tmpg > max) {
					max = tmpg;
				}

				if (tmpb > max) {
					max = tmpb;
				}

				if (max > s2) {
					mult = s2 / (f32)max;
				} else {
					mult = 1.0f;
				}

				red = tmpr * mult;
				green = tmpg * mult;
				blue = tmpb * mult;
				max *= mult;

				if (extra + max > 285) {
					extra = 285 - max;
				}

				if (red + green + blue != 0
						|| g_Rooms[roomnum].unk5c == 0.0f
						|| (g_Rooms[roomnum].flags & ROOMFLAG_LIGHTSOFF)) {
					red += extra;
					green += extra;
					blue += extra;
				}

				if (g_Rooms[roomnum].lightop == LIGHTOP_5) {
					scenarioHighlightRoom(roomnum, &red, &green, &blue);
				}

				if (red > 255) {
					red = 255;
				}

				if (green > 255) {
					green = 255;
				}

				if (blue > 255) {
					blue = 255;
				}

				if (red < 0) {
					red = 0;
				}

				if (green < 0) {
					green = 0;
				}

				if (blue < 0) {
					blue = 0;
				}

				dst[i].r = red;
				dst[i].g = green;
				dst[i].b = blue;
				dst[i].a = alpha;
			}
		}
	}
}

void func0f004c6c(void)
{
	s32 sp44;
	s32 sp40;
	s32 sp3c;
	s32 sp38;
	s32 sp34;
	s32 i;
	s32 j;
	s32 s4;
	u8 *ptr;
	u8 *backupptr;

	sp44 = align16(0x2000);
	sp40 = align16(g_NumPortals * 4);
	sp3c = align16(g_NumPortals * 0xc);
	sp38 = align16(g_NumPortals * 4);
	sp34 = align16(g_NumPortals * 2);

	for (i = 0, s4 = sp38; i < g_NumPortals; i++) {
		if (i != 0) {
			s4 += i * 2;
		}
	}

	s4 = align16(s4);
	ptr = mempAlloc(align16(s4), MEMPOOL_STAGE);
	var80061430 = (void *)ptr;

	ptr += sp38;

	for (i = 0; i < g_NumPortals; i++) {
		if (i != 0) {
			var80061430[i] = (void *)ptr;
			ptr += i * 2;
		} else {
			var80061430[i] = 0;
		}
	}

	s4 += sp3c;
	s4 += sp44;
	s4 += sp40;
	s4 += sp38;
	s4 += g_NumPortals * sp34;

	align16((s32)s4);

	ptr = mempGetNextStageAllocation();
	var8009cad0 = (void *)ptr;
	ptr += sp44;

	var8009cad8 = (void *)ptr;
	ptr += sp40;

	var8006142c = (void *)ptr;
	ptr += sp38;

	backupptr = ptr;

	ptr += g_NumPortals * sp34;
	var80061428 = (void *)ptr;
	ptr = backupptr;

	s4 = sp38;

	for (i = 0; i < g_NumPortals; i++) {
		var8006142c[i] = (void *)ptr;
		ptr += sp34;
		s4 += sp34;

		for (j = 0; j < g_NumPortals; j++) {
			var8006142c[i][j] = 0x8009;
		}
	}

	for (i = 0; i < g_NumPortals; i++) {
		var8009cad8[i] = portalGetXluFrac(i) > 0.5f;

		portalGetAvgVertexPos(i, &var80061428[i]);
	}

	if (g_Vars.stagenum == STAGE_INVESTIGATION) {
		var8009cad8[0] = 1;
	}

	for (i = 0; i < g_NumPortals; i++) {
		var8006142c[i][i] = 0;
	}

	func0f00505c();

	for (i = 0; i < g_NumPortals; i++) {
		for (j = 0; j < i; j++) {
			u16 a = var8006142c[i][j];
			u16 b = var8006142c[j][i];

			var80061430[i][j] = a < b ? a : b;
		}
	}
}

void func0f00505c(void)
{
	s32 j;
	s32 sp78;
	s32 i;
	s32 k;
	s32 portalnum;
	s32 portalnum2;
	s32 roomnum;
	s32 l;
	u16 dist;
	u32 stack;

	for (i = 0; i < g_NumPortals; i++) {
		for (j = 0, var8009cad0[0] = i, sp78 = 1; j != sp78; j = (j + 1) & 0x7ff) {
			portalnum = var8009cad0[j];

			for (k = 0; k < 2; k++) {
				if (k != 0) {
					roomnum = g_BgPortals[portalnum].roomnum2;
				} else {
					roomnum = g_BgPortals[portalnum].roomnum1;
				}

				for (l = 0; l < g_Rooms[roomnum].numportals; l++) {
					portalnum2 = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + l];

					if (portalnum2 != portalnum && var8009cad8[portalnum2] != 0) {
						if (var8006142c[portalnum][portalnum2] >= 0x8000) {
							f32 xdiff = var80061428[portalnum].x - var80061428[portalnum2].x;
							f32 ydiff = var80061428[portalnum].y - var80061428[portalnum2].y;
							f32 zdiff = var80061428[portalnum].z - var80061428[portalnum2].z;

							f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

							var8006142c[portalnum][portalnum2] = dist;
							var8006142c[portalnum2][portalnum] = dist;
						}

						dist = (var8006142c[i][portalnum] + var8006142c[portalnum2][portalnum]);

						if (dist <= 5800 && ((i == portalnum) != 0 || dist < var8006142c[i][portalnum2])) {
							var8006142c[i][portalnum2] = dist;
							var8009cad0[sp78] = portalnum2;
							sp78 = (sp78 + 1) & 0x7ff;
						}
					}
				}
			}
		}
	}
}

f32 func0f0053d0(s32 roomnum1, struct coord *pos1, s32 portalnum1, s32 roomnum2, struct coord *pos2, s32 portalnum2, f32 *arg6)
{
	f32 sp6c;
	f32 *sp68;
	f32 sp64;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;

	sp6c = 32767.0f;
	sp68 = arg6 ? arg6 : &sp6c;
	sp64 = *sp68;

	xdiff = pos1->x - pos2->x;
	xdiff = xdiff > 0.0f ? xdiff : -xdiff;

	if (xdiff < sp64) {
		zdiff = pos1->z - pos2->z;
		zdiff = zdiff > 0.0f ? zdiff : -zdiff;

		if (zdiff < sp64) {
			ydiff = pos1->y - pos2->y;
			ydiff = ydiff > 0.0f ? ydiff : -ydiff;

			if (ydiff < sp64) {
				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

				if (dist < sp64) {
					if (roomnum1 == roomnum2 || portalnum1 == portalnum2) {
						if (dist < *sp68) {
							*sp68 = dist;
						}
					} else {
						f32 sp50 = func0f000920(portalnum1, portalnum2);

						if (sp50 < sp64) {
							struct coord sp44;
							f32 xdiff2;
							f32 zdiff2;

							portalGetAvgVertexPos(portalnum1, &sp44);
							sp64 -= sp50;

							xdiff2 = sp44.x - pos1->x;
							xdiff2 = xdiff2 > 0.0f ? xdiff2 : -xdiff2;

							if (xdiff2 < sp64) {
								zdiff2 = sp44.z - pos1->z;
								zdiff2 = zdiff2 > 0.0f ? zdiff2 : -zdiff2;

								if (zdiff2 < sp64) {
									f32 sp38 = sqrtf(xdiff2 * xdiff2 + zdiff2 * zdiff2);

									if (sp38 < sp64) {
										struct coord sp2c;
										f32 xdiff3;
										f32 zdiff3;

										portalGetAvgVertexPos(portalnum2, &sp2c);
										sp64 -= sp38;

										xdiff3 = sp2c.x - pos2->x;
										xdiff3 = xdiff3 > 0.0f ? xdiff3 : -xdiff3;

										if (xdiff3 < sp64) {
											zdiff3 = sp2c.z - pos2->z;
											zdiff3 = zdiff3 > 0.0f ? zdiff3 : -zdiff3;

											if (zdiff3 < sp64) {
												f32 dist3 = sqrtf(xdiff3 * xdiff3 + zdiff3 * zdiff3);

												if (dist3 < sp64) {
													sp64 -= dist3;
													*sp68 -= sp64;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return *sp68;
}

void func0f0056f4(s32 roomnum1, struct coord *pos1, s32 roomnum2, struct coord *pos2, s32 arg4, f32 *result, s32 arg6)
{
	f32 dist;

	if (!var80061444
			|| PLAYERCOUNT() >= 3
			|| roomnum1 == roomnum2
			|| roomnum1 == -1
			|| roomnum2 == -1) {
		f32 xdist = pos1->x - pos2->x;

		if (!(xdist > 0.0f)) {
			xdist = -xdist;
		}

		if (xdist < *result) {
			f32 zdist = pos1->z - pos2->z;

			if (!(zdist > 0.0f)) {
				zdist = -zdist;
			}

			if (zdist < *result) {
				f32 ydist = pos1->y - pos2->y;

				if (!(ydist > 0.0f)) {
					ydist = -ydist;
				}

				if (ydist < *result) {
					dist = sqrtf(xdist * xdist + ydist * ydist + zdist * zdist);

					if (dist < *result) {
						*result = dist;
					}
				}
			}
		}
	} else {
		s32 portalnum1;
		s32 portalnum2;
		s32 i;
		s32 j;

		for (i = 0; i < g_Rooms[roomnum1].numportals; i++) {
			portalnum1 = g_RoomPortals[g_Rooms[roomnum1].roomportallistoffset + i];

			for (j = 0; j < g_Rooms[roomnum2].numportals; j++) {
				portalnum2 = g_RoomPortals[g_Rooms[roomnum2].roomportallistoffset + j];

				dist = func0f0053d0(roomnum1, pos1, portalnum1, roomnum2, pos2, portalnum2, result);

				if (dist < *result) {
					*result = dist;
				}
			}
		}
	}
}

void func0f0059fc(s32 roomnum1, struct coord *pos1, s32 roomnum2, struct coord *pos2, s32 arg4, f32 *result)
{
	s32 portalnum1;
	s32 portalnum2;
	s32 i;
	s32 j;
	f32 dist;

	*result = 32767;

	if (roomnum1 == roomnum2) {
		*result = coordsGetDistance(pos1, pos2);
		return;
	}

	for (i = 0; i < g_Rooms[roomnum1].numportals; i++) {
		portalnum1 = g_RoomPortals[g_Rooms[roomnum1].roomportallistoffset + i];
		if (1);

		for (j = 0; j < g_Rooms[roomnum2].numportals; j++) {
			portalnum2 = g_RoomPortals[g_Rooms[roomnum2].roomportallistoffset + j];
			if (j);
			if (j);

			dist = func0f0053d0(roomnum1, pos1, portalnum1, roomnum2, pos2, portalnum2, NULL);

			if (dist < *result) {
				*result = dist;
			}
		}
	}
}
