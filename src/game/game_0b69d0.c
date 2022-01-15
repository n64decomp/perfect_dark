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
#include "game/game_095320.h"
#include "game/atan2f.h"
#include "game/game_096ca0.h"
#include "game/bondgun.h"
#include "game/game_0abe70.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/game_0b69d0.h"
#include "game/healthbar.h"
#include "game/hudmsg.h"
#include "game/game_0f09f0.h"
#include "game/mainmenu.h"
#include "game/filemgr.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
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

const char var7f1ad420[] = "Gunmem: 0x%08x\n";
const char var7f1ad430[] = "Gunmem: bondsub 0x%08x\n";
const char var7f1ad448[] = "Gunmem: bondsub->anim 0x%08x\n";
const char var7f1ad468[] = "Gunmem: savedata 0x%08x\n";
const char var7f1ad484[] = "Gunmem: wo 0x%08x\n";
const char var7f1ad498[] = "Jo using %d bytes gunmem (gunmemsize %d)\n";
const char var7f1ad4c4[] = "Gunmem: bondmeml 0x%08x size 0x%08x\n";
const char var7f1ad4ec[] = "Gunmem: tex block free 0x%08x\n";
const char var7f1ad50c[] = "Gunmem: Free at end %d\n";

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

#if VERSION >= VERSION_PAL_FINAL
f32 g_CutsceneCurAnimFrame240;
f32 var8009e388pf;
#else
s32 g_CutsceneCurAnimFrame240;
#endif

s16 g_CutsceneAnimNum;
f32 g_CutsceneBlurFrac;

#if VERSION < VERSION_PAL_FINAL
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
#if PAL
	{ 320, 266, 320, 1,                1, 266, 0,  212, 20, 168, 42 }, // default
	{ 448, 266, 448, 0.71428567171097, 1, 266, 0,  212, 20, 168, 42 }, // hi-res
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
u32 var80070744 = 0;
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

u32 g_NumDeathAnimations = 0;

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

void currentPlayerStartNewLife(void)
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
	currentPlayerResetToDefault();
	g_Vars.currentplayer->isdead = false;
	g_Vars.currentplayer->healthdamagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->damagetype = DAMAGETYPE_7;
	g_Vars.currentplayer->gunammooff = 0;
	g_Vars.currentplayer->gunsightoff = 2;

	currentPlayerSetHudmsgsOn(0xffffffff);

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

	func0f0b85a0(&g_Vars.currentplayer->bond2, &pos);

	g_Vars.currentplayer->bond2.unk00.x = -sinf(angle);
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = cosf(angle);

	g_Vars.currentplayer->prop->pos.f[0] = g_Vars.currentplayer->bondprevpos.f[0] = pos.f[0];
	g_Vars.currentplayer->prop->pos.f[1] = g_Vars.currentplayer->bondprevpos.f[1] = pos.f[1];
	g_Vars.currentplayer->prop->pos.f[2] = g_Vars.currentplayer->bondprevpos.f[2] = pos.f[2];

	propDeregisterRooms(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
	g_Vars.currentplayer->prop->rooms[1] = -1;

	currentPlayerSetCamPropertiesWithRoom(&pos, &g_Vars.currentplayer->bond2.unk28,
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
	currentPlayerSpawn();

	if (g_Vars.normmplayerisrunning) {
		currentPlayerStartChrFade(120, 1);
	} else {
		currentPlayerStartChrFade(0, 1);
	}

	if (g_Vars.currentplayer->prop->chr) {
		g_Vars.currentplayer->prop->chr->chrflags &= ~CHRCFLAG_HIDDEN;
	}
}

void currentPlayerResetToDefault(void)
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

	g_Vars.currentplayer->unk1c1c = 0;
	g_Vars.currentplayer->unk1c20 = 0;
	g_Vars.currentplayer->unk1c24 = 0;
	g_Vars.currentplayer->unk1c28 = 0;
	g_Vars.currentplayer->unk1c2c = 0;
	g_Vars.currentplayer->unk1c30 = 0;
	g_Vars.currentplayer->unk1c34 = 0;
	g_Vars.currentplayer->unk1c38 = 0;
	g_Vars.currentplayer->unk1c3c = 0;
}

bool currentPlayerAssumeChrForAnti(struct chrdata *hostchr, bool force)
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

		g_Vars.currentplayer->invdowntime = PALDOWN(-40);
		g_Vars.currentplayer->usedowntime = PALDOWN(-40);

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

		func0f0b8ba0();
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

void currentPlayerSpawn(void)
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

	g_Vars.currentplayer->lifestarttime60 = getMissionTime();
	g_Vars.currentplayer->healthdisplaytime60 = 0;

	invGiveSingleWeapon(WEAPON_UNARMED);
	currentPlayerSetShieldFrac(0);

	if (cheatIsActive(CHEAT_JOSHIELD)) {
		currentPlayerSetShieldFrac(1);
	}

	if (cheatIsActive(CHEAT_SUPERSHIELD)) {
		currentPlayerSetShieldFrac(1);
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
				func0f0b8ba0();
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
				if (currentPlayerAssumeChrForAnti(sortedchrs[i], force)) {
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
				func0f0b8ba0();
			}
#else
			if (g_Vars.currentplayer->model00d4 == NULL) {
				func0f0b8ba0();
			}
#endif
		}
	}

	currentPlayerUpdatePerimInfo();
}

void func0f0b85a0(struct playerbond *pb, struct coord *pos)
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

void func0f0b85f8(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		func0f0b8ba0();
	}

	setCurrentPlayerNum(prevplayernum);
}

void currentPlayerChooseBodyAndHead(s32 *bodynum, s32 *headnum, s32 *arg2)
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

