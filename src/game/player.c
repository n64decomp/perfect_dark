#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/bondmove.h"
#include "game/chraction.h"
#include "game/floor.h"
#include "game/inv.h"
#include "game/nbomb.h"
#include "game/title.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/atan2f.h"
#include "game/quaternion.h"
#include "game/bondgun.h"
#include "game/env.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/modeldef.h"
#include "game/healthbar.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/file.h"
#include "game/filemgr.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/explosions.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/room.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/joy.h"
#include "lib/lib_17ce0.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

s32 g_DefaultWeapons[2];
f32 g_MpSwirlRotateSpeed;
f32 g_MpSwirlAngleDegrees;
f32 g_MpSwirlForwardSpeed;
f32 g_MpSwirlDistance;
s16 g_WarpType1Pad;
struct warpparams *g_WarpType2Params;
f32 g_WarpType3PosAngle;
f32 g_WarpType3RotAngle;
f32 g_WarpType3Range;
f32 g_WarpType3Height;
f32 g_WarpType3MoreHeight;
u32 g_WarpType3Pad;
s32 g_WarpType2HasDirection;
u32 g_WarpType2Arg2;

s32 var8009de2c;
u32 var8009de34;
s16 g_SpawnPoints[MAX_SPAWNPOINTS];
s32 g_NumSpawnPoints;

struct vimode g_ViModes[] = {
	//  fbwidth
	//  |    fbheight
	//  |    |    width
	//  |    |    |  yscale
	//  |    |    |  |                 xscale
	//  |    |    |  |                 |    fullheight
	//  |    |    |  |                 |    |  fulltop
	//  |    |    |  |                 |    |  |     wideheight
	//  |    |    |  |                 |    |  |     |  widetop
	//  |    |    |  |                 |    |  |     |  |     cinemaheight
	//  |    |    |  |                 |    |  |     |  |     |  cinematop
	//  |    |    |  |                 |    |  |     |  |     |  |
#if VERSION >= VERSION_JPN_FINAL
	{ 320, 220, 320, 1,                1, 220, 0,  180, 20, 136, 42  }, // default
	{ 640, 220, 640, 0.5,              1, 220, 0,  180, 20, 136, 42  }, // hi-res
#elif VERSION >= VERSION_PAL_FINAL
	{ 320, 266, 320, 1,                1, 266, 0,  212, 20, 168, 42 }, // default
	{ 448, 266, 448, 0.71428567171097, 1, 266, 0,  212, 20, 168, 42 }, // hi-res
#elif VERSION >= VERSION_PAL_BETA
	{ 320, 252, 320, 1,                1, 252, 0,  212, 20, 168, 42 }, // default
	{ 448, 252, 448, 0.71428567171097, 1, 252, 0,  212, 20, 168, 42 }, // hi-res
#else
	{ 320, 220, 320, 1,                1, 220, 0,  180, 20, 136, 42  }, // default
	{ 640, 220, 640, 0.5,              1, 220, 0,  180, 20, 136, 42  }, // hi-res
	{ 320, 480, 320, 2,                2, 440, 20, 360, 60, 272, 104 }, // unused
	{ 440, 330, 440, 1,                1, 330, 0,  330, 0,  330, 0   }, // unused
	{ 440, 240, 440, 0.72727274894714, 1, 220, 0,  180, 0,  136, 0   }, // unused
	{ 400, 300, 400, 1,                2, 300, 0,  300, 0,  300, 0   }, // unused
#endif
};

s32 g_ViRes = VIRES_LO;
bool g_HiResEnabled = false;
u32 var800706d0 = 0x00000000;
u32 var800706d4 = 0x00000000;
u32 var800706d8 = 0x00000000;
u32 var800706dc = 0x00000000;
u32 var800706e0 = 0x00000000;
u32 var800706e4 = 0xbf800000;
u32 var800706e8 = 0x00000000;
u32 var800706ec = 0x3f800000;
u32 var800706f0 = 0x00000000;
u32 var800706f4 = 0x00000000;
u32 var800706f8 = 0x3f800000;
u32 var800706fc = 0x00000000;
u32 var80070700 = 0x00000000;
u32 var80070704 = 0x3f800000;
u32 var80070708 = 0x00000000;
u32 var8007070c = 0x00000000;
u32 var80070710 = 0x00000000;
u32 var80070714 = 0x00000000;
u32 var80070718 = 0x00000000;
u32 var8007071c = 0x00000000;
u32 var80070720 = 0x00000000;
u32 var80070724 = 0x00000000;
u32 var80070728 = 0x3f800000;
s32 var8007072c = 1;
u32 var80070730 = 0xffffffff;
u32 var80070734 = 0xffffffff;
u32 var80070738 = 0;
u32 var8007073c = 0;
struct gecreditsdata *g_CurrentGeCreditsData = NULL;
bool g_PlayerTriggerGeFadeIn = false;
u32 var80070748 = 0;
u32 var8007074c = 0;

bool g_PlayersWithControl[] = {
	true, true, true, true
};

bool g_PlayerInvincible = false;

s16 g_DeathAnimations[] = {
	ANIM_DEATH_001A,
	ANIM_DEATH_001C,
	ANIM_DEATH_0020,
	ANIM_DEATH_0021,
	ANIM_DEATH_0022,
	ANIM_DEATH_0023,
	ANIM_DEATH_0024,
	ANIM_DEATH_0025,
	0,
};

s32 g_NumDeathAnimations = 0;

extern bool g_IsMatchStart;

/**
 * Choose which location to spawn into from the given pads. Write the position
 * and rooms to the dstpos and dstrooms pointers and return the angle that the
 * player should be facing.
 *
 * It works by splitting each pad into one of three categories: good pads, bad
 * pads, and very bad pads. Categorisation logic is based on distances to enemy
 * chrs and room visibility. A shortlist of 4 pads is then created based on the
 * best pads, and a random pad is selected from the shortlist.
 *
 * @dangerous: If there are too many pads (24+) in the setup then array
 * overflows may occur.
 */
f32 playerChooseSpawnLocation(f32 chrradius, struct coord *dstpos, s16 *dstrooms, struct prop *prop, s16 *pads, s32 numpads)
{
	u8 verybadpads[24];
	u8 badpads[24];
	f32 padsqdists[24];

	u8 stack1[0x10];
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 sqdist;

	// "sl" prefixes are for shortlist
	s16 slpadindexes[8];
	struct coord slpositions[4];
	s16 slrooms[4][8];
	f32 slangles[4];
	s32 sllen = 0;

	s32 i;
	s32 p;
	s32 playercount = PLAYERCOUNT();
	f32 dstangle;
	u8 stack2[0x10];
	struct pad pad;
	s32 stack3[2];
	s16 tmppadrooms[2];
	f32 bestsqdist;
	s16 neighbours[20];

	// During the initial spawn, when there's more bots than spawn points they'll
	// consider all spawn pads to be "verybad" and end up spawning next to the
	// player. So for match start spawns, we'll use *any* pad in the map at random.
	if (g_IsMatchStart && g_MpNumChrs > numpads) {
		padUnpack(random() % g_PadsFile->numpads, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);

		dstrooms[0] = pad.room;
		dstrooms[1] = -1;

		dstpos->x = pad.pos.x;
		dstpos->y = pad.pos.y;
		dstpos->z = pad.pos.z;

		return atan2f(pad.look.x, pad.look.z);
	}

	// Iterate all spawn pads and populate the category arrays
	for (p = 0; p < numpads; p++) {
		bestsqdist = U32_MAX;
		padUnpack(pads[p], PADFIELD_POS | PADFIELD_ROOM, &pad);
		verybadpads[p] = false;
		badpads[p] = false;

		// Iterate players other than the one being spawned.
		// Note the closest chr's distance.
		// Decide whether the pad is considered to be ok, bad or very bad.
		for (i = 0; i < playercount; i++) {
			if (g_Vars.players[i]->prop
					&& g_Vars.players[i]->prop != prop
					&& (!prop || chrCompareTeams(prop->chr, g_Vars.players[i]->prop->chr, COMPARE_ENEMIES))) {
				xdiff = g_Vars.players[i]->prop->pos.x - pad.pos.x;
				ydiff = g_Vars.players[i]->prop->pos.y - pad.pos.y;
				zdiff = g_Vars.players[i]->prop->pos.z - pad.pos.z;

				sqdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

				if (sqdist < bestsqdist) {
					bestsqdist = sqdist;
				}

				if (roomIsOnPlayerScreen(pad.room, i)) {
					verybadpads[p] = true;
				}

				if (verybadpads[p] || roomIsOnPlayerStandby(pad.room, i)) {
					badpads[p] = true;
				}
			}
		}

		// Do the same as above, but for simulants
		tmppadrooms[0] = pad.room;
		tmppadrooms[1] = -1;

		roomGetNeighbours(pad.room, neighbours, 20);

		for (i = playercount; i < g_MpNumChrs; i++) {
			struct chrdata *chr = g_MpChrs[i].chr;

			if (chr->prop
					&& chr->prop != prop
					&& (!prop || chrCompareTeams(prop->chr, chr, COMPARE_ENEMIES))) {
				xdiff = chr->prop->pos.x - pad.pos.x;
				ydiff = chr->prop->pos.y - pad.pos.y;
				zdiff = chr->prop->pos.z - pad.pos.z;

				sqdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

				if (sqdist < bestsqdist) {
					bestsqdist = sqdist;
				}

				if (arrayIntersects(tmppadrooms, chr->prop->rooms)) {
					verybadpads[p] = true;
				}

				if (verybadpads[p] || arrayIntersects(neighbours, chr->prop->rooms)) {
					badpads[p] = true;
				}
			}
		}

		padsqdists[p] = bestsqdist;
	}

	// Now start building the shortlist arrays.
	// Start with a random index into the array, then process it circularly
	// until the shortlist is full or a full iteration is done.
	// Look for pads that aren't bad (and therefore aren't very bad either) and
	// are at least 10m away. For each pad added, set their distance to -1 so
	// they don't get reused later.
	i = random() % numpads;
	p = i; \
	while (sllen < 4) {
		if (padsqdists[p] > 1000 * 1000 && !badpads[p]) {
			padUnpack(pads[p], PADFIELD_POS | PADFIELD_ROOM | PADFIELD_LOOK, &pad);

			slrooms[sllen][0] = pad.room;
			slrooms[sllen][1] = -1;

			slpositions[sllen].x = pad.pos.x;
			slpositions[sllen].y = pad.pos.y;
			slpositions[sllen].z = pad.pos.z;

			slangles[sllen] = atan2f(pad.look.x, pad.look.z);

#if VERSION >= VERSION_NTSC_1_0
			if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#else
			if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#endif

			padsqdists[p] = -1.0f;
		}

		p = (p + 1) % numpads;

		if (p == i) {
			break;
		}
	}

	// If the shortlist still has vacant slots, iterate the pads again but this
	// time take the bad pads. Keep the very bad pads out of contention for now.
	p = i = random() % numpads;

	while (sllen < 4) {
		if (padsqdists[p] > 1000 * 1000 && !verybadpads[p]) {
			padUnpack(pads[p], PADFIELD_POS | PADFIELD_ROOM | PADFIELD_LOOK, &pad);

			slrooms[sllen][0] = pad.room;
			slrooms[sllen][1] = -1;

			slpositions[sllen].x = pad.pos.x;
			slpositions[sllen].y = pad.pos.y;
			slpositions[sllen].z = pad.pos.z;

			slangles[sllen] = atan2f(pad.look.x, pad.look.z);

#if VERSION >= VERSION_NTSC_1_0
			if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#else
			if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#endif

			padsqdists[p] = -1.0f;
		}

		if (numpads);

		p = (p + 1) % numpads;

		if (p == i) {
			break;
		}
	}

	// If there's still vacancies in the shortlist, fill them using any
	// remaining pads in distance order.
	while (sllen < 4) {
		i = -1;
		bestsqdist = -1.0f;

		for (p = 0; p < numpads; p++) {
			if (padsqdists[p] > bestsqdist) {
				bestsqdist = padsqdists[p];
				i = p;
			}
		}

		// If there's no more pads, bail out of the loop
		if (i < 0) {
			break;
		}

		// If the pad with the furtherest chr is less than 2m away from that
		// chr, bail out of the loop provided there's at least something in the
		// shortlist.
		if (!(bestsqdist > 200 * 200) && sllen != 0) {
			break;
		}

		// Add this pad to the shortlist
		padUnpack(pads[i], PADFIELD_POS | PADFIELD_ROOM | PADFIELD_LOOK, &pad);

		slrooms[sllen][0] = pad.room;
		slrooms[sllen][1] = -1;

		slpositions[sllen].x = pad.pos.x;
		slpositions[sllen].y = pad.pos.y;
		slpositions[sllen].z = pad.pos.z;

		slangles[sllen] = atan2f(pad.look.x, pad.look.z);

#if VERSION >= VERSION_NTSC_1_0
		if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
			slpadindexes[sllen] = i;
			sllen++;
		}
#else
		if (chrAdjustPosForSpawn(chrradius, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
			slpadindexes[sllen] = i;
			sllen++;
		}
#endif

		padsqdists[i] = -1.0f;
	}

	// Finally, choose a random pad from the shortlist
	if (sllen > 0) {
		p = random() % sllen;

		dstpos->x = slpositions[p].x;
		dstpos->y = slpositions[p].y;
		dstpos->z = slpositions[p].z;

		roomsCopy(slrooms[p], dstrooms);

		dstangle = slangles[p];
	} else {
		// No shortlisted pads, so pick a random one from the full selection
		padUnpack(pads[random() % numpads], PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);

		dstrooms[0] = pad.room;
		dstrooms[1] = -1;

		dstpos->x = pad.pos.x;
		dstpos->y = pad.pos.y;
		dstpos->z = pad.pos.z;

		dstangle = atan2f(pad.look.x, pad.look.z);
	}

	return dstangle;
}

f32 playerChooseGeneralSpawnLocation(f32 chrradius, struct coord *pos, s16 *rooms, struct prop *prop)
{
	return playerChooseSpawnLocation(chrradius, pos, rooms, prop, g_SpawnPoints, g_NumSpawnPoints);
}

void playerStartNewLife(void)
{
	struct coord pos = {0, 0, 0};
	s16 rooms[8];
	f32 angle;
	s32 *cmd = g_StageSetup.intro;
	f32 groundy;
	s32 i;

	pakEnableRumbleForPlayer(g_Vars.currentplayernum);

	g_Vars.currentplayer->dostartnewlife = false;

	{
		struct prop *prop = g_Vars.currentplayer->prop->child;

		while (prop) {
			struct defaultobj *obj = prop->obj;

			if (obj) {
				obj->hidden |= OBJHFLAG_REAPABLE;
			}

			prop = prop->next;
		}
	}

	splatResetChr(g_Vars.currentplayer->prop->chr);
	playerLoadDefaults();
	g_Vars.currentplayer->isdead = false;
	g_Vars.currentplayer->healthdamagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->damagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->gunammooff = 0;
	g_Vars.currentplayer->gunsightoff = 2;

	hudmsgsSetOn(0xffffffff);

	angle = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop); // var7f1ad534

	groundy = cdFindGroundInfoAtCyl(&pos, 30, rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom,
			NULL, NULL);

	pos.y = groundy + g_Vars.currentplayer->vv_eyeheight;

	g_Vars.currentplayer->vv_manground = groundy;
	g_Vars.currentplayer->vv_theta = angle * 360.0f / M_BADTAU;
	g_Vars.currentplayer->vv_ground = groundy;

	playerResetBond(&g_Vars.currentplayer->bond2, &pos);

	g_Vars.currentplayer->bond2.unk00.x = -sinf(angle);
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = cosf(angle);

	g_Vars.currentplayer->prop->pos.f[0] = g_Vars.currentplayer->bondprevpos.f[0] = pos.f[0];
	g_Vars.currentplayer->prop->pos.f[1] = g_Vars.currentplayer->bondprevpos.f[1] = pos.f[1];
	g_Vars.currentplayer->prop->pos.f[2] = g_Vars.currentplayer->bondprevpos.f[2] = pos.f[2];

	propDeregisterRooms(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
	g_Vars.currentplayer->prop->rooms[1] = -1;

	playerSetCamPropertiesWithRoom(&pos, &g_Vars.currentplayer->bond2.unk28,
			&g_Vars.currentplayer->bond2.unk1c, rooms[0]);

	invClear();

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->ammoheldarr); i++) {
		g_Vars.currentplayer->ammoheldarr[i] = 0;
	}

	invGiveSingleWeapon(WEAPON_UNARMED);

	if (cmd) {
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);

		while (cmd[0] != INTROCMD_END) {
			switch (cmd[0]) {
			case INTROCMD_SPAWN:
				cmd += 3;
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				cmd += 3;
				break;
			case INTROCMD_HILL:
				cmd += 2;
				break;
			case INTROCMD_WEAPON:
				if (cmd[3] == 0) {
					if (cmd[2] >= 0) {
						invGiveDoubleWeapon(cmd[1], cmd[2]);
					} else {
						invGiveSingleWeapon(cmd[1]);
					}
				}
				cmd += 4;
				break;
			case INTROCMD_AMMO:
				if (cmd[3] == 0) {
					bgunSetAmmoQuantity(cmd[1], cmd[2]);
				}
				cmd += 4;
				break;
			case INTROCMD_3:
				cmd += 8;
				break;
			case INTROCMD_4:
				cmd += 2;
				break;
			case INTROCMD_OUTFIT:
				cmd += 2;
				break;
			case INTROCMD_6:
				cmd += 10;
				break;
			default:
				cmd++;
				break;
			}
		}
	}

	bmoveUpdateRooms(g_Vars.currentplayer);
	playerSpawn();

	if (g_Vars.normmplayerisrunning) {
		playerStartChrFade(120, 1);
	} else {
		playerStartChrFade(0, 1);
	}

	if (g_Vars.currentplayer->prop->chr) {
		g_Vars.currentplayer->prop->chr->chrflags &= ~CHRCFLAG_HIDDEN;
	}
}

