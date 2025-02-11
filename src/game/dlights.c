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
#include "game/zbuf.h"
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
u32 var8009cad4;
bool *g_PortalsNotGlassTmp;
s32 g_NumPortals;
s32 g_NumRooms;
s32 g_RecursionLimit;
f32 (*g_CalculateTransferHandler)(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2);
u8 g_GooglesRoomBrightness;
u8 g_GogglesObjColourIntensity;
u8 g_GogglesObjColourAlpha;
u8 g_GogglesChrColourIntensity;
u8 g_GogglesChrColourAlpha;

struct transfertableentry *g_LightTransferLookup = NULL;
bool var80061424 = false;
struct coord *g_PortalPositionsTmp = NULL;
u16 **g_PortalDistTableTmp = NULL;
u16 **g_PortalDistLookup = NULL;
f32 *g_RoomTransferTmp = NULL;
bool *g_PortalsOpenTmp = NULL;
f32 g_MinTransferAmount = 50;
s32 g_PortalTransmissionCount = 0;
bool g_PortalDistTableEnabled = true;
u32 var80061448 = 0x00000000;
bool g_IsSwitchingGoggles = false;
u32 var80061450 = 0x00000000;
u32 var80061454 = 0xffffffff;

#if VERSION >= VERSION_NTSC_1_0
s32 g_LightsPrevTickMode = 0;
#endif

void l2_build_transfer_table(u8 *arg0);
void lights_calculate_room_dimensions(void);
void l2_build_transfer_for_room(s32 roomnum);
void l2_build_transfer_through_portal(s32 roomnum, f32 arg1, s32 recursioncount, s32 portalnum);
void rooms_tick_lighting(void);
void room_flash_local_lighting(s32 roomnum, s32 increment, s32 limit);
void l3_build_portal_dist_lookup(void);
void l3_build_portal_dist_table(void);
void lights_update_goggle_sounds(void);

u32 portal_get_acoustic_distance_to_portal(s32 portalnum1, s32 portalnum2)
{
	if (portalnum1 != portalnum2) {
		s32 upper = (portalnum1 > portalnum2) ? portalnum1 : portalnum2;
		s32 lower = (portalnum1 < portalnum2) ? portalnum1 : portalnum2;

		return g_PortalDistLookup[upper][lower];
	}

	return 0;
}

struct light *room_get_light(s32 roomnum, s32 lightnum)
{
	return (struct light *)&g_BgLightsFileData[(g_Rooms[roomnum].lightindex + lightnum) * 0x22];
}

u8 room_get_final_brightness(s32 roomnum)
{
	s32 brightness = g_Rooms[roomnum].br_flash + g_Rooms[roomnum].br_settled_regional;

	if (brightness > 255) {
		brightness = 255;
	}

	if (brightness < 0) {
		brightness = 0;
	}

	return brightness;
}

u8 room_get_final_brightness_for_player(s32 roomnum)
{
	s32 brightness = g_Rooms[roomnum].br_flash;

	if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
		brightness += g_GooglesRoomBrightness;
	} else {
		brightness += g_Rooms[roomnum].br_settled_regional;
	}

	if (brightness > 255) {
		brightness = 255;
	}

	if (brightness < 0) {
		brightness = 0;
	}

	return brightness;
}

u8 room_get_max_possible_brightness(s32 arg0)
{
	return 255;
}

u8 room_get_settled_regional_brightness_for_player(s32 roomnum)
{
	u32 brightness;

	if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
		return g_GooglesRoomBrightness;
	}

	if (g_Rooms[roomnum].flags & ROOMFLAG_BRIGHTNESS_CALCED) {
		brightness = g_Rooms[roomnum].br_settled_regional;
	} else {
		brightness = 255;
	}

	return brightness;
}

u8 room_get_settled_local_brightness(s32 room)
{
	return g_Rooms[room].br_settled_local & 0xff;
}

s32 room_get_flash_brightness(s32 roomnum)
{
	if (g_Rooms[roomnum].br_flash > 255) {
		return 255;
	}

	if (g_Rooms[roomnum].br_flash < 0) {
		return 0;
	}

	return (g_Rooms[roomnum].flags & ROOMFLAG_BRIGHTNESS_CALCED) ? g_Rooms[roomnum].br_flash : 0;
}

f32 room_get_light_op_cur_frac(s32 roomnum)
{
	return g_Rooms[roomnum].lightop_cur_frac;
}

f32 room_get_final_brightness_frac(s32 roomnum)
{
	f32 frac = (g_Rooms[roomnum].br_flash + g_Rooms[roomnum].br_settled_regional) / (1.0f / 255.0f);

	if (frac > 1) {
		frac = 1;
	}

	if (frac < 0) {
		frac = 0;
	}

	return frac;
}

f32 room_get_settled_regional_brightness_frac(s32 roomnum)
{
	return g_Rooms[roomnum].br_settled_regional / 255.0f;
}

f32 room_get_settled_local_brightness_frac(s32 roomnum)
{
	return g_Rooms[roomnum].br_settled_local / 255.0f;
}

/**
 * The resulting position is not a world position. It is relative to the room.
 */
bool light_get_bbox_centre(s32 roomnum, u32 lightnum, struct coord *pos)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	s32 i;
	light += lightnum;

	pos->x = 0;
	pos->y = 0;
	pos->z = 0;

	for (i = 0; i < ARRAYCOUNT(light->bbox); i++) {
		pos->x += light->bbox[i].x;
		pos->y += light->bbox[i].y;
		pos->z += light->bbox[i].z;
	}

	pos->x *= 0.25f;
	pos->y *= 0.25f;
	pos->z *= 0.25f;

	return true;
}

bool light_is_healthy(s32 roomnum, s32 lightnum)
{
	bool healthy;

	if (roomnum && room_get_light(roomnum, lightnum)->healthy) {
		healthy = true;
	} else {
		healthy = false;
	}

	return healthy;
}

bool light_is_vulnerable(s32 roomnum, s32 lightnum)
{
	struct light *light = room_get_light(roomnum, lightnum);

	return light->vulnerable;
}

bool light_is_on(s32 roomnum, s32 lightnum)
{
	bool on;

	if (roomnum && room_get_light(roomnum, lightnum)->on) {
		on = true;
	} else {
		on = false;
	}

	return on;
}

void room_set_flash_brightness(s32 roomnum, s32 value)
{
	g_Rooms[roomnum].br_flash = value;
}

void light_get_direction(s32 roomnum, u32 lightnum, struct coord *dir)
{
	struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].lightindex * 0x22];
	light += lightnum;

	dir->x = light->dirx;
	dir->y = light->diry;
	dir->z = light->dirz;
}

/**
 * Unused function.
 *
 * The use of var80061424 makes sense if the function was able to call itself
 * recursively and skip a part when recursing.
 */
void lights_do_nothing_useful(void)
{
	if (var80061424) {
		var80061424 = false;
	}

	var80061424 = true;
}

void room_set_defaults(struct room *room)
{
	room->br_light_min = 0;
	room->br_light_max = 255;
	room->br_light_each = 0;
	room->br_settled_local = 128;
	room->br_flash = 0;
	room->br_settled_regional = 0;
	room->lightop = LIGHTOP_NONE;
	room->flags &= ~(ROOMFLAG_BRIGHTNESS_DIRTY_PERM | ROOMFLAG_LIGHTS_DIRTY | ROOMFLAG_RENDERALWAYS | ROOMFLAG_BRIGHTNESS_CALCED);
	room->volume = 1;
	room->surfacearea = 1;
	room->lightop_cur_frac = 1;
	room->lightop_to_frac = 0;
	room->lightop_from_frac = 0;
	room->lightop_duration240 = 0;
}

