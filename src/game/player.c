#include <ultra64.h>
#include "constants.h"
#include "game/bondeyespy.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/floor.h"
#include "game/inventory/items.h"
#include "game/nbomb.h"
#include "game/title.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/objectives.h"
#include "game/atan2f.h"
#include "game/game_096ca0.h"
#include "game/bondgun.h"
#include "game/game_0abe70.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/player.h"
#include "game/game_1a7560.h"
#include "game/healthbar.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/inventory/inventory.h"
#include "game/playermgr.h"
#include "game/explosions/explosions.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_1668e0.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/training/training.h"
#include "game/training/training.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/pak/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/ailist.h"
#include "lib/collision.h"
#include "lib/joy.h"
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
s16 g_WarpPadId;
struct var8009ddec *var8009ddec;
f32 var8009ddf0;
f32 var8009ddf4;
f32 var8009ddf8;
f32 var8009ddfc;
f32 var8009de00;
u32 var8009de04;
s32 var8009de08;
u32 var8009de0c;
s32 g_CutsceneCurAnimFrame60;

#if PAL
f32 g_CutsceneCurAnimFrame240;
f32 var8009e388pf;
#else
s32 g_CutsceneCurAnimFrame240;
#endif

s16 g_CutsceneAnimNum;
f32 g_CutsceneBlurFrac;

#if !PAL
s32 g_CutsceneFrameOverrun240;
#endif

bool g_CutsceneSkipRequested;
f32 g_CutsceneCurTotalFrame60f;
s32 var8009de2c;
f32 g_CutsceneBarFrac; // 0 when bars across the top and bottom, 1 when fullscreen
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
s32 g_InCutscene = 0x00000000;

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
f32 playerChooseSpawnLocation(f32 chrwidth, struct coord *dstpos, s16 *dstrooms, struct prop *prop, s16 *pads, s32 numpads)
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

				if (roomIsVisibleByPlayer(pad.room, i)) {
					verybadpads[p] = true;
				}

				// @bug: The aibot check should be in the aibot loop. As it
				// stands it's using the playernum iterator as the AI bot num,
				// so if there's more AI bots than players then some AI bots
				// will be excluded from the room visibility check.
				if (verybadpads[p] || roomIsVisibleByAibot(pad.room, i)) {
					badpads[p] = true;
				}
			}
		}

		// Do the same as above, but for simulants
		tmppadrooms[0] = pad.room;
		tmppadrooms[1] = -1;

		roomGetNeighbours(pad.room, neighbours, 20);

		for (i = 0; i < g_BotCount; i++) {
			if (g_MpBotChrPtrs[i]->prop
					&& g_MpBotChrPtrs[i]->prop != prop
					&& (!prop || chrCompareTeams(prop->chr, g_MpBotChrPtrs[i], COMPARE_ENEMIES))) {
				xdiff = g_MpBotChrPtrs[i]->prop->pos.x - pad.pos.x;
				ydiff = g_MpBotChrPtrs[i]->prop->pos.y - pad.pos.y;
				zdiff = g_MpBotChrPtrs[i]->prop->pos.z - pad.pos.z;

				sqdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

				if (sqdist < bestsqdist) {
					bestsqdist = sqdist;
				}

				if (arrayIntersects(tmppadrooms, g_MpBotChrPtrs[i]->prop->rooms)) {
					verybadpads[p] = true;
				}

				if (verybadpads[p] || arrayIntersects(neighbours, g_MpBotChrPtrs[i]->prop->rooms)) {
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
	p = i; while (sllen < 4) {
		if (padsqdists[p] > 1000 * 1000 && !badpads[p]) {
			padUnpack(pads[p], PADFIELD_POS | PADFIELD_ROOM | PADFIELD_LOOK, &pad);

			slrooms[sllen][0] = pad.room;
			slrooms[sllen][1] = -1;

			slpositions[sllen].x = pad.pos.x;
			slpositions[sllen].y = pad.pos.y;
			slpositions[sllen].z = pad.pos.z;

			slangles[sllen] = atan2f(pad.look.x, pad.look.z);

#if VERSION >= VERSION_NTSC_1_0
			if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#else
			if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
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
			if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
				slpadindexes[sllen] = p;
				sllen++;
			}
#else
			if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
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
		if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false, false)) {
			slpadindexes[sllen] = i;
			sllen++;
		}
#else
		if (chrAdjustPosForSpawn(chrwidth, &slpositions[sllen], slrooms[sllen], slangles[sllen], true, false)) {
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

f32 playerChooseGeneralSpawnLocation(f32 chrwidth, struct coord *pos, s16 *rooms, struct prop *prop)
{
	return playerChooseSpawnLocation(chrwidth, pos, rooms, prop, g_SpawnPoints, g_NumSpawnPoints);
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

	if (g_Vars.coopplayernum < 0) {
		struct prop *prop = g_Vars.currentplayer->prop->child;

		while (prop) {
			struct defaultobj *obj = prop->obj;

			if (obj) {
				obj->hidden |= OBJHFLAG_REAPABLE;
			}

			prop = prop->next;
		}
	}

	chrInitSplats(g_Vars.currentplayer->prop->chr);
	playerLoadDefaults();
	g_Vars.currentplayer->isdead = false;
	g_Vars.currentplayer->healthdamagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->damagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->gunammooff = 0;
	g_Vars.currentplayer->gunsightoff = 2;

	hudmsgsSetOn(0xffffffff);

	angle = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop); // var7f1ad534

	groundy = cdFindGroundY(&pos, 30, rooms,
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

	if (g_Vars.coopplayernum >= 0) {
		u32 stack;
		bool ammotypesheld[33];
		s32 stack2[2];

		for (i = 0; i != ARRAYCOUNT(ammotypesheld); i++) {
			ammotypesheld[i] = false;
		}

		for (i = 1; i != ARRAYCOUNT(g_Weapons); i++) {
			if (invHasSingleWeaponOrProp(i)) {
				s32 ammotype = bgunGetAmmoTypeForWeapon(i, FUNC_PRIMARY);

				if (ammotype >= 0 && ammotype <= AMMOTYPE_ECM_MINE) {
					ammotypesheld[ammotype] = true;
				}
			}
		}

		for (i = 0; i != ARRAYCOUNT(ammotypesheld); i++) {
			if (ammotypesheld[i] == false) {
				g_Vars.currentplayer->ammoheldarr[i] = 0;
			}
		}
	} else {
		invClear();

		for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->ammoheldarr); i++) {
			g_Vars.currentplayer->ammoheldarr[i] = 0;
		}
	}

	invGiveSingleWeapon(WEAPON_UNARMED);

	if (cmd) {
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);
		if (cmd);

		if (g_Vars.antiplayernum < 0 || g_Vars.currentplayer != g_Vars.anti) {
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
	}

	if (g_Vars.coopplayernum >= 0 && g_Vars.currentplayer->stealhealth > 0) {
		g_Vars.currentplayer->bondhealth = g_Vars.currentplayer->stealhealth;
		g_Vars.currentplayer->oldhealth = 0;
		g_Vars.currentplayer->oldarmour = 0;
		g_Vars.currentplayer->apparenthealth = 0;
		g_Vars.currentplayer->apparentarmour = 0;
	}

	bmove0f0cb8c4(g_Vars.currentplayer);
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
	g_Vars.currentplayer->periminfo.header.type = TILETYPE_03;
	g_Vars.currentplayer->periminfo.header.flags = TILEFLAG_0004 | TILEFLAG_0010;
	g_Vars.currentplayer->periminfo.ymax = 0;
	g_Vars.currentplayer->periminfo.ymin = 0;
	g_Vars.currentplayer->periminfo.x = 0;
	g_Vars.currentplayer->periminfo.z = 0;
	g_Vars.currentplayer->periminfo.width = 0;
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
	g_Vars.currentplayer->bondshotspeed[0] = 0;
	g_Vars.currentplayer->bondshotspeed[1] = 0;
	g_Vars.currentplayer->bondshotspeed[2] = 0;

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

bool playerSpawnAnti(struct chrdata *hostchr, bool force)
{
	struct prop *hostprop;
	union modelrwdata *chrrootrwdata;
	struct chrdata *playerchr = g_Vars.currentplayer->prop->chr;
	union modelrwdata *playerrootrwdata;

	hostprop = hostchr->prop;

	hostchr->chrflags |= CHRCFLAG_PERIMDISABLEDTMP;
	playerchr->hidden |= CHRHFLAG_00100000;
	playerchr->chrwidth = hostchr->chrwidth;

	if (chrMoveToPos(playerchr, &hostchr->prop->pos, hostchr->prop->rooms, chrGetInverseTheta(hostchr), false) || force) {
		if (hostchr->weapons_held[0] && hostchr->weapons_held[1]) {
			// Dual wielding
			struct weaponobj *weapon1 = hostchr->weapons_held[0]->weapon;
			struct weaponobj *weapon2 = hostchr->weapons_held[1]->weapon;

#if VERSION >= VERSION_NTSC_1_0
			invGiveSingleWeapon(weapon1->weaponnum);
			invGiveDoubleWeapon(weapon1->weaponnum, weapon1->weaponnum);
			bgunEquipWeapon2(HAND_RIGHT, weapon1->weaponnum);
			bgunEquipWeapon2(HAND_LEFT, weapon1->weaponnum);
#else
			invGiveDoubleWeapon(weapon1->weaponnum, weapon2->weaponnum);
			bgunEquipWeapon2(HAND_RIGHT, weapon1->weaponnum);
			bgunEquipWeapon2(HAND_LEFT, weapon2->weaponnum);
#endif
		} else if (hostchr->weapons_held[0]) {
			// Right hand only
			struct weaponobj *weapon = hostchr->weapons_held[0]->weapon;

			if (weapon->weaponnum == WEAPON_SUPERDRAGON) {
				invGiveSingleWeapon(WEAPON_DRAGON);
				bgunEquipWeapon2(HAND_RIGHT, WEAPON_DRAGON);
			} else {
				invGiveSingleWeapon(weapon->weaponnum);
				bgunEquipWeapon2(HAND_RIGHT, weapon->weaponnum);
			}
		} else if (hostchr->weapons_held[1]) {
			// Left hand only
			struct weaponobj *weapon = hostchr->weapons_held[1]->weapon;

			if (weapon->weaponnum == WEAPON_SUPERDRAGON) {
				invGiveSingleWeapon(WEAPON_DRAGON);
				bgunEquipWeapon2(HAND_RIGHT, WEAPON_DRAGON);
			} else {
				invGiveSingleWeapon(weapon->weaponnum);
				bgunEquipWeapon2(HAND_RIGHT, weapon->weaponnum);
			}
		} else {
			// Unarmed
			invGiveSingleWeapon(WEAPON_UNARMED);
			bgunEquipWeapon2(HAND_RIGHT, WEAPON_UNARMED);
		}

		g_Vars.currentplayer->invdowntime = TICKS(-40);
		g_Vars.currentplayer->usedowntime = TICKS(-40);

		bgunGiveMaxAmmo(true);

		g_Vars.currentplayer->bondhealth = (chrGetMaxDamage(hostchr) - hostchr->damage) * 0.125f;

		if (g_Vars.currentplayer->bondhealth > 1) {
			g_Vars.currentplayer->bondhealth = 1;
		}

		chrSetShield(playerchr, chrGetShield(hostchr));

		g_Vars.currentplayer->haschrbody = false;
		g_Vars.currentplayer->model00d4 = NULL;

		chr0f020d44(g_Vars.currentplayer->prop, false);

		if (hostchr->bodynum == BODY_SKEDAR) {
			g_Vars.antiheadnum = HEAD_MRBLONDE;
			g_Vars.antibodynum = BODY_MRBLONDE;
		} else {
			g_Vars.antiheadnum = hostchr->headnum;
			g_Vars.antibodynum = hostchr->bodynum;
		}

		playerTickChrBody();
		modelCopyAnimData(hostchr->model, playerchr->model);
		func0f02e9a0(playerchr, 12);

		chrrootrwdata = modelGetNodeRwData(hostchr->model, hostchr->model->filedata->rootnode);
		playerrootrwdata = modelGetNodeRwData(playerchr->model, playerchr->model->filedata->rootnode);

		playerrootrwdata->chrinfo = chrrootrwdata->chrinfo;

		if (playerrootrwdata->chrinfo.unk34.y < 10) {
			playerrootrwdata->chrinfo.unk34.y = 10;
		}

		if (playerrootrwdata->chrinfo.unk24.y < 10) {
			playerrootrwdata->chrinfo.unk24.y = 10;
		}

		playerchr->chrwidth = hostchr->chrwidth;
		g_Vars.currentplayer->bond2.width = hostchr->chrwidth;

		chr0f020d44(hostprop, true);
		propDeregisterRooms(hostprop);
		propDelist(hostprop);
		propDisable(hostprop);
		propFree(hostprop);

		return true;
	}

	hostchr->chrflags &= ~CHRCFLAG_PERIMDISABLEDTMP;

	return false;
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

	if (cheatIsActive(CHEAT_JOSHIELD)) {
		playerSetShieldFrac(1);
	}

	if (cheatIsActive(CHEAT_SUPERSHIELD)) {
		playerSetShieldFrac(1);
		g_Vars.currentplayer->armourscale = 2;
	}

	if (g_Vars.mplayerisrunning) {
		if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.anti) {
			numsqdists = 0;
			force = false;

			invGiveSingleWeapon(WEAPON_SUICIDEPILL);
			bgunEquipWeapon2(HAND_LEFT, WEAPON_NONE);
			bgunEquipWeapon2(HAND_RIGHT, WEAPON_UNARMED);

			if (g_Vars.lvframenum > 0) {
				s32 prevplayernum = g_Vars.currentplayernum;
				setCurrentPlayerNum(g_Vars.bondplayernum);
				bgun0f0a0c08(&sp84, &sp9c);
				mtx4RotateVec(currentPlayerGetUnk174c(), &sp9c, &sp90);
				mtx4TransformVec(currentPlayerGetUnk174c(), &sp84, &sp78);
				setCurrentPlayerNum(prevplayernum);
			}

			if (g_Vars.currentplayer->model00d4 == NULL) {
				playerTickChrBody();
			}

			for (i = 0; i < chrsGetNumSlots(); i++) {
				if (g_ChrSlots[i].model
						&& g_ChrSlots[i].prop
						&& (g_ChrSlots[i].hidden & CHRHFLAG_00400000)
						&& (g_ChrSlots[i].chrflags & CHRCFLAG_HIDDEN) == 0
						&& g_ChrSlots[i].prop->type == PROPTYPE_CHR
						&& !chrIsDead(&g_ChrSlots[i])
						&& (g_ChrSlots[i].prop->flags & PROPFLAG_ENABLED)) {
					if (g_Vars.bond->prop) {
						xdiff = g_ChrSlots[i].prop->pos.x - g_Vars.bond->prop->pos.x;
						ydiff = g_ChrSlots[i].prop->pos.y - g_Vars.bond->prop->pos.y;
						zdiff = g_ChrSlots[i].prop->pos.z - g_Vars.bond->prop->pos.z;
					} else {
						xdiff = g_ChrSlots[i].prop->pos.x - g_Vars.currentplayer->prop->pos.x;
						ydiff = g_ChrSlots[i].prop->pos.y - g_Vars.currentplayer->prop->pos.y;
						zdiff = g_ChrSlots[i].prop->pos.z - g_Vars.currentplayer->prop->pos.z;
					}

					sqdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

					if (g_Vars.lvframenum > 0
							&& (g_ChrSlots[i].hidden & CHRHFLAG_00800000)
							&& func0f06b39c(&sp78, &sp90, &g_ChrSlots[i].prop->pos, model0001af80(g_ChrSlots[i].model))
							&& (random() % 8)) {
						sqdist += 1000000;
					}

					// Insert sqdist to sorteddists, maintaining sort order,
					// and mirror the changes into the sortedchrs array.

					// Move j to the first sqdist that is further than the new one
					for (j = 0; j < numsqdists; j++) {
						if (sqdist < sorteddists[j]) {
							break;
						}
					}

					if (j < 10) {
						// Move the higher sorteddists forward, removing the highest item
						for (k = numsqdists; k > j; k--) {
							if (k < 10) {
								sortedchrs[k] = sortedchrs[k - 1];
								sorteddists[k] = sorteddists[k - 1];
							}
						}

						// Write new sqdist
						sortedchrs[j] = &g_ChrSlots[i];
						sorteddists[j] = sqdist;

						if (numsqdists < 9) {
							numsqdists++;
						}
					}
				}
			}

			// Randomly swap some of the earlier elements so the player
			// doesn't always spawn into the closest
			if (numsqdists > 1 && (random() % 2) == 0) {
				tmpchr = sortedchrs[0];
				sqdist = sorteddists[0];
				sortedchrs[0] = sortedchrs[1];
				sorteddists[0] = sorteddists[1];
				sortedchrs[1] = tmpchr;
				sorteddists[1] = sqdist;
			}

			if (numsqdists > 2 && (random() % 4) == 0) {
				tmpchr = sortedchrs[0];
				sqdist = sorteddists[0];
				sortedchrs[0] = sortedchrs[2];
				sorteddists[0] = sorteddists[2];
				sortedchrs[2] = tmpchr;
				sorteddists[2] = sqdist;
			}

			// Iterate sortedchrs in order and try to spawn into any of them.
			// The spawn may fail if the chr is on-screen, and potentially in
			// some other conditions such as the chr being too close to a wall.
			// If no chrs can be spawned into, iterate the list again but this
			// time allowing the spawn to happen on-screen (force = true).
			for (i = 0; i < numsqdists; i++) {
				if (playerSpawnAnti(sortedchrs[i], force)) {
					break;
				}

				if (i == numsqdists - 1) {
					i = 0;

					if (force) {
						break;
					}

					force = true;
				}
			}

			if (g_Vars.currentplayer->prop->chr) {
				g_Vars.currentplayer->prop->chr->blurdrugamount = 0;
				g_Vars.currentplayer->prop->chr->blurnumtimesdied = 0;
			}
		} else {
			bgunEquipWeapon2(HAND_LEFT, g_DefaultWeapons[HAND_LEFT]);
			bgunEquipWeapon2(HAND_RIGHT, g_DefaultWeapons[HAND_RIGHT]);

#if VERSION >= VERSION_NTSC_1_0
			if (g_Vars.currentplayer->model00d4 == NULL
					&& (IS8MB() || g_Vars.fourmeg2player || g_MpAllChrPtrs[g_Vars.currentplayernum] == NULL)) {
				playerTickChrBody();
			}
#else
			if (g_Vars.currentplayer->model00d4 == NULL) {
				playerTickChrBody();
			}
#endif
		}
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

	pb->width = 30;
}

void playersTickAllChrBodies(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		playerTickChrBody();
	}

	setCurrentPlayerNum(prevplayernum);
}

void playerChooseBodyAndHead(s32 *bodynum, s32 *headnum, s32 *arg2)
{
	s32 outfit;
	bool solo;

	if (g_Vars.antiplayernum >= 0
			&& g_Vars.currentplayer == g_Vars.anti
			&& g_Vars.antiheadnum >= 0
			&& g_Vars.antibodynum >= 0) {
		*headnum = g_Vars.antiheadnum;
		*bodynum = g_Vars.antibodynum;
		return;
	}

	if (g_Vars.normmplayerisrunning) {
		if (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum < mpGetNumHeads2()) {
			*headnum = mpGetHeadId(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum);
		} else {
			*headnum = g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpheadnum - mpGetNumHeads2();

			if (arg2) {
				*arg2 = true;
			}
		}

		*bodynum = mpGetBodyId(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.mpbodynum);
		return;
	}

	outfit = g_Vars.currentplayer->bondtype;
	solo = !(g_Vars.coopplayernum >= 0) || (g_Vars.currentplayer != g_Vars.coop);

	if (cheatIsActive(CHEAT_PLAYASELVIS)) {
		*bodynum = BODY_THEKING;
		*headnum = HEAD_ELVIS;
		return;
	}

	if (g_Vars.stagenum == STAGE_VILLA && lvGetDifficulty() >= DIFF_PA) {
		outfit = OUTFIT_NEGOTIATOR;
	}

	if (g_Vars.currentplayer->disguised) {
		switch (g_Vars.stagenum) {
		case STAGE_RESCUE:  outfit = OUTFIT_LAB; break;
		case STAGE_AIRBASE: outfit = OUTFIT_STEWARDESS; break;
		}
	}

	switch (outfit) {
	default:
	case OUTFIT_DEFAULT:
		*bodynum = BODY_DARK_COMBAT;
		*headnum = solo ? HEAD_DARK_COMBAT : HEAD_VD;
		break;
	case OUTFIT_ELVIS:
		*bodynum = BODY_THEKING;
		*headnum = solo ? HEAD_ELVIS : HEAD_ELVIS;
		break;
	case OUTFIT_TRENT:
		*bodynum = BODY_TRENT;
		*headnum = solo ? HEAD_TRENT : HEAD_TRENT;
		break;
	case OUTFIT_TRENCH:
		*bodynum = BODY_DARK_TRENCH;
		*headnum = solo ? HEAD_DARK_COMBAT : HEAD_VD;
		break;
	case OUTFIT_FROCK_RIPPED:
		*bodynum = BODY_DARK_RIPPED;
		*headnum = solo ? HEAD_DARK_FROCK : HEAD_VD;
		break;
	case OUTFIT_FROCK:
		*bodynum = BODY_DARK_FROCK;
		*headnum = solo ? HEAD_DARK_FROCK : HEAD_VD;
		break;
	case OUTFIT_LEATHER:
		*bodynum = BODY_DARK_LEATHER;
		*headnum = solo ? HEAD_DARK_COMBAT : HEAD_VD;
		break;
	case OUTFIT_DEEPSEA:
		*bodynum = BODY_DARKWET;
		*headnum = solo ? HEAD_DARK_COMBAT : HEAD_VD;
		break;
	case OUTFIT_WETSUIT:
		*bodynum = BODY_DARKAQUALUNG;
		*headnum = solo ? HEAD_DARKAQUA : HEAD_VD;
		break;
	case OUTFIT_SNOW:
		*bodynum = BODY_DARKSNOW;
		*headnum = solo ? HEAD_DARK_SNOW : HEAD_VD;
		break;
	case OUTFIT_LAB:
		*bodynum = BODY_DARKLAB;
		*headnum = solo ? HEAD_DARK_COMBAT : HEAD_VD;
		break;
	case OUTFIT_STEWARDESS:
		*bodynum = BODY_DARK_AF1;
		*headnum = solo ? HEAD_DARK_FROCK : HEAD_VD;
		break;
	case OUTFIT_NEGOTIATOR:
		*bodynum = BODY_DARK_NEGOTIATOR;
		*headnum = solo ? HEAD_DARK_FROCK : HEAD_VD;
		break;
	case OUTFIT_MRBLONDE:
		*bodynum = BODY_MRBLONDE;
		*headnum = solo ? HEAD_MRBLONDE : HEAD_MRBLONDE;
		break;
	case OUTFIT_MAIAN:
		*bodynum = BODY_ELVIS1;
		*headnum = solo ? HEAD_MAIAN_S : HEAD_MAIAN_S;
		break;
	}
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
		s32 sp100[4];
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

		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
			weaponnum = g_DefaultWeapons[0];
		}

		weaponmodelnum = playermgrGetModelOfWeapon(weaponnum);

		if (IS4MB()) {
			bodynum = BODY_DARK_COMBAT;
			headnum = HEAD_DARK_COMBAT;
		}

		if (!g_Vars.mplayerisrunning || (IS4MB() && PLAYERCOUNT() == 1)) {
			// 1 player
			if (g_Vars.currentplayer->gunmem2 == NULL) {
				if (!var8009dfc0 && bgun0f09e004(2)) {
					g_Vars.currentplayer->gunmem2 = bgunGetGunMem();
				} else {
					if (var8009dfc0);

					g_Vars.currentplayer->haschrbody = false;

					if (!var8009dfc0) {
						g_Vars.lockscreen = true;
					}
					return;
				}
			}

			offset1 = 0;
			var8007fc0c = 8;
			osSyncPrintf("Gunmem: 0x%08x\n", bgunGetGunMem());

			allocation = g_Vars.currentplayer->gunmem2;
			model = (struct model *)(allocation + offset1);
			osSyncPrintf("Gunmem: bondsub 0x%08x\n", (u32)model);
			offset1 += ALIGN64(sizeof(struct model));

			model->anim = (struct anim *)(allocation + offset1);
			osSyncPrintf("Gunmem: bondsub->anim 0x%08x\n", model->anim);
			offset1 += sizeof(struct anim);
			offset1 = ALIGN64(offset1);

			rwdatas = (union modelrwdata **)(allocation + offset1);
			osSyncPrintf("Gunmem: savedata 0x%08x\n", (u32)rwdatas);
			offset1 += 0x400;
			offset1 = ALIGN64(offset1);

			weaponobj = (struct weaponobj *)(allocation + offset1);
			osSyncPrintf("Gunmem: wo 0x%08x\n", (u32)weaponobj);
			offset1 += sizeof(struct weaponobj);
			offset1 = ALIGN64(offset1);

			offset2 = offset1 + ALIGN64(fileGetInflatedLength(g_HeadsAndBodies[bodynum].filenum));

			if (headnum >= 0) {
				offset2 += ALIGN64(fileGetInflatedLength(g_HeadsAndBodies[headnum].filenum));
			}

			if (weaponmodelnum >= 0) {
				offset2 += ALIGN64(fileGetInflatedLength(g_ModelStates[weaponmodelnum].fileid));
			}

			offset2 += 0x4000;
			bgunCalculateGunMemCapacity();
			spe8 = g_Vars.currentplayer->gunmem2 + offset2;
			func0f172e70(sp100, spe8, bgunCalculateGunMemCapacity() - offset2);
			bodyfiledata = func0f1a7794(g_HeadsAndBodies[bodynum].filenum, allocation + offset1, offset2 - offset1, sp100);
			offset1 = ALIGN64(fileGetSize(g_HeadsAndBodies[bodynum].filenum) + offset1);

			if (headnum >= 0) {
				headfiledata = func0f1a7794(g_HeadsAndBodies[headnum].filenum, allocation + offset1, offset2 - offset1, sp100);
				offset1 = ALIGN64(fileGetSize(g_HeadsAndBodies[headnum].filenum) + offset1);
			}

			modelCalculateRwDataLen(bodyfiledata);

			if (headfiledata != NULL) {
				modelCalculateRwDataLen(headfiledata);
			}

			modelInit(model, bodyfiledata, rwdatas, false);
			animInit(model->anim);

			model->unk02 = 256;

			func0f172f54(sp100);

			// @TODO: Figure out these arguments
			osSyncPrintf("Jo using %d bytes gunmem (gunmemsize %d)\n");
			osSyncPrintf("Gunmem: bondmeml 0x%08x size 0x%08x\n", bgunGetGunMem(), bgunCalculateGunMemCapacity());
			osSyncPrintf("Gunmem: tex block free 0x%08x\n");
			osSyncPrintf("Gunmem: Free at end %d\n");

			func0f172f54(sp100);
		} else {
			// 2-4 players
			if (g_HeadsAndBodies[bodynum].filedata == NULL) {
				g_HeadsAndBodies[bodynum].filedata = fileLoad(g_HeadsAndBodies[bodynum].filenum);
			}

			bodyfiledata = g_HeadsAndBodies[bodynum].filedata;

			if (g_HeadsAndBodies[bodynum].unk00_01) {
				headnum = -1;
			} else if (sp60) {
				headfiledata = func0f18e57c(headnum, &headnum);
			} else if (g_Vars.normmplayerisrunning && IS8MB()) {
				g_HeadsAndBodies[headnum].filedata = fileLoad(g_HeadsAndBodies[headnum].filenum);
				headfiledata = g_HeadsAndBodies[headnum].filedata;
				g_FileInfo[g_HeadsAndBodies[headnum].filenum].size = 0;
				bodyCalculateHeadOffset(headfiledata, headnum, bodynum);
			} else {
				if (g_HeadsAndBodies[headnum].filedata == NULL) {
					g_HeadsAndBodies[headnum].filedata = fileLoad(g_HeadsAndBodies[headnum].filenum);
				}

				headfiledata = g_HeadsAndBodies[headnum].filedata;
			}
		}

		g_Vars.currentplayer->model00d4 = func0f02ce8c(bodynum, headnum, bodyfiledata, headfiledata, false, model, true, true);

		chr0f020b14(g_Vars.currentplayer->prop, g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms, turnangle, 0);
		g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;
		chr = g_Vars.currentplayer->prop->chr;

		if (g_Vars.mplayerisrunning) {
			g_MpAllChrPtrs[g_Vars.currentplayernum] = chr;
			g_MpAllChrConfigPtrs[g_Vars.currentplayernum] = &g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base;
		}

		chr->chrflags |= CHRCFLAG_00000001;

		modelSetRootPosition(g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos);
		chrSetLookAngle(g_Vars.currentplayer->prop->chr, turnangle);

		chr->headnum = headnum;
		chr->bodynum = bodynum;
		chr->race = bodyGetRace(chr->bodynum);
		chr->chrwidth = g_Vars.currentplayer->bond2.width;

		g_Vars.currentplayer->vv_eyeheight = (s32)g_HeadsAndBodies[bodynum].height;

#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.antiplayernum >= 0
				&& g_Vars.currentplayer == g_Vars.anti
				&& g_Vars.currentplayer->vv_eyeheight > 159) {
			g_Vars.currentplayer->vv_eyeheight = 159;
		}
#endif

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
				weaponfiledata = func0f1a7794(g_ModelStates[weaponmodelnum].fileid, allocation + offset1, offset2 - offset1, sp100);
				fileGetSize(g_ModelStates[weaponmodelnum].fileid);
				modelCalculateRwDataLen(weaponfiledata);
			} else {
				weaponobj = NULL;
				weaponfiledata = NULL;
			}

			weaponCreateForChr(chr, weaponmodelnum, weaponnum, 0, weaponobj, weaponfiledata);
		}

		chr->fireslots[0] = bgunAllocateFireslot();
		func0f02e9a0(chr, 0);
		bmove0f0cb8c4(g_Vars.currentplayer);
	} else {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;

		if (chr->model->anim == NULL) {
			chr->chrflags |= CHRCFLAG_00000001;
			func0f02e9a0(chr, 0);
			modelSetRootPosition(g_Vars.currentplayer->model00d4, &g_Vars.currentplayer->prop->pos);
			chrSetLookAngle(g_Vars.currentplayer->prop->chr, turnangle);
			bmove0f0cb8c4(g_Vars.currentplayer);
		}
	}
}

void player0f0b9538(void)
{
	if (g_Vars.currentplayer->haschrbody) {
		if (!g_Vars.mplayerisrunning || (IS4MB() && PLAYERCOUNT() == 1)) {
			g_Vars.currentplayer->haschrbody = false;
			chr0f020d44(g_Vars.currentplayer->prop, false);
			g_Vars.currentplayer->model00d4 = NULL;
			bmove0f0cb8c4(g_Vars.currentplayer);
			bgun0f09df50();
			g_Vars.currentplayer->gunmem2 = NULL;
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
		for (i = 0; i < g_Vars.lvupdate240_60; i++) {
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
	if (g_IsTitleDemo) {
		mainChangeToStage(STAGE_TITLE);
	} else if (g_Vars.autocutplaying) {
		g_Vars.autocutfinished = true;
	} else {
		playerSetTickMode(TICKMODE_NORMAL);
		g_PlayerTriggerGeFadeIn = false;
		bmoveSetModeForAllPlayers(MOVEMODE_WALK);
	}
}

void playerPrepareWarpToPad(s16 pad)
{
	playerSetTickMode(TICKMODE_WARP);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	playersClearMemCamRoom();
	g_WarpPadId = pad;
}

void playerPrepareWarpType2(struct var8009ddec *cmd, s32 arg1, s32 arg2)
{
	playerSetTickMode(TICKMODE_WARP);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	playersClearMemCamRoom();
	g_WarpPadId = -1;
	var8009ddec = cmd;
	var8009de08 = arg1;
	var8009de0c = arg2;
}

void playerPrepareWarpType3(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5)
{
	playerSetTickMode(TICKMODE_WARP);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	playersClearMemCamRoom();
	g_WarpPadId = -1;
	var8009ddec = NULL;
	var8009ddf0 = arg0;
	var8009ddf4 = arg1;
	var8009ddf8 = arg2;
	var8009ddfc = arg3;
	var8009de00 = arg4;
	var8009de04 = arg5;
}

u32 var80070818 = 0x00000000;
u32 var8007081c = 0x00000000;
u32 var80070820 = 0x00000000;
u32 var80070824 = 0x00000000;
u32 var80070828 = 0x00000000;
u32 var8007082c = 0x3f800000;
u32 var80070830 = 0x00000000;
u32 var80070834 = 0x3f800000;
u32 var80070838 = 0x00000000;
u32 var8007083c = 0x00000000;
u32 g_GlobalMenuRoot = 0;

GLOBAL_ASM(
glabel playerExecutePreparedWarp
.late_rodata
glabel var7f1ad5cc
.word 0x40c907a9
.text
/*  f0b9cbc:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0b9cc0:	3c0f8007 */ 	lui	$t7,%hi(var80070818)
/*  f0b9cc4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0b9cc8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0b9ccc:	25ef0818 */ 	addiu	$t7,$t7,%lo(var80070818)
/*  f0b9cd0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0b9cd4:	27ae0058 */ 	addiu	$t6,$sp,0x58
/*  f0b9cd8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f0b9cdc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0b9ce0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0b9ce4:	3c0a8007 */ 	lui	$t2,%hi(var80070824)
/*  f0b9ce8:	254a0824 */ 	addiu	$t2,$t2,%lo(var80070824)
/*  f0b9cec:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f0b9cf0:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0b9cf4:	8d410000 */ 	lw	$at,0x0($t2)
/*  f0b9cf8:	27a9004c */ 	addiu	$t1,$sp,0x4c
/*  f0b9cfc:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f0b9d00:	ad210000 */ 	sw	$at,0x0($t1)
/*  f0b9d04:	8d410008 */ 	lw	$at,0x8($t2)
/*  f0b9d08:	3c188007 */ 	lui	$t8,%hi(var80070830)
/*  f0b9d0c:	27180830 */ 	addiu	$t8,$t8,%lo(var80070830)
/*  f0b9d10:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f0b9d14:	ad210008 */ 	sw	$at,0x8($t1)
/*  f0b9d18:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b9d1c:	27b90040 */ 	addiu	$t9,$sp,0x40
/*  f0b9d20:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f0b9d24:	af210000 */ 	sw	$at,0x0($t9)
/*  f0b9d28:	8f010008 */ 	lw	$at,0x8($t8)
/*  f0b9d2c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0b9d30:	af280004 */ 	sw	$t0,0x4($t9)
/*  f0b9d34:	0fc3060c */ 	jal	playerSetCameraMode
/*  f0b9d38:	af210008 */ 	sw	$at,0x8($t9)
/*  f0b9d3c:	3c04800a */ 	lui	$a0,%hi(g_WarpPadId)
/*  f0b9d40:	8484dde8 */ 	lh	$a0,%lo(g_WarpPadId)($a0)
/*  f0b9d44:	3c10800a */ 	lui	$s0,%hi(var8009ddec)
/*  f0b9d48:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9d4c:	0480000f */ 	bltz	$a0,.L0f0b9d8c
/*  f0b9d50:	2610ddec */ 	addiu	$s0,$s0,%lo(var8009ddec)
/*  f0b9d54:	0fc456ac */ 	jal	padUnpack
/*  f0b9d58:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9d5c:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9d60:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9d64:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9d68:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0b9d6c:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f0b9d70:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9d74:	e7ae005c */ 	swc1	$f14,0x5c($sp)
/*  f0b9d78:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9d7c:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*  f0b9d80:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9d84:	10000096 */ 	b	.L0f0b9fe0
/*  f0b9d88:	afac003c */ 	sw	$t4,0x3c($sp)
.L0f0b9d8c:
/*  f0b9d8c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f0b9d90:	3c04800a */ 	lui	$a0,%hi(var8009de04)
/*  f0b9d94:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9d98:	10400030 */ 	beqz	$v0,.L0f0b9e5c
/*  f0b9d9c:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9da0:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f0b9da4:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f0b9da8:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f0b9dac:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0b9db0:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0b9db4:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0b9db8:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0b9dbc:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f0b9dc0:	0fc456ac */ 	jal	padUnpack
/*  f0b9dc4:	8c440018 */ 	lw	$a0,0x18($v0)
/*  f0b9dc8:	3c09800a */ 	lui	$t1,%hi(var8009de08)
/*  f0b9dcc:	8d29de08 */ 	lw	$t1,%lo(var8009de08)($t1)
/*  f0b9dd0:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f0b9dd4:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9dd8:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9ddc:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9de0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0b9de4:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0b9de8:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9dec:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9df0:	1121007b */ 	beq	$t1,$at,.L0f0b9fe0
/*  f0b9df4:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9df8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f0b9dfc:	0c0068f4 */ 	jal	cosf
/*  f0b9e00:	c54c0014 */ 	lwc1	$f12,0x14($t2)
/*  f0b9e04:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f0b9e08:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e0c:	0c0068f7 */ 	jal	sinf
/*  f0b9e10:	c5ac0010 */ 	lwc1	$f12,0x10($t5)
/*  f0b9e14:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0b9e18:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0b9e1c:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f0b9e20:	e7b2004c */ 	swc1	$f18,0x4c($sp)
/*  f0b9e24:	0c0068f7 */ 	jal	sinf
/*  f0b9e28:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f0b9e2c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0b9e30:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f0b9e34:	0c0068f4 */ 	jal	cosf
/*  f0b9e38:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f0b9e3c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0b9e40:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e44:	0c0068f4 */ 	jal	cosf
/*  f0b9e48:	c72c0010 */ 	lwc1	$f12,0x10($t9)
/*  f0b9e4c:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0b9e50:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0b9e54:	10000062 */ 	b	.L0f0b9fe0
/*  f0b9e58:	e7a60054 */ 	swc1	$f6,0x54($sp)
.L0f0b9e5c:
/*  f0b9e5c:	0fc456ac */ 	jal	padUnpack
/*  f0b9e60:	8c84de04 */ 	lw	$a0,%lo(var8009de04)($a0)
/*  f0b9e64:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f0b9e68:	c7a20064 */ 	lwc1	$f2,0x64($sp)
/*  f0b9e6c:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f0b9e70:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0b9e74:	3c10800a */ 	lui	$s0,%hi(var8009ddf0)
/*  f0b9e78:	2610ddf0 */ 	addiu	$s0,$s0,%lo(var8009ddf0)
/*  f0b9e7c:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9e80:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0b9e84:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0b9e88:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f0b9e8c:	0c0068f7 */ 	jal	sinf
/*  f0b9e90:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0b9e94:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9e98:	0c0068f4 */ 	jal	cosf
/*  f0b9e9c:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ea0:	3c01800a */ 	lui	$at,%hi(var8009ddf8)
/*  f0b9ea4:	c42addf8 */ 	lwc1	$f10,%lo(var8009ddf8)($at)
/*  f0b9ea8:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f0b9eac:	3c01800a */ 	lui	$at,%hi(var8009de00)
/*  f0b9eb0:	c7ae0034 */ 	lwc1	$f14,0x34($sp)
/*  f0b9eb4:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0b9eb8:	c426de00 */ 	lwc1	$f6,%lo(var8009de00)($at)
/*  f0b9ebc:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0b9ec0:	3c01800a */ 	lui	$at,%hi(var8009ddfc)
/*  f0b9ec4:	c42addfc */ 	lwc1	$f10,%lo(var8009ddfc)($at)
/*  f0b9ec8:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f0b9ecc:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ed0:	46121100 */ 	add.s	$f4,$f2,$f18
/*  f0b9ed4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0b9ed8:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0b9edc:	0c0068f4 */ 	jal	cosf
/*  f0b9ee0:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f0b9ee4:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0b9ee8:	0c0068f7 */ 	jal	sinf
/*  f0b9eec:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9ef0:	3c01800a */ 	lui	$at,%hi(var8009ddf8)
/*  f0b9ef4:	c426ddf8 */ 	lwc1	$f6,%lo(var8009ddf8)($at)
/*  f0b9ef8:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0b9efc:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0b9f00:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9f04:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0b9f08:	46088280 */ 	add.s	$f10,$f16,$f8
/*  f0b9f0c:	0c0068f4 */ 	jal	cosf
/*  f0b9f10:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f0b9f14:	3c01800a */ 	lui	$at,%hi(var8009de00)
/*  f0b9f18:	c7ae0034 */ 	lwc1	$f14,0x34($sp)
/*  f0b9f1c:	c426de00 */ 	lwc1	$f6,%lo(var8009de00)($at)
/*  f0b9f20:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0b9f24:	c7b20058 */ 	lwc1	$f18,0x58($sp)
/*  f0b9f28:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f0b9f2c:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f0b9f30:	c60c0000 */ 	lwc1	$f12,0x0($s0)
/*  f0b9f34:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0b9f38:	460a4481 */ 	sub.s	$f18,$f8,$f10
/*  f0b9f3c:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f0b9f40:	0c0068f7 */ 	jal	sinf
/*  f0b9f44:	e7b20050 */ 	swc1	$f18,0x50($sp)
/*  f0b9f48:	3c017f1b */ 	lui	$at,%hi(var7f1ad5cc)
/*  f0b9f4c:	c42cd5cc */ 	lwc1	$f12,%lo(var7f1ad5cc)($at)
/*  f0b9f50:	3c01800a */ 	lui	$at,%hi(var8009ddf4)
/*  f0b9f54:	c428ddf4 */ 	lwc1	$f8,%lo(var8009ddf4)($at)
/*  f0b9f58:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f0b9f5c:	c42aa00c */ 	lwc1	$f10,%lo(g_Vars+0x4c)($at)
/*  f0b9f60:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0b9f64:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f0b9f68:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0b9f6c:	44800000 */ 	mtc1	$zero,$f0
/*  f0b9f70:	46048181 */ 	sub.s	$f6,$f16,$f4
/*  f0b9f74:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f0b9f78:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f0b9f7c:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f0b9f80:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f0b9f84:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9f88:	4602603e */ 	c.le.s	$f12,$f2
/*  f0b9f8c:	00000000 */ 	nop
/*  f0b9f90:	45020009 */ 	bc1fl	.L0f0b9fb8
/*  f0b9f94:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0b9f98:	460c1201 */ 	sub.s	$f8,$f2,$f12
.L0f0b9f9c:
/*  f0b9f9c:	e6080000 */ 	swc1	$f8,0x0($s0)
/*  f0b9fa0:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9fa4:	4602603e */ 	c.le.s	$f12,$f2
/*  f0b9fa8:	00000000 */ 	nop
/*  f0b9fac:	4503fffb */ 	bc1tl	.L0f0b9f9c
/*  f0b9fb0:	460c1201 */ 	sub.s	$f8,$f2,$f12
/*  f0b9fb4:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0b9fb8:
/*  f0b9fb8:	00000000 */ 	nop
/*  f0b9fbc:	45020009 */ 	bc1fl	.L0f0b9fe4
/*  f0b9fc0:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f0b9fc4:	460c1280 */ 	add.s	$f10,$f2,$f12
.L0f0b9fc8:
/*  f0b9fc8:	e60a0000 */ 	swc1	$f10,0x0($s0)
/*  f0b9fcc:	c6020000 */ 	lwc1	$f2,0x0($s0)
/*  f0b9fd0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0b9fd4:	00000000 */ 	nop
/*  f0b9fd8:	4503fffb */ 	bc1tl	.L0f0b9fc8
/*  f0b9fdc:	460c1280 */ 	add.s	$f10,$f2,$f12
.L0f0b9fe0:
/*  f0b9fe0:	8fa8003c */ 	lw	$t0,0x3c($sp)
.L0f0b9fe4:
/*  f0b9fe4:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0b9fe8:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f0b9fec:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f0b9ff0:	27a70030 */ 	addiu	$a3,$sp,0x30
/*  f0b9ff4:	0fc306e9 */ 	jal	player0f0c1ba4
/*  f0b9ff8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0b9ffc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ba000:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0ba004:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0ba008:	03e00008 */ 	jr	$ra
/*  f0ba00c:	00000000 */ 	nop
);

// Mismatch: Can't match the last section's pos
//void playerExecutePreparedWarp(void)
//{
//	struct pad pad; // 64
//	struct coord pos = {0, 0, 0}; // 58
//	struct coord look = {0, 0, 1}; // 4c
//	struct coord up = {0, 1, 0}; // 40
//	s32 room; // 3c
//	struct coord memcampos; // 30
//
//	playerSetCameraMode(CAMERAMODE_THIRDPERSON);
//
//	// d4c
//	if (g_WarpPadId >= 0) {
//		// Used by device and holo training to warp player back to room
//		padUnpack(g_WarpPadId, PADFIELD_POS | PADFIELD_ROOM, &pad);
//
//		pos.x = pad.pos.x;
//		pos.y = pad.pos.y;
//		pos.z = pad.pos.z;
//
//		memcampos.x = pad.pos.x;
//		memcampos.y = pad.pos.y;
//		memcampos.z = pad.pos.z;
//
//		room = pad.room;
//	} else /*d98*/ if (var8009ddec) {
//		// Used by AI command 00df, but that command is not used
//		pos.x = var8009ddec->pos.x;
//		pos.y = var8009ddec->pos.y;
//		pos.z = var8009ddec->pos.z;
//
//		padUnpack(var8009ddec->pad, PADFIELD_POS | PADFIELD_ROOM, &pad);
//
//		room = pad.room;
//
//		memcampos.x = pad.pos.x;
//		memcampos.y = pad.pos.y;
//		memcampos.z = pad.pos.z;
//
//		if (var8009de08 != 1) {
//			look.x = cosf(var8009ddec->look[1]) * sinf(var8009ddec->look[0]);
//			look.y = sinf(var8009ddec->look[1]);
//			look.z = cosf(var8009ddec->look[1]) * cosf(var8009ddec->look[0]);
//		}
//	} else {
//		// e5c
//		// Used by AI command 00f4, but that command is not used
//		padUnpack(var8009de04, PADFIELD_POS | PADFIELD_ROOM, &pad);
//
//		room = pad.room;
//
//		memcampos.f[0] = pad.pos.f[0];
//		memcampos.f[1] = pad.pos.f[1];
//		memcampos.f[2] = pad.pos.f[2];
//
//		pos.f[0] = sinf(var8009ddf0); cosf(var8009ddf0);
//		pos.f[0] = pos.f[0] * var8009ddf8 + memcampos.f[0];
//		pos.f[1] = memcampos.f[1] + var8009de00 + var8009ddfc;
//		pos.f[2] = cosf(var8009ddf0); sinf(var8009ddf0);
//		pos.f[2] = pos.f[2] * var8009ddf8 + memcampos.f[2];
//
//		cosf(var8009ddf0);
//		look.x = memcampos.f[0] - pos.f[0];
//		look.y = memcampos.f[1] + var8009de00 - pos.f[1];
//		sinf(var8009ddf0);
//		look.z = memcampos.f[2] - pos.f[2];
//
//		var8009ddf0 += var8009ddf4 * g_Vars.lvupdate240freal;
//
//		while (var8009ddf0 >= M_BADTAU) {
//			var8009ddf0 -= M_BADTAU;
//		}
//
//		while (var8009ddf0 < 0) {
//			var8009ddf0 += M_BADTAU;
//		}
//	}
//
//	player0f0c1ba4(&pos, &up, &look, &memcampos, room);
//}

void playerStartCutscene2(void)
{
	playerSetTickMode(TICKMODE_CUTSCENE);
	g_PlayerTriggerGeFadeIn = false;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	playersClearMemCamRoom();

#if PAL
	g_CutsceneCurAnimFrame240 = var8009e388pf;
	g_CutsceneCurAnimFrame60 = floorf(g_CutsceneCurAnimFrame240 + 0.01f);
#else
	g_CutsceneCurAnimFrame240 = g_CutsceneFrameOverrun240;
	g_CutsceneCurAnimFrame60 = g_CutsceneFrameOverrun240 >> 2;
#endif

	g_CutsceneBlurFrac = 0;
	var8009de2c = -1;
	g_InCutscene = 1;

	pakStopRumbleForAllPaks(true);
	g_Vars.in_cutscene = g_Vars.tickmode == TICKMODE_CUTSCENE && g_CutsceneCurAnimFrame60 < animGetNumFrames(g_CutsceneAnimNum) - 1;
	g_Vars.cutsceneskip60ths = 0;
}

void playerStartCutscene(s16 animnum)
{
	if ((!g_IsTitleDemo && !g_Vars.autocutplaying)
			|| !g_Vars.in_cutscene
			|| !g_CutsceneSkipRequested) {
		joyDisableTemporarily();

		if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
			g_CutsceneSkipRequested = false;
			g_CutsceneCurTotalFrame60f = 0;
		}

		if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
			playersTickAllChrBodies();
		}

		g_CutsceneAnimNum = animnum;

		if (g_Vars.currentplayer->haschrbody) {
			playerStartCutscene2();
		}
	}
}

void playerReorientForCutsceneStop(u32 arg0)
{
	struct coord sp94;
	struct coord sp88;
	struct coord sp7c;
	u8 sp7f;
	Mtxf sp38;
	s32 lastframe;
	f32 theta;
	u32 stack;

	var8009de2c = arg0;
	lastframe = animGetNumFrames(g_CutsceneAnimNum) - 1;
	anim00023d38(g_CutsceneAnimNum);
	sp7f = anim00023ab0(g_CutsceneAnimNum, lastframe);
	anim00023d0c();
	anim00024050(0, 0, &g_Skel20, g_CutsceneAnimNum, sp7f, &sp94, &sp88, &sp7c);
	mtx4LoadRotation(&sp94, &sp38);

	theta = atan2f(-sp38.m[2][0], -sp38.m[2][2]);
	theta = (M_BADTAU - theta) * 57.304901123047f;
	g_Vars.bond->vv_theta = theta;

	chrSetLookAngle(g_Vars.bond->prop->chr, (360 - theta) * 0.017450513318181f);
}

void playerTickCutscene(bool arg0)
{
	struct coord pos;
	struct coord up;
	struct coord look;
	struct coord sp178;
	struct coord sp16c;
	struct coord sp160;
	u8 sp15f;
	Mtxf sp11c;
	f32 sp118 = func0f15c888();
	f32 fovy;
	s32 endframe;
	s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
	u16 buttons;
#if PAL
	u8 stack3[0x2c];
#endif
	f32 barfrac;
	f32 sp104;
	Mtxf spc4;
	Mtxf sp84;
	f32 sp74[4];
	f32 sp64[4];
	f32 sp54[4];

	if (arg0) {
		buttons = joyGetButtons(contpadnum, 0xffff);
	} else {
		buttons = 0;
	}

	anim00023d38(g_CutsceneAnimNum);

	endframe = animGetNumFrames(g_CutsceneAnimNum) - 1;

	if (g_Vars.currentplayerindex == 0) {
		g_Vars.cutsceneskip60ths = 0;

		if (g_CutsceneCurAnimFrame60 < endframe) {
#if PAL
			g_CutsceneCurAnimFrame240 += g_Vars.lvupdate240freal;
			g_CutsceneCurAnimFrame60 = floorf(g_CutsceneCurAnimFrame240 + 0.01f);
#else
			g_CutsceneCurAnimFrame240 += g_Vars.lvupdate240;
			g_CutsceneCurAnimFrame60 = g_CutsceneCurAnimFrame240 >> 2;
#endif

			if (g_Anims[g_CutsceneAnimNum].flags & ANIMFLAG_08) {
				while (g_CutsceneCurAnimFrame60 < endframe && anim000239e0(g_CutsceneAnimNum, g_CutsceneCurAnimFrame60)) {
#if PAL
					g_CutsceneCurAnimFrame240 += 1.2f;
					g_CutsceneCurAnimFrame60 = floorf(g_CutsceneCurAnimFrame240 + 0.01f);
#else
					g_CutsceneCurAnimFrame60++;
					g_CutsceneCurAnimFrame240 += 4;
#endif

					g_Vars.cutsceneskip60ths++;
				}
			}

			if (g_CutsceneCurAnimFrame60 >= endframe) {
#if PAL
				var8009e388pf = g_CutsceneCurAnimFrame240 - endframe;
#else
				g_CutsceneFrameOverrun240 = g_CutsceneCurAnimFrame240 - endframe * 4;
#endif
			}

			if (g_CutsceneCurAnimFrame60 > endframe) {
				g_CutsceneCurAnimFrame60 = endframe;
			}
		}
	}

	g_Vars.in_cutscene = (g_Vars.tickmode == TICKMODE_CUTSCENE && g_CutsceneCurAnimFrame60 < endframe);
	sp15f = anim00023ab0(g_CutsceneAnimNum, g_CutsceneCurAnimFrame60);
	anim00023d0c();
	anim00024050(0, 0, &g_Skel20, g_CutsceneAnimNum, sp15f, &sp178, &sp16c, &sp160);

	pos.x = sp16c.x * sp118;
	pos.y = sp16c.y * sp118;
	pos.z = sp16c.z * sp118;

	mtx4LoadRotation(&sp178, &sp11c);

	up.x = sp11c.m[1][0];
	up.y = sp11c.m[1][1];
	up.z = sp11c.m[1][2];

	look.x = -sp11c.m[2][0];
	look.y = -sp11c.m[2][1];
	look.z = -sp11c.m[2][2];

	fovy = anim00024c14(1, g_CutsceneAnimNum, sp15f);
	g_CutsceneBlurFrac = anim00024c14(2, g_CutsceneAnimNum, sp15f);
	g_CutsceneBarFrac = 0;

	if (var8009de2c > 0 && var8009de2c >= endframe - g_CutsceneCurAnimFrame60) {
		barfrac = 1 - (f32)(endframe - g_CutsceneCurAnimFrame60) / (f32)var8009de2c;

		g_CutsceneBarFrac = barfrac;
		sp104 = 1 - cosf(1.5705462694168f * barfrac);

		bmoveSetMode(MOVEMODE_WALK);

		pos.x += sp104 * (g_Vars.bond->bond2.unk10.x - pos.x);
		pos.y += sp104 * (g_Vars.bond->bond2.unk10.y - pos.y);
		pos.z += sp104 * (g_Vars.bond->bond2.unk10.z - pos.z);

		mtx00016d58(&spc4, 0, 0, 0, -look.x, -look.y, -look.z, up.x, up.y, up.z);
		mtx00016d58(&sp84, 0, 0, 0,
				-g_Vars.bond->bond2.unk1c.x, -g_Vars.bond->bond2.unk1c.y, -g_Vars.bond->bond2.unk1c.z,
				g_Vars.bond->bond2.unk28.x, g_Vars.bond->bond2.unk28.y, g_Vars.bond->bond2.unk28.z);
		quaternion0f097044(&spc4, sp74);
		quaternion0f097044(&sp84, sp64);
		quaternion0f0976c0(sp64, sp74);
		quaternionSlerp(sp74, sp64, sp104, sp54);
		quaternionToMtx(sp54, &sp11c);

		up.x = sp11c.m[1][0];
		up.y = sp11c.m[1][1];
		up.z = sp11c.m[1][2];

		look.x = sp11c.m[2][0];
		look.y = sp11c.m[2][1];
		look.z = sp11c.m[2][2];

		g_CutsceneBlurFrac += barfrac * (0 - g_CutsceneBlurFrac);
		fovy += barfrac * (60 - fovy);
	}

	playerSetCameraMode(CAMERAMODE_THIRDPERSON);
	player0f0c1bd8(&pos, &up, &look);
	playermgrSetFovY(fovy);
	viSetFovY(fovy);

	if (g_Vars.currentplayerindex == 0) {
		g_CutsceneCurTotalFrame60f += g_Vars.lvupdate240freal;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_CutsceneCurTotalFrame60f > 30 && (buttons & 0xffff)) {
		g_CutsceneSkipRequested = true;

		if (g_Vars.autocutplaying) {
			if (buttons & (B_BUTTON | START_BUTTON)) {
				g_Vars.autocutgroupskip = true;
			} else {
				g_Vars.autocutfinished = true;
			}
		}
	}
#else
	if (g_CutsceneCurTotalFrame60f > 30) {
		if (buttons & 0xffff) {
			g_CutsceneSkipRequested = true;
		}

		if ((buttons & (B_BUTTON | START_BUTTON)) && g_Vars.autocutplaying) {
			g_Vars.autocutgroupskip = true;
		}
	}
#endif
}

f32 playerGetCutsceneBlurFrac(void)
{
	return g_CutsceneBlurFrac;
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
		g_Vars.currentplayer->zoomintime += g_Vars.lvupdate240freal;

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

	alarmStopAudio();
	gasStopAudio();

	for (i = 0; i < 2; i++) {
		hand = &g_Vars.currentplayer->hands[i];

		if (hand->audiohandle2 && sndGetState(hand->audiohandle2) != AL_STOPPED) {
			audioStop(hand->audiohandle2);
		}
	}
}

void playerTickPauseMenu(void)
{
	bool opened = false;

	switch (g_Vars.currentplayer->pausemode) {
	case PAUSEMODE_UNPAUSED:
		break;
	case PAUSEMODE_PAUSING:
		// Pause menu is opening
		switch (g_GlobalMenuRoot) {
		case MENUROOT_TRAINING:
		case MENUROOT_MAINMENU:
			opened = soloChoosePauseDialog();
			break;
		case MENUROOT_FILEMGR:
			opened = filemgrConsiderPushingFileSelectDialog();
			break;
		case MENUROOT_4MBMAINMENU:
		case MENUROOT_MPSETUP:
			opened = true;
			break;
		}

		if (opened) {
			struct trainingdata *data = dtGetData();
			lvSetPaused(true);
			g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;

			if ((g_GlobalMenuRoot == MENUROOT_MAINMENU || g_GlobalMenuRoot == MENUROOT_TRAINING)
					&& g_Vars.stagenum == STAGE_CITRAINING) {
				s32 room = g_Vars.currentplayer->prop->rooms[0];

				if ((room >= ROOM_DISH_HOLO1 && room <= ROOM_DISH_HOLO4)
						|| room == ROOM_DISH_FIRINGRANGE
						|| room == ROOM_DISH_DEVICELAB
						|| (data && data->intraining)) {
					return;
				}
			}

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

		gSPMatrix(gdl++, 0x80000000 + (u32)a, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
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
		g_Vars.currentplayer->colourfadetime60 += g_Vars.lvupdate240freal;

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

		g_Vars.currentplayer->bondfadetime60 += g_Vars.lvupdate240freal;

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
				inc = g_Vars.lvupdate240freal;
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

bool playerIsDamageVisible(void)
{
	return g_Vars.currentplayer->damageshowtime >= 0;
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

	gdl = healthbarRender(gdl, 0, 0, 0);

	gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	return gdl;
}

void playerSurroundWithExplosions(s32 arg0)
{
	g_Vars.currentplayer->bondexploding = true;
	g_Vars.currentplayer->bondnextexplode = arg0 + g_Vars.lvframe60;
	g_Vars.currentplayer->bondcurexplode = 0;
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
		case 0: pos.x += 250.0f + 150.0f * (random() * (1.0f / U32_MAX)); break;
		case 1: pos.x -= 250.0f + 150.0f * (random() * (1.0f / U32_MAX)); break;
		case 2: pos.z += 250.0f + 150.0f * (random() * (1.0f / U32_MAX)); break;
		case 3: pos.z -= 250.0f + 150.0f * (random() * (1.0f / U32_MAX)); break;
		}

		pos.y += 200.0f * (random() * (1.0f / U32_MAX)) - 100.0f;

		explosionCreateSimple(NULL, &pos, g_Vars.currentplayer->prop->rooms, EXPLOSIONTYPE_18, g_Vars.currentplayernum);

		g_Vars.currentplayer->bondnextexplode = g_Vars.lvframe60 + TICKS(15) + (random() % TICKS(15));
	}
}

void playerResetLoResIf4Mb(void)
{
	if (IS4MB()) {
#if VERSION >= VERSION_PAL_BETA
		g_ViModes[VIRES_LO].fbwidth = 320;
		g_ViModes[VIRES_LO].fbheight = 220;
		g_ViModes[VIRES_LO].width = 320;
		g_ViModes[VIRES_LO].yscale = 1;
		g_ViModes[VIRES_LO].xscale = 1;
		g_ViModes[VIRES_LO].fullheight = 220;
		g_ViModes[VIRES_LO].fulltop = 0;
#else
		g_ViModes[VIRES_LO].fbheight = 220;
		g_ViModes[VIRES_LO].fulltop = 0;
		g_ViModes[VIRES_LO].fullheight = 220;
#endif

		g_ViModes[VIRES_LO].wideheight = 180;
		g_ViModes[VIRES_LO].widetop = 20;
		g_ViModes[VIRES_LO].cinemaheight = 136;
		g_ViModes[VIRES_LO].cinematop = 42;
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

#if VERSION >= VERSION_NTSC_1_0
bool playerHasSharedViewport(void)
{
	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& menuGetRoot() == MENUROOT_MPENDSCREEN
			&& var8009dfc0 == 0) {
		return true;
	}

	return (g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE;
}
#endif

s16 playerGetViewportWidth(void)
{
	s16 width;

#if VERSION >= VERSION_NTSC_1_0
	if (!playerHasSharedViewport())
#else
	if ((!g_InCutscene || g_MainIsEndscreen) && menuGetRoot() != MENUROOT_COOPCONTINUE)
#endif
	{
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
	} else {
		// Probably cutscene
		width = g_ViModes[g_ViRes].width;
	}

	return width;
}

s16 playerGetViewportLeft(void)
{
#if VERSION >= VERSION_NTSC_1_0
	s32 something = !playerHasSharedViewport();
#else
	s32 something = !((g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE);
#endif
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

	if (PLAYERCOUNT() >= 2
#if VERSION >= VERSION_NTSC_1_0
			&& !playerHasSharedViewport()
#else
			&& !((g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE)
#endif
			) {
		s16 tmp = g_ViModes[g_ViRes].fullheight;

		if (IS4MB() && !g_Vars.fourmeg2player) {
			height = tmp;
		} else {
			height = tmp / 2;
		}

		if (PLAYERCOUNT() == 2) {
			if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
				height = tmp;
			} else if (g_Vars.currentplayernum == 0 && IS8MB()) {
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
		} else if (g_InCutscene && !var8009dfc0) {
			if (var8009de2c >= 1) {
				f32 a = g_ViModes[g_ViRes].wideheight;
				f32 b = g_ViModes[g_ViRes].fullheight;
				a = a * (1.0f - g_CutsceneBarFrac);
				b = b * g_CutsceneBarFrac;
				height = a + b;
			} else {
				height = g_ViModes[g_ViRes].wideheight;
			}
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

	if (PLAYERCOUNT() >= 2
#if VERSION >= VERSION_NTSC_1_0
			&& !playerHasSharedViewport()
#else
			&& !((g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE)
#endif
			) {
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
			if (g_InCutscene && optionsGetCutsceneSubtitles() && g_Vars.stagenum != STAGE_CITRAINING) {
				if (var8009de2c >= 1) {
					f32 a = g_ViModes[g_ViRes].fulltop;
					f32 b = g_ViModes[g_ViRes].widetop;
					a = a * (1.0f - g_CutsceneBarFrac);
					b = b * g_CutsceneBarFrac;
					top = a + b;
				} else {
					top = g_ViModes[g_ViRes].fulltop;
				}
			} else {
				top = g_ViModes[g_ViRes].widetop;
			}
		} else if (optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
			top = g_ViModes[g_ViRes].cinematop;
		} else {
			if (g_InCutscene && !var8009dfc0
					&& (!optionsGetCutsceneSubtitles() || g_Vars.stagenum == STAGE_CITRAINING)) {
				if (var8009de2c >= 1) {
					f32 a = g_ViModes[g_ViRes].widetop;
					f32 b = g_ViModes[g_ViRes].fulltop;
					a = a * (1.0f - g_CutsceneBarFrac);
					b = b * g_CutsceneBarFrac;
					top = a + b;
				} else {
					top = g_ViModes[g_ViRes].widetop;
				}
			} else {
				return g_ViModes[g_ViRes].fulltop;
			}
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
		func0f12acec(&g_Vars.currentplayer->bond2.unk10, &g_Vars.currentplayer->bond2.unk1c, &coord);
	} else {
		viShake(0);
	}
}

void playerAutoWalk(s16 aimpad, u8 walkspeed, u8 turnspeed, u8 lookup, u8 dist)
{
	playerSetTickMode(TICKMODE_AUTOWALK);

	g_Vars.currentplayer->autocontrol_aimpad = aimpad;
	g_Vars.currentplayer->autocontrol_walkspeed = walkspeed;
	g_Vars.currentplayer->autocontrol_turnspeed = turnspeed;
	g_Vars.currentplayer->autocontrol_lookup = lookup;
	g_Vars.currentplayer->autocontrol_dist = dist;
}

void playerLaunchSlayerRocket(struct weaponobj *rocket)
{
	g_Vars.currentplayer->slayerrocket = rocket;
	g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKET;

	// Turn off these devices
	g_Vars.currentplayer->devicesactive &= ~(
			DEVICE_NIGHTVISION |
			DEVICE_XRAYSCANNER |
			DEVICE_EYESPY |
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
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate240_60;

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
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate240_60;

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
		u32 time = g_Vars.currentplayer->teleporttime + g_Vars.lvupdate240_60;

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

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel playerConfigureVi
/*  f0be800:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0be804:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0be808:	0fc2f8fd */ 	jal	0xf0be3f4
/*  f0be80c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0be810:	3c018007 */ 	lui	$at,0x8007
/*  f0be814:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0be818:	ac200c18 */ 	sw	$zero,0xc18($at)
/*  f0be81c:	0fc54a23 */ 	jal	0xf15288c
/*  f0be820:	00002025 */ 	move	$a0,$zero
/*  f0be824:	3c018008 */ 	lui	$at,0x8008
/*  f0be828:	ac2000f0 */ 	sw	$zero,0xf0($at)
/*  f0be82c:	3c014270 */ 	lui	$at,0x4270
/*  f0be830:	44816000 */ 	mtc1	$at,$f12
/*  f0be834:	0fc4a3b7 */ 	jal	0xf128edc
/*  f0be838:	00000000 */ 	nop
/*  f0be83c:	0fc4a3bb */ 	jal	0xf128eec
/*  f0be840:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0be844:	0fc2f57c */ 	jal	0xf0bd5f0
/*  f0be848:	00000000 */ 	nop
/*  f0be84c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be850:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0be854:	0fc2f6cf */ 	jal	0xf0bdb3c
/*  f0be858:	01c08025 */ 	move	$s0,$t6
/*  f0be85c:	02002025 */ 	move	$a0,$s0
/*  f0be860:	0fc4a3a9 */ 	jal	0xf128ea4
/*  f0be864:	00402825 */ 	move	$a1,$v0
/*  f0be868:	0fc2f612 */ 	jal	0xf0bd848
/*  f0be86c:	00000000 */ 	nop
/*  f0be870:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be874:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0be878:	0fc2f7b0 */ 	jal	0xf0bdec0
/*  f0be87c:	01e08025 */ 	move	$s0,$t7
/*  f0be880:	02002025 */ 	move	$a0,$s0
/*  f0be884:	0fc4a3b0 */ 	jal	0xf128ec0
/*  f0be888:	00402825 */ 	move	$a1,$v0
/*  f0be88c:	3c188007 */ 	lui	$t8,0x8007
/*  f0be890:	8f180c18 */ 	lw	$t8,0xc18($t8)
/*  f0be894:	3c048007 */ 	lui	$a0,0x8007
/*  f0be898:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0be89c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0be8a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0be8a4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0be8a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0be8ac:	00992021 */ 	addu	$a0,$a0,$t9
/*  f0be8b0:	0c002a95 */ 	jal	0xaa54
/*  f0be8b4:	8c840bd0 */ 	lw	$a0,0xbd0($a0)
/*  f0be8b8:	0fc2f57c */ 	jal	0xf0bd5f0
/*  f0be8bc:	00000000 */ 	nop
/*  f0be8c0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be8c4:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0be8c8:	0fc2f6cf */ 	jal	0xf0bdb3c
/*  f0be8cc:	01008025 */ 	move	$s0,$t0
/*  f0be8d0:	3c014270 */ 	lui	$at,0x4270
/*  f0be8d4:	00103400 */ 	sll	$a2,$s0,0x10
/*  f0be8d8:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0be8dc:	00075403 */ 	sra	$t2,$a3,0x10
/*  f0be8e0:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0be8e4:	44816000 */ 	mtc1	$at,$f12
/*  f0be8e8:	01203025 */ 	move	$a2,$t1
/*  f0be8ec:	01403825 */ 	move	$a3,$t2
/*  f0be8f0:	0c002f5f */ 	jal	0xbd7c
/*  f0be8f4:	c7ae0024 */ 	lwc1	$f14,0x24($sp)
/*  f0be8f8:	0fc2f612 */ 	jal	0xf0bd848
/*  f0be8fc:	00000000 */ 	nop
/*  f0be900:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be904:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0be908:	0fc2f7b0 */ 	jal	0xf0bdec0
/*  f0be90c:	01608025 */ 	move	$s0,$t3
/*  f0be910:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be914:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be918:	00056c03 */ 	sra	$t5,$a1,0x10
/*  f0be91c:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0be920:	01802025 */ 	move	$a0,$t4
/*  f0be924:	0c002f13 */ 	jal	0xbc4c
/*  f0be928:	01a02825 */ 	move	$a1,$t5
/*  f0be92c:	0fc2f53a */ 	jal	0xf0bd4e8
/*  f0be930:	00000000 */ 	nop
/*  f0be934:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be938:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0be93c:	0fc2f545 */ 	jal	0xf0bd514
/*  f0be940:	01c08025 */ 	move	$s0,$t6
/*  f0be944:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be948:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be94c:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0be950:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f0be954:	01e02025 */ 	move	$a0,$t7
/*  f0be958:	0c002ee2 */ 	jal	0xbb88
/*  f0be95c:	03002825 */ 	move	$a1,$t8
/*  f0be960:	0fc2f53a */ 	jal	0xf0bd4e8
/*  f0be964:	00000000 */ 	nop
/*  f0be968:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be96c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0be970:	0fc2f545 */ 	jal	0xf0bd514
/*  f0be974:	03208025 */ 	move	$s0,$t9
/*  f0be978:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be97c:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be980:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f0be984:	00044403 */ 	sra	$t0,$a0,0x10
/*  f0be988:	01002025 */ 	move	$a0,$t0
/*  f0be98c:	0c002ed1 */ 	jal	0xbb44
/*  f0be990:	01202825 */ 	move	$a1,$t1
/*  f0be994:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0be998:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0be99c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0be9a0:	03e00008 */ 	jr	$ra
/*  f0be9a4:	00000000 */ 	nop
);
#else
void playerConfigureVi(void)
{
	f32 ratio = player0f0bd358();
	g_ViRes = VIRES_LO;

	func0f1531dc(false);

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
#endif

#if VERSION >= VERSION_JPN_FINAL
const char var7f1af224pb[] = "tps";
struct coord var800726acpb = {0, 0, 0};
struct coord var800726b8pb = {0, 0, 1};
struct coord var800726c4pb = {0, 1, 0};

GLOBAL_ASM(
glabel playerTick
.late_rodata
glabel var7f1af390
.word 0x3faaaaab
.word 0x3983126f
.word 0x3d4ccccd
.word 0x3d4ccccd
.word 0x3c8ef461
.word 0x40c907a9
.word 0x40490fdb
.word 0xc0490fdb
.word 0xbdb851ec
.word 0x3db851ec
.word 0xbe4ccccd
.word 0x3e4ccccd
.text
/*  f0be9a8:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f0be9ac:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0be9b0:	3c13800a */ 	lui	$s3,0x800a
/*  f0be9b4:	2673a630 */ 	addiu	$s3,$s3,-22992
/*  f0be9b8:	8e6f0298 */ 	lw	$t7,0x298($s3)
/*  f0be9bc:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0be9c0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0be9c4:	8dce0c1c */ 	lw	$t6,0xc1c($t6)
/*  f0be9c8:	3c118007 */ 	lui	$s1,0x8007
/*  f0be9cc:	26310c18 */ 	addiu	$s1,$s1,0xc18
/*  f0be9d0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0be9d4:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0be9d8:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0be9dc:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0be9e0:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0be9e4:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0be9e8:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0be9ec:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f0be9f0:	05e10004 */ 	bgez	$t7,.JF0f0bea04
/*  f0be9f4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0be9f8:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f0be9fc:	07020020 */ 	bltzl	$t8,.JF0f0bea80
/*  f0bea00:	8e2f0000 */ 	lw	$t7,0x0($s1)
.JF0f0bea04:
/*  f0bea04:	8e79006c */ 	lw	$t9,0x6c($s3)
/*  f0bea08:	00003825 */ 	move	$a3,$zero
/*  f0bea0c:	00002825 */ 	move	$a1,$zero
/*  f0bea10:	13200003 */ 	beqz	$t9,.JF0f0bea20
/*  f0bea14:	00002025 */ 	move	$a0,$zero
/*  f0bea18:	10000001 */ 	b	.JF0f0bea20
/*  f0bea1c:	24070001 */ 	li	$a3,0x1
.JF0f0bea20:
/*  f0bea20:	8e690068 */ 	lw	$t1,0x68($s3)
/*  f0bea24:	00001025 */ 	move	$v0,$zero
/*  f0bea28:	11200003 */ 	beqz	$t1,.JF0f0bea38
/*  f0bea2c:	00000000 */ 	nop
/*  f0bea30:	10000001 */ 	b	.JF0f0bea38
/*  f0bea34:	24050001 */ 	li	$a1,0x1
.JF0f0bea38:
/*  f0bea38:	8e6a0064 */ 	lw	$t2,0x64($s3)
/*  f0bea3c:	11400003 */ 	beqz	$t2,.JF0f0bea4c
/*  f0bea40:	00000000 */ 	nop
/*  f0bea44:	10000001 */ 	b	.JF0f0bea4c
/*  f0bea48:	24040001 */ 	li	$a0,0x1
.JF0f0bea4c:
/*  f0bea4c:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f0bea50:	11600003 */ 	beqz	$t3,.JF0f0bea60
/*  f0bea54:	00000000 */ 	nop
/*  f0bea58:	10000001 */ 	b	.JF0f0bea60
/*  f0bea5c:	24020001 */ 	li	$v0,0x1
.JF0f0bea60:
/*  f0bea60:	00446021 */ 	addu	$t4,$v0,$a0
/*  f0bea64:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0bea68:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f0bea6c:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0bea70:	54200003 */ 	bnezl	$at,.JF0f0bea80
/*  f0bea74:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bea78:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0bea7c:	8e2f0000 */ 	lw	$t7,0x0($s1)
.JF0f0bea80:
/*  f0bea80:	24010001 */ 	li	$at,0x1
/*  f0bea84:	15e10005 */ 	bne	$t7,$at,.JF0f0bea9c
/*  f0bea88:	00000000 */ 	nop
/*  f0bea8c:	0fc54a23 */ 	jal	0xf15288c
/*  f0bea90:	24040001 */ 	li	$a0,0x1
/*  f0bea94:	10000003 */ 	b	.JF0f0beaa4
/*  f0bea98:	00000000 */ 	nop
.JF0f0bea9c:
/*  f0bea9c:	0fc54a23 */ 	jal	0xf15288c
/*  f0beaa0:	00002025 */ 	move	$a0,$zero
.JF0f0beaa4:
/*  f0beaa4:	3c018008 */ 	lui	$at,0x8008
/*  f0beaa8:	0fc54972 */ 	jal	0xf1525c8
/*  f0beaac:	ac2000f0 */ 	sw	$zero,0xf0($at)
/*  f0beab0:	24010001 */ 	li	$at,0x1
/*  f0beab4:	14410008 */ 	bne	$v0,$at,.JF0f0bead8
/*  f0beab8:	00000000 */ 	nop
/*  f0beabc:	0fc2f8fd */ 	jal	0xf0be3f4
/*  f0beac0:	00000000 */ 	nop
/*  f0beac4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0beac8:	c424e3b0 */ 	lwc1	$f4,-0x1c50($at)
/*  f0beacc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0bead0:	10000004 */ 	b	.JF0f0beae4
/*  f0bead4:	e7a6032c */ 	swc1	$f6,0x32c($sp)
.JF0f0bead8:
/*  f0bead8:	0fc2f8fd */ 	jal	0xf0be3f4
/*  f0beadc:	00000000 */ 	nop
/*  f0beae0:	e7a0032c */ 	swc1	$f0,0x32c($sp)
.JF0f0beae4:
/*  f0beae4:	3c108007 */ 	lui	$s0,0x8007
/*  f0beae8:	26100d8c */ 	addiu	$s0,$s0,0xd8c
/*  f0beaec:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0beaf0:	2484e254 */ 	addiu	$a0,$a0,-7596
/*  f0beaf4:	0c0036b4 */ 	jal	0xdad0
/*  f0beaf8:	02002825 */ 	move	$a1,$s0
/*  f0beafc:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0beb00:	53000008 */ 	beqzl	$t8,.JF0f0beb24
/*  f0beb04:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0beb08:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0beb0c:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f0beb10:	24150001 */ 	li	$s5,0x1
/*  f0beb14:	a3201bfd */ 	sb	$zero,0x1bfd($t9)
/*  f0beb18:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0beb1c:	a1351bfc */ 	sb	$s5,0x1bfc($t1)
/*  f0beb20:	8e6a0284 */ 	lw	$t2,0x284($s3)
.JF0f0beb24:
/*  f0beb24:	24150001 */ 	li	$s5,0x1
/*  f0beb28:	914b1bfc */ 	lbu	$t3,0x1bfc($t2)
/*  f0beb2c:	51600004 */ 	beqzl	$t3,.JF0f0beb40
/*  f0beb30:	8e6c04b4 */ 	lw	$t4,0x4b4($s3)
/*  f0beb34:	0fc2f960 */ 	jal	0xf0be580
/*  f0beb38:	27a4032c */ 	addiu	$a0,$sp,0x32c
/*  f0beb3c:	8e6c04b4 */ 	lw	$t4,0x4b4($s3)
.JF0f0beb40:
/*  f0beb40:	2401004e */ 	li	$at,0x4e
/*  f0beb44:	5581000a */ 	bnel	$t4,$at,.JF0f0beb70
/*  f0beb48:	3c014270 */ 	lui	$at,0x4270
/*  f0beb4c:	0fc06fbb */ 	jal	0xf01beec
/*  f0beb50:	00000000 */ 	nop
/*  f0beb54:	50400006 */ 	beqzl	$v0,.JF0f0beb70
/*  f0beb58:	3c014270 */ 	lui	$at,0x4270
/*  f0beb5c:	0fc06fd2 */ 	jal	0xf01bf48
/*  f0beb60:	00000000 */ 	nop
/*  f0beb64:	10000838 */ 	b	.JF0f0c0c48
/*  f0beb68:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0beb6c:	3c014270 */ 	lui	$at,0x4270
.JF0f0beb70:
/*  f0beb70:	44816000 */ 	mtc1	$at,$f12
/*  f0beb74:	0fc4a3b7 */ 	jal	0xf128edc
/*  f0beb78:	00000000 */ 	nop
/*  f0beb7c:	0fc4a3bb */ 	jal	0xf128eec
/*  f0beb80:	c7ac032c */ 	lwc1	$f12,0x32c($sp)
/*  f0beb84:	0fc2f57c */ 	jal	0xf0bd5f0
/*  f0beb88:	00000000 */ 	nop
/*  f0beb8c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0beb90:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0beb94:	0fc2f6cf */ 	jal	0xf0bdb3c
/*  f0beb98:	01a08025 */ 	move	$s0,$t5
/*  f0beb9c:	02002025 */ 	move	$a0,$s0
/*  f0beba0:	0fc4a3a9 */ 	jal	0xf128ea4
/*  f0beba4:	00402825 */ 	move	$a1,$v0
/*  f0beba8:	0fc2f612 */ 	jal	0xf0bd848
/*  f0bebac:	00000000 */ 	nop
/*  f0bebb0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bebb4:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bebb8:	0fc2f7b0 */ 	jal	0xf0bdec0
/*  f0bebbc:	01c08025 */ 	move	$s0,$t6
/*  f0bebc0:	02002025 */ 	move	$a0,$s0
/*  f0bebc4:	0fc4a3b0 */ 	jal	0xf128ec0
/*  f0bebc8:	00402825 */ 	move	$a1,$v0
/*  f0bebcc:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bebd0:	3c048007 */ 	lui	$a0,0x8007
/*  f0bebd4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0bebd8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bebdc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bebe0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0bebe4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0bebe8:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0bebec:	0c002a95 */ 	jal	0xaa54
/*  f0bebf0:	8c840bd0 */ 	lw	$a0,0xbd0($a0)
/*  f0bebf4:	0fc2f57c */ 	jal	0xf0bd5f0
/*  f0bebf8:	00000000 */ 	nop
/*  f0bebfc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bec00:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0bec04:	0fc2f6cf */ 	jal	0xf0bdb3c
/*  f0bec08:	03208025 */ 	move	$s0,$t9
/*  f0bec0c:	3c014270 */ 	lui	$at,0x4270
/*  f0bec10:	00103400 */ 	sll	$a2,$s0,0x10
/*  f0bec14:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0bec18:	00075403 */ 	sra	$t2,$a3,0x10
/*  f0bec1c:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0bec20:	44816000 */ 	mtc1	$at,$f12
/*  f0bec24:	01203025 */ 	move	$a2,$t1
/*  f0bec28:	01403825 */ 	move	$a3,$t2
/*  f0bec2c:	0c002f5f */ 	jal	0xbd7c
/*  f0bec30:	c7ae032c */ 	lwc1	$f14,0x32c($sp)
/*  f0bec34:	0fc2f612 */ 	jal	0xf0bd848
/*  f0bec38:	00000000 */ 	nop
/*  f0bec3c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bec40:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0bec44:	0fc2f7b0 */ 	jal	0xf0bdec0
/*  f0bec48:	01608025 */ 	move	$s0,$t3
/*  f0bec4c:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bec50:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bec54:	00056c03 */ 	sra	$t5,$a1,0x10
/*  f0bec58:	00046403 */ 	sra	$t4,$a0,0x10
/*  f0bec5c:	01802025 */ 	move	$a0,$t4
/*  f0bec60:	0c002f13 */ 	jal	0xbc4c
/*  f0bec64:	01a02825 */ 	move	$a1,$t5
/*  f0bec68:	0fc2f53a */ 	jal	0xf0bd4e8
/*  f0bec6c:	00000000 */ 	nop
/*  f0bec70:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bec74:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0bec78:	0fc2f545 */ 	jal	0xf0bd514
/*  f0bec7c:	01c08025 */ 	move	$s0,$t6
/*  f0bec80:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0bec84:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0bec88:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0bec8c:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f0bec90:	01e02025 */ 	move	$a0,$t7
/*  f0bec94:	0c002ee2 */ 	jal	0xbb88
/*  f0bec98:	03002825 */ 	move	$a1,$t8
/*  f0bec9c:	0fc2f53a */ 	jal	0xf0bd4e8
/*  f0beca0:	00000000 */ 	nop
/*  f0beca4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0beca8:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0becac:	0fc2f545 */ 	jal	0xf0bd514
/*  f0becb0:	03208025 */ 	move	$s0,$t9
/*  f0becb4:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0becb8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0becbc:	00055403 */ 	sra	$t2,$a1,0x10
/*  f0becc0:	00044c03 */ 	sra	$t1,$a0,0x10
/*  f0becc4:	01202025 */ 	move	$a0,$t1
/*  f0becc8:	0c002ed1 */ 	jal	0xbb44
/*  f0beccc:	01402825 */ 	move	$a1,$t2
/*  f0becd0:	0fc2f12b */ 	jal	0xf0bc4ac
/*  f0becd4:	00000000 */ 	nop
/*  f0becd8:	0fc2f19b */ 	jal	0xf0bc66c
/*  f0becdc:	00000000 */ 	nop
/*  f0bece0:	8e6b0288 */ 	lw	$t3,0x288($s3)
/*  f0bece4:	0fc54771 */ 	jal	0xf151dc4
/*  f0bece8:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0becec:	0fc322b8 */ 	jal	0xf0c8ae0
/*  f0becf0:	00402025 */ 	move	$a0,$v0
/*  f0becf4:	8e6c0288 */ 	lw	$t4,0x288($s3)
/*  f0becf8:	0fc54771 */ 	jal	0xf151dc4
/*  f0becfc:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0bed00:	0fc32309 */ 	jal	0xf0c8c24
/*  f0bed04:	00402025 */ 	move	$a0,$v0
/*  f0bed08:	8e6d0288 */ 	lw	$t5,0x288($s3)
/*  f0bed0c:	0fc5477a */ 	jal	0xf151de8
/*  f0bed10:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0bed14:	0fc322b0 */ 	jal	0xf0c8ac0
/*  f0bed18:	00402025 */ 	move	$a0,$v0
/*  f0bed1c:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f0bed20:	0fc54795 */ 	jal	0xf151e54
/*  f0bed24:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0bed28:	02a02025 */ 	move	$a0,$s5
/*  f0bed2c:	0fc2a99b */ 	jal	0xf0aa66c
/*  f0bed30:	00402825 */ 	move	$a1,$v0
/*  f0bed34:	02a02025 */ 	move	$a0,$s5
/*  f0bed38:	0fc2b33e */ 	jal	0xf0accf8
/*  f0bed3c:	24050001 */ 	li	$a1,0x1
/*  f0bed40:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bed44:	10600002 */ 	beqz	$v1,.JF0f0bed50
/*  f0bed48:	24010001 */ 	li	$at,0x1
/*  f0bed4c:	1461000d */ 	bne	$v1,$at,.JF0f0bed84
.JF0f0bed50:
/*  f0bed50:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0bed54:	8def0cb4 */ 	lw	$t7,0xcb4($t7)
/*  f0bed58:	3c188006 */ 	lui	$t8,0x8006
/*  f0bed5c:	55e0000a */ 	bnezl	$t7,.JF0f0bed88
/*  f0bed60:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0bed64:	8f18d880 */ 	lw	$t8,-0x2780($t8)
/*  f0bed68:	57000007 */ 	bnezl	$t8,.JF0f0bed88
/*  f0bed6c:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0bed70:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bed74:	8e690038 */ 	lw	$t1,0x38($s3)
/*  f0bed78:	8e191b7c */ 	lw	$t9,0x1b7c($s0)
/*  f0bed7c:	03295021 */ 	addu	$t2,$t9,$t1
/*  f0bed80:	ae0a1b7c */ 	sw	$t2,0x1b7c($s0)
.JF0f0bed84:
/*  f0bed84:	8e6b0284 */ 	lw	$t3,0x284($s3)
.JF0f0bed88:
/*  f0bed88:	8d6c00c4 */ 	lw	$t4,0xc4($t3)
/*  f0bed8c:	318d0020 */ 	andi	$t5,$t4,0x20
/*  f0bed90:	11a00004 */ 	beqz	$t5,.JF0f0beda4
/*  f0bed94:	00000000 */ 	nop
/*  f0bed98:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0bed9c:	0fc3092f */ 	jal	0xf0c24bc
/*  f0beda0:	24050001 */ 	li	$a1,0x1
.JF0f0beda4:
/*  f0beda4:	0fc2f225 */ 	jal	0xf0bc894
/*  f0beda8:	00000000 */ 	nop
/*  f0bedac:	0fc2f468 */ 	jal	0xf0bd1a0
/*  f0bedb0:	00000000 */ 	nop
/*  f0bedb4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bedb8:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f0bedbc:	1040008c */ 	beqz	$v0,.JF0f0beff0
/*  f0bedc0:	00000000 */ 	nop
/*  f0bedc4:	8e6e02ac */ 	lw	$t6,0x2ac($s3)
/*  f0bedc8:	24010006 */ 	li	$at,0x6
/*  f0bedcc:	00409025 */ 	move	$s2,$v0
/*  f0bedd0:	15c10014 */ 	bne	$t6,$at,.JF0f0bee24
/*  f0bedd4:	8e71028c */ 	lw	$s1,0x28c($s3)
/*  f0bedd8:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0beddc:	24050001 */ 	li	$a1,0x1
/*  f0bede0:	3406ffff */ 	li	$a2,0xffff
/*  f0bede4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f0bede8:	a2400035 */ 	sb	$zero,0x35($s2)
/*  f0bedec:	a2550034 */ 	sb	$s5,0x34($s2)
/*  f0bedf0:	0fc24d13 */ 	jal	0xf09344c
/*  f0bedf4:	a2400037 */ 	sb	$zero,0x37($s2)
/*  f0bedf8:	8e2f0018 */ 	lw	$t7,0x18($s1)
/*  f0bedfc:	2401fffb */ 	li	$at,-5
/*  f0bee00:	35f80400 */ 	ori	$t8,$t7,0x400
/*  f0bee04:	ae380018 */ 	sw	$t8,0x18($s1)
/*  f0bee08:	37090010 */ 	ori	$t1,$t8,0x10
/*  f0bee0c:	ae290018 */ 	sw	$t1,0x18($s1)
/*  f0bee10:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bee14:	8e0a00c4 */ 	lw	$t2,0xc4($s0)
/*  f0bee18:	01415824 */ 	and	$t3,$t2,$at
/*  f0bee1c:	10000074 */ 	b	.JF0f0beff0
/*  f0bee20:	ae0b00c4 */ 	sw	$t3,0xc4($s0)
.JF0f0bee24:
/*  f0bee24:	924c0034 */ 	lbu	$t4,0x34($s2)
/*  f0bee28:	5580002c */ 	bnezl	$t4,.JF0f0beedc
/*  f0bee2c:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
/*  f0bee30:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0bee34:	51a00022 */ 	beqzl	$t5,.JF0f0beec0
/*  f0bee38:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bee3c:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f0bee40:	0fc5475a */ 	jal	0xf151d68
/*  f0bee44:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0bee48:	8fb80330 */ 	lw	$t8,0x330($sp)
/*  f0bee4c:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0bee50:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bee54:	13000005 */ 	beqz	$t8,.JF0f0bee6c
/*  f0bee58:	01e02025 */ 	move	$a0,$t7
/*  f0bee5c:	0c0053be */ 	jal	0x14ef8
/*  f0bee60:	3405ffff */ 	li	$a1,0xffff
/*  f0bee64:	10000002 */ 	b	.JF0f0bee70
/*  f0bee68:	3043ffff */ 	andi	$v1,$v0,0xffff
.JF0f0bee6c:
/*  f0bee6c:	00001825 */ 	move	$v1,$zero
.JF0f0bee70:
/*  f0bee70:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bee74:	8e1900d8 */ 	lw	$t9,0xd8($s0)
/*  f0bee78:	57200011 */ 	bnezl	$t9,.JF0f0beec0
/*  f0bee7c:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bee80:	8e091a24 */ 	lw	$t1,0x1a24($s0)
/*  f0bee84:	306a1000 */ 	andi	$t2,$v1,0x1000
/*  f0bee88:	5520000d */ 	bnezl	$t1,.JF0f0beec0
/*  f0bee8c:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bee90:	5140000b */ 	beqzl	$t2,.JF0f0beec0
/*  f0bee94:	8e6c0034 */ 	lw	$t4,0x34($s3)
/*  f0bee98:	8e6b0314 */ 	lw	$t3,0x314($s3)
/*  f0bee9c:	15600005 */ 	bnez	$t3,.JF0f0beeb4
/*  f0beea0:	00000000 */ 	nop
/*  f0beea4:	0fc2efe3 */ 	jal	0xf0bbf8c
/*  f0beea8:	24040002 */ 	li	$a0,0x2
/*  f0beeac:	10000004 */ 	b	.JF0f0beec0
/*  f0beeb0:	8e6c0034 */ 	lw	$t4,0x34($s3)
.JF0f0beeb4:
/*  f0beeb4:	0fc5e4e5 */ 	jal	0xf179394
/*  f0beeb8:	00000000 */ 	nop
/*  f0beebc:	8e6c0034 */ 	lw	$t4,0x34($s3)
.JF0f0beec0:
/*  f0beec0:	5180001d */ 	beqzl	$t4,.JF0f0bef38
/*  f0beec4:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0beec8:	0fc3467a */ 	jal	0xf0d19e8
/*  f0beecc:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0beed0:	10000019 */ 	b	.JF0f0bef38
/*  f0beed4:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0beed8:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
.JF0f0beedc:
/*  f0beedc:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f0beee0:	00114880 */ 	sll	$t1,$s1,0x2
/*  f0beee4:	01c07827 */ 	nor	$t7,$t6,$zero
/*  f0beee8:	01afc024 */ 	and	$t8,$t5,$t7
/*  f0beeec:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0beef0:	13200010 */ 	beqz	$t9,.JF0f0bef34
/*  f0beef4:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0beef8:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0beefc:	8d4a0ca0 */ 	lw	$t2,0xca0($t2)
/*  f0bef00:	5140000d */ 	beqzl	$t2,.JF0f0bef38
/*  f0bef04:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bef08:	0fc344f4 */ 	jal	0xf0d13d0
/*  f0bef0c:	00000000 */ 	nop
/*  f0bef10:	54400009 */ 	bnezl	$v0,.JF0f0bef38
/*  f0bef14:	924e0035 */ 	lbu	$t6,0x35($s2)
/*  f0bef18:	a2550034 */ 	sb	$s5,0x34($s2)
/*  f0bef1c:	a2400037 */ 	sb	$zero,0x37($s2)
/*  f0bef20:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bef24:	2401fffb */ 	li	$at,-5
/*  f0bef28:	8e0b00c4 */ 	lw	$t3,0xc4($s0)
/*  f0bef2c:	01616024 */ 	and	$t4,$t3,$at
/*  f0bef30:	ae0c00c4 */ 	sw	$t4,0xc4($s0)
.JF0f0bef34:
/*  f0bef34:	924e0035 */ 	lbu	$t6,0x35($s2)
.JF0f0bef38:
/*  f0bef38:	00116880 */ 	sll	$t5,$s1,0x2
/*  f0bef3c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0bef40:	11c0002b */ 	beqz	$t6,.JF0f0beff0
/*  f0bef44:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f0bef48:	8def0ca0 */ 	lw	$t7,0xca0($t7)
/*  f0bef4c:	11e00028 */ 	beqz	$t7,.JF0f0beff0
/*  f0bef50:	00000000 */ 	nop
/*  f0bef54:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bef58:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f0bef5c:	8e1800c4 */ 	lw	$t8,0xc4($s0)
/*  f0bef60:	03204827 */ 	nor	$t1,$t9,$zero
/*  f0bef64:	03095024 */ 	and	$t2,$t8,$t1
/*  f0bef68:	314b0004 */ 	andi	$t3,$t2,0x4
/*  f0bef6c:	11600020 */ 	beqz	$t3,.JF0f0beff0
/*  f0bef70:	00000000 */ 	nop
/*  f0bef74:	824c0037 */ 	lb	$t4,0x37($s2)
/*  f0bef78:	240e0001 */ 	li	$t6,0x1
/*  f0bef7c:	240f000a */ 	li	$t7,0xa
/*  f0bef80:	15800019 */ 	bnez	$t4,.JF0f0befe8
/*  f0bef84:	3c048009 */ 	lui	$a0,0x8009
/*  f0bef88:	a2400039 */ 	sb	$zero,0x39($s2)
/*  f0bef8c:	824d0039 */ 	lb	$t5,0x39($s2)
/*  f0bef90:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0bef94:	a24e0037 */ 	sb	$t6,0x37($s2)
/*  f0bef98:	a2400068 */ 	sb	$zero,0x68($s2)
/*  f0bef9c:	a2400036 */ 	sb	$zero,0x36($s2)
/*  f0befa0:	a24d0038 */ 	sb	$t5,0x38($s2)
/*  f0befa4:	8f380004 */ 	lw	$t8,0x4($t9)
/*  f0befa8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0befac:	44814000 */ 	mtc1	$at,$f8
/*  f0befb0:	af0f0120 */ 	sw	$t7,0x120($t8)
/*  f0befb4:	2409ffff */ 	li	$t1,-1
/*  f0befb8:	240affff */ 	li	$t2,-1
/*  f0befbc:	240bffff */ 	li	$t3,-1
/*  f0befc0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0befc4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0befc8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0befcc:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f0befd0:	240580ab */ 	li	$a1,-32597
/*  f0befd4:	00003025 */ 	move	$a2,$zero
/*  f0befd8:	2407ffff */ 	li	$a3,-1
/*  f0befdc:	0c004230 */ 	jal	0x108c0
/*  f0befe0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0befe4:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0befe8:
/*  f0befe8:	2411ffd8 */ 	li	$s1,-40
/*  f0befec:	a611024c */ 	sh	$s1,0x24c($s0)
.JF0f0beff0:
/*  f0beff0:	0fc5b3cc */ 	jal	0xf16cf30
/*  f0beff4:	2411ffd8 */ 	li	$s1,-40
/*  f0beff8:	50400004 */ 	beqzl	$v0,.JF0f0bf00c
/*  f0beffc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf000:	0fc2ef58 */ 	jal	0xf0bbd60
/*  f0bf004:	00000000 */ 	nop
/*  f0bf008:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0bf00c:
/*  f0bf00c:	8e0c1a24 */ 	lw	$t4,0x1a24($s0)
/*  f0bf010:	51800005 */ 	beqzl	$t4,.JF0f0bf028
/*  f0bf014:	960e0010 */ 	lhu	$t6,0x10($s0)
/*  f0bf018:	0fc2ef7b */ 	jal	0xf0bbdec
/*  f0bf01c:	00000000 */ 	nop
/*  f0bf020:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf024:	960e0010 */ 	lhu	$t6,0x10($s0)
.JF0f0bf028:
/*  f0bf028:	24010002 */ 	li	$at,0x2
/*  f0bf02c:	55c1000c */ 	bnel	$t6,$at,.JF0f0bf060
/*  f0bf030:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bf034:	8e0d0264 */ 	lw	$t5,0x264($s0)
/*  f0bf038:	51a00005 */ 	beqzl	$t5,.JF0f0bf050
/*  f0bf03c:	ae000264 */ 	sw	$zero,0x264($s0)
/*  f0bf040:	8e1900d8 */ 	lw	$t9,0xd8($s0)
/*  f0bf044:	53200006 */ 	beqzl	$t9,.JF0f0bf060
/*  f0bf048:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0bf04c:	ae000264 */ 	sw	$zero,0x264($s0)
.JF0f0bf050:
/*  f0bf050:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f0bf054:	240f0003 */ 	li	$t7,0x3
/*  f0bf058:	a70f0010 */ 	sh	$t7,0x10($t8)
/*  f0bf05c:	8e6302ac */ 	lw	$v1,0x2ac($s3)
.JF0f0bf060:
/*  f0bf060:	24010006 */ 	li	$at,0x6
/*  f0bf064:	10610002 */ 	beq	$v1,$at,.JF0f0bf070
/*  f0bf068:	3c018007 */ 	lui	$at,0x8007
/*  f0bf06c:	ac200cb4 */ 	sw	$zero,0xcb4($at)
.JF0f0bf070:
/*  f0bf070:	24010006 */ 	li	$at,0x6
/*  f0bf074:	54610054 */ 	bnel	$v1,$at,.JF0f0bf1c8
/*  f0bf078:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf07c:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0bf080:	00000000 */ 	nop
/*  f0bf084:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf088:	00002025 */ 	move	$a0,$zero
/*  f0bf08c:	00002825 */ 	move	$a1,$zero
/*  f0bf090:	8e0919c8 */ 	lw	$t1,0x19c8($s0)
/*  f0bf094:	00003025 */ 	move	$a2,$zero
/*  f0bf098:	24070001 */ 	li	$a3,0x1
/*  f0bf09c:	51200008 */ 	beqzl	$t1,.JF0f0bf0c0
/*  f0bf0a0:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f0bf0a4:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bf0a8:	a611024c */ 	sh	$s1,0x24c($s0)
/*  f0bf0ac:	0fc2ecc7 */ 	jal	0xf0bb31c
/*  f0bf0b0:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0bf0b4:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0bf0b8:	a551024c */ 	sh	$s1,0x24c($t2)
/*  f0bf0bc:	8e6b006c */ 	lw	$t3,0x6c($s3)
.JF0f0bf0c0:
/*  f0bf0c0:	00003025 */ 	move	$a2,$zero
/*  f0bf0c4:	00003825 */ 	move	$a3,$zero
/*  f0bf0c8:	11600003 */ 	beqz	$t3,.JF0f0bf0d8
/*  f0bf0cc:	00002825 */ 	move	$a1,$zero
/*  f0bf0d0:	10000001 */ 	b	.JF0f0bf0d8
/*  f0bf0d4:	24070001 */ 	li	$a3,0x1
.JF0f0bf0d8:
/*  f0bf0d8:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f0bf0dc:	00002025 */ 	move	$a0,$zero
/*  f0bf0e0:	00001025 */ 	move	$v0,$zero
/*  f0bf0e4:	11800003 */ 	beqz	$t4,.JF0f0bf0f4
/*  f0bf0e8:	00064880 */ 	sll	$t1,$a2,0x2
/*  f0bf0ec:	10000001 */ 	b	.JF0f0bf0f4
/*  f0bf0f0:	24050001 */ 	li	$a1,0x1
.JF0f0bf0f4:
/*  f0bf0f4:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f0bf0f8:	02691821 */ 	addu	$v1,$s3,$t1
/*  f0bf0fc:	2408ffff */ 	li	$t0,-1
/*  f0bf100:	11c00003 */ 	beqz	$t6,.JF0f0bf110
/*  f0bf104:	00000000 */ 	nop
/*  f0bf108:	10000001 */ 	b	.JF0f0bf110
/*  f0bf10c:	24040001 */ 	li	$a0,0x1
.JF0f0bf110:
/*  f0bf110:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f0bf114:	11a00003 */ 	beqz	$t5,.JF0f0bf124
/*  f0bf118:	00000000 */ 	nop
/*  f0bf11c:	10000001 */ 	b	.JF0f0bf124
/*  f0bf120:	24020001 */ 	li	$v0,0x1
.JF0f0bf124:
/*  f0bf124:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0bf128:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0bf12c:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0bf130:	1b000022 */ 	blez	$t8,.JF0f0bf1bc
/*  f0bf134:	00000000 */ 	nop
/*  f0bf138:	8c6a0064 */ 	lw	$t2,0x64($v1)
.JF0f0bf13c:
/*  f0bf13c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0bf140:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0bf144:	ad481c40 */ 	sw	$t0,0x1c40($t2)
/*  f0bf148:	8e6b006c */ 	lw	$t3,0x6c($s3)
/*  f0bf14c:	00003825 */ 	move	$a3,$zero
/*  f0bf150:	00002825 */ 	move	$a1,$zero
/*  f0bf154:	11600003 */ 	beqz	$t3,.JF0f0bf164
/*  f0bf158:	00002025 */ 	move	$a0,$zero
/*  f0bf15c:	10000001 */ 	b	.JF0f0bf164
/*  f0bf160:	24070001 */ 	li	$a3,0x1
.JF0f0bf164:
/*  f0bf164:	8e6c0068 */ 	lw	$t4,0x68($s3)
/*  f0bf168:	00001025 */ 	move	$v0,$zero
/*  f0bf16c:	11800003 */ 	beqz	$t4,.JF0f0bf17c
/*  f0bf170:	00000000 */ 	nop
/*  f0bf174:	10000001 */ 	b	.JF0f0bf17c
/*  f0bf178:	24050001 */ 	li	$a1,0x1
.JF0f0bf17c:
/*  f0bf17c:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f0bf180:	11c00003 */ 	beqz	$t6,.JF0f0bf190
/*  f0bf184:	00000000 */ 	nop
/*  f0bf188:	10000001 */ 	b	.JF0f0bf190
/*  f0bf18c:	24040001 */ 	li	$a0,0x1
.JF0f0bf190:
/*  f0bf190:	8e6d0070 */ 	lw	$t5,0x70($s3)
/*  f0bf194:	11a00003 */ 	beqz	$t5,.JF0f0bf1a4
/*  f0bf198:	00000000 */ 	nop
/*  f0bf19c:	10000001 */ 	b	.JF0f0bf1a4
/*  f0bf1a0:	24020001 */ 	li	$v0,0x1
.JF0f0bf1a4:
/*  f0bf1a4:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0bf1a8:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0bf1ac:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0bf1b0:	00d8082a */ 	slt	$at,$a2,$t8
/*  f0bf1b4:	5420ffe1 */ 	bnezl	$at,.JF0f0bf13c
/*  f0bf1b8:	8c6a0064 */ 	lw	$t2,0x64($v1)
.JF0f0bf1bc:
/*  f0bf1bc:	1000060b */ 	b	.JF0f0c09ec
/*  f0bf1c0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf1c4:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0bf1c8:
/*  f0bf1c8:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f0bf1cc:	50400033 */ 	beqzl	$v0,.JF0f0bf29c
/*  f0bf1d0:	920d1bfc */ 	lbu	$t5,0x1bfc($s0)
/*  f0bf1d4:	8e0a1c54 */ 	lw	$t2,0x1c54($s0)
/*  f0bf1d8:	8e0900c4 */ 	lw	$t1,0xc4($s0)
/*  f0bf1dc:	01405827 */ 	nor	$t3,$t2,$zero
/*  f0bf1e0:	012b6024 */ 	and	$t4,$t1,$t3
/*  f0bf1e4:	318e0004 */ 	andi	$t6,$t4,0x4
/*  f0bf1e8:	51c0002c */ 	beqzl	$t6,.JF0f0bf29c
/*  f0bf1ec:	920d1bfc */ 	lbu	$t5,0x1bfc($s0)
/*  f0bf1f0:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0bf1f4:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0bf1f8:	51a00028 */ 	beqzl	$t5,.JF0f0bf29c
/*  f0bf1fc:	920d1bfc */ 	lbu	$t5,0x1bfc($s0)
/*  f0bf200:	4481a000 */ 	mtc1	$at,$f20
/*  f0bf204:	0fc4a3b7 */ 	jal	0xf128edc
/*  f0bf208:	4600a306 */ 	mov.s	$f12,$f20
/*  f0bf20c:	0c002f35 */ 	jal	0xbcd4
/*  f0bf210:	4600a306 */ 	mov.s	$f12,$f20
/*  f0bf214:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf218:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f0bf21c:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f0bf220:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f0bf224:	e7aa0308 */ 	swc1	$f10,0x308($sp)
/*  f0bf228:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f0bf22c:	8f0a0000 */ 	lw	$t2,0x0($t8)
/*  f0bf230:	c552000c */ 	lwc1	$f18,0xc($t2)
/*  f0bf234:	e7b2030c */ 	swc1	$f18,0x30c($sp)
/*  f0bf238:	8e090480 */ 	lw	$t1,0x480($s0)
/*  f0bf23c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0bf240:	c5640010 */ 	lwc1	$f4,0x10($t3)
/*  f0bf244:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0bf248:	e7a40310 */ 	swc1	$f4,0x310($sp)
/*  f0bf24c:	00002025 */ 	move	$a0,$zero
/*  f0bf250:	00002825 */ 	move	$a1,$zero
/*  f0bf254:	00003025 */ 	move	$a2,$zero
/*  f0bf258:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bf25c:	24070001 */ 	li	$a3,0x1
/*  f0bf260:	0fc30a3a */ 	jal	0xf0c28e8
/*  f0bf264:	24040002 */ 	li	$a0,0x2
/*  f0bf268:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0bf26c:	27a40308 */ 	addiu	$a0,$sp,0x308
/*  f0bf270:	8d820480 */ 	lw	$v0,0x480($t4)
/*  f0bf274:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f0bf278:	24450010 */ 	addiu	$a1,$v0,0x10
/*  f0bf27c:	24460004 */ 	addiu	$a2,$v0,0x4
/*  f0bf280:	246e0028 */ 	addiu	$t6,$v1,0x28
/*  f0bf284:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0bf288:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0bf28c:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bf290:	100005d6 */ 	b	.JF0f0c09ec
/*  f0bf294:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf298:	920d1bfc */ 	lbu	$t5,0x1bfc($s0)
.JF0f0bf29c:
/*  f0bf29c:	24020003 */ 	li	$v0,0x3
/*  f0bf2a0:	544d0011 */ 	bnel	$v0,$t5,.JF0f0bf2e8
/*  f0bf2a4:	96180010 */ 	lhu	$t8,0x10($s0)
/*  f0bf2a8:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0bf2ac:	00000000 */ 	nop
/*  f0bf2b0:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0bf2b4:	3c01800a */ 	lui	$at,0x800a
/*  f0bf2b8:	00002025 */ 	move	$a0,$zero
/*  f0bf2bc:	972f1c00 */ 	lhu	$t7,0x1c00($t9)
/*  f0bf2c0:	00002825 */ 	move	$a1,$zero
/*  f0bf2c4:	00003025 */ 	move	$a2,$zero
/*  f0bf2c8:	24070001 */ 	li	$a3,0x1
/*  f0bf2cc:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bf2d0:	a42fe4b8 */ 	sh	$t7,-0x1b48($at)
/*  f0bf2d4:	0fc2eb4f */ 	jal	0xf0bad3c
/*  f0bf2d8:	00000000 */ 	nop
/*  f0bf2dc:	100005c3 */ 	b	.JF0f0c09ec
/*  f0bf2e0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf2e4:	96180010 */ 	lhu	$t8,0x10($s0)
.JF0f0bf2e8:
/*  f0bf2e8:	24010002 */ 	li	$at,0x2
/*  f0bf2ec:	27aa02fc */ 	addiu	$t2,$sp,0x2fc
/*  f0bf2f0:	17010241 */ 	bne	$t8,$at,.JF0f0bfbf8
/*  f0bf2f4:	3c098007 */ 	lui	$t1,0x8007
/*  f0bf2f8:	25290f20 */ 	addiu	$t1,$t1,0xf20
/*  f0bf2fc:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0bf300:	8d2c0004 */ 	lw	$t4,0x4($t1)
/*  f0bf304:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0bf308:	ad410000 */ 	sw	$at,0x0($t2)
/*  f0bf30c:	8d210008 */ 	lw	$at,0x8($t1)
/*  f0bf310:	25ad0f2c */ 	addiu	$t5,$t5,0xf2c
/*  f0bf314:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f0bf318:	ad410008 */ 	sw	$at,0x8($t2)
/*  f0bf31c:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0bf320:	27ae02f0 */ 	addiu	$t6,$sp,0x2f0
/*  f0bf324:	8daf0004 */ 	lw	$t7,0x4($t5)
/*  f0bf328:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0bf32c:	8da10008 */ 	lw	$at,0x8($t5)
/*  f0bf330:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0bf334:	256b0f38 */ 	addiu	$t3,$t3,0xf38
/*  f0bf338:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0bf33c:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0bf340:	8d610000 */ 	lw	$at,0x0($t3)
/*  f0bf344:	27b802e4 */ 	addiu	$t8,$sp,0x2e4
/*  f0bf348:	8d690004 */ 	lw	$t1,0x4($t3)
/*  f0bf34c:	af010000 */ 	sw	$at,0x0($t8)
/*  f0bf350:	8d610008 */ 	lw	$at,0x8($t3)
/*  f0bf354:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0bf358:	24040001 */ 	li	$a0,0x1
/*  f0bf35c:	af010008 */ 	sw	$at,0x8($t8)
/*  f0bf360:	afa002e0 */ 	sw	$zero,0x2e0($sp)
/*  f0bf364:	0fc30a3a */ 	jal	0xf0c28e8
/*  f0bf368:	8e110264 */ 	lw	$s1,0x264($s0)
/*  f0bf36c:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0bf370:	00000000 */ 	nop
/*  f0bf374:	00002025 */ 	move	$a0,$zero
/*  f0bf378:	00002825 */ 	move	$a1,$zero
/*  f0bf37c:	00003025 */ 	move	$a2,$zero
/*  f0bf380:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bf384:	24070001 */ 	li	$a3,0x1
/*  f0bf388:	0fc2f918 */ 	jal	0xf0be460
/*  f0bf38c:	00000000 */ 	nop
/*  f0bf390:	522001fc */ 	beqzl	$s1,.JF0f0bfb84
/*  f0bf394:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0bf398:	8e2c0014 */ 	lw	$t4,0x14($s1)
/*  f0bf39c:	518001f9 */ 	beqzl	$t4,.JF0f0bfb84
/*  f0bf3a0:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0bf3a4:	c622001c */ 	lwc1	$f2,0x1c($s1)
/*  f0bf3a8:	c62e0028 */ 	lwc1	$f14,0x28($s1)
/*  f0bf3ac:	c6200034 */ 	lwc1	$f0,0x34($s1)
/*  f0bf3b0:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0bf3b4:	00000000 */ 	nop
/*  f0bf3b8:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0bf3bc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0bf3c0:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0bf3c4:	0c012838 */ 	jal	0x4a0e0
/*  f0bf3c8:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0bf3cc:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f0bf3d0:	c624001c */ 	lwc1	$f4,0x1c($s1)
/*  f0bf3d4:	27af024e */ 	addiu	$t7,$sp,0x24e
/*  f0bf3d8:	00008025 */ 	move	$s0,$zero
/*  f0bf3dc:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0bf3e0:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bf3e4:	27a5027c */ 	addiu	$a1,$sp,0x27c
/*  f0bf3e8:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f0bf3ec:	24070014 */ 	li	$a3,0x14
/*  f0bf3f0:	e7a602b8 */ 	swc1	$f6,0x2b8($sp)
/*  f0bf3f4:	c6280020 */ 	lwc1	$f8,0x20($s1)
/*  f0bf3f8:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0bf3fc:	e7b202bc */ 	swc1	$f18,0x2bc($sp)
/*  f0bf400:	c62a0024 */ 	lwc1	$f10,0x24($s1)
/*  f0bf404:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0bf408:	e7a402c0 */ 	swc1	$f4,0x2c0($sp)
/*  f0bf40c:	c6260028 */ 	lwc1	$f6,0x28($s1)
/*  f0bf410:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0bf414:	e7a802c4 */ 	swc1	$f8,0x2c4($sp)
/*  f0bf418:	c632002c */ 	lwc1	$f18,0x2c($s1)
/*  f0bf41c:	46009283 */ 	div.s	$f10,$f18,$f0
/*  f0bf420:	e7aa02c8 */ 	swc1	$f10,0x2c8($sp)
/*  f0bf424:	c6240030 */ 	lwc1	$f4,0x30($s1)
/*  f0bf428:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0bf42c:	e7a602cc */ 	swc1	$f6,0x2cc($sp)
/*  f0bf430:	c6280034 */ 	lwc1	$f8,0x34($s1)
/*  f0bf434:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0bf438:	e7b202d0 */ 	swc1	$f18,0x2d0($sp)
/*  f0bf43c:	c62a0038 */ 	lwc1	$f10,0x38($s1)
/*  f0bf440:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0bf444:	e7a402d4 */ 	swc1	$f4,0x2d4($sp)
/*  f0bf448:	c626003c */ 	lwc1	$f6,0x3c($s1)
/*  f0bf44c:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0bf450:	e7a802d8 */ 	swc1	$f8,0x2d8($sp)
/*  f0bf454:	8e390014 */ 	lw	$t9,0x14($s1)
/*  f0bf458:	c7320008 */ 	lwc1	$f18,0x8($t9)
/*  f0bf45c:	e7b202fc */ 	swc1	$f18,0x2fc($sp)
/*  f0bf460:	8e2e0014 */ 	lw	$t6,0x14($s1)
/*  f0bf464:	c5ca000c */ 	lwc1	$f10,0xc($t6)
/*  f0bf468:	e7aa0300 */ 	swc1	$f10,0x300($sp)
/*  f0bf46c:	8e2d0014 */ 	lw	$t5,0x14($s1)
/*  f0bf470:	c5a40010 */ 	lwc1	$f4,0x10($t5)
/*  f0bf474:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0bf478:	0fc58969 */ 	jal	0xf1625a4
/*  f0bf47c:	e7a40304 */ 	swc1	$f4,0x304($sp)
/*  f0bf480:	87aa027c */ 	lh	$t2,0x27c($sp)
/*  f0bf484:	2401ffff */ 	li	$at,-1
/*  f0bf488:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0bf48c:	15410002 */ 	bne	$t2,$at,.JF0f0bf498
/*  f0bf490:	00000000 */ 	nop
/*  f0bf494:	24100001 */ 	li	$s0,0x1
.JF0f0bf498:
/*  f0bf498:	5200000f */ 	beqzl	$s0,.JF0f0bf4d8
/*  f0bf49c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf4a0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf4a4:	8e6b0038 */ 	lw	$t3,0x38($s3)
/*  f0bf4a8:	24190003 */ 	li	$t9,0x3
/*  f0bf4ac:	8e1800c8 */ 	lw	$t8,0xc8($s0)
/*  f0bf4b0:	030b4821 */ 	addu	$t1,$t8,$t3
/*  f0bf4b4:	ae0900c8 */ 	sw	$t1,0xc8($s0)
/*  f0bf4b8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf4bc:	8e0c00c8 */ 	lw	$t4,0xc8($s0)
/*  f0bf4c0:	29810079 */ 	slti	$at,$t4,0x79
/*  f0bf4c4:	1420000f */ 	bnez	$at,.JF0f0bf504
/*  f0bf4c8:	00000000 */ 	nop
/*  f0bf4cc:	1000000d */ 	b	.JF0f0bf504
/*  f0bf4d0:	a6190010 */ 	sh	$t9,0x10($s0)
/*  f0bf4d4:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0bf4d8:
/*  f0bf4d8:	8e0200c8 */ 	lw	$v0,0xc8($s0)
/*  f0bf4dc:	18400009 */ 	blez	$v0,.JF0f0bf504
/*  f0bf4e0:	00000000 */ 	nop
/*  f0bf4e4:	8e6e0038 */ 	lw	$t6,0x38($s3)
/*  f0bf4e8:	004e6823 */ 	subu	$t5,$v0,$t6
/*  f0bf4ec:	ae0d00c8 */ 	sw	$t5,0xc8($s0)
/*  f0bf4f0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bf4f4:	8e0f00c8 */ 	lw	$t7,0xc8($s0)
/*  f0bf4f8:	05e10002 */ 	bgez	$t7,.JF0f0bf504
/*  f0bf4fc:	00000000 */ 	nop
/*  f0bf500:	ae0000c8 */ 	sw	$zero,0xc8($s0)
.JF0f0bf504:
/*  f0bf504:	0c00586a */ 	jal	0x161a8
/*  f0bf508:	27a502f0 */ 	addiu	$a1,$sp,0x2f0
/*  f0bf50c:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0bf510:	0c00586a */ 	jal	0x161a8
/*  f0bf514:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bf518:	8e2a0040 */ 	lw	$t2,0x40($s1)
/*  f0bf51c:	31580080 */ 	andi	$t8,$t2,0x80
/*  f0bf520:	53000198 */ 	beqzl	$t8,.JF0f0bfb84
/*  f0bf524:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0bf528:	8e6b0288 */ 	lw	$t3,0x288($s3)
/*  f0bf52c:	8e340048 */ 	lw	$s4,0x48($s1)
/*  f0bf530:	0fc5474c */ 	jal	0xf151d30
/*  f0bf534:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0bf538:	8e690288 */ 	lw	$t1,0x288($s3)
/*  f0bf53c:	00408025 */ 	move	$s0,$v0
/*  f0bf540:	0fc5475a */ 	jal	0xf151d68
/*  f0bf544:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0bf548:	8e790288 */ 	lw	$t9,0x288($s3)
/*  f0bf54c:	00029600 */ 	sll	$s2,$v0,0x18
/*  f0bf550:	00126603 */ 	sra	$t4,$s2,0x18
/*  f0bf554:	01809025 */ 	move	$s2,$t4
/*  f0bf558:	0fc54761 */ 	jal	0xf151d84
/*  f0bf55c:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f0bf560:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0bf564:	00157603 */ 	sra	$t6,$s5,0x18
/*  f0bf568:	24010006 */ 	li	$at,0x6
/*  f0bf56c:	01c0a825 */ 	move	$s5,$t6
/*  f0bf570:	a3a0023d */ 	sb	$zero,0x23d($sp)
/*  f0bf574:	a3a0023c */ 	sb	$zero,0x23c($sp)
/*  f0bf578:	afa00118 */ 	sw	$zero,0x118($sp)
/*  f0bf57c:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0bf580:	12010008 */ 	beq	$s0,$at,.JF0f0bf5a4
/*  f0bf584:	afa00110 */ 	sw	$zero,0x110($sp)
/*  f0bf588:	24010007 */ 	li	$at,0x7
/*  f0bf58c:	12010005 */ 	beq	$s0,$at,.JF0f0bf5a4
/*  f0bf590:	24010005 */ 	li	$at,0x5
/*  f0bf594:	12010003 */ 	beq	$s0,$at,.JF0f0bf5a4
/*  f0bf598:	24010004 */ 	li	$at,0x4
/*  f0bf59c:	56010062 */ 	bnel	$s0,$at,.JF0f0bf728
/*  f0bf5a0:	8e78028c */ 	lw	$t8,0x28c($s3)
.JF0f0bf5a4:
/*  f0bf5a4:	8e6d028c */ 	lw	$t5,0x28c($s3)
/*  f0bf5a8:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0bf5ac:	24010004 */ 	li	$at,0x4
/*  f0bf5b0:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f0bf5b4:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f0bf5b8:	8d4a0ca0 */ 	lw	$t2,0xca0($t2)
/*  f0bf5bc:	240e0001 */ 	li	$t6,0x1
/*  f0bf5c0:	51400049 */ 	beqzl	$t2,.JF0f0bf6e8
/*  f0bf5c4:	afae0114 */ 	sw	$t6,0x114($sp)
/*  f0bf5c8:	12010004 */ 	beq	$s0,$at,.JF0f0bf5dc
/*  f0bf5cc:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf5d0:	24010005 */ 	li	$at,0x5
/*  f0bf5d4:	1601001d */ 	bne	$s0,$at,.JF0f0bf64c
/*  f0bf5d8:	3405c000 */ 	li	$a1,0xc000
.JF0f0bf5dc:
/*  f0bf5dc:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0bf5e0:	03002025 */ 	move	$a0,$t8
/*  f0bf5e4:	0c0053be */ 	jal	0x14ef8
/*  f0bf5e8:	3405c000 */ 	li	$a1,0xc000
/*  f0bf5ec:	1440000c */ 	bnez	$v0,.JF0f0bf620
/*  f0bf5f0:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bf5f4:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0bf5f8:	01602025 */ 	move	$a0,$t3
/*  f0bf5fc:	0c0053be */ 	jal	0x14ef8
/*  f0bf600:	3405c000 */ 	li	$a1,0xc000
/*  f0bf604:	14400006 */ 	bnez	$v0,.JF0f0bf620
/*  f0bf608:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bf60c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0bf610:	01202025 */ 	move	$a0,$t1
/*  f0bf614:	0c0053be */ 	jal	0x14ef8
/*  f0bf618:	24052000 */ 	li	$a1,0x2000
/*  f0bf61c:	10400002 */ 	beqz	$v0,.JF0f0bf628
.JF0f0bf620:
/*  f0bf620:	240c0001 */ 	li	$t4,0x1
/*  f0bf624:	afac0114 */ 	sw	$t4,0x114($sp)
.JF0f0bf628:
/*  f0bf628:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf62c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0bf630:	03202025 */ 	move	$a0,$t9
/*  f0bf634:	0c0053ee */ 	jal	0x14fb8
/*  f0bf638:	24052000 */ 	li	$a1,0x2000
/*  f0bf63c:	1040001e */ 	beqz	$v0,.JF0f0bf6b8
/*  f0bf640:	240e0001 */ 	li	$t6,0x1
/*  f0bf644:	1000001c */ 	b	.JF0f0bf6b8
/*  f0bf648:	afae0118 */ 	sw	$t6,0x118($sp)
.JF0f0bf64c:
/*  f0bf64c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf650:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0bf654:	0c0053be */ 	jal	0x14ef8
/*  f0bf658:	01a02025 */ 	move	$a0,$t5
/*  f0bf65c:	1440000c */ 	bnez	$v0,.JF0f0bf690
/*  f0bf660:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bf664:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bf668:	01e02025 */ 	move	$a0,$t7
/*  f0bf66c:	0c0053be */ 	jal	0x14ef8
/*  f0bf670:	3405c000 */ 	li	$a1,0xc000
/*  f0bf674:	14400006 */ 	bnez	$v0,.JF0f0bf690
/*  f0bf678:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf67c:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0bf680:	01402025 */ 	move	$a0,$t2
/*  f0bf684:	0c0053be */ 	jal	0x14ef8
/*  f0bf688:	24052000 */ 	li	$a1,0x2000
/*  f0bf68c:	10400002 */ 	beqz	$v0,.JF0f0bf698
.JF0f0bf690:
/*  f0bf690:	24180001 */ 	li	$t8,0x1
/*  f0bf694:	afb80114 */ 	sw	$t8,0x114($sp)
.JF0f0bf698:
/*  f0bf698:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bf69c:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0bf6a0:	01602025 */ 	move	$a0,$t3
/*  f0bf6a4:	0c0053ee */ 	jal	0x14fb8
/*  f0bf6a8:	24052000 */ 	li	$a1,0x2000
/*  f0bf6ac:	10400002 */ 	beqz	$v0,.JF0f0bf6b8
/*  f0bf6b0:	24090001 */ 	li	$t1,0x1
/*  f0bf6b4:	afa90118 */ 	sw	$t1,0x118($sp)
.JF0f0bf6b8:
/*  f0bf6b8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf6bc:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0bf6c0:	0c00536a */ 	jal	0x14da8
/*  f0bf6c4:	01802025 */ 	move	$a0,$t4
/*  f0bf6c8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf6cc:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0bf6d0:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0bf6d4:	0c005394 */ 	jal	0x14e50
/*  f0bf6d8:	03202025 */ 	move	$a0,$t9
/*  f0bf6dc:	10000002 */ 	b	.JF0f0bf6e8
/*  f0bf6e0:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0bf6e4:	afae0114 */ 	sw	$t6,0x114($sp)
.JF0f0bf6e8:
/*  f0bf6e8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf6ec:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0bf6f0:	01a02025 */ 	move	$a0,$t5
/*  f0bf6f4:	0c0053be */ 	jal	0x14ef8
/*  f0bf6f8:	24051000 */ 	li	$a1,0x1000
/*  f0bf6fc:	14400006 */ 	bnez	$v0,.JF0f0bf718
/*  f0bf700:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bf704:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bf708:	01e02025 */ 	move	$a0,$t7
/*  f0bf70c:	0c0053be */ 	jal	0x14ef8
/*  f0bf710:	24051000 */ 	li	$a1,0x1000
/*  f0bf714:	10400044 */ 	beqz	$v0,.JF0f0bf828
.JF0f0bf718:
/*  f0bf718:	240a0001 */ 	li	$t2,0x1
/*  f0bf71c:	10000042 */ 	b	.JF0f0bf828
/*  f0bf720:	afaa0110 */ 	sw	$t2,0x110($sp)
/*  f0bf724:	8e78028c */ 	lw	$t8,0x28c($s3)
.JF0f0bf728:
/*  f0bf728:	3c098007 */ 	lui	$t1,0x8007
/*  f0bf72c:	24010002 */ 	li	$at,0x2
/*  f0bf730:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0bf734:	012b4821 */ 	addu	$t1,$t1,$t3
/*  f0bf738:	8d290ca0 */ 	lw	$t1,0xca0($t1)
/*  f0bf73c:	24190001 */ 	li	$t9,0x1
/*  f0bf740:	51200031 */ 	beqzl	$t1,.JF0f0bf808
/*  f0bf744:	afb90114 */ 	sw	$t9,0x114($sp)
/*  f0bf748:	12010004 */ 	beq	$s0,$at,.JF0f0bf75c
/*  f0bf74c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf750:	24010003 */ 	li	$at,0x3
/*  f0bf754:	16010011 */ 	bne	$s0,$at,.JF0f0bf79c
/*  f0bf758:	24052000 */ 	li	$a1,0x2000
.JF0f0bf75c:
/*  f0bf75c:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0bf760:	01802025 */ 	move	$a0,$t4
/*  f0bf764:	0c0053ee */ 	jal	0x14fb8
/*  f0bf768:	34058000 */ 	li	$a1,0x8000
/*  f0bf76c:	10400003 */ 	beqz	$v0,.JF0f0bf77c
/*  f0bf770:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf774:	24190001 */ 	li	$t9,0x1
/*  f0bf778:	afb90118 */ 	sw	$t9,0x118($sp)
.JF0f0bf77c:
/*  f0bf77c:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0bf780:	01c02025 */ 	move	$a0,$t6
/*  f0bf784:	0c0053be */ 	jal	0x14ef8
/*  f0bf788:	24056030 */ 	li	$a1,0x6030
/*  f0bf78c:	10400012 */ 	beqz	$v0,.JF0f0bf7d8
/*  f0bf790:	240d0001 */ 	li	$t5,0x1
/*  f0bf794:	10000010 */ 	b	.JF0f0bf7d8
/*  f0bf798:	afad0114 */ 	sw	$t5,0x114($sp)
.JF0f0bf79c:
/*  f0bf79c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf7a0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bf7a4:	0c0053ee */ 	jal	0x14fb8
/*  f0bf7a8:	01e02025 */ 	move	$a0,$t7
/*  f0bf7ac:	10400003 */ 	beqz	$v0,.JF0f0bf7bc
/*  f0bf7b0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf7b4:	240a0001 */ 	li	$t2,0x1
/*  f0bf7b8:	afaa0118 */ 	sw	$t2,0x118($sp)
.JF0f0bf7bc:
/*  f0bf7bc:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0bf7c0:	03002025 */ 	move	$a0,$t8
/*  f0bf7c4:	0c0053be */ 	jal	0x14ef8
/*  f0bf7c8:	3405c030 */ 	li	$a1,0xc030
/*  f0bf7cc:	10400002 */ 	beqz	$v0,.JF0f0bf7d8
/*  f0bf7d0:	240b0001 */ 	li	$t3,0x1
/*  f0bf7d4:	afab0114 */ 	sw	$t3,0x114($sp)
.JF0f0bf7d8:
/*  f0bf7d8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf7dc:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0bf7e0:	0c00536a */ 	jal	0x14da8
/*  f0bf7e4:	01202025 */ 	move	$a0,$t1
/*  f0bf7e8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf7ec:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0bf7f0:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0bf7f4:	0c005394 */ 	jal	0x14e50
/*  f0bf7f8:	01802025 */ 	move	$a0,$t4
/*  f0bf7fc:	10000002 */ 	b	.JF0f0bf808
/*  f0bf800:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0bf804:	afb90114 */ 	sw	$t9,0x114($sp)
.JF0f0bf808:
/*  f0bf808:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bf80c:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0bf810:	01c02025 */ 	move	$a0,$t6
/*  f0bf814:	0c0053be */ 	jal	0x14ef8
/*  f0bf818:	24051000 */ 	li	$a1,0x1000
/*  f0bf81c:	10400002 */ 	beqz	$v0,.JF0f0bf828
/*  f0bf820:	240d0001 */ 	li	$t5,0x1
/*  f0bf824:	afad0110 */ 	sw	$t5,0x110($sp)
.JF0f0bf828:
/*  f0bf828:	8faf0110 */ 	lw	$t7,0x110($sp)
/*  f0bf82c:	51e0000b */ 	beqzl	$t7,.JF0f0bf85c
/*  f0bf830:	83ab023c */ 	lb	$t3,0x23c($sp)
/*  f0bf834:	8e6a0314 */ 	lw	$t2,0x314($s3)
/*  f0bf838:	15400005 */ 	bnez	$t2,.JF0f0bf850
/*  f0bf83c:	00000000 */ 	nop
/*  f0bf840:	0fc2efe3 */ 	jal	0xf0bbf8c
/*  f0bf844:	24040002 */ 	li	$a0,0x2
/*  f0bf848:	10000004 */ 	b	.JF0f0bf85c
/*  f0bf84c:	83ab023c */ 	lb	$t3,0x23c($sp)
.JF0f0bf850:
/*  f0bf850:	0fc5e4e5 */ 	jal	0xf179394
/*  f0bf854:	00000000 */ 	nop
/*  f0bf858:	83ab023c */ 	lb	$t3,0x23c($sp)
.JF0f0bf85c:
/*  f0bf85c:	c660004c */ 	lwc1	$f0,0x4c($s3)
/*  f0bf860:	83a9023d */ 	lb	$t1,0x23d($sp)
/*  f0bf864:	448b3000 */ 	mtc1	$t3,$f6
/*  f0bf868:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bf86c:	00096023 */ 	negu	$t4,$t1
/*  f0bf870:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0bf874:	448c5000 */ 	mtc1	$t4,$f10
/*  f0bf878:	c430e3b4 */ 	lwc1	$f16,-0x1c4c($at)
/*  f0bf87c:	c7ae02c0 */ 	lwc1	$f14,0x2c0($sp)
/*  f0bf880:	c7a202b8 */ 	lwc1	$f2,0x2b8($sp)
/*  f0bf884:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0bf888:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0bf88c:	24180001 */ 	li	$t8,0x1
/*  f0bf890:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f0bf894:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0bf898:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0bf89c:	46109582 */ 	mul.s	$f22,$f18,$f16
/*  f0bf8a0:	00000000 */ 	nop
/*  f0bf8a4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bf8a8:	00000000 */ 	nop
/*  f0bf8ac:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0bf8b0:	00000000 */ 	nop
/*  f0bf8b4:	460e7482 */ 	mul.s	$f18,$f14,$f14
/*  f0bf8b8:	00000000 */ 	nop
/*  f0bf8bc:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0bf8c0:	e7a80174 */ 	swc1	$f8,0x174($sp)
/*  f0bf8c4:	0c012838 */ 	jal	0x4a0e0
/*  f0bf8c8:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0bf8cc:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0bf8d0:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0bf8d4:	4600b306 */ 	mov.s	$f12,$f22
/*  f0bf8d8:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0bf8dc:	46007383 */ 	div.s	$f14,$f14,$f0
/*  f0bf8e0:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0bf8e4:	0c0068df */ 	jal	0x1a37c
/*  f0bf8e8:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0bf8ec:	46000506 */ 	mov.s	$f20,$f0
/*  f0bf8f0:	0c0068dc */ 	jal	0x1a370
/*  f0bf8f4:	4600b306 */ 	mov.s	$f12,$f22
/*  f0bf8f8:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0bf8fc:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0bf900:	44803000 */ 	mtc1	$zero,$f6
/*  f0bf904:	46141102 */ 	mul.s	$f4,$f2,$f20
/*  f0bf908:	e7a0014c */ 	swc1	$f0,0x14c($sp)
/*  f0bf90c:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0bf910:	46147202 */ 	mul.s	$f8,$f14,$f20
/*  f0bf914:	e7a60154 */ 	swc1	$f6,0x154($sp)
/*  f0bf918:	e7a40150 */ 	swc1	$f4,0x150($sp)
/*  f0bf91c:	0c0068df */ 	jal	0x1a37c
/*  f0bf920:	e7a80158 */ 	swc1	$f8,0x158($sp)
/*  f0bf924:	46000506 */ 	mov.s	$f20,$f0
/*  f0bf928:	0c0068dc */ 	jal	0x1a370
/*  f0bf92c:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0bf930:	44801000 */ 	mtc1	$zero,$f2
/*  f0bf934:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0bf938:	27b5013c */ 	addiu	$s5,$sp,0x13c
/*  f0bf93c:	e7a0015c */ 	swc1	$f0,0x15c($sp)
/*  f0bf940:	4612103e */ 	c.le.s	$f2,$f18
/*  f0bf944:	02a03025 */ 	move	$a2,$s5
/*  f0bf948:	27a4015c */ 	addiu	$a0,$sp,0x15c
/*  f0bf94c:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f0bf950:	45000003 */ 	bc1f	.JF0f0bf960
/*  f0bf954:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f0bf958:	10000003 */ 	b	.JF0f0bf968
/*  f0bf95c:	e7b40164 */ 	swc1	$f20,0x164($sp)
.JF0f0bf960:
/*  f0bf960:	4600a287 */ 	neg.s	$f10,$f20
/*  f0bf964:	e7aa0164 */ 	swc1	$f10,0x164($sp)
.JF0f0bf968:
/*  f0bf968:	0fc26136 */ 	jal	0xf0984d8
/*  f0bf96c:	e7a20168 */ 	swc1	$f2,0x168($sp)
/*  f0bf970:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f0bf974:	02002825 */ 	move	$a1,$s0
/*  f0bf978:	0fc25f1d */ 	jal	0xf097c74
/*  f0bf97c:	02a02025 */ 	move	$a0,$s5
/*  f0bf980:	02002025 */ 	move	$a0,$s0
/*  f0bf984:	0c0056ac */ 	jal	0x15ab0
/*  f0bf988:	26850004 */ 	addiu	$a1,$s4,0x4
/*  f0bf98c:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f0bf990:	44808000 */ 	mtc1	$zero,$f16
/*  f0bf994:	2419ffff */ 	li	$t9,-1
/*  f0bf998:	35cd4000 */ 	ori	$t5,$t6,0x4000
/*  f0bf99c:	31aa0080 */ 	andi	$t2,$t5,0x80
/*  f0bf9a0:	a69900b2 */ 	sh	$t9,0xb2($s4)
/*  f0bf9a4:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*  f0bf9a8:	e6900018 */ 	swc1	$f16,0x18($s4)
/*  f0bf9ac:	e6900014 */ 	swc1	$f16,0x14($s4)
/*  f0bf9b0:	15400002 */ 	bnez	$t2,.JF0f0bf9bc
/*  f0bf9b4:	e6900010 */ 	swc1	$f16,0x10($s4)
/*  f0bf9b8:	ae800088 */ 	sw	$zero,0x88($s4)
.JF0f0bf9bc:
/*  f0bf9bc:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0bf9c0:	53000003 */ 	beqzl	$t8,.JF0f0bf9d0
/*  f0bf9c4:	c6820004 */ 	lwc1	$f2,0x4($s4)
/*  f0bf9c8:	a6200062 */ 	sh	$zero,0x62($s1)
/*  f0bf9cc:	c6820004 */ 	lwc1	$f2,0x4($s4)
.JF0f0bf9d0:
/*  f0bf9d0:	c68e0008 */ 	lwc1	$f14,0x8($s4)
/*  f0bf9d4:	c680000c */ 	lwc1	$f0,0xc($s4)
/*  f0bf9d8:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0bf9dc:	00000000 */ 	nop
/*  f0bf9e0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0bf9e4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0bf9e8:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0bf9ec:	0c012838 */ 	jal	0x4a0e0
/*  f0bf9f0:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f0bf9f4:	8fab0114 */ 	lw	$t3,0x114($sp)
/*  f0bf9f8:	46000386 */ 	mov.s	$f14,$f0
/*  f0bf9fc:	3c014140 */ 	lui	$at,0x4140
/*  f0bfa00:	51600006 */ 	beqzl	$t3,.JF0f0bfa1c
/*  f0bfa04:	44816000 */ 	mtc1	$at,$f12
/*  f0bfa08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfa0c:	44816000 */ 	mtc1	$at,$f12
/*  f0bfa10:	10000004 */ 	b	.JF0f0bfa24
/*  f0bfa14:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0bfa18:	44816000 */ 	mtc1	$at,$f12
.JF0f0bfa1c:
/*  f0bfa1c:	00000000 */ 	nop
/*  f0bfa20:	460c003c */ 	c.lt.s	$f0,$f12
.JF0f0bfa24:
/*  f0bfa24:	46000086 */ 	mov.s	$f2,$f0
/*  f0bfa28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfa2c:	4502000c */ 	bc1fl	.JF0f0bfa60
/*  f0bfa30:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0bfa34:	c42ae3b8 */ 	lwc1	$f10,-0x1c48($at)
/*  f0bfa38:	c664004c */ 	lwc1	$f4,0x4c($s3)
/*  f0bfa3c:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0bfa40:	46003080 */ 	add.s	$f2,$f6,$f0
/*  f0bfa44:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0bfa48:	00000000 */ 	nop
/*  f0bfa4c:	45020011 */ 	bc1fl	.JF0f0bfa94
/*  f0bfa50:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bfa54:	1000000e */ 	b	.JF0f0bfa90
/*  f0bfa58:	46006086 */ 	mov.s	$f2,$f12
/*  f0bfa5c:	4600603c */ 	c.lt.s	$f12,$f0
.JF0f0bfa60:
/*  f0bfa60:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfa64:	4502000b */ 	bc1fl	.JF0f0bfa94
/*  f0bfa68:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bfa6c:	c432e3bc */ 	lwc1	$f18,-0x1c44($at)
/*  f0bfa70:	c668004c */ 	lwc1	$f8,0x4c($s3)
/*  f0bfa74:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0bfa78:	460a0081 */ 	sub.s	$f2,$f0,$f10
/*  f0bfa7c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0bfa80:	00000000 */ 	nop
/*  f0bfa84:	45020003 */ 	bc1fl	.JF0f0bfa94
/*  f0bfa88:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bfa8c:	46006086 */ 	mov.s	$f2,$f12
.JF0f0bfa90:
/*  f0bfa90:	c6840004 */ 	lwc1	$f4,0x4($s4)
.JF0f0bfa94:
/*  f0bfa94:	c6880008 */ 	lwc1	$f8,0x8($s4)
/*  f0bfa98:	27b001bc */ 	addiu	$s0,$sp,0x1bc
/*  f0bfa9c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0bfaa0:	02002825 */ 	move	$a1,$s0
/*  f0bfaa4:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0bfaa8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0bfaac:	460e3483 */ 	div.s	$f18,$f6,$f14
/*  f0bfab0:	c686000c */ 	lwc1	$f6,0xc($s4)
/*  f0bfab4:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f0bfab8:	e6920004 */ 	swc1	$f18,0x4($s4)
/*  f0bfabc:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f0bfac0:	460e9203 */ 	div.s	$f8,$f18,$f14
/*  f0bfac4:	e6840008 */ 	swc1	$f4,0x8($s4)
/*  f0bfac8:	0c00573d */ 	jal	0x15cf4
/*  f0bfacc:	e688000c */ 	swc1	$f8,0xc($s4)
/*  f0bfad0:	27b2012c */ 	addiu	$s2,$sp,0x12c
/*  f0bfad4:	02402825 */ 	move	$a1,$s2
/*  f0bfad8:	0fc25f79 */ 	jal	0xf097de4
/*  f0bfadc:	02002025 */ 	move	$a0,$s0
/*  f0bfae0:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f0bfae4:	02003025 */ 	move	$a2,$s0
/*  f0bfae8:	02a02025 */ 	move	$a0,$s5
/*  f0bfaec:	0fc26136 */ 	jal	0xf0984d8
/*  f0bfaf0:	02402825 */ 	move	$a1,$s2
/*  f0bfaf4:	27b2017c */ 	addiu	$s2,$sp,0x17c
/*  f0bfaf8:	02402825 */ 	move	$a1,$s2
/*  f0bfafc:	0fc25f1d */ 	jal	0xf097c74
/*  f0bfb00:	02002025 */ 	move	$a0,$s0
/*  f0bfb04:	02402025 */ 	move	$a0,$s2
/*  f0bfb08:	0c005750 */ 	jal	0x15d40
/*  f0bfb0c:	27a502b8 */ 	addiu	$a1,$sp,0x2b8
/*  f0bfb10:	c7a002a8 */ 	lwc1	$f0,0x2a8($sp)
/*  f0bfb14:	c7aa02b8 */ 	lwc1	$f10,0x2b8($sp)
/*  f0bfb18:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0bfb1c:	e624001c */ 	swc1	$f4,0x1c($s1)
/*  f0bfb20:	c7a602bc */ 	lwc1	$f6,0x2bc($sp)
/*  f0bfb24:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0bfb28:	e6320020 */ 	swc1	$f18,0x20($s1)
/*  f0bfb2c:	c7a802c0 */ 	lwc1	$f8,0x2c0($sp)
/*  f0bfb30:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bfb34:	e62a0024 */ 	swc1	$f10,0x24($s1)
/*  f0bfb38:	c7a402c4 */ 	lwc1	$f4,0x2c4($sp)
/*  f0bfb3c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bfb40:	e6260028 */ 	swc1	$f6,0x28($s1)
/*  f0bfb44:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0bfb48:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0bfb4c:	e628002c */ 	swc1	$f8,0x2c($s1)
/*  f0bfb50:	c7aa02cc */ 	lwc1	$f10,0x2cc($sp)
/*  f0bfb54:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0bfb58:	e6240030 */ 	swc1	$f4,0x30($s1)
/*  f0bfb5c:	c7a602d0 */ 	lwc1	$f6,0x2d0($sp)
/*  f0bfb60:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0bfb64:	e6320034 */ 	swc1	$f18,0x34($s1)
/*  f0bfb68:	c7a802d4 */ 	lwc1	$f8,0x2d4($sp)
/*  f0bfb6c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bfb70:	e62a0038 */ 	swc1	$f10,0x38($s1)
/*  f0bfb74:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
/*  f0bfb78:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bfb7c:	e626003c */ 	swc1	$f6,0x3c($s1)
/*  f0bfb80:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
.JF0f0bfb84:
/*  f0bfb84:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bfb88:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bfb8c:	15200006 */ 	bnez	$t1,.JF0f0bfba8
/*  f0bfb90:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0bfb94:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0bfb98:	24190003 */ 	li	$t9,0x3
/*  f0bfb9c:	ad800264 */ 	sw	$zero,0x264($t4)
/*  f0bfba0:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f0bfba4:	a5d90010 */ 	sh	$t9,0x10($t6)
.JF0f0bfba8:
/*  f0bfba8:	8e6f0284 */ 	lw	$t7,0x284($s3)
/*  f0bfbac:	240d0001 */ 	li	$t5,0x1
/*  f0bfbb0:	1220000c */ 	beqz	$s1,.JF0f0bfbe4
/*  f0bfbb4:	aded0274 */ 	sw	$t5,0x274($t7)
/*  f0bfbb8:	8e220014 */ 	lw	$v0,0x14($s1)
/*  f0bfbbc:	10400009 */ 	beqz	$v0,.JF0f0bfbe4
/*  f0bfbc0:	24470008 */ 	addiu	$a3,$v0,0x8
/*  f0bfbc4:	244a0028 */ 	addiu	$t2,$v0,0x28
/*  f0bfbc8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0bfbcc:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bfbd0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bfbd4:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0bfbd8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0bfbdc:	10000004 */ 	b	.JF0f0bfbf0
/*  f0bfbe0:	00000000 */ 	nop
.JF0f0bfbe4:
/*  f0bfbe4:	00003825 */ 	move	$a3,$zero
/*  f0bfbe8:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0bfbec:	afa00010 */ 	sw	$zero,0x10($sp)
.JF0f0bfbf0:
/*  f0bfbf0:	1000037e */ 	b	.JF0f0c09ec
/*  f0bfbf4:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0bfbf8:
/*  f0bfbf8:	24010001 */ 	li	$at,0x1
/*  f0bfbfc:	14610261 */ 	bne	$v1,$at,.JF0f0c0584
/*  f0bfc00:	00000000 */ 	nop
/*  f0bfc04:	0fc2e96e */ 	jal	0xf0ba5b8
/*  f0bfc08:	00000000 */ 	nop
/*  f0bfc0c:	8e78028c */ 	lw	$t8,0x28c($s3)
/*  f0bfc10:	3c098007 */ 	lui	$t1,0x8007
/*  f0bfc14:	00003825 */ 	move	$a3,$zero
/*  f0bfc18:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0bfc1c:	012b4821 */ 	addu	$t1,$t1,$t3
/*  f0bfc20:	8d290ca0 */ 	lw	$t1,0xca0($t1)
/*  f0bfc24:	00002025 */ 	move	$a0,$zero
/*  f0bfc28:	00002825 */ 	move	$a1,$zero
/*  f0bfc2c:	11200007 */ 	beqz	$t1,.JF0f0bfc4c
/*  f0bfc30:	00003025 */ 	move	$a2,$zero
/*  f0bfc34:	24040001 */ 	li	$a0,0x1
/*  f0bfc38:	24050001 */ 	li	$a1,0x1
/*  f0bfc3c:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bfc40:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0bfc44:	10000003 */ 	b	.JF0f0bfc54
/*  f0bfc48:	00000000 */ 	nop
.JF0f0bfc4c:
/*  f0bfc4c:	0fc33346 */ 	jal	0xf0ccd18
/*  f0bfc50:	24070001 */ 	li	$a3,0x1
.JF0f0bfc54:
/*  f0bfc54:	0fc2f918 */ 	jal	0xf0be460
/*  f0bfc58:	00000000 */ 	nop
/*  f0bfc5c:	0fc30a3a */ 	jal	0xf0c28e8
/*  f0bfc60:	00002025 */ 	move	$a0,$zero
/*  f0bfc64:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfc68:	44802000 */ 	mtc1	$zero,$f4
/*  f0bfc6c:	27a400f4 */ 	addiu	$a0,$sp,0xf4
/*  f0bfc70:	c612037c */ 	lwc1	$f18,0x37c($s0)
/*  f0bfc74:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0bfc78:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0bfc7c:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bfc80:	c6080380 */ 	lwc1	$f8,0x380($s0)
/*  f0bfc84:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0bfc88:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f0bfc8c:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0bfc90:	c60a0384 */ 	lwc1	$f10,0x384($s0)
/*  f0bfc94:	44804000 */ 	mtc1	$zero,$f8
/*  f0bfc98:	44803000 */ 	mtc1	$zero,$f6
/*  f0bfc9c:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f0bfca0:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f0bfca4:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bfca8:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f0bfcac:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0bfcb0:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0bfcb4:	e7a400f8 */ 	swc1	$f4,0xf8($sp)
/*  f0bfcb8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f0bfcbc:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bfcc0:	246c0028 */ 	addiu	$t4,$v1,0x28
/*  f0bfcc4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0bfcc8:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0bfccc:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bfcd0:	8e790318 */ 	lw	$t9,0x318($s3)
/*  f0bfcd4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0bfcd8:	17200228 */ 	bnez	$t9,.JF0f0c057c
/*  f0bfcdc:	00000000 */ 	nop
/*  f0bfce0:	81cde6eb */ 	lb	$t5,-0x1915($t6)
/*  f0bfce4:	05a10225 */ 	bgez	$t5,.JF0f0c057c
/*  f0bfce8:	00000000 */ 	nop
/*  f0bfcec:	8e620474 */ 	lw	$v0,0x474($s3)
/*  f0bfcf0:	18400222 */ 	blez	$v0,.JF0f0c057c
/*  f0bfcf4:	00000000 */ 	nop
/*  f0bfcf8:	8e6f0478 */ 	lw	$t7,0x478($s3)
/*  f0bfcfc:	15e0021f */ 	bnez	$t7,.JF0f0c057c
/*  f0bfd00:	00000000 */ 	nop
/*  f0bfd04:	8e6a04b4 */ 	lw	$t2,0x4b4($s3)
/*  f0bfd08:	24010026 */ 	li	$at,0x26
/*  f0bfd0c:	1141021b */ 	beq	$t2,$at,.JF0f0c057c
/*  f0bfd10:	00000000 */ 	nop
/*  f0bfd14:	8e78000c */ 	lw	$t8,0xc($s3)
/*  f0bfd18:	240b0001 */ 	li	$t3,0x1
/*  f0bfd1c:	2b010015 */ 	slti	$at,$t8,0x15
/*  f0bfd20:	14200216 */ 	bnez	$at,.JF0f0c057c
/*  f0bfd24:	00000000 */ 	nop
/*  f0bfd28:	ae6b0478 */ 	sw	$t3,0x478($s3)
/*  f0bfd2c:	18400213 */ 	blez	$v0,.JF0f0c057c
/*  f0bfd30:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f0bfd34:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0bfd38:	4481b000 */ 	mtc1	$at,$f22
/*  f0bfd3c:	3c09800a */ 	lui	$t1,0x800a
/*  f0bfd40:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f0bfd44:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfd48:	c434e3c0 */ 	lwc1	$f20,-0x1c40($at)
/*  f0bfd4c:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f0bfd50:	24140013 */ 	li	$s4,0x13
/*  f0bfd54:	24120064 */ 	li	$s2,0x64
.JF0f0bfd58:
/*  f0bfd58:	3c0c800a */ 	lui	$t4,0x800a
/*  f0bfd5c:	8d8c28d0 */ 	lw	$t4,0x28d0($t4)
/*  f0bfd60:	3c0103c0 */ 	lui	$at,0x3c0
/*  f0bfd64:	00008825 */ 	move	$s1,$zero
/*  f0bfd68:	0181c824 */ 	and	$t9,$t4,$at
/*  f0bfd6c:	17200078 */ 	bnez	$t9,.JF0f0bff50
/*  f0bfd70:	00000000 */ 	nop
/*  f0bfd74:	0fc59689 */ 	jal	0xf165a24
/*  f0bfd78:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bfd7c:	14540015 */ 	bne	$v0,$s4,.JF0f0bfdd4
/*  f0bfd80:	00000000 */ 	nop
/*  f0bfd84:	0c00611c */ 	jal	0x18470
/*  f0bfd88:	24040012 */ 	li	$a0,0x12
/*  f0bfd8c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfd90:	3c014000 */ 	lui	$at,0x4000
/*  f0bfd94:	44812000 */ 	mtc1	$at,$f4
/*  f0bfd98:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0bfd9c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bfda0:	240e0010 */ 	li	$t6,0x10
/*  f0bfda4:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0bfda8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0bfdac:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bfdb0:	24040056 */ 	li	$a0,0x56
/*  f0bfdb4:	2405003e */ 	li	$a1,0x3e
/*  f0bfdb8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bfdbc:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bfdc0:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bfdc4:	0fc130e6 */ 	jal	0xf04c398
/*  f0bfdc8:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bfdcc:	1000002a */ 	b	.JF0f0bfe78
/*  f0bfdd0:	00408825 */ 	move	$s1,$v0
.JF0f0bfdd4:
/*  f0bfdd4:	0fc59689 */ 	jal	0xf165a24
/*  f0bfdd8:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bfddc:	24010023 */ 	li	$at,0x23
/*  f0bfde0:	14410012 */ 	bne	$v0,$at,.JF0f0bfe2c
/*  f0bfde4:	00000000 */ 	nop
/*  f0bfde8:	0c00611c */ 	jal	0x18470
/*  f0bfdec:	24040012 */ 	li	$a0,0x12
/*  f0bfdf0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfdf4:	240d0010 */ 	li	$t5,0x10
/*  f0bfdf8:	2404005b */ 	li	$a0,0x5b
/*  f0bfdfc:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0bfe00:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bfe04:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0bfe08:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bfe0c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bfe10:	24050008 */ 	li	$a1,0x8
/*  f0bfe14:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bfe18:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bfe1c:	0fc130e6 */ 	jal	0xf04c398
/*  f0bfe20:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bfe24:	10000014 */ 	b	.JF0f0bfe78
/*  f0bfe28:	00408825 */ 	move	$s1,$v0
.JF0f0bfe2c:
/*  f0bfe2c:	0c00611c */ 	jal	0x18470
/*  f0bfe30:	24040012 */ 	li	$a0,0x12
/*  f0bfe34:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bfe38:	3c014000 */ 	lui	$at,0x4000
/*  f0bfe3c:	44813000 */ 	mtc1	$at,$f6
/*  f0bfe40:	c6040144 */ 	lwc1	$f4,0x144($s0)
/*  f0bfe44:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bfe48:	240f0010 */ 	li	$t7,0x10
/*  f0bfe4c:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0bfe50:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0bfe54:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bfe58:	24040056 */ 	li	$a0,0x56
/*  f0bfe5c:	2405003e */ 	li	$a1,0x3e
/*  f0bfe60:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bfe64:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bfe68:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0bfe6c:	0fc130e6 */ 	jal	0xf04c398
/*  f0bfe70:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bfe74:	00408825 */ 	move	$s1,$v0
.JF0f0bfe78:
/*  f0bfe78:	10400035 */ 	beqz	$v0,.JF0f0bff50
/*  f0bfe7c:	3c014030 */ 	lui	$at,0x4030
/*  f0bfe80:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bfe84:	240c0010 */ 	li	$t4,0x10
/*  f0bfe88:	240d0003 */ 	li	$t5,0x3
/*  f0bfe8c:	8e0b0118 */ 	lw	$t3,0x118($s0)
/*  f0bfe90:	8e0a0114 */ 	lw	$t2,0x114($s0)
/*  f0bfe94:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bfe98:	01614825 */ 	or	$t1,$t3,$at
/*  f0bfe9c:	3c018000 */ 	lui	$at,0x8000
/*  f0bfea0:	240f0032 */ 	li	$t7,0x32
/*  f0bfea4:	35582000 */ 	ori	$t8,$t2,0x2000
/*  f0bfea8:	03217025 */ 	or	$t6,$t9,$at
/*  f0bfeac:	ae180114 */ 	sw	$t8,0x114($s0)
/*  f0bfeb0:	ae090118 */ 	sw	$t1,0x118($s0)
/*  f0bfeb4:	a20c0125 */ 	sb	$t4,0x125($s0)
/*  f0bfeb8:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bfebc:	ae0e0014 */ 	sw	$t6,0x14($s0)
/*  f0bfec0:	a20d02b1 */ 	sb	$t5,0x2b1($s0)
/*  f0bfec4:	a20f02e2 */ 	sb	$t7,0x2e2($s0)
/*  f0bfec8:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bfecc:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bfed0:	0fc59689 */ 	jal	0xf165a24
/*  f0bfed4:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bfed8:	14540005 */ 	bne	$v0,$s4,.JF0f0bfef0
/*  f0bfedc:	02002025 */ 	move	$a0,$s0
/*  f0bfee0:	0fc085f3 */ 	jal	0xf0217cc
/*  f0bfee4:	3c054220 */ 	lui	$a1,0x4220
/*  f0bfee8:	10000005 */ 	b	.JF0f0bff00
/*  f0bfeec:	02002025 */ 	move	$a0,$s0
.JF0f0bfef0:
/*  f0bfef0:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bfef4:	0fc085f3 */ 	jal	0xf0217cc
/*  f0bfef8:	02002025 */ 	move	$a0,$s0
/*  f0bfefc:	02002025 */ 	move	$a0,$s0
.JF0f0bff00:
/*  f0bff00:	0fc085ee */ 	jal	0xf0217b8
/*  f0bff04:	3c054080 */ 	lui	$a1,0x4080
/*  f0bff08:	8e0a0018 */ 	lw	$t2,0x18($s0)
/*  f0bff0c:	921902e1 */ 	lbu	$t9,0x2e1($s0)
/*  f0bff10:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0bff14:	3c010004 */ 	lui	$at,0x4
/*  f0bff18:	0141c025 */ 	or	$t8,$t2,$at
/*  f0bff1c:	372d0001 */ 	ori	$t5,$t9,0x1
/*  f0bff20:	3c012000 */ 	lui	$at,0x2000
/*  f0bff24:	a20d02e1 */ 	sb	$t5,0x2e1($s0)
/*  f0bff28:	31af0001 */ 	andi	$t7,$t5,0x1
/*  f0bff2c:	01614825 */ 	or	$t1,$t3,$at
/*  f0bff30:	ae180018 */ 	sw	$t8,0x18($s0)
/*  f0bff34:	ae090014 */ 	sw	$t1,0x14($s0)
/*  f0bff38:	a20f02e1 */ 	sb	$t7,0x2e1($s0)
/*  f0bff3c:	02002025 */ 	move	$a0,$s0
/*  f0bff40:	240500f5 */ 	li	$a1,0xf5
/*  f0bff44:	24060002 */ 	li	$a2,0x2
/*  f0bff48:	0fc23215 */ 	jal	0xf08c854
/*  f0bff4c:	00003825 */ 	move	$a3,$zero
.JF0f0bff50:
/*  f0bff50:	0fc41bed */ 	jal	0xf106fb4
/*  f0bff54:	24040016 */ 	li	$a0,0x16
/*  f0bff58:	10400058 */ 	beqz	$v0,.JF0f0c00bc
/*  f0bff5c:	00000000 */ 	nop
/*  f0bff60:	0fc59689 */ 	jal	0xf165a24
/*  f0bff64:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bff68:	24010023 */ 	li	$at,0x23
/*  f0bff6c:	14410012 */ 	bne	$v0,$at,.JF0f0bffb8
/*  f0bff70:	00000000 */ 	nop
/*  f0bff74:	0c00611c */ 	jal	0x18470
/*  f0bff78:	24040012 */ 	li	$a0,0x12
/*  f0bff7c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bff80:	240a0010 */ 	li	$t2,0x10
/*  f0bff84:	2404005b */ 	li	$a0,0x5b
/*  f0bff88:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0bff8c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bff90:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0bff94:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0bff98:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bff9c:	24050008 */ 	li	$a1,0x8
/*  f0bffa0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bffa4:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bffa8:	0fc130e6 */ 	jal	0xf04c398
/*  f0bffac:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0bffb0:	10000011 */ 	b	.JF0f0bfff8
/*  f0bffb4:	00408825 */ 	move	$s1,$v0
.JF0f0bffb8:
/*  f0bffb8:	0c00611c */ 	jal	0x18470
/*  f0bffbc:	02802025 */ 	move	$a0,$s4
/*  f0bffc0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0bffc4:	24180010 */ 	li	$t8,0x10
/*  f0bffc8:	2404005a */ 	li	$a0,0x5a
/*  f0bffcc:	c6060144 */ 	lwc1	$f6,0x144($s0)
/*  f0bffd0:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0bffd4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0bffd8:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bffdc:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bffe0:	2405001b */ 	li	$a1,0x1b
/*  f0bffe4:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bffe8:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bffec:	0fc130e6 */ 	jal	0xf04c398
/*  f0bfff0:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bfff4:	00408825 */ 	move	$s1,$v0
.JF0f0bfff8:
/*  f0bfff8:	10400030 */ 	beqz	$v0,.JF0f0c00bc
/*  f0bfffc:	3c014030 */ 	lui	$at,0x4030
/*  f0c0000:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0c0004:	34210081 */ 	ori	$at,$at,0x81
/*  f0c0008:	240e0010 */ 	li	$t6,0x10
/*  f0c000c:	8e0c0118 */ 	lw	$t4,0x118($s0)
/*  f0c0010:	8e0b0114 */ 	lw	$t3,0x114($s0)
/*  f0c0014:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f0c0018:	0181c825 */ 	or	$t9,$t4,$at
/*  f0c001c:	3c018000 */ 	lui	$at,0x8000
/*  f0c0020:	240d0064 */ 	li	$t5,0x64
/*  f0c0024:	35692080 */ 	ori	$t1,$t3,0x2080
/*  f0c0028:	01e15025 */ 	or	$t2,$t7,$at
/*  f0c002c:	ae090114 */ 	sw	$t1,0x114($s0)
/*  f0c0030:	ae190118 */ 	sw	$t9,0x118($s0)
/*  f0c0034:	a20e0125 */ 	sb	$t6,0x125($s0)
/*  f0c0038:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0c003c:	a20d02e2 */ 	sb	$t5,0x2e2($s0)
/*  f0c0040:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0c0044:	a21502b1 */ 	sb	$s5,0x2b1($s0)
/*  f0c0048:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0c004c:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0c0050:	0fc59689 */ 	jal	0xf165a24
/*  f0c0054:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c0058:	14540005 */ 	bne	$v0,$s4,.JF0f0c0070
/*  f0c005c:	02002025 */ 	move	$a0,$s0
/*  f0c0060:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c0064:	3c054220 */ 	lui	$a1,0x4220
/*  f0c0068:	10000005 */ 	b	.JF0f0c0080
/*  f0c006c:	8e180018 */ 	lw	$t8,0x18($s0)
.JF0f0c0070:
/*  f0c0070:	4405b000 */ 	mfc1	$a1,$f22
/*  f0c0074:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c0078:	02002025 */ 	move	$a0,$s0
/*  f0c007c:	8e180018 */ 	lw	$t8,0x18($s0)
.JF0f0c0080:
/*  f0c0080:	920e02e1 */ 	lbu	$t6,0x2e1($s0)
/*  f0c0084:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f0c0088:	3c010004 */ 	lui	$at,0x4
/*  f0c008c:	03015825 */ 	or	$t3,$t8,$at
/*  f0c0090:	35cf0001 */ 	ori	$t7,$t6,0x1
/*  f0c0094:	3c012000 */ 	lui	$at,0x2000
/*  f0c0098:	a20f02e1 */ 	sb	$t7,0x2e1($s0)
/*  f0c009c:	31ea0001 */ 	andi	$t2,$t7,0x1
/*  f0c00a0:	4405b000 */ 	mfc1	$a1,$f22
/*  f0c00a4:	01216025 */ 	or	$t4,$t1,$at
/*  f0c00a8:	ae0b0018 */ 	sw	$t3,0x18($s0)
/*  f0c00ac:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*  f0c00b0:	a20a02e1 */ 	sb	$t2,0x2e1($s0)
/*  f0c00b4:	0fc085ee */ 	jal	0xf0217b8
/*  f0c00b8:	02002025 */ 	move	$a0,$s0
.JF0f0c00bc:
/*  f0c00bc:	0fc41bed */ 	jal	0xf106fb4
/*  f0c00c0:	24040018 */ 	li	$a0,0x18
/*  f0c00c4:	1040005e */ 	beqz	$v0,.JF0f0c0240
/*  f0c00c8:	00000000 */ 	nop
/*  f0c00cc:	0fc59689 */ 	jal	0xf165a24
/*  f0c00d0:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c00d4:	24010023 */ 	li	$at,0x23
/*  f0c00d8:	14410012 */ 	bne	$v0,$at,.JF0f0c0124
/*  f0c00dc:	00000000 */ 	nop
/*  f0c00e0:	0c00611c */ 	jal	0x18470
/*  f0c00e4:	24040012 */ 	li	$a0,0x12
/*  f0c00e8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c00ec:	24180010 */ 	li	$t8,0x10
/*  f0c00f0:	2404005b */ 	li	$a0,0x5b
/*  f0c00f4:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0c00f8:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c00fc:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0c0100:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0c0104:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c0108:	24050008 */ 	li	$a1,0x8
/*  f0c010c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c0110:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c0114:	0fc130e6 */ 	jal	0xf04c398
/*  f0c0118:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0c011c:	10000011 */ 	b	.JF0f0c0164
/*  f0c0120:	00408825 */ 	move	$s1,$v0
.JF0f0c0124:
/*  f0c0124:	0c00611c */ 	jal	0x18470
/*  f0c0128:	24040012 */ 	li	$a0,0x12
/*  f0c012c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0130:	240b0010 */ 	li	$t3,0x10
/*  f0c0134:	2404005b */ 	li	$a0,0x5b
/*  f0c0138:	c6040144 */ 	lwc1	$f4,0x144($s0)
/*  f0c013c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c0140:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0c0144:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0c0148:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c014c:	24050012 */ 	li	$a1,0x12
/*  f0c0150:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c0154:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c0158:	0fc130e6 */ 	jal	0xf04c398
/*  f0c015c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0c0160:	00408825 */ 	move	$s1,$v0
.JF0f0c0164:
/*  f0c0164:	10400036 */ 	beqz	$v0,.JF0f0c0240
/*  f0c0168:	3c018030 */ 	lui	$at,0x8030
/*  f0c016c:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0c0170:	240d0010 */ 	li	$t5,0x10
/*  f0c0174:	24180002 */ 	li	$t8,0x2
/*  f0c0178:	8e190118 */ 	lw	$t9,0x118($s0)
/*  f0c017c:	8e090114 */ 	lw	$t1,0x114($s0)
/*  f0c0180:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f0c0184:	03217025 */ 	or	$t6,$t9,$at
/*  f0c0188:	3c018000 */ 	lui	$at,0x8000
/*  f0c018c:	352c2000 */ 	ori	$t4,$t1,0x2000
/*  f0c0190:	240b0032 */ 	li	$t3,0x32
/*  f0c0194:	24090032 */ 	li	$t1,0x32
/*  f0c0198:	01e15025 */ 	or	$t2,$t7,$at
/*  f0c019c:	ae0c0114 */ 	sw	$t4,0x114($s0)
/*  f0c01a0:	ae0e0118 */ 	sw	$t6,0x118($s0)
/*  f0c01a4:	a20d0125 */ 	sb	$t5,0x125($s0)
/*  f0c01a8:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0c01ac:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0c01b0:	a21802b1 */ 	sb	$t8,0x2b1($s0)
/*  f0c01b4:	a20b02e2 */ 	sb	$t3,0x2e2($s0)
/*  f0c01b8:	a2090002 */ 	sb	$t1,0x2($s0)
/*  f0c01bc:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0c01c0:	0fc59689 */ 	jal	0xf165a24
/*  f0c01c4:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c01c8:	14540006 */ 	bne	$v0,$s4,.JF0f0c01e4
/*  f0c01cc:	02002025 */ 	move	$a0,$s0
/*  f0c01d0:	4405b000 */ 	mfc1	$a1,$f22
/*  f0c01d4:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c01d8:	02002025 */ 	move	$a0,$s0
/*  f0c01dc:	10000004 */ 	b	.JF0f0c01f0
/*  f0c01e0:	02002025 */ 	move	$a0,$s0
.JF0f0c01e4:
/*  f0c01e4:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c01e8:	3c054120 */ 	lui	$a1,0x4120
/*  f0c01ec:	02002025 */ 	move	$a0,$s0
.JF0f0c01f0:
/*  f0c01f0:	0fc085ee */ 	jal	0xf0217b8
/*  f0c01f4:	3c054120 */ 	lui	$a1,0x4120
/*  f0c01f8:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f0c01fc:	920a02e1 */ 	lbu	$t2,0x2e1($s0)
/*  f0c0200:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*  f0c0204:	3c010004 */ 	lui	$at,0x4
/*  f0c0208:	0181c825 */ 	or	$t9,$t4,$at
/*  f0c020c:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f0c0210:	3c012000 */ 	lui	$at,0x2000
/*  f0c0214:	a20b02e1 */ 	sb	$t3,0x2e1($s0)
/*  f0c0218:	31690001 */ 	andi	$t1,$t3,0x1
/*  f0c021c:	01c16825 */ 	or	$t5,$t6,$at
/*  f0c0220:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0c0224:	ae0d0014 */ 	sw	$t5,0x14($s0)
/*  f0c0228:	a20902e1 */ 	sb	$t1,0x2e1($s0)
/*  f0c022c:	02002025 */ 	move	$a0,$s0
/*  f0c0230:	24050101 */ 	li	$a1,0x101
/*  f0c0234:	24060010 */ 	li	$a2,0x10
/*  f0c0238:	0fc23215 */ 	jal	0xf08c854
/*  f0c023c:	00003825 */ 	move	$a3,$zero
.JF0f0c0240:
/*  f0c0240:	0fc41bed */ 	jal	0xf106fb4
/*  f0c0244:	24040017 */ 	li	$a0,0x17
/*  f0c0248:	10400062 */ 	beqz	$v0,.JF0f0c03d4
/*  f0c024c:	00000000 */ 	nop
/*  f0c0250:	0fc59689 */ 	jal	0xf165a24
/*  f0c0254:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c0258:	24010023 */ 	li	$at,0x23
/*  f0c025c:	14410012 */ 	bne	$v0,$at,.JF0f0c02a8
/*  f0c0260:	00000000 */ 	nop
/*  f0c0264:	0c00611c */ 	jal	0x18470
/*  f0c0268:	24040012 */ 	li	$a0,0x12
/*  f0c026c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0270:	240c0010 */ 	li	$t4,0x10
/*  f0c0274:	2404005b */ 	li	$a0,0x5b
/*  f0c0278:	c6120144 */ 	lwc1	$f18,0x144($s0)
/*  f0c027c:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c0280:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0c0284:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0c0288:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c028c:	24050008 */ 	li	$a1,0x8
/*  f0c0290:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c0294:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c0298:	0fc130e6 */ 	jal	0xf04c398
/*  f0c029c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0c02a0:	10000011 */ 	b	.JF0f0c02e8
/*  f0c02a4:	00408825 */ 	move	$s1,$v0
.JF0f0c02a8:
/*  f0c02a8:	0c00611c */ 	jal	0x18470
/*  f0c02ac:	24040012 */ 	li	$a0,0x12
/*  f0c02b0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c02b4:	24190010 */ 	li	$t9,0x10
/*  f0c02b8:	24040092 */ 	li	$a0,0x92
/*  f0c02bc:	c60a0144 */ 	lwc1	$f10,0x144($s0)
/*  f0c02c0:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c02c4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0c02c8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0c02cc:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c02d0:	02802825 */ 	move	$a1,$s4
/*  f0c02d4:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c02d8:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c02dc:	0fc130e6 */ 	jal	0xf04c398
/*  f0c02e0:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0c02e4:	00408825 */ 	move	$s1,$v0
.JF0f0c02e8:
/*  f0c02e8:	1040003a */ 	beqz	$v0,.JF0f0c03d4
/*  f0c02ec:	3c014030 */ 	lui	$at,0x4030
/*  f0c02f0:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0c02f4:	24180010 */ 	li	$t8,0x10
/*  f0c02f8:	240c0064 */ 	li	$t4,0x64
/*  f0c02fc:	8e0f0118 */ 	lw	$t7,0x118($s0)
/*  f0c0300:	8e0e0114 */ 	lw	$t6,0x114($s0)
/*  f0c0304:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0c0308:	01e15025 */ 	or	$t2,$t7,$at
/*  f0c030c:	3c018000 */ 	lui	$at,0x8000
/*  f0c0310:	24190032 */ 	li	$t9,0x32
/*  f0c0314:	35cd2000 */ 	ori	$t5,$t6,0x2000
/*  f0c0318:	01614825 */ 	or	$t1,$t3,$at
/*  f0c031c:	ae0d0114 */ 	sw	$t5,0x114($s0)
/*  f0c0320:	ae0a0118 */ 	sw	$t2,0x118($s0)
/*  f0c0324:	a2180125 */ 	sb	$t8,0x125($s0)
/*  f0c0328:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0c032c:	ae090014 */ 	sw	$t1,0x14($s0)
/*  f0c0330:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0c0334:	a20c02e2 */ 	sb	$t4,0x2e2($s0)
/*  f0c0338:	a2190002 */ 	sb	$t9,0x2($s0)
/*  f0c033c:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0c0340:	0fc59689 */ 	jal	0xf165a24
/*  f0c0344:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c0348:	14540005 */ 	bne	$v0,$s4,.JF0f0c0360
/*  f0c034c:	02002025 */ 	move	$a0,$s0
/*  f0c0350:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c0354:	3c054220 */ 	lui	$a1,0x4220
/*  f0c0358:	10000005 */ 	b	.JF0f0c0370
/*  f0c035c:	02002025 */ 	move	$a0,$s0
.JF0f0c0360:
/*  f0c0360:	4405b000 */ 	mfc1	$a1,$f22
/*  f0c0364:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c0368:	02002025 */ 	move	$a0,$s0
/*  f0c036c:	02002025 */ 	move	$a0,$s0
.JF0f0c0370:
/*  f0c0370:	0fc085ee */ 	jal	0xf0217b8
/*  f0c0374:	3c054120 */ 	lui	$a1,0x4120
/*  f0c0378:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0c037c:	920b02e1 */ 	lbu	$t3,0x2e1($s0)
/*  f0c0380:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f0c0384:	3c010004 */ 	lui	$at,0x4
/*  f0c0388:	01c16825 */ 	or	$t5,$t6,$at
/*  f0c038c:	356c0001 */ 	ori	$t4,$t3,0x1
/*  f0c0390:	3c012000 */ 	lui	$at,0x2000
/*  f0c0394:	a20c02e1 */ 	sb	$t4,0x2e1($s0)
/*  f0c0398:	31990001 */ 	andi	$t9,$t4,0x1
/*  f0c039c:	01e15025 */ 	or	$t2,$t7,$at
/*  f0c03a0:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f0c03a4:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0c03a8:	a21902e1 */ 	sb	$t9,0x2e1($s0)
/*  f0c03ac:	02002025 */ 	move	$a0,$s0
/*  f0c03b0:	240500f9 */ 	li	$a1,0xf9
/*  f0c03b4:	24060009 */ 	li	$a2,0x9
/*  f0c03b8:	0fc23215 */ 	jal	0xf08c854
/*  f0c03bc:	00003825 */ 	move	$a3,$zero
/*  f0c03c0:	02002025 */ 	move	$a0,$s0
/*  f0c03c4:	240500f8 */ 	li	$a1,0xf8
/*  f0c03c8:	24060008 */ 	li	$a2,0x8
/*  f0c03cc:	0fc23215 */ 	jal	0xf08c854
/*  f0c03d0:	3c071000 */ 	lui	$a3,0x1000
.JF0f0c03d4:
/*  f0c03d4:	0fc41bed */ 	jal	0xf106fb4
/*  f0c03d8:	24040019 */ 	li	$a0,0x19
/*  f0c03dc:	5040005d */ 	beqzl	$v0,.JF0f0c0554
/*  f0c03e0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0c03e4:	0fc59689 */ 	jal	0xf165a24
/*  f0c03e8:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c03ec:	24010023 */ 	li	$at,0x23
/*  f0c03f0:	14410012 */ 	bne	$v0,$at,.JF0f0c043c
/*  f0c03f4:	00000000 */ 	nop
/*  f0c03f8:	0c00611c */ 	jal	0x18470
/*  f0c03fc:	24040012 */ 	li	$a0,0x12
/*  f0c0400:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0404:	240e0010 */ 	li	$t6,0x10
/*  f0c0408:	2404005b */ 	li	$a0,0x5b
/*  f0c040c:	c6060144 */ 	lwc1	$f6,0x144($s0)
/*  f0c0410:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c0414:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0c0418:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0c041c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c0420:	24050008 */ 	li	$a1,0x8
/*  f0c0424:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c0428:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c042c:	0fc130e6 */ 	jal	0xf04c398
/*  f0c0430:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c0434:	10000011 */ 	b	.JF0f0c047c
/*  f0c0438:	00408825 */ 	move	$s1,$v0
.JF0f0c043c:
/*  f0c043c:	0c00611c */ 	jal	0x18470
/*  f0c0440:	24040012 */ 	li	$a0,0x12
/*  f0c0444:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0448:	240d0010 */ 	li	$t5,0x10
/*  f0c044c:	24040057 */ 	li	$a0,0x57
/*  f0c0450:	c6080144 */ 	lwc1	$f8,0x144($s0)
/*  f0c0454:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c0458:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c045c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0c0460:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0c0464:	24050029 */ 	li	$a1,0x29
/*  f0c0468:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0c046c:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0c0470:	0fc130e6 */ 	jal	0xf04c398
/*  f0c0474:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0c0478:	00408825 */ 	move	$s1,$v0
.JF0f0c047c:
/*  f0c047c:	10400034 */ 	beqz	$v0,.JF0f0c0550
/*  f0c0480:	3c01c030 */ 	lui	$at,0xc030
/*  f0c0484:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0c0488:	24090010 */ 	li	$t1,0x10
/*  f0c048c:	240e0096 */ 	li	$t6,0x96
/*  f0c0490:	8e180118 */ 	lw	$t8,0x118($s0)
/*  f0c0494:	8e0f0114 */ 	lw	$t7,0x114($s0)
/*  f0c0498:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*  f0c049c:	03015825 */ 	or	$t3,$t8,$at
/*  f0c04a0:	3c018000 */ 	lui	$at,0x8000
/*  f0c04a4:	35ea2000 */ 	ori	$t2,$t7,0x2000
/*  f0c04a8:	0181c825 */ 	or	$t9,$t4,$at
/*  f0c04ac:	ae0a0114 */ 	sw	$t2,0x114($s0)
/*  f0c04b0:	ae0b0118 */ 	sw	$t3,0x118($s0)
/*  f0c04b4:	a2090125 */ 	sb	$t1,0x125($s0)
/*  f0c04b8:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0c04bc:	ae190014 */ 	sw	$t9,0x14($s0)
/*  f0c04c0:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0c04c4:	a20e02e2 */ 	sb	$t6,0x2e2($s0)
/*  f0c04c8:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0c04cc:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0c04d0:	0fc59689 */ 	jal	0xf165a24
/*  f0c04d4:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0c04d8:	14540005 */ 	bne	$v0,$s4,.JF0f0c04f0
/*  f0c04dc:	02002025 */ 	move	$a0,$s0
/*  f0c04e0:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c04e4:	3c054220 */ 	lui	$a1,0x4220
/*  f0c04e8:	10000005 */ 	b	.JF0f0c0500
/*  f0c04ec:	02002025 */ 	move	$a0,$s0
.JF0f0c04f0:
/*  f0c04f0:	4405b000 */ 	mfc1	$a1,$f22
/*  f0c04f4:	0fc085f3 */ 	jal	0xf0217cc
/*  f0c04f8:	02002025 */ 	move	$a0,$s0
/*  f0c04fc:	02002025 */ 	move	$a0,$s0
.JF0f0c0500:
/*  f0c0500:	0fc085ee */ 	jal	0xf0217b8
/*  f0c0504:	3c054120 */ 	lui	$a1,0x4120
/*  f0c0508:	8e0d0018 */ 	lw	$t5,0x18($s0)
/*  f0c050c:	920902e1 */ 	lbu	$t1,0x2e1($s0)
/*  f0c0510:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0c0514:	3c010004 */ 	lui	$at,0x4
/*  f0c0518:	01a17825 */ 	or	$t7,$t5,$at
/*  f0c051c:	35390001 */ 	ori	$t9,$t1,0x1
/*  f0c0520:	3c012000 */ 	lui	$at,0x2000
/*  f0c0524:	a21902e1 */ 	sb	$t9,0x2e1($s0)
/*  f0c0528:	332e0001 */ 	andi	$t6,$t9,0x1
/*  f0c052c:	0141c025 */ 	or	$t8,$t2,$at
/*  f0c0530:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f0c0534:	ae180014 */ 	sw	$t8,0x14($s0)
/*  f0c0538:	a20e02e1 */ 	sb	$t6,0x2e1($s0)
/*  f0c053c:	02002025 */ 	move	$a0,$s0
/*  f0c0540:	24050104 */ 	li	$a1,0x104
/*  f0c0544:	2406000d */ 	li	$a2,0xd
/*  f0c0548:	0fc23215 */ 	jal	0xf08c854
/*  f0c054c:	00003825 */ 	move	$a3,$zero
.JF0f0c0550:
/*  f0c0550:	8fad0058 */ 	lw	$t5,0x58($sp)
.JF0f0c0554:
/*  f0c0554:	adb104b8 */ 	sw	$s1,0x4b8($t5)
/*  f0c0558:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0c055c:	8e690474 */ 	lw	$t1,0x474($s3)
/*  f0c0560:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0c0564:	25ea0001 */ 	addiu	$t2,$t7,0x1
/*  f0c0568:	0149082a */ 	slt	$at,$t2,$t1
/*  f0c056c:	270b0004 */ 	addiu	$t3,$t8,0x4
/*  f0c0570:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0c0574:	1420fdf8 */ 	bnez	$at,.JF0f0bfd58
/*  f0c0578:	afaa00e8 */ 	sw	$t2,0xe8($sp)
.JF0f0c057c:
/*  f0c057c:	1000011b */ 	b	.JF0f0c09ec
/*  f0c0580:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0584:
/*  f0c0584:	10600003 */ 	beqz	$v1,.JF0f0c0594
/*  f0c0588:	24010005 */ 	li	$at,0x5
/*  f0c058c:	54610018 */ 	bnel	$v1,$at,.JF0f0c05f0
/*  f0c0590:	24010004 */ 	li	$at,0x4
.JF0f0c0594:
/*  f0c0594:	0fc2e96e */ 	jal	0xf0ba5b8
/*  f0c0598:	00000000 */ 	nop
/*  f0c059c:	24040001 */ 	li	$a0,0x1
/*  f0c05a0:	24050001 */ 	li	$a1,0x1
/*  f0c05a4:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0c05a8:	0fc33346 */ 	jal	0xf0ccd18
/*  f0c05ac:	00003825 */ 	move	$a3,$zero
/*  f0c05b0:	0fc2f918 */ 	jal	0xf0be460
/*  f0c05b4:	00000000 */ 	nop
/*  f0c05b8:	0fc30a3a */ 	jal	0xf0c28e8
/*  f0c05bc:	00002025 */ 	move	$a0,$zero
/*  f0c05c0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c05c4:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c05c8:	2604037c */ 	addiu	$a0,$s0,0x37c
/*  f0c05cc:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0c05d0:	246c0028 */ 	addiu	$t4,$v1,0x28
/*  f0c05d4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c05d8:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0c05dc:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0c05e0:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0c05e4:	10000101 */ 	b	.JF0f0c09ec
/*  f0c05e8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c05ec:	24010004 */ 	li	$at,0x4
.JF0f0c05f0:
/*  f0c05f0:	1461000c */ 	bne	$v1,$at,.JF0f0c0624
/*  f0c05f4:	00000000 */ 	nop
/*  f0c05f8:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0c05fc:	00000000 */ 	nop
/*  f0c0600:	00002025 */ 	move	$a0,$zero
/*  f0c0604:	00002825 */ 	move	$a1,$zero
/*  f0c0608:	00003025 */ 	move	$a2,$zero
/*  f0c060c:	0fc33346 */ 	jal	0xf0ccd18
/*  f0c0610:	24070001 */ 	li	$a3,0x1
/*  f0c0614:	0fc2e9da */ 	jal	0xf0ba768
/*  f0c0618:	00000000 */ 	nop
/*  f0c061c:	100000f3 */ 	b	.JF0f0c09ec
/*  f0c0620:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0624:
/*  f0c0624:	1443000c */ 	bne	$v0,$v1,.JF0f0c0658
/*  f0c0628:	24010007 */ 	li	$at,0x7
/*  f0c062c:	0fc2e708 */ 	jal	0xf0b9c20
/*  f0c0630:	00000000 */ 	nop
/*  f0c0634:	00002025 */ 	move	$a0,$zero
/*  f0c0638:	00002825 */ 	move	$a1,$zero
/*  f0c063c:	00003025 */ 	move	$a2,$zero
/*  f0c0640:	0fc33346 */ 	jal	0xf0ccd18
/*  f0c0644:	24070001 */ 	li	$a3,0x1
/*  f0c0648:	0fc2eb4f */ 	jal	0xf0bad3c
/*  f0c064c:	00000000 */ 	nop
/*  f0c0650:	100000e6 */ 	b	.JF0f0c09ec
/*  f0c0654:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0658:
/*  f0c0658:	546100e5 */ 	bnel	$v1,$at,.JF0f0c09f0
/*  f0c065c:	c60a1b80 */ 	lwc1	$f10,0x1b80($s0)
/*  f0c0660:	0fc2e96e */ 	jal	0xf0ba5b8
/*  f0c0664:	00000000 */ 	nop
/*  f0c0668:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0c066c:	24050002 */ 	li	$a1,0x2
/*  f0c0670:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0c0674:	0fc45798 */ 	jal	0xf115e60
/*  f0c0678:	87241ba4 */ 	lh	$a0,0x1ba4($t9)
/*  f0c067c:	0c003a49 */ 	jal	0xe924
/*  f0c0680:	00000000 */ 	nop
/*  f0c0684:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0c0688:	85ce0610 */ 	lh	$t6,0x610($t6)
/*  f0c068c:	544e000c */ 	bnel	$v0,$t6,.JF0f0c06c0
/*  f0c0690:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0694:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f0c0698:	24010019 */ 	li	$at,0x19
/*  f0c069c:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0c06a0:	85af1ba4 */ 	lh	$t7,0x1ba4($t5)
/*  f0c06a4:	15e10005 */ 	bne	$t7,$at,.JF0f0c06bc
/*  f0c06a8:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0c06ac:	44813000 */ 	mtc1	$at,$f6
/*  f0c06b0:	00000000 */ 	nop
/*  f0c06b4:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0c06b8:	e7b20078 */ 	swc1	$f18,0x78($sp)
.JF0f0c06bc:
/*  f0c06bc:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c06c0:
/*  f0c06c0:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0c06c4:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0c06c8:	c60a037c */ 	lwc1	$f10,0x37c($s0)
/*  f0c06cc:	c6060384 */ 	lwc1	$f6,0x384($s0)
/*  f0c06d0:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f0c06d4:	46062381 */ 	sub.s	$f14,$f4,$f6
/*  f0c06d8:	e7ac00d8 */ 	swc1	$f12,0xd8($sp)
/*  f0c06dc:	0fc25d3c */ 	jal	0xf0974f0
/*  f0c06e0:	e7ae00d4 */ 	swc1	$f14,0xd4($sp)
/*  f0c06e4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c06e8:	c436e3c4 */ 	lwc1	$f22,-0x1c3c($at)
/*  f0c06ec:	44809000 */ 	mtc1	$zero,$f18
/*  f0c06f0:	46000506 */ 	mov.s	$f20,$f0
/*  f0c06f4:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0c06f8:	00000000 */ 	nop
/*  f0c06fc:	45020003 */ 	bc1fl	.JF0f0c070c
/*  f0c0700:	4612a03c */ 	c.lt.s	$f20,$f18
/*  f0c0704:	46160501 */ 	sub.s	$f20,$f0,$f22
/*  f0c0708:	4612a03c */ 	c.lt.s	$f20,$f18
.JF0f0c070c:
/*  f0c070c:	00000000 */ 	nop
/*  f0c0710:	45020003 */ 	bc1fl	.JF0f0c0720
/*  f0c0714:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0718:	4616a500 */ 	add.s	$f20,$f20,$f22
/*  f0c071c:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0720:
/*  f0c0720:	c60c036c */ 	lwc1	$f12,0x36c($s0)
/*  f0c0724:	0fc25d3c */ 	jal	0xf0974f0
/*  f0c0728:	c60e0374 */ 	lwc1	$f14,0x374($s0)
/*  f0c072c:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0c0730:	44804000 */ 	mtc1	$zero,$f8
/*  f0c0734:	46000086 */ 	mov.s	$f2,$f0
/*  f0c0738:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c073c:	45020003 */ 	bc1fl	.JF0f0c074c
/*  f0c0740:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0c0744:	46160081 */ 	sub.s	$f2,$f0,$f22
/*  f0c0748:	4608103c */ 	c.lt.s	$f2,$f8
.JF0f0c074c:
/*  f0c074c:	00000000 */ 	nop
/*  f0c0750:	45020003 */ 	bc1fl	.JF0f0c0760
/*  f0c0754:	46141301 */ 	sub.s	$f12,$f2,$f20
/*  f0c0758:	46161080 */ 	add.s	$f2,$f2,$f22
/*  f0c075c:	46141301 */ 	sub.s	$f12,$f2,$f20
.JF0f0c0760:
/*  f0c0760:	c42ee3c8 */ 	lwc1	$f14,-0x1c38($at)
/*  f0c0764:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c0768:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0c076c:	46006006 */ 	mov.s	$f0,$f12
/*  f0c0770:	45000002 */ 	bc1f	.JF0f0c077c
/*  f0c0774:	00000000 */ 	nop
/*  f0c0778:	46166001 */ 	sub.s	$f0,$f12,$f22
.JF0f0c077c:
/*  f0c077c:	c42ae3cc */ 	lwc1	$f10,-0x1c34($at)
/*  f0c0780:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0c0784:	00000000 */ 	nop
/*  f0c0788:	45020003 */ 	bc1fl	.JF0f0c0798
/*  f0c078c:	460e0103 */ 	div.s	$f4,$f0,$f14
/*  f0c0790:	46160000 */ 	add.s	$f0,$f0,$f22
/*  f0c0794:	460e0103 */ 	div.s	$f4,$f0,$f14
.JF0f0c0798:
/*  f0c0798:	44803000 */ 	mtc1	$zero,$f6
/*  f0c079c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c07a0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0c07a4:	00000000 */ 	nop
/*  f0c07a8:	45020006 */ 	bc1fl	.JF0f0c07c4
/*  f0c07ac:	44811000 */ 	mtc1	$at,$f2
/*  f0c07b0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c07b4:	44811000 */ 	mtc1	$at,$f2
/*  f0c07b8:	10000004 */ 	b	.JF0f0c07cc
/*  f0c07bc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c07c0:	44811000 */ 	mtc1	$at,$f2
.JF0f0c07c4:
/*  f0c07c4:	00000000 */ 	nop
/*  f0c07c8:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c07cc:
/*  f0c07cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c07d0:	8e181bac */ 	lw	$t8,0x1bac($s0)
/*  f0c07d4:	44989000 */ 	mtc1	$t8,$f18
/*  f0c07d8:	00000000 */ 	nop
/*  f0c07dc:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0c07e0:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0c07e4:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0c07e8:	440a2000 */ 	mfc1	$t2,$f4
/*  f0c07ec:	00000000 */ 	nop
/*  f0c07f0:	ae0a1bd8 */ 	sw	$t2,0x1bd8($s0)
/*  f0c07f4:	c426e3d0 */ 	lwc1	$f6,-0x1c30($at)
/*  f0c07f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c07fc:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0c0800:	00000000 */ 	nop
/*  f0c0804:	4503000e */ 	bc1tl	.JF0f0c0840
/*  f0c0808:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c080c:	c432e3d4 */ 	lwc1	$f18,-0x1c2c($at)
/*  f0c0810:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c0814:	00000000 */ 	nop
/*  f0c0818:	45030009 */ 	bc1tl	.JF0f0c0840
/*  f0c081c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0820:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0c0824:	ad201bd8 */ 	sw	$zero,0x1bd8($t1)
/*  f0c0828:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c082c:	860c1baa */ 	lh	$t4,0x1baa($s0)
/*  f0c0830:	55800003 */ 	bnezl	$t4,.JF0f0c0840
/*  f0c0834:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0838:	ae001bac */ 	sw	$zero,0x1bac($s0)
/*  f0c083c:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0840:
/*  f0c0840:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c0844:	44814000 */ 	mtc1	$at,$f8
/*  f0c0848:	c6020154 */ 	lwc1	$f2,0x154($s0)
/*  f0c084c:	4608103e */ 	c.le.s	$f2,$f8
/*  f0c0850:	00000000 */ 	nop
/*  f0c0854:	4502000d */ 	bc1fl	.JF0f0c088c
/*  f0c0858:	86021baa */ 	lh	$v0,0x1baa($s0)
/*  f0c085c:	86191ba6 */ 	lh	$t9,0x1ba6($s0)
/*  f0c0860:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c0864:	44813000 */ 	mtc1	$at,$f6
/*  f0c0868:	44995000 */ 	mtc1	$t9,$f10
/*  f0c086c:	00000000 */ 	nop
/*  f0c0870:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0c0874:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0c0878:	46169202 */ 	mul.s	$f8,$f18,$f22
/*  f0c087c:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0c0880:	e60a0154 */ 	swc1	$f10,0x154($s0)
/*  f0c0884:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0888:	86021baa */ 	lh	$v0,0x1baa($s0)
.JF0f0c088c:
/*  f0c088c:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0c0890:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c0894:	10400015 */ 	beqz	$v0,.JF0f0c08ec
/*  f0c0898:	00000000 */ 	nop
/*  f0c089c:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0c08a0:	c7a000d4 */ 	lwc1	$f0,0xd4($sp)
/*  f0c08a4:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0c08a8:	0c012838 */ 	jal	0x4a0e0
/*  f0c08ac:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f0c08b0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c08b4:	e7a000d8 */ 	swc1	$f0,0xd8($sp)
/*  f0c08b8:	860e1ba8 */ 	lh	$t6,0x1ba8($s0)
/*  f0c08bc:	448e4000 */ 	mtc1	$t6,$f8
/*  f0c08c0:	00000000 */ 	nop
/*  f0c08c4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0c08c8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0c08cc:	00000000 */ 	nop
/*  f0c08d0:	45000004 */ 	bc1f	.JF0f0c08e4
/*  f0c08d4:	00000000 */ 	nop
/*  f0c08d8:	0fc2e9af */ 	jal	0xf0ba6bc
/*  f0c08dc:	24040001 */ 	li	$a0,0x1
/*  f0c08e0:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c08e4:
/*  f0c08e4:	10000010 */ 	b	.JF0f0c0928
/*  f0c08e8:	86021baa */ 	lh	$v0,0x1baa($s0)
.JF0f0c08ec:
/*  f0c08ec:	c424e3d8 */ 	lwc1	$f4,-0x1c28($at)
/*  f0c08f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c08f4:	4600203e */ 	c.le.s	$f4,$f0
/*  f0c08f8:	00000000 */ 	nop
/*  f0c08fc:	4502000b */ 	bc1fl	.JF0f0c092c
/*  f0c0900:	860d1ba8 */ 	lh	$t5,0x1ba8($s0)
/*  f0c0904:	c426e3dc */ 	lwc1	$f6,-0x1c24($at)
/*  f0c0908:	4606003e */ 	c.le.s	$f0,$f6
/*  f0c090c:	00000000 */ 	nop
/*  f0c0910:	45020006 */ 	bc1fl	.JF0f0c092c
/*  f0c0914:	860d1ba8 */ 	lh	$t5,0x1ba8($s0)
/*  f0c0918:	0fc2e9af */ 	jal	0xf0ba6bc
/*  f0c091c:	24040001 */ 	li	$a0,0x1
/*  f0c0920:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0924:	86021baa */ 	lh	$v0,0x1baa($s0)
.JF0f0c0928:
/*  f0c0928:	860d1ba8 */ 	lh	$t5,0x1ba8($s0)
.JF0f0c092c:
/*  f0c092c:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f0c0930:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0934:	448d9000 */ 	mtc1	$t5,$f18
/*  f0c0938:	44811000 */ 	mtc1	$at,$f2
/*  f0c093c:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0c0940:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0c0944:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0c0948:	00000000 */ 	nop
/*  f0c094c:	4502000f */ 	bc1fl	.JF0f0c098c
/*  f0c0950:	44824000 */ 	mtc1	$v0,$f8
/*  f0c0954:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c0958:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0c095c:	45020005 */ 	bc1fl	.JF0f0c0974
/*  f0c0960:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c0964:	44801000 */ 	mtc1	$zero,$f2
/*  f0c0968:	10000008 */ 	b	.JF0f0c098c
/*  f0c096c:	44824000 */ 	mtc1	$v0,$f8
/*  f0c0970:	46002181 */ 	sub.s	$f6,$f4,$f0
.JF0f0c0974:
/*  f0c0974:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c0978:	44816000 */ 	mtc1	$at,$f12
/*  f0c097c:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f0c0980:	460c9282 */ 	mul.s	$f10,$f18,$f12
/*  f0c0984:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f0c0988:	44824000 */ 	mtc1	$v0,$f8
.JF0f0c098c:
/*  f0c098c:	24040001 */ 	li	$a0,0x1
/*  f0c0990:	24050001 */ 	li	$a1,0x1
/*  f0c0994:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0c0998:	00003025 */ 	move	$a2,$zero
/*  f0c099c:	24070001 */ 	li	$a3,0x1
/*  f0c09a0:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0c09a4:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0c09a8:	44189000 */ 	mfc1	$t8,$f18
/*  f0c09ac:	0fc33346 */ 	jal	0xf0ccd18
/*  f0c09b0:	ae181bdc */ 	sw	$t8,0x1bdc($s0)
/*  f0c09b4:	0fc2f918 */ 	jal	0xf0be460
/*  f0c09b8:	00000000 */ 	nop
/*  f0c09bc:	0fc30a3a */ 	jal	0xf0c28e8
/*  f0c09c0:	00002025 */ 	move	$a0,$zero
/*  f0c09c4:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c09c8:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0c09cc:	2604037c */ 	addiu	$a0,$s0,0x37c
/*  f0c09d0:	26050394 */ 	addiu	$a1,$s0,0x394
/*  f0c09d4:	246b0028 */ 	addiu	$t3,$v1,0x28
/*  f0c09d8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c09dc:	26060388 */ 	addiu	$a2,$s0,0x388
/*  f0c09e0:	0fc30a3e */ 	jal	0xf0c28f8
/*  f0c09e4:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0c09e8:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c09ec:
/*  f0c09ec:	c60a1b80 */ 	lwc1	$f10,0x1b80($s0)
.JF0f0c09f0:
/*  f0c09f0:	c6680010 */ 	lwc1	$f8,0x10($s3)
/*  f0c09f4:	3c118007 */ 	lui	$s1,0x8007
/*  f0c09f8:	26310c9c */ 	addiu	$s1,$s1,0xc9c
/*  f0c09fc:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c0a00:	e6041b80 */ 	swc1	$f4,0x1b80($s0)
/*  f0c0a04:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0c0a08:	11400047 */ 	beqz	$t2,.JF0f0c0b28
/*  f0c0a0c:	00000000 */ 	nop
/*  f0c0a10:	8e690288 */ 	lw	$t1,0x288($s3)
/*  f0c0a14:	0fc5475a */ 	jal	0xf151d68
/*  f0c0a18:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0c0a1c:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0c0a20:	00106603 */ 	sra	$t4,$s0,0x18
/*  f0c0a24:	0fc5b3cc */ 	jal	0xf16cf30
/*  f0c0a28:	01808025 */ 	move	$s0,$t4
/*  f0c0a2c:	1440002c */ 	bnez	$v0,.JF0f0c0ae0
/*  f0c0a30:	8fb90330 */ 	lw	$t9,0x330($sp)
/*  f0c0a34:	1320002a */ 	beqz	$t9,.JF0f0c0ae0
/*  f0c0a38:	00102600 */ 	sll	$a0,$s0,0x18
/*  f0c0a3c:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0c0a40:	01c02025 */ 	move	$a0,$t6
/*  f0c0a44:	0c0053ee */ 	jal	0x14fb8
/*  f0c0a48:	3405f030 */ 	li	$a1,0xf030
/*  f0c0a4c:	10400024 */ 	beqz	$v0,.JF0f0c0ae0
/*  f0c0a50:	240d0002 */ 	li	$t5,0x2
/*  f0c0a54:	0fc2f11f */ 	jal	0xf0bc47c
/*  f0c0a58:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f0c0a5c:	50400016 */ 	beqzl	$v0,.JF0f0c0ab8
/*  f0c0a60:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0a64:	8e6f0284 */ 	lw	$t7,0x284($s3)
/*  f0c0a68:	44800000 */ 	mtc1	$zero,$f0
/*  f0c0a6c:	00002025 */ 	move	$a0,$zero
/*  f0c0a70:	c5e602e4 */ 	lwc1	$f6,0x2e4($t7)
/*  f0c0a74:	00002825 */ 	move	$a1,$zero
/*  f0c0a78:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0c0a7c:	00000000 */ 	nop
/*  f0c0a80:	45020018 */ 	bc1fl	.JF0f0c0ae4
/*  f0c0a84:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0c0a88:	44070000 */ 	mfc1	$a3,$f0
/*  f0c0a8c:	0fc2f0e8 */ 	jal	0xf0bc3a0
/*  f0c0a90:	00003025 */ 	move	$a2,$zero
/*  f0c0a94:	3c014270 */ 	lui	$at,0x4270
/*  f0c0a98:	44816000 */ 	mtc1	$at,$f12
/*  f0c0a9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0aa0:	44817000 */ 	mtc1	$at,$f14
/*  f0c0aa4:	0fc2f112 */ 	jal	0xf0bc448
/*  f0c0aa8:	00000000 */ 	nop
/*  f0c0aac:	1000000d */ 	b	.JF0f0c0ae4
/*  f0c0ab0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0c0ab4:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0ab8:
/*  f0c0ab8:	44809000 */ 	mtc1	$zero,$f18
/*  f0c0abc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0ac0:	c60a030c */ 	lwc1	$f10,0x30c($s0)
/*  f0c0ac4:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0c0ac8:	00000000 */ 	nop
/*  f0c0acc:	45020005 */ 	bc1fl	.JF0f0c0ae4
/*  f0c0ad0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0c0ad4:	44817000 */ 	mtc1	$at,$f14
/*  f0c0ad8:	0fc2f112 */ 	jal	0xf0bc448
/*  f0c0adc:	c60c02e8 */ 	lwc1	$f12,0x2e8($s0)
.JF0f0c0ae0:
/*  f0c0ae0:	8e380000 */ 	lw	$t8,0x0($s1)
.JF0f0c0ae4:
/*  f0c0ae4:	24010002 */ 	li	$at,0x2
/*  f0c0ae8:	1701000f */ 	bne	$t8,$at,.JF0f0c0b28
/*  f0c0aec:	00000000 */ 	nop
/*  f0c0af0:	0fc2f11f */ 	jal	0xf0bc47c
/*  f0c0af4:	00000000 */ 	nop
/*  f0c0af8:	1040000b */ 	beqz	$v0,.JF0f0c0b28
/*  f0c0afc:	00000000 */ 	nop
/*  f0c0b00:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0c0b04:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c0b08:	44814000 */ 	mtc1	$at,$f8
/*  f0c0b0c:	c56402e4 */ 	lwc1	$f4,0x2e4($t3)
/*  f0c0b10:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0c0b14:	00000000 */ 	nop
/*  f0c0b18:	45000003 */ 	bc1f	.JF0f0c0b28
/*  f0c0b1c:	00000000 */ 	nop
/*  f0c0b20:	0c003a4c */ 	jal	0xe930
/*  f0c0b24:	00000000 */ 	nop
.JF0f0c0b28:
/*  f0c0b28:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0c0b2c:	8d4a0c94 */ 	lw	$t2,0xc94($t2)
/*  f0c0b30:	51400004 */ 	beqzl	$t2,.JF0f0c0b44
/*  f0c0b34:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0b38:	0fc2e9b4 */ 	jal	0xf0ba6d0
/*  f0c0b3c:	00000000 */ 	nop
/*  f0c0b40:	8e700284 */ 	lw	$s0,0x284($s3)
.JF0f0c0b44:
/*  f0c0b44:	8e0900d8 */ 	lw	$t1,0xd8($s0)
/*  f0c0b48:	51200035 */ 	beqzl	$t1,.JF0f0c0c20
/*  f0c0b4c:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0b50:	8e02032c */ 	lw	$v0,0x32c($s0)
/*  f0c0b54:	14400005 */ 	bnez	$v0,.JF0f0c0b6c
/*  f0c0b58:	00000000 */ 	nop
/*  f0c0b5c:	0fc28e4c */ 	jal	0xf0a3930
/*  f0c0b60:	00000000 */ 	nop
/*  f0c0b64:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f0c0b68:	8e02032c */ 	lw	$v0,0x32c($s0)
.JF0f0c0b6c:
/*  f0c0b6c:	5040002c */ 	beqzl	$v0,.JF0f0c0c20
/*  f0c0b70:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0b74:	8e0c0330 */ 	lw	$t4,0x330($s0)
/*  f0c0b78:	51800029 */ 	beqzl	$t4,.JF0f0c0c20
/*  f0c0b7c:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0b80:	8e790314 */ 	lw	$t9,0x314($s3)
/*  f0c0b84:	57200006 */ 	bnezl	$t9,.JF0f0c0ba0
/*  f0c0b88:	8e6e0298 */ 	lw	$t6,0x298($s3)
/*  f0c0b8c:	0c003989 */ 	jal	0xe624
/*  f0c0b90:	00000000 */ 	nop
/*  f0c0b94:	10000022 */ 	b	.JF0f0c0c20
/*  f0c0b98:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0b9c:	8e6e0298 */ 	lw	$t6,0x298($s3)
.JF0f0c0ba0:
/*  f0c0ba0:	05c20017 */ 	bltzl	$t6,.JF0f0c0c00
/*  f0c0ba4:	8e6a029c */ 	lw	$t2,0x29c($s3)
/*  f0c0ba8:	8e6d02a0 */ 	lw	$t5,0x2a0($s3)
/*  f0c0bac:	15b0000f */ 	bne	$t5,$s0,.JF0f0c0bec
/*  f0c0bb0:	00000000 */ 	nop
/*  f0c0bb4:	8e6202a4 */ 	lw	$v0,0x2a4($s3)
/*  f0c0bb8:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f0c0bbc:	11e0000b */ 	beqz	$t7,.JF0f0c0bec
/*  f0c0bc0:	00000000 */ 	nop
/*  f0c0bc4:	8c58032c */ 	lw	$t8,0x32c($v0)
/*  f0c0bc8:	13000008 */ 	beqz	$t8,.JF0f0c0bec
/*  f0c0bcc:	00000000 */ 	nop
/*  f0c0bd0:	8c4b0330 */ 	lw	$t3,0x330($v0)
/*  f0c0bd4:	11600005 */ 	beqz	$t3,.JF0f0c0bec
/*  f0c0bd8:	00000000 */ 	nop
/*  f0c0bdc:	0c003989 */ 	jal	0xe624
/*  f0c0be0:	00000000 */ 	nop
/*  f0c0be4:	1000000e */ 	b	.JF0f0c0c20
/*  f0c0be8:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
.JF0f0c0bec:
/*  f0c0bec:	0fc129ba */ 	jal	0xf04a6e8
/*  f0c0bf0:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0c0bf4:	1000000a */ 	b	.JF0f0c0c20
/*  f0c0bf8:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0bfc:	8e6a029c */ 	lw	$t2,0x29c($s3)
.JF0f0c0c00:
/*  f0c0c00:	05420007 */ 	bltzl	$t2,.JF0f0c0c20
/*  f0c0c04:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0c08:	8e6902a0 */ 	lw	$t1,0x2a0($s3)
/*  f0c0c0c:	55300004 */ 	bnel	$t1,$s0,.JF0f0c0c20
/*  f0c0c10:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0c0c14:	0c003989 */ 	jal	0xe624
/*  f0c0c18:	00000000 */ 	nop
/*  f0c0c1c:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
.JF0f0c0c20:
/*  f0c0c20:	24010005 */ 	li	$at,0x5
/*  f0c0c24:	55810008 */ 	bnel	$t4,$at,.JF0f0c0c48
/*  f0c0c28:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0c0c2c:	0fc2f11f */ 	jal	0xf0bc47c
/*  f0c0c30:	00000000 */ 	nop
/*  f0c0c34:	50400004 */ 	beqzl	$v0,.JF0f0c0c48
/*  f0c0c38:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0c0c3c:	0c003989 */ 	jal	0xe624
/*  f0c0c40:	00000000 */ 	nop
/*  f0c0c44:	8fbf004c */ 	lw	$ra,0x4c($sp)
.JF0f0c0c48:
/*  f0c0c48:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0c0c4c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0c0c50:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0c0c54:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0c0c58:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0c0c5c:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0c0c60:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0c0c64:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0c0c68:	03e00008 */ 	jr	$ra
/*  f0c0c6c:	27bd0330 */ 	addiu	$sp,$sp,0x330
);
#elif VERSION == VERSION_PAL_BETA
const char var7f1af224pb[] = "tps";
struct coord var800726acpb = {0, 0, 0};
struct coord var800726b8pb = {0, 0, 1};
struct coord var800726c4pb = {0, 1, 0};

GLOBAL_ASM(
glabel playerTick
.late_rodata
glabel var7f1af390
.word 0x3faaaaab
.word 0x3f986186
.word 0x3983126f
.word 0x3d4ccccd
.word 0x3d4ccccd
.word 0x3c8ef461
.word 0x40c907a9
.word 0x40490fdb
.word 0xc0490fdb
.word 0xbdb851ec
.word 0x3db851ec
.word 0xbe4ccccd
.word 0x3e4ccccd
.text
/*  f0bdd70:	27bdfcd0 */ 	addiu	$sp,$sp,-816
/*  f0bdd74:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0bdd78:	3c13800a */ 	lui	$s3,0x800a
/*  f0bdd7c:	2673e4d0 */ 	addiu	$s3,$s3,-6960
/*  f0bdd80:	8e6f0298 */ 	lw	$t7,0x298($s3)
/*  f0bdd84:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0bdd88:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0bdd8c:	8dce239c */ 	lw	$t6,0x239c($t6)
/*  f0bdd90:	3c118007 */ 	lui	$s1,0x8007
/*  f0bdd94:	26312398 */ 	addiu	$s1,$s1,0x2398
/*  f0bdd98:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0bdd9c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0bdda0:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0bdda4:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0bdda8:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0bddac:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0bddb0:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0bddb4:	afa40330 */ 	sw	$a0,0x330($sp)
/*  f0bddb8:	05e10004 */ 	bgez	$t7,.PB0f0bddcc
/*  f0bddbc:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0bddc0:	8e78029c */ 	lw	$t8,0x29c($s3)
/*  f0bddc4:	0700001f */ 	bltz	$t8,.PB0f0bde44
/*  f0bddc8:	00000000 */ 	nop
.PB0f0bddcc:
/*  f0bddcc:	8e79006c */ 	lw	$t9,0x6c($s3)
/*  f0bddd0:	00003825 */ 	move	$a3,$zero
/*  f0bddd4:	00002825 */ 	move	$a1,$zero
/*  f0bddd8:	13200003 */ 	beqz	$t9,.PB0f0bdde8
/*  f0bdddc:	00002025 */ 	move	$a0,$zero
/*  f0bdde0:	10000001 */ 	b	.PB0f0bdde8
/*  f0bdde4:	24070001 */ 	li	$a3,0x1
.PB0f0bdde8:
/*  f0bdde8:	8e690068 */ 	lw	$t1,0x68($s3)
/*  f0bddec:	00001025 */ 	move	$v0,$zero
/*  f0bddf0:	11200003 */ 	beqz	$t1,.PB0f0bde00
/*  f0bddf4:	00000000 */ 	nop
/*  f0bddf8:	10000001 */ 	b	.PB0f0bde00
/*  f0bddfc:	24050001 */ 	li	$a1,0x1
.PB0f0bde00:
/*  f0bde00:	8e6a0064 */ 	lw	$t2,0x64($s3)
/*  f0bde04:	11400003 */ 	beqz	$t2,.PB0f0bde14
/*  f0bde08:	00000000 */ 	nop
/*  f0bde0c:	10000001 */ 	b	.PB0f0bde14
/*  f0bde10:	24040001 */ 	li	$a0,0x1
.PB0f0bde14:
/*  f0bde14:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f0bde18:	11600003 */ 	beqz	$t3,.PB0f0bde28
/*  f0bde1c:	00000000 */ 	nop
/*  f0bde20:	10000001 */ 	b	.PB0f0bde28
/*  f0bde24:	24020001 */ 	li	$v0,0x1
.PB0f0bde28:
/*  f0bde28:	00446021 */ 	addu	$t4,$v0,$a0
/*  f0bde2c:	01856821 */ 	addu	$t5,$t4,$a1
/*  f0bde30:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f0bde34:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0bde38:	14200002 */ 	bnez	$at,.PB0f0bde44
/*  f0bde3c:	00000000 */ 	nop
/*  f0bde40:	ae200000 */ 	sw	$zero,0x0($s1)
.PB0f0bde44:
/*  f0bde44:	0fc55163 */ 	jal	func0f1531dc
/*  f0bde48:	00002025 */ 	move	$a0,$zero
/*  f0bde4c:	0fc550b3 */ 	jal	optionsGetScreenRatio
/*  f0bde50:	00000000 */ 	nop
/*  f0bde54:	24010001 */ 	li	$at,0x1
/*  f0bde58:	14410008 */ 	bne	$v0,$at,.PB0f0bde7c
/*  f0bde5c:	00000000 */ 	nop
/*  f0bde60:	0fc2f5f1 */ 	jal	player0f0bd358
/*  f0bde64:	00000000 */ 	nop
/*  f0bde68:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bde6c:	c424f390 */ 	lwc1	$f4,-0xc70($at)
/*  f0bde70:	46040382 */ 	mul.s	$f14,$f0,$f4
/*  f0bde74:	10000004 */ 	b	.PB0f0bde88
/*  f0bde78:	00000000 */ 	nop
.PB0f0bde7c:
/*  f0bde7c:	0fc2f5f1 */ 	jal	player0f0bd358
/*  f0bde80:	00000000 */ 	nop
/*  f0bde84:	46000386 */ 	mov.s	$f14,$f0
.PB0f0bde88:
/*  f0bde88:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bde8c:	c426f394 */ 	lwc1	$f6,-0xc6c($at)
/*  f0bde90:	3c108007 */ 	lui	$s0,0x8007
/*  f0bde94:	2610250c */ 	addiu	$s0,$s0,0x250c
/*  f0bde98:	46067382 */ 	mul.s	$f14,$f14,$f6
/*  f0bde9c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0bdea0:	2484f224 */ 	addiu	$a0,$a0,-3548
/*  f0bdea4:	02002825 */ 	move	$a1,$s0
/*  f0bdea8:	0c003648 */ 	jal	mainOverrideVariable
/*  f0bdeac:	e7ae032c */ 	swc1	$f14,0x32c($sp)
/*  f0bdeb0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0bdeb4:	51e00008 */ 	beqzl	$t7,.PB0f0bded8
/*  f0bdeb8:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0bdebc:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f0bdec0:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f0bdec4:	24150001 */ 	li	$s5,0x1
/*  f0bdec8:	a3001bfd */ 	sb	$zero,0x1bfd($t8)
/*  f0bdecc:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0bded0:	a3351bfc */ 	sb	$s5,0x1bfc($t9)
/*  f0bded4:	8e690284 */ 	lw	$t1,0x284($s3)
.PB0f0bded8:
/*  f0bded8:	24150001 */ 	li	$s5,0x1
/*  f0bdedc:	912a1bfc */ 	lbu	$t2,0x1bfc($t1)
/*  f0bdee0:	51400004 */ 	beqzl	$t2,.PB0f0bdef4
/*  f0bdee4:	8e6b04b4 */ 	lw	$t3,0x4b4($s3)
/*  f0bdee8:	0fc2f654 */ 	jal	playerTickTeleport
/*  f0bdeec:	27a4032c */ 	addiu	$a0,$sp,0x32c
/*  f0bdef0:	8e6b04b4 */ 	lw	$t3,0x4b4($s3)
.PB0f0bdef4:
/*  f0bdef4:	2401004e */ 	li	$at,0x4e
/*  f0bdef8:	5561000a */ 	bnel	$t3,$at,.PB0f0bdf24
/*  f0bdefc:	3c014270 */ 	lui	$at,0x4270
/*  f0bdf00:	0fc06b7e */ 	jal	func0f01ad5c
/*  f0bdf04:	00000000 */ 	nop
/*  f0bdf08:	50400006 */ 	beqzl	$v0,.PB0f0bdf24
/*  f0bdf0c:	3c014270 */ 	lui	$at,0x4270
/*  f0bdf10:	0fc06b95 */ 	jal	func0f01adb8
/*  f0bdf14:	00000000 */ 	nop
/*  f0bdf18:	1000083b */ 	b	.PB0f0c0008
/*  f0bdf1c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bdf20:	3c014270 */ 	lui	$at,0x4270
.PB0f0bdf24:
/*  f0bdf24:	44816000 */ 	mtc1	$at,$f12
/*  f0bdf28:	0fc4a7ed */ 	jal	playermgrSetFovY
/*  f0bdf2c:	00000000 */ 	nop
/*  f0bdf30:	0fc4a7f1 */ 	jal	playermgrSetAspectRatio
/*  f0bdf34:	c7ac032c */ 	lwc1	$f12,0x32c($sp)
/*  f0bdf38:	0fc2f270 */ 	jal	playerGetViewportWidth
/*  f0bdf3c:	00000000 */ 	nop
/*  f0bdf40:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdf44:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0bdf48:	0fc2f3c3 */ 	jal	playerGetViewportHeight
/*  f0bdf4c:	01808025 */ 	move	$s0,$t4
/*  f0bdf50:	02002025 */ 	move	$a0,$s0
/*  f0bdf54:	0fc4a7df */ 	jal	playermgrSetViewSize
/*  f0bdf58:	00402825 */ 	move	$a1,$v0
/*  f0bdf5c:	0fc2f306 */ 	jal	playerGetViewportLeft
/*  f0bdf60:	00000000 */ 	nop
/*  f0bdf64:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdf68:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0bdf6c:	0fc2f4a4 */ 	jal	playerGetViewportTop
/*  f0bdf70:	01a08025 */ 	move	$s0,$t5
/*  f0bdf74:	02002025 */ 	move	$a0,$s0
/*  f0bdf78:	0fc4a7e6 */ 	jal	playermgrSetViewPosition
/*  f0bdf7c:	00402825 */ 	move	$a1,$v0
/*  f0bdf80:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0bdf84:	3c048007 */ 	lui	$a0,0x8007
/*  f0bdf88:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0bdf8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bdf90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bdf94:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0bdf98:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0bdf9c:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f0bdfa0:	0c0029f7 */ 	jal	viSetMode
/*  f0bdfa4:	8c842350 */ 	lw	$a0,0x2350($a0)
/*  f0bdfa8:	0fc2f270 */ 	jal	playerGetViewportWidth
/*  f0bdfac:	00000000 */ 	nop
/*  f0bdfb0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdfb4:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0bdfb8:	0fc2f3c3 */ 	jal	playerGetViewportHeight
/*  f0bdfbc:	03008025 */ 	move	$s0,$t8
/*  f0bdfc0:	3c014270 */ 	lui	$at,0x4270
/*  f0bdfc4:	00103400 */ 	sll	$a2,$s0,0x10
/*  f0bdfc8:	00023c00 */ 	sll	$a3,$v0,0x10
/*  f0bdfcc:	00074c03 */ 	sra	$t1,$a3,0x10
/*  f0bdfd0:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f0bdfd4:	44816000 */ 	mtc1	$at,$f12
/*  f0bdfd8:	03203025 */ 	move	$a2,$t9
/*  f0bdfdc:	01203825 */ 	move	$a3,$t1
/*  f0bdfe0:	0c002ec1 */ 	jal	viSetFovAspectAndSize
/*  f0bdfe4:	c7ae032c */ 	lwc1	$f14,0x32c($sp)
/*  f0bdfe8:	0fc2f306 */ 	jal	playerGetViewportLeft
/*  f0bdfec:	00000000 */ 	nop
/*  f0bdff0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0bdff4:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0bdff8:	0fc2f4a4 */ 	jal	playerGetViewportTop
/*  f0bdffc:	01408025 */ 	move	$s0,$t2
/*  f0be000:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be004:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be008:	00056403 */ 	sra	$t4,$a1,0x10
/*  f0be00c:	00045c03 */ 	sra	$t3,$a0,0x10
/*  f0be010:	01602025 */ 	move	$a0,$t3
/*  f0be014:	0c002e75 */ 	jal	viSetViewPosition
/*  f0be018:	01802825 */ 	move	$a1,$t4
/*  f0be01c:	0fc2f22e */ 	jal	playerGetFbWidth
/*  f0be020:	00000000 */ 	nop
/*  f0be024:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be028:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0be02c:	0fc2f239 */ 	jal	playerGetFbHeight
/*  f0be030:	01a08025 */ 	move	$s0,$t5
/*  f0be034:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be038:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be03c:	00057c03 */ 	sra	$t7,$a1,0x10
/*  f0be040:	00047403 */ 	sra	$t6,$a0,0x10
/*  f0be044:	01c02025 */ 	move	$a0,$t6
/*  f0be048:	0c002e44 */ 	jal	viSetSize
/*  f0be04c:	01e02825 */ 	move	$a1,$t7
/*  f0be050:	0fc2f22e */ 	jal	playerGetFbWidth
/*  f0be054:	00000000 */ 	nop
/*  f0be058:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0be05c:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0be060:	0fc2f239 */ 	jal	playerGetFbHeight
/*  f0be064:	03008025 */ 	move	$s0,$t8
/*  f0be068:	00102400 */ 	sll	$a0,$s0,0x10
/*  f0be06c:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f0be070:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f0be074:	0004cc03 */ 	sra	$t9,$a0,0x10
/*  f0be078:	03202025 */ 	move	$a0,$t9
/*  f0be07c:	0c002e33 */ 	jal	viSetBufSize
/*  f0be080:	01202825 */ 	move	$a1,$t1
/*  f0be084:	0fc2ee1f */ 	jal	playerUpdateColourScreenProperties
/*  f0be088:	00000000 */ 	nop
/*  f0be08c:	0fc2ee8f */ 	jal	playerTickChrFade
/*  f0be090:	00000000 */ 	nop
/*  f0be094:	8e6a0288 */ 	lw	$t2,0x288($s3)
/*  f0be098:	0fc54ed5 */ 	jal	optionsGetAutoAim
/*  f0be09c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0be0a0:	0fc31fac */ 	jal	bmoveSetAutoAimY
/*  f0be0a4:	00402025 */ 	move	$a0,$v0
/*  f0be0a8:	8e6b0288 */ 	lw	$t3,0x288($s3)
/*  f0be0ac:	0fc54ed5 */ 	jal	optionsGetAutoAim
/*  f0be0b0:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0be0b4:	0fc31ffd */ 	jal	bmoveSetAutoAimX
/*  f0be0b8:	00402025 */ 	move	$a0,$v0
/*  f0be0bc:	8e6c0288 */ 	lw	$t4,0x288($s3)
/*  f0be0c0:	0fc54ede */ 	jal	optionsGetLookAhead
/*  f0be0c4:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0be0c8:	0fc31fa4 */ 	jal	bmoveSetAutoMoveCentreEnabled
/*  f0be0cc:	00402025 */ 	move	$a0,$v0
/*  f0be0d0:	8e6d0288 */ 	lw	$t5,0x288($s3)
/*  f0be0d4:	0fc54ef9 */ 	jal	optionsGetAmmoOnScreen
/*  f0be0d8:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0be0dc:	02a02025 */ 	move	$a0,$s5
/*  f0be0e0:	0fc2a662 */ 	jal	bgunSetGunAmmoVisible
/*  f0be0e4:	00402825 */ 	move	$a1,$v0
/*  f0be0e8:	02a02025 */ 	move	$a0,$s5
/*  f0be0ec:	0fc2b020 */ 	jal	bgunSetSightVisible
/*  f0be0f0:	24050001 */ 	li	$a1,0x1
/*  f0be0f4:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0be0f8:	10600002 */ 	beqz	$v1,.PB0f0be104
/*  f0be0fc:	24010001 */ 	li	$at,0x1
/*  f0be100:	1461000d */ 	bne	$v1,$at,.PB0f0be138
.PB0f0be104:
/*  f0be104:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0be108:	8dce2434 */ 	lw	$t6,0x2434($t6)
/*  f0be10c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0be110:	55c0000a */ 	bnezl	$t6,.PB0f0be13c
/*  f0be114:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0be118:	8defe4e0 */ 	lw	$t7,-0x1b20($t7)
/*  f0be11c:	55e00007 */ 	bnezl	$t7,.PB0f0be13c
/*  f0be120:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0be124:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be128:	8e790038 */ 	lw	$t9,0x38($s3)
/*  f0be12c:	8d181b7c */ 	lw	$t8,0x1b7c($t0)
/*  f0be130:	03194821 */ 	addu	$t1,$t8,$t9
/*  f0be134:	ad091b7c */ 	sw	$t1,0x1b7c($t0)
.PB0f0be138:
/*  f0be138:	8e6a0284 */ 	lw	$t2,0x284($s3)
.PB0f0be13c:
/*  f0be13c:	8d4b00c4 */ 	lw	$t3,0xc4($t2)
/*  f0be140:	316c0020 */ 	andi	$t4,$t3,0x20
/*  f0be144:	11800004 */ 	beqz	$t4,.PB0f0be158
/*  f0be148:	00000000 */ 	nop
/*  f0be14c:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0be150:	0fc3061f */ 	jal	playerDieByShooter
/*  f0be154:	24050001 */ 	li	$a1,0x1
.PB0f0be158:
/*  f0be158:	0fc2ef19 */ 	jal	playerTickDamageAndHealth
/*  f0be15c:	00000000 */ 	nop
/*  f0be160:	0fc2f15c */ 	jal	playerTickExplode
/*  f0be164:	00000000 */ 	nop
/*  f0be168:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be16c:	8d020480 */ 	lw	$v0,0x480($t0)
/*  f0be170:	1040008c */ 	beqz	$v0,.PB0f0be3a4
/*  f0be174:	00000000 */ 	nop
/*  f0be178:	8e6d02ac */ 	lw	$t5,0x2ac($s3)
/*  f0be17c:	24010006 */ 	li	$at,0x6
/*  f0be180:	00408825 */ 	move	$s1,$v0
/*  f0be184:	15a10014 */ 	bne	$t5,$at,.PB0f0be1d8
/*  f0be188:	8e70028c */ 	lw	$s0,0x28c($s3)
/*  f0be18c:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0be190:	24050001 */ 	li	$a1,0x1
/*  f0be194:	3406ffff */ 	li	$a2,0xffff
/*  f0be198:	8c900004 */ 	lw	$s0,0x4($a0)
/*  f0be19c:	a2200035 */ 	sb	$zero,0x35($s1)
/*  f0be1a0:	a2350034 */ 	sb	$s5,0x34($s1)
/*  f0be1a4:	0fc24943 */ 	jal	func0f0926bc
/*  f0be1a8:	a2200037 */ 	sb	$zero,0x37($s1)
/*  f0be1ac:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0be1b0:	2401fffb */ 	li	$at,-5
/*  f0be1b4:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f0be1b8:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f0be1bc:	35f90010 */ 	ori	$t9,$t7,0x10
/*  f0be1c0:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0be1c4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be1c8:	8d0900c4 */ 	lw	$t1,0xc4($t0)
/*  f0be1cc:	01215024 */ 	and	$t2,$t1,$at
/*  f0be1d0:	10000074 */ 	b	.PB0f0be3a4
/*  f0be1d4:	ad0a00c4 */ 	sw	$t2,0xc4($t0)
.PB0f0be1d8:
/*  f0be1d8:	922b0034 */ 	lbu	$t3,0x34($s1)
/*  f0be1dc:	5560002c */ 	bnezl	$t3,.PB0f0be290
/*  f0be1e0:	8d0d1c54 */ 	lw	$t5,0x1c54($t0)
/*  f0be1e4:	804c0037 */ 	lb	$t4,0x37($v0)
/*  f0be1e8:	51800022 */ 	beqzl	$t4,.PB0f0be274
/*  f0be1ec:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f0be1f0:	8e6d0288 */ 	lw	$t5,0x288($s3)
/*  f0be1f4:	0fc54ebe */ 	jal	optionsGetContpadNum1
/*  f0be1f8:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0be1fc:	8faf0330 */ 	lw	$t7,0x330($sp)
/*  f0be200:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0be204:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0be208:	11e00005 */ 	beqz	$t7,.PB0f0be220
/*  f0be20c:	01c02025 */ 	move	$a0,$t6
/*  f0be210:	0c00566a */ 	jal	joyGetButtons
/*  f0be214:	3405ffff */ 	li	$a1,0xffff
/*  f0be218:	10000002 */ 	b	.PB0f0be224
/*  f0be21c:	3043ffff */ 	andi	$v1,$v0,0xffff
.PB0f0be220:
/*  f0be220:	00001825 */ 	move	$v1,$zero
.PB0f0be224:
/*  f0be224:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be228:	8d1800d8 */ 	lw	$t8,0xd8($t0)
/*  f0be22c:	57000011 */ 	bnezl	$t8,.PB0f0be274
/*  f0be230:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f0be234:	8d191a24 */ 	lw	$t9,0x1a24($t0)
/*  f0be238:	30691000 */ 	andi	$t1,$v1,0x1000
/*  f0be23c:	5720000d */ 	bnezl	$t9,.PB0f0be274
/*  f0be240:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f0be244:	5120000b */ 	beqzl	$t1,.PB0f0be274
/*  f0be248:	8e6b0034 */ 	lw	$t3,0x34($s3)
/*  f0be24c:	8e6a0314 */ 	lw	$t2,0x314($s3)
/*  f0be250:	15400005 */ 	bnez	$t2,.PB0f0be268
/*  f0be254:	00000000 */ 	nop
/*  f0be258:	0fc2ecd7 */ 	jal	playerPause
/*  f0be25c:	24040002 */ 	li	$a0,0x2
/*  f0be260:	10000004 */ 	b	.PB0f0be274
/*  f0be264:	8e6b0034 */ 	lw	$t3,0x34($s3)
.PB0f0be268:
/*  f0be268:	0fc5ea40 */ 	jal	mpPushPauseDialog
/*  f0be26c:	00000000 */ 	nop
/*  f0be270:	8e6b0034 */ 	lw	$t3,0x34($s3)
.PB0f0be274:
/*  f0be274:	5160001d */ 	beqzl	$t3,.PB0f0be2ec
/*  f0be278:	922d0035 */ 	lbu	$t5,0x35($s1)
/*  f0be27c:	0fc34372 */ 	jal	eyespyProcessInput
/*  f0be280:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0be284:	10000019 */ 	b	.PB0f0be2ec
/*  f0be288:	922d0035 */ 	lbu	$t5,0x35($s1)
/*  f0be28c:	8d0d1c54 */ 	lw	$t5,0x1c54($t0)
.PB0f0be290:
/*  f0be290:	8d0c00c4 */ 	lw	$t4,0xc4($t0)
/*  f0be294:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f0be298:	01a07027 */ 	nor	$t6,$t5,$zero
/*  f0be29c:	018e7824 */ 	and	$t7,$t4,$t6
/*  f0be2a0:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f0be2a4:	13000010 */ 	beqz	$t8,.PB0f0be2e8
/*  f0be2a8:	3c098007 */ 	lui	$t1,0x8007
/*  f0be2ac:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0be2b0:	8d292420 */ 	lw	$t1,0x2420($t1)
/*  f0be2b4:	5120000d */ 	beqzl	$t1,.PB0f0be2ec
/*  f0be2b8:	922d0035 */ 	lbu	$t5,0x35($s1)
/*  f0be2bc:	0fc341ec */ 	jal	eyespyTryLaunch
/*  f0be2c0:	00000000 */ 	nop
/*  f0be2c4:	54400009 */ 	bnezl	$v0,.PB0f0be2ec
/*  f0be2c8:	922d0035 */ 	lbu	$t5,0x35($s1)
/*  f0be2cc:	a2350034 */ 	sb	$s5,0x34($s1)
/*  f0be2d0:	a2200037 */ 	sb	$zero,0x37($s1)
/*  f0be2d4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be2d8:	2401fffb */ 	li	$at,-5
/*  f0be2dc:	8d0a00c4 */ 	lw	$t2,0xc4($t0)
/*  f0be2e0:	01415824 */ 	and	$t3,$t2,$at
/*  f0be2e4:	ad0b00c4 */ 	sw	$t3,0xc4($t0)
.PB0f0be2e8:
/*  f0be2e8:	922d0035 */ 	lbu	$t5,0x35($s1)
.PB0f0be2ec:
/*  f0be2ec:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0be2f0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0be2f4:	11a0002b */ 	beqz	$t5,.PB0f0be3a4
/*  f0be2f8:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f0be2fc:	8dce2420 */ 	lw	$t6,0x2420($t6)
/*  f0be300:	11c00028 */ 	beqz	$t6,.PB0f0be3a4
/*  f0be304:	00000000 */ 	nop
/*  f0be308:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be30c:	8d181c54 */ 	lw	$t8,0x1c54($t0)
/*  f0be310:	8d0f00c4 */ 	lw	$t7,0xc4($t0)
/*  f0be314:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f0be318:	01f94824 */ 	and	$t1,$t7,$t9
/*  f0be31c:	312a0004 */ 	andi	$t2,$t1,0x4
/*  f0be320:	11400020 */ 	beqz	$t2,.PB0f0be3a4
/*  f0be324:	00000000 */ 	nop
/*  f0be328:	822b0037 */ 	lb	$t3,0x37($s1)
/*  f0be32c:	240d0001 */ 	li	$t5,0x1
/*  f0be330:	240e0008 */ 	li	$t6,0x8
/*  f0be334:	15600019 */ 	bnez	$t3,.PB0f0be39c
/*  f0be338:	3c048009 */ 	lui	$a0,0x8009
/*  f0be33c:	a2200039 */ 	sb	$zero,0x39($s1)
/*  f0be340:	822c0039 */ 	lb	$t4,0x39($s1)
/*  f0be344:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0be348:	a22d0037 */ 	sb	$t5,0x37($s1)
/*  f0be34c:	a2200068 */ 	sb	$zero,0x68($s1)
/*  f0be350:	a2200036 */ 	sb	$zero,0x36($s1)
/*  f0be354:	a22c0038 */ 	sb	$t4,0x38($s1)
/*  f0be358:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f0be35c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0be360:	44814000 */ 	mtc1	$at,$f8
/*  f0be364:	adee0120 */ 	sw	$t6,0x120($t7)
/*  f0be368:	2419ffff */ 	li	$t9,-1
/*  f0be36c:	2409ffff */ 	li	$t1,-1
/*  f0be370:	240affff */ 	li	$t2,-1
/*  f0be374:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0be378:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0be37c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0be380:	8c847f30 */ 	lw	$a0,0x7f30($a0)
/*  f0be384:	240580ab */ 	li	$a1,-32597
/*  f0be388:	00003025 */ 	move	$a2,$zero
/*  f0be38c:	2407ffff */ 	li	$a3,-1
/*  f0be390:	0c004254 */ 	jal	sndStart
/*  f0be394:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0be398:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0be39c:
/*  f0be39c:	2410ffdf */ 	li	$s0,-33
/*  f0be3a0:	a510024c */ 	sh	$s0,0x24c($t0)
.PB0f0be3a4:
/*  f0be3a4:	0fc5b9b8 */ 	jal	lvIsPaused
/*  f0be3a8:	2410ffdf */ 	li	$s0,-33
/*  f0be3ac:	50400004 */ 	beqzl	$v0,.PB0f0be3c0
/*  f0be3b0:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be3b4:	0fc2ec4c */ 	jal	playerStopAudioForPause
/*  f0be3b8:	00000000 */ 	nop
/*  f0be3bc:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0be3c0:
/*  f0be3c0:	8d0b1a24 */ 	lw	$t3,0x1a24($t0)
/*  f0be3c4:	51600005 */ 	beqzl	$t3,.PB0f0be3dc
/*  f0be3c8:	950d0010 */ 	lhu	$t5,0x10($t0)
/*  f0be3cc:	0fc2ec6f */ 	jal	playerTickPauseMenu
/*  f0be3d0:	00000000 */ 	nop
/*  f0be3d4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be3d8:	950d0010 */ 	lhu	$t5,0x10($t0)
.PB0f0be3dc:
/*  f0be3dc:	24010002 */ 	li	$at,0x2
/*  f0be3e0:	55a1000c */ 	bnel	$t5,$at,.PB0f0be414
/*  f0be3e4:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0be3e8:	8d0c0264 */ 	lw	$t4,0x264($t0)
/*  f0be3ec:	51800005 */ 	beqzl	$t4,.PB0f0be404
/*  f0be3f0:	ad000264 */ 	sw	$zero,0x264($t0)
/*  f0be3f4:	8d1800d8 */ 	lw	$t8,0xd8($t0)
/*  f0be3f8:	53000006 */ 	beqzl	$t8,.PB0f0be414
/*  f0be3fc:	8e6302ac */ 	lw	$v1,0x2ac($s3)
/*  f0be400:	ad000264 */ 	sw	$zero,0x264($t0)
.PB0f0be404:
/*  f0be404:	8e6f0284 */ 	lw	$t7,0x284($s3)
/*  f0be408:	240e0003 */ 	li	$t6,0x3
/*  f0be40c:	a5ee0010 */ 	sh	$t6,0x10($t7)
/*  f0be410:	8e6302ac */ 	lw	$v1,0x2ac($s3)
.PB0f0be414:
/*  f0be414:	24010006 */ 	li	$at,0x6
/*  f0be418:	10610002 */ 	beq	$v1,$at,.PB0f0be424
/*  f0be41c:	3c018007 */ 	lui	$at,0x8007
/*  f0be420:	ac202434 */ 	sw	$zero,0x2434($at)
.PB0f0be424:
/*  f0be424:	24010006 */ 	li	$at,0x6
/*  f0be428:	54610054 */ 	bnel	$v1,$at,.PB0f0be57c
/*  f0be42c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be430:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0be434:	00000000 */ 	nop
/*  f0be438:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be43c:	00002025 */ 	move	$a0,$zero
/*  f0be440:	00002825 */ 	move	$a1,$zero
/*  f0be444:	8d1919c8 */ 	lw	$t9,0x19c8($t0)
/*  f0be448:	00003025 */ 	move	$a2,$zero
/*  f0be44c:	24070001 */ 	li	$a3,0x1
/*  f0be450:	53200008 */ 	beqzl	$t9,.PB0f0be474
/*  f0be454:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f0be458:	0fc3303a */ 	jal	bmoveTick
/*  f0be45c:	a510024c */ 	sh	$s0,0x24c($t0)
/*  f0be460:	0fc2e9b2 */ 	jal	playerTickCutscene
/*  f0be464:	8fa40330 */ 	lw	$a0,0x330($sp)
/*  f0be468:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0be46c:	a530024c */ 	sh	$s0,0x24c($t1)
/*  f0be470:	8e6a006c */ 	lw	$t2,0x6c($s3)
.PB0f0be474:
/*  f0be474:	00003025 */ 	move	$a2,$zero
/*  f0be478:	00003825 */ 	move	$a3,$zero
/*  f0be47c:	11400003 */ 	beqz	$t2,.PB0f0be48c
/*  f0be480:	00002825 */ 	move	$a1,$zero
/*  f0be484:	10000001 */ 	b	.PB0f0be48c
/*  f0be488:	24070001 */ 	li	$a3,0x1
.PB0f0be48c:
/*  f0be48c:	8e6b0068 */ 	lw	$t3,0x68($s3)
/*  f0be490:	00002025 */ 	move	$a0,$zero
/*  f0be494:	00001025 */ 	move	$v0,$zero
/*  f0be498:	11600003 */ 	beqz	$t3,.PB0f0be4a8
/*  f0be49c:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f0be4a0:	10000001 */ 	b	.PB0f0be4a8
/*  f0be4a4:	24050001 */ 	li	$a1,0x1
.PB0f0be4a8:
/*  f0be4a8:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f0be4ac:	02791821 */ 	addu	$v1,$s3,$t9
/*  f0be4b0:	2408ffff */ 	li	$t0,-1
/*  f0be4b4:	11a00003 */ 	beqz	$t5,.PB0f0be4c4
/*  f0be4b8:	00000000 */ 	nop
/*  f0be4bc:	10000001 */ 	b	.PB0f0be4c4
/*  f0be4c0:	24040001 */ 	li	$a0,0x1
.PB0f0be4c4:
/*  f0be4c4:	8e6c0070 */ 	lw	$t4,0x70($s3)
/*  f0be4c8:	11800003 */ 	beqz	$t4,.PB0f0be4d8
/*  f0be4cc:	00000000 */ 	nop
/*  f0be4d0:	10000001 */ 	b	.PB0f0be4d8
/*  f0be4d4:	24020001 */ 	li	$v0,0x1
.PB0f0be4d8:
/*  f0be4d8:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0be4dc:	03057021 */ 	addu	$t6,$t8,$a1
/*  f0be4e0:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f0be4e4:	19e0062a */ 	blez	$t7,.PB0f0bfd90
/*  f0be4e8:	00000000 */ 	nop
/*  f0be4ec:	8c690064 */ 	lw	$t1,0x64($v1)
.PB0f0be4f0:
/*  f0be4f0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0be4f4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0be4f8:	ad281c40 */ 	sw	$t0,0x1c40($t1)
/*  f0be4fc:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f0be500:	00003825 */ 	move	$a3,$zero
/*  f0be504:	00002825 */ 	move	$a1,$zero
/*  f0be508:	11400003 */ 	beqz	$t2,.PB0f0be518
/*  f0be50c:	00002025 */ 	move	$a0,$zero
/*  f0be510:	10000001 */ 	b	.PB0f0be518
/*  f0be514:	24070001 */ 	li	$a3,0x1
.PB0f0be518:
/*  f0be518:	8e6b0068 */ 	lw	$t3,0x68($s3)
/*  f0be51c:	00001025 */ 	move	$v0,$zero
/*  f0be520:	11600003 */ 	beqz	$t3,.PB0f0be530
/*  f0be524:	00000000 */ 	nop
/*  f0be528:	10000001 */ 	b	.PB0f0be530
/*  f0be52c:	24050001 */ 	li	$a1,0x1
.PB0f0be530:
/*  f0be530:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f0be534:	11a00003 */ 	beqz	$t5,.PB0f0be544
/*  f0be538:	00000000 */ 	nop
/*  f0be53c:	10000001 */ 	b	.PB0f0be544
/*  f0be540:	24040001 */ 	li	$a0,0x1
.PB0f0be544:
/*  f0be544:	8e6c0070 */ 	lw	$t4,0x70($s3)
/*  f0be548:	11800003 */ 	beqz	$t4,.PB0f0be558
/*  f0be54c:	00000000 */ 	nop
/*  f0be550:	10000001 */ 	b	.PB0f0be558
/*  f0be554:	24020001 */ 	li	$v0,0x1
.PB0f0be558:
/*  f0be558:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0be55c:	03057021 */ 	addu	$t6,$t8,$a1
/*  f0be560:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f0be564:	00cf082a */ 	slt	$at,$a2,$t7
/*  f0be568:	5420ffe1 */ 	bnezl	$at,.PB0f0be4f0
/*  f0be56c:	8c690064 */ 	lw	$t1,0x64($v1)
/*  f0be570:	10000607 */ 	b	.PB0f0bfd90
/*  f0be574:	00000000 */ 	nop
/*  f0be578:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0be57c:
/*  f0be57c:	8d020480 */ 	lw	$v0,0x480($t0)
/*  f0be580:	5040002f */ 	beqzl	$v0,.PB0f0be640
/*  f0be584:	910d1bfc */ 	lbu	$t5,0x1bfc($t0)
/*  f0be588:	8d091c54 */ 	lw	$t1,0x1c54($t0)
/*  f0be58c:	8d1900c4 */ 	lw	$t9,0xc4($t0)
/*  f0be590:	01205027 */ 	nor	$t2,$t1,$zero
/*  f0be594:	032a5824 */ 	and	$t3,$t9,$t2
/*  f0be598:	316d0004 */ 	andi	$t5,$t3,0x4
/*  f0be59c:	51a00028 */ 	beqzl	$t5,.PB0f0be640
/*  f0be5a0:	910d1bfc */ 	lbu	$t5,0x1bfc($t0)
/*  f0be5a4:	804c0037 */ 	lb	$t4,0x37($v0)
/*  f0be5a8:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0be5ac:	51800024 */ 	beqzl	$t4,.PB0f0be640
/*  f0be5b0:	910d1bfc */ 	lbu	$t5,0x1bfc($t0)
/*  f0be5b4:	4481a000 */ 	mtc1	$at,$f20
/*  f0be5b8:	0fc4a7ed */ 	jal	playermgrSetFovY
/*  f0be5bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f0be5c0:	0c002e97 */ 	jal	viSetFovY
/*  f0be5c4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0be5c8:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be5cc:	8d180480 */ 	lw	$t8,0x480($t0)
/*  f0be5d0:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f0be5d4:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f0be5d8:	e7aa0308 */ 	swc1	$f10,0x308($sp)
/*  f0be5dc:	8d0f0480 */ 	lw	$t7,0x480($t0)
/*  f0be5e0:	8de90000 */ 	lw	$t1,0x0($t7)
/*  f0be5e4:	c532000c */ 	lwc1	$f18,0xc($t1)
/*  f0be5e8:	e7b2030c */ 	swc1	$f18,0x30c($sp)
/*  f0be5ec:	8d190480 */ 	lw	$t9,0x480($t0)
/*  f0be5f0:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*  f0be5f4:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*  f0be5f8:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0be5fc:	e7a40310 */ 	swc1	$f4,0x310($sp)
/*  f0be600:	00002025 */ 	move	$a0,$zero
/*  f0be604:	00002825 */ 	move	$a1,$zero
/*  f0be608:	00003025 */ 	move	$a2,$zero
/*  f0be60c:	0fc3303a */ 	jal	bmoveTick
/*  f0be610:	24070001 */ 	li	$a3,0x1
/*  f0be614:	0fc3072a */ 	jal	playerSetCameraMode
/*  f0be618:	24040002 */ 	li	$a0,0x2
/*  f0be61c:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0be620:	27a40308 */ 	addiu	$a0,$sp,0x308
/*  f0be624:	8d620480 */ 	lw	$v0,0x480($t3)
/*  f0be628:	24450010 */ 	addiu	$a1,$v0,0x10
/*  f0be62c:	0fc30814 */ 	jal	player0f0c1bd8
/*  f0be630:	24460004 */ 	addiu	$a2,$v0,0x4
/*  f0be634:	100005d6 */ 	b	.PB0f0bfd90
/*  f0be638:	00000000 */ 	nop
/*  f0be63c:	910d1bfc */ 	lbu	$t5,0x1bfc($t0)
.PB0f0be640:
/*  f0be640:	24020003 */ 	li	$v0,0x3
/*  f0be644:	544d0011 */ 	bnel	$v0,$t5,.PB0f0be68c
/*  f0be648:	950e0010 */ 	lhu	$t6,0x10($t0)
/*  f0be64c:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0be650:	00000000 */ 	nop
/*  f0be654:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0be658:	3c01800a */ 	lui	$at,0x800a
/*  f0be65c:	00002025 */ 	move	$a0,$zero
/*  f0be660:	95981c00 */ 	lhu	$t8,0x1c00($t4)
/*  f0be664:	00002825 */ 	move	$a1,$zero
/*  f0be668:	00003025 */ 	move	$a2,$zero
/*  f0be66c:	24070001 */ 	li	$a3,0x1
/*  f0be670:	0fc3303a */ 	jal	bmoveTick
/*  f0be674:	a4382318 */ 	sh	$t8,0x2318($at)
/*  f0be678:	0fc2e833 */ 	jal	playerExecutePreparedWarp
/*  f0be67c:	00000000 */ 	nop
/*  f0be680:	100005c3 */ 	b	.PB0f0bfd90
/*  f0be684:	00000000 */ 	nop
/*  f0be688:	950e0010 */ 	lhu	$t6,0x10($t0)
.PB0f0be68c:
/*  f0be68c:	24010002 */ 	li	$at,0x2
/*  f0be690:	27af02fc */ 	addiu	$t7,$sp,0x2fc
/*  f0be694:	15c10241 */ 	bne	$t6,$at,.PB0f0bef9c
/*  f0be698:	3c098007 */ 	lui	$t1,0x8007
/*  f0be69c:	252926a0 */ 	addiu	$t1,$t1,0x26a0
/*  f0be6a0:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0be6a4:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f0be6a8:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0be6ac:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0be6b0:	8d210008 */ 	lw	$at,0x8($t1)
/*  f0be6b4:	25ad26ac */ 	addiu	$t5,$t5,0x26ac
/*  f0be6b8:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f0be6bc:	ade10008 */ 	sw	$at,0x8($t7)
/*  f0be6c0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0be6c4:	27ab02f0 */ 	addiu	$t3,$sp,0x2f0
/*  f0be6c8:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f0be6cc:	ad610000 */ 	sw	$at,0x0($t3)
/*  f0be6d0:	8da10008 */ 	lw	$at,0x8($t5)
/*  f0be6d4:	3c198007 */ 	lui	$t9,0x8007
/*  f0be6d8:	273926b8 */ 	addiu	$t9,$t9,0x26b8
/*  f0be6dc:	ad780004 */ 	sw	$t8,0x4($t3)
/*  f0be6e0:	ad610008 */ 	sw	$at,0x8($t3)
/*  f0be6e4:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0be6e8:	27ae02e4 */ 	addiu	$t6,$sp,0x2e4
/*  f0be6ec:	8f290004 */ 	lw	$t1,0x4($t9)
/*  f0be6f0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0be6f4:	8f210008 */ 	lw	$at,0x8($t9)
/*  f0be6f8:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0be6fc:	24040001 */ 	li	$a0,0x1
/*  f0be700:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0be704:	afa002e0 */ 	sw	$zero,0x2e0($sp)
/*  f0be708:	0fc3072a */ 	jal	playerSetCameraMode
/*  f0be70c:	8d110264 */ 	lw	$s1,0x264($t0)
/*  f0be710:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0be714:	00000000 */ 	nop
/*  f0be718:	00002025 */ 	move	$a0,$zero
/*  f0be71c:	00002825 */ 	move	$a1,$zero
/*  f0be720:	00003025 */ 	move	$a2,$zero
/*  f0be724:	0fc3303a */ 	jal	bmoveTick
/*  f0be728:	24070001 */ 	li	$a3,0x1
/*  f0be72c:	0fc2f60c */ 	jal	playerUpdateShake
/*  f0be730:	00000000 */ 	nop
/*  f0be734:	522001fc */ 	beqzl	$s1,.PB0f0bef28
/*  f0be738:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0be73c:	8e2a0014 */ 	lw	$t2,0x14($s1)
/*  f0be740:	514001f9 */ 	beqzl	$t2,.PB0f0bef28
/*  f0be744:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0be748:	c622001c */ 	lwc1	$f2,0x1c($s1)
/*  f0be74c:	c62e0028 */ 	lwc1	$f14,0x28($s1)
/*  f0be750:	c6200034 */ 	lwc1	$f0,0x34($s1)
/*  f0be754:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0be758:	00000000 */ 	nop
/*  f0be75c:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0be760:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0be764:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0be768:	0c012ae4 */ 	jal	sqrtf
/*  f0be76c:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0be770:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f0be774:	c624001c */ 	lwc1	$f4,0x1c($s1)
/*  f0be778:	27b8024e */ 	addiu	$t8,$sp,0x24e
/*  f0be77c:	00008025 */ 	move	$s0,$zero
/*  f0be780:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0be784:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0be788:	27a5027c */ 	addiu	$a1,$sp,0x27c
/*  f0be78c:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f0be790:	24070014 */ 	li	$a3,0x14
/*  f0be794:	e7a602b8 */ 	swc1	$f6,0x2b8($sp)
/*  f0be798:	c6280020 */ 	lwc1	$f8,0x20($s1)
/*  f0be79c:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0be7a0:	e7b202bc */ 	swc1	$f18,0x2bc($sp)
/*  f0be7a4:	c62a0024 */ 	lwc1	$f10,0x24($s1)
/*  f0be7a8:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0be7ac:	e7a402c0 */ 	swc1	$f4,0x2c0($sp)
/*  f0be7b0:	c6260028 */ 	lwc1	$f6,0x28($s1)
/*  f0be7b4:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0be7b8:	e7a802c4 */ 	swc1	$f8,0x2c4($sp)
/*  f0be7bc:	c632002c */ 	lwc1	$f18,0x2c($s1)
/*  f0be7c0:	46009283 */ 	div.s	$f10,$f18,$f0
/*  f0be7c4:	e7aa02c8 */ 	swc1	$f10,0x2c8($sp)
/*  f0be7c8:	c6240030 */ 	lwc1	$f4,0x30($s1)
/*  f0be7cc:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f0be7d0:	e7a602cc */ 	swc1	$f6,0x2cc($sp)
/*  f0be7d4:	c6280034 */ 	lwc1	$f8,0x34($s1)
/*  f0be7d8:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f0be7dc:	e7b202d0 */ 	swc1	$f18,0x2d0($sp)
/*  f0be7e0:	c62a0038 */ 	lwc1	$f10,0x38($s1)
/*  f0be7e4:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0be7e8:	e7a402d4 */ 	swc1	$f4,0x2d4($sp)
/*  f0be7ec:	c626003c */ 	lwc1	$f6,0x3c($s1)
/*  f0be7f0:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0be7f4:	e7a802d8 */ 	swc1	$f8,0x2d8($sp)
/*  f0be7f8:	8e2c0014 */ 	lw	$t4,0x14($s1)
/*  f0be7fc:	c5920008 */ 	lwc1	$f18,0x8($t4)
/*  f0be800:	e7b202fc */ 	swc1	$f18,0x2fc($sp)
/*  f0be804:	8e2b0014 */ 	lw	$t3,0x14($s1)
/*  f0be808:	c56a000c */ 	lwc1	$f10,0xc($t3)
/*  f0be80c:	e7aa0300 */ 	swc1	$f10,0x300($sp)
/*  f0be810:	8e2d0014 */ 	lw	$t5,0x14($s1)
/*  f0be814:	c5a40010 */ 	lwc1	$f4,0x10($t5)
/*  f0be818:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0be81c:	0fc58e01 */ 	jal	func0f162194
/*  f0be820:	e7a40304 */ 	swc1	$f4,0x304($sp)
/*  f0be824:	87af027c */ 	lh	$t7,0x27c($sp)
/*  f0be828:	2401ffff */ 	li	$at,-1
/*  f0be82c:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0be830:	15e10002 */ 	bne	$t7,$at,.PB0f0be83c
/*  f0be834:	00000000 */ 	nop
/*  f0be838:	24100001 */ 	li	$s0,0x1
.PB0f0be83c:
/*  f0be83c:	5200000f */ 	beqzl	$s0,.PB0f0be87c
/*  f0be840:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be844:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be848:	8e790038 */ 	lw	$t9,0x38($s3)
/*  f0be84c:	240c0003 */ 	li	$t4,0x3
/*  f0be850:	8d0e00c8 */ 	lw	$t6,0xc8($t0)
/*  f0be854:	01d94821 */ 	addu	$t1,$t6,$t9
/*  f0be858:	ad0900c8 */ 	sw	$t1,0xc8($t0)
/*  f0be85c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be860:	8d0a00c8 */ 	lw	$t2,0xc8($t0)
/*  f0be864:	29410065 */ 	slti	$at,$t2,0x65
/*  f0be868:	1420000f */ 	bnez	$at,.PB0f0be8a8
/*  f0be86c:	00000000 */ 	nop
/*  f0be870:	1000000d */ 	b	.PB0f0be8a8
/*  f0be874:	a50c0010 */ 	sh	$t4,0x10($t0)
/*  f0be878:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0be87c:
/*  f0be87c:	8d0200c8 */ 	lw	$v0,0xc8($t0)
/*  f0be880:	18400009 */ 	blez	$v0,.PB0f0be8a8
/*  f0be884:	00000000 */ 	nop
/*  f0be888:	8e6b0038 */ 	lw	$t3,0x38($s3)
/*  f0be88c:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f0be890:	ad0d00c8 */ 	sw	$t5,0xc8($t0)
/*  f0be894:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0be898:	8d1800c8 */ 	lw	$t8,0xc8($t0)
/*  f0be89c:	07010002 */ 	bgez	$t8,.PB0f0be8a8
/*  f0be8a0:	00000000 */ 	nop
/*  f0be8a4:	ad0000c8 */ 	sw	$zero,0xc8($t0)
.PB0f0be8a8:
/*  f0be8a8:	0c005b16 */ 	jal	mtx00016208
/*  f0be8ac:	27a502f0 */ 	addiu	$a1,$sp,0x2f0
/*  f0be8b0:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0be8b4:	0c005b16 */ 	jal	mtx00016208
/*  f0be8b8:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0be8bc:	8e2f0040 */ 	lw	$t7,0x40($s1)
/*  f0be8c0:	31ee0080 */ 	andi	$t6,$t7,0x80
/*  f0be8c4:	51c00198 */ 	beqzl	$t6,.PB0f0bef28
/*  f0be8c8:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
/*  f0be8cc:	8e790288 */ 	lw	$t9,0x288($s3)
/*  f0be8d0:	8e340048 */ 	lw	$s4,0x48($s1)
/*  f0be8d4:	0fc54eb0 */ 	jal	optionsGetControlMode
/*  f0be8d8:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f0be8dc:	8e690288 */ 	lw	$t1,0x288($s3)
/*  f0be8e0:	00408025 */ 	move	$s0,$v0
/*  f0be8e4:	0fc54ebe */ 	jal	optionsGetContpadNum1
/*  f0be8e8:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0be8ec:	8e6c0288 */ 	lw	$t4,0x288($s3)
/*  f0be8f0:	00029600 */ 	sll	$s2,$v0,0x18
/*  f0be8f4:	00125603 */ 	sra	$t2,$s2,0x18
/*  f0be8f8:	01409025 */ 	move	$s2,$t2
/*  f0be8fc:	0fc54ec5 */ 	jal	optionsGetContpadNum2
/*  f0be900:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0be904:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0be908:	00155e03 */ 	sra	$t3,$s5,0x18
/*  f0be90c:	24010006 */ 	li	$at,0x6
/*  f0be910:	0160a825 */ 	move	$s5,$t3
/*  f0be914:	a3a0023d */ 	sb	$zero,0x23d($sp)
/*  f0be918:	a3a0023c */ 	sb	$zero,0x23c($sp)
/*  f0be91c:	afa00118 */ 	sw	$zero,0x118($sp)
/*  f0be920:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0be924:	12010008 */ 	beq	$s0,$at,.PB0f0be948
/*  f0be928:	afa00110 */ 	sw	$zero,0x110($sp)
/*  f0be92c:	24010007 */ 	li	$at,0x7
/*  f0be930:	12010005 */ 	beq	$s0,$at,.PB0f0be948
/*  f0be934:	24010005 */ 	li	$at,0x5
/*  f0be938:	12010003 */ 	beq	$s0,$at,.PB0f0be948
/*  f0be93c:	24010004 */ 	li	$at,0x4
/*  f0be940:	56010062 */ 	bnel	$s0,$at,.PB0f0beacc
/*  f0be944:	8e6e028c */ 	lw	$t6,0x28c($s3)
.PB0f0be948:
/*  f0be948:	8e6d028c */ 	lw	$t5,0x28c($s3)
/*  f0be94c:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0be950:	24010004 */ 	li	$at,0x4
/*  f0be954:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f0be958:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f0be95c:	8def2420 */ 	lw	$t7,0x2420($t7)
/*  f0be960:	240b0001 */ 	li	$t3,0x1
/*  f0be964:	51e00049 */ 	beqzl	$t7,.PB0f0bea8c
/*  f0be968:	afab0114 */ 	sw	$t3,0x114($sp)
/*  f0be96c:	12010004 */ 	beq	$s0,$at,.PB0f0be980
/*  f0be970:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be974:	24010005 */ 	li	$at,0x5
/*  f0be978:	1601001d */ 	bne	$s0,$at,.PB0f0be9f0
/*  f0be97c:	3405c000 */ 	li	$a1,0xc000
.PB0f0be980:
/*  f0be980:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0be984:	01c02025 */ 	move	$a0,$t6
/*  f0be988:	0c00566a */ 	jal	joyGetButtons
/*  f0be98c:	3405c000 */ 	li	$a1,0xc000
/*  f0be990:	1440000c */ 	bnez	$v0,.PB0f0be9c4
/*  f0be994:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be998:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0be99c:	03202025 */ 	move	$a0,$t9
/*  f0be9a0:	0c00566a */ 	jal	joyGetButtons
/*  f0be9a4:	3405c000 */ 	li	$a1,0xc000
/*  f0be9a8:	14400006 */ 	bnez	$v0,.PB0f0be9c4
/*  f0be9ac:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0be9b0:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0be9b4:	01202025 */ 	move	$a0,$t1
/*  f0be9b8:	0c00566a */ 	jal	joyGetButtons
/*  f0be9bc:	24052000 */ 	li	$a1,0x2000
/*  f0be9c0:	10400002 */ 	beqz	$v0,.PB0f0be9cc
.PB0f0be9c4:
/*  f0be9c4:	240a0001 */ 	li	$t2,0x1
/*  f0be9c8:	afaa0114 */ 	sw	$t2,0x114($sp)
.PB0f0be9cc:
/*  f0be9cc:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be9d0:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0be9d4:	01802025 */ 	move	$a0,$t4
/*  f0be9d8:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0be9dc:	24052000 */ 	li	$a1,0x2000
/*  f0be9e0:	1040001e */ 	beqz	$v0,.PB0f0bea5c
/*  f0be9e4:	240b0001 */ 	li	$t3,0x1
/*  f0be9e8:	1000001c */ 	b	.PB0f0bea5c
/*  f0be9ec:	afab0118 */ 	sw	$t3,0x118($sp)
.PB0f0be9f0:
/*  f0be9f0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0be9f4:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0be9f8:	0c00566a */ 	jal	joyGetButtons
/*  f0be9fc:	01a02025 */ 	move	$a0,$t5
/*  f0bea00:	1440000c */ 	bnez	$v0,.PB0f0bea34
/*  f0bea04:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bea08:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0bea0c:	03002025 */ 	move	$a0,$t8
/*  f0bea10:	0c00566a */ 	jal	joyGetButtons
/*  f0bea14:	3405c000 */ 	li	$a1,0xc000
/*  f0bea18:	14400006 */ 	bnez	$v0,.PB0f0bea34
/*  f0bea1c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bea20:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0bea24:	01e02025 */ 	move	$a0,$t7
/*  f0bea28:	0c00566a */ 	jal	joyGetButtons
/*  f0bea2c:	24052000 */ 	li	$a1,0x2000
/*  f0bea30:	10400002 */ 	beqz	$v0,.PB0f0bea3c
.PB0f0bea34:
/*  f0bea34:	240e0001 */ 	li	$t6,0x1
/*  f0bea38:	afae0114 */ 	sw	$t6,0x114($sp)
.PB0f0bea3c:
/*  f0bea3c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0bea40:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0bea44:	03202025 */ 	move	$a0,$t9
/*  f0bea48:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0bea4c:	24052000 */ 	li	$a1,0x2000
/*  f0bea50:	10400002 */ 	beqz	$v0,.PB0f0bea5c
/*  f0bea54:	24090001 */ 	li	$t1,0x1
/*  f0bea58:	afa90118 */ 	sw	$t1,0x118($sp)
.PB0f0bea5c:
/*  f0bea5c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bea60:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0bea64:	0c005616 */ 	jal	joyGetStickX
/*  f0bea68:	01402025 */ 	move	$a0,$t2
/*  f0bea6c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bea70:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0bea74:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0bea78:	0c005640 */ 	jal	joyGetStickY
/*  f0bea7c:	01802025 */ 	move	$a0,$t4
/*  f0bea80:	10000002 */ 	b	.PB0f0bea8c
/*  f0bea84:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0bea88:	afab0114 */ 	sw	$t3,0x114($sp)
.PB0f0bea8c:
/*  f0bea8c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bea90:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f0bea94:	01a02025 */ 	move	$a0,$t5
/*  f0bea98:	0c00566a */ 	jal	joyGetButtons
/*  f0bea9c:	24051000 */ 	li	$a1,0x1000
/*  f0beaa0:	14400006 */ 	bnez	$v0,.PB0f0beabc
/*  f0beaa4:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0beaa8:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0beaac:	03002025 */ 	move	$a0,$t8
/*  f0beab0:	0c00566a */ 	jal	joyGetButtons
/*  f0beab4:	24051000 */ 	li	$a1,0x1000
/*  f0beab8:	10400044 */ 	beqz	$v0,.PB0f0bebcc
.PB0f0beabc:
/*  f0beabc:	240f0001 */ 	li	$t7,0x1
/*  f0beac0:	10000042 */ 	b	.PB0f0bebcc
/*  f0beac4:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f0beac8:	8e6e028c */ 	lw	$t6,0x28c($s3)
.PB0f0beacc:
/*  f0beacc:	3c098007 */ 	lui	$t1,0x8007
/*  f0bead0:	24010002 */ 	li	$at,0x2
/*  f0bead4:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0bead8:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0beadc:	8d292420 */ 	lw	$t1,0x2420($t1)
/*  f0beae0:	240c0001 */ 	li	$t4,0x1
/*  f0beae4:	51200031 */ 	beqzl	$t1,.PB0f0bebac
/*  f0beae8:	afac0114 */ 	sw	$t4,0x114($sp)
/*  f0beaec:	12010004 */ 	beq	$s0,$at,.PB0f0beb00
/*  f0beaf0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beaf4:	24010003 */ 	li	$at,0x3
/*  f0beaf8:	16010011 */ 	bne	$s0,$at,.PB0f0beb40
/*  f0beafc:	24052000 */ 	li	$a1,0x2000
.PB0f0beb00:
/*  f0beb00:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0beb04:	01402025 */ 	move	$a0,$t2
/*  f0beb08:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0beb0c:	34058000 */ 	li	$a1,0x8000
/*  f0beb10:	10400003 */ 	beqz	$v0,.PB0f0beb20
/*  f0beb14:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beb18:	240c0001 */ 	li	$t4,0x1
/*  f0beb1c:	afac0118 */ 	sw	$t4,0x118($sp)
.PB0f0beb20:
/*  f0beb20:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0beb24:	01602025 */ 	move	$a0,$t3
/*  f0beb28:	0c00566a */ 	jal	joyGetButtons
/*  f0beb2c:	24056030 */ 	li	$a1,0x6030
/*  f0beb30:	10400012 */ 	beqz	$v0,.PB0f0beb7c
/*  f0beb34:	240d0001 */ 	li	$t5,0x1
/*  f0beb38:	10000010 */ 	b	.PB0f0beb7c
/*  f0beb3c:	afad0114 */ 	sw	$t5,0x114($sp)
.PB0f0beb40:
/*  f0beb40:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beb44:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0beb48:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0beb4c:	03002025 */ 	move	$a0,$t8
/*  f0beb50:	10400003 */ 	beqz	$v0,.PB0f0beb60
/*  f0beb54:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beb58:	240f0001 */ 	li	$t7,0x1
/*  f0beb5c:	afaf0118 */ 	sw	$t7,0x118($sp)
.PB0f0beb60:
/*  f0beb60:	00047603 */ 	sra	$t6,$a0,0x18
/*  f0beb64:	01c02025 */ 	move	$a0,$t6
/*  f0beb68:	0c00566a */ 	jal	joyGetButtons
/*  f0beb6c:	3405c030 */ 	li	$a1,0xc030
/*  f0beb70:	10400002 */ 	beqz	$v0,.PB0f0beb7c
/*  f0beb74:	24190001 */ 	li	$t9,0x1
/*  f0beb78:	afb90114 */ 	sw	$t9,0x114($sp)
.PB0f0beb7c:
/*  f0beb7c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beb80:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0beb84:	0c005616 */ 	jal	joyGetStickX
/*  f0beb88:	01202025 */ 	move	$a0,$t1
/*  f0beb8c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0beb90:	00045603 */ 	sra	$t2,$a0,0x18
/*  f0beb94:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f0beb98:	0c005640 */ 	jal	joyGetStickY
/*  f0beb9c:	01402025 */ 	move	$a0,$t2
/*  f0beba0:	10000002 */ 	b	.PB0f0bebac
/*  f0beba4:	a3a2023c */ 	sb	$v0,0x23c($sp)
/*  f0beba8:	afac0114 */ 	sw	$t4,0x114($sp)
.PB0f0bebac:
/*  f0bebac:	00122600 */ 	sll	$a0,$s2,0x18
/*  f0bebb0:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0bebb4:	01602025 */ 	move	$a0,$t3
/*  f0bebb8:	0c00566a */ 	jal	joyGetButtons
/*  f0bebbc:	24051000 */ 	li	$a1,0x1000
/*  f0bebc0:	10400002 */ 	beqz	$v0,.PB0f0bebcc
/*  f0bebc4:	240d0001 */ 	li	$t5,0x1
/*  f0bebc8:	afad0110 */ 	sw	$t5,0x110($sp)
.PB0f0bebcc:
/*  f0bebcc:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0bebd0:	5300000b */ 	beqzl	$t8,.PB0f0bec00
/*  f0bebd4:	83b9023c */ 	lb	$t9,0x23c($sp)
/*  f0bebd8:	8e6f0314 */ 	lw	$t7,0x314($s3)
/*  f0bebdc:	15e00005 */ 	bnez	$t7,.PB0f0bebf4
/*  f0bebe0:	00000000 */ 	nop
/*  f0bebe4:	0fc2ecd7 */ 	jal	playerPause
/*  f0bebe8:	24040002 */ 	li	$a0,0x2
/*  f0bebec:	10000004 */ 	b	.PB0f0bec00
/*  f0bebf0:	83b9023c */ 	lb	$t9,0x23c($sp)
.PB0f0bebf4:
/*  f0bebf4:	0fc5ea40 */ 	jal	mpPushPauseDialog
/*  f0bebf8:	00000000 */ 	nop
/*  f0bebfc:	83b9023c */ 	lb	$t9,0x23c($sp)
.PB0f0bec00:
/*  f0bec00:	c660004c */ 	lwc1	$f0,0x4c($s3)
/*  f0bec04:	83a9023d */ 	lb	$t1,0x23d($sp)
/*  f0bec08:	44993000 */ 	mtc1	$t9,$f6
/*  f0bec0c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bec10:	00095023 */ 	negu	$t2,$t1
/*  f0bec14:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0bec18:	448a5000 */ 	mtc1	$t2,$f10
/*  f0bec1c:	c430f398 */ 	lwc1	$f16,-0xc68($at)
/*  f0bec20:	c7ae02c0 */ 	lwc1	$f14,0x2c0($sp)
/*  f0bec24:	c7a202b8 */ 	lwc1	$f2,0x2b8($sp)
/*  f0bec28:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0bec2c:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0bec30:	240e0001 */ 	li	$t6,0x1
/*  f0bec34:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f0bec38:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0bec3c:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0bec40:	46109582 */ 	mul.s	$f22,$f18,$f16
/*  f0bec44:	00000000 */ 	nop
/*  f0bec48:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bec4c:	00000000 */ 	nop
/*  f0bec50:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0bec54:	00000000 */ 	nop
/*  f0bec58:	460e7482 */ 	mul.s	$f18,$f14,$f14
/*  f0bec5c:	00000000 */ 	nop
/*  f0bec60:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0bec64:	e7a80174 */ 	swc1	$f8,0x174($sp)
/*  f0bec68:	0c012ae4 */ 	jal	sqrtf
/*  f0bec6c:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0bec70:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0bec74:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0bec78:	4600b306 */ 	mov.s	$f12,$f22
/*  f0bec7c:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0bec80:	46007383 */ 	div.s	$f14,$f14,$f0
/*  f0bec84:	e7a202ac */ 	swc1	$f2,0x2ac($sp)
/*  f0bec88:	0c006b8b */ 	jal	sinf
/*  f0bec8c:	e7ae02b4 */ 	swc1	$f14,0x2b4($sp)
/*  f0bec90:	46000506 */ 	mov.s	$f20,$f0
/*  f0bec94:	0c006b88 */ 	jal	cosf
/*  f0bec98:	4600b306 */ 	mov.s	$f12,$f22
/*  f0bec9c:	c7a202ac */ 	lwc1	$f2,0x2ac($sp)
/*  f0beca0:	c7ae02b4 */ 	lwc1	$f14,0x2b4($sp)
/*  f0beca4:	44803000 */ 	mtc1	$zero,$f6
/*  f0beca8:	46141102 */ 	mul.s	$f4,$f2,$f20
/*  f0becac:	e7a0014c */ 	swc1	$f0,0x14c($sp)
/*  f0becb0:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0becb4:	46147202 */ 	mul.s	$f8,$f14,$f20
/*  f0becb8:	e7a60154 */ 	swc1	$f6,0x154($sp)
/*  f0becbc:	e7a40150 */ 	swc1	$f4,0x150($sp)
/*  f0becc0:	0c006b8b */ 	jal	sinf
/*  f0becc4:	e7a80158 */ 	swc1	$f8,0x158($sp)
/*  f0becc8:	46000506 */ 	mov.s	$f20,$f0
/*  f0beccc:	0c006b88 */ 	jal	cosf
/*  f0becd0:	c7ac0174 */ 	lwc1	$f12,0x174($sp)
/*  f0becd4:	44801000 */ 	mtc1	$zero,$f2
/*  f0becd8:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0becdc:	27b5013c */ 	addiu	$s5,$sp,0x13c
/*  f0bece0:	e7a0015c */ 	swc1	$f0,0x15c($sp)
/*  f0bece4:	4612103e */ 	c.le.s	$f2,$f18
/*  f0bece8:	02a03025 */ 	move	$a2,$s5
/*  f0becec:	27a4015c */ 	addiu	$a0,$sp,0x15c
/*  f0becf0:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f0becf4:	45000003 */ 	bc1f	.PB0f0bed04
/*  f0becf8:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f0becfc:	10000003 */ 	b	.PB0f0bed0c
/*  f0bed00:	e7b40164 */ 	swc1	$f20,0x164($sp)
.PB0f0bed04:
/*  f0bed04:	4600a287 */ 	neg.s	$f10,$f20
/*  f0bed08:	e7aa0164 */ 	swc1	$f10,0x164($sp)
.PB0f0bed0c:
/*  f0bed0c:	0fc25d6a */ 	jal	quaternionMultQuaternion
/*  f0bed10:	e7a20168 */ 	swc1	$f2,0x168($sp)
/*  f0bed14:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f0bed18:	02002825 */ 	move	$a1,$s0
/*  f0bed1c:	0fc25b51 */ 	jal	quaternionToMtx
/*  f0bed20:	02a02025 */ 	move	$a0,$s5
/*  f0bed24:	02002025 */ 	move	$a0,$s0
/*  f0bed28:	0c005958 */ 	jal	mtx4RotateVecInPlace
/*  f0bed2c:	26850004 */ 	addiu	$a1,$s4,0x4
/*  f0bed30:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f0bed34:	44808000 */ 	mtc1	$zero,$f16
/*  f0bed38:	240cffff */ 	li	$t4,-1
/*  f0bed3c:	356d4000 */ 	ori	$t5,$t3,0x4000
/*  f0bed40:	31af0080 */ 	andi	$t7,$t5,0x80
/*  f0bed44:	a68c00b2 */ 	sh	$t4,0xb2($s4)
/*  f0bed48:	ae8d0000 */ 	sw	$t5,0x0($s4)
/*  f0bed4c:	e6900018 */ 	swc1	$f16,0x18($s4)
/*  f0bed50:	e6900014 */ 	swc1	$f16,0x14($s4)
/*  f0bed54:	15e00002 */ 	bnez	$t7,.PB0f0bed60
/*  f0bed58:	e6900010 */ 	swc1	$f16,0x10($s4)
/*  f0bed5c:	ae800088 */ 	sw	$zero,0x88($s4)
.PB0f0bed60:
/*  f0bed60:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0bed64:	51c00003 */ 	beqzl	$t6,.PB0f0bed74
/*  f0bed68:	c6820004 */ 	lwc1	$f2,0x4($s4)
/*  f0bed6c:	a6200062 */ 	sh	$zero,0x62($s1)
/*  f0bed70:	c6820004 */ 	lwc1	$f2,0x4($s4)
.PB0f0bed74:
/*  f0bed74:	c68e0008 */ 	lwc1	$f14,0x8($s4)
/*  f0bed78:	c680000c */ 	lwc1	$f0,0xc($s4)
/*  f0bed7c:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0bed80:	00000000 */ 	nop
/*  f0bed84:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0bed88:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0bed8c:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0bed90:	0c012ae4 */ 	jal	sqrtf
/*  f0bed94:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f0bed98:	8fb90114 */ 	lw	$t9,0x114($sp)
/*  f0bed9c:	46000386 */ 	mov.s	$f14,$f0
/*  f0beda0:	3c014140 */ 	lui	$at,0x4140
/*  f0beda4:	53200006 */ 	beqzl	$t9,.PB0f0bedc0
/*  f0beda8:	44816000 */ 	mtc1	$at,$f12
/*  f0bedac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bedb0:	44816000 */ 	mtc1	$at,$f12
/*  f0bedb4:	10000004 */ 	b	.PB0f0bedc8
/*  f0bedb8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0bedbc:	44816000 */ 	mtc1	$at,$f12
.PB0f0bedc0:
/*  f0bedc0:	00000000 */ 	nop
/*  f0bedc4:	460c003c */ 	c.lt.s	$f0,$f12
.PB0f0bedc8:
/*  f0bedc8:	46000086 */ 	mov.s	$f2,$f0
/*  f0bedcc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bedd0:	4502000c */ 	bc1fl	.PB0f0bee04
/*  f0bedd4:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0bedd8:	c42af39c */ 	lwc1	$f10,-0xc64($at)
/*  f0beddc:	c664004c */ 	lwc1	$f4,0x4c($s3)
/*  f0bede0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0bede4:	46003080 */ 	add.s	$f2,$f6,$f0
/*  f0bede8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0bedec:	00000000 */ 	nop
/*  f0bedf0:	45020011 */ 	bc1fl	.PB0f0bee38
/*  f0bedf4:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bedf8:	1000000e */ 	b	.PB0f0bee34
/*  f0bedfc:	46006086 */ 	mov.s	$f2,$f12
/*  f0bee00:	4600603c */ 	c.lt.s	$f12,$f0
.PB0f0bee04:
/*  f0bee04:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bee08:	4502000b */ 	bc1fl	.PB0f0bee38
/*  f0bee0c:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bee10:	c432f3a0 */ 	lwc1	$f18,-0xc60($at)
/*  f0bee14:	c668004c */ 	lwc1	$f8,0x4c($s3)
/*  f0bee18:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f0bee1c:	460a0081 */ 	sub.s	$f2,$f0,$f10
/*  f0bee20:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0bee24:	00000000 */ 	nop
/*  f0bee28:	45020003 */ 	bc1fl	.PB0f0bee38
/*  f0bee2c:	c6840004 */ 	lwc1	$f4,0x4($s4)
/*  f0bee30:	46006086 */ 	mov.s	$f2,$f12
.PB0f0bee34:
/*  f0bee34:	c6840004 */ 	lwc1	$f4,0x4($s4)
.PB0f0bee38:
/*  f0bee38:	c6880008 */ 	lwc1	$f8,0x8($s4)
/*  f0bee3c:	27b001bc */ 	addiu	$s0,$sp,0x1bc
/*  f0bee40:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0bee44:	02002825 */ 	move	$a1,$s0
/*  f0bee48:	27a402b8 */ 	addiu	$a0,$sp,0x2b8
/*  f0bee4c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0bee50:	460e3483 */ 	div.s	$f18,$f6,$f14
/*  f0bee54:	c686000c */ 	lwc1	$f6,0xc($s4)
/*  f0bee58:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f0bee5c:	e6920004 */ 	swc1	$f18,0x4($s4)
/*  f0bee60:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f0bee64:	460e9203 */ 	div.s	$f8,$f18,$f14
/*  f0bee68:	e6840008 */ 	swc1	$f4,0x8($s4)
/*  f0bee6c:	0c0059e9 */ 	jal	mtx3ToMtx4
/*  f0bee70:	e688000c */ 	swc1	$f8,0xc($s4)
/*  f0bee74:	27b2012c */ 	addiu	$s2,$sp,0x12c
/*  f0bee78:	02402825 */ 	move	$a1,$s2
/*  f0bee7c:	0fc25bad */ 	jal	quaternion0f097044
/*  f0bee80:	02002025 */ 	move	$a0,$s0
/*  f0bee84:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f0bee88:	02003025 */ 	move	$a2,$s0
/*  f0bee8c:	02a02025 */ 	move	$a0,$s5
/*  f0bee90:	0fc25d6a */ 	jal	quaternionMultQuaternion
/*  f0bee94:	02402825 */ 	move	$a1,$s2
/*  f0bee98:	27b2017c */ 	addiu	$s2,$sp,0x17c
/*  f0bee9c:	02402825 */ 	move	$a1,$s2
/*  f0beea0:	0fc25b51 */ 	jal	quaternionToMtx
/*  f0beea4:	02002025 */ 	move	$a0,$s0
/*  f0beea8:	02402025 */ 	move	$a0,$s2
/*  f0beeac:	0c0059fc */ 	jal	mtx4ToMtx3
/*  f0beeb0:	27a502b8 */ 	addiu	$a1,$sp,0x2b8
/*  f0beeb4:	c7a002a8 */ 	lwc1	$f0,0x2a8($sp)
/*  f0beeb8:	c7aa02b8 */ 	lwc1	$f10,0x2b8($sp)
/*  f0beebc:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0beec0:	e624001c */ 	swc1	$f4,0x1c($s1)
/*  f0beec4:	c7a602bc */ 	lwc1	$f6,0x2bc($sp)
/*  f0beec8:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0beecc:	e6320020 */ 	swc1	$f18,0x20($s1)
/*  f0beed0:	c7a802c0 */ 	lwc1	$f8,0x2c0($sp)
/*  f0beed4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0beed8:	e62a0024 */ 	swc1	$f10,0x24($s1)
/*  f0beedc:	c7a402c4 */ 	lwc1	$f4,0x2c4($sp)
/*  f0beee0:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0beee4:	e6260028 */ 	swc1	$f6,0x28($s1)
/*  f0beee8:	c7b202c8 */ 	lwc1	$f18,0x2c8($sp)
/*  f0beeec:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0beef0:	e628002c */ 	swc1	$f8,0x2c($s1)
/*  f0beef4:	c7aa02cc */ 	lwc1	$f10,0x2cc($sp)
/*  f0beef8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0beefc:	e6240030 */ 	swc1	$f4,0x30($s1)
/*  f0bef00:	c7a602d0 */ 	lwc1	$f6,0x2d0($sp)
/*  f0bef04:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f0bef08:	e6320034 */ 	swc1	$f18,0x34($s1)
/*  f0bef0c:	c7a802d4 */ 	lwc1	$f8,0x2d4($sp)
/*  f0bef10:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bef14:	e62a0038 */ 	swc1	$f10,0x38($s1)
/*  f0bef18:	c7a402d8 */ 	lwc1	$f4,0x2d8($sp)
/*  f0bef1c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bef20:	e626003c */ 	swc1	$f6,0x3c($s1)
/*  f0bef24:	8fa902e0 */ 	lw	$t1,0x2e0($sp)
.PB0f0bef28:
/*  f0bef28:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bef2c:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bef30:	15200006 */ 	bnez	$t1,.PB0f0bef4c
/*  f0bef34:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0bef38:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f0bef3c:	240c0003 */ 	li	$t4,0x3
/*  f0bef40:	ad400264 */ 	sw	$zero,0x264($t2)
/*  f0bef44:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f0bef48:	a56c0010 */ 	sh	$t4,0x10($t3)
.PB0f0bef4c:
/*  f0bef4c:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f0bef50:	240d0001 */ 	li	$t5,0x1
/*  f0bef54:	1220000c */ 	beqz	$s1,.PB0f0bef88
/*  f0bef58:	af0d0274 */ 	sw	$t5,0x274($t8)
/*  f0bef5c:	8e220014 */ 	lw	$v0,0x14($s1)
/*  f0bef60:	10400009 */ 	beqz	$v0,.PB0f0bef88
/*  f0bef64:	24470008 */ 	addiu	$a3,$v0,0x8
/*  f0bef68:	244f0028 */ 	addiu	$t7,$v0,0x28
/*  f0bef6c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0bef70:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0bef74:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f0bef78:	0fc3072e */ 	jal	player0f0c1840
/*  f0bef7c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f0bef80:	10000383 */ 	b	.PB0f0bfd90
/*  f0bef84:	00000000 */ 	nop
.PB0f0bef88:
/*  f0bef88:	00003825 */ 	move	$a3,$zero
/*  f0bef8c:	0fc3072e */ 	jal	player0f0c1840
/*  f0bef90:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0bef94:	1000037e */ 	b	.PB0f0bfd90
/*  f0bef98:	00000000 */ 	nop
.PB0f0bef9c:
/*  f0bef9c:	24010001 */ 	li	$at,0x1
/*  f0befa0:	14610261 */ 	bne	$v1,$at,.PB0f0bf928
/*  f0befa4:	00000000 */ 	nop
/*  f0befa8:	0fc2e652 */ 	jal	player0f0b9538
/*  f0befac:	00000000 */ 	nop
/*  f0befb0:	8e6e028c */ 	lw	$t6,0x28c($s3)
/*  f0befb4:	3c098007 */ 	lui	$t1,0x8007
/*  f0befb8:	00003825 */ 	move	$a3,$zero
/*  f0befbc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0befc0:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0befc4:	8d292420 */ 	lw	$t1,0x2420($t1)
/*  f0befc8:	00002025 */ 	move	$a0,$zero
/*  f0befcc:	00002825 */ 	move	$a1,$zero
/*  f0befd0:	11200007 */ 	beqz	$t1,.PB0f0beff0
/*  f0befd4:	00003025 */ 	move	$a2,$zero
/*  f0befd8:	24040001 */ 	li	$a0,0x1
/*  f0befdc:	24050001 */ 	li	$a1,0x1
/*  f0befe0:	0fc3303a */ 	jal	bmoveTick
/*  f0befe4:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0befe8:	10000003 */ 	b	.PB0f0beff8
/*  f0befec:	00000000 */ 	nop
.PB0f0beff0:
/*  f0beff0:	0fc3303a */ 	jal	bmoveTick
/*  f0beff4:	24070001 */ 	li	$a3,0x1
.PB0f0beff8:
/*  f0beff8:	0fc2f60c */ 	jal	playerUpdateShake
/*  f0beffc:	00000000 */ 	nop
/*  f0bf000:	0fc3072a */ 	jal	playerSetCameraMode
/*  f0bf004:	00002025 */ 	move	$a0,$zero
/*  f0bf008:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf00c:	44802000 */ 	mtc1	$zero,$f4
/*  f0bf010:	27a400f4 */ 	addiu	$a0,$sp,0xf4
/*  f0bf014:	c512037c */ 	lwc1	$f18,0x37c($t0)
/*  f0bf018:	25050394 */ 	addiu	$a1,$t0,0x394
/*  f0bf01c:	25060388 */ 	addiu	$a2,$t0,0x388
/*  f0bf020:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bf024:	c5080380 */ 	lwc1	$f8,0x380($t0)
/*  f0bf028:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0bf02c:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f0bf030:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0bf034:	c50a0384 */ 	lwc1	$f10,0x384($t0)
/*  f0bf038:	44804000 */ 	mtc1	$zero,$f8
/*  f0bf03c:	44803000 */ 	mtc1	$zero,$f6
/*  f0bf040:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f0bf044:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f0bf048:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f0bf04c:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f0bf050:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0bf054:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0bf058:	e7a400f8 */ 	swc1	$f4,0xf8($sp)
/*  f0bf05c:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f0bf060:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf064:	246a0028 */ 	addiu	$t2,$v1,0x28
/*  f0bf068:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0bf06c:	0fc3072e */ 	jal	player0f0c1840
/*  f0bf070:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bf074:	8e6c0318 */ 	lw	$t4,0x318($s3)
/*  f0bf078:	3c0b800a */ 	lui	$t3,0x800a
/*  f0bf07c:	15800344 */ 	bnez	$t4,.PB0f0bfd90
/*  f0bf080:	00000000 */ 	nop
/*  f0bf084:	816d251b */ 	lb	$t5,0x251b($t3)
/*  f0bf088:	05a10341 */ 	bgez	$t5,.PB0f0bfd90
/*  f0bf08c:	00000000 */ 	nop
/*  f0bf090:	8e620474 */ 	lw	$v0,0x474($s3)
/*  f0bf094:	1840033e */ 	blez	$v0,.PB0f0bfd90
/*  f0bf098:	00000000 */ 	nop
/*  f0bf09c:	8e780478 */ 	lw	$t8,0x478($s3)
/*  f0bf0a0:	1700033b */ 	bnez	$t8,.PB0f0bfd90
/*  f0bf0a4:	00000000 */ 	nop
/*  f0bf0a8:	8e6f04b4 */ 	lw	$t7,0x4b4($s3)
/*  f0bf0ac:	24010026 */ 	li	$at,0x26
/*  f0bf0b0:	11e10337 */ 	beq	$t7,$at,.PB0f0bfd90
/*  f0bf0b4:	00000000 */ 	nop
/*  f0bf0b8:	8e6e000c */ 	lw	$t6,0xc($s3)
/*  f0bf0bc:	24190001 */ 	li	$t9,0x1
/*  f0bf0c0:	29c10015 */ 	slti	$at,$t6,0x15
/*  f0bf0c4:	14200332 */ 	bnez	$at,.PB0f0bfd90
/*  f0bf0c8:	00000000 */ 	nop
/*  f0bf0cc:	ae790478 */ 	sw	$t9,0x478($s3)
/*  f0bf0d0:	1840032f */ 	blez	$v0,.PB0f0bfd90
/*  f0bf0d4:	afa000e8 */ 	sw	$zero,0xe8($sp)
/*  f0bf0d8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0bf0dc:	4481b000 */ 	mtc1	$at,$f22
/*  f0bf0e0:	3c09800a */ 	lui	$t1,0x800a
/*  f0bf0e4:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f0bf0e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bf0ec:	c434f3a4 */ 	lwc1	$f20,-0xc5c($at)
/*  f0bf0f0:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f0bf0f4:	24140013 */ 	li	$s4,0x13
/*  f0bf0f8:	24120064 */ 	li	$s2,0x64
.PB0f0bf0fc:
/*  f0bf0fc:	3c0a800a */ 	lui	$t2,0x800a
/*  f0bf100:	8d4a6700 */ 	lw	$t2,0x6700($t2)
/*  f0bf104:	3c0103c0 */ 	lui	$at,0x3c0
/*  f0bf108:	00008825 */ 	move	$s1,$zero
/*  f0bf10c:	01416024 */ 	and	$t4,$t2,$at
/*  f0bf110:	15800078 */ 	bnez	$t4,.PB0f0bf2f4
/*  f0bf114:	00000000 */ 	nop
/*  f0bf118:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf11c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf120:	14540015 */ 	bne	$v0,$s4,.PB0f0bf178
/*  f0bf124:	00000000 */ 	nop
/*  f0bf128:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf12c:	24040012 */ 	li	$a0,0x12
/*  f0bf130:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf134:	3c014000 */ 	lui	$at,0x4000
/*  f0bf138:	44812000 */ 	mtc1	$at,$f4
/*  f0bf13c:	c50a0144 */ 	lwc1	$f10,0x144($t0)
/*  f0bf140:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf144:	240b0010 */ 	li	$t3,0x10
/*  f0bf148:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0bf14c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0bf150:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf154:	24040056 */ 	li	$a0,0x56
/*  f0bf158:	2405003e */ 	li	$a1,0x3e
/*  f0bf15c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf160:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf164:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bf168:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf16c:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bf170:	1000002a */ 	b	.PB0f0bf21c
/*  f0bf174:	00408825 */ 	move	$s1,$v0
.PB0f0bf178:
/*  f0bf178:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf17c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf180:	24010023 */ 	li	$at,0x23
/*  f0bf184:	14410012 */ 	bne	$v0,$at,.PB0f0bf1d0
/*  f0bf188:	00000000 */ 	nop
/*  f0bf18c:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf190:	24040012 */ 	li	$a0,0x12
/*  f0bf194:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf198:	240d0010 */ 	li	$t5,0x10
/*  f0bf19c:	2404005b */ 	li	$a0,0x5b
/*  f0bf1a0:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0bf1a4:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf1a8:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0bf1ac:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bf1b0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf1b4:	24050008 */ 	li	$a1,0x8
/*  f0bf1b8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf1bc:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf1c0:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf1c4:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bf1c8:	10000014 */ 	b	.PB0f0bf21c
/*  f0bf1cc:	00408825 */ 	move	$s1,$v0
.PB0f0bf1d0:
/*  f0bf1d0:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf1d4:	24040012 */ 	li	$a0,0x12
/*  f0bf1d8:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf1dc:	3c014000 */ 	lui	$at,0x4000
/*  f0bf1e0:	44813000 */ 	mtc1	$at,$f6
/*  f0bf1e4:	c5040144 */ 	lwc1	$f4,0x144($t0)
/*  f0bf1e8:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf1ec:	24180010 */ 	li	$t8,0x10
/*  f0bf1f0:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0bf1f4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0bf1f8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf1fc:	24040056 */ 	li	$a0,0x56
/*  f0bf200:	2405003e */ 	li	$a1,0x3e
/*  f0bf204:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf208:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf20c:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0bf210:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf214:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bf218:	00408825 */ 	move	$s1,$v0
.PB0f0bf21c:
/*  f0bf21c:	10400035 */ 	beqz	$v0,.PB0f0bf2f4
/*  f0bf220:	3c014030 */ 	lui	$at,0x4030
/*  f0bf224:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf228:	240a0010 */ 	li	$t2,0x10
/*  f0bf22c:	240d0003 */ 	li	$t5,0x3
/*  f0bf230:	8e190118 */ 	lw	$t9,0x118($s0)
/*  f0bf234:	8e0f0114 */ 	lw	$t7,0x114($s0)
/*  f0bf238:	8e0c0014 */ 	lw	$t4,0x14($s0)
/*  f0bf23c:	03214825 */ 	or	$t1,$t9,$at
/*  f0bf240:	3c018000 */ 	lui	$at,0x8000
/*  f0bf244:	24180032 */ 	li	$t8,0x32
/*  f0bf248:	35ee2000 */ 	ori	$t6,$t7,0x2000
/*  f0bf24c:	01815825 */ 	or	$t3,$t4,$at
/*  f0bf250:	ae0e0114 */ 	sw	$t6,0x114($s0)
/*  f0bf254:	ae090118 */ 	sw	$t1,0x118($s0)
/*  f0bf258:	a20a0125 */ 	sb	$t2,0x125($s0)
/*  f0bf25c:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf260:	ae0b0014 */ 	sw	$t3,0x14($s0)
/*  f0bf264:	a20d02b1 */ 	sb	$t5,0x2b1($s0)
/*  f0bf268:	a21802e2 */ 	sb	$t8,0x2e2($s0)
/*  f0bf26c:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bf270:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf274:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf278:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf27c:	14540005 */ 	bne	$v0,$s4,.PB0f0bf294
/*  f0bf280:	02002025 */ 	move	$a0,$s0
/*  f0bf284:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf288:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf28c:	10000005 */ 	b	.PB0f0bf2a4
/*  f0bf290:	02002025 */ 	move	$a0,$s0
.PB0f0bf294:
/*  f0bf294:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf298:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf29c:	02002025 */ 	move	$a0,$s0
/*  f0bf2a0:	02002025 */ 	move	$a0,$s0
.PB0f0bf2a4:
/*  f0bf2a4:	0fc08191 */ 	jal	chrSetMaxDamage
/*  f0bf2a8:	3c054080 */ 	lui	$a1,0x4080
/*  f0bf2ac:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f0bf2b0:	920c02e1 */ 	lbu	$t4,0x2e1($s0)
/*  f0bf2b4:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bf2b8:	3c010004 */ 	lui	$at,0x4
/*  f0bf2bc:	01e17025 */ 	or	$t6,$t7,$at
/*  f0bf2c0:	358d0001 */ 	ori	$t5,$t4,0x1
/*  f0bf2c4:	3c012000 */ 	lui	$at,0x2000
/*  f0bf2c8:	a20d02e1 */ 	sb	$t5,0x2e1($s0)
/*  f0bf2cc:	31b80001 */ 	andi	$t8,$t5,0x1
/*  f0bf2d0:	03214825 */ 	or	$t1,$t9,$at
/*  f0bf2d4:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f0bf2d8:	ae090014 */ 	sw	$t1,0x14($s0)
/*  f0bf2dc:	a21802e1 */ 	sb	$t8,0x2e1($s0)
/*  f0bf2e0:	02002025 */ 	move	$a0,$s0
/*  f0bf2e4:	240500f5 */ 	li	$a1,0xf5
/*  f0bf2e8:	24060002 */ 	li	$a2,0x2
/*  f0bf2ec:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f0bf2f0:	00003825 */ 	move	$a3,$zero
.PB0f0bf2f4:
/*  f0bf2f4:	0fc41d39 */ 	jal	cheatIsActive
/*  f0bf2f8:	24040016 */ 	li	$a0,0x16
/*  f0bf2fc:	10400058 */ 	beqz	$v0,.PB0f0bf460
/*  f0bf300:	00000000 */ 	nop
/*  f0bf304:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf308:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf30c:	24010023 */ 	li	$at,0x23
/*  f0bf310:	14410012 */ 	bne	$v0,$at,.PB0f0bf35c
/*  f0bf314:	00000000 */ 	nop
/*  f0bf318:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf31c:	24040012 */ 	li	$a0,0x12
/*  f0bf320:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf324:	240f0010 */ 	li	$t7,0x10
/*  f0bf328:	2404005b */ 	li	$a0,0x5b
/*  f0bf32c:	c50a0144 */ 	lwc1	$f10,0x144($t0)
/*  f0bf330:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf334:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0bf338:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0bf33c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf340:	24050008 */ 	li	$a1,0x8
/*  f0bf344:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf348:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf34c:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf350:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0bf354:	10000011 */ 	b	.PB0f0bf39c
/*  f0bf358:	00408825 */ 	move	$s1,$v0
.PB0f0bf35c:
/*  f0bf35c:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf360:	02802025 */ 	move	$a0,$s4
/*  f0bf364:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf368:	240e0010 */ 	li	$t6,0x10
/*  f0bf36c:	2404005a */ 	li	$a0,0x5a
/*  f0bf370:	c5060144 */ 	lwc1	$f6,0x144($t0)
/*  f0bf374:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf378:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0bf37c:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bf380:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf384:	2405001b */ 	li	$a1,0x1b
/*  f0bf388:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf38c:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf390:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf394:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bf398:	00408825 */ 	move	$s1,$v0
.PB0f0bf39c:
/*  f0bf39c:	10400030 */ 	beqz	$v0,.PB0f0bf460
/*  f0bf3a0:	3c014030 */ 	lui	$at,0x4030
/*  f0bf3a4:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf3a8:	34210081 */ 	ori	$at,$at,0x81
/*  f0bf3ac:	240b0010 */ 	li	$t3,0x10
/*  f0bf3b0:	8e0a0118 */ 	lw	$t2,0x118($s0)
/*  f0bf3b4:	8e190114 */ 	lw	$t9,0x114($s0)
/*  f0bf3b8:	8e180014 */ 	lw	$t8,0x14($s0)
/*  f0bf3bc:	01416025 */ 	or	$t4,$t2,$at
/*  f0bf3c0:	3c018000 */ 	lui	$at,0x8000
/*  f0bf3c4:	240d0064 */ 	li	$t5,0x64
/*  f0bf3c8:	37292080 */ 	ori	$t1,$t9,0x2080
/*  f0bf3cc:	03017825 */ 	or	$t7,$t8,$at
/*  f0bf3d0:	ae090114 */ 	sw	$t1,0x114($s0)
/*  f0bf3d4:	ae0c0118 */ 	sw	$t4,0x118($s0)
/*  f0bf3d8:	a20b0125 */ 	sb	$t3,0x125($s0)
/*  f0bf3dc:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf3e0:	a20d02e2 */ 	sb	$t5,0x2e2($s0)
/*  f0bf3e4:	ae0f0014 */ 	sw	$t7,0x14($s0)
/*  f0bf3e8:	a21502b1 */ 	sb	$s5,0x2b1($s0)
/*  f0bf3ec:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bf3f0:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf3f4:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf3f8:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf3fc:	14540005 */ 	bne	$v0,$s4,.PB0f0bf414
/*  f0bf400:	02002025 */ 	move	$a0,$s0
/*  f0bf404:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf408:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf40c:	10000005 */ 	b	.PB0f0bf424
/*  f0bf410:	8e0e0018 */ 	lw	$t6,0x18($s0)
.PB0f0bf414:
/*  f0bf414:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf418:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf41c:	02002025 */ 	move	$a0,$s0
/*  f0bf420:	8e0e0018 */ 	lw	$t6,0x18($s0)
.PB0f0bf424:
/*  f0bf424:	920b02e1 */ 	lbu	$t3,0x2e1($s0)
/*  f0bf428:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f0bf42c:	3c010004 */ 	lui	$at,0x4
/*  f0bf430:	01c1c825 */ 	or	$t9,$t6,$at
/*  f0bf434:	35780001 */ 	ori	$t8,$t3,0x1
/*  f0bf438:	3c012000 */ 	lui	$at,0x2000
/*  f0bf43c:	a21802e1 */ 	sb	$t8,0x2e1($s0)
/*  f0bf440:	330f0001 */ 	andi	$t7,$t8,0x1
/*  f0bf444:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf448:	01215025 */ 	or	$t2,$t1,$at
/*  f0bf44c:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0bf450:	ae0a0014 */ 	sw	$t2,0x14($s0)
/*  f0bf454:	a20f02e1 */ 	sb	$t7,0x2e1($s0)
/*  f0bf458:	0fc08191 */ 	jal	chrSetMaxDamage
/*  f0bf45c:	02002025 */ 	move	$a0,$s0
.PB0f0bf460:
/*  f0bf460:	0fc41d39 */ 	jal	cheatIsActive
/*  f0bf464:	24040018 */ 	li	$a0,0x18
/*  f0bf468:	1040005e */ 	beqz	$v0,.PB0f0bf5e4
/*  f0bf46c:	00000000 */ 	nop
/*  f0bf470:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf474:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf478:	24010023 */ 	li	$at,0x23
/*  f0bf47c:	14410012 */ 	bne	$v0,$at,.PB0f0bf4c8
/*  f0bf480:	00000000 */ 	nop
/*  f0bf484:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf488:	24040012 */ 	li	$a0,0x12
/*  f0bf48c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf490:	240e0010 */ 	li	$t6,0x10
/*  f0bf494:	2404005b */ 	li	$a0,0x5b
/*  f0bf498:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0bf49c:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf4a0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0bf4a4:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bf4a8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf4ac:	24050008 */ 	li	$a1,0x8
/*  f0bf4b0:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf4b4:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf4b8:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf4bc:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bf4c0:	10000011 */ 	b	.PB0f0bf508
/*  f0bf4c4:	00408825 */ 	move	$s1,$v0
.PB0f0bf4c8:
/*  f0bf4c8:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf4cc:	24040012 */ 	li	$a0,0x12
/*  f0bf4d0:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf4d4:	24190010 */ 	li	$t9,0x10
/*  f0bf4d8:	2404005b */ 	li	$a0,0x5b
/*  f0bf4dc:	c5040144 */ 	lwc1	$f4,0x144($t0)
/*  f0bf4e0:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf4e4:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0bf4e8:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0bf4ec:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf4f0:	24050012 */ 	li	$a1,0x12
/*  f0bf4f4:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf4f8:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf4fc:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf500:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0bf504:	00408825 */ 	move	$s1,$v0
.PB0f0bf508:
/*  f0bf508:	10400036 */ 	beqz	$v0,.PB0f0bf5e4
/*  f0bf50c:	3c018030 */ 	lui	$at,0x8030
/*  f0bf510:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf514:	240d0010 */ 	li	$t5,0x10
/*  f0bf518:	240e0002 */ 	li	$t6,0x2
/*  f0bf51c:	8e0c0118 */ 	lw	$t4,0x118($s0)
/*  f0bf520:	8e090114 */ 	lw	$t1,0x114($s0)
/*  f0bf524:	8e180014 */ 	lw	$t8,0x14($s0)
/*  f0bf528:	01815825 */ 	or	$t3,$t4,$at
/*  f0bf52c:	3c018000 */ 	lui	$at,0x8000
/*  f0bf530:	352a2000 */ 	ori	$t2,$t1,0x2000
/*  f0bf534:	24190032 */ 	li	$t9,0x32
/*  f0bf538:	24090032 */ 	li	$t1,0x32
/*  f0bf53c:	03017825 */ 	or	$t7,$t8,$at
/*  f0bf540:	ae0a0114 */ 	sw	$t2,0x114($s0)
/*  f0bf544:	ae0b0118 */ 	sw	$t3,0x118($s0)
/*  f0bf548:	a20d0125 */ 	sb	$t5,0x125($s0)
/*  f0bf54c:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf550:	ae0f0014 */ 	sw	$t7,0x14($s0)
/*  f0bf554:	a20e02b1 */ 	sb	$t6,0x2b1($s0)
/*  f0bf558:	a21902e2 */ 	sb	$t9,0x2e2($s0)
/*  f0bf55c:	a2090002 */ 	sb	$t1,0x2($s0)
/*  f0bf560:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf564:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf568:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf56c:	14540006 */ 	bne	$v0,$s4,.PB0f0bf588
/*  f0bf570:	02002025 */ 	move	$a0,$s0
/*  f0bf574:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf578:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf57c:	02002025 */ 	move	$a0,$s0
/*  f0bf580:	10000004 */ 	b	.PB0f0bf594
/*  f0bf584:	02002025 */ 	move	$a0,$s0
.PB0f0bf588:
/*  f0bf588:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf58c:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf590:	02002025 */ 	move	$a0,$s0
.PB0f0bf594:
/*  f0bf594:	0fc08191 */ 	jal	chrSetMaxDamage
/*  f0bf598:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf59c:	8e0a0018 */ 	lw	$t2,0x18($s0)
/*  f0bf5a0:	920f02e1 */ 	lbu	$t7,0x2e1($s0)
/*  f0bf5a4:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f0bf5a8:	3c010004 */ 	lui	$at,0x4
/*  f0bf5ac:	01416025 */ 	or	$t4,$t2,$at
/*  f0bf5b0:	35f90001 */ 	ori	$t9,$t7,0x1
/*  f0bf5b4:	3c012000 */ 	lui	$at,0x2000
/*  f0bf5b8:	a21902e1 */ 	sb	$t9,0x2e1($s0)
/*  f0bf5bc:	33290001 */ 	andi	$t1,$t9,0x1
/*  f0bf5c0:	01616825 */ 	or	$t5,$t3,$at
/*  f0bf5c4:	ae0c0018 */ 	sw	$t4,0x18($s0)
/*  f0bf5c8:	ae0d0014 */ 	sw	$t5,0x14($s0)
/*  f0bf5cc:	a20902e1 */ 	sb	$t1,0x2e1($s0)
/*  f0bf5d0:	02002025 */ 	move	$a0,$s0
/*  f0bf5d4:	24050101 */ 	li	$a1,0x101
/*  f0bf5d8:	24060010 */ 	li	$a2,0x10
/*  f0bf5dc:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f0bf5e0:	00003825 */ 	move	$a3,$zero
.PB0f0bf5e4:
/*  f0bf5e4:	0fc41d39 */ 	jal	cheatIsActive
/*  f0bf5e8:	24040017 */ 	li	$a0,0x17
/*  f0bf5ec:	10400062 */ 	beqz	$v0,.PB0f0bf778
/*  f0bf5f0:	00000000 */ 	nop
/*  f0bf5f4:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf5f8:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf5fc:	24010023 */ 	li	$at,0x23
/*  f0bf600:	14410012 */ 	bne	$v0,$at,.PB0f0bf64c
/*  f0bf604:	00000000 */ 	nop
/*  f0bf608:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf60c:	24040012 */ 	li	$a0,0x12
/*  f0bf610:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf614:	240a0010 */ 	li	$t2,0x10
/*  f0bf618:	2404005b */ 	li	$a0,0x5b
/*  f0bf61c:	c5120144 */ 	lwc1	$f18,0x144($t0)
/*  f0bf620:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf624:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0bf628:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0bf62c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf630:	24050008 */ 	li	$a1,0x8
/*  f0bf634:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf638:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf63c:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf640:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bf644:	10000011 */ 	b	.PB0f0bf68c
/*  f0bf648:	00408825 */ 	move	$s1,$v0
.PB0f0bf64c:
/*  f0bf64c:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf650:	24040012 */ 	li	$a0,0x12
/*  f0bf654:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf658:	240c0010 */ 	li	$t4,0x10
/*  f0bf65c:	24040092 */ 	li	$a0,0x92
/*  f0bf660:	c50a0144 */ 	lwc1	$f10,0x144($t0)
/*  f0bf664:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf668:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0bf66c:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0bf670:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf674:	02802825 */ 	move	$a1,$s4
/*  f0bf678:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf67c:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf680:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf684:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0bf688:	00408825 */ 	move	$s1,$v0
.PB0f0bf68c:
/*  f0bf68c:	1040003a */ 	beqz	$v0,.PB0f0bf778
/*  f0bf690:	3c014030 */ 	lui	$at,0x4030
/*  f0bf694:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf698:	240e0010 */ 	li	$t6,0x10
/*  f0bf69c:	240a0064 */ 	li	$t2,0x64
/*  f0bf6a0:	8e180118 */ 	lw	$t8,0x118($s0)
/*  f0bf6a4:	8e0b0114 */ 	lw	$t3,0x114($s0)
/*  f0bf6a8:	8e190014 */ 	lw	$t9,0x14($s0)
/*  f0bf6ac:	03017825 */ 	or	$t7,$t8,$at
/*  f0bf6b0:	3c018000 */ 	lui	$at,0x8000
/*  f0bf6b4:	240c0032 */ 	li	$t4,0x32
/*  f0bf6b8:	356d2000 */ 	ori	$t5,$t3,0x2000
/*  f0bf6bc:	03214825 */ 	or	$t1,$t9,$at
/*  f0bf6c0:	ae0d0114 */ 	sw	$t5,0x114($s0)
/*  f0bf6c4:	ae0f0118 */ 	sw	$t7,0x118($s0)
/*  f0bf6c8:	a20e0125 */ 	sb	$t6,0x125($s0)
/*  f0bf6cc:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf6d0:	ae090014 */ 	sw	$t1,0x14($s0)
/*  f0bf6d4:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0bf6d8:	a20a02e2 */ 	sb	$t2,0x2e2($s0)
/*  f0bf6dc:	a20c0002 */ 	sb	$t4,0x2($s0)
/*  f0bf6e0:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf6e4:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf6e8:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf6ec:	14540005 */ 	bne	$v0,$s4,.PB0f0bf704
/*  f0bf6f0:	02002025 */ 	move	$a0,$s0
/*  f0bf6f4:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf6f8:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf6fc:	10000005 */ 	b	.PB0f0bf714
/*  f0bf700:	02002025 */ 	move	$a0,$s0
.PB0f0bf704:
/*  f0bf704:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf708:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf70c:	02002025 */ 	move	$a0,$s0
/*  f0bf710:	02002025 */ 	move	$a0,$s0
.PB0f0bf714:
/*  f0bf714:	0fc08191 */ 	jal	chrSetMaxDamage
/*  f0bf718:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf71c:	8e0b0018 */ 	lw	$t3,0x18($s0)
/*  f0bf720:	921902e1 */ 	lbu	$t9,0x2e1($s0)
/*  f0bf724:	8e180014 */ 	lw	$t8,0x14($s0)
/*  f0bf728:	3c010004 */ 	lui	$at,0x4
/*  f0bf72c:	01616825 */ 	or	$t5,$t3,$at
/*  f0bf730:	372a0001 */ 	ori	$t2,$t9,0x1
/*  f0bf734:	3c012000 */ 	lui	$at,0x2000
/*  f0bf738:	a20a02e1 */ 	sb	$t2,0x2e1($s0)
/*  f0bf73c:	314c0001 */ 	andi	$t4,$t2,0x1
/*  f0bf740:	03017825 */ 	or	$t7,$t8,$at
/*  f0bf744:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f0bf748:	ae0f0014 */ 	sw	$t7,0x14($s0)
/*  f0bf74c:	a20c02e1 */ 	sb	$t4,0x2e1($s0)
/*  f0bf750:	02002025 */ 	move	$a0,$s0
/*  f0bf754:	240500f9 */ 	li	$a1,0xf9
/*  f0bf758:	24060009 */ 	li	$a2,0x9
/*  f0bf75c:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f0bf760:	00003825 */ 	move	$a3,$zero
/*  f0bf764:	02002025 */ 	move	$a0,$s0
/*  f0bf768:	240500f8 */ 	li	$a1,0xf8
/*  f0bf76c:	24060008 */ 	li	$a2,0x8
/*  f0bf770:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f0bf774:	3c071000 */ 	lui	$a3,0x1000
.PB0f0bf778:
/*  f0bf778:	0fc41d39 */ 	jal	cheatIsActive
/*  f0bf77c:	24040019 */ 	li	$a0,0x19
/*  f0bf780:	5040005d */ 	beqzl	$v0,.PB0f0bf8f8
/*  f0bf784:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0bf788:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf78c:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf790:	24010023 */ 	li	$at,0x23
/*  f0bf794:	14410012 */ 	bne	$v0,$at,.PB0f0bf7e0
/*  f0bf798:	00000000 */ 	nop
/*  f0bf79c:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf7a0:	24040012 */ 	li	$a0,0x12
/*  f0bf7a4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf7a8:	240b0010 */ 	li	$t3,0x10
/*  f0bf7ac:	2404005b */ 	li	$a0,0x5b
/*  f0bf7b0:	c5060144 */ 	lwc1	$f6,0x144($t0)
/*  f0bf7b4:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf7b8:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0bf7bc:	46143482 */ 	mul.s	$f18,$f6,$f20
/*  f0bf7c0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf7c4:	24050008 */ 	li	$a1,0x8
/*  f0bf7c8:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf7cc:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf7d0:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf7d4:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0bf7d8:	10000011 */ 	b	.PB0f0bf820
/*  f0bf7dc:	00408825 */ 	move	$s1,$v0
.PB0f0bf7e0:
/*  f0bf7e0:	0c0063c8 */ 	jal	ailistFindById
/*  f0bf7e4:	24040012 */ 	li	$a0,0x12
/*  f0bf7e8:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf7ec:	240d0010 */ 	li	$t5,0x10
/*  f0bf7f0:	24040057 */ 	li	$a0,0x57
/*  f0bf7f4:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0bf7f8:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf7fc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0bf800:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0bf804:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0bf808:	24050029 */ 	li	$a1,0x29
/*  f0bf80c:	24660008 */ 	addiu	$a2,$v1,0x8
/*  f0bf810:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f0bf814:	0fc12d06 */ 	jal	chrSpawnAtCoord
/*  f0bf818:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0bf81c:	00408825 */ 	move	$s1,$v0
.PB0f0bf820:
/*  f0bf820:	10400034 */ 	beqz	$v0,.PB0f0bf8f4
/*  f0bf824:	3c01c030 */ 	lui	$at,0xc030
/*  f0bf828:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f0bf82c:	24090010 */ 	li	$t1,0x10
/*  f0bf830:	240b0096 */ 	li	$t3,0x96
/*  f0bf834:	8e0e0118 */ 	lw	$t6,0x118($s0)
/*  f0bf838:	8e180114 */ 	lw	$t8,0x114($s0)
/*  f0bf83c:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0bf840:	01c1c825 */ 	or	$t9,$t6,$at
/*  f0bf844:	3c018000 */ 	lui	$at,0x8000
/*  f0bf848:	370f2000 */ 	ori	$t7,$t8,0x2000
/*  f0bf84c:	01416025 */ 	or	$t4,$t2,$at
/*  f0bf850:	ae0f0114 */ 	sw	$t7,0x114($s0)
/*  f0bf854:	ae190118 */ 	sw	$t9,0x118($s0)
/*  f0bf858:	a2090125 */ 	sb	$t1,0x125($s0)
/*  f0bf85c:	a21502a2 */ 	sb	$s5,0x2a2($s0)
/*  f0bf860:	ae0c0014 */ 	sw	$t4,0x14($s0)
/*  f0bf864:	a20002b1 */ 	sb	$zero,0x2b1($s0)
/*  f0bf868:	a20b02e2 */ 	sb	$t3,0x2e2($s0)
/*  f0bf86c:	a2120002 */ 	sb	$s2,0x2($s0)
/*  f0bf870:	a2120003 */ 	sb	$s2,0x3($s0)
/*  f0bf874:	0fc59b21 */ 	jal	stageGetIndex
/*  f0bf878:	8e6404b4 */ 	lw	$a0,0x4b4($s3)
/*  f0bf87c:	14540005 */ 	bne	$v0,$s4,.PB0f0bf894
/*  f0bf880:	02002025 */ 	move	$a0,$s0
/*  f0bf884:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf888:	3c054220 */ 	lui	$a1,0x4220
/*  f0bf88c:	10000005 */ 	b	.PB0f0bf8a4
/*  f0bf890:	02002025 */ 	move	$a0,$s0
.PB0f0bf894:
/*  f0bf894:	4405b000 */ 	mfc1	$a1,$f22
/*  f0bf898:	0fc08196 */ 	jal	chrAddHealth
/*  f0bf89c:	02002025 */ 	move	$a0,$s0
/*  f0bf8a0:	02002025 */ 	move	$a0,$s0
.PB0f0bf8a4:
/*  f0bf8a4:	0fc08191 */ 	jal	chrSetMaxDamage
/*  f0bf8a8:	3c054120 */ 	lui	$a1,0x4120
/*  f0bf8ac:	8e0d0018 */ 	lw	$t5,0x18($s0)
/*  f0bf8b0:	920902e1 */ 	lbu	$t1,0x2e1($s0)
/*  f0bf8b4:	8e0f0014 */ 	lw	$t7,0x14($s0)
/*  f0bf8b8:	3c010004 */ 	lui	$at,0x4
/*  f0bf8bc:	01a1c025 */ 	or	$t8,$t5,$at
/*  f0bf8c0:	352c0001 */ 	ori	$t4,$t1,0x1
/*  f0bf8c4:	3c012000 */ 	lui	$at,0x2000
/*  f0bf8c8:	a20c02e1 */ 	sb	$t4,0x2e1($s0)
/*  f0bf8cc:	318b0001 */ 	andi	$t3,$t4,0x1
/*  f0bf8d0:	01e17025 */ 	or	$t6,$t7,$at
/*  f0bf8d4:	ae180018 */ 	sw	$t8,0x18($s0)
/*  f0bf8d8:	ae0e0014 */ 	sw	$t6,0x14($s0)
/*  f0bf8dc:	a20b02e1 */ 	sb	$t3,0x2e1($s0)
/*  f0bf8e0:	02002025 */ 	move	$a0,$s0
/*  f0bf8e4:	24050104 */ 	li	$a1,0x104
/*  f0bf8e8:	2406000d */ 	li	$a2,0xd
/*  f0bf8ec:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f0bf8f0:	00003825 */ 	move	$a3,$zero
.PB0f0bf8f4:
/*  f0bf8f4:	8fad0058 */ 	lw	$t5,0x58($sp)
.PB0f0bf8f8:
/*  f0bf8f8:	adb104b8 */ 	sw	$s1,0x4b8($t5)
/*  f0bf8fc:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f0bf900:	8e690474 */ 	lw	$t1,0x474($s3)
/*  f0bf904:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0bf908:	270f0001 */ 	addiu	$t7,$t8,0x1
/*  f0bf90c:	01e9082a */ 	slt	$at,$t7,$t1
/*  f0bf910:	25d90004 */ 	addiu	$t9,$t6,0x4
/*  f0bf914:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0bf918:	1420fdf8 */ 	bnez	$at,.PB0f0bf0fc
/*  f0bf91c:	afaf00e8 */ 	sw	$t7,0xe8($sp)
/*  f0bf920:	1000011b */ 	b	.PB0f0bfd90
/*  f0bf924:	00000000 */ 	nop
.PB0f0bf928:
/*  f0bf928:	10600003 */ 	beqz	$v1,.PB0f0bf938
/*  f0bf92c:	24010005 */ 	li	$at,0x5
/*  f0bf930:	54610018 */ 	bnel	$v1,$at,.PB0f0bf994
/*  f0bf934:	24010004 */ 	li	$at,0x4
.PB0f0bf938:
/*  f0bf938:	0fc2e652 */ 	jal	player0f0b9538
/*  f0bf93c:	00000000 */ 	nop
/*  f0bf940:	24040001 */ 	li	$a0,0x1
/*  f0bf944:	24050001 */ 	li	$a1,0x1
/*  f0bf948:	8fa60330 */ 	lw	$a2,0x330($sp)
/*  f0bf94c:	0fc3303a */ 	jal	bmoveTick
/*  f0bf950:	00003825 */ 	move	$a3,$zero
/*  f0bf954:	0fc2f60c */ 	jal	playerUpdateShake
/*  f0bf958:	00000000 */ 	nop
/*  f0bf95c:	0fc3072a */ 	jal	playerSetCameraMode
/*  f0bf960:	00002025 */ 	move	$a0,$zero
/*  f0bf964:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bf968:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bf96c:	2504037c */ 	addiu	$a0,$t0,0x37c
/*  f0bf970:	25050394 */ 	addiu	$a1,$t0,0x394
/*  f0bf974:	246a0028 */ 	addiu	$t2,$v1,0x28
/*  f0bf978:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0bf97c:	25060388 */ 	addiu	$a2,$t0,0x388
/*  f0bf980:	0fc3072e */ 	jal	player0f0c1840
/*  f0bf984:	24670008 */ 	addiu	$a3,$v1,0x8
/*  f0bf988:	10000101 */ 	b	.PB0f0bfd90
/*  f0bf98c:	00000000 */ 	nop
/*  f0bf990:	24010004 */ 	li	$at,0x4
.PB0f0bf994:
/*  f0bf994:	1461000c */ 	bne	$v1,$at,.PB0f0bf9c8
/*  f0bf998:	00000000 */ 	nop
/*  f0bf99c:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0bf9a0:	00000000 */ 	nop
/*  f0bf9a4:	00002025 */ 	move	$a0,$zero
/*  f0bf9a8:	00002825 */ 	move	$a1,$zero
/*  f0bf9ac:	00003025 */ 	move	$a2,$zero
/*  f0bf9b0:	0fc3303a */ 	jal	bmoveTick
/*  f0bf9b4:	24070001 */ 	li	$a3,0x1
/*  f0bf9b8:	0fc2e6be */ 	jal	playerTickMpSwirl
/*  f0bf9bc:	00000000 */ 	nop
/*  f0bf9c0:	100000f3 */ 	b	.PB0f0bfd90
/*  f0bf9c4:	00000000 */ 	nop
.PB0f0bf9c8:
/*  f0bf9c8:	1443000c */ 	bne	$v0,$v1,.PB0f0bf9fc
/*  f0bf9cc:	24010007 */ 	li	$at,0x7
/*  f0bf9d0:	0fc2e3ec */ 	jal	playerTickChrBody
/*  f0bf9d4:	00000000 */ 	nop
/*  f0bf9d8:	00002025 */ 	move	$a0,$zero
/*  f0bf9dc:	00002825 */ 	move	$a1,$zero
/*  f0bf9e0:	00003025 */ 	move	$a2,$zero
/*  f0bf9e4:	0fc3303a */ 	jal	bmoveTick
/*  f0bf9e8:	24070001 */ 	li	$a3,0x1
/*  f0bf9ec:	0fc2e833 */ 	jal	playerExecutePreparedWarp
/*  f0bf9f0:	00000000 */ 	nop
/*  f0bf9f4:	100000e6 */ 	b	.PB0f0bfd90
/*  f0bf9f8:	00000000 */ 	nop
.PB0f0bf9fc:
/*  f0bf9fc:	146100e4 */ 	bne	$v1,$at,.PB0f0bfd90
/*  f0bfa00:	00000000 */ 	nop
/*  f0bfa04:	0fc2e652 */ 	jal	player0f0b9538
/*  f0bfa08:	00000000 */ 	nop
/*  f0bfa0c:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f0bfa10:	24050002 */ 	li	$a1,0x2
/*  f0bfa14:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0bfa18:	0fc458d4 */ 	jal	padUnpack
/*  f0bfa1c:	85841ba4 */ 	lh	$a0,0x1ba4($t4)
/*  f0bfa20:	0c003a6e */ 	jal	mainGetStageNum
/*  f0bfa24:	00000000 */ 	nop
/*  f0bfa28:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0bfa2c:	856b2480 */ 	lh	$t3,0x2480($t3)
/*  f0bfa30:	544b000c */ 	bnel	$v0,$t3,.PB0f0bfa64
/*  f0bfa34:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfa38:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f0bfa3c:	24010019 */ 	li	$at,0x19
/*  f0bfa40:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0bfa44:	85b81ba4 */ 	lh	$t8,0x1ba4($t5)
/*  f0bfa48:	17010005 */ 	bne	$t8,$at,.PB0f0bfa60
/*  f0bfa4c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0bfa50:	44813000 */ 	mtc1	$at,$f6
/*  f0bfa54:	00000000 */ 	nop
/*  f0bfa58:	46062481 */ 	sub.s	$f18,$f4,$f6
/*  f0bfa5c:	e7b20078 */ 	swc1	$f18,0x78($sp)
.PB0f0bfa60:
/*  f0bfa60:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfa64:
/*  f0bfa64:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0bfa68:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0bfa6c:	c50a037c */ 	lwc1	$f10,0x37c($t0)
/*  f0bfa70:	c5060384 */ 	lwc1	$f6,0x384($t0)
/*  f0bfa74:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f0bfa78:	46062381 */ 	sub.s	$f14,$f4,$f6
/*  f0bfa7c:	e7ac00d8 */ 	swc1	$f12,0xd8($sp)
/*  f0bfa80:	0fc25970 */ 	jal	atan2f
/*  f0bfa84:	e7ae00d4 */ 	swc1	$f14,0xd4($sp)
/*  f0bfa88:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfa8c:	c436f3a8 */ 	lwc1	$f22,-0xc58($at)
/*  f0bfa90:	44809000 */ 	mtc1	$zero,$f18
/*  f0bfa94:	46000506 */ 	mov.s	$f20,$f0
/*  f0bfa98:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0bfa9c:	00000000 */ 	nop
/*  f0bfaa0:	45020003 */ 	bc1fl	.PB0f0bfab0
/*  f0bfaa4:	4612a03c */ 	c.lt.s	$f20,$f18
/*  f0bfaa8:	46160501 */ 	sub.s	$f20,$f0,$f22
/*  f0bfaac:	4612a03c */ 	c.lt.s	$f20,$f18
.PB0f0bfab0:
/*  f0bfab0:	00000000 */ 	nop
/*  f0bfab4:	45020003 */ 	bc1fl	.PB0f0bfac4
/*  f0bfab8:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfabc:	4616a500 */ 	add.s	$f20,$f20,$f22
/*  f0bfac0:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfac4:
/*  f0bfac4:	c50c036c */ 	lwc1	$f12,0x36c($t0)
/*  f0bfac8:	0fc25970 */ 	jal	atan2f
/*  f0bfacc:	c50e0374 */ 	lwc1	$f14,0x374($t0)
/*  f0bfad0:	4600b03c */ 	c.lt.s	$f22,$f0
/*  f0bfad4:	44804000 */ 	mtc1	$zero,$f8
/*  f0bfad8:	46000086 */ 	mov.s	$f2,$f0
/*  f0bfadc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfae0:	45020003 */ 	bc1fl	.PB0f0bfaf0
/*  f0bfae4:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0bfae8:	46160081 */ 	sub.s	$f2,$f0,$f22
/*  f0bfaec:	4608103c */ 	c.lt.s	$f2,$f8
.PB0f0bfaf0:
/*  f0bfaf0:	00000000 */ 	nop
/*  f0bfaf4:	45020003 */ 	bc1fl	.PB0f0bfb04
/*  f0bfaf8:	46141301 */ 	sub.s	$f12,$f2,$f20
/*  f0bfafc:	46161080 */ 	add.s	$f2,$f2,$f22
/*  f0bfb00:	46141301 */ 	sub.s	$f12,$f2,$f20
.PB0f0bfb04:
/*  f0bfb04:	c42ef3ac */ 	lwc1	$f14,-0xc54($at)
/*  f0bfb08:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfb0c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0bfb10:	46006006 */ 	mov.s	$f0,$f12
/*  f0bfb14:	45000002 */ 	bc1f	.PB0f0bfb20
/*  f0bfb18:	00000000 */ 	nop
/*  f0bfb1c:	46166001 */ 	sub.s	$f0,$f12,$f22
.PB0f0bfb20:
/*  f0bfb20:	c42af3b0 */ 	lwc1	$f10,-0xc50($at)
/*  f0bfb24:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfb28:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0bfb2c:	00000000 */ 	nop
/*  f0bfb30:	45020003 */ 	bc1fl	.PB0f0bfb40
/*  f0bfb34:	460e0103 */ 	div.s	$f4,$f0,$f14
/*  f0bfb38:	46160000 */ 	add.s	$f0,$f0,$f22
/*  f0bfb3c:	460e0103 */ 	div.s	$f4,$f0,$f14
.PB0f0bfb40:
/*  f0bfb40:	44803000 */ 	mtc1	$zero,$f6
/*  f0bfb44:	00000000 */ 	nop
/*  f0bfb48:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0bfb4c:	00000000 */ 	nop
/*  f0bfb50:	45020006 */ 	bc1fl	.PB0f0bfb6c
/*  f0bfb54:	44811000 */ 	mtc1	$at,$f2
/*  f0bfb58:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0bfb5c:	44811000 */ 	mtc1	$at,$f2
/*  f0bfb60:	10000004 */ 	b	.PB0f0bfb74
/*  f0bfb64:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfb68:	44811000 */ 	mtc1	$at,$f2
.PB0f0bfb6c:
/*  f0bfb6c:	00000000 */ 	nop
/*  f0bfb70:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfb74:
/*  f0bfb74:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfb78:	8d0e1bac */ 	lw	$t6,0x1bac($t0)
/*  f0bfb7c:	448e9000 */ 	mtc1	$t6,$f18
/*  f0bfb80:	00000000 */ 	nop
/*  f0bfb84:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0bfb88:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0bfb8c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0bfb90:	440f2000 */ 	mfc1	$t7,$f4
/*  f0bfb94:	00000000 */ 	nop
/*  f0bfb98:	ad0f1bd8 */ 	sw	$t7,0x1bd8($t0)
/*  f0bfb9c:	c426f3b4 */ 	lwc1	$f6,-0xc4c($at)
/*  f0bfba0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfba4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0bfba8:	00000000 */ 	nop
/*  f0bfbac:	4503000e */ 	bc1tl	.PB0f0bfbe8
/*  f0bfbb0:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfbb4:	c432f3b8 */ 	lwc1	$f18,-0xc48($at)
/*  f0bfbb8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0bfbbc:	00000000 */ 	nop
/*  f0bfbc0:	45030009 */ 	bc1tl	.PB0f0bfbe8
/*  f0bfbc4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfbc8:	8e690284 */ 	lw	$t1,0x284($s3)
/*  f0bfbcc:	ad201bd8 */ 	sw	$zero,0x1bd8($t1)
/*  f0bfbd0:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfbd4:	850a1baa */ 	lh	$t2,0x1baa($t0)
/*  f0bfbd8:	55400003 */ 	bnezl	$t2,.PB0f0bfbe8
/*  f0bfbdc:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfbe0:	ad001bac */ 	sw	$zero,0x1bac($t0)
/*  f0bfbe4:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfbe8:
/*  f0bfbe8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0bfbec:	44814000 */ 	mtc1	$at,$f8
/*  f0bfbf0:	c5020154 */ 	lwc1	$f2,0x154($t0)
/*  f0bfbf4:	4608103e */ 	c.le.s	$f2,$f8
/*  f0bfbf8:	00000000 */ 	nop
/*  f0bfbfc:	4502000d */ 	bc1fl	.PB0f0bfc34
/*  f0bfc00:	85021baa */ 	lh	$v0,0x1baa($t0)
/*  f0bfc04:	850c1ba6 */ 	lh	$t4,0x1ba6($t0)
/*  f0bfc08:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0bfc0c:	44813000 */ 	mtc1	$at,$f6
/*  f0bfc10:	448c5000 */ 	mtc1	$t4,$f10
/*  f0bfc14:	00000000 */ 	nop
/*  f0bfc18:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0bfc1c:	46062483 */ 	div.s	$f18,$f4,$f6
/*  f0bfc20:	46169202 */ 	mul.s	$f8,$f18,$f22
/*  f0bfc24:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0bfc28:	e50a0154 */ 	swc1	$f10,0x154($t0)
/*  f0bfc2c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfc30:	85021baa */ 	lh	$v0,0x1baa($t0)
.PB0f0bfc34:
/*  f0bfc34:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0bfc38:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfc3c:	10400015 */ 	beqz	$v0,.PB0f0bfc94
/*  f0bfc40:	00000000 */ 	nop
/*  f0bfc44:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0bfc48:	c7a000d4 */ 	lwc1	$f0,0xd4($sp)
/*  f0bfc4c:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0bfc50:	0c012ae4 */ 	jal	sqrtf
/*  f0bfc54:	46123300 */ 	add.s	$f12,$f6,$f18
/*  f0bfc58:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfc5c:	e7a000d8 */ 	swc1	$f0,0xd8($sp)
/*  f0bfc60:	850b1ba8 */ 	lh	$t3,0x1ba8($t0)
/*  f0bfc64:	448b4000 */ 	mtc1	$t3,$f8
/*  f0bfc68:	00000000 */ 	nop
/*  f0bfc6c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0bfc70:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0bfc74:	00000000 */ 	nop
/*  f0bfc78:	45000004 */ 	bc1f	.PB0f0bfc8c
/*  f0bfc7c:	00000000 */ 	nop
/*  f0bfc80:	0fc2e693 */ 	jal	playerSetTickMode
/*  f0bfc84:	24040001 */ 	li	$a0,0x1
/*  f0bfc88:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfc8c:
/*  f0bfc8c:	10000010 */ 	b	.PB0f0bfcd0
/*  f0bfc90:	85021baa */ 	lh	$v0,0x1baa($t0)
.PB0f0bfc94:
/*  f0bfc94:	c424f3bc */ 	lwc1	$f4,-0xc44($at)
/*  f0bfc98:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0bfc9c:	4600203e */ 	c.le.s	$f4,$f0
/*  f0bfca0:	00000000 */ 	nop
/*  f0bfca4:	4502000b */ 	bc1fl	.PB0f0bfcd4
/*  f0bfca8:	850d1ba8 */ 	lh	$t5,0x1ba8($t0)
/*  f0bfcac:	c426f3c0 */ 	lwc1	$f6,-0xc40($at)
/*  f0bfcb0:	4606003e */ 	c.le.s	$f0,$f6
/*  f0bfcb4:	00000000 */ 	nop
/*  f0bfcb8:	45020006 */ 	bc1fl	.PB0f0bfcd4
/*  f0bfcbc:	850d1ba8 */ 	lh	$t5,0x1ba8($t0)
/*  f0bfcc0:	0fc2e693 */ 	jal	playerSetTickMode
/*  f0bfcc4:	24040001 */ 	li	$a0,0x1
/*  f0bfcc8:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfccc:	85021baa */ 	lh	$v0,0x1baa($t0)
.PB0f0bfcd0:
/*  f0bfcd0:	850d1ba8 */ 	lh	$t5,0x1ba8($t0)
.PB0f0bfcd4:
/*  f0bfcd4:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f0bfcd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfcdc:	448d9000 */ 	mtc1	$t5,$f18
/*  f0bfce0:	44811000 */ 	mtc1	$at,$f2
/*  f0bfce4:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0bfce8:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0bfcec:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0bfcf0:	00000000 */ 	nop
/*  f0bfcf4:	4502000f */ 	bc1fl	.PB0f0bfd34
/*  f0bfcf8:	44824000 */ 	mtc1	$v0,$f8
/*  f0bfcfc:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0bfd00:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f0bfd04:	45020005 */ 	bc1fl	.PB0f0bfd1c
/*  f0bfd08:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0bfd0c:	44801000 */ 	mtc1	$zero,$f2
/*  f0bfd10:	10000008 */ 	b	.PB0f0bfd34
/*  f0bfd14:	44824000 */ 	mtc1	$v0,$f8
/*  f0bfd18:	46002181 */ 	sub.s	$f6,$f4,$f0
.PB0f0bfd1c:
/*  f0bfd1c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0bfd20:	44816000 */ 	mtc1	$at,$f12
/*  f0bfd24:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f0bfd28:	460c9282 */ 	mul.s	$f10,$f18,$f12
/*  f0bfd2c:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f0bfd30:	44824000 */ 	mtc1	$v0,$f8
.PB0f0bfd34:
/*  f0bfd34:	24040001 */ 	li	$a0,0x1
/*  f0bfd38:	24050001 */ 	li	$a1,0x1
/*  f0bfd3c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0bfd40:	00003025 */ 	move	$a2,$zero
/*  f0bfd44:	24070001 */ 	li	$a3,0x1
/*  f0bfd48:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0bfd4c:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0bfd50:	440e9000 */ 	mfc1	$t6,$f18
/*  f0bfd54:	0fc3303a */ 	jal	bmoveTick
/*  f0bfd58:	ad0e1bdc */ 	sw	$t6,0x1bdc($t0)
/*  f0bfd5c:	0fc2f60c */ 	jal	playerUpdateShake
/*  f0bfd60:	00000000 */ 	nop
/*  f0bfd64:	0fc3072a */ 	jal	playerSetCameraMode
/*  f0bfd68:	00002025 */ 	move	$a0,$zero
/*  f0bfd6c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfd70:	8d0300bc */ 	lw	$v1,0xbc($t0)
/*  f0bfd74:	2504037c */ 	addiu	$a0,$t0,0x37c
/*  f0bfd78:	25050394 */ 	addiu	$a1,$t0,0x394
/*  f0bfd7c:	24790028 */ 	addiu	$t9,$v1,0x28
/*  f0bfd80:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0bfd84:	25060388 */ 	addiu	$a2,$t0,0x388
/*  f0bfd88:	0fc3072e */ 	jal	player0f0c1840
/*  f0bfd8c:	24670008 */ 	addiu	$a3,$v1,0x8
.PB0f0bfd90:
/*  f0bfd90:	0fc48074 */ 	jal	debug0f11990cnb
/*  f0bfd94:	00000000 */ 	nop
/*  f0bfd98:	50400004 */ 	beqzl	$v0,.PB0f0bfdac
/*  f0bfd9c:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfda0:	0fc480b6 */ 	jal	debug0f119a14nb
/*  f0bfda4:	00000000 */ 	nop
/*  f0bfda8:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfdac:
/*  f0bfdac:	c6680010 */ 	lwc1	$f8,0x10($s3)
/*  f0bfdb0:	3c118007 */ 	lui	$s1,0x8007
/*  f0bfdb4:	c50a1b80 */ 	lwc1	$f10,0x1b80($t0)
/*  f0bfdb8:	2631241c */ 	addiu	$s1,$s1,0x241c
/*  f0bfdbc:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0bfdc0:	e5041b80 */ 	swc1	$f4,0x1b80($t0)
/*  f0bfdc4:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0bfdc8:	11e00047 */ 	beqz	$t7,.PB0f0bfee8
/*  f0bfdcc:	00000000 */ 	nop
/*  f0bfdd0:	8e690288 */ 	lw	$t1,0x288($s3)
/*  f0bfdd4:	0fc54ebe */ 	jal	optionsGetContpadNum1
/*  f0bfdd8:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0bfddc:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0bfde0:	00105603 */ 	sra	$t2,$s0,0x18
/*  f0bfde4:	0fc5b9b8 */ 	jal	lvIsPaused
/*  f0bfde8:	01408025 */ 	move	$s0,$t2
/*  f0bfdec:	1440002c */ 	bnez	$v0,.PB0f0bfea0
/*  f0bfdf0:	8fac0330 */ 	lw	$t4,0x330($sp)
/*  f0bfdf4:	1180002a */ 	beqz	$t4,.PB0f0bfea0
/*  f0bfdf8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f0bfdfc:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0bfe00:	01602025 */ 	move	$a0,$t3
/*  f0bfe04:	0c00569a */ 	jal	joyGetButtonsPressedThisFrame
/*  f0bfe08:	3405f030 */ 	li	$a1,0xf030
/*  f0bfe0c:	10400024 */ 	beqz	$v0,.PB0f0bfea0
/*  f0bfe10:	240d0002 */ 	li	$t5,0x2
/*  f0bfe14:	0fc2ee13 */ 	jal	playerIsFadeComplete
/*  f0bfe18:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f0bfe1c:	50400016 */ 	beqzl	$v0,.PB0f0bfe78
/*  f0bfe20:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfe24:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f0bfe28:	44800000 */ 	mtc1	$zero,$f0
/*  f0bfe2c:	00002025 */ 	move	$a0,$zero
/*  f0bfe30:	c70602e4 */ 	lwc1	$f6,0x2e4($t8)
/*  f0bfe34:	00002825 */ 	move	$a1,$zero
/*  f0bfe38:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0bfe3c:	00000000 */ 	nop
/*  f0bfe40:	45020018 */ 	bc1fl	.PB0f0bfea4
/*  f0bfe44:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0bfe48:	44070000 */ 	mfc1	$a3,$f0
/*  f0bfe4c:	0fc2eddc */ 	jal	playerSetFadeColour
/*  f0bfe50:	00003025 */ 	move	$a2,$zero
/*  f0bfe54:	3c014270 */ 	lui	$at,0x4270
/*  f0bfe58:	44816000 */ 	mtc1	$at,$f12
/*  f0bfe5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfe60:	44817000 */ 	mtc1	$at,$f14
/*  f0bfe64:	0fc2ee06 */ 	jal	playerSetFadeFrac
/*  f0bfe68:	00000000 */ 	nop
/*  f0bfe6c:	1000000d */ 	b	.PB0f0bfea4
/*  f0bfe70:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0bfe74:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bfe78:
/*  f0bfe78:	44809000 */ 	mtc1	$zero,$f18
/*  f0bfe7c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfe80:	c50a030c */ 	lwc1	$f10,0x30c($t0)
/*  f0bfe84:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0bfe88:	00000000 */ 	nop
/*  f0bfe8c:	45020005 */ 	bc1fl	.PB0f0bfea4
/*  f0bfe90:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0bfe94:	44817000 */ 	mtc1	$at,$f14
/*  f0bfe98:	0fc2ee06 */ 	jal	playerSetFadeFrac
/*  f0bfe9c:	c50c02e8 */ 	lwc1	$f12,0x2e8($t0)
.PB0f0bfea0:
/*  f0bfea0:	8e2e0000 */ 	lw	$t6,0x0($s1)
.PB0f0bfea4:
/*  f0bfea4:	24010002 */ 	li	$at,0x2
/*  f0bfea8:	15c1000f */ 	bne	$t6,$at,.PB0f0bfee8
/*  f0bfeac:	00000000 */ 	nop
/*  f0bfeb0:	0fc2ee13 */ 	jal	playerIsFadeComplete
/*  f0bfeb4:	00000000 */ 	nop
/*  f0bfeb8:	1040000b */ 	beqz	$v0,.PB0f0bfee8
/*  f0bfebc:	00000000 */ 	nop
/*  f0bfec0:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f0bfec4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0bfec8:	44814000 */ 	mtc1	$at,$f8
/*  f0bfecc:	c72402e4 */ 	lwc1	$f4,0x2e4($t9)
/*  f0bfed0:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0bfed4:	00000000 */ 	nop
/*  f0bfed8:	45000003 */ 	bc1f	.PB0f0bfee8
/*  f0bfedc:	00000000 */ 	nop
/*  f0bfee0:	0c003a71 */ 	jal	func0000e990
/*  f0bfee4:	00000000 */ 	nop
.PB0f0bfee8:
/*  f0bfee8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0bfeec:	8def2414 */ 	lw	$t7,0x2414($t7)
/*  f0bfef0:	51e00004 */ 	beqzl	$t7,.PB0f0bff04
/*  f0bfef4:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bfef8:	0fc2e698 */ 	jal	playerBeginGeFadeIn
/*  f0bfefc:	00000000 */ 	nop
/*  f0bff00:	8e680284 */ 	lw	$t0,0x284($s3)
.PB0f0bff04:
/*  f0bff04:	8d0900d8 */ 	lw	$t1,0xd8($t0)
/*  f0bff08:	51200035 */ 	beqzl	$t1,.PB0f0bffe0
/*  f0bff0c:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bff10:	8d02032c */ 	lw	$v0,0x32c($t0)
/*  f0bff14:	14400005 */ 	bnez	$v0,.PB0f0bff2c
/*  f0bff18:	00000000 */ 	nop
/*  f0bff1c:	0fc28b13 */ 	jal	bgun0f0a29c8
/*  f0bff20:	00000000 */ 	nop
/*  f0bff24:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f0bff28:	8d02032c */ 	lw	$v0,0x32c($t0)
.PB0f0bff2c:
/*  f0bff2c:	5040002c */ 	beqzl	$v0,.PB0f0bffe0
/*  f0bff30:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bff34:	8d0a0330 */ 	lw	$t2,0x330($t0)
/*  f0bff38:	51400029 */ 	beqzl	$t2,.PB0f0bffe0
/*  f0bff3c:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bff40:	8e6c0314 */ 	lw	$t4,0x314($s3)
/*  f0bff44:	55800006 */ 	bnezl	$t4,.PB0f0bff60
/*  f0bff48:	8e6b0298 */ 	lw	$t3,0x298($s3)
/*  f0bff4c:	0c0039ae */ 	jal	mainEndStage
/*  f0bff50:	00000000 */ 	nop
/*  f0bff54:	10000022 */ 	b	.PB0f0bffe0
/*  f0bff58:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bff5c:	8e6b0298 */ 	lw	$t3,0x298($s3)
.PB0f0bff60:
/*  f0bff60:	05620017 */ 	bltzl	$t3,.PB0f0bffc0
/*  f0bff64:	8e6f029c */ 	lw	$t7,0x29c($s3)
/*  f0bff68:	8e6d02a0 */ 	lw	$t5,0x2a0($s3)
/*  f0bff6c:	15a8000f */ 	bne	$t5,$t0,.PB0f0bffac
/*  f0bff70:	00000000 */ 	nop
/*  f0bff74:	8e6202a4 */ 	lw	$v0,0x2a4($s3)
/*  f0bff78:	8c5800d8 */ 	lw	$t8,0xd8($v0)
/*  f0bff7c:	1300000b */ 	beqz	$t8,.PB0f0bffac
/*  f0bff80:	00000000 */ 	nop
/*  f0bff84:	8c4e032c */ 	lw	$t6,0x32c($v0)
/*  f0bff88:	11c00008 */ 	beqz	$t6,.PB0f0bffac
/*  f0bff8c:	00000000 */ 	nop
/*  f0bff90:	8c590330 */ 	lw	$t9,0x330($v0)
/*  f0bff94:	13200005 */ 	beqz	$t9,.PB0f0bffac
/*  f0bff98:	00000000 */ 	nop
/*  f0bff9c:	0c0039ae */ 	jal	mainEndStage
/*  f0bffa0:	00000000 */ 	nop
/*  f0bffa4:	1000000e */ 	b	.PB0f0bffe0
/*  f0bffa8:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
.PB0f0bffac:
/*  f0bffac:	0fc125da */ 	jal	chrsClearRefsToPlayer
/*  f0bffb0:	8e64028c */ 	lw	$a0,0x28c($s3)
/*  f0bffb4:	1000000a */ 	b	.PB0f0bffe0
/*  f0bffb8:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bffbc:	8e6f029c */ 	lw	$t7,0x29c($s3)
.PB0f0bffc0:
/*  f0bffc0:	05e20007 */ 	bltzl	$t7,.PB0f0bffe0
/*  f0bffc4:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bffc8:	8e6902a0 */ 	lw	$t1,0x2a0($s3)
/*  f0bffcc:	55280004 */ 	bnel	$t1,$t0,.PB0f0bffe0
/*  f0bffd0:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
/*  f0bffd4:	0c0039ae */ 	jal	mainEndStage
/*  f0bffd8:	00000000 */ 	nop
/*  f0bffdc:	8e6a02ac */ 	lw	$t2,0x2ac($s3)
.PB0f0bffe0:
/*  f0bffe0:	24010005 */ 	li	$at,0x5
/*  f0bffe4:	55410008 */ 	bnel	$t2,$at,.PB0f0c0008
/*  f0bffe8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bffec:	0fc2ee13 */ 	jal	playerIsFadeComplete
/*  f0bfff0:	00000000 */ 	nop
/*  f0bfff4:	50400004 */ 	beqzl	$v0,.PB0f0c0008
/*  f0bfff8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0bfffc:	0c0039ae */ 	jal	mainEndStage
/*  f0c0000:	00000000 */ 	nop
/*  f0c0004:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PB0f0c0008:
/*  f0c0008:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0c000c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0c0010:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0c0014:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0c0018:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0c001c:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0c0020:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0c0024:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0c0028:	03e00008 */ 	jr	$ra
/*  f0c002c:	27bd0330 */ 	addiu	$sp,$sp,0x330
);
#else
void playerTick(bool arg0)
{
	f32 aspectratio;
	f32 f20;

	g_ViRes = g_HiResEnabled;

	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() > 1) {
		g_ViRes = VIRES_LO;
	}

#if PAL
	func0f1531dc(false);
#else
	if (g_ViRes == VIRES_HI) {
		func0f1531dc(true);
	} else {
		func0f1531dc(false);
	}
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

	if ((g_Vars.tickmode == TICKMODE_GE_FADEIN || g_Vars.tickmode == TICKMODE_NORMAL) && !g_InCutscene && !g_MainIsEndscreen) {
		g_Vars.currentplayer->bondviewlevtime60 += g_Vars.lvupdate240_60;
	}

	if (g_Vars.currentplayer->devicesactive & DEVICE_SUICIDEPILL) {
		playerDieByShooter(g_Vars.currentplayernum, true);
	}

	playerTickDamageAndHealth();
	playerTickExplode();

	if (g_Vars.currentplayer->eyespy) {
		// The stage uses an eyespy
		struct eyespy *eyespy = g_Vars.currentplayer->eyespy;
		u32 playernum = g_Vars.currentplayernum;

		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
			// Turn off the eyespy if active
			struct chrdata *chr = eyespy->prop->chr;
			eyespy->deployed = false;
			eyespy->held = true;
			eyespy->active = false;
			func0f0926bc(eyespy->prop, 1, 0xffff);
			chr->chrflags |= CHRCFLAG_HIDDEN;
			chr->chrflags |= CHRCFLAG_INVINCIBLE;
			g_Vars.currentplayer->devicesactive &= ~DEVICE_EYESPY;
		} else {
			if (eyespy->held == false) {
				// Eyespy is deployed
#if VERSION >= VERSION_NTSC_1_0
				if (g_Vars.currentplayer->eyespy->active) {
					// And is being controlled
					s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
					u16 buttons = arg0 ? joyGetButtons(contpad1, 0xffff) : 0;

					if (g_Vars.currentplayer->isdead == false
							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
							&& (buttons & START_BUTTON)) {
						if (g_Vars.mplayerisrunning == false) {
							playerPause(MENUROOT_MAINMENU);
						} else {
							mpPushPauseDialog();
						}
					}
				}
#endif

				if (g_Vars.lvupdate240) {
					eyespyProcessInput(arg0);
				}
			} else {
				// Eyespy is held
				// If eyespy is activated, launch it
				if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
						&& g_PlayersWithControl[playernum]
						&& !eyespyTryLaunch()) {
					// Launch failed
					eyespy->held = true;
					eyespy->active = false;
					g_Vars.currentplayer->devicesactive &= ~DEVICE_EYESPY;
				}
			}

			if (eyespy->deployed
					&& g_PlayersWithControl[playernum]
					&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)) {
				// Eyespy is being controlled
				if (eyespy->active == false) {
					// Eyespy is being turned off
					eyespy->active = true;
					eyespy->buttonheld = eyespy->camerabuttonheld = false;
					eyespy->camerashuttertime = 0;
					eyespy->startuptimer60 = 0;
					eyespy->prop->chr->soundtimer = TICKS(10);
					sndStart(var80095200, SFX_DETONATE, NULL, -1, -1, -1, -1, -1);
				}

				g_Vars.currentplayer->invdowntime = TICKS(-40);
			}
		}
	}

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

	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		g_InCutscene = false;
	}

	if (g_Vars.tickmode == (u32)TICKMODE_CUTSCENE) {
		// In a cutscene
		s32 i;

		playerTickChrBody();

		if (g_Vars.currentplayer->haschrbody) {
			g_Vars.currentplayer->invdowntime = TICKS(-40);
			bmoveTick(0, 0, 0, 1);
			playerTickCutscene(arg0);
			g_Vars.currentplayer->invdowntime = TICKS(-40);
		}

		for (i = 0; i < PLAYERCOUNT(); i++) {
			g_Vars.players[i]->joybutinhibit = 0xffffffff;
		}
	} else if (g_Vars.currentplayer->eyespy
			&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
			&& g_Vars.currentplayer->eyespy->active) {
		// Controlling an eyespy
		struct coord sp308;
		playermgrSetFovY(120);
		viSetFovY(120);
		sp308.x = g_Vars.currentplayer->eyespy->prop->pos.x;
		sp308.y = g_Vars.currentplayer->eyespy->prop->pos.y;
		sp308.z = g_Vars.currentplayer->eyespy->prop->pos.z;
		playerTickChrBody();
		bmoveTick(0, 0, 0, 1);
		playerSetCameraMode(CAMERAMODE_EYESPY);
		player0f0c1bd8(&sp308, &g_Vars.currentplayer->eyespy->up, &g_Vars.currentplayer->eyespy->look);
	} else if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
		// Deep Sea teleport
		playerTickChrBody();
		g_WarpPadId = g_Vars.currentplayer->teleportcamerapad;
		bmoveTick(0, 0, 0, 1);
		playerExecutePreparedWarp();
	} else if (g_Vars.currentplayer->visionmode == (u32)VISIONMODE_SLAYERROCKET) {
		// Controlling a Slayer rocket
		struct coord sp2fc = {0, 0, 0};
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
			s16 rooms[21];
			bool outofbounds = false;
			s16 sp250[20];
			s16 sp24e;

			sp2b8[0][0] = rocket->base.realrot[0][0] / sp2a8;
			sp2b8[0][1] = rocket->base.realrot[0][1] / sp2a8;
			sp2b8[0][2] = rocket->base.realrot[0][2] / sp2a8;
			sp2b8[1][0] = rocket->base.realrot[1][0] / sp2a8;
			sp2b8[1][1] = rocket->base.realrot[1][1] / sp2a8;
			sp2b8[1][2] = rocket->base.realrot[1][2] / sp2a8;
			sp2b8[2][0] = rocket->base.realrot[2][0] / sp2a8;
			sp2b8[2][1] = rocket->base.realrot[2][1] / sp2a8;
			sp2b8[2][2] = rocket->base.realrot[2][2] / sp2a8;

			sp2fc.x = rocket->base.prop->pos.x;
			sp2fc.y = rocket->base.prop->pos.y;
			sp2fc.z = rocket->base.prop->pos.z;

			func0f162194(&sp2fc, rooms, sp250, 20, &sp24e);

			if (rooms[0] == -1) {
				outofbounds = true;
			}

			if (outofbounds) {
				// Slayer rocket has flown out of bounds
				// Allow 2 seconds of this, then blow up rocket
				g_Vars.currentplayer->badrockettime += g_Vars.lvupdate240_60;

				if (g_Vars.currentplayer->badrockettime > TICKS(120)) {
#if VERSION >= VERSION_NTSC_1_0
					g_Vars.currentplayer->visionmode = VISIONMODE_SLAYERROCKETSTATIC;
#else
					g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
#endif
				}
			} else if (g_Vars.currentplayer->badrockettime > 0) {
				// Slayer rocket is in bounds, but was recently out
				g_Vars.currentplayer->badrockettime -= g_Vars.lvupdate240_60;

				if (g_Vars.currentplayer->badrockettime < 0) {
					g_Vars.currentplayer->badrockettime = 0;
				}
			}

			mtx00016208(sp2b8, &sp2f0);
			mtx00016208(sp2b8, &sp2e4);

			if (rocket->base.hidden & OBJHFLAG_AIRBORNE) {
				struct projectile *projectile = rocket->base.projectile;
				u32 mode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
				f32 fVar22;
				s8 contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
				s8 contpad2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
				s8 stickx = 0;
				s8 sticky = 0;
				Mtxf sp1fc;
				Mtxf sp1bc;
				Mtxf sp17c;
				f32 targetspeed;
				f32 sp174;
				f32 sp15c[6];
				f32 sp14c[4];
				f32 sp13c[4];
				f32 sp12c[4];
				f32 prevspeed;
				f32 sp11c[3];
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

							if (joyGetButtons(contpad1, B_BUTTON | Z_TRIG | L_TRIG | R_TRIG)) {
								slow = true;
							}
						} else {
							if (joyGetButtonsPressedThisFrame(contpad1, Z_TRIG)) {
								explode = true;
							}

							if (joyGetButtons(contpad1, A_BUTTON | B_BUTTON | L_TRIG | R_TRIG)) {
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

#if VERSION >= VERSION_PAL_FINAL
				fVar22 = sticky * g_Vars.lvupdate240freal * 0.00025f;
				sp174 = -stickx * g_Vars.lvupdate240freal * 0.00025f;
#else
				fVar22 = sticky * g_Vars.lvupdate240f * 0.00025f;
				sp174 = -stickx * g_Vars.lvupdate240f * 0.00025f;
#endif

				f20 = sqrtf(sp2ac.f[0] * sp2ac.f[0] + sp2ac.f[2] * sp2ac.f[2]);

				sp2ac.x /= f20;
				sp2ac.z /= f20;

				f20 = sinf(fVar22);

				sp14c[0] = cosf(fVar22);
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

				projectile->unk0b2 = 0xffff;
				projectile->flags |= PROJECTILEFLAG_00004000;
				projectile->unk018 = 0;
				projectile->unk014 = 0;
				projectile->unk010 = 0;

				if ((projectile->flags & PROJECTILEFLAG_00000080) == 0) {
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
#if VERSION >= VERSION_PAL_FINAL
					newspeed = prevspeed + 0.05f * g_Vars.lvupdate240freal;
#else
					newspeed = prevspeed + 0.05f * g_Vars.lvupdate240f;
#endif

					if (newspeed > targetspeed) {
						newspeed = targetspeed;
					}
				} else if (prevspeed > targetspeed) {
#if VERSION >= VERSION_PAL_FINAL
					newspeed = prevspeed - 0.05f * g_Vars.lvupdate240freal;
#else
					newspeed = prevspeed - 0.05f * g_Vars.lvupdate240f;
#endif

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
			player0f0c1840(&sp2fc, &sp2e4, &sp2f0, &rocket->base.prop->pos, rocket->base.prop->rooms);
		} else {
			player0f0c1840(&sp2fc, &sp2e4, &sp2f0, NULL, NULL);
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

		player0f0b9538();

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

		if (g_Vars.normmplayerisrunning == false
				&& g_MissionConfig.iscoop
				&& g_Vars.numaibuddies > 0
				&& !g_Vars.aibuddiesspawned
				&& g_Vars.stagenum != STAGE_CITRAINING
				&& g_Vars.lvframenum > 20) {
			g_Vars.aibuddiesspawned = true;

			// Spawn coop bots
			for (i = 0; i < g_Vars.numaibuddies; i++) {
				prop = NULL;

				// If no buddy cheats are active, spawn Velvet
				if ((g_CheatsActiveBank0 & (
								1 << CHEAT_PUGILIST
								| 1 << CHEAT_HOTSHOT
								| 1 << CHEAT_HITANDRUN
								| 1 << CHEAT_ALIEN)) == 0) {
					if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
						prop = chrSpawnAtCoord(BODY_DARK_COMBAT, HEAD_VD,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta / 2),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else {
						prop = chrSpawnAtCoord(BODY_DARK_COMBAT, HEAD_VD,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta / 2),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					}

					if (prop) {
						chr = prop->chr;
						chr->flags |= CHRFLAG0_SKIPSAFETYCHECKS;
						chr->flags2 |= CHRFLAG1_IGNORECOVER | CHRFLAG1_NOOP_00200000 | CHRFLAG1_AIVSAI_ADVANTAGED;
						chr->team = TEAM_ALLY;
						chr->squadron = SQUADRON_01;
						chr->hidden |= CHRHFLAG_DETECTED;
						chr->voicebox = VOICEBOX_FEMALE;
						chr->teamscandist = 50;
						chr->accuracyrating = 100;
						chr->speedrating = 100;

						if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
							chrAddHealth(chr, 40);
						} else {
							chrAddHealth(chr, 20);
						}

						chrSetMaxDamage(chr, 4);

						chr->chrflags |= CHRCFLAG_00040000;
						chr->hidden |= CHRHFLAG_CLOAKED;
						chr->cloakfadefinished = true;
						chr->cloakfadefrac = 0;

						chrGiveWeapon(chr, MODEL_CHRFALCON2, WEAPON_FALCON2, 0);
					}
				}

				if (cheatIsActive(CHEAT_PUGILIST)) {
					if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else {
						prop = chrSpawnAtCoord(BODY_CARRINGTON, HEAD_JAMIE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_PUGILIST_BUDDY),
								SPAWNFLAG_00000010);
					}

					if (prop) {
						chr = prop->chr;
						chr->flags |= CHRFLAG0_SKIPSAFETYCHECKS | CHRFLAG0_CHUCKNORRIS;
						chr->flags2 |= CHRFLAG1_IGNORECOVER | CHRFLAG1_NOOP_00200000 | CHRFLAG1_AIVSAI_ADVANTAGED | CHRFLAG1_ADJUSTPUNCHSPEED | CHRFLAG1_HANDCOMBATONLY;
						chr->team = TEAM_ALLY;
						chr->squadron = SQUADRON_01;
						chr->teamscandist = 100;
						chr->hidden |= CHRHFLAG_DETECTED;
						chr->voicebox = VOICEBOX_MALE1;
						chr->accuracyrating = 100;
						chr->speedrating = 100;

						if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
							chrAddHealth(chr, 40);
						} else {
							chrAddHealth(chr, 20);
						}

						chr->chrflags |= CHRCFLAG_00040000;
						chr->hidden |= CHRHFLAG_CLOAKED;
						chr->cloakfadefinished = true;
						chr->cloakfadefrac = 0;

						chrSetMaxDamage(chr, 20);
					}
				}

				if (cheatIsActive(CHEAT_HITANDRUN)) {
					if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MARK2,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					}

					if (prop) {
						chr = prop->chr;
						chr->flags |= CHRFLAG0_SKIPSAFETYCHECKS;
						chr->flags2 |= CHRFLAG1_PUNCHHARDER | CHRFLAG1_NOOP_00200000 | CHRFLAG1_AIVSAI_ADVANTAGED;
						chr->team = TEAM_ALLY;
						chr->squadron = SQUADRON_01;
						chr->hidden |= CHRHFLAG_DETECTED;
						chr->voicebox = VOICEBOX_MALE2;
						chr->teamscandist = 50;
						chr->accuracyrating = 50;
						chr->speedrating = 100;

						if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
							chrAddHealth(chr, 20);
						} else {
							chrAddHealth(chr, 10);
						}

						chrSetMaxDamage(chr, 10);

						chr->chrflags |= CHRCFLAG_00040000;
						chr->hidden |= CHRHFLAG_CLOAKED;
						chr->cloakfadefinished = true;
						chr->cloakfadefrac = 0;

						chrGiveWeapon(chr, MODEL_CHRAVENGER, WEAPON_K7AVENGER, 0);
					}
				}

				if (cheatIsActive(CHEAT_HOTSHOT)) {
					if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else {
						prop = chrSpawnAtCoord(BODY_CISOLDIER, HEAD_CHRIST,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					}

					if (prop) {
						chr = prop->chr;
						chr->flags |= CHRFLAG0_SKIPSAFETYCHECKS;
						chr->flags2 |= CHRFLAG1_IGNORECOVER | CHRFLAG1_NOOP_00200000 | CHRFLAG1_AIVSAI_ADVANTAGED;
						chr->team = TEAM_ALLY;
						chr->squadron = SQUADRON_01;
						chr->hidden |= CHRHFLAG_DETECTED;
						chr->voicebox = VOICEBOX_MALE0;
						chr->teamscandist = 100;
						chr->accuracyrating = 50;
						chr->speedrating = 100;

						if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
							chrAddHealth(chr, 40);
						} else {
							chrAddHealth(chr, 20);
						}

						chrSetMaxDamage(chr, 10);

						chr->chrflags |= CHRCFLAG_00040000;
						chr->hidden |= CHRHFLAG_CLOAKED;
						chr->cloakfadefinished = true;
						chr->cloakfadefrac = 0;

						chrGiveWeapon(chr, MODEL_CHRDY357TRENT, WEAPON_DY357LX, 0);
						chrGiveWeapon(chr, MODEL_CHRDY357, WEAPON_DY357MAGNUM, OBJFLAG_WEAPON_LEFTHANDED);
					}
				}

				if (cheatIsActive(CHEAT_ALIEN)) {
					if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR) {
						prop = chrSpawnAtCoord(BODY_MRBLONDE, HEAD_MRBLONDE,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					} else {
						prop = chrSpawnAtCoord(BODY_ELVIS1, HEAD_MAIAN_S,
								&g_Vars.currentplayer->prop->pos,
								g_Vars.currentplayer->prop->rooms,
								BADDEG2RAD(g_Vars.currentplayer->vv_theta),
								ailistFindById(GAILIST_INIT_DEFAULT_BUDDY),
								SPAWNFLAG_00000010);
					}

					if (prop) {
						chr = prop->chr;
						chr->flags |= CHRFLAG0_SKIPSAFETYCHECKS;
						chr->flags2 |= CHRFLAG1_PUNCHHARDER | CHRFLAG1_IGNORECOVER | CHRFLAG1_NOOP_00200000 | CHRFLAG1_AIVSAI_ADVANTAGED;
						chr->team = TEAM_ALLY;
						chr->squadron = SQUADRON_01;
						chr->hidden |= CHRHFLAG_DETECTED;
						chr->voicebox = VOICEBOX_MALE0;
						chr->teamscandist = 150;
						chr->accuracyrating = 100;
						chr->speedrating = 100;

						if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
							chrAddHealth(chr, 40);
						} else {
							chrAddHealth(chr, 20);
						}

						chrSetMaxDamage(chr, 10);

						chr->chrflags |= CHRCFLAG_00040000;
						chr->hidden |= CHRHFLAG_CLOAKED;
						chr->cloakfadefinished = true;
						chr->cloakfadefrac = 0;

						chrGiveWeapon(chr, MODEL_CHRRCP120, WEAPON_RCP120, 0);
					}
				}

				g_Vars.aibuddies[i] = prop;
			}
		}
	} else if (g_Vars.tickmode == TICKMODE_GE_FADEIN || g_Vars.tickmode == TICKMODE_GE_FADEOUT) {
		player0f0b9538();
		bmoveTick(1, 1, arg0, 0);
		playerUpdateShake();
		playerSetCameraMode(CAMERAMODE_DEFAULT);
		player0f0c1840(&g_Vars.currentplayer->bond2.unk10,
				&g_Vars.currentplayer->bond2.unk28,
				&g_Vars.currentplayer->bond2.unk1c,
				&g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms);
	} else if (g_Vars.tickmode == TICKMODE_MPSWIRL) {
		// Start of an MP match where the camera circles around the player
		playerTickChrBody();
		bmoveTick(0, 0, 0, 1);
		playerTickMpSwirl();
	} else if (g_Vars.tickmode == TICKMODE_WARP) {
		// Eg. In CI training, warping from device hallways
		// to device room at the end of a training session
		playerTickChrBody();
		bmoveTick(0, 0, 0, 1);
		playerExecutePreparedWarp();
	} else if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
		// Extraction bodyguard room and Duel
		f32 targetangle;
		f32 autodist;
		f32 oldangle;
		f32 xdist;
		f32 zdist;
		f32 diffangle;
		f32 direction;
		struct pad pad;
		f32 speedfrac;

		player0f0b9538();
		padUnpack(g_Vars.currentplayer->autocontrol_aimpad, PADFIELD_POS, &pad);

		if (mainGetStageNum() == g_Stages[STAGEINDEX_EXTRACTION].id
				&& g_Vars.currentplayer->autocontrol_aimpad == 0x19) {
			pad.pos.x -= 100;
		}

		xdist = pad.pos.x - g_Vars.currentplayer->bond2.unk10.x;
		zdist = pad.pos.z - g_Vars.currentplayer->bond2.unk10.z;
		targetangle = atan2f(xdist, zdist);

		if (targetangle > M_BADTAU) {
			targetangle -= M_BADTAU;
		}

		if (targetangle < 0) {
			targetangle += M_BADTAU;
		}

		oldangle = atan2f(g_Vars.currentplayer->bond2.unk00.x, g_Vars.currentplayer->bond2.unk00.z);

		if (oldangle > M_BADTAU) {
			oldangle -= M_BADTAU;
		}

		if (oldangle < 0) {
			oldangle += M_BADTAU;
		}

		diffangle = oldangle - targetangle;

		if (diffangle > M_PI) {
			diffangle -= M_BADTAU;
		}

		if (diffangle < -M_PI) {
			diffangle += M_BADTAU;
		}

		direction = (diffangle / M_PI < 0) ? -1 : 1;

		g_Vars.currentplayer->autocontrol_x = (f32)direction * g_Vars.currentplayer->autocontrol_turnspeed;

		if (!(diffangle < -0.09f || diffangle > 0.09f)) {
			// Facing the target
			g_Vars.currentplayer->autocontrol_x = 0;

			if (g_Vars.currentplayer->autocontrol_walkspeed == 0) {
				g_Vars.currentplayer->autocontrol_turnspeed = 0;
			}
		}

		if (g_Vars.currentplayer->vv_verta <= 30) {
			g_Vars.currentplayer->vv_verta += g_Vars.currentplayer->autocontrol_lookup / 360.0f * M_BADTAU;
		}

		if (g_Vars.currentplayer->autocontrol_walkspeed) {
			xdist = sqrtf(xdist * xdist + zdist * zdist);

			if (xdist < g_Vars.currentplayer->autocontrol_dist) {
				playerSetTickMode(TICKMODE_NORMAL);
			}
		} else {
			if (diffangle >= -0.2f && diffangle <= 0.2f) {
				playerSetTickMode(TICKMODE_NORMAL);
			}
		}

		autodist = g_Vars.currentplayer->autocontrol_dist;

		speedfrac = 1;

		if (xdist < autodist + autodist) {
			if (xdist < autodist) {
				speedfrac = 0;
			} else {
				speedfrac = 0.5f + (xdist - autodist) / autodist * 0.5f;
			}
		}

		g_Vars.currentplayer->autocontrol_y = g_Vars.currentplayer->autocontrol_walkspeed * speedfrac;
		bmoveTick(1, 1, 0, 1);
		playerUpdateShake();
		playerSetCameraMode(CAMERAMODE_DEFAULT);
		player0f0c1840(&g_Vars.currentplayer->bond2.unk10,
				&g_Vars.currentplayer->bond2.unk28,
				&g_Vars.currentplayer->bond2.unk1c,
				&g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms);
	}

#if VERSION < VERSION_NTSC_1_0
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
				&& joyGetButtonsPressedThisFrame(contpad1, A_BUTTON | B_BUTTON | Z_TRIG | START_BUTTON | L_TRIG | R_TRIG)) {
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
			bgun0f0a29c8();
		}

		if (g_Vars.currentplayer->redbloodfinished && g_Vars.currentplayer->deathanimfinished) {
			if (g_Vars.mplayerisrunning == false) {
				mainEndStage();
			} else if (g_Vars.coopplayernum >= 0) {
				if (g_Vars.currentplayer == g_Vars.bond
						&& g_Vars.coop->isdead
						&& g_Vars.coop->redbloodfinished
						&& g_Vars.coop->deathanimfinished) {
					mainEndStage();
				} else {
					chrsClearRefsToPlayer(g_Vars.currentplayernum);
				}
			} else if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.bond) {
				mainEndStage();
			}
		}
	}

	if (g_Vars.tickmode == TICKMODE_GE_FADEOUT && playerIsFadeComplete()) {
		mainEndStage();
	}
}
#endif

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
	func0f166df0(room, &g_Vars.currentplayer->globaldrawworldoffset);

	g_Vars.currentplayer->globaldrawworldbgoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawworldbgoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawworldbgoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	currentPlayerSetLastRoomForOffset(room);
}

void playerSetGlobalDrawCameraOffset(void)
{
	g_Vars.currentplayer->globaldrawcameraoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawcameraoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawcameraoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	mtx4RotateVecInPlace(currentPlayerGetMatrix1740(), &g_Vars.currentplayer->globaldrawcameraoffset);
}

GLOBAL_ASM(
glabel player0f0bfc7c
/*  f0bfc7c:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*  f0bfc80:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0bfc84:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0bfc88:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0bfc8c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0bfc90:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0bfc94:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0bfc98:	0fc5722e */ 	jal	currentPlayerGetScaleBg2Gfx
/*  f0bfc9c:	afa40110 */ 	sw	$a0,0x110($sp)
/*  f0bfca0:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0bfca4:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0bfca8:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0bfcac:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0bfcb0:	0fc2feee */ 	jal	playerSetGlobalDrawWorldOffset
/*  f0bfcb4:	8dc41ba0 */ 	lw	$a0,0x1ba0($t6)
/*  f0bfcb8:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfcbc:	00000000 */ 	nop
/*  f0bfcc0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0bfcc4:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfcc8:	ade2005c */ 	sw	$v0,0x5c($t7)
/*  f0bfccc:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0bfcd0:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfcd4:	af020060 */ 	sw	$v0,0x60($t8)
/*  f0bfcd8:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0bfcdc:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfce0:	af220064 */ 	sw	$v0,0x64($t9)
/*  f0bfce4:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0bfce8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0bfcec:	0fc59e6c */ 	jal	gfxAllocateLookAt
/*  f0bfcf0:	ad220068 */ 	sw	$v0,0x68($t1)
/*  f0bfcf4:	8fa80110 */ 	lw	$t0,0x110($sp)
/*  f0bfcf8:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f0bfcfc:	afa200cc */ 	sw	$v0,0xcc($sp)
/*  f0bfd00:	c5040000 */ 	lwc1	$f4,0x0($t0)
/*  f0bfd04:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f0bfd08:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f0bfd0c:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0bfd10:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0bfd14:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0bfd18:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f0bfd1c:	c5100004 */ 	lwc1	$f16,0x4($t0)
/*  f0bfd20:	c472003c */ 	lwc1	$f18,0x3c($v1)
/*  f0bfd24:	44055000 */ 	mfc1	$a1,$f10
/*  f0bfd28:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0bfd2c:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0bfd30:	e7a60078 */ 	swc1	$f6,0x78($sp)
/*  f0bfd34:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0bfd38:	c4700040 */ 	lwc1	$f16,0x40($v1)
/*  f0bfd3c:	44063000 */ 	mfc1	$a2,$f6
/*  f0bfd40:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0bfd44:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0bfd48:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0bfd4c:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0bfd50:	44072000 */ 	mfc1	$a3,$f4
/*  f0bfd54:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f0bfd58:	e7b00080 */ 	swc1	$f16,0x80($sp)
/*  f0bfd5c:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfd60:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0bfd64:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0bfd68:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f0bfd6c:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f0bfd70:	e7b20088 */ 	swc1	$f18,0x88($sp)
/*  f0bfd74:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f0bfd78:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bfd7c:	c6100004 */ 	lwc1	$f16,0x4($s0)
/*  f0bfd80:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0bfd84:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f0bfd88:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0bfd8c:	c62a0000 */ 	lwc1	$f10,0x0($s1)
/*  f0bfd90:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f0bfd94:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0bfd98:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0bfd9c:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f0bfda0:	0c005a1d */ 	jal	mtx00016874
/*  f0bfda4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0bfda8:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f0bfdac:	c7b00080 */ 	lwc1	$f16,0x80($sp)
/*  f0bfdb0:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f0bfdb4:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0bfdb8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0bfdbc:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0bfdc0:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0bfdc4:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f0bfdc8:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfdcc:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0bfdd0:	8fa500cc */ 	lw	$a1,0xcc($sp)
/*  f0bfdd4:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0bfdd8:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfddc:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0bfde0:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0bfde4:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0bfde8:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfdec:	0c0011c3 */ 	jal	guLookAtReflect
/*  f0bfdf0:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0bfdf4:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0bfdf8:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0bfdfc:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0bfe00:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f0bfe04:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0bfe08:	8c470008 */ 	lw	$a3,0x8($v0)
/*  f0bfe0c:	8d440064 */ 	lw	$a0,0x64($t2)
/*  f0bfe10:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0bfe14:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfe18:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0bfe1c:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0bfe20:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0bfe24:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfe28:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0bfe2c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfe30:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0bfe34:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfe38:	0c005a1d */ 	jal	mtx00016874
/*  f0bfe3c:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0bfe40:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f0bfe44:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0bfe48:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f0bfe4c:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0bfe50:	8d860004 */ 	lw	$a2,0x4($t4)
/*  f0bfe54:	8d870008 */ 	lw	$a3,0x8($t4)
/*  f0bfe58:	8d640068 */ 	lw	$a0,0x68($t3)
/*  f0bfe5c:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0bfe60:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0bfe64:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0bfe68:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f0bfe6c:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0bfe70:	c6260000 */ 	lwc1	$f6,0x0($s1)
/*  f0bfe74:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0bfe78:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f0bfe7c:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0bfe80:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f0bfe84:	0c005ad6 */ 	jal	mtx00016b58
/*  f0bfe88:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0bfe8c:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfe90:	00000000 */ 	nop
/*  f0bfe94:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0bfe98:	00408825 */ 	or	$s1,$v0,$zero
/*  f0bfe9c:	0fc2d5c6 */ 	jal	currentPlayerGetUnk1754
/*  f0bfea0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0bfea4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0bfea8:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0bfeac:	0c005680 */ 	jal	mtx4MultMtx4
/*  f0bfeb0:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bfeb4:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f0bfeb8:	44816000 */ 	mtc1	$at,$f12
/*  f0bfebc:	3c0146fa */ 	lui	$at,0x46fa
/*  f0bfec0:	44811000 */ 	mtc1	$at,$f2
/*  f0bfec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0bfec8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0bfecc:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f0bfed0:	24040010 */ 	addiu	$a0,$zero,0x10
.L0f0bfed4:
/*  f0bfed4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0bfed8:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0bfedc:
/*  f0bfedc:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0bfee0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0bfee4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0bfee8:	00000000 */ 	nop
/*  f0bfeec:	45020004 */ 	bc1fl	.L0f0bff00
/*  f0bfef0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0bfef4:	10000006 */ 	b	.L0f0bff10
/*  f0bfef8:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f0bfefc:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0bff00:
/*  f0bff00:	00000000 */ 	nop
/*  f0bff04:	45000002 */ 	bc1f	.L0f0bff10
/*  f0bff08:	00000000 */ 	nop
/*  f0bff0c:	e44c0000 */ 	swc1	$f12,0x0($v0)
.L0f0bff10:
/*  f0bff10:	1464fff2 */ 	bne	$v1,$a0,.L0f0bfedc
/*  f0bff14:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0bff18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0bff1c:	14a8ffed */ 	bne	$a1,$t0,.L0f0bfed4
/*  f0bff20:	24c60010 */ 	addiu	$a2,$a2,0x10
/*  f0bff24:	0fc2d3ee */ 	jal	currentPlayerSetUnk006c
/*  f0bff28:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bff2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0bff30:	0c0128d8 */ 	jal	guMtxF2L
/*  f0bff34:	02202825 */ 	or	$a1,$s1,$zero
/*  f0bff38:	0fc2d3fe */ 	jal	currentPlayerSetUnk1758
/*  f0bff3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0bff40:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f0bff44:	0c0057c1 */ 	jal	mtx00015f04
/*  f0bff48:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0bff4c:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0bff50:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0bff54:	0c0128d8 */ 	jal	guMtxF2L
/*  f0bff58:	8da5005c */ 	lw	$a1,0x5c($t5)
/*  f0bff5c:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f0bff60:	8c64005c */ 	lw	$a0,0x5c($v1)
/*  f0bff64:	0c005a08 */ 	jal	mtx00016820
/*  f0bff68:	8c650060 */ 	lw	$a1,0x60($v1)
/*  f0bff6c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0bff70:	0fc2d3e6 */ 	jal	currentPlayerSetUnk173c
/*  f0bff74:	8dc4005c */ 	lw	$a0,0x5c($t6)
/*  f0bff78:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0bff7c:	0fc2d3de */ 	jal	currentPlayerSetUnk1738
/*  f0bff80:	8de40060 */ 	lw	$a0,0x60($t7)
/*  f0bff84:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0bff88:	0fc2d406 */ 	jal	currentPlayerSetMatrix1740
/*  f0bff8c:	8f040064 */ 	lw	$a0,0x64($t8)
/*  f0bff90:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0bff94:	0fc2d5d6 */ 	jal	currentPlayerSetUnk174c
/*  f0bff98:	8f240068 */ 	lw	$a0,0x68($t9)
/*  f0bff9c:	0fc2d5e6 */ 	jal	currentPlayerSetUnk175c
/*  f0bffa0:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*  f0bffa4:	0fc2d60e */ 	jal	func0f0b5838
/*  f0bffa8:	00000000 */ 	nop
/*  f0bffac:	0fc2ff07 */ 	jal	playerSetGlobalDrawCameraOffset
/*  f0bffb0:	00000000 */ 	nop
/*  f0bffb4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0bffb8:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0bffbc:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0bffc0:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0bffc4:	03e00008 */ 	jr	$ra
/*  f0bffc8:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

// Mismatch near first call to mtx00016874:
// - Goal seems to have less float registers available which causes it to
// reload cam_look properties for the function call
// - Because it has to reload, it then stores cam_look in a callee-save register
//void player0f0bfc7c(struct coord *cam_pos, struct coord *cam_look, struct coord *cam_up)
//{
//	f32 spd0[16];
//	void *spcc;
//	Mtxf sp8c;
//	struct coord sp80;
//	struct coord sp74;
//	f32 scale;
//	Mtxf *s0;
//	Mtx *s1;
//	s32 i;
//	s32 j;
//
//	scale = currentPlayerGetScaleBg2Gfx();
//	playerSetGlobalDrawWorldOffset(g_Vars.currentplayer->cam_room);
//
//	g_Vars.currentplayer->matrix5c = gfxAllocateMatrix();
//	g_Vars.currentplayer->matrix60 = gfxAllocateMatrix();
//	g_Vars.currentplayer->matrix64 = gfxAllocateMatrix();
//	g_Vars.currentplayer->matrix68 = gfxAllocateMatrix();
//
//	spcc = gfxAllocateLookAt(2);
//
//	sp74.x = (cam_pos->x - g_Vars.currentplayer->globaldrawworldoffset.x) * scale;
//	sp74.y = (cam_pos->y - g_Vars.currentplayer->globaldrawworldoffset.y) * scale;
//	sp74.z = (cam_pos->z - g_Vars.currentplayer->globaldrawworldoffset.z) * scale;
//
//	sp80.x = (cam_pos->x - g_Vars.currentplayer->globaldrawworldoffset.x) * scale + cam_look->x;
//	sp80.y = (cam_pos->y - g_Vars.currentplayer->globaldrawworldoffset.y) * scale + cam_look->y;
//	sp80.z = (cam_pos->z - g_Vars.currentplayer->globaldrawworldoffset.z) * scale + cam_look->z;
//
//	mtx00016874(&sp8c,
//			sp74.x, sp74.y, sp74.z,
//			cam_look->x, cam_look->y, cam_look->z,
//			cam_up->x, cam_up->y, cam_up->z);
//
//	guLookAtReflect(spd0, spcc,
//			sp74.x, sp74.y, sp74.z,
//			sp80.x, sp80.y, sp80.z,
//			cam_up->x, cam_up->y, cam_up->z);
//
//	mtx00016874(g_Vars.currentplayer->matrix64,
//			cam_pos->x, cam_pos->y, cam_pos->z,
//			cam_look->x, cam_look->y, cam_look->z,
//			cam_up->x, cam_up->y, cam_up->z);
//
//	mtx00016b58(g_Vars.currentplayer->matrix68,
//			cam_pos->x, cam_pos->y, cam_pos->z,
//			cam_look->x, cam_look->y, cam_look->z,
//			cam_up->x, cam_up->y, cam_up->z);
//
//	s1 = gfxAllocateMatrix();
//	s0 = gfxAllocateMatrix();
//	mtx4MultMtx4(currentPlayerGetUnk1754(), &sp8c, s0);
//
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			if (s0->m[i][j] > 32000.0f) {
//				s0->m[i][j] = 32000.0f;
//			} else if (s0->m[i][j] < -32000.0f) {
//				s0->m[i][j] = -32000.0f;
//			}
//		}
//	}
//
//	currentPlayerSetUnk006c(s0);
//	guMtxF2L(s0, s1);
//	currentPlayerSetUnk1758(s1);
//	mtx00015f04(scale, &sp8c);
//	guMtxF2L(&sp8c, g_Vars.currentplayer->matrix5c);
//	mtx00016820(g_Vars.currentplayer->matrix5c, g_Vars.currentplayer->matrix60);
//	currentPlayerSetUnk173c(g_Vars.currentplayer->matrix5c);
//	currentPlayerSetUnk1738(g_Vars.currentplayer->matrix60);
//	currentPlayerSetMatrix1740(g_Vars.currentplayer->matrix64);
//	currentPlayerSetUnk174c(g_Vars.currentplayer->matrix68);
//	currentPlayerSetUnk175c(spcc);
//	func0f0b5838();
//	playerSetGlobalDrawCameraOffset();
//}

Gfx *playerUpdateShootRot(Gfx *gdl)
{
	struct coord sp3c;
	struct coord sp30;
	f32 y;
	f32 value;
	f32 rotx;
	f32 roty;

	player0f0bfc7c(&g_Vars.currentplayer->cam_pos,
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
		g_Vars.currentplayer->shieldshowrot = g_Vars.thisframe240 % rand;
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

		g_Vars.currentplayer->shieldshowrot += g_Vars.lvupdate240freal * (0.8f + 2.0f * f20 * f20);

		if (g_Vars.currentplayer->shieldshowrot >= maxrotf) {
			g_Vars.currentplayer->shieldshowrot -= maxrotf;
		}

		f20 = (sinf(g_Vars.currentplayer->shieldshowrot * (M_BADTAU / maxrotf)) + 1) * 0.5f;
		sp90[0] = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * f20;

		f20 = (cosf(g_Vars.currentplayer->shieldshowrot * (M_BADTAU / maxrotf)) + 1) * 0.5f;
		sp90[1] = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * f20;

		sp88[0] = currentPlayerGetScreenWidth() * (1.0f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 20) % 100) + (g_Vars.currentplayer->shieldshowtime * (0.2f + 0.002f * (g_Vars.currentplayer->shieldshowrnd % 100)) * (1.0f / 60.0f)));
		sp88[1] = currentPlayerGetScreenHeight() * (1.0f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 24) % 100) + (g_Vars.currentplayer->shieldshowtime * (0.2f + 0.002f * ((g_Vars.currentplayer->shieldshowrnd >> 8) % 100)) * (1.0f / 60.0f)));

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
		func0f0b39c0(&gdl, &g_TexShieldConfigs[0], 4, 1, 2, 1, NULL);

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

		g_Vars.currentplayer->shieldshowtime += g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->shieldshowtime > 60) {
			g_Vars.currentplayer->shieldshowtime = -1;
		}
	}

	return gdl;
}

Gfx *playerRenderHud(Gfx *gdl)
{
	if (g_Vars.currentplayer->cameramode == CAMERAMODE_THIRDPERSON) {
		gdl = func0f0aeed8(gdl);
		gdl = func0f15b114(gdl);
		gdl = hudmsgsRender(gdl);

		if (g_Vars.currentplayer->isdead == false) {
			gdl = playerDrawStoredFade(gdl);
		}

		if (g_Vars.stagenum == STAGE_ESCAPE) {
			gdl = gasRender(gdl);
		}

		return gdl;
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY) {
		bgun0f0a6c30();
		gdl = func0f0aeed8(gdl);
		bgun0f0a7138(&gdl);
		gdl = lasersightRenderDot(gdl);

		if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
			gdl = func0f15b114(gdl);
		}

		if (g_NbombsActive) {
			gdl = func0f00a490(gdl);
		}

		if (g_Vars.stagenum == STAGE_ESCAPE) {
			gdl = gasRender(gdl);
		}

		gdl = playerRenderShield(gdl);

		// Adjust eyes shutting
		if (g_Vars.currentplayer->eyesshut) {
			if (g_Vars.currentplayer->eyesshutfrac < 0.95f) {
				g_Vars.currentplayer->eyesshutfrac += g_Vars.lvupdate240freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac > 0.95f) {
					g_Vars.currentplayer->eyesshutfrac = 0.95f;
				}
			}
		} else {
			if (g_Vars.currentplayer->eyesshutfrac > 0) {
				g_Vars.currentplayer->eyesshutfrac -= g_Vars.lvupdate240freal * 0.12f;

				if (g_Vars.currentplayer->eyesshutfrac < 0) {
					g_Vars.currentplayer->eyesshutfrac = 0;
				}
			}
		}

		if (g_Vars.currentplayer->isdead == false
				&& g_InCutscene == 0
				&& (!g_Vars.currentplayer->eyespy || (g_Vars.currentplayer->eyespy && !g_Vars.currentplayer->eyespy->active))
				&& ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit) & DEVICE_NIGHTVISION)) {
			gdl = bviewRenderNvLens(gdl);
			gdl = bviewRenderNvBinoculars(gdl);
		} else if (g_Vars.currentplayer->isdead == false
				&& g_InCutscene == 0
				&& (!g_Vars.currentplayer->eyespy || (g_Vars.currentplayer->eyespy && !g_Vars.currentplayer->eyespy->active))
				&& ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit) & DEVICE_IRSCANNER)) {
			gdl = bviewRenderIrLens(gdl);
			gdl = bviewRenderIrBinoculars(gdl);
		}

		if (g_Vars.currentplayer->eyesshutfrac > 0) {
			gdl = playerDrawFade(gdl, 0, 0, 0, g_Vars.currentplayer->eyesshutfrac);
		}
	}

	gdl = player0f0baf84(gdl);

	// Draw menu
	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY && g_Vars.currentplayer->mpmenuon) {
		s32 a = viGetViewLeft();
		s32 b = viGetViewTop();
		s32 c = viGetViewLeft() + viGetViewWidth();
		s32 d = viGetViewTop() + viGetViewHeight();

		gdl = func0f153628(gdl);
		gdl = func0f153a34(gdl, a, b, c, d, 0x000000a0);
		gdl = func0f153780(gdl);
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
			&& playerIsHealthVisible()
			&& func0f0f0c68()) {
		gdl = playerRenderHealthBar(gdl);
	}

	if (g_Vars.normmplayerisrunning == false) {
		objectivesCheckAll();
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

				if (g_Vars.mplayerisrunning) {
					if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
						// Coop or anti
						struct chrdata *chr = g_Vars.currentplayer->prop->chr;

						if (chr) {
							chr->chrflags |= CHRCFLAG_HIDDEN;
						}

						if (g_Vars.antiplayernum >= 0 && g_Vars.currentplayer == g_Vars.anti) {
							// Anti
							if (joyGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000) && !mpIsPaused()) {
								g_Vars.currentplayer->dostartnewlife = true;
							}
						} else {
							// Coop
							if (g_Vars.coopplayernum >= 0 &&
									(!g_Vars.bond->isdead || !g_Vars.coop->isdead)) {
								f32 totalhealth;
								u32 buddyplayernum = g_Vars.bondplayernum;
								u32 prevplayernum = g_Vars.currentplayernum;
								f32 stealhealth;
								f32 shield;

								canrestart = joyGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000)
									&& !mpIsPaused();

								// Get ready to respawn.
								// The other player's health will be halved.
								buddyplayernum = g_Vars.currentplayer == g_Vars.coop ? g_Vars.bondplayernum : g_Vars.coopplayernum;

								setCurrentPlayerNum(buddyplayernum);
								shield = chrGetShield(g_Vars.currentplayer->prop->chr) * 0.125f;
								totalhealth = g_Vars.currentplayer->bondhealth + shield;

#if VERSION >= VERSION_NTSC_FINAL
								// NTSC final prevents coop from being able to respawn
								// in Deep Sea after the mid cutscene. Without this condition,
								// the player could respawn on the other side of the exit trigger.
								// Additionally, the logic for coopcanrestart is different.
								if (totalhealth > 0.125f
										&& !(mainGetStageNum() == STAGE_DEEPSEA && chrHasStageFlag(NULL, 0x00000200))) {
									if (canrestart) {
										playerDisplayHealth();

										stealhealth = totalhealth * 0.5f;

										if (stealhealth < shield) {
											chrSetShield(g_Vars.currentplayer->prop->chr, (shield - stealhealth) * 8.0f);
										} else {
											chrSetShield(g_Vars.currentplayer->prop->chr, 0);
											g_Vars.currentplayer->bondhealth -= stealhealth - shield;
										}

										// Back to the player who died
										setCurrentPlayerNum(prevplayernum);
										g_Vars.currentplayer->dostartnewlife = true;
										g_Vars.currentplayer->oldhealth = 0;
										g_Vars.currentplayer->oldarmour = 0;
										g_Vars.currentplayer->apparenthealth = 0;
										g_Vars.currentplayer->apparentarmour = 0;
										g_Vars.currentplayer->stealhealth = stealhealth;
									} else {
										setCurrentPlayerNum(prevplayernum);
									}

									g_Vars.currentplayer->coopcanrestart = true;
								} else {
									// Can't respawn
									setCurrentPlayerNum(prevplayernum);
								}
#else
								if (totalhealth > 0.125f && canrestart) {
									playerDisplayHealth();

									stealhealth = totalhealth * 0.5f;

									if (stealhealth < shield) {
										chrSetShield(g_Vars.currentplayer->prop->chr, (shield - stealhealth) * 8.0f);
									} else {
										chrSetShield(g_Vars.currentplayer->prop->chr, 0);
										g_Vars.currentplayer->bondhealth -= stealhealth - shield;
									}

									// Back to the player who died
									setCurrentPlayerNum(prevplayernum);
									g_Vars.currentplayer->dostartnewlife = true;
									g_Vars.currentplayer->oldhealth = 0;
									g_Vars.currentplayer->oldarmour = 0;
									g_Vars.currentplayer->apparenthealth = 0;
									g_Vars.currentplayer->apparentarmour = 0;
									g_Vars.currentplayer->stealhealth = stealhealth;
								} else {
									setCurrentPlayerNum(prevplayernum);
								}

								if (totalhealth > 0.125f) {
									g_Vars.currentplayer->coopcanrestart = true;
								}
#endif
							}
						}
					} else {
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
								g_Vars.currentplayer->deadtimer -= g_Vars.lvupdate240_60;

								if (g_Vars.currentplayer->deadtimer < 0) {
									canrestart = true;
								}
							}
						}

						if (joyGetButtons(optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex), 0xb000)
								&& !mpIsPaused()
								&& g_NumReasonsToEndMpMatch == 0) {
							canrestart = true;
						}

						if (canrestart) {
							g_Vars.currentplayer->dostartnewlife = true;
						}
					}
				}
			}
		}
	}

	if (g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY) {
		gdl = bgun0f0abcb0(gdl);

		if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_HORIZONSCANNER) {
			gdl = bviewRenderHorizonScanner(gdl);
		}

		if (optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex)) {
			gdl = bgunRenderHud(gdl);
		}

#if VERSION >= VERSION_NTSC_1_0
		gdl = radarRender(gdl);
		gdl = hudmsgsRender(gdl);
#else
		gdl = hudmsgsRender(gdl);
		gdl = radarRender(gdl);
#endif

		gdl = playerDrawStoredFade(gdl);
	} else {
		gdl = func0f15b114(gdl);

		if (g_Vars.currentplayer->eyespy) {
			if (g_Vars.currentplayer->eyespy->startuptimer60 < TICKS(50)) {
				gdl = bviewRenderFisheye(gdl, -1, 255, 0, g_Vars.currentplayer->eyespy->startuptimer60, g_Vars.currentplayer->eyespy->hit);
			} else {
				s32 time = g_Vars.currentplayer->eyespy->camerashuttertime;

				if (time > 0) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						gdl = bviewRenderFisheye(gdl, -1, 255, time, TICKS(50), g_Vars.currentplayer->eyespy->hit);
					} else {
						gdl = bviewRenderFisheye(gdl, -1, 255, 0, TICKS(50), g_Vars.currentplayer->eyespy->hit);
					}

					g_Vars.currentplayer->eyespy->camerashuttertime -= g_Vars.lvupdate240_60;
				} else {
					gdl = bviewRenderFisheye(gdl, -1, 255, 0, TICKS(50), g_Vars.currentplayer->eyespy->hit);
				}
			}

			gdl = bviewRenderEyespyDecorations(gdl);
		}

		if (g_Vars.currentplayer->mpmenuon) {
			s32 a = viGetViewLeft();
			s32 b = viGetViewTop();
			s32 c = viGetViewLeft() + viGetViewWidth();
			s32 d = viGetViewTop() + viGetViewHeight();

			gdl = func0f153628(gdl);
			gdl = func0f153a34(gdl, a, b, c, d, 0x000000a0);
			gdl = func0f153780(gdl);
		}

		gdl = hudmsgsRender(gdl);
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

		if (g_Vars.mplayerisrunning &&
				(g_Vars.antiplayernum < 0
				 || g_Vars.currentplayernum != g_Vars.antiplayernum
				 || shooter != g_Vars.antiplayernum)) {
			currentPlayerDropAllItems();
		}

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
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
			g_Vars.currentplayer->bondtankexplode = true;
		}

		bmoveSetMode(MOVEMODE_WALK);
		bgun0f0a29c8();

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

// Never called
void playerSetInvincible(bool enable)
{
	if (enable) {
		cheatActivate(CHEAT_INVINCIBLE);
	} else {
		cheatDeactivate(CHEAT_INVINCIBLE);
	}
}

void playerSetBondVisible(bool visible)
{
	g_Vars.bondvisible = visible;
}

void playerSetBondCollisionsEnabled(bool enabled)
{
	g_Vars.bondcollisions = enabled;
}

void playerSetCameraMode(s32 mode)
{
	g_Vars.currentplayer->cameramode = mode;
}

void player0f0c1840(struct coord *pos, struct coord *up, struct coord *look, struct coord *pos2, s16 *rooms2)
{
	bool done = false;
	s32 room;
	s16 sp90[20];
	s16 tmp;
	s16 sp64[20];
	s16 sp54[8];
	s16 sp52;
	s32 i;

	if (rooms2 != NULL && *rooms2 != -1) {
		func00018148(pos2, pos, rooms2, sp54, NULL, 0);

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
		func0f162194(pos, sp90, sp64, 20, &sp52);

		if (sp90[0] != -1) {
			tmp = room = cd0002a400(pos, sp90);

			if (room > 0) {
				playerSetCamPropertiesWithRoom(pos, up, look, tmp);
			} else {
				playerSetCamPropertiesWithRoom(pos, up, look, sp90[0]);
			}
		} else if (sp64[0] != -1) {
			tmp = room = cd0002a400(pos, sp64);

			if (room > 0) {
				playerSetCamPropertiesWithoutRoom(pos, up, look, tmp);
			} else {
				playerSetCamPropertiesWithoutRoom(pos, up, look, sp64[0]);
			}
		} else {
			if (sp52 != -1) {
				playerSetCamPropertiesWithoutRoom(pos, up, look, sp52);
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

void player0f0c1bd8(struct coord *pos, struct coord *up, struct coord *look)
{
	if (g_Vars.currentplayer->memcamroom >= 0) {
		player0f0c1ba4(pos, up, look, &g_Vars.currentplayer->memcampos, g_Vars.currentplayer->memcamroom);
	} else {
		player0f0c1840(pos, up, look, NULL, NULL);
	}
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

void playersClearMemCamRoom(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		playerClearMemCamRoom();
	}

	setCurrentPlayerNum(prevplayernum);
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
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		objSetPerimEnabled(g_Vars.currentplayer->hoverbike, enable);
	}

	g_Vars.players[playernum]->bondperimenabled = enable;
}

bool playerUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	s32 playernum = playermgrGetPlayerNumByProp(prop);

	if (g_Vars.players[playernum]->bondperimenabled
			&& (!g_Vars.mplayerisrunning || !g_Vars.players[playernum]->isdead)) {
		if (g_Vars.unk00048c) {
			g_Vars.players[playernum]->perimshoot = g_Vars.players[playernum]->periminfo;
			g_Vars.players[playernum]->perimshoot.width = 15;

			*start = (void *) &g_Vars.players[playernum]->perimshoot;
		} else {
			*start = (void *) &g_Vars.players[playernum]->periminfo;
		}

		*end = *start + sizeof(struct tiletype3);

		return true;
	}

	*end = NULL;
	*start = NULL;

	return false;
}

void playerUpdatePerimInfo(void)
{
	g_Vars.currentplayer->periminfo.header.type = TILETYPE_03;
	g_Vars.currentplayer->periminfo.header.flags = TILEFLAG_0004 | TILEFLAG_0010;

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
	g_Vars.currentplayer->periminfo.width = g_Vars.currentplayer->bond2.width;
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
void playerGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin)
{
	s32 playernum = playermgrGetPlayerNumByProp(prop);

	*width = g_Vars.players[playernum]->bond2.width;
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
		if (var80075d60 == 0
				|| var80075d60 == 1
				|| (player->cameramode == CAMERAMODE_THIRDPERSON && player->visionmode != VISIONMODE_SLAYERROCKET)) {
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

				mtx00015be4(currentPlayerGetUnk174c(), spe8, &spa8);

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
				|| player->cameramode == CAMERAMODE_EYESPY
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

		if (chrprop->type == PROPTYPE_PLAYER
				&& g_Vars.players[playermgrGetPlayerNumByProp(chrprop)]->bondmovemode == MOVEMODE_BIKE) {
			// Player on a hoverbike
			if (leftprop && rightprop) {
				wieldmode = WIELDMODE_DUALGUNS;
			} else if (!leftprop && !rightprop) {
				wieldmode = WIELDMODE_UNARMED;
			} else if (leftgun && weaponHasFlag(leftgun->weaponnum, WEAPONFLAG_ONEHANDED)) {
				wieldmode = WIELDMODE_PISTOL;
			} else if (rightgun && weaponHasFlag(rightgun->weaponnum, WEAPONFLAG_ONEHANDED)) {
				wieldmode = WIELDMODE_PISTOL;
			} else {
				wieldmode = WIELDMODE_HEAVY;
			}

			if (wieldmode == WIELDMODE_PISTOL) {
				animnum = ANIM_ONBIKE_PISTOL;
			} else if (wieldmode == WIELDMODE_DUALGUNS) {
				animnum = ANIM_ONBIKE_DUALGUNS;
			} else if (wieldmode == WIELDMODE_HEAVY) {
				animnum = ANIM_ONBIKE_HEAVYGUN;
			} else {
				animnum = ANIM_ONBIKE_UNARMED;
			}

			speed = 0.5f;
			animcfg = NULL;
		} else {
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

			limit = g_Vars.lvupdate240freal * 0.10470308363438f;

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

Gfx *playerRender(struct prop *prop, Gfx *gdl, bool withalpha)
{
	if (g_Vars.players[playermgrGetPlayerNumByProp(prop)]->haschrbody) {
		gdl = chrRender(prop, gdl, withalpha);
	}

	return gdl;
}

Gfx *playerLoadMatrix(Gfx *gdl)
{
	gSPMatrix(gdl++, g_Vars.currentplayer->matrix5c, G_MTX_LOAD);
	return gdl;
}

GLOBAL_ASM(
glabel player0f0c3320
/*  f0c3320:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0c3324:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c3328:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c332c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c3330:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0c3334:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0c3338:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0c333c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c3340:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c3344:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c3348:	18a0001f */ 	blez	$a1,.L0f0c33c8
/*  f0c334c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c3350:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0c3354:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0c3358:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c335c:	27b20040 */ 	addiu	$s2,$sp,0x40
.L0f0c3360:
/*  f0c3360:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0c3364:	00000000 */ 	nop
/*  f0c3368:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c336c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0c3370:	0c0056f9 */ 	jal	mtx00015be4
/*  f0c3374:	02403025 */ 	or	$a2,$s2,$zero
/*  f0c3378:	8e620284 */ 	lw	$v0,0x284($s3)
/*  f0c337c:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f0c3380:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0c3384:	c4460038 */ 	lwc1	$f6,0x38($v0)
/*  f0c3388:	00117180 */ 	sll	$t6,$s1,0x6
/*  f0c338c:	01d52821 */ 	addu	$a1,$t6,$s5
/*  f0c3390:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c3394:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0c3398:	02402025 */ 	or	$a0,$s2,$zero
/*  f0c339c:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f0c33a0:	c450003c */ 	lwc1	$f16,0x3c($v0)
/*  f0c33a4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0c33a8:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f0c33ac:	c4460040 */ 	lwc1	$f6,0x40($v0)
/*  f0c33b0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c33b4:	0c005815 */ 	jal	mtx00016054
/*  f0c33b8:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f0c33bc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0c33c0:	1634ffe7 */ 	bne	$s1,$s4,.L0f0c3360
/*  f0c33c4:	26100040 */ 	addiu	$s0,$s0,0x40
.L0f0c33c8:
/*  f0c33c8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0c33cc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0c33d0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0c33d4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0c33d8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0c33dc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0c33e0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0c33e4:	03e00008 */ 	jr	$ra
/*  f0c33e8:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

// Mismatch: goal stores matrices in both s5 and s0, increments s0 for the first
// &matrices[i], and calculates s5 + i * 0x40 for the second &matrices[i].
// The below stores matrices in s5, calculates s5 + i * 0x40 for the first
// &matrices[i], then puts that value in s0 for the second &matrices[i].
//void player0f0c3320(Mtxf *matrices, s32 count)
//{
//	Mtxf sp40;
//	s32 i;
//
//	for (i = 0; i < count; i++) {
//		mtx00015be4(currentPlayerGetUnk174c(), &matrices[i], &sp40);
//
//		sp40.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
//		sp40.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
//		sp40.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;
//
//		mtx00016054(&sp40, &matrices[i]);
//	}
//}