u32 var8007078c = 0x01000008;
u32 var80070790 = 0x00f5ffff;
u32 var80070794 = 0x00004000;
u32 var80070798 = 0x00000000;
u32 var8007079c = 0x00000000;
u32 var800707a0 = 0x00000000;
u32 var800707a4 = 0x00000000;
u32 var800707a8 = 0x3f800000;
u32 var800707ac = 0x00000000;
u32 var800707b0 = 0x00000000;
u32 var800707b4 = 0x00000000;
u32 var800707b8 = 0x3f800000;
u32 var800707bc = 0x00000000;
u32 var800707c0 = 0x00000000;
u32 var800707c4 = 0x00000000;
u32 var800707c8 = 0x3f800000;
u32 var800707cc = 0x00000000;
u32 var800707d0 = 0x00000000;
u32 var800707d4 = 0x00000000;
u32 var800707d8 = 0x000003e8;
u32 var800707dc = 0xffffff00;
u32 var800707e0 = 0xffffff00;
u32 var800707e4 = 0x0fff0000;
u32 var800707e8 = 0x02000000;
u32 var800707ec = 0x00ffffff;
u32 var800707f0 = 0x00000000;

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0b8ba0
.late_rodata
glabel var7f1ad5b4
.word 0x40c907a9
.text
/*  f0b8ba0:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0b8ba4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0b8ba8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0b8bac:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0b8bb0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b8bb4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b8bb8:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0b8bbc:	44810000 */ 	mtc1	$at,$f0
/*  f0b8bc0:	c4640144 */ 	lwc1	$f4,0x144($v1)
/*  f0b8bc4:	3c017f1b */ 	lui	$at,%hi(var7f1ad5b4)
/*  f0b8bc8:	c428d5b4 */ 	lwc1	$f8,%lo(var7f1ad5b4)($at)
/*  f0b8bcc:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0b8bd0:	3c188007 */ 	lui	$t8,%hi(var8007078c)
/*  f0b8bd4:	2718078c */ 	addiu	$t8,$t8,%lo(var8007078c)
/*  f0b8bd8:	27090060 */ 	addiu	$t1,$t8,0x60
/*  f0b8bdc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0b8be0:	27af0074 */ 	addiu	$t7,$sp,0x74
/*  f0b8be4:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0b8be8:	e7b00114 */ 	swc1	$f16,0x114($sp)
/*  f0b8bec:	8c6e19c8 */ 	lw	$t6,0x19c8($v1)
/*  f0b8bf0:	55c00236 */ 	bnezl	$t6,.L0f0b94cc
/*  f0b8bf4:	8c6a00bc */ 	lw	$t2,0xbc($v1)
/*  f0b8bf8:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0b8bfc:	afa000f0 */ 	sw	$zero,0xf0($sp)
.L0f0b8c00:
/*  f0b8c00:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b8c04:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0b8c08:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0b8c0c:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f0b8c10:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f0b8c14:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f0b8c18:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f0b8c1c:	1709fff8 */ 	bne	$t8,$t1,.L0f0b8c00
/*  f0b8c20:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f0b8c24:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b8c28:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f0b8c2c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8c30:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0b8c34:	0fc2867c */ 	jal	bgunGetWeaponNum2
/*  f0b8c38:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0b8c3c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b8c40:	240a0056 */ 	addiu	$t2,$zero,0x56
/*  f0b8c44:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f0b8c48:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0b8c4c:	afaa0068 */ 	sw	$t2,0x68($sp)
/*  f0b8c50:	afab0064 */ 	sw	$t3,0x64($sp)
/*  f0b8c54:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0b8c58:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0b8c5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0b8c60:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0b8c64:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b8c68:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0b8c6c:	0fc2e1cb */ 	jal	currentPlayerChooseBodyAndHead
/*  f0b8c70:	adac19c8 */ 	sw	$t4,0x19c8($t5)
/*  f0b8c74:	8e0e02ac */ 	lw	$t6,0x2ac($s0)
/*  f0b8c78:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b8c7c:	3c08800a */ 	lui	$t0,%hi(g_DefaultWeapons)
/*  f0b8c80:	15c10003 */ 	bne	$t6,$at,.L0f0b8c90
/*  f0b8c84:	00000000 */ 	nop
/*  f0b8c88:	8d08ddd0 */ 	lw	$t0,%lo(g_DefaultWeapons)($t0)
/*  f0b8c8c:	afa8006c */ 	sw	$t0,0x6c($sp)
.L0f0b8c90:
/*  f0b8c90:	0fc4a2bd */ 	jal	weaponGetModel
/*  f0b8c94:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f0b8c98:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f0b8c9c:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f0b8ca0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b8ca4:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0b8ca8:	14c30004 */ 	bne	$a2,$v1,.L0f0b8cbc
/*  f0b8cac:	24190056 */ 	addiu	$t9,$zero,0x56
/*  f0b8cb0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0b8cb4:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0b8cb8:	afa90064 */ 	sw	$t1,0x64($sp)
.L0f0b8cbc:
/*  f0b8cbc:	8e180314 */ 	lw	$t8,0x314($s0)
/*  f0b8cc0:	53000020 */ 	beqzl	$t8,.L0f0b8d44
/*  f0b8cc4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b8cc8:	14c300e0 */ 	bne	$a2,$v1,.L0f0b904c
/*  f0b8ccc:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f0b8cd0:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0b8cd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b8cd8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b8cdc:	11e00003 */ 	beqz	$t7,.L0f0b8cec
/*  f0b8ce0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b8ce4:	10000001 */ 	b	.L0f0b8cec
/*  f0b8ce8:	00c02825 */ 	or	$a1,$a2,$zero
.L0f0b8cec:
/*  f0b8cec:	8e0a0068 */ 	lw	$t2,0x68($s0)
/*  f0b8cf0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b8cf4:	11400003 */ 	beqz	$t2,.L0f0b8d04
/*  f0b8cf8:	00000000 */ 	nop
/*  f0b8cfc:	10000001 */ 	b	.L0f0b8d04
/*  f0b8d00:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0b8d04:
/*  f0b8d04:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f0b8d08:	11600003 */ 	beqz	$t3,.L0f0b8d18
/*  f0b8d0c:	00000000 */ 	nop
/*  f0b8d10:	10000001 */ 	b	.L0f0b8d18
/*  f0b8d14:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0b8d18:
/*  f0b8d18:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0b8d1c:	11800003 */ 	beqz	$t4,.L0f0b8d2c
/*  f0b8d20:	00000000 */ 	nop
/*  f0b8d24:	10000001 */ 	b	.L0f0b8d2c
/*  f0b8d28:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0b8d2c:
/*  f0b8d2c:	00446821 */ 	addu	$t5,$v0,$a0
/*  f0b8d30:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f0b8d34:	01c54021 */ 	addu	$t0,$t6,$a1
/*  f0b8d38:	54c800c5 */ 	bnel	$a2,$t0,.L0f0b9050
/*  f0b8d3c:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b8d40:	8e190284 */ 	lw	$t9,0x284($s0)
.L0f0b8d44:
/*  f0b8d44:	3c05800a */ 	lui	$a1,%hi(var8009dfc0)
/*  f0b8d48:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var8009dfc0)
/*  f0b8d4c:	8f291bd4 */ 	lw	$t1,0x1bd4($t9)
/*  f0b8d50:	55200017 */ 	bnezl	$t1,.L0f0b8db0
/*  f0b8d54:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0b8d58:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0b8d5c:	5700000d */ 	bnezl	$t8,.L0f0b8d94
/*  f0b8d60:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b8d64:	0fc27801 */ 	jal	bgun0f09e004
/*  f0b8d68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0b8d6c:	3c05800a */ 	lui	$a1,%hi(var8009dfc0)
/*  f0b8d70:	24a5dfc0 */ 	addiu	$a1,$a1,%lo(var8009dfc0)
/*  f0b8d74:	10400006 */ 	beqz	$v0,.L0f0b8d90
/*  f0b8d78:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b8d7c:	0fc2777b */ 	jal	bgun0f09ddec
/*  f0b8d80:	00000000 */ 	nop
/*  f0b8d84:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b8d88:	10000008 */ 	b	.L0f0b8dac
/*  f0b8d8c:	ade21bd4 */ 	sw	$v0,0x1bd4($t7)
.L0f0b8d90:
/*  f0b8d90:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b8d94:
/*  f0b8d94:	ac6019c8 */ 	sw	$zero,0x19c8($v1)
/*  f0b8d98:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0b8d9c:	554001e2 */ 	bnezl	$t2,.L0f0b9528
/*  f0b8da0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b8da4:	100001df */ 	b	.L0f0b9524
/*  f0b8da8:	ae060320 */ 	sw	$a2,0x320($s0)
.L0f0b8dac:
/*  f0b8dac:	240b0008 */ 	addiu	$t3,$zero,0x8
.L0f0b8db0:
/*  f0b8db0:	3c018008 */ 	lui	$at,%hi(var8007fc0c)
/*  f0b8db4:	0fc2777b */ 	jal	bgun0f09ddec
/*  f0b8db8:	a42bfc0c */ 	sh	$t3,%lo(var8007fc0c)($at)
/*  f0b8dbc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b8dc0:	24030040 */ 	addiu	$v1,$zero,0x40
/*  f0b8dc4:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8dc8:	8d851bd4 */ 	lw	$a1,0x1bd4($t4)
/*  f0b8dcc:	00a36821 */ 	addu	$t5,$a1,$v1
/*  f0b8dd0:	246300cb */ 	addiu	$v1,$v1,0xcb
/*  f0b8dd4:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f0b8dd8:	acad0020 */ 	sw	$t5,0x20($a1)
/*  f0b8ddc:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b8de0:	39c8003f */ 	xori	$t0,$t6,0x3f
/*  f0b8de4:	2503043f */ 	addiu	$v1,$t0,0x43f
/*  f0b8de8:	3469003f */ 	ori	$t1,$v1,0x3f
/*  f0b8dec:	3938003f */ 	xori	$t8,$t1,0x3f
/*  f0b8df0:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b8df4:	270300a7 */ 	addiu	$v1,$t8,0xa7
/*  f0b8df8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b8dfc:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f0b8e00:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b8e04:	394b003f */ 	xori	$t3,$t2,0x3f
/*  f0b8e08:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b8e0c:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f0b8e10:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f0b8e14:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0b8e18:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0b8e1c:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8e20:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0b8e24:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0b8e28:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0b8e2c:	afa500ec */ 	sw	$a1,0xec($sp)
/*  f0b8e30:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f0b8e34:	244e003f */ 	addiu	$t6,$v0,0x3f
/*  f0b8e38:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f0b8e3c:	35c8003f */ 	ori	$t0,$t6,0x3f
/*  f0b8e40:	3919003f */ 	xori	$t9,$t0,0x3f
/*  f0b8e44:	0329c021 */ 	addu	$t8,$t9,$t1
/*  f0b8e48:	05e0000e */ 	bltz	$t7,.L0f0b8e84
/*  f0b8e4c:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f0b8e50:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f0b8e54:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f0b8e58:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b8e5c:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8e60:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0b8e64:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0b8e68:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8e6c:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8e70:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0b8e74:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b8e78:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0b8e7c:	016e4021 */ 	addu	$t0,$t3,$t6
/*  f0b8e80:	afa800e4 */ 	sw	$t0,0xe4($sp)
.L0f0b8e84:
/*  f0b8e84:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0b8e88:	0720000b */ 	bltz	$t9,.L0f0b8eb8
/*  f0b8e8c:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f0b8e90:	3c048008 */ 	lui	$a0,%hi(g_ModelStates+0x4)
/*  f0b8e94:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b8e98:	0fc59c15 */ 	jal	fileGetInflatedLength
/*  f0b8e9c:	9484b070 */ 	lhu	$a0,%lo(g_ModelStates+0x4)($a0)
/*  f0b8ea0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0b8ea4:	244f003f */ 	addiu	$t7,$v0,0x3f
/*  f0b8ea8:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b8eac:	394c003f */ 	xori	$t4,$t2,0x3f
/*  f0b8eb0:	030c6821 */ 	addu	$t5,$t8,$t4
/*  f0b8eb4:	afad00e4 */ 	sw	$t5,0xe4($sp)
.L0f0b8eb8:
/*  f0b8eb8:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8ebc:	256e4000 */ 	addiu	$t6,$t3,0x4000
/*  f0b8ec0:	0fc2777f */ 	jal	bgun0f09ddfc
/*  f0b8ec4:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0b8ec8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b8ecc:	8fa900e4 */ 	lw	$t1,0xe4($sp)
/*  f0b8ed0:	8d191bd4 */ 	lw	$t9,0x1bd4($t0)
/*  f0b8ed4:	03297821 */ 	addu	$t7,$t9,$t1
/*  f0b8ed8:	0fc2777f */ 	jal	bgun0f09ddfc
/*  f0b8edc:	afaf00e8 */ 	sw	$t7,0xe8($sp)
/*  f0b8ee0:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f0b8ee4:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b8ee8:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0b8eec:	0fc5cb9c */ 	jal	func0f172e70
/*  f0b8ef0:	004a3023 */ 	subu	$a2,$v0,$t2
/*  f0b8ef4:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0b8ef8:	8fa200f0 */ 	lw	$v0,0xf0($sp)
/*  f0b8efc:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0b8f00:	00186080 */ 	sll	$t4,$t8,0x2
/*  f0b8f04:	01986021 */ 	addu	$t4,$t4,$t8
/*  f0b8f08:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b8f0c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b8f10:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8f14:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0b8f18:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8f1c:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b8f20:	01a22821 */ 	addu	$a1,$t5,$v0
/*  f0b8f24:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b8f28:	01623023 */ 	subu	$a2,$t3,$v0
/*  f0b8f2c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0b8f30:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8f34:	afa200fc */ 	sw	$v0,0xfc($sp)
/*  f0b8f38:	000e4080 */ 	sll	$t0,$t6,0x2
/*  f0b8f3c:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f0b8f40:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0b8f44:	00882021 */ 	addu	$a0,$a0,$t0
/*  f0b8f48:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b8f4c:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8f50:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0b8f54:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b8f58:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8f5c:	00594821 */ 	addu	$t1,$v0,$t9
/*  f0b8f60:	252f003f */ 	addiu	$t7,$t1,0x3f
/*  f0b8f64:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b8f68:	3958003f */ 	xori	$t8,$t2,0x3f
/*  f0b8f6c:	0580001b */ 	bltz	$t4,.L0f0b8fdc
/*  f0b8f70:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0b8f74:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b8f78:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b8f7c:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f0b8f80:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f0b8f84:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b8f88:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b8f8c:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8f90:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b8f94:	01782821 */ 	addu	$a1,$t3,$t8
/*  f0b8f98:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b8f9c:	01183023 */ 	subu	$a2,$t0,$t8
/*  f0b8fa0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0b8fa4:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b8fa8:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b8fac:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0b8fb0:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0b8fb4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0b8fb8:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b8fbc:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b8fc0:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b8fc4:	8faf00f0 */ 	lw	$t7,0xf0($sp)
/*  f0b8fc8:	004f5021 */ 	addu	$t2,$v0,$t7
/*  f0b8fcc:	254c003f */ 	addiu	$t4,$t2,0x3f
/*  f0b8fd0:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b8fd4:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0b8fd8:	afab00f0 */ 	sw	$t3,0xf0($sp)
.L0f0b8fdc:
/*  f0b8fdc:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0b8fe0:	8fa400fc */ 	lw	$a0,0xfc($sp)
/*  f0b8fe4:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f0b8fe8:	51c00004 */ 	beqzl	$t6,.L0f0b8ffc
/*  f0b8fec:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0b8ff0:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0b8ff4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0b8ff8:	8fa4005c */ 	lw	$a0,0x5c($sp)
.L0f0b8ffc:
/*  f0b8ffc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0b9000:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0b9004:	0c008be9 */ 	jal	modelInit
/*  f0b9008:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b900c:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0b9010:	0c008c28 */ 	jal	animInit
/*  f0b9014:	8d040020 */ 	lw	$a0,0x20($t0)
/*  f0b9018:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0b901c:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0b9020:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b9024:	0fc5cbd5 */ 	jal	func0f172f54
/*  f0b9028:	a7380002 */ 	sh	$t8,0x2($t9)
/*  f0b902c:	0fc2777b */ 	jal	bgun0f09ddec
/*  f0b9030:	00000000 */ 	nop
/*  f0b9034:	0fc2777f */ 	jal	bgun0f09ddfc
/*  f0b9038:	00000000 */ 	nop
/*  f0b903c:	0fc5cbd5 */ 	jal	func0f172f54
/*  f0b9040:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b9044:	1000005d */ 	b	.L0f0b91bc
/*  f0b9048:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b904c:
/*  f0b904c:	00097880 */ 	sll	$t7,$t1,0x2
.L0f0b9050:
/*  f0b9050:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b9054:	3c0a8008 */ 	lui	$t2,%hi(g_HeadsAndBodies)
/*  f0b9058:	254acf04 */ 	addiu	$t2,$t2,%lo(g_HeadsAndBodies)
/*  f0b905c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b9060:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b9064:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b9068:	5480000e */ 	bnezl	$a0,.L0f0b90a4
/*  f0b906c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0b9070:	0fc69e11 */ 	jal	fileLoad
/*  f0b9074:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b9078:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b907c:	3c0b8008 */ 	lui	$t3,%hi(g_HeadsAndBodies)
/*  f0b9080:	256bcf04 */ 	addiu	$t3,$t3,%lo(g_HeadsAndBodies)
/*  f0b9084:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b9088:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b908c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b9090:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b9094:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b9098:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b909c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b90a0:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f0b90a4:
/*  f0b90a4:	afa400fc */ 	sw	$a0,0xfc($sp)
/*  f0b90a8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0b90ac:	000ec040 */ 	sll	$t8,$t6,0x1
/*  f0b90b0:	07010003 */ 	bgez	$t8,.L0f0b90c0
/*  f0b90b4:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0b90b8:	1000003f */ 	b	.L0f0b91b8
/*  f0b90bc:	afb90064 */ 	sw	$t9,0x64($sp)
.L0f0b90c0:
/*  f0b90c0:	11200005 */ 	beqz	$t1,.L0f0b90d8
/*  f0b90c4:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0b90c8:	0fc6395f */ 	jal	func0f18e57c
/*  f0b90cc:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b90d0:	10000039 */ 	b	.L0f0b91b8
/*  f0b90d4:	afa200f8 */ 	sw	$v0,0xf8($sp)
.L0f0b90d8:
/*  f0b90d8:	8e0f0318 */ 	lw	$t7,0x318($s0)
/*  f0b90dc:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0b90e0:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f0b90e4:	51e00020 */ 	beqzl	$t7,.L0f0b9168
/*  f0b90e8:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b90ec:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0b90f0:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b90f4:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f0b90f8:	10ca001a */ 	beq	$a2,$t2,.L0f0b9164
/*  f0b90fc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b9100:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b9104:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b9108:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b910c:	0fc69e11 */ 	jal	fileLoad
/*  f0b9110:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f0b9114:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0b9118:	3c088008 */ 	lui	$t0,%hi(g_HeadsAndBodies)
/*  f0b911c:	2508cf04 */ 	addiu	$t0,$t0,%lo(g_HeadsAndBodies)
/*  f0b9120:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0b9124:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f0b9128:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0b912c:	01c81821 */ 	addu	$v1,$t6,$t0
/*  f0b9130:	94780002 */ 	lhu	$t8,0x2($v1)
/*  f0b9134:	3c01800a */ 	lui	$at,%hi(g_FileInfo)
/*  f0b9138:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b913c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0b9140:	00390821 */ 	addu	$at,$at,$t9
/*  f0b9144:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b9148:	ac206680 */ 	sw	$zero,%lo(g_FileInfo)($at)
/*  f0b914c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b9150:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b9154:	0fc0b76f */ 	jal	bodyCalculateHeadOffset
/*  f0b9158:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f0b915c:	10000017 */ 	b	.L0f0b91bc
/*  f0b9160:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b9164:
/*  f0b9164:	00097880 */ 	sll	$t7,$t1,0x2
.L0f0b9168:
/*  f0b9168:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b916c:	3c0a8008 */ 	lui	$t2,%hi(g_HeadsAndBodies)
/*  f0b9170:	254acf04 */ 	addiu	$t2,$t2,%lo(g_HeadsAndBodies)
/*  f0b9174:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b9178:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b917c:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b9180:	5480000d */ 	bnezl	$a0,.L0f0b91b8
/*  f0b9184:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f0b9188:	0fc69e11 */ 	jal	fileLoad
/*  f0b918c:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b9190:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b9194:	3c0b8008 */ 	lui	$t3,%hi(g_HeadsAndBodies)
/*  f0b9198:	256bcf04 */ 	addiu	$t3,$t3,%lo(g_HeadsAndBodies)
/*  f0b919c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b91a0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b91a4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b91a8:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b91ac:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b91b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b91b4:	afa400f8 */ 	sw	$a0,0xf8($sp)
.L0f0b91b8:
/*  f0b91b8:	8fae005c */ 	lw	$t6,0x5c($sp)
.L0f0b91bc:
/*  f0b91bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b91c0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0b91c4:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0b91c8:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0b91cc:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f0b91d0:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b91d4:	8fa600fc */ 	lw	$a2,0xfc($sp)
/*  f0b91d8:	8fa700f8 */ 	lw	$a3,0xf8($sp)
/*  f0b91dc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0b91e0:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f0b91e4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0b91e8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b91ec:	af2200d4 */ 	sw	$v0,0xd4($t9)
/*  f0b91f0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b91f4:	c7b20114 */ 	lwc1	$f18,0x114($sp)
/*  f0b91f8:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0b91fc:	8c6500d4 */ 	lw	$a1,0xd4($v1)
/*  f0b9200:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b9204:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0b9208:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f0b920c:	0fc082c5 */ 	jal	chr0f020b14
/*  f0b9210:	24870028 */ 	addiu	$a3,$a0,0x28
/*  f0b9214:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b9218:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f0b921c:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f0b9220:	a1490000 */ 	sb	$t1,0x0($t2)
/*  f0b9224:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b9228:	8e0b0314 */ 	lw	$t3,0x314($s0)
/*  f0b922c:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f0b9230:	11600011 */ 	beqz	$t3,.L0f0b9278
/*  f0b9234:	8da60004 */ 	lw	$a2,0x4($t5)
/*  f0b9238:	8e02028c */ 	lw	$v0,0x28c($s0)
/*  f0b923c:	3c01800b */ 	lui	$at,%hi(g_MpAllChrPtrs)
/*  f0b9240:	3c0f800b */ 	lui	$t7,%hi(g_PlayerConfigsArray)
/*  f0b9244:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b9248:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b924c:	ac26c4d0 */ 	sw	$a2,%lo(g_MpAllChrPtrs)($at)
/*  f0b9250:	8e080288 */ 	lw	$t0,0x288($s0)
/*  f0b9254:	3c01800b */ 	lui	$at,%hi(g_MpAllChrConfigPtrs)
/*  f0b9258:	25efc7b8 */ 	addiu	$t7,$t7,%lo(g_PlayerConfigsArray)
/*  f0b925c:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0b9260:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b9264:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b9268:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0b926c:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0b9270:	032f4821 */ 	addu	$t1,$t9,$t7
/*  f0b9274:	ac29c500 */ 	sw	$t1,%lo(g_MpAllChrConfigPtrs)($at)
.L0f0b9278:
/*  f0b9278:	8cca0018 */ 	lw	$t2,0x18($a2)
/*  f0b927c:	354c0001 */ 	ori	$t4,$t2,0x1
/*  f0b9280:	accc0018 */ 	sw	$t4,0x18($a2)
/*  f0b9284:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9288:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b928c:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b9290:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f0b9294:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0b9298:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b929c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b92a0:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b92a4:	8dab00bc */ 	lw	$t3,0xbc($t5)
/*  f0b92a8:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f0b92ac:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0b92b0:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0b92b4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0b92b8:	a04e0006 */ 	sb	$t6,0x6($v0)
/*  f0b92bc:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0b92c0:	a4480010 */ 	sh	$t0,0x10($v0)
/*  f0b92c4:	0fc0b378 */ 	jal	bodyGetRace
/*  f0b92c8:	84440010 */ 	lh	$a0,0x10($v0)
/*  f0b92cc:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0b92d0:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f0b92d4:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies)
/*  f0b92d8:	a30202fe */ 	sb	$v0,0x2fe($t8)
/*  f0b92dc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b92e0:	2484cf04 */ 	addiu	$a0,$a0,%lo(g_HeadsAndBodies)
/*  f0b92e4:	c7240378 */ 	lwc1	$f4,0x378($t9)
/*  f0b92e8:	e7040024 */ 	swc1	$f4,0x24($t8)
/*  f0b92ec:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0b92f0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b92f4:	01e50019 */ 	multu	$t7,$a1
/*  f0b92f8:	00004812 */ 	mflo	$t1
/*  f0b92fc:	00895021 */ 	addu	$t2,$a0,$t1
/*  f0b9300:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*  f0b9304:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0b9308:	000d5e02 */ 	srl	$t3,$t5,0x18
/*  f0b930c:	448b3000 */ 	mtc1	$t3,$f6
/*  f0b9310:	00000000 */ 	nop
/*  f0b9314:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b9318:	e5c819c4 */ 	swc1	$f8,0x19c4($t6)
/*  f0b931c:	8e08029c */ 	lw	$t0,0x29c($s0)
/*  f0b9320:	0502000e */ 	bltzl	$t0,.L0f0b935c
/*  f0b9324:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9328:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b932c:	8e1902a8 */ 	lw	$t9,0x2a8($s0)
/*  f0b9330:	3c01431f */ 	lui	$at,0x431f
/*  f0b9334:	57230009 */ 	bnel	$t9,$v1,.L0f0b935c
/*  f0b9338:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b933c:	44810000 */ 	mtc1	$at,$f0
/*  f0b9340:	c46a19c4 */ 	lwc1	$f10,0x19c4($v1)
/*  f0b9344:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0b9348:	00000000 */ 	nop
/*  f0b934c:	45020003 */ 	bc1fl	.L0f0b935c
/*  f0b9350:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9354:	e46019c4 */ 	swc1	$f0,0x19c4($v1)
/*  f0b9358:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b935c:
/*  f0b935c:	c47019c4 */ 	lwc1	$f16,0x19c4($v1)
/*  f0b9360:	e47019c0 */ 	swc1	$f16,0x19c0($v1)
/*  f0b9364:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f0b9368:	07020010 */ 	bltzl	$t8,.L0f0b93ac
/*  f0b936c:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9370:	03050019 */ 	multu	$t8,$a1
/*  f0b9374:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9378:	c47219c0 */ 	lwc1	$f18,0x19c0($v1)
/*  f0b937c:	00007812 */ 	mflo	$t7
/*  f0b9380:	008f4821 */ 	addu	$t1,$a0,$t7
/*  f0b9384:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f0b9388:	000a6180 */ 	sll	$t4,$t2,0x6
/*  f0b938c:	000c6e02 */ 	srl	$t5,$t4,0x18
/*  f0b9390:	448d2000 */ 	mtc1	$t5,$f4
/*  f0b9394:	00000000 */ 	nop
/*  f0b9398:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0b939c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f0b93a0:	10000007 */ 	b	.L0f0b93c0
/*  f0b93a4:	e46819c0 */ 	swc1	$f8,0x19c0($v1)
/*  f0b93a8:	8e030284 */ 	lw	$v1,0x284($s0)
.L0f0b93ac:
/*  f0b93ac:	3c014150 */ 	lui	$at,0x4150
/*  f0b93b0:	44818000 */ 	mtc1	$at,$f16
/*  f0b93b4:	c46a19c0 */ 	lwc1	$f10,0x19c0($v1)
/*  f0b93b8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f0b93bc:	e46419c0 */ 	swc1	$f4,0x19c0($v1)
.L0f0b93c0:
/*  f0b93c0:	8c8b00a0 */ 	lw	$t3,0xa0($a0)
/*  f0b93c4:	8c99071c */ 	lw	$t9,0x71c($a0)
/*  f0b93c8:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b93cc:	000b7180 */ 	sll	$t6,$t3,0x6
/*  f0b93d0:	0019c180 */ 	sll	$t8,$t9,0x6
/*  f0b93d4:	00187e02 */ 	srl	$t7,$t8,0x18
/*  f0b93d8:	000e4602 */ 	srl	$t0,$t6,0x18
/*  f0b93dc:	010f4821 */ 	addu	$t1,$t0,$t7
/*  f0b93e0:	44899000 */ 	mtc1	$t1,$f18
/*  f0b93e4:	c46619c0 */ 	lwc1	$f6,0x19c0($v1)
/*  f0b93e8:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0b93ec:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0b93f0:	00000000 */ 	nop
/*  f0b93f4:	45020004 */ 	bc1fl	.L0f0b9408
/*  f0b93f8:	c46819c4 */ 	lwc1	$f8,0x19c4($v1)
/*  f0b93fc:	e46019c0 */ 	swc1	$f0,0x19c0($v1)
/*  f0b9400:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b9404:	c46819c4 */ 	lwc1	$f8,0x19c4($v1)
.L0f0b9408:
/*  f0b9408:	e46819bc */ 	swc1	$f8,0x19bc($v1)
/*  f0b940c:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0b9410:	05400023 */ 	bltz	$t2,.L0f0b94a0
/*  f0b9414:	00000000 */ 	nop
/*  f0b9418:	8e0c0314 */ 	lw	$t4,0x314($s0)
/*  f0b941c:	3c0b8008 */ 	lui	$t3,%hi(g_ModelStates)
/*  f0b9420:	256bb06c */ 	addiu	$t3,$t3,%lo(g_ModelStates)
/*  f0b9424:	15800013 */ 	bnez	$t4,.L0f0b9474
/*  f0b9428:	000a68c0 */ 	sll	$t5,$t2,0x3
/*  f0b942c:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0b9430:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0b9434:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0b9438:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b943c:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b9440:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f0b9444:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b9448:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f0b944c:	0fc69de5 */ 	jal	func0f1a7794
/*  f0b9450:	03193023 */ 	subu	$a2,$t8,$t9
/*  f0b9454:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0b9458:	afa200f4 */ 	sw	$v0,0xf4($sp)
/*  f0b945c:	0fc59ca0 */ 	jal	fileGetSize
/*  f0b9460:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b9464:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f0b9468:	8fa400f4 */ 	lw	$a0,0xf4($sp)
/*  f0b946c:	10000004 */ 	b	.L0f0b9480
/*  f0b9470:	8faf00dc */ 	lw	$t7,0xdc($sp)
.L0f0b9474:
/*  f0b9474:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0b9478:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f0b947c:	8faf00dc */ 	lw	$t7,0xdc($sp)
.L0f0b9480:
/*  f0b9480:	8fa900f4 */ 	lw	$t1,0xf4($sp)
/*  f0b9484:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b9488:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0b948c:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0b9490:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b9494:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0b9498:	0fc22e3a */ 	jal	weaponCreateForChr
/*  f0b949c:	afa90014 */ 	sw	$t1,0x14($sp)
.L0f0b94a0:
/*  f0b94a0:	0fc29c3e */ 	jal	bgunAllocateFireslot
/*  f0b94a4:	00000000 */ 	nop
/*  f0b94a8:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b94ac:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b94b0:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f0b94b4:	a082017c */ 	sb	$v0,0x17c($a0)
/*  f0b94b8:	0fc32e31 */ 	jal	bmove0f0cb8c4
/*  f0b94bc:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0b94c0:	10000019 */ 	b	.L0f0b9528
/*  f0b94c4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b94c8:	8c6a00bc */ 	lw	$t2,0xbc($v1)
.L0f0b94cc:
/*  f0b94cc:	8d440004 */ 	lw	$a0,0x4($t2)
/*  f0b94d0:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0b94d4:	8dab0020 */ 	lw	$t3,0x20($t5)
/*  f0b94d8:	55600013 */ 	bnezl	$t3,.L0f0b9528
/*  f0b94dc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b94e0:	8c8e0018 */ 	lw	$t6,0x18($a0)
/*  f0b94e4:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b94e8:	35d90001 */ 	ori	$t9,$t6,0x1
/*  f0b94ec:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f0b94f0:	ac990018 */ 	sw	$t9,0x18($a0)
/*  f0b94f4:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b94f8:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b94fc:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b9500:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0b9504:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b9508:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0b950c:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b9510:	8f0800bc */ 	lw	$t0,0xbc($t8)
/*  f0b9514:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f0b9518:	8d040004 */ 	lw	$a0,0x4($t0)
/*  f0b951c:	0fc32e31 */ 	jal	bmove0f0cb8c4
/*  f0b9520:	8e040284 */ 	lw	$a0,0x284($s0)
.L0f0b9524:
/*  f0b9524:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0b9528:
/*  f0b9528:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0b952c:	27bd0118 */ 	addiu	$sp,$sp,0x118
/*  f0b9530:	03e00008 */ 	jr	$ra
/*  f0b9534:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f0b8ba0
.late_rodata
glabel var7f1ad5b4
.word 0x40c907a9
.text
/*  f0b68b8:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0b68bc:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0b68c0:	3c10800a */ 	lui	$s0,0x800a
/*  f0b68c4:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0b68c8:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b68cc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0b68d0:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0b68d4:	44810000 */ 	mtc1	$at,$f0
/*  f0b68d8:	c4640144 */ 	lwc1	$f4,0x144($v1)
/*  f0b68dc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0b68e0:	c4287904 */ 	lwc1	$f8,0x7904($at)
/*  f0b68e4:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0b68e8:	3c188007 */ 	lui	$t8,0x8007
/*  f0b68ec:	27182e4c */ 	addiu	$t8,$t8,0x2e4c
/*  f0b68f0:	27090060 */ 	addiu	$t1,$t8,0x60
/*  f0b68f4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0b68f8:	27af0074 */ 	addiu	$t7,$sp,0x74
/*  f0b68fc:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0b6900:	e7b00114 */ 	swc1	$f16,0x114($sp)
/*  f0b6904:	8c6e19c8 */ 	lw	$t6,0x19c8($v1)
/*  f0b6908:	55c00227 */ 	bnezl	$t6,.NB0f0b71a8
/*  f0b690c:	8c6f00bc */ 	lw	$t7,0xbc($v1)
/*  f0b6910:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0b6914:	afa000f0 */ 	sw	$zero,0xf0($sp)
.NB0f0b6918:
/*  f0b6918:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b691c:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0b6920:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f0b6924:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f0b6928:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f0b692c:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f0b6930:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f0b6934:	1709fff8 */ 	bne	$t8,$t1,.NB0f0b6918
/*  f0b6938:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f0b693c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0b6940:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f0b6944:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b6948:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0b694c:	0fc27de9 */ 	jal	bgunGetWeaponNum2
/*  f0b6950:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0b6954:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b6958:	240a0056 */ 	addiu	$t2,$zero,0x56
/*  f0b695c:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f0b6960:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0b6964:	afaa0068 */ 	sw	$t2,0x68($sp)
/*  f0b6968:	afab0064 */ 	sw	$t3,0x64($sp)
/*  f0b696c:	afa00060 */ 	sw	$zero,0x60($sp)
/*  f0b6970:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f0b6974:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0b6978:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0b697c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b6980:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f0b6984:	0fc2d911 */ 	jal	currentPlayerChooseBodyAndHead
/*  f0b6988:	adac19c8 */ 	sw	$t4,0x19c8($t5)
/*  f0b698c:	8e0e02ac */ 	lw	$t6,0x2ac($s0)
/*  f0b6990:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0b6994:	3c08800a */ 	lui	$t0,0x800a
/*  f0b6998:	15c10003 */ 	bne	$t6,$at,.NB0f0b69a8
/*  f0b699c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b69a0:	8d0825b0 */ 	lw	$t0,0x25b0($t0)
/*  f0b69a4:	afa8006c */ 	sw	$t0,0x6c($sp)
.NB0f0b69a8:
/*  f0b69a8:	0fc48dcd */ 	jal	weaponGetModel
/*  f0b69ac:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f0b69b0:	3c038009 */ 	lui	$v1,0x8009
/*  f0b69b4:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f0b69b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b69bc:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0b69c0:	14c30004 */ 	bne	$a2,$v1,.NB0f0b69d4
/*  f0b69c4:	24190056 */ 	addiu	$t9,$zero,0x56
/*  f0b69c8:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0b69cc:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0b69d0:	afa90064 */ 	sw	$t1,0x64($sp)
.NB0f0b69d4:
/*  f0b69d4:	8e180314 */ 	lw	$t8,0x314($s0)
/*  f0b69d8:	53000020 */ 	beqzl	$t8,.NB0f0b6a5c
/*  f0b69dc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b69e0:	14c300e0 */ 	bne	$a2,$v1,.NB0f0b6d64
/*  f0b69e4:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f0b69e8:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0b69ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0b69f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0b69f4:	11e00003 */ 	beqz	$t7,.NB0f0b6a04
/*  f0b69f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0b69fc:	10000001 */ 	beqz	$zero,.NB0f0b6a04
/*  f0b6a00:	00c02825 */ 	or	$a1,$a2,$zero
.NB0f0b6a04:
/*  f0b6a04:	8e0a0068 */ 	lw	$t2,0x68($s0)
/*  f0b6a08:	00001025 */ 	or	$v0,$zero,$zero
/*  f0b6a0c:	11400003 */ 	beqz	$t2,.NB0f0b6a1c
/*  f0b6a10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6a14:	10000001 */ 	beqz	$zero,.NB0f0b6a1c
/*  f0b6a18:	00c01825 */ 	or	$v1,$a2,$zero
.NB0f0b6a1c:
/*  f0b6a1c:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f0b6a20:	11600003 */ 	beqz	$t3,.NB0f0b6a30
/*  f0b6a24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6a28:	10000001 */ 	beqz	$zero,.NB0f0b6a30
/*  f0b6a2c:	00c02025 */ 	or	$a0,$a2,$zero
.NB0f0b6a30:
/*  f0b6a30:	8e0c0070 */ 	lw	$t4,0x70($s0)
/*  f0b6a34:	11800003 */ 	beqz	$t4,.NB0f0b6a44
/*  f0b6a38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6a3c:	10000001 */ 	beqz	$zero,.NB0f0b6a44
/*  f0b6a40:	00c01025 */ 	or	$v0,$a2,$zero
.NB0f0b6a44:
/*  f0b6a44:	00446821 */ 	addu	$t5,$v0,$a0
/*  f0b6a48:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f0b6a4c:	01c54021 */ 	addu	$t0,$t6,$a1
/*  f0b6a50:	54c800c5 */ 	bnel	$a2,$t0,.NB0f0b6d68
/*  f0b6a54:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b6a58:	8e190284 */ 	lw	$t9,0x284($s0)
.NB0f0b6a5c:
/*  f0b6a5c:	3c05800a */ 	lui	$a1,0x800a
/*  f0b6a60:	24a52780 */ 	addiu	$a1,$a1,0x2780
/*  f0b6a64:	8f291bd4 */ 	lw	$t1,0x1bd4($t9)
/*  f0b6a68:	55200017 */ 	bnezl	$t1,.NB0f0b6ac8
/*  f0b6a6c:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f0b6a70:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0b6a74:	5700000d */ 	bnezl	$t8,.NB0f0b6aac
/*  f0b6a78:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b6a7c:	0fc26fc8 */ 	jal	bgun0f09e004
/*  f0b6a80:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0b6a84:	3c05800a */ 	lui	$a1,0x800a
/*  f0b6a88:	24a52780 */ 	addiu	$a1,$a1,0x2780
/*  f0b6a8c:	10400006 */ 	beqz	$v0,.NB0f0b6aa8
/*  f0b6a90:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b6a94:	0fc26f42 */ 	jal	bgun0f09ddec
/*  f0b6a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6a9c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b6aa0:	10000008 */ 	beqz	$zero,.NB0f0b6ac4
/*  f0b6aa4:	ade21bd4 */ 	sw	$v0,0x1bd4($t7)
.NB0f0b6aa8:
/*  f0b6aa8:	8e030284 */ 	lw	$v1,0x284($s0)
.NB0f0b6aac:
/*  f0b6aac:	ac6019c8 */ 	sw	$zero,0x19c8($v1)
/*  f0b6ab0:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f0b6ab4:	554001d3 */ 	bnezl	$t2,.NB0f0b7204
/*  f0b6ab8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b6abc:	100001d0 */ 	beqz	$zero,.NB0f0b7200
/*  f0b6ac0:	ae060320 */ 	sw	$a2,0x320($s0)
.NB0f0b6ac4:
/*  f0b6ac4:	240b0008 */ 	addiu	$t3,$zero,0x8
.NB0f0b6ac8:
/*  f0b6ac8:	3c018008 */ 	lui	$at,0x8008
/*  f0b6acc:	0fc26f42 */ 	jal	bgun0f09ddec
/*  f0b6ad0:	a42b2470 */ 	sh	$t3,0x2470($at)
/*  f0b6ad4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b6ad8:	24030040 */ 	addiu	$v1,$zero,0x40
/*  f0b6adc:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6ae0:	8d851bd4 */ 	lw	$a1,0x1bd4($t4)
/*  f0b6ae4:	00a36821 */ 	addu	$t5,$a1,$v1
/*  f0b6ae8:	246300cb */ 	addiu	$v1,$v1,0xcb
/*  f0b6aec:	346e003f */ 	ori	$t6,$v1,0x3f
/*  f0b6af0:	acad0020 */ 	sw	$t5,0x20($a1)
/*  f0b6af4:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b6af8:	39c8003f */ 	xori	$t0,$t6,0x3f
/*  f0b6afc:	2503043f */ 	addiu	$v1,$t0,0x43f
/*  f0b6b00:	3469003f */ 	ori	$t1,$v1,0x3f
/*  f0b6b04:	3938003f */ 	xori	$t8,$t1,0x3f
/*  f0b6b08:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b6b0c:	270300a7 */ 	addiu	$v1,$t8,0xa7
/*  f0b6b10:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b6b14:	346a003f */ 	ori	$t2,$v1,0x3f
/*  f0b6b18:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b6b1c:	394b003f */ 	xori	$t3,$t2,0x3f
/*  f0b6b20:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b6b24:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f0b6b28:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f0b6b2c:	afb90058 */ 	sw	$t9,0x58($sp)
/*  f0b6b30:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0b6b34:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6b38:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0b6b3c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0b6b40:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0b6b44:	afa500ec */ 	sw	$a1,0xec($sp)
/*  f0b6b48:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f0b6b4c:	244e003f */ 	addiu	$t6,$v0,0x3f
/*  f0b6b50:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f0b6b54:	35c8003f */ 	ori	$t0,$t6,0x3f
/*  f0b6b58:	3919003f */ 	xori	$t9,$t0,0x3f
/*  f0b6b5c:	0329c021 */ 	addu	$t8,$t9,$t1
/*  f0b6b60:	05e0000e */ 	bltz	$t7,.NB0f0b6b9c
/*  f0b6b64:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f0b6b68:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f0b6b6c:	014f5021 */ 	addu	$t2,$t2,$t7
/*  f0b6b70:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0b6b74:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6b78:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f0b6b7c:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0b6b80:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6b84:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b6b88:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0b6b8c:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b6b90:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0b6b94:	016e4021 */ 	addu	$t0,$t3,$t6
/*  f0b6b98:	afa800e4 */ 	sw	$t0,0xe4($sp)
.NB0f0b6b9c:
/*  f0b6b9c:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0b6ba0:	0720000b */ 	bltz	$t9,.NB0f0b6bd0
/*  f0b6ba4:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f0b6ba8:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6bac:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b6bb0:	0fc58635 */ 	jal	fileGetInflatedLength
/*  f0b6bb4:	9484d8d0 */ 	lhu	$a0,-0x2730($a0)
/*  f0b6bb8:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0b6bbc:	244f003f */ 	addiu	$t7,$v0,0x3f
/*  f0b6bc0:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b6bc4:	394c003f */ 	xori	$t4,$t2,0x3f
/*  f0b6bc8:	030c6821 */ 	addu	$t5,$t8,$t4
/*  f0b6bcc:	afad00e4 */ 	sw	$t5,0xe4($sp)
.NB0f0b6bd0:
/*  f0b6bd0:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b6bd4:	256e4000 */ 	addiu	$t6,$t3,0x4000
/*  f0b6bd8:	0fc26f46 */ 	jal	bgun0f09ddfc
/*  f0b6bdc:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0b6be0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b6be4:	8fa900e4 */ 	lw	$t1,0xe4($sp)
/*  f0b6be8:	8d191bd4 */ 	lw	$t9,0x1bd4($t0)
/*  f0b6bec:	03297821 */ 	addu	$t7,$t9,$t1
/*  f0b6bf0:	0fc26f46 */ 	jal	bgun0f09ddfc
/*  f0b6bf4:	afaf00e8 */ 	sw	$t7,0xe8($sp)
/*  f0b6bf8:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f0b6bfc:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b6c00:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0b6c04:	0fc5b6c2 */ 	jal	func0f172e70
/*  f0b6c08:	004a3023 */ 	subu	$a2,$v0,$t2
/*  f0b6c0c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0b6c10:	8fa200f0 */ 	lw	$v0,0xf0($sp)
/*  f0b6c14:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0b6c18:	00186080 */ 	sll	$t4,$t8,0x2
/*  f0b6c1c:	01986021 */ 	addu	$t4,$t4,$t8
/*  f0b6c20:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0b6c24:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0b6c28:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6c2c:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0b6c30:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6c34:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b6c38:	01a22821 */ 	addu	$a1,$t5,$v0
/*  f0b6c3c:	0c0091a1 */ 	jal	func0f1a7794
/*  f0b6c40:	01623023 */ 	subu	$a2,$t3,$v0
/*  f0b6c44:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0b6c48:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6c4c:	afa200fc */ 	sw	$v0,0xfc($sp)
/*  f0b6c50:	000e4080 */ 	sll	$t0,$t6,0x2
/*  f0b6c54:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f0b6c58:	00084080 */ 	sll	$t0,$t0,0x2
/*  f0b6c5c:	00882021 */ 	addu	$a0,$a0,$t0
/*  f0b6c60:	0fc586ed */ 	jal	fileGetSize
/*  f0b6c64:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6c68:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f0b6c6c:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b6c70:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6c74:	00594821 */ 	addu	$t1,$v0,$t9
/*  f0b6c78:	252f003f */ 	addiu	$t7,$t1,0x3f
/*  f0b6c7c:	35ea003f */ 	ori	$t2,$t7,0x3f
/*  f0b6c80:	3958003f */ 	xori	$t8,$t2,0x3f
/*  f0b6c84:	0580001b */ 	bltz	$t4,.NB0f0b6cf4
/*  f0b6c88:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0b6c8c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b6c90:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b6c94:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f0b6c98:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f0b6c9c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b6ca0:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b6ca4:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6ca8:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b6cac:	01782821 */ 	addu	$a1,$t3,$t8
/*  f0b6cb0:	0c0091a1 */ 	jal	func0f1a7794
/*  f0b6cb4:	01183023 */ 	subu	$a2,$t0,$t8
/*  f0b6cb8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0b6cbc:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6cc0:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b6cc4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0b6cc8:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0b6ccc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0b6cd0:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0b6cd4:	0fc586ed */ 	jal	fileGetSize
/*  f0b6cd8:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6cdc:	8faf00f0 */ 	lw	$t7,0xf0($sp)
/*  f0b6ce0:	004f5021 */ 	addu	$t2,$v0,$t7
/*  f0b6ce4:	254c003f */ 	addiu	$t4,$t2,0x3f
/*  f0b6ce8:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0b6cec:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0b6cf0:	afab00f0 */ 	sw	$t3,0xf0($sp)
.NB0f0b6cf4:
/*  f0b6cf4:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0b6cf8:	8fa400fc */ 	lw	$a0,0xfc($sp)
/*  f0b6cfc:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f0b6d00:	51c00004 */ 	beqzl	$t6,.NB0f0b6d14
/*  f0b6d04:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0b6d08:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0b6d0c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0b6d10:	8fa4005c */ 	lw	$a0,0x5c($sp)
.NB0f0b6d14:
/*  f0b6d14:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f0b6d18:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0b6d1c:	0c00900f */ 	jal	modelInit
/*  f0b6d20:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b6d24:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f0b6d28:	0c00904e */ 	jal	animInit
/*  f0b6d2c:	8d040020 */ 	lw	$a0,0x20($t0)
/*  f0b6d30:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0b6d34:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0b6d38:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b6d3c:	0fc5b6fb */ 	jal	func0f172f54
/*  f0b6d40:	a7380002 */ 	sh	$t8,0x2($t9)
/*  f0b6d44:	0fc26f42 */ 	jal	bgun0f09ddec
/*  f0b6d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6d4c:	0fc26f46 */ 	jal	bgun0f09ddfc
/*  f0b6d50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b6d54:	0fc5b6fb */ 	jal	func0f172f54
/*  f0b6d58:	27a40100 */ 	addiu	$a0,$sp,0x100
/*  f0b6d5c:	1000005d */ 	beqz	$zero,.NB0f0b6ed4
/*  f0b6d60:	8fae005c */ 	lw	$t6,0x5c($sp)
.NB0f0b6d64:
/*  f0b6d64:	00097880 */ 	sll	$t7,$t1,0x2
.NB0f0b6d68:
/*  f0b6d68:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b6d6c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0b6d70:	254af764 */ 	addiu	$t2,$t2,-2204
/*  f0b6d74:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b6d78:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b6d7c:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b6d80:	5480000e */ 	bnezl	$a0,.NB0f0b6dbc
/*  f0b6d84:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0b6d88:	0c0091cd */ 	jal	fileLoad
/*  f0b6d8c:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b6d90:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0b6d94:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0b6d98:	256bf764 */ 	addiu	$t3,$t3,-2204
/*  f0b6d9c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b6da0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b6da4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b6da8:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b6dac:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b6db0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0b6db4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b6db8:	8c6e0000 */ 	lw	$t6,0x0($v1)
.NB0f0b6dbc:
/*  f0b6dbc:	afa400fc */ 	sw	$a0,0xfc($sp)
/*  f0b6dc0:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0b6dc4:	000ec040 */ 	sll	$t8,$t6,0x1
/*  f0b6dc8:	07010003 */ 	bgez	$t8,.NB0f0b6dd8
/*  f0b6dcc:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f0b6dd0:	1000003f */ 	beqz	$zero,.NB0f0b6ed0
/*  f0b6dd4:	afb90064 */ 	sw	$t9,0x64($sp)
.NB0f0b6dd8:
/*  f0b6dd8:	11200005 */ 	beqz	$t1,.NB0f0b6df0
/*  f0b6ddc:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0b6de0:	0fc621cf */ 	jal	func0f18e57c
/*  f0b6de4:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0b6de8:	10000039 */ 	beqz	$zero,.NB0f0b6ed0
/*  f0b6dec:	afa200f8 */ 	sw	$v0,0xf8($sp)
.NB0f0b6df0:
/*  f0b6df0:	8e0f0318 */ 	lw	$t7,0x318($s0)
/*  f0b6df4:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0b6df8:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f0b6dfc:	51e00020 */ 	beqzl	$t7,.NB0f0b6e80
/*  f0b6e00:	00097880 */ 	sll	$t7,$t1,0x2
/*  f0b6e04:	914a30e0 */ 	lbu	$t2,0x30e0($t2)
/*  f0b6e08:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b6e0c:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6e10:	10ca001a */ 	beq	$a2,$t2,.NB0f0b6e7c
/*  f0b6e14:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b6e18:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b6e1c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b6e20:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0b6e24:	0c0091cd */ 	jal	fileLoad
/*  f0b6e28:	9484f766 */ 	lhu	$a0,-0x89a($a0)
/*  f0b6e2c:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0b6e30:	3c088008 */ 	lui	$t0,0x8008
/*  f0b6e34:	2508f764 */ 	addiu	$t0,$t0,-2204
/*  f0b6e38:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0b6e3c:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f0b6e40:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0b6e44:	01c81821 */ 	addu	$v1,$t6,$t0
/*  f0b6e48:	94780002 */ 	lhu	$t8,0x2($v1)
/*  f0b6e4c:	3c01800b */ 	lui	$at,0x800b
/*  f0b6e50:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b6e54:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0b6e58:	00390821 */ 	addu	$at,$at,$t9
/*  f0b6e5c:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0b6e60:	ac20af40 */ 	sw	$zero,-0x50c0($at)
/*  f0b6e64:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b6e68:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b6e6c:	0fc0b5be */ 	jal	bodyCalculateHeadOffset
/*  f0b6e70:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f0b6e74:	10000017 */ 	beqz	$zero,.NB0f0b6ed4
/*  f0b6e78:	8fae005c */ 	lw	$t6,0x5c($sp)
.NB0f0b6e7c:
/*  f0b6e7c:	00097880 */ 	sll	$t7,$t1,0x2
.NB0f0b6e80:
/*  f0b6e80:	01e97821 */ 	addu	$t7,$t7,$t1
/*  f0b6e84:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0b6e88:	254af764 */ 	addiu	$t2,$t2,-2204
/*  f0b6e8c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0b6e90:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0b6e94:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f0b6e98:	5480000d */ 	bnezl	$a0,.NB0f0b6ed0
/*  f0b6e9c:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f0b6ea0:	0c0091cd */ 	jal	fileLoad
/*  f0b6ea4:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f0b6ea8:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f0b6eac:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0b6eb0:	256bf764 */ 	addiu	$t3,$t3,-2204
/*  f0b6eb4:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0b6eb8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0b6ebc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0b6ec0:	01ab1821 */ 	addu	$v1,$t5,$t3
/*  f0b6ec4:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f0b6ec8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0b6ecc:	afa400f8 */ 	sw	$a0,0xf8($sp)
.NB0f0b6ed0:
/*  f0b6ed0:	8fae005c */ 	lw	$t6,0x5c($sp)
.NB0f0b6ed4:
/*  f0b6ed4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0b6ed8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0b6edc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0b6ee0:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0b6ee4:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f0b6ee8:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0b6eec:	8fa600fc */ 	lw	$a2,0xfc($sp)
/*  f0b6ef0:	8fa700f8 */ 	lw	$a3,0xf8($sp)
/*  f0b6ef4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0b6ef8:	0fc0b20b */ 	jal	func0f02ce8c
/*  f0b6efc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0b6f00:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b6f04:	af2200d4 */ 	sw	$v0,0xd4($t9)
/*  f0b6f08:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b6f0c:	c7b20114 */ 	lwc1	$f18,0x114($sp)
/*  f0b6f10:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0b6f14:	8c6500d4 */ 	lw	$a1,0xd4($v1)
/*  f0b6f18:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0b6f1c:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0b6f20:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f0b6f24:	0fc08195 */ 	jal	chr0f020b14
/*  f0b6f28:	24870028 */ 	addiu	$a3,$a0,0x28
/*  f0b6f2c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0b6f30:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f0b6f34:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f0b6f38:	a1490000 */ 	sb	$t1,0x0($t2)
/*  f0b6f3c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0b6f40:	8e0b0314 */ 	lw	$t3,0x314($s0)
/*  f0b6f44:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f0b6f48:	11600011 */ 	beqz	$t3,.NB0f0b6f90
/*  f0b6f4c:	8da60004 */ 	lw	$a2,0x4($t5)
/*  f0b6f50:	8e02028c */ 	lw	$v0,0x28c($s0)
/*  f0b6f54:	3c01800b */ 	lui	$at,0x800b
/*  f0b6f58:	3c0f800b */ 	lui	$t7,0x800b
/*  f0b6f5c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0b6f60:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b6f64:	ac260d80 */ 	sw	$a2,0xd80($at)
/*  f0b6f68:	8e080288 */ 	lw	$t0,0x288($s0)
/*  f0b6f6c:	3c01800b */ 	lui	$at,0x800b
/*  f0b6f70:	25ef1068 */ 	addiu	$t7,$t7,0x1068
/*  f0b6f74:	8d180070 */ 	lw	$t8,0x70($t0)
/*  f0b6f78:	002e0821 */ 	addu	$at,$at,$t6
/*  f0b6f7c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0b6f80:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0b6f84:	0019c940 */ 	sll	$t9,$t9,0x5
/*  f0b6f88:	032f4821 */ 	addu	$t1,$t9,$t7
/*  f0b6f8c:	ac290db0 */ 	sw	$t1,0xdb0($at)
.NB0f0b6f90:
/*  f0b6f90:	8cca0018 */ 	lw	$t2,0x18($a2)
/*  f0b6f94:	354c0001 */ 	ori	$t4,$t2,0x1
/*  f0b6f98:	accc0018 */ 	sw	$t4,0x18($a2)
/*  f0b6f9c:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b6fa0:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b6fa4:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b6fa8:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f0b6fac:	0c006f6d */ 	jal	modelSetRootPosition
/*  f0b6fb0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b6fb4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0b6fb8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b6fbc:	8dab00bc */ 	lw	$t3,0xbc($t5)
/*  f0b6fc0:	0fc0f74b */ 	jal	chrSetLookAngle
/*  f0b6fc4:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0b6fc8:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f0b6fcc:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0b6fd0:	a04e0006 */ 	sb	$t6,0x6($v0)
/*  f0b6fd4:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0b6fd8:	a4480010 */ 	sh	$t0,0x10($v0)
/*  f0b6fdc:	0fc0b1e0 */ 	jal	bodyGetRace
/*  f0b6fe0:	84440010 */ 	lh	$a0,0x10($v0)
/*  f0b6fe4:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f0b6fe8:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f0b6fec:	3c048008 */ 	lui	$a0,0x8008
/*  f0b6ff0:	a30202fe */ 	sb	$v0,0x2fe($t8)
/*  f0b6ff4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0b6ff8:	2484f764 */ 	addiu	$a0,$a0,-2204
/*  f0b6ffc:	c7240378 */ 	lwc1	$f4,0x378($t9)
/*  f0b7000:	e7040024 */ 	swc1	$f4,0x24($t8)
/*  f0b7004:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0b7008:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0b700c:	01e50019 */ 	multu	$t7,$a1
/*  f0b7010:	00004812 */ 	mflo	$t1
/*  f0b7014:	00895021 */ 	addu	$t2,$a0,$t1
/*  f0b7018:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*  f0b701c:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0b7020:	000d5e02 */ 	srl	$t3,$t5,0x18
/*  f0b7024:	448b3000 */ 	mtc1	$t3,$f6
/*  f0b7028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b702c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0b7030:	e5c819c4 */ 	swc1	$f8,0x19c4($t6)
/*  f0b7034:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b7038:	c46a19c4 */ 	lwc1	$f10,0x19c4($v1)
/*  f0b703c:	e46a19c0 */ 	swc1	$f10,0x19c0($v1)
/*  f0b7040:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f0b7044:	05020010 */ 	bltzl	$t0,.NB0f0b7088
/*  f0b7048:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b704c:	01050019 */ 	multu	$t0,$a1
/*  f0b7050:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b7054:	c47019c0 */ 	lwc1	$f16,0x19c0($v1)
/*  f0b7058:	0000c812 */ 	mflo	$t9
/*  f0b705c:	0099c021 */ 	addu	$t8,$a0,$t9
/*  f0b7060:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*  f0b7064:	000f4980 */ 	sll	$t1,$t7,0x6
/*  f0b7068:	00095602 */ 	srl	$t2,$t1,0x18
/*  f0b706c:	448a9000 */ 	mtc1	$t2,$f18
/*  f0b7070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b7074:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0b7078:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0b707c:	10000007 */ 	beqz	$zero,.NB0f0b709c
/*  f0b7080:	e46619c0 */ 	swc1	$f6,0x19c0($v1)
/*  f0b7084:	8e030284 */ 	lw	$v1,0x284($s0)
.NB0f0b7088:
/*  f0b7088:	3c014150 */ 	lui	$at,0x4150
/*  f0b708c:	44815000 */ 	mtc1	$at,$f10
/*  f0b7090:	c46819c0 */ 	lwc1	$f8,0x19c0($v1)
/*  f0b7094:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0b7098:	e47219c0 */ 	swc1	$f18,0x19c0($v1)
.NB0f0b709c:
/*  f0b709c:	8c8c00a0 */ 	lw	$t4,0xa0($a0)
/*  f0b70a0:	8c8e071c */ 	lw	$t6,0x71c($a0)
/*  f0b70a4:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b70a8:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0b70ac:	000e4180 */ 	sll	$t0,$t6,0x6
/*  f0b70b0:	0008ce02 */ 	srl	$t9,$t0,0x18
/*  f0b70b4:	000d5e02 */ 	srl	$t3,$t5,0x18
/*  f0b70b8:	0179c021 */ 	addu	$t8,$t3,$t9
/*  f0b70bc:	44988000 */ 	mtc1	$t8,$f16
/*  f0b70c0:	c46419c0 */ 	lwc1	$f4,0x19c0($v1)
/*  f0b70c4:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f0b70c8:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0b70cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b70d0:	45020004 */ 	bc1fl	.NB0f0b70e4
/*  f0b70d4:	c46619c4 */ 	lwc1	$f6,0x19c4($v1)
/*  f0b70d8:	e46019c0 */ 	swc1	$f0,0x19c0($v1)
/*  f0b70dc:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b70e0:	c46619c4 */ 	lwc1	$f6,0x19c4($v1)
.NB0f0b70e4:
/*  f0b70e4:	e46619bc */ 	swc1	$f6,0x19bc($v1)
/*  f0b70e8:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f0b70ec:	05e00023 */ 	bltz	$t7,.NB0f0b717c
/*  f0b70f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b70f4:	8e090314 */ 	lw	$t1,0x314($s0)
/*  f0b70f8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0b70fc:	258cd8cc */ 	addiu	$t4,$t4,-10036
/*  f0b7100:	15200013 */ 	bnez	$t1,.NB0f0b7150
/*  f0b7104:	000f50c0 */ 	sll	$t2,$t7,0x3
/*  f0b7108:	8fae00f0 */ 	lw	$t6,0xf0($sp)
/*  f0b710c:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0b7110:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f0b7114:	014c1821 */ 	addu	$v1,$t2,$t4
/*  f0b7118:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b711c:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f0b7120:	27a70100 */ 	addiu	$a3,$sp,0x100
/*  f0b7124:	01ae2821 */ 	addu	$a1,$t5,$t6
/*  f0b7128:	0c0091a1 */ 	jal	func0f1a7794
/*  f0b712c:	010e3023 */ 	subu	$a2,$t0,$t6
/*  f0b7130:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0b7134:	afa200f4 */ 	sw	$v0,0xf4($sp)
/*  f0b7138:	0fc586ed */ 	jal	fileGetSize
/*  f0b713c:	94640004 */ 	lhu	$a0,0x4($v1)
/*  f0b7140:	0c008f6f */ 	jal	modelCalculateRwDataLen
/*  f0b7144:	8fa400f4 */ 	lw	$a0,0xf4($sp)
/*  f0b7148:	10000004 */ 	beqz	$zero,.NB0f0b715c
/*  f0b714c:	8fb900dc */ 	lw	$t9,0xdc($sp)
.NB0f0b7150:
/*  f0b7150:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f0b7154:	afa000f4 */ 	sw	$zero,0xf4($sp)
/*  f0b7158:	8fb900dc */ 	lw	$t9,0xdc($sp)
.NB0f0b715c:
/*  f0b715c:	8fb800f4 */ 	lw	$t8,0xf4($sp)
/*  f0b7160:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b7164:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0b7168:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0b716c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0b7170:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0b7174:	0fc22844 */ 	jal	weaponCreateForChr
/*  f0b7178:	afb80014 */ 	sw	$t8,0x14($sp)
.NB0f0b717c:
/*  f0b717c:	0fc2938f */ 	jal	bgunAllocateFireslot
/*  f0b7180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0b7184:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0b7188:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b718c:	0fc0b8b8 */ 	jal	func0f02e9a0
/*  f0b7190:	a082017c */ 	sb	$v0,0x17c($a0)
/*  f0b7194:	0fc3243d */ 	jal	bmove0f0cb8c4
/*  f0b7198:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0b719c:	10000019 */ 	beqz	$zero,.NB0f0b7204
/*  f0b71a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b71a4:	8c6f00bc */ 	lw	$t7,0xbc($v1)
.NB0f0b71a8:
/*  f0b71a8:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0b71ac:	8c8a0020 */ 	lw	$t2,0x20($a0)
/*  f0b71b0:	8d4c0020 */ 	lw	$t4,0x20($t2)
/*  f0b71b4:	55800013 */ 	bnezl	$t4,.NB0f0b7204
/*  f0b71b8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0b71bc:	8c8d0018 */ 	lw	$t5,0x18($a0)
/*  f0b71c0:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0b71c4:	35ae0001 */ 	ori	$t6,$t5,0x1
/*  f0b71c8:	0fc0b8b8 */ 	jal	func0f02e9a0
/*  f0b71cc:	ac8e0018 */ 	sw	$t6,0x18($a0)
/*  f0b71d0:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f0b71d4:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f0b71d8:	8c6400d4 */ 	lw	$a0,0xd4($v1)
/*  f0b71dc:	0c006f6d */ 	jal	modelSetRootPosition
/*  f0b71e0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0b71e4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0b71e8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0b71ec:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f0b71f0:	0fc0f74b */ 	jal	chrSetLookAngle
/*  f0b71f4:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0b71f8:	0fc3243d */ 	jal	bmove0f0cb8c4
/*  f0b71fc:	8e040284 */ 	lw	$a0,0x284($s0)
.NB0f0b7200:
/*  f0b7200:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f0b7204:
/*  f0b7204:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0b7208:	27bd0118 */ 	addiu	$sp,$sp,0x118
/*  f0b720c:	03e00008 */ 	jr	$ra
/*  f0b7210:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void func0f0b9538(void)
{
	if (g_Vars.currentplayer->haschrbody) {
		if (!g_Vars.mplayerisrunning || (IS4MB() && PLAYERCOUNT() == 1)) {
			g_Vars.currentplayer->haschrbody = false;
			chr0f020d44(g_Vars.currentplayer->prop, false);
			g_Vars.currentplayer->model00d4 = NULL;
			bmove0f0cb8c4(g_Vars.currentplayer);
			bgun0f09df50();
			g_Vars.currentplayer->unk1bd4 = 0;
		}
	}
}

void setTickMode(s32 tickmode)
{
	g_Vars.tickmode = tickmode;
	g_Vars.in_cutscene = false;
}

void func0f0b9650(void)
{
	setTickMode(TICKMODE_0);
	var80070744 = 0;
}

void playersBeginMpSwirl(void)
{
	setTickMode(TICKMODE_MPSWIRL);
	var80070744 = 0;
	bmoveSetMode(MOVEMODE_WALK);

	g_MpSwirlRotateSpeed = 0;
	g_MpSwirlAngleDegrees = -90;
	g_MpSwirlForwardSpeed = 0;
	g_MpSwirlDistance = 80;

	skyChooseAndApply(mainGetStageNum(), false);
}

void currentPlayerTickMpSwirl(void)
{
	f32 angle;
	struct coord pos = {0, 0, 0};
	struct coord look = {0, 0, 1};
	struct coord up = {0, 1, 0};
	s32 i;

	currentPlayerSetCameraMode(CAMERAMODE_THIRDPERSON);

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

	func0f0c1840(&pos, &up, &look, &g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms);

	if (g_MpSwirlDistance < 5.0f) {
		currentPlayerEndCutscene();
	}
}

void func0f0b9a20(void)
{
	setTickMode(TICKMODE_NORMAL);
	var80070744 = 0;
	bmoveSetMode(MOVEMODE_WALK);

	if (mainGetStageNum() == STAGE_TEST_LEN) {
		currentPlayerSetFadeColour(0, 0, 0, 1);
		currentPlayerSetFadeFrac(0, 1);
	} else if (var80070748 != 0) {
		currentPlayerSetFadeColour(0, 0, 0, 1);
		currentPlayerSetFadeFrac(60, 0);
	}

	skyChooseAndApply(mainGetStageNum(), false);
	bgunEquipWeapon2(HAND_LEFT, g_DefaultWeapons[HAND_LEFT]);
	bgunEquipWeapon2(HAND_RIGHT, g_DefaultWeapons[HAND_RIGHT]);
	var8007074c = 0;
}

void currentPlayerEndCutscene(void)
{
	if (g_IsTitleDemo) {
		mainChangeToStage(STAGE_TITLE);
	} else if (g_Vars.autocutplaying) {
		g_Vars.autocutfinished = true;
	} else {
		setTickMode(TICKMODE_NORMAL);
		var80070744 = 0;
		bmoveSetModeForAllPlayers(MOVEMODE_WALK);
	}
}

void currentPlayerPrepareWarpToPad(s16 pad)
{
	setTickMode(TICKMODE_WARP);
	var80070744 = 0;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	allPlayersClearMemCamRoom();
	g_WarpPadId = pad;
}

void currentPlayerPrepareWarpType2(struct var8009ddec *cmd, s32 arg1, s32 arg2)
{
	setTickMode(TICKMODE_WARP);
	var80070744 = 0;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	allPlayersClearMemCamRoom();
	g_WarpPadId = -1;
	var8009ddec = cmd;
	var8009de08 = arg1;
	var8009de0c = arg2;
}

void currentPlayerPrepareWarpType3(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5)
{
	setTickMode(TICKMODE_WARP);
	var80070744 = 0;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	allPlayersClearMemCamRoom();
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
glabel currentPlayerExecutePreparedWarp
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
/*  f0b9d34:	0fc3060c */ 	jal	currentPlayerSetCameraMode
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
/*  f0b9ff4:	0fc306e9 */ 	jal	func0f0c1ba4
/*  f0b9ff8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0b9ffc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ba000:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0ba004:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0ba008:	03e00008 */ 	jr	$ra
/*  f0ba00c:	00000000 */ 	nop
);

