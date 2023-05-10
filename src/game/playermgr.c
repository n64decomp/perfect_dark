#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

static void playermgrAllocatePlayer(s32 index);

void playermgrInit(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_Vars.playerstats[i].damagescale = 1;
	}

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;
}

void playermgrReset(void)
{
	g_Vars.players[0] = NULL;
	g_Vars.players[1] = NULL;
	g_Vars.players[2] = NULL;
	g_Vars.players[3] = NULL;
	g_Vars.playercount = 0;
	g_Vars.currentplayer = NULL;
	g_Vars.currentplayerindex = 0;
	g_Vars.currentplayerstats = NULL;
	g_Vars.currentplayernum = 0;
	g_Vars.playerorder[0] = 0;
	g_Vars.playerorder[1] = 1;
	g_Vars.playerorder[2] = 2;
	g_Vars.playerorder[3] = 3;
	g_Vars.bond = NULL;
	g_Vars.coop = NULL;
	g_Vars.anti = NULL;
}

void playermgrAllocatePlayers(s32 count)
{
	g_Vars.players[0] = NULL;
	g_Vars.players[1] = NULL;
	g_Vars.players[2] = NULL;
	g_Vars.players[3] = NULL;
	g_Vars.playercount = 0;

	if (count > 0) {
		s32 i;

		for (i = 0; i < count; i++) {
			playermgrAllocatePlayer(i);
		}

		setCurrentPlayerNum(0);
		g_Vars.bond = g_Vars.players[g_Vars.bondplayernum];

		if (g_Vars.coopplayernum >= 0) {
			g_Vars.coop = g_Vars.players[g_Vars.coopplayernum];
			g_Vars.anti = NULL;
		} else if (g_Vars.antiplayernum >= 0) {
			g_Vars.coop = NULL;
			g_Vars.anti = g_Vars.players[g_Vars.antiplayernum];
		}

	} else {
		playermgrAllocatePlayer(0);
		setCurrentPlayerNum(0);

		playermgrSetViewSize(g_ViModes[VIRES_LO].fbwidth, g_ViModes[VIRES_LO].fbheight);

		g_Vars.coop = NULL;
		g_Vars.anti = NULL;
		g_Vars.bond = g_Vars.players[0];
	}
}