void playerLoadDefaults(void)
{
	if (!g_Vars.mplayerisrunning || g_Vars.currentplayer->model00d4 == NULL) {
		g_Vars.currentplayer->vv_eyeheight = 159;
		g_Vars.currentplayer->vv_headheight = 172;
	}

	g_Vars.currentplayer->globaldrawworldoffset.x = 0;
	g_Vars.currentplayer->globaldrawworldoffset.y = 0;
	g_Vars.currentplayer->globaldrawworldoffset.z = 0;
	g_Vars.currentplayer->globaldrawcameraoffset.x = 0;
	g_Vars.currentplayer->globaldrawcameraoffset.y = 0;
	g_Vars.currentplayer->globaldrawcameraoffset.z = 0;
	g_Vars.currentplayer->globaldrawworldbgoffset.x = 0;
	g_Vars.currentplayer->globaldrawworldbgoffset.y = 0;
	g_Vars.currentplayer->globaldrawworldbgoffset.z = 0;

	g_Vars.currentplayer->cameramode = CAMERAMODE_DEFAULT;
	g_Vars.currentplayer->memcampos.x = 0;
	g_Vars.currentplayer->memcampos.y = 0;
	g_Vars.currentplayer->memcampos.z = 0;
	g_Vars.currentplayer->memcamroom = -1;

	g_Vars.currentplayer->bondmovemode = -1;
	g_Vars.currentplayer->walkinitmove = 0;

	bmoveSetMode(MOVEMODE_WALK);

	g_Vars.currentplayer->bondperimenabled = true;
	g_Vars.currentplayer->periminfo.header.type = GEOTYPE_CYL;
	g_Vars.currentplayer->periminfo.header.flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SHOOT;
	g_Vars.currentplayer->periminfo.ymax = 0;
	g_Vars.currentplayer->periminfo.ymin = 0;
	g_Vars.currentplayer->periminfo.x = 0;
	g_Vars.currentplayer->periminfo.z = 0;
	g_Vars.currentplayer->periminfo.radius = 0;
	g_Vars.currentplayer->bondactivateorreload = false;
	g_Vars.currentplayer->isdead = false;

	if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_DUEL) {
		g_Vars.currentplayer->bondhealth = 0.01f;
	} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MAIANSOS) {
		g_Vars.currentplayer->bondhealth = 0.5f;
	} else {
		g_Vars.currentplayer->bondhealth = 1;
	}

	g_Vars.currentplayer->oldhealth = 1;
	g_Vars.currentplayer->oldarmour = 0;
	g_Vars.currentplayer->apparenthealth = 1;
	g_Vars.currentplayer->apparentarmour = 0;
	g_Vars.currentplayer->damageshowtime = -1;
	g_Vars.currentplayer->healthshowtime = -1;
	g_Vars.currentplayer->shieldshowtime = -1;
	g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_HIDDEN;
	g_Vars.currentplayer->bondbreathing = 0;
	g_Vars.currentplayer->speedtheta = 0;
	g_Vars.currentplayer->speedthetacontrol = 0;
	g_Vars.currentplayer->vv_costheta = 1;
	g_Vars.currentplayer->vv_sintheta = 0;
	g_Vars.currentplayer->vv_verta = -4;
	g_Vars.currentplayer->vv_verta360 = g_Vars.currentplayer->vv_verta;

	if (g_Vars.currentplayer->vv_verta360 < 0) {
		g_Vars.currentplayer->vv_verta360 += 360;
	}

	g_Vars.currentplayer->speedverta = 0;
	g_Vars.currentplayer->vv_cosverta = 1;
	g_Vars.currentplayer->vv_sinverta = 0;
	g_Vars.currentplayer->bondshotspeed.x = 0;
	g_Vars.currentplayer->bondshotspeed.y = 0;
	g_Vars.currentplayer->bondshotspeed.z = 0;

	g_Vars.currentplayer->docentreupdown = 0;
	g_Vars.currentplayer->lastupdown60 = 0;
	g_Vars.currentplayer->prevupdown = 0;
	g_Vars.currentplayer->movecentrerelease = 0;
	g_Vars.currentplayer->lookaheadcentreenabled = true;
	g_Vars.currentplayer->automovecentreenabled = true;
	g_Vars.currentplayer->fastmovecentreenabled = false;
	g_Vars.currentplayer->automovecentre = true;
	g_Vars.currentplayer->insightaimmode = false;

	g_Vars.currentplayer->autoyaimenabled = true;
	g_Vars.currentplayer->autoaimy = 0;
	g_Vars.currentplayer->autoyaimprop = NULL;
	g_Vars.currentplayer->autoyaimtime60 = -1;

	g_Vars.currentplayer->autoxaimenabled = true;
	g_Vars.currentplayer->autoaimx = 0;
	g_Vars.currentplayer->autoxaimprop = NULL;
	g_Vars.currentplayer->autoxaimtime60 = -1;

	g_Vars.currentplayer->autoaimdamp = (PAL ? 0.974f : 0.979f);

	g_Vars.currentplayer->colourscreenred = 0xff;
	g_Vars.currentplayer->colourscreengreen = 0xff;
	g_Vars.currentplayer->colourscreenblue = 0xff;
	g_Vars.currentplayer->colourscreenfrac = 0;
	g_Vars.currentplayer->colourfadetime60 = -1;
	g_Vars.currentplayer->colourfadetimemax60 = -1;
	g_Vars.currentplayer->colourfaderedold = 0xff;
	g_Vars.currentplayer->colourfaderednew = 0xff;
	g_Vars.currentplayer->colourfadegreenold = 0xff;
	g_Vars.currentplayer->colourfadegreennew = 0xff;
	g_Vars.currentplayer->colourfadeblueold = 0xff;
	g_Vars.currentplayer->colourfadebluenew = 0xff;
	g_Vars.currentplayer->colourfadefracold = 0;
	g_Vars.currentplayer->colourfadefracnew = 0;

	g_Vars.currentplayer->bondfadetime60 = -1;
	g_Vars.currentplayer->bondfadetimemax60 = -1;
	g_Vars.currentplayer->bondfadefracold = 0;
	g_Vars.currentplayer->bondfadefracnew = 0;

	g_Vars.currentplayer->controldef = 2;
	g_Vars.currentplayer->bondleandown = 15;
	g_Vars.currentplayer->shootrotx = 0;
	g_Vars.currentplayer->shootroty = 0;
	g_Vars.currentplayer->inlift = false;
	g_Vars.currentplayer->lift = NULL;
	g_Vars.currentplayer->onladder = false;

	g_Vars.currentplayer->eyesshut = false;
	g_Vars.currentplayer->eyesshutfrac = 0;

	g_Vars.currentplayer->waitforzrelease = false;
	g_Vars.currentplayer->devicesactive = 0;
	g_Vars.currentplayer->commandingaibot = NULL;
	g_Vars.currentplayer->deadtimer = -1;
	g_Vars.currentplayer->coopcanrestart = false;

	g_Vars.currentplayer->usinggoggles = false;
	g_Vars.currentplayer->nvhum = NULL;
	g_Vars.currentplayer->nvoverload = NULL;
	g_Vars.currentplayer->unk1c28 = 0;
	g_Vars.currentplayer->unk1c2c = 0;
	g_Vars.currentplayer->unk1c30 = 0;
	g_Vars.currentplayer->unk1c34 = 0;
	g_Vars.currentplayer->unk1c38 = 0;
	g_Vars.currentplayer->unk1c3c = 0;
}

void playerSpawn(void)
{
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 sqdist;
	struct chrdata *sortedchrs[10];
	f32 sorteddists[10];
	struct chrdata *tmpchr;
	s32 i;
	s32 j;
	s32 k;
	bool force;
	s32 numsqdists;
	struct coord sp9c;
	struct coord sp90;
	struct coord sp84;
	struct coord sp78;

	g_Vars.currentplayer->deathanimfinished = false;
	g_Vars.currentplayer->redbloodfinished = false;
	g_Vars.currentplayer->startnewbonddie = true;
	g_Vars.currentplayer->killsthislife = 0;

	g_Vars.currentplayer->lifestarttime60 = playerGetMissionTime();
	g_Vars.currentplayer->healthdisplaytime60 = 0;

	invGiveSingleWeapon(WEAPON_UNARMED);
	playerSetShieldFrac(0);

	if ((g_MpSetup.options & MPOPTION_SPAWNWITHWEAPON)
			&& g_MpSetup.weapons[0] != MPWEAPON_NONE
			&& g_MpSetup.weapons[0] != MPWEAPON_DISABLED) {
		struct mpweapon *mpweapon = &g_MpWeapons[g_MpSetup.weapons[0]];
		invGiveSingleWeapon(mpweapon->weaponnum);
		bgunEquipWeapon2(HAND_LEFT, WEAPON_NONE);
		bgunEquipWeapon2(HAND_RIGHT, mpweapon->weaponnum);
		bgunSetAmmoQuantity(mpweapon->weapon1ammotypeminusone, mpweapon->weapon1ammoqty);
	} else {
		bgunEquipWeapon2(HAND_LEFT, g_DefaultWeapons[HAND_LEFT]);
		bgunEquipWeapon2(HAND_RIGHT, g_DefaultWeapons[HAND_RIGHT]);
	}

	if (g_Vars.currentplayer->model00d4 == NULL) {
		playerTickChrBody();
	}

	playerUpdatePerimInfo();
}

void playerResetBond(struct playerbond *pb, struct coord *pos)
{
	pb->unk10.x = pos->x;
	pb->unk10.y = pos->y;
	pb->unk10.z = pos->z;

	pb->unk1c.x = 1;
	pb->unk1c.y = 0;
	pb->unk1c.z = 0;

	pb->unk28.x = 0;
	pb->unk28.y = 1;
	pb->unk28.z = 0;

	pb->unk00.x = 0;
	pb->unk00.y = 0;
	pb->unk00.z = 1;

	pb->radius = 30;
}

void playerChooseBodyAndHead(s32 *bodynum, s32 *headnum, s32 *arg2)
{
	if (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum < mpGetNumHeads2()) {
		*headnum = mpGetHeadId(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum);
	} else {
		*headnum = g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum - mpGetNumHeads2();

		if (arg2) {
			*arg2 = true;
		}
	}

	*bodynum = mpGetBodyId(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpbodynum);
}

/**
 * Ensure the chr's "chrbody" is set up, then tick it.
 *
 * The majority of this function is code that sets up the chrbody. The chrbody
 * is their model, weapon and animation as seen from a third person perspective.
 * It's needed for cutscenes, and in some cases during gameplay such as when
 * using the eyespy or flying a Slayer rocket.
 *
 * When using 1 player, these allocations are made out of "gunmem", which is a
 * single allocation that's assumed to be big enough.
 *
 * When using 2-4 players, gunmem is not used here. This might be because all
 * these structures are already allocated elsewhere in memory due to the two
 * players being able to see each other at any time.
 */
void playerTickChrBody(void)
{
	f32 turnangle = (360.0f - g_Vars.currentplayer->vv_theta) * M_BADTAU / 360.0f;

	if (g_Vars.currentplayer->haschrbody == false) {
		struct chrdata *chr;
		struct texpool texpool;
		struct modelfiledata *bodyfiledata;
		struct modelfiledata *headfiledata = NULL;
		struct modelfiledata *weaponfiledata;
		s32 offset1 = 0;
		u8 *allocation;
		void *spe8;
		s32 offset2;
		u32 stack2;
		struct weaponobj *weaponobj;

		// Unused
		struct weaponobj template = {
			256,                    // extrascale
			0,                      // hidden2
			OBJTYPE_WEAPON,         // type
			MODEL_CHRFALCON2,       // modelnum
			-1,                     // pad
			OBJFLAG_ASSIGNEDTOCHR,  // flags
			0,                      // flags2
			0,                      // flags3
			NULL,                   // prop
			NULL,                   // model
			1, 0, 0,                // realrot
			0, 1, 0,
			0, 0, 1,
			0,                      // hidden
			NULL,                   // geo
			NULL,                   // projectile
			0,                      // damage
			1000,                   // maxdamage
			0xff, 0xff, 0xff, 0x00, // shadecol
			0xff, 0xff, 0xff, 0x00, // nextcol
			0x0fff,                 // floorcol
			0,                      // tiles
			WEAPON_FALCON2,         // weaponnum
			0,                      // unk5d
			0,                      // unk5e
			FUNC_PRIMARY,           // gunfunc
			0,                      // fadeouttimer60
			-1,                     // dualweaponnum
			-1,                     // timer240
			NULL,                   // dualweapon
		};

		s32 weaponmodelnum;
		s32 weaponnum = bgunGetWeaponNum2(HAND_RIGHT);
		s32 bodynum = BODY_DARK_COMBAT;
		s32 headnum = HEAD_DARK_COMBAT;
		bool sp60 = false;
		struct model *model = NULL;
		union modelrwdata **rwdatas;
		u32 stack3[2];

		g_Vars.currentplayer->haschrbody = true;
		playerChooseBodyAndHead(&bodynum, &headnum, &sp60);

		weaponmodelnum = playermgrGetModelOfWeapon(weaponnum);

		if (g_HeadsAndBodies[bodynum].filedata == NULL) {
			g_HeadsAndBodies[bodynum].filedata = modeldefLoadToNew(g_HeadsAndBodies[bodynum].filenum);
		}

		bodyfiledata = g_HeadsAndBodies[bodynum].filedata;

		if (g_HeadsAndBodies[bodynum].unk00_01) {
			headnum = -1;
		} else if (sp60) {
			headfiledata = func0f18e57c(headnum, &headnum);
		} else {
			g_HeadsAndBodies[headnum].filedata = modeldefLoadToNew(g_HeadsAndBodies[headnum].filenum);
			headfiledata = g_HeadsAndBodies[headnum].filedata;
			g_FileInfo[g_HeadsAndBodies[headnum].filenum].loadedsize = 0;
			bodyCalculateHeadOffset(headfiledata, headnum, bodynum);
		}

		g_Vars.currentplayer->model00d4 = body0f02ce8c(bodynum, headnum, bodyfiledata, headfiledata, false, model, true, true);

		chr0f020b14(g_Vars.currentplayer->prop, g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms, turnangle);
		g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;
		chr = g_Vars.currentplayer->prop->chr;

		chr->chrflags |= CHRCFLAG_00000001;

		modelSetRootPosition(g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos);
		chrSetLookAngle(g_Vars.currentplayer->prop->chr, turnangle);

		chr->headnum = headnum;
		chr->bodynum = bodynum;
		chr->race = bodyGetRace(chr->bodynum);
		chr->radius = g_Vars.currentplayer->bond2.radius;

		g_Vars.currentplayer->vv_eyeheight = (s32)g_HeadsAndBodies[bodynum].height;
		g_Vars.currentplayer->vv_headheight = g_Vars.currentplayer->vv_eyeheight;

		if (headnum >= 0) {
			g_Vars.currentplayer->vv_headheight += (s32)g_HeadsAndBodies[headnum].height;
		} else {
			g_Vars.currentplayer->vv_headheight += 13;
		}

		if (g_Vars.currentplayer->vv_headheight > g_HeadsAndBodies[BODY_MRBLONDE].height + g_HeadsAndBodies[HEAD_MRBLONDE].height) {
			g_Vars.currentplayer->vv_headheight = g_HeadsAndBodies[BODY_MRBLONDE].height + g_HeadsAndBodies[HEAD_MRBLONDE].height;
		}

		g_Vars.currentplayer->vv_height = g_Vars.currentplayer->vv_eyeheight;

		if (weaponmodelnum >= 0) {
			if (g_Vars.mplayerisrunning == false) {
				weaponfiledata = modeldefLoad(g_ModelStates[weaponmodelnum].fileid, allocation + offset1, offset2 - offset1, &texpool);
				fileGetLoadedSize(g_ModelStates[weaponmodelnum].fileid);
				modelCalculateRwDataLen(weaponfiledata);
			} else {
				weaponobj = NULL;
				weaponfiledata = NULL;
			}

			weaponCreateForChr(chr, weaponmodelnum, weaponnum, 0, weaponobj, weaponfiledata);
		}

		chr->fireslots[0] = bgunAllocateFireslot();
		func0f02e9a0(chr, 0);
		bmoveUpdateRooms(g_Vars.currentplayer);
	} else {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;

		if (chr->model->anim == NULL) {
			chr->chrflags |= CHRCFLAG_00000001;
			func0f02e9a0(chr, 0);
			modelSetRootPosition(g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos);
			chrSetLookAngle(g_Vars.currentplayer->prop->chr, turnangle);
			bmoveUpdateRooms(g_Vars.currentplayer);
		}
	}
}

void playerSetTickMode(s32 tickmode)
{
	g_Vars.tickmode = tickmode;
	g_Vars.in_cutscene = false;
}

void playerBeginGeFadeIn(void)
{
	playerSetTickMode(TICKMODE_GE_FADEIN);
	g_PlayerTriggerGeFadeIn = false;
}

void playersBeginMpSwirl(void)
{
	playerSetTickMode(TICKMODE_MPSWIRL);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetMode(MOVEMODE_WALK);

	g_MpSwirlRotateSpeed = 0;
	g_MpSwirlAngleDegrees = -90;
	g_MpSwirlForwardSpeed = 0;
	g_MpSwirlDistance = 80;

	envChooseAndApply(mainGetStageNum(), false);
}

void playerTickMpSwirl(void)
{
	f32 angle;
	struct coord pos = {0, 0, 0};
	struct coord look = {0, 0, 1};
	struct coord up = {0, 1, 0};
	s32 i;

	playerSetCameraMode(CAMERAMODE_THIRDPERSON);

	// This function is called once for each player per frame,
	// but the swirl position should only be updated once per frame,
	// so it's only updated for the player at index 0.
	if (g_Vars.currentplayerindex == 0) {
		for (i = 0; i < g_Vars.lvupdate60; i++) {
			// Calculate rotation
			if (g_MpSwirlAngleDegrees < 179.5f) {
				if (g_MpSwirlAngleDegrees < -20) {
					g_MpSwirlRotateSpeed += 0.1f;
				}

				if (g_MpSwirlAngleDegrees > 110) {
					g_MpSwirlRotateSpeed -= 0.1f;
				}

				g_MpSwirlAngleDegrees += g_MpSwirlRotateSpeed;
			}

			if (g_MpSwirlAngleDegrees >= 179.5f) {
				g_MpSwirlAngleDegrees = 180.0f;
			}

			// Calculate distance
			if (g_MpSwirlAngleDegrees > 80) {
				if (g_MpSwirlDistance > 60) {
					g_MpSwirlForwardSpeed -= 0.1f;
				} else {
					g_MpSwirlForwardSpeed += 0.015f;
				}

				g_MpSwirlDistance += g_MpSwirlForwardSpeed;

				if (g_MpSwirlDistance < 1) {
					g_MpSwirlDistance = 1;
				}
			}
		}
	}

	angle = (g_MpSwirlAngleDegrees - g_Vars.currentplayer->vv_theta) * M_PI / 180.0f;

	pos.x = sinf(angle) * g_MpSwirlDistance + g_Vars.currentplayer->bond2.unk10.x;
	pos.y = g_Vars.currentplayer->bond2.unk10.y + g_MpSwirlDistance * 0.08f;
	pos.z = cosf(angle) * g_MpSwirlDistance + g_Vars.currentplayer->bond2.unk10.z;

	look.x = g_Vars.currentplayer->bond2.unk10.x - pos.x;
	look.y = g_Vars.currentplayer->bond2.unk10.y - pos.y;
	look.z = g_Vars.currentplayer->bond2.unk10.z - pos.z;

	player0f0c1840(&pos, &up, &look, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms);

	if (g_MpSwirlDistance < 5.0f) {
		playerEndCutscene();
	}
}

void player0f0b9a20(void)
{
	playerSetTickMode(TICKMODE_NORMAL);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetMode(MOVEMODE_WALK);

	if (mainGetStageNum() == STAGE_TEST_LEN) {
		playerSetFadeColour(0, 0, 0, 1);
		playerSetFadeFrac(0, 1);
	} else if (var80070748 != 0) {
		playerSetFadeColour(0, 0, 0, 1);
		playerSetFadeFrac(60, 0);
	}

	envChooseAndApply(mainGetStageNum(), false);
	bgunEquipWeapon2(HAND_LEFT, g_DefaultWeapons[HAND_LEFT]);
	bgunEquipWeapon2(HAND_RIGHT, g_DefaultWeapons[HAND_RIGHT]);
	var8007074c = 0;
}