// Mismatch: Can't match the last section's pos
//void currentPlayerExecutePreparedWarp(void)
//{
//	struct pad pad; // 64
//	struct coord pos = {0, 0, 0}; // 58
//	struct coord look = {0, 0, 1}; // 4c
//	struct coord up = {0, 1, 0}; // 40
//	s32 room; // 3c
//	struct coord memcampos; // 30
//
//	currentPlayerSetCameraMode(CAMERAMODE_THIRDPERSON);
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
//	func0f0c1ba4(&pos, &up, &look, &memcampos, room);
//}

void func0f0ba010(void)
{
	setTickMode(TICKMODE_CUTSCENE);
	var80070744 = 0;
	bmoveSetModeForAllPlayers(MOVEMODE_CUTSCENE);
	allPlayersClearMemCamRoom();

#if VERSION >= VERSION_PAL_FINAL
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

void cameraDoAnimation(s16 animnum)
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
			func0f0b85f8();
		}

		g_CutsceneAnimNum = animnum;

		if (g_Vars.currentplayer->haschrbody) {
			func0f0ba010();
		}
	}
}

void func0f0ba190(u32 arg0)
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

void func0f0ba29c(bool arg0)
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
#if VERSION >= VERSION_PAL_FINAL
	u8 stack3[0x2c];
