#include <ultra64.h>
#include "constants.h"
#include "game/inventory/items.h"
#include "game/game_097ba0.h"
#include "game/game_1655c0.h"
#include "bss.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

extern u32 var800700ac;

void func0f010bb0(void)
{
	s32 i;

	struct hand hand = {
		0,
		0,
		0,
		0,
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
		(PAL ? -16.750415802002f : -19.999996185303f), // unk0728
		0,
		(PAL ? 16.750415802002f : 19.999996185303f),  // unk0730
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
		0,
		0,
		0,
		0,
		{-1}, // beam
	};

	if (IS4MB() && PLAYERCOUNT() == 2) {
		i = ALIGN16(var800700ac);
	} else {
		i = ALIGN16(func0f09ddfc());
	}

	g_Vars.currentplayer->gunctrl.unk158c = malloc(i, MEMPOOL_STAGE);
	g_Vars.currentplayer->gunctrl.unk159c = 0;
	g_Vars.currentplayer->gunctrl.unk15a0 = 0;
	g_Vars.currentplayer->gunctrl.unk15a4 = 0;
	g_Vars.currentplayer->gunctrl.unk15b0 = 0;
	g_Vars.currentplayer->gunctrl.unk15b1 = 0;
	g_Vars.currentplayer->gunctrl.gunmemtype = 0;
	g_Vars.currentplayer->gunctrl.gunmemnew = -1;
	g_Vars.currentplayer->gunctrl.gunmemowner = GUNMEMOWNER_2;
	g_Vars.currentplayer->gunctrl.gunlocktimer = 0;

	g_Vars.currentplayer->gunctrl.unk1583_06 = true;
	g_Vars.currentplayer->gunctrl.unk1583_00 = false;
	g_Vars.currentplayer->gunctrl.unk1583_04 = false;

	g_Vars.currentplayer->gunctrl.switchtoweaponnum = -1;
	g_Vars.currentplayer->gunctrl.fnfader = 0;

	g_Vars.currentplayer->gunctrl.invertgunfunc = false;

	g_Vars.currentplayer->hands[0] = hand;
	g_Vars.currentplayer->hands[1] = hand;

	g_Vars.currentplayer->hands[0].unk0d0f_02 = false;
	g_Vars.currentplayer->hands[1].unk0d0f_02 = false;

	g_Vars.currentplayer->hands[1].audiohandle = NULL;
	g_Vars.currentplayer->hands[0].audiohandle = NULL;

	g_Vars.currentplayer->gunctrl.curgunstr = 0;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->hands[1].unk0d74); i++) {
		g_Vars.currentplayer->hands[1].unk0d74[i] = 0;
		g_Vars.currentplayer->hands[0].unk0d74[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->ammoheldarr); i++) {
		g_Vars.currentplayer->ammoheldarr[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayerstats->shotcount); i++) {
		g_Vars.currentplayerstats->shotcount[i] = 0;
	}

	g_Vars.currentplayerstats->killcount = 0;
	g_Vars.currentplayerstats->ggkillcount = 0;
	g_Vars.currentplayer->deathcount = 0;
	g_Vars.currentplayer->gunposamplitude = 1;
	g_Vars.currentplayer->gunxamplitude = 1;
	g_Vars.currentplayer->doautoselect = false;
	g_Vars.currentplayer->playertriggeron = false;
	g_Vars.currentplayer->playertriggerprev = false;
	g_Vars.currentplayer->playertrigtime240 = 0;
	g_Vars.currentplayer->curguntofire = 0;

	g_Vars.currentplayer->gunshadecol[0] = 0xff;
	g_Vars.currentplayer->gunshadecol[1] = 0xff;
	g_Vars.currentplayer->gunshadecol[2] = 0xff;
	g_Vars.currentplayer->gunshadecol[3] = 0;
	g_Vars.currentplayer->resetshadecol = 1;
	g_Vars.currentplayer->aimtype = 0;
	g_Vars.currentplayer->crosspos[0] = 0;
	g_Vars.currentplayer->crosspos[1] = 0;
	g_Vars.currentplayer->unk1668 = 0;
	g_Vars.currentplayer->unk166c = 0;
	g_Vars.currentplayer->unk1670 = 0.9f;
	g_Vars.currentplayer->unk1674 = 0;
	g_Vars.currentplayer->unk1678 = 0;
	g_Vars.currentplayer->unk167c = 0;
	g_Vars.currentplayer->unk1680 = 0;
	g_Vars.currentplayer->unk1684 = 0.9f;
	g_Vars.currentplayer->unk1688 = 0;
	g_Vars.currentplayer->unk168c = -M_PI;
	g_Vars.currentplayer->unk1690 = 0;
	g_Vars.currentplayer->unk16d4 = 0;
	g_Vars.currentplayer->magnetattracttime = -1;
	g_Vars.currentplayer->unk16dc = 0;
	g_Vars.currentplayer->unk16e0 = 0;
	g_Vars.currentplayer->unk16e4 = 0;
	g_Vars.currentplayer->syncoffset = 0;
	g_Vars.currentplayer->cyclesum = 0;
	g_Vars.currentplayer->gunampsum = 0;

	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_RIGHT);
	func0f09d140(HAND_LEFT);
	func0f09d140(HAND_LEFT);
	func0f09d140(HAND_LEFT);

	g_Vars.currentplayer->unk16d8 = 0;
	g_Vars.currentplayer->gunsightoff = GUNSIGHTREASON_AIMING;
	g_Vars.currentplayer->gunzoomfovs[0] = 15;
	g_Vars.currentplayer->gunzoomfovs[1] = 60;
	g_Vars.currentplayer->gunzoomfovs[2] = 30;

	if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
		g_Weapons[WEAPON_EYESPY]->name = L_GUN_061; // "DrugSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN_061; // "DrugSpy"
		g_Weapons[WEAPON_EYESPY]->flags &= ~(WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN);
	} else if (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_CHICAGO
			|| (stageGetIndex(g_Vars.stagenum) == STAGEINDEX_MBR)) {
		g_Weapons[WEAPON_EYESPY]->name = L_GUN_062; // "BombSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN_062; // "BombSpy"
		g_Weapons[WEAPON_EYESPY]->flags &= ~(WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN);
	} else {
		// This is setting the "an" determiner for the camspy which seems
		// unusual at first. The theory is that during development it was called
		// the eyespy, then the pickup message was changed to "your camspy"
		// which made the determiner unused, hence no need to update it.
		g_Weapons[WEAPON_EYESPY]->name = L_GUN_060; // "CamSpy"
		g_Weapons[WEAPON_EYESPY]->shortname = L_GUN_060; // "CamSpy"
		g_Weapons[WEAPON_EYESPY]->flags |= (WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN);
	}

	func0f09ceac();
}