static void playermgrAllocatePlayer(s32 index)
{
	struct hand hand = {
		{0},
		0,
		0,
		1, // gunon
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1, // unk06ac
		0,
		0,
		0,
		0,
		1, // unk06c0
		0,
		0,
		0,
		0,
		1, // unk06d4
		0,
		0,
		0,
		0,
		1, // unk06e8
		0,
		0,
		0,
		0,
		0,
		0,
		-1, // unk0704
		0,
		1, // unk070c
		0,
		0,
		0,
		0,
		0,
		0,
		PAL ? -16.750415802002f : -19.999996185303f, // unk0728
		0,
		PAL ? 16.750415802002f : 19.999996185303f, // unk0730
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		-1, // unk0770
		0,
		0,
		-1, // unk077c
		0,
		0,
		-1, // unk0788
		0,
		0,
		-1, // unk0794
		0,
		1, // unk079c
		0,
		0,
		1, // unk07a8
		0,
		0,
		1, // unk07b4
		0,
		0,
		1, // unk07c0
		0,
		0,
		0,
		1, // unk07d0
		1, // unk07d4
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		{0, 0, 1000}, // unk07f8
		NULL, // audiohandle2
		0,
		0,
		0,
		{-1}, // beam.age
	};

	s32 i;

	g_Vars.players[index] = mempAlloc(sizeof(struct player), MEMPOOL_STAGE);
	g_Vars.playercount++;

	g_Vars.players[index]->cameramode = CAMERAMODE_DEFAULT;
	g_Vars.players[index]->memcampos.x = 0;
	g_Vars.players[index]->memcampos.y = 0;
	g_Vars.players[index]->memcampos.z = 0;
	g_Vars.players[index]->memcamroom = -1;
	g_Vars.players[index]->cam_pos.x = 0;
	g_Vars.players[index]->cam_pos.y = 0;
	g_Vars.players[index]->cam_pos.z = 0;
	g_Vars.players[index]->cam_room = 1;
	g_Vars.players[index]->globaldrawworldoffset.x = 0;
	g_Vars.players[index]->globaldrawworldoffset.y = 0;
	g_Vars.players[index]->globaldrawworldoffset.z = 0;
	g_Vars.players[index]->globaldrawcameraoffset.x = 0;
	g_Vars.players[index]->globaldrawcameraoffset.y = 0;
	g_Vars.players[index]->globaldrawcameraoffset.z = 0;
	g_Vars.players[index]->globaldrawworldbgoffset.x = 0;
	g_Vars.players[index]->globaldrawworldbgoffset.y = 0;
	g_Vars.players[index]->globaldrawworldbgoffset.z = 0;

	g_Vars.players[index]->vv_manground = 0;
	g_Vars.players[index]->vv_ground = 0;
	g_Vars.players[index]->prop = NULL;

	g_Vars.players[index]->bondperimenabled = true;
	g_Vars.players[index]->periminfo.header.type = GEOTYPE_CYL;
	g_Vars.players[index]->periminfo.header.flags = GEOFLAG_WALL | GEOFLAG_BLOCK_SHOOT;
	g_Vars.players[index]->periminfo.ymax = 0;
	g_Vars.players[index]->periminfo.ymin = 0;
	g_Vars.players[index]->periminfo.x = 0;
	g_Vars.players[index]->periminfo.z = 0;
	g_Vars.players[index]->periminfo.radius = 0;

	g_Vars.players[index]->bondactivateorreload = 0;
	g_Vars.players[index]->model00d4 = 0;
	g_Vars.players[index]->isdead = false;
	g_Vars.players[index]->aborted = false;
	g_Vars.players[index]->bondhealth = 1;
	g_Vars.players[index]->stealhealth = -1;
	g_Vars.players[index]->oldhealth = 1;
	g_Vars.players[index]->oldarmour = 0;
	g_Vars.players[index]->apparenthealth = 1;
	g_Vars.players[index]->apparentarmour = 0;
	g_Vars.players[index]->damageshowtime = -1;
	g_Vars.players[index]->healthshowtime = -1;
	g_Vars.players[index]->shieldshowtime = -1;
	g_Vars.players[index]->healthshowmode = HEALTHSHOWMODE_HIDDEN;

	g_Vars.players[index]->docentreupdown = false;
	g_Vars.players[index]->lastupdown60 = 0;
	g_Vars.players[index]->prevupdown = 0;
	g_Vars.players[index]->movecentrerelease = 0;
	g_Vars.players[index]->lookaheadcentreenabled = true;
	g_Vars.players[index]->automovecentreenabled = true;
	g_Vars.players[index]->fastmovecentreenabled = false;
	g_Vars.players[index]->automovecentre = true;
	g_Vars.players[index]->insightaimmode = false;

	g_Vars.players[index]->autoaimenabled = true;
	g_Vars.players[index]->autoaimx = 0;
	g_Vars.players[index]->autoaimy = 0;
	g_Vars.players[index]->autoaimprop = NULL;
	g_Vars.players[index]->autoaimtime60 = -1;

	g_Vars.players[index]->vv_theta = 0;
	g_Vars.players[index]->speedtheta = 0;
	g_Vars.players[index]->speedthetacontrol = 0;
	g_Vars.players[index]->vv_costheta = 1;
	g_Vars.players[index]->vv_sintheta = 0;

	g_Vars.players[index]->vv_verta = -4;
	g_Vars.players[index]->vv_verta360 = -229.21960449219f;
	g_Vars.players[index]->speedverta = 0;
	g_Vars.players[index]->vv_cosverta = 1;
	g_Vars.players[index]->vv_sinverta = 0;

	g_Vars.players[index]->bondfadetime60 = -1;
	g_Vars.players[index]->bondfadetimemax60 = -1;
	g_Vars.players[index]->bondfadefracold = 0;
	g_Vars.players[index]->bondfadefracnew = 0;
	g_Vars.players[index]->bondbreathing = 0;

	g_Vars.players[index]->playwatchup = true;

	g_Vars.players[index]->colourscreenred = 0xff;
	g_Vars.players[index]->colourscreengreen = 0xff;
	g_Vars.players[index]->colourscreenblue = 0xff;
	g_Vars.players[index]->colourscreenfrac = 0;
	g_Vars.players[index]->colourfadetime60 = -1;
	g_Vars.players[index]->colourfadetimemax60 = -1;
	g_Vars.players[index]->colourfaderedold = 0xff;
	g_Vars.players[index]->colourfaderednew = 0xff;
	g_Vars.players[index]->colourfadegreenold = 0xff;
	g_Vars.players[index]->colourfadegreennew = 0xff;
	g_Vars.players[index]->colourfadeblueold = 0xff;
	g_Vars.players[index]->colourfadebluenew = 0xff;
	g_Vars.players[index]->colourfadefracold = 0;
	g_Vars.players[index]->colourfadefracnew = 0;

	g_Vars.players[index]->bondtype = OUTFIT_DEFAULT;
	g_Vars.players[index]->startnewbonddie = true;
	g_Vars.players[index]->redbloodfinished = false;
	g_Vars.players[index]->deathanimfinished = false;
	g_Vars.players[index]->controldef = 2;
	g_Vars.players[index]->resetheadpos = true;
	g_Vars.players[index]->resetheadrot = true;
	g_Vars.players[index]->resetheadtick = true;

	g_Vars.players[index]->headanim = 0;
	g_Vars.players[index]->headdamp = (PAL ? 0.9166f : 0.93f);
	g_Vars.players[index]->headwalkingtime60 = 0;
	g_Vars.players[index]->headamplitude = 1;
	g_Vars.players[index]->sideamplitude = 1;
	g_Vars.players[index]->headpos.x = 0;
	g_Vars.players[index]->headpos.y = 0;
	g_Vars.players[index]->headpos.z = 0;
	g_Vars.players[index]->headlook.x = 0;
	g_Vars.players[index]->headlook.y = 0;
	g_Vars.players[index]->headlook.z = 1;
	g_Vars.players[index]->headup.x = 0;
	g_Vars.players[index]->headup.y = 1;
	g_Vars.players[index]->headup.z = 0;
	g_Vars.players[index]->headpossum.x = 0;
	g_Vars.players[index]->headpossum.y = 0;
	g_Vars.players[index]->headpossum.z = 0;
	g_Vars.players[index]->headlooksum.x = 0;
	g_Vars.players[index]->headlooksum.y = 0;
	g_Vars.players[index]->headlooksum.z = (PAL ? 11.990406036377f : 14.285716056824f);
	g_Vars.players[index]->headupsum.x = 0;
	g_Vars.players[index]->headupsum.y = (PAL ? 11.990406036377f  : 14.285716056824f);
	g_Vars.players[index]->headupsum.z = 0;
	g_Vars.players[index]->headbodyoffset.x = 0;
	g_Vars.players[index]->headbodyoffset.y = 0;
	g_Vars.players[index]->headbodyoffset.z = 0;

	g_Vars.players[index]->standheight = 0;
	g_Vars.players[index]->standbodyoffset.x = 0;
	g_Vars.players[index]->standbodyoffset.y = 0;
	g_Vars.players[index]->standbodyoffset.z = 0;
	g_Vars.players[index]->standfrac = 0;
	g_Vars.players[index]->standlook[0].x = 0;
	g_Vars.players[index]->standlook[0].y = 0;
	g_Vars.players[index]->standlook[0].z = 1;
	g_Vars.players[index]->standlook[1].x = 0;
	g_Vars.players[index]->standlook[1].y = 0;
	g_Vars.players[index]->standlook[1].z = 1;
	g_Vars.players[index]->standup[0].x = 0;
	g_Vars.players[index]->standup[0].y = 1;
	g_Vars.players[index]->standup[0].z = 0;
	g_Vars.players[index]->standup[1].x = 0;
	g_Vars.players[index]->standup[1].y = 1;
	g_Vars.players[index]->standup[1].z = 0;
	g_Vars.players[index]->standcnt = 0;

	g_Vars.players[index]->devicesactive = 0;
	g_Vars.players[index]->devicesinhibit = 0;

	g_Vars.players[index]->floorflags = 0;

	for (i = 0; i < 3; i++) {
		g_Vars.players[index]->viewport[i].vp.vscale[0] = 640;
		g_Vars.players[index]->viewport[i].vp.vscale[1] = (PAL ? 544 : 480);
		g_Vars.players[index]->viewport[i].vp.vscale[2] = 511;
		g_Vars.players[index]->viewport[i].vp.vscale[3] = 0;

		g_Vars.players[index]->viewport[i].vp.vtrans[0] = 640;
		g_Vars.players[index]->viewport[i].vp.vtrans[1] = (PAL ? 544 : 480);
		g_Vars.players[index]->viewport[i].vp.vtrans[2] = 511;
		g_Vars.players[index]->viewport[i].vp.vtrans[3] = 0;
	}

	g_Vars.players[index]->viewwidth = 100;
	g_Vars.players[index]->viewheight = 100;
	g_Vars.players[index]->viewleft = 0;
	g_Vars.players[index]->viewtop = 0;

	g_Vars.players[index]->slayerrocket = NULL;
	g_Vars.players[index]->badrockettime = 0;

	g_Vars.players[index]->gunctrl.gunmemtype = 0;
	g_Vars.players[index]->gunctrl.gunmem = NULL;
	g_Vars.players[index]->gunctrl.gunmodeldef = NULL;

	g_Vars.players[index]->gunctrl.weaponnum = WEAPON_NONE;
	g_Vars.players[index]->gunctrl.prevweaponnum = -1;
	g_Vars.players[index]->gunctrl.switchtoweaponnum = -1;

	g_Vars.players[index]->gunctrl.gunmemowner = GUNMEMOWNER_CHRBODY;
	g_Vars.players[index]->gunctrl.gunlocktimer = 0;
	g_Vars.players[index]->gunctrl.action = 0;

	g_Vars.players[index]->gunctrl.passivemode = false;

	g_Vars.players[index]->hands[0] = hand;
	g_Vars.players[index]->hands[1] = hand;

	g_Vars.players[index]->gunposamplitude = 1;
	g_Vars.players[index]->gunxamplitude = 1;

	g_Vars.players[index]->doautoselect = false;
	g_Vars.players[index]->playertriggeron = false;
	g_Vars.players[index]->playertriggerprev = 0;
	g_Vars.players[index]->playertrigtime240 = 0;
	g_Vars.players[index]->curguntofire = 0;
	g_Vars.players[index]->gunshadecol[0] = 0xff;
	g_Vars.players[index]->gunshadecol[1] = 0xff;
	g_Vars.players[index]->gunshadecol[2] = 0xff;
	g_Vars.players[index]->gunshadecol[3] = 0;
	g_Vars.players[index]->resetshadecol = true;
	g_Vars.players[index]->lookingatprop.prop = NULL;

	for (i = 0; i < 4; i++) {
		g_Vars.players[index]->trackedprops[i].prop = NULL;
	}

	g_Vars.players[index]->crosspos[0] = 0;
	g_Vars.players[index]->crosspos[1] = 0;
	g_Vars.players[index]->crosspossum[0] = 0;
	g_Vars.players[index]->crosspossum[1] = 0;
	g_Vars.players[index]->guncrossdamp = 0.9f;

	g_Vars.players[index]->hands[HAND_LEFT].crosspos[0] = 0;
	g_Vars.players[index]->hands[HAND_LEFT].crosspos[1] = 0;
	g_Vars.players[index]->hands[HAND_LEFT].guncrosspossum[0] = 0;
	g_Vars.players[index]->hands[HAND_LEFT].guncrosspossum[1] = 0;

	g_Vars.players[index]->hands[HAND_RIGHT].crosspos[0] = 0;
	g_Vars.players[index]->hands[HAND_RIGHT].crosspos[1] = 0;
	g_Vars.players[index]->hands[HAND_RIGHT].guncrosspossum[0] = 0;
	g_Vars.players[index]->hands[HAND_RIGHT].guncrosspossum[1] = 0;

	g_Vars.players[index]->crosspos2[0] = 0;
	g_Vars.players[index]->crosspos2[1] = 0;
	g_Vars.players[index]->crosssum2[0] = 0;
	g_Vars.players[index]->crosssum2[1] = 0;
	g_Vars.players[index]->gunaimdamp = 0.9f;
	g_Vars.players[index]->aimangle.x = 0;
	g_Vars.players[index]->aimangle.y = -M_PI;
	g_Vars.players[index]->aimangle.z = 0;

	g_Vars.players[index]->copiedgoldeneye = 0;
	g_Vars.players[index]->gunammooff = 0;
	g_Vars.players[index]->gunsync = 0;
	g_Vars.players[index]->syncchange = 0;
	g_Vars.players[index]->synccount = 0;
	g_Vars.players[index]->syncoffset = 0;
	g_Vars.players[index]->cyclesum = 0;
	g_Vars.players[index]->gunampsum = 0;

	g_Vars.players[index]->gunzoomfovs[0] = 15;
	g_Vars.players[index]->gunzoomfovs[1] = 60;
	g_Vars.players[index]->gunzoomfovs[2] = 30;

	g_Vars.players[index]->lastroomforoffset = -1;

	g_Vars.players[index]->c_screenwidth = 320;
	g_Vars.players[index]->c_screenheight = PAL ? 272 : 240;
	g_Vars.players[index]->c_screenleft = 0;
	g_Vars.players[index]->c_screentop = 0;
	g_Vars.players[index]->c_perspnear = 10;
	g_Vars.players[index]->c_perspfovy = 46;
	g_Vars.players[index]->c_perspaspect = 1;
	g_Vars.players[index]->c_halfwidth = 160;
	g_Vars.players[index]->c_halfheight = PAL ? 136 : 120;
	g_Vars.players[index]->c_scalex = 1;
	g_Vars.players[index]->c_scaley = 1;
	g_Vars.players[index]->c_recipscalex = 1;
	g_Vars.players[index]->c_recipscaley = 1;

	g_Vars.players[index]->mtxl1738 = NULL;
	g_Vars.players[index]->mtxl173c = NULL;
	g_Vars.players[index]->worldtoscreenmtx = NULL;
	g_Vars.players[index]->c_viewfmdynticknum = -1;
	g_Vars.players[index]->mtxf1748 = NULL;
	g_Vars.players[index]->projectionmtx = NULL;
	g_Vars.players[index]->perspmtxl = NULL;
	g_Vars.players[index]->mtxf1754 = NULL;
	g_Vars.players[index]->orthomtxl = NULL;
	g_Vars.players[index]->lookat = NULL;
	g_Vars.players[index]->prevworldtoscreenmtx = NULL;
	g_Vars.players[index]->c_prevviewfmdynticknum = -1;
	g_Vars.players[index]->prevprojectionmtx = NULL;

	g_Vars.players[index]->unk0484 = NULL;
	g_Vars.players[index]->unk0488 = NULL;

	g_Vars.players[index]->c_scalelod60 = 1;
	g_Vars.players[index]->c_scalelod = 1;
	g_Vars.players[index]->c_lodscalez = 1;
	g_Vars.players[index]->c_lodscalezu32 = 0x10000;

	g_Vars.players[index]->screenxminf = 0;
	g_Vars.players[index]->screenyminf = 0;
	g_Vars.players[index]->screenxmaxf = 320;
	g_Vars.players[index]->screenymaxf = PAL ? 272 : 240;

	g_Vars.players[index]->gunsightoff = 0;
	g_Vars.players[index]->unk1834 = 0;
	g_Vars.players[index]->unk1838 = 0;
	g_Vars.players[index]->unk183c = 0;

	g_Vars.players[index]->zoomintime = 0;
	g_Vars.players[index]->zoomintimemax = 0;
	g_Vars.players[index]->zoominfovy = 60;
	g_Vars.players[index]->zoominfovyold = 60;
	g_Vars.players[index]->zoominfovynew = 60;
	g_Vars.players[index]->fovy = 60;
	g_Vars.players[index]->aspect = 640.0f / (PAL ? 544.0f : 480.0f);
	g_Vars.players[index]->hudmessoff = 0;
	g_Vars.players[index]->bondmesscnt = -1;

	g_Vars.players[index]->weapons = NULL;
	g_Vars.players[index]->equipment = NULL;
	g_Vars.players[index]->equipmaxitems = 0;
	g_Vars.players[index]->equipallguns = false;
	g_Vars.players[index]->equipcuritem = 0;

	g_Vars.players[index]->angleoffset = 0;
	g_Vars.players[index]->invincible = cheatIsActive(CHEAT_INVINCIBLE);
	g_Vars.players[index]->healthdamagetype = 7;
	g_Vars.players[index]->vv_height = 1;
	g_Vars.players[index]->vv_eyeheight = 1;
	g_Vars.players[index]->vv_headheight = 1;
	g_Vars.players[index]->bondleandown = 0;

	g_Vars.players[index]->mpmenuon = false;
	g_Vars.players[index]->damagetype = 7;
	g_Vars.players[index]->deathcount = 0;
	g_Vars.players[index]->lastkilltime60 = -1;
	g_Vars.players[index]->lastkilltime60_2 = -1;
	g_Vars.players[index]->lastkilltime60_3 = -1;
	g_Vars.players[index]->lastkilltime60_4 = -1;
	g_Vars.players[index]->healthdisplaytime60 = 0;

	g_Vars.players[index]->chrmuzzlelast[0] = 0;
	g_Vars.players[index]->chrmuzzlelast[1] = 0;
	g_Vars.players[index]->healthscale = 1;
	g_Vars.players[index]->armourscale = 1;

	g_Vars.players[index]->haschrbody = false;
	g_Vars.players[index]->pausemode = PAUSEMODE_UNPAUSED;
	g_Vars.players[index]->pausetime60 = 0;
	g_Vars.players[index]->activatetimelast = 0;
	g_Vars.players[index]->activatetimethis = 0;
	g_Vars.players[index]->bondmovemode = MOVEMODE_WALK;

	g_Vars.players[index]->bondtankthetaspeedsum = 0;
	g_Vars.players[index]->bondtankverta = 0;
	g_Vars.players[index]->bondtankvertasum = 0;
	g_Vars.players[index]->bondturrettheta = 0;
	g_Vars.players[index]->bondturretthetasum = 0;
	g_Vars.players[index]->bondturretspeedsum = 0;
	g_Vars.players[index]->bondturretside = 0;
	g_Vars.players[index]->bondturretchange = 0;
	g_Vars.players[index]->bondtankslowtime = 0;

	g_Vars.players[index]->hoverbike = NULL;
	g_Vars.players[index]->bondonground = false;
	g_Vars.players[index]->tank = NULL;
	g_Vars.players[index]->unk1af0 = NULL;
	g_Vars.players[index]->bondonturret = 0;
	g_Vars.players[index]->grabbedprop = NULL;
	g_Vars.players[index]->bondtankexplode = false;
	g_Vars.players[index]->tickdiefinished = false;
	g_Vars.players[index]->introanimnum = 0;
	g_Vars.players[index]->lastsighton = 0;

	for (i = 0; i < 4; i++) {
		g_Vars.players[index]->targetset[i] = 0;
	}

	g_Vars.players[index]->sighttracktype = SIGHTTRACKTYPE_NONE;
	g_Vars.players[index]->gunextraaimx = 0;
	g_Vars.players[index]->gunextraaimy = 0;

	g_Vars.players[index]->model.anim = &g_Vars.players[index]->unk01c0;

	g_Vars.players[index]->eyespy = NULL;
	g_Vars.players[index]->eyespydarts = 8;

	g_Vars.players[index]->autocontrol_aimpad = 0;
	g_Vars.players[index]->autocontrol_lookup = 0;
	g_Vars.players[index]->autocontrol_dist = 0;
	g_Vars.players[index]->autocontrol_walkspeed = 0;
	g_Vars.players[index]->autocontrol_turnspeed = 0;

	g_Vars.players[index]->autoerasertarget = NULL;
	g_Vars.players[index]->autoeraserdist = -1;

	g_Vars.players[index]->sighttimer240 = 0;
	g_Vars.players[index]->aimtaptime = 0;
	g_Vars.players[index]->cachedlookahead = -4;
	g_Vars.players[index]->lookaheadframe = 0;

	g_Vars.players[index]->numaibuddies = 0;

	for (i = 0; i < MAX_BOTS; i++) {
		g_Vars.players[index]->aibuddynums[i] = 0;
	}

	g_Vars.players[index]->teleportstate = TELEPORTSTATE_INACTIVE;
	g_Vars.players[index]->teleporttime = 0;
	g_Vars.players[index]->teleportpad = 0;

	g_Vars.players[index]->commandingaibot = NULL;
	g_Vars.players[index]->training = 0;
	g_Vars.players[index]->deadtimer = -1;
	g_Vars.players[index]->coopcanrestart = false;
	g_Vars.players[index]->foot = 0;
	g_Vars.players[index]->footstepdist = 0;

	g_Vars.players[index]->unk1c64 = 0;
	g_Vars.players[index]->bondextrapos.x = 0;
	g_Vars.players[index]->bondextrapos.y = 0;
	g_Vars.players[index]->bondextrapos.z = 0;

	g_Vars.players[index]->disguised = false;
	g_Vars.players[index]->dostartnewlife = false;

	g_Vars.bondvisible = true;
	g_Vars.bondcollisions = true;
}