#endif
	f32 barfrac;
	f32 sp104;
	Mtxf spc4;
	Mtxf sp84;
	u32 stack1;
	struct coord sp74;
	u32 stack2;
	struct coord sp64;
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
#if VERSION >= VERSION_PAL_FINAL
			g_CutsceneCurAnimFrame240 += g_Vars.lvupdate240freal;
			g_CutsceneCurAnimFrame60 = floorf(g_CutsceneCurAnimFrame240 + 0.01f);
#else
			g_CutsceneCurAnimFrame240 += g_Vars.lvupdate240;
			g_CutsceneCurAnimFrame60 = g_CutsceneCurAnimFrame240 >> 2;
#endif

			if (g_Anims[g_CutsceneAnimNum].flags & ANIMFLAG_08) {
				while (g_CutsceneCurAnimFrame60 < endframe && anim000239e0(g_CutsceneAnimNum, g_CutsceneCurAnimFrame60)) {
#if VERSION >= VERSION_PAL_FINAL
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
#if VERSION >= VERSION_PAL_FINAL
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
		func0f097044(&spc4, &sp74);
		func0f097044(&sp84, &sp64);
		func0f0976c0(&sp64, &sp74);
		func0f0972b8(&sp74, &sp64, sp104, sp54);
		func0f096ed4(sp54, &sp11c);

		up.x = sp11c.m[1][0];
		up.y = sp11c.m[1][1];
		up.z = sp11c.m[1][2];

		look.x = sp11c.m[2][0];
		look.y = sp11c.m[2][1];
		look.z = sp11c.m[2][2];

		g_CutsceneBlurFrac += barfrac * (0 - g_CutsceneBlurFrac);
		fovy += barfrac * (60 - fovy);
	}

	currentPlayerSetCameraMode(CAMERAMODE_THIRDPERSON);
	func0f0c1bd8(&pos, &up, &look);
	currentPlayerSetFovY(fovy);
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

f32 cutsceneGetBlurFrac(void)
{
	return g_CutsceneBlurFrac;
}

void currentPlayerSetZoomFovY(f32 fovy, f32 timemax)
{
	g_Vars.currentplayer->zoomintime = 0;
	g_Vars.currentplayer->zoomintimemax = timemax;
	g_Vars.currentplayer->zoominfovyold = g_Vars.currentplayer->zoominfovy;
	g_Vars.currentplayer->zoominfovynew = fovy;
}

f32 currentPlayerGetZoomFovY(void)
{
	if (g_Vars.currentplayer->zoomintimemax > g_Vars.currentplayer->zoomintime) {
		return g_Vars.currentplayer->zoominfovynew;
	}

	return g_Vars.currentplayer->zoominfovy;
}

void func0f0ba8b0(f32 fovy)
{
	if (currentPlayerGetZoomFovY() != fovy) {
		if (fovy < g_Vars.currentplayer->zoominfovy) {
			currentPlayerSetZoomFovY(fovy, (g_Vars.currentplayer->zoominfovy - fovy) * 15.0f / 30.0f);
		} else {
			currentPlayerSetZoomFovY(fovy, (fovy - g_Vars.currentplayer->zoominfovy) * 15.0f / 30.0f);
		}
	}
}

f32 currentPlayerGetTeleportFovY(void)
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

void currentPlayerUpdateZoom(void)
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

	currentPlayerSetFovY(g_Vars.currentplayer->zoominfovy);
	viSetFovY(g_Vars.currentplayer->zoominfovy);

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		fovy = currentPlayerGetTeleportFovY();
		currentPlayerSetFovY(fovy);
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

void func0f0bace0(void)
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

void currentPlayerTickPauseMenu(void)
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

void currentPlayerPause(s32 root)
{
	g_GlobalMenuRoot = root;

	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
		g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSING;
	}
}