void playerEndCutscene(void)
{
	if (g_Vars.autocutplaying) {
		g_Vars.autocutfinished = true;
	} else {
		playerSetTickMode(TICKMODE_NORMAL);
		g_PlayerTriggerGeFadeIn = false;
		bmoveSetModeForAllPlayers(MOVEMODE_WALK);
	}
}

void playerExecutePreparedWarp(void)
{
	struct pad pad;
	struct coord pos = {0, 0, 0};
	struct coord look = {0, 0, 1};
	struct coord up = {0, 1, 0};
	s32 room;
	struct coord memcampos;

	playerSetCameraMode(CAMERAMODE_THIRDPERSON);

	if (g_WarpType1Pad >= 0) {
		// Warp to an exact position with a static direction of 0, 0, 1.
		// Used by device and holo training to warp player back to room,
		// and Deep Sea teleports
		padUnpack(g_WarpType1Pad, PADFIELD_POS | PADFIELD_ROOM, &pad);

		memcampos.x = pad.pos.x;
		memcampos.y = pad.pos.y;
		memcampos.z = pad.pos.z;

		pos.x = memcampos.f[0];
		pos.y = memcampos.f[1];
		pos.z = memcampos.f[2];

		room = pad.room;
	} else if (g_WarpType2Params) {
		// Warp to an exact position with an optional direction.
		// Used by AI command 00df, but that command is not used.
		pos.x = g_WarpType2Params->pos.x;
		pos.y = g_WarpType2Params->pos.y;
		pos.z = g_WarpType2Params->pos.z;

		padUnpack(g_WarpType2Params->pad, PADFIELD_POS | PADFIELD_ROOM, &pad);

		room = pad.room;

		memcampos.x = pad.pos.x;
		memcampos.y = pad.pos.y;
		memcampos.z = pad.pos.z;

		if (1);

		if (g_WarpType2HasDirection != 1) {
			look.x = cosf(g_WarpType2Params->look[1]) * sinf(g_WarpType2Params->look[0]);
			look.y = sinf(g_WarpType2Params->look[1]);
			look.z = cosf(g_WarpType2Params->look[1]) * cosf(g_WarpType2Params->look[0]);
		}
	} else {
		// Warp to a location within a specified range and angle of the pad,
		// with options for the direction and height offset from the pad.
		// Used by AI command 00f4, but that command is not used.
		padUnpack(g_WarpType3Pad, PADFIELD_POS | PADFIELD_ROOM, &pad);

		room = pad.room;

		memcampos.x = pad.pos.x;
		memcampos.y = pad.pos.y;
		memcampos.z = pad.pos.z;

		pos.x = memcampos.x + sinf(g_WarpType3PosAngle) * g_WarpType3Range + cosf(g_WarpType3PosAngle) * 0.0f;
		pos.y = memcampos.y + g_WarpType3MoreHeight + g_WarpType3Height;
		pos.z = memcampos.z + cosf(g_WarpType3PosAngle) * g_WarpType3Range + sinf(g_WarpType3PosAngle) * 0.0f;

		look.x = memcampos.x + cosf(g_WarpType3PosAngle) * 0.0f - pos.f[0];
		look.y = memcampos.y + g_WarpType3MoreHeight - pos.f[1];
		look.z = memcampos.z + sinf(g_WarpType3PosAngle) * 0.0f - pos.f[2];

		g_WarpType3PosAngle += g_WarpType3RotAngle * g_Vars.lvupdate60freal;

		while (g_WarpType3PosAngle >= M_BADTAU) {
			g_WarpType3PosAngle -= M_BADTAU;
		}

		while (g_WarpType3PosAngle < 0) {
			g_WarpType3PosAngle += M_BADTAU;
		}
	}

	player0f0c1ba4(&pos, &up, &look, &memcampos, room);
}

void playerSetZoomFovY(f32 fovy, f32 timemax)
{
	g_Vars.currentplayer->zoomintime = 0;
	g_Vars.currentplayer->zoomintimemax = timemax;
	g_Vars.currentplayer->zoominfovyold = g_Vars.currentplayer->zoominfovy;
	g_Vars.currentplayer->zoominfovynew = fovy;
}

f32 playerGetZoomFovY(void)
{
	if (g_Vars.currentplayer->zoomintimemax > g_Vars.currentplayer->zoomintime) {
		return g_Vars.currentplayer->zoominfovynew;
	}

	return g_Vars.currentplayer->zoominfovy;
}

void playerTweenFovY(f32 targetfovy)
{
	if (playerGetZoomFovY() != targetfovy) {
		if (g_Vars.currentplayer->zoominfovy > targetfovy) {
			playerSetZoomFovY(targetfovy, (g_Vars.currentplayer->zoominfovy - targetfovy) * 15.0f / 30.0f);
		} else {
			playerSetZoomFovY(targetfovy, (targetfovy - g_Vars.currentplayer->zoominfovy) * 15.0f / 30.0f);
		}
	}
}

f32 playerGetTeleportFovY(void)
{
	f32 time;
	u32 fovyoffset;

	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_PREENTER) {
		return 60.0f;
	}

	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_EXITING) {
		time = 47 - g_Vars.currentplayer->teleporttime;
	} else {
		time = g_Vars.currentplayer->teleporttime;
	}

	time = time / 48.0f;
	time = 1.0f - cosf(time * M_PI * 0.5f);
	fovyoffset = 117.0f * time;

	return fovyoffset + 60.0f;
}

void playerUpdateZoom(void)
{
	f32 scale;
	f32 fovy;
	struct stagetableentry *stage;

	if (g_Vars.currentplayer->zoomintime < g_Vars.currentplayer->zoomintimemax) {
		g_Vars.currentplayer->zoomintime += g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->zoomintime > g_Vars.currentplayer->zoomintimemax) {
			g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
		}

		g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovyold +
			(g_Vars.currentplayer->zoomintime *
			 (g_Vars.currentplayer->zoominfovynew - g_Vars.currentplayer->zoominfovyold))
			/ g_Vars.currentplayer->zoomintimemax;
	} else {
		g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
		g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovynew;
	}

	playermgrSetFovY(g_Vars.currentplayer->zoominfovy);
	viSetFovY(g_Vars.currentplayer->zoominfovy);

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		fovy = playerGetTeleportFovY();
		playermgrSetFovY(fovy);
		viSetFovY(fovy);
	}

	if (g_Vars.currentplayer->zoominfovy >= 15) {
		scale = 1;
	} else if (g_Vars.currentplayer->zoominfovy >= 7) {
		scale = (g_Vars.currentplayer->zoominfovy - 7) * 0.0875f + 0.3f;
	} else if (g_Vars.currentplayer->zoominfovy >= 4) {
		scale = (g_Vars.currentplayer->zoominfovy - 4) * (1.0f / 30.0f) + 0.2f;
	} else if (g_Vars.currentplayer->zoominfovy >= 2) {
		scale = (g_Vars.currentplayer->zoominfovy - 2) * (1.0f / 20.0f) + 0.1f;
	} else {
		scale = 0.1;
	}

	stage = stageGetCurrent();
	currentPlayerSetScaleBg2Gfx((1 - (1 - stage->unk34) * (1 - scale) * (10.f / 9.0f)) * scale);
}

void playerStopAudioForPause(void)
{
	struct hand *hand;
	s32 i;

	for (i = 0; i < 2; i++) {
		hand = &g_Vars.currentplayer->hands[i];

		if (hand->audiohandle2 && sndGetState(hand->audiohandle2) != AL_STOPPED) {
			audioStop(hand->audiohandle2);
		}
	}
}

u32 var8007083c = 0;
u32 g_GlobalMenuRoot = 0;

void playerTickPauseMenu(void)
{
	bool opened = false;

	switch (g_Vars.currentplayer->pausemode) {
	case PAUSEMODE_UNPAUSED:
		break;
	case PAUSEMODE_PAUSING:
		// Pause menu is opening
		switch (g_GlobalMenuRoot) {
		case MENUROOT_FILEMGR:
			opened = filemgrConsiderPushingFileSelectDialog();
			break;
		case MENUROOT_4MBMAINMENU:
		case MENUROOT_MPSETUP:
			opened = true;
			break;
		}

		if (opened) {
			lvSetPaused(true);
			g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;

			musicStartMenu();
		}
		break;
	case PAUSEMODE_PAUSED:
		// Pause menu is fully open
		break;
	case PAUSEMODE_UNPAUSING:
		// Pause menu is closing
		g_Vars.currentplayer->pausetime60 += g_Vars.diffframe60;

		if (g_Vars.currentplayer->pausetime60 >= 20) {
			lvSetPaused(false);
			g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
			musicEndMenu();
		}
		break;
	}
}

void playerPause(s32 root)
{
	g_GlobalMenuRoot = root;

	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
		g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSING;
	}
}

void playerUnpause(void)
{
	if (g_Vars.currentplayer->pausemode == PAUSEMODE_PAUSED) {
		lvSetPaused(false);
		musicEndMenu();
		g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
	}
}

Gfx *player0f0baf84(Gfx *gdl)
{
	if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
		Mtx *a = gfxAllocateMatrix();
		u16 b;

		guPerspective(a, &b, g_Vars.currentplayer->zoominfovy,
				PAL ? 1.7316017150879f : 1.4545454978943f, 10, 300, 1);

		gSPMatrix(gdl++, OS_PHYSICAL_TO_K0(a), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPPerspNormalize(gdl++, b);
	}

	return gdl;
}

Gfx *playerDrawFade(Gfx *gdl, u32 r, u32 g, u32 b, f32 frac)
{
	if (frac > 0) {
		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetColorDither(gdl++, G_CD_DISABLE);
		gDPSetTexturePersp(gdl++, G_TP_NONE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
		gDPSetTextureConvert(gdl++, G_TC_FILT);
		gDPSetTextureLUT(gdl++, G_TT_NONE);
		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
		gDPSetPrimColor(gdl++, 0, 0, r, g, b, (s32)(frac * 255));
		gDPFillRectangle(gdl++, viGetViewLeft(), viGetViewTop(),
				viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
		gDPPipeSync(gdl++);
		gDPSetColorDither(gdl++, G_CD_BAYER);
		gDPSetTexturePersp(gdl++, G_TP_PERSP);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
	}

	return gdl;
}

Gfx *playerDrawStoredFade(Gfx *gdl)
{
	return playerDrawFade(gdl,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			g_Vars.currentplayer->colourscreenfrac);
}

void playerSetFadeColour(s32 r, s32 g, s32 b, f32 frac)
{
	g_Vars.currentplayer->colourscreenred = r;
	g_Vars.currentplayer->colourscreengreen = g;
	g_Vars.currentplayer->colourscreenblue = b;
	g_Vars.currentplayer->colourscreenfrac = frac;
}

void playerAdjustFade(f32 maxfadetime, s32 r, s32 g, s32 b, f32 frac)
{
	g_Vars.currentplayer->colourfadetime60 = 0;
	g_Vars.currentplayer->colourfadetimemax60 = maxfadetime;
	g_Vars.currentplayer->colourfaderedold = g_Vars.currentplayer->colourscreenred;
	g_Vars.currentplayer->colourfaderednew = r;
	g_Vars.currentplayer->colourfadegreenold = g_Vars.currentplayer->colourscreengreen;
	g_Vars.currentplayer->colourfadegreennew = g;
	g_Vars.currentplayer->colourfadeblueold = g_Vars.currentplayer->colourscreenblue;
	g_Vars.currentplayer->colourfadebluenew = b;
	g_Vars.currentplayer->colourfadefracold = g_Vars.currentplayer->colourscreenfrac;
	g_Vars.currentplayer->colourfadefracnew = frac;
}

void playerSetFadeFrac(f32 maxfadetime, f32 frac)
{
	playerAdjustFade(maxfadetime,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			frac);
}

bool playerIsFadeComplete(void)
{
	return g_Vars.currentplayer->colourfadetimemax60 < 0;
}

void playerUpdateColourScreenProperties(void)
{
	if (g_Vars.currentplayer->colourfadetimemax60 >= 0) {
		g_Vars.currentplayer->colourfadetime60 += g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->colourfadetime60 < g_Vars.currentplayer->colourfadetimemax60) {
			f32 mult = g_Vars.currentplayer->colourfadetime60 / g_Vars.currentplayer->colourfadetimemax60;
			g_Vars.currentplayer->colourscreenfrac = g_Vars.currentplayer->colourfadefracold + (g_Vars.currentplayer->colourfadefracnew - g_Vars.currentplayer->colourfadefracold) * mult;
			g_Vars.currentplayer->colourscreenred = g_Vars.currentplayer->colourfaderedold + (s32)((g_Vars.currentplayer->colourfaderednew - g_Vars.currentplayer->colourfaderedold) * mult);
			g_Vars.currentplayer->colourscreengreen = g_Vars.currentplayer->colourfadegreenold + (s32)((g_Vars.currentplayer->colourfadegreennew - g_Vars.currentplayer->colourfadegreenold) * mult);
			g_Vars.currentplayer->colourscreenblue = g_Vars.currentplayer->colourfadeblueold + (s32)((g_Vars.currentplayer->colourfadebluenew - g_Vars.currentplayer->colourfadeblueold) * mult);
			return;
		}

		g_Vars.currentplayer->colourscreenfrac = g_Vars.currentplayer->colourfadefracnew;
		g_Vars.currentplayer->colourscreenred = g_Vars.currentplayer->colourfaderednew;
		g_Vars.currentplayer->colourscreengreen = g_Vars.currentplayer->colourfadegreennew;
		g_Vars.currentplayer->colourscreenblue = g_Vars.currentplayer->colourfadebluenew;
		g_Vars.currentplayer->colourfadetimemax60 = -1;
	}
}

void playerStartChrFade(f32 duration60, f32 targetfrac)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;

	if (chr) {
		g_Vars.currentplayer->bondfadetime60 = 0;
		g_Vars.currentplayer->bondfadetimemax60 = duration60;
		g_Vars.currentplayer->bondfadefracold = chr->fadealpha / 255.0f;
		g_Vars.currentplayer->bondfadefracnew = targetfrac;
	}
}

void playerTickChrFade(void)
{
	if (g_Vars.currentplayer->bondfadetimemax60 >= 0) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;
		f32 frac;

		g_Vars.currentplayer->bondfadetime60 += g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->bondfadetime60 < g_Vars.currentplayer->bondfadetimemax60) {
			frac = g_Vars.currentplayer->bondfadefracold
				+ (g_Vars.currentplayer->bondfadefracnew - g_Vars.currentplayer->bondfadefracold)
				* g_Vars.currentplayer->bondfadetime60
				/ g_Vars.currentplayer->bondfadetimemax60;
		} else {
			frac = g_Vars.currentplayer->bondfadefracnew;
			g_Vars.currentplayer->bondfadetimemax60 = -1;
		}

		if (chr) {
			chr->fadealpha = (s8)(frac * 255);
		}
	}
}

struct damagetype g_DamageTypes[] = {
	// flashstartframe
	// |  flashfullframe
	// |  |  flashendframe
	// |  |  |   maxalpha
	// |  |  |   |     red
	// |  |  |   |     |     green
	// |  |  |   |     |     |     blue
	// |  |  |   |     |     |     |
	{  0, 5, 40, 0.7,  0x96, 0x00, 0x00 },
	{  0, 5, 40, 0.7,  0x96, 0x00, 0x00 },
	{  0, 5, 30, 0.65, 0x96, 0x00, 0x00 },
	{  0, 5, 25, 0.6,  0x96, 0x00, 0x00 },
	{  0, 5, 22, 0.55, 0x96, 0x00, 0x00 },
	{  0, 5, 19, 0.5,  0x96, 0x00, 0x00 },
	{  0, 5, 17, 0.45, 0x96, 0x00, 0x00 },
	{  0, 5, 15, 0.4,  0x96, 0x00, 0x00 },
};

struct healthdamagetype g_HealthDamageTypes[] = {
	// openendframe
	// |  updatestartframe
	// |  |   updateendframe
	// |  |   |   closestartframe
	// |  |   |   |    closeendframe
	// |  |   |   |    |
	{ 20, 34, 46, 270, 285 },
	{ 20, 37, 52, 250, 265 },
	{ 20, 40, 58, 230, 245 },
	{ 20, 43, 64, 210, 225 },
	{ 20, 46, 70, 190, 205 },
	{ 20, 49, 76, 170, 185 },
	{ 20, 52, 82, 150, 165 },
	{ 20, 55, 88, 130, 145 },
};

/**
 * Make the health bar appear. If called while the health bar is already open,
 * the health displayed will be updated and the show timer will be reset.
 */
void playerDisplayHealth(void)
{
	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->bondhealth;
		g_Vars.currentplayer->oldarmour = playerGetShieldFrac();
		break;
	case HEALTHSHOWMODE_OPENING:
	case HEALTHSHOWMODE_PREVIOUS:
		break;
	case HEALTHSHOWMODE_UPDATING:
	case HEALTHSHOWMODE_CURRENT:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->apparenthealth;
		g_Vars.currentplayer->oldarmour = g_Vars.currentplayer->apparentarmour;
		break;
	case HEALTHSHOWMODE_CLOSING:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->bondhealth;
		g_Vars.currentplayer->oldarmour = playerGetShieldFrac();
		break;
	}

	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		g_Vars.currentplayer->healthshowtime = 0;
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_OPENING;
		break;
	case HEALTHSHOWMODE_OPENING:
	case HEALTHSHOWMODE_PREVIOUS:
		break;
	case HEALTHSHOWMODE_UPDATING:
	case HEALTHSHOWMODE_CURRENT:
		g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updatestartframe;
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_UPDATING;
		break;
	case HEALTHSHOWMODE_CLOSING:
		g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openendframe * playerGetHealthBarHeightFrac();
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_OPENING;
		break;
	}
}

/**
 * Update properties relating to the damage flash and health bar updating.
 */