void playermgrCalculateAiBuddyNums(void)
{
	s32 i;
	s32 playernum = g_Vars.currentplayernum;
	s32 playercount = PLAYERCOUNT();

	for (i = playercount; i < g_MpNumChrs; i++) {
		if (g_MpAllChrConfigPtrs[i]->team == g_MpAllChrConfigPtrs[playernum]->team) {
			g_Vars.players[playernum]->aibuddynums[g_Vars.players[playernum]->numaibuddies] = i;
			g_Vars.players[playernum]->numaibuddies++;
		}
	}
}

void setCurrentPlayerNum(s32 playernum)
{
	g_Vars.currentplayernum = playernum;
	g_Vars.currentplayer = g_Vars.players[playernum];
	g_Vars.currentplayerstats = &g_Vars.playerstats[playernum];
	g_Vars.currentplayerindex = playermgrGetOrderOfPlayer(playernum);
}

s32 playermgrGetPlayerNumByProp(struct prop *prop)
{
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (prop == g_Vars.players[i]->prop) {
			return i;
		}
	}

	return -1;
}

void playermgrSetViewSize(s32 width, s32 height)
{
	g_Vars.currentplayer->viewwidth = width;
	g_Vars.currentplayer->viewheight = height;
}

void playermgrSetViewPosition(s32 viewleft, s32 viewtop)
{
	g_Vars.currentplayer->viewleft = viewleft;
	g_Vars.currentplayer->viewtop = viewtop;
}