void currentPlayerUnpause(void)
{
	if (g_Vars.currentplayer->pausemode == PAUSEMODE_PAUSED) {
		lvSetPaused(false);
		musicEndMenu();
		g_Vars.currentplayer->pausemode = PAUSEMODE_UNPAUSED;
	}
}

Gfx *func0f0baf84(Gfx *gdl)
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

Gfx *fadeDraw(Gfx *gdl, u32 r, u32 g, u32 b, f32 frac)
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

Gfx *currentPlayerDrawFade(Gfx *gdl)
{
	return fadeDraw(gdl,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			g_Vars.currentplayer->colourscreenfrac);
}

void currentPlayerSetFadeColour(s32 r, s32 g, s32 b, f32 frac)
{
	g_Vars.currentplayer->colourscreenred = r;
	g_Vars.currentplayer->colourscreengreen = g;
	g_Vars.currentplayer->colourscreenblue = b;
	g_Vars.currentplayer->colourscreenfrac = frac;
}

void currentPlayerAdjustFade(f32 maxfadetime, s32 r, s32 g, s32 b, f32 frac)
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

void currentPlayerSetFadeFrac(f32 maxfadetime, f32 frac)
{
	currentPlayerAdjustFade(maxfadetime,
			g_Vars.currentplayer->colourscreenred,
			g_Vars.currentplayer->colourscreengreen,
			g_Vars.currentplayer->colourscreenblue,
			frac);
}

bool currentPlayerIsFadeComplete(void)
{
	return g_Vars.currentplayer->colourfadetimemax60 < 0;
}

void currentPlayerUpdateColourScreenProperties(void)
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

void currentPlayerStartChrFade(f32 duration60, f32 targetfrac)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;

	if (chr) {
		g_Vars.currentplayer->bondfadetime60 = 0;
		g_Vars.currentplayer->bondfadetimemax60 = duration60;
		g_Vars.currentplayer->bondfadefracold = chr->fadealpha / 255.0f;
		g_Vars.currentplayer->bondfadefracnew = targetfrac;
	}
}

void currentPlayerTickChrFade(void)
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
void currentPlayerDisplayHealth(void)
{
	switch (g_Vars.currentplayer->healthshowmode) {
	case HEALTHSHOWMODE_HIDDEN:
		g_Vars.currentplayer->oldhealth = g_Vars.currentplayer->bondhealth;
		g_Vars.currentplayer->oldarmour = currentPlayerGetShieldFrac();
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
		g_Vars.currentplayer->oldarmour = currentPlayerGetShieldFrac();
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
		g_Vars.currentplayer->healthshowtime = g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].openendframe * currentPlayerGetHealthBarHeightFrac();
		g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_OPENING;
		break;
	}
}

/**
 * Update properties relating to the damage flash and health bar updating.
 */