void playerTickDamageAndHealth(void)
{
	/**
	 * Handle flash of red when the player is damaged.
	 *
	 * damageshowtime is an incrementing timer. It's set to a negative value
	 * normally, 0 when damaged, then ticks up while the flash of red is
	 * visible.
	 *
	 * The player's health is split into 8 equally-sized parts, and the selected
	 * part determines which damage type is used. At lower health, the red flash
	 * and health bar animate faster.
	 */
	if (g_Vars.currentplayer->damageshowtime >= 0.0f) {
		if (g_Vars.currentplayer->damageshowtime == 0) {
			// This is the first frame of damage
			bgunSetSightVisible(GUNSIGHTREASON_DAMAGE, false);
			g_Vars.currentplayer->damagetype = (s32)(playerGetHealthFrac() * 8.0f);

			if (g_Vars.currentplayer->damagetype > DAMAGETYPE_7) {
				g_Vars.currentplayer->damagetype = DAMAGETYPE_7;
			}

			if (g_Vars.currentplayer->damagetype < DAMAGETYPE_0) {
				g_Vars.currentplayer->damagetype = DAMAGETYPE_0;
			}
		}

		if (!g_Vars.currentplayer->isdead
				&& g_Vars.currentplayer->damageshowtime <= g_DamageTypes[g_Vars.currentplayer->damagetype].flashendframe) {
			f32 inc;

			if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
				inc = g_Vars.lvupdate60freal;
			} else {
				inc = g_Vars.diffframe240freal;
			}

			if (inc > 5) {
				inc = 5;
			}

			g_Vars.currentplayer->damageshowtime += inc;

			if (g_Vars.currentplayer->damageshowtime >= g_DamageTypes[g_Vars.currentplayer->damagetype].flashstartframe
					&& g_Vars.currentplayer->damageshowtime <= g_DamageTypes[g_Vars.currentplayer->damagetype].flashendframe) {
				f32 alpha;
				f32 flashdoneframes = g_Vars.currentplayer->damageshowtime - g_DamageTypes[g_Vars.currentplayer->damagetype].flashstartframe;
				f32 flashfullframe = g_DamageTypes[g_Vars.currentplayer->damagetype].flashfullframe;
				f32 totalframes = g_DamageTypes[g_Vars.currentplayer->damagetype].flashendframe - g_DamageTypes[g_Vars.currentplayer->damagetype].flashstartframe;

				if (flashdoneframes < flashfullframe) {
					alpha = g_DamageTypes[g_Vars.currentplayer->damagetype].maxalpha * flashdoneframes / flashfullframe;
				} else {
					alpha = g_DamageTypes[g_Vars.currentplayer->damagetype].maxalpha * (totalframes - flashdoneframes) / (totalframes - flashfullframe);
				}

				playerSetFadeColour(
						g_DamageTypes[g_Vars.currentplayer->damagetype].red,
						g_DamageTypes[g_Vars.currentplayer->damagetype].green,
						g_DamageTypes[g_Vars.currentplayer->damagetype].blue, alpha);
			}
		} else {
			g_Vars.currentplayer->damageshowtime = -1;
			playerSetFadeColour(0xff, 0xff, 0xff, 0);

			if (!g_Vars.currentplayer->isdead) {
				bgunSetSightVisible(GUNSIGHTREASON_DAMAGE, true);
			}
		}
	}

	/**
	 * Handle updating the health bar.
	 *
	 * This works similarly to the damage code above, in that the health bar is
	 * split into 8 parts and the current part is used to look up settings.
	 */
	if (playerIsHealthVisible()) {
		if (g_Vars.currentplayer->healthshowmode == HEALTHSHOWMODE_OPENING) {
			g_Vars.currentplayer->healthdamagetype = (s32)((playerGetHealthFrac() + playerGetShieldFrac()) * 8.0f);

			if (g_Vars.currentplayer->healthdamagetype > DAMAGETYPE_7) {
				g_Vars.currentplayer->healthdamagetype = DAMAGETYPE_7;
			}

			if (g_Vars.currentplayer->healthdamagetype < DAMAGETYPE_0) {
				g_Vars.currentplayer->healthdamagetype = DAMAGETYPE_0;
			}
		}

		if (!g_Vars.currentplayer->isdead) {
			f32 updatedoneframes;
			f32 updateduration;
			f32 frac;
			f32 healthdiff;
			f32 armourdiff;

			switch (g_Vars.currentplayer->healthshowmode) {
			case HEALTHSHOWMODE_OPENING:
				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->oldhealth;
				g_Vars.currentplayer->apparentarmour = g_Vars.currentplayer->oldarmour;
				g_Vars.currentplayer->healthshowtime += g_Vars.diffframe60freal;

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openendframe) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_PREVIOUS;
				}
				break;
			case HEALTHSHOWMODE_PREVIOUS:
				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->oldhealth;
				g_Vars.currentplayer->apparentarmour = g_Vars.currentplayer->oldarmour;
				g_Vars.currentplayer->healthshowtime += g_Vars.diffframe60freal;

				if (currentPlayerIsMenuOpenInSoloOrMp()) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_CURRENT;
				}

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updatestartframe) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_UPDATING;
				}
				break;
			case HEALTHSHOWMODE_UPDATING:
				g_Vars.currentplayer->healthshowtime += g_Vars.diffframe60freal;

				updatedoneframes = g_Vars.currentplayer->healthshowtime - g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updatestartframe;
				updateduration = (f32)g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updateendframe - (f32)g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updatestartframe;
				frac = updatedoneframes / updateduration;

				if (frac < 0) {
					frac = 0;
				}

				if (frac > 1) {
					frac = 1;
				}

				if (currentPlayerIsMenuOpenInSoloOrMp()) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_CURRENT;
				}

				healthdiff = g_Vars.currentplayer->oldhealth - g_Vars.currentplayer->bondhealth;
				armourdiff = g_Vars.currentplayer->oldarmour - playerGetShieldFrac();

				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->oldhealth - frac * healthdiff;
				g_Vars.currentplayer->apparentarmour = g_Vars.currentplayer->oldarmour - frac * armourdiff;

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updateendframe) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_CURRENT;
				}
				break;
			case HEALTHSHOWMODE_CURRENT:
				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->bondhealth;
				g_Vars.currentplayer->apparentarmour = playerGetShieldFrac();
				g_Vars.currentplayer->healthshowtime += g_Vars.diffframe60freal;

				if (currentPlayerIsMenuOpenInSoloOrMp()) {
					g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closestartframe;
				}

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closestartframe
						&& !currentPlayerIsMenuOpenInSoloOrMp()) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_CLOSING;
					g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closestartframe;
				}
				break;
			case HEALTHSHOWMODE_CLOSING:
				g_Vars.currentplayer->healthshowtime += g_Vars.diffframe60freal;

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closeendframe) {
					g_Vars.currentplayer->healthshowtime = -1;
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_HIDDEN;
				}
				break;
			}
		} else {
			g_Vars.currentplayer->healthshowtime = -1;
			g_Vars.currentplayer->healthshowmode = 0;
		}
	}
}

/**
 * Trigger the red flash when the player is damaged.
 *
 * May be called while the red flash is already happening, which may result in
 * the fade being reset to the full alpha point.
 */
void playerDisplayDamage(void)
{
	/**
	 * @bug: This should be using damagetype (not healthdamagetype) as the array
	 * index. These are usually the same value, but I beleive they may be
	 * different if the player has low health with a shield.
	 */
	if (g_Vars.currentplayer->damageshowtime >= g_DamageTypes[g_Vars.currentplayer->healthdamagetype].flashfullframe) {
		g_Vars.currentplayer->damageshowtime = g_DamageTypes[g_Vars.currentplayer->healthdamagetype].flashfullframe;
		return;
	}

	if (g_Vars.currentplayer->damageshowtime < 0) {
		g_Vars.currentplayer->damageshowtime = 0;
	}
}

Gfx *playerRenderHealthBar(Gfx *gdl)
{
	Mtxf matrix;
	Mtxf *addr = gfxAllocateMatrix();

	mtx00016ae4(&matrix, 0, 370, 0, 0, 0, 0, 0, 0, -1);
	mtx00016054(&matrix, addr);

	gSPMatrix(gdl++, osVirtualToPhysical((void *)addr), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetPrimColorViaWord(gdl++, 0, 0, 0xe6e6e600);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	gdl = healthbarDraw(gdl, NULL, 0, 0);

	gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	return gdl;
}

void playerTickExplode(void)
{
	g_Vars.currentplayer->bondcurexplode++;

	if (g_Vars.currentplayer->bondexploding && !g_PlayerInvincible
			&& g_Vars.lvframe60 > g_Vars.currentplayer->bondnextexplode) {
		struct coord pos;

		pos.x = g_Vars.currentplayer->prop->pos.x;
		pos.y = g_Vars.currentplayer->prop->pos.y;
		pos.z = g_Vars.currentplayer->prop->pos.z;

		switch (g_Vars.currentplayer->bondcurexplode % 4) {
		case 0: pos.x += 250.0f + 150.0f * RANDOMFRAC(); break;
		case 1: pos.x -= 250.0f + 150.0f * RANDOMFRAC(); break;
		case 2: pos.z += 250.0f + 150.0f * RANDOMFRAC(); break;
		case 3: pos.z -= 250.0f + 150.0f * RANDOMFRAC(); break;
		}

		pos.y += 200.0f * RANDOMFRAC() - 100.0f;

		explosionCreateSimple(NULL, &pos, g_Vars.currentplayer->prop->rooms, EXPLOSIONTYPE_BONDEXPLODE, g_Vars.currentplayernum);

		g_Vars.currentplayer->bondnextexplode = g_Vars.lvframe60 + TICKS(15) + (random() % TICKS(15));
	}
}

void playerSetHiResEnabled(bool enable)
{
	g_HiResEnabled = enable;
}

s16 playerGetFbWidth(void)
{
	s16 width = g_ViModes[g_ViRes].fbwidth;
	return width;
}

s16 playerGetFbHeight(void)
{
	s16 height = g_ViModes[g_ViRes].fbheight;

	if (g_Vars.fourmeg2player) {
		height = height >> 1;
	}

	return height;
}

s16 playerGetViewportWidth(void)
{
	s16 width;

	if (PLAYERCOUNT() >= 3) {
		// 3/4 players
		width = g_ViModes[g_ViRes].width / 2;

		if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 2) {
			width--;
		}
	} else if (PLAYERCOUNT() == 2) {
		if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || g_Vars.fourmeg2player) {
			// 2 players vsplit
			width = g_ViModes[g_ViRes].width / 2;

			if (g_Vars.currentplayernum == 0) {
				width--;
			}
		} else {
			// 2 players full width
			width = g_ViModes[g_ViRes].width;
		}
	} else {
		// 1 player
		width = g_ViModes[g_ViRes].width;
	}

	return width;
}

s16 playerGetViewportLeft(void)
{
	s32 something = true;
	s16 left;

	if (PLAYERCOUNT() >= 3 && something != 0) {
		if (g_Vars.currentplayernum == 1 || g_Vars.currentplayernum == 3) {
			// 3/4 players - right side
			left = g_ViModes[g_ViRes].width / 2 + g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
		} else {
			// 3/4 players - left side
			left = g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
		}
	} else if (PLAYERCOUNT() == 2 && something != 0) {
		if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || g_Vars.fourmeg2player) {
			if (g_Vars.currentplayernum == 1) {
				// 2 players vsplit - right side
				left = (g_ViModes[g_ViRes].width / 2) + g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
			} else {
				// 2 players vsplit - left side
				left = g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
			}
		} else {
			// 2 players - full width
			left = g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
		}
	} else {
		// Full screen
		left = g_ViModes[g_ViRes].fbwidth - g_ViModes[g_ViRes].width;
	}

	return left;
}

s16 playerGetViewportHeight(void)
{
	s16 height;

	if (PLAYERCOUNT() >= 2) {
		s16 tmp = g_ViModes[g_ViRes].fullheight;

		height = tmp / 2;

		if (PLAYERCOUNT() == 2) {
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				height = tmp;
			} else if (g_Vars.currentplayernum == 0) {
				height--;
			}
		} else if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 1) {
			height--;
		}
	} else {
		if (optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE) {
			height = g_ViModes[g_ViRes].wideheight;
		} else if (optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
			height = g_ViModes[g_ViRes].cinemaheight;
		} else {
			height = g_ViModes[g_ViRes].fullheight;
		}
	}

	return height;
}