Gfx *lights_set_for_room(Gfx *gdl, RoomNum roomnum)
{
	Lights1 *lights = gfx_allocate(sizeof(Lights1));

	u8 brightness = room_get_final_brightness_for_player(roomnum);
	u8 a0 = (u32)(brightness * 0.5882353f);

	lights->a.l.col[0] = a0;
	lights->a.l.col[1] = a0;
	lights->a.l.col[2] = a0;
	lights->a.l.colc[0] = a0;
	lights->a.l.colc[1] = a0;
	lights->a.l.colc[2] = a0;

	lights->l[0].l.col[0] = brightness;
	lights->l[0].l.col[1] = brightness;
	lights->l[0].l.col[2] = brightness;
	lights->l[0].l.colc[0] = brightness;
	lights->l[0].l.colc[1] = brightness;
	lights->l[0].l.colc[2] = brightness;
	lights->l[0].l.dir[0] = 0x4d;
	lights->l[0].l.dir[1] = 0x4d;
	lights->l[0].l.dir[2] = 0x2e;

	gSPSetLights1(gdl++, (*lights));

	gSPLookAtX(gdl++, &cam_get_look_at()->l[0]);
	gSPLookAtY(gdl++, &cam_get_look_at()->l[1]);

	return gdl;
}

Gfx *lights_set_default(Gfx *gdl)
{
	static Lights1 var80061460 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0x4d, 0x4d, 0x2e);

	gSPSetLights1(gdl++, var80061460);

	gSPLookAtX(gdl++, &cam_get_look_at()->l[0]);
	gSPLookAtY(gdl++, &cam_get_look_at()->l[1]);

	return gdl;
}

void room_init_lights(s32 roomnum)
{
	struct room *room = &g_Rooms[roomnum];
	struct light *light;
	s32 i;

	bg_get_room_brightness_range(roomnum, &room->br_light_min, &room->br_light_max);

	room->br_light_min = room->br_light_min / 4;

	if (room->numlights) {
		room->br_light_each = (f32)(room->br_light_max - room->br_light_min) / (f32)room->numlights;
	} else {
		room->br_light_each = 0;
	}

	if (room->br_light_min > 255) {
		room->br_light_min = 255;
	}

	if (room->br_light_max > 255) {
		room->br_light_max = 255;
	}

	room->br_base = room->br_light_min;

	if (room->numlights == 0) {
		room->br_base += (room->br_light_max - room->br_light_min) * 4 / 5;
	}

	switch (g_Vars.stagenum) {
	case STAGE_EXTRACTION:
	case STAGE_DEFECTION:
		if (roomnum == 0x003d) { // near the top comms hub
			room->br_base = 2;
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

	room->flags |= ROOMFLAG_LIGHTS_DIRTY;

#if VERSION < VERSION_NTSC_1_0
	if (cheat_is_active(CHEAT_PERFECTDARKNESS) && (room->flags & ROOMFLAG_RENDERALWAYS) == 0) {
		room->lightop = LIGHTOP_SET;
		room->lightop_to_frac = 0.0f;
	}
#endif

	light = (struct light *)&g_BgLightsFileData[(u32)g_Rooms[roomnum].lightindex * 0x22];

	for (i = 0; i < room->numlights; i++) {
#if VERSION < VERSION_NTSC_1_0
		if (cheat_is_active(CHEAT_PERFECTDARKNESS)) {
			light->brightness = 0;
			light->sparkable = (random() % 2) ? true : false;
			light->healthy = false;
			light->on = false;
			light->sparking = false;
			light->vulnerable = false;
		} else
#endif
		{
			light->brightness = g_Rooms[roomnum].br_light_each;
			light->sparkable = true;
			light->healthy = true;
			light->on = true;
			light->sparking = false;
			light->vulnerable = true;

			switch (g_Vars.stagenum) {
			case STAGE_CITRAINING:
			case STAGE_DEFENSE:
				if (roomnum == ROOM_DISH_FIRINGRANGE) {
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

bool lights_handle_hit(struct coord *gunpos, struct coord *hitpos, s32 roomnum)
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
			if (func0002f490(&light->bbox[0], &light->bbox[1], &light->bbox[3], NULL, &spa4, &sp98, &sp8c, 0, 0)
					|| func0002f490(&light->bbox[1], &light->bbox[2], &light->bbox[3], NULL, &spa4, &sp98, &sp8c, 0, 0)) {
				struct coord soundpos;

				soundpos.x = light->bbox[0].x;
				soundpos.y = light->bbox[0].y;
				soundpos.z = light->bbox[0].z;

				room_set_light_broken(roomnum, i);
				ps_create(0, 0, SFXMAP_8077_HIT_GLASS, -1, -1, PSFLAG_AMBIENT, 0, PSTYPE_NONE, &soundpos, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
				return true;
			}
		}

		light++;
	}

	return false;
}

void room_set_lights_faulty(s32 roomnum, s32 chance)
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
	g_Rooms[roomnum].br_base = 50;
#else
	g_Rooms[roomnum].br_base = 15;
#endif

	g_Rooms[roomnum].flags |= ROOMFLAG_LIGHTS_DIRTY;
}

void room_set_light_broken(s32 roomnum, s32 lightnum)
{
	struct light *light = room_get_light(roomnum, lightnum);
	light->healthy = false;
	light->on = false;

	osSyncPrintf("LIGHTS : Hit occured on light %d in room %d\n", lightnum, roomnum);

	g_Rooms[roomnum].flags |= ROOMFLAG_LIGHTS_DIRTY;
}

/**
 * lights_reset_3 is called after BG is loaded, after lights_reset_2 and after
 * portals have been reset.
 *
 * It handles building the portal distance lookup table. This is a table of
 * distances between every combination of portals, where the distance are routed
 * through rooms and portals.
 */
void lights_reset_3(void)
{
	if (g_PortalDistTableEnabled) {
		l3_build_portal_dist_lookup();
	}
}

/**
 * lights_reset_2 is called after BG is loaded, but before portals have been reset.
 *
 * The purpose of this function is to allocate and populate g_LightTransferLookup,
 * which is a table of how much each room emits light into another rooms,
 * so that when lights are shot out or turned off the nearby rooms can be
 * darked appropriately. This is all based on the volume and surface area of
 * each room, as well as the size of the portals (doorways) between each room.
 *
 * To calculate this, temporary tables are allocated out the z-buffer.
 */
void lights_reset_2(void)
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

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2 -> BUILD LIGHTS TRANSFER TABLE - Starting\n");

	osGetCount();

	g_PortalTransmissionCount = 0;

	lights_calculate_room_dimensions();

	if (1);
	for (g_NumPortals = 0; g_BgPortals[g_NumPortals].verticesoffset != 0; g_NumPortals++);

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2_BuildTransferTables -> Found %d portals\n", g_NumPortals);

	if (g_NumPortals == 0) {
		return;
	}

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2_BuildTransferTables -> Found %d rooms\n", g_NumRooms);

	table1size = align16(sizeof(g_RoomTransferTmp[0]) * g_Vars.roomcount);
	table2size = align16(sizeof(g_PortalsOpenTmp[0]) * g_NumPortals);
	table3size = align16(sizeof(sp44[0]) * g_Vars.roomcount);
	table4size = align16(sizeof(sp48[0]) * g_NumRooms * g_NumRooms);
	sp68 = align16(sizeof(g_LightTransferLookup[0]) * g_Vars.roomcount);

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2_BuildTransferTables -> Alloc %u bytes of free memory\n", memp_get_stage_free());

	/**
	 * This lighting initialisation needs to build temporary tables in memory.
	 * The memp system allows freeing of the most recent allocation *only*,
	 * so it's not easy to build these tables and dispose of them afterwards.
	 *
	 * Instead of using memp, it uses the z-buffer as a temporary scratch space.
	 * This is safe because there are no RDP tasks in progress at this point.
	 * The game waits for them to complete before loading the stage.
	 *
	 * Note that for some stages the z-buffer allocation must be higher than the
	 * lo-res size to support the lighting needs here.
	 */
	ptr = zbuf_get_allocation();

	g_RoomTransferTmp = (f32 *)ptr;
	ptr += table1size;

	g_PortalsOpenTmp = (bool *)ptr;
	ptr += table2size;

	sp44 = (s32 *)ptr;
	ptr += table3size;

	sp48 = (u8 *)ptr;
	ptr += table4size;

	s5 = (u8 *)ptr;

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2_BuildTransferTables -> Alloc %u bytes for scratch\n", sp68);

	g_LightTransferLookup = memp_alloc(sp68, MEMPOOL_STAGE);

	for (i = 0; i < g_NumPortals; i++) {
		if (PORTAL_IS_CLOSED(i)) {
			g_PortalsOpenTmp[i] = false;
		} else {
			g_PortalsOpenTmp[i] = true;
			if (1);
		}
	}

	if (g_Vars.stagenum == STAGE_EXTRACTION || g_Vars.stagenum == STAGE_DEFECTION) {
		g_PortalsOpenTmp[98] = false;
		g_PortalsOpenTmp[100] = false;
	}

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2 -> Building room based light transmission table\n");

	l2_build_transfer_table(sp48);

	// Do horizontal stuff
	for (i = 1, table3size = 0; i < g_Vars.roomcount; i++) {
		sp44[i] = func0f177a54((void *)(i * g_NumRooms + sp48), g_Vars.roomcount, (void *)(&s5[i * g_NumRooms]), 1);
		table3size += align4(sp44[i]);
	}

	ptr = memp_alloc(align16(table3size), MEMPOOL_STAGE);

	sp68 += align16(table3size);

	sp54 = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		s32 size = align4(sp44[i]);

		g_LightTransferLookup[i].horizontal = ptr;

		ptr += size;
		sp54 += size;

		for (j = 0; j < sp44[i]; j++) {
			g_LightTransferLookup[i].horizontal[j] = *(&s5[i * g_NumRooms] + j);
		}
	}

	table3size = 0;

	// Do vertical stuff
	for (i = 1; i < g_Vars.roomcount; i++) {
		sp44[i] = func0f177a54((void *)(sp48 + i), g_Vars.roomcount, (void *)(&s5[i * g_NumRooms]), g_NumRooms);

		table3size += align4(sp44[i]);
	}

	ptr = memp_alloc(align16(table3size), MEMPOOL_STAGE);

	sp68 += align16(table3size);

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_LightTransferLookup[i].vertical = ptr;

		ptr += align4(sp44[i]);

		for (j = 0; j < sp44[i]; j++) {
			g_LightTransferLookup[i].vertical[j] = *(&s5[i * g_NumRooms] + j);
		}
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags |= ROOMFLAG_ONSCREEN;
	}

	lighting_tick();

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_ONSCREEN;
	}

	osGetCount();

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2 -> Finished\n");
}

