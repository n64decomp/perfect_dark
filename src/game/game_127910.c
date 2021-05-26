#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/game_097ba0.h"
#include "game/game_0b69d0.h"
#include "game/game_127910.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memory.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

void func0f127910(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_Vars.playerstats[i].damagescale = 1;
	}

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;
}

void playersUnrefAll(void)
{
	g_Vars.players[0] = NULL;
	g_Vars.players[1] = NULL;
	g_Vars.players[2] = NULL;
	g_Vars.players[3] = NULL;
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

void playersAllocate(s32 count)
{
	g_Vars.players[0] = NULL;
	g_Vars.players[1] = NULL;
	g_Vars.players[2] = NULL;
	g_Vars.players[3] = NULL;

	if (count > 0) {
		s32 i;

		for (i = 0; i < count; i++) {
			playerAllocate(i);
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
		playerAllocate(0);
		setCurrentPlayerNum(0);

		if (g_Vars.fourmeg2player) {
			s16 a = viGetFbWidth();
			s16 b = viGetFbHeight();
			currentPlayerSetViewSize(a, b << 1);
		} else {
			s16 a = viGetFbWidth();
			s16 b = viGetFbHeight();
			currentPlayerSetViewSize(a, b);
		}

		g_Vars.coop = NULL;
		g_Vars.anti = NULL;
		g_Vars.bond = g_Vars.players[0];
	}
}

void playerAllocate(s32 index)
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

	g_Vars.players[index] = malloc(sizeof(struct player), MEMPOOL_STAGE);

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
	g_Vars.players[index]->periminfo.header.type = TILETYPE_03;
	g_Vars.players[index]->periminfo.header.flags = TILEFLAG_0004 | TILEFLAG_0010;
	g_Vars.players[index]->periminfo.ymax = 0;
	g_Vars.players[index]->periminfo.ymin = 0;
	g_Vars.players[index]->periminfo.x = 0;
	g_Vars.players[index]->periminfo.z = 0;
	g_Vars.players[index]->periminfo.width = 0;

	g_Vars.players[index]->bondactivateorreload = 0;
	g_Vars.players[index]->unk00d4 = 0;
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

	g_Vars.players[index]->autoyaimenabled = true;
	g_Vars.players[index]->autoaimy = 0;
	g_Vars.players[index]->autoyaimprop = NULL;
	g_Vars.players[index]->autoyaimtime60 = -1;

	g_Vars.players[index]->autoxaimenabled = true;
	g_Vars.players[index]->autoaimx = 0;
	g_Vars.players[index]->autoxaimprop = NULL;
	g_Vars.players[index]->autoxaimtime60 = -1;

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

	for (i = 0; i < 2; i++) {
		g_Vars.players[index]->viewport[i].unk00 = 640;
		g_Vars.players[index]->viewport[i].unk02 = (PAL ? 544 : 480);
		g_Vars.players[index]->viewport[i].unk04 = 511;
		g_Vars.players[index]->viewport[i].unk06 = 0;

		g_Vars.players[index]->viewport[i].unk08 = 640;
		g_Vars.players[index]->viewport[i].unk0a = (PAL ? 544 : 480);
		g_Vars.players[index]->viewport[i].unk0c = 511;
		g_Vars.players[index]->viewport[i].unk0e = 0;
	}

	g_Vars.players[index]->viewx = 100;
	g_Vars.players[index]->viewy = 100;
	g_Vars.players[index]->viewleft = 0;
	g_Vars.players[index]->viewtop = 0;

	g_Vars.players[index]->slayerrocket = NULL;
	g_Vars.players[index]->badrockettime = 0;

	g_Vars.players[index]->gunctrl.gunmemtype = 0;
	g_Vars.players[index]->gunctrl.unk158c = NULL;
	g_Vars.players[index]->gunctrl.unk1590 = 0;

	g_Vars.players[index]->gunctrl.weaponnum = WEAPON_NONE;
	g_Vars.players[index]->gunctrl.prevweaponnum = -1;
	g_Vars.players[index]->gunctrl.switchtoweaponnum = -1;

	g_Vars.players[index]->gunctrl.gunmemowner = GUNMEMOWNER_2;
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
	g_Vars.players[index]->aimtype = 0;
	g_Vars.players[index]->lookingatprop.prop = NULL;

	for (i = 0; i < 4; i++) {
		g_Vars.players[index]->cmpfollowprops[i].prop = NULL;
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

	g_Vars.players[index]->unk1738 = NULL;
	g_Vars.players[index]->unk173c = NULL;
	g_Vars.players[index]->matrix1740 = NULL;
	g_Vars.players[index]->c_viewfmdynticknum = -1;
	g_Vars.players[index]->unk1748 = 0;
	g_Vars.players[index]->unk174c = NULL;
	g_Vars.players[index]->unk1750 = NULL;
	g_Vars.players[index]->unk1754 = NULL;
	g_Vars.players[index]->unk1758 = NULL;
	g_Vars.players[index]->unk175c = NULL;
	g_Vars.players[index]->prev1740 = NULL;
	g_Vars.players[index]->c_prevviewfmdynticknum = -1;
	g_Vars.players[index]->unk1768 = NULL;

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

	g_Vars.players[index]->unk1994 = 0;
	g_Vars.players[index]->unk1998 = 0;
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

	g_Vars.players[index]->target = 0;
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

	for (i = 0; i < 8; i++) {
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

void currentPlayerCalculateAiBuddyNums(void)
{
	s32 i;
	s32 playernum = g_Vars.currentplayernum;
	s32 playercount = PLAYERCOUNT();

	for (i = playercount; i < g_MpNumPlayers; i++) {
		if (var800ac500[i]->team == var800ac500[playernum]->team) {
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
	g_Vars.currentplayerindex = calculatePlayerIndex(playernum);
}

s32 propGetPlayerNum(struct prop *prop)
{
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (prop == g_Vars.players[i]->prop) {
			return i;
		}
	}

	return -1;
}

void currentPlayerSetViewSize(s32 viewx, s32 viewy)
{
	g_Vars.currentplayer->viewx = viewx;
	g_Vars.currentplayer->viewy = viewy;
}

void currentPlayerSetViewPosition(s32 viewleft, s32 viewtop)
{
	g_Vars.currentplayer->viewleft = viewleft;
	g_Vars.currentplayer->viewtop = viewtop;
}

void currentPlayerSetFovY(f32 fovy)
{
	g_Vars.currentplayer->fovy = fovy;
}

void currentPlayerSetAspectRatio(f32 aspect)
{
	g_Vars.currentplayer->aspect = aspect;
}

GLOBAL_ASM(
glabel weaponGetModel
.late_rodata
glabel var7f1b5168
.word weaponGetModel+0x60 # f128b54
glabel var7f1b516c
.word weaponGetModel+0x60 # f128b54
glabel var7f1b5170
.word weaponGetModel+0x68 # f128b5c
glabel var7f1b5174
.word weaponGetModel+0x98 # f128b8c
glabel var7f1b5178
.word weaponGetModel+0xa0 # f128b94
glabel var7f1b517c
.word weaponGetModel+0x70 # f128b64
glabel var7f1b5180
.word weaponGetModel+0x78 # f128b6c
glabel var7f1b5184
.word weaponGetModel+0x90 # f128b84
glabel var7f1b5188
.word weaponGetModel+0x80 # f128b74
glabel var7f1b518c
.word weaponGetModel+0x88 # f128b7c
glabel var7f1b5190
.word weaponGetModel+0xa8 # f128b9c
glabel var7f1b5194
.word weaponGetModel+0xd0 # f128bc4
glabel var7f1b5198
.word weaponGetModel+0xd8 # f128bcc
glabel var7f1b519c
.word weaponGetModel+0xe0 # f128bd4
glabel var7f1b51a0
.word weaponGetModel+0xe8 # f128bdc
glabel var7f1b51a4
.word weaponGetModel+0xb8 # f128bac
glabel var7f1b51a8
.word weaponGetModel+0xc8 # f128bbc
glabel var7f1b51ac
.word weaponGetModel+0xb0 # f128ba4
glabel var7f1b51b0
.word weaponGetModel+0xc0 # f128bb4
glabel var7f1b51b4
.word weaponGetModel+0xf0 # f128be4
glabel var7f1b51b8
.word weaponGetModel+0xf8 # f128bec
glabel var7f1b51bc
.word weaponGetModel+0x120 # f128c14
glabel var7f1b51c0
.word weaponGetModel+0x118 # f128c0c
glabel var7f1b51c4
.word weaponGetModel+0x108 # f128bfc
glabel var7f1b51c8
.word weaponGetModel+0x100 # f128bf4
glabel var7f1b51cc
.word weaponGetModel+0x110 # f128c04
glabel var7f1b51d0
.word weaponGetModel+0x138 # f128c2c
glabel var7f1b51d4
.word weaponGetModel+0x128 # f128c1c
glabel var7f1b51d8
.word weaponGetModel+0x140 # f128c34
glabel var7f1b51dc
.word weaponGetModel+0x130 # f128c24
glabel var7f1b51e0
.word weaponGetModel+0x158 # f128c4c
glabel var7f1b51e4
.word weaponGetModel+0x150 # f128c44
glabel var7f1b51e8
.word weaponGetModel+0x170 # f128c64
glabel var7f1b51ec
.word weaponGetModel+0x168 # f128c5c
glabel var7f1b51f0
.word weaponGetModel+0x160 # f128c54
glabel var7f1b51f4
.word weaponGetModel+0x1c8 # f128cbc
glabel var7f1b51f8
.word weaponGetModel+0x188 # f128c7c
glabel var7f1b51fc
.word weaponGetModel+0x190 # f128c84
glabel var7f1b5200
.word weaponGetModel+0x198 # f128c8c
glabel var7f1b5204
.word weaponGetModel+0x1a0 # f128c94
glabel var7f1b5208
.word weaponGetModel+0x1a8 # f128c9c
glabel var7f1b520c
.word weaponGetModel+0x1b0 # f128ca4
glabel var7f1b5210
.word weaponGetModel+0x1b8 # f128cac
glabel var7f1b5214
.word weaponGetModel+0x1c0 # f128cb4
glabel var7f1b5218
.word weaponGetModel+0x148 # f128c3c
glabel var7f1b521c
.word weaponGetModel+0x1e0 # f128cd4
glabel var7f1b5220
.word weaponGetModel+0x1e0 # f128cd4
glabel var7f1b5224
.word weaponGetModel+0x1e0 # f128cd4
glabel var7f1b5228
.word weaponGetModel+0x1e0 # f128cd4
glabel var7f1b522c
.word weaponGetModel+0x180 # f128c74
.text
/*  f128af4:	28810052 */ 	slti	$at,$a0,0x52
/*  f128af8:	14200007 */ 	bnez	$at,.L0f128b18
/*  f128afc:	24010052 */ 	addiu	$at,$zero,0x52
/*  f128b00:	10810072 */ 	beq	$a0,$at,.L0f128ccc
/*  f128b04:	24010057 */ 	addiu	$at,$zero,0x57
/*  f128b08:	10810058 */ 	beq	$a0,$at,.L0f128c6c
/*  f128b0c:	00000000 */ 	nop
/*  f128b10:	10000071 */ 	b	.L0f128cd8
/*  f128b14:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128b18:
/*  f128b18:	28810032 */ 	slti	$at,$a0,0x32
/*  f128b1c:	14200005 */ 	bnez	$at,.L0f128b34
/*  f128b20:	24010051 */ 	addiu	$at,$zero,0x51
/*  f128b24:	10810067 */ 	beq	$a0,$at,.L0f128cc4
/*  f128b28:	00000000 */ 	nop
/*  f128b2c:	1000006a */ 	b	.L0f128cd8
/*  f128b30:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128b34:
/*  f128b34:	2c810032 */ 	sltiu	$at,$a0,0x32
/*  f128b38:	10200066 */ 	beqz	$at,.L0f128cd4
/*  f128b3c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f128b40:	3c017f1b */ 	lui	$at,%hi(var7f1b5168)
/*  f128b44:	002e0821 */ 	addu	$at,$at,$t6
/*  f128b48:	8c2e5168 */ 	lw	$t6,%lo(var7f1b5168)($at)
/*  f128b4c:	01c00008 */ 	jr	$t6
/*  f128b50:	00000000 */ 	nop
/*  f128b54:	03e00008 */ 	jr	$ra
/*  f128b58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f128b5c:	03e00008 */ 	jr	$ra
/*  f128b60:	240200f5 */ 	addiu	$v0,$zero,0xf5
/*  f128b64:	03e00008 */ 	jr	$ra
/*  f128b68:	240200f6 */ 	addiu	$v0,$zero,0xf6
/*  f128b6c:	03e00008 */ 	jr	$ra
/*  f128b70:	240200f7 */ 	addiu	$v0,$zero,0xf7
/*  f128b74:	03e00008 */ 	jr	$ra
/*  f128b78:	240200f8 */ 	addiu	$v0,$zero,0xf8
/*  f128b7c:	03e00008 */ 	jr	$ra
/*  f128b80:	240200f9 */ 	addiu	$v0,$zero,0xf9
/*  f128b84:	03e00008 */ 	jr	$ra
/*  f128b88:	240200fa */ 	addiu	$v0,$zero,0xfa
/*  f128b8c:	03e00008 */ 	jr	$ra
/*  f128b90:	240200fb */ 	addiu	$v0,$zero,0xfb
/*  f128b94:	03e00008 */ 	jr	$ra
/*  f128b98:	240200fc */ 	addiu	$v0,$zero,0xfc
/*  f128b9c:	03e00008 */ 	jr	$ra
/*  f128ba0:	240200fd */ 	addiu	$v0,$zero,0xfd
/*  f128ba4:	03e00008 */ 	jr	$ra
/*  f128ba8:	240200fe */ 	addiu	$v0,$zero,0xfe
/*  f128bac:	03e00008 */ 	jr	$ra
/*  f128bb0:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f128bb4:	03e00008 */ 	jr	$ra
/*  f128bb8:	24020100 */ 	addiu	$v0,$zero,0x100
/*  f128bbc:	03e00008 */ 	jr	$ra
/*  f128bc0:	24020101 */ 	addiu	$v0,$zero,0x101
/*  f128bc4:	03e00008 */ 	jr	$ra
/*  f128bc8:	24020102 */ 	addiu	$v0,$zero,0x102
/*  f128bcc:	03e00008 */ 	jr	$ra
/*  f128bd0:	24020103 */ 	addiu	$v0,$zero,0x103
/*  f128bd4:	03e00008 */ 	jr	$ra
/*  f128bd8:	24020104 */ 	addiu	$v0,$zero,0x104
/*  f128bdc:	03e00008 */ 	jr	$ra
/*  f128be0:	24020105 */ 	addiu	$v0,$zero,0x105
/*  f128be4:	03e00008 */ 	jr	$ra
/*  f128be8:	24020106 */ 	addiu	$v0,$zero,0x106
/*  f128bec:	03e00008 */ 	jr	$ra
/*  f128bf0:	24020107 */ 	addiu	$v0,$zero,0x107
/*  f128bf4:	03e00008 */ 	jr	$ra
/*  f128bf8:	24020108 */ 	addiu	$v0,$zero,0x108
/*  f128bfc:	03e00008 */ 	jr	$ra
/*  f128c00:	24020109 */ 	addiu	$v0,$zero,0x109
/*  f128c04:	03e00008 */ 	jr	$ra
/*  f128c08:	2402010a */ 	addiu	$v0,$zero,0x10a
/*  f128c0c:	03e00008 */ 	jr	$ra
/*  f128c10:	2402010b */ 	addiu	$v0,$zero,0x10b
/*  f128c14:	03e00008 */ 	jr	$ra
/*  f128c18:	2402010c */ 	addiu	$v0,$zero,0x10c
/*  f128c1c:	03e00008 */ 	jr	$ra
/*  f128c20:	2402010d */ 	addiu	$v0,$zero,0x10d
/*  f128c24:	03e00008 */ 	jr	$ra
/*  f128c28:	24020195 */ 	addiu	$v0,$zero,0x195
/*  f128c2c:	03e00008 */ 	jr	$ra
/*  f128c30:	2402010f */ 	addiu	$v0,$zero,0x10f
/*  f128c34:	03e00008 */ 	jr	$ra
/*  f128c38:	2402010e */ 	addiu	$v0,$zero,0x10e
/*  f128c3c:	03e00008 */ 	jr	$ra
/*  f128c40:	2402010e */ 	addiu	$v0,$zero,0x10e
/*  f128c44:	03e00008 */ 	jr	$ra
/*  f128c48:	24020110 */ 	addiu	$v0,$zero,0x110
/*  f128c4c:	03e00008 */ 	jr	$ra
/*  f128c50:	24020112 */ 	addiu	$v0,$zero,0x112
/*  f128c54:	03e00008 */ 	jr	$ra
/*  f128c58:	24020115 */ 	addiu	$v0,$zero,0x115
/*  f128c5c:	03e00008 */ 	jr	$ra
/*  f128c60:	24020114 */ 	addiu	$v0,$zero,0x114
/*  f128c64:	03e00008 */ 	jr	$ra
/*  f128c68:	24020113 */ 	addiu	$v0,$zero,0x113
.L0f128c6c:
/*  f128c6c:	03e00008 */ 	jr	$ra
/*  f128c70:	24020011 */ 	addiu	$v0,$zero,0x11
/*  f128c74:	03e00008 */ 	jr	$ra
/*  f128c78:	2402012e */ 	addiu	$v0,$zero,0x12e
/*  f128c7c:	03e00008 */ 	jr	$ra
/*  f128c80:	24020117 */ 	addiu	$v0,$zero,0x117
/*  f128c84:	03e00008 */ 	jr	$ra
/*  f128c88:	24020118 */ 	addiu	$v0,$zero,0x118
/*  f128c8c:	03e00008 */ 	jr	$ra
/*  f128c90:	24020119 */ 	addiu	$v0,$zero,0x119
/*  f128c94:	03e00008 */ 	jr	$ra
/*  f128c98:	2402011a */ 	addiu	$v0,$zero,0x11a
/*  f128c9c:	03e00008 */ 	jr	$ra
/*  f128ca0:	2402011b */ 	addiu	$v0,$zero,0x11b
/*  f128ca4:	03e00008 */ 	jr	$ra
/*  f128ca8:	2402011c */ 	addiu	$v0,$zero,0x11c
/*  f128cac:	03e00008 */ 	jr	$ra
/*  f128cb0:	2402011d */ 	addiu	$v0,$zero,0x11d
/*  f128cb4:	03e00008 */ 	jr	$ra
/*  f128cb8:	2402011e */ 	addiu	$v0,$zero,0x11e
/*  f128cbc:	03e00008 */ 	jr	$ra
/*  f128cc0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f128cc4:
/*  f128cc4:	03e00008 */ 	jr	$ra
/*  f128cc8:	24020198 */ 	addiu	$v0,$zero,0x198
.L0f128ccc:
/*  f128ccc:	03e00008 */ 	jr	$ra
/*  f128cd0:	24020197 */ 	addiu	$v0,$zero,0x197
.L0f128cd4:
/*  f128cd4:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128cd8:
/*  f128cd8:	10200003 */ 	beqz	$at,.L0f128ce8
/*  f128cdc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f128ce0:	03e00008 */ 	jr	$ra
/*  f128ce4:	2402010c */ 	addiu	$v0,$zero,0x10c
.L0f128ce8:
/*  f128ce8:	03e00008 */ 	jr	$ra
/*  f128cec:	00601025 */ 	or	$v0,$v1,$zero
);

//s32 weaponGetModel(s32 weapon)
//{
//	switch (weapon) {
//	case WEAPON_NONE:
//	case WEAPON_UNARMED:          return -1;
//	case WEAPON_FALCON2:          return MODEL_CHRFALCON2;
//	case WEAPON_MAGSEC4:          return MODEL_CHRLEEGUN1;
//	case WEAPON_MAULER:           return MODEL_CHRMAULER;
//	case WEAPON_DY357MAGNUM:      return MODEL_CHRDY357;
//	case WEAPON_DY357LX:          return MODEL_CHRDY357TRENT;
//	case WEAPON_PHOENIX:          return MODEL_CHRMAIANPISTOL;
//	case WEAPON_FALCON2_SILENCER: return MODEL_CHRFALCON2SIL;
//	case WEAPON_FALCON2_SCOPE:    return MODEL_CHRFALCON2SCOPE;
//	case WEAPON_CMP150:           return MODEL_CHRCMP150;
//	case WEAPON_AR34:             return MODEL_CHRAR34;
//	case WEAPON_DRAGON:           return MODEL_CHRDRAGON;
//	case WEAPON_SUPERDRAGON:      return MODEL_CHRSUPERDRAGON;
//	case WEAPON_K7AVENGER:        return MODEL_CHRAVENGER;
//	case WEAPON_CYCLONE:          return MODEL_CHRCYCLONE;
//	case WEAPON_CALLISTO:         return MODEL_CHRMAIANSMG;
//	case WEAPON_RCP120:           return MODEL_CHRRCP120;
//	case WEAPON_LAPTOPGUN:        return MODEL_CHRPCGUN;
//	case WEAPON_SHOTGUN:          return MODEL_CHRSHOTGUN;
//	case WEAPON_REAPER:           return MODEL_CHRSKMINIGUN;
//	case WEAPON_ROCKETLAUNCHER:   return MODEL_CHRDYROCKET;
//	case WEAPON_DEVASTATOR:       return MODEL_CHRDEVASTATOR;
//	case WEAPON_SLAYER:           return MODEL_CHRSKROCKET;
//	case WEAPON_FARSIGHT:         return MODEL_CHRZ2020;
//	case WEAPON_SNIPERRIFLE:      return MODEL_CHRSNIPERRIFLE;
//	case WEAPON_CROSSBOW:         return MODEL_CHRCROSSBOW;
//	case WEAPON_LASER:            return MODEL_CHRLASER;
//	case WEAPON_COMBATKNIFE:      return MODEL_CHRKNIFE;
//	case WEAPON_TRANQUILIZER:     return MODEL_CHRDRUGGUN;
//	case WEAPON_PSYCHOSISGUN:     return MODEL_CHRDRUGGUN;
//	case WEAPON_NBOMB:            return MODEL_CHRNBOMB;
//	case WEAPON_GRENADE:          return MODEL_CHRGRENADE;
//	case WEAPON_REMOTEMINE:       return MODEL_CHRREMOTEMINE;
//	case WEAPON_PROXIMITYMINE:    return MODEL_CHRPROXIMITYMINE;
//	case WEAPON_TIMEDMINE:        return MODEL_CHRTIMEDMINE;
//	case WEAPON_BRIEFCASE2:       return MODEL_CHRBRIEFCASE;
//	case WEAPON_CLOAKINGDEVICE:   return MODEL_CHRCLOAKER;
//	case WEAPON_PP9I:             return MODEL_CHRWPPK;
//	case WEAPON_CC13:             return MODEL_CHRTT33;
//	case WEAPON_KL01313:          return MODEL_CHRSKORPION;
//	case WEAPON_KF7SPECIAL:       return MODEL_CHRKALASH;
//	case WEAPON_ZZT:              return MODEL_CHRUZI;
//	case WEAPON_DMC:              return MODEL_CHRMP5K;
//	case WEAPON_AR53:             return MODEL_CHRM16;
//	case WEAPON_RCP45:            return MODEL_CHRFNP90;
//	case WEAPON_COMBATBOOST:      return -1;
//	case WEAPON_HAMMER:           return MODEL_CHRLUMPHAMMER;
//	case WEAPON_52:               return MODEL_CHRSONICSCREWER;
//	}
//
//	if (weapon <= WEAPON_PSYCHOSISGUN) {
//		return MODEL_CHRSNIPERRIFLE;
//	}
//
//	return -1;
//}

void currentPlayerSetWeaponFlag4(s32 hand)
{
	chrSetObjHiddenFlag4OnWeapon(g_Vars.currentplayer->prop->chr, hand);
}

void func0f128d20(s32 hand)
{
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;

	if (chr->weapons_held[hand] == NULL) {
		s32 weaponnum = handGetWeaponNum(hand);
		s32 modelnum = weaponGetModel(weaponnum);

		if (hand == HAND_LEFT && weaponnum == WEAPON_REMOTEMINE) {
			modelnum = -1;
		}

		if (modelnum >= 0) {
			u32 flags;

			if (hand == HAND_RIGHT) {
				flags = 0;
			} else {
				flags = 0x10000000;
			}

			func0f08b8e8(chr, modelnum, weaponnum, flags, 0, 0);
		}
	}
}

void randomisePlayerOrder(void)
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

u32 calculatePlayerIndex(u32 playernum)
{
	u32 count = 0;
	u32 i;

	for (i = 0; i < 4; i++) {
		u32 thisnum = g_Vars.playerorder[i];

		if (playernum == thisnum) {
			break;
		}

		if (g_Vars.players[thisnum]) {
			count++;
		}
	}

	return count;
}

s32 getPlayerByOrderNum(s32 arg0)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Vars.players[g_Vars.playerorder[i]]) {
			if (arg0 == 0) {
				return g_Vars.playerorder[i];
			}

			arg0--;
		}
	}

	return 0;
}