#if VERSION >= VERSION_NTSC_1_0
s16 playerGetViewportTop(void)
{
	s16 top;

	if (PLAYERCOUNT() >= 2) {
		top = g_ViModes[g_ViRes].fulltop;

		if (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL || PLAYERCOUNT() != 2) {
			if (PLAYERCOUNT() == 2
					&& g_Vars.currentplayernum == 1
					&& optionsGetScreenSplit() != SCREENSPLIT_VERTICAL
					&& !g_Vars.fourmeg2player) {
				// 2 players hsplit - bottom side
				top = g_ViModes[g_ViRes].fulltop + g_ViModes[g_ViRes].fullheight / 2;
			} else if (g_Vars.currentplayernum == 2 || g_Vars.currentplayernum == 3) {
				// 3/4 players - bottom side
				top = g_ViModes[g_ViRes].fulltop + g_ViModes[g_ViRes].fullheight / 2;
			}
		}
	} else {
		if (optionsGetEffectiveScreenSize() == SCREENSIZE_WIDE) {
			top = g_ViModes[g_ViRes].widetop;
		} else if (optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
			top = g_ViModes[g_ViRes].cinematop;
		} else {
			top = g_ViModes[g_ViRes].fulltop;
		}
	}

	return top;
}
#else
GLOBAL_ASM(
glabel playerGetViewportTop
/*  f0baad4:	3c07800a */ 	lui	$a3,0x800a
/*  f0baad8:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f0baadc:	8cee006c */ 	lw	$t6,0x6c($a3)
/*  f0baae0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0baae4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0baae8:	11c00003 */ 	beqz	$t6,.NB0f0baaf8
/*  f0baaec:	00003025 */ 	or	$a2,$zero,$zero
/*  f0baaf0:	10000001 */ 	beqz	$zero,.NB0f0baaf8
/*  f0baaf4:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f0baaf8:
/*  f0baaf8:	8cef0068 */ 	lw	$t7,0x68($a3)
/*  f0baafc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0bab00:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bab04:	11e00003 */ 	beqz	$t7,.NB0f0bab14
/*  f0bab08:	00001025 */ 	or	$v0,$zero,$zero
/*  f0bab0c:	10000001 */ 	beqz	$zero,.NB0f0bab14
/*  f0bab10:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0bab14:
/*  f0bab14:	8cf80064 */ 	lw	$t8,0x64($a3)
/*  f0bab18:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0bab1c:	13000003 */ 	beqz	$t8,.NB0f0bab2c
/*  f0bab20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bab24:	10000001 */ 	beqz	$zero,.NB0f0bab2c
/*  f0bab28:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0bab2c:
/*  f0bab2c:	8cf90070 */ 	lw	$t9,0x70($a3)
/*  f0bab30:	13200003 */ 	beqz	$t9,.NB0f0bab40
/*  f0bab34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bab38:	10000001 */ 	beqz	$zero,.NB0f0bab40
/*  f0bab3c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0bab40:
/*  f0bab40:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0bab44:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0bab48:	01465821 */ 	addu	$t3,$t2,$a2
/*  f0bab4c:	29610002 */ 	slti	$at,$t3,0x2
/*  f0bab50:	14200074 */ 	bnez	$at,.NB0f0bad24
/*  f0bab54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bab58:	8d8c2e24 */ 	lw	$t4,0x2e24($t4)
/*  f0bab5c:	3c0d8006 */ 	lui	$t5,0x8006
/*  f0bab60:	11800004 */ 	beqz	$t4,.NB0f0bab74
/*  f0bab64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bab68:	8dadf2f0 */ 	lw	$t5,-0xd10($t5)
/*  f0bab6c:	11a0006d */ 	beqz	$t5,.NB0f0bad24
/*  f0bab70:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0bab74:
/*  f0bab74:	0fc3e4d2 */ 	jal	menuGetRoot
/*  f0bab78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bab7c:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0bab80:	10410068 */ 	beq	$v0,$at,.NB0f0bad24
/*  f0bab84:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0bab88:	8dce2d88 */ 	lw	$t6,0x2d88($t6)
/*  f0bab8c:	3c058007 */ 	lui	$a1,0x8007
/*  f0bab90:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bab94:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bab98:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bab9c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0baba0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0baba4:	00af2821 */ 	addu	$a1,$a1,$t7
/*  f0baba8:	84a52c9a */ 	lh	$a1,0x2c9a($a1)
/*  f0babac:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f0babb0:	a7a5001e */ 	sh	$a1,0x1e($sp)
/*  f0babb4:	3c07800a */ 	lui	$a3,0x800a
/*  f0babb8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0babbc:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f0babc0:	110200fa */ 	beq	$t0,$v0,.NB0f0bafac
/*  f0babc4:	87a5001e */ 	lh	$a1,0x1e($sp)
/*  f0babc8:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*  f0babcc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0babd0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0babd4:	13000003 */ 	beqz	$t8,.NB0f0babe4
/*  f0babd8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0babdc:	10000001 */ 	beqz	$zero,.NB0f0babe4
/*  f0babe0:	01003025 */ 	or	$a2,$t0,$zero
.NB0f0babe4:
/*  f0babe4:	8cf90068 */ 	lw	$t9,0x68($a3)
/*  f0babe8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0babec:	00001025 */ 	or	$v0,$zero,$zero
/*  f0babf0:	13200003 */ 	beqz	$t9,.NB0f0bac00
/*  f0babf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0babf8:	10000001 */ 	beqz	$zero,.NB0f0bac00
/*  f0babfc:	01002025 */ 	or	$a0,$t0,$zero
.NB0f0bac00:
/*  f0bac00:	8ce90064 */ 	lw	$t1,0x64($a3)
/*  f0bac04:	11200003 */ 	beqz	$t1,.NB0f0bac14
/*  f0bac08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bac0c:	10000001 */ 	beqz	$zero,.NB0f0bac14
/*  f0bac10:	01001825 */ 	or	$v1,$t0,$zero
.NB0f0bac14:
/*  f0bac14:	8cea0070 */ 	lw	$t2,0x70($a3)
/*  f0bac18:	11400003 */ 	beqz	$t2,.NB0f0bac28
/*  f0bac1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bac20:	10000001 */ 	beqz	$zero,.NB0f0bac28
/*  f0bac24:	01001025 */ 	or	$v0,$t0,$zero
.NB0f0bac28:
/*  f0bac28:	00435821 */ 	addu	$t3,$v0,$v1
/*  f0bac2c:	01646021 */ 	addu	$t4,$t3,$a0
/*  f0bac30:	01866821 */ 	addu	$t5,$t4,$a2
/*  f0bac34:	55a10023 */ 	bnel	$t5,$at,.NB0f0bacc4
/*  f0bac38:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bac3c:	8cee028c */ 	lw	$t6,0x28c($a3)
/*  f0bac40:	550e0020 */ 	bnel	$t0,$t6,.NB0f0bacc4
/*  f0bac44:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bac48:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f0bac4c:	a7a5001e */ 	sh	$a1,0x1e($sp)
/*  f0bac50:	3c07800a */ 	lui	$a3,0x800a
/*  f0bac54:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0bac58:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f0bac5c:	11020018 */ 	beq	$t0,$v0,.NB0f0bacc0
/*  f0bac60:	87a5001e */ 	lh	$a1,0x1e($sp)
/*  f0bac64:	90ef04e0 */ 	lbu	$t7,0x4e0($a3)
/*  f0bac68:	3c188007 */ 	lui	$t8,0x8007
/*  f0bac6c:	55e00015 */ 	bnezl	$t7,.NB0f0bacc4
/*  f0bac70:	8ce2028c */ 	lw	$v0,0x28c($a3)
/*  f0bac74:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f0bac78:	3c098007 */ 	lui	$t1,0x8007
/*  f0bac7c:	25292c80 */ 	addiu	$t1,$t1,0x2c80
/*  f0bac80:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0bac84:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bac88:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bac8c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bac90:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bac94:	03291021 */ 	addu	$v0,$t9,$t1
/*  f0bac98:	8c4a0014 */ 	lw	$t2,0x14($v0)
/*  f0bac9c:	8c4c0018 */ 	lw	$t4,0x18($v0)
/*  f0baca0:	05410003 */ 	bgez	$t2,.NB0f0bacb0
/*  f0baca4:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f0baca8:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0bacac:	00015843 */ 	sra	$t3,$at,0x1
.NB0f0bacb0:
/*  f0bacb0:	016c2821 */ 	addu	$a1,$t3,$t4
/*  f0bacb4:	00056c00 */ 	sll	$t5,$a1,0x10
/*  f0bacb8:	100000bc */ 	beqz	$zero,.NB0f0bafac
/*  f0bacbc:	000d2c03 */ 	sra	$a1,$t5,0x10
.NB0f0bacc0:
/*  f0bacc0:	8ce2028c */ 	lw	$v0,0x28c($a3)
.NB0f0bacc4:
/*  f0bacc4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bacc8:	10410002 */ 	beq	$v0,$at,.NB0f0bacd4
/*  f0baccc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0bacd0:	144100b6 */ 	bne	$v0,$at,.NB0f0bafac
.NB0f0bacd4:
/*  f0bacd4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0bacd8:	8def2d88 */ 	lw	$t7,0x2d88($t7)
/*  f0bacdc:	3c198007 */ 	lui	$t9,0x8007
/*  f0bace0:	27392c80 */ 	addiu	$t9,$t9,0x2c80
/*  f0bace4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bace8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bacec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bacf0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bacf4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bacf8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0bacfc:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0bad00:	8c4b0018 */ 	lw	$t3,0x18($v0)
/*  f0bad04:	05210003 */ 	bgez	$t1,.NB0f0bad14
/*  f0bad08:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0bad0c:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0bad10:	00015043 */ 	sra	$t2,$at,0x1
.NB0f0bad14:
/*  f0bad14:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f0bad18:	00056400 */ 	sll	$t4,$a1,0x10
/*  f0bad1c:	100000a3 */ 	beqz	$zero,.NB0f0bafac
/*  f0bad20:	000c2c03 */ 	sra	$a1,$t4,0x10
.NB0f0bad24:
/*  f0bad24:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f0bad28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bad2c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0bad30:	14480046 */ 	bne	$v0,$t0,.NB0f0bae4c
/*  f0bad34:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0bad38:	8dce2e24 */ 	lw	$t6,0x2e24($t6)
/*  f0bad3c:	11c00038 */ 	beqz	$t6,.NB0f0bae20
/*  f0bad40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bad44:	0fc53402 */ 	jal	optionsGetCutsceneSubtitles
/*  f0bad48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bad4c:	3c07800a */ 	lui	$a3,0x800a
/*  f0bad50:	10400033 */ 	beqz	$v0,.NB0f0bae20
/*  f0bad54:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f0bad58:	8cef04b4 */ 	lw	$t7,0x4b4($a3)
/*  f0bad5c:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0bad60:	3c18800a */ 	lui	$t8,0x800a
/*  f0bad64:	11e1002e */ 	beq	$t7,$at,.NB0f0bae20
/*  f0bad68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bad6c:	8f18260c */ 	lw	$t8,0x260c($t8)
/*  f0bad70:	3c198007 */ 	lui	$t9,0x8007
/*  f0bad74:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0bad78:	1b00001e */ 	blez	$t8,.NB0f0badf4
/*  f0bad7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bad80:	8f392d88 */ 	lw	$t9,0x2d88($t9)
/*  f0bad84:	254a2c80 */ 	addiu	$t2,$t2,0x2c80
/*  f0bad88:	3c01800a */ 	lui	$at,0x800a
/*  f0bad8c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0bad90:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0bad94:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0bad98:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0bad9c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0bada0:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f0bada4:	8c4b0018 */ 	lw	$t3,0x18($v0)
/*  f0bada8:	8c4c0020 */ 	lw	$t4,0x20($v0)
/*  f0badac:	c42c2610 */ 	lwc1	$f12,0x2610($at)
/*  f0badb0:	448b2000 */ 	mtc1	$t3,$f4
/*  f0badb4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0badb8:	44814000 */ 	mtc1	$at,$f8
/*  f0badbc:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0badc0:	448c3000 */ 	mtc1	$t4,$f6
/*  f0badc4:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f0badc8:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0badcc:	46005002 */ 	mul.s	$f0,$f10,$f0
/*  f0badd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0badd4:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0badd8:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f0baddc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0bade0:	44059000 */ 	mfc1	$a1,$f18
/*  f0bade4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bade8:	00057400 */ 	sll	$t6,$a1,0x10
/*  f0badec:	1000006f */ 	beqz	$zero,.NB0f0bafac
/*  f0badf0:	000e2c03 */ 	sra	$a1,$t6,0x10
.NB0f0badf4:
/*  f0badf4:	3c188007 */ 	lui	$t8,0x8007
/*  f0badf8:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f0badfc:	3c058007 */ 	lui	$a1,0x8007
/*  f0bae00:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0bae04:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bae08:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bae0c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0bae10:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0bae14:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f0bae18:	10000064 */ 	beqz	$zero,.NB0f0bafac
/*  f0bae1c:	84a52c9a */ 	lh	$a1,0x2c9a($a1)
.NB0f0bae20:
/*  f0bae20:	3c098007 */ 	lui	$t1,0x8007
/*  f0bae24:	8d292d88 */ 	lw	$t1,0x2d88($t1)
/*  f0bae28:	3c058007 */ 	lui	$a1,0x8007
/*  f0bae2c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0bae30:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0bae34:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bae38:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0bae3c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bae40:	00aa2821 */ 	addu	$a1,$a1,$t2
/*  f0bae44:	10000059 */ 	beqz	$zero,.NB0f0bafac
/*  f0bae48:	84a52ca2 */ 	lh	$a1,0x2ca2($a1)
.NB0f0bae4c:
/*  f0bae4c:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f0bae50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bae54:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0bae58:	1441000c */ 	bne	$v0,$at,.NB0f0bae8c
/*  f0bae5c:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0bae60:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0bae64:	8d6b2d88 */ 	lw	$t3,0x2d88($t3)
/*  f0bae68:	3c058007 */ 	lui	$a1,0x8007
/*  f0bae6c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0bae70:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bae74:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bae78:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0bae7c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0bae80:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f0bae84:	10000049 */ 	beqz	$zero,.NB0f0bafac
/*  f0bae88:	84a52caa */ 	lh	$a1,0x2caa($a1)
.NB0f0bae8c:
/*  f0bae8c:	8dad2e24 */ 	lw	$t5,0x2e24($t5)
/*  f0bae90:	3c0e800a */ 	lui	$t6,0x800a
/*  f0bae94:	11a0003a */ 	beqz	$t5,.NB0f0baf80
/*  f0bae98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0bae9c:	8dce2780 */ 	lw	$t6,0x2780($t6)
/*  f0baea0:	15c00037 */ 	bnez	$t6,.NB0f0baf80
/*  f0baea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0baea8:	0fc53402 */ 	jal	optionsGetCutsceneSubtitles
/*  f0baeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0baeb0:	3c07800a */ 	lui	$a3,0x800a
/*  f0baeb4:	10400004 */ 	beqz	$v0,.NB0f0baec8
/*  f0baeb8:	24e7e6c0 */ 	addiu	$a3,$a3,-6464
/*  f0baebc:	8cef04b4 */ 	lw	$t7,0x4b4($a3)
/*  f0baec0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0baec4:	15e1002e */ 	bne	$t7,$at,.NB0f0baf80
.NB0f0baec8:
/*  f0baec8:	3c18800a */ 	lui	$t8,0x800a
/*  f0baecc:	8f18260c */ 	lw	$t8,0x260c($t8)
/*  f0baed0:	3c198007 */ 	lui	$t9,0x8007
/*  f0baed4:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0baed8:	1b00001e */ 	blez	$t8,.NB0f0baf54
/*  f0baedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0baee0:	8f392d88 */ 	lw	$t9,0x2d88($t9)
/*  f0baee4:	254a2c80 */ 	addiu	$t2,$t2,0x2c80
/*  f0baee8:	3c01800a */ 	lui	$at,0x800a
/*  f0baeec:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0baef0:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0baef4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0baef8:	01394823 */ 	subu	$t1,$t1,$t9
/*  f0baefc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0baf00:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f0baf04:	8c4b0020 */ 	lw	$t3,0x20($v0)
/*  f0baf08:	8c4c0018 */ 	lw	$t4,0x18($v0)
/*  f0baf0c:	c42c2610 */ 	lwc1	$f12,0x2610($at)
/*  f0baf10:	448b2000 */ 	mtc1	$t3,$f4
/*  f0baf14:	3c013f80 */ 	lui	$at,0x3f80
/*  f0baf18:	44814000 */ 	mtc1	$at,$f8
/*  f0baf1c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0baf20:	448c3000 */ 	mtc1	$t4,$f6
/*  f0baf24:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f0baf28:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0baf2c:	46005002 */ 	mul.s	$f0,$f10,$f0
/*  f0baf30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0baf34:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0baf38:	46020400 */ 	add.s	$f16,$f0,$f2
/*  f0baf3c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0baf40:	44059000 */ 	mfc1	$a1,$f18
/*  f0baf44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0baf48:	00057400 */ 	sll	$t6,$a1,0x10
/*  f0baf4c:	10000017 */ 	beqz	$zero,.NB0f0bafac
/*  f0baf50:	000e2c03 */ 	sra	$a1,$t6,0x10
.NB0f0baf54:
/*  f0baf54:	3c188007 */ 	lui	$t8,0x8007
/*  f0baf58:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f0baf5c:	3c058007 */ 	lui	$a1,0x8007
/*  f0baf60:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0baf64:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0baf68:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0baf6c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0baf70:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0baf74:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f0baf78:	1000000c */ 	beqz	$zero,.NB0f0bafac
/*  f0baf7c:	84a52ca2 */ 	lh	$a1,0x2ca2($a1)
.NB0f0baf80:
/*  f0baf80:	3c098007 */ 	lui	$t1,0x8007
/*  f0baf84:	8d292d88 */ 	lw	$t1,0x2d88($t1)
/*  f0baf88:	3c028007 */ 	lui	$v0,0x8007
/*  f0baf8c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0baf90:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0baf94:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0baf98:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0baf9c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0bafa0:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f0bafa4:	10000002 */ 	beqz	$zero,.NB0f0bafb0
/*  f0bafa8:	84422c9a */ 	lh	$v0,0x2c9a($v0)
.NB0f0bafac:
/*  f0bafac:	00a01025 */ 	or	$v0,$a1,$zero
.NB0f0bafb0:
/*  f0bafb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0bafb4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0bafb8:	03e00008 */ 	jr	$ra
/*  f0bafbc:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

f32 player0f0bd358(void)
{
	f32 result;
	s16 stack;
	s16 height = playerGetViewportHeight();
	s16 width = playerGetViewportWidth();

	result = (f32)width / (f32)height;
	result = g_ViModes[g_ViRes].yscale * result;

	return result;
}

void playerUpdateShake(void)
{
	struct coord coord = {0, 0, 0};

	if (g_Vars.currentplayer->isdead == false) {
		explosionsUpdateShake(&g_Vars.currentplayer->bond2.unk10, &g_Vars.currentplayer->bond2.unk1c, &coord);
	} else {
		viShake(0);
	}
}

void playerLaunchSlayerRocket(struct weaponobj *rocket)
{
	g_Vars.currentplayer->slayerrocket = rocket;
	g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKET;

	// Turn off these devices
	g_Vars.currentplayer->devicesactive &= ~(
			DEVICE_NIGHTVISION |
			DEVICE_XRAYSCANNER |
			DEVICE_IRSCANNER);

	g_Vars.currentplayer->badrockettime = 0;
}

void playerTickTeleport(f32 *aspectratio)
{
	if (g_Vars.currentplayer->teleportstate) {
		// empty
	}

	// State 1: TELEPORTSTATE_PREENTER
	// Wait in this state for 24 ticks
	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_PREENTER) {
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate60;

		if (time >= 24) {
			g_Vars.currentplayer->teleporttime = 0;
			g_Vars.currentplayer->teleportstate = TELEPORTSTATE_ENTERING;
		} else {
			g_Vars.currentplayer->teleporttime = time;
		}
	}

	// State 2: TELEPORTSTATE_ENTERING
	// Adjust aspect ratio over 48 ticks
	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate60;

		if (g_Vars.currentplayer->teleporttime == 48) {
			g_Vars.currentplayer->teleportstate = TELEPORTSTATE_WHITE;
			g_Vars.currentplayer->teleporttime = 0;
		} else if (time >= 48) {
			g_Vars.currentplayer->teleporttime = 48;
		} else {
			f32 tmp = 1 - cosf((time / 48.0f) * M_PI * 0.5f);
			g_Vars.currentplayer->teleporttime = time;
			*aspectratio = *aspectratio / (1.0f + 4.0f * tmp);
		}
	}

	// State 3: TELEPORTSTATE_WHITE
	// Wait indefinitely for AI scripting to progress it to state 4

	// State 4: TELEPORTSTATE_EXITING
	// Adjust aspect ratio over 48 ticks, but with slightly faster
	// time progression in the first several ticks.
	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_EXITING) {
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate60;

		if (g_Vars.currentplayer->teleporttime < 7) {
			time = g_Vars.currentplayer->teleporttime + 1;
		}

		if (time >= 48) {
			g_Vars.currentplayer->teleporttime = 0;
			g_Vars.currentplayer->teleportstate = TELEPORTSTATE_INACTIVE;
		} else {
			f32 tmp = 1 - cosf(((47 - time) / 48.0f) * M_PI * 0.5f);
			g_Vars.currentplayer->teleporttime = time;
			*aspectratio = *aspectratio * (1.0f + 4.0f * tmp);
		}
	}

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		f32 fovy = playerGetTeleportFovY();
		playermgrSetFovY(fovy);
		viSetFovY(fovy);
	}
}

void playerConfigureVi(void)
{
	f32 ratio = player0f0bd358();
	g_ViRes = VIRES_LO;

	text0f1531dc(false);

#if VERSION >= VERSION_JPN_FINAL
	var800800f0jf = 0;
#endif

	playermgrSetFovY(60);
	playermgrSetAspectRatio(ratio);
	playermgrSetViewSize(playerGetViewportWidth(), playerGetViewportHeight());
	playermgrSetViewPosition(playerGetViewportLeft(), playerGetViewportTop());

	viSetMode(g_ViModes[g_ViRes].xscale);

	viSetFovAspectAndSize(60, ratio, playerGetViewportWidth(), playerGetViewportHeight());

	viSetViewPosition(playerGetViewportLeft(), playerGetViewportTop());
	viSetSize(playerGetFbWidth(), playerGetFbHeight());
	viSetBufSize(playerGetFbWidth(), playerGetFbHeight());
}

void playerTick(bool arg0)
{
	f32 aspectratio;
	f32 f20;

	g_ViRes = g_HiResEnabled;

#if PAL
	text0f1531dc(false);
#else
	if (g_ViRes == VIRES_HI) {
		text0f1531dc(true);
	} else {
		text0f1531dc(false);
	}
#endif

#if VERSION >= VERSION_JPN_FINAL
	var800800f0jf = 0;
#endif

	if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
		aspectratio = player0f0bd358() * 1.33333333f;
	} else {
		aspectratio = player0f0bd358();
	}

#if PAL
	aspectratio *= 1.1904761791229f;
#endif

	mainOverrideVariable("tps", &var8007083c);

	if (var8007083c != TELEPORTSTATE_INACTIVE) {
		var8007083c = TELEPORTSTATE_INACTIVE;
		g_Vars.currentplayer->teleporttime = 0;
		g_Vars.currentplayer->teleportstate = TELEPORTSTATE_PREENTER;
	}

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		playerTickTeleport(&aspectratio);
	}

	if (g_Vars.stagenum == STAGE_TEST_OLD && func0f01ad5c()) {
		func0f01adb8();
		return;
	}

	playermgrSetFovY(60);
	playermgrSetAspectRatio(aspectratio);
	playermgrSetViewSize(playerGetViewportWidth(), playerGetViewportHeight());
	playermgrSetViewPosition(playerGetViewportLeft(), playerGetViewportTop());

	viSetMode(g_ViModes[g_ViRes].xscale);
	viSetFovAspectAndSize(60, aspectratio, playerGetViewportWidth(), playerGetViewportHeight());
	viSetViewPosition(playerGetViewportLeft(), playerGetViewportTop());
	viSetSize(playerGetFbWidth(), playerGetFbHeight());
	viSetBufSize(playerGetFbWidth(), playerGetFbHeight());

	playerUpdateColourScreenProperties();
	playerTickChrFade();

	bmoveSetAutoAimY(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
	bmoveSetAutoAimX(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
	bmoveSetAutoMoveCentreEnabled(optionsGetLookAhead(g_Vars.currentplayerstats->mpindex));
	bgunSetGunAmmoVisible(GUNAMMOREASON_OPTION, optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex));
	bgunSetSightVisible(GUNSIGHTREASON_1, true);

	if ((g_Vars.tickmode == TICKMODE_GE_FADEIN || g_Vars.tickmode == TICKMODE_NORMAL) && !g_MainIsEndscreen) {
		g_Vars.currentplayer->bondviewlevtime60 += g_Vars.lvupdate60;
	}

	if (g_Vars.currentplayer->devicesactive & DEVICE_SUICIDEPILL) {
		playerDieByShooter(g_Vars.currentplayernum, true);
	}

	playerTickDamageAndHealth();
	playerTickExplode();

	if (lvIsPaused()) {
		playerStopAudioForPause();
	}

	if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
		playerTickPauseMenu();
	}

	if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET) {
		if (g_Vars.currentplayer->slayerrocket == NULL || g_Vars.currentplayer->isdead) {
			g_Vars.currentplayer->slayerrocket = NULL;
#if VERSION >= VERSION_NTSC_1_0
			g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
#else
			g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
#endif
		}
	}

	if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
		// Deep Sea teleport
		playerTickChrBody();
		g_WarpType1Pad = g_Vars.currentplayer->teleportcamerapad;
		bmoveTick(0, 0, 0, 1);
		playerExecutePreparedWarp();
	} else if (g_Vars.currentplayer->visionmode == (u32)VISIONMODE_SLAYERROCKET) {
		// Controlling a Slayer rocket
		struct coord rocketpos = {0, 0, 0};
		struct coord sp2f0 = {0, 0, 1};
		struct coord sp2e4 = {0, 1, 0};

		bool rocketok = false;
		struct weaponobj *rocket = g_Vars.currentplayer->slayerrocket;

		playerSetCameraMode(CAMERAMODE_THIRDPERSON);
		playerTickChrBody();
		bmoveTick(0, 0, 0, 1);
		playerUpdateShake();

		if (rocket && rocket->base.prop) {
			f32 sp2b8[3][3];
			struct coord sp2ac;
			f32 sp2a8 = sqrtf(
					rocket->base.realrot[0][0] * rocket->base.realrot[0][0] +
					rocket->base.realrot[1][0] * rocket->base.realrot[1][0] +
					rocket->base.realrot[2][0] * rocket->base.realrot[2][0]);
			s16 inrooms[21];
			s16 aboverooms[21];
			s16 bestroom;
			s16 outofbounds = false;

			sp2b8[0][0] = rocket->base.realrot[0][0] / sp2a8;
			sp2b8[0][1] = rocket->base.realrot[0][1] / sp2a8;
			sp2b8[0][2] = rocket->base.realrot[0][2] / sp2a8;
			sp2b8[1][0] = rocket->base.realrot[1][0] / sp2a8;
			sp2b8[1][1] = rocket->base.realrot[1][1] / sp2a8;
			sp2b8[1][2] = rocket->base.realrot[1][2] / sp2a8;
			sp2b8[2][0] = rocket->base.realrot[2][0] / sp2a8;
			sp2b8[2][1] = rocket->base.realrot[2][1] / sp2a8;
			sp2b8[2][2] = rocket->base.realrot[2][2] / sp2a8;

			rocketpos.x = rocket->base.prop->pos.x;
			rocketpos.y = rocket->base.prop->pos.y;
			rocketpos.z = rocket->base.prop->pos.z;

			bgFindRoomsByPos(&rocketpos, inrooms, aboverooms, 20, &bestroom);

			if (inrooms[0] == -1) {
				outofbounds = true;
			}

			if (outofbounds) {
				// Slayer rocket has flown out of bounds
				// Allow 2 seconds of this, then blow up rocket
				g_Vars.currentplayer->badrockettime += g_Vars.lvupdate60;

				if (g_Vars.currentplayer->badrockettime > TICKS(120)) {
#if VERSION >= VERSION_NTSC_1_0
					g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
#else
					g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
#endif
				}
			} else if (g_Vars.currentplayer->badrockettime > 0) {
				// Slayer rocket is in bounds, but was recently out
				g_Vars.currentplayer->badrockettime -= g_Vars.lvupdate60;

				if (g_Vars.currentplayer->badrockettime < 0) {
					g_Vars.currentplayer->badrockettime = 0;
				}
			}

			mtx00016208(sp2b8, &sp2f0);
			mtx00016208(sp2b8, &sp2e4);

			if (rocket->base.hidden & OBJHFLAG_PROJECTILE) {
				struct projectile *projectile = rocket->base.projectile;
				u32 mode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
				f32 targetspeed;
				s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
				s8 contpad2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
				s8 stickx = 0;
				s8 sticky = 0;
				Mtxf sp1fc;
				Mtxf sp1bc;
				Mtxf sp17c;
				f32 sp178;
				f32 sp174;
				f32 sp15c[6];
				f32 sp14c[4];
				f32 sp13c[4];
				f32 sp12c[4];
				f32 prevspeed;
#ifdef AVOID_UB
				f32 sp11c[4];
#else
				f32 sp11c[3];
#endif
				bool explode = false;
				bool slow = false;
				bool pause = false;
				f32 newspeed;

				if (mode == CONTROLMODE_23
						|| mode == CONTROLMODE_24
						|| mode == CONTROLMODE_22
						|| mode == CONTROLMODE_21) {
					if (g_PlayersWithControl[g_Vars.currentplayernum]) {
						if (mode == CONTROLMODE_21 || mode == CONTROLMODE_22) {
							if (joyGetButtons(contpad1, A_BUTTON | B_BUTTON)
									|| joyGetButtons(contpad2, A_BUTTON | B_BUTTON)
									|| joyGetButtons(contpad2, Z_TRIG)) {
								slow = true;
							}

							if (joyGetButtonsPressedThisFrame(contpad1, Z_TRIG)) {
								explode = true;
							}
						} else {
							if (joyGetButtons(contpad1, A_BUTTON | B_BUTTON)
									|| joyGetButtons(contpad2, A_BUTTON | B_BUTTON)
									|| joyGetButtons(contpad1, Z_TRIG)) {
								slow = true;
							}

							if (joyGetButtonsPressedThisFrame(contpad2, Z_TRIG)) {
								explode = true;
							}
						}

						stickx = joyGetStickX(contpad1);
						sticky = joyGetStickY(contpad1);
					} else {
						slow = true;
					}

					if (joyGetButtons(contpad1, START_BUTTON) || joyGetButtons(contpad2, START_BUTTON)) {
						pause = true;
					}
				} else {
					if (g_PlayersWithControl[g_Vars.currentplayernum]) {
						if (mode == CONTROLMODE_13 || mode == CONTROLMODE_14) {
							if (joyGetButtonsPressedThisFrame(contpad1, A_BUTTON)) {
								explode = true;
							}

							if (joyGetButtons(contpad1, B_BUTTON | Z_TRIG | 0 | R_TRIG)) {
								slow = true;
							}
						} else {
							if (joyGetButtonsPressedThisFrame(contpad1, Z_TRIG)) {
								explode = true;
							}

							if (joyGetButtons(contpad1, A_BUTTON | B_BUTTON | 0 | R_TRIG)) {
								slow = true;
							}
						}

						stickx = joyGetStickX(contpad1);
						sticky = joyGetStickY(contpad1);
					} else {
						slow = true;
					}

					if (joyGetButtons(contpad1, START_BUTTON)) {
						pause = true;
					}
				}

				if (pause) {
					if (g_Vars.mplayerisrunning == false) {
						playerPause(MENUROOT_MAINMENU);
					} else {
						mpPushPauseDialog();
					}
				}

				rocketok = true;
				sp2ac.x = sp2b8[0][0];
				sp2ac.z = sp2b8[0][2];

				sp178 = sticky * LVUPDATE60FREAL() * 0.00025f;
				sp174 = -stickx * LVUPDATE60FREAL() * 0.00025f;

				f20 = sqrtf(sp2ac.f[0] * sp2ac.f[0] + sp2ac.f[2] * sp2ac.f[2]);

				sp2ac.x /= f20;
				sp2ac.z /= f20;

				f20 = sinf(sp178);

				sp14c[0] = cosf(sp178);
				sp14c[1] = sp2ac.f[0] * f20;
				sp14c[2] = 0;
				sp14c[3] = sp2ac.f[2] * f20;

				f20 = sinf(sp174);

				sp15c[0] = cosf(sp174);
				sp15c[1] = 0;
				sp15c[2] = sp2b8[1][1] >= 0 ? f20 : -f20;
				sp15c[3] = 0;

				quaternionMultQuaternion(sp15c, sp14c, sp13c);
				quaternionToMtx(sp13c, &sp1fc);
				mtx4RotateVecInPlace(&sp1fc, &projectile->speed);

				projectile->powerlimit240 = -1;
				projectile->flags |= PROJECTILEFLAG_NOTIMELIMIT;
				projectile->unk018 = 0;
				projectile->unk014 = 0;
				projectile->unk010 = 0;

				if ((projectile->flags & PROJECTILEFLAG_LAUNCHING) == 0) {
					projectile->ownerprop = NULL;
				}

				if (explode) {
					rocket->team = TEAM_00;
				}

				prevspeed = sqrtf(
						projectile->speed.f[0] * projectile->speed.f[0] +
						projectile->speed.f[1] * projectile->speed.f[1] +
						projectile->speed.f[2] * projectile->speed.f[2]);

				if (slow) {
					targetspeed = 1;
				} else {
					targetspeed = 12;
				}

				newspeed = prevspeed;

				if (prevspeed < targetspeed) {
					newspeed = prevspeed + 0.05f * LVUPDATE60FREAL();

					if (newspeed > targetspeed) {
						newspeed = targetspeed;
					}
				} else if (prevspeed > targetspeed) {
					newspeed = prevspeed - 0.05f * LVUPDATE60FREAL();

					if (newspeed < targetspeed) {
						newspeed = targetspeed;
					}
				}

				projectile->speed.x = (projectile->speed.x * newspeed) / prevspeed;
				projectile->speed.y = (projectile->speed.y * newspeed) / prevspeed;
				projectile->speed.z = (projectile->speed.z * newspeed) / prevspeed;

				mtx3ToMtx4(sp2b8, &sp1bc);
				quaternion0f097044(&sp1bc, sp12c);
				quaternionMultQuaternion(sp13c, sp12c, sp11c);
				quaternionToMtx(sp11c, &sp17c);
				mtx4ToMtx3(&sp17c, sp2b8);

				rocket->base.realrot[0][0] = sp2b8[0][0] * sp2a8;
				rocket->base.realrot[0][1] = sp2b8[0][1] * sp2a8;
				rocket->base.realrot[0][2] = sp2b8[0][2] * sp2a8;
				rocket->base.realrot[1][0] = sp2b8[1][0] * sp2a8;
				rocket->base.realrot[1][1] = sp2b8[1][1] * sp2a8;
				rocket->base.realrot[1][2] = sp2b8[1][2] * sp2a8;
				rocket->base.realrot[2][0] = sp2b8[2][0] * sp2a8;
				rocket->base.realrot[2][1] = sp2b8[2][1] * sp2a8;
				rocket->base.realrot[2][2] = sp2b8[2][2] * sp2a8;
			}
		}

		if (!rocketok) {
			g_Vars.currentplayer->slayerrocket = NULL;
#if VERSION >= VERSION_NTSC_1_0
			g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
#else
			g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
#endif
		}

		g_Vars.currentplayer->waitforzrelease = true;

		if (rocket && rocket->base.prop) {
			player0f0c1840(&rocketpos, &sp2e4, &sp2f0, &rocket->base.prop->pos, rocket->base.prop->rooms);
		} else {
			player0f0c1840(&rocketpos, &sp2e4, &sp2f0, NULL, NULL);
		}
	} else if (g_Vars.tickmode == TICKMODE_NORMAL) {
		// Normal movement
		f32 a = 0;
		f32 b = 0;
		f32 c = 0;
		struct coord spf4;
		struct prop *prop;
		struct chrdata *chr;
		s32 i;

		if (g_PlayersWithControl[g_Vars.currentplayernum]) {
			bmoveTick(1, 1, arg0, 0);
		} else {
			bmoveTick(0, 0, 0, 1);
		}

		playerUpdateShake();
		playerSetCameraMode(CAMERAMODE_DEFAULT);

		spf4.x = g_Vars.currentplayer->bond2.unk10.x;
		spf4.y = g_Vars.currentplayer->bond2.unk10.y;
		spf4.z = g_Vars.currentplayer->bond2.unk10.z;

		spf4.x = a + spf4.x;
		spf4.y = b + spf4.y;
		spf4.z = c + spf4.z;

		player0f0c1840(&spf4,
				&g_Vars.currentplayer->bond2.unk28,
				&g_Vars.currentplayer->bond2.unk1c,
				&g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms);
	} else if (g_Vars.tickmode == TICKMODE_MPSWIRL) {
		// Start of an MP match where the camera circles around the player
		playerTickChrBody();
		bmoveTick(0, 0, 0, 1);
		playerTickMpSwirl();
	}

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
	if (debug0f11990cnb()) {
		debug0f119a14nb();
	}
#endif

	// Increment the time on Bond's watch (leftover from GE)
	g_Vars.currentplayer->bondwatchtime60 += g_Vars.diffframe60freal;

	// Also a leftover from GE? Maybe cancelling fade in mission intros?
	if (var8007074c) {
		s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);

		if (!lvIsPaused()
				&& arg0
				&& joyGetButtonsPressedThisFrame(contpad1, A_BUTTON | B_BUTTON | Z_TRIG | START_BUTTON | 0 | R_TRIG)) {
			var8007074c = 2;

			if (playerIsFadeComplete()) {
				if (g_Vars.currentplayer->colourscreenfrac == 0) {
					playerSetFadeColour(0, 0, 0, 0);
					playerSetFadeFrac(60, 1);
				}
			} else {
				if (g_Vars.currentplayer->colourfadefracnew == 0) {
					playerSetFadeFrac(g_Vars.currentplayer->colourfadetime60, 1);
				}
			}
		}

		if (var8007074c == 2
				&& playerIsFadeComplete()
				&& g_Vars.currentplayer->colourscreenfrac == 1) {
			func0000e990();
		}
	}

	if (g_PlayerTriggerGeFadeIn) {
		playerBeginGeFadeIn();
	}

	// Handle mission exit on death
	if (g_Vars.currentplayer->isdead) {
		if (g_Vars.currentplayer->redbloodfinished == false) {
			bgunHandlePlayerDead();
		}
	}

	if (g_Vars.tickmode == TICKMODE_GE_FADEOUT && playerIsFadeComplete()) {
		mainEndStage();
	}
}

#define WIELDMODE_PISTOL   0
#define WIELDMODE_HEAVY    1
#define WIELDMODE_UNARMED  2
#define WIELDMODE_DUALGUNS 3

#define TURNMODE_STAND_NOTURN   0
#define TURNMODE_STAND_SOFTTURN 1
#define TURNMODE_STAND_HARDTURN 2
#define TURNMODE_DUCK_NOTURN    3
#define TURNMODE_DUCK_TURN      4
#define TURNMODE_SQUAT_NOTURN   5
#define TURNMODE_SQUAT_TURN     6

struct attackanimconfig var800709f4 = { ANIM_0281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.34901028871536, -1.5705462694168, 1.5705462694168, -1.5705462694168, 0,   0   };
struct attackanimconfig var80070a3c = { ANIM_0285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.34901028871536, -1.5705462694168, 1.5705462694168, -1.5705462694168, 0,   0   };
struct attackanimconfig var80070a84 = { ANIM_0282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.34901028871536, -1.5705462694168, 1.5705462694168, -1.5705462694168, 1.6, 1.6 };
struct attackanimconfig var80070acc = { ANIM_0286, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.17450514435768, -1.5705462694168, 1.5705462694168, -1.5705462694168, 1.6, 1.6 };
struct attackanimconfig var80070b14 = { ANIM_0283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.34901028871536, -1.5705462694168, 1.5705462694168, -1.5705462694168, 0,   0   };
struct attackanimconfig var80070b5c = { ANIM_0287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.17450514435768, -1.5705462694168, 1.5705462694168, -1.5705462694168, 0,   0   };

struct var80070ba4 {
	struct attackanimconfig *animcfg;
	s16 animnum;
	f32 speed;
	f32 startframe;
	f32 endframe;
	f32 unk14;
};

struct var80070ba4 var80070ba4[4][7] = { // [wieldmode][turnmode]
	{
		{ var80065be0,            0,                       0.1,   79, 87,  1.0470308065414  },
		{ &g_AttackAnimLightWalk, 0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &g_AttackAnimLightRun,  0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &var800709f4,           0,                       0.001, 0,  0.1, 1.0470308065414  },
		{ &var800709f4,           0,                       0.503, -1, -1,  1.0470308065414  },
		{ &var80070a3c,           0,                       0.001, 0,  0.1, 0.52351540327072 },
		{ &var80070a3c,           0,                       0.45,  -1, -1,  0.52351540327072 },
	}, {
		{ var800656c0,            0,                       0.05,  35, 40,  1.0470308065414  },
		{ &g_AttackAnimHeavyWalk, 0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &g_AttackAnimHeavyRun,  0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &var80070a84,           0,                       0.001, 0,  0.1, 1.0470308065414  },
		{ &var80070a84,           0,                       0.503, -1, -1,  1.0470308065414  },
		{ &var80070acc,           0,                       0.001, 0,  0.1, 0.52351540327072 },
		{ &var80070acc,           0,                       0.45,  -1, -1,  0.52351540327072 },
	}, {
		{ NULL,                   ANIM_006A,               0.25,  0,  -1,  1.0470308065414  },
		{ NULL,                   ANIM_006B,               0.5,   -1, -1,  1.0470308065414  },
		{ NULL,                   ANIM_RUNNING_ONEHANDGUN, 0.5,   -1, -1,  1.0470308065414  },
		{ NULL,                   ANIM_0280,               0.001, 0,  0.1, 1.0470308065414  },
		{ NULL,                   ANIM_0280,               0.503, -1, -1,  1.0470308065414  },
		{ NULL,                   ANIM_0284,               0.001, 0,  0.1, 0.52351540327072 },
		{ NULL,                   ANIM_0284,               0.45,  -1, -1,  0.52351540327072 },
	}, {
		{ var800663d8,            0,                       0.1,   32, 42,  1.0470308065414  },
		{ &g_AttackAnimDualWalk,  0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &g_AttackAnimDualRun,   0,                       0.5,   -1, -1,  1.0470308065414  },
		{ &var80070b14,           0,                       0.001, 0,  0.1, 1.0470308065414  },
		{ &var80070b14,           0,                       0.503, -1, -1,  1.0470308065414  },
		{ &var80070b5c,           0,                       0.001, 0,  0.1, 0.52351540327072 },
		{ &var80070b5c,           0,                       0.45,  -1, -1,  0.52351540327072 },
	},
};

void playerSetGlobalDrawWorldOffset(s32 room)
{
	room0f166df0(room, &g_Vars.currentplayer->globaldrawworldoffset);

	g_Vars.currentplayer->globaldrawworldbgoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawworldbgoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawworldbgoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	roomSetLastForOffset(room);
}

void playerSetGlobalDrawCameraOffset(void)
{
	g_Vars.currentplayer->globaldrawcameraoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawcameraoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawcameraoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	mtx4RotateVecInPlace(camGetWorldToScreenMtxf(), &g_Vars.currentplayer->globaldrawcameraoffset);
}

void playerAllocateMatrices(struct coord *cam_pos, struct coord *cam_look, struct coord *cam_up)
{
	Mtx spd0;
	LookAt *lookat;
	Mtxf sp8c;
	struct coord sp80;
	struct coord sp74;
	f32 scale;
	Mtxf *s0;
	Mtx *s1;
	s32 i;
	s32 j;

	scale = currentPlayerGetScaleBg2Gfx();
	playerSetGlobalDrawWorldOffset(g_Vars.currentplayer->cam_room);

	g_Vars.currentplayer->mtxl005c = gfxAllocateMatrix();
	g_Vars.currentplayer->mtxl0060 = gfxAllocateMatrix();
	g_Vars.currentplayer->mtxf0064 = gfxAllocateMatrix();
	g_Vars.currentplayer->mtxf0068 = gfxAllocateMatrix();

	lookat = gfxAllocateLookAt(2);

	sp74.x = (cam_pos->x - g_Vars.currentplayer->globaldrawworldoffset.x) * scale;
	sp74.y = (cam_pos->y - g_Vars.currentplayer->globaldrawworldoffset.y) * scale;
	sp74.z = (cam_pos->z - g_Vars.currentplayer->globaldrawworldoffset.z) * scale;

	sp80.f[0] = sp74.f[0] + cam_look->f[0];
	sp80.f[1] = sp74.f[1] + cam_look->f[1];
	sp80.f[2] = sp74.f[2] + cam_look->f[2];

	mtx00016874(&sp8c,
			sp74.x, sp74.y, sp74.z,
			cam_look->x, cam_look->y, cam_look->z,
			cam_up->x, cam_up->y, cam_up->z);

	guLookAtReflect(&spd0, lookat,
			sp74.x, sp74.y, sp74.z,
			sp80.x, sp80.y, sp80.z,
			cam_up->x, cam_up->y, cam_up->z);

	mtx00016874(g_Vars.currentplayer->mtxf0064,
			cam_pos->x, cam_pos->y, cam_pos->z,
			cam_look->x, cam_look->y, cam_look->z,
			cam_up->x, cam_up->y, cam_up->z);

	mtx00016b58(g_Vars.currentplayer->mtxf0068,
			cam_pos->x, cam_pos->y, cam_pos->z,
			cam_look->x, cam_look->y, cam_look->z,
			cam_up->x, cam_up->y, cam_up->z);

	s1 = gfxAllocateMatrix();
	s0 = gfxAllocateMatrix();
	mtx4MultMtx4(camGetMtxF1754(), &sp8c, s0);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s0->m[i][j] > 32000.0f) {
				s0->m[i][j] = 32000.0f;
			} else if (s0->m[i][j] < -32000.0f) {
				s0->m[i][j] = -32000.0f;
			}
		}
	}

	camSetMtxF006c(s0);
	guMtxF2L(s0->m, s1);
	camSetOrthogonalMtxL(s1);
	mtx00015f04(scale, &sp8c);
	guMtxF2L(sp8c.m, g_Vars.currentplayer->mtxl005c);
	mtx00016820(g_Vars.currentplayer->mtxl005c, g_Vars.currentplayer->mtxl0060);
	camSetMtxL173c(g_Vars.currentplayer->mtxl005c);
	camSetMtxL1738(g_Vars.currentplayer->mtxl0060);
	camSetWorldToScreenMtxf(g_Vars.currentplayer->mtxf0064);
	camSetProjectionMtxF(g_Vars.currentplayer->mtxf0068);
	camSetLookAt(lookat);
	cam0f0b5838();
	playerSetGlobalDrawCameraOffset();
}

Gfx *playerUpdateShootRot(Gfx *gdl)
{
	struct coord sp3c;
	struct coord sp30;
	f32 y;
	f32 value;
	f32 rotx;
	f32 roty;

	playerAllocateMatrices(&g_Vars.currentplayer->cam_pos,
			&g_Vars.currentplayer->cam_look,
			&g_Vars.currentplayer->cam_up);
	bgun0f0a0c08(&sp30, &sp3c);
	y = sp3c.y;

	value = sqrtf(sp3c.z * sp3c.z + sp3c.x * sp3c.x);

	rotx = atan2f(y, value);
	rotx += (g_Vars.currentplayer->vv_verta * M_BADTAU) / 360.0f;

	if (rotx >= M_PI) {
		rotx -= M_BADTAU;
	}

	g_Vars.currentplayer->shootrotx = rotx;

	roty = atan2f(-sp3c.x, -sp3c.z);

	if (roty >= M_PI) {
		roty -= M_BADTAU;
	}

	g_Vars.currentplayer->shootroty = roty;

	return gdl;
}

/**
 * Trigger the shield display when the player is damaged while using a shield.
 *
 * May be called while the shield is already being displayed, in which case the
 * effect is restarted.
 */
void playerDisplayShield(void)
{
	if (g_Vars.currentplayer->shieldshowtime < 0) {
		s32 rand = ((g_Vars.currentplayer->shieldshowrnd >> 16) % 200) * 4 + 800;

		g_Vars.currentplayer->shieldshowrnd = random();
		g_Vars.currentplayer->shieldshowrot = g_Vars.thisframestart240 % rand;
	}

	g_Vars.currentplayer->shieldshowtime = 0;
}

/**
 * Render the current player's shield from the first person perspective.
 */
Gfx *playerRenderShield(Gfx *gdl)
{
	f32 sp90[2];
	f32 sp88[2];
	f32 shield;
	s32 red;
	s32 green;
	s32 blue;
	s32 maxrot;
	f32 maxrotf;
	f32 f20;
	s32 add;

	if (g_Vars.currentplayer->shieldshowtime >= 0) {
		shield = playerGetShieldFrac() * 8;
		maxrot = ((g_Vars.currentplayer->shieldshowrnd >> 16) % 200) * 4 + 800;
		maxrotf = maxrot;
		f20 = (60 - g_Vars.currentplayer->shieldshowtime) * (1.0f / 60.0f);

		g_Vars.currentplayer->shieldshowrot += g_Vars.lvupdate60freal * (0.8f + 2.0f * f20 * f20);

		if (g_Vars.currentplayer->shieldshowrot >= maxrotf) {
			g_Vars.currentplayer->shieldshowrot -= maxrotf;
		}

		f20 = (sinf(g_Vars.currentplayer->shieldshowrot * (M_BADTAU / maxrotf)) + 1) * 0.5f;
		sp90[0] = camGetScreenLeft() + camGetScreenWidth() * f20;

		f20 = (cosf(g_Vars.currentplayer->shieldshowrot * (M_BADTAU / maxrotf)) + 1) * 0.5f;
		sp90[1] = camGetScreenTop() + camGetScreenHeight() * f20;

		sp88[0] = camGetScreenWidth() * (1.0f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 20) % 100) + (g_Vars.currentplayer->shieldshowtime * (0.2f + 0.002f * (g_Vars.currentplayer->shieldshowrnd % 100)) * (1.0f / 60.0f)));
		sp88[1] = camGetScreenHeight() * (1.0f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 24) % 100) + (g_Vars.currentplayer->shieldshowtime * (0.2f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 8) % 100)) * (1.0f / 60.0f)));

		chr0f0295f8(shield, &red, &green, &blue);

		if (g_Vars.currentplayer->shieldshowtime < 30) {
			f20 = 1 - g_Vars.currentplayer->shieldshowtime * (1.0f / 120.0f);
			f20 = 50 * f20 * f20 * f20;
		} else if (g_Vars.currentplayer->shieldshowtime < 60) {
			f20 = (g_Vars.currentplayer->shieldshowtime - (1.0f / 120.0f)) * (1.0f / 120.0f);
			f20 = -30 * f20;
		}

		add = f20;

		red += add;

		if (red > 255) {
			red = 255;
		} else if (red < 0) {
			red = 0;
		}

		green += add;

		if (green > 255) {
			green = 255;
		} else if (green < 0) {
			green = 0;
		}

		blue += add;

		if (blue > 255) {
			blue = 255;
		} else if (blue < 0) {
			blue = 0;
		}

		f20 = 1 - g_Vars.currentplayer->shieldshowtime * (1.0f / 60.0f);
		texSelect(&gdl, &g_TexShieldConfigs[0], 4, 1, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_CLD_SURF2);
		gDPSetEnvColor(gdl++, red, green, blue, (s32)(200 * f20));
		gDPSetPrimColor(gdl++, 0, 0, 0xff, 0xff, 0xff, (s32)(175 * f20 * f20));
		gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 1, COMBINED, PRIMITIVE, COMBINED);

		func0f0b2740(&gdl, sp90, sp88, g_TexShieldConfigs->width, g_TexShieldConfigs->height,
				(g_Vars.currentplayer->shieldshowrnd & 1) != 0,
				(g_Vars.currentplayer->shieldshowrnd & 2) != 0,
				(g_Vars.currentplayer->shieldshowrnd & 4) != 0,
				0);

		g_Vars.currentplayer->shieldshowtime += g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->shieldshowtime > 60) {
			g_Vars.currentplayer->shieldshowtime = -1;
		}
	}

	return gdl;
}