f32 l2_calculate_room_transfer(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2);

/**
 * dst is effectively a square grid with dimensions roomcount * roomcount.
 *
 * For each room, calculate how much that room transfers light into every other
 * room and write this to dst.
 *
 * Where the transfer between rooms A -> B and B -> A are different,
 * use the smallest of the two.
 *
 * The resulting grid should be diagonally mirrored.
 */
void l2_build_transfer_table(u8 *dst)
{
	s32 i;
	s32 j;

	g_CalculateTransferHandler = l2_calculate_room_transfer;

	g_MinTransferAmount = 50;
	g_RecursionLimit = 20;
	g_PortalTransmissionCount = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		u8 *dstptr = &dst[i * g_NumRooms];

		l2_build_transfer_for_room(i); // populates g_RoomTransferTmp

		for (j = 0; j < 1; j++) {
			dstptr[j] = 0;
		}

		for (j = 1; j < g_Vars.roomcount; j++) {
			if (g_RoomTransferTmp[i] < g_RoomTransferTmp[j]) {
				g_RoomTransferTmp[j] = g_RoomTransferTmp[i];
			}

			dstptr[j] = g_RoomTransferTmp[j];
		}
	}
}

/**
 * Both portalnums are portals for the given room.
 *
 * Light is coming into the room through portal 1, is being absorbed
 * evenly by the room's surface area and is exiting via portal 2.
 *
 * Calculate the fraction of light being transferred out.
 * This is portal 2's surface area as a percentage of the total surface area
 * excluding portal 1's surface area.
 */
f32 l2_calculate_room_transfer(s32 roomnum, f32 mult, s32 portalnum1, s32 portalnum2)
{
	f32 portal1surfacearea = 0;
	f32 result;

	if (portalnum1 != -1) {
		portal1surfacearea = bg_calculate_portal_surface_area(portalnum1);
	}

	result = (bg_calculate_portal_surface_area(portalnum2) / (g_Rooms[roomnum].surfacearea - portal1surfacearea)) * mult;
	return result;
}

void lights_calculate_room_dimensions(void)
{
	s32 i;
	s32 j;

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2 -> Generating room parameters from BG data\n");

	for (i = 0; i < g_Vars.roomcount; i++) {
		bool valid = true;

		g_Rooms[i].volume = 1.0f;
		g_Rooms[i].surfacearea = 1.0f;

		for (j = 0; j < 3; j++) {
			f32 diff = g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j];

			if (diff > 0.0f) {
				g_Rooms[i].volume *= (g_Rooms[i].bbmax[j] - g_Rooms[i].bbmin[j]) / 100.0f;
			} else {
				osSyncPrintf("L2(%d) -> ", __LINE__);
				osSyncPrintf("L2 -> Light2_ProcessBgParams room %d does not have a 3D bounding box => Room Volume is bodged!\n", i);
				valid = false;
			}
		}

		g_Rooms[i].volume += 1.0f;

		if (g_Rooms[i].volume > 60.0f) {
			g_Rooms[i].volume = 60.0f;
		}

		if (valid) {
			f32 xdiff = g_Rooms[i].bbmax[0] - g_Rooms[i].bbmin[0];
			f32 ydiff = g_Rooms[i].bbmax[1] - g_Rooms[i].bbmin[1];
			f32 zdiff = g_Rooms[i].bbmax[2] - g_Rooms[i].bbmin[2];

			xdiff = xdiff > 0 ? xdiff : -xdiff;
			ydiff = ydiff > 0 ? ydiff : -ydiff;
			zdiff = zdiff > 0 ? zdiff : -zdiff;

			g_Rooms[i].surfacearea = 2.0f * (xdiff * ydiff + xdiff * zdiff + ydiff * zdiff);
		} else {
			g_Rooms[i].surfacearea = 20000000.0f;
			osSyncPrintf("L2(%d) -> ", __LINE__);
			osSyncPrintf("%s%sL2 -> Surface area bodged for room %d - using %f\n", "", "", i, g_Rooms[i].surfacearea);
		}
	}

	osSyncPrintf("L2(%d) -> ", __LINE__);
	osSyncPrintf("L2 -> Finished\n");
}

