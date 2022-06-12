#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
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

#if VERSION < VERSION_NTSC_1_0
u32 var80061478 = 0;
#endif

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

	if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
		value += var8009caec;
	} else {
		value += g_Rooms[roomnum].unk4b;
	}

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

	if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
		return var8009caec;
	}

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
	room->bitfield.prevop = 0;
	room->flags &= ~(ROOMFLAG_0200 | ROOMFLAG_DIRTY | ROOMFLAG_RENDERALWAYS | ROOMFLAG_0040);
	room->unk6c = 1;
	room->unk70 = 1;
	room->unk5c = 1;
	room->unk60 = 0;
	room->unk64 = 0;
	room->unk68 = 0;
}

Gfx *func0f001138(Gfx *gdl, s16 roomnum)
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

	gSPLookAtX(gdl++, camGetUnk175c()->m[0]);
	gSPLookAtY(gdl++, camGetUnk175c()->m[1]);

	return gdl;
}

Gfx *func0f001300(Gfx *gdl)
{
	gSPSetLights1(gdl++, var80061460);

	gSPLookAtX(gdl++, camGetUnk175c()->m[0]);
	gSPLookAtY(gdl++, camGetUnk175c()->m[1]);

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

#if VERSION < VERSION_NTSC_1_0
	if (cheatIsActive(CHEAT_PERFECTDARKNESS) && (room->flags & ROOMFLAG_RENDERALWAYS) == 0) {
		room->bitfield.prevop = 1;
		room->unk60 = 0.0f;
	}
#endif

	light = (struct light *)&g_BgLightsFileData[(u32)g_Rooms[roomnum].lightindex * 0x22];

	for (i = 0; i < room->numlights; i++) {
#if VERSION < VERSION_NTSC_1_0
		if (cheatIsActive(CHEAT_PERFECTDARKNESS)) {
			light->unk04 = 0;
			light->unk05_00 = (random() % 2) ? true : false;
			light->healthy = false;
			light->on = false;
			light->sparking = false;
			light->vulnerable = false;
		} else
#endif
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
				func0f0939f8(0, 0, SFX_HIT_GLASS, -1, -1, 0x400, 0, 0, &soundpos, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
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

	ptr = func0f176080();

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
		if ((g_BgPortals[i].flags & PORTALFLAG_ENABLED) && (g_BgPortals[i].flags & PORTALFLAG_04) == 0) {
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
		g_Rooms[i].flags |= ROOMFLAG_VISIBLEBYPLAYER;
	}

	lightingTick();

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_VISIBLEBYPLAYER;
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
	if (cheatIsActive(CHEAT_PERFECTDARKNESS) == false) {
		g_Rooms[roomnum].bitfield.prevop = operation;

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
/*  f003360:	0fc24e7e */ 	jal	func0f0939f8
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
/*  f003360:	0fc24e7e */ 	jal	func0f0939f8
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

// Mismatch: Documented below
//bool lightTickBroken(s32 roomnum, s32 lightnum)
//{
//	struct light *light = (struct light *)(g_BgLightsFileData + ((g_Rooms[roomnum].lightindex + lightnum) * 0x22));
//	struct coord spc8;
//	struct coord spbc;
//	struct coord spb0;
//	struct coord spa4;
//	struct coord sp98;
//	struct coord sp8c;
//	struct coord sp80;
//	struct coord centre; // 74
//	f32 rand1; // 70
//	f32 rand2; // 6c
//	s32 sparktype; // 68
//
//	if (!light->unk05_00) {
//		return false;
//	}
//
//	if (light->sparking) {
//		if ((random() % 8) == 0) {
//			light->sparking = false;
//		} else if ((random() % 2) == 0) {
//			rand1 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
//			rand2 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
//			sparktype = -1;
//
//			spc8.x = light->bbox[1].x - light->bbox[0].x;
//			spc8.y = light->bbox[1].y - light->bbox[0].y;
//			spc8.z = light->bbox[1].z - light->bbox[0].z;
//
//			spc8.x = rand1 * spc8.x;
//			spc8.y = rand1 * spc8.y;
//			spc8.z = rand1 * spc8.z;
//
//			spbc.x = light->bbox[2].x - light->bbox[0].x;
//			spbc.y = light->bbox[2].y - light->bbox[0].y;
//			spbc.z = light->bbox[2].z - light->bbox[0].z;
//
//			spbc.x = rand2 * spbc.x;
//			spbc.y = rand2 * spbc.y;
//			spbc.z = rand2 * spbc.z;
//
//			// @bug? These all use x
//			sp98.x = light->bbox[0].x + spc8.x + spbc.x;
//			sp98.y = light->bbox[0].x + spc8.y + spbc.y;
//			sp98.z = light->bbox[0].x + spc8.z + spbc.z;
//
//			sp8c.x = light->unk07;
//			sp8c.y = light->unk08;
//			sp8c.z = light->unk09;
//
//			sp80.x = -sp8c.f[0];
//			sp80.y = -sp8c.f[1];
//			sp80.z = -sp8c.f[2];
//
//			func0f177164(&sp98, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1546 : 1570, "dlights.c");
//
//			spa4.x += sp80.x;
//			spa4.y += sp80.y;
//			spa4.z += sp80.z;
//
//			func0f177164(&spa4, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1548 : 1572, "dlights.c");
//
//			// Mismatch: Goal loads roomnum * 0x14 into sp58 here but doesn't
//			// use it until after lightGetBboxCentre. The below statement does
//			// the same but also emits the load and store instructions.
//			g_BgRooms[roomnum].unk00 += 0;
//
//			switch (random() % 4) {
//			case 0:
//				sparktype = SPARKTYPE_11;
//				break;
//			case 1:
//				sparktype = SPARKTYPE_12;
//				break;
//			case 2:
//				sparktype = SPARKTYPE_13;
//				break;
//			case 3:
//				sparktype = SPARKTYPE_14;
//				break;
//			}
//
//			lightGetBboxCentre(roomnum, lightnum, &centre);
//
//			centre.x += g_BgRooms[roomnum].pos.x;
//			centre.y += g_BgRooms[roomnum].pos.y;
//			centre.z += g_BgRooms[roomnum].pos.z;
//
//			sparksCreate(roomnum, NULL, &centre, &spa4, &sp8c, sparktype);
//
//			if ((random() % 4) == 0) {
//				s16 smokerooms[2]; // 64
//				smokerooms[0] = roomnum;
//				smokerooms[1] = -1;
//
//				smokeCreateSimple(&centre, smokerooms, SMOKETYPE_BULLETIMPACT);
//			}
//
//			roomAdjustLighting(roomnum, 0x40, 0x50);
//			func0f0939f8(NULL, NULL, propsndGetRandomSparkSound(), -1, -1, 0x400, 0, 0x10, &centre, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
//			return true;
//		}
//	} else {
//		u32 stack;
//
//		if ((random() % 80) == 0) {
//			light->sparking = true;
//		}
//	}
//
//	return false;
//}

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
		func0f141234();

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
		g_Rooms[i].bitfield.prevop = 1;
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
		g_Rooms[i].bitfield.prevop = 1;
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
		if (TICKMODE_CUTSCENE == g_Vars.tickmode && TICKMODE_CUTSCENE != var80061458) {
			func0f003444();
		} else if (TICKMODE_NORMAL == g_Vars.tickmode && TICKMODE_NORMAL != var80061458) {
			func0f0035c0();
		}

		var80061458 = g_Vars.tickmode;
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0037ac
.late_rodata
glabel var7f1a7dbc
.word func0f0037ac+0x134 # f0038e0
glabel var7f1a7dc0
.word func0f0037ac+0x194 # f003940
glabel var7f1a7dc4
.word func0f0037ac+0x278 # f003a24
glabel var7f1a7dc8
.word func0f0037ac+0x328 # f003ad4
glabel var7f1a7dcc
.word func0f0037ac+0x410 # f003bbc
glabel var7f1a7dd0
.word 0x40c90fdb
glabel var7f1a7dd4
.word 0x3b808081
.text
/*  f0037ac:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f0037b0:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0037b4:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f0037b8:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f0037bc:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f0037c0:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f0037c4:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f0037c8:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f0037cc:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0037d0:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f0037d4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0037d8:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0037dc:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0037e0:	afa000d0 */ 	sw	$zero,0xd0($sp)
/*  f0037e4:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f0037e8:	0fc41b99 */ 	jal	cheatIsActive
/*  f0037ec:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f0037f0:	10400003 */ 	beqz	$v0,.L0f003800
/*  f0037f4:	00000000 */ 	nop
/*  f0037f8:	0fc00dcb */ 	jal	func0f00372c
/*  f0037fc:	00000000 */ 	nop
.L0f003800:
/*  f003800:	3c0e8006 */ 	lui	$t6,%hi(var80061420)
/*  f003804:	8dce1420 */ 	lw	$t6,%lo(var80061420)($t6)
/*  f003808:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f00380c:	51c002b4 */ 	beqzl	$t6,.L0f0042e0
/*  f003810:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f003814:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f003818:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f00381c:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f003820:	28410002 */ 	slti	$at,$v0,0x2
/*  f003824:	14200010 */ 	bnez	$at,.L0f003868
/*  f003828:	3c13800a */ 	lui	$s3,%hi(g_Rooms)
/*  f00382c:	26734928 */ 	addiu	$s3,$s3,%lo(g_Rooms)
/*  f003830:	2403fbff */ 	addiu	$v1,$zero,-1025
/*  f003834:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f003838:
/*  f003838:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f00383c:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003840:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003844:	96180000 */ 	lhu	$t8,0x0($s0)
/*  f003848:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f00384c:	0303c824 */ 	and	$t9,$t8,$v1
/*  f003850:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f003854:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f003858:	03c2082a */ 	slt	$at,$s8,$v0
/*  f00385c:	5420fff6 */ 	bnezl	$at,.L0f003838
/*  f003860:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003864:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f003868:
/*  f003868:	3c13800a */ 	lui	$s3,%hi(g_Rooms)
/*  f00386c:	28410002 */ 	slti	$at,$v0,0x2
/*  f003870:	142001aa */ 	bnez	$at,.L0f003f1c
/*  f003874:	26734928 */ 	addiu	$s3,$s3,%lo(g_Rooms)
/*  f003878:	4480b000 */ 	mtc1	$zero,$f22
/*  f00387c:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f003880:	2417008c */ 	addiu	$s7,$zero,0x8c
/*  f003884:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f003888:	27b5009c */ 	addiu	$s5,$sp,0x9c
/*  f00388c:	27b400a0 */ 	addiu	$s4,$sp,0xa0
/*  f003890:	8e680000 */ 	lw	$t0,0x0($s3)
.L0f003894:
/*  f003894:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x34)
/*  f003898:	8d4a9ff4 */ 	lw	$t2,%lo(g_Vars+0x34)($t2)
/*  f00389c:	01128021 */ 	addu	$s0,$t0,$s2
/*  f0038a0:	86090054 */ 	lh	$t1,0x54($s0)
/*  f0038a4:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f0038a8:	a60b0054 */ 	sh	$t3,0x54($s0)
/*  f0038ac:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0038b0:	01928021 */ 	addu	$s0,$t4,$s2
/*  f0038b4:	960d004e */ 	lhu	$t5,0x4e($s0)
/*  f0038b8:	000d7302 */ 	srl	$t6,$t5,0xc
/*  f0038bc:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0038c0:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f0038c4:	102000c2 */ 	beqz	$at,.L0f003bd0
/*  f0038c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0038cc:	3c017f1a */ 	lui	$at,%hi(var7f1a7dbc)
/*  f0038d0:	002f0821 */ 	addu	$at,$at,$t7
/*  f0038d4:	8c2f7dbc */ 	lw	$t7,%lo(var7f1a7dbc)($at)
/*  f0038d8:	01e00008 */ 	jr	$t7
/*  f0038dc:	00000000 */ 	nop
/*  f0038e0:	c6040060 */ 	lwc1	$f4,0x60($s0)
/*  f0038e4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0038e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0038ec:	e604005c */ 	swc1	$f4,0x5c($s0)
/*  f0038f0:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0038f4:	03128021 */ 	addu	$s0,$t8,$s2
/*  f0038f8:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*  f0038fc:	4616303c */ 	c.lt.s	$f6,$f22
/*  f003900:	00000000 */ 	nop
/*  f003904:	45020005 */ 	bc1fl	.L0f00391c
/*  f003908:	96080000 */ 	lhu	$t0,0x0($s0)
/*  f00390c:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f003910:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f003914:	03328021 */ 	addu	$s0,$t9,$s2
/*  f003918:	96080000 */ 	lhu	$t0,0x0($s0)
.L0f00391c:
/*  f00391c:	00003025 */ 	or	$a2,$zero,$zero
/*  f003920:	00003825 */ 	or	$a3,$zero,$zero
/*  f003924:	35090100 */ 	ori	$t1,$t0,0x100
/*  f003928:	a6090000 */ 	sh	$t1,0x0($s0)
/*  f00392c:	0fc00b0a */ 	jal	roomSetLighting
/*  f003930:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f003934:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f003938:	100000a5 */ 	b	.L0f003bd0
/*  f00393c:	01528021 */ 	addu	$s0,$t2,$s2
/*  f003940:	860b0054 */ 	lh	$t3,0x54($s0)
/*  f003944:	056100a2 */ 	bgez	$t3,.L0f003bd0
/*  f003948:	00000000 */ 	nop
/*  f00394c:	0c004b70 */ 	jal	random
/*  f003950:	00000000 */ 	nop
/*  f003954:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003958:	44824000 */ 	mtc1	$v0,$f8
/*  f00395c:	3c014f80 */ 	lui	$at,0x4f80
/*  f003960:	01928021 */ 	addu	$s0,$t4,$s2
/*  f003964:	04410004 */ 	bgez	$v0,.L0f003978
/*  f003968:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f00396c:	44818000 */ 	mtc1	$at,$f16
/*  f003970:	00000000 */ 	nop
/*  f003974:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f003978:
/*  f003978:	3c012f80 */ 	lui	$at,0x2f80
/*  f00397c:	44819000 */ 	mtc1	$at,$f18
/*  f003980:	3c0142c8 */ 	lui	$at,0x42c8
/*  f003984:	44813000 */ 	mtc1	$at,$f6
/*  f003988:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00398c:	c6100060 */ 	lwc1	$f16,0x60($s0)
/*  f003990:	3c013f80 */ 	lui	$at,0x3f80
/*  f003994:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f003998:	4610403c */ 	c.lt.s	$f8,$f16
/*  f00399c:	00000000 */ 	nop
/*  f0039a0:	45020008 */ 	bc1fl	.L0f0039c4
/*  f0039a4:	c6120064 */ 	lwc1	$f18,0x64($s0)
/*  f0039a8:	44815000 */ 	mtc1	$at,$f10
/*  f0039ac:	00000000 */ 	nop
/*  f0039b0:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*  f0039b4:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0039b8:	1000000d */ 	b	.L0f0039f0
/*  f0039bc:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f0039c0:	c6120064 */ 	lwc1	$f18,0x64($s0)
.L0f0039c4:
/*  f0039c4:	e612005c */ 	swc1	$f18,0x5c($s0)
/*  f0039c8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0039cc:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f0039d0:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f0039d4:	4616203c */ 	c.lt.s	$f4,$f22
/*  f0039d8:	00000000 */ 	nop
/*  f0039dc:	45020005 */ 	bc1fl	.L0f0039f4
/*  f0039e0:	c6060068 */ 	lwc1	$f6,0x68($s0)
/*  f0039e4:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f0039e8:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0039ec:	01f28021 */ 	addu	$s0,$t7,$s2
.L0f0039f0:
/*  f0039f0:	c6060068 */ 	lwc1	$f6,0x68($s0)
.L0f0039f4:
/*  f0039f4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0039f8:	44194000 */ 	mfc1	$t9,$f8
/*  f0039fc:	00000000 */ 	nop
/*  f003a00:	a6190054 */ 	sh	$t9,0x54($s0)
/*  f003a04:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003a08:	01128021 */ 	addu	$s0,$t0,$s2
/*  f003a0c:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f003a10:	352a0100 */ 	ori	$t2,$t1,0x100
/*  f003a14:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f003a18:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f003a1c:	1000006c */ 	b	.L0f003bd0
/*  f003a20:	01728021 */ 	addu	$s0,$t3,$s2
/*  f003a24:	860c0054 */ 	lh	$t4,0x54($s0)
/*  f003a28:	00003025 */ 	or	$a2,$zero,$zero
/*  f003a2c:	5980001d */ 	blezl	$t4,.L0f003aa4
/*  f003a30:	03c02025 */ 	or	$a0,$s8,$zero
/*  f003a34:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f003a38:	e610005c */ 	swc1	$f16,0x5c($s0)
/*  f003a3c:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f003a40:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f003a44:	860e0054 */ 	lh	$t6,0x54($s0)
/*  f003a48:	c6040068 */ 	lwc1	$f4,0x68($s0)
/*  f003a4c:	c6080060 */ 	lwc1	$f8,0x60($s0)
/*  f003a50:	448e5000 */ 	mtc1	$t6,$f10
/*  f003a54:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f003a58:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f003a5c:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f003a60:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f003a64:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f003a68:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f003a6c:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f003a70:	e608005c */ 	swc1	$f8,0x5c($s0)
/*  f003a74:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003a78:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003a7c:	c610005c */ 	lwc1	$f16,0x5c($s0)
/*  f003a80:	4616803c */ 	c.lt.s	$f16,$f22
/*  f003a84:	00000000 */ 	nop
/*  f003a88:	4502000d */ 	bc1fl	.L0f003ac0
/*  f003a8c:	96080000 */ 	lhu	$t0,0x0($s0)
/*  f003a90:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f003a94:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f003a98:	10000008 */ 	b	.L0f003abc
/*  f003a9c:	03128021 */ 	addu	$s0,$t8,$s2
/*  f003aa0:	03c02025 */ 	or	$a0,$s8,$zero
.L0f003aa4:
/*  f003aa4:	00002825 */ 	or	$a1,$zero,$zero
/*  f003aa8:	00003825 */ 	or	$a3,$zero,$zero
/*  f003aac:	0fc00b0a */ 	jal	roomSetLighting
/*  f003ab0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f003ab4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f003ab8:	03328021 */ 	addu	$s0,$t9,$s2
.L0f003abc:
/*  f003abc:	96080000 */ 	lhu	$t0,0x0($s0)
.L0f003ac0:
/*  f003ac0:	35090100 */ 	ori	$t1,$t0,0x100
/*  f003ac4:	a6090000 */ 	sh	$t1,0x0($s0)
/*  f003ac8:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f003acc:	10000040 */ 	b	.L0f003bd0
/*  f003ad0:	01528021 */ 	addu	$s0,$t2,$s2
/*  f003ad4:	86020054 */ 	lh	$v0,0x54($s0)
/*  f003ad8:	18400003 */ 	blez	$v0,.L0f003ae8
/*  f003adc:	00021823 */ 	negu	$v1,$v0
/*  f003ae0:	10000001 */ 	b	.L0f003ae8
/*  f003ae4:	00401825 */ 	or	$v1,$v0,$zero
.L0f003ae8:
/*  f003ae8:	c6000068 */ 	lwc1	$f0,0x68($s0)
/*  f003aec:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f003af0:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f003af4:	440c3000 */ 	mfc1	$t4,$f6
/*  f003af8:	c6060060 */ 	lwc1	$f6,0x60($s0)
/*  f003afc:	006c001a */ 	div	$zero,$v1,$t4
/*  f003b00:	00006810 */ 	mfhi	$t5
/*  f003b04:	448d5000 */ 	mtc1	$t5,$f10
/*  f003b08:	15800002 */ 	bnez	$t4,.L0f003b14
/*  f003b0c:	00000000 */ 	nop
/*  f003b10:	0007000d */ 	break	0x7
.L0f003b14:
/*  f003b14:	2401ffff */ 	addiu	$at,$zero,-1
/*  f003b18:	15810004 */ 	bne	$t4,$at,.L0f003b2c
/*  f003b1c:	3c018000 */ 	lui	$at,0x8000
/*  f003b20:	14610002 */ 	bne	$v1,$at,.L0f003b2c
/*  f003b24:	00000000 */ 	nop
/*  f003b28:	0006000d */ 	break	0x6
.L0f003b2c:
/*  f003b2c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f003b30:	3c017f1a */ 	lui	$at,%hi(var7f1a7dd0)
/*  f003b34:	c4327dd0 */ 	lwc1	$f18,%lo(var7f1a7dd0)($at)
/*  f003b38:	3c013f00 */ 	lui	$at,0x3f00
/*  f003b3c:	46068280 */ 	add.s	$f10,$f16,$f6
/*  f003b40:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f003b44:	44812000 */ 	mtc1	$at,$f4
/*  f003b48:	00000000 */ 	nop
/*  f003b4c:	46045502 */ 	mul.s	$f20,$f10,$f4
/*  f003b50:	0c0068f4 */ 	jal	cosf
/*  f003b54:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f003b58:	3c013f80 */ 	lui	$at,0x3f80
/*  f003b5c:	44819000 */ 	mtc1	$at,$f18
/*  f003b60:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003b64:	46120200 */ 	add.s	$f8,$f0,$f18
/*  f003b68:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f003b6c:	c6060060 */ 	lwc1	$f6,0x60($s0)
/*  f003b70:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f003b74:	46068280 */ 	add.s	$f10,$f16,$f6
/*  f003b78:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*  f003b7c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003b80:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003b84:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f003b88:	4616203c */ 	c.lt.s	$f4,$f22
/*  f003b8c:	00000000 */ 	nop
/*  f003b90:	45020005 */ 	bc1fl	.L0f003ba8
/*  f003b94:	96190000 */ 	lhu	$t9,0x0($s0)
/*  f003b98:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f003b9c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f003ba0:	03128021 */ 	addu	$s0,$t8,$s2
/*  f003ba4:	96190000 */ 	lhu	$t9,0x0($s0)
.L0f003ba8:
/*  f003ba8:	37280100 */ 	ori	$t0,$t9,0x100
/*  f003bac:	a6080000 */ 	sh	$t0,0x0($s0)
/*  f003bb0:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f003bb4:	10000006 */ 	b	.L0f003bd0
/*  f003bb8:	01328021 */ 	addu	$s0,$t1,$s2
/*  f003bbc:	960a0000 */ 	lhu	$t2,0x0($s0)
/*  f003bc0:	354b0100 */ 	ori	$t3,$t2,0x100
/*  f003bc4:	a60b0000 */ 	sh	$t3,0x0($s0)
/*  f003bc8:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003bcc:	01928021 */ 	addu	$s0,$t4,$s2
.L0f003bd0:
/*  f003bd0:	3c0d8006 */ 	lui	$t5,%hi(g_IsSwitchingGoggles)
/*  f003bd4:	8dad144c */ 	lw	$t5,%lo(g_IsSwitchingGoggles)($t5)
/*  f003bd8:	51a00007 */ 	beqzl	$t5,.L0f003bf8
/*  f003bdc:	96060000 */ 	lhu	$a2,0x0($s0)
/*  f003be0:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f003be4:	35cf0100 */ 	ori	$t7,$t6,0x100
/*  f003be8:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f003bec:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f003bf0:	03128021 */ 	addu	$s0,$t8,$s2
/*  f003bf4:	96060000 */ 	lhu	$a2,0x0($s0)
.L0f003bf8:
/*  f003bf8:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f003bfc:	5320007f */ 	beqzl	$t9,.L0f003dfc
/*  f003c00:	860a0052 */ 	lh	$t2,0x52($s0)
/*  f003c04:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003c08:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f003c0c:	afa800c8 */ 	sw	$t0,0xc8($sp)
/*  f003c10:	10800032 */ 	beqz	$a0,.L0f003cdc
/*  f003c14:	00001825 */ 	or	$v1,$zero,$zero
/*  f003c18:	9609000a */ 	lhu	$t1,0xa($s0)
/*  f003c1c:	3c0b800a */ 	lui	$t3,%hi(g_BgLightsFileData)
/*  f003c20:	8d6b4cd8 */ 	lw	$t3,%lo(g_BgLightsFileData)($t3)
/*  f003c24:	00095100 */ 	sll	$t2,$t1,0x4
/*  f003c28:	01495021 */ 	addu	$t2,$t2,$t1
/*  f003c2c:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f003c30:	00002825 */ 	or	$a1,$zero,$zero
/*  f003c34:	1880000b */ 	blez	$a0,.L0f003c64
/*  f003c38:	014b1021 */ 	addu	$v0,$t2,$t3
.L0f003c3c:
/*  f003c3c:	944c0004 */ 	lhu	$t4,0x4($v0)
/*  f003c40:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f003c44:	0064082a */ 	slt	$at,$v1,$a0
/*  f003c48:	000c7680 */ 	sll	$t6,$t4,0x1a
/*  f003c4c:	05c10002 */ 	bgez	$t6,.L0f003c58
/*  f003c50:	00000000 */ 	nop
/*  f003c54:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f003c58:
/*  f003c58:	1420fff8 */ 	bnez	$at,.L0f003c3c
/*  f003c5c:	24420022 */ 	addiu	$v0,$v0,0x22
/*  f003c60:	00001825 */ 	or	$v1,$zero,$zero
.L0f003c64:
/*  f003c64:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f003c68:	11e00004 */ 	beqz	$t7,.L0f003c7c
/*  f003c6c:	3c014000 */ 	lui	$at,0x4000
/*  f003c70:	44810000 */ 	mtc1	$at,$f0
/*  f003c74:	10000028 */ 	b	.L0f003d18
/*  f003c78:	c610005c */ 	lwc1	$f16,0x5c($s0)
.L0f003c7c:
/*  f003c7c:	50a0000c */ 	beqzl	$a1,.L0f003cb0
/*  f003c80:	9219004c */ 	lbu	$t9,0x4c($s0)
/*  f003c84:	9218004c */ 	lbu	$t8,0x4c($s0)
/*  f003c88:	3c014f80 */ 	lui	$at,0x4f80
/*  f003c8c:	44989000 */ 	mtc1	$t8,$f18
/*  f003c90:	07010020 */ 	bgez	$t8,.L0f003d14
/*  f003c94:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f003c98:	44814000 */ 	mtc1	$at,$f8
/*  f003c9c:	00000000 */ 	nop
/*  f003ca0:	46080000 */ 	add.s	$f0,$f0,$f8
/*  f003ca4:	1000001c */ 	b	.L0f003d18
/*  f003ca8:	c610005c */ 	lwc1	$f16,0x5c($s0)
/*  f003cac:	9219004c */ 	lbu	$t9,0x4c($s0)
.L0f003cb0:
/*  f003cb0:	3c014f80 */ 	lui	$at,0x4f80
/*  f003cb4:	44998000 */ 	mtc1	$t9,$f16
/*  f003cb8:	07210004 */ 	bgez	$t9,.L0f003ccc
/*  f003cbc:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f003cc0:	44815000 */ 	mtc1	$at,$f10
/*  f003cc4:	00000000 */ 	nop
/*  f003cc8:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f003ccc:
/*  f003ccc:	3c014000 */ 	lui	$at,0x4000
/*  f003cd0:	44812000 */ 	mtc1	$at,$f4
/*  f003cd4:	1000000f */ 	b	.L0f003d14
/*  f003cd8:	46043003 */ 	div.s	$f0,$f6,$f4
.L0f003cdc:
/*  f003cdc:	30c82000 */ 	andi	$t0,$a2,0x2000
/*  f003ce0:	11000004 */ 	beqz	$t0,.L0f003cf4
/*  f003ce4:	3c014000 */ 	lui	$at,0x4000
/*  f003ce8:	44810000 */ 	mtc1	$at,$f0
/*  f003cec:	1000000a */ 	b	.L0f003d18
/*  f003cf0:	c610005c */ 	lwc1	$f16,0x5c($s0)
.L0f003cf4:
/*  f003cf4:	9209004c */ 	lbu	$t1,0x4c($s0)
/*  f003cf8:	3c014f80 */ 	lui	$at,0x4f80
/*  f003cfc:	44899000 */ 	mtc1	$t1,$f18
/*  f003d00:	05210004 */ 	bgez	$t1,.L0f003d14
/*  f003d04:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f003d08:	44814000 */ 	mtc1	$at,$f8
/*  f003d0c:	00000000 */ 	nop
/*  f003d10:	46080000 */ 	add.s	$f0,$f0,$f8
.L0f003d14:
/*  f003d14:	c610005c */ 	lwc1	$f16,0x5c($s0)
.L0f003d18:
/*  f003d18:	3c0f800a */ 	lui	$t7,%hi(g_BgLightsFileData)
/*  f003d1c:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f003d20:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f003d24:	440b5000 */ 	mfc1	$t3,$f10
/*  f003d28:	00000000 */ 	nop
/*  f003d2c:	a60b0050 */ 	sh	$t3,0x50($s0)
/*  f003d30:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003d34:	8def4cd8 */ 	lw	$t7,%lo(g_BgLightsFileData)($t7)
/*  f003d38:	01928021 */ 	addu	$s0,$t4,$s2
/*  f003d3c:	960d000a */ 	lhu	$t5,0xa($s0)
/*  f003d40:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003d44:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f003d48:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f003d4c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f003d50:	1880001c */ 	blez	$a0,.L0f003dc4
/*  f003d54:	01cf1021 */ 	addu	$v0,$t6,$t7
.L0f003d58:
/*  f003d58:	94580004 */ 	lhu	$t8,0x4($v0)
/*  f003d5c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f003d60:	0018ce80 */ 	sll	$t9,$t8,0x1a
/*  f003d64:	07230015 */ 	bgezl	$t9,.L0f003dbc
/*  f003d68:	0064082a */ 	slt	$at,$v1,$a0
/*  f003d6c:	90490004 */ 	lbu	$t1,0x4($v0)
/*  f003d70:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*  f003d74:	3c014f80 */ 	lui	$at,0x4f80
/*  f003d78:	44892000 */ 	mtc1	$t1,$f4
/*  f003d7c:	05210004 */ 	bgez	$t1,.L0f003d90
/*  f003d80:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f003d84:	44814000 */ 	mtc1	$at,$f8
/*  f003d88:	00000000 */ 	nop
/*  f003d8c:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f003d90:
/*  f003d90:	46123002 */ 	mul.s	$f0,$f6,$f18
/*  f003d94:	860a0050 */ 	lh	$t2,0x50($s0)
/*  f003d98:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f003d9c:	440c8000 */ 	mfc1	$t4,$f16
/*  f003da0:	00000000 */ 	nop
/*  f003da4:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f003da8:	a60d0050 */ 	sh	$t5,0x50($s0)
/*  f003dac:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003db0:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f003db4:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003db8:	0064082a */ 	slt	$at,$v1,$a0
.L0f003dbc:
/*  f003dbc:	1420ffe6 */ 	bnez	$at,.L0f003d58
/*  f003dc0:	24420022 */ 	addiu	$v0,$v0,0x22
.L0f003dc4:
/*  f003dc4:	860f0050 */ 	lh	$t7,0x50($s0)
/*  f003dc8:	29e10100 */ 	slti	$at,$t7,0x100
/*  f003dcc:	54200006 */ 	bnezl	$at,.L0f003de8
/*  f003dd0:	96080000 */ 	lhu	$t0,0x0($s0)
/*  f003dd4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f003dd8:	a6180050 */ 	sh	$t8,0x50($s0)
/*  f003ddc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f003de0:	03328021 */ 	addu	$s0,$t9,$s2
/*  f003de4:	96080000 */ 	lhu	$t0,0x0($s0)
.L0f003de8:
/*  f003de8:	3109feff */ 	andi	$t1,$t0,0xfeff
/*  f003dec:	a6090000 */ 	sh	$t1,0x0($s0)
/*  f003df0:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f003df4:	01728021 */ 	addu	$s0,$t3,$s2
/*  f003df8:	860a0052 */ 	lh	$t2,0x52($s0)
.L0f003dfc:
/*  f003dfc:	3c028006 */ 	lui	$v0,%hi(var80061420)
/*  f003e00:	5140003c */ 	beqzl	$t2,.L0f003ef4
/*  f003e04:	96080000 */ 	lhu	$t0,0x0($s0)
/*  f003e08:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x34)
/*  f003e0c:	8e319ff4 */ 	lw	$s1,%lo(g_Vars+0x34)($s1)
/*  f003e10:	8c421420 */ 	lw	$v0,%lo(var80061420)($v0)
/*  f003e14:	001e80c0 */ 	sll	$s0,$s8,0x3
/*  f003e18:	00116040 */ 	sll	$t4,$s1,0x1
/*  f003e1c:	1040001c */ 	beqz	$v0,.L0f003e90
/*  f003e20:	01808825 */ 	or	$s1,$t4,$zero
/*  f003e24:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f003e28:	afa0009c */ 	sw	$zero,0x9c($sp)
/*  f003e2c:	00506821 */ 	addu	$t5,$v0,$s0
/*  f003e30:	8da40004 */ 	lw	$a0,0x4($t5)
/*  f003e34:	02802825 */ 	or	$a1,$s4,$zero
/*  f003e38:	0fc5df23 */ 	jal	func0f177c8c
/*  f003e3c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003e40:	50560014 */ 	beql	$v0,$s6,.L0f003e94
/*  f003e44:	8e6a0000 */ 	lw	$t2,0x0($s3)
.L0f003e48:
/*  f003e48:	10400009 */ 	beqz	$v0,.L0f003e70
/*  f003e4c:	3c098006 */ 	lui	$t1,%hi(var80061420)
/*  f003e50:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f003e54:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003e58:	01f70019 */ 	multu	$t7,$s7
/*  f003e5c:	0000c012 */ 	mflo	$t8
/*  f003e60:	01d81021 */ 	addu	$v0,$t6,$t8
/*  f003e64:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f003e68:	37280400 */ 	ori	$t0,$t9,0x400
/*  f003e6c:	a4480000 */ 	sh	$t0,0x0($v0)
.L0f003e70:
/*  f003e70:	8d291420 */ 	lw	$t1,%lo(var80061420)($t1)
/*  f003e74:	02802825 */ 	or	$a1,$s4,$zero
/*  f003e78:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003e7c:	01305821 */ 	addu	$t3,$t1,$s0
/*  f003e80:	0fc5df23 */ 	jal	func0f177c8c
/*  f003e84:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f003e88:	1456ffef */ 	bne	$v0,$s6,.L0f003e48
/*  f003e8c:	00000000 */ 	nop
.L0f003e90:
/*  f003e90:	8e6a0000 */ 	lw	$t2,0x0($s3)
.L0f003e94:
/*  f003e94:	01528021 */ 	addu	$s0,$t2,$s2
/*  f003e98:	86020052 */ 	lh	$v0,0x52($s0)
/*  f003e9c:	18400008 */ 	blez	$v0,.L0f003ec0
/*  f003ea0:	0222082a */ 	slt	$at,$s1,$v0
/*  f003ea4:	0051082a */ 	slt	$at,$v0,$s1
/*  f003ea8:	50200003 */ 	beqzl	$at,.L0f003eb8
/*  f003eac:	00516023 */ 	subu	$t4,$v0,$s1
/*  f003eb0:	00408825 */ 	or	$s1,$v0,$zero
/*  f003eb4:	00516023 */ 	subu	$t4,$v0,$s1
.L0f003eb8:
/*  f003eb8:	10000006 */ 	b	.L0f003ed4
/*  f003ebc:	a60c0052 */ 	sh	$t4,0x52($s0)
.L0f003ec0:
/*  f003ec0:	50200003 */ 	beqzl	$at,.L0f003ed0
/*  f003ec4:	00516821 */ 	addu	$t5,$v0,$s1
/*  f003ec8:	00408825 */ 	or	$s1,$v0,$zero
/*  f003ecc:	00516821 */ 	addu	$t5,$v0,$s1
.L0f003ed0:
/*  f003ed0:	a60d0052 */ 	sh	$t5,0x52($s0)
.L0f003ed4:
/*  f003ed4:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003ed8:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003edc:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f003ee0:	35d80400 */ 	ori	$t8,$t6,0x400
/*  f003ee4:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f003ee8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f003eec:	03328021 */ 	addu	$s0,$t9,$s2
/*  f003ef0:	96080000 */ 	lhu	$t0,0x0($s0)
.L0f003ef4:
/*  f003ef4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f003ef8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003efc:	3109feff */ 	andi	$t1,$t0,0xfeff
/*  f003f00:	a6090000 */ 	sh	$t1,0x0($s0)
/*  f003f04:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f003f08:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f003f0c:	03c2082a */ 	slt	$at,$s8,$v0
/*  f003f10:	5420fe60 */ 	bnezl	$at,.L0f003894
/*  f003f14:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003f18:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f003f1c:
/*  f003f1c:	3c0b8006 */ 	lui	$t3,%hi(g_IsSwitchingGoggles)
/*  f003f20:	8d6b144c */ 	lw	$t3,%lo(g_IsSwitchingGoggles)($t3)
/*  f003f24:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f003f28:	2417008c */ 	addiu	$s7,$zero,0x8c
/*  f003f2c:	15600002 */ 	bnez	$t3,.L0f003f38
/*  f003f30:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*  f003f34:	11400010 */ 	beqz	$t2,.L0f003f78
.L0f003f38:
/*  f003f38:	28410002 */ 	slti	$at,$v0,0x2
/*  f003f3c:	1420000e */ 	bnez	$at,.L0f003f78
/*  f003f40:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f003f44:	8e6c0000 */ 	lw	$t4,0x0($s3)
.L0f003f48:
/*  f003f48:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f003f4c:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003f50:	01928021 */ 	addu	$s0,$t4,$s2
/*  f003f54:	960d0000 */ 	lhu	$t5,0x0($s0)
/*  f003f58:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f003f5c:	35af0200 */ 	ori	$t7,$t5,0x200
/*  f003f60:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f003f64:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f003f68:	03c2082a */ 	slt	$at,$s8,$v0
/*  f003f6c:	5420fff6 */ 	bnezl	$at,.L0f003f48
/*  f003f70:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003f74:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f003f78:
/*  f003f78:	28410002 */ 	slti	$at,$v0,0x2
/*  f003f7c:	1420009a */ 	bnez	$at,.L0f0041e8
/*  f003f80:	27b5008c */ 	addiu	$s5,$sp,0x8c
/*  f003f84:	3c017f1a */ 	lui	$at,%hi(var7f1a7dd4)
/*  f003f88:	c4347dd4 */ 	lwc1	$f20,%lo(var7f1a7dd4)($at)
/*  f003f8c:	27b40090 */ 	addiu	$s4,$sp,0x90
.L0f003f90:
/*  f003f90:	53c00092 */ 	beqzl	$s8,.L0f0041dc
/*  f003f94:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003f98:	03d70019 */ 	multu	$s8,$s7
/*  f003f9c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003fa0:	00009012 */ 	mflo	$s2
/*  f003fa4:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f003fa8:	97060000 */ 	lhu	$a2,0x0($t8)
/*  f003fac:	30d90080 */ 	andi	$t9,$a2,0x80
/*  f003fb0:	17200002 */ 	bnez	$t9,.L0f003fbc
/*  f003fb4:	30c8000c */ 	andi	$t0,$a2,0xc
/*  f003fb8:	11000087 */ 	beqz	$t0,.L0f0041d8
.L0f003fbc:
/*  f003fbc:	30c90600 */ 	andi	$t1,$a2,0x600
/*  f003fc0:	11200085 */ 	beqz	$t1,.L0f0041d8
/*  f003fc4:	00008825 */ 	or	$s1,$zero,$zero
/*  f003fc8:	3c0b8006 */ 	lui	$t3,%hi(var80061420)
/*  f003fcc:	8d6b1420 */ 	lw	$t3,%lo(var80061420)($t3)
/*  f003fd0:	001e80c0 */ 	sll	$s0,$s8,0x3
/*  f003fd4:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f003fd8:	afa0008c */ 	sw	$zero,0x8c($sp)
/*  f003fdc:	01705021 */ 	addu	$t2,$t3,$s0
/*  f003fe0:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f003fe4:	02802825 */ 	or	$a1,$s4,$zero
/*  f003fe8:	0fc5df23 */ 	jal	func0f177c8c
/*  f003fec:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003ff0:	50560021 */ 	beql	$v0,$s6,.L0f004078
/*  f003ff4:	2a210100 */ 	slti	$at,$s1,0x100
/*  f003ff8:	8fac008c */ 	lw	$t4,0x8c($sp)
.L0f003ffc:
/*  f003ffc:	3c088006 */ 	lui	$t0,%hi(var80061420)
/*  f004000:	11800014 */ 	beqz	$t4,.L0f004054
/*  f004004:	00000000 */ 	nop
/*  f004008:	11800011 */ 	beqz	$t4,.L0f004050
/*  f00400c:	00001825 */ 	or	$v1,$zero,$zero
/*  f004010:	01970019 */ 	multu	$t4,$s7
/*  f004014:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f004018:	44824000 */ 	mtc1	$v0,$f8
/*  f00401c:	00000000 */ 	nop
/*  f004020:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f004024:	00007812 */ 	mflo	$t7
/*  f004028:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f00402c:	85d80050 */ 	lh	$t8,0x50($t6)
/*  f004030:	4606a482 */ 	mul.s	$f18,$f20,$f6
/*  f004034:	44985000 */ 	mtc1	$t8,$f10
/*  f004038:	00000000 */ 	nop
/*  f00403c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f004040:	46049402 */ 	mul.s	$f16,$f18,$f4
/*  f004044:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f004048:	44035000 */ 	mfc1	$v1,$f10
/*  f00404c:	00000000 */ 	nop
.L0f004050:
/*  f004050:	02238821 */ 	addu	$s1,$s1,$v1
.L0f004054:
/*  f004054:	8d081420 */ 	lw	$t0,%lo(var80061420)($t0)
/*  f004058:	02802825 */ 	or	$a1,$s4,$zero
/*  f00405c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f004060:	01104821 */ 	addu	$t1,$t0,$s0
/*  f004064:	0fc5df23 */ 	jal	func0f177c8c
/*  f004068:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f00406c:	5456ffe3 */ 	bnel	$v0,$s6,.L0f003ffc
/*  f004070:	8fac008c */ 	lw	$t4,0x8c($sp)
/*  f004074:	2a210100 */ 	slti	$at,$s1,0x100
.L0f004078:
/*  f004078:	54200003 */ 	bnezl	$at,.L0f004088
/*  f00407c:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f004080:	241100ff */ 	addiu	$s1,$zero,0xff
/*  f004084:	8e6b0000 */ 	lw	$t3,0x0($s3)
.L0f004088:
/*  f004088:	24010005 */ 	addiu	$at,$zero,0x5
/*  f00408c:	01725021 */ 	addu	$t2,$t3,$s2
/*  f004090:	a151004b */ 	sb	$s1,0x4b($t2)
/*  f004094:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f004098:	01928021 */ 	addu	$s0,$t4,$s2
/*  f00409c:	960d0000 */ 	lhu	$t5,0x0($s0)
/*  f0040a0:	35af0040 */ 	ori	$t7,$t5,0x40
/*  f0040a4:	a60f0000 */ 	sh	$t7,0x0($s0)
/*  f0040a8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0040ac:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f0040b0:	96180000 */ 	lhu	$t8,0x0($s0)
/*  f0040b4:	37191000 */ 	ori	$t9,$t8,0x1000
/*  f0040b8:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f0040bc:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0040c0:	01128021 */ 	addu	$s0,$t0,$s2
/*  f0040c4:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f0040c8:	312bf9ff */ 	andi	$t3,$t1,0xf9ff
/*  f0040cc:	a60b0000 */ 	sh	$t3,0x0($s0)
/*  f0040d0:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f0040d4:	01526021 */ 	addu	$t4,$t2,$s2
/*  f0040d8:	958d004e */ 	lhu	$t5,0x4e($t4)
/*  f0040dc:	000d7b02 */ 	srl	$t7,$t5,0xc
/*  f0040e0:	15e10023 */ 	bne	$t7,$at,.L0f004170
/*  f0040e4:	00000000 */ 	nop
/*  f0040e8:	0fc00284 */ 	jal	func0f000a10
/*  f0040ec:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0040f0:	001e2400 */ 	sll	$a0,$s8,0x10
/*  f0040f4:	00047403 */ 	sra	$t6,$a0,0x10
/*  f0040f8:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0040fc:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f004100:	01c02025 */ 	or	$a0,$t6,$zero
/*  f004104:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f004108:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f00410c:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f004110:	0fc6192e */ 	jal	scenarioHighlightRoom
/*  f004114:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f004118:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f00411c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f004120:	44984000 */ 	mtc1	$t8,$f8
/*  f004124:	03324021 */ 	addu	$t0,$t9,$s2
/*  f004128:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f00412c:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f004130:	e5120074 */ 	swc1	$f18,0x74($t0)
/*  f004134:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f004138:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f00413c:	44892000 */ 	mtc1	$t1,$f4
/*  f004140:	01725021 */ 	addu	$t2,$t3,$s2
/*  f004144:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f004148:	46148282 */ 	mul.s	$f10,$f16,$f20
/*  f00414c:	e54a0078 */ 	swc1	$f10,0x78($t2)
/*  f004150:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f004154:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f004158:	448c4000 */ 	mtc1	$t4,$f8
/*  f00415c:	01b27821 */ 	addu	$t7,$t5,$s2
/*  f004160:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f004164:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f004168:	10000016 */ 	b	.L0f0041c4
/*  f00416c:	e5f2007c */ 	swc1	$f18,0x7c($t7)
.L0f004170:
/*  f004170:	0fc00284 */ 	jal	func0f000a10
/*  f004174:	03c02025 */ 	or	$a0,$s8,$zero
/*  f004178:	44822000 */ 	mtc1	$v0,$f4
/*  f00417c:	3c014f80 */ 	lui	$at,0x4f80
/*  f004180:	04410004 */ 	bgez	$v0,.L0f004194
/*  f004184:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f004188:	44815000 */ 	mtc1	$at,$f10
/*  f00418c:	00000000 */ 	nop
/*  f004190:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f004194:
/*  f004194:	46148202 */ 	mul.s	$f8,$f16,$f20
/*  f004198:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f00419c:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f0041a0:	e7080074 */ 	swc1	$f8,0x74($t8)
/*  f0041a4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0041a8:	03328021 */ 	addu	$s0,$t9,$s2
/*  f0041ac:	c6060074 */ 	lwc1	$f6,0x74($s0)
/*  f0041b0:	e6060078 */ 	swc1	$f6,0x78($s0)
/*  f0041b4:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f0041b8:	01128021 */ 	addu	$s0,$t0,$s2
/*  f0041bc:	c6120074 */ 	lwc1	$f18,0x74($s0)
/*  f0041c0:	e612007c */ 	swc1	$f18,0x7c($s0)
.L0f0041c4:
/*  f0041c4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f0041c8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f0041cc:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f0041d0:	252b0001 */ 	addiu	$t3,$t1,0x1
/*  f0041d4:	afab00d0 */ 	sw	$t3,0xd0($sp)
.L0f0041d8:
/*  f0041d8:	27de0001 */ 	addiu	$s8,$s8,0x1
.L0f0041dc:
/*  f0041dc:	03c2082a */ 	slt	$at,$s8,$v0
/*  f0041e0:	1420ff6b */ 	bnez	$at,.L0f003f90
/*  f0041e4:	00000000 */ 	nop
.L0f0041e8:
/*  f0041e8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x4d8)
/*  f0041ec:	8d4aa498 */ 	lw	$t2,%lo(g_Vars+0x4d8)($t2)
/*  f0041f0:	3c038006 */ 	lui	$v1,%hi(g_IsSwitchingGoggles)
/*  f0041f4:	8c63144c */ 	lw	$v1,%lo(g_IsSwitchingGoggles)($v1)
/*  f0041f8:	1d400035 */ 	bgtz	$t2,.L0f0042d0
/*  f0041fc:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*  f004200:	15800003 */ 	bnez	$t4,.L0f004210
/*  f004204:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x33c)
/*  f004208:	10600031 */ 	beqz	$v1,.L0f0042d0
/*  f00420c:	00000000 */ 	nop
.L0f004210:
/*  f004210:	8e31a2fc */ 	lw	$s1,%lo(g_Vars+0x33c)($s1)
/*  f004214:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f004218:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f00421c:	5220002a */ 	beqzl	$s1,.L0f0042c8
/*  f004220:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f004224:	922d0000 */ 	lbu	$t5,0x0($s1)
.L0f004228:
/*  f004228:	568d0024 */ 	bnel	$s4,$t5,.L0f0042bc
/*  f00422c:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f004230:	862f0028 */ 	lh	$t7,0x28($s1)
/*  f004234:	0000f025 */ 	or	$s8,$zero,$zero
/*  f004238:	02208025 */ 	or	$s0,$s1,$zero
/*  f00423c:	52cf001f */ 	beql	$s6,$t7,.L0f0042bc
/*  f004240:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f004244:	86220028 */ 	lh	$v0,0x28($s1)
.L0f004248:
/*  f004248:	00570019 */ 	multu	$v0,$s7
/*  f00424c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f004250:	0000c012 */ 	mflo	$t8
/*  f004254:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f004258:	97280000 */ 	lhu	$t0,0x0($t9)
/*  f00425c:	31091000 */ 	andi	$t1,$t0,0x1000
/*  f004260:	51200012 */ 	beqzl	$t1,.L0f0042ac
/*  f004264:	8602002a */ 	lh	$v0,0x2a($s0)
/*  f004268:	5472000a */ 	bnel	$v1,$s2,.L0f004294
/*  f00426c:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f004270:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f004274:	8c44001c */ 	lw	$a0,0x1c($v0)
/*  f004278:	244500fc */ 	addiu	$a1,$v0,0xfc
/*  f00427c:	0fc1a451 */ 	jal	func0f069144
/*  f004280:	9446018a */ 	lhu	$a2,0x18a($v0)
/*  f004284:	3c038006 */ 	lui	$v1,%hi(g_IsSwitchingGoggles)
/*  f004288:	10000007 */ 	b	.L0f0042a8
/*  f00428c:	8c63144c */ 	lw	$v1,%lo(g_IsSwitchingGoggles)($v1)
/*  f004290:	8e220004 */ 	lw	$v0,0x4($s1)
.L0f004294:
/*  f004294:	3c038006 */ 	lui	$v1,%hi(g_IsSwitchingGoggles)
/*  f004298:	904a032e */ 	lbu	$t2,0x32e($v0)
/*  f00429c:	354c0020 */ 	ori	$t4,$t2,0x20
/*  f0042a0:	a04c032e */ 	sb	$t4,0x32e($v0)
/*  f0042a4:	8c63144c */ 	lw	$v1,%lo(g_IsSwitchingGoggles)($v1)
.L0f0042a8:
/*  f0042a8:	8602002a */ 	lh	$v0,0x2a($s0)
.L0f0042ac:
/*  f0042ac:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0042b0:	16c2ffe5 */ 	bne	$s6,$v0,.L0f004248
/*  f0042b4:	00000000 */ 	nop
/*  f0042b8:	8e310020 */ 	lw	$s1,0x20($s1)
.L0f0042bc:
/*  f0042bc:	5620ffda */ 	bnezl	$s1,.L0f004228
/*  f0042c0:	922d0000 */ 	lbu	$t5,0x0($s1)
/*  f0042c4:	240d000f */ 	addiu	$t5,$zero,0xf
.L0f0042c8:
/*  f0042c8:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4e1)
/*  f0042cc:	a02da4a1 */ 	sb	$t5,%lo(g_Vars+0x4e1)($at)
.L0f0042d0:
/*  f0042d0:	10600002 */ 	beqz	$v1,.L0f0042dc
/*  f0042d4:	3c018006 */ 	lui	$at,%hi(g_IsSwitchingGoggles)
/*  f0042d8:	ac20144c */ 	sw	$zero,%lo(g_IsSwitchingGoggles)($at)
.L0f0042dc:
/*  f0042dc:	8fbf0054 */ 	lw	$ra,0x54($sp)
.L0f0042e0:
/*  f0042e0:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0042e4:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0042e8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0042ec:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f0042f0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f0042f4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f0042f8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f0042fc:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f004300:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f004304:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f004308:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f00430c:	03e00008 */ 	jr	$ra
/*  f004310:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#else
GLOBAL_ASM(
glabel func0f0037ac
.late_rodata
glabel var7f1a7dbc
.word func0f0037ac+0x154
glabel var7f1a7dc0
.word func0f0037ac+0x1b4
glabel var7f1a7dc4
.word func0f0037ac+0x298
glabel var7f1a7dc8
.word func0f0037ac+0x348
glabel var7f1a7dcc
.word func0f0037ac+0x430
glabel var7f1a7dd0
.word 0x40c90fdb
glabel var7f1a7dd4
.word 0x3b808081
.text
/*  f0034d4:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f0034d8:	3c038006 */ 	lui	$v1,0x8006
/*  f0034dc:	3c02800a */ 	lui	$v0,0x800a
/*  f0034e0:	8c633980 */ 	lw	$v1,0x3980($v1)
/*  f0034e4:	8c42e96c */ 	lw	$v0,-0x1694($v0)
/*  f0034e8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0034ec:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f0034f0:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f0034f4:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f0034f8:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f0034fc:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f003500:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f003504:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f003508:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f00350c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f003510:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f003514:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f003518:	afa000d4 */ 	sw	$zero,0xd4($sp)
/*  f00351c:	1062000a */ 	beq	$v1,$v0,.NB0f003548
/*  f003520:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f003524:	24010006 */ 	addiu	$at,$zero,0x6
/*  f003528:	14610005 */ 	bne	$v1,$at,.NB0f003540
/*  f00352c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f003530:	14410003 */ 	bne	$v0,$at,.NB0f003540
/*  f003534:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f003538:	3c018006 */ 	lui	$at,0x8006
/*  f00353c:	ac2e395c */ 	sw	$t6,0x395c($at)
.NB0f003540:
/*  f003540:	3c018006 */ 	lui	$at,0x8006
/*  f003544:	ac223980 */ 	sw	$v0,0x3980($at)
.NB0f003548:
/*  f003548:	3c0f8006 */ 	lui	$t7,0x8006
/*  f00354c:	8def3930 */ 	lw	$t7,0x3930($t7)
/*  f003550:	3c02800a */ 	lui	$v0,0x800a
/*  f003554:	51e002b4 */ 	beqzl	$t7,.NB0f004028
/*  f003558:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f00355c:	8c42e97c */ 	lw	$v0,-0x1684($v0)
/*  f003560:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f003564:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f003568:	28410002 */ 	slti	$at,$v0,0x2
/*  f00356c:	14200010 */ 	bnez	$at,.NB0f0035b0
/*  f003570:	3c13800b */ 	lui	$s3,0x800b
/*  f003574:	267390a8 */ 	addiu	$s3,$s3,-28504
/*  f003578:	2403fbff */ 	addiu	$v1,$zero,-1025
/*  f00357c:	8e780000 */ 	lw	$t8,0x0($s3)
.NB0f003580:
/*  f003580:	3c02800a */ 	lui	$v0,0x800a
/*  f003584:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003588:	03128021 */ 	addu	$s0,$t8,$s2
/*  f00358c:	96190000 */ 	lhu	$t9,0x0($s0)
/*  f003590:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f003594:	03234024 */ 	and	$t0,$t9,$v1
/*  f003598:	a6080000 */ 	sh	$t0,0x0($s0)
/*  f00359c:	8c42e97c */ 	lw	$v0,-0x1684($v0)
/*  f0035a0:	03c2082a */ 	slt	$at,$s8,$v0
/*  f0035a4:	5420fff6 */ 	bnezl	$at,.NB0f003580
/*  f0035a8:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0035ac:	241e0001 */ 	addiu	$s8,$zero,0x1
.NB0f0035b0:
/*  f0035b0:	3c13800b */ 	lui	$s3,0x800b
/*  f0035b4:	28410002 */ 	slti	$at,$v0,0x2
/*  f0035b8:	142001aa */ 	bnez	$at,.NB0f003c64
/*  f0035bc:	267390a8 */ 	addiu	$s3,$s3,-28504
/*  f0035c0:	4480b000 */ 	mtc1	$zero,$f22
/*  f0035c4:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f0035c8:	2417008c */ 	addiu	$s7,$zero,0x8c
/*  f0035cc:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0035d0:	27b5009c */ 	addiu	$s5,$sp,0x9c
/*  f0035d4:	27b400a0 */ 	addiu	$s4,$sp,0xa0
/*  f0035d8:	8e690000 */ 	lw	$t1,0x0($s3)
.NB0f0035dc:
/*  f0035dc:	3c0b800a */ 	lui	$t3,0x800a
/*  f0035e0:	8d6be6f4 */ 	lw	$t3,-0x190c($t3)
/*  f0035e4:	01328021 */ 	addu	$s0,$t1,$s2
/*  f0035e8:	860a0054 */ 	lh	$t2,0x54($s0)
/*  f0035ec:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f0035f0:	a60c0054 */ 	sh	$t4,0x54($s0)
/*  f0035f4:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0035f8:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f0035fc:	960e004e */ 	lhu	$t6,0x4e($s0)
/*  f003600:	000e7b02 */ 	srl	$t7,$t6,0xc
/*  f003604:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f003608:	2f010005 */ 	sltiu	$at,$t8,0x5
/*  f00360c:	102000c2 */ 	beqz	$at,.NB0f003918
/*  f003610:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f003614:	3c017f1a */ 	lui	$at,0x7f1a
/*  f003618:	00380821 */ 	addu	$at,$at,$t8
/*  f00361c:	8c381a5c */ 	lw	$t8,0x1a5c($at)
/*  f003620:	03000008 */ 	jr	$t8
/*  f003624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003628:	c6040060 */ 	lwc1	$f4,0x60($s0)
/*  f00362c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f003630:	00002825 */ 	or	$a1,$zero,$zero
/*  f003634:	e604005c */ 	swc1	$f4,0x5c($s0)
/*  f003638:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f00363c:	03328021 */ 	addu	$s0,$t9,$s2
/*  f003640:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*  f003644:	4616303c */ 	c.lt.s	$f6,$f22
/*  f003648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00364c:	45020005 */ 	bc1fl	.NB0f003664
/*  f003650:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f003654:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f003658:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f00365c:	01128021 */ 	addu	$s0,$t0,$s2
/*  f003660:	96090000 */ 	lhu	$t1,0x0($s0)
.NB0f003664:
/*  f003664:	00003025 */ 	or	$a2,$zero,$zero
/*  f003668:	00003825 */ 	or	$a3,$zero,$zero
/*  f00366c:	352a0100 */ 	ori	$t2,$t1,0x100
/*  f003670:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f003674:	0fc00b2e */ 	jal	roomSetLighting
/*  f003678:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f00367c:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f003680:	100000a5 */ 	beqz	$zero,.NB0f003918
/*  f003684:	01728021 */ 	addu	$s0,$t3,$s2
/*  f003688:	860c0054 */ 	lh	$t4,0x54($s0)
/*  f00368c:	058100a2 */ 	bgez	$t4,.NB0f003918
/*  f003690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003694:	0c004d84 */ 	jal	random
/*  f003698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00369c:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0036a0:	44824000 */ 	mtc1	$v0,$f8
/*  f0036a4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0036a8:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f0036ac:	04410004 */ 	bgez	$v0,.NB0f0036c0
/*  f0036b0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0036b4:	44818000 */ 	mtc1	$at,$f16
/*  f0036b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0036bc:	46105280 */ 	add.s	$f10,$f10,$f16
.NB0f0036c0:
/*  f0036c0:	3c012f80 */ 	lui	$at,0x2f80
/*  f0036c4:	44819000 */ 	mtc1	$at,$f18
/*  f0036c8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0036cc:	44813000 */ 	mtc1	$at,$f6
/*  f0036d0:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0036d4:	c6100060 */ 	lwc1	$f16,0x60($s0)
/*  f0036d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0036dc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0036e0:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0036e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0036e8:	45020008 */ 	bc1fl	.NB0f00370c
/*  f0036ec:	c6120064 */ 	lwc1	$f18,0x64($s0)
/*  f0036f0:	44815000 */ 	mtc1	$at,$f10
/*  f0036f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0036f8:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*  f0036fc:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003700:	1000000d */ 	beqz	$zero,.NB0f003738
/*  f003704:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f003708:	c6120064 */ 	lwc1	$f18,0x64($s0)
.NB0f00370c:
/*  f00370c:	e612005c */ 	swc1	$f18,0x5c($s0)
/*  f003710:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003714:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003718:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f00371c:	4616203c */ 	c.lt.s	$f4,$f22
/*  f003720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003724:	45020005 */ 	bc1fl	.NB0f00373c
/*  f003728:	c6060068 */ 	lwc1	$f6,0x68($s0)
/*  f00372c:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f003730:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f003734:	03128021 */ 	addu	$s0,$t8,$s2
.NB0f003738:
/*  f003738:	c6060068 */ 	lwc1	$f6,0x68($s0)
.NB0f00373c:
/*  f00373c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f003740:	44084000 */ 	mfc1	$t0,$f8
/*  f003744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003748:	a6080054 */ 	sh	$t0,0x54($s0)
/*  f00374c:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f003750:	01328021 */ 	addu	$s0,$t1,$s2
/*  f003754:	960a0000 */ 	lhu	$t2,0x0($s0)
/*  f003758:	354b0100 */ 	ori	$t3,$t2,0x100
/*  f00375c:	a60b0000 */ 	sh	$t3,0x0($s0)
/*  f003760:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003764:	1000006c */ 	beqz	$zero,.NB0f003918
/*  f003768:	01928021 */ 	addu	$s0,$t4,$s2
/*  f00376c:	860d0054 */ 	lh	$t5,0x54($s0)
/*  f003770:	00003025 */ 	or	$a2,$zero,$zero
/*  f003774:	59a0001d */ 	blezl	$t5,.NB0f0037ec
/*  f003778:	03c02025 */ 	or	$a0,$s8,$zero
/*  f00377c:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f003780:	e610005c */ 	swc1	$f16,0x5c($s0)
/*  f003784:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003788:	01d28021 */ 	addu	$s0,$t6,$s2
/*  f00378c:	860f0054 */ 	lh	$t7,0x54($s0)
/*  f003790:	c6040068 */ 	lwc1	$f4,0x68($s0)
/*  f003794:	c6080060 */ 	lwc1	$f8,0x60($s0)
/*  f003798:	448f5000 */ 	mtc1	$t7,$f10
/*  f00379c:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f0037a0:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0037a4:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f0037a8:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f0037ac:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f0037b0:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f0037b4:	46122200 */ 	add.s	$f8,$f4,$f18
/*  f0037b8:	e608005c */ 	swc1	$f8,0x5c($s0)
/*  f0037bc:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0037c0:	03128021 */ 	addu	$s0,$t8,$s2
/*  f0037c4:	c610005c */ 	lwc1	$f16,0x5c($s0)
/*  f0037c8:	4616803c */ 	c.lt.s	$f16,$f22
/*  f0037cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0037d0:	4502000d */ 	bc1fl	.NB0f003808
/*  f0037d4:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f0037d8:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f0037dc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0037e0:	10000008 */ 	beqz	$zero,.NB0f003804
/*  f0037e4:	03328021 */ 	addu	$s0,$t9,$s2
/*  f0037e8:	03c02025 */ 	or	$a0,$s8,$zero
.NB0f0037ec:
/*  f0037ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0037f0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0037f4:	0fc00b2e */ 	jal	roomSetLighting
/*  f0037f8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0037fc:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003800:	01128021 */ 	addu	$s0,$t0,$s2
.NB0f003804:
/*  f003804:	96090000 */ 	lhu	$t1,0x0($s0)
.NB0f003808:
/*  f003808:	352a0100 */ 	ori	$t2,$t1,0x100
/*  f00380c:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f003810:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f003814:	10000040 */ 	beqz	$zero,.NB0f003918
/*  f003818:	01728021 */ 	addu	$s0,$t3,$s2
/*  f00381c:	86020054 */ 	lh	$v0,0x54($s0)
/*  f003820:	18400003 */ 	blez	$v0,.NB0f003830
/*  f003824:	00021823 */ 	negu	$v1,$v0
/*  f003828:	10000001 */ 	beqz	$zero,.NB0f003830
/*  f00382c:	00401825 */ 	or	$v1,$v0,$zero
.NB0f003830:
/*  f003830:	c6000068 */ 	lwc1	$f0,0x68($s0)
/*  f003834:	c6100064 */ 	lwc1	$f16,0x64($s0)
/*  f003838:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f00383c:	440d3000 */ 	mfc1	$t5,$f6
/*  f003840:	c6060060 */ 	lwc1	$f6,0x60($s0)
/*  f003844:	006d001a */ 	div	$zero,$v1,$t5
/*  f003848:	00007010 */ 	mfhi	$t6
/*  f00384c:	448e5000 */ 	mtc1	$t6,$f10
/*  f003850:	15a00002 */ 	bnez	$t5,.NB0f00385c
/*  f003854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003858:	0007000d */ 	break	0x7
.NB0f00385c:
/*  f00385c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f003860:	15a10004 */ 	bne	$t5,$at,.NB0f003874
/*  f003864:	3c018000 */ 	lui	$at,0x8000
/*  f003868:	14610002 */ 	bne	$v1,$at,.NB0f003874
/*  f00386c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003870:	0006000d */ 	break	0x6
.NB0f003874:
/*  f003874:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f003878:	3c017f1a */ 	lui	$at,0x7f1a
/*  f00387c:	c4321a70 */ 	lwc1	$f18,0x1a70($at)
/*  f003880:	3c013f00 */ 	lui	$at,0x3f00
/*  f003884:	46068280 */ 	add.s	$f10,$f16,$f6
/*  f003888:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f00388c:	44812000 */ 	mtc1	$at,$f4
/*  f003890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003894:	46045502 */ 	mul.s	$f20,$f10,$f4
/*  f003898:	0c006d52 */ 	jal	cosf
/*  f00389c:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f0038a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0038a4:	44819000 */ 	mtc1	$at,$f18
/*  f0038a8:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f0038ac:	46120200 */ 	add.s	$f8,$f0,$f18
/*  f0038b0:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f0038b4:	c6060060 */ 	lwc1	$f6,0x60($s0)
/*  f0038b8:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f0038bc:	46068280 */ 	add.s	$f10,$f16,$f6
/*  f0038c0:	e60a005c */ 	swc1	$f10,0x5c($s0)
/*  f0038c4:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0038c8:	03128021 */ 	addu	$s0,$t8,$s2
/*  f0038cc:	c604005c */ 	lwc1	$f4,0x5c($s0)
/*  f0038d0:	4616203c */ 	c.lt.s	$f4,$f22
/*  f0038d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0038d8:	45020005 */ 	bc1fl	.NB0f0038f0
/*  f0038dc:	96080000 */ 	lhu	$t0,0x0($s0)
/*  f0038e0:	e616005c */ 	swc1	$f22,0x5c($s0)
/*  f0038e4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0038e8:	03328021 */ 	addu	$s0,$t9,$s2
/*  f0038ec:	96080000 */ 	lhu	$t0,0x0($s0)
.NB0f0038f0:
/*  f0038f0:	35090100 */ 	ori	$t1,$t0,0x100
/*  f0038f4:	a6090000 */ 	sh	$t1,0x0($s0)
/*  f0038f8:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f0038fc:	10000006 */ 	beqz	$zero,.NB0f003918
/*  f003900:	01528021 */ 	addu	$s0,$t2,$s2
/*  f003904:	960b0000 */ 	lhu	$t3,0x0($s0)
/*  f003908:	356c0100 */ 	ori	$t4,$t3,0x100
/*  f00390c:	a60c0000 */ 	sh	$t4,0x0($s0)
/*  f003910:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f003914:	01b28021 */ 	addu	$s0,$t5,$s2
.NB0f003918:
/*  f003918:	3c0e8006 */ 	lui	$t6,0x8006
/*  f00391c:	8dce395c */ 	lw	$t6,0x395c($t6)
/*  f003920:	51c00007 */ 	beqzl	$t6,.NB0f003940
/*  f003924:	96060000 */ 	lhu	$a2,0x0($s0)
/*  f003928:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f00392c:	35f80100 */ 	ori	$t8,$t7,0x100
/*  f003930:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f003934:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f003938:	03328021 */ 	addu	$s0,$t9,$s2
/*  f00393c:	96060000 */ 	lhu	$a2,0x0($s0)
.NB0f003940:
/*  f003940:	30c80100 */ 	andi	$t0,$a2,0x100
/*  f003944:	5100007f */ 	beqzl	$t0,.NB0f003b44
/*  f003948:	860b0052 */ 	lh	$t3,0x52($s0)
/*  f00394c:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003950:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f003954:	afa900c8 */ 	sw	$t1,0xc8($sp)
/*  f003958:	10800032 */ 	beqz	$a0,.NB0f003a24
/*  f00395c:	00001825 */ 	or	$v1,$zero,$zero
/*  f003960:	960a000a */ 	lhu	$t2,0xa($s0)
/*  f003964:	3c0c800b */ 	lui	$t4,0x800b
/*  f003968:	8d8c9458 */ 	lw	$t4,-0x6ba8($t4)
/*  f00396c:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f003970:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f003974:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f003978:	00002825 */ 	or	$a1,$zero,$zero
/*  f00397c:	1880000b */ 	blez	$a0,.NB0f0039ac
/*  f003980:	016c1021 */ 	addu	$v0,$t3,$t4
.NB0f003984:
/*  f003984:	944d0004 */ 	lhu	$t5,0x4($v0)
/*  f003988:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f00398c:	0064082a */ 	slt	$at,$v1,$a0
/*  f003990:	000d7e80 */ 	sll	$t7,$t5,0x1a
/*  f003994:	05e10002 */ 	bgez	$t7,.NB0f0039a0
/*  f003998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00399c:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f0039a0:
/*  f0039a0:	1420fff8 */ 	bnez	$at,.NB0f003984
/*  f0039a4:	24420022 */ 	addiu	$v0,$v0,0x22
/*  f0039a8:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0039ac:
/*  f0039ac:	30d82000 */ 	andi	$t8,$a2,0x2000
/*  f0039b0:	13000004 */ 	beqz	$t8,.NB0f0039c4
/*  f0039b4:	3c014000 */ 	lui	$at,0x4000
/*  f0039b8:	44810000 */ 	mtc1	$at,$f0
/*  f0039bc:	10000028 */ 	beqz	$zero,.NB0f003a60
/*  f0039c0:	c610005c */ 	lwc1	$f16,0x5c($s0)
.NB0f0039c4:
/*  f0039c4:	50a0000c */ 	beqzl	$a1,.NB0f0039f8
/*  f0039c8:	9208004c */ 	lbu	$t0,0x4c($s0)
/*  f0039cc:	9219004c */ 	lbu	$t9,0x4c($s0)
/*  f0039d0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0039d4:	44999000 */ 	mtc1	$t9,$f18
/*  f0039d8:	07210020 */ 	bgez	$t9,.NB0f003a5c
/*  f0039dc:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0039e0:	44814000 */ 	mtc1	$at,$f8
/*  f0039e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0039e8:	46080000 */ 	add.s	$f0,$f0,$f8
/*  f0039ec:	1000001c */ 	beqz	$zero,.NB0f003a60
/*  f0039f0:	c610005c */ 	lwc1	$f16,0x5c($s0)
/*  f0039f4:	9208004c */ 	lbu	$t0,0x4c($s0)
.NB0f0039f8:
/*  f0039f8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0039fc:	44888000 */ 	mtc1	$t0,$f16
/*  f003a00:	05010004 */ 	bgez	$t0,.NB0f003a14
/*  f003a04:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f003a08:	44815000 */ 	mtc1	$at,$f10
/*  f003a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003a10:	460a3180 */ 	add.s	$f6,$f6,$f10
.NB0f003a14:
/*  f003a14:	3c014000 */ 	lui	$at,0x4000
/*  f003a18:	44812000 */ 	mtc1	$at,$f4
/*  f003a1c:	1000000f */ 	beqz	$zero,.NB0f003a5c
/*  f003a20:	46043003 */ 	div.s	$f0,$f6,$f4
.NB0f003a24:
/*  f003a24:	30c92000 */ 	andi	$t1,$a2,0x2000
/*  f003a28:	11200004 */ 	beqz	$t1,.NB0f003a3c
/*  f003a2c:	3c014000 */ 	lui	$at,0x4000
/*  f003a30:	44810000 */ 	mtc1	$at,$f0
/*  f003a34:	1000000a */ 	beqz	$zero,.NB0f003a60
/*  f003a38:	c610005c */ 	lwc1	$f16,0x5c($s0)
.NB0f003a3c:
/*  f003a3c:	920a004c */ 	lbu	$t2,0x4c($s0)
/*  f003a40:	3c014f80 */ 	lui	$at,0x4f80
/*  f003a44:	448a9000 */ 	mtc1	$t2,$f18
/*  f003a48:	05410004 */ 	bgez	$t2,.NB0f003a5c
/*  f003a4c:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f003a50:	44814000 */ 	mtc1	$at,$f8
/*  f003a54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003a58:	46080000 */ 	add.s	$f0,$f0,$f8
.NB0f003a5c:
/*  f003a5c:	c610005c */ 	lwc1	$f16,0x5c($s0)
.NB0f003a60:
/*  f003a60:	3c18800b */ 	lui	$t8,0x800b
/*  f003a64:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f003a68:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f003a6c:	440c5000 */ 	mfc1	$t4,$f10
/*  f003a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003a74:	a60c0050 */ 	sh	$t4,0x50($s0)
/*  f003a78:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f003a7c:	8f189458 */ 	lw	$t8,-0x6ba8($t8)
/*  f003a80:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f003a84:	960e000a */ 	lhu	$t6,0xa($s0)
/*  f003a88:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003a8c:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f003a90:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f003a94:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f003a98:	1880001c */ 	blez	$a0,.NB0f003b0c
/*  f003a9c:	01f81021 */ 	addu	$v0,$t7,$t8
.NB0f003aa0:
/*  f003aa0:	94590004 */ 	lhu	$t9,0x4($v0)
/*  f003aa4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f003aa8:	00194680 */ 	sll	$t0,$t9,0x1a
/*  f003aac:	05030015 */ 	bgezl	$t0,.NB0f003b04
/*  f003ab0:	0064082a */ 	slt	$at,$v1,$a0
/*  f003ab4:	904a0004 */ 	lbu	$t2,0x4($v0)
/*  f003ab8:	c606005c */ 	lwc1	$f6,0x5c($s0)
/*  f003abc:	3c014f80 */ 	lui	$at,0x4f80
/*  f003ac0:	448a2000 */ 	mtc1	$t2,$f4
/*  f003ac4:	05410004 */ 	bgez	$t2,.NB0f003ad8
/*  f003ac8:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f003acc:	44814000 */ 	mtc1	$at,$f8
/*  f003ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003ad4:	46089480 */ 	add.s	$f18,$f18,$f8
.NB0f003ad8:
/*  f003ad8:	46123002 */ 	mul.s	$f0,$f6,$f18
/*  f003adc:	860b0050 */ 	lh	$t3,0x50($s0)
/*  f003ae0:	4600040d */ 	trunc.w.s	$f16,$f0
/*  f003ae4:	440d8000 */ 	mfc1	$t5,$f16
/*  f003ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003aec:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f003af0:	a60e0050 */ 	sh	$t6,0x50($s0)
/*  f003af4:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003af8:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003afc:	82040008 */ 	lb	$a0,0x8($s0)
/*  f003b00:	0064082a */ 	slt	$at,$v1,$a0
.NB0f003b04:
/*  f003b04:	1420ffe6 */ 	bnez	$at,.NB0f003aa0
/*  f003b08:	24420022 */ 	addiu	$v0,$v0,0x22
.NB0f003b0c:
/*  f003b0c:	86180050 */ 	lh	$t8,0x50($s0)
/*  f003b10:	2b010100 */ 	slti	$at,$t8,0x100
/*  f003b14:	54200006 */ 	bnezl	$at,.NB0f003b30
/*  f003b18:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f003b1c:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f003b20:	a6190050 */ 	sh	$t9,0x50($s0)
/*  f003b24:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003b28:	01128021 */ 	addu	$s0,$t0,$s2
/*  f003b2c:	96090000 */ 	lhu	$t1,0x0($s0)
.NB0f003b30:
/*  f003b30:	312afeff */ 	andi	$t2,$t1,0xfeff
/*  f003b34:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f003b38:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003b3c:	01928021 */ 	addu	$s0,$t4,$s2
/*  f003b40:	860b0052 */ 	lh	$t3,0x52($s0)
.NB0f003b44:
/*  f003b44:	3c028006 */ 	lui	$v0,0x8006
/*  f003b48:	5160003c */ 	beqzl	$t3,.NB0f003c3c
/*  f003b4c:	96090000 */ 	lhu	$t1,0x0($s0)
/*  f003b50:	3c11800a */ 	lui	$s1,0x800a
/*  f003b54:	8e31e6f4 */ 	lw	$s1,-0x190c($s1)
/*  f003b58:	8c423930 */ 	lw	$v0,0x3930($v0)
/*  f003b5c:	001e80c0 */ 	sll	$s0,$s8,0x3
/*  f003b60:	00116840 */ 	sll	$t5,$s1,0x1
/*  f003b64:	1040001c */ 	beqz	$v0,.NB0f003bd8
/*  f003b68:	01a08825 */ 	or	$s1,$t5,$zero
/*  f003b6c:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f003b70:	afa0009c */ 	sw	$zero,0x9c($sp)
/*  f003b74:	00507021 */ 	addu	$t6,$v0,$s0
/*  f003b78:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f003b7c:	02802825 */ 	or	$a1,$s4,$zero
/*  f003b80:	0fc5ca4b */ 	jal	func0f177c8c
/*  f003b84:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003b88:	50560014 */ 	beql	$v0,$s6,.NB0f003bdc
/*  f003b8c:	8e6b0000 */ 	lw	$t3,0x0($s3)
.NB0f003b90:
/*  f003b90:	10400009 */ 	beqz	$v0,.NB0f003bb8
/*  f003b94:	3c0a8006 */ 	lui	$t2,0x8006
/*  f003b98:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f003b9c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003ba0:	03170019 */ 	multu	$t8,$s7
/*  f003ba4:	0000c812 */ 	mflo	$t9
/*  f003ba8:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f003bac:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f003bb0:	35090400 */ 	ori	$t1,$t0,0x400
/*  f003bb4:	a4490000 */ 	sh	$t1,0x0($v0)
.NB0f003bb8:
/*  f003bb8:	8d4a3930 */ 	lw	$t2,0x3930($t2)
/*  f003bbc:	02802825 */ 	or	$a1,$s4,$zero
/*  f003bc0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003bc4:	01506021 */ 	addu	$t4,$t2,$s0
/*  f003bc8:	0fc5ca4b */ 	jal	func0f177c8c
/*  f003bcc:	8d840004 */ 	lw	$a0,0x4($t4)
/*  f003bd0:	1456ffef */ 	bne	$v0,$s6,.NB0f003b90
/*  f003bd4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f003bd8:
/*  f003bd8:	8e6b0000 */ 	lw	$t3,0x0($s3)
.NB0f003bdc:
/*  f003bdc:	01728021 */ 	addu	$s0,$t3,$s2
/*  f003be0:	86020052 */ 	lh	$v0,0x52($s0)
/*  f003be4:	18400008 */ 	blez	$v0,.NB0f003c08
/*  f003be8:	0222082a */ 	slt	$at,$s1,$v0
/*  f003bec:	0051082a */ 	slt	$at,$v0,$s1
/*  f003bf0:	50200003 */ 	beqzl	$at,.NB0f003c00
/*  f003bf4:	00516823 */ 	subu	$t5,$v0,$s1
/*  f003bf8:	00408825 */ 	or	$s1,$v0,$zero
/*  f003bfc:	00516823 */ 	subu	$t5,$v0,$s1
.NB0f003c00:
/*  f003c00:	10000006 */ 	beqz	$zero,.NB0f003c1c
/*  f003c04:	a60d0052 */ 	sh	$t5,0x52($s0)
.NB0f003c08:
/*  f003c08:	50200003 */ 	beqzl	$at,.NB0f003c18
/*  f003c0c:	00517021 */ 	addu	$t6,$v0,$s1
/*  f003c10:	00408825 */ 	or	$s1,$v0,$zero
/*  f003c14:	00517021 */ 	addu	$t6,$v0,$s1
.NB0f003c18:
/*  f003c18:	a60e0052 */ 	sh	$t6,0x52($s0)
.NB0f003c1c:
/*  f003c1c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f003c20:	03128021 */ 	addu	$s0,$t8,$s2
/*  f003c24:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f003c28:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f003c2c:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f003c30:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003c34:	01128021 */ 	addu	$s0,$t0,$s2
/*  f003c38:	96090000 */ 	lhu	$t1,0x0($s0)
.NB0f003c3c:
/*  f003c3c:	3c02800a */ 	lui	$v0,0x800a
/*  f003c40:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003c44:	312afeff */ 	andi	$t2,$t1,0xfeff
/*  f003c48:	a60a0000 */ 	sh	$t2,0x0($s0)
/*  f003c4c:	8c42e97c */ 	lw	$v0,-0x1684($v0)
/*  f003c50:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f003c54:	03c2082a */ 	slt	$at,$s8,$v0
/*  f003c58:	5420fe60 */ 	bnezl	$at,.NB0f0035dc
/*  f003c5c:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f003c60:	241e0001 */ 	addiu	$s8,$zero,0x1
.NB0f003c64:
/*  f003c64:	3c0c8006 */ 	lui	$t4,0x8006
/*  f003c68:	8d8c395c */ 	lw	$t4,0x395c($t4)
/*  f003c6c:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f003c70:	2417008c */ 	addiu	$s7,$zero,0x8c
/*  f003c74:	15800002 */ 	bnez	$t4,.NB0f003c80
/*  f003c78:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f003c7c:	11600010 */ 	beqz	$t3,.NB0f003cc0
.NB0f003c80:
/*  f003c80:	28410002 */ 	slti	$at,$v0,0x2
/*  f003c84:	1420000e */ 	bnez	$at,.NB0f003cc0
/*  f003c88:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f003c8c:	8e6d0000 */ 	lw	$t5,0x0($s3)
.NB0f003c90:
/*  f003c90:	3c02800a */ 	lui	$v0,0x800a
/*  f003c94:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003c98:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f003c9c:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f003ca0:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f003ca4:	35d80200 */ 	ori	$t8,$t6,0x200
/*  f003ca8:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f003cac:	8c42e97c */ 	lw	$v0,-0x1684($v0)
/*  f003cb0:	03c2082a */ 	slt	$at,$s8,$v0
/*  f003cb4:	5420fff6 */ 	bnezl	$at,.NB0f003c90
/*  f003cb8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f003cbc:	241e0001 */ 	addiu	$s8,$zero,0x1
.NB0f003cc0:
/*  f003cc0:	28410002 */ 	slti	$at,$v0,0x2
/*  f003cc4:	1420009a */ 	bnez	$at,.NB0f003f30
/*  f003cc8:	27b5008c */ 	addiu	$s5,$sp,0x8c
/*  f003ccc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f003cd0:	c4341a74 */ 	lwc1	$f20,0x1a74($at)
/*  f003cd4:	27b40090 */ 	addiu	$s4,$sp,0x90
.NB0f003cd8:
/*  f003cd8:	53c00092 */ 	beqzl	$s8,.NB0f003f24
/*  f003cdc:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f003ce0:	03d70019 */ 	multu	$s8,$s7
/*  f003ce4:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003ce8:	00009012 */ 	mflo	$s2
/*  f003cec:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f003cf0:	97260000 */ 	lhu	$a2,0x0($t9)
/*  f003cf4:	30c80080 */ 	andi	$t0,$a2,0x80
/*  f003cf8:	15000002 */ 	bnez	$t0,.NB0f003d04
/*  f003cfc:	30c9000c */ 	andi	$t1,$a2,0xc
/*  f003d00:	11200087 */ 	beqz	$t1,.NB0f003f20
.NB0f003d04:
/*  f003d04:	30ca0600 */ 	andi	$t2,$a2,0x600
/*  f003d08:	11400085 */ 	beqz	$t2,.NB0f003f20
/*  f003d0c:	00008825 */ 	or	$s1,$zero,$zero
/*  f003d10:	3c0c8006 */ 	lui	$t4,0x8006
/*  f003d14:	8d8c3930 */ 	lw	$t4,0x3930($t4)
/*  f003d18:	001e80c0 */ 	sll	$s0,$s8,0x3
/*  f003d1c:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f003d20:	afa0008c */ 	sw	$zero,0x8c($sp)
/*  f003d24:	01905821 */ 	addu	$t3,$t4,$s0
/*  f003d28:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f003d2c:	02802825 */ 	or	$a1,$s4,$zero
/*  f003d30:	0fc5ca4b */ 	jal	func0f177c8c
/*  f003d34:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003d38:	50560021 */ 	beql	$v0,$s6,.NB0f003dc0
/*  f003d3c:	2a210100 */ 	slti	$at,$s1,0x100
/*  f003d40:	8fad008c */ 	lw	$t5,0x8c($sp)
.NB0f003d44:
/*  f003d44:	3c098006 */ 	lui	$t1,0x8006
/*  f003d48:	11a00014 */ 	beqz	$t5,.NB0f003d9c
/*  f003d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003d50:	11a00011 */ 	beqz	$t5,.NB0f003d98
/*  f003d54:	00001825 */ 	or	$v1,$zero,$zero
/*  f003d58:	01b70019 */ 	multu	$t5,$s7
/*  f003d5c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003d60:	44824000 */ 	mtc1	$v0,$f8
/*  f003d64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003d68:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f003d6c:	0000c012 */ 	mflo	$t8
/*  f003d70:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f003d74:	85f90050 */ 	lh	$t9,0x50($t7)
/*  f003d78:	4606a482 */ 	mul.s	$f18,$f20,$f6
/*  f003d7c:	44995000 */ 	mtc1	$t9,$f10
/*  f003d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003d84:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f003d88:	46049402 */ 	mul.s	$f16,$f18,$f4
/*  f003d8c:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f003d90:	44035000 */ 	mfc1	$v1,$f10
/*  f003d94:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f003d98:
/*  f003d98:	02238821 */ 	addu	$s1,$s1,$v1
.NB0f003d9c:
/*  f003d9c:	8d293930 */ 	lw	$t1,0x3930($t1)
/*  f003da0:	02802825 */ 	or	$a1,$s4,$zero
/*  f003da4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f003da8:	01305021 */ 	addu	$t2,$t1,$s0
/*  f003dac:	0fc5ca4b */ 	jal	func0f177c8c
/*  f003db0:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f003db4:	5456ffe3 */ 	bnel	$v0,$s6,.NB0f003d44
/*  f003db8:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f003dbc:	2a210100 */ 	slti	$at,$s1,0x100
.NB0f003dc0:
/*  f003dc0:	54200003 */ 	bnezl	$at,.NB0f003dd0
/*  f003dc4:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003dc8:	241100ff */ 	addiu	$s1,$zero,0xff
/*  f003dcc:	8e6c0000 */ 	lw	$t4,0x0($s3)
.NB0f003dd0:
/*  f003dd0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f003dd4:	01925821 */ 	addu	$t3,$t4,$s2
/*  f003dd8:	a171004b */ 	sb	$s1,0x4b($t3)
/*  f003ddc:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f003de0:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f003de4:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f003de8:	35d80040 */ 	ori	$t8,$t6,0x40
/*  f003dec:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f003df0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003df4:	01f28021 */ 	addu	$s0,$t7,$s2
/*  f003df8:	96190000 */ 	lhu	$t9,0x0($s0)
/*  f003dfc:	37281000 */ 	ori	$t0,$t9,0x1000
/*  f003e00:	a6080000 */ 	sh	$t0,0x0($s0)
/*  f003e04:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f003e08:	01328021 */ 	addu	$s0,$t1,$s2
/*  f003e0c:	960a0000 */ 	lhu	$t2,0x0($s0)
/*  f003e10:	314cf9ff */ 	andi	$t4,$t2,0xf9ff
/*  f003e14:	a60c0000 */ 	sh	$t4,0x0($s0)
/*  f003e18:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f003e1c:	01726821 */ 	addu	$t5,$t3,$s2
/*  f003e20:	95ae004e */ 	lhu	$t6,0x4e($t5)
/*  f003e24:	000ec302 */ 	srl	$t8,$t6,0xc
/*  f003e28:	17010023 */ 	bne	$t8,$at,.NB0f003eb8
/*  f003e2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003e30:	0fc00284 */ 	jal	func0f000a10
/*  f003e34:	03c02025 */ 	or	$a0,$s8,$zero
/*  f003e38:	001e2400 */ 	sll	$a0,$s8,0x10
/*  f003e3c:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f003e40:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f003e44:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f003e48:	01e02025 */ 	or	$a0,$t7,$zero
/*  f003e4c:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f003e50:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f003e54:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f003e58:	0fc60248 */ 	jal	scenarioHighlightRoom
/*  f003e5c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f003e60:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f003e64:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003e68:	44994000 */ 	mtc1	$t9,$f8
/*  f003e6c:	01124821 */ 	addu	$t1,$t0,$s2
/*  f003e70:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f003e74:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f003e78:	e5320074 */ 	swc1	$f18,0x74($t1)
/*  f003e7c:	8faa007c */ 	lw	$t2,0x7c($sp)
/*  f003e80:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f003e84:	448a2000 */ 	mtc1	$t2,$f4
/*  f003e88:	01925821 */ 	addu	$t3,$t4,$s2
/*  f003e8c:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f003e90:	46148282 */ 	mul.s	$f10,$f16,$f20
/*  f003e94:	e56a0078 */ 	swc1	$f10,0x78($t3)
/*  f003e98:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f003e9c:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f003ea0:	448d4000 */ 	mtc1	$t5,$f8
/*  f003ea4:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f003ea8:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f003eac:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f003eb0:	10000016 */ 	beqz	$zero,.NB0f003f0c
/*  f003eb4:	e712007c */ 	swc1	$f18,0x7c($t8)
.NB0f003eb8:
/*  f003eb8:	0fc00284 */ 	jal	func0f000a10
/*  f003ebc:	03c02025 */ 	or	$a0,$s8,$zero
/*  f003ec0:	44822000 */ 	mtc1	$v0,$f4
/*  f003ec4:	3c014f80 */ 	lui	$at,0x4f80
/*  f003ec8:	04410004 */ 	bgez	$v0,.NB0f003edc
/*  f003ecc:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f003ed0:	44815000 */ 	mtc1	$at,$f10
/*  f003ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f003ed8:	460a8400 */ 	add.s	$f16,$f16,$f10
.NB0f003edc:
/*  f003edc:	46148202 */ 	mul.s	$f8,$f16,$f20
/*  f003ee0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003ee4:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f003ee8:	e7280074 */ 	swc1	$f8,0x74($t9)
/*  f003eec:	8e680000 */ 	lw	$t0,0x0($s3)
/*  f003ef0:	01128021 */ 	addu	$s0,$t0,$s2
/*  f003ef4:	c6060074 */ 	lwc1	$f6,0x74($s0)
/*  f003ef8:	e6060078 */ 	swc1	$f6,0x78($s0)
/*  f003efc:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f003f00:	01328021 */ 	addu	$s0,$t1,$s2
/*  f003f04:	c6120074 */ 	lwc1	$f18,0x74($s0)
/*  f003f08:	e612007c */ 	swc1	$f18,0x7c($s0)
.NB0f003f0c:
/*  f003f0c:	8faa00d4 */ 	lw	$t2,0xd4($sp)
/*  f003f10:	3c02800a */ 	lui	$v0,0x800a
/*  f003f14:	8c42e97c */ 	lw	$v0,-0x1684($v0)
/*  f003f18:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f003f1c:	afac00d4 */ 	sw	$t4,0xd4($sp)
.NB0f003f20:
/*  f003f20:	27de0001 */ 	addiu	$s8,$s8,0x1
.NB0f003f24:
/*  f003f24:	03c2082a */ 	slt	$at,$s8,$v0
/*  f003f28:	1420ff6b */ 	bnez	$at,.NB0f003cd8
/*  f003f2c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f003f30:
/*  f003f30:	3c0b800a */ 	lui	$t3,0x800a
/*  f003f34:	8d6beb98 */ 	lw	$t3,-0x1468($t3)
/*  f003f38:	3c038006 */ 	lui	$v1,0x8006
/*  f003f3c:	8c63395c */ 	lw	$v1,0x395c($v1)
/*  f003f40:	1d600035 */ 	bgtz	$t3,.NB0f004018
/*  f003f44:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f003f48:	15a00003 */ 	bnez	$t5,.NB0f003f58
/*  f003f4c:	3c11800a */ 	lui	$s1,0x800a
/*  f003f50:	10600031 */ 	beqz	$v1,.NB0f004018
/*  f003f54:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f003f58:
/*  f003f58:	8e31e9fc */ 	lw	$s1,-0x1604($s1)
/*  f003f5c:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f003f60:	5220002b */ 	beqzl	$s1,.NB0f004010
/*  f003f64:	240e000f */ 	addiu	$t6,$zero,0xf
/*  f003f68:	922e0000 */ 	lbu	$t6,0x0($s1)
.NB0f003f6c:
/*  f003f6c:	564e0025 */ 	bnel	$s2,$t6,.NB0f004004
/*  f003f70:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f003f74:	86380028 */ 	lh	$t8,0x28($s1)
/*  f003f78:	0000f025 */ 	or	$s8,$zero,$zero
/*  f003f7c:	02208025 */ 	or	$s0,$s1,$zero
/*  f003f80:	52d80020 */ 	beql	$s6,$t8,.NB0f004004
/*  f003f84:	8e310020 */ 	lw	$s1,0x20($s1)
/*  f003f88:	86220028 */ 	lh	$v0,0x28($s1)
.NB0f003f8c:
/*  f003f8c:	00570019 */ 	multu	$v0,$s7
/*  f003f90:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f003f94:	24010002 */ 	addiu	$at,$zero,0x2
/*  f003f98:	0000c812 */ 	mflo	$t9
/*  f003f9c:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f003fa0:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f003fa4:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f003fa8:	51400012 */ 	beqzl	$t2,.NB0f003ff4
/*  f003fac:	8602002a */ 	lh	$v0,0x2a($s0)
/*  f003fb0:	5461000a */ 	bnel	$v1,$at,.NB0f003fdc
/*  f003fb4:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f003fb8:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f003fbc:	8c44001c */ 	lw	$a0,0x1c($v0)
/*  f003fc0:	244500fc */ 	addiu	$a1,$v0,0xfc
/*  f003fc4:	0fc1a0f1 */ 	jal	func0f069144
/*  f003fc8:	9446018a */ 	lhu	$a2,0x18a($v0)
/*  f003fcc:	3c038006 */ 	lui	$v1,0x8006
/*  f003fd0:	10000007 */ 	beqz	$zero,.NB0f003ff0
/*  f003fd4:	8c63395c */ 	lw	$v1,0x395c($v1)
/*  f003fd8:	8e220004 */ 	lw	$v0,0x4($s1)
.NB0f003fdc:
/*  f003fdc:	3c038006 */ 	lui	$v1,0x8006
/*  f003fe0:	904b032e */ 	lbu	$t3,0x32e($v0)
/*  f003fe4:	356d0020 */ 	ori	$t5,$t3,0x20
/*  f003fe8:	a04d032e */ 	sb	$t5,0x32e($v0)
/*  f003fec:	8c63395c */ 	lw	$v1,0x395c($v1)
.NB0f003ff0:
/*  f003ff0:	8602002a */ 	lh	$v0,0x2a($s0)
.NB0f003ff4:
/*  f003ff4:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f003ff8:	16c2ffe4 */ 	bne	$s6,$v0,.NB0f003f8c
/*  f003ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f004000:	8e310020 */ 	lw	$s1,0x20($s1)
.NB0f004004:
/*  f004004:	5620ffd9 */ 	bnezl	$s1,.NB0f003f6c
/*  f004008:	922e0000 */ 	lbu	$t6,0x0($s1)
/*  f00400c:	240e000f */ 	addiu	$t6,$zero,0xf
.NB0f004010:
/*  f004010:	3c01800a */ 	lui	$at,0x800a
/*  f004014:	a02eeba1 */ 	sb	$t6,-0x145f($at)
.NB0f004018:
/*  f004018:	10600002 */ 	beqz	$v1,.NB0f004024
/*  f00401c:	3c018006 */ 	lui	$at,0x8006
/*  f004020:	ac20395c */ 	sw	$zero,0x395c($at)
.NB0f004024:
/*  f004024:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f004028:
/*  f004028:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f00402c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f004030:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f004034:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f004038:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f00403c:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f004040:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f004044:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f004048:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f00404c:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f004050:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f004054:	03e00008 */ 	jr	$ra
/*  f004058:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif

void lightsTick(void)
{
	struct hand *hand1 = &g_Vars.currentplayer->hands[0];
	struct hand *hand2 = &g_Vars.currentplayer->hands[1];

	func0f005bb0();

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
		if (g_Rooms[roomnum].flags & ROOMFLAG_VISIBLEBYPLAYER) {
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

GLOBAL_ASM(
glabel func0f004604
.late_rodata
glabel var7f1a7ddc
.word 0x3b808081
.text
/*  f004604:	3c06800a */ 	lui	$a2,%hi(g_Rooms)
/*  f004608:	000428c0 */ 	sll	$a1,$a0,0x3
/*  f00460c:	24c64928 */ 	addiu	$a2,$a2,%lo(g_Rooms)
/*  f004610:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f004614:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f004618:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f00461c:	00052880 */ 	sll	$a1,$a1,0x2
/*  f004620:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f004624:	00052880 */ 	sll	$a1,$a1,0x2
/*  f004628:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f00462c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f004630:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f004634:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f004638:	3c028008 */ 	lui	$v0,%hi(var8007fc3c)
/*  f00463c:	01c55821 */ 	addu	$t3,$t6,$a1
/*  f004640:	956f0056 */ 	lhu	$t7,0x56($t3)
/*  f004644:	9442fc3c */ 	lhu	$v0,%lo(var8007fc3c)($v0)
/*  f004648:	504f0183 */ 	beql	$v0,$t7,.L0f004c58
/*  f00464c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f004650:	85780002 */ 	lh	$t8,0x2($t3)
/*  f004654:	53000180 */ 	beqzl	$t8,.L0f004c58
/*  f004658:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f00465c:	a5620056 */ 	sh	$v0,0x56($t3)
/*  f004660:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f004664:	03255821 */ 	addu	$t3,$t9,$a1
/*  f004668:	95630000 */ 	lhu	$v1,0x0($t3)
/*  f00466c:	306e0040 */ 	andi	$t6,$v1,0x40
/*  f004670:	15c00002 */ 	bnez	$t6,.L0f00467c
/*  f004674:	346f0200 */ 	ori	$t7,$v1,0x200
/*  f004678:	a56f0000 */ 	sh	$t7,0x0($t3)
.L0f00467c:
/*  f00467c:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f004680:	0fc002c9 */ 	jal	func0f000b24
/*  f004684:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f004688:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f00468c:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f004690:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f004694:	305200ff */ 	andi	$s2,$v0,0xff
/*  f004698:	03197021 */ 	addu	$t6,$t8,$t9
/*  f00469c:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*  f0046a0:	85e40016 */ 	lh	$a0,0x16($t7)
/*  f0046a4:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0046a8:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0046ac:	3c07800a */ 	lui	$a3,%hi(g_Rooms)
/*  f0046b0:	24e74928 */ 	addiu	$a3,$a3,%lo(g_Rooms)
/*  f0046b4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0046b8:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0046bc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0046c0:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0046c4:	af220058 */ 	sw	$v0,0x58($t9)
/*  f0046c8:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0046cc:	01c65821 */ 	addu	$t3,$t6,$a2
/*  f0046d0:	8d630014 */ 	lw	$v1,0x14($t3)
/*  f0046d4:	856c0052 */ 	lh	$t4,0x52($t3)
/*  f0046d8:	846f0014 */ 	lh	$t7,0x14($v1)
/*  f0046dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0046e0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0046e4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0046e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0046ec:	03192021 */ 	addu	$a0,$t8,$t9
/*  f0046f0:	95780000 */ 	lhu	$t8,0x0($t3)
/*  f0046f4:	24840007 */ 	addiu	$a0,$a0,0x7
/*  f0046f8:	348e0007 */ 	ori	$t6,$a0,0x7
/*  f0046fc:	39cf0007 */ 	xori	$t7,$t6,0x7
/*  f004700:	33190080 */ 	andi	$t9,$t8,0x80
/*  f004704:	13200003 */ 	beqz	$t9,.L0f004714
/*  f004708:	01e02025 */ 	or	$a0,$t7,$zero
/*  f00470c:	10000151 */ 	b	.L0f004c54
/*  f004710:	ad6f0058 */ 	sw	$t7,0x58($t3)
.L0f004714:
/*  f004714:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f004718:	00008025 */ 	or	$s0,$zero,$zero
/*  f00471c:	00008825 */ 	or	$s1,$zero,$zero
/*  f004720:	19c0014c */ 	blez	$t6,.L0f004c54
/*  f004724:	00a05025 */ 	or	$t2,$a1,$zero
/*  f004728:	3c1f8007 */ 	lui	$ra,%hi(g_InCutscene)
/*  f00472c:	27ff0764 */ 	addiu	$ra,$ra,%lo(g_InCutscene)
/*  f004730:	00804825 */ 	or	$t1,$a0,$zero
.L0f004734:
/*  f004734:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f004738:	01e65821 */ 	addu	$t3,$t7,$a2
/*  f00473c:	8d780014 */ 	lw	$t8,0x14($t3)
/*  f004740:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f004744:	03317021 */ 	addu	$t6,$t9,$s1
/*  f004748:	91cf0006 */ 	lbu	$t7,0x6($t6)
/*  f00474c:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f004750:	1300003d */ 	beqz	$t8,.L0f004848
/*  f004754:	00000000 */ 	nop
/*  f004758:	91390000 */ 	lbu	$t9,0x0($t1)
/*  f00475c:	44923000 */ 	mtc1	$s2,$f6
/*  f004760:	3c017f1a */ 	lui	$at,%hi(var7f1a7ddc)
/*  f004764:	a1590000 */ 	sb	$t9,0x0($t2)
/*  f004768:	912e0001 */ 	lbu	$t6,0x1($t1)
/*  f00476c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f004770:	a14e0001 */ 	sb	$t6,0x1($t2)
/*  f004774:	912f0002 */ 	lbu	$t7,0x2($t1)
/*  f004778:	a14f0002 */ 	sb	$t7,0x2($t2)
/*  f00477c:	06410005 */ 	bgez	$s2,.L0f004794
/*  f004780:	c4247ddc */ 	lwc1	$f4,%lo(var7f1a7ddc)($at)
/*  f004784:	3c014f80 */ 	lui	$at,0x4f80
/*  f004788:	44815000 */ 	mtc1	$at,$f10
/*  f00478c:	00000000 */ 	nop
/*  f004790:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f004794:
/*  f004794:	91380003 */ 	lbu	$t8,0x3($t1)
/*  f004798:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f00479c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0047a0:	44989000 */ 	mtc1	$t8,$f18
/*  f0047a4:	07010004 */ 	bgez	$t8,.L0f0047b8
/*  f0047a8:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0047ac:	44815000 */ 	mtc1	$at,$f10
/*  f0047b0:	00000000 */ 	nop
/*  f0047b4:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0047b8:
/*  f0047b8:	46103102 */ 	mul.s	$f4,$f6,$f16
/*  f0047bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0047c0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0047c4:	4459f800 */ 	cfc1	$t9,$31
/*  f0047c8:	44cef800 */ 	ctc1	$t6,$31
/*  f0047cc:	00000000 */ 	nop
/*  f0047d0:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f0047d4:	444ef800 */ 	cfc1	$t6,$31
/*  f0047d8:	00000000 */ 	nop
/*  f0047dc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0047e0:	51c00013 */ 	beqzl	$t6,.L0f004830
/*  f0047e4:	440e4000 */ 	mfc1	$t6,$f8
/*  f0047e8:	44814000 */ 	mtc1	$at,$f8
/*  f0047ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0047f0:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f0047f4:	44cef800 */ 	ctc1	$t6,$31
/*  f0047f8:	00000000 */ 	nop
/*  f0047fc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f004800:	444ef800 */ 	cfc1	$t6,$31
/*  f004804:	00000000 */ 	nop
/*  f004808:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f00480c:	15c00005 */ 	bnez	$t6,.L0f004824
/*  f004810:	00000000 */ 	nop
/*  f004814:	440e4000 */ 	mfc1	$t6,$f8
/*  f004818:	3c018000 */ 	lui	$at,0x8000
/*  f00481c:	10000007 */ 	b	.L0f00483c
/*  f004820:	01c17025 */ 	or	$t6,$t6,$at
.L0f004824:
/*  f004824:	10000005 */ 	b	.L0f00483c
/*  f004828:	240effff */ 	addiu	$t6,$zero,-1
/*  f00482c:	440e4000 */ 	mfc1	$t6,$f8
.L0f004830:
/*  f004830:	00000000 */ 	nop
/*  f004834:	05c0fffb */ 	bltz	$t6,.L0f004824
/*  f004838:	00000000 */ 	nop
.L0f00483c:
/*  f00483c:	44d9f800 */ 	ctc1	$t9,$31
/*  f004840:	100000fe */ 	b	.L0f004c3c
/*  f004844:	a14e0003 */ 	sb	$t6,0x3($t2)
.L0f004848:
/*  f004848:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x284)
/*  f00484c:	8ce7a244 */ 	lw	$a3,%lo(g_Vars+0x284)($a3)
/*  f004850:	02406825 */ 	or	$t5,$s2,$zero
/*  f004854:	8ce800d8 */ 	lw	$t0,0xd8($a3)
/*  f004858:	15000013 */ 	bnez	$t0,.L0f0048a8
/*  f00485c:	00000000 */ 	nop
/*  f004860:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f004864:	15e00010 */ 	bnez	$t7,.L0f0048a8
/*  f004868:	00000000 */ 	nop
/*  f00486c:	8ce20480 */ 	lw	$v0,0x480($a3)
/*  f004870:	50400007 */ 	beqzl	$v0,.L0f004890
/*  f004874:	8cee1c54 */ 	lw	$t6,0x1c54($a3)
/*  f004878:	1040000b */ 	beqz	$v0,.L0f0048a8
/*  f00487c:	00000000 */ 	nop
/*  f004880:	80580037 */ 	lb	$t8,0x37($v0)
/*  f004884:	17000008 */ 	bnez	$t8,.L0f0048a8
/*  f004888:	00000000 */ 	nop
/*  f00488c:	8cee1c54 */ 	lw	$t6,0x1c54($a3)
.L0f004890:
/*  f004890:	8cf900c4 */ 	lw	$t9,0xc4($a3)
/*  f004894:	01c07827 */ 	nor	$t7,$t6,$zero
/*  f004898:	032fc024 */ 	and	$t8,$t9,$t7
/*  f00489c:	330e0001 */ 	andi	$t6,$t8,0x1
/*  f0048a0:	55c00016 */ 	bnezl	$t6,.L0f0048fc
/*  f0048a4:	91220001 */ 	lbu	$v0,0x1($t1)
.L0f0048a8:
/*  f0048a8:	5500002c */ 	bnezl	$t0,.L0f00495c
/*  f0048ac:	91260000 */ 	lbu	$a2,0x0($t1)
/*  f0048b0:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0048b4:	57200029 */ 	bnezl	$t9,.L0f00495c
/*  f0048b8:	91260000 */ 	lbu	$a2,0x0($t1)
/*  f0048bc:	8ce20480 */ 	lw	$v0,0x480($a3)
/*  f0048c0:	50400007 */ 	beqzl	$v0,.L0f0048e0
/*  f0048c4:	8cee1c54 */ 	lw	$t6,0x1c54($a3)
/*  f0048c8:	50400024 */ 	beqzl	$v0,.L0f00495c
/*  f0048cc:	91260000 */ 	lbu	$a2,0x0($t1)
/*  f0048d0:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f0048d4:	55e00021 */ 	bnezl	$t7,.L0f00495c
/*  f0048d8:	91260000 */ 	lbu	$a2,0x0($t1)
/*  f0048dc:	8cee1c54 */ 	lw	$t6,0x1c54($a3)
.L0f0048e0:
/*  f0048e0:	8cf800c4 */ 	lw	$t8,0xc4($a3)
/*  f0048e4:	01c0c827 */ 	nor	$t9,$t6,$zero
/*  f0048e8:	03197824 */ 	and	$t7,$t8,$t9
/*  f0048ec:	31ee0008 */ 	andi	$t6,$t7,0x8
/*  f0048f0:	51c0001a */ 	beqzl	$t6,.L0f00495c
/*  f0048f4:	91260000 */ 	lbu	$a2,0x0($t1)
/*  f0048f8:	91220001 */ 	lbu	$v0,0x1($t1)
.L0f0048fc:
/*  f0048fc:	91230000 */ 	lbu	$v1,0x0($t1)
/*  f004900:	0043082a */ 	slt	$at,$v0,$v1
/*  f004904:	5020000a */ 	beqzl	$at,.L0f004930
/*  f004908:	91230002 */ 	lbu	$v1,0x2($t1)
/*  f00490c:	91380002 */ 	lbu	$t8,0x2($t1)
/*  f004910:	00602025 */ 	or	$a0,$v1,$zero
/*  f004914:	00602825 */ 	or	$a1,$v1,$zero
/*  f004918:	0303082a */ 	slt	$at,$t8,$v1
/*  f00491c:	50200004 */ 	beqzl	$at,.L0f004930
/*  f004920:	91230002 */ 	lbu	$v1,0x2($t1)
/*  f004924:	1000000f */ 	b	.L0f004964
/*  f004928:	00603025 */ 	or	$a2,$v1,$zero
/*  f00492c:	91230002 */ 	lbu	$v1,0x2($t1)
.L0f004930:
/*  f004930:	0062082a */ 	slt	$at,$v1,$v0
/*  f004934:	10200003 */ 	beqz	$at,.L0f004944
/*  f004938:	00602025 */ 	or	$a0,$v1,$zero
/*  f00493c:	10000001 */ 	b	.L0f004944
/*  f004940:	00402025 */ 	or	$a0,$v0,$zero
.L0f004944:
/*  f004944:	00801025 */ 	or	$v0,$a0,$zero
/*  f004948:	00402025 */ 	or	$a0,$v0,$zero
/*  f00494c:	00402825 */ 	or	$a1,$v0,$zero
/*  f004950:	10000004 */ 	b	.L0f004964
/*  f004954:	00403025 */ 	or	$a2,$v0,$zero
/*  f004958:	91260000 */ 	lbu	$a2,0x0($t1)
.L0f00495c:
/*  f00495c:	91250001 */ 	lbu	$a1,0x1($t1)
/*  f004960:	91240002 */ 	lbu	$a0,0x2($t1)
.L0f004964:
/*  f004964:	91390003 */ 	lbu	$t9,0x3($t1)
/*  f004968:	00c5082a */ 	slt	$at,$a2,$a1
/*  f00496c:	00c01825 */ 	or	$v1,$a2,$zero
/*  f004970:	10200002 */ 	beqz	$at,.L0f00497c
/*  f004974:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f004978:	00a01825 */ 	or	$v1,$a1,$zero
.L0f00497c:
/*  f00497c:	0064082a */ 	slt	$at,$v1,$a0
/*  f004980:	44864000 */ 	mtc1	$a2,$f8
/*  f004984:	50200003 */ 	beqzl	$at,.L0f004994
/*  f004988:	01a3082a */ 	slt	$at,$t5,$v1
/*  f00498c:	00801825 */ 	or	$v1,$a0,$zero
/*  f004990:	01a3082a */ 	slt	$at,$t5,$v1
.L0f004994:
/*  f004994:	5020000d */ 	beqzl	$at,.L0f0049cc
/*  f004998:	44832000 */ 	mtc1	$v1,$f4
/*  f00499c:	44839000 */ 	mtc1	$v1,$f18
/*  f0049a0:	44925000 */ 	mtc1	$s2,$f10
/*  f0049a4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0049a8:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f0049ac:	06410004 */ 	bgez	$s2,.L0f0049c0
/*  f0049b0:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0049b4:	44818000 */ 	mtc1	$at,$f16
/*  f0049b8:	00000000 */ 	nop
/*  f0049bc:	46103180 */ 	add.s	$f6,$f6,$f16
.L0f0049c0:
/*  f0049c0:	10000005 */ 	b	.L0f0049d8
/*  f0049c4:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f0049c8:	44832000 */ 	mtc1	$v1,$f4
.L0f0049cc:
/*  f0049cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0049d0:	44810000 */ 	mtc1	$at,$f0
/*  f0049d4:	468020a0 */ 	cvt.s.w	$f2,$f4
.L0f0049d8:
/*  f0049d8:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0049dc:	44853000 */ 	mtc1	$a1,$f6
/*  f0049e0:	00000000 */ 	nop
/*  f0049e4:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0049e8:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f0049ec:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0049f0:	44845000 */ 	mtc1	$a0,$f10
/*  f0049f4:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0049f8:	440e8000 */ 	mfc1	$t6,$f16
/*  f0049fc:	00000000 */ 	nop
/*  f004a00:	afae0080 */ 	sw	$t6,0x80($sp)
/*  f004a04:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f004a08:	4600448d */ 	trunc.w.s	$f18,$f8
/*  f004a0c:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f004a10:	44199000 */ 	mfc1	$t9,$f18
/*  f004a14:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f004a18:	afb9007c */ 	sw	$t9,0x7c($sp)
/*  f004a1c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f004a20:	4600448d */ 	trunc.w.s	$f18,$f8
/*  f004a24:	440e2000 */ 	mfc1	$t6,$f4
/*  f004a28:	00000000 */ 	nop
/*  f004a2c:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f004a30:	8ce800d8 */ 	lw	$t0,0xd8($a3)
/*  f004a34:	44039000 */ 	mfc1	$v1,$f18
/*  f004a38:	15000013 */ 	bnez	$t0,.L0f004a88
/*  f004a3c:	00000000 */ 	nop
/*  f004a40:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f004a44:	17200010 */ 	bnez	$t9,.L0f004a88
/*  f004a48:	00000000 */ 	nop
/*  f004a4c:	8ce20480 */ 	lw	$v0,0x480($a3)
/*  f004a50:	50400007 */ 	beqzl	$v0,.L0f004a70
/*  f004a54:	8cf81c54 */ 	lw	$t8,0x1c54($a3)
/*  f004a58:	1040000b */ 	beqz	$v0,.L0f004a88
/*  f004a5c:	00000000 */ 	nop
/*  f004a60:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f004a64:	15e00008 */ 	bnez	$t7,.L0f004a88
/*  f004a68:	00000000 */ 	nop
/*  f004a6c:	8cf81c54 */ 	lw	$t8,0x1c54($a3)
.L0f004a70:
/*  f004a70:	8cee00c4 */ 	lw	$t6,0xc4($a3)
/*  f004a74:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f004a78:	01d97824 */ 	and	$t7,$t6,$t9
/*  f004a7c:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f004a80:	17000015 */ 	bnez	$t8,.L0f004ad8
/*  f004a84:	00000000 */ 	nop
.L0f004a88:
/*  f004a88:	55000016 */ 	bnezl	$t0,.L0f004ae4
/*  f004a8c:	01837821 */ 	addu	$t7,$t4,$v1
/*  f004a90:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f004a94:	55c00013 */ 	bnezl	$t6,.L0f004ae4
/*  f004a98:	01837821 */ 	addu	$t7,$t4,$v1
/*  f004a9c:	8ce20480 */ 	lw	$v0,0x480($a3)
/*  f004aa0:	50400007 */ 	beqzl	$v0,.L0f004ac0
/*  f004aa4:	8cf81c54 */ 	lw	$t8,0x1c54($a3)
/*  f004aa8:	5040000e */ 	beqzl	$v0,.L0f004ae4
/*  f004aac:	01837821 */ 	addu	$t7,$t4,$v1
/*  f004ab0:	80590037 */ 	lb	$t9,0x37($v0)
/*  f004ab4:	5720000b */ 	bnezl	$t9,.L0f004ae4
/*  f004ab8:	01837821 */ 	addu	$t7,$t4,$v1
/*  f004abc:	8cf81c54 */ 	lw	$t8,0x1c54($a3)
.L0f004ac0:
/*  f004ac0:	8cef00c4 */ 	lw	$t7,0xc4($a3)
/*  f004ac4:	03007027 */ 	nor	$t6,$t8,$zero
/*  f004ac8:	01eec824 */ 	and	$t9,$t7,$t6
/*  f004acc:	33380008 */ 	andi	$t8,$t9,0x8
/*  f004ad0:	53000004 */ 	beqzl	$t8,.L0f004ae4
/*  f004ad4:	01837821 */ 	addu	$t7,$t4,$v1
.L0f004ad8:
/*  f004ad8:	10000006 */ 	b	.L0f004af4
/*  f004adc:	00006025 */ 	or	$t4,$zero,$zero
/*  f004ae0:	01837821 */ 	addu	$t7,$t4,$v1
.L0f004ae4:
/*  f004ae4:	29e1011e */ 	slti	$at,$t7,0x11e
/*  f004ae8:	14200002 */ 	bnez	$at,.L0f004af4
/*  f004aec:	240e011d */ 	addiu	$t6,$zero,0x11d
/*  f004af0:	01c36023 */ 	subu	$t4,$t6,$v1
.L0f004af4:
/*  f004af4:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f004af8:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f004afc:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f004b00:	03387821 */ 	addu	$t7,$t9,$t8
/*  f004b04:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f004b08:	5720000c */ 	bnezl	$t9,.L0f004b3c
/*  f004b0c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f004b10:	44805000 */ 	mtc1	$zero,$f10
/*  f004b14:	c570005c */ 	lwc1	$f16,0x5c($t3)
/*  f004b18:	46105032 */ 	c.eq.s	$f10,$f16
/*  f004b1c:	00000000 */ 	nop
/*  f004b20:	45030006 */ 	bc1tl	.L0f004b3c
/*  f004b24:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f004b28:	95780000 */ 	lhu	$t8,0x0($t3)
/*  f004b2c:	330f2000 */ 	andi	$t7,$t8,0x2000
/*  f004b30:	51e0000b */ 	beqzl	$t7,.L0f004b60
/*  f004b34:	9578004e */ 	lhu	$t8,0x4e($t3)
/*  f004b38:	8fae0080 */ 	lw	$t6,0x80($sp)
.L0f004b3c:
/*  f004b3c:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f004b40:	01ccc821 */ 	addu	$t9,$t6,$t4
/*  f004b44:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f004b48:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f004b4c:	030c7821 */ 	addu	$t7,$t8,$t4
/*  f004b50:	01ccc821 */ 	addu	$t9,$t6,$t4
/*  f004b54:	afaf007c */ 	sw	$t7,0x7c($sp)
/*  f004b58:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f004b5c:	9578004e */ 	lhu	$t8,0x4e($t3)
.L0f004b60:
/*  f004b60:	24010005 */ 	addiu	$at,$zero,0x5
/*  f004b64:	00187b02 */ 	srl	$t7,$t8,0xc
/*  f004b68:	55e1000f */ 	bnel	$t7,$at,.L0f004ba8
/*  f004b6c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f004b70:	87a4009a */ 	lh	$a0,0x9a($sp)
/*  f004b74:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f004b78:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f004b7c:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f004b80:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f004b84:	afaa0040 */ 	sw	$t2,0x40($sp)
/*  f004b88:	0fc6192e */ 	jal	scenarioHighlightRoom
/*  f004b8c:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f004b90:	3c1f8007 */ 	lui	$ra,%hi(g_InCutscene)
/*  f004b94:	27ff0764 */ 	addiu	$ra,$ra,%lo(g_InCutscene)
/*  f004b98:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f004b9c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f004ba0:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f004ba4:	8fae0080 */ 	lw	$t6,0x80($sp)
.L0f004ba8:
/*  f004ba8:	29c10100 */ 	slti	$at,$t6,0x100
/*  f004bac:	14200002 */ 	bnez	$at,.L0f004bb8
/*  f004bb0:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f004bb4:	afb90080 */ 	sw	$t9,0x80($sp)
.L0f004bb8:
/*  f004bb8:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f004bbc:	2b010100 */ 	slti	$at,$t8,0x100
/*  f004bc0:	14200002 */ 	bnez	$at,.L0f004bcc
/*  f004bc4:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f004bc8:	afaf007c */ 	sw	$t7,0x7c($sp)
.L0f004bcc:
/*  f004bcc:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f004bd0:	29c10100 */ 	slti	$at,$t6,0x100
/*  f004bd4:	14200002 */ 	bnez	$at,.L0f004be0
/*  f004bd8:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f004bdc:	afb90078 */ 	sw	$t9,0x78($sp)
.L0f004be0:
/*  f004be0:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f004be4:	07030003 */ 	bgezl	$t8,.L0f004bf4
/*  f004be8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f004bec:	afa00080 */ 	sw	$zero,0x80($sp)
/*  f004bf0:	8faf007c */ 	lw	$t7,0x7c($sp)
.L0f004bf4:
/*  f004bf4:	05e30003 */ 	bgezl	$t7,.L0f004c04
/*  f004bf8:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f004bfc:	afa0007c */ 	sw	$zero,0x7c($sp)
/*  f004c00:	8fae0078 */ 	lw	$t6,0x78($sp)
.L0f004c04:
/*  f004c04:	05c30003 */ 	bgezl	$t6,.L0f004c14
/*  f004c08:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f004c0c:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f004c10:	8fb90080 */ 	lw	$t9,0x80($sp)
.L0f004c14:
/*  f004c14:	3c07800a */ 	lui	$a3,%hi(g_Rooms)
/*  f004c18:	24e74928 */ 	addiu	$a3,$a3,%lo(g_Rooms)
/*  f004c1c:	a1590000 */ 	sb	$t9,0x0($t2)
/*  f004c20:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f004c24:	a1580001 */ 	sb	$t8,0x1($t2)
/*  f004c28:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f004c2c:	a14f0002 */ 	sb	$t7,0x2($t2)
/*  f004c30:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f004c34:	a14e0003 */ 	sb	$t6,0x3($t2)
/*  f004c38:	8fa60048 */ 	lw	$a2,0x48($sp)
.L0f004c3c:
/*  f004c3c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f004c40:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f004c44:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f004c48:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f004c4c:	1619feb9 */ 	bne	$s0,$t9,.L0f004734
/*  f004c50:	25290004 */ 	addiu	$t1,$t1,0x4
.L0f004c54:
/*  f004c54:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f004c58:
/*  f004c58:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f004c5c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f004c60:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f004c64:	03e00008 */ 	jr	$ra
/*  f004c68:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

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
		var8009cad8[i] = portal0f0b656c(i) > 0.5f;

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

/**
 * This function:
 * - Controls the sound effects for the night vision and IR scanner.
 * - Sets g_IsSwitchingGoggles if equipping or unequipping NV/IR on this frame.
 * - Updates the player's usinggoggles property.
 */
void func0f005bb0(void)
{
	s32 brightness = func0f0009c0(g_Vars.currentplayer->prop->rooms[0]);

	if (((USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) && !g_Vars.currentplayer->usinggoggles)
			|| ((!USINGDEVICE(DEVICE_NIGHTVISION) && !USINGDEVICE(DEVICE_IRSCANNER)) && g_Vars.currentplayer->usinggoggles)) {
		g_IsSwitchingGoggles = true;
	}

	g_Vars.currentplayer->usinggoggles = USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER);

	if (USINGDEVICE(DEVICE_NIGHTVISION) && !lvIsPaused()) {
		// Play the goggle's hum sound
		if (g_Vars.currentplayer->nvhum == NULL) {
			sndStart(var80095200, SFX_0505, &g_Vars.currentplayer->nvhum, -1, -1, -1.0f, -1, -1);
		}

		if (brightness > 128) {
			// Room is too bright for night vision - play overload sound
			if (g_Vars.currentplayer->nvoverload == NULL) {
				sndStart(var80095200, SFX_01BE, &g_Vars.currentplayer->nvoverload, -1, -1, -1.0f, -1, -1);
			}
		} else {
			// Room is dark enough for night vision - stop overload sound if active
			if (g_Vars.currentplayer->nvoverload != NULL) {
				if (sndGetState(g_Vars.currentplayer->nvoverload) != AL_STOPPED) {
					audioStop(g_Vars.currentplayer->nvoverload);
				}
			}
		}
	} else {
		// Paused or not wearing night vision - stop both sounds
		if (g_Vars.currentplayer->nvhum != NULL) {
			if (sndGetState(g_Vars.currentplayer->nvhum) != NULL) {
				audioStop(g_Vars.currentplayer->nvhum);
			}
		}

		if (g_Vars.currentplayer->nvoverload != NULL) {
			if (sndGetState(g_Vars.currentplayer->nvoverload) != NULL) {
				audioStop(g_Vars.currentplayer->nvoverload);
			}
		}
	}
}