Gfx *playerRenderHud(Gfx *gdl)
{
	if (g_Vars.currentplayer->cameramode == CAMERAMODE_THIRDPERSON) {
		gdl = boltbeamsRender(gdl);
		gdl = hudmsgsRender(gdl);

		if (g_Vars.currentplayer->isdead == false) {
			gdl = playerDrawStoredFade(gdl);
		}

		return gdl;
	}

	{
		bgunTickGameplay2();
		gdl = boltbeamsRender(gdl);
		bgunRender(&gdl);
		gdl = lasersightRenderDot(gdl);

		if (g_NbombsActive) {
			gdl = nbombRenderOverlay(gdl);
		}

		gdl = playerRenderShield(gdl);

		// Adjust eyes shutting
		if (g_Vars.currentplayer->eyesshut) {
			if (g_Vars.currentplayer->eyesshutfrac < 0.95f) {
				g_Vars.currentplayer->eyesshutfrac += g_Vars.lvupdate60freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac > 0.95f) {
					g_Vars.currentplayer->eyesshutfrac = 0.95f;
				}
			}
		} else {
			if (g_Vars.currentplayer->eyesshutfrac > 0) {
				g_Vars.currentplayer->eyesshutfrac -= g_Vars.lvupdate60freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac < 0) {
					g_Vars.currentplayer->eyesshutfrac = 0;
				}
			}
		}

		if (g_Vars.currentplayer->eyesshutfrac > 0) {
			gdl = playerDrawFade(gdl, 0, 0, 0, g_Vars.currentplayer->eyesshutfrac);
		}
	}

	gdl = player0f0baf84(gdl);

	// Draw menu
	if (g_Vars.currentplayer->mpmenuon) {
		s32 a = viGetViewLeft();
		s32 b = viGetViewTop();
		s32 c = viGetViewLeft() + viGetViewWidth();
		s32 d = viGetViewTop() + viGetViewHeight();

		gdl = text0f153628(gdl);
		gdl = text0f153a34(gdl, a, b, c, d, 0x000000a0);
		gdl = text0f153780(gdl);
	}

	if (playerIsHealthVisible() && func0f0f0c68()) {
		gdl = playerRenderHealthBar(gdl);
	}

	if (g_Vars.currentplayer->isdead) {
		g_Vars.currentplayer->coopcanrestart = false;

		if (g_Vars.currentplayer->deathanimfinished == false) {
			bool pass = false;

			if (g_Vars.currentplayer->isdead == 1) {
				pakDisableRumbleForPlayer(g_Vars.currentplayernum);
				g_Vars.currentplayer->isdead = 2;
				pass = true;
			}

			if (pass) {
				if (g_Vars.mplayerisrunning == false) {
					musicStartSoloDeath();
				} else {
					musicStartMpDeath();
				}
			} else {
				if (g_Vars.currentplayer->redbloodfinished) {
					playerSetFadeColour(0x96, 0, 0, 0.70588237f);
				} else {
					g_Vars.currentplayer->redbloodfinished = true;
				}
			}
		}

		if (modelGetCurAnimFrame(&g_Vars.currentplayer->model) >= modelGetAnimEndFrame(&g_Vars.currentplayer->model)
				&& g_Vars.currentplayer->redbloodfinished) {
			if (g_Vars.currentplayer->deathanimfinished == false) {
				g_Vars.currentplayer->deathanimfinished = true;
				playerAdjustFade(60, 0, 0, 0, 1);
				playerStartChrFade(120, 0);
			}

			if (playerIsFadeComplete()) {
				bool canrestart = false;

				u32 playernum = g_Vars.currentplayernum;
				s32 playercount = PLAYERCOUNT();
				struct chrdata *chr = g_Vars.currentplayer->prop->chr;
				s32 numdeaths = 0;
				s32 i;

				if (chr) {
					chr->chrflags |= CHRCFLAG_HIDDEN;
				}

				for (i = 0; i < playercount; i++) {
					numdeaths += g_Vars.playerstats[i].kills[playernum];
				}

				if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
					if (g_Vars.currentplayer->deadtimer < 0) {
						g_Vars.currentplayer->deadtimer = TICKS(600);
					}

					if (g_Vars.currentplayer->deadtimer >= 0) {
						g_Vars.currentplayer->deadtimer -= g_Vars.lvupdate60;

						if (g_Vars.currentplayer->deadtimer < 0) {
							canrestart = true;
						}
					}
				}

				if (joyGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000)
						&& !mpIsPaused()
						&& g_MpMatchIsEnding == 0) {
					canrestart = true;
				}

				if (canrestart) {
					g_Vars.currentplayer->dostartnewlife = true;
				}
			}
		}
	}

	{
		gdl = bgunDrawSight(gdl);

		if (optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex)) {
			gdl = bgunDrawHud(gdl);
		}