/**
 * Given roomnum, calculate how much light can be transferred from this room
 * into every other room and write the amounts to g_RoomTransferTmp.
 *
 * g_RoomTransferTmp is a pointer to an array with {roomcount} elements.
 */
void l2_build_transfer_for_room(s32 roomnum)
{
	s32 i;
	f32 wallsurfaceareafrac;
	f32 portalsurfacearea = 0.0f;

	// Reset the array
	for (i = 0; i < g_Vars.roomcount; i++) {
		g_RoomTransferTmp[i] = 0.0f;
	}

	// Write the light value into the given room's slot
	g_RoomTransferTmp[roomnum] = sqrtf(g_Rooms[roomnum].volume) * 255.0f;
	if (1);

	// Iterate portals recursively and calculate the transfers into the other slots.
	// This updates other slots in g_RoomTransferTmp.
	if (g_Rooms[roomnum].numportals != 0) {
		l2_build_transfer_through_portal(roomnum, g_RoomTransferTmp[roomnum], 0, -1);
		if (1);
		if (1);
	}

	// Calculate how much of the given room's surface area is walls or other
	// solid surfaces, as opposed to portals which let light out.
	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		portalsurfacearea += bg_calculate_portal_surface_area(g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i]);
	}

	wallsurfaceareafrac = (g_Rooms[roomnum].surfacearea - portalsurfacearea) / g_Rooms[roomnum].surfacearea;

	// Presumably this is normalising each room's transfer values based on the room's volume
	for (i = 1; i < g_Vars.roomcount; i++) {
		g_RoomTransferTmp[i] *= 3.0f / sqrtf(g_Rooms[i].volume);
	}

	if (g_RoomTransferTmp[roomnum] > 255.0f) {
		g_RoomTransferTmp[roomnum] = 255.0f;
	}

	// Edge case: If the room is almost entirely made up of portals, fudge some values.
	// Maybe to avoid a divide by zero error somewhere?
	if (wallsurfaceareafrac < 0.1f) {
		g_Rooms[roomnum].br_light_min = g_Rooms[roomnum].br_light_max >> 1;
		g_RoomTransferTmp[roomnum] = g_Rooms[roomnum].br_light_max;
	}
}

/**
 * Recursively iterate each room's neighbours and calculate how much light can
 * be transferred into each. Write results to g_RoomTransferTmp.
 */
void l2_build_transfer_through_portal(s32 roomnum, f32 mult, s32 recursioncount, s32 portalnum)
{
	s32 i;
	s32 otherroomnum = -1;

	g_PortalTransmissionCount++;

	if (portalnum != -1) {
		if (roomnum == g_BgPortals[portalnum].roomnum1) {
			otherroomnum = g_BgPortals[portalnum].roomnum2;
		} else {
			otherroomnum = g_BgPortals[portalnum].roomnum1;
		}
	}

	for (i = 0; i < g_Rooms[roomnum].numportals; i++) {
		s32 iterportalnum = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + i];
		s32 iterroomnum;

		if (g_PortalsOpenTmp[iterportalnum]) {
			if (roomnum == g_BgPortals[iterportalnum].roomnum1) {
				iterroomnum = g_BgPortals[iterportalnum].roomnum2;
			} else {
				iterroomnum = g_BgPortals[iterportalnum].roomnum1;
			}

			if (iterroomnum != otherroomnum) {
				f32 amount = g_CalculateTransferHandler(roomnum, mult, portalnum, iterportalnum);

				if (amount > g_MinTransferAmount && recursioncount < g_RecursionLimit) {
					g_RoomTransferTmp[roomnum] -= amount;
					g_RoomTransferTmp[iterroomnum] += amount;

					if (g_RoomTransferTmp[roomnum] < 0.0f) {
						g_RoomTransferTmp[roomnum] = 0.0f;
					}

					l2_build_transfer_through_portal(iterroomnum, amount, recursioncount + 1, iterportalnum);
				}
			}
		}
	}
}

void lights_reset_1(void)
{
	s32 i;

	g_NumRooms = align4(g_Vars.roomcount);
#if VERSION >= VERSION_NTSC_1_0
	g_LightsPrevTickMode = 0;
#endif
	g_Vars.remakewallhitvtx = 0;

	for (i = 1; i < g_Vars.roomcount; i++) {
		room_set_defaults(&g_Rooms[i]);
		room_init_lights(i);
	}

	g_LightTransferLookup = NULL;

	if (IS4MB()) {
		g_PortalDistTableEnabled = false;
	}
}

void room_set_lights_on(s32 roomnum, s32 enable)
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

	g_Rooms[roomnum].flags |= ROOMFLAG_LIGHTS_DIRTY;
}

/**
 * @bug: The lightop_timer240 values are not set correctly.
 * They should be duration60 * 4. This only affects LIGHTOP_TRANSITION,
 * which makes it start the transition 3/4 of the way into it.
 */
void room_set_light_op(s32 roomnum, s32 operation, u8 br_to, u8 br_from, u8 duration60)
{
	if (cheat_is_active(CHEAT_PERFECTDARKNESS) == false) {
		g_Rooms[roomnum].lightop = operation;

		switch (operation) {
		case LIGHTOP_SET:
			g_Rooms[roomnum].lightop_to_frac = br_to * 0.01f;
			break;
		case LIGHTOP_SETRANDOM:
			g_Rooms[roomnum].lightop_to_frac = br_to;
			g_Rooms[roomnum].lightop_from_frac = br_from * 0.01f;
			g_Rooms[roomnum].lightop_duration240 = duration60 * 4.0f;
			g_Rooms[roomnum].lightop_timer240 = duration60;
			break;
		case LIGHTOP_TRANSITION:
			g_Rooms[roomnum].lightop_to_frac = br_to * 0.01f;
			g_Rooms[roomnum].lightop_from_frac = br_from * 0.01f;
			g_Rooms[roomnum].lightop_duration240 = duration60 * 4.0f;
			g_Rooms[roomnum].lightop_timer240 = duration60;
			break;
		case LIGHTOP_SINELOOP:
			g_Rooms[roomnum].lightop_to_frac = br_to * 0.01f;
			g_Rooms[roomnum].lightop_from_frac = br_from * 0.01f;
			g_Rooms[roomnum].lightop_duration240 = duration60 * 4.0f;
			g_Rooms[roomnum].lightop_timer240 = 0;
			break;
		case LIGHTOP_HIGHLIGHT:
			break;
		}
	}
}

