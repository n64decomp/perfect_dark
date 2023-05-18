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


s32 *var8009cad0;
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
struct coord *var80061428 = NULL;
u16 **var8006142c = NULL;
u16 **var80061430 = NULL;
f32 *var80061434 = NULL;
bool *var80061438 = NULL;
f32 var8006143c = 50;
u32 var80061440 = 0x00000000;
bool g_IsSwitchingGoggles = false;

s32 var80061458 = 0x00000000;

Lights1 var80061460 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0x4d, 0x4d, 0x2e);

static void func0f0023b8(void);
static void func0f002844(s32 roomnum, f32 arg1, s32 arg2, s32 portalnum);
static void func0f00259c(s32 roomnum);
static void func0f00215c(u8 *arg0);
static void func0f003444(void);
static void func0f0035c0(void);
static void func0f00372c(void);
static void func0f0037ac(void);
static void func0f004558(s32 roomnum, s32 increment, s32 limit);
static void func0f00505c(void);
static void func0f004c6c(void);
static f32 func0f0053d0(s32 roomnum1, struct coord *pos1, s32 portalnum1, s32 roomnum2, struct coord *pos2, s32 portalnum2, f32 *arg6);
static void func0f005bb0(void);

static s32 func0f177a54(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3)
{
	s32 i = 0;
	s32 v1 = 0;
	s32 t0 = 0;

	for (; i < arg1; i++) {
		s32 index = i * arg3;

		if (arg0[index] != 0) {
			u8 *ptr = &arg0[index];

			if (i != 0 && ptr[-arg3] == 0) {
				arg2[v1++] = 0;

				if (t0 == 255) {
					arg2[v1++] = 200;
					arg2[v1++] = 0;
					t0 -= 200;
				} else {
					while (t0 > 255) {
						arg2[v1++] = 255;
						t0 -= 255;
					}
				}

				arg2[v1++] = t0;
				t0 = 0;
			}

			arg2[v1++] = arg0[index];
		} else {
			t0++;
		}
	}

	arg2[v1++] = 0;
	arg2[v1++] = 0;

	return v1;
}

static s32 func0f177c8c(u8 *arg0, s32 *arg1, s32 *arg2)
{
	s32 result;

	if (*arg1 == 0) {
		*arg2 = -1;
	}

	while (arg0[*arg1] == 0) {
		*arg1 += 1;

		if (arg0[*arg1]) {
			while (arg0[*arg1] == 255) {
				*arg2 += 255;
				*arg1 += 1;
			}

			*arg2 += arg0[*arg1];
			*arg1 += 1;
		} else {
			return -1;
		}
	}

	*arg2 += 1;

	result = arg0[*arg1];

	*arg1 += 1;

	return result;
}

static u32 func0f000920(s32 portalnum1, s32 portalnum2)
{
	if (portalnum1 != portalnum2) {
		s32 upper = (portalnum1 > portalnum2) ? portalnum1 : portalnum2;
		s32 lower = (portalnum1 < portalnum2) ? portalnum1 : portalnum2;

		return var80061430[upper][lower];
	}

	return 0;
}

static struct light *roomGetLight(s32 roomnum, s32 lightnum)
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

static void roomSetDefaults(struct room *room)
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

	gSPLookAtX(gdl++, &g_Vars.currentplayer->lookat->l[0]);
	gSPLookAtY(gdl++, &g_Vars.currentplayer->lookat->l[1]);

	return gdl;
}

Gfx *lightsSetDefault(Gfx *gdl)
{
	gSPSetLights1(gdl++, var80061460);

	gSPLookAtX(gdl++, &g_Vars.currentplayer->lookat->l[0]);
	gSPLookAtY(gdl++, &g_Vars.currentplayer->lookat->l[1]);

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

	g_Rooms[roomnum].unk4c = 50;

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
	func0f004c6c();
}

extern struct rend_vidat *g_ViBackData;

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

	var80061440 = 0;

	func0f0023b8();

	if (1);
	for (g_NumPortals = 0; g_BgPortals[g_NumPortals].verticesoffset != 0; g_NumPortals++);

	if (g_NumPortals == 0) {
		return;
	}

	table1size = ALIGN16(g_Vars.roomcount * 4);
	table2size = ALIGN16(g_NumPortals * 4);
	table3size = ALIGN16(g_Vars.roomcount * 4);
	table4size = ALIGN16((u32)var8009cae0 * (u32)var8009cae0);
	sp68 = ALIGN16(g_Vars.roomcount * 8);

	ptr = (void *) g_ViBackData->fb;

	var80061434 = (f32 *)ptr;
	ptr += table1size;

	var80061438 = (bool *)ptr;
	ptr += table2size;

	sp44 = (s32 *)(ptr);
	ptr += table3size;

	sp48 = (u8 *)ptr;
	ptr += table4size;

	s5 = (u8 *) mblurGetAllocation();

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
		table3size += ALIGN4(sp44[i]);
	}

	ptr = mempAlloc(ALIGN16(table3size), MEMPOOL_STAGE);

	sp68 += ALIGN16(table3size);

	sp54 = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		s32 size = ALIGN4(sp44[i]);

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

		table3size += ALIGN4(sp44[i]);
	}

	ptr = mempAlloc(ALIGN16(table3size), MEMPOOL_STAGE);

	for (i = 1; i < g_Vars.roomcount; i++) {
		var80061420[i].unk04 = ptr;

		ptr += ALIGN4(sp44[i]);

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
}