#if VERSION >= VERSION_NTSC_1_0
		gdl = radarRender(gdl);
		gdl = hudmsgsRender(gdl);
#else
		gdl = hudmsgsRender(gdl);
		gdl = radarRender(gdl);
#endif

		gdl = playerDrawStoredFade(gdl);
	}

	return gdl;
}

void playerDie(bool force)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	s32 shooter;

	if (chr->lastshooter >= 0 && chr->timeshooter > 0) {
		shooter = chr->lastshooter;
	} else {
		shooter = g_Vars.currentplayernum;
	}

	playerDieByShooter(shooter, force);
}

void playerDieByShooter(u32 shooter, bool force)
{
#if VERSION >= VERSION_NTSC_1_0
	if (!g_Vars.currentplayer->isdead && (force || !g_Vars.currentplayer->invincible))
#else
	if (!g_Vars.currentplayer->isdead && (force || !g_Vars.currentplayer->invincible || !g_Vars.currentplayer->training))
#endif
	{
		u32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
		func0f0f8120();
		g_MpPlayerNum = prevplayernum;

		hudmsgsRemoveForDeadPlayer(g_Vars.currentplayernum);

		if (g_Vars.mplayerisrunning) {
			mpstatsRecordDeath(shooter, g_Vars.currentplayernum);
		}

		chrUncloak(g_Vars.currentplayer->prop->chr, true);

		currentPlayerDropAllItems();

		g_Vars.currentplayer->isdead = true;
		g_Vars.currentplayer->bonddie = g_Vars.currentplayer->bond2;
		g_Vars.currentplayer->thetadie = g_Vars.currentplayer->vv_theta;
		g_Vars.currentplayer->vertadie = g_Vars.currentplayer->vv_verta;
		g_Vars.currentplayer->posdie.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->posdie.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->posdie.z = g_Vars.currentplayer->prop->pos.z;

		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
			if (g_Vars.currentplayer->unk1af0) {
				g_Vars.currentplayer->bondtankexplode = true;
			}
		}

		bmoveSetMode(MOVEMODE_WALK);
		bgunHandlePlayerDead();

		if (playerGetMissionTime() - g_Vars.currentplayer->lifestarttime60 < g_Vars.currentplayerstats->shortestlife) {
			g_Vars.currentplayerstats->shortestlife = playerGetMissionTime() - g_Vars.currentplayer->lifestarttime60;
		}

		g_Vars.currentplayer->lifestarttime60 = playerGetMissionTime();
	}
}

void playerCheckIfShotInBack(s32 attackerplayernum, f32 x, f32 z)
{
	if (g_Vars.normmplayerisrunning) {
		s32 victimplayernum = g_Vars.currentplayernum;
		f32 angle = atan2f(x, z);
		f32 finalangle = g_Vars.players[victimplayernum]->vv_theta - (360.0f - RAD2DEG2(angle));

		if (finalangle < 0) {
			finalangle = -finalangle;
		}

		if (finalangle < 90.0f || finalangle > 270.0f) {
			g_Vars.playerstats[attackerplayernum].backshotcount++;
		}
	}
}

/**
 * Determines what height the health bar should have. The function is called
 * while any menu is open and any time when the health bar should be shown.
 *
 * A return value of 0 means zero height, while 1 means full expanded height.
 */
f32 playerGetHealthBarHeightFrac(void)
{
	f32 done;
	f32 total;

	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		return 0;
	case HEALTHSHOWMODE_OPENING:
		total = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openendframe;
		done = g_Vars.currentplayer->healthshowtime;
		return done / total;
	case HEALTHSHOWMODE_CLOSING:
		total = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closeendframe - g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closestartframe;
		done = g_Vars.currentplayer->healthshowtime - g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].closestartframe;
		return 1 - done / total;
	}

	return 1;
}

bool playerIsHealthVisible(void)
{
	return g_Vars.currentplayer->healthshowmode != HEALTHSHOWMODE_HIDDEN;
}

void playerSetCameraMode(s32 mode)
{
	g_Vars.currentplayer->cameramode = mode;
}

void player0f0c1840(struct coord *pos, struct coord *up, struct coord *look, struct coord *pos2, s16 *rooms2)
{
	bool done = false;
	s16 inrooms[21];
	s16 aboverooms[21];
	s16 sp54[8];
	s16 bestroom;
	s16 tmp;
	s32 i;
	s32 room;

	if (rooms2 != NULL && *rooms2 != -1) {
		portal00018148(pos2, pos, rooms2, sp54, NULL, 0);

		// Remove values from sp54 (room numbers) if that room doesn't contain
		// the coord, and shuffle the array back when removing values.
		for (i = 0; sp54[i] != -1; i++) {
			if (!roomContainsCoord(pos, sp54[i])) {
				s32 j;

#if VERSION >= VERSION_NTSC_1_0
				for (j = i + 1; sp54[j] != -1; j++) {
					sp54[j - 1] = sp54[j];
				}

				sp54[j - 1] = -1;
				i--;
#else
				// ntsc-beta corrupts the array by overwriting the first shifted
				// value with -1, and leaving a duplicate at the end.
				for (j = i + 1; sp54[j] != -1; j++) {
					sp54[j - 1] = sp54[j];
				}

				sp54[i] = -1;
#endif
			}
		}

		if (sp54[0] != -1 && sp54[1] == -1) {
			playerSetCamPropertiesWithRoom(pos, up, look, sp54[0]);
			done = true;
		}

		if (!done) {
			for (i = 0; sp54[i] != -1; i++) {
				if ((g_Rooms[sp54[i]].flags & ROOMFLAG_0010) == 0) {
					if (func0f162128(pos, sp54[i])) {
						playerSetCamPropertiesWithRoom(pos, up, look, sp54[i]);
						done = true;
						break;
					}
				}
			}
		}

		// The same thing again but inverted flag check
		if (!done) {
			for (i = 0; sp54[i] != -1; i++) {
				if (g_Rooms[sp54[i]].flags & ROOMFLAG_0010) {
					if (func0f162128(pos, sp54[i])) {
						playerSetCamPropertiesWithRoom(pos, up, look, sp54[i]);
						done = true;
						break;
					}
				}
			}
		}
	}

	if (!done) {
		bgFindRoomsByPos(pos, inrooms, aboverooms, 20, &bestroom);

		if (inrooms[0] != -1) {
			tmp = room = cdFindFloorRoomAtPos(pos, inrooms);

			if (room > 0) {
				playerSetCamPropertiesWithRoom(pos, up, look, tmp);
			} else {
				playerSetCamPropertiesWithRoom(pos, up, look, inrooms[0]);
			}
		} else if (aboverooms[0] != -1) {
			tmp = room = cdFindFloorRoomAtPos(pos, aboverooms);

			if (room > 0) {
				playerSetCamPropertiesWithoutRoom(pos, up, look, tmp);
			} else {
				playerSetCamPropertiesWithoutRoom(pos, up, look, aboverooms[0]);
			}
		} else {
			if (bestroom != -1) {
				playerSetCamPropertiesWithoutRoom(pos, up, look, bestroom);
			} else {
				playerSetCamPropertiesWithoutRoom(pos, up, look, 1);
			}
		}
	}
}

void player0f0c1ba4(struct coord *pos, struct coord *up, struct coord *look, struct coord *memcampos, s32 memcamroom)
{
	s16 rooms[2];
	rooms[0] = memcamroom;
	rooms[1] = -1;

	player0f0c1840(pos, up, look, memcampos, rooms);
}

void playerSetCamPropertiesWithRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	g_Vars.currentplayer->memcampos.x = pos->x;
	g_Vars.currentplayer->memcampos.y = pos->y;
	g_Vars.currentplayer->memcampos.z = pos->z;
	g_Vars.currentplayer->memcamroom = room;

	playerSetCamProperties(pos, up, look, room);
}

void playerSetCamPropertiesWithoutRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	playerClearMemCamRoom();
	playerSetCamProperties(pos, up, look, room);
}

void playerSetCamProperties(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	struct player *player = g_Vars.currentplayer;

	player->cam_pos.x = pos->x;
	player->cam_pos.y = pos->y;
	player->cam_pos.z = pos->z;
	player->cam_up.x = up->x;
	player->cam_up.y = up->y;
	player->cam_up.z = up->z;
	player->cam_look.x = look->x;
	player->cam_look.y = look->y;
	player->cam_look.z = look->z;
	player->cam_room = room;
}