bool light_tick_broken(s32 roomnum, s32 lightnum)
{
	struct light *light = (struct light *)(g_BgLightsFileData + ((g_Rooms[roomnum].lightindex + lightnum) * 0x22));

	if (!light->sparkable) {
		return false;
	}

	if (light->sparking) {
		if ((random() % 8) == 0) {
			light->sparking = false;
		} else if ((random() % 2) == 0) {
			struct coord spc8;
			struct coord spbc;
			struct coord spb0;
			struct coord spa4;
			struct coord sp98;
			struct coord sp8c;
			struct coord sp80;
			struct coord centre;
			f32 rand1 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
			f32 rand2 = 2.0f * RANDOMFRAC() - 1.0f; // range -1 to 1
			s32 sparktype = -1;
			RoomNum smokerooms[2];
			struct bgroom *room;

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

			sp8c.x = light->dirx;
			sp8c.y = light->diry;
			sp8c.z = light->dirz;

			sp80.x = -sp8c.x;
			sp80.y = -sp8c.y;
			sp80.z = -sp8c.z;

			func0f177164(&sp98, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1546 : 1570, "dlights.c");

			spa4.x += sp80.x;
			spa4.y += sp80.y;
			spa4.z += sp80.z;

			func0f177164(&spa4, &spa4, VERSION >= VERSION_NTSC_1_0 ? 1548 : 1572, "dlights.c");

			room = (void *) (roomnum * sizeof(struct bgroom));

			switch (random() % 4) {
			case 0:
				if (roomnum && roomnum && roomnum);
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

			light_get_bbox_centre(roomnum, lightnum, &centre);

			room = (void *) ((u8 *) g_BgRooms + (u32) room);
			centre.x += room->pos.x;
			centre.y += room->pos.y;
			centre.z += room->pos.z;

			sparks_create(roomnum, NULL, &centre, &spa4, &sp8c, sparktype);

			if ((random() % 4) == 0) {
				smokerooms[0] = roomnum;
				smokerooms[1] = -1;

				smoke_create_simple(&centre, smokerooms, SMOKETYPE_BULLETIMPACT);
			}

			room_flash_lighting(roomnum, 64, 80);
			ps_create(NULL, NULL, ps_get_random_spark_sound(), -1, -1, PSFLAG_AMBIENT, 0, PSTYPE_FOOTSTEP, &centre, -1.0f, 0, roomnum, -1.0f, -1.0f, -1.0f);
			return true;
		}
	} else {
		if ((random() % 80) == 0) {
			light->sparking = true;
		}
	}

	return false;
}

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

void lighting_tick(void)
{
	s32 i;

	rooms_tick_lighting();

	if (g_Vars.remakewallhitvtx) {
		wallhits_recolour();

		g_Vars.remakewallhitvtx = false;

		for (i = 1; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags &= ~ROOMFLAG_NEEDRESHADE;
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void lights_configure_for_perfect_darkness_cutscene(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < g_Vars.roomcount; i++) {
		struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];
		g_Rooms[i].lightop = LIGHTOP_SET;
		g_Rooms[i].lightop_to_frac = 0.5f;

		for (j = 0; j < g_Rooms[i].numlights; j++) {
			light->sparkable = random() % 2 ? true : false;
			light->healthy = true;
			light->on = true;
			light->sparking = false;
			light->vulnerable = true;
			light->brightness = g_Rooms[i].br_light_each;

			light++;
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void lights_configure_for_perfect_darkness_gameplay(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < g_Vars.roomcount; i++) {
		struct light *light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];
		g_Rooms[i].lightop = LIGHTOP_SET;
		g_Rooms[i].lightop_to_frac = 0;

		for (j = 0; j < g_Rooms[i].numlights; j++) {
			light->sparkable = random() % 2 ? true : false;
			light->healthy = false;
			light->on = false;
			light->sparking = false;
			light->vulnerable = false;
			light->brightness = 0;

			light++;
		}
	}
}
#endif

#if VERSION >= VERSION_NTSC_1_0
void lights_tick_perfect_darkness(void)
{
	if (g_Vars.tickmode != g_LightsPrevTickMode) {
		if (TICKMODE_CUTSCENE == g_Vars.tickmode && TICKMODE_CUTSCENE != g_LightsPrevTickMode) {
			lights_configure_for_perfect_darkness_cutscene();
		} else if (TICKMODE_NORMAL == g_Vars.tickmode && TICKMODE_NORMAL != g_LightsPrevTickMode) {
			lights_configure_for_perfect_darkness_gameplay();
		}

		g_LightsPrevTickMode = g_Vars.tickmode;
	}
}
#endif

void rooms_tick_lighting(void)
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
	s32 timer240;
	f32 angle;
	f32 average;
	u32 stack;

#if VERSION >= VERSION_NTSC_1_0
	if (cheat_is_active(CHEAT_PERFECTDARKNESS)) {
		lights_tick_perfect_darkness();
	}
#else
	static s32 prevtickmode = 0;

	if (prevtickmode != g_Vars.tickmode) {
		if (prevtickmode == TICKMODE_CUTSCENE && g_Vars.tickmode == TICKMODE_NORMAL) {
			g_IsSwitchingGoggles = 2;
		}

		prevtickmode = g_Vars.tickmode;
	}
#endif

	if (g_LightTransferLookup == NULL) {
		return;
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		g_Rooms[i].flags &= ~ROOMFLAG_BRIGHTNESS_DIRTY_TEMP;
	}

	for (i = 1; i < g_Vars.roomcount; i++) {
		// Tick any light operations
		g_Rooms[i].lightop_timer240 -= g_Vars.lvupdate240;

		switch (g_Rooms[i].lightop) {
		case LIGHTOP_SET:
			g_Rooms[i].lightop_cur_frac = g_Rooms[i].lightop_to_frac;

			if (g_Rooms[i].lightop_cur_frac < 0.0f) {
				g_Rooms[i].lightop_cur_frac = 0.0f;
			}

			g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
			room_set_light_op(i, LIGHTOP_NONE, 0, 0, 0);
			break;
		case LIGHTOP_SETRANDOM:
			if (g_Rooms[i].lightop_timer240 < 0) {
				if (RANDOMFRAC() * 100.0f < g_Rooms[i].lightop_to_frac) {
					g_Rooms[i].lightop_cur_frac = 1.0f;
				} else {
					g_Rooms[i].lightop_cur_frac = g_Rooms[i].lightop_from_frac;

					if (g_Rooms[i].lightop_cur_frac < 0.0f) {
						g_Rooms[i].lightop_cur_frac = 0.0f;
					}
				}

				g_Rooms[i].lightop_timer240 = g_Rooms[i].lightop_duration240;
				g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
			}
			break;
		case LIGHTOP_TRANSITION:
			if (g_Rooms[i].lightop_timer240 > 0) {
				g_Rooms[i].lightop_cur_frac = g_Rooms[i].lightop_from_frac;
				g_Rooms[i].lightop_cur_frac += g_Rooms[i].lightop_timer240 / g_Rooms[i].lightop_duration240 * (g_Rooms[i].lightop_to_frac - g_Rooms[i].lightop_from_frac);

				if (g_Rooms[i].lightop_cur_frac < 0.0f) {
					g_Rooms[i].lightop_cur_frac = 0.0f;
				}
			} else {
				room_set_light_op(i, LIGHTOP_NONE, 0, 0, 0);
			}

			g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
			break;
		case LIGHTOP_SINELOOP:
			timer240 = g_Rooms[i].lightop_timer240 > 0 ? g_Rooms[i].lightop_timer240 : -g_Rooms[i].lightop_timer240;

			angle = (timer240 % (s32) g_Rooms[i].lightop_duration240) * DTOR(360) / g_Rooms[i].lightop_duration240;
			average = (g_Rooms[i].lightop_to_frac + g_Rooms[i].lightop_from_frac) * 0.5f;

			g_Rooms[i].lightop_cur_frac = g_Rooms[i].lightop_to_frac + (cosf(angle) + 1.0f) * average;

			if (g_Rooms[i].lightop_cur_frac < 0.0f) {
				g_Rooms[i].lightop_cur_frac = 0.0f;
			}

			g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
			break;
		case LIGHTOP_HIGHLIGHT:
			g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
			break;
		}

		if (g_IsSwitchingGoggles) {
			g_Rooms[i].flags |= ROOMFLAG_LIGHTS_DIRTY;
		}

		if (g_Rooms[i].flags & ROOMFLAG_LIGHTS_DIRTY) {
			// Calculate the settled local brightness
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
					amount = g_Rooms[i].br_base;
				} else {
					amount = (f32)g_Rooms[i].br_base / 2;
				}
			} else {
				if (g_Rooms[i].flags & ROOMFLAG_LIGHTSOFF) {
					amount = 2.0f;
				} else {
					amount = g_Rooms[i].br_base;
				}
			}

			amount *= g_Rooms[i].lightop_cur_frac;
			g_Rooms[i].br_settled_local = amount;

			// Add brightness for each light that is on
			light = (struct light *)&g_BgLightsFileData[g_Rooms[i].lightindex * 0x22];

			for (j = 0; j < g_Rooms[i].numlights; j++) {
				if (light->on) {
					amount = g_Rooms[i].lightop_cur_frac * light->brightness;
					g_Rooms[i].br_settled_local += (s32)amount;
				}

				light++;
			}

			if (g_Rooms[i].br_settled_local > 255) {
				g_Rooms[i].br_settled_local = 255;
			}

			g_Rooms[i].flags &= ~ROOMFLAG_LIGHTS_DIRTY;

			wasdirty = 1;
		}

		// Tick any flash lighting
		if (g_Rooms[i].br_flash != 0) {
			s32 increment = g_Vars.lvupdate240 * 2;

			if (g_LightTransferLookup != NULL) {
				s32 spa0 = 0;
				s32 sp9c = 0;

				s32 ret = func0f177c8c(g_LightTransferLookup[i].vertical, &spa0, &sp9c);

				while (ret != -1) {
					if (ret != 0) {
						g_Rooms[sp9c].flags |= ROOMFLAG_BRIGHTNESS_DIRTY_TEMP;
					}

					ret = func0f177c8c(g_LightTransferLookup[i].vertical, &spa0, &sp9c);
				}
			}

			if (g_Rooms[i].br_flash > 0) {
				if (increment > g_Rooms[i].br_flash) {
					increment = g_Rooms[i].br_flash;
				}

				g_Rooms[i].br_flash -= increment;
			} else {
				// @bug: In this branch br_flash is zero or negative.
				// Both instances of br_flash should be negated here.
				if (increment < g_Rooms[i].br_flash) {
					increment = g_Rooms[i].br_flash;
				}

				g_Rooms[i].br_flash += increment;
			}

			g_Rooms[i].flags |= ROOMFLAG_BRIGHTNESS_DIRTY_TEMP;
		}

		g_Rooms[i].flags &= ~ROOMFLAG_LIGHTS_DIRTY;
	}

	// If switching googles, mark all rooms as dirty so their brightness will be
	// recalculated the next time they appear on screen.
	if (g_IsSwitchingGoggles || wasdirty) {
		for (i = 1; i < g_Vars.roomcount; i++) {
			g_Rooms[i].flags |= ROOMFLAG_BRIGHTNESS_DIRTY_PERM;
		}
	}

	// Calculate settled regional lighting for any rooms that need it
	for (i = 1; i < g_Vars.roomcount; i++) {
		if (i != 0) {
			if ((g_Rooms[i].flags & ROOMFLAG_RENDERALWAYS) || (g_Rooms[i].flags & (ROOMFLAG_ONSCREEN | ROOMFLAG_STANDBY))) {
				if (g_Rooms[i].flags & (ROOMFLAG_BRIGHTNESS_DIRTY_PERM | ROOMFLAG_BRIGHTNESS_DIRTY_TEMP)) {
					s32 sum = 0;
					s32 sp90 = 0;
					s32 sp8c = 0;

					s32 ret = func0f177c8c(g_LightTransferLookup[i].horizontal, &sp90, &sp8c);

					while (ret != -1) {
						if (sp8c != 0) {
							s32 add = 0;

							if (sp8c) {
								add += (s32)((1.0f / 255.0f) * ret * g_Rooms[sp8c].br_settled_local);
							}

							sum += add;
						}

						ret = func0f177c8c(g_LightTransferLookup[i].horizontal, &sp90, &sp8c);
					}

					if (sum > 255) {
						sum = 255;
					}

					g_Rooms[i].br_settled_regional = sum;
					g_Rooms[i].flags |= ROOMFLAG_BRIGHTNESS_CALCED;
					g_Rooms[i].flags |= ROOMFLAG_NEEDRESHADE;
					g_Rooms[i].flags &= ~(ROOMFLAG_BRIGHTNESS_DIRTY_PERM | ROOMFLAG_BRIGHTNESS_DIRTY_TEMP);

					if (g_Rooms[i].lightop == LIGHTOP_HIGHLIGHT) {
						s32 r = room_get_final_brightness_for_player(i);
						s32 g = r;
						s32 b = r;

						scenario_highlight_room(i, &r, &g, &b);

						g_Rooms[i].highlightfrac_r = r * (1.0f / 255.0f);
						g_Rooms[i].highlightfrac_g = g * (1.0f / 255.0f);
						g_Rooms[i].highlightfrac_b = b * (1.0f / 255.0f);
					} else {
						g_Rooms[i].highlightfrac_r = room_get_final_brightness_for_player(i) * (1.0f / 255.0f);
						g_Rooms[i].highlightfrac_g = g_Rooms[i].highlightfrac_r;
						g_Rooms[i].highlightfrac_b = g_Rooms[i].highlightfrac_r;
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
					if (g_Rooms[prop->rooms[i]].flags & ROOMFLAG_NEEDRESHADE) {
						if (2 == g_IsSwitchingGoggles) {
							struct chrdata *chr = prop->chr;
							prop_calculate_shade_colour(chr->prop, chr->nextcol, chr->floorcol);
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

void lights_tick(void)
{
	struct hand *hand1 = &g_Vars.currentplayer->hands[0];
	struct hand *hand2 = &g_Vars.currentplayer->hands[1];

	lights_update_goggle_sounds();

	if (hand1->flashon || hand2->flashon) {
		room_flash_lighting(g_Vars.currentplayer->prop->rooms[0], 64, 80);
	}
}

void lights_stub(void)
{
	// empty
}

/**
 * Set a lighting flash in the given room and its neighbours.
 *
 * The room must not have ROOMFLAG_OUTDOORS.
 */
void room_flash_lighting(s32 roomnum, s32 start, s32 limit)
{
	if (g_LightTransferLookup && !(g_Rooms[roomnum].flags & ROOMFLAG_OUTDOORS ? 1 : 0)) {
		s32 value;
		s32 sp78 = 0;
		s32 neighbournum = 0;

		value = func0f177c8c(g_LightTransferLookup[roomnum].vertical, &sp78, &neighbournum);

		while (value != -1) {
			f32 increment = value * (1.0f / 255.0f) * start * 5.0f;

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
				room_flash_local_lighting(neighbournum, increment, limit);
			}

			value = func0f177c8c(g_LightTransferLookup[roomnum].vertical, &sp78, &neighbournum);
		}
	}
}

void room_flash_local_lighting(s32 roomnum, s32 increment, s32 limit)
{
	if (roomnum) {
		if (g_Rooms[roomnum].flags & ROOMFLAG_ONSCREEN) {
			if (increment > 0) {
				// Increasing
				if (g_Rooms[roomnum].br_flash < limit) {
					g_Rooms[roomnum].br_flash += increment;

					if (g_Rooms[roomnum].br_flash > limit) {
						g_Rooms[roomnum].br_flash = limit;
					}
				}
			} else {
				// Decreasing
				if (g_Rooms[roomnum].br_flash > limit) {
					g_Rooms[roomnum].br_flash += increment;

					if (g_Rooms[roomnum].br_flash < limit) {
						g_Rooms[roomnum].br_flash = limit;
					}
				}
			}
		}
	}
}

void room_highlight(s32 roomnum)
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
	Col *src;
	Col *dst;
	u8 br_settled_regional;
	s32 max;
	f32 mult;
	u32 stack;

	if (g_BgFrameCount != g_Rooms[roomnum].hlupdatedframe && g_Rooms[roomnum].loaded240 != 0) {
		g_Rooms[roomnum].hlupdatedframe = g_BgFrameCount;

		if ((g_Rooms[roomnum].flags & ROOMFLAG_BRIGHTNESS_CALCED) == 0) {
			g_Rooms[roomnum].flags |= ROOMFLAG_BRIGHTNESS_DIRTY_PERM;
		}

		br_settled_regional = room_get_settled_regional_brightness_for_player(roomnum);
		numcolours = g_Rooms[roomnum].gfxdata->numcolours;
		dst = gfx_allocate_colours(numcolours);
		g_Rooms[roomnum].colours = dst;

		extra = g_Rooms[roomnum].br_flash;
		src = (Col *)((uintptr_t)g_Rooms[roomnum].gfxdata->vertices + g_Rooms[roomnum].gfxdata->numvertices * sizeof(Vtx));
		src = (Col *)ALIGN8((uintptr_t)src);

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
				dst[i].a = src[i].a * (1.0f / 255.0f * br_settled_regional);
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

				if (max > br_settled_regional) {
					mult = br_settled_regional / (f32)max;
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
						|| g_Rooms[roomnum].lightop_cur_frac == 0.0f
						|| (g_Rooms[roomnum].flags & ROOMFLAG_LIGHTSOFF)) {
					red += extra;
					green += extra;
					blue += extra;
				}

				if (g_Rooms[roomnum].lightop == LIGHTOP_HIGHLIGHT) {
					scenario_highlight_room(roomnum, &red, &green, &blue);
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

void l3_build_portal_dist_lookup(void)
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

	sp44 = align16(MAX_PORTALS * sizeof(var8009cad0[0]));
	sp40 = align16(g_NumPortals * sizeof(g_PortalsNotGlassTmp[0]));
	sp3c = align16(g_NumPortals * sizeof(g_PortalPositionsTmp[0]));
	sp38 = align16(g_NumPortals * sizeof(g_PortalDistLookup[0]));
	sp34 = align16(g_NumPortals * sizeof(g_PortalDistLookup[0][0]));

	for (i = 0, s4 = sp38; i < g_NumPortals; i++) {
		if (i != 0) {
			s4 += i * sizeof(g_PortalDistLookup[0][0]);
		}
	}

	s4 = align16(s4);
	ptr = memp_alloc(align16(s4), MEMPOOL_STAGE);
	g_PortalDistLookup = (void *)ptr;

	ptr += sp38;

	for (i = 0; i < g_NumPortals; i++) {
		if (i != 0) {
			g_PortalDistLookup[i] = (void *)ptr;
			ptr += i * sizeof(g_PortalDistLookup[0][0]);
		} else {
			g_PortalDistLookup[i] = NULL;
		}
	}

	s4 += sp3c;
	s4 += sp44;
	s4 += sp40;
	s4 += sp38;
	s4 += g_NumPortals * sp34;

	align16((s32)s4);

	ptr = memp_get_next_stage_allocation();
	var8009cad0 = (void *)ptr;
	ptr += sp44;

	g_PortalsNotGlassTmp = (void *)ptr;
	ptr += sp40;

	g_PortalDistTableTmp = (void *)ptr;
	ptr += sp38;

	backupptr = ptr;

	ptr += g_NumPortals * sp34;
	g_PortalPositionsTmp = (void *)ptr;
	ptr = backupptr;

	s4 = sp38;

	for (i = 0; i < g_NumPortals; i++) {
		g_PortalDistTableTmp[i] = (void *)ptr;
		ptr += sp34;
		s4 += sp34;

		for (j = 0; j < g_NumPortals; j++) {
			g_PortalDistTableTmp[i][j] = 0x8009;
		}
	}

	for (i = 0; i < g_NumPortals; i++) {
		g_PortalsNotGlassTmp[i] = portal_get_xlu_frac(i) > 0.5f;

		portal_get_centre(i, &g_PortalPositionsTmp[i]);
	}

	if (g_Vars.stagenum == STAGE_INVESTIGATION) {
		g_PortalsNotGlassTmp[0] = true;
	}

	for (i = 0; i < g_NumPortals; i++) {
		g_PortalDistTableTmp[i][i] = 0;
	}

	l3_build_portal_dist_table();

	for (i = 0; i < g_NumPortals; i++) {
		for (j = 0; j < i; j++) {
			u16 a = g_PortalDistTableTmp[i][j];
			u16 b = g_PortalDistTableTmp[j][i];

			g_PortalDistLookup[i][j] = a < b ? a : b;
		}
	}
}

void l3_build_portal_dist_table(void)
{
	u32 j;
	u32 sp78;
	s32 i;
	s32 k;
	s32 portalnum;
	s32 portalnum2;
	s32 roomnum;
	s32 l;
	u16 dist;
	u32 stack;

	for (i = 0; i < g_NumPortals; i++) {
		for (j = 0, var8009cad0[0] = i, sp78 = 1; j != sp78; j = (j + 1) % 0x800) {
			portalnum = var8009cad0[j];

			for (k = 0; k < 2; k++) {
				if (k != 0) {
					roomnum = g_BgPortals[portalnum].roomnum2;
				} else {
					roomnum = g_BgPortals[portalnum].roomnum1;
				}

				for (l = 0; l < g_Rooms[roomnum].numportals; l++) {
					portalnum2 = g_RoomPortals[g_Rooms[roomnum].roomportallistoffset + l];

					if (portalnum2 != portalnum && g_PortalsNotGlassTmp[portalnum2]) {
						// If we haven't visited this slot yet
						if (g_PortalDistTableTmp[portalnum][portalnum2] >= 0x8000) {
							f32 xdiff = g_PortalPositionsTmp[portalnum].x - g_PortalPositionsTmp[portalnum2].x;
							f32 ydiff = g_PortalPositionsTmp[portalnum].y - g_PortalPositionsTmp[portalnum2].y;
							f32 zdiff = g_PortalPositionsTmp[portalnum].z - g_PortalPositionsTmp[portalnum2].z;

							f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

							g_PortalDistTableTmp[portalnum][portalnum2] = dist;
							g_PortalDistTableTmp[portalnum2][portalnum] = dist;
						}

						dist = g_PortalDistTableTmp[i][portalnum] + g_PortalDistTableTmp[portalnum2][portalnum];

						if (dist <= 5800 && ((i == portalnum) != 0 || dist < g_PortalDistTableTmp[i][portalnum2])) {
							g_PortalDistTableTmp[i][portalnum2] = dist;
							var8009cad0[sp78] = portalnum2;
							sp78 = (sp78 + 1) % 0x800;
						}
					}
				}
			}
		}
	}
}

/**
 * Find the distance between pos1 and pos2 via portals.
 *
 * resultarg can be a pointer to a float containing the max distance to check,
 * or NULL if there is no realistic limit.
 *
 * The calculated distance is returned, and written to the pointer argument if provided.
 */
f32 lights_find_distance_through_portals(s32 roomnum1, struct coord *pos1, s32 portalnum1, s32 roomnum2, struct coord *pos2, s32 portalnum2, f32 *resultarg)
{
	f32 resultstatic;
	f32 *resultptr;
	f32 limit;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;

	resultstatic = 32767.0f;
	resultptr = resultarg ? resultarg : &resultstatic;
	limit = *resultptr;

	xdiff = pos1->x - pos2->x;
	xdiff = ABSF(xdiff);

	if (xdiff < limit) {
		zdiff = pos1->z - pos2->z;
		zdiff = ABSF(zdiff);

		if (zdiff < limit) {
			ydiff = pos1->y - pos2->y;
			ydiff = ABSF(ydiff);

			if (ydiff < limit) {
				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

				if (dist < limit) {
					if (roomnum1 == roomnum2 || portalnum1 == portalnum2) {
						if (dist < *resultptr) {
							*resultptr = dist;
						}
					} else {
						f32 portalsdist = portal_get_acoustic_distance_to_portal(portalnum1, portalnum2);

						if (portalsdist < limit) {
							struct coord portalpos;
							f32 xdiff2;
							f32 zdiff2;

							portal_get_centre(portalnum1, &portalpos);
							limit -= portalsdist;

							xdiff2 = portalpos.x - pos1->x;
							xdiff2 = ABSF(xdiff2);

							if (xdiff2 < limit) {
								zdiff2 = portalpos.z - pos1->z;
								zdiff2 = ABSF(zdiff2);

								if (zdiff2 < limit) {
									f32 dist2 = sqrtf(xdiff2 * xdiff2 + zdiff2 * zdiff2);

									if (dist2 < limit) {
										struct coord portalpos2;
										f32 xdiff3;
										f32 zdiff3;

										portal_get_centre(portalnum2, &portalpos2);
										limit -= dist2;

										xdiff3 = portalpos2.x - pos2->x;
										xdiff3 = ABSF(xdiff3);

										if (xdiff3 < limit) {
											zdiff3 = portalpos2.z - pos2->z;
											zdiff3 = ABSF(zdiff3);

											if (zdiff3 < limit) {
												f32 dist3 = sqrtf(xdiff3 * xdiff3 + zdiff3 * zdiff3);

												if (dist3 < limit) {
													limit -= dist3;
													*resultptr -= limit;
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

	return *resultptr;
}

void lights_find_distance_through_rooms_with_limit(s32 roomnum1, struct coord *pos1, s32 roomnum2, struct coord *pos2, s32 arg4, f32 *result, bool arg6)
{
	f32 dist;

	if (!g_PortalDistTableEnabled
			|| PLAYERCOUNT() >= 3
			|| roomnum1 == roomnum2
			|| roomnum1 == -1
			|| roomnum2 == -1) {
		f32 xdist = pos1->x - pos2->x;
		xdist = ABSF(xdist);

		if (xdist < *result) {
			f32 zdist = pos1->z - pos2->z;
			zdist = ABSF(zdist);

			if (zdist < *result) {
				f32 ydist = pos1->y - pos2->y;
				ydist = ABSF(ydist);

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

				dist = lights_find_distance_through_portals(roomnum1, pos1, portalnum1, roomnum2, pos2, portalnum2, result);

				if (dist < *result) {
					*result = dist;
				}
			}
		}
	}
}

void lights_find_distance_through_rooms(s32 roomnum1, struct coord *pos1, s32 roomnum2, struct coord *pos2, s32 arg4, f32 *result)
{
	s32 portalnum1;
	s32 portalnum2;
	s32 i;
	s32 j;
	f32 dist;

	*result = 32767;

	if (roomnum1 == roomnum2) {
		*result = coords_get_distance(pos1, pos2);
	} else {
		for (i = 0; i < g_Rooms[roomnum1].numportals; i++) {
			portalnum1 = g_RoomPortals[g_Rooms[roomnum1].roomportallistoffset + i];
			if (1);

			for (j = 0; j < g_Rooms[roomnum2].numportals; j++) {
				portalnum2 = g_RoomPortals[g_Rooms[roomnum2].roomportallistoffset + j];
				if (j);
				if (j);

				dist = lights_find_distance_through_portals(roomnum1, pos1, portalnum1, roomnum2, pos2, portalnum2, NULL);

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
void lights_update_goggle_sounds(void)
{
	s32 brightness = room_get_final_brightness(g_Vars.currentplayer->prop->rooms[0]);

	if (((USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) && !g_Vars.currentplayer->usinggoggles)
			|| ((!USINGDEVICE(DEVICE_NIGHTVISION) && !USINGDEVICE(DEVICE_IRSCANNER)) && g_Vars.currentplayer->usinggoggles)) {
		g_IsSwitchingGoggles = true;
	}

	g_Vars.currentplayer->usinggoggles = USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER);

	if (USINGDEVICE(DEVICE_NIGHTVISION) && !lv_is_paused()) {
		// Play the goggle's hum sound
		if (g_Vars.currentplayer->nvhum == NULL) {
			snd_start(var80095200, SFXNUM_0505, &g_Vars.currentplayer->nvhum, -1, -1, -1.0f, -1, -1);
		}

		if (brightness > 128) {
			// Room is too bright for night vision - play overload sound
			if (g_Vars.currentplayer->nvoverload == NULL) {
				snd_start(var80095200, SFXNUM_01BE, &g_Vars.currentplayer->nvoverload, -1, -1, -1.0f, -1, -1);
			}
		} else {
			// Room is dark enough for night vision - stop overload sound if active
			if (g_Vars.currentplayer->nvoverload != NULL) {
				if (sndp_get_state(g_Vars.currentplayer->nvoverload) != AL_STOPPED) {
					sndp_stop_sound(g_Vars.currentplayer->nvoverload);
				}
			}
		}
	} else {
		// Paused or not wearing night vision - stop both sounds
		if (g_Vars.currentplayer->nvhum != NULL) {
			if (sndp_get_state(g_Vars.currentplayer->nvhum) != AL_STOPPED) {
				sndp_stop_sound(g_Vars.currentplayer->nvhum);
			}
		}

		if (g_Vars.currentplayer->nvoverload != NULL) {
			if (sndp_get_state(g_Vars.currentplayer->nvoverload) != AL_STOPPED) {
				sndp_stop_sound(g_Vars.currentplayer->nvoverload);
			}
		}
	}
}