s32 playermgrGetModelOfWeapon(s32 weapon)
{
	switch (weapon) {
	case WEAPON_NONE:
	case WEAPON_UNARMED:          return -1;
	case WEAPON_FALCON2:          return MODEL_CHRFALCON2;
	case WEAPON_MAGSEC4:          return MODEL_CHRLEEGUN1;
	case WEAPON_MAULER:           return MODEL_CHRMAULER;
	case WEAPON_DY357MAGNUM:      return MODEL_CHRDY357;
	case WEAPON_DY357LX:          return MODEL_CHRDY357TRENT;
	case WEAPON_PHOENIX:          return MODEL_CHRMAIANPISTOL;
	case WEAPON_FALCON2_SILENCER: return MODEL_CHRFALCON2SIL;
	case WEAPON_FALCON2_SCOPE:    return MODEL_CHRFALCON2SCOPE;
	case WEAPON_CMP150:           return MODEL_CHRCMP150;
	case WEAPON_AR34:             return MODEL_CHRAR34;
	case WEAPON_DRAGON:           return MODEL_CHRDRAGON;
	case WEAPON_SUPERDRAGON:      return MODEL_CHRSUPERDRAGON;
	case WEAPON_K7AVENGER:        return MODEL_CHRAVENGER;
	case WEAPON_CYCLONE:          return MODEL_CHRCYCLONE;
	case WEAPON_CALLISTO:         return MODEL_CHRMAIANSMG;
	case WEAPON_RCP120:           return MODEL_CHRRCP120;
	case WEAPON_LAPTOPGUN:        return MODEL_CHRPCGUN;
	case WEAPON_SHOTGUN:          return MODEL_CHRSHOTGUN;
	case WEAPON_REAPER:           return MODEL_CHRSKMINIGUN;
	case WEAPON_ROCKETLAUNCHER:   return MODEL_CHRDYROCKET;
	case WEAPON_DEVASTATOR:       return MODEL_CHRDEVASTATOR;
	case WEAPON_SLAYER:           return MODEL_CHRSKROCKET;
	case WEAPON_FARSIGHT:         return MODEL_CHRZ2020;
	case WEAPON_SNIPERRIFLE:      return MODEL_CHRSNIPERRIFLE;
	case WEAPON_CROSSBOW:         return MODEL_CHRCROSSBOW;
	case WEAPON_LASER:            return MODEL_CHRLASER;
	case WEAPON_COMBATKNIFE:      return MODEL_CHRKNIFE;
	case WEAPON_TRANQUILIZER:     return MODEL_CHRDRUGGUN;
	case WEAPON_PSYCHOSISGUN:     return MODEL_CHRDRUGGUN;
	case WEAPON_NBOMB:            return MODEL_CHRNBOMB;
	case WEAPON_GRENADE:          return MODEL_CHRGRENADE;
	case WEAPON_REMOTEMINE:       return MODEL_CHRREMOTEMINE;
	case WEAPON_PROXIMITYMINE:    return MODEL_CHRPROXIMITYMINE;
	case WEAPON_TIMEDMINE:        return MODEL_CHRTIMEDMINE;
	case WEAPON_BRIEFCASE2:       return MODEL_CHRBRIEFCASE;
	case WEAPON_CLOAKINGDEVICE:   return MODEL_CHRCLOAKER;
	case WEAPON_PP9I:             return MODEL_CHRWPPK;
	case WEAPON_CC13:             return MODEL_CHRTT33;
	case WEAPON_KL01313:          return MODEL_CHRSKORPION;
	case WEAPON_KF7SPECIAL:       return MODEL_CHRKALASH;
	case WEAPON_ZZT:              return MODEL_CHRUZI;
	case WEAPON_DMC:              return MODEL_CHRMP5K;
	case WEAPON_AR53:             return MODEL_CHRM16;
	case WEAPON_RCP45:            return MODEL_CHRFNP90;
	case WEAPON_COMBATBOOST:      return -1;
	case WEAPON_HAMMER:           return MODEL_CHRLUMPHAMMER;
	case WEAPON_SCREWDRIVER:      return MODEL_CHRSONICSCREWER;
	}

	if (weapon <= WEAPON_PSYCHOSISGUN) {
		return MODEL_CHRSNIPERRIFLE;
	}

	return -1;
}