static f32 func0f002334(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2);

static void func0f00215c(u8 *arg0)
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

static void func0f0023b8(void)
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

static void func0f00259c(s32 roomnum)
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

static void func0f002844(s32 roomnum, f32 arg1, s32 arg2, s32 portalnum)
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

	var8009cae0 = ALIGN4(g_Vars.roomcount);
	var80061458 = 0;
	g_Vars.remakewallhitvtx = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		roomSetDefaults(&g_Rooms[i]);
		roomInitLights(i);
	}

	var80061420 = 0;
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

			func0f177164(&sp98, &spa4);

			spa4.x += sp80.x;
			spa4.y += sp80.y;
			spa4.z += sp80.z;

			func0f177164(&spa4, &spa4);

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

static void func0f003444(void)
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

static void func0f0035c0(void)
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

static void func0f00372c(void)
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

static void func0f0037ac(void)
{
	s32 i;
	s32 numprocessed = 0;
	s32 j;
	bool wasdirty = false;
	struct light *light;
	f32 amount;
	s32 v1;
	f32 angle;
	f32 average;
	u32 stack;

	if (cheatIsActive(CHEAT_PERFECTDARKNESS)) {
		func0f00372c();
	}

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

	func0f005bb0();

	if (hand1->flashon || hand2->flashon) {
		roomAdjustLighting(g_Vars.currentplayer->prop->rooms[0], 64, 80);
	}
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

static void func0f004558(s32 roomnum, s32 increment, s32 limit)
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
				if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
					tmpr = tmpg = tmpb = (src[i].r > src[i].g && src[i].r > src[i].b)
						? src[i].r
						: src[i].g > src[i].b ? src[i].g : src[i].b;
				} else {
					tmpr = src[i].r;
					tmpg = src[i].g;
					tmpb = src[i].b;
				}

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

				if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
					extra = 0;
				} else if (extra + max > 285) {
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

static void func0f004c6c(void)
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

	sp44 = ALIGN16(0x2000);
	sp40 = ALIGN16(g_NumPortals * 4);
	sp3c = ALIGN16(g_NumPortals * 0xc);
	sp38 = ALIGN16(g_NumPortals * 4);
	sp34 = ALIGN16(g_NumPortals * 2);

	for (i = 0, s4 = sp38; i < g_NumPortals; i++) {
		if (i != 0) {
			s4 += i * 2;
		}
	}

	s4 = ALIGN16(s4);
	ptr = mempAlloc(ALIGN16(s4), MEMPOOL_STAGE);
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

static void func0f00505c(void)
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

static f32 func0f0053d0(s32 roomnum1, struct coord *pos1, s32 portalnum1, s32 roomnum2, struct coord *pos2, s32 portalnum2, f32 *arg6)
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
	xdiff = absf(xdiff);

	if (xdiff < sp64) {
		zdiff = pos1->z - pos2->z;
		zdiff = absf(zdiff);

		if (zdiff < sp64) {
			ydiff = pos1->y - pos2->y;
			ydiff = absf(ydiff);

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
							xdiff2 = absf(xdiff2);

							if (xdiff2 < sp64) {
								zdiff2 = sp44.z - pos1->z;
								zdiff2 = absf(zdiff2);

								if (zdiff2 < sp64) {
									f32 sp38 = sqrtf(xdiff2 * xdiff2 + zdiff2 * zdiff2);

									if (sp38 < sp64) {
										struct coord sp2c;
										f32 xdiff3;
										f32 zdiff3;

										portalGetAvgVertexPos(portalnum2, &sp2c);
										sp64 -= sp38;

										xdiff3 = sp2c.x - pos2->x;
										xdiff3 = absf(xdiff3);

										if (xdiff3 < sp64) {
											zdiff3 = sp2c.z - pos2->z;
											zdiff3 = absf(zdiff3);

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

	if (PLAYERCOUNT() >= 3
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

/**
 * This function:
 * - Controls the sound effects for the night vision and IR scanner.
 * - Sets g_IsSwitchingGoggles if equipping or unequipping NV/IR on this frame.
 * - Updates the player's usinggoggles property.
 */
static void func0f005bb0(void)
{
	s32 brightness = func0f0009c0(g_Vars.currentplayer->prop->rooms[0]);

	if (((USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) && !g_Vars.currentplayer->usinggoggles)
			|| ((!USINGDEVICE(DEVICE_NIGHTVISION) && !USINGDEVICE(DEVICE_IRSCANNER)) && g_Vars.currentplayer->usinggoggles)) {
		g_IsSwitchingGoggles = true;
	}

	g_Vars.currentplayer->usinggoggles = USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER);

	if (USINGDEVICE(DEVICE_NIGHTVISION) && !g_LvIsPaused) {
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