void currentPlayerTickDamageAndHealth(void)
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
			g_Vars.currentplayer->damagetype = (s32)(currentPlayerGetHealthFrac() * 8.0f);

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

				currentPlayerSetFadeColour(
						g_DamageTypes[g_Vars.currentplayer->damagetype].red,
						g_DamageTypes[g_Vars.currentplayer->damagetype].green,
						g_DamageTypes[g_Vars.currentplayer->damagetype].blue, alpha);
			}
		} else {
			g_Vars.currentplayer->damageshowtime = -1;
			currentPlayerSetFadeColour(0xff, 0xff, 0xff, 0);

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
	if (currentPlayerIsHealthVisible()) {
		if (g_Vars.currentplayer->healthshowmode == HEALTHSHOWMODE_OPENING) {
			g_Vars.currentplayer->healthdamagetype = (s32)((currentPlayerGetHealthFrac() + currentPlayerGetShieldFrac()) * 8.0f);

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
				armourdiff = g_Vars.currentplayer->oldarmour - currentPlayerGetShieldFrac();

				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->oldhealth - frac * healthdiff;
				g_Vars.currentplayer->apparentarmour = g_Vars.currentplayer->oldarmour - frac * armourdiff;

				if (g_Vars.currentplayer->healthshowtime >= g_HealthDamageTypes[g_Vars.currentplayer->healthdamagetype].updateendframe) {
					g_Vars.currentplayer->healthshowmode = HEALTHSHOWMODE_CURRENT;
				}
				break;
			case HEALTHSHOWMODE_CURRENT:
				g_Vars.currentplayer->apparenthealth = g_Vars.currentplayer->bondhealth;
				g_Vars.currentplayer->apparentarmour = currentPlayerGetShieldFrac();
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

bool currentPlayerIsDamageVisible(void)
{
	return g_Vars.currentplayer->damageshowtime >= 0;
}

/**
 * Trigger the red flash when the player is damaged.
 *
 * May be called while the red flash is already happening, which may result in
 * the fade being reset to the full alpha point.
 */
void currentPlayerDisplayDamage(void)
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

Gfx *hudRenderHealthBar(Gfx *gdl)
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

void currentPlayerSurroundWithExplosions(s32 arg0)
{
	g_Vars.currentplayer->bondexploding = true;
	g_Vars.currentplayer->bondnextexplode = arg0 + g_Vars.lvframe60;
	g_Vars.currentplayer->bondcurexplode = 0;
}

void currentPlayerTickExplode(void)
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

		g_Vars.currentplayer->bondnextexplode = g_Vars.lvframe60 + PALDOWN(15) + (random() % PALDOWN(15));
	}
}

void viResetLoResIf4Mb(void)
{
	if (IS4MB()) {
#if PAL
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

void optionsSetHiRes(bool enable)
{
	g_HiResEnabled = enable;
}

s16 viGetFbWidth(void)
{
	s16 width = g_ViModes[g_ViRes].fbwidth;
	return width;
}

s16 viGetFbHeight(void)
{
	s16 height = g_ViModes[g_ViRes].fbheight;

	if (g_Vars.fourmeg2player) {
		height = height >> 1;
	}

	return height;
}

#if VERSION >= VERSION_NTSC_1_0
bool is2PSharedViewport(void)
{
	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& menuGetRoot() == MENUROOT_MPENDSCREEN
			&& var8009dfc0 == 0) {
		return true;
	}

	return (g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE;
}
#endif

s16 currentPlayerGetViewportWidth(void)
{
	s16 width;

#if VERSION >= VERSION_NTSC_1_0
	if (!is2PSharedViewport())
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

s16 currentPlayerGetViewportLeft(void)
{
#if VERSION >= VERSION_NTSC_1_0
	s32 something = !is2PSharedViewport();
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

s16 currentPlayerGetViewportHeight(void)
{
	s16 height;

	if (PLAYERCOUNT() >= 2
#if VERSION >= VERSION_NTSC_1_0
			&& !is2PSharedViewport()
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
s16 currentPlayerGetViewportTop(void)
{
	s16 top;

	if (PLAYERCOUNT() >= 2
#if VERSION >= VERSION_NTSC_1_0
			&& !is2PSharedViewport()
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
glabel currentPlayerGetViewportTop
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

f32 func0f0bd358(void)
{
	f32 result;
	s16 stack;
	s16 height = currentPlayerGetViewportHeight();
	s16 width = currentPlayerGetViewportWidth();

	result = (f32)width / (f32)height;
	result = g_ViModes[g_ViRes].yscale * result;

	return result;
}

void func0f0bd3c4(void)
{
	struct coord coord = {0, 0, 0};

	if (g_Vars.currentplayer->isdead == false) {
		func0f12acec(&g_Vars.currentplayer->bond2.unk10, &g_Vars.currentplayer->bond2.unk1c, &coord);
	} else {
		viShake(0);
	}
}

void currentPlayerAutoWalk(s16 aimpad, u8 walkspeed, u8 turnspeed, u8 lookup, u8 dist)
{
	setTickMode(TICKMODE_AUTOWALK);
	g_Vars.currentplayer->autocontrol_aimpad = aimpad;
	g_Vars.currentplayer->autocontrol_walkspeed = walkspeed;
	g_Vars.currentplayer->autocontrol_turnspeed = turnspeed;
	g_Vars.currentplayer->autocontrol_lookup = lookup;
	g_Vars.currentplayer->autocontrol_dist = dist;
}

void currentPlayerLaunchSlayerRocket(struct weaponobj *rocket)
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

void currentPlayerTickTeleport(f32 *aspectratio)
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
		f32 fovy = currentPlayerGetTeleportFovY();
		currentPlayerSetFovY(fovy);
		viSetFovY(fovy);
	}
}

void currentPlayerConfigureVi(void)
{
	f32 ratio = func0f0bd358();
	g_ViRes = VIRES_LO;

	func0f1531dc(false);

	currentPlayerSetFovY(60);
	currentPlayerSetAspectRatio(ratio);
	currentPlayerSetViewSize(currentPlayerGetViewportWidth(), currentPlayerGetViewportHeight());
	currentPlayerSetViewPosition(currentPlayerGetViewportLeft(), currentPlayerGetViewportTop());

	viSetMode(g_ViModes[g_ViRes].xscale);

	viSetFovAspectAndSize(60, ratio, currentPlayerGetViewportWidth(), currentPlayerGetViewportHeight());

	viSetViewPosition(currentPlayerGetViewportLeft(), currentPlayerGetViewportTop());
	viSetSize(viGetFbWidth(), viGetFbHeight());
	viSetBufSize(viGetFbWidth(), viGetFbHeight());
}

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
		aspectratio = func0f0bd358() * 1.33333333f;
	} else {
		aspectratio = func0f0bd358();
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
		currentPlayerTickTeleport(&aspectratio);
	}

	if (g_Vars.stagenum == STAGE_TEST_OLD && func0f01ad5c()) {
		func0f01adb8();
		return;
	}

	currentPlayerSetFovY(60);
	currentPlayerSetAspectRatio(aspectratio);
	currentPlayerSetViewSize(currentPlayerGetViewportWidth(), currentPlayerGetViewportHeight());
	currentPlayerSetViewPosition(currentPlayerGetViewportLeft(), currentPlayerGetViewportTop());

	viSetMode(g_ViModes[g_ViRes].xscale);
	viSetFovAspectAndSize(60, aspectratio, currentPlayerGetViewportWidth(), currentPlayerGetViewportHeight());
	viSetViewPosition(currentPlayerGetViewportLeft(), currentPlayerGetViewportTop());
	viSetSize(viGetFbWidth(), viGetFbHeight());
	viSetBufSize(viGetFbWidth(), viGetFbHeight());

	currentPlayerUpdateColourScreenProperties();
	currentPlayerTickChrFade();

	bmoveSetAutoAimY(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
	bmoveSetAutoAimX(optionsGetAutoAim(g_Vars.currentplayerstats->mpindex));
	bmoveSetAutoMoveCentreEnabled(optionsGetLookAhead(g_Vars.currentplayerstats->mpindex));
	bgunSetGunAmmoVisible(GUNAMMOREASON_OPTION, optionsGetAmmoOnScreen(g_Vars.currentplayerstats->mpindex));
	bgunSetSightVisible(GUNSIGHTREASON_1, true);

	if ((g_Vars.tickmode == TICKMODE_0 || g_Vars.tickmode == TICKMODE_NORMAL) && !g_InCutscene && !g_MainIsEndscreen) {
		g_Vars.currentplayer->bondviewlevtime60 += g_Vars.lvupdate240_60;
	}

	if (g_Vars.currentplayer->devicesactive & DEVICE_SUICIDEPILL) {
		currentPlayerDieByShooter(g_Vars.currentplayernum, true);
	}

	currentPlayerTickDamageAndHealth();
	currentPlayerTickExplode();

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
							currentPlayerPause(MENUROOT_MAINMENU);
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
					eyespy->prop->chr->soundtimer = PALDOWN(10);
					sndStart(var80095200, SFX_DETONATE, NULL, -1, -1, -1, -1, -1);
				}

				g_Vars.currentplayer->invdowntime = PALDOWN(-40);
			}
		}
	}

	if (lvIsPaused()) {
		func0f0bace0();
	}

	if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
		currentPlayerTickPauseMenu();
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

		func0f0b8ba0();

		if (g_Vars.currentplayer->haschrbody) {
			g_Vars.currentplayer->invdowntime = PALDOWN(-40);
			bmoveTick(0, 0, 0, 1);
			func0f0ba29c(arg0);
			g_Vars.currentplayer->invdowntime = PALDOWN(-40);
		}

		for (i = 0; i < PLAYERCOUNT(); i++) {
			g_Vars.players[i]->joybutinhibit = 0xffffffff;
		}
	} else if (g_Vars.currentplayer->eyespy
			&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
			&& g_Vars.currentplayer->eyespy->active) {
		// Controlling an eyespy
		struct coord sp308;
		currentPlayerSetFovY(120);
		viSetFovY(120);
		sp308.x = g_Vars.currentplayer->eyespy->prop->pos.x;
		sp308.y = g_Vars.currentplayer->eyespy->prop->pos.y;
		sp308.z = g_Vars.currentplayer->eyespy->prop->pos.z;
		func0f0b8ba0();
		bmoveTick(0, 0, 0, 1);
		currentPlayerSetCameraMode(CAMERAMODE_EYESPY);
		func0f0c1bd8(&sp308, &g_Vars.currentplayer->eyespy->up, &g_Vars.currentplayer->eyespy->look);
	} else if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
		// Deep Sea teleport
		func0f0b8ba0();
		g_WarpPadId = g_Vars.currentplayer->teleportcamerapad;
		bmoveTick(0, 0, 0, 1);
		currentPlayerExecutePreparedWarp();
	} else if (g_Vars.currentplayer->visionmode == (u32)VISIONMODE_SLAYERROCKET) {
		// Controlling a Slayer rocket
		struct coord sp2fc = {0, 0, 0};
		struct coord sp2f0 = {0, 0, 1};
		struct coord sp2e4 = {0, 1, 0};

		bool rocketok = false;
		struct weaponobj *rocket = g_Vars.currentplayer->slayerrocket;

		currentPlayerSetCameraMode(CAMERAMODE_THIRDPERSON);
		func0f0b8ba0();
		bmoveTick(0, 0, 0, 1);
		func0f0bd3c4();

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

				if (g_Vars.currentplayer->badrockettime > PALDOWN(120)) {
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
				f32 fVar20;
				f32 sp174;
				f32 sp15c[6];
				f32 sp14c[4];
				f32 sp13c[4];
				f32 targetspeed;
				struct coord sp12c;
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
						currentPlayerPause(MENUROOT_MAINMENU);
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

				fVar20 = sqrtf(sp2ac.f[0] * sp2ac.f[0] + sp2ac.f[2] * sp2ac.f[2]);

				sp2ac.x /= fVar20;
				sp2ac.z /= fVar20;

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

				func0f097738(sp15c, sp14c, sp13c);
				func0f096ed4(sp13c, &sp1fc);
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
				func0f097044(&sp1bc, &sp12c);
				func0f097738(sp13c, sp12c.f, sp11c);
				func0f096ed4(sp11c, &sp17c);
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
			func0f0c1840(&sp2fc, &sp2e4, &sp2f0, &rocket->base.prop->pos, rocket->base.prop->rooms);
		} else {
			func0f0c1840(&sp2fc, &sp2e4, &sp2f0, NULL, NULL);
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

		func0f0b9538();

		if (g_PlayersWithControl[g_Vars.currentplayernum]) {
			bmoveTick(1, 1, arg0, 0);
		} else {
			bmoveTick(0, 0, 0, 1);
		}

		func0f0bd3c4();
		currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);

		spf4.x = g_Vars.currentplayer->bond2.unk10.x;
		spf4.y = g_Vars.currentplayer->bond2.unk10.y;
		spf4.z = g_Vars.currentplayer->bond2.unk10.z;

		spf4.x = a + spf4.x;
		spf4.y = b + spf4.y;
		spf4.z = c + spf4.z;

		func0f0c1840(&spf4,
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
	} else if (g_Vars.tickmode == TICKMODE_0 || g_Vars.tickmode == TICKMODE_5) {
		// Unused? Suspect this is GE level fade in and GE level fade out
		func0f0b9538();
		bmoveTick(1, 1, arg0, 0);
		func0f0bd3c4();
		currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);
		func0f0c1840(&g_Vars.currentplayer->bond2.unk10,
				&g_Vars.currentplayer->bond2.unk28,
				&g_Vars.currentplayer->bond2.unk1c,
				&g_Vars.currentplayer->prop->pos,
				g_Vars.currentplayer->prop->rooms);
	} else if (g_Vars.tickmode == TICKMODE_MPSWIRL) {
		// Start of an MP match where the camera circles around the player
		func0f0b8ba0();
		bmoveTick(0, 0, 0, 1);
		currentPlayerTickMpSwirl();
	} else if (g_Vars.tickmode == TICKMODE_WARP) {
		// Eg. In CI training, warping from device hallways
		// to device room at the end of a training session
		func0f0b8ba0();
		bmoveTick(0, 0, 0, 1);
		currentPlayerExecutePreparedWarp();
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

		func0f0b9538();
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
				setTickMode(TICKMODE_NORMAL);
			}
		} else {
			if (diffangle >= -0.2f && diffangle <= 0.2f) {
				setTickMode(TICKMODE_NORMAL);
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
		func0f0bd3c4();
		currentPlayerSetCameraMode(CAMERAMODE_DEFAULT);
		func0f0c1840(&g_Vars.currentplayer->bond2.unk10,
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

		if (lvIsPaused() == false
				&& arg0
				&& joyGetButtonsPressedThisFrame(contpad1, A_BUTTON | B_BUTTON | Z_TRIG | START_BUTTON | L_TRIG | R_TRIG)) {
			var8007074c = 2;

			if (currentPlayerIsFadeComplete()) {
				if (g_Vars.currentplayer->colourscreenfrac == 0) {
					currentPlayerSetFadeColour(0, 0, 0, 0);
					currentPlayerSetFadeFrac(60, 1);
				}
			} else {
				if (g_Vars.currentplayer->colourfadefracnew == 0) {
					currentPlayerSetFadeFrac(g_Vars.currentplayer->colourfadetime60, 1);
				}
			}
		}

		if (var8007074c == 2
				&& currentPlayerIsFadeComplete()
				&& g_Vars.currentplayer->colourscreenfrac == 1) {
			func0000e990();
		}
	}

	if (var80070744) {
		func0f0b9650();
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

	if (g_Vars.tickmode == TICKMODE_5 && currentPlayerIsFadeComplete()) {
		mainEndStage();
	}
}

u32 var800709f4 = 0x02810000;
u32 var800709f8 = 0x00000000;
u32 var800709fc = 0x00000000;
u32 var80070a00 = 0x00000000;
u32 var80070a04 = 0x00000000;
u32 var80070a08 = 0x00000000;
u32 var80070a0c = 0x00000000;
u32 var80070a10 = 0x00000000;
u32 var80070a14 = 0x00000000;
u32 var80070a18 = 0x00000000;
u32 var80070a1c = 0x00000000;
u32 var80070a20 = 0x00000000;
u32 var80070a24 = 0x3eb2b17a;
u32 var80070a28 = 0xbfc907a9;
u32 var80070a2c = 0x3fc907a9;
u32 var80070a30 = 0xbfc907a9;
u32 var80070a34 = 0x00000000;
u32 var80070a38 = 0x00000000;
u32 var80070a3c = 0x02850000;
u32 var80070a40 = 0x00000000;
u32 var80070a44 = 0x00000000;
u32 var80070a48 = 0x00000000;
u32 var80070a4c = 0x00000000;
u32 var80070a50 = 0x00000000;
u32 var80070a54 = 0x00000000;
u32 var80070a58 = 0x00000000;
u32 var80070a5c = 0x00000000;
u32 var80070a60 = 0x00000000;
u32 var80070a64 = 0x00000000;
u32 var80070a68 = 0x00000000;
u32 var80070a6c = 0x3eb2b17a;
u32 var80070a70 = 0xbfc907a9;
u32 var80070a74 = 0x3fc907a9;
u32 var80070a78 = 0xbfc907a9;
u32 var80070a7c = 0x00000000;
u32 var80070a80 = 0x00000000;
u32 var80070a84 = 0x02820000;
u32 var80070a88 = 0x00000000;
u32 var80070a8c = 0x00000000;
u32 var80070a90 = 0x00000000;
u32 var80070a94 = 0x00000000;
u32 var80070a98 = 0x00000000;
u32 var80070a9c = 0x00000000;
u32 var80070aa0 = 0x00000000;
u32 var80070aa4 = 0x00000000;
u32 var80070aa8 = 0x00000000;
u32 var80070aac = 0x00000000;
u32 var80070ab0 = 0x00000000;
u32 var80070ab4 = 0x3eb2b17a;
u32 var80070ab8 = 0xbfc907a9;
u32 var80070abc = 0x3fc907a9;
u32 var80070ac0 = 0xbfc907a9;
u32 var80070ac4 = 0x3fcccccd;
u32 var80070ac8 = 0x3fcccccd;
u32 var80070acc = 0x02860000;
u32 var80070ad0 = 0x00000000;
u32 var80070ad4 = 0x00000000;
u32 var80070ad8 = 0x00000000;
u32 var80070adc = 0x00000000;
u32 var80070ae0 = 0x00000000;
u32 var80070ae4 = 0x00000000;
u32 var80070ae8 = 0x00000000;
u32 var80070aec = 0x00000000;
u32 var80070af0 = 0x00000000;
u32 var80070af4 = 0x00000000;
u32 var80070af8 = 0x00000000;
u32 var80070afc = 0x3e32b17a;
u32 var80070b00 = 0xbfc907a9;
u32 var80070b04 = 0x3fc907a9;
u32 var80070b08 = 0xbfc907a9;
u32 var80070b0c = 0x3fcccccd;
u32 var80070b10 = 0x3fcccccd;
u32 var80070b14 = 0x02830000;
u32 var80070b18 = 0x00000000;
u32 var80070b1c = 0x00000000;
u32 var80070b20 = 0x00000000;
u32 var80070b24 = 0x00000000;
u32 var80070b28 = 0x00000000;
u32 var80070b2c = 0x00000000;
u32 var80070b30 = 0x00000000;
u32 var80070b34 = 0x00000000;
u32 var80070b38 = 0x00000000;
u32 var80070b3c = 0x00000000;
u32 var80070b40 = 0x00000000;
u32 var80070b44 = 0x3eb2b17a;
u32 var80070b48 = 0xbfc907a9;
u32 var80070b4c = 0x3fc907a9;
u32 var80070b50 = 0xbfc907a9;
u32 var80070b54 = 0x00000000;
u32 var80070b58 = 0x00000000;
u32 var80070b5c = 0x02870000;
u32 var80070b60 = 0x00000000;
u32 var80070b64 = 0x00000000;
u32 var80070b68 = 0x00000000;
u32 var80070b6c = 0x00000000;
u32 var80070b70 = 0x00000000;
u32 var80070b74 = 0x00000000;
u32 var80070b78 = 0x00000000;
u32 var80070b7c = 0x00000000;
u32 var80070b80 = 0x00000000;
u32 var80070b84 = 0x00000000;
u32 var80070b88 = 0x00000000;
u32 var80070b8c = 0x3e32b17a;
u32 var80070b90 = 0xbfc907a9;
u32 var80070b94 = 0x3fc907a9;
u32 var80070b98 = 0xbfc907a9;
u32 var80070b9c = 0x00000000;
u32 var80070ba0 = 0x00000000;
u32 var80070ba4 = (u32) &var80065be0;
u32 var80070ba8 = 0x00000000;
u32 var80070bac = 0x3dcccccd;
u32 var80070bb0 = 0x429e0000;
u32 var80070bb4 = 0x42ae0000;
u32 var80070bb8 = 0x3f86051b;
u32 var80070bbc = (u32) &g_AttackAnimLightWalk;
u32 var80070bc0 = 0x00000000;
u32 var80070bc4 = 0x3f000000;
u32 var80070bc8 = 0xbf800000;
u32 var80070bcc = 0xbf800000;
u32 var80070bd0 = 0x3f86051b;
u32 var80070bd4 = (u32) &g_AttackAnimLightRun;
u32 var80070bd8 = 0x00000000;
u32 var80070bdc = 0x3f000000;
u32 var80070be0 = 0xbf800000;
u32 var80070be4 = 0xbf800000;
u32 var80070be8 = 0x3f86051b;
u32 var80070bec = (u32) &var800709f4;
u32 var80070bf0 = 0x00000000;
u32 var80070bf4 = 0x3a83126f;
u32 var80070bf8 = 0x00000000;
u32 var80070bfc = 0x3dcccccd;
u32 var80070c00 = 0x3f86051b;
u32 var80070c04 = (u32) &var800709f4;
u32 var80070c08 = 0x00000000;
u32 var80070c0c = 0x3f00c49c;
u32 var80070c10 = 0xbf800000;
u32 var80070c14 = 0xbf800000;
u32 var80070c18 = 0x3f86051b;
u32 var80070c1c = (u32) &var80070a3c;
u32 var80070c20 = 0x00000000;
u32 var80070c24 = 0x3a83126f;
u32 var80070c28 = 0x00000000;
u32 var80070c2c = 0x3dcccccd;
u32 var80070c30 = 0x3f06051b;
u32 var80070c34 = (u32) &var80070a3c;
u32 var80070c38 = 0x00000000;
u32 var80070c3c = 0x3ee66666;
u32 var80070c40 = 0xbf800000;
u32 var80070c44 = 0xbf800000;
u32 var80070c48 = 0x3f06051b;
u32 var80070c4c = (u32) &var800656c0;
u32 var80070c50 = 0x00000000;
u32 var80070c54 = 0x3d4ccccd;
u32 var80070c58 = 0x420c0000;
u32 var80070c5c = 0x42200000;
u32 var80070c60 = 0x3f86051b;
u32 var80070c64 = (u32) &g_AttackAnimHeavyWalk;
u32 var80070c68 = 0x00000000;
u32 var80070c6c = 0x3f000000;
u32 var80070c70 = 0xbf800000;
u32 var80070c74 = 0xbf800000;
u32 var80070c78 = 0x3f86051b;
u32 var80070c7c = (u32) &g_AttackAnimHeavyRun;
u32 var80070c80 = 0x00000000;
u32 var80070c84 = 0x3f000000;
u32 var80070c88 = 0xbf800000;
u32 var80070c8c = 0xbf800000;
u32 var80070c90 = 0x3f86051b;
u32 var80070c94 = (u32) &var80070a84;
u32 var80070c98 = 0x00000000;
u32 var80070c9c = 0x3a83126f;
u32 var80070ca0 = 0x00000000;
u32 var80070ca4 = 0x3dcccccd;
u32 var80070ca8 = 0x3f86051b;
u32 var80070cac = (u32) &var80070a84;
u32 var80070cb0 = 0x00000000;
u32 var80070cb4 = 0x3f00c49c;
u32 var80070cb8 = 0xbf800000;
u32 var80070cbc = 0xbf800000;
u32 var80070cc0 = 0x3f86051b;
u32 var80070cc4 = (u32) &var80070acc;
u32 var80070cc8 = 0x00000000;
u32 var80070ccc = 0x3a83126f;
u32 var80070cd0 = 0x00000000;
u32 var80070cd4 = 0x3dcccccd;
u32 var80070cd8 = 0x3f06051b;
u32 var80070cdc = (u32) &var80070acc;
u32 var80070ce0 = 0x00000000;
u32 var80070ce4 = 0x3ee66666;
u32 var80070ce8 = 0xbf800000;
u32 var80070cec = 0xbf800000;
u32 var80070cf0 = 0x3f06051b;
u32 var80070cf4 = 0x00000000;
u32 var80070cf8 = 0x006a0000;
u32 var80070cfc = 0x3e800000;
u32 var80070d00 = 0x00000000;
u32 var80070d04 = 0xbf800000;
u32 var80070d08 = 0x3f86051b;
u32 var80070d0c = 0x00000000;
u32 var80070d10 = 0x006b0000;
u32 var80070d14 = 0x3f000000;
u32 var80070d18 = 0xbf800000;
u32 var80070d1c = 0xbf800000;
u32 var80070d20 = 0x3f86051b;
u32 var80070d24 = 0x00000000;
u32 var80070d28 = 0x00590000;
u32 var80070d2c = 0x3f000000;
u32 var80070d30 = 0xbf800000;
u32 var80070d34 = 0xbf800000;
u32 var80070d38 = 0x3f86051b;
u32 var80070d3c = 0x00000000;
u32 var80070d40 = 0x02800000;
u32 var80070d44 = 0x3a83126f;
u32 var80070d48 = 0x00000000;
u32 var80070d4c = 0x3dcccccd;
u32 var80070d50 = 0x3f86051b;
u32 var80070d54 = 0x00000000;
u32 var80070d58 = 0x02800000;
u32 var80070d5c = 0x3f00c49c;
u32 var80070d60 = 0xbf800000;
u32 var80070d64 = 0xbf800000;
u32 var80070d68 = 0x3f86051b;
u32 var80070d6c = 0x00000000;
u32 var80070d70 = 0x02840000;
u32 var80070d74 = 0x3a83126f;
u32 var80070d78 = 0x00000000;
u32 var80070d7c = 0x3dcccccd;
u32 var80070d80 = 0x3f06051b;
u32 var80070d84 = 0x00000000;
u32 var80070d88 = 0x02840000;
u32 var80070d8c = 0x3ee66666;
u32 var80070d90 = 0xbf800000;
u32 var80070d94 = 0xbf800000;
u32 var80070d98 = 0x3f06051b;
u32 var80070d9c = (u32) &var800663d8;
u32 var80070da0 = 0x00000000;
u32 var80070da4 = 0x3dcccccd;
u32 var80070da8 = 0x42000000;
u32 var80070dac = 0x42280000;
u32 var80070db0 = 0x3f86051b;
u32 var80070db4 = (u32) &g_AttackAnimDualWalk;
u32 var80070db8 = 0x00000000;
u32 var80070dbc = 0x3f000000;
u32 var80070dc0 = 0xbf800000;
u32 var80070dc4 = 0xbf800000;
u32 var80070dc8 = 0x3f86051b;
u32 var80070dcc = (u32) &g_AttackAnimDualRun;
u32 var80070dd0 = 0x00000000;
u32 var80070dd4 = 0x3f000000;
u32 var80070dd8 = 0xbf800000;
u32 var80070ddc = 0xbf800000;
u32 var80070de0 = 0x3f86051b;
u32 var80070de4 = (u32) &var80070b14;
u32 var80070de8 = 0x00000000;
u32 var80070dec = 0x3a83126f;
u32 var80070df0 = 0x00000000;
u32 var80070df4 = 0x3dcccccd;
u32 var80070df8 = 0x3f86051b;
u32 var80070dfc = (u32) &var80070b14;
u32 var80070e00 = 0x00000000;
u32 var80070e04 = 0x3f00c49c;
u32 var80070e08 = 0xbf800000;
u32 var80070e0c = 0xbf800000;
u32 var80070e10 = 0x3f86051b;
u32 var80070e14 = (u32) &var80070b5c;
u32 var80070e18 = 0x00000000;
u32 var80070e1c = 0x3a83126f;
u32 var80070e20 = 0x00000000;
u32 var80070e24 = 0x3dcccccd;
u32 var80070e28 = 0x3f06051b;
u32 var80070e2c = (u32) &var80070b5c;
u32 var80070e30 = 0x00000000;
u32 var80070e34 = 0x3ee66666;
u32 var80070e38 = 0xbf800000;
u32 var80070e3c = 0xbf800000;
u32 var80070e40 = 0x3f06051b;
u32 var80070e44 = 0x00000000;
u32 var80070e48 = 0x00000000;
u32 var80070e4c = 0x00000000;


void currentPlayerSetGlobalDrawWorldOffset(s32 room)
{
	func0f166df0(room, &g_Vars.currentplayer->globaldrawworldoffset);

	g_Vars.currentplayer->globaldrawworldbgoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawworldbgoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawworldbgoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	currentPlayerSetLastRoomForOffset(room);
}

void currentPlayerSetGlobalDrawCameraOffset(void)
{
	g_Vars.currentplayer->globaldrawcameraoffset.x = g_Vars.currentplayer->globaldrawworldoffset.x;
	g_Vars.currentplayer->globaldrawcameraoffset.y = g_Vars.currentplayer->globaldrawworldoffset.y;
	g_Vars.currentplayer->globaldrawcameraoffset.z = g_Vars.currentplayer->globaldrawworldoffset.z;

	mtx4RotateVecInPlace(currentPlayerGetMatrix1740(), &g_Vars.currentplayer->globaldrawcameraoffset);
}

GLOBAL_ASM(
glabel func0f0bfc7c
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
/*  f0bfcb0:	0fc2feee */ 	jal	currentPlayerSetGlobalDrawWorldOffset
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
/*  f0bffac:	0fc2ff07 */ 	jal	currentPlayerSetGlobalDrawCameraOffset
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
//void func0f0bfc7c(struct coord *cam_pos, struct coord *cam_look, struct coord *cam_up)
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
//	currentPlayerSetGlobalDrawWorldOffset(g_Vars.currentplayer->cam_room);
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
//	currentPlayerSetGlobalDrawCameraOffset();
//}

Gfx *currentPlayerUpdateShootRot(Gfx *gdl)
{
	struct coord sp3c;
	struct coord sp30;
	f32 y;
	f32 value;
	f32 rotx;
	f32 roty;

	func0f0bfc7c(&g_Vars.currentplayer->cam_pos,
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
void currentPlayerDisplayShield(void)
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
Gfx *currentPlayerRenderShield(Gfx *gdl)
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
		shield = currentPlayerGetShieldFrac() * 8;
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
		func0f0b39c0(&gdl, &var800ab58c[0], 4, 1, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_CLD_SURF2);
		gDPSetEnvColor(gdl++, red, green, blue, (s32)(200 * f20));
		gDPSetPrimColor(gdl++, 0, 0, 0xff, 0xff, 0xff, (s32)(175 * f20 * f20));
		gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 1, COMBINED, PRIMITIVE, COMBINED);

		func0f0b2740(&gdl, sp90, sp88, var800ab58c->width, var800ab58c->height,
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

Gfx *currentPlayerRenderHud(Gfx *gdl)
{
	if (g_Vars.currentplayer->cameramode == CAMERAMODE_THIRDPERSON) {
		gdl = func0f0aeed8(gdl);
		gdl = func0f15b114(gdl);
		gdl = hudmsgsRender(gdl);

		if (g_Vars.currentplayer->isdead == false) {
			gdl = currentPlayerDrawFade(gdl);
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

		if (g_NbombsActive != 0) {
			gdl = func0f00a490(gdl);
		}

		if (g_Vars.stagenum == STAGE_ESCAPE) {
			gdl = gasRender(gdl);
		}

		gdl = currentPlayerRenderShield(gdl);

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
			gdl = fadeDraw(gdl, 0, 0, 0, g_Vars.currentplayer->eyesshutfrac);
		}
	}

	gdl = func0f0baf84(gdl);

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
			&& currentPlayerIsHealthVisible()
			&& func0f0f0c68()) {
		gdl = hudRenderHealthBar(gdl);
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
					currentPlayerSetFadeColour(0x96, 0, 0, 0.70588237f);
				} else {
					g_Vars.currentplayer->redbloodfinished = true;
				}
			}
		}

		if (modelGetCurAnimFrame(&g_Vars.currentplayer->model) >= modelGetAnimEndFrame(&g_Vars.currentplayer->model)
				&& g_Vars.currentplayer->redbloodfinished) {
			if (g_Vars.currentplayer->deathanimfinished == false) {
				g_Vars.currentplayer->deathanimfinished = true;
				currentPlayerAdjustFade(60, 0, 0, 0, 1);
				currentPlayerStartChrFade(120, 0);
			}

			if (currentPlayerIsFadeComplete()) {
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
										currentPlayerDisplayHealth();

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
									currentPlayerDisplayHealth();

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
								g_Vars.currentplayer->deadtimer = PALDOWN(600);
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

		gdl = currentPlayerDrawFade(gdl);
	} else {
		gdl = func0f15b114(gdl);

		if (g_Vars.currentplayer->eyespy) {
			if (g_Vars.currentplayer->eyespy->startuptimer60 < PALDOWN(50)) {
				gdl = bviewRenderFisheye(gdl, -1, 255, 0, g_Vars.currentplayer->eyespy->startuptimer60, g_Vars.currentplayer->eyespy->hit);
			} else {
				s32 time = g_Vars.currentplayer->eyespy->camerashuttertime;

				if (time > 0) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						gdl = bviewRenderFisheye(gdl, -1, 255, time, PALDOWN(50), g_Vars.currentplayer->eyespy->hit);
					} else {
						gdl = bviewRenderFisheye(gdl, -1, 255, 0, PALDOWN(50), g_Vars.currentplayer->eyespy->hit);
					}

					g_Vars.currentplayer->eyespy->camerashuttertime -= g_Vars.lvupdate240_60;
				} else {
					gdl = bviewRenderFisheye(gdl, -1, 255, 0, PALDOWN(50), g_Vars.currentplayer->eyespy->hit);
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
		gdl = currentPlayerDrawFade(gdl);
	}

	return gdl;
}

void currentPlayerDie(bool force)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	s32 shooter;

	if (chr->lastshooter >= 0 && chr->timeshooter > 0) {
		shooter = chr->lastshooter;
	} else {
		shooter = g_Vars.currentplayernum;
	}

	currentPlayerDieByShooter(shooter, force);
}

void currentPlayerDieByShooter(u32 shooter, bool force)
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

		hudmsgRemoveForDeadPlayer(g_Vars.currentplayernum);

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

		if (getMissionTime() - g_Vars.currentplayer->lifestarttime60 < g_Vars.currentplayerstats->shortestlife) {
			g_Vars.currentplayerstats->shortestlife = getMissionTime() - g_Vars.currentplayer->lifestarttime60;
		}

		g_Vars.currentplayer->lifestarttime60 = getMissionTime();
	}
}

void currentPlayerCheckIfShotInBack(s32 attackerplayernum, f32 x, f32 z)
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
f32 currentPlayerGetHealthBarHeightFrac(void)
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

bool currentPlayerIsHealthVisible(void)
{
	return g_Vars.currentplayer->healthshowmode != HEALTHSHOWMODE_HIDDEN;
}

// Never called
void setInvincible(bool enable)
{
	if (enable) {
		cheatActivate(CHEAT_INVINCIBLE);
	} else {
		cheatDeactivate(CHEAT_INVINCIBLE);
	}
}

void setBondVisible(bool visible)
{
	g_Vars.bondvisible = visible;
}

void setBondCollisions(bool enabled)
{
	g_Vars.bondcollisions = enabled;
}

void currentPlayerSetCameraMode(s32 mode)
{
	g_Vars.currentplayer->cameramode = mode;
}

void func0f0c1840(struct coord *pos, struct coord *up, struct coord *look, struct coord *pos2, s16 *rooms2)
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
			currentPlayerSetCamPropertiesWithRoom(pos, up, look, sp54[0]);
			done = true;
		}

		if (!done) {
			for (i = 0; sp54[i] != -1; i++) {
				if ((g_Rooms[sp54[i]].flags & ROOMFLAG_0010) == 0) {
					if (func0f162128(pos, sp54[i])) {
						currentPlayerSetCamPropertiesWithRoom(pos, up, look, sp54[i]);
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
						currentPlayerSetCamPropertiesWithRoom(pos, up, look, sp54[i]);
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
				currentPlayerSetCamPropertiesWithRoom(pos, up, look, tmp);
			} else {
				currentPlayerSetCamPropertiesWithRoom(pos, up, look, sp90[0]);
			}
		} else if (sp64[0] != -1) {
			tmp = room = cd0002a400(pos, sp64);

			if (room > 0) {
				currentPlayerSetCamPropertiesWithoutRoom(pos, up, look, tmp);
			} else {
				currentPlayerSetCamPropertiesWithoutRoom(pos, up, look, sp64[0]);
			}
		} else {
			if (sp52 != -1) {
				currentPlayerSetCamPropertiesWithoutRoom(pos, up, look, sp52);
			} else {
				currentPlayerSetCamPropertiesWithoutRoom(pos, up, look, 1);
			}
		}
	}
}