void playermgrDeleteWeapon(s32 hand)
{
	weaponDeleteFromChr(g_Vars.currentplayer->prop->chr, hand);
}

void playermgrCreateWeapon(s32 hand)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;

	if (chr->weapons_held[hand] == NULL) {
		s32 weaponnum = bgunGetWeaponNum(hand);
		s32 modelnum = playermgrGetModelOfWeapon(weaponnum);

		if (hand == HAND_LEFT && weaponnum == WEAPON_REMOTEMINE) {
			modelnum = -1;
		}

		if (modelnum >= 0) {
			u32 flags;

			if (hand == HAND_RIGHT) {
				flags = 0;
			} else {
				flags = OBJFLAG_WEAPON_LEFTHANDED;
			}

			weaponCreateForChr(chr, modelnum, weaponnum, flags, NULL, NULL);
		}
	}
}

void playermgrShuffle(void)
{
	s32 i;

	// Order them ascending
	for (i = 0; i < 4; i++) {
		g_Vars.playerorder[i] = i;
	}

	// Randomly swap numbers with later elements
	for (i = 0; i != 3; i++) {
		s32 otherindex = random() % (4 - i);
		s32 tmp = g_Vars.playerorder[i];

		g_Vars.playerorder[i] = g_Vars.playerorder[i + otherindex];
		g_Vars.playerorder[i + otherindex] = tmp;
	}
}

s32 playermgrGetOrderOfPlayer(s32 playernum)
{
	s32 index = 0;
	s32 i;

	for (i = 0; i < 4; i++) {
		s32 thisnum = g_Vars.playerorder[i];

		if (playernum == thisnum) {
			break;
		}

		if (g_Vars.players[thisnum]) {
			index++;
		}
	}

	return index;
}

s32 playermgrGetPlayerAtOrder(s32 ordernum)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Vars.players[g_Vars.playerorder[i]]) {
			if (ordernum == 0) {
				return g_Vars.playerorder[i];
			}

			ordernum--;
		}
	}

	return 0;
}