void playerClearMemCamRoom(void)
{
	g_Vars.currentplayer->memcamroom = -1;
}

void playerSetPerimEnabled(struct prop *prop, bool enable)
{
	u32 playernum = playermgrGetPlayerNumByProp(prop);

	if (g_Vars.players[playernum]->haschrbody) {
		chrSetPerimEnabled(prop->chr, enable);
	}

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		if (g_Vars.currentplayer->unk1af0) {
			objSetPerimEnabled(g_Vars.currentplayer->unk1af0, enable);
		}
	}

	g_Vars.players[playernum]->bondperimenabled = enable;
}

bool playerUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	s32 playernum = playermgrGetPlayerNumByProp(prop);

	if (g_Vars.players[playernum]->bondperimenabled
			&& (!g_Vars.mplayerisrunning || !g_Vars.players[playernum]->isdead)) {
		if (g_Vars.useperimshoot) {
			g_Vars.players[playernum]->perimshoot = g_Vars.players[playernum]->periminfo;
			g_Vars.players[playernum]->perimshoot.radius = 15;

			*start = (void *) &g_Vars.players[playernum]->perimshoot;
		} else {
			*start = (void *) &g_Vars.players[playernum]->periminfo;
		}

		*end = *start + sizeof(struct geocyl);

		return true;
	}

	*end = NULL;
	*start = NULL;

	return false;
}

void playerUpdatePerimInfo(void)
{
	g_Vars.currentplayer->periminfo.header.type = GEOTYPE_CYL;
	g_Vars.currentplayer->periminfo.header.flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SHOOT;

	g_Vars.currentplayer->periminfo.ymin = g_Vars.currentplayer->vv_manground;
	g_Vars.currentplayer->periminfo.ymax = g_Vars.currentplayer->vv_manground + g_Vars.currentplayer->vv_headheight;

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		// note: crouchoffsetrealsmall is negative
		f32 minsane;
		g_Vars.currentplayer->periminfo.ymax += g_Vars.currentplayer->crouchoffsetrealsmall;
		minsane = g_Vars.currentplayer->vv_manground + 80;

		if (g_Vars.currentplayer->periminfo.ymax < minsane) {
			g_Vars.currentplayer->periminfo.ymax = minsane;
		}
	}

	g_Vars.currentplayer->periminfo.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->periminfo.z = g_Vars.currentplayer->prop->pos.z;
	g_Vars.currentplayer->periminfo.radius = g_Vars.currentplayer->bond2.radius;
}

/**
 * Populates the width, ymax and ymin arguments with absolute coordinates.
 *
 * ymin is set to 30 units above the player's feet. This allows them to go up
 * steps or ledges that are 30 units or smaller.
 *
 * ymax is the top of the head, minus some if crouching, and always at least 80
 * units above the feet.
 */
void playerGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin)
{
	s32 playernum = playermgrGetPlayerNumByProp(prop);

	*radius = g_Vars.players[playernum]->bond2.radius;
	*ymin = g_Vars.currentplayer->vv_manground + 30;
	*ymax = g_Vars.currentplayer->vv_manground + g_Vars.players[playernum]->vv_headheight;

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		// note: crouchoffsetrealsmall is negative
		f32 minsane;
		*ymax += g_Vars.players[playernum]->crouchoffsetrealsmall;
		minsane = g_Vars.currentplayer->vv_manground + 80;

		if (*ymax < minsane) {
			*ymax = minsane;
		}
	}
}

f32 playerGetHealthFrac(void)
{
	return g_Vars.currentplayer->bondhealth;
}

f32 playerGetShieldFrac(void)
{
	f32 frac = chrGetShield(g_Vars.currentplayer->prop->chr) * 0.125f;

	if (frac < 0) {
		frac = 0;
	}

	if (frac > 1) {
		frac = 1;
	}

	return frac;
}

void playerSetShieldFrac(f32 frac)
{
	if (frac < 0) {
		frac = 0;
	}

	if (frac > 1) {
		frac = 1;
	}

	chrSetShield(g_Vars.currentplayer->prop->chr, frac * 8);
}

s32 playerGetMissionTime(void)
{
#if PAL
	return g_Vars.currentplayer->bondviewlevtime60 * 60 / 50;
#else
	return g_Vars.currentplayer->bondviewlevtime60;
#endif
}

s32 playerTickBeams(struct prop *prop)
{
	beamTick(&g_Vars.players[playermgrGetPlayerNumByProp(prop)]->hands[0].beam);
	beamTick(&g_Vars.players[playermgrGetPlayerNumByProp(prop)]->hands[1].beam);

	if (prop->chr && g_Vars.mplayerisrunning) {
		struct chrdata *chr = prop->chr;

		if (chr->fireslots[0] >= 0) {
			beamTick(&g_Fireslots[chr->fireslots[0]].beam);
		}

		if (chr->fireslots[1] >= 0) {
			beamTick(&g_Fireslots[chr->fireslots[1]].beam);
		}
	}

	return 0;
}

s32 playerTickThirdPerson(struct prop *prop)
{
	s32 playernum = playermgrGetPlayerNumByProp(prop);
	struct player *player = g_Vars.players[playernum];
	struct chrdata *chr = prop->chr;
	s32 i;
	s32 tickop1;
	Mtxf *spe8;
	Mtxf spa8;
	struct coord sp9c;
	s32 tickop2;
	struct coord sp8c;
	struct coord sp80;
	f32 angle;
	s32 animnum;
	f32 shootrotx;
	f32 shootroty;
	struct prop *leftprop;
	struct prop *rightprop;
	struct coord sp5c;

	if (g_Vars.currentplayerindex == 0 && player->haschrbody) {
		chr->hidden &= ~CHRHFLAG_00000800;
	}

	if (player->haschrbody && player->model00d4) {
		if (player->cameramode == CAMERAMODE_THIRDPERSON && player->visionmode != VISIONMODE_SLAYERROCKET) {
			chr->chrflags |= CHRCFLAG_00000001;

			player->bondperimenabled = false;
			tickop1 = chrTick(prop);
			player->bondperimenabled = true;

			player->vv_ground = chr->ground;
			player->vv_manground = chr->ground;

			chr0f0220ac(prop->chr);

			if (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				if (player->model00d4->filedata->skel == &g_SkelChr) {
					spe8 = player->model00d4->matrices;
				} else {
					spe8 = player->model00d4->matrices;
				}

				mtx00015be4(camGetProjectionMtxF(), spe8, &spa8);

				sp9c.x = spa8.m[3][0] + spa8.m[1][0] * 7;
				sp9c.y = spa8.m[3][1] + spa8.m[1][1] * 7;
				sp9c.z = spa8.m[3][2] + spa8.m[1][2] * 7;

				player->vv_theta = (M_BADTAU - chrGetInverseTheta(chr)) * 360.0f / M_BADTAU;
				player->vv_verta = 0;
			} else {
				sp9c.x = player->prop->pos.x;
				sp9c.y = player->prop->pos.y;
				sp9c.z = player->prop->pos.z;

				player->vv_theta = (M_BADTAU - chrGetInverseTheta(chr)) * 360.0f / M_BADTAU;
				player->vv_verta = 0;
			}

			bmoveUpdateVerta();
			bmove0f0cc19c(&sp9c);

			return tickop1;
		}
	}

	if (player->haschrbody
			&& player->model00d4
			&& ((g_Vars.mplayerisrunning && g_Vars.currentplayernum != playernum)
				|| (player->cameramode == CAMERAMODE_THIRDPERSON && player->visionmode == VISIONMODE_SLAYERROCKET))) {
		chr->actiontype = ACT_BONDMULTI;

		if ((chr->hidden & CHRHFLAG_00000800) == 0) {
			leftprop = chrGetHeldProp(chr, HAND_LEFT);
			rightprop = chrGetHeldProp(chr, HAND_RIGHT);
			animnum = modelGetAnimNum(chr->model);

			playerChooseThirdPersonAnimation(chr, bmoveGetCrouchPosByPlayer(playernum), player->speedsideways, player->speedforwards, player->speedtheta, &player->angleoffset, &chr->act_bondmulti.animcfg);

			if (chrIsDead(chr)) {
				shootrotx = 0;
				shootroty = 0;
			} else {
				shootrotx = player->shootrotx;
				shootroty = player->shootroty;
			}

			if (modelGetAnimNum(chr->model) == animnum) {
				if (chr->act_bondmulti.animcfg) {
					chr->hidden2 &= ~CHRH2FLAG_0004;
					chrCalculateAimEndProperties(chr, chr->act_bondmulti.animcfg, leftprop != NULL, rightprop != NULL, shootrotx);
				} else {
					chr->hidden2 |= CHRH2FLAG_0004;
					chr->aimendback = shootrotx;
					chr->aimendrshoulder = 0;
					chr->aimendlshoulder = 0;
				}
			}

			chr->aimendsideback = shootroty;
			chr->aimendcount = 10;

			chrSetFiring(chr, HAND_RIGHT, player->hands[HAND_RIGHT].flashon);
			chrSetFiring(chr, HAND_LEFT, player->hands[HAND_LEFT].flashon);
		}

		sp80.x = prop->pos.x;
		sp80.y = prop->pos.y;
		sp80.z = prop->pos.z;

		modelGetRootPosition(chr->model, &sp8c);

		sp8c.x = prop->pos.x;
		sp8c.z = prop->pos.z;

		modelSetRootPosition(chr->model, &sp8c);

		angle = (360.0f - player->vv_theta) * 0.017450513318181f - player->angleoffset;

		if (angle >= M_BADTAU) {
			angle -= M_BADTAU;
		} else if (angle < 0) {
			angle += M_BADTAU;
		}

		chrSetLookAngle(chr, angle);

		chr->chrflags |= CHRHFLAG_00000001;

		tickop2 = chrTick(prop);

		prop->pos.x = sp80.x;
		prop->pos.y = sp80.y;
		prop->pos.z = sp80.z;

		if ((chr->hidden & CHRHFLAG_00000800) == 0) {
			for (i = 0; i < 2; i++) {
				if (chrGetGunPos(chr, i, &player->chrmuzzlelastpos[i])) {
					player->chrmuzzlelast[i] = g_Vars.lvframenum;
				} else if (player->chrmuzzlelast[i] < g_Vars.lvframenum - 1) {
					player->chrmuzzlelastpos[i].x = player->hands[i].muzzlepos.x;
					player->chrmuzzlelastpos[i].y = player->hands[i].muzzlepos.y;
					player->chrmuzzlelastpos[i].z = player->hands[i].muzzlepos.z;
				}
			}

			chr->hidden |= CHRHFLAG_00000800;
		}

		return tickop2;
	}

	if (PLAYERCOUNT() == 1) {
		chrUpdateCloak(chr);
	}

	if (player->haschrbody && chr->model) {
		modelGetRootPosition(chr->model, &sp5c);

		sp5c.x = prop->pos.x;
		sp5c.z = prop->pos.z;

		modelSetRootPosition(chr->model, &sp5c);
	}

	chr->ground = player->vv_ground;
	chr->manground = player->vv_manground;
	chr->sumground = chr->manground * (PAL ? 8.417509f : 9.999998f);

	if (g_Vars.mplayerisrunning) {
		if (chr->weapons_held[0] && (chr->weapons_held[0]->obj->hidden & OBJHFLAG_REAPABLE)) {
			objFree(chr->weapons_held[0]->obj, true, false);
		}

		if (chr->weapons_held[1] && (chr->weapons_held[1]->obj->hidden & OBJHFLAG_REAPABLE)) {
			objFree(chr->weapons_held[1]->obj, true, false);
		}
	}

	prop->flags &= ~PROPFLAG_ONTHISSCREENTHISTICK;

	return TICKOP_NONE;
}

/**
 * Choose and apply an animation for a multiplayer player from a third person
 * perspective, based on their crouch state, equipped weapons and how quickly
 * they are turning.
 *
 * Despite the function name, this is also used for bots.
 */
void playerChooseThirdPersonAnimation(struct chrdata *chr, s32 crouchpos, f32 speedsideways, f32 speedforwards, f32 speedtheta, f32 *angleoffset, struct attackanimconfig **animcfgptr)
{
	struct prop *leftprop = chrGetHeldProp(chr, HAND_LEFT);
	struct prop *rightprop = chrGetHeldProp(chr, HAND_RIGHT);
	struct weaponobj *leftgun = NULL;
	struct weaponobj *rightgun = NULL;
	s16 animnum = 0;
	struct attackanimconfig *animcfg;
	f32 speed;
	s32 prevanimnum;
	bool reconfigure = false;
	s32 wieldmode;
	s32 i;
	f32 startframe = -1;
	f32 endframe = -1;
	struct var80070ba4 *row;
	f32 angle;
	f32 turnspeed;
	s32 turnmode;
	f32 limit;

	if (leftprop != NULL) {
		leftgun = leftprop->weapon;
	}

	if (rightprop != NULL) {
		rightgun = rightprop->weapon;
	}

	prevanimnum = modelGetAnimNum(chr->model);

	if (chrIsDead(chr)) {
		// Choose a death animation
		bool found = false;

		for (i = 0; i < g_NumDeathAnimations; i++) {
			if (g_DeathAnimations[i] == prevanimnum) {
				found = true;
				break;
			}
		}

		if (found) {
			animnum = prevanimnum;
			speed = 0.5f;
		} else {
			animnum = g_DeathAnimations[random() % g_NumDeathAnimations];
			speed = 0.5f;
		}

		animcfg = NULL;
	} else {
		struct prop *chrprop = chr->prop;

		// Player or bot on foot
		if (leftprop && rightprop) {
			wieldmode = WIELDMODE_DUALGUNS;
		} else if (!leftprop && !rightprop) {
			wieldmode = WIELDMODE_UNARMED;
		} else if (leftgun && !weaponHasFlag(leftgun->weaponnum, WEAPONFLAG_AICANUSE)) {
			wieldmode = WIELDMODE_UNARMED;
		} else if (rightgun && !weaponHasFlag(rightgun->weaponnum, WEAPONFLAG_AICANUSE)) {
			wieldmode = WIELDMODE_UNARMED;
		} else if (leftgun && weaponHasFlag(leftgun->weaponnum, WEAPONFLAG_ONEHANDED)) {
			wieldmode = WIELDMODE_PISTOL;
		} else if (rightgun && weaponHasFlag(rightgun->weaponnum, WEAPONFLAG_ONEHANDED)) {
			wieldmode = WIELDMODE_PISTOL;
		} else {
			wieldmode = WIELDMODE_HEAVY;
		}

		turnspeed = sqrtf(speedsideways * speedsideways + speedforwards * speedforwards);

		if (speedtheta < 0) {
			speedtheta = -speedtheta;
		}

		if (turnspeed < speedtheta) {
			turnspeed = speedtheta;
		}

		if (turnspeed < 0.05f) {
			if (crouchpos == CROUCHPOS_SQUAT) {
				turnmode = TURNMODE_SQUAT_NOTURN;
			} else if (crouchpos == CROUCHPOS_DUCK) {
				turnmode = TURNMODE_DUCK_NOTURN;
			} else {
				turnmode = TURNMODE_STAND_NOTURN;
			}

			row = &var80070ba4[wieldmode][turnmode];
			speed = 1.0f;
			angle = 0.0f;
		} else {
			angle = atan2f(speedsideways, speedforwards);

			if (angle >= M_BADPI) {
				angle -= M_BADTAU;
			}

			if (crouchpos == CROUCHPOS_SQUAT) {
				turnmode = TURNMODE_SQUAT_TURN;
				speed = turnspeed * 2.8571429252625f;

				if (speed > 1.2f) {
					speed = 1.2f;
				}
			} else if (crouchpos == CROUCHPOS_DUCK) {
				turnmode = TURNMODE_DUCK_TURN;
				speed = turnspeed * 2;

				if (speed > 1.2f) {
					speed = 1.2f;
				}
			} else if (turnspeed < 0.4f
					|| (chr->prop->type == PROPTYPE_PLAYER
						&& g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)]->headanim == 0)) {
				turnmode = TURNMODE_STAND_SOFTTURN;
				speed = 2.0f * turnspeed;

				if (speed > 1.2f) {
					speed = 1.2f;
				}
			} else {
				turnmode = TURNMODE_STAND_HARDTURN;
				speed = turnspeed;

				if (speed > 1.2f) {
					speed = 1.2f;
				}
			}

			if (angle < -1.6333680152893f) {
				angle += M_BADPI;
				speed = -speed;
			} else if (angle > 1.6333680152893f) {
				angle -= M_BADPI;
				speed = -speed;
			}

			row = &var80070ba4[wieldmode][turnmode];

			if (angle < -row->unk14) {
				angle = -row->unk14;
			} else if (angle > row->unk14) {
				angle = row->unk14;
			}
		}

		limit = g_Vars.lvupdate60freal * 0.10470308363438f;

		if (angle - *angleoffset > limit) {
			*angleoffset += limit;
		} else if (angle - *angleoffset < -limit) {
			*angleoffset -= limit;
		} else {
			*angleoffset = angle;
		}

		animcfg = row->animcfg;

		if (row->animnum) {
			animnum = row->animnum;
		}

		speed *= row->speed;
		startframe = row->startframe;
		endframe = row->endframe;
	}

	if (animcfg != NULL && animnum == 0) {
		animnum = animcfg->animnum;
	}

	if (animnum != prevanimnum) {
		reconfigure = true;
	}

	if (startframe >= 0 && (!chr->model->anim->looping || startframe != chr->model->anim->loopframe)) {
		reconfigure = true;
	}

	if (startframe < 0 && chr->model->anim->looping) {
		reconfigure = true;
	}

	if (reconfigure) {
		if (chr->model->anim->animnum2 == 0) {
			modelSetAnimation(chr->model, animnum, false, startframe >= 0 ? startframe : 0, speed, 16);

			if (startframe >= 0) {
				modelSetAnimLooping(chr->model, startframe, 16);
			}

			if (endframe >= 0) {
				modelSetAnimEndFrame(chr->model, endframe);
			}
		}
	} else {
		if (speed != modelGetAnimSpeed(chr->model)) {
			modelSetAnimSpeed(chr->model, speed, 1);
		}
	}

	*animcfgptr = animcfg;
}

Gfx *playerRender(struct prop *prop, Gfx *gdl, bool xlupass)
{
	if (g_Vars.players[playermgrGetPlayerNumByProp(prop)]->haschrbody) {
		gdl = chrRender(prop, gdl, xlupass);
	}

	return gdl;
}

Gfx *playerLoadMatrix(Gfx *gdl)
{
	gSPMatrix(gdl++, g_Vars.currentplayer->mtxl005c, G_MTX_LOAD);
	return gdl;
}

void player0f0c3320(Mtxf *matrices, s32 count)
{
	Mtxf sp40;
	s32 i;
	s32 j;

	for (i = 0, j = 0; i < count; i++, j += sizeof(Mtxf)) {
		mtx00015be4(camGetProjectionMtxF(), (Mtxf *)((u32)matrices + j), &sp40);

		sp40.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
		sp40.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
		sp40.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

		mtx00016054(&sp40, matrices + i);
	}
}