void func0f0c1ba4(struct coord *pos, struct coord *up, struct coord *look, struct coord *memcampos, s32 memcamroom)
{
	s16 rooms[2];
	rooms[0] = memcamroom;
	rooms[1] = -1;

	func0f0c1840(pos, up, look, memcampos, rooms);
}

void func0f0c1bd8(struct coord *pos, struct coord *up, struct coord *look)
{
	if (g_Vars.currentplayer->memcamroom >= 0) {
		func0f0c1ba4(pos, up, look, &g_Vars.currentplayer->memcampos, g_Vars.currentplayer->memcamroom);
	} else {
		func0f0c1840(pos, up, look, NULL, NULL);
	}
}

void currentPlayerSetCamPropertiesWithRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	g_Vars.currentplayer->memcampos.x = pos->x;
	g_Vars.currentplayer->memcampos.y = pos->y;
	g_Vars.currentplayer->memcampos.z = pos->z;
	g_Vars.currentplayer->memcamroom = room;
	currentPlayerSetCamProperties(pos, up, look, room);
}

void currentPlayerSetCamPropertiesWithoutRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room)
{
	currentPlayerClearMemCamRoom();
	currentPlayerSetCamProperties(pos, up, look, room);
}

void currentPlayerSetCamProperties(struct coord *pos, struct coord *up, struct coord *look, s32 room)
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

void currentPlayerClearMemCamRoom(void)
{
	g_Vars.currentplayer->memcamroom = -1;
}

void allPlayersClearMemCamRoom(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		currentPlayerClearMemCamRoom();
	}

	setCurrentPlayerNum(prevplayernum);
}

void playerSetPerimEnabled(struct prop *prop, bool enable)
{
	u32 playernum = propGetPlayerNum(prop);

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
	s32 playernum = propGetPlayerNum(prop);

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

void currentPlayerUpdatePerimInfo(void)
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
void propPlayerGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin)
{
	s32 playernum = propGetPlayerNum(prop);

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

f32 currentPlayerGetHealthFrac(void)
{
	return g_Vars.currentplayer->bondhealth;
}

f32 currentPlayerGetShieldFrac(void)
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

void currentPlayerSetShieldFrac(f32 frac)
{
	if (frac < 0) {
		frac = 0;
	}

	if (frac > 1) {
		frac = 1;
	}

	chrSetShield(g_Vars.currentplayer->prop->chr, frac * 8);
}

s32 getMissionTime(void)
{
#if PAL
	return g_Vars.currentplayer->bondviewlevtime60 * 60 / 50;
#else
	return g_Vars.currentplayer->bondviewlevtime60;
#endif
}

s32 playerTickBeams(struct prop *prop)
{
	beamTick(&g_Vars.players[propGetPlayerNum(prop)]->hands[0].beam);
	beamTick(&g_Vars.players[propGetPlayerNum(prop)]->hands[1].beam);

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
	s32 playernum = propGetPlayerNum(prop);
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

			func0f0c2a58(chr, bmoveGetCrouchPosByPlayer(playernum), player->speedsideways, player->speedforwards, player->speedtheta, &player->angleoffset, &chr->act_bondmulti.animcfg);

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

GLOBAL_ASM(
glabel func0f0c2a58
.late_rodata
glabel var7f1ad714
.word 0x3d4ccccd
glabel var7f1ad718
.word 0x404907a9
glabel var7f1ad71c
.word 0x40c907a9
glabel var7f1ad720
.word 0x3f99999a
glabel var7f1ad724
.word 0x4036db6e
glabel var7f1ad728
.word 0x3f99999a
glabel var7f1ad72c
.word 0x3ecccccd
glabel var7f1ad730
.word 0x404907a9
glabel var7f1ad734
.word 0x3f99999a
glabel var7f1ad738
.word 0x3f99999a
glabel var7f1ad73c
.word 0xbfd11234
glabel var7f1ad740
.word 0x3fd11234
glabel var7f1ad744
.word 0x3dd66e92
.text
/*  f0c2a58:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0c2a5c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0c2a60:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0c2a64:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0c2a68:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0c2a6c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0c2a70:	0fc0a209 */ 	jal	chrGetHeldProp
/*  f0c2a74:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2a78:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0c2a7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2a80:	0fc0a209 */ 	jal	chrGetHeldProp
/*  f0c2a84:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0c2a88:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2a8c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c2a90:	44811000 */ 	mtc1	$at,$f2
/*  f0c2a94:	00402825 */ 	or	$a1,$v0,$zero
/*  f0c2a98:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c2a9c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c2aa0:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*  f0c2aa4:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f0c2aa8:	10600002 */ 	beqz	$v1,.L0f0c2ab4
/*  f0c2aac:	e7a2002c */ 	swc1	$f2,0x2c($sp)
/*  f0c2ab0:	8c660004 */ 	lw	$a2,0x4($v1)
.L0f0c2ab4:
/*  f0c2ab4:	10400002 */ 	beqz	$v0,.L0f0c2ac0
/*  f0c2ab8:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0c2abc:	8c470004 */ 	lw	$a3,0x4($v0)
.L0f0c2ac0:
/*  f0c2ac0:	8dc40020 */ 	lw	$a0,0x20($t6)
/*  f0c2ac4:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2ac8:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0c2acc:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2ad0:	afa50058 */ 	sw	$a1,0x58($sp)
/*  f0c2ad4:	0c00744f */ 	jal	modelGetAnimNum
/*  f0c2ad8:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0c2adc:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0c2ae0:	0fc0e6a5 */ 	jal	chrIsDead
/*  f0c2ae4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0c2ae8:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2aec:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0c2af0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2af4:	1040002d */ 	beqz	$v0,.L0f0c2bac
/*  f0c2af8:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2afc:	3c048007 */ 	lui	$a0,%hi(g_NumDeathAnimations)
/*  f0c2b00:	8c84077c */ 	lw	$a0,%lo(g_NumDeathAnimations)($a0)
/*  f0c2b04:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2b08:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c2b0c:	1880000c */ 	blez	$a0,.L0f0c2b40
/*  f0c2b10:	3c038007 */ 	lui	$v1,%hi(g_DeathAnimations)
/*  f0c2b14:	24630768 */ 	addiu	$v1,$v1,%lo(g_DeathAnimations)
/*  f0c2b18:	8fa60040 */ 	lw	$a2,0x40($sp)
.L0f0c2b1c:
/*  f0c2b1c:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f0c2b20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c2b24:	0044082a */ 	slt	$at,$v0,$a0
/*  f0c2b28:	14cf0003 */ 	bne	$a2,$t7,.L0f0c2b38
/*  f0c2b2c:	00000000 */ 	nop
/*  f0c2b30:	10000003 */ 	b	.L0f0c2b40
/*  f0c2b34:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2b38:
/*  f0c2b38:	1420fff8 */ 	bnez	$at,.L0f0c2b1c
/*  f0c2b3c:	24630002 */ 	addiu	$v1,$v1,0x2
.L0f0c2b40:
/*  f0c2b40:	10a00005 */ 	beqz	$a1,.L0f0c2b58
/*  f0c2b44:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2b48:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2b4c:	44819000 */ 	mtc1	$at,$f18
/*  f0c2b50:	10000013 */ 	b	.L0f0c2ba0
/*  f0c2b54:	a7a6004e */ 	sh	$a2,0x4e($sp)
.L0f0c2b58:
/*  f0c2b58:	0c004b70 */ 	jal	random
/*  f0c2b5c:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2b60:	3c198007 */ 	lui	$t9,%hi(g_NumDeathAnimations)
/*  f0c2b64:	8f39077c */ 	lw	$t9,%lo(g_NumDeathAnimations)($t9)
/*  f0c2b68:	3c0b8007 */ 	lui	$t3,%hi(g_DeathAnimations)
/*  f0c2b6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2b70:	0059001b */ 	divu	$zero,$v0,$t9
/*  f0c2b74:	00004810 */ 	mfhi	$t1
/*  f0c2b78:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0c2b7c:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0c2b80:	856b0768 */ 	lh	$t3,%lo(g_DeathAnimations)($t3)
/*  f0c2b84:	44819000 */ 	mtc1	$at,$f18
/*  f0c2b88:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2b8c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2b90:	17200002 */ 	bnez	$t9,.L0f0c2b9c
/*  f0c2b94:	00000000 */ 	nop
/*  f0c2b98:	0007000d */ 	break	0x7
.L0f0c2b9c:
/*  f0c2b9c:	a7ab004e */ 	sh	$t3,0x4e($sp)
.L0f0c2ba0:
/*  f0c2ba0:	87a5004e */ 	lh	$a1,0x4e($sp)
/*  f0c2ba4:	10000158 */ 	b	.L0f0c3108
/*  f0c2ba8:	00004025 */ 	or	$t0,$zero,$zero
.L0f0c2bac:
/*  f0c2bac:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0c2bb0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c2bb4:	8d84001c */ 	lw	$a0,0x1c($t4)
/*  f0c2bb8:	908d0000 */ 	lbu	$t5,0x0($a0)
/*  f0c2bbc:	15a10048 */ 	bne	$t5,$at,.L0f0c2ce0
/*  f0c2bc0:	00000000 */ 	nop
/*  f0c2bc4:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0c2bc8:	afa50058 */ 	sw	$a1,0x58($sp)
/*  f0c2bcc:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2bd0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c2bd4:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2bd8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0c2bdc:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x64)
/*  f0c2be0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0c2be4:	8defa024 */ 	lw	$t7,%lo(g_Vars+0x64)($t7)
/*  f0c2be8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c2bec:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0c2bf0:	8df801b0 */ 	lw	$t8,0x1b0($t7)
/*  f0c2bf4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0c2bf8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2bfc:	17010038 */ 	bne	$t8,$at,.L0f0c2ce0
/*  f0c2c00:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c04:	10600005 */ 	beqz	$v1,.L0f0c2c1c
/*  f0c2c08:	00000000 */ 	nop
/*  f0c2c0c:	10a00003 */ 	beqz	$a1,.L0f0c2c1c
/*  f0c2c10:	00000000 */ 	nop
/*  f0c2c14:	1000001c */ 	b	.L0f0c2c88
/*  f0c2c18:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f0c2c1c:
/*  f0c2c1c:	14600005 */ 	bnez	$v1,.L0f0c2c34
/*  f0c2c20:	00000000 */ 	nop
/*  f0c2c24:	14a00003 */ 	bnez	$a1,.L0f0c2c34
/*  f0c2c28:	00000000 */ 	nop
/*  f0c2c2c:	10000016 */ 	b	.L0f0c2c88
/*  f0c2c30:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2c34:
/*  f0c2c34:	10c00008 */ 	beqz	$a2,.L0f0c2c58
/*  f0c2c38:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2c3c:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2c40:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2c44:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2c48:	10400003 */ 	beqz	$v0,.L0f0c2c58
/*  f0c2c4c:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c50:	1000000d */ 	b	.L0f0c2c88
/*  f0c2c54:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2c58:
/*  f0c2c58:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2c5c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2c60:	50400009 */ 	beqzl	$v0,.L0f0c2c88
/*  f0c2c64:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2c68:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2c6c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2c70:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c2c74:	10400003 */ 	beqz	$v0,.L0f0c2c84
/*  f0c2c78:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c2c7c:	10000002 */ 	b	.L0f0c2c88
/*  f0c2c80:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2c84:
/*  f0c2c84:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2c88:
/*  f0c2c88:	14a00004 */ 	bnez	$a1,.L0f0c2c9c
/*  f0c2c8c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0c2c90:	2419029c */ 	addiu	$t9,$zero,0x29c
/*  f0c2c94:	1000000d */ 	b	.L0f0c2ccc
/*  f0c2c98:	a7b9004e */ 	sh	$t9,0x4e($sp)
.L0f0c2c9c:
/*  f0c2c9c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c2ca0:	14a10003 */ 	bne	$a1,$at,.L0f0c2cb0
/*  f0c2ca4:	2409029d */ 	addiu	$t1,$zero,0x29d
/*  f0c2ca8:	10000008 */ 	b	.L0f0c2ccc
/*  f0c2cac:	a7a9004e */ 	sh	$t1,0x4e($sp)
.L0f0c2cb0:
/*  f0c2cb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2cb4:	14a10004 */ 	bne	$a1,$at,.L0f0c2cc8
/*  f0c2cb8:	240b029b */ 	addiu	$t3,$zero,0x29b
/*  f0c2cbc:	240a029e */ 	addiu	$t2,$zero,0x29e
/*  f0c2cc0:	10000002 */ 	b	.L0f0c2ccc
/*  f0c2cc4:	a7aa004e */ 	sh	$t2,0x4e($sp)
.L0f0c2cc8:
/*  f0c2cc8:	a7ab004e */ 	sh	$t3,0x4e($sp)
.L0f0c2ccc:
/*  f0c2ccc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c2cd0:	44819000 */ 	mtc1	$at,$f18
/*  f0c2cd4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c2cd8:	1000010b */ 	b	.L0f0c3108
/*  f0c2cdc:	87a5004e */ 	lh	$a1,0x4e($sp)
.L0f0c2ce0:
/*  f0c2ce0:	10600005 */ 	beqz	$v1,.L0f0c2cf8
/*  f0c2ce4:	00000000 */ 	nop
/*  f0c2ce8:	10a00003 */ 	beqz	$a1,.L0f0c2cf8
/*  f0c2cec:	00000000 */ 	nop
/*  f0c2cf0:	1000002e */ 	b	.L0f0c2dac
/*  f0c2cf4:	24050003 */ 	addiu	$a1,$zero,0x3
.L0f0c2cf8:
/*  f0c2cf8:	14600005 */ 	bnez	$v1,.L0f0c2d10
/*  f0c2cfc:	00000000 */ 	nop
/*  f0c2d00:	14a00003 */ 	bnez	$a1,.L0f0c2d10
/*  f0c2d04:	00000000 */ 	nop
/*  f0c2d08:	10000028 */ 	b	.L0f0c2dac
/*  f0c2d0c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d10:
/*  f0c2d10:	10c00008 */ 	beqz	$a2,.L0f0c2d34
/*  f0c2d14:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0c2d18:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2d1c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d20:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2d24:	14400003 */ 	bnez	$v0,.L0f0c2d34
/*  f0c2d28:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2d2c:	1000001f */ 	b	.L0f0c2dac
/*  f0c2d30:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d34:
/*  f0c2d34:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2d38:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0c2d3c:	10400008 */ 	beqz	$v0,.L0f0c2d60
/*  f0c2d40:	00000000 */ 	nop
/*  f0c2d44:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2d48:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d4c:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0c2d50:	14400003 */ 	bnez	$v0,.L0f0c2d60
/*  f0c2d54:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c2d58:	10000014 */ 	b	.L0f0c2dac
/*  f0c2d5c:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f0c2d60:
/*  f0c2d60:	10c00007 */ 	beqz	$a2,.L0f0c2d80
/*  f0c2d64:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2d68:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d6c:	90c4005c */ 	lbu	$a0,0x5c($a2)
/*  f0c2d70:	50400004 */ 	beqzl	$v0,.L0f0c2d84
/*  f0c2d74:	8fa20050 */ 	lw	$v0,0x50($sp)
/*  f0c2d78:	1000000c */ 	b	.L0f0c2dac
/*  f0c2d7c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0c2d80:
/*  f0c2d80:	8fa20050 */ 	lw	$v0,0x50($sp)
.L0f0c2d84:
/*  f0c2d84:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0c2d88:	50400008 */ 	beqzl	$v0,.L0f0c2dac
/*  f0c2d8c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2d90:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c2d94:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f0c2d98:	50400004 */ 	beqzl	$v0,.L0f0c2dac
/*  f0c2d9c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c2da0:	10000002 */ 	b	.L0f0c2dac
/*  f0c2da4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c2da8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c2dac:
/*  f0c2dac:	c7a00068 */ 	lwc1	$f0,0x68($sp)
/*  f0c2db0:	c7a2006c */ 	lwc1	$f2,0x6c($sp)
/*  f0c2db4:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2db8:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0c2dbc:	00000000 */ 	nop
/*  f0c2dc0:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0c2dc4:	0c012974 */ 	jal	sqrtf
/*  f0c2dc8:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0c2dcc:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0c2dd0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2dd4:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2dd8:	46000406 */ 	mov.s	$f16,$f0
/*  f0c2ddc:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0c2de0:	3c017f1b */ 	lui	$at,%hi(var7f1ad714)
/*  f0c2de4:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f0c2de8:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f0c2dec:	45020003 */ 	bc1fl	.L0f0c2dfc
/*  f0c2df0:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c2df4:	46001087 */ 	neg.s	$f2,$f2
/*  f0c2df8:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0c2dfc:
/*  f0c2dfc:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0c2e00:	45000002 */ 	bc1f	.L0f0c2e0c
/*  f0c2e04:	00000000 */ 	nop
/*  f0c2e08:	46001406 */ 	mov.s	$f16,$f2
.L0f0c2e0c:
/*  f0c2e0c:	c42ad714 */ 	lwc1	$f10,%lo(var7f1ad714)($at)
/*  f0c2e10:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0c2e14:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2e18:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c2e1c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0c2e20:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2e24:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0c2e28:	45000013 */ 	bc1f	.L0f0c2e78
/*  f0c2e2c:	3c0f8007 */ 	lui	$t7,%hi(var80070ba4)
/*  f0c2e30:	14400003 */ 	bnez	$v0,.L0f0c2e40
/*  f0c2e34:	25ef0ba4 */ 	addiu	$t7,$t7,%lo(var80070ba4)
/*  f0c2e38:	10000006 */ 	b	.L0f0c2e54
/*  f0c2e3c:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0c2e40:
/*  f0c2e40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2e44:	14410003 */ 	bne	$v0,$at,.L0f0c2e54
/*  f0c2e48:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c2e4c:	10000001 */ 	b	.L0f0c2e54
/*  f0c2e50:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0c2e54:
/*  f0c2e54:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0c2e58:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0c2e5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2e60:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0c2e64:	44819000 */ 	mtc1	$at,$f18
/*  f0c2e68:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0c2e6c:	44806000 */ 	mtc1	$zero,$f12
/*  f0c2e70:	10000081 */ 	b	.L0f0c3078
/*  f0c2e74:	01cf1021 */ 	addu	$v0,$t6,$t7
.L0f0c2e78:
/*  f0c2e78:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2e7c:	0fc259d4 */ 	jal	atan2f
/*  f0c2e80:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0c2e84:	3c017f1b */ 	lui	$at,%hi(var7f1ad718)
/*  f0c2e88:	c42ed718 */ 	lwc1	$f14,%lo(var7f1ad718)($at)
/*  f0c2e8c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2e90:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f0c2e94:	4600703e */ 	c.le.s	$f14,$f0
/*  f0c2e98:	46000306 */ 	mov.s	$f12,$f0
/*  f0c2e9c:	3c017f1b */ 	lui	$at,%hi(var7f1ad71c)
/*  f0c2ea0:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0c2ea4:	45000003 */ 	bc1f	.L0f0c2eb4
/*  f0c2ea8:	00000000 */ 	nop
/*  f0c2eac:	c424d71c */ 	lwc1	$f4,%lo(var7f1ad71c)($at)
/*  f0c2eb0:	46040301 */ 	sub.s	$f12,$f0,$f4
.L0f0c2eb4:
/*  f0c2eb4:	1440000d */ 	bnez	$v0,.L0f0c2eec
/*  f0c2eb8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2ebc:	3c017f1b */ 	lui	$at,%hi(var7f1ad720)
/*  f0c2ec0:	c422d720 */ 	lwc1	$f2,%lo(var7f1ad720)($at)
/*  f0c2ec4:	3c017f1b */ 	lui	$at,%hi(var7f1ad724)
/*  f0c2ec8:	c426d724 */ 	lwc1	$f6,%lo(var7f1ad724)($at)
/*  f0c2ecc:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f0c2ed0:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f0c2ed4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2ed8:	00000000 */ 	nop
/*  f0c2edc:	4500003e */ 	bc1f	.L0f0c2fd8
/*  f0c2ee0:	00000000 */ 	nop
/*  f0c2ee4:	1000003c */ 	b	.L0f0c2fd8
/*  f0c2ee8:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2eec:
/*  f0c2eec:	1441000c */ 	bne	$v0,$at,.L0f0c2f20
/*  f0c2ef0:	3c017f1b */ 	lui	$at,%hi(var7f1ad728)
/*  f0c2ef4:	c422d728 */ 	lwc1	$f2,%lo(var7f1ad728)($at)
/*  f0c2ef8:	3c014000 */ 	lui	$at,0x4000
/*  f0c2efc:	44814000 */ 	mtc1	$at,$f8
/*  f0c2f00:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0c2f04:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0c2f08:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2f0c:	00000000 */ 	nop
/*  f0c2f10:	45000031 */ 	bc1f	.L0f0c2fd8
/*  f0c2f14:	00000000 */ 	nop
/*  f0c2f18:	1000002f */ 	b	.L0f0c2fd8
/*  f0c2f1c:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2f20:
/*  f0c2f20:	3c017f1b */ 	lui	$at,%hi(var7f1ad72c)
/*  f0c2f24:	c42ad72c */ 	lwc1	$f10,%lo(var7f1ad72c)($at)
/*  f0c2f28:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c2f2c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c2f30:	00000000 */ 	nop
/*  f0c2f34:	45030016 */ 	bc1tl	.L0f0c2f90
/*  f0c2f38:	46108480 */ 	add.s	$f18,$f16,$f16
/*  f0c2f3c:	8f04001c */ 	lw	$a0,0x1c($t8)
/*  f0c2f40:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c2f44:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f0c2f48:	1721001a */ 	bne	$t9,$at,.L0f0c2fb4
/*  f0c2f4c:	00000000 */ 	nop
/*  f0c2f50:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0c2f54:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f0c2f58:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0c2f5c:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0c2f60:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0c2f64:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x64)
/*  f0c2f68:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0c2f6c:	8d4aa024 */ 	lw	$t2,%lo(g_Vars+0x64)($t2)
/*  f0c2f70:	3c017f1b */ 	lui	$at,%hi(var7f1ad730)
/*  f0c2f74:	c42ed730 */ 	lwc1	$f14,%lo(var7f1ad730)($at)
/*  f0c2f78:	8d4b03ac */ 	lw	$t3,0x3ac($t2)
/*  f0c2f7c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0c2f80:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0c2f84:	1560000b */ 	bnez	$t3,.L0f0c2fb4
/*  f0c2f88:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f0c2f8c:	46108480 */ 	add.s	$f18,$f16,$f16
.L0f0c2f90:
/*  f0c2f90:	3c017f1b */ 	lui	$at,%hi(var7f1ad734)
/*  f0c2f94:	c422d734 */ 	lwc1	$f2,%lo(var7f1ad734)($at)
/*  f0c2f98:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c2f9c:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c2fa0:	00000000 */ 	nop
/*  f0c2fa4:	4500000c */ 	bc1f	.L0f0c2fd8
/*  f0c2fa8:	00000000 */ 	nop
/*  f0c2fac:	1000000a */ 	b	.L0f0c2fd8
/*  f0c2fb0:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2fb4:
/*  f0c2fb4:	3c017f1b */ 	lui	$at,%hi(var7f1ad738)
/*  f0c2fb8:	c422d738 */ 	lwc1	$f2,%lo(var7f1ad738)($at)
/*  f0c2fbc:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0c2fc0:	46008486 */ 	mov.s	$f18,$f16
/*  f0c2fc4:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0c2fc8:	00000000 */ 	nop
/*  f0c2fcc:	45000002 */ 	bc1f	.L0f0c2fd8
/*  f0c2fd0:	00000000 */ 	nop
/*  f0c2fd4:	46001486 */ 	mov.s	$f18,$f2
.L0f0c2fd8:
/*  f0c2fd8:	3c017f1b */ 	lui	$at,%hi(var7f1ad73c)
/*  f0c2fdc:	c424d73c */ 	lwc1	$f4,%lo(var7f1ad73c)($at)
/*  f0c2fe0:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0c2fe4:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2fe8:	4604603c */ 	c.lt.s	$f12,$f4
/*  f0c2fec:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0c2ff0:	01856021 */ 	addu	$t4,$t4,$a1
/*  f0c2ff4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0c2ff8:	45000004 */ 	bc1f	.L0f0c300c
/*  f0c2ffc:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0c3000:	460e6300 */ 	add.s	$f12,$f12,$f14
/*  f0c3004:	10000009 */ 	b	.L0f0c302c
/*  f0c3008:	46009487 */ 	neg.s	$f18,$f18
.L0f0c300c:
/*  f0c300c:	3c017f1b */ 	lui	$at,%hi(var7f1ad740)
/*  f0c3010:	c426d740 */ 	lwc1	$f6,%lo(var7f1ad740)($at)
/*  f0c3014:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c3018:	00000000 */ 	nop
/*  f0c301c:	45020004 */ 	bc1fl	.L0f0c3030
/*  f0c3020:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f0c3024:	460e6301 */ 	sub.s	$f12,$f12,$f14
/*  f0c3028:	46009487 */ 	neg.s	$f18,$f18
.L0f0c302c:
/*  f0c302c:	01a36823 */ 	subu	$t5,$t5,$v1
.L0f0c3030:
/*  f0c3030:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0c3034:	3c0f8007 */ 	lui	$t7,%hi(var80070ba4)
/*  f0c3038:	25ef0ba4 */ 	addiu	$t7,$t7,%lo(var80070ba4)
/*  f0c303c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0c3040:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0c3044:	c4400014 */ 	lwc1	$f0,0x14($v0)
/*  f0c3048:	46000087 */ 	neg.s	$f2,$f0
/*  f0c304c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c3050:	00000000 */ 	nop
/*  f0c3054:	45020004 */ 	bc1fl	.L0f0c3068
/*  f0c3058:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c305c:	10000006 */ 	b	.L0f0c3078
/*  f0c3060:	46001306 */ 	mov.s	$f12,$f2
/*  f0c3064:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0c3068:
/*  f0c3068:	00000000 */ 	nop
/*  f0c306c:	45000002 */ 	bc1f	.L0f0c3078
/*  f0c3070:	00000000 */ 	nop
/*  f0c3074:	46000306 */ 	mov.s	$f12,$f0
.L0f0c3078:
/*  f0c3078:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f0c307c:	c428a00c */ 	lwc1	$f8,%lo(g_Vars+0x4c)($at)
/*  f0c3080:	3c017f1b */ 	lui	$at,%hi(var7f1ad744)
/*  f0c3084:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0c3088:	c42ad744 */ 	lwc1	$f10,%lo(var7f1ad744)($at)
/*  f0c308c:	c4620000 */ 	lwc1	$f2,0x0($v1)
/*  f0c3090:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0c3094:	46026381 */ 	sub.s	$f14,$f12,$f2
/*  f0c3098:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0c309c:	00000000 */ 	nop
/*  f0c30a0:	45020005 */ 	bc1fl	.L0f0c30b8
/*  f0c30a4:	46000187 */ 	neg.s	$f6,$f0
/*  f0c30a8:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f0c30ac:	1000000a */ 	b	.L0f0c30d8
/*  f0c30b0:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f0c30b4:	46000187 */ 	neg.s	$f6,$f0
.L0f0c30b8:
/*  f0c30b8:	4606703c */ 	c.lt.s	$f14,$f6
/*  f0c30bc:	00000000 */ 	nop
/*  f0c30c0:	45020005 */ 	bc1fl	.L0f0c30d8
/*  f0c30c4:	e46c0000 */ 	swc1	$f12,0x0($v1)
/*  f0c30c8:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0c30cc:	10000002 */ 	b	.L0f0c30d8
/*  f0c30d0:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f0c30d4:	e46c0000 */ 	swc1	$f12,0x0($v1)
.L0f0c30d8:
/*  f0c30d8:	84430004 */ 	lh	$v1,0x4($v0)
/*  f0c30dc:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f0c30e0:	50600003 */ 	beqzl	$v1,.L0f0c30f0
/*  f0c30e4:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c30e8:	a7a3004e */ 	sh	$v1,0x4e($sp)
/*  f0c30ec:	c44a0008 */ 	lwc1	$f10,0x8($v0)
.L0f0c30f0:
/*  f0c30f0:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c30f4:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c30f8:	460a9482 */ 	mul.s	$f18,$f18,$f10
/*  f0c30fc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c3100:	87a5004e */ 	lh	$a1,0x4e($sp)
/*  f0c3104:	e7a4002c */ 	swc1	$f4,0x2c($sp)
.L0f0c3108:
/*  f0c3108:	44806000 */ 	mtc1	$zero,$f12
/*  f0c310c:	11000004 */ 	beqz	$t0,.L0f0c3120
/*  f0c3110:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c3114:	14a00002 */ 	bnez	$a1,.L0f0c3120
/*  f0c3118:	00000000 */ 	nop
/*  f0c311c:	85050000 */ 	lh	$a1,0x0($t0)
.L0f0c3120:
/*  f0c3120:	50a60003 */ 	beql	$a1,$a2,.L0f0c3130
/*  f0c3124:	4602603e */ 	c.le.s	$f12,$f2
/*  f0c3128:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0c312c:	4602603e */ 	c.le.s	$f12,$f2
.L0f0c3130:
/*  f0c3130:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0c3134:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c3138:	4502000d */ 	bc1fl	.L0f0c3170
/*  f0c313c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c3140:	8f190020 */ 	lw	$t9,0x20($t8)
/*  f0c3144:	8f220020 */ 	lw	$v0,0x20($t9)
/*  f0c3148:	8049000a */ 	lb	$t1,0xa($v0)
/*  f0c314c:	51200007 */ 	beqzl	$t1,.L0f0c316c
/*  f0c3150:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c3154:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0c3158:	46061032 */ 	c.eq.s	$f2,$f6
/*  f0c315c:	00000000 */ 	nop
/*  f0c3160:	45030003 */ 	bc1tl	.L0f0c3170
/*  f0c3164:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c3168:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c316c:
/*  f0c316c:	460c103c */ 	c.lt.s	$f2,$f12
.L0f0c3170:
/*  f0c3170:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f0c3174:	45000006 */ 	bc1f	.L0f0c3190
/*  f0c3178:	8d440020 */ 	lw	$a0,0x20($t2)
/*  f0c317c:	8c8b0020 */ 	lw	$t3,0x20($a0)
/*  f0c3180:	816c000a */ 	lb	$t4,0xa($t3)
/*  f0c3184:	11800002 */ 	beqz	$t4,.L0f0c3190
/*  f0c3188:	00000000 */ 	nop
/*  f0c318c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c3190:
/*  f0c3190:	5060002f */ 	beqzl	$v1,.L0f0c3250
/*  f0c3194:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3198:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0c319c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c31a0:	3c014180 */ 	lui	$at,0x4180
/*  f0c31a4:	85ae0002 */ 	lh	$t6,0x2($t5)
/*  f0c31a8:	55c00038 */ 	bnezl	$t6,.L0f0c328c
/*  f0c31ac:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c31b0:	4602603e */ 	c.le.s	$f12,$f2
/*  f0c31b4:	44814000 */ 	mtc1	$at,$f8
/*  f0c31b8:	45020004 */ 	bc1fl	.L0f0c31cc
/*  f0c31bc:	46006006 */ 	mov.s	$f0,$f12
/*  f0c31c0:	10000002 */ 	b	.L0f0c31cc
/*  f0c31c4:	46001006 */ 	mov.s	$f0,$f2
/*  f0c31c8:	46006006 */ 	mov.s	$f0,$f12
.L0f0c31cc:
/*  f0c31cc:	44070000 */ 	mfc1	$a3,$f0
/*  f0c31d0:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c31d4:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c31d8:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c31dc:	0c007733 */ 	jal	modelSetAnimation
/*  f0c31e0:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f0c31e4:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0c31e8:	44805000 */ 	mtc1	$zero,$f10
/*  f0c31ec:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c31f0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0c31f4:	4602503e */ 	c.le.s	$f10,$f2
/*  f0c31f8:	3c064180 */ 	lui	$a2,0x4180
/*  f0c31fc:	45020007 */ 	bc1fl	.L0f0c321c
/*  f0c3200:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f0c3204:	8de40020 */ 	lw	$a0,0x20($t7)
/*  f0c3208:	44051000 */ 	mfc1	$a1,$f2
/*  f0c320c:	0c00777b */ 	jal	modelSetAnimLooping
/*  f0c3210:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3214:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c3218:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
.L0f0c321c:
/*  f0c321c:	44803000 */ 	mtc1	$zero,$f6
/*  f0c3220:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c3224:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c3228:	00000000 */ 	nop
/*  f0c322c:	45020017 */ 	bc1fl	.L0f0c328c
/*  f0c3230:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c3234:	8f040020 */ 	lw	$a0,0x20($t8)
/*  f0c3238:	44052000 */ 	mfc1	$a1,$f4
/*  f0c323c:	0c007787 */ 	jal	modelSetAnimEndFrame
/*  f0c3240:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3244:	10000010 */ 	b	.L0f0c3288
/*  f0c3248:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c324c:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f0c3250:
/*  f0c3250:	0c007498 */ 	jal	modelGetAnimSpeed
/*  f0c3254:	e7b20044 */ 	swc1	$f18,0x44($sp)
/*  f0c3258:	c7b20044 */ 	lwc1	$f18,0x44($sp)
/*  f0c325c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0c3260:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0c3264:	46120032 */ 	c.eq.s	$f0,$f18
/*  f0c3268:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0c326c:	45030007 */ 	bc1tl	.L0f0c328c
/*  f0c3270:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0c3274:	8f240020 */ 	lw	$a0,0x20($t9)
/*  f0c3278:	44059000 */ 	mfc1	$a1,$f18
/*  f0c327c:	0c0077ac */ 	jal	modelSetAnimSpeed
/*  f0c3280:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0c3284:	8fa80048 */ 	lw	$t0,0x48($sp)
.L0f0c3288:
/*  f0c3288:	8fa90078 */ 	lw	$t1,0x78($sp)
.L0f0c328c:
/*  f0c328c:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f0c3290:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0c3294:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0c3298:	03e00008 */ 	jr	$ra
/*  f0c329c:	00000000 */ 	nop
);

Gfx *playerRender(struct prop *prop, Gfx *gdl, bool withalpha)
{
	if (g_Vars.players[propGetPlayerNum(prop)]->haschrbody) {
		gdl = chrRender(prop, gdl, withalpha);
	}

	return gdl;
}

Gfx *currentPlayerLoadMatrix(Gfx *gdl)
{
	gSPMatrix(gdl++, g_Vars.currentplayer->matrix5c, G_MTX_LOAD);
	return gdl;
}

GLOBAL_ASM(
glabel func0f0c3320
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
//void func0f0c3320(Mtxf *matrices, s32 count)
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
